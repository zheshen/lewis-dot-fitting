
 /**************************************************************
 * Purpose:                                                    *
 * This program is intended to output the final *pdb files of  *
 * optimized trainining structures, including particle         *
 * coordinates, electron radii and shape variables.  	       *
 **************************************************************/
 
#include "Common.h"
#include "Structure.h"

void output(V * Out, int part, char * pdb_file){

	int p;
	char d_file[250];

	FILE *OutFile = fopen(pdb_file, "a+");
	for(p = 0; p < part; p++) {

		fprintf(OutFile, "\nATOM   ");

		if (p < 999) {fprintf(OutFile, " "); }
		if (p < 99)  {fprintf(OutFile, " "); }
		if (p < 9)   {fprintf(OutFile, " "); }

		fprintf(OutFile, "%i ", p+1);

		if     ((Out[p].s) ==  1){ fprintf(OutFile, "H ");}
		else if((Out[p].s) ==  2){ fprintf(OutFile, "A ");}
		else if((Out[p].s) == -2){ fprintf(OutFile, "B ");}
		else if((Out[p].s) ==  0){ fprintf(OutFile, "E ");}
		else if((Out[p].s) ==  8){ fprintf(OutFile, "O ");}
		else if((Out[p].s) ==  7){ fprintf(OutFile, "N ");}
		else if((Out[p].s) ==  6){ fprintf(OutFile, "C ");}
		else if((Out[p].s) == 16){ fprintf(OutFile, "S ");}
		else if((Out[p].s) == 15){ fprintf(OutFile, "P ");}
		else if((Out[p].s) == 14){ fprintf(OutFile, "Si");}
		else if((Out[p].s) ==300){ fprintf(OutFile, "M ");}
		else if((Out[p].s) ==301){ fprintf(OutFile, "U ");}
		else if((Out[p].s) ==  9){ fprintf(OutFile, "F ");}
		else if((Out[p].s) ==  5){ fprintf(OutFile, "Bo");}	
		else if((Out[p].s) == 13){ fprintf(OutFile, "Al");}
		else if((Out[p].s) == 17){ fprintf(OutFile, "Cl");}
                else if((Out[p].s) ==  3){ fprintf(OutFile, "Li");}
                else if((Out[p].s) ==  4){ fprintf(OutFile, "Be");}
                else if((Out[p].s) == 11){ fprintf(OutFile, "Na");}
                else if((Out[p].s) == 12){ fprintf(OutFile, "Mg");}
		else if((Out[p].s) == 200){ fprintf(OutFile, "Qq");}
		else if((Out[p].s) == 21){ fprintf(OutFile, "Sc");}
		else if((Out[p].s) == 22){ fprintf(OutFile, "Ti");}
		else if((Out[p].s) == 23){ fprintf(OutFile, "V");}
		else if((Out[p].s) == 24){ fprintf(OutFile, "Cr");}
		else if((Out[p].s) == 25){ fprintf(OutFile, "Mn");}
		else if((Out[p].s) == 26){ fprintf(OutFile, "Fe");}
		else if((Out[p].s) == 27){ fprintf(OutFile, "Co");}
		else if((Out[p].s) == 28){ fprintf(OutFile, "Ni");}
		else if((Out[p].s) == 29){ fprintf(OutFile, "Cu");}
		else if((Out[p].s) == 30){ fprintf(OutFile, "Zn");}
		else if((Out[p].s) == 39){ fprintf(OutFile, "Y");}
		else if((Out[p].s) == 40){ fprintf(OutFile, "Zr");}
		else if((Out[p].s) == 41){ fprintf(OutFile, "Nb");}
		else if((Out[p].s) == 42){ fprintf(OutFile, "Mo");}
		else if((Out[p].s) == 43){ fprintf(OutFile, "Tc");}
		else if((Out[p].s) == 44){ fprintf(OutFile, "Ru");}
		else if((Out[p].s) == 45){ fprintf(OutFile, "Rh");}
		else if((Out[p].s) == 46){ fprintf(OutFile, "Pd");}
		else if((Out[p].s) == 47){ fprintf(OutFile, "Ag");}
		else if((Out[p].s) == 48){ fprintf(OutFile, "Cd");}


		fprintf(OutFile, "                 ");

		if (fabs(Out[p].x) >= 10) {fprintf(OutFile, "% 2.2f", Out[p].x); }
		else {fprintf(OutFile, "% 1.3f", Out[p].x); }
		fprintf(OutFile, "  ");

		if (fabs(Out[p].y) >= 10) {fprintf(OutFile, "% 2.2f", Out[p].y); }
		else {fprintf(OutFile, "% 1.3f", Out[p].y); }
		fprintf(OutFile, "  ");

		if (fabs(Out[p].z) >= 10) {fprintf(OutFile, "% 2.2f", Out[p].z); }
		else {fprintf(OutFile, "% 1.3f", Out[p].z); }
		fprintf(OutFile, "  ");

		if (fabs(creal(Out[p].d)) >= 10) {fprintf(OutFile, "% 2.2f", creal(Out[p].d)); }
		else {fprintf(OutFile, "% 1.3f", creal(Out[p].d)); }
		fprintf(OutFile, "  ");

		if (fabs(cimag(Out[p].d)) >= 10) {fprintf(OutFile, "% 2.2f", cimag(Out[p].d)); }
		else {fprintf(OutFile, "% 1.3f", cimag(Out[p].d)); }
		fprintf(OutFile, "  ");

		if (fabs(Out[p].eta) >= 10) {fprintf(OutFile, "% 2.2f", Out[p].eta); }
		else {fprintf(OutFile, "% 1.3f", Out[p].eta); }
		fprintf(OutFile, "  ");

		if (fabs(Out[p].zeta) >= 10) {fprintf(OutFile, "% 2.2f", Out[p].zeta); }
		else {fprintf(OutFile, "% 1.3f", Out[p].zeta); }


	}

	fprintf(OutFile, "\nEND\n");

	fclose(OutFile);    

	memcpy(d_file, pdb_file, strlen(pdb_file) - 4);
	d_file[strlen(pdb_file) - 4] = '\0';
	strcat(d_file, ".d");

	OutFile = fopen(d_file, "a+");
	for(p = 0; p < part; p++) {

		if (fabs(creal(Out[p].d)) >= 10) {fprintf(OutFile, "% 2.2f", creal(Out[p].d)); }
		else {fprintf(OutFile, "% 1.3f", creal(Out[p].d)); }
		fprintf(OutFile, "  ");

		if (fabs(cimag(Out[p].d)) >= 10) {fprintf(OutFile, "% 2.2f", cimag(Out[p].d)); }
		else {fprintf(OutFile, "% 1.3f", cimag(Out[p].d)); }
		fprintf(OutFile, "  ");

		if (fabs(Out[p].eta) >= 10) {fprintf(OutFile, "% 2.2f", Out[p].eta); }
		else {fprintf(OutFile, "% 1.3f", Out[p].eta); }
		fprintf(OutFile, "  ");

		if (fabs(Out[p].zeta) >= 10) {fprintf(OutFile, "% 2.2f", Out[p].zeta); }
		else {fprintf(OutFile, "% 1.3f", Out[p].zeta); }
	} 
	fprintf(OutFile, "\n");
	fclose(OutFile);

}

