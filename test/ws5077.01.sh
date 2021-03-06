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
###########################PARAMETERS#################################
Nsh='01' #269  bash script version, the number following potential version
###########################PARAMETERS#################################
#       TauAB           KapAB1   KapAB2   KapAB3            TauK1    TauK2                                        sigma
AB_0='0.469460 0.000000 0.841450 0.000000 1.815180 0.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 '
#	ChiexK	TauexK1	TauexK2	 ChiexR	  TauexR            ChiexA   TauexC0   TauexC1  TauexC2  TauexC3
AB_1='0.076992 1.550513 0.811044 0.204323 1.096857 0.000000 1.030641 8.159463 0.000095 0.000013 0.054442 0.000000 0.000000 '
#	TauAX	RhoAX				   ChiexX    TauexXc2 ChiexXc  TauexXc1 TauexX  TauexX2	  TauexX3  TauexX0
AH_0='0.577522 0.000000 0.000000 1.340945 1.210662 66.988457 0.000000 0.000000 0.000000 0.854573 0.000000 0.000000 1.000000 '

LiA_0='1.000000 1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 '

BeA_0='1.000000 1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 '

BoA_0='1.000000 1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 '

CA_0='1.000000 1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 '

NA_0='0.595780 0.296160 0.000000 0.359410 1.064130 0.000000 18.349100 0.000000 0.000000 0.951130 0.000000 0.000000 1.000000 '

OA_0='0.467208 0.852814 0.000000 0.982896 1.156891 0.000000 3.067956 0.000000 0.079923 0.000000 0.000000 0.000000 0.000000 '

FA_0='0.648180 0.189240 0.100000 0.099270 1.048380 0.000000 25.989500 0.000000 0.000000 1.489970 0.000000 0.000000 1.000000 '

NaA_0='1.000000 1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 '

MgA_0='1.000000 1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 '

AlA_0='1.000000 1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 '

SiA_0='1.000000 1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 '

PA_0='1.000000 1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 '

SA_0='1.000000 1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 '

ClA_0='0.461500 0.826810 0.000000 0.986800 1.053360 0.000000 20.027400 0.000000 0.000000 1.208410 0.000000 0.000000 1.000000 '

FeA_0='1.240410 0.000000 0.000000 0.849990 1.032050 17.640900 0.554500 0.000000 0.921950 1.357020 48.989600 0.000000 1.000000 '

MA_0='1.372833 0.574065 0.008684 1.715849 1.354467 0.010717 0.044709 0.000000 3.891288 0.015289 0.000000 0.000035 13.776544 '

CH_0='1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 '

NH_0='1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 '

OH_0='1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 '

CC_0='1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 '

NN_0='1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 '

OO_0='1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 '

CN_0='1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 '

CO_0='1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 '

NO_0='1.000000 1.000000 1.000000 0.000000 0.000000 0.000000 '

HH_0='1.000010 1.000020 1.000030 0.000000 0.000000 0.000000 '



############################EXPONENTS#################################

EXP_1='0 0 0 1 1 1 1 1 1 1 3 6 1 1 1 1 1'
#EXP_2='6 1 1 6 1 1 4 6 1 1 4 6 1 1 3 6 1'

#############################KEYS####################################

KEY_AB0_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_AB0_1='0 0 0 0 0 0 1 0 0 0 0 0 0'

KEY_AB1_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_AB1_1='1 1 1 1 1 0 1 1 1 1 1 0 0'

KEY_AH_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_AH_1='1 0 0 1 1 1 0 0 0 1 0 0 0'

KEY_LiA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_LiA_1='1 1 1 1 1 1 1 1 0 0 0 0 0'

KEY_BeA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_BeA_1='1 1 1 1 1 1 1 1 0 0 0 0 0'

KEY_BoA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_BoA_1='1 1 1 1 1 1 1 1 0 0 0 0 0'

KEY_CA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_CA_1='1 1 1 1 1 1 1 1 0 0 0 0 0'

KEY_NA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_NA_1='1 1 0 1 1 0 1 0 0 1 0 0 0'

KEY_OA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_OA_1='1 1 0 1 1 0 1 0 1 0 0 0 0'

KEY_FA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_FA_1='1 1 0 1 1 0 1 0 0 1 0 0 0'

KEY_NaA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_NaA_1='1 1 1 1 1 1 1 1 0 0 0 0 0'

KEY_MgA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_MgA_1='1 1 1 1 1 1 1 1 0 0 0 0 0'

KEY_AlA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_AlA_1='1 1 1 1 1 1 1 1 0 0 0 0 0'

KEY_SiA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_SiA_1='1 1 1 1 1 1 1 1 0 0 0 0 0'

KEY_PA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_PA_1='1 1 1 1 1 1 1 1 0 0 0 0 0'

KEY_SA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_SA_1='1 1 1 1 1 1 1 1 0 0 0 0 0'

KEY_ClA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_ClA_1='1 1 0 1 1 0 1 0 0 1 0 0 0'

KEY_FeA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_FeA_1='1 0 0 1 1 1 1 0 1 1 1 0 0'

KEY_MA_0='0 0 0 0 0 0 0 0 0 0 0 0 0'
KEY_MA_1='1 1 1 1 1 1 1 0 1 1 0 1 1'

KEY_CH_0='0 0 0 0 0 0'
KEY_CH_1='1 1 1 1 1 1'

KEY_NH_0='0 0 0 0 0 0'
KEY_NH_1='1 1 1 1 1 1'

KEY_OH_0='0 0 0 0 0 0'
KEY_OH_1='1 1 1 1 1 1'

