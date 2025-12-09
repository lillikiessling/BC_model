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
static constexpr auto number_of_datum_variables = 2;
static constexpr auto number_of_floating_point_variables = 12;
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
 
#define nrn_init _nrn_init__modulator2
#define _nrn_initial _nrn_initial__modulator2
#define nrn_cur _nrn_cur__modulator2
#define _nrn_current _nrn_current__modulator2
#define nrn_jacob _nrn_jacob__modulator2
#define nrn_state _nrn_state__modulator2
#define _net_receive _net_receive__modulator2 
 
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
#define Alpha_Max _ml->template fpfield<0>(_iml)
#define Alpha_Max_columnindex 0
#define Alpha_Delay _ml->template fpfield<1>(_iml)
#define Alpha_Delay_columnindex 1
#define Alpha_tau _ml->template fpfield<2>(_iml)
#define Alpha_tau_columnindex 2
#define DC_Level _ml->template fpfield<3>(_iml)
#define DC_Level_columnindex 3
#define DC_Delay _ml->template fpfield<4>(_iml)
#define DC_Delay_columnindex 4
#define DC_Off _ml->template fpfield<5>(_iml)
#define DC_Off_columnindex 5
#define Ramp_Max _ml->template fpfield<6>(_iml)
#define Ramp_Max_columnindex 6
#define Ramp_Delay _ml->template fpfield<7>(_iml)
#define Ramp_Delay_columnindex 7
#define Ramp_Off _ml->template fpfield<8>(_iml)
#define Ramp_Off_columnindex 8
#define Slope_UP _ml->template fpfield<9>(_iml)
#define Slope_UP_columnindex 9
#define Slope_DOWN _ml->template fpfield<10>(_iml)
#define Slope_DOWN_columnindex 10
#define _g _ml->template fpfield<11>(_iml)
#define _g_columnindex 11
#define _nd_area *_ml->dptr_field<0>(_iml)
 static _nrn_mechanism_cache_instance _ml_real{nullptr};
static _nrn_mechanism_cache_range *_ml{&_ml_real};
static size_t _iml{0};
static Datum *_ppvar;
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_alpha(void*);
 static double _hoc_mramp(void*);
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
 {"alpha", _hoc_alpha},
 {"mramp", _hoc_mramp},
 {0, 0}
};
#define alpha alpha_modulator2
#define mramp mramp_modulator2
 extern double alpha( double );
 extern double mramp( double );
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
#define e e_modulator2
 double e = 0;
#define mod mod_modulator2
 double mod = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"e_modulator2", "mV"},
 {"mod_modulator2", "uM"},
 {"Alpha_Max", "umho"},
 {"Alpha_Delay", "ms"},
 {"Alpha_tau", "ms"},
 {"DC_Level", "uM"},
 {"DC_Delay", "ms"},
 {"DC_Off", "ms"},
 {"Ramp_Max", "uM"},
 {"Ramp_Delay", "ms"},
 {"Ramp_Off", "ms"},
 {"Slope_UP", "ms"},
 {"Slope_DOWN", "ms"},
 {0, 0}
};
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 {"e_modulator2", &e_modulator2},
 {"mod_modulator2", &mod_modulator2},
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
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"modulator2",
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
 0,
 0,
 0,
 0};
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     0, /* Alpha_Max */
     0, /* Alpha_Delay */
     0.1, /* Alpha_tau */
     0, /* DC_Level */
     0, /* DC_Delay */
     0, /* DC_Off */
     500, /* Ramp_Max */
     0, /* Ramp_Delay */
     0, /* Ramp_Off */
     1, /* Slope_UP */
     -0.0001, /* Slope_DOWN */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
  if (nrn_point_prop_) {
    _nrn_mechanism_access_alloc_seq(_prop) = _nrn_mechanism_access_alloc_seq(nrn_point_prop_);
    _ppvar = _nrn_mechanism_access_dparam(nrn_point_prop_);
  } else {
   _ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 12);
 	/*initialize range parameters*/
 	Alpha_Max = _parm_default[0]; /* 0 */
 	Alpha_Delay = _parm_default[1]; /* 0 */
 	Alpha_tau = _parm_default[2]; /* 0.1 */
 	DC_Level = _parm_default[3]; /* 0 */
 	DC_Delay = _parm_default[4]; /* 0 */
 	DC_Off = _parm_default[5]; /* 0 */
 	Ramp_Max = _parm_default[6]; /* 500 */
 	Ramp_Delay = _parm_default[7]; /* 0 */
 	Ramp_Off = _parm_default[8]; /* 0 */
 	Slope_UP = _parm_default[9]; /* 1 */
 	Slope_DOWN = _parm_default[10]; /* -0.0001 */
  }
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 12);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _modulate_newunits_reg() {
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
                                       _nrn_mechanism_field<double>{"Alpha_Max"} /* 0 */,
                                       _nrn_mechanism_field<double>{"Alpha_Delay"} /* 1 */,
                                       _nrn_mechanism_field<double>{"Alpha_tau"} /* 2 */,
                                       _nrn_mechanism_field<double>{"DC_Level"} /* 3 */,
                                       _nrn_mechanism_field<double>{"DC_Delay"} /* 4 */,
                                       _nrn_mechanism_field<double>{"DC_Off"} /* 5 */,
                                       _nrn_mechanism_field<double>{"Ramp_Max"} /* 6 */,
                                       _nrn_mechanism_field<double>{"Ramp_Delay"} /* 7 */,
                                       _nrn_mechanism_field<double>{"Ramp_Off"} /* 8 */,
                                       _nrn_mechanism_field<double>{"Slope_UP"} /* 9 */,
                                       _nrn_mechanism_field<double>{"Slope_DOWN"} /* 10 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 11 */,
                                       _nrn_mechanism_field<double*>{"_nd_area", "area"} /* 0 */,
                                       _nrn_mechanism_field<Point_process*>{"_pntproc", "pntproc"} /* 1 */);
  hoc_register_prop_size(_mechtype, 12, 2);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 modulator2 /Users/lillikiessling/Documents/Stanford/Code/BC_model/Ion_channels/modulate_newunits.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
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
 
