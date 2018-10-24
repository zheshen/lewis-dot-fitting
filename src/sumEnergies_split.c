//getEnergies.c
//by Seyit on March, 17 2009
//WS139.84

#include "Energy.h"

//double energy(double, double, double, int, int, int);

//Sum energies for 2nd row hydrides and Lewis structures
double *sumEnergies_split(V * Vin,  int part){

	//extern int print;
	//extern int icue_spinOplus5;
	double d_x, d_y, d_z;
	double r2, r;
	double Rn2, Rn;
	double Ri, Rj;
	double mid_x, mid_y, mid_z;
	int i, j,k,l;
	int NumNuc;
//	double di2, dj2, dij2, dij;
//	extern double parKE[];
	static double items[10];                       //  array to store different energy contributions
//	static double items2[10];
	int flag;
	for (i = 0; i<10; i++){
		items[i] = 0.0;
//		items2[i] = 0.0;
	}
	struct V Vx[part];

	double sum = 0;
	k = 0;
	//Single loop through particles: Calculate KE & set Nuclei array
        for (i = 0; i < part; i++){
		Vx[i].s=-3;//so that old information in Vx is removed and doesn't cause problem
                
                //KE for electrons
                if (Vin[i].q==-1){
                        sum += kineticEnergy(Vin[i].d, ENERGY);
//                        sum += kineticEnergy( Vin[i].dr, Vin[i].di, ENERGY);
//                        items[0] += kineticEnergy( Vin[i].dr, Vin[i].di, ENERGY);
                        items[0] += kineticEnergy(Vin[i].d, ENERGY);
//			items2[0] += kineticEnergy( Vin[i].d, ENERGY);
                }
        
                //Identifying kernels & creating kernel struct
                if(Vin[i].q>0){
			Vx[k].x=Vin[i].x;
                        Vx[k].y=Vin[i].y;
                        Vx[k].z=Vin[i].z;
                        Vx[k].d=Vin[i].d;
                        Vx[k].s=Vin[i].s;
			Vx[k].q=Vin[i].q;
			k++;
                }

        NumNuc=k;//total number of kernels in the species
        }

	//Double loop through particles: Calculate pairwise & send out 3body information
	for (i = 0; i < part; i++){
		for (j = i + 1; j < part; j++){
			
			d_x = Vin[i].x - Vin[j].x;
			d_y = Vin[i].y - Vin[j].y;
			d_z = Vin[i].z - Vin[j].z;
                        r2 = d_x * d_x + d_y * d_y + d_z * d_z;
                        r = sqrt(r2);

			sum += energy(&Vin[i], &Vin[j], ENERGY);
			flag = energy_split(&Vin[i], &Vin[j], ENERGY, items);
//			sum += energy(&Vin[i], &Vin[j], r2, r, Vin[i].dr, Vin[j].dr, Vin[i].di, Vin[j].di, Vin[i].q, Vin[j].q, Vin[i].s, Vin[j].s, ENERGY);
//			flag = energy_split(&Vin[i], & Vin[j], r2, r, Vin[i].dr, Vin[j].dr, Vin[i].di, Vin[j].di, Vin[i].q, Vin[j].q, Vin[i].s, Vin[j].s, ENERGY, items);
//			items2[flag] += energy(r2, r, Vin[i].d, Vin[j].d, Vin[i].q, Vin[j].q, Vin[i].s, Vin[j].s, ENERGY);
                        //AA & BB midpoint coordinate calculation
                        if((Vin[i].s==Vin[j].s)&&(Vin[j].q==-1)){
                                mid_x=(Vin[i].x + Vin[j].x)*0.5;
                                mid_y=(Vin[i].y + Vin[j].y)*0.5;
                                mid_z=(Vin[i].z + Vin[j].z)*0.5;
				for(l=0; l<part; l++){
					if ((l!=i)&&(l!=j)){
						d_x = Vin[l].x - mid_x;
						d_y = Vin[l].y - mid_y;
						d_z = Vin[l].z - mid_z;
						Rn2 = d_x * d_x + d_y * d_y + d_z * d_z;
						Rn = sqrt(Rn2);
						Ri = getR2Dist(Vin,i,Vin,l);
						Rj = getR2Dist(Vin,j,Vin,l);
						sum += TBenergy(&Vin[i], &Vin[j], &Vin[l], ENERGY);
						if (Vin[l].q != -1)
							items[5] += TBenergy(&Vin[i], &Vin[j], &Vin[l], ENERGY);
						else
							items[5] += 0;
//						sum += TBenergy(r2,r, Rn2, Rn, Ri, Rj, Vin[l].x, Vin[l].y, Vin[l].z, Vin[i].x, Vin[i].y, Vin[i].z, Vin[j].x, Vin[j].y, \
//Vin[j].z, Vin[i].dr, Vin[j].dr, Vin[i].di, Vin[j].di, Vin[l].q, Vin[l].s, ENERGY);
//						if (Vin[l].q != -1)
//							items[5] += TBenergy(r2,r, Rn2, Rn, Ri, Rj, Vin[l].x, Vin[l].y, Vin[l].z, Vin[i].x, Vin[i].y, Vin[i].z, Vin[j].x, Vin[j].y, \
//Vin[j].z, Vin[i].dr, Vin[j].dr, Vin[i].di, Vin[j].di, Vin[l].q, Vin[l].s, ENERGY);
//						else
//							items[4] += TBenergy(r2,r, Rn2, Rn, Ri, Rj, Vin[l].x, Vin[l].y, Vin[l].z, Vin[i].x, Vin[i].y, Vin[i].z, Vin[j].x, Vin[j].y, \
//Vin[j].z, Vin[i].dr, Vin[j].dr, Vin[i].di, Vin[j].di, Vin[l].q, Vin[l].s, ENERGY);
					}
				}
			}
//				for(k=0; k<NumNuc; k++){//go through all kernels for the AA pair
//					d_x = Vx[k].x - mid_x;
//                        		d_y = Vx[k].y - mid_y;
//                        		d_z = Vx[k].z - mid_z;
//                        		Rn2 = d_x * d_x + d_y * d_y + d_z * d_z;
//                        		Rn = sqrt(Rn2);
//					Ri = getR2Dist(Vin,i,Vx,k);
//					Rj = getR2Dist(Vin,j,Vx,k);
//					
//					sum += TBenergy(r2,r, Rn2, Rn, Ri, Rj, Vx[k].x, Vx[k].y, Vx[k].z, Vin[i].x, Vin[i].y, Vin[i].z, Vin[j].x, Vin[j].y, \
//Vin[j].z, Vin[i].d, Vin[j].d,Vx[k].q, Vx[k].s, ENERGY);
//					items[5] += TBenergy(r2,r, Rn2, Rn, Ri, Rj, Vx[k].x, Vx[k].y, Vx[k].z, Vin[i].x, Vin[i].y, Vin[i].z, Vin[j].x, Vin[j].y, \
//Vin[j].z, Vin[i].d, Vin[j].d,Vx[k].q, Vx[k].s, ENERGY);
//
//				}
                       

		
	/*		if((print)&&(r<0.0001))
		{
		printf("energy of %d and %d at r %f is %f\n",Vin[i].s, Vin[j].s, r, energy(r2, r, Vin[i].d, Vin[j].d, Vin[i].q, Vin[j].q, Vin[i].s, Vin[j].s, ENERGY));		
		printf("sumenergy of the same molecule is %f\n",sum);
		}*/
		}
	}
//	printf("items2  %f %f %f %f %f\n",items2[0],items2[2],items2[1],items2[4],items2[3]);
	return items;
	
}



/*
void setDvalue(struct V * Vin, int part){
	int i;
	for (i=0; i<part; i++){
		if (Vin[i].q > 0)
			Vin[i].d = 0;
	}
}
*/
