/**
	* \file PnlBrlyRlyRec_evals.cpp
	* job handler for job PnlBrlyRlyRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyRlyRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refRly()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFRLY, jref) != 0);
	args.push_back(a);

	return(args.back());
};
