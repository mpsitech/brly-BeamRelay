/**
	* \file PnlBrlyFilDetail_evals.cpp
	* job handler for job PnlBrlyFilDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyFilDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalTxfFnmActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalLstCluActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalButCluViewActive(
			DbsBrly* dbsbrly
		) {
	// LstClu.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClu != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalButCluClusterAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)&fil.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recFil.refBrlyCFile == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyFilDetail::evalButCluUnclusterAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)&!fil.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recFil.refBrlyCFile == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyFilDetail::evalTxtReuActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalButReuViewAvail(
			DbsBrly* dbsbrly
		) {
	// fil.reuEq(0)|(pre.ixCrdaccTtb()&fil.retEq(ttb))

	vector<bool> args;
	bool a, b;

	a = false; a = (recFil.refUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCTTB, jref) != 0);
	args.push_back(a);
	a = false; a = (recFil.refIxVTbl == VecBrlyVMFileRefTbl::TTB);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyFilDetail::evalButReuViewActive(
			DbsBrly* dbsbrly
		) {
	// !fil.reuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFil.refUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalPupCntActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalButCntEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalTxfAcvActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalTxfAnmActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalPupMimActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalButMimEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalTxfSizActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFilDetail::evalTxfCmtActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
