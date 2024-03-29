/**
	* \file PnlBrlyLegRec.cpp
	* job handler for job PnlBrlyLegRec (implementation)
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

#include "PnlBrlyLegRec.h"

#include "PnlBrlyLegRec_blks.cpp"
#include "PnlBrlyLegRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlBrlyLegRec
 ******************************************************************************/

PnlBrlyLegRec::PnlBrlyLegRec(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::PNLBRLYLEGREC, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	pnlorgmnleg = NULL;
	pnlmnlocation = NULL;
	pnlcor1nconnection = NULL;
	pnl1nflight = NULL;
	pnlmap = NULL;
	pnldetail = NULL;
	pnlpre = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYLEG_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYLEG_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYLEG_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFLEG, jref);
};

PnlBrlyLegRec::~PnlBrlyLegRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngBrly* PnlBrlyLegRec::getNewDpchEng(
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

void PnlBrlyLegRec::refresh(
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
	continf.TxtRef = StubBrly::getStubLegStd(dbsbrly, recLeg.ref, ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recLeg.ref == 0) statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;

	statshr.pnl1nflightAvail = evalPnl1nflightAvail(dbsbrly);
	statshr.pnlcor1nconnectionAvail = evalPnlcor1nconnectionAvail(dbsbrly);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbsbrly);

	if (statshr.ixBrlyVExpstate == VecBrlyVExpstate::MIND) {
		if (pnlpre) {delete pnlpre; pnlpre = NULL;};
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlmap) {delete pnlmap; pnlmap = NULL;};
		if (pnl1nflight) {delete pnl1nflight; pnl1nflight = NULL;};
		if (pnlcor1nconnection) {delete pnlcor1nconnection; pnlcor1nconnection = NULL;};
		if (pnlmnlocation) {delete pnlmnlocation; pnlmnlocation = NULL;};
		if (pnlorgmnleg) {delete pnlorgmnleg; pnlorgmnleg = NULL;};
	} else {
		if (!pnlpre) pnlpre = new PnlBrlyLegPre(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnldetail) pnldetail = new PnlBrlyLegDetail(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmap) pnlmap = new PnlBrlyLegMap(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnl1nflight) pnl1nflight = new PnlBrlyLeg1NFlight(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlcor1nconnection) pnlcor1nconnection = new PnlBrlyLegCor1NConnection(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlmnlocation) pnlmnlocation = new PnlBrlyLegMNLocation(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlorgmnleg) pnlorgmnleg = new PnlBrlyLegOrgMNLeg(xchg, dbsbrly, jref, ixBrlyVLocale);
	};

	statshr.jrefPre = ((pnlpre) ? pnlpre->jref : 0);
	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefMap = ((pnlmap) ? pnlmap->jref : 0);
	statshr.jref1NFlight = ((pnl1nflight) ? pnl1nflight->jref : 0);
	statshr.jrefCor1NConnection = ((pnlcor1nconnection) ? pnlcor1nconnection->jref : 0);
	statshr.jrefMNLocation = ((pnlmnlocation) ? pnlmnlocation->jref : 0);
	statshr.jrefOrgMNLeg = ((pnlorgmnleg) ? pnlorgmnleg->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlBrlyLegRec::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFLEG) {
		BrlyMLeg* _recLeg = NULL;

		if (dbsbrly->tblbrlymleg->loadRecByRef(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLEG, jref), &_recLeg)) {
			recLeg = *_recLeg;
			ixWSubsetLeg = dbsbrly->getIxWSubsetByBrlyMLeg(_recLeg);
			delete _recLeg;
		} else {
			recLeg = BrlyMLeg();
			ixWSubsetLeg = 0;
		};

		if (recLeg.ref != 0) {
			if (pnlpre) pnlpre->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnldetail) pnldetail->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmap) pnlmap->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnl1nflight) pnl1nflight->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlcor1nconnection) pnlcor1nconnection->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlmnlocation) pnlmnlocation->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlorgmnleg) pnlorgmnleg->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
		};

		refresh(dbsbrly, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyLegRec::minimize(
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

void PnlBrlyLegRec::regularize(
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

void PnlBrlyLegRec::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGRECDO) {
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

void PnlBrlyLegRec::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyLegRec::handleDpchAppDoButMinimizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	minimize(dbsbrly, true, dpcheng);
};

void PnlBrlyLegRec::handleDpchAppDoButRegularizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	regularize(dbsbrly, true, dpcheng);
};

void PnlBrlyLegRec::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYLEGUPD_REFEQ) {
		call->abort = handleCallBrlyLegUpd_refEq(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEG_TYPEQ) {
		call->abort = handleCallBrlyLeg_typEq(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEG_INSBS) {
		call->abort = handleCallBrlyLeg_inSbs(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEG_CLUEQ) {
		call->abort = handleCallBrlyLeg_cluEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlBrlyLegRec::handleCallBrlyLegUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlyLegUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyLegRec::handleCallBrlyLeg_typEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recLeg.ixVBasetype == ixInv); // IP handleCallBrlyLeg_typEq --- LINE
	return retval;
};

bool PnlBrlyLegRec::handleCallBrlyLeg_inSbs(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetLeg & ixInv) != 0); // IP handleCallBrlyLeg_inSbs --- LINE
	return retval;
};

bool PnlBrlyLegRec::handleCallBrlyLeg_cluEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recLeg.refBrlyCLeg == refInv); // IP handleCallBrlyLeg_cluEq --- LINE
	return retval;
};
