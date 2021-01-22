/**
	* \file BrlyMapgenLegmap.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMAPGENLEGMAP_H
#define BRLYMAPGENLEGMAP_H

#include "BrlyMapgen.h"

// IP include.cust --- INSERT

namespace BrlyMapgenLegmap {

	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyMapgenLegmap* dpchinv);
	// IP cust --- IBEGIN

	void radToCoo(const double phi, const double theta, const double pixphi, const double pixtheta, const Sbecore::uint height, const Sbecore::uint width, const int xoffset, const int yoffset, double* x, double* y);
	void legToSphr(const double legphi, const double legtheta, const double* legrmat, double* phi, double* theta);
	void qlegphiToLeg(const double qlegphi, const double* qlegrmat, double* legphi, double* legtheta);
	void qlegToRad(BrlyQLegMapLeg* qleg);
	void qlegToDeg(BrlyQLegMapLeg* qleg);
	void qlocToRad(BrlyQLegMapLocation* qloc);
	void qlocToDeg(BrlyQLegMapLocation* qloc);
	// IP cust --- IEND
};

#endif
