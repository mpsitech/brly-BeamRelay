/**
	* \file BrlyDynConflt.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDYNCONFLT_H
#define BRLYDYNCONFLT_H

#include "BrlyDyn.h"

// IP include.cust --- INSERT

namespace BrlyDynConflt {

	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynConflt* dpchinv);
	// IP cust --- INSERT
};

#endif
