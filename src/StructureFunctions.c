#include "Structure.h"

void Initialize(Species * spec){
	spec->sym = malloc(sizeof(double) * spec->degFree);
	spec->ist = malloc(sizeof(double) * spec->degFree);
	spec->key = malloc(sizeof(double) * spec->degFree);
	spec->coord = malloc(sizeof(V) * spec->numPart);
	spec->g = malloc(sizeof(double) * spec->degFree);
}

void Delete(Species  spec){
	free(spec.sym);
	free(spec.ist);
	free(spec.key);
	free(spec.coord);
	free(spec.g);
}
	
void lowermainDebugPrint(Species spec){
	int i;
	printf("\n==========================================\n");
	printf("Lowermain is now printing out structure information\n");
	printf("     Species type: %s \n", spec.name);
	printf("     Enum value: %d \n", spec.type);
	printf("     Particles: %d \n", spec.numPart);
	printf("     Degrees of Freedom: %d \n", spec.degFree);
	printf("     Energy: %f \n", spec.energy);
	for( i = 0; i< spec.degFree; i++){
		printf("     For sym coord %d:\n",i+1);
		printf("        ist[%d]= %f \n",i, spec.ist[i]);
		printf("        sym[%d]= %f \n",i, spec.sym[i]);
		printf("        key[%d]= %d \n",i, spec.key[i]);
	}
	printf("Now printing the (x,y,z,q,s) array\n");
	for( i = 0; i <spec.numPart; i++){
		printf("%f %f %f %f %d \n",spec.coord[i].x, spec.coord[i].y, spec.coord[i].z, spec.coord[i].q, spec.coord[i].s);   
	}
	printf("\n");
} 

double raddeg(double rad){
	double deg;
	deg =  (rad*180)/3.1415926535;
	return deg;
}

double degrad(double deg){

	double rad;
	rad =  3.1415926535 * deg / 180;
	return rad;
}

double rot(double x, double y, double z, double a, double b, double c, int xyz){
	if (xyz == 0){
		return x*cos(b)*cos(c) + y*(sin(a)*sin(b)*cos(c)-cos(a)*sin(c)) + z*(cos(a)*sin(b)*cos(c)+sin(a)*sin(c));
	}
	else if (xyz == 1){
		return x*cos(b)*sin(c) + y*(sin(a)*sin(b)*sin(c)+cos(a)*cos(c)) + z*(cos(a)*sin(b)*sin(c)-sin(a)*cos(c));
	}else{
		return -x*sin(b) + y*sin(a)*cos(b) + z*cos(a)*cos(b);
	}
}

//double getDistance(V * Vin, int a, int b){
//	double x1 = Vin[a].x;
//	double y1 = Vin[a].y;
//	double z1 = Vin[a].z;
//	double x2 = Vin[b].x;
//	double y2 = Vin[b].y;
//	double z2 = Vin[b].z;
//	double rvector;
//	rvector = sqrt ( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1) );
//	return rvector;
//}

//method for calculating angle between two points and origin
//double getAngle(V * Vin, int a, int b){
//	double x1 = Vin[a].x;
//	double y1 = Vin[a].y;
//	double z1 = Vin[a].z;
//	double x2 = Vin[b].x;
//	double y2 = Vin[b].y;
//	double z2 = Vin[b].z;
//	//printf("\nDid the correct info print?\n x1 = %f, y1 = %f, z1 = %f \n x2 = %f, y2 = %f, z2 = %f \n", x1,y1,z1,x2,y2,z2);
//	double dot12, dot11, dot22;
//	double rads;
//	dot12 =(x1*x2)+(y1*y2)+(z1*z2);
//	dot11 =(x1*x1)+(y1*y1)+(z1*z1);
//	dot22 =(x2*x2)+(y2*y2)+(z2*z2);
//	rads = acos(dot12/(sqrt(dot11)*sqrt(dot22)));
//	//printf("Does this make sense? %f\n", rads);
//	return rads;
//}

double getDipole(struct V *Vin, int n){

        double dipoleMoment = 0;
        double dipoleMoment_x = 0;
        double dipoleMoment_y = 0;
        double dipoleMoment_z = 0;
        int i;

        for (i = 0; i < n; i++){
                dipoleMoment_x += (Vin[i].x * Vin[i].q);
                dipoleMoment_y += (Vin[i].y * Vin[i].q);
                dipoleMoment_z += (Vin[i].z * Vin[i].q);
        }
	dipoleMoment = distance(dipoleMoment_x,dipoleMoment_y,dipoleMoment_z,0,0,0);
	dipoleMoment *= debye; 
	dipoleMoment = fabs(dipoleMoment); 

        return dipoleMoment;
}

