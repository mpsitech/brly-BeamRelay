/**
	* \file DlgBrlyTtbNew_evals.cpp
	* job handler for job DlgBrlyTtbNew (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgBrlyTtbNew::evalButCncActive(
			DbsBrly* dbsbrly
		) {
	// sge(!create)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::CREATE);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool DlgBrlyTtbNew::evalButCreActive(
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
