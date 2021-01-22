/**
	* \file CrdBrlyNav_evals.cpp
	* job handler for job CrdBrlyNav (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdBrlyNav::evalPnladminAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsg()|pre.ixCrdaccUsr()|pre.ixCrdaccPrs()|pre.ixCrdaccFil()|pre.ixCrdaccOpr()|pre.ixCrdaccPty()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPRS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref) != 0);
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

bool CrdBrlyNav::evalPnlbaseAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccReg()|pre.ixCrdaccLoc()|pre.ixCrdaccLeg()|pre.ixCrdaccTtb()|pre.ixCrdaccFlt()|pre.ixCrdaccSeg()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCTTB, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) != 0);
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

bool CrdBrlyNav::evalPnlconnectAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccCon()|pre.ixCrdaccRly()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCRLY, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdBrlyNav::evalMitSesSpsAvail(
			DbsBrly* dbsbrly
		) {
	// stgbrlyappearance.suspsessEq(true)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->stgbrlyappearance.suspsess == true);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMspCrd1Avail(
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

bool CrdBrlyNav::evalMitCrdUsgAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdUsrAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdPrsAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdFilAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdOprAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccOpr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdPtyAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMspCrd2Avail(
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

bool CrdBrlyNav::evalMitCrdRegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccReg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdLocAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLoc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdLegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdTtbAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccTtb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCTTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdFltAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFlt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdSegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMspCrd3Avail(
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

bool CrdBrlyNav::evalMitCrdConAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitCrdRlyAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccRly()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCRLY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMspApp2Avail(
			DbsBrly* dbsbrly
		) {
	// MitAppLoiAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitAppLoiAvail(dbsbrly);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyNav::evalMitAppLoiAvail(
			DbsBrly* dbsbrly
		) {
	// virgin()

	vector<bool> args;
	bool a;

	a = false; {uint cnt = 0; dbsbrly->loadUintBySQL("SELECT COUNT(ref) FROM TblBrlyMUser WHERE sref <> 'temp'", cnt); a = (cnt == 0);};
	args.push_back(a);

	return(args.back());
};
