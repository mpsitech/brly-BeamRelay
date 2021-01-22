/**
	* \file VecBrlyVReqitmode.cpp
	* vector VecBrlyVReqitmode (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "VecBrlyVReqitmode.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecBrlyVReqitmode
 ******************************************************************************/

uint VecBrlyVReqitmode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "notify") return NOTIFY;
	if (s == "poll") return POLL;

	return(0);
};

string VecBrlyVReqitmode::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == NOTIFY) return("notify");
	if (ix == POLL) return("poll");

	return("");
};
