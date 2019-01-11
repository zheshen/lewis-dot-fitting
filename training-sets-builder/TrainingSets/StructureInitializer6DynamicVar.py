

import sys, os
import argparse

parser = argparse.ArgumentParser(description='Creat input files for monatomic training sets.')

parser.add_argument('input', type=str, help='input file')
#parser.add_argument('-o', dest='OUTPUT', type=str, default='output.c', help='ouput file')

args = parser.parse_args()

INPUT	=	args.input


FORMAT0	='''\
#include "Structure.h"

extern double U_spin%(fullname)s;					//declare structure energy                           

void specspin%(fullname)s(Species * spec){				//define SPEC function for specific structure

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	strcpy(spec->fullname, "%(fullname)s");			//Enter full name for the structure
	strcpy(spec->name, "%(name)s");				//Enter abbreviation name
	strcpy(spec->spin, "a%(spin_a)db%(spin_b)d");		//Enter spin structure
	spec->type = %(fullname)s;				//Enter type name
	spec->complete = 0;					//Not used temporarily
	spec->kernel = %(kernel)d;					//Not used temporarily
	spec->degFree = 16;					//Enter degree of freedom for the structure
	spec->numPart = %(numPart)d;					//Enter number of particles for the structure
	spec->stepSize = 0.101;					//Enter the stepsize for optimization, default is 0.101
	spec->ainter = ainterspin%(fullname)s;			//Enter the function name for "ainter" 
	spec->dev = devspin%(fullname)s;			//Enter the function name for "dev"

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//Set memory space for spec
	Initialize(spec);

        //Initial Values expressed in Radians and Angstroms
        spec->ist[0] = 1.000000;					// distance of electron to the center 
        spec->ist[1] = 1.000000; 
        spec->ist[2] = 1.000000; 
        spec->ist[3] = 1.000000; 		
        spec->ist[4] = 3.000000;					// 1/radius^2
        spec->ist[5] = 3.000000;
        spec->ist[6] = 3.000000; 
        spec->ist[7] = 3.000000; 
        spec->ist[8] = 1.000000;					// eta
        spec->ist[9] = 1.000000;
        spec->ist[10] = 1.000000; 					// zeta
        spec->ist[11] = 1.000000; 
        spec->ist[12] = 0.001;						// rotation angle
        spec->ist[13] = 0.001; 
        spec->ist[14] = 0.001; 
        spec->ist[15] = %(distance)f; 

        //translate initial values into log10 form for upnup, set Key
        int i;
        for(i = 0; i < spec->degFree; i++){
                spec->key[i] = 0;
                spec->sym[i] = log10(spec->ist[i]);
        }

        spec->sym[12] = log10((pi / spec->ist[0]) - 1);
        spec->sym[13] = log10((pi / spec->ist[0]) - 1);
        spec->sym[14] = log10((pi / spec->ist[0]) - 1);

'''

FORMAT1	='''\
	spec->key[12] = 1;
	spec->key[13] = 1;
	spec->key[14] = 1;

	if (fix_d){
		spec->key[4] = 0;
		spec->key[5] = 0;
		spec->key[6] = 0;
		spec->key[7] = 0;
		spec->sym[4] = log10(d_value);
		spec->sym[5] = log10(d_value);
		spec->sym[6] = log10(d_value);
		spec->sym[7] = log10(d_value);
		spec->key[8] = 0;
		spec->key[9] = 0;
		spec->key[10] = 0;
		spec->key[11] = 0;
		spec->sym[8] = log10(d_value);
		spec->sym[9] = log10(d_value);
		spec->sym[10] = log10(d_value);
		spec->sym[11] = log10(d_value);
	}

}


double ainterspin%(fullname)s(Species * spec){
	
	int i, part;
	double Usum;
	part = spec->numPart;
        V Vin[part];

        double ra1	=	pow(10, spec->sym[0]);			//distance from O to electron alpha1's
        double rb1	=	pow(10, spec->sym[1]);			//distance from O to electron beta1's
        double ra2	=	pow(10, spec->sym[2]);			//distance from O to electron alpha1's
        double rb2	=	pow(10, spec->sym[3]);			//distance from O to electron beta1's
        
        double da1_r	=	pow(10, spec->sym[4]);			//diameter of electron alpha1's
        double db1_r	=	pow(10, spec->sym[5]);			//diameter of electron beta1's
        double da1_i	=	pow(10, spec->sym[6]);			//diameter of electron alpha2's
        double db1_i	=	pow(10, spec->sym[7]);			//diameter of electron beta2's

        double da2	=	pow(10, spec->sym[8]);			//eta of electron alpha1's
        double db2	=	pow(10, spec->sym[9]);			//eta of electron alpha2's
        double da3	=	pow(10, spec->sym[10]);			//zeta of electron beta1's
        double db3	=	pow(10, spec->sym[11]);			//zeta of electron beta2's

	double a	=	pi / (1 + pow(10, spec->sym[12]));	//rotation angle a
	double b	=	pi / (1 + pow(10, spec->sym[13]));	//rotation angle b
	double c	=	pi / (1 + pow(10, spec->sym[14]));	//rotation angle c

	double r_kernel	=	pow(10, spec->sym[15]);			//distance of kernel to center, half of bond length	

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
'''

KERNEL_COORD	='''\
        //Particle Positions
        //O
        Vin[0].x = 0.0;
        Vin[0].y = 0.0;
        Vin[0].z = 0.0;
        Vin[0].q = %(charge)d;
        Vin[0].s = %(kernel)d;

'''

KERNEL_2_COORD	='''\
        //O
        Vin[1].x = 0.0;
        Vin[1].y = 0.0;
        Vin[1].z = 0.0;
        Vin[1].q = %(charge2)d;
        Vin[1].s = %(kernel2)d;

'''

