/**
	* \file PnlBrlyConRec_evals.cpp
	* job handler for job PnlBrlyConRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyConRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};
