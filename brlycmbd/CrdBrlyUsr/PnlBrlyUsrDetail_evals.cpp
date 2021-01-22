/**
	* \file PnlBrlyUsrDetail_evals.cpp
	* job handler for job PnlBrlyUsrDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyUsrDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalTxtPrsActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalButPrsViewAvail(
			DbsBrly* dbsbrly
		) {
	// usr.prsEq(0)|(pre.ixCrdaccPrs())

	vector<bool> args;
	bool a, b;

	a = false; a = (recUsr.refBrlyMPerson == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPRS, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalButPrsViewActive(
			DbsBrly* dbsbrly
		) {
	// !usr.prsEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recUsr.refBrlyMPerson == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalTxtSrfActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalTxtUsgActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalButUsgViewAvail(
			DbsBrly* dbsbrly
		) {
	// usr.usgEq(0)|(pre.ixCrdaccUsg())

	vector<bool> args;
	bool a, b;

	a = false; a = (recUsr.refBrlyMUsergroup == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSG, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalButUsgViewActive(
			DbsBrly* dbsbrly
		) {
	// !usr.usgEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recUsr.refBrlyMUsergroup == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalPupJstActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalButJstEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalPupSteActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalPupLclActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalPupUlvActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalTxfPwdActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalTxfFkyActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyUsrDetail::evalTxfCmtActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
