/*
 *  energy_library.c
 *  		
 *  by Seyit Kale
 *  Sept 23, 2009
 *
 */

#include "Energy.h"
//#include "libgammainc.h"
#include "Faddeeva.h"
//extern int E_or_F;
double dawson(double);
C gammainc(double, double);

//Function library - return energies

//KE = 3h^2/(2md^2)============================================================
double simpleKE(double e_const, double d, int E_or_F){

	double d2 = d * d;
	double u = e_const;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) u / d2;
        }
        if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
                return (-2) * e_const / (d2 * d);
        }

	//default
		return 0;
}
//=============================================================================

//KE = (3h^2/(2md^2))*K========================================================
double scaledKE(double e_const, double d, double k, int E_or_F){

        double d2 = d * d;
        double u = e_const * k;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) u / d2;
        }
        if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
                return (-2) * u / (d2 * d);
        }

        //default
                return 0;

}
//=============================================================================

//KE = (3h^2/(2md^2))*K========================================================
double scaledKE_complex(double e_const, double complex d, double eta, double zeta, double k, double tau1, double tau2, int E_or_F){

        double u = e_const * k;

        if (E_or_F == ENERGY){          //ENERGY
//                return (double) u * 3.0 * d * conj(d) / (d + conj(d));
     		return (double) u * 3.0 / 2.0  * (creal(d) * ( 1.0 + tau1*eta ) + tau2*zeta);
        }
        if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
                return 0;
        }

        //default
                return 0;

}
//=============================================================================

//KE = 3h^2/(2md^2)============================================================
double shiftedKE(double e_const, double d, double k, double rho, int E_or_F){

	double d_s = d + rho;
        double d2 = d_s * d_s;
        double u = e_const * k;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) u / d2;
        }
        else {
                return 0;
        }
}
//=============================================================================

//KE = 3h^2/(2md^2)============================================================
double shiftedKEvariant1(double e_const, double d, double k, double rho, int E_or_F){

        double d_s = d - rho;
        double d2 = d_s * d_s;
        double u = e_const * k;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) u / d2;
        }
        else {
                return 0;
        }
}
//=============================================================================

//E = [(2 di dj) / (di2 + dj2)]^N==============================================
double sizeAdjust(double di, double dj, double deff, double N, int E_or_F){

	double num= di * dj * 2.;
	double denom= deff * deff;
	double n= num / denom;
	double u= getPower(n,N);

        if (E_or_F == ENERGY){          //ENERGY
                return u;
        }

        return 0;
}




//E = (h^2/2me)(1/da2)[3(da^4 / dg^4 - 1)+ z^2]==================================
double kineticExchange(double da2, double dag4, double z2, int E_or_F){

	double coeff=h_me * 0.5 / da2;
	double term= 3 * (dag4 -1) + z2;

        if (E_or_F == ENERGY){          //ENERGY
                return coeff * term;
        }

        return 0;
}

//E = (h^2/2me)(1/da2)[3(da^4 / dg^4 - 1)+ z^2]==================================
double kineticExchangeVar2(double da2, double dag4, double z2, double K1, double K2, int E_or_F){

        double coeff=h_me * 0.5 / da2;
        double term1= K1 * 3 * (dag4 -1);
	double term2= K2 * z2;

        if (E_or_F == ENERGY){          //ENERGY
                return coeff * (term1+term2);
        }

        return 0;
}



//E = (d^2 / g^4) - (4/d^2) + (8/3)(r^2/d^4)================================
double kineticTermForExclusion(double r2, double r, double d, double g, int E_or_F){
	double d2 = d * d;
	double d4 = d2 * d2;
	double g2 = g * g;
	double g4 = g2 * g2;
	double d2g4= d2 / g4;
	double r2d4= r2 / d4;
	
        if (E_or_F == ENERGY){          //ENERGY
                return d2g4 - ( 4. /d2 ) + (8. * r2d4 / 3.);
        }

        return 0;
}

//E = (2g^2 / d^2) ^3 exp (-2 r2 /d2)=======================================
double overlapTermForExclusion(double r2, double r, double d, double g, int E_or_F){
	double d2 = d * d;
	double g2 = g * g;
	double gd = 2. * g2 / d2;
	double gd3= gd * gd * gd;
	double c = exp(-2.*r2/d2);

        if (E_or_F == ENERGY){          //ENERGY
                return gd3 * c;
        }

        return 0;
}

//E = (3h2/2m) * X * [ s2 / (1-s2) + (1-2T1) * s2 / (1+s2) ] * k============
double effLikeExclusion(double s2, double k, double X, double T1, int E_or_F){
	double coeff= EkeConst * X;
	double Sn = s2 / (1.-s2);
	double Sp = s2 / (1.+s2);
	double St = Sn + (1.-2.*T1) * Sp;
	
        if (E_or_F == ENERGY){          //ENERGY
		return coeff * St * k;
        }

        return 0;
}

//E = (Xk/Dk2)*{ (3*(gamma2 - 1) + Wk) / (gamma3 exp (Wk) -1) } - (Xr/Dr) { [(2/sqrt(pi)) gamma - erf(sqrt(Wr))/sqrt(Wr)]/(gamma3 exp(Wr) - 1 )}
double IntExchangePot4Var(double r2, double r, double gamma, double Dk2, double Dr2, double Wk, double Wr, double Xk, double Xr, int E_or_F){

	//extern int diagnose_print;

	double Dr = sqrt(Dr2);
	double sqWr = sqrt(Wr);
	double coeff1 = Xk / Dk2;
	double coeff2 = Xr / Dr;
	double gamma2 = gamma * gamma;
	double gamma3 = gamma2 * gamma;
	double gam_3_1 = 3. * (gamma2 - 1.);
	double part1num = gam_3_1 + Wk;
	double part1den = gamma3 * exp(Wk) - 1.;
	double part1 = coeff1 * part1num / part1den;
	double sqpi = 2. / sqrt(pi);
	double sqpiG = sqpi * gamma;
	double erfWr_Wr = erf(sqWr) / sqWr;
	double part2num = sqpiG - erfWr_Wr;
	double part2den = gamma3 * exp(Wr) - 1.;
	double part2 = coeff2 * part2num / part2den;
	double sum = part1 - part2;
	
	/*
	if(diagnose_print)
	{
	printf("coeff1 %f, coeff2 %f, part1 %f, part2 %f, SUM %f\n", coeff1, coeff2, part1, part2, sum);
	}
*/
        if (E_or_F == ENERGY){          //ENERGY
                return sum;
        }

        return 0;
}

//E = X1/d2 exp ( -(r / T1 D1)^2) - X2/d exp (-(r / T2 D2)^2) + X3/d2 exp (-(r / T3 D3)^2)======================
double DexclusionSum3Gaussians(double r2, double r, double D1, double D2, double D3, double X1, double T1, double X2, double T2, double X3, double T3, int E_or_F){
        // extern int diagnose_print;


	double T1D1 = T1 * T1 * D1;
	double T2D2 = T2 * T2 * D2;
	double T3D3 = T3 * T3 * D3;
	double D2_ = sqrt(D2);
	double r2T1D1 = r2 / T1D1;
	double r2T2D2 = r2 / T2D2;
	double r2T3D3 = r2 / T3D3;
	double gauss1 = X1 * exp(-r2T1D1) / D1;
	double gauss2 = X2 * exp(-r2T2D2) / D2_;
	double gauss3 = X3 * exp(-r2T3D3) / D3;
	double sum = gauss1 - gauss2 + gauss3;

	/*
        if(diagnose_print)
        {
        printf("gauss1 %f, gauss2 %f, gauss3 %f, SUM %f\n", gauss1, gauss2, gauss3, sum);
        }
*/
        if (E_or_F == ENERGY){          //ENERGY
                return sum;
        }

        return 0;
}


double DexclusionSum3GaussiansNested(double r2, double r, double d2, double X, double T1, double T2, double T3, double L1, double L2, int E_or_F){

	double T1r2 = T1 * T1 * r2;
	double T2r2 = T2 * T2 * r2;
	double T3r2 = T3 * T3 * r2;
	double T2L1 = T2 * T2 * L1 * L1;
	double T3L2 = T3 * T3 * L2 * L2;
	double a1 = exp(-T1r2);
        double b1 = exp(-T2r2);
        double c1 = exp(-T3r2);
	double b2 = exp(-T2L1);
	double c2 = exp(-T3L2);
	double sum = X * a1 * (b2 - b1) * (c2 - c1) / d2;

        if (E_or_F == ENERGY){          //ENERGY
                return sum;
        }

        return 0;
}

double DexclusionSum3SuperGaussiansNested(double r2, double r, double d2, double X, double T1, double T2, double T3, int E_or_F){

        double T1r2 = T1 * T1 * r2;
	double T1r4 = T1r2 * T1r2;
        double T2r2 = T2 * T2 * r2;
	double T2r4 = T2r2 * T2r2;
        double T3r2 = T3 * T3 * r2;
	double T3r4 = T3r2 * T3r2;
        double a = exp(-T1r4);
        double b = exp(-T2r4);
        double c = exp(-T3r4);
        double sum = X * a * (2.*b - 1) * (2.* c - 1) / d2;

        if (E_or_F == ENERGY){          //ENERGY
                return sum;
        }

        return 0;
}

double DexclusionSumGandSuperGPowN(double r2, double r, double d, double X1, double T1, double X2, double T2, double n1, int E_or_F){

	double d2 = d * d;
	double T1r = r / T1;
	double T2r = r / T2;
	double T1r2 = T1r * T1r;
	double T2r2 = T2r * T2r;
	double T2rN = getPower(T2r2,n1);
	double G = exp(-T1r2);
	double superG = exp(-T2rN);
	double term1 = X1 * G / d2;
	double term2 = X2 * superG / d;
	double sum = term1 - term2;

        if (E_or_F == ENERGY){          //ENERGY
                return sum;
        }

        return 0;
}

double DexclusionSumGPowNandGPowNM(double r2, double r, double d, double X1, double T1, double X2, double T2, double n1, double n2, int E_or_F){

        double d2 = d * d;
        double T1r = r / T1;
        double T2r = r / T2;
        double T1r2 = T1r * T1r;
        double T2r2 = T2r * T2r;
	double T1rN = getPower(T1r2,n1);
        double T2rN = getPower(T2r2,n1+n2);
        double G = exp(-T1rN);
        double superG = exp(-T2rN);
        double term1 = X1 * G / d2;
        double term2 = X2 * superG / d;
        double sum = term1 - term2;

        if (E_or_F == ENERGY){          //ENERGY
                return sum;
        }

        return 0;



}


double DexclusionProd3Lorentzians(double r2, double r, double d2, double X, double T1, double T2, double T3, int E_or_F){


	double T1r = r / T1;
	double T2r = r / T2;
	double T3r = r / T3;
	double T1r2 = T1r * T1r;
        double T2r2 = T2r * T2r;
        double T3r2 = T3r * T3r;
	double T3r6 = T3r2 * T3r2 * T3r2;
	double sT1r2 = 1 - T1r2;
	double sT2r2 = 1 - T2r2;
	double sT3r6 = 1 + T3r6;
	double sum = X * sT1r2 * sT2r2 / sT3r6;


        if (E_or_F == ENERGY){          //ENERGY
                return sum / d2;
        }

        return 0;
}

double DexclusionProd3LorentziansOver8thPow(double r2, double r, double d2, double X, double T1, double T2, double T3, int E_or_F){


        double T1r = r / T1;
        double T2r = r / T2;
        double T3r = r / T3;
        double T1r2 = T1r * T1r;
        double T2r2 = T2r * T2r;
        double T3r2 = T3r * T3r;
        double T3r4 = T3r2 * T3r2;
	double T3r8 = T3r4 * T3r4;
        double sT1r2 = 1 - T1r2;
        double sT2r2 = 1 - T2r2;
        double sT3r8 = 1 + T3r8;
        double sum = X * sT1r2 * sT2r2 / sT3r8;


        if (E_or_F == ENERGY){          //ENERGY
                return sum / d2;
        }

        return 0;
}

//E = erf(r/d)=================================================================
double Derf(double r2, double r, double d, int E_or_F){
        double rd = r /d;
        double u = erf(rd);

        if (E_or_F == ENERGY){          //ENERGY
                return u;
        }

        return 0;
}

//E = erf(Tr/d)=================================================================
double Derf1Par(double r2, double r, double d, double T,int E_or_F){
        double rd = r /d;
	double Trd = T * rd;
        double u = erf(Trd);

        if (E_or_F == ENERGY){          //ENERGY
                return u;
        }

        return 0;
}
//=============================================================================


//E = (q / r ) erf [ (sqrt(pi) / 2 ) reff1 ( 1 + reff2) ]===========================
double DerfPolyNoPar(double r2, double r, double deff1, double deff2, double Q, int E_or_F){
	double r_ = r + 0.00001;
	double reff1 = r_ / deff1;
	double reff2 = r_ / deff2;
	double p1 = 1 + reff2;
	double p2 = reff1 * p1 * rootpi * 0.5;
	double c = erf(p2);

        if (E_or_F == ENERGY){          //ENERGY
                return Q * c / r_;
        }

        return 0;
}
//=============================================================================

	


