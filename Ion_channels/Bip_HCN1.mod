NEURON {
    SUFFIX Bip_HCN1
    USEION h READ eh WRITE ih
    RANGE ghcn1_bar, ih
    GLOBAL m_inf, tau_m
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
    ghcn1_bar = 0.1128 (mS/cm2) : Maximum HCN1 conductance
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
    ih = ghcn1_bar * m * (v - eh)
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
    : m (activation) rates
    m_inf = 1 / (1+exp((v-39)/6.6)) - 0.0027
    tau_m = 60 : constant
}