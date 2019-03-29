
//#include "Common.h"
//#include "Metropolis.h"
#include "Lowermain.h"
#include <omp.h>

double ainterspinN2_snglt_linnett(Species *spec);
double ainterspinN2_snglt_snglbnd(Species *spec);
double ainterspinN2_snglt_dblbnd(Species *spec);
double ainterspinN2_snglt_trplbnd(Species *spec);

double lowermainspinN2_snglt(){

	extern char directory[];
	extern int print;

        extern double U_spinN2_snglt;
	extern double U_spinN2_snglt_linnett;
	extern double U_spinN2_snglt_snglbnd;
	extern double U_spinN2_snglt_dblbnd;
	extern double U_spinN2_snglt_trplbnd;


	char molecule[] = "NITROGEN  DIATOMIC SNG MIN";
        const double real_bl= 1.10;
        const double real_bo= 3;


	double deviation = 0;
	//double wTotal    = 0;
	int success = 0;

	int i;
	double fr1;
	double bo;
	double spinsym;

	FILE *OutFile;

	Species spec;
	spec.icue = 4;
	strcpy(spec.fullname, "N2_snglt");			//Enter full name for the structure
	strcpy(spec.name, "N2_snglt");				//Enter abbreviation name
	strcpy(spec.spin, "a5b5");				//Enter spin structure
	spec.type = N2_snglt;					//Enter type name
	spec.kernel = 2;					//Not used temporarily
	spec.degFree = 11;					//Enter degree of freedom for the structure
	spec.numPart = 12;					//Enter number of particles for the structure
	spec.stepSize = 0.101;					//Enter the stepsize for optimization, default is 0.101


	Initialize(&spec);


	Species linnett;
	Species snglbnd;
	Species dblbnd;
	Species trplbnd;
	linnett.type = N2_snglt_linnett;
	snglbnd.type = N2_snglt_snglbnd;
	dblbnd.type = N2_snglt_dblbnd;
	trplbnd.type = N2_snglt_trplbnd;
	specSwitch(&linnett);
	specSwitch(&snglbnd);
	specSwitch(&dblbnd);
	specSwitch(&trplbnd);
	linnett.icue = 4;
	snglbnd.icue = 4;
	dblbnd.icue = 4;
	trplbnd.icue = 4;
	

	//Literature Values
	//No literature value specified

	//Initial Values expressed in Radians and Angstroms


	//translate initial values into log10 form for upnup, set Key


	for (i = 0; i < 9000; i++){
//
//#pragma omp parallel
//		{
//#pragma omp sections 
//		{
//#pragma omp section 
//                        {
//				(*linnett.ainter)(&linnett);
//			}
//#pragma omp section 
//			{
//				(*snglbnd.ainter)(&snglbnd);
//			}
//#pragma omp section 
//			{
//				(*dblbnd.ainter)(&dblbnd);
//			}
//#pragma omp section 
//			{
//				(*trplbnd.ainter)(&trplbnd);
//			}
//		}
//		}
//

		if (spec.icue == 4){ //enter here if optimization complete

#pragma omp parallel
			{
#pragma omp sections 
			{
#pragma omp section 
                        	{	
//					if (wspinN2_snglt_linnett)
					(*linnett.ainter)(&linnett);
//					else U_spinN2_snglt_linnett = 0.0;
				}
#pragma omp section 
				{
//					if (wspinN2_snglt_snglbnd)
					(*snglbnd.ainter)(&snglbnd);
//					else U_spinN2_snglt_snglbnd = 0.0;
				}
#pragma omp section 
				{
//					if (wspinN2_snglt_dblbnd)
					(*dblbnd.ainter)(&dblbnd);
//					else U_spinN2_snglt_dblbnd = 0.0;
				}
#pragma omp section 
				{
//					if (wspinN2_snglt_trplbnd)
      					(*trplbnd.ainter)(&trplbnd);
//					else U_spinN2_snglt_trplbnd = 0.0;
				}
			}
			}


//					U_spinN2_snglt_linnett = (*linnett.ainter)(&linnett);
//					U_spinN2_snglt_snglbnd = (*snglbnd.ainter)(&snglbnd);
//					U_spinN2_snglt_dblbnd = (*dblbnd.ainter)(&dblbnd);
//					U_spinN2_snglt_trplbnd = (*trplbnd.ainter)(&trplbnd);
//					printf("%f, %f, %f, %f\n", U_spinN2_snglt_linnett, U_spinN2_snglt_snglbnd, U_spinN2_snglt_dblbnd, U_spinN2_snglt_trplbnd);

			U_spinN2_snglt=fmin(fmin(fmin(U_spinN2_snglt_linnett,U_spinN2_snglt_snglbnd),U_spinN2_snglt_dblbnd),U_spinN2_snglt_trplbnd); //spinN2_snglt (triplet)
			if (U_spinN2_snglt==U_spinN2_snglt_linnett)
			{
				for (i=0; i<linnett.numPart;i++){
					spec.coord[i].x = linnett.coord[i].x;
					spec.coord[i].y = linnett.coord[i].y;
					spec.coord[i].z = linnett.coord[i].z;
					spec.coord[i].d = linnett.coord[i].d;
					spec.coord[i].eta = linnett.coord[i].eta;
					spec.coord[i].zeta = linnett.coord[i].zeta;
					spec.coord[i].q = linnett.coord[i].q;
					spec.coord[i].s = linnett.coord[i].s;
				}                         
			}                                 
			else if(U_spinN2_snglt==U_spinN2_snglt_snglbnd)
			{
				for (i=0; i<snglbnd.numPart;i++){
					spec.coord[i].x = snglbnd.coord[i].x;
					spec.coord[i].y = snglbnd.coord[i].y;
					spec.coord[i].z = snglbnd.coord[i].z;
					spec.coord[i].d = snglbnd.coord[i].d;
					spec.coord[i].eta = snglbnd.coord[i].eta;
					spec.coord[i].zeta = snglbnd.coord[i].zeta;
					spec.coord[i].q = snglbnd.coord[i].q;
					spec.coord[i].s = snglbnd.coord[i].s;
				}
			}
			else if(U_spinN2_snglt==U_spinN2_snglt_dblbnd)
			{
				for (i=0; i<dblbnd.numPart;i++){
					spec.coord[i].x = dblbnd.coord[i].x;
					spec.coord[i].y = dblbnd.coord[i].y;
					spec.coord[i].z = dblbnd.coord[i].z;
					spec.coord[i].d = dblbnd.coord[i].d;
					spec.coord[i].eta = dblbnd.coord[i].eta;
					spec.coord[i].zeta = dblbnd.coord[i].zeta;
					spec.coord[i].q = dblbnd.coord[i].q;
					spec.coord[i].s = dblbnd.coord[i].s;
				}
			}
			else if(U_spinN2_snglt==U_spinN2_snglt_trplbnd)
			{

				for (i=0; i<trplbnd.numPart;i++){
					spec.coord[i].x = trplbnd.coord[i].x;
					spec.coord[i].y = trplbnd.coord[i].y;
					spec.coord[i].z = trplbnd.coord[i].z;
					spec.coord[i].d = trplbnd.coord[i].d;
					spec.coord[i].eta = trplbnd.coord[i].eta;
					spec.coord[i].zeta = trplbnd.coord[i].zeta;
					spec.coord[i].q = trplbnd.coord[i].q;
					spec.coord[i].s = trplbnd.coord[i].s;
				}
			}
			else
				U_spinN2_snglt=0.0;





			if(MC_spinN2_snglt){
				fr1    = getDistance(spec.coord, 0, 1);
				bo = getBondOrder(spec.coord,spec.numPart,real_bl);
				spinsym = getSpinSym(spec.coord, spec.numPart, real_bl);

			}

			double deviation_bo, deviation_po, deviation_sym;
			deviation = 0.0;
			deviation_bo = 100*fabs(real_bo-bo)/real_bo;
			deviation += 100*fabs(real_bo-bo)/real_bo;
			double dipole=0.0;
			dipole=getPolar(spec.coord,spec.numPart);
        		deviation_po = 100*dipole*exp(10*dipole);
//        		deviation += 100*dipole*exp(10*dipole);
        		deviation_sym= 100*spinsym*exp(10*spinsym);
//        		deviation += 100*spinsym*exp(10*spinsym);

//			if(spinsym * FIT_SpinSym > 0.1)
//				deviation = 5E5;


			if (print){


				printHeader(molecule, deviation);

				OutFile = fopen(directory, "a");

				if (MC_spinN2_snglt){

					fprintf(OutFile,"| O  - O  dist          |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |   N/A   |       -       |\n", fr1);
					fprintf(OutFile,"| Ex.  A1 radius        |      A     |      -         |   -   |   D_Init (MC)  |%7.3f+%7.3fI|   N/A   |       -       |\n", creal(spec.coord[2].d), cimag(spec.coord[2].d));
					fprintf(OutFile,"| Bond Order            |      -     |   % 8.2f     |   -   |   D_Init (MC)  |    % 8.2f    |    N    |  % 8.2e    |\n", real_bo, bo, deviation_bo);
                        		fprintf(OutFile,"| Polarity              |      A     |      -         |   -   |                |    %8.4f    |    N    |       -       |\n", dipole);
					fprintf(OutFile,"| Spin Symmetry         |      A     |      -         |   -   |   D_Init (MC)  |    % 8.5f    |    N    |       -       |\n", spinsym);


				}

				fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");

			        fprintf(OutFile, "| Potential Energy      |   kJ/mol   |      -         |   -   |   Linnett      |  % 7.5e  |", U_spinN2_snglt_linnett );
			        fprintf(OutFile, "   N/A   |       -       |\n");
			
			        fprintf(OutFile, "| Potential Energy      |   kJ/mol   |      -         |   -   |   Snglbnd      |  % 7.5e  |", U_spinN2_snglt_snglbnd );
			        fprintf(OutFile, "   N/A   |       -       |\n");
			
			        fprintf(OutFile, "| Potential Energy      |   kJ/mol   |      -         |   -   |   Dblbnd       |  % 7.5e  |", U_spinN2_snglt_dblbnd );
			        fprintf(OutFile, "   N/A   |       -       |\n");
			
			        fprintf(OutFile, "| Potential Energy      |   kJ/mol   |      -         |   -   |   Trplbnd      |  % 7.5e  |", U_spinN2_snglt_trplbnd );
			        fprintf(OutFile, "   N/A   |       -       |\n");


                                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");

				fclose(OutFile);

				printEnergy(U_spinN2_snglt);

                        extern int writefinalpdb;
                        if ((writefinalpdb)&&(spec.icue==4)){output(spec.coord, spec.numPart, "spinN2_snglt_min_final.pdb");}

			}	
			success = 1;
			break;
		}	
	}

	if(!success){
		printNoMinima(molecule);
		deviation = 5E5;
	}
	Delete(spec);
	Delete(linnett);
	Delete(snglbnd);
	Delete(dblbnd);
	Delete(trplbnd);
	return deviation;
}              
