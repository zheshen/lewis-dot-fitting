#include <omp.h>
#include "Energy.h"
#include "Faddeeva.h"
void test(){
	C result;
	double complex term;
	#pragma omp parallel private(result) private(term)
				{
	#pragma omp sections 
				{
	#pragma omp section 
					{
						printf("BoysF0(%f)=%f\n", 12.0, BoysF0(12.0));
					}
	#pragma omp section 
					{
						printf("BoysF0(%f)=%f\n", 36.0, BoysF0(36.0));
					}
	#pragma omp section 
					{
						printf("Faddeeva_dawson(%f + %f*I)=%f + %f*I\n", -2.0, 1.0, creal(Faddeeva_Dawson(-2.0+I,0)), cimag(Faddeeva_Dawson(-2.0+I,0)));
					}
	#pragma omp section 
					{
						double complex a = 1;
						double complex b = 1;
						double r_a[3] = {0,0,-0.1};
						double r_b[3] = {0,0,0};
						double R_X[3] = {0,0,0};
						double k, omega, delta_K, m, delta_M, delta_U;
						k = K(a);
						omega = Omega(a, r_a, b, r_b);
						delta_K = Delta_K(a, r_a, b, r_b);
						m = M(a, r_a, b, r_b);
						delta_M = Delta_M(a, r_a, b, r_b);
						delta_U = Delta_U(a, r_a, b, r_b, R_X);
						printf("k=%f\n", k);
						printf("omega=%f\n", omega);
						printf("m=%f\n", m);
						printf("delta_M=%f\n", delta_M);
						printf("delta_U=%f\n", delta_U);
					}
				}
				}

	double complex a;
	double complex b;
	double complex c;
	double complex d;
	double complex e;
	double complex f;
	double complex g;
	a = I;
	b = -I;
	c = csqrt(a);
	e = a * a;
	d = BoysF0(a) + BoysF0(b);
	f = BoysF0(a);
	g = BoysF0(b);
	printf("c %f+%fI\n", creal(c), cimag(c));
	printf("e %f+%fI\n", creal(e), cimag(e));
	printf("d %f+%fI\n", creal(d), cimag(d));
	printf("f %f+%fI\n", creal(f), cimag(f));
	printf("g %f+%fI\n", creal(g), cimag(g));
	
}

