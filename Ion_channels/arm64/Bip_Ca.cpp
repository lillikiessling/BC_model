/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
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
static constexpr auto number_of_datum_variables = 8;
static constexpr auto number_of_floating_point_variables = 35;
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
 
#define nrn_init _nrn_init__Bip_Ca
#define _nrn_initial _nrn_initial__Bip_Ca
#define nrn_cur _nrn_cur__Bip_Ca
#define _nrn_current _nrn_current__Bip_Ca
#define nrn_jacob _nrn_jacob__Bip_Ca
#define nrn_state _nrn_state__Bip_Ca
#define _net_receive _net_receive__Bip_Ca 
#define rates rates__Bip_Ca 
#define states states__Bip_Ca 
 
#define _threadargscomma_ _ml, _iml, _ppvar, _thread, _globals, _nt,
#define _threadargsprotocomma_ Memb_list* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt,
#define _internalthreadargsprotocomma_ _nrn_mechanism_cache_range* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt,
#define _threadargs_ _ml, _iml, _ppvar, _thread, _globals, _nt
#define _threadargsproto_ Memb_list* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt
#define _internalthreadargsproto_ _nrn_mechanism_cache_range* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *hoc_getarg(int);
 
#define t _nt->_t
#define dt _nt->_dt
#define gcalbar _ml->template fpfield<0>(_iml)
#define gcalbar_columnindex 0
#define gcatbar _ml->template fpfield<1>(_iml)
#define gcatbar_columnindex 1
#define gkcabar _ml->template fpfield<2>(_iml)
#define gkcabar_columnindex 2
#define vshift_CaT _ml->template fpfield<3>(_iml)
#define vshift_CaT_columnindex 3
#define vshift_CaL _ml->template fpfield<4>(_iml)
#define vshift_CaL_columnindex 4
#define vshift_KCa _ml->template fpfield<5>(_iml)
#define vshift_KCa_columnindex 5
#define m_inf _ml->template fpfield<6>(_iml)
#define m_inf_columnindex 6
#define h_inf _ml->template fpfield<7>(_iml)
#define h_inf_columnindex 7
#define c_inf _ml->template fpfield<8>(_iml)
#define c_inf_columnindex 8
#define n_inf _ml->template fpfield<9>(_iml)
#define n_inf_columnindex 9
#define p_inf _ml->template fpfield<10>(_iml)
#define p_inf_columnindex 10
#define m_tau _ml->template fpfield<11>(_iml)
#define m_tau_columnindex 11
#define h_tau _ml->template fpfield<12>(_iml)
#define h_tau_columnindex 12
#define c_tau _ml->template fpfield<13>(_iml)
#define c_tau_columnindex 13
#define n_tau _ml->template fpfield<14>(_iml)
#define n_tau_columnindex 14
#define p_tau _ml->template fpfield<15>(_iml)
#define p_tau_columnindex 15
#define m _ml->template fpfield<16>(_iml)
#define m_columnindex 16
#define h _ml->template fpfield<17>(_iml)
#define h_columnindex 17
#define c _ml->template fpfield<18>(_iml)
#define c_columnindex 18
#define n _ml->template fpfield<19>(_iml)
#define n_columnindex 19
#define p _ml->template fpfield<20>(_iml)
#define p_columnindex 20
#define eca _ml->template fpfield<21>(_iml)
#define eca_columnindex 21
#define cai _ml->template fpfield<22>(_iml)
#define cai_columnindex 22
#define Dm _ml->template fpfield<23>(_iml)
#define Dm_columnindex 23
#define Dh _ml->template fpfield<24>(_iml)
#define Dh_columnindex 24
#define Dc _ml->template fpfield<25>(_iml)
#define Dc_columnindex 25
#define Dn _ml->template fpfield<26>(_iml)
#define Dn_columnindex 26
#define Dp _ml->template fpfield<27>(_iml)
#define Dp_columnindex 27
#define ica _ml->template fpfield<28>(_iml)
#define ica_columnindex 28
#define ik _ml->template fpfield<29>(_iml)
#define ik_columnindex 29
#define ical _ml->template fpfield<30>(_iml)
#define ical_columnindex 30
#define icat _ml->template fpfield<31>(_iml)
#define icat_columnindex 31
#define ek _ml->template fpfield<32>(_iml)
#define ek_columnindex 32
#define v _ml->template fpfield<33>(_iml)
#define v_columnindex 33
#define _g _ml->template fpfield<34>(_iml)
#define _g_columnindex 34
#define _ion_eca *(_ml->dptr_field<0>(_iml))
#define _p_ion_eca static_cast<neuron::container::data_handle<double>>(_ppvar[0])
#define _ion_cai *(_ml->dptr_field<1>(_iml))
#define _p_ion_cai static_cast<neuron::container::data_handle<double>>(_ppvar[1])
#define _ion_cao *(_ml->dptr_field<2>(_iml))
#define _p_ion_cao static_cast<neuron::container::data_handle<double>>(_ppvar[2])
#define _ion_ica *(_ml->dptr_field<3>(_iml))
#define _p_ion_ica static_cast<neuron::container::data_handle<double>>(_ppvar[3])
#define _ion_dicadv *(_ml->dptr_field<4>(_iml))
#define _ion_ek *(_ml->dptr_field<5>(_iml))
#define _p_ion_ek static_cast<neuron::container::data_handle<double>>(_ppvar[5])
#define _ion_ik *(_ml->dptr_field<6>(_iml))
#define _p_ion_ik static_cast<neuron::container::data_handle<double>>(_ppvar[6])
#define _ion_dikdv *(_ml->dptr_field<7>(_iml))
 /* Thread safe. No static _ml, _iml or _ppvar. */
 static int hoc_nrnpointerindex =  -1;
 static _nrn_mechanism_std_vector<Datum> _extcall_thread;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mechtype);
