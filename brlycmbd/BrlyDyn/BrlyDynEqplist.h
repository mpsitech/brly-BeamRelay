/**
	* \file BrlyDynEqplist.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDYNEQPLIST_H
#define BRLYDYNEQPLIST_H

#include "BrlyDyn.h"

// IP include.cust --- INSERT

namespace BrlyDynEqplist {

	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynEqplist* dpchinv);
	// IP cust --- IBEGIN

	double evalCorrphi(const double phi, const double* rtrmat);
	inline double evalFltlocSwap(const double phi1, const double* rtrmat1, const double phi2);
	inline double evalFltfltSwap(const double phi1, const double* rtrmat1, const double phi2, const double* rtrmat2);
	// IP cust --- IEND
};

#endif
