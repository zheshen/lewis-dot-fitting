//Simple Monte Carlo subroutine for Water Suite
//To be used as a final-finish to WS minima
//
//Type of MC is specified by the argument mc_type:
//

#include "Energy.h"
//Particle structure definition 
//struct V {double x,y,z, q; int s;};

//Function declarations******************************************
double metropolis(V *, int, int);

double sumEnergiesOne(struct V *, double **, double **, int);
double sumEnergiesAll(struct V *, double **, double **, int);
double sumEnergiesRegular(struct V *, double **, double **, int *, double, int);
double sumEnergiesSmallParticle(struct V *, double **, double **, double, int, int);
void updateEarrays(double **, double **, int *, int, int);
void updateEarray(double **, double **, int, int, int);
void updatePositions(struct V *, struct V *, int *, int, int);
void updatePosition(struct V *, struct V *, int, int);
void copyPositions(struct V *, struct V *, int);
void linreg(struct V *, int , double *, double *);

void getVx(struct V *, struct V *, int, int *);

//double sumEnergies_MC_one(struct V *, double **, double **, int);
//double sumEnergies_MC_reg(struct V *, double **, double **, double, int, int);
//void initializeArrays(struct V *, struct V *, struct V *, double **, double **, int);
//void finalizeArrays(struct V *, struct V *, int);
int isAllowed(struct V *, int, int);
//void updateArrays(struct V *, struct V *, double **, double **, int, int, int);
//void updatePositions(struct V *, struct V *, int, int);
//void updateEnergyArrays(double **, double **, int, int, int);
double getPairwiseEnergy(struct V *, int, int);
double getKineticEnergy(struct V *, int);
double getTBenergy(struct V *, struct V *, int, int, int);

//FRA's help with parallelization
//v was removed
int Met(double, double, double, unsigned int *);
//int Met(double, long, double, double, unsigned int *);
//int Met(double, long, double, double);
//

float drnd_r(unsigned int *myseed);
float ran2(long *);
float drnd();
//Utilities------------------------------------------------------
//double raddeg(double);
//double degrad(double);
//double getDistance(struct V *, int, int);
//double distance(int, int, int, int, int, int);
//double getAngle(struct V *, int, int, int);
//double angle(int, int, int, int, int, int);
//***************************************************************

//Global MC structure arrays for lowermain feedback**************
struct V V_spinO2qnt[m_spinO2qnt];
struct V V_spinO2qnt_linnett[m_spinO2qnt];
struct V V_spinO2qnt_snglbnd[m_spinO2qnt];
struct V V_spinO2qnt_dblbnd[m_spinO2qnt];
struct V V_spinO2qnt_trplbnd[m_spinO2qnt];

