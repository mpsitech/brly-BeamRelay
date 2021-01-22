#!/bin/bash
# file remake.sh
# re-make script for Brly combined daemon, release brlycmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Jan 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/brly/_rls/brlycmbd_ubuntu
./checkout.sh

cd $BUILDROOT/brlycmbd

./make.sh "$@"
