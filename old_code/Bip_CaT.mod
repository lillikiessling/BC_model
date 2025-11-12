NEURON {
    SUFFIX Bip_CaT_lilli
    USEION ca READ cai, cao WRITE ica VALENCE 2
    USEION k READ ek
    RANGE gcatbar, m, h, ica, ecat
    RANGE vshift
}

UNITS {
    (mV) = (millivolt)
    (mA) = (milliamp)
    (S) = (siemens)
    (mS) = (millisiemens)
    (pS) = (picosiemens)
    (um) = (micron)
    FARADAY = 96485.3 (coul)
    R = 8.3134 (joule/degC)
}

PARAMETER {
    gcaT_bar = 2.715 (mS/cm2) : Maximum T-type calcium conductance
    z = 2
    cao = 1800 (uM)
    vshift = 0 (mV)
}

ASSIGNED {
    v (mV)
    celsius (degC)
    cai (uM)
    ek (mV)
    ecat (mV)
    ica (mA/cm2)
    alpha_m (1/ms)
    beta_m (1/ms)
    m_inf
    h_inf
    tau_m (ms)
    tau_h (ms)
    T (K)
}

STATE {
    m
    h
}

BREAKPOINT {
    SOLVE states METHOD cnexp
    ecat = 0.45 *(1000) * (R*T/(z*FARADAY)) * log(cao/cai) + 0.55 * ek
    ica = gcaT_bar * m * h * (v - ecat)
}


INITIAL {
    rates(v)
    m = m_inf
    h = h_inf
}

DERIVATIVE states {
    rates(v)
    m' = (m_inf - m) / tau_m
    h' = (h_inf - h) / tau_h
}

PROCEDURE rates(v (mV)) {
    LOCAL vred
    vred = v - vshift
    : m (activation) steady-state and tau
    m_inf = 1 / (1 + exp((vred - 37.5456) / (-3.073015)))
    tau_m = 1.358 + (21.675 / (1 + exp((vred - 39.9596) / 4.110392)))

    : h (inactivation) steady-state and tau
    h_inf = 1 / (1 + exp((vred - 8.968) / 8.416382))
    tau_h = 65.8207 + 0.0023 * exp((vred - 80) / 4.781719)
}