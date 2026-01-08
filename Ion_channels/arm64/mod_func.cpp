#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern "C" void _BiP_HCN4_reg(void);
extern "C" void _Bip_Ca_reg(void);
extern "C" void _Bip_CaL_reg(void);
extern "C" void _Bip_CaT_reg(void);
extern "C" void _Bip_HCN1_reg(void);
extern "C" void _Bip_HCN2_reg(void);
extern "C" void _Bip_KCa_reg(void);
extern "C" void _Bip_Kir_reg(void);
extern "C" void _Bip_Kv_reg(void);
extern "C" void _Bip_Na_reg(void);
extern "C" void _FCM_reg(void);
extern "C" void _Sikora_cas_reg(void);
extern "C" void _Sikora_ribbon_tiger_reg(void);
extern "C" void _Sikora_spike_reg(void);
extern "C" void _Sikora_tsbp_reg(void);
extern "C" void _Xtra_reg(void);
extern "C" void _capump_reg(void);
extern "C" void _modulate_reg(void);
extern "C" void _ribbon_tiger_reg(void);

extern "C" void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \"BiP_HCN4.mod\"");
    fprintf(stderr, " \"Bip_Ca.mod\"");
    fprintf(stderr, " \"Bip_CaL.mod\"");
    fprintf(stderr, " \"Bip_CaT.mod\"");
    fprintf(stderr, " \"Bip_HCN1.mod\"");
    fprintf(stderr, " \"Bip_HCN2.mod\"");
    fprintf(stderr, " \"Bip_KCa.mod\"");
    fprintf(stderr, " \"Bip_Kir.mod\"");
    fprintf(stderr, " \"Bip_Kv.mod\"");
    fprintf(stderr, " \"Bip_Na.mod\"");
    fprintf(stderr, " \"FCM.mod\"");
    fprintf(stderr, " \"Sikora_cas.mod\"");
    fprintf(stderr, " \"Sikora_ribbon_tiger.mod\"");
    fprintf(stderr, " \"Sikora_spike.mod\"");
    fprintf(stderr, " \"Sikora_tsbp.mod\"");
    fprintf(stderr, " \"Xtra.mod\"");
    fprintf(stderr, " \"capump.mod\"");
    fprintf(stderr, " \"modulate.mod\"");
    fprintf(stderr, " \"ribbon_tiger.mod\"");
    fprintf(stderr, "\n");
  }
  _BiP_HCN4_reg();
  _Bip_Ca_reg();
  _Bip_CaL_reg();
  _Bip_CaT_reg();
  _Bip_HCN1_reg();
  _Bip_HCN2_reg();
  _Bip_KCa_reg();
  _Bip_Kir_reg();
  _Bip_Kv_reg();
  _Bip_Na_reg();
  _FCM_reg();
  _Sikora_cas_reg();
  _Sikora_ribbon_tiger_reg();
  _Sikora_spike_reg();
  _Sikora_tsbp_reg();
  _Xtra_reg();
  _capump_reg();
  _modulate_reg();
  _ribbon_tiger_reg();
}
