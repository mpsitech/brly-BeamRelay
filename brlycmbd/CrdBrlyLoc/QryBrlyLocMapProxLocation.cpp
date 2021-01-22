/**
	* \file QryBrlyLocMapProxLocation.cpp
	* job handler for job QryBrlyLocMapProxLocation (implementation)
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

#include "QryBrlyLocMapProxLocation.h"

#include "QryBrlyLocMapProxLocation_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryBrlyLocMapProxLocation
 ******************************************************************************/

QryBrlyLocMapProxLocation::QryBrlyLocMapProxLocation(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::QRYBRLYLOCMAPPROXLOCATION, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyLocMapProxLocation::~QryBrlyLocMapProxLocation() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryBrlyLocMapProxLocation::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyLocMapProxLocation::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	ubigint preRefLoc = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLOC, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqlocmapproxlocation->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblBrlyQLocMapProxLocation(qwr, jref, jnum, ref, mref, mtheta, mphi)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblBrlyProxRMLocationMLocation.ref, TblBrlyMLocation.ref, TblBrlyMLocation.theta, TblBrlyMLocation.phi";
	sqlstr += " FROM TblBrlyMLocation, TblBrlyProxRMLocationMLocation";
	sqlstr += " WHERE TblBrlyProxRMLocationMLocation.dstRefBrlyMLocation = " + to_string(preRefLoc) + "";
	sqlstr += " AND TblBrlyMLocation.ref = TblBrlyProxRMLocationMLocation.orgRefBrlyMLocation";
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQLocMapProxLocation SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyLocMapProxLocation::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQLocMapProxLocation* rec = NULL;

	dbsbrly->tblbrlyqlocmapproxlocation->loadRstByJref(jref, false, rst);

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = i+1;
			rec->stubMref = StubBrly::getStubLocStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyLocMapProxLocation", "fetch");
	};

	refreshJnum();
};

uint QryBrlyLocMapProxLocation::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQLocMapProxLocation* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyLocMapProxLocation::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQLocMapProxLocation* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQLocMapProxLocation* QryBrlyLocMapProxLocation::getRecByJnum(
			const uint jnum
		) {
	BrlyQLocMapProxLocation* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyLocMapProxLocation::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\trerun" << endl;
			cout << "\tshow" << endl;
		} else if (req->cmd == "rerun") {
			req->retain = handleRerun(dbsbrly);

		} else if (req->cmd == "show") {
			req->retain = handleShow(dbsbrly);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

bool QryBrlyLocMapProxLocation::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	rerun(dbsbrly);
	return retval;
};

bool QryBrlyLocMapProxLocation::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQLocMapProxLocation* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tmtheta";
	cout << "\tmphi";
	cout << "\tx";
	cout << "\ty";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->qwr;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->mtheta;
		cout << "\t" << rec->mphi;
		cout << "\t" << rec->x;
		cout << "\t" << rec->y;
		cout << endl;
	};
	return retval;
};

void QryBrlyLocMapProxLocation::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if ((call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallBrlyStubChgFromSelf(dbsbrly);
	};
};

bool QryBrlyLocMapProxLocation::handleCallBrlyStubChgFromSelf(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCallBrlyStubChgFromSelf --- INSERT
	return retval;
};
