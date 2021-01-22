/**
	* \file PnlBrlyLocRec.h
	* job handler for job PnlBrlyLocRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYLOCREC_H
#define PNLBRLYLOCREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlBrlyLocEqpMNConnection.h"
#include "PnlBrlyLocProxOrgMNLocation.h"
#include "PnlBrlyLocVisOrgMNLocation.h"
#include "PnlBrlyLocMNLeg.h"
#include "PnlBrlyLocMNFlight.h"
#include "PnlBrlyLocMNSegment.h"
#include "PnlBrlyLocEqp1NNode.h"
#include "PnlBrlyLocEnd1NLeg.h"
#include "PnlBrlyLocBgn1NLeg.h"
#include "PnlBrlyLocMap.h"
#include "PnlBrlyLocDetail.h"

#define VecVBrlyLocRecDo PnlBrlyLocRec::VecVDo

#define ContInfBrlyLocRec PnlBrlyLocRec::ContInf
#define StatAppBrlyLocRec PnlBrlyLocRec::StatApp
#define StatShrBrlyLocRec PnlBrlyLocRec::StatShr
#define TagBrlyLocRec PnlBrlyLocRec::Tag

#define DpchAppBrlyLocRecDo PnlBrlyLocRec::DpchAppDo
#define DpchEngBrlyLocRecData PnlBrlyLocRec::DpchEngData

/**
	* PnlBrlyLocRec
	*/
class PnlBrlyLocRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLocRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLocRec)
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
		* StatApp (full: StatAppBrlyLocRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneMap = false, const bool initdoneBgn1NLeg = false, const bool initdoneEnd1NLeg = false, const bool initdoneEqp1NNode = false, const bool initdoneMNSegment = false, const bool initdoneMNFlight = false, const bool initdoneMNLeg = false, const bool initdoneVisOrgMNLocation = false, const bool initdoneProxOrgMNLocation = false, const bool initdoneEqpMNConnection = false);
	};

	/**
		* StatShr (full: StatShrBrlyLocRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXBRLYVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFMAP = 3;
		static const Sbecore::uint JREFBGN1NLEG = 4;
		static const Sbecore::uint PNLBGN1NLEGAVAIL = 5;
		static const Sbecore::uint JREFEND1NLEG = 6;
		static const Sbecore::uint PNLEND1NLEGAVAIL = 7;
		static const Sbecore::uint JREFEQP1NNODE = 8;
		static const Sbecore::uint PNLEQP1NNODEAVAIL = 9;
		static const Sbecore::uint JREFMNSEGMENT = 10;
		static const Sbecore::uint JREFMNFLIGHT = 11;
		static const Sbecore::uint JREFMNLEG = 12;
		static const Sbecore::uint JREFVISORGMNLOCATION = 13;
		static const Sbecore::uint JREFPROXORGMNLOCATION = 14;
		static const Sbecore::uint JREFEQPMNCONNECTION = 15;
		static const Sbecore::uint PNLEQPMNCONNECTIONAVAIL = 16;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 17;

	public:
		StatShr(const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefMap = 0, const Sbecore::ubigint jrefBgn1NLeg = 0, const bool pnlbgn1nlegAvail = false, const Sbecore::ubigint jrefEnd1NLeg = 0, const bool pnlend1nlegAvail = false, const Sbecore::ubigint jrefEqp1NNode = 0, const bool pnleqp1nnodeAvail = false, const Sbecore::ubigint jrefMNSegment = 0, const Sbecore::ubigint jrefMNFlight = 0, const Sbecore::ubigint jrefMNLeg = 0, const Sbecore::ubigint jrefVisOrgMNLocation = 0, const Sbecore::ubigint jrefProxOrgMNLocation = 0, const Sbecore::ubigint jrefEqpMNConnection = 0, const bool pnleqpmnconnectionAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixBrlyVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefMap;
		Sbecore::ubigint jrefBgn1NLeg;
		bool pnlbgn1nlegAvail;
		Sbecore::ubigint jrefEnd1NLeg;
		bool pnlend1nlegAvail;
		Sbecore::ubigint jrefEqp1NNode;
		bool pnleqp1nnodeAvail;
		Sbecore::ubigint jrefMNSegment;
		Sbecore::ubigint jrefMNFlight;
		Sbecore::ubigint jrefMNLeg;
		Sbecore::ubigint jrefVisOrgMNLocation;
		Sbecore::ubigint jrefProxOrgMNLocation;
		Sbecore::ubigint jrefEqpMNConnection;
		bool pnleqpmnconnectionAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyLocRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocRecDo)
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
		* DpchEngData (full: DpchEngBrlyLocRecData)
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

	bool evalPnlbgn1nlegAvail(DbsBrly* dbsbrly);
	bool evalPnlend1nlegAvail(DbsBrly* dbsbrly);
	bool evalPnleqp1nnodeAvail(DbsBrly* dbsbrly);
	bool evalPnleqpmnconnectionAvail(DbsBrly* dbsbrly);
	bool evalButRegularizeActive(DbsBrly* dbsbrly);

public:
	PnlBrlyLocRec(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyLocRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlyLocEqpMNConnection* pnleqpmnconnection;
	PnlBrlyLocProxOrgMNLocation* pnlproxorgmnlocation;
	PnlBrlyLocVisOrgMNLocation* pnlvisorgmnlocation;
	PnlBrlyLocMNLeg* pnlmnleg;
	PnlBrlyLocMNFlight* pnlmnflight;
	PnlBrlyLocMNSegment* pnlmnsegment;
	PnlBrlyLocEqp1NNode* pnleqp1nnode;
	PnlBrlyLocEnd1NLeg* pnlend1nleg;
	PnlBrlyLocBgn1NLeg* pnlbgn1nleg;
	PnlBrlyLocMap* pnlmap;
	PnlBrlyLocDetail* pnldetail;

	BrlyMLocation recLoc;
	Sbecore::uint ixWSubsetLoc;

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
	bool handleCallBrlyLocUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyEqpUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyLoc_eqpEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_oprEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyLoc_typEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyLoc_inSbs(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyEqp_ptyEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_inSbs(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyEqp_hktEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
