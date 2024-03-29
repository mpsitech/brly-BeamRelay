#!/bin/bash
# file checkout.sh
# checkout script for Brly web-based UI, release webappbrly_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${WHIZROOT}/web

mkdir $WEBROOT/appbrly

cp checkin.sh $WEBROOT/appbrly/

cp -r ../../webappbrly/* $WEBROOT/appbrly/
cp ../../webappbrly/iconbrly/favicon.ico $WEBROOT/appbrly/
