/**
	* \file BrlyMFile_vecs.cpp
	* database access for table TblBrlyMFile (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblBrlyMFile::VecVRefTbl
 ******************************************************************************/

uint TblBrlyMFile::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "ttb") return TTB;

	return(0);
};

string TblBrlyMFile::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TTB) return("ttb");

	return("");
};

string TblBrlyMFile::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TTB) return("timetable");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == VOID) return("keine");
		if (ix == TTB) return("Flugplan");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblBrlyMFile::VecVRefTbl::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};
