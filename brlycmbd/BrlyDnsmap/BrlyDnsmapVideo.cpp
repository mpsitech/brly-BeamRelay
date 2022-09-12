/**
	* \file BrlyDnsmapVideo.cpp
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

#include "BrlyDnsmapVideo.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace BrlyDnsmap;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace BrlyDnsmapVideo
 ******************************************************************************/

DpchRetBrlyDnsmapVideo* BrlyDnsmapVideo::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyDnsmapVideo* dpchinv
		) {
	double altzmax = dpchinv->altzmax;
	uint frmrate = dpchinv->frmrate;
	bool fullsize = dpchinv->fullsize;
	bool grayscale = dpchinv->grayscale;
	ubigint refBrlyMFile = dpchinv->refBrlyMFile;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string folder;

	// IP run --- INSERT

	return(new DpchRetBrlyDnsmapVideo("", "", ixOpVOpres, 100, folder));
};

// IP cust --- INSERT