struct V V_spinB2_snglt_linnett[m_spinB2_snglt_linnett];
struct V V_spinB2_snglt_snglbnd[m_spinB2_snglt_snglbnd];
struct V V_spinB2_snglt_dblbnd[m_spinB2_snglt_dblbnd];
struct V V_spinB2_snglt_trplbnd[m_spinB2_snglt_trplbnd];
struct V V_spinB2_trplt_linnett[m_spinB2_trplt_linnett];
struct V V_spinB2_trplt_snglbnd[m_spinB2_trplt_snglbnd];
struct V V_spinB2_trplt_dblbnd[m_spinB2_trplt_dblbnd];
struct V V_spinB2_trplt_trplbnd[m_spinB2_trplt_trplbnd];
struct V V_spinAl2_snglt_linnett[m_spinAl2_snglt_linnett];
struct V V_spinAl2_snglt_snglbnd[m_spinAl2_snglt_snglbnd];
struct V V_spinAl2_snglt_dblbnd[m_spinAl2_snglt_dblbnd];
struct V V_spinAl2_snglt_trplbnd[m_spinAl2_snglt_trplbnd];
struct V V_spinAl2_trplt_linnett[m_spinAl2_trplt_linnett];
struct V V_spinAl2_trplt_snglbnd[m_spinAl2_trplt_snglbnd];
struct V V_spinAl2_trplt_dblbnd[m_spinAl2_trplt_dblbnd];
struct V V_spinAl2_trplt_trplbnd[m_spinAl2_trplt_trplbnd];
struct V V_spinC2_snglt_linnett[m_spinC2_snglt_linnett];
struct V V_spinC2_snglt_snglbnd[m_spinC2_snglt_snglbnd];
struct V V_spinC2_snglt_dblbnd[m_spinC2_snglt_dblbnd];
struct V V_spinC2_snglt_trplbnd[m_spinC2_snglt_trplbnd];
struct V V_spinC2_trplt_linnett[m_spinC2_trplt_linnett];
struct V V_spinC2_trplt_snglbnd[m_spinC2_trplt_snglbnd];
struct V V_spinC2_trplt_dblbnd[m_spinC2_trplt_dblbnd];
struct V V_spinC2_trplt_trplbnd[m_spinC2_trplt_trplbnd];
struct V V_spinSi2_snglt_linnett[m_spinSi2_snglt_linnett];
struct V V_spinSi2_snglt_snglbnd[m_spinSi2_snglt_snglbnd];
struct V V_spinSi2_snglt_dblbnd[m_spinSi2_snglt_dblbnd];
struct V V_spinSi2_snglt_trplbnd[m_spinSi2_snglt_trplbnd];
struct V V_spinSi2_trplt_linnett[m_spinSi2_trplt_linnett];
struct V V_spinSi2_trplt_snglbnd[m_spinSi2_trplt_snglbnd];
struct V V_spinSi2_trplt_dblbnd[m_spinSi2_trplt_dblbnd];
struct V V_spinSi2_trplt_trplbnd[m_spinSi2_trplt_trplbnd];
struct V V_spinN2_snglt_linnett[m_spinN2_snglt_linnett];
struct V V_spinN2_snglt_snglbnd[m_spinN2_snglt_snglbnd];
struct V V_spinN2_snglt_dblbnd[m_spinN2_snglt_dblbnd];
struct V V_spinN2_snglt_trplbnd[m_spinN2_snglt_trplbnd];
struct V V_spinN2_trplt_linnett[m_spinN2_trplt_linnett];
struct V V_spinN2_trplt_snglbnd[m_spinN2_trplt_snglbnd];
struct V V_spinN2_trplt_dblbnd[m_spinN2_trplt_dblbnd];
struct V V_spinN2_trplt_trplbnd[m_spinN2_trplt_trplbnd];
struct V V_spinP2_snglt_linnett[m_spinP2_snglt_linnett];
struct V V_spinP2_snglt_snglbnd[m_spinP2_snglt_snglbnd];
struct V V_spinP2_snglt_dblbnd[m_spinP2_snglt_dblbnd];
struct V V_spinP2_snglt_trplbnd[m_spinP2_snglt_trplbnd];
struct V V_spinP2_trplt_linnett[m_spinP2_trplt_linnett];
struct V V_spinP2_trplt_snglbnd[m_spinP2_trplt_snglbnd];
struct V V_spinP2_trplt_dblbnd[m_spinP2_trplt_dblbnd];
struct V V_spinP2_trplt_trplbnd[m_spinP2_trplt_trplbnd];
struct V V_spinS2_snglt_linnett[m_spinS2_snglt_linnett];
struct V V_spinS2_snglt_snglbnd[m_spinS2_snglt_snglbnd];
struct V V_spinS2_snglt_dblbnd[m_spinS2_snglt_dblbnd];
struct V V_spinS2_snglt_trplbnd[m_spinS2_snglt_trplbnd];
struct V V_spinS2_trplt_linnett[m_spinS2_trplt_linnett];
struct V V_spinS2_trplt_snglbnd[m_spinS2_trplt_snglbnd];
struct V V_spinS2_trplt_dblbnd[m_spinS2_trplt_dblbnd];
struct V V_spinS2_trplt_trplbnd[m_spinS2_trplt_trplbnd];
struct V V_spinF2_snglt_linnett[m_spinF2_snglt_linnett];
struct V V_spinF2_snglt_snglbnd[m_spinF2_snglt_snglbnd];
struct V V_spinF2_snglt_dblbnd[m_spinF2_snglt_dblbnd];
struct V V_spinF2_snglt_trplbnd[m_spinF2_snglt_trplbnd];
struct V V_spinF2_trplt_linnett[m_spinF2_trplt_linnett];
struct V V_spinF2_trplt_snglbnd[m_spinF2_trplt_snglbnd];
struct V V_spinF2_trplt_dblbnd[m_spinF2_trplt_dblbnd];
struct V V_spinF2_trplt_trplbnd[m_spinF2_trplt_trplbnd];
struct V V_spinCl2_snglt_linnett[m_spinCl2_snglt_linnett];
struct V V_spinCl2_snglt_snglbnd[m_spinCl2_snglt_snglbnd];
struct V V_spinCl2_snglt_dblbnd[m_spinCl2_snglt_dblbnd];
struct V V_spinCl2_snglt_trplbnd[m_spinCl2_snglt_trplbnd];
struct V V_spinCl2_trplt_linnett[m_spinCl2_trplt_linnett];
struct V V_spinCl2_trplt_snglbnd[m_spinCl2_trplt_snglbnd];
struct V V_spinCl2_trplt_dblbnd[m_spinCl2_trplt_dblbnd];
struct V V_spinCl2_trplt_trplbnd[m_spinCl2_trplt_trplbnd];

