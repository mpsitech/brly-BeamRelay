/**
	* \file PnlBrlyRegRec.h
	* job handler for job PnlBrlyRegRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYREGREC_H
#define PNLBRLYREGREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlBrlyRegSup1NRegion.h"
#include "PnlBrlyReg1NLocation.h"
#include "PnlBrlyRegADstswitch.h"
#include "PnlBrlyRegDetail.h"

#define VecVBrlyRegRecDo PnlBrlyRegRec::VecVDo

#define ContInfBrlyRegRec PnlBrlyRegRec::ContInf
#define StatAppBrlyRegRec PnlBrlyRegRec::StatApp
#define StatShrBrlyRegRec PnlBrlyRegRec::StatShr
#define TagBrlyRegRec PnlBrlyRegRec::Tag

#define DpchAppBrlyRegRecDo PnlBrlyRegRec::DpchAppDo
#define DpchEngBrlyRegRecData PnlBrlyRegRec::DpchEngData

/**
	* PnlBrlyRegRec
	*/
class PnlBrlyRegRec : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyRegRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyRegRec)
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
		* StatApp (full: StatAppBrlyRegRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneADstswitch = false, const bool initdone1NLocation = false, const bool initdoneSup1NRegion = false);
	};

	/**
		* StatShr (full: StatShrBrlyRegRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXBRLYVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFADSTSWITCH = 3;
		static const Sbecore::uint JREF1NLOCATION = 4;
		static const Sbecore::uint PNL1NLOCATIONAVAIL = 5;
		static const Sbecore::uint JREFSUP1NREGION = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefADstswitch = 0, const Sbecore::ubigint jref1NLocation = 0, const bool pnl1nlocationAvail = false, const Sbecore::ubigint jrefSup1NRegion = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixBrlyVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefADstswitch;
		Sbecore::ubigint jref1NLocation;
		bool pnl1nlocationAvail;
		Sbecore::ubigint jrefSup1NRegion;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyRegRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyRegRecDo)
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
		* DpchEngData (full: DpchEngBrlyRegRecData)
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

	bool evalPnl1nlocationAvail(DbsBrly* dbsbrly);
	bool evalButRegularizeActive(DbsBrly* dbsbrly);

public:
	PnlBrlyRegRec(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyRegRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlBrlyRegSup1NRegion* pnlsup1nregion;
	PnlBrlyReg1NLocation* pnl1nlocation;
	PnlBrlyRegADstswitch* pnladstswitch;
	PnlBrlyRegDetail* pnldetail;

	BrlyMRegion recReg;
	Sbecore::uint ixWSubsetReg;

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
	bool handleCallBrlyRegUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyReg_isLeaf(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, bool& boolvalRet);
	bool handleCallBrlyReg_supEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyReg_inSbs(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
