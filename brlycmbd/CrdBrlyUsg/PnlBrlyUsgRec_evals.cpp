/**
	* \file PnlBrlyUsgRec_evals.cpp
	* job handler for job PnlBrlyUsgRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyUsgRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};
