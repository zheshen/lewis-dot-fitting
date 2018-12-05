/*
 *  interactions.c
 *  		
 *  by Seyit Kale
 *  Sept 23, 2009
 *
 */

#include "Energy.h"

//Individual interactions=====================================================================
double formOfKE(double e_const, double complex d, double eta, double zeta, double k, double tau1, double tau2, int E_or_F, double *items){
	double u=0;
//	u = shiftedKE(e_const, dij, p1, p2, E_or_F);
//	u = scaledKE(e_const, dij, p1, E_or_F);
	u = scaledKE_complex(e_const, d, eta, zeta, k, tau1, tau2, E_or_F);
//	u = simpleKE(e_const, dij, E_or_F);
//	u = 0.0;	
//	u = e_const * K(a, r_a);
	if (items != NULL)
	items[0] += u;
	return u;
}

//UexA formula
double formOfAAX(V *a, V *b, V *R, double r2, double Rn2, double pAB2, double pAB5, double pAB6, double pAB7, double pAB8, double pAB9, double pAB10, double pAB11, double pAB12, double pAB20, double pAB21, double pAB22, double pAB23, double pAB24, double pAB25, double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10, double p11, double p12, double p13, int n1, int n2, int E_or_F, double *items){
	double u=0;
	double uA=0;
	double uN=0;
	double uexA=0;
	double uexR=0;
	double r_a[3], r_b[3], R_X[3];
	double complex d_a, d_b;
	double q;
	int s;
	d_a = a->d;
	d_b = b->d;
	r_a[0] = a->x;
	r_a[1] = a->y;
	r_a[2] = a->z;
	r_b[0] = b->x;
	r_b[1] = b->y;
	r_b[2] = b->z;
	R_X[0] = R->x;
	R_X[1] = R->y;
	R_X[2] = R->z;
	double unitVector[3] = {0.000001, 0.000001, 0.000001};
	double Rhat, Rbar;
	double Eta_a, Eta_b;
	q = R->q;
	s = R->s;
	if (q == -1) uexA = 0.0;
	else{
		Rhat = 0.5*(creal(d_a)+creal(d_b));
		Rbar = creal(d_a)*creal(d_b)/(creal(d_a)+creal(d_b));
//		Ihat = 0.5*(cimag(d_a)*cimag(d_a)/creal(d_a)+cimag(d_b)*cimag(d_b)/creal(d_b));
		Eta_a = a->eta;
		Eta_b = b->eta;
		double rr[3];
		rr[0] = r_a[0] - r_b[0]; rr[1] = r_a[1] - r_b[1]; rr[2] = r_a[2]-r_b[2];
		r2 = rr[0]*rr[0] + rr[1] * rr[1] + rr[2] * rr[2];
		double r_m[3];
		r_m[0] = 0.5*(r_a[0]+r_b[0]);
		r_m[1] = 0.5*(r_a[1]+r_b[1]);
		r_m[2] = 0.5*(r_a[2]+r_b[2]);
		double Rnn[3];
		Rnn[0] = r_m[0]-R_X[0]; Rnn[1] = r_m[1]-R_X[1]; Rnn[2] = r_m[2]-R_X[2]; 
//		//Rn2 = (r_m[0]-R_X[0])*(r_m[0]-R_X[0]) + (r_m[1]-R_X[1])*(r_m[1]-R_X[1]) + (r_m[2]-R_X[2])*(r_m[2]-R_X[2]);
//		Rn2 = Rnn[0]*Rnn[0] + Rnn[1]*Rnn[1] + Rnn[2]*Rnn[2];
//		Rn = sqrt(Rn2);
//
		double RnUV[3];//adding unitvector to prevent donominator from going to zero, whole block newly added in DE5045 
		for (int ii = 0; ii < 3; ii++){
			RnUV[ii] = Rnn[ii] + unitVector[ii];
		}
		double RnUV2 = RnUV[0]*RnUV[0] + RnUV[1]*RnUV[1] + RnUV[2]*RnUV[2];
		double rDotR = rr[0]*RnUV[0] + rr[1]*RnUV[1] + rr[2]*RnUV[2];	
		double rAbsR = r2*RnUV2;
		double C = 3.0 * rDotR*rDotR / rAbsR;
		
		double anglePart = 1 + sin(pi / 2 + pi * C);//newly added in DE5045
		uA = E2_const*2.0/rootpi*pAB20*sqrt(2*Rhat)*exp(-pAB21*Rbar*r2)*exp(-pAB24*(Eta_a+Eta_b));
//		uN = p6*q*sqrt(2.0*Rhat)*anglePart/((1+p10*2.0*Rhat*Rn2)+(p11*Ihat*r2))
		uN = q * ((1-C) * exp(-pAB22 * 2*Rhat * Rn2)+ C * exp(-pAB22 * (1.0+pAB23) * 2*Rhat * Rn2)) ;
		uexA = uA*uN;
	}
//	uexA = -E2_const/Omega(d_a, r_a, d_b, r_b)*q*Delta_U(d_a, r_a, d_b, r_b, R_X);
//	uexR = E2_const/Omega(d_a, r_a, d_b, r_b)*(s-q)*Delta_C(d_a, r_a, d_b, r_b, p2, R_X);
//	uexA = uA*q;
        u = uexA;

//	extern int diagnose_print;
//	double r2, r;
//	r2 = (r_a[0]-r_b[0])*(r_a[0]-r_b[0]) + (r_a[1]-r_b[1])*(r_a[1]-r_b[1]) + (r_a[2]-r_b[2])*(r_a[2]-r_b[2]);
//	r = sqrt(r2);
//	diagnose_print = 1;
//	if (diagnose_print == 1)
//		printf("AAX r %f, omega %f, d_a %f+%fI, d_b %f+%fI, uexA %f, uexR %f, u %f\n", r, Omega(d_a, r_a, d_b, r_b), creal(d_a), cimag(d_a), creal(d_b), cimag(d_b), uexA, uexR, u);
//	diagnose_print = 0;
 
//	extern int diagnose_print;
//	diagnose_print = 1;
//	if (diagnose_print == 1)
//		printf("AAX r %f, dr1 %f, di1 %f, miu %f, omega %f, RaN2 %f, uA %f\n", r, dr1, di1, miu, omega, RaN2, uA);
//	diagnose_print = 0;
	if (items != NULL)
	items[5] += u;
	return u;
}

