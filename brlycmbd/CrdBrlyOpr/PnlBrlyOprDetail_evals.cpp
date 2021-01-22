/**
	* \file PnlBrlyOprDetail_evals.cpp
	* job handler for job PnlBrlyOprDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyOprDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccOprIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyOprDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyOprDetail::evalTxtSrfActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccOprIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyOprDetail::evalTxfIcaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccOprIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyOprDetail::evalTxfTitActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccOprIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
