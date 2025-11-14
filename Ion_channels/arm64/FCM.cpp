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
static constexpr auto number_of_floating_point_variables = 49;
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
#define h16rates h16rates__FCM 
#define h12rates h12rates__FCM 
#define m16rates m16rates__FCM 
#define m12rates m12rates__FCM 
#define n16rates n16rates__FCM 
#define n12rates n12rates__FCM 
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
#define gna12bar _ml->template fpfield<0>(_iml)
#define gna12bar_columnindex 0
#define gna16bar _ml->template fpfield<1>(_iml)
#define gna16bar_columnindex 1
#define gk12bar _ml->template fpfield<2>(_iml)
#define gk12bar_columnindex 2
#define gk16bar _ml->template fpfield<3>(_iml)
#define gk16bar_columnindex 3
#define gcabar _ml->template fpfield<4>(_iml)
#define gcabar_columnindex 4
#define gkcabar _ml->template fpfield<5>(_iml)
#define gkcabar_columnindex 5
#define ina12 _ml->template fpfield<6>(_iml)
#define ina12_columnindex 6
#define ina16 _ml->template fpfield<7>(_iml)
#define ina16_columnindex 7
#define ik12 _ml->template fpfield<8>(_iml)
#define ik12_columnindex 8
#define ik16 _ml->template fpfield<9>(_iml)
#define ik16_columnindex 9
#define ikca _ml->template fpfield<10>(_iml)
#define ikca_columnindex 10
#define m12_inf _ml->template fpfield<11>(_iml)
#define m12_inf_columnindex 11
#define h12_inf _ml->template fpfield<12>(_iml)
#define h12_inf_columnindex 12
#define m16_inf _ml->template fpfield<13>(_iml)
#define m16_inf_columnindex 13
#define h16_inf _ml->template fpfield<14>(_iml)
#define h16_inf_columnindex 14
#define n12_inf _ml->template fpfield<15>(_iml)
#define n12_inf_columnindex 15
#define n16_inf _ml->template fpfield<16>(_iml)
#define n16_inf_columnindex 16
#define c_inf _ml->template fpfield<17>(_iml)
#define c_inf_columnindex 17
#define m12_tau _ml->template fpfield<18>(_iml)
#define m12_tau_columnindex 18
#define h12_tau _ml->template fpfield<19>(_iml)
#define h12_tau_columnindex 19
#define m16_tau _ml->template fpfield<20>(_iml)
#define m16_tau_columnindex 20
#define h16_tau _ml->template fpfield<21>(_iml)
#define h16_tau_columnindex 21
#define n12_tau _ml->template fpfield<22>(_iml)
#define n12_tau_columnindex 22
#define n16_tau _ml->template fpfield<23>(_iml)
#define n16_tau_columnindex 23
#define c_tau _ml->template fpfield<24>(_iml)
#define c_tau_columnindex 24
#define m12 _ml->template fpfield<25>(_iml)
#define m12_columnindex 25
#define h12 _ml->template fpfield<26>(_iml)
#define h12_columnindex 26
#define m16 _ml->template fpfield<27>(_iml)
#define m16_columnindex 27
#define h16 _ml->template fpfield<28>(_iml)
#define h16_columnindex 28
#define n12 _ml->template fpfield<29>(_iml)
#define n12_columnindex 29
#define n16 _ml->template fpfield<30>(_iml)
#define n16_columnindex 30
#define c _ml->template fpfield<31>(_iml)
#define c_columnindex 31
#define ena _ml->template fpfield<32>(_iml)
#define ena_columnindex 32
#define ek _ml->template fpfield<33>(_iml)
#define ek_columnindex 33
#define eca _ml->template fpfield<34>(_iml)
#define eca_columnindex 34
#define cao _ml->template fpfield<35>(_iml)
#define cao_columnindex 35
#define cai _ml->template fpfield<36>(_iml)
#define cai_columnindex 36
#define Dm12 _ml->template fpfield<37>(_iml)
#define Dm12_columnindex 37
#define Dh12 _ml->template fpfield<38>(_iml)
#define Dh12_columnindex 38
#define Dm16 _ml->template fpfield<39>(_iml)
#define Dm16_columnindex 39
#define Dh16 _ml->template fpfield<40>(_iml)
#define Dh16_columnindex 40
#define Dn12 _ml->template fpfield<41>(_iml)
#define Dn12_columnindex 41
#define Dn16 _ml->template fpfield<42>(_iml)
#define Dn16_columnindex 42
#define Dc _ml->template fpfield<43>(_iml)
#define Dc_columnindex 43
#define ina _ml->template fpfield<44>(_iml)
#define ina_columnindex 44
#define ik _ml->template fpfield<45>(_iml)
#define ik_columnindex 45
#define ica _ml->template fpfield<46>(_iml)
#define ica_columnindex 46
#define v _ml->template fpfield<47>(_iml)
#define v_columnindex 47
#define _g _ml->template fpfield<48>(_iml)
#define _g_columnindex 48
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
 static void _hoc_h16rates(void);
 static void _hoc_h12rates(void);
 static void _hoc_m16rates(void);
 static void _hoc_m12rates(void);
 static void _hoc_n16rates(void);
 static void _hoc_n12rates(void);
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
 {"h16rates_FCM", _hoc_h16rates},
 {"h12rates_FCM", _hoc_h12rates},
 {"m16rates_FCM", _hoc_m16rates},
 {"m12rates_FCM", _hoc_m12rates},
 {"n16rates_FCM", _hoc_n16rates},
 {"n12rates_FCM", _hoc_n12rates},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_crates(Prop*);
 static double _npy_h16rates(Prop*);
 static double _npy_h12rates(Prop*);
 static double _npy_m16rates(Prop*);
 static double _npy_m12rates(Prop*);
 static double _npy_n16rates(Prop*);
 static double _npy_n12rates(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"crates", _npy_crates},
 {"h16rates", _npy_h16rates},
 {"h12rates", _npy_h12rates},
 {"m16rates", _npy_m16rates},
 {"m12rates", _npy_m12rates},
 {"n16rates", _npy_n16rates},
 {"n12rates", _npy_n12rates},
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
 {"gna12bar_FCM", "mS/cm2"},
 {"gna16bar_FCM", "mS/cm2"},
 {"gk12bar_FCM", "mS/cm2"},
 {"gk16bar_FCM", "mS/cm2"},
 {"gcabar_FCM", "mS/cm2"},
 {"gkcabar_FCM", "mS/cm2"},
 {"ina12_FCM", "mA/cm2"},
 {"ina16_FCM", "mA/cm2"},
 {"ik12_FCM", "mA/cm2"},
 {"ik16_FCM", "mA/cm2"},
 {"ikca_FCM", "mA/cm2"},
 {0, 0}
};
 static double c0 = 0;
 static double delta_t = 0.01;
 static double h160 = 0;
 static double h120 = 0;
 static double m160 = 0;
 static double m120 = 0;
 static double n160 = 0;
 static double n120 = 0;
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
 "gna12bar_FCM",
 "gna16bar_FCM",
 "gk12bar_FCM",
 "gk16bar_FCM",
 "gcabar_FCM",
 "gkcabar_FCM",
 0,
 "ina12_FCM",
 "ina16_FCM",
 "ik12_FCM",
 "ik16_FCM",
 "ikca_FCM",
 "m12_inf_FCM",
 "h12_inf_FCM",
 "m16_inf_FCM",
 "h16_inf_FCM",
 "n12_inf_FCM",
 "n16_inf_FCM",
 "c_inf_FCM",
 "m12_tau_FCM",
 "h12_tau_FCM",
 "m16_tau_FCM",
 "h16_tau_FCM",
 "n12_tau_FCM",
 "n16_tau_FCM",
 "c_tau_FCM",
 0,
 "m12_FCM",
 "h12_FCM",
 "m16_FCM",
 "h16_FCM",
 "n12_FCM",
 "n16_FCM",
 "c_FCM",
 0,
 0};
 static Symbol* _na_sym;
 static Symbol* _k_sym;
 static Symbol* _ca_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     0, /* gna12bar */
     0, /* gna16bar */
     0, /* gk12bar */
     0, /* gk16bar */
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
    assert(_nrn_mechanism_get_num_vars(_prop) == 49);
 	/*initialize range parameters*/
 	gna12bar = _parm_default[0]; /* 0 */
 	gna16bar = _parm_default[1]; /* 0 */
 	gk12bar = _parm_default[2]; /* 0 */
 	gk16bar = _parm_default[3]; /* 0 */
 	gcabar = _parm_default[4]; /* 0 */
 	gkcabar = _parm_default[5]; /* 0 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 49);
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
                                       _nrn_mechanism_field<double>{"gna12bar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"gna16bar"} /* 1 */,
                                       _nrn_mechanism_field<double>{"gk12bar"} /* 2 */,
                                       _nrn_mechanism_field<double>{"gk16bar"} /* 3 */,
                                       _nrn_mechanism_field<double>{"gcabar"} /* 4 */,
                                       _nrn_mechanism_field<double>{"gkcabar"} /* 5 */,
                                       _nrn_mechanism_field<double>{"ina12"} /* 6 */,
                                       _nrn_mechanism_field<double>{"ina16"} /* 7 */,
                                       _nrn_mechanism_field<double>{"ik12"} /* 8 */,
                                       _nrn_mechanism_field<double>{"ik16"} /* 9 */,
                                       _nrn_mechanism_field<double>{"ikca"} /* 10 */,
                                       _nrn_mechanism_field<double>{"m12_inf"} /* 11 */,
                                       _nrn_mechanism_field<double>{"h12_inf"} /* 12 */,
                                       _nrn_mechanism_field<double>{"m16_inf"} /* 13 */,
                                       _nrn_mechanism_field<double>{"h16_inf"} /* 14 */,
                                       _nrn_mechanism_field<double>{"n12_inf"} /* 15 */,
                                       _nrn_mechanism_field<double>{"n16_inf"} /* 16 */,
                                       _nrn_mechanism_field<double>{"c_inf"} /* 17 */,
                                       _nrn_mechanism_field<double>{"m12_tau"} /* 18 */,
                                       _nrn_mechanism_field<double>{"h12_tau"} /* 19 */,
                                       _nrn_mechanism_field<double>{"m16_tau"} /* 20 */,
                                       _nrn_mechanism_field<double>{"h16_tau"} /* 21 */,
                                       _nrn_mechanism_field<double>{"n12_tau"} /* 22 */,
                                       _nrn_mechanism_field<double>{"n16_tau"} /* 23 */,
                                       _nrn_mechanism_field<double>{"c_tau"} /* 24 */,
                                       _nrn_mechanism_field<double>{"m12"} /* 25 */,
                                       _nrn_mechanism_field<double>{"h12"} /* 26 */,
                                       _nrn_mechanism_field<double>{"m16"} /* 27 */,
                                       _nrn_mechanism_field<double>{"h16"} /* 28 */,
                                       _nrn_mechanism_field<double>{"n12"} /* 29 */,
                                       _nrn_mechanism_field<double>{"n16"} /* 30 */,
                                       _nrn_mechanism_field<double>{"c"} /* 31 */,
                                       _nrn_mechanism_field<double>{"ena"} /* 32 */,
                                       _nrn_mechanism_field<double>{"ek"} /* 33 */,
                                       _nrn_mechanism_field<double>{"eca"} /* 34 */,
                                       _nrn_mechanism_field<double>{"cao"} /* 35 */,
                                       _nrn_mechanism_field<double>{"cai"} /* 36 */,
                                       _nrn_mechanism_field<double>{"Dm12"} /* 37 */,
                                       _nrn_mechanism_field<double>{"Dh12"} /* 38 */,
                                       _nrn_mechanism_field<double>{"Dm16"} /* 39 */,
                                       _nrn_mechanism_field<double>{"Dh16"} /* 40 */,
                                       _nrn_mechanism_field<double>{"Dn12"} /* 41 */,
                                       _nrn_mechanism_field<double>{"Dn16"} /* 42 */,
                                       _nrn_mechanism_field<double>{"Dc"} /* 43 */,
                                       _nrn_mechanism_field<double>{"ina"} /* 44 */,
                                       _nrn_mechanism_field<double>{"ik"} /* 45 */,
                                       _nrn_mechanism_field<double>{"ica"} /* 46 */,
                                       _nrn_mechanism_field<double>{"v"} /* 47 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 48 */,
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
  hoc_register_prop_size(_mechtype, 49, 12);
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
static int h16rates(_internalthreadargsprotocomma_ double);
static int h12rates(_internalthreadargsprotocomma_ double);
static int m16rates(_internalthreadargsprotocomma_ double);
static int m12rates(_internalthreadargsprotocomma_ double);
static int n16rates(_internalthreadargsprotocomma_ double);
static int n12rates(_internalthreadargsprotocomma_ double);
 
