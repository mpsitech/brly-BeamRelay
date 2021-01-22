/**
	* \file PnlBrlyRegRec_evals.cpp
	* job handler for job PnlBrlyRegRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyRegRec::evalPnl1nlocationAvail(
			DbsBrly* dbsbrly
		) {
	// reg.inSbs(rip)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetReg & VecBrlyWMRegionSubset::SBSBRLYBMREGIONRIP) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refReg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFREG, jref) != 0);
	args.push_back(a);

	return(args.back());
};