struct V V_spinH_polar[m_spinH_polar];
struct V V_spinBneutrl_polar[m_spinBneutrl_polar];
struct V V_spinCneutrl_polar[m_spinCneutrl_polar];
struct V V_spinNneutrl_polar[m_spinNneutrl_polar];
struct V V_spinOneutrl_polar[m_spinOneutrl_polar];
struct V V_spinFneutrl_polar[m_spinFneutrl_polar];
struct V V_spinAlneutrl_polar[m_spinAlneutrl_polar];
struct V V_spinSineutrl_polar[m_spinSineutrl_polar];
struct V V_spinPneutrl_polar[m_spinPneutrl_polar];
struct V V_spinSneutrl_polar[m_spinSneutrl_polar];
struct V V_spinClneutrl_polar[m_spinClneutrl_polar];



struct V V_spinH4linear[m_spinH4linear];
struct V V_spinH4square[m_spinH4square];
struct V V_spinH4tetra[m_spinH4tetra];
struct V V_spinH3linear[m_spinH3linear];
struct V V_spinH3trig[m_spinH3trig];

struct V V_spinH2minus[m_spinH2minus];
struct V V_spinH4[m_spinH4];
struct V V_spinH3[m_spinH3];
struct V V_spinOHdot2[m_spinOHdot2];
struct V V_spinOH[m_spinOH];
struct V V_TransitionspinOH[m_TransitionspinOH];
struct V V_spinOneutrl[m_spinOneutrl];
struct V V_spinO_1[m_spinO_1];
struct V V_spinO_2[m_spinO_2];
struct V V_spinOplus[m_spinOplus];
struct V V_spinOplus2[m_spinOplus2];
struct V V_spinOplus3[m_spinOplus3];
struct V V_spinOplus4[m_spinOplus4];
struct V V_spinOplus5[m_spinOplus5];
struct V V_spinOneutrlex[m_spinOneutrlex];
struct V V_spinOplus2ex[m_spinOplus2ex];
struct V V_spinOplusex[m_spinOplusex];
struct V V_spinOplus3ex[m_spinOplus3ex];
struct V V_spinOplus4ex[m_spinOplus4ex];
struct V V_spinOplus2ex2[m_spinOplus2ex2];

struct V V_spinCplus3[m_spinCplus3];
struct V V_spinCplus2[m_spinCplus2];
struct V V_spinCplus[m_spinCplus];
struct V V_spinCneutrl[m_spinCneutrl];
struct V V_spinC_1[m_spinC_1];
struct V V_spinNplus4[m_spinNplus4];
struct V V_spinNplus3[m_spinNplus3];
struct V V_spinNplus2[m_spinNplus2];
struct V V_spinNplus[m_spinNplus];
struct V V_spinNneutrl[m_spinNneutrl];
struct V V_spinN_1[m_spinN_1];
struct V V_spinSplus5[m_spinSplus5];
struct V V_spinSplus4[m_spinSplus4];
struct V V_spinSplus3[m_spinSplus3];
struct V V_spinSplus2[m_spinSplus2];
struct V V_spinSplus[m_spinSplus];
struct V V_spinSneutrl[m_spinSneutrl];
struct V V_spinS_1[m_spinS_1];
struct V V_spinPplus4[m_spinPplus4];
struct V V_spinPplus3[m_spinPplus3];
struct V V_spinPplus2[m_spinPplus2];
struct V V_spinPplus[m_spinPplus];
struct V V_spinPneutrl[m_spinPneutrl];
struct V V_spinP_1[m_spinP_1];
struct V V_spinSiplus3[m_spinSiplus3];
struct V V_spinSiplus2[m_spinSiplus2];
struct V V_spinSiplus[m_spinSiplus];
struct V V_spinSineutrl[m_spinSineutrl];
struct V V_spinSi_1[m_spinSi_1];
struct V V_spinFplus6[m_spinFplus6];
struct V V_spinFplus5[m_spinFplus5];
struct V V_spinFplus4[m_spinFplus4];
struct V V_spinFplus3[m_spinFplus3];
struct V V_spinFplus2[m_spinFplus2];
struct V V_spinFplus[m_spinFplus];
struct V V_spinFneutrl[m_spinFneutrl];
struct V V_spinF_1[m_spinF_1];

