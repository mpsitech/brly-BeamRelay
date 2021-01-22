/**
	* \file SqkBrlyDnsmap.h
	* squawk generation for operation pack BrlyDnsmap (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef SQKBRLYDNSMAP_H
#define SQKBRLYDNSMAP_H

#include "BrlyDnsmap_blks.h"

/**
	* SqkBrlyDnsmap
	*/
namespace SqkBrlyDnsmap {
	std::string getSquawkCollect(DbsBrly* dbsbrly, DpchInvBrlyDnsmapCollect* dpchinv);
	std::string getSquawkFrame(DbsBrly* dbsbrly, DpchInvBrlyDnsmapFrame* dpchinv);
	std::string getSquawkVideo(DbsBrly* dbsbrly, DpchInvBrlyDnsmapVideo* dpchinv);
};

#endif
