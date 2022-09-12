/**
	* \file SessBrly.cpp
	* job handler for job SessBrly (implementation)
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

#include "SessBrly.h"

#include "SessBrly_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class SessBrly
 ******************************************************************************/

SessBrly::SessBrly(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const ubigint refBrlyMUser
			, const string& ip
		) :
			JobBrly(xchg, VecBrlyVJob::SESSBRLY, jrefSup)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	crdnav = NULL;

	// IP constructor.cust1 --- INSERT

	vector<ubigint> refs;

	ubigint refSes;

	BrlyMUser* usr = NULL;

	bool adm;

	ListBrlyRMUserMUsergroup urus;
	BrlyRMUserMUsergroup* uru = NULL;

	uint ixBrlyWAccessBase, ixBrlyWAccess;

	uint jnum;

	// create new session with start time
	time_t rawtime;
	time(&rawtime);

	refSes = dbsbrly->tblbrlymsession->insertNewRec(NULL, refBrlyMUser, (uint) rawtime, 0, ip);

	xchg->addRefPreset(VecBrlyVPreset::PREBRLYSESS, jref, refSes);
	xchg->addTxtvalPreset(VecBrlyVPreset::PREBRLYIP, jref, ip);

	// set locale and presetings corresponding to user
	dbsbrly->tblbrlymuser->loadRecByRef(refBrlyMUser, &usr);

	ixBrlyVLocale = usr->ixBrlyVLocale;
	adm = (usr->ixBrlyVUserlevel == VecBrlyVUserlevel::ADM);

	xchg->addBoolvalPreset(VecBrlyVPreset::PREBRLYADMIN, jref, adm);
	xchg->addBoolvalPreset(VecBrlyVPreset::PREBRLYNOADM, jref, (usr->ixBrlyVUserlevel == VecBrlyVUserlevel::REG));

	xchg->addRefPreset(VecBrlyVPreset::PREBRLYGROUP, jref, usr->refBrlyMUsergroup);
	xchg->addRefPreset(VecBrlyVPreset::PREBRLYOWNER, jref, refBrlyMUser);

	delete usr;

	// set jrefSess (for access to BrlyQSelect from rst-type panel queries)
	xchg->addRefPreset(VecBrlyVPreset::PREBRLYJREFSESS, jref, jref);

	// fill query in BrlyQSelect with all applicable user groups
	jnum = 1;

	dbsbrly->tblbrlyqselect->insertNewRec(NULL, jref, jnum++, 0, 0);

	if (adm) {
		dbsbrly->loadRefsBySQL("SELECT ref FROM TblBrlyMUsergroup ORDER BY ref ASC", false, refs);

		for (unsigned int i = 0; i < refs.size(); i++) dbsbrly->tblbrlyqselect->insertNewRec(NULL, jref, jnum++, 0, refs[i]);

	} else {
		dbsbrly->tblbrlyrmusermusergroup->loadRstByUsr(refBrlyMUser, false, urus);

		for (unsigned int i = 0; i < urus.nodes.size(); i++) {
			uru = urus.nodes[i];

			usgaccs[uru->refBrlyMUsergroup] = uru->ixBrlyVUserlevel;
			dbsbrly->tblbrlyqselect->insertNewRec(NULL, jref, jnum++, 0, uru->refBrlyMUsergroup);
		};
	};

	// determine access rights for each card
	ixBrlyWAccessBase = 0;
	getIxCrdacc(dbsbrly, 0, adm, urus, refBrlyMUser, ixBrlyWAccessBase);

	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYUSG, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSG, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYUSR, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYPRS, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPRS, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYFIL, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYOPR, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYPTY, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYREG, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYLOC, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYLEG, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYTTB, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCTTB, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYFLT, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYSEG, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYCON, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref, ixBrlyWAccess);
	ixBrlyWAccess = ixBrlyWAccessBase; if (!adm) getIxCrdacc(dbsbrly, VecBrlyVCard::CRDBRLYRLY, adm, urus, refBrlyMUser, ixBrlyWAccess); xchg->addIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCRLY, jref, ixBrlyWAccess);

	crdnav = new CrdBrlyNav(xchg, dbsbrly, jref, ixBrlyVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecBrlyVCall::CALLBRLYREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYCRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYCRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYCRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYLOG, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYRECACCESS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

SessBrly::~SessBrly() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void SessBrly::warnTerm(
			DbsBrly* dbsbrly
		) {
	crdnav->warnTerm(dbsbrly);
};

void SessBrly::term(
			DbsBrly* dbsbrly
		) {
	BrlyMSession* ses = NULL;

	time_t rawtime;

	// update session with stop time
	time(&rawtime);

	if (dbsbrly->tblbrlymsession->loadRecByRef(xchg->getRefPreset(VecBrlyVPreset::PREBRLYSESS, jref), &ses)) {
		ses->stop = rawtime;
		dbsbrly->tblbrlymsession->updateRec(ses);

		delete ses;
	};
};

void SessBrly::eraseCrd(
			map<ubigint, JobBrly*>& subjobs
		) {
	string input;
	ubigint iinput;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoll(input.c_str());

	if (!eraseSubjobByJref(subjobs, iinput)) cout << "\tjob reference doesn't exist!" << endl;
	else cout << "\tcard erased." << endl;
};

uint SessBrly::checkCrdActive(
			const uint ixBrlyVCard
		) {

	return 0;
};

uint SessBrly::checkCrdaccess(
			const uint ixBrlyVCard
		) {
	if (ixBrlyVCard == VecBrlyVCard::CRDBRLYUSG) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSG, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYUSR) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCUSR, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYPRS) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPRS, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYFIL) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFIL, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYOPR) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCOPR, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYPTY) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCPTY, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYREG) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCREG, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYLOC) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLOC, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYLEG) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCLEG, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYTTB) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCTTB, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYFLT) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCFLT, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYSEG) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCSEG, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYCON) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCCON, jref);
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYRLY) return xchg->getIxPreset(VecBrlyVPreset::PREBRLYIXCRDACCRLY, jref);

	return 0;
};

