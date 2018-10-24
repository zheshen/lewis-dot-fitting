#include "Structure.h"

extern double U_spinO3_linnett;					//declare structure energy                           

void specspinO3_linnett(Species * spec){				//define SPEC function for specific structure

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	strcpy(spec->fullname, "O3_linnett");			//Enter full name for the structure
	strcpy(spec->name, "O3_li");				//Enter abbreviation name
	strcpy(spec->spin, "a9b9");		//Enter spin structure
	spec->type = O3_linnett;				//Enter type name
	spec->complete = 0;					//Not used temporarily
	spec->kernel = 3;					//Not used temporarily
	spec->degFree = 16;					//Enter degree of freedom for the structure
	spec->numPart = 21;					//Enter number of particles for the structure
	spec->stepSize = 0.101;					//Enter the stepsize for optimization, default is 0.101
	spec->ainter = ainterspinO3_linnett;			//Enter the function name for "ainter" 
	spec->dev = devspinO3_linnett;			//Enter the function name for "dev"

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//Set memory space for spec
	Initialize(spec);

        //Initial Values expressed in Radians and Angstroms
        spec->ist[0] = 1.000000;					// distance of electron to the center 
        spec->ist[1] = 1.000000; 
        spec->ist[2] = 1.000000; 
        spec->ist[3] = 1.000000; 		
        spec->ist[4] = 3.000000;					// 1/radius^2
        spec->ist[5] = 3.000000;
        spec->ist[6] = 3.000000; 
        spec->ist[7] = 3.000000; 
        spec->ist[8] = 1.000000;					// eta
        spec->ist[9] = 1.000000;
        spec->ist[10] = 1.000000; 					// zeta
        spec->ist[11] = 1.000000; 
        spec->ist[12] = 0.001;						// rotation angle
        spec->ist[13] = 0.001; 
        spec->ist[14] = 0.001; 
        spec->ist[15] = 0.639000; 

        //translate initial values into log10 form for upnup, set Key
        int i;
        for(i = 0; i < spec->degFree; i++){
                spec->key[i] = 0;
                spec->sym[i] = log10(spec->ist[i]);
        }

        spec->sym[12] = log10((pi / spec->ist[0]) - 1);
        spec->sym[13] = log10((pi / spec->ist[0]) - 1);
        spec->sym[14] = log10((pi / spec->ist[0]) - 1);

	spec->key[12] = 1;
	spec->key[13] = 1;
	spec->key[14] = 1;

	if (fix_d){
		spec->key[4] = 0;
		spec->key[5] = 0;
		spec->key[6] = 0;
		spec->key[7] = 0;
		spec->sym[4] = log10(d_value);
		spec->sym[5] = log10(d_value);
		spec->sym[6] = log10(d_value);
		spec->sym[7] = log10(d_value);
		spec->key[8] = 0;
		spec->key[9] = 0;
		spec->key[10] = 0;
		spec->key[11] = 0;
		spec->sym[8] = log10(d_value);
		spec->sym[9] = log10(d_value);
		spec->sym[10] = log10(d_value);
		spec->sym[11] = log10(d_value);
	}

}


