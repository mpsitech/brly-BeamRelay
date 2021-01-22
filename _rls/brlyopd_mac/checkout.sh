#!/bin/bash
# file checkout.sh
# checkout script for Brly operation daemon, release brlyopd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Jan 2021
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

mkdir $BUILDROOT/brlyopd
mkdir $BUILDROOT/brlyopd/IexBrly
mkdir $BUILDROOT/brlyopd/VecBrly
mkdir $BUILDROOT/brlyopd/BrlyTtimp
mkdir $BUILDROOT/brlyopd/BrlyMapgen
mkdir $BUILDROOT/brlyopd/BrlyDyn
mkdir $BUILDROOT/brlyopd/BrlyDnsmap
mkdir $BUILDROOT/brlyopd/BrlyBase

mkdir $LIBROOT/brlyopd

mkdir $BINROOT/brlyopd

cp make.sh $BUILDROOT/brlyopd/
cp remake.sh $BUILDROOT/brlyopd/

cp Makefile.inc $BUILDROOT/brlyopd/
cp Makefile $BUILDROOT/brlyopd/

cp ../../brlyopd/Brlyopd.h $BUILDROOT/brlyopd/
cp ../../brlyopd/Brlyopd.cpp $BUILDROOT/brlyopd/

cp ../../brlyopd/BrlyopdEngsrv.h $BUILDROOT/brlyopd/
cp ../../brlyopd/BrlyopdEngsrv.cpp $BUILDROOT/brlyopd/

cp ../../brlyopd/BrlyopdOpprc.h $BUILDROOT/brlyopd/
cp ../../brlyopd/BrlyopdOpprc.cpp $BUILDROOT/brlyopd/

cp ../../brlyopd/Brlyopd_exe.h $BUILDROOT/brlyopd/
cp ../../brlyopd/Brlyopd_exe.cpp $BUILDROOT/brlyopd/

cp $CMBDBUILDROOT/Brly.h $BUILDROOT/brlyopd/
cp $CMBDBUILDROOT/Brly.cpp $BUILDROOT/brlyopd/

cp Makefile_IexBrly $BUILDROOT/brlyopd/IexBrly/Makefile

cp $CMBDBUILDROOT/IexBrly/IexBrly*.h $BUILDROOT/brlyopd/IexBrly/
cp $CMBDBUILDROOT/IexBrly/IexBrly*.cpp $BUILDROOT/brlyopd/IexBrly/

cp Makefile_VecBrly $BUILDROOT/brlyopd/VecBrly/Makefile

cp $CMBDBUILDROOT/VecBrly/Vec*.h $BUILDROOT/brlyopd/VecBrly/
cp $CMBDBUILDROOT/VecBrly/Vec*.cpp $BUILDROOT/brlyopd/VecBrly/

cp Makefile_BrlyTtimp $BUILDROOT/brlyopd/BrlyTtimp/Makefile

cp $CMBDBUILDROOT/BrlyTtimp/BrlyTtimp*.h $BUILDROOT/brlyopd/BrlyTtimp/
cp $CMBDBUILDROOT/BrlyTtimp/BrlyTtimp*.cpp $BUILDROOT/brlyopd/BrlyTtimp/

cp Makefile_BrlyMapgen $BUILDROOT/brlyopd/BrlyMapgen/Makefile

cp $CMBDBUILDROOT/BrlyMapgen/BrlyMapgen*.h $BUILDROOT/brlyopd/BrlyMapgen/
cp $CMBDBUILDROOT/BrlyMapgen/BrlyMapgen*.cpp $BUILDROOT/brlyopd/BrlyMapgen/

cp Makefile_BrlyDyn $BUILDROOT/brlyopd/BrlyDyn/Makefile

cp $CMBDBUILDROOT/BrlyDyn/BrlyDyn*.h $BUILDROOT/brlyopd/BrlyDyn/
cp $CMBDBUILDROOT/BrlyDyn/BrlyDyn*.cpp $BUILDROOT/brlyopd/BrlyDyn/

cp Makefile_BrlyDnsmap $BUILDROOT/brlyopd/BrlyDnsmap/Makefile

cp $CMBDBUILDROOT/BrlyDnsmap/BrlyDnsmap*.h $BUILDROOT/brlyopd/BrlyDnsmap/
cp $CMBDBUILDROOT/BrlyDnsmap/BrlyDnsmap*.cpp $BUILDROOT/brlyopd/BrlyDnsmap/

cp Makefile_BrlyBase $BUILDROOT/brlyopd/BrlyBase/Makefile

cp $CMBDBUILDROOT/BrlyBase/BrlyBase*.h $BUILDROOT/brlyopd/BrlyBase/
cp $CMBDBUILDROOT/BrlyBase/BrlyBase*.cpp $BUILDROOT/brlyopd/BrlyBase/
