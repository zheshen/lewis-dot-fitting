/*
 *  interactions.c
 *  		
 *  by Seyit Kale
 *  Sept 23, 2009
 *
 */

#include "Energy.h"

/*
//Individual interactions=====================================================================
double formOfKE_split(double e_const, double dij, double p1, double p2, int E_or_F, double * items){
	double u=0;

//	u = shiftedKE(e_const, dij, p1, p2, E_or_F);
//	u = scaledKE(e_const, dij, p1, E_or_F);
	u = simpleKE(e_const, dij, E_or_F, items);
//	u = 0.0;
	*items += u;	
	return u;
}

double formOfAAX_split(double r2, double r, double Rn2, double Rn, double Ri2, double Rj2, double Nx, double Ny, double Nz, double ix, double iy, double iz, double jx, double jy, double jz, double d1, double d2, double q, double s, double pAB2, double pAB7, double pAB10, double pAB11, double pAB12, double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10, double p11, double p12, double p13, int n1, int n2, int E_or_F, double * items){
	double u=0;
	double uA=0;
	double uN=0;
	double rexK=0;
	double rexK2=0;
	double RexX=0;
	double RexX2=0;
	double rexA=0;
	double rexA2=0;
	double dexK=0;
	double dexR=0;
	double dexX=0;
	double dexA=0;
	double zN;
//	double Ri = 0;
//	double Rj = 0;
	dexK = geo2par((pAB11+pAB10)*d1,(pAB11+pAB10)*d2,0.0,0.0);
//	dR = geo2par(pAB12*d1,pAB12*d2,0.0,0.0);
	rexK = r/dexK;
	rexK2 = rexK*rexK;
	dexX = p10 * InvSqSumInv(d1,d2);
	RexX = Rn/dexX;
	RexX2 = RexX*RexX;
	dexA = geo2par(pAB10*d1,pAB10*d2,0.0,0.0);
	rexA = r/dexA;
	rexA2 = rexA*rexA;
//	double dexA, dexK, rexK, rexR, rexA;
//	dexA = 1/sqrt(1/d1/d1+1/d2/d2);
//	dexK = sqrt((d1*d1+d2*d2)/2);
//	rexK = r*pAB11/dexK;
//	rexR = r*(pAB11+pAB12)/dexK;
//	rexA = r*(pAB10+pAB11)/dexK;

//	double r_x, r_y, r_z, RN_x, RN_y, RN_z, c;
//	r_x = jx - ix;
//	r_y = jy - iy;
//	r_z = jz - iz;
//	RN_x = 0.5*(ix+jx)-Nx;
//	RN_y = 0.5*(iy+jy)-Ny;
//	RN_z = 0.5*(iz+jz)-Nz;
//	c = 3*(r_x*(RN_x+0.0000001)+r_y*(RN_y+0.0000001)+r_z*(RN_z+0.0000001))*(r_x*(RN_x+0.0000001)+r_y*(RN_y+0.0000001)+r_z*(RN_z+0.0000001))/(r_x*r_x+r_y*r_y+r_z*r_z)/((RN_x+0.0000001)*(RN_x+0.0000001)+(RN_y+0.0000001)*(RN_y+0.0000001)+(RN_z+0.0000001)*(RN_z+0.0000001));

//	double RN, RexX1, RexX2;
//	RN = sqrt(RN_x*RN_x+RN_y*RN_y+RN_z*RN_z);
//	RexX1 = RN*p10/dexK;
//	RexX2 = RN*(p10+p11)/dexK;
	zN = s;
        uA = dexA*dexA/(6*rootpi)/(1+p7*rexA2+p8*rexA2*rexA2+p9*rexA2*rexA2*rexA2*rexA2);
        uN = zN*exp(-0.55*RexX2)/(dexX*dexX*dexX);
        u = p6*uA*uN;

//	extern int diagnose_print;
//	if (diagnose_print == 1)
//		printf("AAX r %f, uA %f, uN %f, rab_N2 %f, Ri2 %f, Rj2 %f, p1 %f, p2 %f, p13 %f, beta2 %f, betaa2 %f, betab2 %f, betaab2 %f, F0abN %f, F0aN %f, F0bN %f\n", r, uA, uN, rabN2, Ri2, Rj2, p1, p2, p13,  beta2, betaa2, betab2, betaab2, FAAN_abN, FAAN_aN, FAAN_bN);
	*(items+5) += u;
	return u;
}
*/

