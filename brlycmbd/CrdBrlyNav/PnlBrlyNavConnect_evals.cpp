/**
	* \file PnlBrlyNavConnect_evals.cpp
	* job handler for job PnlBrlyNavConnect (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyNavConnect::evalLstConAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavConnect::evalButConViewActive(
			DbsBrly* dbsbrly
		) {
	// LstCon.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCon != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavConnect::evalLstRlyAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRly()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCRLY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavConnect::evalButRlyViewActive(
			DbsBrly* dbsbrly
		) {
	// LstRly.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstRly != 0);
	args.push_back(a);

	return(args.back());
};
