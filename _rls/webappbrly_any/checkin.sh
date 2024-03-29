#!/bin/bash
# file checkin.sh
# checkin script for Brly web-based UI, release webappbrly_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set REPROOT=${WHIZDEVROOT}/rep

cp -r * $REPROOT/brly/webappbrly/
mv $REPROOT/brly/webappbrly/favicon.ico $REPROOT/brly/webappbrly/iconbrly/
touch $REPROOT/brly/webappbrly/iconbrly/"IP folder --- KEEP"

rm $REPROOT/brly/webappbrly/checkin.sh
