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
spinN2_snglt_linnett.o spinN2_snglt_snglbnd.o spinN2_snglt_dblbnd.o spinN2_snglt_trplbnd.o spinN2_trplt_linnett.o spinN2_trplt_snglbnd.o spinN2_trplt_dblbnd.o spinN2_trplt_trplbnd.o \
spinC2_snglt_linnett.o spinC2_snglt_snglbnd.o spinC2_snglt_dblbnd.o spinC2_snglt_trplbnd.o spinC2_trplt_linnett.o spinC2_trplt_snglbnd.o spinC2_trplt_dblbnd.o spinC2_trplt_trplbnd.o \
spinB2_snglt_linnett.o spinB2_snglt_snglbnd.o spinB2_snglt_dblbnd.o spinB2_snglt_trplbnd.o spinB2_trplt_linnett.o spinB2_trplt_snglbnd.o spinB2_trplt_dblbnd.o spinB2_trplt_trplbnd.o \
spinF2_snglt_linnett.o spinF2_snglt_snglbnd.o spinF2_snglt_dblbnd.o spinF2_snglt_trplbnd.o spinF2_trplt_linnett.o spinF2_trplt_snglbnd.o spinF2_trplt_dblbnd.o spinF2_trplt_trplbnd.o \
spinAl2_snglt_linnett.o spinAl2_snglt_snglbnd.o spinAl2_snglt_dblbnd.o spinAl2_snglt_trplbnd.o spinAl2_trplt_linnett.o spinAl2_trplt_snglbnd.o spinAl2_trplt_dblbnd.o spinAl2_trplt_trplbnd.o \
spinSi2_snglt_linnett.o spinSi2_snglt_snglbnd.o spinSi2_snglt_dblbnd.o spinSi2_snglt_trplbnd.o spinSi2_trplt_linnett.o spinSi2_trplt_snglbnd.o spinSi2_trplt_dblbnd.o spinSi2_trplt_trplbnd.o \
spinP2_snglt_linnett.o spinP2_snglt_snglbnd.o spinP2_snglt_dblbnd.o spinP2_snglt_trplbnd.o spinP2_trplt_linnett.o spinP2_trplt_snglbnd.o spinP2_trplt_dblbnd.o spinP2_trplt_trplbnd.o \
spinS2_snglt_linnett.o spinS2_snglt_snglbnd.o spinS2_snglt_dblbnd.o spinS2_snglt_trplbnd.o spinS2_trplt_linnett.o spinS2_trplt_snglbnd.o spinS2_trplt_dblbnd.o spinS2_trplt_trplbnd.o \
spinCl2_snglt_linnett.o spinCl2_snglt_snglbnd.o spinCl2_snglt_dblbnd.o spinCl2_snglt_trplbnd.o spinCl2_trplt_linnett.o spinCl2_trplt_snglbnd.o spinCl2_trplt_dblbnd.o spinCl2_trplt_trplbnd.o \
spinH.o spinH_.o spinH2.o spinH2plus.o spinH2minus.o spinH2trp.o spinH3.o spinH3plus.o spinH3linear.o \
spinZnneutrl.o spinZnneutrlex.o spinZnplus1.o spinZnplus1ex.o spinZnplus2.o spinZnplus2ex.o spinZnplus3.o spinZnplus3ex.o spinZnplus4.o spinZnplus4ex.o spinZnplus4ex2.o \
spinZnplus5.o spinZnplus5ex.o spinZnplus5ex2.o spinZnplus6.o spinZnplus6ex.o spinZnplus6ex2.o spinZnplus7.o spinZnplus8.o spinZnplus9.o spinZnplus10.o spinZnplus10ex.o spinZnplus11.o \
spinZnneutrlex2.o spinZnplus1ex2.o spinZnplus2ex2.o spinZnplus3ex2.o spinZnplus4ex3.o spinZnplus5ex3.o spinZnplus6ex3.o spinZnplus7ex.o spinZnplus8ex.o spinZnplus9ex.o \
spinO_2.o spinO_1.o spinOneutrl.o spinOneutrlex.o spinOneutrlex2.o spinOplus1.o spinOplus1ex.o spinOplus1ex2.o spinOplus2.o spinOplus2ex.o spinOplus2ex2.o spinOplus3.o spinOplus3ex.o \
spinOplus4.o spinOplus4ex.o spinOplus5.o \
spinO2_linnett.o spinO2_snglbnd.o spinO2_dblbnd.o spinO2_trplbnd.o spinO2dia_linnett.o spinO2dia_snglbnd.o spinO2dia_dblbnd.o spinO2dia_trplbnd.o spinO2qnt_linnett.o spinO2qnt_snglbnd.o spinO2qnt_dblbnd.o spinO2qnt_trplbnd.o spinO2plus1.o spinO2_1.o \
spinO3_linnett.o spinO3trp_linnett.o \
spinB_1.o spinBneutrlex.o spinBneutrl.o spinBplus1ex.o spinBplus1.o spinBplus2.o \
spinC_1.o spinCneutrl.o spinCneutrlex.o spinCneutrlex2.o spinCplus1.o spinCplus1ex.o spinCplus2.o spinCplus2ex.o spinCplus3.o \
spinNneutrl.o spinNneutrlex.o spinNplus1.o spinNplus1ex.o spinNplus1ex2.o spinNplus2.o spinNplus2ex.o spinNplus3.o spinNplus3ex.o spinNplus4.o \
spinFeplus7.o spinFeplus6.o spinFeplus6ex.o spinFeplus5.o spinFeplus5ex.o spinFeplus4.o spinFeplus4ex.o spinFeplus4ex2.o spinFeplus3.o spinFeplus3ex.o spinFeplus3ex2.o spinFeplus2.o spinFeplus2ex.o spinFeplus2ex2.o spinFeplus1.o spinFeplus1ex.o spinFeplus1ex2.o spinFeneutrl.o spinFeneutrlex.o spinFeneutrlex2.o spinFeneutrlex3.o \
spinSplus5.o spinSplus4.o spinSplus3.o spinSplus2.o spinSplus1.o spinSneutrl.o spinS_1.o spinSplus4ex.o spinSplus3ex.o spinSplus2ex.o spinSplus2ex2.o spinSplus1ex.o spinSneutrlex.o spinSneutrlex2.o \
spinPplus4.o spinPplus3.o spinPplus2.o spinPplus1.o spinPneutrl.o spinP_1.o spinPplus3ex.o spinPplus2ex.o spinPplus1ex.o spinPplus1ex2.o spinPneutrlex.o \
spinSiplus3.o spinSiplus2.o spinSiplus1.o spinSineutrl.o spinSi_1.o spinSiplus2ex.o spinSiplus1ex.o spinSineutrlex.o spinSineutrlex2.o \
spinFplus6.o spinFplus5.o spinFplus4.o spinFplus3.o spinFplus2.o spinFplus1.o spinFneutrl.o spinF_1.o spinFplus5ex.o spinFplus4ex.o spinFplus3ex.o spinFplus3ex2.o spinFplus2ex.o spinFplus1ex.o spinFneutrlex.o spinFplus1ex2.o spinFplus2ex2.o \
spinCl_1.o spinClneutrl.o spinClneutrlex.o spinClplus1ex2.o spinClplus1ex.o spinClplus1.o spinClplus2ex.o spinClplus2.o spinClplus3ex2.o spinClplus3ex.o spinClplus3.o spinClplus4ex.o spinClplus4.o spinClplus5ex.o spinClplus5.o spinClplus6.o \
spinAl_1.o spinAlneutrlex.o spinAlneutrl.o spinAlplus1ex.o spinAlplus1.o spinAlplus2.o \
spinLi_1.o spinLineutrl.o \
spinBeneutrl.o spinBeneutrlex.o spinBeplus1.o \
spinNa_1.o spinNaneutrl.o \
spinMgneutrl.o spinMgneutrlex.o spinMgplus1.o \
spinScplus2.o spinScplus1.o spinScplus1ex.o spinScneutrl.o spinScneutrlex.o \
spinTiplus3.o spinTiplus2.o spinTiplus2ex.o spinTiplus1.o spinTiplus1ex.o spinTineutrl.o spinTineutrlex.o spinTineutrlex2.o \
spinVplus4.o spinVplus3.o spinVplus3ex.o spinVplus2.o spinVplus2ex.o spinVplus1.o spinVplus1ex.o spinVplus1ex2.o spinVneutrl.o spinVneutrlex.o spinVneutrlex2.o \
spinCrplus5.o spinCrplus4.o spinCrplus4ex.o spinCrplus3.o spinCrplus3ex.o spinCrplus2.o spinCrplus2ex.o spinCrplus2ex2.o spinCrplus1.o spinCrplus1ex.o spinCrplus1ex2.o spinCrneutrl.o spinCrneutrlex.o spinCrneutrlex2.o \
spinMnplus6.o spinMnplus5.o spinMnplus5ex.o spinMnplus4.o spinMnplus4ex.o spinMnplus3.o spinMnplus3ex.o spinMnplus2.o spinMnplus2ex.o spinMnplus2ex2.o spinMnplus1.o spinMnplus1ex.o spinMnplus1ex2.o spinMnneutrl.o spinMnneutrlex.o spinMnneutrlex2.o \
spinCoplus8.o spinCoplus7.o spinCoplus7ex.o spinCoplus6.o spinCoplus6ex.o spinCoplus5.o spinCoplus5ex.o spinCoplus5ex2.o spinCoplus4.o spinCoplus4ex.o spinCoplus4ex2.o spinCoplus3.o spinCoplus3ex.o spinCoplus3ex2.o spinCoplus2.o spinCoplus2ex.o spinCoplus2ex2.o spinCoplus1.o spinCoplus1ex.o spinCoplus1ex2.o spinConeutrl.o spinConeutrlex.o \
spinNiplus9.o spinNiplus8.o spinNiplus8ex.o spinNiplus7.o spinNiplus7ex.o spinNiplus6.o spinNiplus6ex.o spinNiplus5.o spinNiplus5ex.o spinNiplus5ex2.o spinNiplus4.o spinNiplus4ex.o spinNiplus4ex2.o spinNiplus3.o spinNiplus3ex.o spinNiplus3ex2.o spinNiplus2.o spinNiplus2ex.o spinNiplus2ex2.o spinNiplus1.o spinNiplus1ex.o spinNineutrl.o spinNineutrlex.o \
spinCuplus10.o spinCuplus9.o spinCuplus9ex.o spinCuplus8.o spinCuplus7.o spinCuplus6.o spinCuplus5.o spinCuplus5ex.o spinCuplus5ex2.o spinCuplus4.o spinCuplus4ex.o spinCuplus4ex2.o spinCuplus3.o spinCuplus3ex.o spinCuplus3ex2.o spinCuplus2.o spinCuplus2ex.o spinCuplus1.o spinCuplus1ex.o spinCuneutrl.o spinCuneutrlex.o \
spinYneutrl.o spinYneutrlex.o spinYplus1.o spinYplus1ex.o spinYplus2.o \
spinZrneutrl.o spinZrneutrlex.o spinZrneutrlex2.o spinZrplus1.o spinZrplus1ex.o spinZrplus2.o spinZrplus2ex.o spinZrplus3.o \
#spinNbplus4.o spinNbplus3.o spinNbplus3ex.o spinNbplus2.o spinNbplus2ex.o spinNbplus1.o spinNbplus1ex.o spinNbplus1ex2.o spinNbneutrl.o spinNbneutrlex.o spinNbneutrlex2.o \
#spinMoplus5.o spinMoplus4.o spinMoplus4ex.o spinMoplus3.o spinMoplus3ex.o spinMoplus2.o spinMoplus2ex.o spinMoplus2ex2.o spinMoplus1.o spinMoplus1ex.o spinMoplus1ex2.o spinMoneutrl.o spinMoneutrlex.o spinMoneutrlex2.o spinMoneutrlex3.o \
#spinTcplus6.o spinTcplus5.o spinTcplus4.o spinTcplus3.o spinTcplus2.o spinTcplus1.o spinTcplus1ex.o spinTcneutrl.o spinTcneutrlex.o spinTcneutrlex2.o spinTcneutrlex3.o \ 
#spinRuplus7.o spinRuplus6.o spinRuplus5.o spinRuplus4.o spinRuplus3.o spinRuplus2.o spinRuplus2ex.o spinRuplus1.o spinRuplus1ex.o spinRuplus1ex2.o spinRuneutrl.o spinRuneutrlex.o spinRuneutrlex2.o \
#spinRhplus8.o spinRhplus7.o spinRhplus6.o spinRhplus5.o spinRhplus4.o spinRhplus3.o spinRhplus2.o spinRhplus2ex.o spinRhplus2ex2.o spinRhplus1.o spinRhplus1ex.o spinRhplus1ex2.o spinRhneutrl.o spinRhneutrlex.o\
#spinPdplus9.o spinPdplus8.o spinPdplus7.o spinPdplus6.o spinPdplus5.o spinPdplus4.o spinPdplus3.o spinPdplus2.o spinPdplus2ex.o spinPdplus2ex2.o spinPdplus1.o spinPdplus1ex.o spinPdneutrl.o spinPdneutrlex.o \
#spinAgplus10.o spinAgplus9.o spinAgplus8.o spinAgplus7.o spinAgplus6.o spinAgplus5.o spinAgplus4.o spinAgplus3.o spinAgplus2.o spinAgplus2ex.o spinAgplus1.o spinAgplus1ex.o spinAgneutrl.o spinAgneutrlex.o \ll
#spinCdplus11.o spinCdplus10.o spinCdplus9.o spinCdplus8.o spinCdplus7.o spinCdplus6.o spinCdplus5.o spinCdplus4.o spinCdplus3.o spinCdplus3ex.o spinCdplus2.o spinCdplus2ex.o ##spinCdplus2ex2.o spinCdplus1.o spinCdplus1ex.o spinCdneutrl.o spinCdneutrlex.o \


