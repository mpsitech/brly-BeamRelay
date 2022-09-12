/**
	* \file CrdBrlyRly.cpp
	* job handler for job CrdBrlyRly (implementation)
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

#include "CrdBrlyRly.h"

#include "CrdBrlyRly_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdBrlyRly
 ******************************************************************************/

CrdBrlyRly::CrdBrlyRly(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
			, const ubigint ref
		) :
			JobBrly(xchg, VecBrlyVJob::CRDBRLYRLY, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	pnlrec = NULL;

	// IP constructor.cust1 --- INSERT

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbsbrly, VecBrlyVCall::CALLBRLYREFPRESET, jref, VecBrlyVPreset::PREBRLYREFRLY, ref);

	// initialize according to ref
	changeRef(dbsbrly, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlBrlyRlyList(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnlheadbar = new PnlBrlyRlyHeadbar(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnlrec = new PnlBrlyRlyRec(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	changeStage(dbsbrly, VecVSge::IDLE);

	xchg->addClstn(VecBrlyVCall::CALLBRLYREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdBrlyRly::~CrdBrlyRly() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngBrly* CrdBrlyRly::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdBrlyRly::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdBrlyRly/" + VecBrlyVLocale::getSref(ixBrlyVLocale);
	continf.MtxCrdRly = StubBrly::getStubRlyStd(dbsbrly, xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFRLY, jref), ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void CrdBrlyRly::changeRef(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbsbrly, VecBrlyVCall::CALLBRLYLOG, jref, VecBrlyVPreset::VOID, 0, "CrdBrlyRly", ref);
	xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFRLY, jref, ref);

	if (pnllist) pnllist->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFRLY, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFRLY, jrefTrig, notif);

	refresh(dbsbrly, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdBrlyRly::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdBrlyRly::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLYDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsbrly, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYALERT) {
			handleDpchAppBrlyAlert(dbsbrly, (DpchAppBrlyAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdBrlyRly::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdBrlyRly::handleDpchAppDoClose(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	xchg->triggerIxCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDCLOSE, jref, VecBrlyVCard::CRDBRLYRLY);
};

void CrdBrlyRly::handleDpchAppDoMitAppAbtClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsbrly, VecVSge::ALRBRLYABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdBrlyRly::handleDpchAppBrlyAlert(
			DbsBrly* dbsbrly
			, DpchAppBrlyAlert* dpchappbrlyalert
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppBrlyAlert --- BEGIN
	if (ixVSge == VecVSge::ALRBRLYABT) {
		changeStage(dbsbrly, nextIxVSgeSuccess);
	};

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	// IP handleDpchAppBrlyAlert --- END
};

void CrdBrlyRly::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYREFPRESET) {
		call->abort = handleCallBrlyRefPreSet(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYDLGCLOSE) {
		call->abort = handleCallBrlyDlgClose(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSTATCHG) {
		call->abort = handleCallBrlyStatChg(dbsbrly, call->jref);
	};
};

bool CrdBrlyRly::handleCallBrlyRefPreSet(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecBrlyVPreset::PREBRLYREFRLY) {
		changeRef(dbsbrly, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbsbrly, true);
	};

	return retval;
};

bool CrdBrlyRly::handleCallBrlyDlgClose(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlyDlgClose --- INSERT
	return retval;
};

bool CrdBrlyRly::handleCallBrlyStatChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD) && (pnlrec->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD)) pnllist->minimize(dbsbrly, true);
	return retval;
};

void CrdBrlyRly::changeStage(
			DbsBrly* dbsbrly
			, uint _ixVSge
			, DpchEngBrly** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsbrly); break;
				case VecVSge::ALRBRLYABT: leaveSgeAlrbrlyabt(dbsbrly); break;
			};

			setStage(dbsbrly, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::ALRBRLYABT: _ixVSge = enterSgeAlrbrlyabt(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdBrlyRly::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdBrlyRly::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdBrlyRly::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdBrlyRly::enterSgeAlrbrlyabt(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::ALRBRLYABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrBrly::prepareAlrAbt(jref, ixBrlyVLocale, feedFMcbAlert)); // IP enterSgeAlrbrlyabt --- LINE

	return retval;
};

void CrdBrlyRly::leaveSgeAlrbrlyabt(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeAlrbrlyabt --- INSERT
};
