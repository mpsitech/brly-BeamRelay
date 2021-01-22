/**
	* \file SqkBrlyBase.cpp
	* squawk generation for operation pack BrlyBase (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "SqkBrlyBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkBrlyBase
 ******************************************************************************/

string SqkBrlyBase::getSquawkLegleg(
			DbsBrly* dbsbrly
			, DpchInvBrlyBaseLegleg* dpchinv
		) {
	// example: "calculate leg-to-leg visibility"
	return("calculate leg-to-leg visibility"); // IP getSquawkLegleg --- RLINE
};

string SqkBrlyBase::getSquawkLegloc(
			DbsBrly* dbsbrly
			, DpchInvBrlyBaseLegloc* dpchinv
		) {
	// example: "calculate location-to-leg visibility"
	return("calculate location-to-leg visibility"); // IP getSquawkLegloc --- RLINE
};

string SqkBrlyBase::getSquawkLocloc(
			DbsBrly* dbsbrly
			, DpchInvBrlyBaseLocloc* dpchinv
		) {
	// example: "calculate location-to-location proximity and visibility"
	return("calculate location-to-location proximity and visibility"); // IP getSquawkLocloc --- RLINE
};
