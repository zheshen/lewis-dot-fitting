
 /**************************************************************
 * Purpose:                                                    *
 * This program includes some useful tool functions for MC     *
 * optimization process, such as distance, angle and dihedral  *
 * measure functions.		   			       *
 **************************************************************/

#include <math.h>
#include "Metropolis.h"
//#include "Lowermain.h"
double getSpinSym(struct V *vv, int m_molec, double bl){
	int i;
	double ax=0.0;
	double ay=0.0;
	double az=0.0;
        double bx=0.0;
        double by=0.0;
        double bz=0.0;

	double ssa=0.0;
	double ssb=0.0;
	double spinsym=0.0;

        for(i=0;i<m_molec;i++){
                if(vv[i].s== 2){
			ax += vv[i].x;
			ay += vv[i].y;
			az += vv[i].z;
		}
                if(vv[i].s==-2){
                        bx += vv[i].x;
                        by += vv[i].y;
                        bz += vv[i].z;
                }

	}
	ssa = distance(ax, ay, az, 0.0, 0.0, 0.0);
	ssb = distance(bx, by, bz, 0.0, 0.0, 0.0);
	spinsym= fmax(ssa,ssb);

	return spinsym;
}

double getBondOrder(struct V *vv, int  m_molec, double bl){
	int i;
	double bond_order=0.0;
	double bo_contrib[m_molec];

        for(i=0;i<m_molec;i++){
                if(vv[i].q==-1){
//			bo_contrib[i]=fmax(-0.5,(0.5-fabs(vv[i].z)/bl));
			bo_contrib[i]=-(1./bl)*fabs(vv[i].z)+0.5;
			if(fabs(vv[i].z)>(bl*0.5))
				bo_contrib[i]=0;
			bond_order+=bo_contrib[i];
		}
	}
	return bond_order;
}

void linreg(struct V *vp, int n, double *beta, double *r2){

	int i;
	double sumx=0;
	double sumy=0;
	double sumxy=0;
	double sumx2=0;
	double sumy2=0;
	*beta=0;
	*r2=0;
//	printf("n is %d\n",n);

	for (i=0;i<n;i++){
	//	printf("vp.x is %f vp.y is %f\n",vp[i].x,vp[i].y);
			sumx+=vp[i].x;
			sumy+=vp[i].y;
			sumxy+=vp[i].x*vp[i].y;
			sumx2+=vp[i].x*vp[i].x;
			sumy2+=vp[i].y*vp[i].y;
	}

//	printf("sumxy %f and sumx2 %f\n",sumxy,sumx2);
	*beta=sumxy/sumx2;
	*r2=sumxy/sqrt(sumx2*sumy2);
//	printf("beta in linreg is %f\n",*beta);
}

double getPolar(struct V *vv, int  m_molec){

        int i;
	double delx=0.0;
        double dely=0.0;
	double delz=0.0;
	double polarity=0.0;

        for(i=0;i<m_molec;i++){
			delx+=vv[i].q*vv[i].x;
                        dely+=vv[i].q*vv[i].y;
			delz+=vv[i].q*vv[i].z;
                        //printf("y-value is %f at i %d\n",vv[i].y,i);
                        //printf("dely is %f at i %d\n",dely,i);
        }

	polarity=distance(delx,dely,delz,0.0,0.0,0.0);

        return fabs(polarity);
}


double getYPolar(struct V *vv, int  m_molec){

	int i;
	double dely=0.0;

	for(i=0;i<m_molec;i++){
		if(vv[i].q==-1){
			dely+=vv[i].y;
			//printf("y-value is %f at i %d\n",vv[i].y,i);
			//printf("dely is %f at i %d\n",dely,i);
		}
	}
	return fabs(dely);
}

double getDistance(struct V *vv, int i, int j){

	//Get coordinates
	double x1 = vv[i].x;
	double y1 = vv[i].y;
	double z1 = vv[i].z;

	double x2 = vv[j].x;
	double y2 = vv[j].y;
	double z2 = vv[j].z;

	//Calculate distance
	return distance(x1, y1, z1, x2, y2, z2);
}

double getR2(struct V *vv, int i, int j){

	double r2, dx, dy, dz;

	dx = vv[i].x - vv[j].x;
	dy = vv[i].y - vv[j].y;
	dz = vv[i].z - vv[j].z;

	r2 = dx * dx + dy * dy + dz * dz;

	return r2;
}

