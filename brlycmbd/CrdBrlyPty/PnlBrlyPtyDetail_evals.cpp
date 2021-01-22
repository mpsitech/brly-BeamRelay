/**
	* \file PnlBrlyPtyDetail_evals.cpp
	* job handler for job PnlBrlyPtyDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyPtyDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPtyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPtyDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPtyDetail::evalTxtSrfActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPtyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPtyDetail::evalTxfTitActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPtyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPtyDetail::evalPupEtyActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPtyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPtyDetail::evalButEtyEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyPtyDetail::evalTxfCapActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPtyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
