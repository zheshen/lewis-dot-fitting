#include "Structure.h"

extern double U_spinDielectronex;					//declare structure energy                           

void specspinDielectronex(Species * spec){				//define SPEC function for specific structure

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	strcpy(spec->fullname, "Dielectronex");			//Enter full name for the structure
	strcpy(spec->name, "e2ex");				//Enter abbreviation name
	strcpy(spec->spin, "ab");		//Enter spin structure
	spec->type = Dielectronex;				//Enter type name
	spec->complete = 0;					//Not used temporarily
	spec->kernel = 1;					//Not used temporarily
	spec->degFree = 11;					//Enter degree of freedom for the structure
	spec->numPart = 3;					//Enter number of particles for the structure
	spec->stepSize = 0.101;					//Enter the stepsize for optimization, default is 0.101
	spec->ainter = ainterspinDielectronex;			//Enter the function name for "ainter" 
	spec->dev = devspinDielectronex;			//Enter the function name for "dev"

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//Set memory space for spec
	Initialize(spec);

        //Initial Values expressed in Radians and Angstroms
        spec->ist[0] = 1.000000;					//distance of electron to the center 
        spec->ist[1] = 1.000000; 
        spec->ist[2] = 1.000000; 
        spec->ist[3] = 1.000000; 		
        spec->ist[4] = 0.600000;					//diameter of electron
        spec->ist[5] = 0.600000;
        spec->ist[6] = 0.600000; 
        spec->ist[7] = 0.600000; 
        spec->ist[8] = 0.001;					//rotation angle
        spec->ist[9] = 0.001; 
        spec->ist[10] = 0.001; 

        //translate initial values into log10 form for upnup, set Key
        int i;
        for(i = 0; i < spec->degFree; i++){
                spec->key[i] = 1;
                spec->sym[i] = log10(spec->ist[i]);
        }

        spec->sym[8] = log10((pi / spec->ist[0]) - 1);
        spec->sym[9] = log10((pi / spec->ist[0]) - 1);
        spec->sym[10] = log10((pi / spec->ist[0]) - 1);

        if (fix_d){
                spec->key[4] = 0;
                spec->key[5] = 0;
                spec->key[6] = 0;
                spec->key[7] = 0;
                spec->sym[4] = log10(d_value);
                spec->sym[5] = log10(d_value);
                spec->sym[6] = log10(d_value);
                spec->sym[7] = log10(d_value);
        }

}


double ainterspinDielectronex(Species * spec){
	
	int i, part;
	double Usum;
	part = spec->numPart;
        V Vin[part];

        double ra1	=	pow(10, spec->sym[0]);			//distance from O to electron alpha1's
        double ra2	=	pow(10, spec->sym[1]);			//distance from O to electron alpha2's
        double rb1	=	pow(10, spec->sym[2]);			//distance from O to electron beta1's
        double rb2	=	pow(10, spec->sym[3]);			//distance from O to electron beta2's
        
        double da1	=	pow(10, spec->sym[4]);			//diameter of electron alpha1's
        double da2	=	2*pi*pow(10, spec->sym[5]);			//diameter of electron alpha2's
        double db1	=	pow(10, spec->sym[6]);			//diameter of electron beta1's
        double db2	=	pow(10, spec->sym[7]);			//diameter of electron beta2's

	double a	=	pi / (1 + pow(10, spec->sym[8]));	//rotation angle a
	double b	=	pi / (1 + pow(10, spec->sym[9]));	//rotation angle b
	double c	=	pi / (1 + pow(10, spec->sym[10]));	//rotation angle c

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
        //Particle Positions
        //O
        Vin[0].x = 0.0;
        Vin[0].y = 0.0;
        Vin[0].z = 0.0;
        Vin[0].q = 4;
        Vin[0].s = 22;

       //a-1 
        Vin[1].x = 0.0;
        Vin[1].y = ra1;
        Vin[1].z = 0.0;
        Vin[1].q = -1;
        Vin[1].s = 2;
        Vin[1].d = da1+da2*I;

       //a-2 
        Vin[2].x = 0.0;
        Vin[2].y = -ra1;
        Vin[2].z = 0.0;
        Vin[2].q = -1;
        Vin[2].s = -2;
        Vin[2].d = da1+da2*I;


        //set d value
        setDvalue(Vin, part);

	//calculate structure energy
        if((MC_spinDielectronex) && (spec->icue ==4)){
        //        Usum = metropolis(Vin, part,-2);//fix heavy
                Usum = sumEnergies(Vin, part);
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = fJ*Usum*1E-15*kjmol;
	U_spinDielectronex = Usum;
//	printf("U_spinDielectronex=%f\n",U_spinDielectronex);
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


double devspinDielectronex(Species *spec){

        double deviation = 0;
        double wTotal    = 0;
	double *items;
        FILE *OutFile;
	char Out[50];
        extern char directory[];
        extern int print;
        extern int pdbSwitch;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double fr1, fr2, fr3, fd1, fd2, fd3;

        //Current Positions
        if (MC_spinDielectronex){
		fr1    = getDistance(spec->coord, 0, 1);
		fr2    = getDistance(spec->coord, 0, spec->numPart-1);
		//fr3	 = getDistance(spec->coord, 0, 7);
		fd1    = spec->coord[1].d;
		//fd3    = spec->coord[7].d;
        }

	double dipole=0.0;
	dipole=getPolar(spec->coord,spec->numPart);
        deviation = 50*dipole*exp(10*dipole);

	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spinDielectronex){
                         fprintf(OutFile,"| Lone A1  dist         |      A     |      -         |   -   |                |    % 8.5f    |   N/A   |       -       |\n", fr1);
                         fprintf(OutFile,"| Lone B1  dist         |      A     |      -         |   -   |                |    % 8.5f    |   N/A   |       -       |\n", fr2);
                         //fprintf(OutFile,"| Linear A  dist        |      A     |      -         |   -   |                |    % 8.5f    |   N/A   |       -       |\n", fr3);
//                         fprintf(OutFile,"| Lone A1 radius        |      A     |      -         |   -   |                |    % 8.5f    |   N/A   |       -       |\n", fd1);
//                         fprintf(OutFile,"| Lone B1 radius        |      A     |      -         |   -   |                |    % 8.5f    |   N/A   |       -       |\n", fd2);
                         //fprintf(OutFile,"| Linear A radius       |      A     |      -         |   -   |                |    % 8.5f    |   N/A   |       -       |\n", fd3);
                         fprintf(OutFile,"| Polarity              |      A     |      -         |   -   |                |    % 8.4f    |   N/A   |       -       |\n", dipole);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	    	fclose(OutFile);
	printf("U_spinDielectronex=%f\n",U_spinDielectronex);
		printEnergy(U_spinDielectronex);
	}

	//structure output
	sprintf(Out, "MC_spin%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spinDielectronex)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	return deviation;

}
