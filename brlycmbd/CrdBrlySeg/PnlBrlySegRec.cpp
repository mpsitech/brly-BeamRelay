/**
	* \file PnlBrlySegRec.cpp
	* job handler for job PnlBrlySegRec (implementation)
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

#include "PnlBrlySegRec.h"

#include "PnlBrlySegRec_blks.cpp"
#include "PnlBrlySegRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlBrlySegRec
 ******************************************************************************/

PnlBrlySegRec::PnlBrlySegRec(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::PNLBRLYSEGREC, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	pnlmnconnection = NULL;
	pnlmnlocation = NULL;
	pnlorgmnsegment = NULL;
	pnldetail = NULL;
	pnlpre = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYSEG_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSEG_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFSEG, jref);
};

PnlBrlySegRec::~PnlBrlySegRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngBrly* PnlBrlySegRec::getNewDpchEng(
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

void PnlBrlySegRec::refresh(
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
	continf.TxtRef = StubBrly::getStubSegStd(dbsbrly, recSeg.ref, ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recSeg.ref == 0) statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsbrly);

	if (statshr.ixBrlyVExpstate == VecBrlyVExpstate::MIND) {
		if (pnlpre) {delete pnlpre; pnlpre = NULL;};
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlorgmnsegment) {delete pnlorgmnsegment; pnlorgmnsegment = NULL;};
		if (pnlmnlocation) {delete pnlmnlocation; pnlmnlocation = NULL;};
		if (pnlmnconnection) {delete pnlmnconnection; pnlmnconnection = NULL;};
	} else {
		if (!pnlpre) pnlpre = new PnlBrlySegPre(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnldetail) pnldetail = new PnlBrlySegDetail(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlorgmnsegment) pnlorgmnsegment = new PnlBrlySegOrgMNSegment(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmnlocation) pnlmnlocation = new PnlBrlySegMNLocation(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmnconnection) pnlmnconnection = new PnlBrlySegMNConnection(xchg, dbsbrly, jref, ixBrlyVLocale);
	};

	statshr.jrefPre = ((pnlpre) ? pnlpre->jref : 0);
	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefOrgMNSegment = ((pnlorgmnsegment) ? pnlorgmnsegment->jref : 0);
	statshr.jrefMNLocation = ((pnlmnlocation) ? pnlmnlocation->jref : 0);
	statshr.jrefMNConnection = ((pnlmnconnection) ? pnlmnconnection->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlBrlySegRec::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFSEG) {
		BrlyMSegment* _recSeg = NULL;

		if (dbsbrly->tblbrlymsegment->loadRecByRef(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEG, jref), &_recSeg)) {
			recSeg = *_recSeg;
			delete _recSeg;
		} else recSeg = BrlyMSegment();

		if (recSeg.ref != 0) {
			if (pnlpre) pnlpre->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnldetail) pnldetail->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlorgmnsegment) pnlorgmnsegment->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmnlocation) pnlmnlocation->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmnconnection) pnlmnconnection->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
		};

		refresh(dbsbrly, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlySegRec::minimize(
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

void PnlBrlySegRec::regularize(
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

void PnlBrlySegRec::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGRECDO) {
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

void PnlBrlySegRec::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlySegRec::handleDpchAppDoButMinimizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	minimize(dbsbrly, true, dpcheng);
};

void PnlBrlySegRec::handleDpchAppDoButRegularizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	regularize(dbsbrly, true, dpcheng);
};

void PnlBrlySegRec::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSEGUPD_REFEQ) {
		call->abort = handleCallBrlySegUpd_refEq(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSEG_REUEQ) {
		call->abort = handleCallBrlySeg_reuEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSEG_RETEQ) {
		call->abort = handleCallBrlySeg_retEq(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlBrlySegRec::handleCallBrlySegUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlySegUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlySegRec::handleCallBrlySeg_reuEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSeg.refUref == refInv); // IP handleCallBrlySeg_reuEq --- LINE
	return retval;
};

bool PnlBrlySegRec::handleCallBrlySeg_retEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSeg.refIxVTbl == ixInv); // IP handleCallBrlySeg_retEq --- LINE
	return retval;
};
