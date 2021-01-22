/**
	* \file BrlyMConnection_vecs.cpp
	* database access for table TblBrlyMConnection (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblBrlyMConnection::VecVModel
 ******************************************************************************/

uint TblBrlyMConnection::VecVModel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "spl") return SPL;
	if (s == "ext") return EXT;

	return(0);
};

string TblBrlyMConnection::VecVModel::getSref(
			const uint ix
		) {
	if (ix == SPL) return("spl");
	if (ix == EXT) return("ext");

	return("");
};

string TblBrlyMConnection::VecVModel::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == SPL) return("simple");
		if (ix == EXT) return("extended");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == SPL) return("einfach");
		if (ix == EXT) return("erweitert");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblBrlyMConnection::VecVModel::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};
