/*************************************************************************************
 *                                   sumEnergies.c                                   *
 *                                                                                   *
 ************************************************************************************/

//#include "Common.h"
#include "Metropolis.h"
//#include "Wolf.h"

//Particle-particle energy calculation -the very first call
double sumEnergiesOne(struct V *vin, double **e_in, double **e_test, int p){

        double sum = 0;
        int i, j;
	struct V Vx[p];
	int NumNuc=0;

	getVx(vin,Vx,p,&NumNuc);

        //Pairwise energies (non-diagonal elements)
        for (i = 0; i < p; i++){
                for (j = i+1; j < p; j++){
                        e_in[i][j] = getPairwiseEnergy(vin, i, j);
			//printf("Pairwise i %i j %i ein %f etest %f \n", i, j, e_in[i][j], e_test[i][j]);
				if((vin[i].q==-1)&&(vin[i].s==vin[j].s)){//3 body term for likespin
		                	//printf("Pairwise i %i j %i ein %f etest %f \n", i, j, e_in[i][j], e_test[i][j]);
					//printf("Enter 3body term with %d nuclei and %d particles in total\n",NumNuc,p);
					e_in[i][j] += getTBenergy(vin,Vx,i,j,p);
					//printf("3body value: %f\n",getTBenergy(vin,Vx,i,j,NumNuc));
		                	//printf("Pairwise i %i j %i ein %f etest %f \n", i, j, e_in[i][j], e_test[i][j]);
				}
		}
	}
        //Kinetic energies (diagonal elements, electrons only)
        for (i = 0; i < p; i++){
        	if ((vin[i].s == 0) || (vin[i].s == -2) || (vin[i].s == 2))
                        e_in[i][i] = getKineticEnergy(vin, i);
                else
                        e_in[i][i] = 0.;
        }
	
        //Sum up energies -both pairwise and kinetic
        for (i = 0; i < p; i++)
                for (j = i; j < p; j++) //This loop should start with j=i.
                        e_test[i][j] = e_in[i][j];
	
        for (i = 0; i < p; i++)
                for (j = i; j < p; j++) //This loop should start with j=i.
                        sum += e_in[i][j];
	
	return sum;
}

//Particle-particle energy calculation - summing All
//This may look same as sumEnergiesOne, but it sets e_test and does not sync that with e_in at the end.
double sumEnergiesAll(struct V *vin, double **e_in, double **e_test, int p){

        double sum = 0;
        int i, j;
        struct V Vx[p];
        int NumNuc=0;

        getVx(vin,Vx,p,&NumNuc);
        //Pairwise energies (non-diagonal elements)
        for (i = 0; i < p; i++){
                for (j = i+1; j < p; j++){
                        e_test[i][j] = getPairwiseEnergy(vin, i, j);
                                if((vin[i].q==-1)&&(vin[i].s==vin[j].s)){//3 body term for likespin
                                        e_test[i][j] += getTBenergy(vin,Vx,i,j,p);
                                }
                }
        }
        //Kinetic energies (diagonal elements, electrons only)
        for (i = 0; i < p; i++){
                if ((vin[i].s == 0) || (vin[i].s == -2) || (vin[i].s == 2))
                        e_test[i][i] = getKineticEnergy(vin, i);
                else
                        e_test[i][i] = 0.;
        }

	//Summing all energies
        for (i = 0; i < p; i++)
                for (j = i; j < p; j++) //This loop should start with j=i.
                        sum += e_test[i][j];

	return sum;

}

//Particle-particle energy calculation -regular call
double sumEnergiesRegular(struct V *vv, double **ee_in, double **ee_t, int *isMoved, double sum, int p){
	
	double temp = sum;
	int i;
	int Xmove=0;

	for(i=0; i<p; i++)
		if((isMoved[i]==1)&&(vv[i].q>0))
			Xmove=1;

//	if(Xmove)//This is not the most efficient way, and in the future might need to change, when simulating bulk and etc.
		temp=sumEnergiesAll(vv, ee_in, ee_t, p);
	
//	else
//		for (i = 0; i < p; i++)
//			if (isMoved[i])
//				temp = sumEnergiesSmallParticle(vv, ee_in, ee_t, temp, i, p);
	
	return temp;
}

//Pairwise summation -for small particle movements
double sumEnergiesSmallParticle(struct V *vin, double **e_in, double **e_test, double sum, int c, int p){
	
        double temp = sum;
        int i;
        struct V Vx[p];
        int NumNuc=0;
	extern int debug;

        getVx(vin,Vx,p,&NumNuc);
	
        //Pairwise energies
        for (i = 0; i < c; i++){
                e_test[i][c] = getPairwiseEnergy(vin, i, c);
//		if (debug==1)
//		printf("Pairwise i %i c %i ein %f etest %f \n", i, c, e_in[i][c], e_test[i][c]);

               if((vin[c].q==-1)&&(vin[i].s==vin[c].s)){//3 body term for likespin
//		if (debug==1)
//                        printf("Moved Energy: Enter 3body term with %d nuclei and %d particles in total\n",NumNuc,p);
			e_test[i][c] += getTBenergy(vin,Vx,i,c,p);
//		if (debug==1)
//                        printf("Moved 3body value: %f\n",getTBenergy(vin,Vx,i,c,NumNuc));
//		if (debug==1)
//                        printf("Moved Pairwise i %i c %i ein %f etest %f \n", i, c, e_in[i][c], e_test[i][c]);
             }

                temp += e_test[i][c];
                temp -= e_in[i][c];
        }
	
        for (i = c+1; i < p; i++){
                e_test[c][i] = getPairwiseEnergy(vin, i, c);

               if((vin[c].q==-1)&&(vin[i].s==vin[c].s)){//3 body term for likespin
                        e_test[c][i] += getTBenergy(vin,Vx,i,c,p);
               }

                temp += e_test[c][i];
                temp -= e_in[c][i];
        }
	
        //Kinetic energy
        if ((vin[c].s == 0) || (vin[c].s == -2) || (vin[c].s == 2)) {
                e_test[c][c] = getKineticEnergy(vin, c);
                temp += e_test[c][c];
                temp -= e_in[c][c];
        }
	
	return temp;
	
}

