from neuron import h
import numpy as np
import matplotlib.pyplot as plt


# Parameters and morphology based on:
# ======= Ion Channel Types=======
# HCN1: 'Bip_HCN1'
# HCN2: 'Bip_HCN2'
# HCN4: 'Bip_HCN4'
# CaL : 'Bip_CaL'
# CaT : 'Bip_CaT'
# KCa: 'Bip_KCa' -> must come with 'Bip_caconc' 
# Kir: 'Bip_Kir'
# Kv: 'Bip_Kv'
# Na: 'Bip_Na'


# ======= Reversal Potentials =======
# eh = -45 # mV
# ek = -58 # mV
# ena = 57.016 # mV
# eca = eca (default neuron)


# ======= Locations (from Thesis Havel Benav) =======
# HCN1: term, soma
# HCN2: term, soma
# HCN4: term 
# CaL : soma
# CaT : soma
# KCa: soma
# Kir: soma
# Kv: soma
# Na: term, soma, dendrites


# ======= Morphology (From Paul Werginz model) =======
# dXdend = 5  # max. compartment length dendrite (um)
# dXaxon = 2  # max. compartment length axon (um)
# dXterm = 1  # max. compartment length terminals (um)
# rhoA = 132  # intracellular (axial) resistivity (Ohm*cm)
# cM = 1.14  # specific membrane capcitance (uF/cm2)
# eL = -50  # Leak reversal potential (mV)
# temp = 35  # temperature (Celsius)
# glbar = 0.04166 # specific leak conductance (S/cm2)


# ON-type Bipolar Cell model (using nrn/cells/BC_Euler9_ON morphology)
class ONBipolarCell:
    """
    ON-type Bipolar Cell based on BC_Euler9_ON morphology and ion channel distribution.
    Conductances are defined in .mod files.
    """

    def __init__(self, Stim=None):
        # ==== Constants ====
        self.dXdend = 5.0   # µm
        self.dXaxon = 2.0   # µm
        self.dXterm = 1.0   # µm
        self.rhoA = 132.0   # Ohm*cm
        self.cM = 1.14      # µF/cm2
        self.eL = -50.0     # mV
        self.glbar = 0.04166  # S/cm2
        self.temp = 35.0     # °C

        # reversal potentials
        self.eh = -45.0
        self.ek = -58.0
        self.ena = 57.016

        # temperature
        h.celsius = self.temp

        # ==== Load morphology from hoc template ====
        self.cell = h.BC_Euler9_ON()
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
        sec.insert("Bip_CaL")
        sec.insert("Bip_CaT")
        sec.insert("Bip_caconc")
        sec.insert("Bip_KCa")
        sec.insert("Bip_Kir")
        sec.insert("Bip_Kv")
        sec.insert("Bip_Na")
        sec.eh = self.eh
        sec.ek = self.ek
        sec.ena = self.ena

        # --- dendrites ---
        for sec in self.dendritic:
            sec.insert("Bip_Na")
            sec.ena = self.ena

        # --- axon ---
        for sec in self.axonal:
            sec.insert("Bip_Na")
            sec.ena = self.ena

        # --- terminals ---
        for sec in self.terminal:
            sec.insert("Bip_HCN1")
            sec.insert("Bip_HCN2")
            sec.insert("Bip_HCN4")
            sec.insert("Bip_Na")
            sec.eh = self.eh
            sec.ena = self.ena

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
