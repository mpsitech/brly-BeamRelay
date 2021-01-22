/**
	* \file BrlyDynFltseg.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDYNFLTSEG_H
#define BRLYDYNFLTSEG_H

#include "BrlyDyn.h"

// IP include.cust --- INSERT

namespace BrlyDynFltseg {

	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynFltseg* dpchinv);
	// IP cust --- IBEGIN

	void segmentFlight(DbsBrly* dbsbrly, BrlyMFlight* flt);
	double getDeltaphi(const double theta0, const double phi0, const double theta1, const double phi1);
	void segToDeg(BrlyMSegment* seg);
	void wpToRad(BrlyAMFaflightWaypoint* wp);
	// IP cust --- IEND
};

#endif
