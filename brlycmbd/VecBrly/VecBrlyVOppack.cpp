/**
	* \file VecBrlyVOppack.cpp
	* vector VecBrlyVOppack (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "VecBrlyVOppack.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecBrlyVOppack
 ******************************************************************************/

uint VecBrlyVOppack::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "brlybase") return BRLYBASE;
	if (s == "brlydnsmap") return BRLYDNSMAP;
	if (s == "brlydyn") return BRLYDYN;
	if (s == "brlymapgen") return BRLYMAPGEN;
	if (s == "brlyttimp") return BRLYTTIMP;

	return(0);
};

string VecBrlyVOppack::getSref(
			const uint ix
		) {
	if (ix == BRLYBASE) return("BrlyBase");
	if (ix == BRLYDNSMAP) return("BrlyDnsmap");
	if (ix == BRLYDYN) return("BrlyDyn");
	if (ix == BRLYMAPGEN) return("BrlyMapgen");
	if (ix == BRLYTTIMP) return("BrlyTtimp");

	return("");
};

string VecBrlyVOppack::getTitle(
			const uint ix
		) {
	if (ix == BRLYBASE) return("static calculation");
	if (ix == BRLYDNSMAP) return("density map generation");
	if (ix == BRLYDYN) return("dynamic calculation");
	if (ix == BRLYMAPGEN) return("map generation");
	if (ix == BRLYTTIMP) return("timetable import");
	return(getSref(ix));

	return("");
};

string VecBrlyVOppack::getComment(
			const uint ix
		) {

	return("");
};

void VecBrlyVOppack::appendToFeed(
			const uint ix
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix));
};

void VecBrlyVOppack::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};
