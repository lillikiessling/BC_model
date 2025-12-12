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
static constexpr auto number_of_datum_variables = 11;
static constexpr auto number_of_floating_point_variables = 32;
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
 
#define nrn_init _nrn_init__FCM
#define _nrn_initial _nrn_initial__FCM
#define nrn_cur _nrn_cur__FCM
#define _nrn_current _nrn_current__FCM
#define nrn_jacob _nrn_jacob__FCM
#define nrn_state _nrn_state__FCM
#define _net_receive _net_receive__FCM 
#define crates crates__FCM 
#define hrates hrates__FCM 
#define mrates mrates__FCM 
#define nrates nrates__FCM 
#define states states__FCM 
 
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
#define gnabar _ml->template fpfield<0>(_iml)
#define gnabar_columnindex 0
#define gkbar _ml->template fpfield<1>(_iml)
#define gkbar_columnindex 1
#define gcabar _ml->template fpfield<2>(_iml)
#define gcabar_columnindex 2
#define gkcabar _ml->template fpfield<3>(_iml)
#define gkcabar_columnindex 3
#define ina _ml->template fpfield<4>(_iml)
#define ina_columnindex 4
#define ik _ml->template fpfield<5>(_iml)
#define ik_columnindex 5
#define ik_ _ml->template fpfield<6>(_iml)
#define ik__columnindex 6
#define ikca _ml->template fpfield<7>(_iml)
#define ikca_columnindex 7
#define m_inf _ml->template fpfield<8>(_iml)
#define m_inf_columnindex 8
#define h_inf _ml->template fpfield<9>(_iml)
#define h_inf_columnindex 9
#define n_inf _ml->template fpfield<10>(_iml)
#define n_inf_columnindex 10
#define c_inf _ml->template fpfield<11>(_iml)
#define c_inf_columnindex 11
#define m_tau _ml->template fpfield<12>(_iml)
#define m_tau_columnindex 12
#define h_tau _ml->template fpfield<13>(_iml)
#define h_tau_columnindex 13
#define n_tau _ml->template fpfield<14>(_iml)
#define n_tau_columnindex 14
#define c_tau _ml->template fpfield<15>(_iml)
#define c_tau_columnindex 15
#define m _ml->template fpfield<16>(_iml)
#define m_columnindex 16
#define h _ml->template fpfield<17>(_iml)
#define h_columnindex 17
#define n _ml->template fpfield<18>(_iml)
#define n_columnindex 18
#define c _ml->template fpfield<19>(_iml)
#define c_columnindex 19
#define ena _ml->template fpfield<20>(_iml)
#define ena_columnindex 20
#define ek _ml->template fpfield<21>(_iml)
#define ek_columnindex 21
#define eca _ml->template fpfield<22>(_iml)
#define eca_columnindex 22
#define cao _ml->template fpfield<23>(_iml)
#define cao_columnindex 23
#define cai _ml->template fpfield<24>(_iml)
#define cai_columnindex 24
#define Dm _ml->template fpfield<25>(_iml)
#define Dm_columnindex 25
#define Dh _ml->template fpfield<26>(_iml)
#define Dh_columnindex 26
#define Dn _ml->template fpfield<27>(_iml)
#define Dn_columnindex 27
#define Dc _ml->template fpfield<28>(_iml)
#define Dc_columnindex 28
#define ica _ml->template fpfield<29>(_iml)
#define ica_columnindex 29
#define v _ml->template fpfield<30>(_iml)
#define v_columnindex 30
#define _g _ml->template fpfield<31>(_iml)
#define _g_columnindex 31
#define _ion_ena *(_ml->dptr_field<0>(_iml))
#define _p_ion_ena static_cast<neuron::container::data_handle<double>>(_ppvar[0])
#define _ion_ina *(_ml->dptr_field<1>(_iml))
#define _p_ion_ina static_cast<neuron::container::data_handle<double>>(_ppvar[1])
#define _ion_dinadv *(_ml->dptr_field<2>(_iml))
#define _ion_ek *(_ml->dptr_field<3>(_iml))
#define _p_ion_ek static_cast<neuron::container::data_handle<double>>(_ppvar[3])
#define _ion_ik *(_ml->dptr_field<4>(_iml))
#define _p_ion_ik static_cast<neuron::container::data_handle<double>>(_ppvar[4])
#define _ion_dikdv *(_ml->dptr_field<5>(_iml))
#define _ion_cai *(_ml->dptr_field<6>(_iml))
#define _p_ion_cai static_cast<neuron::container::data_handle<double>>(_ppvar[6])
#define _ion_eca *(_ml->dptr_field<7>(_iml))
#define _p_ion_eca static_cast<neuron::container::data_handle<double>>(_ppvar[7])
#define _ion_cao *(_ml->dptr_field<8>(_iml))
#define _p_ion_cao static_cast<neuron::container::data_handle<double>>(_ppvar[8])
#define _ion_ica *(_ml->dptr_field<9>(_iml))
#define _p_ion_ica static_cast<neuron::container::data_handle<double>>(_ppvar[9])
#define _ion_dicadv *(_ml->dptr_field<10>(_iml))
 /* Thread safe. No static _ml, _iml or _ppvar. */
 static int hoc_nrnpointerindex =  -1;
 static _nrn_mechanism_std_vector<Datum> _extcall_thread;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_crates(void);
 static void _hoc_hrates(void);
 static void _hoc_mrates(void);
 static void _hoc_nrates(void);
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
 {"setdata_FCM", _hoc_setdata},
 {"crates_FCM", _hoc_crates},
 {"hrates_FCM", _hoc_hrates},
 {"mrates_FCM", _hoc_mrates},
 {"nrates_FCM", _hoc_nrates},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_crates(Prop*);
 static double _npy_hrates(Prop*);
 static double _npy_mrates(Prop*);
 static double _npy_nrates(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"crates", _npy_crates},
 {"hrates", _npy_hrates},
 {"mrates", _npy_mrates},
 {"nrates", _npy_nrates},
 {0, 0}
};
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
#define cadis cadis_FCM
 double cadis = 0.001;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"cadis_FCM", "mM"},
 {"gnabar_FCM", "mS/cm2"},
 {"gkbar_FCM", "mS/cm2"},
 {"gcabar_FCM", "mS/cm2"},
 {"gkcabar_FCM", "mS/cm2"},
 {"ina_FCM", "mA/cm2"},
 {"ik_FCM", "mA/cm2"},
 {"ik__FCM", "mA/cm2"},
 {"ikca_FCM", "mA/cm2"},
 {0, 0}
};
 static double c0 = 0;
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 {"cadis_FCM", &cadis_FCM},
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
 
