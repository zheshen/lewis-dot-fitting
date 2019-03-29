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
double getSpinDipole(V *, int, double *, double *);
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
void setShape(V *, int);

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
void specspinFplus3ex2(Species *spec);
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
void specspinVplus1ex2(Species *spec);
void specspinVplus2(Species *spec);
void specspinVplus2ex(Species *spec);
void specspinVplus3(Species *spec);
void specspinVplus3ex(Species *spec);
void specspinVplus4(Species *spec);

void specspinCrneutrl(Species *spec);
void specspinCrneutrlex(Species *spec);
void specspinCrneutrlex2(Species *spec);
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

void specspinYneutrl(Species *spec);
void specspinYneutrlex(Species *spec);
void specspinYplus1(Species *spec);
void specspinYplus1ex(Species *spec);
void specspinYplus2(Species *spec);

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
void specspinO2plus1(Species *spec);
void specspinO2_1(Species *spec);
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

double devspinF_1(Species *spec);
double devspinFneutrl(Species *spec);
double devspinFneutrlex(Species *spec);
double devspinFplus1(Species *spec);
double devspinFplus1ex(Species *spec);
double devspinFplus1ex2(Species *spec);
double devspinFplus2(Species *spec);
double devspinFplus2ex(Species *spec);
double devspinFplus2ex2(Species *spec);
double devspinFplus3(Species *spec);
double devspinFplus3ex(Species *spec);
double devspinFplus3ex2(Species *spec);
double devspinFplus4(Species *spec);
double devspinFplus4ex(Species *spec);
double devspinFplus5(Species *spec);
double devspinFplus5ex(Species *spec);
double devspinFplus6(Species *spec);

double devspinSi_1(Species *spec);
double devspinSineutrl(Species *spec);
double devspinSineutrlex(Species *spec);
double devspinSineutrlex2(Species *spec);
double devspinSiplus1(Species *spec);
double devspinSiplus1ex(Species *spec);
double devspinSiplus2(Species *spec);
double devspinSiplus2ex(Species *spec);
double devspinSiplus3(Species *spec);

double devspinP_1(Species *spec);
double devspinPneutrl(Species *spec);
double devspinPneutrlex(Species *spec);
double devspinPplus1(Species *spec);
double devspinPplus1ex(Species *spec);
double devspinPplus1ex2(Species *spec);
double devspinPplus2(Species *spec);
double devspinPplus2ex(Species *spec);
double devspinPplus3(Species *spec);
double devspinPplus3ex(Species *spec);
double devspinPplus4(Species *spec);

double devspinS_1(Species *spec);
double devspinSneutrl(Species *spec);
double devspinSneutrlex(Species *spec);
double devspinSneutrlex2(Species *spec);
double devspinSplus1(Species *spec);
double devspinSplus1ex(Species *spec);
double devspinSplus2(Species *spec);
double devspinSplus2ex(Species *spec);
double devspinSplus2ex2(Species *spec);
double devspinSplus3(Species *spec);
double devspinSplus3ex(Species *spec);
double devspinSplus4(Species *spec);
double devspinSplus4ex(Species *spec);
double devspinSplus5(Species *spec);

double devspinB_1(Species *spec);
double devspinBneutrl(Species *spec);
double devspinBneutrlex(Species *spec);
double devspinBplus1(Species *spec);
double devspinBplus1ex(Species *spec);
double devspinBplus2(Species *spec);

double devspinCl_1(Species *spec);
double devspinClneutrl(Species *spec);
double devspinClneutrlex(Species *spec);
double devspinClplus1(Species *spec);
double devspinClplus1ex(Species *spec);
double devspinClplus1ex2(Species *spec);
double devspinClplus2(Species *spec);
double devspinClplus2ex(Species *spec);
double devspinClplus3(Species *spec);
double devspinClplus3ex(Species *spec);
double devspinClplus3ex2(Species *spec);
double devspinClplus4(Species *spec);
double devspinClplus4ex(Species *spec);
double devspinClplus5(Species *spec);
double devspinClplus5ex(Species *spec);
double devspinClplus6(Species *spec);

double devspinAl_1(Species *spec);
double devspinAlneutrl(Species *spec);
double devspinAlneutrlex(Species *spec);
double devspinAlplus1(Species *spec);
double devspinAlplus1ex(Species *spec);
double devspinAlplus2(Species *spec);

double devspinLi_1(Species *spec);
double devspinLineutrl(Species *spec);

double devspinBe_1(Species *spec);
double devspinBeneutrl(Species *spec);
double devspinBeneutrlex(Species *spec);
double devspinBeplus1(Species *spec);

double devspinNa_1(Species *spec);
double devspinNaneutrl(Species *spec);

double devspinMg_1(Species *spec);
double devspinMgneutrl(Species *spec);
double devspinMgneutrlex(Species *spec);
double devspinMgplus1(Species *spec);

double devspinScneutrl(Species *spec);
double devspinScneutrlex(Species *spec);
double devspinScplus1(Species *spec);
double devspinScplus1ex(Species *spec);
double devspinScplus2(Species *spec);

double devspinTineutrl(Species *spec);
double devspinTineutrlex(Species *spec);
double devspinTineutrlex2(Species *spec);
double devspinTiplus1(Species *spec);
double devspinTiplus1ex(Species *spec);
double devspinTiplus2(Species *spec);
double devspinTiplus2ex(Species *spec);
double devspinTiplus3(Species *spec);

double devspinVneutrl(Species *spec);
double devspinVneutrlex(Species *spec);
double devspinVneutrlex2(Species *spec);
double devspinVplus1(Species *spec);
double devspinVplus1ex(Species *spec);
double devspinVplus1ex2(Species *spec);
double devspinVplus2(Species *spec);
double devspinVplus2ex(Species *spec);
double devspinVplus3(Species *spec);
double devspinVplus3ex(Species *spec);
double devspinVplus4(Species *spec);

