/*
 *  Energy.c AKA "acase"
 *  		
 *
 *  Created by Mike on 1/20/06.
 *
 * Corrected by Seyit, June 7 - 2007
 * Totally changed by Seyit, May 18 - 2009
 * -the reason of change was the excessive number of 
 * new particles..
 *
 * Again, totally changed by Seyit, Jun 1 - 2009
 * -This time the reason is easier interconversion 
 * between WS and MD, yes not MC, MD.
 *
 */
#include "Energy.h"

double kineticEnergy(double complex d, double eta, double zeta, int E_or_F){
	return kineticEnergy_split(d, eta, zeta, E_or_F, NULL);
}

double TBenergy(V * a, V * b, V * R, int E_or_F){
	return TBenergy_split(a, b, R, E_or_F, NULL);
}

double energy(V *a, V *b, int E_or_F) {
	return energy_split(a, b, E_or_F, NULL);
}

double kineticEnergy_split(double complex d, double eta, double zeta, int E_or_F, double *items){

//        extern double parKE[];
	extern double parAB[];
	double pAB2 = parAB[1];
	double pAB3 = parAB[2];
	double pAB6 = parAB[5];
	double pAB7 = parAB[6];
	double pAB8 = parAB[7];

        double k = 1.0;
	double tau1 = pAB7;
	double tau2 = pAB8;

        return formOfKE(E_const, d, eta, zeta, k, tau1, tau2, E_or_F, items);

}