//E = q/(r8 + C1*K2*d^2*r6 + C2*K4*d^4*r4 + C3*K6*d^6*r2 + C4*K8*d^8)^1/8==========================
double Derf1ParApprox8Pow(double r2, double r, double d, double Q, double T, int E_or_F){
//k is 1/T that goes into the error function

	double K = 1/T;

	const double C1 = 0.0;//1.19692709;
        const double C2 = 1.53791471;//0.02041489;
        const double C3 = 0.99158164;//1.36197802;
        const double C4 = 0.38050426;//0.37946349;
	
        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
	double Kd	= K * d;
	double Kd2	= Kd * Kd;
	double Kd4	= Kd2 * Kd2;
	double Kd6	= Kd2 * Kd4;
	double Kd8	= Kd4 * Kd4;
	double Kd2r6	= Kd2 * r6;
	double Kd4r4	= Kd4 * r4;
	double Kd6r2	= Kd6 * r2;
        double t8       = r8 + C1*Kd2r6 + C2*Kd4r4 + C3*Kd6r2 + C4*Kd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = q/deff'(r8 + C2*reff4 + C3*reff2 + 1)^1/8==========================
double Derf1ParApprox8PowReff(double r2, double r, double d, double Q, int E_or_F){
//k is 1/T that goes into the error function

	//const double k = sqrt(pi)*0.5;
        const double C2 = 2.49317343;//0.02041489;
        const double C3 = 2.04672187;//1.36197802;

	//double d        = d1 * k;
	//double r2	= reff2 / (k * k);
        double r4       = r2 * r2;
        double r8       = r4 * r4;
        double t8       = r8 + C2*r4 + C3*r2 + 1;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / (d*t);
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = q/(r8 + C1*K2*d^2*r6 + C2*K4*d^4*r4 + C3*K6*d^6*r2 + C4*K8*d^8)^1/8==========================
double Derf1ParApprox8Pow2(double r2, double r, double d, double Q, double K, double C,int E_or_F){

//        const double C1 = 0.0;//1.19692709;
        const double C2 = 1.53791471;//0.02041489;
        const double C3 = 0.99158164;//1.36197802;
        const double C4 = 0.38050426;//0.37946349;


	double C1	= C;
        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
        double Kd       = K * d;
        double Kd2      = Kd * Kd;
        double Kd4      = Kd2 * Kd2;
        double Kd6      = Kd2 * Kd4;
        double Kd8      = Kd4 * Kd4;
        double Kd2r6    = Kd2 * r6;
        double Kd4r4    = Kd4 * r4;
        double Kd6r2    = Kd6 * r2;
        double t8       = r8 + C1*Kd2r6 + C2*Kd4r4 + C3*Kd6r2 + C4*Kd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = cos (T1(pi)r/d) ===================================
double DampedOscillCos2(double r2, double r, double d, double T1, int E_or_F){

        double rd  = r / d;
        //double d2  = d * d;
        double rd2 = rd * rd;
        double T1pird2 = T1 * pi * rd2;
        double cosT1 = cos(T1pird2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) cosT1;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================



//E = X * cos (T1(pi)r/d) * exp(-T2 (r/d)^2)===================================
double DampedOscillCosExp(double r2, double r, double d, double X, double T1, double T2, int E_or_F){

	double rd  = r / d;
	double d2  = d * d;
	double rd2 = rd * rd;
	double T1pird = T1 * pi * rd;
	double T2rd2 = T2 * rd2;
	double cosT1 = cos(T1pird);
	double expT2 = exp(-T2rd2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) X*cosT1*expT2/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = X * cos (T1(pi)(r/d)^N) * exp(-T2 (r/d)^2)===================================
double DampedOscillCosExpN(double r2, double r, double d, double X, double T1, double T2, double N, int E_or_F){

        double rd  = r / d;
	double rdN = getPower(rd,N);
        double d2  = d * d;
        double rd2 = rd * rd;
        double T1pirdN = T1 * pi * rdN;
        double T2rd2 = T2 * rd2;
        double cosT1 = cos(T1pirdN);
        double expT2 = exp(-T2rd2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) X*cosT1*expT2/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = X * cos ((pi/2)(T1r/d)^N) * exp(-(T2r/d)^M)===================================
double DampedOscillCosNExpN(double r2, double r, double d, double X, double T1, double T2, double N, double M, int E_or_F){

        double rd  = r / d;
	double d2  = d * d;
	double T1rd = T1*rd;
	double T2rd = T2*rd;
        double rdN = getPower(T1rd,N);
        double rdM = getPower(T2rd,M);
        double pirdN = pi * rdN * 0.5;
        double cosT1 = cos(pirdN);
        double expT2 = exp(-rdM);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) X*cosT1*expT2/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = X * cos ((pi/2)(T1r/d)^N) * exp(-(T2r/d)^M)===================================
double DampedOscillCosNExpNVar4(double r2, double r, double d, double X, double T1, double T2, double N, double M, int E_or_F){

//	printf("parameters are r %f, d %f, X %f, T1 %f, T2 %f, N %f, M %f\n",r,d,X,T1,T2,N,M);
        double rd  = r / d;
//	printf("rd is %f\n",rd);
        double d2  = d * d;
//	printf("d2 is %f\n",d2);
        double T1r = T1*r;
//	printf("T1r is %f\n",T1r);
	double T1rN = getPower(T1r,N*0.5);
//	printf("T1rN is %f\n",T1rN);
	double dN   = getPower(d,N);
//	printf("dN is %f\n",dN);
	double rdN  = T1rN / dN;
//	printf("rdN is %f\n",rdN);
        double T2rd = T2*rd;
//	printf("T2rd is %f\n",T2rd);
        double rdM = getPower(T2rd,M);
//	printf("rdM is %f\n",rdM);
        double pirdN = pi * rdN * 0.5;
//	printf("pirdN is %f\n",pirdN);
        double cosT1 = cos(pirdN);
///	printf("cosT1 is %f\n",cosT1);
        double expT2 = exp(-rdM);
//	printf("expT2 is %f\n",expT2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) X*cosT1*expT2/d2;
		//printf("energy returned is %f\n", X*cosT1*expT2/d2);
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = (3h^2/2m)X * cos ((pi/2)(T1r/d)^N) * exp(-(T2r/d)^M)===================================
double DampedOscillCosNExpNVar2(double r2, double r, double d, double X, double T1, double T2, double N, double M, int E_or_F){

        double rd  = r / d;
        double d2  = d * d;
        double T1rd = T1*rd;
        double T2rd = T2*rd;
        double rdN = getPower(T1rd,N);
        double rdM = getPower(T2rd,M);
        double pirdN = pi * rdN * 0.5;
        double cosT1 = cos(pirdN);
        double expT2 = exp(-rdM);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) EkeConst*X*cosT1*expT2/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================



//E = (3h^2/2m)X * cos ((pi/2)(T1*rd)^N) * exp(-(T2*rd)^M)===================================
double DampedOscillCosNExpNReff(double r2, double r, double d, double X, double T1, double T2, double N, double M, int E_or_F){

        double rd  = r;
        double d2  = d * d;
        double T1rd = T1*rd;
        double T2rd = T2*rd;
        double rdN = getPower(T1rd,N);
        double rdM = getPower(T2rd,M);
        double pirdN = pi * rdN * 0.5;
        double cosT1 = cos(pirdN);
        double expT2 = exp(-rdM);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) EkeConst*X*cosT1*expT2/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================



//E = (3h^2/2m)X * ln((T1/(r/d)+0.00001)^N) * exp(-(T2r/d)^M)===================================
double DampedOscillLnNExpN(double r2, double r, double d, double X, double T1, double T2, double N, double M, int E_or_F){

        double rd  = r / d;
        double d2  = d * d;
	double rd_ = rd + 0.00001;
        double T1rd = T1/rd_;
        double T2rd = T2*rd;
        double rdN = getPower(T1rd,N);
        double rdM = getPower(T2rd,M);
        double LnT1 = log(rdN);
        double expT2 = exp(-rdM);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) EkeConst*X*LnT1*expT2/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = (3h^2/2m)X * ln((T1/(r/d)+0.00001)^N) * exp(-(T2r/d)^M)===================================
double DampedOscillLn_R2(double r2, double r, double d, double X, double T1, int E_or_F){

        double rd  = r / d;
	double rd2 = rd * rd;
	double rd_2= 1 / (rd2+0.00001);
        double d2  = d * d;
        double rd_ = rd + 0.00001;
        double T1rd = T1/rd_;
        double LnT1 = log(T1rd);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) EkeConst*X*LnT1*rd_2/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = (3h^2/2m)X * cos ((pi/2)T3erf(T1r/d)) * exp(-(T2r/d)^M)===================================
double DampedOscillCosErfExpN(double r2, double r, double d, double X, double T1, double T2, double T3, double M, int E_or_F){

        double rd  = r / d;
        double d2  = d * d;
        double T1rd = T1*rd;
        double T2rd = T2*rd;
        double rdN = erf(T1rd);
        double rdM = getPower(T2rd,M);
        double pirdN = pi * rdN * 0.5 * T3;
        double cosT1 = cos(pirdN);
        double expT2 = exp(-rdM);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) EkeConst*X*cosT1*expT2/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}


//E = (3h^2/2m)* cos ((pi/2)(T1r/d)^N) * { X1 exp(-([T1+T2]r/d)^M) + X2 exp(-(T2r/d)^M)]===================================
double DampedOscillCosNExpNVar3(double r2, double r, double d, double X1, double X2, double T1, double T2, double T3, \
	double N, double M, int E_or_F){

        double rd  = r / d;
        double d2  = d * d;
        double T1rd = T1*rd;
        double T2rd = T2*rd;
	double T3rd = (T2+T3)*rd;
        double rdN = getPower(T1rd,N);
        double rdM = getPower(T2rd,M);
	double rdpM= getPower(T3rd,M);
        double pirdN = pi * rdN * 0.5;
        double cosT1 = cos(pirdN);
        double expT2 = exp(-rdM);
	double expT3 = exp(-rdpM);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) EkeConst*cosT1*(X1*expT2+X2*expT3)/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================



//E = (3h^2/2m)X * cos ((pi/2)(T1r/d)^N) ===================================
double DampedOscillCosNR2N(double r2, double r, double d, double X, double T1, double N, double M, int E_or_F){

        double rd  = r / d;
	double rd2 = rd * rd;
	double rd_2= 1/rd2;
        //double d2  = d * d;
        double T1rd = T1*rd;
        double rdN = getPower(T1rd,N);
        double rdM = getPower(rd_2,M);
        double pirdN = pi * rdN * 0.5;
        double cosT1 = cos(pirdN);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) EkeConst*X*cosT1*rdM;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = X * cos {(pi)[T1(r/d)^2+T2(r/d)]) * exp(-T3 (r/d)^2)===================================
double DampedOscillCos2ParExp(double r2, double r, double d, double X, double T1, double T2, double T3, int E_or_F){

        double rd  = r / d;
        double d2  = d * d;
        double rd2 = rd * rd;
        double T1rd2 = T1 * rd2;
	double T2rd  = T2 * rd;
	double T1T2   = T1rd2 + T2rd;
        double T3rd2 = T3 * rd2;
        double cosT1T2 = cos(T1T2*pi);
        double expT3 = exp(-T3rd2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) X*cosT1T2*expT3/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = X * cos {(pi)[T1(r/d)^2+T2(r/d)]) * exp(-T3 (r/d)^2)===================================
double DampedOscillCos2ParExpVar1(double r2, double r, double d, double X, double T1, double T2, double T3, int E_or_F){

        double rd  = r / d;
        double d2  = d * d;
        double rd2 = rd * rd;
	double rd_2= sqrt(rd);
        double T1rd_2 = T1 * rd_2;
        double T2rd  = T2 * rd;
        double T1T2   = T1rd_2 + T2rd;
        double T3rd2 = T3 * rd2;
        double cosT1T2 = cos(T1T2*pi);
        double expT3 = exp(-T3rd2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) X*cosT1T2*expT3/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}       
//=============================================================================


//E = X * cos (T1(pi)(r/d)^N) * exp(-T2 (r/d)^4)===================================
double DampedOscillCosNExp4(double r2, double r, double d, double X, double T1, double T2, double N, int E_or_F){

        double rd  = r / d;
        double rdN = getPower(rd,N);
        double d2  = d * d;
        double rd2 = rd * rd;
	double rd4 = rd2 * rd2;
        double T1pirdN = T1 * pi * rdN;
        double T2rd4 = T2 * rd4;
        double cosT1 = cos(T1pirdN);
        double expT2 = exp(-T2rd4);
	double total =X*cosT1*expT2/d2;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) total;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = (3h^2/2m){ X1 exp(-(T1r/d)^M) + X2 exp(-(T2r/d)^M)]===================================
double DampedOscillExpNExpN(double r2, double r, double d, double X1, double X2, double T1, double T2, \
        double M, int E_or_F){

        double rd  = r / d;
        double d2  = d * d;
        double T1rd = T1*rd;
        double T2rd = T2*rd;
        double rdN = getPower(T1rd,M);
        double rdM = getPower(T2rd,M);
        double expT1 = exp(-rdN);
        double expT2 = exp(-rdM);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) EkeConst*(X1*expT1+X2*expT2)/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E= 3h2 / 2m * X / d2 * (1 -[ erf(root(pi)/2 T1 rN) / erf(root(pi)/2 T3 dN)] ) * exp(- (T2 r/d)^M)
double DampedOscillErfNExpN(double r2, double r, double d, double X, double T1, double T2, double T3, double N, double M, int E_or_F){

        double rd  = r / d;
        double d2  = d * d;
	double sqpi2 = sqrt(pi) * 0.5;
        double T1r = T1*r;
        double T2rd = T2*rd;
        double T3d = T1 * T3 * d;
        double rN = getPower(T1r,N);
	double dN = getPower(T3d,N);
        double rdM = getPower(T2rd,M);

	double Rerf= erf(sqpi2 * rN);
	double Derf= erf(sqpi2 * dN);
	double Terf= 1 - (Rerf/Derf);	
        double expT2 = exp(-rdM);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) EkeConst*X*Terf*expT2/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }





}

//E= 3h2 / 2m * X / d2 * (1 -[ erf(root(pi)/2 T1 r/d^N) / erf(root(pi)/2 T3 dN)] ) * exp(- (T2 r/d)^M)
double DampedOscillErfNExpNVar2(double r2, double r, double d, double X, double T1, double T2, double T3, double N, double M, int E_or_F){

        double rd  = r / d;
        double d2  = d * d;
        double sqpi2 = sqrt(pi) * 0.5;
        double T1r = T1*rd;
        double T2rd = T2*rd;
        double T3d = T1 * T3 * d;
        double rN = getPower(T1r,N);
        double dN = getPower(T3d,N);
        double rdM = getPower(T2rd,M);

        double Rerf= erf(sqpi2 * rN);
        double Derf= erf(sqpi2 * dN);
        double Terf= 1 - (Rerf/Derf);
        double expT2 = exp(-rdM);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) EkeConst*X*Terf*expT2/d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }





}



//E = q/r + S/r^2==============================================================
double superCoulomb(double r2, double r, double Q, double S, int E_or_F){

	double coulomb = Q / r;
	double super = S / r2;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) coulomb + super;
	}
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }


}

//E = q/r =====================================================================
double simpleCoulomb(double r2, double r, double Q, int E_or_F){

        //double r = sqrt(r2);

        if (E_or_F == ENERGY){		//ENERGY
                return (double) Q / r;
        }
        if (E_or_F == FORCE) {          //FORCE / DISTANCE
                double r3 = r2 * r;
                return (-Q) / r3;
        }
        if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
                //D independent
                return 0.;
        }
        if (E_or_F == HESSIAN) {        //HESSIAN (2ND DERIVATIVE)
                double r3 = r2 * r;
                return 2. * Q / r3;
        }

        //Default:
        return 0.;

}
//=============================================================================

//E = q/(r + R) ===============================================================
double DshiftedCoulomb(double r2, double r, double d, double Q, double R, int E_or_F){

        //double r = sqrt(r2);
	double dR = d * R;
        double t = r + dR;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = (q /r) erf ( root2* r / sqrt(di^2 + dj^2))===============================
double DeffCoulomb(double r2, double r, double di, double dj, double Q, int E_or_F){

        double di2 = di * di;//1
        double dj2 = dj * dj;//1
	double d2 = di2 + dj2; //2
	double d = sqrt(d2);//sqrt(2)
	double t = sqrt(2) * r / d ;//r
	double u = erf(t);
	//printf("erf(r) for r %f is %f\n", r, u);
	
        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q * u / r;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
	


}

//E = (h^2 / m) (3/2 (1/d1^2 + 1/ d2^2) - 2 ( 3 (d1^2 + d2^2) - 2 r2)/(d1^2 + d2^2))
double DeffKE(double r2, double r, double di, double dj, int E_or_F){

	double di2 = di * di;//1
	double dj2 = dj * dj;//1
	double idi2 = 1./di2;//1
	double idj2 = 1./dj2;//1
	double sid2 = idi2 + idj2;//2
	double sd2  = di2 + dj2;//2
	double sd4  = sd2 * sd2;//4
	double t    = 1.5 * sid2 - 2.*(3*sd2 - 2 * r2) / sd4;
		    // 3          -  2 * ( 6 - 2r2) / 4   
        if (E_or_F == ENERGY){          //ENERGY
                return (double) h_me * t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }



}

//E = (2/(di/dj  + dj/di))^3/2 exp ( - r2 / (di^2 + dj^2))====================
double DeffS(double r2, double r, double di, double dj, int E_or_F){

        double di2 = di * di;//1
        double dj2 = dj * dj;//1
        double sd2  = di2 + dj2;//2
	double dij = di / dj;//1
	double dji = dj / di;//1
	double sdij = dij + dji;//2
	double isdij = 1./ sdij;//0.5
	double c2    = 2. * isdij;//1
	double c     = sqrt (c2);//1
	double c3    = c * c * c;//1
	double t   = r2 / sd2;//r2 / 2
	double u   = exp (-t);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) c3 * u;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E = S^2 / (1 - S^2) + (1 - T) * S^2 / (1 + S^2) =============================
double DeffParallel(double s, double T, int E_or_F) {
	
	double s2 = s * s;
	double ps2 = 1. + s2;
	double ms2 = 1. - s2;
	double ips2 = 1. / ps2;
	double ims2 = 1. / ms2;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) s2 * ims2 + (1 - T) * s2 * ips2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}


