/*
 * MATLAB Compiler: 6.4 (R2017a)
 * Date: Thu Feb  8 14:15:04 2018
 * Arguments:
 * "-B""macro_default""-B""csharedlib:libgammainc""-W""lib:libgammainc""-T""link
 * :lib""gammainc.m""gamma.m""-v"
 */

#ifndef __libgammainc_h
#define __libgammainc_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_libgammainc
#define PUBLIC_libgammainc_C_API __global
#else
#define PUBLIC_libgammainc_C_API /* No import statement needed. */
#endif

#define LIB_libgammainc_C_API PUBLIC_libgammainc_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libgammainc
#define PUBLIC_libgammainc_C_API __declspec(dllexport)
#else
#define PUBLIC_libgammainc_C_API __declspec(dllimport)
#endif

#define LIB_libgammainc_C_API PUBLIC_libgammainc_C_API


#else

#define LIB_libgammainc_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libgammainc_C_API 
#define LIB_libgammainc_C_API /* No special import/export declaration */
#endif

extern LIB_libgammainc_C_API 
bool MW_CALL_CONV libgammaincInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libgammainc_C_API 
bool MW_CALL_CONV libgammaincInitialize(void);

extern LIB_libgammainc_C_API 
void MW_CALL_CONV libgammaincTerminate(void);



extern LIB_libgammainc_C_API 
void MW_CALL_CONV libgammaincPrintStackTrace(void);

extern LIB_libgammainc_C_API 
bool MW_CALL_CONV mlxGammainc(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libgammainc_C_API 
bool MW_CALL_CONV mlxGamma(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);



extern LIB_libgammainc_C_API bool MW_CALL_CONV mlfGammainc(int nargout, mxArray** a, mxArray* a1, mxArray* a2);

extern LIB_libgammainc_C_API bool MW_CALL_CONV mlfGamma(int nargout, mxArray** a, mxArray* a1);

#ifdef __cplusplus
}
#endif
#endif
