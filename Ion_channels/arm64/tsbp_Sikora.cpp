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
static constexpr auto number_of_datum_variables = 5;
static constexpr auto number_of_floating_point_variables = 11;
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
 
#define nrn_init _nrn_init__tsbp
#define _nrn_initial _nrn_initial__tsbp
#define nrn_cur _nrn_cur__tsbp
#define _nrn_current _nrn_current__tsbp
#define nrn_jacob _nrn_jacob__tsbp
#define nrn_state _nrn_state__tsbp
#define _net_receive _net_receive__tsbp 
#define evaluate_fct evaluate_fct__tsbp 
#define states states__tsbp 
 
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
#define gcabar _ml->template fpfield<0>(_iml)
#define gcabar_columnindex 0
#define c_inf _ml->template fpfield<1>(_iml)
#define c_inf_columnindex 1
#define tau_c _ml->template fpfield<2>(_iml)
#define tau_c_columnindex 2
#define c_exp _ml->template fpfield<3>(_iml)
#define c_exp_columnindex 3
#define c _ml->template fpfield<4>(_iml)
#define c_columnindex 4
#define eca _ml->template fpfield<5>(_iml)
#define eca_columnindex 5
#define cao _ml->template fpfield<6>(_iml)
#define cao_columnindex 6
#define cai _ml->template fpfield<7>(_iml)
#define cai_columnindex 7
#define Dc _ml->template fpfield<8>(_iml)
#define Dc_columnindex 8
#define ica _ml->template fpfield<9>(_iml)
#define ica_columnindex 9
#define _g _ml->template fpfield<10>(_iml)
#define _g_columnindex 10
#define _ion_cai *(_ml->dptr_field<0>(_iml))
#define _p_ion_cai static_cast<neuron::container::data_handle<double>>(_ppvar[0])
#define _ion_eca *(_ml->dptr_field<1>(_iml))
#define _p_ion_eca static_cast<neuron::container::data_handle<double>>(_ppvar[1])
#define _ion_cao *(_ml->dptr_field<2>(_iml))
#define _p_ion_cao static_cast<neuron::container::data_handle<double>>(_ppvar[2])
#define _ion_ica *(_ml->dptr_field<3>(_iml))
#define _p_ion_ica static_cast<neuron::container::data_handle<double>>(_ppvar[3])
#define _ion_dicadv *(_ml->dptr_field<4>(_iml))
 static _nrn_mechanism_cache_instance _ml_real{nullptr};
static _nrn_mechanism_cache_range *_ml{&_ml_real};
static size_t _iml{0};
static Datum *_ppvar;
 static int hoc_nrnpointerindex =  -1;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_evaluate_fct(void);
 static void _hoc_states(void);
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
 {"setdata_tsbp", _hoc_setdata},
 {"evaluate_fct_tsbp", _hoc_evaluate_fct},
 {"states_tsbp", _hoc_states},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_evaluate_fct(Prop*);
 static double _npy_states(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"evaluate_fct", _npy_evaluate_fct},
 {"states", _npy_states},
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
 {"gcabar_tsbp", "mho/cm2"},
 {0, 0}
};
 static double c0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
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
 neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
_ppvar = _nrn_mechanism_access_dparam(_prop);
 Node * _node = _nrn_mechanism_access_node(_prop);
v = _nrn_mechanism_access_voltage(_node);
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
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"tsbp",
 "gcabar_tsbp",
 0,
 "c_inf_tsbp",
 "tau_c_tsbp",
 "c_exp_tsbp",
 0,
 "c_tsbp",
 0,
 0};
 static Symbol* _ca_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     0.002, /* gcabar */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 11);
 	/*initialize range parameters*/
 	gcabar = _parm_default[0]; /* 0.002 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 11);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 1);
 	_ppvar[0] = _nrn_mechanism_get_param_handle(prop_ion, 1); /* cai */
 	_ppvar[1] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* eca */
 	_ppvar[2] = _nrn_mechanism_get_param_handle(prop_ion, 2); /* cao */
 	_ppvar[3] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ica */
 	_ppvar[4] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dicadv */
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _tsbp_Sikora_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("ca", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
         hoc_register_npy_direct(_mechtype, npy_direct_func_proc);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"gcabar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"c_inf"} /* 1 */,
                                       _nrn_mechanism_field<double>{"tau_c"} /* 2 */,
                                       _nrn_mechanism_field<double>{"c_exp"} /* 3 */,
                                       _nrn_mechanism_field<double>{"c"} /* 4 */,
                                       _nrn_mechanism_field<double>{"eca"} /* 5 */,
                                       _nrn_mechanism_field<double>{"cao"} /* 6 */,
                                       _nrn_mechanism_field<double>{"cai"} /* 7 */,
                                       _nrn_mechanism_field<double>{"Dc"} /* 8 */,
                                       _nrn_mechanism_field<double>{"ica"} /* 9 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 10 */,
                                       _nrn_mechanism_field<double*>{"_ion_cai", "ca_ion"} /* 0 */,
                                       _nrn_mechanism_field<double*>{"_ion_eca", "ca_ion"} /* 1 */,
                                       _nrn_mechanism_field<double*>{"_ion_cao", "ca_ion"} /* 2 */,
                                       _nrn_mechanism_field<double*>{"_ion_ica", "ca_ion"} /* 3 */,
                                       _nrn_mechanism_field<double*>{"_ion_dicadv", "ca_ion"} /* 4 */);
  hoc_register_prop_size(_mechtype, 11, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "ca_ion");
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 tsbp /Users/lillikiessling/Documents/Stanford/Code/BC_model/Ion_channels/tsbp_Sikora.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "L-type calcium channel for Tiger Salamander Bipolar cell";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int evaluate_fct(double);
static int states();
 
