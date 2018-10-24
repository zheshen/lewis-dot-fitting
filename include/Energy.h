/*************************************************************************************************
 *                                           Energy.h                                            *
 *                                                                                               *
 * by Seyit Kale                                                                                 *
 * Sept 22, 2009.                                                                                *
 * Last revised: Dec 6, 2010                                                                     *
 ************************************************************************************************/
#include "Structure.h"

//Declaration of interaction types================================================================
double formOfAAX(V *, V *, V *, double, double, double, double, double, double, double, double, double, double, double, double, double, double,double, double, double, double, double, double, double, double, double, double, double, double, double, int, int, int, double *);
double formOfAA(V *, V *, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, int, int, int, int, double *);
double formOfAB(V *, V *, double, double, double, double, double, double, double, int, int, int, int, double *);
double formOfAV(double, double, double, double, double, double, double, double, double, double, \
        int, int, int, int, double *);
double formOfAH(double,double, double, double, double, double, double, double, double, double, double, double, int, int, int, double *);
double formOfXA(V *, V *, double, double, double, double, double, double, double, double, double, double, double, double, double, int, int, int, int, double *);
double formOfVV(double, double, double, double, double, double, double, double, double, \
	int, int, int, int, double *);
double formOfVH(double, double, double, double, double, double, double, int, int, int, double *);
double formOfXV(double, double, double, double, double, double, double, int, int, int, int, double *);
double formOfHH(double, double, double, double, double, double, double, int, int, int, double *);
double formOfXH(double, double, double, double, double, double, double, int, int, int, int, int, double *);
double formOfXY(double, double, double, double, double, double, double, int, int, int, int, int, double *);
double formOfKE(double, double complex, double, double, double, double, double, int, double *);
//double formOfMH(double, double, double, double, double, double, double, int, int, int);
//double formOfMV(double, double, double, double, double, double, double, int, int, int);
//double formOfXM(double, double, double, double, double, double, double, int, int, int, int, int);
//double formOfMM(double, double, double, double, double, double, double, int, int, int, int, int);
double formOfAA_split(V *, V *, double, double, double, double, double, double, double, double, double, double, double, double, double, int, int, int, int, double *);
double formOfAB_split(V *, V *, double, double, double, double, double, double, double, int, int, int, int, double *);
double formOfXA_split(V *, V *, double, double, double, double, double, double, double, double, double, double, double, double, double, int, int, int, int, double *);
//================================================================================================

//Primary energy call=============================================================================
double kineticEnergy_split(double complex, double, double, int, double *);
double kineticEnergy(double complex, double, double, int);
double energy_split(V *, V *, int, double *);
double energy(V *, V *, int);
//int energy_split(V *, V *, int, double *);
double TBenergy_split(V *, V *, V *, int, double *);//3-body energy
double TBenergy(V *, V *, V *, int);//3-body energy
double interaction(double, double, double, int);
//================================================================================================

//Declaration of common functional forms==========================================================
double simpleKE(double, double, int);
double scaledKE(double, double, double, int);
double scaledKE_complex(double, double complex, double, double, double, double, double, int);
double shiftedKE(double, double, double, double, int);
double simpleCoulomb(double, double, double, int);
double superCoulomb(double, double, double, double, int);
double sizeAdjust(double,double,double,double,int);

double kineticExchange(double, double, double,int);
double kineticExchangeVar2(double, double, double, double, double, int);

double DexclusionSum3Gaussians(double, double, double, double, double, double, double, double, double, double, double, int);
double DexclusionSum3GaussiansNested(double, double, double, double, double, double, double, double, double, int);
double DexclusionSum3SuperGaussiansNested(double, double, double, double, double, double, double, int);
double DexclusionProd3Lorentzians(double, double, double, double, double, double, double, int);
double DexclusionProd3LorentziansOver8thPow(double, double, double, double, double, double, double, int);
double DexclusionSumGandSuperGPowN(double, double, double, double, double, double, double, double, int);
double DexclusionSumGPowNandGPowNM(double, double, double, double, double, double, double, double, double, int);

