/**
	* \file DlgBrlyTtbNew.cpp
	* job handler for job DlgBrlyTtbNew (implementation)
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

#include "DlgBrlyTtbNew.h"

#include "DlgBrlyTtbNew_blks.cpp"
#include "DlgBrlyTtbNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgBrlyTtbNew
 ******************************************************************************/

DlgBrlyTtbNew::DlgBrlyTtbNew(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::DLGBRLYTTBNEW, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	feedFDetPupAli.tag = "FeedFDetPupAli";
	dbsbrly->fillFeedFromKlst(VecBrlyVKeylist::KLSTBRLYKALLIANCE, ixBrlyVLocale, feedFDetPupAli);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	valid = false;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgBrlyTtbNew::~DlgBrlyTtbNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngBrly* DlgBrlyTtbNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFDetPupAli, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgBrlyTtbNew::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButCncActive = evalButCncActive(dbsbrly);
	statshr.ButCreActive = evalButCreActive(dbsbrly);

	// contiac

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void DlgBrlyTtbNew::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCNCCLICK) {
					handleDpchAppDoButCncClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCRECLICK) {
					handleDpchAppDoButCreClick(dbsbrly, &(req->dpcheng));
				};

			};

		};
	};
};

void DlgBrlyTtbNew::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgBrlyTtbNew::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	ubigint ref;

	uint startd, stopd;

	// validate numFDetPupAli
	valid = (feedFDetPupAli.getIxByNum(_contiac->numFDetPupAli) != 0);
	if (valid) contiac.numFDetPupAli = _contiac->numFDetPupAli;
	else contiac.numFDetPupAli = 0;

	// validate DetTxfTit
	if (valid) {
		valid = (_contiac->DetTxfTit.length() >= 3);
		if (valid) valid = (dbsbrly->loadRefBySQL("SELECT ref FROM TblBrlyMTimetable WHERE Title = '" + _contiac->DetTxfTit + "'", ref) == false);

		if (valid) contiac.DetTxfTit = _contiac->DetTxfTit;
		else contiac.DetTxfTit = "";
	};

	// validate DetTxfSta
	if (valid) {
		startd = Ftm::invdate(_contiac->DetTxfSta);
		valid = (startd != 0);

		if (valid) contiac.DetTxfSta = _contiac->DetTxfSta;
		else contiac.DetTxfSta = "";
	};

	// validate DetTxfSto
	if (valid) {
		stopd = Ftm::invdate(_contiac->DetTxfSto);
		valid = (stopd != 0);
	};

	if (valid) valid = ((stopd > startd) || ((stopd-startd) <= 180));

	if (valid) contiac.DetTxfSto = _contiac->DetTxfSto;
	else contiac.DetTxfSto = "";

	refresh(dbsbrly, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgBrlyTtbNew::handleDpchAppDoButCncClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButCncClick --- IBEGIN
	if (statshr.ButCncActive) {
		*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
		xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButCncClick --- IEND
};

void DlgBrlyTtbNew::handleDpchAppDoButCreClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButCreClick --- RBEGIN
	if (statshr.ButCreActive) {
		if (ixVSge == VecVSge::IDLE) {
			changeStage(dbsbrly, VecVSge::CREATE);
		};

		if (ixVSge == VecVSge::DONE) {
			if (!*dpcheng) *dpcheng = new DpchEngBrlyConfirm(true, jref, "");
			xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYDLGCLOSE, jref);
		};
	};
	// IP handleDpchAppDoButCreClick --- REND
};

void DlgBrlyTtbNew::changeStage(
			DbsBrly* dbsbrly
			, uint _ixVSge
			, DpchEngBrly** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsbrly); break;
				case VecVSge::CREATE: leaveSgeCreate(dbsbrly); break;
				case VecVSge::DONE: leaveSgeDone(dbsbrly); break;
			};

			setStage(dbsbrly, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbsbrly, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgBrlyTtbNew::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint DlgBrlyTtbNew::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgBrlyTtbNew::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgBrlyTtbNew::enterSgeCreate(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN
	BrlyMTimetable ttb;

	ttb.srefBrlyKAlliance = feedFDetPupAli.getByNum(contiac.numFDetPupAli)->sref;
	ttb.Title = contiac.DetTxfTit;
	ttb.startd = Ftm::invdate(contiac.DetTxfSta);
	ttb.stopd = Ftm::invdate(contiac.DetTxfSto);

	dbsbrly->tblbrlymtimetable->insertRec(&ttb);

	xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYTTBMOD, jref);
	xchg->triggerIxRefCall(dbsbrly, VecBrlyVCall::CALLBRLYREFPRESET, jref, VecBrlyVPreset::PREBRLYREFTTB, ttb.ref);

	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgBrlyTtbNew::leaveSgeCreate(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgBrlyTtbNew::enterSgeDone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgBrlyTtbNew::leaveSgeDone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeDone --- INSERT
};