static int  states (  ) {
   evaluate_fct ( _threadargscomma_ v ) ;
   c = c + c_exp * ( c_inf - c ) ;
   
/*VERBATIM*/
	return 0;
  return 0; }
 
static void _hoc_states(void) {
  double _r;
  
  if(!_prop_id) {
    hoc_execerror("No data for states_tsbp. Requires prior call to setdata_tsbp and that the specified mechanism instance still be in existence.", NULL);
  } else {
    _setdata(_extcall_prop);
  }
   _r = 1.;
 states (  );
 hoc_retpushx(_r);
}
 
static double _npy_states(Prop* _prop) {
    double _r{0.0};
    neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
  _ppvar = _nrn_mechanism_access_dparam(_prop);
 _r = 1.;
 states (  );
 return(_r);
}
 
static int  evaluate_fct (  double _lv ) {
   double _la , _lb ;
 _la = ( - 0.3 * ( _lv + 70.0 ) ) / ( ( exp ( - 0.1 * ( _lv + 70.0 ) ) ) - 1.0 ) ;
   _lb = 10.0 * ( exp ( ( - 1.0 * ( _lv + 38.0 ) ) / 9.0 ) ) ;
   tau_c = 1.0 / ( _la + _lb ) ;
   c_inf = _la * tau_c ;
   c_exp = 1.0 - exp ( - dt / tau_c ) ;
    return 0; }
 
static void _hoc_evaluate_fct(void) {
  double _r;
  
  if(!_prop_id) {
    hoc_execerror("No data for evaluate_fct_tsbp. Requires prior call to setdata_tsbp and that the specified mechanism instance still be in existence.", NULL);
  } else {
    _setdata(_extcall_prop);
  }
   _r = 1.;
 evaluate_fct (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_evaluate_fct(Prop* _prop) {
    double _r{0.0};
    neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
  _ppvar = _nrn_mechanism_access_dparam(_prop);
 _r = 1.;
 evaluate_fct (  *getarg(1) );
 return(_r);
}
 
static int _ode_count(int _type){ hoc_execerror("tsbp", "cannot be used with CVODE"); return 0;}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  c = c0;
 {
   c = 0.0038 ;
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
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   ica = gcabar * c * c * c * ( v - eca ) ;
   }
 _current += ica;

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
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 auto const _g_local = _nrn_current(_v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g_local - _rhs)/.001;
  _ion_ica += ica ;
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
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 { error =  states();
 if(error){
  std_cerr_stream << "at line 57 in file tsbp_Sikora.mod:\n	SOLVE states\n";
  std_cerr_stream << _ml << ' ' << _iml << '\n';
  abort_run(error);
}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/Users/lillikiessling/Documents/Stanford/Code/BC_model/Ion_channels/tsbp_Sikora.mod";
    const char* nmodl_file_text = 
  "TITLE L-type calcium channel for Tiger Salamander Bipolar cell\n"
  ":\n"
  ": Modified from Fohlmeister et al, 1990, Brain Res 510, 343-345\n"
  ":\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX tsbp\n"
  "	USEION ca READ cai, eca, cao WRITE ica\n"
  "	RANGE gcabar\n"
  "	RANGE c_inf\n"
  "	RANGE tau_c\n"
  "	RANGE c_exp\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "UNITS {\n"
  "	(molar) = (1/liter)\n"
  "	(mM) = (millimolar)\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gcabar	= 0.002	(mho/cm2)\n"
  "	eca		(mV)\n"
  "	cao	= 1.8	(mM)\n"
  "	cai     = 0.0001 (mM)\n"
  "	dt              (ms)\n"
  "	v               (mV)\n"
  "\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	c \n"
  "}\n"
  "\n"
  "INITIAL {\n"
  ": The initial values were determined at a resting value of -66.3232 mV in a single-compartment\n"
  ":	c = 0.0016\n"
  ": at -60 mV\n"
  "        c = 0.0038\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ica	(mA/cm2)\n"
  "	c_inf\n"
  "	tau_c\n"
  "	c_exp\n"
  "\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states\n"
  "	ica = gcabar * c*c*c * (v - eca)\n"
  "\n"
  "}\n"
  "\n"
  "PROCEDURE states() {	: exact when v held constant\n"
  "	evaluate_fct(v)\n"
  "	c = c + c_exp * (c_inf - c)\n"
  "\n"
  "	VERBATIM\n"
  "	return 0;\n"
  "	ENDVERBATIM\n"
  "\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "\n"
  "PROCEDURE evaluate_fct(v(mV)) { LOCAL a,b\n"
  "	\n"
  ":CA channel\n"
  ": a = (-0.3 * (v+10)) / ((exp(-0.1*(v+10))) - 1) : for Goldfish Bipolar\n"
  " a = (-0.3 * (v+70)) / ((exp(-0.1*(v+70))) - 1)\n"
  " b = 10 * (exp((-1*(v + 38))/9))\n"
  "\n"
  "\n"
  "	tau_c = 1 / (a + b)\n"
  "	c_inf = a * tau_c\n"
  "\n"
  ": State vars to inifinity\n"
  "	c_exp = 1 - exp(-dt/tau_c)\n"
  "\n"
  "}\n"
  "\n"
  "UNITSON\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