double getSpinDipole(struct V *Vin, int n, double *dipole_A, double *dipole_B){

        double dipoleMomentA = 0;
        double dipoleMomentB = 0;
        double dipoleMomentA_x = 0;
        double dipoleMomentA_y = 0;
        double dipoleMomentA_z = 0;
        double dipoleMomentB_x = 0;
        double dipoleMomentB_y = 0;
        double dipoleMomentB_z = 0;
        int i;

        for (i = 0; i < n; i++){
		if (Vin[i].s == 2){
                	dipoleMomentA_x += (Vin[i].x * Vin[i].q);
                	dipoleMomentA_y += (Vin[i].y * Vin[i].q);
                	dipoleMomentA_z += (Vin[i].z * Vin[i].q);
		}
		else if (Vin[i].s == -2){
                	dipoleMomentB_x += (Vin[i].x * Vin[i].q);
                	dipoleMomentB_y += (Vin[i].y * Vin[i].q);
                	dipoleMomentB_z += (Vin[i].z * Vin[i].q);
		}
        }
	dipoleMomentA = distance(dipoleMomentA_x,dipoleMomentA_y,dipoleMomentA_z,0,0,0);
	dipoleMomentA *= debye; 
	dipoleMomentA = fabs(dipoleMomentA); 
	dipoleMomentB = distance(dipoleMomentB_x,dipoleMomentB_y,dipoleMomentB_z,0,0,0);
	dipoleMomentB *= debye; 
	dipoleMomentB = fabs(dipoleMomentB); 

	*dipole_A = dipoleMomentA;
	*dipole_B = dipoleMomentB;

        return dipoleMomentA+dipoleMomentB;
}

double distance(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2 ){
	double rvector;
	rvector = sqrt ( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1) );
	return rvector;
}

//method for calculating angle between two points and origin
double angle(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2){
	double dot12, dot11, dot22;
	double rads;
	dot12 =(x1*x2)+(y1*y2)+(z1*z2);
	dot11 =(x1*x1)+(y1*y1)+(z1*z1);
	dot22 =(x2*x2)+(y2*y2)+(z2*z2);
	rads = acos(dot12/(sqrt(dot11)*sqrt(dot22)));
	return rads;
}

//double getDipole(struct V Vin[], int n){
//
//	double dipoleMoment = 0;
//	int i;
//
//	for (i = 0; i < n; i++){
//		dipoleMoment += (Vin[i].z * Vin[i].q);
//	}
//
//	return dipoleMoment;
//}
//Quadrupole moment calculator -only for on-diagonal values

//double getQuadrupole(V Vin[], int n, int xyz){
//	
//	double quadrupole = 0.;
//	double x, y, z, xi, r2;
//	int i;
//	
//	double x0, y0, z0;
//	x0 = y0 = z0 = 0.;
//	double mass, M = 0.;
//	
//	//Find center of mass
//        for (i = 0; i < n; i++){
//		if (Vin[i].q ==  1) {mass =  MASS_PROTON;        }
//		if (Vin[i].q ==  6) {mass =  MASS_OXYGEN;        }
//		if (Vin[i].q == -2) {mass =  MASS_ELECTRON_PAIR; }
//		x0 += Vin[i].x * mass;
//		y0 += Vin[i].y * mass;
//		z0 += Vin[i].z * mass;
//		M  += mass;
//	}
//	x0 /= M;
//	y0 /= M;
//	z0 /= M;
//	
//	//printf("x0 = %f y0 = %f z0 = %f \n", x0, y0, z0);
//        
//	for (i = 0; i < n; i++){
//		x = Vin[i].x - x0;
//		y = Vin[i].y - y0;
//		z = Vin[i].z - z0;
//		
//		r2 = x * x + y * y + z * z;
//		
//		if (xyz == 0)
//			xi = x; 
//		if (xyz == 1)
//			xi = y; 
//		if (xyz == 2)
//			xi = z; 
//		
//		quadrupole += Vin[i].q * (3 * xi * xi - r2);
//	}
//	
//	quadrupole *= 0.5;
//	quadrupole *= debye;
//	
//	return quadrupole;
//}
//
/*
void assignpar(){
	extern double dlewis[];
	extern int key_potentials[];
	extern double ist_potentials[];
	extern double a_potentials[];
	extern double parVV[];
	extern double parVH[];
	extern double parCV[];
	extern double parCH[];
	extern double parNV[];
	extern double parNH[];
	extern double parOV[];
	extern double parOH[];
	extern double parCC[];
	extern double parNN[];
	extern double parOO[];
	extern double parCN[];
	extern double parCO[];
	extern double parNO[];
	int i,k,l;
	k = 0;
	l = 0;

//	for (i = 0; i < n_potentials; i++){
//		if (key_potentials[i])
//			dlewis[i] = pow(10, a_potentials[i]);
//		else
///			dlewis[i] = ist_potentials[i];
//	}
	for (i = l; i<l+n_VV; i++){
		parVV[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_VV;

	for (i = l; i<l+n_VH; i++){
		parVH[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_VH;

	for (i = l; i<l+n_CV; i++){
		parCV[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_CV;

	for (i = l; i<l+n_CH; i++){
		parCH[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_CH;

	for (i = l; i<l+n_NV; i++){
		parNV[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_NV;

	for (i = l; i<l+n_NH; i++){
		parNH[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_NH;

	for (i = l; i<l+n_OV; i++){
		parOV[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_OV;

	for (i = l; i<l+n_OH1; i++){
		parOH[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_OH1;

	for (i = l; i<l+n_CC; i++){
		parCC[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_CC;

	for (i = l; i<l+n_NN; i++){
		parNN[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_NN;

	for (i = l; i<l+n_OO; i++){
		parOO[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_OO;

	for (i = l; i<l+n_CN; i++){
		parCN[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_CN;

	for (i = l; i<l+n_CO1; i++){
		parCO[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_CO1;

	for (i = l; i<l+n_NO; i++){
		parNO[k] = dlewis[i];
		k++;
	}
	k = 0;
	l += n_NO;

}
*/


