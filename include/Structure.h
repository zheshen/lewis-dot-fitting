/*
 * Structure.h
 * By: Geoff Conklin
 * Date: 9/22/2016
 * Purpose: Used to declare the types of structs and provide 
 * a clear documentation as to how structures are established
 * in LEWIS. In addition to structure layout,
 * a few structure related functions are provided here as 
 * structure specific switches or initilization
 *
 * Revised by: Zhe Shen
 * Date: 6/21/2017
 * Integrated all structure related function declarations into here.
 *
 * Date: 7/25/2017
 * Add pointers to "ainter" & "dev" functions to the structure of each training structure.
 * Notice: remember to add function decalarations for "spec**, "ainter**" & "dev**" of each training structure in this head file below. 

*/

// Species.h defines typedef MoName as an enum list of all species
#include "Species.h"
#include "Common.h"

typedef struct C{
	double real;
	double imag;
}C;
typedef struct V{
	double x, y, z, q, eta, zeta;
	double complex d; 
	int s;
}V;

typedef struct Species{
	char fullname[100];
	char name[25];
	char spin[10];
	MoName type;
	int complete;
	int kernel;
	int degFree;
	int numPart;
	int icue;
	double energy;
	double stepSize;
	double *sym;
	double *ist;
	int *key;
	double b;
	double bg;
	double *g;
	double (*ainter)();
	double (*dev)();
	V *coord;
}Species;

int upnupspin(Species *spec);
void Initialize(Species *); // Allocates memory for sym and coord structure arrays in a Species
void Delete(Species);	    // Frees memory allocated by initialize
double ainterSwitch(Species *); // Uses the Species sym coords and type to convert to cartesian coords and store them in the same Species
void specSwitch(Species *); // Set initial species structure for particular training structure
double devSwitch(Species *); // Calculate strcture deviation and print structure output for each training structure

// Minimization routines
int metropolisSym(Species); 
//double sumEnergies(V *, int);
//Structure property calculations
double distance(double, double, double, double, double ,double);
double angle(double, double, double, double, double, double);
double getDistance(V *, int, int);
double getAngle(V *, int, int, int);
double getR2Dist(V *, int, V *, int);
double raddeg(double);
double degrad(double);
double rot(double, double, double, double, double, double, int);
double getDipole(V *, int);
//double getQuadrupole(V *, int, int);
double getDihedral(struct V *, int, int, int, int);
double smaller(double, double);
double getR2(struct V *, int, int);
double getYPolar(struct V*, int);
double getPolar(struct V*, int);
double getBondOrder(struct V*, int, double);
double getSpinSym(struct V*, int, double);
//double getStepScale(int);


double sumEnergies(V *, int);
double sumEnergies_split(V *, int, double *);
//double *sumEnergies_split(V *, int);
double metropolis(V *, int, int);
void output(V *, int, char *);
void setSvalue(V *, int);
void setDvalue(V *, int);

//Include all specific functions of initial Species setting for each training strucure.

void specspinH(Species *spec);
void specspinH_(Species *spec);
void specspinH2(Species *spec);
void specspinH2trp(Species *spec);
void specspinH2plus(Species *spec);
void specspinH2minus(Species *spec);
void specspinH3(Species *spec);
void specspinH3plus(Species *spec);
void specspinH3linear(Species *spec);

void specspinZnneutrl(Species *spec);
void specspinZnneutrlex(Species *spec);
void specspinZnplus1(Species *spec);
void specspinZnplus1ex(Species *spec);
void specspinZnplus2(Species *spec);
void specspinZnplus2ex(Species *spec);
void specspinZnplus3(Species *spec);
void specspinZnplus3ex(Species *spec);
void specspinZnplus4(Species *spec);
void specspinZnplus4ex(Species *spec);
void specspinZnplus4ex2(Species *spec);
void specspinZnplus5(Species *spec);
void specspinZnplus5ex(Species *spec);
void specspinZnplus5ex2(Species *spec);
void specspinZnplus6(Species *spec);
void specspinZnplus6ex(Species *spec);
void specspinZnplus6ex2(Species *spec);
void specspinZnplus7(Species *spec);
void specspinZnplus8(Species *spec);
void specspinZnplus9(Species *spec);
void specspinZnplus10(Species *spec);
void specspinZnplus10ex(Species *spec);
void specspinZnplus11(Species *spec);

