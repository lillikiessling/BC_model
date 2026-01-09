: $Id: xtra.mod,v 1.3 2009/02/24 00:52:07 ted Exp ted $


NEURON {
	SUFFIX xtra
	RANGE rx, rx2, er, RPSim_Ex
	RANGE x, y, z
	GLOBAL is, is2
	POINTER im, ex
}

PARAMETER {
	: default transfer resistance between stim electrodes and axon
	rx  = 1 (megohm) : mV/nA
	rx2 = 1 (megohm) : mV/nA
	RPSim_Ex = 0	(millivolts)
	trigger = 0 (1)
	x = 0 (1) : spatial coords
	y = 0 (1)
	z = 0 (1)
}

ASSIGNED {
	v (millivolts)
	is (milliamp)
	is2 (milliamp)
	ex (millivolts)
	im (milliamp/cm2)
	er (microvolts)
	area (micron2)
}

INITIAL {
	ex = RPSim_Ex*trigger :+ is2*rx2*(1e6)
	er = (10)*rx*im*area
}

:BEFORE BREAKPOINT { : before each cy' = f(y,t) setup
:  ex = is*rx*(1e6) + is2*rx2*(1e6)}

:BEFORE BREAKPOINT { : before each cy' = f(y,t) setup
:  ex = RPSim_Ex*trigger :+ is2*rx2*(1e6)
:}

BEFORE BREAKPOINT { : before each cy' = f(y,t) setup
  ex = is*rx*(1e6) + is2*rx2*(1e6) + RPSim_Ex*trigger
}

AFTER SOLVE { 
  er = (10)*rx*im*area
}