#spinH.o spinH_.o spinH2.o spinH2trp.o spinH2minus.o spinH2plus.o spinH3.o spinH3linear.o spinH3plus.o \



LOWERMAINS = lowermain.o lowermainspinO2.o lowermainspinO2dia.o lowermainspinO2qnt.o lowermainspinN2_snglt.o lowermainspinN2_trplt.o lowermainspinC2_snglt.o lowermainspinC2_trplt.o lowermainspinB2_snglt.o lowermainspinB2_trplt.o lowermainspinF2_snglt.o lowermainspinF2_trplt.o lowermainspinAl2_snglt.o lowermainspinAl2_trplt.o lowermainspinSi2_snglt.o lowermainspinSi2_trplt.o lowermainspinP2_snglt.o lowermainspinP2_trplt.o lowermainspinS2_snglt.o lowermainspinS2_trplt.o lowermainspinCl2_snglt.o lowermainspinCl2_trplt.o

UPNUPS = upnupspin.o

MC = mc_metropolis.o mc_met.o mc_sumEnergies.o mc_utilities.o 


UTILITIES = main.o status.o energy_reader.o energy_interactions.o energy_library.o sumEnergies.o output.o \
printer.o spinthermo.o setWspinthermo.o LEcuyer.o de.o evaluate.o \
StructureFunctions.o restartOutput.o finalOutput.o specSwitch.o test.o Faddeeva.o 

_DEPS = Common.h U.h Structure.h main.h de.h Energy.h Lowermain.h Metropolis.h Print.h Species.h U.h Utilities.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJECTS = $(SPINS) $(LOWERMAINS) $(UPNUPS) $(MC) $(UTILITIES) 
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJECTS)) 

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ballet: $(OBJECTS)
	$(CC) -w -o $@ $^ $(CFLAGS) $(LIBS)

ballet_ionization: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

ballet_ionization_Fe: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

ballet_ionization_C: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

ballet_ionization_N: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

ballet_no_se: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

oxygenrun_no_se: $(OBJECTS)
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

hydrogenrun: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

nitrogenrun: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -rf ballet* oxygenrun* zincrun*  $(OBJECTS)  *.pdb *.d log.txt *~  fit.* core.* DiffEvolution.out DE*.txt DE*.txt.energies sub.sh.*

pure:
	rm -rf $(OBJECTS) *.pdb *.d log.txt *~  fit.* core.* DiffEvolution.out

tidy:
	rm *.pdb *.d




