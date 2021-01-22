/**
	* \file SqkBrlyTtimp.cpp
	* squawk generation for operation pack BrlyTtimp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "SqkBrlyTtimp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkBrlyTtimp
 ******************************************************************************/

string SqkBrlyTtimp::getSquawkRawstar(
			DbsBrly* dbsbrly
			, DpchInvBrlyTtimpRawstar* dpchinv
		) {
	// example: "transform file 'Star01122006_16022007.txt' from Star Alliance into intermediate format"
	return("translate file '" + dpchinv->infile + "' from StarAlliance into intermediate format"); // IP getSquawkRawstar --- RLINE
};
