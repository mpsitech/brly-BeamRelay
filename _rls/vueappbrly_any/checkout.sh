#!/bin/bash
# file checkout.sh
# checkout script for Brly Vue.js UI, release vueappbrly_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${WHIZROOT}/web

mkdir $WEBROOT/vueappbrly/src

cp checkin.sh $WEBROOT/vueappbrly/src

cp ../../vueappbrly/AppBrly.vue $WEBROOT/vueappbrly/src/
cp ../../vueappbrly/main.js $WEBROOT/vueappbrly/src/

mkdir $WEBROOT/vueappbrly/src/assets

cp ../../vueappbrly/assets/* $WEBROOT/vueappbrly/src/assets/
cp ../../vueappbrly/assets/favicon.ico $WEBROOT/vueappbrly/public/

mkdir $WEBROOT/vueappbrly/src/components

cp ../../vueappbrly/SessBrly.vue $WEBROOT/vueappbrly/src/components/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyStart

cp ../../vueappbrly/CrdBrlyStart/CrdBrlyStart.vue $WEBROOT/vueappbrly/src/components/CrdBrlyStart/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyUsg

cp ../../vueappbrly/CrdBrlyUsg/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyUsg/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyUsr

cp ../../vueappbrly/CrdBrlyUsr/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyUsr/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyPrs

cp ../../vueappbrly/CrdBrlyPrs/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyPrs/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyFil

cp ../../vueappbrly/CrdBrlyFil/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyFil/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyOpr

cp ../../vueappbrly/CrdBrlyOpr/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyOpr/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyPty

cp ../../vueappbrly/CrdBrlyPty/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyPty/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyNav

cp ../../vueappbrly/CrdBrlyNav/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyNav/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyReg

cp ../../vueappbrly/CrdBrlyReg/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyReg/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyLoc

cp ../../vueappbrly/CrdBrlyLoc/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyLoc/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyLeg

cp ../../vueappbrly/CrdBrlyLeg/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyLeg/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyTtb

cp ../../vueappbrly/CrdBrlyTtb/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyTtb/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyFlt

cp ../../vueappbrly/CrdBrlyFlt/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyFlt/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlySeg

cp ../../vueappbrly/CrdBrlySeg/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlySeg/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyCon

cp ../../vueappbrly/CrdBrlyCon/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyCon/

mkdir $WEBROOT/vueappbrly/src/components/CrdBrlyRly

cp ../../vueappbrly/CrdBrlyRly/*.vue $WEBROOT/vueappbrly/src/components/CrdBrlyRly/

mkdir $WEBROOT/vueappbrly/src/scripts

cp ../../vueappbrly/scripts/*.js $WEBROOT/vueappbrly/src/scripts/
