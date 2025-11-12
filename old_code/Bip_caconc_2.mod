NEURON {
    SUFFIX Bip_caconc_old
    USEION ca READ ica
    GLOBAL tau, ca_res, F, ek
    RANGE depth, eca_t, cai, cao
}

UNITS {
    (mM) = (milli/liter)
    (uM) = (micro/liter)
    (mA) = (milliamp)
    (um) = (micrometer)
    (uF) = (microfarad)
}

PARAMETER {
    tau = 1.5 (ms)         : Time constant for Ca removal
    ca_res = 0.15 (uM)     : Minimal residual Ca2+ concentration
    F = 96489 (C/M)        : Faraday constant
    ek = -58 (mV)          : K+ reversal potential (used for EcaT mixing)
    depth = 1 (um)         : Thickness of submembrane Ca shell
    cao = 1800 (uM)        : Extracellular Ca2+ concentration
}

ASSIGNED {
    ica (mA/cm2)
    eca_t (mV)
    area (cm2)
}

STATE {
    cai (uM)
}

INITIAL {
    cai = 0.1501  : Initial [Ca2+]i for ON-type CBC
    eca_t = (26.7 * log(cao / (cai + 1e-12))) * 0.45 + ek * 0.55 : add Temperature factor instead of default Nernst
}


BREAKPOINT {
    SOLVE conc METHOD derivimplicit
    eca_t = (26.7 * log(cao / (cai + 1e-12))) * 0.45 + ek * 0.55
}

DERIVATIVE conc {
    LOCAL s, v

    : compute local surface and volume for this segment
    : area() gives um2, convert to dm2 for consistency with dissertation
    s = area * 1e-8        
    v = s * depth * 1e-4   

    cai' = - (ica * s) / (2 * F * v) - ((cai - ca_res) / tau)
}


