/**
	* \file PnlBrlyFltRec_evals.cpp
	* job handler for job PnlBrlyFltRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyFltRec::evalPnlfafawaypointAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.fafEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMFaflight == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltRec::evalPnleqp1nnodeAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltRec::evalPnleqpmnconnectionAvail(
			DbsBrly* dbsbrly
		) {
	// !flt.eqpEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFlt.refBrlyMEquipment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlBrlyFltRec::evalButRegularizeActive(
			DbsBrly* dbsbrly
		) {
	// pre.refFlt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFFLT, jref) != 0);
	args.push_back(a);

	return(args.back());
};
