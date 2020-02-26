PROJECT = ferratendo
MAJVER = 0.2
MINVER = 0
LIBS = ${PROJECT}
PROGS = checagba checagbc checands infogba infogbc infon64 infonds

include make/conf

DATA =
DOCS =
ICONS =
INFOS =
INCLUDES = bios_gb.h bios_gba.h calculo.h cartucho_gba.h cartucho_gbc.h
INCLUDES += cartucho_n64.h cartucho_nds.h codigos.h codigos_gbc.h
INCLUDES += codigos_letras.h codigos_nds.h tempo.h transcrever.h

MANS =

XERECAOBJ = calculo.o
INFOOBJ = tempo.o transcrever.o
SRC =
LIBSRC := cartucho_gba.c cartucho_gbc.c cartucho_n64.c cartucho_nds.c
LIBSRC += ${XERECAOBJ:.o=.c} ${INFOOBJ:.o=.c}
PROGSRC = checagba.c checagbc.c checands.c infogba.c infogbc.c infon64.c
PROGSRC += infonds.c

GTKUI = 0
QTUI = 0

#ifeq (${CONSOLE}, 1)
#PROGOBJ = terminal.o
#endif

include make/exconf
include make/build

checagba checagba-static: checagba.o
checagbc checagbc-static: checagbc.o
checands checands-static: checands.o
checagba-static checagbc-static checands-static: ${XERECAOBJ}
infogba infogba-static: infogba.o
infogbc infogbc-static: infogbc.o
infon64 infon64-static: infon64.o
infonds infonds-static: infonds.o
infogba-static infogbc-static infon64-static infonds-static: ${INFOOBJ}
checagba-static infogba-static: cartucho_gba.o
checagbc-static infogbc-static: cartucho_gbc.o
checands-static infonds-static: cartucho_nds.o
infon64-static: cartucho_n64.o

include make/pack
include make/rules
include make/thedep