#define _cvode_ieq _ppvar[11].literal_value<int>()
 static void _ode_matsol_instance1(_internalthreadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"FCM",
 "gnabar_FCM",
 "gkbar_FCM",
 "gcabar_FCM",
 "gkcabar_FCM",
 0,
 "ina_FCM",
 "ik_FCM",
 "ik__FCM",
 "ikca_FCM",
 "m_inf_FCM",
 "h_inf_FCM",
 "n_inf_FCM",
 "c_inf_FCM",
 "m_tau_FCM",
 "h_tau_FCM",
 "n_tau_FCM",
 "c_tau_FCM",
 0,
 "m_FCM",
 "h_FCM",
 "n_FCM",
 "c_FCM",
 0,
 0};
 static Symbol* _na_sym;
 static Symbol* _k_sym;
 static Symbol* _ca_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     0, /* gnabar */
     0, /* gkbar */
     0, /* gcabar */
     0, /* gkcabar */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 12, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 32);
 	/*initialize range parameters*/
 	gnabar = _parm_default[0]; /* 0 */
 	gkbar = _parm_default[1]; /* 0 */
 	gcabar = _parm_default[2]; /* 0 */
 	gkcabar = _parm_default[3]; /* 0 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 32);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* ena */
 	_ppvar[1] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ina */
 	_ppvar[2] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dinadv */
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[3] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* ek */
 	_ppvar[4] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ik */
 	_ppvar[5] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dikdv */
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 1);
 	_ppvar[6] = _nrn_mechanism_get_param_handle(prop_ion, 1); /* cai */
 	_ppvar[7] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* eca */
 	_ppvar[8] = _nrn_mechanism_get_param_handle(prop_ion, 2); /* cao */
 	_ppvar[9] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ica */
 	_ppvar[10] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dicadv */
 
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

 extern "C" void _FCM_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	ion_reg("k", -10000.);
 	ion_reg("ca", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	_k_sym = hoc_lookup("k_ion");
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
         hoc_register_npy_direct(_mechtype, npy_direct_func_proc);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"gnabar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"gkbar"} /* 1 */,
                                       _nrn_mechanism_field<double>{"gcabar"} /* 2 */,
                                       _nrn_mechanism_field<double>{"gkcabar"} /* 3 */,
                                       _nrn_mechanism_field<double>{"ina"} /* 4 */,
                                       _nrn_mechanism_field<double>{"ik"} /* 5 */,
                                       _nrn_mechanism_field<double>{"ik_"} /* 6 */,
                                       _nrn_mechanism_field<double>{"ikca"} /* 7 */,
                                       _nrn_mechanism_field<double>{"m_inf"} /* 8 */,
                                       _nrn_mechanism_field<double>{"h_inf"} /* 9 */,
                                       _nrn_mechanism_field<double>{"n_inf"} /* 10 */,
                                       _nrn_mechanism_field<double>{"c_inf"} /* 11 */,
                                       _nrn_mechanism_field<double>{"m_tau"} /* 12 */,
                                       _nrn_mechanism_field<double>{"h_tau"} /* 13 */,
                                       _nrn_mechanism_field<double>{"n_tau"} /* 14 */,
                                       _nrn_mechanism_field<double>{"c_tau"} /* 15 */,
                                       _nrn_mechanism_field<double>{"m"} /* 16 */,
                                       _nrn_mechanism_field<double>{"h"} /* 17 */,
                                       _nrn_mechanism_field<double>{"n"} /* 18 */,
                                       _nrn_mechanism_field<double>{"c"} /* 19 */,
                                       _nrn_mechanism_field<double>{"ena"} /* 20 */,
                                       _nrn_mechanism_field<double>{"ek"} /* 21 */,
                                       _nrn_mechanism_field<double>{"eca"} /* 22 */,
                                       _nrn_mechanism_field<double>{"cao"} /* 23 */,
                                       _nrn_mechanism_field<double>{"cai"} /* 24 */,
                                       _nrn_mechanism_field<double>{"Dm"} /* 25 */,
                                       _nrn_mechanism_field<double>{"Dh"} /* 26 */,
                                       _nrn_mechanism_field<double>{"Dn"} /* 27 */,
                                       _nrn_mechanism_field<double>{"Dc"} /* 28 */,
                                       _nrn_mechanism_field<double>{"ica"} /* 29 */,
                                       _nrn_mechanism_field<double>{"v"} /* 30 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 31 */,
                                       _nrn_mechanism_field<double*>{"_ion_ena", "na_ion"} /* 0 */,
                                       _nrn_mechanism_field<double*>{"_ion_ina", "na_ion"} /* 1 */,
                                       _nrn_mechanism_field<double*>{"_ion_dinadv", "na_ion"} /* 2 */,
                                       _nrn_mechanism_field<double*>{"_ion_ek", "k_ion"} /* 3 */,
                                       _nrn_mechanism_field<double*>{"_ion_ik", "k_ion"} /* 4 */,
                                       _nrn_mechanism_field<double*>{"_ion_dikdv", "k_ion"} /* 5 */,
                                       _nrn_mechanism_field<double*>{"_ion_cai", "ca_ion"} /* 6 */,
                                       _nrn_mechanism_field<double*>{"_ion_eca", "ca_ion"} /* 7 */,
                                       _nrn_mechanism_field<double*>{"_ion_cao", "ca_ion"} /* 8 */,
                                       _nrn_mechanism_field<double*>{"_ion_ica", "ca_ion"} /* 9 */,
                                       _nrn_mechanism_field<double*>{"_ion_dicadv", "ca_ion"} /* 10 */,
                                       _nrn_mechanism_field<int>{"_cvode_ieq", "cvodeieq"} /* 11 */);
  hoc_register_prop_size(_mechtype, 32, 12);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 8, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 9, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 10, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 11, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 FCM /Users/lillikiessling/Documents/Stanford/Code/BC_model/Ion_channels/FCM.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "HH style channels for spiking retinal ganglion cells";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int crates(_internalthreadargsprotocomma_ double);
