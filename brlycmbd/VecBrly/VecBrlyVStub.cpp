/**
	* \file VecBrlyVStub.cpp
	* vector VecBrlyVStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "VecBrlyVStub.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecBrlyVStub
 ******************************************************************************/

uint VecBrlyVStub::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "stubbrlyconstd") return STUBBRLYCONSTD;
	if (s == "stubbrlyeqpshort") return STUBBRLYEQPSHORT;
	if (s == "stubbrlyeqpstd") return STUBBRLYEQPSTD;
	if (s == "stubbrlyfafstd") return STUBBRLYFAFSTD;
	if (s == "stubbrlyfilstd") return STUBBRLYFILSTD;
	if (s == "stubbrlyfltsref") return STUBBRLYFLTSREF;
	if (s == "stubbrlyfltstd") return STUBBRLYFLTSTD;
	if (s == "stubbrlylegshort") return STUBBRLYLEGSHORT;
	if (s == "stubbrlylegstd") return STUBBRLYLEGSTD;
	if (s == "stubbrlylocsref") return STUBBRLYLOCSREF;
	if (s == "stubbrlylocstd") return STUBBRLYLOCSTD;
	if (s == "stubbrlyloctitle") return STUBBRLYLOCTITLE;
	if (s == "stubbrlyndelong") return STUBBRLYNDELONG;
	if (s == "stubbrlyndestd") return STUBBRLYNDESTD;
	if (s == "stubbrlyoprsref") return STUBBRLYOPRSREF;
	if (s == "stubbrlyoprstd") return STUBBRLYOPRSTD;
	if (s == "stubbrlyprsstd") return STUBBRLYPRSSTD;
	if (s == "stubbrlyptysref") return STUBBRLYPTYSREF;
	if (s == "stubbrlyptystd") return STUBBRLYPTYSTD;
	if (s == "stubbrlyreghsref") return STUBBRLYREGHSREF;
	if (s == "stubbrlyreglong") return STUBBRLYREGLONG;
	if (s == "stubbrlyregstd") return STUBBRLYREGSTD;
	if (s == "stubbrlyrlylong") return STUBBRLYRLYLONG;
	if (s == "stubbrlyrlystd") return STUBBRLYRLYSTD;
	if (s == "stubbrlysegstd") return STUBBRLYSEGSTD;
	if (s == "stubbrlysesmenu") return STUBBRLYSESMENU;
	if (s == "stubbrlysesstd") return STUBBRLYSESSTD;
	if (s == "stubbrlyttbstd") return STUBBRLYTTBSTD;
	if (s == "stubbrlyttbtitle") return STUBBRLYTTBTITLE;
	if (s == "stubbrlyowner") return STUBBRLYOWNER;
	if (s == "stubbrlyusrstd") return STUBBRLYUSRSTD;
	if (s == "stubbrlygroup") return STUBBRLYGROUP;
	if (s == "stubbrlyusgstd") return STUBBRLYUSGSTD;

	return(0);
};

string VecBrlyVStub::getSref(
			const uint ix
		) {
	if (ix == STUBBRLYCONSTD) return("StubBrlyConStd");
	if (ix == STUBBRLYEQPSHORT) return("StubBrlyEqpShort");
	if (ix == STUBBRLYEQPSTD) return("StubBrlyEqpStd");
	if (ix == STUBBRLYFAFSTD) return("StubBrlyFafStd");
	if (ix == STUBBRLYFILSTD) return("StubBrlyFilStd");
	if (ix == STUBBRLYFLTSREF) return("StubBrlyFltSref");
	if (ix == STUBBRLYFLTSTD) return("StubBrlyFltStd");
	if (ix == STUBBRLYLEGSHORT) return("StubBrlyLegShort");
	if (ix == STUBBRLYLEGSTD) return("StubBrlyLegStd");
	if (ix == STUBBRLYLOCSREF) return("StubBrlyLocSref");
	if (ix == STUBBRLYLOCSTD) return("StubBrlyLocStd");
	if (ix == STUBBRLYLOCTITLE) return("StubBrlyLocTitle");
	if (ix == STUBBRLYNDELONG) return("StubBrlyNdeLong");
	if (ix == STUBBRLYNDESTD) return("StubBrlyNdeStd");
	if (ix == STUBBRLYOPRSREF) return("StubBrlyOprSref");
	if (ix == STUBBRLYOPRSTD) return("StubBrlyOprStd");
	if (ix == STUBBRLYPRSSTD) return("StubBrlyPrsStd");
	if (ix == STUBBRLYPTYSREF) return("StubBrlyPtySref");
	if (ix == STUBBRLYPTYSTD) return("StubBrlyPtyStd");
	if (ix == STUBBRLYREGHSREF) return("StubBrlyRegHsref");
	if (ix == STUBBRLYREGLONG) return("StubBrlyRegLong");
	if (ix == STUBBRLYREGSTD) return("StubBrlyRegStd");
	if (ix == STUBBRLYRLYLONG) return("StubBrlyRlyLong");
	if (ix == STUBBRLYRLYSTD) return("StubBrlyRlyStd");
	if (ix == STUBBRLYSEGSTD) return("StubBrlySegStd");
	if (ix == STUBBRLYSESMENU) return("StubBrlySesMenu");
	if (ix == STUBBRLYSESSTD) return("StubBrlySesStd");
	if (ix == STUBBRLYTTBSTD) return("StubBrlyTtbStd");
	if (ix == STUBBRLYTTBTITLE) return("StubBrlyTtbTitle");
	if (ix == STUBBRLYOWNER) return("StubBrlyOwner");
	if (ix == STUBBRLYUSRSTD) return("StubBrlyUsrStd");
	if (ix == STUBBRLYGROUP) return("StubBrlyGroup");
	if (ix == STUBBRLYUSGSTD) return("StubBrlyUsgStd");

	return("");
};
