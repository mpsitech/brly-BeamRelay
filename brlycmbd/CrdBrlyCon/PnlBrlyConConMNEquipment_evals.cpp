/**
	* \file PnlBrlyConConMNEquipment_evals.cpp
	* job handler for job PnlBrlyConConMNEquipment (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlBrlyConConMNEquipment::evalButUpAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConConMNEquipment::evalButUpActive(
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

bool PnlBrlyConConMNEquipment::evalButDownAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConConMNEquipment::evalButDownActive(
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

bool PnlBrlyConConMNEquipment::evalButViewAvail(
			DbsBrly* dbsbrly
		) {
	// !sel()|((pre.ixCrdaccLoc())|(pre.ixCrdaccFlt()))

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlBrlyConConMNEquipment::evalButViewActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConConMNEquipment::evalButAddAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConConMNEquipment::evalButSubAvail(
			DbsBrly* dbsbrly
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref) & VecBrlyWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlBrlyConConMNEquipment::evalButSubActive(
			DbsBrly* dbsbrly
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
