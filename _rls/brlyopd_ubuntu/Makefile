# file Makefile
# make file for Brly operation daemon, release brlyopd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbsbrly -I$(BUILDROOT)/brlyopd/VecBrly -I$(BUILDROOT)/brlyopd/IexBrly -I$(BUILDROOT)/brlyopd
INCPATH += -I$(BUILDROOT)/brlyopd/BrlyTtimp -I$(BUILDROOT)/brlyopd/BrlyMapgen -I$(BUILDROOT)/brlyopd/BrlyDyn -I$(BUILDROOT)/brlyopd/BrlyDnsmap -I$(BUILDROOT)/brlyopd/BrlyBase
INCPATH += -I${WHIZSDKROOT}/build -I/usr/include -I/usr/include/jsoncpp -I/usr/include/libxml2 -I/usr/include/mariadb

PCHS = Brlyopd.h.gch

OBJS = Brly.o BrlyopdEngsrv.o BrlyopdOpprc.o Brlyopd.o
OBJS += Brlyopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlyopd
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/lib/x86_64-linux-gnu
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lbrlyttimp -lbrlymapgen -lbrlydyn -lbrlydnsmap -lbrlybase
LIBS += -liexbrly -lvecbrly -ldbsbrly
LIBS += -lcurl -lmicrohttpd -lnetcdf -lpng -lsbecore_mar
LIBS += -lhdf5_hl -lmariadbclient -lsbecore_plus
LIBS += -lhdf5 -lsbecore
LIBS += -ljsoncpp -lxml2 -lz
LIBS += -lpthread

EXE = Brlyopd

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJS)
	$(LINK) $(LINKFLAGS) $(OBJS) $(LIBPATH) $(LIBS) -o $(EXE)

pch:	$(PCHS)

install:
	mv $(EXE) $(BINROOT)/brlyopd/

clean:
	rm -f *.gch
	rm -f *.o
