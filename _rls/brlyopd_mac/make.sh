#!/bin/bash
# file make.sh
# make script for Brly operation daemon, release brlyopd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

if [ "$1" = "all" ] || [ "$1" = "clean" ]; then
	subs=("IexBrly" "VecBrly" "BrlyTtimp" "BrlyMapgen" "BrlyDyn" "BrlyDnsmap" "BrlyBase")
else
	subs=("$@")
fi

if [ "$1" = "clean" ]; then
	for var in "${subs[@]}"
	do
		cd "$var"
		make clean
		cd ..
	done

	make clean
else
	make Brlyopd.h.gch
	if [ $? -ne 0 ]; then
		exit
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

	rm Brlyopd.h.gch
fi
