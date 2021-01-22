/**
	* \file VecBrlyVOpengtype.cpp
	* vector VecBrlyVOpengtype (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "VecBrlyVOpengtype.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecBrlyVOpengtype
 ******************************************************************************/

uint VecBrlyVOpengtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "brlyopd") return BRLYOPD;

	return(0);
};

string VecBrlyVOpengtype::getSref(
			const uint ix
		) {
	if (ix == BRLYOPD) return("brlyopd");

	return("");
};

string VecBrlyVOpengtype::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == BRLYOPD) return("brlyopd with BrlyBase/BrlyDnsmap/BrlyDyn/BrlyMapgen/BrlyTtimp");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == BRLYOPD) return("brlyopd mit BrlyBase/BrlyDnsmap/BrlyDyn/BrlyMapgen/BrlyTtimp");
		return(getTitle(ix, 1));
	};

	return("");
};

void VecBrlyVOpengtype::appendToFeed(
			const uint ix
			, const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixBrlyVLocale));
};

void VecBrlyVOpengtype::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};
