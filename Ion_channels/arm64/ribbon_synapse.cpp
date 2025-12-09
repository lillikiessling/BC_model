/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#define _pval pval
// clang-format off
#include "md1redef.h"
#include "section_fwd.hpp"
#include "nrniv_mf.h"
#include "md2redef.h"
#include "nrnconf.h"
// clang-format on
#include "neuron/cache/mechanism_range.hpp"
#include <vector>
using std::size_t;
static auto& std_cerr_stream = std::cerr;
static constexpr auto number_of_datum_variables = 3;
static constexpr auto number_of_floating_point_variables = 142;
namespace {
template <typename T>
using _nrn_mechanism_std_vector = std::vector<T>;
using _nrn_model_sorted_token = neuron::model_sorted_token;
using _nrn_mechanism_cache_range = neuron::cache::MechanismRange<number_of_floating_point_variables, number_of_datum_variables>;
using _nrn_mechanism_cache_instance = neuron::cache::MechanismInstance<number_of_floating_point_variables, number_of_datum_variables>;
using _nrn_non_owning_id_without_container = neuron::container::non_owning_identifier_without_container;
template <typename T>
using _nrn_mechanism_field = neuron::mechanism::field<T>;
template <typename... Args>
void _nrn_mechanism_register_data_fields(Args&&... args) {
  neuron::mechanism::register_data_fields(std::forward<Args>(args)...);
}
}
 
#if !NRNGPU
#undef exp
#define exp hoc_Exp
#if NRN_ENABLE_ARCH_INDEP_EXP_POW
#undef pow
#define pow hoc_pow
#endif
#endif
 
#define nrn_init _nrn_init__ribbon_synapse
#define _nrn_initial _nrn_initial__ribbon_synapse
#define nrn_cur _nrn_cur__ribbon_synapse
#define _nrn_current _nrn_current__ribbon_synapse
#define nrn_jacob _nrn_jacob__ribbon_synapse
#define nrn_state _nrn_state__ribbon_synapse
#define _net_receive _net_receive__ribbon_synapse 
#define RVPSIZE RVPSIZE__ribbon_synapse 
#define _f_rates _f_rates__ribbon_synapse 
#define kstates kstates__ribbon_synapse 
#define rates rates__ribbon_synapse 
#define vesicle_release vesicle_release__ribbon_synapse 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _internalthreadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
#define _internalthreadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *hoc_getarg(int);
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define S _ml->template fpfield<0>(_iml)
#define S_columnindex 0
#define W _ml->template fpfield<1>(_iml)
#define W_columnindex 1
#define powr _ml->template fpfield<2>(_iml)
#define powr_columnindex 2
#define K1 _ml->template fpfield<3>(_iml)
#define K1_columnindex 3
#define CAthresh _ml->template fpfield<4>(_iml)
#define CAthresh_columnindex 4
#define preCAnow _ml->template fpfield<5>(_iml)
#define preCAnow_columnindex 5
#define erev _ml->template fpfield<6>(_iml)
#define erev_columnindex 6
#define erevN _ml->template fpfield<7>(_iml)
#define erevN_columnindex 7
#define gmax _ml->template fpfield<8>(_iml)
#define gmax_columnindex 8
#define gmaxN _ml->template fpfield<9>(_iml)
#define gmaxN_columnindex 9
#define StanddAMPA _ml->template fpfield<10>(_iml)
#define StanddAMPA_columnindex 10
#define StandNMDA _ml->template fpfield<11>(_iml)
#define StandNMDA_columnindex 11
#define xC0 _ml->template fpfield<12>(_iml)
#define xC0_columnindex 12
#define xC1 _ml->template fpfield<13>(_iml)
#define xC1_columnindex 13
#define xC2 _ml->template fpfield<14>(_iml)
#define xC2_columnindex 14
#define xD _ml->template fpfield<15>(_iml)
#define xD_columnindex 15
#define xOO _ml->template fpfield<16>(_iml)
#define xOO_columnindex 16
#define mg _ml->template fpfield<17>(_iml)
#define mg_columnindex 17
#define AbsRefract _ml->template fpfield<18>(_iml)
#define AbsRefract_columnindex 18
#define rate_constant _ml->template fpfield<19>(_iml)
#define rate_constant_columnindex 19
#define tau_dAMPA _ml->template fpfield<20>(_iml)
#define tau_dAMPA_columnindex 20
#define tau_NMDA _ml->template fpfield<21>(_iml)
#define tau_NMDA_columnindex 21
#define glumax_dAMPA _ml->template fpfield<22>(_iml)
#define glumax_dAMPA_columnindex 22
#define glumax_NMDA _ml->template fpfield<23>(_iml)
#define glumax_NMDA_columnindex 23
#define e _ml->template fpfield<24>(_iml)
#define e_columnindex 24
#define Alpha_Max _ml->template fpfield<25>(_iml)
#define Alpha_Max_columnindex 25
#define Alpha_Delay _ml->template fpfield<26>(_iml)
#define Alpha_Delay_columnindex 26
#define Alpha_tau _ml->template fpfield<27>(_iml)
#define Alpha_tau_columnindex 27
#define DC_Level _ml->template fpfield<28>(_iml)
#define DC_Level_columnindex 28
#define DC_Delay _ml->template fpfield<29>(_iml)
#define DC_Delay_columnindex 29
#define DC_Off _ml->template fpfield<30>(_iml)
#define DC_Off_columnindex 30
#define Ramp_Max _ml->template fpfield<31>(_iml)
#define Ramp_Max_columnindex 31
#define Ramp_Delay _ml->template fpfield<32>(_iml)
#define Ramp_Delay_columnindex 32
#define Ramp_Off _ml->template fpfield<33>(_iml)
#define Ramp_Off_columnindex 33
#define Slope_UP _ml->template fpfield<34>(_iml)
#define Slope_UP_columnindex 34
#define Slope_DOWN _ml->template fpfield<35>(_iml)
#define Slope_DOWN_columnindex 35
#define alpend _ml->template fpfield<36>(_iml)
#define alpend_columnindex 36
#define Max_RVP _ml->template fpfield<37>(_iml)
#define Max_RVP_columnindex 37
#define rate_constantIN _ml->template fpfield<38>(_iml)
#define rate_constantIN_columnindex 38
#define Vmax _ml->template fpfield<39>(_iml)
#define Vmax_columnindex 39
#define k _ml->template fpfield<40>(_iml)
#define k_columnindex 40
#define n _ml->template fpfield<41>(_iml)
#define n_columnindex 41
#define Rb _ml->template fpfield<42>(_iml)
#define Rb_columnindex 42
#define RBu _ml->template fpfield<43>(_iml)
#define RBu_columnindex 43
#define RBd _ml->template fpfield<44>(_iml)
#define RBd_columnindex 44
#define RBDr _ml->template fpfield<45>(_iml)
#define RBDr_columnindex 45
#define RBb _ml->template fpfield<46>(_iml)
#define RBb_columnindex 46
#define RB2u _ml->template fpfield<47>(_iml)
#define RB2u_columnindex 47
#define RB2d _ml->template fpfield<48>(_iml)
#define RB2d_columnindex 48
#define RB2Dr _ml->template fpfield<49>(_iml)
#define RB2Dr_columnindex 49
#define RB2o _ml->template fpfield<50>(_iml)
#define RB2o_columnindex 50
#define RB2c _ml->template fpfield<51>(_iml)
#define RB2c_columnindex 51
#define RDBb _ml->template fpfield<52>(_iml)
#define RDBb_columnindex 52
#define RDB2u _ml->template fpfield<53>(_iml)
#define RDB2u_columnindex 53
#define Rm _ml->template fpfield<54>(_iml)
#define Rm_columnindex 54
#define RMum _ml->template fpfield<55>(_iml)
#define RMum_columnindex 55
#define RBm _ml->template fpfield<56>(_iml)
#define RBm_columnindex 56
#define RBMum _ml->template fpfield<57>(_iml)
#define RBMum_columnindex 57
#define RB2m _ml->template fpfield<58>(_iml)
#define RB2m_columnindex 58
#define RB2Mum _ml->template fpfield<59>(_iml)
#define RB2Mum_columnindex 59
#define RMb _ml->template fpfield<60>(_iml)
#define RMb_columnindex 60
#define RMBu _ml->template fpfield<61>(_iml)
#define RMBu_columnindex 61
#define RMBb _ml->template fpfield<62>(_iml)
#define RMBb_columnindex 62
#define RMB2u _ml->template fpfield<63>(_iml)
#define RMB2u_columnindex 63
#define RMB2o _ml->template fpfield<64>(_iml)
#define RMB2o_columnindex 64
#define RMB2c _ml->template fpfield<65>(_iml)
#define RMB2c_columnindex 65
#define RMB2d _ml->template fpfield<66>(_iml)
#define RMB2d_columnindex 66
#define RMB2Dr _ml->template fpfield<67>(_iml)
#define RMB2Dr_columnindex 67
#define RMBd _ml->template fpfield<68>(_iml)
#define RMBd_columnindex 68
#define RMBDr _ml->template fpfield<69>(_iml)
#define RMBDr_columnindex 69
#define RMDBb _ml->template fpfield<70>(_iml)
#define RMDBb_columnindex 70
#define RMDB2u _ml->template fpfield<71>(_iml)
#define RMDB2u_columnindex 71
#define RDBm _ml->template fpfield<72>(_iml)
#define RDBm_columnindex 72
#define RDBMum _ml->template fpfield<73>(_iml)
#define RDBMum_columnindex 73
#define RDB2m _ml->template fpfield<74>(_iml)
#define RDB2m_columnindex 74
#define RDB2Mum _ml->template fpfield<75>(_iml)
#define RDB2Mum_columnindex 75
#define Rb2 _ml->template fpfield<76>(_iml)
#define Rb2_columnindex 76
#define Ru _ml->template fpfield<77>(_iml)
#define Ru_columnindex 77
#define Rd _ml->template fpfield<78>(_iml)
#define Rd_columnindex 78
#define Rr _ml->template fpfield<79>(_iml)
#define Rr_columnindex 79
#define Ro _ml->template fpfield<80>(_iml)
#define Ro_columnindex 80
#define Rc _ml->template fpfield<81>(_iml)
#define Rc_columnindex 81
#define gluConc_dAMPA _ml->template fpfield<82>(_iml)
#define gluConc_dAMPA_columnindex 82
#define gluConc_NMDA _ml->template fpfield<83>(_iml)
#define gluConc_NMDA_columnindex 83
#define i _ml->template fpfield<84>(_iml)
#define i_columnindex 84
#define g _ml->template fpfield<85>(_iml)
#define g_columnindex 85
#define g2 _ml->template fpfield<86>(_iml)
#define g2_columnindex 86
#define rb _ml->template fpfield<87>(_iml)
#define rb_columnindex 87
#define rb2 _ml->template fpfield<88>(_iml)
#define rb2_columnindex 88
#define rBb _ml->template fpfield<89>(_iml)
#define rBb_columnindex 89
#define rDBb _ml->template fpfield<90>(_iml)
#define rDBb_columnindex 90
#define rMb _ml->template fpfield<91>(_iml)
#define rMb_columnindex 91
#define rMBb _ml->template fpfield<92>(_iml)
#define rMBb_columnindex 92
#define rm _ml->template fpfield<93>(_iml)
#define rm_columnindex 93
#define rBm _ml->template fpfield<94>(_iml)
#define rBm_columnindex 94
#define rB2m _ml->template fpfield<95>(_iml)
#define rB2m_columnindex 95
#define rDBm _ml->template fpfield<96>(_iml)
#define rDBm_columnindex 96
#define rDB2m _ml->template fpfield<97>(_iml)
#define rDB2m_columnindex 97
#define UFP _ml->template fpfield<98>(_iml)
#define UFP_columnindex 98
#define R _ml->template fpfield<99>(_iml)
#define R_columnindex 99
#define RM _ml->template fpfield<100>(_iml)
#define RM_columnindex 100
#define RA _ml->template fpfield<101>(_iml)
#define RA_columnindex 101
#define RA2 _ml->template fpfield<102>(_iml)
#define RA2_columnindex 102
#define RdA _ml->template fpfield<103>(_iml)
#define RdA_columnindex 103
#define RdA2 _ml->template fpfield<104>(_iml)
#define RdA2_columnindex 104
#define RMA _ml->template fpfield<105>(_iml)
#define RMA_columnindex 105
#define RMA2 _ml->template fpfield<106>(_iml)
#define RMA2_columnindex 106
#define RdMA _ml->template fpfield<107>(_iml)
#define RdMA_columnindex 107
#define RdMA2 _ml->template fpfield<108>(_iml)
#define RdMA2_columnindex 108
#define O _ml->template fpfield<109>(_iml)
#define O_columnindex 109
#define OM _ml->template fpfield<110>(_iml)
#define OM_columnindex 110
#define C0 _ml->template fpfield<111>(_iml)
#define C0_columnindex 111
#define C1 _ml->template fpfield<112>(_iml)
#define C1_columnindex 112
#define C2 _ml->template fpfield<113>(_iml)
#define C2_columnindex 113
#define D _ml->template fpfield<114>(_iml)
#define D_columnindex 114
#define OO _ml->template fpfield<115>(_iml)
#define OO_columnindex 115
#define B _ml->template fpfield<116>(_iml)
#define B_columnindex 116
#define last_quanta _ml->template data_array<117, 20>(_iml)
#define last_quanta_columnindex 117
#define release_start _ml->template data_array<118, 20>(_iml)
#define release_start_columnindex 118
#define RVP_Size _ml->template data_array<119, 20>(_iml)
#define RVP_Size_columnindex 119
#define RVP_out _ml->template data_array<120, 20>(_iml)
#define RVP_out_columnindex 120
#define rate _ml->template data_array<121, 20>(_iml)
#define rate_columnindex 121
#define rateIN _ml->template data_array<122, 20>(_iml)
#define rateIN_columnindex 122
#define DR _ml->template fpfield<123>(_iml)
#define DR_columnindex 123
#define DRM _ml->template fpfield<124>(_iml)
#define DRM_columnindex 124
#define DRA _ml->template fpfield<125>(_iml)
#define DRA_columnindex 125
#define DRA2 _ml->template fpfield<126>(_iml)
#define DRA2_columnindex 126
#define DRdA _ml->template fpfield<127>(_iml)
#define DRdA_columnindex 127
#define DRdA2 _ml->template fpfield<128>(_iml)
#define DRdA2_columnindex 128
#define DRMA _ml->template fpfield<129>(_iml)
#define DRMA_columnindex 129
#define DRMA2 _ml->template fpfield<130>(_iml)
#define DRMA2_columnindex 130
#define DRdMA _ml->template fpfield<131>(_iml)
#define DRdMA_columnindex 131
#define DRdMA2 _ml->template fpfield<132>(_iml)
#define DRdMA2_columnindex 132
#define DO _ml->template fpfield<133>(_iml)
#define DO_columnindex 133
#define DOM _ml->template fpfield<134>(_iml)
#define DOM_columnindex 134
#define DC0 _ml->template fpfield<135>(_iml)
#define DC0_columnindex 135
#define DC1 _ml->template fpfield<136>(_iml)
#define DC1_columnindex 136
#define DC2 _ml->template fpfield<137>(_iml)
#define DC2_columnindex 137
#define DD _ml->template fpfield<138>(_iml)
#define DD_columnindex 138
#define DOO _ml->template fpfield<139>(_iml)
#define DOO_columnindex 139
#define DB _ml->template fpfield<140>(_iml)
#define DB_columnindex 140
#define _g _ml->template fpfield<141>(_iml)
#define _g_columnindex 141
#define _nd_area *_ml->dptr_field<0>(_iml)
#define preCA	*_ppvar[2].get<double*>()
#define _p_preCA _ppvar[2].literal_value<void*>()
 static _nrn_mechanism_cache_instance _ml_real{nullptr};