static int hrates(_internalthreadargsprotocomma_ double);
static int mrates(_internalthreadargsprotocomma_ double);
static int nrates(_internalthreadargsprotocomma_ double);
 
static int _ode_spec1(_internalthreadargsproto_);
/*static int _ode_matsol1(_internalthreadargsproto_);*/
 static neuron::container::field_index _slist1[4], _dlist1[4];
 static int states(_internalthreadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (_internalthreadargsproto_) {int _reset = 0; {
   mrates ( _threadargscomma_ v ) ;
   hrates ( _threadargscomma_ v ) ;
   nrates ( _threadargscomma_ v ) ;
   crates ( _threadargscomma_ v ) ;
   Dm = ( m_inf - m ) / m_tau ;
   Dh = ( h_inf - h ) / h_tau ;
   Dn = ( n_inf - n ) / n_tau ;
   Dc = ( c_inf - c ) / c_tau ;
   }
 return _reset;
}
 static int _ode_matsol1 (_internalthreadargsproto_) {
 mrates ( _threadargscomma_ v ) ;
 hrates ( _threadargscomma_ v ) ;
 nrates ( _threadargscomma_ v ) ;
 crates ( _threadargscomma_ v ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / m_tau )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / h_tau )) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / n_tau )) ;
 Dc = Dc  / (1. - dt*( ( ( ( - 1.0 ) ) ) / c_tau )) ;
  return 0;
}
 /*END CVODE*/
 static int states (_internalthreadargsproto_) { {
   mrates ( _threadargscomma_ v ) ;
   hrates ( _threadargscomma_ v ) ;
   nrates ( _threadargscomma_ v ) ;
   crates ( _threadargscomma_ v ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / m_tau)))*(- ( ( ( m_inf ) ) / m_tau ) / ( ( ( ( - 1.0 ) ) ) / m_tau ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / h_tau)))*(- ( ( ( h_inf ) ) / h_tau ) / ( ( ( ( - 1.0 ) ) ) / h_tau ) - h) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / n_tau)))*(- ( ( ( n_inf ) ) / n_tau ) / ( ( ( ( - 1.0 ) ) ) / n_tau ) - n) ;
    c = c + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / c_tau)))*(- ( ( ( c_inf ) ) / c_tau ) / ( ( ( ( - 1.0 ) ) ) / c_tau ) - c) ;
   }
  return 0;
}
 
