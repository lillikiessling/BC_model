NEURON {
	THREADSAFE
    	SUFFIX Bip_Ca
    	USEION ca READ eca, cai WRITE ica
        USEION k READ ek WRITE ik
    	RANGE gcalbar, gcatbar, gkcabar
    	RANGE m_inf, h_inf, c_inf, n_inf, p_inf
    	RANGE m_tau, h_tau, c_tau, n_tau, p_tau
		RANGE vshift_CaT, vshift_CaL, vshift_KCa
}

:m and h is used for Bip_CaL
:n and p is used for Bip_CaT
:c is used for Bip_KCa

UNITS {
	(molar) = 	(1/liter)
	(mA) = 		(milliamp)
	(mV) = 		(millivolt)
	(mS) = 		(millisiemens)
}



PARAMETER {
    gcalbar = 0.4352	(mS/cm2)
    gcatbar = 0.954 	(mS/cm2)
    gkcabar = 360	    (mS/cm2)
    eca          	    (mV)
    cai = 0.1 		    (uM)
    dt           	    (ms)
    v            	    (mV)
    vshift_CaT = -80	(mV)
    vshift_CaL = -70	(mV)
    vshift_KCa = -53.08 (mV)	
}

STATE  {m h c n p}


INITIAL {
	rates(v)
	m = m_inf
    n = n_inf
	h = h_inf
    p = p_inf
	c = c_inf
}

ASSIGNED {
    ica    		(mA/cm2)
    ik        (mA/cm2)
    ical    	(mA/cm2)
    icat    	(mA/cm2)
    ek        (mV)
    m_inf h_inf c_inf n_inf p_inf
    m_tau h_tau c_tau n_tau p_tau
}


BREAKPOINT {
	SOLVE states METHOD cnexp
    	ical = (1e-3) * gcalbar * m*m*h * (v-(0.32*eca+0.68*-58))
        icat = (1e-3) * gcatbar * n*p * (v-(0.45*eca+0.55*-58))
        ica = ical + icat
        ik = gkcabar*c*c*((cai)/(cai+0.2)) * (v - ek)
}

DERIVATIVE states {
    rates(v)
    m' = (m_inf-m)/m_tau
    n' = (n_inf-n)/n_tau
    h' = (h_inf-h)/h_tau
    p' = (p_inf-p)/p_tau
    c' = (c_inf-c)/c_tau
}

PROCEDURE rates(v (mV)) {
    LOCAL v_CaL, v_CaT, v_KCa, am,bm,ah,bh,an,bn,ap,bp,ac,bc
    v_CaL = v - vshift_CaL
    v_CaT = v - vshift_CaT
    v_KCa = v - vshift_KCa

    : Bip_CaL m and h
    am = 0.427 * (v_CaL - 63) / (1 - exp(-(v_CaL - 63)/10.5))
	bm = 0.0406 * exp((70 - v_CaL)/12)
	m_tau = 1 / (am+bm)
	m_inf = am * m_tau
    h_tau = 292
    h_inf = 1 / (1 + exp((v_CaL/ 66.4)))

    : Bip_CaT n and p
    n_tau = 1.358 *(21.675 / (1 + exp((v + 39.9596) / 4.110392)))
    n_inf =  1 / (1 + exp(-(v + 37.5456) / 3.073015))
    p_tau = 65.8207 + 0.0023 * exp((v_CaT - 80) / 4.781719)
    p_inf = 1 / (1 + exp((v_CaT - 8.968) / 8.416382))

    : Bip_KCa c
    ac = (100 * (230-v_KCa)) / ((exp((230-v_KCa)/52)) - 1)
    bc = 120 * (exp((-v_KCa/95)))
    c_tau = 1 / (ac + bc) 
    c_inf = ac * c_tau
}

