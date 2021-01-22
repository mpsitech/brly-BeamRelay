/**
	* \file PnlBrlyFltRec.h
	* job handler for job PnlBrlyFltRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYFLTREC_H
#define PNLBRLYFLTREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlBrlyFltEqpMNConnection.h"
#include "PnlBrlyFltOrgMNFlight.h"
#include "PnlBrlyFltMNConnection.h"
#include "PnlBrlyFltMNLocation.h"
#include "PnlBrlyFltEqp1NNode.h"
#include "PnlBrlyFltRef1NSegment.h"
#include "PnlBrlyFlt1NConnection.h"
#include "PnlBrlyFltFafAWaypoint.h"
#include "PnlBrlyFltDetail.h"
#include "PnlBrlyFltPre.h"

#define VecVBrlyFltRecDo PnlBrlyFltRec::VecVDo

#define ContInfBrlyFltRec PnlBrlyFltRec::ContInf
#define StatAppBrlyFltRec PnlBrlyFltRec::StatApp
#define StatShrBrlyFltRec PnlBrlyFltRec::StatShr
#define TagBrlyFltRec PnlBrlyFltRec::Tag

#define DpchAppBrlyFltRecDo PnlBrlyFltRec::DpchAppDo
#define DpchEngBrlyFltRecData PnlBrlyFltRec::DpchEngData

/**
	* PnlBrlyFltRec
	*/
class PnlBrlyFltRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyFltRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyFltRec)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyFltRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneFafAWaypoint = false, const bool initdone1NConnection = false, const bool initdoneRef1NSegment = false, const bool initdoneEqp1NNode = false, const bool initdoneMNLocation = false, const bool initdoneMNConnection = false, const bool initdoneOrgMNFlight = false, const bool initdoneEqpMNConnection = false);
	};

	/**
		* StatShr (full: StatShrBrlyFltRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXBRLYVEXPSTATE = 1;
		static const Sbecore::uint JREFPRE = 2;
		static const Sbecore::uint JREFDETAIL = 3;
		static const Sbecore::uint JREFFAFAWAYPOINT = 4;
		static const Sbecore::uint PNLFAFAWAYPOINTAVAIL = 5;
		static const Sbecore::uint JREF1NCONNECTION = 6;
		static const Sbecore::uint JREFREF1NSEGMENT = 7;
		static const Sbecore::uint JREFEQP1NNODE = 8;
		static const Sbecore::uint PNLEQP1NNODEAVAIL = 9;
		static const Sbecore::uint JREFMNLOCATION = 10;
		static const Sbecore::uint JREFMNCONNECTION = 11;
		static const Sbecore::uint JREFORGMNFLIGHT = 12;
		static const Sbecore::uint JREFEQPMNCONNECTION = 13;
		static const Sbecore::uint PNLEQPMNCONNECTIONAVAIL = 14;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 15;

	public:
		StatShr(const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const Sbecore::ubigint jrefPre = 0, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefFafAWaypoint = 0, const bool pnlfafawaypointAvail = false, const Sbecore::ubigint jref1NConnection = 0, const Sbecore::ubigint jrefRef1NSegment = 0, const Sbecore::ubigint jrefEqp1NNode = 0, const bool pnleqp1nnodeAvail = false, const Sbecore::ubigint jrefMNLocation = 0, const Sbecore::ubigint jrefMNConnection = 0, const Sbecore::ubigint jrefOrgMNFlight = 0, const Sbecore::ubigint jrefEqpMNConnection = 0, const bool pnleqpmnconnectionAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixBrlyVExpstate;
		Sbecore::ubigint jrefPre;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefFafAWaypoint;
		bool pnlfafawaypointAvail;
		Sbecore::ubigint jref1NConnection;
		Sbecore::ubigint jrefRef1NSegment;
		Sbecore::ubigint jrefEqp1NNode;
		bool pnleqp1nnodeAvail;
		Sbecore::ubigint jrefMNLocation;
		Sbecore::ubigint jrefMNConnection;
		Sbecore::ubigint jrefOrgMNFlight;
		Sbecore::ubigint jrefEqpMNConnection;
		bool pnleqpmnconnectionAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyFltRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFltRecDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngBrlyFltRecData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalPnlfafawaypointAvail(DbsBrly* dbsbrly);
	bool evalPnleqp1nnodeAvail(DbsBrly* dbsbrly);
	bool evalPnleqpmnconnectionAvail(DbsBrly* dbsbrly);
	bool evalButRegularizeActive(DbsBrly* dbsbrly);

public:
	PnlBrlyFltRec(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyFltRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlyFltEqpMNConnection* pnleqpmnconnection;
	PnlBrlyFltOrgMNFlight* pnlorgmnflight;
	PnlBrlyFltMNConnection* pnlmnconnection;
	PnlBrlyFltMNLocation* pnlmnlocation;
	PnlBrlyFltEqp1NNode* pnleqp1nnode;
	PnlBrlyFltRef1NSegment* pnlref1nsegment;
	PnlBrlyFlt1NConnection* pnl1nconnection;
	PnlBrlyFltFafAWaypoint* pnlfafawaypoint;
	PnlBrlyFltDetail* pnldetail;
	PnlBrlyFltPre* pnlpre;

	BrlyMFlight recFlt;

	BrlyMFaflight recFaf;

	BrlyMEquipment recEqp;
	Sbecore::uint ixWSubsetEqp;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void minimize(DbsBrly* dbsbrly, const bool notif = false, DpchEngBrly** dpcheng = NULL);
	void regularize(DbsBrly* dbsbrly, const bool notif = false, DpchEngBrly** dpcheng = NULL);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyFltUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyFafUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyEqpUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyFlt_fafEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_ptyEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_hktEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyFlt_ttbEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyFlt_eqpEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_oprEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_inSbs(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
