
#include "Lowermain.h"
#include <string.h>
#include "main.h" 
#include "de.h"
#include "Utilities.h"
#include "U.h"
void test();
//Declaration of important variables 
char version[] = "DE6001.072";
char shelloutput[] = "ws6001";
int printFunctionPlots = 1;
int pdbSwitch = 0; //the whole trajectory of upnup 
int finalpdbswitch = 1;
int print;
int split;
int diagnose_print =0;
int debug =0;
char *optim;
char *strat[] =
{
	"",
	"DE/best/1/exp",
	"DE/rand/1/exp",
	"DE/rand-to-best/1/exp",
	"DE/best/2/exp",
	"DE/rand/2/exp",
	"DE/best/1/bin",
	"DE/rand/1/bin",
	"DE/rand-to-best/1/bin",
	"DE/best/2/bin",
	"DE/rand/2/bin"
};
char *popstrat[] =
{
	"Input values",
	"Random val. ",
	"Mixed popul."
};

//double resolutionHighInit = 0.000000001;
//double resolutionHigh[n_potentials];
double resolutionLow = 0.00001;
int writefinalpdb = 0;
int writeupnuppdb = 0;

int main (int argc, char *argv[]) {

	int success, i;
//	extern	struct tm * timeinfo;

//	FRA's help with parallelization        //init_rng();

	for (i = 0; i < 350; i++)
		dlewis[i] = 0;

	//Parameters
	for (i = 0; i < n_potentials; i++){
		ist_potentials[i] = atof(argv[i + 1]);   
		dlewis[i]=ist_potentials[i];
		//	printf("ist pot %d is %f\n",i, ist_potentials[i]);
	}
	//Keys
	for (i = 0; i < n_potentials; i++){
		key_potentials[i] = atoi(argv[i + n_potentials + 1]);
		//	printf("key pot %d is %d\n", i, key_potentials[i]);
	}
	//Exponents
	neu_potentials = argc - 2 * n_potentials - 5; 
//	printf("argc and n_pot are %d and %d so neu pot is %d\n", argc, n_potentials, neu_potentials);
	for (i = 0; i < neu_potentials; i++){
		dlewis[n_potentials + i] = atof(argv[i + 2 * n_potentials + 1]);
		printf("%f\n", dlewis[n_potentials + i]);
	}

	assignpar();
	//Record number
	simulation         = atoi(argv[argc - 4]);
	printf("simulation no: %d\n", simulation);
	if (simulation > 99){
		sprintf(stringSimulation, "%i", simulation);
	}
	else if ((simulation > 9) && (simulation <= 99)) {
		sprintf(stringSimulation, "0%i", simulation);
	}
	else{
		sprintf(stringSimulation, "00%i", simulation);
	}

	shellversion         = atoi(argv[argc - 3]);
	shellkey	     = atoi(argv[argc - 2]);	
	optim		     = argv[argc - 1];	

	strcpy(directory, version);
	strcat(directory, "#");
	strcat(directory, stringSimulation);
	strcat(directory, ".txt");	
	//Also generate the name of the error output file 
	strcpy(directoryWarnings, directory);
	strcat(directoryWarnings, ".warnings");
	//Starting with v211 generate a third output to plot smt. -right now dimer transition energies
	strcpy(directoryPlots, directory);
	strcat(directoryPlots, ".plots");
	//Starting with v225, print out functional forms. Then feed them into xmgrace
	strcpy(directoryFunctionPlots, directory);
	strcat(directoryFunctionPlots, ".functions");

	strcpy(directorySplitEnergies, directory);
	strcat(directorySplitEnergies, ".energies");

	//Misc initializations
	print=0;						
	//icue = 1;						//Upnup Progress Variable
	success = 0;					//Minima Found Success Variable
	wspinThermo = setWspinthermo();
	//Time calc for printout
	time_t rawtime;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	int n_vary=0;
	for(i = 0;  i < n_potentials; i++){
		printf("%f, %d\n", dlewis[i], i);
		//stepSize[i] = stepSizeMain;
		//resolutionHigh[i] = resolutionHighInit;
		if(key_potentials[i]==1){
			dinit[n_vary]=dlewis[i];
			n_vary++;
			printf("%f, %d, %d\n", dlewis[i], i, n_vary);
		}
	}
	
	//Optimization
	printf("Starting optimization\n");
	//	for(i=0; i<n_potentials+neu_potentials; i++){
	//		printf("dlewis[%d] is %f\n",i,dlewis[i]);
	//	}
	de(n_vary);	//The optimization comment
	updateDarray();
	assignpar();
	finalOutput();

	print = 1;
	if (finalpdbswitch){
		writeupnuppdb = 1;
		writefinalpdb = 1;
	}

//	lowermain(H);
//	lowermain(H_);
//	lowermain(H2);
//	lowermain(H2trp);
//	lowermain(H2plus);
//	lowermain(H2minus);
//	lowermain(H3);
//	lowermain(H3plus);
//        lowermain(H3linear);

	lowermain(O_1);
	lowermain(Oneutrl);
	lowermain(Oneutrlex);
	lowermain(Oneutrlex2);
	lowermain(Oplus1);
	lowermain(Oplus1ex);
	lowermain(Oplus1ex2);
	lowermain(Oplus2);
	lowermain(Oplus2ex);
	lowermain(Oplus2ex2);
	lowermain(Oplus3);
	lowermain(Oplus3ex);
	lowermain(Oplus4);
	lowermain(Oplus4ex);
	lowermain(Oplus5);

	lowermainspinO2();
	lowermainspinO2dia();
	lowermainspinO2qnt();

	lowermain(O2_linnett);
	lowermain(O2_snglbnd);
	lowermain(O2_dblbnd);
	lowermain(O2_trplbnd);
	lowermain(O2dia_linnett);
	lowermain(O2dia_snglbnd);
	lowermain(O2dia_dblbnd);
	lowermain(O2dia_trplbnd);
	lowermain(O2plus1);
	lowermain(O2_1);

	lowermain(O3_linnett);
	lowermain(O3trp_linnett);

/*
	lowermain(Feplus7);
	lowermain(Feplus6);
	lowermain(Feplus6ex);
	lowermain(Feplus5);
	lowermain(Feplus5ex);
	lowermain(Feplus4);
	lowermain(Feplus4ex);
	lowermain(Feplus4ex2);
	lowermain(Feplus3);
	lowermain(Feplus3ex);
	lowermain(Feplus3ex2);
	lowermain(Feplus2);
	lowermain(Feplus2ex);
	lowermain(Feplus2ex2);
	lowermain(Feplus1);
	lowermain(Feplus1ex);
	lowermain(Feplus1ex2);
	lowermain(Feneutrl);
	lowermain(Feneutrlex);
	lowermain(Feneutrlex2);
	lowermain(Feneutrlex3);
*/

	lowermain(Znplus11);
	lowermain(Znplus10);
	lowermain(Znplus9);
	lowermain(Znplus8);
	lowermain(Znplus7);
	lowermain(Znplus6);
	lowermain(Znplus5);
	lowermain(Znplus4);
	lowermain(Znplus3);
	lowermain(Znplus2);
	lowermain(Znplus1);
	lowermain(Znneutrl);
	lowermain(Znplus10ex);
	lowermain(Znplus6ex);
	lowermain(Znplus6ex2);
	lowermain(Znplus5ex);
	lowermain(Znplus5ex2);
	lowermain(Znplus4ex);
	lowermain(Znplus4ex2);
	lowermain(Znplus3ex);
	lowermain(Znplus2ex);
	lowermain(Znplus1ex);
	lowermain(Znneutrlex);
	lowermain(Znplus9ex);
	lowermain(Znplus8ex);
	lowermain(Znplus7ex);
	lowermain(Znplus6ex3);
	lowermain(Znplus5ex3);
	lowermain(Znplus4ex3);
	lowermain(Znplus3ex2);
	lowermain(Znplus2ex2);
	lowermain(Znplus1ex2);
	lowermain(Znneutrlex2);

//	lowermainspinOH();
//	lowermain(t_H);
//	lowermain(t_H_);
//	lowermain(t_H2);
/*	lowermainspinH2trp();
//	lowermainTransitionspinH2();
//	lowermainTransitiontripletH2();

//	if(FIT_triplet)
//		lowermainTransitiontripletH2();
//	lowermainTransitionspinH2();
//	lowermainspinH2v();

//	lowermainspinH2plus();
//	lowermainTransitionspinH2plus();
//	lowermainspinH2minus();
//	lowermainTransitionspinH2minus();
//	lowermainspinH3plus();
//	lowermainTransitionspinH3plus();
//	lowermainspinH_trp();


//	lowermainspinH3();
//	lowermainspinH4();
//
//	lowermainspinH3linear();
//	lowermainspinH3trig();
//	lowermainspinH4linear();
//	lowermainspinH4square();
//	lowermainspinH4tetra();

//	lowermainspinOHdot();
//	lowermainspinOH();
//	lowermainTransitionspinOH();
//	lowermainspinOHdot2();
//	lowermainTransitionspinOHdot();
//	lowermainTransitionspinOHdot2();
//	lowermainspinH2O();
//	lowermainspinH2Olinear();
//	lowermainspinH2Oplus();
//	lowermainspinH3O();
//	lowermainspinO2plus();

//	lowermainspinO2_1();
//	lowermainspinO2_2();
//	lowermainspinO2_2v();


	lowermainspinF_1();
	lowermainspinFneutrlex();
	lowermainspinFneutrl();
	lowermainspinFplusex2();
	lowermainspinFplusex();
	lowermainspinFplus();
	lowermainspinFplus2ex2();
	lowermainspinFplus2ex();
	lowermainspinFplus2();
	lowermainspinFplus3ex2();
	lowermainspinFplus3ex();
	lowermainspinFplus3();
	lowermainspinFplus4ex();
	lowermainspinFplus4();
	lowermainspinFplus5ex();
	lowermainspinFplus5();
	lowermainspinFplus6();
        lowermainspinF2_trplt();
        lowermainspinF2_snglt();

	lowermainspinC_1();
	lowermainspinCneutrlex2();
	lowermainspinCneutrlex();
	lowermainspinCneutrl();
	lowermainspinCplusex();
	lowermainspinCplus();
	lowermainspinCplus2ex();
	lowermainspinCplus2();
	lowermainspinCplus3();
        lowermainspinC2_trplt();
        lowermainspinC2_snglt();

	lowermainspinN_1();
	lowermainspinNneutrlex2();
	lowermainspinNneutrlex();
	lowermainspinNneutrl();
	lowermainspinNplusex2();
	lowermainspinNplusex();
	lowermainspinNplus();
	lowermainspinNplus2ex();
	lowermainspinNplus2();
	lowermainspinNplus3ex();
	lowermainspinNplus3();
	lowermainspinNplus4();
        lowermainspinN2_trplt();
        lowermainspinN2_snglt();

	lowermainspinSi_1();
	lowermainspinSineutrlex2();
	lowermainspinSineutrlex();
	lowermainspinSineutrl();
	lowermainspinSiplusex();
	lowermainspinSiplus();
	lowermainspinSiplus2ex();
	lowermainspinSiplus2();
	lowermainspinSiplus3();
        lowermainspinSi2_trplt();
        lowermainspinSi2_snglt();

	lowermainspinP_1();
	lowermainspinPneutrlex();
	lowermainspinPneutrl();
	lowermainspinPplusex2();
	lowermainspinPplusex();
	lowermainspinPplus();
	lowermainspinPplus2ex();
	lowermainspinPplus2();
	lowermainspinPplus3ex();
	lowermainspinPplus3();
	lowermainspinPplus4();
        lowermainspinP2_trplt();
        lowermainspinP2_snglt();

	lowermainspinS_1();
	lowermainspinSneutrlex2();
	lowermainspinSneutrlex();
	lowermainspinSneutrl();
	lowermainspinSplusex();
	lowermainspinSplus();
	lowermainspinSplus2ex2();
	lowermainspinSplus2ex();
	lowermainspinSplus2();
	lowermainspinSplus3ex();
	lowermainspinSplus3();
	lowermainspinSplus4ex();
	lowermainspinSplus4();
	lowermainspinSplus5();
        lowermainspinS2_trplt();
        lowermainspinS2_snglt();

	lowermainspinB_1();
	lowermainspinBneutrlex();
	lowermainspinBneutrl();
	lowermainspinBplusex();
	lowermainspinBplus();
	lowermainspinBplus2();		
        lowermainspinB2_trplt();
        lowermainspinB2_snglt();

	lowermainspinCl_1();
	lowermainspinClneutrlex();
	lowermainspinClneutrl();
	lowermainspinClplusex2();
	lowermainspinClplusex();
	lowermainspinClplus();
	lowermainspinClplus2ex();
	lowermainspinClplus2();
	lowermainspinClplus3ex2();
	lowermainspinClplus3ex();
	lowermainspinClplus3();
	lowermainspinClplus4ex();
	lowermainspinClplus4();
	lowermainspinClplus5ex();
	lowermainspinClplus5();
	lowermainspinClplus6();
        lowermainspinCl2_trplt();
        lowermainspinCl2_snglt();

	lowermainspinAl_1();
	lowermainspinAlneutrlex();
	lowermainspinAlneutrl();
	lowermainspinAlplusex();
	lowermainspinAlplus();
	lowermainspinAlplus2();				
	lowermainspinAl2_trplt();
	lowermainspinAl2_snglt();

	lowermainspinLi_1();
	lowermainspinLineutrl();
	lowermainspinBeneutrl();
	lowermainspinBeneutrlex();
	lowermainspinBeplus();
	lowermainspinNa_1();
	lowermainspinNaneutrl();
	lowermainspinMgneutrl();
	lowermainspinMgneutrlex();
	lowermainspinMgplus();



	lowermainspinH_polar();
	lowermainspinBneutrl_polar();
	lowermainspinCneutrl_polar();
	lowermainspinNneutrl_polar();
	lowermainspinOneutrl_polar();
	lowermainspinFneutrl_polar();
	lowermainspinAlneutrl_polar();
	lowermainspinSineutrl_polar();
	lowermainspinPneutrl_polar();
	lowermainspinSneutrl_polar();
	lowermainspinClneutrl_polar();


	lowermainspinScplus2();
	lowermainspinTiplus3();
	lowermainspinTiplus2();
	lowermainspinTiplus2ex();
	lowermainspinVplus4();
	lowermainspinVplus3();
	lowermainspinVplus3ex();
	lowermainspinVplus2();
	lowermainspinVplus2ex();
	lowermainspinCrplus5();
	lowermainspinCrplus4();
	lowermainspinCrplus4ex();
	lowermainspinCrplus3();
	lowermainspinCrplus3ex();
	lowermainspinCrplus2();
	lowermainspinCrplus2ex();
	lowermainspinCrplus2ex2();
	lowermainspinCrplus1();
	lowermainspinCrplus1ex();
	lowermainspinCrplus1ex2();
	lowermainspinMnplus6();
	lowermainspinMnplus5();
	lowermainspinMnplus5ex();
	lowermainspinMnplus4();
	lowermainspinMnplus4ex();
	lowermainspinMnplus3();
	lowermainspinMnplus3ex();
	lowermainspinMnplus2();
	lowermainspinMnplus2ex();
	lowermainspinMnplus2ex2();
	lowermainspinCoplus8();
	lowermainspinCoplus7();
	lowermainspinCoplus7ex();
	lowermainspinCoplus6();
	lowermainspinCoplus6ex();
	lowermainspinCoplus5();
	lowermainspinCoplus5ex();
	lowermainspinCoplus5ex2();
	lowermainspinCoplus4();
	lowermainspinCoplus4ex();
	lowermainspinCoplus4ex2();
	lowermainspinCoplus3();
	lowermainspinCoplus3ex();
	lowermainspinCoplus3ex2();
	lowermainspinCoplus2();
	lowermainspinCoplus2ex();
	lowermainspinCoplus2ex2();
	lowermainspinNiplus9();
	lowermainspinNiplus8();
	lowermainspinNiplus8ex();
	lowermainspinNiplus7();
	lowermainspinNiplus7ex();
	lowermainspinNiplus6();
	lowermainspinNiplus6ex();
	lowermainspinNiplus5();
	lowermainspinNiplus5ex();
	lowermainspinNiplus5ex2();
	lowermainspinNiplus4();
	lowermainspinNiplus4ex();
	lowermainspinNiplus4ex2();
	lowermainspinNiplus3();
	lowermainspinNiplus3ex();
	lowermainspinNiplus3ex2();
	lowermainspinNiplus2();
	lowermainspinNiplus2ex();
	lowermainspinNiplus2ex2();
	lowermainspinCuplus10();
	lowermainspinCuplus9();
	lowermainspinCuplus9ex();
	lowermainspinCuplus8();
	lowermainspinCuplus7();
	lowermainspinCuplus6();
	lowermainspinCuplus5();
	lowermainspinCuplus5ex();
	lowermainspinCuplus5ex2();
	lowermainspinCuplus4();
	lowermainspinCuplus4ex();
	lowermainspinCuplus4ex2();
	lowermainspinCuplus3();
	lowermainspinCuplus3ex();
	lowermainspinCuplus3ex2();
	lowermainspinCuplus2();
	lowermainspinCuplus2ex();
	lowermainspinCuplus1();
	lowermainspinCuplus1ex();
	lowermainspinYplus2();
	lowermainspinZrplus3();
	lowermainspinZrplus2();
	lowermainspinZrplus2ex();
	lowermainspinNbplus4();
	lowermainspinNbplus3();
	lowermainspinNbplus3ex();
	lowermainspinNbplus2();
	lowermainspinNbplus2ex();
	lowermainspinNbplus1();
	lowermainspinNbplus1ex();
	lowermainspinNbplus1ex2();
	lowermainspinMoplus5();
	lowermainspinMoplus4();
	lowermainspinMoplus4ex();
	lowermainspinMoplus3();
	lowermainspinMoplus3ex();
	lowermainspinMoplus2();
	lowermainspinMoplus2ex();
	lowermainspinMoplus2ex2();
	lowermainspinMoplus1();
	lowermainspinMoplus1ex();
	lowermainspinMoplus1ex2();
	lowermainspinTcplus6();
	lowermainspinTcplus5();
	lowermainspinTcplus4();
	lowermainspinTcplus3();
	lowermainspinTcplus2();
	lowermainspinRuplus7();
	lowermainspinRuplus6();
	lowermainspinRuplus5();
	lowermainspinRuplus4();
	lowermainspinRuplus3();
	lowermainspinRuplus2();
	lowermainspinRuplus2ex();
	lowermainspinRuplus1();
	lowermainspinRuplus1ex();
	lowermainspinRuplus1ex2();
	lowermainspinRhplus8();
	lowermainspinRhplus7();
	lowermainspinRhplus6();
	lowermainspinRhplus5();
	lowermainspinRhplus4();
	lowermainspinRhplus3();
	lowermainspinRhplus2();
	lowermainspinRhplus2ex();
	lowermainspinRhplus2ex2();
	lowermainspinRhplus1();
	lowermainspinRhplus1ex();
	lowermainspinRhplus1ex2();
	lowermainspinPdplus9();
	lowermainspinPdplus8();
	lowermainspinPdplus7();
	lowermainspinPdplus6();
	lowermainspinPdplus5();
	lowermainspinPdplus4();
	lowermainspinPdplus3();
	lowermainspinPdplus2();
	lowermainspinPdplus2ex();
	lowermainspinPdplus2ex2();
	lowermainspinPdplus1();
	lowermainspinPdplus1ex();
	lowermainspinPdneutrl();
	lowermainspinPdneutrlex();
	lowermainspinAgplus10();
	lowermainspinAgplus9();
	lowermainspinAgplus8();
	lowermainspinAgplus7();
	lowermainspinAgplus6();
	lowermainspinAgplus5();
	lowermainspinAgplus4();
	lowermainspinAgplus3();
	lowermainspinAgplus2();
	lowermainspinAgplus2ex();
	lowermainspinAgplus1();
	lowermainspinAgplus1ex();
	lowermainspinCdplus11();
	lowermainspinCdplus10();
	lowermainspinCdplus9();
	lowermainspinCdplus8();
	lowermainspinCdplus7();
	lowermainspinCdplus6();
	lowermainspinCdplus5();
	lowermainspinCdplus4();
	lowermainspinCdplus3();
	lowermainspinCdplus3ex();
	lowermainspinCdplus2();
	lowermainspinCdplus2ex();

	lowermainspinCuneutrl();
	lowermainspinCuneutrlex();
	lowermainspinNiplus1();
	lowermainspinNiplus1ex();
	lowermainspinNineutrl();
	lowermainspinNineutrlex();
	lowermainspinCoplus1();
	lowermainspinCoplus1ex();
	lowermainspinCoplus1ex2();
	lowermainspinConeutrl();
	lowermainspinConeutrlex();
	lowermainspinMnplus1();
	lowermainspinMnplus1ex();
	lowermainspinMnplus1ex2();
	lowermainspinMnplus1ex3();
	lowermainspinMnneutrl();
	lowermainspinMnneutrlex();
	lowermainspinMnneutrlex2();
	lowermainspinMnneutrlex3();
	lowermainspinCrneutrl();
	lowermainspinCrneutrlex();
	lowermainspinCrneutrlex2();
	lowermainspinCrneutrlex3();
	lowermainspinVplus1();
	lowermainspinVplus1ex();
	lowermainspinVplus1ex2();
	lowermainspinVneutrl();
	lowermainspinVneutrlex();
	lowermainspinVneutrlex2();
	lowermainspinTiplus1();
	lowermainspinTiplus1ex();
	lowermainspinTineutrl();
	lowermainspinTineutrlex();
	lowermainspinTineutrlex2();
	lowermainspinScplus1();
	lowermainspinScplus1ex();
	lowermainspinScneutrl();
	lowermainspinScneutrlex();

	lowermainspinCdplus1();
	lowermainspinCdplus1ex();
	lowermainspinCdneutrl();
	lowermainspinCdneutrlex();
	lowermainspinAgneutrl();
	lowermainspinAgneutrlex();
	lowermainspinRhneutrl();
	lowermainspinRhneutrlex();
	lowermainspinRuneutrl();
	lowermainspinRuneutrlex();
	lowermainspinRuneutrlex2();
	lowermainspinTcplus1();
	lowermainspinTcplus1ex();
	lowermainspinTcneutrl();
	lowermainspinTcneutrlex();
	lowermainspinTcneutrlex2();
	lowermainspinTcneutrlex3();
	lowermainspinMoneutrl();
	lowermainspinMoneutrlex();
	lowermainspinMoneutrlex2();
	lowermainspinMoneutrlex3();
	lowermainspinNbneutrl();
	lowermainspinNbneutrlex();
	lowermainspinNbneutrlex2();
	lowermainspinZrplus1();
	lowermainspinZrplus1ex();
	lowermainspinZrneutrl();
	lowermainspinZrneutrlex();
	lowermainspinZrneutrlex2();
	lowermainspinYplus1();
	lowermainspinYplus1ex();
	lowermainspinYneutrl();
	lowermainspinYneutrlex();

	lowermainspinZundel();
	lowermainspinDeprotonatedDimer();
	lowermainspindimer();
*/
	spinthermo();
	printEndLine();
	if (printFunctionPlots)
		printAllEnergyPlots();
	success = 1;

//if(!success)
//	printNoMinima("UPPER MAIN ");

	return 0;
	}

