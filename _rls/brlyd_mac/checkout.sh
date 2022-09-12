#!/bin/bash
# file checkout.sh
# checkout script for Brly daemon, release brlyd_mac
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
export set REPROOT=${WHIZDEVROOT}/rep
export set CMBDBUILDROOT=$REPROOT/brly/brlycmbd

mkdir $BUILDROOT/brlyd
mkdir $BUILDROOT/brlyd/IexBrly
mkdir $BUILDROOT/brlyd/VecBrly
mkdir $BUILDROOT/brlyd/CrdBrlyUsg
mkdir $BUILDROOT/brlyd/CrdBrlyUsr
mkdir $BUILDROOT/brlyd/CrdBrlyPrs
mkdir $BUILDROOT/brlyd/CrdBrlyFil
mkdir $BUILDROOT/brlyd/CrdBrlyOpr
mkdir $BUILDROOT/brlyd/CrdBrlyPty
mkdir $BUILDROOT/brlyd/CrdBrlyNav
mkdir $BUILDROOT/brlyd/CrdBrlyReg
mkdir $BUILDROOT/brlyd/CrdBrlyLoc
mkdir $BUILDROOT/brlyd/CrdBrlyLeg
mkdir $BUILDROOT/brlyd/CrdBrlyTtb
mkdir $BUILDROOT/brlyd/CrdBrlyFlt
mkdir $BUILDROOT/brlyd/CrdBrlySeg
mkdir $BUILDROOT/brlyd/CrdBrlyCon
mkdir $BUILDROOT/brlyd/CrdBrlyRly

mkdir $LIBROOT/brlyd

mkdir $BINROOT/brlyd

cp make.sh $BUILDROOT/brlyd/
cp remake.sh $BUILDROOT/brlyd/

cp Makefile.inc $BUILDROOT/brlyd/
cp Makefile $BUILDROOT/brlyd/

cp ../../brlyd/Brlyd.h $BUILDROOT/brlyd/
cp ../../brlyd/Brlyd.cpp $BUILDROOT/brlyd/

cp ../../brlyd/BrlydAppsrv.h $BUILDROOT/brlyd/
cp ../../brlyd/BrlydAppsrv.cpp $BUILDROOT/brlyd/

cp ../../brlyd/BrlydJobprc.h $BUILDROOT/brlyd/
cp ../../brlyd/BrlydJobprc.cpp $BUILDROOT/brlyd/

cp ../../brlyd/BrlydOpprc.h $BUILDROOT/brlyd/
cp ../../brlyd/BrlydOpprc.cpp $BUILDROOT/brlyd/

cp ../../brlyd/BrlydOpengsrv.h $BUILDROOT/brlyd/
cp ../../brlyd/BrlydOpengsrv.cpp $BUILDROOT/brlyd/

cp ../../brlyd/BrlydOpengcli.h $BUILDROOT/brlyd/
cp ../../brlyd/BrlydOpengcli.cpp $BUILDROOT/brlyd/

cp ../../brlyd/Brlyd_exe.h $BUILDROOT/brlyd/
cp ../../brlyd/Brlyd_exe.cpp $BUILDROOT/brlyd/

cp $CMBDBUILDROOT/Brly.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/Brly.cpp $BUILDROOT/brlyd/

cp $CMBDBUILDROOT/Root*.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/Root*.cpp $BUILDROOT/brlyd/

cp $CMBDBUILDROOT/Sess*.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/Sess*.cpp $BUILDROOT/brlyd/

