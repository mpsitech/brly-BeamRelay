/**
	* \file PnlBrlyLegRec.h
	* job handler for job PnlBrlyLegRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYLEGREC_H
#define PNLBRLYLEGREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlBrlyLegOrgMNLeg.h"
#include "PnlBrlyLegMNLocation.h"
#include "PnlBrlyLegCor1NConnection.h"
#include "PnlBrlyLeg1NFlight.h"
#include "PnlBrlyLegMap.h"
#include "PnlBrlyLegDetail.h"
#include "PnlBrlyLegPre.h"

#define VecVBrlyLegRecDo PnlBrlyLegRec::VecVDo

#define ContInfBrlyLegRec PnlBrlyLegRec::ContInf
#define StatAppBrlyLegRec PnlBrlyLegRec::StatApp
#define StatShrBrlyLegRec PnlBrlyLegRec::StatShr
#define TagBrlyLegRec PnlBrlyLegRec::Tag

#define DpchAppBrlyLegRecDo PnlBrlyLegRec::DpchAppDo
#define DpchEngBrlyLegRecData PnlBrlyLegRec::DpchEngData

/**
	* PnlBrlyLegRec
	*/
class PnlBrlyLegRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLegRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLegRec)
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
		* StatApp (full: StatAppBrlyLegRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneMap = false, const bool initdone1NFlight = false, const bool initdoneCor1NConnection = false, const bool initdoneMNLocation = false, const bool initdoneOrgMNLeg = false);
	};

	/**
		* StatShr (full: StatShrBrlyLegRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXBRLYVEXPSTATE = 1;
		static const Sbecore::uint JREFPRE = 2;
		static const Sbecore::uint JREFDETAIL = 3;
		static const Sbecore::uint JREFMAP = 4;
		static const Sbecore::uint JREF1NFLIGHT = 5;
		static const Sbecore::uint PNL1NFLIGHTAVAIL = 6;
		static const Sbecore::uint JREFCOR1NCONNECTION = 7;
		static const Sbecore::uint PNLCOR1NCONNECTIONAVAIL = 8;
		static const Sbecore::uint JREFMNLOCATION = 9;
		static const Sbecore::uint JREFORGMNLEG = 10;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 11;

	public:
		StatShr(const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const Sbecore::ubigint jrefPre = 0, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefMap = 0, const Sbecore::ubigint jref1NFlight = 0, const bool pnl1nflightAvail = false, const Sbecore::ubigint jrefCor1NConnection = 0, const bool pnlcor1nconnectionAvail = false, const Sbecore::ubigint jrefMNLocation = 0, const Sbecore::ubigint jrefOrgMNLeg = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixBrlyVExpstate;
		Sbecore::ubigint jrefPre;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefMap;
		Sbecore::ubigint jref1NFlight;
		bool pnl1nflightAvail;
		Sbecore::ubigint jrefCor1NConnection;
		bool pnlcor1nconnectionAvail;
		Sbecore::ubigint jrefMNLocation;
		Sbecore::ubigint jrefOrgMNLeg;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyLegRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLegRecDo)
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
		* DpchEngData (full: DpchEngBrlyLegRecData)
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

	bool evalPnl1nflightAvail(DbsBrly* dbsbrly);
	bool evalPnlcor1nconnectionAvail(DbsBrly* dbsbrly);
	bool evalButRegularizeActive(DbsBrly* dbsbrly);

public:
	PnlBrlyLegRec(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyLegRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlyLegOrgMNLeg* pnlorgmnleg;
	PnlBrlyLegMNLocation* pnlmnlocation;
	PnlBrlyLegCor1NConnection* pnlcor1nconnection;
	PnlBrlyLeg1NFlight* pnl1nflight;
	PnlBrlyLegMap* pnlmap;
	PnlBrlyLegDetail* pnldetail;
	PnlBrlyLegPre* pnlpre;

	BrlyMLeg recLeg;
	Sbecore::uint ixWSubsetLeg;

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
	bool handleCallBrlyLegUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyLeg_cluEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyLeg_typEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyLeg_inSbs(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
