IDIR=../include
LDIR=../lib
ODIR=obj
LIBS=-lm
CFLAGS_OMP=-fopenmp -DOMP -O3 -g -Wall -std=c99
CFLAGS_SERIAL= -Wall -O3 -g
CFLAGS=$(CFLAGS_OMP) -I$(IDIR) -L.
cluster=/home/zheshen
mac=/Users/zheshen

ifeq ($(HOME) , $(mac))
CC = gcc-5
else
CC = gcc
endif


SPINS = spinDielectron.o spinDielectronex.o \
spinZnneutrl.o spinZnneutrlex.o spinZnplus1.o spinZnplus1ex.o spinZnplus2.o spinZnplus2ex.o spinZnplus3.o spinZnplus3ex.o spinZnplus4.o spinZnplus4ex.o spinZnplus4ex2.o \
spinZnplus5.o spinZnplus5ex.o spinZnplus5ex2.o spinZnplus6.o spinZnplus6ex.o spinZnplus6ex2.o spinZnplus7.o spinZnplus8.o spinZnplus9.o spinZnplus10.o spinZnplus10ex.o spinZnplus11.o \
spinZnneutrlex2.o spinZnplus1ex2.o spinZnplus2ex2.o spinZnplus3ex2.o spinZnplus4ex3.o spinZnplus5ex3.o spinZnplus6ex3.o spinZnplus7ex.o spinZnplus8ex.o spinZnplus9ex.o \
spinO_2.o spinO_1.o spinOneutrl.o spinOneutrlex.o spinOneutrlex2.o spinOplus1.o spinOplus1ex.o spinOplus1ex2.o spinOplus2.o spinOplus2ex.o spinOplus2ex2.o spinOplus3.o spinOplus3ex.o \
spinOplus4.o spinOplus4ex.o spinOplus5.o \
spinO2_linnett.o spinO2_snglbnd.o spinO2_dblbnd.o spinO2_trplbnd.o spinO2dia_linnett.o spinO2dia_snglbnd.o spinO2dia_dblbnd.o spinO2dia_trplbnd.o spinO2qnt_linnett.o spinO2qnt_snglbnd.o spinO2qnt_dblbnd.o spinO2qnt_trplbnd.o \
spinO3_linnett.o spinO3trp_linnett.o
#spinH.o spinH_.o spinH2.o spinH2trp.o spinH2minus.o spinH2plus.o spinH3.o spinH3linear.o spinH3plus.o \

LOWERMAINS = lowermain.o lowermainspinO2.o lowermainspinO2dia.o lowermainspinO2qnt.o

UPNUPS = upnupspin.o

MC = mc_metropolis.o mc_met.o mc_sumEnergies.o mc_utilities.o 


UTILITIES = main.o status.o energy_reader.o energy_interactions.o energy_library.o sumEnergies.o output.o \
printer.o spinthermo.o setWspinthermo.o LEcuyer.o de.o evaluate.o \
StructureFunctions.o restartOutput.o finalOutput.o specSwitch.o test.o Faddeeva.o 

_DEPS = Common.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJECTS = $(SPINS) $(LOWERMAINS) $(UPNUPS) $(MC) $(UTILITIES) 
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJECTS)) 

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ballet: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

ballet_no_se: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

oxygenrun: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

oxygenrun_no_O3: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

oxygenrun_no_di: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

oxygenrun_no_qnt: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

oxygenrun_no_ex_se: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

oxygenrun_no_loc_min: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

zincrun: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -rf ballet* oxygenrun* zincrun*  $(OBJECTS)  *.pdb *.d log.txt *~  fit.* core.* DiffEvolution.out DE*.txt DE*.txt.energies sub.sh.*

pure:
	rm -rf $(OBJECTS) *.pdb *.d log.txt *~  fit.* core.* DiffEvolution.out

tidy:
	rm *.pdb *.d