static int _ode_spec1(_internalthreadargsproto_);
/*static int _ode_matsol1(_internalthreadargsproto_);*/
 static neuron::container::field_index _slist1[7], _dlist1[7];
 static int states(_internalthreadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (_internalthreadargsproto_) {int _reset = 0; {
   m12rates ( _threadargscomma_ v ) ;
   h12rates ( _threadargscomma_ v ) ;
   m16rates ( _threadargscomma_ v ) ;
   h16rates ( _threadargscomma_ v ) ;
   n12rates ( _threadargscomma_ v ) ;
   n16rates ( _threadargscomma_ v ) ;
   crates ( _threadargscomma_ v ) ;
   Dm12 = ( m12_inf - m12 ) / m12_tau ;
   Dh12 = ( h12_inf - h12 ) / h12_tau ;
   Dm16 = ( m16_inf - m16 ) / m16_tau ;
   Dh16 = ( h16_inf - h16 ) / h16_tau ;
   Dn12 = ( n12_inf - n12 ) / n12_tau ;
   Dn16 = ( n16_inf - n16 ) / n16_tau ;
   Dc = ( c_inf - c ) / c_tau ;
   }
 return _reset;
}
 static int _ode_matsol1 (_internalthreadargsproto_) {
 m12rates ( _threadargscomma_ v ) ;
 h12rates ( _threadargscomma_ v ) ;
 m16rates ( _threadargscomma_ v ) ;
 h16rates ( _threadargscomma_ v ) ;
 n12rates ( _threadargscomma_ v ) ;
 n16rates ( _threadargscomma_ v ) ;
 crates ( _threadargscomma_ v ) ;
 Dm12 = Dm12  / (1. - dt*( ( ( ( - 1.0 ) ) ) / m12_tau )) ;
 Dh12 = Dh12  / (1. - dt*( ( ( ( - 1.0 ) ) ) / h12_tau )) ;
 Dm16 = Dm16  / (1. - dt*( ( ( ( - 1.0 ) ) ) / m16_tau )) ;
 Dh16 = Dh16  / (1. - dt*( ( ( ( - 1.0 ) ) ) / h16_tau )) ;
 Dn12 = Dn12  / (1. - dt*( ( ( ( - 1.0 ) ) ) / n12_tau )) ;
 Dn16 = Dn16  / (1. - dt*( ( ( ( - 1.0 ) ) ) / n16_tau )) ;
 Dc = Dc  / (1. - dt*( ( ( ( - 1.0 ) ) ) / c_tau )) ;
  return 0;
}
 /*END CVODE*/
 static int states (_internalthreadargsproto_) { {
   m12rates ( _threadargscomma_ v ) ;
   h12rates ( _threadargscomma_ v ) ;
   m16rates ( _threadargscomma_ v ) ;
   h16rates ( _threadargscomma_ v ) ;
   n12rates ( _threadargscomma_ v ) ;
   n16rates ( _threadargscomma_ v ) ;
   crates ( _threadargscomma_ v ) ;
    m12 = m12 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / m12_tau)))*(- ( ( ( m12_inf ) ) / m12_tau ) / ( ( ( ( - 1.0 ) ) ) / m12_tau ) - m12) ;
    h12 = h12 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / h12_tau)))*(- ( ( ( h12_inf ) ) / h12_tau ) / ( ( ( ( - 1.0 ) ) ) / h12_tau ) - h12) ;
    m16 = m16 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / m16_tau)))*(- ( ( ( m16_inf ) ) / m16_tau ) / ( ( ( ( - 1.0 ) ) ) / m16_tau ) - m16) ;
    h16 = h16 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / h16_tau)))*(- ( ( ( h16_inf ) ) / h16_tau ) / ( ( ( ( - 1.0 ) ) ) / h16_tau ) - h16) ;
    n12 = n12 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / n12_tau)))*(- ( ( ( n12_inf ) ) / n12_tau ) / ( ( ( ( - 1.0 ) ) ) / n12_tau ) - n12) ;
    n16 = n16 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / n16_tau)))*(- ( ( ( n16_inf ) ) / n16_tau ) / ( ( ( ( - 1.0 ) ) ) / n16_tau ) - n16) ;
    c = c + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / c_tau)))*(- ( ( ( c_inf ) ) / c_tau ) / ( ( ( ( - 1.0 ) ) ) / c_tau ) - c) ;
   }
  return 0;
}
 