double getAngle(struct V *vv, int i, int j, int k){

	//Get coordinates
	double x1 = vv[i].x;
	double y1 = vv[i].y;
	double z1 = vv[i].z;

	double x2 = vv[j].x;
	double y2 = vv[j].y;
	double z2 = vv[j].z;

	double x3 = vv[k].x;
	double y3 = vv[k].y;
	double z3 = vv[k].z;

	//Shift angle center to origin
	double a1 = x1 - x2;
	double b1 = y1 - y2;
	double c1 = z1 - z2;

	double a2 = x3 - x2;
	double b2 = y3 - y2;
	double c2 = z3 - z2;

	//Calculate angle
	//return fabs(raddeg(angle(a1, b1, c1, a2, b2, c2)));
	return raddeg(angle(a1, b1, c1, a2, b2, c2));
}


double getDihedral(struct V *vv, int i, int j, int k, int l){

	//Get coordinates
	double x1 = vv[i].x;
	double y1 = vv[i].y;
	double z1 = vv[i].z;

	double x2 = vv[j].x;
	double y2 = vv[j].y;
	double z2 = vv[j].z;

	double x3 = vv[k].x;
	double y3 = vv[k].y;
	double z3 = vv[k].z;

	double x4 = vv[l].x;
	double y4 = vv[l].y;
	double z4 = vv[l].z;

	//Get vectors A1 and A2, which are on the first plane
	double a1x = x1 - x2;
	double a1y = y1 - y2;
	double a1z = z1 - z2;

	double a2x = x3 - x2;
	double a2y = y3 - y2;
	double a2z = z3 - z2;

	//Get the normal vector to the first plane
	double u1x =  a1y * a2z - a1z * a2y;
	double u1y = -a1x * a2z + a1z * a2x;
	double u1z =  a1x * a2y - a1y * a2x;

	//Get vector A3 which is on the second plane, just like A2
	double a3x = x3 - x4;
	double a3y = y3 - y4;
	double a3z = z3 - z4;

	//Get the normal vector to the second plane
	double u2x =  a2y * a3z - a2z * a3y;
	double u2y = -a2x * a3z + a2z * a3x;
	double u2z =  a2x * a3y - a2y * a3x;

	//Get the angle between the two plane normals
	//return fabs(raddeg(angle(u1x, u1y, u1z, u2x, u2y, u2z)));
	return raddeg(angle(u1x, u1y, u1z, u2x, u2y, u2z));
}

double smaller(double x, double y){

	if (x < y)
		return x;

	return y;	
}

//Determine whether a chosen particle is allowed to be moved
int isAllowed(struct V *vin, int c, int mc_type){

	//Fix one chosen particle
	if (mc_type >= 0){
		if (c == mc_type)
			return 0;
		else
			return 1;
	}

	//Move everything
	if (mc_type == -1)
		return 1;

	//Fix heavy atoms
	if (mc_type == -2){
		if (vin[c].s > 2)
			return 0;
		else 
			return 1;
	}

	//Rotate but do not translate heavy atoms
	if (mc_type == -4){
		if (vin[c].s > 2)
			return 2; //means you can rotate but not translate
		else 
			return 1;
	}

	//For rotational transition dimer
	if (mc_type == -102){
		if ((c == 4) || (c == 5) || (c == 6)) //acceptor oxygen and its protons
			return 0;
		else if (c == 13) //donor oxygen
			return 2;
		else
			return 1;
	}

	//Fix all nuclei (heavy atoms + protons)
	if (mc_type == -3)
		if ((vin[c].s == 1) || (vin[c].s > 2))
			return 0;

	//Add more conditions here

	//Special codes
	//-101: transition deprotonated dimer -fix oxygens and central proton
	if (mc_type == -101)
		if ((vin[c].s > 3) || (c==12))
			return 0;

	//Default -allow
	return 1;
}


double getPower(double r, double neu){

	double r2, r3, r4, r6;
	double term;
	
	int n = (int) neu;

	switch (n){

	case 0:
		term = 1;
		break;
	case 1:
		term = r;
		break;
	case 2:
		term = r * r;
		break;
	case 3:
		term = r * r * r;
		break;
	case 4:
		r2 = r * r;
		term = r2 * r2;
		break;
	case 5:
		r2 = r * r;
		r3 = r2 * r;
		term = r2 * r3;
		break;
	case 6:
		r3 = r * r * r;
		term = r3 * r3;
		break;
	case 7:
		r3 = r * r * r;
		r6 = r3 * r3;
		term = r6 * r;
		break;
	case 8:
		r2 = r * r;
		r4 = r2 * r2;
		term = r4 * r4;
		break;
	case 9:
		r3 = r * r * r;
		term = r3 * r3 * r3;
		break;
	case 10:
		r2 = r * r;
		r4 = r2 * r2;
		term = r4 * r4 * r2;
		break;
	case 11:
		r2 = r * r;
		r4 = r2 * r2;
		term = r4 * r4 * r2 * r;
		break;
	case 12:
		r2 = r * r;
		r4 = r2 * r2;
		term = r4 * r4 * r4;
		break;
	default:
		term = pow(r, neu);	
		break;
	}

	return term;

}