double DvirialExponentialExclusion(double, double, double, double, double, double, int);
double DvirialGaussianExclusion(double, double, double, double, double, double, int);
double DvirialShiftedExclusionPow6(double, double, double, double, double, double, int);
double DvirialLorentzianExclusionPowN(double, double, double, double,double, double, double, int);
double DvirialLorentzianExclusionPowNVar1(double, double, double, double,double, double, double, int);
double DvirialLorentzianExclusionPowNPar3(double, double, double, double, double, double, double, double, int);
double DvirialLorentzianExclusionPow6Par3(double, double, double, double, double, double, double, int);


double DexclusionGaussian(double, double, double, double, int);
double Dexclusion1Gaussian(double, double, double, double, int);
double DexclusionGaussianReff(double, double, double, double, double, int);
double DexclusionGaussianReff1Par(double, double, double, double, int);

double DexclusionLorentzianVar1(double, double, double, double, double, int);
double DexclusionLorentzianVar2(double, double, double, double, double, int);
double DexclusionLorentzian6Pow(double, double, double, double, int);

double Dexclusion2CrossGaussianReff(double, double, double, double, double, double, double, int);
double Dexclusion2CrossPow4GaussianReff(double, double, double, double, double, double, double, int);
double Dexclusion2CrossPoly22Exp4Reff(double, double, double, double, double, double, double, int);


double kineticTermForExclusion(double, double, double, double, int);
double overlapTermForExclusion(double, double, double, double, int);
double effLikeExclusion(double, double, double, double, int);

double DampedOscillCosExp(double, double, double, double, double, double, int);
double DampedOscillCosExpN(double, double, double, double, double, double, double, int);
double DampedOscillCosNExpN(double, double, double, double, double, double, double, double, int);
double DampedOscillCosNExpNVar4(double, double, double, double, double, double, double, double, int);
double DampedOscillCosNExpNVar2(double, double, double, double, double, double, double, double, int);
double DampedOscillCosNExpNVar3(double, double, double, double, double, double, double, double, double, double, int);
double DampedOscillCosNExpNReff(double, double, double, double, double, double, double, double, int);
double DampedOscillCosNR2N(double, double, double, double, double, double, double, int);
double DampedOscillCosNExp4(double, double, double, double, double, double, double, int);
double DampedOscillCos2ParExp(double, double, double, double, double, double, double, int);
double DampedOscillCos2ParExpVar1(double, double, double, double, double, double, double, int);

double DampedOscillCos2(double, double, double, double, int);
double DampedOscillCosErfExpN(double, double, double, double, double, double, double, double, int);

double DampedOscillExpNExpN(double, double, double, double, double, double, double , double , int);


double DampedOscillErfNExpN(double, double, double, double, double, double, double, double, double, int);
double DampedOscillErfNExpNVar2(double, double, double, double, double, double, double, double, double, int);

double DampedOscillLnNExpN(double, double, double, double, double, double, double, double, int);
double DampedOscillLn_R2(double, double, double, double, double, int);

double Derf1Par(double, double, double, double, int);
double DerfPolyNoPar(double, double, double, double, double, int);

double Derf1ParApprox8Pow(double, double, double, double, double, int);
double Derf1ParApprox8PowReff(double, double, double, double, int);
double Derf1ParApprox8Pow2(double, double, double,  double, double, double, int);


double DshiftedCoulomb(double, double, double, double, double, int);
double DeffCoulomb(double, double, double, double, double, int);
double DeffKE(double, double, double, double, int);
double DeffS(double, double, double, double, int);
double DeffParallel(double, double, int);

double IntExchangePot4Var(double, double, double, double, double, double, double, double, double, int);

double DsimpleExclusion(double, double, double, double, int, int);
double DshiftedExclusion3Par(double, double, double, double, double, double, double, int);
double DshiftedExclusion2ParV2(double, double, double, double, double, int, int, int);
double DexponentialExclusion2Par(double, double, double, double, double, int, int);
double DexponentialExclusion2Par2(double, double, double, double, int, int);
double DexponentialExclusion2Par3(double, double, double,  double, double, int, int);
double DexponentialExclusion3Par(double, double, double, double, double, double, int, int);
double DexponentialExclusion3Par2(double, double, double, double, double, double, int, int);
double D2exponentialExclusion2Par(double, double, double, double, double, double, int);

