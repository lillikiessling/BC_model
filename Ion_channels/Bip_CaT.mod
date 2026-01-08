TITLE HH style Ca T-type channel

INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
	THREADSAFE
    	SUFFIX Bip_CaT
    	USEION ca READ eca WRITE ica
    	RANGE gcabar
    	RANGE m_inf, h_inf
    	RANGE m_tau, h_tau
		RANGE vshift
}

UNITS {
	(molar) = 	(1/liter)
	(mA) = 		(milliamp)
	(mV) = 		(millivolt)
	(mS) = 		(millisiemens)

}

PARAMETER {
	gcabar = 0.954 	(mS/cm2)
	eca          	(mV)
	dt           	(ms)
	v            	(mV)
	:vshift = -80.0  (mV)
	vshift = -53.08  (mV)
}

STATE { m h }

INITIAL {
	mrates(v)
	m = m_inf
	hrates(v)
	h = h_inf
}

ASSIGNED {
    	ica    		(mA/cm2)
    	m_inf h_inf
    	m_tau h_tau
}

INITIAL { 
	mrates(v)
	hrates(v)

	m = m_inf
	h = h_inf
}

BREAKPOINT {
	SOLVE states METHOD cnexp
    	ica = (1e-3) * gcabar * m*h * (v-(0.45*eca+0.55*-58))
}

DERIVATIVE states {
    	mrates(v)
	hrates(v)

	m' = (m_inf-m)/m_tau
        h' = (h_inf-h)/h_tau
}

PROCEDURE mrates(v) { LOCAL a,b
	:m_tau = (1.36*(21.68)) / (1+exp((v+40.04)/4.11))
	m_tau = 1.358 *(21.675 / (1 + exp((v + 39.9596) / 4.110392)))
	:m_inf = 1/(1+exp(-(v+42.45)/3.07))
	m_inf =  1 / (1 + exp(-(v + 37.5456) / 3.073015))
}

PROCEDURE hrates(v) { LOCAL vred
	vred = v - vshift
	:h_tau = 65.82 + 0.0023*exp((v-0)/4.78)
	h_tau = 65.8207 + 0.0023 * exp((vred - 80) / 4.781719)
	:h_inf = 1/(1+exp((v+71.03)/8.42))
	h_inf = 1 / (1 + exp((vred - 8.968) / 8.416382))
}