SPIN_A8_COORD	='''\
        //a-1 
        Vin[1].x = ra1;
        Vin[1].y = ra1;
        Vin[1].z = ra1;
        Vin[1].q = -1;
        Vin[1].s = 2;
        Vin[1].d = da1_r+da1_i*I;
        Vin[1].eta = da2;
        Vin[1].zeta = da3;

        //a-2 
        Vin[2].x = ra1;
        Vin[2].y = ra1;
        Vin[2].z = -ra1;
        Vin[2].q = -1;
        Vin[2].s = 2;
        Vin[2].d = da1_r+da1_i*I;
        Vin[2].eta = da2;
        Vin[2].zeta = da3;

	//a-3 
        Vin[3].x = ra1;
        Vin[3].y = -ra1;
        Vin[3].z = ra1;
        Vin[3].q = -1;
        Vin[3].s = 2;
        Vin[3].d = da1_r+da1_i*I;
        Vin[3].eta = da2;
        Vin[3].zeta = da3;

	//a-4 
        Vin[4].x = ra1;
        Vin[4].y = -ra1;
        Vin[4].z = -ra1;
        Vin[4].q = -1;
        Vin[4].s = 2;
        Vin[4].d = da1_r+da1_i*I;
        Vin[4].eta = da2;
        Vin[4].zeta = da3;

        //a-5 
        Vin[5].x = -ra1;
        Vin[5].y = ra1;
        Vin[5].z = ra1;
        Vin[5].q = -1;
        Vin[5].s = 2;
        Vin[5].d = da1_r+da1_i*I;
        Vin[5].eta = da2;
        Vin[5].zeta = da3;

       //a-6 
        Vin[6].x = -ra1;
        Vin[6].y = ra1;
        Vin[6].z = -ra1;
        Vin[6].q = -1;
        Vin[6].s = 2;
        Vin[6].d = da1_r+da1_i*I;
        Vin[6].eta = da2;
        Vin[6].zeta = da3;

       //a-7 
        Vin[7].x = -ra1;
        Vin[7].y = -ra1;
        Vin[7].z = ra1;
        Vin[7].q = -1;
        Vin[7].s = 2;
        Vin[7].d = da1_r+da1_i*I;
        Vin[7].eta = da2;
        Vin[7].zeta = da3;

       //a-8 
        Vin[8].x = -ra1;
        Vin[8].y = -ra1;
        Vin[8].z = -ra1;
        Vin[8].q = -1;
        Vin[8].s = 2;
        Vin[8].d = da1_r+da1_i*I;
        Vin[8].eta = da2;
        Vin[8].zeta = da3;
'''

SPIN_A7_COORD	='''\
        //a-1 
        Vin[1].x = ra1;
        Vin[1].y = 0.0;
        Vin[1].z = 0.0;
        Vin[1].q = -1;
        Vin[1].s = 2;
        Vin[1].d = da1_r+da1_i*I;
        Vin[1].eta = da2;
        Vin[1].zeta = da3;

        //a-2 
        Vin[2].x = -ra1;
        Vin[2].y = 0.0;
        Vin[2].z = 0.0;
        Vin[2].q = -1;
        Vin[2].s = 2;
        Vin[2].d = da1_r+da1_i*I;
        Vin[2].eta = da2;
        Vin[2].zeta = da3;

	//a-3 
        Vin[3].x = 0.0;
        Vin[3].y = ra1;
        Vin[3].z = 0.0;
        Vin[3].q = -1;
        Vin[3].s = 2;
        Vin[3].d = da1_r+da1_i*I;
        Vin[3].eta = da2;
        Vin[3].zeta = da3;

	//a-4 
        Vin[4].x = 0.0;
        Vin[4].y = -ra1;
        Vin[4].z = 0.0;
        Vin[4].q = -1;
        Vin[4].s = 2;
        Vin[4].d = da1_r+da1_i*I;
        Vin[4].eta = da2;
        Vin[4].zeta = da3;

        //a-5 
        Vin[5].x = 0.0;
        Vin[5].y = 0.0;
        Vin[5].z = ra1;
        Vin[5].q = -1;
        Vin[5].s = 2;
        Vin[5].d = da1_r+da1_i*I;
        Vin[5].eta = da2;
        Vin[5].zeta = da3;

       //a-6 
        Vin[6].x = 0.0;
        Vin[6].y = 0.0;
        Vin[6].z = -ra1;
        Vin[6].q = -1;
        Vin[6].s = 2;
        Vin[6].d = da1_r+da1_i*I;
        Vin[6].eta = da2;
        Vin[6].zeta = da3;

        //a-7 
        Vin[7].x = 0.0;
        Vin[7].y = 0.0;
        Vin[7].z = 0.0;
        Vin[7].q = -1;
        Vin[7].s = 2;
        Vin[7].d = da1_r+da1_i*I;
        Vin[7].eta = da2;
        Vin[7].zeta = da3;

'''

SPIN_A6_COORD	='''\
        //a-1 
        Vin[1].x = ra1;
        Vin[1].y = 0.0;
        Vin[1].z = 0.0;
        Vin[1].q = -1;
        Vin[1].s = 2;
        Vin[1].d = da1_r+da1_i*I;
        Vin[1].eta = da2;
        Vin[1].zeta = da3;

        //a-2 
        Vin[2].x = -ra1;
        Vin[2].y = 0.0;
        Vin[2].z = 0.0;
        Vin[2].q = -1;
        Vin[2].s = 2;
        Vin[2].d = da1_r+da1_i*I;
        Vin[2].eta = da2;
        Vin[2].zeta = da3;

	//a-3 
        Vin[3].x = 0.0;
        Vin[3].y = ra1;
        Vin[3].z = 0.0;
        Vin[3].q = -1;
        Vin[3].s = 2;
        Vin[3].d = da1_r+da1_i*I;
        Vin[3].eta = da2;
        Vin[3].zeta = da3;

	//a-4 
        Vin[4].x = 0.0;
        Vin[4].y = -ra1;
        Vin[4].z = 0.0;
        Vin[4].q = -1;
        Vin[4].s = 2;
        Vin[4].d = da1_r+da1_i*I;
        Vin[4].eta = da2;
        Vin[4].zeta = da3;

        //a-5 
        Vin[5].x = 0.0;
        Vin[5].y = 0.0;
        Vin[5].z = ra1;
        Vin[5].q = -1;
        Vin[5].s = 2;
        Vin[5].d = da1_r+da1_i*I;
        Vin[5].eta = da2;
        Vin[5].zeta = da3;

       //a-6 
        Vin[6].x = 0.0;
        Vin[6].y = 0.0;
        Vin[6].z = -ra1;
        Vin[6].q = -1;
        Vin[6].s = 2;
        Vin[6].d = da1_r+da1_i*I;
        Vin[6].eta = da2;
        Vin[6].zeta = da3;

'''

SPIN_A5_COORD	='''\
       //a-1 
        Vin[1].x = 0.0;
        Vin[1].y = ra1;
        Vin[1].z = 0.0;
        Vin[1].q = -1;
        Vin[1].s = 2;
        Vin[1].d = da1_r+da1_i*I;
        Vin[1].eta = da2;
        Vin[1].zeta = da3;

       //a-2 
        Vin[2].x = 0.0;
        Vin[2].y = -ra1;
        Vin[2].z = 0.0;
        Vin[2].q = -1;
        Vin[2].s = 2;
        Vin[2].d = da1_r+da1_i*I;
        Vin[2].eta = da2;
        Vin[2].zeta = da3;

       //a-3 
        Vin[3].x = ra1;
        Vin[3].y = 0.0;
        Vin[3].z = 0.0;
        Vin[3].q = -1;
        Vin[3].s = 2;
        Vin[3].d = da1_r+da1_i*I;
        Vin[3].eta = da2;
        Vin[3].zeta = da3;

       //a-4 
        Vin[4].x = -0.5*ra1;
        Vin[4].y = 0.0;
        Vin[4].z = 0.5*sqrt(3.0)*ra1;
        Vin[4].q = -1;
        Vin[4].s = 2;
        Vin[4].d = da1_r+da1_i*I;
        Vin[4].eta = da2;
        Vin[4].zeta = da3;

       //a-5 
        Vin[5].x = -0.5*ra1;
        Vin[5].y = 0.0;
        Vin[5].z = -0.5*sqrt(3.0)*ra1;
        Vin[5].q = -1;
        Vin[5].s = 2;
        Vin[5].d = da1_r+da1_i*I;
        Vin[5].eta = da2;
        Vin[5].zeta = da3;

'''

