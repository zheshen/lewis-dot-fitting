//metropolis.c
//Written by Seyit
 
#include "Metropolis.h"
//#include "Common.h"
//#include "Wolf.h"
//#include "Boundary.h"
//#include "Pressure.h"
//FRA
#include <omp.h>

//FRA's help
//int Met(double, long, double , double);
int rnd(int);
int irnd();
float ran2(long *);
//void output(struct V *, int, char[], double, int);

double metropolis(V *V_in, int p, int mc_type){

	double e_in, e_t, e_min, rr;
	double cm_x, cm_y, cm_z;
	double a_x, a_y, a_z;
	double b_x, b_y, b_z;
	double c_x, c_y, c_z;
	double distx, disty, distz;
	double alpha, beta, gamma;
	double cA, sA, cB, sB, cC, sC;
	int rot = 0, isBigStep = 0;
	int isSizeMove = 0, isElectron = 0, whichSize = 0;
	double transCount = 0, rotCount = 0, smallCount = 0, sizeCount = 0;
	double transAccept = 0, rotAccept = 0, smallAccept = 0, sizeAccept = 0;
	int accept;
	int steps = (int) (MC_STEPS);
	double T = (double) MC_TEMP;
	//long u;
	double mxj2small  = (double) MC_small_step; //0.002;
	double mxj2rigid  = (double) MC_rigid_step; //0.008;
	double mxj2angle  = (double) MC_angle_step; //0.010;
	double mxj2radius = (double) MC_radius_step; //0.00006;
	int allowed;
	
	int c, i, t = 0;

	extern int debug;	
	//u = -time(0);
	//srand(u);

        //FRA
        //
        //unsigned int myseed=myseeds[omp_get_thread_num()];
        //differentiating among threads might not be necessary, but just in case....
#ifdef OMP
        unsigned int myseed = time(NULL) + omp_get_thread_num();
#else
        unsigned int myseed = time(NULL) ;
#endif
	//

	
        struct V *V_min, *V_t;
	
        V_min = malloc(p * sizeof(struct V));
        V_t   = malloc(p * sizeof(struct V));
	
        if ((V_min == NULL) || (V_t == NULL))
                printf("FATAL: Malloc could not allocate structure arrays. \n");
	
	int isMoved[p];
	
	for (i = 0; i < p; i++)
		if ((V_in[i].s == 0) || (V_in[i].s == 2) || (V_in[i].s == -2))
		{ if(creal(V_in[i].d) <= 0)
			{V_in[i].d =  MC_D_INIT + 0.5*(V_in[i].d-conj(V_in[i].d));}
		}
	
	copyPositions(V_min, V_in, p);
	copyPositions(V_t, V_in, p);
	
	//Declare matrices for initial/test pairwise energies and interparticles distances
	double **ee_in, **ee_t;
	
	ee_in = malloc(p * sizeof(double *));
	ee_t  = malloc(p * sizeof(double *));
	
        if ((ee_in == NULL) || (ee_t == NULL))
                printf("FATAL: Malloc could not allocate energy matrices.\n ");
	
	for (i = 0; i < p; i++)
		ee_in[i] = malloc(p * sizeof(double));
	
	for (i = 0; i < p; i++)
                ee_t[i] = malloc(p * sizeof(double));
	
        for (i = 0; i < p; i++)
                if ((ee_in[i] == NULL) || (ee_t[i] == NULL))
                        printf("FATAL: Malloc could not allocate energy matrices.\n ");
	
	//Calculate the first energies 
	e_in  = sumEnergiesOne(V_in, ee_in, ee_t, p);
	e_min = e_in;	e_t   = e_in;
	
	//Go trough the main loop
	for (t = 1; t <= steps; t++){
		
		//Reset moved or not information
		for (i = 0; i < p; i++)
			isMoved[i] = 0;
		
		//Reset test energy
		e_t = e_in;
                
		//Choose a random particle to move
		//FRA
                c = rand_r(&myseed) % p;
                //c = rand() % p;
		
		//Check whether moving the selected particle is permitted
		allowed = isAllowed(V_t, c, mc_type);
		if (!allowed)
			continue;
		
		isBigStep = 0;
		if (V_in[c].s > 3)
			isBigStep = 1;
		
		//Heavy particle -a rigid rotation or a translation
		if (isBigStep){
			//Chose whether to rotate (1) or translate (0)
			if (allowed == 2)
				rot = 1;
			else
                                //FRA 
                                rot = rand_r(&myseed) % 2;
                                //rot = rand() % 2;
			
			if (rot){
                                //FRA
                                alpha = 4 * pi * (drnd_r(&myseed) - 0.500) * mxj2angle;
                                beta  = 2 * pi * (drnd_r(&myseed) - 0.500) * mxj2angle;
                                gamma = 4 * pi * (drnd_r(&myseed) - 0.500) * mxj2angle;
                                //alpha = 4 * pi * (drnd() - 0.500) * mxj2angle;
                                //beta  = 2 * pi * (drnd() - 0.500) * mxj2angle;
                                //gamma = 4 * pi * (drnd() - 0.500) * mxj2angle;
                                //alpha = 4 * pi * (ran2(&u) - 0.500) * mxj2angle;
                                //beta  = 2 * pi * (ran2(&u) - 0.500) * mxj2angle;
                                //gamma = 4 * pi * (ran2(&u) - 0.500) * mxj2angle;
                                //Set cosines and sines
                                cA = cos(alpha); sA = sin(alpha);
                                cB = cos(beta ); sB = sin(beta );
                                cC = cos(gamma); sC = sin(gamma);   
				
	                        //Set up the test configuration
        	                for (i = 0; i < p; i++){
                                	//Get interparticle distance between c and i
                                        rr = getR2(V_in, i, c);
					
					//Check whether particle i is close to nucleus c
                                	if (rr < MC_R2_MAX){
                                        	cm_x = V_in[i].x - V_in[c].x;
                                        	cm_y = V_in[i].y - V_in[c].y;
                                        	cm_z = V_in[i].z - V_in[c].z;
                                        	//Alpha
                                        	a_x  =  cA * cm_x + sA * cm_y;
                                        	a_y  = -sA * cm_x + cA * cm_y;
                                        	a_z  =  cm_z;
                                        	//Beta
                                        	b_x  =  cB * a_x - sB * a_z;
                                        	b_y  =  a_y;
                                        	b_z  =  sB * a_x + cB * a_z;
                                        	//Gamma
                                        	c_x  =  cC * b_x + sC * b_y;
                                        	c_y  = -sC * b_x + cC * b_y;
                                        	c_z  = b_z;
                                        	//Add the center of mass and translation
                                        	V_t[i].x  = c_x + V_in[c].x;
                                        	V_t[i].y  = c_y + V_in[c].y; 
                                        	V_t[i].z  = c_z + V_in[c].z;                                 
                                        	//Mark this particle as 'moved'
                                        	isMoved[i] = 1;
                                	}
				}	
			}
			else{
                                //FRA
                                distx = (drnd_r(&myseed)- 0.500) * mxj2rigid;
                                disty = (drnd_r(&myseed)- 0.500) * mxj2rigid;
                                distz = (drnd_r(&myseed)- 0.500) * mxj2rigid;
                                //distx = (drnd() - 0.500) * mxj2rigid;
                                //disty = (drnd() - 0.500) * mxj2rigid;
                                //distz = (drnd() - 0.500) * mxj2rigid;
                                //distx = (ran2(&u) - 0.500) * mxj2rigid;
                                //disty = (ran2(&u) - 0.500) * mxj2rigid;
                                //distz = (ran2(&u) - 0.500) * mxj2rigid;
				
                                //Set up the test configuration
        	                for (i = 0; i < p; i++){
                                        //Get interparticle distance between c and i
                                        rr = getR2(V_in, i, c);
					
                                        //Check whether particle i is close to nucleus c
                                        if (rr < MC_R2_MAX){
                                        	V_t[i].x  += distx;
                                        	V_t[i].y  += disty;
                                        	V_t[i].z  += distz;
						isMoved[i] = 1;
					}
				}
			}
	                //End of rigid particle movement
                }
                //Small particle -simple translation of a single particle
                else {
			if ((V_t[c].s == 0) || (V_t[c].s == 2) || (V_t[c].s == -2))
				isElectron = 1;
			else
				isElectron = 0;
			
			if (isElectron)
                                //FRA
                                isSizeMove = rand_r(&myseed) % 2;
                                //isSizeMove = rand() % 2;
			else
				isSizeMove = 0;
			
			if (!isSizeMove){
				//Determine amount of translation
                                //FRA
                                distx = (drnd_r(&myseed) - 0.500) * mxj2small;
                                disty = (drnd_r(&myseed) - 0.500) * mxj2small;
                                distz = (drnd_r(&myseed) - 0.500) * mxj2small;
	                	//distx = (drnd() - 0.500) * mxj2small;
        	        	//disty = (drnd() - 0.500) * mxj2small;
                		//distz = (drnd() - 0.500) * mxj2small;
	                	//distx = (ran2(&u) - 0.500) * mxj2small;
        	       		//disty = (ran2(&u) - 0.500) * mxj2small;
                		//distz = (ran2(&u) - 0.500) * mxj2small;
				//Translate the chosen particle
				V_t[c].x += distx;
				V_t[c].y += disty;
				V_t[c].z += distz;
			} else{  //If it's an electron size move vary size of electron
				whichSize = rand_r(&myseed) % 3;
                                //FRA 
                                if (whichSize == 0)
                                	V_t[c].d = fabs(creal(V_t[c].d) + ((drnd_r(&myseed) - 0.500) * mxj2radius)) + (cimag(V_t[c].d) + ((drnd_r(&myseed) - 0.500) * mxj2radius))*I;
				else if (whichSize == 1)
					V_t[c].eta = fabs(creal(V_t[c].eta) + ((drnd_r(&myseed) - 0.500) * mxj2radius));
				else if (whichSize == 2)
					V_t[c].zeta = fabs(creal(V_t[c].zeta) + ((drnd_r(&myseed) - 0.500) * mxj2radius));
				//V_t[c].d = fabs(V_t[c].d + ((drnd() - 0.500) * mxj2radius));
                                //V_t[c].d = fabs(V_t[c].d * (1+((drnd() - 0.500) * mxj2radius)));

				//V_t[c].d = fabs(V_t[c].d + ((ran2(&u) - 0.500) * mxj2radius));
			}
			//Mark particle c as 'moved'
			isMoved[c] = 1;		
			//End of small particle movement
		}
			
		//Calculation of test energy
		if (isBigStep)
			e_t = sumEnergiesRegular(V_t, ee_in, ee_t, isMoved, e_in, p);
		else
			e_t = sumEnergiesSmallParticle(V_t, ee_in, ee_t, e_in, c, p);

//	if(debug)	
//	printf("1e_min=%f\n",e_t);
		//Enter Metropolis algorithm
                //FRA
                //removed u
                accept = Met((double) T,  e_in, e_t,&myseed);
                //accept = Met((double) T, u, e_in, e_t,&myseed);
                //accept = Met((double) T, u, e_in, e_t);
		
//	if(debug)	
//	printf("accept=%d\n", accept);
		//Update current energy
		if (accept)
			e_in = e_t;
		else
			e_t = e_in;
		
		//Update structure and energy arrays
		if (isBigStep){
			updateEarrays(ee_in, ee_t, isMoved, p, accept);	
			updatePositions(V_in, V_t, isMoved, p, accept);
			if (rot){
				rotAccept += accept;
				rotCount  += 1;
			} else {
				transAccept += accept;
				transCount  += 1;
			}
		} else {
//	if(debug)	
//	printf("2accept=%d\n", accept);
			
			updateEarray(ee_in, ee_t, c, p, accept);
			updatePosition(V_in, V_t, c, accept);
			if (isSizeMove){
				sizeAccept += accept;
				sizeCount  += 1;
			} else {
				smallAccept += accept;
				smallCount  += 1;
//	if(debug)	
//	printf("3accept=%d, smallAccept=%f, smallCount=%f\n", accept, smallAccept, smallCount);
			}
		}
//	if(debug)	
//	printf("2e_min=%f accept=%d\n",e_min, accept);
		//Update minimum energy and minimum structure if necessary
		if (e_in < e_min){
			e_min = e_in;
			copyPositions(V_min, V_in, p);
		}
		
//	if(debug)	
//	printf("3e_min=%f\n",e_min);
		//Adjust step sizes 
		if ((t%(steps/100) == 0) && (t < steps/1)){
			if (smallCount){
//	if(debug)	
//	printf("smallAccept=%f, smallCount=%f, ratio=%f\n", smallAccept, smallCount, (smallAccept / smallCount));
				if ((smallAccept / smallCount) < .35)
					mxj2small  *= 0.9;
				if ((smallAccept / smallCount) > .45)
					mxj2small  *= 1.1;
				smallAccept = 0; smallCount = 0;
			}
			if (sizeCount){
				if ((sizeAccept / sizeCount) < .35)
					mxj2radius  *= 0.9;
				if ((sizeAccept / sizeCount) > .45)
					mxj2radius  *= 1.1;
				sizeAccept = 0; sizeCount = 0;
			}
			if (rotCount){
				if ((rotAccept / rotCount) < .01)
					mxj2angle *= 0.9;
				if ((rotAccept / rotCount) > .02)
					mxj2angle *= 1.1;
				rotAccept = 0; rotCount = 0;
			}
			if (transCount){
				if ((transAccept / transCount) < .10)
					mxj2rigid *= 0.9;
				if ((transAccept / transCount) > .45)
					mxj2rigid *= 1.1;
				transAccept = 0; transCount = 0;
			}
		}
	} //End of all Metropolis cycles
	
	//Set final minimum configuration
	copyPositions(V_in, V_min, p);
	
	//Now free the allocated energy matrices
	for (i = 0; i < p; i++){ 
		free(ee_t[i]);
		free(ee_in[i]);
	}
	
	//Also free the pointers to the matrices
	free(ee_t);
	free(ee_in);
	
	//Free the structure arrays
	free(V_min);
	free(V_t);
	
//	printf("trans ratio: %f rot ratio %f small ratio %f size ratio %f part %i \n", (transAccept/transCount) , (rotAccept/rotCount), (smallAccept/smallCount), (sizeAccept/sizeCount), p);
//	if (p == 11)
//		for(i = 0; i < p; i++)
//                	printf("  Particle %5i  |   % 8.2f     |   % 8.2f     |   % 8.2f     |   % 8.4f     |   % 8.2f     |\n", \
                        	i, V_in[i].x, V_in[i].y, V_in[i].z, V_in[i].d, V_in[i].q);
	
	return e_min;

}