void assignpar(){
	int i,k,l;
	k = 0;
	l = 0;

	for (i = l; i<l+n_AB; i++){
		parAB[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_AB;

	for (i = l; i<l+n_AH; i++){
		parAH[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_AH;

	for (i = l; i<l+n_LiA; i++){
		parLiA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_LiA;

	for (i = l; i<l+n_BeA; i++){
		parBeA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_BeA;

	for (i = l; i<l+n_BoA; i++){
		parBoA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_BoA;

	for (i = l; i<l+n_CA; i++){
		parCA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_CA;

	for (i = l; i<l+n_NA; i++){
		parNA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_NA;

	for (i = l; i<l+n_OA; i++){
		parOA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_OA;

	for (i = l; i<l+n_FA; i++){
		parFA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_FA;

	for (i = l; i<l+n_NaA; i++){
		parNaA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_NaA;

	for (i = l; i<l+n_MgA; i++){
		parMgA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_MgA;

	for (i = l; i<l+n_AlA; i++){
		parAlA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_AlA;

	for (i = l; i<l+n_SiA; i++){
		parSiA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_SiA;

	for (i = l; i<l+n_PA; i++){
		parPA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_PA;

	for (i = l; i<l+n_SA; i++){
		parSA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_SA;

	for (i = l; i<l+n_ClA; i++){
		parClA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_ClA;

	for (i = l; i<l+n_FeA; i++){
		parFeA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_FeA;

	for (i = l; i<l+n_MA; i++){
		parMA[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_MA;

	for (i = l; i<l+n_CH; i++){
		parCH[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_CH;

	for (i = l; i<l+n_NH; i++){
		parNH[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_NH;

	for (i = l; i<l+n_OH; i++){
		parOH[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_OH;

	for (i = l; i<l+n_CC; i++){
		parCC[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_CC;


	for (i = l; i<l+n_NN; i++){
		parNN[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_NN;

	for (i = l; i<l+n_OO; i++){
		parOO[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_OO;

	for (i = l; i<l+n_CN; i++){
		parCN[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_CN;

	for (i = l; i<l+n_CO; i++){
		parCO[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_CO;

	for (i = l; i<l+n_NO; i++){
		parNO[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_NO;

	for (i = l; i<l+n_HH; i++){
		parHH[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_HH;

}

void updateDarray(){
	int i,j;
//	extern double best[];
	/* Assigning the parameters that changed back into the overall dlewis[] array*/
	j=0;
	for (i=0; i<n_potentials; i++){
		if (key_potentials[i]>0) {
//			  printf("key_potential at %d is %d\n",i,key_potentials[i]);
			dlewis[i]=best[j];
//			  printf("best at %d is %f\n",i,best[j]);
			j++;
		}
	}
}
