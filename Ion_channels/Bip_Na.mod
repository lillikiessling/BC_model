NEURON {
    SUFFIX Bip_Na
    USEION na READ ena WRITE ina
    RANGE gna_bar, ina
    RANGE m_inf, h_inf, tau_m, tau_h
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
    gna_bar = 2.22858 (mS/cm2): Maximum sodium conductance
}

ASSIGNED {
    v (mV)
    ena (mV)
    ina (mA/cm2)
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
    ina = gna_bar * m*m*m * h * (v - ena)
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
    LOCAL alpha_m, beta_m, alpha_h, beta_h

    :Sodium activation
    alpha_m = 0.271 * exp(v / 30.075) 
    beta_m  = 10 / (exp((v + 25.2619) / 10.1191) + 1) 
    tau_m = 1 / (alpha_m + beta_m)
    m_inf = alpha_m / (alpha_m + beta_m)

    :Sodium inactivation
    alpha_h = 0.3898 * exp((1.6482 - v)/12.2978) 
    beta_h  = 0.6624 / (exp((-44.9996 - v)/40) + 1) 
    tau_h = 1 / (alpha_h + beta_h) 
    h_inf = alpha_h / (alpha_h + beta_h)
}
