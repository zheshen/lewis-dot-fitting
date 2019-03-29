#include "Structure.h"

extern double U_spinC2_snglt_linnett;					//declare structure energy                           

void specspinC2_snglt_linnett(Species * spec){				//define SPEC function for specific structure

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	strcpy(spec->fullname, "C2_snglt_linnett");			//Enter full name for the structure
	strcpy(spec->name, "C2_sn_li");				//Enter abbreviation name
	strcpy(spec->spin, "a4b4");		//Enter spin structure
	spec->type = C2_snglt_linnett;				//Enter type name
	spec->complete = 0;					//Not used temporarily
	spec->kernel = 2;					//Not used temporarily
	spec->degFree = 16;					//Enter degree of freedom for the structure
	spec->numPart = 10;					//Enter number of particles for the structure
	spec->stepSize = 0.101;					//Enter the stepsize for optimization, default is 0.101
	spec->ainter = ainterspinC2_snglt_linnett;			//Enter the function name for "ainter" 
	spec->dev = devspinC2_snglt_linnett;			//Enter the function name for "dev"

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
        spec->ist[15] = 0.620000; 

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


double ainterspinC2_snglt_linnett(Species * spec){
	
	int i, part;
	double Usum;
	part = spec->numPart;
        V Vin[part];

        double ra1	=	pow(10, spec->sym[0]);			//distance from O to electron alpha1's
        double rb1	=	pow(10, spec->sym[1]);			//distance from O to electron beta1's
        double ra2	=	pow(10, spec->sym[2]);			//distance from O to electron alpha1's
        double rb2	=	pow(10, spec->sym[3]);			//distance from O to electron beta1's
        
        double da1_r	=	pow(10, spec->sym[4]);			//diameter of electron alpha1's
        double db1_r	=	pow(10, spec->sym[5]);			//diameter of electron beta1's
        double da1_i	=	pow(10, spec->sym[6]);			//diameter of electron alpha2's
        double db1_i	=	pow(10, spec->sym[7]);			//diameter of electron beta2's

        double da2	=	pow(10, spec->sym[8]);			//eta of electron alpha1's
        double db2	=	pow(10, spec->sym[9]);			//eta of electron alpha2's
        double da3	=	pow(10, spec->sym[10]);			//zeta of electron beta1's
        double db3	=	pow(10, spec->sym[11]);			//zeta of electron beta2's

	double a	=	pi / (1 + pow(10, spec->sym[12]));	//rotation angle a
	double b	=	pi / (1 + pow(10, spec->sym[13]));	//rotation angle b
	double c	=	pi / (1 + pow(10, spec->sym[14]));	//rotation angle c

	double r_kernel	=	pow(10, spec->sym[15]);			//distance of kernel to center, half of bond length	

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	Vin[0].x = 0.000;
	Vin[0].y = 0.000;
	Vin[0].z = 0.620;
	Vin[0].d = 0.000;
	Vin[0].q = 4;
	Vin[0].s = 6;

	Vin[1].x = 0.000;
	Vin[1].y = 0.000;
	Vin[1].z = -0.620;
	Vin[1].d = 0.000;
	Vin[1].q = 4;
	Vin[1].s = 6;

	Vin[2].x = -0.234;
	Vin[2].y = -0.396;
	Vin[2].z = 0.000;
	Vin[2].d = 0.547;
	Vin[2].q = -1;
	Vin[2].s = -2;

	Vin[3].x = -0.234;
	Vin[3].y = -0.397;
	Vin[3].z = 0.000;
	Vin[3].d = 0.547;
	Vin[3].q = -1;
	Vin[3].s = 2;

	Vin[4].x = 0.460;
	Vin[4].y = -0.005;
	Vin[4].z = 0.000;
	Vin[4].d = 0.547;
	Vin[4].q = -1;
	Vin[4].s = -2;

	Vin[5].x = -0.226;
	Vin[5].y = 0.401;
	Vin[5].z = 0.000;
	Vin[5].d = 0.547;
	Vin[5].q = -1;
	Vin[5].s = 2;

	Vin[6].x = 0.461;
	Vin[6].y = -0.004;
	Vin[6].z = 0.000;
	Vin[6].d = 0.548;
	Vin[6].q = -1;
	Vin[6].s = 2;

	Vin[7].x = -0.227;
	Vin[7].y = 0.401;
	Vin[7].z = 0.000;
	Vin[7].d = 0.547;
	Vin[7].q = -1;
	Vin[7].s = -2;

	Vin[8].x = -0.003;
	Vin[8].y = 0.000;
	Vin[8].z = 0.945;
	Vin[8].d = 0.557;
	Vin[8].q = -1;
	Vin[8].s = -2;

	Vin[9].x = 0.003;
	Vin[9].y = 0.000;
	Vin[9].z = -0.945;
	Vin[9].d = 0.557;
	Vin[9].q = -1;
	Vin[9].s = 2;


        //set d value
        setDvalue(Vin, part);

        //set shape value
        setShape(Vin, part);

	//calculate structure energy
        if((MC_spinC2_snglt_linnett) && (spec->icue ==4)){
		for(i=0;i<4;i++){
                	metropolis(Vin, part,-3);
		}
                Usum = metropolis(Vin, part,-3);
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = Usum*1E3;
	U_spinC2_snglt_linnett = Usum;

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


double devspinC2_snglt_linnett(Species *spec){

        double deviation = 0;
        double wTotal    = 0;
	double *items;
        FILE *OutFile;
	char Out[50];
        extern char directory[];
        extern int print;
        extern int pdbSwitch;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double fr1, bo;
	const double real_bl = 1.240;
	const double real_bo = 2.0; 

        //Current Positions
        if (MC_spinC2_snglt_linnett){
		fr1    = getDistance(spec->coord, 0, 1);
		bo     = getBondOrder(spec->coord, spec->numPart, real_bl);
        }
	
	deviation = fabs(real_bo-bo)/LENGTH;

	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spinC2_snglt_linnett){
			fprintf(OutFile,"| Kernel  dist          |      A     |   % 8.5f     |   -   |        -       |    %8.5f    |   N/A   |       -       |\n", real_bl, fr1);
			fprintf(OutFile,"| A1 1/radius^2         |    1/A^2   |      -         |   -   |        -       |%7.3f+%7.3fI|   N/A   |       -       |\n", creal(spec->coord[2].d), cimag(spec->coord[2].d));
			fprintf(OutFile,"| Lone A1  eta          |            |      -         |   -   |                |    %8.5f    |   N/A   |       -       |\n", spec->coord[2].eta);
			fprintf(OutFile,"| Lone A1  zeta         |            |      -         |   -   |                |    %8.5f    |   N/A   |       -       |\n", spec->coord[2].zeta);
			fprintf(OutFile,"| Bond Order            |      -     |   % 8.2f     |   -   |        -       |    %8.2f    |   N/A   |  % 8.2e    |\n", real_bo, bo,deviation*100);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	    	fclose(OutFile);
		printEnergy(U_spinC2_snglt_linnett);
	}

	//structure output
	sprintf(Out, "MC_spin%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spinC2_snglt_linnett)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	double scaledDev;
	scaledDev = 100*deviation;
	return scaledDev;

}
