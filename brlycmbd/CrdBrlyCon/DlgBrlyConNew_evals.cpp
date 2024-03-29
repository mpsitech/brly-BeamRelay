/**
	* \file DlgBrlyConNew_evals.cpp
	* job handler for job DlgBrlyConNew (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgBrlyConNew::evalCalButRunActive(
			DbsBrly* dbsbrly
		) {
	// sge(credone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::CREDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgBrlyConNew::evalCalButStoActive(
			DbsBrly* dbsbrly
		) {
	// sge(calc1|calc2|calc3|calc4)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::CALC1);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::CALC2);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::CALC3);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::CALC4);
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

	return(args.back());
};

bool DlgBrlyConNew::evalButDneActive(
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

bool DlgBrlyConNew::evalDetButCreActive(
			DbsBrly* dbsbrly
		) {
	// sge(idle)&valid()

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = valid;
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};
