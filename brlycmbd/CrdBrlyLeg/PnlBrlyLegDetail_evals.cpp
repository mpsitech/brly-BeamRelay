/**
	* \file PnlBrlyLegDetail_evals.cpp
	* job handler for job PnlBrlyLegDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyLegDetail::evalButSaveAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalButSaveActive(
			DbsBrly* dbsbrly
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalTxtBloActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalTxtEloActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalPupTypActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalLstCluActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalButCluViewActive(
			DbsBrly* dbsbrly
		) {
	// LstClu.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClu != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalButCluClusterAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)&leg.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recLeg.refBrlyCLeg == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyLegDetail::evalButCluUnclusterAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)&!leg.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recLeg.refBrlyCLeg == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyLegDetail::evalTxfAltActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalTxfDphActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalTxfAphActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalTxfXalActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalTxfXp0Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalTxfXp1Active(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalTxfXapActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLegDetail::evalChkCdnActive(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
