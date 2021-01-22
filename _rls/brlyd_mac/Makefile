# file Makefile
# make file for Brly daemon, release brlyd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Jan 2021
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DBRLYD

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbsbrly -I$(BUILDROOT)/brlyd/VecBrly -I$(BUILDROOT)/brlyd/IexBrly -I$(BUILDROOT)/brlyd
INCPATH += -I$(BUILDROOT)/brlyd/CrdBrlyUsg -I$(BUILDROOT)/brlyd/CrdBrlyUsr -I$(BUILDROOT)/brlyd/CrdBrlyPrs -I$(BUILDROOT)/brlyd/CrdBrlyFil -I$(BUILDROOT)/brlyd/CrdBrlyOpr -I$(BUILDROOT)/brlyd/CrdBrlyPty -I$(BUILDROOT)/brlyd/CrdBrlyNav -I$(BUILDROOT)/brlyd/CrdBrlyReg -I$(BUILDROOT)/brlyd/CrdBrlyLoc -I$(BUILDROOT)/brlyd/CrdBrlyLeg -I$(BUILDROOT)/brlyd/CrdBrlyTtb -I$(BUILDROOT)/brlyd/CrdBrlyFlt -I$(BUILDROOT)/brlyd/CrdBrlySeg -I$(BUILDROOT)/brlyd/CrdBrlyCon -I$(BUILDROOT)/brlyd/CrdBrlyRly
INCPATH += -I${WHIZSDKROOT}/build -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include -I/usr/local/opt/libpng/include -I/usr/local/opt/sqlite/include

PCHS = Brlyd.h.gch

OBJS = Brly.o BrlydAppsrv.o BrlydJobprc.o BrlydOpprc.o BrlydOpengcli.o BrlydOpengsrv.o Brlyd.o
OBJS += RootBrly.o SessBrly.o
OBJS += BrlyTtimp_blks.o SqkBrlyTtimp.o BrlyMapgen_blks.o SqkBrlyMapgen.o BrlyDyn_blks.o SqkBrlyDyn.o BrlyDnsmap_blks.o SqkBrlyDnsmap.o BrlyBase_blks.o SqkBrlyBase.o
OBJS += Brlyd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlyd
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/local/lib -L/usr/local/mysql/lib -L/usr/local/opt/libpng/lib -L/usr/local/opt/sqlite/lib

LIBS = -lcrdbrlyusg -lcrdbrlyusr -lcrdbrlyprs -lcrdbrlyfil -lcrdbrlyopr -lcrdbrlypty -lcrdbrlynav -lcrdbrlyreg -lcrdbrlyloc -lcrdbrlyleg -lcrdbrlyttb -lcrdbrlyflt -lcrdbrlyseg -lcrdbrlycon -lcrdbrlyrly
LIBS += -liexbrly -lvecbrly -ldbsbrly
LIBS += -lcurl -lmicrohttpd -lpng -lsbecore_dbsmon -lsbecore_mon
LIBS += -ldbswzem
LIBS += -lsbecore_lite -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus -lsqlite3
LIBS += -lsbecore
LIBS += -lxml2

EXE = Brlyd

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
	mv $(EXE) $(BINROOT)/brlyd/

clean:
	rm -f *.gch
	rm -f *.o