void specspinZnneutrlex2(Species *spec);
void specspinZnplus1ex2(Species *spec);
void specspinZnplus2ex2(Species *spec);
void specspinZnplus3ex2(Species *spec);
void specspinZnplus4ex3(Species *spec);
void specspinZnplus5ex3(Species *spec);
void specspinZnplus6ex3(Species *spec);
void specspinZnplus7ex(Species *spec);
void specspinZnplus8ex(Species *spec);
void specspinZnplus9ex(Species *spec);

void specspinO_2(Species *spec);
void specspinO_1(Species *spec);
void specspinOneutrl(Species *spec);
void specspinOneutrlex(Species *spec);
void specspinOneutrlex2(Species *spec);
void specspinOplus1(Species *spec);
void specspinOplus1ex(Species *spec);
void specspinOplus1ex2(Species *spec);
void specspinOplus2(Species *spec);
void specspinOplus2ex(Species *spec);
void specspinOplus2ex2(Species *spec);
void specspinOplus3(Species *spec);
void specspinOplus3ex(Species *spec);
void specspinOplus4(Species *spec);
void specspinOplus4ex(Species *spec);
void specspinOplus5(Species *spec);

void specspinFeneutrl(Species *spec);
void specspinFeneutrlex(Species *spec);
void specspinFeneutrlex2(Species *spec);
void specspinFeneutrlex3(Species *spec);
void specspinFeplus1(Species *spec);
void specspinFeplus1ex(Species *spec);
void specspinFeplus1ex2(Species *spec);
void specspinFeplus2(Species *spec);
void specspinFeplus2ex(Species *spec);
void specspinFeplus2ex2(Species *spec);
void specspinFeplus3(Species *spec);
void specspinFeplus3ex(Species *spec);
void specspinFeplus3ex2(Species *spec);
void specspinFeplus4(Species *spec);
void specspinFeplus4ex(Species *spec);
void specspinFeplus4ex2(Species *spec);
void specspinFeplus5(Species *spec);
void specspinFeplus5ex(Species *spec);
void specspinFeplus6(Species *spec);
void specspinFeplus6ex(Species *spec);
void specspinFeplus7(Species *spec);

void specspinC_1(Species *spec);
void specspinCneutrl(Species *spec);
void specspinCneutrlex(Species *spec);
void specspinCneutrlex2(Species *spec);
void specspinCplus1(Species *spec);
void specspinCplus1ex(Species *spec);
void specspinCplus2(Species *spec);
void specspinCplus2ex(Species *spec);
void specspinCplus3(Species *spec);

void specspinNneutrl(Species *spec);
void specspinNneutrlex(Species *spec);
void specspinNneutrlex2(Species *spec);
void specspinNplus1(Species *spec);
void specspinNplus1ex(Species *spec);
void specspinNplus1ex2(Species *spec);
void specspinNplus2(Species *spec);
void specspinNplus2ex(Species *spec);
void specspinNplus3(Species *spec);
void specspinNplus3ex(Species *spec);
void specspinNplus4(Species *spec);

void specspinF_1(Species *spec);
void specspinFneutrl(Species *spec);
void specspinFneutrlex(Species *spec);
void specspinFplus1(Species *spec);
void specspinFplus1ex(Species *spec);
void specspinFplus1ex2(Species *spec);
void specspinFplus2(Species *spec);
void specspinFplus2ex(Species *spec);
void specspinFplus2ex2(Species *spec);
void specspinFplus3(Species *spec);
void specspinFplus3ex(Species *spec);
void specspinFplus4(Species *spec);
void specspinFplus4ex(Species *spec);
void specspinFplus5(Species *spec);
void specspinFplus5ex(Species *spec);
void specspinFplus6(Species *spec);

void specspinSi_1(Species *spec);
void specspinSineutrl(Species *spec);
void specspinSineutrlex(Species *spec);
void specspinSineutrlex2(Species *spec);
void specspinSiplus1(Species *spec);
void specspinSiplus1ex(Species *spec);
void specspinSiplus2(Species *spec);
void specspinSiplus2ex(Species *spec);
void specspinSiplus3(Species *spec);