//UexK and UexR and U_AB
double formOfAA(V *a, V *b, double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10, double p11, double p12, double p13, double p14, double p15, double p16, double p17, double p18, double p19, double p20, double p21, double p22, double p23, double p24, double p25, double p26, int n1, int n2, int n3, int E_or_F, double *items){

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
	double Rhat, Rbar;
	double Eta_a, Eta_b;
	double Zeta_a, Zeta_b;
	Rhat = 0.5*(creal(d_a)+creal(d_b));
	Rbar = creal(d_a)*creal(d_b)/(creal(d_a)+creal(d_b));
//	Ihat = 0.5*(cimag(d_a)*cimag(d_a)/creal(d_a)+cimag(d_b)*cimag(d_b)/creal(d_b));
	Eta_a = a->eta;
	Eta_b = b->eta;
	Zeta_a = a->zeta;
	Zeta_b = b->zeta;
	double r2, r, Rn2, Rn;
	r2 = (r_a[0]-r_b[0])*(r_a[0]-r_b[0]) + (r_a[1]-r_b[1])*(r_a[1]-r_b[1]) + (r_a[2]-r_b[2])*(r_a[2]-r_b[2]);
	r = sqrt(r2);
	double deff, reff, reff2;
	deff = p1*sqrt(1.0/Rbar);
	reff = r/deff;
	reff2 = reff*reff;
	double q;
	q = a->q * b->q;
	
//	uexK = E_const/Omega(d_a, r_a, d_b, r_b)*Delta_K(d_a, r_a, d_b, r_b);
//	uexR = E2_const/Omega(d_a, r_a, d_b, r_b)*Delta_M(d_a, r_a, d_b, r_b);
//	uAB = E2_const*M(d_a, r_a, d_b, r_b);	
	uexK = E_const*p14*Rbar*exp(-p15*Rbar*r2)*exp(-p16*(Eta_a+Eta_b));
	uexR = -E2_const*2.0/rootpi*p17*sqrt(Rbar)*exp(-p18*Rbar*r2)*exp(-p19*(Eta_a+Eta_b));
//	uAB = E2_const/deff/sqrt(reff*reff+p3*reff+1.0);
//	uAB = E2_const*Dsmooth8Coulomb4ParReff(reff2,reff,deff,q,p3,p4,p5,1.0,E_or_F);
	uAB = E2_const*InvPoly8Par142(reff2,reff,deff,q,p3,p4,p5,1.0,E_or_F);

        u = uAB + uexK + uexR;

//	extern int diagnose_print;
	//diagnose_print = 1;
//	if (diagnose_print == 1)
//		printf("AA r %f, omega %f, d_a %f+%fI, d_b %f+%fI, uexK %f, uexR %f, uAB %f, u %f\n", r, Omega(d_a, r_a, d_b, r_b), creal(d_a), cimag(d_a), creal(d_b), cimag(d_b), uexK, uexR, uAB, u);
	//diagnose_print = 0;
 
//	extern int diagnose_print;     
//	DIagnose_print = 1;                   
//	if (diagnose_print ==1)
//		printf("AA r %f miu %f omega %f uAB %f uK %f B1 %f B2 %f uR %f \n", r, miu, omega, uAB,  uK, B1, B2, uR );        
//	diagnose_print = 0;

	if (items != NULL){
		items[2] += uAB;
		items[3] += uexK;
		items[4] += uexR;
	}
        return u;
}