void SessBrly::getIxCrdacc(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCard
			, const bool adm
			, ListBrlyRMUserMUsergroup& urus
			, const ubigint refBrlyMUser
			, uint& ixBrlyWAccess
		) {
	BrlyRMUserMUsergroup* uru = NULL;
	BrlyAMUsergroupAccess* usgAacc = NULL;
	BrlyAMUserAccess* usrAacc = NULL;

	uint ixCrdacc = 0;

	bool first = true;

	if (adm) {
		ixBrlyWAccess = VecBrlyWAccess::EDIT + VecBrlyWAccess::EXEC + VecBrlyWAccess::VIEW;
		return;
	};

	// check for access rights override by any of the applicable user groups
	for (unsigned int i = 0; i < urus.nodes.size(); i++) {
		uru = urus.nodes[i];

		if (dbsbrly->tblbrlyamusergroupaccess->loadRecBySQL("SELECT * FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = " + to_string(uru->refBrlyMUsergroup) + " AND x1IxBrlyVFeatgroup = " + to_string(VecBrlyVFeatgroup::VECBRLYVCARD) + " AND x2FeaSrefUix = '" + VecBrlyVCard::getSref(ixBrlyVCard) + "'", &usgAacc)) {
			ixCrdacc |= usgAacc->ixBrlyWAccess;
			first = false;

			delete usgAacc;
			if (ixCrdacc == (VecBrlyWAccess::EDIT + VecBrlyWAccess::EXEC + VecBrlyWAccess::VIEW)) break;
		};
	};

	if (!first) ixBrlyWAccess = ixCrdacc;

	// user access rights override user group access rights
	if (dbsbrly->tblbrlyamuseraccess->loadRecBySQL("SELECT * FROM TblBrlyAMUserAccess WHERE refBrlyMUser = " + to_string(refBrlyMUser) + " AND x1IxBrlyVFeatgroup = " + to_string(VecBrlyVFeatgroup::VECBRLYVCARD) + " AND x2FeaSrefUix = '" + VecBrlyVCard::getSref(ixBrlyVCard) + "'", &usrAacc)) {
		ixBrlyWAccess = usrAacc->ixBrlyWAccess;
		delete usrAacc;
	};

};

