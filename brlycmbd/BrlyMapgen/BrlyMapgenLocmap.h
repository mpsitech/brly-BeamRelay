/**
	* \file BrlyMapgenLocmap.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMAPGENLOCMAP_H
#define BRLYMAPGENLOCMAP_H

#include "BrlyMapgen.h"

// IP include.cust --- INSERT

namespace BrlyMapgenLocmap {

	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyMapgenLocmap* dpchinv);
	// IP cust --- IBEGIN

	void radToCoo(const double phi, const double theta, const double locphi, const double loctheta, const double pixphi, const double pixtheta, const Sbecore::uint height, const Sbecore::uint width, const int xoffset, const int yoffset, double* x, double* y);
	void legphiToSphr(const double legphi, const double* legrmat, double* phi, double* theta);
	void qlegToRad(BrlyQLocMapLeg* qleg);
	void qlegToDeg(BrlyQLocMapLeg* qleg);
	void qplocToRad(BrlyQLocMapProxLocation* qploc);
	void qplocToDeg(BrlyQLocMapProxLocation* qploc);
	void qvlocToRad(BrlyQLocMapVisLocation* qvloc);
	void qvlocToDeg(BrlyQLocMapVisLocation* qvloc);
	// IP cust --- IEND
};

#endif
