/**
	* \file QryBrlyPrsList.cpp
	* job handler for job QryBrlyPrsList (implementation)
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

#include "QryBrlyPrsList.h"

#include "QryBrlyPrsList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryBrlyPrsList
 ******************************************************************************/

QryBrlyPrsList::QryBrlyPrsList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::QRYBRLYPRSLIST, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYPRSMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyPrsList::~QryBrlyPrsList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryBrlyPrsList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecBrlyVCall::CALLBRLYPRSUPD_REFEQ, jref);
	else xchg->addRefClstn(VecBrlyVCall::CALLBRLYPRSUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryBrlyPrsList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecBrlyVPreset::PREBRLYJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecBrlyVPreset::PREBRLYPRSLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecBrlyVPreset::PREBRLYPRSLIST_OWN, jref);
	string preLnm = xchg->getTxtvalPreset(VecBrlyVPreset::PREBRLYPRSLIST_LNM, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqprslist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMPerson.ref)";
	sqlstr += " FROM TblBrlyMPerson, TblBrlyQSelect";
	sqlstr += " WHERE TblBrlyQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblBrlyMPerson.grp = TblBrlyQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblBrlyMPerson.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preLnm, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQPrsList(jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMPerson.ref, TblBrlyMPerson.grp, TblBrlyMPerson.own, TblBrlyMPerson.Title, TblBrlyMPerson.Firstname, TblBrlyMPerson.Lastname, TblBrlyMPerson.ixVSex, TblBrlyMPerson.telVal, TblBrlyMPerson.emlVal";
	sqlstr += " FROM TblBrlyMPerson, TblBrlyQSelect";
	sqlstr += " WHERE TblBrlyQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblBrlyMPerson.grp = TblBrlyQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblBrlyMPerson.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preLnm, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQPrsList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyPrsList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const string& preLnm
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMPerson.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMPerson.own = " + to_string(preOwn) + "";
	};

	if (preLnm.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMPerson.Lastname LIKE '" + preLnm + "'";
	};
};

void QryBrlyPrsList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyPrsList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::LNM) sqlstr += " ORDER BY TblBrlyMPerson.Lastname ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblBrlyMPerson.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblBrlyMPerson.grp ASC";
};

void QryBrlyPrsList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQPrsList* rec = NULL;

	ListBrlyJMPersonLastname prsJlnms;
	BrlyJMPersonLastname* prsJlnm = NULL;

	int preSysdate = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYSYSDATE, jref);

	dbsbrly->tblbrlyqprslist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			dbsbrly->tblbrlyjmpersonlastname->loadRstByPrs(rec->ref, false, prsJlnms);
			for (unsigned int j = 0; j < prsJlnms.nodes.size(); j++) {
				prsJlnm = prsJlnms.nodes[j];
				if (preSysdate >= prsJlnm->x1Startd) {
					rec->Lastname = prsJlnm->Lastname;
				};
			};
			rec->jnum = statshr.jnumFirstload + i;
			rec->stubGrp = StubBrly::getStubGroup(dbsbrly, rec->grp, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubOwn = StubBrly::getStubOwner(dbsbrly, rec->own, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVSex = VecBrlyVMPersonSex::getSref(rec->ixVSex);
			rec->titIxVSex = VecBrlyVMPersonSex::getTitle(rec->ixVSex, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyPrsList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyPrsList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQPrsList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyPrsList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQPrsList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQPrsList* QryBrlyPrsList::getRecByJnum(
			const uint jnum
		) {
	BrlyQPrsList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyPrsList::handleRequest(
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

bool QryBrlyPrsList::handleRerun(
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

bool QryBrlyPrsList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQPrsList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tTitle";
	cout << "\tFirstname";
	cout << "\tLastname";
	cout << "\tixVSex";
	cout << "\tsrefIxVSex";
	cout << "\ttitIxVSex";
	cout << "\ttelVal";
	cout << "\temlVal";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->grp;
		cout << "\t" << rec->stubGrp;
		cout << "\t" << rec->own;
		cout << "\t" << rec->stubOwn;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Firstname;
		cout << "\t" << rec->Lastname;
		cout << "\t" << rec->ixVSex;
		cout << "\t" << rec->srefIxVSex;
		cout << "\t" << rec->titIxVSex;
		cout << "\t" << rec->telVal;
		cout << "\t" << rec->emlVal;
		cout << endl;
	};
	return retval;
};

void QryBrlyPrsList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYPRSMOD) {
		call->abort = handleCallBrlyPrsMod(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYPRSUPD_REFEQ) {
		call->abort = handleCallBrlyPrsUpd_refEq(dbsbrly, call->jref);
	} else if ((call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallBrlyStubChgFromSelf(dbsbrly);
	};
};

bool QryBrlyPrsList::handleCallBrlyPrsMod(
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

bool QryBrlyPrsList::handleCallBrlyPrsUpd_refEq(
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

bool QryBrlyPrsList::handleCallBrlyStubChgFromSelf(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCallBrlyStubChgFromSelf --- INSERT
	return retval;
};
