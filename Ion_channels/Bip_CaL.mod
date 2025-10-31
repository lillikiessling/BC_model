TITLE Bipolar Cell L-type Calcium Channel (ON-type with weighted reversal potential)

NEURON {
    SUFFIX Bip_CaL
    USEION ca READ cai, cao WRITE ica VALENCE 2
    USEION k READ ek
    RANGE gcalbar, m, h, ica, ecal, vshift, m_inf, h_inf
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
    gcalbar = 0.4352 (mho/cm2)
    z = 2
    cao = 1800 (uM)
    vshift = 90 (mV)
}

ASSIGNED {
    v (mV)
    celsius (degC)
    cai (uM)
    ek (mV)
    ecal (mV)
    ica (mA/cm2)
    alpha_m (1/ms)
    beta_m (1/ms)
    m_inf
    h_inf
    tau_m (ms)
    tau_h (ms)
    T (K)
}

STATE { m h }

INITIAL {
    T = celsius + 273.15
    rates(v)
    m = m_inf
    h = h_inf
}


BREAKPOINT {
    SOLVE states METHOD cnexp
    ecal = 0.32 *(1000) * (R*T/(z*FARADAY)) * log(cao/cai) + 0.68 * ek
    ica  = gcalbar * m^2 * h * (v - ecal)
}

DERIVATIVE states {
    rates(v)
    m' = (m_inf - m)/tau_m
    h' = (h_inf - h)/tau_h
}


PROCEDURE rates(v(mV)) {
    LOCAL v2
    v2 = v + vshift
    alpha_m = 0.427 * (v2 - 63) / (1 - exp(-(v2 - 63)/10.5))
    beta_m = 0.0406 * exp((70 - v2)/12)
    m_inf = alpha_m / (alpha_m + beta_m)
    tau_m = 1 / (alpha_m + beta_m)
    h_inf = 1 / (1 + exp((v2 / 66.4)))
    tau_h = 292
}