SPIN_A4_COORD	='''\
       //a-1 
        Vin[1].x = ra1;
        Vin[1].y = ra1;
        Vin[1].z = ra1;
        Vin[1].q = -1;
        Vin[1].s = 2;
        Vin[1].d = da1_r+da1_i*I;
        Vin[1].eta = da2;
        Vin[1].zeta = da3;

       //a-2 
        Vin[2].x = ra1;
        Vin[2].y = -ra1;
        Vin[2].z = -ra1;
        Vin[2].q = -1;
        Vin[2].s = 2;
        Vin[2].d = da1_r+da1_i*I;
        Vin[2].eta = da2;
        Vin[2].zeta = da3;

       //a-3 
        Vin[3].x = -ra1;
        Vin[3].y = -ra1;
        Vin[3].z = ra1;
        Vin[3].q = -1;
        Vin[3].s = 2;
        Vin[3].d = da1_r+da1_i*I;
        Vin[3].eta = da2;
        Vin[3].zeta = da3;

       //a-4 
        Vin[4].x = -ra1;
        Vin[4].y = ra1;
        Vin[4].z = -ra1;
        Vin[4].q = -1;
        Vin[4].s = 2;
        Vin[4].d = da1_r+da1_i*I;
        Vin[4].eta = da2;
        Vin[4].zeta = da3;

'''

SPIN_A3_COORD	='''\
       //a-1 
        Vin[1].x = ra1;
        Vin[1].y = 0.0;
        Vin[1].z = 0.0;
        Vin[1].q = -1;
        Vin[1].s = 2;
        Vin[1].d = da1_r+da1_i*I;
        Vin[1].eta = da2;
        Vin[1].zeta = da3;

       //a-2 
        Vin[2].x = -0.5*ra1;
        Vin[2].y = 0.0;
        Vin[2].z = 0.5*sqrt(3.0)*ra1;
        Vin[2].q = -1;
        Vin[2].s = 2;
        Vin[2].d = da1_r+da1_i*I;
        Vin[2].eta = da2;
        Vin[2].zeta = da3;

       //a-3 
        Vin[3].x = -0.5*ra1;
        Vin[3].y = 0.0;
        Vin[3].z = -0.5*sqrt(3.0)*ra1;
        Vin[3].q = -1;
        Vin[3].s = 2;
        Vin[3].d = da1_r+da1_i*I;
        Vin[3].eta = da2;
        Vin[3].zeta = da3;

'''

SPIN_A2_COORD	='''\
       //a-1 
        Vin[1].x = 0.0;
        Vin[1].y = ra1;
        Vin[1].z = 0.0;
        Vin[1].q = -1;
        Vin[1].s = 2;
        Vin[1].d = da1_r+da1_i*I;
        Vin[1].eta = da2;
        Vin[1].zeta = da3;

       //a-2 
        Vin[2].x = 0.0;
        Vin[2].y = -ra1;
        Vin[2].z = 0.0;
        Vin[2].q = -1;
        Vin[2].s = 2;
        Vin[2].d = da1_r+da1_i*I;
        Vin[2].eta = da2;
        Vin[2].zeta = da3;

'''

SPIN_A1_COORD	='''\
       //a-1 
        Vin[1].x = 0.0;
        Vin[1].y = 0.0;
        Vin[1].z = 0.0;
        Vin[1].q = -1;
        Vin[1].s = 2;
        Vin[1].d = da1_r+da1_i*I;
        Vin[1].eta = da2;
        Vin[1].zeta = da3;

'''

SPIN_B6_COORD	='''\
        //b-1 
        Vin[%(spin_a)d+1].x = rot(rb1, 0.0, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+1].y = rot(rb1, 0.0, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+1].z = rot(rb1, 0.0, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+1].q = -1;
        Vin[%(spin_a)d+1].s = -2;
        Vin[%(spin_a)d+1].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+1].eta = db2;
        Vin[%(spin_a)d+1].zeta = db3;

	//b-2 
        Vin[%(spin_a)d+2].x = rot(-rb1, 0.0, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+2].y = rot(-rb1, 0.0, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+2].z = rot(-rb1, 0.0, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+2].q = -1;
        Vin[%(spin_a)d+2].s = -2;
        Vin[%(spin_a)d+2].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+2].eta = db2;
        Vin[%(spin_a)d+2].zeta = db3;

        //b-3 
        Vin[%(spin_a)d+3].x = rot(0.0, rb1, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+3].y = rot(0.0, rb1, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+3].z = rot(0.0, rb1, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+3].q = -1;
        Vin[%(spin_a)d+3].s = -2;
        Vin[%(spin_a)d+3].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+3].eta = db2;
        Vin[%(spin_a)d+3].zeta = db3;
        
        //b-4 
        Vin[%(spin_a)d+4].x = rot(0.0, -rb1, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+4].y = rot(0.0, -rb1, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+4].z = rot(0.0, -rb1, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+4].q = -1;
        Vin[%(spin_a)d+4].s = -2;
        Vin[%(spin_a)d+4].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+4].eta = db2;
        Vin[%(spin_a)d+4].zeta = db3;

        //b-5 
        Vin[%(spin_a)d+5].x = rot(0.0, 0.0, rb1, a, b, c, 0);
        Vin[%(spin_a)d+5].y = rot(0.0, 0.0, rb1, a, b, c, 1);
        Vin[%(spin_a)d+5].z = rot(0.0, 0.0, rb1, a, b, c, 2);
        Vin[%(spin_a)d+5].q = -1;
        Vin[%(spin_a)d+5].s = -2;
        Vin[%(spin_a)d+5].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+5].eta = db2;
        Vin[%(spin_a)d+5].zeta = db3;

        //b-6 
        Vin[%(spin_a)d+6].x = rot(0.0, 0.0, -rb1, a, b, c, 0);
        Vin[%(spin_a)d+6].y = rot(0.0, 0.0, -rb1, a, b, c, 1);
        Vin[%(spin_a)d+6].z = rot(0.0, 0.0, -rb1, a, b, c, 2);
        Vin[%(spin_a)d+6].q = -1;
        Vin[%(spin_a)d+6].s = -2;
        Vin[%(spin_a)d+6].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+6].eta = db2;
        Vin[%(spin_a)d+6].zeta = db3;

'''

