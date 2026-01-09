TITLE HH style Ca L-type channel

INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
	THREADSAFE
    	SUFFIX Bip_CaL
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
    	gcabar = 0.4352	(mS/cm2)
    	eca          	(mV)
    	dt           	(ms)
    	v            	(mV)
		vshift = -70.0	(mV)
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


BREAKPOINT {
	SOLVE states METHOD cnexp
    ica = (1e-3) * gcabar * m*m*h * (v-(0.32*eca+0.68*-58))
}


DERIVATIVE states {
    mrates(v)
	hrates(v)

	m' = (m_inf-m)/m_tau
    h' = (h_inf-h)/h_tau
}

PROCEDURE mrates(v) { LOCAL a,b, vred
	vred = v - vshift
	a = 0.427 * (vred - 63) / (1 - exp(-(vred - 63)/10.5))
	b = 0.0406 * exp((70 - vred)/12)
	m_tau = 1 / (a+b)
	m_inf = a * m_tau
}

PROCEDURE hrates(v) { LOCAL vred
	vred = v - vshift
	h_tau = 292
	h_inf = 1 / (1 + exp((vred / 66.4)))
}
