#include "Structure.h"

extern double U_spinO_1;					//declare structure energy                           

void specspinO_1(Species * spec){				//define SPEC function for specific structure

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

	strcpy(spec->fullname, "O_1");			//Enter full name for the structure
	strcpy(spec->name, "O-1");				//Enter abbreviation name
	strcpy(spec->spin, "a4b3");		//Enter spin structure
	spec->type = O_1;				//Enter type name
	spec->complete = 0;					//Not used temporarily
	spec->kernel = 1;					//Not used temporarily
	spec->degFree = 16;					//Enter degree of freedom for the structure
	spec->numPart = 8;					//Enter number of particles for the structure
	spec->stepSize = 0.101;					//Enter the stepsize for optimization, default is 0.101
	spec->ainter = ainterspinO_1;			//Enter the function name for "ainter" 
	spec->dev = devspinO_1;			//Enter the function name for "dev"

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
        spec->ist[15] = 1.000000; 

        //translate initial values into log10 form for upnup, set Key
        int i;
        for(i = 0; i < spec->degFree; i++){
                spec->key[i] = 0;
                spec->sym[i] = log10(spec->ist[i]);
        }

        spec->sym[12] = log10((pi / spec->ist[0]) - 1);
        spec->sym[13] = log10((pi / spec->ist[0]) - 1);
        spec->sym[14] = log10((pi / spec->ist[0]) - 1);

	spec->key[0] = 1;
	spec->key[4] = 1;
	spec->key[6] = 1;
	spec->key[8] = 1;
	spec->key[10] = 1;

	spec->key[1] = 1;
	spec->key[5] = 1;
	spec->key[7] = 1;
	spec->key[9] = 1;
	spec->key[11] = 1;

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


double ainterspinO_1(Species * spec){
	
	int i, part;
	double Usum;
	part = spec->numPart;
        V Vin[part];

        double ra1	=	pow(10, spec->sym[0]);			//distance from O to electron alpha1's
        double rb1	=	pow(10, spec->sym[1]);			//distance from O to electron beta1's
        double ra2	=	pow(10, spec->sym[2]);			//distance from O to electron alpha1's
        double rb2	=	pow(10, spec->sym[3]);			//distance from O to electron beta1's
        
        double da1_r	=	pow(10, spec->sym[4]);			//diameter of electron alpha1's
        double db1_r	=	pow(10, spec->sym[6]);			//diameter of electron beta1's
        double da1_i	=	pow(10, spec->sym[5]);			//diameter of electron alpha2's
        double db1_i	=	pow(10, spec->sym[7]);			//diameter of electron beta2's

        double da2	=	pow(10, spec->sym[8]);			//diameter of electron alpha1's
        double db2	=	pow(10, spec->sym[9]);			//diameter of electron alpha2's
        double da3	=	pow(10, spec->sym[10]);			//diameter of electron beta1's
        double db3	=	pow(10, spec->sym[11]);			//diameter of electron beta2's

	double a	=	pi / (1 + pow(10, spec->sym[12]));	//rotation angle a
	double b	=	pi / (1 + pow(10, spec->sym[13]));	//rotation angle b
	double c	=	pi / (1 + pow(10, spec->sym[14]));	//rotation angle c

	double r_kernel	=	pow(10, spec->sym[15]);			//distance of kernel to center	

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BELOW CHANGABLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
        //Particle Positions
        //O
        Vin[0].x = 0.0;
        Vin[0].y = 0.0;
        Vin[0].z = 0.0;
        Vin[0].q = 6;
        Vin[0].s = 8;

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

       //b-1 
        Vin[4+1].x = rot(rb1, 0.0, 0.0, a, b, c, 0);
        Vin[4+1].y = rot(rb1, 0.0, 0.0, a, b, c, 1);
        Vin[4+1].z = rot(rb1, 0.0, 0.0, a, b, c, 2);
        Vin[4+1].q = -1;
        Vin[4+1].s = -2;
        Vin[4+1].d = db1_r+db1_i*I;
        Vin[4+1].eta = db2;
        Vin[4+1].zeta = db3;

       //b-2 
        Vin[4+2].x = rot(-0.5*rb1, 0.0, 0.5*sqrt(3.0)*rb1, a, b, c, 0);
        Vin[4+2].y = rot(-0.5*rb1, 0.0, 0.5*sqrt(3.0)*rb1, a, b, c, 1);
        Vin[4+2].z = rot(-0.5*rb1, 0.0, 0.5*sqrt(3.0)*rb1, a, b, c, 2);
        Vin[4+2].q = -1;
        Vin[4+2].s = -2;
        Vin[4+2].d = db1_r+db1_i*I;
        Vin[4+2].eta = db2;
        Vin[4+2].zeta = db3;

       //b-3 
        Vin[4+3].x = rot(-0.5*rb1, 0.0, -0.5*sqrt(3.0)*rb1, a, b, c, 0);
        Vin[4+3].y = rot(-0.5*rb1, 0.0, -0.5*sqrt(3.0)*rb1, a, b, c, 1);
        Vin[4+3].z = rot(-0.5*rb1, 0.0, -0.5*sqrt(3.0)*rb1, a, b, c, 2);
        Vin[4+3].q = -1;
        Vin[4+3].s = -2;
        Vin[4+3].d = db1_r+db1_i*I;
        Vin[4+3].eta = db2;
        Vin[4+3].zeta = db3;


        //set d value
        setDvalue(Vin, part);

	//calculate structure energy
        if((MC_spinO_1) && (spec->icue ==4)){
                Usum = metropolis(Vin, part,-2);//fix heavy
        }else{
                Usum = sumEnergies(Vin, part);
	}
	Usum = Usum*1E3;
	U_spinO_1 = Usum;

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


double devspinO_1(Species *spec){

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
        if (MC_spinO_1){
		fr1    = getDistance(spec->coord, 0, 1);
		fr2    = getDistance(spec->coord, 0, spec->numPart-1);
		fd1    = spec->coord[1].d;
		fd2    = spec->coord[spec->numPart-1].d;
		fd3    = spec->coord[1].eta;
		fd4    = spec->coord[spec->numPart-1].eta;
		fd5    = spec->coord[1].zeta;
		fd6    = spec->coord[spec->numPart-1].zeta;
        }

	double dipole=0.0;
	dipole=getPolar(spec->coord,spec->numPart);
        deviation = 100*dipole*exp(10*dipole);

	// main output
	if (print){
		printHeader(spec->fullname, deviation);
		OutFile = fopen(directory, "a");
                if (MC_spinO_1){
                         fprintf(OutFile,"| Lone A1  dist         |      A     |      -         |   -   |                |    %8.5f    |   N/A   |       -       |\n", fr1);
                         fprintf(OutFile,"| Lone B1  dist         |      A     |      -         |   -   |                |    %8.5f    |   N/A   |       -       |\n", fr2);
                         fprintf(OutFile,"| Lone A1 1/radius^2    |    1/A^2   |      -         |   -   |                |%7.3f+%7.3fI|   N/A   |       -       |\n", creal(fd1), cimag(fd1));
                         fprintf(OutFile,"| Lone B1 1/radius^2    |    1/A^2   |      -         |   -   |                |%7.3f+%7.3fI|   N/A   |       -       |\n", creal(fd2), cimag(fd2));
                         fprintf(OutFile,"| Lone A1  eta          |            |      -         |   -   |                |    %8.5f    |   N/A   |       -       |\n", fd3);
                         fprintf(OutFile,"| Lone B1  eta          |            |      -         |   -   |                |    %8.5f    |   N/A   |       -       |\n", fd4);
                         fprintf(OutFile,"| Lone A1  zeta         |            |      -         |   -   |                |    %8.5f    |   N/A   |       -       |\n", fd5);
                         fprintf(OutFile,"| Lone B1  zeta         |            |      -         |   -   |                |    %8.5f    |   N/A   |       -       |\n", fd6);
                         fprintf(OutFile,"| Polarity              |      -     |      -         |   -   |                |    %8.2f    |   N/A   |       -       |\n", dipole);
                }
                fprintf(OutFile, "|-------------------------------------------------------------------------------------------------------------------------|\n");
	    	fclose(OutFile);
		printEnergy(U_spinO_1);
	}

	//structure output
	sprintf(Out, "MC_spin%s.pdb", spec->fullname);
        if ((pdbSwitch) && (MC_spinO_1)){ output(spec->coord, spec->numPart, Out); }

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ABOVE CHANGABLE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	return deviation;

}