double devspinCrneutrl(Species *spec);
double devspinCrneutrlex(Species *spec);
double devspinCrneutrlex2(Species *spec);
double devspinCrplus1(Species *spec);
double devspinCrplus1ex(Species *spec);
double devspinCrplus1ex2(Species *spec);
double devspinCrplus2(Species *spec);
double devspinCrplus2ex(Species *spec);
double devspinCrplus2ex2(Species *spec);
double devspinCrplus3(Species *spec);
double devspinCrplus3ex(Species *spec);
double devspinCrplus4(Species *spec);
double devspinCrplus4ex(Species *spec);
double devspinCrplus5(Species *spec);

double devspinMnneutrl(Species *spec);
double devspinMnneutrlex(Species *spec);
double devspinMnneutrlex2(Species *spec);
double devspinMnplus1(Species *spec);
double devspinMnplus1ex(Species *spec);
double devspinMnplus1ex2(Species *spec);
double devspinMnplus2(Species *spec);
double devspinMnplus2ex(Species *spec);
double devspinMnplus2ex2(Species *spec);
double devspinMnplus3(Species *spec);
double devspinMnplus3ex(Species *spec);
double devspinMnplus4(Species *spec);
double devspinMnplus4ex(Species *spec);
double devspinMnplus5(Species *spec);
double devspinMnplus5ex(Species *spec);
double devspinMnplus6(Species *spec);

double devspinConeutrl(Species *spec);
double devspinConeutrlex(Species *spec);
double devspinCoplus1(Species *spec);
double devspinCoplus1ex(Species *spec);
double devspinCoplus1ex2(Species *spec);
double devspinCoplus2(Species *spec);
double devspinCoplus2ex(Species *spec);
double devspinCoplus2ex2(Species *spec);
double devspinCoplus3(Species *spec);
double devspinCoplus3ex(Species *spec);
double devspinCoplus3ex2(Species *spec);
double devspinCoplus4(Species *spec);
double devspinCoplus4ex(Species *spec);
double devspinCoplus4ex2(Species *spec);
double devspinCoplus5(Species *spec);
double devspinCoplus5ex(Species *spec);
double devspinCoplus5ex2(Species *spec);
double devspinCoplus6(Species *spec);
double devspinCoplus6ex(Species *spec);
double devspinCoplus7(Species *spec);
double devspinCoplus7ex(Species *spec);
double devspinCoplus8(Species *spec);

double devspinNineutrl(Species *spec);
double devspinNineutrlex(Species *spec);
double devspinNiplus1(Species *spec);
double devspinNiplus1ex(Species *spec);
double devspinNiplus2(Species *spec);
double devspinNiplus2ex(Species *spec);
double devspinNiplus2ex2(Species *spec);
double devspinNiplus3(Species *spec);
double devspinNiplus3ex(Species *spec);
double devspinNiplus3ex2(Species *spec);
double devspinNiplus4(Species *spec);
double devspinNiplus4ex(Species *spec);
double devspinNiplus4ex2(Species *spec);
double devspinNiplus5(Species *spec);
double devspinNiplus5ex(Species *spec);
double devspinNiplus5ex2(Species *spec);
double devspinNiplus6(Species *spec);
double devspinNiplus6ex(Species *spec);
double devspinNiplus7(Species *spec);
double devspinNiplus7ex(Species *spec);
double devspinNiplus8(Species *spec);
double devspinNiplus8ex(Species *spec);
double devspinNiplus9(Species *spec);

double devspinCuneutrl(Species *spec);
double devspinCuneutrlex(Species *spec);
double devspinCuplus1(Species *spec);
double devspinCuplus1ex(Species *spec);
double devspinCuplus2(Species *spec);
double devspinCuplus2ex(Species *spec);
double devspinCuplus3(Species *spec);
double devspinCuplus3ex(Species *spec);
double devspinCuplus3ex2(Species *spec);
double devspinCuplus4(Species *spec);
double devspinCuplus4ex(Species *spec);
double devspinCuplus4ex2(Species *spec);
double devspinCuplus5(Species *spec);
double devspinCuplus5ex(Species *spec);
double devspinCuplus5ex2(Species *spec);
double devspinCuplus6(Species *spec);
double devspinCuplus7(Species *spec);
double devspinCuplus8(Species *spec);
double devspinCuplus9(Species *spec);
double devspinCuplus9ex(Species *spec);
double devspinCuplus10(Species *spec);

double devspinYneutrl(Species *spec);
double devspinYneutrlex(Species *spec);
double devspinYplus1(Species *spec);
double devspinYplus1ex(Species *spec);
double devspinYplus2(Species *spec);

double devspinZrneutrl(Species *spec);
double devspinZrneutrlex(Species *spec);
double devspinZrneutrlex2(Species *spec);
double devspinZrplus1(Species *spec);
double devspinZrplus1ex(Species *spec);
double devspinZrplus2(Species *spec);
double devspinZrplus2ex(Species *spec);
double devspinZrplus3(Species *spec);

