TITLE HH style channels for spiking retinal ganglion cells
:
: Modified from Fohlmeister et al., 2010
: must be used with calcium pump mechanism, i.e. capump.mod


INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
	THREADSAFE
    	SUFFIX FCM_Anna
    	USEION na READ ena WRITE ina
    	USEION k READ ek WRITE ik
    	USEION ca READ cai, eca, cao WRITE ica
    	RANGE gnabar, gkbar, gcabar, gkcabar
    	RANGE m_inf, h_inf, n_inf, c_inf
    	RANGE m_tau, h_tau, n_tau, c_tau
    	RANGE ik, ik_, ikca
	RANGE ina
}

UNITS {
    	(molar) = 	(1/liter)
    	(mM) = 		(millimolar)
    	(mA) = 		(milliamp)
    	(mV) = 		(millivolt)
		(mS) = 		(millisiemens)

}

PARAMETER {
    	gnabar		(mS/cm2)
    	gkbar 		(mS/cm2)
    	gcabar   	(mS/cm2)
    	gkcabar 	(mS/cm2)
    	ena				(mV)
    	ek	  			(mV)
    	eca          	(mV)
    	cao = 1.8 		(mM)
    	cai = 0.0001 	(mM)
		cadis = 0.001	(mM)
    	dt           	(ms)
    	v            	(mV)
}

STATE { m h n c }

INITIAL {
	mrates(v)
	m = m_inf
	hrates(v)
	h = h_inf
	nrates(v)
	n = n_inf
	crates(v)
	c = c_inf
}

ASSIGNED {
	ina     	(mA/cm2)
    ik     		(mA/cm2)
	ik_    		(mA/cm2)
    ikca   		(mA/cm2)
    ica    		(mA/cm2)
    m_inf h_inf n_inf c_inf
    m_tau h_tau n_tau c_tau
}

INITIAL { 
	mrates(v)
	hrates(v)
	nrates(v)
	crates(v)

	m = m_inf
	h = h_inf
	n = n_inf
	c = c_inf
}

BREAKPOINT {
	SOLVE states METHOD cnexp
    	ina = (1e-3) * gnabar * m*m*m*h * (v-ena)
    	ik_ = (1e-3) * gkbar * n*n*n*n * (v-ek)
    	ikca = (1e-3) * gkcabar * ((cai/cadis) / (1+(cai/cadis))) * (v-ek)
		ik = ik_ + ikca
    	ica = (1e-3) * gcabar * c*c*c * (v-eca)
}

DERIVATIVE states {
    mrates(v)
	hrates(v)
	nrates(v)
	crates(v)

	m' = (m_inf-m)/m_tau
        h' = (h_inf-h)/h_tau
	n' = (n_inf-n)/n_tau
	c' = (c_inf-c)/c_tau
}

PROCEDURE mrates(v) { LOCAL a,b
	a = (-2.725*(v+35)) / (exp(-0.1*(v+35))-1)
	b = 90.83 * exp(-(v+60)/20)
	m_tau = 1 / (a+b)
	m_inf = a * m_tau
}

PROCEDURE hrates(v) { LOCAL a,b
	a = 1.817 * exp(-(v+52)/20)
	b = 27.25 / (exp(-0.1*(v+22))+1)
	h_tau = 1 / (a+b)
	h_inf = a * h_tau
}

PROCEDURE nrates(v) { LOCAL a,b
	a = (-0.09575*(v+37)) / ((exp(-0.1*(v+37))-1))
	b = 1.915 * exp(-(v+47)/80)
	n_tau = 1 / (a+b)
	n_inf = a * n_tau
}

PROCEDURE crates(v) { LOCAL a,b
	a = (-1.362*(v+13)) / (exp(-0.1*(v+13))-1)
	b = 45.41 * exp(-(v+38)/18)
	c_tau = 1 / (a+b)
	c_inf = a * c_tau
}
