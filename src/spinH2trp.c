#include "Structure.h"

extern double U_spinH2trp;					//declare structure energy                           

void specspinH2trp(Species * spec){				//define SPEC function for specific structure

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	strcpy(spec->fullname, "H2trp");			//Enter full name for the structure
	strcpy(spec->name, "H2*");				//Enter abbreviation name
	strcpy(spec->spin, "a2b0");		//Enter spin structure
	spec->type = H2trp;				//Enter type name
	spec->complete = 0;					//Not used temporarily
	spec->kernel = 2;					//Not used temporarily
	spec->degFree = 16;					//Enter degree of freedom for the structure
	spec->numPart = 4;					//Enter number of particles for the structure
	spec->stepSize = 0.101;					//Enter the stepsize for optimization, default is 0.101
	spec->ainter = ainterspinH2trp;			//Enter the function name for "ainter" 
	spec->dev = devspinH2trp;			//Enter the function name for "dev"

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//Set memory space for spec
	Initialize(spec);

        //Initial Values expressed in Radians and Angstroms
        spec->ist[0] = 1.000000;					//distance of electron to the center 
        spec->ist[1] = 1.000000; 
        spec->ist[2] = 1.000000; 
        spec->ist[3] = 1.000000; 		
        spec->ist[4] = 3.000000;					//diameter of electron
        spec->ist[5] = 3.000000;
        spec->ist[6] = 3.000000; 
        spec->ist[7] = 3.000000; 
        spec->ist[8] = 3.000000;					//diameter of electron
        spec->ist[9] = 3.000000;
        spec->ist[10] = 3.000000; 
        spec->ist[11] = 3.000000; 
        spec->ist[12] = 0.001;					//rotation angle
        spec->ist[13] = 0.001; 
        spec->ist[14] = 0.001; 
        spec->ist[15] = 0.494500; 

        //translate initial values into log10 form for upnup, set Key
        int i;
        for(i = 0; i < spec->degFree; i++){
                spec->key[i] = 1;
                spec->sym[i] = log10(spec->ist[i]);
        }

        spec->sym[12] = log10((pi / spec->ist[0]) - 1);
        spec->sym[13] = log10((pi / spec->ist[0]) - 1);
        spec->sym[14] = log10((pi / spec->ist[0]) - 1);

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


double ainterspinH2trp(Species * spec){
	
	int i, part;
	double Usum;
	part = spec->numPart;
        V Vin[part];

        double ra1	=	pow(10, spec->sym[0]);			//distance from O to electron alpha1's
        double ra2	=	pow(10, spec->sym[1]);			//distance from O to electron alpha2's
        double rb1	=	pow(10, spec->sym[2]);			//distance from O to electron beta1's
        double rb2	=	pow(10, spec->sym[3]);			//distance from O to electron beta2's
        
        double da1_r	=	pow(10, spec->sym[4]);			//diameter of electron alpha1's
        double da2_r	=	pow(10, spec->sym[5]);			//diameter of electron alpha2's
        double db1_r	=	pow(10, spec->sym[6]);			//diameter of electron beta1's
        double db2_r	=	pow(10, spec->sym[7]);			//diameter of electron beta2's

        double da1_i	=	pow(10, spec->sym[8]);			//diameter of electron alpha1's
        double da2_i	=	pow(10, spec->sym[9]);			//diameter of electron alpha2's
        double db1_i	=	pow(10, spec->sym[10]);			//diameter of electron beta1's
        double db2_i	=	pow(10, spec->sym[11]);			//diameter of electron beta2's

	double a	=	pi / (1 + pow(10, spec->sym[12]));	//rotation angle a
	double b	=	pi / (1 + pow(10, spec->sym[13]));	//rotation angle b
	double c	=	pi / (1 + pow(10, spec->sym[14]));	//rotation angle c

	double r_kernel	=	pow(10, spec->sym[15]);			//distance of kernel to center	

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*##################################################
#                                                  #
#                                                  #
#                                                  #
# Replaced With Costomized Structure Coordinates!  #
#                                                  #
#                                                  #
#                                                  #
##################################################*/

        //Particle Positions

	//H1
        Vin[0].x = 0.0;
        Vin[0].y = 0.0;
        Vin[0].z = -r_kernel;
        Vin[0].q = 1;
	Vin[0].s = 1;

	//H2
        Vin[1].x = 0.0;
        Vin[1].y = 0.0;
        Vin[1].z = r_kernel;
        Vin[1].q = 1;
	Vin[1].s = 1;

	//A1
        Vin[2].x = 0.0;
        Vin[2].y = ra1;
        Vin[2].z = 0.0;
        Vin[2].q = -1;
	Vin[2].s = 2;
	Vin[2].d = da1_r+da1_i*I;

	//A2
        Vin[3].x = 0.0;
        Vin[3].y = -ra1; 
        Vin[3].z = 0.0;
        Vin[3].q = -1;
	Vin[3].s = 2;
	Vin[3].d = da1_r+da1_i*I;


	//calculate structure energy
        if((MC_spinH2trp) && (spec->icue ==4)){
		for(i=0;i<4;i++){
                	metropolis(Vin, part,-2);//fix heavy
		}
                Usum = metropolis(Vin, part,-2);//fix heavy
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = Usum*1E3;
	U_spinH2trp = Usum;

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//asign coordinate to structure
        for (i=0; i<part; i++){
        spec->coord[i].x = Vin[i].x;
        spec->coord[i].y = Vin[i].y;
        spec->coord[i].z = Vin[i].z;
        spec->coord[i].d = Vin[i].d;
        spec->coord[i].q = Vin[i].q;
        spec->coord[i].s = Vin[i].s;
        }

	//return structure energy
        return Usum;

}


double devspinH2trp(Species *spec){

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
	const double real_bl = 0.99;
	const double real_bo = 1.0; 

        //Current Positions
        if (MC_spinH2trp){
		fr1    = getDistance(spec->coord, 0, 1);
		//bo     = getBondOrder(spec->coord, spec->numPart, real_bl);
        }
	
	deviation = fabs(real_bl-fr1)/LENGTH;
	//deviation = fabs(real_bo-bo)/LENGTH;
	
	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spinH2trp){
			fprintf(OutFile,"| Kernel  dist          |      A     |    % 8.2f    |   -   |        -       |    %8.5f    |   N/A   |       -       |\n", real_bl, fr1);
			fprintf(OutFile,"| Ex.  A1 1/radius^2    |    1/A^2   |      -         |   -   |        -       |%7.3f+%7.3fI|   N/A   |       -       |\n", creal(spec->coord[2].d), cimag(spec->coord[2].d));
			//fprintf(OutFile,"| Bond Order            |      -     |   % 8.2f     |   -   |        -       |    %8.2f    |   N/A   |  % 8.2e    |\n", real_bo, bo,deviation*100);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	    	fclose(OutFile);
		printEnergy(U_spinH2trp);
	}

	//structure output
	sprintf(Out, "MC_spin%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spinH2trp)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	return deviation;

}