double DinvExponentialExclusion(double, double, double, double, double,int);
double DinvExpExclApprox5Term(double, double, double, double, double, int);

double DpolyExclusion(double, double, double, double, double, int);
double DpolyExclusionPowNReff(double, double, double, double, double, int,int);
double DpolyExclusion2Par(double, double, double, double, double, double, int);


double DpauliExclusion2d94(double, double, double, double, double, double, int);
double DpauliExclusion2d94Cos(double, double, double, double, double, double, double, int);
double DpauliExclusion88Cos(double, double, double, double, double, double, int);
double DpauliExclusion88CosApprox(double, double, double, double, double, double, int);

double D2simpleExclusion(double, double, double, double, double, int);
double D2exclusion1Par(double, double, double, double, int, int);
double D2exclusion2Par(double, double, double, double, double, int, int, int);
double D2exclusion2ParV2(double, double, double, double, double, int, int);

double DsmoothNCoulomb2Par(double, double, double, double, double, double, int);

double Dsmooth2Coulomb0Par(double, double, double, double, int);
double Dsmooth2Coulomb1Par(double, double, double, double, double, int);
double Dsmooth2Coulomb2Par(double, double, double, double, double, double, int);
double Dsmooth4Coulomb2Par(double, double, double, double, double, double, int);

double Dsmooth8Coulomb1Par(double, double, double, double, double, int);
double Dsmooth16Coulomb1Par(double, double, double, double, double, int);
double Dsmooth32Coulomb1Par(double, double, double, double, double, int);
double Dsmooth8CoulombPcore2Par(double, double, double, double, double, double, double, int);

double Dsmooth16Coulomb3Par(double, double, double, double, double, double, double, int);
double Dsmooth6Coulomb2Par(double, double, double, double, double, double, int);

