
        //Particle Positions

        //H1 (center)
        Vin[0].x = 0.0;
        Vin[0].y = 0.0;
        Vin[0].z = 0.0;
        Vin[0].q = 1;
        Vin[0].s = 1;

        //H2 (+z)
        Vin[1].x = 0.0;
        Vin[1].y = 0.0;
        Vin[1].z = r_kernel;
        Vin[1].q = 1;
        Vin[1].s = 1;

        //H3  (-z)
        Vin[2].x = 0.0;
        Vin[2].y = 0.0; 
        Vin[2].z =-r_kernel;
        Vin[2].q = 1;
        Vin[2].s = 1;

        //A   (+z)
        Vin[3].x = 0.0;
        Vin[3].y = 0.0;
        Vin[3].z = ra1;
        Vin[3].q = -1;
        Vin[3].s = 2;
	Vin[3].d = da1_r;
	Vin[3].eta = da2;
	Vin[3].zeta = da3;

        //A
        Vin[4].x = 0.0;
        Vin[4].y = 0.0;
        Vin[4].z =-ra1;
        Vin[4].q = -1;
        Vin[4].s =  2;
	Vin[4].d = da1_r;
	Vin[4].eta = da2;
	Vin[4].zeta = da3;

        //B
        Vin[5].x = 0.0;
        Vin[5].y = 0.0;
        Vin[5].z = 0.0;
        Vin[5].q = -1;
        Vin[5].s = -2;
        Vin[5].d = db1_r;
	Vin[5].eta = db2;
	Vin[5].zeta = db3;