//
//double devspinH(Species *spec);
//double devspinH_(Species *spec);
//double devspinH2(Species *spec);
//double devspinH2trp(Species *spec);
//double devspinH2plus(Species *spec);
//double devspinH2minus(Species *spec);
//double devspinH3(Species *spec);
//double devspinH3plus(Species *spec);
//double devspinH3linear(Species *spec);
//
//double devspinZnneutrl(Species *spec);
//double devspinZnneutrlex(Species *spec);
//double devspinZnplus1(Species *spec);
//double devspinZnplus1ex(Species *spec);
//double devspinZnplus2(Species *spec);
//double devspinZnplus2ex(Species *spec);
//double devspinZnplus3(Species *spec);
//double devspinZnplus3ex(Species *spec);
//double devspinZnplus4(Species *spec);
//double devspinZnplus4ex(Species *spec);
//double devspinZnplus4ex2(Species *spec);
//double devspinZnplus5(Species *spec);
//double devspinZnplus5ex(Species *spec);
//double devspinZnplus5ex2(Species *spec);
//double devspinZnplus6(Species *spec);
//double devspinZnplus6ex(Species *spec);
//double devspinZnplus6ex2(Species *spec);
//double devspinZnplus7(Species *spec);
//double devspinZnplus8(Species *spec);
//double devspinZnplus9(Species *spec);
//double devspinZnplus10(Species *spec);
//double devspinZnplus10ex(Species *spec);
//double devspinZnplus11(Species *spec);
//
//double devspinZnneutrlex2(Species *spec);
//double devspinZnplus1ex2(Species *spec);
//double devspinZnplus2ex2(Species *spec);
//double devspinZnplus3ex2(Species *spec);
//double devspinZnplus4ex3(Species *spec);
//double devspinZnplus5ex3(Species *spec);
//double devspinZnplus6ex3(Species *spec);
//double devspinZnplus7ex(Species *spec);
//double devspinZnplus8ex(Species *spec);
//double devspinZnplus9ex(Species *spec);
//
//double devspinO_2(Species *spec);
//double devspinO_1(Species *spec);
//double devspinOneutrl(Species *spec);
//double devspinOneutrlex(Species *spec);
//double devspinOneutrlex2(Species *spec);
//double devspinOplus1(Species *spec);
//double devspinOplus1ex(Species *spec);
//double devspinOplus1ex2(Species *spec);
//double devspinOplus2(Species *spec);
//double devspinOplus2ex(Species *spec);
//double devspinOplus2ex2(Species *spec);
//double devspinOplus3(Species *spec);
//double devspinOplus3ex(Species *spec);
//double devspinOplus4(Species *spec);
//double devspinOplus4ex(Species *spec);
//double devspinOplus5(Species *spec);
//
//double devspinFeneutrl(Species *spec);
//double devspinFeneutrlex(Species *spec);
//double devspinFeneutrlex2(Species *spec);
//double devspinFeneutrlex3(Species *spec);
//double devspinFeplus1(Species *spec);
//double devspinFeplus1ex(Species *spec);
//double devspinFeplus1ex2(Species *spec);
//double devspinFeplus2(Species *spec);
//double devspinFeplus2ex(Species *spec);
//double devspinFeplus2ex2(Species *spec);
//double devspinFeplus3(Species *spec);
//double devspinFeplus3ex(Species *spec);
//double devspinFeplus3ex2(Species *spec);
//double devspinFeplus4(Species *spec);
//double devspinFeplus4ex(Species *spec);
//double devspinFeplus4ex2(Species *spec);
//double devspinFeplus5(Species *spec);
//double devspinFeplus5ex(Species *spec);
//double devspinFeplus6(Species *spec);
//double devspinFeplus6ex(Species *spec);
//double devspinFeplus7(Species *spec);
//
//double devspinC_1(Species *spec);
//double devspinCneutrl(Species *spec);
//double devspinCneutrlex(Species *spec);
//double devspinCneutrlex2(Species *spec);
//double devspinCplus1(Species *spec);
//double devspinCplus1ex(Species *spec);
//double devspinCplus2(Species *spec);
//double devspinCplus2ex(Species *spec);
//double devspinCplus3(Species *spec);
//
//double devspinNneutrl(Species *spec);
//double devspinNneutrlex(Species *spec);
//double devspinNneutrlex2(Species *spec);
//double devspinNplus1(Species *spec);
//double devspinNplus1ex(Species *spec);
//double devspinNplus1ex2(Species *spec);
//double devspinNplus2(Species *spec);
//double devspinNplus2ex(Species *spec);
//double devspinNplus3(Species *spec);
//double devspinNplus3ex(Species *spec);
//double devspinNplus4(Species *spec);
//
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
double devspinO2plus1(Species *spec);
double devspinO2_1(Species *spec);
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

double ainterspinF_1(Species *spec);
double ainterspinFneutrl(Species *spec);
double ainterspinFneutrlex(Species *spec);
double ainterspinFplus1(Species *spec);
double ainterspinFplus1ex(Species *spec);
double ainterspinFplus1ex2(Species *spec);
double ainterspinFplus2(Species *spec);
double ainterspinFplus2ex(Species *spec);
double ainterspinFplus2ex2(Species *spec);
double ainterspinFplus3(Species *spec);
double ainterspinFplus3ex(Species *spec);
double ainterspinFplus3ex2(Species *spec);
double ainterspinFplus4(Species *spec);
double ainterspinFplus4ex(Species *spec);
double ainterspinFplus5(Species *spec);
double ainterspinFplus5ex(Species *spec);
double ainterspinFplus6(Species *spec);

double ainterspinSi_1(Species *spec);
double ainterspinSineutrl(Species *spec);
double ainterspinSineutrlex(Species *spec);
double ainterspinSineutrlex2(Species *spec);
double ainterspinSiplus1(Species *spec);
double ainterspinSiplus1ex(Species *spec);
double ainterspinSiplus2(Species *spec);
double ainterspinSiplus2ex(Species *spec);
double ainterspinSiplus3(Species *spec);