static int  m12rates ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = ( - 2.725 * ( _lv + 35.0 ) ) / ( exp ( - 0.1 * ( _lv + 35.0 ) ) - 1.0 ) ;
   _lb = 90.83 * exp ( - ( _lv + 60.0 ) / 20.0 ) ;
   m12_tau = 1.0 / ( _la + _lb ) ;
   m12_inf = _la * m12_tau ;
    return 0; }
 
static void _hoc_m12rates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for m12rates_FCM. Requires prior call to setdata_FCM and that the specified mechanism instance still be in existence.", NULL);
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
 m12rates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_m12rates(Prop* _prop) {
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
 m12rates ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  h12rates ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = 1.817 * exp ( - ( _lv + 52.0 ) / 20.0 ) ;
   _lb = 27.25 / ( exp ( - 0.1 * ( _lv + 22.0 ) ) + 1.0 ) ;
   h12_tau = 1.0 / ( _la + _lb ) ;
   h12_inf = _la * h12_tau ;
    return 0; }
 
static void _hoc_h12rates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for h12rates_FCM. Requires prior call to setdata_FCM and that the specified mechanism instance still be in existence.", NULL);
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
 h12rates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_h12rates(Prop* _prop) {
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
 h12rates ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  m16rates ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = ( - 2.725 * ( _lv + 41.0 ) ) / ( exp ( - 0.1 * ( _lv + 41.0 ) ) - 1.0 ) ;
   _lb = 90.83 * exp ( - ( _lv + 66.0 ) / 15.0 ) ;
   m16_tau = 1.0 / ( _la + _lb ) ;
   m16_inf = _la * m16_tau ;
    return 0; }
 
