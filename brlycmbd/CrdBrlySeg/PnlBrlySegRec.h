/**
	* \file PnlBrlySegRec.h
	* job handler for job PnlBrlySegRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYSEGREC_H
#define PNLBRLYSEGREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlBrlySegMNConnection.h"
#include "PnlBrlySegMNLocation.h"
#include "PnlBrlySegOrgMNSegment.h"
#include "PnlBrlySegDetail.h"
#include "PnlBrlySegPre.h"

#define VecVBrlySegRecDo PnlBrlySegRec::VecVDo

#define ContInfBrlySegRec PnlBrlySegRec::ContInf
#define StatAppBrlySegRec PnlBrlySegRec::StatApp
#define StatShrBrlySegRec PnlBrlySegRec::StatShr
#define TagBrlySegRec PnlBrlySegRec::Tag

#define DpchAppBrlySegRecDo PnlBrlySegRec::DpchAppDo
#define DpchEngBrlySegRecData PnlBrlySegRec::DpchEngData

/**
	* PnlBrlySegRec
	*/
class PnlBrlySegRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlySegRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlySegRec)
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
		* StatApp (full: StatAppBrlySegRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneOrgMNSegment = false, const bool initdoneMNLocation = false, const bool initdoneMNConnection = false);
	};

	/**
		* StatShr (full: StatShrBrlySegRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXBRLYVEXPSTATE = 1;
		static const Sbecore::uint JREFPRE = 2;
		static const Sbecore::uint JREFDETAIL = 3;
		static const Sbecore::uint JREFORGMNSEGMENT = 4;
		static const Sbecore::uint JREFMNLOCATION = 5;
		static const Sbecore::uint JREFMNCONNECTION = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const Sbecore::ubigint jrefPre = 0, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefOrgMNSegment = 0, const Sbecore::ubigint jrefMNLocation = 0, const Sbecore::ubigint jrefMNConnection = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixBrlyVExpstate;
		Sbecore::ubigint jrefPre;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefOrgMNSegment;
		Sbecore::ubigint jrefMNLocation;
		Sbecore::ubigint jrefMNConnection;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlySegRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlySegRecDo)
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
		* DpchEngData (full: DpchEngBrlySegRecData)
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
	PnlBrlySegRec(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlySegRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlySegMNConnection* pnlmnconnection;
	PnlBrlySegMNLocation* pnlmnlocation;
	PnlBrlySegOrgMNSegment* pnlorgmnsegment;
	PnlBrlySegDetail* pnldetail;
	PnlBrlySegPre* pnlpre;

	BrlyMSegment recSeg;

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
	bool handleCallBrlySegUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlySeg_reuEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlySeg_retEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
