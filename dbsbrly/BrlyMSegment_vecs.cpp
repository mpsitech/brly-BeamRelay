/**
	* \file BrlyMSegment_vecs.cpp
	* database access for table TblBrlyMSegment (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblBrlyMSegment::VecVRefTbl
 ******************************************************************************/

uint TblBrlyMSegment::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "con") return CON;
	if (s == "flt") return FLT;

	return(0);
};

string TblBrlyMSegment::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == CON) return("con");
	if (ix == FLT) return("flt");

	return("");
};

string TblBrlyMSegment::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == CON) return("connection");
		if (ix == FLT) return("flight");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == CON) return("Verbindung");
		if (ix == FLT) return("Flug");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblBrlyMSegment::VecVRefTbl::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};
