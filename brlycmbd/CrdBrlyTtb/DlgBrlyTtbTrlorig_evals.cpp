/**
	* \file DlgBrlyTtbTrlorig_evals.cpp
	* job handler for job DlgBrlyTtbTrlorig (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgBrlyTtbTrlorig::evalButDneActive(
			DbsBrly* dbsbrly
		) {
	// sge(idle|done)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgBrlyTtbTrlorig::evalTfiDldActive(
			DbsBrly* dbsbrly
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyTtbTrlorig::evalTrlButRunActive(
			DbsBrly* dbsbrly
		) {
	// sge(ulddone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::ULDDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyTtbTrlorig::evalTrlButStoActive(
			DbsBrly* dbsbrly
		) {
	// sge(translate)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::TRANSLATE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyTtbTrlorig::evalRfiUldActive(
			DbsBrly* dbsbrly
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};
