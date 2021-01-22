/**
	* \file PnlBrlyFltFafAWaypoint_evals.cpp
	* job handler for job PnlBrlyFltFafAWaypoint (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyFltFafAWaypoint::evalButUpAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltFafAWaypoint::evalButUpActive(
			DbsBrly* dbsbrly
		) {
	// sel()&!sel.first()

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = false; a = (qry->stgiac.jnum == 1);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyFltFafAWaypoint::evalButDownAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltFafAWaypoint::evalButDownActive(
			DbsBrly* dbsbrly
		) {
	// sel()&!sel.last()

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = false; a = (qry->stgiac.jnum == qry->statshr.ntot);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlBrlyFltFafAWaypoint::evalButNewAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltFafAWaypoint::evalButDuplicateAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltFafAWaypoint::evalButDuplicateActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltFafAWaypoint::evalButDeleteAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccFltIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyFltFafAWaypoint::evalButDeleteActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
