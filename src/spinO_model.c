#include "Structure.h"

extern double U_spinOneutrl;              //Declare structure energy                           

void specspinOneutrl(Species * spec){     //Define SPEC function for specific structure

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	strcpy(spec->fullname, "Oneutrl");                     //Enter full name for the structure
	strcpy(spec->name, "O");                               //Enter abbreviation name
	strcpy(spec->spin, "a4b2");				//Enter spin structure
	spec->type = Oneutrl;                                      //Enter type name
	spec->complete = 0;                                     //Not used temporarily
	spec->degFree = 5;                                      //Enter degree of freedom for the structure
	spec->numPart = 7;                                     //Enter number of particles for the structure
	spec->stepSize = 0.101;                                 //Enter the stepsize for optimization, default is 0.101
	spec->ainter = ainterspinOneutrl;                      //Enter the function name for "ainter" 
	spec->dev = devspinOneutrl;                            //Enter the function name for "dev"
	Initialize(spec);

        //Initial Values expressed in Radians and Angstroms
        spec->ist[0] = 0.35;  //electron-O-Zaxis Angle
        spec->ist[1] = 0.35; //O-electron distance
        spec->ist[2] = 0.525; //diameters of electrons, using previous Fneutrl's values.
        spec->ist[3] = 0.600;
        spec->ist[4] = 0.600;


        //translate initial values into log10 form for upnup, set Key
        int i;
        for(i = 1; i < spec->degFree; i++){
                spec->key[i] = 1;
                spec->sym[i] = log10(spec->ist[i]);
        }

        spec->sym[2] = log10((0.5 * pi / spec->ist[2]) - 1);

        if (fix_d){
                spec->key[3] = 0;
                spec->key[4] = 0;
                spec->sym[3] = log10(d_value);
                spec->sym[4] = log10(d_value);
        }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

}

double ainterspinOneutrl(Species * spec){
	
	int i, part;
	double Usum;
	part = spec->numPart;
        V Vin[part];


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

        //Initialization of Angles and Radii Variables

        double ra        = pow(10, a_spinOneutrl[0]);//distance from O to axial electrons
	double rv	 = pow(10, a_spinOneutrl[1]);//distance from O to vertical electrons
	double psi  	 = 0.5 * pi / (1 + pow(10, a_spinOneutrl[2]));
	double da	 = pow(10, a_spinOneutrl[3]);
	double db	 = pow(10, a_spinOneutrl[4]);

        double trig1 = sin(psi);  
        double trig2 = cos(psi);


        //Particle Positions
        //O
        Vin[0].x = 0.0;
        Vin[0].y = 0.0;
        Vin[0].z = 0.0;
        Vin[0].q = 6;
	Vin[0].s = 8;


	//B1 (lone electron)
        Vin[1].x = 0.0;
        Vin[1].y = rv;
        Vin[1].z = 0.0;
        Vin[1].q = -1;
        Vin[1].s = -2;
	Vin[1].d = db;
	
	//B2 (lone electron)
        Vin[2].x = 0.0;
        Vin[2].y = -rv;
        Vin[2].z = 0.0;
        Vin[2].q = -1;
	Vin[2].s = -2;
	Vin[2].d = db;

        //A1 (lone electron)
        Vin[3].x = 0.0;
        Vin[3].y = ra*trig1;
        Vin[3].z = ra*trig2;
        Vin[3].q = -1;
        Vin[3].s =  2;
        Vin[3].d = da;

	
	//A2 (lone electron)
        Vin[4].x = 0.0;
        Vin[4].y = ra*trig1;
        Vin[4].z = -ra*trig2;
        Vin[4].q = -1;
	Vin[4].s =  2;
	Vin[4].d = da;

	//A3 (lone electron)
        Vin[5].x = ra*trig2;
        Vin[5].y = -ra*trig1;
        Vin[5].z = 0.0;
        Vin[5].q = -1;
	Vin[5].s =  2;
	Vin[5].d = da;

	//A4 (lone electron)
        Vin[6].x = -ra*trig2;
        Vin[6].y = -ra*trig1;
        Vin[6].z = 0.0;
        Vin[6].q = -1;
        Vin[6].s =  2;
	Vin[6].d = da;

        //set d value
        setDvalue(Vin, part);

	//calculate structure energy
        if((MC_spinOneutrl) && (spec->icue ==4)){
                Usum = metropolis(Vin, part,-2);//fix heavy
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = fJ*Usum*1E-15*kjmol;
	U_spinOneutrl = Usum;
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


double devspinOneutrl(Species *spec){

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

	double fr1, fr2;

        //Current Positions
        if(MC_spinOneutrl){
          fr1    = getDistance(spec->coord, 0, 1);
	  fr2    = getDistance(spec->coord, 0, 3);
        //printf("gone in the if loop to calculate distace frh is %f\n",frH);
        }

        deviation = 0.0;

	// main output
	if (print){
		
		printHeader(spec->fullname, deviation);

		OutFile = fopen(directory, "a");

                if (MC_spinOneutrl){
                        //Unchanged from lowermainspinFneutrl.c, except for index changes for spec->coord[].
                         fprintf(OutFile,"| Lone B1 - O dist      |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", fr1);
                         fprintf(OutFile,"| Lone A1 - O dist      |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", fr2);
                         fprintf(OutFile,"| Lone B1 radius        |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", spec->coord[1].d);
                         fprintf(OutFile,"| Lone A1 radius        |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", spec->coord[3].d);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	    	fclose(OutFile);
		
		printEnergy(U_spinOneutrl);
	}

	//structure output

	sprintf(Out, "MC_spin%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spinOneutrl)){ output(spec->coord, spec->numPart, Out); }

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
		fprintf(EnergyOutFile, "\n%12s %12s %12f %12f %12f %12f %12f %12f %12f %12f %12f %12f %12f", spec->name,spec->spin,spec->coord[3].d,spec->coord[1].d,*items,*(items+1),*(items+2),*(items+3),*(items+4),*(items+5),*(items+3)+*(items+4)+*(items+5),*(items+6),*(items+7));
		fclose(EnergyOutFile);
	}

	return deviation;
}

	
