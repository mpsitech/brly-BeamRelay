#!/bin/bash
# file checkout.sh
# checkout script for Brly combined daemon, release brlycmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set LIBROOT=${WHIZSDKROOT}/lib
export set BINROOT=${WHIZROOT}/bin

mkdir $BUILDROOT/brlycmbd
mkdir $BUILDROOT/brlycmbd/IexBrly
mkdir $BUILDROOT/brlycmbd/VecBrly
mkdir $BUILDROOT/brlycmbd/CrdBrlyUsg
mkdir $BUILDROOT/brlycmbd/CrdBrlyUsr
mkdir $BUILDROOT/brlycmbd/CrdBrlyPrs
mkdir $BUILDROOT/brlycmbd/CrdBrlyFil
mkdir $BUILDROOT/brlycmbd/CrdBrlyOpr
mkdir $BUILDROOT/brlycmbd/CrdBrlyPty
mkdir $BUILDROOT/brlycmbd/CrdBrlyNav
mkdir $BUILDROOT/brlycmbd/CrdBrlyReg
mkdir $BUILDROOT/brlycmbd/CrdBrlyLoc
mkdir $BUILDROOT/brlycmbd/CrdBrlyLeg
mkdir $BUILDROOT/brlycmbd/CrdBrlyTtb
mkdir $BUILDROOT/brlycmbd/CrdBrlyFlt
mkdir $BUILDROOT/brlycmbd/CrdBrlySeg
mkdir $BUILDROOT/brlycmbd/CrdBrlyCon
mkdir $BUILDROOT/brlycmbd/CrdBrlyRly
mkdir $BUILDROOT/brlycmbd/BrlyTtimp
mkdir $BUILDROOT/brlycmbd/BrlyDyn
mkdir $BUILDROOT/brlycmbd/BrlyMapgen
mkdir $BUILDROOT/brlycmbd/BrlyBase
mkdir $BUILDROOT/brlycmbd/BrlyDnsmap

mkdir $LIBROOT/brlycmbd

mkdir $BINROOT/brlycmbd

cp make.sh $BUILDROOT/brlycmbd/
cp remake.sh $BUILDROOT/brlycmbd/

cp Makefile.inc $BUILDROOT/brlycmbd/
cp Makefile $BUILDROOT/brlycmbd/

cp ../../brlycmbd/Brlycmbd.h $BUILDROOT/brlycmbd/
cp ../../brlycmbd/Brlycmbd.cpp $BUILDROOT/brlycmbd/

cp ../../brlycmbd/BrlycmbdAppsrv.h $BUILDROOT/brlycmbd/
cp ../../brlycmbd/BrlycmbdAppsrv.cpp $BUILDROOT/brlycmbd/

cp ../../brlycmbd/BrlycmbdJobprc.h $BUILDROOT/brlycmbd/
cp ../../brlycmbd/BrlycmbdJobprc.cpp $BUILDROOT/brlycmbd/

cp ../../brlycmbd/BrlycmbdOpprc.h $BUILDROOT/brlycmbd/
cp ../../brlycmbd/BrlycmbdOpprc.cpp $BUILDROOT/brlycmbd/

cp ../../brlycmbd/Brlycmbd_exe.h $BUILDROOT/brlycmbd/
cp ../../brlycmbd/Brlycmbd_exe.cpp $BUILDROOT/brlycmbd/

cp ../../brlycmbd/Brly.h $BUILDROOT/brlycmbd/
cp ../../brlycmbd/Brly.cpp $BUILDROOT/brlycmbd/

cp ../../brlycmbd/Root*.h $BUILDROOT/brlycmbd/
cp ../../brlycmbd/Root*.cpp $BUILDROOT/brlycmbd/

cp ../../brlycmbd/Sess*.h $BUILDROOT/brlycmbd/
cp ../../brlycmbd/Sess*.cpp $BUILDROOT/brlycmbd/