void specspinP_1(Species *spec);
void specspinPneutrl(Species *spec);
void specspinPneutrlex(Species *spec);
void specspinPplus1(Species *spec);
void specspinPplus1ex(Species *spec);
void specspinPplus1ex2(Species *spec);
void specspinPplus2(Species *spec);
void specspinPplus2ex(Species *spec);
void specspinPplus3(Species *spec);
void specspinPplus3ex(Species *spec);
void specspinPplus4(Species *spec);

void specspinS_1(Species *spec);
void specspinSneutrl(Species *spec);
void specspinSneutrlex(Species *spec);
void specspinSneutrlex2(Species *spec);
void specspinSplus1(Species *spec);
void specspinSplus1ex(Species *spec);
void specspinSplus2(Species *spec);
void specspinSplus2ex(Species *spec);
void specspinSplus2ex2(Species *spec);
void specspinSplus3(Species *spec);
void specspinSplus3ex(Species *spec);
void specspinSplus4(Species *spec);
void specspinSplus4ex(Species *spec);
void specspinSplus5(Species *spec);

void specspinB_1(Species *spec);
void specspinBneutrl(Species *spec);
void specspinBneutrlex(Species *spec);
void specspinBplus1(Species *spec);
void specspinBplus1ex(Species *spec);
void specspinBplus2(Species *spec);

void specspinCl_1(Species *spec);
void specspinClneutrl(Species *spec);
void specspinClneutrlex(Species *spec);
void specspinClplus1(Species *spec);
void specspinClplus1ex(Species *spec);
void specspinClplus1ex2(Species *spec);
void specspinClplus2(Species *spec);
void specspinClplus2ex(Species *spec);
void specspinClplus3(Species *spec);
void specspinClplus3ex(Species *spec);
void specspinClplus3ex2(Species *spec);
void specspinClplus4(Species *spec);
void specspinClplus4ex(Species *spec);
void specspinClplus5(Species *spec);
void specspinClplus5ex(Species *spec);
void specspinClplus6(Species *spec);

void specspinAl_1(Species *spec);
void specspinAlneutrl(Species *spec);
void specspinAlneutrlex(Species *spec);
void specspinAlplus1(Species *spec);
void specspinAlplus1ex(Species *spec);
void specspinAlplus2(Species *spec);

void specspinLi_1(Species *spec);
void specspinLineutrl(Species *spec);

void specspinBe_1(Species *spec);
void specspinBeneutrl(Species *spec);
void specspinBeneutrlex(Species *spec);
void specspinBeplus1(Species *spec);

void specspinNa_1(Species *spec);
void specspinNaneutrl(Species *spec);

void specspinMg_1(Species *spec);
void specspinMgneutrl(Species *spec);
void specspinMgneutrlex(Species *spec);
void specspinMgplus1(Species *spec);

void specspinScneutrl(Species *spec);
void specspinScneutrlex(Species *spec);
void specspinScplus1(Species *spec);
void specspinScplus1ex(Species *spec);
void specspinScplus2(Species *spec);

void specspinTineutrl(Species *spec);
void specspinTineutrlex(Species *spec);
void specspinTineutrlex2(Species *spec);
void specspinTiplus1(Species *spec);
void specspinTiplus1ex(Species *spec);
void specspinTiplus2(Species *spec);
void specspinTiplus2ex(Species *spec);
void specspinTiplus3(Species *spec);

void specspinVneutrl(Species *spec);
void specspinVneutrlex(Species *spec);
void specspinVneutrlex2(Species *spec);
void specspinVplus1(Species *spec);
void specspinVplus1ex(Species *spec);
void specspinVplus2(Species *spec);
void specspinVplus2ex(Species *spec);
void specspinVplus3(Species *spec);
void specspinVplus3ex(Species *spec);
void specspinVplus4(Species *spec);

