#!/bin/bash
# file make.sh
# make script for Brly combined daemon, release brlycmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Jan 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

make Brlycmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexBrly" "VecBrly" "CrdBrlyUsg" "CrdBrlyUsr" "CrdBrlyPrs" "CrdBrlyFil" "CrdBrlyOpr" "CrdBrlyPty" "CrdBrlyNav" "CrdBrlyReg" "CrdBrlyLoc" "CrdBrlyLeg" "CrdBrlyTtb" "CrdBrlyFlt" "CrdBrlySeg" "CrdBrlyCon" "CrdBrlyRly" "BrlyTtimp" "BrlyMapgen" "BrlyDyn" "BrlyDnsmap" "BrlyBase")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j4
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j4
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Brlycmbd.h.gch