//E= (3h^2/2m)(Xdd/d^2+d^2)[3(d^2-d^2)^2 + 4(dd)^2(Tr^2/(d^2+d^2)) /  (d^2+d^2)^3 exp(Tr^2/d^2+d^2) - 8(dd)^3 ]
//the exp in the coefficient is factored into the denominator to make things faster
double DpauliExclusion2d94(double r2, double r, double di, double dj, double X, double T, int E_or_F){

	double dd = di * dj;
	double di2= di * di;
	double dj2= dj * dj;
	double d2pd2= di2 + dj2;
	double d2_d2= di2 - dj2;
	double d2_d2_2= d2_d2 * d2_d2;
	double dd2= dd * dd;
	double dd3= dd2 * dd;
	double d2pd2_3= d2pd2 * d2pd2 * d2pd2;
	double delta= T * r2 / d2pd2;
	double expDelta= exp(delta);
	double coeff = EkeConst * X * dd / d2pd2;
	double num = 3 * d2_d2_2 + 4 * dd2 * delta;
	double denom = d2pd2_3 * expDelta - 8 * dd3;

	//printf("Ekeconst X T dd d2pd2 are %f %f %f %f %f\n",EkeConst,X,T,dd,d2pd2);
	//printf("num denom coeff are %f %f %f \n",num,denom,coeff);
        if (E_or_F == ENERGY){          //ENERGY
                return (double) coeff * num / denom;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
} 

//E= (3h^2/2m)(Xdd/d^2+d^2)cos{0.5piT1(r^2/(d^2+d^2))}[3(d^2-d^2)^2 + 4(dd)^2(Tr^2/(d^2+d^2)) /  (d^2+d^2)^3 exp(Tr^2/d^2+d^2) - 8(dd)^3 ]
double DpauliExclusion2d94Cos(double r2, double r, double di, double dj, double X, double T1, double T, int E_or_F){

        double dd = di * dj;
        double di2= di * di;
        double dj2= dj * dj;
        double d2pd2= di2 + dj2;
        double d2_d2= di2 - dj2;
        double d2_d2_2= d2_d2 * d2_d2;
        double dd2= dd * dd;
        double dd3= dd2 * dd;
        double d2pd2_3= d2pd2 * d2pd2 * d2pd2;
	double del= r2 / d2pd2;
        double delta= T * r2 / d2pd2;
        double expDelta= exp(delta);
	double cosTerm= cos(0.5*pi*T1*del);
        double coeff = EkeConst * X * dd * cosTerm / d2pd2;
        double num = 3 * d2_d2_2 + 4 * dd2 * delta;
        double denom = d2pd2_3 * expDelta - 8 * dd3;

        //printf("Ekeconst X T dd d2pd2 are %f %f %f %f %f\n",EkeConst,X,T,dd,d2pd2);
        //printf("num denom coeff are %f %f %f \n",num,denom,coeff);
        if (E_or_F == ENERGY){          //ENERGY
                return (double) coeff * num / denom;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}

//E=(3h^2/2m)(X/d2)cos(0.5piT1(r2/d2))[(T2*r2/d2) / (exp(T2*r2/d2) - 1)]
double DpauliExclusion88Cos(double r2, double r, double d, double X, double T1, double T2, int E_or_F){

	double d2= d * d;
	double r2d2 = r2 / d2;
	double Xd2 = X / d2;
	double incos= 0.5 * pi * T1 *r2d2 ;
	double cosTerm = cos(incos);
	double del = T2 * r2d2;
	double expdel= exp(del);
	double denom = expdel - 1;
	double coeff= EkeConst * Xd2 * cosTerm;


        if (E_or_F == ENERGY){          //ENERGY
                return (double) coeff * del / denom;

        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E=(3h^2/2m)(X/d2)cos(0.5piT1(r2/d2))exp(-(T2/1.7)*r2/d2)
double DpauliExclusion88CosApprox(double r2, double r, double d, double X, double T1, double T2, int E_or_F){

        double d2= d * d;
        double r2d2 = r2 / d2;
        double Xd2 = X / d2;
        double incos= 0.5 * pi * T1 *r2d2 ;
        double cosTerm = cos(incos);
        double del = T2 * r2d2 / 1.7;
        double expdel= exp(-del);
        double coeff= EkeConst * Xd2 * cosTerm;


        if (E_or_F == ENERGY){          //ENERGY
                return (double) coeff * expdel;

        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E = X / (r2 + K2d2)=========================================================
double DpolyExclusion(double r2, double r, double d, double K, double X, int E_or_F){

	double Kd = K * d;
	double Kd2 = Kd * Kd;
	double s = r2 + Kd2;
	
        if (E_or_F == ENERGY){          //ENERGY
                return (double) X / s;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }


}

//E =( X / (r2 + K2d2) )^m=========================================================
double DpolyExclusionPowNReff(double r2, double r, double d, double X, double K, int N,int E_or_F){

        double K2 = K * K;
        double s = r2 + K2;
	double t = X / s;
	double u = getPower(t,N);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) u;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }


}

//E = X / (r2 + K1*d*r + K2*d2)=========================================================
double DpolyExclusion2Par(double r2, double r, double d, double K1, double K2, double X, int E_or_F){

        double Kd = K1 * d;
        double K2d = K2 * d;
	double Kd2 = K2d * K2d;
	double Kdr = Kd * r;
        double s = r2 + Kdr + Kd2;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) X / s;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }


}

//E = (d*R/r)^N ===============================================================
double DsimpleExclusion(double r2, double r, double d, double R, int N, int E_or_F){

        //double r  = sqrt(r2);
        double c  = d * R / r;
        double cn = getPower(c, N);

        if (E_or_F == ENERGY) {         //ENERGY
                return cn;
        }
        if (E_or_F == FORCE) {          //FORCE / DISTANCE
                return (double) (-N) * cn / r2;
        }
 /*       if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
                return ((double) N) * cn / d;
        }
        if (E_or_F == HESSIAN) {        //HESSIAN (2ND DERIVATIVE)
                double Nd = (double) N;
                return Nd * (Nd + 1) * cn * c * c / (R * R);
        }
*/
        //Default:
        return 0.;
}
//=============================================================================

//E = T1(r/d)^n1 / (1 + T2 (r/d)^n2)===========================================
double DshiftedExclusion2ParV2(double r2, double r, double d, double T1, double T2, int n1, int n2, int E_or_F){

	double rd = r / d;
	double rdn1 = getPower(rd, n1);
	double rdn2 = getPower(rd, n2);
	double T1rdn1 = T1 * rdn1;
	double T2rdn2 = T2 * rdn2;

	if (E_or_F == ENERGY) {         //ENERGY
                return T1rdn1 / (1 + T2rdn2);
        }
        if (E_or_F == FORCE) {          //FORCE / DISTANCE
                return (double) 0;
        }
	return 0;
}

//E= X/(Kad6+Kbd3r3+r6)==========================================================
double DshiftedExclusion3Par(double r2, double r, double d, double Q, double Ka, \
	double Kb, double X, int E_or_F){

	double Kad = Ka * d;
	double Kbd = Kb * d;
	double Kad2 = Kad * Kad;
	double Kad4 = Kad2 * Kad2;
	double Kad6 = Kad2 * Kad4;
	double Kbd2 = Kbd * Kbd;
	double Kbd3 = Kbd2 * Kbd;
	double r3 = r2 * r;
	double r4 = r2 * r2;
	double r6 = r2 * r4;
	double Kbd3r3 = Kbd3 * r3;
	double t = Kad6 + Kbd3r3 + r6;
	

        if (E_or_F == ENERGY){          //ENERGY
                return (double) X / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E =  (K/d2) exp (- T (r/d)^N ) ===================================================
double DexponentialExclusion2Par(double r2, double r, double d, double T, double K, \
        int N, int E_or_F){

        double d2   = d * d;
        double id2  = 1. / d2;
        double c    = r / d;
        double n    = (double) N;
        double cn   = getPower(c, n);
        double t    = T * cn;
        double e    = exp(-t);

        if (E_or_F == ENERGY){          //ENERGY
                return id2 * K * e;
        }
        if (E_or_F == FORCE) {          //FORCE / DISTANCE
                return (-id2) * id2 * K * n * T * cn * e / r2;
        }
        if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
                double s = n * cn - 2;
                return K * id2 * e * s / d;
        }
        if (E_or_F == HESSIAN) {        //HESSIAN (2ND DERIVATIVE)
                double s = (1 - n) + (n * t);
                return K *  n * T * r2 * id2 * e * s;
        }
        //Default:
        return 0.;
}

//E = K exp ( - (r/R)^N)=========================================================
double DexponentialExclusion2Par2(double r2, double r, double R, double K, \
	int N, int E_or_F){

	double c = r/R;
	double n = (double) N;
	double cn= getPower (c,N);
	double e = exp (-cn);

        if (E_or_F == ENERGY){          //ENERGY
                return K * e;
        }
        if (E_or_F == FORCE) {          //FORCE / DISTANCE
                return (-K) * n * cn * e / r2;
        }
        if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
                return 0.0;
        }
        if (E_or_F == HESSIAN) {        //HESSIAN (2ND DERIVATIVE)
                double s = (1 - n) + (n * cn);
                return K * n * cn * s * e / r2;
        } 



	//Default:
	return 0.;
}
// E = (R * r2 / d4) exp (- T (r/d)^N)========================================================
double DexponentialExclusion2Par3(double r2, double r, double d,  double T, double R, \
	int N, int E_or_F){

	double d2 = d * d;//1
	double d4 = d2 * d2;//1
	double rd = r / d;//r
	double r2d4 = r2 / d4;//r2
	//double n = (double) N;
	double cn = getPower(rd,N);//r2
	double t = T * cn;//T*r2
	double e = exp(-t);//exp(-T *r2)

        if (E_or_F == ENERGY){          //ENERGY
		return R * r2d4 * e;//R * r2 * exp (-T *r2)
	}

	//Default;
	return 0.;
}

// E = (R1/d2 + R2 * r2 / d4) exp (- T (r/d)^N)========================================================
double DexponentialExclusion3Par(double r2, double r, double d,  double T, double R1, \
        double R2, int N, int E_or_F){

        double d2 = d * d;//1
        double d4 = d2 * d2;//1
        double rd = r / d;//r
        double r2d4 = r2 / d4;//r2
        //double n = (double) N;
        double cn = getPower(rd,N);//r2
        double t = T * cn;//T*r2
        double e = exp(-t);//exp(-T *r2)
	double R2r2d4 = R2 * r2d4;//r2
	double R1d2 = R1 / d2;//1
	double coef = R1d2 + R2r2d4;//(1+r2)

        if (E_or_F == ENERGY){          //ENERGY
                return coef * e;//(1+ r2) * exp (-T *r2)
        }

        //Default;
        return 0.;
}


// E = (1/d)^N [T1 * (r/d) + T2 * (r2/d2)] exp (- T (r/d)^2)========================================================
double DexponentialExclusion3Par2(double r2, double r, double d,  double T3, double T1, \
        double T2, int N, int E_or_F){

        //double d2 = d * d;//1
        double rd = r / d;//r
	double r2d2 = rd * rd;//r2

        //double n = (double) N;
        double dn = getPower(d,N);//r2

        double t = T3 * r2d2;//T*r2
        double e = exp(-t);//exp(-T *r2)

	double T1rd = T1 * rd;//T1r
	double T2r2d2 = T2 * r2d2; // T2r2
	double sTrd = T1rd + T2r2d2;
        double coef = sTrd / dn;

        if (E_or_F == ENERGY){          //ENERGY
                return coef * e;//(1+ r2) * exp (-T *r2)
        }

        //Default;
        return 0.;
}

// E = K{T(r/d)^2 / [ exp(T* (r/d)^2) -1 ]}===========================================
double DinvExponentialExclusion(double r2, double r, double d, double T, double K, int E_or_F){

	double rd = r / d;
	double rd2 = rd * rd;
	double Trd2 = T * rd2;
	double e = exp(Trd2);

        if (E_or_F == ENERGY){          //ENERGY
		return K * Trd2 / (e - 1);

        }

        //Default;
        return 0.;
}

//E = 1/(1 + s/2 + s2/6 + s3/24 + s4/120 + s5/720)=============================== 
double DinvExpExclApprox5Term(double r2, double r, double d, double K, double T, int E_or_F){

        double rd = r /d;
        double rd2 = rd * rd;
        double s  = T * rd2;
        double s2 = s * s;
        double s3 = s * s2;
        double s4 = s2 * s2;
        double s5 = s3 * s2;
        double sum = 1 + s/2. + s2/6. + s3/24. + s4/120. + s5/720.;


       if (E_or_F == ENERGY){          //ENERGY
                return K/sum;
        }

        return 0.;
}
//=============================================================================



//E = 1/d2 (d*R/r)^N ===============================================================
double D2simpleExclusion(double r2, double r, double d, double R, double N, int E_or_F){

        //double r  = sqrt(r2);
        double c  = d * R / r;
        double cn = getPower(c, N);
	double d2 = d * d;


        if (E_or_F == ENERGY) {         //ENERGY
                return cn / d2;
        }
        //if (E_or_F == FORCE) {          //FORCE / DISTANCE
                return (double) 0.;
        //}

}

//E =  rho(1/d1^2+1/d2^2) exp (- T (r/(d1^2+d2^2) ) ===================================================
double D2exponentialExclusion2Par(double r2, double r, double di, double dj,  double T, double K, \
        int E_or_F){

        double di2   = di * di;
	double dj2   = dj * dj;
	double d2 = di2 + dj2;
	double idi2 = 1./di2;
	double idj2 = 1./dj2;
	double sid2 = idi2 + idj2;
        double c    = r2 / d2;
        double t    = T * c;
        double e    = exp(-t);

        if (E_or_F == ENERGY){          //ENERGY
                return  K * sid2 * e;
        }
        if (E_or_F == FORCE) {          //FORCE / DISTANCE
                //return id2 * id2 * K * n * T * cn * e / r2;
		return 0.;
        }
        if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
               // double s = n * cn - 2;
                //return K * id2 * e * s / d;
		return 0.;
        }
        if (E_or_F == HESSIAN) {        //HESSIAN (2ND DERIVATIVE)
            //    double s = (1 - n) + (n * t);
            //    return K *  n * T * r2 * id2 * e * s;
		return 0.;
        }
        //Default:
        return 0.;
}


//E = X1/(d^2*(r/d)^n1)========================================================
double D2exclusion1Par(double r2, double r, double d, double X1, int n1, int E_or_F){

	double rd = r / d;
        double rdn1 = getPower(rd, n1);
        double d2 = d * d;
        double d2_ = 1 / d2;
	double u = d2_ * X1;

        if (E_or_F == ENERGY){ 
		return (double) u / rdn1;
	}
	else{
		return (double) 0;
	}

}

//E = 1/d^2(1+T1(r/d)^n1+T2(r/d)^n2)===========================================
double D2exclusion2Par(double r2, double r, double d, double T1, double T2, int n1, int n2, int E_or_F){

	double rd = r / d;
        double rdn1 = getPower(rd, n1);
        double rdn2 = getPower(rd, n2);
        double T1rdn1 = T1 * rdn1;
        double T2rdn2 = T2 * rdn2;
	double d2 = d * d;
	double d2_ = 1 / d2;
	double t = 1 + T1rdn1 + T2rdn2;
	

        if (E_or_F == ENERGY){          //ENERGY
		//printf("new exclusion term for r %f, d %f, T1 %f, T2 %f, n1 %d and n2 %d is %f\n",r, d, T1, T2, n1, n2, d2_ / t);
                return (double) d2_ / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E = X1/d^2(1+T1(r/d)^n12)===========================================
double D2exclusion2ParV2(double r2, double r, double d, double T1, double X1, int n1, int E_or_F){

        double rd = r / d;
        double rdn1 = getPower(rd, n1);
        double T1rdn1 = T1 * rdn1;
        double d2 = d * d;
        double d2_ = 1 / d2;
        double t = 1 + T1rdn1;
	double u = d2_ * X1;


        if (E_or_F == ENERGY){          //ENERGY
                //printf("new exclusion term for r %f, d %f, T1 %f, T2 %f, n1 %d and n2 %d is %f\n",r, d, T1, T2, n1, n2, d2_ / t);
                return (double) u / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}



//E= Chi / d2 [ 1 - T1 r / 2 d ] exp ( -(T1+T2) r /d)==========================
double DvirialExponentialExclusion(double r2, double r, double d, double X, double T1, double T2, int E_or_F){

	double d2 = d * d;
        double rd = r / d;
	double T1rd = T1 * rd * 0.5;
	double T2rd = (T1 + T2) * rd;
	double coeff= 1 - T1rd;
	double exprd= exp (-T2rd);

        if (E_or_F == ENERGY){          //ENERGY
                //printf("new exclusion term for r %f, d %f, T1 %f, T2 %f, n1 %d and n2 %d is %f\n",r, d, T1, T2, n1, n2, d2_ / t);
                return (double) EkeConst * X * coeff * exprd / d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E= Chi / d2 [ 1 - (T1 r /d)^2 ] exp ( - [(T1+T2) r /d]^2)==========================
double DvirialGaussianExclusion(double r2, double r, double d, double X, double T1, double T2, int E_or_F){

        double d2 = d * d;
        double rd = r / d;
        double T1rd = T1 * rd;
	double T1rd2 = T1rd * T1rd;
        double T2rd = (T1 + T2) * rd;
	double T2rd2= T2rd *T2rd;
        double coeff= 1 - T1rd2;
        double exprd= exp (-T2rd2);

        if (E_or_F == ENERGY){          //ENERGY
                //printf("new exclusion term for r %f, d %f, T1 %f, T2 %f, n1 %d and n2 %d is %f\n",r, d, T1, T2, n1, n2, d2_ / t);
                return (double) EkeConst * X * coeff * exprd / d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E= Chi / d2 [ 1 - 2 (T1 r /d)^6 ] / [1 + {(T1+T2) r /d}^6]^2 ==========================
double DvirialShiftedExclusionPow6(double r2, double r, double d, double X, double T1, double T2, int E_or_F){

        double d2 = d * d;
        double rd = r / d;
        double T1rd = T1 * rd;
        double T1rd2 = T1rd * T1rd;
        double T1rd4 = T1rd2 * T1rd2;
        double T1rd6 = T1rd2 * T1rd4;
        double T2rd = (T1 + T2) * rd;
	double T2rd2 = T2rd * T2rd;
        double T2rd4 = T2rd2 * T2rd2;
        double T2rd6 = T2rd2 * T2rd4;
        double num1= 1 - 2 * T1rd6;
        double denom_2 = 1 + T2rd6;
	double denom = denom_2 * denom_2;
	double num2 = 1 / denom;

        if (E_or_F == ENERGY){          //ENERGY
                //printf("new exclusion term for r %f, d %f, T1 %f, T2 %f, n1 %d and n2 %d is %f\n",r, d, T1, T2, n1, n2, d2_ / t);
                return (double) EkeConst * X * num1 * num2 / d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E= Chi / d2 [ 1 - (n-1) (T1 r /d)^2n ] / [1 + {(T1+T2) r /d}^2n]^2 ==========================
double DvirialLorentzianExclusionPowN(double r2, double r, double d, double X, double T1, double T2, double N, int E_or_F){

	double n = N * 0.5;
        double d2 = d * d;
        double rd = r / d;
        double T1rd = T1 * rd;
	double T1rdN = getPower(T1rd,N);
        double T2rd = (T1 + T2) * rd;
	double T2rdN = getPower(T2rd,N);
        double num1= 1. - (n-1.) * T1rdN;
        double denom_2 = 1. + T2rdN;
        double denom = denom_2 * denom_2;
        double num2 = 1 / denom;

        if (E_or_F == ENERGY){          //ENERGY
                //printf("new exclusion term for r %f, d %f, T1 %f, T2 %f, n1 %d and n2 %d is %f\n",r, d, T1, T2, n1, n2, d2_ / t);
                return (double) EkeConst * X * num1 * num2 / d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E= Chi / d2 [ 1 - (n-1) (T1 r /d)^2n ] / [1 + {(T1+T2) r /d}^2n]^2 ==========================
double DvirialLorentzianExclusionPowNVar1(double r2, double r, double d, double X, double T1, double T2, double N, int E_or_F){

        double n = N * 0.5;
        double d2 = d * d;
        double rd = r;
        double T1rd = T1 * rd;
        double T1rdN = getPower(T1rd,N);
        double T2rd = (T1 + T2) * rd;
        double T2rdN = getPower(T2rd,N);
        double num1= 1. - (n-1.) * T1rdN;
        double denom_2 = 1. + T2rdN;
        double denom = denom_2 * denom_2;
        double num2 = 1 / denom;

        if (E_or_F == ENERGY){          //ENERGY
                //printf("new exclusion term for r %f, d %f, T1 %f, T2 %f, n1 %d and n2 %d is %f\n",r, d, T1, T2, n1, n2, d2_ / t);
                return (double) EkeConst * X * num1 * num2 / d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E= Chi / d2 [ 1 - (n-1) (T1 Reff)^2n ] / [1 + {(T1+T2) Reff}^2n + (T3 {(T1+T2) Reff}^2n)^2]^2 ==========================
double DvirialLorentzianExclusionPowNPar3(double r2, double r, double d, double X, double T1, double T2, double T3, double N, int E_or_F){

        double n = N * 0.5;
        double d2 = d * d;
        double rd = r;
        double T1rd = T1 * rd;
        double T1rdN = getPower(T1rd,N);
        double T2rd = (T1 + T2) * rd;
        double T2rdN = getPower(T2rd,N);
	double T3rdN = T3 * T2rdN;
	double T3rdN2= T3rdN * T3rdN;
        double num1= 1. - (n-1.) * T1rdN;
        double denom_2 = 1. + T2rdN + T3rdN2;
        double denom = denom_2 * denom_2;
        double num2 = 1 / denom;

        if (E_or_F == ENERGY){          //ENERGY
                //printf("new exclusion term for r %f, d %f, T1 %f, T2 %f, n1 %d and n2 %d is %f\n",r, d, T1, T2, n1, n2, d2_ / t);
                return (double) EkeConst * X * num1 * num2 / d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}

//E= Chi / d2 [ 1 - (T1 Reff)^6 ] / [1 + (T2 Reff)^6 + (T3 Reff)^12)]^2 ==========================
double DvirialLorentzianExclusionPow6Par3(double r2, double r, double d, double X, double T1, double T2, double T3, int E_or_F){

        double d2 = d * d;
        double rd = r;
	double rd2 = rd * rd;
	double rd6 = rd2 * rd2* rd2;
	double rd12 = rd6 * rd6;
        double T1rd6 = T1 * rd6;
        double T2rd6 = T2 * rd6;
        double T3rd12 = T3 * rd12;
        double num1= 1. - T1rd6;
        double denom_2 = 1. + T2rd6 + T3rd12;
        double denom = denom_2 * denom_2;
        double num2 = 1 / denom;

        if (E_or_F == ENERGY){          //ENERGY
                //printf("new exclusion term for r %f, d %f, T1 %f, T2 %f, n1 %d and n2 %d is %f\n",r, d, T1, T2, n1, n2, d2_ / t);
                return (double) EkeConst * X * num1 * num2 / d2;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}




//E = q / (r^n + Ra^n)^1/n===================================================
double DsmoothNCoulomb2Par(double r2, double r, double d, double Q, double Ra, \
	double n, int E_or_F){

	double Rad = Ra * d;
	double Radn = getPower(Rad,n);
	double rn = getPower(r,n);
	double in = 1./n;
	double tn = rn + Radn;
	double t = getPower(tn,in);

        if(E_or_F == ENERGY){           //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}

//E = q/(r2 + d2)^1/2========================================================
double Dsmooth2Coulomb0Par(double r2, double r, double d, double Q, int E_or_F){

        double d2 = d * d;
        double t2  = r2 + d2;
        double t   = sqrt(t2);

	//printf("at r2 %f d %f Q %f d2 is %f t2 is %f t is %f and Q/t is %f\n",r2,d,Q,d2,t2,t,Q/t);

        if(E_or_F == ENERGY){           //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = q/(r2 + Ra2)^1/2========================================================
double Dsmooth2Coulomb1Par(double r2, double r, double d, double Q, double Ra, \
        int E_or_F){

        double Rad = Ra *  d;
	double Rad2 = Rad * Rad;
        double t2  = r2 + Rad2;
        double t   = sqrt(t2);

        if(E_or_F == ENERGY){           //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//============================================================================= 


//E = q/(r2 + Ra * r + Rb2)^1/2================================================
double Dsmooth2Coulomb2Par(double r2, double r, double d, double Q, double Ra, \
        double Rb, int E_or_F){

	double Rbd = Rb * d;
        double Rbd2 = Rbd * Rbd;
        double Rard = Ra * r * d;
        double t2  = r2 + Rard + Rbd2;
        double t   = sqrt(t2);

        if(E_or_F == ENERGY){           //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//============================================================================= 

//E = q/ (d * (r4 + K2* r2 + R4)^1/4) =========================================
double Dsmooth4Coulomb2Par(double r2, double r, double d, double Q, double K, \
        double R, int E_or_F){

        double r4  = r2 * r2;
	double K2  = K * K;
//      double Rd  = R * d;
//      double Rd2 = Rd * Rd;
//      double Rd4  = Rd2 * Rd2;
//      double Kd  = K * d;
//      double Kd2 = Kd * Kd;
//      double Kd2r2 = Kd2 * r2;
        double t4  = r4 + K2 * r2 + R;
        double t2  = sqrt(t4);
        double t   = sqrt(t2);
	t = t * d;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}
//=============================================================================

//E = q/(r8 +  Rb^8)^1/8=============================================
double Dsmooth8Coulomb1Par(double r2, double r, double d, double Q, double K, \
        int E_or_F){

        double r4  = r2 * r2;
        double r8  = r4 * r4;
        double Kd  = K * d;
        double Kd2 = Kd * Kd;
        double Kd4  = Kd2 * Kd2;
        double Kd8  = Kd4 * Kd4;
        double t8  = r8 + Kd8;
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}

//=============================================================================

//E = q/(r16 +  Rb^16)^1/16=============================================
double Dsmooth16Coulomb1Par(double r2, double r, double d, double Q, double K, \
        int E_or_F){

        double r4  = r2 * r2;
        double r8  = r4 * r4;
	double r16 = r8 * r8;
        double Kd  = K * d;
        double Kd2 = Kd * Kd;
        double Kd4  = Kd2 * Kd2;
        double Kd8  = Kd4 * Kd4;
	double Kd16 = Kd8 * Kd8;
	double t16 = r16 + Kd16;
        double t8  = sqrt(t16);
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);
        
        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}       
                
//=============================================================================


//E = q/(r32 +  Rb^32)^1/32=============================================
double Dsmooth32Coulomb1Par(double r2, double r, double d, double Q, double K, \
        int E_or_F){

        double r4  = r2 * r2;
        double r8  = r4 * r4;
        double r16 = r8 * r8;
	double r32 = r16 * r16;
        double Kd  = K * d;
        double Kd2 = Kd * Kd;
        double Kd4  = Kd2 * Kd2;
        double Kd8  = Kd4 * Kd4;
        double Kd16 = Kd8 * Kd8;
	double Kd32 = Kd16 * Kd16;
	double t32 = r32 + Kd32;
        double t16 = sqrt(t32);
        double t8  = sqrt(t16);
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
} 

//=============================================================================

//E = q+qc/(r8 +  Rb^8)^1/8 + qc / (r8 +  Rb^8)^1/8 ===========================
double Dsmooth8CoulombPcore2Par(double r2, double r, double d, double Q, double Qc,  double Ki, \
        double Kj, int E_or_F){

        double r4  = r2 * r2;
        double r8  = r4 * r4;
        double Kid  = Ki * d;
        double Kid2 = Kid * Kid;
        double Kid4  = Kid2 * Kid2;
        double Kid8  = Kid4 * Kid4;
	double Kjd = Kj * d;
	double Kjd2= Kjd * Kjd;
	double Kjd4= Kjd2 * Kjd2;
	double Kjd8= Kjd4 * Kjd4;
        double t8  = r8 + Kid8;
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);
	double p8  = r8 + Kjd8;
	double p4  = sqrt(p8);
	double p2  = sqrt(p4);
	double p   = sqrt(p2);
	double Qt  = Q + Qc;
        
        if (E_or_F == ENERGY){          //ENERGY
                return (double) (Qt / t) - (Qc / p);
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}       
                
//=============================================================================


//E = q/(r8 + Ra^4*r4 +  Rb^8)^1/8=============================================
double Dsmooth8Coulomb2Par(double r2, double r, double d, double Q, double K, \
        double R, int E_or_F){

        double r4  = r2 * r2;
        double r8  = r4 * r4;
        double Rd  = R * d;
        double Rd2 = Rd * Rd;
        double Rd4  = Rd2 * Rd2;
        double Rd8  = Rd4 * Rd4;
        double Kd  = K * d;
        double Kd2 = Kd * Kd;
        double Kd4 = Kd2 * Kd2;
        double Kd4r4 = Kd4 * r4;
        double t8  = r8 + Kd4r4 + Rd8;
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}

//=============================================================================


//E = q/(r8 + 4*T^2*d^2*r^6 + 6*T^4*d^4*r^4+ 4*d^6*r^2 + d^8)^1/8=============================================
double Dsmooth8Coulomb2ParVar12(double r2, double r, double d, double Q, double T, \
         int E_or_F){

        double r4  = r2 * r2;
	double r6  = r4 * r2;
        double r8  = r4 * r4;
        double d2  = d * d;
        double d4  = d2 * d2;
	double d6  = d2 * d4;
        double d8  = d4 * d4;
	double T2  = T * T;
	double T4  = T2 * T2;
//	double T6  = T2 * T4;
        double t8  = r8 + 4*T2*d2*r6 + 6*T4*d4*r4 + 4*d6*r2 + d8;
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}

//=============================================================================


//E = q/(r8 + 4*T^2*d^2*r^6 + 6*d^4*r^4+ 4*T^6*d^6*r^2 + d^8)^1/8=============================================
double Dsmooth8Coulomb2ParVar13(double r2, double r, double d, double Q, double T, \
         int E_or_F){

        double r4  = r2 * r2;
        double r6  = r4 * r2;
        double r8  = r4 * r4; 
        double d2  = d * d;
        double d4  = d2 * d2;
        double d6  = d2 * d4;
        double d8  = d4 * d4;
        double T2  = T * T;
        double T4  = T2 * T2;
        double T6  = T2 * T4;
        double t8  = r8 + 4*T2*d2*r6 + 6*d4*r4 + 4*T6*d6*r2 + d8;
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}

//=============================================================================


//E = q/(r8 + 4*d^2*r^6 + 6*T^4*d^4*r^4+ 4*T^6*d^6*r^2 + d^8)^1/8=============================================
double Dsmooth8Coulomb2ParVar23(double r2, double r, double d, double Q, double T, \
         int E_or_F){

        double r4  = r2 * r2;
        double r6  = r4 * r2;
        double r8  = r4 * r4; 
        double d2  = d * d;
        double d4  = d2 * d2;
        double d6  = d2 * d4;
        double d8  = d4 * d4;
        double T2  = T * T;
        double T4  = T2 * T2;
        double T6  = T2 * T4;
        double t8  = r8 + 4*d2*r6 + 6*T4*d4*r4 + 4*T6*d6*r2 + d8;
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}

//=============================================================================







//E = q/(r8 + K * r4 + R8)^1/8 ================================================
double Dsmooth8Coulomb3ParVariant1(double r2, double r, double dd, double Q, double K, \
        double R, double rho, int E_or_F){

	double d   = dd + rho;
        double r4  = r2 * r2;
        double r8  = r4 * r4;
	double Rd  = R * d;
        double Rd2 = Rd * Rd;
        double Rd4  = Rd2 * Rd2;
        double Rd8  = Rd4 * Rd4;
	double Kd  = K * d;
	double Kd2 = Kd * Kd;
	double Kd4 = Kd2 * Kd2;
        double Kd4r4 = Kd4 * r4;
        double t8  = r8 + Kd4r4 + Rd8;
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}
//=============================================================================

//E = q/(r8 + K * r4 + R8)^1/8 ================================================
double Dsmooth8Coulomb3ParVariant2(double r2, double r, double d1, double d2, double Q, double K, \
        double R, double rho, int E_or_F){

        double d   = deff(d1,d2,rho,0);
        double r4  = r2 * r2;
        double r8  = r4 * r4;
        double Rd  = R * d;
        double Rd2 = Rd * Rd;
        double Rd4  = Rd2 * Rd2;
        double Rd8  = Rd4 * Rd4;
        double Kd  = K * d;
        double Kd2 = Kd * Kd;
        double Kd4 = Kd2 * Kd2;
        double Kd4r4 = Kd4 * r4;
        double t8  = r8 + Kd4r4 + Rd8;
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }

}
//=============================================================================


//E = q/(r8 + Ra^4*r4 + Rb^6*r2 + Rc^8)^1/8====================================
double Dsmooth8Coulomb3Par(double r2, double r, double d, double Q, double Ra, \
        double Rb, double Rc, int E_or_F){

	double Rad	= Ra * d;
	double Rbd	= Rb * d;
	double Rcd	= Rc * d;
        double r4      = r2 * r2;
        double r8      = r4 * r4;
        double Rad2     = Rad * Rad;
        double Rad4     = Rad2 * Rad2;
        double Rad4r4   = Rad4 * r4;
        double Rbd2     = Rbd * Rbd;
        double Rbd6     = Rbd2 * Rbd2 * Rbd2;
        double Rbd6r2   = Rbd6 * r2;
        double Rcd2     = Rcd * Rcd;
        double Rcd4     = Rcd2 * Rcd2;
        double Rcd8     = Rcd4 * Rcd4;
        double t8      = r8 + Rad4r4 + Rbd6r2 + Rcd8;
        double t4      = sqrt(t8);
        double t2      = sqrt(t4);
        double t       = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        if (E_or_F == FORCE) {          //FORCE / DISTANCE
                double Rad4r2 = Rad4 * r2;
                double r6    = r4 * r2;
                double u6    = r6 + 0.50 * Rad4r2 + 0.25 * Rbd6;
                double t9    = t8 * t;
                return (-Q) * u6 / t9;
        }
        if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
                double u6    = 2 * Rad4r4 + 3 * Rbd6r2 + 4 * Rcd8;
                double t9    = t8 * t;
                return (-Q) * (.25/d) * u6 / t9;
        }
        if (E_or_F == HESSIAN) {        //HESSIAN (2ND DERIVATIVE)
                double r3 = r2 * r;
                double r6 = r4 * r2;
                double r7 = r6 * r;
                double t9 = t8 * t;
                double t17 = t8 * t9;

                double num1 = 9. * Q * getPower((2. * Rbd6 * r + 4. * Rad4 * r3 + 8. * r7), 2.);
                double den1 = 64. * t17;
                double num2 = Q * (2. * Rbd6 + 12. * Rad4 * r2 + 56. * r6);
                double den2 = 8. * t9;

                return (num1 / den1) - (num2 / den2);
        }

        //Default:
        return 0.;

}

//=============================================================================

//E = q/(r8 + Ra^2*r6 + Rb^4*r4 + Rc^6*r2 + Rd^8)^1/8==========================
double Dsmooth8Coulomb4ParVariant1(double r2, double r, double d, double Q,
        double Ra, double Rb, double Rc, double Rd, int E_or_F){

        /*Ra = Ra * d;
        Rb = Rb * d;
        Rc = Rc * d;
        Rd = Rd * d;*/

        double r4       = r2 * r2;
        double r6       = r4 * r2;
        double r8       = r4 * r4;
        double Ra2      = d * d * Ra * Ra;
        //double Ra2      = Ra * Ra;
        double Ra2r6    = Ra2 * r6;
        double Rb2      = d * d * Rb * Rb;
        //double Rb2      = Rb * Rb;
        double Rb4      = Rb2 * Rb2;
        double Rb4r4    = Rb4 * r4;
        double Rc2      = d * d * Rc * Rc;
        //double Rc2      = Rc * Rc;
        double Rc6      = Rc2 * Rc2 * Rc2;
        double Rc6r2    = Rc6 * r2;
        double Rd2      = d * d * Rd * Rd;
        //double Rd2      = Rd * Rd;
        double Rd4      = Rd2 * Rd2;
        double Rd8      = Rd4 * Rd4;
        double t8       = r8 + Ra2r6 + Rb4r4 + Rc6r2 + Rd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY) {         //ENERGY
                return Q / t;
        }
        if (E_or_F == FORCE) {          //FORCE / DISTANCE
                double Ra2r4 = Ra2 * r4;
                double Rb4r2 = Rb4 * r2;
                double u6    = r6 + 0.75 * Ra2r4 + 0.50 * Rb4r2 + 0.25 * Rc6;
                double t9    = t8 * t;
                return (-Q) * u6 / t9;
        }
        if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
                double u6    = Ra2r6 + 2 * Rb4r4 + 3 * Rc6r2 + 4 * Rd8;
                double t9    = t8 * t;
                return (-Q) * (.25/d) * u6 / t9;
        }
        if (E_or_F == HESSIAN) {        //HESSIAN (2ND DERIVATIVE)
                double r3 = r2 * r;
                double r5 = r3 * r2;
                double r6 = r4 * r2;
                double r7 = r6 * r;
                double t9 = t8 * t;
                double t17 = t8 * t9;

                double num1 = 9. * Q * getPower((2. * Rc6 * r + 4. * Rb4 * r3 + + 6. * Ra2 * r5 + 8. * r7), 2.);
                double den1 = 64. * t17;
                double num2 = Q * (2. * Rc6 + 12. * Rb4 * r2 + 30. * Ra2 * r4 + 56. * r6);
                double den2 = 8. * t9;

                return (num1 / den1) - (num2 / den2);
        }

        //Default:
        return 0.;

}
//=============================================================================



//E = q/(r8 + Ra^2*d^2*r6 + Rb^4*d^4*r4  Rd^8*d^8)^1/8==========================
double Dsmooth8Coulomb4ParVariant2(double r2, double r, double d1, double d2, double Q, double Ra, \
        double Rb, double Rd, double rho, int E_or_F){

        double d        = deff(d1,d2,rho,0);
        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
        double Rad      = Ra * d;
        double Rbd      = Rb * d;
        double Rdd      = Rd * d;
        double Rad2     = Rad * Rad;
        double Rad2r6   = Rad2 * r6;
        double Rbd2     = Rbd * Rbd;
        double Rbd4     = Rbd2 * Rbd2;
        double Rbd4r4   = Rbd4 * r4;
        double Rdd2     = Rdd * Rdd;
        double Rdd4     = Rdd2 * Rdd2;
        double Rdd8     = Rdd4 * Rdd4;
        double t8       = r8 + Rad2r6 + Rbd4r4 + Rdd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = q/(r8 + Ra^4*d^4*r4 + Rb^7*d^7*r  Rd^8*d^8)^1/8==========================
double Dsmooth8Coulomb4ParVariant3(double r2, double r, double d, double Q, double Ra, \
        double Rb, double Rd, int E_or_F){

        double r4       = r2 * r2;
        double r8       = r4 * r4;
        double Rad      = Ra * d;
        double Rbd      = Rb * d;
        double Rdd      = Rd * d;
        double Rad2     = Rad * Rad;
        double Rad4     = Rad2 * Rad2;
	double Rad4r4   = Rad4 * r4;
        double Rbd2     = Rbd * Rbd;
        double Rbd4     = Rbd2 * Rbd2;
        double Rbd7     = Rbd4 * Rbd2 * Rbd;
	double Rbd7r    = Rbd7 * r;
        double Rdd2     = Rdd * Rdd;
        double Rdd4     = Rdd2 * Rdd2;
        double Rdd8     = Rdd4 * Rdd4;
        double t8       = r8 + Rad4r4 + Rbd7r + Rdd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = q/(r8 + Ra^6*d^6*r2 + Rb^7*d^7*r  Rd^8*d^8)^1/8==========================
double Dsmooth8Coulomb4ParVariant4(double r2, double r, double d, double Q, double Ra, \
        double Rb, double Rd, int E_or_F){

	double r4	= r2 * r2;
        double r8       = r4 * r4;
        double Rad      = Ra * d;
        double Rbd      = Rb * d;
        double Rdd      = Rd * d;
        double Rad2     = Rad * Rad;
        double Rad4     = Rad2 * Rad2;
	double Rad6	= Rad2 * Rad4;
        double Rad6r2   = Rad6 * r2;
        double Rbd2     = Rbd * Rbd;
        double Rbd4     = Rbd2 * Rbd2;
        double Rbd7     = Rbd4 * Rbd2 * Rbd;
        double Rbd7r    = Rbd7 * r;
        double Rdd2     = Rdd * Rdd;
        double Rdd4     = Rdd2 * Rdd2;
        double Rdd8     = Rdd4 * Rdd4;
        double t8       = r8 + Rad6r2 + Rbd7r + Rdd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = q/deff(reff8 + Ra^2*reff6 + Rb^4*reff4 + Rc^6*reff2 + 1)^1/8==========================
double Dsmooth8Coulomb4ParReff(double r2, double r, double d, double Q,
        double Ra, double Rb, double Rc, double Rd, int E_or_F){

        /*Ra = Ra * d;
        Rb = Rb * d;
        Rc = Rc * d;
        Rd = Rd * d;*/

        double r4       = r2 * r2;
        double r6       = r4 * r2;
        double r8       = r4 * r4;
        double Ra2      = Ra * Ra;
        //double Ra2      = Ra * Ra;
        double Ra2r6    = Ra2 * r6;
        double Rb2      = Rb * Rb;
        //double Rb2      = Rb * Rb;
        double Rb4      = Rb2 * Rb2;
        double Rb4r4    = Rb4 * r4;
        double Rc2      = Rc * Rc;
        //double Rc2      = Rc * Rc;
        double Rc6      = Rc2 * Rc2 * Rc2;
        double Rc6r2    = Rc6 * r2;
        //double Rd2      = Rd * Rd;
        //double Rd2      = Rd * Rd;
        double t8       = r8 + Ra2r6 + Rb4r4 + Rc6r2 + 1.;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY) {         //ENERGY
                return Q / (d*t);
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================



//E = q/(r8 + Ra^2*d^2*r6 + Rb^4*d^4*r4 + Rc^6*d^6*r2 + Rd^8*d^8)^1/8==========================
double Dsmooth8Coulomb5ParVariant2(double r2, double r, double d1, double d2, double Q, double Ra, \
        double Rb, double Rc, double Rd, double rho, int E_or_F){

	double d	= deff(d1,d2,rho,0);
        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
        double Rad      = Ra * d;
        double Rbd      = Rb * d;
        double Rcd      = Rc * d;
        double Rdd      = Rd * d;
        double Rad2     = Rad * Rad;
        double Rad2r6   = Rad2 * r6;
        double Rbd2     = Rbd * Rbd;
        double Rbd4     = Rbd2 * Rbd2;
        double Rbd4r4   = Rbd4 * r4;
        double Rcd2     = Rcd * Rcd;
        double Rcd6     = Rcd2 * Rcd2 * Rcd2;
        double Rcd6r2   = Rcd6 * r2;
        double Rdd2     = Rdd * Rdd;
        double Rdd4     = Rdd2 * Rdd2;
        double Rdd8     = Rdd4 * Rdd4;
        double t8       = r8 + Rad2r6 + Rbd4r4 + Rcd6r2 + Rdd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = q/(r8 + Ra^2*d^2*r6 + Rc^6*d^6*r2 + Rd^8*d^8)^1/8==========================
double Dsmooth8Coulomb3ParVar2(double r2, double r, double d, double Q, double Ra, \
       double Rc, double Rd, int E_or_F){

        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
        double Rad      = Ra * d;
        double Rcd      = Rc * d;
        double Rdd      = Rd * d;
        double Rad2     = Rad * Rad;
        double Rad2r6   = Rad2 * r6;
        double Rcd2     = Rcd * Rcd;
        double Rcd6     = Rcd2 * Rcd2 * Rcd2;
        double Rcd6r2   = Rcd6 * r2;
        double Rdd2     = Rdd * Rdd;
        double Rdd4     = Rdd2 * Rdd2;
        double Rdd8     = Rdd4 * Rdd4;
        double t8       = r8 + Rad2r6 + Rcd6r2 + Rdd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================



//E = q/(r8 + Ra^2*d^2*r6 + Rb^4*d^4*r4 + Rc^6*d^6*r2 + Rd^8*d^8)^1/8==========================
double Dsmooth8Coulomb4Par(double r2, double r, double d, double Q, double Ra, \
        double Rb, double Rc, double Rd, int E_or_F){

	double r4	= r2 * r2;
	double r6	= r2 * r4;
	double r8	= r4 * r4;
	double Rad	= Ra * d;
	double Rbd	= Rb * d;
	double Rcd	= Rc * d;
	double Rdd	= Rd * d;
        double Rad2     = Rad * Rad;
	double Rad2r6	= Rad2 * r6;
        double Rbd2     = Rbd * Rbd;
        double Rbd4     = Rbd2 * Rbd2;
	double Rbd4r4	= Rbd4 * r4;
        double Rcd2     = Rcd * Rcd;
        double Rcd6     = Rcd2 * Rcd2 * Rcd2;
	double Rcd6r2	= Rcd6 * r2;
        double Rdd2     = Rdd * Rdd;
        double Rdd4     = Rdd2 * Rdd2;
        double Rdd8     = Rdd4 * Rdd4;
        double t8       = r8 + Rad2r6 + Rbd4r4 + Rcd6r2 + Rdd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = q/(r16+ Ra^6*d^6*r10+ Rb^14*d^14*r2 + Rd^16*d^16)^1/16==========================
double Dsmooth16Coulomb3Par(double r2, double r, double d, double Q, double Ra, \
        double Rb,  double Rd, int E_or_F){

        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
//	double r10	= r4 * r6;
	double r16	= r8 * r8;
        double Ra2     = Ra * Ra;
	double Ra4	= Ra2 * Ra2;
	double Ra6     = Ra4 * Ra2;
	double Ra10	= Ra6 * Ra4;
        double Ra10r6  = Ra10 * r6;
        double Rb2     = Rb * Rb;
        double Rb4     = Rb2 * Rb2;
	double Rb6	= Rb4 * Rb2;
	double Rb12	= Rb6 * Rb6;
        double Rb12r4  = Rb12 * r4;
        double Rd2     = Rd * Rd;
        double Rd4     = Rd2 * Rd2;
        double Rd6     = Rd4 * Rd2;
	double Rd8	= Rd4 * Rd4;
	double Rd14	= Rd8 * Rd6;
	double Rd14r2	= Rd14 * r2;
	double t16 	= r16 + Ra10r6 + Rb12r4 + Rd14r2 + 1;
        double t8       = sqrt(t16);
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);
	       t	*= d;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

double Dsmooth6Coulomb2Par(double r2, double r, double d, double Q, double Ra, \
        double Rb, int E_or_F){

        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double Ra2      = Ra * Ra;
        double Ra2r4    = Ra2 * r4;
        double Rb2      = Rb * Rb;
        double Rb4      = Rb2 * Rb2;
        double Rb4r2    = Rb4 * r2;
	double t6 	= r6 + Ra2r4 + Rb4r2 + 1;
        double t3       = sqrt(t6);
        double t        = pow(t3, 0.3333333333);
	       t	*= d;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================



//E = q/(r8 + (RaRbRcRd)^2*d^2*r6 + (RbRcRd)^4*d^4*r4 + (RcRd)^6*d^6*r2 + Rd^8*d^8)^1/8==========================
double Dsmooth8Coulomb4ParC(double r2, double r, double d, double Q, double Ra, \
        double Rb, double Rc, double Rd, int E_or_F){

        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
        double Rabcd_d  = Ra * Rb * Rc * Rd * d;
        double Rbcd_d   = Rb * Rc * Rd * d;
        double Rcd_d    = Rc * Rd * d;
        double Rd_d     = Rd * d;
        double Rabcd2   = Rabcd_d * Rabcd_d;
        double Rad2r6   = Rabcd2 * r6;
        double Rbcd2    = Rbcd_d * Rbcd_d;
        double Rbcd4    = Rbcd2 * Rbcd2;
        double Rbd4r4   = Rbcd4 * r4;
        double Rcd2     = Rcd_d * Rcd_d;
        double Rcd6     = Rcd2 * Rcd2 * Rcd2;
        double Rcd6r2   = Rcd6 * r2;
        double Rdd2     = Rd_d * Rd_d;
        double Rdd4     = Rdd2 * Rdd2;
        double Rdd8     = Rdd4 * Rdd4;
        double t8       = r8 + Rad2r6 + Rbd4r4 + Rcd6r2 + Rdd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = q/(r8 + Ra^2*d^2*r6 + Rb^4*d^4*r4 + Rc^6*d^6*r2 + Rd^7*d^7 + Re^8*d^8)^1/8==========================
double Dsmooth8Coulomb5Par(double r2, double r, double d, double Q, double Ra, \
        double Rb, double Rc, double Rd, double Re, int E_or_F){

        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
        double Rad      = Ra * d;
        double Rbd      = Rb * d;
        double Rcd      = Rc * d;
        double Rdd      = Rd * d;
	double Red	= Re * d;
        double Rad2     = Rad * Rad;
        double Rad2r6   = Rad2 * r6;
        double Rbd2     = Rbd * Rbd;
        double Rbd4     = Rbd2 * Rbd2;
        double Rbd4r4   = Rbd4 * r4;
        double Rcd2     = Rcd * Rcd;
        double Rcd6     = Rcd2 * Rcd2 * Rcd2;
        double Rcd6r2   = Rcd6 * r2;
	double Rdd2	= Rdd * Rdd;
	double Rdd4	= Rdd2 * Rdd2;
	double Rdd7	= Rdd2 * Rdd4 * Rdd;
	double Rdd7r	= Rdd7 * r; 
        double Red2     = Red * Red;
        double Red4     = Red2 * Red2;
        double Red8     = Red4 * Red4;
        double t8       = r8 + Rad2r6 + Rbd4r4 + Rcd6r2 + Rdd7r + Red8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = q/(r8 + Ra^2*d^2*r6 + Rb^4*d^4*r4 + Rc^5*d^5*r3 + Rd^6*d^6*r2 + Re^7*e^7 + Rf^8*f^8)^1/8==========================
double Dsmooth8Coulomb6Par(double r2, double r, double d, double Q, double Ra, \
        double Rb, double Rc, double Rd, double Re, double Rf, int E_or_F){

        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
	double r3	= r2 * r;
        double Rad      = Ra * d;
        double Rbd      = Rb * d;
        double Rcd      = Rc * d;
        double Rdd      = Rd * d;
        double Red      = Re * d;
	double Rfd	= Rf * d;
        double Rad2     = Rad * Rad;
        double Rad2r6   = Rad2 * r6;
        double Rbd2     = Rbd * Rbd;
        double Rbd4     = Rbd2 * Rbd2;
        double Rbd4r4   = Rbd4 * r4;
        double Rdd2     = Rdd * Rdd;
        double Rdd6     = Rdd2 * Rdd2 * Rdd2;
        double Rdd6r2   = Rdd6 * r2;
	double Rcd2	= Rcd * Rcd;
	double Rcd4	= Rcd2 * Rcd2;
	double Rcd5	= Rcd4 * Rcd;
	double Rcd5r3	= Rcd5 * r3;
        double Red2     = Red * Red;
        double Red4     = Red2 * Red2;
        double Red7     = Red2 * Red4 * Red;
        double Red7r    = Red7 * r;
        double Rfd2     = Rfd * Rfd;
        double Rfd4     = Rfd2 * Rfd2;
        double Rfd8     = Rfd4 * Rfd4;
        double t8       = r8 + Rad2r6 + Rbd4r4 + Rcd5r3 + Rdd6r2 + Red7r + Rfd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================

//E = q/(r8 + Ra^2*d^2*r6 + Rb^4*d^4*r4 + Rc^6*d^6*r2 + Rd^8*d^8)^1/8==========================
double Dsmooth8Coulomb5ParVariant1(double r2, double r, double dd, double Q, double Ra, \
        double Rb, double Rc, double Rd, double rho, int E_or_F){

	double d	= dd + rho;
        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
        double Rad      = Ra * d;
        double Rbd      = Rb * d;
        double Rcd      = Rc * d;
        double Rdd      = Rd * d;
        double Rad2     = Rad * Rad;
        double Rad2r6   = Rad2 * r6;
        double Rbd2     = Rbd * Rbd;
        double Rbd4     = Rbd2 * Rbd2;
        double Rbd4r4   = Rbd4 * r4;
        double Rcd2     = Rcd * Rcd;
        double Rcd6     = Rcd2 * Rcd2 * Rcd2;
        double Rcd6r2   = Rcd6 * r2;
        double Rdd2     = Rdd * Rdd;
        double Rdd4     = Rdd2 * Rdd2;
        double Rdd8     = Rdd4 * Rdd4;
        double t8       = r8 + Rad2r6 + Rbd4r4 + Rcd6r2 + Rdd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================


//E = q (r + Re*d) / (r^8 + r^6 * d^2 * Ra^2 + r^4 * d^4 * Rb^4 + r^2 * d^6 * Rc^6 + Rd^8 * d^8)^1/4=====
double Dnonmono8Coulomb5ParVariant1(double r2, double r, double di, double dj, double Q, double Ra, double Rb, \
        double Rc, double Re, double Rf, double rho, int E_or_F){
	
	double die = di + rho;
	double dje = dj + rho;
	double di2 = die * die;
	double dj2 = dje * dje;
	double d2  = di2 + dj2;
	double d   = sqrt(d2);

        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
        double Rad      = Ra * d;
        double Rbd      = Rb * d;
        double Rcd      = Rc * d;
        double Red      = Re * d;
        double Rfd      = Rf * d;
        double Rad2     = Rad * Rad;
        double Rbd2     = Rbd * Rbd;
        double Rbd4     = Rbd2 * Rbd2;
        double Rcd2     = Rcd * Rcd;
        double Rcd4     = Rcd2 * Rcd2;
        double Rcd6     = Rcd2 * Rcd4;
        double Red2     = Red * Red;
        double Red4     = Red2 * Red2;
        double Red8     = Red4 * Red4;
        double Rad2r6   = Rad2 * r6;
        double Rbd4r4   = Rbd4 * r4;
        double Rcd6r2   = Rcd6 * r2;
        double u     = Rfd + r;
        double l4    = r8 + Rad2r6 + Rbd4r4 + Rcd6r2 + Red8;
        double l2    = sqrt(l4);
        double l     = sqrt(l2);
        double t     = u / l;

        if (E_or_F == ENERGY){          //ENERGY
//	printf("Parameters are: R2 %f R4 %f R6 %f R8 %f and numerator %f\n",Ra,Rb,Rc,Re,Rf);
                return (double) (Q * t);

        }
        else{
                return 0;
        }
}
//=============================================================================


//E = q (r + Rf*d) / (r^8 + r^6 * d^2 * Ra^2 + r^4 * d^4 * Rb^4 + r^2 * d^6 * Rc^6 + Rd^7* d^7*r +Re^8 * d^8 )^1/4=====
double Dnonmono8Coulomb6Par(double r2, double r, double d, double Q, double Ra, double Rb, \
        double Rc, double Rd, double Re, double Rf, int E_or_F){

        double r4       = r2 * r2;
        double r6       = r2 * r4;
        double r8       = r4 * r4;
        double Rad      = Ra * d;
        double Rbd      = Rb * d;
        double Rcd      = Rc * d;
        double Rdd      = Rd * d;
	double Red	= Re * d;
	double Rfd	= Rf * d;
        double Rad2 	= Rad * Rad;
        double Rbd2 	= Rbd * Rbd;
        double Rbd4	= Rbd2 * Rbd2;
        double Rcd2	= Rcd * Rcd;
        double Rcd4	= Rcd2 * Rcd2;
        double Rcd6	= Rcd2 * Rcd4;
        double Rdd2	= Rdd * Rdd;
        double Rdd4	= Rdd2 * Rdd2;
        double Rdd7	= Rdd2 * Rdd4 * Rdd;
        double Red2	= Red * Red;
        double Red4	= Red2 * Red2;
        double Red8	= Red4 * Red4;
        double Rad2r6 	= Rad2 * r6;
        double Rbd4r4 	= Rbd4 * r4;
        double Rcd6r2 	= Rcd6 * r2;
        double Rdd7r 	= Rdd7 * r;
        double u     = Rfd + r;
        double l4    = r8 + Rad2r6 + Rbd4r4 + Rcd6r2 + Rdd7r + Red8;
        double l2    = sqrt(l4);
        double l     = sqrt(l2);
        double t     = u / l;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q * t;

        }
        else{
                return 0;
        }
}
//=============================================================================


//E = q(r-Rc)/(r^2 + Ra * r + Rb^2)============================================
double nonmono2Coulomb3Par(double r2, double r, double Q, double Ra, double Rb, \
	double Rc, int E_or_F){

	double Rar = Ra * r;
	double Rb2 = Rb * Rb;
	double u   = r - Rc;
	double l   = r2 + Rar + Rb2;
	double t   = u / l;

	if (E_or_F == ENERGY){		//ENERGY
		return (double) Q * t;
	}
	else {				// FORCE / DISTANCE
		double l2 = l * l;
		double ac_b = Ra * Rc + Rb2;
		double u_ = r - 2 * Rc - ac_b / r;
		double t_ = u_ / l2;
		return (double) (-Q) * t_;
	}
}
//============================================================================

//E = q(r+Rc)/(r^2 + Ra * r + Rb^2)============================================
double nonmono2Coulomb3ParVariant1(double r2, double r, double Q, double Ra, double Rb, \
        double Rc, int E_or_F){

        double Rar = Ra * r;
        double Rb2 = Rb * Rb;
        double u   = r + Rc;
        double l   = r2 + Rar + Rb2;
        double t   = u / l;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q * t;
        }
        else {                          // FORCE / DISTANCE
                double l2 = l * l;
                double ac_b = Ra * Rc - Rb2;
                double u_ = r + 2 * Rc + ac_b / r;
                double t_ = u_ / l2;
                return (double) (-Q) * t_;
        }
}
//=============================================================================

//E = q(r + Rc) / (r^4 + Ra^2 * r^2 + Rb^4)^1/2================================
double nonmono4Coulomb3Par(double r2, double r, double Q, double Ra, double Rb, \
	double Rc, int E_or_F){

	double r4 = r2 * r2;	
	double Ra2 = Ra * Ra;
	double Ra2r2 = Ra2 * r2;
	double Rb2 = Rb * Rb;
	double Rb4 = Rb2 * Rb2;
	double l2 = r4 + Ra2r2 + Rb4;
	double l  = sqrt(l2);
	double u  = r + Rc;
	double t  = u / l;

	if (E_or_F == ENERGY){		//ENERGY
		return (double) Q * t;
	}
	else {				// FORCE / DISTANCE
		double l3 = l * l2;
		double e  = 2 * r2 + Ra / 2;
		double u_ = u * e - l2;
		double t_ = u_ / l3;
		return (double) (-Q) * t_;	
	}
}
//=============================================================================

//E = q (r + Re) / (r^4 + r^3 * Ra + r^2 * Rb^2 + r * Rc^3 + Rd^4)^1/2=========
double nonmono4Coulomb5Par(double r2, double r, double Q, double Ra, double Rb, \
	double Rc, double Rd, double Re, int E_or_F){

	double r4 = r2 * r2;
	double r3 = r2 * r;
	double Rb2 = Rb * Rb;
	double Rc3 = Rc * Rc * Rc;
	double Rd2 = Rd * Rd;
	double Rd4 = Rd2 * Rd2;
	double u   = r + Re;
	double r3Ra = r3 * Ra;
	double r2Rb2= r2 * Rb2;
	double rRc3 = r * Rc3;
	double l2   = r4 + r3Ra + r2Rb2 + rRc3 + Rd4;
	double l    = sqrt(l2);
	double t    = u / l;

	if (E_or_F == ENERGY){		//ENERGY
		return (double) Q * t;
	}
	else {				// FORCE / DISTANCE
		double l3 = l * l2;
		double Rc3_2r= Rc3 / (2 * r);
		double e  = 2 * r2 + 1.5 * r * Ra + Rb2 + Rc3_2r;
                double u_ = u * e - l2;
                double t_ = u_ / l3;
                return (double) (-Q) * t_;
        }
}
//=============================================================================

//E = q (r + Re) / (r^8 + r^6 * Ra^2 + r^4 * Rb^4 + r^2 * Rc^6 + Rd^8)^1/4=====
double nonmono8Coulomb5Par(double r2, double r, double Q, double Ra, double Rb, \
	double Rc, double Rd, double Re, int E_or_F){

	double r4 = r2 * r2;
	double r8 = r4 * r4;
	double r6 = r4 * r2;
	double Ra2 = Ra * Ra;
	double Rb2 = Rb * Rb;
	double Rb4 = Rb2 * Rb2;
	double Rc2 = Rc * Rc;
	double Rc4 = Rc2 * Rc2;
	double Rc6 = Rc2 * Rc4;
	double Rd2 = Rd * Rd;
	double Rd4 = Rd2 * Rd2;
	double Rd8 = Rd4 * Rd4;
	double r6Ra2 = r6 * Ra2;
	double r4Rb4 = r4 * Rb4;
	double r2Rc6 = r2 * Rc6;
	double u     = r + Re;
	double l4    = r8 + r6Ra2 + r4Rb4 + r2Rc6 + Rd8;
	double l2    = sqrt(l4);
	double l     = sqrt(l2);
	double t     = u / l;

	if (E_or_F == ENERGY){		//ENERGY
		return (double) Q * t;
	
	}
	else{
		return 0;
	}
}
//=============================================================================

//E = q(r + Re) / (r^8 + r^4 * Ra^4 + r^2 * Rb^6 + r * Rc^7 + Rd^8)^1/4========
double nonmono8Coulomb5ParVariant1(double r2, double r, double Q, double Ra, \
	double Rb, double Rc, double Rd, double Re, int E_or_F){

        double r4 = r2 * r2;
        double r8 = r4 * r4;
        double Ra2 = Ra * Ra;
	double Ra4 = Ra2 * Ra2;
        double Rb2 = Rb * Rb;
        double Rb4 = Rb2 * Rb2;
	double Rb6 = Rb2 * Rb4;
        double Rc2 = Rc * Rc;
        double Rc4 = Rc2 * Rc2;
        double Rc7 = Rc2 * Rc4 * Rc;
        double Rd2 = Rd * Rd;
        double Rd4 = Rd2 * Rd2;
        double Rd8 = Rd4 * Rd4;
        double r4Ra4 = r4 * Ra4;
        double r2Rb6 = r2 * Rb6;
        double rRc7 = r * Rc7;
        double u     = r + Re;
        double l4    = r8 + r4Ra4 + r2Rb6 + rRc7 + Rd8;
        double l2    = sqrt(l4);
        double l     = sqrt(l2);
        double t     = u / l;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q * t;

        }
        else{
                return 0;
        }
}
//=============================================================================
//E = q (r + Re) / (r^8 + r^6 * Ra^2 + r^4 * Rb^4 + r^2 * Rc^6 + Rd^8)^1/4=====
double nonmono8Coulomb6Par(double r2, double r, double Q, double Ra, double Rb, \
        double Rc, double Rd, double Re, double Rf, int E_or_F){

        double r4 = r2 * r2;
        double r8 = r4 * r4;
        double r6 = r4 * r2;
        double Ra2 = Ra * Ra;
        double Rb2 = Rb * Rb;
        double Rb4 = Rb2 * Rb2;
        double Rc2 = Rc * Rc;
        double Rc4 = Rc2 * Rc2;
        double Rc6 = Rc2 * Rc4;
	double Rd2 = Rd * Rd;
	double Rd4 = Rd2 * Rd2;
	double Rd7 = Rd2 * Rd4 * Rd;
        double Re2 = Re * Re;
        double Re4 = Re2 * Re2;
        double Re8 = Re4 * Re4;
        double r6Ra2 = r6 * Ra2;
        double r4Rb4 = r4 * Rb4;
        double r2Rc6 = r2 * Rc6;
	double rRd7  = r * Rd7;
        double u     = r + Rf;
        double l4    = r8 + r6Ra2 + r4Rb4 + r2Rc6 + rRd7 + Re8;
        double l2    = sqrt(l4);
        double l     = sqrt(l2);
        double t     = u / l;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q * t;

        }
        else{
                return 0;
        }
}
//=============================================================================


//E = q/(r + R) ===============================================================
double shiftedCoulomb(double r2, double r, double Q, double R, int E_or_F){

        //double r = sqrt(r2);
        double t = r + R;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                double t2  = t * t;
		double t2r = t2 * r;
                return (double) (-Q) / t2r;
        }
}
//=============================================================================

//E = q/(r^1/2 + R^1/2)^2 =========================================================
double root2Coulomb1Par(double r2, double r, double Q, double R, int E_or_F){

        double r_2 = sqrt(r);
        double R_2 = sqrt(R);
        double t_2 = r_2 + R_2;
        double t  = t_2 * t_2;

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                double t_3 = t_2 * t;
                double r_3 = r * r_2;
                double t_r = t_3 * r_3;
                return (double) (-Q) / t_r;
        }
}

//=============================================================================

//E = q/(r2 + R2)^1/2 =========================================================
double smooth2Coulomb1Par(double r2, double r, double Q, double R, int E_or_F){

        double t2 = r2 + R * R;
        double t  = sqrt(t2);

        if (E_or_F == ENERGY){		//ENERGY
                return (double) Q / t;
        }
        else{				//FORCE / DISTANCE
                double t3 = t2 * t;
                return (double) (-Q) / t3;
        }
}
//=============================================================================

//E = q/(r + Ra^1/2 * r^1/2 + Rb)==================================================
double smoothCoulomb2Par(double r2, double r, double Q, double Ra, \
        double Rb, int E_or_F){

	double r_2 = sqrt(r);
	double Ra_2= sqrt(Ra);
        double Rar_2 = Ra_2 * r_2;
        double t  = r + Rar_2 + Rb;

        if(E_or_F == ENERGY){           //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//============================================================================= 

//E = q/(r2 + K * R * r + R2)^1/2==============================================
double smooth2Coulomb2Par(double r2, double r, double Q, double R, double K, \
	int E_or_F){

        //double r   = sqrt(r2);
        double R2  = R * R;
	double KR  = K * R;
        double KRr = KR * r;
        double t2  = r2 + KRr + R2;
	double t   = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                double t3   = t2 * t;
		double KR_r = KR / r;	
		double u    = 1 + .5 * KR_r;
                return (double) (-Q) * u / t3;
        }
}
//=============================================================================

//E = q/(r2 + Ra * r + Rb2)^1/2================================================
double smooth2Coulomb2ParVariant1(double r2, double r, double Q, double Ra, \
	double Rb, int E_or_F){

	double Rb2 = Rb * Rb;
	double Rar = Ra * r;
	double t2  = r2 + Rar + Rb2;
	double t   = sqrt(t2);

	if(E_or_F == ENERGY){		//ENERGY
		return (double) Q / t;
	}
	else{				//FORCE / DISTANCE
		double t3 = t2 * t;
		double Ra_r = Ra / r;
		double u  = 1 + 0.5 * Ra_r;
		return (double) (-Q) * u / t3;
	}
}
//============================================================================= 

//E = q/(r4 + R4)^1/4 =========================================================
double smooth4Coulomb1Par(double r2, double r, double Q, double R, int E_or_F){

	double r4 = r2 * r2;
	double R2 = R * R;
	double R4 = R2 * R2;
        double t4 = r4 + R4;
	double t2 = sqrt(t4);
	double t  = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{ 				//FORCE / DISTANCE
		double t5 = t4 * t;
		return (double) (-Q) * r2 / t5; 
	}
}
//=============================================================================

//E = q/(r4 + K * R2 * r2 + R4)^1/4 ===========================================
double smooth4Coulomb2Par(double r2, double r, double Q, double R, double K, \
	int E_or_F){

	double r4    = r2 * r2;
        double R2    = R * R;
	double R4    = R2 * R2;
	double KR2r2 = K * r2 * R2;
        double t4    = r4 + KR2r2 + R4;
        double t2    = sqrt(t4);
        double t     = sqrt(t2);

        if (E_or_F == ENERGY){		//ENERGY
                return (double) Q / t;
        }
        else{				//FORCE / DISTANCE
                double u2 = r2 + .5 * K * R2;
                double t5 = t4 * t;
                return (double) (-Q) * u2 / t5;
        }
}
//=============================================================================

//E = q/(r4 + K * R3 * r + R4)^1/4 ============================================
double smooth4Coulomb2ParVariant1(double r2, double r, double Q, double R, \
	double K, int E_or_F){
	
	//double r     = sqrt(r2);
        double r4    = r2 * r2;
        double R2    = R * R;
	double R3    = R2 * R;
        double R4    = R2 * R2;
        double kR3r1 = K * R3 * r;
        double t4    = r4 + kR3r1 + R4;
        double t2    = sqrt(t4);
        double t     = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
		double KR3_1 = K * R3 / r;
		double u2    = r2 + 0.25 * KR3_1;	
		double t5    = t4 * t;
		return (double) (-Q) * u2 / t5;
        }  
}
//=============================================================================

//E = q/(r4 + K * r2 + R4)^1/4 ================================================
double smooth4Coulomb2ParVariant2(double r2, double r, double Q, double R, \
	double K, int E_or_F){

        double r4    = r2 * r2;
        double R2    = R * R;
        double R4    = R2 * R2;
	double Kr2   = K * r2;
        double t4    = r4 + Kr2 + R4;
        double t2    = sqrt(t4);
        double t     = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                double u2 = r2 + .5 * K;
                double t5 = t4 * t;
                return (double) (-Q) * u2 / t5;
        }
}
//=============================================================================

//E = q/(r8 + K * R4 * r4 + R8)^1/8 ===========================================
double smooth8Coulomb2Par(double r2, double r, double Q, double R, double K, \
	int E_or_F){

        double r4  = r2 * r2;
	double r8  = r4 * r4;
	double R2  = R * R;
	double R4  = R2 * R2;
        double R8  = R4 * R4;
	double KR4r4 = K * R4 * r4;
        double t8 = r8 + KR4r4 + R8;
        double t4 = sqrt(t8);
        double t2 = sqrt(t4);
        double t  = sqrt(t2);

        if (E_or_F == ENERGY){		//ENERGY
                return (double) Q / t;
        }
        else{				//FORCE / DISTANCE
		double r6 = r4 * r2;
                double u6 = r6 + .5 * K * R4 * r2;
                double t9 = t8 * t;
                return (double) (-Q) * u6 / t9;
        }

}
//=============================================================================

//E = q/(r8 + K * R6 * r2 + R8)^1/8============================================
double smooth8Coulomb2ParVariant1(double r2, double r, double Q, double R, \
	double K, int E_or_F){

        double r4    = r2 * r2;
        double r8    = r4 * r4;
        double R2    = R * R;
        double R4    = R2 * R2;
	double R6    = R4 * R2;
        double R8    = R4 * R4;
        double kR6r2 = K * R6 * r2;
        double t8    = r8 + kR6r2 + R8;
        double t4    = sqrt(t8);
        double t2    = sqrt(t4);
        double t     = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
		double r6 = r4 * r2;
		double u6 = r6 + .25 * K * R6;
		double t9 = t8 * t;
		return (double) (-Q) * u6 / t9;
	}
}
//=============================================================================

//E = q/(r8 + K * R2 * r6 + R8)^1/8============================================
double smooth8Coulomb2ParVariant2(double r2, double r, double Q, double R, \
	double K, int E_or_F){

        double r4    = r2 * r2;
	double r6    = r2 * r4;
        double r8    = r4 * r4;
        double R2    = R * R;
        double R4    = R2 * R2;
        double R8    = R4 * R4;
        double kR2r6 = K * R2 * r6;
        double t8    = r8 + kR2r6 + R8;
        double t4    = sqrt(t8);
        double t2    = sqrt(t4);
        double t     = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                double r6 = r4 * r2;
                double u6 = r6 + .75 * K * R2 * r4;
                double t9 = t8 * t;
                return (double) (-Q) * u6 / t9;
        }
}
//=============================================================================

//E = q/(r8 + K * r4 + R8)^1/8 ================================================
double smooth8Coulomb2ParVariant3(double r2, double r, double Q, double R, \
	double K, int E_or_F){

        double r4  = r2 * r2;
        double r8  = r4 * r4;
        double R2  = R * R;
        double R4  = R2 * R2;
        double R8  = R4 * R4;
        double Kr4 = K * r4;
        double t8  = r8 + Kr4 + R8;
        double t4  = sqrt(t8);
        double t2  = sqrt(t4);
        double t   = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                double r6 = r4 * r2;
                double u6 = r6 + .5 * K * r2;
                double t9 = t8 * t;
                return (double) (-Q) * u6 / t9;
        }

}
//=============================================================================

//E = q/(r8 + Ra^4 * r4 + Rb^8)^1/8 ===========================================
double smooth8Coulomb2ParVariant4(double r2, double r, double Q, double Ra, \
	double Rb, int E_or_F){

        double r4    = r2 * r2;
        double r8    = r4 * r4;
	double Ra2   = Ra * Ra; 
	double Ra4   = Ra2 * Ra2;
	double Ra4r4 = Ra4 * r4;
	double Rb2   = Rb * Rb;
	double Rb4   = Rb2 * Rb2;
	double Rb8   = Rb4 * Rb4;
	double t8    = r8 + Ra4r4 + Rb8;
        double t4    = sqrt(t8);
        double t2    = sqrt(t4);
        double t     = sqrt(t2);
	
        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                double r6 = r4 * r2;
                double u6 = r6 + .5 * Ra4 * r2;
                double t9 = t8 * t;
                return (double) (-Q) * u6 / t9;
	}

}
//=============================================================================

//E = q/(r8 + Ra2 * r6 + Rb4 * r4 + Rc6 * r2)^1/8==============================
double smooth8Coulomb3Par(double r2, double r, double Q, double Ra, double Rb, \
	double Rc, int E_or_F){

        double r4    = r2 * r2;
	double r6    = r4 * r2;
        double r8    = r4 * r4;
        double Ra2   = Ra * Ra;
        double Rb2   = Rb * Rb;
	double Rb4   = Rb2 * Rb2;
        double Rc2   = Rc * Rc;
	double Rc6   = Rc2 * Rc2 * Rc2;
	double Ra2r6 = Ra2 * r6;
	double Rb4r4 = Rb4 * r4;
	double Rc6r2 = Rc6 * r2;
        double t8    = r8 + Ra2r6 + Rb4r4 + Rc6r2;
        double t4    = sqrt(t8);
        double t2    = sqrt(t4);
        double t     = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
		double Ra2r4 = Ra2 * r4;	
		double Rb4r2 = Rb4 * r2;
		double u6 = r6 + 0.75 * Ra2r4 + 0.50 * Rb4r2 + 0.25 * Rc6;
		double t9 = t8 * t;
		return (double) (-Q) * u6 / t9;
	}
}
//=============================================================================

//E = q/(r8 + Ka*r4 + Ka*Kb*r2 + Ka*Kb*Kc)^1/8=================================
double smooth8Coulomb3ParVariant1(double r2, double r, double Q, double Ka, \
	double Kb, double Kc, int E_or_F){

        double r4       = r2 * r2;
        double r8       = r4 * r4;
        double Kar4     = Ka * r4;
        double KaKb     = Ka * Kb;
        double KaKbr2   = KaKb * r2;
        double KaKbKc   = KaKb * Kc;
        double t8       = r8 + Kar4 + KaKbr2 + KaKbKc;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                double Kar2 = Ka * r2;
		double r6   = r4 * r2;
                double u6   = r6 + 0.50 * Kar2 + 0.25 * KaKb;
                double t9   = t8 * t;
                return (double) (-Q) * u6 / t9;
        }
}
//=============================================================================

//E = q/(r8 + Ka*r4 + Ka*Kb*r2 + R*8)^1/8======================================
double smooth8Coulomb3ParVariant2(double r2, double r, double Q, double Ka, \
	double Kb, double R, int E_or_F){

        double r4       = r2 * r2;
        double r8       = r4 * r4;
        double Kar4     = Ka * r4;
        double KaKb     = Ka * Kb;
        double KaKbr2   = KaKb * r2;
        double R2       = R * R;
	double R4       = R2 * R2;
	double R8       = R4 * R4;
        double t8       = r8 + Kar4 + KaKbr2 + R8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                double Kar2 = Ka * r2;
                double r6   = r4 * r2;
                double u6   = r6 + 0.50 * Kar2 + 0.25 * KaKb;
                double t9   = t8 * t;
                return (double) (-Q) * u6 / t9;
        }
}
//=============================================================================

//E = q/(r8 + Ra^4*r4 + Rb^6*r2 + Rc^8)^1/8====================================
double smooth8Coulomb3ParVariant3(double r2, double r, double Q, double Ra, \
	double Rb, double Rc, int E_or_F){

        double r4      = r2 * r2;
        double r8      = r4 * r4;
        double Ra2     = Ra * Ra;
        double Ra4     = Ra2 * Ra2;
	double Ra4r4   = Ra4 * r4;
	double Rb2     = Rb * Rb;
	double Rb6     = Rb2 * Rb2 * Rb2;
	double Rb6r2   = Rb6 * r2;
	double Rc2     = Rc * Rc;
	double Rc4     = Rc2 * Rc2;
	double Rc8     = Rc4 * Rc4;
	double t8      = r8 + Ra4r4 + Rb6r2 + Rc8;
	double t4      = sqrt(t8);
	double t2      = sqrt(t4);
	double t       = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
		double Ra4r2 = Ra4 * r2;
		double r6    = r4 * r2;
		double u6    = r6 + 0.50 * Ra4r2 + 0.25 * Rb6; 
		double t9    = t8 * t;
		return (double) (-Q) * u6 / t9;
	}
}

//=============================================================================

//E = q/(r8 + Ka*r6 + Ka*Kb*r4 + Ka*Kb*Kc*r2 + Ka*Kb*Kc*Kd)^1/8================
double smooth8Coulomb4Par(double r2, double r, double Q, double Ka, double Kb, \
	double Kc, double Kd, int E_or_F){
	
	double r4       = r2 * r2;
	double r6       = r4 * r2;
	double r8       = r4 * r4;
	double Kar6     = Ka * r6;
	double KaKb     = Ka * Kb;
	double KaKbr4   = KaKb * r4;
	double KaKbKc   = KaKb * Kc;
	double KaKbKcr2 = KaKbKc * r2;
	double KaKbKcKd = KaKbKc * Kd;
	double t8       = r8 + Kar6 + KaKbr4 + KaKbKcr2 + KaKbKcKd;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
	}
        else{                           //FORCE / DISTANCE
		double Kar4 = Ka * r4;
		double KaKbr2 = Ka * Kb * r2;
		double u6 = r6 + 0.75 * Kar4 + 0.50 * KaKbr2 + 0.25 * KaKbKc;
		double t9 = t8 * t;
		return (double) (-Q) * u6 / t9;
	}
}
//=============================================================================

//E = q/(r8 + Ra^2*r6 + Rb^4*r4 + Rc^6*r2 + Rd^8)^1/8==========================
double smooth8Coulomb4ParVariant1(double r2, double r, double Q, double Ra, \
	double Rb, double Rc, double Rd, int E_or_F){

	double r4       = r2 * r2;
	double r6       = r4 * r2;
	double r8       = r4 * r4;
	double Ra2      = Ra * Ra;
	double Ra2r6    = Ra2 * r6;
	double Rb2      = Rb * Rb;
	double Rb4      = Rb2 * Rb2;
	double Rb4r4    = Rb4 * r4;
	double Rc2      = Rc * Rc;
	double Rc6      = Rc2 * Rc2 * Rc2;
	double Rc6r2    = Rc6 * r2;	
	double Rd2      = Rd * Rd;
	double Rd4      = Rd2 * Rd2;
	double Rd8      = Rd4 * Rd4;
	double t8       = r8 + Ra2r6 + Rb4r4 + Rc6r2 + Rd8;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);
	
        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
	}
        else{                           //FORCE / DISTANCE
		double Ra2r4 = Ra2 * r4;
		double Rb4r2 = Rb4 * r2;
		double u6    = r6 + 0.75 * Ra2r4 + 0.50 * Rb4r2 + 0.25 * Rc6;	
		double t9    = t8 * t;
		return (double) (-Q) * u6 / t9;
	}
}
//E = q/(r8 + Ra*r^4 + Rb^2*r^2 + Rc^4*r + Rd^8)^1/8==========================
double smooth8Coulomb4ParVariant2(double r2, double r, double Q, double Ra, \
	double Rb, double Rc, double Rd, int E_or_F){

	double r4 	= r2 * r2;
	double r8 	= r4 * r4;
	double Ra2	= Ra * Ra;
	double Ra4	= Ra2 * Ra2;
	double Ra4r4	= Ra4 * r4;
	double Rb2	= Rb * Rb;
	double Rb4	= Rb2 * Rb2;
	double Rb6	= Rb2 * Rb4;
	double Rb6r2	= Rb6 * r2;
	double Rc2	= Rc * Rc;
	double Rc4	= Rc2 * Rc2;
	double Rc7	= Rc2 * Rc4 * Rc;
	double Rc7r	= Rc7 * r;
	double Rd2	= Rd * Rd;
	double Rd4	= Rd2 * Rd2;
	double Rd8	= Rd4 * Rd4; 
	double t8	= r8 + Ra4r4 + Rb6r2 + Rc7r + Rd8;
	double t4 	= sqrt(t8);
	double t2	= sqrt(t4);
	double t	= sqrt(t2);

	if (E_or_F == ENERGY){ //ENERGY
		return (double) Q / t;
	}
	else{		// FORCE / DISTANCE
		double r6	= r4 * r2;
		double Ra4r2	= Ra4 * r2;
		double Rc7r	= Rc7 / r;
		double u6	= r6 + 0.5 * Ra4r2 + 0.25 * Rb6 + 0.125 * Rc7r;
		double t9	= t8 * t;
		return (double) (-Q) * u6 / t9;
	}
}

//E = q/(r16 + Ka*r4 + Ka*Kb*r2 + Ka*Kb*Kc)^1/16===============================
double smooth16Coulomb3Par(double r2, double r, double Q, double Ka, double Kb, \
	double Kc, int E_or_F){

        double r4       = r2 * r2;
        double r8       = r4 * r4;
        double r16      = r8 * r8;
        double Kar4     = Ka * r4;
        double KaKb     = Ka * Kb;
        double KaKbr2   = KaKb * r2;
        double KaKbKc   = KaKb * Kc;
        double t16      = r16 + Kar4 + KaKbr2 + KaKbKc;
        double t8       = sqrt(t16);
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
                double r14    = r16 / r2;
                double Kar2   = Ka * r2;
                double u14 = r14 + 0.25 * Kar2 + 0.125 * KaKb;
                double t17 = t16 * t;
                return (double) (-Q) * u14 / t17;
        }
}
//=============================================================================

//E = q/(r16 + Ka*r8 + Ka*Kb*r4 + Ka*Kb*Kc*r2 + Ka*Kb*Kc*Kd)^1/16==============
double smooth16Coulomb4Par(double r2, double r, double Q, double Ka, double Kb, \
	double Kc, double Kd, int E_or_F){

        double r4       = r2 * r2;
        double r8       = r4 * r4;
        double r16      = r8 * r8;
        double Kar8     = Ka * r8;
        double KaKb     = Ka * Kb;
        double KaKbr4   = KaKb * r4;
        double KaKbKc   = KaKb * Kc;
        double KaKbKcr2 = KaKbKc * r2;
        double KaKbKcKd = KaKbKc * Kd;
        double t16      = r16 + Kar8 + KaKbr4 + KaKbKcr2 + KaKbKcKd;
        double t8       = sqrt(t16);
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY){          //ENERGY
                return (double) Q / t;
        }
        else{                           //FORCE / DISTANCE
		double r6     = r4 * r2;
		double r14    = r8 * r6;
                double Kar6   = Ka * r6;
                double KaKbr2 = KaKb * r2;
                double u14 = r14 + 0.50 * Kar6 + 0.25 * KaKbr2 + 0.125 * KaKbKc;
                double t17 = t16 * t;
                return (double) (-Q) * u14 / t17;
        }
}
//=============================================================================


//E = 1/d1^2  exp ( -(r/d2))===================================================
double Dexclusion1Gaussian(double r2, double r, double d1, double d2, int E_or_F){

	double d1_2= d1 * d1;
	double id2 = 1. / d1_2;
	double rd = r / d2;
	double c = exp(-rd);

        if (E_or_F == ENERGY){          //ENERGY
                return id2 * c;
        }
        else{                           //FORCE / DISTANCE
                return 0.0;
        }
}


//E = 1/d1^2  exp ( -(r/d2)^2)===================================================
double DexclusionGaussian(double r2, double r, double d1, double d2, int E_or_F){

        double d1_2= d1 * d1;
        double id2 = 1. / d1_2;
        double rd = r / d2;
	double rd2= rd * rd;
        double c = exp(-rd2);

        if (E_or_F == ENERGY){          //ENERGY
                return id2 * c;
        }
        else{                           //FORCE / DISTANCE
                return 0.0;
        }
}

//E = 1/d1^2  exp ( -(r/d2)^2)===================================================
double DexclusionGaussianReff(double r2, double r, double d, double X, double T1, int E_or_F){

	double d2 = d * d;
	double T1_2 = T1 * T1;
	double T1r2 = T1_2 * r2;
        double c = exp(-T1r2);

        if (E_or_F == ENERGY){          //ENERGY
                return EkeConst*X*c/d2;
        }
        else{                           //FORCE / DISTANCE
                return 0.0;
        }
}

//E = 1/d1^2  exp ( -(r/d2)^2)===================================================
double DexclusionGaussianReff1Par(double r2, double r, double d, double X, int E_or_F){

        double d2 = d * d;
        double c = exp(-r2);

        if (E_or_F == ENERGY){          //ENERGY
                return X*c/d2;
        }
        else{                           //FORCE / DISTANCE
                return 0.0;
        }
}

//E = 1/d1^2 [1-(T1*reff)^2] [1-(T2*reff)^2]  exp ( -(T3*reff)^2)===================================================
double Dexclusion2CrossGaussianReff(double r2, double r, double d, double X, double T1, double T2, double T3, int E_or_F){

        double d2 = d * d;
        double T1_2 = T1 * T1;
	double T2_2 = T2 * T2;
	double T3_2 = T3 * T3;
        double T1r2 = T1_2 * r2;
        double T2r2 = T2_2 * r2;
        double T3r2 = T3_2 * r2;
	double cross1 = 1 - T1r2;
	double cross2 = 1 - T2r2;
        double c = exp(-T3r2);

        if (E_or_F == ENERGY){          //ENERGY
                return EkeConst*X*cross1*cross2*c/d2;
        }
        else{                           //FORCE / DISTANCE
                return 0.0;
        }
}


//E = 1/d1^2 [1-(T1*reff)^4] [1-(T2*reff)^4]  exp ( -(T3*reff)^2)===================================================
double Dexclusion2CrossPow4GaussianReff(double r2, double r, double d, double X, double T1, double T2, double T3, int E_or_F){

        double d2 = d * d;

        double T1r = T1 * r;
        double T2r = T2 * r;

        double T1r_2 = T1r * T1r;
        double T2r_2 = T2r * T2r;

	double T1r_4 = T1r_2 * T1r_2;
	double T2r_4 = T2r_2 * T2r_2;

        double T3_2 = T3 * T3;
        double T3r2 = T3_2 * r2;

        double cross1 = 1. - T1r_4;
        double cross2 = 1. - T2r_4;
        double c = exp(-T3r2);

        if (E_or_F == ENERGY){          //ENERGY
                return EkeConst*X*cross1*cross2*c/d2;
        }
        else{                           //FORCE / DISTANCE
                return 0.0;
        }
}


//E = 1/d1^2 [1-(T1*reff)^2] [1-(T2*reff)^2]  exp ( -(T3*reff)^4)===================================================
double Dexclusion2CrossPoly22Exp4Reff(double r2, double r, double d, double X, double T1, double T2, double T3, int E_or_F){

        double d2 = d * d;
        double T1_2 = T1 * T1;
        double T2_2 = T2 * T2;
        double T3_2 = T3 * T3;
        double T1r2 = T1_2 * r2;
        double T2r2 = T2_2 * r2;
        double T3r2 = T3_2 * r2;
	double T3r4 = T3r2 * T3r2;
        double cross1 = 1 - T1r2;
        double cross2 = 1 - T2r2;
        double c = exp(-T3r4);

        if (E_or_F == ENERGY){          //ENERGY
                return EkeConst*X*cross1*cross2*c/d2;
        }
        else{                           //FORCE / DISTANCE
                return 0.0;
        }
}

//E = 1 / (K1^2 * r^2 + K2^2 * d2^2)===========================================
double DexclusionLorentzianVar1(double r2, double r, double d, double K1, double K2, int E_or_F){

	double K1_2= K1*K1;
	double K2_2= K2*K2;
	double K2r2= K1_2 * r2;
	double d2 = d * d;
	double K2d2= K2_2 * d2;
	double c= K2r2 + K2d2;

        if (E_or_F == ENERGY){          //ENERGY
                return 1. / c;
        }
        else{                           //FORCE / DISTANCE
                return 0.0;
        }
}


//E = 1 /[ (1/R)^2 * d^2 + (r/d3)^2]==================================================
double DexclusionLorentzianVar2(double r2, double r, double d, double d3, double R, int E_or_F){

	double R2 = R * R;
	double iR2= 1. / R2;
	double d2 = d * d;
        double K2r2= iR2 * d2;
	double rd = r / d3;
	double rd2 = rd * rd;
        double c= K2r2 + rd2;

        if (E_or_F == ENERGY){          //ENERGY
                return 1. / c;
        }
        else{                           //FORCE / DISTANCE
                return 0.0;
        }
}


double DexclusionLorentzian6Pow(double r2, double r, double d1, double d2, int E_or_F){

        double d1_2= d1 * d1;
        double id2 = 1. / d1_2;
        double rd = r / d2;
	double rd2 = rd * rd;
	double rd6 = rd2 * rd2 * rd2;
	double c = 1 + rd6;
	
        if (E_or_F == ENERGY){          //ENERGY
                return id2 / c;
        }
        else{                           //FORCE / DISTANCE
                return 0.0;
        }
}


//E = (R/r)^N =================================================================
double simpleExclusion(double r2, double r, double R, int N, int E_or_F){

        //double r  = sqrt(r2);
        double c  = R / r;
        double cn = getPower(c, N);

        if (E_or_F == ENERGY){		//ENERGY
                return cn;
        }
        else{				//FORCE / DISTANCE
                return (double) (-N) * cn / r2;
        }
}
//=============================================================================

//E = (R2/r2)^N ===============================================================
double simpleExclusionHalfNeu(double r2, double r, double R, int N, int E_or_F){

        double c2  = R * R / r2;
        double c2n = getPower(c2, N);

        if (E_or_F == ENERGY){		//ENERGY
                return c2n;
        }
        else{				//FORCE / DISTANCE
                return (double) (-N) * 2.0 * c2n / r2;
        }

}
//=============================================================================

//E = (X / (r+R) )^N===========================================================
double shiftedExclusion2(double r2, double r, double R, double X, double N, int E_or_F){
	double c = r + R;
	double s = X / c;
	double sn = getPower(s,N);

        if (E_or_F == ENERGY){          //ENERGY
                return sn;
        }

	return 0;
}


//E = K / (1 + (r/R)^N) =======================================================
double shiftedExclusion(double r2, double r, double R, double K, int N, \
	int E_or_F){

        //double r  = sqrt(r2);
        double c  = r / R;
        double cn = getPower(c, N);
        double s  = 1 + cn;
        double e  = K / s;

        if (E_or_F == ENERGY){		//ENERGY
                return e;
        }
        else{				//FORCE / DISTANCE
                return (double) (-N) * e * cn / (s * r2);
        }

}
//=============================================================================

//E = K / (1 + T*(r/R)^N1 + (r/R)^N2) =========================================
double shiftedExclusionVariant1(double r2, double r, double R, double K, \
	double T, int N1, int N2, int E_or_F){

	//double r = sqrt(r2);
	double c = r / R;
	double cn_1 = getPower(c, N1);
	double cn_2 = getPower(c, N2);
	double s    = 1 + T * cn_1 + cn_2;
	
        if (E_or_F == ENERGY){		//ENERGY
                return K / s;
        }
        if (E_or_F == FORCE) {          //FORCE / DISTANCE
                double u = ((double) N1) * T * cn_1 + ((double) N2) * cn_2;
                double s2 = s * s;
                return (-K) * u / (s2 * r2);
        }
        if (E_or_F == FORCE_D){         //ELECTRON RADIUS 1st DERIVATIVE
                //D independent
                return 0.;
        }
        if (E_or_F == HESSIAN) {        //HESSIAN (2ND DERIVATIVE)
                double N1d = (double) N1;
                double N2d = (double) N2;

                double pre1  = 2.0 * K / (R * R * c * c);
                double post1 = N1d * T * cn_1 + N2d * cn_2;
                double num1 = pre1 * post1 * post1;
                double den1 = s * s * s;
                double pre2 = K / (R * R * c * c);
                double post2 = N1d * (N1d - 1.0) * T * cn_1 + N2d * (N2d - 1.0) * cn_2;
                double num2 = pre2 * post2;
                double den2 = s * s;

                return (num1 / den1) - (num2 / den2);
        }

        //Default:
        return 0.;

}	

//E = K / (1 + (r2/R2)^N) =====================================================
double shiftedExclusionHalfNeu(double r2, double r, double R, double K, \
	int N, int E_or_F){

        double c2  = r2 / (R * R);
        double c2n = getPower(c2, N);
        double s   = 1 + c2n;
        double e   = K / s;

        if (E_or_F == ENERGY){		//ENERGY
                return e;
        }
        else{				//FORCE / DISTANCE
                return (double) (-N) * 2.0 * e * c2n / (s * r2);
        }

}
//=============================================================================

//E = K / (1 + (r/R)^N + (r/R)^2N) ============================================
double shiftedExclusionHalfNeuVariant1(double r2, double r, double R, \
	double K, int N, int E_or_F){

	//double r   = sqrt(r2);
	double c   = r / R;
        double cn  = getPower(c, N);
	double c2n = cn * cn;
        double s   = 1 + cn + c2n;

        if (E_or_F == ENERGY){          //ENERGY
                return K / s;
        }
        else{                           //FORCE / DISTANCE
		double u  = cn + 2.0 * c2n;
		double s2 = s * s;
                return (double) (-N) * K * u / (s2 * r2);
        }

}
//=============================================================================

//E = K / (1 + (r/R)^N1 + (r/R)^N2) ===========================================
double shiftedExclusionHalfNeuVariant2(double r2, double r, double R, \
	double K, int N1, int N2, int E_or_F){

        //double r     = sqrt(r2);
        double c     = r / R;
        double cn_1  = getPower(c, N1);
        double cn_2  = getPower(c, N2);
        double s     = 1 + cn_1 + cn_2;

        if (E_or_F == ENERGY){          //ENERGY
                return K / s;
        }
        else{                           //FORCE / DISTANCE
                double u  = ((double) N1) * cn_1 + ((double) N2) * cn_2;
                double s2 = s * s;
                return (-K) * u / (s2 * r2);
        }

}
//=============================================================================

//E = K / (1 + (r/R1)^N1 + (r/R2)^N2) =========================================
double shiftedExclusionHalfNeuVariant3(double r2, double r, double R1, \
	double R2, double K, int N1, int N2, int E_or_F){
	
        //double r       = sqrt(r2);
        double c_1     = r / R1;
        double c_2     = r / R2;
        double c_1n_1  = getPower(c_1, N1);
        double c_2n_2  = getPower(c_2, N2);
        double s       = 1 + c_1n_1 + c_2n_2;
	
        if (E_or_F == ENERGY){          //ENERGY
                return K / s;
        }
        else{                           //FORCE / DISTANCE
                double u  = ((double) N1) * c_1n_1 + ((double) N2) * c_2n_2;
                double s2 = s * s;
                return (-K) * u / (s2 * r2);
        }
	
}
//============================================================================

//E = K / (1 + (r/R)^N)^2=====================================================
double shiftedSmoothExclusion(double r2, double r, double R, double K, \
	int N, int E_or_F){

	//double r   = sqrt(r2);
	double t   = r / R; 
	double tn  = getPower(t, N);
	double sn  = 1 + tn + tn*tn;
	double s2n = sn * sn;
	
        if (E_or_F == ENERGY){          //ENERGY
                return K / s2n;
        }
        else{                           //FORCE / DISTANCE
		double s3n = s2n * sn;
		return (double) (-N) * 2.0 * K * tn / (s3n * r2);
	}
}

//E = K / (1 + (r2/R2))^N=====================================================
double shiftedSmoothExclusionHalfNeu(double r2, double r, double R, \
	double K, int N, int E_or_F){

	double R2  = R * R;
	double t2  = r2 / R2;
	double s2  = 1 + t2;
	double s2n = getPower(s2, N);

        if (E_or_F == ENERGY){          //ENERGY
                return K / s2n;
        }
        else{                           //FORCE / DISTANCE
		double s2n1 = s2n * s2;
		return (double) (-N) * 2.0 * K / s2n1;
	}
}
//============================================================================

//E = K / (1 + (r/R)^N1 + (r/R)^N2 + (r/R)^N3)================================
double softDispersion(double r2, double r, double R, double K, int N1, \
	int N2, int N3, int E_or_F){

        //double r    = sqrt(r2);
	double c    = r / R; 
	double c_n1 = getPower(c, N1);	
	double c_n2 = getPower(c, N2);	
	double c_n3 = getPower(c, N3);	
	double s    = 1 + c_n1 + c_n2 + c_n3;
	
        if (E_or_F == ENERGY){          //ENERGY
                return K / s;
        }
        else{                           //FORCE / DISTANCE
		double s2 = s * s;
		double t  = ((double) N1) * c_n1;
		       t += ((double) N2) * c_n2;
		       t += ((double) N3) * c_n3;
		return (-K) * t / s2;
	}
}

//E = K / (1 + (r/R) + (1/2) * (r/R)^2)=======================================
double exponentMimicExclusion1(double r2, double r, double R, double K, \
	int E_or_F){

	//double r  = sqrt(r2);
	double t  = r / R;
	double t2 = t * t;
	double s2 = 1 + t + t2/2.0;

        if (E_or_F == ENERGY){          //ENERGY
                return K / s2;
        }
        else{                           //FORCE / DISTANCE
		return (-K) * (t + t2) / (s2 * s2 * r2);
	}
}
//=============================================================================

//E = K / (1 + (r/R) + (1/2) * (r/R)^2 + (1/6) * (r/R)^3)======================
double exponentMimicExclusion2(double r2, double r, double R, double K, \
	int E_or_F){

        //double r  = sqrt(r2);
        double t  = r / R;
        double t2 = t * t;
	double t3 = t2 * t;
        double s3 = 1 + t + t2/2.0 + t3/6.0;

        if (E_or_F == ENERGY){          //ENERGY
                return K / s3;
        }
        else{                           //FORCE / DISTANCE
                return (-K) * (t + t2 + 0.5 * t3) / (s3 * s3 * r2);
        }
}
//=============================================================================

//E = K / ((r/R) + (1/2) * (r/R)^2)============================================
double exponentMimicExclusion3(double r2, double r, double R, double K, \
	int E_or_F){

        //double r  = sqrt(r2);
        double t  = r / R;
        double t2 = t * t;
        double s2 = t + t2/2.0;

        if (E_or_F == ENERGY){          //ENERGY
                return K / s2;
        }
        else{                           //FORCE / DISTANCE
                return (-K) * (t + t2) / (s2 * s2 * r2);
        }
}
//=============================================================================

//E = K / ((r/R) + (1/2) * (r/R)^2 + (1/6) * (r/R)^3)==========================
double exponentMimicExclusion4(double r2, double r, double R, double K, \
	int E_or_F){

        //double r  = sqrt(r2);
        double t  = r / R;
        double t2 = t * t;
        double t3 = t2 * t;
        double s3 = t + t2/2.0 + t3/6.0;

        if (E_or_F == ENERGY){          //ENERGY
                return K / s3;
        }
        else{                           //FORCE / DISTANCE
                return (-K) * (t + t2 + 0.5 * t3) / (s3 * s3 * r2);
        }
}
//=============================================================================

//E = K / (1 + (r/Ra) + (1/2) * (r/Rb)^2)======================================
double exponentMimicExclusion5(double r2, double r, double Ra, double Rb, \
	double K, int E_or_F){

        //double r   = sqrt(r2);
        double t   = r / Ra;
	double Rb2 = Rb * Rb;
        double d2  = r2 / Rb2;
        double s2  = 1 + t + d2/2.0;

        if (E_or_F == ENERGY){          //ENERGY
                return K / s2;
        }
        else{                           //FORCE / DISTANCE
		return (-K) * (t + d2) / (s2 * s2 * r2);  
	}
}
//=============================================================================

//E = K / (1 + (r/Ra) + (1/2) * (r/Ra)^2  + (1/6) * (r/Rb)^3)==================
double exponentMimicExclusion6(double r2, double r, double Ra, double Rb, \
	double K, int E_or_F){

        //double r   = sqrt(r2);
	double r3  = r2 * r;
        double t   = r / Ra;
	double t2  = t * t;
        double Rb3 = Rb * Rb * Rb;
        double d3  = r3 / Rb3;
        double s3  = 1 + t + t2/2.0 + d3/6.0;

        if (E_or_F == ENERGY){          //ENERGY
                return K / s3;
        }
        else{                           //FORCE / DISTANCE
		return (-K) * (t + t2 + 0.5 * d3) / (s3 * s3 * r2);
	}
}
//=============================================================================

//E = K * e^(-r/R) ============================================================
double exponentialExclusion(double r2, double r, double R, double K, \
	int E_or_F){

        //double r   = sqrt(r2);
        double t   = r / R;
        double te  = exp(-t);
	double Kte = K * te;

        if (E_or_F == ENERGY){			//ENERGY
                return Kte;
        }
        else{					//FORCE / DISTANCE
		double Rr = R * r;
                return - Kte / Rr;
        }
}
//=============================================================================

//E = K * e^(-(r/R)^n) ========================================================
double exponentialPowerExclusion(double r2, double r, double R, double K, \
	int N, int E_or_F){

	//double r   = sqrt(r2);
	double t   = r / R;
	double tn  = getPower(t, N);
	double tne = exp(-tn);
	double Ktne = K * tne;

        if (E_or_F == ENERGY){          //ENERGY
                return Ktne;
        }
        else{                           //FORCE / DISTANCE
		return (double) (-N) * Ktne * tn / r2;
	}
}
//=============================================================================
double shiftedsum(double d1, double d2, double rho){
	double de = d1 + d2 + rho;
	return de;
}
	
double sqsum(double d1, double d2, double sigma){
	double di2 = d1 * d1;
	double dj2 = d2 * d2;
	double dij = d1 * d2;
	double sum = (di2 + 2 * sigma * dij + dj2) *0.5;
	return sum;
}

double InvSqSumInv(double d1, double d2){

	double d1_=1./d1;
	double d2_=1./d2;
	double di2=d1_ * d1_;
	double dj2=d2_ * d2_;
	double sum=di2 + dj2;
	sum=sqrt(sum);
	sum=1./sum;

	return sum;
}

double shiftedgeo(double d1, double d2, double rho){
                double die = d1 + rho;
                double dje = d2 + rho;
                double di2 = die * die;
                double dj2 = dje * dje;
                double d12 = di2 + dj2;
                double de = sqrt(d12);
	return de;
}

double shiftedgeo2par(double d1, double d2, double rho, double kap){
	double di2 = d1 * d1;
	double dj2 = d2 * d2;
	double dij2 = di2 + dj2;
	double dij = d1 + d2;
	double rho2 = rho * rho;
	double rhokap = rho * kap;
	double de2 = dij2 + 2*rhokap * dij + rho2;
	double de = sqrt(de2);
	return de;
}

double shiftedgeo2(double di, double dj, double rho){
	double di2 = di * di;
	double dj2 = dj * dj;
	double rho2 = rho * rho;
	double de2 = di2 + dj2 + rho2;
	double de = sqrt(de2);
	return de;
}

double shiftedgeo3(double di, double dj, double rho){
	double di2= di * di;
	double dj2= dj * dj;
	double rho2= rho * rho;
	double de2 = (di2 + dj2 + rho2)*0.5;
	double de= sqrt(de2);
	return de;
}

double geo2par(double di, double dj, double rho, double sigma){

        double di2= di * di;
        double dj2= dj * dj;
        double rho2 = rho * rho;
        double dirho = di * rho;
        double djrho = dj * rho;
        double dij = di * dj;
        double midsum = dirho + djrho + dij;
        double kapd= midsum * sigma;
        double de2 = (di2 + 2 * kapd + dj2 + rho2);
        double de= sqrt(de2);
        return de;

}


//d effective calculation
double deff(double d1, double d2, double rho, double kap){

	double de;
	if ((d1==0) || (d2==0)){
		de = shiftedsum(d1,d2,rho);

	}
	else{
		de = shiftedgeo2par(d1,d2,rho,kap);
	}

	return de;
}

//Get the maximum
int maxi(int a, int b){
	if (a > b){ return a; }
	else{ return b; }
}
//Get the minimum
int mini(int a, int b){
	if (a < b){ return a; }
	else{ return b; }
}

double maxi_float(double  a, double  b){
	if (a > b){ return a; }
	else{ return b; }
}
//Throw error message
void exitEnergy(int a, int b){
	//printf("Case not recognized: s1 = %i s2 = %i \n", a, b);
}

double getR2Dist(struct V *Vi, int i, struct V *Vj, int j){
	double r2, dx, dy, dz;

	dx = Vi[i].x - Vj[j].x;
	dy = Vi[i].y - Vj[j].y;
	dz = Vi[i].z - Vj[j].z;

	r2 = dx * dx + dy * dy + dz * dz;
	return r2;
}

//Boys function of F0 in PCCP paper
double complex BoysF0(double complex a){
	double complex x, x2;
	double complex F0;
	if (a != 0.0+0.0*I){
		x2 = -1.0*a;
		x = csqrt(x2);
		F0 = Faddeeva_Dawson(x,0)*cexp(x2)/x;
	}
//	else if (a2 > 0){
//		a = sqrt(a2);
//		F0 = rootpi/2.0 * (erf(a)/a);
//	}
	else return 1.0+0.0*I; //limrootpi/2*(erf(x)/x) x->0		
	
	return F0;
}

double FAA4(double a2, double Chi){
	double sum;
	double coeff = 2/rootpi;
	double coeff2 = coeff * coeff;
	double coeff4 = coeff2 * coeff2;
	double a4 = a2*a2;
	sum = coeff4*a4 + Chi*Chi*a2 +1;
	sum = sqrt(sum);
	sum = sqrt(sum);
	sum = 1/sum;
	
	return sum;
}

double FAA8(double a2, double Chi){
	double sum;
	double coeff = 2/rootpi;
	double coeff2 = coeff * coeff;
	double coeff4 = coeff2 * coeff2;
	double coeff8 = coeff4 * coeff4;
	double a4 = a2*a2;
	double a8 = a4*a4;
	double Chi2 = Chi*Chi;
	double Chi6 = Chi2 * Chi2 * Chi2;
	sum = coeff8 * a8 + Chi6*a2 + 1;
	sum = sqrt(sum);
	sum = sqrt(sum);
	sum = sqrt(sum);
	sum = 1/sum;
	
	return sum;
}

double FAA62Par(double a2, double Chi, double Kap){
	double sum;
	double coeff = 2/rootpi;
	double coeff2 = coeff * coeff;
	double coeff4 = coeff2 * coeff2;
	double coeff6 = coeff2 * coeff4;
	double a4 = a2*a2;
	double a6 = a2*a4;
	double Chi2 = Chi*Chi;
	double Kap2 = Kap*Kap;
	double Kap4 = Kap2*Kap2;
	sum = coeff6 * a6 + Chi2*a4 + Kap4*a2 + 1;
	sum = sqrt(sum);
	sum = pow(sum, 0.333333333333);
	sum = 1/sum;
	
	return sum;
}


double FAA83Par(double a2, double K, double R, double N){
        double sum; 
        double coeff = 2/rootpi;
        double coeff2 = coeff * coeff;
        double coeff4 = coeff2 * coeff2;
        double coeff8 = coeff4 * coeff4;
        double a4 = a2*a2;
        double a6 = a2*a4;
        double a8 = a4*a4;
        double K2 = K*K; 
        double R2 = R*R; 
        double R4 = R2*R2;
        double N3 = N*N*N;
        double N6 = N3*N3;
        sum = coeff8 * a8 + K2 * a6 + R4 * a4 + N6 * a2 + 1; 
        sum = sqrt(sum);
        sum = sqrt(sum);
        sum = sqrt(sum);
        sum = 1/sum;
     
        return sum; 
}

//E = q/deff(reff8 + Ra^7*reff + Rb^4*reff4 + Rc^6*reff2 + 1)^1/8==========================
double InvPoly8Par142(double r2, double r, double d, double Q,
        double Ra, double Rb, double Rc, double Rd, int E_or_F){

        /*Ra = Ra * d;
        Rb = Rb * d;
        Rc = Rc * d;
        Rd = Rd * d;*/

        double r4       = r2 * r2;
        double r6       = r4 * r2;
        double r8       = r4 * r4;
        double Ra2      = Ra * Ra;
        double Ra4      = Ra2 * Ra2;
        double Ra7r     = Ra4 * Ra2 * Ra * r;
        double Rb2      = Rb * Rb;
        //double Rb2      = Rb * Rb;
        double Rb4      = Rb2 * Rb2;
        double Rb4r4    = Rb4 * r4;
        double Rc2      = Rc * Rc;
        //double Rc2      = Rc * Rc;
        double Rc6      = Rc2 * Rc2 * Rc2;
        double Rc6r2    = Rc6 * r2;
        //double Rd2      = Rd * Rd;
        //double Rd2      = Rd * Rd;
        double t8       = r8 + Ra7r + Rb4r4 + Rc6r2 + Rd;
        double t4       = sqrt(t8);
        double t2       = sqrt(t4);
        double t        = sqrt(t2);

        if (E_or_F == ENERGY) {         //ENERGY
                return Q / (d*t);
        }
        else{                           //FORCE / DISTANCE
                return (double) 0;
        }
}
//=============================================================================
	
//C gammainc(double a, double b)
//{
//	C result;
//	mxArray *in1, *in2;
//	mxArray *out1 = NULL;
//	mxArray *out2 = NULL;
//	in1 = mxCreateDoubleMatrix(1,1,mxREAL);
//	in2 = mxCreateDoubleMatrix(1,1,mxREAL);
//	*mxGetPr(in1) = a;
//	*mxGetPr(in2) = b;
//	if (b<0){ 
//		printf("b must be nonnegative!\n");
//		exit(0);
//	}
//        /* Call the library function */
//        mlfGammainc(1, &out1, in1, in2);
//        mlfGamma(1, &out2, in2);
//	result.real = mxGetPr(out1)[0]*mxGetPr(out2)[0];
//	if (a>0) result.imag=0.0;
//	else result.imag = mxGetPi(out1)[0]*mxGetPr(out2)[0];
//        /* Free the memory created */
//        mxDestroyArray(out1); 
//        out1=0;
//        mxDestroyArray(out2); 
//        out2=0;
//        mxDestroyArray(in1); 
//        in1=0;
//        mxDestroyArray(in2); 
//        in2=0;
//    
//	return result;
//}

// 1-body function
double K(double complex a){
	double result;
	result = 3.0*conj(a)*a/(conj(a)+a);
	return result;
}

//2-body functions
double complex * R_ab(double complex a, double r_a[3], double complex b, double r_b[3]){
	double complex result[3];
	result[0] = (a*r_a[0]+b*r_b[0])/(a+b);
	result[1] = (a*r_a[1]+b*r_b[1])/(a+b);
	result[2] = (a*r_a[2]+b*r_b[2])/(a+b);
	return result;	
}

double Omega(double complex a, double r_a[3], double complex b, double r_b[3]){
	double result;
	double r_ab2;
	r_ab2 = (r_a[0]-r_b[0])*(r_a[0]-r_b[0]) + (r_a[1]-r_b[1])*(r_a[1]-r_b[1]) + (r_a[2]-r_b[2])*(r_a[2]-r_b[2]);
	result = csqrt((conj(a)+b)*(a+conj(b))/(conj(a)+a)/(conj(b)+b)) * csqrt((conj(a)+b)*(a+conj(b))/(conj(a)+a)/(conj(b)+b)) * csqrt((conj(a)+b)*(a+conj(b))/(conj(a)+a)/(conj(b)+b)) * cexp((conj(a)*b/(conj(a)+b)+a*conj(b)/(a+conj(b)))*r_ab2) - 1.0;
	return result;
}

double Delta_K(double complex a, double r_a[3], double complex b, double r_b[3]){
	double result;
	double r_ab2;
	r_ab2 = (r_a[0]-r_b[0])*(r_a[0]-r_b[0]) + (r_a[1]-r_b[1])*(r_a[1]-r_b[1]) + (r_a[2]-r_b[2])*(r_a[2]-r_b[2]);
	result = 3.0*conj(a)*a/(conj(a)+a) + 3.0*conj(b)*b/(conj(b)+b) - 3.0*conj(a)*b/(conj(a)+b) - 3.0*a*conj(b)/(a+conj(b)) + 2.0*((conj(a)*b/(conj(a)+b))*(conj(a)*b/(conj(a)+b))+(conj(b)*a/(conj(b)+a))*(conj(b)*a/(conj(b)+a)))*r_ab2;
	return result;
}

double U(double complex a, double r_a[3], double R_X[3]){
	double result;
	double r_aX2;
	r_aX2 = (r_a[0]-R_X[0])*(r_a[0]-R_X[0]) + (r_a[1]-R_X[1])*(r_a[1]-R_X[1]) + (r_a[2]-R_X[2])*(r_a[2]-R_X[2]);
	result = 2.0/rootpi*csqrt(conj(a)+a)*BoysF0((conj(a)+a)*r_aX2);
	return result;
}

double M(double complex a, double r_a[3], double complex b, double r_b[3]){
	double result;
	double r_ab2;
	r_ab2 = (r_a[0]-r_b[0])*(r_a[0]-r_b[0]) + (r_a[1]-r_b[1])*(r_a[1]-r_b[1]) + (r_a[2]-r_b[2])*(r_a[2]-r_b[2]);
	result = 2.0/rootpi*csqrt((conj(a)+a)*(conj(b)+b)/(conj(a)+a+conj(b)+b))*BoysF0((conj(a)+a)*(conj(b)+b)/(conj(a)+a+conj(b)+b)*r_ab2);
	return result;
}

double Delta_M(double complex a, double r_a[3], double complex b, double r_b[3]){
	double result;
	double complex *r_ab_1;
	double complex *r_ab_2;
	double complex r_ab2;
	r_ab_1 = R_ab(conj(a), r_a, b, r_b);
	r_ab_2 = R_ab(a, r_a, conj(b), r_b);
	r_ab2 = (r_ab_1[0]-r_ab_2[0])*(r_ab_1[0]-r_ab_2[0]) + (r_ab_1[1]-r_ab_2[1])*(r_ab_1[1]-r_ab_2[1]) + (r_ab_1[2]-r_ab_2[2])*(r_ab_1[2]-r_ab_2[2]);
	result = M(a, r_a, b, r_b) - 2.0/rootpi*csqrt((conj(a)+b)*(conj(b)+a)/(conj(a)+a+conj(b)+b))*BoysF0((conj(a)+b)*(conj(b)+a)/(conj(a)+a+conj(b)+b)*r_ab2);
	return result;
}

//3-body functions
double complex Delta_U(double complex a, double r_a[3], double complex b, double r_b[3], double R_X[3]){
	double complex result;
	double complex *r_ab_1;
	double complex *r_ab_2;
	double complex r_ab2_1;
	double complex r_ab2_2;
	r_ab_1 = R_ab(conj(a), r_a, b, r_b);
	r_ab_2 = R_ab(a, r_a, conj(b), r_b);
	r_ab2_1 = (r_ab_1[0]-R_X[0])*(r_ab_1[0]-R_X[0]) + (r_ab_1[1]-R_X[1])*(r_ab_1[1]-R_X[1]) + (r_ab_1[2]-R_X[2])*(r_ab_1[2]-R_X[2]);
	r_ab2_2 = (r_ab_2[0]-R_X[0])*(r_ab_2[0]-R_X[0]) + (r_ab_2[1]-R_X[1])*(r_ab_2[1]-R_X[1]) + (r_ab_2[2]-R_X[2])*(r_ab_2[2]-R_X[2]);
	result = U(a, r_a, R_X) + U(b, r_b, R_X) - 2.0/rootpi*csqrt(conj(a)+b)*BoysF0((conj(a)+b)*r_ab2_1) - 2.0/rootpi*csqrt(conj(b)+a)*BoysF0((conj(b)+a)*r_ab2_2);

	double complex B1, B2, B3, B4;
	B1 = 2.0/rootpi*csqrt(conj(a)+b)*BoysF0((conj(a)+b)*r_ab2_1);
	B2 = 2.0/rootpi*csqrt(conj(b)+a)*BoysF0((conj(b)+a)*r_ab2_2);
	B3 = (conj(a)+b)*r_ab2_1;
	B4 = (conj(b)+a)*r_ab2_2;
//	extern int diagnose_print;
//	if (diagnose_print == 1)
//		printf("Delta_U U_a %f, U_b %f, Boys1 %f+%fI Boys2 %f+%fI, B3 %f+%fI, B4 %f+%fI\n", U(a, r_a, R_X), U(b, r_b, R_X), creal(B1), cimag(B1), creal(B2), cimag(B2), creal(B3), cimag(B3), creal(B4), cimag(B4));
	return result;
}

double Delta_C(double complex a, double r_a[3], double complex b, double r_b[3], double complex c, double R_X[3]){
	double result;
	double complex *r_ab_1;
	double complex *r_ab_2;
	double complex r_ab2_1;
	double complex r_ab2_2;
	r_ab_1 = R_ab(conj(a), r_a, b, r_b);
	r_ab_2 = R_ab(a, r_a, conj(b), r_b);
	r_ab2_1 = (r_ab_1[0]-R_X[0])*(r_ab_1[0]-R_X[0]) + (r_ab_1[1]-R_X[1])*(r_ab_1[1]-R_X[1]) + (r_ab_1[2]-R_X[2])*(r_ab_1[2]-R_X[2]);
	r_ab2_2 = (r_ab_2[0]-R_X[0])*(r_ab_2[0]-R_X[0]) + (r_ab_2[1]-R_X[1])*(r_ab_2[1]-R_X[1]) + (r_ab_2[2]-R_X[2])*(r_ab_2[2]-R_X[2]);
	result = M(a, r_a, c, R_X) + M(b, r_b, c, R_X) - 2.0/rootpi*csqrt((conj(a)+b)*(conj(c)+c)/(conj(a)+b+conj(c)+c))*BoysF0((conj(a)+b)*(conj(c)+c)/(conj(a)+b+conj(c)+c)*r_ab2_1) - 2.0/rootpi*csqrt((conj(b)+a)*(conj(c)+c)/(conj(b)+a+conj(c)+c))*BoysF0((conj(a)+b)*(conj(c)+c)/(conj(b)+a+conj(c)+c)*r_ab2_1);
	return result;
}