static void _hoc_m16rates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for m16rates_FCM. Requires prior call to setdata_FCM and that the specified mechanism instance still be in existence.", NULL);
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
 m16rates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_m16rates(Prop* _prop) {
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
 m16rates ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  h16rates ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = 1.817 * exp ( - ( _lv + 58.0 ) / 20.0 ) ;
   _lb = 27.25 / ( exp ( - 0.1 * ( _lv + 28.0 ) ) + 1.0 ) ;
   h16_tau = 1.0 / ( _la + _lb ) ;
   h16_inf = _la * h16_tau ;
    return 0; }
 
static void _hoc_h16rates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for h16rates_FCM. Requires prior call to setdata_FCM and that the specified mechanism instance still be in existence.", NULL);
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
 h16rates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_h16rates(Prop* _prop) {
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
 h16rates ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  n12rates ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = ( - 0.09575 * ( _lv + 37.0 ) ) / ( ( exp ( - 0.1 * ( _lv + 37.0 ) ) - 1.0 ) ) ;
   _lb = 1.915 * exp ( - ( _lv + 47.0 ) / 80.0 ) ;
   n12_tau = 1.0 / ( _la + _lb ) ;
   n12_inf = _la * n12_tau ;
    return 0; }
 
static void _hoc_n12rates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for n12rates_FCM. Requires prior call to setdata_FCM and that the specified mechanism instance still be in existence.", NULL);
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
 n12rates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_n12rates(Prop* _prop) {
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
 n12rates ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  n16rates ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = ( - 0.09575 * ( _lv + 43.0 ) ) / ( ( exp ( - 0.1 * ( _lv + 43.0 ) ) - 1.0 ) ) ;
   _lb = 1.915 * exp ( - ( _lv + 53.0 ) / 80.0 ) ;
   n16_tau = 1.0 / ( _la + _lb ) ;
   n16_inf = _la * n16_tau ;
    return 0; }
 
