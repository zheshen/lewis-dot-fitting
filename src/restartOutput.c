
 /**************************************************************
 * Purpose:                                                    *
 * This program is intended to store intermediate fitting      *
 * results every certain steps in a *.sh.<output_number> file, *
 * so that each interupted fitting will restart from the       *
 * recorded point.                                             *
 **************************************************************/
 
#include "Common.h"
#include "Lowermain.h"
#include <string.h>
#include "main.h"
#include "de.h"

int EndsWith(const char *str, const char *suffix)
{
    if (!str || !suffix)
        return 0;
    size_t lenstr = strlen(str);
    size_t lensuffix = strlen(suffix);
    if (lensuffix >  lenstr)
        return 0;
    return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
}

void restartOutput(double tmp[]){
	int i;
//	extern char version[];
	extern char shelloutput[];
	extern char *shellname;
//	extern int shellversion;
	extern int simulation;
	char Shell_Ver[10];
	char Simu_Num[10];
//	extern int printFunctionPlots;
//	extern int pdbSwitch;
//	extern int finalpdbswitch;
//	extern int print;
//	extern int diagnose_print;
//	extern char *strat[];
//	extern char *popstrat[];
//	extern double resolutionHighInit;
//	extern double resolutionHigh[n_potentials];
//	extern double resolutionLow;
//	extern double stepSizeMain;
//	extern int writefinalpdb;

	char input[50];
	char output[50];
	FILE *InFile;
	FILE *OutFile;
	size_t nbytes = 200;
	char *line;
	line = malloc(nbytes);
	strcpy(input, shellname);
	strcpy(output, shellname);
	if (EndsWith(shellname,".sh")){
//	strcat(input, ".");
//	sprintf(Shell_Ver, "%02d", shellversion);
//	strcat(input, Shell_Ver);
//	strcat(input, ".sh");
//	strcpy(output, input);
		strcat(output, ".");
		sprintf(Simu_Num, "%d", simulation);
		strcat(output, Simu_Num);
	}

	InFile = fopen(input, "r");
	OutFile = fopen(output, "w");

	int j, l;
	l=0;
	j=0;
	for (i=0; i<n_potentials; i++){
		if (key_potentials[i]>0) {
			dlewis[i]=tmp[j];
			j++;
		}
	}

	while (getline(&line,&nbytes,InFile) != -1) {
		if (strncmp(line,"AB_0",4) == 0) {
			fprintf(OutFile,"AB_0=\'");
			for (i=0; i<n_AB/2; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"AB_1",4) == 0) {
			fprintf(OutFile,"AB_1=\'");
			for (i=0; i<n_AB/2; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"AH_0",4) == 0) {
			fprintf(OutFile,"AH_0=\'");
			for (i=0; i<n_AH; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"LiA_0",4) == 0) {
			fprintf(OutFile,"LiA_0=\'");
			for (i=0; i<n_LiA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"BeA_0",4) == 0) {
			fprintf(OutFile,"BeA_0=\'");
			for (i=0; i<n_BeA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"BoA_0",4) == 0) {
			fprintf(OutFile,"BoA_0=\'");
			for (i=0; i<n_BoA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"CA_0",4) == 0) {
			fprintf(OutFile,"CA_0=\'");
			for (i=0; i<n_CA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"NA_0",4) == 0) {
			fprintf(OutFile,"NA_0=\'");
			for (i=0; i<n_NA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"OA_0",4) == 0) {
			fprintf(OutFile,"OA_0=\'");
			for (i=0; i<n_OA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"FA_0",4) == 0) {
			fprintf(OutFile,"FA_0=\'");
			for (i=0; i<n_FA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"NaA_0",4) == 0) {
			fprintf(OutFile,"NaA_0=\'");
			for (i=0; i<n_NaA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"MgA_0",4) == 0) {
			fprintf(OutFile,"MgA_0=\'");
			for (i=0; i<n_MgA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"AlA_0",4) == 0) {
			fprintf(OutFile,"AlA_0=\'");
			for (i=0; i<n_AlA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"SiA_0",4) == 0) {
			fprintf(OutFile,"SiA_0=\'");
			for (i=0; i<n_SiA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"PA_0",4) == 0) {
			fprintf(OutFile,"PA_0=\'");
			for (i=0; i<n_PA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"SA_0",4) == 0) {
			fprintf(OutFile,"SA_0=\'");
			for (i=0; i<n_SA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"ClA_0",4) == 0) {
			fprintf(OutFile,"ClA_0=\'");
			for (i=0; i<n_ClA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"FeA_0",4) == 0) {
			fprintf(OutFile,"FeA_0=\'");
			for (i=0; i<n_FeA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"MA_0",4) == 0) {
			fprintf(OutFile,"MA_0=\'");
			for (i=0; i<n_MA; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"CH_0",4) == 0) {
			fprintf(OutFile,"CH_0=\'");
			for (i=0; i<n_CH; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"NH_0",4) == 0) {
			fprintf(OutFile,"NH_0=\'");
			for (i=0; i<n_NH; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"OH_0",4) == 0) {
			fprintf(OutFile,"OH_0=\'");
			for (i=0; i<n_OH; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"CC_0",4) == 0) {
			fprintf(OutFile,"CC_0=\'");
			for (i=0; i<n_CC; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"NN_0",4) == 0) {
			fprintf(OutFile,"NN_0=\'");
			for (i=0; i<n_NN; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"OO_0",4) == 0) {
			fprintf(OutFile,"OO_0=\'");
			for (i=0; i<n_OO; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"CN_0",4) == 0) {
			fprintf(OutFile,"CN_0=\'");
			for (i=0; i<n_CN; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"CO_0",4) == 0) {
			fprintf(OutFile,"CO_0=\'");
			for (i=0; i<n_CO; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"NO_0",4) == 0) {
			fprintf(OutFile,"NO_0=\'");
			for (i=0; i<n_NO; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}

		else if (strncmp(line,"HH_0",4) == 0) {
			fprintf(OutFile,"HH_0=\'");
			for (i=0; i<n_HH; i++){ 
				fprintf(OutFile,"%5f ", dlewis[l]);
				l++;
			}
			fprintf(OutFile,"\'\n");
		}
		
		else {
			fprintf(OutFile, line);
		}
	}
	fclose(InFile);
	fclose(OutFile);
	free(line);
}