double mramp (  double _lx ) {
   double _lmramp;
 
/*VERBATIM*/
double timeramp, x, Dc;
x = _lx;

if (x >= DC_Delay & x < DC_Off)
   Dc = DC_Level;
else
   Dc = 0;

if (x < Ramp_Delay)
   timeramp = Dc;
else
  {
  if (x < Ramp_Off)
   {
    timeramp = Dc + (Slope_UP * (x - Ramp_Delay));
    if (timeramp >= Ramp_Max)
       timeramp = Ramp_Max;
   }
  else
   {
    timeramp = Ramp_Max + (Slope_DOWN * (x - Ramp_Off));
    if (timeramp <= Dc) 
       timeramp = Dc;
   }
  }
return (timeramp);
 
return _lmramp;
 }
 
static double _hoc_mramp(void* _vptr) {
 double _r;
    auto* const _pnt = static_cast<Point_process*>(_vptr);
  auto* const _p = _pnt->_prop;
  if (!_p) {
    hoc_execerror("POINT_PROCESS data instance not valid", NULL);
  }
   _setdata(_p);
 _r =  mramp (  *getarg(1) );
 return(_r);
}

static void initmodel() {
  int _i; double _save;_ninits++;
{

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

static double _nrn_current(double _v){double _current=0.;v=_v;{
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
 {
   mod = mramp ( _threadargscomma_ t ) + ( Alpha_Max * alpha ( _threadargscomma_ ( t - Alpha_Delay ) / Alpha_tau ) ) ;
   }
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/Users/lillikiessling/Documents/Stanford/Code/BC_model/Ion_channels/modulate_newunits.mod";
    const char* nmodl_file_text = 
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	POINT_PROCESS modulator2\n"
  "	RANGE  Alpha_Max, Alpha_Delay, Alpha_tau, DC_Level, DC_Delay, DC_Off, Ramp_Max, Ramp_Delay, Ramp_Off, Slope_UP, Slope_DOWN\n"
  "	GLOBAL mod\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "    (mV) = (millivolt)\n"
  "    (umho) = (micromho)\n"
  "    (uM) = (micro/liter)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "   Alpha_Max=0     (umho)\n"
  "	Alpha_Delay=0 (ms)\n"
  "	Alpha_tau=.1 (ms)\n"
  "	e=0	(mV)\n"
  "	v	(mV)\n"
  "	mod=0	(uM)\n"
  "   DC_Level (uM)\n"
  "   DC_Delay (ms)\n"
  "   DC_Off (ms)\n"
  "   Ramp_Max=500 (uM)\n"
  "   Ramp_Delay=0 (ms)\n"
  "   Ramp_Off=0 (ms)\n"
  "   Slope_UP=1 (ms)\n"
  "   Slope_DOWN=-.0001 (ms)\n"
  "}\n"
  "\n"
  "\n"
  "BREAKPOINT {\n"
  "        mod = mramp(t) + (Alpha_Max * alpha( (t - Alpha_Delay)/Alpha_tau ))\n"
  "}\n"
  "\n"
  "FUNCTION alpha(x) {\n"
  "	if (x < 0 || x > 10) {\n"
  "		alpha = 0\n"
  "	}else{\n"
  "		alpha = x * exp(1 - x)\n"
  "	}\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "FUNCTION mramp(x)\n"
  "{\n"
  "VERBATIM\n"
  "double timeramp, x, Dc;\n"
  "x = _lx;\n"
  "\n"
  "if (x >= DC_Delay & x < DC_Off)\n"
  "   Dc = DC_Level;\n"
  "else\n"
  "   Dc = 0;\n"
  "\n"
  "if (x < Ramp_Delay)\n"
  "   timeramp = Dc;\n"
  "else\n"
  "  {\n"
  "  if (x < Ramp_Off)\n"
  "   {\n"
  "    timeramp = Dc + (Slope_UP * (x - Ramp_Delay));\n"
  "    if (timeramp >= Ramp_Max)\n"
  "       timeramp = Ramp_Max;\n"
  "   }\n"
  "  else\n"
  "   {\n"
  "    timeramp = Ramp_Max + (Slope_DOWN * (x - Ramp_Off));\n"
  "    if (timeramp <= Dc) \n"
  "       timeramp = Dc;\n"
  "   }\n"
  "  }\n"
  "return (timeramp);\n"
  "ENDVERBATIM\n"
  "}\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
