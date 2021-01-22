/**
	* \file QryBrlyLocProxOrgMNLocation.cpp
	* job handler for job QryBrlyLocProxOrgMNLocation (implementation)
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

#include "QryBrlyLocProxOrgMNLocation.h"

#include "QryBrlyLocProxOrgMNLocation_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryBrlyLocProxOrgMNLocation
 ******************************************************************************/

QryBrlyLocProxOrgMNLocation::QryBrlyLocProxOrgMNLocation(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::QRYBRLYLOCPROXORGMNLOCATION, jrefSup, ixBrlyVLocale)
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

QryBrlyLocProxOrgMNLocation::~QryBrlyLocProxOrgMNLocation() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryBrlyLocProxOrgMNLocation::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyLocProxOrgMNLocation::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefLoc = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFLOC, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYPLOCRLOCMOD_OLOEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqlocproxorgmnlocation->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyProxRMLocationMLocation.ref)";
	sqlstr += " FROM TblBrlyMLocation, TblBrlyProxRMLocationMLocation";
	sqlstr += " WHERE TblBrlyProxRMLocationMLocation.dstRefBrlyMLocation = TblBrlyMLocation.ref";
	sqlstr += " AND TblBrlyProxRMLocationMLocation.orgRefBrlyMLocation = " + to_string(preRefLoc) + "";
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQLocProxOrgMNLocation(jref, jnum, mref, ref, deltaphi)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMLocation.ref, TblBrlyProxRMLocationMLocation.ref, TblBrlyProxRMLocationMLocation.deltaphi";
	sqlstr += " FROM TblBrlyMLocation, TblBrlyProxRMLocationMLocation";
	sqlstr += " WHERE TblBrlyProxRMLocationMLocation.dstRefBrlyMLocation = TblBrlyMLocation.ref";
	sqlstr += " AND TblBrlyProxRMLocationMLocation.orgRefBrlyMLocation = " + to_string(preRefLoc) + "";
	sqlstr += " ORDER BY TblBrlyMLocation.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQLocProxOrgMNLocation SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYPLOCRLOCMOD_OLOEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefLoc);
};

void QryBrlyLocProxOrgMNLocation::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQLocProxOrgMNLocation* rec = NULL;

	dbsbrly->tblbrlyqlocproxorgmnlocation->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubBrly::getStubLocStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyLocProxOrgMNLocation", "fetch");
	};

	refreshJnum();
};

uint QryBrlyLocProxOrgMNLocation::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQLocProxOrgMNLocation* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyLocProxOrgMNLocation::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQLocProxOrgMNLocation* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQLocProxOrgMNLocation* QryBrlyLocProxOrgMNLocation::getRecByJnum(
			const uint jnum
		) {
	BrlyQLocProxOrgMNLocation* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyLocProxOrgMNLocation::handleRequest(
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

bool QryBrlyLocProxOrgMNLocation::handleRerun(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;

	cout << "\tjnumFirstload (" << stgiac.jnumFirstload << "): ";
	cin >> input;
	stgiac.jnumFirstload = atol(input.c_str());
	cout << "\tnload (" << stgiac.nload << "): ";
	cin >> input;
	stgiac.nload = atol(input.c_str());

	rerun(dbsbrly);
	return retval;
};

bool QryBrlyLocProxOrgMNLocation::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQLocProxOrgMNLocation* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tdeltaphi";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->deltaphi;
		cout << endl;
	};
	return retval;
};

void QryBrlyLocProxOrgMNLocation::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYPLOCRLOCMOD_OLOEQ) {
		call->abort = handleCallBrlyPlocRlocMod_oloEq(dbsbrly, call->jref);
	} else if ((call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallBrlyStubChgFromSelf(dbsbrly);
	};
};

bool QryBrlyLocProxOrgMNLocation::handleCallBrlyPlocRlocMod_oloEq(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (ixBrlyVQrystate != VecBrlyVQrystate::OOD) {
		ixBrlyVQrystate = VecBrlyVQrystate::OOD;
		xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);
	};

	return retval;
};

bool QryBrlyLocProxOrgMNLocation::handleCallBrlyStubChgFromSelf(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCallBrlyStubChgFromSelf --- INSERT
	return retval;
};
