/**
	* \file QryBrlyUsrAAccess.cpp
	* job handler for job QryBrlyUsrAAccess (implementation)
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

#include "QryBrlyUsrAAccess.h"

#include "QryBrlyUsrAAccess_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryBrlyUsrAAccess
 ******************************************************************************/

QryBrlyUsrAAccess::QryBrlyUsrAAccess(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::QRYBRLYUSRAACCESS, jrefSup, ixBrlyVLocale)
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

QryBrlyUsrAAccess::~QryBrlyUsrAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryBrlyUsrAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryBrlyUsrAAccess::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFUSR, jref);
	uint preX1 = xchg->getIxPreset(VecBrlyVPreset::PREBRLYUSRAACCESS_X1, jref);
	string preX2 = xchg->getSrefPreset(VecBrlyVPreset::PREBRLYUSRAACCESS_X2, jref);

	xchg->removeClstns(VecBrlyVCall::CALLBRLYUSRAACCMOD_USREQ, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqusraaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyAMUserAccess.ref)";
	sqlstr += " FROM TblBrlyAMUserAccess";
	sqlstr += " WHERE TblBrlyAMUserAccess.refBrlyMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQUsrAAccess(jref, jnum, ref, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyAMUserAccess.ref, TblBrlyAMUserAccess.x1IxBrlyVFeatgroup, TblBrlyAMUserAccess.x2FeaSrefUix, TblBrlyAMUserAccess.ixBrlyWAccess";
	sqlstr += " FROM TblBrlyAMUserAccess";
	sqlstr += " WHERE TblBrlyAMUserAccess.refBrlyMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQUsrAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

	xchg->addRefClstn(VecBrlyVCall::CALLBRLYUSRAACCMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsr);
};

void QryBrlyUsrAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyAMUserAccess.x1IxBrlyVFeatgroup = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyAMUserAccess.x2FeaSrefUix = " + preX2 + "";
	};
};

void QryBrlyUsrAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyUsrAAccess::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQUsrAAccess* rec = NULL;

	dbsbrly->tblbrlyqusraaccess->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxBrlyVFeatgroup = VecBrlyVFeatgroup::getSref(rec->x1IxBrlyVFeatgroup);
			rec->titX1IxBrlyVFeatgroup = VecBrlyVFeatgroup::getTitle(rec->x1IxBrlyVFeatgroup, ixBrlyVLocale);
			rec->srefsIxBrlyWAccess = VecBrlyWAccess::getSrefs(rec->ixBrlyWAccess);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyUsrAAccess", "fetch");
	};

	refreshJnum();
};

uint QryBrlyUsrAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQUsrAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyUsrAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQUsrAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQUsrAAccess* QryBrlyUsrAAccess::getRecByJnum(
			const uint jnum
		) {
	BrlyQUsrAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyUsrAAccess::handleRequest(
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

bool QryBrlyUsrAAccess::handleRerun(
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

bool QryBrlyUsrAAccess::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQUsrAAccess* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxBrlyVFeatgroup";
	cout << "\tsrefX1IxBrlyVFeatgroup";
	cout << "\ttitX1IxBrlyVFeatgroup";
	cout << "\tx2FeaSrefUix";
	cout << "\tixBrlyWAccess";
	cout << "\tsrefsIxBrlyWAccess";
	cout << "\ttitsIxBrlyWAccess";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxBrlyVFeatgroup;
		cout << "\t" << rec->srefX1IxBrlyVFeatgroup;
		cout << "\t" << rec->titX1IxBrlyVFeatgroup;
		cout << "\t" << rec->x2FeaSrefUix;
		cout << "\t" << rec->ixBrlyWAccess;
		cout << "\t" << rec->srefsIxBrlyWAccess;
		cout << "\t" << rec->titsIxBrlyWAccess;
		cout << endl;
	};
	return retval;
};

void QryBrlyUsrAAccess::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYUSRAACCMOD_USREQ) {
		call->abort = handleCallBrlyUsrAaccMod_usrEq(dbsbrly, call->jref);
	} else if ((call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallBrlyStubChgFromSelf(dbsbrly);
	};
};

bool QryBrlyUsrAAccess::handleCallBrlyUsrAaccMod_usrEq(
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

bool QryBrlyUsrAAccess::handleCallBrlyStubChgFromSelf(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCallBrlyStubChgFromSelf --- INSERT
	return retval;
};