static int  mrates ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = ( - 2.725 * ( _lv + 35.0 ) ) / ( exp ( - 0.1 * ( _lv + 35.0 ) ) - 1.0 ) ;
   _lb = 90.83 * exp ( - ( _lv + 60.0 ) / 20.0 ) ;
   m_tau = 1.0 / ( _la + _lb ) ;
   m_inf = _la * m_tau ;
    return 0; }
 
static void _hoc_mrates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for mrates_FCM. Requires prior call to setdata_FCM and that the specified mechanism instance still be in existence.", NULL);
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
 mrates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_mrates(Prop* _prop) {
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
 mrates ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  hrates ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = 1.817 * exp ( - ( _lv + 52.0 ) / 20.0 ) ;
   _lb = 27.25 / ( exp ( - 0.1 * ( _lv + 22.0 ) ) + 1.0 ) ;
   h_tau = 1.0 / ( _la + _lb ) ;
   h_inf = _la * h_tau ;
    return 0; }
 
static void _hoc_hrates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for hrates_FCM. Requires prior call to setdata_FCM and that the specified mechanism instance still be in existence.", NULL);
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
 hrates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_hrates(Prop* _prop) {
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
 hrates ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  nrates ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = ( - 0.09575 * ( _lv + 37.0 ) ) / ( ( exp ( - 0.1 * ( _lv + 37.0 ) ) - 1.0 ) ) ;
   _lb = 1.915 * exp ( - ( _lv + 47.0 ) / 80.0 ) ;
   n_tau = 1.0 / ( _la + _lb ) ;
   n_inf = _la * n_tau ;
    return 0; }
 
static void _hoc_nrates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for nrates_FCM. Requires prior call to setdata_FCM and that the specified mechanism instance still be in existence.", NULL);
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
 nrates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_nrates(Prop* _prop) {
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
 nrates ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  crates ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = ( - 1.362 * ( _lv + 13.0 ) ) / ( exp ( - 0.1 * ( _lv + 13.0 ) ) - 1.0 ) ;
   _lb = 45.41 * exp ( - ( _lv + 38.0 ) / 18.0 ) ;
   c_tau = 1.0 / ( _la + _lb ) ;
   c_inf = _la * c_tau ;
    return 0; }
 
