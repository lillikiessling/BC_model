INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}
NEURON {
    SUFFIX Bip_caconc_lilli
    USEION ca READ ica, cai WRITE cai
    RANGE depth,cainf,taur
    RANGE ca_init
}

UNITS {
    (molar) = (1/liter)        
    (mM)    = (millimolar)
    (um)    = (micron)
    (mA)    = (milliamp)
    (msM)   = (ms mM)
}
CONSTANT {
    FARADAY = 96489     (coul)      
}
PARAMETER {
    depth   = 0.1    (um)       : depth of shell
    taur    = 1.5    (ms)       : remove first-order decay
    :cainf   = 0.15 (uM)
    cainf    = 0.05 (uM)
    :ca_init = 0.1503 (uM)
    ca_init = 0.1 (uM)
}
STATE {
    cai     (uM) 
}

INITIAL {
    cai = ca_init
}

ASSIGNED {
    ica     (mA/cm2)
    drive_channel   (mM/ms)
    drive_pump  (mM/ms)
}
    
BREAKPOINT {
    SOLVE state METHOD derivimplicit
}
DERIVATIVE state { 
: Surface to volume ratio of a cylinder is approximated as 1/depth for very small values of depth
: More precicely the ratio is   2 / ( (depth)^2 / (diam/2 - (2 * depth)) )
    drive_channel =  - (10000) * ica / (2 * FARADAY * depth)
    :if (drive_channel <= 0.) { drive_channel = 0. }  : cannot pump below resting level
    cai' = drive_channel + (cainf-cai)/taur
}