SPIN_B5_COORD	='''\
       //b-1 
        Vin[%(spin_a)d+1].x = rot(0.0, rb1, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+1].y = rot(0.0, rb1, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+1].z = rot(0.0, rb1, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+1].q = -1;
        Vin[%(spin_a)d+1].s = -2;
        Vin[%(spin_a)d+1].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+1].eta = db2;
        Vin[%(spin_a)d+1].zeta = db3;

       //b-2 
        Vin[%(spin_a)d+2].x = rot(0.0, -rb1, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+2].y = rot(0.0, -rb1, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+2].z = rot(0.0, -rb1, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+2].q = -1;
        Vin[%(spin_a)d+2].s = -2;
        Vin[%(spin_a)d+2].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+2].eta = db2;
        Vin[%(spin_a)d+2].zeta = db3;

       //b-3 
        Vin[%(spin_a)d+3].x = rot(rb1, 0.0, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+3].y = rot(rb1, 0.0, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+3].z = rot(rb1, 0.0, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+3].q = -1;
        Vin[%(spin_a)d+3].s = -2;
        Vin[%(spin_a)d+3].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+3].eta = db2;
        Vin[%(spin_a)d+3].zeta = db3;

       //b-4 
        Vin[%(spin_a)d+4].x = rot(-0.5*rb1, 0.0, 0.5*sqrt(3.0)*rb1, a, b, c, 0);
        Vin[%(spin_a)d+4].y = rot(-0.5*rb1, 0.0, 0.5*sqrt(3.0)*rb1, a, b, c, 1);
        Vin[%(spin_a)d+4].z = rot(-0.5*rb1, 0.0, 0.5*sqrt(3.0)*rb1, a, b, c, 2);
        Vin[%(spin_a)d+4].q = -1;
        Vin[%(spin_a)d+4].s = -2;
        Vin[%(spin_a)d+4].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+4].eta = db2;
        Vin[%(spin_a)d+4].zeta = db3;

       //b-5 
        Vin[%(spin_a)d+5].x = rot(-0.5*rb1, 0.0, -0.5*sqrt(3.0)*rb1, a, b, c, 0);
        Vin[%(spin_a)d+5].y = rot(-0.5*rb1, 0.0, -0.5*sqrt(3.0)*rb1, a, b, c, 1);
        Vin[%(spin_a)d+5].z = rot(-0.5*rb1, 0.0, -0.5*sqrt(3.0)*rb1, a, b, c, 2);
        Vin[%(spin_a)d+5].q = -1;
        Vin[%(spin_a)d+5].s = -2;
        Vin[%(spin_a)d+5].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+5].eta = db2;
        Vin[%(spin_a)d+5].zeta = db3;

'''

SPIN_B4_COORD	='''\
       //b-1 
        Vin[%(spin_a)d+1].x = rot(rb1, rb1, rb1, a, b, c, 0);
        Vin[%(spin_a)d+1].y = rot(rb1, rb1, rb1, a, b, c, 1);
        Vin[%(spin_a)d+1].z = rot(rb1, rb1, rb1, a, b, c, 2);
        Vin[%(spin_a)d+1].q = -1;
        Vin[%(spin_a)d+1].s = -2;
        Vin[%(spin_a)d+1].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+1].eta = db2;
        Vin[%(spin_a)d+1].zeta = db3;

       //b-2 
        Vin[%(spin_a)d+2].x = rot(rb1, -rb1, -rb1, a, b, c, 0);
        Vin[%(spin_a)d+2].y = rot(rb1, -rb1, -rb1, a, b, c, 1);
        Vin[%(spin_a)d+2].z = rot(rb1, -rb1, -rb1, a, b, c, 2);
        Vin[%(spin_a)d+2].q = -1;
        Vin[%(spin_a)d+2].s = -2;
        Vin[%(spin_a)d+2].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+2].eta = db2;
        Vin[%(spin_a)d+2].zeta = db3;

       //b-3 
        Vin[%(spin_a)d+3].x = rot(-rb1, rb1, -rb1, a, b, c, 0);
        Vin[%(spin_a)d+3].y = rot(-rb1, rb1, -rb1, a, b, c, 1);
        Vin[%(spin_a)d+3].z = rot(-rb1, rb1, -rb1, a, b, c, 2);
        Vin[%(spin_a)d+3].q = -1;
        Vin[%(spin_a)d+3].s = -2;
        Vin[%(spin_a)d+3].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+3].eta = db2;
        Vin[%(spin_a)d+3].zeta = db3;

       //b-4 
        Vin[%(spin_a)d+4].x = rot(-rb1, -rb1, rb1, a, b, c, 0);
        Vin[%(spin_a)d+4].y = rot(-rb1, -rb1, rb1, a, b, c, 1);
        Vin[%(spin_a)d+4].z = rot(-rb1, -rb1, rb1, a, b, c, 2);
        Vin[%(spin_a)d+4].q = -1;
        Vin[%(spin_a)d+4].s = -2;
        Vin[%(spin_a)d+4].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+4].eta = db2;
        Vin[%(spin_a)d+4].zeta = db3;

'''

SPIN_B3_COORD	='''\
       //b-1 
        Vin[%(spin_a)d+1].x = rot(rb1, 0.0, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+1].y = rot(rb1, 0.0, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+1].z = rot(rb1, 0.0, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+1].q = -1;
        Vin[%(spin_a)d+1].s = -2;
        Vin[%(spin_a)d+1].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+1].eta = db2;
        Vin[%(spin_a)d+1].zeta = db3;

       //b-2 
        Vin[%(spin_a)d+2].x = rot(-0.5*rb1, 0.0, 0.5*sqrt(3.0)*rb1, a, b, c, 0);
        Vin[%(spin_a)d+2].y = rot(-0.5*rb1, 0.0, 0.5*sqrt(3.0)*rb1, a, b, c, 1);
        Vin[%(spin_a)d+2].z = rot(-0.5*rb1, 0.0, 0.5*sqrt(3.0)*rb1, a, b, c, 2);
        Vin[%(spin_a)d+2].q = -1;
        Vin[%(spin_a)d+2].s = -2;
        Vin[%(spin_a)d+2].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+2].eta = db2;
        Vin[%(spin_a)d+2].zeta = db3;

       //b-3 
        Vin[%(spin_a)d+3].x = rot(-0.5*rb1, 0.0, -0.5*sqrt(3.0)*rb1, a, b, c, 0);
        Vin[%(spin_a)d+3].y = rot(-0.5*rb1, 0.0, -0.5*sqrt(3.0)*rb1, a, b, c, 1);
        Vin[%(spin_a)d+3].z = rot(-0.5*rb1, 0.0, -0.5*sqrt(3.0)*rb1, a, b, c, 2);
        Vin[%(spin_a)d+3].q = -1;
        Vin[%(spin_a)d+3].s = -2;
        Vin[%(spin_a)d+3].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+3].eta = db2;
        Vin[%(spin_a)d+3].zeta = db3;

'''

