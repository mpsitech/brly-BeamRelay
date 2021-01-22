/**
	* \file PnlBrlyLocEqpMNConnection_evals.cpp
	* job handler for job PnlBrlyLocEqpMNConnection (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyLocEqpMNConnection::evalButViewAvail(
			DbsBrly* dbsbrly
		) {
	// !sel()|(pre.ixCrdaccCon())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyLocEqpMNConnection::evalButViewActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocEqpMNConnection::evalButAddAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocEqpMNConnection::evalButSubAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccLocIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyLocEqpMNConnection::evalButSubActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