uint SessBrly::checkRecaccess(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCard
			, const ubigint ref
		) {
	uint retval = VecBrlyVRecaccess::NONE;

	ubigint grp;
	ubigint own;

	map<ubigint,uint>::iterator it;

	ubigint refBrlyMUser;
	uint ixBrlyVMaintable;

	BrlyAccRMUserUniversal* ausrRunv = NULL;
	BrlyRMUsergroupUniversal* usgRunv = NULL;

	ixBrlyVMaintable = crdToMtb(ixBrlyVCard);

	if (ixBrlyVMaintable == VecBrlyVMaintable::VOID) {
		retval = VecBrlyVRecaccess::FULL;

	} else if (hasGrpown(ixBrlyVMaintable) && (ref != 0)) {
		// find record's group and owner
		dbsbrly->loadRefBySQL("SELECT grp FROM " + VecBrlyVMaintable::getSref(ixBrlyVMaintable) + " WHERE ref = " + to_string(ref), grp);
		dbsbrly->loadRefBySQL("SELECT own FROM " + VecBrlyVMaintable::getSref(ixBrlyVMaintable) + " WHERE ref = " + to_string(ref), own);

		// administrators can edit any record
		if (xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYADMIN, jref)) retval = VecBrlyVRecaccess::FULL;

		if (retval == VecBrlyVRecaccess::NONE) {
			refBrlyMUser = xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWNER, jref);

			// a record's owner has full rights on his records
			if (refBrlyMUser == own) retval = VecBrlyVRecaccess::FULL;

			if (retval != VecBrlyVRecaccess::FULL) {
				// individual record access right
				if (dbsbrly->tblbrlyaccrmuseruniversal->loadRecByUsrMtbUnv(refBrlyMUser, ixBrlyVMaintable, ref, &ausrRunv)) {
					retval = ausrRunv->ixBrlyVRecaccess;
					delete ausrRunv;
				};
			};

			if (retval != VecBrlyVRecaccess::FULL) {
				it = usgaccs.find(grp);
				if (it != usgaccs.end()) {
					if (it->second == VecBrlyVUserlevel::GADM) {
						// group admins have full access to all of the group's records
						retval = VecBrlyVRecaccess::FULL;
					};
				};
			};

			if (retval != VecBrlyVRecaccess::FULL) {
				// individual record access right due to group membership
				for (it = usgaccs.begin(); it != usgaccs.end(); it++) {

					if (it->second == VecBrlyVUserlevel::GADM) {
						if (dbsbrly->tblbrlyrmusergroupuniversal->loadRecByUsgMtbUnv(it->second, ixBrlyVMaintable, ref, &usgRunv)) {
							if (usgRunv->ixBrlyVRecaccess == VecBrlyVRecaccess::FULL) retval = VecBrlyVRecaccess::FULL;
							else retval = VecBrlyVRecaccess::VIEW;

							delete usgRunv;
						};
					};

					if (retval == VecBrlyVRecaccess::FULL) break;
				};
			};
		};

	} else {
		if (xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYADMIN, jref)) retval = VecBrlyVRecaccess::FULL;
		else retval = VecBrlyVRecaccess::VIEW;
	};

	return retval;
};

