/**
	* \file DlgBrlyTtbTrlorig.cpp
	* job handler for job DlgBrlyTtbTrlorig (implementation)
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

#include "DlgBrlyTtbTrlorig.h"

#include "DlgBrlyTtbTrlorig_blks.cpp"
#include "DlgBrlyTtbTrlorig_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgBrlyTtbTrlorig
 ******************************************************************************/

DlgBrlyTtbTrlorig::DlgBrlyTtbTrlorig(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::DLGBRLYTTBTRLORIG, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	feedFDetPupSrc.tag = "FeedFDetPupSrc";
	VecVSrc::fillFeed(feedFDetPupSrc);
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixBrlyVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::DET;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsbrly, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgBrlyTtbTrlorig::~DlgBrlyTtbTrlorig() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngBrly* DlgBrlyTtbTrlorig::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &continftfi, &continftrl, &feedFDetPupSrc, &feedFDse, &feedFSge, &statshr, &statshrrfi, &statshrtfi, &statshrtrl, items);
	};

	return dpcheng;
};

void DlgBrlyTtbTrlorig::refreshDet(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContIacDet oldContiacdet(contiacdet);

	// IP refreshDet --- BEGIN
	// contiacdet

	// IP refreshDet --- END
	if (contiacdet.diff(&oldContiacdet).size() != 0) insert(moditems, DpchEngData::CONTIACDET);
};

void DlgBrlyTtbTrlorig::refreshRfi(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShrRfi oldStatshrrfi(statshrrfi);

	// IP refreshRfi --- BEGIN
	// statshrrfi
	statshrrfi.UldActive = evalRfiUldActive(dbsbrly);

	// IP refreshRfi --- END
	if (statshrrfi.diff(&oldStatshrrfi).size() != 0) insert(moditems, DpchEngData::STATSHRRFI);
};

void DlgBrlyTtbTrlorig::refreshTrl(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	StatShrTrl oldStatshrtrl(statshrtrl);
	ContInfTrl oldContinftrl(continftrl);

	// IP refreshTrl --- BEGIN
	// statshrtrl
	statshrtrl.ButRunActive = evalTrlButRunActive(dbsbrly);
	statshrtrl.ButStoActive = evalTrlButStoActive(dbsbrly);

	// continftrl

	// IP refreshTrl --- END
	if (statshrtrl.diff(&oldStatshrtrl).size() != 0) insert(moditems, DpchEngData::STATSHRTRL);
	if (continftrl.diff(&oldContinftrl).size() != 0) insert(moditems, DpchEngData::CONTINFTRL);
};

void DlgBrlyTtbTrlorig::refreshTfi(
			DbsBrly* dbsbrly
			, set<uint>& moditems
		) {
	ContInfTfi oldContinftfi(continftfi);
	StatShrTfi oldStatshrtfi(statshrtfi);

	// IP refreshTfi --- RBEGIN
	// statshrtfi
	statshrtfi.DldActive = evalTfiDldActive(dbsbrly);

	// continftfi
	continftfi.Dld = "IexBrlyTtb_conv.txt";

	// IP refreshTfi --- REND
	if (continftfi.diff(&oldContinftfi).size() != 0) insert(moditems, DpchEngData::CONTINFTFI);
	if (statshrtfi.diff(&oldStatshrtfi).size() != 0) insert(moditems, DpchEngData::STATSHRTFI);
};

void DlgBrlyTtbTrlorig::refresh(
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
	statshr.ButDneActive = evalButDneActive(dbsbrly);

	// contiac
	contiac.numFDse = ixVDit;

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshDet(dbsbrly, moditems);
	refreshRfi(dbsbrly, moditems);
	refreshTrl(dbsbrly, moditems);
	refreshTfi(dbsbrly, moditems);

	muteRefresh = false;
};

