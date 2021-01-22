#!/bin/bash
# file stop.sh
# stop script for Brly daemon, release brlyd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Jan 2021
# IP header --- ABOVE

pid=$(pgrep Brlyd)
kill -15 $pid