double ainterspinO3_linnett(Species * spec){
	
	int i, part;
	double Usum;
	part = spec->numPart;
        V Vin[part];

        double ra1	=	pow(10, spec->sym[0]);			//distance from O to electron alpha1's
        double rb1	=	pow(10, spec->sym[1]);			//distance from O to electron beta1's
        double ra2	=	pow(10, spec->sym[2]);			//distance from O to electron alpha1's
        double rb2	=	pow(10, spec->sym[3]);			//distance from O to electron beta1's
        
        double da1_r	=	pow(10, spec->sym[4]);			//diameter of electron alpha1's
        double db1_r	=	pow(10, spec->sym[6]);			//diameter of electron beta1's
        double da1_i	=	pow(10, spec->sym[5]);			//diameter of electron alpha2's
        double db1_i	=	pow(10, spec->sym[7]);			//diameter of electron beta2's

        double da2	=	pow(10, spec->sym[8]);			//diameter of electron alpha1's
        double db2	=	pow(10, spec->sym[9]);			//diameter of electron alpha2's
        double da3	=	pow(10, spec->sym[10]);			//diameter of electron beta1's
        double db3	=	pow(10, spec->sym[11]);			//diameter of electron beta2's

	double a	=	pi / (1 + pow(10, spec->sym[12]));	//rotation angle a
	double b	=	pi / (1 + pow(10, spec->sym[13]));	//rotation angle b
	double c	=	pi / (1 + pow(10, spec->sym[14]));	//rotation angle c

	double r_kernel	=	pow(10, spec->sym[15]);			//distance of kernel to center	

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

//        //Particle Positions
//        //O
//        Vin[0].x = 0.0;
//        Vin[0].y = 0.0;
//        Vin[0].z = 1.088;
//        Vin[0].q = 6;
//        Vin[0].s = 8;
//
//        //O
//        Vin[1].x = 0.0;
//        Vin[1].y = 0.0;
//        Vin[1].z = -1.088;
//        Vin[1].q = 6;
//        Vin[1].s = 8;
//
//        //O
//        Vin[2].x = 0.670;
//        Vin[2].y = 0.0;
//        Vin[2].z = 0.0;
//        Vin[2].q = 6;
//        Vin[2].s = 8;
//	
//	Vin[3].x = 0.916;
//	Vin[3].y = 0.492;
//	Vin[3].z = 0.095;
//	Vin[3].d = 3.0;
//	Vin[3].eta = 1;
//	Vin[3].zeta = 1;
//	Vin[3].q = -1;
//	Vin[3].s = -2;
//	
//	Vin[4].x = 0.905;
//	Vin[4].y = -0.486;
//	Vin[4].z = 0.1;
//	Vin[4].d = 3.0;
//	Vin[4].eta = 1;
//	Vin[4].zeta = 1;
//	Vin[4].q = -1;
//	Vin[4].s = -2;
//
//	Vin[5].x = 0.752;
//	Vin[5].y = 0.005;
//	Vin[5].z = -0.01;
//	Vin[5].d = 3;
//	Vin[5].eta = 1;
//	Vin[5].zeta = 1;
//	Vin[5].q = -1;
//	Vin[5].s = 2;
//
//	Vin[6].x = 0.402;
//	Vin[6].y = -0.477;
//	Vin[6].z = 0.655;
//	Vin[6].d = 3;
//	Vin[6].eta = 1;
//	Vin[6].zeta = 1;
//	Vin[6].q = -1;
//	Vin[6].s = -2;
//
//	Vin[7].x = -0.109;
//	Vin[7].y = -0.003;
//	Vin[7].z = 1.212;
//	Vin[7].d = 3;
//	Vin[7].eta = 1;
//	Vin[7].zeta = 1;
//	Vin[7].q = -1;
//	Vin[7].s = -2;
//
//	Vin[8].x = 0.393;
//	Vin[8].y = 0.501;
//	Vin[8].z = 0.654;
//	Vin[8].d = 3;
//	Vin[8].eta = 1;
//	Vin[8].zeta = 1;
//	Vin[8].q = -1;
//	Vin[8].s = -2;
//	
//	Vin[9].x = 0.102;
//	Vin[9].y = 0.006;
//	Vin[9].z = 0.391;
//	Vin[9].d = 3;
//	Vin[9].eta = 1;
//	Vin[9].zeta = 1;
//	Vin[9].q = -1;
//	Vin[9].s = 2;
//	
//	Vin[10].x = 0.610;
//	Vin[10].y = 0.018;
//	Vin[10].z = 1.181;
//	Vin[10].d = 3;
//	Vin[10].eta = 1;
//	Vin[10].zeta = 1;
//	Vin[10].q = -1;
//	Vin[10].s = 2;
//	
//	Vin[11].x = -0.232;
//	Vin[11].y = -0.495;
//	Vin[11].z = 1.21;
//	Vin[11].d = 3;
//	Vin[11].eta = 1;
//	Vin[11].zeta = 1;
//	Vin[11].q = -1;
//	Vin[11].s = 2;
//	
//	Vin[12].x = -0.277;
//	Vin[12].y = 0.461;
//	Vin[12].z = 1.224;
//	Vin[12].d = 3.0;
//	Vin[12].eta = 1;
//	Vin[12].zeta = 1;
//	Vin[12].q = -1;
//	Vin[12].s = 2;
//
//	Vin[13].x = 0.53;
//	Vin[13].y = 0.515;
//	Vin[13].z = -0.756;
//	Vin[13].d = 3;
//	Vin[13].eta = 1;
//	Vin[13].zeta = 1;
//	Vin[13].q = -1;
//	Vin[13].s = -2;
//
//	Vin[14].x = 0.518;
//	Vin[14].y = -0.528;
//	Vin[14].z = -0.75;
//	Vin[14].d = 3;
//	Vin[14].eta = 1;
//	Vin[14].zeta = 1;
//	Vin[14].q = -1;
//	Vin[14].s = -2;
//
//	Vin[15].x = -0.096;
//	Vin[15].y = 0.004;
//	Vin[15].z = -1.194;
//	Vin[15].d = 3;
//	Vin[15].eta = 1;
//	Vin[15].zeta = 1;
//	Vin[15].q = -1;
//	Vin[15].s = -2;
//	
//	Vin[16].x = -0.261;
//	Vin[16].y = 0.001;
//	Vin[16].z = -0.15;
//	Vin[16].d = 3;
//	Vin[16].eta = 1;
//	Vin[16].zeta = 1;
//	Vin[16].q = -1;
//	Vin[16].s = -2;
//	
//	Vin[17].x = 0.392;
//	Vin[17].y = 0.0;
//	Vin[17].z = -0.553;
//	Vin[17].d = 3;
//	Vin[17].eta = 1;
//	Vin[17].zeta = 1;
//	Vin[17].q = -1;
//	Vin[17].s = 2;
//	
//	Vin[18].x = 0.087;
//	Vin[18].y = 0.506;
//	Vin[18].z = -1.337;
//	Vin[18].d = 3;
//	Vin[18].eta = 1;
//	Vin[18].zeta = 1;
//	Vin[18].q = -1;
//	Vin[18].s = 2;
//	
//	Vin[19].x = 0.143;
//	Vin[19].y = -0.463;
//	Vin[19].z = -1.386;
//	Vin[19].d = 3.0;
//	Vin[19].eta = 1;
//	Vin[19].zeta = 1;
//	Vin[19].q = -1;
//	Vin[19].s = 2;
//
//	Vin[20].x = -0.556;
//	Vin[20].y = -0.034;
//	Vin[20].z = -0.781;
//	Vin[20].d = 3;
//	Vin[20].eta = 1;
//	Vin[20].zeta = 1;
//	Vin[20].q = -1;
//	Vin[20].s = 2;
//
//
//        //Particle Positions
//        //O
//        Vin[0].x = 0.0;
//        Vin[0].y = 0.0;
//        Vin[0].z = 1.088;
//        Vin[0].q = 6;
//        Vin[0].s = 8;
//
//        //O
//        Vin[1].x = 0.0;
//        Vin[1].y = 0.0;
//        Vin[1].z = -1.088;
//        Vin[1].q = 6;
//        Vin[1].s = 8;
//
//        //O
//        Vin[2].x = 0.670;
//        Vin[2].y = 0.0;
//        Vin[2].z = 0.0;
//        Vin[2].q = 6;
//        Vin[2].s = 8;
//	
//	Vin[3].x = 1.005;
//	Vin[3].y = 0.58;
//	Vin[3].z = 0.0;
//	Vin[3].d = 3.0;
//	Vin[3].eta = 1;
//	Vin[3].zeta = 1;
//	Vin[3].q = -1;
//	Vin[3].s = 2;
//	
//	Vin[4].x = 1.005;
//	Vin[4].y = -0.58;
//	Vin[4].z = 0.0;
//	Vin[4].d = 3.0;
//	Vin[4].eta = 1;
//	Vin[4].zeta = 1;
//	Vin[4].q = -1;
//	Vin[4].s = 2;
//
//	Vin[5].x = 0.0;
//	Vin[5].y = 0.0;
//	Vin[5].z = 0.0;
//	Vin[5].d = 3;
//	Vin[5].eta = 1;
//	Vin[5].zeta = 1;
//	Vin[5].q = -1;
//	Vin[5].s = 2;
//
//	Vin[6].x = 0.67;
//	Vin[6].y = 0.0;
//	Vin[6].z = 0.0;
//	Vin[6].d = 3;
//	Vin[6].eta = 1;
//	Vin[6].zeta = 1;
//	Vin[6].q = -1;
//	Vin[6].s = -2;
//
//	Vin[7].x = 0.49;
//	Vin[7].y = 0.47;
//	Vin[7].z = 0.78;
//	Vin[7].d = 3;
//	Vin[7].eta = 1;
//	Vin[7].zeta = 1;
//	Vin[7].q = -1;
//	Vin[7].s = 2;
//
//	Vin[8].x = 0.49;
//	Vin[8].y = -0.47;
//	Vin[8].z = 0.78;
//	Vin[8].d = 3;
//	Vin[8].eta = 1;
//	Vin[8].zeta = 1;
//	Vin[8].q = -1;
//	Vin[8].s = 2;
//	
//	Vin[9].x = 0.335;
//	Vin[9].y = 0.0;
//	Vin[9].z = 0.544;
//	Vin[9].d = 3;
//	Vin[9].eta = 1;
//	Vin[9].zeta = 1;
//	Vin[9].q = -1;
//	Vin[9].s = -2;
//	
//	Vin[10].x = 0.0;
//	Vin[10].y = 0.0;
//	Vin[10].z = 1.088;
//	Vin[10].d = 3;
//	Vin[10].eta = 1;
//	Vin[10].zeta = 1;
//	Vin[10].q = -1;
//	Vin[10].s = 2;
//	
//	Vin[11].x = -0.136;
//	Vin[11].y = 0.47;
//	Vin[11].z = 0.852;
//	Vin[11].d = 3;
//	Vin[11].eta = 1;
//	Vin[11].zeta = 1;
//	Vin[11].q = -1;
//	Vin[11].s = -2;
//	
//	Vin[12].x = -0.136;
//	Vin[12].y = -0.47;
//	Vin[12].z = 0.852;
//	Vin[12].d = 3.0;
//	Vin[12].eta = 1;
//	Vin[12].zeta = 1;
//	Vin[12].q = -1;
//	Vin[12].s = -2;
//
//	Vin[13].x = 0.136;
//	Vin[13].y = 0.0;
//	Vin[13].z = 1.324;
//	Vin[13].d = 3;
//	Vin[13].eta = 1;
//	Vin[13].zeta = 1;
//	Vin[13].q = -1;
//	Vin[13].s = -2;
//
//	Vin[14].x = 0.49;
//	Vin[14].y = 0.47;
//	Vin[14].z = -0.78;
//	Vin[14].d = 3;
//	Vin[14].eta = 1;
//	Vin[14].zeta = 1;
//	Vin[14].q = -1;
//	Vin[14].s = 2;
//
//	Vin[15].x = 0.49;
//	Vin[15].y = -0.47;
//	Vin[15].z = -0.78;
//	Vin[15].d = 3;
//	Vin[15].eta = 1;
//	Vin[15].zeta = 1;
//	Vin[15].q = -1;
//	Vin[15].s = 2;
//	
//	Vin[16].x = 0.335;
//	Vin[16].y = 0.0;
//	Vin[16].z = -0.544;
//	Vin[16].d = 3;
//	Vin[16].eta = 1;
//	Vin[16].zeta = 1;
//	Vin[16].q = -1;
//	Vin[16].s = -2;
//	
//	Vin[17].x = 0.0;
//	Vin[17].y = 0.0;
//	Vin[17].z = -1.088;
//	Vin[17].d = 3;
//	Vin[17].eta = 1;
//	Vin[17].zeta = 1;
//	Vin[17].q = -1;
//	Vin[17].s = 2;
//	
//	Vin[18].x = -0.136;
//	Vin[18].y = 0.47;
//	Vin[18].z = -0.852;
//	Vin[18].d = 3;
//	Vin[18].eta = 1;
//	Vin[18].zeta = 1;
//	Vin[18].q = -1;
//	Vin[18].s = -2;
//	
//	Vin[19].x = -0.136;
//	Vin[19].y = -0.47;
//	Vin[19].z = -0.852;
//	Vin[19].d = 3.0;
//	Vin[19].eta = 1;
//	Vin[19].zeta = 1;
//	Vin[19].q = -1;
//	Vin[19].s = -2;
//
//	Vin[20].x = 0.136;
//	Vin[20].y = 0.0;
//	Vin[20].z = -1.324;
//	Vin[20].d = 3;
//	Vin[20].eta = 1;
//	Vin[20].zeta = 1;
//	Vin[20].q = -1;
//	Vin[20].s = -2;
//
        //Particle Positions
        //O
        Vin[0].x = 0.0;
        Vin[0].y = 0.0;
        Vin[0].z = 1.088;
        Vin[0].q = 6;
        Vin[0].s = 8;

        //O
        Vin[1].x = 0.0;
        Vin[1].y = 0.0;
        Vin[1].z = -1.088;
        Vin[1].q = 6;
        Vin[1].s = 8;

        //O
        Vin[2].x = 0.670;
        Vin[2].y = 0.0;
        Vin[2].z = 0.0;
        Vin[2].q = 6;
        Vin[2].s = 8;
	
	Vin[3].x = 0.70;
	Vin[3].y = 0.0;
	Vin[3].z = 0.0;
	Vin[3].d = 3.0;
	Vin[3].eta = 1;
	Vin[3].zeta = 1;
	Vin[3].q = -1;
	Vin[3].s = 2;
	
	Vin[4].x = 0.70;
	Vin[4].y = -0.0;
	Vin[4].z = 0.0;
	Vin[4].d = 3.0;
	Vin[4].eta = 1;
	Vin[4].zeta = 1;
	Vin[4].q = -1;
	Vin[4].s = -2;

	Vin[5].x = 0.335;
	Vin[5].y = 0.500;
	Vin[5].z = 0.544;
	Vin[5].d = 3;
	Vin[5].eta = 1;
	Vin[5].zeta = 1;
	Vin[5].q = -1;
	Vin[5].s = -2;

	Vin[6].x = 0.335;
	Vin[6].y = -0.500;
	Vin[6].z = 0.544;
	Vin[6].d = 3;
	Vin[6].eta = 1;
	Vin[6].zeta = 1;
	Vin[6].q = -1;
	Vin[6].s = -2;

	Vin[7].x = 0.335;
	Vin[7].y = 0.0;
	Vin[7].z = 1.294;
	Vin[7].d = 3;
	Vin[7].eta = 1;
	Vin[7].zeta = 1;
	Vin[7].q = -1;
	Vin[7].s = -2;

	Vin[8].x = -0.335;
	Vin[8].y = 0.0;
	Vin[8].z = 0.882;
	Vin[8].d = 3;
	Vin[8].eta = 1;
	Vin[8].zeta = 1;
	Vin[8].q = -1;
	Vin[8].s = -2;
	
	Vin[9].x = 0.335;
	Vin[9].y = 0.0;
	Vin[9].z = 0.544;
	Vin[9].d = 3;
	Vin[9].eta = 1;
	Vin[9].zeta = 1;
	Vin[9].q = -1;
	Vin[9].s = 2;
	
	Vin[10].x = 0.0;
	Vin[10].y = 0.5;
	Vin[10].z = 1.088;
	Vin[10].d = 3;
	Vin[10].eta = 1;
	Vin[10].zeta = 1;
	Vin[10].q = -1;
	Vin[10].s = 2;
	
	Vin[11].x = 0.0;
	Vin[11].y = -0.5;
	Vin[11].z = 1.088;
	Vin[11].d = 3;
	Vin[11].eta = 1;
	Vin[11].zeta = 1;
	Vin[11].q = -1;
	Vin[11].s = 2;
	
	Vin[12].x = -0.335;
	Vin[12].y = 0.0;
	Vin[12].z = 1.632;
	Vin[12].d = 3.0;
	Vin[12].eta = 1;
	Vin[12].zeta = 1;
	Vin[12].q = -1;
	Vin[12].s = 2;

	Vin[13].x = 0.335;
	Vin[13].y = 0.500;
	Vin[13].z = -0.544;
	Vin[13].d = 3;
	Vin[13].eta = 1;
	Vin[13].zeta = 1;
	Vin[13].q = -1;
	Vin[13].s = 2;

	Vin[14].x = 0.335;
	Vin[14].y = -0.500;
	Vin[14].z = -0.544;
	Vin[14].d = 3;
	Vin[14].eta = 1;
	Vin[14].zeta = 1;
	Vin[14].q = -1;
	Vin[14].s = 2;

	Vin[15].x = 0.335;
	Vin[15].y = 0.0;
	Vin[15].z = -1.294;
	Vin[15].d = 3;
	Vin[15].eta = 1;
	Vin[15].zeta = 1;
	Vin[15].q = -1;
	Vin[15].s = 2;

	Vin[16].x = -0.335;
	Vin[16].y = 0.0;
	Vin[16].z = -0.882;
	Vin[16].d = 3;
	Vin[16].eta = 1;
	Vin[16].zeta = 1;
	Vin[16].q = -1;
	Vin[16].s = 2;
	
	Vin[17].x = 0.335;
	Vin[17].y = 0.0;
	Vin[17].z = -0.544;
	Vin[17].d = 3;
	Vin[17].eta = 1;
	Vin[17].zeta = 1;
	Vin[17].q = -1;
	Vin[17].s = -2;
	
	Vin[18].x = 0.0;
	Vin[18].y = 0.5;
	Vin[18].z = -1.088;
	Vin[18].d = 3;
	Vin[18].eta = 1;
	Vin[18].zeta = 1;
	Vin[18].q = -1;
	Vin[18].s = -2;
	
	Vin[19].x = 0.0;
	Vin[19].y = -0.5;
	Vin[19].z = -1.088;
	Vin[19].d = 3;
	Vin[19].eta = 1;
	Vin[19].zeta = 1;
	Vin[19].q = -1;
	Vin[19].s = -2;
	
	Vin[20].x = -0.335;
	Vin[20].y = 0.0;
	Vin[20].z = -1.632;
	Vin[20].d = 3.0;
	Vin[20].eta = 1;
	Vin[20].zeta = 1;
	Vin[20].q = -1;
	Vin[20].s = -2;


	//calculate structure energy
        if((MC_spinO3_linnett) && (spec->icue ==4)){
		for(i=0;i<4;i++){
                	metropolis(Vin, part,-2);//fix heavy
		}
                Usum = metropolis(Vin, part,-2);//fix heavy
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = Usum*1E3;
	U_spinO3_linnett = Usum;

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//asign coordinate to structure
        for (i=0; i<part; i++){
        spec->coord[i].x = Vin[i].x;
        spec->coord[i].y = Vin[i].y;
        spec->coord[i].z = Vin[i].z;
        spec->coord[i].d = Vin[i].d;
        spec->coord[i].eta = Vin[i].eta;
        spec->coord[i].zeta = Vin[i].zeta;
        spec->coord[i].q = Vin[i].q;
        spec->coord[i].s = Vin[i].s;
        }

	//return structure energy
        return Usum;

}


double devspinO3_linnett(Species *spec){

        double deviation = 0;
        double wTotal    = 0;
	double *items;
        FILE *OutFile;
	char Out[50];
        extern char directory[];
        extern int print;
        extern int pdbSwitch;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double fr1, bo, dp;
	const double real_bl = 1.28;
	const double real_bo = 1.0; 
	const double real_dp = 0.53;	

        //Current Positions
        if (MC_spinO3_linnett){
		fr1    = getDistance(spec->coord, 0, 2);
//		bo     = getBondOrder(spec->coord, spec->numPart, real_bl);
		dp     = getDipole(spec->coord, spec->numPart);
        }
		
	deviation = 100*fabs(real_dp-dp)/LENGTH;

	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spinO3_linnett){
			fprintf(OutFile,"| Kernel  dist          |      A     |   % 8.2f     |   -   |        -       |    %8.5f    |   N/A   |       -       |\n", real_bl, fr1);
			fprintf(OutFile,"| A1 1/radius^2         |    1/A^2   |      -         |   -   |        -       |%7.3f+%7.3fI|   N/A   |       -       |\n", creal(spec->coord[3].d), cimag(spec->coord[3].d));
			fprintf(OutFile,"| Lone A1  eta          |            |      -         |   -   |                |    %8.5f    |   N/A   |       -       |\n", spec->coord[3].eta);
			fprintf(OutFile,"| Lone A1  zeta         |            |      -         |   -   |                |    %8.5f    |   N/A   |       -       |\n", spec->coord[3].zeta);
//			fprintf(OutFile,"| Bond Order            |      -     |   % 8.2f     |   -   |        -       |    %8.2f    |   N/A   |  % 8.2e    |\n", real_bo, bo,deviation*100);
			fprintf(OutFile,"| Dipole                |      -     |   % 8.2f     |   -   |        -       |    %8.2f    |   N/A   |  % 8.2e    |\n", real_dp, dp, deviation);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	    	fclose(OutFile);
		printEnergy(U_spinO3_linnett);
	}

	//structure output
	sprintf(Out, "MC_spin%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spinO3_linnett)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	return deviation;

}
