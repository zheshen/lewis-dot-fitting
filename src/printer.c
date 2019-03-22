
 /**************************************************************
 * Purpose:                                                    *
 * This program includes some print functions, such as the     *
 * templates of headline and endline for output of each        *
 * training structure.  			  	       *
 **************************************************************/
 
#include "Energy.h"
#include "Print.h"

extern char directory[], directoryWarnings[], directoryPlots[], directoryFunctionPlots[], directorySplitEnergies[];

void printHeader(char *molecule, double deviation){
 
	extern char version[];
	extern double totaldev; 

        //Time
	struct tm * timeinfo;
        time_t rawtime;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
 
	FILE *OutFile;
        OutFile = fopen(directory, "a");

	fprintf(OutFile, "|=========================================================================================================================|\n");
	fprintf(OutFile, "|                                            %24s                                                     |\n", molecule);
	fprintf(OutFile, "|                                                        %s                                                       |\n", version);
	fprintf(OutFile, "|                                               %s", asctime (timeinfo));
	fprintf(OutFile, "|Molecule Deviation....................................................................................% 8.4e percent|\n", deviation*100);
	fprintf(OutFile, "|Suite Total Deviation ................................................................................% 8.4e percent|\n", totaldev);
	fprintf(OutFile, "|=========================================================================================================================|\n");
	fprintf(OutFile, "|      STRUCTURAL PARAMETERS         |    LITERATURE DATA     |                    CALCULATED DATA                        |\n");
	fprintf(OutFile, "|====================================|========================|===========================================================|\n");
	fprintf(OutFile, "|  Feature              |    Units   |      Value     |Uncert.|     Initial    |      Final     |   Fxd?  |     %c Dev     |\n", 37);
	fprintf(OutFile, "|=======================|============|================|=======|================|================|=========|===============|\n");

	fclose(OutFile);
}

void printTransitionHeader(char *molecule, double deviation){
 
	extern char version[];
	extern double totaldev; 

        //Time
	struct tm * timeinfo;
        time_t rawtime;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
 
	FILE *OutFile;
        OutFile = fopen(directory, "a");

	fprintf(OutFile, "|=========================================================================================================================|\n");
	fprintf(OutFile, "|                                                %s                                                 |\n", molecule);
        fprintf(OutFile, "|                                                       %s                                                        |\n", version);
	fprintf(OutFile, "|                                              %s", asctime (timeinfo));
	fprintf(OutFile, "|Transition state total deviation......................................................................% 8.4e percent|\n", deviation*100);
	fprintf(OutFile, "|Suite Total Deviation ................................................................................% 8.4e percent|\n", totaldev);
	fprintf(OutFile, "|=========================================================================================================================|\n");
//	fprintf(OutFile, "|      STRUCTURAL PARAMETER          |      TRANSITION  COORDINATE       |   REF. DATA |  CALC. DATA, WEIGHT & DEVIATION  |\n");
//	fprintf(OutFile, "|   TRANS. COORD.     |      STRUCTURAL PARAMETERS               |    REFERENCE DATA   |  CALC. DATA, WEIGHT & DEVIATION  |\n");
//	fprintf(OutFile, "|      TRANSITION  COORDINATE       |      STRUCTURAL PARAMETER          |   REF. DATA |  CALC. DATA, WEIGHT & DEVIATION  |\n");
//	fprintf(OutFile, "|=====================|==========================================|=====================|==================================|\n");
//	fprintf(OutFile, "|===================================|====================================|=============|==================================|\n");
//	fprintf(OutFile, "|  Feature              |    Units   |  Feature   |    Value   |  Units  |    Value    |    Value    | w_rel |    %c Dev   |\n", 37);
//	fprintf(OutFile, "|Feature| Value |Units|  Feature                                 |  Units |    Value   |    Value    | w_rel |    %c Dev   |\n",37);
//	fprintf(OutFile, "|  Feature   |    Value   |  Units  |  Feature              |    Units   |    Value    |    Value    | w_rel |    %c Dev   |\n", 37);
//	fprintf(OutFile, "|=====================|==========================================|=====================|=============|=======|============|\n");
//	fprintf(OutFile, "|=========================|=========|=======================|============|=============|=============|=======|============|\n");
	fclose(OutFile);
}

void printPlots(double *x, double *y, int c){

	FILE *OutFile;
        OutFile = fopen(directoryPlots, "a");
	
	int i;

	for (i = 0; i < c; i++)
		fprintf(OutFile, "%f %f \n", x[i], y[i]);

	fclose(OutFile);
}

void printAllEnergyPlots(){
        //Add and comment out as necessary..
	// input goes as q1, q2, s1, s2

	printEnergyPlot(-1, -1, 2, -2);//AB
 	printEnergyPlot(-1, -1, 2, 2);//AA
	//printTBenergyPlot(1, 1, 0);//AAH three body term reff=0 rNeff range
	printTBenergyPlot(6, 8, 1);//AAH three body term reff range rNeff=0
	//printEnergyPlot(-2, -2, 0, 0); //VV
        printEnergyPlot( -1, 12, 2, 40); //AH
//        printEnergyPlot( -1, 3, 2, 13); //AAl
//        printEnergyPlot( -1, 7, 2, 17); //ACl


        //printEnergyPlot( 6, -2, 6, 0); //OV
//	printEnergyPlot( 6, -1, 8, 2);//OA
 //       printEnergyPlot( 6,  6, 8, 8); //OO
        //printEnergyPlot( 6,  1, 8, 1); //OH
        printEnergyPlot( 1,  1, 1, 1); //HH
//	printEnergyPlot( 7, -1, 9, 2);//FA
}

