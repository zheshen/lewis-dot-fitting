
/*
 *  Common.h
 *  Water9.0REV
 *
 *  Created by Mike on 1/20/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.

 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include <string.h>
#include <memory.h>
#include <complex.h>

//FRA's help with parallelization
//#define MAX_POSSIBLE_THREADS  512
//unsigned int myseeds[MAX_POSSIBLE_THREADS] ;
//float drnd_r(unsigned int *myseed);
//void init_rng();
//  

//Particle structure definition 
//typedef struct V{double x,y,z,d,q; int s;}V; 

//PERMISSIONS=======================
#define FIT_AB_AH		0.0
#define FIT_AA_AH		0.0
#define FIT_H3H4                0.0 //for cancel out H3 H4 with AA 
#define FIT_spinO		0.0
#define FIT_spinOO		0.0 //for O-O distance changing
#define FIT_spinO2		0.0
#define FIT_spinO3		0.0
#define FIT_spinH		0.0
#define FIT_spinHH              0.0
#define FIT_spinC		0.0
#define FIT_spinN               0.0
#define FIT_spinP               0.0
#define FIT_spinS               0.0
#define FIT_spinF		0.0
#define FIT_spinSi              0.0
#define FIT_spinBo		0.0
#define FIT_spinAl		0.0
#define FIT_spinCl		0.0
#define FIT_spinNa		0.0
#define FIT_spinLi		0.0
#define FIT_spinBe		0.0
#define FIT_spinMg		0.0
#define FIT_spinZn              1.0
#define FIT_spinSc		0.0
#define FIT_spinTi		0.0
#define FIT_spinV		0.0
#define FIT_spinCr		0.0
#define FIT_spinMn		0.0
#define FIT_spinFe		0.0
#define FIT_spinCo		0.0
#define FIT_spinNi		0.0
#define FIT_spinCu		0.0
#define FIT_spinY		0.0
#define FIT_spinZr		0.0
#define FIT_spinNb		0.0
#define FIT_spinMo		0.0
#define FIT_spinTc		0.0
#define FIT_spinRu		0.0
#define FIT_spinRh		0.0
#define FIT_spinPd		0.0
#define FIT_spinAg		0.0
#define FIT_spinCd		0.0
#define FIT_spinOH		0.0
#define FIT_dimer		0.0
#define FIT_spinthermo		1.0
#define FIT_transition		0.0
#define FIT_spinEE		1.0
#define FIT_spinE		1.0
#define FIT_triplet		0.0
#define FIT_ion			1.0
#define FIT_ex			1.0
#define FIT_polar		1.0//1.0
#define FIT_SpinSym             1.0//1.0
#define FIT_diat		0.0
#define fix_d			0.0
#define FIT_SCALE               0.0
#define d_value			0.70710678

//Monte Carlo parameters------------
#define MC_STEPS                80000
#define MC_small_step            0.002
#define MC_rigid_step            0.008
#define MC_angle_step            0.010
#define MC_radius_step           0.20000
#define MC_TEMP                  100
#define MC_R2_MAX                0.25
#define MC_D_INIT               3.0// 0.60
#define MC_numDynamicVar	6

#define MC_ALL                    ON

#define MC_spinDielectron              ON*MC_ALL
#define MC_spinDielectronex            ON*MC_ALL

#define MC_spinO2qnt			ON*MC_ALL
#define MC_spinO2qnt_linnett		ON*MC_ALL
#define MC_spinO2qnt_snglbnd		ON*MC_ALL
#define MC_spinO2qnt_dblbnd		ON*MC_ALL
#define MC_spinO2qnt_trplbnd		ON*MC_ALL
#define MC_spinO2plus1			ON*MC_ALL
#define MC_spinO2_1			ON*MC_ALL
#define MC_spinO3_linnett		ON*MC_ALL
#define MC_spinO3trp_linnett		ON*MC_ALL

#define MC_spinB2_snglt_linnett                 ON*MC_ALL
#define MC_spinB2_snglt_snglbnd                 ON*MC_ALL
#define MC_spinB2_snglt_dblbnd                 ON*MC_ALL
#define MC_spinB2_snglt_trplbnd                 ON*MC_ALL
#define MC_spinB2_trplt_linnett                 ON*MC_ALL
#define MC_spinB2_trplt_snglbnd                 ON*MC_ALL
#define MC_spinB2_trplt_dblbnd                 ON*MC_ALL
#define MC_spinB2_trplt_trplbnd                 ON*MC_ALL
#define MC_spinAl2_snglt_linnett                 ON*MC_ALL
#define MC_spinAl2_snglt_snglbnd                 ON*MC_ALL
#define MC_spinAl2_snglt_dblbnd                 ON*MC_ALL
#define MC_spinAl2_snglt_trplbnd                 ON*MC_ALL
#define MC_spinAl2_trplt_linnett                 ON*MC_ALL
#define MC_spinAl2_trplt_snglbnd                 ON*MC_ALL
#define MC_spinAl2_trplt_dblbnd                 ON*MC_ALL
#define MC_spinAl2_trplt_trplbnd                 ON*MC_ALL
#define MC_spinC2_snglt_linnett                 ON*MC_ALL
#define MC_spinC2_snglt_snglbnd                 ON*MC_ALL
#define MC_spinC2_snglt_dblbnd                 ON*MC_ALL
#define MC_spinC2_snglt_trplbnd                 ON*MC_ALL
#define MC_spinC2_trplt_linnett                 ON*MC_ALL
#define MC_spinC2_trplt_snglbnd                 ON*MC_ALL
#define MC_spinC2_trplt_dblbnd                 ON*MC_ALL
#define MC_spinC2_trplt_trplbnd                 ON*MC_ALL
#define MC_spinSi2_snglt_linnett                 ON*MC_ALL
#define MC_spinSi2_snglt_snglbnd                 ON*MC_ALL
#define MC_spinSi2_snglt_dblbnd                 ON*MC_ALL
#define MC_spinSi2_snglt_trplbnd                 ON*MC_ALL
#define MC_spinSi2_trplt_linnett                 ON*MC_ALL
#define MC_spinSi2_trplt_snglbnd                 ON*MC_ALL
#define MC_spinSi2_trplt_dblbnd                 ON*MC_ALL
#define MC_spinSi2_trplt_trplbnd                 ON*MC_ALL
#define MC_spinN2_snglt_linnett                 ON*MC_ALL
#define MC_spinN2_snglt_snglbnd                 ON*MC_ALL
#define MC_spinN2_snglt_dblbnd                 ON*MC_ALL
#define MC_spinN2_snglt_trplbnd                 ON*MC_ALL
#define MC_spinN2_trplt_linnett                 ON*MC_ALL
#define MC_spinN2_trplt_snglbnd                 ON*MC_ALL
#define MC_spinN2_trplt_dblbnd                 ON*MC_ALL
#define MC_spinN2_trplt_trplbnd                 ON*MC_ALL
#define MC_spinP2_snglt_linnett                 ON*MC_ALL
#define MC_spinP2_snglt_snglbnd                 ON*MC_ALL
#define MC_spinP2_snglt_dblbnd                 ON*MC_ALL
#define MC_spinP2_snglt_trplbnd                 ON*MC_ALL
#define MC_spinP2_trplt_linnett                 ON*MC_ALL
#define MC_spinP2_trplt_snglbnd                 ON*MC_ALL
#define MC_spinP2_trplt_dblbnd                 ON*MC_ALL
#define MC_spinP2_trplt_trplbnd                 ON*MC_ALL
#define MC_spinS2_snglt_linnett                 ON*MC_ALL
#define MC_spinS2_snglt_snglbnd                 ON*MC_ALL
#define MC_spinS2_snglt_dblbnd                 ON*MC_ALL
#define MC_spinS2_snglt_trplbnd                 ON*MC_ALL
#define MC_spinS2_trplt_linnett                 ON*MC_ALL
#define MC_spinS2_trplt_snglbnd                 ON*MC_ALL
#define MC_spinS2_trplt_dblbnd                 ON*MC_ALL
#define MC_spinS2_trplt_trplbnd                 ON*MC_ALL
#define MC_spinF2_snglt_linnett                 ON*MC_ALL
#define MC_spinF2_snglt_snglbnd                 ON*MC_ALL
#define MC_spinF2_snglt_dblbnd                 ON*MC_ALL
#define MC_spinF2_snglt_trplbnd                 ON*MC_ALL
#define MC_spinF2_trplt_linnett                 ON*MC_ALL
#define MC_spinF2_trplt_snglbnd                 ON*MC_ALL
#define MC_spinF2_trplt_dblbnd                 ON*MC_ALL
#define MC_spinF2_trplt_trplbnd                 ON*MC_ALL
#define MC_spinCl2_snglt_linnett                 ON*MC_ALL
#define MC_spinCl2_snglt_snglbnd                 ON*MC_ALL
#define MC_spinCl2_snglt_dblbnd                 ON*MC_ALL
#define MC_spinCl2_snglt_trplbnd                 ON*MC_ALL
#define MC_spinCl2_trplt_linnett                 ON*MC_ALL
#define MC_spinCl2_trplt_snglbnd                 ON*MC_ALL
#define MC_spinCl2_trplt_dblbnd                 ON*MC_ALL
#define MC_spinCl2_trplt_trplbnd                 ON*MC_ALL

#define MC_spinH_polar		ON*MC_ALL
#define MC_spinBneutrl_polar           ON*MC_ALL
#define MC_spinCneutrl_polar           ON*MC_ALL
#define MC_spinNneutrl_polar           ON*MC_ALL
#define MC_spinOneutrl_polar           ON*MC_ALL
#define MC_spinFneutrl_polar           ON*MC_ALL
#define MC_spinAlneutrl_polar           ON*MC_ALL
#define MC_spinSineutrl_polar           ON*MC_ALL
#define MC_spinPneutrl_polar           ON*MC_ALL
#define MC_spinSneutrl_polar           ON*MC_ALL
#define MC_spinClneutrl_polar           ON*MC_ALL


#define MC_spinH3linear			ON*MC_ALL
#define MC_spinH3trig			ON*MC_ALL
#define MC_spinH4linear			ON*MC_ALL
#define MC_spinH4square			ON*MC_ALL
#define MC_spinH4tetra			ON*MC_ALL

#define MC_spinO2			ON*MC_ALL
#define MC_spinO2dia			ON*MC_ALL
#define MC_spinO2_linnett                       ON*MC_ALL
#define MC_spinO2dia_linnett                    ON*MC_ALL
#define MC_spinO2_snglbnd                       ON*MC_ALL
#define MC_spinO2dia_snglbnd                    ON*MC_ALL
#define MC_spinO2_dblbnd                       ON*MC_ALL
#define MC_spinO2dia_dblbnd                    ON*MC_ALL
#define MC_spinO2_trplbnd                       ON*MC_ALL
#define MC_spinO2dia_trplbnd                    ON*MC_ALL

#define MC_spinB2_trplt                     ON * MC_ALL
#define MC_spinB2_snglt                     ON * MC_ALL
#define MC_spinC2_trplt                     ON * MC_ALL
#define MC_spinC2_snglt                     ON * MC_ALL
#define MC_spinSi2_trplt                     ON * MC_ALL
#define MC_spinSi2_snglt                     ON * MC_ALL
#define MC_spinN2_trplt                     ON * MC_ALL
#define MC_spinN2_snglt                     ON * MC_ALL
#define MC_spinS2_trplt                     ON * MC_ALL
#define MC_spinS2_snglt                     ON * MC_ALL
#define MC_spinF2_trplt                     ON * MC_ALL
#define MC_spinF2_snglt                     ON * MC_ALL
#define MC_spinCl2_trplt                     ON * MC_ALL
#define MC_spinCl2_snglt                     ON * MC_ALL
#define MC_spinP2_trplt                     ON * MC_ALL
#define MC_spinP2_snglt                     ON * MC_ALL

#define MC_spinAl2_trplt                     ON * MC_ALL
#define MC_spinAl2_snglt                     ON * MC_ALL

#define MC_spinH		  ON * MC_ALL
#define MC_spinH2		  ON * MC_ALL
#define MC_spinH_		  ON * MC_ALL
#define MC_spinH2plus		  ON * MC_ALL
#define MC_spinH3plus		  ON * MC_ALL
#define MC_spinH2minus		  ON * MC_ALL
#define MC_spinH2trp		  ON * MC_ALL
#define MC_spinH3		  ON * MC_ALL
#define MC_spinH4		  ON * MC_ALL
#define MC_spinOHdot2                 ON * MC_ALL
#define MC_spinOH			  ON * MC_ALL
#define MC_TransitionspinOH		  ON * MC_ALL
#define MC_spinOneutrl 			  ON * MC_ALL
#define MC_spinO_1 			  ON * MC_ALL
#define MC_spinO_2                    ON * MC_ALL
#define MC_spinOplus1                  ON * MC_ALL
#define MC_spinOplus2                 ON * MC_ALL
#define MC_spinOplus3                 ON * MC_ALL
#define MC_spinOplus4                 ON * MC_ALL
#define MC_spinOplus5                 ON * MC_ALL
#define MC_spinOneutrlex		  ON * MC_ALL
#define MC_spinOplus2ex		  ON * MC_ALL
#define MC_spinOplus2ex2	  ON * MC_ALL
#define MC_spinOplus1ex		  ON * MC_ALL
#define MC_spinOplus4ex		  ON * MC_ALL
#define MC_spinOplus3ex		  ON * MC_ALL
#define MC_spinCplus3                     ON * MC_ALL
#define MC_spinCplus2                     ON * MC_ALL
#define MC_spinCplus1                     ON * MC_ALL
#define MC_spinCneutrl                     ON * MC_ALL
#define MC_spinC_1                     ON * MC_ALL
#define MC_spinNplus4                     ON * MC_ALL
#define MC_spinNplus3                     ON * MC_ALL
#define MC_spinNplus2                     ON * MC_ALL
#define MC_spinNplus1                     ON * MC_ALL
#define MC_spinNneutrl                     ON * MC_ALL
#define MC_spinN_1                     ON * MC_ALL
#define MC_spinSplus5                     ON * MC_ALL
#define MC_spinSplus4                     ON * MC_ALL
#define MC_spinSplus3                     ON * MC_ALL
#define MC_spinSplus2                     ON * MC_ALL
#define MC_spinSplus1                    ON * MC_ALL
#define MC_spinSneutrl                     ON * MC_ALL
#define MC_spinS_1                     ON * MC_ALL
#define MC_spinPplus4                     ON * MC_ALL
#define MC_spinPplus3                     ON * MC_ALL
#define MC_spinPplus2                     ON * MC_ALL
#define MC_spinPplus1                    ON * MC_ALL
#define MC_spinPneutrl                     ON * MC_ALL
#define MC_spinP_1                     ON * MC_ALL
#define MC_spinSiplus3                     ON * MC_ALL
#define MC_spinSiplus2                     ON * MC_ALL
#define MC_spinSiplus1                    ON * MC_ALL
#define MC_spinSineutrl                     ON * MC_ALL
#define MC_spinSi_1                     ON * MC_ALL
#define MC_spinFplus6                     ON * MC_ALL
#define MC_spinFplus5                     ON * MC_ALL
#define MC_spinFplus4                     ON * MC_ALL
#define MC_spinFplus3                     ON * MC_ALL
#define MC_spinFplus2                     ON * MC_ALL
#define MC_spinFplus1                    ON * MC_ALL
#define MC_spinFneutrl                     ON * MC_ALL
#define MC_spinF_1                     ON * MC_ALL

#define MC_spinCplus2ex                     ON * MC_ALL
#define MC_spinCplus1ex                     ON * MC_ALL
#define MC_spinCneutrlex                     ON * MC_ALL
#define MC_spinCneutrlex2                     ON * MC_ALL
#define MC_spinNplus3ex                     ON * MC_ALL
#define MC_spinNplus2ex                     ON * MC_ALL
#define MC_spinNplus1ex                     ON * MC_ALL
#define MC_spinNplus1ex2                     ON * MC_ALL
#define MC_spinNneutrlex                     ON * MC_ALL
#define MC_spinFplus5ex                     ON * MC_ALL
#define MC_spinFplus4ex                     ON * MC_ALL
#define MC_spinFplus3ex                     ON * MC_ALL
#define MC_spinFplus3ex2                     ON * MC_ALL
#define MC_spinFplus2ex                     ON * MC_ALL
#define MC_spinFplus1ex                     ON * MC_ALL
#define MC_spinSiplus2ex                     ON * MC_ALL
#define MC_spinSiplus1ex                     ON * MC_ALL
#define MC_spinSineutrlex                     ON * MC_ALL
#define MC_spinSineutrlex2                     ON * MC_ALL
#define MC_spinPplus3ex                     ON * MC_ALL
#define MC_spinPplus2ex                     ON * MC_ALL
#define MC_spinPplus1ex                     ON * MC_ALL
#define MC_spinPplus1ex2                     ON * MC_ALL
#define MC_spinPneutrlex                     ON * MC_ALL
#define MC_spinSplus4ex                     ON * MC_ALL
#define MC_spinSplus3ex                     ON * MC_ALL
#define MC_spinSplus2ex                     ON * MC_ALL
#define MC_spinSplus2ex2                     ON * MC_ALL
#define MC_spinSplus1ex                     ON * MC_ALL
#define MC_spinSneutrlex                     ON * MC_ALL

#define MC_spinOneutrlex2                     ON * MC_ALL
#define MC_spinOplus1ex2                     ON * MC_ALL
#define MC_spinNneutrlex2                     ON * MC_ALL
#define MC_spinFneutrlex                     ON * MC_ALL
#define MC_spinFplus1ex2                     ON * MC_ALL
#define MC_spinFplus2ex2                     ON * MC_ALL
#define MC_spinSneutrlex2                     ON * MC_ALL

#define MC_spinB_1                     ON * MC_ALL
#define MC_spinBneutrlex                     ON * MC_ALL
#define MC_spinBneutrl                     ON * MC_ALL
#define MC_spinBplus1ex                     ON * MC_ALL
#define MC_spinBplus1                    ON * MC_ALL
#define MC_spinBplus2                     ON * MC_ALL

#define MC_spinCl_1                     ON * MC_ALL
#define MC_spinClneutrlex                     ON * MC_ALL
#define MC_spinClneutrl                     ON * MC_ALL
#define MC_spinClplus1ex2                     ON * MC_ALL
#define MC_spinClplus1ex                     ON * MC_ALL
#define MC_spinClplus1                    ON * MC_ALL
#define MC_spinClplus2ex                     ON * MC_ALL
#define MC_spinClplus2                     ON * MC_ALL
#define MC_spinClplus3ex2                     ON * MC_ALL
#define MC_spinClplus3ex                     ON * MC_ALL
#define MC_spinClplus3                     ON * MC_ALL
#define MC_spinClplus4ex                     ON * MC_ALL
#define MC_spinClplus4                     ON * MC_ALL
#define MC_spinClplus5ex                     ON * MC_ALL
#define MC_spinClplus5                     ON * MC_ALL
#define MC_spinClplus6                     ON * MC_ALL
#define MC_spinAl_1                     ON * MC_ALL
#define MC_spinAlneutrlex                     ON * MC_ALL
#define MC_spinAlneutrl                     ON * MC_ALL
#define MC_spinAlplus1ex                     ON * MC_ALL
#define MC_spinAlplus1                    ON * MC_ALL
#define MC_spinAlplus2                     ON * MC_ALL

#define MC_spinLi_1                     ON * MC_ALL
#define MC_spinLineutrl                     ON * MC_ALL
#define MC_spinBeneutrl                     ON * MC_ALL
#define MC_spinBeneutrlex                     ON * MC_ALL
#define MC_spinBeplus1                    ON * MC_ALL
#define MC_spinNa_1                     ON * MC_ALL
#define MC_spinNaneutrl                     ON * MC_ALL
#define MC_spinMgneutrl                     ON * MC_ALL
#define MC_spinMgneutrlex                     ON * MC_ALL
#define MC_spinMgplus1                    ON * MC_ALL

#define MC_spinZnplus11			ON * MC_ALL
#define MC_spinZnplus10			ON * MC_ALL
#define MC_spinZnplus10ex			ON * MC_ALL
#define MC_spinZnplus9			ON * MC_ALL
#define MC_spinZnplus9ex			ON * MC_ALL
#define MC_spinZnplus8ex			ON * MC_ALL
#define MC_spinZnplus8			ON * MC_ALL
#define MC_spinZnplus7			ON * MC_ALL
#define MC_spinZnplus7ex			ON * MC_ALL
#define MC_spinZnplus6			ON * MC_ALL
#define MC_spinZnplus6ex			ON * MC_ALL
#define MC_spinZnplus6ex2			ON * MC_ALL
#define MC_spinZnplus6ex3			ON * MC_ALL
#define MC_spinZnplus5			ON * MC_ALL
#define MC_spinZnplus5ex			ON * MC_ALL
#define MC_spinZnplus5ex2			ON * MC_ALL
#define MC_spinZnplus5ex3			ON * MC_ALL
#define MC_spinZnplus4			ON * MC_ALL
#define MC_spinZnplus4ex			ON * MC_ALL
#define MC_spinZnplus4ex2			ON * MC_ALL
#define MC_spinZnplus4ex3			ON * MC_ALL
#define MC_spinZnplus3			ON * MC_ALL
#define MC_spinZnplus3ex			ON * MC_ALL
#define MC_spinZnplus3ex2			ON * MC_ALL
#define MC_spinZnplus2			ON * MC_ALL
#define MC_spinZnplus2ex			ON * MC_ALL
#define MC_spinZnplus2ex2			ON * MC_ALL
#define MC_spinScplus2			ON * MC_ALL
#define MC_spinTiplus3			ON * MC_ALL
#define MC_spinTiplus2			ON * MC_ALL
#define MC_spinTiplus2ex			ON * MC_ALL
#define MC_spinVplus4			ON * MC_ALL
#define MC_spinVplus3			ON * MC_ALL
#define MC_spinVplus3ex			ON * MC_ALL
#define MC_spinVplus2			ON * MC_ALL
#define MC_spinVplus2ex			ON * MC_ALL
#define MC_spinCrplus5			ON * MC_ALL
#define MC_spinCrplus4			ON * MC_ALL
#define MC_spinCrplus4ex			ON * MC_ALL
#define MC_spinCrplus3			ON * MC_ALL
#define MC_spinCrplus3ex			ON * MC_ALL
#define MC_spinCrplus2			ON * MC_ALL
#define MC_spinCrplus2ex			ON * MC_ALL
#define MC_spinCrplus2ex2			ON * MC_ALL
#define MC_spinCrplus1			ON * MC_ALL
#define MC_spinCrplus1ex			ON * MC_ALL
#define MC_spinCrplus1ex2			ON * MC_ALL
#define MC_spinMnplus6			ON * MC_ALL
#define MC_spinMnplus5			ON * MC_ALL
#define MC_spinMnplus5ex			ON * MC_ALL
#define MC_spinMnplus4			ON * MC_ALL
#define MC_spinMnplus4ex			ON * MC_ALL
#define MC_spinMnplus3			ON * MC_ALL
#define MC_spinMnplus3ex			ON * MC_ALL
#define MC_spinMnplus2			ON * MC_ALL
#define MC_spinMnplus2ex			ON * MC_ALL
#define MC_spinMnplus2ex2			ON * MC_ALL
#define MC_spinFeplus7			ON * MC_ALL
#define MC_spinFeplus6			ON * MC_ALL
#define MC_spinFeplus6ex			ON * MC_ALL
#define MC_spinFeplus5			ON * MC_ALL
#define MC_spinFeplus5ex			ON * MC_ALL
#define MC_spinFeplus4			ON * MC_ALL
#define MC_spinFeplus4ex			ON * MC_ALL
#define MC_spinFeplus4ex2			ON * MC_ALL
#define MC_spinFeplus3			ON * MC_ALL
#define MC_spinFeplus3ex			ON * MC_ALL
#define MC_spinFeplus3ex2			ON * MC_ALL
#define MC_spinFeplus2			ON * MC_ALL
#define MC_spinFeplus2ex			ON * MC_ALL
#define MC_spinFeplus2ex2			ON * MC_ALL
#define MC_spinCoplus8			ON * MC_ALL
#define MC_spinCoplus7			ON * MC_ALL
#define MC_spinCoplus7ex			ON * MC_ALL
#define MC_spinCoplus6			ON * MC_ALL
#define MC_spinCoplus6ex			ON * MC_ALL
#define MC_spinCoplus5			ON * MC_ALL
#define MC_spinCoplus5ex			ON * MC_ALL
#define MC_spinCoplus5ex2			ON * MC_ALL
#define MC_spinCoplus4			ON * MC_ALL
#define MC_spinCoplus4ex			ON * MC_ALL
#define MC_spinCoplus4ex2			ON * MC_ALL
#define MC_spinCoplus3			ON * MC_ALL
#define MC_spinCoplus3ex			ON * MC_ALL
#define MC_spinCoplus3ex2			ON * MC_ALL
#define MC_spinCoplus2			ON * MC_ALL
#define MC_spinCoplus2ex			ON * MC_ALL
#define MC_spinCoplus2ex2			ON * MC_ALL
#define MC_spinNiplus9			ON * MC_ALL
#define MC_spinNiplus8			ON * MC_ALL
#define MC_spinNiplus8ex			ON * MC_ALL
#define MC_spinNiplus7			ON * MC_ALL
#define MC_spinNiplus7ex			ON * MC_ALL
#define MC_spinNiplus6			ON * MC_ALL
#define MC_spinNiplus6ex			ON * MC_ALL
#define MC_spinNiplus5			ON * MC_ALL
#define MC_spinNiplus5ex			ON * MC_ALL
#define MC_spinNiplus5ex2			ON * MC_ALL
#define MC_spinNiplus4			ON * MC_ALL
#define MC_spinNiplus4ex			ON * MC_ALL
#define MC_spinNiplus4ex2			ON * MC_ALL
#define MC_spinNiplus3			ON * MC_ALL
#define MC_spinNiplus3ex			ON * MC_ALL
#define MC_spinNiplus3ex2			ON * MC_ALL
#define MC_spinNiplus2			ON * MC_ALL
#define MC_spinNiplus2ex			ON * MC_ALL
#define MC_spinNiplus2ex2			ON * MC_ALL
#define MC_spinCuplus10			ON * MC_ALL
#define MC_spinCuplus9			ON * MC_ALL
#define MC_spinCuplus9ex			ON * MC_ALL
#define MC_spinCuplus8			ON * MC_ALL
#define MC_spinCuplus7			ON * MC_ALL
#define MC_spinCuplus6			ON * MC_ALL
#define MC_spinCuplus5			ON * MC_ALL
#define MC_spinCuplus5ex			ON * MC_ALL
#define MC_spinCuplus5ex2			ON * MC_ALL
#define MC_spinCuplus4			ON * MC_ALL
#define MC_spinCuplus4ex			ON * MC_ALL
#define MC_spinCuplus4ex2			ON * MC_ALL
#define MC_spinCuplus3			ON * MC_ALL
#define MC_spinCuplus3ex			ON * MC_ALL
#define MC_spinCuplus3ex2			ON * MC_ALL
#define MC_spinCuplus2			ON * MC_ALL
#define MC_spinCuplus2ex			ON * MC_ALL
#define MC_spinCuplus1			ON * MC_ALL
#define MC_spinCuplus1ex			ON * MC_ALL
#define MC_spinYplus2			ON * MC_ALL
#define MC_spinZrplus3			ON * MC_ALL
#define MC_spinZrplus2			ON * MC_ALL
#define MC_spinZrplus2ex			ON * MC_ALL
#define MC_spinNbplus4			ON * MC_ALL
#define MC_spinNbplus3			ON * MC_ALL
#define MC_spinNbplus3ex			ON * MC_ALL
#define MC_spinNbplus2			ON * MC_ALL
#define MC_spinNbplus2ex			ON * MC_ALL
#define MC_spinNbplus1			ON * MC_ALL
#define MC_spinNbplus1ex			ON * MC_ALL
#define MC_spinNbplus1ex2			ON * MC_ALL
#define MC_spinMoplus5			ON * MC_ALL
#define MC_spinMoplus4			ON * MC_ALL
#define MC_spinMoplus4ex			ON * MC_ALL
#define MC_spinMoplus3			ON * MC_ALL
#define MC_spinMoplus3ex			ON * MC_ALL
#define MC_spinMoplus2			ON * MC_ALL
#define MC_spinMoplus2ex			ON * MC_ALL
#define MC_spinMoplus2ex2			ON * MC_ALL
#define MC_spinMoplus1			ON * MC_ALL
#define MC_spinMoplus1ex			ON * MC_ALL
#define MC_spinMoplus1ex2			ON * MC_ALL
#define MC_spinTcplus6			ON * MC_ALL
#define MC_spinTcplus5			ON * MC_ALL
#define MC_spinTcplus4			ON * MC_ALL
#define MC_spinTcplus3			ON * MC_ALL
#define MC_spinTcplus2			ON * MC_ALL
#define MC_spinRuplus7			ON * MC_ALL
#define MC_spinRuplus6			ON * MC_ALL
#define MC_spinRuplus5			ON * MC_ALL
#define MC_spinRuplus4			ON * MC_ALL
#define MC_spinRuplus3			ON * MC_ALL
#define MC_spinRuplus2			ON * MC_ALL
#define MC_spinRuplus2ex			ON * MC_ALL
#define MC_spinRuplus1			ON * MC_ALL
#define MC_spinRuplus1ex			ON * MC_ALL
#define MC_spinRuplus1ex2			ON * MC_ALL
#define MC_spinRhplus8			ON * MC_ALL
#define MC_spinRhplus7			ON * MC_ALL
#define MC_spinRhplus6			ON * MC_ALL
#define MC_spinRhplus5			ON * MC_ALL
#define MC_spinRhplus4			ON * MC_ALL
#define MC_spinRhplus3			ON * MC_ALL
#define MC_spinRhplus2			ON * MC_ALL
#define MC_spinRhplus2ex			ON * MC_ALL
#define MC_spinRhplus2ex2			ON * MC_ALL
#define MC_spinRhplus1			ON * MC_ALL
#define MC_spinRhplus1ex			ON * MC_ALL
#define MC_spinRhplus1ex2			ON * MC_ALL
#define MC_spinPdplus9			ON * MC_ALL
#define MC_spinPdplus8			ON * MC_ALL
#define MC_spinPdplus7			ON * MC_ALL
#define MC_spinPdplus6			ON * MC_ALL
#define MC_spinPdplus5			ON * MC_ALL
#define MC_spinPdplus4			ON * MC_ALL
#define MC_spinPdplus3			ON * MC_ALL
#define MC_spinPdplus2			ON * MC_ALL
#define MC_spinPdplus2ex			ON * MC_ALL
#define MC_spinPdplus2ex2			ON * MC_ALL
#define MC_spinPdplus1			ON * MC_ALL
#define MC_spinPdplus1ex			ON * MC_ALL
#define MC_spinPdneutrl			ON * MC_ALL
#define MC_spinPdneutrlex			ON * MC_ALL
#define MC_spinAgplus10			ON * MC_ALL
#define MC_spinAgplus9			ON * MC_ALL
#define MC_spinAgplus8			ON * MC_ALL
#define MC_spinAgplus7			ON * MC_ALL
#define MC_spinAgplus6			ON * MC_ALL
#define MC_spinAgplus5			ON * MC_ALL
#define MC_spinAgplus4			ON * MC_ALL
#define MC_spinAgplus3			ON * MC_ALL
#define MC_spinAgplus2			ON * MC_ALL
#define MC_spinAgplus2ex			ON * MC_ALL
#define MC_spinAgplus1			ON * MC_ALL
#define MC_spinAgplus1ex			ON * MC_ALL
#define MC_spinCdplus11			ON * MC_ALL
#define MC_spinCdplus10			ON * MC_ALL
#define MC_spinCdplus9			ON * MC_ALL
#define MC_spinCdplus8			ON * MC_ALL
#define MC_spinCdplus7			ON * MC_ALL
#define MC_spinCdplus6			ON * MC_ALL
#define MC_spinCdplus5			ON * MC_ALL
#define MC_spinCdplus4			ON * MC_ALL
#define MC_spinCdplus3			ON * MC_ALL
#define MC_spinCdplus3ex			ON * MC_ALL
#define MC_spinCdplus2			ON * MC_ALL
#define MC_spinCdplus2ex			ON * MC_ALL

#define MC_spinZnplus1			ON * MC_ALL
#define MC_spinZnplus1ex			ON * MC_ALL
#define MC_spinZnplus1ex2			ON * MC_ALL
#define MC_spinZnneutrl			ON * MC_ALL
#define MC_spinZnneutrlex			ON * MC_ALL
#define MC_spinZnneutrlex2			ON * MC_ALL
#define MC_spinCuneutrl			ON * MC_ALL
#define MC_spinCuneutrlex			ON * MC_ALL
#define MC_spinNiplus1			ON * MC_ALL
#define MC_spinNiplus1ex			ON * MC_ALL
#define MC_spinNineutrl			ON * MC_ALL
#define MC_spinNineutrlex			ON * MC_ALL
#define MC_spinCoplus1			ON * MC_ALL
#define MC_spinCoplus1ex			ON * MC_ALL
#define MC_spinCoplus1ex2			ON * MC_ALL
#define MC_spinConeutrl			ON * MC_ALL
#define MC_spinConeutrlex			ON * MC_ALL
#define MC_spinFeplus1			ON * MC_ALL
#define MC_spinFeplus1ex			ON * MC_ALL
#define MC_spinFeplus1ex2			ON * MC_ALL
#define MC_spinFeneutrl			ON * MC_ALL
#define MC_spinFeneutrlex			ON * MC_ALL
#define MC_spinFeneutrlex2			ON * MC_ALL
#define MC_spinFeneutrlex3			ON * MC_ALL
#define MC_spinMnplus1			ON * MC_ALL
#define MC_spinMnplus1ex			ON * MC_ALL
#define MC_spinMnplus1ex2			ON * MC_ALL
#define MC_spinMnplus1ex3			ON * MC_ALL
#define MC_spinMnneutrl			ON * MC_ALL
#define MC_spinMnneutrlex			ON * MC_ALL
#define MC_spinMnneutrlex2			ON * MC_ALL
#define MC_spinMnneutrlex3			ON * MC_ALL
#define MC_spinCrneutrl			ON * MC_ALL
#define MC_spinCrneutrlex			ON * MC_ALL
#define MC_spinCrneutrlex2			ON * MC_ALL
#define MC_spinCrneutrlex3			ON * MC_ALL
#define MC_spinVplus1			ON * MC_ALL
#define MC_spinVplus1ex			ON * MC_ALL
#define MC_spinVplus1ex2			ON * MC_ALL
#define MC_spinVneutrl			ON * MC_ALL
#define MC_spinVneutrlex			ON * MC_ALL
#define MC_spinVneutrlex2			ON * MC_ALL
#define MC_spinTiplus1			ON * MC_ALL
#define MC_spinTiplus1ex			ON * MC_ALL
#define MC_spinTineutrl			ON * MC_ALL
#define MC_spinTineutrlex			ON * MC_ALL
#define MC_spinTineutrlex2			ON * MC_ALL
#define MC_spinScplus1			ON * MC_ALL
#define MC_spinScplus1ex			ON * MC_ALL
#define MC_spinScneutrl			ON * MC_ALL
#define MC_spinScneutrlex			ON * MC_ALL

#define MC_spinCdplus1			ON * MC_ALL
#define MC_spinCdplus1ex			ON * MC_ALL
#define MC_spinCdneutrl			ON * MC_ALL
#define MC_spinCdneutrlex			ON * MC_ALL
#define MC_spinAgneutrl			ON * MC_ALL
#define MC_spinAgneutrlex			ON * MC_ALL
#define MC_spinRhneutrl			ON * MC_ALL
#define MC_spinRhneutrlex			ON * MC_ALL
#define MC_spinRuneutrl			ON * MC_ALL
#define MC_spinRuneutrlex			ON * MC_ALL
#define MC_spinRuneutrlex2			ON * MC_ALL
#define MC_spinTcplus1			ON * MC_ALL
#define MC_spinTcplus1ex			ON * MC_ALL
#define MC_spinTcneutrl			ON * MC_ALL
#define MC_spinTcneutrlex			ON * MC_ALL
#define MC_spinTcneutrlex2			ON * MC_ALL
#define MC_spinTcneutrlex3			ON * MC_ALL
#define MC_spinMoneutrl			ON * MC_ALL
#define MC_spinMoneutrlex			ON * MC_ALL
#define MC_spinMoneutrlex2			ON * MC_ALL
#define MC_spinMoneutrlex3			ON * MC_ALL
#define MC_spinNbneutrl			ON * MC_ALL
#define MC_spinNbneutrlex			ON * MC_ALL
#define MC_spinNbneutrlex2			ON * MC_ALL
#define MC_spinZrplus1			ON * MC_ALL
#define MC_spinZrplus1ex			ON * MC_ALL
#define MC_spinZrneutrl			ON * MC_ALL
#define MC_spinZrneutrlex			ON * MC_ALL
#define MC_spinZrneutrlex2			ON * MC_ALL
#define MC_spinYplus1			ON * MC_ALL
#define MC_spinYplus1ex			ON * MC_ALL
#define MC_spinYneutrl			ON * MC_ALL
#define MC_spinYneutrlex			ON * MC_ALL

//==================================


//MOLECULES AND WEIGHTS=============
//OH-===============================
#define wspinOH                     0.0*FIT_spinOH

//OH- transition===================
#define wTransitionspinOH         0.0*FIT_spinOH * FIT_transition

//H2===============================
#define wspinH2		4000.0*FIT_spinH*FIT_spinEE*FIT_spinHH*FIT_AB_AH  

//H2trp===============================
#define wspinH2trp         3000.0*FIT_spinH*FIT_spinEE*FIT_spinHH * FIT_AA_AH 


//H2transition=====================
#define wTransitionspinH2	   0.0*FIT_spinH * FIT_transition * FIT_spinEE *FIT_spinHH

//H2 triplet transition============
#define wTransitiontripletH2	   0.0*FIT_spinH * FIT_transition * FIT_spinEE * FIT_triplet*FIT_spinHH


//H2v===============================
#define wspinH2v		    0.0*FIT_spinH * FIT_spinEE*FIT_spinHH

//H2plus============================
#define wspinH2plus             300.0*FIT_spinH*FIT_spinE*FIT_spinHH * FIT_AB_AH

//H2minus===========================
#define wspinH2minus		   100.0 * FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_AA_AH 

//H2plus transition=================
#define wTransitionspinH2plus	   0.0 * FIT_spinH * FIT_transition*FIT_spinE*FIT_spinHH

//H2minus transition================
#define wTransitionspinH2minus	   0.0 * FIT_spinH * FIT_transition * FIT_spinEE*FIT_spinHH

//H3plus============================
#define wspinH3pluslength	   2.0 // don't set to be 0 or cause trouble
//sum-------------------------------
#define wspinH3plus 		200.0*FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_AB_AH

//H3================================
#define wspinH3			100.0*FIT_spinH * FIT_spinEE*FIT_spinHH*FIT_H3H4

//H4===============================
#define wspinH4			1.0*FIT_spinH * FIT_spinEE*FIT_spinHH*FIT_H3H4


//H3linear================================
#define wspinH3linear                  100.0*FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_AA_AH

//H3trig================================
#define wspinH3trig                    1.0*FIT_spinH * FIT_spinEE*FIT_spinHH*FIT_H3H4

//H4linear===============================
#define wspinH4linear                  1.0*FIT_spinH * FIT_spinEE*FIT_spinHH*FIT_H3H4

//H4square===============================
#define wspinH4square                  1.0*FIT_spinH * FIT_spinEE*FIT_spinHH*FIT_H3H4

//H4tetra===============================
#define wspinH4tetra                   1.0*FIT_spinH * FIT_spinEE*FIT_spinHH*FIT_H3H4





//OH*===============================
#define wspinOHdot                  0.0*FIT_spinOH
#define wspinOHdot2		   25.0*FIT_spinOH

//OH* transition====================
#define wTransitionspinOHdot	    0.0*FIT_spinOH
#define wTransitionspinOHdot2	    0.0*FIT_spinOH

//H2O===============================
#define wspinH2Oangle              18.0
#define wspinH2Olength             12.0
#define wspinH2OlengthOBP           0.0
#define wspinH2OlengthOLP           0.0
//sum-------------------------------
#define wspinH2O                   30.0*FIT_spinOH*FIT_spinHH

//H2O===============================
#define wspinH2Olinearangle               0.0
#define wspinH2Olinearlength              0.0
#define wspinH2OlinearlengthOBP           0.0
#define wspinH2OlinearlengthOLP           0.0
//sum-------------------------------
#define wspinH2Olinear                  0.0*FIT_spinOH*FIT_spinHH


//H3O+==============================
#define wspinH3Oangle              28.0 * FIT_spinOH
#define wspinH3Olength              8.0 * FIT_spinOH
//sum-------------------------------
#define wspinH3O                   36.0*FIT_spinOH*FIT_spinHH

//H2O+==============================
#define wspinH2Oplusangle	  18.0
#define wspinH2Opluslength	  10.0
//sum------------------------------
#define wspinH2Oplus		  28.0 * FIT_spinOH*FIT_spinHH

//O=================================
#define wspinOneutrl		   1.0*FIT_spinO

//O*===============================
#define wspinOneutrlex		   1.0*FIT_spinO * FIT_ex

//O^-===============================
#define wspinO_1		   1.0*FIT_spinO

//O^-2=============================
#define wspinO_2		  0.0*FIT_spinO

//O2===============================
#define wspinO2		   300.0*FIT_spinO*FIT_spinO2

//O2diamagnetic===================
#define wspinO2dia         300.0*FIT_spinO*FIT_spinO2

//O2quintet======================
#define wspinO2qnt         100.0*FIT_spinO*FIT_spinO2

//O3singlet======================
#define wspinO3            100.0*FIT_spinO*FIT_spinO3

//O3triplet======================
#define wspinO3trp         100.0*FIT_spinO*FIT_spinO3



//O2===============================
#define wspinO2_linnett            1.0*FIT_spinO*FIT_spinO2
//O2===============================
#define wspinO2_snglbnd            1.0*FIT_spinO*FIT_spinO2
//O2===============================	
#define wspinO2_dblbnd             1.0*FIT_spinO*FIT_spinO2
//O2===============================
#define wspinO2_trplbnd            1.0*FIT_spinO*FIT_spinO2


//O2diamagnetic===================
#define wspinO2dia_linnett         1.0*FIT_spinO*FIT_spinO2
//O2diamagnetic===================                           
#define wspinO2dia_snglbnd         1.0*FIT_spinO*FIT_spinO2
//O2diamagnetic===================                           
#define wspinO2dia_dblbnd          1.0*FIT_spinO*FIT_spinO2
//O2diamagnetic===================                           
#define wspinO2dia_trplbnd         1.0*FIT_spinO*FIT_spinO2

//O2qnt===========================
#define wspinO2qnt_linnett         1.0*FIT_spinO*FIT_spinO2
//O2qnt===========================
#define wspinO2qnt_snglbnd         1.0*FIT_spinO*FIT_spinO2
//O2qnt===========================
#define wspinO2qnt_dblbnd          1.0*FIT_spinO*FIT_spinO2
//O2qnt===========================
#define wspinO2qnt_trplbnd         1.0*FIT_spinO*FIT_spinO2

//O2_1=============================
#define wspinO2_1		 100.0*FIT_spinO2  //100.0

//O2_2=============================
#define wspinO2_2		 0.0*FIT_spinOO

//O2_2=============================
#define wspinO2_2v                0.0*FIT_spinOO

//O2^+============================
#define wspinO2plus1		 100.0*FIT_spinO2  //100.0


//O+===============================
#define wspinOplus1		 1.0*FIT_spinO

//O+*=============================
#define wspinOplus1ex		1.0*FIT_spinO* FIT_ex

//O+2=============================
#define wspinOplus2		1.0*FIT_spinO

//O+2*============================
#define wspinOplus2ex		1.0*FIT_spinO* FIT_ex

//O+2**============================
#define wspinOplus2ex2           1.0*FIT_spinO * FIT_ex

//O+3=============================
#define wspinOplus3		1.0*FIT_spinO

//O+3*=============================
#define wspinOplus3ex           1.0*FIT_spinO * FIT_ex

//O+4=============================
#define wspinOplus4		1.0*FIT_spinO

//O+4*============================
#define wspinOplus4ex		1.0*FIT_spinO* FIT_ex

//O+5=============================
#define wspinOplus5		1.0*FIT_spinO

//H*==============================
#define wspinH                  1.0*FIT_spinH// * FIT_spinE

//H-1==============================
#define wspinH_                 1.0*FIT_spinH //* FIT_spinEE
//H-1trp==============================
//#define wspinH_trp                 1.0*FIT_spinH *FIT_AA_AH //* FIT_spinEE


//Cplus3===========================
#define wspinCplus3            1.0*FIT_spinC
//Cplus2===========================
#define wspinCplus2            1.0*FIT_spinC
//Cplus===========================
#define wspinCplus1           1.0*FIT_spinC
//Cneutrl===========================
#define wspinCneutrl            1.0*FIT_spinC
//C_===========================
#define wspinC_1            1.0*FIT_spinC
//Nplus4===========================
#define wspinNplus4            1.0*FIT_spinN
//Nplus3===========================
#define wspinNplus3            1.0*FIT_spinN
//Nplus2===========================
#define wspinNplus2            1.0*FIT_spinN
//Nplus===========================
#define wspinNplus1           1.0*FIT_spinN
//Nneutrl===========================
#define wspinNneutrl            1.0*FIT_spinN
//N_===========================
#define wspinN_1              0.0*FIT_spinN
//Splus5===========================
#define wspinSplus5            1.0*FIT_spinS
//Splus4===========================
#define wspinSplus4            1.0*FIT_spinS
//Splus3===========================
#define wspinSplus3            1.0*FIT_spinS
//Splus2===========================
#define wspinSplus2            1.0*FIT_spinS
//Splus===========================
#define wspinSplus1           1.0*FIT_spinS
//Sneutrl===========================
#define wspinSneutrl            1.0*FIT_spinS
//S_===========================
#define wspinS_1            1.0*FIT_spinS
//Pplus4===========================
#define wspinPplus4            1.0*FIT_spinP
//Pplus3===========================
#define wspinPplus3            1.0*FIT_spinP
//Pplus2===========================
#define wspinPplus2            1.0*FIT_spinP
//Pplus===========================
#define wspinPplus1           1.0*FIT_spinP
//Pneutrl===========================
#define wspinPneutrl            1.0*FIT_spinP
//P_===========================
#define wspinP_1            1.0*FIT_spinP
//Siplus3===========================
#define wspinSiplus3            1.0*FIT_spinSi
//Siplus2===========================
#define wspinSiplus2            1.0*FIT_spinSi
//Siplus===========================
#define wspinSiplus1           1.0*FIT_spinSi
//Sineutrl===========================
#define wspinSineutrl            1.0*FIT_spinSi
//Si_===========================
#define wspinSi_1            1.0*FIT_spinSi
//Fplus6===========================
#define wspinFplus6            1.0*FIT_spinF
//Fplus5===========================
#define wspinFplus5            1.0*FIT_spinF
//Fplus4===========================
#define wspinFplus4            1.0*FIT_spinF
//Fplus3===========================
#define wspinFplus3            1.0*FIT_spinF
//Fplus2===========================
#define wspinFplus2            1.0*FIT_spinF
//Fplus===========================
#define wspinFplus1           1.0*FIT_spinF
//Fneutrl===========================
#define wspinFneutrl            1.0*FIT_spinF
//F_===========================
#define wspinF_1            1.0*FIT_spinF

//Cplus2ex===========================
#define wspinCplus2ex            1.0*FIT_spinC*FIT_ex
//Cplus1ex===========================
#define wspinCplus1ex            1.0*FIT_spinC*FIT_ex
//Cneutrlex===========================
#define wspinCneutrlex            1.0*FIT_spinC*FIT_ex
//Cneutrlex2===========================
#define wspinCneutrlex2            1.0*FIT_spinC*FIT_ex
//Nplus3ex===========================
#define wspinNplus3ex            1.0*FIT_spinN*FIT_ex
//Nplus2ex===========================
#define wspinNplus2ex            1.0*FIT_spinN*FIT_ex
//Nplus1ex===========================
#define wspinNplus1ex            1.0*FIT_spinN*FIT_ex
//Nplus1ex2===========================
#define wspinNplus1ex2            1.0*FIT_spinN*FIT_ex
//Nneutrlex===========================
#define wspinNneutrlex            1.0*FIT_spinN*FIT_ex
//Fplus5ex===========================
#define wspinFplus5ex            1.0*FIT_spinF*FIT_ex
//Fplus4ex===========================
#define wspinFplus4ex            1.0*FIT_spinF*FIT_ex
//Fplus3ex===========================
#define wspinFplus3ex            1.0*FIT_spinF*FIT_ex
//Fplus3ex2===========================
#define wspinFplus3ex2            1.0*FIT_spinF*FIT_ex
//Fplus2ex===========================
#define wspinFplus2ex            1.0*FIT_spinF*FIT_ex
//Fplus1ex===========================
#define wspinFplus1ex            1.0*FIT_spinF*FIT_ex
//Siplus2ex===========================
#define wspinSiplus2ex            1.0*FIT_spinSi*FIT_ex
//Siplus1ex===========================
#define wspinSiplus1ex            1.0*FIT_spinSi*FIT_ex
//Sineutrlex===========================
#define wspinSineutrlex            1.0*FIT_spinSi*FIT_ex
//Sineutrlex2===========================
#define wspinSineutrlex2            1.0*FIT_spinSi*FIT_ex
//Pplus3ex===========================
#define wspinPplus3ex            1.0*FIT_spinP*FIT_ex
//Pplus2ex===========================
#define wspinPplus2ex            1.0*FIT_spinP*FIT_ex
//Pplus1ex===========================
#define wspinPplus1ex            1.0*FIT_spinP*FIT_ex
//Pplus1ex2===========================
#define wspinPplus1ex2            1.0*FIT_spinP*FIT_ex
//Pneutrlex===========================
#define wspinPneutrlex            1.0*FIT_spinP*FIT_ex
//Splus4ex===========================
#define wspinSplus4ex            1.0*FIT_spinS*FIT_ex
//Splus3ex===========================
#define wspinSplus3ex            1.0*FIT_spinS*FIT_ex
//Splus2ex===========================
#define wspinSplus2ex            1.0*FIT_spinS*FIT_ex
//Splus2ex2===========================
#define wspinSplus2ex2            1.0*FIT_spinS*FIT_ex
//Splus1ex===========================
#define wspinSplus1ex            1.0*FIT_spinS*FIT_ex
//Sneutrlex===========================
#define wspinSneutrlex            1.0*FIT_spinS*FIT_ex

//Oneutrlex2===========================
#define wspinOneutrlex2            1.0*FIT_spinO*FIT_polar*FIT_ex
//Oplus1ex2===========================
#define wspinOplus1ex2            1.0*FIT_spinO*FIT_polar*FIT_ex
//Nneutrlex2===========================
#define wspinNneutrlex2            0.0*FIT_spinN*FIT_ex
//Fneutrlex===========================
#define wspinFneutrlex            1.0*FIT_spinF*FIT_ex
//Fplus1ex2===========================
#define wspinFplus1ex2            1.0*FIT_spinF*FIT_ex
//Fplus2ex2===========================
#define wspinFplus2ex2            1.0*FIT_spinF*FIT_ex
//Sneutrlex2===========================
#define wspinSneutrlex2            1.0*FIT_spinS*FIT_ex

//B_1===========================
#define wspinB_1            1.0*FIT_spinBo
//Bneutrlex===========================
#define wspinBneutrlex            1.0*FIT_spinBo*FIT_ex
//Bneutrl===========================
#define wspinBneutrl            1.0*FIT_spinBo
//Bplus1ex===========================
#define wspinBplus1ex            1.0*FIT_spinBo*FIT_ex
//Bplus===========================
#define wspinBplus1           1.0*FIT_spinBo
//Bplus2===========================
#define wspinBplus2            1.0*FIT_spinBo
//Cl_1===========================
#define wspinCl_1            1.0*FIT_spinCl
//Clneutrlex===========================
#define wspinClneutrlex            1.0*FIT_spinCl*FIT_ex
//Clneutrl===========================
#define wspinClneutrl            1.0*FIT_spinCl
//Clplus1ex2===========================
#define wspinClplus1ex2            1.0*FIT_spinCl*FIT_ex
//Clplus1ex===========================
#define wspinClplus1ex            1.0*FIT_spinCl*FIT_ex
//Clplus===========================
#define wspinClplus1           1.0*FIT_spinCl
//Clplus2ex===========================
#define wspinClplus2ex            1.0*FIT_spinCl*FIT_ex
//Clplus2===========================
#define wspinClplus2            1.0*FIT_spinCl
//Clplus3ex2===========================
#define wspinClplus3ex2            1.0*FIT_spinCl*FIT_ex
//Clplus3ex===========================
#define wspinClplus3ex            1.0*FIT_spinCl*FIT_ex
//Clplus3===========================
#define wspinClplus3            1.0*FIT_spinCl
//Clplus4ex===========================
#define wspinClplus4ex            1.0*FIT_spinCl*FIT_ex
//Clplus4===========================
#define wspinClplus4            1.0*FIT_spinCl
//Clplus5ex===========================
#define wspinClplus5ex            1.0*FIT_spinCl*FIT_ex
//Clplus5===========================
#define wspinClplus5            1.0*FIT_spinCl
//Clplus6===========================
#define wspinClplus6            1.0*FIT_spinCl
//Al_1===========================
#define wspinAl_1            1.0*FIT_spinAl
//Alneutrlex===========================
#define wspinAlneutrlex            1.0*FIT_spinAl*FIT_ex
//Alneutrl===========================
#define wspinAlneutrl            1.0*FIT_spinAl
//Alplus1ex===========================
#define wspinAlplus1ex            1.0*FIT_spinAl*FIT_ex
//Alplus===========================
#define wspinAlplus1           1.0*FIT_spinAl
//Alplus2===========================
#define wspinAlplus2            1.0*FIT_spinAl


//Li_1===========================
#define wspinLi_1            1.0*FIT_spinLi
//Lineutrl===========================
#define wspinLineutrl            1.0*FIT_spinLi
//Beneutrl===========================
#define wspinBeneutrl            1.0*FIT_spinBe
//Beneutrlex===========================
#define wspinBeneutrlex            1.0*FIT_spinBe*FIT_ex
//Beplus===========================
#define wspinBeplus1           1.0*FIT_spinBe
//Na_1===========================
#define wspinNa_1            1.0*FIT_spinNa
//Naneutrl===========================
#define wspinNaneutrl            1.0*FIT_spinNa
//Mgneutrl===========================
#define wspinMgneutrl            1.0*FIT_spinMg*FIT_ex
//Mgneutrlex===========================
#define wspinMgneutrlex            1.0*FIT_spinMg
//Mgplus===========================
#define wspinMgplus1           1.0*FIT_spinMg



//B2_trplt===========================
#define wspinB2_trplt         2000.0*FIT_spinBo*FIT_ex*FIT_diat
//B2_snglt===========================
#define wspinB2_snglt         2000.0*FIT_spinBo*FIT_ex*FIT_diat

//C2_trplt===========================
#define wspinC2_trplt         2000.0*FIT_spinC*FIT_ex*FIT_diat
//C2_snglt===========================
#define wspinC2_snglt         2000.0*FIT_spinC*FIT_ex*FIT_diat

//N2_trplt===========================
#define wspinN2_trplt         2000.0*FIT_spinN*FIT_ex*FIT_diat
//N2_snglt===========================
#define wspinN2_snglt         2000.0*FIT_spinN*FIT_ex*FIT_diat

//F2_trplt===========================
#define wspinF2_trplt         2000.0*FIT_spinF*FIT_ex*FIT_diat
//F2_snglt===========================
#define wspinF2_snglt         2000.0*FIT_spinF*FIT_ex*FIT_diat

//Al2_trplt===========================
#define wspinAl2_trplt        2000.0*FIT_spinAl*FIT_ex*FIT_diat
//Al2_snglt===========================
#define wspinAl2_snglt        2000.0*FIT_spinAl*FIT_ex*FIT_diat

//Si2_trplt===========================
#define wspinSi2_trplt        2000.0*FIT_spinSi*FIT_ex*FIT_diat
//Si2_snglt===========================
#define wspinSi2_snglt        2000.0*FIT_spinSi*FIT_ex*FIT_diat

//P2_trplt===========================
#define wspinP2_trplt         2000.0*FIT_spinP*FIT_ex*FIT_diat
//P2_snglt===========================
#define wspinP2_snglt         2000.0*FIT_spinP*FIT_ex*FIT_diat

//S2_trplt===========================
#define wspinS2_trplt        2000.0*FIT_spinS*FIT_ex*FIT_diat//10000.0*FIT_spinS*FIT_ex
//S2_snglt===========================
#define wspinS2_snglt        2000.0*FIT_spinS*FIT_ex*FIT_diat//10000.0*FIT_spinS*FIT_ex

//Cl2_trplt===========================
#define wspinCl2_trplt        2000.0*FIT_spinCl*FIT_ex*FIT_diat
//Cl2_snglt===========================
#define wspinCl2_snglt        2000.0*FIT_spinCl*FIT_ex*FIT_diat



//Hpolar============================
#define wspinH_polar	      0.0*FIT_spinH*FIT_polar

//Bpolar============================
#define wspinBneutrl_polar    1000.0*FIT_spinBo*FIT_polar
//Cpolar============================
#define wspinCneutrl_polar    0.0*FIT_spinC*FIT_polar
//Npolar============================
#define wspinNneutrl_polar    0.0*FIT_spinN*FIT_polar
//Opolar============================
#define wspinOneutrl_polar    0.0*FIT_spinO*FIT_polar
//Fpolar============================
#define wspinFneutrl_polar    1000.0*FIT_spinF*FIT_polar
//Alpolar============================
#define wspinAlneutrl_polar   1000.0*FIT_spinAl*FIT_polar
//Sipolar============================
#define wspinSineutrl_polar   1000.0*FIT_spinSi*FIT_polar
//Ppolar============================
#define wspinPneutrl_polar    0.0*FIT_spinP*FIT_polar
//Spolar============================
#define wspinSneutrl_polar    1000.0*FIT_spinS*FIT_polar
//Clpolar============================
#define wspinClneutrl_polar   0.0*FIT_spinCl*FIT_polar

//Znplus11===========================
#define wspinZnplus11            1.0*FIT_spinZn
//Znplus10===========================
#define wspinZnplus10            1.0*FIT_spinZn
//Znplus10ex===========================
#define wspinZnplus10ex            1.0*FIT_spinZn * FIT_ex
//Znplus9===========================
#define wspinZnplus9            1.0*FIT_spinZn
//Znplus8===========================
#define wspinZnplus8            1.0*FIT_spinZn
//Znplus7===========================
#define wspinZnplus7            1.0*FIT_spinZn
//Znplus6===========================
#define wspinZnplus6            1.0*FIT_spinZn
//Znplus6ex===========================
#define wspinZnplus6ex            1.0*FIT_spinZn * FIT_ex
//Znplus6ex2===========================
#define wspinZnplus6ex2            1.0*FIT_spinZn * FIT_ex
//Znplus5===========================
#define wspinZnplus5            1.0*FIT_spinZn
//Znplus5ex===========================
#define wspinZnplus5ex            1.0*FIT_spinZn * FIT_ex
//Znplus5ex2===========================
#define wspinZnplus5ex2            1.0*FIT_spinZn * FIT_ex
//Znplus4===========================
#define wspinZnplus4            1.0*FIT_spinZn
//Znplus4ex===========================
#define wspinZnplus4ex            1.0*FIT_spinZn * FIT_ex
//Znplus4ex2===========================
#define wspinZnplus4ex2            1.0*FIT_spinZn * FIT_ex
//Znplus3===========================
#define wspinZnplus3            1.0*FIT_spinZn
//Znplus3ex===========================
#define wspinZnplus3ex            1.0*FIT_spinZn * FIT_ex
//Znplus2===========================
#define wspinZnplus2            1.0*FIT_spinZn
//Znplus2ex===========================
#define wspinZnplus2ex            1.0*FIT_spinZn * FIT_ex
//Scplus2===========================
#define wspinScplus2            1.0*FIT_spinSc
//Tiplus3===========================
#define wspinTiplus3            1.0*FIT_spinTi
//Tiplus2===========================
#define wspinTiplus2            1.0*FIT_spinTi
//Tiplus2ex===========================
#define wspinTiplus2ex            1.0*FIT_spinTi * FIT_ex
//Vplus4===========================
#define wspinVplus4            1.0*FIT_spinV
//Vplus3===========================
#define wspinVplus3            1.0*FIT_spinV
//Vplus3ex===========================
#define wspinVplus3ex            1.0*FIT_spinV * FIT_ex
//Vplus2===========================
#define wspinVplus2            1.0*FIT_spinV
//Vplus2ex===========================
#define wspinVplus2ex            1.0*FIT_spinV * FIT_ex
//Crplus5===========================
#define wspinCrplus5            1.0*FIT_spinCr
//Crplus4===========================
#define wspinCrplus4            1.0*FIT_spinCr
//Crplus4ex===========================
#define wspinCrplus4ex            1.0*FIT_spinCr * FIT_ex
//Crplus3===========================
#define wspinCrplus3            1.0*FIT_spinCr
//Crplus3ex===========================
#define wspinCrplus3ex            1.0*FIT_spinCr * FIT_ex
//Crplus2===========================
#define wspinCrplus2            1.0*FIT_spinCr
//Crplus2ex===========================
#define wspinCrplus2ex            1.0*FIT_spinCr * FIT_ex
//Crplus2ex2===========================
#define wspinCrplus2ex2            1.0*FIT_spinCr * FIT_ex
//Crplus1===========================
#define wspinCrplus1            1.0*FIT_spinCr
//Crplus1ex===========================
#define wspinCrplus1ex            1.0*FIT_spinCr * FIT_ex
//Crplus1ex2===========================
#define wspinCrplus1ex2            1.0*FIT_spinCr * FIT_ex
//Mnplus6===========================
#define wspinMnplus6            1.0*FIT_spinMn
//Mnplus5===========================
#define wspinMnplus5            1.0*FIT_spinMn
//Mnplus5ex===========================
#define wspinMnplus5ex            1.0*FIT_spinMn * FIT_ex
//Mnplus4===========================
#define wspinMnplus4            1.0*FIT_spinMn
//Mnplus4ex===========================
#define wspinMnplus4ex            1.0*FIT_spinMn * FIT_ex
//Mnplus3===========================
#define wspinMnplus3            1.0*FIT_spinMn
//Mnplus3ex===========================
#define wspinMnplus3ex            1.0*FIT_spinMn * FIT_ex
//Mnplus2===========================
#define wspinMnplus2            1.0*FIT_spinMn
//Mnplus2ex===========================
#define wspinMnplus2ex            1.0*FIT_spinMn * FIT_ex
//Mnplus2ex2===========================
#define wspinMnplus2ex2            1.0*FIT_spinMn * FIT_ex
//Feplus7===========================
#define wspinFeplus7            1.0*FIT_spinFe
//Feplus6===========================
#define wspinFeplus6            1.0*FIT_spinFe
//Feplus6ex===========================
#define wspinFeplus6ex            1.0*FIT_spinFe * FIT_ex
//Feplus5===========================
#define wspinFeplus5            1.0*FIT_spinFe
//Feplus5ex===========================
#define wspinFeplus5ex            1.0*FIT_spinFe * FIT_ex
//Feplus4===========================
#define wspinFeplus4            1.0*FIT_spinFe
//Feplus4ex===========================
#define wspinFeplus4ex            1.0*FIT_spinFe * FIT_ex
//Feplus4ex2===========================
#define wspinFeplus4ex2            1.0*FIT_spinFe * FIT_ex
//Feplus3===========================
#define wspinFeplus3            1.0*FIT_spinFe
//Feplus3ex===========================
#define wspinFeplus3ex            1.0*FIT_spinFe * FIT_ex
//Feplus3ex2===========================
#define wspinFeplus3ex2            1.0*FIT_spinFe * FIT_ex
//Feplus2===========================
#define wspinFeplus2            1.0*FIT_spinFe
//Feplus2ex===========================
#define wspinFeplus2ex            1.0*FIT_spinFe * FIT_ex
//Feplus2ex2===========================
#define wspinFeplus2ex2            1.0*FIT_spinFe * FIT_ex
//Coplus8===========================
#define wspinCoplus8            1.0*FIT_spinCo
//Coplus7===========================
#define wspinCoplus7            1.0*FIT_spinCo
//Coplus7ex===========================
#define wspinCoplus7ex            1.0*FIT_spinCo * FIT_ex
//Coplus6===========================
#define wspinCoplus6            1.0*FIT_spinCo
//Coplus6ex===========================
#define wspinCoplus6ex            1.0*FIT_spinCo * FIT_ex
//Coplus5===========================
#define wspinCoplus5            1.0*FIT_spinCo
//Coplus5ex===========================
#define wspinCoplus5ex            1.0*FIT_spinCo * FIT_ex
//Coplus5ex2===========================
#define wspinCoplus5ex2            1.0*FIT_spinCo * FIT_ex
//Coplus4===========================
#define wspinCoplus4            1.0*FIT_spinCo
//Coplus4ex===========================
#define wspinCoplus4ex            1.0*FIT_spinCo * FIT_ex
//Coplus4ex2===========================
#define wspinCoplus4ex2            1.0*FIT_spinCo * FIT_ex
//Coplus3===========================
#define wspinCoplus3            1.0*FIT_spinCo
//Coplus3ex===========================
#define wspinCoplus3ex            1.0*FIT_spinCo * FIT_ex
//Coplus3ex2===========================
#define wspinCoplus3ex2            1.0*FIT_spinCo * FIT_ex
//Coplus2===========================
#define wspinCoplus2            1.0*FIT_spinCo
//Coplus2ex===========================
#define wspinCoplus2ex            1.0*FIT_spinCo * FIT_ex
//Coplus2ex2===========================
#define wspinCoplus2ex2            1.0*FIT_spinCo * FIT_ex
//Niplus9===========================
#define wspinNiplus9            1.0*FIT_spinNi
//Niplus8===========================
#define wspinNiplus8            1.0*FIT_spinNi
//Niplus8ex===========================
#define wspinNiplus8ex            1.0*FIT_spinNi * FIT_ex
//Niplus7===========================
#define wspinNiplus7            1.0*FIT_spinNi
//Niplus7ex===========================
#define wspinNiplus7ex            1.0*FIT_spinNi * FIT_ex
//Niplus6===========================
#define wspinNiplus6            1.0*FIT_spinNi
//Niplus6ex===========================
#define wspinNiplus6ex            1.0*FIT_spinNi * FIT_ex
//Niplus5===========================
#define wspinNiplus5            1.0*FIT_spinNi
//Niplus5ex===========================
#define wspinNiplus5ex            1.0*FIT_spinNi * FIT_ex
//Niplus5ex2===========================
#define wspinNiplus5ex2            1.0*FIT_spinNi * FIT_ex
//Niplus4===========================
#define wspinNiplus4            1.0*FIT_spinNi
//Niplus4ex===========================
#define wspinNiplus4ex            1.0*FIT_spinNi * FIT_ex
//Niplus4ex2===========================
#define wspinNiplus4ex2            1.0*FIT_spinNi * FIT_ex
//Niplus3===========================
#define wspinNiplus3            1.0*FIT_spinNi
//Niplus3ex===========================
#define wspinNiplus3ex            1.0*FIT_spinNi * FIT_ex
//Niplus3ex2===========================
#define wspinNiplus3ex2            1.0*FIT_spinNi * FIT_ex
//Niplus2===========================
#define wspinNiplus2            1.0*FIT_spinNi
//Niplus2ex===========================
#define wspinNiplus2ex            1.0*FIT_spinNi * FIT_ex
//Niplus2ex2===========================
#define wspinNiplus2ex2            1.0*FIT_spinNi * FIT_ex
//Cuplus10===========================
#define wspinCuplus10            1.0*FIT_spinCu
//Cuplus9===========================
#define wspinCuplus9            1.0*FIT_spinCu
//Cuplus9ex===========================
#define wspinCuplus9ex            1.0*FIT_spinCu * FIT_ex
//Cuplus8===========================
#define wspinCuplus8            1.0*FIT_spinCu
//Cuplus7===========================
#define wspinCuplus7            1.0*FIT_spinCu
//Cuplus6===========================
#define wspinCuplus6            1.0*FIT_spinCu
//Cuplus5===========================
#define wspinCuplus5            1.0*FIT_spinCu
//Cuplus5ex===========================
#define wspinCuplus5ex            1.0*FIT_spinCu * FIT_ex
//Cuplus5ex2===========================
#define wspinCuplus5ex2            1.0*FIT_spinCu * FIT_ex
//Cuplus4===========================
#define wspinCuplus4            1.0*FIT_spinCu
//Cuplus4ex===========================
#define wspinCuplus4ex            1.0*FIT_spinCu * FIT_ex
//Cuplus4ex2===========================
#define wspinCuplus4ex2            1.0*FIT_spinCu * FIT_ex
//Cuplus3===========================
#define wspinCuplus3            1.0*FIT_spinCu
//Cuplus3ex===========================
#define wspinCuplus3ex            1.0*FIT_spinCu * FIT_ex
//Cuplus3ex2===========================
#define wspinCuplus3ex2            1.0*FIT_spinCu * FIT_ex
//Cuplus2===========================
#define wspinCuplus2            1.0*FIT_spinCu
//Cuplus2ex===========================
#define wspinCuplus2ex            1.0*FIT_spinCu * FIT_ex
//Cuplus1===========================
#define wspinCuplus1            1.0*FIT_spinCu
//Cuplus1ex===========================
#define wspinCuplus1ex            1.0*FIT_spinCu * FIT_ex

//Yplus2===========================
#define wspinYplus2            1.0*FIT_spinY
//Zrplus3===========================
#define wspinZrplus3            1.0*FIT_spinZr
//Zrplus2===========================
#define wspinZrplus2            1.0*FIT_spinZr
//Zrplus2ex===========================
#define wspinZrplus2ex            1.0*FIT_spinZr * FIT_ex
//Nbplus4===========================
#define wspinNbplus4            1.0*FIT_spinNb
//Nbplus3===========================
#define wspinNbplus3            1.0*FIT_spinNb
//Nbplus3ex===========================
#define wspinNbplus3ex            1.0*FIT_spinNb * FIT_ex
//Nbplus2===========================
#define wspinNbplus2            1.0*FIT_spinNb
//Nbplus2ex===========================
#define wspinNbplus2ex            1.0*FIT_spinNb * FIT_ex
//Nbplus1===========================
#define wspinNbplus1            1.0*FIT_spinNb
//Nbplus1ex===========================
#define wspinNbplus1ex            1.0*FIT_spinNb * FIT_ex
//Nbplus1ex2===========================
#define wspinNbplus1ex2            1.0*FIT_spinNb * FIT_ex
//Moplus5===========================
#define wspinMoplus5            1.0*FIT_spinMo
//Moplus4===========================
#define wspinMoplus4            1.0*FIT_spinMo
//Moplus4ex===========================
#define wspinMoplus4ex            1.0*FIT_spinMo * FIT_ex
//Moplus3===========================
#define wspinMoplus3            1.0*FIT_spinMo
//Moplus3ex===========================
#define wspinMoplus3ex            1.0*FIT_spinMo * FIT_ex
//Moplus2===========================
#define wspinMoplus2            1.0*FIT_spinMo
//Moplus2ex===========================
#define wspinMoplus2ex            1.0*FIT_spinMo * FIT_ex
//Moplus2ex2===========================
#define wspinMoplus2ex2            1.0*FIT_spinMo * FIT_ex
//Moplus1===========================
#define wspinMoplus1            1.0*FIT_spinMo
//Moplus1ex===========================
#define wspinMoplus1ex            1.0*FIT_spinMo * FIT_ex
//Moplus1ex2===========================
#define wspinMoplus1ex2            1.0*FIT_spinMo * FIT_ex
//Tcplus6===========================
#define wspinTcplus6            1.0*FIT_spinTc
//Tcplus5===========================
#define wspinTcplus5            1.0*FIT_spinTc
//Tcplus4===========================
#define wspinTcplus4            1.0*FIT_spinTc
//Tcplus3===========================
#define wspinTcplus3            1.0*FIT_spinTc
//Tcplus2===========================
#define wspinTcplus2            1.0*FIT_spinTc
//Ruplus7===========================
#define wspinRuplus7            1.0*FIT_spinRu
//Ruplus6===========================
#define wspinRuplus6            1.0*FIT_spinRu
//Ruplus5===========================
#define wspinRuplus5            1.0*FIT_spinRu
//Ruplus4===========================
#define wspinRuplus4            1.0*FIT_spinRu
//Ruplus3===========================
#define wspinRuplus3            1.0*FIT_spinRu
//Ruplus2===========================
#define wspinRuplus2            1.0*FIT_spinRu
//Ruplus2ex===========================
#define wspinRuplus2ex            1.0*FIT_spinRu * FIT_ex
//Ruplus1===========================
#define wspinRuplus1            1.0*FIT_spinRu
//Ruplus1ex===========================
#define wspinRuplus1ex            1.0*FIT_spinRu * FIT_ex
//Ruplus1ex2===========================
#define wspinRuplus1ex2            1.0*FIT_spinRu * FIT_ex
//Rhplus8===========================
#define wspinRhplus8            1.0*FIT_spinRh
//Rhplus7===========================
#define wspinRhplus7            1.0*FIT_spinRh
//Rhplus6===========================
#define wspinRhplus6            1.0*FIT_spinRh
//Rhplus5===========================
#define wspinRhplus5            1.0*FIT_spinRh
//Rhplus4===========================
#define wspinRhplus4            1.0*FIT_spinRh
//Rhplus3===========================
#define wspinRhplus3            1.0*FIT_spinRh
//Rhplus2===========================
#define wspinRhplus2            1.0*FIT_spinRh
//Rhplus2ex===========================
#define wspinRhplus2ex            1.0*FIT_spinRh * FIT_ex
//Rhplus2ex2===========================
#define wspinRhplus2ex2            1.0*FIT_spinRh * FIT_ex
//Rhplus1===========================
#define wspinRhplus1            1.0*FIT_spinRh
//Rhplus1ex===========================
#define wspinRhplus1ex            1.0*FIT_spinRh * FIT_ex
//Rhplus1ex2===========================
#define wspinRhplus1ex2            1.0*FIT_spinRh * FIT_ex
//Pdplus9===========================
#define wspinPdplus9            1.0*FIT_spinPd
//Pdplus8===========================
#define wspinPdplus8            1.0*FIT_spinPd
//Pdplus7===========================
#define wspinPdplus7            1.0*FIT_spinPd
//Pdplus6===========================
#define wspinPdplus6            1.0*FIT_spinPd
//Pdplus5===========================
#define wspinPdplus5            1.0*FIT_spinPd
//Pdplus4===========================
#define wspinPdplus4            1.0*FIT_spinPd
//Pdplus3===========================
#define wspinPdplus3            1.0*FIT_spinPd
//Pdplus2===========================
#define wspinPdplus2            1.0*FIT_spinPd
//Pdplus2ex===========================
#define wspinPdplus2ex            1.0*FIT_spinPd * FIT_ex
//Pdplus2ex2===========================
#define wspinPdplus2ex2            1.0*FIT_spinPd * FIT_ex
//Pdplus1===========================
#define wspinPdplus1            1.0*FIT_spinPd
//Pdplus1ex===========================
#define wspinPdplus1ex            1.0*FIT_spinPd * FIT_ex
//Pdneutrl===========================
#define wspinPdneutrl            1.0*FIT_spinPd
//Pdneutrlex===========================
#define wspinPdneutrlex            1.0*FIT_spinPd * FIT_ex
//Agplus10===========================
#define wspinAgplus10            1.0*FIT_spinAg
//Agplus9===========================
#define wspinAgplus9            1.0*FIT_spinAg
//Agplus8===========================
#define wspinAgplus8            1.0*FIT_spinAg
//Agplus7===========================
#define wspinAgplus7            1.0*FIT_spinAg
//Agplus6===========================
#define wspinAgplus6            1.0*FIT_spinAg
//Agplus5===========================
#define wspinAgplus5            1.0*FIT_spinAg
//Agplus4===========================
#define wspinAgplus4            1.0*FIT_spinAg
//Agplus3===========================
#define wspinAgplus3            1.0*FIT_spinAg
//Agplus2===========================
#define wspinAgplus2            1.0*FIT_spinAg
//Agplus2ex===========================
#define wspinAgplus2ex            1.0*FIT_spinAg * FIT_ex
//Agplus1===========================
#define wspinAgplus1            1.0*FIT_spinAg
//Agplus1ex===========================
#define wspinAgplus1ex            1.0*FIT_spinAg * FIT_ex
//Cdplus11===========================
#define wspinCdplus11            1.0*FIT_spinCd
//Cdplus10===========================
#define wspinCdplus10            1.0*FIT_spinCd
//Cdplus9===========================
#define wspinCdplus9            1.0*FIT_spinCd
//Cdplus8===========================
#define wspinCdplus8            1.0*FIT_spinCd
//Cdplus7===========================
#define wspinCdplus7            1.0*FIT_spinCd
//Cdplus6===========================
#define wspinCdplus6            1.0*FIT_spinCd
//Cdplus5===========================
#define wspinCdplus5            1.0*FIT_spinCd
//Cdplus4===========================
#define wspinCdplus4            1.0*FIT_spinCd
//Cdplus3===========================
#define wspinCdplus3            1.0*FIT_spinCd
//Cdplus3ex===========================
#define wspinCdplus3ex            1.0*FIT_spinCd * FIT_ex
//Cdplus2===========================
#define wspinCdplus2            1.0*FIT_spinCd
//Cdplus2ex===========================
#define wspinCdplus2ex            1.0*FIT_spinCd * FIT_ex


//Znplus1===========================
#define wspinZnplus1            1.0*FIT_spinZn
//Znplus1ex===========================
#define wspinZnplus1ex            1.0*FIT_spinZn * FIT_ex
//Znneutrl===========================
#define wspinZnneutrl            1.0*FIT_spinZn
//Znneutrlex===========================
#define wspinZnneutrlex            1.0*FIT_spinZn * FIT_ex
//Cuneutrl===========================
#define wspinCuneutrl            1.0*FIT_spinCu
//Cuneutrlex===========================
#define wspinCuneutrlex            1.0*FIT_spinCu * FIT_ex
//Niplus1===========================
#define wspinNiplus1            1.0*FIT_spinNi
//Niplus1ex===========================
#define wspinNiplus1ex            1.0*FIT_spinNi * FIT_ex
//Nineutrl===========================
#define wspinNineutrl            1.0*FIT_spinNi
//Nineutrlex===========================
#define wspinNineutrlex            1.0*FIT_spinNi * FIT_ex
//Coplus1===========================
#define wspinCoplus1            1.0*FIT_spinCo
//Coplus1ex===========================
#define wspinCoplus1ex            1.0*FIT_spinCo * FIT_ex
//Coplus1ex2===========================
#define wspinCoplus1ex2            1.0*FIT_spinCo * FIT_ex
//Coneutrl===========================
#define wspinConeutrl            1.0*FIT_spinCo
//Coneutrlex===========================
#define wspinConeutrlex            1.0*FIT_spinCo * FIT_ex
//Feplus1===========================
#define wspinFeplus1            1.0*FIT_spinFe
//Feplus1ex===========================
#define wspinFeplus1ex            1.0*FIT_spinFe * FIT_ex
//Feplus1ex2===========================
#define wspinFeplus1ex2            1.0*FIT_spinFe * FIT_ex
//Feneutrl===========================
#define wspinFeneutrl            1.0*FIT_spinFe
//Feneutrlex===========================
#define wspinFeneutrlex            1.0*FIT_spinFe * FIT_ex
//Feneutrlex2===========================
#define wspinFeneutrlex2            1.0*FIT_spinFe * FIT_ex
//Feneutrlex3===========================
#define wspinFeneutrlex3            1.0*FIT_spinFe * FIT_ex
//Mnplus1===========================
#define wspinMnplus1            1.0*FIT_spinMn
//Mnplus1ex===========================
#define wspinMnplus1ex            1.0*FIT_spinMn * FIT_ex
//Mnplus1ex2===========================
#define wspinMnplus1ex2            1.0*FIT_spinMn * FIT_ex
//Mnplus1ex3===========================
#define wspinMnplus1ex3            1.0*FIT_spinMn * FIT_ex
//Mnneutrl===========================
#define wspinMnneutrl            1.0*FIT_spinMn
//Mnneutrlex===========================
#define wspinMnneutrlex            1.0*FIT_spinMn * FIT_ex
//Mnneutrlex2===========================
#define wspinMnneutrlex2            1.0*FIT_spinMn * FIT_ex
//Mnneutrlex3===========================
#define wspinMnneutrlex3            1.0*FIT_spinMn * FIT_ex
//Crneutrl===========================
#define wspinCrneutrl            1.0*FIT_spinCr
//Crneutrlex===========================
#define wspinCrneutrlex            1.0*FIT_spinCr * FIT_ex
//Crneutrlex2===========================
#define wspinCrneutrlex2            1.0*FIT_spinCr * FIT_ex
//Crneutrlex3===========================
#define wspinCrneutrlex3            1.0*FIT_spinCr * FIT_ex
//Vplus1===========================
#define wspinVplus1            1.0*FIT_spinV
//Vplus1ex===========================
#define wspinVplus1ex            1.0*FIT_spinV * FIT_ex
//Vplus1ex2===========================
#define wspinVplus1ex2            1.0*FIT_spinV * FIT_ex
//Vneutrl===========================
#define wspinVneutrl            1.0*FIT_spinV
//Vneutrlex===========================
#define wspinVneutrlex            1.0*FIT_spinV * FIT_ex
//Vneutrlex2===========================
#define wspinVneutrlex2            1.0*FIT_spinV * FIT_ex
//Tiplus1===========================
#define wspinTiplus1            1.0*FIT_spinTi
//Tiplus1ex===========================
#define wspinTiplus1ex            1.0*FIT_spinTi * FIT_ex
//Tineutrl===========================
#define wspinTineutrl            1.0*FIT_spinTi
//Tineutrlex===========================
#define wspinTineutrlex            1.0*FIT_spinTi * FIT_ex
//Tineutrlex2===========================
#define wspinTineutrlex2            1.0*FIT_spinTi * FIT_ex
//Scplus1===========================
#define wspinScplus1            1.0*FIT_spinSc
//Scplus1ex===========================
#define wspinScplus1ex            1.0*FIT_spinSc * FIT_ex
//Scneutrl===========================
#define wspinScneutrl            1.0*FIT_spinSc
//Scneutrlex===========================
#define wspinScneutrlex            1.0*FIT_spinSc * FIT_ex

//Cdplus1===========================
#define wspinCdplus1            1.0*FIT_spinCd
//Cdplus1ex===========================
#define wspinCdplus1ex            1.0*FIT_spinCd * FIT_ex
//Cdneutrl===========================
#define wspinCdneutrl            1.0*FIT_spinCd
//Cdneutrlex===========================
#define wspinCdneutrlex            1.0*FIT_spinCd * FIT_ex
//Agneutrl===========================
#define wspinAgneutrl            1.0*FIT_spinAg
//Agneutrlex===========================
#define wspinAgneutrlex            1.0*FIT_spinAg * FIT_ex
//Rhneutrl===========================
#define wspinRhneutrl            1.0*FIT_spinRh
//Rhneutrlex===========================
#define wspinRhneutrlex            1.0*FIT_spinRh * FIT_ex
//Runeutrl===========================
#define wspinRuneutrl            1.0*FIT_spinRu
//Runeutrlex===========================
#define wspinRuneutrlex            1.0*FIT_spinRu * FIT_ex
//Runeutrlex2===========================
#define wspinRuneutrlex2            1.0*FIT_spinRu * FIT_ex
//Tcplus1===========================
#define wspinTcplus1            1.0*FIT_spinTc
//Tcplus1ex===========================
#define wspinTcplus1ex            1.0*FIT_spinTc * FIT_ex
//Tcneutrl===========================
#define wspinTcneutrl            1.0*FIT_spinTc
//Tcneutrlex===========================
#define wspinTcneutrlex            1.0*FIT_spinTc * FIT_ex
//Tcneutrlex2===========================
#define wspinTcneutrlex2            1.0*FIT_spinTc * FIT_ex
//Tcneutrlex3===========================
#define wspinTcneutrlex3            1.0*FIT_spinTc * FIT_ex
//Moneutrl===========================
#define wspinMoneutrl            1.0*FIT_spinMo
//Moneutrlex===========================
#define wspinMoneutrlex            1.0*FIT_spinMo * FIT_ex
//Moneutrlex2===========================
#define wspinMoneutrlex2            1.0*FIT_spinMo * FIT_ex
//Moneutrlex3===========================
#define wspinMoneutrlex3            1.0*FIT_spinMo * FIT_ex
//Nbneutrl===========================
#define wspinNbneutrl            1.0*FIT_spinNb
//Nbneutrlex===========================
#define wspinNbneutrlex            1.0*FIT_spinNb * FIT_ex
//Nbneutrlex2===========================
#define wspinNbneutrlex2            1.0*FIT_spinNb * FIT_ex
//Zrplus1===========================
#define wspinZrplus1            1.0*FIT_spinZr
//Zrplus1ex===========================
#define wspinZrplus1ex            1.0*FIT_spinZr * FIT_ex
//Zrneutrl===========================
#define wspinZrneutrl            1.0*FIT_spinZr
//Zrneutrlex===========================
#define wspinZrneutrlex            1.0*FIT_spinZr * FIT_ex
//Zrneutrlex2===========================
#define wspinZrneutrlex2            1.0*FIT_spinZr * FIT_ex
//Yplus1===========================
#define wspinYplus1            1.0*FIT_spinY
//Yplus1ex===========================
#define wspinYplus1ex            1.0*FIT_spinY * FIT_ex
//Yneutrl===========================
#define wspinYneutrl            1.0*FIT_spinY
//Yneutrlex===========================
#define wspinYneutrlex            1.0*FIT_spinY * FIT_ex



//H2O.H+.H2O========================
#define wspinZundelrOO              3.0
#define wspinZundelPsi              0.0
#define wspinZundelrHcent           3.0
//sum-------------------------------
#define wspinZundel                 6.0*FIT_dimer

//H2O..OH-==========================
#define wspinDeprotonatedDimerrOO   4.0
#define wspinDeprotonatedDimerrOH   0.0
#define wspinDeprotonatedDimerDihedral 4.0
//sum------------------------------- 
#define wspinDeprotonatedDimer      8.0*FIT_dimer

//H2O..H2O==========================
#define wspinH4O2rOO                8.0
//#define wspinH4O2rDonorOH           0.0
#define wspinH4O2angleD             1.5
#define wspinH4O2angleA             1.5
//sum-------------------------------
#define wspinH4O2                  11.0*FIT_dimer


//NO OF PARAMETERS FOR EACH KIND===
#define n_AB			 26
#define n_AH			 13
#define n_CA			 13
#define n_NA			 13
#define n_OA			 13
#define n_CH			  6
#define n_NH			  6
#define n_OH			  6
#define n_CC			  6
#define n_NN			  6
#define n_OO			  6
#define n_CN			  6
#define n_CO			  6
#define n_NO			  6
#define n_HH			  6
#define n_FA			 13
#define n_SA			 13
#define n_PA			 13
#define n_SiA			 13
#define n_BoA			 13
#define n_AlA			 13
#define n_ClA			 13
#define n_NaA			 13
#define n_LiA			 13
#define n_BeA			 13
#define n_MgA			 13
#define n_FeA                     13
#define n_MA                     13
//sum------------------------------
#define n_potentials		307

//DEGREES OF FREEDOM================
#define n_spinOH		  7
#define n_spinH2		  6
#define n_spinH2trp		 10
#define n_spinH2v		  2
#define n_spinOHdot		  9
#define n_spinOHdot2		 13 
#define n_spinH2O		  7
#define n_spinH2Olinear           4
#define n_spinH2Oplus		  6
#define n_spinH3O		  5
#define n_spinH2plus		  3
#define n_spinH2minus		 10
#define n_spinH3plus		  6
#define n_spinH3		  8
#define n_spinH4	          7
#define n_spinH3linear            7
#define n_spinH3trig              3
#define n_spinH4linear            7
#define n_spinH4square            4
#define n_spinH4tetra             3

#define n_spinH                   1
#define n_spinH_                  4
#define n_spinH_trp               4


#define n_spinZundel             12
#define n_spinO2_2v               4
#define n_spinDeprotonatedDimer  10 
#define n_spindimer               3

#define n_spinO_2                 2
#define n_spinO2                  9
#define n_spinO2dia               6
#define n_spinO2_1                8
#define n_spinO2_2               10
#define n_spinO2plus              5

#define n_TransitionspinH2	  n_spinH2
#define n_TransitionspinH2plus	 n_spinH2plus
#define n_TransitiontripletH2	 n_spinH2
#define n_TransitionspinH2minus	 n_spinH2minus
#define n_TransitionspinOHdot	 n_spinOHdot
#define n_TransitionspinOHdot2   n_spinOHdot2
#define n_TransitionspinOH	 n_spinOH
#define n_TransitionspinH3plus 	 n_spinH3plus


#define n_spinO_1                       8
#define n_spinOneutrlex2                4
#define n_spinOneutrlex                 5
#define n_spinOneutrl                   5
#define n_spinOplus1ex2                  3
#define n_spinOplus1ex                   4
#define n_spinOplus1                    4
#define n_spinOplus2ex2                 3
#define n_spinOplus2ex                  4
#define n_spinOplus2                    5
#define n_spinOplus3ex                  2
#define n_spinOplus3                    5
#define n_spinOplus4ex                  2
#define n_spinOplus4                    2
#define n_spinOplus5                    1
#define n_spinS_1                       8
#define n_spinSneutrlex2                4
#define n_spinSneutrlex                 5
#define n_spinSneutrl                   5
#define n_spinSplus1ex                   4
#define n_spinSplus1                    4
#define n_spinSplus2ex2                 3
#define n_spinSplus2ex                  4
#define n_spinSplus2                    5
#define n_spinSplus3ex                  2
#define n_spinSplus3                    5
#define n_spinSplus4ex                  2
#define n_spinSplus4                    2
#define n_spinSplus5                    1
#define n_spinN_1                       5
#define n_spinNneutrlex2                3
#define n_spinNneutrlex                 4
#define n_spinNneutrl                   4
#define n_spinNplus1ex2                  3
#define n_spinNplus1ex                   4
#define n_spinNplus1                    5
#define n_spinNplus2ex                  2
#define n_spinNplus2                    5
#define n_spinNplus3ex                  2
#define n_spinNplus3                    2
#define n_spinNplus4                    1
#define n_spinP_1                       5
#define n_spinPneutrlex                 4
#define n_spinPneutrl                   4
#define n_spinPplus1ex2                  3
#define n_spinPplus1ex                   4
#define n_spinPplus1                    5
#define n_spinPplus2ex                  2
#define n_spinPplus2                    5
#define n_spinPplus3ex                  2
#define n_spinPplus3                    2
#define n_spinPplus4                    1
#define n_spinC_1                       4
#define n_spinCneutrlex2                3
#define n_spinCneutrlex                 4
#define n_spinCneutrl                   5
#define n_spinCplus1ex                   2
#define n_spinCplus1                    5
#define n_spinCplus2ex                  2
#define n_spinCplus2                    2
#define n_spinCplus3                    1
#define n_spinSi_1                      4
#define n_spinSineutrlex2               3
#define n_spinSineutrlex                4
#define n_spinSineutrl                  5
#define n_spinSiplus1ex                  2
#define n_spinSiplus1                   5
#define n_spinSiplus2ex                 2
#define n_spinSiplus2                   2
#define n_spinSiplus3                   1
#define n_spinB_1                       5
#define n_spinBneutrlex                 2
#define n_spinBneutrl                   5
#define n_spinBplus1ex                   2
#define n_spinBplus1                    2
#define n_spinBplus2                    1

#define n_spinF_1                       2
#define n_spinFneutrl                   8
#define n_spinFneutrlex                 5
#define n_spinFplus1                    5
#define n_spinFplus1ex                   5
#define n_spinFplus1ex2                  4
#define n_spinFplus2                    4
#define n_spinFplus2ex                  4
#define n_spinFplus2ex2                 3
#define n_spinFplus3                    5
#define n_spinFplus3ex                  4
#define n_spinFplus3ex2                 3
#define n_spinFplus4                    5
#define n_spinFplus4ex                  2
#define n_spinFplus5                    2
#define n_spinFplus5ex                  2
#define n_spinFplus6                    1

#define n_spinCl_1                 2
#define n_spinClneutrlex                 5
#define n_spinClneutrl                 8
#define n_spinClplus1ex2                 4
#define n_spinClplus1ex                 5
#define n_spinClplus1                5
#define n_spinClplus2ex                 4
#define n_spinClplus2                 4
#define n_spinClplus3ex2                 3
#define n_spinClplus3ex                 4
#define n_spinClplus3                 5
#define n_spinClplus4ex                 2
#define n_spinClplus4                 5
#define n_spinClplus5ex                 2
#define n_spinClplus5                 2
#define n_spinClplus6                 1
#define n_spinAl_1                 5
#define n_spinAlneutrlex                 2
#define n_spinAlneutrl                 5
#define n_spinAlplus1ex                 2
#define n_spinAlplus1                2
#define n_spinAlplus2                 1

#define n_spinLi_1                 4
#define n_spinLineutrl                 1
#define n_spinBeneutrl                 4
#define n_spinBeneutrlex                 2
#define n_spinBeplus1                1
#define n_spinNa_1                 4
#define n_spinNaneutrl                 1
#define n_spinMgneutrl                 4
#define n_spinMgneutrlex                 2
#define n_spinMgplus1                1

#define n_spinZnplus11			1
#define n_spinZnplus10			4
#define n_spinZnplus10ex		4
#define n_spinZnplus9			5
#define n_spinZnplus8			5
#define n_spinZnplus7			4
#define n_spinZnplus6			5
#define n_spinZnplus6ex			5
#define n_spinZnplus6ex2		5
#define n_spinZnplus5			5
#define n_spinZnplus5ex			8
#define n_spinZnplus5ex2		8
#define n_spinZnplus4			2
#define n_spinZnplus4ex			2
#define n_spinZnplus4ex2		2
#define n_spinZnplus3			8
#define n_spinZnplus3ex			8
#define n_spinZnplus2			5
#define n_spinZnplus2ex			5
#define n_spinScplus2		1
#define n_spinTiplus3		1
#define n_spinTiplus2		4
#define n_spinTiplus2ex		4
#define n_spinVplus4		1
#define n_spinVplus3		4
#define n_spinVplus3ex		4
#define n_spinVplus2		5
#define n_spinVplus2ex		5
#define n_spinCrplus5		1
#define n_spinCrplus4		4
#define n_spinCrplus4ex		4
#define n_spinCrplus3		5
#define n_spinCrplus3ex		5
#define n_spinCrplus2		5
#define n_spinCrplus2ex		5
#define n_spinCrplus2ex2	5
#define n_spinCrplus1		4
#define n_spinCrplus1ex		4
#define n_spinCrplus1ex2	4
#define n_spinMnplus6		1
#define n_spinMnplus5		4
#define n_spinMnplus5ex		4
#define n_spinMnplus4		5
#define n_spinMnplus4ex		5
#define n_spinMnplus3		5
#define n_spinMnplus3ex		5
#define n_spinMnplus2		4
#define n_spinMnplus2ex		4
#define n_spinMnplus2ex2	4
#define n_spinFeplus7		1
#define n_spinFeplus6		4
#define n_spinFeplus6ex		4
#define n_spinFeplus5		5
#define n_spinFeplus5ex		5
#define n_spinFeplus4		5
#define n_spinFeplus4ex		5
#define n_spinFeplus4ex2	5
#define n_spinFeplus3		4
#define n_spinFeplus3ex		4
#define n_spinFeplus3ex2	4
#define n_spinFeplus2		5
#define n_spinFeplus2ex		5
#define n_spinFeplus2ex2	5
#define n_spinCoplus8		1
#define n_spinCoplus7		4
#define n_spinCoplus7ex		4
#define n_spinCoplus6		5
#define n_spinCoplus6ex		5
#define n_spinCoplus5		5
#define n_spinCoplus5ex		5
#define n_spinCoplus5ex2	5
#define n_spinCoplus4		4
#define n_spinCoplus4ex		4
#define n_spinCoplus4ex2	4
#define n_spinCoplus3		5
#define n_spinCoplus3ex		5
#define n_spinCoplus3ex2	5
#define n_spinCoplus2		5
#define n_spinCoplus2ex		8
#define n_spinCoplus2ex2	8
#define n_spinNiplus9		1
#define n_spinNiplus8		4
#define n_spinNiplus8ex		4
#define n_spinNiplus7		5
#define n_spinNiplus7ex		5
#define n_spinNiplus6		5
#define n_spinNiplus6ex		5
#define n_spinNiplus5		4
#define n_spinNiplus5ex		4
#define n_spinNiplus5ex2	4
#define n_spinNiplus4		5
#define n_spinNiplus4ex		5
#define n_spinNiplus4ex2	5
#define n_spinNiplus3		5
#define n_spinNiplus3ex		8
#define n_spinNiplus3ex2	8
#define n_spinNiplus2		2
#define n_spinNiplus2ex		2
#define n_spinNiplus2ex2	2
#define n_spinCuplus10		1
#define n_spinCuplus9		4
#define n_spinCuplus9ex		4
#define n_spinCuplus8		5
#define n_spinCuplus7		5
#define n_spinCuplus6		4
#define n_spinCuplus5		5
#define n_spinCuplus5ex		5
#define n_spinCuplus5ex2	5
#define n_spinCuplus4		5
#define n_spinCuplus4ex		8
#define n_spinCuplus4ex2	8
#define n_spinCuplus3		2
#define n_spinCuplus3ex		2
#define n_spinCuplus3ex2	2
#define n_spinCuplus2		8
#define n_spinCuplus2ex		8
#define n_spinCuplus1		5
#define n_spinCuplus1ex		5
#define n_spinYplus2		1
#define n_spinZrplus3		1
#define n_spinZrplus2		4
#define n_spinZrplus2ex		4
#define n_spinNbplus4		1
#define n_spinNbplus3		4
#define n_spinNbplus3ex		4
#define n_spinNbplus2		5
#define n_spinNbplus2ex		5
#define n_spinNbplus1		5
#define n_spinNbplus1ex		5
#define n_spinNbplus1ex2		5
#define n_spinMoplus5		1
#define n_spinMoplus4		4
#define n_spinMoplus4ex		4
#define n_spinMoplus3		5
#define n_spinMoplus3ex		5
#define n_spinMoplus2		5
#define n_spinMoplus2ex		5
#define n_spinMoplus2ex2		5
#define n_spinMoplus1		4
#define n_spinMoplus1ex		4
#define n_spinMoplus1ex2		4
#define n_spinTcplus6		1
#define n_spinTcplus5		4
#define n_spinTcplus4		5
#define n_spinTcplus3		5
#define n_spinTcplus2		4
#define n_spinRuplus7		1
#define n_spinRuplus6		4
#define n_spinRuplus5		5
#define n_spinRuplus4		5
#define n_spinRuplus3		4
#define n_spinRuplus2		5
#define n_spinRuplus2ex		5
#define n_spinRuplus1		5
#define n_spinRuplus1ex		8
#define n_spinRuplus1ex2		8
#define n_spinRhplus8		1
#define n_spinRhplus7		4
#define n_spinRhplus6		5
#define n_spinRhplus5		5
#define n_spinRhplus4		4
#define n_spinRhplus3		5
#define n_spinRhplus2		2
#define n_spinRhplus2ex		8
#define n_spinRhplus2ex2		8
#define n_spinRhplus1		2
#define n_spinRhplus1ex		2
#define n_spinRhplus1ex2		2
#define n_spinPdplus9		1
#define n_spinPdplus8		4
#define n_spinPdplus7		5
#define n_spinPdplus6		5
#define n_spinPdplus5		4
#define n_spinPdplus4		5
#define n_spinPdplus3		3
#define n_spinPdplus2		2
#define n_spinPdplus2ex		2
#define n_spinPdplus2ex2		2
#define n_spinPdplus1		8
#define n_spinPdplus1ex		8
#define n_spinPdneutrl		5
#define n_spinPdneutrlex		5
#define n_spinAgplus10		1
#define n_spinAgplus9		4
#define n_spinAgplus8		5
#define n_spinAgplus7		5
#define n_spinAgplus6		4
#define n_spinAgplus5		5
#define n_spinAgplus4		5
#define n_spinAgplus3		2
#define n_spinAgplus2		8
#define n_spinAgplus2ex		8
#define n_spinAgplus1		5
#define n_spinAgplus1ex		5
#define n_spinCdplus11		1
#define n_spinCdplus10		4
#define n_spinCdplus9		5
#define n_spinCdplus8		5
#define n_spinCdplus7		4
#define n_spinCdplus6		5
#define n_spinCdplus5		8
#define n_spinCdplus4		2
#define n_spinCdplus3		8
#define n_spinCdplus3ex		8
#define n_spinCdplus2		5
#define n_spinCdplus2ex		5


#define n_spinZnplus1		5
#define n_spinZnplus1ex		5
#define n_spinZnneutrl		5
#define n_spinZnneutrlex		5
#define n_spinCuneutrl		5
#define n_spinCuneutrlex		5
#define n_spinNiplus1		8
#define n_spinNiplus1ex		8
#define n_spinNineutrl		5
#define n_spinNineutrlex		5
#define n_spinCoplus1		2
#define n_spinCoplus1ex		2
#define n_spinCoplus1ex2		2
#define n_spinConeutrl		8
#define n_spinConeutrlex		8
#define n_spinFeplus1		8
#define n_spinFeplus1ex		5
#define n_spinFeplus1ex2		8
#define n_spinFeneutrl		2
#define n_spinFeneutrlex		2
#define n_spinFeneutrlex2		2
#define n_spinFeneutrlex3		2
#define n_spinMnplus1		5
#define n_spinMnplus1ex		5
#define n_spinMnplus1ex2		5
#define n_spinMnplus1ex3		5
#define n_spinMnneutrl		8
#define n_spinMnneutrlex		8
#define n_spinMnneutrlex2		5
#define n_spinMnneutrlex3		8
#define n_spinCrneutrl		5
#define n_spinCrneutrlex		5
#define n_spinCrneutrlex2		5
#define n_spinCrneutrlex3		5
#define n_spinVplus1		5
#define n_spinVplus1ex		5
#define n_spinVplus1ex2		5
#define n_spinVneutrl		4
#define n_spinVneutrlex		4
#define n_spinVneutrlex2		4
#define n_spinTiplus1		5
#define n_spinTiplus1ex		5
#define n_spinTineutrl		5
#define n_spinTineutrlex		5
#define n_spinTineutrlex2		5
#define n_spinScplus1		4
#define n_spinScplus1ex		4
#define n_spinScneutrl		5
#define n_spinScneutrlex		5

#define n_spinCdplus1		5
#define n_spinCdplus1ex		5
#define n_spinCdneutrl		5
#define n_spinCdneutrlex		5
#define n_spinAgneutrl		5
#define n_spinAgneutrlex		5
#define n_spinRhneutrl		8
#define n_spinRhneutrlex		8
#define n_spinRuneutrl		2
#define n_spinRuneutrlex		2
#define n_spinRuneutrlex2		2
#define n_spinTcplus1		5
#define n_spinTcplus1ex		5
#define n_spinTcneutrl		8
#define n_spinTcneutrlex		5
#define n_spinTcneutrlex2		8
#define n_spinTcneutrlex3		8
#define n_spinMoneutrl		5
#define n_spinMoneutrlex		5
#define n_spinMoneutrlex2		5
#define n_spinMoneutrlex3		5
#define n_spinNbneutrl		4
#define n_spinNbneutrlex		4
#define n_spinNbneutrlex2		4
#define n_spinZrplus1		5
#define n_spinZrplus1ex		5
#define n_spinZrneutrl		5
#define n_spinZrneutrlex		5
#define n_spinZrneutrlex2		5
#define n_spinYplus1		3
#define n_spinYplus1ex		3
#define n_spinYneutrl		5
#define n_spinYneutrlex		5

//NUMBERS OF PARTICLES==============
#define m_spinOH	  	 10
#define m_spinH2		  4
#define m_spinH2trp		  4
#define m_spinH2v		  4
#define m_spinOHdot		  9
#define m_spinOHdot2		  9
#define m_spinH2O		 11
#define m_spinH2Olinear          11
#define m_spinH2Oplus		 10
#define m_spinH3O		 12
#define m_spinH2plus		  3
#define m_spinH2minus		  5
#define m_spinH3plus		  5
#define m_spinH3		  6
#define m_spinH4		  8
#define m_spinH3linear            6
#define m_spinH3trig              6
#define m_spinH4linear            8
#define m_spinH4square            8
#define m_spinH4tetra             8
#define m_spinOneutrl		  7
#define m_spinO_1		  8
#define m_spinO_2		  9
#define m_spinO2		 14
#define m_spinO2dia		 14
#define m_spinO2_linnett                 14
#define m_spinO2dia_linnett              14
#define m_spinO2_snglbnd                 14
#define m_spinO2dia_snglbnd              14
#define m_spinO2_dblbnd                 14
#define m_spinO2dia_dblbnd              14
#define m_spinO2_trplbnd                 14
#define m_spinO2dia_trplbnd              14
#define m_spinO2qnt              14
#define m_spinO2qnt_linnett              14
#define m_spinO2qnt_snglbnd              14
#define m_spinO2qnt_dblbnd              14
#define m_spinO2qnt_trplbnd              14



#define m_spinO2_1		 15
#define m_spinO2_2		 16
#define m_spinO2plus		 13
#define m_spinOplus		  6
#define m_spinOplus2		  5
#define m_spinOplus3		  4
#define m_spinOplus4		  3
#define m_spinOplus5		  2
#define m_spinH                   2
#define m_spinH_		  3
#define m_spinH_trp		  3
#define m_spinZundel             23
#define m_spinO2_2v		 16
#define m_spinDeprotonatedDimer	 21
#define m_spindimer		 22
#define m_spinCplus3                       2
#define m_spinCplus2                       3
#define m_spinCplus1                      4
#define m_spinCneutrl                       5
#define m_spinC_1                       6
#define m_spinNplus4                       2
#define m_spinNplus3                       3
#define m_spinNplus2                       4
#define m_spinNplus1                      5
#define m_spinNneutrl                       6
#define m_spinN_1                       7
#define m_spinSplus5                       2
#define m_spinSplus4                       3
#define m_spinSplus3                       4
#define m_spinSplus2                       5
#define m_spinSplus1                      6
#define m_spinSneutrl                       7
#define m_spinS_1                       8
#define m_spinPplus4                       2
#define m_spinPplus3                       3
#define m_spinPplus2                       4
#define m_spinPplus1                      5
#define m_spinPneutrl                       6
#define m_spinP_1                       7
#define m_spinSiplus3                       2
#define m_spinSiplus2                       3
#define m_spinSiplus1                      4
#define m_spinSineutrl                       5
#define m_spinSi_1                       6
#define m_spinFplus6                       2
#define m_spinFplus5                       3
#define m_spinFplus4                       4
#define m_spinFplus3                       5
#define m_spinFplus2                       6
#define m_spinFplus1                      7
#define m_spinFneutrl                       8
#define m_spinF_1                       9

#define m_spinCplus2ex                       3
#define m_spinCplus1ex                       4
#define m_spinCneutrlex                       5
#define m_spinCneutrlex2                       5
#define m_spinNplus3ex                       3
#define m_spinNplus2ex                       4
#define m_spinNplus1ex                       5
#define m_spinNplus1ex2                       5
#define m_spinNneutrlex                       6
#define m_spinFplus5ex                       3
#define m_spinFplus4ex                       4
#define m_spinFplus3ex                       5
#define m_spinFplus3ex2                       5
#define m_spinFplus2ex                       6
#define m_spinFplus1ex                       7
#define m_spinSiplus2ex                       3
#define m_spinSiplus1ex                       4
#define m_spinSineutrlex                       5
#define m_spinSineutrlex2                       5
#define m_spinPplus3ex                       3
#define m_spinPplus2ex                       4
#define m_spinPplus1ex                       5
#define m_spinPplus1ex2                       5
#define m_spinPneutrlex                       6
#define m_spinSplus4ex                       3
#define m_spinSplus3ex                       4
#define m_spinSplus2ex                       5
#define m_spinSplus2ex2                       5
#define m_spinSplus1ex                       6
#define m_spinSneutrlex                       7

#define m_spinOneutrlex2                       7
#define m_spinOplus1ex2                       6
#define m_spinNneutrlex2                       6
#define m_spinFneutrlex                       8
#define m_spinFplus1ex2                       7
#define m_spinFplus2ex2                       6
#define m_spinSneutrlex2                       7

#define m_spinB_1                           5
#define m_spinBneutrlex                     4
#define m_spinBneutrl                       4
#define m_spinBplus1ex                       3
#define m_spinBplus1                        3
#define m_spinBplus2                        2


#define m_spinCl_1                       9
#define m_spinClneutrlex                       8
#define m_spinClneutrl                       8
#define m_spinClplus1ex2                       7
#define m_spinClplus1ex                       7
#define m_spinClplus1                      7
#define m_spinClplus2ex                       6
#define m_spinClplus2                       6
#define m_spinClplus3ex2                       5
#define m_spinClplus3ex                       5
#define m_spinClplus3                       5
#define m_spinClplus4ex                       4
#define m_spinClplus4                       4
#define m_spinClplus5ex                       3
#define m_spinClplus5                       3
#define m_spinClplus6                       2
#define m_spinAl_1                       5
#define m_spinAlneutrlex                       4
#define m_spinAlneutrl                       4
#define m_spinAlplus1ex                       3
#define m_spinAlplus1                      3
#define m_spinAlplus2                       2

#define m_spinAl2_trplt                       8
#define m_spinAl2_snglt                       8

#define m_spinLi_1                       3
#define m_spinLineutrl                       2
#define m_spinBeneutrl                       3
#define m_spinBeneutrlex                       3
#define m_spinBeplus1                      2
#define m_spinNa_1                       3
#define m_spinNaneutrl                       2
#define m_spinMgneutrl                       3
#define m_spinMgneutrlex                       3
#define m_spinMgplus1                      2

#define m_spinB2_trplt                       8
#define m_spinB2_snglt                       8
#define m_spinC2_trplt                       10
#define m_spinC2_snglt                       10
#define m_spinSi2_trplt                       10
#define m_spinSi2_snglt                       10
#define m_spinN2_trplt                       12
#define m_spinN2_snglt                       12
#define m_spinS2_trplt                       14
#define m_spinS2_snglt                       14
#define m_spinF2_trplt                       16
#define m_spinF2_snglt                       16
#define m_spinCl2_trplt                       16
#define m_spinCl2_snglt                       16
#define m_spinP2_trplt                       12
#define m_spinP2_snglt                       12

#define m_spinB2_snglt_linnett                   8
#define m_spinB2_snglt_snglbnd                   8
#define m_spinB2_snglt_dblbnd                   8
#define m_spinB2_snglt_trplbnd                   8
#define m_spinB2_trplt_linnett                   8
#define m_spinB2_trplt_snglbnd                   8
#define m_spinB2_trplt_dblbnd                   8
#define m_spinB2_trplt_trplbnd                   8
#define m_spinAl2_snglt_linnett                   8
#define m_spinAl2_snglt_snglbnd                   8
#define m_spinAl2_snglt_dblbnd                   8
#define m_spinAl2_snglt_trplbnd                   8
#define m_spinAl2_trplt_linnett                   8
#define m_spinAl2_trplt_snglbnd                   8
#define m_spinAl2_trplt_dblbnd                   8
#define m_spinAl2_trplt_trplbnd                   8
#define m_spinC2_snglt_linnett                   10
#define m_spinC2_snglt_snglbnd                   10
#define m_spinC2_snglt_dblbnd                   10
#define m_spinC2_snglt_trplbnd                   10
#define m_spinC2_trplt_linnett                   10
#define m_spinC2_trplt_snglbnd                   10
#define m_spinC2_trplt_dblbnd                   10
#define m_spinC2_trplt_trplbnd                   10
#define m_spinSi2_snglt_linnett                   10
#define m_spinSi2_snglt_snglbnd                   10
#define m_spinSi2_snglt_dblbnd                   10
#define m_spinSi2_snglt_trplbnd                   10
#define m_spinSi2_trplt_linnett                   10
#define m_spinSi2_trplt_snglbnd                   10
#define m_spinSi2_trplt_dblbnd                   10
#define m_spinSi2_trplt_trplbnd                   10
#define m_spinN2_snglt_linnett                   12
#define m_spinN2_snglt_snglbnd                   12
#define m_spinN2_snglt_dblbnd                   12
#define m_spinN2_snglt_trplbnd                   12
#define m_spinN2_trplt_linnett                   12
#define m_spinN2_trplt_snglbnd                   12
#define m_spinN2_trplt_dblbnd                   12
#define m_spinN2_trplt_trplbnd                   12
#define m_spinP2_snglt_linnett                   12
#define m_spinP2_snglt_snglbnd                   12
#define m_spinP2_snglt_dblbnd                   12
#define m_spinP2_snglt_trplbnd                   12
#define m_spinP2_trplt_linnett                   12
#define m_spinP2_trplt_snglbnd                   12
#define m_spinP2_trplt_dblbnd                   12
#define m_spinP2_trplt_trplbnd                   12
#define m_spinS2_snglt_linnett                   14
#define m_spinS2_snglt_snglbnd                   14
#define m_spinS2_snglt_dblbnd                   14
#define m_spinS2_snglt_trplbnd                   14
#define m_spinS2_trplt_linnett                   14
#define m_spinS2_trplt_snglbnd                   14
#define m_spinS2_trplt_dblbnd                   14
#define m_spinS2_trplt_trplbnd                   14
#define m_spinF2_snglt_linnett                   16
#define m_spinF2_snglt_snglbnd                   16
#define m_spinF2_snglt_dblbnd                   16
#define m_spinF2_snglt_trplbnd                   16
#define m_spinF2_trplt_linnett                   16
#define m_spinF2_trplt_snglbnd                   16
#define m_spinF2_trplt_dblbnd                   16
#define m_spinF2_trplt_trplbnd                   16
#define m_spinCl2_snglt_linnett                   16
#define m_spinCl2_snglt_snglbnd                   16
#define m_spinCl2_snglt_dblbnd                   16
#define m_spinCl2_snglt_trplbnd                   16
#define m_spinCl2_trplt_linnett                   16
#define m_spinCl2_trplt_snglbnd                   16
#define m_spinCl2_trplt_dblbnd                   16
#define m_spinCl2_trplt_trplbnd                   16


#define m_spinH_polar                    3
#define m_spinBneutrl_polar              5     
#define m_spinCneutrl_polar              6     
#define m_spinNneutrl_polar              7     
#define m_spinOneutrl_polar              8     
#define m_spinFneutrl_polar              9     
#define m_spinAlneutrl_polar             5      
#define m_spinSineutrl_polar             6      
#define m_spinPneutrl_polar              7     
#define m_spinSneutrl_polar              8     
#define m_spinClneutrl_polar             9      

#define m_TransitionspinH2	 m_spinH2
#define m_TransitionspinH2plus 	 m_spinH2plus
#define m_TransitiontripletH2 	m_spinH2
#define m_TransitionspinH2minus m_spinH2minus
#define m_TransitionspinOHdot	m_spinOHdot
#define m_TransitionspinOHdot2	m_spinOHdot2
#define m_TransitionspinOH	m_spinOH
#define m_TransitionspinH3plus  m_spinH3plus

#define m_spinOneutrlex		m_spinOneutrl
#define m_spinOplus2ex		m_spinOplus2
#define m_spinOplus1ex		m_spinOplus1
#define m_spinOplus4ex		m_spinOplus4
#define m_spinOplus3ex		m_spinOplus3
#define m_spinOplus2ex2          m_spinOplus2

#define m_spinZnplus11		2
#define m_spinZnplus10		3
#define m_spinZnplus10ex		3
#define m_spinZnplus9		4
#define m_spinZnplus8		5
#define m_spinZnplus7		6
#define m_spinZnplus6		7
#define m_spinZnplus6ex		7
#define m_spinZnplus6ex2		7
#define m_spinZnplus5		8
#define m_spinZnplus5ex		8
#define m_spinZnplus5ex2		8
#define m_spinZnplus4		9
#define m_spinZnplus4ex		9
#define m_spinZnplus4ex2		9
#define m_spinZnplus3		10
#define m_spinZnplus3ex		10
#define m_spinZnplus2		11
#define m_spinZnplus2ex		11
#define m_spinScplus2		2
#define m_spinTiplus3		2
#define m_spinTiplus2		3
#define m_spinTiplus2ex		3
#define m_spinVplus4		2
#define m_spinVplus3		3
#define m_spinVplus3ex		3
#define m_spinVplus2		4
#define m_spinVplus2ex		4
#define m_spinCrplus5		2
#define m_spinCrplus4		3
#define m_spinCrplus4ex		3
#define m_spinCrplus3		4
#define m_spinCrplus3ex		4
#define m_spinCrplus2		5
#define m_spinCrplus2ex		5
#define m_spinCrplus2ex2		5
#define m_spinCrplus1		6
#define m_spinCrplus1ex		6
#define m_spinCrplus1ex2		6
#define m_spinMnplus6		2
#define m_spinMnplus5		3
#define m_spinMnplus5ex		3
#define m_spinMnplus4		4
#define m_spinMnplus4ex		4
#define m_spinMnplus3		5
#define m_spinMnplus3ex		5
#define m_spinMnplus2		6
#define m_spinMnplus2ex		6
#define m_spinMnplus2ex2		6
#define m_spinFeplus7		2
#define m_spinFeplus6		3
#define m_spinFeplus6ex		3
#define m_spinFeplus5		4
#define m_spinFeplus5ex		4
#define m_spinFeplus4		5
#define m_spinFeplus4ex		5
#define m_spinFeplus4ex2		5
#define m_spinFeplus3		6
#define m_spinFeplus3ex		6
#define m_spinFeplus3ex2		6
#define m_spinFeplus2		7
#define m_spinFeplus2ex		7
#define m_spinFeplus2ex2		7
#define m_spinCoplus8		2
#define m_spinCoplus7		3
#define m_spinCoplus7ex		3
#define m_spinCoplus6		4
#define m_spinCoplus6ex		4
#define m_spinCoplus5		5
#define m_spinCoplus5ex		5
#define m_spinCoplus5ex2		5
#define m_spinCoplus4		6
#define m_spinCoplus4ex		6
#define m_spinCoplus4ex2		6
#define m_spinCoplus3		7
#define m_spinCoplus3ex		7
#define m_spinCoplus3ex2		7
#define m_spinCoplus2		8
#define m_spinCoplus2ex		8
#define m_spinCoplus2ex2		8
#define m_spinNiplus9		2
#define m_spinNiplus8		3
#define m_spinNiplus8ex		3
#define m_spinNiplus7		4
#define m_spinNiplus7ex		4
#define m_spinNiplus6		5
#define m_spinNiplus6ex		5
#define m_spinNiplus5		6
#define m_spinNiplus5ex		6
#define m_spinNiplus5ex2		6
#define m_spinNiplus4		7
#define m_spinNiplus4ex		7
#define m_spinNiplus4ex2		7
#define m_spinNiplus3		8
#define m_spinNiplus3ex		8
#define m_spinNiplus3ex2		8
#define m_spinNiplus2		9
#define m_spinNiplus2ex		9
#define m_spinNiplus2ex2		9
#define m_spinCuplus10		2
#define m_spinCuplus9		3
#define m_spinCuplus9ex		3
#define m_spinCuplus8		4
#define m_spinCuplus7		5
#define m_spinCuplus6		6
#define m_spinCuplus5		7
#define m_spinCuplus5ex		7
#define m_spinCuplus5ex2		7
#define m_spinCuplus4		8
#define m_spinCuplus4ex		8
#define m_spinCuplus4ex2		8
#define m_spinCuplus3		9
#define m_spinCuplus3ex		9
#define m_spinCuplus3ex2		9
#define m_spinCuplus2		10
#define m_spinCuplus2ex		10
#define m_spinCuplus1		11
#define m_spinCuplus1ex		11
#define m_spinYplus2		2
#define m_spinZrplus3		2
#define m_spinZrplus2		3
#define m_spinZrplus2ex		3
#define m_spinNbplus4		2
#define m_spinNbplus3		3
#define m_spinNbplus3ex		3
#define m_spinNbplus2		4
#define m_spinNbplus2ex		4
#define m_spinNbplus1		5
#define m_spinNbplus1ex		5
#define m_spinNbplus1ex2		5
#define m_spinMoplus5		2
#define m_spinMoplus4		3
#define m_spinMoplus4ex		3
#define m_spinMoplus3		4
#define m_spinMoplus3ex		4
#define m_spinMoplus2		5
#define m_spinMoplus2ex		5
#define m_spinMoplus2ex2		5
#define m_spinMoplus1		6
#define m_spinMoplus1ex		6
#define m_spinMoplus1ex2		6
#define m_spinTcplus6		2
#define m_spinTcplus5		3
#define m_spinTcplus4		4
#define m_spinTcplus3		5
#define m_spinTcplus2		6
#define m_spinRuplus7		2
#define m_spinRuplus6		3
#define m_spinRuplus5		4
#define m_spinRuplus4		5
#define m_spinRuplus3		6
#define m_spinRuplus2		7
#define m_spinRuplus2ex		7
#define m_spinRuplus1		8
#define m_spinRuplus1ex		8
#define m_spinRuplus1ex2		8
#define m_spinRhplus8		2
#define m_spinRhplus7		3
#define m_spinRhplus6		4
#define m_spinRhplus5		5
#define m_spinRhplus4		6
#define m_spinRhplus3		7
#define m_spinRhplus2		8
#define m_spinRhplus2ex		8
#define m_spinRhplus2ex2		8
#define m_spinRhplus1		9
#define m_spinRhplus1ex		9
#define m_spinRhplus1ex2		9
#define m_spinPdplus9		2
#define m_spinPdplus8		3
#define m_spinPdplus7		4
#define m_spinPdplus6		5
#define m_spinPdplus5		6
#define m_spinPdplus4		7
#define m_spinPdplus3		8
#define m_spinPdplus2		9
#define m_spinPdplus2ex		9
#define m_spinPdplus2ex2		9
#define m_spinPdplus1		10
#define m_spinPdplus1ex		10
#define m_spinPdneutrl		11
#define m_spinPdneutrlex		11
#define m_spinAgplus10		2
#define m_spinAgplus9		3
#define m_spinAgplus8		4
#define m_spinAgplus7		5
#define m_spinAgplus6		6
#define m_spinAgplus5		7
#define m_spinAgplus4		8
#define m_spinAgplus3		9
#define m_spinAgplus2		10
#define m_spinAgplus2ex		10
#define m_spinAgplus1		11
#define m_spinAgplus1ex		11
#define m_spinCdplus11		2
#define m_spinCdplus10		3
#define m_spinCdplus9		4
#define m_spinCdplus8		5
#define m_spinCdplus7		6
#define m_spinCdplus6		7
#define m_spinCdplus5		8
#define m_spinCdplus4		9
#define m_spinCdplus3		10
#define m_spinCdplus3ex		10
#define m_spinCdplus2		11
#define m_spinCdplus2ex		11

#define m_spinZnplus1		12
#define m_spinZnplus1ex		12
#define m_spinZnneutrl		13
#define m_spinZnneutrlex		13
#define m_spinCuneutrl		12
#define m_spinCuneutrlex		12
#define m_spinNiplus1		10
#define m_spinNiplus1ex		10
#define m_spinNineutrl		11
#define m_spinNineutrlex		11
#define m_spinCoplus1		9
#define m_spinCoplus1ex		9
#define m_spinCoplus1ex2		9
#define m_spinConeutrl		10
#define m_spinConeutrlex		10
#define m_spinFeplus1		8
#define m_spinFeplus1ex		8
#define m_spinFeplus1ex2		8
#define m_spinFeneutrl		9
#define m_spinFeneutrlex		9
#define m_spinFeneutrlex2		9
#define m_spinFeneutrlex3		9
#define m_spinMnplus1		7
#define m_spinMnplus1ex		7
#define m_spinMnplus1ex2		7
#define m_spinMnplus1ex3		7
#define m_spinMnneutrl		8
#define m_spinMnneutrlex		8
#define m_spinMnneutrlex2		8
#define m_spinMnneutrlex3		8
#define m_spinCrneutrl		7
#define m_spinCrneutrlex		7
#define m_spinCrneutrlex2		7
#define m_spinCrneutrlex3		7
#define m_spinVplus1		5
#define m_spinVplus1ex		5
#define m_spinVplus1ex2		5
#define m_spinVneutrl		6
#define m_spinVneutrlex		6
#define m_spinVneutrlex2		6
#define m_spinTiplus1		4
#define m_spinTiplus1ex		4
#define m_spinTineutrl		5
#define m_spinTineutrlex		5
#define m_spinTineutrlex2		5
#define m_spinScplus1		3
#define m_spinScplus1ex		3
#define m_spinScneutrl		4
#define m_spinScneutrlex		4


#define m_spinCdplus1		12
#define m_spinCdplus1ex		12
#define m_spinCdneutrl		13
#define m_spinCdneutrlex		13
#define m_spinAgneutrl		12
#define m_spinAgneutrlex		12
#define m_spinRhneutrl		10
#define m_spinRhneutrlex		10
#define m_spinRuneutrl		9
#define m_spinRuneutrlex		9
#define m_spinRuneutrlex2		9
#define m_spinTcplus1		7
#define m_spinTcplus1ex		7
#define m_spinTcneutrl		8
#define m_spinTcneutrlex		8
#define m_spinTcneutrlex2		8
#define m_spinTcneutrlex3		8
#define m_spinMoneutrl		7
#define m_spinMoneutrlex		7
#define m_spinMoneutrlex2		7
#define m_spinMoneutrlex3		7
#define m_spinNbneutrl		6
#define m_spinNbneutrlex		6
#define m_spinNbneutrlex2		6
#define m_spinZrplus1		4
#define m_spinZrplus1ex		4
#define m_spinZrneutrl		5
#define m_spinZrneutrlex		5
#define m_spinZrneutrlex2		5
#define m_spinYplus1		3
#define m_spinYplus1ex		3
#define m_spinYneutrl		4
#define m_spinYneutrlex		4



//THERMO WEIGHTS===================
//#define wspinHaff             5*FIT_spinthermo * FIT_spinH * FIT_spinEE
#define wspinOHaff            1.0*FIT_spinthermo * FIT_spinOH*FIT_spinHH
#define wspinH2Oaff           1.0*FIT_spinthermo * FIT_spinOH*FIT_spinHH
#define wspinO_2aff           0.0*FIT_spinthermo * FIT_spinOH

#define wspinHion          1500.0*FIT_spinthermo * FIT_spinH * FIT_spinE * FIT_AB_AH
#define wspinHeaff         1500.0*FIT_spinthermo * FIT_spinH * FIT_spinEE * FIT_AB_AH
//#define wspinHeaff_trp     1000.0*FIT_spinthermo * FIT_spinH * FIT_spinEE * FIT_AA_AH * 0.0
#define wspinH2dis          350.0*FIT_spinthermo * FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_AB_AH
#define wspinH2exdis        300.0*FIT_spinthermo * FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_AA_AH  
#define wspinH2ion          150.0*FIT_spinthermo * FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_AB_AH
#define wspinH2aff	    300.0*FIT_spinthermo * FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_AB_AH
#define wspinH2eaff	    300.0*FIT_spinthermo * FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_AA_AH
#define wspinH3lin   	    100.0*FIT_spinthermo * FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_AA_AH
#define wspinH4squ   	    100.0*FIT_spinthermo * FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_H3H4
#define wspinH4lin   	    100.0*FIT_spinthermo * FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_H3H4

#define wspinHsign	   300.0*FIT_spinthermo * FIT_spinH * FIT_spinEE*FIT_spinHH * FIT_AA_AH 

//#define wspinH2plusdis        0.0*FIT_spinthermo * FIT_spinH * FIT_spinE

#define wspinH2Odis           0.0*FIT_spinthermo * FIT_spinOH*FIT_spinHH

#define wspinO_1eaff         0.0*FIT_spinthermo * FIT_spinO
#define wspinO2ex	      100 *  FIT_spinthermo * FIT_spinO * FIT_spinO2
#define wspinO2ex2            50 *  FIT_spinthermo * FIT_spinO * FIT_spinO2
#define wspinO2eaff           0 * FIT_spinthermo * FIT_spinO * FIT_spinO2  //50		
#define wspinO2ion            0 * FIT_spinthermo * FIT_spinO * FIT_spinO2  //50

#define wspinOeaff            200.0*FIT_spinthermo * FIT_spinO
#define wspinOneutrlion       184.3*FIT_spinthermo * FIT_spinO
#define wspinOplus1ion          138.0*FIT_spinthermo * FIT_spinO //80.0
#define wspinOplus2ion         105.4*FIT_spinthermo * FIT_spinO //80.0
#define wspinOplus3ion         84.3*FIT_spinthermo * FIT_spinO  //50.0
#define wspinOplus4ion         68.4*FIT_spinthermo * FIT_spinO  //50.0
#define wspinOplus5ion         54.3*FIT_spinthermo * FIT_spinO //30.0
#define wspinOplus6ion         43.1*FIT_spinthermo * FIT_spinO //30.0

#define wspinOneutrlexion      171.3* FIT_spinthermo * FIT_spinO * FIT_ex
#define wspinOneutrlex2ion     146.9* FIT_spinthermo * FIT_spinO*FIT_ex     //200.0
#define wspinOplus1ionex       132.8* FIT_spinthermo * FIT_spinO * FIT_ex  //100.0
#define wspinOplus1ex2ion      108.1* FIT_spinthermo * FIT_spinO*FIT_ex   //80.0
#define wspinOplus2ionex      104.0* FIT_spinthermo * FIT_spinO * FIT_ex  //60.0
#define wspinOplus2ionex2     101.4* FIT_spinthermo * FIT_spinO * FIT_ex  //50.0
#define wspinOplus3ionex      82.0* FIT_spinthermo * FIT_spinO * FIT_ex  //10.0
#define wspinOplus4ionex      66.8* FIT_spinthermo * FIT_spinO * FIT_ex  //10.0
#define wspinOsign            2000.0* FIT_spinthermo * FIT_spinO * FIT_ex  //2000.0



#define wspinCplus3ion            30.0*FIT_spinthermo * FIT_spinC
#define wspinCplus2ion            50.0*FIT_spinthermo * FIT_spinC
#define wspinCplus1ion            100.0*FIT_spinthermo * FIT_spinC
#define wspinCneutrlion          300.0*FIT_spinthermo * FIT_spinC
#define wspinC_1ion              300.0*FIT_spinthermo * FIT_spinC

#define wspinCplus2exion             10.0*FIT_spinthermo * FIT_spinC*FIT_ex
#define wspinCplus1exion              50.0*FIT_spinthermo * FIT_spinC*FIT_ex
#define wspinCneutrlexion           150.0*FIT_spinthermo * FIT_spinC*FIT_ex
#define wspinCneutrlex2ion          150.0*FIT_spinthermo * FIT_spinC*FIT_ex
#define wspinCsign                 0.0*FIT_spinthermo * FIT_spinC*FIT_ex
#define wspinC2ex                0.0*FIT_spinthermo * FIT_spinC



#define wspinNplus4ion            30.0*FIT_spinthermo * FIT_spinN
#define wspinNplus3ion            50.0*FIT_spinthermo * FIT_spinN
#define wspinNplus2ion            80.0*FIT_spinthermo * FIT_spinN
#define wspinNplus1ion            300.0*FIT_spinthermo * FIT_spinN
#define wspinNneutrlion          300.0*FIT_spinthermo * FIT_spinN

#define wspinN_1ion                0.0*FIT_spinthermo * FIT_spinN

#define wspinNplus3exion              10.0*FIT_spinthermo * FIT_spinN*FIT_ex
#define wspinNplus2exion              30.0*FIT_spinthermo * FIT_spinN*FIT_ex
#define wspinNplus1exion               50.0*FIT_spinthermo * FIT_spinN*FIT_ex
#define wspinNplus1ex2ion              80.0*FIT_spinthermo * FIT_spinN*FIT_ex
#define wspinNneutrlexion            200.0*FIT_spinthermo * FIT_spinN*FIT_ex
#define wspinNneutrlex2ion             0.0*FIT_spinthermo * FIT_spinN*FIT_ex
#define wspinNsign		    0.0* FIT_spinthermo * FIT_spinN * FIT_ex
#define wspinN2ex                0.0*FIT_spinthermo * FIT_spinN //100.0




#define wspinFplus6ion            30.0*FIT_spinthermo * FIT_spinF
#define wspinFplus5ion            30.0*FIT_spinthermo * FIT_spinF
#define wspinFplus4ion            50.0*FIT_spinthermo * FIT_spinF
#define wspinFplus3ion            50.0*FIT_spinthermo * FIT_spinF
#define wspinFplus2ion            80.0*FIT_spinthermo * FIT_spinF
#define wspinFplus1ion             80.0*FIT_spinthermo * FIT_spinF
#define wspinFneutrlion          300.0*FIT_spinthermo * FIT_spinF
#define wspinF_1ion              300.0*FIT_spinthermo * FIT_spinF

#define wspinFplus5exion             10.0*FIT_spinthermo * FIT_spinF*FIT_ex
#define wspinFplus4exion             10.0*FIT_spinthermo * FIT_spinF*FIT_ex
#define wspinFplus3exion             30.0*FIT_spinthermo * FIT_spinF*FIT_ex
#define wspinFplus3ex2ion            30.0*FIT_spinthermo * FIT_spinF*FIT_ex
#define wspinFplus2exion             50.0*FIT_spinthermo * FIT_spinF*FIT_ex
#define wspinFplus2ex2ion            50.0*FIT_spinthermo * FIT_spinF*FIT_ex
#define wspinFplus1exion             100.0*FIT_spinthermo * FIT_spinF*FIT_ex
#define wspinFplus1ex2ion            100.0*FIT_spinthermo * FIT_spinF*FIT_ex
#define wspinFneutrlexion           200.0*FIT_spinthermo * FIT_spinF*FIT_ex
#define wspinFsign		   2000.0*FIT_spinthermo * FIT_spinF * FIT_ex	
#define wspinF2ex                100.0*FIT_spinthermo * FIT_spinF


#define wspinSiplus3ion           30.0*FIT_spinthermo * FIT_spinSi
#define wspinSiplus2ion           50.0*FIT_spinthermo * FIT_spinSi
#define wspinSiplus1ion            80.0*FIT_spinthermo * FIT_spinSi
#define wspinSineutrlion         300.0*FIT_spinthermo * FIT_spinSi
#define wspinSi_1ion             300.0*FIT_spinthermo * FIT_spinSi

#define wspinSiplus2exion             10.0*FIT_spinthermo * FIT_spinSi*FIT_ex
#define wspinSiplus1exion              50.0*FIT_spinthermo * FIT_spinSi*FIT_ex
#define wspinSineutrlexion            80.0*FIT_spinthermo * FIT_spinSi*FIT_ex
#define wspinSineutrlex2ion          200.0*FIT_spinthermo * FIT_spinSi*FIT_ex
#define wspinSisign		    2000.0* FIT_spinthermo * FIT_spinSi* FIT_ex
#define wspinSi2ex                0.0*FIT_spinthermo * FIT_spinSi


#define wspinPplus4ion            30.0*FIT_spinthermo * FIT_spinP
#define wspinPplus3ion            30.0*FIT_spinthermo * FIT_spinP
#define wspinPplus2ion            50.0*FIT_spinthermo * FIT_spinP
#define wspinPplus1ion             80.0*FIT_spinthermo * FIT_spinP
#define wspinPneutrlion          300.0*FIT_spinthermo * FIT_spinP
#define wspinP_1ion              300.0*FIT_spinthermo * FIT_spinP

#define wspinPplus3exion             10.0*FIT_spinthermo * FIT_spinP*FIT_ex
#define wspinPplus2exion             30.0*FIT_spinthermo * FIT_spinP*FIT_ex
#define wspinPplus1exion              50.0*FIT_spinthermo * FIT_spinP*FIT_ex
#define wspinPplus1ex2ion             80.0*FIT_spinthermo * FIT_spinP*FIT_ex
#define wspinPneutrlexion           200.0*FIT_spinthermo * FIT_spinP*FIT_ex
#define wspinPsign		   2000.0*FIT_spinthermo * FIT_spinP * FIT_ex
#define wspinP2ex                0.0*FIT_spinthermo * FIT_spinP



#define wspinSplus5ion            10.0*FIT_spinthermo * FIT_spinS
#define wspinSplus4ion            10.0*FIT_spinthermo * FIT_spinS
#define wspinSplus3ion            30.0*FIT_spinthermo * FIT_spinS
#define wspinSplus2ion            50.0*FIT_spinthermo * FIT_spinS
#define wspinSplus1ion             80.0*FIT_spinthermo * FIT_spinS
#define wspinSneutrlion          300.0*FIT_spinthermo * FIT_spinS
#define wspinS_1ion              300.0*FIT_spinthermo * FIT_spinS

#define wspinSplus4exion              10.0*FIT_spinthermo * FIT_spinS*FIT_ex
#define wspinSplus3exion              10.0*FIT_spinthermo * FIT_spinS*FIT_ex
#define wspinSplus2exion              30.0*FIT_spinthermo * FIT_spinS*FIT_ex
#define wspinSplus2ex2ion             50.0*FIT_spinthermo * FIT_spinS*FIT_ex
#define wspinSplus1exion               80.0*FIT_spinthermo * FIT_spinS*FIT_ex
#define wspinSneutrlexion            200.0*FIT_spinthermo * FIT_spinS*FIT_ex
#define wspinSneutrlex2ion           200.0*FIT_spinthermo * FIT_spinS*FIT_ex
#define wspinSsign		    2000.0*FIT_spinthermo * FIT_spinS * FIT_ex
#define wspinS2ex                100.0*FIT_spinthermo * FIT_spinS


#define wspinB_1ion             300.0*FIT_spinthermo * FIT_spinBo
#define wspinBneutrlexion       200.0*FIT_spinthermo * FIT_spinBo*FIT_ex
#define wspinBneutrlion         300.0*FIT_spinthermo * FIT_spinBo
#define wspinBplus1exion          80.0*FIT_spinthermo * FIT_spinBo*FIT_ex
#define wspinBplus1ion            50.0*FIT_spinthermo * FIT_spinBo
#define wspinBplus2ion           10.0*FIT_spinthermo * FIT_spinBo
#define wspinBsign	       2000.0*FIT_spinthermo * FIT_spinBo*FIT_ex
#define wspinB2ex                0.0*FIT_spinthermo * FIT_spinBo


#define wspinCl_1ion             300.0*FIT_spinthermo * FIT_spinCl
#define wspinClneutrlion         300.0*FIT_spinthermo * FIT_spinCl
#define wspinClplus1ion            80.0*FIT_spinthermo * FIT_spinCl
#define wspinClplus2ion           80.0*FIT_spinthermo * FIT_spinCl
#define wspinClplus3ion           50.0*FIT_spinthermo * FIT_spinCl
#define wspinClplus4ion           50.0*FIT_spinthermo * FIT_spinCl
#define wspinClplus5ion           30.0*FIT_spinthermo * FIT_spinCl
#define wspinClplus6ion           30.0*FIT_spinthermo * FIT_spinCl


#define wspinClneutrlexion       200.0*FIT_spinthermo * FIT_spinCl*FIT_ex
#define wspinClplus1ex2ion        200.0*FIT_spinthermo * FIT_spinCl*FIT_ex
#define wspinClplus1exion          80.0*FIT_spinthermo * FIT_spinCl*FIT_ex
#define wspinClplus2exion         80.0*FIT_spinthermo * FIT_spinCl*FIT_ex
#define wspinClplus3ex2ion        50.0*FIT_spinthermo * FIT_spinCl*FIT_ex
#define wspinClplus3exion         50.0*FIT_spinthermo * FIT_spinCl*FIT_ex
#define wspinClplus4exion         10.0*FIT_spinthermo * FIT_spinCl*FIT_ex
#define wspinClplus5exion         10.0*FIT_spinthermo * FIT_spinCl*FIT_ex
#define wspinClsign	        2000.0*FIT_spinthermo * FIT_spinCl*FIT_ex
#define wspinCl2ex                100.0*FIT_spinthermo * FIT_spinCl

#define wspinScplus2ion		10.0*FIT_spinthermo * FIT_spinSc
#define wspinScplus1ion		20.0*FIT_spinthermo * FIT_spinSc
#define wspinScplus1exion	10.0*FIT_spinthermo * FIT_spinSc * FIT_ex
#define wspinScneutrlion	30.0*FIT_spinthermo * FIT_spinSc
#define wspinScneutrlexion	20.0*FIT_spinthermo * FIT_spinSc * FIT_ex
#define wspinScsign		2000.0*FIT_spinthermo * FIT_spinSc*FIT_ex
#define wspinTiplus3ion		10.0*FIT_spinthermo * FIT_spinTi
#define wspinTiplus2ion		20.0*FIT_spinthermo * FIT_spinTi
#define wspinTiplus2exion	10.0*FIT_spinthermo * FIT_spinTi * FIT_ex
#define wspinTiplus1ion		30.0*FIT_spinthermo * FIT_spinTi
#define wspinTiplus1exion	20.0*FIT_spinthermo * FIT_spinTi * FIT_ex
#define wspinTineutrlion	40.0*FIT_spinthermo * FIT_spinTi
#define wspinTineutrlexion	30.0*FIT_spinthermo * FIT_spinTi * FIT_ex
#define wspinTineutrlex2ion	20.0*FIT_spinthermo * FIT_spinTi * FIT_ex
#define wspinTisign		2000.0*FIT_spinthermo * FIT_spinTi*FIT_ex
#define wspinVplus4ion		10.0*FIT_spinthermo * FIT_spinV
#define wspinVplus3ion		20.0*FIT_spinthermo * FIT_spinV
#define wspinVplus3exion	10.0*FIT_spinthermo * FIT_spinV * FIT_ex
#define wspinVplus2ion		30.0*FIT_spinthermo * FIT_spinV
#define wspinVplus2exion	20.0*FIT_spinthermo * FIT_spinV * FIT_ex
#define wspinVplus1ion		40.0*FIT_spinthermo * FIT_spinV
#define wspinVplus1exion	30.0*FIT_spinthermo * FIT_spinV * FIT_ex
#define wspinVplus1ex2ion	20.0*FIT_spinthermo * FIT_spinV * FIT_ex
#define wspinVneutrlion		50.0*FIT_spinthermo * FIT_spinV
#define wspinVneutrlexion	40.0*FIT_spinthermo * FIT_spinV * FIT_ex
#define wspinVneutrlex2ion	30.0*FIT_spinthermo * FIT_spinV * FIT_ex
#define wspinVsign		2000.0*FIT_spinthermo * FIT_spinV*FIT_ex
#define wspinCrplus5ion		10.0*FIT_spinthermo * FIT_spinCr
#define wspinCrplus4ion		20.0*FIT_spinthermo * FIT_spinCr
#define wspinCrplus4exion	10.0*FIT_spinthermo * FIT_spinCr * FIT_ex
#define wspinCrplus3ion		30.0*FIT_spinthermo * FIT_spinCr
#define wspinCrplus3exion	20.0*FIT_spinthermo * FIT_spinCr * FIT_ex
#define wspinCrplus2ion		40.0*FIT_spinthermo * FIT_spinCr
#define wspinCrplus2exion	30.0*FIT_spinthermo * FIT_spinCr * FIT_ex
#define wspinCrplus2ex2ion	20.0*FIT_spinthermo * FIT_spinCr * FIT_ex
#define wspinCrplus1ion		50.0*FIT_spinthermo * FIT_spinCr
#define wspinCrplus1exion	40.0*FIT_spinthermo * FIT_spinCr * FIT_ex
#define wspinCrplus1ex2ion	30.0*FIT_spinthermo * FIT_spinCr * FIT_ex
#define wspinCrneutrlion	60.0*FIT_spinthermo * FIT_spinCr
#define wspinCrneutrlexion	50.0*FIT_spinthermo * FIT_spinCr * FIT_ex
#define wspinCrneutrlex2ion	40.0*FIT_spinthermo * FIT_spinCr * FIT_ex
#define wspinCrneutrlex3ion	40.0*FIT_spinthermo * FIT_spinCr * FIT_ex
#define wspinCrsign		2000.0*FIT_spinthermo * FIT_spinCr*FIT_ex
#define wspinMnplus6ion		10.0*FIT_spinthermo * FIT_spinMn
#define wspinMnplus5ion		20.0*FIT_spinthermo * FIT_spinMn
#define wspinMnplus5exion	10.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnplus4ion		30.0*FIT_spinthermo * FIT_spinMn
#define wspinMnplus4exion	20.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnplus3ion		40.0*FIT_spinthermo * FIT_spinMn
#define wspinMnplus3exion	30.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnplus2ion		50.0*FIT_spinthermo * FIT_spinMn
#define wspinMnplus2exion	40.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnplus2ex2ion	30.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnplus1ion		60.0*FIT_spinthermo * FIT_spinMn
#define wspinMnplus1exion	50.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnplus1ex2ion	40.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnplus1ex3ion	40.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnneutrlion	70.0*FIT_spinthermo * FIT_spinMn
#define wspinMnneutrlexion	60.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnneutrlex2ion	50.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnneutrlex3ion	50.0*FIT_spinthermo * FIT_spinMn * FIT_ex
#define wspinMnsign		2000.0*FIT_spinthermo * FIT_spinMn*FIT_ex
#define wspinFeplus8ion		35.7*FIT_spinthermo * FIT_spinFe	//10
#define wspinFeplus7ion		44.9*FIT_spinthermo * FIT_spinFe	//10
#define wspinFeplus6ion		55.6*FIT_spinthermo * FIT_spinFe	//20
#define wspinFeplus6exion	55.3*FIT_spinthermo * FIT_spinFe * FIT_ex	//10
#define wspinFeplus5ion		68.0*FIT_spinthermo * FIT_spinFe	//30
#define wspinFeplus5exion	67.6*FIT_spinthermo * FIT_spinFe * FIT_ex	//20
#define wspinFeplus4ion		83.1*FIT_spinthermo * FIT_spinFe	//40
#define wspinFeplus4exion	82.3*FIT_spinthermo * FIT_spinFe * FIT_ex	//30
#define wspinFeplus4ex2ion	81.9*FIT_spinthermo * FIT_spinFe * FIT_ex	//20
#define wspinFeplus3ion		102.9*FIT_spinthermo * FIT_spinFe	//50
#define wspinFeplus3exion	100.9*FIT_spinthermo * FIT_spinFe * FIT_ex	//40
#define wspinFeplus3ex2ion	100.0*FIT_spinthermo * FIT_spinFe * FIT_ex	//30
#define wspinFeplus2ion		125.6*FIT_spinthermo * FIT_spinFe	//60
#define wspinFeplus2exion	123.1*FIT_spinthermo * FIT_spinFe * FIT_ex	
#define wspinFeplus2ex2ion	121.7*FIT_spinthermo * FIT_spinFe * FIT_ex	//40
#define wspinFeplus1ion		154.0*FIT_spinthermo * FIT_spinFe	//70
#define wspinFeplus1exion	153.4*FIT_spinthermo * FIT_spinFe * FIT_ex	//60
#define wspinFeplus1ex2ion	148.8*FIT_spinthermo * FIT_spinFe * FIT_ex	//50
#define wspinFeneutrlion	200.0*FIT_spinthermo * FIT_spinFe	//80
#define wspinFeneutrlexion	184.2*FIT_spinthermo * FIT_spinFe * FIT_ex
#define wspinFeneutrlex2ion	177.5*FIT_spinthermo * FIT_spinFe * FIT_ex
#define wspinFeneutrlex3ion	171.5*FIT_spinthermo * FIT_spinFe * FIT_ex
#define wspinFesign		0.0*FIT_spinthermo * FIT_spinFe*FIT_ex
#define wspinCoplus8ion		10.0*FIT_spinthermo * FIT_spinCo
#define wspinCoplus7ion		20.0*FIT_spinthermo * FIT_spinCo
#define wspinCoplus7exion	10.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus6ion		30.0*FIT_spinthermo * FIT_spinCo
#define wspinCoplus6exion	20.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus5ion		40.0*FIT_spinthermo * FIT_spinCo
#define wspinCoplus5exion	30.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus5ex2ion	20.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus4ion		50.0*FIT_spinthermo * FIT_spinCo
#define wspinCoplus4exion	40.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus4ex2ion	30.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus3ion		60.0*FIT_spinthermo * FIT_spinCo
#define wspinCoplus3exion	50.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus3ex2ion	40.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus2ion		70.0*FIT_spinthermo * FIT_spinCo
#define wspinCoplus2exion	60.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus2ex2ion	50.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus1ion		80.0*FIT_spinthermo * FIT_spinCo
#define wspinCoplus1exion	70.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCoplus1ex2ion	60.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinConeutrlion	90.0*FIT_spinthermo * FIT_spinCo
#define wspinConeutrlexion	80.0*FIT_spinthermo * FIT_spinCo * FIT_ex
#define wspinCosign		2000.0*FIT_spinthermo * FIT_spinCo*FIT_ex
#define wspinNiplus9ion		10.0*FIT_spinthermo * FIT_spinNi
#define wspinNiplus8ion		20.0*FIT_spinthermo * FIT_spinNi
#define wspinNiplus8exion	10.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus7ion		30.0*FIT_spinthermo * FIT_spinNi
#define wspinNiplus7exion	20.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus6ion		40.0*FIT_spinthermo * FIT_spinNi
#define wspinNiplus6exion	30.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus5ion		50.0*FIT_spinthermo * FIT_spinNi
#define wspinNiplus5exion	40.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus5ex2ion	30.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus4ion		60.0*FIT_spinthermo * FIT_spinNi
#define wspinNiplus4exion	50.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus4ex2ion	40.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus3ion		70.0*FIT_spinthermo * FIT_spinNi
#define wspinNiplus3exion	60.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus3ex2ion	50.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus2ion		80.0*FIT_spinthermo * FIT_spinNi
#define wspinNiplus2exion	70.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus2ex2ion	60.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNiplus1ion		90.0*FIT_spinthermo * FIT_spinNi
#define wspinNiplus1exion	80.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNineutrlion	100.0*FIT_spinthermo * FIT_spinNi
#define wspinNineutrlexion	90.0*FIT_spinthermo * FIT_spinNi * FIT_ex
#define wspinNisign		2000.0*FIT_spinthermo * FIT_spinNi*FIT_ex
#define wspinCuplus10ion	10.0*FIT_spinthermo * FIT_spinCu
#define wspinCuplus9ion		20.0*FIT_spinthermo * FIT_spinCu
#define wspinCuplus9exion	10.0*FIT_spinthermo * FIT_spinCu * FIT_ex
#define wspinCuplus8ion		30.0*FIT_spinthermo * FIT_spinCu
#define wspinCuplus7ion		40.0*FIT_spinthermo * FIT_spinCu
#define wspinCuplus6ion		50.0*FIT_spinthermo * FIT_spinCu
#define wspinCuplus5ion		60.0*FIT_spinthermo * FIT_spinCu
#define wspinCuplus5exion	50.0*FIT_spinthermo * FIT_spinCu * FIT_ex
#define wspinCuplus5ex2ion	40.0*FIT_spinthermo * FIT_spinCu * FIT_ex
#define wspinCuplus4ion		70.0*FIT_spinthermo * FIT_spinCu
#define wspinCuplus4exion	60.0*FIT_spinthermo * FIT_spinCu * FIT_ex
#define wspinCuplus4ex2ion	50.0*FIT_spinthermo * FIT_spinCu * FIT_ex
#define wspinCuplus3ion		80.0*FIT_spinthermo * FIT_spinCu
#define wspinCuplus3exion	70.0*FIT_spinthermo * FIT_spinCu * FIT_ex
#define wspinCuplus3ex2ion	60.0*FIT_spinthermo * FIT_spinCu * FIT_ex
#define wspinCuplus2ion		90.0*FIT_spinthermo * FIT_spinCu
#define wspinCuplus2exion	80.0*FIT_spinthermo * FIT_spinCu * FIT_ex
#define wspinCuplus1ion		100.0*FIT_spinthermo * FIT_spinCu
#define wspinCuplus1exion	90.0*FIT_spinthermo * FIT_spinCu * FIT_ex
#define wspinCuneutrlion	110.0*FIT_spinthermo * FIT_spinCu
#define wspinCuneutrlexion	100.0*FIT_spinthermo * FIT_spinCu * FIT_ex
#define wspinCusign		2000.0*FIT_spinthermo * FIT_spinCu*FIT_ex
#define wspinZnplus12ion	4.1*FIT_spinthermo * FIT_spinZn * FIT_ion            //10
#define wspinZnplus11ion	10.2*FIT_spinthermo * FIT_spinZn * FIT_ion           //10
#define wspinZnplus10ion	16.9*FIT_spinthermo * FIT_spinZn * FIT_ion            //20
#define wspinZnplus10exion	16.8*FIT_spinthermo * FIT_spinZn * FIT_ex   //10
#define wspinZnplus9ion		24.3*FIT_spinthermo * FIT_spinZn * FIT_ion            //30
#define wspinZnplus8ion		32.5*FIT_spinthermo * FIT_spinZn * FIT_ion            //40
#define wspinZnplus7ion		42.0*FIT_spinthermo * FIT_spinZn * FIT_ion            //50
#define wspinZnplus6ion		52.3*FIT_spinthermo * FIT_spinZn * FIT_ion            //60
#define wspinZnplus6exion	51.9*FIT_spinthermo * FIT_spinZn * FIT_ex   //50
#define wspinZnplus6ex2ion	51.7*FIT_spinthermo * FIT_spinZn * FIT_ex   //40
#define wspinZnplus5ion		64.4*FIT_spinthermo * FIT_spinZn * FIT_ion            //70
#define wspinZnplus5exion	64.0*FIT_spinthermo * FIT_spinZn * FIT_ex   //60
#define wspinZnplus5ex2ion	58.6*FIT_spinthermo * FIT_spinZn * FIT_ex   //50
#define wspinZnplus4ion		78.9*FIT_spinthermo * FIT_spinZn * FIT_ion            //80
#define wspinZnplus4exion	78.4*FIT_spinthermo * FIT_spinZn * FIT_ex   //70
#define wspinZnplus4ex2ion	73.8*FIT_spinthermo * FIT_spinZn * FIT_ex   //60
#define wspinZnplus3ion		97.2*FIT_spinthermo * FIT_spinZn * FIT_ion             //90
#define wspinZnplus3exion	91.1*FIT_spinthermo * FIT_spinZn * FIT_ex    //80
#define wspinZnplus2ion		122.2*FIT_spinthermo * FIT_spinZn * FIT_ion           //100
#define wspinZnplus2exion	113.9*FIT_spinthermo * FIT_spinZn * FIT_ex   //90
#define wspinZnplus1ion		149.8*FIT_spinthermo * FIT_spinZn * FIT_ion           //110
#define wspinZnplus1exion	127.8*FIT_spinthermo * FIT_spinZn * FIT_ex  //100
#define wspinZnneutrlion	200.0*FIT_spinthermo * FIT_spinZn * FIT_ion            //200
#define wspinZnneutrlexion	168.5*FIT_spinthermo * FIT_spinZn * FIT_ex  //110
#define wspinZnsign		2000.0*FIT_spinthermo * FIT_spinZn*FIT_ex  //2000.0
#define wspinYplus2ion		10.0*FIT_spinthermo * FIT_spinY
#define wspinYplus1ion		20.0*FIT_spinthermo * FIT_spinY
#define wspinYplus1exion	10.0*FIT_spinthermo * FIT_spinY * FIT_ex
#define wspinYneutrlion	        30.0*FIT_spinthermo * FIT_spinY
#define wspinYneutrlexion	20.0*FIT_spinthermo * FIT_spinY * FIT_ex
#define wspinYsign		2000.0*FIT_spinthermo * FIT_spinY*FIT_ex
#define wspinZrplus3ion		10.0*FIT_spinthermo * FIT_spinZr
#define wspinZrplus2ion		20.0*FIT_spinthermo * FIT_spinZr
#define wspinZrplus2exion	10.0*FIT_spinthermo * FIT_spinZr * FIT_ex
#define wspinZrplus1ion		30.0*FIT_spinthermo * FIT_spinZr
#define wspinZrplus1exion	20.0*FIT_spinthermo * FIT_spinZr * FIT_ex
#define wspinZrneutrlion	40.0*FIT_spinthermo * FIT_spinZr
#define wspinZrneutrlexion	30.0*FIT_spinthermo * FIT_spinZr * FIT_ex
#define wspinZrneutrlex2ion	20.0*FIT_spinthermo * FIT_spinZr * FIT_ex
#define wspinZrsign		2000.0*FIT_spinthermo * FIT_spinZr*FIT_ex
#define wspinNbplus4ion		10.0*FIT_spinthermo * FIT_spinNb
#define wspinNbplus3ion		20.0*FIT_spinthermo * FIT_spinNb
#define wspinNbplus3exion	10.0*FIT_spinthermo * FIT_spinNb * FIT_ex
#define wspinNbplus2ion		30.0*FIT_spinthermo * FIT_spinNb
#define wspinNbplus2exion	20.0*FIT_spinthermo * FIT_spinNb * FIT_ex
#define wspinNbplus1ion		40.0*FIT_spinthermo * FIT_spinNb
#define wspinNbplus1exion	30.0*FIT_spinthermo * FIT_spinNb * FIT_ex
#define wspinNbplus1ex2ion	20.0*FIT_spinthermo * FIT_spinNb * FIT_ex
#define wspinNbneutrlion	50.0*FIT_spinthermo * FIT_spinNb
#define wspinNbneutrlexion	40.0*FIT_spinthermo * FIT_spinNb * FIT_ex
#define wspinNbneutrlex2ion	30.0*FIT_spinthermo * FIT_spinNb * FIT_ex
#define wspinNbsign		2000.0*FIT_spinthermo * FIT_spinNb*FIT_ex
#define wspinMoplus5ion		10.0*FIT_spinthermo * FIT_spinMo
#define wspinMoplus4ion		20.0*FIT_spinthermo * FIT_spinMo
#define wspinMoplus4exion	10.0*FIT_spinthermo * FIT_spinMo * FIT_ex
#define wspinMoplus3ion		30.0*FIT_spinthermo * FIT_spinMo
#define wspinMoplus3exion	20.0*FIT_spinthermo * FIT_spinMo * FIT_ex
#define wspinMoplus2ion		40.0*FIT_spinthermo * FIT_spinMo
#define wspinMoplus2exion	30.0*FIT_spinthermo * FIT_spinMo * FIT_ex
#define wspinMoplus2ex2ion	20.0*FIT_spinthermo * FIT_spinMo * FIT_ex
#define wspinMoplus1ion		50.0*FIT_spinthermo * FIT_spinMo
#define wspinMoplus1exion	40.0*FIT_spinthermo * FIT_spinMo * FIT_ex
#define wspinMoplus1ex2ion	30.0*FIT_spinthermo * FIT_spinMo * FIT_ex
#define wspinMoneutrlion	60.0*FIT_spinthermo * FIT_spinMo
#define wspinMoneutrlexion	50.0*FIT_spinthermo * FIT_spinMo * FIT_ex
#define wspinMoneutrlex2ion	40.0*FIT_spinthermo * FIT_spinMo * FIT_ex
#define wspinMoneutrlex3ion	40.0*FIT_spinthermo * FIT_spinMo * FIT_ex
#define wspinMosign		2000.0*FIT_spinthermo * FIT_spinMo*FIT_ex
#define wspinTcplus6ion		10.0*FIT_spinthermo * FIT_spinTc
#define wspinTcplus5ion		20.0*FIT_spinthermo * FIT_spinTc
#define wspinTcplus4ion		30.0*FIT_spinthermo * FIT_spinTc
#define wspinTcplus3ion		40.0*FIT_spinthermo * FIT_spinTc
#define wspinTcplus2ion		50.0*FIT_spinthermo * FIT_spinTc
#define wspinTcplus1ion		60.0*FIT_spinthermo * FIT_spinTc
#define wspinTcplus1exion	50.0*FIT_spinthermo * FIT_spinTc * FIT_ex
#define wspinTcneutrlion	70.0*FIT_spinthermo * FIT_spinTc
#define wspinTcneutrlexion	60.0*FIT_spinthermo * FIT_spinTc * FIT_ex
#define wspinTcneutrlex2ion	50.0*FIT_spinthermo * FIT_spinTc * FIT_ex
#define wspinTcneutrlex3ion	50.0*FIT_spinthermo * FIT_spinTc * FIT_ex
#define wspinTcsign		2000.0*FIT_spinthermo * FIT_spinTc*FIT_ex
#define wspinRuplus7ion		10.0*FIT_spinthermo * FIT_spinRu
#define wspinRuplus6ion		20.0*FIT_spinthermo * FIT_spinRu
#define wspinRuplus5ion		30.0*FIT_spinthermo * FIT_spinRu
#define wspinRuplus4ion		40.0*FIT_spinthermo * FIT_spinRu
#define wspinRuplus3ion		50.0*FIT_spinthermo * FIT_spinRu
#define wspinRuplus2ion		60.0*FIT_spinthermo * FIT_spinRu
#define wspinRuplus2exion	50.0*FIT_spinthermo * FIT_spinRu * FIT_ex
#define wspinRuplus1ion		70.0*FIT_spinthermo * FIT_spinRu
#define wspinRuplus1exion	60.0*FIT_spinthermo * FIT_spinRu * FIT_ex
#define wspinRuplus1ex2ion	50.0*FIT_spinthermo * FIT_spinRu * FIT_ex
#define wspinRuneutrlion	80.0*FIT_spinthermo * FIT_spinRu
#define wspinRuneutrlexion	70.0*FIT_spinthermo * FIT_spinRu * FIT_ex
#define wspinRuneutrlex2ion	60.0*FIT_spinthermo * FIT_spinRu * FIT_ex
#define wspinRusign		2000.0*FIT_spinthermo * FIT_spinRu*FIT_ex
#define wspinRhplus8ion		10.0*FIT_spinthermo * FIT_spinRh
#define wspinRhplus7ion		20.0*FIT_spinthermo * FIT_spinRh
#define wspinRhplus6ion		30.0*FIT_spinthermo * FIT_spinRh
#define wspinRhplus5ion		40.0*FIT_spinthermo * FIT_spinRh
#define wspinRhplus4ion		50.0*FIT_spinthermo * FIT_spinRh
#define wspinRhplus3ion		60.0*FIT_spinthermo * FIT_spinRh
#define wspinRhplus2ion		70.0*FIT_spinthermo * FIT_spinRh
#define wspinRhplus2exion	60.0*FIT_spinthermo * FIT_spinRh * FIT_ex
#define wspinRhplus2ex2ion	50.0*FIT_spinthermo * FIT_spinRh * FIT_ex
#define wspinRhplus1ion		80.0*FIT_spinthermo * FIT_spinRh
#define wspinRhplus1exion	70.0*FIT_spinthermo * FIT_spinRh * FIT_ex
#define wspinRhplus1ex2ion	60.0*FIT_spinthermo * FIT_spinRh * FIT_ex
#define wspinRhneutrlion	90.0*FIT_spinthermo * FIT_spinRh
#define wspinRhneutrlexion	80.0*FIT_spinthermo * FIT_spinRh * FIT_ex
#define wspinRhsign		2000.0*FIT_spinthermo * FIT_spinRh*FIT_ex
#define wspinPdplus9ion		10.0*FIT_spinthermo * FIT_spinPd
#define wspinPdplus8ion		20.0*FIT_spinthermo * FIT_spinPd
#define wspinPdplus7ion		30.0*FIT_spinthermo * FIT_spinPd
#define wspinPdplus6ion		40.0*FIT_spinthermo * FIT_spinPd
#define wspinPdplus5ion		50.0*FIT_spinthermo * FIT_spinPd
#define wspinPdplus4ion		60.0*FIT_spinthermo * FIT_spinPd
#define wspinPdplus3ion		70.0*FIT_spinthermo * FIT_spinPd
#define wspinPdplus2ion		80.0*FIT_spinthermo * FIT_spinPd
#define wspinPdplus2exion	70.0*FIT_spinthermo * FIT_spinPd * FIT_ex
#define wspinPdplus2ex2ion	60.0*FIT_spinthermo * FIT_spinPd * FIT_ex
#define wspinPdplus1ion		90.0*FIT_spinthermo * FIT_spinPd
#define wspinPdplus1exion	80.0*FIT_spinthermo * FIT_spinPd * FIT_ex
#define wspinPdneutrlion	100.0*FIT_spinthermo * FIT_spinPd
#define wspinPdneutrlexion	90.0*FIT_spinthermo * FIT_spinPd * FIT_ex
#define wspinPdsign		2000.0*FIT_spinthermo * FIT_spinPd*FIT_ex
#define wspinAgplus10ion	10.0*FIT_spinthermo * FIT_spinAg
#define wspinAgplus9ion		20.0*FIT_spinthermo * FIT_spinAg
#define wspinAgplus8ion		30.0*FIT_spinthermo * FIT_spinAg
#define wspinAgplus7ion		40.0*FIT_spinthermo * FIT_spinAg
#define wspinAgplus6ion		50.0*FIT_spinthermo * FIT_spinAg
#define wspinAgplus5ion		60.0*FIT_spinthermo * FIT_spinAg
#define wspinAgplus4ion		70.0*FIT_spinthermo * FIT_spinAg
#define wspinAgplus3ion		80.0*FIT_spinthermo * FIT_spinAg
#define wspinAgplus2ion		90.0*FIT_spinthermo * FIT_spinAg
#define wspinAgplus2exion	80.0*FIT_spinthermo * FIT_spinAg * FIT_ex
#define wspinAgplus1ion		100.0*FIT_spinthermo * FIT_spinAg
#define wspinAgplus1exion	90.0*FIT_spinthermo * FIT_spinAg * FIT_ex
#define wspinAgneutrlion	110.0*FIT_spinthermo * FIT_spinAg
#define wspinAgneutrlexion	100.0*FIT_spinthermo * FIT_spinAg * FIT_ex
#define wspinAgsign		2000.0*FIT_spinthermo * FIT_spinAg*FIT_ex
#define wspinCdplus11ion	10.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus10ion	20.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus9ion		30.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus8ion		40.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus7ion		50.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus6ion		60.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus5ion		70.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus4ion		80.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus3ion		90.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus3exion	80.0*FIT_spinthermo * FIT_spinCd * FIT_ex
#define wspinCdplus2ion		100.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus2exion	90.0*FIT_spinthermo * FIT_spinCd * FIT_ex
#define wspinCdplus1ion		110.0*FIT_spinthermo * FIT_spinCd
#define wspinCdplus1exion	100.0*FIT_spinthermo * FIT_spinCd * FIT_ex
#define wspinCdneutrlion	120.0*FIT_spinthermo * FIT_spinCd
#define wspinCdneutrlexion	110.0*FIT_spinthermo * FIT_spinCd * FIT_ex
#define wspinCdsign		2000.0*FIT_spinthermo * FIT_spinCd*FIT_ex



#define wspinAl_1ion             300.0*FIT_spinthermo * FIT_spinAl
#define wspinAlneutrlexion       150.0*FIT_spinthermo * FIT_spinAl*FIT_ex
#define wspinAlneutrlion         300.0*FIT_spinthermo * FIT_spinAl
#define wspinAlplus1exion          80.0*FIT_spinthermo * FIT_spinAl*FIT_ex
#define wspinAlplus1ion           150.0*FIT_spinthermo * FIT_spinAl
#define wspinAlplus2ion           50.0*FIT_spinthermo * FIT_spinAl

#define wspinAl2ex		  0.0*FIT_spinthermo * FIT_spinAl
#define wspinAlsign 	        2000.0*FIT_spinthermo * FIT_spinAl*FIT_ex


#define wspinLi_1ion             200.0*FIT_spinthermo * FIT_spinLi
#define wspinLineutrlion         200.0*FIT_spinthermo * FIT_spinLi

#define wspinBeneutrlion         200.0*FIT_spinthermo * FIT_spinBe
#define wspinBeneutrlexion        50.0*FIT_spinthermo * FIT_spinBe*FIT_ex
#define wspinBeplus1ion           200.0*FIT_spinthermo * FIT_spinBe

#define wspinNa_1ion             200.0*FIT_spinthermo * FIT_spinNa
#define wspinNaneutrlion         200.0*FIT_spinthermo * FIT_spinNa

#define wspinMgneutrlion         200.0*FIT_spinthermo * FIT_spinMg
#define wspinMgneutrlexion        50.0*FIT_spinthermo * FIT_spinMg*FIT_ex
#define wspinMgplus1ion           200.0*FIT_spinthermo * FIT_spinMg


#define wspinO2_2dis          1.0*FIT_spinthermo * FIT_spinOO
#define wspinO2_1dis          1.0*FIT_spinthermo * FIT_spinOO
#define wspinO2dis            1.0*FIT_spinthermo * FIT_spinOO
#define wspinOHdotaff         1.0*FIT_spinthermo * FIT_spinOH
#define wspinOHdotdis	      1.0*FIT_spinthermo * FIT_spinH * FIT_spinOH 
#define wspinH2Odim           1.0*FIT_spinthermo * FIT_dimer
#define wspinO_1aff	      0.0
//==================================

//ainter energies are Hartree*A/ao
//that is hartree in Angstroms


//NUMERICAL CONSTANTS===============
#define debye             4.80215827
#define pi              3.1415926536
#define rootpi		1.7724538509
#define fJ              2.3070774E-3
#define kjmol           6.0221413E20
#define kcalmol             0.239006
#define EkeConst	 0.793765816 //(3/2) * h_me 
#define E_const          0.73522
#define E2_const         1.38936537
#define h_me		 0.529177211 //(h^2/me) which ends up meaning atomic radius to Angstrom constant
#define Scale2MJ	 1.0         //1.38936537

#define n_polar		 7 
#define del_qpolar	 5000.0
#define qstart		20000.0
//==================================

//DEVIATION REFERENCES==============
#define LENGTH                   1.0
#define LENGTH_XY                3.0
#define ANGLE                  100.0
#define DIHEDRAL               150.0
#define ESCALE			0.02
#define KT			 2.5 
#define DIPOLE                   2.0
/*No flex reference is defined.   */
//==================================

//OPERATIONAL MACROS================
#define ENERGY                     1
#define FORCE                      0
#define FORCE_D                    3
#define HESSIAN                    2
#define ON                         1
#define OFF                        0
//==================================

//DE PARAMETERS====================
#define MAXPOP  n_potentials * 100
#define MAXDIM  n_potentials
/*------Constants for rnd_uni()----*/
#define IM1 2147483563
#define IM2 2147483399
#define AM (1.0/IM1)
#define IMM1 (IM1-1)
#define IA1 40014
#define IA2 40692
#define IQ1 53668
#define IQ2 52774
#define IR1 12211
#define IR2 3791
#define NTAB 32
#define NDIV (1+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
//================================