void specspinCrneutrl(Species *spec);
void specspinCrneutrlex(Species *spec);
void specspinCrplus1(Species *spec);
void specspinCrplus1ex(Species *spec);
void specspinCrplus1ex2(Species *spec);
void specspinCrplus2(Species *spec);
void specspinCrplus2ex(Species *spec);
void specspinCrplus2ex2(Species *spec);
void specspinCrplus3(Species *spec);
void specspinCrplus3ex(Species *spec);
void specspinCrplus4(Species *spec);
void specspinCrplus4ex(Species *spec);
void specspinCrplus5(Species *spec);

void specspinMnneutrl(Species *spec);
void specspinMnneutrlex(Species *spec);
void specspinMnneutrlex2(Species *spec);
void specspinMnplus1(Species *spec);
void specspinMnplus1ex(Species *spec);
void specspinMnplus1ex2(Species *spec);
void specspinMnplus2(Species *spec);
void specspinMnplus2ex(Species *spec);
void specspinMnplus2ex2(Species *spec);
void specspinMnplus3(Species *spec);
void specspinMnplus3ex(Species *spec);
void specspinMnplus4(Species *spec);
void specspinMnplus4ex(Species *spec);
void specspinMnplus5(Species *spec);
void specspinMnplus5ex(Species *spec);
void specspinMnplus6(Species *spec);

void specspinConeutrl(Species *spec);
void specspinConeutrlex(Species *spec);
void specspinCoplus1(Species *spec);
void specspinCoplus1ex(Species *spec);
void specspinCoplus1ex2(Species *spec);
void specspinCoplus2(Species *spec);
void specspinCoplus2ex(Species *spec);
void specspinCoplus2ex2(Species *spec);
void specspinCoplus3(Species *spec);
void specspinCoplus3ex(Species *spec);
void specspinCoplus3ex2(Species *spec);
void specspinCoplus4(Species *spec);
void specspinCoplus4ex(Species *spec);
void specspinCoplus4ex2(Species *spec);
void specspinCoplus5(Species *spec);
void specspinCoplus5ex(Species *spec);
void specspinCoplus5ex2(Species *spec);
void specspinCoplus6(Species *spec);
void specspinCoplus6ex(Species *spec);
void specspinCoplus7(Species *spec);
void specspinCoplus7ex(Species *spec);
void specspinCoplus8(Species *spec);

void specspinNineutrl(Species *spec);
void specspinNineutrlex(Species *spec);
void specspinNiplus1(Species *spec);
void specspinNiplus1ex(Species *spec);
void specspinNiplus2(Species *spec);
void specspinNiplus2ex(Species *spec);
void specspinNiplus2ex2(Species *spec);
void specspinNiplus3(Species *spec);
void specspinNiplus3ex(Species *spec);
void specspinNiplus3ex2(Species *spec);
void specspinNiplus4(Species *spec);
void specspinNiplus4ex(Species *spec);
void specspinNiplus4ex2(Species *spec);
void specspinNiplus5(Species *spec);
void specspinNiplus5ex(Species *spec);
void specspinNiplus5ex2(Species *spec);
void specspinNiplus6(Species *spec);
void specspinNiplus6ex(Species *spec);
void specspinNiplus7(Species *spec);
void specspinNiplus7ex(Species *spec);
void specspinNiplus8(Species *spec);
void specspinNiplus8ex(Species *spec);
void specspinNiplus9(Species *spec);

void specspinCuneutrl(Species *spec);
void specspinCuneutrlex(Species *spec);
void specspinCuplus1(Species *spec);
void specspinCuplus1ex(Species *spec);
void specspinCuplus2(Species *spec);
void specspinCuplus2ex(Species *spec);
void specspinCuplus3(Species *spec);
void specspinCuplus3ex(Species *spec);
void specspinCuplus3ex2(Species *spec);
void specspinCuplus4(Species *spec);
void specspinCuplus4ex(Species *spec);
void specspinCuplus4ex2(Species *spec);
void specspinCuplus5(Species *spec);
void specspinCuplus5ex(Species *spec);
void specspinCuplus5ex2(Species *spec);
void specspinCuplus6(Species *spec);
void specspinCuplus7(Species *spec);
void specspinCuplus8(Species *spec);
void specspinCuplus9(Species *spec);
void specspinCuplus9ex(Species *spec);
void specspinCuplus10(Species *spec);