double formOfAA_split(V *a, V *b, double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10, double p11, double p12, double p13, int n1, int n2, int n3, int E_or_F, double * items){


	double uAB=0;
	double u=0;
	double uexK;
	double uexR;
	double r_a[3], r_b[3];
	double complex d_a, d_b;
	d_a = a->d;
	d_b = b->d;
	r_a[0] = a->x;
	r_a[1] = a->y;
	r_a[2] = a->z;
	r_b[0] = b->x;
	r_b[1] = b->y;
	r_b[2] = b->z;
	double Rhat, Ihat;
	Rhat = 0.5*(creal(d_a)+creal(d_b));
	Ihat = 0.5*(cimag(d_a)*cimag(d_a)/creal(d_a)+cimag(d_b)*cimag(d_b)/creal(d_b));
	double r2, r, Rn2, Rn;
	r2 = (r_a[0]-r_b[0])*(r_a[0]-r_b[0]) + (r_a[1]-r_b[1])*(r_a[1]-r_b[1]) + (r_a[2]-r_b[2])*(r_a[2]-r_b[2]);
	r = sqrt(r2);
	double deff, reff;
	deff = p1*sqrt(1.0/Rhat);
	reff = r/deff;
	
//	uexK = E_const/Omega(d_a, r_a, d_b, r_b)*Delta_K(d_a, r_a, d_b, r_b);
//	uexR = E2_const/Omega(d_a, r_a, d_b, r_b)*Delta_M(d_a, r_a, d_b, r_b);
//	uAB = E2_const*M(d_a, r_a, d_b, r_b);	
	uexK = E_const*p7*(Rhat+Ihat)*exp(-0.6*p11*(Rhat+Ihat)*r2);
	uexR = -E2_const*2.0/rootpi*p8*sqrt(Rhat)*exp(-p12*Rhat*r2);
	uAB = E2_const/deff/sqrt(reff*reff+p2*reff+1.0);
        u = uAB + uexK + uexR;

	extern int diagnose_print;
	//diagnose_print = 1;
	if (diagnose_print == 1)
		printf("AA r %f, omega %f, d_a %f+%fI, d_b %f+%fI, uexK %f, uexR %f, uAB %f, u %f\n", r, Omega(d_a, r_a, d_b, r_b), creal(d_a), cimag(d_a), creal(d_b), cimag(d_b), uexK, uexR, uAB, u);

	*(items+2) += uAB;                       
 	*(items+3) += uexK;
	*(items+4) += uexR;

//	extern int diagnose_print;     
//	DIagnose_print = 1;                   
//	if (diagnose_print ==1)
//		printf("AA r %f miu %f omega %f uAB %f uK %f B1 %f B2 %f uR %f \n", r, miu, omega, uAB,  uK, B1, B2, uR );        
//	diagnose_print = 0;

        return u;
}



double formOfAB_split(V *a, V *b, double p1, double p2, double p3, double p4, double p5, double p6, double p13, int n1, int n2, int n3, int E_or_F, double *items){
	double u;
	u = formOfAB(a, b, p1, p2, p3, p4, p5, p6, p13, n1, n2, n3, E_or_F);
	*(items+1) += u;	

	return u;
}

