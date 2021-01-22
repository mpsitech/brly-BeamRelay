/**
	* \file VecBrlyVQrystate.cpp
	* vector VecBrlyVQrystate (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "VecBrlyVQrystate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecBrlyVQrystate
 ******************************************************************************/

uint VecBrlyVQrystate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mnr") return MNR;
	if (s == "ood") return OOD;
	if (s == "slm") return SLM;
	if (s == "utd") return UTD;

	return(0);
};

string VecBrlyVQrystate::getSref(
			const uint ix
		) {
	if (ix == MNR) return("mnr");
	if (ix == OOD) return("ood");
	if (ix == SLM) return("slm");
	if (ix == UTD) return("utd");

	return("");
};

string VecBrlyVQrystate::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == MNR) return("might need refresh");
		if (ix == OOD) return("out of date");
		if (ix == SLM) return("slightly modified");
		if (ix == UTD) return("up to date");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == MNR) return("eventuell veraltet");
		if (ix == OOD) return("veraltet");
		if (ix == SLM) return("geringf\\u00fcgig ver\\u00e4ndert");
		if (ix == UTD) return("aktuell");
		return(getTitle(ix, 1));
	};

	return("");
};

void VecBrlyVQrystate::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};
