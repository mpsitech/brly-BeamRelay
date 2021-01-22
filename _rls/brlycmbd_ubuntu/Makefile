# file Makefile
# make file for Brly combined daemon, release brlycmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Jan 2021
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DBRLYCMBD

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbsbrly -I$(BUILDROOT)/brlycmbd/VecBrly -I$(BUILDROOT)/brlycmbd/IexBrly -I$(BUILDROOT)/brlycmbd
INCPATH += -I$(BUILDROOT)/brlycmbd/CrdBrlyUsg -I$(BUILDROOT)/brlycmbd/CrdBrlyUsr -I$(BUILDROOT)/brlycmbd/CrdBrlyPrs -I$(BUILDROOT)/brlycmbd/CrdBrlyFil -I$(BUILDROOT)/brlycmbd/CrdBrlyOpr -I$(BUILDROOT)/brlycmbd/CrdBrlyPty -I$(BUILDROOT)/brlycmbd/CrdBrlyNav -I$(BUILDROOT)/brlycmbd/CrdBrlyReg -I$(BUILDROOT)/brlycmbd/CrdBrlyLoc -I$(BUILDROOT)/brlycmbd/CrdBrlyLeg -I$(BUILDROOT)/brlycmbd/CrdBrlyTtb -I$(BUILDROOT)/brlycmbd/CrdBrlyFlt -I$(BUILDROOT)/brlycmbd/CrdBrlySeg -I$(BUILDROOT)/brlycmbd/CrdBrlyCon -I$(BUILDROOT)/brlycmbd/CrdBrlyRly
INCPATH += -I$(BUILDROOT)/brlycmbd/BrlyTtimp -I$(BUILDROOT)/brlycmbd/BrlyMapgen -I$(BUILDROOT)/brlycmbd/BrlyDyn -I$(BUILDROOT)/brlycmbd/BrlyDnsmap -I$(BUILDROOT)/brlycmbd/BrlyBase
INCPATH += -I${WHIZSDKROOT}/build -I/usr/include -I/usr/include/libxml2 -I/usr/include/mariadb

PCHS = Brlycmbd.h.gch

OBJS = Brly.o BrlycmbdAppsrv.o BrlycmbdJobprc.o BrlycmbdOpprc.o Brlycmbd.o
OBJS += RootBrly.o SessBrly.o
OBJS += Brlycmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlycmbd
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/lib/x86_64-linux-gnu
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lcrdbrlyusg -lcrdbrlyusr -lcrdbrlyprs -lcrdbrlyfil -lcrdbrlyopr -lcrdbrlypty -lcrdbrlynav -lcrdbrlyreg -lcrdbrlyloc -lcrdbrlyleg -lcrdbrlyttb -lcrdbrlyflt -lcrdbrlyseg -lcrdbrlycon -lcrdbrlyrly
LIBS += -lbrlyttimp -lbrlymapgen -lbrlydyn -lbrlydnsmap -lbrlybase
LIBS += -liexbrly -lvecbrly -ldbsbrly
LIBS += -lmicrohttpd -lnetcdf -lpng -lsbecore_dbsmon -lsbecore_mon
LIBS += -ldbswzem -lhdf5_hl
LIBS += -lhdf5 -lsbecore_lite -lsbecore_mar
LIBS += -lmariadbclient -lsbecore_plus -lsqlite3 -lz
LIBS += -lsbecore
LIBS += -lxml2
LIBS += -lpthread

EXE = Brlycmbd

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
	mv $(EXE) $(BINROOT)/brlycmbd/

clean:
	rm -f *.gch
	rm -f *.o