void specspinYnneutrl(Species *spec);
void specspinYnneutrlex(Species *spec);
void specspinYnplus1(Species *spec);
void specspinYnplus1ex(Species *spec);
void specspinYnplus2(Species *spec);

void specspinZrneutrl(Species *spec);
void specspinZrneutrlex(Species *spec);
void specspinZrneutrlex2(Species *spec);
void specspinZrplus1(Species *spec);
void specspinZrplus1ex(Species *spec);
void specspinZrplus2(Species *spec);
void specspinZrplus2ex(Species *spec);
void specspinZrplus3(Species *spec);



// Diatomics

void specspinO2_linnett(Species *spec);
void specspinO2_snglbnd(Species *spec);
void specspinO2_dblbnd(Species *spec);
void specspinO2_trplbnd(Species *spec);
void specspinO2dia_linnett(Species *spec);
void specspinO2dia_snglbnd(Species *spec);
void specspinO2dia_dblbnd(Species *spec);
void specspinO2dia_trplbnd(Species *spec);
void specspinO2qnt_linnett(Species *spec);
void specspinO2qnt_snglbnd(Species *spec);
void specspinO2qnt_dblbnd(Species *spec);
void specspinO2qnt_trplbnd(Species *spec);
void spicspinO3_linnett(Species *spec);
void spicspinO3trp_linnett(Species *spec);

void specspinDielectron(Species *spec);
void specspinDielectronex(Species *spec);

//Include all specific functions of structure deviation calculation for each training strucure.

double devspinH(Species *spec);
double devspinH_(Species *spec);
double devspinH2(Species *spec);
double devspinH2trp(Species *spec);
double devspinH2plus(Species *spec);
double devspinH2minus(Species *spec);
double devspinH3(Species *spec);
double devspinH3plus(Species *spec);
double devspinH3linear(Species *spec);

double devspinZnneutrl(Species *spec);
double devspinZnneutrlex(Species *spec);
double devspinZnplus1(Species *spec);
double devspinZnplus1ex(Species *spec);
double devspinZnplus2(Species *spec);
double devspinZnplus2ex(Species *spec);
double devspinZnplus3(Species *spec);
double devspinZnplus3ex(Species *spec);
double devspinZnplus4(Species *spec);
double devspinZnplus4ex(Species *spec);
double devspinZnplus4ex2(Species *spec);
double devspinZnplus5(Species *spec);
double devspinZnplus5ex(Species *spec);
double devspinZnplus5ex2(Species *spec);
double devspinZnplus6(Species *spec);
double devspinZnplus6ex(Species *spec);
double devspinZnplus6ex2(Species *spec);
double devspinZnplus7(Species *spec);
double devspinZnplus8(Species *spec);
double devspinZnplus9(Species *spec);
double devspinZnplus10(Species *spec);
double devspinZnplus10ex(Species *spec);
double devspinZnplus11(Species *spec);

double devspinZnneutrlex2(Species *spec);
double devspinZnplus1ex2(Species *spec);
double devspinZnplus2ex2(Species *spec);
double devspinZnplus3ex2(Species *spec);
double devspinZnplus4ex3(Species *spec);
double devspinZnplus5ex3(Species *spec);
double devspinZnplus6ex3(Species *spec);
double devspinZnplus7ex(Species *spec);
double devspinZnplus8ex(Species *spec);
double devspinZnplus9ex(Species *spec);

double devspinO_2(Species *spec);
double devspinO_1(Species *spec);
double devspinOneutrl(Species *spec);
double devspinOneutrlex(Species *spec);
double devspinOneutrlex2(Species *spec);
double devspinOplus1(Species *spec);
double devspinOplus1ex(Species *spec);
double devspinOplus1ex2(Species *spec);
double devspinOplus2(Species *spec);
double devspinOplus2ex(Species *spec);
double devspinOplus2ex2(Species *spec);
double devspinOplus3(Species *spec);
double devspinOplus3ex(Species *spec);
double devspinOplus4(Species *spec);
double devspinOplus4ex(Species *spec);
double devspinOplus5(Species *spec);

