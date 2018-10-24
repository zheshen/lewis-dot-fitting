#include "Structure.h"

extern double U_spinZnplus5;              //Declare structure energy                           

void specspinZnplus5(Species * spec){     //Define SPEC function for specific structure

        int i;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	strcpy(spec->fullname, "Znplus5");                     //Enter full name for the structure
	strcpy(spec->name, "Zn+5");                               //Enter abbreviation name
	strcpy(spec->spin, "a5b2");				//Enter spin structure
	spec->type = Znplus5;                                      //Enter type name
	spec->complete = 0;                                     //Not used temporarily
	spec->degFree = 5;                                      //Enter degree of freedom for the structure
	spec->numPart = 8;                                     //Enter number of particles for the structure
	spec->stepSize = 0.101;                                 //Enter the stepsize for optimization, default is 0.101
	spec->ainter = ainterspinZnplus5;                      //Enter the function name for "ainter" 
	spec->dev = devspinZnplus5;                            //Enter the function name for "dev"
	Initialize(spec);

	//Literature Values
	//No literature value specified

	//Initial Values expressed in Radians and Angstroms
        spec->ist[0] = 0.700; //O-A distance
        spec->ist[1] = 0.700; //O-B Distance
	spec->ist[2] = 0.300;
	spec->ist[3] = 0.600;
	spec->ist[4] = 0.600;


	//translate initial values into log10 form for upnup, set Key
	for(i = 0; i < spec->degFree; i++){
		spec->key[i] = 1;
		spec->sym[i] = log10(spec->ist[i]);
        }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

}

