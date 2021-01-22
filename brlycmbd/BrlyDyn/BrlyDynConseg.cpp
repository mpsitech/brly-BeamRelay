/**
	* \file BrlyDynConseg.cpp
	* Brly operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyopd.h>
#endif

#include "BrlyDynConseg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace BrlyDyn;

/******************************************************************************
 namespace BrlyDynConseg
 ******************************************************************************/

DpchRetBrly* BrlyDynConseg::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDynConseg* dpchinv
		) {
	ubigint refBrlyMConnection = dpchinv->refBrlyMConnection;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
