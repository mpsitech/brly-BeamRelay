/**
	* \file PnlBrlySegOrgMNSegment_evals.cpp
	* job handler for job PnlBrlySegOrgMNSegment (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlySegOrgMNSegment::evalButViewAvail(
			DbsBrly* dbsbrly
		) {
	// !sel()|(pre.ixCrdaccSeg())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlySegOrgMNSegment::evalButViewActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegOrgMNSegment::evalButAddAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegOrgMNSegment::evalButSubAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlySegOrgMNSegment::evalButSubActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
