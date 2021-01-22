/**
	* \file PnlBrlyLegPre.cpp
	* job handler for job PnlBrlyLegPre (implementation)
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

#include "PnlBrlyLegPre.h"

#include "PnlBrlyLegPre_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlBrlyLegPre
 ******************************************************************************/

PnlBrlyLegPre::PnlBrlyLegPre(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::PNLBRLYLEGPRE, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

};

PnlBrlyLegPre::~PnlBrlyLegPre() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngBrly* PnlBrlyLegPre::getNewDpchEng(
			set<uint> items
		) {
	DpchEngBrly* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngBrlyConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &statshr, items);
	};

	return dpcheng;
};

void PnlBrlyLegPre::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlBrlyLegPre::updatePreset(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFLEG) {
	};
	// IP updatePreset --- END
};

void PnlBrlyLegPre::handleRequest(
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

		} else if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGPREDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsbrly, &(dpchappdata->contiac), &(req->dpcheng));
			};

		};
	};
};

void PnlBrlyLegPre::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlBrlyLegPre::handleDpchAppDataContiac(
			DbsBrly* dbsbrly
			, ContIac* _contiac
			, DpchEngBrly** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- INSERT
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};