void SessBrly::logRecaccess(
			DbsBrly* dbsbrly
			, const uint ixBrlyVPreset
			, const ubigint preUref
			, const uint ixBrlyVCard
			, const ubigint unvUref
		) {
	vector<ubigint> refs;

	ubigint refBrlyMUser;
	uint unvIxBrlyVMaintable;
	uint preIxBrlyVMaintable;

	BrlyHistRMUserUniversal* husrRunv = NULL;

	if (xchg->stgbrlyappearance.histlength > 0) {
		refBrlyMUser = xchg->getRefPreset(VecBrlyVPreset::PREBRLYOWNER, jref);
		unvIxBrlyVMaintable = crdToMtb(ixBrlyVCard);
		preIxBrlyVMaintable = preToMtb(ixBrlyVPreset);

		if (!dbsbrly->tblbrlyhistrmuseruniversal->loadRecByUsrMtbUnvCrd(refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVCard, &husrRunv)) {
			husrRunv = new BrlyHistRMUserUniversal(0, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVCard, ixBrlyVPreset, preIxBrlyVMaintable, preUref, 0);
		};

		husrRunv->start = time(NULL);

		if (husrRunv->ref == 0) {
			dbsbrly->tblbrlyhistrmuseruniversal->insertRec(husrRunv);

			dbsbrly->tblbrlyhistrmuseruniversal->loadRefsByUsrMtbCrd(refBrlyMUser, unvIxBrlyVMaintable, ixBrlyVCard, false, refs, 4294967296, xchg->stgbrlyappearance.histlength);
			for (unsigned int i = 0; i < refs.size(); i++) dbsbrly->tblbrlyhistrmuseruniversal->removeRecByRef(refs[i]);

		} else dbsbrly->tblbrlyhistrmuseruniversal->updateRec(husrRunv);

		xchg->triggerIxRefCall(dbsbrly, VecBrlyVCall::CALLBRLYHUSRRUNVMOD_CRDUSREQ, jref, ixBrlyVCard, refBrlyMUser);
	};

	delete husrRunv;
};

uint SessBrly::crdToMtb(
			const uint ixBrlyVCard
		) {
	if (ixBrlyVCard == VecBrlyVCard::CRDBRLYUSG) return VecBrlyVMaintable::TBLBRLYMUSERGROUP;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYUSR) return VecBrlyVMaintable::TBLBRLYMUSER;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYPRS) return VecBrlyVMaintable::TBLBRLYMPERSON;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYFIL) return VecBrlyVMaintable::TBLBRLYMFILE;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYOPR) return VecBrlyVMaintable::TBLBRLYMOPERATOR;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYPTY) return VecBrlyVMaintable::TBLBRLYMPLNTYPE;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYREG) return VecBrlyVMaintable::TBLBRLYMREGION;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYLOC) return VecBrlyVMaintable::TBLBRLYMLOCATION;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYLEG) return VecBrlyVMaintable::TBLBRLYMLEG;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYTTB) return VecBrlyVMaintable::TBLBRLYMTIMETABLE;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYFLT) return VecBrlyVMaintable::TBLBRLYMFLIGHT;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYSEG) return VecBrlyVMaintable::TBLBRLYMSEGMENT;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYCON) return VecBrlyVMaintable::TBLBRLYMCONNECTION;
	else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYRLY) return VecBrlyVMaintable::TBLBRLYMRELAY;

	return VecBrlyVMaintable::VOID;
};

uint SessBrly::preToMtb(
			const uint ixBrlyVPreset
		) {
	if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFAPT) return VecBrlyVMaintable::TBLBRLYMLOCATION;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFCON) return VecBrlyVMaintable::TBLBRLYMCONNECTION;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFCOR) return VecBrlyVMaintable::TBLBRLYMLEG;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFEQP) return VecBrlyVMaintable::TBLBRLYMEQUIPMENT;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFFAF) return VecBrlyVMaintable::TBLBRLYMFAFLIGHT;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFFIL) return VecBrlyVMaintable::TBLBRLYMFILE;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFFLT) return VecBrlyVMaintable::TBLBRLYMFLIGHT;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFLEG) return VecBrlyVMaintable::TBLBRLYMLEG;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFLOC) return VecBrlyVMaintable::TBLBRLYMLOCATION;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFNDE) return VecBrlyVMaintable::TBLBRLYMNODE;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFOPR) return VecBrlyVMaintable::TBLBRLYMOPERATOR;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFPLN) return VecBrlyVMaintable::TBLBRLYMEQUIPMENT;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFPRS) return VecBrlyVMaintable::TBLBRLYMPERSON;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFPTY) return VecBrlyVMaintable::TBLBRLYMPLNTYPE;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFREG) return VecBrlyVMaintable::TBLBRLYMREGION;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFRIP) return VecBrlyVMaintable::TBLBRLYMREGION;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFRLY) return VecBrlyVMaintable::TBLBRLYMRELAY;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFRTE) return VecBrlyVMaintable::TBLBRLYMLEG;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFSEG) return VecBrlyVMaintable::TBLBRLYMSEGMENT;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFSES) return VecBrlyVMaintable::TBLBRLYMSESSION;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFTTB) return VecBrlyVMaintable::TBLBRLYMTIMETABLE;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFUSG) return VecBrlyVMaintable::TBLBRLYMUSERGROUP;
	else if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYREFUSR) return VecBrlyVMaintable::TBLBRLYMUSER;

	return VecBrlyVMaintable::VOID;
};

