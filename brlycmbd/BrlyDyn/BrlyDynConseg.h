/**
	* \file BrlyDynConseg.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDYNCONSEG_H
#define BRLYDYNCONSEG_H

#include "BrlyDyn.h"

// IP include.cust --- INSERT

namespace BrlyDynConseg {

	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynConseg* dpchinv);
	// IP cust --- INSERT
};

#endif