SPIN_B2_COORD	='''\
       //b-1 
        Vin[%(spin_a)d+1].x = rot(0.0, rb1, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+1].y = rot(0.0, rb1, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+1].z = rot(0.0, rb1, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+1].q = -1;
        Vin[%(spin_a)d+1].s = -2;
        Vin[%(spin_a)d+1].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+1].eta = db2;
        Vin[%(spin_a)d+1].zeta = db3;

       //b-2 
        Vin[%(spin_a)d+2].x = rot(0.0, -rb1, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+2].y = rot(0.0, -rb1, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+2].z = rot(0.0, -rb1, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+2].q = -1;
        Vin[%(spin_a)d+2].s = -2;
        Vin[%(spin_a)d+2].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+2].eta = db2;
        Vin[%(spin_a)d+2].zeta = db3;

'''

SPIN_B1_COORD	='''\
       //b-1 
        Vin[%(spin_a)d+1].x = rot(0.0, 0.0, 0.0, a, b, c, 0);
        Vin[%(spin_a)d+1].y = rot(0.0, 0.0, 0.0, a, b, c, 1);
        Vin[%(spin_a)d+1].z = rot(0.0, 0.0, 0.0, a, b, c, 2);
        Vin[%(spin_a)d+1].q = -1;
        Vin[%(spin_a)d+1].s = -2;
        Vin[%(spin_a)d+1].d = db1_r+db1_i*I;
        Vin[%(spin_a)d+1].eta = db2;
        Vin[%(spin_a)d+1].zeta = db3;

'''

FORMAT2	='''
        //set d value
        setDvalue(Vin, part);

	//calculate structure energy
        if((MC_spin%(fullname)s) && (spec->icue ==4)){
                Usum = metropolis(Vin, part,-3);//fix heavy
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = Usum*1E3;
	U_spin%(fullname)s = Usum;

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//asign coordinate to structure
        for (i=0; i<part; i++){
        spec->coord[i].x = Vin[i].x;
        spec->coord[i].y = Vin[i].y;
        spec->coord[i].z = Vin[i].z;
        spec->coord[i].d = Vin[i].d;
        spec->coord[i].eta = Vin[i].eta;
        spec->coord[i].zeta = Vin[i].zeta;
        spec->coord[i].q = Vin[i].q;
        spec->coord[i].s = Vin[i].s;
        }

	//return structure energy
        return Usum;

}


double devspin%(fullname)s(Species *spec){

        double deviation = 0;
        double wTotal    = 0;
	double *items;
        FILE *OutFile;
	char Out[50];
        extern char directory[];
        extern int print;
        extern int pdbSwitch;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double fr1, fr2, fr3, fd3, fd4, fd5, fd6;
	double complex fd1, fd2;

        //Current Positions
        if (MC_spin%(fullname)s){
		fr1    = getDistance(spec->coord, 0, 1);
		fr2    = getDistance(spec->coord, 0, spec->numPart-1);
		fd1    = spec->coord[1].d;
		fd2    = spec->coord[spec->numPart-1].d;
		fd3    = spec->coord[1].eta;
		fd4    = spec->coord[spec->numPart-1].eta;
		fd5    = spec->coord[1].zeta;
		fd6    = spec->coord[spec->numPart-1].zeta;
        }

	double polar=0.0;
	polar=getPolar(spec->coord,spec->numPart);
        deviation = polar*exp(10*polar);

	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spin%(fullname)s){
                         fprintf(OutFile,"| Lone A1  dist         |      A     |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", fr1);
                         fprintf(OutFile,"| Lone B1  dist         |      A     |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", fr2);
                         fprintf(OutFile,"| Lone A1 1/radius^2    |    1/A^2   |      -         |   -   |                |%%7.3f+%%7.3fI|   N/A   |       -       |\\n", creal(fd1), cimag(fd1));
                         fprintf(OutFile,"| Lone B1 1/radius^2    |    1/A^2   |      -         |   -   |                |%%7.3f+%%7.3fI|   N/A   |       -       |\\n", creal(fd2), cimag(fd2));
                         fprintf(OutFile,"| Lone A1  eta          |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", fd3);
                         fprintf(OutFile,"| Lone B1  eta          |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", fd4);
                         fprintf(OutFile,"| Lone A1  zeta         |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", fd5);
                         fprintf(OutFile,"| Lone B1  zeta         |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", fd6);
                         fprintf(OutFile,"| Polarity              |      -     |      -         |   -   |                |    %%8.2f    |   N/A   |       -       |\\n", polar);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\\n");
	    	fclose(OutFile);
		printEnergy(U_spin%(fullname)s);
	}

	//structure output
	sprintf(Out, "MC_spin%%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spin%(fullname)s)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	double scaledDev;
	scaledDev = 100*deviation;
	return scaledDev;

}
'''

# Fix all heavy atoms, no structure deviation.
DEV0	='''
        //set d value
        setDvalue(Vin, part);

	//calculate structure energy
        if((MC_spin%(fullname)s) && (spec->icue ==4)){
		for(i=0;i<4;i++){
                	metropolis(Vin, part,-3);//fix heavy
		}
                Usum = metropolis(Vin, part,-3);//fix heavy
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = Usum*1E3;
	U_spin%(fullname)s = Usum;

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//asign coordinate to structure
        for (i=0; i<part; i++){
        spec->coord[i].x = Vin[i].x;
        spec->coord[i].y = Vin[i].y;
        spec->coord[i].z = Vin[i].z;
        spec->coord[i].d = Vin[i].d;
        spec->coord[i].eta = Vin[i].eta;
        spec->coord[i].zeta = Vin[i].zeta;
        spec->coord[i].q = Vin[i].q;
        spec->coord[i].s = Vin[i].s;
        }

	//return structure energy
        return Usum;

}


double devspin%(fullname)s(Species *spec){

        double deviation = 0;
        double wTotal    = 0;
	double *items;
        FILE *OutFile;
	char Out[50];
        extern char directory[];
        extern int print;
        extern int pdbSwitch;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double fr1, bo;
	const double real_bl = %(real_bl).2f;
//	const double real_bo = %(real_bo).1f; 

        //Current Positions
        if (MC_spin%(fullname)s){
		fr1    = getDistance(spec->coord, 0, 1);
		//bo     = getBondOrder(spec->coord, spec->numPart, real_bl);
        }
	
	//deviation = fabs(real_bl-fr1)/LENGTH;
	//deviation = fabs(real_bo-bo)/LENGTH;
	deviation = 0;	

	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spin%(fullname)s){
			fprintf(OutFile,"| Kernel  dist          |      A     |   %% 8.2f     |   -   |        -       |    %%8.5f    |   N/A   |       -       |\\n", real_bl, fr1);
			fprintf(OutFile,"| A1 1/radius^2         |      A     |      -         |   -   |        -       |%%7.3f+%%7.3fI|   N/A   |       -       |\\n", creal(spec->coord[%(kernel)d].d), cimag(spec->coord[%(kernel)d].d));
			fprintf(OutFile,"| Lone A1  eta          |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", spec->coord[%(kernel)d].eta);
			fprintf(OutFile,"| Lone A1  zeta         |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", spec->coord[%(kernel)d].zeta);
			//fprintf(OutFile,"| Bond Order            |      -     |   %% 8.2f     |   -   |        -       |    %%8.2f    |   N/A   |  %% 8.2e    |\\n", real_bo, bo,deviation*100);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\\n");
	    	fclose(OutFile);
		printEnergy(U_spin%(fullname)s);
	}

	//structure output
	sprintf(Out, "MC_spin%%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spin%(fullname)s)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	double scaledDev;
	scaledDev = 100*deviation;
	return scaledDev;

}
'''