void DlgBrlyTtbTrlorig::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBTRLORIGDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbsbrly, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBTRLORIGDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsbrly, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoTrl != 0) {
				if (dpchappdo->ixVDoTrl == VecVDoTrl::BUTRUNCLICK) {
					handleDpchAppDoTrlButRunClick(dbsbrly, &(req->dpcheng));
				} else if (dpchappdo->ixVDoTrl == VecVDoTrl::BUTSTOCLICK) {
					handleDpchAppDoTrlButStoClick(dbsbrly, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbsbrly, req->filename);

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DOWNLOAD) {
		req->filename = handleDownload(dbsbrly);

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixOpVOpres == VecOpVOpres::SUCCESS) opNSuccess++;
			else if (req->dpchret->ixOpVOpres == VecOpVOpres::FAILURE) opNFailure++;

			if ((opNSuccess + opNFailure) == opN) {
				clearOps();

				opN = 0;
				opNSuccess = 0;

				if (opNFailure > 0) {
					opNFailure = 0;
					changeStage(dbsbrly, nextIxVSgeFailure);
				} else changeStage(dbsbrly, nextIxVSgeSuccess);
			};
		};
	};
};

void DlgBrlyTtbTrlorig::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgBrlyTtbTrlorig::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::TFI)) ixVDit = _contiac->numFDse;
		refresh(dbsbrly, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgBrlyTtbTrlorig::handleDpchAppDataContiacdet(
			DbsBrly* dbsbrly
			, ContIacDet* _contiacdet
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- INSERT
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgBrlyTtbTrlorig::handleDpchAppDoButDneClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngBrlyConfirm(true, jref, "");
		xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButDneClick --- IEND
};

void DlgBrlyTtbTrlorig::handleDpchAppDoTrlButRunClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoTrlButRunClick --- BEGIN
	if (statshrtrl.ButRunActive) {
		changeStage(dbsbrly, VecVSge::TRANSLATE, dpcheng);
	};
	// IP handleDpchAppDoTrlButRunClick --- END
};

void DlgBrlyTtbTrlorig::handleDpchAppDoTrlButStoClick(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
		) {
	// IP handleDpchAppDoTrlButStoClick --- INSERT
};

void DlgBrlyTtbTrlorig::handleUploadInSgeIdle(
			DbsBrly* dbsbrly
			, const string& filename
		) {
	// IP handleUploadInSgeIdle --- INSERT
	changeStage(dbsbrly, VecVSge::ULDDONE);
};

string DlgBrlyTtbTrlorig::handleDownload(
			DbsBrly* dbsbrly
		) {
	return(""); // IP handleDownload --- LINE
};

void DlgBrlyTtbTrlorig::changeStage(
			DbsBrly* dbsbrly
			, uint _ixVSge
			, DpchEngBrly** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsbrly); break;
				case VecVSge::ULDDONE: leaveSgeUlddone(dbsbrly); break;
				case VecVSge::TRANSLATE: leaveSgeTranslate(dbsbrly); break;
				case VecVSge::DONE: leaveSgeDone(dbsbrly); break;
			};

			setStage(dbsbrly, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbsbrly, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::ULDDONE: _ixVSge = enterSgeUlddone(dbsbrly, reenter); break;
			case VecVSge::TRANSLATE: _ixVSge = enterSgeTranslate(dbsbrly, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgBrlyTtbTrlorig::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::ULDDONE) || (ixVSge == VecVSge::TRANSLATE) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::ULDDONE) retval = "raw data file loaded";
			else if (ixVSge == VecVSge::TRANSLATE) retval = "translating";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::ULDDONE) retval = "Rohdaten-Datei geladen";
			else if (ixVSge == VecVSge::TRANSLATE) retval = "\\u00fcbersetze";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgBrlyTtbTrlorig::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgBrlyTtbTrlorig::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgBrlyTtbTrlorig::enterSgeUlddone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::ULDDONE;

	// IP enterSgeUlddone --- INSERT

	return retval;
};

void DlgBrlyTtbTrlorig::leaveSgeUlddone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeUlddone --- INSERT
};

uint DlgBrlyTtbTrlorig::enterSgeTranslate(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::TRANSLATE;
	nextIxVSgeSuccess = VecVSge::DONE;

	clearInvs();

	// IP enterSgeTranslate --- INSERT

	submitInvs(dbsbrly, retval, retval);
	return retval;
};

void DlgBrlyTtbTrlorig::leaveSgeTranslate(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeTranslate --- INSERT
};

uint DlgBrlyTtbTrlorig::enterSgeDone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgBrlyTtbTrlorig::leaveSgeDone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeDone --- INSERT
};
