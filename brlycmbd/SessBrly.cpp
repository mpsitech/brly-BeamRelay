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
	xchg->addClstn(VecBrlyVCall::CALLBRLYRECACCESS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYLOG, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYCRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYCRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecBrlyVCall::CALLBRLYCRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

SessBrly::~SessBrly() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

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
	CrdBrlyCon* crdcon = NULL;

	crdcon = new CrdBrlyCon(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdcons.push_back(crdcon);
	cout << "\tjob reference: " << crdcon->jref << endl;
	xchg->jrefCmd = crdcon->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdfil(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyFil* crdfil = NULL;

	crdfil = new CrdBrlyFil(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdfils.push_back(crdfil);
	cout << "\tjob reference: " << crdfil->jref << endl;
	xchg->jrefCmd = crdfil->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdflt(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyFlt* crdflt = NULL;

	crdflt = new CrdBrlyFlt(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdflts.push_back(crdflt);
	cout << "\tjob reference: " << crdflt->jref << endl;
	xchg->jrefCmd = crdflt->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdleg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyLeg* crdleg = NULL;

	crdleg = new CrdBrlyLeg(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdlegs.push_back(crdleg);
	cout << "\tjob reference: " << crdleg->jref << endl;
	xchg->jrefCmd = crdleg->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdloc(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyLoc* crdloc = NULL;

	crdloc = new CrdBrlyLoc(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdlocs.push_back(crdloc);
	cout << "\tjob reference: " << crdloc->jref << endl;
	xchg->jrefCmd = crdloc->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdopr(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyOpr* crdopr = NULL;

	crdopr = new CrdBrlyOpr(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdoprs.push_back(crdopr);
	cout << "\tjob reference: " << crdopr->jref << endl;
	xchg->jrefCmd = crdopr->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdprs(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyPrs* crdprs = NULL;

	crdprs = new CrdBrlyPrs(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdprss.push_back(crdprs);
	cout << "\tjob reference: " << crdprs->jref << endl;
	xchg->jrefCmd = crdprs->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdpty(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyPty* crdpty = NULL;

	crdpty = new CrdBrlyPty(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdptys.push_back(crdpty);
	cout << "\tjob reference: " << crdpty->jref << endl;
	xchg->jrefCmd = crdpty->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdreg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyReg* crdreg = NULL;

	crdreg = new CrdBrlyReg(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdregs.push_back(crdreg);
	cout << "\tjob reference: " << crdreg->jref << endl;
	xchg->jrefCmd = crdreg->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdrly(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyRly* crdrly = NULL;

	crdrly = new CrdBrlyRly(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdrlys.push_back(crdrly);
	cout << "\tjob reference: " << crdrly->jref << endl;
	xchg->jrefCmd = crdrly->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdseg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlySeg* crdseg = NULL;

	crdseg = new CrdBrlySeg(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdsegs.push_back(crdseg);
	cout << "\tjob reference: " << crdseg->jref << endl;
	xchg->jrefCmd = crdseg->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdttb(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyTtb* crdttb = NULL;

	crdttb = new CrdBrlyTtb(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdttbs.push_back(crdttb);
	cout << "\tjob reference: " << crdttb->jref << endl;
	xchg->jrefCmd = crdttb->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdusg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyUsg* crdusg = NULL;

	crdusg = new CrdBrlyUsg(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdusgs.push_back(crdusg);
	cout << "\tjob reference: " << crdusg->jref << endl;
	xchg->jrefCmd = crdusg->jref;

	return false;
	return retval;
};

bool SessBrly::handleCreateCrdusr(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	CrdBrlyUsr* crdusr = NULL;

	crdusr = new CrdBrlyUsr(xchg, dbsbrly, jref, ixBrlyVLocale, 0);
	crdusrs.push_back(crdusr);
	cout << "\tjob reference: " << crdusr->jref << endl;
	xchg->jrefCmd = crdusr->jref;

	return false;
	return retval;
};

bool SessBrly::handleEraseCrdcon(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyCon* crdcon = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdcons.begin(); it != crdcons.end();) {
		crdcon = *it;
		if (crdcon->jref == iinput) {
			it = crdcons.erase(it);
			delete crdcon;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdfil(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyFil* crdfil = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdfils.begin(); it != crdfils.end();) {
		crdfil = *it;
		if (crdfil->jref == iinput) {
			it = crdfils.erase(it);
			delete crdfil;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdflt(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyFlt* crdflt = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdflts.begin(); it != crdflts.end();) {
		crdflt = *it;
		if (crdflt->jref == iinput) {
			it = crdflts.erase(it);
			delete crdflt;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdleg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyLeg* crdleg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdlegs.begin(); it != crdlegs.end();) {
		crdleg = *it;
		if (crdleg->jref == iinput) {
			it = crdlegs.erase(it);
			delete crdleg;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdloc(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyLoc* crdloc = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdlocs.begin(); it != crdlocs.end();) {
		crdloc = *it;
		if (crdloc->jref == iinput) {
			it = crdlocs.erase(it);
			delete crdloc;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdopr(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyOpr* crdopr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdoprs.begin(); it != crdoprs.end();) {
		crdopr = *it;
		if (crdopr->jref == iinput) {
			it = crdoprs.erase(it);
			delete crdopr;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdprs(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyPrs* crdprs = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdprss.begin(); it != crdprss.end();) {
		crdprs = *it;
		if (crdprs->jref == iinput) {
			it = crdprss.erase(it);
			delete crdprs;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdpty(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyPty* crdpty = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdptys.begin(); it != crdptys.end();) {
		crdpty = *it;
		if (crdpty->jref == iinput) {
			it = crdptys.erase(it);
			delete crdpty;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdreg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyReg* crdreg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdregs.begin(); it != crdregs.end();) {
		crdreg = *it;
		if (crdreg->jref == iinput) {
			it = crdregs.erase(it);
			delete crdreg;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdrly(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyRly* crdrly = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdrlys.begin(); it != crdrlys.end();) {
		crdrly = *it;
		if (crdrly->jref == iinput) {
			it = crdrlys.erase(it);
			delete crdrly;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdseg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlySeg* crdseg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdsegs.begin(); it != crdsegs.end();) {
		crdseg = *it;
		if (crdseg->jref == iinput) {
			it = crdsegs.erase(it);
			delete crdseg;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdttb(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyTtb* crdttb = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdttbs.begin(); it != crdttbs.end();) {
		crdttb = *it;
		if (crdttb->jref == iinput) {
			it = crdttbs.erase(it);
			delete crdttb;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdusg(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyUsg* crdusg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdusgs.begin(); it != crdusgs.end();) {
		crdusg = *it;
		if (crdusg->jref == iinput) {
			it = crdusgs.erase(it);
			delete crdusg;
			break;
		} else it++;
	};

	return retval;
};

bool SessBrly::handleEraseCrdusr(
			DbsBrly* dbsbrly
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdBrlyUsr* crdusr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdusrs.begin(); it != crdusrs.end();) {
		crdusr = *it;
		if (crdusr->jref == iinput) {
			it = crdusrs.erase(it);
			delete crdusr;
			break;
		} else it++;
	};

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

	for (auto it = crdusgs.begin(); it != crdusgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyUsg");
	for (auto it = crdusrs.begin(); it != crdusrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyUsr");
	for (auto it = crdprss.begin(); it != crdprss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyPrs");
	for (auto it = crdfils.begin(); it != crdfils.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyFil");
	for (auto it = crdoprs.begin(); it != crdoprs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyOpr");
	for (auto it = crdptys.begin(); it != crdptys.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyPty");
	for (auto it = crdregs.begin(); it != crdregs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyReg");
	for (auto it = crdlocs.begin(); it != crdlocs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyLoc");
	for (auto it = crdlegs.begin(); it != crdlegs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyLeg");
	for (auto it = crdttbs.begin(); it != crdttbs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyTtb");
	for (auto it = crdflts.begin(); it != crdflts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyFlt");
	for (auto it = crdsegs.begin(); it != crdsegs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlySeg");
	for (auto it = crdcons.begin(); it != crdcons.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyCon");
	for (auto it = crdrlys.begin(); it != crdrlys.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdBrlyRly");

	*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});
};

void SessBrly::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	if (call->ixVCall == VecBrlyVCall::CALLBRLYREFPRESET) {
		call->abort = handleCallBrlyRefPreSet(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYRECACCESS) {
		call->abort = handleCallBrlyRecaccess(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOG) {
		call->abort = handleCallBrlyLog(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCRDOPEN) {
		call->abort = handleCallBrlyCrdOpen(dbsbrly, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCRDCLOSE) {
		call->abort = handleCallBrlyCrdClose(dbsbrly, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYCRDACTIVE) {
		call->abort = handleCallBrlyCrdActive(dbsbrly, call->jref, call->argInv.ix, call->argRet.ix);
	};
};

bool SessBrly::handleCallBrlyRefPreSet(
			DbsBrly* dbsbrly
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	if (ixInv == VecBrlyVPreset::PREBRLYJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecBrlyVPreset::PREBRLYJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngBrlySuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	};
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
		if (ixBrlyVCard == VecBrlyVCard::CRDBRLYUSG) {
			CrdBrlyUsg* crdusg = NULL;

			crdusg = new CrdBrlyUsg(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdusgs.push_back(crdusg);

			refRet = crdusg->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYUSR) {
			CrdBrlyUsr* crdusr = NULL;

			crdusr = new CrdBrlyUsr(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdusrs.push_back(crdusr);

			refRet = crdusr->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYPRS) {
			CrdBrlyPrs* crdprs = NULL;

			crdprs = new CrdBrlyPrs(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdprss.push_back(crdprs);

			refRet = crdprs->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYFIL) {
			CrdBrlyFil* crdfil = NULL;

			crdfil = new CrdBrlyFil(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdfils.push_back(crdfil);

			refRet = crdfil->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYOPR) {
			CrdBrlyOpr* crdopr = NULL;

			crdopr = new CrdBrlyOpr(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdoprs.push_back(crdopr);

			refRet = crdopr->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYPTY) {
			CrdBrlyPty* crdpty = NULL;

			crdpty = new CrdBrlyPty(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdptys.push_back(crdpty);

			refRet = crdpty->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYNAV) {
		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYREG) {
			CrdBrlyReg* crdreg = NULL;

			crdreg = new CrdBrlyReg(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdregs.push_back(crdreg);

			refRet = crdreg->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYLOC) {
			CrdBrlyLoc* crdloc = NULL;

			crdloc = new CrdBrlyLoc(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdlocs.push_back(crdloc);

			refRet = crdloc->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYLEG) {
			CrdBrlyLeg* crdleg = NULL;

			crdleg = new CrdBrlyLeg(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdlegs.push_back(crdleg);

			refRet = crdleg->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYTTB) {
			CrdBrlyTtb* crdttb = NULL;

			crdttb = new CrdBrlyTtb(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdttbs.push_back(crdttb);

			refRet = crdttb->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYFLT) {
			CrdBrlyFlt* crdflt = NULL;

			crdflt = new CrdBrlyFlt(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdflts.push_back(crdflt);

			refRet = crdflt->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYSEG) {
			CrdBrlySeg* crdseg = NULL;

			crdseg = new CrdBrlySeg(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdsegs.push_back(crdseg);

			refRet = crdseg->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYCON) {
			CrdBrlyCon* crdcon = NULL;

			crdcon = new CrdBrlyCon(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdcons.push_back(crdcon);

			refRet = crdcon->jref;

		} else if (ixBrlyVCard == VecBrlyVCard::CRDBRLYRLY) {
			CrdBrlyRly* crdrly = NULL;

			crdrly = new CrdBrlyRly(xchg, dbsbrly, jref, ixBrlyVLocale, ref);
			crdrlys.push_back(crdrly);

			refRet = crdrly->jref;

		};
	};

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

	if (ixInv == VecBrlyVCard::CRDBRLYUSG) {
		CrdBrlyUsg* crdusg = NULL;

		for (auto it = crdusgs.begin(); it != crdusgs.end();) {
			crdusg = *it;
			if (crdusg->jref == jrefTrig) {
				it = crdusgs.erase(it);
				delete crdusg;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYUSR) {
		CrdBrlyUsr* crdusr = NULL;

		for (auto it = crdusrs.begin(); it != crdusrs.end();) {
			crdusr = *it;
			if (crdusr->jref == jrefTrig) {
				it = crdusrs.erase(it);
				delete crdusr;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYPRS) {
		CrdBrlyPrs* crdprs = NULL;

		for (auto it = crdprss.begin(); it != crdprss.end();) {
			crdprs = *it;
			if (crdprs->jref == jrefTrig) {
				it = crdprss.erase(it);
				delete crdprs;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYFIL) {
		CrdBrlyFil* crdfil = NULL;

		for (auto it = crdfils.begin(); it != crdfils.end();) {
			crdfil = *it;
			if (crdfil->jref == jrefTrig) {
				it = crdfils.erase(it);
				delete crdfil;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYOPR) {
		CrdBrlyOpr* crdopr = NULL;

		for (auto it = crdoprs.begin(); it != crdoprs.end();) {
			crdopr = *it;
			if (crdopr->jref == jrefTrig) {
				it = crdoprs.erase(it);
				delete crdopr;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYPTY) {
		CrdBrlyPty* crdpty = NULL;

		for (auto it = crdptys.begin(); it != crdptys.end();) {
			crdpty = *it;
			if (crdpty->jref == jrefTrig) {
				it = crdptys.erase(it);
				delete crdpty;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYNAV) {
		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

	} else if (ixInv == VecBrlyVCard::CRDBRLYREG) {
		CrdBrlyReg* crdreg = NULL;

		for (auto it = crdregs.begin(); it != crdregs.end();) {
			crdreg = *it;
			if (crdreg->jref == jrefTrig) {
				it = crdregs.erase(it);
				delete crdreg;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYLOC) {
		CrdBrlyLoc* crdloc = NULL;

		for (auto it = crdlocs.begin(); it != crdlocs.end();) {
			crdloc = *it;
			if (crdloc->jref == jrefTrig) {
				it = crdlocs.erase(it);
				delete crdloc;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYLEG) {
		CrdBrlyLeg* crdleg = NULL;

		for (auto it = crdlegs.begin(); it != crdlegs.end();) {
			crdleg = *it;
			if (crdleg->jref == jrefTrig) {
				it = crdlegs.erase(it);
				delete crdleg;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYTTB) {
		CrdBrlyTtb* crdttb = NULL;

		for (auto it = crdttbs.begin(); it != crdttbs.end();) {
			crdttb = *it;
			if (crdttb->jref == jrefTrig) {
				it = crdttbs.erase(it);
				delete crdttb;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYFLT) {
		CrdBrlyFlt* crdflt = NULL;

		for (auto it = crdflts.begin(); it != crdflts.end();) {
			crdflt = *it;
			if (crdflt->jref == jrefTrig) {
				it = crdflts.erase(it);
				delete crdflt;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYSEG) {
		CrdBrlySeg* crdseg = NULL;

		for (auto it = crdsegs.begin(); it != crdsegs.end();) {
			crdseg = *it;
			if (crdseg->jref == jrefTrig) {
				it = crdsegs.erase(it);
				delete crdseg;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYCON) {
		CrdBrlyCon* crdcon = NULL;

		for (auto it = crdcons.begin(); it != crdcons.end();) {
			crdcon = *it;
			if (crdcon->jref == jrefTrig) {
				it = crdcons.erase(it);
				delete crdcon;
				break;
			} else it++;
		};
	} else if (ixInv == VecBrlyVCard::CRDBRLYRLY) {
		CrdBrlyRly* crdrly = NULL;

		for (auto it = crdrlys.begin(); it != crdrlys.end();) {
			crdrly = *it;
			if (crdrly->jref == jrefTrig) {
				it = crdrlys.erase(it);
				delete crdrly;
				break;
			} else it++;
		};
	};
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
