
 /**************************************************************
 * Purpose:		   			  	       *
 * This program is a random seed generator for parallel running* 
 **************************************************************/
 
#include "Metropolis.h"


#define RANDMAX 2147483647

float ran2(long *idum) {

	int j;
	long k ;
	static long idum2=123456789;
	static long iy=0;
	static long iv[NTAB];
	float temp;
	
	if( *idum <= 0 ) {					//initialize
		if (-(*idum) < 1) *idum=1;		//be sure to prevent idum = 0
		else *idum = -(*idum);
		for (j=NTAB+7; j >=0; j--) {
			k=(*idum)/IQ1;
			*idum=IA1*(*idum-k*IQ1)-k*IR1;
			if (*idum < 0) *idum += IM1;
			if (j < NTAB) iv[j] = *idum;
		}
		iy=iv[0];
	}
	k = (*idum)/IQ1;
	*idum=IA1*(*idum-k*IQ1)-k*IR1;
	if (*idum < 0) *idum += IM1;
	k=idum2/IQ2;
	idum2=IA2*(idum2-k*IQ2)-k*IR2;
	if (idum2 < 0) idum2 += IM2;
	j=iy/NDIV;
	iy=iv[j]-idum2;
	iv[j] = *idum;
	if (iy<1) iy += IMM1;
	if ((temp=AM*iy) > RNMX) return RNMX;
	else return temp;
}


float drnd(){

        double w;

        w= (float)rand()/RANDMAX;

        return w;
}

//FRA's help with parallelization	
float drnd_r(unsigned int *myseed){


        double w;

        w= (float)rand_r(myseed)/RANDMAX;

        return w;


}
//
