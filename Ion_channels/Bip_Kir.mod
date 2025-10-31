NEURON {
    SUFFIX Bip_Kir
    USEION k READ ek WRITE ik
    RANGE gkir_bar, ik
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
    gkir_bar = 0.175 (mS/cm2) : Maximum inward rectifier potassium conductance
}

ASSIGNED {
    v (mV)
    ek (mV)
    ik (mA/cm2)
    m_inf
    tau_m (ms)
}

STATE {
    m
}

BREAKPOINT {
    SOLVE states METHOD cnexp
    ik = gkir_bar * m * (v - ek)
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
    LOCAL alpha_m, beta_m
    
    : m (activation) rates
    alpha_m = 0.13289 * exp((v-8.94)/-6.3902)
    beta_m = 0.16994 * exp((v-48.94)/27.714)
    m_inf = alpha_m / (alpha_m + beta_m)
    tau_m = 1 / (alpha_m + beta_m)
}