cp $CMBDBUILDROOT/gbl/*.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/gbl/*.cpp $BUILDROOT/brlyd/

cp Makefile_IexBrly $BUILDROOT/brlyd/IexBrly/Makefile

cp $CMBDBUILDROOT/IexBrly/IexBrly*.h $BUILDROOT/brlyd/IexBrly/
cp $CMBDBUILDROOT/IexBrly/IexBrly*.cpp $BUILDROOT/brlyd/IexBrly/

cp $CMBDBUILDROOT/IexBrly/JobBrlyIex*.h $BUILDROOT/brlyd/IexBrly/
cp $CMBDBUILDROOT/IexBrly/JobBrlyIex*.cpp $BUILDROOT/brlyd/IexBrly/

cp Makefile_VecBrly $BUILDROOT/brlyd/VecBrly/Makefile

cp $CMBDBUILDROOT/VecBrly/Vec*.h $BUILDROOT/brlyd/VecBrly/
cp $CMBDBUILDROOT/VecBrly/Vec*.cpp $BUILDROOT/brlyd/VecBrly/

cp Makefile_CrdBrlyUsg $BUILDROOT/brlyd/CrdBrlyUsg/Makefile

cp $CMBDBUILDROOT/CrdBrlyUsg/*.h $BUILDROOT/brlyd/CrdBrlyUsg/
cp $CMBDBUILDROOT/CrdBrlyUsg/*.cpp $BUILDROOT/brlyd/CrdBrlyUsg/

cp Makefile_CrdBrlyUsr $BUILDROOT/brlyd/CrdBrlyUsr/Makefile

cp $CMBDBUILDROOT/CrdBrlyUsr/*.h $BUILDROOT/brlyd/CrdBrlyUsr/
cp $CMBDBUILDROOT/CrdBrlyUsr/*.cpp $BUILDROOT/brlyd/CrdBrlyUsr/

cp Makefile_CrdBrlyPrs $BUILDROOT/brlyd/CrdBrlyPrs/Makefile

cp $CMBDBUILDROOT/CrdBrlyPrs/*.h $BUILDROOT/brlyd/CrdBrlyPrs/
cp $CMBDBUILDROOT/CrdBrlyPrs/*.cpp $BUILDROOT/brlyd/CrdBrlyPrs/

cp Makefile_CrdBrlyFil $BUILDROOT/brlyd/CrdBrlyFil/Makefile

cp $CMBDBUILDROOT/CrdBrlyFil/*.h $BUILDROOT/brlyd/CrdBrlyFil/
cp $CMBDBUILDROOT/CrdBrlyFil/*.cpp $BUILDROOT/brlyd/CrdBrlyFil/

cp Makefile_CrdBrlyOpr $BUILDROOT/brlyd/CrdBrlyOpr/Makefile

cp $CMBDBUILDROOT/CrdBrlyOpr/*.h $BUILDROOT/brlyd/CrdBrlyOpr/
cp $CMBDBUILDROOT/CrdBrlyOpr/*.cpp $BUILDROOT/brlyd/CrdBrlyOpr/

cp Makefile_CrdBrlyPty $BUILDROOT/brlyd/CrdBrlyPty/Makefile

cp $CMBDBUILDROOT/CrdBrlyPty/*.h $BUILDROOT/brlyd/CrdBrlyPty/
cp $CMBDBUILDROOT/CrdBrlyPty/*.cpp $BUILDROOT/brlyd/CrdBrlyPty/

cp Makefile_CrdBrlyNav $BUILDROOT/brlyd/CrdBrlyNav/Makefile

cp $CMBDBUILDROOT/CrdBrlyNav/*.h $BUILDROOT/brlyd/CrdBrlyNav/
cp $CMBDBUILDROOT/CrdBrlyNav/*.cpp $BUILDROOT/brlyd/CrdBrlyNav/

cp Makefile_CrdBrlyReg $BUILDROOT/brlyd/CrdBrlyReg/Makefile

cp $CMBDBUILDROOT/CrdBrlyReg/*.h $BUILDROOT/brlyd/CrdBrlyReg/
cp $CMBDBUILDROOT/CrdBrlyReg/*.cpp $BUILDROOT/brlyd/CrdBrlyReg/

cp Makefile_CrdBrlyLoc $BUILDROOT/brlyd/CrdBrlyLoc/Makefile

cp $CMBDBUILDROOT/CrdBrlyLoc/*.h $BUILDROOT/brlyd/CrdBrlyLoc/
cp $CMBDBUILDROOT/CrdBrlyLoc/*.cpp $BUILDROOT/brlyd/CrdBrlyLoc/

cp Makefile_CrdBrlyLeg $BUILDROOT/brlyd/CrdBrlyLeg/Makefile

cp $CMBDBUILDROOT/CrdBrlyLeg/*.h $BUILDROOT/brlyd/CrdBrlyLeg/
cp $CMBDBUILDROOT/CrdBrlyLeg/*.cpp $BUILDROOT/brlyd/CrdBrlyLeg/

cp Makefile_CrdBrlyTtb $BUILDROOT/brlyd/CrdBrlyTtb/Makefile

cp $CMBDBUILDROOT/CrdBrlyTtb/*.h $BUILDROOT/brlyd/CrdBrlyTtb/
cp $CMBDBUILDROOT/CrdBrlyTtb/*.cpp $BUILDROOT/brlyd/CrdBrlyTtb/

cp Makefile_CrdBrlyFlt $BUILDROOT/brlyd/CrdBrlyFlt/Makefile

cp $CMBDBUILDROOT/CrdBrlyFlt/*.h $BUILDROOT/brlyd/CrdBrlyFlt/
cp $CMBDBUILDROOT/CrdBrlyFlt/*.cpp $BUILDROOT/brlyd/CrdBrlyFlt/

cp Makefile_CrdBrlySeg $BUILDROOT/brlyd/CrdBrlySeg/Makefile

cp $CMBDBUILDROOT/CrdBrlySeg/*.h $BUILDROOT/brlyd/CrdBrlySeg/
cp $CMBDBUILDROOT/CrdBrlySeg/*.cpp $BUILDROOT/brlyd/CrdBrlySeg/

cp Makefile_CrdBrlyCon $BUILDROOT/brlyd/CrdBrlyCon/Makefile

cp $CMBDBUILDROOT/CrdBrlyCon/*.h $BUILDROOT/brlyd/CrdBrlyCon/
cp $CMBDBUILDROOT/CrdBrlyCon/*.cpp $BUILDROOT/brlyd/CrdBrlyCon/

cp Makefile_CrdBrlyRly $BUILDROOT/brlyd/CrdBrlyRly/Makefile

cp $CMBDBUILDROOT/CrdBrlyRly/*.h $BUILDROOT/brlyd/CrdBrlyRly/
cp $CMBDBUILDROOT/CrdBrlyRly/*.cpp $BUILDROOT/brlyd/CrdBrlyRly/

cp $CMBDBUILDROOT/BrlyTtimp/BrlyTtimp_blks.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyTtimp/BrlyTtimp_blks.cpp $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyTtimp/SqkBrlyTtimp.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyTtimp/SqkBrlyTtimp.cpp $BUILDROOT/brlyd/

cp $CMBDBUILDROOT/BrlyDyn/BrlyDyn_blks.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyDyn/BrlyDyn_blks.cpp $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyDyn/SqkBrlyDyn.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyDyn/SqkBrlyDyn.cpp $BUILDROOT/brlyd/

cp $CMBDBUILDROOT/BrlyMapgen/BrlyMapgen_blks.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyMapgen/BrlyMapgen_blks.cpp $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyMapgen/SqkBrlyMapgen.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyMapgen/SqkBrlyMapgen.cpp $BUILDROOT/brlyd/

cp $CMBDBUILDROOT/BrlyBase/BrlyBase_blks.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyBase/BrlyBase_blks.cpp $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyBase/SqkBrlyBase.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyBase/SqkBrlyBase.cpp $BUILDROOT/brlyd/

cp $CMBDBUILDROOT/BrlyDnsmap/BrlyDnsmap_blks.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyDnsmap/BrlyDnsmap_blks.cpp $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyDnsmap/SqkBrlyDnsmap.h $BUILDROOT/brlyd/
cp $CMBDBUILDROOT/BrlyDnsmap/SqkBrlyDnsmap.cpp $BUILDROOT/brlyd/
