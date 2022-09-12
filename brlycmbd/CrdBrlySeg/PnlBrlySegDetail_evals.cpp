/**
	* \file PnlBrlySegDetail_evals.cpp
	* job handler for job PnlBrlySegDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlySegDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxtReuActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalButReuViewAvail(
			DbsBrly* dbsbrly
		) {
	// seg.reuEq(0)|((pre.ixCrdaccFlt()&seg.retEq(flt))|(pre.ixCrdaccCon()&seg.retEq(con)))

	vector<bool> args;
	bool a, b;

	a = false; a = (recSeg.refUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) != 0);
	args.push_back(a);
	a = false; a = (recSeg.refIxVTbl == VecBrlyVMSegmentRefTbl::FLT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) != 0);
	args.push_back(a);
	a = false; a = (recSeg.refIxVTbl == VecBrlyVMSegmentRefTbl::CON);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlySegDetail::evalButReuViewActive(
			DbsBrly* dbsbrly
		) {
	// !seg.reuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSeg.refUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfDphActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfAl0Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfAl1Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfTh0Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfTh1Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfPh0Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfPh1Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfStaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalTxfStoActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegDetail::evalChkCdnActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
