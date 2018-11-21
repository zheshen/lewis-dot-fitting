#!/bin/bash
#$ -S /bin/bash
#$ -pe orte 4 
#####################################################################
#SBATCH --account=chemistry
#SBATCH --partition=guest-compute		# queue to be used
#SBATCH --time=24:00:00	 			# Running time (in hours-minutes-seconds)
#SBATCH --job-name=LewisDot  			# Job name
#SBATCH --mail-type=BEGIN,END,FAIL 		# send and email when the job begins, ends or fails
#SBATCH --mail-user=your_email_address	 	# Email address to send the job status
#SBATCH --output=output_%j.txt 			# Name of the output file
#SBATCH --tasks=1				# Number of computer nodes
#SBATCH --cpus-per-task=4		 	# Number of cores on each computer node

export OMP_NESTED=TRUE
export OMP_NUM_THREADS=4

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
