
#include "Structure.h"

//extern double spec->sym[];
extern double resolutionLow;
//extern int key_spinH[];
//extern double *stepSize_spinH;

int upnupspin(Species *spec){

//	extern int spec->icue;
//        static double b, bg;
        double t, w, ss, xz, xtb, sum;
//    static double g[spec->degFree];
	double grd[spec->degFree];
    int n;
//	strcpy(spec->name, "H");
//	H.type = t_H;
//	H.complete = 0;
//	H.degFree = 1;
//	H.numPart = 2;
//	Initialize(&H);
    switch (spec->icue) {
	case 1:  goto L5;
	case 2:  goto L20;
	case 3:  goto L35;
	case 4:  goto L5;
    }

/*     ENTER HERE IF ICUE=1 */
L5:
    for (n = 0; n < spec->degFree; n++) { spec->g[n] = spec->sym[n]; }

    (*spec->ainter)(spec);
    ss = -sumEnergies(spec->coord, spec->numPart);
    spec->b = ss;
    spec->bg = spec->b;
    goto L35;

/*     ENTER HERE IF ICUE=2 */
/*     PATTERN MOVE  IN DIRECTION OF PAST IMPROVEMENT */
L20:
    for (n = 0; n < spec->degFree; n++) {
		xtb = spec->sym[n] * 2. - spec->g[n];
		spec->g[n] = spec->sym[n];
		spec->sym[n] = xtb;
    }
    (*spec->ainter)(spec);
    ss = -sumEnergies(spec->coord, spec->numPart);
    t = ss;
    if (t - spec->b <= 0.) { goto L27; } 
	else { goto L26; }

L26:
    spec->b = t;
    goto L35;

L27:
    for (n = 0; n < spec->degFree; n++) { spec->sym[n] = spec->g[n]; }

/*     ENTER HERE IF ICUE=3 */
L35:
    sum = 0.;

/*     EXPLORATION SEARCH LOOP */
    for (n = 0; n < spec->degFree; n++) {
		if (spec->key[n] == 0) { goto L55; }
		xz = spec->sym[n];
		//d__1 = xz - spec->g[n];
		spec->sym[n] = xz + copysign(spec->stepSize, (xz - spec->g[n]));
        	(*spec->ainter)(spec);
    		ss = -sumEnergies(spec->coord, spec->numPart);
		t = ss;
		//d__1 = spec->sym[n] - xz;
		grd[n] = (t - spec->b) * copysign(1.00, (spec->sym[n] - xz));
		if (t - spec->b <= 0.) { goto L40;} 
		else { goto L60; }
L40:
		//d__1 = xz - spec->g[n];
		spec->sym[n] = xz - copysign(spec->stepSize, (xz - spec->g[n]));
        	(*spec->ainter)(spec);
    		ss = -sumEnergies(spec->coord, spec->numPart);
		t = ss;
		//d__1 = spec->sym[n] - xz;
		grd[n] = (t - spec->b) * copysign(1.00, (spec->sym[n] - xz));
		if (t - spec->b <= 0.) { goto L50;} 
		else { goto L60; }

L50:
		spec->sym[n] = xz;
		goto L65;
L55:
		grd[n] = (float)0.;
		goto L65;
L60:
		spec->b = t;
L65:
		//sum += (d__1 = grd[n], abs(d__1)); abs is returning the integer value!!??
		sum += abs(grd[n]);
    }

/*     TRY IN DIRECTION OF PSEUDO GRADIENT */
    if (sum <= 0.) { goto L81; } 
	else { goto L71; }
L71:
    w = spec->stepSize / sum;
    for (n = 0; n < spec->degFree; n++) {
		xz = spec->sym[n];
		spec->sym[n] = xz + w * grd[n];
		grd[n] = xz;
    }
    (*spec->ainter)(spec);
    ss = -sumEnergies(spec->coord, spec->numPart);
    t = ss;

/*     IF NEW VALUE IS BETTER, USE IT */
    if (t - spec->b <= 0.) { goto L75; } 
	else { goto L74; }
L74:

    spec->b = t;
    goto L78;

L78:
    
    for (n = 0; n < spec->degFree; n++) { grd[n] = spec->sym[n]; }
    goto L81;

/*     OTHERWISE USE EXPLORATION SEARCH VALUE */
L75:
    
    for (n = 0; n < spec->degFree; n++) { spec->sym[n] = grd[n]; }
    goto L81;

L81:

/*     IF NEW BASEPOINT SHOWS IMPROVEMENT, ADOPT IT FOR FUTURE */

    if (spec->b - spec->bg <= 0.) { goto L200; }
	else { goto L190; }

L190:
    spec->bg = spec->b;
    spec->icue = 2;
    return 0;

/*     OTHERWISE RESTORE PREVIOUS BASEPOINT */
L200:
    
    for (n = 0; n < spec->degFree; n++) { spec->sym[n] = spec->g[n]; }

/*     IF RESOLUTION LIMIT EXCEEDED, QUIT */
/*      IF(SUM/DABS(BG)-RSLN) 300,300,400 */
    if (spec->stepSize - resolutionLow <= 0.) { goto L300; } 
	else { goto L400; }

/* 	if (dabs(B-BG).gt.RSLN) go to 400 */
L300:

    spec->icue = 4;
    return 0;

/*     OTHERWISE HALVE STEPSIZE AND START AGAIN */
L400:
    spec->stepSize /= 2.;
    spec->b = spec->bg;
    spec->icue = 3;
    return 0;
}

