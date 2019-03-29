
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
	O2plus1, O2_1, O2, O2dia, O2qnt, O2_linnett, O2_snglbnd, O2_dblbnd, O2_trplbnd, O2dia_linnett, O2dia_snglbnd, O2dia_dblbnd, O2dia_trplbnd, O2qnt_linnett, O2qnt_snglbnd, O2qnt_dblbnd, O2qnt_trplbnd,
	//O3
	O3_linnett, O3trp_linnett,
	//C
	C_1, Cneutrl, Cneutrlex, Cneutrlex2, Cplus1, Cplus1ex, Cplus2, Cplus2ex, Cplus3, 
	//N
	N_1, Nneutrl, Nneutrlex, Nneutrlex2, Nplus1, Nplus1ex, Nplus1ex2, Nplus2, Nplus2ex, Nplus3, Nplus3ex, Nplus4, 
	

	N2_snglt, N2_trplt, N2_snglt_linnett, N2_snglt_snglbnd, N2_snglt_dblbnd, N2_snglt_trplbnd, N2_trplt_linnett, N2_trplt_snglbnd, N2_trplt_dblbnd, N2_trplt_trplbnd,

	C2_snglt, C2_trplt, C2_snglt_linnett, C2_snglt_snglbnd, C2_snglt_dblbnd, C2_snglt_trplbnd, C2_trplt_linnett, C2_trplt_snglbnd, C2_trplt_dblbnd, C2_trplt_trplbnd,

	B2_snglt, B2_trplt, B2_snglt_linnett, B2_snglt_snglbnd, B2_snglt_dblbnd, B2_snglt_trplbnd, B2_trplt_linnett, B2_trplt_snglbnd, B2_trplt_dblbnd, B2_trplt_trplbnd,

	F2_snglt, F2_trplt, F2_snglt_linnett, F2_snglt_snglbnd, F2_snglt_dblbnd, F2_snglt_trplbnd, F2_trplt_linnett, F2_trplt_snglbnd, F2_trplt_dblbnd, F2_trplt_trplbnd,

	Al2_snglt, Al2_trplt, Al2_snglt_linnett, Al2_snglt_snglbnd, Al2_snglt_dblbnd, Al2_snglt_trplbnd, Al2_trplt_linnett, Al2_trplt_snglbnd, Al2_trplt_dblbnd, Al2_trplt_trplbnd,

	Si2_snglt, Si2_trplt, Si2_snglt_linnett, Si2_snglt_snglbnd, Si2_snglt_dblbnd, Si2_snglt_trplbnd, Si2_trplt_linnett, Si2_trplt_snglbnd, Si2_trplt_dblbnd, Si2_trplt_trplbnd,

	P2_snglt, P2_trplt, P2_snglt_linnett, P2_snglt_snglbnd, P2_snglt_dblbnd, P2_snglt_trplbnd, P2_trplt_linnett, P2_trplt_snglbnd, P2_trplt_dblbnd, P2_trplt_trplbnd,

	S2_snglt, S2_trplt, S2_snglt_linnett, S2_snglt_snglbnd, S2_snglt_dblbnd, S2_snglt_trplbnd, S2_trplt_linnett, S2_trplt_snglbnd, S2_trplt_dblbnd, S2_trplt_trplbnd,

	Cl2_snglt, Cl2_trplt, Cl2_snglt_linnett, Cl2_snglt_snglbnd, Cl2_snglt_dblbnd, Cl2_snglt_trplbnd, Cl2_trplt_linnett, Cl2_trplt_snglbnd, Cl2_trplt_dblbnd, Cl2_trplt_trplbnd,

	Splus5, Splus4, Splus3, Splus2, Splus1, Sneutrl, S_1, Splus4ex, Splus3ex, Splus2ex, Splus2ex2, Splus1ex, Sneutrlex, Sneutrlex2, 
	Pplus4, Pplus3, Pplus2, Pplus1, Pneutrl, P_1, Pplus3ex, Pplus2ex, Pplus1ex, Pplus1ex2, Pneutrlex, 
	Siplus3, Siplus2, Siplus1, Sineutrl, Si_1, Siplus2ex, Siplus1ex, Sineutrlex, Sineutrlex2, 
	Fplus6, Fplus5, Fplus4, Fplus3, Fplus2, Fplus1, Fneutrl, F_1, Fplus5ex, Fplus4ex, Fplus3ex, Fplus3ex2, Fplus2ex, Fplus1ex, Fneutrlex, Fplus1ex2, Fplus2ex2, 
	Cl_1, Clneutrl, Clneutrlex, Clplus1ex2, Clplus1ex, Clplus1, Clplus2ex, Clplus2, Clplus3ex2, Clplus3ex, Clplus3, Clplus4ex, Clplus4, Clplus5ex, Clplus5, Clplus6, 
	Al_1, Alneutrlex, Alneutrl, Alplus1ex, Alplus1, Alplus2, 
	Li_1, Lineutrl, 
	Beneutrl, Beneutrlex, Beplus1, 
	Na_1, Naneutrl, 
	Mgneutrl, Mgneutrlex, Mgplus1, 
	Tiplus3, Tiplus2, Tiplus2ex, Tiplus1, Tiplus1ex, Tineutrl, Tineutrlex, Tineutrlex2, 
	Scplus2, Scplus1, Scplus1ex, Scneutrl, Scneutrlex, 
	Vplus4, Vplus3, Vplus3ex, Vplus2, Vplus2ex, Vplus1, Vplus1ex, Vplus1ex2, Vneutrl, Vneutrlex, Vneutrlex2, 
	Crplus5, Crplus4, Crplus4ex, Crplus3, Crplus3ex, Crplus2, Crplus2ex, Crplus2ex2, Crplus1, Crplus1ex, Crplus1ex2, Crneutrl, Crneutrlex, Crneutrlex2, Crneutrlex3, 
	Mnplus6, Mnplus5, Mnplus5ex, Mnplus4, Mnplus4ex, Mnplus3, Mnplus3ex, Mnplus2, Mnplus2ex, Mnplus2ex2, Mnplus1, Mnplus1ex, Mnplus1ex2, Mnplus1ex3, Mnneutrl, Mnneutrlex, Mnneutrlex2, Mnneutrlex3, 
	Coplus8, Coplus7, Coplus7ex, Coplus6, Coplus6ex, Coplus5, Coplus5ex, Coplus5ex2, Coplus4, Coplus4ex, Coplus4ex2, Coplus3, Coplus3ex, Coplus3ex2, Coplus2, Coplus2ex, Coplus2ex2, Coplus1, Coplus1ex, Coplus1ex2, Coneutrl, Coneutrlex, 
	Niplus9, Niplus8, Niplus8ex, Niplus7, Niplus7ex, Niplus6, Niplus6ex, Niplus5, Niplus5ex, Niplus5ex2, Niplus4, Niplus4ex, Niplus4ex2, Niplus3, Niplus3ex, Niplus3ex2, Niplus2, Niplus2ex, Niplus2ex2, Niplus1, Niplus1ex, Nineutrl, Nineutrlex, 
	Cuplus10, Cuplus9, Cuplus9ex, Cuplus8, Cuplus7, Cuplus6, Cuplus5, Cuplus5ex, Cuplus5ex2, Cuplus4, Cuplus4ex, Cuplus4ex2, Cuplus3, Cuplus3ex, Cuplus3ex2, Cuplus2, Cuplus2ex, Cuplus1, Cuplus1ex, Cuneutrl, Cuneutrlex, 
	Yneutrl, Yneutrlex, Yplus1, Yplus1ex, Yplus2, 
	Zrneutrl, Zrneutrlex, Zrneutrlex2, Zrplus1, Zrplus1ex, Zrplus2, Zrplus2ex, Zrplus3, 
	Nbplus4, Nbplus3, Nbplus3ex, Nbplus2, Nbplus2ex, Nbplus1, Nbplus1ex, Nbplus1ex2, Nbneutrl, Nbneutrlex, Nbneutrlex2, 
	Moplus5, Moplus4, Moplus4ex, Moplus3, Moplus3ex, Moplus2, Moplus2ex, Moplus2ex2, Moplus1, Moplus1ex, Moplus1ex2, Moneutrl, Moneutrlex, Moneutrlex2, Moneutrlex3, 
	Tcplus6, Tcplus5, Tcplus4, Tcplus3, Tcplus2, Tcplus1, Tcplus1ex, Tcneutrl, Tcneutrlex, Tcneutrlex2, Tcneutrlex3,  
	Ruplus7, Ruplus6, Ruplus5, Ruplus4, Ruplus3, Ruplus2, Ruplus2ex, Ruplus1, Ruplus1ex, Ruplus1ex2, Runeutrl, Runeutrlex, Runeutrlex2, 
	Rhplus8, Rhplus7, Rhplus6, Rhplus5, Rhplus4, Rhplus3, Rhplus2, Rhplus2ex, Rhplus2ex2, Rhplus1, Rhplus1ex, Rhplus1ex2, Rhneutrl, Rhneutrlex,
	Pdplus9, Pdplus8, Pdplus7, Pdplus6, Pdplus5, Pdplus4, Pdplus3, Pdplus2, Pdplus2ex, Pdplus2ex2, Pdplus1, Pdplus1ex, Pdneutrl, Pdneutrlex, 
	Agplus10, Agplus9, Agplus8, Agplus7, Agplus6, Agplus5, Agplus4, Agplus3, Agplus2, Agplus2ex, Agplus1, Agplus1ex, Agneutrl, Agneutrlex, 
	Cdplus11, Cdplus10, Cdplus9, Cdplus8, Cdplus7, Cdplus6, Cdplus5, Cdplus4, Cdplus3, Cdplus3ex, Cdplus2, Cdplus2ex, Cdplus2ex2, Cdplus1, Cdplus1ex, Cdneutrl, Cdneutrlex, 
	B_1, Bneutrlex, Bneutrl, Bplus1ex, Bplus1, Bplus2,

	
	
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