static _nrn_mechanism_cache_range *_ml{&_ml_real};
static size_t _iml{0};
static Datum *_ppvar;
 static int hoc_nrnpointerindex =  2;
 /* external NEURON variables */
 extern double mod_modulator;
 /* declaration of user functions */
 static double _hoc_RVPSIZE(void*);
 static double _hoc_alpha(void*);
 static double _hoc_rates(void*);
 static double _hoc_vesicle_release(void*);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mechtype);
#endif
 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(Object* _ho) { void* create_point_process(int, Object*);
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt(void*);
 static double _hoc_loc_pnt(void* _vptr) {double loc_point_process(int, void*);
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(void* _vptr) {double has_loc_point(void*);
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(void* _vptr) {
 double get_loc_point_process(void*); return (get_loc_point_process(_vptr));
}
 static void _hoc_setdata(void*);
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 {0, 0}
};
 static Member_func _member_func[] = {
 {"loc", _hoc_loc_pnt},
 {"has_loc", _hoc_has_loc},
 {"get_loc", _hoc_get_loc_pnt},
 {"RVPSIZE", _hoc_RVPSIZE},
 {"alpha", _hoc_alpha},
 {"rates", _hoc_rates},
 {"vesicle_release", _hoc_vesicle_release},
 {0, 0}
};
#define alpha alpha_ribbon_synapse
 extern double alpha( double );
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
#define Orate Orate_ribbon_synapse
 double Orate = 0;
#define total_count total_count_ribbon_synapse
 double total_count = 0;
#define usetable usetable_ribbon_synapse
 double usetable = 1;
#define vmax vmax_ribbon_synapse
 double vmax = 100;
#define vmin vmin_ribbon_synapse
 double vmin = -200;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {"usetable_ribbon_synapse", 0, 1},
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"vmin_ribbon_synapse", "mV"},
 {"vmax_ribbon_synapse", "mV"},
 {"Orate_ribbon_synapse", "/s"},
 {"CAthresh", "mM"},
 {"erev", "mV"},
 {"erevN", "mV"},
 {"gmax", "umho"},
 {"gmaxN", "umho"},
 {"StanddAMPA", "mM"},
 {"StandNMDA", "mM"},
 {"mg", "mM"},
 {"AbsRefract", "ms"},
 {"rate_constant", "1/s"},
 {"tau_dAMPA", "ms"},
 {"tau_NMDA", "ms"},
 {"glumax_dAMPA", "mM"},
 {"glumax_NMDA", "mM"},
 {"e", "mV"},
 {"Alpha_Max", "umho"},
 {"Alpha_Delay", "ms"},
 {"Alpha_tau", "ms"},
 {"DC_Level", "mM"},
 {"DC_Delay", "ms"},
 {"DC_Off", "ms"},
 {"Ramp_Max", "mM"},
 {"Ramp_Delay", "ms"},
 {"Ramp_Off", "ms"},
 {"Slope_UP", "ms"},
 {"Slope_DOWN", "ms"},
 {"rate_constantIN", "1/s"},
 {"Rb", "/uM"},
 {"RBu", "/ms"},
 {"RBd", "/ms"},
 {"RBDr", "/ms"},
 {"RBb", "/uM"},
 {"RB2u", "/ms"},
 {"RB2d", "/ms"},
 {"RB2Dr", "/ms"},
 {"RB2o", "/ms"},
 {"RB2c", "/ms"},
 {"RDBb", "/uM"},
 {"RDB2u", "/ms"},
 {"Rm", "/uM"},
 {"RMum", "/ms"},
 {"RBm", "/uM"},
 {"RBMum", "/ms"},
 {"RB2m", "/uM"},
 {"RB2Mum", "/ms"},
 {"RMb", "/uM"},
 {"RMBu", "/ms"},
 {"RMBb", "/uM"},
 {"RMB2u", "/ms"},
 {"RMB2o", "/ms"},
 {"RMB2c", "/ms"},
 {"RMB2d", "/ms"},
 {"RMB2Dr", "/ms"},
 {"RMBd", "/ms"},
 {"RMBDr", "/ms"},
 {"RMDBb", "/uM"},
 {"RMDB2u", "/ms"},
 {"RDBm", "/uM"},
 {"RDBMum", "/ms"},
 {"RDB2m", "/uM"},
 {"RDB2Mum", "/ms"},
 {"Rb2", "/uM"},
 {"Ru", "/ms"},
 {"Rd", "/ms"},
 {"Rr", "/ms"},
 {"Ro", "/ms"},
 {"Rc", "/ms"},
 {"gluConc_dAMPA", "mM"},
 {"gluConc_NMDA", "mM"},
 {"i", "nA"},
 {"g", "umho"},
 {"g2", "umho"},
 {"rb", "/ms"},
 {"rb2", "/ms"},
 {"rBb", "/ms"},
 {"rDBb", "/ms"},
 {"rMb", "/ms"},
 {"rMBb", "/ms"},
 {"rm", "/ms"},
 {"rBm", "/ms"},
 {"rB2m", "/ms"},
 {"rDBm", "/ms"},
 {"rDB2m", "/ms"},
 {"preCA", "mM"},
 {0, 0}
};
 static double B0 = 0;
 static double C20 = 0;
 static double C10 = 0;
 static double C00 = 0;
 static double D0 = 0;
 static double OO0 = 0;
 static double OM0 = 0;
 static double O0 = 0;
 static double RdMA20 = 0;
 static double RdMA0 = 0;
 static double RMA20 = 0;
 static double RMA0 = 0;
 static double RdA20 = 0;
 static double RdA0 = 0;
 static double RA20 = 0;
 static double RA0 = 0;
 static double RM0 = 0;
 static double R0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 {"vmin_ribbon_synapse", &vmin_ribbon_synapse},
 {"vmax_ribbon_synapse", &vmax_ribbon_synapse},
 {"total_count_ribbon_synapse", &total_count_ribbon_synapse},
 {"Orate_ribbon_synapse", &Orate_ribbon_synapse},
 {"usetable_ribbon_synapse", &usetable_ribbon_synapse},
 {0, 0}
};
 static DoubVec hoc_vdoub[] = {
 {0, 0, 0}
};
 static double _sav_indep;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
_ppvar = _nrn_mechanism_access_dparam(_prop);
 Node * _node = _nrn_mechanism_access_node(_prop);
