/**
	* \file PnlBrlyRlyRec.cpp
	* job handler for job PnlBrlyRlyRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "PnlBrlyRlyRec.h"

#include "PnlBrlyRlyRec_blks.cpp"
#include "PnlBrlyRlyRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlBrlyRlyRec
 ******************************************************************************/

PnlBrlyRlyRec::PnlBrlyRlyRec(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::PNLBRLYRLYREC, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	pnl1nnode = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYRLY_CONEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFRLY, jref);
};

PnlBrlyRlyRec::~PnlBrlyRlyRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngBrly* PnlBrlyRlyRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyRlyRec::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubBrly::getStubRlyStd(dbsbrly, recRly.ref, ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recRly.ref == 0) statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsbrly);

	if (statshr.ixBrlyVExpstate == VecBrlyVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1nnode) {delete pnl1nnode; pnl1nnode = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlBrlyRlyDetail(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnl1nnode) pnl1nnode = new PnlBrlyRly1NNode(xchg, dbsbrly, jref, ixBrlyVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NNode = ((pnl1nnode) ? pnl1nnode->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlBrlyRlyRec::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFRLY) {
		BrlyMRelay* _recRly = NULL;

		if (dbsbrly->tblbrlymrelay->loadRecByRef(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFRLY, jref), &_recRly)) {
			recRly = *_recRly;
			delete _recRly;
		} else recRly = BrlyMRelay();

		if (recRly.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnl1nnode) pnl1nnode->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
		};

		refresh(dbsbrly, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyRlyRec::minimize(
			DbsBrly* dbsbrly
			, const bool notif
			, DpchEngBrly** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixBrlyVExpstate != VecBrlyVExpstate::MIND) {
		statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsbrly, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlBrlyRlyRec::regularize(
			DbsBrly* dbsbrly
			, const bool notif
			, DpchEngBrly** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixBrlyVExpstate != VecBrlyVExpstate::REGD) {
		statshr.ixBrlyVExpstate = VecBrlyVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsbrly, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlBrlyRlyRec::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYINIT) {
			handleDpchAppBrlyInit(dbsbrly, (DpchAppBrlyInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLYRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlBrlyRlyRec::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyRlyRec::handleDpchAppDoButMinimizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	minimize(dbsbrly, true, dpcheng);
};

void PnlBrlyRlyRec::handleDpchAppDoButRegularizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	regularize(dbsbrly, true, dpcheng);
};

void PnlBrlyRlyRec::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYRLYUPD_REFEQ) {
		call->abort = handleCallBrlyRlyUpd_refEq(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYRLY_CONEQ) {
		call->abort = handleCallBrlyRly_conEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlBrlyRlyRec::handleCallBrlyRlyUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlyRlyUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyRlyRec::handleCallBrlyRly_conEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRly.refBrlyMConnection == refInv); // IP handleCallBrlyRly_conEq --- LINE
	return retval;
};
