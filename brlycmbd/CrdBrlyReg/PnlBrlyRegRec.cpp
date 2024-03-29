/**
	* \file PnlBrlyRegRec.cpp
	* job handler for job PnlBrlyRegRec (implementation)
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

#include "PnlBrlyRegRec.h"

#include "PnlBrlyRegRec_blks.cpp"
#include "PnlBrlyRegRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlBrlyRegRec
 ******************************************************************************/

PnlBrlyRegRec::PnlBrlyRegRec(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::PNLBRLYREGREC, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	pnlsup1nregion = NULL;
	pnl1nlocation = NULL;
	pnladstswitch = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYREG_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYREG_ISLEAF, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYREG_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsbrly, VecBrlyVPreset::PREBRLYREFREG, jref);
};

PnlBrlyRegRec::~PnlBrlyRegRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngBrly* PnlBrlyRegRec::getNewDpchEng(
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

void PnlBrlyRegRec::refresh(
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
	continf.TxtRef = StubBrly::getStubRegStd(dbsbrly, recReg.ref, ixBrlyVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recReg.ref == 0) statshr.ixBrlyVExpstate = VecBrlyVExpstate::MIND;

	statshr.pnl1nlocationAvail = evalPnl1nlocationAvail(dbsbrly);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbsbrly);

	if (statshr.ixBrlyVExpstate == VecBrlyVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnladstswitch) {delete pnladstswitch; pnladstswitch = NULL;};
		if (pnl1nlocation) {delete pnl1nlocation; pnl1nlocation = NULL;};
		if (pnlsup1nregion) {delete pnlsup1nregion; pnlsup1nregion = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlBrlyRegDetail(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnladstswitch) pnladstswitch = new PnlBrlyRegADstswitch(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnl1nlocation) pnl1nlocation = new PnlBrlyReg1NLocation(xchg, dbsbrly, jref, ixBrlyVLocale);
		if (!pnlsup1nregion) pnlsup1nregion = new PnlBrlyRegSup1NRegion(xchg, dbsbrly, jref, ixBrlyVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefADstswitch = ((pnladstswitch) ? pnladstswitch->jref : 0);
	statshr.jref1NLocation = ((pnl1nlocation) ? pnl1nlocation->jref : 0);
	statshr.jrefSup1NRegion = ((pnlsup1nregion) ? pnlsup1nregion->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlBrlyRegRec::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFREG) {
		BrlyMRegion* _recReg = NULL;

		if (dbsbrly->tblbrlymregion->loadRecByRef(xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFREG, jref), &_recReg)) {
			recReg = *_recReg;
			ixWSubsetReg = dbsbrly->getIxWSubsetByBrlyMRegion(_recReg);
			delete _recReg;
		} else {
			recReg = BrlyMRegion();
			ixWSubsetReg = 0;
		};

		if (recReg.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnladstswitch) pnladstswitch->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnl1nlocation) pnl1nlocation->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
			if (pnlsup1nregion) pnlsup1nregion->updatePreset(dbsbrly, ixBrlyVPreset, jrefTrig, notif);
		};

		refresh(dbsbrly, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlBrlyRegRec::minimize(
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

void PnlBrlyRegRec::regularize(
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

void PnlBrlyRegRec::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGRECDO) {
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

void PnlBrlyRegRec::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyRegRec::handleDpchAppDoButMinimizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	minimize(dbsbrly, true, dpcheng);
};

void PnlBrlyRegRec::handleDpchAppDoButRegularizeClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	regularize(dbsbrly, true, dpcheng);
};

void PnlBrlyRegRec::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYREGUPD_REFEQ) {
		call->abort = handleCallBrlyRegUpd_refEq(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREG_SUPEQ) {
		call->abort = handleCallBrlyReg_supEq(dbsbrly, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREG_ISLEAF) {
		call->abort = handleCallBrlyReg_isLeaf(dbsbrly, call->jref, call->argRet.boolval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREG_INSBS) {
		call->abort = handleCallBrlyReg_inSbs(dbsbrly, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlBrlyRegRec::handleCallBrlyRegUpd_refEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallBrlyRegUpd_refEq --- INSERT
	return retval;
};

bool PnlBrlyRegRec::handleCallBrlyReg_supEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recReg.supRefBrlyMRegion == refInv); // IP handleCallBrlyReg_supEq --- LINE
	return retval;
};

bool PnlBrlyRegRec::handleCallBrlyReg_isLeaf(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = [&](){uint cnt = 0; if (recReg.ref != 0) dbsbrly->loadUintBySQL("SELECT COUNT(ref) FROM TblBrlyMRegion WHERE supRefBrlyMRegion = " + to_string(recReg.ref), cnt); return(cnt == 0);}(); // IP handleCallBrlyReg_isLeaf --- LINE
	return retval;
};

bool PnlBrlyRegRec::handleCallBrlyReg_inSbs(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetReg & ixInv) != 0); // IP handleCallBrlyReg_inSbs --- LINE
	return retval;
};