v = _nrn_mechanism_access_voltage(_node);
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 static void nrn_alloc(Prop*);
static void nrn_init(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_state(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 static void nrn_cur(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_jacob(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 static void _hoc_destroy_pnt(void* _vptr) {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"ribbon_synapse",
 "S",
 "W",
 "powr",
 "K1",
 "CAthresh",
 "preCAnow",
 "erev",
 "erevN",
 "gmax",
 "gmaxN",
 "StanddAMPA",
 "StandNMDA",
 "xC0",
 "xC1",
 "xC2",
 "xD",
 "xOO",
 "mg",
 "AbsRefract",
 "rate_constant",
 "tau_dAMPA",
 "tau_NMDA",
 "glumax_dAMPA",
 "glumax_NMDA",
 "e",
 "Alpha_Max",
 "Alpha_Delay",
 "Alpha_tau",
 "DC_Level",
 "DC_Delay",
 "DC_Off",
 "Ramp_Max",
 "Ramp_Delay",
 "Ramp_Off",
 "Slope_UP",
 "Slope_DOWN",
 "alpend",
 "Max_RVP",
 "rate_constantIN",
 "Vmax",
 "k",
 "n",
 "Rb",
 "RBu",
 "RBd",
 "RBDr",
 "RBb",
 "RB2u",
 "RB2d",
 "RB2Dr",
 "RB2o",
 "RB2c",
 "RDBb",
 "RDB2u",
 "Rm",
 "RMum",
 "RBm",
 "RBMum",
 "RB2m",
 "RB2Mum",
 "RMb",
 "RMBu",
 "RMBb",
 "RMB2u",
 "RMB2o",
 "RMB2c",
 "RMB2d",
 "RMB2Dr",
 "RMBd",
 "RMBDr",
 "RMDBb",
 "RMDB2u",
 "RDBm",
 "RDBMum",
 "RDB2m",
 "RDB2Mum",
 "Rb2",
 "Ru",
 "Rd",
 "Rr",
 "Ro",
 "Rc",
 0,
 "gluConc_dAMPA",
 "gluConc_NMDA",
 "i",
 "g",
 "g2",
 "rb",
 "rb2",
 "rBb",
 "rDBb",
 "rMb",
 "rMBb",
 "rm",
 "rBm",
 "rB2m",
 "rDBm",
 "rDB2m",
 "UFP",
 0,
 "R",
 "RM",
 "RA",
 "RA2",
 "RdA",
 "RdA2",
 "RMA",
 "RMA2",
 "RdMA",
 "RdMA2",
 "O",
 "OM",
 "C0",
 "C1",
 "C2",
 "D",
 "OO",
 "B",
 0,
 "preCA",
 0};
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     2.84985, /* S */
     0.0498303, /* W */
     4, /* powr */
     18.3892, /* K1 */
     0.00010001, /* CAthresh */
     0, /* preCAnow */
     0, /* erev */
     0, /* erevN */
     0, /* gmax */
     0, /* gmaxN */
     0, /* StanddAMPA */
     0.001, /* StandNMDA */
     0.55004, /* xC0 */
     0.21319, /* xC1 */
     0.08263, /* xC2 */
     0.10207, /* xD */
     0.05207, /* xOO */
     0, /* mg */
     0, /* AbsRefract */
     0, /* rate_constant */
     0.055, /* tau_dAMPA */
     0.1, /* tau_NMDA */
     0, /* glumax_dAMPA */
     0, /* glumax_NMDA */
     0, /* e */
     0, /* Alpha_Max */
     0, /* Alpha_Delay */
     0.1, /* Alpha_tau */
     0, /* DC_Level */
     0, /* DC_Delay */
     0, /* DC_Off */
     0, /* Ramp_Max */
     0, /* Ramp_Delay */
     0, /* Ramp_Off */
     0, /* Slope_UP */
     0, /* Slope_DOWN */
     0, /* alpend */
     5, /* Max_RVP */
     0.125, /* rate_constantIN */
     1840.22, /* Vmax */
     86.4882, /* k */
     3.30393, /* n */
     0.02, /* Rb */
     0.3, /* RBu */
     1, /* RBd */
     0.3, /* RBDr */
     0.01, /* RBb */
     100, /* RB2u */
     8, /* RB2d */
     0.0002, /* RB2Dr */
     30, /* RB2o */
     1.5, /* RB2c */
     0.01, /* RDBb */
     0.0083, /* RDB2u */
     0, /* Rm */
     0, /* RMum */
     0, /* RBm */
     0, /* RBMum */
     0, /* RB2m */
     0, /* RB2Mum */
     0, /* RMb */
     0, /* RMBu */
     0, /* RMBb */
     0, /* RMB2u */
     0, /* RMB2o */
     0, /* RMB2c */
     0, /* RMB2d */
     0, /* RMB2Dr */
     0, /* RMBd */
     0, /* RMBDr */
     0, /* RMDBb */
     0, /* RMDB2u */
     0, /* RDBm */
     0, /* RDBMum */
     0, /* RDB2m */
     0, /* RDB2Mum */
     0.005, /* Rb2 */
     0.0129, /* Ru */
     0.0084, /* Rd */
     0.0068, /* Rr */
     0.0465, /* Ro */
     0.0738, /* Rc */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
  if (nrn_point_prop_) {
    _nrn_mechanism_access_alloc_seq(_prop) = _nrn_mechanism_access_alloc_seq(nrn_point_prop_);
    _ppvar = _nrn_mechanism_access_dparam(nrn_point_prop_);
  } else {
   _ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 142);
 	/*initialize range parameters*/
 	S = _parm_default[0]; /* 2.84985 */
 	W = _parm_default[1]; /* 0.0498303 */
 	powr = _parm_default[2]; /* 4 */
 	K1 = _parm_default[3]; /* 18.3892 */
 	CAthresh = _parm_default[4]; /* 0.00010001 */
 	preCAnow = _parm_default[5]; /* 0 */
 	erev = _parm_default[6]; /* 0 */
 	erevN = _parm_default[7]; /* 0 */
 	gmax = _parm_default[8]; /* 0 */
 	gmaxN = _parm_default[9]; /* 0 */
 	StanddAMPA = _parm_default[10]; /* 0 */
 	StandNMDA = _parm_default[11]; /* 0.001 */
 	xC0 = _parm_default[12]; /* 0.55004 */
 	xC1 = _parm_default[13]; /* 0.21319 */
 	xC2 = _parm_default[14]; /* 0.08263 */
 	xD = _parm_default[15]; /* 0.10207 */
 	xOO = _parm_default[16]; /* 0.05207 */
 	mg = _parm_default[17]; /* 0 */
 	AbsRefract = _parm_default[18]; /* 0 */
 	rate_constant = _parm_default[19]; /* 0 */
 	tau_dAMPA = _parm_default[20]; /* 0.055 */
 	tau_NMDA = _parm_default[21]; /* 0.1 */
 	glumax_dAMPA = _parm_default[22]; /* 0 */
 	glumax_NMDA = _parm_default[23]; /* 0 */
 	e = _parm_default[24]; /* 0 */
 	Alpha_Max = _parm_default[25]; /* 0 */
 	Alpha_Delay = _parm_default[26]; /* 0 */
 	Alpha_tau = _parm_default[27]; /* 0.1 */
 	DC_Level = _parm_default[28]; /* 0 */
 	DC_Delay = _parm_default[29]; /* 0 */
 	DC_Off = _parm_default[30]; /* 0 */
 	Ramp_Max = _parm_default[31]; /* 0 */
 	Ramp_Delay = _parm_default[32]; /* 0 */
 	Ramp_Off = _parm_default[33]; /* 0 */
 	Slope_UP = _parm_default[34]; /* 0 */
 	Slope_DOWN = _parm_default[35]; /* 0 */
 	alpend = _parm_default[36]; /* 0 */
 	Max_RVP = _parm_default[37]; /* 5 */
 	rate_constantIN = _parm_default[38]; /* 0.125 */
 	Vmax = _parm_default[39]; /* 1840.22 */
 	k = _parm_default[40]; /* 86.4882 */
 	n = _parm_default[41]; /* 3.30393 */
 	Rb = _parm_default[42]; /* 0.02 */
 	RBu = _parm_default[43]; /* 0.3 */
 	RBd = _parm_default[44]; /* 1 */
 	RBDr = _parm_default[45]; /* 0.3 */
 	RBb = _parm_default[46]; /* 0.01 */
 	RB2u = _parm_default[47]; /* 100 */
 	RB2d = _parm_default[48]; /* 8 */
 	RB2Dr = _parm_default[49]; /* 0.0002 */
 	RB2o = _parm_default[50]; /* 30 */
 	RB2c = _parm_default[51]; /* 1.5 */
 	RDBb = _parm_default[52]; /* 0.01 */
 	RDB2u = _parm_default[53]; /* 0.0083 */
 	Rm = _parm_default[54]; /* 0 */
 	RMum = _parm_default[55]; /* 0 */
 	RBm = _parm_default[56]; /* 0 */
 	RBMum = _parm_default[57]; /* 0 */
 	RB2m = _parm_default[58]; /* 0 */
 	RB2Mum = _parm_default[59]; /* 0 */
 	RMb = _parm_default[60]; /* 0 */
 	RMBu = _parm_default[61]; /* 0 */
 	RMBb = _parm_default[62]; /* 0 */
 	RMB2u = _parm_default[63]; /* 0 */
 	RMB2o = _parm_default[64]; /* 0 */
 	RMB2c = _parm_default[65]; /* 0 */
 	RMB2d = _parm_default[66]; /* 0 */
 	RMB2Dr = _parm_default[67]; /* 0 */
 	RMBd = _parm_default[68]; /* 0 */
 	RMBDr = _parm_default[69]; /* 0 */
 	RMDBb = _parm_default[70]; /* 0 */
 	RMDB2u = _parm_default[71]; /* 0 */
 	RDBm = _parm_default[72]; /* 0 */
 	RDBMum = _parm_default[73]; /* 0 */
 	RDB2m = _parm_default[74]; /* 0 */
 	RDB2Mum = _parm_default[75]; /* 0 */
 	Rb2 = _parm_default[76]; /* 0.005 */
 	Ru = _parm_default[77]; /* 0.0129 */
 	Rd = _parm_default[78]; /* 0.0084 */
 	Rr = _parm_default[79]; /* 0.0068 */
 	Ro = _parm_default[80]; /* 0.0465 */
 	Rc = _parm_default[81]; /* 0.0738 */
  }
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 142);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _ribbon_synapse_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"S"} /* 0 */,
                                       _nrn_mechanism_field<double>{"W"} /* 1 */,
                                       _nrn_mechanism_field<double>{"powr"} /* 2 */,
                                       _nrn_mechanism_field<double>{"K1"} /* 3 */,
                                       _nrn_mechanism_field<double>{"CAthresh"} /* 4 */,
                                       _nrn_mechanism_field<double>{"preCAnow"} /* 5 */,
                                       _nrn_mechanism_field<double>{"erev"} /* 6 */,
                                       _nrn_mechanism_field<double>{"erevN"} /* 7 */,
                                       _nrn_mechanism_field<double>{"gmax"} /* 8 */,
                                       _nrn_mechanism_field<double>{"gmaxN"} /* 9 */,
                                       _nrn_mechanism_field<double>{"StanddAMPA"} /* 10 */,
                                       _nrn_mechanism_field<double>{"StandNMDA"} /* 11 */,
                                       _nrn_mechanism_field<double>{"xC0"} /* 12 */,
                                       _nrn_mechanism_field<double>{"xC1"} /* 13 */,
                                       _nrn_mechanism_field<double>{"xC2"} /* 14 */,
                                       _nrn_mechanism_field<double>{"xD"} /* 15 */,
                                       _nrn_mechanism_field<double>{"xOO"} /* 16 */,
                                       _nrn_mechanism_field<double>{"mg"} /* 17 */,
                                       _nrn_mechanism_field<double>{"AbsRefract"} /* 18 */,
                                       _nrn_mechanism_field<double>{"rate_constant"} /* 19 */,
                                       _nrn_mechanism_field<double>{"tau_dAMPA"} /* 20 */,
                                       _nrn_mechanism_field<double>{"tau_NMDA"} /* 21 */,
                                       _nrn_mechanism_field<double>{"glumax_dAMPA"} /* 22 */,
                                       _nrn_mechanism_field<double>{"glumax_NMDA"} /* 23 */,
                                       _nrn_mechanism_field<double>{"e"} /* 24 */,
                                       _nrn_mechanism_field<double>{"Alpha_Max"} /* 25 */,
                                       _nrn_mechanism_field<double>{"Alpha_Delay"} /* 26 */,
                                       _nrn_mechanism_field<double>{"Alpha_tau"} /* 27 */,
                                       _nrn_mechanism_field<double>{"DC_Level"} /* 28 */,
                                       _nrn_mechanism_field<double>{"DC_Delay"} /* 29 */,
                                       _nrn_mechanism_field<double>{"DC_Off"} /* 30 */,
                                       _nrn_mechanism_field<double>{"Ramp_Max"} /* 31 */,
                                       _nrn_mechanism_field<double>{"Ramp_Delay"} /* 32 */,
                                       _nrn_mechanism_field<double>{"Ramp_Off"} /* 33 */,
                                       _nrn_mechanism_field<double>{"Slope_UP"} /* 34 */,
                                       _nrn_mechanism_field<double>{"Slope_DOWN"} /* 35 */,
                                       _nrn_mechanism_field<double>{"alpend"} /* 36 */,
                                       _nrn_mechanism_field<double>{"Max_RVP"} /* 37 */,
                                       _nrn_mechanism_field<double>{"rate_constantIN"} /* 38 */,
                                       _nrn_mechanism_field<double>{"Vmax"} /* 39 */,
                                       _nrn_mechanism_field<double>{"k"} /* 40 */,
                                       _nrn_mechanism_field<double>{"n"} /* 41 */,
                                       _nrn_mechanism_field<double>{"Rb"} /* 42 */,
                                       _nrn_mechanism_field<double>{"RBu"} /* 43 */,
                                       _nrn_mechanism_field<double>{"RBd"} /* 44 */,
                                       _nrn_mechanism_field<double>{"RBDr"} /* 45 */,
                                       _nrn_mechanism_field<double>{"RBb"} /* 46 */,
                                       _nrn_mechanism_field<double>{"RB2u"} /* 47 */,
                                       _nrn_mechanism_field<double>{"RB2d"} /* 48 */,
                                       _nrn_mechanism_field<double>{"RB2Dr"} /* 49 */,
                                       _nrn_mechanism_field<double>{"RB2o"} /* 50 */,
                                       _nrn_mechanism_field<double>{"RB2c"} /* 51 */,
                                       _nrn_mechanism_field<double>{"RDBb"} /* 52 */,
                                       _nrn_mechanism_field<double>{"RDB2u"} /* 53 */,
                                       _nrn_mechanism_field<double>{"Rm"} /* 54 */,
                                       _nrn_mechanism_field<double>{"RMum"} /* 55 */,
                                       _nrn_mechanism_field<double>{"RBm"} /* 56 */,
                                       _nrn_mechanism_field<double>{"RBMum"} /* 57 */,
                                       _nrn_mechanism_field<double>{"RB2m"} /* 58 */,
                                       _nrn_mechanism_field<double>{"RB2Mum"} /* 59 */,
                                       _nrn_mechanism_field<double>{"RMb"} /* 60 */,
                                       _nrn_mechanism_field<double>{"RMBu"} /* 61 */,
                                       _nrn_mechanism_field<double>{"RMBb"} /* 62 */,
                                       _nrn_mechanism_field<double>{"RMB2u"} /* 63 */,
                                       _nrn_mechanism_field<double>{"RMB2o"} /* 64 */,
                                       _nrn_mechanism_field<double>{"RMB2c"} /* 65 */,
                                       _nrn_mechanism_field<double>{"RMB2d"} /* 66 */,
                                       _nrn_mechanism_field<double>{"RMB2Dr"} /* 67 */,
                                       _nrn_mechanism_field<double>{"RMBd"} /* 68 */,
                                       _nrn_mechanism_field<double>{"RMBDr"} /* 69 */,
                                       _nrn_mechanism_field<double>{"RMDBb"} /* 70 */,
                                       _nrn_mechanism_field<double>{"RMDB2u"} /* 71 */,
                                       _nrn_mechanism_field<double>{"RDBm"} /* 72 */,
                                       _nrn_mechanism_field<double>{"RDBMum"} /* 73 */,
                                       _nrn_mechanism_field<double>{"RDB2m"} /* 74 */,
                                       _nrn_mechanism_field<double>{"RDB2Mum"} /* 75 */,
                                       _nrn_mechanism_field<double>{"Rb2"} /* 76 */,
                                       _nrn_mechanism_field<double>{"Ru"} /* 77 */,
                                       _nrn_mechanism_field<double>{"Rd"} /* 78 */,
                                       _nrn_mechanism_field<double>{"Rr"} /* 79 */,
                                       _nrn_mechanism_field<double>{"Ro"} /* 80 */,
                                       _nrn_mechanism_field<double>{"Rc"} /* 81 */,
                                       _nrn_mechanism_field<double>{"gluConc_dAMPA"} /* 82 */,
                                       _nrn_mechanism_field<double>{"gluConc_NMDA"} /* 83 */,
                                       _nrn_mechanism_field<double>{"i"} /* 84 */,
                                       _nrn_mechanism_field<double>{"g"} /* 85 */,
                                       _nrn_mechanism_field<double>{"g2"} /* 86 */,
                                       _nrn_mechanism_field<double>{"rb"} /* 87 */,
                                       _nrn_mechanism_field<double>{"rb2"} /* 88 */,
                                       _nrn_mechanism_field<double>{"rBb"} /* 89 */,
                                       _nrn_mechanism_field<double>{"rDBb"} /* 90 */,
                                       _nrn_mechanism_field<double>{"rMb"} /* 91 */,
                                       _nrn_mechanism_field<double>{"rMBb"} /* 92 */,
                                       _nrn_mechanism_field<double>{"rm"} /* 93 */,
                                       _nrn_mechanism_field<double>{"rBm"} /* 94 */,
                                       _nrn_mechanism_field<double>{"rB2m"} /* 95 */,
                                       _nrn_mechanism_field<double>{"rDBm"} /* 96 */,
                                       _nrn_mechanism_field<double>{"rDB2m"} /* 97 */,
                                       _nrn_mechanism_field<double>{"UFP"} /* 98 */,
                                       _nrn_mechanism_field<double>{"R"} /* 99 */,
                                       _nrn_mechanism_field<double>{"RM"} /* 100 */,
                                       _nrn_mechanism_field<double>{"RA"} /* 101 */,
                                       _nrn_mechanism_field<double>{"RA2"} /* 102 */,
                                       _nrn_mechanism_field<double>{"RdA"} /* 103 */,
                                       _nrn_mechanism_field<double>{"RdA2"} /* 104 */,
                                       _nrn_mechanism_field<double>{"RMA"} /* 105 */,
                                       _nrn_mechanism_field<double>{"RMA2"} /* 106 */,
                                       _nrn_mechanism_field<double>{"RdMA"} /* 107 */,
                                       _nrn_mechanism_field<double>{"RdMA2"} /* 108 */,
                                       _nrn_mechanism_field<double>{"O"} /* 109 */,
                                       _nrn_mechanism_field<double>{"OM"} /* 110 */,
                                       _nrn_mechanism_field<double>{"C0"} /* 111 */,
                                       _nrn_mechanism_field<double>{"C1"} /* 112 */,
                                       _nrn_mechanism_field<double>{"C2"} /* 113 */,
                                       _nrn_mechanism_field<double>{"D"} /* 114 */,
                                       _nrn_mechanism_field<double>{"OO"} /* 115 */,
                                       _nrn_mechanism_field<double>{"B"} /* 116 */,
                                       _nrn_mechanism_field<double>{"last_quanta", 20} /* 117 */,
                                       _nrn_mechanism_field<double>{"release_start", 20} /* 118 */,
                                       _nrn_mechanism_field<double>{"RVP_Size", 20} /* 119 */,
                                       _nrn_mechanism_field<double>{"RVP_out", 20} /* 120 */,
                                       _nrn_mechanism_field<double>{"rate", 20} /* 121 */,
                                       _nrn_mechanism_field<double>{"rateIN", 20} /* 122 */,
                                       _nrn_mechanism_field<double>{"DR"} /* 123 */,
                                       _nrn_mechanism_field<double>{"DRM"} /* 124 */,
                                       _nrn_mechanism_field<double>{"DRA"} /* 125 */,
                                       _nrn_mechanism_field<double>{"DRA2"} /* 126 */,
                                       _nrn_mechanism_field<double>{"DRdA"} /* 127 */,
                                       _nrn_mechanism_field<double>{"DRdA2"} /* 128 */,
                                       _nrn_mechanism_field<double>{"DRMA"} /* 129 */,
                                       _nrn_mechanism_field<double>{"DRMA2"} /* 130 */,
                                       _nrn_mechanism_field<double>{"DRdMA"} /* 131 */,
                                       _nrn_mechanism_field<double>{"DRdMA2"} /* 132 */,
                                       _nrn_mechanism_field<double>{"DO"} /* 133 */,
                                       _nrn_mechanism_field<double>{"DOM"} /* 134 */,
                                       _nrn_mechanism_field<double>{"DC0"} /* 135 */,
                                       _nrn_mechanism_field<double>{"DC1"} /* 136 */,
                                       _nrn_mechanism_field<double>{"DC2"} /* 137 */,
                                       _nrn_mechanism_field<double>{"DD"} /* 138 */,
                                       _nrn_mechanism_field<double>{"DOO"} /* 139 */,
                                       _nrn_mechanism_field<double>{"DB"} /* 140 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 141 */,
                                       _nrn_mechanism_field<double*>{"_nd_area", "area"} /* 0 */,
                                       _nrn_mechanism_field<Point_process*>{"_pntproc", "pntproc"} /* 1 */,
                                       _nrn_mechanism_field<double*>{"preCA", "pointer"} /* 2 */);
  hoc_register_prop_size(_mechtype, 256, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "pointer");
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ribbon_synapse /Users/lillikiessling/Documents/Stanford/Code/BC_model/Ion_channels/ribbon_synapse.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_B;
static int _reset;
static const char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int RVPSIZE();
static int _f_rates(double);
static int rates(double);
static int vesicle_release();
 