#endif
 static void _hoc_setdata();
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 {"setdata_Bip_Ca", _hoc_setdata},
 {"rates_Bip_Ca", _hoc_rates},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_rates(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"rates", _npy_rates},
 {0, 0}
};
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"gcalbar_Bip_Ca", "mS/cm2"},
 {"gcatbar_Bip_Ca", "mS/cm2"},
 {"gkcabar_Bip_Ca", "mS/cm2"},
 {"vshift_CaT_Bip_Ca", "mV"},
 {"vshift_CaL_Bip_Ca", "mV"},
 {"vshift_KCa_Bip_Ca", "mV"},
 {0, 0}
};
 static double c0 = 0;
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double p0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 {0, 0}
};
 static DoubVec hoc_vdoub[] = {
 {0, 0, 0}
};
 static double _sav_indep;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 _prop_id = _nrn_get_prop_id(_prop);
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 static void nrn_alloc(Prop*);
static void nrn_init(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_state(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 static void nrn_cur(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_jacob(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(Prop*, int, neuron::container::data_handle<double>*, neuron::container::data_handle<double>*, double*, int);
static void _ode_spec(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void _ode_matsol(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 
#define _cvode_ieq _ppvar[8].literal_value<int>()
 static void _ode_matsol_instance1(_internalthreadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"Bip_Ca",
 "gcalbar_Bip_Ca",
 "gcatbar_Bip_Ca",
 "gkcabar_Bip_Ca",
 "vshift_CaT_Bip_Ca",
 "vshift_CaL_Bip_Ca",
 "vshift_KCa_Bip_Ca",
 0,
 "m_inf_Bip_Ca",
 "h_inf_Bip_Ca",
 "c_inf_Bip_Ca",
 "n_inf_Bip_Ca",
 "p_inf_Bip_Ca",
 "m_tau_Bip_Ca",
 "h_tau_Bip_Ca",
 "c_tau_Bip_Ca",
 "n_tau_Bip_Ca",
 "p_tau_Bip_Ca",
 0,
 "m_Bip_Ca",
 "h_Bip_Ca",
 "c_Bip_Ca",
 "n_Bip_Ca",
 "p_Bip_Ca",
 0,
 0};
 static Symbol* _ca_sym;
 static Symbol* _k_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     0.4352, /* gcalbar */
     0.954, /* gcatbar */
     360, /* gkcabar */
     -80, /* vshift_CaT */
     -70, /* vshift_CaL */
     -53.08, /* vshift_KCa */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 9, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 35);
 	/*initialize range parameters*/
 	gcalbar = _parm_default[0]; /* 0.4352 */
 	gcatbar = _parm_default[1]; /* 0.954 */
 	gkcabar = _parm_default[2]; /* 360 */
 	vshift_CaT = _parm_default[3]; /* -80 */
 	vshift_CaL = _parm_default[4]; /* -70 */
 	vshift_KCa = _parm_default[5]; /* -53.08 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 35);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 1);
 	_ppvar[0] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* eca */
 	_ppvar[1] = _nrn_mechanism_get_param_handle(prop_ion, 1); /* cai */
 	_ppvar[2] = _nrn_mechanism_get_param_handle(prop_ion, 2); /* cao */
 	_ppvar[3] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ica */
 	_ppvar[4] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dicadv */
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[5] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* ek */
 	_ppvar[6] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ik */
 	_ppvar[7] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 {0, 0}
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _Bip_Ca_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	ion_reg("k", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
         hoc_register_npy_direct(_mechtype, npy_direct_func_proc);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"gcalbar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"gcatbar"} /* 1 */,
                                       _nrn_mechanism_field<double>{"gkcabar"} /* 2 */,
                                       _nrn_mechanism_field<double>{"vshift_CaT"} /* 3 */,
                                       _nrn_mechanism_field<double>{"vshift_CaL"} /* 4 */,
                                       _nrn_mechanism_field<double>{"vshift_KCa"} /* 5 */,
                                       _nrn_mechanism_field<double>{"m_inf"} /* 6 */,
                                       _nrn_mechanism_field<double>{"h_inf"} /* 7 */,
                                       _nrn_mechanism_field<double>{"c_inf"} /* 8 */,
                                       _nrn_mechanism_field<double>{"n_inf"} /* 9 */,
                                       _nrn_mechanism_field<double>{"p_inf"} /* 10 */,
                                       _nrn_mechanism_field<double>{"m_tau"} /* 11 */,
                                       _nrn_mechanism_field<double>{"h_tau"} /* 12 */,
                                       _nrn_mechanism_field<double>{"c_tau"} /* 13 */,
                                       _nrn_mechanism_field<double>{"n_tau"} /* 14 */,
                                       _nrn_mechanism_field<double>{"p_tau"} /* 15 */,
                                       _nrn_mechanism_field<double>{"m"} /* 16 */,
                                       _nrn_mechanism_field<double>{"h"} /* 17 */,
                                       _nrn_mechanism_field<double>{"c"} /* 18 */,
                                       _nrn_mechanism_field<double>{"n"} /* 19 */,
                                       _nrn_mechanism_field<double>{"p"} /* 20 */,
                                       _nrn_mechanism_field<double>{"eca"} /* 21 */,
                                       _nrn_mechanism_field<double>{"cai"} /* 22 */,
                                       _nrn_mechanism_field<double>{"Dm"} /* 23 */,
                                       _nrn_mechanism_field<double>{"Dh"} /* 24 */,
                                       _nrn_mechanism_field<double>{"Dc"} /* 25 */,
                                       _nrn_mechanism_field<double>{"Dn"} /* 26 */,
                                       _nrn_mechanism_field<double>{"Dp"} /* 27 */,
                                       _nrn_mechanism_field<double>{"ica"} /* 28 */,
                                       _nrn_mechanism_field<double>{"ik"} /* 29 */,
                                       _nrn_mechanism_field<double>{"ical"} /* 30 */,
                                       _nrn_mechanism_field<double>{"icat"} /* 31 */,
                                       _nrn_mechanism_field<double>{"ek"} /* 32 */,
                                       _nrn_mechanism_field<double>{"v"} /* 33 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 34 */,
                                       _nrn_mechanism_field<double*>{"_ion_eca", "ca_ion"} /* 0 */,
                                       _nrn_mechanism_field<double*>{"_ion_cai", "ca_ion"} /* 1 */,
                                       _nrn_mechanism_field<double*>{"_ion_cao", "ca_ion"} /* 2 */,
                                       _nrn_mechanism_field<double*>{"_ion_ica", "ca_ion"} /* 3 */,
                                       _nrn_mechanism_field<double*>{"_ion_dicadv", "ca_ion"} /* 4 */,
                                       _nrn_mechanism_field<double*>{"_ion_ek", "k_ion"} /* 5 */,
                                       _nrn_mechanism_field<double*>{"_ion_ik", "k_ion"} /* 6 */,
                                       _nrn_mechanism_field<double*>{"_ion_dikdv", "k_ion"} /* 7 */,
                                       _nrn_mechanism_field<int>{"_cvode_ieq", "cvodeieq"} /* 8 */);
  hoc_register_prop_size(_mechtype, 35, 9);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 8, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Bip_Ca /Users/lillikiessling/Documents/Stanford/Code/BC_model/Ion_channels/Bip_Ca.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_internalthreadargsprotocomma_ double);
 
static int _ode_spec1(_internalthreadargsproto_);
/*static int _ode_matsol1(_internalthreadargsproto_);*/
 static neuron::container::field_index _slist1[5], _dlist1[5];
 static int states(_internalthreadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (_internalthreadargsproto_) {int _reset = 0; {
   rates ( _threadargscomma_ v ) ;
   Dm = ( m_inf - m ) / m_tau ;
   Dn = ( n_inf - n ) / n_tau ;
   Dh = ( h_inf - h ) / h_tau ;
   Dp = ( p_inf - p ) / p_tau ;
   Dc = ( c_inf - c ) / c_tau ;
   }
 return _reset;
}
 static int _ode_matsol1 (_internalthreadargsproto_) {
 rates ( _threadargscomma_ v ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / m_tau )) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / n_tau )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / h_tau )) ;
 Dp = Dp  / (1. - dt*( ( ( ( - 1.0 ) ) ) / p_tau )) ;
 Dc = Dc  / (1. - dt*( ( ( ( - 1.0 ) ) ) / c_tau )) ;
  return 0;
}
 /*END CVODE*/
 static int states (_internalthreadargsproto_) { {
   rates ( _threadargscomma_ v ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / m_tau)))*(- ( ( ( m_inf ) ) / m_tau ) / ( ( ( ( - 1.0 ) ) ) / m_tau ) - m) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / n_tau)))*(- ( ( ( n_inf ) ) / n_tau ) / ( ( ( ( - 1.0 ) ) ) / n_tau ) - n) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / h_tau)))*(- ( ( ( h_inf ) ) / h_tau ) / ( ( ( ( - 1.0 ) ) ) / h_tau ) - h) ;
    p = p + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / p_tau)))*(- ( ( ( p_inf ) ) / p_tau ) / ( ( ( ( - 1.0 ) ) ) / p_tau ) - p) ;
    c = c + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / c_tau)))*(- ( ( ( c_inf ) ) / c_tau ) / ( ( ( ( - 1.0 ) ) ) / c_tau ) - c) ;
   }
  return 0;
}
 
