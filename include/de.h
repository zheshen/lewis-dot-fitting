
#include "Common.h"
#include "Utilities.h"

/*------------------------Globals---------------------------------------*/

long  rnd_uni_init;                 /* serves as a seed for rnd_uni()   */
double c[MAXPOP][MAXDIM+2], d[MAXPOP][MAXDIM+2];
double (*pold)[MAXPOP][MAXDIM+2], (*pnew)[MAXPOP][MAXDIM+2], (*pswap)[MAXPOP][MAXDIM+2];


/*---------Function declarations----------------------------------------*/

void  assignd(int D, double a[], double b[]);
double rnd_uni(long *idum);    /* uniform pseudo random number generator */
double evaluate(int D, double tmp[], long *nfeval); /* obj. funct. */
int PorM();


//Declaration of DE variables that need to be global
double tmp[MAXDIM+2], best[MAXDIM+2], bestit[MAXDIM+2]; /* members  */
double dinit[MAXDIM+2];
double cvar;
int strategy;
int gen, genmax;
int NP;
double inibound_h, inibound_l, inibound_amp;
double F, CR;
int randomstart;
long nfeval;

