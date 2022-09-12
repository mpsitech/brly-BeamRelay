/**
	* \file RootBrly.cpp
	* job handler for job RootBrly (implementation)
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

#include "RootBrly.h"

#include "RootBrly_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class RootBrly
 ******************************************************************************/

RootBrly::RootBrly(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const bool _clearAll
		) :
			JobBrly(xchg, VecBrlyVJob::ROOTBRLY, jrefSup, VecBrlyVLocale::ENUS)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// log
	xchg->appendToLogfile("root job created");

	if (_clearAll) clearAll(dbsbrly);
	else clearQtb(dbsbrly);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecBrlyVCall::CALLBRLYREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYSUSPSESS, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYLOGOUT, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	if (xchg->stgbrlyappearance.roottterm != 0) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * xchg->stgbrlyappearance.roottterm);
};

RootBrly::~RootBrly() {
	// log
	xchg->appendToLogfile("root job deleted");

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void RootBrly::clearAll(
			DbsBrly* dbsbrly
		) {
	BrlyMUsergroup* usg = NULL;
	BrlyRMUserMUsergroup* uru = NULL;
	BrlyMUser* usr = NULL;
	BrlyMPerson* prs = NULL;

	time_t now;

	string s;

	// empty out tables
	dbsbrly->executeQuery("DELETE FROM TblBrlyAccRMUserUniversal");
	dbsbrly->executeQuery("DELETE FROM TblBrlyAMFaflightWaypoint");
	dbsbrly->executeQuery("DELETE FROM TblBrlyAMPersonDetail");
	dbsbrly->executeQuery("DELETE FROM TblBrlyAMRegionDstswitch");
	dbsbrly->executeQuery("DELETE FROM TblBrlyAMUserAccess");
	dbsbrly->executeQuery("DELETE FROM TblBrlyAMUsergroupAccess");
	dbsbrly->executeQuery("DELETE FROM TblBrlyAVControlPar");
	dbsbrly->executeQuery("DELETE FROM TblBrlyAVKeylistKey");
	dbsbrly->executeQuery("DELETE FROM TblBrlyAVValuelistVal");
	if (dbsbrly->ixDbsVDbstype == VecDbsVDbstype::MY) dbsbrly->executeQuery("DELETE FROM TblBrlyCFile");
	else if (dbsbrly->ixDbsVDbstype == VecDbsVDbstype::PG) dbsbrly->executeQuery("ALTER SEQUENCE TblBrlyCFile RESTART WITH 1");
	if (dbsbrly->ixDbsVDbstype == VecDbsVDbstype::MY) dbsbrly->executeQuery("DELETE FROM TblBrlyCLeg");
	else if (dbsbrly->ixDbsVDbstype == VecDbsVDbstype::PG) dbsbrly->executeQuery("ALTER SEQUENCE TblBrlyCLeg RESTART WITH 1");
	dbsbrly->executeQuery("DELETE FROM TblBrlyHistRMUserUniversal");
	dbsbrly->executeQuery("DELETE FROM TblBrlyJAVKeylistKey");
	dbsbrly->executeQuery("DELETE FROM TblBrlyJMPersonLastname");
	dbsbrly->executeQuery("DELETE FROM TblBrlyJMRegion");
	dbsbrly->executeQuery("DELETE FROM TblBrlyJMRegionTitle");
	dbsbrly->executeQuery("DELETE FROM TblBrlyJMUserState");
	dbsbrly->executeQuery("DELETE FROM TblBrlyLRMConnectionMEquipment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMConnection");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMEquipment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMFaflight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMFile");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMLeg");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMNode");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMOperator");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMPerson");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMPlntype");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMRegion");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMRelay");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMSegment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMSession");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMTimetable");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMUser");
	dbsbrly->executeQuery("DELETE FROM TblBrlyMUsergroup");
	dbsbrly->executeQuery("DELETE FROM TblBrlyORMConnectionMEquipment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyProxRMLocationMLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMConnectionMFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMConnectionMSegment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMFlightMFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMFlightMLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMLegMLeg");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMLegMLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMLocationMSegment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMSegmentMSegment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMUsergroupUniversal");
	dbsbrly->executeQuery("DELETE FROM TblBrlyRMUserMUsergroup");
	dbsbrly->executeQuery("DELETE FROM TblBrlyVisRMLocationMLocation");

	clearQtb(dbsbrly);

	// generate a temporary user such that a session can be generated
	time(&now);

	dbsbrly->tblbrlymusergroup->insertNewRec(&usg, 0, 0, "temp", "temporary user group for system initialization");
	dbsbrly->tblbrlyamusergroupaccess->insertNewRec(NULL, usg->ref, VecBrlyVFeatgroup::VECBRLYVCARD, "CrdBrlyNav", VecBrlyWAccess::EDIT + VecBrlyWAccess::EXEC + VecBrlyWAccess::VIEW);
	dbsbrly->tblbrlyrmusermusergroup->insertNewRec(&uru, 0, usg->ref, VecBrlyVUserlevel::GADM);
	dbsbrly->tblbrlymuser->insertNewRec(&usr, usg->ref, 0, uru->ref, usg->ref, 0, "temp", 0, VecBrlyVMUserState::DUE, VecBrlyVLocale::ENUS, VecBrlyVUserlevel::GADM, "asdf1234", "", "temporary user for system initialization");
	usr->refJState = dbsbrly->tblbrlyjmuserstate->insertNewRec(NULL, usr->ref, 0, VecBrlyVMUserState::DUE);
	dbsbrly->tblbrlyjmuserstate->insertNewRec(NULL, usr->ref, now + 24*3600, VecBrlyVMUserState::EXP);
	usr->refBrlyMPerson = dbsbrly->tblbrlymperson->insertNewRec(&prs, usg->ref, usr->ref, VecBrlyWMPersonDerivate::USR, VecBrlyVMPersonSex::M, "Mr.", "Jack", 0, "Smith", 0, "", 0, "", "Dear Jack");

	prs->refJLastname = dbsbrly->tblbrlyjmpersonlastname->insertNewRec(NULL, prs->ref, 0, "Smith");

	usg->grp = usg->ref;
	usg->own = usr->ref;
	dbsbrly->tblbrlymusergroup->updateRec(usg);

	uru->refBrlyMUser = usr->ref;
	dbsbrly->tblbrlyrmusermusergroup->updateRec(uru);

	dbsbrly->tblbrlymuser->updateRec(usr);

	dbsbrly->tblbrlymperson->updateRec(prs);

	cout << "\ttemporary account created for user 'temp', expires " << Ftm::stamp(now + 24*3600) << "; use password 'asdf1234' to log in" << endl;

	xchg->appendToLogfile("database cleared");

	delete usg;
	delete uru;
	delete usr;
	delete prs;
};

