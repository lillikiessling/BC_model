TITLE Bipolar Cell Calcium Concentration Mechanism (ON-type)


NEURON {
    SUFFIX Bip_caconc
    USEION ca READ ica WRITE cai VALENCE 2
    RANGE cai, taur, area_um2, vol_um3
}

UNITS {
    (mV) = (millivolt)
    (mA) = (milliamp)
    (um) = (micron)
    (molar) = (1/liter)
    (uM) = (micromolar)
    FARADAY = (faraday) (coulomb)
    R = (k-mole) (joule/degC)
}

PARAMETER {
    ca_res = 0.15 (uM)
    taur = 1.5 (ms)
    area_um2 = 0 (um2)   : section surface area auto-detect
    vol_um3  = 0 (um3)   : submembrane volume auto-compute from area
    shell_thickness = 0.1 (um)
}

ASSIGNED {
    ica (mA/cm2)
    eca (mV)
    areal (um2)
    voll  (um3)
}

STATE { cai (uM) }

INITIAL {
    cai = 0.1501 (uM)

    : compute local surface and volume for this segment
    if (vol_um3 <= 0) {
        voll = areal * shell_thickness
    } else {
        voll = vol_um3
    }
}

BREAKPOINT {
    SOLVE state METHOD cnexp
}

DERIVATIVE state {
    : Convert area (um2) and volume (um3) 1e-8 converts mA/cm2 to nA/um2, the 1e6 converts mol/L to uM
    cai' = - (1e-8 * ica * areal) / (2 * FARADAY * voll) * 1e6 + (ca_res - cai)/taur
}