double ainterspinP_1(Species *spec);
double ainterspinPneutrl(Species *spec);
double ainterspinPneutrlex(Species *spec);
double ainterspinPplus1(Species *spec);
double ainterspinPplus1ex(Species *spec);
double ainterspinPplus1ex2(Species *spec);
double ainterspinPplus2(Species *spec);
double ainterspinPplus2ex(Species *spec);
double ainterspinPplus3(Species *spec);
double ainterspinPplus3ex(Species *spec);
double ainterspinPplus4(Species *spec);

double ainterspinS_1(Species *spec);
double ainterspinSneutrl(Species *spec);
double ainterspinSneutrlex(Species *spec);
double ainterspinSneutrlex2(Species *spec);
double ainterspinSplus1(Species *spec);
double ainterspinSplus1ex(Species *spec);
double ainterspinSplus2(Species *spec);
double ainterspinSplus2ex(Species *spec);
double ainterspinSplus2ex2(Species *spec);
double ainterspinSplus3(Species *spec);
double ainterspinSplus3ex(Species *spec);
double ainterspinSplus4(Species *spec);
double ainterspinSplus4ex(Species *spec);
double ainterspinSplus5(Species *spec);

double ainterspinB_1(Species *spec);
double ainterspinBneutrl(Species *spec);
double ainterspinBneutrlex(Species *spec);
double ainterspinBplus1(Species *spec);
double ainterspinBplus1ex(Species *spec);
double ainterspinBplus2(Species *spec);

double ainterspinCl_1(Species *spec);
double ainterspinClneutrl(Species *spec);
double ainterspinClneutrlex(Species *spec);
double ainterspinClplus1(Species *spec);
double ainterspinClplus1ex(Species *spec);
double ainterspinClplus1ex2(Species *spec);
double ainterspinClplus2(Species *spec);
double ainterspinClplus2ex(Species *spec);
double ainterspinClplus3(Species *spec);
double ainterspinClplus3ex(Species *spec);
double ainterspinClplus3ex2(Species *spec);
double ainterspinClplus4(Species *spec);
double ainterspinClplus4ex(Species *spec);
double ainterspinClplus5(Species *spec);
double ainterspinClplus5ex(Species *spec);
double ainterspinClplus6(Species *spec);

double ainterspinAl_1(Species *spec);
double ainterspinAlneutrl(Species *spec);
double ainterspinAlneutrlex(Species *spec);
double ainterspinAlplus1(Species *spec);
double ainterspinAlplus1ex(Species *spec);
double ainterspinAlplus2(Species *spec);

double ainterspinLi_1(Species *spec);
double ainterspinLineutrl(Species *spec);

double ainterspinBe_1(Species *spec);
double ainterspinBeneutrl(Species *spec);
double ainterspinBeneutrlex(Species *spec);
double ainterspinBeplus1(Species *spec);

double ainterspinNa_1(Species *spec);
double ainterspinNaneutrl(Species *spec);

double ainterspinMg_1(Species *spec);
double ainterspinMgneutrl(Species *spec);
double ainterspinMgneutrlex(Species *spec);
double ainterspinMgplus1(Species *spec);

double ainterspinScneutrl(Species *spec);
double ainterspinScneutrlex(Species *spec);
double ainterspinScplus1(Species *spec);
double ainterspinScplus1ex(Species *spec);
double ainterspinScplus2(Species *spec);

double ainterspinTineutrl(Species *spec);
double ainterspinTineutrlex(Species *spec);
double ainterspinTineutrlex2(Species *spec);
double ainterspinTiplus1(Species *spec);
double ainterspinTiplus1ex(Species *spec);
double ainterspinTiplus2(Species *spec);
double ainterspinTiplus2ex(Species *spec);
double ainterspinTiplus3(Species *spec);

double ainterspinVneutrl(Species *spec);
double ainterspinVneutrlex(Species *spec);
double ainterspinVneutrlex2(Species *spec);
double ainterspinVplus1(Species *spec);
double ainterspinVplus1ex(Species *spec);
double ainterspinVplus1ex2(Species *spec);
double ainterspinVplus2(Species *spec);
double ainterspinVplus2ex(Species *spec);
double ainterspinVplus3(Species *spec);
double ainterspinVplus3ex(Species *spec);
double ainterspinVplus4(Species *spec);

double ainterspinCrneutrl(Species *spec);
double ainterspinCrneutrlex(Species *spec);
double ainterspinCrneutrlex2(Species *spec);
double ainterspinCrplus1(Species *spec);
double ainterspinCrplus1ex(Species *spec);
double ainterspinCrplus1ex2(Species *spec);
double ainterspinCrplus2(Species *spec);
double ainterspinCrplus2ex(Species *spec);
double ainterspinCrplus2ex2(Species *spec);
double ainterspinCrplus3(Species *spec);
double ainterspinCrplus3ex(Species *spec);
double ainterspinCrplus4(Species *spec);
double ainterspinCrplus4ex(Species *spec);
double ainterspinCrplus5(Species *spec);

double ainterspinMnneutrl(Species *spec);
double ainterspinMnneutrlex(Species *spec);
double ainterspinMnneutrlex2(Species *spec);
double ainterspinMnplus1(Species *spec);
double ainterspinMnplus1ex(Species *spec);
double ainterspinMnplus1ex2(Species *spec);
double ainterspinMnplus2(Species *spec);
double ainterspinMnplus2ex(Species *spec);
double ainterspinMnplus2ex2(Species *spec);
double ainterspinMnplus3(Species *spec);
double ainterspinMnplus3ex(Species *spec);
double ainterspinMnplus4(Species *spec);
double ainterspinMnplus4ex(Species *spec);
double ainterspinMnplus5(Species *spec);
double ainterspinMnplus5ex(Species *spec);
double ainterspinMnplus6(Species *spec);