/*
double formOfAV(double r2, double r, double dij, double q, double p1, double p2, double p3, double p4, \
        double p5, double p6, int n1, int n2, int n3, int E_or_F){

        double u = 0;
//        u  = smooth8Coulomb2ParVariant4(r2, r, q, p1, p2, E_or_F);
//        u += shiftedExclusion(r2, r, p3, p4, n1, E_or_F)*0.5; 
  

        return u;
}


double formOfAH(double r2, double r, double d1, double d2, double q, double p1, double p2, double p3, double p4, \
        double p5, double p6, double p13, int n1, int n2, int E_or_F){
//printf("p1 %f, p2 %f, p3 %f, p4 %f, p5 %f, p6 %f\n", p1, p2 ,p3,p4,p5,p6);
//extern int diagnose_print;
        double u = 0;
//	double d = 0;
	//double root2=1.4142135;
	double beta2 = 0;
	double beta = 0;
//	d = shiftedgeo2(p4*d1,p4*d2,p5);
//	d = shiftedsum(p4*d1, p4*d2, p5);
//	d = geo2par(p4*d1,p4*d2,p5,p6);
	beta2 = 2/(p1*p1)/(d1*d1+2*d1*p2*p13+p2*p2);
	beta = sqrt(beta2);

        double reff = 0;
        double reff2= 0;
        reff= beta*r;
        reff2 = reff * reff;

//        u  = Dsmooth4Coulomb2Par(r2, r, d, q, p1, p2, E_or_F);
//	u = DshiftedCoulomb(r2, r, d, q, p2, E_or_F);
//	u = Dsmooth2Coulomb1Par(r2, r, d, q, p2, E_or_F);
//	u = simpleCoulomb(r2, r, q, E_or_F);
//	u = Derf1ParApprox8Pow(r2, r, d, q, 1/root2,E_or_F);

	double F  = FAA62Par(reff2, p3, p4);
	u = F * q * beta * 2 /rootpi;

//        u = Dsmooth8Coulomb3ParVar2(r2, r, d, q, p1, p3, p4, E_or_F);
//	if (r==0)
//		u = q/d;
//	else
//		u = (q/r) * erf(0.8862269254527580*reff);
//if (diagnose_print ==1)
//	printf("AH r %f uAH %f\n", r, u);        


        return u;
}
*/
double formOfXA_split(V *a, V *R, double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10, double p11, double p12, double p13, int n1, int n2, int n3, int E_or_F, double *items){

        double u = 0;
	double ucore = 0;
	double uex = 0;
	double r_a[3], R_X[3];
	double complex d, d_a, d_X, d_c;
	double q;
	int s;
	d_a = a->d;
	d_X = R->d;
	r_a[0] = a->x;
	r_a[1] = a->y;
	r_a[2] = a->z;
	R_X[0] = R->x;
	R_X[1] = R->y;
	R_X[2] = R->z;
	q = abs(R->q * a->q);
//	printf("Rq = %f, aq = %f, q = %f\n", R->q, a->q, q);
	s = R->s;
	if ((s == 2) || (s==-2)) 
		return formOfXA(R, a, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F);
	d_c = p2 + p3*I;
	
	double r2, r, Rn2, Rn;
	r2 = (r_a[0]-R_X[0])*(r_a[0]-R_X[0]) + (r_a[1]-R_X[1])*(r_a[1]-R_X[1]) + (r_a[2]-R_X[2])*(r_a[2]-R_X[2]);
	r = sqrt(r2);
	double deff1, reff1, deff2, reff2;
	deff1 = p1*sqrt(1.0/creal(d_a));
	reff1 = r/deff1;
	deff2 = p1*sqrt(1.0/creal(d_a)+p2*p2);
	reff2 = r/deff2;
//	if ((d_a == 0)) {
//		d = d_a;
//		d_a = d_X;
//		d_X = d;
//	}

//	ucore = E2_const*(-1.0*s*U(d_a, r_a, R_X) + (s-q)*M(d_a, r_a, d_c, R_X));
	ucore = E2_const*(-1.0*s/deff1/sqrt(sqrt(reff1*reff1*reff1*reff1+p3*reff1*reff1+1.0)) + (s-q)/deff2/sqrt(sqrt(reff2*reff2*reff2*reff2+p3*reff2*reff2+1.0)));
//	printf("2Rq = %f, aq = %f, q = %f\n", R->q, a->q, q);
//	uex = (s-q)/2.0/Omega(d_a, r_a, d_c, R_X) * (E_const/2.0*Delta_K(d_a, r_a, d_c, R_X) + E2_const*Delta_M(d_a, r_a, d_c, R_X) - E2_const*s/2.0*Delta_U(d_a, r_a, d_c, R_X, R_X));
//	uex = E2_const*(s-q)/2.0*2.0/rootpi*p8*sqrt(conj(d_a)+d_a)*exp(1.0*p9*(conj(d_a)-d_a)*(conj(d_a)-d_a)/2.0/(conj(d_a)+d_a)*r2);
	uex = E2_const*p8*sqrt(creal(d_a))*exp(-p9*cimag(d_a)*cimag(d_a)/creal(d_a)*r2);
//	printf("3Rq = %f, aq = %f, q = %f\n", R->q, a->q, q);
	u = ucore + uex;

	*(items+6) += ucore;
	*(items+7) += uex;

	return u;
//printf("p1 %f, p2 %f, p3 %f, p4 %f, p5 %f, p6 %f, p13 %f\n", p1, p2 ,p3,p4,p5,p6,p13);
//        double u = 0;
//	u = formOfXA(a, R, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F);
//	*(items+6) += u;
//        return u;

}

