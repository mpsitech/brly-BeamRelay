/**
	* \file QryBrlyUsrList.cpp
	* job handler for job QryBrlyUsrList (implementation)
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

#include "QryBrlyUsrList.h"

#include "QryBrlyUsrList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryBrlyUsrList
 ******************************************************************************/

QryBrlyUsrList::QryBrlyUsrList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::QRYBRLYUSRLIST, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYUSRMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyUsrList::~QryBrlyUsrList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryBrlyUsrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecBrlyVCall::CALLBRLYUSRUPD_REFEQ, jref);
	else xchg->addRefClstn(VecBrlyVCall::CALLBRLYUSRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryBrlyUsrList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecBrlyVPreset::PREBRLYJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecBrlyVPreset::PREBRLYUSRLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecBrlyVPreset::PREBRLYUSRLIST_OWN, jref);
	ubigint prePrs = xchg->getRefPreset(VecBrlyVPreset::PREBRLYUSRLIST_PRS, jref);
	string preSrf = xchg->getSrefPreset(VecBrlyVPreset::PREBRLYUSRLIST_SRF, jref);
	ubigint preUsg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYUSRLIST_USG, jref);
	uint preSte = xchg->getIxPreset(VecBrlyVPreset::PREBRLYUSRLIST_STE, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqusrlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMUser.ref)";
	sqlstr += " FROM TblBrlyMUser, TblBrlyQSelect";
	sqlstr += " WHERE TblBrlyQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblBrlyMUser.grp = TblBrlyQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblBrlyMUser.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, prePrs, preSrf, preUsg, preSte, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQUsrList(jref, jnum, ref, grp, own, refBrlyMPerson, sref, refBrlyMUsergroup, ixVState, ixBrlyVLocale, ixBrlyVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMUser.ref, TblBrlyMUser.grp, TblBrlyMUser.own, TblBrlyMUser.refBrlyMPerson, TblBrlyMUser.sref, TblBrlyMUser.refBrlyMUsergroup, TblBrlyMUser.ixVState, TblBrlyMUser.ixBrlyVLocale, TblBrlyMUser.ixBrlyVUserlevel";
	sqlstr += " FROM TblBrlyMUser, TblBrlyQSelect";
	sqlstr += " WHERE TblBrlyQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblBrlyMUser.grp = TblBrlyQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblBrlyMUser.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, prePrs, preSrf, preUsg, preSte, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQUsrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyUsrList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const ubigint prePrs
			, const string& preSrf
			, const ubigint preUsg
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMUser.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMUser.own = " + to_string(preOwn) + "";
	};

	if (prePrs != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMUser.refBrlyMPerson = " + to_string(prePrs) + "";
	};

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMUser.sref = '" + preSrf + "'";
	};

	if (preUsg != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMUser.refBrlyMUsergroup = " + to_string(preUsg) + "";
	};

	if (preSte != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMUser.ixVState = " + to_string(preSte) + "";
	};
};

void QryBrlyUsrList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyUsrList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblBrlyMUser.ixVState ASC";
	else if (preIxOrd == VecVOrd::USG) sqlstr += " ORDER BY TblBrlyMUser.refBrlyMUsergroup ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblBrlyMUser.sref ASC";
	else if (preIxOrd == VecVOrd::PRS) sqlstr += " ORDER BY TblBrlyMUser.refBrlyMPerson ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblBrlyMUser.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblBrlyMUser.grp ASC";
};

void QryBrlyUsrList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQUsrList* rec = NULL;

	ListBrlyJMUserState usrJstes;
	BrlyJMUserState* usrJste = NULL;

	int preSystime = xchg->getIntvalPreset(VecBrlyVPreset::PREBRLYSYSTIME, jref);

	dbsbrly->tblbrlyqusrlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			dbsbrly->tblbrlyjmuserstate->loadRstByUsr(rec->ref, false, usrJstes);
			for (unsigned int j = 0; j < usrJstes.nodes.size(); j++) {
				usrJste = usrJstes.nodes[j];
				if (preSystime >= usrJste->x1Start) {
					rec->ixVState = usrJste->ixVState;
				};
			};
			rec->jnum = statshr.jnumFirstload + i;
			rec->stubGrp = StubBrly::getStubGroup(dbsbrly, rec->grp, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubOwn = StubBrly::getStubOwner(dbsbrly, rec->own, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefBrlyMPerson = StubBrly::getStubPrsStd(dbsbrly, rec->refBrlyMPerson, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefBrlyMUsergroup = StubBrly::getStubUsgStd(dbsbrly, rec->refBrlyMUsergroup, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecBrlyVMUserState::getSref(rec->ixVState);
			rec->titIxVState = VecBrlyVMUserState::getTitle(rec->ixVState, ixBrlyVLocale);
			rec->srefIxBrlyVLocale = VecBrlyVLocale::getSref(rec->ixBrlyVLocale);
			rec->titIxBrlyVLocale = VecBrlyVLocale::getTitle(rec->ixBrlyVLocale, ixBrlyVLocale);
			rec->srefIxBrlyVUserlevel = VecBrlyVUserlevel::getSref(rec->ixBrlyVUserlevel);
			rec->titIxBrlyVUserlevel = VecBrlyVUserlevel::getTitle(rec->ixBrlyVUserlevel, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyUsrList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyUsrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQUsrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyUsrList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQUsrList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQUsrList* QryBrlyUsrList::getRecByJnum(
			const uint jnum
		) {
	BrlyQUsrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyUsrList::handleRequest(
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

bool QryBrlyUsrList::handleRerun(
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

bool QryBrlyUsrList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQUsrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\trefBrlyMPerson";
	cout << "\tstubRefBrlyMPerson";
	cout << "\tsref";
	cout << "\trefBrlyMUsergroup";
	cout << "\tstubRefBrlyMUsergroup";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tixBrlyVLocale";
	cout << "\tsrefIxBrlyVLocale";
	cout << "\ttitIxBrlyVLocale";
	cout << "\tixBrlyVUserlevel";
	cout << "\tsrefIxBrlyVUserlevel";
	cout << "\ttitIxBrlyVUserlevel";
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
		cout << "\t" << rec->refBrlyMPerson;
		cout << "\t" << rec->stubRefBrlyMPerson;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refBrlyMUsergroup;
		cout << "\t" << rec->stubRefBrlyMUsergroup;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->ixBrlyVLocale;
		cout << "\t" << rec->srefIxBrlyVLocale;
		cout << "\t" << rec->titIxBrlyVLocale;
		cout << "\t" << rec->ixBrlyVUserlevel;
		cout << "\t" << rec->srefIxBrlyVUserlevel;
		cout << "\t" << rec->titIxBrlyVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryBrlyUsrList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYUSRUPD_REFEQ) {
		call->abort = handleCallBrlyUsrUpd_refEq(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSRMOD) {
		call->abort = handleCallBrlyUsrMod(dbsbrly, call->jref);
	} else if ((call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallBrlyStubChgFromSelf(dbsbrly);
	};
};

bool QryBrlyUsrList::handleCallBrlyUsrUpd_refEq(
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

bool QryBrlyUsrList::handleCallBrlyUsrMod(
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

bool QryBrlyUsrList::handleCallBrlyStubChgFromSelf(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCallBrlyStubChgFromSelf --- INSERT
	return retval;
};