double formOfAB(V *a, V *b, double p1, double p2, double p3, double p4, \
       double p5, double p6, double p13, int n1, int n2, int n3, int E_or_F, double *items){

//printf("p1 %f, p2 %f, p3 %f, p4 %f, p5 %f, p6 %f, p13 %f\n", p1, p2 ,p3,p4,p5,p6,p13);

	double u=0;
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
	double Rhat, Rbar, Ihat;
	Rhat = 0.5*(creal(d_a)+creal(d_b));
	Rbar = creal(d_a)*creal(d_b)/(creal(d_a)+creal(d_b));
	Ihat = 0.5*(cimag(d_a)*cimag(d_a)/creal(d_a)+cimag(d_b)*cimag(d_b)/creal(d_b));
	double r2, r, Rn2, Rn;
	r2 = (r_a[0]-r_b[0])*(r_a[0]-r_b[0]) + (r_a[1]-r_b[1])*(r_a[1]-r_b[1]) + (r_a[2]-r_b[2])*(r_a[2]-r_b[2]);
	r = sqrt(r2);
	double deff, reff, reff2;
	deff = p1*sqrt(1.0/Rbar);
	reff = r/deff;
	reff2 = reff*reff;
	double q;
	q = a->q * b->q;
//	u = p1*(1.0/sqrt((2*dr1*dr1)/(dr1+dr1)+r));
//	u = E2_const/deff/sqrt(reff*reff+p3*reff+1.0);
//	u = E2_const*Dsmooth8Coulomb4ParReff(reff2,reff,deff,q,p3,p4,p5,1.0,E_or_F);
	u = E2_const*InvPoly8Par142(reff2,reff,deff,q,p3,p4,p5,1.0,E_or_F);
//	u = E2_const*M(d_a, r_a, d_b, r_b);	
//	u = p1*(2/rootpi*sqrt((2*dr1*dr1)/(dr1+dr1))*BoysF0(2*dr1*dr1/(dr1+dr1)*r2));

//	extern int diagnose_print;     
//	diagnose_print = 1;                   
//	if (diagnose_print ==1)
//		printf("AB r %f  uAB %f \n", r, u );        
//	diagnose_print = 0;

	if (items != NULL)
	items[1] += u;
	return u;
}
double formOfAV(double r2, double r, double dij, double q, double p1, double p2, double p3, double p4, \
        double p5, double p6, int n1, int n2, int n3, int E_or_F, double *items){

        double u = 0;
//        u  = smooth8Coulomb2ParVariant4(r2, r, q, p1, p2, E_or_F);
//        u += shiftedExclusion(r2, r, p3, p4, n1, E_or_F)*0.5; 
  

        return u;
}


