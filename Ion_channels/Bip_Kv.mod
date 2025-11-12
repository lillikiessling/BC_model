NEURON {
    SUFFIX Bip_Kv
    USEION k READ ek WRITE ik
    RANGE gk_bar, ik
    GLOBAL m_inf, h_inf, tau_m, tau_h
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
    gk_bar = 14.3357 (mS/cm2) : Maximum potassium conductance
    vshift = -53.08  (mV) 
}

ASSIGNED {
    v (mV)
    ek (mV)
    ik (mA/cm2)
    m_inf
    h_inf
    tau_m (ms)
    tau_h (ms)
}

STATE {
    m
    h
}

BREAKPOINT {
    SOLVE states METHOD cnexp
    ik = gk_bar * m^2 * h * (v - ek)
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
    m_inf = 1 / (1 + exp((vred - 50) / (-12.3)))
    tau_m = 2.0304 + (27.913114 / (1 + exp((vred - 27.4141) / 55.704638)))

    : h (inactivation) steady-state and tau 
    h_inf = 0.05 + (0.95 / (1 + exp((vred - 23.2939) / 19.385636)))
    tau_h = 199.78 + 2776.11 * exp((-vred - 5) / 55)
}