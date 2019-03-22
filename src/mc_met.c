
 /**************************************************************
 * Purpose:		   			  	       *
 * This program implements the MC acceptance criterion. Input  *
 * are energies before and after MC move, temperature and      *
 * random number seed. Output is 1 or 0, indicating accept or  *
 * reject.                                                     * 
 **************************************************************/

#include "Metropolis.h"
#define RANDMAX 2147483647

float ran2(long *);

//FRA's help with parallelization
//v was removed
int Met(double T,  double Uok1, double Uok2, unsigned int *myseed  ){
//int Met(double T, long v, double Uok1, double Uok2, unsigned int *myseed  ){
//int Met(double T, long v, double Uok1, double Uok2){

	int result;
	double w, y;
	
	w = 0;
	y = 1;

	if (Uok2<=Uok1){
		result=1;
	}
	else {
		//w = ran2(&v);
		//FRA v was removed when we changed the random generator
                w = drnd_r(myseed);
		//w = drnd();
		//
		y = exp(-(Uok2-Uok1) * 1.2027E5 / T); //1.671E5 / 1.38936537 
		
		if (w > y){
			result=0;
		}
		else{
			result=1;
		}
	}

	return result;

}
