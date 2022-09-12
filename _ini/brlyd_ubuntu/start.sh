#!/bin/bash
# file start.sh
# start script for Brly daemon, release brlyd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

nohup ./Brlyd -nocp &
disown
