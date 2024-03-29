/**
	* \file QryBrlyLocList.cpp
	* job handler for job QryBrlyLocList (implementation)
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

#include "QryBrlyLocList.h"

#include "QryBrlyLocList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryBrlyLocList
 ******************************************************************************/

QryBrlyLocList::QryBrlyLocList(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::QRYBRLYLOCLIST, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixBrlyVQrystate = VecBrlyVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsbrly);

	xchg->addClstn(VecBrlyVCall::CALLBRLYLOCMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryBrlyLocList::~QryBrlyLocList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryBrlyLocList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecBrlyVCall::CALLBRLYLOCUPD_REFEQ, jref);
	else xchg->addRefClstn(VecBrlyVCall::CALLBRLYLOCUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryBrlyLocList::rerun(
			DbsBrly* dbsbrly
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecBrlyVPreset::PREBRLYLOCLIST_SRF, jref);
	string preIca = xchg->getTxtvalPreset(VecBrlyVPreset::PREBRLYLOCLIST_ICA, jref);
	string preTit = xchg->getTxtvalPreset(VecBrlyVPreset::PREBRLYLOCLIST_TIT, jref);
	uint preTyp = xchg->getIxPreset(VecBrlyVPreset::PREBRLYLOCLIST_TYP, jref);
	ubigint preReg = xchg->getRefPreset(VecBrlyVPreset::PREBRLYLOCLIST_REG, jref);
	ubigint preEqp = xchg->getRefPreset(VecBrlyVPreset::PREBRLYLOCLIST_EQP, jref);

	dbsbrly->tblbrlyqselect->removeRstByJref(jref);
	dbsbrly->tblbrlyqloclist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblBrlyMLocation.ref)";
	sqlstr += " FROM TblBrlyMLocation";
	rerun_filtSQL(sqlstr, preSrf, preIca, preTit, preTyp, preReg, preEqp, true);
	dbsbrly->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblBrlyQLocList(jref, jnum, ref, sref, srefICAO, Title, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, alt, theta, phi)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblBrlyMLocation.ref, TblBrlyMLocation.sref, TblBrlyMLocation.srefICAO, TblBrlyMLocation.Title, TblBrlyMLocation.ixVBasetype, TblBrlyMLocation.refBrlyMRegion, TblBrlyMLocation.refBrlyMEquipment, TblBrlyMLocation.alt, TblBrlyMLocation.theta, TblBrlyMLocation.phi";
	sqlstr += " FROM TblBrlyMLocation";
	rerun_filtSQL(sqlstr, preSrf, preIca, preTit, preTyp, preReg, preEqp, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsbrly->executeQuery(sqlstr);

	sqlstr = "UPDATE TblBrlyQLocList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsbrly->executeQuery(sqlstr);

	ixBrlyVQrystate = VecBrlyVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsbrly);

	if (call) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTATCHG, jref);

};

void QryBrlyLocList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const string& preIca
			, const string& preTit
			, const uint preTyp
			, const ubigint preReg
			, const ubigint preEqp
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMLocation.sref = '" + preSrf + "'";
	};

	if (preIca.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMLocation.srefICAO LIKE '" + preIca + "'";
	};

	if (preTit.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMLocation.Title LIKE '" + preTit + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMLocation.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preReg != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMLocation.refBrlyMRegion = " + to_string(preReg) + "";
	};

	if (preEqp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblBrlyMLocation.refBrlyMEquipment = " + to_string(preEqp) + "";
	};
};

void QryBrlyLocList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryBrlyLocList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::EQP) sqlstr += " ORDER BY TblBrlyMLocation.refBrlyMEquipment ASC";
	else if (preIxOrd == VecVOrd::REG) sqlstr += " ORDER BY TblBrlyMLocation.refBrlyMRegion ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblBrlyMLocation.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblBrlyMLocation.Title ASC";
	else if (preIxOrd == VecVOrd::ICA) sqlstr += " ORDER BY TblBrlyMLocation.srefICAO ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblBrlyMLocation.sref ASC";
};

void QryBrlyLocList::fetch(
			DbsBrly* dbsbrly
		) {
	string sqlstr;

	StmgrBrly* stmgr = NULL;
	Stcch* stcch = NULL;

	BrlyQLocList* rec = NULL;

	dbsbrly->tblbrlyqloclist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecBrlyVMLocationBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecBrlyVMLocationBasetype::getTitle(rec->ixVBasetype, ixBrlyVLocale);
			rec->stubRefBrlyMRegion = StubBrly::getStubRegStd(dbsbrly, rec->refBrlyMRegion, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefBrlyMEquipment = StubBrly::getStubLocStd(dbsbrly, rec->refBrlyMEquipment, ixBrlyVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryBrlyLocList", "fetch");
	};

	refreshJnum();
};

uint QryBrlyLocList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	BrlyQLocList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryBrlyLocList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	BrlyQLocList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

BrlyQLocList* QryBrlyLocList::getRecByJnum(
			const uint jnum
		) {
	BrlyQLocList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryBrlyLocList::handleRequest(
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

bool QryBrlyLocList::handleRerun(
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

bool QryBrlyLocList::handleShow(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	BrlyQLocList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tsrefICAO";
	cout << "\tTitle";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\trefBrlyMRegion";
	cout << "\tstubRefBrlyMRegion";
	cout << "\trefBrlyMEquipment";
	cout << "\tstubRefBrlyMEquipment";
	cout << "\talt";
	cout << "\ttheta";
	cout << "\tphi";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->srefICAO;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->refBrlyMRegion;
		cout << "\t" << rec->stubRefBrlyMRegion;
		cout << "\t" << rec->refBrlyMEquipment;
		cout << "\t" << rec->stubRefBrlyMEquipment;
		cout << "\t" << rec->alt;
		cout << "\t" << rec->theta;
		cout << "\t" << rec->phi;
		cout << endl;
	};
	return retval;
};

void QryBrlyLocList::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYLOCMOD) {
		call->abort = handleCallBrlyLocMod(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOCUPD_REFEQ) {
		call->abort = handleCallBrlyLocUpd_refEq(dbsbrly, call->jref);
	} else if ((call->ixVCall == VecBrlyVCall::CALLBRLYSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallBrlyStubChgFromSelf(dbsbrly);
	};
};

bool QryBrlyLocList::handleCallBrlyLocMod(
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

bool QryBrlyLocList::handleCallBrlyLocUpd_refEq(
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

bool QryBrlyLocList::handleCallBrlyStubChgFromSelf(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	// IP handleCallBrlyStubChgFromSelf --- INSERT
	return retval;
};
