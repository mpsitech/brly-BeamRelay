/**
	* \file BrlyMRelay_vecs.cpp
	* database access for table TblBrlyMRelay (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblBrlyMRelay::VecVDir
 ******************************************************************************/

uint TblBrlyMRelay::VecVDir::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "bwd") return BWD;
	if (s == "fwd") return FWD;

	return(0);
};

string TblBrlyMRelay::VecVDir::getSref(
			const uint ix
		) {
	if (ix == BWD) return("bwd");
	if (ix == FWD) return("fwd");

	return("");
};

string TblBrlyMRelay::VecVDir::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == BWD) return("backward");
		if (ix == FWD) return("forward");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == BWD) return("r\\u00fcckw\\u00e4rts");
		if (ix == FWD) return("vorw\\u00e4rts");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblBrlyMRelay::VecVDir::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};
