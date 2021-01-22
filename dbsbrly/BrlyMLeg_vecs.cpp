/**
	* \file BrlyMLeg_vecs.cpp
	* database access for table TblBrlyMLeg (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblBrlyMLeg::VecVBasetype
 ******************************************************************************/

uint TblBrlyMLeg::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "corr") return CORR;
	if (s == "rte") return RTE;

	return(0);
};

string TblBrlyMLeg::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == CORR) return("corr");
	if (ix == RTE) return("rte");

	return("");
};

string TblBrlyMLeg::VecVBasetype::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == CORR) return("corridor");
		if (ix == RTE) return("route");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == CORR) return("Korridor");
		if (ix == RTE) return("Route");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblBrlyMLeg::VecVBasetype::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class TblBrlyMLeg::VecWSubset
 ******************************************************************************/

uint TblBrlyMLeg::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbsbrlybmlegcor") ix |= SBSBRLYBMLEGCOR;
		else if (ss[i] == "sbsbrlybmlegrte") ix |= SBSBRLYBMLEGRTE;
	};

	return(ix);
};

void TblBrlyMLeg::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSBRLYBMLEGRTE); i *= 2) if (ix & i) ics.insert(i);
};

string TblBrlyMLeg::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSBRLYBMLEGCOR) ss.push_back("SbsBrlyBMLegCor");
	if (ix & SBSBRLYBMLEGRTE) ss.push_back("SbsBrlyBMLegRte");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblBrlyMLeg::VecWSubset::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == SBSBRLYBMLEGCOR) return("corridor");
		if (ix == SBSBRLYBMLEGRTE) return("route");
		return(getSrefs(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == SBSBRLYBMLEGCOR) return("Korridor");
		if (ix == SBSBRLYBMLEGRTE) return("Route");
		return(getTitle(ix, 1));
	};

	return("");
};
