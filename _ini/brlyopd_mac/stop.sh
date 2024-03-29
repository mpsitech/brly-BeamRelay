#!/bin/bash
# file stopall.sh
# stop script for Brly operation daemon(s), release brlyopd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

IFS=$'\n'
pids=$(pgrep Brlyopd)

for var in "${pids[@]}"
do
	kill -15 $var
done
