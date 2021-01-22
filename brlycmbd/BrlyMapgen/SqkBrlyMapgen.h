/**
	* \file SqkBrlyMapgen.h
	* squawk generation for operation pack BrlyMapgen (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef SQKBRLYMAPGEN_H
#define SQKBRLYMAPGEN_H

#include "BrlyMapgen_blks.h"

/**
	* SqkBrlyMapgen
	*/
namespace SqkBrlyMapgen {
	std::string getSquawkConmap(DbsBrly* dbsbrly, DpchInvBrlyMapgenConmap* dpchinv);
	std::string getSquawkLegmap(DbsBrly* dbsbrly, DpchInvBrlyMapgenLegmap* dpchinv);
	std::string getSquawkLocmap(DbsBrly* dbsbrly, DpchInvBrlyMapgenLocmap* dpchinv);
};

#endif
