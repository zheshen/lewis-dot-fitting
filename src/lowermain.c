//lowermain.c
//by Zhe Shen on June, 28 2017.
//Integrated all lowermain***.c into to one lowermain.c


#include "Lowermain.h"

double lowermain(MoName type){

        extern char directory[];
	extern char directorySplitEnergies[250];
        extern int print;
	extern int split;
	extern int writeupnuppdb;
        extern int writefinalpdb;
        extern int pdbSwitch;
	char Out[50];
	FILE *EnergyOutFile;
	double *items;
//        extern int icue_spin;//1;
//	icue_spin = 1;
	double deviation;
        int success = 0;
        int i;
	
	//Structure initialization for specific training set.
	Species spec;
	spec.type = type;
	spec.icue = 1;
	specSwitch(&spec);

	//Optimization loop
        for (i = 0; i < 9000; i++){
		if (spec.kernel == 1){upnupspin(&spec);}
		else if (spec.kernel == 2){spec.icue = 4;}
		else if (spec.kernel == 3){spec.icue = 4;}
		//icue_spin = 4;
		if (spec.icue == 4){ //enter here if optimization complete
			
			//structure output after upnup			

			sprintf(Out, "spin%s_upnup.pdb", spec.fullname);
			if (writeupnuppdb){ output(spec.coord, spec.numPart, Out); }

			split = 1;

			(*spec.ainter)(&spec);

			deviation = (*spec.dev)(&spec); //Calculate structure deviation and print structure information

			//final structure output 

			sprintf(Out, "spin%s.pdb", spec.fullname);
      			if (pdbSwitch){ output(spec.coord, spec.numPart, Out); }

			sprintf(Out, "spin%s_final.pdb", spec.fullname);	
			if ((writefinalpdb)&&(spec.icue==4)){ output(spec.coord, spec.numPart, Out); }

        		//energy terms output

			if ((split)&&(print)){
				//extern int diagnose_print;
				//diagnose_print = 1;
				static double items[10];
				for (i = 0; i<10; i++){
					items[i] = 0.0;
				}
				
				sumEnergies_split(spec.coord, spec.numPart, items);
				EnergyOutFile = fopen(directorySplitEnergies,"a");
				if (spec.kernel == 1)
				fprintf(EnergyOutFile, "\n%12s %12s %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f", spec.name,spec.spin,creal(spec.coord[1].d),spec.coord[1].eta,spec.coord[1].zeta,creal(spec.coord[spec.numPart-1].d),spec.coord[spec.numPart-1].eta,spec.coord[spec.numPart-1].zeta,*items,*(items+1),*(items+2),*(items+3),*(items+4),*(items+5),*(items+3)+*(items+4)+*(items+5),*(items+6),*(items+7),*(items+6)+*(items+7),*(items+8));
				else if (spec.kernel == 2)
				fprintf(EnergyOutFile, "\n%12s %12s %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f", spec.name,spec.spin,creal(spec.coord[2].d),spec.coord[2].eta,spec.coord[2].zeta,creal(spec.coord[spec.numPart-1].d),spec.coord[spec.numPart-1].eta,spec.coord[spec.numPart-1].zeta,*items,*(items+1),*(items+2),*(items+3),*(items+4),*(items+5),*(items+3)+*(items+4)+*(items+5),*(items+6),*(items+7),*(items+6)+*(items+7),*(items+8));
				else if (spec.kernel == 3)
				fprintf(EnergyOutFile, "\n%12s %12s %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f", spec.name,spec.spin,creal(spec.coord[3].d),spec.coord[3].eta,spec.coord[3].zeta,creal(spec.coord[spec.numPart-1].d),spec.coord[spec.numPart-1].eta,spec.coord[spec.numPart-1].zeta,*items,*(items+1),*(items+2),*(items+3),*(items+4),*(items+5),*(items+3)+*(items+4)+*(items+5),*(items+6),*(items+7),*(items+6)+*(items+7),*(items+8));
				
				fclose(EnergyOutFile);
				//diagnose_print = 0;
			}

			split = 0;
			success = 1;
                        break;
                }
        
	}

        if(!success){
                printNoMinima(spec.fullname);
                deviation = 5E5;
        }
	Delete(spec);
        return deviation;
}

