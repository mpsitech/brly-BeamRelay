/**
	* \file CrdBrlyFlt.h
	* job handler for job CrdBrlyFlt (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef CRDBRLYFLT_H
#define CRDBRLYFLT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlBrlyFltList.h"
#include "PnlBrlyFltHeadbar.h"
#include "PnlBrlyFltRec.h"

#define VecVBrlyFltDo CrdBrlyFlt::VecVDo
#define VecVBrlyFltSge CrdBrlyFlt::VecVSge

#define ContInfBrlyFlt CrdBrlyFlt::ContInf
#define StatAppBrlyFlt CrdBrlyFlt::StatApp
#define StatShrBrlyFlt CrdBrlyFlt::StatShr
#define TagBrlyFlt CrdBrlyFlt::Tag

#define DpchAppBrlyFltDo CrdBrlyFlt::DpchAppDo
#define DpchEngBrlyFltData CrdBrlyFlt::DpchEngData

/**
	* CrdBrlyFlt
	*/
class CrdBrlyFlt : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyFltDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyFltSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRBRLYABT = 2;
		static const Sbecore::uint COLLECT = 3;
		static const Sbecore::uint COLDONE = 4;
		static const Sbecore::uint PLOT = 5;
		static const Sbecore::uint PLTDONE = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfBrlyFlt)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDFLT = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdFlt = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdFlt;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyFlt)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrBrlyFlt)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFHEADBAR = 1;
		static const Sbecore::uint JREFLIST = 2;
		static const Sbecore::uint JREFREC = 3;

	public:
		StatShr(const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0);

	public:
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyFlt)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFltDo)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngBrlyFltData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

public:
	CrdBrlyFlt(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale, const Sbecore::ubigint ref = 0);
	~CrdBrlyFlt();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlBrlyFltList* pnllist;
	PnlBrlyFltHeadbar* pnlheadbar;
	PnlBrlyFltRec* pnlrec;

	// IP vars.cust --- IBEGIN
	bool con;
	bool seg;
	bool capacity;
	bool pReach;
	std::string arena;
	std::string srefsKEqptype;
	Sbecore::uint start;
	Sbecore::uint stop;
	Sbecore::uint dt;

	Sbecore::ubigint refBrlyMFile;
	bool vid;
	Sbecore::uint tIx;
	Sbecore::uint frmrate;
	bool fullsize;
	bool grayscale;
	double altzmax;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void changeRef(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint ref, const bool notif = false);
	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:
	bool handleDnscollect(DbsBrly* dbsbrly);
	bool handleDnsplot(DbsBrly* dbsbrly);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleDpchAppDoClose(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyRefPreSet(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool handleCallBrlyDlgClose(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);

private:
	void changeStage(DbsBrly* dbsbrly, Sbecore::uint _ixVSge, DpchEngBrly** dpcheng = NULL);

public:
	std::string getSquawk(DbsBrly* dbsbrly);

private:
	Sbecore::uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeAlrbrlyabt(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeAlrbrlyabt(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCollect(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCollect(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeColdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeColdone(DbsBrly* dbsbrly);
	Sbecore::uint enterSgePlot(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgePlot(DbsBrly* dbsbrly);
	Sbecore::uint enterSgePltdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgePltdone(DbsBrly* dbsbrly);

};

#endif
