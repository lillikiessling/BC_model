#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern "C" void _Bip_CaL_reg(void);
extern "C" void _Bip_CaT_reg(void);
extern "C" void _Bip_HCN1_reg(void);
extern "C" void _Bip_HCN2_reg(void);
extern "C" void _Bip_Kir_reg(void);
extern "C" void _Bip_Kv_reg(void);
extern "C" void _Bip_Na_reg(void);
extern "C" void _Bip_caconc_reg(void);
extern "C" void _Bip_caconc_2_reg(void);
extern "C" void _Horizontal_INa_reg(void);

extern "C" void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \"Bip_CaL.mod\"");
    fprintf(stderr, " \"Bip_CaT.mod\"");
    fprintf(stderr, " \"Bip_HCN1.mod\"");
    fprintf(stderr, " \"Bip_HCN2.mod\"");
    fprintf(stderr, " \"Bip_Kir.mod\"");
    fprintf(stderr, " \"Bip_Kv.mod\"");
    fprintf(stderr, " \"Bip_Na.mod\"");
    fprintf(stderr, " \"Bip_caconc.mod\"");
    fprintf(stderr, " \"Bip_caconc_2.mod\"");
    fprintf(stderr, " \"Horizontal_INa.mod\"");
    fprintf(stderr, "\n");
  }
  _Bip_CaL_reg();
  _Bip_CaT_reg();
  _Bip_HCN1_reg();
  _Bip_HCN2_reg();
  _Bip_Kir_reg();
  _Bip_Kv_reg();
  _Bip_Na_reg();
  _Bip_caconc_reg();
  _Bip_caconc_2_reg();
  _Horizontal_INa_reg();
}
