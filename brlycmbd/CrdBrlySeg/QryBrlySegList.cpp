/**
	* \file QryBrlySegList.cpp
	* job handler for job QryBrlySegList (implementation)
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

#include "QryBrlySegList.h"

#include "QryBrlySegList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryBrlySegList
 ******************************************************************************/

QryBrlySegList::QryBrlySegList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::QRYBRLYSEGLIST, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYSEGMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlySegList::~QryBrlySegList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryBrlySegList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecBrlyVCall::CALLBRLYSEGUPD_REFEQ, jref);
	else xchg->addRefClstn(VecBrlyVCall::CALLBRLYSEGUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryBrlySegList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	uint preRet = xchg->getIxPreset(VecBrlyVPreset::PREBRLYSEGLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecBrlyVPreset::PREBRLYSEGLIST_REU, jref);
	int preSta = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYSEGLIST_STA, jref);
	int preSto = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYSEGLIST_STO, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqseglist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMSegment.ref)";
	sqlstr += " FROM TblBrlyMSegment";
	rerun_filtSQL(sqlstr, preRet, preReu, preSta, preSto, true);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQSegList(jref, jnum, ref, refIxVTbl, refUref, alt0, alt1, theta0, theta1, phi0, phi1, start, stop)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMSegment.ref, TblBrlyMSegment.refIxVTbl, TblBrlyMSegment.refUref, TblBrlyMSegment.alt0, TblBrlyMSegment.alt1, TblBrlyMSegment.theta0, TblBrlyMSegment.theta1, TblBrlyMSegment.phi0, TblBrlyMSegment.phi1, TblBrlyMSegment.start, TblBrlyMSegment.stop";
	sqlstr += " FROM TblBrlyMSegment";
	rerun_filtSQL(sqlstr, preRet, preReu, preSta, preSto, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQSegList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlySegList::rerun_filtSQL(
			string& sqlstr
			, const uint preRet
			, const ubigint preReu
			, const int preSta
			, const int preSto
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMSegment.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMSegment.refUref = " + to_string(preReu) + "";
	};

	if (preSta != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMSegment.start = " + to_string(preSta) + "";
	};

	if (preSto != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMSegment.stop = " + to_string(preSto) + "";
	};
};

void QryBrlySegList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlySegList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STO) sqlstr += " ORDER BY TblBrlyMSegment.stop ASC";
	else if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblBrlyMSegment.start ASC";
	else if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblBrlyMSegment.refUref ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblBrlyMSegment.refIxVTbl ASC";
};

void QryBrlySegList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQSegList* rec = NULL;

	dbsbrly->tblbrlyqseglist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefRefIxVTbl = VecBrlyVMSegmentRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecBrlyVMSegmentRefTbl::getTitle(rec->refIxVTbl, ixBrlyVLocale);
			if (rec->refIxVTbl == VecBrlyVMSegmentRefTbl::CON) {
				rec->stubRefUref = StubBrly::getStubConStd(dbsbrly, rec->refUref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecBrlyVMSegmentRefTbl::FLT) {
				rec->stubRefUref = StubBrly::getStubFltStd(dbsbrly, rec->refUref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
			rec->ftmStart = Ftm::stamp(rec->start);
			rec->ftmStop = Ftm::stamp(rec->stop);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlySegList", "fetch");
	};

	refreshJnum();
};

uint QryBrlySegList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQSegList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlySegList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQSegList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQSegList* QryBrlySegList::getRecByJnum(
			const uint jnum
		) {
	BrlyQSegList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlySegList::handleRequest(
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

bool QryBrlySegList::handleRerun(
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

bool QryBrlySegList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQSegList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\talt0";
	cout << "\talt1";
	cout << "\ttheta0";
	cout << "\ttheta1";
	cout << "\tphi0";
	cout << "\tphi1";
	cout << "\tstart";
	cout << "\tftmStart";
	cout << "\tstop";
	cout << "\tftmStop";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->alt0;
		cout << "\t" << rec->alt1;
		cout << "\t" << rec->theta0;
		cout << "\t" << rec->theta1;
		cout << "\t" << rec->phi0;
		cout << "\t" << rec->phi1;
		cout << "\t" << rec->start;
		cout << "\t" << rec->ftmStart;
		cout << "\t" << rec->stop;
		cout << "\t" << rec->ftmStop;
		cout << endl;
	};
	return retval;
};

void QryBrlySegList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYSEGMOD) {
		call->abort = handleCallBrlySegMod(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSEGUPD_REFEQ) {
		call->abort = handleCallBrlySegUpd_refEq(dbsbrly, call->jref);
	} else if ((call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallBrlyStubChgFromSelf(dbsbrly);
	};
};

bool QryBrlySegList::handleCallBrlySegMod(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixBrlyVQrystate == VecBrlyVQrystate::UTD) || (ixBrlyVQrystate == VecBrlyVQrystate::SLM)) {
		ixBrlyVQrystate = VecBrlyVQrystate::MNR;
		xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);
	};

	return retval;
};

bool QryBrlySegList::handleCallBrlySegUpd_refEq(
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

bool QryBrlySegList::handleCallBrlyStubChgFromSelf(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCallBrlyStubChgFromSelf --- INSERT
	return retval;
};
