/**
	* \file SqkBrlyDyn.h
	* squawk generation for operation pack BrlyDyn (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef SQKBRLYDYN_H
#define SQKBRLYDYN_H

#include "BrlyDyn_blks.h"

/**
	* SqkBrlyDyn
	*/
namespace SqkBrlyDyn {
	std::string getSquawkConflt(DbsBrly* dbsbrly, DpchInvBrlyDynConflt* dpchinv);
	std::string getSquawkConseg(DbsBrly* dbsbrly, DpchInvBrlyDynConseg* dpchinv);
	std::string getSquawkEqplist(DbsBrly* dbsbrly, DpchInvBrlyDynEqplist* dpchinv);
	std::string getSquawkFltfltloc(DbsBrly* dbsbrly, DpchInvBrlyDynFltfltloc* dpchinv);
	std::string getSquawkFltseg(DbsBrly* dbsbrly, DpchInvBrlyDynFltseg* dpchinv);
	std::string getSquawkRly(DbsBrly* dbsbrly, DpchInvBrlyDynRly* dpchinv);
	std::string getSquawkSeglocseg(DbsBrly* dbsbrly, DpchInvBrlyDynSeglocseg* dpchinv);
};

#endif