# Fix all atoms, include bond order in deviation
DEV1	='''
        //set d value
        setDvalue(Vin, part);

	//calculate structure energy
        if((MC_spin%(fullname)s) && (spec->icue ==4)){
		for(i=0;i<4;i++){
                	metropolis(Vin, part,-1);
		}
                Usum = metropolis(Vin, part,-1);
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = Usum*1E3;
	U_spin%(fullname)s = Usum;

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//asign coordinate to structure
        for (i=0; i<part; i++){
        spec->coord[i].x = Vin[i].x;
        spec->coord[i].y = Vin[i].y;
        spec->coord[i].z = Vin[i].z;
        spec->coord[i].d = Vin[i].d;
        spec->coord[i].eta = Vin[i].eta;
        spec->coord[i].zeta = Vin[i].zeta;
        spec->coord[i].q = Vin[i].q;
        spec->coord[i].s = Vin[i].s;
        }

	//return structure energy
        return Usum;

}


double devspin%(fullname)s(Species *spec){

        double deviation = 0;
        double wTotal    = 0;
	double *items;
        FILE *OutFile;
	char Out[50];
        extern char directory[];
        extern int print;
        extern int pdbSwitch;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double fr1, bo;
	const double real_bl = %(real_bl).2f;
	const double real_bo = %(real_bo).1f; 

        //Current Positions
        if (MC_spin%(fullname)s){
		fr1    = getDistance(spec->coord, 0, 1);
		bo     = getBondOrder(spec->coord, spec->numPart, real_bl);
        }
	
	deviation = fabs(real_bo-bo)/LENGTH;

	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spin%(fullname)s){
			fprintf(OutFile,"| Kernel  dist          |      A     |   %% 8.2f     |   -   |        -       |    %%8.5f    |   N/A   |       -       |\\n", real_bl, fr1);
			fprintf(OutFile,"| A1 1/radius^2         |    1/A^2   |      -         |   -   |        -       |%%7.3f+%%7.3fI|   N/A   |       -       |\\n", creal(spec->coord[%(kernel)d].d), cimag(spec->coord[%(kernel)d].d));
			fprintf(OutFile,"| Lone A1  eta          |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", spec->coord[%(kernel)d].eta);
			fprintf(OutFile,"| Lone A1  zeta         |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", spec->coord[%(kernel)d].zeta);
			fprintf(OutFile,"| Bond Order            |      -     |   %% 8.2f     |   -   |        -       |    %%8.2f    |   N/A   |  %% 8.2e    |\\n", real_bo, bo,deviation*100);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\\n");
	    	fclose(OutFile);
		printEnergy(U_spin%(fullname)s);
	}

	//structure output
	sprintf(Out, "MC_spin%%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spin%(fullname)s)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	double scaledDev;
	scaledDev = 100*deviation;
	return scaledDev;

}
'''

# Move everything, include bond length in deviation.
DEV2	='''
        //set d value
        setDvalue(Vin, part);

	//calculate structure energy
        if((MC_spin%(fullname)s) && (spec->icue ==4)){
		for(i=0;i<4;i++){
                	metropolis(Vin, part,-1);//move everything
		}
                Usum = metropolis(Vin, part,-1);//move everything
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = Usum*1E3;
	U_spin%(fullname)s = Usum;

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//asign coordinate to structure
        for (i=0; i<part; i++){
        spec->coord[i].x = Vin[i].x;
        spec->coord[i].y = Vin[i].y;
        spec->coord[i].z = Vin[i].z;
        spec->coord[i].d = Vin[i].d;
        spec->coord[i].eta = Vin[i].eta;
        spec->coord[i].zeta = Vin[i].zeta;
        spec->coord[i].q = Vin[i].q;
        spec->coord[i].s = Vin[i].s;
        }

	//return structure energy
        return Usum;

}


double devspin%(fullname)s(Species *spec){

        double deviation = 0;
        double wTotal    = 0;
	double *items;
        FILE *OutFile;
	char Out[50];
        extern char directory[];
        extern int print;
        extern int pdbSwitch;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double fr1, bo;
	const double real_bl = %(real_bl).2f;
	const double real_bo = %(real_bo).1f; 

        //Current Positions
        if (MC_spin%(fullname)s){
		fr1    = getDistance(spec->coord, 0, 1);
		//bo     = getBondOrder(spec->coord, spec->numPart, real_bl);
        }
	
	deviation = fabs(real_bl-fr1)/LENGTH;
	//deviation = fabs(real_bo-bo)/LENGTH;
	
	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spin%(fullname)s){
			fprintf(OutFile,"| Kernel  dist          |      A     |    %% 8.2f    |   -   |        -       |    %%8.5f    |   N/A   |       -       |\\n", real_bl, fr1);
			fprintf(OutFile,"| Ex.  A1 1/radius^2    |    1/A^2   |      -         |   -   |        -       |%%7.3f+%%7.3fI|   N/A   |       -       |\\n", creal(spec->coord[%(kernel)d].d), cimag(spec->coord[%(kernel)d].d));
			fprintf(OutFile,"| Lone A1  eta          |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", spec->coord[%(kernel)d].eta);
			fprintf(OutFile,"| Lone A1  zeta         |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", spec->coord[%(kernel)d].zeta);
			//fprintf(OutFile,"| Bond Order            |      -     |   %% 8.2f     |   -   |        -       |    %%8.2f    |   N/A   |  %% 8.2e    |\\n", real_bo, bo,deviation*100);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\\n");
	    	fclose(OutFile);
		printEnergy(U_spin%(fullname)s);
	}

	//structure output
	sprintf(Out, "MC_spin%%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spin%(fullname)s)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	double scaledDev;
	scaledDev = 100*deviation;
	return scaledDev;

}
'''

