#!/bin/bash
# file checkout.sh
# checkout script for Brly database access library, release dbsbrly_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Jan 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build

mkdir $BUILDROOT/dbsbrly

cp makeall.sh $BUILDROOT/dbsbrly/

cp Makefile $BUILDROOT/dbsbrly/

cp ../../dbsbrly/DbsBrly.h $BUILDROOT/dbsbrly/
cp ../../dbsbrly/DbsBrly_vecs.cpp $BUILDROOT/dbsbrly/
cp ../../dbsbrly/DbsBrly.cpp $BUILDROOT/dbsbrly/

cp ../../dbsbrly/Brly*.h $BUILDROOT/dbsbrly/
cp ../../dbsbrly/Brly*.cpp $BUILDROOT/dbsbrly/