//Update current and test energy matrices every MC step
void updateEarrays(double **ee_in, double **ee_t, int *isMoved, int p, int accept){

	int i;
	
	for (i = 0; i < p; i++)
		if (isMoved[i])	
			updateEarray(ee_in, ee_t, i, p, accept);
}

void updateEarray(double **ee_in, double **ee_t, int c, int p, int accept){
	
	int i;
	
	if (accept){
		for (i = 0; i < c; i++)
			ee_in[i][c] = ee_t[i][c];
		for (i = c; i < p; i++)
			ee_in[c][i] = ee_t[c][i];
	}
	else {
		for (i = 0; i < c; i++)
			ee_t[i][c] = ee_in[i][c];
		for (i = c; i < p; i++)
			ee_t[c][i] = ee_in[c][i];
	}
}

//Update position arrays depending on whether a step is accepted or not
void updatePositions(struct V *vin, struct V *vc, int *isMoved, int p, int accept){

	int i;
	
	for (i = 0; i < p; i++)
		if (isMoved[i])	
			updatePosition(vin, vc, i, accept);

}

void updatePosition(struct V *vin, struct V *vc, int c, int accept){

        if (accept){
                vin[c].x = vc[c].x;
                vin[c].y = vc[c].y;
                vin[c].z = vc[c].z;
                vin[c].d = vc[c].d;
                vin[c].eta = vc[c].eta;
                vin[c].zeta = vc[c].zeta;
        }
        else{
                vc[c].x = vin[c].x;
                vc[c].y = vin[c].y;
                vc[c].z = vin[c].z;
                vc[c].d = vin[c].d;
                vc[c].eta = vin[c].eta;
                vc[c].zeta = vin[c].zeta;
        }
}

void copyPositions(struct V *v1, struct V *v2, int p){
	
	int i;
	
	for (i = 0; i < p; i++){
                v1[i].x = v2[i].x;
                v1[i].y = v2[i].y;
                v1[i].z = v2[i].z;
                v1[i].d = v2[i].d;
                v1[i].eta = v2[i].eta;
                v1[i].zeta = v2[i].zeta;
                v1[i].q = v2[i].q;
                v1[i].s = v2[i].s;
	}
}

double getKineticEnergy(struct V *vv, int i){

        return kineticEnergy(vv[i].d, vv[i].eta, vv[i].zeta, ENERGY);

}

//Calculates distance and returns pairwise energy.
double getPairwiseEnergy(struct V *vv, int i, int j){

        double r2 = getR2(vv, i, j);
        double r  = sqrt(r2);

        return energy(&vv[i], &vv[j], ENERGY);
	
}

double getTBenergy(struct V *vv, struct V *Vx, int i, int j, int p){

	int k;
	double sum=0;
	double temp=0;
	double mid_x, mid_y, mid_z;
	double d_x, d_y, d_z;
        double Rn2 =0;
        double Rn =0;
	double Ri =0;
	double Rj =0;
        double r2 = getR2(vv, i, j);
        double r  = sqrt(r2);

        mid_x=(vv[i].x + vv[j].x)*0.5;
        mid_y=(vv[i].y + vv[j].y)*0.5;
        mid_z=(vv[i].z + vv[j].z)*0.5;

	for(k=0; k<p; k++){
		if((k!=i)&&(k!=j)){
	                d_x = vv[k].x - mid_x;
	                d_y = vv[k].y - mid_y;
	                d_z = vv[k].z - mid_z;
	                Rn2 = d_x * d_x + d_y * d_y + d_z * d_z;
	                Rn = sqrt(Rn2);
			Ri = getR2Dist(vv,i,vv,k);
			Rj = getR2Dist(vv,j,vv,k);
		
			temp=TBenergy(&vv[i], &vv[j], &vv[k], r2, Rn2, ENERGY);
	                //printf("Threebody energy value for i %d j %d and k %d gives AAX dist %f with energy %f\n",i,j,k,r,temp);
	                sum+= temp;
		}
	}

	return sum;
}

void getVx(struct V *vv, struct V *Vx, int p,int *NumNuc){
	int i, k;
	k=0;
        for (i = 0; i < p; i++){
                Vx[k].s=-3;//Setting Vx so that we don't have old values messing things up
		if(vv[i].q>0){
                        Vx[k].x=vv[i].x;
                        Vx[k].y=vv[i].y;
                        Vx[k].z=vv[i].z;
                        Vx[k].d=vv[i].d;
                        Vx[k].eta=vv[i].eta;
                        Vx[k].zeta=vv[i].zeta;
                        Vx[k].s=vv[i].s;
			Vx[k].q=vv[i].q;
                        k++;
		}
	}
	*NumNuc=k;
}
