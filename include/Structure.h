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
