/**
	* \file QryBrlyCon1NRelay.cpp
	* job handler for job QryBrlyCon1NRelay (implementation)
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

#include "QryBrlyCon1NRelay.h"

#include "QryBrlyCon1NRelay_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryBrlyCon1NRelay
 ******************************************************************************/

QryBrlyCon1NRelay::QryBrlyCon1NRelay(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::QRYBRLYCON1NRELAY, jrefSup, ixBrlyVLocale)
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

QryBrlyCon1NRelay::~QryBrlyCon1NRelay() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryBrlyCon1NRelay::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyCon1NRelay::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCon = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFCON, jref);
	int preTime = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYTIME, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYRLYMOD_CONEQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqcon1nrelay->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMRelay.ref)";
	sqlstr += " FROM TblBrlyMRelay";
	sqlstr += " WHERE TblBrlyMRelay.refBrlyMConnection = " + to_string(preRefCon) + "";
	rerun_filtSQL(sqlstr, preTime, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQCon1NRelay(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMRelay.ref";
	sqlstr += " FROM TblBrlyMRelay";
	sqlstr += " WHERE TblBrlyMRelay.refBrlyMConnection = " + to_string(preRefCon) + "";
	rerun_filtSQL(sqlstr, preTime, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQCon1NRelay SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYRLYMOD_CONEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefCon);
};

void QryBrlyCon1NRelay::rerun_filtSQL(
			string& sqlstr
			, const int preTime
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTime != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMRelay.x1Start <= " + to_string(preTime) + "";
	};

	if (preTime != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMRelay.x1Stop >= " + to_string(preTime) + "";
	};
};

void QryBrlyCon1NRelay::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyCon1NRelay::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQCon1NRelay* rec = NULL;

	dbsbrly->tblbrlyqcon1nrelay->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubBrly::getStubRlyStd(dbsbrly, rec->ref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyCon1NRelay", "fetch");
	};

	refreshJnum();
};

uint QryBrlyCon1NRelay::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQCon1NRelay* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyCon1NRelay::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQCon1NRelay* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQCon1NRelay* QryBrlyCon1NRelay::getRecByJnum(
			const uint jnum
		) {
	BrlyQCon1NRelay* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyCon1NRelay::handleRequest(
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

bool QryBrlyCon1NRelay::handleRerun(
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

bool QryBrlyCon1NRelay::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQCon1NRelay* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << endl;
	};
	return retval;
};

void QryBrlyCon1NRelay::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYRLYMOD_CONEQ) {
		call->abort = handleCallBrlyRlyMod_conEq(dbsbrly, call->jref);
	} else if ((call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallBrlyStubChgFromSelf(dbsbrly);
	};
};

bool QryBrlyCon1NRelay::handleCallBrlyRlyMod_conEq(
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

bool QryBrlyCon1NRelay::handleCallBrlyStubChgFromSelf(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCallBrlyStubChgFromSelf --- INSERT
	return retval;
};
