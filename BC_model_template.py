from neuron import h
import numpy as np
import matplotlib.pyplot as plt

# ON-type Bipolar Cell model (using nrn/cells/BC_Euler9_ON morphology)
class ONBipolarCell:
    """
    ON-type Bipolar Cell based on BC_Euler9_ON morphology and ion channel distribution.
    Conductances are defined in .mod files.
    """

    def __init__(self, Stim=None):
        # ==== Constants ====
        self.dXdend = 2.0   # µm
        self.dXaxon = 2.0   # µm
        self.dXterm = 1.0   # µm
        self.rhoA = 130.0   # Ohm*cm
        self.cM = 1.1       # µF/cm2
        self.temp = 35.0     # °C

        # reversal potentials
        self.eh = -45.0
        self.ek = -58.0
        self.ena = 57.016
        #self.eL = -41   # mV
        self.eL = -53.08  # mV
        self.glbar = 0.04166   / 1000  #mS/cm2 
        


        # temperature
        h.celsius = self.temp

        # ==== Load morphology from hoc template ====
        self.cell = h.BC_Euler9_ON()
        #self.cell = h.BC_rect()
        self.soma = self.cell.soma
        self.dendritic = self.cell.dendritic
        self.axonal = self.cell.axonal
        self.terminal = self.cell.terminal
        self.all = self.cell.all

        # ==== Set up morphology and biophysics ====
        self._set_nseg()
        self._set_passive()
        self._insert_channels()

        # ==== Set cell position & rotation ====
        self.x = 0
        self.y = 0
        self.z = 0
        self.theta_z = 0.0
        self.theta_x = 0.0

        if Stim is not None:
            # 1) translate
            self._set_position(Stim)

            # 2) gather rotation angles (radians)
            theta_z = Stim.get('theta_z', 0.0)
            theta_x = Stim.get('theta_x', 0.0)
            # 3) rotate 
            self._rotateZ(theta_z)
            self._rotateX(theta_x)


    # --------------------------------------------------
    def _set_nseg(self):
        """Segment each section according to maximum compartment length rules."""
        for sec in self.all:
            if "dend" in sec.name():
                sec.nseg = int(np.ceil(sec.L / self.dXdend))
            elif "axon" in sec.name():
                sec.nseg = int(np.ceil(sec.L / self.dXaxon))
            elif "term" in sec.name():
                sec.nseg = int(np.ceil(sec.L / self.dXterm))
            else:
                sec.nseg = 1  # soma
        # optional: print segment counts
        # for sec in self.all:
        #     print(f"{sec.name()} nseg={sec.nseg}")

    # --------------------------------------------------
    def _set_passive(self):
        """Assign passive properties."""
        for sec in self.all:
            sec.Ra = self.rhoA
            sec.cm = self.cM
            sec.insert("pas")
            sec.g_pas = self.glbar
            sec.e_pas = self.eL

    # --------------------------------------------------
    def _insert_channels(self):
        """Insert active conductances at appropriate locations."""
        # --- soma ---
        sec = self.soma
        sec.insert("Bip_HCN1")
        sec.insert("Bip_HCN2")
        sec.insert("Bip_CaT")
        sec.insert("cad")
        #sec.insert("Bip_KCa")
        sec.insert("Bip_Kir")
        sec.insert("Bip_Kv")
        sec.eh = self.eh
        sec.ek = self.ek

        # --- dendrites ---
        for sec in self.dendritic:
            sec.insert("Bip_Na")
            sec.ena = self.ena

        # --- axon ---
        for sec in self.axonal:
            sec.insert("Bip_HCN4")
            sec.eh = self.eh

        # --- terminals ---
        for sec in self.terminal:
            sec.insert("Bip_HCN1")
            sec.insert("Bip_HCN2")
            sec.insert("Bip_HCN4")
            sec.insert("Bip_Na")
            sec.insert("Bip_CaL")
            sec.insert("cad")
            sec.eh = self.eh
            sec.ena = self.ena
        
        # NOTE: In Havels dissertation he uses the reduced membrane potential (substracting VR / vshift). 
        # But for our simulations we have to use the absolute membrane potential. So we have to set vshift to 0.
        for sec in self.all:
            if "Bip_Na" in sec.psection()['density_mechs']:
                sec.vshift_Bip_Na = 0
                sec.gna_bar_Bip_Na = 0.75 / 1000 # mS/cm2
            if "Bip_Kv" in sec.psection()['density_mechs']:
                sec.vshift_Bip_Kv = 0
                sec.gk_bar_Bip_Kv = 2  / 1000 # mS/cm2
            if "Bip_Kir" in sec.psection()['density_mechs']:
                sec.vshift_Bip_Kir = 0
                sec.gkir_bar_Bip_Kir = 0.05   / 1000 # mS/cm2
            if "Bip_KCa" in sec.psection()['density_mechs']:
                sec.vshift_Bip_KCa = 0
                sec.gkcabar_Bip_KCa = 0.036   / 1000 # mS/cm2
            if "Bip_HCN1" in sec.psection()['density_mechs']:
                sec.vshift_Bip_HCN1 = 0
                sec.ghcn1_bar_Bip_HCN1 = 0.08  / 1000  # mS/cm2
            if "Bip_HCN2" in sec.psection()['density_mechs']:
                sec.vshift_Bip_HCN2 = 0
                sec.ghcn2_bar_Bip_HCN2 = 0.08   / 1000 # mS/cm2
            if "Bip_HCN4" in sec.psection()['density_mechs']:
                sec.vshift_Bip_HCN4 = 0
                sec.ghcn4_bar_Bip_HCN4 = 0.08 / 1000  # mS/cm2
            if "Bip_CaT" in sec.psection()['density_mechs']:
                sec.vshift_Bip_CaT = 0 
                sec.gcabar_Bip_CaT = 286   / 1000 # mS/cm2
            if "Bip_CaL" in sec.psection()['density_mechs']:
                sec.gcabar_Bip_CaL = 150 / 1000 # mS/cm2
                #sec.vshift_Bip_CaL = 0 # -70 + 53.08 = -16.92


    # ----------------------------
    def _set_position(self, Stim):
        self.x = Stim.get('cellXShift', 0)
        self.y = Stim.get('cellYShift', 0)
        self.z = Stim.get('cellZShift', 0)
        for sec in self.all:
            for i in range(sec.n3d()):
                sec.pt3dchange(
                    i,
                    sec.x3d(i) + self.x,
                    sec.y3d(i) + self.y,
                    sec.z3d(i) + self.z,
                    sec.diam3d(i)
                )

    # ----------------------------
    def _rotateZ(self, theta_z):
        """Rotate cell around z-axis by theta_z (radians)."""
        self.theta_z = theta_z
        cos_theta = np.cos(theta_z)
        sin_theta = np.sin(theta_z)
        for sec in self.all:
            for i in range(sec.n3d()):
                x = sec.x3d(i) - self.x
                y = sec.y3d(i) - self.y
                xprime = x * cos_theta - y * sin_theta
                yprime = x * sin_theta + y * cos_theta
                sec.pt3dchange(i, xprime + self.x, yprime + self.y, sec.z3d(i), sec.diam3d(i))
    
    def _rotateX(self, theta_x):
        """Rotate cell around x-axis by theta_x (radians)."""
        self.theta_x = theta_x
        cos_theta = np.cos(theta_x)
        sin_theta = np.sin(theta_x)
        for sec in self.all:
            for i in range(sec.n3d()):
                y = sec.y3d(i) - self.y
                z = sec.z3d(i) - self.z
                yprime = y * cos_theta - z * sin_theta
                zprime = y * sin_theta + z * cos_theta
                sec.pt3dchange(i, sec.x3d(i), yprime + self.y, zprime + self.z, sec.diam3d(i))

    # --------------------------------------------------
    def info(self):
        nsec = len(list(self.all))
        nseg = sum(sec.nseg for sec in self.all)
        print("ON Bipolar Cell (BC_Euler9_ON morphology)")
        print(f"  Total sections: {nsec}")
        print(f"  Total segments: {nseg}")
        print(f"  Position: ({self.x:.1f}, {self.y:.1f}, {self.z:.1f}) µm")
        print(
            "  Rotation around Z-axis: "
            f"{np.degrees(self.theta_z):.1f} degrees"
        )
        print(
            "  Rotation around X-axis: "
            f"{np.degrees(self.theta_x):.1f} degrees"
        )
        print(f"  Temperature: {self.temp} °C")
        print(f"  Passive leak: g_pas={self.glbar} S/cm2, e_pas={self.eL} mV")

    # --------------------------------------------------
    def sections(self):
        return list(self.all)


# Example usage
if __name__ == "__main__":
    Stim = {'cellXShift': 10,
            'cellYShift': 5,
            'cellZShift': 2,
            'theta_z': np.radians(30),  # rotate 30 degrees around Z-axis
            'theta_x': np.radians(15)}  # rotate 15 degrees around X-axis
    cell = ONBipolarCell(Stim)
    cell.info()
