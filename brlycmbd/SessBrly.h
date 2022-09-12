/**
	* \file SessBrly.h
	* job handler for job SessBrly (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef SESSBRLY_H
#define SESSBRLY_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "CrdBrlyRly.h"
#include "CrdBrlyCon.h"
#include "CrdBrlySeg.h"
#include "CrdBrlyFlt.h"
#include "CrdBrlyTtb.h"
#include "CrdBrlyLeg.h"
#include "CrdBrlyLoc.h"
#include "CrdBrlyReg.h"
#include "CrdBrlyNav.h"
#include "CrdBrlyPty.h"
#include "CrdBrlyOpr.h"
#include "CrdBrlyFil.h"
#include "CrdBrlyPrs.h"
#include "CrdBrlyUsr.h"
#include "CrdBrlyUsg.h"

#define StatShrSessBrly SessBrly::StatShr

#define DpchEngSessBrlyData SessBrly::DpchEngData

/**
	* SessBrly
	*/
class SessBrly : public JobBrly {

public:
	/**
		* StatShr (full: StatShrSessBrly)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFCRDNAV = 1;

	public:
		StatShr(const Sbecore::ubigint jrefCrdnav = 0);

	public:
		Sbecore::ubigint jrefCrdnav;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessBrlyData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint FEEDFENSSEC = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Feed* feedFEnsSec = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Feed feedFEnsSec;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

public:
	SessBrly(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::ubigint refBrlyMUser, const std::string& ip);
	~SessBrly();

public:
	StatShr statshr;

	std::map<Sbecore::ubigint, JobBrly*> crdrlys;
	std::map<Sbecore::ubigint, JobBrly*> crdcons;
	std::map<Sbecore::ubigint, JobBrly*> crdsegs;
	std::map<Sbecore::ubigint, JobBrly*> crdflts;
	std::map<Sbecore::ubigint, JobBrly*> crdttbs;
	std::map<Sbecore::ubigint, JobBrly*> crdlegs;
	std::map<Sbecore::ubigint, JobBrly*> crdlocs;
	std::map<Sbecore::ubigint, JobBrly*> crdregs;
	CrdBrlyNav* crdnav;
	std::map<Sbecore::ubigint, JobBrly*> crdptys;
	std::map<Sbecore::ubigint, JobBrly*> crdoprs;
	std::map<Sbecore::ubigint, JobBrly*> crdfils;
	std::map<Sbecore::ubigint, JobBrly*> crdprss;
	std::map<Sbecore::ubigint, JobBrly*> crdusrs;
	std::map<Sbecore::ubigint, JobBrly*> crdusgs;

	std::map<Sbecore::ubigint,Sbecore::uint> usgaccs;

	std::map<Sbecore::ubigint,std::string> scr;
	std::map<std::string,Sbecore::ubigint> descr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void warnTerm(DbsBrly* dbsbrly);
	void term(DbsBrly* dbsbrly);

	void eraseCrd(std::map<Sbecore::ubigint, JobBrly*>& subjobs);

	Sbecore::uint checkCrdActive(const Sbecore::uint ixBrlyVCard);

	Sbecore::uint checkCrdaccess(const Sbecore::uint ixBrlyVCard);
	void getIxCrdacc(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCard, const bool adm, ListBrlyRMUserMUsergroup& urus, const Sbecore::ubigint refBrlyMUser, Sbecore::uint& ixBrlyWAccess);

	Sbecore::uint checkRecaccess(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCard, const Sbecore::ubigint ref);
	void logRecaccess(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint preUref, const Sbecore::uint ixBrlyVCard, const Sbecore::ubigint unvUref);

	Sbecore::uint crdToMtb(const Sbecore::uint ixBrlyVCard);
	Sbecore::uint preToMtb(const Sbecore::uint ixBrlyVPreset);
	bool hasActive(const Sbecore::uint ixBrlyVCard);
	bool hasGrpown(const Sbecore::uint ixBrlyVMaintable);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:
	bool handleCreateCrdcon(DbsBrly* dbsbrly);
	bool handleCreateCrdfil(DbsBrly* dbsbrly);
	bool handleCreateCrdflt(DbsBrly* dbsbrly);
	bool handleCreateCrdleg(DbsBrly* dbsbrly);
	bool handleCreateCrdloc(DbsBrly* dbsbrly);
	bool handleCreateCrdopr(DbsBrly* dbsbrly);
	bool handleCreateCrdprs(DbsBrly* dbsbrly);
	bool handleCreateCrdpty(DbsBrly* dbsbrly);
	bool handleCreateCrdreg(DbsBrly* dbsbrly);
	bool handleCreateCrdrly(DbsBrly* dbsbrly);
	bool handleCreateCrdseg(DbsBrly* dbsbrly);
	bool handleCreateCrdttb(DbsBrly* dbsbrly);
	bool handleCreateCrdusg(DbsBrly* dbsbrly);
	bool handleCreateCrdusr(DbsBrly* dbsbrly);
	bool handleEraseCrdcon(DbsBrly* dbsbrly);
	bool handleEraseCrdfil(DbsBrly* dbsbrly);
	bool handleEraseCrdflt(DbsBrly* dbsbrly);
	bool handleEraseCrdleg(DbsBrly* dbsbrly);
	bool handleEraseCrdloc(DbsBrly* dbsbrly);
	bool handleEraseCrdopr(DbsBrly* dbsbrly);
	bool handleEraseCrdprs(DbsBrly* dbsbrly);
	bool handleEraseCrdpty(DbsBrly* dbsbrly);
	bool handleEraseCrdreg(DbsBrly* dbsbrly);
	bool handleEraseCrdrly(DbsBrly* dbsbrly);
	bool handleEraseCrdseg(DbsBrly* dbsbrly);
	bool handleEraseCrdttb(DbsBrly* dbsbrly);
	bool handleEraseCrdusg(DbsBrly* dbsbrly);
	bool handleEraseCrdusr(DbsBrly* dbsbrly);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyRefPreSet(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool handleCallBrlyCrdActive(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, Sbecore::uint& ixRet);
	bool handleCallBrlyCrdClose(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallBrlyCrdOpen(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv, Sbecore::ubigint& refRet);
	bool handleCallBrlyLog(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv);
	bool handleCallBrlyRecaccess(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);

};

#endif