struct V V_spinCplus2ex[m_spinCplus2ex];
struct V V_spinCplusex[m_spinCplusex];
struct V V_spinCneutrlex[m_spinCneutrlex];
struct V V_spinCneutrlex2[m_spinCneutrlex2];
struct V V_spinNplus3ex[m_spinNplus3ex];
struct V V_spinNplus2ex[m_spinNplus2ex];
struct V V_spinNplusex[m_spinNplusex];
struct V V_spinNplusex2[m_spinNplusex2];
struct V V_spinNneutrlex[m_spinNneutrlex];
struct V V_spinFplus5ex[m_spinFplus5ex];
struct V V_spinFplus4ex[m_spinFplus4ex];
struct V V_spinFplus3ex[m_spinFplus3ex];
struct V V_spinFplus3ex2[m_spinFplus3ex2];
struct V V_spinFplus2ex[m_spinFplus2ex];
struct V V_spinFplusex[m_spinFplusex];
struct V V_spinSiplus2ex[m_spinSiplus2ex];
struct V V_spinSiplusex[m_spinSiplusex];
struct V V_spinSineutrlex[m_spinSineutrlex];
struct V V_spinSineutrlex2[m_spinSineutrlex2];
struct V V_spinPplus3ex[m_spinPplus3ex];
struct V V_spinPplus2ex[m_spinPplus2ex];
struct V V_spinPplusex[m_spinPplusex];
struct V V_spinPplusex2[m_spinPplusex2];
struct V V_spinPneutrlex[m_spinPneutrlex];
struct V V_spinSplus4ex[m_spinSplus4ex];
struct V V_spinSplus3ex[m_spinSplus3ex];
struct V V_spinSplus2ex[m_spinSplus2ex];
struct V V_spinSplus2ex2[m_spinSplus2ex2];
struct V V_spinSplusex[m_spinSplusex];
struct V V_spinSneutrlex[m_spinSneutrlex];

struct V V_spinOneutrlex2[m_spinOneutrlex2];
struct V V_spinOplusex2[m_spinOplusex2];
struct V V_spinNneutrlex2[m_spinNneutrlex2];
struct V V_spinFneutrlex[m_spinFneutrlex];
struct V V_spinFplusex2[m_spinFplusex2];
struct V V_spinFplus2ex2[m_spinFplus2ex2];
struct V V_spinSneutrlex2[m_spinSneutrlex2];

struct V V_spinB_1[m_spinB_1];
struct V V_spinBneutrlex[m_spinBneutrlex];
struct V V_spinBneutrl[m_spinBneutrl];
struct V V_spinBplusex[m_spinBplusex];
struct V V_spinBplus[m_spinBplus];
struct V V_spinBplus2[m_spinBplus2];

struct V V_spinCl_1[m_spinCl_1];
struct V V_spinClneutrlex[m_spinClneutrlex];
struct V V_spinClneutrl[m_spinClneutrl];
struct V V_spinClplusex2[m_spinClplusex2];
struct V V_spinClplusex[m_spinClplusex];
struct V V_spinClplus[m_spinClplus];
struct V V_spinClplus2ex[m_spinClplus2ex];
struct V V_spinClplus2[m_spinClplus2];
struct V V_spinClplus3ex2[m_spinClplus3ex2];
struct V V_spinClplus3ex[m_spinClplus3ex];
struct V V_spinClplus3[m_spinClplus3];
struct V V_spinClplus4ex[m_spinClplus4ex];
struct V V_spinClplus4[m_spinClplus4];
struct V V_spinClplus5ex[m_spinClplus5ex];
struct V V_spinClplus5[m_spinClplus5];
struct V V_spinClplus6[m_spinClplus6];
struct V V_spinAl_1[m_spinAl_1];
struct V V_spinAlneutrlex[m_spinAlneutrlex];
struct V V_spinAlneutrl[m_spinAlneutrl];
struct V V_spinAlplusex[m_spinAlplusex];
struct V V_spinAlplus[m_spinAlplus];
struct V V_spinAlplus2[m_spinAlplus2];

struct V V_spinAl2_trplt[m_spinAl2_trplt];
struct V V_spinAl2_snglt[m_spinAl2_snglt];

struct V V_spinLi_1[m_spinLi_1];
struct V V_spinLineutrl[m_spinLineutrl];
struct V V_spinBeneutrl[m_spinBeneutrl];
struct V V_spinBeneutrlex[m_spinBeneutrlex];
struct V V_spinBeplus[m_spinBeplus];
struct V V_spinNa_1[m_spinNa_1];
struct V V_spinNaneutrl[m_spinNaneutrl];
struct V V_spinMgneutrl[m_spinMgneutrl];
struct V V_spinMgneutrlex[m_spinMgneutrlex];
struct V V_spinMgplus[m_spinMgplus];

struct V V_spinO2[m_spinO2];
struct V V_spinO2dia[m_spinO2dia];

struct V V_spinO2_linnett[m_spinO2];
struct V V_spinO2dia_linnett[m_spinO2dia];
struct V V_spinO2_snglbnd[m_spinO2];
struct V V_spinO2dia_snglbnd[m_spinO2dia];
struct V V_spinO2_dblbnd[m_spinO2];
struct V V_spinO2dia_dblbnd[m_spinO2dia];
struct V V_spinO2_trplbnd[m_spinO2];
struct V V_spinO2dia_trplbnd[m_spinO2dia];