cp ../../brlycmbd/gbl/*.h $BUILDROOT/brlycmbd/
cp ../../brlycmbd/gbl/*.cpp $BUILDROOT/brlycmbd/

cp Makefile_IexBrly $BUILDROOT/brlycmbd/IexBrly/Makefile

cp ../../brlycmbd/IexBrly/IexBrly*.h $BUILDROOT/brlycmbd/IexBrly/
cp ../../brlycmbd/IexBrly/IexBrly*.cpp $BUILDROOT/brlycmbd/IexBrly/

cp ../../brlycmbd/IexBrly/JobBrlyIex*.h $BUILDROOT/brlycmbd/IexBrly/
cp ../../brlycmbd/IexBrly/JobBrlyIex*.cpp $BUILDROOT/brlycmbd/IexBrly/

cp Makefile_VecBrly $BUILDROOT/brlycmbd/VecBrly/Makefile

cp ../../brlycmbd/VecBrly/Vec*.h $BUILDROOT/brlycmbd/VecBrly/
cp ../../brlycmbd/VecBrly/Vec*.cpp $BUILDROOT/brlycmbd/VecBrly/

cp Makefile_CrdBrlyUsg $BUILDROOT/brlycmbd/CrdBrlyUsg/Makefile

cp ../../brlycmbd/CrdBrlyUsg/*.h $BUILDROOT/brlycmbd/CrdBrlyUsg/
cp ../../brlycmbd/CrdBrlyUsg/*.cpp $BUILDROOT/brlycmbd/CrdBrlyUsg/

cp Makefile_CrdBrlyUsr $BUILDROOT/brlycmbd/CrdBrlyUsr/Makefile

cp ../../brlycmbd/CrdBrlyUsr/*.h $BUILDROOT/brlycmbd/CrdBrlyUsr/
cp ../../brlycmbd/CrdBrlyUsr/*.cpp $BUILDROOT/brlycmbd/CrdBrlyUsr/

cp Makefile_CrdBrlyPrs $BUILDROOT/brlycmbd/CrdBrlyPrs/Makefile

cp ../../brlycmbd/CrdBrlyPrs/*.h $BUILDROOT/brlycmbd/CrdBrlyPrs/
cp ../../brlycmbd/CrdBrlyPrs/*.cpp $BUILDROOT/brlycmbd/CrdBrlyPrs/

cp Makefile_CrdBrlyFil $BUILDROOT/brlycmbd/CrdBrlyFil/Makefile

cp ../../brlycmbd/CrdBrlyFil/*.h $BUILDROOT/brlycmbd/CrdBrlyFil/
cp ../../brlycmbd/CrdBrlyFil/*.cpp $BUILDROOT/brlycmbd/CrdBrlyFil/

cp Makefile_CrdBrlyOpr $BUILDROOT/brlycmbd/CrdBrlyOpr/Makefile

cp ../../brlycmbd/CrdBrlyOpr/*.h $BUILDROOT/brlycmbd/CrdBrlyOpr/
cp ../../brlycmbd/CrdBrlyOpr/*.cpp $BUILDROOT/brlycmbd/CrdBrlyOpr/

cp Makefile_CrdBrlyPty $BUILDROOT/brlycmbd/CrdBrlyPty/Makefile

cp ../../brlycmbd/CrdBrlyPty/*.h $BUILDROOT/brlycmbd/CrdBrlyPty/
cp ../../brlycmbd/CrdBrlyPty/*.cpp $BUILDROOT/brlycmbd/CrdBrlyPty/

cp Makefile_CrdBrlyNav $BUILDROOT/brlycmbd/CrdBrlyNav/Makefile

cp ../../brlycmbd/CrdBrlyNav/*.h $BUILDROOT/brlycmbd/CrdBrlyNav/
cp ../../brlycmbd/CrdBrlyNav/*.cpp $BUILDROOT/brlycmbd/CrdBrlyNav/

cp Makefile_CrdBrlyReg $BUILDROOT/brlycmbd/CrdBrlyReg/Makefile

cp ../../brlycmbd/CrdBrlyReg/*.h $BUILDROOT/brlycmbd/CrdBrlyReg/
cp ../../brlycmbd/CrdBrlyReg/*.cpp $BUILDROOT/brlycmbd/CrdBrlyReg/

cp Makefile_CrdBrlyLoc $BUILDROOT/brlycmbd/CrdBrlyLoc/Makefile

cp ../../brlycmbd/CrdBrlyLoc/*.h $BUILDROOT/brlycmbd/CrdBrlyLoc/
cp ../../brlycmbd/CrdBrlyLoc/*.cpp $BUILDROOT/brlycmbd/CrdBrlyLoc/

cp Makefile_CrdBrlyLeg $BUILDROOT/brlycmbd/CrdBrlyLeg/Makefile

cp ../../brlycmbd/CrdBrlyLeg/*.h $BUILDROOT/brlycmbd/CrdBrlyLeg/
cp ../../brlycmbd/CrdBrlyLeg/*.cpp $BUILDROOT/brlycmbd/CrdBrlyLeg/

cp Makefile_CrdBrlyTtb $BUILDROOT/brlycmbd/CrdBrlyTtb/Makefile

cp ../../brlycmbd/CrdBrlyTtb/*.h $BUILDROOT/brlycmbd/CrdBrlyTtb/
cp ../../brlycmbd/CrdBrlyTtb/*.cpp $BUILDROOT/brlycmbd/CrdBrlyTtb/

cp Makefile_CrdBrlyFlt $BUILDROOT/brlycmbd/CrdBrlyFlt/Makefile

cp ../../brlycmbd/CrdBrlyFlt/*.h $BUILDROOT/brlycmbd/CrdBrlyFlt/
cp ../../brlycmbd/CrdBrlyFlt/*.cpp $BUILDROOT/brlycmbd/CrdBrlyFlt/

cp Makefile_CrdBrlySeg $BUILDROOT/brlycmbd/CrdBrlySeg/Makefile

cp ../../brlycmbd/CrdBrlySeg/*.h $BUILDROOT/brlycmbd/CrdBrlySeg/
cp ../../brlycmbd/CrdBrlySeg/*.cpp $BUILDROOT/brlycmbd/CrdBrlySeg/

cp Makefile_CrdBrlyCon $BUILDROOT/brlycmbd/CrdBrlyCon/Makefile

cp ../../brlycmbd/CrdBrlyCon/*.h $BUILDROOT/brlycmbd/CrdBrlyCon/
cp ../../brlycmbd/CrdBrlyCon/*.cpp $BUILDROOT/brlycmbd/CrdBrlyCon/

cp Makefile_CrdBrlyRly $BUILDROOT/brlycmbd/CrdBrlyRly/Makefile

cp ../../brlycmbd/CrdBrlyRly/*.h $BUILDROOT/brlycmbd/CrdBrlyRly/
cp ../../brlycmbd/CrdBrlyRly/*.cpp $BUILDROOT/brlycmbd/CrdBrlyRly/

cp Makefile_BrlyTtimp $BUILDROOT/brlycmbd/BrlyTtimp/Makefile

cp ../../brlycmbd/BrlyTtimp/*.h $BUILDROOT/brlycmbd/BrlyTtimp/
cp ../../brlycmbd/BrlyTtimp/*.cpp $BUILDROOT/brlycmbd/BrlyTtimp/

cp Makefile_BrlyDyn $BUILDROOT/brlycmbd/BrlyDyn/Makefile

cp ../../brlycmbd/BrlyDyn/*.h $BUILDROOT/brlycmbd/BrlyDyn/
cp ../../brlycmbd/BrlyDyn/*.cpp $BUILDROOT/brlycmbd/BrlyDyn/

cp Makefile_BrlyMapgen $BUILDROOT/brlycmbd/BrlyMapgen/Makefile

cp ../../brlycmbd/BrlyMapgen/*.h $BUILDROOT/brlycmbd/BrlyMapgen/
cp ../../brlycmbd/BrlyMapgen/*.cpp $BUILDROOT/brlycmbd/BrlyMapgen/

cp Makefile_BrlyBase $BUILDROOT/brlycmbd/BrlyBase/Makefile

cp ../../brlycmbd/BrlyBase/*.h $BUILDROOT/brlycmbd/BrlyBase/
cp ../../brlycmbd/BrlyBase/*.cpp $BUILDROOT/brlycmbd/BrlyBase/

cp Makefile_BrlyDnsmap $BUILDROOT/brlycmbd/BrlyDnsmap/Makefile

cp ../../brlycmbd/BrlyDnsmap/*.h $BUILDROOT/brlycmbd/BrlyDnsmap/
cp ../../brlycmbd/BrlyDnsmap/*.cpp $BUILDROOT/brlycmbd/BrlyDnsmap/
