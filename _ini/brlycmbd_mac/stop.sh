#!/bin/bash
# file stop.sh
# stop script for Brly combined daemon, release brlycmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

pid=$(pgrep Brlycmbd)
kill -15 $pid