double ainterspinConeutrl(Species *spec);
double ainterspinConeutrlex(Species *spec);
double ainterspinCoplus1(Species *spec);
double ainterspinCoplus1ex(Species *spec);
double ainterspinCoplus1ex2(Species *spec);
double ainterspinCoplus2(Species *spec);
double ainterspinCoplus2ex(Species *spec);
double ainterspinCoplus2ex2(Species *spec);
double ainterspinCoplus3(Species *spec);
double ainterspinCoplus3ex(Species *spec);
double ainterspinCoplus3ex2(Species *spec);
double ainterspinCoplus4(Species *spec);
double ainterspinCoplus4ex(Species *spec);
double ainterspinCoplus4ex2(Species *spec);
double ainterspinCoplus5(Species *spec);
double ainterspinCoplus5ex(Species *spec);
double ainterspinCoplus5ex2(Species *spec);
double ainterspinCoplus6(Species *spec);
double ainterspinCoplus6ex(Species *spec);
double ainterspinCoplus7(Species *spec);
double ainterspinCoplus7ex(Species *spec);
double ainterspinCoplus8(Species *spec);

double ainterspinNineutrl(Species *spec);
double ainterspinNineutrlex(Species *spec);
double ainterspinNiplus1(Species *spec);
double ainterspinNiplus1ex(Species *spec);
double ainterspinNiplus2(Species *spec);
double ainterspinNiplus2ex(Species *spec);
double ainterspinNiplus2ex2(Species *spec);
double ainterspinNiplus3(Species *spec);
double ainterspinNiplus3ex(Species *spec);
double ainterspinNiplus3ex2(Species *spec);
double ainterspinNiplus4(Species *spec);
double ainterspinNiplus4ex(Species *spec);
double ainterspinNiplus4ex2(Species *spec);
double ainterspinNiplus5(Species *spec);
double ainterspinNiplus5ex(Species *spec);
double ainterspinNiplus5ex2(Species *spec);
double ainterspinNiplus6(Species *spec);
double ainterspinNiplus6ex(Species *spec);
double ainterspinNiplus7(Species *spec);
double ainterspinNiplus7ex(Species *spec);
double ainterspinNiplus8(Species *spec);
double ainterspinNiplus8ex(Species *spec);
double ainterspinNiplus9(Species *spec);

double ainterspinCuneutrl(Species *spec);
double ainterspinCuneutrlex(Species *spec);
double ainterspinCuplus1(Species *spec);
double ainterspinCuplus1ex(Species *spec);
double ainterspinCuplus2(Species *spec);
double ainterspinCuplus2ex(Species *spec);
double ainterspinCuplus3(Species *spec);
double ainterspinCuplus3ex(Species *spec);
double ainterspinCuplus3ex2(Species *spec);
double ainterspinCuplus4(Species *spec);
double ainterspinCuplus4ex(Species *spec);
double ainterspinCuplus4ex2(Species *spec);
double ainterspinCuplus5(Species *spec);
double ainterspinCuplus5ex(Species *spec);
double ainterspinCuplus5ex2(Species *spec);
double ainterspinCuplus6(Species *spec);
double ainterspinCuplus7(Species *spec);
double ainterspinCuplus8(Species *spec);
double ainterspinCuplus9(Species *spec);
double ainterspinCuplus9ex(Species *spec);
double ainterspinCuplus10(Species *spec);

double ainterspinYneutrl(Species *spec);
double ainterspinYneutrlex(Species *spec);
double ainterspinYplus1(Species *spec);
double ainterspinYplus1ex(Species *spec);
double ainterspinYplus2(Species *spec);

double ainterspinZrneutrl(Species *spec);
double ainterspinZrneutrlex(Species *spec);
double ainterspinZrneutrlex2(Species *spec);
double ainterspinZrplus1(Species *spec);
double ainterspinZrplus1ex(Species *spec);
double ainterspinZrplus2(Species *spec);
double ainterspinZrplus2ex(Species *spec);
double ainterspinZrplus3(Species *spec);


