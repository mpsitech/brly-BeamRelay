/**
	* \file PnlBrlyLocDetail_evals.cpp
	* job handler for job PnlBrlyLocDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyLocDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxtSrfActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfIcaActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfTitActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalPupTypActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxtRegActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfAltActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfTheActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfPhiActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfTzActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxfAphActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalChkCdnActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpNewAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)&loc.eqpEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpDeleteAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)&!loc.eqpEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxtEqpOprAvail(
			DbsBrly* dbsbrly
		) {
	// !loc.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxtEqpOprActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpOprViewAvail(
			DbsBrly* dbsbrly
		) {
	// eqp.oprEq(0)|(pre.ixCrdaccOpr())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEqp.refBrlyMOperator == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpOprViewActive(
			DbsBrly* dbsbrly
		) {
	// !eqp.oprEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEqp.refBrlyMOperator == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxtEqpPtyAvail(
			DbsBrly* dbsbrly
		) {
	// !loc.eqpEq(0)&eqp.inSbs(pln)

	vector<bool> args;
	bool a, b;

	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = ((ixWSubsetEqp & VecBrlyWMEquipmentSubset::SBSBRLYBMEQUIPMENTPLN) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyLocDetail::evalTxtEqpPtyActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpPtyViewAvail(
			DbsBrly* dbsbrly
		) {
	// eqp.ptyEq(0)|(pre.ixCrdaccPty())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEqp.refBrlyMPlntype == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpPtyViewActive(
			DbsBrly* dbsbrly
		) {
	// !eqp.ptyEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEqp.refBrlyMPlntype == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalPupEqpEtyAvail(
			DbsBrly* dbsbrly
		) {
	// !loc.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalPupEqpEtyActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalButEqpEtyEditAvail(
			DbsBrly* dbsbrly
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalChkEqpFibAvail(
			DbsBrly* dbsbrly
		) {
	// !loc.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recLoc.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyLocDetail::evalChkEqpFibActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
