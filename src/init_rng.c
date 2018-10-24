#include "Common.h"
#include <omp.h>

void init_rng(){

#pragma omp parallel
  {
  
  printf ("I am thread %d of %d \n",  omp_get_thread_num() , omp_get_num_threads() );
  //FRA 
  //Probably we gonna need something smarter than this , but for now it might work
  myseeds[omp_get_thread_num()] = time(NULL) + omp_get_thread_num()  ;
//  myseeds[omp_get_thread_num()] = omp_get_thread_num()  ;
  
  }


}

