/**
	* \file BrlyMLocation_vecs.cpp
	* database access for table TblBrlyMLocation (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblBrlyMLocation::VecVBasetype
 ******************************************************************************/

uint TblBrlyMLocation::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "apt") return APT;
	if (s == "gnd") return GND;
	if (s == "elv") return ELV;

	return(0);
};

string TblBrlyMLocation::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == APT) return("apt");
	if (ix == GND) return("gnd");
	if (ix == ELV) return("elv");

	return("");
};

string TblBrlyMLocation::VecVBasetype::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == APT) return("airport");
		if (ix == GND) return("ground location");
		if (ix == ELV) return("elevated location");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == APT) return("Flughafen");
		if (ix == GND) return("Ort am Boden");
		if (ix == ELV) return("schwebender Ort");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblBrlyMLocation::VecVBasetype::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class TblBrlyMLocation::VecWSubset
 ******************************************************************************/

uint TblBrlyMLocation::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbsbrlybmlocationapt") ix |= SBSBRLYBMLOCATIONAPT;
	};

	return(ix);
};

void TblBrlyMLocation::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSBRLYBMLOCATIONAPT); i *= 2) if (ix & i) ics.insert(i);
};

string TblBrlyMLocation::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSBRLYBMLOCATIONAPT) ss.push_back("SbsBrlyBMLocationApt");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblBrlyMLocation::VecWSubset::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == SBSBRLYBMLOCATIONAPT) return("airport");
		return(getSrefs(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == SBSBRLYBMLOCATIONAPT) return("Flughafen");
		return(getTitle(ix, 1));
	};

	return("");
};