double formOfAH(double r2, double r, double d1, double d2, double q, double p1, double p2, double p3, double p4, \
        double p5, double p6, double p13, int n1, int n2, int E_or_F, double *items){
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

double formOfXA(V *a, V *R, double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10, double p11, double p12, double p13, int n1, int n2, int n3, int E_or_F, double *items){


//printf("p1 %f, p2 %f, p3 %f, p4 %f, p5 %f, p6 %f, p13 %f\n", p1, p2 ,p3,p4,p5,p6,p13);
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
//	printf("Rq = %f, aq = %f, q = %f\n", R->q, a->q, q);
	s = R->s;
	if ((s == 2) || (s==-2)) 
		return formOfXA(R, a, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);

	double r2, r, Rn2, Rn;
	r2 = (r_a[0]-R_X[0])*(r_a[0]-R_X[0]) + (r_a[1]-R_X[1])*(r_a[1]-R_X[1]) + (r_a[2]-R_X[2])*(r_a[2]-R_X[2]);
	r = sqrt(r2);
	
	double deff = 0;
	double reff;
	double reff2;
	double Eta_a;
	double Zeta_a;	
	Eta_a = a->eta;
	Zeta_a = a->zeta;
	deff = p1 * (1.0/sqrt(creal(d_a))/sqrt(1.0+p9*Eta_a)+p2/sqrt(1.0+p7*Eta_a));
	reff = r/deff;
	reff2 = reff * reff;

	q = a->q * R->q;
//	if ((d_a == 0)) {
//		d = d_a;
//		d_a = d_X;
//		d_X = d;
//	}

//	ucore = E2_const*(-1.0*s*U(d_a, r_a, R_X) + (s-q)*M(d_a, r_a, d_c, R_X));
//	ucore = E2_const*(-1.0*s/deff1/sqrt(sqrt(reff1*reff1*reff1*reff1+p3*reff1*reff1+1.0)) + (s-q)/deff2/sqrt(sqrt(reff2*reff2*reff2*reff2+p3*reff2*reff2+1.0)));
//	printf("2Rq = %f, aq = %f, q = %f\n", R->q, a->q, q);
//	uex = (s-q)/2.0/Omega(d_a, r_a, d_c, R_X) * (E_const/2.0*Delta_K(d_a, r_a, d_c, R_X) + E2_const*Delta_M(d_a, r_a, d_c, R_X) - E2_const*s/2.0*Delta_U(d_a, r_a, d_c, R_X, R_X));
//	uex = E2_const*(s-q)/2.0*2.0/rootpi*p8*sqrt(conj(d_a)+d_a)*exp(1.0*p9*(conj(d_a)-d_a)*(conj(d_a)-d_a)/2.0/(conj(d_a)+d_a)*r2);
//	ucore = E2_const*Dsmooth8Coulomb4ParReff(reff2,reff,deff,q,p3,p4,p5,1.0,E_or_F); 
	ucore = E2_const*InvPoly8Par142(reff2,reff,deff,q,p3,p4,p5,1.0,E_or_F);
//	uex = E_const*creal(d_a)*p8*exp(-p9*creal(d_a)*creal(d_a)*r2)*exp(-p7*Eta_a);
//	printf("3Rq = %f, aq = %f, q = %f\n", R->q, a->q, q);
	u = ucore + uex;

//	extern int diagnose_print;
//	diagnose_print = 1;
//	if (diagnose_print == 1)
//		printf("AX Delta_M %f, Delta_U %f+%fI, U %f, M %f, r %f, omega %f, d_a %f+%fI, d_c %f+%fI, q %f, s %d, ucore %f, uex %f, u %f\n", Delta_M(d_a, r_a, d_c, R_X), creal(Delta_U(d_a, r_a, d_c, R_X, R_X)), cimag(Delta_U(d_a, r_a, d_c, R_X, R_X)), U(d_a, r_a, R_X), M(d_a, r_a, d_c, R_X), r, Omega(d_a, r_a, d_c, R_X), creal(d_a), cimag(d_a), creal(d_c), cimag(d_c), q, s, ucore, uex, u );
//	diagnose_print = 0;
 

	if (items != NULL){
	items[6] += ucore;
	items[7] += uex;
	}
        return u;
}


double formOfVV(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	double p5, double p6, int n1, int n2, int n3, int E_or_F, double *items){
	
	double u = 0;
//	u  = smooth8Coulomb4ParVariant1(r2, r, q, p1, p2, p3, p4, E_or_F);
//	u  = smooth8Coulomb2ParVariant4(r2, r, q, p1, p2, E_or_F);
//	u += shiftedExclusion(r2, r, p3, p4, n1, E_or_F);
	return u;
}

double formOfVH(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int E_or_F, double *items){
	
        double u = 0;
//	u  = smooth8Coulomb4ParVariant1(r2, r, q, p1, p2, p3, p4, E_or_F);
        return u;
}

double formOfXV(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int n3, int E_or_F, double *items){
	
	double u = 0;
//        u  = smooth8Coulomb3ParVariant3(r2, r, q, p1, p2, p3, E_or_F);
//        u += simpleExclusion(r2, r, p4, n1, E_or_F);
        return u;
}

double formOfHH(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int E_or_F, double *items){
	
        double u = 0;

	u  = simpleCoulomb(r2, r, q, E_or_F);

	if (items != NULL)
	items[8] += u;
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

double formOfXH(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int n3, int n4, int E_or_F, double *items){
	
        double u = 0;
//	u  = simpleCoulomb(r2, r, q, E_or_F);
//        u -= DexponentialExclusion2Par(r2, r, 1.0, p1, p2, n1, E_or_F);

//	u -= shiftedExclusionVariant1(r2, r, p1, p2, p3, n1, n2, E_or_F);
        return u;
}

double formOfXY(double r2, double r, double q, double p1, double p2, double p3, double p4, \
	int n1, int n2, int n3, int n4, int E_or_F, double *items){
	
        double u = 0;
	double secondterm = 1 + p1*pow(r/p2, (double)n1) + pow(r/p2, (double)n2);
	secondterm = p3/secondterm;	
//	u = q/r - secondterm;;
//	u = q/r;
	u = simpleCoulomb(r2, r, q, E_or_F) - secondterm;
	u = 0.0;
	if (items != NULL)
	items[8] += u;
	return u;
//extern int diagnose_print;
//if(diagnose_print==1)
//	printf("r %f, p2 rho %f, p3 kap %f, p1 tau %f, n1 %d, n2 %d, 2ndterm %f, u %f\n", r, p2, p3, p1, n1, n2, secondterm, u);

//        return u;

}

/*
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
}*/

//============================================================================================

