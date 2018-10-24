#include "Structure.h"

extern double U_spinZnneutrl;					//declare structure energy                           

void specspinZnneutrl(Species * spec){				//define SPEC function for specific structure

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	strcpy(spec->fullname, "Znneutrl");			//Enter full name for the structure
	strcpy(spec->name, "Zn");				//Enter abbreviation name
	strcpy(spec->spin, "a6b6");				//Enter spin structure
	spec->type = Znneutrl;					//Enter type name
	spec->complete = 0;					//Not used temporarily
	spec->degFree = 11;					//Enter degree of freedom for the structure
	spec->numPart = 13;					//Enter number of particles for the structure
	spec->stepSize = 0.101;					//Enter the stepsize for optimization, default is 0.101
	spec->ainter = ainterspinZnneutrl;			//Enter the function name for "ainter" 
	spec->dev = devspinZnneutrl;				//Enter the function name for "dev"

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//Set memory space for spec
	Initialize(spec);

        //Initial Values expressed in Radians and Angstroms
        spec->ist[0] = 1.0;					//distance of electron to the center 
        spec->ist[1] = 1.0; 
        spec->ist[2] = 1.0; 
        spec->ist[3] = 1.0; 		
        spec->ist[4] = 0.600;					//diameter of electron
        spec->ist[5] = 0.600;
        spec->ist[6] = 0.600; 
        spec->ist[7] = 0.600; 
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


double ainterspinZnneutrl(Species * spec){
	
	int i, part;
	double Usum;
	part = spec->numPart;
        V Vin[part];

        double ra1	=	pow(10, spec->sym[0]);			//distance from O to electron alpha1's
        double ra2	=	pow(10, spec->sym[1]);			//distance from O to electron alpha2's
        double rb1	=	pow(10, spec->sym[2]);			//distance from O to electron beta1's
        double rb2	=	pow(10, spec->sym[3]);			//distance from O to electron beta2's
        
        double da1	=	pow(10, spec->sym[4]);			//diameter of electron alpha1's
        double da2	=	pow(10, spec->sym[5]);			//diameter of electron alpha2's
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
        Vin[0].q = 12;
        Vin[0].s = 30;

        //a-1 
        Vin[1].x = ra1*1.0;
        Vin[1].y = 0.0;
        Vin[1].z = 0.0;
        Vin[1].q = -1;
        Vin[1].s = 2;
        Vin[1].d = da1;

        //a-2 
        Vin[2].x = ra1*-1.0;
        Vin[2].y = 0.0;
        Vin[2].z = 0.0;
        Vin[2].q = -1;
        Vin[2].s = 2;
        Vin[2].d = da1;

	//a-3 
        Vin[3].x = 0.0;
        Vin[3].y = ra1*1.0;
        Vin[3].z = 0.0;
        Vin[3].q = -1;
        Vin[3].s = 2;
        Vin[3].d = da1;

	//a-4 
        Vin[4].x = 0.0;
        Vin[4].y = ra1*-1.0;
        Vin[4].z = 0.0;
        Vin[4].q = -1;
        Vin[4].s = 2;
        Vin[4].d = da1;

        //a-5 
        Vin[5].x = 0.0;
        Vin[5].y = 0.0;
        Vin[5].z = ra1*1.0;
        Vin[5].q = -1;
        Vin[5].s = 2;
        Vin[5].d = da1;

       //a-6 
        Vin[6].x = 0.0;
        Vin[6].y = 0.0;
        Vin[6].z = ra1*-1.0;
        Vin[6].q = -1;
        Vin[6].s = 2;
        Vin[6].d = da1;

        //b-1 
        Vin[7].x = rot(rb1*1.0, 0.0, 0.0, a, b, c, 0);
        Vin[7].y = rot(rb1*1.0, 0.0, 0.0, a, b, c, 1);
        Vin[7].z = rot(rb1*1.0, 0.0, 0.0, a, b, c, 2);
        Vin[7].q = -1;
        Vin[7].s = -2;
        Vin[7].d = db1;

	//b-2 
        Vin[8].x = rot(rb1*-1.0, 0.0, 0.0, a, b, c, 0);
        Vin[8].y = rot(rb1*-1.0, 0.0, 0.0, a, b, c, 1);
        Vin[8].z = rot(rb1*-1.0, 0.0, 0.0, a, b, c, 2);
        Vin[8].q = -1;
        Vin[8].s = -2;
        Vin[8].d = db1;

        //b-3 
        Vin[9].x = rot(0.0, rb1*1.0, 0.0, a, b, c, 0);
        Vin[9].y = rot(0.0, rb1*1.0, 0.0, a, b, c, 1);
        Vin[9].z = rot(0.0, rb1*1.0, 0.0, a, b, c, 2);
        Vin[9].q = -1;
        Vin[9].s = -2;
        Vin[9].d = db1;
        
        //b-4 
        Vin[10].x = rot(0.0, rb1*-1.0, 0.0, a, b, c, 0);
        Vin[10].y = rot(0.0, rb1*-1.0, 0.0, a, b, c, 1);
        Vin[10].z = rot(0.0, rb1*-1.0, 0.0, a, b, c, 2);
        Vin[10].q = -1;
        Vin[10].s = -2;
        Vin[10].d = db1;

        //b-5 
        Vin[11].x = rot(0.0, 0.0, rb1*1.0, a, b, c, 0);
        Vin[11].y = rot(0.0, 0.0, rb1*1.0, a, b, c, 1);
        Vin[11].z = rot(0.0, 0.0, rb1*1.0, a, b, c, 2);
        Vin[11].q = -1;
        Vin[11].s = -2;
        Vin[11].d = db1;

        //b-6 
        Vin[12].x = rot(0.0, 0.0, rb1*-1.0, a, b, c, 0);
        Vin[12].y = rot(0.0, 0.0, rb1*-1.0, a, b, c, 1);
        Vin[12].z = rot(0.0, 0.0, rb1*-1.0, a, b, c, 2);
        Vin[12].q = -1;
        Vin[12].s = -2;
        Vin[12].d = db1;

        //set d value
        setDvalue(Vin, part);

	//calculate structure energy
        if((MC_spinZnneutrl) && (spec->icue ==4)){
                Usum = metropolis(Vin, part,-2);//fix heavy
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = fJ*Usum*1E-15*kjmol;
	U_spinZnneutrl = Usum;

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


double devspinZnneutrl(Species *spec){

        double deviation = 0;
        double wTotal    = 0;
	double *items;
        FILE *OutFile;
	char Out[50];
        extern char directory[];
        extern int print;
        extern int pdbSwitch;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double fr1, fr2, fr3;

        //Current Positions
        if(MC_spinZnneutrl){
		fr1    = getDistance(spec->coord, 0, 1);
		fr2    = getDistance(spec->coord, 0, spec->numPart-1);
		//fr3	 = getDistance(spec->coord, 0, 7);
        }

	double dipole=0.0;
	dipole=getPolar(spec->coord,spec->numPart);
        deviation = 100*dipole*exp(10*dipole);

	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spinZnneutrl){
                         fprintf(OutFile,"| Lone A1 - Znneutrlex dist  |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", fr1);
                         fprintf(OutFile,"| Lone B1 - Znneutrlex dist  |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", fr2);
                         //fprintf(OutFile,"| Linear A - Znneutrlex dist |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", fr3);
                         fprintf(OutFile,"| Lone A1 radius             |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", spec->coord[1].d);
                         fprintf(OutFile,"| Lone B1 radius             |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", spec->coord[spec->numPart-1].d);
                         //fprintf(OutFile,"| Linear A radius            |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", spec->coord[7].d);
                         fprintf(OutFile,"| Polarity of neutrl         |      A     |      -         |   -   |                |    % 8.4f    |   N/A   |       -       |\n", dipole);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	    	fclose(OutFile);
		printEnergy(U_spinZnneutrl);
	}

	//structure output
	sprintf(Out, "MC_spin%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spinZnneutrl)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	return deviation;

}

	
