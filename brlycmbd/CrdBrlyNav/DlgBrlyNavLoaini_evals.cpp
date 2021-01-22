/**
	* \file DlgBrlyNavLoaini_evals.cpp
	* job handler for job DlgBrlyNavLoaini (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgBrlyNavLoaini::evalButDneActive(
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

bool DlgBrlyNavLoaini::evalLfiDldActive(
			DbsBrly* dbsbrly
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyNavLoaini::evalPprButRunActive(
			DbsBrly* dbsbrly
		) {
	// sge(impdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IMPDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyNavLoaini::evalPprButStoActive(
			DbsBrly* dbsbrly
		) {
	// sge(postprc)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::POSTPRC);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyNavLoaini::evalImpButRunActive(
			DbsBrly* dbsbrly
		) {
	// sge(prsdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::PRSDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyNavLoaini::evalImpButStoActive(
			DbsBrly* dbsbrly
		) {
	// sge(impidle|import)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IMPIDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::IMPORT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgBrlyNavLoaini::evalIfiUldActive(
			DbsBrly* dbsbrly
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};