double devspinFeneutrl(Species *spec);
double devspinFeneutrlex(Species *spec);
double devspinFeneutrlex2(Species *spec);
double devspinFeneutrlex3(Species *spec);
double devspinFeplus1(Species *spec);
double devspinFeplus1ex(Species *spec);
double devspinFeplus1ex2(Species *spec);
double devspinFeplus2(Species *spec);
double devspinFeplus2ex(Species *spec);
double devspinFeplus2ex2(Species *spec);
double devspinFeplus3(Species *spec);
double devspinFeplus3ex(Species *spec);
double devspinFeplus3ex2(Species *spec);
double devspinFeplus4(Species *spec);
double devspinFeplus4ex(Species *spec);
double devspinFeplus4ex2(Species *spec);
double devspinFeplus5(Species *spec);
double devspinFeplus5ex(Species *spec);
double devspinFeplus6(Species *spec);
double devspinFeplus6ex(Species *spec);
double devspinFeplus7(Species *spec);

double devspinC_1(Species *spec);
double devspinCneutrl(Species *spec);
double devspinCneutrlex(Species *spec);
double devspinCneutrlex2(Species *spec);
double devspinCplus1(Species *spec);
double devspinCplus1ex(Species *spec);
double devspinCplus2(Species *spec);
double devspinCplus2ex(Species *spec);
double devspinCplus3(Species *spec);

double devspinNneutrl(Species *spec);
double devspinNneutrlex(Species *spec);
double devspinNneutrlex2(Species *spec);
double devspinNplus1(Species *spec);
double devspinNplus1ex(Species *spec);
double devspinNplus1ex2(Species *spec);
double devspinNplus2(Species *spec);
double devspinNplus2ex(Species *spec);
double devspinNplus3(Species *spec);
double devspinNplus3ex(Species *spec);
double devspinNplus4(Species *spec);

double devspinO2_linnett(Species *spec);
double devspinO2_snglbnd(Species *spec);
double devspinO2_dblbnd(Species *spec);
double devspinO2_trplbnd(Species *spec);
double devspinO2dia_linnett(Species *spec);
double devspinO2dia_snglbnd(Species *spec);
double devspinO2dia_dblbnd(Species *spec);
double devspinO2dia_trplbnd(Species *spec);
double devspinO2qnt_linnett(Species *spec);
double devspinO2qnt_snglbnd(Species *spec);
double devspinO2qnt_dblbnd(Species *spec);
double devspinO2qnt_trplbnd(Species *spec);
double devspinO3_linnett(Species *spec);
double devspinO3trp_linnett(Species *spec);

double devspinDielectron(Species *spec);
double devspinDielectronex(Species *spec);

//Include all specific functions of structure coordinate transformation and energy calculation for each training strucure.

double ainterspinH(Species *spec);
double ainterspinH_(Species *spec);
double ainterspinH2(Species *spec);
double ainterspinH2trp(Species *spec);
double ainterspinH2plus(Species *spec);
double ainterspinH2minus(Species *spec);
double ainterspinH3(Species *spec);
double ainterspinH3plus(Species *spec);
double ainterspinH3linear(Species *spec);

double ainterspinZnneutrl(Species *spec);
double ainterspinZnneutrlex(Species *spec);
double ainterspinZnplus1(Species *spec);
double ainterspinZnplus1ex(Species *spec);
double ainterspinZnplus2(Species *spec);
double ainterspinZnplus2ex(Species *spec);
double ainterspinZnplus3(Species *spec);
double ainterspinZnplus3ex(Species *spec);
double ainterspinZnplus4(Species *spec);
double ainterspinZnplus4ex(Species *spec);
double ainterspinZnplus4ex2(Species *spec);
double ainterspinZnplus5(Species *spec);
double ainterspinZnplus5ex(Species *spec);
double ainterspinZnplus5ex2(Species *spec);
double ainterspinZnplus6(Species *spec);
double ainterspinZnplus6ex(Species *spec);
double ainterspinZnplus6ex2(Species *spec);
double ainterspinZnplus7(Species *spec);
double ainterspinZnplus8(Species *spec);
double ainterspinZnplus9(Species *spec);
double ainterspinZnplus10(Species *spec);
double ainterspinZnplus10ex(Species *spec);
double ainterspinZnplus11(Species *spec);

