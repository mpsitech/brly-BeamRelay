/**
	* \file BrlyDynFltfltloc.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDYNFLTFLTLOC_H
#define BRLYDYNFLTFLTLOC_H

#include "BrlyDyn.h"

// IP include.cust --- INSERT

namespace BrlyDynFltfltloc {

	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynFltfltloc* dpchinv);
	// IP cust --- IBEGIN

	inline double visFltflt(const double t, const double* legrmat1, const double omega1, const Sbecore::uint t01, const double* legrmat2, const double omega2, const Sbecore::uint t02, const double cosa0);
	inline double visdrvFltflt(const double t, const double* legrmat1, const double omega1, const Sbecore::uint t01, const double* legrmat2, const double omega2, const Sbecore::uint t02, const double cosa0);
	bool viszeroFltflt(const double* legrmat1, const double omega1, const Sbecore::uint t01, const double* legrmat2, const double omega2, const Sbecore::uint t02, const double cosa0, const double t0, const double t1, const double tini, const double tol, unsigned int* t);
	// IP cust --- IEND
};

#endif