struct V V_spinB2_trplt[m_spinB2_trplt];
struct V V_spinB2_snglt[m_spinB2_snglt];
struct V V_spinC2_trplt[m_spinC2_trplt];
struct V V_spinC2_snglt[m_spinC2_snglt];
struct V V_spinSi2_trplt[m_spinSi2_trplt];
struct V V_spinSi2_snglt[m_spinSi2_snglt];
struct V V_spinN2_trplt[m_spinN2_trplt];
struct V V_spinN2_snglt[m_spinN2_snglt];
struct V V_spinS2_trplt[m_spinS2_trplt];
struct V V_spinS2_snglt[m_spinS2_snglt];
struct V V_spinF2_trplt[m_spinF2_trplt];
struct V V_spinF2_snglt[m_spinF2_snglt];
struct V V_spinCl2_trplt[m_spinCl2_trplt];
struct V V_spinCl2_snglt[m_spinCl2_snglt];
struct V V_spinP2_trplt[m_spinP2_trplt];
struct V V_spinP2_snglt[m_spinP2_snglt];

struct V V_spinZnplus11[m_spinZnplus11];
struct V V_spinZnplus10[m_spinZnplus10];
struct V V_spinZnplus10ex[m_spinZnplus10ex];
struct V V_spinZnplus9[m_spinZnplus9];
struct V V_spinZnplus8[m_spinZnplus8];
struct V V_spinZnplus7[m_spinZnplus7];
struct V V_spinZnplus6[m_spinZnplus6];
struct V V_spinZnplus6ex[m_spinZnplus6ex];
struct V V_spinZnplus6ex2[m_spinZnplus6ex2];
struct V V_spinZnplus5[m_spinZnplus5];
struct V V_spinZnplus5ex[m_spinZnplus5ex];
struct V V_spinZnplus5ex2[m_spinZnplus5ex2];
struct V V_spinZnplus4[m_spinZnplus4];
struct V V_spinZnplus4ex[m_spinZnplus4ex];
struct V V_spinZnplus4ex2[m_spinZnplus4ex2];
struct V V_spinZnplus3[m_spinZnplus3];
struct V V_spinZnplus3ex[m_spinZnplus3ex];
struct V V_spinZnplus2[m_spinZnplus2];
struct V V_spinZnplus2ex[m_spinZnplus2ex];