bool SessBrly::hasActive(
			const uint ixBrlyVCard
		) {
	return(false);
};

bool SessBrly::hasGrpown(
			const uint ixBrlyVMaintable
		) {
	return((ixBrlyVMaintable == VecBrlyVMaintable::TBLBRLYMCONNECTION) || (ixBrlyVMaintable == VecBrlyVMaintable::TBLBRLYMFILE) || (ixBrlyVMaintable == VecBrlyVMaintable::TBLBRLYMLEG) || (ixBrlyVMaintable == VecBrlyVMaintable::TBLBRLYMPERSON) || (ixBrlyVMaintable == VecBrlyVMaintable::TBLBRLYMUSER) || (ixBrlyVMaintable == VecBrlyVMaintable::TBLBRLYMUSERGROUP));
};

void SessBrly::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tcreateCrdcon" << endl;
			cout << "\tcreateCrdfil" << endl;
			cout << "\tcreateCrdflt" << endl;
			cout << "\tcreateCrdleg" << endl;
			cout << "\tcreateCrdloc" << endl;
			cout << "\tcreateCrdopr" << endl;
			cout << "\tcreateCrdprs" << endl;
			cout << "\tcreateCrdpty" << endl;
			cout << "\tcreateCrdreg" << endl;
			cout << "\tcreateCrdrly" << endl;
			cout << "\tcreateCrdseg" << endl;
			cout << "\tcreateCrdttb" << endl;
			cout << "\tcreateCrdusg" << endl;
			cout << "\tcreateCrdusr" << endl;
			cout << "\teraseCrdcon" << endl;
			cout << "\teraseCrdfil" << endl;
			cout << "\teraseCrdflt" << endl;
			cout << "\teraseCrdleg" << endl;
			cout << "\teraseCrdloc" << endl;
			cout << "\teraseCrdopr" << endl;
			cout << "\teraseCrdprs" << endl;
			cout << "\teraseCrdpty" << endl;
			cout << "\teraseCrdreg" << endl;
			cout << "\teraseCrdrly" << endl;
			cout << "\teraseCrdseg" << endl;
			cout << "\teraseCrdttb" << endl;
			cout << "\teraseCrdusg" << endl;
			cout << "\teraseCrdusr" << endl;
		} else if (req->cmd == "createCrdcon") {
			req->retain = handleCreateCrdcon(dbsbrly);

		} else if (req->cmd == "createCrdfil") {
			req->retain = handleCreateCrdfil(dbsbrly);

		} else if (req->cmd == "createCrdflt") {
			req->retain = handleCreateCrdflt(dbsbrly);

		} else if (req->cmd == "createCrdleg") {
			req->retain = handleCreateCrdleg(dbsbrly);

		} else if (req->cmd == "createCrdloc") {
			req->retain = handleCreateCrdloc(dbsbrly);

		} else if (req->cmd == "createCrdopr") {
			req->retain = handleCreateCrdopr(dbsbrly);

		} else if (req->cmd == "createCrdprs") {
			req->retain = handleCreateCrdprs(dbsbrly);

		} else if (req->cmd == "createCrdpty") {
			req->retain = handleCreateCrdpty(dbsbrly);

		} else if (req->cmd == "createCrdreg") {
			req->retain = handleCreateCrdreg(dbsbrly);

		} else if (req->cmd == "createCrdrly") {
			req->retain = handleCreateCrdrly(dbsbrly);

		} else if (req->cmd == "createCrdseg") {
			req->retain = handleCreateCrdseg(dbsbrly);

		} else if (req->cmd == "createCrdttb") {
			req->retain = handleCreateCrdttb(dbsbrly);

		} else if (req->cmd == "createCrdusg") {
			req->retain = handleCreateCrdusg(dbsbrly);

		} else if (req->cmd == "createCrdusr") {
			req->retain = handleCreateCrdusr(dbsbrly);

		} else if (req->cmd == "eraseCrdcon") {
			req->retain = handleEraseCrdcon(dbsbrly);

		} else if (req->cmd == "eraseCrdfil") {
			req->retain = handleEraseCrdfil(dbsbrly);

		} else if (req->cmd == "eraseCrdflt") {
			req->retain = handleEraseCrdflt(dbsbrly);

		} else if (req->cmd == "eraseCrdleg") {
			req->retain = handleEraseCrdleg(dbsbrly);

		} else if (req->cmd == "eraseCrdloc") {
			req->retain = handleEraseCrdloc(dbsbrly);

		} else if (req->cmd == "eraseCrdopr") {
			req->retain = handleEraseCrdopr(dbsbrly);

		} else if (req->cmd == "eraseCrdprs") {
			req->retain = handleEraseCrdprs(dbsbrly);

		} else if (req->cmd == "eraseCrdpty") {
			req->retain = handleEraseCrdpty(dbsbrly);

		} else if (req->cmd == "eraseCrdreg") {
			req->retain = handleEraseCrdreg(dbsbrly);

		} else if (req->cmd == "eraseCrdrly") {
			req->retain = handleEraseCrdrly(dbsbrly);

		} else if (req->cmd == "eraseCrdseg") {
			req->retain = handleEraseCrdseg(dbsbrly);

		} else if (req->cmd == "eraseCrdttb") {
			req->retain = handleEraseCrdttb(dbsbrly);

		} else if (req->cmd == "eraseCrdusg") {
			req->retain = handleEraseCrdusg(dbsbrly);

		} else if (req->cmd == "eraseCrdusr") {
			req->retain = handleEraseCrdusr(dbsbrly);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYINIT) {
			handleDpchAppBrlyInit(dbsbrly, (DpchAppBrlyInit*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

bool SessBrly::handleCreateCrdcon(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdcons, new CrdBrlyCon(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdfil(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdfils, new CrdBrlyFil(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdflt(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdflts, new CrdBrlyFlt(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdleg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdlegs, new CrdBrlyLeg(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdloc(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdlocs, new CrdBrlyLoc(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdopr(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdoprs, new CrdBrlyOpr(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdprs(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdprss, new CrdBrlyPrs(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdpty(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdptys, new CrdBrlyPty(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdreg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdregs, new CrdBrlyReg(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdrly(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdrlys, new CrdBrlyRly(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdseg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdsegs, new CrdBrlySeg(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdttb(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdttbs, new CrdBrlyTtb(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdusg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdusgs, new CrdBrlyUsg(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleCreateCrdusr(
			DbsBrly* dbsbrly
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdusrs, new CrdBrlyUsr(xchg, dbsbrly, jref, ixBrlyVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessBrly::handleEraseCrdcon(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdcons);
	return retval;
};

bool SessBrly::handleEraseCrdfil(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdfils);
	return retval;
};

bool SessBrly::handleEraseCrdflt(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdflts);
	return retval;
};

bool SessBrly::handleEraseCrdleg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdlegs);
	return retval;
};

bool SessBrly::handleEraseCrdloc(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdlocs);
	return retval;
};

bool SessBrly::handleEraseCrdopr(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdoprs);
	return retval;
};

bool SessBrly::handleEraseCrdprs(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdprss);
	return retval;
};

bool SessBrly::handleEraseCrdpty(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdptys);
	return retval;
};

bool SessBrly::handleEraseCrdreg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdregs);
	return retval;
};

bool SessBrly::handleEraseCrdrly(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdrlys);
	return retval;
};

bool SessBrly::handleEraseCrdseg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdsegs);
	return retval;
};

bool SessBrly::handleEraseCrdttb(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdttbs);
	return retval;
};

bool SessBrly::handleEraseCrdusg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdusgs);
	return retval;
};

bool SessBrly::handleEraseCrdusr(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	eraseCrd(crdusrs);
	return retval;
};

void SessBrly::handleDpchAppBrlyInit(
			DbsBrly* dbsbrly
			, DpchAppBrlyInit* dpchappbrlyinit
			, DpchEngBrly** dpcheng
		) {
	Feed feedFEnsSec("FeedFEnsSec");

	// resume session
	xchg->removePreset(VecBrlyVPreset::PREBRLYSUSPSESS, jref);

	for (auto it = crdusgs.begin(); it != crdusgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyUsg");
	for (auto it = crdusrs.begin(); it != crdusrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyUsr");
	for (auto it = crdprss.begin(); it != crdprss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyPrs");
	for (auto it = crdfils.begin(); it != crdfils.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyFil");
	for (auto it = crdoprs.begin(); it != crdoprs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyOpr");
	for (auto it = crdptys.begin(); it != crdptys.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyPty");
	for (auto it = crdregs.begin(); it != crdregs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyReg");
	for (auto it = crdlocs.begin(); it != crdlocs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyLoc");
	for (auto it = crdlegs.begin(); it != crdlegs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyLeg");
	for (auto it = crdttbs.begin(); it != crdttbs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyTtb");
	for (auto it = crdflts.begin(); it != crdflts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyFlt");
	for (auto it = crdsegs.begin(); it != crdsegs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlySeg");
	for (auto it = crdcons.begin(); it != crdcons.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyCon");
	for (auto it = crdrlys.begin(); it != crdrlys.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdBrlyRly");

	*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});
};

void SessBrly::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYREFPRESET) {
		call->abort = handleCallBrlyRefPreSet(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCRDACTIVE) {
		call->abort = handleCallBrlyCrdActive(dbsbrly, call->jref, call->argInv.ix, call->argRet.ix);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCRDCLOSE) {
		call->abort = handleCallBrlyCrdClose(dbsbrly, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCRDOPEN) {
		call->abort = handleCallBrlyCrdOpen(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOG) {
		call->abort = handleCallBrlyLog(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYRECACCESS) {
		call->abort = handleCallBrlyRecaccess(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	};
};

bool SessBrly::handleCallBrlyRefPreSet(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallBrlyRefPreSet --- BEGIN
	if (ixInv == VecBrlyVPreset::PREBRLYJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecBrlyVPreset::PREBRLYJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngBrlySuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	} else if (ixInv == VecBrlyVPreset::PREBRLYTLAST) {
		if (xchg->stgbrlyappearance.sesstterm != 0) xchg->addRefPreset(ixInv, jref, refInv);

	};
// IP handleCallBrlyRefPreSet --- END
	return retval;
};

bool SessBrly::handleCallBrlyCrdActive(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkCrdActive(ixInv);
	return retval;
};

bool SessBrly::handleCallBrlyCrdClose(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// delete only if card is not part of a suspended session
	if (xchg->getBoolvalPreset(VecBrlyVPreset::PREBRLYSUSPSESS, jrefTrig)) return retval;

	ubigint jrefNotif = xchg->getRefPreset(VecBrlyVPreset::PREBRLYJREFNOTIFY, jref);
	if (jrefNotif == jrefTrig) xchg->removePreset(VecBrlyVPreset::PREBRLYJREFNOTIFY, jref);

	if (ixInv == VecBrlyVCard::CRDBRLYUSG) eraseSubjobByJref(crdusgs, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYUSR) eraseSubjobByJref(crdusrs, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYPRS) eraseSubjobByJref(crdprss, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYFIL) eraseSubjobByJref(crdfils, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYOPR) eraseSubjobByJref(crdoprs, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYPTY) eraseSubjobByJref(crdptys, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYNAV) {
		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

	} 
else if (ixInv == VecBrlyVCard::CRDBRLYREG) eraseSubjobByJref(crdregs, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYLOC) eraseSubjobByJref(crdlocs, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYLEG) eraseSubjobByJref(crdlegs, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYTTB) eraseSubjobByJref(crdttbs, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYFLT) eraseSubjobByJref(crdflts, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYSEG) eraseSubjobByJref(crdsegs, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYCON) eraseSubjobByJref(crdcons, jrefTrig);
	else if (ixInv == VecBrlyVCard::CRDBRLYRLY) eraseSubjobByJref(crdrlys, jrefTrig);
	return retval;
};

bool SessBrly::handleCallBrlyCrdOpen(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval = false;
	bool denied = false;

	uint ixBrlyVCard = VecBrlyVCard::getIx(srefInv);

	ubigint ref = (ubigint) intvalInv;
	if (intvalInv == -1) {
		ref = 0;
		ref--;
	};

	uint ixBrlyVPreset;
	ubigint preUref = 0;

	uint ixBrlyWAccess;
	uint ixBrlyVRecaccess;

	if (hasActive(ixBrlyVCard)) {
		if (ixInv == 0) {
			ixBrlyVPreset = checkCrdActive(ixBrlyVCard);
			if (ixBrlyVPreset == 0) {
				denied = true;
			} else {
				preUref = xchg->getRefPreset(ixBrlyVPreset, jref);
			};

		} else {
			ixBrlyVPreset = ixInv;
			preUref = refInv;
		};
	};

	if (!denied) {
		ixBrlyWAccess = checkCrdaccess(ixBrlyVCard);
		denied = (ixBrlyWAccess == 0);
	};

	if (!denied) {
		if (intvalInv == -1) {
			denied = (((ixBrlyWAccess & VecBrlyWAccess::EDIT) == 0) || ((ixBrlyWAccess & VecBrlyWAccess::EXEC) == 0));
		} else if (intvalInv > 0) {
			ixBrlyVRecaccess = checkRecaccess(dbsbrly, ixBrlyVCard, intvalInv);
			denied = (ixBrlyVRecaccess == VecBrlyVRecaccess::NONE);
		};
	};

	if (denied) {
		refRet = 0;

	} else {
		if (ixBrlyVCard == VecBrlyVCard::CRDBRLYUSG) refRet = insertSubjob(crdusgs, new CrdBrlyUsg(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYUSR) refRet = insertSubjob(crdusrs, new CrdBrlyUsr(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYPRS) refRet = insertSubjob(crdprss, new CrdBrlyPrs(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYFIL) refRet = insertSubjob(crdfils, new CrdBrlyFil(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYOPR) refRet = insertSubjob(crdoprs, new CrdBrlyOpr(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYPTY) refRet = insertSubjob(crdptys, new CrdBrlyPty(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYREG) refRet = insertSubjob(crdregs, new CrdBrlyReg(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYLOC) refRet = insertSubjob(crdlocs, new CrdBrlyLoc(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYLEG) refRet = insertSubjob(crdlegs, new CrdBrlyLeg(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYTTB) refRet = insertSubjob(crdttbs, new CrdBrlyTtb(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYFLT) refRet = insertSubjob(crdflts, new CrdBrlyFlt(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYSEG) refRet = insertSubjob(crdsegs, new CrdBrlySeg(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYCON) refRet = insertSubjob(crdcons, new CrdBrlyCon(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
		else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYRLY) refRet = insertSubjob(crdrlys, new CrdBrlyRly(xchg, dbsbrly, jref, ixBrlyVLocale, ref));
	};

	return retval;
};

bool SessBrly::handleCallBrlyLog(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval = false;
	logRecaccess(dbsbrly, ixInv, refInv, VecBrlyVCard::getIx(srefInv), intvalInv);
	return retval;
};

bool SessBrly::handleCallBrlyRecaccess(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkRecaccess(dbsbrly, ixInv, refInv);
	return retval;
};
