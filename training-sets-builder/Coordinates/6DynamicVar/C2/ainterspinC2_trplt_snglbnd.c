#include "Metropolis.h"
#include "Ainter.h"

extern double a_spinC2_trplt_snglbnd[];

double ainterspinC2_trplt_snglbnd(){
	int i;
	struct V Vin[m_spinC2_trplt_snglbnd];

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

	Vin[2].x = 0.000;
	Vin[2].y = 0.353;
	Vin[2].z = 0.000;
	Vin[2].d = 0.646;
	Vin[2].q = -1;
	Vin[2].s = 2;

	Vin[3].x = 0.000;
	Vin[3].y = -0.353;
	Vin[3].z = 0.000;
	Vin[3].d = 0.646;
	Vin[3].q = -1;
	Vin[3].s = 2;

	Vin[4].x = 0.000;
	Vin[4].y = 0.351;
	Vin[4].z = -1.150;
	Vin[4].d = 0.685;
	Vin[4].q = -1;
	Vin[4].s = 2;

	Vin[5].x = 0.000;
	Vin[5].y = -0.351;
	Vin[5].z = -1.150;
	Vin[5].d = 0.685;
	Vin[5].q = -1;
	Vin[5].s = 2;

	Vin[6].x = 0.000;
	Vin[6].y = 0.000;
	Vin[6].z = -0.950;
	Vin[6].d = 0.685;
	Vin[6].q = -1;
	Vin[6].s = -2;

	Vin[7].x = 0.000;
	Vin[7].y = 0.352;
	Vin[7].z = 1.150;
	Vin[7].d = 0.714;
	Vin[7].q = -1;
	Vin[7].s = -2;

	Vin[8].x = 0.000;
	Vin[8].y = -0.351;
	Vin[8].z = 1.150;
	Vin[8].d = 0.637;
	Vin[8].q = -1;
	Vin[8].s = -2;

	Vin[9].x = 0.000;
	Vin[9].y = 0.000;
	Vin[9].z = 0.950;
	Vin[9].d = 0.715;
	Vin[9].q = -1;
	Vin[9].s = 2;

	double Usum=0;

	extern int pdbSwitch;
	extern int writefinalpdb;
	extern int icue_spinC2_trplt_snglbnd;


	if((MC_spinC2_trplt_snglbnd) && (icue_spinC2_trplt_snglbnd==4))
	{for(i=0;i<4;i++)
		{metropolis(Vin,m_spinC2_trplt_snglbnd,-2);
		}
		Usum=metropolis(Vin,m_spinC2_trplt_snglbnd,-2);
	}
	else
		Usum=sumEnergies(Vin,m_spinC2_trplt_snglbnd);


	if (pdbSwitch){ output(Vin,m_spinC2_trplt_snglbnd, "spinC2_trplt_snglbnd.pdb");}

	if ((writefinalpdb)&&(icue_spinC2_trplt_snglbnd==4)) { output(Vin,m_spinC2_trplt_snglbnd, "spinC2_trplt_snglbnd.pdb");}


	if(MC_spinC2_trplt_snglbnd){
		extern struct V V_spinC2_trplt_snglbnd[];
		for(i=0; i<m_spinC2_trplt_snglbnd;i++){
			V_spinC2_trplt_snglbnd[i].x = Vin[i].x;
			V_spinC2_trplt_snglbnd[i].y = Vin[i].y;
			V_spinC2_trplt_snglbnd[i].z = Vin[i].z;
			V_spinC2_trplt_snglbnd[i].d = Vin[i].d;
			V_spinC2_trplt_snglbnd[i].q = Vin[i].q;
			V_spinC2_trplt_snglbnd[i].s = Vin[i].s;
		}
	}

	return Usum;

}
