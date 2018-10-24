
//Declaration of main.c functions
double status();
double setWspinthermo();
//double upnupmain();
//double updateEnergyArray();
int de(int);
//double evaluate(int,double,long);
void updateDarray();
//int PorM();
void finalOutput();

//Variables
char directory[250], directoryWarnings[250], directoryPlots[250], directoryFunctionPlots[250], directorySplitEnergies[250];
double totaldev, totalweight;
double spinOHdipole, spinH2Odipole, spinH3Odipole;
double zStructfinal, devOHydrideStruct, devNCOHydrideStruct, devThermo, devspinThermo, devFlex, finaldev;
double dummy[10];


int simulation;
int shellversion, shellkey;
char stringSimulation[8];
double wspinThermo;
int neu_potentials;
int icue_spin;
struct tm * timeinfo;
int n_vary;
FILE *OutFile;

//double stepSize[n_potentials];
//int icue;
//double a_potentials[n_potentials];
double final_potentials[n_potentials];
int key_potentials[n_potentials];
double ist_potentials[n_potentials];

//Parameter variables
double dlewis[400]; //to cover all parameters and exponents
double parAB[n_AB];
//double parAA[n_AA];
double parAH[n_AH];
double parCA[n_CA];
double parNA[n_NA];
double parOA[n_OA];
double parHH[n_HH];
double parCH[n_CH];
double parNH[n_NH];
double parOH[n_OH];
double parCC[n_CC];
double parNN[n_NN];
double parOO[n_OO];
double parCN[n_CN];
double parCO[n_CO];
double parNO[n_NO];
//double parKE[n_KE];
double parFA[n_FA];
double parSiA[n_SiA];
double parSA[n_SA];
double parPA[n_PA];
double parBoA[n_BoA];
double parAlA[n_AlA];
double parClA[n_ClA];
double parFeA[n_FeA];
double parMA[n_MA];
//double parXA[n_XA];
double parNaA[n_NaA];
double parLiA[n_LiA];
double parBeA[n_BeA];
double parMgA[n_MgA];

