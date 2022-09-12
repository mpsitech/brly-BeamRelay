# file Makefile
# make file for Brly daemon, release brlyd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DBRLYD

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbsbrly -I$(BUILDROOT)/brlyd/VecBrly -I$(BUILDROOT)/brlyd/IexBrly -I$(BUILDROOT)/brlyd
INCPATH += -I$(BUILDROOT)/brlyd/CrdBrlyUsg -I$(BUILDROOT)/brlyd/CrdBrlyUsr -I$(BUILDROOT)/brlyd/CrdBrlyPrs -I$(BUILDROOT)/brlyd/CrdBrlyFil -I$(BUILDROOT)/brlyd/CrdBrlyOpr -I$(BUILDROOT)/brlyd/CrdBrlyPty -I$(BUILDROOT)/brlyd/CrdBrlyNav -I$(BUILDROOT)/brlyd/CrdBrlyReg -I$(BUILDROOT)/brlyd/CrdBrlyLoc -I$(BUILDROOT)/brlyd/CrdBrlyLeg -I$(BUILDROOT)/brlyd/CrdBrlyTtb -I$(BUILDROOT)/brlyd/CrdBrlyFlt -I$(BUILDROOT)/brlyd/CrdBrlySeg -I$(BUILDROOT)/brlyd/CrdBrlyCon -I$(BUILDROOT)/brlyd/CrdBrlyRly
INCPATH += -I${WHIZSDKROOT}/build -I/opt/homebrew/include -I/opt/homebrew/opt/curl/include -I/opt/homebrew/opt/libmicrohttpd/include -I/opt/homebrew/opt/libpng/include -I/opt/homebrew/opt/libxml2/include -I/opt/homebrew/opt/sqlite3/include -I/usr/local/mysql/include

PCHS = Brlyd.h.gch

OBJS = Brly.o BrlydAppsrv.o BrlydJobprc.o BrlydOpprc.o BrlydOpengcli.o BrlydOpengsrv.o Brlyd.o
OBJS += RootBrly.o SessBrly.o
OBJS += BrlyTtimp_blks.o SqkBrlyTtimp.o BrlyDyn_blks.o SqkBrlyDyn.o BrlyMapgen_blks.o SqkBrlyMapgen.o BrlyBase_blks.o SqkBrlyBase.o BrlyDnsmap_blks.o SqkBrlyDnsmap.o
OBJS += Brlyd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlyd
LIBPATH += -L${WHIZSDKROOT}/lib -L/opt/homebrew/lib -L/opt/homebrew/opt/curl/lib -L/opt/homebrew/opt/libmicrohttpd/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/libxml2/include -L/opt/homebrew/opt/sqlite3/lib -L/usr/local/mysql/lib

LIBS = -lcrdbrlyusg -lcrdbrlyusr -lcrdbrlyprs -lcrdbrlyfil -lcrdbrlyopr -lcrdbrlypty -lcrdbrlynav -lcrdbrlyreg -lcrdbrlyloc -lcrdbrlyleg -lcrdbrlyttb -lcrdbrlyflt -lcrdbrlyseg -lcrdbrlycon -lcrdbrlyrly
LIBS += -liexbrly -lvecbrly -ldbsbrly
LIBS += -lcurl -lmicrohttpd -lpng -lsbecore_dbsmon -lsbecore_mon
LIBS += -ldbswzem
LIBS += -lsbecore_lite -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus -lsqlite3
LIBS += -lsbecore
LIBS += -ljsoncpp -lxml2

EXE = Brlyd

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
	mv $(EXE) $(BINROOT)/brlyd/

clean:
	rm -f *.gch
	rm -f *.o