KEY_CC_0='0 0 0 0 0 0'
KEY_CC_1='1 1 1 1 1 1'

KEY_NN_0='0 0 0 0 0 0'
KEY_NN_1='1 1 1 1 1 1'

KEY_OO_0='0 0 0 0 0 0'
KEY_OO_1='1 1 1 1 1 1'

KEY_CN_0='0 0 0 0 0 0'
KEY_CN_1='1 1 1 1 1 1'

KEY_CO_0='0 0 0 0 0 0'
KEY_CO_1='1 1 1 1 1 1'

KEY_NO_0='0 0 0 0 0 0'
KEY_NO_1='1 1 1 1 1 1'

KEY_HH_0='0 0 0 0 0 0'
KEY_HH_1='1 1 1 0 0 0'


##############################
#Setting all keys to zero as default
##############################
KEY_AB0=$KEY_AB0_0
KEY_AB1=$KEY_AB1_0
KEY_AH=$KEY_AH_0
KEY_CA=$KEY_CA_0
KEY_NA=$KEY_NA_0
KEY_OA=$KEY_OA_0
KEY_CH=$KEY_CH_0
KEY_NH=$KEY_NH_0
KEY_OH=$KEY_OH_0
KEY_CC=$KEY_CC_0
KEY_NN=$KEY_NN_0
KEY_OO=$KEY_OO_0
KEY_CN=$KEY_CN_0
KEY_CO=$KEY_CO_0
KEY_NO=$KEY_NO_0
KEY_SiA=$KEY_SiA_0
KEY_PA=$KEY_PA_0
KEY_SA=$KEY_SA_0
KEY_FA=$KEY_FA_0
KEY_BoA=$KEY_BoA_0
KEY_AlA=$KEY_AlA_0
KEY_ClA=$KEY_ClA_0
KEY_LiA=$KEY_LiA_0
KEY_BeA=$KEY_BeA_0
KEY_NaA=$KEY_NaA_0
KEY_MgA=$KEY_MgA_0
KEY_FeA=$KEY_FeA_0
KEY_MA=$KEY_MA_0
KEY_HH=$KEY_HH_0
###########################INITIALIZATION#############################

if   [ $init -eq 1 ]
then
        EXP=$EXP_1

elif [ $init -eq 2 ]
then
        EXP=$EXP_2
fi


if [ $key -eq 0 ]
then 
	KEY_HH=$KEY_HH_0

elif [ $key -eq 1 ]
then
#	KEY_AB=$KEY_AB_1
	KEY_AH=$KEY_AH_1

elif [ $key -eq 2 ]
then
	KEY_AB0=$KEY_AB0_1
	KEY_AB1=$KEY_AB1_1
	KEY_OA=$KEY_OA_1

elif [ $key -eq 3 ]
then
	KEY_AB=$KEY_AB_1
	KEY_AH=$KEY_AH_1
	KEY_OA=$KEY_OA_1

elif [ $key -eq 4 ]
then
#	KEY_AB=$KEY_AB_1
	KEY_NA=$KEY_NA_1
#	KEY_OA=$KEY_OA_1

elif [ $key -eq 5 ]
then
#	KEY_AB=$KEY_AB_1
	KEY_FA=$KEY_FA_1

elif [ $key -eq 6 ]
then
#	KEY_AB=$KEY_AB_1
	KEY_CLA=$KEY_CLA_1

elif [ $key -eq 7 ]
then
	KEY_AB=$KEY_AB_1
#	KEY_OA=$KEY_OA_1
#	KEY_FeA=$KEY_FeA_1

elif [ $key -eq 8 ]
then
#	KEY_AB0=$KEY_AB0_1
#	KEY_AB1=$KEY_AB1_1
#	KEY_OA=$KEY_OA_1
	KEY_MA=$KEY_MA_1


fi

KEYS="${KEY_AB0} ${KEY_AB1} ${KEY_AH} ${KEY_LiA} ${KEY_BeA} ${KEY_BoA} ${KEY_CA} ${KEY_NA} ${KEY_OA} ${KEY_FA} ${KEY_NaA} ${KEY_MgA} ${KEY_AlA} ${KEY_SiA} ${KEY_PA} ${KEY_SA} ${KEY_ClA} ${KEY_FeA} ${KEY_MA} ${KEY_CH} ${KEY_NH} ${KEY_OH} ${KEY_CC} ${KEY_NN} ${KEY_OO} ${KEY_CN} ${KEY_CO} ${KEY_NO} ${KEY_HH}"
echo $KEYS $EXP $i
###########################OPTIMIZATION###############################

AA=$AA_0
AB0=$AB_0
AB1=$AB_1
AH=$AH_0
CA=$CA_0
NA=$NA_0
OA=$OA_0
CH=$CH_0
NH=$NH_0
OH=$OH_0
CC=$CC_0
NN=$NN_0
OO=$OO_0
CN=$CN_0
CO=$CO_0
NO=$NO_0
SiA=$SiA_0
PA=$PA_0
SA=$SA_0
FA=$FA_0
BoA=$BoA_0
AlA=$AlA_0
ClA=$ClA_0
LiA=$LiA_0
BeA=$BeA_0
NaA=$NaA_0
MgA=$MgA_0
FeA=$FeA_0
MA=$MA_0
HH=$HH_0
./oxygenrun $AB0 $AB1 $AH $LiA $BeA $BoA $CA $NA $OA $FA $NaA $MgA $AlA $SiA $PA $SA $ClA $FeA $MA $CH $NH $OH $CC $NN $OO $CN $CO $NO $HH $KEYS $EXP $i $Nsh $key $optim


