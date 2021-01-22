/**
	* \file PnlBrlyRegADstswitch_evals.cpp
	* job handler for job PnlBrlyRegADstswitch (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyRegADstswitch::evalButNewAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegADstswitch::evalButDuplicateAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegADstswitch::evalButDuplicateActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegADstswitch::evalButDeleteAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegADstswitch::evalButDeleteActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