void RootBrly::clearQtb(
			DbsBrly* dbsbrly
		) {
	dbsbrly->executeQuery("DELETE FROM TblBrlyQCon1NRelay");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQConConMNEquipment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQConList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQConMapFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQConMapLeg");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQConMapLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQConMapNode");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQConMapRelay");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQConMNFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQConMNSegment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQConRef1NSegment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQFilList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQFlt1NConnection");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQFltEqp1NNode");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQFltEqpMNConnection");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQFltFafAWaypoint");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQFltList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQFltMNConnection");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQFltMNLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQFltOrgMNFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQFltRef1NSegment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLeg1NFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLegCor1NConnection");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLegList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLegMapLeg");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLegMapLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLegMNLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLegOrgMNLeg");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocBgn1NLeg");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocEnd1NLeg");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocEqp1NNode");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocEqpMNConnection");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocMapLeg");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocMapProxLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocMapVisLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocMNFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocMNLeg");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocMNSegment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocProxOrgMNLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQLocVisOrgMNLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQOpr1NEquipment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQOprList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQPreselect");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQPrsADetail");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQPrsList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQPty1NEquipment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQPtyList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQReg1NLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQRegADstswitch");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQRegList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQRegSup1NRegion");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQRly1NNode");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQRlyList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQSegList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQSegMNConnection");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQSegMNLocation");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQSegOrgMNSegment");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQSelect");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQTtb1NFlight");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQTtbList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQTtbRef1NFile");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQUsgAAccess");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQUsgList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQUsgMNUser");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQUsr1NSession");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQUsrAAccess");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQUsrList");
	dbsbrly->executeQuery("DELETE FROM TblBrlyQUsrMNUsergroup");
};