struct V V_spinScplus2[m_spinScplus2];
struct V V_spinTiplus3[m_spinTiplus3];
struct V V_spinTiplus2[m_spinTiplus2];
struct V V_spinTiplus2ex[m_spinTiplus2ex];
struct V V_spinVplus4[m_spinVplus4];
struct V V_spinVplus3[m_spinVplus3];
struct V V_spinVplus3ex[m_spinVplus3ex];
struct V V_spinVplus2[m_spinVplus2];
struct V V_spinVplus2ex[m_spinVplus2ex];
struct V V_spinCrplus5[m_spinCrplus5];
struct V V_spinCrplus4[m_spinCrplus4];
struct V V_spinCrplus4ex[m_spinCrplus4ex];
struct V V_spinCrplus3[m_spinCrplus3];
struct V V_spinCrplus3ex[m_spinCrplus3ex];
struct V V_spinCrplus2[m_spinCrplus2];
struct V V_spinCrplus2ex[m_spinCrplus2ex];
struct V V_spinCrplus2ex2[m_spinCrplus2ex2];
struct V V_spinCrplus1[m_spinCrplus1];
struct V V_spinCrplus1ex[m_spinCrplus1ex];
struct V V_spinCrplus1ex2[m_spinCrplus1ex2];
struct V V_spinMnplus6[m_spinMnplus6];
struct V V_spinMnplus5[m_spinMnplus5];
struct V V_spinMnplus5ex[m_spinMnplus5ex];
struct V V_spinMnplus4[m_spinMnplus4];
struct V V_spinMnplus4ex[m_spinMnplus4ex];
struct V V_spinMnplus3[m_spinMnplus3];
struct V V_spinMnplus3ex[m_spinMnplus3ex];
struct V V_spinMnplus2[m_spinMnplus2];
struct V V_spinMnplus2ex[m_spinMnplus2ex];
struct V V_spinMnplus2ex2[m_spinMnplus2ex2];
struct V V_spinFeplus7[m_spinFeplus7];
struct V V_spinFeplus6[m_spinFeplus6];
struct V V_spinFeplus6ex[m_spinFeplus6ex];
struct V V_spinFeplus5[m_spinFeplus5];
struct V V_spinFeplus5ex[m_spinFeplus5ex];
struct V V_spinFeplus4[m_spinFeplus4];
struct V V_spinFeplus4ex[m_spinFeplus4ex];
struct V V_spinFeplus4ex2[m_spinFeplus4ex2];
struct V V_spinFeplus3[m_spinFeplus3];
struct V V_spinFeplus3ex[m_spinFeplus3ex];
struct V V_spinFeplus3ex2[m_spinFeplus3ex2];
struct V V_spinFeplus2[m_spinFeplus2];
struct V V_spinFeplus2ex[m_spinFeplus2ex];
struct V V_spinFeplus2ex2[m_spinFeplus2ex2];
struct V V_spinCoplus8[m_spinCoplus8];
struct V V_spinCoplus7[m_spinCoplus7];
struct V V_spinCoplus7ex[m_spinCoplus7ex];
struct V V_spinCoplus6[m_spinCoplus6];
struct V V_spinCoplus6ex[m_spinCoplus6ex];
struct V V_spinCoplus5[m_spinCoplus5];
struct V V_spinCoplus5ex[m_spinCoplus5ex];
struct V V_spinCoplus5ex2[m_spinCoplus5ex2];
struct V V_spinCoplus4[m_spinCoplus4];
struct V V_spinCoplus4ex[m_spinCoplus4ex];
struct V V_spinCoplus4ex2[m_spinCoplus4ex2];
struct V V_spinCoplus3[m_spinCoplus3];
struct V V_spinCoplus3ex[m_spinCoplus3ex];
struct V V_spinCoplus3ex2[m_spinCoplus3ex2];
struct V V_spinCoplus2[m_spinCoplus2];
struct V V_spinCoplus2ex[m_spinCoplus2ex];
struct V V_spinCoplus2ex2[m_spinCoplus2ex2];
struct V V_spinNiplus9[m_spinNiplus9];
struct V V_spinNiplus8[m_spinNiplus8];
struct V V_spinNiplus8ex[m_spinNiplus8ex];
struct V V_spinNiplus7[m_spinNiplus7];
struct V V_spinNiplus7ex[m_spinNiplus7ex];
struct V V_spinNiplus6[m_spinNiplus6];
struct V V_spinNiplus6ex[m_spinNiplus6ex];
struct V V_spinNiplus5[m_spinNiplus5];
struct V V_spinNiplus5ex[m_spinNiplus5ex];
struct V V_spinNiplus5ex2[m_spinNiplus5ex2];
struct V V_spinNiplus4[m_spinNiplus4];
struct V V_spinNiplus4ex[m_spinNiplus4ex];
struct V V_spinNiplus4ex2[m_spinNiplus4ex2];
struct V V_spinNiplus3[m_spinNiplus3];
struct V V_spinNiplus3ex[m_spinNiplus3ex];
struct V V_spinNiplus3ex2[m_spinNiplus3ex2];
struct V V_spinNiplus2[m_spinNiplus2];
struct V V_spinNiplus2ex[m_spinNiplus2ex];
struct V V_spinNiplus2ex2[m_spinNiplus2ex2];
struct V V_spinCuplus10[m_spinCuplus10];
struct V V_spinCuplus9[m_spinCuplus9];
struct V V_spinCuplus9ex[m_spinCuplus9ex];
struct V V_spinCuplus8[m_spinCuplus8];
struct V V_spinCuplus7[m_spinCuplus7];
struct V V_spinCuplus6[m_spinCuplus6];
struct V V_spinCuplus5[m_spinCuplus5];
struct V V_spinCuplus5ex[m_spinCuplus5ex];
struct V V_spinCuplus5ex2[m_spinCuplus5ex2];
struct V V_spinCuplus4[m_spinCuplus4];
struct V V_spinCuplus4ex[m_spinCuplus4ex];
struct V V_spinCuplus4ex2[m_spinCuplus4ex2];
struct V V_spinCuplus3[m_spinCuplus3];
struct V V_spinCuplus3ex[m_spinCuplus3ex];
struct V V_spinCuplus3ex2[m_spinCuplus3ex2];
struct V V_spinCuplus2[m_spinCuplus2];
struct V V_spinCuplus2ex[m_spinCuplus2ex];
struct V V_spinCuplus1[m_spinCuplus1];
struct V V_spinCuplus1ex[m_spinCuplus1ex];
struct V V_spinYplus2[m_spinYplus2];
struct V V_spinZrplus3[m_spinZrplus3];
struct V V_spinZrplus2[m_spinZrplus2];
struct V V_spinZrplus2ex[m_spinZrplus2ex];
struct V V_spinNbplus4[m_spinNbplus4];
struct V V_spinNbplus3[m_spinNbplus3];
struct V V_spinNbplus3ex[m_spinNbplus3ex];
struct V V_spinNbplus2[m_spinNbplus2];
struct V V_spinNbplus2ex[m_spinNbplus2ex];
struct V V_spinNbplus1[m_spinNbplus1];
struct V V_spinNbplus1ex[m_spinNbplus1ex];
struct V V_spinNbplus1ex2[m_spinNbplus1ex2];
struct V V_spinMoplus5[m_spinMoplus5];
struct V V_spinMoplus4[m_spinMoplus4];
struct V V_spinMoplus4ex[m_spinMoplus4ex];
struct V V_spinMoplus3[m_spinMoplus3];
struct V V_spinMoplus3ex[m_spinMoplus3ex];
struct V V_spinMoplus2[m_spinMoplus2];
struct V V_spinMoplus2ex[m_spinMoplus2ex];
struct V V_spinMoplus2ex2[m_spinMoplus2ex2];
struct V V_spinMoplus1[m_spinMoplus1];
struct V V_spinMoplus1ex[m_spinMoplus1ex];
struct V V_spinMoplus1ex2[m_spinMoplus1ex2];
struct V V_spinTcplus6[m_spinTcplus6];
struct V V_spinTcplus5[m_spinTcplus5];
struct V V_spinTcplus4[m_spinTcplus4];
struct V V_spinTcplus3[m_spinTcplus3];
struct V V_spinTcplus2[m_spinTcplus2];
struct V V_spinRuplus7[m_spinRuplus7];
struct V V_spinRuplus6[m_spinRuplus6];
struct V V_spinRuplus5[m_spinRuplus5];
struct V V_spinRuplus4[m_spinRuplus4];
struct V V_spinRuplus3[m_spinRuplus3];
struct V V_spinRuplus2[m_spinRuplus2];
struct V V_spinRuplus2ex[m_spinRuplus2ex];
struct V V_spinRuplus1[m_spinRuplus1];
struct V V_spinRuplus1ex[m_spinRuplus1ex];
struct V V_spinRuplus1ex2[m_spinRuplus1ex2];
struct V V_spinRhplus8[m_spinRhplus8];
struct V V_spinRhplus7[m_spinRhplus7];
struct V V_spinRhplus6[m_spinRhplus6];
struct V V_spinRhplus5[m_spinRhplus5];
struct V V_spinRhplus4[m_spinRhplus4];
struct V V_spinRhplus3[m_spinRhplus3];
struct V V_spinRhplus2[m_spinRhplus2];
struct V V_spinRhplus2ex[m_spinRhplus2ex];
struct V V_spinRhplus2ex2[m_spinRhplus2ex2];
struct V V_spinRhplus1[m_spinRhplus1];
struct V V_spinRhplus1ex[m_spinRhplus1ex];
struct V V_spinRhplus1ex2[m_spinRhplus1ex2];
struct V V_spinPdplus9[m_spinPdplus9];
struct V V_spinPdplus8[m_spinPdplus8];
struct V V_spinPdplus7[m_spinPdplus7];
struct V V_spinPdplus6[m_spinPdplus6];
struct V V_spinPdplus5[m_spinPdplus5];
struct V V_spinPdplus4[m_spinPdplus4];
struct V V_spinPdplus3[m_spinPdplus3];
struct V V_spinPdplus2[m_spinPdplus2];
struct V V_spinPdplus2ex[m_spinPdplus2ex];
struct V V_spinPdplus2ex2[m_spinPdplus2ex2];
struct V V_spinPdplus1[m_spinPdplus1];
struct V V_spinPdplus1ex[m_spinPdplus1ex];
struct V V_spinPdneutrl[m_spinPdneutrl];
struct V V_spinPdneutrlex[m_spinPdneutrlex];
struct V V_spinAgplus10[m_spinAgplus10];
struct V V_spinAgplus9[m_spinAgplus9];
struct V V_spinAgplus8[m_spinAgplus8];
struct V V_spinAgplus7[m_spinAgplus7];
struct V V_spinAgplus6[m_spinAgplus6];
struct V V_spinAgplus5[m_spinAgplus5];
struct V V_spinAgplus4[m_spinAgplus4];
struct V V_spinAgplus3[m_spinAgplus3];
struct V V_spinAgplus2[m_spinAgplus2];
struct V V_spinAgplus2ex[m_spinAgplus2ex];
struct V V_spinAgplus1[m_spinAgplus1];
struct V V_spinAgplus1ex[m_spinAgplus1ex];
struct V V_spinCdplus11[m_spinCdplus11];
struct V V_spinCdplus10[m_spinCdplus10];
struct V V_spinCdplus9[m_spinCdplus9];
struct V V_spinCdplus8[m_spinCdplus8];
struct V V_spinCdplus7[m_spinCdplus7];
struct V V_spinCdplus6[m_spinCdplus6];
struct V V_spinCdplus5[m_spinCdplus5];
struct V V_spinCdplus4[m_spinCdplus4];
struct V V_spinCdplus3[m_spinCdplus3];
struct V V_spinCdplus3ex[m_spinCdplus3ex];
struct V V_spinCdplus2[m_spinCdplus2];
struct V V_spinCdplus2ex[m_spinCdplus2ex];

