/**
	* \file QryBrlySegMNConnection.cpp
	* job handler for job QryBrlySegMNConnection (implementation)
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

#include "QryBrlySegMNConnection.h"

#include "QryBrlySegMNConnection_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryBrlySegMNConnection
 ******************************************************************************/

QryBrlySegMNConnection::QryBrlySegMNConnection(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::QRYBRLYSEGMNCONNECTION, jrefSup, ixBrlyVLocale)
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

QryBrlySegMNConnection::~QryBrlySegMNConnection() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryBrlySegMNConnection::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlySegMNConnection::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefSeg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEG, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYCONRSEGMOD_SEGEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqsegmnconnection->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyRMConnectionMSegment.ref)";
	sqlstr += " FROM TblBrlyMConnection, TblBrlyRMConnectionMSegment";
	sqlstr += " WHERE TblBrlyRMConnectionMSegment.refBrlyMConnection = TblBrlyMConnection.ref";
	sqlstr += " AND TblBrlyRMConnectionMSegment.refBrlyMSegment = " + to_string(preRefSeg) + "";
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQSegMNConnection(jref, jnum, mref, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMConnection.ref, TblBrlyRMConnectionMSegment.ref, TblBrlyRMConnectionMSegment.x1Start, TblBrlyRMConnectionMSegment.x1Stop, TblBrlyRMConnectionMSegment.x2Legphi0, TblBrlyRMConnectionMSegment.x2Legphi1";
	sqlstr += " FROM TblBrlyMConnection, TblBrlyRMConnectionMSegment";
	sqlstr += " WHERE TblBrlyRMConnectionMSegment.refBrlyMConnection = TblBrlyMConnection.ref";
	sqlstr += " AND TblBrlyRMConnectionMSegment.refBrlyMSegment = " + to_string(preRefSeg) + "";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQSegMNConnection SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYCONRSEGMOD_SEGEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefSeg);
};

void QryBrlySegMNConnection::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQSegMNConnection* rec = NULL;

	dbsbrly->tblbrlyqsegmnconnection->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubBrly::getStubConStd(dbsbrly, rec->mref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmX1Start = Ftm::stamp(rec->x1Start);
			rec->ftmX1Stop = Ftm::stamp(rec->x1Stop);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlySegMNConnection", "fetch");
	};

	refreshJnum();
};

uint QryBrlySegMNConnection::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQSegMNConnection* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlySegMNConnection::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQSegMNConnection* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQSegMNConnection* QryBrlySegMNConnection::getRecByJnum(
			const uint jnum
		) {
	BrlyQSegMNConnection* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlySegMNConnection::handleRequest(
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

bool QryBrlySegMNConnection::handleRerun(
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

bool QryBrlySegMNConnection::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQSegMNConnection* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tx1Start";
	cout << "\tftmX1Start";
	cout << "\tx1Stop";
	cout << "\tftmX1Stop";
	cout << "\tx2Legphi0";
	cout << "\tx2Legphi1";
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
		cout << "\t" << rec->x1Start;
		cout << "\t" << rec->ftmX1Start;
		cout << "\t" << rec->x1Stop;
		cout << "\t" << rec->ftmX1Stop;
		cout << "\t" << rec->x2Legphi0;
		cout << "\t" << rec->x2Legphi1;
		cout << endl;
	};
	return retval;
};

void QryBrlySegMNConnection::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYCONRSEGMOD_SEGEQ) {
		call->abort = handleCallBrlyConRsegMod_segEq(dbsbrly, call->jref);
	} else if ((call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallBrlyStubChgFromSelf(dbsbrly);
	};
};

bool QryBrlySegMNConnection::handleCallBrlyConRsegMod_segEq(
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

bool QryBrlySegMNConnection::handleCallBrlyStubChgFromSelf(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCallBrlyStubChgFromSelf --- INSERT
	return retval;
};
