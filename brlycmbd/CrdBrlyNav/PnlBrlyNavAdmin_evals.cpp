/**
	* \file PnlBrlyNavAdmin_evals.cpp
	* job handler for job PnlBrlyNavAdmin (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyNavAdmin::evalLstUsgAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButUsgViewActive(
			DbsBrly* dbsbrly
		) {
	// LstUsg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalLstUsrAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButUsrViewActive(
			DbsBrly* dbsbrly
		) {
	// LstUsr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalLstPrsAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButPrsViewActive(
			DbsBrly* dbsbrly
		) {
	// LstPrs.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrs != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalLstFilAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButFilViewActive(
			DbsBrly* dbsbrly
		) {
	// LstFil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFil != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalLstOprAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccOpr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButOprViewActive(
			DbsBrly* dbsbrly
		) {
	// LstOpr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstOpr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalLstPtyAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccPty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavAdmin::evalButPtyViewActive(
			DbsBrly* dbsbrly
		) {
	// LstPty.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPty != 0);
	args.push_back(a);

	return(args.back());
};