double ainterspinZnplus5(Species * spec){
	
	
	int i, part;
	double Usum;
	part = spec->numPart;
        V Vin[part];


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

        //Initialization of Angles and Radii Variables
        double psialpha = 0.5 * pi / (1 + pow(10, spec->sym[0])); //angle between lone electron alpha's and bond axis
        double psibeta  = 0.5 * pi / (1 + pow(10, spec->sym[1])); //angle between lone electron beta's and bond axis

        double ra         = pow(10, spec->sym[2]);//distance from O to lone electron alpha's
        double rb    	  = pow(10, spec->sym[3]);//distance from O to lone electron beta's
        double rbond      = pow(10, spec->sym[4]);//distance from origin to bonding electrons
        double da   	  = pow(10, spec->sym[5]);
        double db    	  = pow(10, spec->sym[6]);
        double dbond      = pow(10, spec->sym[7]);


        //Helping variables
        double theta    = 0.523598776;//theta is the degree between x axis origin and one of the base vertices of triangle (30degrees)
        double sin30    = sin(theta);
        double cos30    = cos(theta);
        double trig3 = sin(psialpha);
        double trig4 = cos(psialpha);
        double trig1 = sin(psibeta);
        double trig2 = cos(psibeta);


        //Particle Positions
        //O
        Vin[0].x = 0.0;
        Vin[0].y = 0.0;
        Vin[0].z = 0.0;
        Vin[0].q = 12;
        Vin[0].s = 30;


        //B1-1 (lone electron)
        Vin[1].x = rb*trig1;
        Vin[1].y = rb*sin30;
        Vin[1].z = rb*trig2;
        Vin[1].q = -1;
        Vin[1].s = -2;
        Vin[1].d = db;

        //B1-2 (lone electron)
        Vin[2].x = -rb*trig1;
        Vin[2].y = -rb*sin30;
        Vin[2].z = -rb*trig2;
        Vin[2].q = -1;
        Vin[2].s = -2;
	Vin[2].d = db;

        //A1-5 (lone electron)
        Vin[3].x = 0.0;
        Vin[3].y = 0.0;
        Vin[3].z = 0.0;
        Vin[3].q = -1;
        Vin[3].s = 2;
	Vin[3].d = da;

        //A1-1 (lone electron)
        Vin[4].x = -ra*trig3;
        Vin[4].y = 0.0;
        Vin[4].z = -ra*trig4;
        Vin[4].q = -1;
        Vin[4].s =  2;
	Vin[4].d = da;

        //A1-2 (lone electron)
        Vin[5].x = ra*sin30*trig3;
        Vin[5].y = -ra*cos30*trig3;
        Vin[5].z = -ra*trig4;
        Vin[5].q = -1;
        Vin[5].s =  2;
	Vin[5].d = da;

        //A1-3 (lone electron)
        Vin[6].x = ra*sin30*trig3;
        Vin[6].y = ra*cos30*trig3;
        Vin[6].z = -ra*trig4;
        Vin[6].q = -1;
        Vin[6].s =  2;
	Vin[6].d = da;

        //A4 (bonding electron) 
        Vin[7].x = 0.0;
        Vin[7].y = 0.0;
        Vin[7].z = rbond;
        Vin[7].q = -1;
        Vin[7].s =  2;
	Vin[7].d = dbond;

        //set d value
        setDvalue(Vin, part);

	//calculate structure energy
        if((MC_spinZnplus5) && (spec->icue ==4)){
                for(i=0;i<5;i++){
                        metropolis(Vin, part,-2);
                }
                Usum = metropolis(Vin, part,-2);//fix heavy
        }else
                Usum = sumEnergies(Vin, part);
	Usum = fJ*Usum*1E-15*kjmol;
	U_spinZnplus5 = Usum;

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


double devspinZnplus5(Species *spec){

        double deviation = 0;
        double wTotal    = 0;
	double *items;
        FILE *OutFile;
	FILE *EnergyOutFile;
	char Out[50];
        extern char directory[];
	extern char directorySplitEnergies[250];
        extern int print;
	extern int split;
        extern int writefinalpdb;
        extern int pdbSwitch;
	


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double fr1, fr3;

        //Current Positions
        if(MC_spinZnplus5){
          fr1    = getDistance(spec->coord, 0, 1);
	  fr3	 = getDistance(spec->coord, 0, 7);
        //printf("gone in the if loop to calculate distace frh is %f\n",frH);
        }

        deviation = 0.0;

	// main output
	if (print){
		
		printHeader(spec->fullname, deviation);

		OutFile = fopen(directory, "a");

                if (MC_spinZnplus5){
                        //Unchanged from lowermainspinFneutrl.c, except for index changes for spec->coord[].
                         fprintf(OutFile,"| Lone A1 - Znplus5ex dist      |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", fr1);
                         fprintf(OutFile,"| Lone B1 - Znplus5ex dist      |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", fr3);
                         fprintf(OutFile,"| Lone A1 radius        |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", spec->coord[1].d);
                         fprintf(OutFile,"| Lone B1 radius        |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", spec->coord[7].d);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	    	fclose(OutFile);
		
		printEnergy(U_spinZnplus5);
	}

	//structure output

	sprintf(Out, "MC_spin%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spinZnplus5)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//structure output

	sprintf(Out, "spin%s.pdb", spec->fullname);
        if (pdbSwitch){ output(spec->coord, spec->numPart, Out); }

	sprintf(Out, "spin%s_final.pdb", spec->fullname);	
	if ((writefinalpdb)&&(spec->icue==4)){ output(spec->coord, spec->numPart, Out); }

        //energy terms output

	if ((split)&&(print)){
		items = sumEnergies_split(spec->coord, spec->numPart);
		EnergyOutFile = fopen(directorySplitEnergies,"a");
		fprintf(EnergyOutFile, "\n%12s %12s %12f %12f %12f %12f %12f %12f %12f %12f %12f %12f %12f", spec->name,spec->spin,spec->coord[1].d,spec->coord[7].d,*items,*(items+1),*(items+2),*(items+3),*(items+4),*(items+5),*(items+3)+*(items+4)+*(items+5),*(items+6),*(items+7));
		fclose(EnergyOutFile);
	}

	return deviation;
}

	