//double ainterspinH(Species *spec);
//double ainterspinH_(Species *spec);
//double ainterspinH2(Species *spec);
//double ainterspinH2trp(Species *spec);
//double ainterspinH2plus(Species *spec);
//double ainterspinH2minus(Species *spec);
//double ainterspinH3(Species *spec);
//double ainterspinH3plus(Species *spec);
//double ainterspinH3linear(Species *spec);
//
//double ainterspinZnneutrl(Species *spec);
//double ainterspinZnneutrlex(Species *spec);
//double ainterspinZnplus1(Species *spec);
//double ainterspinZnplus1ex(Species *spec);
//double ainterspinZnplus2(Species *spec);
//double ainterspinZnplus2ex(Species *spec);
//double ainterspinZnplus3(Species *spec);
//double ainterspinZnplus3ex(Species *spec);
//double ainterspinZnplus4(Species *spec);
//double ainterspinZnplus4ex(Species *spec);
//double ainterspinZnplus4ex2(Species *spec);
//double ainterspinZnplus5(Species *spec);
//double ainterspinZnplus5ex(Species *spec);
//double ainterspinZnplus5ex2(Species *spec);
//double ainterspinZnplus6(Species *spec);
//double ainterspinZnplus6ex(Species *spec);
//double ainterspinZnplus6ex2(Species *spec);
//double ainterspinZnplus7(Species *spec);
//double ainterspinZnplus8(Species *spec);
//double ainterspinZnplus9(Species *spec);
//double ainterspinZnplus10(Species *spec);
//double ainterspinZnplus10ex(Species *spec);
//double ainterspinZnplus11(Species *spec);
//
//double ainterspinZnneutrlex2(Species *spec);
//double ainterspinZnplus1ex2(Species *spec);
//double ainterspinZnplus2ex2(Species *spec);
//double ainterspinZnplus3ex2(Species *spec);
//double ainterspinZnplus4ex3(Species *spec);
//double ainterspinZnplus5ex3(Species *spec);
//double ainterspinZnplus6ex3(Species *spec);
//double ainterspinZnplus7ex(Species *spec);
//double ainterspinZnplus8ex(Species *spec);
//double ainterspinZnplus9ex(Species *spec);
//
//double ainterspinO_2(Species *spec);
//double ainterspinO_1(Species *spec);
//double ainterspinOneutrl(Species *spec);
//double ainterspinOneutrlex(Species *spec);
//double ainterspinOneutrlex2(Species *spec);
//double ainterspinOplus1(Species *spec);
//double ainterspinOplus1ex(Species *spec);
//double ainterspinOplus1ex2(Species *spec);
//double ainterspinOplus2(Species *spec);
//double ainterspinOplus2ex(Species *spec);
//double ainterspinOplus2ex2(Species *spec);
//double ainterspinOplus3(Species *spec);
//double ainterspinOplus3ex(Species *spec);
//double ainterspinOplus4(Species *spec);
//double ainterspinOplus4ex(Species *spec);
//double ainterspinOplus5(Species *spec);
//
//double ainterspinFeneutrl(Species *spec);
//double ainterspinFeneutrlex(Species *spec);
//double ainterspinFeneutrlex2(Species *spec);
//double ainterspinFeneutrlex3(Species *spec);
//double ainterspinFeplus1(Species *spec);
//double ainterspinFeplus1ex(Species *spec);
//double ainterspinFeplus1ex2(Species *spec);
//double ainterspinFeplus2(Species *spec);
//double ainterspinFeplus2ex(Species *spec);
//double ainterspinFeplus2ex2(Species *spec);
//double ainterspinFeplus3(Species *spec);
//double ainterspinFeplus3ex(Species *spec);
//double ainterspinFeplus3ex2(Species *spec);
//double ainterspinFeplus4(Species *spec);
//double ainterspinFeplus4ex(Species *spec);
//double ainterspinFeplus4ex2(Species *spec);
//double ainterspinFeplus5(Species *spec);
//double ainterspinFeplus5ex(Species *spec);
//double ainterspinFeplus6(Species *spec);
//double ainterspinFeplus6ex(Species *spec);
//double ainterspinFeplus7(Species *spec);
//
//double ainterspinC_1(Species *spec);
//double ainterspinCneutrl(Species *spec);
//double ainterspinCneutrlex(Species *spec);
//double ainterspinCneutrlex2(Species *spec);
//double ainterspinCplus1(Species *spec);
//double ainterspinCplus1ex(Species *spec);
//double ainterspinCplus2(Species *spec);
//double ainterspinCplus2ex(Species *spec);
//double ainterspinCplus3(Species *spec);
//
//double ainterspinNneutrl(Species *spec);
//double ainterspinNneutrlex(Species *spec);
//double ainterspinNneutrlex2(Species *spec);
//double ainterspinNplus1(Species *spec);
//double ainterspinNplus1ex(Species *spec);
//double ainterspinNplus1ex2(Species *spec);
//double ainterspinNplus2(Species *spec);
//double ainterspinNplus2ex(Species *spec);
//double ainterspinNplus3(Species *spec);
//double ainterspinNplus3ex(Species *spec);
//double ainterspinNplus4(Species *spec);
//
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
double ainterspinO2plus1(Species *spec);
double ainterspinO2_1(Species *spec);
double ainterspinO3_linnett(Species *spec);
double ainterspinO3trp_linnett(Species *spec);

double ainterspinDielectron(Species *spec);
double ainterspinDielectronex(Species *spec);

void specspinN2_snglt_linnett(Species *spec);
void specspinN2_snglt_snglbnd(Species *spec);
void specspinN2_snglt_dblbnd(Species *spec);
void specspinN2_snglt_trplbnd(Species *spec);
void specspinN2_trplt_linnett(Species *spec);
void specspinN2_trplt_snglbnd(Species *spec);
void specspinN2_trplt_dblbnd(Species *spec);
void specspinN2_trplt_trplbnd(Species *spec);

double devspinN2_snglt_linnett(Species *spec);
double devspinN2_snglt_snglbnd(Species *spec);
double devspinN2_snglt_dblbnd(Species *spec);
double devspinN2_snglt_trplbnd(Species *spec);
double devspinN2_trplt_linnett(Species *spec);
double devspinN2_trplt_snglbnd(Species *spec);
double devspinN2_trplt_dblbnd(Species *spec);
double devspinN2_trplt_trplbnd(Species *spec);

double ainterspinN2_snglt_linnett(Species *spec);
double ainterspinN2_snglt_snglbnd(Species *spec);
double ainterspinN2_snglt_dblbnd(Species *spec);
double ainterspinN2_snglt_trplbnd(Species *spec);
double ainterspinN2_trplt_linnett(Species *spec);
double ainterspinN2_trplt_snglbnd(Species *spec);
double ainterspinN2_trplt_dblbnd(Species *spec);
double ainterspinN2_trplt_trplbnd(Species *spec);

void specspinC2_snglt_linnett(Species *spec);
void specspinC2_snglt_snglbnd(Species *spec);
void specspinC2_snglt_dblbnd(Species *spec);
void specspinC2_snglt_trplbnd(Species *spec);
void specspinC2_trplt_linnett(Species *spec);
void specspinC2_trplt_snglbnd(Species *spec);
void specspinC2_trplt_dblbnd(Species *spec);
void specspinC2_trplt_trplbnd(Species *spec);

