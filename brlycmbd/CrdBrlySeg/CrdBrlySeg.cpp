/**
	* \file CrdBrlySeg.cpp
	* job handler for job CrdBrlySeg (implementation)
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

#include "CrdBrlySeg.h"

#include "CrdBrlySeg_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdBrlySeg
 ******************************************************************************/

CrdBrlySeg::CrdBrlySeg(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
			, const ubigint ref
		) :
			JobBrly(xchg, VecBrlyVJob::CRDBRLYSEG, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	pnlrec = NULL;

	// IP constructor.cust1 --- INSERT

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbsbrly, VecBrlyVCall::CALLBRLYREFPRESET, jref, VecBrlyVPreset::PREBRLYREFSEG, ref);

	// initialize according to ref
	changeRef(dbsbrly, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlBrlySegList(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnlheadbar = new PnlBrlySegHeadbar(xchg, dbsbrly, jref, ixBrlyVLocale);
	pnlrec = new PnlBrlySegRec(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	changeStage(dbsbrly, VecVSge::IDLE);

	xchg->addClstn(VecBrlyVCall::CALLBRLYREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdBrlySeg::~CrdBrlySeg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngBrly* CrdBrlySeg::getNewDpchEng(
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

void CrdBrlySeg::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdBrlySeg/" + VecBrlyVLocale::getSref(ixBrlyVLocale);
	continf.MtxCrdSeg = StubBrly::getStubSegStd(dbsbrly, xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEG, jref), ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void CrdBrlySeg::changeRef(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbsbrly, VecBrlyVCall::CALLBRLYLOG, jref, VecBrlyVPreset::VOID, 0, "CrdBrlySeg", ref);
	xchg->addRefPreset(VecBrlyVPreset::PREBRLYREFSEG, jref, ref);

	if (pnllist) pnllist->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFSEG, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFSEG, jrefTrig, notif);

	refresh(dbsbrly, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdBrlySeg::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdBrlySeg::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGDO) {
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

void CrdBrlySeg::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdBrlySeg::handleDpchAppDoClose(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	xchg->triggerIxCall(dbsbrly, VecBrlyVCall::CALLBRLYCRDCLOSE, jref, VecBrlyVCard::CRDBRLYSEG);
};

void CrdBrlySeg::handleDpchAppDoMitAppAbtClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsbrly, VecVSge::ALRBRLYABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdBrlySeg::handleDpchAppBrlyAlert(
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

void CrdBrlySeg::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYREFPRESET) {
		call->abort = handleCallBrlyRefPreSet(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSTATCHG) {
		call->abort = handleCallBrlyStatChg(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYDLGCLOSE) {
		call->abort = handleCallBrlyDlgClose(dbsbrly, call->jref);
	};
};

bool CrdBrlySeg::handleCallBrlyRefPreSet(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecBrlyVPreset::PREBRLYREFSEG) {
		changeRef(dbsbrly, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbsbrly, true);
	};

	return retval;
};

bool CrdBrlySeg::handleCallBrlyStatChg(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD) && (pnlrec->statshr.ixBrlyVExpstate == VecBrlyVExpstate::REGD)) pnllist->minimize(dbsbrly, true);
	return retval;
};

bool CrdBrlySeg::handleCallBrlyDlgClose(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlyDlgClose --- INSERT
	return retval;
};

void CrdBrlySeg::changeStage(
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

string CrdBrlySeg::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdBrlySeg::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdBrlySeg::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdBrlySeg::enterSgeAlrbrlyabt(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::ALRBRLYABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrBrly::prepareAlrAbt(jref, ixBrlyVLocale, feedFMcbAlert)); // IP enterSgeAlrbrlyabt --- LINE

	return retval;
};

void CrdBrlySeg::leaveSgeAlrbrlyabt(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeAlrbrlyabt --- INSERT
};
