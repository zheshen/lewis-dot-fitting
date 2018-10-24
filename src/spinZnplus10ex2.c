#include "Structure.h"

extern double U_spinZnplus10ex;              //Declare structure energy                           

void specspinZnplus10ex(Species * spec){     //Define SPEC function for specific structure

        int i;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	strcpy(spec->fullname, "Znplus10ex");                     //Enter full name for the structure
	strcpy(spec->name, "Zn+10*");                               //Enter abbreviation name
	strcpy(spec->spin, "ab");				//Enter spin structure
	spec->type = Znplus10ex;                                      //Enter type name
	spec->complete = 0;                                     //Not used temporarily
	spec->degFree = 4;                                      //Enter degree of freedom for the structure
	spec->numPart = 3;                                     //Enter number of particles for the structure
	spec->stepSize = 0.101;                                 //Enter the stepsize for optimization, default is 0.101
	spec->ainter = ainterspinZnplus10ex;                      //Enter the function name for "ainter" 
	spec->dev = devspinZnplus10ex;                            //Enter the function name for "dev"
	Initialize(spec);

        //Initial Values expressed in Radians and Angstroms
        spec->ist[0] = 0.00001;    //BP-H Distance (rH)
	spec->ist[1] = 0.00001;
	spec->ist[2] = 0.950;
	spec->ist[3] = 5.200;


        //translate initial values into log10 form for upnup, set Key
        for(i = 0; i < spec->degFree; i++){
                spec->key[i] = 1;
                spec->sym[i] = log10(spec->ist[i]);
        }

        if (fix_d){
                spec->key[2] = 0;
                spec->sym[2] = log10(d_value);
        }


/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

}

double ainterspinZnplus10ex(Species * spec){
	
	
	int i, part;
	double Usum;
	part = spec->numPart;
        V Vin[part];


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double ra = pow(10, spec->sym[0]);
	double rb = pow(10, spec->sym[1]);
	double ad = pow(10, spec->sym[2]);
	double bd = pow(10, spec->sym[3]);

        //Particle Positions

	//A
        Vin[0].x = 0.0;
        Vin[0].y = 0.0;
        Vin[0].z = ra;
        Vin[0].q = -1;
	Vin[0].s = 2;
	Vin[0].d = ad;

	//Be
        Vin[1].x = 0.0;
        Vin[1].y = 0.0;
        Vin[1].z = 0.0;
        Vin[1].q = 12;
	Vin[1].s = 30;
	//B
        Vin[2].x = 0.0;
        Vin[2].y = 0.0;
        Vin[2].z = -rb;
        Vin[2].q = -1;
        Vin[2].s = -2;
	Vin[2].d = bd;

        //set d value
        setDvalue(Vin, part);

        Usum = sumEnergies(Vin, part);
	Usum = fJ*Usum*1E-15*kjmol;
	U_spinZnplus10ex = Usum;

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


double devspinZnplus10ex(Species *spec){

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

        double ra, rb, dist1, dist2,ad,bd;

        //Current Positions
	ra = pow(10, spec->sym[0]);
	rb = pow(10, spec->sym[1]);
	ad = pow(10, spec->sym[2]);
	bd = pow(10, spec->sym[3]);

        //mean absolute deviation
        wTotal    += 1.0;

        deviation /= wTotal;
	
	if (print){

                dist1 = spec->ist[0];      //BP-H initial dist
                dist2 = ra;             //BP-H final dist

                printHeader(spec->fullname, deviation);

                OutFile = fopen(directory, "a");

                fprintf(OutFile, "| H-A Distance          |      A     |      -         |   -   |    % 8.2f    |    % 8.2f    |", dist1, dist2);
                fprintf(OutFile,"    N    |       -       |\n");
		
		fprintf(OutFile, "| H-B Distance          |      A     |      -         |   -   |    % 8.2f    |    % 8.2f    |", spec->ist[1], rb);
                fprintf(OutFile,"    N    |       -       |\n");
                fprintf(OutFile, "| A Radius              |      A     |      -         |   -   |    % 8.2f    |    % 8.2f    |", spec->ist[2], ad);
                fprintf(OutFile,"    N    |       -       |\n");


		fprintf(OutFile, "| B Radius              |      A     |      -         |   -   |    % 8.2f    |    % 8.2f    |", spec->ist[3], bd);
                fprintf(OutFile,"    N    |       -       |\n");

                fclose(OutFile);

                printEnergy(U_spinZnplus10ex);
        }

	//structure output

	sprintf(Out, "MC_spin%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spinZnplus10ex)){ output(spec->coord, spec->numPart, Out); }

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
		fprintf(EnergyOutFile, "\n%12s %12s %12f %12f %12f %12f %12f %12f %12f %12f %12f %12f %12f", spec->name,spec->spin,spec->coord[0].d,spec->coord[2].d,*items,*(items+1),*(items+2),*(items+3),*(items+4),*(items+5),*(items+3)+*(items+4)+*(items+5),*(items+6),*(items+7));
		fclose(EnergyOutFile);
	}

	return deviation;
}

	
