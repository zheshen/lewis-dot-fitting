/*
 *  Met.c
 *  
 *
 *  Created by Mike on Wed Sep 14 2005.
 *  Copyright (c) 2005 __MyCompanyName__. All rights reserved.
 *
 */
/*Metropolis Algorithm*/
/*returns 1 if accept, 0 if reject*/
// modified by Seyit Kale on Dec 6, 2006 
// for reasons of oxygen priority implementation in a computationally inexpensive way
// (MC 19.60.04)


//#include "Common.h"
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