double ainterspinZnneutrlex2(Species *spec);
double ainterspinZnplus1ex2(Species *spec);
double ainterspinZnplus2ex2(Species *spec);
double ainterspinZnplus3ex2(Species *spec);
double ainterspinZnplus4ex3(Species *spec);
double ainterspinZnplus5ex3(Species *spec);
double ainterspinZnplus6ex3(Species *spec);
double ainterspinZnplus7ex(Species *spec);
double ainterspinZnplus8ex(Species *spec);
double ainterspinZnplus9ex(Species *spec);

double ainterspinO_2(Species *spec);
double ainterspinO_1(Species *spec);
double ainterspinOneutrl(Species *spec);
double ainterspinOneutrlex(Species *spec);
double ainterspinOneutrlex2(Species *spec);
double ainterspinOplus1(Species *spec);
double ainterspinOplus1ex(Species *spec);
double ainterspinOplus1ex2(Species *spec);
double ainterspinOplus2(Species *spec);
double ainterspinOplus2ex(Species *spec);
double ainterspinOplus2ex2(Species *spec);
double ainterspinOplus3(Species *spec);
double ainterspinOplus3ex(Species *spec);
double ainterspinOplus4(Species *spec);
double ainterspinOplus4ex(Species *spec);
double ainterspinOplus5(Species *spec);

double ainterspinFeneutrl(Species *spec);
double ainterspinFeneutrlex(Species *spec);
double ainterspinFeneutrlex2(Species *spec);
double ainterspinFeneutrlex3(Species *spec);
double ainterspinFeplus1(Species *spec);
double ainterspinFeplus1ex(Species *spec);
double ainterspinFeplus1ex2(Species *spec);
double ainterspinFeplus2(Species *spec);
double ainterspinFeplus2ex(Species *spec);
double ainterspinFeplus2ex2(Species *spec);
double ainterspinFeplus3(Species *spec);
double ainterspinFeplus3ex(Species *spec);
double ainterspinFeplus3ex2(Species *spec);
double ainterspinFeplus4(Species *spec);
double ainterspinFeplus4ex(Species *spec);
double ainterspinFeplus4ex2(Species *spec);
double ainterspinFeplus5(Species *spec);
double ainterspinFeplus5ex(Species *spec);
double ainterspinFeplus6(Species *spec);
double ainterspinFeplus6ex(Species *spec);
double ainterspinFeplus7(Species *spec);

double ainterspinC_1(Species *spec);
double ainterspinCneutrl(Species *spec);
double ainterspinCneutrlex(Species *spec);
double ainterspinCneutrlex2(Species *spec);
double ainterspinCplus1(Species *spec);
double ainterspinCplus1ex(Species *spec);
double ainterspinCplus2(Species *spec);
double ainterspinCplus2ex(Species *spec);
double ainterspinCplus3(Species *spec);

double ainterspinNneutrl(Species *spec);
double ainterspinNneutrlex(Species *spec);
double ainterspinNneutrlex2(Species *spec);
double ainterspinNplus1(Species *spec);
double ainterspinNplus1ex(Species *spec);
double ainterspinNplus1ex2(Species *spec);
double ainterspinNplus2(Species *spec);
double ainterspinNplus2ex(Species *spec);
double ainterspinNplus3(Species *spec);
double ainterspinNplus3ex(Species *spec);
double ainterspinNplus4(Species *spec);

double ainterspinO2_linnett(Species *spec);
double ainterspinO2_snglbnd(Species *spec);
double ainterspinO2_dblbnd(Species *spec);
double ainterspinO2_trplbnd(Species *spec);
double ainterspinO2dia_linnett(Species *spec);
double ainterspinO2dia_snglbnd(Species *spec);
double ainterspinO2dia_dblbnd(Species *spec);
double ainterspinO2dia_trplbnd(Species *spec);
double ainterspinO2qnt_linnett(Species *spec);
double ainterspinO2qnt_snglbnd(Species *spec);
double ainterspinO2qnt_dblbnd(Species *spec);
double ainterspinO2qnt_trplbnd(Species *spec);
double ainterspinO3_linnett(Species *spec);
double ainterspinO3trp_linnett(Species *spec);

double ainterspinDielectron(Species *spec);
double ainterspinDielectronex(Species *spec);
