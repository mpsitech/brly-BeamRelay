/**
	* \file BrlyMEquipment_vecs.cpp
	* database access for table TblBrlyMEquipment (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblBrlyMEquipment::VecVHkTbl
 ******************************************************************************/

uint TblBrlyMEquipment::VecVHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "flt") return FLT;
	if (s == "loc") return LOC;

	return(0);
};

string TblBrlyMEquipment::VecVHkTbl::getSref(
			const uint ix
		) {
	if (ix == FLT) return("flt");
	if (ix == LOC) return("loc");

	return("");
};

string TblBrlyMEquipment::VecVHkTbl::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == FLT) return("flight");
		if (ix == LOC) return("location");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == FLT) return("Flug");
		if (ix == LOC) return("Ort");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblBrlyMEquipment::VecVHkTbl::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class TblBrlyMEquipment::VecWSubset
 ******************************************************************************/

uint TblBrlyMEquipment::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbsbrlybmequipmentpln") ix |= SBSBRLYBMEQUIPMENTPLN;
	};

	return(ix);
};

void TblBrlyMEquipment::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSBRLYBMEQUIPMENTPLN); i *= 2) if (ix & i) ics.insert(i);
};

string TblBrlyMEquipment::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSBRLYBMEQUIPMENTPLN) ss.push_back("SbsBrlyBMEquipmentPln");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblBrlyMEquipment::VecWSubset::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == SBSBRLYBMEQUIPMENTPLN) return("plane");
		return(getSrefs(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == SBSBRLYBMEQUIPMENTPLN) return("Flugzeug");
		return(getTitle(ix, 1));
	};

	return("");
};
