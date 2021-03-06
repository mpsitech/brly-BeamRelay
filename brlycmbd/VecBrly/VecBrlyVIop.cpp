/**
	* \file VecBrlyVIop.cpp
	* vector VecBrlyVIop (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "VecBrlyVIop.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecBrlyVIop
 ******************************************************************************/

uint VecBrlyVIop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "retr") return RETR;
	if (s == "retrins") return RETRINS;
	if (s == "retrupd") return RETRUPD;
	if (s == "retrupdins") return RETRUPDINS;
	if (s == "rmv") return RMV;

	return(0);
};

string VecBrlyVIop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RETR) return("retr");
	if (ix == RETRINS) return("retrins");
	if (ix == RETRUPD) return("retrupd");
	if (ix == RETRUPDINS) return("retrupdins");
	if (ix == RMV) return("rmv");

	return("");
};

string VecBrlyVIop::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == INS) return("insert");
		if (ix == RETR) return("retrieve");
		if (ix == RETRINS) return("retrieve, else insert");
		if (ix == RETRUPD) return("retrieve and update");
		if (ix == RETRUPDINS) return("retrieve and update, else insert");
		if (ix == RMV) return("remove");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == INS) return("einf\\u00fcgen");
		if (ix == RETR) return("auffinden");
		if (ix == RETRINS) return("auffinden, sonst einf\\u00fcgen");
		if (ix == RETRUPD) return("auffinden und aktualisieren");
		if (ix == RETRUPDINS) return("auffinden und aktualisieren, sonst einf\\u00fcgen");
		if (ix == RMV) return("entfernen");
		return(getTitle(ix, 1));
	};

	return("");
};

void VecBrlyVIop::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};