#define _MATELM1(_row,_col)	*(_getelm(_row + 1, _col + 1))
 
#define _RHS1(_arg) _coef1[_arg + 1]
 static double *_coef1;
 
#define _linmat1  1
 static void* _sparseobj1;
 static void* _cvsparseobj1;
 
static int _ode_spec1(_internalthreadargsproto_);
/*static int _ode_matsol1(_internalthreadargsproto_);*/
 static void _n_rates(double);
 static neuron::container::field_index _slist1[17], _dlist1[17]; static double *_temp1;
 static int kstates ();
 
static int  vesicle_release (  ) {
   Orate = 0.0 ;
   UFP = 0.0 ;
   {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
     if ( RVP_Size [ _li ]  == Max_RVP ) {
       UFP = UFP + 1.0 ;
       }
     } }
   {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
     preCAnow = preCA ;
     if ( RVP_Size [ _li ] < 1.0 ) {
       rate [ _li ] = S * ( W * preCAnow * 1000.0 ) / pow( ( ( ( preCAnow * 1000.0 ) / K1 ) + 1.0 ) , powr ) ;
       }
     else {
       rate_constant = ( Vmax * pow( ( 1000.0 * preCAnow ) , n ) ) / ( pow( k , n ) + pow( ( 1000.0 * preCAnow ) , n ) ) ;
       if ( RVP_Size [ _li ]  == Max_RVP ) {
         rate [ _li ] = UFP * rate_constant ;
         }
       else {
         rate [ _li ] = RVP_Size [ _li ] * rate_constant ;
         }
       }
     Orate = Orate + rate [ _li ] ;
     last_quanta [ _li ] = last_quanta [ _li ] + dt ;
     if ( ( scop_random ( ) < ( rate [ _li ] / ( 1000.0 / dt ) ) )  && ( last_quanta [ _li ] >= AbsRefract ) ) {
       release_start [ _li ] = t ;
       last_quanta [ _li ] = 0.0 ;
       RVP_out [ _li ] = 1.0 ;
       total_count = total_count + 1.0 ;
       }
     gluConc_dAMPA = gluConc_dAMPA + ( glumax_dAMPA * alpha ( _threadargscomma_ ( t - release_start [ _li ] ) / tau_dAMPA ) ) ;
     gluConc_NMDA = gluConc_NMDA + ( glumax_NMDA * alpha ( _threadargscomma_ ( t - release_start [ _li ] ) / tau_NMDA ) ) ;
     } }
    return 0; }
 
static double _hoc_vesicle_release(void* _vptr) {
 double _r;
    auto* const _pnt = static_cast<Point_process*>(_vptr);
  auto* const _p = _pnt->_prop;
  if (!_p) {
    hoc_execerror("POINT_PROCESS data instance not valid", NULL);
  }
   _setdata(_p);
 _r = 1.;
 vesicle_release (  );
 return(_r);
}
 
static int  RVPSIZE (  ) {
   {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
     RVP_Size [ _li ] = RVP_Size [ _li ] - RVP_out [ _li ] ;
     if ( RVP_Size [ _li ] < 0.0 ) {
       RVP_Size [ _li ] = 0.0 ;
       }
     if ( RVP_Size [ _li ] > Max_RVP ) {
       RVP_Size [ _li ] = Max_RVP ;
       }
     if ( RVP_Size [ _li ] < Max_RVP ) {
       rateIN [ _li ] = rate_constantIN * ( Max_RVP - RVP_Size [ _li ] ) ;
       if ( scop_random ( ) < rateIN [ _li ] / ( 1000.0 / dt ) ) {
         RVP_Size [ _li ] = RVP_Size [ _li ] + 1.0 ;
         }
       }
     RVP_out [ _li ] = 0.0 ;
     } }
    return 0; }
 
static double _hoc_RVPSIZE(void* _vptr) {
 double _r;
    auto* const _pnt = static_cast<Point_process*>(_vptr);
  auto* const _p = _pnt->_prop;
  if (!_p) {
    hoc_execerror("POINT_PROCESS data instance not valid", NULL);
  }
   _setdata(_p);
 _r = 1.;
 RVPSIZE (  );
 return(_r);
}
 
