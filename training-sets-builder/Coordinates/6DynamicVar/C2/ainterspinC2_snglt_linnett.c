#include "Metropolis.h"
#include "Ainter.h"

extern double a_spinC2_snglt_linnett[];

double ainterspinC2_snglt_linnett(){
	int i;
	struct V Vin[m_spinC2_snglt_linnett];

	Vin[0].x = 0.000;
	Vin[0].y = 0.000;
	Vin[0].z = 0.620;
	Vin[0].d = 0.000;
	Vin[0].q = 4;
	Vin[0].s = 6;

	Vin[1].x = 0.000;
	Vin[1].y = 0.000;
	Vin[1].z = -0.620;
	Vin[1].d = 0.000;
	Vin[1].q = 4;
	Vin[1].s = 6;

	Vin[2].x = -0.234;
	Vin[2].y = -0.396;
	Vin[2].z = 0.000;
	Vin[2].d = 0.547;
	Vin[2].q = -1;
	Vin[2].s = -2;

	Vin[3].x = -0.234;
	Vin[3].y = -0.397;
	Vin[3].z = 0.000;
	Vin[3].d = 0.547;
	Vin[3].q = -1;
	Vin[3].s = 2;

	Vin[4].x = 0.460;
	Vin[4].y = -0.005;
	Vin[4].z = 0.000;
	Vin[4].d = 0.547;
	Vin[4].q = -1;
	Vin[4].s = -2;

	Vin[5].x = -0.226;
	Vin[5].y = 0.401;
	Vin[5].z = 0.000;
	Vin[5].d = 0.547;
	Vin[5].q = -1;
	Vin[5].s = 2;

	Vin[6].x = 0.461;
	Vin[6].y = -0.004;
	Vin[6].z = 0.000;
	Vin[6].d = 0.548;
	Vin[6].q = -1;
	Vin[6].s = 2;

	Vin[7].x = -0.227;
	Vin[7].y = 0.401;
	Vin[7].z = 0.000;
	Vin[7].d = 0.547;
	Vin[7].q = -1;
	Vin[7].s = -2;

	Vin[8].x = -0.003;
	Vin[8].y = 0.000;
	Vin[8].z = 0.945;
	Vin[8].d = 0.557;
	Vin[8].q = -1;
	Vin[8].s = -2;

	Vin[9].x = 0.003;
	Vin[9].y = 0.000;
	Vin[9].z = -0.945;
	Vin[9].d = 0.557;
	Vin[9].q = -1;
	Vin[9].s = 2;

	double Usum=0;

	extern int pdbSwitch;
	extern int writefinalpdb;
	extern int icue_spinC2_snglt_linnett;


	if((MC_spinC2_snglt_linnett) && (icue_spinC2_snglt_linnett==4))
	{for(i=0;i<4;i++)
		{metropolis(Vin,m_spinC2_snglt_linnett,-2);
		}
		Usum=metropolis(Vin,m_spinC2_snglt_linnett,-2);
	}
	else
		Usum=sumEnergies(Vin,m_spinC2_snglt_linnett);


	if (pdbSwitch){ output(Vin,m_spinC2_snglt_linnett, "spinC2_snglt_linnett.pdb");}

	if ((writefinalpdb)&&(icue_spinC2_snglt_linnett==4)) { output(Vin,m_spinC2_snglt_linnett, "spinC2_snglt_linnett.pdb");}


	if(MC_spinC2_snglt_linnett){
		extern struct V V_spinC2_snglt_linnett[];
		for(i=0; i<m_spinC2_snglt_linnett;i++){
			V_spinC2_snglt_linnett[i].x = Vin[i].x;
			V_spinC2_snglt_linnett[i].y = Vin[i].y;
			V_spinC2_snglt_linnett[i].z = Vin[i].z;
			V_spinC2_snglt_linnett[i].d = Vin[i].d;
			V_spinC2_snglt_linnett[i].q = Vin[i].q;
			V_spinC2_snglt_linnett[i].s = Vin[i].s;
		}
	}

	return Usum;

}
