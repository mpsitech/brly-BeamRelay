/**
	* \file CrdBrlyCon_evals.cpp
	* job handler for job CrdBrlyCon (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdBrlyCon::evalMspCrd1Avail(
			DbsBrly* dbsbrly
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbsbrly);
	args.push_back(a);

	return(args.back());
};

bool CrdBrlyCon::evalMitCrdNewAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccConIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) & VecBrlyWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};
