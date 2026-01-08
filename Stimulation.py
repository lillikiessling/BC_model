from neuron import h
import numpy as np

class Stimulus:
    def PointSource_Stim(self, amplitude, duration, type, stimXShift, stimYShift, stimZShift):
        Stim = {}   
        # ----------------------------
        # General 
        # ----------------------------
        Stim['ID'] = 1  
        Stim['reset'] = 1  
        Stim['vInit'] = -65  # membrane potential to initialize model (mV)
        Stim['type'] = type
        Stim['amp'] = amplitude

        # -----------------------------
        # Spatial parameters (extracellular)
        # ----------------------------
        Stim['elec'] = 'point'  # electrode type ('point' or 'disk'), for 'extracellular' only
        Stim['rhoExt'] = 1000  # extracellular resisitivity (Ohm*cm), for 'point' & 'disk' only
        Stim['stimXShift'] = stimXShift  # electrode x-shift (um), for 'point' & 'disk' only
        Stim['stimYShift'] = stimYShift  # electrode y-shift (um), for 'point' & 'disk' only
        Stim['stimZShift'] = stimZShift  # electrode z-shift (um), for 'point' & 'disk' only

        # -----------------------------
        # Temporal parameters
        # ----------------------------
        Stim['del'] = 0         
        Stim['dur'] = duration
        Stim['dt'] = 0.025
        Stim['initDur'] = 0
        Stim['initDt'] = 0
        Stim['pulseShape'] = 'mono'
        Stim['spike_threshold'] = 0.0
        return Stim
    
    def make_Stim(self, cell, duration=15, delay=0,
                  type='extracellular', amplitude=10.0,
                  stimXShift=0, stimYShift=0, stimZShift=50):

        # Build base stimulus
        Stim = self.PointSource_Stim(
            amplitude, duration, type,
            stimXShift, stimYShift, stimZShift
        )

        # FINAL timing parameters
        Stim['del'] = delay
        Stim['dur'] = duration

        # Stop time must include delay + duration
        Stim['stop'] = Stim['del'] + Stim['dur'] + Stim['del']

        # Build temporal vectors
        tsvec, isvec = self.setStimTemp(Stim)

        # Attach stimulus
        if type == 'iClamp':
            ic = self.setStimIClamp(cell)
            isvec.play(ic._ref_amp, tsvec)

        elif type == 'extracellular':
            self.setStimTransferImpedance(Stim, cell)
            isvec.play(h._ref_is_xtra, tsvec, 1)
        return Stim, tsvec, isvec
    


    ### Computes the compartment centers of a given section
    def compSectCenters(self, section):
        # Allocate memory
        n3d = int(h.n3d(sec=section))
        xx = h.Vector(n3d)
        yy = h.Vector(n3d)
        zz = h.Vector(n3d)
        dd = h.Vector(n3d)
        ll = h.Vector(n3d)

        # Get xyz coordiantes, diameter and length along section
        for i in range(0,n3d):
            xx.x[i] = h.x3d(i,sec=section)
            yy.x[i] = h.y3d(i,sec=section)
            zz.x[i] = h.z3d(i,sec=section)
            dd.x[i] = h.diam3d(i,sec=section)
            ll.x[i] = h.arc3d(i,sec=section)

        # Interpolate to the geometric centers of each segment of the section
        ll.div(section.L)

        rint = h.Vector(section.nseg+2)
        rint.indgen(1./section.nseg)
        rint.sub(1./(2.*section.nseg))
        rint.x[0] = 0
        rint.x[section.nseg+1] = 1

        xint = h.Vector(section.nseg+2)
        yint = h.Vector(section.nseg+2)
        zint = h.Vector(section.nseg+2)
        dint = h.Vector(section.nseg+2)
        xint.interpolate(rint,ll,xx)
        yint.interpolate(rint,ll,yy)
        zint.interpolate(rint,ll,zz)
        dint.interpolate(rint,ll,dd)

        return rint,xint,yint,zint,dint

    def setStimTransferImpedance(self, Stim, cell):
        for section in cell.all:
            # Insert extracellular mechanisms (both needed)
            section.insert('extracellular')
            section.insert('xtra')
            
            # Compute segment centers
            rint,xint,yint,zint,dint = self.compSectCenters(section)

            # Set centers in xtra mechanism
            for i in range(1,section.nseg+1):
                section(rint.x[i]).xtra.x = xint.x[i]
                section(rint.x[i]).xtra.y = yint.x[i]
                section(rint.x[i]).xtra.z = zint.x[i]
                #section(rint.x[i]).xtra.d = dint.x[i]

            # Loop over all segments in section
            for seg in section:
                # Compute transfer impedance depending on electrode type
                if Stim['elec']=='point': 
                    # Compute distance from electrode to center of each segment
                    dist = np.sqrt((seg.xtra.x-Stim['stimXShift'])**2 + (seg.xtra.y-Stim['stimYShift'])**2 + (seg.xtra.z-Stim['stimZShift'])**2)                        
                    # Set transfer impedance for each segment
                    seg.xtra.rx = Stim['rhoExt'] / (4.0*np.pi*dist) * 0.01 # in MOhm
                elif Stim['elec']=='disk':
                    # Compute distance from electrode to center of each segment (xy only) and vertical distance
                    r = np.sqrt((seg.xtra.x-Stim['stimXShift'])**2 + (seg.xtra.y-Stim['stimYShift'])**2)                    
                    z = seg.xtra.z-Stim['stimZShift']
                    # Set transfer impedance for each segment
                    seg.xtra.rx  = (2.0*Stim['rhoExt']) / (4.0*np.pi*Stim['rDisk']) * 0.01 * np.arcsin((2*Stim['rDisk']) / (np.sqrt((r-Stim['rDisk'])**2+z**2)+np.sqrt((r+Stim['rDisk'])**2+z**2))) # in MOhm
                else:
                    print('--- Unknown electrode type')
                    
                # Map references of extracellular and membrane current with xtra mechanism
                h.setpointer(section(seg.x)._ref_e_extracellular,'ex',section(seg.x).xtra)
                h.setpointer(section(seg.x)._ref_i_membrane,'im',section(seg.x).xtra)
        

    ### Sets up temporal stimulus
    def setStimTemp(self, Stim):
    
        # Helper variables
        initDur = Stim['initDur']    
        dt = Stim['dt']
        delay = Stim['del']
        dur = Stim['dur']
        stop = Stim['stop']
            
        # Pulse stim
        tsvec = np.concatenate(([0,0],initDur+np.linspace(0,stop,int(stop/dt)+1)))
        isvec = np.concatenate(([0,0],np.zeros(int(stop/dt)+1)))
        if Stim['pulseShape']=='mono':
            isvec[int(delay/dt):int((delay+dur)/dt)+1] = Stim['amp']
        elif Stim['pulseShape']=='bi':      
            isvec[int(delay/dt):int((delay+dur)/dt)+1] = Stim['amp']*Stim['pulseRatio'][0]
            isvec[int((delay+dur)/dt):int((delay+2*dur)/dt)+1] = Stim['amp']*Stim['pulseRatio'][1]
        else:
            print('--- Unknown pulse type')
        return h.Vector(tsvec), h.Vector(isvec)*1e-3 


    ### Sets up stimulus for iClamp
    def setStimIClamp(self, cell):        
        ic = h.IClamp(cell.soma(0.5)) # current clamp always at soma center
        ic.dur = 1e9
        ic.delay = 0
        return ic
    
