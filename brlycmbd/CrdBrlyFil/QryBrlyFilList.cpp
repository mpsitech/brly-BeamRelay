/**
	* \file QryBrlyFilList.cpp
	* job handler for job QryBrlyFilList (implementation)
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

#include "QryBrlyFilList.h"

#include "QryBrlyFilList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryBrlyFilList
 ******************************************************************************/

QryBrlyFilList::QryBrlyFilList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::QRYBRLYFILLIST, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYFILMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyFilList::~QryBrlyFilList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryBrlyFilList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecBrlyVCall::CALLBRLYFILUPD_REFEQ, jref);
	else xchg->addRefClstn(VecBrlyVCall::CALLBRLYFILUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryBrlyFilList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecBrlyVPreset::PREBRLYJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecBrlyVPreset::PREBRLYFILLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecBrlyVPreset::PREBRLYFILLIST_OWN, jref);
	string preFnm = xchg->getTxtvalPreset(VecBrlyVPreset::PREBRLYFILLIST_FNM, jref);
	uint preRet = xchg->getIxPreset(VecBrlyVPreset::PREBRLYFILLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecBrlyVPreset::PREBRLYFILLIST_REU, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqfillist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMFile.ref)";
	sqlstr += " FROM TblBrlyMFile, TblBrlyQSelect";
	sqlstr += " WHERE TblBrlyQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblBrlyMFile.grp = TblBrlyQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblBrlyMFile.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preFnm, preRet, preReu, false);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQFilList(jref, jnum, ref, grp, own, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMFile.ref, TblBrlyMFile.grp, TblBrlyMFile.own, TblBrlyMFile.Filename, TblBrlyMFile.refIxVTbl, TblBrlyMFile.refUref, TblBrlyMFile.osrefKContent, TblBrlyMFile.srefKMimetype, TblBrlyMFile.Size";
	sqlstr += " FROM TblBrlyMFile, TblBrlyQSelect";
	sqlstr += " WHERE TblBrlyQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblBrlyMFile.grp = TblBrlyQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblBrlyMFile.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preFnm, preRet, preReu, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQFilList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyFilList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const string& preFnm
			, const uint preRet
			, const ubigint preReu
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMFile.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMFile.own = " + to_string(preOwn) + "";
	};

	if (preFnm.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMFile.Filename LIKE '" + preFnm + "'";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMFile.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMFile.refUref = " + to_string(preReu) + "";
	};
};

void QryBrlyFilList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyFilList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblBrlyMFile.refUref ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblBrlyMFile.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::FNM) sqlstr += " ORDER BY TblBrlyMFile.Filename ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblBrlyMFile.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblBrlyMFile.grp ASC";
};

void QryBrlyFilList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQFilList* rec = NULL;

	dbsbrly->tblbrlyqfillist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubGrp = StubBrly::getStubGroup(dbsbrly, rec->grp, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubOwn = StubBrly::getStubOwner(dbsbrly, rec->own, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefRefIxVTbl = VecBrlyVMFileRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecBrlyVMFileRefTbl::getTitle(rec->refIxVTbl, ixBrlyVLocale);
			if (rec->refIxVTbl == VecBrlyVMFileRefTbl::TTB) {
				rec->stubRefUref = StubBrly::getStubTtbStd(dbsbrly, rec->refUref, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
			rec->titOsrefKContent = dbsbrly->getKlstTitleBySref(VecBrlyVKeylist::KLSTBRLYKMFILECONTENT, rec->osrefKContent, ixBrlyVLocale);
			rec->titSrefKMimetype = dbsbrly->getKlstTitleBySref(VecBrlyVKeylist::KLSTBRLYKMFILEMIMETYPE, rec->srefKMimetype, ixBrlyVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyFilList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyFilList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQFilList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyFilList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQFilList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQFilList* QryBrlyFilList::getRecByJnum(
			const uint jnum
		) {
	BrlyQFilList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyFilList::handleRequest(
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

bool QryBrlyFilList::handleRerun(
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

bool QryBrlyFilList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQFilList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tFilename";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\tosrefKContent";
	cout << "\ttitOsrefKContent";
	cout << "\tsrefKMimetype";
	cout << "\ttitSrefKMimetype";
	cout << "\tSize";
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
		cout << "\t" << rec->Filename;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->osrefKContent;
		cout << "\t" << rec->titOsrefKContent;
		cout << "\t" << rec->srefKMimetype;
		cout << "\t" << rec->titSrefKMimetype;
		cout << "\t" << rec->Size;
		cout << endl;
	};
	return retval;
};

void QryBrlyFilList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYFILUPD_REFEQ) {
		call->abort = handleCallBrlyFilUpd_refEq(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFILMOD) {
		call->abort = handleCallBrlyFilMod(dbsbrly, call->jref);
	} else if ((call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallBrlyStubChgFromSelf(dbsbrly);
	};
};

bool QryBrlyFilList::handleCallBrlyFilUpd_refEq(
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

bool QryBrlyFilList::handleCallBrlyFilMod(
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

bool QryBrlyFilList::handleCallBrlyStubChgFromSelf(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCallBrlyStubChgFromSelf --- INSERT
	return retval;
};
