/**
	* \file BrlyMUser_vecs.cpp
	* database access for table TblBrlyMUser (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblBrlyMUser::VecVState
 ******************************************************************************/

uint TblBrlyMUser::VecVState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "act") return ACT;
	if (s == "dsg") return DSG;
	if (s == "due") return DUE;
	if (s == "exp") return EXP;

	return(0);
};

string TblBrlyMUser::VecVState::getSref(
			const uint ix
		) {
	if (ix == ACT) return("act");
	if (ix == DSG) return("dsg");
	if (ix == DUE) return("due");
	if (ix == EXP) return("exp");

	return("");
};

string TblBrlyMUser::VecVState::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == ACT) return("active");
		if (ix == DSG) return("designated");
		if (ix == DUE) return("due for expiration");
		if (ix == EXP) return("expired");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == ACT) return("aktiv");
		if (ix == DSG) return("vorgesehen");
		if (ix == DUE) return("l\\u00e4uft ab");
		if (ix == EXP) return("abgelaufen");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblBrlyMUser::VecVState::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};
