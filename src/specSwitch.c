
 /**************************************************************
 * Purpose:		   			  	       *
 * This program ainterSwitch.c is inteneded to consolidate     * 
 * structure minimization across al molecules. Previous to     *
 * water suite version 304.007 each molecule had a seperate    *
 * upnup"molecule_name".c file due to the novel coordinate     *
 * conversion between symmetry based and cartesian coordinates.*
 * This program aims to fix that by accessing the appropriate  *
 * ainter"molecule_name".c file in a generic minimization      *
 * routine. 						       *
 *							       *
 **************************************************************/
 
/***************************************************************
 * Arguments: Species
 * =============================================================
 * Variable    |  Type    | Purpose
 * ------------|----------|-------------------------------------   
 *  spec       | Species  | All information for a specific  
 *  	       |	  | molecular species is contained in
 *  	       |	  | this struct. For more detail see 
 *             |          | Structure.h where it is defined.
 * ------------|----------|-------------------------------------   
 *  molec      | MoName   | This is an Enum type which replaces
 *             |	  | all relevant species with a
 *             |	  | corresponding integer. This allows
 *             |	  | the switch statement to seemingly 
 *             |	  | match character strings.
 **************************************************************/

#include <stdio.h>
#include <string.h>
#include "Structure.h"
/* Copy and paste this format then add species
		case t_ : ainter(spec); break;
*/
void specSwitch(Species *spec){
	MoName molec = spec->type;
	switch (molec){
		// Diaelectron
		case Dielectron : specspinDielectron(spec); break;
		case Dielectronex : specspinDielectronex(spec); break;
		// H radical
//		case t_H : specspinH(spec); break;
//		case t_H_ : specspinH_(spec); break;
//		// Diatomic
//		case t_H2 : specspinH2(spec); break;
//		case t_H2trp : specspinH2trp(spec); break;
//
		case H: specspinH(spec); break;
		case H_: specspinH_(spec); break;
		case H2: specspinH2(spec); break;
		case H2trp: specspinH2trp(spec); break;
		case H2minus: specspinH2minus(spec); break;
		case H2plus: specspinH2plus(spec); break;
		case H3: specspinH3(spec); break;
		case H3plus: specspinH3plus(spec); break;
		case H3linear: specspinH3linear(spec); break;

		case Znneutrl : specspinZnneutrl(spec); break;
		case Znneutrlex : specspinZnneutrlex(spec); break;
		case Znneutrlex2 : specspinZnneutrlex2(spec); break;
		case Znplus1 : specspinZnplus1(spec); break;
		case Znplus1ex : specspinZnplus1ex(spec); break;
		case Znplus1ex2 : specspinZnplus1ex2(spec); break;
		case Znplus2 : specspinZnplus2(spec); break;
		case Znplus2ex : specspinZnplus2ex(spec); break;
		case Znplus2ex2 : specspinZnplus2ex2(spec); break;
		case Znplus3 : specspinZnplus3(spec); break;
		case Znplus3ex : specspinZnplus3ex(spec); break;
		case Znplus3ex2 : specspinZnplus3ex2(spec); break;
		case Znplus4 : specspinZnplus4(spec); break;
		case Znplus4ex : specspinZnplus4ex(spec); break;
		case Znplus4ex2 : specspinZnplus4ex2(spec); break;
		case Znplus4ex3 : specspinZnplus4ex3(spec); break;
		case Znplus5 : specspinZnplus5(spec); break;
		case Znplus5ex : specspinZnplus5ex(spec); break;
		case Znplus5ex2 : specspinZnplus5ex2(spec); break;
		case Znplus5ex3 : specspinZnplus5ex3(spec); break;
		case Znplus6 : specspinZnplus6(spec); break;
		case Znplus6ex : specspinZnplus6ex(spec); break;
		case Znplus6ex2 : specspinZnplus6ex2(spec); break;
		case Znplus6ex3 : specspinZnplus6ex3(spec); break;
		case Znplus7 : specspinZnplus7(spec); break;
		case Znplus7ex : specspinZnplus7ex(spec); break;
		case Znplus8 : specspinZnplus8(spec); break;
		case Znplus8ex : specspinZnplus8ex(spec); break;
		case Znplus9 : specspinZnplus9(spec); break;
		case Znplus9ex : specspinZnplus9ex(spec); break;
		case Znplus10 : specspinZnplus10(spec); break;
		case Znplus10ex : specspinZnplus10ex(spec); break;
		case Znplus11 : specspinZnplus11(spec); break;

		case Feneutrl : specspinFeneutrl(spec); break;
		case Feneutrlex : specspinFeneutrlex(spec); break;
		case Feneutrlex2 : specspinFeneutrlex2(spec); break;
		case Feneutrlex3 : specspinFeneutrlex3(spec); break;
		case Feplus1 : specspinFeplus1(spec); break;
		case Feplus1ex : specspinFeplus1ex(spec); break;
		case Feplus1ex2 : specspinFeplus1ex2(spec); break;
		case Feplus2 : specspinFeplus2(spec); break;
		case Feplus2ex : specspinFeplus2ex(spec); break;
		case Feplus2ex2 : specspinFeplus2ex2(spec); break;
		case Feplus3 : specspinFeplus3(spec); break;
		case Feplus3ex : specspinFeplus3ex(spec); break;
		case Feplus3ex2 : specspinFeplus3ex2(spec); break;
		case Feplus4 : specspinFeplus4(spec); break;
		case Feplus4ex : specspinFeplus4ex(spec); break;
		case Feplus4ex2 : specspinFeplus4ex2(spec); break;
		case Feplus5 : specspinFeplus5(spec); break;
		case Feplus5ex : specspinFeplus5ex(spec); break;
		case Feplus6 : specspinFeplus6(spec); break;
		case Feplus6ex : specspinFeplus6ex(spec); break;
		case Feplus7 : specspinFeplus7(spec); break;
		
		case O_2 : specspinO_2(spec); break;
		case O_1 : specspinO_1(spec); break;
		case Oneutrl : specspinOneutrl(spec); break;
		case Oneutrlex : specspinOneutrlex(spec); break;
		case Oneutrlex2 : specspinOneutrlex2(spec); break;
		case Oplus1 : specspinOplus1(spec); break;
		case Oplus1ex : specspinOplus1ex(spec); break;
		case Oplus1ex2 : specspinOplus1ex2(spec); break;
		case Oplus2 : specspinOplus2(spec); break;
		case Oplus2ex : specspinOplus2ex(spec); break;
		case Oplus2ex2 : specspinOplus2ex2(spec); break;
		case Oplus3 : specspinOplus3(spec); break;
		case Oplus3ex : specspinOplus3ex(spec); break;
		case Oplus4 : specspinOplus4(spec); break;
		case Oplus4ex : specspinOplus4ex(spec); break;
		case Oplus5 : specspinOplus5(spec); break;
		
		case O2_linnett : specspinO2_linnett(spec); break;
		case O2_snglbnd : specspinO2_snglbnd(spec); break;
		case O2_dblbnd : specspinO2_dblbnd(spec); break;
		case O2_trplbnd : specspinO2_trplbnd(spec); break;
		case O2dia_linnett : specspinO2dia_linnett(spec); break;
		case O2dia_snglbnd : specspinO2dia_snglbnd(spec); break;
		case O2dia_dblbnd : specspinO2dia_dblbnd(spec); break;
		case O2dia_trplbnd : specspinO2dia_trplbnd(spec); break;
		case O2qnt_linnett : specspinO2qnt_linnett(spec); break;
		case O2qnt_snglbnd : specspinO2qnt_snglbnd(spec); break;
		case O2qnt_dblbnd : specspinO2qnt_dblbnd(spec); break;
		case O2qnt_trplbnd : specspinO2qnt_trplbnd(spec); break;
		case O2plus1 : specspinO2plus1(spec); break;
		case O2_1 : specspinO2_1(spec); break;
		case O3_linnett : specspinO3_linnett(spec); break;
		case O3trp_linnett : specspinO3trp_linnett(spec); break;

		case C_1 : specspinC_1(spec); break;
		case Cneutrl : specspinCneutrl(spec); break;
		case Cneutrlex : specspinCneutrlex(spec); break;
		case Cneutrlex2 : specspinCneutrlex2(spec); break;
		case Cplus1 : specspinCplus1(spec); break;
		case Cplus1ex : specspinCplus1ex(spec); break;
		case Cplus2 : specspinCplus2(spec); break;
		case Cplus2ex : specspinCplus2ex(spec); break;
		case Cplus3 : specspinCplus3(spec); break;

//		case N_1 : specspinN_1(spec); break;
		case Nneutrl : specspinNneutrl(spec); break;
		case Nneutrlex : specspinNneutrlex(spec); break;
//		case Nneutrlex2 : specspinNneutrlex2(spec); break;
		case Nplus1 : specspinNplus1(spec); break;
		case Nplus1ex : specspinNplus1ex(spec); break;
		case Nplus1ex2 : specspinNplus1ex2(spec); break;
		case Nplus2 : specspinNplus2(spec); break;
		case Nplus2ex : specspinNplus2ex(spec); break;
		case Nplus3 : specspinNplus3(spec); break;
		case Nplus3ex : specspinNplus3ex(spec); break;
		case Nplus4 : specspinNplus4(spec); break;
		



/*		case t_H3plus : ainterH3plus(spec); break;
		case t_C2 : ainterC2(spec); break;
		case t_N2 : ainterN2(spec); break;
		case t_O2 : ainterO2(spec); break;
		case t_CO : ainterCO(spec); break;
		case t_O_2 : ainterO_2(spec); break;
		case t_O : ainterO(spec); break;
		// Single Carbon species
		case t_CH2 : ainterCH2(spec); break;
		case t_CH3 : ainterCH3(spec); break;
		case t_CH3cation : ainterCH3cation(spec); break;
		case t_CH4 : ainterCH4(spec); break;
		case t_CH5 : ainterCH5(spec); break;
		// Single Nitrogen species
		case t_NH2 : ainterNH2(spec); break;
		case t_NH3 : ainterNH3(spec); break;
		case t_NH4 : ainterNH4(spec); break;
		// Single Oxygen species
		case t_H2O : ainterH2O(spec); break;
		case t_H3O : ainterH3O(spec); break;
		case t_OH : ainterOH(spec); break;
		case t_H2OClosed : ainterH2OClosed(spec); break;
		case t_H2OOpen : ainterH2OOpen(spec); break;
		case t_H2OLong : ainterH2OLong(spec); break;
		case t_H2OShort : ainterH2OShort(spec); break;
		// CC species
		case t_C2H2 : ainterC2H2(spec); break;
		case t_C2H2single : ainterC2H2single(spec); break;
		case t_C2H3 : ainterC2H3(spec); break;
		case t_C2H4 : ainterC2H4(spec); break;
		case t_C2H5 : ainterC2H5(spec); break;
		case t_C2H5cation : ainterC2H5cation(spec); break;
		case t_C2H6 : ainterC2H6(spec); break;
		case t_C2H8 : ainterC2H8(spec); break;
		// NN
		case t_N2H2 : ainterN2H2(spec); break;
		case t_N2H3 : ainterN2H3(spec); break;
		case t_N2H4 : ainterN2H4(spec); break;
		case t_N2H5 : ainterN2H5(spec); break;
		case t_N2H6 : ainterN2H6(spec); break;
		case t_N2H7 : ainterN2H7(spec); break;
		case t_N2H : ainterN2H(spec); break;
		// OO
		case t_H2O2 : ainterH2O2(spec); break;
		case t_H3O2 : ainterH3O2(spec); break;
		// CN
		case t_CH2NH2 : ainterCH2NH2(spec); break;
		case t_CH2NH2ionic : ainterCH2NH2ionic(spec); break;
		case t_CH2NH : ainterCH2NH(spec); break;
		case t_CH3NH2 : ainterCH3NH2(spec); break;
		case t_CH3NH3 : ainterCH3NH3(spec); break;
		case t_CH3NH : ainterCH3NH(spec); break;
		case t_HCN : ainterHCN(spec); break;
		case t_HCNH : ainterHCNH(spec); break;
		case t_HCNsingle : ainterHCNsingle(spec); break;
		// CO
		case t_CH2O : ainterCH2O(spec); break;
		case t_CH2OH : ainterCH2OH(spec); break;
		case t_CH2OHionic : ainterCH2OHionic(spec); break;
		case t_CH3O : ainterCH3O(spec); break;
		case t_CH3OH2 : ainterCH3OH2(spec); break;
		case t_CH3OH : ainterCH3OH(spec); break;
		case t_CHO2 : ainterCHO2(spec); break;
		case t_CHOOH : ainterCHOOH(spec); break;
		case t_CHOOHcarbocationic : ainterCHOOHcarbocationic(spec); break;
		// NO
		case t_H2NO : ainterH2NO(spec); break;
		case t_H2NOionic : ainterH2NOionic(spec); break;
		case t_H2NOsingle : ainterH2NOsingle(spec); break;
		case t_HNO : ainterHNO(spec); break;
		case t_NH2O : ainterNH2O(spec); break;
		case t_NH2OH : ainterNH2OH(spec); break;
		// Dimers
		case t_dimer : ainterdimer(spec); break;
		case t_DeprotonatedDimer : ainterDeprotonatedDimer(spec); break;
		case t_TransitionDeprotonatedDimer : ainterTransitionDeprotonatedDimer(spec); break;
		case t_Transitiondimer : ainterTransitiondimer(spec); break;
		case t_TransitionStretchDimer : ainterTransitionStretchDimer(spec); break;
		case t_Zundel : ainterZundel(spec); break;
		case t_CH3OH_H2O : ainterCH3OH_H2O(spec); break;
		case t_CH4H2O : ainterCH4H2O(spec); break;
		case t_CH4H2S : ainterCH4H2S(spec); break;
		case t_CH4NH3 : ainterCH4NH3(spec); break;
		case t_NH3H2O : ainterNH3H2O(spec); break;
		case t_NH3OH : ainterNH3OH(spec); break;
		// Sulfer containing species
		case t_CH3S : ainterCH3S(spec); break;
		case t_CH3SH : ainterCH3SH(spec); break;
		case t_CH3SH2 : ainterCH3SH2(spec); break;
		case t_H2S2 : ainterH2S2(spec); break;
		case t_H2S : ainterH2S(spec); break;
		case t_H2SO4 : ainterH2SO4(spec); break;
		case t_H3S : ainterH3S(spec); break;
		case t_H4S2 : ainterH4S2(spec); break;
		case t_HOSH : ainterHOSH(spec); break;
		case t_NH2SH : ainterNH2SH(spec); break;
		// Other
		case t_CationH2O : ainterCationH2O(spec); break;
		case t_CH3dot : ainterCH3dot(spec); break;
		case t_C6H6 : ainterC6H6(spec); break;
*/
		default : printf("Invalid type to specSwitch()\n"); break;
	}
}
/* A function like this may be useful for defining Species->name 
  when only the enum type is given although it seems unlikely that it
  should be done with way since enum type MoName and the actual name
  could be set in the same location in the code  
*/
//void PrintType(MoName molec, int i){
//	char Name[50];
//	switch (molec){
//		// Diatomic
//		case t_H2 : strcpy(Name,"H2");break; 
//		case t_H3plus : strcpy(Name,"H3plus");break; 
//		case t_C2 : strcpy(Name,"C2");break; 
//		case t_N2 : strcpy(Name,"N2");break; 
//		case t_O2 : strcpy(Name,"O2");break; 
//		case t_CO : strcpy(Name,"CO");break; 
//		case t_H_ : strcpy(Name,"H_");break; 
//		case t_O_2 : strcpy(Name,"O_2");break; 
//		case t_O : strcpy(Name,"O");break; 
//		// Single Carbon species
//		case t_CH2 : strcpy(Name,"CH2");break; 
//		case t_CH3 : strcpy(Name,"CH3");break; 
//		case t_CH3cation : strcpy(Name,"CH3cation");break; 
//		case t_CH4 : strcpy(Name,"CH4");break; 
//		case t_CH5 : strcpy(Name,"CH5");break; 
//		// Single Nitrogen species
//		case t_NH2 : strcpy(Name,"NH2");break; 
//		case t_NH3 : strcpy(Name,"NH3");break; 
//		case t_NH4 : strcpy(Name,"NH4");break; 
//		// Single Oxygen species
//		case t_H2O : strcpy(Name,"H2O");break; 
//		case t_H3O : strcpy(Name,"H3O");break; 
//		case t_OH : strcpy(Name,"OH");break; 
//		case t_H2OClosed : strcpy(Name,"H2OClosed");break; 
//		case t_H2OOpen : strcpy(Name,"H2OOpen");break; 
//		case t_H2OLong : strcpy(Name,"H2OLong");break; 
//		case t_H2OShort : strcpy(Name,"H2OShort");break; 
//		// CC species
//		case t_C2H2 : strcpy(Name,"C2H2");break; 
//		case t_C2H2single : strcpy(Name,"C2H2single");break; 
//		case t_C2H3 : strcpy(Name,"C2H3");break; 
//		case t_C2H4 : strcpy(Name,"C2H4");break; 
//		case t_C2H5 : strcpy(Name,"C2H5");break; 
//		case t_C2H5cation : strcpy(Name,"C2H5cation");break; 
//		case t_C2H6 : strcpy(Name,"C2H6");break; 
//		case t_C2H8 : strcpy(Name,"C2H8");break; 
//		// NN
//		case t_N2H2 : strcpy(Name,"N2H2");break; 
//		case t_N2H3 : strcpy(Name,"N2H3");break; 
//		case t_N2H4 : strcpy(Name,"N2H4");break; 
//		case t_N2H5 : strcpy(Name,"N2H5");break; 
//		case t_N2H6 : strcpy(Name,"N2H6");break; 
//		case t_N2H7 : strcpy(Name,"N2H7");break; 
//		case t_N2H : strcpy(Name,"N2H");break; 
//		// OO
//		case t_H2O2 : strcpy(Name,"H2O2");break; 
//		case t_H3O2 : strcpy(Name,"H3O2");break; 
//		// CN
//		case t_CH2NH2 : strcpy(Name,"CH2NH2");break; 
//		case t_CH2NH2ionic : strcpy(Name,"CH2NH2ionic");break; 
//		case t_CH2NH : strcpy(Name,"CH2NH");break; 
//		case t_CH3NH2 : strcpy(Name,"CH3NH2");break; 
//		case t_CH3NH3 : strcpy(Name,"CH3NH3");break; 
//		case t_CH3NH : strcpy(Name,"CH3NH");break; 
//		case t_HCN : strcpy(Name,"HCN");break; 
//		case t_HCNH : strcpy(Name,"HCNH");break; 
//		case t_HCNsingle : strcpy(Name,"HCNsingle");break; 
//		// CO
//		case t_CH2O : strcpy(Name,"CH2O");break; 
//		case t_CH2OH : strcpy(Name,"CH2OH");break; 
//		case t_CH2OHionic : strcpy(Name,"CH2OHionic");break; 
//		case t_CH3O : strcpy(Name,"CH3O");break; 
//		case t_CH3OH2 : strcpy(Name,"CH3OH2");break; 
//		case t_CH3OH : strcpy(Name,"CH3OH");break; 
//		case t_CHO2 : strcpy(Name,"CHO2");break; 
//		case t_CHOOH : strcpy(Name,"CHOOH");break; 
//		case t_CHOOHcarbocationic : strcpy(Name,"CHOOHcarbocationic");break; 
//		// NO
//		case t_H2NO : strcpy(Name,"H2NO");break; 
//		case t_H2NOionic : strcpy(Name,"H2NOionic");break; 
//		case t_H2NOsingle : strcpy(Name,"H2NOsingle");break; 
//		case t_HNO : strcpy(Name,"HNO");break; 
//		case t_NH2O : strcpy(Name,"NH2O");break; 
//		case t_NH2OH : strcpy(Name,"NH2OH");break; 
//		// Dimers
//		case t_dimer : strcpy(Name,"dimer");break; 
//		case t_DeprotonatedDimer : strcpy(Name,"DeprotonatedDimer");break; 
//		case t_TransitionDeprotonatedDimer : strcpy(Name,"TransitionDeprotonatedDimer");break; 
//		case t_Transitiondimer : strcpy(Name,"Transitiondimer");break; 
//		case t_TransitionStretchDimer : strcpy(Name,"TransitionStretchDimer");break; 
//		case t_Zundel : strcpy(Name,"Zundel");break; 
//		case t_CH3OH_H2O : strcpy(Name,"CH3OH_H2O");break; 
//		case t_CH4H2O : strcpy(Name,"CH4H2O");break; 
//		case t_CH4H2S : strcpy(Name,"CH4H2S");break; 
//		case t_CH4NH3 : strcpy(Name,"CH4NH3");break; 
//		case t_NH3H2O : strcpy(Name,"NH3H2O");break; 
//		case t_NH3OH : strcpy(Name,"NH3OH");break; 
//		// Sulfer containing species
//		case t_CH3S : strcpy(Name,"CH3S");break; 
//		case t_CH3SH : strcpy(Name,"CH3SH");break; 
//		case t_CH3SH2 : strcpy(Name,"CH3SH2");break; 
//		case t_H2S2 : strcpy(Name,"H2S2");break; 
//		case t_H2S : strcpy(Name,"H2S");break; 
//		case t_H2SO4 : strcpy(Name,"H2SO4");break; 
//		case t_H3S : strcpy(Name,"H3S");break; 
//		case t_H4S2 : strcpy(Name,"H4S2");break; 
//		case t_HOSH : strcpy(Name,"HOSH");break; 
//		case t_NH2SH : strcpy(Name,"NH2SH");break; 
//		// Other
//		case t_CationH2O : strcpy(Name,"CationH2O");break; 
//		case t_CH3dot : strcpy(Name,"CH3dot");break; 
//		case t_C6H6 : strcpy(Name,"C6H6");break; 
//		case t_NumberOfTypes : printf("There are %d number of types\n",t_NumberOfTypes);strcpy(Name,"NumberOfTypes");break; 
//		default : printf("Invalid type to ainterSwitch()\n");
//	}
// 
//	printf("The structure is of type: %s \n", Name);
//	if(i==0){printf("Now running lowermain%s() ... \n\n", Name);}
//	else{printf("No lowermain%s() function defined yet... \n\n", Name);}
//}
//
//
