from neuron import h
import numpy as np

class DummyRGC:
    def __init__(self):
        self.cell = h.RGC_20170907_S2W1C1()

        self.soma = self.cell.soma
        self.axon = self.cell.axon
        self.dendritic = self.cell.dendritic
        self.all = self.cell.all

        self._set_nseg()
        self._insert_channels()

    def _set_nseg(self):
        for sec in self.all:
            sec.nseg = max(1, int(sec.L / 10))

    def _insert_channels(self):
        for sec in self.all:

            # Passive properties
            sec.Ra = 120
            sec.cm = 1.0
            sec.insert("pas")
            sec.g_pas = 1e-4
            sec.e_pas = -65

            # Active channels
            sec.insert("FCM")
            sec.insert("Bip_caconc")

            # reversal potentials
            sec.ena = 55
            sec.ek  = -80

            # simple uniform conductances for now
            for seg in sec:
                seg.gna12bar_FCM = 0.05
                seg.gna16bar_FCM = 0.05
                seg.gk12bar_FCM  = 0.02
                seg.gk16bar_FCM  = 0.02
                seg.gcabar_FCM   = 0.001
                seg.gkcabar_FCM  = 0.001

    def soma_v(self):
        return self.soma(0.5)._ref_v