bool RootBrly::authenticate(
			DbsBrly* dbsbrly
			, const string& username
			, const string& password
			, ubigint& refBrlyMUser
		) {
	bool valid = false;

	ubigint ref;

	BrlyMUser* usr = NULL;

	time_t now;

	refBrlyMUser = 0;

	if (dbsbrly->tblbrlymuser->loadRecBySrfPwd(username, password, &usr)) {
		if ((usr->ixVState == VecBrlyVMUserState::DSG) || (usr->ixVState == VecBrlyVMUserState::DUE)) {
			// check if expired
			time(&now);

			if (dbsbrly->loadRefBySQL("SELECT ref FROM TblBrlyJMUserState WHERE refBrlyMUser = " + to_string(usr->ref) + " AND x1Start < " + to_string(now) + " AND ixVState = " + to_string(VecBrlyVMUserState::EXP) + " ORDER BY x1Start DESC LIMIT 1", ref)) {
				usr->refJState = ref;
				usr->ixVState = VecBrlyVMUserState::EXP;
				dbsbrly->tblbrlymuser->updateRec(usr);
			};
		};

		valid = ((usr->ixVState == VecBrlyVMUserState::ACT) || (usr->ixVState == VecBrlyVMUserState::DUE));

		if (valid) refBrlyMUser = usr->ref;

		delete usr;
	};

	return valid;
};

void RootBrly::termSess(
			DbsBrly* dbsbrly
			, const ubigint jref
		) {
	JobBrly* job = NULL;

	job = xchg->getJobByJref(jref);

	if (job) {
		if (job->ixBrlyVJob == VecBrlyVJob::SESSBRLY) ((SessBrly*) job)->term(dbsbrly);
	};
};

void RootBrly::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tclearAll" << endl;
			cout << "\tcreateSess" << endl;
			cout << "\teraseSess" << endl;
		} else if (req->cmd == "clearAll") {
			req->retain = handleClearAll(dbsbrly);

		} else if (req->cmd == "createSess") {
			req->retain = handleCreateSess(dbsbrly);

		} else if (req->cmd == "eraseSess") {
			req->retain = handleEraseSess(dbsbrly);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPROOTBRLYLOGIN) {
			handleDpchAppLogin(dbsbrly, (DpchAppLogin*) (req->dpchapp), req->ip, &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::TIMER) {
		if (req->sref == "warnterm") handleTimerWithSrefWarnterm(dbsbrly);
	};
};

bool RootBrly::handleClearAll(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	clearAll(dbsbrly);
	return retval;
};

