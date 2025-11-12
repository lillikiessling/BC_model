NEURON {
    SUFFIX Bip_KCa
    USEION ca READ cai
    USEION k READ ek WRITE ik
    RANGE gkcabar
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
	gkcabar = 360	(mS/cm2)
	dt           	(ms)
	v            	(mV)
	vshift = -53.08 (mV)
}



ASSIGNED {
    ica    		(mA/cm2)
    m_inf
    tau_m
    ik         (mA/cm2)
    ek         (mV)
    cai        (uM)
}


BREAKPOINT {
    SOLVE states METHOD cnexp
    ik = gkcabar*m*m*((cai)/(cai+0.2)) * (v - ek)
}

STATE {
    m
}

INITIAL {
    rates(v)
    m = m_inf
}


DERIVATIVE states {
    rates(v)
    m' = (m_inf - m)/tau_m
}


UNITSOFF
PROCEDURE rates(v(mV)) { LOCAL a,b,am,bm, vred
vred = v - vshift

am = (100 * (230-vred)) / ((exp((230-vred)/52)) - 1)
bm = 120 * (exp((-vred/95)))
tau_m = 1 / (am + bm) 
m_inf = am * tau_m

}
UNITSON