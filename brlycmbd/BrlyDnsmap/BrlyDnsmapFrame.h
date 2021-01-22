/**
	* \file BrlyDnsmapFrame.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDNSMAPFRAME_H
#define BRLYDNSMAPFRAME_H

#include "BrlyDnsmap.h"

// IP include.cust --- INSERT

namespace BrlyDnsmapFrame {

	DpchRetBrlyDnsmapFrame* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDnsmapFrame* dpchinv);
	// IP cust --- INSERT
};

#endif
