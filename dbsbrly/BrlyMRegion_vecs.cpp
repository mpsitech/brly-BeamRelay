/**
	* \file BrlyMRegion_vecs.cpp
	* database access for table TblBrlyMRegion (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblBrlyMRegion::VecVDst
 ******************************************************************************/

uint TblBrlyMRegion::VecVDst::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "none") return NONE;
	if (s == "ndst") return NDST;
	if (s == "sdst") return SDST;

	return(0);
};

string TblBrlyMRegion::VecVDst::getSref(
			const uint ix
		) {
	if (ix == NONE) return("none");
	if (ix == NDST) return("ndst");
	if (ix == SDST) return("sdst");

	return("");
};

string TblBrlyMRegion::VecVDst::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == NONE) return("none");
		if (ix == NDST) return("northern hemisphere");
		if (ix == SDST) return("southern hemisphere");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == NONE) return("keine");
		if (ix == NDST) return("Nordhalbkugel");
		if (ix == SDST) return("S\\u00fcdhalbkugel");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblBrlyMRegion::VecVDst::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class TblBrlyMRegion::VecWSubset
 ******************************************************************************/

uint TblBrlyMRegion::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbsbrlybmregionrip") ix |= SBSBRLYBMREGIONRIP;
	};

	return(ix);
};

void TblBrlyMRegion::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSBRLYBMREGIONRIP); i *= 2) if (ix & i) ics.insert(i);
};

string TblBrlyMRegion::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSBRLYBMREGIONRIP) ss.push_back("SbsBrlyBMRegionRip");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblBrlyMRegion::VecWSubset::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == SBSBRLYBMREGIONRIP) return("impartible region");
		return(getSrefs(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == SBSBRLYBMREGIONRIP) return("unteilbare Region");
		return(getTitle(ix, 1));
	};

	return("");
};
