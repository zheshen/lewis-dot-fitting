#include "Common.h"
double spinthermo(){
	extern char directory[];
	extern int print;

	double prod[50];
	char plot[250];
	extern int debug;
	double maxi_float(double, double);

        extern double U_spinH3linear;
        extern double U_spinH3trig;
        extern double U_spinH4linear;
        extern double U_spinH4square;
        extern double U_spinH4tetra;

	extern double U_spinO2qnt;
        extern double U_spinO2_linnett;
        extern double U_spinO2dia_linnett;
        extern double U_spinO2qnt_linnett;
        extern double U_spinO2_snglbnd;
        extern double U_spinO2dia_snglbnd;
        extern double U_spinO2qnt_snglbnd;
        extern double U_spinO2_dblbnd;
        extern double U_spinO2dia_dblbnd;
        extern double U_spinO2qnt_dblbnd;
        extern double U_spinO2_trplbnd;
        extern double U_spinO2dia_trplbnd;
        extern double U_spinO2qnt_trplbnd;
	extern double U_spinO3_linnett;
	extern double U_spinO3trp_linnett;
	
	extern double U_spinB2_trplt;
	extern double U_spinB2_snglt;
	extern double U_spinC2_trplt;
	extern double U_spinC2_snglt;
	extern double U_spinSi2_trplt;
	extern double U_spinSi2_snglt;
	extern double U_spinN2_trplt;
	extern double U_spinN2_snglt;
	extern double U_spinS2_trplt;
	extern double U_spinS2_snglt;
	extern double U_spinF2_trplt;
	extern double U_spinF2_snglt;
	extern double U_spinCl2_trplt;
	extern double U_spinCl2_snglt;
	extern double U_spinAl2_trplt;
	extern double U_spinAl2_snglt;
	extern double U_spinP2_trplt;
	extern double U_spinP2_snglt;

	extern double U_spinLi_1;
	extern double U_spinLineutrl;
	extern double U_spinBeneutrl;
	extern double U_spinBeneutrlex;
	extern double U_spinBeplus1;
	extern double U_spinNa_1;
	extern double U_spinNaneutrl;
	extern double U_spinMgneutrl;
	extern double U_spinMgneutrlex;
	extern double U_spinMgplus1;

	extern double U_spinH2trp;
	extern double U_spinH3plus;
	extern double U_spinH3;
	extern double U_spinH4;
	extern double U_spinH2minus;

	extern double U_spinCl_1;
	extern double U_spinClneutrlex;
	extern double U_spinClneutrl;
	extern double U_spinClplus1ex2;
	extern double U_spinClplus1ex;
	extern double U_spinClplus1;
	extern double U_spinClplus2ex;
	extern double U_spinClplus2;
	extern double U_spinClplus3ex2;
	extern double U_spinClplus3ex;
	extern double U_spinClplus3;
	extern double U_spinClplus4ex;
	extern double U_spinClplus4;
	extern double U_spinClplus5ex;
	extern double U_spinClplus5;
	extern double U_spinClplus6;
	extern double U_spinAl_1;
	extern double U_spinAlneutrlex;
	extern double U_spinAlneutrl;
	extern double U_spinAlplus1ex;
	extern double U_spinAlplus1;
	extern double U_spinAlplus2;

	extern double U_spinB_1;
	extern double U_spinBneutrlex;
	extern double U_spinBneutrl;
	extern double U_spinBplus1ex;
	extern double U_spinBplus1;
	extern double U_spinBplus2;

	extern double U_spinOneutrlex2;
	extern double U_spinOplus1ex2;
	extern double U_spinNneutrlex2;
	extern double U_spinFneutrlex;
	extern double U_spinFplus1ex2;
	extern double U_spinFplus2ex2;
	extern double U_spinSneutrlex2;

	extern double U_spinCplus2ex;
	extern double U_spinCplus1ex;
	extern double U_spinCneutrlex;
	extern double U_spinCneutrlex2;
	extern double U_spinNplus3ex;
	extern double U_spinNplus2ex;
	extern double U_spinNplus1ex;
	extern double U_spinNplus1ex2;
	extern double U_spinNneutrlex;
	extern double U_spinFplus5ex;
	extern double U_spinFplus4ex;
	extern double U_spinFplus3ex;
	extern double U_spinFplus3ex2;
	extern double U_spinFplus2ex;
	extern double U_spinFplus1ex;
	extern double U_spinSiplus2ex;
	extern double U_spinSiplus1ex;
	extern double U_spinSineutrlex;
	extern double U_spinSineutrlex2;
	extern double U_spinPplus3ex;
	extern double U_spinPplus2ex;
	extern double U_spinPplus1ex;
	extern double U_spinPplus1ex2;
	extern double U_spinPneutrlex;
	extern double U_spinSplus4ex;
	extern double U_spinSplus3ex;
	extern double U_spinSplus2ex;
	extern double U_spinSplus2ex2;
	extern double U_spinSplus1ex;
	extern double U_spinSneutrlex;

	extern double U_spinH2;
	extern double U_spinH_;
//	extern double U_spinH_trp;
	extern double U_spinH;
//	extern double U_spinH2O;
//	extern double U_spinOH;
//	extern double U_spinH3O;
	extern double U_spinO_2;
	extern double U_spinH2plus;
//	extern double U_spinOHdot;

	extern double U_spinOneutrl;
	extern double U_spinO_1;
	extern double U_spinOplus1;
	extern double U_spinOplus2;
	extern double U_spinO2;
	extern double U_spinO2dia;
	extern double U_spinO2plus1;
	extern double U_spinO2_1;
	extern double U_spinO2_2;
//	extern double U_spinH2Oplus;
//	extern double U_spindimer;
	extern double U_spinOplus3;
	extern double U_spinOplus4;
	extern double U_spinOplus5;
	extern double U_spinOneutrlex;
	extern double U_spinOplus2ex;
	extern double U_spinOplus2ex2;
	extern double U_spinOplus1ex;
	extern double U_spinOplus3ex;
	extern double U_spinOplus4ex;

	extern double U_spinCplus3;
	extern double U_spinCplus2;
	extern double U_spinCplus1;
	extern double U_spinCneutrl;
	extern double U_spinC_1;
	extern double U_spinNplus4;
	extern double U_spinNplus3;
	extern double U_spinNplus2;
	extern double U_spinNplus1;
	extern double U_spinNneutrl;
	extern double U_spinN_1;
	extern double U_spinSplus5;
	extern double U_spinSplus4;
	extern double U_spinSplus3;
	extern double U_spinSplus2;
	extern double U_spinSplus1;
	extern double U_spinSneutrl;
	extern double U_spinS_1;
	extern double U_spinPplus4;
	extern double U_spinPplus3;
	extern double U_spinPplus2;
	extern double U_spinPplus1;
	extern double U_spinPneutrl;
	extern double U_spinP_1;
	extern double U_spinSiplus3;
	extern double U_spinSiplus2;
	extern double U_spinSiplus1;
	extern double U_spinSineutrl;
	extern double U_spinSi_1;
	extern double U_spinFplus6;
	extern double U_spinFplus5;
	extern double U_spinFplus4;
	extern double U_spinFplus3;
	extern double U_spinFplus2;
	extern double U_spinFplus1;
	extern double U_spinFneutrl;
	extern double U_spinF_1;

	extern double U_spinScplus2;
	extern double U_spinScplus1;
	extern double U_spinScplus1ex;
	extern double U_spinScneutrl;
	extern double U_spinScneutrlex;
	extern double U_spinTiplus3;
	extern double U_spinTiplus2;
	extern double U_spinTiplus2ex;
	extern double U_spinTiplus1;
	extern double U_spinTiplus1ex;
	extern double U_spinTineutrl;
	extern double U_spinTineutrlex;
	extern double U_spinTineutrlex2;
	extern double U_spinVplus4;
	extern double U_spinVplus3;
	extern double U_spinVplus3ex;
	extern double U_spinVplus2;
	extern double U_spinVplus2ex;
	extern double U_spinVplus1;
	extern double U_spinVplus1ex;
	extern double U_spinVplus1ex2;
	extern double U_spinVneutrl;
	extern double U_spinVneutrlex;
	extern double U_spinVneutrlex2;
	extern double U_spinCrplus5;
	extern double U_spinCrplus4;
	extern double U_spinCrplus4ex;
	extern double U_spinCrplus3;
	extern double U_spinCrplus3ex;
	extern double U_spinCrplus2;
	extern double U_spinCrplus2ex;
	extern double U_spinCrplus2ex2;
	extern double U_spinCrplus1;
	extern double U_spinCrplus1ex;
	extern double U_spinCrplus1ex2;
	extern double U_spinCrneutrl;
	extern double U_spinCrneutrlex;
	extern double U_spinCrneutrlex2;
	extern double U_spinCrneutrlex3;
	extern double U_spinMnplus6;
	extern double U_spinMnplus5;
	extern double U_spinMnplus5ex;
	extern double U_spinMnplus4;
	extern double U_spinMnplus4ex;
	extern double U_spinMnplus3;
	extern double U_spinMnplus3ex;
	extern double U_spinMnplus2;
	extern double U_spinMnplus2ex;
	extern double U_spinMnplus2ex2;
	extern double U_spinMnplus1;
	extern double U_spinMnplus1ex;
	extern double U_spinMnplus1ex2;
	extern double U_spinMnplus1ex3;
	extern double U_spinMnneutrl;
	extern double U_spinMnneutrlex;
	extern double U_spinMnneutrlex2;
	extern double U_spinMnneutrlex3;
	extern double U_spinFeplus7;
	extern double U_spinFeplus6;
	extern double U_spinFeplus6ex;
	extern double U_spinFeplus5;
	extern double U_spinFeplus5ex;
	extern double U_spinFeplus4;
	extern double U_spinFeplus4ex;
	extern double U_spinFeplus4ex2;
	extern double U_spinFeplus3;
	extern double U_spinFeplus3ex;
	extern double U_spinFeplus3ex2;
	extern double U_spinFeplus2;
	extern double U_spinFeplus2ex;
	extern double U_spinFeplus2ex2;
	extern double U_spinFeplus1;
	extern double U_spinFeplus1ex;
	extern double U_spinFeplus1ex2;
	extern double U_spinFeneutrl;
	extern double U_spinFeneutrlex;
	extern double U_spinFeneutrlex2;
	extern double U_spinFeneutrlex3;
	extern double U_spinCoplus8;
	extern double U_spinCoplus7;
	extern double U_spinCoplus7ex;
	extern double U_spinCoplus6;
	extern double U_spinCoplus6ex;
	extern double U_spinCoplus5;
	extern double U_spinCoplus5ex;
	extern double U_spinCoplus5ex2;
	extern double U_spinCoplus4;
	extern double U_spinCoplus4ex;
	extern double U_spinCoplus4ex2;
	extern double U_spinCoplus3;
	extern double U_spinCoplus3ex;
	extern double U_spinCoplus3ex2;
	extern double U_spinCoplus2;
	extern double U_spinCoplus2ex;
	extern double U_spinCoplus2ex2;
	extern double U_spinCoplus1;
	extern double U_spinCoplus1ex;
	extern double U_spinCoplus1ex2;
	extern double U_spinConeutrl;
	extern double U_spinConeutrlex;
	extern double U_spinNiplus9;
	extern double U_spinNiplus8;
	extern double U_spinNiplus8ex;
	extern double U_spinNiplus7;
	extern double U_spinNiplus7ex;
	extern double U_spinNiplus6;
	extern double U_spinNiplus6ex;
	extern double U_spinNiplus5;
	extern double U_spinNiplus5ex;
	extern double U_spinNiplus5ex2;
	extern double U_spinNiplus4;
	extern double U_spinNiplus4ex;
	extern double U_spinNiplus4ex2;
	extern double U_spinNiplus3;
	extern double U_spinNiplus3ex;
	extern double U_spinNiplus3ex2;
	extern double U_spinNiplus2;
	extern double U_spinNiplus2ex;
	extern double U_spinNiplus2ex2;
	extern double U_spinNiplus1;
	extern double U_spinNiplus1ex;
	extern double U_spinNineutrl;
	extern double U_spinNineutrlex;
	extern double U_spinCuplus10;
	extern double U_spinCuplus9;
	extern double U_spinCuplus9ex;
	extern double U_spinCuplus8;
	extern double U_spinCuplus7;
	extern double U_spinCuplus6;
	extern double U_spinCuplus5;
	extern double U_spinCuplus5ex;
	extern double U_spinCuplus5ex2;
	extern double U_spinCuplus4;
	extern double U_spinCuplus4ex;
	extern double U_spinCuplus4ex2;
	extern double U_spinCuplus3;
	extern double U_spinCuplus3ex;
	extern double U_spinCuplus3ex2;
	extern double U_spinCuplus2;
	extern double U_spinCuplus2ex;
	extern double U_spinCuplus1;
	extern double U_spinCuplus1ex;
	extern double U_spinCuneutrl;
	extern double U_spinCuneutrlex;
	extern double U_spinZnplus11;
	extern double U_spinZnplus10;
	extern double U_spinZnplus10ex;
	extern double U_spinZnplus9;
	extern double U_spinZnplus9ex;
	extern double U_spinZnplus8;
	extern double U_spinZnplus8ex;
	extern double U_spinZnplus7;
	extern double U_spinZnplus7ex;
	extern double U_spinZnplus6;
	extern double U_spinZnplus6ex;
	extern double U_spinZnplus6ex2;
	extern double U_spinZnplus6ex3;
	extern double U_spinZnplus5;
	extern double U_spinZnplus5ex;
	extern double U_spinZnplus5ex2;
	extern double U_spinZnplus5ex3;
	extern double U_spinZnplus4;
	extern double U_spinZnplus4ex;
	extern double U_spinZnplus4ex2;
	extern double U_spinZnplus4ex3;
	extern double U_spinZnplus3;
	extern double U_spinZnplus3ex;
	extern double U_spinZnplus3ex2;
	extern double U_spinZnplus2;
	extern double U_spinZnplus2ex;
	extern double U_spinZnplus2ex2;
	extern double U_spinZnplus1;
	extern double U_spinZnplus1ex;
	extern double U_spinZnplus1ex2;
	extern double U_spinZnneutrl;
	extern double U_spinZnneutrlex;
	extern double U_spinZnneutrlex2;
	extern double U_spinYplus2;
	extern double U_spinYplus1;
	extern double U_spinYplus1ex;
	extern double U_spinYneutrl;
	extern double U_spinYneutrlex;
	extern double U_spinZrplus3;
	extern double U_spinZrplus2;
	extern double U_spinZrplus2ex;
	extern double U_spinZrplus1;
	extern double U_spinZrplus1ex;
	extern double U_spinZrneutrl;
	extern double U_spinZrneutrlex;
	extern double U_spinZrneutrlex2;
	extern double U_spinNbplus4;
	extern double U_spinNbplus3;
	extern double U_spinNbplus3ex;
	extern double U_spinNbplus2;
	extern double U_spinNbplus2ex;
	extern double U_spinNbplus1;
	extern double U_spinNbplus1ex;
	extern double U_spinNbplus1ex2;
	extern double U_spinNbneutrl;
	extern double U_spinNbneutrlex;
	extern double U_spinNbneutrlex2;
	extern double U_spinMoplus5;
	extern double U_spinMoplus4;
	extern double U_spinMoplus4ex;
	extern double U_spinMoplus3;
	extern double U_spinMoplus3ex;
	extern double U_spinMoplus2;
	extern double U_spinMoplus2ex;
	extern double U_spinMoplus2ex2;
	extern double U_spinMoplus1;
	extern double U_spinMoplus1ex;
	extern double U_spinMoplus1ex2;
	extern double U_spinMoneutrl;
	extern double U_spinMoneutrlex;
	extern double U_spinMoneutrlex2;
	extern double U_spinMoneutrlex3;
	extern double U_spinTcplus6;
	extern double U_spinTcplus5;
	extern double U_spinTcplus4;
	extern double U_spinTcplus3;
	extern double U_spinTcplus2;
	extern double U_spinTcplus1;
	extern double U_spinTcplus1ex;
	extern double U_spinTcneutrl;
	extern double U_spinTcneutrlex;
	extern double U_spinTcneutrlex2;
	extern double U_spinTcneutrlex3;
	extern double U_spinRuplus7;
	extern double U_spinRuplus6;
	extern double U_spinRuplus5;
	extern double U_spinRuplus4;
	extern double U_spinRuplus3;
	extern double U_spinRuplus2;
	extern double U_spinRuplus2ex;
	extern double U_spinRuplus1;
	extern double U_spinRuplus1ex;
	extern double U_spinRuplus1ex2;
	extern double U_spinRuneutrl;
	extern double U_spinRuneutrlex;
	extern double U_spinRuneutrlex2;
	extern double U_spinRhplus8;
	extern double U_spinRhplus7;
	extern double U_spinRhplus6;
	extern double U_spinRhplus5;
	extern double U_spinRhplus4;
	extern double U_spinRhplus3;
	extern double U_spinRhplus2;
	extern double U_spinRhplus2ex;
	extern double U_spinRhplus2ex2;
	extern double U_spinRhplus1;
	extern double U_spinRhplus1ex;
	extern double U_spinRhplus1ex2;
	extern double U_spinRhneutrl;
	extern double U_spinRhneutrlex;
	extern double U_spinPdplus9;
	extern double U_spinPdplus8;
	extern double U_spinPdplus7;
	extern double U_spinPdplus6;
	extern double U_spinPdplus5;
	extern double U_spinPdplus4;
	extern double U_spinPdplus3;
	extern double U_spinPdplus2;
	extern double U_spinPdplus2ex;
	extern double U_spinPdplus2ex2;
	extern double U_spinPdplus1;
	extern double U_spinPdplus1ex;
	extern double U_spinPdneutrl;
	extern double U_spinPdneutrlex;
	extern double U_spinAgplus10;
	extern double U_spinAgplus9;
	extern double U_spinAgplus8;
	extern double U_spinAgplus7;
	extern double U_spinAgplus6;
	extern double U_spinAgplus5;
	extern double U_spinAgplus4;
	extern double U_spinAgplus3;
	extern double U_spinAgplus2;
	extern double U_spinAgplus2ex;
	extern double U_spinAgplus1;
	extern double U_spinAgplus1ex;
	extern double U_spinAgneutrl;
	extern double U_spinAgneutrlex;
	extern double U_spinCdplus11;
	extern double U_spinCdplus10;
	extern double U_spinCdplus9;
	extern double U_spinCdplus8;
	extern double U_spinCdplus7;
	extern double U_spinCdplus6;
	extern double U_spinCdplus5;
	extern double U_spinCdplus4;
	extern double U_spinCdplus3;
	extern double U_spinCdplus3ex;
	extern double U_spinCdplus2;
	extern double U_spinCdplus2ex;
	extern double U_spinCdplus1;
	extern double U_spinCdplus1ex;
	extern double U_spinCdneutrl;
	extern double U_spinCdneutrlex;

	//int counter;//Sign mismatch counter
	int Ccounter=0;
	int Ocounter=0;
	int Ncounter=0;
	int Fcounter=0;
	int Sicounter=0;
	int Pcounter=0;
	int Scounter=0;
	int Clcounter=0;
	int Alcounter=0;
	int Bcounter=0;
	int Hcounter=0;
	int Zncounter=0;
	int Sccounter=0;
	int Ticounter=0;
	int Vcounter=0;
	int Crcounter=0;
	int Mncounter=0;
	int Fecounter=0;
	int Cocounter=0;
	int Nicounter=0;
	int Cucounter=0;
	int Ycounter=0;
	int Zrcounter=0;
	int Nbcounter=0;
	int Mocounter=0;
	int Tccounter=0;
	int Rucounter=0;
	int Rhcounter=0;
	int Pdcounter=0;
	int Agcounter=0;
	int Cdcounter=0;

	int O2_id=0;
	int O2dia_id=0;

	double thermo1, thermo2, thermo3, thermo4, thermo5, thermo6, thermo7, thermo8, thermo9, thermo10;
	double thermo11, thermo12, thermo13, thermo14, thermo15, thermo16, thermo17, thermo18, thermo19, thermo20;
	double thermo21, thermo22, thermo23, thermo24, thermo25, thermo26, thermo27, thermo28, thermo29, thermo30;
	double thermo31, thermo32, thermo33, thermo34, thermo35, thermo36, thermo37, thermo38, thermo39, thermo40;
	double thermo41, thermo42, thermo43, thermo44, thermo45, thermo46, thermo47, thermo48, thermo49, thermo50;
	double thermo51, thermo52, thermo53, thermo54, thermo55, thermo56, thermo57, thermo58, thermo59, thermo60;
	double thermo61, thermo62, thermo63, thermo64, thermo65, thermo66, thermo67, thermo68, thermo69, thermo70;
	double thermo71, thermo72, thermo73, thermo74, thermo75, thermo76, thermo77, thermo78, thermo79, thermo80;
	double thermo81, thermo82, thermo83, thermo84, thermo85, thermo86, thermo87, thermo88, thermo89, thermo90;
	double thermo91, thermo92, thermo93, thermo94, thermo95, thermo96, thermo97, thermo98, thermo99, thermo100;
	double thermo101, thermo102, thermo103, thermo104, thermo105, thermo106, thermo107, thermo108, thermo109, thermo110;
	double thermo111, thermo112, thermo113, thermo114, thermo115, thermo116, thermo117, thermo118, thermo119, thermo120;
	double thermo121, thermo122, thermo123, thermo124, thermo125, thermo126, thermo127, thermo128, thermo129, thermo130;
	double thermo131, thermo132, thermo133, thermo134, thermo135, thermo136, thermo137, thermo138, thermo139, thermo140;
	double thermo141, thermo142, thermo143, thermo144, thermo145, thermo146, thermo147, thermo148, thermo149, thermo150;
	double thermo151, thermo152, thermo153, thermo154, thermo155, thermo156, thermo157, thermo158, thermo159, thermo160;
	double thermo161, thermo162, thermo163, thermo164, thermo165, thermo166, thermo167, thermo168, thermo169, thermo170;
	double thermo171, thermo172, thermo173, thermo174, thermo175, thermo176, thermo177, thermo178, thermo179, thermo180;
	double thermo181, thermo182, thermo183, thermo184, thermo185, thermo186, thermo187, thermo188, thermo189, thermo190;
	double thermo191, thermo192, thermo193, thermo194, thermo195, thermo196, thermo197, thermo198, thermo199, thermo200;
	double thermo201, thermo202, thermo203, thermo204, thermo205, thermo206, thermo207, thermo208, thermo209, thermo210;
	double thermo211, thermo212, thermo213, thermo214, thermo215, thermo216, thermo217, thermo218, thermo219, thermo220;
	double thermo221, thermo222, thermo223, thermo224, thermo225, thermo226, thermo227, thermo228, thermo229, thermo230;
	double thermo231, thermo232, thermo233, thermo234, thermo235, thermo236, thermo237, thermo238, thermo239, thermo240;
	double thermo241, thermo242, thermo243, thermo244, thermo245, thermo246, thermo247, thermo248, thermo249, thermo250;
	double thermo251, thermo252, thermo253, thermo254, thermo255, thermo256, thermo257, thermo258, thermo259, thermo260;
	double thermo261, thermo262, thermo263, thermo264, thermo265, thermo266, thermo267, thermo268, thermo269, thermo270;
	double thermo271, thermo272, thermo273, thermo274, thermo275, thermo276, thermo277, thermo278, thermo279, thermo280;
	double thermo281, thermo282, thermo283, thermo284, thermo285, thermo286, thermo287, thermo288, thermo289, thermo290;
	double thermo291, thermo292, thermo293, thermo294, thermo295, thermo296, thermo297, thermo298, thermo299, thermo300;
	double thermo301, thermo302, thermo303, thermo304, thermo305, thermo306, thermo307, thermo308, thermo309, thermo310;
	double thermo311, thermo312, thermo313, thermo314, thermo315, thermo316, thermo317, thermo318, thermo319, thermo320;
	double thermo321, thermo322, thermo323, thermo324, thermo325, thermo326, thermo327, thermo328, thermo329, thermo330;
	double thermo331, thermo332, thermo333, thermo334, thermo335, thermo336, thermo337, thermo338, thermo339, thermo340;
	double thermo341, thermo342, thermo343, thermo344, thermo345, thermo346, thermo347, thermo348, thermo349, thermo350;
	double thermo351, thermo352, thermo353, thermo354, thermo355, thermo356, thermo357, thermo358, thermo359, thermo360;
	double thermo361, thermo362, thermo363, thermo364, thermo365, thermo366, thermo367, thermo368, thermo369, thermo370;
	double thermo371, thermo372, thermo373, thermo374, thermo375, thermo376, thermo377, thermo378, thermo379, thermo380;
	double thermo381, thermo382, thermo383, thermo384, thermo385, thermo386, thermo387, thermo388, thermo389, thermo390;
	double thermo391, thermo392, thermo393, thermo394, thermo395, thermo396, thermo397, thermo398, thermo399, thermo400;
	double thermo401, thermo402, thermo403, thermo404, thermo405, thermo406, thermo407, thermo408, thermo409, thermo410;
	double thermo411, thermo412, thermo413, thermo414, thermo415, thermo416, thermo417, thermo418, thermo419, thermo420;
	double thermo421, thermo422, thermo423, thermo424, thermo425, thermo426, thermo427, thermo428, thermo429, thermo430;
	double thermo431, thermo432, thermo433, thermo434, thermo435, thermo436, thermo437, thermo438, thermo439, thermo440;
	double thermo441, thermo442, thermo443, thermo444, thermo445, thermo446, thermo447, thermo448, thermo449, thermo450;
	double thermo451, thermo452, thermo453, thermo454, thermo455, thermo456, thermo457, thermo458, thermo459, thermo460;
	double thermo461, thermo462, thermo463, thermo464, thermo465, thermo466, thermo467, thermo468, thermo469, thermo470;
	double thermo471, thermo472, thermo473, thermo474, thermo475, thermo476, thermo477, thermo478, thermo479, thermo480;
	double thermo481, thermo482, thermo483, thermo484, thermo485, thermo486, thermo487, thermo488, thermo489, thermo490;
	double thermo491, thermo492, thermo493, thermo494, thermo495, thermo496, thermo497, thermo498, thermo499, thermo500;
	double thermo501, thermo502, thermo503, thermo504, thermo505, thermo506, thermo507, thermo508, thermo509, thermo510;
	double thermo511, thermo512, thermo513, thermo514, thermo515, thermo516, thermo517, thermo518, thermo519, thermo520;
	double thermo521, thermo522, thermo523, thermo524, thermo525, thermo526, thermo527, thermo528, thermo529, thermo530;
	double thermo531, thermo532, thermo533, thermo534, thermo535, thermo536, thermo537, thermo538, thermo539, thermo540;
	double thermo541, thermo542, thermo543, thermo544, thermo545, thermo546, thermo547, thermo548, thermo549, thermo550;
	double thermo551, thermo552, thermo553, thermo554, thermo555, thermo556, thermo557, thermo558, thermo559, thermo560;
	double thermo561, thermo562, thermo563, thermo564, thermo565, thermo566, thermo567, thermo568, thermo569, thermo570;
	double thermo571, thermo572, thermo573, thermo574, thermo575, thermo576, thermo577, thermo578, thermo579, thermo580;
	double thermo581, thermo582, thermo583, thermo584, thermo585, thermo586, thermo587, thermo588, thermo589, thermo590;
	double thermo591, thermo592, thermo593, thermo594, thermo595, thermo596, thermo597, thermo598, thermo599, thermo600;
	double thermo601, thermo602, thermo603, thermo604, thermo605, thermo606, thermo607, thermo608, thermo609, thermo610;
	double thermo611, thermo612, thermo613, thermo614, thermo615, thermo616, thermo617, thermo618, thermo619, thermo620;
	double thermo621, thermo622, thermo623, thermo624, thermo625, thermo626, thermo627, thermo628, thermo629, thermo630;
	double thermo631, thermo632, thermo633, thermo634, thermo635, thermo636, thermo637, thermo638, thermo639, thermo640;
	double thermo641, thermo642, thermo643, thermo644, thermo645, thermo646, thermo647, thermo648, thermo649, thermo650;
	double thermo651, thermo652, thermo653, thermo654, thermo655, thermo656, thermo657, thermo658, thermo659, thermo660;
	double thermo661, thermo662, thermo663, thermo664, thermo665, thermo666, thermo667, thermo668, thermo669, thermo670;
	double thermo671, thermo672, thermo673, thermo674, thermo675, thermo676, thermo677, thermo678, thermo679, thermo680;
	double thermo681, thermo682, thermo683, thermo684, thermo685, thermo686, thermo687, thermo688, thermo689, thermo690;
	double thermo691, thermo692, thermo693, thermo694, thermo695, thermo696, thermo697, thermo698, thermo699, thermo700;	
	double thermo701, thermo702, thermo703, thermo704, thermo705, thermo706, thermo707, thermo708, thermo709, thermo710;
	double thermo711, thermo712;

	double dev1, dev2, dev3, dev4, dev5, dev6, dev7, dev8, dev9, dev10;
	double dev11, dev12, dev13, dev14, dev15, dev16, dev17, dev18, dev19, dev20;
	double dev21, dev22, dev23, dev24, dev25, dev26, dev27, dev28, dev29, dev30;
	double dev31, dev32, dev33, dev34, dev35, dev36, dev37, dev38, dev39, dev40;
	double dev41, dev42, dev43, dev44, dev45, dev46, dev47, dev48, dev49, dev50;
	double dev51, dev52, dev53, dev54, dev55, dev56, dev57, dev58, dev59, dev60;
	double dev61, dev62, dev63, dev64, dev65, dev66, dev67, dev68, dev69, dev70;
	double dev71, dev72, dev73, dev74, dev75, dev76, dev77, dev78, dev79, dev80;
	double dev81, dev82, dev83, dev84, dev85, dev86, dev87, dev88, dev89, dev90;
	double dev91, dev92, dev93, dev94, dev95, dev96, dev97, dev98, dev99, dev100;
	double dev101, dev102, dev103, dev104, dev105, dev106, dev107, dev108, dev109, dev110;
	double dev111, dev112, dev113, dev114, dev115, dev116, dev117, dev118, dev119, dev120;
	double dev121, dev122, dev123, dev124, dev125, dev126, dev127, dev128, dev129, dev130;
	double dev131, dev132, dev133, dev134, dev135, dev136, dev137, dev138, dev139, dev140;
	double dev141, dev142, dev143, dev144, dev145, dev146, dev147, dev148, dev149, dev150;
	double dev151, dev152, dev153, dev154, dev155, dev156, dev157, dev158, dev159, dev160;
	double dev161, dev162, dev163, dev164, dev165, dev166, dev167, dev168, dev169, dev170;
	double dev171, dev172, dev173, dev174, dev175, dev176, dev177, dev178, dev179, dev180;
	double dev181, dev182, dev183, dev184, dev185, dev186, dev187, dev188, dev189, dev190;
	double dev191, dev192, dev193, dev194, dev195, dev196, dev197, dev198, dev199, dev200;
	double dev201, dev202, dev203, dev204, dev205, dev206, dev207, dev208, dev209, dev210;
	double dev211, dev212, dev213, dev214, dev215, dev216, dev217, dev218, dev219, dev220;
	double dev221, dev222, dev223, dev224, dev225, dev226, dev227, dev228, dev229, dev230;
	double dev231, dev232, dev233, dev234, dev235, dev236, dev237, dev238, dev239, dev240;
	double dev241, dev242, dev243, dev244, dev245, dev246, dev247, dev248, dev249, dev250;
	double dev251, dev252, dev253, dev254, dev255, dev256, dev257, dev258, dev259, dev260;
	double dev261, dev262, dev263, dev264, dev265, dev266, dev267, dev268, dev269, dev270;
	double dev271, dev272, dev273, dev274, dev275, dev276, dev277, dev278, dev279, dev280;
	double dev281, dev282, dev283, dev284, dev285, dev286, dev287, dev288, dev289, dev290;
	double dev291, dev292, dev293, dev294, dev295, dev296, dev297, dev298, dev299, dev300;
	double dev301, dev302, dev303, dev304, dev305, dev306, dev307, dev308, dev309, dev310;
	double dev311, dev312, dev313, dev314, dev315, dev316, dev317, dev318, dev319, dev320;
	double dev321, dev322, dev323, dev324, dev325, dev326, dev327, dev328, dev329, dev330;
	double dev331, dev332, dev333, dev334, dev335, dev336, dev337, dev338, dev339, dev340;
	double dev341, dev342, dev343, dev344, dev345, dev346, dev347, dev348, dev349, dev350;
	double dev351, dev352, dev353, dev354, dev355, dev356, dev357, dev358, dev359, dev360;
	double dev361, dev362, dev363, dev364, dev365, dev366, dev367, dev368, dev369, dev370;
	double dev371, dev372, dev373, dev374, dev375, dev376, dev377, dev378, dev379, dev380;
	double dev381, dev382, dev383, dev384, dev385, dev386, dev387, dev388, dev389, dev390;
	double dev391, dev392, dev393, dev394, dev395, dev396, dev397, dev398, dev399, dev400;
	double dev401, dev402, dev403, dev404, dev405, dev406, dev407, dev408, dev409, dev410;
	double dev411, dev412, dev413, dev414, dev415, dev416, dev417, dev418, dev419, dev420;
	double dev421, dev422, dev423, dev424, dev425, dev426, dev427, dev428, dev429, dev430;
	double dev431, dev432, dev433, dev434, dev435, dev436, dev437, dev438, dev439, dev440;
	double dev441, dev442, dev443, dev444, dev445, dev446, dev447, dev448, dev449, dev450;
	double dev451, dev452, dev453, dev454, dev455, dev456, dev457, dev458, dev459, dev460;
	double dev461, dev462, dev463, dev464, dev465, dev466, dev467, dev468, dev469, dev470;
	double dev471, dev472, dev473, dev474, dev475, dev476, dev477, dev478, dev479, dev480;
	double dev481, dev482, dev483, dev484, dev485, dev486, dev487, dev488, dev489, dev490;
	double dev491, dev492, dev493, dev494, dev495, dev496, dev497, dev498, dev499, dev500;
	double dev501, dev502, dev503, dev504, dev505, dev506, dev507, dev508, dev509, dev510;
	double dev511, dev512, dev513, dev514, dev515, dev516, dev517, dev518, dev519, dev520;
	double dev521, dev522, dev523, dev524, dev525, dev526, dev527, dev528, dev529, dev530;
	double dev531, dev532, dev533, dev534, dev535, dev536, dev537, dev538, dev539, dev540;
	double dev541, dev542, dev543, dev544, dev545, dev546, dev547, dev548, dev549, dev550;
	double dev551, dev552, dev553, dev554, dev555, dev556, dev557, dev558, dev559, dev560;
	double dev561, dev562, dev563, dev564, dev565, dev566, dev567, dev568, dev569, dev570;
	double dev571, dev572, dev573, dev574, dev575, dev576, dev577, dev578, dev579, dev580;
	double dev581, dev582, dev583, dev584, dev585, dev586, dev587, dev588, dev589, dev590;
	double dev591, dev592, dev593, dev594, dev595, dev596, dev597, dev598, dev599, dev600;
	double dev601, dev602, dev603, dev604, dev605, dev606, dev607, dev608, dev609, dev610;
	double dev611, dev612, dev613, dev614, dev615, dev616, dev617, dev618, dev619, dev620;
	double dev621, dev622, dev623, dev624, dev625, dev626, dev627, dev628, dev629, dev630;
	double dev631, dev632, dev633, dev634, dev635, dev636, dev637, dev638, dev639, dev640;
	double dev641, dev642, dev643, dev644, dev645, dev646, dev647, dev648, dev649, dev650;
	double dev651, dev652, dev653, dev654, dev655, dev656, dev657, dev658, dev659, dev660;
	double dev661, dev662, dev663, dev664, dev665, dev666, dev667, dev668, dev669, dev670;
	double dev671, dev672, dev673, dev674, dev675, dev676, dev677, dev678, dev679, dev680;
	double dev681, dev682, dev683, dev684, dev685, dev686, dev687, dev688, dev689, dev690;
	double dev691, dev692, dev693, dev694, dev695, dev696, dev697, dev698, dev699, dev700;	
	double dev711;

	double perdev1, perdev2, perdev3, perdev4, perdev5, perdev6, perdev7, perdev8, perdev9, perdev10;
	double perdev11, perdev12, perdev13, perdev14, perdev15, perdev16, perdev17, perdev18, perdev19, perdev20;
	double perdev21, perdev22, perdev23, perdev24, perdev25, perdev26, perdev27, perdev28, perdev29, perdev30;
	double perdev31, perdev32, perdev33, perdev34, perdev35, perdev36, perdev37, perdev38, perdev39, perdev40;
	double perdev41, perdev42, perdev43, perdev44, perdev45, perdev46, perdev47, perdev48, perdev49, perdev50;
	double perdev51, perdev52, perdev53, perdev54, perdev55, perdev56, perdev57, perdev58, perdev59, perdev60;
	double perdev61, perdev62, perdev63, perdev64, perdev65, perdev66, perdev67, perdev68, perdev69, perdev70;
	double perdev71, perdev72, perdev73, perdev74, perdev75, perdev76, perdev77, perdev78, perdev79, perdev80;
	double perdev81, perdev82, perdev83, perdev84, perdev85, perdev86, perdev87, perdev88, perdev89, perdev90;
	double perdev91, perdev92, perdev93, perdev94, perdev95, perdev96, perdev97, perdev98, perdev99, perdev100;
	double perdev101, perdev102, perdev103, perdev104, perdev105, perdev106, perdev107, perdev108, perdev109, perdev110;
	double perdev111, perdev112, perdev113, perdev114, perdev115, perdev116, perdev117, perdev118, perdev119, perdev120;
	double perdev121, perdev122, perdev123, perdev124, perdev125, perdev126, perdev127, perdev128, perdev129, perdev130;
	double perdev131, perdev132, perdev133, perdev134, perdev135, perdev136, perdev137, perdev138, perdev139, perdev140;
	double perdev141, perdev142, perdev143, perdev144, perdev145, perdev146, perdev147, perdev148, perdev149, perdev150;
	double perdev151, perdev152, perdev153, perdev154, perdev155, perdev156, perdev157, perdev158, perdev159, perdev160;
	double perdev161, perdev162, perdev163, perdev164, perdev165, perdev166, perdev167, perdev168, perdev169, perdev170;
	double perdev171, perdev172, perdev173, perdev174, perdev175, perdev176, perdev177, perdev178, perdev179, perdev180;
	double perdev181, perdev182, perdev183, perdev184, perdev185, perdev186, perdev187, perdev188, perdev189, perdev190;
	double perdev191, perdev192, perdev193, perdev194, perdev195, perdev196, perdev197, perdev198, perdev199, perdev200;
	double perdev201, perdev202, perdev203, perdev204, perdev205, perdev206, perdev207, perdev208, perdev209, perdev210;
	double perdev211, perdev212, perdev213, perdev214, perdev215, perdev216, perdev217, perdev218, perdev219, perdev220;
	double perdev221, perdev222, perdev223, perdev224, perdev225, perdev226, perdev227, perdev228, perdev229, perdev230;
	double perdev231, perdev232, perdev233, perdev234, perdev235, perdev236, perdev237, perdev238, perdev239, perdev240;
	double perdev241, perdev242, perdev243, perdev244, perdev245, perdev246, perdev247, perdev248, perdev249, perdev250;
	double perdev251, perdev252, perdev253, perdev254, perdev255, perdev256, perdev257, perdev258, perdev259, perdev260;
	double perdev261, perdev262, perdev263, perdev264, perdev265, perdev266, perdev267, perdev268, perdev269, perdev270;
	double perdev271, perdev272, perdev273, perdev274, perdev275, perdev276, perdev277, perdev278, perdev279, perdev280;
	double perdev281, perdev282, perdev283, perdev284, perdev285, perdev286, perdev287, perdev288, perdev289, perdev290;
	double perdev291, perdev292, perdev293, perdev294, perdev295, perdev296, perdev297, perdev298, perdev299, perdev300;
	double perdev301, perdev302, perdev303, perdev304, perdev305, perdev306, perdev307, perdev308, perdev309, perdev310;
	double perdev311, perdev312, perdev313, perdev314, perdev315, perdev316, perdev317, perdev318, perdev319, perdev320;
	double perdev321, perdev322, perdev323, perdev324, perdev325, perdev326, perdev327, perdev328, perdev329, perdev330;
	double perdev331, perdev332, perdev333, perdev334, perdev335, perdev336, perdev337, perdev338, perdev339, perdev340;
	double perdev341, perdev342, perdev343, perdev344, perdev345, perdev346, perdev347, perdev348, perdev349, perdev350;
	double perdev351, perdev352, perdev353, perdev354, perdev355, perdev356, perdev357, perdev358, perdev359, perdev360;
	double perdev361, perdev362, perdev363, perdev364, perdev365, perdev366, perdev367, perdev368, perdev369, perdev370;
	double perdev371, perdev372, perdev373, perdev374, perdev375, perdev376, perdev377, perdev378, perdev379, perdev380;
	double perdev381, perdev382, perdev383, perdev384, perdev385, perdev386, perdev387, perdev388, perdev389, perdev390;
	double perdev391, perdev392, perdev393, perdev394, perdev395, perdev396, perdev397, perdev398, perdev399, perdev400;
	double perdev401, perdev402, perdev403, perdev404, perdev405, perdev406, perdev407, perdev408, perdev409, perdev410;
	double perdev411, perdev412, perdev413, perdev414, perdev415, perdev416, perdev417, perdev418, perdev419, perdev420;
	double perdev421, perdev422, perdev423, perdev424, perdev425, perdev426, perdev427, perdev428, perdev429, perdev430;
	double perdev431, perdev432, perdev433, perdev434, perdev435, perdev436, perdev437, perdev438, perdev439, perdev440;
	double perdev441, perdev442, perdev443, perdev444, perdev445, perdev446, perdev447, perdev448, perdev449, perdev450;
	double perdev451, perdev452, perdev453, perdev454, perdev455, perdev456, perdev457, perdev458, perdev459, perdev460;
	double perdev461, perdev462, perdev463, perdev464, perdev465, perdev466, perdev467, perdev468, perdev469, perdev470;
	double perdev471, perdev472, perdev473, perdev474, perdev475, perdev476, perdev477, perdev478, perdev479, perdev480;
	double perdev481, perdev482, perdev483, perdev484, perdev485, perdev486, perdev487, perdev488, perdev489, perdev490;
	double perdev491, perdev492, perdev493, perdev494, perdev495, perdev496, perdev497, perdev498, perdev499, perdev500;
	double perdev501, perdev502, perdev503, perdev504, perdev505, perdev506, perdev507, perdev508, perdev509, perdev510;
	double perdev511, perdev512, perdev513, perdev514, perdev515, perdev516, perdev517, perdev518, perdev519, perdev520;
	double perdev521, perdev522, perdev523, perdev524, perdev525, perdev526, perdev527, perdev528, perdev529, perdev530;
	double perdev531, perdev532, perdev533, perdev534, perdev535, perdev536, perdev537, perdev538, perdev539, perdev540;
	double perdev541, perdev542, perdev543, perdev544, perdev545, perdev546, perdev547, perdev548, perdev549, perdev550;
	double perdev551, perdev552, perdev553, perdev554, perdev555, perdev556, perdev557, perdev558, perdev559, perdev560;
	double perdev561, perdev562, perdev563, perdev564, perdev565, perdev566, perdev567, perdev568, perdev569, perdev570;
	double perdev571, perdev572, perdev573, perdev574, perdev575, perdev576, perdev577, perdev578, perdev579, perdev580;
	double perdev581, perdev582, perdev583, perdev584, perdev585, perdev586, perdev587, perdev588, perdev589, perdev590;
	double perdev591, perdev592, perdev593, perdev594, perdev595, perdev596, perdev597, perdev598, perdev599, perdev600;
	double perdev601, perdev602, perdev603, perdev604, perdev605, perdev606, perdev607, perdev608, perdev609, perdev610;
	double perdev611, perdev612, perdev613, perdev614, perdev615, perdev616, perdev617, perdev618, perdev619, perdev620;
	double perdev621, perdev622, perdev623, perdev624, perdev625, perdev626, perdev627, perdev628, perdev629, perdev630;
	double perdev631, perdev632, perdev633, perdev634, perdev635, perdev636, perdev637, perdev638, perdev639, perdev640;
	double perdev641, perdev642, perdev643, perdev644, perdev645, perdev646, perdev647, perdev648, perdev649, perdev650;
	double perdev651, perdev652, perdev653, perdev654, perdev655, perdev656, perdev657, perdev658, perdev659, perdev660;
	double perdev661, perdev662, perdev663, perdev664, perdev665, perdev666, perdev667, perdev668, perdev669, perdev670;
	double perdev671, perdev672, perdev673, perdev674, perdev675, perdev676, perdev677, perdev678, perdev679, perdev680;
	double perdev681, perdev682, perdev683, perdev684, perdev685, perdev686, perdev687, perdev688, perdev689, perdev690;
	double perdev691, perdev692, perdev693, perdev694, perdev695, perdev696, perdev697, perdev698, perdev699, perdev700;	
	double perdev711;
	
	double deviation = 0;
	double wTotal    = 0;

	FILE *OutFile;
	int i;

//	const double LitThermo1 = 1675; //wikipedia data page
	const double LitThermo1 = 424.54; // Burt , Dunn et al 1970 j chem phys (check spreadsheet) (also handbook has 298 K value)
	const double LitThermo2 = 1635; //wikipedia data page
	const double LitThermo3 = 697; //wikipedia data page
	const double LitThermo4 = 2630; //seyit's calculations in his notebook 11 pg 64
	const double LitThermo5 = 458.112; //Molecular Spectra and Molecular Structure.IV. Constants of Diatomic Moleculesexperimental Herzberg 1979 book 
	const double LitThermo6 = 1488.37; //Handbook of chem and phys
	const double LitThermo7 = 493; //"Molecular Symmetry" by D. J. Willock pg 227
	const double LitThermo8 = -142; //chemguide.co.uk website
	const double LitThermo9 = 844; //chemguide.co.uk website
	const double LitThermo10 = 1313.9; //webelements.com
	const double LitThermo11 = 3388.3; //webelements.com
	const double LitThermo12 = 281; //Nakatsuji & Nakai chem phys letters 1992 "potential energy curves of dioxygen species"
	const double LitThermo13 = 394; //Nakatsuji & Nakai chem phys letters 1992 "potential energy curves of dioxygen species"
	const double LitThermo14 = 494; //Nakatsuji & Nakai chem phys letters 1992 "potential energy curves of dioxygen species"
	const double LitThermo15 = 593.2; //webbook.nist.gov
	const double LitThermo16 = 1601; //webbook.nist.gov
	const double LitThermo17 = 21.50; //Xantheas (JCP 1996)
	const double LitThermo18 = 72.77; //Lykke et al. Phys Rev A 1991 Vol 43 pg 6104-6107
	const double LitThermo19 = 1312.05; //experimental value:handbook of chem phys
	const double LitThermo20 = 446.727; //Experimental value from Stevens et al journal of chemical physics vol 61 no 9 november 1974
	const double LitThermo21 = 10.0;
	const double LitThermo22 = -142.0;//-41929.9; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo23 = -1313.9;//-41787.9; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo24 = -3388.3;//-40474.0; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo25 = -5300.5;//-37085.7; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo26 = -7469.2;//-31785.2; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo27 = -10989.0;//-24316.0; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo28 = -13326.0; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo29 = 94.29; //Nist (O2 vib freq) //also in wikipedia and other papers in form of 7882cm-1

//	const double LitThermo31 = -41085.9; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed.
	const double LitThermo32 = -41929.9; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo33 = -41787.9; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo34 = -40474.0; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo35 = -37085.7; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo36 = -31785.2; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo37 = -24316.0; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo38 = -13326.0; //Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo39 = 189.82;//-41598.07753; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo40 = 242.52;//-36846.83962; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo122 = 721.64;//-36846.83962; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo41 = 320.73;//-40153.27343; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo42 = 980.25;//-23334.11833; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo30 = 854.61;//32639.81; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo117= -41598.07753; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo118= -40153.27343; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo119= -36846.83962; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo120= -32639.81; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo121= -23334.11833; //Experimental value + excitation energy from Spectra values from NIST
	const double LitThermo123 = -36364; //Experimental value + excitation energy from Spectra values from NIST

	const double LitThermo43 = -6222.7156;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo44 = -4620.4705;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo45 = -2352.6328;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo46 = -1086.4538;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo47 = -121.8513;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo48 = -9444.9689;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo49 = -7475.0567;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo50 = -4578.1559;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo51 = -2856.0914;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo52 = -1402.3314;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo53 = 1;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo54 = -8495.8233;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo55 = -7004.3048;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo56 = -4556.2306;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo57 = -3356.7249;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo58 = -2251.7651;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo59 = -999.5891;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo60 = -200.4101;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo61 = -6273.9687;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo62 = -4963.582;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo63 = -2914.1177;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo64 = -1907.4572;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo65 = -1011.8118;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo66 = -72.0263;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo67 = -4355.5227;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo68 = -3231.5853;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo69 = -1577.1348;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo70 = -786.5186;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo71 = -133.6322;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo72 = -17867.7335;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo73 = -15164.1276;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo74 = -11022.755;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo75 = -8407.7129;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo76 = -6050.4411;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo77 = -3374.1713;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo78 = -1681.0467;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo79 = -328.165;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo80 = -6222.7156;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo81 = -10843.1861;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo82 = -13195.819;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo83 = -14282.2728;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo84 = -14404.1241;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo85 = -9444.9689;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo86 = -16920.0256;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo87 = -21498.1815;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo88 = -24354.2729;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo89 = -25756.6043;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo90 = -25755;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo91 = -8495.8233;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo92 = -15500.1281;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo93 = -20056.3587;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo94 = -23413.0835;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo95 = -25664.8486;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo96 = -26664.4377;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo97 = -26864.8478;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo98 = -6273.9687;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo99 = -11237.5507;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo100 = -14151.6683;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo101 = -16059.1255;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo102 = -17070.9374;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo103 = -17142.9637;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo104 = -4355.5227;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo105 = -7587.108;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo106 = -9164.2429;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo107 = -9950.7614;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo108 = -10084.3936;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo109 = -17867.7335;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo110 = -33031.8611;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo111 = -44054.6161;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo112 = -52462.329;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo113 = -58512.7701;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo114 = -61886.9414;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo115 = -63567.9881;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo116 = -63896.153;// Experimental value calculated from ionization energies and electron affinities handbook of chem and phys 76th ed
	const double LitThermo126 = 626.45;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo127 = 514.43;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo128 = 121.93;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo129 = 403.56;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo130 = 804;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo131 = 684.11;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo132 = 183.22;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo133 = 559.67;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo134 = 229.98;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo135 = 1155.47;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo136 = 1026.28;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo137 = 301.92;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo138 = 887.57;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo139 = 407.78;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo140 = 249.7;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo141 = 630.73;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo142 = 512.29;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo143 = 75.35;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo144 = 398.67;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo145 = 812.48;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo146 = 680.93;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo147 = 106.26;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo148 = 546.66;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo149 = 135.91;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo150 = 993.19;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo151 = 851.55;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo152 = 135.45;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo153 = 701.87;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo154 = 177.68;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo155 = 110.52;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo156 = 882.46;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo157 = 2935.64;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo158 = 1567.11;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo159 = 1225.04;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo160 = 2111.34;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo161 = 4688.54;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo162 = 629.52;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo163 = 692.64;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo164 = -3659.75;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo165 = -2427.07;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo166 = -800.64;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo167 = -26.99;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo168 = 446.63;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo169 = 342.7;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo170 = -3659.75;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo171 = -6086.82;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo172 = -6887.46;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo173 = -6914.45;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo174 = -348.74;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo175 = 860.81;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo176 = -1251.19;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo177 = 1290.53;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo178 = 139.41;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo179 = -2297.66;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo180 = 215.96;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo181 = -3821.78;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo182 = 777.57;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo183 = 164.7;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo184 = -5158.61;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo185 = 1023.92;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo186 = -6541.7;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo187 = 1173.08;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo188 = -9361.97;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo189 = -11018.22;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo190 = -41.86;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo191 = 347.16;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo192 = -577.54;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo193 = 447.32;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo194 = -1816.68;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo195 = -2744.78;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo196 = -39799.87;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo197 = -39451.13;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo198 = -38199.94;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo199 = -35902.28;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo200 = -32080.5;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo201 = -26921.89;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo202 = -20380.19;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo203 = -11018.22;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo204 = -5180.86;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo205 = -5139;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo206 = -4561.46;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo207 = -2744.78;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo208 = 0;//just to show it needs to be positive
	const double LitThermo209 = 0;//just to show it needs to be positive
	const double LitThermo210 = 254.7;//1997 JPCA stablization of hydrogen radical anions in solid hydrogen
	const double LitThermo211 = 0;//just to show it needs to be positive
	const double LitThermo214 = -59.59;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo215 = -520.22;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo216 = -899.5;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo217 = 262.92;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo218 = -1757.11;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo219 = -52.87;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo220 = -495.85;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo221 = -737.75;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo222 = 261.39;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo223 = -1450.68;// Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo224 = 294.956;//Hartree-Fock description of excited states of H2 JCP 2014 Guiseppe J
	const double LitThermo225 = 50;//just to show it needs to be positive
        const double LitThermo226 = 50;//just to show it needs to be positive
        const double LitThermo227 = 67.38;//lower bound from NISTwebbook
        const double LitThermo228 = 50;//just to show it needs to be positive
        const double LitThermo229 = 595.20;//lower bound from NISTwebbook
        const double LitThermo230 = 223.53;//lower bound from NISTwebbook
        const double LitThermo231 = 100;//just to show it needs to be positive
        const double LitThermo232 = 50;//just to show it needs to be positive
        const double LitThermo233 = 211.24;//lowerbound from NISTwebbook
	const double LitThermo234 = 0;//just to show it needs to be positive
	const double LitThermo235 = 0;//just to show it needs to be positive
	const double LitThermo236 = 0;//just to show it needs to be positive
	const double LitThermo238 = 0;//just to show it needs to be positive
        const double LitThermo239 = 0;//just to show it needs to be positive
        const double LitThermo240 = 0;//just to show it needs to be positive
        const double LitThermo241 = 0;//just to show it needs to be positive
        const double LitThermo242 = 0;//just to show it needs to be positive
        const double LitThermo243 = 0;//just to show it needs to be positive
	const double LitThermo244 = 40.1999;//Mielke et al, 2009, J phys chem A 113. 4479-4488
	const double LitThermo245 = 260.124;//Mielke et al, 2009, J phys chem
	const double LitThermo246 = 179.91; //Silver and Brown, 1980, J Chem phys
	const double LitThermo247 = 594.128;//Silver and Brown, 1980, J Chem phys
	const double LitThermo248 = 786.592;//Silver and Brown, 1980, J Chem phys
	//LitThermo249 used up but doesn't need a value
	//LitThermo250 used up but doesn't need a value
	const double LitThermo251 = 50.0;//just to show it needs to be positive
	//LitThermo252 used up but doesn't need a value (using a prev defined value)

	const double LitThermo253 = 1175; //Wiki
	const double LitThermo254 = 43.42; //Wiki
	const double LitThermo256 = 2388.711; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo257 = 1235.711; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo258 = 30.39704; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo259 = 633.0978; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo260 = 137.8119; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo261 = -2388.711; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo262 = -3623.721; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo263 = -4526.819; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo264 = 4174.715; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo265 = 2652.59; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo266 = 101.37; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo267 = 1309.858; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo268 = 55.37193; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo269 = 658.8241; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo270 = 78.43841; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo271 = 86.79472; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo272 = -4174.715; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo273 = -6827.305; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo274 = -8137.163; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo275 = -8795.987; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo276 = 6298.82403538; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo277 = 4506.8066121; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo278 = 131.104469982; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo279 = 2828.1275259; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo280 = 143.150859447; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo281 = 1410.638; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo282 = 103.3615; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo283 = 214.2659; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo284 = 650.9187; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo285 = 25.26886; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo286 = 130.3055; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo287 = -6298.82403538; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo288 = -10805.631; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo289 = -13633.758; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo290 = -15044.397; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo291 = -15695.315; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo292 = 8745.0901815; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo293 = 6701.980074; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo294 = 157.76573019; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo295 = 4743.296004; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo296 = 180.084115029; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo297 = 2987.234424; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo298 = 200.63331607; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo299 = 300.732589119; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo300 = 1591.069; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo301 = 233.6135; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo302 = 360.5998; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo303 = 652.8796; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo304 = 90.83586; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo305 = 277.0987; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo306 = 382.6564; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo307 = -8745.0901815; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo308 = -15447.07; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo309 = -20190.366; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo310 = -12177.601; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo311 = -24768.255; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo312 = -25421.134; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo313 = 11501.5279407; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo314 = 9224.14764; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo315 = 183.46019166; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo316 = 6985.65156; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo317 = 214.043644353; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo318 = 4940.12928; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo319 = 247.082688651; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo320 = 3248.5209492; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo321 = 320.896324994; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo322 = 468.637838169; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo323 = 1509.054; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo324 = 113.324; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo325 = 357.3234; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo326 = 463.2047; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo327 = 717.2854; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo328 = 220.1459; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo329 = 278.6946; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo330 = 391.5892; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo331 = -11501.5279407; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo332 = -20725.676; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo333 = -27711.327; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo334 = -32651.456; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo335 = -35899.977; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo336 = -37409.032; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo337 = -27126.317; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo338 = 14575.311114; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo339 = 12060.8625; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo340 = 209.057201361; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo341 = 9550.7557965; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo342 = 246.631129959; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo343 = 7236.5175; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo344 = 287.771214381; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo345 = 437.676156828; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo346 = 5298.095679; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo347 = 385.747872117; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo348 = 563.1940353; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo349 = 2957.4199719; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo350 = 232.136867841; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo351 = 363.146780661; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo352 = 1563.011; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo353 = 22.40163; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo354 = 189.5472; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo355 = 762.4846; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo356 = 143.27; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo357 = 231.4918; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo358 = 329.4928; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo359 = -14575.311114; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo360 = -26636.174; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo361 = -36186.929; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo362 = -43423.447; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo363 = -48721.543; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo364 = -54678.963; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo365 = -53241.973; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo366 = -54004.458; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo367 = 17960.071566; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo368 = 15225.63282; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo369 = 234.76227639; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo370 = 12446.8101; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo371 = 278.56732899; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo372 = 9841.6638; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo373 = 339.465035925; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo374 = 501.553379235; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo375 = 7670.70855; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo376 = 445.227221622; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo377 = 650.05154268; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo378 = 4946.883363; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo379 = 273.749738073; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo380 = 283.273959972; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo381 = 3232.31115; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo382 = 203.100100155; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo383 = 555.534905178; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo384 = 1648.421; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo385 = 40.08146; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo386 = 139.3825; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo387 = 760.4142; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo388 = 89.03242; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo389 = -17960.071566; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo390 = -33185.704; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo391 = -45632.514; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo392 = -55474.178; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo393 = -63144.887; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo394 = -68091.770; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo395 = -71324.081; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo396 = -72972.502; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo397 = -73732.916; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo398 = 21680.60643; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo399 = 18641.26908; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo400 = 261.9619335; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo401 = 15630.8778; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo402 = 278.2682196; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo403 = 12736.2708; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo404 = 317.5383879; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo405 = 10420.5852; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo406 = 501.493557357; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo407 = 732.078915846; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo408 = 7338.793614; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo409 = 312.864562464; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo410 = 493.493828478; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo411 = 5297.13081; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo412 = 237.218832864; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo413 = 1320.82557687; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo414 = 3395.374011; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo415 = 167.85825993; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo416 = 642.452041462; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo417 = 1753.055; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo418 = 100.415; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo419 = 737.148; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo420 = 161.7539; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo421 = -21680.60643; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo422 = -40321.876; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo423 = -55952.753; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo424 = -68689.024; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo425 = -79109.609; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo426 = -86448.403; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo427 = -91745.534; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo428 = -95140.908; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo429 = -96893.963; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo430 = -97631.111; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo431 = 25569.0285; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo432 = 22404.25818; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo433 = 285.8906847; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo434 = 19104.4062; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo435 = 16016.8254; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo436 = 13411.6791; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo437 = 9938.1507; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo438 = 350.332355472; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo439 = 555.146062971; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo440 = 7699.65462; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo441 = 270.064903362; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo442 = 3184.82994651; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo443 = 5536.418322; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo444 = 194.37286005; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo445 = 1431.14483886; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo446 = 3554.6738829; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo447 = 727.403739593; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo448 = 1957.94980469; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo449 = 262.330407322; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo450 = 745.4945; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo451 = 466.7743; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo452 = -25569.0285; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo453 = -47973.287; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo454 = -67077.693; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo455 = -83094.518; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo456 = -96506.197; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo457 = -106444.348; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo458 = -114144.003; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo459 = -119680.421; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo460 = -123235.095; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo461 = -125193.045; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo462 = -125938.539; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo463 = 29988.13; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo464 = 26476.01; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo465 = 311.8746; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo466 = 22963.88; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo467 = 19586.84; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo468 = 16779.07; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo469 = 12929.24; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo470 = 386.623; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo471 = 229.0889; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo472 = 10420.59; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo473 = 302.2549; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo474 = 4117.250; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo475 = 7969.818; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo476 = 220.0866; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo477 = 2160.062; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo478 = 5748.014; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo479 = 1539.975; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo480 = 3832.749; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo481 = 934.2257; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo482 = 1733.328; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo483 = 1240.567; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo484 = 906.4171; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo485 = 386.5359; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo486 = -29988.13; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo487 = -56464.1; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo488 = -79428.0; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo489 = -99014.9; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo490 = -115794.0; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo491 = -128723.173; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo492 = -139143.758; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo493 = -147113.576; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo494 = -152861.591; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo495 = -156694.340; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo496 = -158427.668; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo497 = -159334.085; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo498 = 1980.392; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo499 = 1179.45; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo500 = 10.05145; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo501 = 599.9009; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo502 = 130.8456; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo503 = -1980.392; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo504 = -3159.754; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo505 = -3759.638; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo506 = 3321.01378906; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo507 = 2235.664032; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo508 = 68.709279264; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo509 = 1266.908; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo510 = 50.8232; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo511 = 640.1024; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo512 = 58.26708; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo513 = 61.03237; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo514 = -3321.01378906; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo515 = -5556.522; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo516 = -6823.395; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo517 = -7463.480; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo518 = 4879.74924288; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo519 = 3629.0703456; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo520 = 100.121565034; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo521 = 2416.099584; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo522 = 110.486477866; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo523 = 1381.731072; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo524 = 66.542122848; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo525 = 146.707187766; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo526 = 652.1587; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo527 = 13.67142; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo528 = 105.599; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo529 = -4879.74924288; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo530 = -8508.581; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo531 = -10924.613; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo532 = -12306.306; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo533 = -12958.446; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo534 = 6641.09355878; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo535 = 5257.235856; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo536 = 121.908337776; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo537 = 3891.425568; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo538 = 138.53967119; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo539 = 2617.762848; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo540 = 133.37998632; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo541 = 242.735799053; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo542 = 1559.271936; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo543 = 181.831467043; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo544 = 274.919712154; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo545 = 684.3457; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo546 = 128.8236; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo547 = 246.5306; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo548 = 376.6563; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo549 = -6641.09355878; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo550 = -11897.996; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo551 = -15789.313; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo552 = -18407.003; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo553 = -19966.231; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo554 = -20650.558; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo555 = 8491.0848; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo556 = 6947.2512; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo557 = 5499.9072; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo558 = 3956.0736; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo559 = 2851.26768; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo560 = 1472.431; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo561 = 41.40784; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo562 = 686.9461; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo563 = 142.2507; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo564 = 196.5397; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo565 = 242.0298; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo566 = -8491.0848; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo567 = -15437.904; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo568 = -20937.657; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo569 = -24893.620; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo570 = -27744.808; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo571 = -29217.198; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo572 = -29904.125; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo573 = 10613.856; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo574 = 8973.5328; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo575 = 7333.2096; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo576 = 5692.8864; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo577 = 4342.032; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo578 = 2747.058912; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo579 = 324.953815296; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo580 = 1617.4551648; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo581 = 109.485097218; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo582 = 129.930965568; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo583 = 710.2117; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo584 = 78.29938; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo585 = 175.8626; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo586 = -10613.856; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo587 = -19586.841; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo588 = -26919.845; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo589 = -32612.572; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo590 = -36954.483; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo591 = -39701.465; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo592 = -41318.875; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo593 = -42029.066; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo594 = 13026.096; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo595 = 11105.95296; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo596 = 9359.4912; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo597 = 7719.168; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo598 = 6078.8448; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo599 = 4052.5632; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo600 = 2996.966976; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo601 = 155.881843488; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo602 = 514.68035088; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo603 = 1744.531968; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo604 = 139.295281248; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo605 = 201.99615312; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo606 = 719.7063; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo607 = 39.59644; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo608 = -13026.096; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo609 = -24131.374; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo610 = -33490.603; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo611 = -41209.555; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo612 = -47288.230; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo613 = -51340.679; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo614 = -54337.563; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo615 = -56082.046; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo616 = -56801.732; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo617 = 15428.68704; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo618 = 13605.0336; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo619 = 11578.752; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo620 = 9745.4496; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo621 = 8114.77536; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo622 = 5885.8656; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo623 = 4438.5216; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo624 = 3177.402528; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo625 = 175.073624928; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo626 = 633.0441432; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo627 = 1874.792928; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo628 = 300.087769949; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo629 = 804.420286656; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo630 = 78.5281188538; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo631 = -15428.68704; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo632 = -29032.908; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo633 = -40611.336; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo634 = -50356.513; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo635 = -58471.061; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo636 = -64356.762; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo637 = -68795.160; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo638 = -71972.473; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo639 = -73847.214; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo640 = -74651.612; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo641 = 18140.0448; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo642 = 16113.7632; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo643 = 14000.64096; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo644 = 12061.2; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo645 = 10227.8976; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo646 = 7912.1472; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo647 = 6271.824; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo648 = 4727.9904; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo649 = 3360.732768; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo650 = 756.627057984; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo651 = 2073.02116224; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo652 = 468.574249618; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo653 = 731.0278; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo654 = 703.3142; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo655 = -18140.0448; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo656 = -34252.8; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo657 = -48253.1; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo658 = -60314.0; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo659 = -70541.6; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo660 = -78453.5; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo661 = -84725.1; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo662 = -89453.0; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo663 = -92813.6; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo664 = -94886.6; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo665 = -95617.6; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo666 = 21034.7328; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo667 = 18815.472; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo668 = 16692.7008; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo669 = 14473.44; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo670 = 12553.29696; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo671 = 10131.408; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo672 = 8394.5952; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo673 = 6551.64384; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo674 = 4920.9696; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo675 = 1300.44823296; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo676 = 3615.2723328; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo677 = 962.489549376; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo678 = 1631.476; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo679 = 1270.361; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo680 = 867.8103; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo681 = 360.2592; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo682 = -21034.144; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo683 = -39849.09; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo684 = -56541.323; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo685 = -71014.358; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo686 = -83567.304; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo687 = -93698.429; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo688 = -102092.79; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo689 = -108644.25; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo690 = -113565.08; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo691 = -117180.25; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo692 = -118811.68; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo693 = -119679.47; //Experimental value calculated from atomic spectra values obtained from NIST
	const double LitThermo711 = 193.94; //QM value calculated from "First Principles Calculations to Study the Equilibrium Configuration of Ozone Molecule"

	//literature thermo values (in kJ/mol)

	thermo1 = U_spinH2 - U_spinH3plus;
	thermo2 = 0.0;//U_spinOH - U_spinH2O;
	thermo3 = 0.0;//U_spinH2O - U_spinH3O;
	thermo4 = 0.0;//U_spinO_2 - U_spinOH;
	thermo5 = U_spinH*2 - U_spinH2;
	thermo6 = U_spinH2plus - U_spinH2;
	thermo7 = 0.0;//(U_spinOHdot + U_spinH) - U_spinH2O;

	thermo208 = U_spinH3 - (U_spinH + U_spinH2);
	thermo209 = U_spinH4 - (2*U_spinH2);

	thermo244 = U_spinH3linear - (U_spinH + U_spinH2);
	thermo245 = U_spinH3trig - (U_spinH + U_spinH2);
	thermo246 = U_spinH4linear - (2*U_spinH2);
	thermo247 = U_spinH4square - (2*U_spinH2);
	thermo248 = U_spinH4tetra - (2*U_spinH2);

	thermo210 = U_spinH2minus - U_spinH2;
	thermo211 = U_spinH2 + U_spinH2plus - (U_spinH3plus + U_spinH);

	thermo234 = U_spinH3trig - U_spinH3linear;
	thermo235 = U_spinH4tetra - U_spinH4square;
	thermo236 = U_spinH4square - U_spinH4linear;

	thermo8 = U_spinO_1 - U_spinOneutrl;
	thermo9 = U_spinO_2 - U_spinO_1;
	thermo10 = U_spinOplus1 - U_spinOneutrl;
	thermo11 = U_spinOplus2 - U_spinOplus1;
	thermo12 = U_spinO_1*2 - U_spinO2_2;
	thermo13 = (U_spinOneutrl + U_spinO_1) - U_spinO2_1;
	thermo14 = U_spinOneutrl*2 - U_spinO2;
	thermo15 = 0.0;//U_spinOHdot - U_spinH2Oplus;
	thermo16 = 0.0;//U_spinO_1 - U_spinOHdot;
	thermo17 = 0.0;//U_spindimer - U_spinH2O*2;
	thermo18 = U_spinH - U_spinH_;
	thermo19 = -U_spinH;
	thermo20 = 0.0;//U_spinOneutrl + U_spinH - U_spinOHdot;
	thermo21 = 0.0;	
	thermo22 = U_spinO_1-U_spinOneutrl;
	thermo23 = U_spinOneutrl-U_spinOplus1;
	thermo24 = U_spinOplus1-U_spinOplus2;
	thermo25 = U_spinOplus2-U_spinOplus3;
	thermo26 = U_spinOplus3-U_spinOplus4;
	thermo27 = U_spinOplus4-U_spinOplus5;
	thermo28 = U_spinOplus5;

	thermo249=fmin(fmin(fmin(U_spinO2_linnett,U_spinO2_snglbnd),U_spinO2_dblbnd),U_spinO2_trplbnd); //spinO2 (triplet)
	thermo250=fmin(fmin(fmin(U_spinO2dia_linnett,U_spinO2dia_snglbnd),U_spinO2dia_dblbnd),U_spinO2dia_trplbnd);//spinO2dia (singlet)
	
	if(thermo249==U_spinO2_linnett)
		O2_id=1;
	else if(thermo249==U_spinO2_snglbnd)
		O2_id=2;
	else if(thermo249==U_spinO2_dblbnd)
		O2_id=3;
	else if(thermo249==U_spinO2_trplbnd)
		O2_id=4;
        if(thermo250==U_spinO2dia_linnett)
                O2dia_id=1;
        else if(thermo250==U_spinO2dia_snglbnd)
                O2dia_id=2;
        else if(thermo250==U_spinO2dia_dblbnd)
                O2dia_id=3;
        else if(thermo250==U_spinO2dia_trplbnd)
                O2dia_id=4;

	thermo29 = U_spinO2dia - U_spinO2;
	thermo251= U_spinO2qnt - U_spinO2dia;
	thermo252= U_spinO2qnt - U_spinO2;
//	thermo29 = thermo250 - thermo249;
	thermo253= U_spinO2plus1 - U_spinO2;
	thermo254= U_spinO2 - U_spinO2_1;

//	thermo31 = U_spinO_2;
	thermo32 = U_spinO_1;
	thermo33 = U_spinOneutrl;
	thermo34 = U_spinOplus1;
	thermo35 = U_spinOplus2;
	thermo36 = U_spinOplus3;
	thermo37 = U_spinOplus4;
	thermo38 = U_spinOplus5;
	thermo39 = U_spinOneutrlex - U_spinOneutrl;
	thermo40 = U_spinOplus2ex - U_spinOplus2;
	thermo122= U_spinOplus2ex2 - U_spinOplus2;
	thermo41 = U_spinOplus1ex - U_spinOplus1;
	thermo42 = U_spinOplus4ex - U_spinOplus4;
	thermo30 = U_spinOplus3ex - U_spinOplus3;

	thermo117= U_spinOneutrlex;
	thermo118= U_spinOplus1ex;
	thermo119= U_spinOplus2ex;
	thermo123= U_spinOplus2ex2;
	thermo120= U_spinOplus3ex;
	thermo121= U_spinOplus4ex;

	thermo43 = U_spinCplus3;
	thermo44 = U_spinCplus2 - U_spinCplus3;
	thermo45 = U_spinCplus1 - U_spinCplus2;
	thermo46 = U_spinCneutrl - U_spinCplus1;
	thermo47 = U_spinC_1 - U_spinCneutrl;
	thermo48 = U_spinNplus4;
	thermo49 = U_spinNplus3 - U_spinNplus4;
	thermo50 = U_spinNplus2 - U_spinNplus3;
	thermo51 = U_spinNplus1 - U_spinNplus2;
	thermo52 = U_spinNneutrl - U_spinNplus1;
	thermo53 = U_spinN_1 - U_spinNneutrl;
	thermo54 = U_spinSplus5;
	thermo55 = U_spinSplus4 - U_spinSplus5;
	thermo56 = U_spinSplus3 - U_spinSplus4;
	thermo57 = U_spinSplus2 - U_spinSplus3;
	thermo58 = U_spinSplus1 - U_spinSplus2;
	thermo59 = U_spinSneutrl - U_spinSplus1;
	thermo60 = U_spinS_1 - U_spinSneutrl;
	thermo61 = U_spinPplus4;
	thermo62 = U_spinPplus3 - U_spinPplus4;
	thermo63 = U_spinPplus2 - U_spinPplus3;
	thermo64 = U_spinPplus1 - U_spinPplus2;
	thermo65 = U_spinPneutrl - U_spinPplus1;
	thermo66 = U_spinP_1 - U_spinPneutrl;
	thermo67 = U_spinSiplus3;
	thermo68 = U_spinSiplus2 - U_spinSiplus3;
	thermo69 = U_spinSiplus1 - U_spinSiplus2;
	thermo70 = U_spinSineutrl - U_spinSiplus1;
	thermo71 = U_spinSi_1 - U_spinSineutrl;
	thermo72 = U_spinFplus6;
	thermo73 = U_spinFplus5 - U_spinFplus6;
	thermo74 = U_spinFplus4 - U_spinFplus5;
	thermo75 = U_spinFplus3 - U_spinFplus4;
	thermo76 = U_spinFplus2 - U_spinFplus3;
	thermo77 = U_spinFplus1 - U_spinFplus2;
	thermo78 = U_spinFneutrl - U_spinFplus1;
	thermo79 = U_spinF_1 - U_spinFneutrl;
	thermo80 = U_spinCplus3;
	thermo81 = U_spinCplus2;
	thermo82 = U_spinCplus1;
	thermo83 = U_spinCneutrl;
	thermo84 = U_spinC_1;
	thermo85 = U_spinNplus4;
	thermo86 = U_spinNplus3;
	thermo87 = U_spinNplus2;
	thermo88 = U_spinNplus1;
	thermo89 = U_spinNneutrl;
	thermo90 = U_spinN_1;
	thermo91 = U_spinSplus5;
	thermo92 = U_spinSplus4;
	thermo93 = U_spinSplus3;
	thermo94 = U_spinSplus2;
	thermo95 = U_spinSplus1;
	thermo96 = U_spinSneutrl;
	thermo97 = U_spinS_1;
	thermo98 = U_spinPplus4;
	thermo99 = U_spinPplus3;
	thermo100 = U_spinPplus2;
	thermo101 = U_spinPplus1;
	thermo102 = U_spinPneutrl;
	thermo103 = U_spinP_1;
	thermo104 = U_spinSiplus3;
	thermo105 = U_spinSiplus2;
	thermo106 = U_spinSiplus1;
	thermo107 = U_spinSineutrl;
	thermo108 = U_spinSi_1;
	thermo109 = U_spinFplus6;
	thermo110 = U_spinFplus5;
	thermo111 = U_spinFplus4;
	thermo112 = U_spinFplus3;
	thermo113 = U_spinFplus2;
	thermo114 = U_spinFplus1;
	thermo115 = U_spinFneutrl;
	thermo116 = U_spinF_1;
	thermo126 = U_spinCplus2ex - U_spinCplus2;
	thermo127 = U_spinCplus1ex - U_spinCplus1;
	thermo128 = U_spinCneutrlex - U_spinCneutrl;
	thermo129 = U_spinCneutrlex2 - U_spinCneutrl;
	thermo130 = U_spinNplus3ex - U_spinNplus3;
	thermo131 = U_spinNplus2ex - U_spinNplus2;
	thermo132 = U_spinNplus1ex - U_spinNplus1;
	thermo133 = U_spinNplus1ex2 - U_spinNplus1;
	thermo134 = U_spinNneutrlex - U_spinNneutrl;
	thermo135 = U_spinFplus5ex - U_spinFplus5;
	thermo136 = U_spinFplus4ex - U_spinFplus4;
	thermo137 = U_spinFplus3ex - U_spinFplus3;
	thermo138 = U_spinFplus3ex2 - U_spinFplus3;
	thermo139 = U_spinFplus2ex - U_spinFplus2;
	thermo140 = U_spinFplus1ex - U_spinFplus1;
	thermo141 = U_spinSiplus2ex - U_spinSiplus2;
	thermo142 = U_spinSiplus1ex - U_spinSiplus1;
	thermo143 = U_spinSineutrlex - U_spinSineutrl;
	thermo144 = U_spinSineutrlex2 - U_spinSineutrl;
	thermo145 = U_spinPplus3ex - U_spinPplus3;
	thermo146 = U_spinPplus2ex - U_spinPplus2;
	thermo147 = U_spinPplus1ex - U_spinPplus1;
	thermo148 = U_spinPplus1ex2 - U_spinPplus1;
	thermo149 = U_spinPneutrlex - U_spinPneutrl;
	thermo150 = U_spinSplus4ex - U_spinSplus4;
	thermo151 = U_spinSplus3ex - U_spinSplus3;
	thermo152 = U_spinSplus2ex - U_spinSplus2;
	thermo153 = U_spinSplus2ex2 - U_spinSplus2;
	thermo154 = U_spinSplus1ex - U_spinSplus1;
	thermo155 = U_spinSneutrlex - U_spinSneutrl;
	thermo156 = U_spinOneutrlex2 - U_spinOneutrl;

	thermo163 = U_spinOneutrlex2 - U_spinOneutrlex;
	thermo157 = U_spinOplus1ex2 - U_spinOplus1;
	thermo158 = U_spinNneutrlex2 - U_spinNneutrl;
	thermo159 = U_spinFneutrlex - U_spinFneutrl;
	thermo160 = U_spinFplus1ex2 - U_spinFplus1;
	thermo161 = U_spinFplus2ex2 - U_spinFplus2;
	thermo162 = U_spinSneutrlex2 - U_spinSneutrl;

	thermo164 = U_spinBplus2 ;
	thermo165 = U_spinBplus1 - U_spinBplus2;
	thermo166 = U_spinBneutrl - U_spinBplus1;
	thermo167 = U_spinB_1 - U_spinBneutrl;
	thermo168 = U_spinBplus1ex - U_spinBplus1;
	thermo169 = U_spinBneutrlex - U_spinBneutrl;
	thermo170 = U_spinBplus2 ;
	thermo171 = U_spinBplus1 ;
	thermo172 = U_spinBneutrl ;
	thermo173 = U_spinB_1 ;

	thermo174 = U_spinCl_1 - U_spinClneutrl;
	thermo175 = U_spinClneutrlex - U_spinClneutrl;
	thermo176 = U_spinClneutrl - U_spinClplus1;
	thermo177 = U_spinClplus1ex2 - U_spinClplus1;
	thermo178 = U_spinClplus1ex - U_spinClplus1;
	thermo179 = U_spinClplus1 - U_spinClplus2;
	thermo180 = U_spinClplus2ex - U_spinClplus2;
	thermo181 = U_spinClplus2 - U_spinClplus3;
	thermo182 = U_spinClplus3ex2 - U_spinClplus3;
	thermo183 = U_spinClplus3ex - U_spinClplus3;
	thermo184 = U_spinClplus3 - U_spinClplus4;
	thermo185 = U_spinClplus4ex - U_spinClplus4;
	thermo186 = U_spinClplus4 - U_spinClplus5;
	thermo187 = U_spinClplus5ex - U_spinClplus5;
	thermo188 = U_spinClplus5 - U_spinClplus6;
	thermo189 = U_spinClplus6;
	thermo190 = U_spinAl_1 - U_spinAlneutrl;
	thermo191 = U_spinAlneutrlex - U_spinAlneutrl;
	thermo192 = U_spinAlneutrl - U_spinAlplus1;
	thermo193 = U_spinAlplus1ex - U_spinAlplus1;
	thermo194 = U_spinAlplus1 - U_spinAlplus2;
	thermo195 = U_spinAlplus2;
	thermo196 = U_spinCl_1;
	thermo197 = U_spinClneutrl;
	thermo198 = U_spinClplus1;
	thermo199 = U_spinClplus2;
	thermo200 = U_spinClplus3;
	thermo201 = U_spinClplus4;
	thermo202 = U_spinClplus5;
	thermo203 = U_spinClplus6;
	thermo204 = U_spinAl_1;
	thermo205 = U_spinAlneutrl;
	thermo206 = U_spinAlplus1;
	thermo207 = U_spinAlplus2;

	thermo214 = U_spinLi_1 - U_spinLineutrl;
	thermo215 = U_spinLineutrl;
	thermo216 = U_spinBeneutrl - U_spinBeplus1;
	thermo217 = U_spinBeneutrlex - U_spinBeneutrl;
	thermo218 = U_spinBeplus1;
	thermo219 = U_spinNa_1 - U_spinNaneutrl;
	thermo220 = U_spinNaneutrl;
	thermo221 = U_spinMgneutrl - U_spinMgplus1;
	thermo222 = U_spinMgneutrlex - U_spinMgneutrl;
	thermo223 = U_spinMgplus1;
	thermo224 = 2*U_spinH - U_spinH2trp; 
	thermo225 = U_spinAl2_snglt - U_spinAl2_trplt;
        thermo226 = U_spinB2_snglt - U_spinB2_trplt;
        thermo227 = U_spinC2_trplt - U_spinC2_snglt;
        thermo228 = U_spinSi2_snglt - U_spinSi2_trplt;
        thermo229 = U_spinN2_trplt - U_spinN2_snglt;
        thermo230 = U_spinP2_trplt - U_spinP2_snglt;
        thermo231 = U_spinS2_snglt - U_spinS2_trplt;
        thermo232 = U_spinF2_trplt - U_spinF2_snglt;
        thermo233 = U_spinCl2_trplt - U_spinCl2_snglt;

	thermo238 = U_spinO2_snglbnd - U_spinO2_linnett;
	thermo239 = U_spinO2_dblbnd - U_spinO2_linnett;
	thermo240 = U_spinO2_trplbnd - U_spinO2_linnett;
        thermo241 = U_spinO2dia_snglbnd - U_spinO2dia_linnett;
        thermo242 = U_spinO2dia_dblbnd - U_spinO2dia_linnett;
        thermo243 = U_spinO2dia_trplbnd - U_spinO2dia_linnett;

	thermo256 = 0.0 - U_spinScplus2;
	thermo257 = U_spinScplus2 - U_spinScplus1;
	thermo258 = U_spinScplus1ex - U_spinScplus1;
	thermo259 = U_spinScplus1 - U_spinScneutrl;
	thermo260 = U_spinScneutrlex - U_spinScneutrl;
	thermo261 = U_spinScplus2 - 0.0;
	thermo262 = U_spinScplus1 - 0.0;
	thermo263 = U_spinScneutrl - 0.0;
	thermo264 = 0.0 - U_spinTiplus3;
	thermo265 = U_spinTiplus3 - U_spinTiplus2;
	thermo266 = U_spinTiplus2ex - U_spinTiplus2;
	thermo267 = U_spinTiplus2 - U_spinTiplus1;
	thermo268 = U_spinTiplus1ex - U_spinTiplus1;
	thermo269 = U_spinTiplus1 - U_spinTineutrl;
	thermo270 = U_spinTineutrlex - U_spinTineutrl;
	thermo271 = U_spinTineutrlex2 - U_spinTineutrl;
	thermo272 = U_spinTiplus3 - 0.0;
	thermo273 = U_spinTiplus2 - 0.0;
	thermo274 = U_spinTiplus1 - 0.0;
	thermo275 = U_spinTineutrl - 0.0;
	thermo276 = 0.0 - U_spinVplus4;
	thermo277 = U_spinVplus4 - U_spinVplus3;
	thermo278 = U_spinVplus3ex - U_spinVplus3;
	thermo279 = U_spinVplus3 - U_spinVplus2;
	thermo280 = U_spinVplus2ex - U_spinVplus2;
	thermo281 = U_spinVplus2 - U_spinVplus1;
	thermo282 = U_spinVplus1ex - U_spinVplus1;
	thermo283 = U_spinVplus1ex2 - U_spinVplus1;
	thermo284 = U_spinVplus1 - U_spinVneutrl;
	thermo285 = U_spinVneutrlex - U_spinVneutrl;
	thermo286 = U_spinVneutrlex2 - U_spinVneutrl;
	thermo287 = U_spinVplus4 - 0.0;
	thermo288 = U_spinVplus3 - 0.0;
	thermo289 = U_spinVplus2 - 0.0;
	thermo290 = U_spinVplus1 - 0.0;
	thermo291 = U_spinVneutrl - 0.0;
	thermo292 = 0.0 - U_spinCrplus5;
	thermo293 = U_spinCrplus5 - U_spinCrplus4;
	thermo294 = U_spinCrplus4ex - U_spinCrplus4;
	thermo295 = U_spinCrplus4 - U_spinCrplus3;
	thermo296 = U_spinCrplus3ex - U_spinCrplus3;
	thermo297 = U_spinCrplus3 - U_spinCrplus2;
	thermo298 = U_spinCrplus2ex - U_spinCrplus2;
	thermo299 = U_spinCrplus2ex2 - U_spinCrplus2;
	thermo300 = U_spinCrplus2 - U_spinCrplus1;
	thermo301 = U_spinCrplus1ex - U_spinCrplus1;
	thermo302 = U_spinCrplus1ex2 - U_spinCrplus1;
	thermo303 = U_spinCrplus1 - U_spinCrneutrl;
	thermo304 = U_spinCrneutrlex - U_spinCrneutrl;
	thermo305 = U_spinCrneutrlex2 - U_spinCrneutrl;
	thermo306 = U_spinCrneutrlex3 - U_spinCrneutrl;
	thermo307 = U_spinCrplus5 - 0.0;
	thermo308 = U_spinCrplus4 - 0.0;
	thermo309 = U_spinCrplus3 - 0.0;
	thermo310 = U_spinCrplus2 - 0.0;
	thermo311 = U_spinCrplus1 - 0.0;
	thermo312 = U_spinCrneutrl - 0.0;
	thermo313 = 0.0 - U_spinMnplus6;
	thermo314 = U_spinMnplus6 - U_spinMnplus5;
	thermo315 = U_spinMnplus5ex - U_spinMnplus5;
	thermo316 = U_spinMnplus5 - U_spinMnplus4;
	thermo317 = U_spinMnplus4ex - U_spinMnplus4;
	thermo318 = U_spinMnplus4 - U_spinMnplus3;
	thermo319 = U_spinMnplus3ex - U_spinMnplus3;
	thermo320 = U_spinMnplus3 - U_spinMnplus2;
	thermo321 = U_spinMnplus2ex - U_spinMnplus2;
	thermo322 = U_spinMnplus2ex2 - U_spinMnplus2;
	thermo323 = U_spinMnplus2 - U_spinMnplus1;
	thermo324 = U_spinMnplus1ex - U_spinMnplus1;
	thermo325 = U_spinMnplus1ex2 - U_spinMnplus1;
	thermo326 = U_spinMnplus1ex3 - U_spinMnplus1;
	thermo327 = U_spinMnplus1 - U_spinMnneutrl;
	thermo328 = U_spinMnneutrlex - U_spinMnneutrl;
	thermo329 = U_spinMnneutrlex2 - U_spinMnneutrl;
	thermo330 = U_spinMnneutrlex3 - U_spinMnneutrl;
	thermo331 = U_spinMnplus6 - 0.0;
	thermo332 = U_spinMnplus5 - 0.0;
	thermo333 = U_spinMnplus4 - 0.0;
	thermo334 = U_spinMnplus3 - 0.0;
	thermo335 = U_spinMnplus2 - 0.0;
	thermo336 = U_spinMnplus1 - 0.0;
	thermo337 = U_spinMnneutrl - 0.0;
	thermo338 = 0.0 - U_spinFeplus7;
	thermo339 = U_spinFeplus7 - U_spinFeplus6;
	thermo340 = U_spinFeplus6ex - U_spinFeplus6;
	thermo341 = U_spinFeplus6 - U_spinFeplus5;
	thermo342 = U_spinFeplus5ex - U_spinFeplus5;
	thermo343 = U_spinFeplus5 - U_spinFeplus4;
	thermo344 = U_spinFeplus4ex - U_spinFeplus4;
	thermo345 = U_spinFeplus4ex2 - U_spinFeplus4;
	thermo346 = U_spinFeplus4 - U_spinFeplus3;
	thermo347 = U_spinFeplus3ex - U_spinFeplus3;
	thermo348 = U_spinFeplus3ex2 - U_spinFeplus3;
	thermo349 = U_spinFeplus3 - U_spinFeplus2;
	thermo350 = U_spinFeplus2ex - U_spinFeplus2;
	thermo351 = U_spinFeplus2ex2 - U_spinFeplus2;
	thermo352 = U_spinFeplus2 - U_spinFeplus1;
	thermo353 = U_spinFeplus1ex - U_spinFeplus1;
	thermo354 = U_spinFeplus1ex2 - U_spinFeplus1;
	thermo355 = U_spinFeplus1 - U_spinFeneutrl;
	thermo356 = U_spinFeneutrlex - U_spinFeneutrl;
	thermo357 = U_spinFeneutrlex2 - U_spinFeneutrl;
	thermo358 = U_spinFeneutrlex3 - U_spinFeneutrl;
	thermo359 = U_spinFeplus7 - 0.0;
	thermo360 = U_spinFeplus6 - 0.0;
	thermo361 = U_spinFeplus5 - 0.0;
	thermo362 = U_spinFeplus4 - 0.0;
	thermo363 = U_spinFeplus3 - 0.0;
	thermo364 = U_spinFeplus2 - 0.0;
	thermo365 = U_spinFeplus1 - 0.0;
	thermo366 = U_spinFeneutrl - 0.0;
	thermo367 = 0.0 - U_spinCoplus8;
	thermo368 = U_spinCoplus8 - U_spinCoplus7;
	thermo369 = U_spinCoplus7ex - U_spinCoplus7;
	thermo370 = U_spinCoplus7 - U_spinCoplus6;
	thermo371 = U_spinCoplus6ex - U_spinCoplus6;
	thermo372 = U_spinCoplus6 - U_spinCoplus5;
	thermo373 = U_spinCoplus5ex - U_spinCoplus5;
	thermo374 = U_spinCoplus5ex2 - U_spinCoplus5;
	thermo375 = U_spinCoplus5 - U_spinCoplus4;
	thermo376 = U_spinCoplus4ex - U_spinCoplus4;
	thermo377 = U_spinCoplus4ex2 - U_spinCoplus4;
	thermo378 = U_spinCoplus4 - U_spinCoplus3;
	thermo379 = U_spinCoplus3ex - U_spinCoplus3;
	thermo380 = U_spinCoplus3ex2 - U_spinCoplus3;
	thermo381 = U_spinCoplus3 - U_spinCoplus2;
	thermo382 = U_spinCoplus2ex - U_spinCoplus2;
	thermo383 = U_spinCoplus2ex2 - U_spinCoplus2;
	thermo384 = U_spinCoplus2 - U_spinCoplus1;
	thermo385 = U_spinCoplus1ex - U_spinCoplus1;
	thermo386 = U_spinCoplus1ex2 - U_spinCoplus1;
	thermo387 = U_spinCoplus1 - U_spinConeutrl;
	thermo388 = U_spinConeutrlex - U_spinConeutrl;
	thermo389 = U_spinCoplus8 - 0.0;
	thermo390 = U_spinCoplus7 - 0.0;
	thermo391 = U_spinCoplus6 - 0.0;
	thermo392 = U_spinCoplus5 - 0.0;
	thermo393 = U_spinCoplus4 - 0.0;
	thermo394 = U_spinCoplus3 - 0.0;
	thermo395 = U_spinCoplus2 - 0.0;
	thermo396 = U_spinCoplus1 - 0.0;
	thermo397 = U_spinConeutrl - 0.0;
	thermo398 = 0.0 - U_spinNiplus9;
	thermo399 = U_spinNiplus9 - U_spinNiplus8;
	thermo400 = U_spinNiplus8ex - U_spinNiplus8;
	thermo401 = U_spinNiplus8 - U_spinNiplus7;
	thermo402 = U_spinNiplus7ex - U_spinNiplus7;
	thermo403 = U_spinNiplus7 - U_spinNiplus6;
	thermo404 = U_spinNiplus6ex - U_spinNiplus6;
	thermo405 = U_spinNiplus6 - U_spinNiplus5;
	thermo406 = U_spinNiplus5ex - U_spinNiplus5;
	thermo407 = U_spinNiplus5ex2 - U_spinNiplus5;
	thermo408 = U_spinNiplus5 - U_spinNiplus4;
	thermo409 = U_spinNiplus4ex - U_spinNiplus4;
	thermo410 = U_spinNiplus4ex2 - U_spinNiplus4;
	thermo411 = U_spinNiplus4 - U_spinNiplus3;
	thermo412 = U_spinNiplus3ex - U_spinNiplus3;
	thermo413 = U_spinNiplus3ex2 - U_spinNiplus3;
	thermo414 = U_spinNiplus3 - U_spinNiplus2;
	thermo415 = U_spinNiplus2ex - U_spinNiplus2;
	thermo416 = U_spinNiplus2ex2 - U_spinNiplus2;
	thermo417 = U_spinNiplus2 - U_spinNiplus1;
	thermo418 = U_spinNiplus1ex - U_spinNiplus1;
	thermo419 = U_spinNiplus1 - U_spinNineutrl;
	thermo420 = U_spinNineutrlex - U_spinNineutrl;
	thermo421 = U_spinNiplus9 - 0.0;
	thermo422 = U_spinNiplus8 - 0.0;
	thermo423 = U_spinNiplus7 - 0.0;
	thermo424 = U_spinNiplus6 - 0.0;
	thermo425 = U_spinNiplus5 - 0.0;
	thermo426 = U_spinNiplus4 - 0.0;
	thermo427 = U_spinNiplus3 - 0.0;
	thermo428 = U_spinNiplus2 - 0.0;
	thermo429 = U_spinNiplus1 - 0.0;
	thermo430 = U_spinNineutrl - 0.0;
	thermo431 = 0.0 - U_spinCuplus10;
	thermo432 = U_spinCuplus10 - U_spinCuplus9;
	thermo433 = U_spinCuplus9ex - U_spinCuplus9;
	thermo434 = U_spinCuplus9 - U_spinCuplus8;
	thermo435 = U_spinCuplus8 - U_spinCuplus7;
	thermo436 = U_spinCuplus7 - U_spinCuplus6;
	thermo437 = U_spinCuplus6 - U_spinCuplus5;
	thermo438 = U_spinCuplus5ex - U_spinCuplus5;
	thermo439 = U_spinCuplus5ex2 - U_spinCuplus5;
	thermo440 = U_spinCuplus5 - U_spinCuplus4;
	thermo441 = U_spinCuplus4ex - U_spinCuplus4;
	thermo442 = U_spinCuplus4ex2 - U_spinCuplus4;
	thermo443 = U_spinCuplus4 - U_spinCuplus3;
	thermo444 = U_spinCuplus3ex - U_spinCuplus3;
	thermo445 = U_spinCuplus3ex2 - U_spinCuplus3;
	thermo446 = U_spinCuplus3 - U_spinCuplus2;
	thermo447 = U_spinCuplus2ex - U_spinCuplus2;
	thermo448 = U_spinCuplus2 - U_spinCuplus1;
	thermo449 = U_spinCuplus1ex - U_spinCuplus1;
	thermo450 = U_spinCuplus1 - U_spinCuneutrl;
	thermo451 = U_spinCuneutrlex - U_spinCuneutrl;
	thermo452 = U_spinCuplus10 - 0.0;
	thermo453 = U_spinCuplus9 - 0.0;
	thermo454 = U_spinCuplus8 - 0.0;
	thermo455 = U_spinCuplus7 - 0.0;
	thermo456 = U_spinCuplus6 - 0.0;
	thermo457 = U_spinCuplus5 - 0.0;
	thermo458 = U_spinCuplus4 - 0.0;
	thermo459 = U_spinCuplus3 - 0.0;
	thermo460 = U_spinCuplus2 - 0.0;
	thermo461 = U_spinCuplus1 - 0.0;
	thermo462 = U_spinCuneutrl - 0.0;
	thermo463 = 0.0 - U_spinZnplus11;
	thermo464 = U_spinZnplus11 - U_spinZnplus10;
	thermo465 = U_spinZnplus10ex - U_spinZnplus10;
	thermo466 = U_spinZnplus10 - U_spinZnplus9;
	thermo467 = U_spinZnplus9 - U_spinZnplus8;
	thermo468 = U_spinZnplus8 - U_spinZnplus7;
	thermo469 = U_spinZnplus7 - U_spinZnplus6;
	thermo470 = U_spinZnplus6ex - U_spinZnplus6;
	thermo471 = U_spinZnplus6ex2 - U_spinZnplus6ex;
	thermo472 = U_spinZnplus6 - U_spinZnplus5;
	thermo473 = U_spinZnplus5ex - U_spinZnplus5;
	thermo474 = U_spinZnplus5ex2 - U_spinZnplus5ex;
	thermo475 = U_spinZnplus5 - U_spinZnplus4;
	thermo476 = U_spinZnplus4ex - U_spinZnplus4;
	thermo477 = U_spinZnplus4ex2 - U_spinZnplus4ex;
	thermo478 = U_spinZnplus4 - U_spinZnplus3;
	thermo479 = U_spinZnplus3ex - U_spinZnplus3;
	thermo480 = U_spinZnplus3 - U_spinZnplus2;
	thermo481 = U_spinZnplus2ex - U_spinZnplus2;
	thermo482 = U_spinZnplus2 - U_spinZnplus1;
	thermo483 = U_spinZnplus1ex - U_spinZnplus1;
	thermo484 = U_spinZnplus1 - U_spinZnneutrl;
	thermo485 = U_spinZnneutrlex - U_spinZnneutrl;
	thermo486 = U_spinZnplus11 - 0.0;
	thermo487 = U_spinZnplus10 - 0.0;
	thermo488 = U_spinZnplus9 - 0.0;
	thermo489 = U_spinZnplus8 - 0.0;
	thermo490 = U_spinZnplus7 - 0.0;
	thermo491 = U_spinZnplus6 - 0.0;
	thermo492 = U_spinZnplus5 - 0.0;
	thermo493 = U_spinZnplus4 - 0.0;
	thermo494 = U_spinZnplus3 - 0.0;
	thermo495 = U_spinZnplus2 - 0.0;
	thermo496 = U_spinZnplus1 - 0.0;
	thermo497 = U_spinZnneutrl - 0.0;
	thermo498 = 0.0 - U_spinYplus2;
	thermo499 = U_spinYplus2 - U_spinYplus1;
	thermo500 = U_spinYplus1ex - U_spinYplus1;
	thermo501 = U_spinYplus1 - U_spinYneutrl;
	thermo502 = U_spinYneutrlex - U_spinYneutrl;
	thermo503 = U_spinYplus2 - 0.0;
	thermo504 = U_spinYplus1 - 0.0;
	thermo505 = U_spinYneutrl - 0.0;
	thermo506 = 0.0 - U_spinZrplus3;
	thermo507 = U_spinZrplus3 - U_spinZrplus2;
	thermo508 = U_spinZrplus2ex - U_spinZrplus2;
	thermo509 = U_spinZrplus2 - U_spinZrplus1;
	thermo510 = U_spinZrplus1ex - U_spinZrplus1;
	thermo511 = U_spinZrplus1 - U_spinZrneutrl;
	thermo512 = U_spinZrneutrlex - U_spinZrneutrl;
	thermo513 = U_spinZrneutrlex2 - U_spinZrneutrl;
	thermo514 = U_spinZrplus3 - 0.0;
	thermo515 = U_spinZrplus2 - 0.0;
	thermo516 = U_spinZrplus1 - 0.0;
	thermo517 = U_spinZrneutrl - 0.0;
	thermo518 = 0.0 - U_spinNbplus4;
	thermo519 = U_spinNbplus4 - U_spinNbplus3;
	thermo520 = U_spinNbplus3ex - U_spinNbplus3;
	thermo521 = U_spinNbplus3 - U_spinNbplus2;
	thermo522 = U_spinNbplus2ex - U_spinNbplus2;
	thermo523 = U_spinNbplus2 - U_spinNbplus1;
	thermo524 = U_spinNbplus1ex - U_spinNbplus1;
	thermo525 = U_spinNbplus1ex2 - U_spinNbplus1;
	thermo526 = U_spinNbplus1 - U_spinNbneutrl;
	thermo527 = U_spinNbneutrlex - U_spinNbneutrl;
	thermo528 = U_spinNbneutrlex2 - U_spinNbneutrl;
	thermo529 = U_spinNbplus4 - 0.0;
	thermo530 = U_spinNbplus3 - 0.0;
	thermo531 = U_spinNbplus2 - 0.0;
	thermo532 = U_spinNbplus1 - 0.0;
	thermo533 = U_spinNbneutrl - 0.0;
	thermo534 = 0.0 - U_spinMoplus5;
	thermo535 = U_spinMoplus5 - U_spinMoplus4;
	thermo536 = U_spinMoplus4ex - U_spinMoplus4;
	thermo537 = U_spinMoplus4 - U_spinMoplus3;
	thermo538 = U_spinMoplus3ex - U_spinMoplus3;
	thermo539 = U_spinMoplus3 - U_spinMoplus2;
	thermo540 = U_spinMoplus2ex - U_spinMoplus2;
	thermo541 = U_spinMoplus2ex2 - U_spinMoplus2;
	thermo542 = U_spinMoplus2 - U_spinMoplus1;
	thermo543 = U_spinMoplus1ex - U_spinMoplus1;
	thermo544 = U_spinMoplus1ex2 - U_spinMoplus1;
	thermo545 = U_spinMoplus1 - U_spinMoneutrl;
	thermo546 = U_spinMoneutrlex - U_spinMoneutrl;
	thermo547 = U_spinMoneutrlex2 - U_spinMoneutrl;
	thermo548 = U_spinMoneutrlex3 - U_spinMoneutrl;
	thermo549 = U_spinMoplus5 - 0.0;
	thermo550 = U_spinMoplus4 - 0.0;
	thermo551 = U_spinMoplus3 - 0.0;
	thermo552 = U_spinMoplus2 - 0.0;
	thermo553 = U_spinMoplus1 - 0.0;
	thermo554 = U_spinMoneutrl - 0.0;
	thermo555 = 0.0 - U_spinTcplus6;
	thermo556 = U_spinTcplus6 - U_spinTcplus5;
	thermo557 = U_spinTcplus5 - U_spinTcplus4;
	thermo558 = U_spinTcplus4 - U_spinTcplus3;
	thermo559 = U_spinTcplus3 - U_spinTcplus2;
	thermo560 = U_spinTcplus2 - U_spinTcplus1;
	thermo561 = U_spinTcplus1ex - U_spinTcplus1;
	thermo562 = U_spinTcplus1 - U_spinTcneutrl;
	thermo563 = U_spinTcneutrlex - U_spinTcneutrl;
	thermo564 = U_spinTcneutrlex2 - U_spinTcneutrl;
	thermo565 = U_spinTcneutrlex3 - U_spinTcneutrl;
	thermo566 = U_spinTcplus6 - 0.0;
	thermo567 = U_spinTcplus5 - 0.0;
	thermo568 = U_spinTcplus4 - 0.0;
	thermo569 = U_spinTcplus3 - 0.0;
	thermo570 = U_spinTcplus2 - 0.0;
	thermo571 = U_spinTcplus1 - 0.0;
	thermo572 = U_spinTcneutrl - 0.0;
	thermo573 = 0.0 - U_spinRuplus7;
	thermo574 = U_spinRuplus7 - U_spinRuplus6;
	thermo575 = U_spinRuplus6 - U_spinRuplus5;
	thermo576 = U_spinRuplus5 - U_spinRuplus4;
	thermo577 = U_spinRuplus4 - U_spinRuplus3;
	thermo578 = U_spinRuplus3 - U_spinRuplus2;
	thermo579 = U_spinRuplus2ex - U_spinRuplus2;
	thermo580 = U_spinRuplus2 - U_spinRuplus1;
	thermo581 = U_spinRuplus1ex - U_spinRuplus1;
	thermo582 = U_spinRuplus1ex2 - U_spinRuplus1;
	thermo583 = U_spinRuplus1 - U_spinRuneutrl;
	thermo584 = U_spinRuneutrlex - U_spinRuneutrl;
	thermo585 = U_spinRuneutrlex2 - U_spinRuneutrl;
	thermo586 = U_spinRuplus7 - 0.0;
	thermo587 = U_spinRuplus6 - 0.0;
	thermo588 = U_spinRuplus5 - 0.0;
	thermo589 = U_spinRuplus4 - 0.0;
	thermo590 = U_spinRuplus3 - 0.0;
	thermo591 = U_spinRuplus2 - 0.0;
	thermo592 = U_spinRuplus1 - 0.0;
	thermo593 = U_spinRuneutrl - 0.0;
	thermo594 = 0.0 - U_spinRhplus8;
	thermo595 = U_spinRhplus8 - U_spinRhplus7;
	thermo596 = U_spinRhplus7 - U_spinRhplus6;
	thermo597 = U_spinRhplus6 - U_spinRhplus5;
	thermo598 = U_spinRhplus5 - U_spinRhplus4;
	thermo599 = U_spinRhplus4 - U_spinRhplus3;
	thermo600 = U_spinRhplus3 - U_spinRhplus2;
	thermo601 = U_spinRhplus2ex - U_spinRhplus2;
	thermo602 = U_spinRhplus2ex2 - U_spinRhplus2;
	thermo603 = U_spinRhplus2 - U_spinRhplus1;
	thermo604 = U_spinRhplus1ex - U_spinRhplus1;
	thermo605 = U_spinRhplus1ex2 - U_spinRhplus1;
	thermo606 = U_spinRhplus1 - U_spinRhneutrl;
	thermo607 = U_spinRhneutrlex - U_spinRhneutrl;
	thermo608 = U_spinRhplus8 - 0.0;
	thermo609 = U_spinRhplus7 - 0.0;
	thermo610 = U_spinRhplus6 - 0.0;
	thermo611 = U_spinRhplus5 - 0.0;
	thermo612 = U_spinRhplus4 - 0.0;
	thermo613 = U_spinRhplus3 - 0.0;
	thermo614 = U_spinRhplus2 - 0.0;
	thermo615 = U_spinRhplus1 - 0.0;
	thermo616 = U_spinRhneutrl - 0.0;
	thermo617 = 0.0 - U_spinPdplus9;
	thermo618 = U_spinPdplus9 - U_spinPdplus8;
	thermo619 = U_spinPdplus8 - U_spinPdplus7;
	thermo620 = U_spinPdplus7 - U_spinPdplus6;
	thermo621 = U_spinPdplus6 - U_spinPdplus5;
	thermo622 = U_spinPdplus5 - U_spinPdplus4;
	thermo623 = U_spinPdplus4 - U_spinPdplus3;
	thermo624 = U_spinPdplus3 - U_spinPdplus2;
	thermo625 = U_spinPdplus2ex - U_spinPdplus2;
	thermo626 = U_spinPdplus2ex2 - U_spinPdplus2;
	thermo627 = U_spinPdplus2 - U_spinPdplus1;
	thermo628 = U_spinPdplus1ex - U_spinPdplus1;
	thermo629 = U_spinPdplus1 - U_spinPdneutrl;
	thermo630 = U_spinPdneutrlex - U_spinPdneutrl;
	thermo631 = U_spinPdplus9 - 0.0;
	thermo632 = U_spinPdplus8 - 0.0;
	thermo633 = U_spinPdplus7 - 0.0;
	thermo634 = U_spinPdplus6 - 0.0;
	thermo635 = U_spinPdplus5 - 0.0;
	thermo636 = U_spinPdplus4 - 0.0;
	thermo637 = U_spinPdplus3 - 0.0;
	thermo638 = U_spinPdplus2 - 0.0;
	thermo639 = U_spinPdplus1 - 0.0;
	thermo640 = U_spinPdneutrl - 0.0;
	thermo641 = 0.0 - U_spinAgplus10;
	thermo642 = U_spinAgplus10 - U_spinAgplus9;
	thermo643 = U_spinAgplus9 - U_spinAgplus8;
	thermo644 = U_spinAgplus8 - U_spinAgplus7;
	thermo645 = U_spinAgplus7 - U_spinAgplus6;
	thermo646 = U_spinAgplus6 - U_spinAgplus5;
	thermo647 = U_spinAgplus5 - U_spinAgplus4;
	thermo648 = U_spinAgplus4 - U_spinAgplus3;
	thermo649 = U_spinAgplus3 - U_spinAgplus2;
	thermo650 = U_spinAgplus2ex - U_spinAgplus2;
	thermo651 = U_spinAgplus2 - U_spinAgplus1;
	thermo652 = U_spinAgplus1ex - U_spinAgplus1;
	thermo653 = U_spinAgplus1 - U_spinAgneutrl;
	thermo654 = U_spinAgneutrlex - U_spinAgneutrl;
	thermo655 = U_spinAgplus10 - 0.0;
	thermo656 = U_spinAgplus9 - 0.0;
	thermo657 = U_spinAgplus8 - 0.0;
	thermo658 = U_spinAgplus7 - 0.0;
	thermo659 = U_spinAgplus6 - 0.0;
	thermo660 = U_spinAgplus5 - 0.0;
	thermo661 = U_spinAgplus4 - 0.0;
	thermo662 = U_spinAgplus3 - 0.0;
	thermo663 = U_spinAgplus2 - 0.0;
	thermo664 = U_spinAgplus1 - 0.0;
	thermo665 = U_spinAgneutrl - 0.0;
	thermo666 = 0.0 - U_spinCdplus11;
	thermo667 = U_spinCdplus11 - U_spinCdplus10;
	thermo668 = U_spinCdplus10 - U_spinCdplus9;
	thermo669 = U_spinCdplus9 - U_spinCdplus8;
	thermo670 = U_spinCdplus8 - U_spinCdplus7;
	thermo671 = U_spinCdplus7 - U_spinCdplus6;
	thermo672 = U_spinCdplus6 - U_spinCdplus5;
	thermo673 = U_spinCdplus5 - U_spinCdplus4;
	thermo674 = U_spinCdplus4 - U_spinCdplus3;
	thermo675 = U_spinCdplus3ex - U_spinCdplus3;
	thermo676 = U_spinCdplus3 - U_spinCdplus2;
	thermo677 = U_spinCdplus2ex - U_spinCdplus2;
	thermo678 = U_spinCdplus2 - U_spinCdplus1;
	thermo679 = U_spinCdplus1ex - U_spinCdplus1;
	thermo680 = U_spinCdplus1 - U_spinCdneutrl;
	thermo681 = U_spinCdneutrlex - U_spinCdneutrl;
	thermo682 = U_spinCdplus11 - 0.0;
	thermo683 = U_spinCdplus10 - 0.0;
	thermo684 = U_spinCdplus9 - 0.0;
	thermo685 = U_spinCdplus8 - 0.0;
	thermo686 = U_spinCdplus7 - 0.0;
	thermo687 = U_spinCdplus6 - 0.0;
	thermo688 = U_spinCdplus5 - 0.0;
	thermo689 = U_spinCdplus4 - 0.0;
	thermo690 = U_spinCdplus3 - 0.0;
	thermo691 = U_spinCdplus2 - 0.0;
	thermo692 = U_spinCdplus1 - 0.0;
	thermo693 = U_spinCdneutrl - 0.0;

	thermo701 = U_spinZnplus1ex2 - U_spinZnplus1ex;
	thermo702 = U_spinZnplus2ex2 - U_spinZnplus2ex;
	thermo703 = U_spinZnplus3ex2 - U_spinZnplus3ex;
	thermo704 = U_spinZnplus4ex3 - U_spinZnplus4ex2;
	thermo705 = U_spinZnplus5ex3 - U_spinZnplus5ex;
	thermo706 = U_spinZnplus6ex3 - U_spinZnplus6ex;
	thermo707 = U_spinZnplus7ex - U_spinZnplus7;
	thermo708 = U_spinZnplus8ex - U_spinZnplus8;
	thermo709 = U_spinZnplus9ex - U_spinZnplus9;
	thermo710 = U_spinZnneutrlex2 - U_spinZnneutrlex;

	thermo711 = U_spinO3trp_linnett - U_spinO3_linnett;
	//deviation of thermo values
	/* All dimer enthalpies are subject to ENERGY_M * 
	 * and all proton affinities are to ENERGY_XL    */

	//calculated and lit value differences
	perdev1 = thermo1 - LitThermo1;
	perdev2 = thermo2 - LitThermo2;
	perdev3 = thermo3 - LitThermo3;
	perdev4 = thermo4 - LitThermo4;
	perdev5 = thermo5 - LitThermo5;
	perdev6 = thermo6 - LitThermo6;
	perdev7 = thermo7 - LitThermo7;
	perdev8 = thermo8 - LitThermo8;
	perdev9 = thermo9 - LitThermo9;
	perdev10 = thermo10 - LitThermo10;
	perdev11 = thermo11 - LitThermo11;
	perdev12 = thermo12 - LitThermo12;
	perdev13 = thermo13 - LitThermo13;
	perdev14 = thermo14 - LitThermo14;
	perdev15 = thermo15 - LitThermo15;
	perdev16 = thermo16 - LitThermo16;
	perdev17 = thermo17 - LitThermo17;
	perdev18 = thermo18 - LitThermo18;
	perdev19 = thermo19 - LitThermo19;
	perdev20 = thermo20 - LitThermo20;
	perdev21 = thermo21 - LitThermo21;
	perdev22 = thermo22 - LitThermo22;
	perdev23 = thermo23 - LitThermo23;
	perdev24 = thermo24 - LitThermo24;
	perdev25 = thermo25 - LitThermo25;
	perdev26 = thermo26 - LitThermo26;
	perdev27 = thermo27 - LitThermo27;
	perdev28 = thermo28 - LitThermo28;
	perdev29 = thermo29 - LitThermo29;

//	perdev31 = thermo31 - LitThermo31;
	perdev32 = thermo32 - LitThermo32;
	perdev33 = thermo33 - LitThermo33;
	perdev34 = thermo34 - LitThermo34;
	perdev35 = thermo35 - LitThermo35;
	perdev36 = thermo36 - LitThermo36;
	perdev37 = thermo37 - LitThermo37;
	perdev38 = thermo38 - LitThermo38;
	perdev39 = thermo39 - LitThermo39;
	perdev40 = thermo40 - LitThermo40;
	perdev41 = thermo41 - LitThermo41;
	perdev42 = thermo42 - LitThermo42;

	perdev30 = thermo30 - LitThermo30;
	perdev117= thermo117 - LitThermo117;
	perdev118= thermo118 - LitThermo118;
	perdev119= thermo119 - LitThermo119;
	perdev120= thermo120 - LitThermo120;
	perdev121= thermo121 - LitThermo121;
	perdev122= thermo122 - LitThermo122;
	perdev123= thermo123 - LitThermo123;

	perdev43 = thermo43 - LitThermo43;
	perdev44 = thermo44 - LitThermo44;
	perdev45 = thermo45 - LitThermo45;
	perdev46 = thermo46 - LitThermo46;
	perdev47 = thermo47 - LitThermo47;
	perdev48 = thermo48 - LitThermo48;
	perdev49 = thermo49 - LitThermo49;
	perdev50 = thermo50 - LitThermo50;
	perdev51 = thermo51 - LitThermo51;
	perdev52 = thermo52 - LitThermo52;
	perdev53 = thermo53 - LitThermo53;
	perdev54 = thermo54 - LitThermo54;
	perdev55 = thermo55 - LitThermo55;
	perdev56 = thermo56 - LitThermo56;
	perdev57 = thermo57 - LitThermo57;
	perdev58 = thermo58 - LitThermo58;
	perdev59 = thermo59 - LitThermo59;
	perdev60 = thermo60 - LitThermo60;
	perdev61 = thermo61 - LitThermo61;
	perdev62 = thermo62 - LitThermo62;
	perdev63 = thermo63 - LitThermo63;
	perdev64 = thermo64 - LitThermo64;
	perdev65 = thermo65 - LitThermo65;
	perdev66 = thermo66 - LitThermo66;
	perdev67 = thermo67 - LitThermo67;
	perdev68 = thermo68 - LitThermo68;
	perdev69 = thermo69 - LitThermo69;
	perdev70 = thermo70 - LitThermo70;
	perdev71 = thermo71 - LitThermo71;
	perdev72 = thermo72 - LitThermo72;
	perdev73 = thermo73 - LitThermo73;
	perdev74 = thermo74 - LitThermo74;
	perdev75 = thermo75 - LitThermo75;
	perdev76 = thermo76 - LitThermo76;
	perdev77 = thermo77 - LitThermo77;
	perdev78 = thermo78 - LitThermo78;
	perdev79 = thermo79 - LitThermo79;
	perdev80 = thermo80 - LitThermo80;
	perdev81 = thermo81 - LitThermo81;
	perdev82 = thermo82 - LitThermo82;
	perdev83 = thermo83 - LitThermo83;
	perdev84 = thermo84 - LitThermo84;
	perdev85 = thermo85 - LitThermo85;
	perdev86 = thermo86 - LitThermo86;
	perdev87 = thermo87 - LitThermo87;
	perdev88 = thermo88 - LitThermo88;
	perdev89 = thermo89 - LitThermo89;
	perdev90 = thermo90 - LitThermo90;
	perdev91 = thermo91 - LitThermo91;
	perdev92 = thermo92 - LitThermo92;
	perdev93 = thermo93 - LitThermo93;
	perdev94 = thermo94 - LitThermo94;
	perdev95 = thermo95 - LitThermo95;
	perdev96 = thermo96 - LitThermo96;
	perdev97 = thermo97 - LitThermo97;
	perdev98 = thermo98 - LitThermo98;
	perdev99 = thermo99 - LitThermo99;
	perdev100 = thermo100 - LitThermo100;
	perdev101 = thermo101 - LitThermo101;
	perdev102 = thermo102 - LitThermo102;
	perdev103 = thermo103 - LitThermo103;
	perdev104 = thermo104 - LitThermo104;
	perdev105 = thermo105 - LitThermo105;
	perdev106 = thermo106 - LitThermo106;
	perdev107 = thermo107 - LitThermo107;
	perdev108 = thermo108 - LitThermo108;
	perdev109 = thermo109 - LitThermo109;
	perdev110 = thermo110 - LitThermo110;
	perdev111 = thermo111 - LitThermo111;
	perdev112 = thermo112 - LitThermo112;
	perdev113 = thermo113 - LitThermo113;
	perdev114 = thermo114 - LitThermo114;
	perdev115 = thermo115 - LitThermo115;
	perdev116 = thermo116 - LitThermo116;

	perdev126 = thermo126 - LitThermo126;
	perdev127 = thermo127 - LitThermo127;
	perdev128 = thermo128 - LitThermo128;
	perdev129 = thermo129 - LitThermo129;
	perdev130 = thermo130 - LitThermo130;
	perdev131 = thermo131 - LitThermo131;
	perdev132 = thermo132 - LitThermo132;
	perdev133 = thermo133 - LitThermo133;
	perdev134 = thermo134 - LitThermo134;
	perdev135 = thermo135 - LitThermo135;
	perdev136 = thermo136 - LitThermo136;
	perdev137 = thermo137 - LitThermo137;
	perdev138 = thermo138 - LitThermo138;
	perdev139 = thermo139 - LitThermo139;
	perdev140 = thermo140 - LitThermo140;
	perdev141 = thermo141 - LitThermo141;
	perdev142 = thermo142 - LitThermo142;
	perdev143 = thermo143 - LitThermo143;
	perdev144 = thermo144 - LitThermo144;
	perdev145 = thermo145 - LitThermo145;
	perdev146 = thermo146 - LitThermo146;
	perdev147 = thermo147 - LitThermo147;
	perdev148 = thermo148 - LitThermo148;
	perdev149 = thermo149 - LitThermo149;
	perdev150 = thermo150 - LitThermo150;
	perdev151 = thermo151 - LitThermo151;
	perdev152 = thermo152 - LitThermo152;
	perdev153 = thermo153 - LitThermo153;
	perdev154 = thermo154 - LitThermo154;
	perdev155 = thermo155 - LitThermo155;
	perdev156 = thermo156 - LitThermo156;
	perdev157 = thermo157 - LitThermo157;
	perdev158 = thermo158 - LitThermo158;
	perdev159 = thermo159 - LitThermo159;
	perdev160 = thermo160 - LitThermo160;
	perdev161 = thermo161 - LitThermo161;
	perdev162 = thermo162 - LitThermo162;
	perdev163 = thermo163 - LitThermo163;

	perdev164 = thermo164 - LitThermo164;
	perdev165 = thermo165 - LitThermo165;
	perdev166 = thermo166 - LitThermo166;
	perdev167 = thermo167 - LitThermo167;
	perdev168 = thermo168 - LitThermo168;
	perdev169 = thermo169 - LitThermo169;
	perdev170 = thermo170 - LitThermo170;
	perdev171 = thermo171 - LitThermo171;
	perdev172 = thermo172 - LitThermo172;
	perdev173 = thermo173 - LitThermo173;
	perdev174 = thermo174 - LitThermo174;
	perdev175 = thermo175 - LitThermo175;
	perdev176 = thermo176 - LitThermo176;
	perdev177 = thermo177 - LitThermo177;
	perdev178 = thermo178 - LitThermo178;
	perdev179 = thermo179 - LitThermo179;
	perdev180 = thermo180 - LitThermo180;
	perdev181 = thermo181 - LitThermo181;
	perdev182 = thermo182 - LitThermo182;
	perdev183 = thermo183 - LitThermo183;
	perdev184 = thermo184 - LitThermo184;
	perdev185 = thermo185 - LitThermo185;
	perdev186 = thermo186 - LitThermo186;
	perdev187 = thermo187 - LitThermo187;
	perdev188 = thermo188 - LitThermo188;
	perdev189 = thermo189 - LitThermo189;
	perdev190 = thermo190 - LitThermo190;
	perdev191 = thermo191 - LitThermo191;
	perdev192 = thermo192 - LitThermo192;
	perdev193 = thermo193 - LitThermo193;
	perdev194 = thermo194 - LitThermo194;
	perdev195 = thermo195 - LitThermo195;
	perdev196 = thermo196 - LitThermo196;
	perdev197 = thermo197 - LitThermo197;
	perdev198 = thermo198 - LitThermo198;
	perdev199 = thermo199 - LitThermo199;
	perdev200 = thermo200 - LitThermo200;
	perdev201 = thermo201 - LitThermo201;
	perdev202 = thermo202 - LitThermo202;
	perdev203 = thermo203 - LitThermo203;
	perdev204 = thermo204 - LitThermo204;
	perdev205 = thermo205 - LitThermo205;
	perdev206 = thermo206 - LitThermo206;
	perdev207 = thermo207 - LitThermo207;

	perdev214 = thermo214 - LitThermo214;
	perdev215 = thermo215 - LitThermo215;
	perdev216 = thermo216 - LitThermo216;
	perdev217 = thermo217 - LitThermo217;
	perdev218 = thermo218 - LitThermo218;
	perdev219 = thermo219 - LitThermo219;
	perdev220 = thermo220 - LitThermo220;
	perdev221 = thermo221 - LitThermo221;
	perdev222 = thermo222 - LitThermo222;
	perdev223 = thermo223 - LitThermo223;

	perdev208 = thermo208 - LitThermo208;
	perdev209 = thermo209 - LitThermo209;
	perdev210 = thermo210 - LitThermo210;
	perdev211 = thermo211 - LitThermo211;
	perdev224 = thermo224 - LitThermo224;
	perdev225 = 0.0;
        perdev226 = 0.0;
        perdev227 = 0.0;
        perdev228 = 0.0;
        perdev229 = 0.0;
        perdev230 = 0.0;
        perdev231 = 0.0;
        perdev232 = 0.0;
//	perdev233 = 0.0;
	perdev233 = thermo233 - LitThermo233;
	perdev234 = thermo234 - LitThermo234;
	perdev235 = thermo235 - LitThermo235;
	perdev236 = thermo236 - LitThermo236;

	perdev238=thermo238 - LitThermo238;
        perdev239=thermo239 - LitThermo239;
        perdev240=thermo240 - LitThermo240;
        perdev241=thermo241 - LitThermo241;
        perdev242=thermo242 - LitThermo242;
        perdev243=thermo243 - LitThermo243;
	perdev244= thermo244 - LitThermo244;
	perdev245= thermo245 - LitThermo245;
	perdev246= thermo246 - LitThermo246;
	perdev247= thermo247 - LitThermo247;
	perdev248= thermo248 - LitThermo248;
//	perdev249=0.0;
//	perdev250=0.0;
	perdev251=thermo251 - LitThermo251;
	perdev252=thermo252 - LitThermo29 - LitThermo251;
	perdev253 = thermo253 - LitThermo253;
	perdev254 = thermo254 - LitThermo254;
	
	perdev256 = thermo256 - LitThermo256;
	perdev257 = thermo257 - LitThermo257;
	perdev258 = thermo258 - LitThermo258;
	perdev259 = thermo259 - LitThermo259;
	perdev260 = thermo260 - LitThermo260;
	perdev261 = thermo261 - LitThermo261;
	perdev262 = thermo262 - LitThermo262;
	perdev263 = thermo263 - LitThermo263;
	perdev264 = thermo264 - LitThermo264;
	perdev265 = thermo265 - LitThermo265;
	perdev266 = thermo266 - LitThermo266;
	perdev267 = thermo267 - LitThermo267;
	perdev268 = thermo268 - LitThermo268;
	perdev269 = thermo269 - LitThermo269;
	perdev270 = thermo270 - LitThermo270;
	perdev271 = thermo271 - LitThermo271;
	perdev272 = thermo272 - LitThermo272;
	perdev273 = thermo273 - LitThermo273;
	perdev274 = thermo274 - LitThermo274;
	perdev275 = thermo275 - LitThermo275;
	perdev276 = thermo276 - LitThermo276;
	perdev277 = thermo277 - LitThermo277;
	perdev278 = thermo278 - LitThermo278;
	perdev279 = thermo279 - LitThermo279;
	perdev280 = thermo280 - LitThermo280;
	perdev281 = thermo281 - LitThermo281;
	perdev282 = thermo282 - LitThermo282;
	perdev283 = thermo283 - LitThermo283;
	perdev284 = thermo284 - LitThermo284;
	perdev285 = thermo285 - LitThermo285;
	perdev286 = thermo286 - LitThermo286;
	perdev287 = thermo287 - LitThermo287;
	perdev288 = thermo288 - LitThermo288;
	perdev289 = thermo289 - LitThermo289;
	perdev290 = thermo290 - LitThermo290;
	perdev291 = thermo291 - LitThermo291;
	perdev292 = thermo292 - LitThermo292;
	perdev293 = thermo293 - LitThermo293;
	perdev294 = thermo294 - LitThermo294;
	perdev295 = thermo295 - LitThermo295;
	perdev296 = thermo296 - LitThermo296;
	perdev297 = thermo297 - LitThermo297;
	perdev298 = thermo298 - LitThermo298;
	perdev299 = thermo299 - LitThermo299;
	perdev300 = thermo300 - LitThermo300;
	perdev301 = thermo301 - LitThermo301;
	perdev302 = thermo302 - LitThermo302;
	perdev303 = thermo303 - LitThermo303;
	perdev304 = thermo304 - LitThermo304;
	perdev305 = thermo305 - LitThermo305;
	perdev306 = thermo306 - LitThermo306;
	perdev307 = thermo307 - LitThermo307;
	perdev308 = thermo308 - LitThermo308;
	perdev309 = thermo309 - LitThermo309;
	perdev310 = thermo310 - LitThermo310;
	perdev311 = thermo311 - LitThermo311;
	perdev312 = thermo312 - LitThermo312;
	perdev313 = thermo313 - LitThermo313;
	perdev314 = thermo314 - LitThermo314;
	perdev315 = thermo315 - LitThermo315;
	perdev316 = thermo316 - LitThermo316;
	perdev317 = thermo317 - LitThermo317;
	perdev318 = thermo318 - LitThermo318;
	perdev319 = thermo319 - LitThermo319;
	perdev320 = thermo320 - LitThermo320;
	perdev321 = thermo321 - LitThermo321;
	perdev322 = thermo322 - LitThermo322;
	perdev323 = thermo323 - LitThermo323;
	perdev324 = thermo324 - LitThermo324;
	perdev325 = thermo325 - LitThermo325;
	perdev326 = thermo326 - LitThermo326;
	perdev327 = thermo327 - LitThermo327;
	perdev328 = thermo328 - LitThermo328;
	perdev329 = thermo329 - LitThermo329;
	perdev330 = thermo330 - LitThermo330;
	perdev331 = thermo331 - LitThermo331;
	perdev332 = thermo332 - LitThermo332;
	perdev333 = thermo333 - LitThermo333;
	perdev334 = thermo334 - LitThermo334;
	perdev335 = thermo335 - LitThermo335;
	perdev336 = thermo336 - LitThermo336;
	perdev337 = thermo337 - LitThermo337;
	perdev338 = thermo338 - LitThermo338;
	perdev339 = thermo339 - LitThermo339;
	perdev340 = thermo340 - LitThermo340;
	perdev341 = thermo341 - LitThermo341;
	perdev342 = thermo342 - LitThermo342;
	perdev343 = thermo343 - LitThermo343;
	perdev344 = thermo344 - LitThermo344;
	perdev345 = thermo345 - LitThermo345;
	perdev346 = thermo346 - LitThermo346;
	perdev347 = thermo347 - LitThermo347;
	perdev348 = thermo348 - LitThermo348;
	perdev349 = thermo349 - LitThermo349;
	perdev350 = thermo350 - LitThermo350;
	perdev351 = thermo351 - LitThermo351;
	perdev352 = thermo352 - LitThermo352;
	perdev353 = thermo353 - LitThermo353;
	perdev354 = thermo354 - LitThermo354;
	perdev355 = thermo355 - LitThermo355;
	perdev356 = thermo356 - LitThermo356;
	perdev357 = thermo357 - LitThermo357;
	perdev358 = thermo358 - LitThermo358;
	perdev359 = thermo359 - LitThermo359;
	perdev360 = thermo360 - LitThermo360;
	perdev361 = thermo361 - LitThermo361;
	perdev362 = thermo362 - LitThermo362;
	perdev363 = thermo363 - LitThermo363;
	perdev364 = thermo364 - LitThermo364;
	perdev365 = thermo365 - LitThermo365;
	perdev366 = thermo366 - LitThermo366;
	perdev367 = thermo367 - LitThermo367;
	perdev368 = thermo368 - LitThermo368;
	perdev369 = thermo369 - LitThermo369;
	perdev370 = thermo370 - LitThermo370;
	perdev371 = thermo371 - LitThermo371;
	perdev372 = thermo372 - LitThermo372;
	perdev373 = thermo373 - LitThermo373;
	perdev374 = thermo374 - LitThermo374;
	perdev375 = thermo375 - LitThermo375;
	perdev376 = thermo376 - LitThermo376;
	perdev377 = thermo377 - LitThermo377;
	perdev378 = thermo378 - LitThermo378;
	perdev379 = thermo379 - LitThermo379;
	perdev380 = thermo380 - LitThermo380;
	perdev381 = thermo381 - LitThermo381;
	perdev382 = thermo382 - LitThermo382;
	perdev383 = thermo383 - LitThermo383;
	perdev384 = thermo384 - LitThermo384;
	perdev385 = thermo385 - LitThermo385;
	perdev386 = thermo386 - LitThermo386;
	perdev387 = thermo387 - LitThermo387;
	perdev388 = thermo388 - LitThermo388;
	perdev389 = thermo389 - LitThermo389;
	perdev390 = thermo390 - LitThermo390;
	perdev391 = thermo391 - LitThermo391;
	perdev392 = thermo392 - LitThermo392;
	perdev393 = thermo393 - LitThermo393;
	perdev394 = thermo394 - LitThermo394;
	perdev395 = thermo395 - LitThermo395;
	perdev396 = thermo396 - LitThermo396;
	perdev397 = thermo397 - LitThermo397;
	perdev398 = thermo398 - LitThermo398;
	perdev399 = thermo399 - LitThermo399;
	perdev400 = thermo400 - LitThermo400;
	perdev401 = thermo401 - LitThermo401;
	perdev402 = thermo402 - LitThermo402;
	perdev403 = thermo403 - LitThermo403;
	perdev404 = thermo404 - LitThermo404;
	perdev405 = thermo405 - LitThermo405;
	perdev406 = thermo406 - LitThermo406;
	perdev407 = thermo407 - LitThermo407;
	perdev408 = thermo408 - LitThermo408;
	perdev409 = thermo409 - LitThermo409;
	perdev410 = thermo410 - LitThermo410;
	perdev411 = thermo411 - LitThermo411;
	perdev412 = thermo412 - LitThermo412;
	perdev413 = thermo413 - LitThermo413;
	perdev414 = thermo414 - LitThermo414;
	perdev415 = thermo415 - LitThermo415;
	perdev416 = thermo416 - LitThermo416;
	perdev417 = thermo417 - LitThermo417;
	perdev418 = thermo418 - LitThermo418;
	perdev419 = thermo419 - LitThermo419;
	perdev420 = thermo420 - LitThermo420;
	perdev421 = thermo421 - LitThermo421;
	perdev422 = thermo422 - LitThermo422;
	perdev423 = thermo423 - LitThermo423;
	perdev424 = thermo424 - LitThermo424;
	perdev425 = thermo425 - LitThermo425;
	perdev426 = thermo426 - LitThermo426;
	perdev427 = thermo427 - LitThermo427;
	perdev428 = thermo428 - LitThermo428;
	perdev429 = thermo429 - LitThermo429;
	perdev430 = thermo430 - LitThermo430;
	perdev431 = thermo431 - LitThermo431;
	perdev432 = thermo432 - LitThermo432;
	perdev433 = thermo433 - LitThermo433;
	perdev434 = thermo434 - LitThermo434;
	perdev435 = thermo435 - LitThermo435;
	perdev436 = thermo436 - LitThermo436;
	perdev437 = thermo437 - LitThermo437;
	perdev438 = thermo438 - LitThermo438;
	perdev439 = thermo439 - LitThermo439;
	perdev440 = thermo440 - LitThermo440;
	perdev441 = thermo441 - LitThermo441;
	perdev442 = thermo442 - LitThermo442;
	perdev443 = thermo443 - LitThermo443;
	perdev444 = thermo444 - LitThermo444;
	perdev445 = thermo445 - LitThermo445;
	perdev446 = thermo446 - LitThermo446;
	perdev447 = thermo447 - LitThermo447;
	perdev448 = thermo448 - LitThermo448;
	perdev449 = thermo449 - LitThermo449;
	perdev450 = thermo450 - LitThermo450;
	perdev451 = thermo451 - LitThermo451;
	perdev452 = thermo452 - LitThermo452;
	perdev453 = thermo453 - LitThermo453;
	perdev454 = thermo454 - LitThermo454;
	perdev455 = thermo455 - LitThermo455;
	perdev456 = thermo456 - LitThermo456;
	perdev457 = thermo457 - LitThermo457;
	perdev458 = thermo458 - LitThermo458;
	perdev459 = thermo459 - LitThermo459;
	perdev460 = thermo460 - LitThermo460;
	perdev461 = thermo461 - LitThermo461;
	perdev462 = thermo462 - LitThermo462;
	perdev463 = thermo463 - LitThermo463;
	perdev464 = thermo464 - LitThermo464;
	perdev465 = thermo465 - LitThermo465;
	perdev466 = thermo466 - LitThermo466;
	perdev467 = thermo467 - LitThermo467;
	perdev468 = thermo468 - LitThermo468;
	perdev469 = thermo469 - LitThermo469;
	perdev470 = thermo470 - LitThermo470;
	perdev471 = thermo471 - LitThermo471;
	perdev472 = thermo472 - LitThermo472;
	perdev473 = thermo473 - LitThermo473;
	perdev474 = thermo474 - LitThermo474;
	perdev475 = thermo475 - LitThermo475;
	perdev476 = thermo476 - LitThermo476;
	perdev477 = thermo477 - LitThermo477;
	perdev478 = thermo478 - LitThermo478;
	perdev479 = thermo479 - LitThermo479;
	perdev480 = thermo480 - LitThermo480;
	perdev481 = thermo481 - LitThermo481;
	perdev482 = thermo482 - LitThermo482;
	perdev483 = thermo483 - LitThermo483;
	perdev484 = thermo484 - LitThermo484;
	perdev485 = thermo485 - LitThermo485;
	perdev486 = thermo486 - LitThermo486;
	perdev487 = thermo487 - LitThermo487;
	perdev488 = thermo488 - LitThermo488;
	perdev489 = thermo489 - LitThermo489;
	perdev490 = thermo490 - LitThermo490;
	perdev491 = thermo491 - LitThermo491;
	perdev492 = thermo492 - LitThermo492;
	perdev493 = thermo493 - LitThermo493;
	perdev494 = thermo494 - LitThermo494;
	perdev495 = thermo495 - LitThermo495;
	perdev496 = thermo496 - LitThermo496;
	perdev497 = thermo497 - LitThermo497;
	perdev498 = thermo498 - LitThermo498;
	perdev499 = thermo499 - LitThermo499;
	perdev500 = thermo500 - LitThermo500;
	perdev501 = thermo501 - LitThermo501;
	perdev502 = thermo502 - LitThermo502;
	perdev503 = thermo503 - LitThermo503;
	perdev504 = thermo504 - LitThermo504;
	perdev505 = thermo505 - LitThermo505;
	perdev506 = thermo506 - LitThermo506;
	perdev507 = thermo507 - LitThermo507;
	perdev508 = thermo508 - LitThermo508;
	perdev509 = thermo509 - LitThermo509;
	perdev510 = thermo510 - LitThermo510;
	perdev511 = thermo511 - LitThermo511;
	perdev512 = thermo512 - LitThermo512;
	perdev513 = thermo513 - LitThermo513;
	perdev514 = thermo514 - LitThermo514;
	perdev515 = thermo515 - LitThermo515;
	perdev516 = thermo516 - LitThermo516;
	perdev517 = thermo517 - LitThermo517;
	perdev518 = thermo518 - LitThermo518;
	perdev519 = thermo519 - LitThermo519;
	perdev520 = thermo520 - LitThermo520;
	perdev521 = thermo521 - LitThermo521;
	perdev522 = thermo522 - LitThermo522;
	perdev523 = thermo523 - LitThermo523;
	perdev524 = thermo524 - LitThermo524;
	perdev525 = thermo525 - LitThermo525;
	perdev526 = thermo526 - LitThermo526;
	perdev527 = thermo527 - LitThermo527;
	perdev528 = thermo528 - LitThermo528;
	perdev529 = thermo529 - LitThermo529;
	perdev530 = thermo530 - LitThermo530;
	perdev531 = thermo531 - LitThermo531;
	perdev532 = thermo532 - LitThermo532;
	perdev533 = thermo533 - LitThermo533;
	perdev534 = thermo534 - LitThermo534;
	perdev535 = thermo535 - LitThermo535;
	perdev536 = thermo536 - LitThermo536;
	perdev537 = thermo537 - LitThermo537;
	perdev538 = thermo538 - LitThermo538;
	perdev539 = thermo539 - LitThermo539;
	perdev540 = thermo540 - LitThermo540;
	perdev541 = thermo541 - LitThermo541;
	perdev542 = thermo542 - LitThermo542;
	perdev543 = thermo543 - LitThermo543;
	perdev544 = thermo544 - LitThermo544;
	perdev545 = thermo545 - LitThermo545;
	perdev546 = thermo546 - LitThermo546;
	perdev547 = thermo547 - LitThermo547;
	perdev548 = thermo548 - LitThermo548;
	perdev549 = thermo549 - LitThermo549;
	perdev550 = thermo550 - LitThermo550;
	perdev551 = thermo551 - LitThermo551;
	perdev552 = thermo552 - LitThermo552;
	perdev553 = thermo553 - LitThermo553;
	perdev554 = thermo554 - LitThermo554;
	perdev555 = thermo555 - LitThermo555;
	perdev556 = thermo556 - LitThermo556;
	perdev557 = thermo557 - LitThermo557;
	perdev558 = thermo558 - LitThermo558;
	perdev559 = thermo559 - LitThermo559;
	perdev560 = thermo560 - LitThermo560;
	perdev561 = thermo561 - LitThermo561;
	perdev562 = thermo562 - LitThermo562;
	perdev563 = thermo563 - LitThermo563;
	perdev564 = thermo564 - LitThermo564;
	perdev565 = thermo565 - LitThermo565;
	perdev566 = thermo566 - LitThermo566;
	perdev567 = thermo567 - LitThermo567;
	perdev568 = thermo568 - LitThermo568;
	perdev569 = thermo569 - LitThermo569;
	perdev570 = thermo570 - LitThermo570;
	perdev571 = thermo571 - LitThermo571;
	perdev572 = thermo572 - LitThermo572;
	perdev573 = thermo573 - LitThermo573;
	perdev574 = thermo574 - LitThermo574;
	perdev575 = thermo575 - LitThermo575;
	perdev576 = thermo576 - LitThermo576;
	perdev577 = thermo577 - LitThermo577;
	perdev578 = thermo578 - LitThermo578;
	perdev579 = thermo579 - LitThermo579;
	perdev580 = thermo580 - LitThermo580;
	perdev581 = thermo581 - LitThermo581;
	perdev582 = thermo582 - LitThermo582;
	perdev583 = thermo583 - LitThermo583;
	perdev584 = thermo584 - LitThermo584;
	perdev585 = thermo585 - LitThermo585;
	perdev586 = thermo586 - LitThermo586;
	perdev587 = thermo587 - LitThermo587;
	perdev588 = thermo588 - LitThermo588;
	perdev589 = thermo589 - LitThermo589;
	perdev590 = thermo590 - LitThermo590;
	perdev591 = thermo591 - LitThermo591;
	perdev592 = thermo592 - LitThermo592;
	perdev593 = thermo593 - LitThermo593;
	perdev594 = thermo594 - LitThermo594;
	perdev595 = thermo595 - LitThermo595;
	perdev596 = thermo596 - LitThermo596;
	perdev597 = thermo597 - LitThermo597;
	perdev598 = thermo598 - LitThermo598;
	perdev599 = thermo599 - LitThermo599;
	perdev600 = thermo600 - LitThermo600;
	perdev601 = thermo601 - LitThermo601;
	perdev602 = thermo602 - LitThermo602;
	perdev603 = thermo603 - LitThermo603;
	perdev604 = thermo604 - LitThermo604;
	perdev605 = thermo605 - LitThermo605;
	perdev606 = thermo606 - LitThermo606;
	perdev607 = thermo607 - LitThermo607;
	perdev608 = thermo608 - LitThermo608;
	perdev609 = thermo609 - LitThermo609;
	perdev610 = thermo610 - LitThermo610;
	perdev611 = thermo611 - LitThermo611;
	perdev612 = thermo612 - LitThermo612;
	perdev613 = thermo613 - LitThermo613;
	perdev614 = thermo614 - LitThermo614;
	perdev615 = thermo615 - LitThermo615;
	perdev616 = thermo616 - LitThermo616;
	perdev617 = thermo617 - LitThermo617;
	perdev618 = thermo618 - LitThermo618;
	perdev619 = thermo619 - LitThermo619;
	perdev620 = thermo620 - LitThermo620;
	perdev621 = thermo621 - LitThermo621;
	perdev622 = thermo622 - LitThermo622;
	perdev623 = thermo623 - LitThermo623;
	perdev624 = thermo624 - LitThermo624;
	perdev625 = thermo625 - LitThermo625;
	perdev626 = thermo626 - LitThermo626;
	perdev627 = thermo627 - LitThermo627;
	perdev628 = thermo628 - LitThermo628;
	perdev629 = thermo629 - LitThermo629;
	perdev630 = thermo630 - LitThermo630;
	perdev631 = thermo631 - LitThermo631;
	perdev632 = thermo632 - LitThermo632;
	perdev633 = thermo633 - LitThermo633;
	perdev634 = thermo634 - LitThermo634;
	perdev635 = thermo635 - LitThermo635;
	perdev636 = thermo636 - LitThermo636;
	perdev637 = thermo637 - LitThermo637;
	perdev638 = thermo638 - LitThermo638;
	perdev639 = thermo639 - LitThermo639;
	perdev640 = thermo640 - LitThermo640;
	perdev641 = thermo641 - LitThermo641;
	perdev642 = thermo642 - LitThermo642;
	perdev643 = thermo643 - LitThermo643;
	perdev644 = thermo644 - LitThermo644;
	perdev645 = thermo645 - LitThermo645;
	perdev646 = thermo646 - LitThermo646;
	perdev647 = thermo647 - LitThermo647;
	perdev648 = thermo648 - LitThermo648;
	perdev649 = thermo649 - LitThermo649;
	perdev650 = thermo650 - LitThermo650;
	perdev651 = thermo651 - LitThermo651;
	perdev652 = thermo652 - LitThermo652;
	perdev653 = thermo653 - LitThermo653;
	perdev654 = thermo654 - LitThermo654;
	perdev655 = thermo655 - LitThermo655;
	perdev656 = thermo656 - LitThermo656;
	perdev657 = thermo657 - LitThermo657;
	perdev658 = thermo658 - LitThermo658;
	perdev659 = thermo659 - LitThermo659;
	perdev660 = thermo660 - LitThermo660;
	perdev661 = thermo661 - LitThermo661;
	perdev662 = thermo662 - LitThermo662;
	perdev663 = thermo663 - LitThermo663;
	perdev664 = thermo664 - LitThermo664;
	perdev665 = thermo665 - LitThermo665;
	perdev666 = thermo666 - LitThermo666;
	perdev667 = thermo667 - LitThermo667;
	perdev668 = thermo668 - LitThermo668;
	perdev669 = thermo669 - LitThermo669;
	perdev670 = thermo670 - LitThermo670;
	perdev671 = thermo671 - LitThermo671;
	perdev672 = thermo672 - LitThermo672;
	perdev673 = thermo673 - LitThermo673;
	perdev674 = thermo674 - LitThermo674;
	perdev675 = thermo675 - LitThermo675;
	perdev676 = thermo676 - LitThermo676;
	perdev677 = thermo677 - LitThermo677;
	perdev678 = thermo678 - LitThermo678;
	perdev679 = thermo679 - LitThermo679;
	perdev680 = thermo680 - LitThermo680;
	perdev681 = thermo681 - LitThermo681;
	perdev682 = thermo682 - LitThermo682;
	perdev683 = thermo683 - LitThermo683;
	perdev684 = thermo684 - LitThermo684;
	perdev685 = thermo685 - LitThermo685;
	perdev686 = thermo686 - LitThermo686;
	perdev687 = thermo687 - LitThermo687;
	perdev688 = thermo688 - LitThermo688;
	perdev689 = thermo689 - LitThermo689;
	perdev690 = thermo690 - LitThermo690;
	perdev691 = thermo691 - LitThermo691;
	perdev692 = thermo692 - LitThermo692;
	perdev693 = thermo693 - LitThermo693;
	perdev711 = thermo711 - LitThermo711;

	//scaled deviation
	dev1 = perdev1 / (ESCALE * fabs(LitThermo1) + KT);  
	dev2 = perdev2 / (ESCALE * fabs(LitThermo2) + KT);  
	dev3 = perdev3 / (ESCALE * fabs(LitThermo3) + KT);  
	dev4 = perdev4 / (ESCALE * fabs(LitThermo4) + KT);  
	dev5 = perdev5 / (ESCALE * fabs(LitThermo5) + KT);  
	dev6 = perdev6 / (ESCALE * fabs(LitThermo6) + KT);  
	dev7 = perdev7 / (ESCALE * fabs(LitThermo7) + KT);  
	dev8 = perdev8 / (ESCALE * fabs(LitThermo8) + KT);  
	dev9 = perdev9 / (ESCALE * fabs(LitThermo9) + KT);  
	dev10 = perdev10 / (ESCALE * fabs(LitThermo10) + KT);  
	dev11 = perdev11 / (ESCALE * fabs(LitThermo11) + KT);  
	dev12 = perdev12 / (ESCALE * fabs(LitThermo12) + KT);  
	dev13 = perdev13 / (ESCALE * fabs(LitThermo13) + KT);  
	dev14 = perdev14 / (ESCALE * fabs(LitThermo14) + KT);  
	dev15 = perdev15 / (ESCALE * fabs(LitThermo15) + KT);  
	dev16 = perdev16 / (ESCALE * fabs(LitThermo16) + KT);  
	dev17 = perdev17 / (ESCALE * fabs(LitThermo17) + KT);  
	dev18 = perdev18 / (ESCALE * fabs(LitThermo18) + KT);  
	dev19 = perdev19 / (ESCALE * fabs(LitThermo19) + KT);  
	dev20 = perdev20 / (ESCALE * fabs(LitThermo20) + KT);  
	dev21 = perdev21 / (ESCALE * fabs(LitThermo21) + KT);  
	dev22 = perdev22 / (ESCALE * fabs(LitThermo22) + KT);  
	dev23 = perdev23 / (ESCALE * fabs(LitThermo23) + KT);  
	dev24 = perdev24 / (ESCALE * fabs(LitThermo24) + KT);  
	dev25 = perdev25 / (ESCALE * fabs(LitThermo25) + KT);  
	dev26 = perdev26 / (ESCALE * fabs(LitThermo26) + KT);  
	dev27 = perdev27 / (ESCALE * fabs(LitThermo27) + KT);  
	dev28 = perdev28 / (ESCALE * fabs(LitThermo28) + KT);  
	dev29 = perdev29 / (ESCALE * fabs(LitThermo29) + KT);  

//	dev31 = perdev31 / ENERGY_L;
	dev32 = perdev32 / (ESCALE * fabs(LitThermo32) + KT);  
	dev33 = perdev33 / (ESCALE * fabs(LitThermo33) + KT);  
	dev34 = perdev34 / (ESCALE * fabs(LitThermo34) + KT);  
	dev35 = perdev35 / (ESCALE * fabs(LitThermo35) + KT);  
	dev36 = perdev36 / (ESCALE * fabs(LitThermo36) + KT);  
	dev37 = perdev37 / (ESCALE * fabs(LitThermo37) + KT);  
	dev38 = perdev38 / (ESCALE * fabs(LitThermo38) + KT);  
	dev39 = perdev39 / (ESCALE * fabs(LitThermo39) + KT);  
	dev156 = perdev156 / (ESCALE * fabs(LitThermo156) + KT);  
	dev163 = perdev163 / (ESCALE * fabs(LitThermo163) + KT);  
	dev41 = perdev41 / (ESCALE * fabs(LitThermo41) + KT);  
	dev157 = perdev157 / (ESCALE * fabs(LitThermo157) + KT);  
	dev40 = perdev40 / (ESCALE * fabs(LitThermo40) + KT);  
	dev122= perdev122 / (ESCALE * fabs(LitThermo122) + KT);
	dev30 = perdev30 / (ESCALE * fabs(LitThermo30) + KT);  
	dev42 = perdev42 / (ESCALE * fabs(LitThermo42) + KT);  

	dev117= perdev117 / (ESCALE * fabs(LitThermo117) + KT); 
	dev118= perdev118 / (ESCALE * fabs(LitThermo118) + KT); 
	dev119= perdev119 / (ESCALE * fabs(LitThermo119) + KT); 
	dev120= perdev120 / (ESCALE * fabs(LitThermo120) + KT); 
	dev121= perdev121 / (ESCALE * fabs(LitThermo121) + KT); 
                                                  
	dev123= perdev123 / (ESCALE * fabs(LitThermo123) + KT); 

	dev43 = perdev43 / (ESCALE * fabs(LitThermo43) + KT);  
	dev44 = perdev44 / (ESCALE * fabs(LitThermo44) + KT);  
	dev45 = perdev45 / (ESCALE * fabs(LitThermo45) + KT);  
	dev46 = perdev46 / (ESCALE * fabs(LitThermo46) + KT);  
	dev47 = perdev47 / (ESCALE * fabs(LitThermo47) + KT);  
	dev48 = perdev48 / (ESCALE * fabs(LitThermo48) + KT);  
	dev49 = perdev49 / (ESCALE * fabs(LitThermo49) + KT);  
	dev50 = perdev50 / (ESCALE * fabs(LitThermo50) + KT);  
	dev51 = perdev51 / (ESCALE * fabs(LitThermo51) + KT);  
	dev52 = perdev52 / (ESCALE * fabs(LitThermo52) + KT);  
//	dev53 = perdev53 / ENERGY_L;
	dev54 =	perdev54 / (ESCALE * fabs(LitThermo54) + KT);  
	dev55 = perdev55 / (ESCALE * fabs(LitThermo55) + KT);  
	dev56 = perdev56 / (ESCALE * fabs(LitThermo56) + KT);  
	dev57 = perdev57 / (ESCALE * fabs(LitThermo57) + KT);  
	dev58 = perdev58 / (ESCALE * fabs(LitThermo58) + KT);  
	dev59 = perdev59 / (ESCALE * fabs(LitThermo59) + KT);  
	dev60 = perdev60 / (ESCALE * fabs(LitThermo60) + KT);  
	dev61 = perdev61 / (ESCALE * fabs(LitThermo61) + KT);  
	dev62 = perdev62 / (ESCALE * fabs(LitThermo62) + KT);  
	dev63 = perdev63 / (ESCALE * fabs(LitThermo63) + KT);  
	dev64 = perdev64 / (ESCALE * fabs(LitThermo64) + KT);  
	dev65 = perdev65 / (ESCALE * fabs(LitThermo65) + KT);  
	dev66 = perdev66 / (ESCALE * fabs(LitThermo66) + KT);  
	dev67 = perdev67 / (ESCALE * fabs(LitThermo67) + KT);  
	dev68 = perdev68 / (ESCALE * fabs(LitThermo68) + KT);  
	dev69 = perdev69 / (ESCALE * fabs(LitThermo69) + KT);  
	dev70 = perdev70 / (ESCALE * fabs(LitThermo70) + KT);  
	dev71 = perdev71 / (ESCALE * fabs(LitThermo71) + KT);  
	dev72 = perdev72 / (ESCALE * fabs(LitThermo72) + KT);  
	dev73 = perdev73 / (ESCALE * fabs(LitThermo73) + KT);  
	dev74 = perdev74 / (ESCALE * fabs(LitThermo74) + KT);  
	dev75 = perdev75 / (ESCALE * fabs(LitThermo75) + KT);  
	dev76 = perdev76 / (ESCALE * fabs(LitThermo76) + KT);  
	dev77 = perdev77 / (ESCALE * fabs(LitThermo77) + KT);  
	dev78 = perdev78 / (ESCALE * fabs(LitThermo78) + KT);  
	dev79 = perdev79 / (ESCALE * fabs(LitThermo79) + KT);  
	dev80 = perdev80 / (ESCALE * fabs(LitThermo80) + KT);  
	dev81 = perdev81 / (ESCALE * fabs(LitThermo81) + KT);  
	dev82 = perdev82 / (ESCALE * fabs(LitThermo82) + KT);  
	dev83 = perdev83 / (ESCALE * fabs(LitThermo83) + KT);  
	dev84 = perdev84 / (ESCALE * fabs(LitThermo84) + KT);  
	dev85 = perdev85 / (ESCALE * fabs(LitThermo85) + KT);  
	dev86 = perdev86 / (ESCALE * fabs(LitThermo86) + KT);  
	dev87 = perdev87 / (ESCALE * fabs(LitThermo87) + KT);  
	dev88 = perdev88 / (ESCALE * fabs(LitThermo88) + KT);  
	dev89 = perdev89 / (ESCALE * fabs(LitThermo89) + KT);  
//	dev90 = perdev90 / ENERGY_XL;
	dev91 = perdev91 / (ESCALE * fabs(LitThermo91) + KT);  
	dev92 = perdev92 / (ESCALE * fabs(LitThermo92) + KT);  
	dev93 = perdev93 / (ESCALE * fabs(LitThermo93) + KT);  
	dev94 = perdev94 / (ESCALE * fabs(LitThermo94) + KT);  
	dev95 = perdev95 / (ESCALE * fabs(LitThermo95) + KT);  
	dev96 = perdev96 / (ESCALE * fabs(LitThermo96) + KT);  
	dev97 = perdev97 / (ESCALE * fabs(LitThermo97) + KT);  
	dev98 = perdev98 / (ESCALE * fabs(LitThermo98) + KT);  
	dev99 = perdev99 / (ESCALE * fabs(LitThermo99) + KT);  
	dev100 = perdev100 / (ESCALE * fabs(LitThermo100) + KT);  
	dev101 = perdev101 / (ESCALE * fabs(LitThermo101) + KT);  
	dev102 = perdev102 / (ESCALE * fabs(LitThermo102) + KT);  
	dev103 = perdev103 / (ESCALE * fabs(LitThermo103) + KT);  
	dev104 = perdev104 / (ESCALE * fabs(LitThermo104) + KT);  
	dev105 = perdev105 / (ESCALE * fabs(LitThermo105) + KT);  
	dev106 = perdev106 / (ESCALE * fabs(LitThermo106) + KT);  
	dev107 = perdev107 / (ESCALE * fabs(LitThermo107) + KT);  
	dev108 = perdev108 / (ESCALE * fabs(LitThermo108) + KT);  
	dev109 = perdev109 / (ESCALE * fabs(LitThermo109) + KT);  
	dev110 = perdev110 / (ESCALE * fabs(LitThermo110) + KT);  
	dev111 = perdev111 / (ESCALE * fabs(LitThermo111) + KT);  
	dev112 = perdev112 / (ESCALE * fabs(LitThermo112) + KT);  
	dev113 = perdev113 / (ESCALE * fabs(LitThermo113) + KT);  
	dev114 = perdev114 / (ESCALE * fabs(LitThermo114) + KT);  
	dev115 = perdev115 / (ESCALE * fabs(LitThermo115) + KT);  
	dev116 = perdev116 / (ESCALE * fabs(LitThermo116) + KT);  

	dev126 = perdev126 / (ESCALE * fabs(LitThermo126) + KT);  
	dev127 = perdev127 / (ESCALE * fabs(LitThermo127) + KT);  
	dev128 = perdev128 / (ESCALE * fabs(LitThermo128) + KT);  
	dev129 = perdev129 / (ESCALE * fabs(LitThermo129) + KT);  
	dev130 = perdev130 / (ESCALE * fabs(LitThermo130) + KT);  
	dev131 = perdev131 / (ESCALE * fabs(LitThermo131) + KT);  
	dev132 = perdev132 / (ESCALE * fabs(LitThermo132) + KT);  
	dev133 = perdev133 / (ESCALE * fabs(LitThermo133) + KT);  
	dev134 = perdev134 / (ESCALE * fabs(LitThermo134) + KT);  
	dev135 = perdev135 / (ESCALE * fabs(LitThermo135) + KT);  
	dev136 = perdev136 / (ESCALE * fabs(LitThermo136) + KT);  
	dev137 = perdev137 / (ESCALE * fabs(LitThermo137) + KT);  
	dev138 = perdev138 / (ESCALE * fabs(LitThermo138) + KT);  
	dev139 = perdev139 / (ESCALE * fabs(LitThermo139) + KT);  
	dev140 = perdev140 / (ESCALE * fabs(LitThermo140) + KT);  
	dev141 = perdev141 / (ESCALE * fabs(LitThermo141) + KT);  
	dev142 = perdev142 / (ESCALE * fabs(LitThermo142) + KT);  
	dev143 = perdev143 / (ESCALE * fabs(LitThermo143) + KT);  
	dev144 = perdev144 / (ESCALE * fabs(LitThermo144) + KT);  
	dev145 = perdev145 / (ESCALE * fabs(LitThermo145) + KT);  
	dev146 = perdev146 / (ESCALE * fabs(LitThermo146) + KT);  
	dev147 = perdev147 / (ESCALE * fabs(LitThermo147) + KT);  
	dev148 = perdev148 / (ESCALE * fabs(LitThermo148) + KT);  
	dev149 = perdev149 / (ESCALE * fabs(LitThermo149) + KT);  
	dev150 = perdev150 / (ESCALE * fabs(LitThermo150) + KT);  
	dev151 = perdev151 / (ESCALE * fabs(LitThermo151) + KT);  
	dev152 = perdev152 / (ESCALE * fabs(LitThermo152) + KT);  
	dev153 = perdev153 / (ESCALE * fabs(LitThermo153) + KT);  
	dev154 = perdev154 / (ESCALE * fabs(LitThermo154) + KT);  
	dev155 = perdev155 / (ESCALE * fabs(LitThermo155) + KT);  

	dev159 = perdev159 / (ESCALE * fabs(LitThermo159) + KT);  
	dev160 = perdev160 / (ESCALE * fabs(LitThermo160) + KT);  
	dev161 = perdev161 / (ESCALE * fabs(LitThermo161) + KT);  
	dev162 = perdev162 / (ESCALE * fabs(LitThermo162) + KT);  

	dev164 = perdev164 / (ESCALE * fabs(LitThermo164) + KT);  
	dev165 = perdev165 / (ESCALE * fabs(LitThermo165) + KT);  
	dev166 = perdev166 / (ESCALE * fabs(LitThermo166) + KT);  
	dev167 = perdev167 / (ESCALE * fabs(LitThermo167) + KT);  
	dev168 = perdev168 / (ESCALE * fabs(LitThermo168) + KT);  
	dev169 = perdev169 / (ESCALE * fabs(LitThermo169) + KT);  
	dev170 = perdev170 / (ESCALE * fabs(LitThermo170) + KT);  
	dev171 = perdev171 / (ESCALE * fabs(LitThermo171) + KT);  
	dev172 = perdev172 / (ESCALE * fabs(LitThermo172) + KT);  
	dev173 = perdev173 / (ESCALE * fabs(LitThermo173) + KT);  
	dev174 = perdev174 / (ESCALE * fabs(LitThermo174) + KT);  
	dev175 = perdev175 / (ESCALE * fabs(LitThermo175) + KT);  
	dev176 = perdev176 / (ESCALE * fabs(LitThermo176) + KT);  
	dev177 = perdev177 / (ESCALE * fabs(LitThermo177) + KT);  
	dev178 = perdev178 / (ESCALE * fabs(LitThermo178) + KT);  
	dev179 = perdev179 / (ESCALE * fabs(LitThermo179) + KT);  
	dev180 = perdev180 / (ESCALE * fabs(LitThermo180) + KT);  
	dev181 = perdev181 / (ESCALE * fabs(LitThermo181) + KT);  
	dev182 = perdev182 / (ESCALE * fabs(LitThermo182) + KT);  
	dev183 = perdev183 / (ESCALE * fabs(LitThermo183) + KT);  
	dev184 = perdev184 / (ESCALE * fabs(LitThermo184) + KT);  
	dev185 = perdev185 / (ESCALE * fabs(LitThermo185) + KT);  
	dev186 = perdev186 / (ESCALE * fabs(LitThermo186) + KT);  
	dev187 = perdev187 / (ESCALE * fabs(LitThermo187) + KT);  
	dev188 = perdev188 / (ESCALE * fabs(LitThermo188) + KT);  
	dev189 = perdev189 / (ESCALE * fabs(LitThermo189) + KT);  
	dev190 = perdev190 / (ESCALE * fabs(LitThermo190) + KT);  
	dev191 = perdev191 / (ESCALE * fabs(LitThermo191) + KT);  
	dev192 = perdev192 / (ESCALE * fabs(LitThermo192) + KT);  
	dev193 = perdev193 / (ESCALE * fabs(LitThermo193) + KT);  
	dev194 = perdev194 / (ESCALE * fabs(LitThermo194) + KT);  
	dev195 = perdev195 / (ESCALE * fabs(LitThermo195) + KT);  
	dev196 = perdev196 / (ESCALE * fabs(LitThermo196) + KT);  
	dev197 = perdev197 / (ESCALE * fabs(LitThermo197) + KT);  
	dev198 = perdev198 / (ESCALE * fabs(LitThermo198) + KT);  
	dev199 = perdev199 / (ESCALE * fabs(LitThermo199) + KT);  
	dev200 = perdev200 / (ESCALE * fabs(LitThermo200) + KT);  
	dev201 = perdev201 / (ESCALE * fabs(LitThermo201) + KT);  
	dev202 = perdev202 / (ESCALE * fabs(LitThermo202) + KT);  
	dev203 = perdev203 / (ESCALE * fabs(LitThermo203) + KT);  
	dev204 = perdev204 / (ESCALE * fabs(LitThermo204) + KT);  
	dev205 = perdev205 / (ESCALE * fabs(LitThermo205) + KT);  
	dev206 = perdev206 / (ESCALE * fabs(LitThermo206) + KT);  
	dev207 = perdev207 / (ESCALE * fabs(LitThermo207) + KT);  
	dev208 = perdev208 / (ESCALE * fabs(LitThermo208) + KT);
	dev208 = maxi_float(-dev208, 0.0); 
	dev209 = perdev209 / (ESCALE * fabs(LitThermo209) + KT);
	dev209 = maxi_float(-dev209, 0.0); 
	dev210 = perdev210 / (ESCALE * fabs(LitThermo210) + KT);
	dev211 = perdev211 / (ESCALE * fabs(LitThermo211) + KT);
	dev211 = maxi_float(-dev211, 0.0); 
	dev224 = perdev224 / (ESCALE * fabs(LitThermo224) + KT);
	dev225=0.0;
        dev226=0.0;
        dev227=0.0;
        dev228=0.0;
        dev229=0.0;
        dev230=0.0;
        dev231=0.0;
        dev232=0.0;
//	dev233=0.0;
	dev233 = perdev233 / (ESCALE * fabs(LitThermo233) +KT);

	dev214 = perdev214 / (ESCALE * fabs(LitThermo214) + KT);  
	dev215 = perdev215 / (ESCALE * fabs(LitThermo215) + KT);  
	dev216 = perdev216 / (ESCALE * fabs(LitThermo216) + KT);  
	dev217 = perdev217 / (ESCALE * fabs(LitThermo217) + KT);  
	dev218 = perdev218 / (ESCALE * fabs(LitThermo218) + KT);  
	dev219 = perdev219 / (ESCALE * fabs(LitThermo219) + KT);  
	dev220 = perdev220 / (ESCALE * fabs(LitThermo220) + KT);  
	dev221 = perdev221 / (ESCALE * fabs(LitThermo221) + KT);  
	dev222 = perdev222 / (ESCALE * fabs(LitThermo222) + KT);  
	dev223 = perdev223 / (ESCALE * fabs(LitThermo223) + KT);  

	dev234 = perdev234 / (ESCALE * fabs(LitThermo234) + KT);
	dev234 = maxi_float(-dev234, 0.0); 
	dev235 = perdev235 / (ESCALE * fabs(LitThermo235) + KT);
	dev235 = maxi_float(-dev235, 0.0); 
	dev236 = perdev236 / (ESCALE * fabs(LitThermo236) + KT);
	dev236 = maxi_float(-dev236, 0.0); 
	dev238 = 0.0;
	dev239 = 0.0;
	dev240 = 0.0;
	dev241 = 0.0;
	dev242 = 0.0;
	dev243 = 0.0;
//      dev238=perdev238 / (ESCALE * fabs(LitThermo238) + KT);
//	dev238 = maxi_float(-dev238, 0.0); 
//      dev239=perdev239 / (ESCALE * fabs(LitThermo239) + KT);
//	dev239 = maxi_float(-dev239, 0.0); 
//      dev240=perdev240 / (ESCALE * fabs(LitThermo240) + KT);
//	dev240 = maxi_float(-dev240, 0.0); 
//      dev241=perdev241 / (ESCALE * fabs(LitThermo241) + KT);
//	dev241 = maxi_float(-dev241, 0.0); 
//      dev242=perdev242 / (ESCALE * fabs(LitThermo242) + KT);
//	dev242 = maxi_float(-dev242, 0.0); 
//      dev243=perdev243 / (ESCALE * fabs(LitThermo243) + KT);
//	dev243 = maxi_float(-dev243, 0.0); 
        dev244 = perdev244 / (ESCALE * fabs(LitThermo244) + KT);  
        dev245 = perdev245 / (ESCALE * fabs(LitThermo245) + KT);  
        dev246 = perdev246 / (ESCALE * fabs(LitThermo246) + KT);  
        dev247 = perdev247 / (ESCALE * fabs(LitThermo247) + KT);  
        dev248 = perdev248 / (ESCALE * fabs(LitThermo248) + KT);  
//	dev249 = 0.0;
//	dev250 = 0.0; 
	dev251 = perdev251 / (ESCALE * fabs(LitThermo251) + KT);
	dev252 = perdev252 / (ESCALE * fabs(LitThermo251 + LitThermo29) + KT);

	dev253 = perdev253 / (ESCALE * fabs(LitThermo253) + KT);  
	dev254 = perdev254 / (ESCALE * fabs(LitThermo254) + KT);  
	dev256 = perdev256 / (ESCALE * fabs(LitThermo256) + KT);  
	dev257 = perdev257 / (ESCALE * fabs(LitThermo257) + KT);  
	dev258 = perdev258 / (ESCALE * fabs(LitThermo258) + KT);  
	dev259 = perdev259 / (ESCALE * fabs(LitThermo259) + KT);  
	dev260 = perdev260 / (ESCALE * fabs(LitThermo260) + KT);  
	dev261 = perdev261 / (ESCALE * fabs(LitThermo261) + KT);  
	dev262 = perdev262 / (ESCALE * fabs(LitThermo262) + KT);  
	dev263 = perdev263 / (ESCALE * fabs(LitThermo263) + KT);  
	dev264 = perdev264 / (ESCALE * fabs(LitThermo264) + KT);  
	dev265 = perdev265 / (ESCALE * fabs(LitThermo265) + KT);  
	dev266 = perdev266 / (ESCALE * fabs(LitThermo266) + KT);  
	dev267 = perdev267 / (ESCALE * fabs(LitThermo267) + KT);  
	dev268 = perdev268 / (ESCALE * fabs(LitThermo268) + KT);  
	dev269 = perdev269 / (ESCALE * fabs(LitThermo269) + KT);  
	dev270 = perdev270 / (ESCALE * fabs(LitThermo270) + KT);  
	dev271 = perdev271 / (ESCALE * fabs(LitThermo271) + KT);  
	dev272 = perdev272 / (ESCALE * fabs(LitThermo272) + KT);  
	dev273 = perdev273 / (ESCALE * fabs(LitThermo273) + KT);  
	dev274 = perdev274 / (ESCALE * fabs(LitThermo274) + KT);  
	dev275 = perdev275 / (ESCALE * fabs(LitThermo275) + KT);  
	dev276 = perdev276 / (ESCALE * fabs(LitThermo276) + KT);  
	dev277 = perdev277 / (ESCALE * fabs(LitThermo277) + KT);  
	dev278 = perdev278 / (ESCALE * fabs(LitThermo278) + KT);  
	dev279 = perdev279 / (ESCALE * fabs(LitThermo279) + KT);  
	dev280 = perdev280 / (ESCALE * fabs(LitThermo280) + KT);  
	dev281 = perdev281 / (ESCALE * fabs(LitThermo281) + KT);  
	dev282 = perdev282 / (ESCALE * fabs(LitThermo282) + KT);  
	dev283 = perdev283 / (ESCALE * fabs(LitThermo283) + KT);  
	dev284 = perdev284 / (ESCALE * fabs(LitThermo284) + KT);  
	dev285 = perdev285 / (ESCALE * fabs(LitThermo285) + KT);  
	dev286 = perdev286 / (ESCALE * fabs(LitThermo286) + KT);  
	dev287 = perdev287 / (ESCALE * fabs(LitThermo287) + KT);  
	dev288 = perdev288 / (ESCALE * fabs(LitThermo288) + KT);  
	dev289 = perdev289 / (ESCALE * fabs(LitThermo289) + KT);  
	dev290 = perdev290 / (ESCALE * fabs(LitThermo290) + KT);  
	dev291 = perdev291 / (ESCALE * fabs(LitThermo291) + KT);  
	dev292 = perdev292 / (ESCALE * fabs(LitThermo292) + KT);  
	dev293 = perdev293 / (ESCALE * fabs(LitThermo293) + KT);  
	dev294 = perdev294 / (ESCALE * fabs(LitThermo294) + KT);  
	dev295 = perdev295 / (ESCALE * fabs(LitThermo295) + KT);  
	dev296 = perdev296 / (ESCALE * fabs(LitThermo296) + KT);  
	dev297 = perdev297 / (ESCALE * fabs(LitThermo297) + KT);  
	dev298 = perdev298 / (ESCALE * fabs(LitThermo298) + KT);  
	dev299 = perdev299 / (ESCALE * fabs(LitThermo299) + KT);  
	dev300 = perdev300 / (ESCALE * fabs(LitThermo300) + KT);  
	dev301 = perdev301 / (ESCALE * fabs(LitThermo301) + KT);  
	dev302 = perdev302 / (ESCALE * fabs(LitThermo302) + KT);  
	dev303 = perdev303 / (ESCALE * fabs(LitThermo303) + KT);  
	dev304 = perdev304 / (ESCALE * fabs(LitThermo304) + KT);  
	dev305 = perdev305 / (ESCALE * fabs(LitThermo305) + KT);  
	dev306 = perdev306 / (ESCALE * fabs(LitThermo306) + KT);  
	dev307 = perdev307 / (ESCALE * fabs(LitThermo307) + KT);  
	dev308 = perdev308 / (ESCALE * fabs(LitThermo308) + KT);  
	dev309 = perdev309 / (ESCALE * fabs(LitThermo309) + KT);  
	dev310 = perdev310 / (ESCALE * fabs(LitThermo310) + KT);  
	dev311 = perdev311 / (ESCALE * fabs(LitThermo311) + KT);  
	dev312 = perdev312 / (ESCALE * fabs(LitThermo312) + KT);  
	dev313 = perdev313 / (ESCALE * fabs(LitThermo313) + KT);  
	dev314 = perdev314 / (ESCALE * fabs(LitThermo314) + KT);  
	dev315 = perdev315 / (ESCALE * fabs(LitThermo315) + KT);  
	dev316 = perdev316 / (ESCALE * fabs(LitThermo316) + KT);  
	dev317 = perdev317 / (ESCALE * fabs(LitThermo317) + KT);  
	dev318 = perdev318 / (ESCALE * fabs(LitThermo318) + KT);  
	dev319 = perdev319 / (ESCALE * fabs(LitThermo319) + KT);  
	dev320 = perdev320 / (ESCALE * fabs(LitThermo320) + KT);  
	dev321 = perdev321 / (ESCALE * fabs(LitThermo321) + KT);  
	dev322 = perdev322 / (ESCALE * fabs(LitThermo322) + KT);  
	dev323 = perdev323 / (ESCALE * fabs(LitThermo323) + KT);  
	dev324 = perdev324 / (ESCALE * fabs(LitThermo324) + KT);  
	dev325 = perdev325 / (ESCALE * fabs(LitThermo325) + KT);  
	dev326 = perdev326 / (ESCALE * fabs(LitThermo326) + KT);  
	dev327 = perdev327 / (ESCALE * fabs(LitThermo327) + KT);  
	dev328 = perdev328 / (ESCALE * fabs(LitThermo328) + KT);  
	dev329 = perdev329 / (ESCALE * fabs(LitThermo329) + KT);  
	dev330 = perdev330 / (ESCALE * fabs(LitThermo330) + KT);  
	dev331 = perdev331 / (ESCALE * fabs(LitThermo331) + KT);  
	dev332 = perdev332 / (ESCALE * fabs(LitThermo332) + KT);  
	dev333 = perdev333 / (ESCALE * fabs(LitThermo333) + KT);  
	dev334 = perdev334 / (ESCALE * fabs(LitThermo334) + KT);  
	dev335 = perdev335 / (ESCALE * fabs(LitThermo335) + KT);  
	dev336 = perdev336 / (ESCALE * fabs(LitThermo336) + KT);  
	dev337 = perdev337 / (ESCALE * fabs(LitThermo337) + KT);  
	dev338 = perdev338 / (ESCALE * fabs(LitThermo338) + KT);  
	dev339 = perdev339 / (ESCALE * fabs(LitThermo339) + KT);  
	dev340 = perdev340 / (ESCALE * fabs(LitThermo340) + KT);  
	dev341 = perdev341 / (ESCALE * fabs(LitThermo341) + KT);  
	dev342 = perdev342 / (ESCALE * fabs(LitThermo342) + KT);  
	dev343 = perdev343 / (ESCALE * fabs(LitThermo343) + KT);  
	dev344 = perdev344 / (ESCALE * fabs(LitThermo344) + KT);  
	dev345 = perdev345 / (ESCALE * fabs(LitThermo345) + KT);  
	dev346 = perdev346 / (ESCALE * fabs(LitThermo346) + KT);  
	dev347 = perdev347 / (ESCALE * fabs(LitThermo347) + KT);  
	dev348 = perdev348 / (ESCALE * fabs(LitThermo348) + KT);  
	dev349 = perdev349 / (ESCALE * fabs(LitThermo349) + KT);  
	dev350 = perdev350 / (ESCALE * fabs(LitThermo350) + KT);  
	dev351 = perdev351 / (ESCALE * fabs(LitThermo351) + KT);  
	dev352 = perdev352 / (ESCALE * fabs(LitThermo352) + KT);  
	dev353 = perdev353 / (ESCALE * fabs(LitThermo353) + KT);  
	dev354 = perdev354 / (ESCALE * fabs(LitThermo354) + KT);  
	dev355 = perdev355 / (ESCALE * fabs(LitThermo355) + KT);  
	dev356 = perdev356 / (ESCALE * fabs(LitThermo356) + KT);  
	dev357 = perdev357 / (ESCALE * fabs(LitThermo357) + KT);  
	dev358 = perdev358 / (ESCALE * fabs(LitThermo358) + KT);  
	dev359 = perdev359 / (ESCALE * fabs(LitThermo359) + KT);  
	dev360 = perdev360 / (ESCALE * fabs(LitThermo360) + KT);  
	dev361 = perdev361 / (ESCALE * fabs(LitThermo361) + KT);  
	dev362 = perdev362 / (ESCALE * fabs(LitThermo362) + KT);  
	dev363 = perdev363 / (ESCALE * fabs(LitThermo363) + KT);  
	dev364 = perdev364 / (ESCALE * fabs(LitThermo364) + KT);  
	dev365 = perdev365 / (ESCALE * fabs(LitThermo365) + KT);  
	dev366 = perdev366 / (ESCALE * fabs(LitThermo366) + KT);  
	dev367 = perdev367 / (ESCALE * fabs(LitThermo367) + KT);  
	dev368 = perdev368 / (ESCALE * fabs(LitThermo368) + KT);  
	dev369 = perdev369 / (ESCALE * fabs(LitThermo369) + KT);  
	dev370 = perdev370 / (ESCALE * fabs(LitThermo370) + KT);  
	dev371 = perdev371 / (ESCALE * fabs(LitThermo371) + KT);  
	dev372 = perdev372 / (ESCALE * fabs(LitThermo372) + KT);  
	dev373 = perdev373 / (ESCALE * fabs(LitThermo373) + KT);  
	dev374 = perdev374 / (ESCALE * fabs(LitThermo374) + KT);  
	dev375 = perdev375 / (ESCALE * fabs(LitThermo375) + KT);  
	dev376 = perdev376 / (ESCALE * fabs(LitThermo376) + KT);  
	dev377 = perdev377 / (ESCALE * fabs(LitThermo377) + KT);  
	dev378 = perdev378 / (ESCALE * fabs(LitThermo378) + KT);  
	dev379 = perdev379 / (ESCALE * fabs(LitThermo379) + KT);  
	dev380 = perdev380 / (ESCALE * fabs(LitThermo380) + KT);  
	dev381 = perdev381 / (ESCALE * fabs(LitThermo381) + KT);  
	dev382 = perdev382 / (ESCALE * fabs(LitThermo382) + KT);  
	dev383 = perdev383 / (ESCALE * fabs(LitThermo383) + KT);  
	dev384 = perdev384 / (ESCALE * fabs(LitThermo384) + KT);  
	dev385 = perdev385 / (ESCALE * fabs(LitThermo385) + KT);  
	dev386 = perdev386 / (ESCALE * fabs(LitThermo386) + KT);  
	dev387 = perdev387 / (ESCALE * fabs(LitThermo387) + KT);  
	dev388 = perdev388 / (ESCALE * fabs(LitThermo388) + KT);  
	dev389 = perdev389 / (ESCALE * fabs(LitThermo389) + KT);  
	dev390 = perdev390 / (ESCALE * fabs(LitThermo390) + KT);  
	dev391 = perdev391 / (ESCALE * fabs(LitThermo391) + KT);  
	dev392 = perdev392 / (ESCALE * fabs(LitThermo392) + KT);  
	dev393 = perdev393 / (ESCALE * fabs(LitThermo393) + KT);  
	dev394 = perdev394 / (ESCALE * fabs(LitThermo394) + KT);  
	dev395 = perdev395 / (ESCALE * fabs(LitThermo395) + KT);  
	dev396 = perdev396 / (ESCALE * fabs(LitThermo396) + KT);  
	dev397 = perdev397 / (ESCALE * fabs(LitThermo397) + KT);  
	dev398 = perdev398 / (ESCALE * fabs(LitThermo398) + KT);  
	dev399 = perdev399 / (ESCALE * fabs(LitThermo399) + KT);  
	dev400 = perdev400 / (ESCALE * fabs(LitThermo400) + KT);  
	dev401 = perdev401 / (ESCALE * fabs(LitThermo401) + KT);  
	dev402 = perdev402 / (ESCALE * fabs(LitThermo402) + KT);  
	dev403 = perdev403 / (ESCALE * fabs(LitThermo403) + KT);  
	dev404 = perdev404 / (ESCALE * fabs(LitThermo404) + KT);  
	dev405 = perdev405 / (ESCALE * fabs(LitThermo405) + KT);  
	dev406 = perdev406 / (ESCALE * fabs(LitThermo406) + KT);  
	dev407 = perdev407 / (ESCALE * fabs(LitThermo407) + KT);  
	dev408 = perdev408 / (ESCALE * fabs(LitThermo408) + KT);  
	dev409 = perdev409 / (ESCALE * fabs(LitThermo409) + KT);  
	dev410 = perdev410 / (ESCALE * fabs(LitThermo410) + KT);  
	dev411 = perdev411 / (ESCALE * fabs(LitThermo411) + KT);  
	dev412 = perdev412 / (ESCALE * fabs(LitThermo412) + KT);  
	dev413 = perdev413 / (ESCALE * fabs(LitThermo413) + KT);  
	dev414 = perdev414 / (ESCALE * fabs(LitThermo414) + KT);  
	dev415 = perdev415 / (ESCALE * fabs(LitThermo415) + KT);  
	dev416 = perdev416 / (ESCALE * fabs(LitThermo416) + KT);  
	dev417 = perdev417 / (ESCALE * fabs(LitThermo417) + KT);  
	dev418 = perdev418 / (ESCALE * fabs(LitThermo418) + KT);  
	dev419 = perdev419 / (ESCALE * fabs(LitThermo419) + KT);  
	dev420 = perdev420 / (ESCALE * fabs(LitThermo420) + KT);  
	dev421 = perdev421 / (ESCALE * fabs(LitThermo421) + KT);  
	dev422 = perdev422 / (ESCALE * fabs(LitThermo422) + KT);  
	dev423 = perdev423 / (ESCALE * fabs(LitThermo423) + KT);  
	dev424 = perdev424 / (ESCALE * fabs(LitThermo424) + KT);  
	dev425 = perdev425 / (ESCALE * fabs(LitThermo425) + KT);  
	dev426 = perdev426 / (ESCALE * fabs(LitThermo426) + KT);  
	dev427 = perdev427 / (ESCALE * fabs(LitThermo427) + KT);  
	dev428 = perdev428 / (ESCALE * fabs(LitThermo428) + KT);  
	dev429 = perdev429 / (ESCALE * fabs(LitThermo429) + KT);  
	dev430 = perdev430 / (ESCALE * fabs(LitThermo430) + KT);  
	dev431 = perdev431 / (ESCALE * fabs(LitThermo431) + KT);  
	dev432 = perdev432 / (ESCALE * fabs(LitThermo432) + KT);  
	dev433 = perdev433 / (ESCALE * fabs(LitThermo433) + KT);  
	dev434 = perdev434 / (ESCALE * fabs(LitThermo434) + KT);  
	dev435 = perdev435 / (ESCALE * fabs(LitThermo435) + KT);  
	dev436 = perdev436 / (ESCALE * fabs(LitThermo436) + KT);  
	dev437 = perdev437 / (ESCALE * fabs(LitThermo437) + KT);  
	dev438 = perdev438 / (ESCALE * fabs(LitThermo438) + KT);  
	dev439 = perdev439 / (ESCALE * fabs(LitThermo439) + KT);  
	dev440 = perdev440 / (ESCALE * fabs(LitThermo440) + KT);  
	dev441 = perdev441 / (ESCALE * fabs(LitThermo441) + KT);  
	dev442 = perdev442 / (ESCALE * fabs(LitThermo442) + KT);  
	dev443 = perdev443 / (ESCALE * fabs(LitThermo443) + KT);  
	dev444 = perdev444 / (ESCALE * fabs(LitThermo444) + KT);  
	dev445 = perdev445 / (ESCALE * fabs(LitThermo445) + KT);  
	dev446 = perdev446 / (ESCALE * fabs(LitThermo446) + KT);  
	dev447 = perdev447 / (ESCALE * fabs(LitThermo447) + KT);  
	dev448 = perdev448 / (ESCALE * fabs(LitThermo448) + KT);  
	dev449 = perdev449 / (ESCALE * fabs(LitThermo449) + KT);  
	dev450 = perdev450 / (ESCALE * fabs(LitThermo450) + KT);  
	dev451 = perdev451 / (ESCALE * fabs(LitThermo451) + KT);  
	dev452 = perdev452 / (ESCALE * fabs(LitThermo452) + KT);  
	dev453 = perdev453 / (ESCALE * fabs(LitThermo453) + KT);  
	dev454 = perdev454 / (ESCALE * fabs(LitThermo454) + KT);  
	dev455 = perdev455 / (ESCALE * fabs(LitThermo455) + KT);  
	dev456 = perdev456 / (ESCALE * fabs(LitThermo456) + KT);  
	dev457 = perdev457 / (ESCALE * fabs(LitThermo457) + KT);  
	dev458 = perdev458 / (ESCALE * fabs(LitThermo458) + KT);  
	dev459 = perdev459 / (ESCALE * fabs(LitThermo459) + KT);  
	dev460 = perdev460 / (ESCALE * fabs(LitThermo460) + KT);  
	dev461 = perdev461 / (ESCALE * fabs(LitThermo461) + KT);  
	dev462 = perdev462 / (ESCALE * fabs(LitThermo462) + KT);  
	dev463 = perdev463 / (ESCALE * fabs(LitThermo463) + KT);  
	dev464 = perdev464 / (ESCALE * fabs(LitThermo464) + KT);  
	dev465 = perdev465 / (ESCALE * fabs(LitThermo465) + KT);  
	dev466 = perdev466 / (ESCALE * fabs(LitThermo466) + KT);  
	dev467 = perdev467 / (ESCALE * fabs(LitThermo467) + KT);  
	dev468 = perdev468 / (ESCALE * fabs(LitThermo468) + KT);  
	dev469 = perdev469 / (ESCALE * fabs(LitThermo469) + KT);  
	dev470 = perdev470 / (ESCALE * fabs(LitThermo470) + KT);  
	dev471 = perdev471 / (ESCALE * fabs(LitThermo471) + KT);  
	dev472 = perdev472 / (ESCALE * fabs(LitThermo472) + KT);  
	dev473 = perdev473 / (ESCALE * fabs(LitThermo473) + KT);  
	dev474 = perdev474 / (ESCALE * fabs(LitThermo474) + KT);  
	dev475 = perdev475 / (ESCALE * fabs(LitThermo475) + KT);  
	dev476 = perdev476 / (ESCALE * fabs(LitThermo476) + KT);  
	dev477 = perdev477 / (ESCALE * fabs(LitThermo477) + KT);  
	dev478 = perdev478 / (ESCALE * fabs(LitThermo478) + KT);  
	dev479 = perdev479 / (ESCALE * fabs(LitThermo479) + KT);  
	dev480 = perdev480 / (ESCALE * fabs(LitThermo480) + KT);  
	dev481 = perdev481 / (ESCALE * fabs(LitThermo481) + KT);  
	dev482 = perdev482 / (ESCALE * fabs(LitThermo482) + KT);  
	dev483 = perdev483 / (ESCALE * fabs(LitThermo483) + KT);  
	dev484 = perdev484 / (ESCALE * fabs(LitThermo484) + KT);  
	dev485 = perdev485 / (ESCALE * fabs(LitThermo485) + KT);  
	dev486 = perdev486 / (ESCALE * fabs(LitThermo486) + KT);  
	dev487 = perdev487 / (ESCALE * fabs(LitThermo487) + KT);  
	dev488 = perdev488 / (ESCALE * fabs(LitThermo488) + KT);  
	dev489 = perdev489 / (ESCALE * fabs(LitThermo489) + KT);  
	dev490 = perdev490 / (ESCALE * fabs(LitThermo490) + KT);  
	dev491 = perdev491 / (ESCALE * fabs(LitThermo491) + KT);  
	dev492 = perdev492 / (ESCALE * fabs(LitThermo492) + KT);  
	dev493 = perdev493 / (ESCALE * fabs(LitThermo493) + KT);  
	dev494 = perdev494 / (ESCALE * fabs(LitThermo494) + KT);  
	dev495 = perdev495 / (ESCALE * fabs(LitThermo495) + KT);  
	dev496 = perdev496 / (ESCALE * fabs(LitThermo496) + KT);  
	dev497 = perdev497 / (ESCALE * fabs(LitThermo497) + KT);  
	dev498 = perdev498 / (ESCALE * fabs(LitThermo498) + KT);  
	dev499 = perdev499 / (ESCALE * fabs(LitThermo499) + KT);  
	dev500 = perdev500 / (ESCALE * fabs(LitThermo500) + KT);  
	dev501 = perdev501 / (ESCALE * fabs(LitThermo501) + KT);  
	dev502 = perdev502 / (ESCALE * fabs(LitThermo502) + KT);  
	dev503 = perdev503 / (ESCALE * fabs(LitThermo503) + KT);  
	dev504 = perdev504 / (ESCALE * fabs(LitThermo504) + KT);  
	dev505 = perdev505 / (ESCALE * fabs(LitThermo505) + KT);  
	dev506 = perdev506 / (ESCALE * fabs(LitThermo506) + KT);  
	dev507 = perdev507 / (ESCALE * fabs(LitThermo507) + KT);  
	dev508 = perdev508 / (ESCALE * fabs(LitThermo508) + KT);  
	dev509 = perdev509 / (ESCALE * fabs(LitThermo509) + KT);  
	dev510 = perdev510 / (ESCALE * fabs(LitThermo510) + KT);  
	dev511 = perdev511 / (ESCALE * fabs(LitThermo511) + KT);  
	dev512 = perdev512 / (ESCALE * fabs(LitThermo512) + KT);  
	dev513 = perdev513 / (ESCALE * fabs(LitThermo513) + KT);  
	dev514 = perdev514 / (ESCALE * fabs(LitThermo514) + KT);  
	dev515 = perdev515 / (ESCALE * fabs(LitThermo515) + KT);  
	dev516 = perdev516 / (ESCALE * fabs(LitThermo516) + KT);  
	dev517 = perdev517 / (ESCALE * fabs(LitThermo517) + KT);  
	dev518 = perdev518 / (ESCALE * fabs(LitThermo518) + KT);  
	dev519 = perdev519 / (ESCALE * fabs(LitThermo519) + KT);  
	dev520 = perdev520 / (ESCALE * fabs(LitThermo520) + KT);  
	dev521 = perdev521 / (ESCALE * fabs(LitThermo521) + KT);  
	dev522 = perdev522 / (ESCALE * fabs(LitThermo522) + KT);  
	dev523 = perdev523 / (ESCALE * fabs(LitThermo523) + KT);  
	dev524 = perdev524 / (ESCALE * fabs(LitThermo524) + KT);  
	dev525 = perdev525 / (ESCALE * fabs(LitThermo525) + KT);  
	dev526 = perdev526 / (ESCALE * fabs(LitThermo526) + KT);  
	dev527 = perdev527 / (ESCALE * fabs(LitThermo527) + KT);  
	dev528 = perdev528 / (ESCALE * fabs(LitThermo528) + KT);  
	dev529 = perdev529 / (ESCALE * fabs(LitThermo529) + KT);  
	dev530 = perdev530 / (ESCALE * fabs(LitThermo530) + KT);  
	dev531 = perdev531 / (ESCALE * fabs(LitThermo531) + KT);  
	dev532 = perdev532 / (ESCALE * fabs(LitThermo532) + KT);  
	dev533 = perdev533 / (ESCALE * fabs(LitThermo533) + KT);  
	dev534 = perdev534 / (ESCALE * fabs(LitThermo534) + KT);  
	dev535 = perdev535 / (ESCALE * fabs(LitThermo535) + KT);  
	dev536 = perdev536 / (ESCALE * fabs(LitThermo536) + KT);  
	dev537 = perdev537 / (ESCALE * fabs(LitThermo537) + KT);  
	dev538 = perdev538 / (ESCALE * fabs(LitThermo538) + KT);  
	dev539 = perdev539 / (ESCALE * fabs(LitThermo539) + KT);  
	dev540 = perdev540 / (ESCALE * fabs(LitThermo540) + KT);  
	dev541 = perdev541 / (ESCALE * fabs(LitThermo541) + KT);  
	dev542 = perdev542 / (ESCALE * fabs(LitThermo542) + KT);  
	dev543 = perdev543 / (ESCALE * fabs(LitThermo543) + KT);  
	dev544 = perdev544 / (ESCALE * fabs(LitThermo544) + KT);  
	dev545 = perdev545 / (ESCALE * fabs(LitThermo545) + KT);  
	dev546 = perdev546 / (ESCALE * fabs(LitThermo546) + KT);  
	dev547 = perdev547 / (ESCALE * fabs(LitThermo547) + KT);  
	dev548 = perdev548 / (ESCALE * fabs(LitThermo548) + KT);  
	dev549 = perdev549 / (ESCALE * fabs(LitThermo549) + KT);  
	dev550 = perdev550 / (ESCALE * fabs(LitThermo550) + KT);  
	dev551 = perdev551 / (ESCALE * fabs(LitThermo551) + KT);  
	dev552 = perdev552 / (ESCALE * fabs(LitThermo552) + KT);  
	dev553 = perdev553 / (ESCALE * fabs(LitThermo553) + KT);  
	dev554 = perdev554 / (ESCALE * fabs(LitThermo554) + KT);  
	dev555 = perdev555 / (ESCALE * fabs(LitThermo555) + KT);  
	dev556 = perdev556 / (ESCALE * fabs(LitThermo556) + KT);  
	dev557 = perdev557 / (ESCALE * fabs(LitThermo557) + KT);  
	dev558 = perdev558 / (ESCALE * fabs(LitThermo558) + KT);  
	dev559 = perdev559 / (ESCALE * fabs(LitThermo559) + KT);  
	dev560 = perdev560 / (ESCALE * fabs(LitThermo560) + KT);  
	dev561 = perdev561 / (ESCALE * fabs(LitThermo561) + KT);  
	dev562 = perdev562 / (ESCALE * fabs(LitThermo562) + KT);  
	dev563 = perdev563 / (ESCALE * fabs(LitThermo563) + KT);  
	dev564 = perdev564 / (ESCALE * fabs(LitThermo564) + KT);  
	dev565 = perdev565 / (ESCALE * fabs(LitThermo565) + KT);  
	dev566 = perdev566 / (ESCALE * fabs(LitThermo566) + KT);  
	dev567 = perdev567 / (ESCALE * fabs(LitThermo567) + KT);  
	dev568 = perdev568 / (ESCALE * fabs(LitThermo568) + KT);  
	dev569 = perdev569 / (ESCALE * fabs(LitThermo569) + KT);  
	dev570 = perdev570 / (ESCALE * fabs(LitThermo570) + KT);  
	dev571 = perdev571 / (ESCALE * fabs(LitThermo571) + KT);  
	dev572 = perdev572 / (ESCALE * fabs(LitThermo572) + KT);  
	dev573 = perdev573 / (ESCALE * fabs(LitThermo573) + KT);  
	dev574 = perdev574 / (ESCALE * fabs(LitThermo574) + KT);  
	dev575 = perdev575 / (ESCALE * fabs(LitThermo575) + KT);  
	dev576 = perdev576 / (ESCALE * fabs(LitThermo576) + KT);  
	dev577 = perdev577 / (ESCALE * fabs(LitThermo577) + KT);  
	dev578 = perdev578 / (ESCALE * fabs(LitThermo578) + KT);  
	dev579 = perdev579 / (ESCALE * fabs(LitThermo579) + KT);  
	dev580 = perdev580 / (ESCALE * fabs(LitThermo580) + KT);  
	dev581 = perdev581 / (ESCALE * fabs(LitThermo581) + KT);  
	dev582 = perdev582 / (ESCALE * fabs(LitThermo582) + KT);  
	dev583 = perdev583 / (ESCALE * fabs(LitThermo583) + KT);  
	dev584 = perdev584 / (ESCALE * fabs(LitThermo584) + KT);  
	dev585 = perdev585 / (ESCALE * fabs(LitThermo585) + KT);  
	dev586 = perdev586 / (ESCALE * fabs(LitThermo586) + KT);  
	dev587 = perdev587 / (ESCALE * fabs(LitThermo587) + KT);  
	dev588 = perdev588 / (ESCALE * fabs(LitThermo588) + KT);  
	dev589 = perdev589 / (ESCALE * fabs(LitThermo589) + KT);  
	dev590 = perdev590 / (ESCALE * fabs(LitThermo590) + KT);  
	dev591 = perdev591 / (ESCALE * fabs(LitThermo591) + KT);  
	dev592 = perdev592 / (ESCALE * fabs(LitThermo592) + KT);  
	dev593 = perdev593 / (ESCALE * fabs(LitThermo593) + KT);  
	dev594 = perdev594 / (ESCALE * fabs(LitThermo594) + KT);  
	dev595 = perdev595 / (ESCALE * fabs(LitThermo595) + KT);  
	dev596 = perdev596 / (ESCALE * fabs(LitThermo596) + KT);  
	dev597 = perdev597 / (ESCALE * fabs(LitThermo597) + KT);  
	dev598 = perdev598 / (ESCALE * fabs(LitThermo598) + KT);  
	dev599 = perdev599 / (ESCALE * fabs(LitThermo599) + KT);  
	dev600 = perdev600 / (ESCALE * fabs(LitThermo600) + KT);  
	dev601 = perdev601 / (ESCALE * fabs(LitThermo601) + KT);  
	dev602 = perdev602 / (ESCALE * fabs(LitThermo602) + KT);  
	dev603 = perdev603 / (ESCALE * fabs(LitThermo603) + KT);  
	dev604 = perdev604 / (ESCALE * fabs(LitThermo604) + KT);  
	dev605 = perdev605 / (ESCALE * fabs(LitThermo605) + KT);  
	dev606 = perdev606 / (ESCALE * fabs(LitThermo606) + KT);  
	dev607 = perdev607 / (ESCALE * fabs(LitThermo607) + KT);  
	dev608 = perdev608 / (ESCALE * fabs(LitThermo608) + KT);  
	dev609 = perdev609 / (ESCALE * fabs(LitThermo609) + KT);  
	dev610 = perdev610 / (ESCALE * fabs(LitThermo610) + KT);  
	dev611 = perdev611 / (ESCALE * fabs(LitThermo611) + KT);  
	dev612 = perdev612 / (ESCALE * fabs(LitThermo612) + KT);  
	dev613 = perdev613 / (ESCALE * fabs(LitThermo613) + KT);  
	dev614 = perdev614 / (ESCALE * fabs(LitThermo614) + KT);  
	dev615 = perdev615 / (ESCALE * fabs(LitThermo615) + KT);  
	dev616 = perdev616 / (ESCALE * fabs(LitThermo616) + KT);  
	dev617 = perdev617 / (ESCALE * fabs(LitThermo617) + KT);  
	dev618 = perdev618 / (ESCALE * fabs(LitThermo618) + KT);  
	dev619 = perdev619 / (ESCALE * fabs(LitThermo619) + KT);  
	dev620 = perdev620 / (ESCALE * fabs(LitThermo620) + KT);  
	dev621 = perdev621 / (ESCALE * fabs(LitThermo621) + KT);  
	dev622 = perdev622 / (ESCALE * fabs(LitThermo622) + KT);  
	dev623 = perdev623 / (ESCALE * fabs(LitThermo623) + KT);  
	dev624 = perdev624 / (ESCALE * fabs(LitThermo624) + KT);  
	dev625 = perdev625 / (ESCALE * fabs(LitThermo625) + KT);  
	dev626 = perdev626 / (ESCALE * fabs(LitThermo626) + KT);  
	dev627 = perdev627 / (ESCALE * fabs(LitThermo627) + KT);  
	dev628 = perdev628 / (ESCALE * fabs(LitThermo628) + KT);  
	dev629 = perdev629 / (ESCALE * fabs(LitThermo629) + KT);  
	dev630 = perdev630 / (ESCALE * fabs(LitThermo630) + KT);  
	dev631 = perdev631 / (ESCALE * fabs(LitThermo631) + KT);  
	dev632 = perdev632 / (ESCALE * fabs(LitThermo632) + KT);  
	dev633 = perdev633 / (ESCALE * fabs(LitThermo633) + KT);  
	dev634 = perdev634 / (ESCALE * fabs(LitThermo634) + KT);  
	dev635 = perdev635 / (ESCALE * fabs(LitThermo635) + KT);  
	dev636 = perdev636 / (ESCALE * fabs(LitThermo636) + KT);  
	dev637 = perdev637 / (ESCALE * fabs(LitThermo637) + KT);  
	dev638 = perdev638 / (ESCALE * fabs(LitThermo638) + KT);  
	dev639 = perdev639 / (ESCALE * fabs(LitThermo639) + KT);  
	dev640 = perdev640 / (ESCALE * fabs(LitThermo640) + KT);  
	dev641 = perdev641 / (ESCALE * fabs(LitThermo641) + KT);  
	dev642 = perdev642 / (ESCALE * fabs(LitThermo642) + KT);  
	dev643 = perdev643 / (ESCALE * fabs(LitThermo643) + KT);  
	dev644 = perdev644 / (ESCALE * fabs(LitThermo644) + KT);  
	dev645 = perdev645 / (ESCALE * fabs(LitThermo645) + KT);  
	dev646 = perdev646 / (ESCALE * fabs(LitThermo646) + KT);  
	dev647 = perdev647 / (ESCALE * fabs(LitThermo647) + KT);  
	dev648 = perdev648 / (ESCALE * fabs(LitThermo648) + KT);  
	dev649 = perdev649 / (ESCALE * fabs(LitThermo649) + KT);  
	dev650 = perdev650 / (ESCALE * fabs(LitThermo650) + KT);  
	dev651 = perdev651 / (ESCALE * fabs(LitThermo651) + KT);  
	dev652 = perdev652 / (ESCALE * fabs(LitThermo652) + KT);  
	dev653 = perdev653 / (ESCALE * fabs(LitThermo653) + KT);  
	dev654 = perdev654 / (ESCALE * fabs(LitThermo654) + KT);  
	dev655 = perdev655 / (ESCALE * fabs(LitThermo655) + KT);  
	dev656 = perdev656 / (ESCALE * fabs(LitThermo656) + KT);  
	dev657 = perdev657 / (ESCALE * fabs(LitThermo657) + KT);  
	dev658 = perdev658 / (ESCALE * fabs(LitThermo658) + KT);  
	dev659 = perdev659 / (ESCALE * fabs(LitThermo659) + KT);  
	dev660 = perdev660 / (ESCALE * fabs(LitThermo660) + KT);  
	dev661 = perdev661 / (ESCALE * fabs(LitThermo661) + KT);  
	dev662 = perdev662 / (ESCALE * fabs(LitThermo662) + KT);  
	dev663 = perdev663 / (ESCALE * fabs(LitThermo663) + KT);  
	dev664 = perdev664 / (ESCALE * fabs(LitThermo664) + KT);  
	dev665 = perdev665 / (ESCALE * fabs(LitThermo665) + KT);  
	dev666 = perdev666 / (ESCALE * fabs(LitThermo666) + KT);  
	dev667 = perdev667 / (ESCALE * fabs(LitThermo667) + KT);  
	dev668 = perdev668 / (ESCALE * fabs(LitThermo668) + KT);  
	dev669 = perdev669 / (ESCALE * fabs(LitThermo669) + KT);  
	dev670 = perdev670 / (ESCALE * fabs(LitThermo670) + KT);  
	dev671 = perdev671 / (ESCALE * fabs(LitThermo671) + KT);  
	dev672 = perdev672 / (ESCALE * fabs(LitThermo672) + KT);  
	dev673 = perdev673 / (ESCALE * fabs(LitThermo673) + KT);  
	dev674 = perdev674 / (ESCALE * fabs(LitThermo674) + KT);  
	dev675 = perdev675 / (ESCALE * fabs(LitThermo675) + KT);  
	dev676 = perdev676 / (ESCALE * fabs(LitThermo676) + KT);  
	dev677 = perdev677 / (ESCALE * fabs(LitThermo677) + KT);  
	dev678 = perdev678 / (ESCALE * fabs(LitThermo678) + KT);  
	dev679 = perdev679 / (ESCALE * fabs(LitThermo679) + KT);  
	dev680 = perdev680 / (ESCALE * fabs(LitThermo680) + KT);  
	dev681 = perdev681 / (ESCALE * fabs(LitThermo681) + KT);  
	dev682 = perdev682 / (ESCALE * fabs(LitThermo682) + KT);  
	dev683 = perdev683 / (ESCALE * fabs(LitThermo683) + KT);  
	dev684 = perdev684 / (ESCALE * fabs(LitThermo684) + KT);  
	dev685 = perdev685 / (ESCALE * fabs(LitThermo685) + KT);  
	dev686 = perdev686 / (ESCALE * fabs(LitThermo686) + KT);  
	dev687 = perdev687 / (ESCALE * fabs(LitThermo687) + KT);  
	dev688 = perdev688 / (ESCALE * fabs(LitThermo688) + KT);  
	dev689 = perdev689 / (ESCALE * fabs(LitThermo689) + KT);  
	dev690 = perdev690 / (ESCALE * fabs(LitThermo690) + KT);  
	dev691 = perdev691 / (ESCALE * fabs(LitThermo691) + KT);  
	dev692 = perdev692 / (ESCALE * fabs(LitThermo692) + KT);  
	dev693 = perdev693 / (ESCALE * fabs(LitThermo693) + KT);  
	dev711 = perdev711 / (ESCALE * fabs(LitThermo711) + KT);  

	perdev1 /= LitThermo1;
	perdev2 /= LitThermo2;
	perdev3 /= LitThermo3;
	perdev4 /= LitThermo4;
	perdev5 /= LitThermo5;
	perdev6 /= LitThermo6;
	perdev7 /= LitThermo7;
	perdev8 /= LitThermo8;
	perdev9 /= LitThermo9;
	perdev10 /= LitThermo10;
	perdev11 /= LitThermo11;
	perdev12 /= LitThermo12;
	perdev13 /= LitThermo13;
	perdev14 /= LitThermo14;
	perdev15 /= LitThermo15;
	perdev16 /= LitThermo16;
	perdev17 /= LitThermo17;
	perdev18 /= LitThermo18;
	perdev19 /= LitThermo19;
	perdev20 /= LitThermo20;
	perdev21 /= LitThermo21;
	perdev22 /= LitThermo22;
	perdev23 /= LitThermo23;
	perdev24 /= LitThermo24;
	perdev25 /= LitThermo25;
	perdev26 /= LitThermo26;
	perdev27 /= LitThermo27;
	perdev28 /= LitThermo28;
	perdev29 /= LitThermo29;
	perdev251 /= LitThermo251;
	perdev252 /= (LitThermo29 + LitThermo251);
	perdev253 /= LitThermo253;
	perdev254 /= LitThermo254;

//	perdev31 /= LitThermo31;
	perdev32 /= LitThermo32;
	perdev33 /= LitThermo33;
	perdev34 /= LitThermo34;
	perdev35 /= LitThermo35;
	perdev36 /= LitThermo36;
	perdev37 /= LitThermo37;
	perdev38 /= LitThermo38;
	perdev39 /= LitThermo39;
	perdev40 /= LitThermo40;
	perdev122/= LitThermo122;
	perdev41 /= LitThermo41;
	perdev42 /= LitThermo42;

	perdev30 /= LitThermo30;
	perdev117/= LitThermo117;
	perdev118/= LitThermo118;
	perdev119/= LitThermo119;
	perdev120/= LitThermo120;
	perdev121/= LitThermo121;
	perdev123/= LitThermo123;

	perdev43 /= LitThermo43;
	perdev44 /= LitThermo44;
	perdev45 /= LitThermo45;
	perdev46 /= LitThermo46;
	perdev47 /= LitThermo47;
	perdev48 /= LitThermo48;
	perdev49 /= LitThermo49;
	perdev50 /= LitThermo50;
	perdev51 /= LitThermo51;
	perdev52 /= LitThermo52;
	perdev53 /= LitThermo53;
	perdev54 /= LitThermo54;
	perdev55 /= LitThermo55;
	perdev56 /= LitThermo56;
	perdev57 /= LitThermo57;
	perdev58 /= LitThermo58;
	perdev59 /= LitThermo59;
	perdev60 /= LitThermo60;
	perdev61 /= LitThermo61;
	perdev62 /= LitThermo62;
	perdev63 /= LitThermo63;
	perdev64 /= LitThermo64;
	perdev65 /= LitThermo65;
	perdev66 /= LitThermo66;
	perdev67 /= LitThermo67;
	perdev68 /= LitThermo68;
	perdev69 /= LitThermo69;
	perdev70 /= LitThermo70;
	perdev71 /= LitThermo71;
	perdev72 /= LitThermo72;
	perdev73 /= LitThermo73;
	perdev74 /= LitThermo74;
	perdev75 /= LitThermo75;
	perdev76 /= LitThermo76;
	perdev77 /= LitThermo77;
	perdev78 /= LitThermo78;
	perdev79 /= LitThermo79;
	perdev80 /= LitThermo80;
	perdev81 /= LitThermo81;
	perdev82 /= LitThermo82;
	perdev83 /= LitThermo83;
	perdev84 /= LitThermo84;
	perdev85 /= LitThermo85;
	perdev86 /= LitThermo86;
	perdev87 /= LitThermo87;
	perdev88 /= LitThermo88;
	perdev89 /= LitThermo89;
	perdev90 /= LitThermo90;
	perdev91 /= LitThermo91;
	perdev92 /= LitThermo92;
	perdev93 /= LitThermo93;
	perdev94 /= LitThermo94;
	perdev95 /= LitThermo95;
	perdev96 /= LitThermo96;
	perdev97 /= LitThermo97;
	perdev98 /= LitThermo98;
	perdev99 /= LitThermo99;
	perdev100 /= LitThermo100;
	perdev101 /= LitThermo101;
	perdev102 /= LitThermo102;
	perdev103 /= LitThermo103;
	perdev104 /= LitThermo104;
	perdev105 /= LitThermo105;
	perdev106 /= LitThermo106;
	perdev107 /= LitThermo107;
	perdev108 /= LitThermo108;
	perdev109 /= LitThermo109;
	perdev110 /= LitThermo110;
	perdev111 /= LitThermo111;
	perdev112 /= LitThermo112;
	perdev113 /= LitThermo113;
	perdev114 /= LitThermo114;
	perdev115 /= LitThermo115;
	perdev116 /= LitThermo116;

	perdev126 /= LitThermo126;
	perdev127 /= LitThermo127;
	perdev128 /= LitThermo128;
	perdev129 /= LitThermo129;
	perdev130 /= LitThermo130;
	perdev131 /= LitThermo131;
	perdev132 /= LitThermo132;
	perdev133 /= LitThermo133;
	perdev134 /= LitThermo134;
	perdev135 /= LitThermo135;
	perdev136 /= LitThermo136;
	perdev137 /= LitThermo137;
	perdev138 /= LitThermo138;
	perdev139 /= LitThermo139;
	perdev140 /= LitThermo140;
	perdev141 /= LitThermo141;
	perdev142 /= LitThermo142;
	perdev143 /= LitThermo143;
	perdev144 /= LitThermo144;
	perdev145 /= LitThermo145;
	perdev146 /= LitThermo146;
	perdev147 /= LitThermo147;
	perdev148 /= LitThermo148;
	perdev149 /= LitThermo149;
	perdev150 /= LitThermo150;
	perdev151 /= LitThermo151;
	perdev152 /= LitThermo152;
	perdev153 /= LitThermo153;
	perdev154 /= LitThermo154;
	perdev155 /= LitThermo155;
	perdev156 /= LitThermo156;
	perdev157 /= LitThermo157;
	perdev158 /= LitThermo158;
	perdev159 /= LitThermo159;
	perdev160 /= LitThermo160;
	perdev161 /= LitThermo161;
	perdev162 /= LitThermo162;
	perdev163 /= LitThermo163;
	perdev164 /= LitThermo164;
	perdev165 /= LitThermo165;
	perdev166 /= LitThermo166;
	perdev167 /= LitThermo167;
	perdev168 /= LitThermo168;
	perdev169 /= LitThermo169;
	perdev170 /= LitThermo170;
	perdev171 /= LitThermo171;
	perdev172 /= LitThermo172;
	perdev173 /= LitThermo173;
	perdev174 /= LitThermo174;
	perdev175 /= LitThermo175;
	perdev176 /= LitThermo176;
	perdev177 /= LitThermo177;
	perdev178 /= LitThermo178;
	perdev179 /= LitThermo179;
	perdev180 /= LitThermo180;
	perdev181 /= LitThermo181;
	perdev182 /= LitThermo182;
	perdev183 /= LitThermo183;
	perdev184 /= LitThermo184;
	perdev185 /= LitThermo185;
	perdev186 /= LitThermo186;
	perdev187 /= LitThermo187;
	perdev188 /= LitThermo188;
	perdev189 /= LitThermo189;
	perdev190 /= LitThermo190;
	perdev191 /= LitThermo191;
	perdev192 /= LitThermo192;
	perdev193 /= LitThermo193;
	perdev194 /= LitThermo194;
	perdev195 /= LitThermo195;
	perdev196 /= LitThermo196;
	perdev197 /= LitThermo197;
	perdev198 /= LitThermo198;
	perdev199 /= LitThermo199;
	perdev200 /= LitThermo200;
	perdev201 /= LitThermo201;
	perdev202 /= LitThermo202;
	perdev203 /= LitThermo203;
	perdev204 /= LitThermo204;
	perdev205 /= LitThermo205;
	perdev206 /= LitThermo206;
	perdev207 /= LitThermo207;
//	perdev208 /= LitThermo208;
//	perdev209 /= LitThermo209;
	perdev210 /= LitThermo210;
//	perdev211 /= LitThermo211;
	perdev224 /= LitThermo224;

	perdev214 /= LitThermo214;
	perdev215 /= LitThermo215;
	perdev216 /= LitThermo216;
	perdev217 /= LitThermo217;
	perdev218 /= LitThermo218;
	perdev219 /= LitThermo219;
	perdev220 /= LitThermo220;
	perdev221 /= LitThermo221;
	perdev222 /= LitThermo222;
	perdev223 /= LitThermo223;

	perdev225 /= LitThermo225;
        perdev226 /= LitThermo226;
        perdev227 /= LitThermo227;
        perdev228 /= LitThermo228;
        perdev229 /= LitThermo229;
        perdev230 /= LitThermo230;
        perdev231 /= LitThermo231;
        perdev232 /= LitThermo232;
        perdev233 /= LitThermo233;
//	perdev234 /= LitThermo234;
//	perdev235 /= LitThermo235;
//	perdev236 /= LitThermo236;

//      perdev238 /= LitThermo238;
//      perdev239 /= LitThermo239;
//      perdev240 /= LitThermo240;
//      perdev241 /= LitThermo241;
//      perdev242 /= LitThermo242;
//      perdev243 /= LitThermo243;
	perdev244 /= LitThermo244;
        perdev245 /= LitThermo245;
        perdev246 /= LitThermo246;
        perdev247 /= LitThermo247;
        perdev248 /= LitThermo248;

	perdev256 /= LitThermo256;
	perdev257 /= LitThermo257;
	perdev258 /= LitThermo258;
	perdev259 /= LitThermo259;
	perdev260 /= LitThermo260;
	perdev261 /= LitThermo261;
	perdev262 /= LitThermo262;
	perdev263 /= LitThermo263;
	perdev264 /= LitThermo264;
	perdev265 /= LitThermo265;
	perdev266 /= LitThermo266;
	perdev267 /= LitThermo267;
	perdev268 /= LitThermo268;
	perdev269 /= LitThermo269;
	perdev270 /= LitThermo270;
	perdev271 /= LitThermo271;
	perdev272 /= LitThermo272;
	perdev273 /= LitThermo273;
	perdev274 /= LitThermo274;
	perdev275 /= LitThermo275;
	perdev276 /= LitThermo276;
	perdev277 /= LitThermo277;
	perdev278 /= LitThermo278;
	perdev279 /= LitThermo279;
	perdev280 /= LitThermo280;
	perdev281 /= LitThermo281;
	perdev282 /= LitThermo282;
	perdev283 /= LitThermo283;
	perdev284 /= LitThermo284;
	perdev285 /= LitThermo285;
	perdev286 /= LitThermo286;
	perdev287 /= LitThermo287;
	perdev288 /= LitThermo288;
	perdev289 /= LitThermo289;
	perdev290 /= LitThermo290;
	perdev291 /= LitThermo291;
	perdev292 /= LitThermo292;
	perdev293 /= LitThermo293;
	perdev294 /= LitThermo294;
	perdev295 /= LitThermo295;
	perdev296 /= LitThermo296;
	perdev297 /= LitThermo297;
	perdev298 /= LitThermo298;
	perdev299 /= LitThermo299;
	perdev300 /= LitThermo300;
	perdev301 /= LitThermo301;
	perdev302 /= LitThermo302;
	perdev303 /= LitThermo303;
	perdev304 /= LitThermo304;
	perdev305 /= LitThermo305;
	perdev306 /= LitThermo306;
	perdev307 /= LitThermo307;
	perdev308 /= LitThermo308;
	perdev309 /= LitThermo309;
	perdev310 /= LitThermo310;
	perdev311 /= LitThermo311;
	perdev312 /= LitThermo312;
	perdev313 /= LitThermo313;
	perdev314 /= LitThermo314;
	perdev315 /= LitThermo315;
	perdev316 /= LitThermo316;
	perdev317 /= LitThermo317;
	perdev318 /= LitThermo318;
	perdev319 /= LitThermo319;
	perdev320 /= LitThermo320;
	perdev321 /= LitThermo321;
	perdev322 /= LitThermo322;
	perdev323 /= LitThermo323;
	perdev324 /= LitThermo324;
	perdev325 /= LitThermo325;
	perdev326 /= LitThermo326;
	perdev327 /= LitThermo327;
	perdev328 /= LitThermo328;
	perdev329 /= LitThermo329;
	perdev330 /= LitThermo330;
	perdev331 /= LitThermo331;
	perdev332 /= LitThermo332;
	perdev333 /= LitThermo333;
	perdev334 /= LitThermo334;
	perdev335 /= LitThermo335;
	perdev336 /= LitThermo336;
	perdev337 /= LitThermo337;
	perdev338 /= LitThermo338;
	perdev339 /= LitThermo339;
	perdev340 /= LitThermo340;
	perdev341 /= LitThermo341;
	perdev342 /= LitThermo342;
	perdev343 /= LitThermo343;
	perdev344 /= LitThermo344;
	perdev345 /= LitThermo345;
	perdev346 /= LitThermo346;
	perdev347 /= LitThermo347;
	perdev348 /= LitThermo348;
	perdev349 /= LitThermo349;
	perdev350 /= LitThermo350;
	perdev351 /= LitThermo351;
	perdev352 /= LitThermo352;
	perdev353 /= LitThermo353;
	perdev354 /= LitThermo354;
	perdev355 /= LitThermo355;
	perdev356 /= LitThermo356;
	perdev357 /= LitThermo357;
	perdev358 /= LitThermo358;
	perdev359 /= LitThermo359;
	perdev360 /= LitThermo360;
	perdev361 /= LitThermo361;
	perdev362 /= LitThermo362;
	perdev363 /= LitThermo363;
	perdev364 /= LitThermo364;
	perdev365 /= LitThermo365;
	perdev366 /= LitThermo366;
	perdev367 /= LitThermo367;
	perdev368 /= LitThermo368;
	perdev369 /= LitThermo369;
	perdev370 /= LitThermo370;
	perdev371 /= LitThermo371;
	perdev372 /= LitThermo372;
	perdev373 /= LitThermo373;
	perdev374 /= LitThermo374;
	perdev375 /= LitThermo375;
	perdev376 /= LitThermo376;
	perdev377 /= LitThermo377;
	perdev378 /= LitThermo378;
	perdev379 /= LitThermo379;
	perdev380 /= LitThermo380;
	perdev381 /= LitThermo381;
	perdev382 /= LitThermo382;
	perdev383 /= LitThermo383;
	perdev384 /= LitThermo384;
	perdev385 /= LitThermo385;
	perdev386 /= LitThermo386;
	perdev387 /= LitThermo387;
	perdev388 /= LitThermo388;
	perdev389 /= LitThermo389;
	perdev390 /= LitThermo390;
	perdev391 /= LitThermo391;
	perdev392 /= LitThermo392;
	perdev393 /= LitThermo393;
	perdev394 /= LitThermo394;
	perdev395 /= LitThermo395;
	perdev396 /= LitThermo396;
	perdev397 /= LitThermo397;
	perdev398 /= LitThermo398;
	perdev399 /= LitThermo399;
	perdev400 /= LitThermo400;
	perdev401 /= LitThermo401;
	perdev402 /= LitThermo402;
	perdev403 /= LitThermo403;
	perdev404 /= LitThermo404;
	perdev405 /= LitThermo405;
	perdev406 /= LitThermo406;
	perdev407 /= LitThermo407;
	perdev408 /= LitThermo408;
	perdev409 /= LitThermo409;
	perdev410 /= LitThermo410;
	perdev411 /= LitThermo411;
	perdev412 /= LitThermo412;
	perdev413 /= LitThermo413;
	perdev414 /= LitThermo414;
	perdev415 /= LitThermo415;
	perdev416 /= LitThermo416;
	perdev417 /= LitThermo417;
	perdev418 /= LitThermo418;
	perdev419 /= LitThermo419;
	perdev420 /= LitThermo420;
	perdev421 /= LitThermo421;
	perdev422 /= LitThermo422;
	perdev423 /= LitThermo423;
	perdev424 /= LitThermo424;
	perdev425 /= LitThermo425;
	perdev426 /= LitThermo426;
	perdev427 /= LitThermo427;
	perdev428 /= LitThermo428;
	perdev429 /= LitThermo429;
	perdev430 /= LitThermo430;
	perdev431 /= LitThermo431;
	perdev432 /= LitThermo432;
	perdev433 /= LitThermo433;
	perdev434 /= LitThermo434;
	perdev435 /= LitThermo435;
	perdev436 /= LitThermo436;
	perdev437 /= LitThermo437;
	perdev438 /= LitThermo438;
	perdev439 /= LitThermo439;
	perdev440 /= LitThermo440;
	perdev441 /= LitThermo441;
	perdev442 /= LitThermo442;
	perdev443 /= LitThermo443;
	perdev444 /= LitThermo444;
	perdev445 /= LitThermo445;
	perdev446 /= LitThermo446;
	perdev447 /= LitThermo447;
	perdev448 /= LitThermo448;
	perdev449 /= LitThermo449;
	perdev450 /= LitThermo450;
	perdev451 /= LitThermo451;
	perdev452 /= LitThermo452;
	perdev453 /= LitThermo453;
	perdev454 /= LitThermo454;
	perdev455 /= LitThermo455;
	perdev456 /= LitThermo456;
	perdev457 /= LitThermo457;
	perdev458 /= LitThermo458;
	perdev459 /= LitThermo459;
	perdev460 /= LitThermo460;
	perdev461 /= LitThermo461;
	perdev462 /= LitThermo462;
	perdev463 /= LitThermo463;
	perdev464 /= LitThermo464;
	perdev465 /= LitThermo465;
	perdev466 /= LitThermo466;
	perdev467 /= LitThermo467;
	perdev468 /= LitThermo468;
	perdev469 /= LitThermo469;
	perdev470 /= LitThermo470;
	perdev471 /= LitThermo471;
	perdev472 /= LitThermo472;
	perdev473 /= LitThermo473;
	perdev474 /= LitThermo474;
	perdev475 /= LitThermo475;
	perdev476 /= LitThermo476;
	perdev477 /= LitThermo477;
	perdev478 /= LitThermo478;
	perdev479 /= LitThermo479;
	perdev480 /= LitThermo480;
	perdev481 /= LitThermo481;
	perdev482 /= LitThermo482;
	perdev483 /= LitThermo483;
	perdev484 /= LitThermo484;
	perdev485 /= LitThermo485;
	perdev486 /= LitThermo486;
	perdev487 /= LitThermo487;
	perdev488 /= LitThermo488;
	perdev489 /= LitThermo489;
	perdev490 /= LitThermo490;
	perdev491 /= LitThermo491;
	perdev492 /= LitThermo492;
	perdev493 /= LitThermo493;
	perdev494 /= LitThermo494;
	perdev495 /= LitThermo495;
	perdev496 /= LitThermo496;
	perdev497 /= LitThermo497;
	perdev498 /= LitThermo498;
	perdev499 /= LitThermo499;
	perdev500 /= LitThermo500;
	perdev501 /= LitThermo501;
	perdev502 /= LitThermo502;
	perdev503 /= LitThermo503;
	perdev504 /= LitThermo504;
	perdev505 /= LitThermo505;
	perdev506 /= LitThermo506;
	perdev507 /= LitThermo507;
	perdev508 /= LitThermo508;
	perdev509 /= LitThermo509;
	perdev510 /= LitThermo510;
	perdev511 /= LitThermo511;
	perdev512 /= LitThermo512;
	perdev513 /= LitThermo513;
	perdev514 /= LitThermo514;
	perdev515 /= LitThermo515;
	perdev516 /= LitThermo516;
	perdev517 /= LitThermo517;
	perdev518 /= LitThermo518;
	perdev519 /= LitThermo519;
	perdev520 /= LitThermo520;
	perdev521 /= LitThermo521;
	perdev522 /= LitThermo522;
	perdev523 /= LitThermo523;
	perdev524 /= LitThermo524;
	perdev525 /= LitThermo525;
	perdev526 /= LitThermo526;
	perdev527 /= LitThermo527;
	perdev528 /= LitThermo528;
	perdev529 /= LitThermo529;
	perdev530 /= LitThermo530;
	perdev531 /= LitThermo531;
	perdev532 /= LitThermo532;
	perdev533 /= LitThermo533;
	perdev534 /= LitThermo534;
	perdev535 /= LitThermo535;
	perdev536 /= LitThermo536;
	perdev537 /= LitThermo537;
	perdev538 /= LitThermo538;
	perdev539 /= LitThermo539;
	perdev540 /= LitThermo540;
	perdev541 /= LitThermo541;
	perdev542 /= LitThermo542;
	perdev543 /= LitThermo543;
	perdev544 /= LitThermo544;
	perdev545 /= LitThermo545;
	perdev546 /= LitThermo546;
	perdev547 /= LitThermo547;
	perdev548 /= LitThermo548;
	perdev549 /= LitThermo549;
	perdev550 /= LitThermo550;
	perdev551 /= LitThermo551;
	perdev552 /= LitThermo552;
	perdev553 /= LitThermo553;
	perdev554 /= LitThermo554;
	perdev555 /= LitThermo555;
	perdev556 /= LitThermo556;
	perdev557 /= LitThermo557;
	perdev558 /= LitThermo558;
	perdev559 /= LitThermo559;
	perdev560 /= LitThermo560;
	perdev561 /= LitThermo561;
	perdev562 /= LitThermo562;
	perdev563 /= LitThermo563;
	perdev564 /= LitThermo564;
	perdev565 /= LitThermo565;
	perdev566 /= LitThermo566;
	perdev567 /= LitThermo567;
	perdev568 /= LitThermo568;
	perdev569 /= LitThermo569;
	perdev570 /= LitThermo570;
	perdev571 /= LitThermo571;
	perdev572 /= LitThermo572;
	perdev573 /= LitThermo573;
	perdev574 /= LitThermo574;
	perdev575 /= LitThermo575;
	perdev576 /= LitThermo576;
	perdev577 /= LitThermo577;
	perdev578 /= LitThermo578;
	perdev579 /= LitThermo579;
	perdev580 /= LitThermo580;
	perdev581 /= LitThermo581;
	perdev582 /= LitThermo582;
	perdev583 /= LitThermo583;
	perdev584 /= LitThermo584;
	perdev585 /= LitThermo585;
	perdev586 /= LitThermo586;
	perdev587 /= LitThermo587;
	perdev588 /= LitThermo588;
	perdev589 /= LitThermo589;
	perdev590 /= LitThermo590;
	perdev591 /= LitThermo591;
	perdev592 /= LitThermo592;
	perdev593 /= LitThermo593;
	perdev594 /= LitThermo594;
	perdev595 /= LitThermo595;
	perdev596 /= LitThermo596;
	perdev597 /= LitThermo597;
	perdev598 /= LitThermo598;
	perdev599 /= LitThermo599;
	perdev600 /= LitThermo600;
	perdev601 /= LitThermo601;
	perdev602 /= LitThermo602;
	perdev603 /= LitThermo603;
	perdev604 /= LitThermo604;
	perdev605 /= LitThermo605;
	perdev606 /= LitThermo606;
	perdev607 /= LitThermo607;
	perdev608 /= LitThermo608;
	perdev609 /= LitThermo609;
	perdev610 /= LitThermo610;
	perdev611 /= LitThermo611;
	perdev612 /= LitThermo612;
	perdev613 /= LitThermo613;
	perdev614 /= LitThermo614;
	perdev615 /= LitThermo615;
	perdev616 /= LitThermo616;
	perdev617 /= LitThermo617;
	perdev618 /= LitThermo618;
	perdev619 /= LitThermo619;
	perdev620 /= LitThermo620;
	perdev621 /= LitThermo621;
	perdev622 /= LitThermo622;
	perdev623 /= LitThermo623;
	perdev624 /= LitThermo624;
	perdev625 /= LitThermo625;
	perdev626 /= LitThermo626;
	perdev627 /= LitThermo627;
	perdev628 /= LitThermo628;
	perdev629 /= LitThermo629;
	perdev630 /= LitThermo630;
	perdev631 /= LitThermo631;
	perdev632 /= LitThermo632;
	perdev633 /= LitThermo633;
	perdev634 /= LitThermo634;
	perdev635 /= LitThermo635;
	perdev636 /= LitThermo636;
	perdev637 /= LitThermo637;
	perdev638 /= LitThermo638;
	perdev639 /= LitThermo639;
	perdev640 /= LitThermo640;
	perdev641 /= LitThermo641;
	perdev642 /= LitThermo642;
	perdev643 /= LitThermo643;
	perdev644 /= LitThermo644;
	perdev645 /= LitThermo645;
	perdev646 /= LitThermo646;
	perdev647 /= LitThermo647;
	perdev648 /= LitThermo648;
	perdev649 /= LitThermo649;
	perdev650 /= LitThermo650;
	perdev651 /= LitThermo651;
	perdev652 /= LitThermo652;
	perdev653 /= LitThermo653;
	perdev654 /= LitThermo654;
	perdev655 /= LitThermo655;
	perdev656 /= LitThermo656;
	perdev657 /= LitThermo657;
	perdev658 /= LitThermo658;
	perdev659 /= LitThermo659;
	perdev660 /= LitThermo660;
	perdev661 /= LitThermo661;
	perdev662 /= LitThermo662;
	perdev663 /= LitThermo663;
	perdev664 /= LitThermo664;
	perdev665 /= LitThermo665;
	perdev666 /= LitThermo666;
	perdev667 /= LitThermo667;
	perdev668 /= LitThermo668;
	perdev669 /= LitThermo669;
	perdev670 /= LitThermo670;
	perdev671 /= LitThermo671;
	perdev672 /= LitThermo672;
	perdev673 /= LitThermo673;
	perdev674 /= LitThermo674;
	perdev675 /= LitThermo675;
	perdev676 /= LitThermo676;
	perdev677 /= LitThermo677;
	perdev678 /= LitThermo678;
	perdev679 /= LitThermo679;
	perdev680 /= LitThermo680;
	perdev681 /= LitThermo681;
	perdev682 /= LitThermo682;
	perdev683 /= LitThermo683;
	perdev684 /= LitThermo684;
	perdev685 /= LitThermo685;
	perdev686 /= LitThermo686;
	perdev687 /= LitThermo687;
	perdev688 /= LitThermo688;
	perdev689 /= LitThermo689;
	perdev690 /= LitThermo690;
	perdev691 /= LitThermo691;
	perdev692 /= LitThermo692;
	perdev693 /= LitThermo693;
	perdev711 /= LitThermo711;
	//mean fabsolute deviations

	deviation += fabs(dev1) * wspinH2aff;
	deviation += fabs(dev2) * wspinOHaff;
	deviation += fabs(dev3) * wspinH2Oaff;
	deviation += fabs(dev4) * wspinO_2aff;
	deviation += fabs(dev5) * wspinH2dis;
	deviation += fabs(dev6) * wspinH2ion;
	deviation += fabs(dev7) * wspinH2Odis;
//	deviation += fabs(dev8) * wspinOeaff;
//	deviation += fabs(dev9) * wspinO_1eaff;
//	deviation += fabs(dev10) * wspinOneutrlion;
//	deviation += fabs(dev11) * wspinOplus1ion;
	deviation += fabs(dev12) * wspinO2_2dis;
	deviation += fabs(dev13) * wspinO2_1dis;
	deviation += fabs(dev14) * wspinO2dis;
	deviation += fabs(dev15) * wspinOHdotaff;
	deviation += fabs(dev16) * wspinO_1aff;
	deviation += fabs(dev17) * wspinH2Odim;
	deviation += fabs(dev18) * wspinHeaff;
	deviation += fabs(dev19) * wspinHion;
	deviation += fabs(dev20) * wspinOHdotdis;
//	deviation += fabs(dev21) * wspinHeaff_trp;

	//incremental ionizations
	deviation += fabs(dev22) * wspinOneutrlion;
	deviation += fabs(dev23) * wspinOplus1ion;
	deviation += fabs(dev24) * wspinOplus2ion;
	deviation += fabs(dev25) * wspinOplus3ion;
	deviation += fabs(dev26) * wspinOplus4ion;
	deviation += fabs(dev27) * wspinOplus5ion;
	deviation += fabs(dev28) * wspinOplus6ion;
//	deviation += fabs(dev29) * wspinO2ex;
//	deviation += fabs(dev252) * wspinO2ex2;

	//total energies of molecules
	deviation += fabs(dev32) * wspinOeaff;
	deviation += fabs(dev33) * wspinOneutrlion;
	deviation += fabs(dev34) * wspinOplus1ion;
	deviation += fabs(dev35) * wspinOplus2ion;
	deviation += fabs(dev36) * wspinOplus3ion;
	deviation += fabs(dev37) * wspinOplus4ion;
	deviation += fabs(dev38) * wspinOplus5ion;

	//incremental excitations 
	deviation += fabs(dev39) * wspinOneutrlexion;
	deviation += fabs(dev40) * wspinOplus2ionex;
	deviation += fabs(dev122) * wspinOplus2ionex2;
	deviation += fabs(dev41) * wspinOplus1ionex;
	deviation += fabs(dev42) * wspinOplus4ionex;
	deviation += fabs(dev30) * wspinOplus3ionex;

	//total energies of molecules (excited states)
//	deviation += fabs(dev117) * wspinOneutrlexion;
//	deviation += fabs(dev118) * wspinOplus1ionex;
//	deviation += fabs(dev119) * wspinOplus2ionex;
//	deviation += fabs(dev123) * wspinOplus2ionex2;
//	deviation += fabs(dev120) * wspinOplus3ionex;
//	deviation += fabs(dev121) * wspinOplus4ionex;

	deviation += fabs(dev43) * wspinCplus3ion;
	deviation += fabs(dev44) * wspinCplus2ion;
	deviation += fabs(dev45) * wspinCplus1ion;
	deviation += fabs(dev46) * wspinCneutrlion;
	deviation += fabs(dev47) * wspinC_1ion;
	deviation += fabs(dev48) * wspinNplus4ion;
	deviation += fabs(dev49) * wspinNplus3ion;
	deviation += fabs(dev50) * wspinNplus2ion;
	deviation += fabs(dev51) * wspinNplus1ion;
	deviation += fabs(dev52) * wspinNneutrlion;
//	deviation += fabs(dev53) * wspinN_1ion;
	deviation += fabs(dev54) * wspinSplus5ion;
	deviation += fabs(dev55) * wspinSplus4ion;
	deviation += fabs(dev56) * wspinSplus3ion;
	deviation += fabs(dev57) * wspinSplus2ion;
	deviation += fabs(dev58) * wspinSplus1ion;
	deviation += fabs(dev59) * wspinSneutrlion;
	deviation += fabs(dev60) * wspinS_1ion;
	deviation += fabs(dev61) * wspinPplus4ion;
	deviation += fabs(dev62) * wspinPplus3ion;
	deviation += fabs(dev63) * wspinPplus2ion;
	deviation += fabs(dev64) * wspinPplus1ion;
	deviation += fabs(dev65) * wspinPneutrlion;
	deviation += fabs(dev66) * wspinP_1ion;
	deviation += fabs(dev67) * wspinSiplus3ion;
	deviation += fabs(dev68) * wspinSiplus2ion;
	deviation += fabs(dev69) * wspinSiplus1ion;
	deviation += fabs(dev70) * wspinSineutrlion;
	deviation += fabs(dev71) * wspinSi_1ion;
	deviation += fabs(dev72) * wspinFplus6ion;
	deviation += fabs(dev73) * wspinFplus5ion;
	deviation += fabs(dev74) * wspinFplus4ion;
	deviation += fabs(dev75) * wspinFplus3ion;
	deviation += fabs(dev76) * wspinFplus2ion;
	deviation += fabs(dev77) * wspinFplus1ion;
	deviation += fabs(dev78) * wspinFneutrlion;
	deviation += fabs(dev79) * wspinF_1ion;
	deviation += fabs(dev80) * wspinCplus3ion;
	deviation += fabs(dev81) * wspinCplus2ion;
	deviation += fabs(dev82) * wspinCplus1ion;
	deviation += fabs(dev83) * wspinCneutrlion;
	deviation += fabs(dev84) * wspinC_1ion;
	deviation += fabs(dev85) * wspinNplus4ion;
	deviation += fabs(dev86) * wspinNplus3ion;
	deviation += fabs(dev87) * wspinNplus2ion;
	deviation += fabs(dev88) * wspinNplus1ion;
	deviation += fabs(dev89) * wspinNneutrlion;
//	deviation += fabs(dev90) * wspinN_1ion;
	deviation += fabs(dev91) * wspinSplus5ion;
	deviation += fabs(dev92) * wspinSplus4ion;
	deviation += fabs(dev93) * wspinSplus3ion;
	deviation += fabs(dev94) * wspinSplus2ion;
	deviation += fabs(dev95) * wspinSplus1ion;
	deviation += fabs(dev96) * wspinSneutrlion;
	deviation += fabs(dev97) * wspinS_1ion;
	deviation += fabs(dev98) * wspinPplus4ion;
	deviation += fabs(dev99) * wspinPplus3ion;
	deviation += fabs(dev100) * wspinPplus2ion;
	deviation += fabs(dev101) * wspinPplus1ion;
	deviation += fabs(dev102) * wspinPneutrlion;
	deviation += fabs(dev103) * wspinP_1ion;
	deviation += fabs(dev104) * wspinSiplus3ion;
	deviation += fabs(dev105) * wspinSiplus2ion;
	deviation += fabs(dev106) * wspinSiplus1ion;
	deviation += fabs(dev107) * wspinSineutrlion;
	deviation += fabs(dev108) * wspinSi_1ion;

	//total energies of Fluorine
	deviation += fabs(dev109) * wspinFplus6ion;
	deviation += fabs(dev110) * wspinFplus5ion;
	deviation += fabs(dev111) * wspinFplus4ion;
	deviation += fabs(dev112) * wspinFplus3ion;
	deviation += fabs(dev113) * wspinFplus2ion;
	deviation += fabs(dev114) * wspinFplus1ion;
	deviation += fabs(dev115) * wspinFneutrlion;
	deviation += fabs(dev116) * wspinF_1ion;

	deviation += fabs(dev126) * wspinCplus2exion;
	deviation += fabs(dev127) * wspinCplus1exion;
	deviation += fabs(dev128) * wspinCneutrlexion;
	deviation += fabs(dev129) * wspinCneutrlex2ion;
	deviation += fabs(dev130) * wspinNplus3exion;
	deviation += fabs(dev131) * wspinNplus2exion;
	deviation += fabs(dev132) * wspinNplus1exion;
	deviation += fabs(dev133) * wspinNplus1ex2ion;
	deviation += fabs(dev134) * wspinNneutrlexion;
	deviation += fabs(dev135) * wspinFplus5exion;
	deviation += fabs(dev136) * wspinFplus4exion;
	deviation += fabs(dev137) * wspinFplus3exion;
	deviation += fabs(dev138) * wspinFplus3ex2ion;
	deviation += fabs(dev139) * wspinFplus2exion;
	deviation += fabs(dev140) * wspinFplus1exion;
	deviation += fabs(dev141) * wspinSiplus2exion;
	deviation += fabs(dev142) * wspinSiplus1exion;
	deviation += fabs(dev143) * wspinSineutrlexion;
	deviation += fabs(dev144) * wspinSineutrlex2ion;
	deviation += fabs(dev145) * wspinPplus3exion;
	deviation += fabs(dev146) * wspinPplus2exion;
	deviation += fabs(dev147) * wspinPplus1exion;
	deviation += fabs(dev148) * wspinPplus1ex2ion;
	deviation += fabs(dev149) * wspinPneutrlexion;
	deviation += fabs(dev150) * wspinSplus4exion;
	deviation += fabs(dev151) * wspinSplus3exion;
	deviation += fabs(dev152) * wspinSplus2exion;
	deviation += fabs(dev153) * wspinSplus2ex2ion;
	deviation += fabs(dev154) * wspinSplus1exion;
	deviation += fabs(dev155) * wspinSneutrlexion;
	deviation += fabs(dev156) * wspinOneutrlex2ion;
	deviation += fabs(dev157) * wspinOplus1ex2ion;
//	deviation += fabs(dev158) * wspinNneutrlex2ion;
	deviation += fabs(dev159) * wspinFneutrlexion;
	deviation += fabs(dev160) * wspinFplus1ex2ion;
	deviation += fabs(dev161) * wspinFplus2ex2ion;
	deviation += fabs(dev162) * wspinSneutrlex2ion;
	deviation += fabs(dev163) * wspinOneutrlex2ion;
	deviation += fabs(dev164) * wspinBplus2ion;
	deviation += fabs(dev165) * wspinBplus1ion;
	deviation += fabs(dev166) * wspinBneutrlion;
	deviation += fabs(dev167) * wspinB_1ion;
	deviation += fabs(dev168) * wspinBplus1exion;
	deviation += fabs(dev169) * wspinBneutrlexion;
	deviation += fabs(dev170) * wspinBplus2ion;
	deviation += fabs(dev171) * wspinBplus1ion;
	deviation += fabs(dev172) * wspinBneutrlion;
	deviation += fabs(dev173) * wspinB_1ion;

	deviation += fabs(dev174) * wspinCl_1ion;
	deviation += fabs(dev175) * wspinClneutrlexion;
	deviation += fabs(dev176) * wspinClneutrlion;
	deviation += fabs(dev177) * wspinClplus1ex2ion;
	deviation += fabs(dev178) * wspinClplus1exion;
	deviation += fabs(dev179) * wspinClplus1ion;
	deviation += fabs(dev180) * wspinClplus2exion;
	deviation += fabs(dev181) * wspinClplus2ion;
	deviation += fabs(dev182) * wspinClplus3ex2ion;
	deviation += fabs(dev183) * wspinClplus3exion;
	deviation += fabs(dev184) * wspinClplus3ion;
	deviation += fabs(dev185) * wspinClplus4exion;
	deviation += fabs(dev186) * wspinClplus4ion;
	deviation += fabs(dev187) * wspinClplus5exion;
	deviation += fabs(dev188) * wspinClplus5ion;
	deviation += fabs(dev189) * wspinClplus6ion;

	deviation += fabs(dev190) * wspinAl_1ion;
	deviation += fabs(dev191) * wspinAlneutrlexion;
	deviation += fabs(dev192) * wspinAlneutrlion;
	deviation += fabs(dev193) * wspinAlplus1exion;
	deviation += fabs(dev194) * wspinAlplus1ion;
	deviation += fabs(dev195) * wspinAlplus2ion;

	//total energy of molecule deviations
	deviation += fabs(dev196) * wspinCl_1ion;
	deviation += fabs(dev197) * wspinClneutrlion;
	deviation += fabs(dev198) * wspinClplus1ion;
	deviation += fabs(dev199) * wspinClplus2ion;
	deviation += fabs(dev200) * wspinClplus3ion;
	deviation += fabs(dev201) * wspinClplus4ion;
	deviation += fabs(dev202) * wspinClplus5ion;
	deviation += fabs(dev203) * wspinClplus6ion;

	//total energy of molecules deviations
	deviation += fabs(dev204) * wspinAl_1ion;
	deviation += fabs(dev205) * wspinAlneutrlion;
	deviation += fabs(dev206) * wspinAlplus1ion;
	deviation += fabs(dev207) * wspinAlplus2ion;

	//sign error terms for H	
//	deviation += fabs(dev208) * wspinHsign;
//	deviation += fabs(dev209) * wspinHsign;
	deviation += fabs(dev210) * wspinH2eaff;
	deviation += fabs(dev211) * wspinHsign;
	deviation += fabs(dev224) * wspinH2exdis;
//	deviation += fabs(dev234) * wspinHsign;
//	deviation += fabs(dev235) * wspinHsign;
//	deviation += fabs(dev236) * wspinHsign;

	deviation += fabs(dev214) * wspinLi_1ion;
	deviation += fabs(dev215) * wspinLineutrlion;
	deviation += fabs(dev216) * wspinBeneutrlion;
	deviation += fabs(dev217) * wspinBeneutrlexion;
	deviation += fabs(dev218) * wspinBeplus1ion;
	deviation += fabs(dev219) * wspinNa_1ion;
	deviation += fabs(dev220) * wspinNaneutrlion;
	deviation += fabs(dev221) * wspinMgneutrlion;
	deviation += fabs(dev222) * wspinMgneutrlexion;
	deviation += fabs(dev223) * wspinMgplus1ion;

//	if(debug ==1){
//	printf("O2_li=%f\n",U_spinO2_linnett);
//	printf("O2_sng=%f\n",U_spinO2_snglbnd);
//	printf("O2_db=%f\n",U_spinO2_dblbnd);
//	printf("O2_tr=%f\n",U_spinO2_trplbnd);
//	printf("O2dia_li=%f\n",U_spinO2dia_linnett);
//	printf("O2dia_sng=%f\n",U_spinO2dia_snglbnd);
//	printf("O2dia_db=%f\n",U_spinO2dia_dblbnd);
//	printf("O2dia_tr=%f\n",U_spinO2dia_trplbnd);
//	printf("O2qnt_li=%f\n",U_spinO2qnt_linnett);
//	printf("O2qnt_sng=%f\n",U_spinO2qnt_snglbnd);
//	printf("O2qnt_db=%f\n",U_spinO2qnt_dblbnd);
//	printf("O2qnt_tr=%f\n",U_spinO2qnt_trplbnd);
//	printf("238=%f\n",dev238);
//	printf("239=%f\n",dev239);
//	printf("240=%f\n",dev240);
//	printf("241=%f\n",dev241);
//	printf("242=%f\n",dev242);
//	printf("243=%f\n",dev243);
//	printf("244=%f\n",dev244);
//	}

	deviation += fabs(dev238) * wspinO2_snglbnd;
	deviation += fabs(dev239) * wspinO2_dblbnd;
	deviation += fabs(dev240) * wspinO2_trplbnd;
	deviation += fabs(dev241) * wspinO2dia_snglbnd;
	deviation += fabs(dev242) * wspinO2dia_dblbnd;
	deviation += fabs(dev243) * wspinO2dia_trplbnd;
	deviation += fabs(dev244) * wspinH3lin;

	deviation += fabs(dev253) * wspinO2eaff;
	deviation += fabs(dev254) * wspinO2ion;
	deviation += fabs(dev256) * wspinScplus2ion;
	deviation += fabs(dev257) * wspinScplus1ion;
	deviation += fabs(dev258) * wspinScplus1exion;
	deviation += fabs(dev259) * wspinScneutrlion;
	deviation += fabs(dev260) * wspinScneutrlexion;
	deviation += fabs(dev261) * wspinScplus2ion;
	deviation += fabs(dev262) * wspinScplus1ion;
	deviation += fabs(dev263) * wspinScneutrlion;
	deviation += fabs(dev264) * wspinTiplus3ion;
	deviation += fabs(dev265) * wspinTiplus2ion;
	deviation += fabs(dev266) * wspinTiplus2exion;
	deviation += fabs(dev267) * wspinTiplus1ion;
	deviation += fabs(dev268) * wspinTiplus1exion;
	deviation += fabs(dev269) * wspinTineutrlion;
	deviation += fabs(dev270) * wspinTineutrlexion;
	deviation += fabs(dev271) * wspinTineutrlex2ion;
	deviation += fabs(dev272) * wspinTiplus3ion;
	deviation += fabs(dev273) * wspinTiplus2ion;
	deviation += fabs(dev274) * wspinTiplus1ion;
	deviation += fabs(dev275) * wspinTineutrlion;
	deviation += fabs(dev276) * wspinVplus4ion;
	deviation += fabs(dev277) * wspinVplus3ion;
	deviation += fabs(dev278) * wspinVplus3exion;
	deviation += fabs(dev279) * wspinVplus2ion;
	deviation += fabs(dev280) * wspinVplus2exion;
	deviation += fabs(dev281) * wspinVplus1ion;
	deviation += fabs(dev282) * wspinVplus1exion;
	deviation += fabs(dev283) * wspinVplus1ex2ion;
	deviation += fabs(dev284) * wspinVneutrlion;
	deviation += fabs(dev285) * wspinVneutrlexion;
	deviation += fabs(dev286) * wspinVneutrlex2ion;
	deviation += fabs(dev287) * wspinVplus4ion;
	deviation += fabs(dev288) * wspinVplus3ion;
	deviation += fabs(dev289) * wspinVplus2ion;
	deviation += fabs(dev290) * wspinVplus1ion;
	deviation += fabs(dev291) * wspinVneutrlion;
	deviation += fabs(dev292) * wspinCrplus5ion;
	deviation += fabs(dev293) * wspinCrplus4ion;
	deviation += fabs(dev294) * wspinCrplus4exion;
	deviation += fabs(dev295) * wspinCrplus3ion;
	deviation += fabs(dev296) * wspinCrplus3exion;
	deviation += fabs(dev297) * wspinCrplus2ion;
	deviation += fabs(dev298) * wspinCrplus2exion;
	deviation += fabs(dev299) * wspinCrplus2ex2ion;
	deviation += fabs(dev300) * wspinCrplus1ion;
	deviation += fabs(dev301) * wspinCrplus1exion;
	deviation += fabs(dev302) * wspinCrplus1ex2ion;
	deviation += fabs(dev303) * wspinCrneutrlion;
	deviation += fabs(dev304) * wspinCrneutrlexion;
	deviation += fabs(dev305) * wspinCrneutrlex2ion;
	deviation += fabs(dev306) * wspinCrneutrlex3ion;
	deviation += fabs(dev307) * wspinCrplus5ion;
	deviation += fabs(dev308) * wspinCrplus4ion;
	deviation += fabs(dev309) * wspinCrplus3ion;
	deviation += fabs(dev310) * wspinCrplus2ion;
	deviation += fabs(dev311) * wspinCrplus1ion;
	deviation += fabs(dev312) * wspinCrneutrlion;
	deviation += fabs(dev313) * wspinMnplus6ion;
	deviation += fabs(dev314) * wspinMnplus5ion;
	deviation += fabs(dev315) * wspinMnplus5exion;
	deviation += fabs(dev316) * wspinMnplus4ion;
	deviation += fabs(dev317) * wspinMnplus4exion;
	deviation += fabs(dev318) * wspinMnplus3ion;
	deviation += fabs(dev319) * wspinMnplus3exion;
	deviation += fabs(dev320) * wspinMnplus2ion;
	deviation += fabs(dev321) * wspinMnplus2exion;
	deviation += fabs(dev322) * wspinMnplus2ex2ion;
	deviation += fabs(dev323) * wspinMnplus1ion;
	deviation += fabs(dev324) * wspinMnplus1exion;
	deviation += fabs(dev325) * wspinMnplus1ex2ion;
	deviation += fabs(dev326) * wspinMnplus1ex3ion;
	deviation += fabs(dev327) * wspinMnneutrlion;
	deviation += fabs(dev328) * wspinMnneutrlexion;
	deviation += fabs(dev329) * wspinMnneutrlex2ion;
	deviation += fabs(dev330) * wspinMnneutrlex3ion;
	deviation += fabs(dev331) * wspinMnplus6ion;
	deviation += fabs(dev332) * wspinMnplus5ion;
	deviation += fabs(dev333) * wspinMnplus4ion;
	deviation += fabs(dev334) * wspinMnplus3ion;
	deviation += fabs(dev335) * wspinMnplus2ion;
	deviation += fabs(dev336) * wspinMnplus1ion;
	deviation += fabs(dev337) * wspinMnneutrlion;
	deviation += fabs(dev338) * wspinFeplus7ion;
	deviation += fabs(dev339) * wspinFeplus6ion;
	deviation += fabs(dev340) * wspinFeplus6exion;
	deviation += fabs(dev341) * wspinFeplus5ion;
	deviation += fabs(dev342) * wspinFeplus5exion;
	deviation += fabs(dev343) * wspinFeplus4ion;
	deviation += fabs(dev344) * wspinFeplus4exion;
	deviation += fabs(dev345) * wspinFeplus4ex2ion;
	deviation += fabs(dev346) * wspinFeplus3ion;
	deviation += fabs(dev347) * wspinFeplus3exion;
	deviation += fabs(dev348) * wspinFeplus3ex2ion;
	deviation += fabs(dev349) * wspinFeplus2ion;
	deviation += fabs(dev350) * wspinFeplus2exion;
	deviation += fabs(dev351) * wspinFeplus2ex2ion;
	deviation += fabs(dev352) * wspinFeplus1ion;
	deviation += fabs(dev353) * wspinFeplus1exion;
	deviation += fabs(dev354) * wspinFeplus1ex2ion;
	deviation += fabs(dev355) * wspinFeneutrlion;
	deviation += fabs(dev356) * wspinFeneutrlexion;
	deviation += fabs(dev357) * wspinFeneutrlex2ion;
	deviation += fabs(dev358) * wspinFeneutrlex3ion;
	deviation += fabs(dev359) * wspinFeplus7ion;
	deviation += fabs(dev360) * wspinFeplus6ion;
	deviation += fabs(dev361) * wspinFeplus5ion;
	deviation += fabs(dev362) * wspinFeplus4ion;
	deviation += fabs(dev363) * wspinFeplus3ion;
	deviation += fabs(dev364) * wspinFeplus2ion;
	deviation += fabs(dev365) * wspinFeplus1ion;
	deviation += fabs(dev366) * wspinFeneutrlion;
	deviation += fabs(dev367) * wspinCoplus8ion;
	deviation += fabs(dev368) * wspinCoplus7ion;
	deviation += fabs(dev369) * wspinCoplus7exion;
	deviation += fabs(dev370) * wspinCoplus6ion;
	deviation += fabs(dev371) * wspinCoplus6exion;
	deviation += fabs(dev372) * wspinCoplus5ion;
	deviation += fabs(dev373) * wspinCoplus5exion;
	deviation += fabs(dev374) * wspinCoplus5ex2ion;
	deviation += fabs(dev375) * wspinCoplus4ion;
	deviation += fabs(dev376) * wspinCoplus4exion;
	deviation += fabs(dev377) * wspinCoplus4ex2ion;
	deviation += fabs(dev378) * wspinCoplus3ion;
	deviation += fabs(dev379) * wspinCoplus3exion;
	deviation += fabs(dev380) * wspinCoplus3ex2ion;
	deviation += fabs(dev381) * wspinCoplus2ion;
	deviation += fabs(dev382) * wspinCoplus2exion;
	deviation += fabs(dev383) * wspinCoplus2ex2ion;
	deviation += fabs(dev384) * wspinCoplus1ion;
	deviation += fabs(dev385) * wspinCoplus1exion;
	deviation += fabs(dev386) * wspinCoplus1ex2ion;
	deviation += fabs(dev387) * wspinConeutrlion;
	deviation += fabs(dev388) * wspinConeutrlexion;
	deviation += fabs(dev389) * wspinCoplus8ion;
	deviation += fabs(dev390) * wspinCoplus7ion;
	deviation += fabs(dev391) * wspinCoplus6ion;
	deviation += fabs(dev392) * wspinCoplus5ion;
	deviation += fabs(dev393) * wspinCoplus4ion;
	deviation += fabs(dev394) * wspinCoplus3ion;
	deviation += fabs(dev395) * wspinCoplus2ion;
	deviation += fabs(dev396) * wspinCoplus1ion;
	deviation += fabs(dev397) * wspinConeutrlion;
	deviation += fabs(dev398) * wspinNiplus9ion;
	deviation += fabs(dev399) * wspinNiplus8ion;
	deviation += fabs(dev400) * wspinNiplus8exion;
	deviation += fabs(dev401) * wspinNiplus7ion;
	deviation += fabs(dev402) * wspinNiplus7exion;
	deviation += fabs(dev403) * wspinNiplus6ion;
	deviation += fabs(dev404) * wspinNiplus6exion;
	deviation += fabs(dev405) * wspinNiplus5ion;
	deviation += fabs(dev406) * wspinNiplus5exion;
	deviation += fabs(dev407) * wspinNiplus5ex2ion;
	deviation += fabs(dev408) * wspinNiplus4ion;
	deviation += fabs(dev409) * wspinNiplus4exion;
	deviation += fabs(dev410) * wspinNiplus4ex2ion;
	deviation += fabs(dev411) * wspinNiplus3ion;
	deviation += fabs(dev412) * wspinNiplus3exion;
	deviation += fabs(dev413) * wspinNiplus3ex2ion;
	deviation += fabs(dev414) * wspinNiplus2ion;
	deviation += fabs(dev415) * wspinNiplus2exion;
	deviation += fabs(dev416) * wspinNiplus2ex2ion;
	deviation += fabs(dev417) * wspinNiplus1ion;
	deviation += fabs(dev418) * wspinNiplus1exion;
	deviation += fabs(dev419) * wspinNineutrlion;
	deviation += fabs(dev420) * wspinNineutrlexion;
	deviation += fabs(dev421) * wspinNiplus9ion;
	deviation += fabs(dev422) * wspinNiplus8ion;
	deviation += fabs(dev423) * wspinNiplus7ion;
	deviation += fabs(dev424) * wspinNiplus6ion;
	deviation += fabs(dev425) * wspinNiplus5ion;
	deviation += fabs(dev426) * wspinNiplus4ion;
	deviation += fabs(dev427) * wspinNiplus3ion;
	deviation += fabs(dev428) * wspinNiplus2ion;
	deviation += fabs(dev429) * wspinNiplus1ion;
	deviation += fabs(dev430) * wspinNineutrlion;
	deviation += fabs(dev431) * wspinCuplus10ion;
	deviation += fabs(dev432) * wspinCuplus9ion;
	deviation += fabs(dev433) * wspinCuplus9exion;
	deviation += fabs(dev434) * wspinCuplus8ion;
	deviation += fabs(dev435) * wspinCuplus7ion;
	deviation += fabs(dev436) * wspinCuplus6ion;
	deviation += fabs(dev437) * wspinCuplus5ion;
	deviation += fabs(dev438) * wspinCuplus5exion;
	deviation += fabs(dev439) * wspinCuplus5ex2ion;
	deviation += fabs(dev440) * wspinCuplus4ion;
	deviation += fabs(dev441) * wspinCuplus4exion;
	deviation += fabs(dev442) * wspinCuplus4ex2ion;
	deviation += fabs(dev443) * wspinCuplus3ion;
	deviation += fabs(dev444) * wspinCuplus3exion;
	deviation += fabs(dev445) * wspinCuplus3ex2ion;
	deviation += fabs(dev446) * wspinCuplus2ion;
	deviation += fabs(dev447) * wspinCuplus2exion;
	deviation += fabs(dev448) * wspinCuplus1ion;
	deviation += fabs(dev449) * wspinCuplus1exion;
	deviation += fabs(dev450) * wspinCuneutrlion;
	deviation += fabs(dev451) * wspinCuneutrlexion;
	deviation += fabs(dev452) * wspinCuplus10ion;
	deviation += fabs(dev453) * wspinCuplus9ion;
	deviation += fabs(dev454) * wspinCuplus8ion;
	deviation += fabs(dev455) * wspinCuplus7ion;
	deviation += fabs(dev456) * wspinCuplus6ion;
	deviation += fabs(dev457) * wspinCuplus5ion;
	deviation += fabs(dev458) * wspinCuplus4ion;
	deviation += fabs(dev459) * wspinCuplus3ion;
	deviation += fabs(dev460) * wspinCuplus2ion;
	deviation += fabs(dev461) * wspinCuplus1ion;
	deviation += fabs(dev462) * wspinCuneutrlion;
	deviation += fabs(dev463) * wspinZnplus12ion;
	deviation += fabs(dev464) * wspinZnplus11ion;
	deviation += fabs(dev465) * wspinZnplus10exion;
	deviation += fabs(dev466) * wspinZnplus10ion;
	deviation += fabs(dev467) * wspinZnplus9ion;
	deviation += fabs(dev468) * wspinZnplus8ion;
	deviation += fabs(dev469) * wspinZnplus7ion;
	deviation += fabs(dev470) * wspinZnplus6exion;
	deviation += fabs(dev471) * wspinZnplus6ex2ion;
	deviation += fabs(dev472) * wspinZnplus6ion;
	deviation += fabs(dev473) * wspinZnplus5exion;
	deviation += fabs(dev474) * wspinZnplus5ex2ion;
	deviation += fabs(dev475) * wspinZnplus5ion;
	deviation += fabs(dev476) * wspinZnplus4exion;
	deviation += fabs(dev477) * wspinZnplus4ex2ion;
	deviation += fabs(dev478) * wspinZnplus4ion;
	deviation += fabs(dev479) * wspinZnplus3exion;
	deviation += fabs(dev480) * wspinZnplus3ion;
	deviation += fabs(dev481) * wspinZnplus2exion;
	deviation += fabs(dev482) * wspinZnplus1ion;
	deviation += fabs(dev483) * wspinZnplus1exion;
	deviation += fabs(dev484) * wspinZnplus1ion;
	deviation += fabs(dev485) * wspinZnneutrlexion;
	deviation += fabs(dev486) * wspinZnplus11ion;
	deviation += fabs(dev487) * wspinZnplus10ion;
	deviation += fabs(dev488) * wspinZnplus9ion;
	deviation += fabs(dev489) * wspinZnplus8ion;
	deviation += fabs(dev490) * wspinZnplus7ion;
	deviation += fabs(dev491) * wspinZnplus6ion;
	deviation += fabs(dev492) * wspinZnplus5ion;
	deviation += fabs(dev493) * wspinZnplus4ion;
	deviation += fabs(dev494) * wspinZnplus3ion;
	deviation += fabs(dev495) * wspinZnplus2ion;
	deviation += fabs(dev496) * wspinZnplus1ion;
	deviation += fabs(dev497) * wspinZnneutrlion;
	deviation += fabs(dev498) * wspinYplus2ion;
	deviation += fabs(dev499) * wspinYplus1ion;
	deviation += fabs(dev500) * wspinYplus1exion;
	deviation += fabs(dev501) * wspinYneutrlion;
	deviation += fabs(dev502) * wspinYneutrlexion;
	deviation += fabs(dev503) * wspinYplus2ion;
	deviation += fabs(dev504) * wspinYplus1ion;
	deviation += fabs(dev505) * wspinYneutrlion;
	deviation += fabs(dev506) * wspinZrplus3ion;
	deviation += fabs(dev507) * wspinZrplus2ion;
	deviation += fabs(dev508) * wspinZrplus2exion;
	deviation += fabs(dev509) * wspinZrplus1ion;
	deviation += fabs(dev510) * wspinZrplus1exion;
	deviation += fabs(dev511) * wspinZrneutrlion;
	deviation += fabs(dev512) * wspinZrneutrlexion;
	deviation += fabs(dev513) * wspinZrneutrlex2ion;
	deviation += fabs(dev514) * wspinZrplus3ion;
	deviation += fabs(dev515) * wspinZrplus2ion;
	deviation += fabs(dev516) * wspinZrplus1ion;
	deviation += fabs(dev517) * wspinZrneutrlion;
	deviation += fabs(dev518) * wspinNbplus4ion;
	deviation += fabs(dev519) * wspinNbplus3ion;
	deviation += fabs(dev520) * wspinNbplus3exion;
	deviation += fabs(dev521) * wspinNbplus2ion;
	deviation += fabs(dev522) * wspinNbplus2exion;
	deviation += fabs(dev523) * wspinNbplus1ion;
	deviation += fabs(dev524) * wspinNbplus1exion;
	deviation += fabs(dev525) * wspinNbplus1ex2ion;
	deviation += fabs(dev526) * wspinNbneutrlion;
	deviation += fabs(dev527) * wspinNbneutrlexion;
	deviation += fabs(dev528) * wspinNbneutrlex2ion;
	deviation += fabs(dev529) * wspinNbplus4ion;
	deviation += fabs(dev530) * wspinNbplus3ion;
	deviation += fabs(dev531) * wspinNbplus2ion;
	deviation += fabs(dev532) * wspinNbplus1ion;
	deviation += fabs(dev533) * wspinNbneutrlion;
	deviation += fabs(dev534) * wspinMoplus5ion;
	deviation += fabs(dev535) * wspinMoplus4ion;
	deviation += fabs(dev536) * wspinMoplus4exion;
	deviation += fabs(dev537) * wspinMoplus3ion;
	deviation += fabs(dev538) * wspinMoplus3exion;
	deviation += fabs(dev539) * wspinMoplus2ion;
	deviation += fabs(dev540) * wspinMoplus2exion;
	deviation += fabs(dev541) * wspinMoplus2ex2ion;
	deviation += fabs(dev542) * wspinMoplus1ion;
	deviation += fabs(dev543) * wspinMoplus1exion;
	deviation += fabs(dev544) * wspinMoplus1ex2ion;
	deviation += fabs(dev545) * wspinMoneutrlion;
	deviation += fabs(dev546) * wspinMoneutrlexion;
	deviation += fabs(dev547) * wspinMoneutrlex2ion;
	deviation += fabs(dev548) * wspinMoneutrlex3ion;
	deviation += fabs(dev549) * wspinMoplus5ion;
	deviation += fabs(dev550) * wspinMoplus4ion;
	deviation += fabs(dev551) * wspinMoplus3ion;
	deviation += fabs(dev552) * wspinMoplus2ion;
	deviation += fabs(dev553) * wspinMoplus1ion;
	deviation += fabs(dev554) * wspinMoneutrlion;
	deviation += fabs(dev555) * wspinTcplus6ion;
	deviation += fabs(dev556) * wspinTcplus5ion;
	deviation += fabs(dev557) * wspinTcplus4ion;
	deviation += fabs(dev558) * wspinTcplus3ion;
	deviation += fabs(dev559) * wspinTcplus2ion;
	deviation += fabs(dev560) * wspinTcplus1ion;
	deviation += fabs(dev561) * wspinTcplus1exion;
	deviation += fabs(dev562) * wspinTcneutrlion;
	deviation += fabs(dev563) * wspinTcneutrlexion;
	deviation += fabs(dev564) * wspinTcneutrlex2ion;
	deviation += fabs(dev565) * wspinTcneutrlex3ion;
	deviation += fabs(dev566) * wspinTcplus6ion;
	deviation += fabs(dev567) * wspinTcplus5ion;
	deviation += fabs(dev568) * wspinTcplus4ion;
	deviation += fabs(dev569) * wspinTcplus3ion;
	deviation += fabs(dev570) * wspinTcplus2ion;
	deviation += fabs(dev571) * wspinTcplus1ion;
	deviation += fabs(dev572) * wspinTcneutrlion;
	deviation += fabs(dev573) * wspinRuplus7ion;
	deviation += fabs(dev574) * wspinRuplus6ion;
	deviation += fabs(dev575) * wspinRuplus5ion;
	deviation += fabs(dev576) * wspinRuplus4ion;
	deviation += fabs(dev577) * wspinRuplus3ion;
	deviation += fabs(dev578) * wspinRuplus2ion;
	deviation += fabs(dev579) * wspinRuplus2exion;
	deviation += fabs(dev580) * wspinRuplus1ion;
	deviation += fabs(dev581) * wspinRuplus1exion;
	deviation += fabs(dev582) * wspinRuplus1ex2ion;
	deviation += fabs(dev583) * wspinRuneutrlion;
	deviation += fabs(dev584) * wspinRuneutrlexion;
	deviation += fabs(dev585) * wspinRuneutrlex2ion;
	deviation += fabs(dev586) * wspinRuplus7ion;
	deviation += fabs(dev587) * wspinRuplus6ion;
	deviation += fabs(dev588) * wspinRuplus5ion;
	deviation += fabs(dev589) * wspinRuplus4ion;
	deviation += fabs(dev590) * wspinRuplus3ion;
	deviation += fabs(dev591) * wspinRuplus2ion;
	deviation += fabs(dev592) * wspinRuplus1ion;
	deviation += fabs(dev593) * wspinRuneutrlion;
	deviation += fabs(dev594) * wspinRhplus8ion;
	deviation += fabs(dev595) * wspinRhplus7ion;
	deviation += fabs(dev596) * wspinRhplus6ion;
	deviation += fabs(dev597) * wspinRhplus5ion;
	deviation += fabs(dev598) * wspinRhplus4ion;
	deviation += fabs(dev599) * wspinRhplus3ion;
	deviation += fabs(dev600) * wspinRhplus2ion;
	deviation += fabs(dev601) * wspinRhplus2exion;
	deviation += fabs(dev602) * wspinRhplus2ex2ion;
	deviation += fabs(dev603) * wspinRhplus1ion;
	deviation += fabs(dev604) * wspinRhplus1exion;
	deviation += fabs(dev605) * wspinRhplus1ex2ion;
	deviation += fabs(dev606) * wspinRhneutrlion;
	deviation += fabs(dev607) * wspinRhneutrlexion;
	deviation += fabs(dev608) * wspinRhplus8ion;
	deviation += fabs(dev609) * wspinRhplus7ion;
	deviation += fabs(dev610) * wspinRhplus6ion;
	deviation += fabs(dev611) * wspinRhplus5ion;
	deviation += fabs(dev612) * wspinRhplus4ion;
	deviation += fabs(dev613) * wspinRhplus3ion;
	deviation += fabs(dev614) * wspinRhplus2ion;
	deviation += fabs(dev615) * wspinRhplus1ion;
	deviation += fabs(dev616) * wspinRhneutrlion;
	deviation += fabs(dev617) * wspinPdplus9ion;
	deviation += fabs(dev618) * wspinPdplus8ion;
	deviation += fabs(dev619) * wspinPdplus7ion;
	deviation += fabs(dev620) * wspinPdplus6ion;
	deviation += fabs(dev621) * wspinPdplus5ion;
	deviation += fabs(dev622) * wspinPdplus4ion;
	deviation += fabs(dev623) * wspinPdplus3ion;
	deviation += fabs(dev624) * wspinPdplus2ion;
	deviation += fabs(dev625) * wspinPdplus2exion;
	deviation += fabs(dev626) * wspinPdplus2ex2ion;
	deviation += fabs(dev627) * wspinPdplus1ion;
	deviation += fabs(dev628) * wspinPdplus1exion;
	deviation += fabs(dev629) * wspinPdneutrlion;
	deviation += fabs(dev630) * wspinPdneutrlexion;
	deviation += fabs(dev631) * wspinPdplus9ion;
	deviation += fabs(dev632) * wspinPdplus8ion;
	deviation += fabs(dev633) * wspinPdplus7ion;
	deviation += fabs(dev634) * wspinPdplus6ion;
	deviation += fabs(dev635) * wspinPdplus5ion;
	deviation += fabs(dev636) * wspinPdplus4ion;
	deviation += fabs(dev637) * wspinPdplus3ion;
	deviation += fabs(dev638) * wspinPdplus2ion;
	deviation += fabs(dev639) * wspinPdplus1ion;
	deviation += fabs(dev640) * wspinPdneutrlion;
	deviation += fabs(dev641) * wspinAgplus10ion;
	deviation += fabs(dev642) * wspinAgplus9ion;
	deviation += fabs(dev643) * wspinAgplus8ion;
	deviation += fabs(dev644) * wspinAgplus7ion;
	deviation += fabs(dev645) * wspinAgplus6ion;
	deviation += fabs(dev646) * wspinAgplus5ion;
	deviation += fabs(dev647) * wspinAgplus4ion;
	deviation += fabs(dev648) * wspinAgplus3ion;
	deviation += fabs(dev649) * wspinAgplus2ion;
	deviation += fabs(dev650) * wspinAgplus2exion;
	deviation += fabs(dev651) * wspinAgplus1ion;
	deviation += fabs(dev652) * wspinAgplus1exion;
	deviation += fabs(dev653) * wspinAgneutrlion;
	deviation += fabs(dev654) * wspinAgneutrlexion;
	deviation += fabs(dev655) * wspinAgplus10ion;
	deviation += fabs(dev656) * wspinAgplus9ion;
	deviation += fabs(dev657) * wspinAgplus8ion;
	deviation += fabs(dev658) * wspinAgplus7ion;
	deviation += fabs(dev659) * wspinAgplus6ion;
	deviation += fabs(dev660) * wspinAgplus5ion;
	deviation += fabs(dev661) * wspinAgplus4ion;
	deviation += fabs(dev662) * wspinAgplus3ion;
	deviation += fabs(dev663) * wspinAgplus2ion;
	deviation += fabs(dev664) * wspinAgplus1ion;
	deviation += fabs(dev665) * wspinAgneutrlion;
	deviation += fabs(dev666) * wspinCdplus11ion;
	deviation += fabs(dev667) * wspinCdplus10ion;
	deviation += fabs(dev668) * wspinCdplus9ion;
	deviation += fabs(dev669) * wspinCdplus8ion;
	deviation += fabs(dev670) * wspinCdplus7ion;
	deviation += fabs(dev671) * wspinCdplus6ion;
	deviation += fabs(dev672) * wspinCdplus5ion;
	deviation += fabs(dev673) * wspinCdplus4ion;
	deviation += fabs(dev674) * wspinCdplus3ion;
	deviation += fabs(dev675) * wspinCdplus3exion;
	deviation += fabs(dev676) * wspinCdplus2ion;
	deviation += fabs(dev677) * wspinCdplus2exion;
	deviation += fabs(dev678) * wspinCdplus1ion;
	deviation += fabs(dev679) * wspinCdplus1exion;
	deviation += fabs(dev680) * wspinCdneutrlion;
	deviation += fabs(dev681) * wspinCdneutrlexion;
	deviation += fabs(dev682) * wspinCdplus11ion;
	deviation += fabs(dev683) * wspinCdplus10ion;
	deviation += fabs(dev684) * wspinCdplus9ion;
	deviation += fabs(dev685) * wspinCdplus8ion;
	deviation += fabs(dev686) * wspinCdplus7ion;
	deviation += fabs(dev687) * wspinCdplus6ion;
	deviation += fabs(dev688) * wspinCdplus5ion;
	deviation += fabs(dev689) * wspinCdplus4ion;
	deviation += fabs(dev690) * wspinCdplus3ion;
	deviation += fabs(dev691) * wspinCdplus2ion;
	deviation += fabs(dev692) * wspinCdplus1ion;
	deviation += fabs(dev693) * wspinCdneutrlion;

	// summing thermo weights
//	wTotal += wspinHaff;
	wTotal += wspinOHaff;
	wTotal += wspinH2Oaff;
	wTotal += wspinO_2aff;
	wTotal += wspinH2dis;
	wTotal += wspinH2exdis;
	wTotal += wspinH2ion;
	wTotal += wspinH2aff;
//	wTotal += wspinH2plusdis;
	wTotal += wspinH2Odis;
	wTotal += wspinOeaff;
	wTotal += wspinO_1eaff;
	wTotal += wspinOneutrlion;
	wTotal += wspinOplus1ion;
	wTotal += wspinO2_2dis;
	wTotal += wspinO2_1dis;
	wTotal += wspinO2dis;
	wTotal += wspinOHdotaff;
	wTotal += wspinO_1aff;
	wTotal += wspinH2Odim;
	wTotal += wspinHeaff;
//	wTotal += wspinHeaff_trp;
	wTotal += wspinHion;
	wTotal += wspinOHdotdis;
	wTotal += wspinO2ex;
	wTotal += wspinO2ex2;
	wTotal += wspinOplus2ion;
	wTotal += wspinOplus3ion;
	wTotal += wspinOplus4ion;
	wTotal += wspinOplus5ion;
	wTotal += wspinOneutrlexion;
	wTotal += wspinOplus2ionex;
	wTotal += wspinOplus2ionex2;
	wTotal += wspinOplus1ionex;
	wTotal += wspinOplus4ionex;
	wTotal += wspinCplus3ion;
	wTotal += wspinCplus2ion;
	wTotal += wspinCplus1ion;
	wTotal += wspinCneutrlion;
	wTotal += wspinC_1ion;
	wTotal += wspinNplus4ion;
	wTotal += wspinNplus3ion;
	wTotal += wspinNplus2ion;
	wTotal += wspinNplus1ion;
	wTotal += wspinNneutrlion;
	wTotal += wspinN_1ion;
	wTotal += wspinSplus5ion;
	wTotal += wspinSplus4ion;
	wTotal += wspinSplus3ion;
	wTotal += wspinSplus2ion;
	wTotal += wspinSplus1ion;
	wTotal += wspinSneutrlion;
	wTotal += wspinS_1ion;
	wTotal += wspinPplus4ion;
	wTotal += wspinPplus3ion;
	wTotal += wspinPplus2ion;
	wTotal += wspinPplus1ion;
	wTotal += wspinPneutrlion;
	wTotal += wspinP_1ion;
	wTotal += wspinSiplus3ion;
	wTotal += wspinSiplus2ion;
	wTotal += wspinSiplus1ion;
	wTotal += wspinSineutrlion;
	wTotal += wspinSi_1ion;
	wTotal += wspinFplus6ion;
	wTotal += wspinFplus5ion;
	wTotal += wspinFplus4ion;
	wTotal += wspinFplus3ion;
	wTotal += wspinFplus2ion;
	wTotal += wspinFplus1ion;
	wTotal += wspinFneutrlion;
	wTotal += wspinF_1ion;
	wTotal += wspinCplus2exion;
	wTotal += wspinCplus1exion;
	wTotal += wspinCneutrlexion;
	wTotal += wspinCneutrlex2ion;
	wTotal += wspinNplus3exion;
	wTotal += wspinNplus2exion;
	wTotal += wspinNplus1exion;
	wTotal += wspinNplus1ex2ion;
	wTotal += wspinNneutrlexion;
	wTotal += wspinFplus5exion;
	wTotal += wspinFplus4exion;
	wTotal += wspinFplus3exion;
	wTotal += wspinFplus3ex2ion;
	wTotal += wspinFplus2exion;
	wTotal += wspinFplus1exion;
	wTotal += wspinSiplus2exion;
	wTotal += wspinSiplus1exion;
	wTotal += wspinSineutrlexion;
	wTotal += wspinSineutrlex2ion;
	wTotal += wspinPplus3exion;
	wTotal += wspinPplus2exion;
	wTotal += wspinPplus1exion;
	wTotal += wspinPplus1ex2ion;
	wTotal += wspinPneutrlexion;
	wTotal += wspinSplus4exion;
	wTotal += wspinSplus3exion;
	wTotal += wspinSplus2exion;
	wTotal += wspinSplus2ex2ion;
	wTotal += wspinSplus1exion;
	wTotal += wspinSneutrlexion;
	wTotal += wspinOneutrlex2ion;
	wTotal += wspinOplus1ex2ion;
	wTotal += wspinNneutrlex2ion;
	wTotal += wspinFneutrlexion;
	wTotal += wspinFplus1ex2ion;
	wTotal += wspinFplus2ex2ion;
	wTotal += wspinSneutrlex2ion;
	wTotal += wspinBplus2ion;
	wTotal += wspinBplus1ion;
	wTotal += wspinBneutrlion;
	wTotal += wspinB_1ion;
	wTotal += wspinBplus1exion;
	wTotal += wspinBneutrlexion;
	wTotal += wspinCl_1ion;
	wTotal += wspinClneutrlexion;
	wTotal += wspinClneutrlion;
	wTotal += wspinClplus1ex2ion;
	wTotal += wspinClplus1exion;
	wTotal += wspinClplus1ion;
	wTotal += wspinClplus2exion;
	wTotal += wspinClplus2ion;
	wTotal += wspinClplus3ex2ion;
	wTotal += wspinClplus3exion;
	wTotal += wspinClplus3ion;
	wTotal += wspinClplus4exion;
	wTotal += wspinClplus4ion;
	wTotal += wspinClplus5exion;
	wTotal += wspinClplus5ion;
	wTotal += wspinClplus6ion;
	wTotal += wspinAl_1ion;
	wTotal += wspinAlneutrlexion;
	wTotal += wspinAlneutrlion;
	wTotal += wspinAlplus1exion;
	wTotal += wspinAlplus1ion;
	wTotal += wspinAlplus2ion;
	wTotal += wspinLi_1ion;
	wTotal += wspinLineutrlion;
	wTotal += wspinBeneutrlion;
	wTotal += wspinBeneutrlexion;
	wTotal += wspinBeplus1ion;
	wTotal += wspinNa_1ion;
	wTotal += wspinNaneutrlion;
	wTotal += wspinMgneutrlion;
	wTotal += wspinMgneutrlexion;
	wTotal += wspinMgplus1ion;
	wTotal += wspinH3lin;
	wTotal += wspinH4squ;
	wTotal += wspinH4lin;
	wTotal += wspinScplus2ion;
	wTotal += wspinScplus1ion;
	wTotal += wspinScplus1exion;
	wTotal += wspinScneutrlion;
	wTotal += wspinScneutrlexion;
	wTotal += wspinTiplus3ion;
	wTotal += wspinTiplus2ion;
	wTotal += wspinTiplus2exion;
	wTotal += wspinTiplus1ion;
	wTotal += wspinTiplus1exion;
	wTotal += wspinTineutrlion;
	wTotal += wspinTineutrlexion;
	wTotal += wspinTineutrlex2ion;
	wTotal += wspinVplus4ion;
	wTotal += wspinVplus3ion;
	wTotal += wspinVplus3exion;
	wTotal += wspinVplus2ion;
	wTotal += wspinVplus2exion;
	wTotal += wspinVplus1ion;
	wTotal += wspinVplus1exion;
	wTotal += wspinVplus1ex2ion;
	wTotal += wspinVneutrlion;
	wTotal += wspinVneutrlexion;
	wTotal += wspinVneutrlex2ion;
	wTotal += wspinCrplus5ion;
	wTotal += wspinCrplus4ion;
	wTotal += wspinCrplus4exion;
	wTotal += wspinCrplus3ion;
	wTotal += wspinCrplus3exion;
	wTotal += wspinCrplus2ion;
	wTotal += wspinCrplus2exion;
	wTotal += wspinCrplus2ex2ion;
	wTotal += wspinCrplus1ion;
	wTotal += wspinCrplus1exion;
	wTotal += wspinCrplus1ex2ion;
	wTotal += wspinCrneutrlion;
	wTotal += wspinCrneutrlexion;
	wTotal += wspinCrneutrlex2ion;
	wTotal += wspinCrneutrlex3ion;
	wTotal += wspinMnplus6ion;
	wTotal += wspinMnplus5ion;
	wTotal += wspinMnplus5exion;
	wTotal += wspinMnplus4ion;
	wTotal += wspinMnplus4exion;
	wTotal += wspinMnplus3ion;
	wTotal += wspinMnplus3exion;
	wTotal += wspinMnplus2ion;
	wTotal += wspinMnplus2exion;
	wTotal += wspinMnplus2ex2ion;
	wTotal += wspinMnplus1ion;
	wTotal += wspinMnplus1exion;
	wTotal += wspinMnplus1ex2ion;
	wTotal += wspinMnplus1ex3ion;
	wTotal += wspinMnneutrlion;
	wTotal += wspinMnneutrlexion;
	wTotal += wspinMnneutrlex2ion;
	wTotal += wspinMnneutrlex3ion;
	wTotal += wspinFeplus7ion;
	wTotal += wspinFeplus6ion;
	wTotal += wspinFeplus6exion;
	wTotal += wspinFeplus5ion;
	wTotal += wspinFeplus5exion;
	wTotal += wspinFeplus4ion;
	wTotal += wspinFeplus4exion;
	wTotal += wspinFeplus4ex2ion;
	wTotal += wspinFeplus3ion;
	wTotal += wspinFeplus3exion;
	wTotal += wspinFeplus3ex2ion;
	wTotal += wspinFeplus2ion;
	wTotal += wspinFeplus2exion;
	wTotal += wspinFeplus2ex2ion;
	wTotal += wspinFeplus1ion;
	wTotal += wspinFeplus1exion;
	wTotal += wspinFeplus1ex2ion;
	wTotal += wspinFeneutrlion;
	wTotal += wspinFeneutrlexion;
	wTotal += wspinFeneutrlex2ion;
	wTotal += wspinFeneutrlex3ion;
	wTotal += wspinCoplus8ion;
	wTotal += wspinCoplus7ion;
	wTotal += wspinCoplus7exion;
	wTotal += wspinCoplus6ion;
	wTotal += wspinCoplus6exion;
	wTotal += wspinCoplus5ion;
	wTotal += wspinCoplus5exion;
	wTotal += wspinCoplus5ex2ion;
	wTotal += wspinCoplus4ion;
	wTotal += wspinCoplus4exion;
	wTotal += wspinCoplus4ex2ion;
	wTotal += wspinCoplus3ion;
	wTotal += wspinCoplus3exion;
	wTotal += wspinCoplus3ex2ion;
	wTotal += wspinCoplus2ion;
	wTotal += wspinCoplus2exion;
	wTotal += wspinCoplus2ex2ion;
	wTotal += wspinCoplus1ion;
	wTotal += wspinCoplus1exion;
	wTotal += wspinCoplus1ex2ion;
	wTotal += wspinConeutrlion;
	wTotal += wspinConeutrlexion;
	wTotal += wspinNiplus9ion;
	wTotal += wspinNiplus8ion;
	wTotal += wspinNiplus8exion;
	wTotal += wspinNiplus7ion;
	wTotal += wspinNiplus7exion;
	wTotal += wspinNiplus6ion;
	wTotal += wspinNiplus6exion;
	wTotal += wspinNiplus5ion;
	wTotal += wspinNiplus5exion;
	wTotal += wspinNiplus5ex2ion;
	wTotal += wspinNiplus4ion;
	wTotal += wspinNiplus4exion;
	wTotal += wspinNiplus4ex2ion;
	wTotal += wspinNiplus3ion;
	wTotal += wspinNiplus3exion;
	wTotal += wspinNiplus3ex2ion;
	wTotal += wspinNiplus2ion;
	wTotal += wspinNiplus2exion;
	wTotal += wspinNiplus2ex2ion;
	wTotal += wspinNiplus1ion;
	wTotal += wspinNiplus1exion;
	wTotal += wspinNineutrlion;
	wTotal += wspinNineutrlexion;
	wTotal += wspinCuplus10ion;
	wTotal += wspinCuplus9ion;
	wTotal += wspinCuplus9exion;
	wTotal += wspinCuplus8ion;
	wTotal += wspinCuplus7ion;
	wTotal += wspinCuplus6ion;
	wTotal += wspinCuplus5ion;
	wTotal += wspinCuplus5exion;
	wTotal += wspinCuplus5ex2ion;
	wTotal += wspinCuplus4ion;
	wTotal += wspinCuplus4exion;
	wTotal += wspinCuplus4ex2ion;
	wTotal += wspinCuplus3ion;
	wTotal += wspinCuplus3exion;
	wTotal += wspinCuplus3ex2ion;
	wTotal += wspinCuplus2ion;
	wTotal += wspinCuplus2exion;
	wTotal += wspinCuplus1ion;
	wTotal += wspinCuplus1exion;
	wTotal += wspinCuneutrlion;
	wTotal += wspinCuneutrlexion;
	wTotal += wspinZnplus11ion;
	wTotal += wspinZnplus10ion;
	wTotal += wspinZnplus10exion;
	wTotal += wspinZnplus9ion;
	wTotal += wspinZnplus8ion;
	wTotal += wspinZnplus7ion;
	wTotal += wspinZnplus6ion;
	wTotal += wspinZnplus6exion;
	wTotal += wspinZnplus6ex2ion;
	wTotal += wspinZnplus5ion;
	wTotal += wspinZnplus5exion;
	wTotal += wspinZnplus5ex2ion;
	wTotal += wspinZnplus4ion;
	wTotal += wspinZnplus4exion;
	wTotal += wspinZnplus4ex2ion;
	wTotal += wspinZnplus3ion;
	wTotal += wspinZnplus3exion;
	wTotal += wspinZnplus2ion;
	wTotal += wspinZnplus2exion;
	wTotal += wspinZnplus1ion;
	wTotal += wspinZnplus1exion;
	wTotal += wspinZnneutrlion;
	wTotal += wspinZnneutrlexion;
	wTotal += wspinYplus2ion;
	wTotal += wspinYplus1ion;
	wTotal += wspinYplus1exion;
	wTotal += wspinYneutrlion;
	wTotal += wspinYneutrlexion;
	wTotal += wspinZrplus3ion;
	wTotal += wspinZrplus2ion;
	wTotal += wspinZrplus2exion;
	wTotal += wspinZrplus1ion;
	wTotal += wspinZrplus1exion;
	wTotal += wspinZrneutrlion;
	wTotal += wspinZrneutrlexion;
	wTotal += wspinZrneutrlex2ion;
	wTotal += wspinNbplus4ion;
	wTotal += wspinNbplus3ion;
	wTotal += wspinNbplus3exion;
	wTotal += wspinNbplus2ion;
	wTotal += wspinNbplus2exion;
	wTotal += wspinNbplus1ion;
	wTotal += wspinNbplus1exion;
	wTotal += wspinNbplus1ex2ion;
	wTotal += wspinNbneutrlion;
	wTotal += wspinNbneutrlexion;
	wTotal += wspinNbneutrlex2ion;
	wTotal += wspinMoplus5ion;
	wTotal += wspinMoplus4ion;
	wTotal += wspinMoplus4exion;
	wTotal += wspinMoplus3ion;
	wTotal += wspinMoplus3exion;
	wTotal += wspinMoplus2ion;
	wTotal += wspinMoplus2exion;
	wTotal += wspinMoplus2ex2ion;
	wTotal += wspinMoplus1ion;
	wTotal += wspinMoplus1exion;
	wTotal += wspinMoplus1ex2ion;
	wTotal += wspinMoneutrlion;
	wTotal += wspinMoneutrlexion;
	wTotal += wspinMoneutrlex2ion;
	wTotal += wspinMoneutrlex3ion;
	wTotal += wspinTcplus6ion;
	wTotal += wspinTcplus5ion;
	wTotal += wspinTcplus4ion;
	wTotal += wspinTcplus3ion;
	wTotal += wspinTcplus2ion;
	wTotal += wspinTcplus1ion;
	wTotal += wspinTcplus1exion;
	wTotal += wspinTcneutrlion;
	wTotal += wspinTcneutrlexion;
	wTotal += wspinTcneutrlex2ion;
	wTotal += wspinTcneutrlex3ion;
	wTotal += wspinRuplus7ion;
	wTotal += wspinRuplus6ion;
	wTotal += wspinRuplus5ion;
	wTotal += wspinRuplus4ion;
	wTotal += wspinRuplus3ion;
	wTotal += wspinRuplus2ion;
	wTotal += wspinRuplus2exion;
	wTotal += wspinRuplus1ion;
	wTotal += wspinRuplus1exion;
	wTotal += wspinRuplus1ex2ion;
	wTotal += wspinRuneutrlion;
	wTotal += wspinRuneutrlexion;
	wTotal += wspinRuneutrlex2ion;
	wTotal += wspinRhplus8ion;
	wTotal += wspinRhplus7ion;
	wTotal += wspinRhplus6ion;
	wTotal += wspinRhplus5ion;
	wTotal += wspinRhplus4ion;
	wTotal += wspinRhplus3ion;
	wTotal += wspinRhplus2ion;
	wTotal += wspinRhplus2exion;
	wTotal += wspinRhplus2ex2ion;
	wTotal += wspinRhplus1ion;
	wTotal += wspinRhplus1exion;
	wTotal += wspinRhplus1ex2ion;
	wTotal += wspinRhneutrlion;
	wTotal += wspinRhneutrlexion;
	wTotal += wspinPdplus9ion;
	wTotal += wspinPdplus8ion;
	wTotal += wspinPdplus7ion;
	wTotal += wspinPdplus6ion;
	wTotal += wspinPdplus5ion;
	wTotal += wspinPdplus4ion;
	wTotal += wspinPdplus3ion;
	wTotal += wspinPdplus2ion;
	wTotal += wspinPdplus2exion;
	wTotal += wspinPdplus2ex2ion;
	wTotal += wspinPdplus1ion;
	wTotal += wspinPdplus1exion;
	wTotal += wspinPdneutrlion;
	wTotal += wspinPdneutrlexion;
	wTotal += wspinAgplus10ion;
	wTotal += wspinAgplus9ion;
	wTotal += wspinAgplus8ion;
	wTotal += wspinAgplus7ion;
	wTotal += wspinAgplus6ion;
	wTotal += wspinAgplus5ion;
	wTotal += wspinAgplus4ion;
	wTotal += wspinAgplus3ion;
	wTotal += wspinAgplus2ion;
	wTotal += wspinAgplus2exion;
	wTotal += wspinAgplus1ion;
	wTotal += wspinAgplus1exion;
	wTotal += wspinAgneutrlion;
	wTotal += wspinAgneutrlexion;
	wTotal += wspinCdplus11ion;
	wTotal += wspinCdplus10ion;
	wTotal += wspinCdplus9ion;
	wTotal += wspinCdplus8ion;
	wTotal += wspinCdplus7ion;
	wTotal += wspinCdplus6ion;
	wTotal += wspinCdplus5ion;
	wTotal += wspinCdplus4ion;
	wTotal += wspinCdplus3ion;
	wTotal += wspinCdplus3exion;
	wTotal += wspinCdplus2ion;
	wTotal += wspinCdplus2exion;
	wTotal += wspinCdplus1ion;
	wTotal += wspinCdplus1exion;
	wTotal += wspinCdneutrlion;
	wTotal += wspinCdneutrlexion;
	
//	printf("total deviation %f\n",deviation);
//	printf("total weight %f\n",wTotal);

	//Carbon sign mismatch counter calculation
	prod[0]= LitThermo43 * thermo43;
	prod[1]= LitThermo44 * thermo44;
	prod[2]= LitThermo45 * thermo45;
	prod[3]= LitThermo46 * thermo46;
	prod[4]= LitThermo47 * thermo47;
	prod[5]= LitThermo126* thermo126;
	prod[6]= LitThermo127* thermo127;
	prod[7]= LitThermo128* thermo128;
	prod[8]= LitThermo129* thermo129;
        prod[9]= (thermo227-LitThermo227)*FIT_diat;

	for (i=0; i<10; i++){
		if (prod[i]<0)
			Ccounter++;
		prod[i]=0;
	}

	wTotal += wspinCsign;
	deviation += ((double) Ccounter/0.01)*wspinCsign;

	//Oxygen sign mismatch counter calculation
	prod[0]= LitThermo22 * thermo22;
	prod[1]= LitThermo23 * thermo23;
	prod[2]= LitThermo24 * thermo24;
	prod[3]= LitThermo25 * thermo25;
	prod[4]= LitThermo26 * thermo26;
	prod[5]= LitThermo27 * thermo27;
	prod[6]= LitThermo28 * thermo28;
	prod[7]= LitThermo39 * thermo39;
	prod[8]= LitThermo156* thermo156;
	prod[9]= LitThermo41 * thermo41; 
	prod[10]= LitThermo157* thermo157;
	prod[11]= LitThermo40 * thermo40; 
	prod[12]= LitThermo122* thermo122;
	prod[13]= LitThermo30 * thermo30; 
	prod[14]= LitThermo42 * thermo42;
	prod[15]= LitThermo163* thermo163;
	prod[16] = (-thermo24)- thermo157;//O+1 to O+2 ionization should be greater than O+1 second excitation otherwise second ex is not stable
	prod[17] = thermo157 - thermo41;
	prod[18] = thermo122 - thermo40;
//	prod[16]= LitThermo29 * thermo29;//O2 dia - para
//	prod[20]= thermo251 * LitThermo251;

	prod[19]= thermo29 - LitThermo29;
	prod[21]= thermo252;
	prod[22]= 10 - fabs(thermo238);
	prod[23]= 10 - fabs(thermo239);
	prod[24]= 10 - fabs(thermo240);
	prod[25]= 10 - fabs(thermo241);
	prod[26]= 10 - fabs(thermo242);
	prod[27]= 10 - fabs(thermo243);
//	prod[28]= thermo711 - LitThermo711; // O3trp - O3
//	prod[29]= LitThermo253* thermo253;
//	prod[30]= LitThermo254* thermo254;

        for (i=0; i<28; i++){ //O2 energy conversion
		if (prod[i]<0){
//			if (i==0){ 
//				deviation += wspinOsign*100*wspinOeaff;
//				wTotal += wspinOsign*wspinOeaff;
//			}
//			else if (i==1){
//				deviation += wspinOsign*100*wspinOneutrlion;
//				wTotal += wspinOsign*wspinOneutrlion;
//			}
//			else if (i==2){
//				deviation += wspinOsign*100*wspinOplus1ion;
//				wTotal += wspinOsign*wspinOplus1ion;
//			}
//			else if (i==3){
//				deviation += wspinOsign*100*wspinOplus2ion;
//				wTotal += wspinOsign*wspinOplus2ion;
//			}
//			else if (i==4){
//				deviation += wspinOsign*100*wspinOplus3ion;
//				wTotal += wspinOsign*wspinOplus3ion;
//			}
//			else if (i==5){
//				deviation += wspinOsign*100*wspinOplus4ion;
//				wTotal += wspinOsign*wspinOplus4ion;
//			}
//			else if (i==6){
//				deviation += wspinOsign*100*wspinOplus5ion;
//				wTotal += wspinOsign*wspinOplus5ion;
//			}
//			else if (i==7){
//				deviation += wspinOsign*100*wspinOneutrlexion;
//				wTotal += wspinOsign*wspinOneutrlexion;
//			}
//			else if (i==8){
//				deviation += wspinOsign*100*wspinOneutrlex2ion;
//				wTotal += wspinOsign*wspinOneutrlex2ion;
//			}
//			else if (i==9){
//				deviation += wspinOsign*100*wspinOplus1ionex;
//				wTotal += wspinOsign*wspinOplus1ionex;
//			}
//			else if (i==10){
//				deviation += wspinOsign*100*wspinOplus1ex2ion;
//				wTotal += wspinOsign*wspinOplus1ex2ion;
//			}
//			else if (i==11){
//				deviation += wspinOsign*100*wspinOplus2ionex;
//				wTotal += wspinOsign*wspinOplus2ionex;
//			}
//			else if (i==12){
//				deviation += wspinOsign*100*wspinOplus2ionex;
//				wTotal += wspinOsign*wspinOplus2ionex;
//			}
//			else if (i==13){
//				deviation += wspinOsign*100*wspinOplus3ionex;
//				wTotal += wspinOsign*wspinOplus3ionex;
//			}
//			else if (i==14){
//				deviation += wspinOsign*100*wspinOplus4ionex;
//				wTotal += wspinOsign*wspinOplus4ionex;
//			}
//			else if (i==15){
//				deviation += wspinOsign*100*wspinOneutrlex2ion;
//				wTotal += wspinOsign*wspinOneutrlex2ion;
//			}
//			else if (i==16){
//				deviation += wspinOsign*100*wspinOplus1ion;
//				wTotal += wspinOsign*wspinOplus1ion;
//			}
//			else if (i==17){
//				deviation += wspinOsign*100*wspinOplus1ex2ion;
//				wTotal += wspinOsign*wspinOplus1ex2ion;
//			}
//			else if (i==18){
//				deviation += wspinOsign*100*wspinOplus2ionex2;
//				wTotal += wspinOsign*wspinOplus2ionex2;
//			}
//			else if (i==19){
//				deviation += wspinOsign*100*wspinO2ex;
//				wTotal += wspinOsign*wspinO2ex;
//			}
//			else if (i==20){
//				deviation += wspinOsign*100*wspinO2ex2;
//				wTotal += wspinOsign*wspinO2ex2;
//			}
//			else if (i==21){
//				deviation += wspinOsign*100*wspinO2ex2;
//				wTotal += wspinOsign*wspinO2ex2;
//			}
//			else if (i==22){
//				deviation += wspinOsign*100*wspinO2_snglbnd;
//				wTotal += wspinOsign*wspinO2_snglbnd;
//			}
//			else if (i==23){
//				deviation += wspinOsign*100*wspinO2_dblbnd;
//				wTotal += wspinOsign*wspinO2_dblbnd;
//			}
//			else if (i==24){
//				deviation += wspinOsign*100*wspinO2_trplbnd;
//				wTotal += wspinOsign*wspinO2_trplbnd;    
//			}
//			else if (i==25){
//				deviation += wspinOsign*100*wspinO2dia_snglbnd;
//				wTotal += wspinOsign*wspinO2dia_snglbnd;
//			}
//			else if (i==26){
//				deviation += wspinOsign*100*wspinO2dia_dblbnd;
//				wTotal += wspinOsign*wspinO2dia_dblbnd;  	
//			}
//			else if (i==27){
//				deviation += wspinOsign*100*wspinO2dia_trplbnd;
//				wTotal += wspinOsign*wspinO2dia_trplbnd; 	
//			}
				Ocounter++;
//			printf("%d sign is wrong\n", i);
		}	
		prod[i]=0;
	}

	wTotal += wspinOsign; // 0 sign error terms for O 
        deviation += (Ocounter/0.01)*wspinOsign;
                                      
        //Fluorine sign mismatch counter calculation
	prod[0]= LitThermo72 * thermo72;
        prod[1]= LitThermo73 * thermo73;
        prod[2]= LitThermo74 * thermo74;
	prod[3]= LitThermo75 * thermo75;
	prod[4]= LitThermo76 * thermo76;
	prod[5]= LitThermo77 * thermo77;
	prod[6]= LitThermo78 * thermo78;
	prod[7]= LitThermo79 * thermo79;
	prod[8]= LitThermo135* thermo135;
	prod[9]= LitThermo136* thermo136;
	prod[10]= LitThermo137* thermo137;
	prod[11]= LitThermo138* thermo138;
	prod[12]= LitThermo139* thermo139;
	prod[13]= LitThermo161* thermo161;
	prod[14]= LitThermo140* thermo140;
	prod[15]= LitThermo160* thermo160;
	prod[16]= LitThermo159* thermo159;
        prod[17]= ((-thermo76)-thermo161);
        prod[18]= (thermo232 - LitThermo232)*FIT_diat;
//	printf("F2+ ionization minus F2+ 2nd ex is %f\n",prod[18]);
	for (i=0; i<19; i++){
		if (prod[i]<0)
			Fcounter++;
		prod[i]=0;
	}

	wTotal += wspinFsign;
	deviation += (Fcounter/0.01)*wspinFsign;

	//Sulfur sign mismatch counter calculation
	prod[0]= LitThermo54 * thermo54;
	prod[1]= LitThermo55 * thermo55;
	prod[2]= LitThermo56 * thermo56;
	prod[3]= LitThermo57 * thermo57;
	prod[4]= LitThermo58 * thermo58;
	prod[5]= LitThermo59 * thermo59;
	prod[6]= LitThermo60 * thermo60;
	prod[7]= LitThermo150* thermo150;
	prod[8]= LitThermo151* thermo151;
	prod[9]= LitThermo152* thermo152;
	prod[10]= LitThermo153* thermo153;
	prod[11]= LitThermo154* thermo154;
	prod[12]= LitThermo155* thermo155;
	prod[13]= LitThermo162* thermo162;
	prod[14]= thermo162 - thermo155;
        prod[15]= (thermo231 - LitThermo231)*FIT_diat;

	for (i=0; i<16; i++){
		if (prod[i]<0)
			Scounter++;
		prod[i]=0;
	}

	wTotal += wspinSsign;
	deviation += (Scounter/0.01)*wspinSsign;

	//Phosphorus sign mismatch counter calculation
	prod[0]= LitThermo61 * thermo61;
	prod[1]= LitThermo62 * thermo62;
	prod[2]= LitThermo63 * thermo63;
	prod[3]= LitThermo64 * thermo64;
	prod[4]= LitThermo65 * thermo65;
	prod[5]= LitThermo66 * thermo66;
	prod[6]= LitThermo145* thermo145;
	prod[7]= LitThermo146* thermo146;
	prod[8]= LitThermo147* thermo147;
	prod[9]= LitThermo148* thermo148;
	prod[10]= LitThermo149* thermo149;
        prod[11]= (thermo230-LitThermo230)*FIT_diat;

	for (i=0; i<12; i++){
		if (prod[i]<0)
			Pcounter++;
		prod[i]=0;
	}

	wTotal += wspinPsign;
	deviation += (Pcounter/0.01)*wspinPsign;

	//Nitrogen sign mismatch counter calculation
	prod[0]= LitThermo48 * thermo48;
	prod[1]= LitThermo49 * thermo49;
	prod[2]= LitThermo50 * thermo50;
	prod[3]= LitThermo51 * thermo51;
	prod[4]= LitThermo52 * thermo52;
	prod[5]= LitThermo130* thermo130;
	prod[6]= LitThermo131* thermo131;
	prod[7]= LitThermo132* thermo132;
	prod[8]= LitThermo133* thermo133;
	prod[9]= LitThermo134* thermo134;
	prod[10]= LitThermo158* thermo158;
        prod[11]= (thermo229-LitThermo229)*FIT_diat;

	for (i=0; i<12; i++){
		if (prod[i]<0)
			Ncounter++;
		prod[i]=0;
	}

	wTotal += wspinNsign;
	deviation += (Ncounter/0.01)*wspinNsign;

	//Chlorine sign mismatch counter calculation
	prod[0]= LitThermo189 * thermo189;
	prod[1]= LitThermo188 * thermo188;
	prod[2]= LitThermo187 * thermo187;
	prod[3]= LitThermo186 * thermo186;
	prod[4]= LitThermo185 * thermo185;
	prod[5]= LitThermo184 * thermo184;
	prod[6]= LitThermo183 * thermo183;
	prod[7]= LitThermo182 * thermo182;
	prod[8]= LitThermo181* thermo181;
	prod[9]= LitThermo180* thermo180;
	prod[10]= LitThermo179* thermo179;
	prod[11]= LitThermo178* thermo178;
	prod[12]= LitThermo177* thermo177;
	prod[13]= LitThermo176* thermo176;
	prod[14]= LitThermo175* thermo175;
	prod[15]= LitThermo174* thermo174;
        prod[16]= (thermo233-LitThermo233)*FIT_diat;

	for (i=0; i<17; i++){
		if (prod[i]<0)
			Clcounter++;
		prod[i]=0;
	}

	wTotal += wspinClsign;
	deviation += (Clcounter/0.01)*wspinClsign;

	//Silicon sign mismatch counter calculation
	prod[0]= LitThermo67 * thermo67;
	prod[1]= LitThermo68 * thermo68;
	prod[2]= LitThermo69 * thermo69;
	prod[3]= LitThermo70 * thermo70;
	prod[4]= LitThermo71 * thermo71;
	prod[5]= LitThermo141 * thermo141;
	prod[6]= LitThermo142 * thermo142;
	prod[7]= LitThermo143 * thermo143;
	prod[8]= LitThermo144 * thermo144;
        prod[9]= (thermo228 - LitThermo228)*FIT_diat;

	for (i=0; i<10; i++){
		if (prod[i]<0)
			Sicounter++;
		prod[i]=0;
	}

	wTotal += wspinSisign;
	deviation += (Sicounter/0.01)*wspinSisign;

	//Aluminium sign mismatch counter calculation
	prod[0]= LitThermo195 * thermo195;
	prod[1]= LitThermo194 * thermo194;
	prod[2]= LitThermo192 * thermo192;
	prod[3]= LitThermo190 * thermo190;
	prod[4]= LitThermo193 * thermo193;
	prod[5]= LitThermo191 * thermo191;
	prod[6]= (thermo225 - LitThermo225)*FIT_diat;

	for (i=0; i<7; i++){
		if (prod[i]<0)
			Alcounter++;
		prod[i]=0;
	}

	wTotal += wspinAlsign;
	deviation += (Alcounter/0.01)*wspinAlsign;

	//Boron sign mismatch counter calculation
	prod[0]= LitThermo164 * thermo164;
	prod[1]= LitThermo165 * thermo165;
	prod[2]= LitThermo166 * thermo166;
	prod[3]= LitThermo167 * thermo167;
	prod[4]= LitThermo168 * thermo168;
	prod[5]= LitThermo169 * thermo169;
        prod[6]= (thermo226 - LitThermo226)*FIT_diat;

	for (i=0; i<7; i++){
		if (prod[i]<0)
			Bcounter++;
		prod[i]=0;
	}

	wTotal += wspinBsign;
	deviation += (Bcounter/0.01)*wspinBsign;

	//H sign mismatch
//	prod[0]= thermo208;
//	prod[1]= thermo209;
	prod[2]= thermo210;
	prod[3]= thermo211;
	prod[4]= LitThermo1 * thermo1;
	prod[5]= thermo224;
//	prod[6]= thermo234;
//	prod[7]= thermo235;
//	prod[8]= thermo236;
	prod[9]= LitThermo244 * thermo244;
//	prod[10]=LitThermo245 * thermo245;
//	prod[11]=LitThermo246 * thermo246;
//	prod[12]=LitThermo247 * thermo247;
//	prod[13]=LitThermo248 * thermo248;
	for (i=0; i<14; i++){
		if (prod[i]<0)
			Hcounter++;
		prod[i]=0;
	}

	wTotal += wspinHsign;
	deviation += (Hcounter/0.01)*wspinHsign;

	//Sc sign			
	prod[0] = LitThermo256 * thermo256;
	prod[1] = LitThermo257 * thermo257;
	prod[2] = LitThermo258 * thermo258;
	prod[3] = LitThermo259 * thermo259;
	prod[4] = LitThermo260 * thermo260;
	prod[5] = LitThermo261 * thermo261;
	prod[6] = LitThermo262 * thermo262;
	prod[7] = LitThermo263 * thermo263;
	for (i=0; i<8; i++){
		if (prod[i]<0)
			Sccounter++;
		prod[i]=0;
	}
	wTotal += wspinScsign;
	deviation += (Sccounter/0.01)*wspinScsign;

	//Ti sign			
	prod[0] = LitThermo264 * thermo264;
	prod[1] = LitThermo265 * thermo265;
	prod[2] = LitThermo266 * thermo266;
	prod[3] = LitThermo267 * thermo267;
	prod[4] = LitThermo268 * thermo268;
	prod[5] = LitThermo269 * thermo269;
	prod[6] = LitThermo270 * thermo270;
	prod[7] = LitThermo271 * thermo271;
	prod[8] = LitThermo272 * thermo272;
	prod[9] = LitThermo273 * thermo273;
	prod[10] = LitThermo274 * thermo274;
	prod[11] = LitThermo275 * thermo275;
	for (i=0; i<12; i++){
		if (prod[i]<0)
			Ticounter++;
		prod[i]=0;
	}
	wTotal += wspinTisign;
	deviation += (Ticounter/0.01)*wspinTisign;

	//V sign			
	prod[0] = LitThermo276 * thermo276;
	prod[1] = LitThermo277 * thermo277;
	prod[2] = LitThermo278 * thermo278;
	prod[3] = LitThermo279 * thermo279;
	prod[4] = LitThermo280 * thermo280;
	prod[5] = LitThermo281 * thermo281;
	prod[6] = LitThermo282 * thermo282;
	prod[7] = LitThermo283 * thermo283;
	prod[8] = LitThermo284 * thermo284;
	prod[9] = LitThermo285 * thermo285;
	prod[10] = LitThermo286 * thermo286;
	prod[11] = LitThermo287 * thermo287;
	prod[12] = LitThermo288 * thermo288;
	prod[13] = LitThermo289 * thermo289;
	prod[14] = LitThermo290 * thermo290;
	prod[15] = LitThermo291 * thermo291;
	for (i=0; i<16; i++){
		if (prod[i]<0)
			Vcounter++;
		prod[i]=0;
	}
	wTotal += wspinVsign;
	deviation += (Vcounter/0.01)*wspinVsign;

	//Cr sign			
	prod[0] = LitThermo292 * thermo292;
	prod[1] = LitThermo293 * thermo293;
	prod[2] = LitThermo294 * thermo294;
	prod[3] = LitThermo295 * thermo295;
	prod[4] = LitThermo296 * thermo296;
	prod[5] = LitThermo297 * thermo297;
	prod[6] = LitThermo298 * thermo298;
	prod[7] = LitThermo299 * thermo299;
	prod[8] = LitThermo300 * thermo300;
	prod[9] = LitThermo301 * thermo301;
	prod[10] = LitThermo302 * thermo302;
	prod[11] = LitThermo303 * thermo303;
	prod[12] = LitThermo304 * thermo304;
	prod[13] = LitThermo305 * thermo305;
	prod[14] = LitThermo306 * thermo306;
	prod[15] = LitThermo307 * thermo307;
	prod[16] = LitThermo308 * thermo308;
	prod[17] = LitThermo309 * thermo309;
	prod[18] = LitThermo310 * thermo310;
	prod[19] = LitThermo311 * thermo311;
	prod[20] = LitThermo312 * thermo312;
	for (i=0; i<21; i++){
		if (prod[i]<0)
			Crcounter++;
		prod[i]=0;
	}
	wTotal += wspinCrsign;
	deviation += (Crcounter/0.01)*wspinCrsign;

	//Mn sign			
	prod[0] = LitThermo313 * thermo313;
	prod[1] = LitThermo314 * thermo314;
	prod[2] = LitThermo315 * thermo315;
	prod[3] = LitThermo316 * thermo316;
	prod[4] = LitThermo317 * thermo317;
	prod[5] = LitThermo318 * thermo318;
	prod[6] = LitThermo319 * thermo319;
	prod[7] = LitThermo320 * thermo320;
	prod[8] = LitThermo321 * thermo321;
	prod[9] = LitThermo322 * thermo322;
	prod[10] = LitThermo323 * thermo323;
	prod[11] = LitThermo324 * thermo324;
	prod[12] = LitThermo325 * thermo325;
	prod[13] = LitThermo326 * thermo326;
	prod[14] = LitThermo327 * thermo327;
	prod[15] = LitThermo328 * thermo328;
	prod[16] = LitThermo329 * thermo329;
	prod[17] = LitThermo330 * thermo330;
	prod[18] = LitThermo331 * thermo331;
	prod[19] = LitThermo332 * thermo332;
	prod[20] = LitThermo333 * thermo333;
	prod[21] = LitThermo334 * thermo334;
	prod[22] = LitThermo335 * thermo335;
	prod[23] = LitThermo336 * thermo336;
	prod[24] = LitThermo337 * thermo337;
	for (i=0; i<25; i++){
		if (prod[i]<0)
			Mncounter++;
		prod[i]=0;
	}
	wTotal += wspinMnsign;
	deviation += (Mncounter/0.01)*wspinMnsign;

	//Fe sign			
	prod[0] = LitThermo338 * thermo338;
	prod[1] = LitThermo339 * thermo339;
	prod[2] = LitThermo340 * thermo340;
	prod[3] = LitThermo341 * thermo341;
	prod[4] = LitThermo342 * thermo342;
	prod[5] = LitThermo343 * thermo343;
	prod[6] = LitThermo344 * thermo344;
	prod[7] = LitThermo345 * thermo345;
	prod[8] = LitThermo346 * thermo346;
	prod[9] = LitThermo347 * thermo347;
	prod[10] = LitThermo348 * thermo348;
	prod[11] = LitThermo349 * thermo349;
	prod[12] = LitThermo350 * thermo350;
	prod[13] = LitThermo351 * thermo351;
	prod[14] = LitThermo352 * thermo352;
	prod[15] = LitThermo353 * thermo353;
	prod[16] = LitThermo354 * thermo354;
	prod[17] = LitThermo355 * thermo355;
	prod[18] = LitThermo356 * thermo356;
	prod[19] = LitThermo357 * thermo357;
	prod[20] = LitThermo358 * thermo358;
	prod[21] = LitThermo359 * thermo359;
	prod[22] = LitThermo360 * thermo360;
	prod[23] = LitThermo361 * thermo361;
	prod[24] = LitThermo362 * thermo362;
	prod[25] = LitThermo363 * thermo363;
	prod[26] = LitThermo364 * thermo364;
	prod[27] = LitThermo365 * thermo365;
	prod[28] = LitThermo366 * thermo366;
	for (i=0; i<29; i++){
		if (prod[i]<0)
			Fecounter++;
		prod[i]=0;
	}
	wTotal += wspinFesign;
	deviation += (Fecounter/0.01)*wspinFesign;

	//Co sign			
	prod[0] = LitThermo367 * thermo367;
	prod[1] = LitThermo368 * thermo368;
	prod[2] = LitThermo369 * thermo369;
	prod[3] = LitThermo370 * thermo370;
	prod[4] = LitThermo371 * thermo371;
	prod[5] = LitThermo372 * thermo372;
	prod[6] = LitThermo373 * thermo373;
	prod[7] = LitThermo374 * thermo374;
	prod[8] = LitThermo375 * thermo375;
	prod[9] = LitThermo376 * thermo376;
	prod[10] = LitThermo377 * thermo377;
	prod[11] = LitThermo378 * thermo378;
	prod[12] = LitThermo379 * thermo379;
	prod[13] = LitThermo380 * thermo380;
	prod[14] = LitThermo381 * thermo381;
	prod[15] = LitThermo382 * thermo382;
	prod[16] = LitThermo383 * thermo383;
	prod[17] = LitThermo384 * thermo384;
	prod[18] = LitThermo385 * thermo385;
	prod[19] = LitThermo386 * thermo386;
	prod[20] = LitThermo387 * thermo387;
	prod[21] = LitThermo388 * thermo388;
	prod[22] = LitThermo389 * thermo389;
	prod[23] = LitThermo390 * thermo390;
	prod[24] = LitThermo391 * thermo391;
	prod[25] = LitThermo392 * thermo392;
	prod[26] = LitThermo393 * thermo393;
	prod[27] = LitThermo394 * thermo394;
	prod[28] = LitThermo395 * thermo395;
	prod[29] = LitThermo396 * thermo396;
	prod[30] = LitThermo397 * thermo397;
	for (i=0; i<31; i++){
		if (prod[i]<0)
			Cocounter++;
		prod[i]=0;
	}
	wTotal += wspinCosign;
	deviation += (Cocounter/0.01)*wspinCosign;

	//Ni sign			
	prod[0] = LitThermo398 * thermo398;
	prod[1] = LitThermo399 * thermo399;
	prod[2] = LitThermo400 * thermo400;
	prod[3] = LitThermo401 * thermo401;
	prod[4] = LitThermo402 * thermo402;
	prod[5] = LitThermo403 * thermo403;
	prod[6] = LitThermo404 * thermo404;
	prod[7] = LitThermo405 * thermo405;
	prod[8] = LitThermo406 * thermo406;
	prod[9] = LitThermo407 * thermo407;
	prod[10] = LitThermo408 * thermo408;
	prod[11] = LitThermo409 * thermo409;
	prod[12] = LitThermo410 * thermo410;
	prod[13] = LitThermo411 * thermo411;
	prod[14] = LitThermo412 * thermo412;
	prod[15] = LitThermo413 * thermo413;
	prod[16] = LitThermo414 * thermo414;
	prod[17] = LitThermo415 * thermo415;
	prod[18] = LitThermo416 * thermo416;
	prod[19] = LitThermo417 * thermo417;
	prod[20] = LitThermo418 * thermo418;
	prod[21] = LitThermo419 * thermo419;
	prod[22] = LitThermo420 * thermo420;
	prod[23] = LitThermo421 * thermo421;
	prod[24] = LitThermo422 * thermo422;
	prod[25] = LitThermo423 * thermo423;
	prod[26] = LitThermo424 * thermo424;
	prod[27] = LitThermo425 * thermo425;
	prod[28] = LitThermo426 * thermo426;
	prod[29] = LitThermo427 * thermo427;
	prod[30] = LitThermo428 * thermo428;
	prod[31] = LitThermo429 * thermo429;
	prod[32] = LitThermo430 * thermo430;
	for (i=0; i<33; i++){
		if (prod[i]<0)
			Nicounter++;
		prod[i]=0;
	}
	wTotal += wspinNisign;
	deviation += (Nicounter/0.01)*wspinNisign;

	//Cu sign			
	prod[0] = LitThermo431 * thermo431;
	prod[1] = LitThermo432 * thermo432;
	prod[2] = LitThermo433 * thermo433;
	prod[3] = LitThermo434 * thermo434;
	prod[4] = LitThermo435 * thermo435;
	prod[5] = LitThermo436 * thermo436;
	prod[6] = LitThermo437 * thermo437;
	prod[7] = LitThermo438 * thermo438;
	prod[8] = LitThermo439 * thermo439;
	prod[9] = LitThermo440 * thermo440;
	prod[10] = LitThermo441 * thermo441;
	prod[11] = LitThermo442 * thermo442;
	prod[12] = LitThermo443 * thermo443;
	prod[13] = LitThermo444 * thermo444;
	prod[14] = LitThermo445 * thermo445;
	prod[15] = LitThermo446 * thermo446;
	prod[16] = LitThermo447 * thermo447;
	prod[17] = LitThermo448 * thermo448;
	prod[18] = LitThermo449 * thermo449;
	prod[19] = LitThermo450 * thermo450;
	prod[20] = LitThermo451 * thermo451;
	prod[21] = LitThermo452 * thermo452;
	prod[22] = LitThermo453 * thermo453;
	prod[23] = LitThermo454 * thermo454;
	prod[24] = LitThermo455 * thermo455;
	prod[25] = LitThermo456 * thermo456;
	prod[26] = LitThermo457 * thermo457;
	prod[27] = LitThermo458 * thermo458;
	prod[28] = LitThermo459 * thermo459;
	prod[29] = LitThermo460 * thermo460;
	prod[30] = LitThermo461 * thermo461;
	prod[31] = LitThermo462 * thermo462;
	for (i=0; i<32; i++){
		if (prod[i]<0)
			Cucounter++;
		prod[i]=0;
	}
	wTotal += wspinCusign;
	deviation += (Cucounter/0.01)*wspinCusign;

	//Zn sign			
	prod[0] = LitThermo463*thermo463;
	prod[1] = thermo464;
	prod[2] = thermo465;
	prod[3] = thermo466;
	prod[4] = thermo467;
	prod[5] = thermo468;
	prod[6] = thermo469;
	prod[7] = thermo470;
	prod[8] = thermo471;
	prod[9] = thermo472;
	prod[10] = thermo473;
	prod[11] = thermo474;
	prod[12] = thermo475;
	prod[13] = thermo476;
	prod[14] = thermo477;
	prod[15] = thermo478;
	prod[16] = thermo479;
	prod[17] = thermo480;
	prod[18] = thermo481;
	prod[19] = thermo482;
	prod[20] = thermo483;
	prod[21] = thermo484;
	prod[22] = thermo485;
	prod[23] = LitThermo486 * thermo486;
	prod[24] = LitThermo487 * thermo487;
	prod[25] = LitThermo488 * thermo488;
	prod[26] = LitThermo489 * thermo489;
	prod[27] = LitThermo490 * thermo490;
	prod[28] = LitThermo491 * thermo491;
	prod[29] = LitThermo492 * thermo492;
	prod[30] = LitThermo493 * thermo493;
	prod[31] = LitThermo494 * thermo494;
	prod[32] = LitThermo495 * thermo495;
	prod[33] = LitThermo496 * thermo496;
	prod[34] = LitThermo497 * thermo497;
	prod[35] = thermo701;
	prod[36] = thermo702;
	prod[37] = thermo703;
	prod[38] = thermo704;
	prod[39] = thermo705;
	prod[40] = thermo706;
	prod[41] = thermo707;
	prod[42] = thermo708;
	prod[43] = thermo709;
	prod[44] = thermo710;

	for (i=0; i<45; i++){
//		printf("prod[%d] is %f now\n", i , prod[i]); 
		if (prod[i]<0){
//			if (((i>14) && (i<22)) || (i ==35) || (i==36) || (i==37) || (i==44)){
//			if (i==0){ 
//				deviation += wspinZnsign*wspinZnplus11ion;
//			}
//			else if (i==1){
//				deviation += wspinZnsign*wspinZnplus10ion;
//			}
//			else if (i==2){
//				deviation += wspinZnsign*wspinZnplus10exion;
//			}
//			else if (i==3){
//				deviation += wspinZnsign*wspinZnplus9ion;
//			}
//			else if (i==4){
//				deviation += wspinZnsign*wspinZnplus8ion;
//			}
//			else if (i==5){
//				deviation += wspinZnsign*wspinZnplus7ion;
//			}
//			else if (i==6){
//				deviation += wspinZnsign*wspinZnplus6ion;
//			}
//			else if (i==7){
//				deviation += wspinZnsign*wspinZnplus6exion;
//			}
//			else if (i==8){
//				deviation += wspinZnsign*wspinZnplus6ex2ion;
//			}
//			else if (i==9){
//				deviation += wspinZnsign*wspinZnplus5ion;
//			}
//			else if (i==10){
//				deviation += wspinZnsign*wspinZnplus5exion;
//			}
//			else if (i==11){
//				deviation += wspinZnsign*wspinZnplus5ex2ion;
//			}
//			else if (i==12){
//				deviation += wspinZnsign*wspinZnplus4ion;
//			}
//			else if (i==13){
//				deviation += wspinZnsign*wspinZnplus4exion;
//			}
//			else if (i==14){
//				deviation += wspinZnsign*wspinZnplus4ex2ion;
//			}
//			else if (i==15){
//				deviation += wspinZnsign*wspinZnplus3ion;
//			}
//			else if (i==16){
//				deviation += wspinZnsign*wspinZnplus3exion;
//			}
//			else if (i==17){
//				deviation += wspinZnsign*wspinZnplus2ion;
//			}
//			else if (i==18){
//				deviation += wspinZnsign*wspinZnplus2exion;
//			}
//			else if (i==19){
//				deviation += wspinZnsign*wspinZnplus1ion;
//			}
//			else if (i==20){
//				deviation += wspinZnsign*wspinZnplus1exion;
//			}
//			else if (i==21){
//				deviation += wspinZnsign*wspinZnneutrlion;
//			}
//			else if (i==22){
//				deviation += wspinZnsign*wspinZnneutrlexion;
//			}
//			else if (i==23){
//				deviation += wspinZnsign*wspinZnplus11ion;
//			}
//			else if (i==24){
//				deviation += wspinZnsign*wspinZnplus10ion;
//			}
//			else if (i==25){
//				deviation += wspinZnsign*wspinZnplus9ion;
//			}
//			else if (i==26){
//				deviation += wspinZnsign*wspinZnplus8ion;
//			}
//			else if (i==27){
//				deviation += wspinZnsign*wspinZnplus7ion;
//			}
//			else if (i==28){
//				deviation += wspinZnsign*wspinZnplus6ion;
//			}
//			else if (i==29){
//				deviation += wspinZnsign*wspinZnplus5ion;
//			}
//			else if (i==30){
//				deviation += wspinZnsign*wspinZnplus4ion;
//			}
//			else if (i==31){
//				deviation += wspinZnsign*wspinZnplus3ion;
//			}
//			else if (i==32){
//				deviation += wspinZnsign*wspinZnplus2ion;
//			}
//			else if (i==33){
//				deviation += wspinZnsign*wspinZnplus1ion;
//			}
//			else if (i==34){
//				deviation += wspinZnsign*wspinZnneutrlion;
//			}
//			else if (i==35){
//				deviation += wspinZnsign*wspinZnplus1exion;
//			}
//			else if (i==36){
//				deviation += wspinZnsign*wspinZnplus2exion;
//			}
//			else if (i==37){
//				deviation += wspinZnsign*wspinZnplus3exion;
//			}
//			else if (i==38){
//				deviation += wspinZnsign*wspinZnplus4ex2ion;
//			}
//			else if (i==39){
//				deviation += wspinZnsign*wspinZnplus5ex2ion;
//			}
//			else if (i==40){
//				deviation += wspinZnsign*wspinZnplus6ex2ion;
//			}
//			else if (i==41){
//				deviation += wspinZnsign*wspinZnplus7ion;
//			}
//			else if (i==42){
//				deviation += wspinZnsign*wspinZnplus8ion;
//			}
//			else if (i==43){
//				deviation += wspinZnsign*wspinZnplus9ion;
//			}
//			else if (i==44){
//				deviation += wspinZnsign*wspinZnneutrlexion;
//			}
				Zncounter++;
		}
		prod[i]=0;
	}
	wTotal += wspinZnsign;
	deviation += (Zncounter/0.01)*wspinZnsign;
//	printf("Zncounter is %d\n", Zncounter);
//	printf("weight is now %f, dev is now %f\n", wTotal, deviation);

	//Y sign			
	prod[0] = LitThermo498 * thermo498;
	prod[1] = LitThermo499 * thermo499;
	prod[2] = LitThermo500 * thermo500;
	prod[3] = LitThermo501 * thermo501;
	prod[4] = LitThermo502 * thermo502;
	prod[5] = LitThermo503 * thermo503;
	prod[6] = LitThermo504 * thermo504;
	prod[7] = LitThermo505 * thermo505;
	for (i=0; i<8; i++){
		if (prod[i]<0)
			Ycounter++;
		prod[i]=0;
	}
	wTotal += wspinYsign;
	deviation += (Ycounter/0.01)*wspinYsign;

	//Zr sign			
	prod[0] = LitThermo506 * thermo506;
	prod[1] = LitThermo507 * thermo507;
	prod[2] = LitThermo508 * thermo508;
	prod[3] = LitThermo509 * thermo509;
	prod[4] = LitThermo510 * thermo510;
	prod[5] = LitThermo511 * thermo511;
	prod[6] = LitThermo512 * thermo512;
	prod[7] = LitThermo513 * thermo513;
	prod[8] = LitThermo514 * thermo514;
	prod[9] = LitThermo515 * thermo515;
	prod[10] = LitThermo516 * thermo516;
	prod[11] = LitThermo517 * thermo517;
	for (i=0; i<12; i++){
		if (prod[i]<0)
			Zrcounter++;
		prod[i]=0;
	}
	wTotal += wspinZrsign;
	deviation += (Zrcounter/0.01)*wspinZrsign;

	//Nb sign			
	prod[0] = LitThermo518 * thermo518;
	prod[1] = LitThermo519 * thermo519;
	prod[2] = LitThermo520 * thermo520;
	prod[3] = LitThermo521 * thermo521;
	prod[4] = LitThermo522 * thermo522;
	prod[5] = LitThermo523 * thermo523;
	prod[6] = LitThermo524 * thermo524;
	prod[7] = LitThermo525 * thermo525;
	prod[8] = LitThermo526 * thermo526;
	prod[9] = LitThermo527 * thermo527;
	prod[10] = LitThermo528 * thermo528;
	prod[11] = LitThermo529 * thermo529;
	prod[12] = LitThermo530 * thermo530;
	prod[13] = LitThermo531 * thermo531;
	prod[14] = LitThermo532 * thermo532;
	prod[15] = LitThermo533 * thermo533;
	for (i=0; i<16; i++){
		if (prod[i]<0)
			Nbcounter++;
		prod[i]=0;
	}
	wTotal += wspinNbsign;
	deviation += (Nbcounter/0.01)*wspinNbsign;

	//Mo sign			
	prod[0] = LitThermo534 * thermo534;
	prod[1] = LitThermo535 * thermo535;
	prod[2] = LitThermo536 * thermo536;
	prod[3] = LitThermo537 * thermo537;
	prod[4] = LitThermo538 * thermo538;
	prod[5] = LitThermo539 * thermo539;
	prod[6] = LitThermo540 * thermo540;
	prod[7] = LitThermo541 * thermo541;
	prod[8] = LitThermo542 * thermo542;
	prod[9] = LitThermo543 * thermo543;
	prod[10] = LitThermo544 * thermo544;
	prod[11] = LitThermo545 * thermo545;
	prod[12] = LitThermo546 * thermo546;
	prod[13] = LitThermo547 * thermo547;
	prod[14] = LitThermo548 * thermo548;
	prod[15] = LitThermo549 * thermo549;
	prod[16] = LitThermo550 * thermo550;
	prod[17] = LitThermo551 * thermo551;
	prod[18] = LitThermo552 * thermo552;
	prod[19] = LitThermo553 * thermo553;
	prod[20] = LitThermo554 * thermo554;
	for (i=0; i<21; i++){
		if (prod[i]<0)
			Mocounter++;
		prod[i]=0;
	}
	wTotal += wspinMosign;
	deviation += (Mocounter/0.01)*wspinMosign;

	//Tc sign			
	prod[0] = LitThermo555 * thermo555;
	prod[1] = LitThermo556 * thermo556;
	prod[2] = LitThermo557 * thermo557;
	prod[3] = LitThermo558 * thermo558;
	prod[4] = LitThermo559 * thermo559;
	prod[5] = LitThermo560 * thermo560;
	prod[6] = LitThermo561 * thermo561;
	prod[7] = LitThermo562 * thermo562;
	prod[8] = LitThermo563 * thermo563;
	prod[9] = LitThermo564 * thermo564;
	prod[10] = LitThermo565 * thermo565;
	prod[11] = LitThermo566 * thermo566;
	prod[12] = LitThermo567 * thermo567;
	prod[13] = LitThermo568 * thermo568;
	prod[14] = LitThermo569 * thermo569;
	prod[15] = LitThermo570 * thermo570;
	prod[16] = LitThermo571 * thermo571;
	prod[17] = LitThermo572 * thermo572;
	for (i=0; i<18; i++){
		if (prod[i]<0)
			Tccounter++;
		prod[i]=0;
	}
	wTotal += wspinTcsign;
	deviation += (Tccounter/0.01)*wspinTcsign;

	//Ru sign			
	prod[0] = LitThermo573 * thermo573;
	prod[1] = LitThermo574 * thermo574;
	prod[2] = LitThermo575 * thermo575;
	prod[3] = LitThermo576 * thermo576;
	prod[4] = LitThermo577 * thermo577;
	prod[5] = LitThermo578 * thermo578;
	prod[6] = LitThermo579 * thermo579;
	prod[7] = LitThermo580 * thermo580;
	prod[8] = LitThermo581 * thermo581;
	prod[9] = LitThermo582 * thermo582;
	prod[10] = LitThermo583 * thermo583;
	prod[11] = LitThermo584 * thermo584;
	prod[12] = LitThermo585 * thermo585;
	prod[13] = LitThermo586 * thermo586;
	prod[14] = LitThermo587 * thermo587;
	prod[15] = LitThermo588 * thermo588;
	prod[16] = LitThermo589 * thermo589;
	prod[17] = LitThermo590 * thermo590;
	prod[18] = LitThermo591 * thermo591;
	prod[19] = LitThermo592 * thermo592;
	prod[20] = LitThermo593 * thermo593;
	for (i=0; i<21; i++){
		if (prod[i]<0)
			Rucounter++;
		prod[i]=0;
	}
	wTotal += wspinRusign;
	deviation += (Rucounter/0.01)*wspinRusign;

	//Rh sign			
	prod[0] = LitThermo594 * thermo594;
	prod[1] = LitThermo595 * thermo595;
	prod[2] = LitThermo596 * thermo596;
	prod[3] = LitThermo597 * thermo597;
	prod[4] = LitThermo598 * thermo598;
	prod[5] = LitThermo599 * thermo599;
	prod[6] = LitThermo600 * thermo600;
	prod[7] = LitThermo601 * thermo601;
	prod[8] = LitThermo602 * thermo602;
	prod[9] = LitThermo603 * thermo603;
	prod[10] = LitThermo604 * thermo604;
	prod[11] = LitThermo605 * thermo605;
	prod[12] = LitThermo606 * thermo606;
	prod[13] = LitThermo607 * thermo607;
	prod[14] = LitThermo608 * thermo608;
	prod[15] = LitThermo609 * thermo609;
	prod[16] = LitThermo610 * thermo610;
	prod[17] = LitThermo611 * thermo611;
	prod[18] = LitThermo612 * thermo612;
	prod[19] = LitThermo613 * thermo613;
	prod[20] = LitThermo614 * thermo614;
	prod[21] = LitThermo615 * thermo615;
	prod[22] = LitThermo616 * thermo616;
	for (i=0; i<23; i++){
		if (prod[i]<0)
			Rhcounter++;
		prod[i]=0;
	}
	wTotal += wspinRhsign;
	deviation += (Rhcounter/0.01)*wspinRhsign;

	//Pd sign			
	prod[0] = LitThermo617 * thermo617;
	prod[1] = LitThermo618 * thermo618;
	prod[2] = LitThermo619 * thermo619;
	prod[3] = LitThermo620 * thermo620;
	prod[4] = LitThermo621 * thermo621;
	prod[5] = LitThermo622 * thermo622;
	prod[6] = LitThermo623 * thermo623;
	prod[7] = LitThermo624 * thermo624;
	prod[8] = LitThermo625 * thermo625;
	prod[9] = LitThermo626 * thermo626;
	prod[10] = LitThermo627 * thermo627;
	prod[11] = LitThermo628 * thermo628;
	prod[12] = LitThermo629 * thermo629;
	prod[13] = LitThermo630 * thermo630;
	prod[14] = LitThermo631 * thermo631;
	prod[15] = LitThermo632 * thermo632;
	prod[16] = LitThermo633 * thermo633;
	prod[17] = LitThermo634 * thermo634;
	prod[18] = LitThermo635 * thermo635;
	prod[19] = LitThermo636 * thermo636;
	prod[20] = LitThermo637 * thermo637;
	prod[21] = LitThermo638 * thermo638;
	prod[22] = LitThermo639 * thermo639;
	prod[23] = LitThermo640 * thermo640;
	for (i=0; i<24; i++){
		if (prod[i]<0)
			Pdcounter++;
		prod[i]=0;
	}
	wTotal += wspinPdsign;
	deviation += (Pdcounter/0.01)*wspinPdsign;

	//Ag sign			
	prod[0] = LitThermo641 * thermo641;
	prod[1] = LitThermo642 * thermo642;
	prod[2] = LitThermo643 * thermo643;
	prod[3] = LitThermo644 * thermo644;
	prod[4] = LitThermo645 * thermo645;
	prod[5] = LitThermo646 * thermo646;
	prod[6] = LitThermo647 * thermo647;
	prod[7] = LitThermo648 * thermo648;
	prod[8] = LitThermo649 * thermo649;
	prod[9] = LitThermo650 * thermo650;
	prod[10] = LitThermo651 * thermo651;
	prod[11] = LitThermo652 * thermo652;
	prod[12] = LitThermo653 * thermo653;
	prod[13] = LitThermo654 * thermo654;
	prod[14] = LitThermo655 * thermo655;
	prod[15] = LitThermo656 * thermo656;
	prod[16] = LitThermo657 * thermo657;
	prod[17] = LitThermo658 * thermo658;
	prod[18] = LitThermo659 * thermo659;
	prod[19] = LitThermo660 * thermo660;
	prod[20] = LitThermo661 * thermo661;
	prod[21] = LitThermo662 * thermo662;
	prod[22] = LitThermo663 * thermo663;
	prod[23] = LitThermo664 * thermo664;
	prod[24] = LitThermo665 * thermo665;
	for (i=0; i<25; i++){
		if (prod[i]<0)
			Agcounter++;
		prod[i]=0;
	}
	wTotal += wspinAgsign;
	deviation += (Agcounter/0.01)*wspinAgsign;

	//Cd sign			
	prod[0] = LitThermo666 * thermo666;
	prod[1] = LitThermo667 * thermo667;
	prod[2] = LitThermo668 * thermo668;
	prod[3] = LitThermo669 * thermo669;
	prod[4] = LitThermo670 * thermo670;
	prod[5] = LitThermo671 * thermo671;
	prod[6] = LitThermo672 * thermo672;
	prod[7] = LitThermo673 * thermo673;
	prod[8] = LitThermo674 * thermo674;
	prod[9] = LitThermo675 * thermo675;
	prod[10] = LitThermo676 * thermo676;
	prod[11] = LitThermo677 * thermo677;
	prod[12] = LitThermo678 * thermo678;
	prod[13] = LitThermo679 * thermo679;
	prod[14] = LitThermo680 * thermo680;
	prod[15] = LitThermo681 * thermo681;
	prod[16] = LitThermo682 * thermo682;
	prod[17] = LitThermo683 * thermo683;
	prod[18] = LitThermo684 * thermo684;
	prod[19] = LitThermo685 * thermo685;
	prod[20] = LitThermo686 * thermo686;
	prod[21] = LitThermo687 * thermo687;
	prod[22] = LitThermo688 * thermo688;
	prod[23] = LitThermo689 * thermo689;
	prod[24] = LitThermo690 * thermo690;
	prod[25] = LitThermo691 * thermo691;
	prod[26] = LitThermo692 * thermo692;
	prod[27] = LitThermo693 * thermo693;
	for (i=0; i<28; i++){
		if (prod[i]<0)
			Cdcounter++;
		prod[i]=0;
	}
	wTotal += wspinCdsign;
	deviation += (Cdcounter/0.01)*wspinCdsign;


//	printf("deviation is %f\n",deviation);
//	printf("wTotal is %f\n",wTotal);
	deviation /= wTotal;
//	printf("weighted deviation %f\n",deviation);

	if (print){
		OutFile = fopen(directory, "a");
		fprintf(OutFile, "|=========================================================================================================================|\n");
		fprintf(OutFile, "|                                             Thermodynamics                                                              |\n");
		fprintf(OutFile, "|=========================================================================================================================|\n");
		fprintf(OutFile, "|         Feature                    | Units  |     Value       |       Model      |      %c Dev       |   %c Scaled Dev    |\n", 37, 37);
		fprintf(OutFile, "|====================================|========|=================|==================|==================|===================|\n");
		fprintf(OutFile, "| (H & e) - (H-)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo18, thermo18, perdev18*100, dev18*100);
//		fprintf(OutFile, "| (H+ & e & e) - (H- trp)            | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo21, thermo21, perdev21*100, dev21*100);
		fprintf(OutFile, "| (H+ & e) - (H)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo19, thermo19, perdev19*100, dev19*100);
		fprintf(OutFile, "| (H & H) - (H2)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo5, thermo5, perdev5*100, dev5*100);
		fprintf(OutFile, "| (H2+ & e) - (H2)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo6, thermo6, perdev6*100, dev6*100);
		fprintf(OutFile, "| (H2 & H+) - (H3+)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo1, thermo1, perdev1*100, dev1*100);
//		fprintf(OutFile, "| (H3) - (H2 & H)                    | kJ/mol |      >% 6.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo208, thermo208, dev208*100);
//		fprintf(OutFile, "| (H4) - (H2 & H2)                   | kmol |      >% 6.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo209, thermo209, dev209*100);
                fprintf(OutFile, "| (H3)lin - (H2 & H)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo244, thermo244, perdev244*100, dev244*100);
//		fprintf(OutFile, "| (H3)trg - (H2 & H)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo245, thermo245, perdev245*100, dev245*100);
//		fprintf(OutFile, "| (H4)lin - (H2 & H2)                | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo246, thermo246, perdev246*100, dev246*100);
//		fprintf(OutFile, "| (H4)sq  - (H2 & H2)                | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo247, thermo247, perdev247*100, dev247*100);
//		fprintf(OutFile, "| (H4)tet - (H2 & H2)                | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo248, thermo248, perdev248*100, dev248*100);
		fprintf(OutFile, "| (H2-) - (H2 & e)                   | kJ/mol |      % 6.2f    |    % 10.2f    |    %10.2f    |    % 10.2f     |\n", LitThermo210, thermo210, perdev210*100, dev210*100);
		fprintf(OutFile, "| (H2+ & H2) - (H3+ & H)             | kJ/mol |      >% 6.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo211, thermo211, dev211*100);
		fprintf(OutFile, "| (H & H) - (H2*)                    | kJ/mol |     % 6.3f    |    % 10.3f    |    %10.2f    |    % 10.2f     |\n", LitThermo224, thermo224, perdev224*100, dev224*100);
//		fprintf(OutFile, "| (H3trig) - (H3linear)              | kJ/mol |      >% 6.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo234, thermo234, dev234*100);
//		fprintf(OutFile, "| (H4tetra) - (H4square)             | kJ/mol |      >% 6.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo235, thermo235, dev235*100);
//		fprintf(OutFile, "| (H4square) - (H4linear)            | kJ/mol |      >% 6.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo236, thermo236, dev236*100);
		fprintf(OutFile, "| Counter of sign errors             |  Hyd   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Hcounter);
//		fprintf(OutFile, "| (O-) - (O & e)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo8, thermo8, perdev8*100, dev8*100);
//		fprintf(OutFile, "| (O-2) - (O- & e)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo9, thermo9, perdev9*100, dev9*100);
//		fprintf(OutFile, "| (O+ & e) - (O)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo10, thermo10, perdev10*100, dev10*100);
//		fprintf(OutFile, "| (O+2 & e) - (O+)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo11, thermo11, perdev11*100, dev11*100);
//		fprintf(OutFile, "| (O-2  ) - (O-1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo21, thermo21, perdev21*100, dev21*100);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (O-1  ) - (O  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo22, thermo22, perdev22*100, dev22*100);
		fprintf(OutFile, "| (O    ) - (O+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo23, thermo23, perdev23*100, dev23*100);
		fprintf(OutFile, "| (O+1  ) - (O+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo24, thermo24, perdev24*100, dev24*100);
		fprintf(OutFile, "| (O+2  ) - (O+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo25, thermo25, perdev25*100, dev25*100);
		fprintf(OutFile, "| (O+3  ) - (O+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo26, thermo26, perdev26*100, dev26*100);
		fprintf(OutFile, "| (O+4  ) - (O+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo27, thermo27, perdev27*100, dev27*100);
		fprintf(OutFile, "| (O+5  ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo28, thermo28, perdev28*100, dev28*100);
		fprintf(OutFile, "| (O  * ) - (O  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo39, thermo39, perdev39*100, dev39*100);
		fprintf(OutFile, "| (O  **) - (O  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo156, thermo156, perdev156*100, dev156*100);
		fprintf(OutFile, "| (O  **) - (O* )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo163, thermo163, perdev163*100, dev163*100);
		fprintf(OutFile, "| (O+1* ) - (O+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo41, thermo41, perdev41*100, dev41*100);
		fprintf(OutFile, "| (O+1**) - (O+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo157, thermo157, perdev157*100, dev157*100);
		fprintf(OutFile, "| (O+2* ) - (O+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo40, thermo40, perdev40*100, dev40*100);
		fprintf(OutFile, "| (O+2**) - (O+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo122, thermo122, perdev122*100, dev122*100);
		fprintf(OutFile, "| (O+3* ) - (O+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo30, thermo30, perdev30*100, dev30*100);
		fprintf(OutFile, "| (O+4* ) - (O+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo42, thermo42, perdev42*100, dev42*100);
		fprintf(OutFile, "| (O2dia) - (O2para)                 | kJ/mol |  >% 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo29, thermo29, perdev29*100, dev29*100);
//		fprintf(OutFile, "| (O2qnt) - (O2dia)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo251, thermo251, perdev251*100, dev251*100);
		fprintf(OutFile, "| (O2qnt) - (O2para)                 | kJ/mol |  >% 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo252, perdev252*100, dev252*100);
//		fprintf(OutFile, "| (O2+1 ) - (O2    )                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo253, thermo253, perdev253*100, dev253*100);
//		fprintf(OutFile, "| (O2   ) - (O2-1  )                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo254, thermo254, perdev254*100, dev254*100);
		fprintf(OutFile, "| (O3trp) - (O3)                     | kJ/mol |  >% 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo711, thermo711, perdev711*100, dev711*100);
                fprintf(OutFile, "| Lowest energy starting pt for O2   |  lwst  |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", O2_id);
                fprintf(OutFile, "| Lowest energy starting pt for O2dia|  lwst  |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", O2dia_id);
                fprintf(OutFile, "| (O2snglbnd) - (O2linnett)          | kJ/mol |   % 10.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo238, thermo238, dev238*100);
                fprintf(OutFile, "| (O2dblbnd) - (O2linnett)           | kJ/mol |   % 10.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo239, thermo239, dev239*100);
                fprintf(OutFile, "| (O2trplbnd) - (O2linnet)           | kJ/mol |   % 10.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo240, thermo240, dev240*100);
                fprintf(OutFile, "| (O2dia_snglbnd) - (O2dia_linnett)  | kJ/mol |   % 10.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo241, thermo241, dev241*100);
                fprintf(OutFile, "| (O2dia_dblbnd) - (O2dia_linnett)   | kJ/mol |   % 10.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo242, thermo242, dev242*100);
                fprintf(OutFile, "| (O2dia_trplbnd) - (O2dia_linnett)  | kJ/mol |   % 10.2f    |    % 10.2f    |        n.a.      |    % 10.2f     |\n", LitThermo243, thermo243, dev243*100);
//		fprintf(OutFile, "| Lowest energy starting pt for O2   |  lwst  |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", O2_id);
//		fprintf(OutFile, "| Lowest energy starting pt for O2dia|  lwst  |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", O2dia_id);
//		fprintf(OutFile, "| (O-2  ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo31, thermo31, perdev31*100, dev31*100);
		fprintf(OutFile, "| (O-1  ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo32, thermo32, perdev32*100, dev32*100);
		fprintf(OutFile, "| (O)     - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo33, thermo33, perdev33*100, dev33*100);
		fprintf(OutFile, "| (O+1  ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo34, thermo34, perdev34*100, dev34*100);
		fprintf(OutFile, "| (O+2  ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo35, thermo35, perdev35*100, dev35*100);
		fprintf(OutFile, "| (O+3  ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo36, thermo36, perdev36*100, dev36*100);
		fprintf(OutFile, "| (O+4  ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo37, thermo37, perdev37*100, dev37*100);
		fprintf(OutFile, "| (O+5  ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo38, thermo38, perdev38*100, dev38*100);
		fprintf(OutFile, "| (O  * ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo117, thermo117, perdev117*100, dev117*100);
		fprintf(OutFile, "| (O+1* ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo118, thermo118, perdev118*100, dev118*100);
		fprintf(OutFile, "| (O+2* ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo119, thermo119, perdev119*100, dev119*100);
		fprintf(OutFile, "| (O+2**) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo123, thermo123, perdev123*100, dev123*100);
		fprintf(OutFile, "| (O+3* ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo120, thermo120, perdev120*100, dev120*100);
		fprintf(OutFile, "| (O+4* ) - (O+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo121, thermo121, perdev121*100, dev121*100);
		fprintf(OutFile, "| Counter of sign errors             |  Oxy   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Ocounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (C+3 ) - (C+4)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo43, thermo43, perdev43*100, dev43*100);
		fprintf(OutFile, "| (C+2 ) - (C+3)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo44, thermo44, perdev44*100, dev44*100);
		fprintf(OutFile, "| (C+1 ) - (C+2)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo45, thermo45, perdev45*100, dev45*100);
		fprintf(OutFile, "| (C   ) - (C+1)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo46, thermo46, perdev46*100, dev46*100);
		fprintf(OutFile, "| (C-1 ) - (C  )                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo47, thermo47, perdev47*100, dev47*100);
                fprintf(OutFile, "| (C2para) - (C2dia)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo227, thermo227, perdev227*100, dev227*100);
		fprintf(OutFile, "| (C+2* ) - (C+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo126, thermo126, perdev126*100, dev126*100);
		fprintf(OutFile, "| (C+1* ) - (C+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo127, thermo127, perdev127*100, dev127*100);
		fprintf(OutFile, "| (C  * ) - (C  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo128, thermo128, perdev128*100, dev128*100);
		fprintf(OutFile, "| (C  **) - (C  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo129, thermo129, perdev129*100, dev129*100);
		fprintf(OutFile, "| (C+3 ) - (C+4)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo80, thermo80, perdev80*100, dev80*100);
		fprintf(OutFile, "| (C+2 ) - (C+4)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo81, thermo81, perdev81*100, dev81*100);
		fprintf(OutFile, "| (C+1 ) - (C+4)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo82, thermo82, perdev82*100, dev82*100);
		fprintf(OutFile, "| (C   ) - (C+4)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo83, thermo83, perdev83*100, dev83*100);
		fprintf(OutFile, "| (C-1 ) - (C+4)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo84, thermo84, perdev84*100, dev84*100);
		fprintf(OutFile, "| Counter of sign errors             |  Car   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Ccounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (N+4 ) - (N+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo48, thermo48, perdev48*100, dev48*100);
		fprintf(OutFile, "| (N+3 ) - (N+4)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo49, thermo49, perdev49*100, dev49*100);
		fprintf(OutFile, "| (N+2 ) - (N+3)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo50, thermo50, perdev50*100, dev50*100);
		fprintf(OutFile, "| (N+1 ) - (N+2)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo51, thermo51, perdev51*100, dev51*100);
		fprintf(OutFile, "| (N   ) - (N+1)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo52, thermo52, perdev52*100, dev52*100);
                fprintf(OutFile, "| (N2para) - (N2dia)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo229, thermo229, perdev229*100, dev229*100);
//		fprintf(OutFile, "| (N-1 ) - (N  )                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo53, thermo53, perdev53*100, dev53*100);
		fprintf(OutFile, "| (N+3* ) - (N+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo130, thermo130, perdev130*100, dev130*100);
		fprintf(OutFile, "| (N+2* ) - (N+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo131, thermo131, perdev131*100, dev131*100);
		fprintf(OutFile, "| (N+1* ) - (N+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo132, thermo132, perdev132*100, dev132*100);
		fprintf(OutFile, "| (N+1**) - (N+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo133, thermo133, perdev133*100, dev133*100);
		fprintf(OutFile, "| (N*   ) - (N  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo134, thermo134, perdev134*100, dev134*100);
//		fprintf(OutFile, "| (N  **) - (N  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo158, thermo158, perdev158*100, dev158*100);
		fprintf(OutFile, "| (N+4 ) - (N+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo85, thermo85, perdev85*100, dev85*100);
		fprintf(OutFile, "| (N+3 ) - (N+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo86, thermo86, perdev86*100, dev86*100);
		fprintf(OutFile, "| (N+2 ) - (N+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo87, thermo87, perdev87*100, dev87*100);
		fprintf(OutFile, "| (N+1 ) - (N+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo88, thermo88, perdev88*100, dev88*100);
		fprintf(OutFile, "| (N   ) - (N+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo89, thermo89, perdev89*100, dev89*100);
//		fprintf(OutFile, "| (N-1 ) - (N+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo90, thermo90, perdev90*100, dev90*100);
		fprintf(OutFile, "| Counter of sign errors             |  Nit   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Ncounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (F+6 ) - (F+7)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo72, thermo72, perdev72*100, dev72*100);
		fprintf(OutFile, "| (F+5 ) - (F+6)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo73, thermo73, perdev73*100, dev73*100);
		fprintf(OutFile, "| (F+4 ) - (F+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo74, thermo74, perdev74*100, dev74*100);
		fprintf(OutFile, "| (F+3 ) - (F+4)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo75, thermo75, perdev75*100, dev75*100);
		fprintf(OutFile, "| (F+2 ) - (F+3)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo76, thermo76, perdev76*100, dev76*100);
		fprintf(OutFile, "| (F+1 ) - (F+2)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo77, thermo77, perdev77*100, dev77*100);
		fprintf(OutFile, "| (F   ) - (F+1)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo78, thermo78, perdev78*100, dev78*100);
		fprintf(OutFile, "| (F-1 ) - (F  )                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo79, thermo79, perdev79*100, dev79*100);
                fprintf(OutFile, "| (F2para) - (F2dia)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo232, thermo232, perdev232*100, dev232*100);
		fprintf(OutFile, "| (F+5* ) - (F+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo135, thermo135, perdev135*100, dev135*100);
		fprintf(OutFile, "| (F+4* ) - (F+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo136, thermo136, perdev136*100, dev136*100);
		fprintf(OutFile, "| (F+3* ) - (F+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo137, thermo137, perdev137*100, dev137*100);
		fprintf(OutFile, "| (F+3**) - (F+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo138, thermo138, perdev138*100, dev138*100);
		fprintf(OutFile, "| (F+2* ) - (F+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo139, thermo139, perdev139*100, dev139*100);
		fprintf(OutFile, "| (F+2**) - (F+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo161, thermo161, perdev161*100, dev161*100);
		fprintf(OutFile, "| (F+1* ) - (F+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo140, thermo140, perdev140*100, dev140*100);
		fprintf(OutFile, "| (F+1**) - (F+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo160, thermo160, perdev160*100, dev160*100);
		fprintf(OutFile, "| (F  * ) - (F  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo159, thermo159, perdev159*100, dev159*100);
		fprintf(OutFile, "| (F+6 ) - (F+7)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo109, thermo109, perdev109*100, dev109*100);
		fprintf(OutFile, "| (F+5 ) - (F+7)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo110, thermo110, perdev110*100, dev110*100);
		fprintf(OutFile, "| (F+4 ) - (F+7)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo111, thermo111, perdev111*100, dev111*100);
		fprintf(OutFile, "| (F+3 ) - (F+7)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo112, thermo112, perdev112*100, dev112*100);
		fprintf(OutFile, "| (F+2 ) - (F+7)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo113, thermo113, perdev113*100, dev113*100);
		fprintf(OutFile, "| (F+1 ) - (F+7)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo114, thermo114, perdev114*100, dev114*100);
		fprintf(OutFile, "| (F   ) - (F+7)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo115, thermo115, perdev115*100, dev115*100);
		fprintf(OutFile, "| (F-1 ) - (F+7)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo116, thermo116, perdev116*100, dev116*100);
		fprintf(OutFile, "| Counter of sign errors             |  Flu   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Fcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Si+3) - (Si+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo67, thermo67, perdev67*100, dev67*100);
		fprintf(OutFile, "| (Si+2) - (Si+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo68, thermo68, perdev68*100, dev68*100);
		fprintf(OutFile, "| (Si+1) - (Si+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo69, thermo69, perdev69*100, dev69*100);
		fprintf(OutFile, "| (Si  ) - (Si+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo70, thermo70, perdev70*100, dev70*100);
		fprintf(OutFile, "| (Si-1) - (Si  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo71, thermo71, perdev71*100, dev71*100);
                fprintf(OutFile, "| (Si2dia) - (Si2para)               | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo228, thermo228, perdev228*100, dev228*100);
		fprintf(OutFile, "| (Si+2* ) - (Si+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo141, thermo141, perdev141*100, dev141*100);
		fprintf(OutFile, "| (Si+1* ) - (Si+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo142, thermo142, perdev142*100, dev142*100);
		fprintf(OutFile, "| (Si  * ) - (Si  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo143, thermo143, perdev143*100, dev143*100);
		fprintf(OutFile, "| (Si  **) - (Si  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo144, thermo144, perdev144*100, dev144*100);
		fprintf(OutFile, "| (Si+3 ) - (Si+4)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo104, thermo104, perdev104*100, dev104*100);
		fprintf(OutFile, "| (Si+2 ) - (Si+4)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo105, thermo105, perdev105*100, dev105*100);
		fprintf(OutFile, "| (Si+1 ) - (Si+4)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo106, thermo106, perdev106*100, dev106*100);
		fprintf(OutFile, "| (Si   ) - (Si+4)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo107, thermo107, perdev107*100, dev107*100);
		fprintf(OutFile, "| (Si-1 ) - (Si+4)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo108, thermo108, perdev108*100, dev108*100);
		fprintf(OutFile, "| Counter of sign errors             |  Sil   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Sicounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (P+4 ) - (P+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo61, thermo61, perdev61*100, dev61*100);
		fprintf(OutFile, "| (P+3 ) - (P+4)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo62, thermo62, perdev62*100, dev62*100);
		fprintf(OutFile, "| (P+2 ) - (P+3)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo63, thermo63, perdev63*100, dev63*100);
		fprintf(OutFile, "| (P+1 ) - (P+2)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo64, thermo64, perdev64*100, dev64*100);
		fprintf(OutFile, "| (P   ) - (P+1)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo65, thermo65, perdev65*100, dev65*100);
		fprintf(OutFile, "| (P-1 ) - (P  )                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f	|\n", LitThermo66, thermo66, perdev66*100, dev66*100);
                fprintf(OutFile, "| (P2para) - (P2dia)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo230, thermo230, perdev230*100, dev230*100);
		fprintf(OutFile, "| (P+3* ) - (P+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo145, thermo145, perdev145*100, dev145*100);
		fprintf(OutFile, "| (P+2* ) - (P+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo146, thermo146, perdev146*100, dev146*100);
		fprintf(OutFile, "| (P+1* ) - (P+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo147, thermo147, perdev147*100, dev147*100);
		fprintf(OutFile, "| (P+1**) - (P+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo148, thermo148, perdev148*100, dev148*100);
		fprintf(OutFile, "| (P  * ) - (P  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo149, thermo149, perdev149*100, dev149*100);
		fprintf(OutFile, "| (P+4 ) - (P+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo98, thermo98, perdev98*100, dev98*100);
		fprintf(OutFile, "| (P+3 ) - (P+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo99, thermo99, perdev99*100, dev99*100);
		fprintf(OutFile, "| (P+2 ) - (P+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo100, thermo100, perdev100*100, dev100*100);
		fprintf(OutFile, "| (P+1 ) - (P+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo101, thermo101, perdev101*100, dev101*100);
		fprintf(OutFile, "| (P   ) - (P+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo102, thermo102, perdev102*100, dev102*100);
		fprintf(OutFile, "| (P-1 ) - (P+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo103, thermo103, perdev103*100, dev103*100);
		fprintf(OutFile, "| Counter of sign errors             |  Pho   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Pcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (S+5 ) - (S+6)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo54, thermo54, perdev54*100, dev54*100);
		fprintf(OutFile, "| (S+4 ) - (S+5)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo55, thermo55, perdev55*100, dev55*100);
		fprintf(OutFile, "| (S+3 ) - (S+4)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo56, thermo56, perdev56*100, dev56*100);
		fprintf(OutFile, "| (S+2 ) - (S+3)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo57, thermo57, perdev57*100, dev57*100);
		fprintf(OutFile, "| (S+1 ) - (S+2)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo58, thermo58, perdev58*100, dev58*100);
		fprintf(OutFile, "| (S   ) - (S+1)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo59, thermo59, perdev59*100, dev59*100);
		fprintf(OutFile, "| (S-1 ) - (S  )                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo60, thermo60, perdev60*100, dev60*100);
                fprintf(OutFile, "| (S2dia) - (S2para)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo231, thermo231, perdev231*100, dev231*100);
		fprintf(OutFile, "| (S+4* ) - (S+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo150, thermo150, perdev150*100, dev150*100);
		fprintf(OutFile, "| (S+3* ) - (S+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo151, thermo151, perdev151*100, dev151*100);
		fprintf(OutFile, "| (S+2* ) - (S+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo152, thermo152, perdev152*100, dev152*100);
		fprintf(OutFile, "| (S+2**) - (S+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo153, thermo153, perdev153*100, dev153*100);
		fprintf(OutFile, "| (S+1* ) - (S+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo154, thermo154, perdev154*100, dev154*100);
		fprintf(OutFile, "| (S  * ) - (S  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo155, thermo155, perdev155*100, dev155*100);
		fprintf(OutFile, "| (S  **) - (S  )                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo162, thermo162, perdev162*100, dev162*100);
		fprintf(OutFile, "| (S+5 ) - (S+6)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo91, thermo91, perdev91*100, dev91*100);
		fprintf(OutFile, "| (S+4 ) - (S+6)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo92, thermo92, perdev92*100, dev92*100);
		fprintf(OutFile, "| (S+3 ) - (S+6)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo93, thermo93, perdev93*100, dev93*100);
		fprintf(OutFile, "| (S+2 ) - (S+6)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo94, thermo94, perdev94*100, dev94*100);
		fprintf(OutFile, "| (S+1 ) - (S+6)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo95, thermo95, perdev95*100, dev95*100);
		fprintf(OutFile, "| (S   ) - (S+6)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo96, thermo96, perdev96*100, dev96*100);
		fprintf(OutFile, "| (S-1 ) - (S+6)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo97, thermo97, perdev97*100, dev97*100);
		fprintf(OutFile, "| Counter of sign errors             |  Sul   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Scounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Bo+2 ) - (Bo+3)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo164, thermo164, perdev164*100, dev164*100);
		fprintf(OutFile, "| (Bo+1 ) - (Bo+2)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo165, thermo165, perdev165*100, dev165*100);
		fprintf(OutFile, "| (Bo    ) - (Bo+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo166, thermo166, perdev166*100, dev166*100);
		fprintf(OutFile, "| (Bo-1  ) - (Bo  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo167, thermo167, perdev167*100, dev167*100);
                fprintf(OutFile, "| (Bo2dia) - (Bo2para)               | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo226, thermo226, perdev226*100, dev226*100);
		fprintf(OutFile, "| (Bo+1* ) - (Bo+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo168, thermo168, perdev168*100, dev168*100);
		fprintf(OutFile, "| (Bo  * ) - (Bo  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo169, thermo169, perdev169*100, dev169*100);
		fprintf(OutFile, "| (Bo+2  ) - (Bo+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo170, thermo170, perdev170*100, dev170*100);
		fprintf(OutFile, "| (Bo+1  ) - (Bo+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo171, thermo171, perdev171*100, dev171*100);
		fprintf(OutFile, "| (Bo    ) - (Bo+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo172, thermo172, perdev172*100, dev172*100);
		fprintf(OutFile, "| (Bo-1  ) - (Bo+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo173, thermo173, perdev173*100, dev173*100);
		fprintf(OutFile, "| Counter of sign errors             |  Bor   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Bcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Cl+6  ) - (Cl+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo189, thermo189, perdev189*100, dev189*100);
		fprintf(OutFile, "| (Cl+5  ) - (Cl+6)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo188, thermo188, perdev188*100, dev188*100);
		fprintf(OutFile, "| (Cl+4  ) - (Cl+5)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo186, thermo186, perdev186*100, dev186*100);
		fprintf(OutFile, "| (Cl+3  ) - (Cl+4)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo184, thermo184, perdev184*100, dev184*100);
		fprintf(OutFile, "| (Cl+2  ) - (Cl+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo181, thermo181, perdev181*100, dev181*100);
		fprintf(OutFile, "| (Cl+1  ) - (Cl+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo179, thermo179, perdev179*100, dev179*100);
		fprintf(OutFile, "| (Cl    ) - (Cl+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo176, thermo176, perdev176*100, dev176*100);
		fprintf(OutFile, "| (Cl-1  ) - (Cl  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo174, thermo174, perdev174*100, dev174*100);
                fprintf(OutFile, "| (Cl2para) - (Cl2dia)               | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo233, thermo233, perdev233*100, dev233*100);
		fprintf(OutFile, "| (Cl+5* ) - (Cl+5)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo187, thermo187, perdev187*100, dev187*100);
		fprintf(OutFile, "| (Cl+4* ) - (Cl+4)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo185, thermo185, perdev185*100, dev185*100);
		fprintf(OutFile, "| (Cl+3* ) - (Cl+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo183, thermo183, perdev183*100, dev183*100);
		fprintf(OutFile, "| (Cl+3**) - (Cl+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo182, thermo182, perdev182*100, dev182*100);
		fprintf(OutFile, "| (Cl+2* ) - (Cl+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo180, thermo180, perdev180*100, dev180*100);
		fprintf(OutFile, "| (Cl+1* ) - (Cl+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo178, thermo178, perdev178*100, dev178*100);
		fprintf(OutFile, "| (Cl+1**) - (Cl+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo177, thermo177, perdev177*100, dev177*100);
		fprintf(OutFile, "| (Cl  * ) - (Cl  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo175, thermo175, perdev175*100, dev175*100);
		fprintf(OutFile, "| (Cl^6+ ) - (Cl+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo203, thermo203, perdev203*100, dev203*100);
		fprintf(OutFile, "| (Cl^5+ ) - (Cl+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo202, thermo202, perdev202*100, dev202*100);
		fprintf(OutFile, "| (Cl^4+ ) - (Cl+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo201, thermo201, perdev201*100, dev201*100);
		fprintf(OutFile, "| (Cl^3+ ) - (Cl+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo200, thermo200, perdev200*100, dev200*100);
		fprintf(OutFile, "| (Cl^2+ ) - (Cl+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo199, thermo199, perdev199*100, dev199*100);
		fprintf(OutFile, "| (Cl^1+ ) - (Cl+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo198, thermo198, perdev198*100, dev198*100);
		fprintf(OutFile, "| (Cl    ) - (Cl+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo197, thermo197, perdev197*100, dev197*100);
		fprintf(OutFile, "| (Cl-1  ) - (Cl+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo196, thermo196, perdev196*100, dev196*100);
		fprintf(OutFile, "| Counter of sign errors             |  Chl   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Clcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Al+2  ) - (Al+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo195, thermo195, perdev195*100, dev195*100);
		fprintf(OutFile, "| (Al+1  ) - (Al+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo194, thermo194, perdev194*100, dev194*100);
		fprintf(OutFile, "| (Al    ) - (Al+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo192, thermo192, perdev192*100, dev192*100);
		fprintf(OutFile, "| (Al-1  ) - (Al  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo190, thermo190, perdev190*100, dev190*100);
		fprintf(OutFile, "| (Al+1* ) - (Al+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo193, thermo193, perdev193*100, dev193*100);
		fprintf(OutFile, "| (Al  * ) - (Al  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo191, thermo191, perdev191*100, dev191*100);
		fprintf(OutFile, "| (Al2dia) - (Al2para)               | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo225, thermo225, perdev225*100, dev225*100);
		fprintf(OutFile, "| (Al^2+ ) - (Al+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo207, thermo207, perdev207*100, dev207*100);
		fprintf(OutFile, "| (Al^1+ ) - (Al+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo206, thermo206, perdev206*100, dev206*100);
		fprintf(OutFile, "| (Al    ) - (Al+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo205, thermo205, perdev205*100, dev205*100);
		fprintf(OutFile, "| (Al-1  ) - (Al+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo204, thermo204, perdev204*100, dev204*100);
		fprintf(OutFile, "| Counter of sign errors             |  Alu   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Alcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Li    ) - (Li+ )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo215, thermo215, perdev215*100, dev215*100);
		fprintf(OutFile, "| (Li-1  ) - (Li  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo214, thermo214, perdev214*100, dev214*100);
                fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Be+1  ) - (Be+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo218, thermo218, perdev218*100, dev218*100);
		fprintf(OutFile, "| (Be    ) - (Be+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo216, thermo216, perdev216*100, dev216*100);
		fprintf(OutFile, "| (Be  * ) - (Be  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo217, thermo217, perdev217*100, dev217*100);
                fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Na    ) - (Na+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo220, thermo220, perdev220*100, dev220*100);
		fprintf(OutFile, "| (Na-1  ) - (Na  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo219, thermo219, perdev219*100, dev219*100);
                fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Mg+1  ) - (Mg+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo223, thermo223, perdev223*100, dev223*100);
		fprintf(OutFile, "| (Mg    ) - (Mg+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo221, thermo221, perdev221*100, dev221*100);
		fprintf(OutFile, "| (Mg  * ) - (Mg  )                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo222, thermo222, perdev222*100, dev222*100);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Sc+3) - (Sc+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo256, thermo256, perdev256*100, dev256*100);
		fprintf(OutFile, "| (Sc+2) - (Sc+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo257, thermo257, perdev257*100, dev257*100);
		fprintf(OutFile, "| (Sc+1ex) - (Sc+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo258, thermo258, perdev258*100, dev258*100);
		fprintf(OutFile, "| (Sc+1) - (Sc+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo259, thermo259, perdev259*100, dev259*100);
		fprintf(OutFile, "| (Sc+0ex) - (Sc+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo260, thermo260, perdev260*100, dev260*100);
		fprintf(OutFile, "| (Sc+2) - (Sc+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo261, thermo261, perdev261*100, dev261*100);
		fprintf(OutFile, "| (Sc+1) - (Sc+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo262, thermo262, perdev262*100, dev262*100);
		fprintf(OutFile, "| (Sc+0) - (Sc+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo263, thermo263, perdev263*100, dev263*100);
		fprintf(OutFile, "| Counter of sign errors             | Sc     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Sccounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Ti+4) - (Ti+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo264, thermo264, perdev264*100, dev264*100);
		fprintf(OutFile, "| (Ti+3) - (Ti+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo265, thermo265, perdev265*100, dev265*100);
		fprintf(OutFile, "| (Ti+2ex) - (Ti+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo266, thermo266, perdev266*100, dev266*100);
		fprintf(OutFile, "| (Ti+2) - (Ti+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo267, thermo267, perdev267*100, dev267*100);
		fprintf(OutFile, "| (Ti+1ex) - (Ti+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo268, thermo268, perdev268*100, dev268*100);
		fprintf(OutFile, "| (Ti+1) - (Ti+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo269, thermo269, perdev269*100, dev269*100);
		fprintf(OutFile, "| (Ti+0ex) - (Ti+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo270, thermo270, perdev270*100, dev270*100);
		fprintf(OutFile, "| (Ti+0ex2) - (Ti+0)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo271, thermo271, perdev271*100, dev271*100);
		fprintf(OutFile, "| (Ti+3) - (Ti+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo272, thermo272, perdev272*100, dev272*100);
		fprintf(OutFile, "| (Ti+2) - (Ti+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo273, thermo273, perdev273*100, dev273*100);
		fprintf(OutFile, "| (Ti+1) - (Ti+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo274, thermo274, perdev274*100, dev274*100);
		fprintf(OutFile, "| (Ti+0) - (Ti+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo275, thermo275, perdev275*100, dev275*100);
		fprintf(OutFile, "| Counter of sign errors             | Ti     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Ticounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (V+5) - (V+4)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo276, thermo276, perdev276*100, dev276*100);
		fprintf(OutFile, "| (V+4) - (V+3)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo277, thermo277, perdev277*100, dev277*100);
		fprintf(OutFile, "| (V+3ex) - (V+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo278, thermo278, perdev278*100, dev278*100);
		fprintf(OutFile, "| (V+3) - (V+2)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo279, thermo279, perdev279*100, dev279*100);
		fprintf(OutFile, "| (V+2ex) - (V+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo280, thermo280, perdev280*100, dev280*100);
		fprintf(OutFile, "| (V+2) - (V+1)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo281, thermo281, perdev281*100, dev281*100);
		fprintf(OutFile, "| (V+1ex) - (V+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo282, thermo282, perdev282*100, dev282*100);
		fprintf(OutFile, "| (V+1ex2) - (V+1)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo283, thermo283, perdev283*100, dev283*100);
		fprintf(OutFile, "| (V+1) - (V+0)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo284, thermo284, perdev284*100, dev284*100);
		fprintf(OutFile, "| (V+0ex) - (V+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo285, thermo285, perdev285*100, dev285*100);
		fprintf(OutFile, "| (V+0ex2) - (V+0)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo286, thermo286, perdev286*100, dev286*100);
		fprintf(OutFile, "| (V+4) - (V+5)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo287, thermo287, perdev287*100, dev287*100);
		fprintf(OutFile, "| (V+3) - (V+5)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo288, thermo288, perdev288*100, dev288*100);
		fprintf(OutFile, "| (V+2) - (V+5)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo289, thermo289, perdev289*100, dev289*100);
		fprintf(OutFile, "| (V+1) - (V+5)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo290, thermo290, perdev290*100, dev290*100);
		fprintf(OutFile, "| (V+0) - (V+5)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo291, thermo291, perdev291*100, dev291*100);
		fprintf(OutFile, "| Counter of sign errors             | V      |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Vcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Cr+6) - (Cr+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo292, thermo292, perdev292*100, dev292*100);
		fprintf(OutFile, "| (Cr+5) - (Cr+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo293, thermo293, perdev293*100, dev293*100);
		fprintf(OutFile, "| (Cr+4ex) - (Cr+4)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo294, thermo294, perdev294*100, dev294*100);
		fprintf(OutFile, "| (Cr+4) - (Cr+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo295, thermo295, perdev295*100, dev295*100);
		fprintf(OutFile, "| (Cr+3ex) - (Cr+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo296, thermo296, perdev296*100, dev296*100);
		fprintf(OutFile, "| (Cr+3) - (Cr+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo297, thermo297, perdev297*100, dev297*100);
		fprintf(OutFile, "| (Cr+2ex) - (Cr+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo298, thermo298, perdev298*100, dev298*100);
		fprintf(OutFile, "| (Cr+2ex2) - (Cr+2)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo299, thermo299, perdev299*100, dev299*100);
		fprintf(OutFile, "| (Cr+2) - (Cr+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo300, thermo300, perdev300*100, dev300*100);
		fprintf(OutFile, "| (Cr+1ex) - (Cr+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo301, thermo301, perdev301*100, dev301*100);
		fprintf(OutFile, "| (Cr+1ex2) - (Cr+1)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo302, thermo302, perdev302*100, dev302*100);
		fprintf(OutFile, "| (Cr+1) - (Cr+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo303, thermo303, perdev303*100, dev303*100);
		fprintf(OutFile, "| (Cr+0ex) - (Cr+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo304, thermo304, perdev304*100, dev304*100);
		fprintf(OutFile, "| (Cr+0ex2) - (Cr+0)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo305, thermo305, perdev305*100, dev305*100);
		fprintf(OutFile, "| (Cr+0) - (Cr+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo306, thermo306, perdev306*100, dev306*100);
		fprintf(OutFile, "| (Cr+5) - (Cr+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo307, thermo307, perdev307*100, dev307*100);
		fprintf(OutFile, "| (Cr+4) - (Cr+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo308, thermo308, perdev308*100, dev308*100);
		fprintf(OutFile, "| (Cr+3) - (Cr+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo309, thermo309, perdev309*100, dev309*100);
		fprintf(OutFile, "| (Cr+2) - (Cr+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo310, thermo310, perdev310*100, dev310*100);
		fprintf(OutFile, "| (Cr+1) - (Cr+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo311, thermo311, perdev311*100, dev311*100);
		fprintf(OutFile, "| (Cr+0) - (Cr+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo312, thermo312, perdev312*100, dev312*100);
		fprintf(OutFile, "| Counter of sign errors             | Cr     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Crcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Mn+7) - (Mn+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo313, thermo313, perdev313*100, dev313*100);
		fprintf(OutFile, "| (Mn+6) - (Mn+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo314, thermo314, perdev314*100, dev314*100);
		fprintf(OutFile, "| (Mn+5ex) - (Mn+5)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo315, thermo315, perdev315*100, dev315*100);
		fprintf(OutFile, "| (Mn+5) - (Mn+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo316, thermo316, perdev316*100, dev316*100);
		fprintf(OutFile, "| (Mn+4ex) - (Mn+4)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo317, thermo317, perdev317*100, dev317*100);
		fprintf(OutFile, "| (Mn+4) - (Mn+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo318, thermo318, perdev318*100, dev318*100);
		fprintf(OutFile, "| (Mn+3ex) - (Mn+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo319, thermo319, perdev319*100, dev319*100);
		fprintf(OutFile, "| (Mn+3) - (Mn+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo320, thermo320, perdev320*100, dev320*100);
		fprintf(OutFile, "| (Mn+2ex) - (Mn+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo321, thermo321, perdev321*100, dev321*100);
		fprintf(OutFile, "| (Mn+2ex2) - (Mn+2)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo322, thermo322, perdev322*100, dev322*100);
		fprintf(OutFile, "| (Mn+2) - (Mn+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo323, thermo323, perdev323*100, dev323*100);
		fprintf(OutFile, "| (Mn+1ex) - (Mn+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo324, thermo324, perdev324*100, dev324*100);
		fprintf(OutFile, "| (Mn+1ex2) - (Mn+1)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo325, thermo325, perdev325*100, dev325*100);
		fprintf(OutFile, "| (Mn+1) - (Mn+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo326, thermo326, perdev326*100, dev326*100);
		fprintf(OutFile, "| (Mn+1) - (Mn+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo327, thermo327, perdev327*100, dev327*100);
		fprintf(OutFile, "| (Mn+0ex) - (Mn+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo328, thermo328, perdev328*100, dev328*100);
		fprintf(OutFile, "| (Mn+0ex2) - (Mn+0)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo329, thermo329, perdev329*100, dev329*100);
		fprintf(OutFile, "| (Mn+0) - (Mn+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo330, thermo330, perdev330*100, dev330*100);
		fprintf(OutFile, "| (Mn+6) - (Mn+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo331, thermo331, perdev331*100, dev331*100);
		fprintf(OutFile, "| (Mn+5) - (Mn+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo332, thermo332, perdev332*100, dev332*100);
		fprintf(OutFile, "| (Mn+4) - (Mn+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo333, thermo333, perdev333*100, dev333*100);
		fprintf(OutFile, "| (Mn+3) - (Mn+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo334, thermo334, perdev334*100, dev334*100);
		fprintf(OutFile, "| (Mn+2) - (Mn+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo335, thermo335, perdev335*100, dev335*100);
		fprintf(OutFile, "| (Mn+1) - (Mn+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo336, thermo336, perdev336*100, dev336*100);
		fprintf(OutFile, "| (Mn+0) - (Mn+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo337, thermo337, perdev337*100, dev337*100);
		fprintf(OutFile, "| Counter of sign errors             | Mn     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Mncounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Fe+8) - (Fe+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo338, thermo338, perdev338*100, dev338*100);
		fprintf(OutFile, "| (Fe+7) - (Fe+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo339, thermo339, perdev339*100, dev339*100);
		fprintf(OutFile, "| (Fe+6) - (Fe+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo341, thermo341, perdev341*100, dev341*100);
		fprintf(OutFile, "| (Fe+5) - (Fe+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo343, thermo343, perdev343*100, dev343*100);
		fprintf(OutFile, "| (Fe+4) - (Fe+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo346, thermo346, perdev346*100, dev346*100);
		fprintf(OutFile, "| (Fe+3) - (Fe+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo349, thermo349, perdev349*100, dev349*100);
		fprintf(OutFile, "| (Fe+2) - (Fe+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo352, thermo352, perdev352*100, dev352*100);
		fprintf(OutFile, "| (Fe+1) - (Fe+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo355, thermo355, perdev355*100, dev355*100);
		fprintf(OutFile, "| (Fe+6ex) - (Fe+6)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo340, thermo340, perdev340*100, dev340*100);
		fprintf(OutFile, "| (Fe+5ex) - (Fe+5)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo342, thermo342, perdev342*100, dev342*100);
		fprintf(OutFile, "| (Fe+4ex) - (Fe+4)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo344, thermo344, perdev344*100, dev344*100);
		fprintf(OutFile, "| (Fe+4ex2) - (Fe+4)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo345, thermo345, perdev345*100, dev345*100);
		fprintf(OutFile, "| (Fe+3ex) - (Fe+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo347, thermo347, perdev347*100, dev347*100);
		fprintf(OutFile, "| (Fe+3ex2) - (Fe+3)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo348, thermo348, perdev348*100, dev348*100);
		fprintf(OutFile, "| (Fe+2ex) - (Fe+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo350, thermo350, perdev350*100, dev350*100);
		fprintf(OutFile, "| (Fe+2ex2) - (Fe+2)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo351, thermo351, perdev351*100, dev351*100);
		fprintf(OutFile, "| (Fe+1ex) - (Fe+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo353, thermo353, perdev353*100, dev353*100);
		fprintf(OutFile, "| (Fe+1ex2) - (Fe+1)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo354, thermo354, perdev354*100, dev354*100);
		fprintf(OutFile, "| (Fe+0ex) - (Fe+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo356, thermo356, perdev356*100, dev356*100);
		fprintf(OutFile, "| (Fe+0ex2) - (Fe+0)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo357, thermo357, perdev357*100, dev357*100);
		fprintf(OutFile, "| (Fe+0ex3) - (Fe+0)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo358, thermo358, perdev358*100, dev358*100);
		fprintf(OutFile, "| (Fe+7) - (Fe+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo359, thermo359, perdev359*100, dev359*100);
		fprintf(OutFile, "| (Fe+6) - (Fe+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo360, thermo360, perdev360*100, dev360*100);
		fprintf(OutFile, "| (Fe+5) - (Fe+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo361, thermo361, perdev361*100, dev361*100);
		fprintf(OutFile, "| (Fe+4) - (Fe+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo362, thermo362, perdev362*100, dev362*100);
		fprintf(OutFile, "| (Fe+3) - (Fe+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo363, thermo363, perdev363*100, dev363*100);
		fprintf(OutFile, "| (Fe+2) - (Fe+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo364, thermo364, perdev364*100, dev364*100);
		fprintf(OutFile, "| (Fe+1) - (Fe+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo365, thermo365, perdev365*100, dev365*100);
		fprintf(OutFile, "| (Fe+0) - (Fe+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo366, thermo366, perdev366*100, dev366*100);
		fprintf(OutFile, "| Counter of sign errors             | Fe     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Fecounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Co+9) - (Co+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo367, thermo367, perdev367*100, dev367*100);
		fprintf(OutFile, "| (Co+8) - (Co+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo368, thermo368, perdev368*100, dev368*100);
		fprintf(OutFile, "| (Co+7ex) - (Co+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo369, thermo369, perdev369*100, dev369*100);
		fprintf(OutFile, "| (Co+7) - (Co+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo370, thermo370, perdev370*100, dev370*100);
		fprintf(OutFile, "| (Co+6ex) - (Co+6)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo371, thermo371, perdev371*100, dev371*100);
		fprintf(OutFile, "| (Co+6) - (Co+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo372, thermo372, perdev372*100, dev372*100);
		fprintf(OutFile, "| (Co+5ex) - (Co+5)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo373, thermo373, perdev373*100, dev373*100);
		fprintf(OutFile, "| (Co+5ex2) - (Co+5)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo374, thermo374, perdev374*100, dev374*100);
		fprintf(OutFile, "| (Co+5) - (Co+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo375, thermo375, perdev375*100, dev375*100);
		fprintf(OutFile, "| (Co+4ex) - (Co+4)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo376, thermo376, perdev376*100, dev376*100);
		fprintf(OutFile, "| (Co+4ex2) - (Co+4)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo377, thermo377, perdev377*100, dev377*100);
		fprintf(OutFile, "| (Co+4) - (Co+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo378, thermo378, perdev378*100, dev378*100);
		fprintf(OutFile, "| (Co+3ex) - (Co+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo379, thermo379, perdev379*100, dev379*100);
		fprintf(OutFile, "| (Co+3ex2) - (Co+3)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo380, thermo380, perdev380*100, dev380*100);
		fprintf(OutFile, "| (Co+3) - (Co+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo381, thermo381, perdev381*100, dev381*100);
		fprintf(OutFile, "| (Co+2ex) - (Co+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo382, thermo382, perdev382*100, dev382*100);
		fprintf(OutFile, "| (Co+2ex2) - (Co+2)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo383, thermo383, perdev383*100, dev383*100);
		fprintf(OutFile, "| (Co+2) - (Co+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo384, thermo384, perdev384*100, dev384*100);
		fprintf(OutFile, "| (Co+1ex) - (Co+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo385, thermo385, perdev385*100, dev385*100);
		fprintf(OutFile, "| (Co+1ex2) - (Co+1)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo386, thermo386, perdev386*100, dev386*100);
		fprintf(OutFile, "| (Co+1) - (Co+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo387, thermo387, perdev387*100, dev387*100);
		fprintf(OutFile, "| (Co+0ex) - (Co+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo388, thermo388, perdev388*100, dev388*100);
		fprintf(OutFile, "| (Co+8) - (Co+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo389, thermo389, perdev389*100, dev389*100);
		fprintf(OutFile, "| (Co+7) - (Co+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo390, thermo390, perdev390*100, dev390*100);
		fprintf(OutFile, "| (Co+6) - (Co+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo391, thermo391, perdev391*100, dev391*100);
		fprintf(OutFile, "| (Co+5) - (Co+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo392, thermo392, perdev392*100, dev392*100);
		fprintf(OutFile, "| (Co+4) - (Co+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo393, thermo393, perdev393*100, dev393*100);
		fprintf(OutFile, "| (Co+3) - (Co+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo394, thermo394, perdev394*100, dev394*100);
		fprintf(OutFile, "| (Co+2) - (Co+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo395, thermo395, perdev395*100, dev395*100);
		fprintf(OutFile, "| (Co+1) - (Co+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo396, thermo396, perdev396*100, dev396*100);
		fprintf(OutFile, "| (Co+0) - (Co+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo397, thermo397, perdev397*100, dev397*100);
		fprintf(OutFile, "| Counter of sign errors             | Co     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Cocounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Ni+10) - (Ni+9)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo398, thermo398, perdev398*100, dev398*100);
		fprintf(OutFile, "| (Ni+9) - (Ni+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo399, thermo399, perdev399*100, dev399*100);
		fprintf(OutFile, "| (Ni+8ex) - (Ni+8)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo400, thermo400, perdev400*100, dev400*100);
		fprintf(OutFile, "| (Ni+8) - (Ni+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo401, thermo401, perdev401*100, dev401*100);
		fprintf(OutFile, "| (Ni+7ex) - (Ni+7)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo402, thermo402, perdev402*100, dev402*100);
		fprintf(OutFile, "| (Ni+7) - (Ni+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo403, thermo403, perdev403*100, dev403*100);
		fprintf(OutFile, "| (Ni+6ex) - (Ni+6)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo404, thermo404, perdev404*100, dev404*100);
		fprintf(OutFile, "| (Ni+6) - (Ni+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo405, thermo405, perdev405*100, dev405*100);
		fprintf(OutFile, "| (Ni+5ex) - (Ni+5)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo406, thermo406, perdev406*100, dev406*100);
		fprintf(OutFile, "| (Ni+5ex2) - (Ni+5)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo407, thermo407, perdev407*100, dev407*100);
		fprintf(OutFile, "| (Ni+5) - (Ni+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo408, thermo408, perdev408*100, dev408*100);
		fprintf(OutFile, "| (Ni+4ex) - (Ni+4)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo409, thermo409, perdev409*100, dev409*100);
		fprintf(OutFile, "| (Ni+4ex2) - (Ni+4)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo410, thermo410, perdev410*100, dev410*100);
		fprintf(OutFile, "| (Ni+4) - (Ni+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo411, thermo411, perdev411*100, dev411*100);
		fprintf(OutFile, "| (Ni+3ex) - (Ni+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo412, thermo412, perdev412*100, dev412*100);
		fprintf(OutFile, "| (Ni+3ex2) - (Ni+3)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo413, thermo413, perdev413*100, dev413*100);
		fprintf(OutFile, "| (Ni+3) - (Ni+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo414, thermo414, perdev414*100, dev414*100);
		fprintf(OutFile, "| (Ni+2ex) - (Ni+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo415, thermo415, perdev415*100, dev415*100);
		fprintf(OutFile, "| (Ni+2ex2) - (Ni+2)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo416, thermo416, perdev416*100, dev416*100);
		fprintf(OutFile, "| (Ni+2) - (Ni+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo417, thermo417, perdev417*100, dev417*100);
		fprintf(OutFile, "| (Ni+1ex) - (Ni+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo418, thermo418, perdev418*100, dev418*100);
		fprintf(OutFile, "| (Ni+1) - (Ni+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo419, thermo419, perdev419*100, dev419*100);
		fprintf(OutFile, "| (Ni+0ex) - (Ni+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo420, thermo420, perdev420*100, dev420*100);
		fprintf(OutFile, "| (Ni+9) - (Ni+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo421, thermo421, perdev421*100, dev421*100);
		fprintf(OutFile, "| (Ni+8) - (Ni+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo422, thermo422, perdev422*100, dev422*100);
		fprintf(OutFile, "| (Ni+7) - (Ni+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo423, thermo423, perdev423*100, dev423*100);
		fprintf(OutFile, "| (Ni+6) - (Ni+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo424, thermo424, perdev424*100, dev424*100);
		fprintf(OutFile, "| (Ni+5) - (Ni+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo425, thermo425, perdev425*100, dev425*100);
		fprintf(OutFile, "| (Ni+4) - (Ni+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo426, thermo426, perdev426*100, dev426*100);
		fprintf(OutFile, "| (Ni+3) - (Ni+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo427, thermo427, perdev427*100, dev427*100);
		fprintf(OutFile, "| (Ni+2) - (Ni+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo428, thermo428, perdev428*100, dev428*100);
		fprintf(OutFile, "| (Ni+1) - (Ni+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo429, thermo429, perdev429*100, dev429*100);
		fprintf(OutFile, "| (Ni+0) - (Ni+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo430, thermo430, perdev430*100, dev430*100);
		fprintf(OutFile, "| Counter of sign errors             | Ni     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Nicounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Cu+11) - (Cu+10)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo431, thermo431, perdev431*100, dev431*100);
		fprintf(OutFile, "| (Cu+10) - (Cu+9)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo432, thermo432, perdev432*100, dev432*100);
		fprintf(OutFile, "| (Cu+9ex) - (Cu+9)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo433, thermo433, perdev433*100, dev433*100);
		fprintf(OutFile, "| (Cu+9) - (Cu+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo434, thermo434, perdev434*100, dev434*100);
		fprintf(OutFile, "| (Cu+8) - (Cu+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo435, thermo435, perdev435*100, dev435*100);
		fprintf(OutFile, "| (Cu+7) - (Cu+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo436, thermo436, perdev436*100, dev436*100);
		fprintf(OutFile, "| (Cu+6) - (Cu+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo437, thermo437, perdev437*100, dev437*100);
		fprintf(OutFile, "| (Cu+5ex) - (Cu+5)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo438, thermo438, perdev438*100, dev438*100);
		fprintf(OutFile, "| (Cu+5ex2) - (Cu+5)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo439, thermo439, perdev439*100, dev439*100);
		fprintf(OutFile, "| (Cu+5) - (Cu+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo440, thermo440, perdev440*100, dev440*100);
		fprintf(OutFile, "| (Cu+4ex) - (Cu+4)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo441, thermo441, perdev441*100, dev441*100);
		fprintf(OutFile, "| (Cu+4ex2) - (Cu+4)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo442, thermo442, perdev442*100, dev442*100);
		fprintf(OutFile, "| (Cu+4) - (Cu+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo443, thermo443, perdev443*100, dev443*100);
		fprintf(OutFile, "| (Cu+3ex) - (Cu+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo444, thermo444, perdev444*100, dev444*100);
		fprintf(OutFile, "| (Cu+3ex2) - (Cu+3)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo445, thermo445, perdev445*100, dev445*100);
		fprintf(OutFile, "| (Cu+3) - (Cu+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo446, thermo446, perdev446*100, dev446*100);
		fprintf(OutFile, "| (Cu+2ex) - (Cu+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo447, thermo447, perdev447*100, dev447*100);
		fprintf(OutFile, "| (Cu+2) - (Cu+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo448, thermo448, perdev448*100, dev448*100);
		fprintf(OutFile, "| (Cu+1ex) - (Cu+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo449, thermo449, perdev449*100, dev449*100);
		fprintf(OutFile, "| (Cu+1) - (Cu+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo450, thermo450, perdev450*100, dev450*100);
		fprintf(OutFile, "| (Cu+0ex) - (Cu+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo451, thermo451, perdev451*100, dev451*100);
		fprintf(OutFile, "| (Cu+10) - (Cu+11)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo452, thermo452, perdev452*100, dev452*100);
		fprintf(OutFile, "| (Cu+9) - (Cu+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo453, thermo453, perdev453*100, dev453*100);
		fprintf(OutFile, "| (Cu+8) - (Cu+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo454, thermo454, perdev454*100, dev454*100);
		fprintf(OutFile, "| (Cu+7) - (Cu+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo455, thermo455, perdev455*100, dev455*100);
		fprintf(OutFile, "| (Cu+6) - (Cu+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo456, thermo456, perdev456*100, dev456*100);
		fprintf(OutFile, "| (Cu+5) - (Cu+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo457, thermo457, perdev457*100, dev457*100);
		fprintf(OutFile, "| (Cu+4) - (Cu+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo458, thermo458, perdev458*100, dev458*100);
		fprintf(OutFile, "| (Cu+3) - (Cu+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo459, thermo459, perdev459*100, dev459*100);
		fprintf(OutFile, "| (Cu+2) - (Cu+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo460, thermo460, perdev460*100, dev460*100);
		fprintf(OutFile, "| (Cu+1) - (Cu+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo461, thermo461, perdev461*100, dev461*100);
		fprintf(OutFile, "| (Cu+0) - (Cu+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo462, thermo462, perdev462*100, dev462*100);
		fprintf(OutFile, "| Counter of sign errors             | Cu     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Cucounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Zn+12) - (Zn+11)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo463, thermo463, perdev463*100, dev463*100);
		fprintf(OutFile, "| (Zn+11) - (Zn+10)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo464, thermo464, perdev464*100, dev464*100);
		fprintf(OutFile, "| (Zn+10) - (Zn+9)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo466, thermo466, perdev466*100, dev466*100);
		fprintf(OutFile, "| (Zn+9) - (Zn+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo467, thermo467, perdev467*100, dev467*100);
		fprintf(OutFile, "| (Zn+8) - (Zn+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo468, thermo468, perdev468*100, dev468*100);
		fprintf(OutFile, "| (Zn+7) - (Zn+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo469, thermo469, perdev469*100, dev469*100);
		fprintf(OutFile, "| (Zn+6) - (Zn+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo472, thermo472, perdev472*100, dev472*100);
		fprintf(OutFile, "| (Zn+5) - (Zn+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo475, thermo475, perdev475*100, dev475*100);
		fprintf(OutFile, "| (Zn+4) - (Zn+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo478, thermo478, perdev478*100, dev478*100);
		fprintf(OutFile, "| (Zn+3) - (Zn+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo480, thermo480, perdev480*100, dev480*100);
		fprintf(OutFile, "| (Zn+2) - (Zn+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo482, thermo482, perdev482*100, dev482*100);
		fprintf(OutFile, "| (Zn+1) - (Zn+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo484, thermo484, perdev484*100, dev484*100);
		fprintf(OutFile, "| (Zn+10ex) - (Zn+10)                | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo465, thermo465, perdev465*100, dev465*100);
		fprintf(OutFile, "| (Zn+6ex) - (Zn+6)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo470, thermo470, perdev470*100, dev470*100);
		fprintf(OutFile, "| (Zn+6ex2) - (Zn+6ex)               | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo471, thermo471, perdev471*100, dev471*100);
		fprintf(OutFile, "| (Zn+5ex) - (Zn+5)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo473, thermo473, perdev473*100, dev473*100);
		fprintf(OutFile, "| (Zn+5ex2) - (Zn+5ex)               | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo474, thermo474, perdev474*100, dev474*100);
		fprintf(OutFile, "| (Zn+4ex) - (Zn+4)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo476, thermo476, perdev476*100, dev476*100);
		fprintf(OutFile, "| (Zn+4ex2) - (Zn+4ex)               | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo477, thermo477, perdev477*100, dev477*100);
		fprintf(OutFile, "| (Zn+3ex) - (Zn+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo479, thermo479, perdev479*100, dev479*100);
		fprintf(OutFile, "| (Zn+2ex) - (Zn+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo481, thermo481, perdev481*100, dev481*100);
		fprintf(OutFile, "| (Zn+1ex) - (Zn+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo483, thermo483, perdev483*100, dev483*100);
		fprintf(OutFile, "| (Zn+0ex) - (Zn+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo485, thermo485, perdev485*100, dev485*100);
		fprintf(OutFile, "| (Zn+11) - (Zn+12)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo486, thermo486, perdev486*100, dev486*100);
		fprintf(OutFile, "| (Zn+10) - (Zn+12)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo487, thermo487, perdev487*100, dev487*100);
		fprintf(OutFile, "| (Zn+9) - (Zn+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo488, thermo488, perdev488*100, dev488*100);
		fprintf(OutFile, "| (Zn+8) - (Zn+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo489, thermo489, perdev489*100, dev489*100);
		fprintf(OutFile, "| (Zn+7) - (Zn+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo490, thermo490, perdev490*100, dev490*100);
		fprintf(OutFile, "| (Zn+6) - (Zn+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo491, thermo491, perdev491*100, dev491*100);
		fprintf(OutFile, "| (Zn+5) - (Zn+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo492, thermo492, perdev492*100, dev492*100);
		fprintf(OutFile, "| (Zn+4) - (Zn+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo493, thermo493, perdev493*100, dev493*100);
		fprintf(OutFile, "| (Zn+3) - (Zn+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo494, thermo494, perdev494*100, dev494*100);
		fprintf(OutFile, "| (Zn+2) - (Zn+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo495, thermo495, perdev495*100, dev495*100);
		fprintf(OutFile, "| (Zn+1) - (Zn+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo496, thermo496, perdev496*100, dev496*100);
		fprintf(OutFile, "| (Zn+0) - (Zn+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo497, thermo497, perdev497*100, dev497*100);
		fprintf(OutFile, "| (Zn+9ex) - (Zn+9)                  | kJ/mol |  > % 10.2f   |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo709, 0.0, 0.0);
		fprintf(OutFile, "| (Zn+8ex) - (Zn+8)                  | kJ/mol |  > % 10.2f   |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo708, 0.0, 0.0);
		fprintf(OutFile, "| (Zn+7ex) - (Zn+7)                  | kJ/mol |  > % 10.2f   |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo707, 0.0, 0.0);
		fprintf(OutFile, "| (Zn+6ex3) - (Zn+6ex2)              | kJ/mol |  > % 10.2f   |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo706, 0.0, 0.0);
		fprintf(OutFile, "| (Zn+5ex3) - (Zn+5ex2)              | kJ/mol |  > % 10.2f   |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo705, 0.0, 0.0);
		fprintf(OutFile, "| (Zn+4ex3) - (Zn+4ex2)              | kJ/mol |  > % 10.2f   |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo704, 0.0, 0.0);
		fprintf(OutFile, "| (Zn+3ex2) - (Zn+3ex)               | kJ/mol |  > % 10.2f   |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo703, 0.0, 0.0);
		fprintf(OutFile, "| (Zn+2ex2) - (Zn+2ex)               | kJ/mol |  > % 10.2f   |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo702, 0.0, 0.0);
		fprintf(OutFile, "| (Zn+1ex2) - (Zn+1ex)               | kJ/mol |  > % 10.2f   |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo701, 0.0, 0.0);
		fprintf(OutFile, "| (Zn+0ex2) - (Zn+0ex)               | kJ/mol |  > % 10.2f   |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", 0.0, thermo710, 0.0, 0.0);
		fprintf(OutFile, "| Counter of sign errors             | Zinc   |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Zncounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Y+3) - (Y+2)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo498, thermo498, perdev498*100, dev498*100);
		fprintf(OutFile, "| (Y+2) - (Y+1)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo499, thermo499, perdev499*100, dev499*100);
		fprintf(OutFile, "| (Y+1ex) - (Y+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo500, thermo500, perdev500*100, dev500*100);
		fprintf(OutFile, "| (Y+1) - (Y+0)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo501, thermo501, perdev501*100, dev501*100);
		fprintf(OutFile, "| (Y+0ex) - (Y+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo502, thermo502, perdev502*100, dev502*100);
		fprintf(OutFile, "| (Y+2) - (Y+3)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo503, thermo503, perdev503*100, dev503*100);
		fprintf(OutFile, "| (Y+1) - (Y+3)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo504, thermo504, perdev504*100, dev504*100);
		fprintf(OutFile, "| (Y+0) - (Y+3)                      | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo505, thermo505, perdev505*100, dev505*100);
		fprintf(OutFile, "| Counter of sign errors             | Y      |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Ycounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Zr+4) - (Zr+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo506, thermo506, perdev506*100, dev506*100);
		fprintf(OutFile, "| (Zr+3) - (Zr+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo507, thermo507, perdev507*100, dev507*100);
		fprintf(OutFile, "| (Zr+2ex) - (Zr+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo508, thermo508, perdev508*100, dev508*100);
		fprintf(OutFile, "| (Zr+2) - (Zr+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo509, thermo509, perdev509*100, dev509*100);
		fprintf(OutFile, "| (Zr+1ex) - (Zr+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo510, thermo510, perdev510*100, dev510*100);
		fprintf(OutFile, "| (Zr+1) - (Zr+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo511, thermo511, perdev511*100, dev511*100);
		fprintf(OutFile, "| (Zr+0ex) - (Zr+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo512, thermo512, perdev512*100, dev512*100);
		fprintf(OutFile, "| (Zr+0ex2) - (Zr+0)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo513, thermo513, perdev513*100, dev513*100);
		fprintf(OutFile, "| (Zr+3) - (Zr+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo514, thermo514, perdev514*100, dev514*100);
		fprintf(OutFile, "| (Zr+2) - (Zr+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo515, thermo515, perdev515*100, dev515*100);
		fprintf(OutFile, "| (Zr+1) - (Zr+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo516, thermo516, perdev516*100, dev516*100);
		fprintf(OutFile, "| (Zr+0) - (Zr+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo517, thermo517, perdev517*100, dev517*100);
		fprintf(OutFile, "| Counter of sign errors             | Zr     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Zrcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Nb+5) - (Nb+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo518, thermo518, perdev518*100, dev518*100);
		fprintf(OutFile, "| (Nb+4) - (Nb+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo519, thermo519, perdev519*100, dev519*100);
		fprintf(OutFile, "| (Nb+3ex) - (Nb+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo520, thermo520, perdev520*100, dev520*100);
		fprintf(OutFile, "| (Nb+3) - (Nb+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo521, thermo521, perdev521*100, dev521*100);
		fprintf(OutFile, "| (Nb+2ex) - (Nb+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo522, thermo522, perdev522*100, dev522*100);
		fprintf(OutFile, "| (Nb+2) - (Nb+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo523, thermo523, perdev523*100, dev523*100);
		fprintf(OutFile, "| (Nb+1ex) - (Nb+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo524, thermo524, perdev524*100, dev524*100);
		fprintf(OutFile, "| (Nb+1ex2) - (Nb+1)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo525, thermo525, perdev525*100, dev525*100);
		fprintf(OutFile, "| (Nb+1) - (Nb+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo526, thermo526, perdev526*100, dev526*100);
		fprintf(OutFile, "| (Nb+0ex) - (Nb+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo527, thermo527, perdev527*100, dev527*100);
		fprintf(OutFile, "| (Nb+0ex2) - (Nb+0)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo528, thermo528, perdev528*100, dev528*100);
		fprintf(OutFile, "| (Nb+4) - (Nb+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo529, thermo529, perdev529*100, dev529*100);
		fprintf(OutFile, "| (Nb+3) - (Nb+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo530, thermo530, perdev530*100, dev530*100);
		fprintf(OutFile, "| (Nb+2) - (Nb+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo531, thermo531, perdev531*100, dev531*100);
		fprintf(OutFile, "| (Nb+1) - (Nb+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo532, thermo532, perdev532*100, dev532*100);
		fprintf(OutFile, "| (Nb+0) - (Nb+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo533, thermo533, perdev533*100, dev533*100);
		fprintf(OutFile, "| Counter of sign errors             | Nb     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Nbcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Mo+6) - (Mo+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo534, thermo534, perdev534*100, dev534*100);
		fprintf(OutFile, "| (Mo+5) - (Mo+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo535, thermo535, perdev535*100, dev535*100);
		fprintf(OutFile, "| (Mo+4ex) - (Mo+4)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo536, thermo536, perdev536*100, dev536*100);
		fprintf(OutFile, "| (Mo+4) - (Mo+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo537, thermo537, perdev537*100, dev537*100);
		fprintf(OutFile, "| (Mo+3ex) - (Mo+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo538, thermo538, perdev538*100, dev538*100);
		fprintf(OutFile, "| (Mo+3) - (Mo+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo539, thermo539, perdev539*100, dev539*100);
		fprintf(OutFile, "| (Mo+2ex) - (Mo+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo540, thermo540, perdev540*100, dev540*100);
		fprintf(OutFile, "| (Mo+2ex2) - (Mo+2)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo541, thermo541, perdev541*100, dev541*100);
		fprintf(OutFile, "| (Mo+2) - (Mo+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo542, thermo542, perdev542*100, dev542*100);
		fprintf(OutFile, "| (Mo+1ex) - (Mo+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo543, thermo543, perdev543*100, dev543*100);
		fprintf(OutFile, "| (Mo+1ex2) - (Mo+1)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo544, thermo544, perdev544*100, dev544*100);
		fprintf(OutFile, "| (Mo+1) - (Mo+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo545, thermo545, perdev545*100, dev545*100);
		fprintf(OutFile, "| (Mo+0ex) - (Mo+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo546, thermo546, perdev546*100, dev546*100);
		fprintf(OutFile, "| (Mo+0ex2) - (Mo+0)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo547, thermo547, perdev547*100, dev547*100);
		fprintf(OutFile, "| (Mo+0) - (Mo+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo548, thermo548, perdev548*100, dev548*100);
		fprintf(OutFile, "| (Mo+5) - (Mo+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo549, thermo549, perdev549*100, dev549*100);
		fprintf(OutFile, "| (Mo+4) - (Mo+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo550, thermo550, perdev550*100, dev550*100);
		fprintf(OutFile, "| (Mo+3) - (Mo+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo551, thermo551, perdev551*100, dev551*100);
		fprintf(OutFile, "| (Mo+2) - (Mo+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo552, thermo552, perdev552*100, dev552*100);
		fprintf(OutFile, "| (Mo+1) - (Mo+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo553, thermo553, perdev553*100, dev553*100);
		fprintf(OutFile, "| (Mo+0) - (Mo+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo554, thermo554, perdev554*100, dev554*100);
		fprintf(OutFile, "| Counter of sign errors             | Mo     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Mocounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Tc+7) - (Tc+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo555, thermo555, perdev555*100, dev555*100);
		fprintf(OutFile, "| (Tc+6) - (Tc+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo556, thermo556, perdev556*100, dev556*100);
		fprintf(OutFile, "| (Tc+5) - (Tc+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo557, thermo557, perdev557*100, dev557*100);
		fprintf(OutFile, "| (Tc+4) - (Tc+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo558, thermo558, perdev558*100, dev558*100);
		fprintf(OutFile, "| (Tc+3) - (Tc+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo559, thermo559, perdev559*100, dev559*100);
		fprintf(OutFile, "| (Tc+2) - (Tc+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo560, thermo560, perdev560*100, dev560*100);
		fprintf(OutFile, "| (Tc+1ex) - (Tc+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo561, thermo561, perdev561*100, dev561*100);
		fprintf(OutFile, "| (Tc+1) - (Tc+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo562, thermo562, perdev562*100, dev562*100);
		fprintf(OutFile, "| (Tc+0ex) - (Tc+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo563, thermo563, perdev563*100, dev563*100);
		fprintf(OutFile, "| (Tc+0ex2) - (Tc+0)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo564, thermo564, perdev564*100, dev564*100);
		fprintf(OutFile, "| (Tc+0) - (Tc+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo565, thermo565, perdev565*100, dev565*100);
		fprintf(OutFile, "| (Tc+6) - (Tc+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo566, thermo566, perdev566*100, dev566*100);
		fprintf(OutFile, "| (Tc+5) - (Tc+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo567, thermo567, perdev567*100, dev567*100);
		fprintf(OutFile, "| (Tc+4) - (Tc+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo568, thermo568, perdev568*100, dev568*100);
		fprintf(OutFile, "| (Tc+3) - (Tc+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo569, thermo569, perdev569*100, dev569*100);
		fprintf(OutFile, "| (Tc+2) - (Tc+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo570, thermo570, perdev570*100, dev570*100);
		fprintf(OutFile, "| (Tc+1) - (Tc+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo571, thermo571, perdev571*100, dev571*100);
		fprintf(OutFile, "| (Tc+0) - (Tc+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo572, thermo572, perdev572*100, dev572*100);
		fprintf(OutFile, "| Counter of sign errors             | Tc     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Tccounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Ru+8) - (Ru+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo573, thermo573, perdev573*100, dev573*100);
		fprintf(OutFile, "| (Ru+7) - (Ru+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo574, thermo574, perdev574*100, dev574*100);
		fprintf(OutFile, "| (Ru+6) - (Ru+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo575, thermo575, perdev575*100, dev575*100);
		fprintf(OutFile, "| (Ru+5) - (Ru+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo576, thermo576, perdev576*100, dev576*100);
		fprintf(OutFile, "| (Ru+4) - (Ru+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo577, thermo577, perdev577*100, dev577*100);
		fprintf(OutFile, "| (Ru+3) - (Ru+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo578, thermo578, perdev578*100, dev578*100);
		fprintf(OutFile, "| (Ru+2ex) - (Ru+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo579, thermo579, perdev579*100, dev579*100);
		fprintf(OutFile, "| (Ru+2) - (Ru+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo580, thermo580, perdev580*100, dev580*100);
		fprintf(OutFile, "| (Ru+1ex) - (Ru+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo581, thermo581, perdev581*100, dev581*100);
		fprintf(OutFile, "| (Ru+1ex2) - (Ru+1)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo582, thermo582, perdev582*100, dev582*100);
		fprintf(OutFile, "| (Ru+1) - (Ru+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo583, thermo583, perdev583*100, dev583*100);
		fprintf(OutFile, "| (Ru+0ex) - (Ru+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo584, thermo584, perdev584*100, dev584*100);
		fprintf(OutFile, "| (Ru+0ex2) - (Ru+0)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo585, thermo585, perdev585*100, dev585*100);
		fprintf(OutFile, "| (Ru+7) - (Ru+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo586, thermo586, perdev586*100, dev586*100);
		fprintf(OutFile, "| (Ru+6) - (Ru+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo587, thermo587, perdev587*100, dev587*100);
		fprintf(OutFile, "| (Ru+5) - (Ru+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo588, thermo588, perdev588*100, dev588*100);
		fprintf(OutFile, "| (Ru+4) - (Ru+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo589, thermo589, perdev589*100, dev589*100);
		fprintf(OutFile, "| (Ru+3) - (Ru+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo590, thermo590, perdev590*100, dev590*100);
		fprintf(OutFile, "| (Ru+2) - (Ru+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo591, thermo591, perdev591*100, dev591*100);
		fprintf(OutFile, "| (Ru+1) - (Ru+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo592, thermo592, perdev592*100, dev592*100);
		fprintf(OutFile, "| (Ru+0) - (Ru+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo593, thermo593, perdev593*100, dev593*100);
		fprintf(OutFile, "| Counter of sign errors             | Ru     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Rucounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Rh+9) - (Rh+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo594, thermo594, perdev594*100, dev594*100);
		fprintf(OutFile, "| (Rh+8) - (Rh+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo595, thermo595, perdev595*100, dev595*100);
		fprintf(OutFile, "| (Rh+7) - (Rh+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo596, thermo596, perdev596*100, dev596*100);
		fprintf(OutFile, "| (Rh+6) - (Rh+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo597, thermo597, perdev597*100, dev597*100);
		fprintf(OutFile, "| (Rh+5) - (Rh+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo598, thermo598, perdev598*100, dev598*100);
		fprintf(OutFile, "| (Rh+4) - (Rh+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo599, thermo599, perdev599*100, dev599*100);
		fprintf(OutFile, "| (Rh+3) - (Rh+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo600, thermo600, perdev600*100, dev600*100);
		fprintf(OutFile, "| (Rh+2ex) - (Rh+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo601, thermo601, perdev601*100, dev601*100);
		fprintf(OutFile, "| (Rh+2ex2) - (Rh+2)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo602, thermo602, perdev602*100, dev602*100);
		fprintf(OutFile, "| (Rh+2) - (Rh+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo603, thermo603, perdev603*100, dev603*100);
		fprintf(OutFile, "| (Rh+1ex) - (Rh+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo604, thermo604, perdev604*100, dev604*100);
		fprintf(OutFile, "| (Rh+1ex2) - (Rh+1)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo605, thermo605, perdev605*100, dev605*100);
		fprintf(OutFile, "| (Rh+1) - (Rh+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo606, thermo606, perdev606*100, dev606*100);
		fprintf(OutFile, "| (Rh+0ex) - (Rh+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo607, thermo607, perdev607*100, dev607*100);
		fprintf(OutFile, "| (Rh+8) - (Rh+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo608, thermo608, perdev608*100, dev608*100);
		fprintf(OutFile, "| (Rh+7) - (Rh+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo609, thermo609, perdev609*100, dev609*100);
		fprintf(OutFile, "| (Rh+6) - (Rh+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo610, thermo610, perdev610*100, dev610*100);
		fprintf(OutFile, "| (Rh+5) - (Rh+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo611, thermo611, perdev611*100, dev611*100);
		fprintf(OutFile, "| (Rh+4) - (Rh+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo612, thermo612, perdev612*100, dev612*100);
		fprintf(OutFile, "| (Rh+3) - (Rh+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo613, thermo613, perdev613*100, dev613*100);
		fprintf(OutFile, "| (Rh+2) - (Rh+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo614, thermo614, perdev614*100, dev614*100);
		fprintf(OutFile, "| (Rh+1) - (Rh+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo615, thermo615, perdev615*100, dev615*100);
		fprintf(OutFile, "| (Rh+0) - (Rh+9)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo616, thermo616, perdev616*100, dev616*100);
		fprintf(OutFile, "| Counter of sign errors             | Rh     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Rhcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Pd+10) - (Pd+9)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo617, thermo617, perdev617*100, dev617*100);
		fprintf(OutFile, "| (Pd+9) - (Pd+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo618, thermo618, perdev618*100, dev618*100);
		fprintf(OutFile, "| (Pd+8) - (Pd+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo619, thermo619, perdev619*100, dev619*100);
		fprintf(OutFile, "| (Pd+7) - (Pd+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo620, thermo620, perdev620*100, dev620*100);
		fprintf(OutFile, "| (Pd+6) - (Pd+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo621, thermo621, perdev621*100, dev621*100);
		fprintf(OutFile, "| (Pd+5) - (Pd+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo622, thermo622, perdev622*100, dev622*100);
		fprintf(OutFile, "| (Pd+4) - (Pd+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo623, thermo623, perdev623*100, dev623*100);
		fprintf(OutFile, "| (Pd+3) - (Pd+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo624, thermo624, perdev624*100, dev624*100);
		fprintf(OutFile, "| (Pd+2ex) - (Pd+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo625, thermo625, perdev625*100, dev625*100);
		fprintf(OutFile, "| (Pd+2ex2) - (Pd+2)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo626, thermo626, perdev626*100, dev626*100);
		fprintf(OutFile, "| (Pd+2) - (Pd+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo627, thermo627, perdev627*100, dev627*100);
		fprintf(OutFile, "| (Pd+1ex) - (Pd+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo628, thermo628, perdev628*100, dev628*100);
		fprintf(OutFile, "| (Pd+1) - (Pd+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo629, thermo629, perdev629*100, dev629*100);
		fprintf(OutFile, "| (Pd+0ex) - (Pd+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo630, thermo630, perdev630*100, dev630*100);
		fprintf(OutFile, "| (Pd+9) - (Pd+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo631, thermo631, perdev631*100, dev631*100);
		fprintf(OutFile, "| (Pd+8) - (Pd+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo632, thermo632, perdev632*100, dev632*100);
		fprintf(OutFile, "| (Pd+7) - (Pd+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo633, thermo633, perdev633*100, dev633*100);
		fprintf(OutFile, "| (Pd+6) - (Pd+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo634, thermo634, perdev634*100, dev634*100);
		fprintf(OutFile, "| (Pd+5) - (Pd+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo635, thermo635, perdev635*100, dev635*100);
		fprintf(OutFile, "| (Pd+4) - (Pd+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo636, thermo636, perdev636*100, dev636*100);
		fprintf(OutFile, "| (Pd+3) - (Pd+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo637, thermo637, perdev637*100, dev637*100);
		fprintf(OutFile, "| (Pd+2) - (Pd+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo638, thermo638, perdev638*100, dev638*100);
		fprintf(OutFile, "| (Pd+1) - (Pd+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo639, thermo639, perdev639*100, dev639*100);
		fprintf(OutFile, "| (Pd+0) - (Pd+10)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo640, thermo640, perdev640*100, dev640*100);
		fprintf(OutFile, "| Counter of sign errors             | Pd     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Pdcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Ag+11) - (Ag+10)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo641, thermo641, perdev641*100, dev641*100);
		fprintf(OutFile, "| (Ag+10) - (Ag+9)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo642, thermo642, perdev642*100, dev642*100);
		fprintf(OutFile, "| (Ag+9) - (Ag+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo643, thermo643, perdev643*100, dev643*100);
		fprintf(OutFile, "| (Ag+8) - (Ag+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo644, thermo644, perdev644*100, dev644*100);
		fprintf(OutFile, "| (Ag+7) - (Ag+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo645, thermo645, perdev645*100, dev645*100);
		fprintf(OutFile, "| (Ag+6) - (Ag+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo646, thermo646, perdev646*100, dev646*100);
		fprintf(OutFile, "| (Ag+5) - (Ag+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo647, thermo647, perdev647*100, dev647*100);
		fprintf(OutFile, "| (Ag+4) - (Ag+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo648, thermo648, perdev648*100, dev648*100);
		fprintf(OutFile, "| (Ag+3) - (Ag+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo649, thermo649, perdev649*100, dev649*100);
		fprintf(OutFile, "| (Ag+2ex) - (Ag+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo650, thermo650, perdev650*100, dev650*100);
		fprintf(OutFile, "| (Ag+2) - (Ag+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo651, thermo651, perdev651*100, dev651*100);
		fprintf(OutFile, "| (Ag+1ex) - (Ag+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo652, thermo652, perdev652*100, dev652*100);
		fprintf(OutFile, "| (Ag+1) - (Ag+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo653, thermo653, perdev653*100, dev653*100);
		fprintf(OutFile, "| (Ag+0ex) - (Ag+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo654, thermo654, perdev654*100, dev654*100);
		fprintf(OutFile, "| (Ag+10) - (Ag+11)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo655, thermo655, perdev655*100, dev655*100);
		fprintf(OutFile, "| (Ag+9) - (Ag+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo656, thermo656, perdev656*100, dev656*100);
		fprintf(OutFile, "| (Ag+8) - (Ag+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo657, thermo657, perdev657*100, dev657*100);
		fprintf(OutFile, "| (Ag+7) - (Ag+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo658, thermo658, perdev658*100, dev658*100);
		fprintf(OutFile, "| (Ag+6) - (Ag+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo659, thermo659, perdev659*100, dev659*100);
		fprintf(OutFile, "| (Ag+5) - (Ag+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo660, thermo660, perdev660*100, dev660*100);
		fprintf(OutFile, "| (Ag+4) - (Ag+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo661, thermo661, perdev661*100, dev661*100);
		fprintf(OutFile, "| (Ag+3) - (Ag+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo662, thermo662, perdev662*100, dev662*100);
		fprintf(OutFile, "| (Ag+2) - (Ag+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo663, thermo663, perdev663*100, dev663*100);
		fprintf(OutFile, "| (Ag+1) - (Ag+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo664, thermo664, perdev664*100, dev664*100);
		fprintf(OutFile, "| (Ag+0) - (Ag+11)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo665, thermo665, perdev665*100, dev665*100);
		fprintf(OutFile, "| Counter of sign errors             | Ag     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Agcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
		fprintf(OutFile, "| (Cd+12) - (Cd+11)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo666, thermo666, perdev666*100, dev666*100);
		fprintf(OutFile, "| (Cd+11) - (Cd+10)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo667, thermo667, perdev667*100, dev667*100);
		fprintf(OutFile, "| (Cd+10) - (Cd+9)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo668, thermo668, perdev668*100, dev668*100);
		fprintf(OutFile, "| (Cd+9) - (Cd+8)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo669, thermo669, perdev669*100, dev669*100);
		fprintf(OutFile, "| (Cd+8) - (Cd+7)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo670, thermo670, perdev670*100, dev670*100);
		fprintf(OutFile, "| (Cd+7) - (Cd+6)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo671, thermo671, perdev671*100, dev671*100);
		fprintf(OutFile, "| (Cd+6) - (Cd+5)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo672, thermo672, perdev672*100, dev672*100);
		fprintf(OutFile, "| (Cd+5) - (Cd+4)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo673, thermo673, perdev673*100, dev673*100);
		fprintf(OutFile, "| (Cd+4) - (Cd+3)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo674, thermo674, perdev674*100, dev674*100);
		fprintf(OutFile, "| (Cd+3ex) - (Cd+3)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo675, thermo675, perdev675*100, dev675*100);
		fprintf(OutFile, "| (Cd+3) - (Cd+2)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo676, thermo676, perdev676*100, dev676*100);
		fprintf(OutFile, "| (Cd+2ex) - (Cd+2)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo677, thermo677, perdev677*100, dev677*100);
		fprintf(OutFile, "| (Cd+2) - (Cd+1)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo678, thermo678, perdev678*100, dev678*100);
		fprintf(OutFile, "| (Cd+1ex) - (Cd+1)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo679, thermo679, perdev679*100, dev679*100);
		fprintf(OutFile, "| (Cd+1) - (Cd+0)                    | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo680, thermo680, perdev680*100, dev680*100);
		fprintf(OutFile, "| (Cd+0ex) - (Cd+0)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo681, thermo681, perdev681*100, dev681*100);
		fprintf(OutFile, "| (Cd+11) - (Cd+12)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo682, thermo682, perdev682*100, dev682*100);
		fprintf(OutFile, "| (Cd+10) - (Cd+12)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo683, thermo683, perdev683*100, dev683*100);
		fprintf(OutFile, "| (Cd+9) - (Cd+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo684, thermo684, perdev684*100, dev684*100);
		fprintf(OutFile, "| (Cd+8) - (Cd+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo685, thermo685, perdev685*100, dev685*100);
		fprintf(OutFile, "| (Cd+7) - (Cd+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo686, thermo686, perdev686*100, dev686*100);
		fprintf(OutFile, "| (Cd+6) - (Cd+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo687, thermo687, perdev687*100, dev687*100);
		fprintf(OutFile, "| (Cd+5) - (Cd+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo688, thermo688, perdev688*100, dev688*100);
		fprintf(OutFile, "| (Cd+4) - (Cd+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo689, thermo689, perdev689*100, dev689*100);
		fprintf(OutFile, "| (Cd+3) - (Cd+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo690, thermo690, perdev690*100, dev690*100);
		fprintf(OutFile, "| (Cd+2) - (Cd+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo691, thermo691, perdev691*100, dev691*100);
		fprintf(OutFile, "| (Cd+1) - (Cd+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo692, thermo692, perdev692*100, dev692*100);
		fprintf(OutFile, "| (Cd+0) - (Cd+12)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo693, thermo693, perdev693*100, dev693*100);
		fprintf(OutFile, "| Counter of sign errors             | Cd     |   % 10d    |       n.a.       |        n.a.      |       n.a.        |\n", Cdcounter);
		fprintf(OutFile, "|------------------------------------|--------|-----------------|------------------|------------------|-------------------|\n");
//		fprintf(OutFile, "| (O- & O-) - (O2-2)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo12, thermo12, perdev12*100, dev12*100);
//		fprintf(OutFile, "| (O- & O) - (O2-)                   | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo13, thermo13, perdev13*100, dev13*100);
//		fprintf(OutFile, "| (O & O) - (O2)                     | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo14, thermo14, perdev14*100, dev14*100);
//		fprintf(OutFile, "| (OH* & H+) - (H2O+)                | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo15, thermo15, perdev15*100, dev15*100);
//		fprintf(OutFile, "| (O- & H+) - (OH*)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo16, thermo16, perdev16*100, dev16*100);
//		fprintf(OutFile, "| (O & H ) -  (OH*)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo20, thermo20, perdev20*100, dev20*100);
//         	fprintf(OutFile, "| (OH- & H+) - (H2O)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo2, thermo2, perdev2*100, dev2*100);
//		fprintf(OutFile, "| (H2O & H+) - (H3O)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo3, thermo3, perdev3*100, dev3*100);
//		fprintf(OutFile, "| (O-2 & H+) - (OH-)                 | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo4, thermo4, perdev4*100, dev4*100);
//		fprintf(OutFile, "| (OH* & H) - (H2O)                  | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo7, thermo7, perdev7*100, dev7*100);
//		fprintf(OutFile, "| (H2O..H2O) - (H2O & H2O)           | kJ/mol |   % 10.2f    |    % 10.2f    |    % 10.2f    |    % 10.2f     |\n", LitThermo17, thermo17, perdev17*100, dev17*100);
		fprintf(OutFile, "|=========================================================================================================================|\n");
		fclose(OutFile);

		// Print thermos in seperated files
/*
		strcpy(plot, directory);
		strcat(plot, ".oxy");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "1.0 %f\n",LitThermo38);
		fprintf(OutFile, "1.8 %f\n",LitThermo42+LitThermo37);
		fprintf(OutFile, "2.0 %f\n",LitThermo37);
		fprintf(OutFile, "2.8 %f\n",LitThermo30+LitThermo36);
		fprintf(OutFile, "3.0 %f\n",LitThermo36);
		fprintf(OutFile, "3.6 %f\n",LitThermo123);
		fprintf(OutFile, "3.8 %f\n",LitThermo40+LitThermo35);
		fprintf(OutFile, "4.0 %f\n",LitThermo35);
		fprintf(OutFile, "4.6 %f\n",LitThermo157+LitThermo34);
		fprintf(OutFile, "4.8 %f\n",LitThermo41+LitThermo34);
		fprintf(OutFile, "5.0 %f\n",LitThermo34);
		fprintf(OutFile, "5.6 %f\n",LitThermo156+LitThermo33);
		fprintf(OutFile, "5.8 %f\n",LitThermo39+LitThermo33);
		fprintf(OutFile, "6.0 %f\n",LitThermo33);
		fprintf(OutFile, "7.0 %f\n",LitThermo32);
		//      fprintf(OutFile, "8.0 %f\n",LitThermo31);


		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "1.0 %f\n",thermo38);
		fprintf(OutFile, "1.8 %f\n",thermo42+U_spinOplus4);
		fprintf(OutFile, "2.0 %f\n",thermo37);
		fprintf(OutFile, "2.8 %f\n",thermo30+U_spinOplus3);
		fprintf(OutFile, "3.0 %f\n",thermo36);
		fprintf(OutFile, "3.6 %f\n",thermo122+U_spinOplus2);
		fprintf(OutFile, "3.8 %f\n",thermo40+U_spinOplus2);
		fprintf(OutFile, "4.0 %f\n",thermo35);
		fprintf(OutFile, "4.6 %f\n",thermo157+U_spinOplus1);
		fprintf(OutFile, "4.8 %f\n",thermo41+U_spinOplus1);
		fprintf(OutFile, "5.0 %f\n",thermo34);
		fprintf(OutFile, "5.6 %f\n",thermo156+U_spinOneutrl);
		fprintf(OutFile, "5.8 %f\n",thermo39+U_spinOneutrl);
		fprintf(OutFile, "6.0 %f\n",thermo33);
		fprintf(OutFile, "7.0 %f\n",thermo32);
		//	fprintf(OutFile, "8.0 %f\n",thermo31);


		fprintf(OutFile,"\n\n\n");

		fclose(OutFile);


		strcpy(plot, directory);
		strcat(plot, ".flu");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "1.0 %f\n",LitThermo109);
		fprintf(OutFile, "1.8 %f\n",LitThermo135+LitThermo110);
		fprintf(OutFile, "2.0 %f\n",LitThermo110);
		fprintf(OutFile, "2.8 %f\n",LitThermo136+LitThermo111);
		fprintf(OutFile, "3.0 %f\n",LitThermo111);
		fprintf(OutFile, "3.6 %f\n",LitThermo138+LitThermo112);
		fprintf(OutFile, "3.8 %f\n",LitThermo137+LitThermo112);
		fprintf(OutFile, "4.0 %f\n",LitThermo112);
		fprintf(OutFile, "4.6 %f\n",LitThermo161+LitThermo113);
		fprintf(OutFile, "4.8 %f\n",LitThermo139+LitThermo113);
		fprintf(OutFile, "5.0 %f\n",LitThermo113);
		fprintf(OutFile, "5.6 %f\n",LitThermo160+LitThermo114);
		fprintf(OutFile, "5.8 %f\n",LitThermo140+LitThermo114);
		fprintf(OutFile, "6.0 %f\n",LitThermo114);
		fprintf(OutFile, "6.8 %f\n",LitThermo159+LitThermo115);
		fprintf(OutFile, "7.0 %f\n",LitThermo115);
		fprintf(OutFile, "8.0 %f\n",LitThermo116);



		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "1.0 %f\n",thermo109);
		fprintf(OutFile, "1.8 %f\n",thermo135+U_spinFplus5);
		fprintf(OutFile, "2.0 %f\n",thermo110);
		fprintf(OutFile, "2.8 %f\n",thermo136+U_spinFplus4);
		fprintf(OutFile, "3.0 %f\n",thermo111);
		fprintf(OutFile, "3.6 %f\n",thermo138+U_spinFplus3);
		fprintf(OutFile, "3.8 %f\n",thermo137+U_spinFplus3);
		fprintf(OutFile, "4.0 %f\n",thermo112);
		fprintf(OutFile, "4.6 %f\n",thermo161+U_spinFplus2);
		fprintf(OutFile, "4.8 %f\n",thermo139+U_spinFplus2);
		fprintf(OutFile, "5.0 %f\n",thermo113);
		fprintf(OutFile, "5.6 %f\n",thermo160+U_spinFplus);
		fprintf(OutFile, "5.8 %f\n",thermo140+U_spinFplus);
		fprintf(OutFile, "6.0 %f\n",thermo114);
		fprintf(OutFile, "6.8 %f\n",thermo159+U_spinFneutrl);
		fprintf(OutFile, "7.0 %f\n",thermo115);
		fprintf(OutFile, "8.0 %f\n",thermo116);


		fprintf(OutFile,"\n\n\n");

		fclose(OutFile);



		// plot of ionization and excitation energies
		strcpy(plot, directory);
		strcat(plot, ".oxy2");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",-LitThermo28);
		fprintf(OutFile, "1.5 %f\n",-LitThermo27);
		fprintf(OutFile, "2.0 %f\n",LitThermo42);
		fprintf(OutFile, "2.5 %f\n",-LitThermo26);
		fprintf(OutFile, "3.0 %f\n",LitThermo30);
		fprintf(OutFile, "3.5 %f\n",-LitThermo25);
		fprintf(OutFile, "4.0 %f\n",LitThermo40);
		fprintf(OutFile, "4.0 %f\n",LitThermo122);
		fprintf(OutFile, "4.5 %f\n",-LitThermo24);
		fprintf(OutFile, "5.0 %f\n",LitThermo41);
		fprintf(OutFile, "5.0 %f\n",LitThermo157);
		fprintf(OutFile, "5.5 %f\n",-LitThermo23);
		fprintf(OutFile, "6.0 %f\n",LitThermo39);
		fprintf(OutFile, "6.0 %f\n",LitThermo156);
		fprintf(OutFile, "6.5 %f\n",-LitThermo22);


		fprintf(OutFile,"\n\n\n");


		//Printing model values ionization and first excitation
		fprintf(OutFile, "0.5 %f\n",-thermo28);
		fprintf(OutFile, "1.5 %f\n",-thermo27);
		fprintf(OutFile, "2.0 %f\n",thermo42);
		fprintf(OutFile, "2.5 %f\n",-thermo26);
		fprintf(OutFile, "3.0 %f\n",thermo30);
		fprintf(OutFile, "3.5 %f\n",-thermo25);
		fprintf(OutFile, "4.0 %f\n",thermo40);
		fprintf(OutFile, "4.5 %f\n",-thermo24);
		fprintf(OutFile, "5.0 %f\n",thermo41);
		fprintf(OutFile, "5.5 %f\n",-thermo23);
		fprintf(OutFile, "6.0 %f\n",thermo39);
		fprintf(OutFile, "6.5 %f\n",-thermo22);

		fprintf(OutFile,"\n\n\n");

		//printing model values of second exc. energies
		fprintf(OutFile, "4.0 %f\n",thermo122);
		fprintf(OutFile, "5.0 %f\n",thermo157);
		fprintf(OutFile, "6.0 %f\n",thermo156);

		//      fprintf(OutFile, "8.0 %f\n",thermo31);



		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".flu2");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",-LitThermo72);
		fprintf(OutFile, "1.5 %f\n",-LitThermo73);
		fprintf(OutFile, "2.0 %f\n",LitThermo135);
		fprintf(OutFile, "2.5 %f\n",-LitThermo74);
		fprintf(OutFile, "3.0 %f\n",LitThermo136);
		fprintf(OutFile, "3.5 %f\n",-LitThermo75);
		fprintf(OutFile, "4.0 %f\n",LitThermo138);
		fprintf(OutFile, "4.0 %f\n",LitThermo137);
		fprintf(OutFile, "4.5 %f\n",-LitThermo76);
		fprintf(OutFile, "5.0 %f\n",LitThermo161);
		fprintf(OutFile, "5.0 %f\n",LitThermo139);
		fprintf(OutFile, "5.5 %f\n",-LitThermo77);
		fprintf(OutFile, "6.0 %f\n",LitThermo160);
		fprintf(OutFile, "6.0 %f\n",LitThermo140);
		fprintf(OutFile, "6.5 %f\n",-LitThermo78);
		fprintf(OutFile, "7.0 %f\n",LitThermo159);
		fprintf(OutFile, "7.5 %f\n",-LitThermo79);

		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "0.5 %f\n",-thermo72);
		fprintf(OutFile, "1.5 %f\n",-thermo73);
		fprintf(OutFile, "2.0 %f\n",thermo135);
		fprintf(OutFile, "2.5 %f\n",-thermo74);
		fprintf(OutFile, "3.0 %f\n",thermo136);
		fprintf(OutFile, "3.5 %f\n",-thermo75);
		fprintf(OutFile, "4.0 %f\n",thermo137);
		fprintf(OutFile, "4.5 %f\n",-thermo76);
		fprintf(OutFile, "5.0 %f\n",thermo139);
		fprintf(OutFile, "5.5 %f\n",-thermo77);
		fprintf(OutFile, "6.0 %f\n",thermo140);
		fprintf(OutFile, "6.5 %f\n",-thermo78);
		fprintf(OutFile, "7.0 %f\n",thermo159);
		fprintf(OutFile, "7.5 %f\n",-thermo79);


		fprintf(OutFile,"\n\n\n");

		fprintf(OutFile, "4.0 %f\n",thermo138);
		fprintf(OutFile, "5.0 %f\n",thermo161);
		fprintf(OutFile, "6.0 %f\n",thermo160);

		fprintf(OutFile,"\n\n\n");


		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".bor");

		OutFile = fopen(plot, "a");

		fprintf(OutFile, "1.0 %f\n",LitThermo170);
		fprintf(OutFile, "1.8 %f\n",LitThermo168+LitThermo171);
		fprintf(OutFile, "2.0 %f\n",LitThermo171);
		fprintf(OutFile, "2.8 %f\n",LitThermo169+LitThermo172);
		fprintf(OutFile, "3.0 %f\n",LitThermo172);
		fprintf(OutFile, "4.0 %f\n",LitThermo173);



		fprintf(OutFile,"\n\n\n");


		fprintf(OutFile, "1.0 %f\n",thermo170);
		fprintf(OutFile, "1.8 %f\n",thermo168+U_spinBplus);
		fprintf(OutFile, "2.0 %f\n",thermo171);
		fprintf(OutFile, "2.8 %f\n",thermo169+U_spinBneutrl);
		fprintf(OutFile, "3.0 %f\n",thermo172);
		fprintf(OutFile, "4.0 %f\n",thermo173);

		fprintf(OutFile,"\n\n\n");

		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".bor2");

		OutFile = fopen(plot, "a");


		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",-LitThermo164);
		fprintf(OutFile, "1.5 %f\n",-LitThermo165);
		fprintf(OutFile, "2.0 %f\n",LitThermo168);
		fprintf(OutFile, "2.5 %f\n",-LitThermo166);
		fprintf(OutFile, "3.0 %f\n",LitThermo169);
		fprintf(OutFile, "3.5 %f\n",-LitThermo167);

		fprintf(OutFile,"\n\n\n");

		fprintf(OutFile, "0.5 %f\n",-thermo164);
		fprintf(OutFile, "1.5 %f\n",-thermo165);
		fprintf(OutFile, "2.0 %f\n",thermo168);
		fprintf(OutFile, "2.5 %f\n",-thermo166);
		fprintf(OutFile, "3.0 %f\n",thermo169);
		fprintf(OutFile, "3.5 %f\n",-thermo167);
		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);



		strcpy(plot, directory);
		strcat(plot, ".car");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "1.0 %f\n",LitThermo80);
		fprintf(OutFile, "1.8 %f\n",LitThermo126+LitThermo81);
		fprintf(OutFile, "2.0 %f\n",LitThermo81);
		fprintf(OutFile, "2.8 %f\n",LitThermo127+LitThermo82);
		fprintf(OutFile, "3.0 %f\n",LitThermo82);
		fprintf(OutFile, "3.6 %f\n",LitThermo129+LitThermo83);
		fprintf(OutFile, "3.8 %f\n",LitThermo128+LitThermo83);
		fprintf(OutFile, "4.0 %f\n",LitThermo83);
		fprintf(OutFile, "5.0 %f\n",LitThermo84);



		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "1.0 %f\n",thermo80);
		fprintf(OutFile, "1.8 %f\n",thermo126+U_spinCplus2);
		fprintf(OutFile, "2.0 %f\n",thermo81);
		fprintf(OutFile, "2.8 %f\n",thermo127+U_spinCplus);
		fprintf(OutFile, "3.0 %f\n",thermo82);
		fprintf(OutFile, "3.6 %f\n",thermo129+U_spinCneutrl);
		fprintf(OutFile, "3.8 %f\n",thermo128+U_spinCneutrl);
		fprintf(OutFile, "4.0 %f\n",thermo83);
		fprintf(OutFile, "5.0 %f\n",thermo84);


		fprintf(OutFile,"\n\n\n");

		fclose(OutFile);


		strcpy(plot, directory);
		strcat(plot, ".car2");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",-LitThermo43);
		fprintf(OutFile, "1.5 %f\n",-LitThermo44);
		fprintf(OutFile, "2.0 %f\n",LitThermo126);
		fprintf(OutFile, "2.5 %f\n",-LitThermo45);
		fprintf(OutFile, "3.0 %f\n",LitThermo127);
		fprintf(OutFile, "3.5 %f\n",-LitThermo46);
		fprintf(OutFile, "4.0 %f\n",LitThermo128);
		fprintf(OutFile, "4.0 %f\n",LitThermo129);
		fprintf(OutFile, "4.5 %f\n",-LitThermo47);

		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "0.5 %f\n",-thermo43);
		fprintf(OutFile, "1.5 %f\n",-thermo44);
		fprintf(OutFile, "2.0 %f\n",thermo126);
		fprintf(OutFile, "2.5 %f\n",-thermo45);
		fprintf(OutFile, "3.0 %f\n",thermo127);
		fprintf(OutFile, "3.5 %f\n",-thermo46);
		fprintf(OutFile, "4.0 %f\n",thermo128);
		fprintf(OutFile, "4.5 %f\n",-thermo47);

		fprintf(OutFile,"\n\n\n");

		fprintf(OutFile, "4.0 %f\n",thermo129);

		fprintf(OutFile,"\n\n\n");


		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".sul");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "1.0 %f\n",LitThermo91);
		fprintf(OutFile, "1.8 %f\n",LitThermo150+LitThermo92);
		fprintf(OutFile, "2.0 %f\n",LitThermo92);
		fprintf(OutFile, "2.8 %f\n",LitThermo151+LitThermo93);
		fprintf(OutFile, "3.0 %f\n",LitThermo93);
		fprintf(OutFile, "3.6 %f\n",LitThermo153+LitThermo94);
		fprintf(OutFile, "3.8 %f\n",LitThermo152+LitThermo94);
		fprintf(OutFile, "4.0 %f\n",LitThermo94);
		fprintf(OutFile, "4.8 %f\n",LitThermo154+LitThermo95);
		fprintf(OutFile, "5.0 %f\n",LitThermo95);
		fprintf(OutFile, "5.6 %f\n",LitThermo162+LitThermo96);
		fprintf(OutFile, "5.8 %f\n",LitThermo155+LitThermo96);
		fprintf(OutFile, "6.0 %f\n",LitThermo96);
		fprintf(OutFile, "7.0 %f\n",LitThermo97);
		//      fprintf(OutFile, "8.0 %f\n",LitThermo31);


		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "1.0 %f\n",thermo91);
		fprintf(OutFile, "1.8 %f\n",thermo150+U_spinSplus4);
		fprintf(OutFile, "2.0 %f\n",thermo92);
		fprintf(OutFile, "2.8 %f\n",thermo151+U_spinSplus3);
		fprintf(OutFile, "3.0 %f\n",thermo93);
		fprintf(OutFile, "3.6 %f\n",thermo153+U_spinSplus2);
		fprintf(OutFile, "3.8 %f\n",thermo152+U_spinSplus2);
		fprintf(OutFile, "4.0 %f\n",thermo94);
		fprintf(OutFile, "4.8 %f\n",thermo154+U_spinSplus);
		fprintf(OutFile, "5.0 %f\n",thermo95);
		fprintf(OutFile, "5.6 %f\n",thermo162+U_spinSneutrl);
		fprintf(OutFile, "5.8 %f\n",thermo155+U_spinSneutrl);
		fprintf(OutFile, "6.0 %f\n",thermo96);
		fprintf(OutFile, "7.0 %f\n",thermo97);
		//      fprintf(OutFile, "8.0 %f\n",thermo31);


		fprintf(OutFile,"\n\n\n");

		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".sul2");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",-LitThermo54);
		fprintf(OutFile, "1.5 %f\n",-LitThermo55);
		fprintf(OutFile, "2.0 %f\n",LitThermo150);
		fprintf(OutFile, "2.5 %f\n",-LitThermo56);
		fprintf(OutFile, "3.0 %f\n",LitThermo151);
		fprintf(OutFile, "3.5 %f\n",-LitThermo57);
		fprintf(OutFile, "4.0 %f\n",LitThermo153);
		fprintf(OutFile, "4.0 %f\n",LitThermo152);
		fprintf(OutFile, "4.5 %f\n",-LitThermo58);
		fprintf(OutFile, "5.0 %f\n",LitThermo154);
		fprintf(OutFile, "5.5 %f\n",-LitThermo59);
		fprintf(OutFile, "6.0 %f\n",LitThermo162);
		fprintf(OutFile, "6.0 %f\n",LitThermo155);
		fprintf(OutFile, "6.5 %f\n",-LitThermo60);


		fprintf(OutFile,"\n\n\n");

		//Printing model values ionization and first excitation
		fprintf(OutFile, "0.5 %f\n",-thermo54);
		fprintf(OutFile, "1.5 %f\n",-thermo55);
		fprintf(OutFile, "2.0 %f\n",thermo150);
		fprintf(OutFile, "2.5 %f\n",-thermo56);
		fprintf(OutFile, "3.0 %f\n",thermo151);
		fprintf(OutFile, "3.5 %f\n",-thermo57);
		fprintf(OutFile, "4.0 %f\n",thermo152);
		fprintf(OutFile, "4.5 %f\n",-thermo58);
		fprintf(OutFile, "5.0 %f\n",thermo154);
		fprintf(OutFile, "5.5 %f\n",-thermo59);
		fprintf(OutFile, "6.0 %f\n",thermo155);
		fprintf(OutFile, "6.5 %f\n",-thermo60);

		fprintf(OutFile,"\n\n\n");

		//printing model values of second exc. energies
		fprintf(OutFile, "4.0 %f\n",thermo153);
		fprintf(OutFile, "6.0 %f\n",thermo162);

		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".pho");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "1.0 %f\n",LitThermo98);
		fprintf(OutFile, "1.8 %f\n",LitThermo145+LitThermo99);
		fprintf(OutFile, "2.0 %f\n",LitThermo99);
		fprintf(OutFile, "2.8 %f\n",LitThermo146+LitThermo100);
		fprintf(OutFile, "3.0 %f\n",LitThermo100);
		fprintf(OutFile, "3.6 %f\n",LitThermo148+LitThermo101);
		fprintf(OutFile, "3.8 %f\n",LitThermo147+LitThermo101);
		fprintf(OutFile, "4.0 %f\n",LitThermo101);
		fprintf(OutFile, "4.8 %f\n",LitThermo149+LitThermo102);
		fprintf(OutFile, "5.0 %f\n",LitThermo102);
		fprintf(OutFile, "6.0 %f\n",LitThermo103);
		//      fprintf(OutFile, "8.0 %f\n",LitThermo31);


		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "1.0 %f\n",thermo98);
		fprintf(OutFile, "1.8 %f\n",thermo145+U_spinPplus3);
		fprintf(OutFile, "2.0 %f\n",thermo99);
		fprintf(OutFile, "2.8 %f\n",thermo146+U_spinPplus2);
		fprintf(OutFile, "3.0 %f\n",thermo100);
		fprintf(OutFile, "3.6 %f\n",thermo148+U_spinPplus);
		fprintf(OutFile, "3.8 %f\n",thermo147+U_spinPplus);
		fprintf(OutFile, "4.0 %f\n",thermo101);
		fprintf(OutFile, "4.8 %f\n",thermo149+U_spinPneutrl);
		fprintf(OutFile, "5.0 %f\n",thermo102);
		fprintf(OutFile, "6.0 %f\n",thermo103);
		//      fprintf(OutFile, "8.0 %f\n",thermo31);


		fprintf(OutFile,"\n\n\n");

		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".pho2");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",-LitThermo61);
		fprintf(OutFile, "1.5 %f\n",-LitThermo62);
		fprintf(OutFile, "2.0 %f\n",LitThermo145);
		fprintf(OutFile, "2.5 %f\n",-LitThermo63);
		fprintf(OutFile, "3.0 %f\n",LitThermo146);
		fprintf(OutFile, "3.5 %f\n",-LitThermo64);
		fprintf(OutFile, "4.0 %f\n",LitThermo147);
		fprintf(OutFile, "4.0 %f\n",LitThermo148);
		fprintf(OutFile, "4.5 %f\n",-LitThermo65);
		fprintf(OutFile, "5.0 %f\n",LitThermo149);
		fprintf(OutFile, "5.5 %f\n",-LitThermo66);


		fprintf(OutFile,"\n\n\n");

		//Printing model values ionization and first excitation
		fprintf(OutFile, "0.5 %f\n",-thermo61);
		fprintf(OutFile, "1.5 %f\n",-thermo62);
		fprintf(OutFile, "2.0 %f\n",thermo145);
		fprintf(OutFile, "2.5 %f\n",-thermo63);
		fprintf(OutFile, "3.0 %f\n",thermo146);
		fprintf(OutFile, "3.5 %f\n",-thermo64);
		fprintf(OutFile, "4.0 %f\n",thermo147);
		fprintf(OutFile, "4.5 %f\n",-thermo65);
		fprintf(OutFile, "5.0 %f\n",thermo154);
		fprintf(OutFile, "5.5 %f\n",-thermo66);

		fprintf(OutFile,"\n\n\n");

		//printing model values of second exc. energies
		fprintf(OutFile, "4.0 %f\n",thermo148);

		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".nit");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "1.0 %f\n",LitThermo85);
		fprintf(OutFile, "1.8 %f\n",LitThermo130+LitThermo86);
		fprintf(OutFile, "2.0 %f\n",LitThermo86);
		fprintf(OutFile, "2.8 %f\n",LitThermo131+LitThermo87);
		fprintf(OutFile, "3.0 %f\n",LitThermo87);
		fprintf(OutFile, "3.6 %f\n",LitThermo133+LitThermo88);
		fprintf(OutFile, "3.8 %f\n",LitThermo132+LitThermo88);
		fprintf(OutFile, "4.0 %f\n",LitThermo88);
		//fprintf(OutFile, "4.6 %f\n",LitThermo158+LitThermo89);
		fprintf(OutFile, "4.8 %f\n",LitThermo134+LitThermo89);
		fprintf(OutFile, "5.0 %f\n",LitThermo89);
		//      fprintf(OutFile, "8.0 %f\n",LitThermo31);


		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "1.0 %f\n",thermo85);
		fprintf(OutFile, "1.8 %f\n",thermo130+U_spinNplus3);
		fprintf(OutFile, "2.0 %f\n",thermo86);
		fprintf(OutFile, "2.8 %f\n",thermo131+U_spinNplus2);
		fprintf(OutFile, "3.0 %f\n",thermo87);
		fprintf(OutFile, "3.6 %f\n",thermo133+U_spinNplus);
		fprintf(OutFile, "3.8 %f\n",thermo132+U_spinNplus);
		fprintf(OutFile, "4.0 %f\n",thermo88);
		//fprintf(OutFile, "4.6 %f\n",thermo158+U_spinNneutrl);
		fprintf(OutFile, "4.8 %f\n",thermo134+U_spinNneutrl);
		fprintf(OutFile, "5.0 %f\n",thermo89);
		//      fprintf(OutFile, "8.0 %f\n",thermo31);


		fprintf(OutFile,"\n\n\n");

		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".nit2");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",-LitThermo48);
		fprintf(OutFile, "1.5 %f\n",-LitThermo49);
		fprintf(OutFile, "2.0 %f\n",LitThermo130);
		fprintf(OutFile, "2.5 %f\n",-LitThermo50);
		fprintf(OutFile, "3.0 %f\n",LitThermo131);
		fprintf(OutFile, "3.5 %f\n",-LitThermo51);
		fprintf(OutFile, "4.0 %f\n",LitThermo132);
		fprintf(OutFile, "4.0 %f\n",LitThermo133);
		fprintf(OutFile, "4.5 %f\n",-LitThermo52);
		fprintf(OutFile, "5.0 %f\n",LitThermo134);
		//fprintf(OutFile, "5.0 %f\n",LitThermo158);


		fprintf(OutFile,"\n\n\n");

		//Printing model values ionization and first excitation
		fprintf(OutFile, "0.5 %f\n",-thermo48);
		fprintf(OutFile, "1.5 %f\n",-thermo49);
		fprintf(OutFile, "2.0 %f\n",thermo130);
		fprintf(OutFile, "2.5 %f\n",-thermo50);
		fprintf(OutFile, "3.0 %f\n",thermo131);
		fprintf(OutFile, "3.5 %f\n",-thermo51);
		fprintf(OutFile, "4.0 %f\n",thermo132);
		fprintf(OutFile, "4.5 %f\n",-thermo52);
		fprintf(OutFile, "5.0 %f\n",thermo134);

		fprintf(OutFile,"\n\n\n");

		//printing model values of second exc. energies
		fprintf(OutFile, "4.0 %f\n",thermo133);
		//fprintf(OutFile, "5.0 %f\n",thermo158);

		fclose(OutFile);


		strcpy(plot, directory);
		strcat(plot, ".sil");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "1.0 %f\n",LitThermo104);
		fprintf(OutFile, "1.8 %f\n",LitThermo141+LitThermo105);
		fprintf(OutFile, "2.0 %f\n",LitThermo105);
		fprintf(OutFile, "2.8 %f\n",LitThermo142+LitThermo106);
		fprintf(OutFile, "3.0 %f\n",LitThermo106);
		fprintf(OutFile, "3.6 %f\n",LitThermo144+LitThermo107);
		fprintf(OutFile, "3.8 %f\n",LitThermo143+LitThermo107);
		fprintf(OutFile, "4.0 %f\n",LitThermo107);
		fprintf(OutFile, "5.0 %f\n",LitThermo108);



		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "1.0 %f\n",thermo104);
		fprintf(OutFile, "1.8 %f\n",thermo141+U_spinSiplus2);
		fprintf(OutFile, "2.0 %f\n",thermo105);
		fprintf(OutFile, "2.8 %f\n",thermo142+U_spinSiplus);
		fprintf(OutFile, "3.0 %f\n",thermo106);
		fprintf(OutFile, "3.6 %f\n",thermo144+U_spinSineutrl);
		fprintf(OutFile, "3.8 %f\n",thermo143+U_spinSineutrl);
		fprintf(OutFile, "4.0 %f\n",thermo107);
		fprintf(OutFile, "5.0 %f\n",thermo108);


		fprintf(OutFile,"\n\n\n");

		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".sil2");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",-LitThermo67);
		fprintf(OutFile, "1.5 %f\n",-LitThermo68);
		fprintf(OutFile, "2.0 %f\n",LitThermo141);
		fprintf(OutFile, "2.5 %f\n",-LitThermo69);
		fprintf(OutFile, "3.0 %f\n",LitThermo142);
		fprintf(OutFile, "3.5 %f\n",-LitThermo70);
		fprintf(OutFile, "4.0 %f\n",LitThermo144);
		fprintf(OutFile, "4.0 %f\n",LitThermo143);
		fprintf(OutFile, "4.5 %f\n",-LitThermo71);

		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "0.5 %f\n",-thermo67);
		fprintf(OutFile, "1.5 %f\n",-thermo68);
		fprintf(OutFile, "2.0 %f\n",thermo141);
		fprintf(OutFile, "2.5 %f\n",-thermo69);
		fprintf(OutFile, "3.0 %f\n",thermo142);
		fprintf(OutFile, "3.5 %f\n",-thermo70);
		fprintf(OutFile, "4.0 %f\n",thermo143);
		fprintf(OutFile, "4.5 %f\n",-thermo71);

		fprintf(OutFile,"\n\n\n");

		fprintf(OutFile, "4.0 %f\n",thermo144);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);


		strcpy(plot, directory);
		strcat(plot, ".alu");

		OutFile = fopen(plot, "a");

		fprintf(OutFile, "1.0 %f\n",LitThermo207);
		fprintf(OutFile, "1.8 %f\n",LitThermo193+LitThermo206);
		fprintf(OutFile, "2.0 %f\n",LitThermo206);
		fprintf(OutFile, "2.8 %f\n",LitThermo191+LitThermo205);
		fprintf(OutFile, "3.0 %f\n",LitThermo205);
		fprintf(OutFile, "4.0 %f\n",LitThermo204);



		fprintf(OutFile,"\n\n\n");


		fprintf(OutFile, "1.0 %f\n",thermo207);
		fprintf(OutFile, "1.8 %f\n",thermo193+U_spinAlplus);
		fprintf(OutFile, "2.0 %f\n",thermo206);
		fprintf(OutFile, "2.8 %f\n",thermo191+U_spinAlneutrl);
		fprintf(OutFile, "3.0 %f\n",thermo205);
		fprintf(OutFile, "4.0 %f\n",thermo204);

		fprintf(OutFile,"\n\n\n");

		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".alu2");

		OutFile = fopen(plot, "a");


		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",-LitThermo195);
		fprintf(OutFile, "1.5 %f\n",-LitThermo194);
		fprintf(OutFile, "2.0 %f\n",LitThermo193);
		fprintf(OutFile, "2.5 %f\n",-LitThermo192);
		fprintf(OutFile, "3.0 %f\n",LitThermo191);
		fprintf(OutFile, "3.5 %f\n",-LitThermo190);

		fprintf(OutFile,"\n\n\n");

		fprintf(OutFile, "0.5 %f\n",-thermo195);
		fprintf(OutFile, "1.5 %f\n",-thermo194);
		fprintf(OutFile, "2.0 %f\n",thermo193);
		fprintf(OutFile, "2.5 %f\n",-thermo192);
		fprintf(OutFile, "3.0 %f\n",thermo191);
		fprintf(OutFile, "3.5 %f\n",-thermo190);
		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);


		strcpy(plot, directory);
		strcat(plot, ".chl");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "1.0 %f\n",LitThermo203);
		fprintf(OutFile, "1.8 %f\n",LitThermo187+LitThermo202);
		fprintf(OutFile, "2.0 %f\n",LitThermo202);
		fprintf(OutFile, "2.8 %f\n",LitThermo185+LitThermo201);
		fprintf(OutFile, "3.0 %f\n",LitThermo201);
		fprintf(OutFile, "3.6 %f\n",LitThermo182+LitThermo200);
		fprintf(OutFile, "3.8 %f\n",LitThermo183+LitThermo200);
		fprintf(OutFile, "4.0 %f\n",LitThermo200);
		fprintf(OutFile, "4.8 %f\n",LitThermo180+LitThermo199);
		fprintf(OutFile, "5.0 %f\n",LitThermo199);
		fprintf(OutFile, "5.6 %f\n",LitThermo177+LitThermo198);
		fprintf(OutFile, "5.8 %f\n",LitThermo178+LitThermo198);
		fprintf(OutFile, "6.0 %f\n",LitThermo198);
		fprintf(OutFile, "6.8 %f\n",LitThermo175+LitThermo196);
		fprintf(OutFile, "7.0 %f\n",LitThermo197);
		fprintf(OutFile, "8.0 %f\n",LitThermo196);



		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "1.0 %f\n",thermo203);
		fprintf(OutFile, "1.8 %f\n",thermo187+U_spinClplus5);
		fprintf(OutFile, "2.0 %f\n",thermo202);
		fprintf(OutFile, "2.8 %f\n",thermo185+U_spinClplus4);
		fprintf(OutFile, "3.0 %f\n",thermo201);
		fprintf(OutFile, "3.6 %f\n",thermo182+U_spinClplus3);
		fprintf(OutFile, "3.8 %f\n",thermo183+U_spinClplus3);
		fprintf(OutFile, "4.0 %f\n",thermo200);
		fprintf(OutFile, "4.8 %f\n",thermo180+U_spinClplus2);
		fprintf(OutFile, "5.0 %f\n",thermo199);
		fprintf(OutFile, "5.6 %f\n",thermo177+U_spinClplus);
		fprintf(OutFile, "5.8 %f\n",thermo178+U_spinClplus);
		fprintf(OutFile, "6.0 %f\n",thermo198);
		fprintf(OutFile, "6.8 %f\n",thermo175+U_spinClneutrl);
		fprintf(OutFile, "7.0 %f\n",thermo197);
		fprintf(OutFile, "8.0 %f\n",thermo196);


		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);


		strcpy(plot, directory);
		strcat(plot, ".chl2");

		OutFile = fopen(plot, "a");

		fprintf(OutFile,"\n\n\n");

		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",-LitThermo189);
		fprintf(OutFile, "1.5 %f\n",-LitThermo188);
		fprintf(OutFile, "2.0 %f\n", LitThermo187);
		fprintf(OutFile, "2.5 %f\n",-LitThermo186);
		fprintf(OutFile, "3.0 %f\n", LitThermo185);
		fprintf(OutFile, "3.5 %f\n",-LitThermo184);
		fprintf(OutFile, "4.0 %f\n", LitThermo183);
		fprintf(OutFile, "4.0 %f\n", LitThermo182);
		fprintf(OutFile, "4.5 %f\n",-LitThermo181);
		fprintf(OutFile, "5.0 %f\n", LitThermo180);
		fprintf(OutFile, "5.5 %f\n",-LitThermo179);
		fprintf(OutFile, "6.0 %f\n", LitThermo178);
		fprintf(OutFile, "6.0 %f\n", LitThermo177);
		fprintf(OutFile, "6.5 %f\n",-LitThermo176);
		fprintf(OutFile, "7.0 %f\n", LitThermo175);
		fprintf(OutFile, "7.5 %f\n",-LitThermo174);

		fprintf(OutFile,"\n\n\n");

		//Printing model values
		fprintf(OutFile, "0.5 %f\n",-thermo189);
		fprintf(OutFile, "1.5 %f\n",-thermo188);
		fprintf(OutFile, "2.0 %f\n", thermo187);
		fprintf(OutFile, "2.5 %f\n",-thermo186);
		fprintf(OutFile, "3.0 %f\n", thermo185);
		fprintf(OutFile, "3.5 %f\n",-thermo184);
		fprintf(OutFile, "4.0 %f\n", thermo183);
		fprintf(OutFile, "4.5 %f\n",-thermo181);
		fprintf(OutFile, "5.0 %f\n", thermo180);
		fprintf(OutFile, "5.5 %f\n",-thermo179);
		fprintf(OutFile, "6.0 %f\n", thermo178);
		fprintf(OutFile, "6.5 %f\n",-thermo176);
		fprintf(OutFile, "7.0 %f\n", thermo175);
		fprintf(OutFile, "7.5 %f\n",-thermo174);


		fprintf(OutFile,"\n\n\n");

		fprintf(OutFile, "4.0 %f\n",thermo182);
		fprintf(OutFile, "6.0 %f\n",thermo177);

		fprintf(OutFile,"\n\n\n");


		fclose(OutFile);

		strcpy(plot, directory);
		strcat(plot, ".sc");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo256);
		fprintf(OutFile, "1.5 %f\n",LitThermo257);
		fprintf(OutFile, "2.0 %f\n",LitThermo258);
		fprintf(OutFile, "2.5 %f\n",LitThermo259);
		fprintf(OutFile, "3.0 %f\n",LitThermo260);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo256);
		fprintf(OutFile, "1.5 %f\n",thermo257);
		fprintf(OutFile, "2.0 %f\n",thermo258);
		fprintf(OutFile, "2.5 %f\n",thermo259);
		fprintf(OutFile, "3.0 %f\n",thermo260);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".sc2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo261);
		fprintf(OutFile, "1.5 %f\n",LitThermo262);
		fprintf(OutFile, "2.5 %f\n",LitThermo263);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo261);
		fprintf(OutFile, "1.5 %f\n",thermo262);
		fprintf(OutFile, "2.5 %f\n",thermo263);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".ti");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo264);
		fprintf(OutFile, "1.5 %f\n",LitThermo265);
		fprintf(OutFile, "2.0 %f\n",LitThermo266);
		fprintf(OutFile, "2.5 %f\n",LitThermo267);
		fprintf(OutFile, "3.0 %f\n",LitThermo268);
		fprintf(OutFile, "3.5 %f\n",LitThermo269);
		fprintf(OutFile, "4.0 %f\n",LitThermo270);
		fprintf(OutFile, "4.0 %f\n",LitThermo271);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo264);
		fprintf(OutFile, "1.5 %f\n",thermo265);
		fprintf(OutFile, "2.0 %f\n",thermo266);
		fprintf(OutFile, "2.5 %f\n",thermo267);
		fprintf(OutFile, "3.0 %f\n",thermo268);
		fprintf(OutFile, "3.5 %f\n",thermo269);
		fprintf(OutFile, "4.0 %f\n",thermo270);
		fprintf(OutFile, "4.0 %f\n",thermo271);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".ti2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo272);
		fprintf(OutFile, "1.5 %f\n",LitThermo273);
		fprintf(OutFile, "2.5 %f\n",LitThermo274);
		fprintf(OutFile, "3.5 %f\n",LitThermo275);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo272);
		fprintf(OutFile, "1.5 %f\n",thermo273);
		fprintf(OutFile, "2.5 %f\n",thermo274);
		fprintf(OutFile, "3.5 %f\n",thermo275);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".v");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo276);
		fprintf(OutFile, "1.5 %f\n",LitThermo277);
		fprintf(OutFile, "2.0 %f\n",LitThermo278);
		fprintf(OutFile, "2.5 %f\n",LitThermo279);
		fprintf(OutFile, "3.0 %f\n",LitThermo280);
		fprintf(OutFile, "3.5 %f\n",LitThermo281);
		fprintf(OutFile, "4.0 %f\n",LitThermo282);
		fprintf(OutFile, "4.0 %f\n",LitThermo283);
		fprintf(OutFile, "4.5 %f\n",LitThermo284);
		fprintf(OutFile, "5.0 %f\n",LitThermo285);
		fprintf(OutFile, "5.0 %f\n",LitThermo286);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo276);
		fprintf(OutFile, "1.5 %f\n",thermo277);
		fprintf(OutFile, "2.0 %f\n",thermo278);
		fprintf(OutFile, "2.5 %f\n",thermo279);
		fprintf(OutFile, "3.0 %f\n",thermo280);
		fprintf(OutFile, "3.5 %f\n",thermo281);
		fprintf(OutFile, "4.0 %f\n",thermo282);
		fprintf(OutFile, "4.0 %f\n",thermo283);
		fprintf(OutFile, "4.5 %f\n",thermo284);
		fprintf(OutFile, "5.0 %f\n",thermo285);
		fprintf(OutFile, "5.0 %f\n",thermo286);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".v2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo287);
		fprintf(OutFile, "1.5 %f\n",LitThermo288);
		fprintf(OutFile, "2.5 %f\n",LitThermo289);
		fprintf(OutFile, "3.5 %f\n",LitThermo290);
		fprintf(OutFile, "4.5 %f\n",LitThermo291);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo287);
		fprintf(OutFile, "1.5 %f\n",thermo288);
		fprintf(OutFile, "2.5 %f\n",thermo289);
		fprintf(OutFile, "3.5 %f\n",thermo290);
		fprintf(OutFile, "4.5 %f\n",thermo291);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".cr");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo292);
		fprintf(OutFile, "1.5 %f\n",LitThermo293);
		fprintf(OutFile, "2.0 %f\n",LitThermo294);
		fprintf(OutFile, "2.5 %f\n",LitThermo295);
		fprintf(OutFile, "3.0 %f\n",LitThermo296);
		fprintf(OutFile, "3.5 %f\n",LitThermo297);
		fprintf(OutFile, "4.0 %f\n",LitThermo298);
		fprintf(OutFile, "4.0 %f\n",LitThermo299);
		fprintf(OutFile, "4.5 %f\n",LitThermo300);
		fprintf(OutFile, "5.0 %f\n",LitThermo301);
		fprintf(OutFile, "5.0 %f\n",LitThermo302);
		fprintf(OutFile, "5.5 %f\n",LitThermo303);
		fprintf(OutFile, "6.0 %f\n",LitThermo304);
		fprintf(OutFile, "6.0 %f\n",LitThermo305);
		fprintf(OutFile, "6.0 %f\n",LitThermo306);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo292);
		fprintf(OutFile, "1.5 %f\n",thermo293);
		fprintf(OutFile, "2.0 %f\n",thermo294);
		fprintf(OutFile, "2.5 %f\n",thermo295);
		fprintf(OutFile, "3.0 %f\n",thermo296);
		fprintf(OutFile, "3.5 %f\n",thermo297);
		fprintf(OutFile, "4.0 %f\n",thermo298);
		fprintf(OutFile, "4.0 %f\n",thermo299);
		fprintf(OutFile, "4.5 %f\n",thermo300);
		fprintf(OutFile, "5.0 %f\n",thermo301);
		fprintf(OutFile, "5.0 %f\n",thermo302);
		fprintf(OutFile, "5.5 %f\n",thermo303);
		fprintf(OutFile, "6.0 %f\n",thermo304);
		fprintf(OutFile, "6.0 %f\n",thermo305);
		fprintf(OutFile, "6.0 %f\n",thermo306);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".cr2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo307);
		fprintf(OutFile, "1.5 %f\n",LitThermo308);
		fprintf(OutFile, "2.5 %f\n",LitThermo309);
		fprintf(OutFile, "3.5 %f\n",LitThermo310);
		fprintf(OutFile, "4.5 %f\n",LitThermo311);
		fprintf(OutFile, "5.5 %f\n",LitThermo312);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo307);
		fprintf(OutFile, "1.5 %f\n",thermo308);
		fprintf(OutFile, "2.5 %f\n",thermo309);
		fprintf(OutFile, "3.5 %f\n",thermo310);
		fprintf(OutFile, "4.5 %f\n",thermo311);
		fprintf(OutFile, "5.5 %f\n",thermo312);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".mn");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo313);
		fprintf(OutFile, "1.5 %f\n",LitThermo314);
		fprintf(OutFile, "2.0 %f\n",LitThermo315);
		fprintf(OutFile, "2.5 %f\n",LitThermo316);
		fprintf(OutFile, "3.0 %f\n",LitThermo317);
		fprintf(OutFile, "3.5 %f\n",LitThermo318);
		fprintf(OutFile, "4.0 %f\n",LitThermo319);
		fprintf(OutFile, "4.5 %f\n",LitThermo320);
		fprintf(OutFile, "5.0 %f\n",LitThermo321);
		fprintf(OutFile, "5.0 %f\n",LitThermo322);
		fprintf(OutFile, "5.5 %f\n",LitThermo323);
		fprintf(OutFile, "6.0 %f\n",LitThermo324);
		fprintf(OutFile, "6.0 %f\n",LitThermo325);
		fprintf(OutFile, "6.0 %f\n",LitThermo326);
		fprintf(OutFile, "6.5 %f\n",LitThermo327);
		fprintf(OutFile, "7.0 %f\n",LitThermo328);
		fprintf(OutFile, "7.0 %f\n",LitThermo329);
		fprintf(OutFile, "7.0 %f\n",LitThermo330);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo313);
		fprintf(OutFile, "1.5 %f\n",thermo314);
		fprintf(OutFile, "2.0 %f\n",thermo315);
		fprintf(OutFile, "2.5 %f\n",thermo316);
		fprintf(OutFile, "3.0 %f\n",thermo317);
		fprintf(OutFile, "3.5 %f\n",thermo318);
		fprintf(OutFile, "4.0 %f\n",thermo319);
		fprintf(OutFile, "4.5 %f\n",thermo320);
		fprintf(OutFile, "5.0 %f\n",thermo321);
		fprintf(OutFile, "5.0 %f\n",thermo322);
		fprintf(OutFile, "5.5 %f\n",thermo323);
		fprintf(OutFile, "6.0 %f\n",thermo324);
		fprintf(OutFile, "6.0 %f\n",thermo325);
		fprintf(OutFile, "6.0 %f\n",thermo326);
		fprintf(OutFile, "6.5 %f\n",thermo327);
		fprintf(OutFile, "7.0 %f\n",thermo328);
		fprintf(OutFile, "7.0 %f\n",thermo329);
		fprintf(OutFile, "7.0 %f\n",thermo330);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".mn2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo331);
		fprintf(OutFile, "1.5 %f\n",LitThermo332);
		fprintf(OutFile, "2.5 %f\n",LitThermo333);
		fprintf(OutFile, "3.5 %f\n",LitThermo334);
		fprintf(OutFile, "4.5 %f\n",LitThermo335);
		fprintf(OutFile, "5.5 %f\n",LitThermo336);
		fprintf(OutFile, "6.5 %f\n",LitThermo337);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo331);
		fprintf(OutFile, "1.5 %f\n",thermo332);
		fprintf(OutFile, "2.5 %f\n",thermo333);
		fprintf(OutFile, "3.5 %f\n",thermo334);
		fprintf(OutFile, "4.5 %f\n",thermo335);
		fprintf(OutFile, "5.5 %f\n",thermo336);
		fprintf(OutFile, "6.5 %f\n",thermo337);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".fe");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo338);
		fprintf(OutFile, "1.5 %f\n",LitThermo339);
		fprintf(OutFile, "2.0 %f\n",LitThermo340);
		fprintf(OutFile, "2.5 %f\n",LitThermo341);
		fprintf(OutFile, "3.0 %f\n",LitThermo342);
		fprintf(OutFile, "3.5 %f\n",LitThermo343);
		fprintf(OutFile, "4.0 %f\n",LitThermo344);
		fprintf(OutFile, "4.0 %f\n",LitThermo345);
		fprintf(OutFile, "4.5 %f\n",LitThermo346);
		fprintf(OutFile, "5.0 %f\n",LitThermo347);
		fprintf(OutFile, "5.0 %f\n",LitThermo348);
		fprintf(OutFile, "5.5 %f\n",LitThermo349);
		fprintf(OutFile, "6.0 %f\n",LitThermo350);
		fprintf(OutFile, "6.0 %f\n",LitThermo351);
		fprintf(OutFile, "6.5 %f\n",LitThermo352);
		fprintf(OutFile, "7.0 %f\n",LitThermo353);
		fprintf(OutFile, "7.0 %f\n",LitThermo354);
		fprintf(OutFile, "7.5 %f\n",LitThermo355);
		fprintf(OutFile, "8.0 %f\n",LitThermo356);
		fprintf(OutFile, "8.0 %f\n",LitThermo357);
		fprintf(OutFile, "8.0 %f\n",LitThermo358);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo338);
		fprintf(OutFile, "1.5 %f\n",thermo339);
		fprintf(OutFile, "2.0 %f\n",thermo340);
		fprintf(OutFile, "2.5 %f\n",thermo341);
		fprintf(OutFile, "3.0 %f\n",thermo342);
		fprintf(OutFile, "3.5 %f\n",thermo343);
		fprintf(OutFile, "4.0 %f\n",thermo344);
		fprintf(OutFile, "4.0 %f\n",thermo345);
		fprintf(OutFile, "4.5 %f\n",thermo346);
		fprintf(OutFile, "5.0 %f\n",thermo347);
		fprintf(OutFile, "5.0 %f\n",thermo348);
		fprintf(OutFile, "5.5 %f\n",thermo349);
		fprintf(OutFile, "6.0 %f\n",thermo350);
		fprintf(OutFile, "6.0 %f\n",thermo351);
		fprintf(OutFile, "6.5 %f\n",thermo352);
		fprintf(OutFile, "7.0 %f\n",thermo353);
		fprintf(OutFile, "7.0 %f\n",thermo354);
		fprintf(OutFile, "7.5 %f\n",thermo355);
		fprintf(OutFile, "8.0 %f\n",thermo356);
		fprintf(OutFile, "8.0 %f\n",thermo357);
		fprintf(OutFile, "8.0 %f\n",thermo358);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".fe2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo359);
		fprintf(OutFile, "1.5 %f\n",LitThermo360);
		fprintf(OutFile, "2.5 %f\n",LitThermo361);
		fprintf(OutFile, "3.5 %f\n",LitThermo362);
		fprintf(OutFile, "4.5 %f\n",LitThermo363);
		fprintf(OutFile, "5.5 %f\n",LitThermo364);
		fprintf(OutFile, "6.5 %f\n",LitThermo365);
		fprintf(OutFile, "7.5 %f\n",LitThermo366);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo359);
		fprintf(OutFile, "1.5 %f\n",thermo360);
		fprintf(OutFile, "2.5 %f\n",thermo361);
		fprintf(OutFile, "3.5 %f\n",thermo362);
		fprintf(OutFile, "4.5 %f\n",thermo363);
		fprintf(OutFile, "5.5 %f\n",thermo364);
		fprintf(OutFile, "6.5 %f\n",thermo365);
		fprintf(OutFile, "7.5 %f\n",thermo366);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".co");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo367);
		fprintf(OutFile, "1.5 %f\n",LitThermo368);
		fprintf(OutFile, "2.0 %f\n",LitThermo369);
		fprintf(OutFile, "2.5 %f\n",LitThermo370);
		fprintf(OutFile, "3.0 %f\n",LitThermo371);
		fprintf(OutFile, "3.5 %f\n",LitThermo372);
		fprintf(OutFile, "4.0 %f\n",LitThermo373);
		fprintf(OutFile, "4.0 %f\n",LitThermo374);
		fprintf(OutFile, "4.5 %f\n",LitThermo375);
		fprintf(OutFile, "5.0 %f\n",LitThermo376);
		fprintf(OutFile, "5.0 %f\n",LitThermo377);
		fprintf(OutFile, "5.5 %f\n",LitThermo378);
		fprintf(OutFile, "6.0 %f\n",LitThermo379);
		fprintf(OutFile, "6.0 %f\n",LitThermo380);
		fprintf(OutFile, "6.5 %f\n",LitThermo381);
		fprintf(OutFile, "7.0 %f\n",LitThermo382);
		fprintf(OutFile, "7.0 %f\n",LitThermo383);
		fprintf(OutFile, "7.5 %f\n",LitThermo384);
		fprintf(OutFile, "8.0 %f\n",LitThermo385);
		fprintf(OutFile, "8.0 %f\n",LitThermo386);
		fprintf(OutFile, "8.5 %f\n",LitThermo387);
		fprintf(OutFile, "9.0 %f\n",LitThermo388);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo367);
		fprintf(OutFile, "1.5 %f\n",thermo368);
		fprintf(OutFile, "2.0 %f\n",thermo369);
		fprintf(OutFile, "2.5 %f\n",thermo370);
		fprintf(OutFile, "3.0 %f\n",thermo371);
		fprintf(OutFile, "3.5 %f\n",thermo372);
		fprintf(OutFile, "4.0 %f\n",thermo373);
		fprintf(OutFile, "4.0 %f\n",thermo374);
		fprintf(OutFile, "4.5 %f\n",thermo375);
		fprintf(OutFile, "5.0 %f\n",thermo376);
		fprintf(OutFile, "5.0 %f\n",thermo377);
		fprintf(OutFile, "5.5 %f\n",thermo378);
		fprintf(OutFile, "6.0 %f\n",thermo379);
		fprintf(OutFile, "6.0 %f\n",thermo380);
		fprintf(OutFile, "6.5 %f\n",thermo381);
		fprintf(OutFile, "7.0 %f\n",thermo382);
		fprintf(OutFile, "7.0 %f\n",thermo383);
		fprintf(OutFile, "7.5 %f\n",thermo384);
		fprintf(OutFile, "8.0 %f\n",thermo385);
		fprintf(OutFile, "8.0 %f\n",thermo386);
		fprintf(OutFile, "8.5 %f\n",thermo387);
		fprintf(OutFile, "9.0 %f\n",thermo388);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".co2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo389);
		fprintf(OutFile, "1.5 %f\n",LitThermo390);
		fprintf(OutFile, "2.5 %f\n",LitThermo391);
		fprintf(OutFile, "3.5 %f\n",LitThermo392);
		fprintf(OutFile, "4.5 %f\n",LitThermo393);
		fprintf(OutFile, "5.5 %f\n",LitThermo394);
		fprintf(OutFile, "6.5 %f\n",LitThermo395);
		fprintf(OutFile, "7.5 %f\n",LitThermo396);
		fprintf(OutFile, "8.5 %f\n",LitThermo397);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo389);
		fprintf(OutFile, "1.5 %f\n",thermo390);
		fprintf(OutFile, "2.5 %f\n",thermo391);
		fprintf(OutFile, "3.5 %f\n",thermo392);
		fprintf(OutFile, "4.5 %f\n",thermo393);
		fprintf(OutFile, "5.5 %f\n",thermo394);
		fprintf(OutFile, "6.5 %f\n",thermo395);
		fprintf(OutFile, "7.5 %f\n",thermo396);
		fprintf(OutFile, "8.5 %f\n",thermo397);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".ni");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo398);
		fprintf(OutFile, "1.5 %f\n",LitThermo399);
		fprintf(OutFile, "2.0 %f\n",LitThermo400);
		fprintf(OutFile, "2.5 %f\n",LitThermo401);
		fprintf(OutFile, "3.0 %f\n",LitThermo402);
		fprintf(OutFile, "3.5 %f\n",LitThermo403);
		fprintf(OutFile, "4.0 %f\n",LitThermo404);
		fprintf(OutFile, "4.5 %f\n",LitThermo405);
		fprintf(OutFile, "5.0 %f\n",LitThermo406);
		fprintf(OutFile, "5.0 %f\n",LitThermo407);
		fprintf(OutFile, "5.5 %f\n",LitThermo408);
		fprintf(OutFile, "6.0 %f\n",LitThermo409);
		fprintf(OutFile, "6.0 %f\n",LitThermo410);
		fprintf(OutFile, "6.5 %f\n",LitThermo411);
		fprintf(OutFile, "7.0 %f\n",LitThermo412);
		fprintf(OutFile, "7.0 %f\n",LitThermo413);
		fprintf(OutFile, "7.5 %f\n",LitThermo414);
		fprintf(OutFile, "8.0 %f\n",LitThermo415);
		fprintf(OutFile, "8.0 %f\n",LitThermo416);
		fprintf(OutFile, "8.5 %f\n",LitThermo417);
		fprintf(OutFile, "9.0 %f\n",LitThermo418);
		fprintf(OutFile, "9.5 %f\n",LitThermo419);
		fprintf(OutFile, "10.0 %f\n",LitThermo420);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo398);
		fprintf(OutFile, "1.5 %f\n",thermo399);
		fprintf(OutFile, "2.0 %f\n",thermo400);
		fprintf(OutFile, "2.5 %f\n",thermo401);
		fprintf(OutFile, "3.0 %f\n",thermo402);
		fprintf(OutFile, "3.5 %f\n",thermo403);
		fprintf(OutFile, "4.0 %f\n",thermo404);
		fprintf(OutFile, "4.5 %f\n",thermo405);
		fprintf(OutFile, "5.0 %f\n",thermo406);
		fprintf(OutFile, "5.0 %f\n",thermo407);
		fprintf(OutFile, "5.5 %f\n",thermo408);
		fprintf(OutFile, "6.0 %f\n",thermo409);
		fprintf(OutFile, "6.0 %f\n",thermo410);
		fprintf(OutFile, "6.5 %f\n",thermo411);
		fprintf(OutFile, "7.0 %f\n",thermo412);
		fprintf(OutFile, "7.0 %f\n",thermo413);
		fprintf(OutFile, "7.5 %f\n",thermo414);
		fprintf(OutFile, "8.0 %f\n",thermo415);
		fprintf(OutFile, "8.0 %f\n",thermo416);
		fprintf(OutFile, "8.5 %f\n",thermo417);
		fprintf(OutFile, "9.0 %f\n",thermo418);
		fprintf(OutFile, "9.5 %f\n",thermo419);
		fprintf(OutFile, "10.0 %f\n",thermo420);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".ni2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo421);
		fprintf(OutFile, "1.5 %f\n",LitThermo422);
		fprintf(OutFile, "2.5 %f\n",LitThermo423);
		fprintf(OutFile, "3.5 %f\n",LitThermo424);
		fprintf(OutFile, "4.5 %f\n",LitThermo425);
		fprintf(OutFile, "5.5 %f\n",LitThermo426);
		fprintf(OutFile, "6.5 %f\n",LitThermo427);
		fprintf(OutFile, "7.5 %f\n",LitThermo428);
		fprintf(OutFile, "8.5 %f\n",LitThermo429);
		fprintf(OutFile, "9.5 %f\n",LitThermo430);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo421);
		fprintf(OutFile, "1.5 %f\n",thermo422);
		fprintf(OutFile, "2.5 %f\n",thermo423);
		fprintf(OutFile, "3.5 %f\n",thermo424);
		fprintf(OutFile, "4.5 %f\n",thermo425);
		fprintf(OutFile, "5.5 %f\n",thermo426);
		fprintf(OutFile, "6.5 %f\n",thermo427);
		fprintf(OutFile, "7.5 %f\n",thermo428);
		fprintf(OutFile, "8.5 %f\n",thermo429);
		fprintf(OutFile, "9.5 %f\n",thermo430);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".cu");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo431);
		fprintf(OutFile, "1.5 %f\n",LitThermo432);
		fprintf(OutFile, "2.0 %f\n",LitThermo433);
		fprintf(OutFile, "2.5 %f\n",LitThermo434);
		fprintf(OutFile, "3.5 %f\n",LitThermo435);
		fprintf(OutFile, "4.5 %f\n",LitThermo436);
		fprintf(OutFile, "5.5 %f\n",LitThermo437);
		fprintf(OutFile, "6.0 %f\n",LitThermo438);
		fprintf(OutFile, "6.0 %f\n",LitThermo439);
		fprintf(OutFile, "6.5 %f\n",LitThermo440);
		fprintf(OutFile, "7.0 %f\n",LitThermo441);
		fprintf(OutFile, "7.0 %f\n",LitThermo442);
		fprintf(OutFile, "7.5 %f\n",LitThermo443);
		fprintf(OutFile, "8.0 %f\n",LitThermo444);
		fprintf(OutFile, "8.0 %f\n",LitThermo445);
		fprintf(OutFile, "8.5 %f\n",LitThermo446);
		fprintf(OutFile, "9.0 %f\n",LitThermo447);
		fprintf(OutFile, "9.5 %f\n",LitThermo448);
		fprintf(OutFile, "10.0 %f\n",LitThermo449);
		fprintf(OutFile, "10.5 %f\n",LitThermo450);
		fprintf(OutFile, "11.0 %f\n",LitThermo451);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo431);
		fprintf(OutFile, "1.5 %f\n",thermo432);
		fprintf(OutFile, "2.0 %f\n",thermo433);
		fprintf(OutFile, "2.5 %f\n",thermo434);
		fprintf(OutFile, "3.5 %f\n",thermo435);
		fprintf(OutFile, "4.5 %f\n",thermo436);
		fprintf(OutFile, "5.5 %f\n",thermo437);
		fprintf(OutFile, "6.0 %f\n",thermo438);
		fprintf(OutFile, "6.0 %f\n",thermo439);
		fprintf(OutFile, "6.5 %f\n",thermo440);
		fprintf(OutFile, "7.0 %f\n",thermo441);
		fprintf(OutFile, "7.0 %f\n",thermo442);
		fprintf(OutFile, "7.5 %f\n",thermo443);
		fprintf(OutFile, "8.0 %f\n",thermo444);
		fprintf(OutFile, "8.0 %f\n",thermo445);
		fprintf(OutFile, "8.5 %f\n",thermo446);
		fprintf(OutFile, "9.0 %f\n",thermo447);
		fprintf(OutFile, "9.5 %f\n",thermo448);
		fprintf(OutFile, "10.0 %f\n",thermo449);
		fprintf(OutFile, "10.5 %f\n",thermo450);
		fprintf(OutFile, "11.0 %f\n",thermo451);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".cu2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo452);
		fprintf(OutFile, "1.5 %f\n",LitThermo453);
		fprintf(OutFile, "2.5 %f\n",LitThermo454);
		fprintf(OutFile, "3.5 %f\n",LitThermo455);
		fprintf(OutFile, "4.5 %f\n",LitThermo456);
		fprintf(OutFile, "5.5 %f\n",LitThermo457);
		fprintf(OutFile, "6.5 %f\n",LitThermo458);
		fprintf(OutFile, "7.5 %f\n",LitThermo459);
		fprintf(OutFile, "8.5 %f\n",LitThermo460);
		fprintf(OutFile, "9.5 %f\n",LitThermo461);
		fprintf(OutFile, "10.5 %f\n",LitThermo462);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo452);
		fprintf(OutFile, "1.5 %f\n",thermo453);
		fprintf(OutFile, "2.5 %f\n",thermo454);
		fprintf(OutFile, "3.5 %f\n",thermo455);
		fprintf(OutFile, "4.5 %f\n",thermo456);
		fprintf(OutFile, "5.5 %f\n",thermo457);
		fprintf(OutFile, "6.5 %f\n",thermo458);
		fprintf(OutFile, "7.5 %f\n",thermo459);
		fprintf(OutFile, "8.5 %f\n",thermo460);
		fprintf(OutFile, "9.5 %f\n",thermo461);
		fprintf(OutFile, "10.5 %f\n",thermo462);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".zn");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo463);
		fprintf(OutFile, "1.5 %f\n",LitThermo464);
		fprintf(OutFile, "2.0 %f\n",LitThermo465);
		fprintf(OutFile, "2.5 %f\n",LitThermo466);
		fprintf(OutFile, "3.5 %f\n",LitThermo467);
		fprintf(OutFile, "4.5 %f\n",LitThermo468);
		fprintf(OutFile, "5.5 %f\n",LitThermo469);
		fprintf(OutFile, "6.0 %f\n",LitThermo470);
		fprintf(OutFile, "6.0 %f\n",LitThermo471);
		fprintf(OutFile, "6.5 %f\n",LitThermo472);
		fprintf(OutFile, "7.0 %f\n",LitThermo473);
		fprintf(OutFile, "7.0 %f\n",LitThermo474);
		fprintf(OutFile, "7.5 %f\n",LitThermo475);
		fprintf(OutFile, "8.0 %f\n",LitThermo476);
		fprintf(OutFile, "8.0 %f\n",LitThermo477);
		fprintf(OutFile, "8.5 %f\n",LitThermo478);
		fprintf(OutFile, "9.0 %f\n",LitThermo479);
		fprintf(OutFile, "9.5 %f\n",LitThermo480);
		fprintf(OutFile, "10.0 %f\n",LitThermo481);
		fprintf(OutFile, "10.5 %f\n",LitThermo482);
		fprintf(OutFile, "11.0 %f\n",LitThermo483);
		fprintf(OutFile, "11.5 %f\n",LitThermo484);
		fprintf(OutFile, "12.0 %f\n",LitThermo485);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo463);
		fprintf(OutFile, "1.5 %f\n",thermo464);
		fprintf(OutFile, "2.0 %f\n",thermo465);
		fprintf(OutFile, "2.5 %f\n",thermo466);
		fprintf(OutFile, "3.5 %f\n",thermo467);
		fprintf(OutFile, "4.5 %f\n",thermo468);
		fprintf(OutFile, "5.5 %f\n",thermo469);
		fprintf(OutFile, "6.0 %f\n",thermo470);
		fprintf(OutFile, "6.0 %f\n",thermo471);
		fprintf(OutFile, "6.5 %f\n",thermo472);
		fprintf(OutFile, "7.0 %f\n",thermo473);
		fprintf(OutFile, "7.0 %f\n",thermo474);
		fprintf(OutFile, "7.5 %f\n",thermo475);
		fprintf(OutFile, "8.0 %f\n",thermo476);
		fprintf(OutFile, "8.0 %f\n",thermo477);
		fprintf(OutFile, "8.5 %f\n",thermo478);
		fprintf(OutFile, "9.0 %f\n",thermo479);
		fprintf(OutFile, "9.5 %f\n",thermo480);
		fprintf(OutFile, "10.0 %f\n",thermo481);
		fprintf(OutFile, "10.5 %f\n",thermo482);
		fprintf(OutFile, "11.0 %f\n",thermo483);
		fprintf(OutFile, "11.5 %f\n",thermo484);
		fprintf(OutFile, "12.0 %f\n",thermo485);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".zn2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo486);
		fprintf(OutFile, "1.5 %f\n",LitThermo487);
		fprintf(OutFile, "2.5 %f\n",LitThermo488);
		fprintf(OutFile, "3.5 %f\n",LitThermo489);
		fprintf(OutFile, "4.5 %f\n",LitThermo490);
		fprintf(OutFile, "5.5 %f\n",LitThermo491);
		fprintf(OutFile, "6.5 %f\n",LitThermo492);
		fprintf(OutFile, "7.5 %f\n",LitThermo493);
		fprintf(OutFile, "8.5 %f\n",LitThermo494);
		fprintf(OutFile, "9.5 %f\n",LitThermo495);
		fprintf(OutFile, "10.5 %f\n",LitThermo496);
		fprintf(OutFile, "11.5 %f\n",LitThermo497);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo486);
		fprintf(OutFile, "1.5 %f\n",thermo487);
		fprintf(OutFile, "2.5 %f\n",thermo488);
		fprintf(OutFile, "3.5 %f\n",thermo489);
		fprintf(OutFile, "4.5 %f\n",thermo490);
		fprintf(OutFile, "5.5 %f\n",thermo491);
		fprintf(OutFile, "6.5 %f\n",thermo492);
		fprintf(OutFile, "7.5 %f\n",thermo493);
		fprintf(OutFile, "8.5 %f\n",thermo494);
		fprintf(OutFile, "9.5 %f\n",thermo495);
		fprintf(OutFile, "10.5 %f\n",thermo496);
		fprintf(OutFile, "11.5 %f\n",thermo497);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".y");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo498);
		fprintf(OutFile, "1.5 %f\n",LitThermo499);
		fprintf(OutFile, "2.0 %f\n",LitThermo500);
		fprintf(OutFile, "2.5 %f\n",LitThermo501);
		fprintf(OutFile, "3.0 %f\n",LitThermo502);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo498);
		fprintf(OutFile, "1.5 %f\n",thermo499);
		fprintf(OutFile, "2.0 %f\n",thermo500);
		fprintf(OutFile, "2.5 %f\n",thermo501);
		fprintf(OutFile, "3.0 %f\n",thermo502);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".y2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo503);
		fprintf(OutFile, "1.5 %f\n",LitThermo504);
		fprintf(OutFile, "2.5 %f\n",LitThermo505);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo503);
		fprintf(OutFile, "1.5 %f\n",thermo504);
		fprintf(OutFile, "2.5 %f\n",thermo505);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".zr");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo506);
		fprintf(OutFile, "1.5 %f\n",LitThermo507);
		fprintf(OutFile, "2.0 %f\n",LitThermo508);
		fprintf(OutFile, "2.5 %f\n",LitThermo509);
		fprintf(OutFile, "3.0 %f\n",LitThermo510);
		fprintf(OutFile, "3.5 %f\n",LitThermo511);
		fprintf(OutFile, "4.0 %f\n",LitThermo512);
		fprintf(OutFile, "4.0 %f\n",LitThermo513);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo506);
		fprintf(OutFile, "1.5 %f\n",thermo507);
		fprintf(OutFile, "2.0 %f\n",thermo508);
		fprintf(OutFile, "2.5 %f\n",thermo509);
		fprintf(OutFile, "3.0 %f\n",thermo510);
		fprintf(OutFile, "3.5 %f\n",thermo511);
		fprintf(OutFile, "4.0 %f\n",thermo512);
		fprintf(OutFile, "4.0 %f\n",thermo513);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".zr2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo514);
		fprintf(OutFile, "1.5 %f\n",LitThermo515);
		fprintf(OutFile, "2.5 %f\n",LitThermo516);
		fprintf(OutFile, "3.5 %f\n",LitThermo517);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo514);
		fprintf(OutFile, "1.5 %f\n",thermo515);
		fprintf(OutFile, "2.5 %f\n",thermo516);
		fprintf(OutFile, "3.5 %f\n",thermo517);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".nb");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo518);
		fprintf(OutFile, "1.5 %f\n",LitThermo519);
		fprintf(OutFile, "2.0 %f\n",LitThermo520);
		fprintf(OutFile, "2.5 %f\n",LitThermo521);
		fprintf(OutFile, "3.0 %f\n",LitThermo522);
		fprintf(OutFile, "3.5 %f\n",LitThermo523);
		fprintf(OutFile, "4.0 %f\n",LitThermo524);
		fprintf(OutFile, "4.0 %f\n",LitThermo525);
		fprintf(OutFile, "4.5 %f\n",LitThermo526);
		fprintf(OutFile, "5.0 %f\n",LitThermo527);
		fprintf(OutFile, "5.0 %f\n",LitThermo528);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo518);
		fprintf(OutFile, "1.5 %f\n",thermo519);
		fprintf(OutFile, "2.0 %f\n",thermo520);
		fprintf(OutFile, "2.5 %f\n",thermo521);
		fprintf(OutFile, "3.0 %f\n",thermo522);
		fprintf(OutFile, "3.5 %f\n",thermo523);
		fprintf(OutFile, "4.0 %f\n",thermo524);
		fprintf(OutFile, "4.0 %f\n",thermo525);
		fprintf(OutFile, "4.5 %f\n",thermo526);
		fprintf(OutFile, "5.0 %f\n",thermo527);
		fprintf(OutFile, "5.0 %f\n",thermo528);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".nb2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo529);
		fprintf(OutFile, "1.5 %f\n",LitThermo530);
		fprintf(OutFile, "2.5 %f\n",LitThermo531);
		fprintf(OutFile, "3.5 %f\n",LitThermo532);
		fprintf(OutFile, "4.5 %f\n",LitThermo533);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo529);
		fprintf(OutFile, "1.5 %f\n",thermo530);
		fprintf(OutFile, "2.5 %f\n",thermo531);
		fprintf(OutFile, "3.5 %f\n",thermo532);
		fprintf(OutFile, "4.5 %f\n",thermo533);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".mo");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo534);
		fprintf(OutFile, "1.5 %f\n",LitThermo535);
		fprintf(OutFile, "2.0 %f\n",LitThermo536);
		fprintf(OutFile, "2.5 %f\n",LitThermo537);
		fprintf(OutFile, "3.0 %f\n",LitThermo538);
		fprintf(OutFile, "3.5 %f\n",LitThermo539);
		fprintf(OutFile, "4.0 %f\n",LitThermo540);
		fprintf(OutFile, "4.0 %f\n",LitThermo541);
		fprintf(OutFile, "4.5 %f\n",LitThermo542);
		fprintf(OutFile, "5.0 %f\n",LitThermo543);
		fprintf(OutFile, "5.0 %f\n",LitThermo544);
		fprintf(OutFile, "5.5 %f\n",LitThermo545);
		fprintf(OutFile, "6.0 %f\n",LitThermo546);
		fprintf(OutFile, "6.0 %f\n",LitThermo547);
		fprintf(OutFile, "6.0 %f\n",LitThermo548);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo534);
		fprintf(OutFile, "1.5 %f\n",thermo535);
		fprintf(OutFile, "2.0 %f\n",thermo536);
		fprintf(OutFile, "2.5 %f\n",thermo537);
		fprintf(OutFile, "3.0 %f\n",thermo538);
		fprintf(OutFile, "3.5 %f\n",thermo539);
		fprintf(OutFile, "4.0 %f\n",thermo540);
		fprintf(OutFile, "4.0 %f\n",thermo541);
		fprintf(OutFile, "4.5 %f\n",thermo542);
		fprintf(OutFile, "5.0 %f\n",thermo543);
		fprintf(OutFile, "5.0 %f\n",thermo544);
		fprintf(OutFile, "5.5 %f\n",thermo545);
		fprintf(OutFile, "6.0 %f\n",thermo546);
		fprintf(OutFile, "6.0 %f\n",thermo547);
		fprintf(OutFile, "6.0 %f\n",thermo548);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".mo2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo549);
		fprintf(OutFile, "1.5 %f\n",LitThermo550);
		fprintf(OutFile, "2.5 %f\n",LitThermo551);
		fprintf(OutFile, "3.5 %f\n",LitThermo552);
		fprintf(OutFile, "4.5 %f\n",LitThermo553);
		fprintf(OutFile, "5.5 %f\n",LitThermo554);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo549);
		fprintf(OutFile, "1.5 %f\n",thermo550);
		fprintf(OutFile, "2.5 %f\n",thermo551);
		fprintf(OutFile, "3.5 %f\n",thermo552);
		fprintf(OutFile, "4.5 %f\n",thermo553);
		fprintf(OutFile, "5.5 %f\n",thermo554);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".tc");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo555);
		fprintf(OutFile, "1.5 %f\n",LitThermo556);
		fprintf(OutFile, "2.5 %f\n",LitThermo557);
		fprintf(OutFile, "3.5 %f\n",LitThermo558);
		fprintf(OutFile, "4.5 %f\n",LitThermo559);
		fprintf(OutFile, "5.5 %f\n",LitThermo560);
		fprintf(OutFile, "6.0 %f\n",LitThermo561);
		fprintf(OutFile, "6.5 %f\n",LitThermo562);
		fprintf(OutFile, "7.0 %f\n",LitThermo563);
		fprintf(OutFile, "7.0 %f\n",LitThermo564);
		fprintf(OutFile, "7.0 %f\n",LitThermo565);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo555);
		fprintf(OutFile, "1.5 %f\n",thermo556);
		fprintf(OutFile, "2.5 %f\n",thermo557);
		fprintf(OutFile, "3.5 %f\n",thermo558);
		fprintf(OutFile, "4.5 %f\n",thermo559);
		fprintf(OutFile, "5.5 %f\n",thermo560);
		fprintf(OutFile, "6.0 %f\n",thermo561);
		fprintf(OutFile, "6.5 %f\n",thermo562);
		fprintf(OutFile, "7.0 %f\n",thermo563);
		fprintf(OutFile, "7.0 %f\n",thermo564);
		fprintf(OutFile, "7.0 %f\n",thermo565);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".tc2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo566);
		fprintf(OutFile, "1.5 %f\n",LitThermo567);
		fprintf(OutFile, "2.5 %f\n",LitThermo568);
		fprintf(OutFile, "3.5 %f\n",LitThermo569);
		fprintf(OutFile, "4.5 %f\n",LitThermo570);
		fprintf(OutFile, "5.5 %f\n",LitThermo571);
		fprintf(OutFile, "6.5 %f\n",LitThermo572);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo566);
		fprintf(OutFile, "1.5 %f\n",thermo567);
		fprintf(OutFile, "2.5 %f\n",thermo568);
		fprintf(OutFile, "3.5 %f\n",thermo569);
		fprintf(OutFile, "4.5 %f\n",thermo570);
		fprintf(OutFile, "5.5 %f\n",thermo571);
		fprintf(OutFile, "6.5 %f\n",thermo572);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".ru");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo573);
		fprintf(OutFile, "1.5 %f\n",LitThermo574);
		fprintf(OutFile, "2.5 %f\n",LitThermo575);
		fprintf(OutFile, "3.5 %f\n",LitThermo576);
		fprintf(OutFile, "4.5 %f\n",LitThermo577);
		fprintf(OutFile, "5.5 %f\n",LitThermo578);
		fprintf(OutFile, "6.0 %f\n",LitThermo579);
		fprintf(OutFile, "6.5 %f\n",LitThermo580);
		fprintf(OutFile, "7.0 %f\n",LitThermo581);
		fprintf(OutFile, "7.0 %f\n",LitThermo582);
		fprintf(OutFile, "7.5 %f\n",LitThermo583);
		fprintf(OutFile, "8.0 %f\n",LitThermo584);
		fprintf(OutFile, "8.0 %f\n",LitThermo585);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo573);
		fprintf(OutFile, "1.5 %f\n",thermo574);
		fprintf(OutFile, "2.5 %f\n",thermo575);
		fprintf(OutFile, "3.5 %f\n",thermo576);
		fprintf(OutFile, "4.5 %f\n",thermo577);
		fprintf(OutFile, "5.5 %f\n",thermo578);
		fprintf(OutFile, "6.0 %f\n",thermo579);
		fprintf(OutFile, "6.5 %f\n",thermo580);
		fprintf(OutFile, "7.0 %f\n",thermo581);
		fprintf(OutFile, "7.0 %f\n",thermo582);
		fprintf(OutFile, "7.5 %f\n",thermo583);
		fprintf(OutFile, "8.0 %f\n",thermo584);
		fprintf(OutFile, "8.0 %f\n",thermo585);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".ru2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo586);
		fprintf(OutFile, "1.5 %f\n",LitThermo587);
		fprintf(OutFile, "2.5 %f\n",LitThermo588);
		fprintf(OutFile, "3.5 %f\n",LitThermo589);
		fprintf(OutFile, "4.5 %f\n",LitThermo590);
		fprintf(OutFile, "5.5 %f\n",LitThermo591);
		fprintf(OutFile, "6.5 %f\n",LitThermo592);
		fprintf(OutFile, "7.5 %f\n",LitThermo593);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo586);
		fprintf(OutFile, "1.5 %f\n",thermo587);
		fprintf(OutFile, "2.5 %f\n",thermo588);
		fprintf(OutFile, "3.5 %f\n",thermo589);
		fprintf(OutFile, "4.5 %f\n",thermo590);
		fprintf(OutFile, "5.5 %f\n",thermo591);
		fprintf(OutFile, "6.5 %f\n",thermo592);
		fprintf(OutFile, "7.5 %f\n",thermo593);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".rh");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo594);
		fprintf(OutFile, "1.5 %f\n",LitThermo595);
		fprintf(OutFile, "2.5 %f\n",LitThermo596);
		fprintf(OutFile, "3.5 %f\n",LitThermo597);
		fprintf(OutFile, "4.5 %f\n",LitThermo598);
		fprintf(OutFile, "5.5 %f\n",LitThermo599);
		fprintf(OutFile, "6.5 %f\n",LitThermo600);
		fprintf(OutFile, "7.0 %f\n",LitThermo601);
		fprintf(OutFile, "7.0 %f\n",LitThermo602);
		fprintf(OutFile, "7.5 %f\n",LitThermo603);
		fprintf(OutFile, "8.0 %f\n",LitThermo604);
		fprintf(OutFile, "8.0 %f\n",LitThermo605);
		fprintf(OutFile, "8.5 %f\n",LitThermo606);
		fprintf(OutFile, "9.0 %f\n",LitThermo607);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo594);
		fprintf(OutFile, "1.5 %f\n",thermo595);
		fprintf(OutFile, "2.5 %f\n",thermo596);
		fprintf(OutFile, "3.5 %f\n",thermo597);
		fprintf(OutFile, "4.5 %f\n",thermo598);
		fprintf(OutFile, "5.5 %f\n",thermo599);
		fprintf(OutFile, "6.5 %f\n",thermo600);
		fprintf(OutFile, "7.0 %f\n",thermo601);
		fprintf(OutFile, "7.0 %f\n",thermo602);
		fprintf(OutFile, "7.5 %f\n",thermo603);
		fprintf(OutFile, "8.0 %f\n",thermo604);
		fprintf(OutFile, "8.0 %f\n",thermo605);
		fprintf(OutFile, "8.5 %f\n",thermo606);
		fprintf(OutFile, "9.0 %f\n",thermo607);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".rh2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo608);
		fprintf(OutFile, "1.5 %f\n",LitThermo609);
		fprintf(OutFile, "2.5 %f\n",LitThermo610);
		fprintf(OutFile, "3.5 %f\n",LitThermo611);
		fprintf(OutFile, "4.5 %f\n",LitThermo612);
		fprintf(OutFile, "5.5 %f\n",LitThermo613);
		fprintf(OutFile, "6.5 %f\n",LitThermo614);
		fprintf(OutFile, "7.5 %f\n",LitThermo615);
		fprintf(OutFile, "8.5 %f\n",LitThermo616);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo608);
		fprintf(OutFile, "1.5 %f\n",thermo609);
		fprintf(OutFile, "2.5 %f\n",thermo610);
		fprintf(OutFile, "3.5 %f\n",thermo611);
		fprintf(OutFile, "4.5 %f\n",thermo612);
		fprintf(OutFile, "5.5 %f\n",thermo613);
		fprintf(OutFile, "6.5 %f\n",thermo614);
		fprintf(OutFile, "7.5 %f\n",thermo615);
		fprintf(OutFile, "8.5 %f\n",thermo616);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".pd");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo617);
		fprintf(OutFile, "1.5 %f\n",LitThermo618);
		fprintf(OutFile, "2.5 %f\n",LitThermo619);
		fprintf(OutFile, "3.5 %f\n",LitThermo620);
		fprintf(OutFile, "4.5 %f\n",LitThermo621);
		fprintf(OutFile, "5.5 %f\n",LitThermo622);
		fprintf(OutFile, "6.5 %f\n",LitThermo623);
		fprintf(OutFile, "7.5 %f\n",LitThermo624);
		fprintf(OutFile, "8.0 %f\n",LitThermo625);
		fprintf(OutFile, "8.0 %f\n",LitThermo626);
		fprintf(OutFile, "8.5 %f\n",LitThermo627);
		fprintf(OutFile, "9.0 %f\n",LitThermo628);
		fprintf(OutFile, "9.5 %f\n",LitThermo629);
		fprintf(OutFile, "10.0 %f\n",LitThermo630);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo617);
		fprintf(OutFile, "1.5 %f\n",thermo618);
		fprintf(OutFile, "2.5 %f\n",thermo619);
		fprintf(OutFile, "3.5 %f\n",thermo620);
		fprintf(OutFile, "4.5 %f\n",thermo621);
		fprintf(OutFile, "5.5 %f\n",thermo622);
		fprintf(OutFile, "6.5 %f\n",thermo623);
		fprintf(OutFile, "7.5 %f\n",thermo624);
		fprintf(OutFile, "8.0 %f\n",thermo625);
		fprintf(OutFile, "8.0 %f\n",thermo626);
		fprintf(OutFile, "8.5 %f\n",thermo627);
		fprintf(OutFile, "9.0 %f\n",thermo628);
		fprintf(OutFile, "9.5 %f\n",thermo629);
		fprintf(OutFile, "10.0 %f\n",thermo630);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".pd2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo631);
		fprintf(OutFile, "1.5 %f\n",LitThermo632);
		fprintf(OutFile, "2.5 %f\n",LitThermo633);
		fprintf(OutFile, "3.5 %f\n",LitThermo634);
		fprintf(OutFile, "4.5 %f\n",LitThermo635);
		fprintf(OutFile, "5.5 %f\n",LitThermo636);
		fprintf(OutFile, "6.5 %f\n",LitThermo637);
		fprintf(OutFile, "7.5 %f\n",LitThermo638);
		fprintf(OutFile, "8.5 %f\n",LitThermo639);
		fprintf(OutFile, "9.5 %f\n",LitThermo640);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo631);
		fprintf(OutFile, "1.5 %f\n",thermo632);
		fprintf(OutFile, "2.5 %f\n",thermo633);
		fprintf(OutFile, "3.5 %f\n",thermo634);
		fprintf(OutFile, "4.5 %f\n",thermo635);
		fprintf(OutFile, "5.5 %f\n",thermo636);
		fprintf(OutFile, "6.5 %f\n",thermo637);
		fprintf(OutFile, "7.5 %f\n",thermo638);
		fprintf(OutFile, "8.5 %f\n",thermo639);
		fprintf(OutFile, "9.5 %f\n",thermo640);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".ag");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo641);
		fprintf(OutFile, "1.5 %f\n",LitThermo642);
		fprintf(OutFile, "2.5 %f\n",LitThermo643);
		fprintf(OutFile, "3.5 %f\n",LitThermo644);
		fprintf(OutFile, "4.5 %f\n",LitThermo645);
		fprintf(OutFile, "5.5 %f\n",LitThermo646);
		fprintf(OutFile, "6.5 %f\n",LitThermo647);
		fprintf(OutFile, "7.5 %f\n",LitThermo648);
		fprintf(OutFile, "8.5 %f\n",LitThermo649);
		fprintf(OutFile, "9.0 %f\n",LitThermo650);
		fprintf(OutFile, "9.5 %f\n",LitThermo651);
		fprintf(OutFile, "10.0 %f\n",LitThermo652);
		fprintf(OutFile, "10.5 %f\n",LitThermo653);
		fprintf(OutFile, "11.0 %f\n",LitThermo654);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo641);
		fprintf(OutFile, "1.5 %f\n",thermo642);
		fprintf(OutFile, "2.5 %f\n",thermo643);
		fprintf(OutFile, "3.5 %f\n",thermo644);
		fprintf(OutFile, "4.5 %f\n",thermo645);
		fprintf(OutFile, "5.5 %f\n",thermo646);
		fprintf(OutFile, "6.5 %f\n",thermo647);
		fprintf(OutFile, "7.5 %f\n",thermo648);
		fprintf(OutFile, "8.5 %f\n",thermo649);
		fprintf(OutFile, "9.0 %f\n",thermo650);
		fprintf(OutFile, "9.5 %f\n",thermo651);
		fprintf(OutFile, "10.0 %f\n",thermo652);
		fprintf(OutFile, "10.5 %f\n",thermo653);
		fprintf(OutFile, "11.0 %f\n",thermo654);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".ag2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo655);
		fprintf(OutFile, "1.5 %f\n",LitThermo656);
		fprintf(OutFile, "2.5 %f\n",LitThermo657);
		fprintf(OutFile, "3.5 %f\n",LitThermo658);
		fprintf(OutFile, "4.5 %f\n",LitThermo659);
		fprintf(OutFile, "5.5 %f\n",LitThermo660);
		fprintf(OutFile, "6.5 %f\n",LitThermo661);
		fprintf(OutFile, "7.5 %f\n",LitThermo662);
		fprintf(OutFile, "8.5 %f\n",LitThermo663);
		fprintf(OutFile, "9.5 %f\n",LitThermo664);
		fprintf(OutFile, "10.5 %f\n",LitThermo665);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo655);
		fprintf(OutFile, "1.5 %f\n",thermo656);
		fprintf(OutFile, "2.5 %f\n",thermo657);
		fprintf(OutFile, "3.5 %f\n",thermo658);
		fprintf(OutFile, "4.5 %f\n",thermo659);
		fprintf(OutFile, "5.5 %f\n",thermo660);
		fprintf(OutFile, "6.5 %f\n",thermo661);
		fprintf(OutFile, "7.5 %f\n",thermo662);
		fprintf(OutFile, "8.5 %f\n",thermo663);
		fprintf(OutFile, "9.5 %f\n",thermo664);
		fprintf(OutFile, "10.5 %f\n",thermo665);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".cd");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo666);
		fprintf(OutFile, "1.5 %f\n",LitThermo667);
		fprintf(OutFile, "2.5 %f\n",LitThermo668);
		fprintf(OutFile, "3.5 %f\n",LitThermo669);
		fprintf(OutFile, "4.5 %f\n",LitThermo670);
		fprintf(OutFile, "5.5 %f\n",LitThermo671);
		fprintf(OutFile, "6.5 %f\n",LitThermo672);
		fprintf(OutFile, "7.5 %f\n",LitThermo673);
		fprintf(OutFile, "8.5 %f\n",LitThermo674);
		fprintf(OutFile, "9.0 %f\n",LitThermo675);
		fprintf(OutFile, "9.5 %f\n",LitThermo676);
		fprintf(OutFile, "10.0 %f\n",LitThermo677);
		fprintf(OutFile, "10.5 %f\n",LitThermo678);
		fprintf(OutFile, "11.0 %f\n",LitThermo679);
		fprintf(OutFile, "11.5 %f\n",LitThermo680);
		fprintf(OutFile, "12.0 %f\n",LitThermo681);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo666);
		fprintf(OutFile, "1.5 %f\n",thermo667);
		fprintf(OutFile, "2.5 %f\n",thermo668);
		fprintf(OutFile, "3.5 %f\n",thermo669);
		fprintf(OutFile, "4.5 %f\n",thermo670);
		fprintf(OutFile, "5.5 %f\n",thermo671);
		fprintf(OutFile, "6.5 %f\n",thermo672);
		fprintf(OutFile, "7.5 %f\n",thermo673);
		fprintf(OutFile, "8.5 %f\n",thermo674);
		fprintf(OutFile, "9.0 %f\n",thermo675);
		fprintf(OutFile, "9.5 %f\n",thermo676);
		fprintf(OutFile, "10.0 %f\n",thermo677);
		fprintf(OutFile, "10.5 %f\n",thermo678);
		fprintf(OutFile, "11.0 %f\n",thermo679);
		fprintf(OutFile, "11.5 %f\n",thermo680);
		fprintf(OutFile, "12.0 %f\n",thermo681);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);
		strcpy(plot, directory);
		strcat(plot, ".cd2");
		OutFile = fopen (plot, "a");

		fprintf(OutFile,"\n\n\n");
		//Printing literature values
		fprintf(OutFile, "0.5 %f\n",LitThermo682);
		fprintf(OutFile, "1.5 %f\n",LitThermo683);
		fprintf(OutFile, "2.5 %f\n",LitThermo684);
		fprintf(OutFile, "3.5 %f\n",LitThermo685);
		fprintf(OutFile, "4.5 %f\n",LitThermo686);
		fprintf(OutFile, "5.5 %f\n",LitThermo687);
		fprintf(OutFile, "6.5 %f\n",LitThermo688);
		fprintf(OutFile, "7.5 %f\n",LitThermo689);
		fprintf(OutFile, "8.5 %f\n",LitThermo690);
		fprintf(OutFile, "9.5 %f\n",LitThermo691);
		fprintf(OutFile, "10.5 %f\n",LitThermo692);
		fprintf(OutFile, "11.5 %f\n",LitThermo693);


		fprintf(OutFile,"\n\n\n");
		//Printing model values
		fprintf(OutFile, "0.5 %f\n",thermo682);
		fprintf(OutFile, "1.5 %f\n",thermo683);
		fprintf(OutFile, "2.5 %f\n",thermo684);
		fprintf(OutFile, "3.5 %f\n",thermo685);
		fprintf(OutFile, "4.5 %f\n",thermo686);
		fprintf(OutFile, "5.5 %f\n",thermo687);
		fprintf(OutFile, "6.5 %f\n",thermo688);
		fprintf(OutFile, "7.5 %f\n",thermo689);
		fprintf(OutFile, "8.5 %f\n",thermo690);
		fprintf(OutFile, "9.5 %f\n",thermo691);
		fprintf(OutFile, "10.5 %f\n",thermo692);
		fprintf(OutFile, "11.5 %f\n",thermo693);

		fprintf(OutFile,"\n\n\n");
		fclose(OutFile);

*/

	}
//	printf("weight is now %f, dev is now %f\n", wTotal, deviation);
	return deviation;
}

