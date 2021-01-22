/**
	* \file SqkBrlyBase.h
	* squawk generation for operation pack BrlyBase (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef SQKBRLYBASE_H
#define SQKBRLYBASE_H

#include "BrlyBase_blks.h"

/**
	* SqkBrlyBase
	*/
namespace SqkBrlyBase {
	std::string getSquawkLegleg(DbsBrly* dbsbrly, DpchInvBrlyBaseLegleg* dpchinv);
	std::string getSquawkLegloc(DbsBrly* dbsbrly, DpchInvBrlyBaseLegloc* dpchinv);
	std::string getSquawkLocloc(DbsBrly* dbsbrly, DpchInvBrlyBaseLocloc* dpchinv);
};

#endif