struct V V_spinZnplus1[m_spinZnplus1];
struct V V_spinZnplus1ex[m_spinZnplus1ex];
struct V V_spinZnneutrl[m_spinZnneutrl];
struct V V_spinZnneutrlex[m_spinZnneutrlex];
struct V V_spinCuneutrl[m_spinCuneutrl];
struct V V_spinCuneutrlex[m_spinCuneutrlex];
struct V V_spinNiplus1[m_spinNiplus1];
struct V V_spinNiplus1ex[m_spinNiplus1ex];
struct V V_spinNineutrl[m_spinNineutrl];
struct V V_spinNineutrlex[m_spinNineutrlex];
struct V V_spinCoplus1[m_spinCoplus1];
struct V V_spinCoplus1ex[m_spinCoplus1ex];
struct V V_spinCoplus1ex2[m_spinCoplus1ex2];
struct V V_spinConeutrl[m_spinConeutrl];
struct V V_spinConeutrlex[m_spinConeutrlex];
struct V V_spinFeplus1[m_spinFeplus1];
struct V V_spinFeplus1ex[m_spinFeplus1ex];
struct V V_spinFeplus1ex2[m_spinFeplus1ex2];
struct V V_spinFeneutrl[m_spinFeneutrl];
struct V V_spinFeneutrlex[m_spinFeneutrlex];
struct V V_spinFeneutrlex2[m_spinFeneutrlex2];
struct V V_spinFeneutrlex3[m_spinFeneutrlex3];
struct V V_spinMnplus1[m_spinMnplus1];
struct V V_spinMnplus1ex[m_spinMnplus1ex];
struct V V_spinMnplus1ex2[m_spinMnplus1ex2];
struct V V_spinMnplus1ex3[m_spinMnplus1ex3];
struct V V_spinMnneutrl[m_spinMnneutrl];
struct V V_spinMnneutrlex[m_spinMnneutrlex];
struct V V_spinMnneutrlex2[m_spinMnneutrlex2];
struct V V_spinMnneutrlex3[m_spinMnneutrlex3];
struct V V_spinCrneutrl[m_spinCrneutrl];
struct V V_spinCrneutrlex[m_spinCrneutrlex];
struct V V_spinCrneutrlex2[m_spinCrneutrlex2];
struct V V_spinCrneutrlex3[m_spinCrneutrlex3];
struct V V_spinVplus1[m_spinVplus1];
struct V V_spinVplus1ex[m_spinVplus1ex];
struct V V_spinVplus1ex2[m_spinVplus1ex2];
struct V V_spinVneutrl[m_spinVneutrl];
struct V V_spinVneutrlex[m_spinVneutrlex];
struct V V_spinVneutrlex2[m_spinVneutrlex2];
struct V V_spinTiplus1[m_spinTiplus1];
struct V V_spinTiplus1ex[m_spinTiplus1ex];
struct V V_spinTineutrl[m_spinTineutrl];
struct V V_spinTineutrlex[m_spinTineutrlex];
struct V V_spinTineutrlex2[m_spinTineutrlex2];
struct V V_spinScplus1[m_spinScplus1];
struct V V_spinScplus1ex[m_spinScplus1ex];
struct V V_spinScneutrl[m_spinScneutrl];
struct V V_spinScneutrlex[m_spinScneutrlex];

