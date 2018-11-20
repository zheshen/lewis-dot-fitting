/*
 *  status.c
 WS 26.10.3
 Rewritten by Seyit
 *	
 *	Edited by Mason on 1-15-2009 (added OpenMP)
 *  Created by Mike on 1/20/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include "Common.h" 
#include "Lowermain.h"
#include <omp.h>

//declaration of status.c functions
void assignpar();

//beginning of status.c
double status(){

	double term;
	extern double wspinThermo;
	extern double dlewis[];
	extern int debug;
	int total = 799;
	double z_arr[total];
	double w_arr[total];
	int i;

	for (i = 0; i < total; i++) {
		z_arr[i]=0.0;
		w_arr[i]=0.0;
	}
	extern double totaldev, totalweight, zStructfinal, devOHydrideStruct, devNCOHydrideStruct, devspinThermo;

	assignpar();

//weighted sum of deviations
//#pragma omp parallel num_threads(8) private(term)
#pragma omp parallel private(term)

	{
#pragma omp sections 
		{

//List the larger molecules that take longer first
#pragma omp section
                        {
                                if (wspinO3) {
                                        term = lowermain(O3_linnett); //397
                                        z_arr[397] = wspinO3 * term;
                                        w_arr[397] = wspinO3;}
                        }
#pragma omp section
                        {
                                if (wspinO3trp) {
                                        term = lowermain(O3trp_linnett); //398
                                        z_arr[398] = wspinO3 * term;
                                        w_arr[398] = wspinO3trp;}
                        }
#pragma omp section
                        {
                                if(wspinF2_trplt){
                                        term = lowermainspinF2_trplt();//366
                                        z_arr[366] = wspinF2_trplt * term;
                                        w_arr[366] = wspinF2_trplt;}
                        }
#pragma omp section
                        {
                                if(wspinF2_snglt){
                                        term = lowermainspinF2_snglt();//367
                                        z_arr[367] = wspinF2_snglt * term;
                                        w_arr[367] = wspinF2_snglt;}
                        }
#pragma omp section
                        {
                                if(wspinCl2_trplt){
                                        term = lowermainspinCl2_trplt();//368
                                        z_arr[368] = wspinCl2_trplt * term;
                                        w_arr[368] = wspinCl2_trplt;}
                        }
#pragma omp section
                        {
                                if(wspinCl2_snglt){
                                        term = lowermainspinCl2_snglt();//369
                                        z_arr[369] = wspinCl2_snglt * term;
                                        w_arr[369] = wspinCl2_snglt;}
                        }
//#pragma omp section
//			{
//				if (wspinO2_2v) {
//					term = lowermainspinO2_2v(); //225
//					z_arr[225] = wspinO2_2v * term;
//					w_arr[225] = wspinO2_2v;
//				}
//			}
#pragma omp section
			{
				if (wspinO2_2) {
					term = lowermainspinO2_2(); //218
					z_arr[218] = wspinO2_2 * term;
					w_arr[218] = wspinO2_2;
				}
			}
#pragma omp section
			{
				if (wspinO2_1) {
					term = lowermainspinO2_1(); //217
					z_arr[217] = wspinO2_1 * term;
					w_arr[217] = wspinO2_1;
				}
			}
#pragma omp section
                        {
                                if (wspinO2) {
                                        term = lowermainspinO2(); //216
                                        z_arr[216] = wspinO2 * term;
                                        w_arr[216] = wspinO2;}
                        }
#pragma omp section
                        {
                                if (wspinO2dia) {
                                        term = lowermainspinO2dia();//232
                                        z_arr[232] = wspinO2dia * term;
                                        w_arr[232] = wspinO2dia;}
                       }
#pragma omp section
                       {
                                if (wspinO2qnt) {
                                        term = lowermainspinO2qnt();//396
                                        z_arr[396] = wspinO2qnt * term;
                                        w_arr[396] = wspinO2qnt;}
                        }
#pragma omp section
                        {
                                if(wspinS2_trplt){
                                        term = lowermainspinS2_trplt();//364
                                        z_arr[364] = wspinS2_trplt * term;
                                        w_arr[364] = wspinS2_trplt;}
                        }
#pragma omp section
                        {
                                if(wspinS2_snglt){
                                        term = lowermainspinS2_snglt();//365
                                        z_arr[365] = wspinS2_snglt * term;
                                        w_arr[365] = wspinS2_snglt;}
                        }
#pragma omp section
                        {
                                if(wspinN2_trplt){
                                        term = lowermainspinN2_trplt();//362
                                        z_arr[362] = wspinN2_trplt * term;
                                        w_arr[362] = wspinN2_trplt;}
                        }
#pragma omp section
                        {
                                if(wspinN2_snglt){
                                        term = lowermainspinN2_snglt();//363
                                        z_arr[363] = wspinN2_snglt * term;
                                        w_arr[363] = wspinN2_snglt;}
                        }
#pragma omp section
                        {
                                if(wspinP2_trplt){
                                        term = lowermainspinP2_trplt();//370
                                        z_arr[370] = wspinP2_trplt * term;
                                        w_arr[370] = wspinP2_trplt;}
                        }
#pragma omp section
                        {
                                if(wspinP2_snglt){
                                        term = lowermainspinP2_snglt();//371
                                        z_arr[371] = wspinP2_snglt * term;
                                        w_arr[371] = wspinP2_snglt;}
                        }
#pragma omp section
                        {
                                if(wspinC2_trplt){
                                        term = lowermainspinC2_trplt();//358
                                        z_arr[358] = wspinC2_trplt * term;
                                        w_arr[358] = wspinC2_trplt;}
                        }
#pragma omp section
                        {
                                if(wspinC2_snglt){
                                        term = lowermainspinC2_snglt();//359
                                        z_arr[359] = wspinC2_snglt * term;
                                        w_arr[359] = wspinC2_snglt;}
                        }
#pragma omp section
                        {
                                if(wspinSi2_trplt){
                                        term = lowermainspinSi2_trplt();//360
                                        z_arr[360] = wspinSi2_trplt * term;
                                        w_arr[360] = wspinSi2_trplt;}
                        }
#pragma omp section
                        {
                                if(wspinSi2_snglt){
                                        term = lowermainspinSi2_snglt();//361
                                        z_arr[361] = wspinSi2_snglt * term;
                                        w_arr[361] = wspinSi2_snglt;}
                        }
#pragma omp section
                        {
                                if(wspinB2_trplt){
                                        term = lowermainspinB2_trplt();//356
                                        z_arr[356] = wspinB2_trplt * term;
                                        w_arr[356] = wspinB2_trplt;}
                        }
#pragma omp section
                        {
                                if(wspinB2_snglt){
                                        term = lowermainspinB2_snglt();//357
                                        z_arr[357] = wspinB2_snglt * term;
                                        w_arr[357] = wspinB2_snglt;}
                        }
#pragma omp section
                        {
                                if(wspinAl2_trplt){
                                        term = lowermainspinAl2_trplt();//354
                                        z_arr[354] = wspinAl2_trplt * term;
                                        w_arr[354] = wspinAl2_trplt;}
                        }

#pragma omp section
                        {
                                if(wspinAl2_snglt){
                                        term = lowermainspinAl2_snglt();//355
                                        z_arr[355] = wspinAl2_snglt * term;
                                        w_arr[355] = wspinAl2_snglt;}
                        }

#pragma omp section
			{
				if(wspinZnneutrl){
					term = lowermain(Znneutrl);
					z_arr[707] = wspinZnneutrl * term;
					w_arr[707] = wspinZnneutrl;}
			}
#pragma omp section
			{
				if(wspinZnneutrlex){
					term = lowermain(Znneutrlex);
					z_arr[708] = wspinZnneutrlex * term;
					w_arr[708] = wspinZnneutrlex;}
			}
#pragma omp section
			{
				if(wspinZnneutrlex){
					term = lowermain(Znneutrlex2);
					z_arr[708] += wspinZnneutrlex * term;
					w_arr[708] += wspinZnneutrlex;}
			}
#pragma omp section
			{
				if(wspinZnplus1){
					term = lowermain(Znplus1);
					z_arr[705] = wspinZnplus1 * term;
					w_arr[705] = wspinZnplus1;}
			}
#pragma omp section
			{
				if(wspinZnplus1ex){
					term = lowermain(Znplus1ex);
					z_arr[706] = wspinZnplus1ex * term;
					w_arr[706] = wspinZnplus1ex;}
			}
#pragma omp section
			{
				if(wspinZnplus1ex){
					term = lowermain(Znplus1ex2);
					z_arr[706] += wspinZnplus1ex * term;
					w_arr[706] += wspinZnplus1ex;}
			}
#pragma omp section
			{
				if(wspinZnplus2){
					term = lowermain(Znplus2);
					z_arr[516] = wspinZnplus2 * term;
					w_arr[516] = wspinZnplus2;}
			}
#pragma omp section
			{
				if(wspinZnplus2ex){
					term = lowermain(Znplus2ex);
					z_arr[517] = wspinZnplus2ex * term;
					w_arr[517] = wspinZnplus2ex;}
			}
#pragma omp section
			{
				if(wspinZnplus2ex){
					term = lowermain(Znplus2ex2);
					z_arr[517] += wspinZnplus2ex * term;
					w_arr[517] += wspinZnplus2ex;}
			}
#pragma omp section
			{
				if(wspinZnplus3){
					term = lowermain(Znplus3);
					z_arr[514] = wspinZnplus3 * term;
					w_arr[514] = wspinZnplus3;}
			}
#pragma omp section
			{
				if(wspinZnplus3ex){
					term = lowermain(Znplus3ex);
					z_arr[515] = wspinZnplus3ex * term;
					w_arr[515] = wspinZnplus3ex;}
			}
#pragma omp section
			{
				if(wspinZnplus3ex){
					term = lowermain(Znplus3ex2);
					z_arr[515] += wspinZnplus3ex * term;
					w_arr[515] += wspinZnplus3ex;}
			}
#pragma omp section
			{
				if(wspinZnplus4){
					term = lowermain(Znplus4);
					z_arr[511] = wspinZnplus4 * term;
					w_arr[511] = wspinZnplus4;}
			}
#pragma omp section
			{
				if(wspinZnplus4ex){
					term = lowermain(Znplus4ex);
					z_arr[512] = wspinZnplus4ex * term;
					w_arr[512] = wspinZnplus4ex;}
			}
#pragma omp section
			{
				if(wspinZnplus4ex2){
					term = lowermain(Znplus4ex2);
					z_arr[513] = wspinZnplus4ex2 * term;
					w_arr[513] = wspinZnplus4ex2;}
			}
#pragma omp section
			{
				if(wspinZnplus4ex2){
					term = lowermain(Znplus4ex3);
					z_arr[513] += wspinZnplus4ex2 * term;
					w_arr[513] += wspinZnplus4ex2;}
			}
#pragma omp section
			{
				if(wspinZnplus5){
					term = lowermain(Znplus5);
					z_arr[508] = wspinZnplus5 * term;
					w_arr[508] = wspinZnplus5;}
			}
#pragma omp section
			{
				if(wspinZnplus5ex){
					term = lowermain(Znplus5ex);
					z_arr[509] = wspinZnplus5ex * term;
					w_arr[509] = wspinZnplus5ex;}
			}
#pragma omp section
			{
				if(wspinZnplus5ex2){
					term = lowermain(Znplus5ex2);
					z_arr[510] = wspinZnplus5ex2 * term;
					w_arr[510] = wspinZnplus5ex2;}
			}
#pragma omp section
			{
				if(wspinZnplus5ex2){
					term = lowermain(Znplus5ex3);
					z_arr[510] += wspinZnplus5ex2 * term;
					w_arr[510] += wspinZnplus5ex2;}
			}
#pragma omp section
			{
				if(wspinZnplus6){
					term = lowermain(Znplus6);
					z_arr[505] = wspinZnplus6 * term;
					w_arr[505] = wspinZnplus6;}
			}
#pragma omp section
			{
				if(wspinZnplus6ex){
					term = lowermain(Znplus6ex);
					z_arr[506] = wspinZnplus6ex * term;
					w_arr[506] = wspinZnplus6ex;}
			}
#pragma omp section
			{
				if(wspinZnplus6ex2){
					term = lowermain(Znplus6ex2);
					z_arr[507] = wspinZnplus6ex2 * term;
					w_arr[507] = wspinZnplus6ex2;}
			}
#pragma omp section
			{
				if(wspinZnplus6ex2){
					term = lowermain(Znplus6ex3);
					z_arr[507] += wspinZnplus6ex2 * term;
					w_arr[507] += wspinZnplus6ex2;}
			}
#pragma omp section
			{
				if(wspinZnplus7){
					term = lowermain(Znplus7);
					z_arr[504] = wspinZnplus7 * term;
					w_arr[504] = wspinZnplus7;}
			}
#pragma omp section
			{
				if(wspinZnplus7){
					term = lowermain(Znplus7ex);
					z_arr[504] += wspinZnplus7 * term;
					w_arr[504] += wspinZnplus7;}
			}
#pragma omp section
			{
				if(wspinZnplus8){
					term = lowermain(Znplus8);
					z_arr[503] = wspinZnplus8 * term;
					w_arr[503] = wspinZnplus8;}
			}
#pragma omp section
			{
				if(wspinZnplus8){
					term = lowermain(Znplus8ex);
					z_arr[503] += wspinZnplus8 * term;
					w_arr[503] += wspinZnplus8;}
			}
#pragma omp section
			{
				if(wspinZnplus9){
					term = lowermain(Znplus9);
					z_arr[502] = wspinZnplus9 * term;
					w_arr[502] = wspinZnplus9;}
			}
#pragma omp section
			{
				if(wspinZnplus9){
					term = lowermain(Znplus9ex);
					z_arr[502] += wspinZnplus9 * term;
					w_arr[502] += wspinZnplus9;}
			}
#pragma omp section
			{
				if(wspinZnplus10){
					term = lowermain(Znplus10);
					z_arr[500] = wspinZnplus10 * term;
					w_arr[500] = wspinZnplus10;}
			}
#pragma omp section
			{
				if(wspinZnplus10ex){
					term = lowermain(Znplus10ex);
					z_arr[501] = wspinZnplus10ex * term;
					w_arr[501] = wspinZnplus10ex;}
			}
#pragma omp section
			{
				if(wspinZnplus11){
					term = lowermain(Znplus11);
					z_arr[499] = wspinZnplus11 * term;
					w_arr[499] = wspinZnplus11;}
			}

#pragma omp section
			{
				if (wspinOH) {
					term = lowermainspinOH(); //201
					z_arr[201] = wspinOH * term;
					w_arr[201] = wspinOH;
				}
			}
//#pragma omp section
//			{
//				if (wspinH2O) {
//					term = lowermainspinH2O(); //202
//					z_arr[202] = wspinH2O * term;
//					w_arr[202] = wspinH2O;
//				}
//			}
//#pragma omp section
//			{
//				if (wspinH3O) {
//					term = lowermainspinH3O(); //203
//					z_arr[203] = wspinH3O * term;
//					w_arr[203] = wspinH3O;
//				}
//			}
//
#pragma omp section
			{
				if (wspinOHdot) {
					term = lowermainspinOHdot(); //204
					z_arr[204] = wspinOHdot * term;
					w_arr[204] = wspinOHdot;
				}
			}
#pragma omp section
			{
				if (wspinH2) {
					term = lowermain(H2); //210
					z_arr[210] = wspinH2 * term;
					w_arr[210] = wspinH2;
				}
			}
//#pragma omp section
//			{
//				if (wspinH2v) {
//					term = lowermainspinH2v(); //211
//					z_arr[211] = wspinH2v * term;
//					w_arr[211] = wspinH2v;
//				}
//			}
#pragma omp section
			{
				if (wspinH2plus) {
					term = lowermain(H2plus); //212
					z_arr[212] = wspinH2plus * term;
					w_arr[212] = wspinH2plus;
				}
			}
#pragma omp section
			{
				if (wspinO_2) {
					term = lowermain(O_2); //215
					z_arr[215] = wspinO_2 * term;
					w_arr[215] = wspinO_2;
				}
			}
#pragma omp section
			{
				if (wspinO_1) {
					term = lowermain(O_1); //214
					z_arr[214] = wspinO_1 * term;
					w_arr[214] = wspinO_1;
				}
			}
#pragma omp section
			{
				if (wspinOneutrl) {
					term = lowermain(Oneutrl); //213
					z_arr[213] = wspinOneutrl * term;
					w_arr[213] = wspinOneutrl;
				}
			}
#pragma omp section
			{
				if (wspinOplus1) {
					term = lowermain(Oplus1); //219
					z_arr[219] = wspinOplus1 * term;
					w_arr[219] = wspinOplus1;
				}
			}
#pragma omp section
			{
				if (wspinOplus2) {
					term = lowermain(Oplus2); //220
					z_arr[220] = wspinOplus2 * term;
					w_arr[220] = wspinOplus2;
				}
			}
#pragma omp section
			{
				if (wspinH) {
					term = lowermain(H); //221
					z_arr[221] = wspinH * term;
					w_arr[221] = wspinH;
				}
			}
#pragma omp section
			{
				if (wspinH_) {
					term = lowermain(H_); //222
					z_arr[222] = wspinH_ * term;
					w_arr[222] = wspinH_;
				}
			}
//#pragma omp section
//			{
//				if (wspinH_trp) {
//					term = lowermain(H_trp); //222
//					z_arr[223] = wspinH_trp * term;
//					w_arr[223] = wspinH_trp;
//				}
//			}
//#pragma omp section
//			{
//				if (wspinO2plus) {
//					term = lowermainspinO2plus(); //223
//					z_arr[223] = wspinO2plus * term;
//					w_arr[223] = wspinO2plus;
//				}
//			}
//#pragma omp section
//			{
//				if (wspinH2Oplus) {
//					term = lowermainspinH2Oplus(); //224
//					z_arr[224] = wspinH2Oplus * term;
//					w_arr[224] = wspinH2Oplus;
//				}
//			}
#pragma omp section
			{
				if (wspinH3plus) {
					term = lowermain(H3plus); //226
					z_arr[226] = wspinH3plus * term;
					w_arr[226] = wspinH3plus;
				}
			}
#pragma omp section
			{
				if(wspinH2minus){
					term = lowermain(H2minus);//227
					z_arr[227] = wspinH2minus * term;
					w_arr[227] = wspinH2minus;
				}
			}
#pragma omp section
			{
				if(wspinOHdot2){
					term = lowermainspinOHdot2();//228
					z_arr[228] = wspinOHdot2 * term;
					w_arr[228] = wspinOHdot2;
				}
			}
#pragma omp section
			{
				if (wspinOplus3) {
					term = lowermain(Oplus3); //229
					z_arr[229] = wspinOplus3 * term;
					w_arr[229] = wspinOplus3;
				}
			}
#pragma omp section
			{
				if (wspinOplus4) {
					term = lowermain(Oplus4); //230
					z_arr[230] = wspinOplus4 * term;
					w_arr[230] = wspinOplus4;
				}
			}
#pragma omp section
			{
				if (wspinOplus5) {
					term = lowermain(Oplus5); //231
					z_arr[231] = wspinOplus5 * term;
					w_arr[231] = wspinOplus5;
				}
			}
#pragma omp section
			{
				if(wspinOneutrlex) {
					term = lowermain(Oneutrlex);//233
					z_arr[233] = wspinOneutrlex * term;
					w_arr[233] = wspinOneutrlex;
				}
			}
#pragma omp section
			{
				if(wspinOplus2ex) {
					term = lowermain(Oplus2ex); //234
					z_arr[234] = wspinOplus2ex * term;
					w_arr[234] = wspinOplus2ex;
				}
			}
#pragma omp section
			{
				if(wspinOplus1ex) {
					term = lowermain(Oplus1ex);//235
					z_arr[235] = wspinOplus1ex * term;
					w_arr[235] = wspinOplus1ex;
				}
			}
#pragma omp section
			{
				if(wspinOplus4ex) {
					term = lowermain(Oplus4ex);//236
					z_arr[236] = wspinOplus4ex * term;
					w_arr[236] = wspinOplus4ex;
				}
			}

#pragma omp section
			{
				if(wspinCplus3){
					term = lowermain(Cplus3);//237
					z_arr[237] = wspinCplus3 * term;
					w_arr[237] = wspinCplus3;}
			}

#pragma omp section
			{
				if(wspinCplus2){
					term = lowermain(Cplus2);//238
					z_arr[238] = wspinCplus2 * term;
					w_arr[238] = wspinCplus2;}
			}

#pragma omp section
			{
				if(wspinCplus1){
					term = lowermain(Cplus1);//239
					z_arr[239] = wspinCplus1 * term;
					w_arr[239] = wspinCplus1;}
			}

#pragma omp section
			{
				if(wspinCneutrl){
					term = lowermain(Cneutrl);//240
					z_arr[240] = wspinCneutrl * term;
					w_arr[240] = wspinCneutrl;}
			}

#pragma omp section
			{
				if(wspinC_1){
					term = lowermain(C_1);//241
					z_arr[241] = wspinC_1 * term;
					w_arr[241] = wspinC_1;}
			}

#pragma omp section
			{
				if(wspinNplus4){
					term = lowermain(Nplus4);//242
					z_arr[242] = wspinNplus4 * term;
					w_arr[242] = wspinNplus4;}
			}

#pragma omp section
			{
				if(wspinNplus3){
					term = lowermain(Nplus3);//243

					z_arr[243] = wspinNplus3 * term;
					w_arr[243] = wspinNplus3;}
			}

#pragma omp section
			{
				if(wspinNplus2){
					term = lowermain(Nplus2);//244
					z_arr[244] = wspinNplus2 * term;
					w_arr[244] = wspinNplus2;}
			}

#pragma omp section
			{
				if(wspinNplus1){
					term = lowermain(Nplus1);//245
					z_arr[245] = wspinNplus1 * term;
					w_arr[245] = wspinNplus1;}
			}

#pragma omp section
			{
				if(wspinNneutrl){
					term = lowermain(Nneutrl);//246
					z_arr[246] = wspinNneutrl * term;
					w_arr[246] = wspinNneutrl;}
			}

//#pragma omp section
//			{
//				if(wspinN_1){
//					term = lowermain(N_1);//247
//					z_arr[247] = wspinN_1 * term;
//					w_arr[247] = wspinN_1;}
//			}

#pragma omp section
			{
				if(wspinSplus5){
					term = lowermainspinSplus5();//248
					z_arr[248] = wspinSplus5 * term;
					w_arr[248] = wspinSplus5;}
			}

#pragma omp section
			{
				if(wspinSplus4){
					term = lowermainspinSplus4();//249
					z_arr[249] = wspinSplus4 * term;
					w_arr[249] = wspinSplus4;}
			}

#pragma omp section
			{
				if(wspinSplus3){
					term = lowermainspinSplus3();//250
					z_arr[250] = wspinSplus3 * term;
					w_arr[250] = wspinSplus3;}
			}

#pragma omp section
			{
				if(wspinSplus2){
					term = lowermainspinSplus2();//251
					z_arr[251] = wspinSplus2 * term;
					w_arr[251] = wspinSplus2;}
			}

#pragma omp section
			{
				if(wspinSplus1){
					term = lowermainspinSplus1();//252
					z_arr[252] = wspinSplus1 * term;
					w_arr[252] = wspinSplus1;}
			}

#pragma omp section
			{
				if(wspinSneutrl){
					term = lowermainspinSneutrl();//253
					z_arr[253] = wspinSneutrl * term;
					w_arr[253] = wspinSneutrl;}
			}

#pragma omp section
			{
				if(wspinS_1){
					term = lowermainspinS_1();//254
					z_arr[254] = wspinS_1 * term;
					w_arr[254] = wspinS_1;}
			}

#pragma omp section
			{
				if(wspinPplus4){
					term = lowermainspinPplus4();//255
					z_arr[255] = wspinPplus4 * term;
					w_arr[255] = wspinPplus4;}
			}

#pragma omp section
			{
				if(wspinPplus3){
					term = lowermainspinPplus3();//256
					z_arr[256] = wspinPplus3 * term;
					w_arr[256] = wspinPplus3;}
			}

#pragma omp section
			{
				if(wspinPplus2){
					term = lowermainspinPplus2();//257
					z_arr[257] = wspinPplus2 * term;
					w_arr[257] = wspinPplus2;}
			}

#pragma omp section
			{
				if(wspinPplus1){
					term = lowermainspinPplus1();//258
					z_arr[258] = wspinPplus1 * term;
					w_arr[258] = wspinPplus1;}
			}

#pragma omp section
			{
				if(wspinPneutrl){
					term = lowermainspinPneutrl();//259
					z_arr[259] = wspinPneutrl * term;
					w_arr[259] = wspinPneutrl;}
			}

#pragma omp section
			{
				if(wspinP_1){
					term = lowermainspinP_1();//260
					z_arr[260] = wspinP_1 * term;
					w_arr[260] = wspinP_1;}
			}

#pragma omp section
			{
				if(wspinSiplus3){
					term = lowermainspinSiplus3();//261
					z_arr[261] = wspinSiplus3 * term;
					w_arr[261] = wspinSiplus3;}
			}

#pragma omp section
			{
				if(wspinSiplus2){
					term = lowermainspinSiplus2();//262
					z_arr[262] = wspinSiplus2 * term;
					w_arr[262] = wspinSiplus2;}
			}

#pragma omp section
			{
				if(wspinSiplus1){
					term = lowermainspinSiplus1();//263
					z_arr[263] = wspinSiplus1 * term;
					w_arr[263] = wspinSiplus1;}
			}

#pragma omp section
			{
				if(wspinSineutrl){
					term = lowermainspinSineutrl();//264
					z_arr[264] = wspinSineutrl * term;
					w_arr[264] = wspinSineutrl;}
			}

#pragma omp section
			{
				if(wspinSi_1){
					term = lowermainspinSi_1();//265
					z_arr[265] = wspinSi_1 * term;
					w_arr[265] = wspinSi_1;}
			}

#pragma omp section
			{
				if(wspinFplus6){
					term = lowermainspinFplus6();//266
					z_arr[266] = wspinFplus6 * term;
					w_arr[266] = wspinFplus6;}
			}

#pragma omp section
			{
				if(wspinFplus5){
					term = lowermainspinFplus5();//267
					z_arr[267] = wspinFplus5 * term;
					w_arr[267] = wspinFplus5;}
			}

#pragma omp section
			{
				if(wspinFplus4){
					term = lowermainspinFplus4();//268
					z_arr[268] = wspinFplus4 * term;
					w_arr[268] = wspinFplus4;}
			}

#pragma omp section
			{
				if(wspinFplus3){
					term = lowermainspinFplus3();//269
					z_arr[269] = wspinFplus3 * term;
					w_arr[269] = wspinFplus3;}
			}

#pragma omp section
			{
				if(wspinFplus2){
					term = lowermainspinFplus2();//270
					z_arr[270] = wspinFplus2 * term;
					w_arr[270] = wspinFplus2;}
			}

#pragma omp section
			{
				if(wspinFplus1){
					term = lowermainspinFplus1();//271
					z_arr[271] = wspinFplus1 * term;
					w_arr[271] = wspinFplus1;}
			}

#pragma omp section
			{
				if(wspinFneutrl){
					term = lowermainspinFneutrl();//272
					z_arr[272] = wspinFneutrl * term;
					w_arr[272] = wspinFneutrl;}
			}

#pragma omp section
			{
				if(wspinF_1){
					term = lowermainspinF_1();//273
					z_arr[273] = wspinF_1 * term;
					w_arr[273] = wspinF_1;}
			}

#pragma omp section
			{
				if(wspinOplus3ex) {
					term = lowermain(Oplus3ex); //274
					z_arr[274] = wspinOplus3ex * term;
					w_arr[274] = wspinOplus3ex;
				}
			}
#pragma omp section
			{
				if(wspinOplus2ex2) {
					term = lowermain(Oplus2ex2); //275
					z_arr[275] = wspinOplus2ex2 * term;
					w_arr[275] = wspinOplus2ex2;
				}
			}
#pragma omp section
			{
				if(wspinCplus2ex){
					term = lowermain(Cplus2ex);//276
					z_arr[276] = wspinCplus2ex * term;
					w_arr[276] = wspinCplus2ex;}
			}
#pragma omp section
			{
				if(wspinCplus1ex){
					term = lowermain(Cplus1ex);//277
					z_arr[277] = wspinCplus1ex * term;
					w_arr[277] = wspinCplus1ex;}
			}
#pragma omp section
			{
				if(wspinCneutrlex){
					term = lowermain(Cneutrlex);//278
					z_arr[278] = wspinCneutrlex * term;
					w_arr[278] = wspinCneutrlex;}
			}
#pragma omp section
			{
				if(wspinCneutrlex2){
					term = lowermain(Cneutrlex2);//279
					z_arr[279] = wspinCneutrlex2 * term;
					w_arr[279] = wspinCneutrlex2;}
			}
#pragma omp section
			{
				if(wspinNplus3ex){
					term = lowermain(Nplus3ex);//280
					z_arr[280] = wspinNplus3ex * term;
					w_arr[280] = wspinNplus3ex;}
			}
#pragma omp section
			{
				if(wspinNplus2ex){
					term = lowermain(Nplus2ex);//281
					z_arr[281] = wspinNplus2ex * term;
					w_arr[281] = wspinNplus2ex;}
			}
#pragma omp section
			{
				if(wspinNplus1ex){
					term = lowermain(Nplus1ex);//282
					z_arr[282] = wspinNplus1ex * term;
					w_arr[282] = wspinNplus1ex;}
			}
#pragma omp section
			{
				if(wspinNplus1ex2){
					term = lowermain(Nplus1ex2);//283
					z_arr[283] = wspinNplus1ex2 * term;
					w_arr[283] = wspinNplus1ex2;}
			}
#pragma omp section
			{
				if(wspinNneutrlex){
					term = lowermain(Nneutrlex);//284
					z_arr[284] = wspinNneutrlex * term;
					w_arr[284] = wspinNneutrlex;}
			}
#pragma omp section
			{
				if(wspinFplus5ex){
					term = lowermainspinFplus5ex();//285
					z_arr[285] = wspinFplus5ex * term;
					w_arr[285] = wspinFplus5ex;}
			}
#pragma omp section
			{
				if(wspinFplus4ex){
					term = lowermainspinFplus4ex();//286
					z_arr[286] = wspinFplus4ex * term;
					w_arr[286] = wspinFplus4ex;}
			}
#pragma omp section
			{
				if(wspinFplus3ex){
					term = lowermainspinFplus3ex();//287
					z_arr[287] = wspinFplus3ex * term;
					w_arr[287] = wspinFplus3ex;}
			}
#pragma omp section
			{
				if(wspinFplus3ex2){
					term = lowermainspinFplus3ex2();//288
					z_arr[288] = wspinFplus3ex2 * term;
					w_arr[288] = wspinFplus3ex2;}
			}
#pragma omp section
			{
				if(wspinFplus2ex){
					term = lowermainspinFplus2ex();//289
					z_arr[289] = wspinFplus2ex * term;
					w_arr[289] = wspinFplus2ex;}
			}
#pragma omp section
			{
				if(wspinFplus1ex){
					term = lowermainspinFplus1ex();//290
					z_arr[290] = wspinFplus1ex * term;
					w_arr[290] = wspinFplus1ex;}
			}
#pragma omp section
			{
				if(wspinSiplus2ex){
					term = lowermainspinSiplus2ex();//291
					z_arr[291] = wspinSiplus2ex * term;
					w_arr[291] = wspinSiplus2ex;}
			}
#pragma omp section
			{
				if(wspinSiplus1ex){
					term = lowermainspinSiplus1ex();//292
					z_arr[292] = wspinSiplus1ex * term;
					w_arr[292] = wspinSiplus1ex;}
			}
#pragma omp section
			{
				if(wspinSineutrlex){
					term = lowermainspinSineutrlex();//293
					z_arr[293] = wspinSineutrlex * term;
					w_arr[293] = wspinSineutrlex;}
			}
#pragma omp section
			{
				if(wspinSineutrlex2){
					term = lowermainspinSineutrlex2();//294
					z_arr[294] = wspinSineutrlex2 * term;
					w_arr[294] = wspinSineutrlex2;}
			}
#pragma omp section
			{
				if(wspinPplus3ex){
					term = lowermainspinPplus3ex();//295
					z_arr[295] = wspinPplus3ex * term;
					w_arr[295] = wspinPplus3ex;}
			}
#pragma omp section
			{
				if(wspinPplus2ex){
					term = lowermainspinPplus2ex();//296
					z_arr[296] = wspinPplus2ex * term;
					w_arr[296] = wspinPplus2ex;}
			}
#pragma omp section
			{
				if(wspinPplus1ex){
					term = lowermainspinPplus1ex();//297
					z_arr[297] = wspinPplus1ex * term;
					w_arr[297] = wspinPplus1ex;}
			}
#pragma omp section
			{
				if(wspinPplus1ex2){
					term = lowermainspinPplus1ex2();//298
					z_arr[298] = wspinPplus1ex2 * term;
					w_arr[298] = wspinPplus1ex2;}
			}
#pragma omp section
			{
				if(wspinPneutrlex){
					term = lowermainspinPneutrlex();//299
					z_arr[299] = wspinPneutrlex * term;
					w_arr[299] = wspinPneutrlex;}
			}
#pragma omp section
			{
				if(wspinSplus4ex){
					term = lowermainspinSplus4ex();//300
					z_arr[300] = wspinSplus4ex * term;
					w_arr[300] = wspinSplus4ex;}
			}
#pragma omp section
			{
				if(wspinSplus3ex){
					term = lowermainspinSplus3ex();//301
					z_arr[301] = wspinSplus3ex * term;
					w_arr[301] = wspinSplus3ex;}
			}
#pragma omp section
			{
				if(wspinSplus2ex){
					term = lowermainspinSplus2ex();//302
					z_arr[302] = wspinSplus2ex * term;
					w_arr[302] = wspinSplus2ex;}
			}
#pragma omp section
			{
				if(wspinSplus2ex2){
					term = lowermainspinSplus2ex2();//303
					z_arr[303] = wspinSplus2ex2 * term;
					w_arr[303] = wspinSplus2ex2;}
			}
#pragma omp section
			{
				if(wspinSplus1ex){
					term = lowermainspinSplus1ex();//304
					z_arr[304] = wspinSplus1ex * term;
					w_arr[304] = wspinSplus1ex;}
			}
#pragma omp section
			{
				if(wspinSneutrlex){
					term = lowermainspinSneutrlex();//305
					z_arr[305] = wspinSneutrlex * term;
					w_arr[305] = wspinSneutrlex;}
			}

#pragma omp section
			{
				if(wspinOneutrlex2){
					term = lowermain(Oneutrlex2);//306
					z_arr[306] = wspinOneutrlex2 * term;
					w_arr[306] = wspinOneutrlex2;}
			}
#pragma omp section
			{
				if(wspinOplus1ex2){
					term = lowermain(Oplus1ex2);//307
					z_arr[307] = wspinOplus1ex2 * term;
					w_arr[307] = wspinOplus1ex2;}
			}
//#pragma omp section
//			{
//				if(wspinNneutrlex2){
//					term = lowermain(Nneutrlex2);//308
//					z_arr[308] = wspinNneutrlex2 * term;
//					w_arr[308] = wspinNneutrlex2;}
//			}
#pragma omp section
			{
				if(wspinFneutrlex){
					term = lowermainspinFneutrlex();//309
					z_arr[309] = wspinFneutrlex * term;
					w_arr[309] = wspinFneutrlex;}
			}
#pragma omp section
			{
				if(wspinFplus1ex2){
					term = lowermainspinFplus1ex2();//310
					z_arr[310] = wspinFplus1ex2 * term;
					w_arr[310] = wspinFplus1ex2;}
			}
#pragma omp section
			{
				if(wspinFplus2ex2){
					term = lowermainspinFplus2ex2();//311
					z_arr[311] = wspinFplus2ex2 * term;
					w_arr[311] = wspinFplus2ex2;}
			}
#pragma omp section
			{
				if(wspinSneutrlex2){
					term = lowermainspinSneutrlex2();//312
					z_arr[312] = wspinSneutrlex2 * term;
					w_arr[312] = wspinSneutrlex2;}
			}

#pragma omp section
			{
				if(wspinB_1){
					term = lowermainspinB_1();//313
					z_arr[313] = wspinB_1 * term;
					w_arr[313] = wspinB_1;}
			}
#pragma omp section
			{
				if(wspinBneutrlex){
					term = lowermainspinBneutrlex();//314
					z_arr[314] = wspinBneutrlex * term;
					w_arr[314] = wspinBneutrlex;}
			}
#pragma omp section
			{
				if(wspinBneutrl){
					term = lowermainspinBneutrl();//315
					z_arr[315] = wspinBneutrl * term;
					w_arr[315] = wspinBneutrl;}
			}
#pragma omp section
			{
				if(wspinBplus1ex){
					term = lowermainspinBplus1ex();//316
					z_arr[316] = wspinBplus1ex * term;
					w_arr[316] = wspinBplus1ex;}
			}
#pragma omp section
			{
				if(wspinBplus1){
					term = lowermainspinBplus1();//317
					z_arr[317] = wspinBplus1 * term;
					w_arr[317] = wspinBplus1;}
			}
#pragma omp section
			{
				if(wspinBplus2){
					term = lowermainspinBplus2();//318
					z_arr[318] = wspinBplus2 * term;
					w_arr[318] = wspinBplus2;}
			}
#pragma omp section
			{
				if(wspinCl_1){
					term = lowermainspinCl_1();//319
					z_arr[319] = wspinCl_1 * term;
					w_arr[319] = wspinCl_1;}
			}
#pragma omp section
			{
				if(wspinClneutrlex){
					term = lowermainspinClneutrlex();//320
					z_arr[320] = wspinClneutrlex * term;
					w_arr[320] = wspinClneutrlex;}
			}
#pragma omp section
			{
				if(wspinClneutrl){
					term = lowermainspinClneutrl();//321
					z_arr[321] = wspinClneutrl * term;
					w_arr[321] = wspinClneutrl;}
			}
#pragma omp section
			{
				if(wspinClplus1ex2){
					term = lowermainspinClplus1ex2();//322
					z_arr[322] = wspinClplus1ex2 * term;
					w_arr[322] = wspinClplus1ex2;}
			}
#pragma omp section
			{
				if(wspinClplus1ex){
					term = lowermainspinClplus1ex();//323
					z_arr[323] = wspinClplus1ex * term;
					w_arr[323] = wspinClplus1ex;}
			}
#pragma omp section
			{
				if(wspinClplus1){
					term = lowermainspinClplus1();//324
					z_arr[324] = wspinClplus1 * term;
					w_arr[324] = wspinClplus1;}
			}
#pragma omp section
			{
				if(wspinClplus2ex){
					term = lowermainspinClplus2ex();//325
					z_arr[325] = wspinClplus2ex * term;
					w_arr[325] = wspinClplus2ex;}
			}
#pragma omp section
			{
				if(wspinClplus2){
					term = lowermainspinClplus2();//326
					z_arr[326] = wspinClplus2 * term;
					w_arr[326] = wspinClplus2;}
			}
#pragma omp section
			{
				if(wspinClplus3ex2){
					term = lowermainspinClplus3ex2();//327
					z_arr[327] = wspinClplus3ex2 * term;
					w_arr[327] = wspinClplus3ex2;}
			}
#pragma omp section
			{
				if(wspinClplus3ex){
					term = lowermainspinClplus3ex();//328
					z_arr[328] = wspinClplus3ex * term;
					w_arr[328] = wspinClplus3ex;}
			}
#pragma omp section
			{
				if(wspinClplus3){
					term = lowermainspinClplus3();//329
					z_arr[329] = wspinClplus3 * term;
					w_arr[329] = wspinClplus3;}
			}
#pragma omp section
			{
				if(wspinClplus4ex){
					term = lowermainspinClplus4ex();//330
					z_arr[330] = wspinClplus4ex * term;
					w_arr[330] = wspinClplus4ex;}
			}
#pragma omp section
			{
				if(wspinClplus4){
					term = lowermainspinClplus4();//331
					z_arr[331] = wspinClplus4 * term;
					w_arr[331] = wspinClplus4;}
			}
#pragma omp section
			{
				if(wspinClplus5ex){
					term = lowermainspinClplus5ex();//332
					z_arr[332] = wspinClplus5ex * term;
					w_arr[332] = wspinClplus5ex;}
			}
#pragma omp section
			{
				if(wspinClplus5){
					term = lowermainspinClplus5();//333
					z_arr[333] = wspinClplus5 * term;
					w_arr[333] = wspinClplus5;}
			}
#pragma omp section
			{
				if(wspinClplus6){
					term = lowermainspinClplus6();//334
					z_arr[334] = wspinClplus6 * term;
					w_arr[334] = wspinClplus6;}
			}
#pragma omp section
			{
				if(wspinAl_1){
					term = lowermainspinAl_1();//335
					z_arr[335] = wspinAl_1 * term;
					w_arr[335] = wspinAl_1;}
			}
#pragma omp section
			{
				if(wspinAlneutrlex){
					term = lowermainspinAlneutrlex();//336
					z_arr[336] = wspinAlneutrlex * term;
					w_arr[336] = wspinAlneutrlex;}
			}
#pragma omp section
			{
				if(wspinAlneutrl){
					term = lowermainspinAlneutrl();//337
					z_arr[337] = wspinAlneutrl * term;
					w_arr[337] = wspinAlneutrl;}
			}
#pragma omp section
			{
				if(wspinAlplus1ex){
					term = lowermainspinAlplus1ex();//338
					z_arr[338] = wspinAlplus1ex * term;
					w_arr[338] = wspinAlplus1ex;}
			}
#pragma omp section
			{
				if(wspinAlplus1){
					term = lowermainspinAlplus1();//339
					z_arr[339] = wspinAlplus1 * term;
					w_arr[339] = wspinAlplus1;}
			}
#pragma omp section
			{
				if(wspinAlplus2){
					term = lowermainspinAlplus2();//340
					z_arr[340] = wspinAlplus2 * term;
					w_arr[340] = wspinAlplus2;}
			}
#pragma omp section
			{
				if (wspinH3) {
					term = lowermain(H3); //341
					z_arr[341] = wspinH3 * term;
					w_arr[341] = wspinH3;
				}
			}
//#pragma omp section
//			{
//				if (wspinH4) {
//					term = lowermain(H4); //342
//					z_arr[342] = wspinH4 * term;
//					w_arr[342] = wspinH4;
//				}
//			}
#pragma omp section
			{
				if(wspinLi_1){
					term = lowermainspinLi_1();//343
					z_arr[343] = wspinLi_1 * term;
					w_arr[343] = wspinLi_1;}
			}
#pragma omp section
			{
				if(wspinLineutrl){
					term = lowermainspinLineutrl();//344
					z_arr[344] = wspinLineutrl * term;
					w_arr[344] = wspinLineutrl;}
			}
#pragma omp section
			{
				if(wspinBeneutrl){
					term = lowermainspinBeneutrl();//345
					z_arr[345] = wspinBeneutrl * term;
					w_arr[345] = wspinBeneutrl;}
			}
#pragma omp section
			{
				if(wspinBeneutrlex){
					term = lowermainspinBeneutrlex();//346
					z_arr[346] = wspinBeneutrlex * term;
					w_arr[346] = wspinBeneutrlex;}
			}
#pragma omp section
			{
				if(wspinBeplus1){
					term = lowermainspinBeplus1();//347
					z_arr[347] = wspinBeplus1 * term;
					w_arr[347] = wspinBeplus1;}
			}
#pragma omp section
			{
				if(wspinNa_1){
					term = lowermainspinNa_1();//348
					z_arr[348] = wspinNa_1 * term;
					w_arr[348] = wspinNa_1;}
			}
#pragma omp section
			{
				if(wspinNaneutrl){
					term = lowermainspinNaneutrl();//349
					z_arr[349] = wspinNaneutrl * term;
					w_arr[349] = wspinNaneutrl;}
			}
#pragma omp section
			{
				if(wspinMgneutrl){
					term = lowermainspinMgneutrl();//350
					z_arr[350] = wspinMgneutrl * term;
					w_arr[350] = wspinMgneutrl;}
			}
#pragma omp section
			{
				if(wspinMgneutrlex){
					term = lowermainspinMgneutrlex();//351
					z_arr[351] = wspinMgneutrlex * term;
					w_arr[351] = wspinMgneutrlex;}
			}
#pragma omp section
			{
				if(wspinMgplus1){
					term = lowermainspinMgplus1();//352
					z_arr[352] = wspinMgplus1 * term;
					w_arr[352] = wspinMgplus1;}
			}

#pragma omp section
			{
				if(wspinH2trp){
					term = lowermain(H2trp);//353
					z_arr[353] = wspinH2trp * term;
					w_arr[353] = wspinH2trp;}
			}

#pragma omp section
                        {
                                if (wspinH3linear) {
                                        term = lowermain(H3linear); //380
                                        z_arr[380] = wspinH3linear * term;
                                        w_arr[380] = wspinH3linear;
                                }
                        }
//#pragma omp section
//                        {
//                                if (wspinH3trig) {
//                                        term = lowermain(H3trig); //381
//                                        z_arr[381] = wspinH3trig * term;
//                                        w_arr[381] = wspinH3trig;
//                                }
//                        }
//#pragma omp section
//                        {
//                                if (wspinH4linear) {
//                                        term = lowermain(H4linear); //382
//                                        z_arr[382] = wspinH4linear * term;
//                                        w_arr[382] = wspinH4linear;
//                                }
//                        }
//#pragma omp section
//                        {
//                                if (wspinH4square) {
//                                        term = lowermain(H4square); //383
//                                        z_arr[383] = wspinH4square * term;
//                                        w_arr[383] = wspinH4square;
//                                }
//                        }
//#pragma omp section
//                        {
//                                if (wspinH4tetra) {
//                                        term = lowermain(H4tetra); //384
//                                        z_arr[384] = wspinH4tetra * term;
//                                        w_arr[384] = wspinH4tetra;
//                                }
//                        }
//#pragma omp section
//                        {
//                                if (wspinH_polar) {
//                                        term = lowermainspinH_polar(); //385
//                                        z_arr[385] = wspinH_polar * term;
//                                        w_arr[385] = wspinH_polar;
//                                }
//                        }
#pragma omp section
                        {
                                if (wspinBneutrl_polar) {
                                        term = lowermainspinBneutrl_polar(); //386
                                        z_arr[386] = wspinBneutrl_polar * term;
                                        w_arr[386] = wspinBneutrl_polar;
                                }
                        }
#pragma omp section
                        {
                                if (wspinCneutrl_polar) {
                                        term = lowermainspinCneutrl_polar(); //387
                                        z_arr[387] = wspinCneutrl_polar * term;
                                        w_arr[387] = wspinCneutrl_polar;
                                }
                        }
#pragma omp section
                        {
                                if (wspinNneutrl_polar) {
                                        term = lowermainspinNneutrl_polar(); //388
                                        z_arr[388] = wspinNneutrl_polar * term;
                                        w_arr[388] = wspinNneutrl_polar;
                                }
                        }
#pragma omp section
                        {
                                if (wspinOneutrl_polar) {
                                        term = lowermainspinOneutrl_polar(); //389
                                        z_arr[389] = wspinOneutrl_polar * term;
                                        w_arr[389] = wspinOneutrl_polar;
                                }
                        }
#pragma omp section
                        {
                                if (wspinFneutrl_polar) {
                                        term = lowermainspinFneutrl_polar(); //390
                                        z_arr[390] = wspinFneutrl_polar * term;
                                        w_arr[390] = wspinFneutrl_polar;
                                }
                        }
#pragma omp section
                        {
                                if (wspinAlneutrl_polar) {
                                        term = lowermainspinAlneutrl_polar(); //391 
                                        z_arr[391] = wspinAlneutrl_polar * term;
                                        w_arr[391] = wspinAlneutrl_polar;
                                }
                        }
#pragma omp section
                        {
                                if (wspinSineutrl_polar) {
                                        term = lowermainspinSineutrl_polar(); //392
                                        z_arr[392] = wspinSineutrl_polar * term;
                                        w_arr[392] = wspinSineutrl_polar;
                                }
                        }
#pragma omp section
                        {
                                if (wspinPneutrl_polar) {
                                        term = lowermainspinPneutrl_polar(); //393
                                        z_arr[393] = wspinPneutrl_polar * term;
                                        w_arr[393] = wspinPneutrl_polar;
                                }
                        }
#pragma omp section
                        {
                                if (wspinSneutrl_polar) {
                                        term = lowermainspinSneutrl_polar(); //394
                                        z_arr[394] = wspinSneutrl_polar * term;
                                        w_arr[394] = wspinSneutrl_polar;
                                }
                        }
#pragma omp section
                        {
                                if (wspinClneutrl_polar) {
                                        term = lowermainspinClneutrl_polar(); //395
                                        z_arr[395] = wspinClneutrl_polar * term;
                                        w_arr[395] = wspinClneutrl_polar;
                                }
                        }
#pragma omp section
			{
				if(wspinScplus2){
					term = lowermainspinScplus2();
					z_arr[518] = wspinScplus2 * term;
					w_arr[518] = wspinScplus2;}
			}
#pragma omp section
			{
				if(wspinTiplus3){
					term = lowermainspinTiplus3();
					z_arr[519] = wspinTiplus3 * term;
					w_arr[519] = wspinTiplus3;}
			}
#pragma omp section
			{
				if(wspinTiplus2){
					term = lowermainspinTiplus2();
					z_arr[520] = wspinTiplus2 * term;
					w_arr[520] = wspinTiplus2;}
			}
#pragma omp section
			{
				if(wspinTiplus2ex){
					term = lowermainspinTiplus2ex();
					z_arr[521] = wspinTiplus2ex * term;
					w_arr[521] = wspinTiplus2ex;}
			}
#pragma omp section
			{
				if(wspinVplus4){
					term = lowermainspinVplus4();
					z_arr[522] = wspinVplus4 * term;
					w_arr[522] = wspinVplus4;}
			}
#pragma omp section
			{
				if(wspinVplus3){
					term = lowermainspinVplus3();
					z_arr[523] = wspinVplus3 * term;
					w_arr[523] = wspinVplus3;}
			}
#pragma omp section
			{
				if(wspinVplus3ex){
					term = lowermainspinVplus3ex();
					z_arr[524] = wspinVplus3ex * term;
					w_arr[524] = wspinVplus3ex;}
			}
#pragma omp section
			{
				if(wspinVplus2){
					term = lowermainspinVplus2();
					z_arr[525] = wspinVplus2 * term;
					w_arr[525] = wspinVplus2;}
			}
#pragma omp section
			{
				if(wspinVplus2ex){
					term = lowermainspinVplus2ex();
					z_arr[526] = wspinVplus2ex * term;
					w_arr[526] = wspinVplus2ex;}
			}
#pragma omp section
			{
				if(wspinCrplus5){
					term = lowermainspinCrplus5();
					z_arr[527] = wspinCrplus5 * term;
					w_arr[527] = wspinCrplus5;}
			}
#pragma omp section
			{
				if(wspinCrplus4){
					term = lowermainspinCrplus4();
					z_arr[528] = wspinCrplus4 * term;
					w_arr[528] = wspinCrplus4;}
			}
#pragma omp section
			{
				if(wspinCrplus4ex){
					term = lowermainspinCrplus4ex();
					z_arr[529] = wspinCrplus4ex * term;
					w_arr[529] = wspinCrplus4ex;}
			}
#pragma omp section
			{
				if(wspinCrplus3){
					term = lowermainspinCrplus3();
					z_arr[530] = wspinCrplus3 * term;
					w_arr[530] = wspinCrplus3;}
			}
#pragma omp section
			{
				if(wspinCrplus3ex){
					term = lowermainspinCrplus3ex();
					z_arr[531] = wspinCrplus3ex * term;
					w_arr[531] = wspinCrplus3ex;}
			}
#pragma omp section
			{
				if(wspinCrplus2){
					term = lowermainspinCrplus2();
					z_arr[532] = wspinCrplus2 * term;
					w_arr[532] = wspinCrplus2;}
			}
#pragma omp section
			{
				if(wspinCrplus2ex){
					term = lowermainspinCrplus2ex();
					z_arr[533] = wspinCrplus2ex * term;
					w_arr[533] = wspinCrplus2ex;}
			}
#pragma omp section
			{
				if(wspinCrplus2ex2){
					term = lowermainspinCrplus2ex2();
					z_arr[534] = wspinCrplus2ex2 * term;
					w_arr[534] = wspinCrplus2ex2;}
			}
#pragma omp section
			{
				if(wspinCrplus1){
					term = lowermainspinCrplus1();
					z_arr[535] = wspinCrplus1 * term;
					w_arr[535] = wspinCrplus1;}
			}
#pragma omp section
			{
				if(wspinCrplus1ex){
					term = lowermainspinCrplus1ex();
					z_arr[536] = wspinCrplus1ex * term;
					w_arr[536] = wspinCrplus1ex;}
			}
#pragma omp section
			{
				if(wspinCrplus1ex2){
					term = lowermainspinCrplus1ex2();
					z_arr[537] = wspinCrplus1ex2 * term;
					w_arr[537] = wspinCrplus1ex2;}
			}
#pragma omp section
			{
				if(wspinMnplus6){
					term = lowermainspinMnplus6();
					z_arr[538] = wspinMnplus6 * term;
					w_arr[538] = wspinMnplus6;}
			}
#pragma omp section
			{
				if(wspinMnplus5){
					term = lowermainspinMnplus5();
					z_arr[539] = wspinMnplus5 * term;
					w_arr[539] = wspinMnplus5;}
			}
#pragma omp section
			{
				if(wspinMnplus5ex){
					term = lowermainspinMnplus5ex();
					z_arr[540] = wspinMnplus5ex * term;
					w_arr[540] = wspinMnplus5ex;}
			}
#pragma omp section
			{
				if(wspinMnplus4){
					term = lowermainspinMnplus4();
					z_arr[541] = wspinMnplus4 * term;
					w_arr[541] = wspinMnplus4;}
			}
#pragma omp section
			{
				if(wspinMnplus4ex){
					term = lowermainspinMnplus4ex();
					z_arr[542] = wspinMnplus4ex * term;
					w_arr[542] = wspinMnplus4ex;}
			}
#pragma omp section
			{
				if(wspinMnplus3){
					term = lowermainspinMnplus3();
					z_arr[543] = wspinMnplus3 * term;
					w_arr[543] = wspinMnplus3;}
			}
#pragma omp section
			{
				if(wspinMnplus3ex){
					term = lowermainspinMnplus3ex();
					z_arr[544] = wspinMnplus3ex * term;
					w_arr[544] = wspinMnplus3ex;}
			}
#pragma omp section
			{
				if(wspinMnplus2){
					term = lowermainspinMnplus2();
					z_arr[545] = wspinMnplus2 * term;
					w_arr[545] = wspinMnplus2;}
			}
#pragma omp section
			{
				if(wspinMnplus2ex){
					term = lowermainspinMnplus2ex();
					z_arr[546] = wspinMnplus2ex * term;
					w_arr[546] = wspinMnplus2ex;}
			}
#pragma omp section
			{
				if(wspinMnplus2ex2){
					term = lowermainspinMnplus2ex2();
					z_arr[547] = wspinMnplus2ex2 * term;
					w_arr[547] = wspinMnplus2ex2;}
			}
#pragma omp section
			{
				if(wspinFeplus7){
					term = lowermain(Feplus7);
					z_arr[548] = wspinFeplus7 * term;
					w_arr[548] = wspinFeplus7;}
			}
#pragma omp section
			{
				if(wspinFeplus6){
					term = lowermain(Feplus6);
					z_arr[549] = wspinFeplus6 * term;
					w_arr[549] = wspinFeplus6;}
			}
#pragma omp section
			{
				if(wspinFeplus6ex){
					term = lowermain(Feplus6ex);
					z_arr[550] = wspinFeplus6ex * term;
					w_arr[550] = wspinFeplus6ex;}
			}
#pragma omp section
			{
				if(wspinFeplus5){
					term = lowermain(Feplus5);
					z_arr[551] = wspinFeplus5 * term;
					w_arr[551] = wspinFeplus5;}
			}
#pragma omp section
			{
				if(wspinFeplus5ex){
					term = lowermain(Feplus5ex);
					z_arr[552] = wspinFeplus5ex * term;
					w_arr[552] = wspinFeplus5ex;}
			}
#pragma omp section
			{
				if(wspinFeplus4){
					term = lowermain(Feplus4);
					z_arr[553] = wspinFeplus4 * term;
					w_arr[553] = wspinFeplus4;}
			}
#pragma omp section
			{
				if(wspinFeplus4ex){
					term = lowermain(Feplus4ex);
					z_arr[554] = wspinFeplus4ex * term;
					w_arr[554] = wspinFeplus4ex;}
			}
#pragma omp section
			{
				if(wspinFeplus4ex2){
					term = lowermain(Feplus4ex2);
					z_arr[555] = wspinFeplus4ex2 * term;
					w_arr[555] = wspinFeplus4ex2;}
			}
#pragma omp section
			{
				if(wspinFeplus3){
					term = lowermain(Feplus3);
					z_arr[556] = wspinFeplus3 * term;
					w_arr[556] = wspinFeplus3;}
			}
#pragma omp section
			{
				if(wspinFeplus3ex){
					term = lowermain(Feplus3ex);
					z_arr[557] = wspinFeplus3ex * term;
					w_arr[557] = wspinFeplus3ex;}
			}
#pragma omp section
			{
				if(wspinFeplus3ex2){
					term = lowermain(Feplus3ex2);
					z_arr[558] = wspinFeplus3ex2 * term;
					w_arr[558] = wspinFeplus3ex2;}
			}
#pragma omp section
			{
				if(wspinFeplus2){
					term = lowermain(Feplus2);
					z_arr[559] = wspinFeplus2 * term;
					w_arr[559] = wspinFeplus2;}
			}
#pragma omp section
			{
				if(wspinFeplus2ex){
					term = lowermain(Feplus2ex);
					z_arr[560] = wspinFeplus2ex * term;
					w_arr[560] = wspinFeplus2ex;}
			}
#pragma omp section
			{
				if(wspinFeplus2ex2){
					term = lowermain(Feplus2ex2);
					z_arr[561] = wspinFeplus2ex2 * term;
					w_arr[561] = wspinFeplus2ex2;}
			}
#pragma omp section
			{
				if(wspinCoplus8){
					term = lowermainspinCoplus8();
					z_arr[562] = wspinCoplus8 * term;
					w_arr[562] = wspinCoplus8;}
			}
#pragma omp section
			{
				if(wspinCoplus7){
					term = lowermainspinCoplus7();
					z_arr[563] = wspinCoplus7 * term;
					w_arr[563] = wspinCoplus7;}
			}
#pragma omp section
			{
				if(wspinCoplus7ex){
					term = lowermainspinCoplus7ex();
					z_arr[564] = wspinCoplus7ex * term;
					w_arr[564] = wspinCoplus7ex;}
			}
#pragma omp section
			{
				if(wspinCoplus6){
					term = lowermainspinCoplus6();
					z_arr[565] = wspinCoplus6 * term;
					w_arr[565] = wspinCoplus6;}
			}
#pragma omp section
			{
				if(wspinCoplus6ex){
					term = lowermainspinCoplus6ex();
					z_arr[566] = wspinCoplus6ex * term;
					w_arr[566] = wspinCoplus6ex;}
			}
#pragma omp section
			{
				if(wspinCoplus5){
					term = lowermainspinCoplus5();
					z_arr[567] = wspinCoplus5 * term;
					w_arr[567] = wspinCoplus5;}
			}
#pragma omp section
			{
				if(wspinCoplus5ex){
					term = lowermainspinCoplus5ex();
					z_arr[568] = wspinCoplus5ex * term;
					w_arr[568] = wspinCoplus5ex;}
			}
#pragma omp section
			{
				if(wspinCoplus5ex2){
					term = lowermainspinCoplus5ex2();
					z_arr[569] = wspinCoplus5ex2 * term;
					w_arr[569] = wspinCoplus5ex2;}
			}
#pragma omp section
			{
				if(wspinCoplus4){
					term = lowermainspinCoplus4();
					z_arr[570] = wspinCoplus4 * term;
					w_arr[570] = wspinCoplus4;}
			}
#pragma omp section
			{
				if(wspinCoplus4ex){
					term = lowermainspinCoplus4ex();
					z_arr[571] = wspinCoplus4ex * term;
					w_arr[571] = wspinCoplus4ex;}
			}
#pragma omp section
			{
				if(wspinCoplus4ex2){
					term = lowermainspinCoplus4ex2();
					z_arr[572] = wspinCoplus4ex2 * term;
					w_arr[572] = wspinCoplus4ex2;}
			}
#pragma omp section
			{
				if(wspinCoplus3){
					term = lowermainspinCoplus3();
					z_arr[573] = wspinCoplus3 * term;
					w_arr[573] = wspinCoplus3;}
			}
#pragma omp section
			{
				if(wspinCoplus3ex){
					term = lowermainspinCoplus3ex();
					z_arr[574] = wspinCoplus3ex * term;
					w_arr[574] = wspinCoplus3ex;}
			}
#pragma omp section
			{
				if(wspinCoplus3ex2){
					term = lowermainspinCoplus3ex2();
					z_arr[575] = wspinCoplus3ex2 * term;
					w_arr[575] = wspinCoplus3ex2;}
			}
#pragma omp section
			{
				if(wspinCoplus2){
					term = lowermainspinCoplus2();
					z_arr[576] = wspinCoplus2 * term;
					w_arr[576] = wspinCoplus2;}
			}
#pragma omp section
			{
				if(wspinCoplus2ex){
					term = lowermainspinCoplus2ex();
					z_arr[577] = wspinCoplus2ex * term;
					w_arr[577] = wspinCoplus2ex;}
			}
#pragma omp section
			{
				if(wspinCoplus2ex2){
					term = lowermainspinCoplus2ex2();
					z_arr[578] = wspinCoplus2ex2 * term;
					w_arr[578] = wspinCoplus2ex2;}
			}
#pragma omp section
			{
				if(wspinNiplus9){
					term = lowermainspinNiplus9();
					z_arr[579] = wspinNiplus9 * term;
					w_arr[579] = wspinNiplus9;}
			}
#pragma omp section
			{
				if(wspinNiplus8){
					term = lowermainspinNiplus8();
					z_arr[580] = wspinNiplus8 * term;
					w_arr[580] = wspinNiplus8;}
			}
#pragma omp section
			{
				if(wspinNiplus8ex){
					term = lowermainspinNiplus8ex();
					z_arr[581] = wspinNiplus8ex * term;
					w_arr[581] = wspinNiplus8ex;}
			}
#pragma omp section
			{
				if(wspinNiplus7){
					term = lowermainspinNiplus7();
					z_arr[582] = wspinNiplus7 * term;
					w_arr[582] = wspinNiplus7;}
			}
#pragma omp section
			{
				if(wspinNiplus7ex){
					term = lowermainspinNiplus7ex();
					z_arr[583] = wspinNiplus7ex * term;
					w_arr[583] = wspinNiplus7ex;}
			}
#pragma omp section
			{
				if(wspinNiplus6){
					term = lowermainspinNiplus6();
					z_arr[584] = wspinNiplus6 * term;
					w_arr[584] = wspinNiplus6;}
			}
#pragma omp section
			{
				if(wspinNiplus6ex){
					term = lowermainspinNiplus6ex();
					z_arr[585] = wspinNiplus6ex * term;
					w_arr[585] = wspinNiplus6ex;}
			}
#pragma omp section
			{
				if(wspinNiplus5){
					term = lowermainspinNiplus5();
					z_arr[586] = wspinNiplus5 * term;
					w_arr[586] = wspinNiplus5;}
			}
#pragma omp section
			{
				if(wspinNiplus5ex){
					term = lowermainspinNiplus5ex();
					z_arr[587] = wspinNiplus5ex * term;
					w_arr[587] = wspinNiplus5ex;}
			}
#pragma omp section
			{
				if(wspinNiplus5ex2){
					term = lowermainspinNiplus5ex2();
					z_arr[588] = wspinNiplus5ex2 * term;
					w_arr[588] = wspinNiplus5ex2;}
			}
#pragma omp section
			{
				if(wspinNiplus4){
					term = lowermainspinNiplus4();
					z_arr[589] = wspinNiplus4 * term;
					w_arr[589] = wspinNiplus4;}
			}
#pragma omp section
			{
				if(wspinNiplus4ex){
					term = lowermainspinNiplus4ex();
					z_arr[590] = wspinNiplus4ex * term;
					w_arr[590] = wspinNiplus4ex;}
			}
#pragma omp section
			{
				if(wspinNiplus4ex2){
					term = lowermainspinNiplus4ex2();
					z_arr[591] = wspinNiplus4ex2 * term;
					w_arr[591] = wspinNiplus4ex2;}
			}
#pragma omp section
			{
				if(wspinNiplus3){
					term = lowermainspinNiplus3();
					z_arr[592] = wspinNiplus3 * term;
					w_arr[592] = wspinNiplus3;}
			}
#pragma omp section
			{
				if(wspinNiplus3ex){
					term = lowermainspinNiplus3ex();
					z_arr[593] = wspinNiplus3ex * term;
					w_arr[593] = wspinNiplus3ex;}
			}
#pragma omp section
			{
				if(wspinNiplus3ex2){
					term = lowermainspinNiplus3ex2();
					z_arr[594] = wspinNiplus3ex2 * term;
					w_arr[594] = wspinNiplus3ex2;}
			}
#pragma omp section
			{
				if(wspinNiplus2){
					term = lowermainspinNiplus2();
					z_arr[595] = wspinNiplus2 * term;
					w_arr[595] = wspinNiplus2;}
			}
#pragma omp section
			{
				if(wspinNiplus2ex){
					term = lowermainspinNiplus2ex();
					z_arr[596] = wspinNiplus2ex * term;
					w_arr[596] = wspinNiplus2ex;}
			}
#pragma omp section
			{
				if(wspinNiplus2ex2){
					term = lowermainspinNiplus2ex2();
					z_arr[597] = wspinNiplus2ex2 * term;
					w_arr[597] = wspinNiplus2ex2;}
			}
#pragma omp section
			{
				if(wspinCuplus10){
					term = lowermainspinCuplus10();
					z_arr[598] = wspinCuplus10 * term;
					w_arr[598] = wspinCuplus10;}
			}
#pragma omp section
			{
				if(wspinCuplus9){
					term = lowermainspinCuplus9();
					z_arr[599] = wspinCuplus9 * term;
					w_arr[599] = wspinCuplus9;}
			}
#pragma omp section
			{
				if(wspinCuplus9ex){
					term = lowermainspinCuplus9ex();
					z_arr[600] = wspinCuplus9ex * term;
					w_arr[600] = wspinCuplus9ex;}
			}
#pragma omp section
			{
				if(wspinCuplus8){
					term = lowermainspinCuplus8();
					z_arr[601] = wspinCuplus8 * term;
					w_arr[601] = wspinCuplus8;}
			}
#pragma omp section
			{
				if(wspinCuplus7){
					term = lowermainspinCuplus7();
					z_arr[602] = wspinCuplus7 * term;
					w_arr[602] = wspinCuplus7;}
			}
#pragma omp section
			{
				if(wspinCuplus6){
					term = lowermainspinCuplus6();
					z_arr[603] = wspinCuplus6 * term;
					w_arr[603] = wspinCuplus6;}
			}
#pragma omp section
			{
				if(wspinCuplus5){
					term = lowermainspinCuplus5();
					z_arr[604] = wspinCuplus5 * term;
					w_arr[604] = wspinCuplus5;}
			}
#pragma omp section
			{
				if(wspinCuplus5ex){
					term = lowermainspinCuplus5ex();
					z_arr[605] = wspinCuplus5ex * term;
					w_arr[605] = wspinCuplus5ex;}
			}
#pragma omp section
			{
				if(wspinCuplus5ex2){
					term = lowermainspinCuplus5ex2();
					z_arr[606] = wspinCuplus5ex2 * term;
					w_arr[606] = wspinCuplus5ex2;}
			}
#pragma omp section
			{
				if(wspinCuplus4){
					term = lowermainspinCuplus4();
					z_arr[607] = wspinCuplus4 * term;
					w_arr[607] = wspinCuplus4;}
			}
#pragma omp section
			{
				if(wspinCuplus4ex){
					term = lowermainspinCuplus4ex();
					z_arr[608] = wspinCuplus4ex * term;
					w_arr[608] = wspinCuplus4ex;}
			}
#pragma omp section
			{
				if(wspinCuplus4ex2){
					term = lowermainspinCuplus4ex2();
					z_arr[609] = wspinCuplus4ex2 * term;
					w_arr[609] = wspinCuplus4ex2;}
			}
#pragma omp section
			{
				if(wspinCuplus3){
					term = lowermainspinCuplus3();
					z_arr[610] = wspinCuplus3 * term;
					w_arr[610] = wspinCuplus3;}
			}
#pragma omp section
			{
				if(wspinCuplus3ex){
					term = lowermainspinCuplus3ex();
					z_arr[611] = wspinCuplus3ex * term;
					w_arr[611] = wspinCuplus3ex;}
			}
#pragma omp section
			{
				if(wspinCuplus3ex2){
					term = lowermainspinCuplus3ex2();
					z_arr[612] = wspinCuplus3ex2 * term;
					w_arr[612] = wspinCuplus3ex2;}
			}
#pragma omp section
			{
				if(wspinCuplus2){
					term = lowermainspinCuplus2();
					z_arr[613] = wspinCuplus2 * term;
					w_arr[613] = wspinCuplus2;}
			}
#pragma omp section
			{
				if(wspinCuplus2ex){
					term = lowermainspinCuplus2ex();
					z_arr[614] = wspinCuplus2ex * term;
					w_arr[614] = wspinCuplus2ex;}
			}
#pragma omp section
			{
				if(wspinCuplus1){
					term = lowermainspinCuplus1();
					z_arr[615] = wspinCuplus1 * term;
					w_arr[615] = wspinCuplus1;}
			}
#pragma omp section
			{
				if(wspinCuplus1ex){
					term = lowermainspinCuplus1ex();
					z_arr[616] = wspinCuplus1ex * term;
					w_arr[616] = wspinCuplus1ex;}
			}
#pragma omp section
			{
				if(wspinYplus2){
					term = lowermainspinYplus2();
					z_arr[617] = wspinYplus2 * term;
					w_arr[617] = wspinYplus2;}
			}
#pragma omp section
			{
				if(wspinZrplus3){
					term = lowermainspinZrplus3();
					z_arr[618] = wspinZrplus3 * term;
					w_arr[618] = wspinZrplus3;}
			}
#pragma omp section
			{
				if(wspinZrplus2){
					term = lowermainspinZrplus2();
					z_arr[619] = wspinZrplus2 * term;
					w_arr[619] = wspinZrplus2;}
			}
#pragma omp section
			{
				if(wspinZrplus2ex){
					term = lowermainspinZrplus2ex();
					z_arr[620] = wspinZrplus2ex * term;
					w_arr[620] = wspinZrplus2ex;}
			}
#pragma omp section
			{
				if(wspinNbplus4){
					term = lowermainspinNbplus4();
					z_arr[621] = wspinNbplus4 * term;
					w_arr[621] = wspinNbplus4;}
			}
#pragma omp section
			{
				if(wspinNbplus3){
					term = lowermainspinNbplus3();
					z_arr[622] = wspinNbplus3 * term;
					w_arr[622] = wspinNbplus3;}
			}
#pragma omp section
			{
				if(wspinNbplus3ex){
					term = lowermainspinNbplus3ex();
					z_arr[623] = wspinNbplus3ex * term;
					w_arr[623] = wspinNbplus3ex;}
			}
#pragma omp section
			{
				if(wspinNbplus2){
					term = lowermainspinNbplus2();
					z_arr[624] = wspinNbplus2 * term;
					w_arr[624] = wspinNbplus2;}
			}
#pragma omp section
			{
				if(wspinNbplus2ex){
					term = lowermainspinNbplus2ex();
					z_arr[625] = wspinNbplus2ex * term;
					w_arr[625] = wspinNbplus2ex;}
			}
#pragma omp section
			{
				if(wspinNbplus1){
					term = lowermainspinNbplus1();
					z_arr[626] = wspinNbplus1 * term;
					w_arr[626] = wspinNbplus1;}
			}
#pragma omp section
			{
				if(wspinNbplus1ex){
					term = lowermainspinNbplus1ex();
					z_arr[627] = wspinNbplus1ex * term;
					w_arr[627] = wspinNbplus1ex;}
			}
#pragma omp section
			{
				if(wspinNbplus1ex2){
					term = lowermainspinNbplus1ex2();
					z_arr[628] = wspinNbplus1ex2 * term;
					w_arr[628] = wspinNbplus1ex2;}
			}
#pragma omp section
			{
				if(wspinMoplus5){
					term = lowermainspinMoplus5();
					z_arr[629] = wspinMoplus5 * term;
					w_arr[629] = wspinMoplus5;}
			}
#pragma omp section
			{
				if(wspinMoplus4){
					term = lowermainspinMoplus4();
					z_arr[630] = wspinMoplus4 * term;
					w_arr[630] = wspinMoplus4;}
			}
#pragma omp section
			{
				if(wspinMoplus4ex){
					term = lowermainspinMoplus4ex();
					z_arr[631] = wspinMoplus4ex * term;
					w_arr[631] = wspinMoplus4ex;}
			}
#pragma omp section
			{
				if(wspinMoplus3){
					term = lowermainspinMoplus3();
					z_arr[632] = wspinMoplus3 * term;
					w_arr[632] = wspinMoplus3;}
			}
#pragma omp section
			{
				if(wspinMoplus3ex){
					term = lowermainspinMoplus3ex();
					z_arr[633] = wspinMoplus3ex * term;
					w_arr[633] = wspinMoplus3ex;}
			}
#pragma omp section
			{
				if(wspinMoplus2){
					term = lowermainspinMoplus2();
					z_arr[634] = wspinMoplus2 * term;
					w_arr[634] = wspinMoplus2;}
			}
#pragma omp section
			{
				if(wspinMoplus2ex){
					term = lowermainspinMoplus2ex();
					z_arr[635] = wspinMoplus2ex * term;
					w_arr[635] = wspinMoplus2ex;}
			}
#pragma omp section
			{
				if(wspinMoplus2ex2){
					term = lowermainspinMoplus2ex2();
					z_arr[636] = wspinMoplus2ex2 * term;
					w_arr[636] = wspinMoplus2ex2;}
			}
#pragma omp section
			{
				if(wspinMoplus1){
					term = lowermainspinMoplus1();
					z_arr[637] = wspinMoplus1 * term;
					w_arr[637] = wspinMoplus1;}
			}
#pragma omp section
			{
				if(wspinMoplus1ex){
					term = lowermainspinMoplus1ex();
					z_arr[638] = wspinMoplus1ex * term;
					w_arr[638] = wspinMoplus1ex;}
			}
#pragma omp section
			{
				if(wspinMoplus1ex2){
					term = lowermainspinMoplus1ex2();
					z_arr[639] = wspinMoplus1ex2 * term;
					w_arr[639] = wspinMoplus1ex2;}
			}
#pragma omp section
			{
				if(wspinTcplus6){
					term = lowermainspinTcplus6();
					z_arr[640] = wspinTcplus6 * term;
					w_arr[640] = wspinTcplus6;}
			}
#pragma omp section
			{
				if(wspinTcplus5){
					term = lowermainspinTcplus5();
					z_arr[641] = wspinTcplus5 * term;
					w_arr[641] = wspinTcplus5;}
			}
#pragma omp section
			{
				if(wspinTcplus4){
					term = lowermainspinTcplus4();
					z_arr[642] = wspinTcplus4 * term;
					w_arr[642] = wspinTcplus4;}
			}
#pragma omp section
			{
				if(wspinTcplus3){
					term = lowermainspinTcplus3();
					z_arr[643] = wspinTcplus3 * term;
					w_arr[643] = wspinTcplus3;}
			}
#pragma omp section
			{
				if(wspinTcplus2){
					term = lowermainspinTcplus2();
					z_arr[644] = wspinTcplus2 * term;
					w_arr[644] = wspinTcplus2;}
			}
#pragma omp section
			{
				if(wspinRuplus7){
					term = lowermainspinRuplus7();
					z_arr[645] = wspinRuplus7 * term;
					w_arr[645] = wspinRuplus7;}
			}
#pragma omp section
			{
				if(wspinRuplus6){
					term = lowermainspinRuplus6();
					z_arr[646] = wspinRuplus6 * term;
					w_arr[646] = wspinRuplus6;}
			}
#pragma omp section
			{
				if(wspinRuplus5){
					term = lowermainspinRuplus5();
					z_arr[647] = wspinRuplus5 * term;
					w_arr[647] = wspinRuplus5;}
			}
#pragma omp section
			{
				if(wspinRuplus4){
					term = lowermainspinRuplus4();
					z_arr[648] = wspinRuplus4 * term;
					w_arr[648] = wspinRuplus4;}
			}
#pragma omp section
			{
				if(wspinRuplus3){
					term = lowermainspinRuplus3();
					z_arr[649] = wspinRuplus3 * term;
					w_arr[649] = wspinRuplus3;}
			}
#pragma omp section
			{
				if(wspinRuplus2){
					term = lowermainspinRuplus2();
					z_arr[650] = wspinRuplus2 * term;
					w_arr[650] = wspinRuplus2;}
			}
#pragma omp section
			{
				if(wspinRuplus2ex){
					term = lowermainspinRuplus2ex();
					z_arr[651] = wspinRuplus2ex * term;
					w_arr[651] = wspinRuplus2ex;}
			}
#pragma omp section
			{
				if(wspinRuplus1){
					term = lowermainspinRuplus1();
					z_arr[652] = wspinRuplus1 * term;
					w_arr[652] = wspinRuplus1;}
			}
#pragma omp section
			{
				if(wspinRuplus1ex){
					term = lowermainspinRuplus1ex();
					z_arr[653] = wspinRuplus1ex * term;
					w_arr[653] = wspinRuplus1ex;}
			}
#pragma omp section
			{
				if(wspinRuplus1ex2){
					term = lowermainspinRuplus1ex2();
					z_arr[654] = wspinRuplus1ex2 * term;
					w_arr[654] = wspinRuplus1ex2;}
			}
#pragma omp section
			{
				if(wspinRhplus8){
					term = lowermainspinRhplus8();
					z_arr[655] = wspinRhplus8 * term;
					w_arr[655] = wspinRhplus8;}
			}
#pragma omp section
			{
				if(wspinRhplus7){
					term = lowermainspinRhplus7();
					z_arr[656] = wspinRhplus7 * term;
					w_arr[656] = wspinRhplus7;}
			}
#pragma omp section
			{
				if(wspinRhplus6){
					term = lowermainspinRhplus6();
					z_arr[657] = wspinRhplus6 * term;
					w_arr[657] = wspinRhplus6;}
			}
#pragma omp section
			{
				if(wspinRhplus5){
					term = lowermainspinRhplus5();
					z_arr[658] = wspinRhplus5 * term;
					w_arr[658] = wspinRhplus5;}
			}
#pragma omp section
			{
				if(wspinRhplus4){
					term = lowermainspinRhplus4();
					z_arr[659] = wspinRhplus4 * term;
					w_arr[659] = wspinRhplus4;}
			}
#pragma omp section
			{
				if(wspinRhplus3){
					term = lowermainspinRhplus3();
					z_arr[660] = wspinRhplus3 * term;
					w_arr[660] = wspinRhplus3;}
			}
#pragma omp section
			{
				if(wspinRhplus2){
					term = lowermainspinRhplus2();
					z_arr[661] = wspinRhplus2 * term;
					w_arr[661] = wspinRhplus2;}
			}
#pragma omp section
			{
				if(wspinRhplus2ex){
					term = lowermainspinRhplus2ex();
					z_arr[662] = wspinRhplus2ex * term;
					w_arr[662] = wspinRhplus2ex;}
			}
#pragma omp section
			{
				if(wspinRhplus2ex2){
					term = lowermainspinRhplus2ex2();
					z_arr[663] = wspinRhplus2ex2 * term;
					w_arr[663] = wspinRhplus2ex2;}
			}
#pragma omp section
			{
				if(wspinRhplus1){
					term = lowermainspinRhplus1();
					z_arr[664] = wspinRhplus1 * term;
					w_arr[664] = wspinRhplus1;}
			}
#pragma omp section
			{
				if(wspinRhplus1ex){
					term = lowermainspinRhplus1ex();
					z_arr[665] = wspinRhplus1ex * term;
					w_arr[665] = wspinRhplus1ex;}
			}
#pragma omp section
			{
				if(wspinRhplus1ex2){
					term = lowermainspinRhplus1ex2();
					z_arr[666] = wspinRhplus1ex2 * term;
					w_arr[666] = wspinRhplus1ex2;}
			}
#pragma omp section
			{
				if(wspinPdplus9){
					term = lowermainspinPdplus9();
					z_arr[667] = wspinPdplus9 * term;
					w_arr[667] = wspinPdplus9;}
			}
#pragma omp section
			{
				if(wspinPdplus8){
					term = lowermainspinPdplus8();
					z_arr[668] = wspinPdplus8 * term;
					w_arr[668] = wspinPdplus8;}
			}
#pragma omp section
			{
				if(wspinPdplus7){
					term = lowermainspinPdplus7();
					z_arr[669] = wspinPdplus7 * term;
					w_arr[669] = wspinPdplus7;}
			}
#pragma omp section
			{
				if(wspinPdplus6){
					term = lowermainspinPdplus6();
					z_arr[670] = wspinPdplus6 * term;
					w_arr[670] = wspinPdplus6;}
			}
#pragma omp section
			{
				if(wspinPdplus5){
					term = lowermainspinPdplus5();
					z_arr[671] = wspinPdplus5 * term;
					w_arr[671] = wspinPdplus5;}
			}
#pragma omp section
			{
				if(wspinPdplus4){
					term = lowermainspinPdplus4();
					z_arr[672] = wspinPdplus4 * term;
					w_arr[672] = wspinPdplus4;}
			}
#pragma omp section
			{
				if(wspinPdplus3){
					term = lowermainspinPdplus3();
					z_arr[673] = wspinPdplus3 * term;
					w_arr[673] = wspinPdplus3;}
			}
#pragma omp section
			{
				if(wspinPdplus2){
					term = lowermainspinPdplus2();
					z_arr[674] = wspinPdplus2 * term;
					w_arr[674] = wspinPdplus2;}
			}
#pragma omp section
			{
				if(wspinPdplus2ex){
					term = lowermainspinPdplus2ex();
					z_arr[675] = wspinPdplus2ex * term;
					w_arr[675] = wspinPdplus2ex;}
			}
#pragma omp section
			{
				if(wspinPdplus2ex2){
					term = lowermainspinPdplus2ex2();
					z_arr[676] = wspinPdplus2ex2 * term;
					w_arr[676] = wspinPdplus2ex2;}
			}
#pragma omp section
			{
				if(wspinPdplus1){
					term = lowermainspinPdplus1();
					z_arr[677] = wspinPdplus1 * term;
					w_arr[677] = wspinPdplus1;}
			}
#pragma omp section
			{
				if(wspinPdplus1ex){
					term = lowermainspinPdplus1ex();
					z_arr[678] = wspinPdplus1ex * term;
					w_arr[678] = wspinPdplus1ex;}
			}
#pragma omp section
			{
				if(wspinPdneutrl){
					term = lowermainspinPdneutrl();
					z_arr[679] = wspinPdneutrl * term;
					w_arr[679] = wspinPdneutrl;}
			}
#pragma omp section
			{
				if(wspinPdneutrlex){
					term = lowermainspinPdneutrlex();
					z_arr[680] = wspinPdneutrlex * term;
					w_arr[680] = wspinPdneutrlex;}
			}
#pragma omp section
			{
				if(wspinAgplus10){
					term = lowermainspinAgplus10();
					z_arr[681] = wspinAgplus10 * term;
					w_arr[681] = wspinAgplus10;}
			}
#pragma omp section
			{
				if(wspinAgplus9){
					term = lowermainspinAgplus9();
					z_arr[682] = wspinAgplus9 * term;
					w_arr[682] = wspinAgplus9;}
			}
#pragma omp section
			{
				if(wspinAgplus8){
					term = lowermainspinAgplus8();
					z_arr[683] = wspinAgplus8 * term;
					w_arr[683] = wspinAgplus8;}
			}
#pragma omp section
			{
				if(wspinAgplus7){
					term = lowermainspinAgplus7();
					z_arr[684] = wspinAgplus7 * term;
					w_arr[684] = wspinAgplus7;}
			}
#pragma omp section
			{
				if(wspinAgplus6){
					term = lowermainspinAgplus6();
					z_arr[685] = wspinAgplus6 * term;
					w_arr[685] = wspinAgplus6;}
			}
#pragma omp section
			{
				if(wspinAgplus5){
					term = lowermainspinAgplus5();
					z_arr[686] = wspinAgplus5 * term;
					w_arr[686] = wspinAgplus5;}
			}
#pragma omp section
			{
				if(wspinAgplus4){
					term = lowermainspinAgplus4();
					z_arr[687] = wspinAgplus4 * term;
					w_arr[687] = wspinAgplus4;}
			}
#pragma omp section
			{
				if(wspinAgplus3){
					term = lowermainspinAgplus3();
					z_arr[688] = wspinAgplus3 * term;
					w_arr[688] = wspinAgplus3;}
			}
#pragma omp section
			{
				if(wspinAgplus2){
					term = lowermainspinAgplus2();
					z_arr[689] = wspinAgplus2 * term;
					w_arr[689] = wspinAgplus2;}
			}
#pragma omp section
			{
				if(wspinAgplus2ex){
					term = lowermainspinAgplus2ex();
					z_arr[690] = wspinAgplus2ex * term;
					w_arr[690] = wspinAgplus2ex;}
			}
#pragma omp section
			{
				if(wspinAgplus1){
					term = lowermainspinAgplus1();
					z_arr[691] = wspinAgplus1 * term;
					w_arr[691] = wspinAgplus1;}
			}
#pragma omp section
			{
				if(wspinAgplus1ex){
					term = lowermainspinAgplus1ex();
					z_arr[692] = wspinAgplus1ex * term;
					w_arr[692] = wspinAgplus1ex;}
			}
#pragma omp section
			{
				if(wspinCdplus11){
					term = lowermainspinCdplus11();
					z_arr[693] = wspinCdplus11 * term;
					w_arr[693] = wspinCdplus11;}
			}
#pragma omp section
			{
				if(wspinCdplus10){
					term = lowermainspinCdplus10();
					z_arr[694] = wspinCdplus10 * term;
					w_arr[694] = wspinCdplus10;}
			}
#pragma omp section
			{
				if(wspinCdplus9){
					term = lowermainspinCdplus9();
					z_arr[695] = wspinCdplus9 * term;
					w_arr[695] = wspinCdplus9;}
			}
#pragma omp section
			{
				if(wspinCdplus8){
					term = lowermainspinCdplus8();
					z_arr[696] = wspinCdplus8 * term;
					w_arr[696] = wspinCdplus8;}
			}
#pragma omp section
			{
				if(wspinCdplus7){
					term = lowermainspinCdplus7();
					z_arr[697] = wspinCdplus7 * term;
					w_arr[697] = wspinCdplus7;}
			}
#pragma omp section
			{
				if(wspinCdplus6){
					term = lowermainspinCdplus6();
					z_arr[698] = wspinCdplus6 * term;
					w_arr[698] = wspinCdplus6;}
			}
#pragma omp section
			{
				if(wspinCdplus5){
					term = lowermainspinCdplus5();
					z_arr[699] = wspinCdplus5 * term;
					w_arr[699] = wspinCdplus5;}
			}
#pragma omp section
			{
				if(wspinCdplus4){
					term = lowermainspinCdplus4();
					z_arr[700] = wspinCdplus4 * term;
					w_arr[700] = wspinCdplus4;}
			}
#pragma omp section
			{
				if(wspinCdplus3){
					term = lowermainspinCdplus3();
					z_arr[701] = wspinCdplus3 * term;
					w_arr[701] = wspinCdplus3;}
			}
#pragma omp section
			{
				if(wspinCdplus3ex){
					term = lowermainspinCdplus3ex();
					z_arr[702] = wspinCdplus3ex * term;
					w_arr[702] = wspinCdplus3ex;}
			}
#pragma omp section
			{
				if(wspinCdplus2){
					term = lowermainspinCdplus2();
					z_arr[703] = wspinCdplus2 * term;
					w_arr[703] = wspinCdplus2;}
			}
#pragma omp section
			{
				if(wspinCdplus2ex){
					term = lowermainspinCdplus2ex();
					z_arr[704] = wspinCdplus2ex * term;
					w_arr[704] = wspinCdplus2ex;}
			}
#pragma omp section
			{
				if(wspinCuneutrl){
					term = lowermainspinCuneutrl();
					z_arr[709] = wspinCuneutrl * term;
					w_arr[709] = wspinCuneutrl;}
			}
#pragma omp section
			{
				if(wspinCuneutrlex){
					term = lowermainspinCuneutrlex();
					z_arr[710] = wspinCuneutrlex * term;
					w_arr[710] = wspinCuneutrlex;}
			}
#pragma omp section
			{
				if(wspinNiplus1){
					term = lowermainspinNiplus1();
					z_arr[711] = wspinNiplus1 * term;
					w_arr[711] = wspinNiplus1;}
			}
#pragma omp section
			{
				if(wspinNiplus1ex){
					term = lowermainspinNiplus1ex();
					z_arr[712] = wspinNiplus1ex * term;
					w_arr[712] = wspinNiplus1ex;}
			}
#pragma omp section
			{
				if(wspinNineutrl){
					term = lowermainspinNineutrl();
					z_arr[713] = wspinNineutrl * term;
					w_arr[713] = wspinNineutrl;}
			}
#pragma omp section
			{
				if(wspinNineutrlex){
					term = lowermainspinNineutrlex();
					z_arr[714] = wspinNineutrlex * term;
					w_arr[714] = wspinNineutrlex;}
			}
#pragma omp section
			{
				if(wspinCoplus1){
					term = lowermainspinCoplus1();
					z_arr[715] = wspinCoplus1 * term;
					w_arr[715] = wspinCoplus1;}
			}
#pragma omp section
			{
				if(wspinCoplus1ex){
					term = lowermainspinCoplus1ex();
					z_arr[716] = wspinCoplus1ex * term;
					w_arr[716] = wspinCoplus1ex;}
			}
#pragma omp section
			{
				if(wspinCoplus1ex2){
					term = lowermainspinCoplus1ex2();
					z_arr[717] = wspinCoplus1ex2 * term;
					w_arr[717] = wspinCoplus1ex2;}
			}
#pragma omp section
			{
				if(wspinConeutrl){
					term = lowermainspinConeutrl();
					z_arr[718] = wspinConeutrl * term;
					w_arr[718] = wspinConeutrl;}
			}
#pragma omp section
			{
				if(wspinConeutrlex){
					term = lowermainspinConeutrlex();
					z_arr[719] = wspinConeutrlex * term;
					w_arr[719] = wspinConeutrlex;}
			}
#pragma omp section
			{
				if(wspinFeplus1){
					term = lowermain(Feplus1);
					z_arr[720] = wspinFeplus1 * term;
					w_arr[720] = wspinFeplus1;}
			}
#pragma omp section
			{
				if(wspinFeplus1ex){
					term = lowermain(Feplus1ex);
					z_arr[721] = wspinFeplus1ex * term;
					w_arr[721] = wspinFeplus1ex;}
			}
#pragma omp section
			{
				if(wspinFeplus1ex2){
					term = lowermain(Feplus1ex2);
					z_arr[722] = wspinFeplus1ex2 * term;
					w_arr[722] = wspinFeplus1ex2;}
			}
#pragma omp section
			{
				if(wspinFeneutrl){
					term = lowermain(Feneutrl);
					z_arr[723] = wspinFeneutrl * term;
					w_arr[723] = wspinFeneutrl;}
			}
#pragma omp section
			{
				if(wspinFeneutrlex){
					term = lowermain(Feneutrlex);
					z_arr[724] = wspinFeneutrlex * term;
					w_arr[724] = wspinFeneutrlex;}
			}
#pragma omp section
			{
				if(wspinFeneutrlex2){
					term = lowermain(Feneutrlex2);
					z_arr[725] = wspinFeneutrlex2 * term;
					w_arr[725] = wspinFeneutrlex2;}
			}
#pragma omp section
			{
				if(wspinFeneutrlex3){
					term = lowermain(Feneutrlex3);
					z_arr[726] = wspinFeneutrlex3 * term;
					w_arr[726] = wspinFeneutrlex3;}
			}
#pragma omp section
			{
				if(wspinMnplus1){
					term = lowermainspinMnplus1();
					z_arr[727] = wspinMnplus1 * term;
					w_arr[727] = wspinMnplus1;}
			}
#pragma omp section
			{
				if(wspinMnplus1ex){
					term = lowermainspinMnplus1ex();
					z_arr[728] = wspinMnplus1ex * term;
					w_arr[728] = wspinMnplus1ex;}
			}
#pragma omp section
			{
				if(wspinMnplus1ex2){
					term = lowermainspinMnplus1ex2();
					z_arr[729] = wspinMnplus1ex2 * term;
					w_arr[729] = wspinMnplus1ex2;}
			}
#pragma omp section
			{
				if(wspinMnplus1ex3){
					term = lowermainspinMnplus1ex3();
					z_arr[730] = wspinMnplus1ex3 * term;
					w_arr[730] = wspinMnplus1ex3;}
			}
#pragma omp section
			{
				if(wspinMnneutrl){
					term = lowermainspinMnneutrl();
					z_arr[731] = wspinMnneutrl * term;
					w_arr[731] = wspinMnneutrl;}
			}
#pragma omp section
			{
				if(wspinMnneutrlex){
					term = lowermainspinMnneutrlex();
					z_arr[732] = wspinMnneutrlex * term;
					w_arr[732] = wspinMnneutrlex;}
			}
#pragma omp section
			{
				if(wspinMnneutrlex2){
					term = lowermainspinMnneutrlex2();
					z_arr[733] = wspinMnneutrlex2 * term;
					w_arr[733] = wspinMnneutrlex2;}
			}
#pragma omp section
			{
				if(wspinMnneutrlex3){
					term = lowermainspinMnneutrlex3();
					z_arr[734] = wspinMnneutrlex3 * term;
					w_arr[734] = wspinMnneutrlex3;}
			}
#pragma omp section
			{
				if(wspinCrneutrl){
					term = lowermainspinCrneutrl();
					z_arr[735] = wspinCrneutrl * term;
					w_arr[735] = wspinCrneutrl;}
			}
#pragma omp section
			{
				if(wspinCrneutrlex){
					term = lowermainspinCrneutrlex();
					z_arr[736] = wspinCrneutrlex * term;
					w_arr[736] = wspinCrneutrlex;}
			}
#pragma omp section
			{
				if(wspinCrneutrlex2){
					term = lowermainspinCrneutrlex2();
					z_arr[737] = wspinCrneutrlex2 * term;
					w_arr[737] = wspinCrneutrlex2;}
			}
#pragma omp section
			{
				if(wspinCrneutrlex3){
					term = lowermainspinCrneutrlex3();
					z_arr[738] = wspinCrneutrlex3 * term;
					w_arr[738] = wspinCrneutrlex3;}
			}
#pragma omp section
			{
				if(wspinVplus1){
					term = lowermainspinVplus1();
					z_arr[739] = wspinVplus1 * term;
					w_arr[739] = wspinVplus1;}
			}
#pragma omp section
			{
				if(wspinVplus1ex){
					term = lowermainspinVplus1ex();
					z_arr[740] = wspinVplus1ex * term;
					w_arr[740] = wspinVplus1ex;}
			}
#pragma omp section
			{
				if(wspinVplus1ex2){
					term = lowermainspinVplus1ex2();
					z_arr[741] = wspinVplus1ex2 * term;
					w_arr[741] = wspinVplus1ex2;}
			}
#pragma omp section
			{
				if(wspinVneutrl){
					term = lowermainspinVneutrl();
					z_arr[742] = wspinVneutrl * term;
					w_arr[742] = wspinVneutrl;}
			}
#pragma omp section
			{
				if(wspinVneutrlex){
					term = lowermainspinVneutrlex();
					z_arr[743] = wspinVneutrlex * term;
					w_arr[743] = wspinVneutrlex;}
			}
#pragma omp section
			{
				if(wspinVneutrlex2){
					term = lowermainspinVneutrlex2();
					z_arr[744] = wspinVneutrlex2 * term;
					w_arr[744] = wspinVneutrlex2;}
			}
#pragma omp section
			{
				if(wspinTiplus1){
					term = lowermainspinTiplus1();
					z_arr[745] = wspinTiplus1 * term;
					w_arr[745] = wspinTiplus1;}
			}
#pragma omp section
			{
				if(wspinTiplus1ex){
					term = lowermainspinTiplus1ex();
					z_arr[746] = wspinTiplus1ex * term;
					w_arr[746] = wspinTiplus1ex;}
			}
#pragma omp section
			{
				if(wspinTineutrl){
					term = lowermainspinTineutrl();
					z_arr[747] = wspinTineutrl * term;
					w_arr[747] = wspinTineutrl;}
			}
#pragma omp section
			{
				if(wspinTineutrlex){
					term = lowermainspinTineutrlex();
					z_arr[748] = wspinTineutrlex * term;
					w_arr[748] = wspinTineutrlex;}
			}
#pragma omp section
			{
				if(wspinTineutrlex2){
					term = lowermainspinTineutrlex2();
					z_arr[749] = wspinTineutrlex2 * term;
					w_arr[749] = wspinTineutrlex2;}
			}
#pragma omp section
			{
				if(wspinScplus1){
					term = lowermainspinScplus1();
					z_arr[750] = wspinScplus1 * term;
					w_arr[750] = wspinScplus1;}
			}
#pragma omp section
			{
				if(wspinScplus1ex){
					term = lowermainspinScplus1ex();
					z_arr[751] = wspinScplus1ex * term;
					w_arr[751] = wspinScplus1ex;}
			}
#pragma omp section
			{
				if(wspinScneutrl){
					term = lowermainspinScneutrl();
					z_arr[752] = wspinScneutrl * term;
					w_arr[752] = wspinScneutrl;}
			}
#pragma omp section
			{
				if(wspinScneutrlex){
					term = lowermainspinScneutrlex();
					z_arr[753] = wspinScneutrlex * term;
					w_arr[753] = wspinScneutrlex;}
			}
#pragma omp section
			{
				if(wspinCdplus1){
					term = lowermainspinCdplus1();
					z_arr[754] = wspinCdplus1 * term;
					w_arr[754] = wspinCdplus1;}
			}
#pragma omp section
			{
				if(wspinCdplus1ex){
					term = lowermainspinCdplus1ex();
					z_arr[755] = wspinCdplus1ex * term;
					w_arr[755] = wspinCdplus1ex;}
			}
#pragma omp section
			{
				if(wspinCdneutrl){
					term = lowermainspinCdneutrl();
					z_arr[756] = wspinCdneutrl * term;
					w_arr[756] = wspinCdneutrl;}
			}
#pragma omp section
			{
				if(wspinCdneutrlex){
					term = lowermainspinCdneutrlex();
					z_arr[757] = wspinCdneutrlex * term;
					w_arr[757] = wspinCdneutrlex;}
			}
#pragma omp section
			{
				if(wspinAgneutrl){
					term = lowermainspinAgneutrl();
					z_arr[758] = wspinAgneutrl * term;
					w_arr[758] = wspinAgneutrl;}
			}
#pragma omp section
			{
				if(wspinAgneutrlex){
					term = lowermainspinAgneutrlex();
					z_arr[759] = wspinAgneutrlex * term;
					w_arr[759] = wspinAgneutrlex;}
			}
#pragma omp section
			{
				if(wspinRhneutrl){
					term = lowermainspinRhneutrl();
					z_arr[760] = wspinRhneutrl * term;
					w_arr[760] = wspinRhneutrl;}
			}
#pragma omp section
			{
				if(wspinRhneutrlex){
					term = lowermainspinRhneutrlex();
					z_arr[761] = wspinRhneutrlex * term;
					w_arr[761] = wspinRhneutrlex;}
			}
#pragma omp section
			{
				if(wspinRuneutrl){
					term = lowermainspinRuneutrl();
					z_arr[762] = wspinRuneutrl * term;
					w_arr[762] = wspinRuneutrl;}
			}
#pragma omp section
			{
				if(wspinRuneutrlex){
					term = lowermainspinRuneutrlex();
					z_arr[763] = wspinRuneutrlex * term;
					w_arr[763] = wspinRuneutrlex;}
			}
#pragma omp section
			{
				if(wspinRuneutrlex2){
					term = lowermainspinRuneutrlex2();
					z_arr[764] = wspinRuneutrlex2 * term;
					w_arr[764] = wspinRuneutrlex2;}
			}
#pragma omp section
			{
				if(wspinTcplus1){
					term = lowermainspinTcplus1();
					z_arr[765] = wspinTcplus1 * term;
					w_arr[765] = wspinTcplus1;}
			}
#pragma omp section
			{
				if(wspinTcplus1ex){
					term = lowermainspinTcplus1ex();
					z_arr[766] = wspinTcplus1ex * term;
					w_arr[766] = wspinTcplus1ex;}
			}
#pragma omp section
			{
				if(wspinTcneutrl){
					term = lowermainspinTcneutrl();
					z_arr[767] = wspinTcneutrl * term;
					w_arr[767] = wspinTcneutrl;}
			}
#pragma omp section
			{
				if(wspinTcneutrlex){
					term = lowermainspinTcneutrlex();
					z_arr[768] = wspinTcneutrlex * term;
					w_arr[768] = wspinTcneutrlex;}
			}
#pragma omp section
			{
				if(wspinTcneutrlex2){
					term = lowermainspinTcneutrlex2();
					z_arr[769] = wspinTcneutrlex2 * term;
					w_arr[769] = wspinTcneutrlex2;}
			}
#pragma omp section
			{
				if(wspinTcneutrlex3){
					term = lowermainspinTcneutrlex3();
					z_arr[770] = wspinTcneutrlex3 * term;
					w_arr[770] = wspinTcneutrlex3;}
			}
#pragma omp section
			{
				if(wspinMoneutrl){
					term = lowermainspinMoneutrl();
					z_arr[771] = wspinMoneutrl * term;
					w_arr[771] = wspinMoneutrl;}
			}
#pragma omp section
			{
				if(wspinMoneutrlex){
					term = lowermainspinMoneutrlex();
					z_arr[772] = wspinMoneutrlex * term;
					w_arr[772] = wspinMoneutrlex;}
			}
#pragma omp section
			{
				if(wspinMoneutrlex2){
					term = lowermainspinMoneutrlex2();
					z_arr[773] = wspinMoneutrlex2 * term;
					w_arr[773] = wspinMoneutrlex2;}
			}
#pragma omp section
			{
				if(wspinMoneutrlex3){
					term = lowermainspinMoneutrlex3();
					z_arr[774] = wspinMoneutrlex3 * term;
					w_arr[774] = wspinMoneutrlex3;}
			}
#pragma omp section
			{
				if(wspinNbneutrl){
					term = lowermainspinNbneutrl();
					z_arr[775] = wspinNbneutrl * term;
					w_arr[775] = wspinNbneutrl;}
			}
#pragma omp section
			{
				if(wspinNbneutrlex){
					term = lowermainspinNbneutrlex();
					z_arr[776] = wspinNbneutrlex * term;
					w_arr[776] = wspinNbneutrlex;}
			}
#pragma omp section
			{
				if(wspinNbneutrlex2){
					term = lowermainspinNbneutrlex2();
					z_arr[777] = wspinNbneutrlex2 * term;
					w_arr[777] = wspinNbneutrlex2;}
			}
#pragma omp section
			{
				if(wspinZrplus1){
					term = lowermainspinZrplus1();
					z_arr[778] = wspinZrplus1 * term;
					w_arr[778] = wspinZrplus1;}
			}
#pragma omp section
			{
				if(wspinZrplus1ex){
					term = lowermainspinZrplus1ex();
					z_arr[779] = wspinZrplus1ex * term;
					w_arr[779] = wspinZrplus1ex;}
			}
#pragma omp section
			{
				if(wspinZrneutrl){
					term = lowermainspinZrneutrl();
					z_arr[780] = wspinZrneutrl * term;
					w_arr[780] = wspinZrneutrl;}
			}
#pragma omp section
			{
				if(wspinZrneutrlex){
					term = lowermainspinZrneutrlex();
					z_arr[781] = wspinZrneutrlex * term;
					w_arr[781] = wspinZrneutrlex;}
			}
#pragma omp section
			{
				if(wspinZrneutrlex2){
					term = lowermainspinZrneutrlex2();
					z_arr[782] = wspinZrneutrlex2 * term;
					w_arr[782] = wspinZrneutrlex2;}
			}
#pragma omp section
			{
				if(wspinYplus1){
					term = lowermainspinYplus1();
					z_arr[783] = wspinYplus1 * term;
					w_arr[783] = wspinYplus1;}
			}
#pragma omp section
			{
				if(wspinYplus1ex){
					term = lowermainspinYplus1ex();
					z_arr[784] = wspinYplus1ex * term;
					w_arr[784] = wspinYplus1ex;}
			}
#pragma omp section
			{
				if(wspinYneutrl){
					term = lowermainspinYneutrl();
					z_arr[785] = wspinYneutrl * term;
					w_arr[785] = wspinYneutrl;}
			}
#pragma omp section
			{
				if(wspinYneutrlex){
					term = lowermainspinYneutrlex();
					z_arr[786] = wspinYneutrlex * term;
					w_arr[786] = wspinYneutrlex;}
			}
		}

//#pragma omp sections
//		{ //Put a compound here only when absolutely necessary
//#pragma omp section
//			{
//				if (wspinZundel) {
//					term = lowermainspinZundel(); //205
//					z_arr[205] = wspinZundel * term;
//					w_arr[205] = wspinZundel;
//				}
//			}
//#pragma omp section
//			{
//				if (wspinDeprotonatedDimer){
//					term = lowermainspinDeprotonatedDimer();//206
//					z_arr[206] = wspinDeprotonatedDimer * term;
//					w_arr[206] = wspinDeprotonatedDimer;
//				}
//			}
//#pragma omp section
//			{
//				if (wspinH4O2){
//					term = lowermainspindimer();//207
//					z_arr[207] = wspinH4O2 * term;
//					w_arr[207] = wspinH4O2;
//				}
//			}
//		}

#pragma omp sections
		{
//#pragma omp section
//                        {
//                                if(wspinO2_linnett){
//                                        term = lowermain(O2_linnett);//787
//                                        z_arr[787] = wspinO2_linnett * term;
//                                        w_arr[787] = wspinO2_linnett;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2_snglbnd){
//                                        term = lowermain(O2_snglbnd);//788
//                                        z_arr[788] = wspinO2_snglbnd * term;
//                                        w_arr[788] = wspinO2_snglbnd;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2_dblbnd){
//                                        term = lowermain(O2_dblbnd);//789
//                                        z_arr[789] = wspinO2_dblbnd * term;
//                                        w_arr[789] = wspinO2_dblbnd;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2_trplbnd){
//                                        term = lowermain(O2_trplbnd);//790
//                                        z_arr[790] = wspinO2_trplbnd * term;
//                                        w_arr[790] = wspinO2_trplbnd;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2dia_linnett){
//                                        term = lowermain(O2dia_linnett);//791
//                                        z_arr[791] = wspinO2dia_linnett * term;
//                                        w_arr[791] = wspinO2dia_linnett;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2dia_snglbnd){
//                                        term = lowermain(O2dia_snglbnd);//792
//                                        z_arr[792] = wspinO2dia_snglbnd * term;
//                                        w_arr[792] = wspinO2dia_snglbnd;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2dia_dblbnd){
//                                        term = lowermain(O2dia_dblbnd);//793
//                                        z_arr[793] = wspinO2dia_dblbnd * term;
//                                        w_arr[793] = wspinO2dia_dblbnd;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2dia_trplbnd){
//                                        term = lowermain(O2dia_trplbnd);//794
//                                        z_arr[794] = wspinO2dia_trplbnd * term;
//                                        w_arr[794] = wspinO2dia_trplbnd;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2qnt_linnett){
//                                        term = lowermain(O2qnt_linnett);//795
//                                        z_arr[795] = wspinO2qnt_linnett * term;
//                                        w_arr[795] = wspinO2qnt_linnett;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2qnt_snglbnd){
//                                        term = lowermain(O2qnt_snglbnd);//796
//                                        z_arr[796] = wspinO2qnt_snglbnd * term;
//                                        w_arr[796] = wspinO2qnt_snglbnd;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2qnt_dblbnd){
//                                        term = lowermain(O2qnt_dblbnd);//797
//                                        z_arr[797] = wspinO2qnt_dblbnd * term;
//                                        w_arr[797] = wspinO2qnt_dblbnd;}
//                        }
//#pragma omp section
//                        {
//                                if(wspinO2qnt_trplbnd){
//                                        term = lowermain(O2qnt_trplbnd);//798
//                                        z_arr[798] = wspinO2qnt_trplbnd * term;
//                                        w_arr[798] = wspinO2qnt_trplbnd;}
//                        }
#pragma omp section
			{
				if (wTransitionspinH2) {
					term = lowermainTransitionspinH2();//492
					z_arr[492] = wTransitionspinH2 * term;
					w_arr[492] = wTransitionspinH2;
				}
			}
#pragma omp section
			{
				if (wTransitionspinH2plus) {
					term = lowermainTransitionspinH2plus();//493
					z_arr[493] = wTransitionspinH2plus * term;
					w_arr[493] = wTransitionspinH2plus;
				}
			}
#pragma omp section
			{
				if (wTransitiontripletH2) {
					term = lowermainTransitiontripletH2();//494
					z_arr[494] = wTransitiontripletH2 * term;
					w_arr[494] = wTransitiontripletH2;
				}
			}
#pragma omp section
			{
				if (wTransitionspinH2minus){
					term = lowermainTransitionspinH2minus();//495
					z_arr[495] = wTransitionspinH2minus * term;
					w_arr[495] = wTransitionspinH2minus;
				}
			}
#pragma omp section
			{
				if (wTransitionspinOHdot){
					term = lowermainTransitionspinOHdot();//496
					z_arr[496] = wTransitionspinOHdot * term;
					w_arr[496] = wTransitionspinOHdot;
				}
			}
#pragma omp section
			{
				if (wTransitionspinOHdot2){
					term = lowermainTransitionspinOHdot2();//497
					z_arr[497] = wTransitionspinOHdot2 * term;
					w_arr[497] = wTransitionspinOHdot2;
				}
			}
#pragma omp section
			{
				if (wTransitionspinOH){
					term = lowermainTransitionspinOH();//498
					z_arr[498]= wTransitionspinOH * term;
					w_arr[498]= wTransitionspinOH;
				}
			}
#pragma omp section 
			{
				if (wspinThermo) {
					devspinThermo = spinthermo();
//					printf("z is %f. wspinThermo is %f, deviation of spinthermo is %f\n", wspinThermo*devspinThermo, wspinThermo, devspinThermo);
					z_arr[491] = wspinThermo*devspinThermo;
					w_arr[491] = wspinThermo;
				}
			}

		}
	}
	//printf("status went through each molecule\n");
	double zfinal;
	double w = 0;
	double z = 0;

	//NOW DO SUMS ACROSS THE ARRAYS
	for (i=0;i<=6;i++){ //
		z+=z_arr[i];
		w+=w_arr[i];
	}
	for (i=200;i<=209;i++){
		z+=z_arr[i];
		w+=w_arr[i];
	}
        //This was just for debug
//      printf("1) z = %lf ; w = %lf \n",z,w);
	devOHydrideStruct = 0. ; //FRA z/w; //weighted MAD of O hydride structures for main.c printout

	z=0.0;
	w=0.0;
	for (i=0;i<=90;i++){ //∑0,90 (at #91, non-structural deviations begin)
		z+=z_arr[i];
//		printf("deviation value for i %d is %f\n",i, z_arr[i]);
		w+=w_arr[i];
	}
	for (i=200;i<=490;i++){
		z+=z_arr[i];
//		printf("deviation value for i %d is %f\n",i, z_arr[i]);
		w+=w_arr[i];
	}
	for (i=492;i<=798;i++){
		z+=z_arr[i];
//		printf("deviation value for i %d is %f\n",i, z_arr[i]);
		w+=w_arr[i];
	}
        //This was just for debug
//      printf("2) z = %lf ; w = %lf \n",z,w);
	zStructfinal = z/w;   //weighted MAD of all structures for main.c printout

//	z=0.0;
//	w=0.0;
//	for (i=0;i<=34;i++){ //∑0,34
//		z+=z_arr[i];
//		w+=w_arr[i];
//	}
//	for (i=200;i<=490;i++){
//		z+=z_arr[i];
//		w+=w_arr[i];
//	}
//	for (i=787;i<=798;i++){
//		z+=z_arr[i];
//		w+=w_arr[i];
//	}
//        //This was just for debug
//        //printf("3) z = %lf ; w = %lf \n",z,w);
//	devNCOHydrideStruct = z/w; //weighted MAD of N, C, O hydride structures for main.c printout

	z=0.0;
	w=0.0;
	for (i=0;i<total;i++){
		z+=z_arr[i];
                //This was just for debug
//              printf ( "i = %d , zarr = %lf \n",i,z_arr[i]) ;
		w+=w_arr[i];			
//		printf(" deviation is %f weight is %f for the index %d\n",z_arr[i],w_arr[i],i);
	}
        //This was just for debug
//	printf("4) z = %lf ; w = %lf \n",z,w);
	zfinal = (z/w);  //weighted MAD of all features
	totaldev = (z/w)*100; //total deviation in percent
	totalweight = w;
//	printf("exiting status\n");
//	printf("final weighted status dev is %f\n",zfinal);
	return zfinal;
}



