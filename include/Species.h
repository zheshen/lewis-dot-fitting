
typedef enum MoName{

	Dielectron, Dielectronex,
	// H radical
	H, H_,
	// Diatomic and Monoatomic
	H2, H2trp, H2minus, H2plus, H3, H3linear, H3plus,
	// C
	t_CH2, t_CH3, t_CH3cation, t_CH4, t_CH5,
	// N
	t_NH2, t_NH3, t_NH4,
	// O
	t_H2O, t_H3O, t_OH,t_H2OClosed, t_H2OOpen, t_H2OLong, t_H2OShort,
	// CC
	t_C2H2, t_C2H2single, t_C2H3, t_C2H4, t_C2H5, t_C2H5cation, t_C2H6, t_C2H8,
	// NN
	t_N2H2, t_N2H3, t_N2H4, t_N2H5, t_N2H6, t_N2H7, t_N2H,
	// OO
	t_H2O2, t_H3O2, 
	// CN
	t_CH2NH2, t_CH2NH2ionic, t_CH2NH, t_CH3NH2, t_CH3NH3, t_CH3NH, t_HCN, t_HCNH, t_HCNsingle, 
	// CO
	t_CH2O, t_CH2OH, t_CH2OHionic, t_CH3O, t_CH3OH2, t_CH3OH, t_CHO2, t_CHOOH, t_CHOOHcarbocationic,
	// NO
	t_H2NO, t_H2NOionic, t_H2NOsingle, t_HNO, t_NH2O, t_NH2OH,
	//Zn
	Znneutrl, Znneutrlex, Znplus1, Znplus1ex, Znplus2, Znplus2ex, Znplus3, Znplus3ex, Znplus4, Znplus4ex, Znplus4ex2, Znplus5, Znplus5ex, Znplus5ex2, Znplus6, Znplus6ex, Znplus6ex2, 
	Znplus7, Znplus8, Znplus9, Znplus10, Znplus10ex, Znplus11,
	Znneutrlex2, Znplus1ex2, Znplus2ex2, Znplus3ex2, Znplus4ex3, Znplus5ex3, Znplus6ex3, Znplus7ex, Znplus8ex, Znplus9ex,
	//Fe
	Feneutrl, Feneutrlex, Feneutrlex2, Feneutrlex3, Feplus1, Feplus1ex, Feplus1ex2, Feplus2, Feplus2ex, Feplus2ex2, Feplus3, Feplus3ex, Feplus3ex2, Feplus4, Feplus4ex, Feplus4ex2, 
	Feplus5, Feplus5ex, Feplus6, Feplus6ex, Feplus7,
	//O
	O_2, O_1, Oneutrl, Oneutrlex, Oneutrlex2, Oplus1, Oplus1ex, Oplus1ex2, Oplus2, Oplus2ex, Oplus2ex2, Oplus3, Oplus3ex, Oplus4, Oplus4ex, Oplus5,
	//O2
	O2, O2dia, O2qnt, O2_linnett, O2_snglbnd, O2_dblbnd, O2_trplbnd, O2dia_linnett, O2dia_snglbnd, O2dia_dblbnd, O2dia_trplbnd, O2qnt_linnett, O2qnt_snglbnd, O2qnt_dblbnd, O2qnt_trplbnd,
	//O3
	O3_linnett, O3trp_linnett,
	// Dimers
	t_dimer,
	t_DeprotonatedDimer,
	t_TransitionDeprotonatedDimer,
	t_Transitiondimer,
	t_TransitionStretchDimer,
	t_Zundel,
	//
	t_CH3OH_H2O,
	t_CH4H2O,
	t_CH4H2S,
	t_CH4NH3,
	t_NH3H2O,
	t_NH3OH,
	// All Sulfer Species
	t_H2S2, t_H2S, t_H3S, t_H4S2, t_SH,
	t_CH3S, t_CH3SH, t_CH3SH2,
	t_NH2SH,
	t_H2SO4, t_SO3, t_HOSH,
	// Other
	t_CationH2O, 
	t_CH3dot,
	t_C6H6,
	t_O,
	t_NumberOfTypes
}MoName;