struct V V_spinCdplus1[m_spinCdplus1];
struct V V_spinCdplus1ex[m_spinCdplus1ex];
struct V V_spinCdneutrl[m_spinCdneutrl];
struct V V_spinCdneutrlex[m_spinCdneutrlex];
struct V V_spinAgneutrl[m_spinAgneutrl];
struct V V_spinAgneutrlex[m_spinAgneutrlex];
struct V V_spinRhneutrl[m_spinRhneutrl];
struct V V_spinRhneutrlex[m_spinRhneutrlex];
struct V V_spinRuneutrl[m_spinRuneutrl];
struct V V_spinRuneutrlex[m_spinRuneutrlex];
struct V V_spinRuneutrlex2[m_spinRuneutrlex2];
struct V V_spinTcplus1[m_spinTcplus1];
struct V V_spinTcplus1ex[m_spinTcplus1ex];
struct V V_spinTcneutrl[m_spinTcneutrl];
struct V V_spinTcneutrlex[m_spinTcneutrlex];
struct V V_spinTcneutrlex2[m_spinTcneutrlex2];
struct V V_spinTcneutrlex3[m_spinTcneutrlex3];
struct V V_spinMoneutrl[m_spinMoneutrl];
struct V V_spinMoneutrlex[m_spinMoneutrlex];
struct V V_spinMoneutrlex2[m_spinMoneutrlex2];
struct V V_spinMoneutrlex3[m_spinMoneutrlex3];
struct V V_spinNbneutrl[m_spinNbneutrl];
struct V V_spinNbneutrlex[m_spinNbneutrlex];
struct V V_spinNbneutrlex2[m_spinNbneutrlex2];
struct V V_spinZrplus1[m_spinZrplus1];
struct V V_spinZrplus1ex[m_spinZrplus1ex];
struct V V_spinZrneutrl[m_spinZrneutrl];
struct V V_spinZrneutrlex[m_spinZrneutrlex];
struct V V_spinZrneutrlex2[m_spinZrneutrlex2];
struct V V_spinYplus1[m_spinYplus1];
struct V V_spinYplus1ex[m_spinYplus1ex];
struct V V_spinYneutrl[m_spinYneutrl];
struct V V_spinYneutrlex[m_spinYneutrlex];


//***************************************************************