static int kstates ()
 {_reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=2;_i<17;_i++){
  	_RHS1(_i) = -_dt1*(_ml->data(_iml, _slist1[_i]) - _ml->data(_iml, _dlist1[_i]));
	_MATELM1(_i, _i) = _dt1;
      
} }
 rb = Rb * ( 1e3 ) * gluConc_dAMPA ;
   rBb = RBb * ( 1e3 ) * gluConc_dAMPA ;
   rDBb = RDBb * ( 1e3 ) * gluConc_dAMPA ;
   rMb = RMb * ( 1e3 ) * gluConc_dAMPA ;
   rMBb = RMBb * ( 1e3 ) * gluConc_dAMPA ;
   rm = Rm * ( 1e3 ) * mod_modulator ;
   rBm = RBm * ( 1e3 ) * mod_modulator ;
   rB2m = RB2m * ( 1e3 ) * mod_modulator ;
   rDBm = RDBm * ( 1e3 ) * mod_modulator ;
   rDB2m = RDB2m * ( 1e3 ) * mod_modulator ;
   /* ~ R <-> RA ( rb , RBu )*/
 f_flux =  rb * R ;
 b_flux =  RBu * RA ;
 _RHS1( 16) -= (f_flux - b_flux);
 _RHS1( 14) += (f_flux - b_flux);
 
 _term =  rb ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 14 ,16)  -= _term;
 _term =  RBu ;
 _MATELM1( 16 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ RA <-> RdA ( RBd , RBDr )*/
 f_flux =  RBd * RA ;
 b_flux =  RBDr * RdA ;
 _RHS1( 14) -= (f_flux - b_flux);
 _RHS1( 12) += (f_flux - b_flux);
 
 _term =  RBd ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 12 ,14)  -= _term;
 _term =  RBDr ;
 _MATELM1( 14 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ RA <-> RA2 ( rBb , RB2u )*/
 f_flux =  rBb * RA ;
 b_flux =  RB2u * RA2 ;
 _RHS1( 14) -= (f_flux - b_flux);
 _RHS1( 13) += (f_flux - b_flux);
 
 _term =  rBb ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 13 ,14)  -= _term;
 _term =  RB2u ;
 _MATELM1( 14 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  /* ~ RA2 <-> RdA2 ( RB2d , RB2Dr )*/
 f_flux =  RB2d * RA2 ;
 b_flux =  RB2Dr * RdA2 ;
 _RHS1( 13) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  RB2d ;
 _MATELM1( 13 ,13)  += _term;
 _MATELM1( 11 ,13)  -= _term;
 _term =  RB2Dr ;
 _MATELM1( 13 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ RA2 <-> O ( RB2o , RB2c )*/
 f_flux =  RB2o * RA2 ;
 b_flux =  RB2c * O ;
 _RHS1( 13) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  RB2o ;
 _MATELM1( 13 ,13)  += _term;
 _MATELM1( 6 ,13)  -= _term;
 _term =  RB2c ;
 _MATELM1( 13 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ RdA <-> RdA2 ( rDBb , RDB2u )*/
 f_flux =  rDBb * RdA ;
 b_flux =  RDB2u * RdA2 ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  rDBb ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  RDB2u ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ R <-> RM ( rm , RMum )*/
 f_flux =  rm * R ;
 b_flux =  RMum * RM ;
 _RHS1( 16) -= (f_flux - b_flux);
 _RHS1( 15) += (f_flux - b_flux);
 
 _term =  rm ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 15 ,16)  -= _term;
 _term =  RMum ;
 _MATELM1( 16 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  /* ~ RA <-> RMA ( rBm , RBMum )*/
 f_flux =  rBm * RA ;
 b_flux =  RBMum * RMA ;
 _RHS1( 14) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  rBm ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 10 ,14)  -= _term;
 _term =  RBMum ;
 _MATELM1( 14 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ RA2 <-> RMA2 ( rB2m , RB2Mum )*/
 f_flux =  rB2m * RA2 ;
 b_flux =  RB2Mum * RMA2 ;
 _RHS1( 13) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  rB2m ;
 _MATELM1( 13 ,13)  += _term;
 _MATELM1( 9 ,13)  -= _term;
 _term =  RB2Mum ;
 _MATELM1( 13 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ RM <-> RMA ( rMb , RMBu )*/
 f_flux =  rMb * RM ;
 b_flux =  RMBu * RMA ;
 _RHS1( 15) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  rMb ;
 _MATELM1( 15 ,15)  += _term;
 _MATELM1( 10 ,15)  -= _term;
 _term =  RMBu ;
 _MATELM1( 15 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ RMA <-> RMA2 ( rMBb , RMB2u )*/
 f_flux =  rMBb * RMA ;
 b_flux =  RMB2u * RMA2 ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  rMBb ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  RMB2u ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ RMA2 <-> OM ( RMB2o , RMB2c )*/
 f_flux =  RMB2o * RMA2 ;
 b_flux =  RMB2c * OM ;
 _RHS1( 9) -= (f_flux - b_flux);
 
 _term =  RMB2o ;
 _MATELM1( 9 ,9)  += _term;
 _term =  RMB2c ;
 _MATELM1( 9 ,1)  -= _term;
 /*REACTION*/
  /* ~ RMA2 <-> RdMA2 ( RMB2d , RMB2Dr )*/
 f_flux =  RMB2d * RMA2 ;
 b_flux =  RMB2Dr * RdMA2 ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  RMB2d ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 7 ,9)  -= _term;
 _term =  RMB2Dr ;
 _MATELM1( 9 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ RMA <-> RdMA ( RMBd , RMBDr )*/
 f_flux =  RMBd * RMA ;
 b_flux =  RMBDr * RdMA ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  RMBd ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 8 ,10)  -= _term;
 _term =  RMBDr ;
 _MATELM1( 10 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ RdMA <-> RdMA2 ( RMDBb , RMDB2u )*/
 f_flux =  RMDBb * RdMA ;
 b_flux =  RMDB2u * RdMA2 ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  RMDBb ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  RMDB2u ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ RdA <-> RdMA ( rDBm , RDBMum )*/
 f_flux =  rDBm * RdA ;
 b_flux =  RDBMum * RdMA ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  rDBm ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 8 ,12)  -= _term;
 _term =  RDBMum ;
 _MATELM1( 12 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ RdA2 <-> RdMA2 ( rDB2m , RDB2Mum )*/
 f_flux =  rDB2m * RdA2 ;
 b_flux =  RDB2Mum * RdMA2 ;
 _RHS1( 11) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  rDB2m ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 7 ,11)  -= _term;
 _term =  RDB2Mum ;
 _MATELM1( 11 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
   /* R + RM + RA + RA2 + RdA + RdA2 + RMA + RMA2 + RdMA + RdMA2 + O + OM = 1.0 */
 _RHS1(1) =  1.0;
 _MATELM1(1, 1) = 1;
 _RHS1(1) -= OM ;
 _MATELM1(1, 6) = 1;
 _RHS1(1) -= O ;
 _MATELM1(1, 7) = 1;
 _RHS1(1) -= RdMA2 ;
 _MATELM1(1, 8) = 1;
 _RHS1(1) -= RdMA ;
 _MATELM1(1, 9) = 1;
 _RHS1(1) -= RMA2 ;
 _MATELM1(1, 10) = 1;
 _RHS1(1) -= RMA ;
 _MATELM1(1, 11) = 1;
 _RHS1(1) -= RdA2 ;
 _MATELM1(1, 12) = 1;
 _RHS1(1) -= RdA ;
 _MATELM1(1, 13) = 1;
 _RHS1(1) -= RA2 ;
 _MATELM1(1, 14) = 1;
 _RHS1(1) -= RA ;
 _MATELM1(1, 15) = 1;
 _RHS1(1) -= RM ;
 _MATELM1(1, 16) = 1;
 _RHS1(1) -= R ;
 /*CONSERVATION*/
 rb2 = Rb2 * ( 1e3 ) * gluConc_NMDA ;
   /* ~ C0 <-> C1 ( rb2 , Ru )*/
 f_flux =  rb2 * C0 ;
 b_flux =  Ru * C1 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  rb2 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  Ru ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ C1 <-> C2 ( rb2 , Ru )*/
 f_flux =  rb2 * C1 ;
 b_flux =  Ru * C2 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  rb2 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  Ru ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C2 <-> D ( Rd , Rr )*/
 f_flux =  Rd * C2 ;
 b_flux =  Rr * D ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  Rd ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 5 ,2)  -= _term;
 _term =  Rr ;
 _MATELM1( 2 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C2 <-> OO ( Ro , Rc )*/
 f_flux =  Ro * C2 ;
 b_flux =  Rc * OO ;
 _RHS1( 2) -= (f_flux - b_flux);
 
 _term =  Ro ;
 _MATELM1( 2 ,2)  += _term;
 _term =  Rc ;
 _MATELM1( 2 ,0)  -= _term;
 /*REACTION*/
   /* C0 + C1 + C2 + D + OO = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= OO ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= D ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= C2 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= C1 ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= C0 ;
 /*CONSERVATION*/
   } return _reset;
 }
 static double _mfac_rates, _tmin_rates;
 static void _check_rates();
 static void _check_rates() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_mg;
  if (!usetable) {return;}
  if (_sav_mg != mg) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_rates =  vmin ;
   _tmax =  vmax ;
   _dx = (_tmax - _tmin_rates)/200.; _mfac_rates = 1./_dx;
   for (_i=0, _x=_tmin_rates; _i < 201; _x += _dx, _i++) {
    _f_rates(_x);
    _t_B[_i] = B;
   }
   _sav_mg = mg;
  }
 }

 static int rates(double _lv){ _check_rates();
 _n_rates(_lv);
 return 0;
 }

 static void _n_rates(double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_rates(_lv); return; 
}
 _xi = _mfac_rates * (_lv - _tmin_rates);
 if (std::isnan(_xi)) {
  B = _xi;
  return;
 }
 if (_xi <= 0.) {
 B = _t_B[0];
 return; }
 if (_xi >= 200.) {
 B = _t_B[200];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 B = _t_B[_i] + _theta*(_t_B[_i+1] - _t_B[_i]);
 }

 
static int  _f_rates (  double _lv ) {
   B = 1.0 / ( 1.0 + exp ( 0.062 * - _lv ) * ( mg / 3.57 ) ) ;
    return 0; }
 
static double _hoc_rates(void* _vptr) {
 double _r;
    auto* const _pnt = static_cast<Point_process*>(_vptr);
  auto* const _p = _pnt->_prop;
  if (!_p) {
    hoc_execerror("POINT_PROCESS data instance not valid", NULL);
  }
   _setdata(_p);
  _r = 1.;
 rates (  *getarg(1) );
 return(_r);
}
 
double alpha (  double _lx ) {
   double _lalpha;
 if ( _lx < 0.0  || _lx > 10.0 ) {
     _lalpha = 0.0 ;
     }
   else {
     _lalpha = _lx * exp ( 1.0 - _lx ) ;
     }
   
return _lalpha;
 }
 
static double _hoc_alpha(void* _vptr) {
 double _r;
    auto* const _pnt = static_cast<Point_process*>(_vptr);
  auto* const _p = _pnt->_prop;
  if (!_p) {
    hoc_execerror("POINT_PROCESS data instance not valid", NULL);
  }
   _setdata(_p);
 _r =  alpha (  *getarg(1) );
 return(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<17;_i++) _ml->data(_iml, _dlist1[_i]) = 0.0;}
 rb = Rb * ( 1e3 ) * gluConc_dAMPA ;
 rBb = RBb * ( 1e3 ) * gluConc_dAMPA ;
 rDBb = RDBb * ( 1e3 ) * gluConc_dAMPA ;
 rMb = RMb * ( 1e3 ) * gluConc_dAMPA ;
 rMBb = RMBb * ( 1e3 ) * gluConc_dAMPA ;
 rm = Rm * ( 1e3 ) * mod_modulator ;
 rBm = RBm * ( 1e3 ) * mod_modulator ;
 rB2m = RB2m * ( 1e3 ) * mod_modulator ;
 rDBm = RDBm * ( 1e3 ) * mod_modulator ;
 rDB2m = RDB2m * ( 1e3 ) * mod_modulator ;
 /* ~ R <-> RA ( rb , RBu )*/
 f_flux =  rb * R ;
 b_flux =  RBu * RA ;
 DR -= (f_flux - b_flux);
 DRA += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RA <-> RdA ( RBd , RBDr )*/
 f_flux =  RBd * RA ;
 b_flux =  RBDr * RdA ;
 DRA -= (f_flux - b_flux);
 DRdA += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RA <-> RA2 ( rBb , RB2u )*/
 f_flux =  rBb * RA ;
 b_flux =  RB2u * RA2 ;
 DRA -= (f_flux - b_flux);
 DRA2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RA2 <-> RdA2 ( RB2d , RB2Dr )*/
 f_flux =  RB2d * RA2 ;
 b_flux =  RB2Dr * RdA2 ;
 DRA2 -= (f_flux - b_flux);
 DRdA2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RA2 <-> O ( RB2o , RB2c )*/
 f_flux =  RB2o * RA2 ;
 b_flux =  RB2c * O ;
 DRA2 -= (f_flux - b_flux);
 DO += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RdA <-> RdA2 ( rDBb , RDB2u )*/
 f_flux =  rDBb * RdA ;
 b_flux =  RDB2u * RdA2 ;
 DRdA -= (f_flux - b_flux);
 DRdA2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ R <-> RM ( rm , RMum )*/
 f_flux =  rm * R ;
 b_flux =  RMum * RM ;
 DR -= (f_flux - b_flux);
 DRM += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RA <-> RMA ( rBm , RBMum )*/
 f_flux =  rBm * RA ;
 b_flux =  RBMum * RMA ;
 DRA -= (f_flux - b_flux);
 DRMA += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RA2 <-> RMA2 ( rB2m , RB2Mum )*/
 f_flux =  rB2m * RA2 ;
 b_flux =  RB2Mum * RMA2 ;
 DRA2 -= (f_flux - b_flux);
 DRMA2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RM <-> RMA ( rMb , RMBu )*/
 f_flux =  rMb * RM ;
 b_flux =  RMBu * RMA ;
 DRM -= (f_flux - b_flux);
 DRMA += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RMA <-> RMA2 ( rMBb , RMB2u )*/
 f_flux =  rMBb * RMA ;
 b_flux =  RMB2u * RMA2 ;
 DRMA -= (f_flux - b_flux);
 DRMA2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RMA2 <-> OM ( RMB2o , RMB2c )*/
 f_flux =  RMB2o * RMA2 ;
 b_flux =  RMB2c * OM ;
 DRMA2 -= (f_flux - b_flux);
 DOM += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RMA2 <-> RdMA2 ( RMB2d , RMB2Dr )*/
 f_flux =  RMB2d * RMA2 ;
 b_flux =  RMB2Dr * RdMA2 ;
 DRMA2 -= (f_flux - b_flux);
 DRdMA2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RMA <-> RdMA ( RMBd , RMBDr )*/
 f_flux =  RMBd * RMA ;
 b_flux =  RMBDr * RdMA ;
 DRMA -= (f_flux - b_flux);
 DRdMA += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RdMA <-> RdMA2 ( RMDBb , RMDB2u )*/
 f_flux =  RMDBb * RdMA ;
 b_flux =  RMDB2u * RdMA2 ;
 DRdMA -= (f_flux - b_flux);
 DRdMA2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RdA <-> RdMA ( rDBm , RDBMum )*/
 f_flux =  rDBm * RdA ;
 b_flux =  RDBMum * RdMA ;
 DRdA -= (f_flux - b_flux);
 DRdMA += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RdA2 <-> RdMA2 ( rDB2m , RDB2Mum )*/
 f_flux =  rDB2m * RdA2 ;
 b_flux =  RDB2Mum * RdMA2 ;
 DRdA2 -= (f_flux - b_flux);
 DRdMA2 += (f_flux - b_flux);
 
 /*REACTION*/
   /* R + RM + RA + RA2 + RdA + RdA2 + RMA + RMA2 + RdMA + RdMA2 + O + OM = 1.0 */
 /*CONSERVATION*/
 rb2 = Rb2 * ( 1e3 ) * gluConc_NMDA ;
 /* ~ C0 <-> C1 ( rb2 , Ru )*/
 f_flux =  rb2 * C0 ;
 b_flux =  Ru * C1 ;
 DC0 -= (f_flux - b_flux);
 DC1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C1 <-> C2 ( rb2 , Ru )*/
 f_flux =  rb2 * C1 ;
 b_flux =  Ru * C2 ;
 DC1 -= (f_flux - b_flux);
 DC2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> D ( Rd , Rr )*/
 f_flux =  Rd * C2 ;
 b_flux =  Rr * D ;
 DC2 -= (f_flux - b_flux);
 DD += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> OO ( Ro , Rc )*/
 f_flux =  Ro * C2 ;
 b_flux =  Rc * OO ;
 DC2 -= (f_flux - b_flux);
 DOO += (f_flux - b_flux);
 
 /*REACTION*/
   /* C0 + C1 + C2 + D + OO = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<17;_i++){
  	_RHS1(_i) = _dt1*(_ml->data(_iml, _dlist1[_i]));
	_MATELM1(_i, _i) = _dt1;
      
} }
 rb = Rb * ( 1e3 ) * gluConc_dAMPA ;
 rBb = RBb * ( 1e3 ) * gluConc_dAMPA ;
 rDBb = RDBb * ( 1e3 ) * gluConc_dAMPA ;
 rMb = RMb * ( 1e3 ) * gluConc_dAMPA ;
 rMBb = RMBb * ( 1e3 ) * gluConc_dAMPA ;
 rm = Rm * ( 1e3 ) * mod_modulator ;
 rBm = RBm * ( 1e3 ) * mod_modulator ;
 rB2m = RB2m * ( 1e3 ) * mod_modulator ;
 rDBm = RDBm * ( 1e3 ) * mod_modulator ;
 rDB2m = RDB2m * ( 1e3 ) * mod_modulator ;
 /* ~ R <-> RA ( rb , RBu )*/
 _term =  rb ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 14 ,16)  -= _term;
 _term =  RBu ;
 _MATELM1( 16 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ RA <-> RdA ( RBd , RBDr )*/
 _term =  RBd ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 12 ,14)  -= _term;
 _term =  RBDr ;
 _MATELM1( 14 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ RA <-> RA2 ( rBb , RB2u )*/
 _term =  rBb ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 13 ,14)  -= _term;
 _term =  RB2u ;
 _MATELM1( 14 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  /* ~ RA2 <-> RdA2 ( RB2d , RB2Dr )*/
 _term =  RB2d ;
 _MATELM1( 13 ,13)  += _term;
 _MATELM1( 11 ,13)  -= _term;
 _term =  RB2Dr ;
 _MATELM1( 13 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ RA2 <-> O ( RB2o , RB2c )*/
 _term =  RB2o ;
 _MATELM1( 13 ,13)  += _term;
 _MATELM1( 6 ,13)  -= _term;
 _term =  RB2c ;
 _MATELM1( 13 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ RdA <-> RdA2 ( rDBb , RDB2u )*/
 _term =  rDBb ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  RDB2u ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ R <-> RM ( rm , RMum )*/
 _term =  rm ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 15 ,16)  -= _term;
 _term =  RMum ;
 _MATELM1( 16 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  /* ~ RA <-> RMA ( rBm , RBMum )*/
 _term =  rBm ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 10 ,14)  -= _term;
 _term =  RBMum ;
 _MATELM1( 14 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ RA2 <-> RMA2 ( rB2m , RB2Mum )*/
 _term =  rB2m ;
 _MATELM1( 13 ,13)  += _term;
 _MATELM1( 9 ,13)  -= _term;
 _term =  RB2Mum ;
 _MATELM1( 13 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ RM <-> RMA ( rMb , RMBu )*/
 _term =  rMb ;
 _MATELM1( 15 ,15)  += _term;
 _MATELM1( 10 ,15)  -= _term;
 _term =  RMBu ;
 _MATELM1( 15 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ RMA <-> RMA2 ( rMBb , RMB2u )*/
 _term =  rMBb ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  RMB2u ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ RMA2 <-> OM ( RMB2o , RMB2c )*/
 _term =  RMB2o ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 1 ,9)  -= _term;
 _term =  RMB2c ;
 _MATELM1( 9 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ RMA2 <-> RdMA2 ( RMB2d , RMB2Dr )*/
 _term =  RMB2d ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 7 ,9)  -= _term;
 _term =  RMB2Dr ;
 _MATELM1( 9 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ RMA <-> RdMA ( RMBd , RMBDr )*/
 _term =  RMBd ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 8 ,10)  -= _term;
 _term =  RMBDr ;
 _MATELM1( 10 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ RdMA <-> RdMA2 ( RMDBb , RMDB2u )*/
 _term =  RMDBb ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  RMDB2u ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ RdA <-> RdMA ( rDBm , RDBMum )*/
 _term =  rDBm ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 8 ,12)  -= _term;
 _term =  RDBMum ;
 _MATELM1( 12 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ RdA2 <-> RdMA2 ( rDB2m , RDB2Mum )*/
 _term =  rDB2m ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 7 ,11)  -= _term;
 _term =  RDB2Mum ;
 _MATELM1( 11 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
   /* R + RM + RA + RA2 + RdA + RdA2 + RMA + RMA2 + RdMA + RdMA2 + O + OM = 1.0 */
 /*CONSERVATION*/
 rb2 = Rb2 * ( 1e3 ) * gluConc_NMDA ;
 /* ~ C0 <-> C1 ( rb2 , Ru )*/
 _term =  rb2 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  Ru ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ C1 <-> C2 ( rb2 , Ru )*/
 _term =  rb2 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  Ru ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C2 <-> D ( Rd , Rr )*/
 _term =  Rd ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 5 ,2)  -= _term;
 _term =  Rr ;
 _MATELM1( 2 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C2 <-> OO ( Ro , Rc )*/
 _term =  Ro ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 0 ,2)  -= _term;
 _term =  Rc ;
 _MATELM1( 2 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
   /* C0 + C1 + C2 + D + OO = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ hoc_execerror("ribbon_synapse", "cannot be used with CVODE"); return 0;}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  B = B0;
  C2 = C20;
  C1 = C10;
  C0 = C00;
  D = D0;
  OO = OO0;
  OM = OM0;
  O = O0;
  RdMA2 = RdMA20;
  RdMA = RdMA0;
  RMA2 = RMA20;
  RMA = RMA0;
  RdA2 = RdA20;
  RdA = RdA0;
  RA2 = RA20;
  RA = RA0;
  RM = RM0;
  R = R0;
 {
   R = 1.0 ;
   {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
     last_quanta [ _li ] = 40.0 ;
     release_start [ _li ] = 10000.0 ;
     RVP_Size [ _li ] = Max_RVP ;
     } }
   rates ( _threadargscomma_ v ) ;
   C0 = xC0 ;
   C1 = xC1 ;
   C2 = xC2 ;
   D = xD ;
   OO = xOO ;
   total_count = 0.0 ;
   UFP = 0.0 ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
Node *_nd; double _v; int* _ni; int _cntml;
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
_ml = &_lmr;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
 v = _v;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   rates ( _threadargscomma_ v ) ;
   gluConc_dAMPA = StanddAMPA ;
   gluConc_NMDA = StandNMDA ;
   g = gmax * ( O + OM ) ;
   g2 = gmaxN * OO * B ;
   i = ( g * ( v - erev ) ) + ( g2 * ( v - erevN ) ) ;
   }
 _current += i;

} return _current;
}

static void nrn_cur(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_rhs = _nt->node_rhs_storage();
auto const _vec_sav_rhs = _nt->node_sav_rhs_storage();
auto const _vec_v = _nt->node_voltage_storage();
Node *_nd; int* _ni; double _rhs, _v; int _cntml;
_ml = &_lmr;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
 auto const _g_local = _nrn_current(_v + .001);
 	{ _rhs = _nrn_current(_v);
 	}
 _g = (_g_local - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
	 _vec_rhs[_ni[_iml]] -= _rhs;
 
}}

static void nrn_jacob(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_d = _nt->node_d_storage();
auto const _vec_sav_d = _nt->node_sav_d_storage();
auto* const _ml = &_lmr;
Node *_nd; int* _ni; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
  _vec_d[_ni[_iml]] += _g;
 
}}

static void nrn_state(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
_ml = &_lmr;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
 _nd = _ml_arg->_nodelist[_iml];
   _v = _vec_v[_ni[_iml]];
 v=_v;
{
 { error =  vesicle_release();
 if(error){
  std_cerr_stream << "at line 261 in file ribbon_synapse.mod:\n\n";
  std_cerr_stream << _ml << ' ' << _iml << '\n';
  abort_run(error);
}
 } { error =  RVPSIZE();
 if(error){
  std_cerr_stream << "at line 263 in file ribbon_synapse.mod:\n\n";
  std_cerr_stream << _ml << ' ' << _iml << '\n';
  abort_run(error);
}
 } { error = sparse(&_sparseobj1, 17, _slist1, _dlist1, neuron::scopmath::row_view{_ml, _iml}, &t, dt, kstates, &_coef1, _linmat1);
 if(error){
  std_cerr_stream << "at line 265 in file ribbon_synapse.mod:\n\n";
  std_cerr_stream << _ml << ' ' << _iml << '\n';
  abort_run(error);
}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 17; ++_i) {
      _ml->data(_iml, _slist1[_i]) += dt*_ml->data(_iml, _dlist1[_i]);
    }}
 }}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
   _t_B = makevector(201*sizeof(double));
 _slist1[0] = {OO_columnindex, 0};  _dlist1[0] = {DOO_columnindex, 0};
 _slist1[1] = {OM_columnindex, 0};  _dlist1[1] = {DOM_columnindex, 0};
 _slist1[2] = {C2_columnindex, 0};  _dlist1[2] = {DC2_columnindex, 0};
 _slist1[3] = {C1_columnindex, 0};  _dlist1[3] = {DC1_columnindex, 0};
 _slist1[4] = {C0_columnindex, 0};  _dlist1[4] = {DC0_columnindex, 0};
 _slist1[5] = {D_columnindex, 0};  _dlist1[5] = {DD_columnindex, 0};
 _slist1[6] = {O_columnindex, 0};  _dlist1[6] = {DO_columnindex, 0};
 _slist1[7] = {RdMA2_columnindex, 0};  _dlist1[7] = {DRdMA2_columnindex, 0};
 _slist1[8] = {RdMA_columnindex, 0};  _dlist1[8] = {DRdMA_columnindex, 0};
 _slist1[9] = {RMA2_columnindex, 0};  _dlist1[9] = {DRMA2_columnindex, 0};
 _slist1[10] = {RMA_columnindex, 0};  _dlist1[10] = {DRMA_columnindex, 0};
 _slist1[11] = {RdA2_columnindex, 0};  _dlist1[11] = {DRdA2_columnindex, 0};
 _slist1[12] = {RdA_columnindex, 0};  _dlist1[12] = {DRdA_columnindex, 0};
 _slist1[13] = {RA2_columnindex, 0};  _dlist1[13] = {DRA2_columnindex, 0};
 _slist1[14] = {RA_columnindex, 0};  _dlist1[14] = {DRA_columnindex, 0};
 _slist1[15] = {RM_columnindex, 0};  _dlist1[15] = {DRM_columnindex, 0};
 _slist1[16] = {R_columnindex, 0};  _dlist1[16] = {DR_columnindex, 0};
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/Users/lillikiessling/Documents/Stanford/Code/BC_model/Ion_channels/ribbon_synapse.mod";
    const char* nmodl_file_text = 
  "COMMENT\n"
  "Ribbon Synapse with function calls within BREAKPOINT.\n"
  "Alpha function evaluation for glutamate profile\n"
  "ENDCOMMENT\n"
  "\n"
  "DEFINE NumSites 20 : The number of Release Sites per Synapse\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "     POINT_PROCESS ribbon_synapse\n"
  "     EXTERNAL mod_modulator\n"
  "     POINTER preCA\n"
  "     RANGE preCAnow\n"
  "     RANGE CAthresh\n"
  "     RANGE S, W, K1, powr\n"
  "     RANGE  Alpha_Max, Alpha_Delay, Alpha_tau, DC_Level, DC_Delay, DC_Off, Ramp_Max\n"
  "     RANGE  Ramp_Delay, Ramp_Off, Slope_UP, Slope_DOWN\n"
  "     RANGE R, RM, RA, RA2, RdA, RdA2, RMA, RMA2, RdMA, RdMA2, O, OM\n"
  "     RANGE g, gmax, erev, rb, rBb, rDb, rDBb, rMb, rMBb, rm, rBm, rB2m, rDBm, rDB2m\n"
  "     RANGE Rb, RBu, RBd, RBDr, RBb, RB2u\n"
  "     RANGE RB2d, RB2Dr, RB2o, RB2c, RDBb, RDB2u\n"
  "     RANGE Rm, RMum, RBm, RBMum, RB2m, RB2Mum\n"
  "     RANGE RMb, RMBu, RMBb, RMB2u, RMB2o, RMB2c\n"
  "     RANGE RMB2d, RMB2Dr, RMBd, RMBDr, RMDBb, RMDB2u\n"
  "     RANGE RDBMum, RDBm, RDB2Mum, RDB2m\n"
  "     RANGE tau_dAMPA, glumax_dAMPA, e, AbsRefract,  gluConc_dAMPA, pr, StanddAMPA, rate_constant\n"
  ":  for the NMDA receptor\n"
  "     RANGE g2, gmaxN, erevN, rb2, mg\n"
  "     RANGE C0, C1, C2, D, OO, B\n"
  "     RANGE Rb2, Ru, Rd, Rr, Ro, Rc, alpend\n"
  "     RANGE tau_NMDA, gluConc_NMDA, glumax_NMDA, StandNMDA\n"
  "     RANGE Max_RVP,  rate_constantIN\n"
  "     RANGE Vmax, k, n\n"
  "     RANGE UFP\n"
  "     GLOBAL total_count, Orate\n"
  "\n"
  ": for setting state variable at HOC level\n"
  ":NMDA\n"
  "     RANGE xC0, xC1, xC2, xD, xOO\n"
  ":\n"
  "     GLOBAL vmin, vmax\n"
  "     NONSPECIFIC_CURRENT i\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "     (nA) = (nanoamp)\n"
  "     (mV) = (millivolt)\n"
  "     (pS) = (picosiemens)\n"
  "     (umho) = (micromho)\n"
  "     (mM) = (milli/liter)\n"
  "     (uM) = (micro/liter)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "     S = 2.84985 : Proportionality Constant rate equation\n"
  "     W = 0.0498303 : Constant factor in rate equation\n"
  "     powr = 4 : Power of rate equation\n"
  "     K1 = 18.3892 : CaX dissociation constant\n"
  "     CAthresh = .00010001 (mM) : [Ca++] threshold\n"
  "     preCA (mM) : presynaptic [Ca++] for a full RVP\n"
  "     preCAnow\n"
  "     erev = 0 (mV)	: reversal potential of dAMPA\n"
  "     erevN = 0 (mV)     : reversal potential of NMDA\n"
  "     gmax = 0 (umho)	: maximal conductance dAMPA\n"
  "     gmaxN = 0 (umho)   : max conductance NMDA\n"
  "     StanddAMPA = 0 (mM) : standing level of glutamate seen by dAMPA\n"
  "     StandNMDA = 0.001 (mM)  : standing level of glutamate seen by NMDA\n"
  "	xC0 = 0.55004\n"
  "	xC1 = 0.21319\n"
  "	xC2 = 0.08263\n"
  "	xD =  0.10207\n"
  "	xOO = 0.05207\n"
  "     mg = 0 (mM)\n"
  "        AbsRefract = 0 (ms)\n"
  "        rate_constant (1/s)\n"
  "        tau_dAMPA=0.055 (ms) \n"
  "        tau_NMDA=0.1 (ms)\n"
  "        glumax_dAMPA=0   (mM) \n"
  "        glumax_NMDA=0    (mM)\n"
  "        e=0     (mV)\n"
  "        Alpha_Max=0     (umho)\n"
  "        Alpha_Delay=0 (ms)\n"
  "        Alpha_tau=.1 (ms)\n"
  "        DC_Level (mM)\n"
  "        DC_Delay (ms)\n"
  "        DC_Off (ms)\n"
  "        Ramp_Max (mM)\n"
  "        Ramp_Delay (ms)\n"
  "        Ramp_Off (ms)\n"
  "        Slope_UP (ms)\n"
  "        Slope_DOWN (ms)\n"
  "        alpend=0\n"
  "        Max_RVP = 5 : Maximum number of vesicles in RVP for one release site\n"
  "        rate_constantIN = 0.125 (1/s) : Rate constant of RVP uptake\n"
  "	  Vmax = 1840.22 : for Hill equation\n"
  "        k = 86.48823 :        \"\n"
  "        n = 3.30393  :        \"\n"
  "\n"
  ": Rates\n"
  "\n"
  "     : Partin, Fleck & Mayer (1996) J Nsci 16, 6634-47\n"
  "     Rb  = 2e-2     (/uM /ms) :binding single ligand\n"
  "     RBu  = 3e-1    (/ms)     :unbinding from single bound\n"
  "     RBd  = 1e0     (/ms)     :desensitization from single bound\n"
  "     RBDr  = 3e-1   (/ms)     :resensitization from single bound\n"
  "     RBb  =1e-2     (/uM /ms) :binding second ligand\n"
  "     RB2u  = 1e2    (/ms)     :unbinding from double to single ligand\n"
  "     RB2d = 8e0     (/ms)     :desensitization from double bound\n"
  "     RB2Dr = 2e-4   (/ms)     :resensitization from double bound\n"
  "     RB2o = 3e1     (/ms)     :opening from double bound ligand\n"
  "     RB2c = 1.5e0   (/ms)     :closing to double bound ligand\n"
  "     RDBb = 1e-2    (/uM /ms) :desensitized/single bound ligand binding 2nd ligand\n"
  "     RDB2u = 8.3e-3      (/ms)     :desensitized/double bound ligand unbinding 2nd ligand\n"
  "\n"
  ": dAMPA modulator kinetics OFF\n"
  "     Rm  = 0 (/uM /ms)       :binding modulator\n"
  "     RMum  = 0        (/ms)   :unbinding modulator\n"
  "     RBm = 0         (/uM /ms)       :single bound ligand binding modulator\n"
  "     RBMum =0         (/ms)   :single bound ligand unbinding modulator\n"
  "     RB2m = 0        (/uM /ms)       :double bound ligand binding modulator\n"
  "     RB2Mum = 0       (/ms)   :double bound ligand unbinding modulator\n"
  "     RMb = 0  (/uM /ms)      :modulator bound binding single ligand\n"
  "     RMBu = 0        (/ms)   :modulator bound unbinding single ligand\n"
  "     RMBb = 0        (/uM /ms)       :modulator bound binding double ligand\n"
  "     RMB2u = 0        (/ms)   :modulator bound unbinding double ligand\n"
  "     RMB2o = 0        (/ms)   :opening from modulator plus double bound ligand\n"
  "     RMB2c = 0     (/ms)   :closing from modulator plus double bound ligand\n"
  "     RMB2d = 0        (/ms)   :desensitization from double ligand bound with modulator\n"
  "     RMB2Dr = 0      (/ms)   :resensitization from double ligand bound with modulator\n"
  "     RMBd = 0 (/ms)   :desensitization from single ligand bound with modulator\n"
  "     RMBDr = 0       (/ms)   :resensitization to single ligand bound with modulator\n"
  "     RMDBb = 0       (/uM /ms)       :desensitized/single bound ligand&modulator binding 2nd ligand\n"
  "     RMDB2u = 0 (/ms)      :desensitized/double bound ligand&modulator unbinding ligand\n"
  "     RDBm = 0        (/uM /ms)       :desensitized/single bound ligand binding modulator\n"
  "     RDBMum = 0      (/ms)   :desensitized/single bound ligand unbinding modulator\n"
  "     RDB2m = 0       (/uM /ms)       :desensitized/double bound ligand binding modulator\n"
  "     RDB2Mum = 0 (/ms)       :desensitized/double bound ligand unbinding modulator\n"
  "\n"
  "        : Destexhe, Mainen & Sejnowski, 1996\n"
  "        Rb2     = 5e-3    (/uM /ms)     : binding\n"
  "        Ru      = 12.9e-3  (/ms)        : unbinding\n"
  "        Rd      = 8.4e-3   (/ms)        : desensitization\n"
  "        Rr      = 6.8e-3   (/ms)        : resensitization\n"
  "        Ro      = 46.5e-3   (/ms)       : opening\n"
  "        Rc      = 73.8e-3   (/ms)       : closing\n"
  "\n"
  "        vmin = -200     (mV)\n"
  "        vmax = 100      (mV)\n"
  "\n"
  "}\n"
  "\n"
  "COMMENT\n"
  ":    Partin values for modulator\n"
  "     Rm  = 1e-2 (/uM /ms)       :binding modulator\n"
  "     RMum  = 5e0        (/ms)   :unbinding modulator\n"
  "     RBm = 1e-2         (/uM /ms)       :single bound ligand binding modulator\n"
  "     RBMum =5e0         (/ms)   :single bound ligand unbinding modulator\n"
  "     RB2m = 1e-2        (/uM /ms)       :double bound ligand binding modulator\n"
  "     RB2Mum = 5e0       (/ms)   :double bound ligand unbinding modulator\n"
  "     RMb = 2e-2  (/uM /ms)      :modulator bound binding single ligand\n"
  "     RMBu = 3e-1        (/ms)   :modulator bound unbinding single ligand\n"
  "     RMBb = 1e-2        (/uM /ms)       :modulator bound binding double ligand\n"
  "     RMB2u = 1e2        (/ms)   :modulator bound unbinding double ligand\n"
  "     RMB2o = 3e1        (/ms)   :opening from modulator plus double bound ligand\n"
  "     RMB2c = 2.5e-1     (/ms)   :closing from modulator plus double bound ligand\n"
  "     RMB2d = 8e0        (/ms)   :desensitization from double ligand bound with modulator\n"
  "     RMB2Dr = 2e-4      (/ms)   :resensitization from double ligand bound with modulator\n"
  "     RMBd = 1e0 (/ms)   :desensitization from single ligand bound with modulator\n"
  "     RMBDr = 3e-1       (/ms)   :resensitization to single ligand bound with modulator\n"
  "     RMDBb = 1e-2       (/uM /ms)       :desensitized/single bound ligand&modulator binding 2nd ligand\n"
  "     RMDB2u = 8.3e-3 (/ms)      :desensitized/double bound ligand&modulator unbinding ligand\n"
  "     RDBm = 1e-4        (/uM /ms)       :desensitized/single bound ligand binding modulator\n"
  "     RDBMum = 5e-2      (/ms)   :desensitized/single bound ligand unbinding modulator\n"
  "     RDB2m = 1e-4       (/uM /ms)       :desensitized/double bound ligand binding modulator\n"
  "     RDB2Mum = 5e-2 (/ms)       :desensitized/double bound ligand unbinding modulator\n"
  "ENDCOMMENT\n"
  "\n"
  "\n"
  "ASSIGNED {\n"
  "     gluConc_dAMPA    (mM)\n"
  "     gluConc_NMDA     (mM)\n"
  "     v		(mV)	: postsynaptic voltage\n"
  "     i		(nA)	: current = g*(v - Erev)\n"
  "     g		(umho)	: conductance dAMPA\n"
  "     g2         (umho)  : conductance NMDA\n"
  "     mod_modulator (mM):pointer to concentration of ext. modulator compound (ie cyclothiazide)\n"
  "     rb		(/ms)	:binding single ligand\n"
  "     rb2        (/ms)\n"
  "     rBb		(/ms)	:binding second ligand\n"
  "     rDBb	(/ms)	:binding second ligand from desensitized state\n"
  "     rMb		(/ms)	:binding ligand from modulator bound state\n"
  "     rMBb	(/ms)	:binding second ligand from modulator single ligand bound state\n"
  "     rm		(/ms)	:binding modulator no ligand bound\n"
  "     rBm		(/ms)	:binding modulator from single ligand bound state\n"
  "     rB2m	(/ms)	:binding modulator from double ligand bound state\n"
  "     rDBm	(/ms)	:binding modulator from single ligand bound desensitized state\n"
  "     rDB2m	(/ms)	:binding modulator from double ligand bound desensitized state\n"
  "     dt         (ms)\n"
  "     last_quanta[NumSites] (ms)   :time since last quantal release\n"
  "     release_start[NumSites] (ms) :time of last quantal release\n"
  "     RVP_Size[NumSites] : Current size of RVP\n"
  "     RVP_out[NumSites] : Number of vesicles released at the current time step\n"
  "     total_count : count of all vesicular releases\n"
  "     Orate      (/s)  : overall calculated rate for entire ribbon\n"
  "     rate[NumSites] :\n"
  "     rateIN[NumSites] :\n"
  "     UFP : Current size of ultra-fast pool\n"
  "}\n"
  "\n"
  "STATE {\n"
  "     : Channel states (all fractions) dAMPA\n"
  "     R		: unbound\n"
  "     RM		: modulator bound no ligand\n"
  "     RA		: single ligand bound\n"
  "     RA2		: double ligand bound\n"
  "     RdA		: desensitized single bound\n"
  "     RdA2		: desensitized double bound\n"
  "     RMA		: modulator bound single ligand bound\n"
  "     RMA2		: modulator bound double ligand bound\n"
  "     RdMA		: modulator bound single ligand desensitized\n"
  "     RdMA2		: modulator bound double ligand desensitized\n"
  "     O		: open, ligand bound\n"
  "     OM		: open, modulator  & ligand bound\n"
  "\n"
  "     : Channel states (all fractions) NMDA\n"
  "        C0              : unbound\n"
  "        C1              : single bound\n"
  "        C2              : double bound\n"
  "        D               : desensitized\n"
  "        OO              : open\n"
  "\n"
  "        B               : fraction free of Mg2+ block\n"
  "}\n"
  "\n"
  "\n"
  "INITIAL {\n"
  "     R = 1\n"
  "FROM i=0 TO NumSites-1{     \n"
  "           last_quanta[i] = 40\n"
  "           release_start[i] = 10000 :initialize to something that will always be larger than any t\n"
  "RVP_Size[i] = Max_RVP\n"
  "     }\n"
  "        rates(v)\n"
  "\n"
  "        C0 = xC0 \n"
  "        C1 = xC1\n"
  "        C2 = xC2\n"
  "        D = xD\n"
  "        OO = xOO\n"
  "\n"
  "total_count = 0\n"
  "UFP = 0\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "rates(v)\n"
  "\n"
  "gluConc_dAMPA = StanddAMPA\n"
  "gluConc_NMDA = StandNMDA\n"
  "\n"
  "SOLVE vesicle_release METHOD after_cvode\n"
  "\n"
  "SOLVE RVPSIZE METHOD after_cvode\n"
  "\n"
  "SOLVE kstates METHOD sparse\n"
  "\n"
  "     g = gmax *(O+OM)\n"
  "     g2 = gmaxN * OO * B\n"
  "     i = (g * (v - erev) ) + (g2 * (v - erevN) )\n"
  "}\n"
  "\n"
  "PROCEDURE vesicle_release(){\n"
  "Orate = 0\n"
  ": Calculate size of ultra-fast pool\n"
  "UFP = 0\n"
  "FROM i=0 TO NumSites-1\n"
  "{ \n"
  "if (RVP_Size[i] == Max_RVP)\n"
  "   {UFP = UFP + 1}\n"
  "}\n"
  ":\n"
  "\n"
  "FROM i=0 TO NumSites-1 \n"
  "  {\n"
  "preCAnow = preCA\n"
  "\n"
  ":\n"
  "if (RVP_Size[i] < 1)\n"
  "{ rate[i] = S * (W * preCAnow * 1000) / ( ((preCAnow * 1000) / K1) + 1)^powr\n"
  "}  : factor of 1000 for conversion from NEURON mM to formula uM\n"
  "else\n"
  "{\n"
  "rate_constant =  (Vmax * (1000 * preCAnow)^n) / (k^n + (1000 * preCAnow)^n)\n"
  "\n"
  "if (RVP_Size[i] == Max_RVP)\n"
  " { rate[i] = UFP * rate_constant }\n"
  "else\n"
  " { rate[i] =  RVP_Size[i] * rate_constant }\n"
  "}\n"
  "Orate = Orate + rate[i]\n"
  ":\n"
  "  last_quanta[i] = last_quanta[i] + dt\n"
  ": The probability of release is linearly related to rate (rate/(1000/dt)\n"
  "  if ( ( scop_random() < (rate[i] / (1000/dt) ) ) && (last_quanta[i] >= AbsRefract) )\n"
  "     {\n"
  "       release_start[i] = t\n"
  "       last_quanta[i] = 0\n"
  "       RVP_out[i] = 1\n"
  "       total_count = total_count + 1\n"
  "     }\n"
  "gluConc_dAMPA= gluConc_dAMPA + (glumax_dAMPA * alpha( (t - release_start[i])/tau_dAMPA ))\n"
  "gluConc_NMDA = gluConc_NMDA + (glumax_NMDA * alpha( (t - release_start[i])/tau_NMDA ))\n"
  "  }\n"
  "}\n"
  "\n"
  "PROCEDURE RVPSIZE(){\n"
  "FROM i=0 TO NumSites-1\n"
  "{\n"
  "RVP_Size[i] = RVP_Size[i]  - RVP_out[i]\n"
  "if (RVP_Size[i] < 0) {RVP_Size[i] = 0}\n"
  "if (RVP_Size[i] > Max_RVP){RVP_Size[i] = Max_RVP}\n"
  ": refilling of RVP\n"
  "if (RVP_Size[i] < Max_RVP){\n"
  "rateIN[i] = rate_constantIN  *  (Max_RVP - RVP_Size[i]) \n"
  " if (scop_random() < rateIN[i] / (1000 / dt))\n"
  "  { RVP_Size[i] = RVP_Size[i] + 1 }\n"
  "}\n"
  "RVP_out[i] = 0\n"
  "}\n"
  "}\n"
  "\n"
  "KINETIC kstates {\n"
  "     rb = Rb * (1e3) * gluConc_dAMPA		:Initial lower case 'r' indicates\n"
  "     rBb = RBb * (1e3) * gluConc_dAMPA		:the rates are ligand dependent\n"
  "     rDBb = RDBb * (1e3) * gluConc_dAMPA		:and are expressed in units of	\n"
  "     rMb = RMb * (1e3) * gluConc_dAMPA 		:/micromolar/microsec\n"
  "     rMBb = RMBb * (1e3) * gluConc_dAMPA \n"
  "     rm  = Rm * (1e3) * mod_modulator		:Initial lower case 'r' indicates\n"
  "     rBm = RBm * (1e3) * mod_modulator   	:the rates are dependent on the \n"
  "     rB2m = RB2m * (1e3) * mod_modulator	:concentration of the modulator\n"
  "     rDBm = RDBm * (1e3) * mod_modulator	:(cyclothiozide or aniracetam)\n"
  "     rDB2m = RDB2m * (1e3) * mod_modulator	:units are /micromolar/microsec\n"
  "\n"
  "     ~ R <-> RA     (rb,RBu)\n"
  "     ~ RA <-> RdA   (RBd,RBDr)\n"
  "     ~ RA <-> RA2   (rBb,RB2u)\n"
  "     ~ RA2 <-> RdA2 (RB2d,RB2Dr)\n"
  "     ~ RA2 <-> O    (RB2o,RB2c)\n"
  "     ~ RdA <-> RdA2 (rDBb,RDB2u)\n"
  "     ~ R <-> RM     (rm,RMum)\n"
  "     ~ RA <-> RMA   (rBm,RBMum)\n"
  "     ~ RA2 <-> RMA2 (rB2m,RB2Mum)\n"
  "     ~ RM <-> RMA   (rMb,RMBu)\n"
  "     ~ RMA <-> RMA2 (rMBb,RMB2u)\n"
  "     ~ RMA2 <-> OM   (RMB2o,RMB2c)\n"
  "     ~ RMA2 <-> RdMA2 (RMB2d,RMB2Dr)\n"
  "     ~ RMA <-> RdMA (RMBd,RMBDr)\n"
  "     ~ RdMA <-> RdMA2 (RMDBb,RMDB2u)\n"
  "     ~ RdA <-> RdMA (rDBm,RDBMum)\n"
  "     ~ RdA2 <-> RdMA2 (rDB2m,RDB2Mum)\n"
  "\n"
  "     CONSERVE R+RM+RA+RA2+RdA+RdA2+RMA+RMA2+RdMA+RdMA2+O+OM = 1\n"
  "\n"
  "\n"
  "       rb2 = Rb2 * (1e3) * gluConc_NMDA\n"
  "\n"
  "        ~ C0 <-> C1     (rb2,Ru)\n"
  "        ~ C1 <-> C2     (rb2,Ru)\n"
  "        ~ C2 <-> D      (Rd,Rr)\n"
  "        ~ C2 <-> OO     (Ro,Rc)\n"
  "\n"
  "        CONSERVE C0+C1+C2+D+OO = 1\n"
  "}\n"
  "\n"
  "PROCEDURE rates(v(mV)) {\n"
  "        TABLE B\n"
  "        DEPEND mg\n"
  "        FROM vmin TO vmax WITH 200\n"
  "\n"
  "        : Stevens & Jahr 1990a,b\n"
  "\n"
  "        B = 1 / (1 + exp(0.062 (/mV) * -v) * (mg / 3.57 (mM)))\n"
  "}\n"
  "\n"
  "\n"
  "FUNCTION alpha(x) {\n"
  "        if (x < 0 || x > 10) {\n"
  "                alpha = 0\n"
  "        }else{\n"
  "                alpha = x * exp(1 - x)\n"
  "        }\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
