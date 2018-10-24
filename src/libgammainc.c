/*
 * MATLAB Compiler: 6.4 (R2017a)
 * Date: Thu Feb  8 14:15:04 2018
 * Arguments:
 * "-B""macro_default""-B""csharedlib:libgammainc""-W""lib:libgammainc""-T""link
 * :lib""gammainc.m""gamma.m""-v"
 */

#include <stdio.h>
#define EXPORTING_libgammainc 1
#include "libgammainc.h"

static HMCRINSTANCE _mcr_inst = NULL;


#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libgammainc_C_API
#define LIB_libgammainc_C_API /* No special import/export declaration */
#endif

LIB_libgammainc_C_API 
bool MW_CALL_CONV libgammaincInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream((void *)(libgammaincInitializeWithHandlers));
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(   &_mcr_inst,
                                                                error_handler, 
                                                                print_handler,
                                                                ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
  return true;
}

LIB_libgammainc_C_API 
bool MW_CALL_CONV libgammaincInitialize(void)
{
  return libgammaincInitializeWithHandlers(mclDefaultErrorHandler, 
                                           mclDefaultPrintHandler);
}

LIB_libgammainc_C_API 
void MW_CALL_CONV libgammaincTerminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

LIB_libgammainc_C_API 
void MW_CALL_CONV libgammaincPrintStackTrace(void) 
{
  char** stackTrace;
  int stackDepth = mclGetStackTrace(&stackTrace);
  int i;
  for(i=0; i<stackDepth; i++)
  {
    mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
    mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
  }
  mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_libgammainc_C_API 
bool MW_CALL_CONV mlxGammainc(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "gammainc", nlhs, plhs, nrhs, prhs);
}

LIB_libgammainc_C_API 
bool MW_CALL_CONV mlxGamma(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "gamma", nlhs, plhs, nrhs, prhs);
}

LIB_libgammainc_C_API 
bool MW_CALL_CONV mlfGammainc(int nargout, mxArray** a, mxArray* a1, mxArray* a2)
{
  return mclMlfFeval(_mcr_inst, "gammainc", nargout, 1, 2, a, a1, a2);
}

LIB_libgammainc_C_API 
bool MW_CALL_CONV mlfGamma(int nargout, mxArray** a, mxArray* a1)
{
  return mclMlfFeval(_mcr_inst, "gamma", nargout, 1, 1, a, a1);
}

