TITLE HH style channels for spiking retinal ganglion cells
:
: Modified from Fohlmeister et al., 2010
: must be used with calcium pump mechanism, i.e. capump.mod


INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
	THREADSAFE
    	SUFFIX FCM
    	USEION na READ ena WRITE ina
    	USEION k READ ek WRITE ik
    	USEION ca READ cai, eca, cao WRITE ica
    	RANGE gna12bar, gna16bar, gk12bar, gk16bar, gcabar, gkcabar
    	RANGE m12_inf, h12_inf, m16_inf, h16_inf, n12_inf, n16_inf, c_inf
    	RANGE m12_tau, h12_tau, m16_tau, h16_tau, n12_tau, n16_tau, c_tau
    	RANGE ik12, ik16, ikca
	RANGE ina12, ina16
}

UNITS {
    	(molar) = 	(1/liter)
    	(mM) = 		(millimolar)
    	(mA) = 		(milliamp)
    	(mV) = 		(millivolt)
	(mS) = 		(millisiemens)

}

PARAMETER {
    	gna12bar		(mS/cm2)
		gna16bar		(mS/cm2)
    	gk12bar 		(mS/cm2)
		gk16bar 		(mS/cm2)
    	gcabar   	(mS/cm2)
    	gkcabar 		(mS/cm2)
    	ena		(mV)
    	ek	  	(mV)
    	eca          	(mV)
    	cao = 1.8 	(mM)
    	cai = 0.0001 	(mM)
		cadis = 0.001	(mM)
    	dt           	(ms)
    	v            	(mV)
}

STATE { m12 h12 m16 h16 n12 n16 c }

INITIAL {
	m12rates(v)
	m12 = m12_inf
	h12rates(v)
	h12 = h12_inf
	m16rates(v)
	m16 = m16_inf
	h16rates(v)
	h16 = h16_inf
	n12rates(v)
	n12 = n12_inf
	n16rates(v)
	n16 = n16_inf
	crates(v)
	c = c_inf
}

ASSIGNED {
	ina     		(mA/cm2)
    	ina12   		(mA/cm2)
	ina16   		(mA/cm2)
    	ik     		(mA/cm2)
	ik12   		(mA/cm2)
	ik16   		(mA/cm2)
    	ikca   		(mA/cm2)
    	ica    		(mA/cm2)
    	m12_inf h12_inf m16_inf h16_inf n12_inf n16_inf c_inf
    	m12_tau h12_tau m16_tau h16_tau n12_tau n16_tau c_tau
}

INITIAL { 
	m12rates(v)
	h12rates(v)
	m16rates(v)
	h16rates(v)
	n12rates(v)
	n16rates(v)
	crates(v)

	m12 = m12_inf
	h12 = h12_inf
	m16 = m16_inf
	h16 = h16_inf
	n12 = n12_inf
	n16 = n16_inf
	c = c_inf
}

BREAKPOINT {
	SOLVE states METHOD cnexp
    	ina12 = (1e-3) * gna12bar * m12*m12*m12*h12 * (v-ena)
	ina16 = (1e-3) * gna16bar * m16*m16*m16*h16 * (v-ena)
	ina = ina12 + ina16
    	ik12 = (1e-3) * gk12bar * n12*n12*n12*n12 * (v-ek)
	ik16 = (1e-3) * gk16bar * n16*n16*n16*n16 * (v-ek)
    	ikca = (1e-3) * gkcabar * ((cai/cadis) / (1+(cai/cadis))) * (v-ek)
	ik = ik12 + ik16 + ikca
    	ica = (1e-3) * gcabar * c*c*c * (v-eca)
}

DERIVATIVE states {
    	m12rates(v)
	h12rates(v)
	m16rates(v)
	h16rates(v)
	n12rates(v)
	n16rates(v)
	crates(v)

	m12' = (m12_inf-m12)/m12_tau
        	h12' = (h12_inf-h12)/h12_tau
	m16' = (m16_inf-m16)/m16_tau
        	h16' = (h16_inf-h16)/h16_tau
	n12' = (n12_inf-n12)/n12_tau
	n16' = (n16_inf-n16)/n16_tau
	c' = (c_inf-c)/c_tau
}

PROCEDURE m12rates(v) { LOCAL a,b
	a = (-2.725*(v+35)) / (exp(-0.1*(v+35))-1)
	b = 90.83 * exp(-(v+60)/20)
	m12_tau = 1 / (a+b)
	m12_inf = a * m12_tau
}

PROCEDURE h12rates(v) { LOCAL a,b
	a = 1.817 * exp(-(v+52)/20)
	b = 27.25 / (exp(-0.1*(v+22))+1)
	h12_tau = 1 / (a+b)
	h12_inf = a * h12_tau
}

PROCEDURE m16rates(v) { LOCAL a,b
	a = (-2.725*(v+41)) / (exp(-0.1*(v+41))-1)
	b = 90.83 * exp(-(v+66)/15)
	m16_tau = 1 / (a+b)
	m16_inf = a * m16_tau
}

PROCEDURE h16rates(v) { LOCAL a,b
	a = 1.817 * exp(-(v+58)/20)
	b = 27.25 / (exp(-0.1*(v+28))+1)
	h16_tau = 1 / (a+b)
	h16_inf = a * h16_tau
}

PROCEDURE n12rates(v) { LOCAL a,b
	a = (-0.09575*(v+37)) / ((exp(-0.1*(v+37))-1))
	b = 1.915 * exp(-(v+47)/80)
	n12_tau = 1 / (a+b)
	n12_inf = a * n12_tau
}

PROCEDURE n16rates(v) { LOCAL a,b
	a = (-0.09575*(v+43)) / ((exp(-0.1*(v+43))-1))
	b = 1.915 * exp(-(v+53)/80)
	n16_tau = 1 / (a+b)
	n16_inf = a * n16_tau
}

PROCEDURE crates(v) { LOCAL a,b
	a = (-1.362*(v+13)) / (exp(-0.1*(v+13))-1)
	b = 45.41 * exp(-(v+38)/18)
	c_tau = 1 / (a+b)
	c_inf = a * c_tau
}
