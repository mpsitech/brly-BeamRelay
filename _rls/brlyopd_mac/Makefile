# file Makefile
# make file for Brly operation daemon, release brlyopd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Jan 2021
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbsbrly -I$(BUILDROOT)/brlyopd/VecBrly -I$(BUILDROOT)/brlyopd/IexBrly -I$(BUILDROOT)/brlyopd
INCPATH += -I$(BUILDROOT)/brlyopd/BrlyTtimp -I$(BUILDROOT)/brlyopd/BrlyMapgen -I$(BUILDROOT)/brlyopd/BrlyDyn -I$(BUILDROOT)/brlyopd/BrlyDnsmap -I$(BUILDROOT)/brlyopd/BrlyBase
INCPATH += -I${WHIZSDKROOT}/build -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include -I/usr/local/opt/libpng/include

PCHS = Brlyopd.h.gch

OBJS = Brly.o BrlyopdEngsrv.o BrlyopdOpprc.o Brlyopd.o
OBJS += Brlyopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlyopd
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/local/lib -L/usr/local/mysql/lib -L/usr/local/opt/libpng/lib

LIBS = -lbrlyttimp -lbrlymapgen -lbrlydyn -lbrlydnsmap -lbrlybase
LIBS += -liexbrly -lvecbrly -ldbsbrly
LIBS += -lcurl -lmicrohttpd -lpng -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus
LIBS += -lsbecore
LIBS += -lxml2

EXE = Brlyopd

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJS)
	$(LINK) $(LINKFLAGS) $(OBJS) $(LIBPATH) $(LIBS) -o $(EXE)
	rm -f *.o

pch:	$(PCHS)

install:
	mv $(EXE) $(BINROOT)/brlyopd/

clean:
	rm -f *.gch
	rm -f *.o
