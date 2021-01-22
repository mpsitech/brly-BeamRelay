/**
	* \file PnlBrlyRegDetail_evals.cpp
	* job handler for job PnlBrlyRegDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyRegDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalTxtSrfActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalPupJtiActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalButJtiEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalTxtTitActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalTxtSupActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalButSupViewAvail(
			DbsBrly* dbsbrly
		) {
	// reg.supEq(0)|(pre.ixCrdaccReg())

	vector<bool> args;
	bool a, b;

	a = false; a = (recReg.supRefBrlyMRegion == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyRegDetail::evalButSupViewActive(
			DbsBrly* dbsbrly
		) {
	// !reg.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recReg.supRefBrlyMRegion == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalPupJActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalButJEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalPupDstActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyRegDetail::evalTxtTofActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