double TBenergy_split(V * a, V * b, V * R, int E_or_F, double *items){
	extern int diagnose_print;
        extern double dlewis[];
	extern double parAB[];
//        extern double parAA[];
        extern double parAH[];
        extern double parCA[];
        extern double parNA[];
        extern double parOA[];
//        extern double parCH[];
//        extern double parNH[];
//        extern double parOH[];
//        extern double parCC[];
//        extern double parNN[];
//        extern double parOO[];
//        extern double parCN[];
//        extern double parCO[];
//        extern double parNO[];
        extern double parHH[];
//	  extern double parKE[];
        extern double parSA[];
        extern double parPA[];
        extern double parFA[];
        extern double parSiA[];
	extern double parBoA[];
	extern double parClA[];
	extern double parAlA[];	
//	extern double parXA[];
	extern double parLiA[];
	extern double parBeA[];
	extern double parNaA[];
	extern double parMgA[];
        extern double parFeA[];
        extern double parMA[];

	double pAB2 = parAB[1];
	double pAB5 = parAB[4];
	double pAB6 = parAB[5];
	double pAB7 = parAB[6];
	double pAB8 = parAB[7];
	double pAB9 = parAB[8];
	double pAB10 = parAB[9];
	double pAB11 = parAB[10];
	double pAB12 = parAB[11];
	double pAB20 = parAB[19];
	double pAB21 = parAB[20];
	double pAB22 = parAB[21];
	double pAB23 = parAB[22];
	double pAB24 = parAB[23];
	double pAB25 = parAB[24];
	double p1=0;
	double p2=0;
	double p3=0;
	double p4=0;
	double p5=0;
	double p6=0;
	double p7=0;
	double p8=0;
	double p9=0;
	double p10=0;
	double p11=0;
	double p12=0;
	double p13=0;

	int s;
	s = R->s;

		if(s == 1){
                                p1  = parAH[0];
                                p2  = parAH[1];
                                p3  = parAH[2];
                                p4  = parAH[3];
                                p5  = parAH[4];
                                p6  = parAH[5];
                                p7  = parAH[6];
                                p8  = parAH[7];
                                p9  = parAH[8];
                                p10 = parAH[9];
				p11 = parAH[10];
				p12 = parAH[11];
				p13 = parAH[12];
	}

		else if(s == 2){
                                p1  = parAB[0];
                                p2  = parAB[1];
                                p3  = parAB[2];
                                p4  = parAB[3];
                                p5  = parAB[4];
                                p6  = parAB[5];
                                p7  = parAB[6];
                                p8  = parAB[7];
                                p9  = parAB[8];
                                p10 = parAB[9];
				p11 = parAB[10];
				p12 = parAB[11];
				p13 = parAB[12];
		}

		else if(s == -2){
                                p1  = parAB[0];
                                p2  = parAB[1];
                                p3  = parAB[2];
                                p4  = parAB[3];
                                p5  = parAB[4];
                                p6  = parAB[5];
                                p7  = parAB[6];
                                p8  = parAB[7];
                                p9  = parAB[8];
                                p10 = parAB[9];
				p11 = parAB[10];
				p12 = parAB[11];
				p13 = parAB[12];
		}

		else if(s == 3){
                                p1  = parLiA[0];
                                p2  = parLiA[1];
                                p3  = parLiA[2];
                                p4  = parLiA[3];
                                p5  = parLiA[4];
                                p6  = parLiA[5];
                                p7  = parLiA[6];
                                p8  = parLiA[7];
                                p9  = parLiA[8];
                                p10 = parLiA[9];
				p11 = parLiA[10];
				p12 = parLiA[11];
				p13 = parLiA[12];
		}


		else if(s == 4){
                                p1  = parBeA[0];
                                p2  = parBeA[1];
                                p3  = parBeA[2];
                                p4  = parBeA[3];
                                p5  = parBeA[4];
                                p6  = parBeA[5];
                                p7  = parBeA[6];
                                p8  = parBeA[7];
                                p9  = parBeA[8];
                                p10 = parBeA[9];
				p11 = parBeA[10];
				p12 = parBeA[11];
				p13 = parBeA[12];
		}

		else if(s == 5){
                                p1  = parBoA[0];
                                p2  = parBoA[1];
                                p3  = parBoA[2];
                                p4  = parBoA[3];
                                p5  = parBoA[4];
                                p6  = parBoA[5];
                                p7  = parBoA[6];
                                p8  = parBoA[7];
                                p9  = parBoA[8];
                                p10 = parBoA[9];
				p11 = parBoA[10];
				p12 = parBoA[11];
				p13 = parBoA[12];
		}

		else if(s == 6){
                                p1  = parCA[0];
                                p2  = parCA[1];
                                p3  = parCA[2];
                                p4  = parCA[3];
                                p5  = parCA[4];
                                p6  = parCA[5];
                                p7  = parCA[6];
                                p8  = parCA[7];
                                p9  = parCA[8];
                                p10 = parCA[9];
				p11 = parCA[10];
				p12 = parCA[11];
				p13 = parCA[12];
		}


		else if(s == 7){
                                p1  = parNA[0];
                                p2  = parNA[1];
                                p3  = parNA[2];
                                p4  = parNA[3];
                                p5  = parNA[4];
                                p6  = parNA[5];
                                p7  = parNA[6];
                                p8  = parNA[7];
                                p9  = parNA[8];
                                p10 = parNA[9];
				p11 = parNA[10];
				p12 = parNA[11];
				p13 = parNA[12];
		}

		else if(s == 8){
                                p1  = parOA[0];
                                p2  = parOA[1];
                                p3  = parOA[2];
                                p4  = parOA[3];
                                p5  = parOA[4];
                                p6  = parOA[5];
                                p7  = parOA[6];
                                p8  = parOA[7];
                                p9  = parOA[8];
                                p10 = parOA[9];
				p11 = parOA[10];
				p12 = parOA[11];
				p13 = parOA[12];
		}

		else if(s == 9){
                                p1  = parFA[0];
                                p2  = parFA[1];
                                p3  = parFA[2];
                                p4  = parFA[3];
                                p5  = parFA[4];
                                p6  = parFA[5];
                                p7  = parFA[6];
                                p8  = parFA[7];
                                p9  = parFA[8];
                                p10 = parFA[9];
				p11 = parFA[10];
				p12 = parFA[11];
				p13 = parFA[12];
		}

		else if(s ==11){
                                p1  = parNaA[0];
                                p2  = parNaA[1];
                                p3  = parNaA[2];
                                p4  = parNaA[3];
                                p5  = parNaA[4];
                                p6  = parNaA[5];
                                p7  = parNaA[6];
                                p8  = parNaA[7];
                                p9  = parNaA[8];
                                p10 = parNaA[9];
				p11 = parNaA[10];
				p12 = parNaA[11];
				p13 = parNaA[12];
		}

		else if(s ==12){
                                p1  = parMgA[0];
                                p2  = parMgA[1];
                                p3  = parMgA[2];
                                p4  = parMgA[3];
                                p5  = parMgA[4];
                                p6  = parMgA[5];
                                p7  = parMgA[6];
                                p8  = parMgA[7];
                                p9  = parMgA[8];
                                p10 = parMgA[9];
				p11 = parMgA[10];
				p12 = parMgA[11];
				p13 = parMgA[12];
		}


		else if(s ==13){
                                p1  = parAlA[0];
                                p2  = parAlA[1];
                                p3  = parAlA[2];
                                p4  = parAlA[3];
                                p5  = parAlA[4];
                                p6  = parAlA[5];
                                p7  = parAlA[6];
                                p8  = parAlA[7];
                                p9  = parAlA[8];
                                p10 = parAlA[9];
				p11 = parAlA[10];
				p12 = parAlA[11];
				p13 = parAlA[12];
		}


		else if(s ==14){
                                p1  = parSiA[0];
                                p2  = parSiA[1];
                                p3  = parSiA[2];
                                p4  = parSiA[3];
                                p5  = parSiA[4];
                                p6  = parSiA[5];
                                p7  = parSiA[6];
                                p8  = parSiA[7];
                                p9  = parSiA[8];
                                p10 = parSiA[9];
				p11 = parSiA[10];
				p12 = parSiA[11];
				p13 = parSiA[12];
		}


		else if(s ==15){
                                p1  = parPA[0];
                                p2  = parPA[1];
                                p3  = parPA[2];
                                p4  = parPA[3];
                                p5  = parPA[4];
                                p6  = parPA[5];
                                p7  = parPA[6];
                                p8  = parPA[7];
                                p9  = parPA[8];
                                p10 = parPA[9];
				p11 = parPA[10];
				p12 = parPA[11];
				p13 = parPA[12];
		}


		else if(s ==16){
                                p1  = parSA[0];
                                p2  = parSA[1];
                                p3  = parSA[2];
                                p4  = parSA[3];
                                p5  = parSA[4];
                                p6  = parSA[5];
                                p7  = parSA[6];
                                p8  = parSA[7];
                                p9  = parSA[8];
                                p10 = parSA[9];
				p11 = parSA[10];
				p12 = parSA[11];
				p13 = parSA[12];
		}


		else if(s ==17){
                                p1  = parClA[0];
                                p2  = parClA[1];
                                p3  = parClA[2];
                                p4  = parClA[3];
                                p5  = parClA[4];
                                p6  = parClA[5];
                                p7  = parClA[6];
                                p8  = parClA[7];
                                p9  = parClA[8];
                                p10 = parClA[9];
				p11 = parClA[10];
				p12 = parClA[11];
				p13 = parClA[12];
		}

		else if(s ==26){
                                p1  = parFeA[0];
                                p2  = parFeA[1];
                                p3  = parFeA[2];
                                p4  = parFeA[3];
                                p5  = parFeA[4];
                                p6  = parFeA[5];
                                p7  = parFeA[6];
                                p8  = parFeA[7];
                                p9  = parFeA[8];
                                p10 = parFeA[9];
				p11 = parFeA[10];
				p12 = parFeA[11];
				p13 = parFeA[12];
		}

		else if((s<0)&&(s!=-2)){
			return 0;
		}

                else {
                                p1  = parMA[0];
                                p2  = parMA[1];
                                p3  = parMA[2];
                                p4  = parMA[3];
                                p5  = parMA[4];
                                p6  = parMA[5];
                                p7  = parMA[6];
                                p8  = parMA[7];
                                p9  = parMA[8];
                                p10 = parMA[9];
				p11 = parMA[10];
				p12 = parMA[11];
				p13 = parMA[12];
		}
                 

               int    n1  = (int) dlewis[n_potentials + 0];
               int    n2  = (int) dlewis[n_potentials + 1];
//        extern int diagnose_print;
//        diagnose_print = 1;
//        if (diagnose_print == 1)
//                printf("energy_read r %f, dr1 %f, di1 %f\n", r, dr1, di1);
//        diagnose_print = 0;
	
	return formOfAAX(a, b, R, pAB2, pAB5, pAB6, pAB7, pAB8, pAB9, pAB10, pAB11, pAB12, pAB20, pAB21, pAB22, pAB23, pAB24, pAB25, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, E_or_F, items);

}