void printEnergyPlot(double q1, double q2, int s1, int s2){

	//printf("q1 is %f q2 is %f s1 is %d s2 is %d\n",q1,q2,s1,s2);
        const double dr  = 0.01;
        const double i_0 = 0.0;
        const int i_f   = 1001;
        int i;
	extern int diagnose_print;

       // double q = q1 * q2;
        double r2, r;
	double dr1, dr2, di1, di2;
	V a, b;
	
        FILE *OutFile;
        OutFile = fopen(directoryFunctionPlots, "a");
        fprintf(OutFile, "\n");

        /*for (i = i_0; i < i_f; i++){                r       = dr * i;
                r2      = r * r;
                fprintf(OutFile, "%f %f \n", r, simpleCoulomb(r2, r, q, ENERGY));
        }
        
        fprintf(OutFile, "\n");*/
//	diagnose_print = 1;

	if ((q1 == q2) && (q1 == -1)){
		a.d = 1.0;//sqrt(0.5);
		b.d = 1.0;//sqrt(0.5);
	}
	else if ((q1 == -1) || (q2 == -1)){
		a.d = 1.0;
		b.d = 0;
	}
	else {
		a.d = 0;
		b.d = 0;
	}
	a.x = 0.0;
	a.y = 0.0;
	a.z = 0.0;
	b.x = 0.0;
	b.y = 0.0;
	b.z = 0.0;
	a.q = q1;
	b.q = q2;
	a.s = s1;
	b.s = s2;
	r = i_0-dr;
        for (i = 0; i < i_f; i++){
                r      += dr;
                r2      = r * r;
		b.z     = r;
                fprintf(OutFile, "%f %f \n", r, energy(&a, &b, 1.0, ENERGY));
        }
        fprintf(OutFile, "\n");
        fclose(OutFile);
}

void printTBenergyPlot(double q, int s, int distType){
        const double dr  = 0.01;
        const double i_0 = 0.0;
        const int i_f   = 1001;
        int i;
	extern int diagnose_print;
	diagnose_print = 0;

        double r2, r;
        double dr1, dr2, di1, di2;
	V a, b, X;

        FILE *OutFile;
        OutFile = fopen(directoryFunctionPlots, "a");
        fprintf(OutFile, "\n");

	a.d = 1;
	b.d = 1;
	a.x = 0.3;
	a.y = 0.0;
	a.z = 0.0;
	b.x = -0.3;
	b.y = 0.0;
	b.z = 0.0;
	X.x = 0.0;
	X.y = 0.1;
	X.z = 0.0;
	a.q = -1;
	b.q = -1;
	a.s = -2;
	b.s = -2;
	X.q = q;
	X.s = s;
        r = i_0-dr;
        for (i = 0; i < i_f; i++){
                r      += dr;
                r2      = r * r;
		a.x     = -r;
		b.x     =r;
		//TBenergy(r2 between electrons & then its r, r2 midpoint to X & then its r, r2 e1 to X, r2 e2 to X, d1, d2, q, s, E_or_F)
//		if(distType)
                fprintf(OutFile, "%f %f \n", r, TBenergy(&a, &b, &X, r2, 0.0, ENERGY));
//		else
//		fprintf(OutFile, "%f %f \n", r, 0.0);
                //fprintf(OutFile, "%f %f \n", r, TBenergy(0, 0, r2, r, 0, 0, d1,d2, q, s, ENERGY));

//	diagnose_print = 0;
        }

        fprintf(OutFile, "\n");
        fclose(OutFile);

}

void printEnergy(double energy){

	FILE *OutFile;
        OutFile = fopen(directory, "a");

	double potenfJ       = energy / (1E-15*kjmol); 
	double potenkJ_mol   = energy;
	double potenkcal_mol = energy * kcalmol;

	fprintf(OutFile, "| Potential Energy      |     fJ     |      -         |   -   |  % 7.5e  |  % 7.5e  |", potenfJ, potenfJ );
	fprintf(OutFile, "   N/A   |       -       |\n");

	fprintf(OutFile, "| Potential Energy      |   kJ/mol   |      -         |   -   |  % 7.5e  |  % 7.5e  |", potenkJ_mol, potenkJ_mol );
	fprintf(OutFile, "   N/A   |       -       |\n");

	fprintf(OutFile, "| Potential Energy      |  kcal/mol  |      -         |   -   |  % 7.5e  |  % 7.5e  |", potenkcal_mol, potenkcal_mol );
	fprintf(OutFile, "   N/A   |       -       |\n");

	fclose(OutFile);
}

void printNoMinima(char *molecule){

	FILE *OutFile;
        OutFile = fopen(directoryWarnings, "a");

	fprintf(OutFile, "|=========================================================================================================================|\n");
	fprintf(OutFile, "WARNING: NO MINIMA COULD BE FOUND FOR MOLECULE: %s \n", molecule);
	fprintf(OutFile, "|=========================================================================================================================|\n");
	fclose(OutFile);
}

void printEndLine(){

	FILE *OutFile;
        OutFile = fopen(directory, "a");
	
	fprintf(OutFile, "|END OF FILE =============================================================================================================|\n");

        fclose(OutFile);

}

void printEnergyTermsHead(){
        FILE *EnergyOutFile;
        EnergyOutFile = fopen(directorySplitEnergies,"a");
        fprintf(EnergyOutFile, "\n%12s %12s %8s %8s %8s %8s %8s %8s %8s %8s %8s %8s %8s %8s %8s %8s %8s %8s %8s", "Item","Spin","a_R","a_eta","a_zeta","b_R","b_eta","b_zeta","KE","U_AB","U_AA(AB)","UexK","UexR","UexX","Uex","U_AX_c","U_AX_ex","U_AX","U_XY");
        fclose(EnergyOutFile);
	
}
