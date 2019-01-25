#include "Common.h"
#include "Lowermain.h"
#include <string.h>
#include "main.h"
#include "de.h"

void finalOutput(){
	int i;
//	extern char version[];
	extern char shelloutput[];
//	extern int printFunctionPlots;
//	extern int pdbSwitch;
	extern int finalpdbswitch;
	extern int print;
//	extern int diagnose_print;
	extern char *strat[];
	extern char *popstrat[];
//	extern double resolutionHighInit;
//	extern double resolutionHigh[n_potentials];
//	extern double resolutionLow;
//	extern double stepSizeMain;
	extern int writefinalpdb;
//	extern long nfeval; 
	extern int debug; 
	printf("parameter optimization is complete, will start printing..\n");			
	printf("After optimization\n");
	//        for(i=0; i<n_potentials+neu_potentials; i++){
	//                printf("dlewis[%d] is %f\n",i,dlewis[i]);
	//        }
	for (i = 0; i < n_potentials; i++)
		final_potentials[i]= dlewis[i];
	//finaldev = evaluate(n_vary,dlewis,&nfeval); 
	finaldev = status();
	printf("final deviations are taken from status..\n");

	//print to a text file
	OutFile = fopen(directory, "a+");
	fprintf(OutFile, "|=========================================================================================================================|\n");
	fprintf(OutFile, "|                                                  POTENTIAL PARAMETERS                                                   |\n");
	fprintf(OutFile, "|						 bash %s.%02d.sh 1 %d %d 0                                                |\n", shelloutput, shellversion, simulation, shellkey);
	fprintf(OutFile, "|                                                %s", asctime (timeinfo));
	fprintf(OutFile, "|Suite Total Deviation (Structural and Thermodynamics)...................................................%8.2e percent |\n", (finaldev)*100);
	fprintf(OutFile, "|Suite Structural Deviation .............................................................................%8.2e percent |\n", zStructfinal*100);		
	fprintf(OutFile, "|Oxygen Hydrides Structural Deviation ...................................................................%8.2e percent |\n", devOHydrideStruct*100);
	fprintf(OutFile, "|O, C, N Structural Deviation ...........................................................................%8.2e percent |\n", devNCOHydrideStruct*100);
	fprintf(OutFile, "|Thermo Deviation........................................................................................%8.2e percent |\n", devspinThermo*100);
	//			fprintf(OutFile, "|Flexibility Deviation...................................................................................% 8.2f percent |\n", devFlex*100);
	//                      fprintf(OutFile, "|Suite Total Weight......................................................................................% 8.2f percent |\n", totalweight);

/*
	//Row beginning and end points
	int i0_1 =  0; int if_1 = n_AA+n_AB+n_AH+n_HH;  //AA, AB, AH, HH
	int i0_2 =  1; int if_2 = n_AA+n_AB+n_AH+n_HH;
	int i0_3 = if_1; int if_3 = if_1 + n_CA + n_NA + n_OA + n_CH + n_NH + n_OH;  //XA XH
	int i0_4 = if_2+1; int if_4 = if_3;
	int i0_5 = if_3; int if_5 = if_3 + n_CC + n_NN + n_OO + n_CN + n_CO + n_NO;  //XY
	int i0_6 = if_4+1; int if_6 = if_5;
	int i0_7 = if_6; int if_7 = if_6 + n_SiA + n_PA + n_SA;
	int i0_8 = if_7; int if_8 = if_7 + n_FA + n_BoA + n_AlA;
	int i0_9 = if_8; int if_9 = if_8 + n_ClA + n_LiA + n_BeA;
	int i0_10 = if_9; int if_10 = if_9 + n_NaA + n_MgA + n_MA;
	int i0_11 = if_10; int if_11 = if_10 + 13;
	int i0_12 = if_11; int if_12 = if_11 + (n_KE - 13);
	int i0_13 = if_12; int if_13 = if_12 + n_XA;
	printf("i's are: %d %d %d %d %d %d %d %d %d %d %d %d\n",i0_1, i0_2, i0_3, i0_4, i0_5, i0_6, i0_7, i0_8, i0_9, i0_10, i0_11, i0_12);
	printf("f's are: %d %d %d %d %d %d %d %d %d %d %d %d\n",if_1, if_2, if_3, if_4, if_5, if_6, if_7, if_8, if_9, if_10, if_11, if_12);
*/
	//First Row Parameters
	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    | TauAB1 | TauAB2 | KapAB1 | KapAB2 | KapAB3 |  n.a.  | TauK1  | TauK2  |   n.a. |   n.a. |   n.a. |  n.a.  |  SigAB |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i = 0; i < 13; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i = 0; i < 13; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i = 0; i < 13; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    | ChiexK | TauexK1| TauexK2| ChiexR | TauexR1| TauexR2| ChiexA | Tauex0 | Tauex1 | Tauex2 | Tauex3 | Tauex4 |  n.a.  |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i = 13; i < 26; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i = 13; i < 26; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i = 13; i < 26; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauAH |  RhoAH | KapAH1 | KapAH2 | KapAH3 | ChiexH |TauexHc2| ChiexHc|TauexHc1| TauexH1| TauexH2| TauexH3| TauexH0|\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =26; i < 39; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =26; i < 39; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =26; i < 39; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    | TauLiA | RhoLiA | KapLiA1| KapLiA2| KapLiA3|  n.a.  |KapexLi1|KapexLi2|KapexLi3| TauexLi| RhoexLi|  n.a.  | SigLiA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =39; i < 52; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =39; i < 52; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =39; i < 52; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");


	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    | TauBeA | RhoBeA | KapBeA1| KapBeA2| KapBeA3|  n.a.  |KapexBe1|KapexBe2|KapexBe3| TauexBe| RhoexBe|  n.a.  | SigBeA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =52; i < 65; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =52; i < 65; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =52; i < 65; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");


	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    | TauBoA | RhoBoA | KapBoA1| KapBoA2| KapBoA3|  n.a.  |KapexBo1|KapexBo2|KapexBo3| TauexBo| RhoexBo|  n.a.  | SigBoA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =65; i < 78; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =65; i < 78; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =65; i < 78; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");


	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauCA |  RhoCA | KapCA1 | KapCA2 | KapCA3 |  n.a.  |TauexCc2| ChiexCc|TauexCc1| TauexC | RhoexC |  n.a.  |  SigCA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =78; i < 91; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =78; i < 91; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =78; i < 91; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauNA |  RhoNA | KapNA1 | KapNA2 | KapNA3 |  n.a.  |TauexNc2| ChiexNc|TauexNc1| TauexN1| TauexN2|  n.a.  |  SigNA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =91; i < 104; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =91; i < 104; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =91; i < 104; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauOA |  RhoOA | KapOA1 | KapOA2 | KapOA3 | ChiexO |TauexOc1|TauexOc2|TauexOc3| TauexO1| TauexO2| TauexO3| TauexO0|\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =104; i <117; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =104; i <117; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =104; i <117; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");


	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauFA |  RhoFA | KapFA1 | KapFA2 | KapFA3 |  n.a.  | ChiexF | KapexF2| KapexF3| TauexF1| TauexF2|  n.a.  |  SigFA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =117; i <130; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =117; i <130; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =117; i <130; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    | TauNaA | RhoNaA | KapNaA1| KapNaA2| KapNaA3|  n.a.  |KapexNa1|KapexNa2|KapexNa3| TauexNa| RhoexNa|  n.a.  | SigNaA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =130; i <143; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =130; i <143; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =130; i <143; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    | TauMgA | RhoMgA | KapMgA1| KapMgA2| KapMgA3|  n.a.  |KapexMg1|KapexMg2|KapexMg3| TauexMg| RhoexMg|  n.a.  | SigMgA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =143; i <156; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =143; i <156; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =143; i <156; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    | TauAlA | RhoAlA | KapAlA1| KapAlA2| KapAlA3|  n.a.  |KapexAl1|KapexAl2|KapexAl3| TauexAl| RhoexAl|  n.a.  | SigAlA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =156; i <169; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =156; i <169; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =156; i <169; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    | TauSiA | RhoSiA | KapSiA1| KapSiA2| KapSiA3|  n.a.  |KapexSi1|KapexSi2|KapexSi3| TauexSi| RhoexSi|  n.a.  | SigSiA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =169; i <182; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =169; i <182; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =169; i <182; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauPA |  RhoPA | KapPA1 | KapPA2 | KapPA3 |  n.a.  | KapexP1| KapexP2| KapexP3| TauexP | RhoexP |  n.a.  |  SigPA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =182; i <195; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =182; i <195; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =182; i <195; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauSA |  RhoSA | KapSA1 | KapSA2 | KapSA3 |  n.a.  | ChiexS | KapexS2| KapexS3| TauexS1| TauexS2|  n.a.  |  SigSA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =195; i <208; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =195; i <208; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =195; i <208; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    | TauClA | RhoClA | KapClA1| KapClA2| KapClA3|  n.a.  | ChiexCl|KapexCl2|KapexCl3|TauexCl1|TauexCl2|  n.a.  | SigClA |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =208; i <221; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =208; i <221; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =208; i <221; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauFeA|  RhoFeA| KapFeA1| KapFeA2|KapFeA3|ChiexFe|TauexFec2|ChiexFec|TauexFec1|TauexFe1|TauexFe2|TauexFe3|  SigFeA|\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =221; i <234; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =221; i <234; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =221; i <234; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauMA |  RhoMA | KapMA1 | KapMA2 | KapMA3 | ChiexM |TauexMc2| ChiexMc|TauexMc1| TauexM1| TauexM2| TauexM3| TauexM0|\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =234; i <247; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =234; i <247; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =234; i <247; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");


	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauCH |  RhoCH |  KapCH |  n.a.  |  n.a.  |  n.a.  |  TauNH |  RhoNH |  KapNH |  n.a.  |  n.a.  |  n.a.  |  n.a.  |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =247; i <259; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =247; i <259; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =247; i <259; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");


	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauOH |  RhoOH |  KapOH |  n.a.  |  n.a.  |  n.a.  |  TauCC |  RhoCC |  KapCC |  n.a.  |  n.a.  |  n.a.  |  n.a.  |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =259; i <271; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =259; i <271; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =259; i <271; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");


	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauNN |  RhoNN |  KapNN |  n.a.  |  n.a.  |  n.a.  |  TauOO |  RhoOO |  KapOO |  n.a.  |  n.a.  |  n.a.  |  n.a.  |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =271; i <283; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =271; i <283; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =271; i <283; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");


	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauCN |  RhoCN |  KapCN |  n.a.  |  n.a.  |  n.a.  |  TauCO |  RhoCO |  KapCO |  n.a.  |  n.a.  |  n.a.  |  n.a.  |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =283; i <295; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =283; i <295; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =283; i <295; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");


	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  TauNO |  RhoNO |  KapNO |  n.a.  |  n.a.  |  n.a.  |  TauHH |  RhoHH |  KapHH |  n.a.  |  n.a.  |  n.a.  |  n.a.  |\n");
                                                  
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| I  |");

	for (i =295; i <307; i++){
		if (ist_potentials[i] < 10)  { fprintf(OutFile, "% 7.5f|", ist_potentials[i]); continue; }
		if (ist_potentials[i] < 100) { fprintf(OutFile, "% 7.4f|", ist_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", ist_potentials[i]);
	}
	fprintf(OutFile, "\n| F  |");

	for (i =295; i <307; i++){
		if (final_potentials[i] < 10)   {fprintf(OutFile, "% 7.5f|", final_potentials[i]); continue; }
		if (final_potentials[i] < 100)  {fprintf(OutFile, "% 7.4f|", final_potentials[i]); continue; }
		fprintf(OutFile, "% 7.3f|", final_potentials[i]);
	}
	fprintf(OutFile, "\n| f  |");

	for (i =295; i <307; i++){
		if (key_potentials[i]) { fprintf(OutFile, "   N    |");}
		else                   { fprintf(OutFile, "   Y    |");}
	}
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
	fprintf(OutFile, "|    |  NeuAA1|  NeuAA2|  n.a.  |   n.a. |  n.a.  |  n.a.  |  n.a.  |   n.a. |  n.a.  |  n.a.  | NeuXY1 | NeuXY2 |  n.a.  |\n");
	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");


	fprintf(OutFile, "| F  |");
	for (i = 0; i < 13; i++)
		fprintf(OutFile, "  %2i    |", (int) dlewis[n_potentials + i]);
	fprintf(OutFile, "\n");

	fprintf(OutFile, "|=========================================================================================================================|\n");
        fprintf(OutFile, "|    |  n.a.  |  n.a.  |  n.a.  |  n.a   |  n.a.  |  n.a.  |  n.a.  |  n.a.  |  n.a.  |  n.a.  |  n.a.  |  n.a.  |  n.a.  |\n");

	fprintf(OutFile, "|====|========|========|========|========|========|========|========|========|========|========|========|========|========|\n");

	fprintf(OutFile, "| F  |");
	for (i = 13; i < neu_potentials; i++)
		fprintf(OutFile, "  %2i    |", (int) dlewis[n_potentials + i]);
	fprintf(OutFile, "\n");


	fprintf(OutFile, "|=========================================================================================================================|\n");
	fprintf(OutFile, "|                                                        WEIGHTS                                                          |\n");
	fprintf(OutFile, "|=========================================================================================================================|\n");
	fprintf(OutFile, "|      Molecule         |     Sum     |                     Feature(s) and weight(s)                                      |\n");
	fprintf(OutFile, "|=========================================================================================================================|\n");
	fprintf(OutFile, "| H2                    |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH2, wspinH2);

//	fprintf(OutFile, "| H2v                   |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH2v, wspinH2v);
	fprintf(OutFile, "| H2+                   |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH2plus, wspinH2plus);
	fprintf(OutFile, "| H2-                   |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH2minus, wspinH2minus);
	fprintf(OutFile, "| H2*                   |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH2trp, wspinH2trp);

	fprintf(OutFile, "| H3+                   |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH3plus, wspinH3pluslength);
	fprintf(OutFile, "| H3                    |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH3, wspinH3);
	fprintf(OutFile, "| H4                    |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH4, wspinH4);
        fprintf(OutFile, "| H3linear              |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH3linear, wspinH3linear);
        fprintf(OutFile, "| H3trig                |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH3trig, wspinH3trig);
        fprintf(OutFile, "| H4linear              |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH4linear, wspinH4linear);
        fprintf(OutFile, "| H4square              |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH4square, wspinH4square);
        fprintf(OutFile, "| H4tetra               |   % 7.1f   | HH  % 5.1f |           |           |           |           |           |           |\n", wspinH4tetra, wspinH4tetra);
	fprintf(OutFile, "| H                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinH);
	fprintf(OutFile, "| H-                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinH_);


	fprintf(OutFile, "| OH*                   |   % 7.1f   | OH  % 5.1f |           |           |           |           |           |           |\n", wspinOHdot, wspinOHdot);
	fprintf(OutFile, "| OH-                   |   % 7.1f   | OH  % 5.1f |           |           |           |           |           |           |\n", wspinOH, wspinOH);
	fprintf(OutFile, "| OH* (2)               |   % 7.1f   | OH  % 5.1f |           |           |           |           |           |           |\n", wspinOHdot2, wspinOHdot2);

	fprintf(OutFile, "| H2O                   |   % 7.1f   | HOH % 5.1f | OH  % 5.1f | OBi % 5.1f | OLp % 5.1f |           |           |           |\n", wspinH2O, wspinH2Oangle, wspinH2Olength, wspinH2OlengthOBP, wspinH2OlengthOLP);
	fprintf(OutFile, "| H2O (linear)          |   % 7.1f   | HOH % 5.1f | OH  % 5.1f | OBi % 5.1f | OLp % 5.1f |           |           |           |\n", wspinH2Olinear, wspinH2Olinearangle, wspinH2Olinearlength, wspinH2OlinearlengthOBP, wspinH2OlinearlengthOLP);
	fprintf(OutFile, "| H2O+                  |   % 7.1f   | HOH % 5.1f | OH  % 5.1f |           |           |           |           |           |\n", wspinH2Oplus, wspinH2Oplusangle, wspinH2Opluslength);
	fprintf(OutFile, "| H3O+                  |   % 7.1f   | HOH % 5.1f | OH  % 5.1f |           |           |           |           |           |\n", wspinH3O, wspinH3Oangle, wspinH3Olength);
	fprintf(OutFile, "| O-2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO_2);
	fprintf(OutFile, "| O-1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO_1);
	fprintf(OutFile, "| O                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOneutrl);
	fprintf(OutFile, "| O+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus1);
	fprintf(OutFile, "| O+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus2);
	fprintf(OutFile, "| O+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus3);
	fprintf(OutFile, "| O+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus4);
	fprintf(OutFile, "| O+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus5);
	fprintf(OutFile, "| O*                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOneutrlex);

	fprintf(OutFile, "| O**                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOneutrlex2);
	fprintf(OutFile, "| O+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus1ex);
	fprintf(OutFile, "| O+1**                 |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus1ex2);
	fprintf(OutFile, "| O+2*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus2ex);
	fprintf(OutFile, "| O+2**                 |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus2ex2);
	fprintf(OutFile, "| O+3*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus3ex);
	fprintf(OutFile, "| O+4*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOplus4ex);

	fprintf(OutFile, "|C+3                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCplus3);
	fprintf(OutFile, "|C+2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCplus2);
	fprintf(OutFile, "|C+1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCplus1);
	fprintf(OutFile, "|C                      |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCneutrl);
	fprintf(OutFile, "|C-1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinC_1);
	fprintf(OutFile, "|N+4                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNplus4);
	fprintf(OutFile, "|N+3                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNplus3);
	fprintf(OutFile, "|N+2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNplus2);
	fprintf(OutFile, "|N+1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNplus1);
	fprintf(OutFile, "|N                      |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNneutrl);
	fprintf(OutFile, "|N-1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinN_1);
	fprintf(OutFile, "|S+5                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSplus5);
	fprintf(OutFile, "|S+4                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSplus4);
	fprintf(OutFile, "|S+3                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSplus3);
	fprintf(OutFile, "|S+2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSplus2);
	fprintf(OutFile, "|S+1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSplus1);
	fprintf(OutFile, "|S                      |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSneutrl);
	fprintf(OutFile, "|S-1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinS_1);
	fprintf(OutFile, "|P+4                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPplus4);
	fprintf(OutFile, "|P+3                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPplus3);
	fprintf(OutFile, "|P+2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPplus2);
	fprintf(OutFile, "|P+1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPplus1);
	fprintf(OutFile, "|P                      |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPneutrl);
	fprintf(OutFile, "|P-1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinP_1);
	fprintf(OutFile, "|Si+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSiplus3);
	fprintf(OutFile, "|Si+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSiplus2);
	fprintf(OutFile, "|Si+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSiplus1);
	fprintf(OutFile, "|Si                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSineutrl);
	fprintf(OutFile, "|Si-1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSi_1);
	fprintf(OutFile, "|F+6                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus6);
	fprintf(OutFile, "|F+5                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus5);
	fprintf(OutFile, "|F+4                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus4);
	fprintf(OutFile, "|F+3                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus3);
	fprintf(OutFile, "|F+2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus2);
	fprintf(OutFile, "|F+1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus1);
	fprintf(OutFile, "|F                      |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFneutrl);
	fprintf(OutFile, "|F-1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinF_1);
	fprintf(OutFile, "|C+2*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCplus2ex);
	fprintf(OutFile, "|C+1*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCplus1ex);
	fprintf(OutFile, "|C*                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCneutrlex);
	fprintf(OutFile, "|C**                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCneutrlex2);
	fprintf(OutFile, "|N+3*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNplus3ex);
	fprintf(OutFile, "|N+2*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNplus2ex);
	fprintf(OutFile, "|N+1*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNplus1ex);
	fprintf(OutFile, "|N+1**                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNplus1ex2);
	fprintf(OutFile, "|N*                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNneutrlex);
	fprintf(OutFile, "|N**                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNneutrlex2);
	fprintf(OutFile, "|F+5*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus5ex);
	fprintf(OutFile, "|F+4*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus4ex);
	fprintf(OutFile, "|F+3*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus3ex);
	fprintf(OutFile, "|F+3**                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus3ex2);
	fprintf(OutFile, "|F+2*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus2ex);
	fprintf(OutFile, "|F+2**                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus2ex2);
	fprintf(OutFile, "|F+1*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus1ex);
	fprintf(OutFile, "|F+1**                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFplus1ex2);
	fprintf(OutFile, "|F*                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFneutrlex);
	fprintf(OutFile, "|Si+2*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSiplus2ex);
	fprintf(OutFile, "|Si+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSiplus1ex);
	fprintf(OutFile, "|Si*                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSineutrlex);
	fprintf(OutFile, "|Si**                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSineutrlex2);
	fprintf(OutFile, "|P+3*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPplus3ex);
	fprintf(OutFile, "|P+2*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPplus2ex);
	fprintf(OutFile, "|P+1*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPplus1ex);
	fprintf(OutFile, "|P+1**                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPplus1ex2);
	fprintf(OutFile, "|P*                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPneutrlex);
	fprintf(OutFile, "|S+4*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSplus4ex);
	fprintf(OutFile, "|S+3*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSplus3ex);
	fprintf(OutFile, "|S+2*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSplus2ex);
	fprintf(OutFile, "|S+2**                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSplus2ex2);
	fprintf(OutFile, "|S+1*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSplus1ex);
	fprintf(OutFile, "|S*                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSneutrlex);
	fprintf(OutFile, "|S**                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSneutrlex2);
	fprintf(OutFile, "|Bo-1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinB_1);
	fprintf(OutFile, "|Bo*                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinBneutrlex);
	fprintf(OutFile, "|Bo                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinBneutrl);
	fprintf(OutFile, "|Bo+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinBplus1ex);
	fprintf(OutFile, "|Bo+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinBplus1);
	fprintf(OutFile, "|Bo+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinBplus2);
	fprintf(OutFile, "|Cl-1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCl_1);
	fprintf(OutFile, "|Cl*                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClneutrlex);
	fprintf(OutFile, "|Cl                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClneutrl);
	fprintf(OutFile, "|Cl+1**                 |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus1ex2);
	fprintf(OutFile, "|Cl+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus1ex);
	fprintf(OutFile, "|Cl+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus1);
	fprintf(OutFile, "|Cl+2*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus2ex);
	fprintf(OutFile, "|Cl+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus2);
	fprintf(OutFile, "|Cl+3**                 |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus3ex2);
	fprintf(OutFile, "|Cl+3*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus3ex);
	fprintf(OutFile, "|Cl+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus3);
	fprintf(OutFile, "|Cl+4*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus4ex);
	fprintf(OutFile, "|Cl+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus4);
	fprintf(OutFile, "|Cl+5*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus5ex);
	fprintf(OutFile, "|Cl+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus5);
	fprintf(OutFile, "|Cl+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClplus6);
	fprintf(OutFile, "|Al-1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAl_1);
	fprintf(OutFile, "|Al*                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAlneutrlex);
	fprintf(OutFile, "|Al                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAlneutrl);
	fprintf(OutFile, "|Al+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAlplus1ex);
	fprintf(OutFile, "|Al+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAlplus1);
	fprintf(OutFile, "|Al+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAlplus2);
	fprintf(OutFile, "|Li-1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinLi_1);
	fprintf(OutFile, "|Li                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinLineutrl);
	fprintf(OutFile, "|Be                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinBeneutrl);
	fprintf(OutFile, "|Be*                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinBeneutrlex);
	fprintf(OutFile, "|Be+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinBeplus1);
	fprintf(OutFile, "|Na-1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNa_1);
	fprintf(OutFile, "|Na                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNaneutrl);
	fprintf(OutFile, "|Mg                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMgneutrl);
	fprintf(OutFile, "|Mg*                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMgneutrlex);
	fprintf(OutFile, "|Mg+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMgplus1);



	fprintf(OutFile, "| O2-2                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2_2);
	fprintf(OutFile, "| O2-2  (v)             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2_2v);
	fprintf(OutFile, "| O2-1                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2_1);
	fprintf(OutFile, "| O2+1                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2plus1);
	fprintf(OutFile, "| O2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2);
	fprintf(OutFile, "| O2dia                 |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2dia);
        fprintf(OutFile, "| O2 linnett            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2_linnett);
        fprintf(OutFile, "| O2 snglbnd            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2_snglbnd);
        fprintf(OutFile, "| O2 dblbnd             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2_dblbnd);
        fprintf(OutFile, "| O2 trplbnd            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2_trplbnd);
        fprintf(OutFile, "| O2dia linnett         |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2dia_linnett);
        fprintf(OutFile, "| O2dia snglbnd         |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2dia_snglbnd);
        fprintf(OutFile, "| O2dia dblbnd          |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2dia_dblbnd);
        fprintf(OutFile, "| O2dia trplbnd         |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2dia_trplbnd);
	fprintf(OutFile, "| O2qnt                 |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinO2qnt);



	fprintf(OutFile, "| Al2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAl2_trplt);
	fprintf(OutFile, "| Al2dia                |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAl2_snglt);
	fprintf(OutFile, "| Bo2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinB2_trplt);
	fprintf(OutFile, "| Bo2dia                |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinB2_snglt);
	fprintf(OutFile, "| C2para                |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinC2_trplt);
	fprintf(OutFile, "| C2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinC2_snglt);
	fprintf(OutFile, "| Si2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSi2_trplt);
	fprintf(OutFile, "| Si2dia                |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSi2_snglt);
	fprintf(OutFile, "| N2para                |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinN2_trplt);
	fprintf(OutFile, "| N2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinN2_snglt);
        fprintf(OutFile, "| P2para                |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinP2_trplt);
        fprintf(OutFile, "| P2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinP2_snglt);

	fprintf(OutFile, "| S2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinS2_trplt);
	fprintf(OutFile, "| S2dia                 |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinS2_snglt);
	fprintf(OutFile, "| F2para                |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinF2_trplt);
	fprintf(OutFile, "| F2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinF2_snglt);
	fprintf(OutFile, "| Cl2para               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCl2_trplt);
	fprintf(OutFile, "| Cl2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCl2_snglt);

	fprintf(OutFile, "| H  polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinH_polar);
        fprintf(OutFile, "| B  polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinBneutrl_polar);
        fprintf(OutFile, "| C  polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCneutrl_polar);
        fprintf(OutFile, "| N  polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNneutrl_polar);
        fprintf(OutFile, "| O  polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinOneutrl_polar);
        fprintf(OutFile, "| F  polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFneutrl_polar);
        fprintf(OutFile, "| Al polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAlneutrl_polar);
        fprintf(OutFile, "| Si polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSineutrl_polar);
        fprintf(OutFile, "| P  polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPneutrl_polar);
        fprintf(OutFile, "| S  polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinSneutrl_polar);
        fprintf(OutFile, "| Cl polarizability     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinClneutrl_polar);


	fprintf(OutFile, "|Zn+11                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus11);
	fprintf(OutFile, "|Zn+10                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus10);
	fprintf(OutFile, "|Zn+10                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus10ex);
	fprintf(OutFile, "|Zn+9                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus9);
	fprintf(OutFile, "|Zn+8                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus8);
	fprintf(OutFile, "|Zn+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus7);
	fprintf(OutFile, "|Zn+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus6);
	fprintf(OutFile, "|Zn+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus6ex);
	fprintf(OutFile, "|Zn+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus6ex2);
	fprintf(OutFile, "|Zn+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus5);
	fprintf(OutFile, "|Zn+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus5ex);
	fprintf(OutFile, "|Zn+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus5ex2);
	fprintf(OutFile, "|Zn+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus4);
	fprintf(OutFile, "|Zn+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus4ex);
	fprintf(OutFile, "|Zn+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus4ex2);
	fprintf(OutFile, "|Zn+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus3);
	fprintf(OutFile, "|Zn+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus3ex);
	fprintf(OutFile, "|Zn+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus2);
	fprintf(OutFile, "|Zn+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus2ex);
	fprintf(OutFile, "|Zn+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus1);
	fprintf(OutFile, "|Zn+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnplus1ex);
	fprintf(OutFile, "|Znneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnneutrl);
	fprintf(OutFile, "|Znneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZnneutrlex);
	fprintf(OutFile, "|Sc+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinScplus2);
	fprintf(OutFile, "|Sc+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinScplus1);
	fprintf(OutFile, "|Sc+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinScplus1ex);
	fprintf(OutFile, "|Scneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinScneutrl);
	fprintf(OutFile, "|Scneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinScneutrlex);
	fprintf(OutFile, "|Ti+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTiplus3);
	fprintf(OutFile, "|Ti+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTiplus2);
	fprintf(OutFile, "|Ti+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTiplus2ex);
	fprintf(OutFile, "|Ti+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTiplus1);
	fprintf(OutFile, "|Ti+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTiplus1ex);
	fprintf(OutFile, "|Tineutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTineutrl);
	fprintf(OutFile, "|Tineutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTineutrlex);
	fprintf(OutFile, "|Tineutrlex2            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTineutrlex2);
	fprintf(OutFile, "|V+4                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVplus4);
	fprintf(OutFile, "|V+3                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVplus3);
	fprintf(OutFile, "|V+3                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVplus3ex);
	fprintf(OutFile, "|V+2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVplus2);
	fprintf(OutFile, "|V+2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVplus2ex);
	fprintf(OutFile, "|V+1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVplus1);
	fprintf(OutFile, "|V+1*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVplus1ex);
	fprintf(OutFile, "|V+1**                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVplus1ex2);
	fprintf(OutFile, "|Vneutrl                |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVneutrl);
	fprintf(OutFile, "|Vneutrlex              |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVneutrlex);
	fprintf(OutFile, "|Vneutrlex2             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinVneutrlex2);
	fprintf(OutFile, "|Cr+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus5);
	fprintf(OutFile, "|Cr+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus4);
	fprintf(OutFile, "|Cr+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus4ex);
	fprintf(OutFile, "|Cr+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus3);
	fprintf(OutFile, "|Cr+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus3ex);
	fprintf(OutFile, "|Cr+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus2);
	fprintf(OutFile, "|Cr+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus2ex);
	fprintf(OutFile, "|Cr+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus2ex2);
	fprintf(OutFile, "|Cr+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus1);
	fprintf(OutFile, "|Cr+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus1ex);
	fprintf(OutFile, "|Cr+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrplus1ex2);
	fprintf(OutFile, "|Crneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrneutrl);
	fprintf(OutFile, "|Crneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrneutrlex);
	fprintf(OutFile, "|Crneutrlex2            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrneutrlex2);
	fprintf(OutFile, "|Crneutrlex3            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCrneutrlex3);
	fprintf(OutFile, "|Mn+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus6);
	fprintf(OutFile, "|Mn+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus5);
	fprintf(OutFile, "|Mn+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus5ex);
	fprintf(OutFile, "|Mn+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus4);
	fprintf(OutFile, "|Mn+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus4ex);
	fprintf(OutFile, "|Mn+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus3);
	fprintf(OutFile, "|Mn+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus3ex);
	fprintf(OutFile, "|Mn+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus2);
	fprintf(OutFile, "|Mn+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus2ex);
	fprintf(OutFile, "|Mn+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus2ex2);
	fprintf(OutFile, "|Mn+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus1);
	fprintf(OutFile, "|Mn+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus1ex);
	fprintf(OutFile, "|Mn+1**                 |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus1ex2);
	fprintf(OutFile, "|Mn+1*  3               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnplus1ex3);
	fprintf(OutFile, "|Mnneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnneutrl);
	fprintf(OutFile, "|Mnneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnneutrlex);
	fprintf(OutFile, "|Mnneutrlex2            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnneutrlex2);
	fprintf(OutFile, "|Mnneutrlex3            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMnneutrlex3);
	fprintf(OutFile, "|Fe+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus7);
	fprintf(OutFile, "|Fe+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus6);
	fprintf(OutFile, "|Fe+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus6ex);
	fprintf(OutFile, "|Fe+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus5);
	fprintf(OutFile, "|Fe+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus5ex);
	fprintf(OutFile, "|Fe+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus4);
	fprintf(OutFile, "|Fe+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus4ex);
	fprintf(OutFile, "|Fe+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus4ex2);
	fprintf(OutFile, "|Fe+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus3);
	fprintf(OutFile, "|Fe+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus3ex);
	fprintf(OutFile, "|Fe+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus3ex2);
	fprintf(OutFile, "|Fe+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus2);
	fprintf(OutFile, "|Fe+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus2ex);
	fprintf(OutFile, "|Fe+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus2ex2);
	fprintf(OutFile, "|Fe+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus1);
	fprintf(OutFile, "|Fe+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus1ex);
	fprintf(OutFile, "|Fe+1**                 |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeplus1ex2);
	fprintf(OutFile, "|Feneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeneutrl);
	fprintf(OutFile, "|Feneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeneutrlex);
	fprintf(OutFile, "|Feneutrlex2            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeneutrlex2);
	fprintf(OutFile, "|Feneutrlex3            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinFeneutrlex3);
	fprintf(OutFile, "|Co+8                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus8);
	fprintf(OutFile, "|Co+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus7);
	fprintf(OutFile, "|Co+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus7ex);
	fprintf(OutFile, "|Co+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus6);
	fprintf(OutFile, "|Co+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus6ex);
	fprintf(OutFile, "|Co+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus5);
	fprintf(OutFile, "|Co+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus5ex);
	fprintf(OutFile, "|Co+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus5ex2);
	fprintf(OutFile, "|Co+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus4);
	fprintf(OutFile, "|Co+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus4ex);
	fprintf(OutFile, "|Co+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus4ex2);
	fprintf(OutFile, "|Co+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus3);
	fprintf(OutFile, "|Co+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus3ex);
	fprintf(OutFile, "|Co+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus3ex2);
	fprintf(OutFile, "|Co+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus2);
	fprintf(OutFile, "|Co+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus2ex);
	fprintf(OutFile, "|Co+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus2ex2);
	fprintf(OutFile, "|Co+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus1);
	fprintf(OutFile, "|Co+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus1ex);
	fprintf(OutFile, "|Co+1**                 |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCoplus1ex2);
	fprintf(OutFile, "|Coneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinConeutrl);
	fprintf(OutFile, "|Coneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinConeutrlex);
	fprintf(OutFile, "|Ni+9                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus9);
	fprintf(OutFile, "|Ni+8                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus8);
	fprintf(OutFile, "|Ni+8                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus8ex);
	fprintf(OutFile, "|Ni+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus7);
	fprintf(OutFile, "|Ni+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus7ex);
	fprintf(OutFile, "|Ni+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus6);
	fprintf(OutFile, "|Ni+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus6ex);
	fprintf(OutFile, "|Ni+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus5);
	fprintf(OutFile, "|Ni+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus5ex);
	fprintf(OutFile, "|Ni+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus5ex2);
	fprintf(OutFile, "|Ni+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus4);
	fprintf(OutFile, "|Ni+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus4ex);
	fprintf(OutFile, "|Ni+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus4ex2);
	fprintf(OutFile, "|Ni+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus3);
	fprintf(OutFile, "|Ni+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus3ex);
	fprintf(OutFile, "|Ni+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus3ex2);
	fprintf(OutFile, "|Ni+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus2);
	fprintf(OutFile, "|Ni+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus2ex);
	fprintf(OutFile, "|Ni+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus2ex2);
	fprintf(OutFile, "|Ni+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus1);
	fprintf(OutFile, "|Ni+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNiplus1ex);
	fprintf(OutFile, "|Nineutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNineutrl);
	fprintf(OutFile, "|Nineutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNineutrlex);
	fprintf(OutFile, "|Cu+10                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus10);
	fprintf(OutFile, "|Cu+9                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus9);
	fprintf(OutFile, "|Cu+9                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus9ex);
	fprintf(OutFile, "|Cu+8                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus8);
	fprintf(OutFile, "|Cu+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus7);
	fprintf(OutFile, "|Cu+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus6);
	fprintf(OutFile, "|Cu+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus5);
	fprintf(OutFile, "|Cu+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus5ex);
	fprintf(OutFile, "|Cu+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus5ex2);
	fprintf(OutFile, "|Cu+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus4);
	fprintf(OutFile, "|Cu+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus4ex);
	fprintf(OutFile, "|Cu+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus4ex2);
	fprintf(OutFile, "|Cu+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus3);
	fprintf(OutFile, "|Cu+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus3ex);
	fprintf(OutFile, "|Cu+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus3ex2);
	fprintf(OutFile, "|Cu+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus2);
	fprintf(OutFile, "|Cu+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus2ex);
	fprintf(OutFile, "|Cu+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus1);
	fprintf(OutFile, "|Cu+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuplus1ex);
	fprintf(OutFile, "|Cuneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuneutrl);
	fprintf(OutFile, "|Cuneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCuneutrlex);
	fprintf(OutFile, "|Y+2                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinYplus2);
	fprintf(OutFile, "|Y+1                    |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinYplus1);
	fprintf(OutFile, "|Y+1*                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinYplus1ex);
	fprintf(OutFile, "|Yneutrl                |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinYneutrl);
	fprintf(OutFile, "|Yneutrlex              |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinYneutrlex);
	fprintf(OutFile, "|Zr+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZrplus3);
	fprintf(OutFile, "|Zr+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZrplus2);
	fprintf(OutFile, "|Zr+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZrplus2ex);
	fprintf(OutFile, "|Zr+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZrplus1);
	fprintf(OutFile, "|Zr+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZrplus1ex);
	fprintf(OutFile, "|Zrneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZrneutrl);
	fprintf(OutFile, "|Zrneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZrneutrlex);
	fprintf(OutFile, "|Zrneutrlex2            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinZrneutrlex2);
	fprintf(OutFile, "|Nb+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbplus4);
	fprintf(OutFile, "|Nb+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbplus3);
	fprintf(OutFile, "|Nb+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbplus3ex);
	fprintf(OutFile, "|Nb+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbplus2);
	fprintf(OutFile, "|Nb+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbplus2ex);
	fprintf(OutFile, "|Nb+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbplus1);
	fprintf(OutFile, "|Nb+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbplus1ex);
	fprintf(OutFile, "|Nb+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbplus1ex2);
	fprintf(OutFile, "|Nbneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbneutrl);
	fprintf(OutFile, "|Nbneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbneutrlex);
	fprintf(OutFile, "|Nbneutrlex2            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinNbneutrlex2);
	fprintf(OutFile, "|Mo+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus5);
	fprintf(OutFile, "|Mo+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus4);
	fprintf(OutFile, "|Mo+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus4ex);
	fprintf(OutFile, "|Mo+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus3);
	fprintf(OutFile, "|Mo+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus3ex);
	fprintf(OutFile, "|Mo+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus2);
	fprintf(OutFile, "|Mo+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus2ex);
	fprintf(OutFile, "|Mo+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus2ex2);
	fprintf(OutFile, "|Mo+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus1);
	fprintf(OutFile, "|Mo+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus1ex);
	fprintf(OutFile, "|Mo+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoplus1ex2);
	fprintf(OutFile, "|Moneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoneutrl);
	fprintf(OutFile, "|Moneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoneutrlex);
	fprintf(OutFile, "|Moneutrlex2            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoneutrlex2);
	fprintf(OutFile, "|Moneutrlex3            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinMoneutrlex3);
	fprintf(OutFile, "|Tc+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcplus6);
	fprintf(OutFile, "|Tc+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcplus5);
	fprintf(OutFile, "|Tc+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcplus4);
	fprintf(OutFile, "|Tc+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcplus3);
	fprintf(OutFile, "|Tc+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcplus2);
	fprintf(OutFile, "|Tc+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcplus1);
	fprintf(OutFile, "|Tc+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcplus1ex);
	fprintf(OutFile, "|Tcneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcneutrl);
	fprintf(OutFile, "|Tcneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcneutrlex);
	fprintf(OutFile, "|Tcneutrlex2            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcneutrlex2);
	fprintf(OutFile, "|Tcneutrlex3            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinTcneutrlex3);
	fprintf(OutFile, "|Ru+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuplus7);
	fprintf(OutFile, "|Ru+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuplus6);
	fprintf(OutFile, "|Ru+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuplus5);
	fprintf(OutFile, "|Ru+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuplus4);
	fprintf(OutFile, "|Ru+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuplus3);
	fprintf(OutFile, "|Ru+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuplus2);
	fprintf(OutFile, "|Ru+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuplus2ex);
	fprintf(OutFile, "|Ru+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuplus1);
	fprintf(OutFile, "|Ru+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuplus1ex);
	fprintf(OutFile, "|Ru+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuplus1ex2);
	fprintf(OutFile, "|Runeutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuneutrl);
	fprintf(OutFile, "|Runeutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuneutrlex);
	fprintf(OutFile, "|Runeutrlex2            |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRuneutrlex2);
	fprintf(OutFile, "|Rh+8                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus8);
	fprintf(OutFile, "|Rh+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus7);
	fprintf(OutFile, "|Rh+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus6);
	fprintf(OutFile, "|Rh+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus5);
	fprintf(OutFile, "|Rh+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus4);
	fprintf(OutFile, "|Rh+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus3);
	fprintf(OutFile, "|Rh+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus2);
	fprintf(OutFile, "|Rh+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus2ex);
	fprintf(OutFile, "|Rh+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus2ex2);
	fprintf(OutFile, "|Rh+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus1);
	fprintf(OutFile, "|Rh+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus1ex);
	fprintf(OutFile, "|Rh+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhplus1ex2);
	fprintf(OutFile, "|Rhneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhneutrl);
	fprintf(OutFile, "|Rhneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinRhneutrlex);
	fprintf(OutFile, "|Pd+9                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus9);
	fprintf(OutFile, "|Pd+8                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus8);
	fprintf(OutFile, "|Pd+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus7);
	fprintf(OutFile, "|Pd+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus6);
	fprintf(OutFile, "|Pd+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus5);
	fprintf(OutFile, "|Pd+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus4);
	fprintf(OutFile, "|Pd+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus3);
	fprintf(OutFile, "|Pd+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus2);
	fprintf(OutFile, "|Pd+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus2ex);
	fprintf(OutFile, "|Pd+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus2ex2);
	fprintf(OutFile, "|Pd+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus1);
	fprintf(OutFile, "|Pd+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdplus1ex);
	fprintf(OutFile, "|Pd                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdneutrl);
	fprintf(OutFile, "|Pd                     |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinPdneutrlex);
	fprintf(OutFile, "|Ag+10                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus10);
	fprintf(OutFile, "|Ag+9                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus9);
	fprintf(OutFile, "|Ag+8                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus8);
	fprintf(OutFile, "|Ag+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus7);
	fprintf(OutFile, "|Ag+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus6);
	fprintf(OutFile, "|Ag+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus5);
	fprintf(OutFile, "|Ag+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus4);
	fprintf(OutFile, "|Ag+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus3);
	fprintf(OutFile, "|Ag+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus2);
	fprintf(OutFile, "|Ag+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus2ex);
	fprintf(OutFile, "|Ag+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus1);
	fprintf(OutFile, "|Ag+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgplus1ex);
	fprintf(OutFile, "|Agneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgneutrl);
	fprintf(OutFile, "|Agneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinAgneutrlex);
	fprintf(OutFile, "|Cd+11                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus11);
	fprintf(OutFile, "|Cd+10                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus10);
	fprintf(OutFile, "|Cd+9                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus9);
	fprintf(OutFile, "|Cd+8                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus8);
	fprintf(OutFile, "|Cd+7                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus7);
	fprintf(OutFile, "|Cd+6                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus6);
	fprintf(OutFile, "|Cd+5                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus5);
	fprintf(OutFile, "|Cd+4                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus4);
	fprintf(OutFile, "|Cd+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus3);
	fprintf(OutFile, "|Cd+3                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus3ex);
	fprintf(OutFile, "|Cd+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus2);
	fprintf(OutFile, "|Cd+2                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus2ex);
	fprintf(OutFile, "|Cd+1                   |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus1);
	fprintf(OutFile, "|Cd+1*                  |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdplus1ex);
	fprintf(OutFile, "|Cdneutrl               |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdneutrl);
	fprintf(OutFile, "|Cdneutrlex             |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinCdneutrlex);
	



	fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
//	fprintf(OutFile, "| H3O+..H2O Zundel      |   % 7.1f   | OO  % 5.1f | psi % 5.1f | OH  % 5.1f |           |           |           |           |\n", wspinZundel, wspinZundelrOO, wspinZundelPsi, wspinZundelrHcent);
//	fprintf(OutFile, "| OH-..H2O Dept. dimer  |   % 7.1f   | OO  % 5.1f | OH  % 5.1f | dihe% 5.1f |           |           |           |           |\n", wspinDeprotonatedDimer, wspinDeprotonatedDimerrOO, wspinDeprotonatedDimerrOH, wspinDeprotonatedDimerDihedral);
//	fprintf(OutFile, "| H2O..H2O dimer        |   % 7.1f   | OO  % 5.1f | th_D% 5.1f | th_A% 5.1f |           |           |           |           |\n", wspinH4O2, wspinH4O2rOO, wspinH4O2angleD, wspinH4O2angleA);

	fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	fprintf(OutFile, "| H2 transition state   |   % 7.1f   |           |           |           |           |           |           |           |\n", wTransitionspinH2);
	fprintf(OutFile, "| H2 triplet tr. state  |   % 7.1f   |           |           |           |           |           |           |           |\n", wTransitiontripletH2);
	fprintf(OutFile, "| H2^+ tr. state        |   % 7.1f   |           |           |           |           |           |           |           |\n", wTransitionspinH2plus);
	fprintf(OutFile, "| H2^- tr. state        |   % 7.1f   |           |           |           |           |           |           |           |\n", wTransitionspinH2minus);
	fprintf(OutFile, "| OH* tr. state         |   % 7.1f   |           |           |           |           |           |           |           |\n", wTransitionspinOHdot);
	fprintf(OutFile, "| OH* tr. state (2)     |   % 7.1f   |           |           |           |           |           |           |           |\n", wTransitionspinOHdot2);
	fprintf(OutFile, "| OH- tr. state         |   % 7.1f   |           |           |           |           |           |           |           |\n", wTransitionspinOH);
	fprintf(OutFile, "|=========================================================================================================================|\n");
//	fprintf(OutFile, "| (H- & H+) - (H2)      |   % 7.1f   | Proton affinity       |           |           |           |           |           |\n",wspinHaff);
	fprintf(OutFile, "| (H+ & e) - (H)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinHion);
	fprintf(OutFile, "| (H & e) - (H-) > 0    |   % 7.1f   | Electron affinity     |           |           |           |           |           |\n",wspinHeaff);
//	fprintf(OutFile, "| (H&e&e) - (H-trp) > 0 |   % 7.1f   | Electron affinity     |           |           |           |           |           |\n",wspinHeaff_trp);
	fprintf(OutFile, "| (H & H) - (H2)        |   % 7.1f   | Dissociation energy   |           |           |           |           |           |\n",wspinH2dis);
	fprintf(OutFile, "| (H & H) - (H2*)       |   % 7.1f   | Dissociation energy   |           |           |           |           |           |\n",wspinH2exdis);
//	fprintf(OutFile, "| (H & H+) - (H2+)      |   % 7.1f   | Dissociation energy   |           |           |           |           |           |\n",wspinH2plusdis);
	fprintf(OutFile, "| (H2+ & e) - (H2) > 0  |   % 7.1f   | Dissociation energy   |           |           |           |           |           |\n",wspinH2ion);
	fprintf(OutFile, "| (H2 & H+) - (H3+)     |   % 7.1f   | Proton affinity       |           |           |           |           |           |\n",wspinH2aff);
        fprintf(OutFile, "| (H3trig) - (H3linear) |   % 7.1f   | Structural constr.    |           |           |           |           |           |\n",wspinH3lin);
        fprintf(OutFile, "| (H4tetra) - (H4square)|   % 7.1f   | Structural constr.    |           |           |           |           |           |\n",wspinH4squ);
        fprintf(OutFile, "| (H4square) - (H3lin)  |   % 7.1f   | Structural constr.    |           |           |           |           |           |\n",wspinH4lin);
	fprintf(OutFile, "| H sign mismatch       |   % 7.1f   | H3 and H4 fall apart  |           |           |           |           |           |\n", wspinHsign);
	fprintf(OutFile, "| (OH & H+) - (H2O)     |   % 7.1f   | Proton affinity       |           |           |           |           |           |\n",wspinOHaff);
	fprintf(OutFile, "| (H2O & H+) - (H3O+)   |   % 7.1f   | Proton affinity       |           |           |           |           |           |\n",wspinH2Oaff);
	fprintf(OutFile, "| (O-2 & H+) - (OH-)    |   % 7.1f   | Proton affinity       |           |           |           |           |           |\n",wspinO_2aff);
	fprintf(OutFile, "| (OH & H) - (H2O)      |   % 7.1f   | Dissociation energy   |           |           |           |           |           |\n",wspinH2Odis);

	fprintf(OutFile, "| (O-2) - (O+6)         |   % 7.1f   | Electron affinity     |           |           |           |           |           |\n",wspinO_1eaff);
	fprintf(OutFile, "| (O-) - (O+6)          |   % 7.1f   | Electron affinity     |           |           |           |           |           |\n",wspinOeaff);
	fprintf(OutFile, "| (O    ) - (O+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinOneutrlion);
	fprintf(OutFile, "| (O+1  ) - (O+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinOplus1ion);
	fprintf(OutFile, "| (O+2  ) - (O+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinOplus2ion);
	fprintf(OutFile, "| (O+3  ) - (O+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinOplus3ion);
	fprintf(OutFile, "| (O+4  ) - (O+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinOplus4ion);
	fprintf(OutFile, "| (O+5  ) - (O+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinOplus5ion);
	fprintf(OutFile, "| (O  * ) - (O+6)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinOneutrlexion);
	fprintf(OutFile, "| (O  **) - (O  )       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinOneutrlex2ion);
	fprintf(OutFile, "| (O+1* ) - (O+6)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinOplus1ionex);
	fprintf(OutFile, "| (O+1**) - (O+6)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinOplus1ex2ion);
	fprintf(OutFile, "| (O+2 )*- (O+6)        |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinOplus2ionex);
	fprintf(OutFile, "| (O+3 )*- (O+6)        |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinOplus3ionex);
	fprintf(OutFile, "| (O+4 )*- (O+6)        |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinOplus4ionex);
	fprintf(OutFile, "| (O2dia) - (O2para)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinO2ex);
	fprintf(OutFile, "| O sign mismatch       |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinOsign);
	
	fprintf(OutFile, "| (C+3 ) - (C+4)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinCplus3ion);
	fprintf(OutFile, "| (C+2 ) - (C+4)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinCplus2ion);
	fprintf(OutFile, "| (C+1 ) - (C+4)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinCplus1ion);
	fprintf(OutFile, "| (C   ) - (C+4)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinCneutrlion);
	fprintf(OutFile, "| (C-1 ) - (C+4)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinC_1ion);
	fprintf(OutFile, "| (N+4 ) - (N+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinNplus4ion);
	fprintf(OutFile, "| (N+3 ) - (N+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinNplus3ion);
	fprintf(OutFile, "| (N+2 ) - (N+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinNplus2ion);
	fprintf(OutFile, "| (N+1 ) - (N+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinNplus1ion);
	fprintf(OutFile, "| (N   ) - (N+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinNneutrlion);
	fprintf(OutFile, "| (N-1 ) - (N+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinN_1ion);

	fprintf(OutFile, "| (S+5 ) - (S+6)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSplus5ion);
	fprintf(OutFile, "| (S+4 ) - (S+6)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSplus4ion);
	fprintf(OutFile, "| (S+3 ) - (S+6)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSplus3ion);
	fprintf(OutFile, "| (S+2 ) - (S+6)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSplus2ion);
	fprintf(OutFile, "| (S+1 ) - (S+6)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSplus1ion);
	fprintf(OutFile, "| (S   ) - (S+6)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSneutrlion);
	fprintf(OutFile, "| (S-1 ) - (S+6)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinS_1ion);

	fprintf(OutFile, "| (P+4 ) - (P+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinPplus4ion);
	fprintf(OutFile, "| (P+3 ) - (P+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinPplus3ion);
	fprintf(OutFile, "| (P+2 ) - (P+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinPplus2ion);
	fprintf(OutFile, "| (P+1 ) - (P+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinPplus1ion);
	fprintf(OutFile, "| (P   ) - (P+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinPneutrlion);
	fprintf(OutFile, "| (P-1 ) - (P+5)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinP_1ion);

	fprintf(OutFile, "| (Si+3) - (Si+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSiplus3ion);
	fprintf(OutFile, "| (Si+2) - (Si+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSiplus2ion);
	fprintf(OutFile, "| (Si+1) - (Si+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSiplus1ion);
	fprintf(OutFile, "| (Si  ) - (Si+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSineutrlion);
	fprintf(OutFile, "| (Si-1) - (Si+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinSi_1ion);

	fprintf(OutFile, "| (F+6 ) - (F+7)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinFplus6ion);
	fprintf(OutFile, "| (F+5 ) - (F+7)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinFplus5ion);
	fprintf(OutFile, "| (F+4 ) - (F+7)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinFplus4ion);
	fprintf(OutFile, "| (F+3 ) - (F+7)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinFplus3ion);
	fprintf(OutFile, "| (F+2 ) - (F+7)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinFplus2ion);
	fprintf(OutFile, "| (F+1 ) - (F+7)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinFplus1ion);
	fprintf(OutFile, "| (F   ) - (F+7)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinFneutrlion);
	fprintf(OutFile, "| (F-1 ) - (F+7)        |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinF_1ion);

	fprintf(OutFile, "| (C+2* ) - (C+2)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinCplus2exion);
	fprintf(OutFile, "| (C+1* ) - (C+1)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinCplus1exion);
	fprintf(OutFile, "| (C  * ) - (C  )       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinCneutrlexion);
	fprintf(OutFile, "| (C ** ) - (C  )       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinCneutrlex2ion);
        fprintf(OutFile, "| (C2para) - (C2dia)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinC2ex);
	fprintf(OutFile, "| C sign mismatch       |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinCsign);

	fprintf(OutFile, "| (N+3* ) - (N+3)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinNplus3exion);
	fprintf(OutFile, "| (N+2* ) - (N+2)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinNplus2exion);
	fprintf(OutFile, "| (N+1* ) - (N+1)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinNplus1exion);
	fprintf(OutFile, "| (N+1**) - (N+1)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinNplus1ex2ion);
	fprintf(OutFile, "| (N  * ) - (N  )       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinNneutrlexion);
	fprintf(OutFile, "| (N  **) - (N  )       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinNneutrlex2ion);
        fprintf(OutFile, "| (N2para) - (N2dia)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinN2ex);
	fprintf(OutFile, "| N sign mismatch       |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinNsign);

	fprintf(OutFile, "| (F+5* ) - (F+5)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinFplus5exion);
	fprintf(OutFile, "| (F+4* ) - (F+4)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinFplus4exion);
	fprintf(OutFile, "| (F+3* ) - (F+3)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinFplus3exion);
	fprintf(OutFile, "| (F+3**) - (F+3)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinFplus3ex2ion);
	fprintf(OutFile, "| (F+2* ) - (F+2)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinFplus2exion);

	fprintf(OutFile, "| (F+2**) - (F+2)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinFplus2ex2ion);
	fprintf(OutFile, "| (F+1* ) - (F+1)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinFplus1exion);
	fprintf(OutFile, "| (F+1**) - (F+1)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinFplus1ex2ion);
	fprintf(OutFile, "| (F  * ) - (F  )       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinFneutrlexion);
        fprintf(OutFile, "| (F2para) - (F2dia)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinF2ex);
	fprintf(OutFile, "| F sign mismatch       |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinFsign);

	fprintf(OutFile, "| (Si+2* ) - (Si+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSiplus2exion);
	fprintf(OutFile, "| (Si+1* ) - (Si+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSiplus1exion);
	fprintf(OutFile, "| (Si  * ) - (Si  )     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSineutrlexion);
	fprintf(OutFile, "| (Si ** ) - (Si  )     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSineutrlex2ion);
        fprintf(OutFile, "| (Si2dia) - (Si2para)  |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSi2ex);
	fprintf(OutFile, "| Si sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinSisign);

	fprintf(OutFile, "| (P+3* ) - (P+3)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinPplus3exion);
	fprintf(OutFile, "| (P+2* ) - (P+2)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinPplus2exion);
	fprintf(OutFile, "| (P+1* ) - (P+2)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinPplus1exion);
	fprintf(OutFile, "| (P+1**) - (P+1)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinPplus1ex2ion);
	fprintf(OutFile, "| (P  * ) - (P  )       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinPneutrlexion);
        fprintf(OutFile, "| (P2para) - (P2dia)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinP2ex);
	fprintf(OutFile, "| P sign mismatch       |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinPsign);

	fprintf(OutFile, "| (S+4* ) - (S+4)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSplus4exion);
	fprintf(OutFile, "| (S+3* ) - (S+3)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSplus3exion);
	fprintf(OutFile, "| (S+2* ) - (S+2)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSplus2exion);
	fprintf(OutFile, "| (S+2**) - (S+2)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSplus2ex2ion);
	fprintf(OutFile, "| (S+1* ) - (S+1)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSplus1exion);
	fprintf(OutFile, "| (S  * ) - (S  )       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSneutrlexion);
	fprintf(OutFile, "| (S  **) - (S  )       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinSneutrlex2ion);
        fprintf(OutFile, "| (S2dia) - (S2para)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinS2ex);
	fprintf(OutFile, "| S sign mismatch       |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinSsign);

	fprintf(OutFile, "| (Bo-1  ) - (Bo  )     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinB_1ion);
	fprintf(OutFile, "| (Bo  * ) - (Bo  )     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinBneutrlexion);
	fprintf(OutFile, "| (Bo    ) - (Bo+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinBneutrlion);
	fprintf(OutFile, "| (Bo+1* ) - (Bo+1)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinBplus1exion);
	fprintf(OutFile, "| (Bo+1  ) - (Bo+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinBplus1ion);
	fprintf(OutFile, "| (Bo+2  ) - (Bo+3)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinBplus2ion);
        fprintf(OutFile, "| (Bo2dia) - (Bo2para)  |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinAl2ex);
	fprintf(OutFile, "| Bo sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinBsign);

	fprintf(OutFile, "| (Cl-1  ) - (Cl  )     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinCl_1ion);
	fprintf(OutFile, "| (Cl  * ) - (Cl  )     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinClneutrlexion);
	fprintf(OutFile, "| (Cl    ) - (Cl+1)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinClneutrlion);
	fprintf(OutFile, "| (Cl+1**) - (Cl+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinClplus1ex2ion);
	fprintf(OutFile, "| (Cl+1* ) - (Cl+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinClplus1exion);
	fprintf(OutFile, "| (Cl+1  ) - (Cl+2)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinClplus1ion);
	fprintf(OutFile, "| (Cl+2* ) - (Cl+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinClplus2exion);
	fprintf(OutFile, "| (Cl+2  ) - (Cl+3)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinClplus2ion);
	fprintf(OutFile, "| (Cl+3**) - (Cl+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinClplus3ex2ion);
	fprintf(OutFile, "| (Cl+3* ) - (Cl+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinClplus3exion);
	fprintf(OutFile, "| (Cl+3  ) - (Cl+4)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinClplus3ion);
	fprintf(OutFile, "| (Cl+4* ) - (Cl+4)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinClplus4exion);
	fprintf(OutFile, "| (Cl+4  ) - (Cl+5)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinClplus4ion);
	fprintf(OutFile, "| (Cl+5* ) - (Cl+5)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinClplus5exion);
	fprintf(OutFile, "| (Cl+5  ) - (Cl+6)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinClplus5ion);
	fprintf(OutFile, "| (Cl+6  ) - (Cl+7)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinClplus6ion);
        fprintf(OutFile, "| (Cl2para) - (Cl2dia)  |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinCl2ex);
	fprintf(OutFile, "| Cl sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinClsign);

	fprintf(OutFile, "| (Al-1  ) - (Al  )     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinAl_1ion);
	fprintf(OutFile, "| (Al  * ) - (Al  )     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinAlneutrlexion);
	fprintf(OutFile, "| (Al    ) - (Al+1)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinAlneutrlion);
	fprintf(OutFile, "| (Al+ * ) - (Al+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinAlplus1exion);
	fprintf(OutFile, "| (Al+   ) - (Al+2)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinAlplus1ion);
	fprintf(OutFile, "| (Al+2  ) - (Al+3)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinAlplus2ion);
	fprintf(OutFile, "| (Al2dia) - (Al2para)  |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinAl2ex);
	fprintf(OutFile, "| Al sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinAlsign);

	fprintf(OutFile, "| (Li-   ) - (Li  )     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinLi_1ion);
	fprintf(OutFile, "| (Li    ) - (Li+ )     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinLineutrlion);
	fprintf(OutFile, "| (Be    ) - (Be+ )     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinBeneutrlion);
	fprintf(OutFile, "| (Be  * ) - (Be  )     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinBeneutrlexion);
	fprintf(OutFile, "| (Be+   ) - (Be+2)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinBeplus1ion);
	fprintf(OutFile, "| (Na-   ) - (Na  )     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinNa_1ion);
	fprintf(OutFile, "| (Na    ) - (Na+ )     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinNaneutrlion);
	fprintf(OutFile, "| (Mg    ) - (Mg+ )     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinMgneutrlion);
	fprintf(OutFile, "| (Mg  * ) - (Mg  )     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n",wspinMgneutrlexion);
	fprintf(OutFile, "| (Mg+   ) - (Mg+2)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n",wspinMgplus1ion);

	fprintf(OutFile, "| (O- & O-) - (O2-2)    |   % 7.1f   | Dissociation energy   |           |           |           |           |           |\n",wspinO2_2dis);
	fprintf(OutFile, "| (O- & O) - (O2-)      |   % 7.1f   | Dissociation energy   |           |           |           |           |           |\n",wspinO2_1dis);
	fprintf(OutFile, "| (O & O) - (O2)        |   % 7.1f   | Dissociation energy   |           |           |           |           |           |\n",wspinO2dis);
	fprintf(OutFile, "| (OH* & H+) - (H2O+)   |   % 7.1f   | Proton affinity       |           |           |           |           |           |\n",wspinOHdotaff);

//	fprintf(OutFile, "| (O- & H+) - (OH*)     |   % 7.1f   | Proton affinity       |           |           |           |           |           |\n",wspinO_1aff);
	fprintf(OutFile, "| (O- & H+) - (OH*)     |   % 7.1f   | Proton affinity       |           |           |           |           |           |\n",wspinO_1aff);
	fprintf(OutFile, "| (O & H )  - (OH*)     |   % 7.1f   | Dissociation energy   |           |           |           |           |           |\n",wspinOHdotdis);
	fprintf(OutFile, "| (H2O..H2O) - (H2O)*2  |   % 7.1f   | Dimerization enthalpy |           |           |           |           |           |\n",wspinH2Odim);

	fprintf(OutFile, "| (Sc+3) - (Sc+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinScplus2ion);
	fprintf(OutFile, "| (Sc+2) - (Sc+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinScplus1ion);
	fprintf(OutFile, "| (Sc+1ex) - (Sc+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinScplus1exion);
	fprintf(OutFile, "| (Sc+1) - (Sc+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinScneutrlion);
	fprintf(OutFile, "| (Sc+0ex) - (Sc+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinScneutrlexion);
	fprintf(OutFile, "| Sc sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinScsign);

	fprintf(OutFile, "| (Ti+4) - (Ti+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTiplus3ion);
	fprintf(OutFile, "| (Ti+3) - (Ti+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTiplus2ion);
	fprintf(OutFile, "| (Ti+2ex) - (Ti+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinTiplus2exion);
	fprintf(OutFile, "| (Ti+2) - (Ti+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTiplus1ion);
	fprintf(OutFile, "| (Ti+1ex) - (Ti+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinTiplus1exion);
	fprintf(OutFile, "| (Ti+1) - (Ti+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTineutrlion);
	fprintf(OutFile, "| (Ti+0ex) - (Ti+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinTineutrlexion);
	fprintf(OutFile, "| (Ti+0ex2) - (Ti+0)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinTineutrlex2ion);
	fprintf(OutFile, "| Ti sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinTisign);

	fprintf(OutFile, "| (V+5) - (V+4)         |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinVplus4ion);
	fprintf(OutFile, "| (V+4) - (V+3)         |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinVplus3ion);
	fprintf(OutFile, "| (V+3ex) - (V+3)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinVplus3exion);
	fprintf(OutFile, "| (V+3) - (V+2)         |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinVplus2ion);
	fprintf(OutFile, "| (V+2ex) - (V+2)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinVplus2exion);
	fprintf(OutFile, "| (V+2) - (V+1)         |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinVplus1ion);
	fprintf(OutFile, "| (V+1ex) - (V+1)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinVplus1exion);
	fprintf(OutFile, "| (V+1ex2) - (V+1)      |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinVplus1ex2ion);
	fprintf(OutFile, "| (V+1) - (V+0)         |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinVneutrlion);
	fprintf(OutFile, "| (V+0ex) - (V+0)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinVneutrlexion);
	fprintf(OutFile, "| (V+0ex2) - (V+0)      |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinVneutrlex2ion);
	fprintf(OutFile, "| V  sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinVsign);

	fprintf(OutFile, "| (Cr+6) - (Cr+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCrplus5ion);
	fprintf(OutFile, "| (Cr+5) - (Cr+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCrplus4ion);
	fprintf(OutFile, "| (Cr+4ex) - (Cr+4)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCrplus4exion);
	fprintf(OutFile, "| (Cr+4) - (Cr+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCrplus3ion);
	fprintf(OutFile, "| (Cr+3ex) - (Cr+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCrplus3exion);
	fprintf(OutFile, "| (Cr+3) - (Cr+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCrplus2ion);
	fprintf(OutFile, "| (Cr+2ex) - (Cr+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCrplus2exion);
	fprintf(OutFile, "| (Cr+2ex2) - (Cr+2)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCrplus2ex2ion);
	fprintf(OutFile, "| (Cr+2) - (Cr+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCrplus1ion);
	fprintf(OutFile, "| (Cr+1ex) - (Cr+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCrplus1exion);
	fprintf(OutFile, "| (Cr+1ex2) - (Cr+1)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCrplus1ex2ion);
	fprintf(OutFile, "| (Cr+1) - (Cr+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCrneutrlion);
	fprintf(OutFile, "| (Cr+0ex) - (Cr+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCrneutrlexion);
	fprintf(OutFile, "| (Cr+0ex2) - (Cr+0)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCrneutrlex2ion);
	fprintf(OutFile, "| (Cr+0) - (Cr+0)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCrneutrlex3ion);
	fprintf(OutFile, "| Cr sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinCrsign);

	fprintf(OutFile, "| (Mn+7) - (Mn+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMnplus6ion);
	fprintf(OutFile, "| (Mn+6) - (Mn+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMnplus5ion);
	fprintf(OutFile, "| (Mn+5ex) - (Mn+5)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnplus5exion);
	fprintf(OutFile, "| (Mn+5) - (Mn+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMnplus4ion);
	fprintf(OutFile, "| (Mn+4ex) - (Mn+4)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnplus4exion);
	fprintf(OutFile, "| (Mn+4) - (Mn+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMnplus3ion);
	fprintf(OutFile, "| (Mn+3ex) - (Mn+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnplus3exion);
	fprintf(OutFile, "| (Mn+3) - (Mn+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMnplus2ion);
	fprintf(OutFile, "| (Mn+2ex) - (Mn+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnplus2exion);
	fprintf(OutFile, "| (Mn+2ex2) - (Mn+2)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnplus2ex2ion);
	fprintf(OutFile, "| (Mn+2) - (Mn+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMnplus1ion);
	fprintf(OutFile, "| (Mn+1ex) - (Mn+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnplus1exion);
	fprintf(OutFile, "| (Mn+1ex2) - (Mn+1)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnplus1ex2ion);
	fprintf(OutFile, "| (Mn+1) - (Mn+1)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnplus1ex3ion);
	fprintf(OutFile, "| (Mn+1) - (Mn+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMnneutrlion);
	fprintf(OutFile, "| (Mn+0ex) - (Mn+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnneutrlexion);
	fprintf(OutFile, "| (Mn+0ex2) - (Mn+0)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnneutrlex2ion);
	fprintf(OutFile, "| (Mn+0) - (Mn+0)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMnneutrlex3ion);
	fprintf(OutFile, "| Mn sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinMnsign);

	fprintf(OutFile, "| (Fe+8) - (Fe+7)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinFeplus7ion);
	fprintf(OutFile, "| (Fe+7) - (Fe+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinFeplus6ion);
	fprintf(OutFile, "| (Fe+6ex) - (Fe+6)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeplus6exion);
	fprintf(OutFile, "| (Fe+6) - (Fe+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinFeplus5ion);
	fprintf(OutFile, "| (Fe+5ex) - (Fe+5)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeplus5exion);
	fprintf(OutFile, "| (Fe+5) - (Fe+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinFeplus4ion);
	fprintf(OutFile, "| (Fe+4ex) - (Fe+4)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeplus4exion);
	fprintf(OutFile, "| (Fe+4ex2) - (Fe+4)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeplus4ex2ion);
	fprintf(OutFile, "| (Fe+4) - (Fe+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinFeplus3ion);
	fprintf(OutFile, "| (Fe+3ex) - (Fe+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeplus3exion);
	fprintf(OutFile, "| (Fe+3ex2) - (Fe+3)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeplus3ex2ion);
	fprintf(OutFile, "| (Fe+3) - (Fe+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinFeplus2ion);
	fprintf(OutFile, "| (Fe+2ex) - (Fe+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeplus2exion);
	fprintf(OutFile, "| (Fe+2ex2) - (Fe+2)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeplus2ex2ion);
	fprintf(OutFile, "| (Fe+2) - (Fe+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinFeplus1ion);
	fprintf(OutFile, "| (Fe+1ex) - (Fe+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeplus1exion);
	fprintf(OutFile, "| (Fe+1ex2) - (Fe+1)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeplus1ex2ion);
	fprintf(OutFile, "| (Fe+1) - (Fe+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinFeneutrlion);
	fprintf(OutFile, "| (Fe+0ex) - (Fe+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeneutrlexion);
	fprintf(OutFile, "| (Fe+0ex2) - (Fe+0)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeneutrlex2ion);
	fprintf(OutFile, "| (Fe+0) - (Fe+0)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinFeneutrlex3ion);
	fprintf(OutFile, "| Fe sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinFesign);

	fprintf(OutFile, "| (Co+9) - (Co+8)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCoplus8ion);
	fprintf(OutFile, "| (Co+8) - (Co+7)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCoplus7ion);
	fprintf(OutFile, "| (Co+7ex) - (Co+7)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus7exion);
	fprintf(OutFile, "| (Co+7) - (Co+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCoplus6ion);
	fprintf(OutFile, "| (Co+6ex) - (Co+6)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus6exion);
	fprintf(OutFile, "| (Co+6) - (Co+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCoplus5ion);
	fprintf(OutFile, "| (Co+5ex) - (Co+5)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus5exion);
	fprintf(OutFile, "| (Co+5ex2) - (Co+5)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus5ex2ion);
	fprintf(OutFile, "| (Co+5) - (Co+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCoplus4ion);
	fprintf(OutFile, "| (Co+4ex) - (Co+4)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus4exion);
	fprintf(OutFile, "| (Co+4ex2) - (Co+4)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus4ex2ion);
	fprintf(OutFile, "| (Co+4) - (Co+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCoplus3ion);
	fprintf(OutFile, "| (Co+3ex) - (Co+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus3exion);
	fprintf(OutFile, "| (Co+3ex2) - (Co+3)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus3ex2ion);
	fprintf(OutFile, "| (Co+3) - (Co+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCoplus2ion);
	fprintf(OutFile, "| (Co+2ex) - (Co+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus2exion);
	fprintf(OutFile, "| (Co+2ex2) - (Co+2)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus2ex2ion);
	fprintf(OutFile, "| (Co+2) - (Co+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCoplus1ion);
	fprintf(OutFile, "| (Co+1ex) - (Co+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus1exion);
	fprintf(OutFile, "| (Co+1ex2) - (Co+1)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCoplus1ex2ion);
	fprintf(OutFile, "| (Co+1) - (Co+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinConeutrlion);
	fprintf(OutFile, "| (Co+0ex) - (Co+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinConeutrlexion);
	fprintf(OutFile, "| Co sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinCosign);

	fprintf(OutFile, "| (Ni+10) - (Ni+9)      |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNiplus9ion);
	fprintf(OutFile, "| (Ni+9) - (Ni+8)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNiplus8ion);
	fprintf(OutFile, "| (Ni+8ex) - (Ni+8)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus8exion);
	fprintf(OutFile, "| (Ni+8) - (Ni+7)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNiplus7ion);
	fprintf(OutFile, "| (Ni+7ex) - (Ni+7)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus7exion);
	fprintf(OutFile, "| (Ni+7) - (Ni+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNiplus6ion);
	fprintf(OutFile, "| (Ni+6ex) - (Ni+6)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus6exion);
	fprintf(OutFile, "| (Ni+6) - (Ni+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNiplus5ion);
	fprintf(OutFile, "| (Ni+5ex) - (Ni+5)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus5exion);
	fprintf(OutFile, "| (Ni+5ex2) - (Ni+5)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus5ex2ion);
	fprintf(OutFile, "| (Ni+5) - (Ni+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNiplus4ion);
	fprintf(OutFile, "| (Ni+4ex) - (Ni+4)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus4exion);
	fprintf(OutFile, "| (Ni+4ex2) - (Ni+4)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus4ex2ion);
	fprintf(OutFile, "| (Ni+4) - (Ni+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNiplus3ion);
	fprintf(OutFile, "| (Ni+3ex) - (Ni+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus3exion);
	fprintf(OutFile, "| (Ni+3ex2) - (Ni+3)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus3ex2ion);
	fprintf(OutFile, "| (Ni+3) - (Ni+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNiplus2ion);
	fprintf(OutFile, "| (Ni+2ex) - (Ni+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus2exion);
	fprintf(OutFile, "| (Ni+2ex2) - (Ni+2)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus2ex2ion);
	fprintf(OutFile, "| (Ni+2) - (Ni+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNiplus1ion);
	fprintf(OutFile, "| (Ni+1ex) - (Ni+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNiplus1exion);
	fprintf(OutFile, "| (Ni+1) - (Ni+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNineutrlion);
	fprintf(OutFile, "| (Ni+0ex) - (Ni+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNineutrlexion);
	fprintf(OutFile, "| Ni sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinNisign);

	fprintf(OutFile, "| (Cu+11) - (Cu+10)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuplus10ion);
	fprintf(OutFile, "| (Cu+10) - (Cu+9)      |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuplus9ion);
	fprintf(OutFile, "| (Cu+9ex) - (Cu+9)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCuplus9exion);
	fprintf(OutFile, "| (Cu+9) - (Cu+8)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuplus8ion);
	fprintf(OutFile, "| (Cu+8) - (Cu+7)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuplus7ion);
	fprintf(OutFile, "| (Cu+7) - (Cu+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuplus6ion);
	fprintf(OutFile, "| (Cu+6) - (Cu+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuplus5ion);
	fprintf(OutFile, "| (Cu+5ex) - (Cu+5)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCuplus5exion);
	fprintf(OutFile, "| (Cu+5ex2) - (Cu+5)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCuplus5ex2ion);
	fprintf(OutFile, "| (Cu+5) - (Cu+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuplus4ion);
	fprintf(OutFile, "| (Cu+4ex) - (Cu+4)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCuplus4exion);
	fprintf(OutFile, "| (Cu+4ex2) - (Cu+4)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCuplus4ex2ion);
	fprintf(OutFile, "| (Cu+4) - (Cu+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuplus3ion);
	fprintf(OutFile, "| (Cu+3ex) - (Cu+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCuplus3exion);
	fprintf(OutFile, "| (Cu+3ex2) - (Cu+3)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCuplus3ex2ion);
	fprintf(OutFile, "| (Cu+3) - (Cu+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuplus2ion);
	fprintf(OutFile, "| (Cu+2ex) - (Cu+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCuplus2exion);
	fprintf(OutFile, "| (Cu+2) - (Cu+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuplus1ion);
	fprintf(OutFile, "| (Cu+1ex) - (Cu+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCuplus1exion);
	fprintf(OutFile, "| (Cu+1) - (Cu+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCuneutrlion);
	fprintf(OutFile, "| (Cu+0ex) - (Cu+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCuneutrlexion);
	fprintf(OutFile, "| Cu sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinCusign);

	fprintf(OutFile, "| (Zn+12) - (Zn+11)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus11ion);
	fprintf(OutFile, "| (Zn+11) - (Zn+10)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus10ion);
	fprintf(OutFile, "| (Zn+10ex) - (Zn+10)   |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnplus10exion);
	fprintf(OutFile, "| (Zn+10) - (Zn+9)      |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus9ion);
	fprintf(OutFile, "| (Zn+9) - (Zn+8)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus8ion);
	fprintf(OutFile, "| (Zn+8) - (Zn+7)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus7ion);
	fprintf(OutFile, "| (Zn+7) - (Zn+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus6ion);
	fprintf(OutFile, "| (Zn+6ex) - (Zn+6)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnplus6exion);
	fprintf(OutFile, "| (Zn+6ex2) - (Zn+6)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnplus6ex2ion);
	fprintf(OutFile, "| (Zn+6) - (Zn+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus5ion);
	fprintf(OutFile, "| (Zn+5ex) - (Zn+5)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnplus5exion);
	fprintf(OutFile, "| (Zn+5ex2) - (Zn+5)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnplus5ex2ion);
	fprintf(OutFile, "| (Zn+5) - (Zn+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus4ion);
	fprintf(OutFile, "| (Zn+4ex) - (Zn+4)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnplus4exion);
	fprintf(OutFile, "| (Zn+4ex2) - (Zn+4)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnplus4ex2ion);
	fprintf(OutFile, "| (Zn+4) - (Zn+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus3ion);
	fprintf(OutFile, "| (Zn+3ex) - (Zn+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnplus3exion);
	fprintf(OutFile, "| (Zn+3) - (Zn+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus2ion);
	fprintf(OutFile, "| (Zn+2ex) - (Zn+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnplus2exion);
	fprintf(OutFile, "| (Zn+2) - (Zn+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnplus1ion);
	fprintf(OutFile, "| (Zn+1ex) - (Zn+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnplus1exion);
	fprintf(OutFile, "| (Zn+1) - (Zn+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZnneutrlion);
	fprintf(OutFile, "| (Zn+0ex) - (Zn+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZnneutrlexion);
	fprintf(OutFile, "| Zn sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinZnsign);

	fprintf(OutFile, "| (Y+3) - (Y+2)         |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinYplus2ion);
	fprintf(OutFile, "| (Y+2) - (Y+1)         |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinYplus1ion);
	fprintf(OutFile, "| (Y+1ex) - (Y+1)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinYplus1exion);
	fprintf(OutFile, "| (Y+1) - (Y+0)         |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinYneutrlion);
	fprintf(OutFile, "| (Y+0ex) - (Y+0)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinYneutrlexion);
	fprintf(OutFile, "| Y  sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinYsign);

	fprintf(OutFile, "| (Zr+4) - (Zr+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZrplus3ion);
	fprintf(OutFile, "| (Zr+3) - (Zr+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZrplus2ion);
	fprintf(OutFile, "| (Zr+2ex) - (Zr+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZrplus2exion);
	fprintf(OutFile, "| (Zr+2) - (Zr+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZrplus1ion);
	fprintf(OutFile, "| (Zr+1ex) - (Zr+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZrplus1exion);
	fprintf(OutFile, "| (Zr+1) - (Zr+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinZrneutrlion);
	fprintf(OutFile, "| (Zr+0ex) - (Zr+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZrneutrlexion);
	fprintf(OutFile, "| (Zr+0ex2) - (Zr+0)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinZrneutrlex2ion);
	fprintf(OutFile, "| Zr sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinZrsign);

	fprintf(OutFile, "| (Nb+5) - (Nb+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNbplus4ion);
	fprintf(OutFile, "| (Nb+4) - (Nb+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNbplus3ion);
	fprintf(OutFile, "| (Nb+3ex) - (Nb+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNbplus3exion);
	fprintf(OutFile, "| (Nb+3) - (Nb+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNbplus2ion);
	fprintf(OutFile, "| (Nb+2ex) - (Nb+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNbplus2exion);
	fprintf(OutFile, "| (Nb+2) - (Nb+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNbplus1ion);
	fprintf(OutFile, "| (Nb+1ex) - (Nb+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNbplus1exion);
	fprintf(OutFile, "| (Nb+1ex2) - (Nb+1)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNbplus1ex2ion);
	fprintf(OutFile, "| (Nb+1) - (Nb+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinNbneutrlion);
	fprintf(OutFile, "| (Nb+0ex) - (Nb+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNbneutrlexion);
	fprintf(OutFile, "| (Nb+0ex2) - (Nb+0)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinNbneutrlex2ion);
	fprintf(OutFile, "| Nb sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinNbsign);

	fprintf(OutFile, "| (Mo+6) - (Mo+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMoplus5ion);
	fprintf(OutFile, "| (Mo+5) - (Mo+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMoplus4ion);
	fprintf(OutFile, "| (Mo+4ex) - (Mo+4)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMoplus4exion);
	fprintf(OutFile, "| (Mo+4) - (Mo+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMoplus3ion);
	fprintf(OutFile, "| (Mo+3ex) - (Mo+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMoplus3exion);
	fprintf(OutFile, "| (Mo+3) - (Mo+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMoplus2ion);
	fprintf(OutFile, "| (Mo+2ex) - (Mo+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMoplus2exion);
	fprintf(OutFile, "| (Mo+2ex2) - (Mo+2)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMoplus2ex2ion);
	fprintf(OutFile, "| (Mo+2) - (Mo+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMoplus1ion);
	fprintf(OutFile, "| (Mo+1ex) - (Mo+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMoplus1exion);
	fprintf(OutFile, "| (Mo+1ex2) - (Mo+1)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMoplus1ex2ion);
	fprintf(OutFile, "| (Mo+1) - (Mo+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinMoneutrlion);
	fprintf(OutFile, "| (Mo+0ex) - (Mo+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMoneutrlexion);
	fprintf(OutFile, "| (Mo+0ex2) - (Mo+0)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMoneutrlex2ion);
	fprintf(OutFile, "| (Mo+0) - (Mo+0)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinMoneutrlex3ion);
	fprintf(OutFile, "| Mo sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinMosign);

	fprintf(OutFile, "| (Tc+7) - (Tc+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTcplus6ion);
	fprintf(OutFile, "| (Tc+6) - (Tc+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTcplus5ion);
	fprintf(OutFile, "| (Tc+5) - (Tc+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTcplus4ion);
	fprintf(OutFile, "| (Tc+4) - (Tc+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTcplus3ion);
	fprintf(OutFile, "| (Tc+3) - (Tc+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTcplus2ion);
	fprintf(OutFile, "| (Tc+2) - (Tc+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTcplus1ion);
	fprintf(OutFile, "| (Tc+1ex) - (Tc+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinTcplus1exion);
	fprintf(OutFile, "| (Tc+1) - (Tc+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinTcneutrlion);
	fprintf(OutFile, "| (Tc+0ex) - (Tc+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinTcneutrlexion);
	fprintf(OutFile, "| (Tc+0ex2) - (Tc+0)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinTcneutrlex2ion);
	fprintf(OutFile, "| (Tc+0) - (Tc+0)       |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinTcneutrlex3ion);
	fprintf(OutFile, "| Tc sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinTcsign);

	fprintf(OutFile, "| (Ru+8) - (Ru+7)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRuplus7ion);
	fprintf(OutFile, "| (Ru+7) - (Ru+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRuplus6ion);
	fprintf(OutFile, "| (Ru+6) - (Ru+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRuplus5ion);
	fprintf(OutFile, "| (Ru+5) - (Ru+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRuplus4ion);
	fprintf(OutFile, "| (Ru+4) - (Ru+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRuplus3ion);
	fprintf(OutFile, "| (Ru+3) - (Ru+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRuplus2ion);
	fprintf(OutFile, "| (Ru+2ex) - (Ru+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinRuplus2exion);
	fprintf(OutFile, "| (Ru+2) - (Ru+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRuplus1ion);
	fprintf(OutFile, "| (Ru+1ex) - (Ru+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinRuplus1exion);
	fprintf(OutFile, "| (Ru+1ex2) - (Ru+1)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinRuplus1ex2ion);
	fprintf(OutFile, "| (Ru+1) - (Ru+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRuneutrlion);
	fprintf(OutFile, "| (Ru+0ex) - (Ru+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinRuneutrlexion);
	fprintf(OutFile, "| (Ru+0ex2) - (Ru+0)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinRuneutrlex2ion);
	fprintf(OutFile, "| Ru sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinRusign);

	fprintf(OutFile, "| (Rh+9) - (Rh+8)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRhplus8ion);
	fprintf(OutFile, "| (Rh+8) - (Rh+7)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRhplus7ion);
	fprintf(OutFile, "| (Rh+7) - (Rh+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRhplus6ion);
	fprintf(OutFile, "| (Rh+6) - (Rh+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRhplus5ion);
	fprintf(OutFile, "| (Rh+5) - (Rh+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRhplus4ion);
	fprintf(OutFile, "| (Rh+4) - (Rh+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRhplus3ion);
	fprintf(OutFile, "| (Rh+3) - (Rh+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRhplus2ion);
	fprintf(OutFile, "| (Rh+2ex) - (Rh+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinRhplus2exion);
	fprintf(OutFile, "| (Rh+2ex2) - (Rh+2)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinRhplus2ex2ion);
	fprintf(OutFile, "| (Rh+2) - (Rh+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRhplus1ion);
	fprintf(OutFile, "| (Rh+1ex) - (Rh+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinRhplus1exion);
	fprintf(OutFile, "| (Rh+1ex2) - (Rh+1)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinRhplus1ex2ion);
	fprintf(OutFile, "| (Rh+1) - (Rh+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinRhneutrlion);
	fprintf(OutFile, "| (Rh+0ex) - (Rh+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinRhneutrlexion);
	fprintf(OutFile, "| Rh sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinRhsign);

	fprintf(OutFile, "| (Pd+10) - (Pd+9)      |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinPdplus9ion);
	fprintf(OutFile, "| (Pd+9) - (Pd+8)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinPdplus8ion);
	fprintf(OutFile, "| (Pd+8) - (Pd+7)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinPdplus7ion);
	fprintf(OutFile, "| (Pd+7) - (Pd+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinPdplus6ion);
	fprintf(OutFile, "| (Pd+6) - (Pd+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinPdplus5ion);
	fprintf(OutFile, "| (Pd+5) - (Pd+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinPdplus4ion);
	fprintf(OutFile, "| (Pd+4) - (Pd+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinPdplus3ion);
	fprintf(OutFile, "| (Pd+3) - (Pd+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinPdplus2ion);
	fprintf(OutFile, "| (Pd+2ex) - (Pd+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinPdplus2exion);
	fprintf(OutFile, "| (Pd+2ex2) - (Pd+2)    |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinPdplus2ex2ion);
	fprintf(OutFile, "| (Pd+2) - (Pd+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinPdplus1ion);
	fprintf(OutFile, "| (Pd+1ex) - (Pd+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinPdplus1exion);
	fprintf(OutFile, "| (Pd+1) - (Pd+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinPdneutrlion);
	fprintf(OutFile, "| (Pd+0ex) - (Pd+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinPdneutrlexion);
	fprintf(OutFile, "| Pd sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinPdsign);

	fprintf(OutFile, "| (Ag+11) - (Ag+10)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgplus10ion);
	fprintf(OutFile, "| (Ag+10) - (Ag+9)      |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgplus9ion);
	fprintf(OutFile, "| (Ag+9) - (Ag+8)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgplus8ion);
	fprintf(OutFile, "| (Ag+8) - (Ag+7)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgplus7ion);
	fprintf(OutFile, "| (Ag+7) - (Ag+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgplus6ion);
	fprintf(OutFile, "| (Ag+6) - (Ag+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgplus5ion);
	fprintf(OutFile, "| (Ag+5) - (Ag+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgplus4ion);
	fprintf(OutFile, "| (Ag+4) - (Ag+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgplus3ion);
	fprintf(OutFile, "| (Ag+3) - (Ag+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgplus2ion);
	fprintf(OutFile, "| (Ag+2ex) - (Ag+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinAgplus2exion);
	fprintf(OutFile, "| (Ag+2) - (Ag+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgplus1ion);
	fprintf(OutFile, "| (Ag+1ex) - (Ag+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinAgplus1exion);
	fprintf(OutFile, "| (Ag+1) - (Ag+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinAgneutrlion);
	fprintf(OutFile, "| (Ag+0ex) - (Ag+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinAgneutrlexion);
	fprintf(OutFile, "| Ag sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinAgsign);

	fprintf(OutFile, "| (Cd+12) - (Cd+11)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus11ion);
	fprintf(OutFile, "| (Cd+11) - (Cd+10)     |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus10ion);
	fprintf(OutFile, "| (Cd+10) - (Cd+9)      |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus9ion);
	fprintf(OutFile, "| (Cd+9) - (Cd+8)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus8ion);
	fprintf(OutFile, "| (Cd+8) - (Cd+7)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus7ion);
	fprintf(OutFile, "| (Cd+7) - (Cd+6)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus6ion);
	fprintf(OutFile, "| (Cd+6) - (Cd+5)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus5ion);
	fprintf(OutFile, "| (Cd+5) - (Cd+4)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus4ion);
	fprintf(OutFile, "| (Cd+4) - (Cd+3)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus3ion);
	fprintf(OutFile, "| (Cd+3ex) - (Cd+3)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCdplus3exion);
	fprintf(OutFile, "| (Cd+3) - (Cd+2)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus2ion);
	fprintf(OutFile, "| (Cd+2ex) - (Cd+2)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCdplus2exion);
	fprintf(OutFile, "| (Cd+2) - (Cd+1)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdplus1ion);
	fprintf(OutFile, "| (Cd+1ex) - (Cd+1)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCdplus1exion);
	fprintf(OutFile, "| (Cd+1) - (Cd+0)       |   % 7.1f   | Ionization energy     |           |           |           |           |           |\n", wspinCdneutrlion);
	fprintf(OutFile, "| (Cd+0ex) - (Cd+0)     |   % 7.1f   | Excitation energy     |           |           |           |           |           |\n", wspinCdneutrlexion);
	fprintf(OutFile, "| Cd sign mismatch      |   % 7.1f   | Exc. and Ion sign     |           |           |           |           |           |\n", wspinCdsign);

	fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	fprintf(OutFile, "| Thermo Total          |   % 7.1f   |           |           |           |           |           |           |           |\n", wspinThermo);

	fprintf(OutFile, "|=========================================================================================================================|\n");
	fprintf(OutFile, "|Suite Total Weight......................................................................................% 8.2f percent |\n", totalweight);
	fprintf(OutFile, "|=========================================================================================================================|\n");

	fprintf(OutFile, "| DIFFERENTIAL EVOLUTION OPTIMIZATION PARAMETERS                                                                          |\n");
	fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	fprintf(OutFile,"| Strategy: %s    | D=%d         | NP=%d       | F=%-4.2g       | CR=%-4.2g      |\n",strat[strategy],n_vary,NP,F,CR);
	fprintf(OutFile,"| Upper limit %3.1f   | Lower limit %3.1f | Radial limit %3.1f  | Initial population strategy: %s\n",inibound_h, inibound_l, inibound_amp, popstrat[randomstart]);
	fprintf(OutFile,"| Generation=%d        | NFEs=%ld        | cost-variance=%-10.5g|\n",gen,nfeval,cvar);

	fprintf(OutFile, "|=========================================================================================================================|\n");

	fprintf(OutFile, "| METROPOLIS FINE ENERGY MINIMIZATION                                                                                     |\n");
	fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	fprintf(OutFile, "| # Steps: % 10i | Temperature (K): %5.1f | D_init (A): %5.1f |                                                      |\n", \
			(int) MC_STEPS, (double) MC_TEMP, (double) MC_D_INIT);
	fprintf(OutFile, "| Stepsizes (Angstrom or radian) | small: %8.7f | rigid: %8.7f | rotation: %8.7f | electron radius: %8.7f |\n", \
			(double) MC_small_step, (double) MC_rigid_step, (double) MC_angle_step, (double) MC_radius_step);

	fprintf(OutFile, "| Step sizes are adjusted during the runs. Above values are only initial step sizes.                                      |\n");
	fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	//			fprintf(OutFile, "| MC OHdot2      :                                                                                            ");
	//			if (MC_spinOHdot2){ fprintf(OutFile, "|     ON    |"); } else {fprintf(OutFile, "|    OFF    |"); }                        fprintf(OutFile, "\n");

	fclose(OutFile);

	/*
	   printf("Parameters and weights are printed, starting to print each molecule now..\n");

	   printf("status before print =1\n");

	   status();
	   printf("spinthermo before print =1\n");
	   spinthermo();



	   print = 1;
	   printf("print is turned on\n");
	   printf("spinthermmo right after print 1\n");
	   spinthermo();
	   printf("status after print 1\n");
	   status();
	 */
	printEnergyTermsHead();
}