static int  rates ( _internalthreadargsprotocomma_ double _lv ) {
   double _lv_CaL , _lv_CaT , _lv_KCa , _lam , _lbm , _lah , _lbh , _lan , _lbn , _lap , _lbp , _lac , _lbc ;
 _lv_CaL = _lv - vshift_CaL ;
   _lv_CaT = _lv - vshift_CaT ;
   _lv_KCa = _lv - vshift_KCa ;
   _lam = 0.427 * ( _lv_CaL - 63.0 ) / ( 1.0 - exp ( - ( _lv_CaL - 63.0 ) / 10.5 ) ) ;
   _lbm = 0.0406 * exp ( ( 70.0 - _lv_CaL ) / 12.0 ) ;
   m_tau = 1.0 / ( _lam + _lbm ) ;
   m_inf = _lam * m_tau ;
   h_tau = 292.0 ;
   h_inf = 1.0 / ( 1.0 + exp ( ( _lv_CaL / 66.4 ) ) ) ;
   n_tau = 1.358 * ( 21.675 / ( 1.0 + exp ( ( _lv + 39.9596 ) / 4.110392 ) ) ) ;
   n_inf = 1.0 / ( 1.0 + exp ( - ( _lv + 37.5456 ) / 3.073015 ) ) ;
   p_tau = 65.8207 + 0.0023 * exp ( ( _lv_CaT - 80.0 ) / 4.781719 ) ;
   p_inf = 1.0 / ( 1.0 + exp ( ( _lv_CaT - 8.968 ) / 8.416382 ) ) ;
   _lac = ( 100.0 * ( 230.0 - _lv_KCa ) ) / ( ( exp ( ( 230.0 - _lv_KCa ) / 52.0 ) ) - 1.0 ) ;
   _lbc = 120.0 * ( exp ( ( - _lv_KCa / 95.0 ) ) ) ;
   c_tau = 1.0 / ( _lac + _lbc ) ;
   c_inf = _lac * c_tau ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for rates_Bip_Ca. Requires prior call to setdata_Bip_Ca and that the specified mechanism instance still be in existence.", NULL);
  }
  Prop* _local_prop = _extcall_prop;
  _nrn_mechanism_cache_instance _ml_real{_local_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _local_prop ? _nrn_mechanism_access_dparam(_local_prop) : nullptr;
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r = 1.;
 rates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_rates(Prop* _prop) {
    double _r{0.0};
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 _nrn_mechanism_cache_instance _ml_real{_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _nrn_mechanism_access_dparam(_prop);
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r = 1.;
 rates ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int _ode_count(int _type){ return 5;}
 
static void _ode_spec(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
   Datum* _ppvar;
   size_t _iml;   _nrn_mechanism_cache_range* _ml;   Node* _nd{};
  double _v{};
  int _cntml;
  _nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
  _ml = &_lmr;
  _cntml = _ml_arg->_nodecount;
  Datum *_thread{_ml_arg->_thread};
  double* _globals = nullptr;
  if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _ppvar = _ml_arg->_pdata[_iml];
    _nd = _ml_arg->_nodelist[_iml];
    v = NODEV(_nd);
  eca = _ion_eca;
  cai = _ion_cai;
  ek = _ion_ek;
     _ode_spec1 (_threadargs_);
   }}
 
static void _ode_map(Prop* _prop, int _ieq, neuron::container::data_handle<double>* _pv, neuron::container::data_handle<double>* _pvdot, double* _atol, int _type) { 
  Datum* _ppvar;
  _ppvar = _nrn_mechanism_access_dparam(_prop);
  _cvode_ieq = _ieq;
  for (int _i=0; _i < 5; ++_i) {
    _pv[_i] = _nrn_mechanism_get_param_handle(_prop, _slist1[_i]);
    _pvdot[_i] = _nrn_mechanism_get_param_handle(_prop, _dlist1[_i]);
    _cvode_abstol(_atollist, _atol, _i);
  }
 }
 
static void _ode_matsol_instance1(_internalthreadargsproto_) {
 _ode_matsol1 (_threadargs_);
 }
 
static void _ode_matsol(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
   Datum* _ppvar;
   size_t _iml;   _nrn_mechanism_cache_range* _ml;   Node* _nd{};
  double _v{};
  int _cntml;
  _nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
  _ml = &_lmr;
  _cntml = _ml_arg->_nodecount;
  Datum *_thread{_ml_arg->_thread};
  double* _globals = nullptr;
  if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _ppvar = _ml_arg->_pdata[_iml];
    _nd = _ml_arg->_nodelist[_iml];
    v = NODEV(_nd);
  eca = _ion_eca;
  cai = _ion_cai;
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel(_internalthreadargsproto_) {
  int _i; double _save;{
  c = c0;
  h = h0;
  m = m0;
  n = n0;
  p = p0;
 {
   rates ( _threadargscomma_ v ) ;
   m = m_inf ;
   n = n_inf ;
   h = h_inf ;
   p = p_inf ;
   c = c_inf ;
   }
 
}
}

static void nrn_init(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
 v = _v;
  eca = _ion_eca;
  cai = _ion_cai;
  ek = _ion_ek;
 initmodel(_threadargs_);
  }
}

static double _nrn_current(_internalthreadargsprotocomma_ double _v) {
double _current=0.; v=_v;
{ {
   ical = ( 1e-3 ) * gcalbar * m * m * h * ( v - ( 0.32 * eca + 0.68 * - 58.0 ) ) ;
   icat = ( 1e-3 ) * gcatbar * n * p * ( v - ( 0.45 * eca + 0.55 * - 58.0 ) ) ;
   ica = ical + icat ;
   ik = gkcabar * c * c * ( ( cai ) / ( cai + 0.2 ) ) * ( v - ek ) ;
   }
 _current += ica;
 _current += ik;

} return _current;
}

static void nrn_cur(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_rhs = _nt->node_rhs_storage();
auto const _vec_sav_rhs = _nt->node_sav_rhs_storage();
auto const _vec_v = _nt->node_voltage_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
  eca = _ion_eca;
  cai = _ion_cai;
  ek = _ion_ek;
 auto const _g_local = _nrn_current(_threadargscomma_ _v + .001);
 	{ double _dik;
 double _dica;
  _dica = ica;
  _dik = ik;
 _rhs = _nrn_current(_threadargscomma_ _v);
  _ion_dicadv += (_dica - ica)/.001 ;
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g_local - _rhs)/.001;
  _ion_ica += ica ;
  _ion_ik += ik ;
	 _vec_rhs[_ni[_iml]] -= _rhs;
 
}
 
}

static void nrn_jacob(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_d = _nt->node_d_storage();
auto const _vec_sav_d = _nt->node_sav_d_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (_iml = 0; _iml < _cntml; ++_iml) {
  _vec_d[_ni[_iml]] += _g;
 
}
 
}

static void nrn_state(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni;
_ni = _ml_arg->_nodeindices;
size_t _cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (size_t _iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
 _nd = _ml_arg->_nodelist[_iml];
   _v = _vec_v[_ni[_iml]];
 v=_v;
{
  eca = _ion_eca;
  cai = _ion_cai;
  ek = _ion_ek;
 {   states(_threadargs_);
  }  }}

}

static void terminal(){}

static void _initlists(){
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = {m_columnindex, 0};  _dlist1[0] = {Dm_columnindex, 0};
 _slist1[1] = {n_columnindex, 0};  _dlist1[1] = {Dn_columnindex, 0};
 _slist1[2] = {h_columnindex, 0};  _dlist1[2] = {Dh_columnindex, 0};
 _slist1[3] = {p_columnindex, 0};  _dlist1[3] = {Dp_columnindex, 0};
 _slist1[4] = {c_columnindex, 0};  _dlist1[4] = {Dc_columnindex, 0};
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/Users/lillikiessling/Documents/Stanford/Code/BC_model/Ion_channels/Bip_Ca.mod";
    const char* nmodl_file_text = 
  "NEURON {\n"
  "	THREADSAFE\n"
  "    	SUFFIX Bip_Ca\n"
  "    	USEION ca READ eca, cai WRITE ica\n"
  "        USEION k READ ek WRITE ik\n"
  "    	RANGE gcalbar, gcatbar, gkcabar\n"
  "    	RANGE m_inf, h_inf, c_inf, n_inf, p_inf\n"
  "    	RANGE m_tau, h_tau, c_tau, n_tau, p_tau\n"
  "		RANGE vshift_CaT, vshift_CaL, vshift_KCa\n"
  "}\n"
  "\n"
  ":m and h is used for Bip_CaL\n"
  ":n and p is used for Bip_CaT\n"
  ":c is used for Bip_KCa\n"
  "\n"
  "UNITS {\n"
  "	(molar) = 	(1/liter)\n"
  "	(mA) = 		(milliamp)\n"
  "	(mV) = 		(millivolt)\n"
  "	(mS) = 		(millisiemens)\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "PARAMETER {\n"
  "    gcalbar = 0.4352	(mS/cm2)\n"
  "    gcatbar = 0.954 	(mS/cm2)\n"
  "    gkcabar = 360	    (mS/cm2)\n"
  "    eca          	    (mV)\n"
  "    cai = 0.1 		    (uM)\n"
  "    dt           	    (ms)\n"
  "    v            	    (mV)\n"
  "    vshift_CaT = -80	(mV)\n"
  "    vshift_CaL = -70	(mV)\n"
  "    vshift_KCa = -53.08 (mV)	\n"
  "}\n"
  "\n"
  "STATE  {m h c n p}\n"
  "\n"
  "\n"
  "INITIAL {\n"
  "	rates(v)\n"
  "	m = m_inf\n"
  "    n = n_inf\n"
  "	h = h_inf\n"
  "    p = p_inf\n"
  "	c = c_inf\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    ica    		(mA/cm2)\n"
  "    ik        (mA/cm2)\n"
  "    ical    	(mA/cm2)\n"
  "    icat    	(mA/cm2)\n"
  "    ek        (mV)\n"
  "    m_inf h_inf c_inf n_inf p_inf\n"
  "    m_tau h_tau c_tau n_tau p_tau\n"
  "}\n"
  "\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states METHOD cnexp\n"
  "    	ical = (1e-3) * gcalbar * m*m*h * (v-(0.32*eca+0.68*-58))\n"
  "        icat = (1e-3) * gcatbar * n*p * (v-(0.45*eca+0.55*-58))\n"
  "        ica = ical + icat\n"
  "        ik = gkcabar*c*c*((cai)/(cai+0.2)) * (v - ek)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    rates(v)\n"
  "    m' = (m_inf-m)/m_tau\n"
  "    n' = (n_inf-n)/n_tau\n"
  "    h' = (h_inf-h)/h_tau\n"
  "    p' = (p_inf-p)/p_tau\n"
  "    c' = (c_inf-c)/c_tau\n"
  "}\n"
  "\n"
  "PROCEDURE rates(v (mV)) {\n"
  "    LOCAL v_CaL, v_CaT, v_KCa, am,bm,ah,bh,an,bn,ap,bp,ac,bc\n"
  "    v_CaL = v - vshift_CaL\n"
  "    v_CaT = v - vshift_CaT\n"
  "    v_KCa = v - vshift_KCa\n"
  "\n"
  "    : Bip_CaL m and h\n"
  "    am = 0.427 * (v_CaL - 63) / (1 - exp(-(v_CaL - 63)/10.5))\n"
  "	bm = 0.0406 * exp((70 - v_CaL)/12)\n"
  "	m_tau = 1 / (am+bm)\n"
  "	m_inf = am * m_tau\n"
  "    h_tau = 292\n"
  "    h_inf = 1 / (1 + exp((v_CaL/ 66.4)))\n"
  "\n"
  "    : Bip_CaT n and p\n"
  "    n_tau = 1.358 *(21.675 / (1 + exp((v + 39.9596) / 4.110392)))\n"
  "    n_inf =  1 / (1 + exp(-(v + 37.5456) / 3.073015))\n"
  "    p_tau = 65.8207 + 0.0023 * exp((v_CaT - 80) / 4.781719)\n"
  "    p_inf = 1 / (1 + exp((v_CaT - 8.968) / 8.416382))\n"
  "\n"
  "    : Bip_KCa c\n"
  "    ac = (100 * (230-v_KCa)) / ((exp((230-v_KCa)/52)) - 1)\n"
  "    bc = 120 * (exp((-v_KCa/95)))\n"
  "    c_tau = 1 / (ac + bc) \n"
  "    c_inf = ac * c_tau\n"
  "}\n"
  "\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