double energy_split(V *a, V *b, int E_or_F, double *items) {
	extern diagnose_print;
	extern double dlewis[];
	extern double parAB[];
//        extern double parAA[];
        extern double parAH[];
        extern double parCA[];
        extern double parNA[];
        extern double parOA[];
        extern double parCH[];
        extern double parNH[];
        extern double parOH[];
        extern double parCC[];
        extern double parNN[];
        extern double parOO[];
        extern double parCN[];
        extern double parCO[];
        extern double parNO[];
        extern double parHH[];
//	extern double parKE[];
        extern double parSA[];
        extern double parPA[];
        extern double parFA[];
        extern double parSiA[];
	extern double parBoA[];
	extern double parClA[];
	extern double parAlA[];	
//	extern double parXA[];
	extern double parLiA[];
	extern double parBeA[];
	extern double parNaA[];
	extern double parMgA[];
        extern double parFeA[];
        extern double parMA[];
	double u  = 0.0;
        double sp_type = 0.0;

//	extern int print;
//	extern int icue_spinO;
//	int dvar;

//	if((print)&&(icue_spinO>1))
//		{for(dvar=0;dvar<n_potentials;dvar++)
//			printf("par %d of d is %f\n",dvar,dlewis[dvar]);
//		}
	double r2, r;
	int s1, s2;
	double q1, q2;
	s1 = a->s;
	s2 = b->s;
	q1 = a->q;
	q2 = b->q;

        if ((fabs(s1) == 2) && (fabs(s2) == 2)){
                if (s1 == -s2) { sp_type = -1; }
                else           { sp_type = 1; }
        }

        if (fabs(s1) == 2) { s1 = -2;   }
        if (fabs(s2) == 2) { s2 = -2;   }


	double s;
	s = maxi(s1, s2);

	double r_a[3], r_b[3];
	r_a[0] = a->x;
	r_a[1] = a->y;
	r_a[2] = a->z;
	r_b[0] = b->x;
	r_b[1] = b->y;
	r_b[2] = b->z;

	r2 = (r_a[0]-r_b[0])*(r_a[0]-r_b[0]) + (r_a[1]-r_b[1])*(r_a[1]-r_b[1]) + (r_a[2]-r_b[2])*(r_a[2]-r_b[2]);
	r = sqrt(r2);

	int m1 = maxi(s1, s2);
	int m2 = mini(s1, s2);
	//printf("m1 and m2 are respectively %d and %d\n",m1,m2);
	double q  = q1 * q2;
	
	//ENERGY CALCULATIONS - potential equations
	switch (m2){

                case -2:
//AA=BB===========================================================
                        if (sp_type ==1){

                                double p1  = parAB[0];/**/
                                double p2  = parAB[1];
                                double p3  = parAB[2];
                                double p4  = parAB[3];
                                double p5  = parAB[4];
                                double p6  = parAB[5];
                                double p7  = parAB[6];
                                double p8  = parAB[7];
                                double p9  = parAB[8];
                                double p10 = parAB[9];
                                double p11 = parAB[10];
                                double p12 = parAB[11];
                                double p13 = parAB[12];
                                double p14 = parAB[13];
                                double p15 = parAB[14];
                                double p16 = parAB[15];
                                double p17 = parAB[16];
                                double p18 = parAB[17];
                                double p19 = parAB[18];
                                double p20 = parAB[19];
                                double p21 = parAB[20];
                                double p22 = parAB[21];
                                double p23 = parAB[22];
                                double p24 = parAB[23];
                                double p25 = parAB[24];
                                double p26 = parAB[25];

                                int    n1  = (int) dlewis[n_potentials + 0];
                                int    n2  = (int) dlewis[n_potentials + 1];
                                int    n3  = (int) dlewis[n_potentials + 2];

                                u = formOfAA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, n1, n2, n3, E_or_F, items);

			//	if((print)&&(icue_spinO>1))
			//		printf("AA energy at r %f is %f\n",r,u);
                                break;
			}
//AB=BA============================================================
                        else if(sp_type ==-1){
                                double p1  = parAB[0];/**/
                                double p2  = parAB[1];/**/
                                double p3  = parAB[2];
                                double p4  = parAB[3];
                                double p5  = parAB[4];
				double p6  = parAB[5];
				double p13  = parAB[12];	
                                int    n1  = (int) dlewis[n_potentials + 0];
                                int    n2  = (int) dlewis[n_potentials + 1];
                                int    n3  = (int) dlewis[n_potentials + 2];

                                u = formOfAB(a, b, p1, p2, p3, p4, p5, p6, p13, n1, n2, n3, E_or_F, items);
			//	if((print)&&(icue_spinO>1))
			//		printf("AB energy is at r %f is %f\n",r,u);
                                break;
			}
/*//AV===============================================================
                        else if(m1 == 0){
                                double p1  = dlewis[0];
                                double p2  = dlewis[1];
                                double p3  = dlewis[2];
                                double p4  = dlewis[3];
                                double p5  = dlewis[4];
                                double p6  = dlewis[5];

                                int    n1  = (int) dlewis[n_potentials + 0];
                                int    n2  = (int) dlewis[n_potentials + 1];
                                int    n3  = (int) dlewis[n_potentials + 2];

                                u = formOfAV(r2, r, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                                break;
                        }
*/
//AH===============================================================
                         else if (m1 == 1){
                                double p1  = parAH[0];
                                double p2  = parAH[1];
                                double p3  = parAH[2];
                                double p4  = parAH[3];
                                double p5  = parAH[4];
                                double p6  = parAH[5];
                                double p7  = parAH[6];
                                double p8  = parAH[7];
                                double p9  = parAH[8];
                                double p10 = parAH[9];
                                double p11 = parAH[10];
                                double p12 = parAH[11];
                                double p13 = parAH[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

				//if (diagnose_print == 1)printf("%f  %f  %f %f\n", p1, p2, p3, p4);
                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
//CA===============================================================
                        else if (m1 == 6){
                                double p1  = parCA[0];
                                double p2  = parCA[1];
                                double p3  = parCA[2];
                                double p4  = parCA[3];
                                double p5  = parCA[4];
                                double p6  = parCA[5];
                                double p7  = parCA[6];
                                double p8  = parCA[7];
                                double p9  = parCA[8];
                                double p10 = parCA[9];
                                double p11 = parCA[10];
                                double p12 = parCA[11];
                                double p13 = parCA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                //u = formOfXA(r_a, r_b, r2, r, dr1,dr2, di1, di2, q, s, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F);
                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
//NA===============================================================
                         else if (m1 == 7){
                                double p1  = parNA[0];
                                double p2  = parNA[1];
                                double p3  = parNA[2];
                                double p4  = parNA[3];
                                double p5  = parNA[4];
                                double p6  = parNA[5];
                                double p7  = parNA[6];
                                double p8  = parNA[7];
                                double p9  = parNA[8];
                                double p10 = parNA[9];
                                double p11 = parNA[10];
                                double p12 = parNA[11];
                                double p13 = parNA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                     else if (m1 == 7){
                                double p1  = parNA[0];
                                double p2  = parNA[1];
                                double p3  = parNA[2];
                                double p4  = parNA[3];
				double p5  = parKE[5];
                                double p6  = parXA[5];

				//p5 = p6+p5;

                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                                break;
                        }*/
//OA===============================================================
                         else if (m1 == 8){
                                double p1  = parOA[0];
                                double p2  = parOA[1];
                                double p3  = parOA[2];
                                double p4  = parOA[3];
                                double p5  = parOA[4];
                                double p6  = parOA[5];
                                double p7  = parOA[6];
                                double p8  = parOA[7];
                                double p9  = parOA[8];
                                double p10 = parOA[9];
                                double p11 = parOA[10];
                                double p12 = parOA[11];
                                double p13 = parOA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                       else if (m1 == 8){
                                double p1  = parOA[0];
                                double p2  = parOA[1];
                                double p3  = parOA[2];
                                double p4  = parOA[3];
				double p5  = parKE[6];
                                double p6  = parXA[6];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
 //                               int    n3  = (int) dlewis[n_potentials + 5];
				int    n3  = (int) -2; //charge of core

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
			//	if((print)&&(icue_spinO>1))
			//		printf("OA energy at r %f is %f\n",r,u);
                                break;
                        }*/
//FA===============================================================
                         else if (m1 == 9){
                                double p1  = parFA[0];
                                double p2  = parFA[1];
                                double p3  = parFA[2];
                                double p4  = parFA[3];
                                double p5  = parFA[4];
                                double p6  = parFA[5];
                                double p7  = parFA[6];
                                double p8  = parFA[7];
                                double p9  = parFA[8];
                                double p10 = parFA[9];
                                double p11 = parFA[10];
                                double p12 = parFA[11];
                                double p13 = parFA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                       else if (m1 == 9){
                                double p1  = parFA[0];
                                double p2  = parFA[1];
                                double p3  = parFA[2];
                                double p4  = parFA[3];
                                double p5  = parKE[7];
                                double p6  = parXA[7];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                        //        int    n3  = (int) dlewis[n_potentials + 5];
				int    n3  = (int) -2;//charge of core

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                        //      if((print)&&(icue_spinO>1))
                        //              printf("OA energy at r %f is %f\n",r,u);
                                break;
                        }
*/
//SiA==============================================================
                         else if (m1 ==14){
                                double p1  = parSiA[0];
                                double p2  = parSiA[1];
                                double p3  = parSiA[2];
                                double p4  = parSiA[3];
                                double p5  = parSiA[4];
                                double p6  = parSiA[5];
                                double p7  = parSiA[6];
                                double p8  = parSiA[7];
                                double p9  = parSiA[8];
                                double p10 = parSiA[9];
                                double p11 = parSiA[10];
                                double p12 = parSiA[11];
                                double p13 = parSiA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                       else if (m1 ==14){
                                double p1  = parSiA[0];
                                double p2  = parSiA[1];
                                double p3  = parSiA[2];
                                double p4  = parSiA[3];
                                double p5  = parKE[9];
                                double p6  = parXA[9];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                        //      if((print)&&(icue_spinO>1))
                        //              printf("OA energy at r %f is %f\n",r,u);
                                break;
                        }*/
//PA===============================================================
                         else if (m1 ==15){
                                double p1  = parPA[0];
                                double p2  = parPA[1];
                                double p3  = parPA[2];
                                double p4  = parPA[3];
                                double p5  = parPA[4];
                                double p6  = parPA[5];
                                double p7  = parPA[6];
                                double p8  = parPA[7];
                                double p9  = parPA[8];
                                double p10 = parPA[9];
                                double p11 = parPA[10];
                                double p12 = parPA[11];
                                double p13 = parPA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                     else if (m1 ==15){
                                double p1  = parPA[0];
                                double p2  = parPA[1];
                                double p3  = parPA[2];
                                double p4  = parPA[3];
                                double p5  = parKE[10];
                                double p6  = parXA[10];



                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                        //      if((print)&&(icue_spinO>1))
                        //              printf("OA energy at r %f is %f\n",r,u);
                                break;
                        }*/
//SA===============================================================
                         else if (m1 ==16){
                                double p1  = parSA[0];
                                double p2  = parSA[1];
                                double p3  = parSA[2];
                                double p4  = parSA[3];
                                double p5  = parSA[4];
                                double p6  = parSA[5];
                                double p7  = parSA[6];
                                double p8  = parSA[7];
                                double p9  = parSA[8];
                                double p10 = parSA[9];
                                double p11 = parSA[10];
                                double p12 = parSA[11];
                                double p13 = parSA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                     else if (m1 ==16){
                                double p1  = parSA[0];
                                double p2  = parSA[1];
                                double p3  = parSA[2];
                                double p4  = parSA[3];
                                double p5  = parKE[11];
                                double p6  = parXA[11];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                        //      if((print)&&(icue_spinO>1))
                        //              printf("OA energy at r %f is %f\n",r,u);
                                break;
                        }*/
//BoA===============================================================
                         else if (m1 == 5){
                                double p1  = parBoA[0];
                                double p2  = parBoA[1];
                                double p3  = parBoA[2];
                                double p4  = parBoA[3];
                                double p5  = parBoA[4];
                                double p6  = parBoA[5];
                                double p7  = parBoA[6];
                                double p8  = parBoA[7];
                                double p9  = parBoA[8];
                                double p10 = parBoA[9];
                                double p11 = parBoA[10];
                                double p12 = parBoA[11];
                                double p13 = parBoA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                       else if (m1 == 5){
                                double p1  = parBoA[0];
                                double p2  = parBoA[1];
                                double p3  = parBoA[2];
                                double p4  = parBoA[3];
                                double p5  = parKE[3];
                                double p6  = parXA[3];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                                break;
                        }
*/
//ClA===============================================================
                         else if (m1 ==17){
                                double p1  = parClA[0];
                                double p2  = parClA[1];
                                double p3  = parClA[2];
                                double p4  = parClA[3];
                                double p5  = parClA[4];
                                double p6  = parClA[5];
                                double p7  = parClA[6];
                                double p8  = parClA[7];
                                double p9  = parClA[8];
                                double p10 = parClA[9];
                                double p11 = parClA[10];
                                double p12 = parClA[11];
                                double p13 = parClA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                       else if (m1 == 17){
                                double p1  = parClA[0];
                                double p2  = parClA[1];
                                double p3  = parClA[2];
                                double p4  = parClA[3];
                                double p5  = parKE[12];
                                double p6  = parXA[12];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                                break;
                        }*/
//AlA===============================================================
                         else if (m1 ==13){
                                double p1  = parAlA[0];
                                double p2  = parAlA[1];
                                double p3  = parAlA[2];
                                double p4  = parAlA[3];
                                double p5  = parAlA[4];
                                double p6  = parAlA[5];
                                double p7  = parAlA[6];
                                double p8  = parAlA[7];
                                double p9  = parAlA[8];
                                double p10 = parAlA[9];
                                double p11 = parAlA[10];
                                double p12 = parAlA[11];
                                double p13 = parAlA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                       else if (m1 == 13){
                                double p1  = parAlA[0];
                                double p2  = parAlA[1];
                                double p3  = parAlA[2];
                                double p4  = parAlA[3];
                                double p5  = parKE[8];
                                double p6  = parXA[8];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                                break;
                        }
*/
//LiA===============================================================
                          else if (m1 == 3){
                                double p1  = parLiA[0];
                                double p2  = parLiA[1];
                                double p3  = parLiA[2];
                                double p4  = parLiA[3];
                                double p5  = parLiA[4];
                                double p6  = parLiA[5];
                                double p7  = parLiA[6];
                                double p8  = parLiA[7];
                                double p9  = parLiA[8];
                                double p10 = parLiA[9];
                                double p11 = parLiA[10];
                                double p12 = parLiA[11];
                                double p13 = parLiA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                      else if (m1 ==  3){
                                double p1  = parLiA[0];
                                double p2  = parLiA[1];
                                double p3  = parLiA[2];
                                double p4  = parLiA[3];
                                double p5  = parKE[1];
                                double p6  = parXA[1];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                                break;
                        }*/
//BeA===============================================================
                         else if (m1 == 4){
                                double p1  = parBeA[0];
                                double p2  = parBeA[1];
                                double p3  = parBeA[2];
                                double p4  = parBeA[3];
                                double p5  = parBeA[4];
                                double p6  = parBeA[5];
                                double p7  = parBeA[6];
                                double p8  = parBeA[7];
                                double p9  = parBeA[8];
                                double p10 = parBeA[9];
                                double p11 = parBeA[10];
                                double p12 = parBeA[11];
                                double p13 = parBeA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                       else if (m1 ==  4){
                                double p1  = parBeA[0];
                                double p2  = parBeA[1];
                                double p3  = parBeA[2];
                                double p4  = parBeA[3];
                                double p5  = parKE[2];
                                double p6  = parXA[2];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                                break;
                        }*/
//NaA===============================================================
                         else if (m1 ==11){
                                double p1  = parNaA[0];
                                double p2  = parNaA[1];
                                double p3  = parNaA[2];
                                double p4  = parNaA[3];
                                double p5  = parNaA[4];
                                double p6  = parNaA[5];
                                double p7  = parNaA[6];
                                double p8  = parNaA[7];
                                double p9  = parNaA[8];
                                double p10 = parNaA[9];
                                double p11 = parNaA[10];
                                double p12 = parNaA[11];
                                double p13 = parNaA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                       else if (m1 == 11){
                                double p1  = parNaA[0];
                                double p2  = parNaA[1];
                                double p3  = parNaA[2];
                                double p4  = parNaA[3];
                                double p5  = parKE[13];
                                double p6  = parXA[1];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                                break;
                        }*/
//MgA===============================================================
                         else if (m1 ==12){
                                double p1  = parMgA[0];
                                double p2  = parMgA[1];
                                double p3  = parMgA[2];
                                double p4  = parMgA[3];
                                double p5  = parMgA[4];
                                double p6  = parMgA[5];
                                double p7  = parMgA[6];
                                double p8  = parMgA[7];
                                double p9  = parMgA[8];
                                double p10 = parMgA[9];
                                double p11 = parMgA[10];
                                double p12 = parMgA[11];
                                double p13 = parMgA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }
/*                       else if (m1 == 12){
                                double p1  = parMgA[0];
                                double p2  = parMgA[1];
                                double p3  = parMgA[2];
                                double p4  = parMgA[3];
                                double p5  = parKE[14];
                                double p6  = parXA[1];


                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];

                                u = formOfXA(r_a, r_b, r2, r, dr1, dr2, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
                                break;
                        }
*/



//FeA===============================================================
                        else if(m1==26) { 
                                double p1  = parFeA[0];
                                double p2  = parFeA[1];
                                double p3  = parFeA[2];
                                double p4  = parFeA[3];
                                double p5  = parFeA[4];
                                double p6  = parFeA[5];
                                double p7  = parFeA[6];
                                double p8  = parFeA[7];
                                double p9  = parFeA[8];
                                double p10 = parFeA[9];
                                double p11 = parFeA[10];
                                double p12 = parFeA[11];
                                double p13 = parFeA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }

//MA===============================================================
                        else{
                                double p1  = parMA[0];
                                double p2  = parMA[1];
                                double p3  = parMA[2];
                                double p4  = parMA[3];
                                double p5  = parMA[4];
                                double p6  = parMA[5];
                                double p7  = parMA[6];
                                double p8  = parMA[7];
                                double p9  = parMA[8];
                                double p10 = parMA[9];
                                double p11 = parMA[10];
                                double p12 = parMA[11];
                                double p13 = parMA[12];
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];


                                u = formOfXA(a, b, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, n1, n2, n3, E_or_F, items);
                                break;
                        }

/*		case 0:
//VV===============================================================
			if (m1 == m2){
				double p1  = dlewis[0];
				double p2  = dlewis[1];
				double p3  = dlewis[2];
				double p4  = dlewis[3];
				double p5  = dlewis[4];
				double p6  = dlewis[5];
				
				int    n1  = (int) dlewis[n_potentials + 0];				
				int    n2  = (int) dlewis[n_potentials + 1];				
				int    n3  = (int) dlewis[n_potentials + 2];				
				
				u = formOfVV(r2, r, q, p1, p2, p3, p4, p5, p6, n1, n2, n3, E_or_F);
				break;
			} 
//VH===============================================================
			else if (m1 == 1){
				double p1  = dlewis[6];
				double p2  = dlewis[7];
				double p3  = dlewis[8];
				double p4  = dlewis[9];
				
				int    n1  = 0;
				int    n2  = 0;
				
				u = formOfVH(r2, r, q, p1, p2, p3, p4, n1, n2, E_or_F);
				break;		
			}
//CV===============================================================
			else if (m1 == 4){
                                double p1  = dlewis[10];
                                double p2  = dlewis[11];
                                double p3  = dlewis[12];
                                double p4  = dlewis[13];
				
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];
				
                                u = formOfXV(r2, r, q, p1, p2, p3, p4, n1, n2, n3, E_or_F);
				break;
			}
//NV===============================================================
			else if (m1 == 5){
                                double p1  = dlewis[14];
                                double p2  = dlewis[15];
                                double p3  = dlewis[16];
                                double p4  = dlewis[17];
				
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];
				
                                u = formOfXV(r2, r, q, p1, p2, p3, p4, n1, n2, n3, E_or_F);
				break;	
			}
//OV===============================================================
			else if (m1 == 6){
                                double p1  = dlewis[18];
                                double p2  = dlewis[19];
                                double p3  = dlewis[20];
                                double p4  = dlewis[21];
				
                                int    n1  = (int) dlewis[n_potentials + 3];
                                int    n2  = (int) dlewis[n_potentials + 4];
                                int    n3  = (int) dlewis[n_potentials + 5];
				
                                u = formOfXV(r2, r, q, p1, p2, p3, p4, n1, n2, n3, E_or_F);
				break;
			}

*/
		case 1:
//HH===============================================================
			if (m1 == m2){
                                double p1  = parHH[0];
                                double p2  = parHH[1];
                                double p3  = parHH[2];
                                double p4  = parHH[3];
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
	                        int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfHH(r2, r, q, p1, p2, p3, p4, n1, n2, E_or_F, items);
				break;		
			}
//CH===============================================================
			else if (m1 == 6){
                                double p1  = parCH[0];
                                double p2  = parCH[2];
                                double p3  = parCH[3];
                                double p4  = parCH[4];
				
                                int    n1  = (int) dlewis[n_potentials + 6];
                                int    n2  = (int) dlewis[n_potentials + 7];
                                int    n3  = (int) dlewis[n_potentials + 8];
                                int    n4  = (int) dlewis[n_potentials + 9];
				
                                u = formOfXH(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
				break;
			}
//NH===============================================================
			else if (m1 == 7){
                                double p1  = parNH[0];
                                double p2  = parNH[1];
                                double p3  = parNH[2];
                                double p4  = parNH[3];
				
                                int    n1  = (int) dlewis[n_potentials + 6];
                                int    n2  = (int) dlewis[n_potentials + 7];
                                int    n3  = (int) dlewis[n_potentials + 8];
                                int    n4  = (int) dlewis[n_potentials + 9];
				
                                u = formOfXH(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
				break;
			}
//OH===============================================================
			else if (m1 == 8){
                                double p1  = parOH[0];
                                double p2  = parOH[1];
                                double p3  = parOH[2];
                                double p4  = parOH[3];
				
                                int    n1  = (int) dlewis[n_potentials + 6];
                                int    n2  = (int) dlewis[n_potentials + 7];
                                int    n3  = (int) dlewis[n_potentials + 8];
                                int    n4  = (int) dlewis[n_potentials + 9];
				
                                u = formOfXH(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
				break;
			}
//SH===============================================================
			/*else if (m1 ==16){
                                double p1  = 1.0;
                                double p2  = 1.0;
                                double p3  = 1.0;
                                double p4  = 1.0;
				
                                int    n1  = (int) dlewis[n_potentials + 6];
                                int    n2  = (int) dlewis[n_potentials + 7];
                                int    n3  = (int) dlewis[n_potentials + 8];
                                int    n4  = (int) dlewis[n_potentials + 9];
				
                                u = formOfXH(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
				break;
			}*/
//MH===============================================================
			/*else if (m1 ==300){
                                double p1  = 1.0;
                                double p2  = 1.0;
                                double p3  = 1.0;
                                double p4  = 1.0;
				
                                int    n1  = 0;
                                int    n2  = 0;
				
                                u = formOfMH(r2, r, q, p1, p2, p3, p4, n1, n2, E_or_F);
				break;
			}
			else {
				exitEnergy(m1, m2);
				break;
			}*/

		case 5:
//BB================================================================
                        if (m1 == m2){
                                double p1  = parCC[0];
                                double p2  = parCC[1];
                                double p3  = parCC[2];
                                double p4  = parCC[3];

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];

                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
                                break;
                        }


		case 6:
//CC===============================================================
			if (m1 == m2){
                                double p1  = parCC[0];
                                double p2  = parCC[1];
                                double p3  = parCC[2];
                                double p4  = parCC[3];

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];

                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
				break;
			}
//CN===============================================================
			else if (m1 == 7){
                                double p1  = parCN[0];
                                double p2  = parCN[1];
                                double p3  = parCN[2];
                                double p4  = parCN[3];

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];

                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
				break;
			}
//CO===============================================================
			else if (m1 == 8){
                                double p1  = parCO[0];
                                double p2  = parCO[1];
                                double p3  = parCO[2];
                                double p4  = parCO[3];

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];

                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
				break;
			}
//CS===============================================================
			/*else if (m1 ==16){
				double p1  = 1.0;
				double p2  = 1.0;
                                double p3  = 1.0;
                                double p4  = 1.0;

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];

                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
				break;
			}*/
//CM===============================================================
			/*else if (m1 ==300){
				double p1  = 1.0;
				double p2  = 1.0;
                                double p3  = 1.0;
                                double p4  = 1.0;

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfXM(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
				break;
			}
			else {
				exitEnergy(m1, m2);
				break;
			}*/

		case 7:
//NN===============================================================
			if (m1 == m2){
                                double p1  = parNN[0];
                                double p2  = parNN[1];
                                double p3  = parNN[2];
                                double p4  = parNN[3];
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
				break;
			}
//NO===============================================================
			else if (m1 == 8){
                                double p1  = parNO[0];
                                double p2  = parNO[1];
                                double p3  = parNO[2];
                                double p4  = parNO[3];
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
				break;
			}
//NS===============================================================
			/*else if (m1 ==16){
				double p1  = 1.0;
				double p2  = 1.0;
                                double p3  = 1.0;
                                double p4  = 1.0;
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
				break;	
			}*/
//NM===============================================================
			/*else if (m1 ==300){
				double p1   = 1.0;
				double p2   = 1.0;
                                double p3   = 1.0;
                                double p4   = 1.0;
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfXM(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
				break;
			}
			else {
				exitEnergy(m1, m2);
				break;
			}*/
		
		case 8:
//OO===============================================================
			if (m1 == m2){
				double p1  = parOO[0];
				double p2  = parOO[1];
                                double p3  = parOO[2];
                                double p4  = parOO[3];
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
				break;
			}
//OS===============================================================
			/*else if (m1 ==16){
				double p1  = 1.0;
				double p2  = 1.0;
                                double p3  = 1.0;
                                double p4  = 1.0;
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
				break;
			}*/
//OM===============================================================
			/*else if (m1 ==300){
				double p1  = 1.0;
				double p2  = 1.0;
                                double p3  = 1.0;
                                double p4  = 1.0;
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfXM(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
				break;
			}
			else {
				exitEnergy(m1, m2);
				break;
			}*/
		case 9:
//FF===============================================================
                        if (m1 == m2){
                                double p1  = parOO[0];
                                double p2  = parOO[1];
                                double p3  = parOO[2];
                                double p4  = parOO[3];

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];

                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
                                break;
                        }

                case 13:
//AlAl=============================================================
                        if (m1 == m2){
                                double p1  = parOO[0];
                                double p2  = parOO[1];
                                double p3  = parOO[2];
                                double p4  = parOO[3];

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];

                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
                                break;
                        }

                case 14:
//SiSi=============================================================
                        if (m1 == m2){
                                double p1  = parOO[0];
                                double p2  = parOO[1];
                                double p3  = parOO[2];
                                double p4  = parOO[3];

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];

                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
                                break;
                        }

                case 15:
//PP===============================================================
                        if (m1 == m2){
                                double p1  = parOO[0];
                                double p2  = parOO[1];
                                double p3  = parOO[2];
                                double p4  = parOO[3];

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];

                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
                                break;
                        }
		
		case 16:
//SS===============================================================
			if (m1 == m2){
				double p1  = 1.0;
				double p2  = 1.0;
                                double p3  = 1.0;
                                double p4  = 1.0;
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
				break;
			}
//SM===============================================================
			/*else if (m1 ==300){
				double p1  = 1.0;
				double p2  = 1.0;
                                double p3  = 1.0;
                                double p4  = 1.0;
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfXM(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
				break;
			}
			else {
				exitEnergy(m1, m2);
				break;
			}*/

                case 17:
//ClCl===============================================================
                        if (m1 == m2){
                                double p1  = parOO[0];
                                double p2  = parOO[1];
                                double p3  = parOO[2];
                                double p4  = parOO[3];

                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];

                                u = formOfXY(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F, items);
                                break;
                        }


		//case 300:
//MM===============================================================
			/*if (m1 == m2){
				double p1  = 1.0;
				double p2  = 1.0;
                                double p3  = 1.0;
                                double p4  = 1.0;
				
                                int    n1  = (int) dlewis[n_potentials + 10];
                                int    n2  = (int) dlewis[n_potentials + 11];
                                int    n3  = (int) dlewis[n_potentials + 12];
                                int    n4  = (int) dlewis[n_potentials + 13];
				
                                u = formOfMM(r2, r, q, p1, p2, p3, p4, n1, n2, n3, n4, E_or_F);
				break;
			}
			else {
				exitEnergy(m1, m2);
				break;
			}*/
                case 200:
//Qq===============================================================
                        if (m1 > m2){
                                double p1  = 0.0;
                                double p2  = 0.0;
                                double p3  = 0.0;
                                double p4  = 0.0;

                                int    n1  = (int) dlewis[n_potentials + 14];
                                int    n2  = (int) dlewis[n_potentials + 15];

                                u = formOfHH(r2, r, q, p1, p2, p3, p4, n1, n2, E_or_F, items);
                                break;
                        }



                default:
                        exitEnergy(m1, m2);
                        break;
        }

        switch (m1){

                case 200:
//Qq===============================================================
                        if (m1 > m2){
                                double p1  = 0.0;
                                double p2  = 0.0;
                                double p3  = 0.0;
                                double p4  = 0.0;

                                int    n1  = (int) dlewis[n_potentials + 14];
                                int    n2  = (int) dlewis[n_potentials + 15];

                                u = formOfHH(r2, r, q, p1, p2, p3, p4, n1, n2, E_or_F, items);
                                break;
                        }


		default:
			exitEnergy(m1, m2);
			break;
	}

	return u;
		
}


