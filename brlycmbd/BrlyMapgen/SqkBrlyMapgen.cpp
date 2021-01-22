/**
	* \file SqkBrlyMapgen.cpp
	* squawk generation for operation pack BrlyMapgen (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "SqkBrlyMapgen.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkBrlyMapgen
 ******************************************************************************/

string SqkBrlyMapgen::getSquawkConmap(
			DbsBrly* dbsbrly
			, DpchInvBrlyMapgenConmap* dpchinv
		) {
	// example: "generate map for connection '(region) eu-c-de - (flight) LH403 2007-2-16 FRA-JFK, t0: 16-02-2007 0:00'"
	return("generate map for connection '" + StubBrly::getStubConStd(dbsbrly, dpchinv->refBrlyMConnection) + "'"); // IP getSquawkConmap --- RLINE
};

string SqkBrlyMapgen::getSquawkLegmap(
			DbsBrly* dbsbrly
			, DpchInvBrlyMapgenLegmap* dpchinv
		) {
	// example: "generate map for leg 'FRA-JFK'"
	return("generate map for leg '" + StubBrly::getStubLegStd(dbsbrly, dpchinv->refBrlyMLeg) + "'"); // IP getSquawkLegmap --- RLINE
};

string SqkBrlyMapgen::getSquawkLocmap(
			DbsBrly* dbsbrly
			, DpchInvBrlyMapgenLocmap* dpchinv
		) {
	// example: "generate map for location '(airport) Frankfurt'"
	return("generate map for location '" + StubBrly::getStubLocStd(dbsbrly, dpchinv->refBrlyMLocation) + "'"); // IP getSquawkLocmap --- RLINE
};