static void _hoc_crates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for crates_FCM. Requires prior call to setdata_FCM and that the specified mechanism instance still be in existence.", NULL);
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
 crates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_crates(Prop* _prop) {
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
 crates ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int _ode_count(int _type){ return 4;}
 
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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
     _ode_spec1 (_threadargs_);
    }}
 
static void _ode_map(Prop* _prop, int _ieq, neuron::container::data_handle<double>* _pv, neuron::container::data_handle<double>* _pvdot, double* _atol, int _type) { 
  Datum* _ppvar;
  _ppvar = _nrn_mechanism_access_dparam(_prop);
  _cvode_ieq = _ieq;
  for (int _i=0; _i < 4; ++_i) {
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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel(_internalthreadargsproto_) {
  int _i; double _save;{
  c = c0;
  h = h0;
  m = m0;
  n = n0;
 {
   mrates ( _threadargscomma_ v ) ;
   m = m_inf ;
   hrates ( _threadargscomma_ v ) ;
   h = h_inf ;
   nrates ( _threadargscomma_ v ) ;
   n = n_inf ;
   crates ( _threadargscomma_ v ) ;
   c = c_inf ;
   }
 {
   mrates ( _threadargscomma_ v ) ;
   hrates ( _threadargscomma_ v ) ;
   nrates ( _threadargscomma_ v ) ;
   crates ( _threadargscomma_ v ) ;
   m = m_inf ;
   h = h_inf ;
   n = n_inf ;
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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 initmodel(_threadargs_);
   }
}

static double _nrn_current(_internalthreadargsprotocomma_ double _v) {
double _current=0.; v=_v;
{ {
   ina = ( 1e-3 ) * gnabar * m * m * m * h * ( v - ena ) ;
   ik_ = ( 1e-3 ) * gkbar * n * n * n * n * ( v - ek ) ;
   ikca = ( 1e-3 ) * gkcabar * ( ( cai / cadis ) / ( 1.0 + ( cai / cadis ) ) ) * ( v - ek ) ;
   ik = ik_ + ikca ;
   ica = ( 1e-3 ) * gcabar * c * c * c * ( v - eca ) ;
   }
 _current += ina;
 _current += ik;
 _current += ica;

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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 auto const _g_local = _nrn_current(_threadargscomma_ _v + .001);
 	{ double _dica;
 double _dik;
 double _dina;
  _dina = ina;
  _dik = ik;
  _dica = ica;
 _rhs = _nrn_current(_threadargscomma_ _v);
  _ion_dinadv += (_dina - ina)/.001 ;
  _ion_dikdv += (_dik - ik)/.001 ;
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g_local - _rhs)/.001;
  _ion_ina += ina ;
  _ion_ik += ik ;
  _ion_ica += ica ;
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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 {   states(_threadargs_);
  }   }}

}

static void terminal(){}

static void _initlists(){
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = {m_columnindex, 0};  _dlist1[0] = {Dm_columnindex, 0};
 _slist1[1] = {h_columnindex, 0};  _dlist1[1] = {Dh_columnindex, 0};
 _slist1[2] = {n_columnindex, 0};  _dlist1[2] = {Dn_columnindex, 0};
 _slist1[3] = {c_columnindex, 0};  _dlist1[3] = {Dc_columnindex, 0};
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/Users/lillikiessling/Documents/Stanford/Code/BC_model/Ion_channels/FCM.mod";
    const char* nmodl_file_text = 
  "TITLE HH style channels for spiking retinal ganglion cells\n"
  ":\n"
  ": Modified from Fohlmeister et al., 2010\n"
  ": must be used with calcium pump mechanism, i.e. capump.mod\n"
  "\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	THREADSAFE\n"
  "    	SUFFIX FCM\n"
  "    	USEION na READ ena WRITE ina\n"
  "    	USEION k READ ek WRITE ik\n"
  "    	USEION ca READ cai, eca, cao WRITE ica\n"
  "    	RANGE gnabar, gkbar, gcabar, gkcabar\n"
  "    	RANGE m_inf, h_inf, n_inf, c_inf\n"
  "    	RANGE m_tau, h_tau, n_tau, c_tau\n"
  "    	RANGE ik, ik_, ikca\n"
  "	RANGE ina\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "    	(molar) = 	(1/liter)\n"
  "    	(mM) = 		(millimolar)\n"
  "    	(mA) = 		(milliamp)\n"
  "    	(mV) = 		(millivolt)\n"
  "		(mS) = 		(millisiemens)\n"
  "\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    	gnabar		(mS/cm2)\n"
  "    	gkbar 		(mS/cm2)\n"
  "    	gcabar   	(mS/cm2)\n"
  "    	gkcabar 	(mS/cm2)\n"
  "    	ena				(mV)\n"
  "    	ek	  			(mV)\n"
  "    	eca          	(mV)\n"
  "    	cao = 1.8 		(mM)\n"
  "    	cai = 0.0001 	(mM)\n"
  "		cadis = 0.001	(mM)\n"
  "    	dt           	(ms)\n"
  "    	v            	(mV)\n"
  "}\n"
  "\n"
  "STATE { m h n c }\n"
  "\n"
  "INITIAL {\n"
  "	mrates(v)\n"
  "	m = m_inf\n"
  "	hrates(v)\n"
  "	h = h_inf\n"
  "	nrates(v)\n"
  "	n = n_inf\n"
  "	crates(v)\n"
  "	c = c_inf\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ina     	(mA/cm2)\n"
  "    ik     		(mA/cm2)\n"
  "	ik_    		(mA/cm2)\n"
  "    ikca   		(mA/cm2)\n"
  "    ica    		(mA/cm2)\n"
  "    m_inf h_inf n_inf c_inf\n"
  "    m_tau h_tau n_tau c_tau\n"
  "}\n"
  "\n"
  "INITIAL { \n"
  "	mrates(v)\n"
  "	hrates(v)\n"
  "	nrates(v)\n"
  "	crates(v)\n"
  "\n"
  "	m = m_inf\n"
  "	h = h_inf\n"
  "	n = n_inf\n"
  "	c = c_inf\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states METHOD cnexp\n"
  "    	ina = (1e-3) * gnabar * m*m*m*h * (v-ena)\n"
  "    	ik_ = (1e-3) * gkbar * n*n*n*n * (v-ek)\n"
  "    	ikca = (1e-3) * gkcabar * ((cai/cadis) / (1+(cai/cadis))) * (v-ek)\n"
  "		ik = ik_ + ikca\n"
  "    	ica = (1e-3) * gcabar * c*c*c * (v-eca)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    mrates(v)\n"
  "	hrates(v)\n"
  "	nrates(v)\n"
  "	crates(v)\n"
  "\n"
  "	m' = (m_inf-m)/m_tau\n"
  "        h' = (h_inf-h)/h_tau\n"
  "	n' = (n_inf-n)/n_tau\n"
  "	c' = (c_inf-c)/c_tau\n"
  "}\n"
  "\n"
  "PROCEDURE mrates(v) { LOCAL a,b\n"
  "	a = (-2.725*(v+35)) / (exp(-0.1*(v+35))-1)\n"
  "	b = 90.83 * exp(-(v+60)/20)\n"
  "	m_tau = 1 / (a+b)\n"
  "	m_inf = a * m_tau\n"
  "}\n"
  "\n"
  "PROCEDURE hrates(v) { LOCAL a,b\n"
  "	a = 1.817 * exp(-(v+52)/20)\n"
  "	b = 27.25 / (exp(-0.1*(v+22))+1)\n"
  "	h_tau = 1 / (a+b)\n"
  "	h_inf = a * h_tau\n"
  "}\n"
  "\n"
  "PROCEDURE nrates(v) { LOCAL a,b\n"
  "	a = (-0.09575*(v+37)) / ((exp(-0.1*(v+37))-1))\n"
  "	b = 1.915 * exp(-(v+47)/80)\n"
  "	n_tau = 1 / (a+b)\n"
  "	n_inf = a * n_tau\n"
  "}\n"
  "\n"
  "PROCEDURE crates(v) { LOCAL a,b\n"
  "	a = (-1.362*(v+13)) / (exp(-0.1*(v+13))-1)\n"
  "	b = 45.41 * exp(-(v+38)/18)\n"
  "	c_tau = 1 / (a+b)\n"
  "	c_inf = a * c_tau\n"
  "}\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
