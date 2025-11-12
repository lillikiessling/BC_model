NEURON {
    SUFFIX Bip_HCN2
    USEION h READ eh WRITE ih
    RANGE ghcn2_bar, ih
    GLOBAL m_inf, tau_m
    RANGE vshift
}

UNITS {
    (mA) = (milliamp)
    (mV) = (millivolt)
    (mS) = (millisiemens)
}

PARAMETER {
    ghcn2_bar = 0.1 (mS/cm2)  : From ON-type CBC section 
    vshift = -53.08 (mV)
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
    ih = ghcn2_bar * m * (v - eh)
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
    : m (activation) steady-state and tau 
    m_inf = 1 / (1 + exp((vred + 42) / 6.2))
    tau_m = 120  : constant tau_m 
}