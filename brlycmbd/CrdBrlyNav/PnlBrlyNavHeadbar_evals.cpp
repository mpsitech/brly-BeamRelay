/**
	* \file PnlBrlyNavHeadbar_evals.cpp
	* job handler for job PnlBrlyNavHeadbar (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyNavHeadbar::evalMenCrdAvail(
			DbsBrly* dbsbrly
		) {
	// MspCrd1Avail()|MspCrd2Avail()|MspCrd3Avail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMspCrd1Avail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMspCrd2Avail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMspCrd3Avail(dbsbrly);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMspCrd1Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdUsgAvail()|MitCrdUsrAvail()|MitCrdPrsAvail()|MitCrdFilAvail()|MitCrdOprAvail()|MitCrdPtyAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdUsgAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdUsrAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdPrsAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdFilAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdOprAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdPtyAvail(dbsbrly);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdUsgAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdUsrAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdPrsAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdFilAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdOprAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccOpr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdPtyAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMspCrd2Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdRegAvail()|MitCrdLocAvail()|MitCrdLegAvail()|MitCrdTtbAvail()|MitCrdFltAvail()|MitCrdSegAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdRegAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdLocAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdLegAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdTtbAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdFltAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdSegAvail(dbsbrly);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdRegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccReg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdLocAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLoc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdLegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdTtbAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccTtb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCTTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdFltAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFlt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdSegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMspCrd3Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdConAvail()|MitCrdRlyAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdConAvail(dbsbrly);
	args.push_back(a);
	a = false; a = evalMitCrdRlyAvail(dbsbrly);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdConAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavHeadbar::evalMitCrdRlyAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRly()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCRLY, jref) != 0);
	args.push_back(a);

	return(args.back());
};
