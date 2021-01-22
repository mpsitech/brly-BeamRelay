/**
	* \file SqkBrlyDnsmap.cpp
	* squawk generation for operation pack BrlyDnsmap (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "SqkBrlyDnsmap.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkBrlyDnsmap
 ******************************************************************************/

string SqkBrlyDnsmap::getSquawkCollect(
			DbsBrly* dbsbrly
			, DpchInvBrlyDnsmapCollect* dpchinv
		) {
	// example: "collect data for time-resolved density map"
	return("collect data for time-resolved density map"); // IP getSquawkCollect --- RLINE
};

string SqkBrlyDnsmap::getSquawkFrame(
			DbsBrly* dbsbrly
			, DpchInvBrlyDnsmapFrame* dpchinv
		) {
	// example: "generate video out of time-resolved density map"
	return("generate video out of time-resolved density map"); // IP getSquawkFrame --- RLINE
};

string SqkBrlyDnsmap::getSquawkVideo(
			DbsBrly* dbsbrly
			, DpchInvBrlyDnsmapVideo* dpchinv
		) {
	// example: "generate video out of time-resolved density map"
	return("generate video out of time-resolved density map"); // IP getSquawkVideo --- RLINE
};
