#!/bin/bash
# file checkin.sh
# checkin script for Brly Vue.js UI, release vueappbrly_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set REPROOT=${WHIZDEVROOT}/rep

cp AppBrly.vue $REPROOT/brly/vueappbrly/
cp main.js $REPROOT/brly/vueappbrly/

cp assets/* $REPROOT/brly/vueappbrly/assets/
cp ../public/favicon.ico $REPROOT/brly/vueappbrly/assets/
touch $REPROOT/brly/vueappbrly/assets/"IP folder --- KEEP"

cp -r components/* $REPROOT/brly/vueappbrly/

cp -r scripts $REPROOT/brly/vueappbrly/
