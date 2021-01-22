/**
	* \file PnlBrlyNavBase_evals.cpp
	* job handler for job PnlBrlyNavBase (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyNavBase::evalLstRegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccReg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButRegViewActive(
			DbsBrly* dbsbrly
		) {
	// LstReg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstReg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalLstLocAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLoc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButLocViewActive(
			DbsBrly* dbsbrly
		) {
	// LstLoc.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstLoc != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalLstLegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButLegViewActive(
			DbsBrly* dbsbrly
		) {
	// LstLeg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstLeg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalLstTtbAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccTtb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCTTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButTtbViewActive(
			DbsBrly* dbsbrly
		) {
	// LstTtb.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstTtb != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalLstFltAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFlt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButFltViewActive(
			DbsBrly* dbsbrly
		) {
	// LstFlt.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFlt != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalLstSegAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyNavBase::evalButSegViewActive(
			DbsBrly* dbsbrly
		) {
	// LstSeg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSeg != 0);
	args.push_back(a);

	return(args.back());
};
