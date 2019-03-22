
 /**************************************************************
 * Purpose                                                     *
 * This program is intended to calculate the total energy of   *
 * a particular fixed structure given a set of parameters.     *
 **************************************************************/
 
#include "Energy.h"

//double energy(double, double, double, int, int, int);

//Sum energies for 2nd row hydrides and Lewis structures
double sumEnergies(V * Vin,  int part){
	return sumEnergies_split(Vin, part, NULL);
}


double sumEnergies_split(V * Vin,  int part,  double *items){

	//extern int print;
	//extern int icue_spinOplus5;
	double d_x, d_y, d_z;
	double r2, r;
	double Rn2, Rn;
	double Ri, Rj;
	double mid_x, mid_y, mid_z;
	int i, j,k,l;
	double Qtot;
	int NumNuc;
//	double di2, dj2, dij2, dij;
//	extern double parKE[];

	struct V Vx[part];

	double sum = 0;
	k = 0;
	//Single loop through particles: Calculate KE & set Nuclei array
        for (i = 0; i < part; i++){
		Vx[i].s=-3;//so that old information in Vx is removed and doesn't cause problem
                
                //KE for electrons
                if (Vin[i].q==-1){
                        sum += kineticEnergy_split(Vin[i].d, Vin[i].eta, Vin[i].zeta, ENERGY, items);
                }
        
                //Identifying kernels & creating kernel struct
                if(Vin[i].q>0){
			Vx[k].x=Vin[i].x;
                        Vx[k].y=Vin[i].y;
                        Vx[k].z=Vin[i].z;
                        Vx[k].d=Vin[i].d;
                        Vx[k].eta=Vin[i].eta;
                        Vx[k].zeta=Vin[i].zeta;
                        Vx[k].s=Vin[i].s;
			Vx[k].q=Vin[i].q;
			k++;
                }

        	NumNuc=k;//total number of kernels in the species
        }

	Qtot = 0.0;
	for (i = 0; i < part; i++){
		Qtot += Vin[i].q;
	}
	Qtot = Qtot + 2.0;	

	//Double loop through particles: Calculate pairwise & send out 3body information
	for (i = 0; i < part; i++){
		for (j = i + 1; j < part; j++){
			
//			d_x = Vin[i].x - Vin[j].x;
//			d_y = Vin[i].y - Vin[j].y;
//			d_z = Vin[i].z - Vin[j].z;
//                      r2 = d_x * d_x + d_y * d_y + d_z * d_z;
//                      r = sqrt(r2);

//		        extern int diagnose_print;
//		        diagnose_print = 1;
//		        if (diagnose_print == 1)
//		                printf("Energy r %f, dr1 %f, dr2 %f, di1 %f, di2 %f\n", r, Vin[i].dr, Vin[j].dr, Vin[i].di, Vin[j].di);
//		        diagnose_print = 0;
//			sum += energy(&Vin[i], &Vin[j], r2, r, Vin[i].dr, Vin[j].dr, Vin[i].di, Vin[j].di, Vin[i].q, Vin[j].q, Vin[i].s, Vin[j].s, ENERGY);
			sum += energy_split(&Vin[i], &Vin[j], Qtot, ENERGY, items);

                        //AA & BB midpoint coordinate calculation
//                        if((Vin[i].s==Vin[j].s)&&(Vin[j].q==-1)){
//                                mid_x=(Vin[i].x + Vin[j].x)*0.5;
//                                mid_y=(Vin[i].y + Vin[j].y)*0.5;
//                                mid_z=(Vin[i].z + Vin[j].z)*0.5;
//				for(l=0; l<part; l++){
//					if ((l!=i)&&(l!=j)){
//						d_x = Vin[l].x - mid_x;
//						d_y = Vin[l].y - mid_y;
//						d_z = Vin[l].z - mid_z;
//						Rn2 = d_x * d_x + d_y * d_y + d_z * d_z;
//						Rn = sqrt(Rn2);
//						Ri = getR2Dist(Vin,i,Vin,l);
//						Rj = getR2Dist(Vin,j,Vin,l);
//        extern int diagnose_print;
//        diagnose_print = 1;
//        if (diagnose_print == 1)
//                printf("sumEnergy r %f, dr1 %f, dr2 %f, di1 %f, di2 %f\n", r, Vin[i].dr, Vin[j].dr, Vin[i].di, Vin[j].di);
//        diagnose_print = 0;
	
//						sum += TBenergy(r2,r, Rn2, Rn, Ri, Rj, Vin[l].x, Vin[l].y, Vin[l].z, Vin[i].x, Vin[i].y, Vin[i].z, Vin[j].x, Vin[j].y, \
//Vin[j].z, Vin[i].dr, Vin[j].dr, Vin[i].di, Vin[j].di, Vin[l].q, Vin[l].s, ENERGY);
//						if (Vin[l].q != -1)
//						sum += TBenergy_split(&Vin[i], &Vin[j], &Vin[l], r2, Rn2, ENERGY, items);
//						else
//							sum += TBenergy_split(&Vin[i], &Vin[j], &Vin[l], r2, Rn2, ENERGY, items);
//							sum += 0;
//					}
//				}
//                        }
			
		
	/*		if((print)&&(r<0.0001))
		{
		printf("energy of %d and %d at r %f is %f\n",Vin[i].s, Vin[j].s, r, energy(r2, r, Vin[i].d, Vin[j].d, Vin[i].q, Vin[j].q, Vin[i].s, Vin[j].s, ENERGY));		
		printf("sumenergy of the same molecule is %f\n",sum);
		}*/
		}
	}
	return sum;	
}




void setDvalue(V * Vin, int part){
	int i;
	for (i=0; i<part; i++){
		if (Vin[i].q > 0){
			Vin[i].d = 0;
			Vin[i].eta = 0;
			Vin[i].zeta = 0;
		}
	}
}