/*
double formOfVV(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	double p5, double p6, int n1, int n2, int n3, int E_or_F){
	
	double u = 0;
//	u  = smooth8Coulomb4ParVariant1(r2, r, q, p1, p2, p3, p4, E_or_F);
//	u  = smooth8Coulomb2ParVariant4(r2, r, q, p1, p2, E_or_F);
//	u += shiftedExclusion(r2, r, p3, p4, n1, E_or_F);
}

double formOfVH(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int E_or_F){
	
        double u = 0;
//	u  = smooth8Coulomb4ParVariant1(r2, r, q, p1, p2, p3, p4, E_or_F);
        return u;
}

double formOfXV(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int n3, int E_or_F){
	
	double u = 0;
//        u  = smooth8Coulomb3ParVariant3(r2, r, q, p1, p2, p3, E_or_F);
//        u += simpleExclusion(r2, r, p4, n1, E_or_F);
        return u;
}

double formOfHH(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int E_or_F){
	
        double u = 0;

	  u  = simpleCoulomb(r2, r, q, E_or_F);

//	  u = superCoulomb(r2, r, q, p1, E_or_F);


//	  u -= shiftedExclusionVariant1(r2, r, p1, p2, p3, n1, n2, E_or_F);


//          u -= DexponentialExclusion2Par2(r2, r, p1, p2, n1, E_or_F);

//	  u -= shiftedExclusion(r2,r,p1,p2,n1,E_or_F);


//	  u -= DexponentialExclusion2Par2(r2, r, p1, p2, n1, E_or_F);
//	  u -= DexponentialExclusion2Par(r2, r, 1.0, p1, p2, n1, E_or_F);
//	  u  = shiftedCoulomb(r2, r, q, p1, E_or_F);
//	  u -= shiftedExclusionVariant1(r2, r, p1, p2, p3, n1, n2, E_or_F);
//	  u  = smooth4Coulomb2Par(r2, r, q, p1, p2, E_or_F);
//	  u  = smooth4Coulomb1Par(r2, r, q, p1, E_or_F);
//	  u  = smooth2Coulomb2ParVariant1(r2, r, q, p1, p2, E_or_F);
////	  u  = smoothCoulomb2Par(r2, r, q, p1,p2, E_or_F);
//	  u  = smooth8Coulomb4ParVariant1(r2, r, q, p1, p2, p3, p4, E_or_F);
//        u  = simpleCoulomb(r2, r, q, E_or_F);
        return u;
}

double formOfXH_split(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int n3, int n4, int E_or_F){
	
        double u = 0;
//	u  = simpleCoulomb(r2, r, q, E_or_F);
//        u -= DexponentialExclusion2Par(r2, r, 1.0, p1, p2, n1, E_or_F);

//	u -= shiftedExclusionVariant1(r2, r, p1, p2, p3, n1, n2, E_or_F);
        return u;
}

double formOfXY(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int n3, int n4, int E_or_Fi, double * items){
	
        double u = 0;
	double secondterm = 1 + p1*pow(r/p2, (double)n1) + pow(r/p2, (double)n2);
	secondterm = p3/secondterm;	
//	u = q/r - secondterm;;
//	u = q/r;
	u = simpleCoulomb(r2, r, q, E_or_F) - secondterm;
//	return 0.0;
//extern int diagnose_print;
//if(diagnose_print==1)
//	printf("r %f, p2 rho %f, p3 kap %f, p1 tau %f, n1 %d, n2 %d, 2ndterm %f, u %f\n", r, p2, p3, p1, n1, n2, secondterm, u);
	*(items+7) += u;
        return u;

}


double formOfMV(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int E_or_F){
	
        double u = 0;
        u  = simpleCoulomb(r2, r, q, E_or_F);
        return u;
}

double formOfMH(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int E_or_F){
	
        double u = 0;
        u  = simpleCoulomb(r2, r, q, E_or_F);
        return u;
}

double formOfXM(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int n3, int n4, int E_or_F){
	
        double u = 0;
	u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
        return u;
}

double formOfMM(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int n3, int n4, int E_or_F){
	
        double u = 0;
	u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
        return u;
}

//============================================================================================
*/
