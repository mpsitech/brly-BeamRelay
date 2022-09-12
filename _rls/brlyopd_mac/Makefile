# file Makefile
# make file for Brly operation daemon, release brlyopd_mac
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
INCPATH += -I${WHIZSDKROOT}/build -I/opt/homebrew/include -I/opt/homebrew/opt/curl/include -I/opt/homebrew/opt/libmicrohttpd/include -I/opt/homebrew/opt/libpng/include -I/opt/homebrew/opt/libxml2/include -I/usr/local/mysql/include

PCHS = Brlyopd.h.gch

OBJS = Brly.o BrlyopdEngsrv.o BrlyopdOpprc.o Brlyopd.o
OBJS += Brlyopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/brlyopd
LIBPATH += -L${WHIZSDKROOT}/lib -L/opt/homebrew/lib -L/opt/homebrew/opt/curl/lib -L/opt/homebrew/opt/libmicrohttpd/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/libxml2/include -L/usr/local/mysql/lib

LIBS = -lbrlyttimp -lbrlymapgen -lbrlydyn -lbrlydnsmap -lbrlybase
LIBS += -liexbrly -lvecbrly -ldbsbrly
LIBS += -lcurl -lmicrohttpd -lpng -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus
LIBS += -lsbecore
LIBS += -ljsoncpp -lxml2

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
