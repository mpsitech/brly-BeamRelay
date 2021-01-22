/**
	* \file BrlyBaseLocloc.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYBASELOCLOC_H
#define BRLYBASELOCLOC_H

#include "BrlyBase.h"

// IP include.cust --- INSERT

namespace BrlyBaseLocloc {

	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyBaseLocloc* dpchinv);
	// IP cust --- IBEGIN

	void calcVis(DbsBrly* dbsbrly, const ListBrlyMLocation& dstlocs, const std::vector<bool>& selDstlocs, const ListBrlyMLocation& orglocs);
	void calcProx(DbsBrly* dbsbrly, const ListBrlyMLocation& dstlocs, const std::vector<bool>& selDstlocs, const ListBrlyMLocation& orglocs, const double earthradius);
	// IP cust --- IEND
};

#endif