static void _hoc_n16rates(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for n16rates_FCM. Requires prior call to setdata_FCM and that the specified mechanism instance still be in existence.", NULL);
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
 n16rates ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_n16rates(Prop* _prop) {
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
 n16rates ( _threadargscomma_ *getarg(1) );
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
 
static int _ode_count(int _type){ return 7;}
 
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
  for (int _i=0; _i < 7; ++_i) {
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
  h16 = h160;
  h12 = h120;
  m16 = m160;
  m12 = m120;
  n16 = n160;
  n12 = n120;
 {
   m12rates ( _threadargscomma_ v ) ;
   m12 = m12_inf ;
   h12rates ( _threadargscomma_ v ) ;
   h12 = h12_inf ;
   m16rates ( _threadargscomma_ v ) ;
   m16 = m16_inf ;
   h16rates ( _threadargscomma_ v ) ;
   h16 = h16_inf ;
   n12rates ( _threadargscomma_ v ) ;
   n12 = n12_inf ;
   n16rates ( _threadargscomma_ v ) ;
   n16 = n16_inf ;
   crates ( _threadargscomma_ v ) ;
   c = c_inf ;
   }
 {
   m12rates ( _threadargscomma_ v ) ;
   h12rates ( _threadargscomma_ v ) ;
   m16rates ( _threadargscomma_ v ) ;
   h16rates ( _threadargscomma_ v ) ;
   n12rates ( _threadargscomma_ v ) ;
   n16rates ( _threadargscomma_ v ) ;
   crates ( _threadargscomma_ v ) ;
   m12 = m12_inf ;
   h12 = h12_inf ;
   m16 = m16_inf ;
   h16 = h16_inf ;
   n12 = n12_inf ;
   n16 = n16_inf ;
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
   ina12 = ( 1e-3 ) * gna12bar * m12 * m12 * m12 * h12 * ( v - ena ) ;
   ina16 = ( 1e-3 ) * gna16bar * m16 * m16 * m16 * h16 * ( v - ena ) ;
   ina = ina12 + ina16 ;
   ik12 = ( 1e-3 ) * gk12bar * n12 * n12 * n12 * n12 * ( v - ek ) ;
   ik16 = ( 1e-3 ) * gk16bar * n16 * n16 * n16 * n16 * ( v - ek ) ;
   ikca = ( 1e-3 ) * gkcabar * ( ( cai / cadis ) / ( 1.0 + ( cai / cadis ) ) ) * ( v - ek ) ;
   ik = ik12 + ik16 + ikca ;
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
 _slist1[0] = {m12_columnindex, 0};  _dlist1[0] = {Dm12_columnindex, 0};
 _slist1[1] = {h12_columnindex, 0};  _dlist1[1] = {Dh12_columnindex, 0};
 _slist1[2] = {m16_columnindex, 0};  _dlist1[2] = {Dm16_columnindex, 0};
 _slist1[3] = {h16_columnindex, 0};  _dlist1[3] = {Dh16_columnindex, 0};
 _slist1[4] = {n12_columnindex, 0};  _dlist1[4] = {Dn12_columnindex, 0};
 _slist1[5] = {n16_columnindex, 0};  _dlist1[5] = {Dn16_columnindex, 0};
 _slist1[6] = {c_columnindex, 0};  _dlist1[6] = {Dc_columnindex, 0};
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
  "    	RANGE gna12bar, gna16bar, gk12bar, gk16bar, gcabar, gkcabar\n"
  "    	RANGE m12_inf, h12_inf, m16_inf, h16_inf, n12_inf, n16_inf, c_inf\n"
  "    	RANGE m12_tau, h12_tau, m16_tau, h16_tau, n12_tau, n16_tau, c_tau\n"
  "    	RANGE ik12, ik16, ikca\n"
  "	RANGE ina12, ina16\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "    	(molar) = 	(1/liter)\n"
  "    	(mM) = 		(millimolar)\n"
  "    	(mA) = 		(milliamp)\n"
  "    	(mV) = 		(millivolt)\n"
  "	(mS) = 		(millisiemens)\n"
  "\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    	gna12bar		(mS/cm2)\n"
  "	gna16bar		(mS/cm2)\n"
  "    	gk12bar 		(mS/cm2)\n"
  "	gk16bar 		(mS/cm2)\n"
  "    	gcabar   	(mS/cm2)\n"
  "    	gkcabar 		(mS/cm2)\n"
  "    	ena		(mV)\n"
  "    	ek	  	(mV)\n"
  "    	eca          	(mV)\n"
  "    	cao = 1.8 	(mM)\n"
  "    	cai = 0.0001 	(mM)\n"
  "	cadis = 0.001	(mM)\n"
  "    	dt           	(ms)\n"
  "    	v            	(mV)\n"
  "}\n"
  "\n"
  "STATE { m12 h12 m16 h16 n12 n16 c }\n"
  "\n"
  "INITIAL {\n"
  "	m12rates(v)\n"
  "	m12 = m12_inf\n"
  "	h12rates(v)\n"
  "	h12 = h12_inf\n"
  "	m16rates(v)\n"
  "	m16 = m16_inf\n"
  "	h16rates(v)\n"
  "	h16 = h16_inf\n"
  "	n12rates(v)\n"
  "	n12 = n12_inf\n"
  "	n16rates(v)\n"
  "	n16 = n16_inf\n"
  "	crates(v)\n"
  "	c = c_inf\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ina     		(mA/cm2)\n"
  "    	ina12   		(mA/cm2)\n"
  "	ina16   		(mA/cm2)\n"
  "    	ik     		(mA/cm2)\n"
  "	ik12   		(mA/cm2)\n"
  "	ik16   		(mA/cm2)\n"
  "    	ikca   		(mA/cm2)\n"
  "    	ica    		(mA/cm2)\n"
  "    	m12_inf h12_inf m16_inf h16_inf n12_inf n16_inf c_inf\n"
  "    	m12_tau h12_tau m16_tau h16_tau n12_tau n16_tau c_tau\n"
  "}\n"
  "\n"
  "INITIAL { \n"
  "	m12rates(v)\n"
  "	h12rates(v)\n"
  "	m16rates(v)\n"
  "	h16rates(v)\n"
  "	n12rates(v)\n"
  "	n16rates(v)\n"
  "	crates(v)\n"
  "\n"
  "	m12 = m12_inf\n"
  "	h12 = h12_inf\n"
  "	m16 = m16_inf\n"
  "	h16 = h16_inf\n"
  "	n12 = n12_inf\n"
  "	n16 = n16_inf\n"
  "	c = c_inf\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states METHOD cnexp\n"
  "    	ina12 = (1e-3) * gna12bar * m12*m12*m12*h12 * (v-ena)\n"
  "	ina16 = (1e-3) * gna16bar * m16*m16*m16*h16 * (v-ena)\n"
  "	ina = ina12 + ina16\n"
  "    	ik12 = (1e-3) * gk12bar * n12*n12*n12*n12 * (v-ek)\n"
  "	ik16 = (1e-3) * gk16bar * n16*n16*n16*n16 * (v-ek)\n"
  "    	ikca = (1e-3) * gkcabar * ((cai/cadis) / (1+(cai/cadis))) * (v-ek)\n"
  "	ik = ik12 + ik16 + ikca\n"
  "    	ica = (1e-3) * gcabar * c*c*c * (v-eca)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    	m12rates(v)\n"
  "	h12rates(v)\n"
  "	m16rates(v)\n"
  "	h16rates(v)\n"
  "	n12rates(v)\n"
  "	n16rates(v)\n"
  "	crates(v)\n"
  "\n"
  "	m12' = (m12_inf-m12)/m12_tau\n"
  "        	h12' = (h12_inf-h12)/h12_tau\n"
  "	m16' = (m16_inf-m16)/m16_tau\n"
  "        	h16' = (h16_inf-h16)/h16_tau\n"
  "	n12' = (n12_inf-n12)/n12_tau\n"
  "	n16' = (n16_inf-n16)/n16_tau\n"
  "	c' = (c_inf-c)/c_tau\n"
  "}\n"
  "\n"
  "PROCEDURE m12rates(v) { LOCAL a,b\n"
  "	a = (-2.725*(v+35)) / (exp(-0.1*(v+35))-1)\n"
  "	b = 90.83 * exp(-(v+60)/20)\n"
  "	m12_tau = 1 / (a+b)\n"
  "	m12_inf = a * m12_tau\n"
  "}\n"
  "\n"
  "PROCEDURE h12rates(v) { LOCAL a,b\n"
  "	a = 1.817 * exp(-(v+52)/20)\n"
  "	b = 27.25 / (exp(-0.1*(v+22))+1)\n"
  "	h12_tau = 1 / (a+b)\n"
  "	h12_inf = a * h12_tau\n"
  "}\n"
  "\n"
  "PROCEDURE m16rates(v) { LOCAL a,b\n"
  "	a = (-2.725*(v+41)) / (exp(-0.1*(v+41))-1)\n"
  "	b = 90.83 * exp(-(v+66)/15)\n"
  "	m16_tau = 1 / (a+b)\n"
  "	m16_inf = a * m16_tau\n"
  "}\n"
  "\n"
  "PROCEDURE h16rates(v) { LOCAL a,b\n"
  "	a = 1.817 * exp(-(v+58)/20)\n"
  "	b = 27.25 / (exp(-0.1*(v+28))+1)\n"
  "	h16_tau = 1 / (a+b)\n"
  "	h16_inf = a * h16_tau\n"
  "}\n"
  "\n"
  "PROCEDURE n12rates(v) { LOCAL a,b\n"
  "	a = (-0.09575*(v+37)) / ((exp(-0.1*(v+37))-1))\n"
  "	b = 1.915 * exp(-(v+47)/80)\n"
  "	n12_tau = 1 / (a+b)\n"
  "	n12_inf = a * n12_tau\n"
  "}\n"
  "\n"
  "PROCEDURE n16rates(v) { LOCAL a,b\n"
  "	a = (-0.09575*(v+43)) / ((exp(-0.1*(v+43))-1))\n"
  "	b = 1.915 * exp(-(v+53)/80)\n"
  "	n16_tau = 1 / (a+b)\n"
  "	n16_inf = a * n16_tau\n"
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