double devspinC2_snglt_linnett(Species *spec);
double devspinC2_snglt_snglbnd(Species *spec);
double devspinC2_snglt_dblbnd(Species *spec);
double devspinC2_snglt_trplbnd(Species *spec);
double devspinC2_trplt_linnett(Species *spec);
double devspinC2_trplt_snglbnd(Species *spec);
double devspinC2_trplt_dblbnd(Species *spec);
double devspinC2_trplt_trplbnd(Species *spec);

double ainterspinC2_snglt_linnett(Species *spec);
double ainterspinC2_snglt_snglbnd(Species *spec);
double ainterspinC2_snglt_dblbnd(Species *spec);
double ainterspinC2_snglt_trplbnd(Species *spec);
double ainterspinC2_trplt_linnett(Species *spec);
double ainterspinC2_trplt_snglbnd(Species *spec);
double ainterspinC2_trplt_dblbnd(Species *spec);
double ainterspinC2_trplt_trplbnd(Species *spec);


void specspinB2_snglt_linnett(Species *spec);
void specspinB2_snglt_snglbnd(Species *spec);
void specspinB2_snglt_dblbnd(Species *spec);
void specspinB2_snglt_trplbnd(Species *spec);
void specspinB2_trplt_linnett(Species *spec);
void specspinB2_trplt_snglbnd(Species *spec);
void specspinB2_trplt_dblbnd(Species *spec);
void specspinB2_trplt_trplbnd(Species *spec);

double devspinB2_snglt_linnett(Species *spec);
double devspinB2_snglt_snglbnd(Species *spec);
double devspinB2_snglt_dblbnd(Species *spec);
double devspinB2_snglt_trplbnd(Species *spec);
double devspinB2_trplt_linnett(Species *spec);
double devspinB2_trplt_snglbnd(Species *spec);
double devspinB2_trplt_dblbnd(Species *spec);
double devspinB2_trplt_trplbnd(Species *spec);

double ainterspinB2_snglt_linnett(Species *spec);
double ainterspinB2_snglt_snglbnd(Species *spec);
double ainterspinB2_snglt_dblbnd(Species *spec);
double ainterspinB2_snglt_trplbnd(Species *spec);
double ainterspinB2_trplt_linnett(Species *spec);
double ainterspinB2_trplt_snglbnd(Species *spec);
double ainterspinB2_trplt_dblbnd(Species *spec);
double ainterspinB2_trplt_trplbnd(Species *spec);

void specspinF2_snglt_linnett(Species *spec);
void specspinF2_snglt_snglbnd(Species *spec);
void specspinF2_snglt_dblbnd(Species *spec);
void specspinF2_snglt_trplbnd(Species *spec);
void specspinF2_trplt_linnett(Species *spec);
void specspinF2_trplt_snglbnd(Species *spec);
void specspinF2_trplt_dblbnd(Species *spec);
void specspinF2_trplt_trplbnd(Species *spec);

double devspinF2_snglt_linnett(Species *spec);
double devspinF2_snglt_snglbnd(Species *spec);
double devspinF2_snglt_dblbnd(Species *spec);
double devspinF2_snglt_trplbnd(Species *spec);
double devspinF2_trplt_linnett(Species *spec);
double devspinF2_trplt_snglbnd(Species *spec);
double devspinF2_trplt_dblbnd(Species *spec);
double devspinF2_trplt_trplbnd(Species *spec);

double ainterspinF2_snglt_linnett(Species *spec);
double ainterspinF2_snglt_snglbnd(Species *spec);
double ainterspinF2_snglt_dblbnd(Species *spec);
double ainterspinF2_snglt_trplbnd(Species *spec);
double ainterspinF2_trplt_linnett(Species *spec);
double ainterspinF2_trplt_snglbnd(Species *spec);
double ainterspinF2_trplt_dblbnd(Species *spec);
double ainterspinF2_trplt_trplbnd(Species *spec);

void specspinAl2_snglt_linnett(Species *spec);
void specspinAl2_snglt_snglbnd(Species *spec);
void specspinAl2_snglt_dblbnd(Species *spec);
void specspinAl2_snglt_trplbnd(Species *spec);
void specspinAl2_trplt_linnett(Species *spec);
void specspinAl2_trplt_snglbnd(Species *spec);
void specspinAl2_trplt_dblbnd(Species *spec);
void specspinAl2_trplt_trplbnd(Species *spec);

double devspinAl2_snglt_linnett(Species *spec);
double devspinAl2_snglt_snglbnd(Species *spec);
double devspinAl2_snglt_dblbnd(Species *spec);
double devspinAl2_snglt_trplbnd(Species *spec);
double devspinAl2_trplt_linnett(Species *spec);
double devspinAl2_trplt_snglbnd(Species *spec);
double devspinAl2_trplt_dblbnd(Species *spec);
double devspinAl2_trplt_trplbnd(Species *spec);

double ainterspinAl2_snglt_linnett(Species *spec);
double ainterspinAl2_snglt_snglbnd(Species *spec);
double ainterspinAl2_snglt_dblbnd(Species *spec);
double ainterspinAl2_snglt_trplbnd(Species *spec);
double ainterspinAl2_trplt_linnett(Species *spec);
double ainterspinAl2_trplt_snglbnd(Species *spec);
double ainterspinAl2_trplt_dblbnd(Species *spec);
double ainterspinAl2_trplt_trplbnd(Species *spec);

void specspinSi2_snglt_linnett(Species *spec);
void specspinSi2_snglt_snglbnd(Species *spec);
void specspinSi2_snglt_dblbnd(Species *spec);
void specspinSi2_snglt_trplbnd(Species *spec);
void specspinSi2_trplt_linnett(Species *spec);
void specspinSi2_trplt_snglbnd(Species *spec);
void specspinSi2_trplt_dblbnd(Species *spec);
void specspinSi2_trplt_trplbnd(Species *spec);

