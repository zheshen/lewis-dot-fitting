#!/bin/bash
#$ -S /bin/bash
#$ -pe orte 8 
#####################################################################
export OMP_NESTED=TRUE
export OMP_NUM_THREADS=4,4

###########################ARGUMENTS##################################
init=$1  #exponent set 
i=$2     #output number
key=$3   #0 for fixed, 1 for O, 2 for C+O, 3 for C+N+O
group=$4 #a particular run for simultaneous simulations
optim=$5
sh=$6
###########################PARAMETERS#################################

if [ -f $sh.$i ]; then
	bash $sh.$i $init $i $key $group $optim 
else
	bash $sh $init $i $key $group $optim
fi
