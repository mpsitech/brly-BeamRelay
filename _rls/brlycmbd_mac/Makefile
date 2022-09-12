# file Makefile
# make file for Brly combined daemon, release brlycmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DBRLYCMBD

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbsbrly -I$(BUILDROOT)/brlycmbd/VecBrly -I$(BUILDROOT)/brlycmbd/IexBrly -I$(BUILDROOT)/brlycmbd
INCPATH += -I$(BUILDROOT)/brlycmbd/CrdBrlyUsg -I$(BUILDROOT)/brlycmbd/CrdBrlyUsr -I$(BUILDROOT)/brlycmbd/CrdBrlyPrs -I$(BUILDROOT)/brlycmbd/CrdBrlyFil -I$(BUILDROOT)/brlycmbd/CrdBrlyOpr -I$(BUILDROOT)/brlycmbd/CrdBrlyPty -I$(BUILDROOT)/brlycmbd/CrdBrlyNav -I$(BUILDROOT)/brlycmbd/CrdBrlyReg -I$(BUILDROOT)/brlycmbd/CrdBrlyLoc -I$(BUILDROOT)/brlycmbd/CrdBrlyLeg -I$(BUILDROOT)/brlycmbd/CrdBrlyTtb -I$(BUILDROOT)/brlycmbd/CrdBrlyFlt -I$(BUILDROOT)/brlycmbd/CrdBrlySeg -I$(BUILDROOT)/brlycmbd/CrdBrlyCon -I$(BUILDROOT)/brlycmbd/CrdBrlyRly
INCPATH += -I$(BUILDROOT)/brlycmbd/BrlyTtimp -I$(BUILDROOT)/brlycmbd/BrlyDyn -I$(BUILDROOT)/brlycmbd/BrlyMapgen -I$(BUILDROOT)/brlycmbd/BrlyBase -I$(BUILDROOT)/brlycmbd/BrlyDnsmap
INCPATH += -I${WHIZSDKROOT}/build -I/opt/homebrew/include -I/opt/homebrew/opt/libmicrohttpd/include -I/opt/homebrew/opt/libpng/include -I/opt/homebrew/opt/libxml2/include -I/opt/homebrew/opt/sqlite3/include -I/usr/local/mysql/include

PCHS = Brlycmbd.h.gch

OBJS = Brly.o BrlycmbdAppsrv.o BrlycmbdJobprc.o BrlycmbdOpprc.o Brlycmbd.o
OBJS += RootBrly.o SessBrly.o
OBJS += Brlycmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlycmbd
LIBPATH += -L${WHIZSDKROOT}/lib -L/opt/homebrew/lib -L/opt/homebrew/opt/libmicrohttpd/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/libxml2/include -L/opt/homebrew/opt/sqlite3/lib -L/usr/local/mysql/lib

LIBS = -lcrdbrlyusg -lcrdbrlyusr -lcrdbrlyprs -lcrdbrlyfil -lcrdbrlyopr -lcrdbrlypty -lcrdbrlynav -lcrdbrlyreg -lcrdbrlyloc -lcrdbrlyleg -lcrdbrlyttb -lcrdbrlyflt -lcrdbrlyseg -lcrdbrlycon -lcrdbrlyrly
LIBS += -lbrlyttimp -lbrlydyn -lbrlymapgen -lbrlybase -lbrlydnsmap
LIBS += -liexbrly -lvecbrly -ldbsbrly
LIBS += -lmicrohttpd -lpng -lsbecore_dbsmon -lsbecore_mon
LIBS += -ldbswzem
LIBS += -lsbecore_lite -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus -lsqlite3
LIBS += -lsbecore
LIBS += -ljsoncpp -lxml2

EXE = Brlycmbd

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
	mv $(EXE) $(BINROOT)/brlycmbd/

clean:
	rm -f *.gch
	rm -f *.o
