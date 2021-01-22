/**
	* \file PnlBrlySegRec_evals.cpp
	* job handler for job PnlBrlySegRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlySegRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refSeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};
