/**
	* \file VecBrlyVExpstate.cpp
	* vector VecBrlyVExpstate (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "VecBrlyVExpstate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecBrlyVExpstate
 ******************************************************************************/

uint VecBrlyVExpstate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detd") return DETD;
	if (s == "maxd") return MAXD;
	if (s == "mind") return MIND;
	if (s == "regd") return REGD;

	return(0);
};

string VecBrlyVExpstate::getSref(
			const uint ix
		) {
	if (ix == DETD) return("detd");
	if (ix == MAXD) return("maxd");
	if (ix == MIND) return("mind");
	if (ix == REGD) return("regd");

	return("");
};