double devspinSi2_snglt_linnett(Species *spec);
double devspinSi2_snglt_snglbnd(Species *spec);
double devspinSi2_snglt_dblbnd(Species *spec);
double devspinSi2_snglt_trplbnd(Species *spec);
double devspinSi2_trplt_linnett(Species *spec);
double devspinSi2_trplt_snglbnd(Species *spec);
double devspinSi2_trplt_dblbnd(Species *spec);
double devspinSi2_trplt_trplbnd(Species *spec);

double ainterspinSi2_snglt_linnett(Species *spec);
double ainterspinSi2_snglt_snglbnd(Species *spec);
double ainterspinSi2_snglt_dblbnd(Species *spec);
double ainterspinSi2_snglt_trplbnd(Species *spec);
double ainterspinSi2_trplt_linnett(Species *spec);
double ainterspinSi2_trplt_snglbnd(Species *spec);
double ainterspinSi2_trplt_dblbnd(Species *spec);
double ainterspinSi2_trplt_trplbnd(Species *spec);

void specspinP2_snglt_linnett(Species *spec);
void specspinP2_snglt_snglbnd(Species *spec);
void specspinP2_snglt_dblbnd(Species *spec);
void specspinP2_snglt_trplbnd(Species *spec);
void specspinP2_trplt_linnett(Species *spec);
void specspinP2_trplt_snglbnd(Species *spec);
void specspinP2_trplt_dblbnd(Species *spec);
void specspinP2_trplt_trplbnd(Species *spec);

double devspinP2_snglt_linnett(Species *spec);
double devspinP2_snglt_snglbnd(Species *spec);
double devspinP2_snglt_dblbnd(Species *spec);
double devspinP2_snglt_trplbnd(Species *spec);
double devspinP2_trplt_linnett(Species *spec);
double devspinP2_trplt_snglbnd(Species *spec);
double devspinP2_trplt_dblbnd(Species *spec);
double devspinP2_trplt_trplbnd(Species *spec);

double ainterspinP2_snglt_linnett(Species *spec);
double ainterspinP2_snglt_snglbnd(Species *spec);
double ainterspinP2_snglt_dblbnd(Species *spec);
double ainterspinP2_snglt_trplbnd(Species *spec);
double ainterspinP2_trplt_linnett(Species *spec);
double ainterspinP2_trplt_snglbnd(Species *spec);
double ainterspinP2_trplt_dblbnd(Species *spec);
double ainterspinP2_trplt_trplbnd(Species *spec);

void specspinS2_snglt_linnett(Species *spec);
void specspinS2_snglt_snglbnd(Species *spec);
void specspinS2_snglt_dblbnd(Species *spec);
void specspinS2_snglt_trplbnd(Species *spec);
void specspinS2_trplt_linnett(Species *spec);
void specspinS2_trplt_snglbnd(Species *spec);
void specspinS2_trplt_dblbnd(Species *spec);
void specspinS2_trplt_trplbnd(Species *spec);

double devspinS2_snglt_linnett(Species *spec);
double devspinS2_snglt_snglbnd(Species *spec);
double devspinS2_snglt_dblbnd(Species *spec);
double devspinS2_snglt_trplbnd(Species *spec);
double devspinS2_trplt_linnett(Species *spec);
double devspinS2_trplt_snglbnd(Species *spec);
double devspinS2_trplt_dblbnd(Species *spec);
double devspinS2_trplt_trplbnd(Species *spec);

double ainterspinS2_snglt_linnett(Species *spec);
double ainterspinS2_snglt_snglbnd(Species *spec);
double ainterspinS2_snglt_dblbnd(Species *spec);
double ainterspinS2_snglt_trplbnd(Species *spec);
double ainterspinS2_trplt_linnett(Species *spec);
double ainterspinS2_trplt_snglbnd(Species *spec);
double ainterspinS2_trplt_dblbnd(Species *spec);
double ainterspinS2_trplt_trplbnd(Species *spec);

void specspinCl2_snglt_linnett(Species *spec);
void specspinCl2_snglt_snglbnd(Species *spec);
void specspinCl2_snglt_dblbnd(Species *spec);
void specspinCl2_snglt_trplbnd(Species *spec);
void specspinCl2_trplt_linnett(Species *spec);
void specspinCl2_trplt_snglbnd(Species *spec);
void specspinCl2_trplt_dblbnd(Species *spec);
void specspinCl2_trplt_trplbnd(Species *spec);

double devspinCl2_snglt_linnett(Species *spec);
double devspinCl2_snglt_snglbnd(Species *spec);
double devspinCl2_snglt_dblbnd(Species *spec);
double devspinCl2_snglt_trplbnd(Species *spec);
double devspinCl2_trplt_linnett(Species *spec);
double devspinCl2_trplt_snglbnd(Species *spec);
double devspinCl2_trplt_dblbnd(Species *spec);
double devspinCl2_trplt_trplbnd(Species *spec);

double ainterspinCl2_snglt_linnett(Species *spec);
double ainterspinCl2_snglt_snglbnd(Species *spec);
double ainterspinCl2_snglt_dblbnd(Species *spec);
double ainterspinCl2_snglt_trplbnd(Species *spec);
double ainterspinCl2_trplt_linnett(Species *spec);
double ainterspinCl2_trplt_snglbnd(Species *spec);
double ainterspinCl2_trplt_dblbnd(Species *spec);
double ainterspinCl2_trplt_trplbnd(Species *spec);

