#!/bin/bash
# file start.sh
# start script for Brly daemon, release brlyd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Jan 2021
# IP header --- ABOVE

nohup ./Brlyd -nocp &
disown