# Fix all atoms, include dipole momemnt in deviation.
DEV3	='''
        //set d value
        setDvalue(Vin, part);

	//calculate structure energy
        if((MC_spin%(fullname)s) && (spec->icue ==4)){
		for(i=0;i<4;i++){
                	metropolis(Vin, part,-3);
		}
                Usum = metropolis(Vin, part,-3);
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = Usum*1E3;
	U_spin%(fullname)s = Usum;

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	//asign coordinate to structure
        for (i=0; i<part; i++){
        spec->coord[i].x = Vin[i].x;
        spec->coord[i].y = Vin[i].y;
        spec->coord[i].z = Vin[i].z;
        spec->coord[i].d = Vin[i].d;
        spec->coord[i].eta = Vin[i].eta;
        spec->coord[i].zeta = Vin[i].zeta;
        spec->coord[i].q = Vin[i].q;
        spec->coord[i].s = Vin[i].s;
        }

	//return structure energy
        return Usum;

}


double devspin%(fullname)s(Species *spec){

        double deviation = 0;
        double wTotal    = 0;
	double *items;
        FILE *OutFile;
	char Out[50];
        extern char directory[];
        extern int print;
        extern int pdbSwitch;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	double fr1, bo, dp;
	const double real_bl = %(real_bl).2f;
	const double real_bo = %(real_bo).1f; 
	const double real_dp = %%DipoleMoment%%; 

        //Current Positions
        if (MC_spin%(fullname)s){
		fr1    = getDistance(spec->coord, 0, 1);
		//bo     = getBondOrder(spec->coord, spec->numPart, real_bl);
		dp     = getDipole(spec->coord, spec->numPart);
        }
	
	//deviation = fabs(real_bl-fr1)/LENGTH;
	//deviation = fabs(real_bo-bo)/LENGTH;
	deviation = fabs(real_dp-dp)/LENGTH;

	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spin%(fullname)s){
			fprintf(OutFile,"| Kernel  dist          |      A     |   %% 8.2f     |   -   |        -       |    %%8.5f    |   N/A   |       -       |\\n", real_bl, fr1);
			fprintf(OutFile,"| A1 1/radius^2         |    1/A^2   |      -         |   -   |        -       |%%7.3f+%%7.3fI|   N/A   |       -       |\\n", creal(spec->coord[%(kernel)d].d), cimag(spec->coord[%(kernel)d].d));
			fprintf(OutFile,"| Lone A1  eta          |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", spec->coord[%(kernel)d].eta);
			fprintf(OutFile,"| Lone A1  zeta         |            |      -         |   -   |                |    %%8.5f    |   N/A   |       -       |\\n", spec->coord[%(kernel)d].zeta);
			//fprintf(OutFile,"| Bond Order            |      -     |   %% 8.2f     |   -   |        -       |    %%8.2f    |   N/A   |  %% 8.2e    |\\n", real_bo, bo,deviation*100);
			fprintf(OutFile,"| Dipole                |      -     |   %% 8.2f     |   -   |        -       |    %%8.2f    |   N/A   |  %% 8.2e    |\\n", real_dp, dp, deviation*100);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\\n");
	    	fclose(OutFile);
		printEnergy(U_spin%(fullname)s);
	}

	//structure output
	sprintf(Out, "MC_spin%%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spin%(fullname)s)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	double scaledDev;
	scaledDev = 100*deviation;
	return scaledDev;

}
'''
def writemonatomic(monatomic):
	for i in range(len(monatomic)):
		fullname = monatomic[i][0]
		name = monatomic[i][1]
		q = int(monatomic[i][2])
		s = int(monatomic[i][3])
		spin_a = int(monatomic[i][4])
		spin_b = int(monatomic[i][5])
		OUTPUT = "spin"+monatomic[i][0]+".c"
		g = open(OUTPUT, 'w')
		text = FORMAT0%{'fullname':fullname,
				'name':name,
				'kernel':1,
				'spin_a':spin_a,
				'spin_b':spin_b,
				'numPart':spin_a + spin_b + 1,
				'distance':1,
			       }

		if spin_a in {8, 7, 6, 5, 4, 3, 2}: 
			text += '''\
	spec->key[0] = 1;
	spec->key[4] = 1;
	spec->key[6] = 1;
	spec->key[8] = 1;
	spec->key[10] = 1;

'''
		elif spin_a == 1:
			text += '''\
	spec->key[4] = 1;
	spec->key[6] = 1;
	spec->key[8] = 1;
	spec->key[10] = 1;

'''
		else:
			print('Spin_a out of range!\n')
		if spin_b in {6, 5, 4, 3, 2}: 
			text += '''\
	spec->key[1] = 1;
	spec->key[5] = 1;
	spec->key[7] = 1;
	spec->key[9] = 1;
	spec->key[11] = 1;

'''
		elif spin_b == 1:
			text += '''\
	spec->key[5] = 1;
	spec->key[7] = 1;
	spec->key[9] = 1;
	spec->key[11] = 1;

'''
		elif spin_b == 0:
			pass
		else:
			print('Spin_b out of range!\n')
		text += FORMAT1%{'fullname':fullname,
				 'name':name,
				 'kernel':1,
				 'spin_a':spin_a,
				 'spin_b':spin_b,
				 'numPart':spin_a + spin_b + 1,
				 'distance':1,
			        }
		text += KERNEL_COORD%{'charge':q,
				      'kernel':s,
				     } 
		if spin_a == 8:
			text += SPIN_A8_COORD
		elif spin_a == 7:
			text += SPIN_A7_COORD
		elif spin_a == 6:
			text += SPIN_A6_COORD
		elif spin_a == 5:
			text += SPIN_A5_COORD
		elif spin_a == 4:
			text += SPIN_A4_COORD
		elif spin_a == 3:
			text += SPIN_A3_COORD
		elif spin_a == 2:
			text += SPIN_A2_COORD
		elif spin_a == 1:
			text += SPIN_A1_COORD
		else:
			print('Spin_a should be set!\n')
	
		if spin_b == 6:
			text += SPIN_B6_COORD%{
					       'spin_a':spin_a,
					      }
		elif spin_b == 5:
			text += SPIN_B5_COORD%{
					       'spin_a':spin_a,
					      }
		elif spin_b == 4:
			text += SPIN_B4_COORD%{
					       'spin_a':spin_a,
					      }
		elif spin_b == 3:
			text += SPIN_B3_COORD%{
					       'spin_a':spin_a,
					      }
		elif spin_b == 2:
			text += SPIN_B2_COORD%{
					       'spin_a':spin_a,
					      }
		elif spin_b == 1:
			text += SPIN_B1_COORD%{
					       'spin_a':spin_a,
					      }
		else:
			pass
	
		text += FORMAT2%{'fullname':fullname,}
				 	
		g.write(text)		
		g.close()

