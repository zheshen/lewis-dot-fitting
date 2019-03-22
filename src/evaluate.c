
 /**************************************************************
 * Purpose:		   			  	       *
 * This programe evaluates the total deviation for a particular*
 * set of parameters. First, all the paramters should be       *
 * assigned to the coresponding varaibles, then status() will  *
 * be involked to calculate the total deviation.               * 
 **************************************************************/
 
# include "Common.h"
double status();
//void updateDarray();
void assignpar();

double evaluate(int D, double tmp[], long *nfeval)
{
	double dev;
	extern double dlewis[];
	extern int key_potentials[];
	int i,j;

	(*nfeval)++;
	//	printf("nfeval is %d\n",*nfeval);


	/* Assigning the parameters that changed back into the overall dlewis[] array*/
	/* Assigning the parameters that changed back into the overall dlewis[] array*/

//	printf("in evaluate before updating d with tmp\n");
//	for (i=0; i<n_potentials; i++){
//		printf("dlewis[%d] is %f\n",i,dlewis[i]);
//	}


	j=0;
	for (i=0; i<n_potentials; i++){
		if (key_potentials[i]>0) {
		//	printf("key_potential at %d is %d\n",i,key_potentials[i]);
			dlewis[i]=tmp[j];
		//	printf("dlewis[%d] is %f\n",i,dlewis[i]);

			j++;
		}
	}
	/**********/

//        printf("in evaluate after updating d with tmp\n");
//        for (i=0; i<n_potentials; i++){
//                printf("dlewis[%d] is %f\n",i,dlewis[i]);
//        }
	assignpar();


	dev=status();
	//printf("dev is %f\n",dev);
	return dev;
}
