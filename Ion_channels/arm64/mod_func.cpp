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
extern "C" void _capump_reg(void);
extern "C" void _cas_Sikora_reg(void);
extern "C" void _modulate_reg(void);
extern "C" void _ribbon_synapse_reg(void);
extern "C" void _ribbon_tiger_Sikora_reg(void);
extern "C" void _ribbon_tiger_simple_reg(void);
extern "C" void _spike_Sikora_reg(void);
extern "C" void _tsbp_Sikora_reg(void);
extern "C" void _xtra_reg(void);

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
    fprintf(stderr, " \"capump.mod\"");
    fprintf(stderr, " \"cas_Sikora.mod\"");
    fprintf(stderr, " \"modulate.mod\"");
    fprintf(stderr, " \"ribbon_synapse.mod\"");
    fprintf(stderr, " \"ribbon_tiger_Sikora.mod\"");
    fprintf(stderr, " \"ribbon_tiger_simple.mod\"");
    fprintf(stderr, " \"spike_Sikora.mod\"");
    fprintf(stderr, " \"tsbp_Sikora.mod\"");
    fprintf(stderr, " \"xtra.mod\"");
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
  _capump_reg();
  _cas_Sikora_reg();
  _modulate_reg();
  _ribbon_synapse_reg();
  _ribbon_tiger_Sikora_reg();
  _ribbon_tiger_simple_reg();
  _spike_Sikora_reg();
  _tsbp_Sikora_reg();
  _xtra_reg();
}