def writediatomic(diatomic):
	for i in range(len(diatomic)):
		fullname = diatomic[i][0]
		name = diatomic[i][1]
		FIX = int(diatomic[i][2])
		q1 = int(diatomic[i][3])
		s1 = int(diatomic[i][4])
		q2 = int(diatomic[i][5])
		s2 = int(diatomic[i][6])
		spin_a = int(diatomic[i][7])
		spin_b = int(diatomic[i][8])
		real_bl = float(diatomic[i][9])
		real_bo = float(diatomic[i][10])
		COORD = "../Coordinates/Repository/"+"coord"+diatomic[i][0]+".in"
		OUTPUT = "spin"+diatomic[i][0]+".c"
		f = open(COORD, 'r')
		g = open(OUTPUT, 'w')
		text = FORMAT0%{'fullname':fullname,
				'name':name,
				'kernel':2,
				'spin_a':spin_a,
				'spin_b':spin_b,
				'numPart':spin_a + spin_b + 2,
				'distance':real_bl/2.0,
			       }
		text += FORMAT1%{'fullname':fullname,
				'name':name,
				'kernel':2,
				'spin_a':spin_a,
				'spin_b':spin_b,
				'numPart':spin_a + spin_b + 2,
				'distance':real_bl/2.0,
			       }
##		text += KERNEL_COORD%{'charge':q1,
##				      'kernel':s1,
##				     } 
##		text += KERNEL_2_COORD%{'charge2':q2,
##				      'kernel2':s2,
##				     } 
##		text += "/*##################################################\n"
##		text += "#                                                  #\n"
##		text += "#                                                  #\n"
##		text += "#                                                  #\n"
##		text += "# Replaced With Costomized Structure Coordinates!  #\n"
##		text += "#                                                  #\n"
##		text += "#                                                  #\n"
##		text += "#                                                  #\n"
##		text += "##################################################*/\n\n"
		text += f.read()
		if FIX == 1:
			text += DEV1%{'fullname':fullname,
					 'real_bl':real_bl,
					 'real_bo':real_bo,
					 'kernel':2,
					}
		elif FIX == 2:
			text += DEV2%{'fullname':fullname,
					 'real_bl':real_bl,
					 'real_bo':real_bo,
					 'kernel':2,
					}		 
		elif FIX == 3:
			text += DEV3%{'fullname':fullname,
					 'real_bl':real_bl,
					 'real_bo':real_bo,
					 'kernel':2,
					}		 
		else:
			text += DEV0%{'fullname':fullname,
					 'real_bl':real_bl,
					 'real_bo':real_bo,
					 'kernel':2,
					}		 
		g.write(text)		
		f.close()
		g.close()

def writetriatomic(triatomic):
	for i in range(len(triatomic)):
		fullname = triatomic[i][0]
		name = triatomic[i][1]
		FIX = int(triatomic[i][2])
		q1 = int(triatomic[i][3])
		s1 = int(triatomic[i][4])
		q2 = int(triatomic[i][5])
		s2 = int(triatomic[i][6])
		q3 = int(triatomic[i][7])
		s3 = int(triatomic[i][8])
		spin_a = int(triatomic[i][9])
		spin_b = int(triatomic[i][10])
		real_bl = float(triatomic[i][11])
		real_bo = float(triatomic[i][12])
		COORD = "../Coordinates/Repository/"+"coord"+triatomic[i][0]+".in"
		OUTPUT = "spin"+triatomic[i][0]+".c"
		f = open(COORD, 'r')
		g = open(OUTPUT, 'w')
		text = FORMAT0%{'fullname':fullname,
				'name':name,
				'kernel':3,
				'spin_a':spin_a,
				'spin_b':spin_b,
				'numPart':spin_a + spin_b + 3,
				'distance':real_bl/2.0,
			       }
		text += FORMAT1%{'fullname':fullname,
				'name':name,
				'kernel':3,
				'spin_a':spin_a,
				'spin_b':spin_b,
				'numPart':spin_a + spin_b + 3,
				'distance':real_bl/2.0,
			       }
##		text += KERNEL_COORD%{'charge':q1,
##				      'kernel':s1,
##				     } 
##		text += KERNEL_2_COORD%{'charge2':q2,
##				      'kernel2':s2,
##				     } 
##		text += "/*##################################################\n"
##		text += "#                                                  #\n"
##		text += "#                                                  #\n"
##		text += "#                                                  #\n"
##		text += "# Replaced With Costomized Structure Coordinates!  #\n"
##		text += "#                                                  #\n"
##		text += "#                                                  #\n"
##		text += "#                                                  #\n"
##		text += "##################################################*/\n\n"
		text += f.read()
		if FIX == 1:
			text += DEV1%{'fullname':fullname,
					 'real_bl':real_bl,
					 'real_bo':real_bo,
					 'kernel':3,
					}
		elif FIX == 2:
			text += DEV2%{'fullname':fullname,
					 'real_bl':real_bl,
					 'real_bo':real_bo,
					 'kernel':3,
					}		 
		elif FIX == 3:
			text += DEV3%{'fullname':fullname,
					 'real_bl':real_bl,
					 'real_bo':real_bo,
					 'kernel':3,
					}		 
		else:
			text += DEV0%{'fullname':fullname,
					 'real_bl':real_bl,
					 'real_bo':real_bo,
					 'kernel':3,
					}		 
		g.write(text)		
		g.close()

if __name__ == "__main__":
	monatomic = []
	diatomic = []
	triatomic = []
	f = open(INPUT, 'r')
	line = f.readline()
	while line:
		if line.find('Fullname') != -1:
			pass
		elif line.startswith("#") or line.startswith("/"):
			pass
		else:
			strs = line.strip().split()
			if len(strs) == 6:
				monatomic.append(strs)
			elif len(strs) == 11:
				diatomic.append(strs)
			elif len(strs) == 13:
				triatomic.append(strs)
			else:
				pass
#			fullname = line.split('=')[1].strip()
#		if line.find('Name') != -1:
#			name = line.split('=')[1].strip()
#		if line.find('Charge') != -1:
#			q = int(line.split('=')[1].strip())
#		if line.find('Kernel') != -1:
#			s = int(line.split('=')[1].strip())
#		if line.find('Spin_a') != -1:
#			spin_a = int(line.split('=')[1].strip())
#		if line.find('Spin_b') != -1:
#			spin_b = int(line.split('=')[1].strip())
		line = f.readline()
	f.close()
	writemonatomic(monatomic)
	writediatomic(diatomic)
	writetriatomic(triatomic)