bool RootBrly::handleCreateSess(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	string input2;

	ubigint refUsr;

	cout << "\tuser name: ";
	cin >> input;
	cout << "\tpassword: ";
	cin >> input2;

	// verify password and create a session
	if (authenticate(dbsbrly, input, input2, refUsr)) {
		xchg->jrefCmd = insertSubjob(sesss, new SessBrly(xchg, dbsbrly, jref, refUsr, "127.0.0.1"));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;

		if ((xchg->stgbrlyappearance.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (xchg->stgbrlyappearance.sesstterm - xchg->stgbrlyappearance.sesstwarn));

		xchg->appendToLogfile("command line session created for user '" + input + "'");

	} else {
		cout << "\tlogin failed." << endl;

		xchg->appendToLogfile("command line login refused for user '" + input + "'");
	};

	return retval;
};

bool RootBrly::handleEraseSess(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	string input;
	ubigint iinput;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	termSess(dbsbrly, iinput);

	if (!eraseSubjobByJref(sesss, iinput)) cout << "\tjob reference doesn't exist!" << endl;
	else cout << "\tsession erased." << endl;

	return retval;
};

void RootBrly::handleDpchAppLogin(
			DbsBrly* dbsbrly
			, DpchAppLogin* dpchapplogin
			, const string ip
			, DpchEngBrly** dpcheng
		) {
	ubigint refUsr;

	ubigint jrefSess;

	Feed feedFEnsSps("FeedFEnsSps");

	// verify password
	if (authenticate(dbsbrly, StrMod::lc(dpchapplogin->username), dpchapplogin->password, refUsr)) {
		if (!(dpchapplogin->m2mNotReg)) {
			if (xchg->stgbrlyappearance.suspsess && dpchapplogin->chksuspsess) {
				// look for suspended sessions
				for (auto it = sesss.begin(); it != sesss.end(); it++) {
					jrefSess = it->second->jref;

					if (xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWNER, jrefSess) == refUsr) {
						if (xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYSUSPSESS, jrefSess)) {
							xchg->addTxtvalPreset(VecBrlyVPreset::PREBRLYIP, jrefSess, ip);
							feedFEnsSps.appendIxSrefTitles(0, Scr::scramble(jrefSess), StubBrly::getStubSesStd(dbsbrly, xchg->getRefPreset(VecBrlyVPreset::PREBRLYSESS, jrefSess)));
						};
					};
				};
			};

			if (feedFEnsSps.size() == 0) {
				// start new session
				jrefSess = insertSubjob(sesss, new SessBrly(xchg, dbsbrly, jref, refUsr, ip));

				if ((xchg->stgbrlyappearance.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (xchg->stgbrlyappearance.sesstterm - xchg->stgbrlyappearance.sesstwarn));

				xchg->appendToLogfile("session created for user '" + dpchapplogin->username + "' from IP " + ip);

				*dpcheng = new DpchEngBrlyConfirm(true, jrefSess, "");

			} else {
				// return suspended sessions
				*dpcheng = new DpchEngData(0, &feedFEnsSps, {DpchEngData::ALL});
			};

		};

	} else {
		xchg->appendToLogfile("login refused for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngBrlyConfirm(false, 0, "");
	};
};

void RootBrly::handleTimerWithSrefWarnterm(
			DbsBrly* dbsbrly
		) {
	SessBrly* sess = NULL;

	time_t tlast;
	time_t tnext = 0;

	time_t rawtime;
	time(&rawtime);

	bool term;

	if (xchg->stgbrlyappearance.sesstterm != 0) {
		for (auto it = sesss.begin(); it != sesss.end();) {
			sess = (SessBrly*) it->second;

			term = false;

			tlast = xchg->getRefPreset(VecBrlyVPreset::PREBRLYTLAST, sess->jref);

			if ((tlast + ((int) xchg->stgbrlyappearance.sesstterm)) <= rawtime) term = true;
			else if ((tlast + ((int) xchg->stgbrlyappearance.sesstterm) - ((int) xchg->stgbrlyappearance.sesstwarn)) <= rawtime) {
				sess->warnTerm(dbsbrly);
				if ((tnext == 0) || ((tlast + ((int) xchg->stgbrlyappearance.sesstterm)) < tnext)) tnext = tlast + ((int) xchg->stgbrlyappearance.sesstterm);
			} else if ((tnext == 0) || ((tlast + ((int) xchg->stgbrlyappearance.sesstterm) - ((int) xchg->stgbrlyappearance.sesstwarn)) < tnext)) tnext = tlast + xchg->stgbrlyappearance.sesstterm - xchg->stgbrlyappearance.sesstwarn;

			if (term) {
				sess->term(dbsbrly);
				it = sesss.erase(it);

				delete sess;

			} else it++;
		};
	};

	term = false;

	if (xchg->stgbrlyappearance.roottterm != 0) {
		tlast = xchg->getRefPreset(VecBrlyVPreset::PREBRLYTLAST, jref);

		if ((tlast + ((int) xchg->stgbrlyappearance.roottterm)) <= rawtime) term = true;
		else if ((tnext == 0) || ((tlast + ((int) xchg->stgbrlyappearance.roottterm)) < tnext)) tnext = tlast + xchg->stgbrlyappearance.roottterm;
	};

	if (term) {
		cout << endl << "\tterminating due to inactivity" << endl;
		kill(getpid(), SIGTERM);
	} else if (tnext != 0) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (tnext - rawtime));
};

void RootBrly::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYREFPRESET) {
		call->abort = handleCallBrlyRefPreSet(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSUSPSESS) {
		call->abort = handleCallBrlySuspsess(dbsbrly, call->jref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOGOUT) {
		call->abort = handleCallBrlyLogout(dbsbrly, call->jref, call->argInv.boolval);
	};
};

bool RootBrly::handleCallBrlyRefPreSet(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecBrlyVPreset::PREBRLYTLAST) {
		xchg->addRefPreset(ixInv, jref, refInv);
	};

	return retval;
};

bool RootBrly::handleCallBrlySuspsess(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
		) {
	bool retval = false;

	xchg->addBoolvalPreset(VecBrlyVPreset::PREBRLYSUSPSESS, jrefTrig, true);
	xchg->removeDcolsByJref(jrefTrig);

	return retval;
};

bool RootBrly::handleCallBrlyLogout(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const bool boolvalInv
		) {
	bool retval = false;

	time_t rawtime;

	termSess(dbsbrly, jrefTrig);

	if (!boolvalInv) {
		eraseSubjobByJref(sesss, jrefTrig);

		if (xchg->stgbrlyappearance.roottterm) {
			time(&rawtime);
			xchg->addRefPreset(VecBrlyVPreset::PREBRLYTLAST, jref, rawtime);
		};
	};

	return retval;
};
