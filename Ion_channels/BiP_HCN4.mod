NEURON {
    SUFFIX Bip_HCN4
    USEION h READ eh WRITE ih
    RANGE ghcn4_bar, ih
    GLOBAL m_inf, tau_m
    RANGE vshift
}

UNITS {
    (mA) = (milliamp)
    (mV) = (millivolt)
    (mS) = (millisiemens)
}

PARAMETER {
    ghcn4_bar = 0.176 (mS/cm2)  
    vshift = -53.08  (mV)
}

ASSIGNED {
    v (mV)
    eh (mV)
    ih (mA/cm2)
    m_inf
    tau_m (ms)
}

STATE {
    m
}

BREAKPOINT {
    SOLVE states METHOD cnexp
    ih = ghcn4_bar * m * (v - eh)
}

INITIAL {
    rates(v)
    m = m_inf
}

DERIVATIVE states {
    rates(v)
    m' = (m_inf - m) / tau_m
}

PROCEDURE rates(v (mV)) {
    LOCAL vred
    vred = v - vshift
    m_inf = 1 / (1 + exp((vred + 60) / 9.6))
    tau_m = 461
}