/**
	* \file PnlBrlyConRec.h
	* job handler for job PnlBrlyConRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYCONREC_H
#define PNLBRLYCONREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlBrlyConMNSegment.h"
#include "PnlBrlyConMNFlight.h"
#include "PnlBrlyConConMNEquipment.h"
#include "PnlBrlyConRef1NSegment.h"
#include "PnlBrlyCon1NRelay.h"
#include "PnlBrlyConMap.h"
#include "PnlBrlyConDetail.h"
#include "PnlBrlyConPre.h"

#define VecVBrlyConRecDo PnlBrlyConRec::VecVDo

#define ContInfBrlyConRec PnlBrlyConRec::ContInf
#define StatAppBrlyConRec PnlBrlyConRec::StatApp
#define StatShrBrlyConRec PnlBrlyConRec::StatShr
#define TagBrlyConRec PnlBrlyConRec::Tag

#define DpchAppBrlyConRecDo PnlBrlyConRec::DpchAppDo
#define DpchEngBrlyConRecData PnlBrlyConRec::DpchEngData

/**
	* PnlBrlyConRec
	*/
class PnlBrlyConRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyConRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyConRec)
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
		* StatApp (full: StatAppBrlyConRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneMap = false, const bool initdone1NRelay = false, const bool initdoneRef1NSegment = false, const bool initdoneConMNEquipment = false, const bool initdoneMNFlight = false, const bool initdoneMNSegment = false);
	};

	/**
		* StatShr (full: StatShrBrlyConRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXBRLYVEXPSTATE = 1;
		static const Sbecore::uint JREFPRE = 2;
		static const Sbecore::uint JREFDETAIL = 3;
		static const Sbecore::uint JREFMAP = 4;
		static const Sbecore::uint JREF1NRELAY = 5;
		static const Sbecore::uint JREFREF1NSEGMENT = 6;
		static const Sbecore::uint JREFCONMNEQUIPMENT = 7;
		static const Sbecore::uint JREFMNFLIGHT = 8;
		static const Sbecore::uint JREFMNSEGMENT = 9;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 10;

	public:
		StatShr(const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const Sbecore::ubigint jrefPre = 0, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefMap = 0, const Sbecore::ubigint jref1NRelay = 0, const Sbecore::ubigint jrefRef1NSegment = 0, const Sbecore::ubigint jrefConMNEquipment = 0, const Sbecore::ubigint jrefMNFlight = 0, const Sbecore::ubigint jrefMNSegment = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixBrlyVExpstate;
		Sbecore::ubigint jrefPre;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefMap;
		Sbecore::ubigint jref1NRelay;
		Sbecore::ubigint jrefRef1NSegment;
		Sbecore::ubigint jrefConMNEquipment;
		Sbecore::ubigint jrefMNFlight;
		Sbecore::ubigint jrefMNSegment;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyConRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyConRecDo)
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
		* DpchEngData (full: DpchEngBrlyConRecData)
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

	bool evalButRegularizeActive(DbsBrly* dbsbrly);

public:
	PnlBrlyConRec(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyConRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlyConMNSegment* pnlmnsegment;
	PnlBrlyConMNFlight* pnlmnflight;
	PnlBrlyConConMNEquipment* pnlconmnequipment;
	PnlBrlyConRef1NSegment* pnlref1nsegment;
	PnlBrlyCon1NRelay* pnl1nrelay;
	PnlBrlyConMap* pnlmap;
	PnlBrlyConDetail* pnldetail;
	PnlBrlyConPre* pnlpre;

	BrlyMConnection recCon;

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
	bool handleCallBrlyConUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyCon_ttbEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyCon_fltEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