double Dsmooth8Coulomb3Par(double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb3ParVar2(double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb2Par(double, double, double, double, double, double, int);
double Dsmooth8Coulomb2ParVar12( double, double, double, double, double, int);
double Dsmooth8Coulomb2ParVar13( double, double, double, double, double, int);
double Dsmooth8Coulomb2ParVar23( double, double, double, double, double, int);

double Dsmooth8Coulomb4ParReff(double, double, double,double,double,double,double,double,int);
double Dsmooth8Coulomb3ParVariant1(double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb3ParVariant2(double, double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb4ParVariant1(double, double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb4ParVariant2(double, double, double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb4ParVariant3(double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb4ParVariant4(double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb4Par(double, double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb4ParC(double, double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb5ParVariant2(double, double, double, double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb5Par(double, double, double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb6Par(double, double, double, double, double, double, double, double, double, double, int);
double Dsmooth8Coulomb5ParVariant1(double, double, double, double, double, double, double, double, double, int);
double Dnonmono8Coulomb5Par(double, double, double, double, double, double, double, double, double, int);
double Dnonmono8Coulomb5ParVariant1(double, double, double, double, double, double, double, double, double, double, double, int);
double Dnonmono8Coulomb6Par(double, double, double, double, double, double, double, double, double, double, int);
double nonmono2Coulomb3Par(double, double, double, double, double, double, int);
double nonmono2Coulomb3ParVariant1(double, double, double, double, double, double, int);
double nonmono4Coulomb3Par(double, double, double, double, double, double, int);
double nonmono4Coulomb5Par(double, double, double, double, double, double, double, double, int);
double nonmono8Coulomb5Par(double, double, double, double, double, double, double, double, int);
double nonmono8Coulomb5ParVariant1(double, double, double, double, double, double, double, double, int);
double nonmono8Coulomb6Par(double, double, double, double, double, double, double, double, double, int);
double shiftedCoulomb(double, double, double, double, int);
double root2Coulomb1Par(double, double, double, double, int);
double smoothCoulomb2Par(double, double, double, double, double, int);
double smooth2Coulomb1Par(double, double, double, double, int);
double smooth2Coulomb2Par(double, double, double, double, double, int);
double smooth2Coulomb2ParVariant1(double, double, double, double, double, int);
double smooth4Coulomb1Par(double, double, double, double, int);
double smooth4Coulomb2Par(double, double, double, double, double, int);
double smooth4Coulomb2ParVariant1(double, double, double, double, double, int);
double smooth4Coulomb2ParVariant2(double, double, double, double, double, int);
double smooth8Coulomb2Par(double, double, double, double, double, int);
double smooth8Coulomb2ParVariant1(double, double, double, double, double, int);
double smooth8Coulomb2ParVariant2(double, double, double, double, double, int);
double smooth8Coulomb2ParVariant3(double, double, double, double, double, int);
double smooth8Coulomb2ParVariant4(double, double, double, double, double, int);
double smooth8Coulomb3Par(double, double, double, double, double, double, int);
double smooth8Coulomb3ParVariant1(double, double, double, double, double, double, int);
double smooth8Coulomb3ParVariant2(double, double, double, double, double, double, int);
double smooth8Coulomb3ParVariant3(double, double, double, double, double, double, int);
double smooth8Coulomb4Par(double, double, double, double, double, double, double, int);
double smooth8Coulomb4ParVariant1(double, double, double, double, double, double, double, int);
double smooth8Coulomb4ParVariant2(double, double, double, double, double, double, double, int);
double smooth16Coulomb3Par(double, double, double, double, double, double, int);
double smooth16Coulomb4Par(double, double, double, double, double, double, double, int);
double simpleExclusion(double, double, double, int, int);
double simpleExclusionHalfNeu(double, double, double, int, int);
double shiftedExclusion(double, double, double, double, int, int);

double shiftedExclusion2(double, double, double, double, double, int);

double shiftedExclusionVariant1(double, double, double, double, double, int, int, int);
double shiftedExclusionHalfNeu(double, double, double, double, int, int);
double shiftedExclusionHalfNeuVariant1(double, double, double, double, int, int);
double shiftedExclusionHalfNeuVariant2(double, double, double, double, int, int, int);
double shiftedExclusionHalfNeuVariant3(double, double, double, double, double, int, int, int);
double shiftedSmoothExclusion(double, double, double, double, int, int);
double shiftedSmoothExclusionHalfNeu(double, double, double, double, int, int);
double exponentMimicExclusion1(double, double, double, double, int);
double exponentMimicExclusion2(double, double, double, double, int);
double exponentMimicExclusion3(double, double, double, double, int);
double exponentMimicExclusion4(double, double, double, double, int);
double exponentMimicExclusion5(double, double, double, double, double, int);
double exponentMimicExclusion6(double, double, double, double, double, int);
double exponentialExclusion(double, double, double, double, int);
double exponentialPowerExclusion(double, double, double, double, int, int);
double softDispersion(double, double, double, double, int, int, int, int);
//================================================================================================
double shiftedsum(double, double, double);
double shiftedgeo(double, double, double);
double shiftedgeo2par(double, double, double, double);
double shiftedgeo2(double, double, double);
double shiftedgeo3(double, double, double);
double geo2par(double, double, double, double);
double sqsum(double,double,double);
double InvSqSumInv(double, double);
double complex BoysF0(double complex);
double FAA4(double, double);
double FAA8(double, double);
double FAA83Par(double, double, double, double);
double FAA62Par(double, double, double);
double InvPoly8Par142(double, double, double,double,double,double,double,double,int);

//Routine operational functions===================================================================
int maxi(int, int);
int mini(int, int);
double maxi_float(double, double);
double deff(double, double, double, double);
double getPower(double, double);
void exitEnergy(int, int);
//================================================================================================
//1-body  functions===============================================================================
double K(double complex a);
//2-body  functions===============================================================================
double complex * R_ab(double complex a, double r_a[3], double complex b, double r_b[3]);
double Omega(double complex a, double r_a[3], double complex b, double r_b[3]);
double Delta_K(double complex a, double r_a[3], double complex b, double r_b[3]);
double U(double complex a, double r_a[3], double R_X[3]);
double M(double complex a, double r_a[3], double complex b, double r_b[3]);
double Delta_M(double complex a, double r_a[3], double complex b, double r_b[3]);
//3-body  functions===============================================================================
double complex Delta_U(double complex a, double r_a[3], double complex b, double r_b[3], double R_X[3]);
double Delta_C(double complex a, double r_a[3], double complex b, double r_b[3], double complex c, double R_X[3]);
