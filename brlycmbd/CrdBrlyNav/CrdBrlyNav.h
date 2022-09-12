/**
	* \file CrdBrlyNav.h
	* job handler for job CrdBrlyNav (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef CRDBRLYNAV_H
#define CRDBRLYNAV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlBrlyNavConnect.h"
#include "PnlBrlyNavBase.h"
#include "PnlBrlyNavAdmin.h"
#include "PnlBrlyNavHeadbar.h"
#include "DlgBrlyNavLoaini.h"

#define VecVBrlyNavDo CrdBrlyNav::VecVDo
#define VecVBrlyNavSge CrdBrlyNav::VecVSge

#define ContInfBrlyNav CrdBrlyNav::ContInf
#define StatAppBrlyNav CrdBrlyNav::StatApp
#define StatShrBrlyNav CrdBrlyNav::StatShr
#define TagBrlyNav CrdBrlyNav::Tag

#define DpchAppBrlyNavDo CrdBrlyNav::DpchAppDo
#define DpchEngBrlyNavData CrdBrlyNav::DpchEngData

/**
	* CrdBrlyNav
	*/
class CrdBrlyNav : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyNavDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITSESSPSCLICK = 3;
		static const Sbecore::uint MITSESTRMCLICK = 4;
		static const Sbecore::uint MITCRDUSGCLICK = 5;
		static const Sbecore::uint MITCRDUSRCLICK = 6;
		static const Sbecore::uint MITCRDPRSCLICK = 7;
		static const Sbecore::uint MITCRDFILCLICK = 8;
		static const Sbecore::uint MITCRDOPRCLICK = 9;
		static const Sbecore::uint MITCRDPTYCLICK = 10;
		static const Sbecore::uint MITCRDREGCLICK = 11;
		static const Sbecore::uint MITCRDLOCCLICK = 12;
		static const Sbecore::uint MITCRDLEGCLICK = 13;
		static const Sbecore::uint MITCRDTTBCLICK = 14;
		static const Sbecore::uint MITCRDFLTCLICK = 15;
		static const Sbecore::uint MITCRDSEGCLICK = 16;
		static const Sbecore::uint MITCRDCONCLICK = 17;
		static const Sbecore::uint MITCRDRLYCLICK = 18;
		static const Sbecore::uint MITAPPLOICLICK = 19;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyNavSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRBRLYABT = 2;
		static const Sbecore::uint ALRBRLYTRM = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfBrlyNav)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXSESSES1 = 3;
		static const Sbecore::uint MTXSESSES2 = 4;
		static const Sbecore::uint MTXSESSES3 = 5;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxSesSes1 = "", const std::string& MtxSesSes2 = "", const std::string& MtxSesSes3 = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxSesSes1;
		std::string MtxSesSes2;
		std::string MtxSesSes3;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyNav)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneAdmin = false, const bool initdoneBase = false, const bool initdoneConnect = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneAdmin = false, const bool initdoneBase = false, const bool initdoneConnect = false);
	};

	/**
		* StatShr (full: StatShrBrlyNav)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFDLGLOAINI = 1;
		static const Sbecore::uint JREFHEADBAR = 2;
		static const Sbecore::uint JREFADMIN = 3;
		static const Sbecore::uint PNLADMINAVAIL = 4;
		static const Sbecore::uint JREFBASE = 5;
		static const Sbecore::uint PNLBASEAVAIL = 6;
		static const Sbecore::uint JREFCONNECT = 7;
		static const Sbecore::uint PNLCONNECTAVAIL = 8;
		static const Sbecore::uint MITSESSPSAVAIL = 9;
		static const Sbecore::uint MSPCRD1AVAIL = 10;
		static const Sbecore::uint MITCRDUSGAVAIL = 11;
		static const Sbecore::uint MITCRDUSRAVAIL = 12;
		static const Sbecore::uint MITCRDPRSAVAIL = 13;
		static const Sbecore::uint MITCRDFILAVAIL = 14;
		static const Sbecore::uint MITCRDOPRAVAIL = 15;
		static const Sbecore::uint MITCRDPTYAVAIL = 16;
		static const Sbecore::uint MSPCRD2AVAIL = 17;
		static const Sbecore::uint MITCRDREGAVAIL = 18;
		static const Sbecore::uint MITCRDLOCAVAIL = 19;
		static const Sbecore::uint MITCRDLEGAVAIL = 20;
		static const Sbecore::uint MITCRDTTBAVAIL = 21;
		static const Sbecore::uint MITCRDFLTAVAIL = 22;
		static const Sbecore::uint MITCRDSEGAVAIL = 23;
		static const Sbecore::uint MSPCRD3AVAIL = 24;
		static const Sbecore::uint MITCRDCONAVAIL = 25;
		static const Sbecore::uint MITCRDRLYAVAIL = 26;
		static const Sbecore::uint MSPAPP2AVAIL = 27;
		static const Sbecore::uint MITAPPLOIAVAIL = 28;

	public:
		StatShr(const Sbecore::ubigint jrefDlgloaini = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefAdmin = 0, const bool pnladminAvail = false, const Sbecore::ubigint jrefBase = 0, const bool pnlbaseAvail = false, const Sbecore::ubigint jrefConnect = 0, const bool pnlconnectAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdFilAvail = true, const bool MitCrdOprAvail = true, const bool MitCrdPtyAvail = true, const bool MspCrd2Avail = true, const bool MitCrdRegAvail = true, const bool MitCrdLocAvail = true, const bool MitCrdLegAvail = true, const bool MitCrdTtbAvail = true, const bool MitCrdFltAvail = true, const bool MitCrdSegAvail = true, const bool MspCrd3Avail = true, const bool MitCrdConAvail = true, const bool MitCrdRlyAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		Sbecore::ubigint jrefDlgloaini;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefAdmin;
		bool pnladminAvail;
		Sbecore::ubigint jrefBase;
		bool pnlbaseAvail;
		Sbecore::ubigint jrefConnect;
		bool pnlconnectAvail;
		bool MitSesSpsAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdFilAvail;
		bool MitCrdOprAvail;
		bool MitCrdPtyAvail;
		bool MspCrd2Avail;
		bool MitCrdRegAvail;
		bool MitCrdLocAvail;
		bool MitCrdLegAvail;
		bool MitCrdTtbAvail;
		bool MitCrdFltAvail;
		bool MitCrdSegAvail;
		bool MspCrd3Avail;
		bool MitCrdConAvail;
		bool MitCrdRlyAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyNav)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyNavDo)
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
		* DpchEngData (full: DpchEngBrlyNavData)
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

	bool evalPnladminAvail(DbsBrly* dbsbrly);
	bool evalPnlbaseAvail(DbsBrly* dbsbrly);
	bool evalPnlconnectAvail(DbsBrly* dbsbrly);
	bool evalMitSesSpsAvail(DbsBrly* dbsbrly);
	bool evalMspCrd1Avail(DbsBrly* dbsbrly);
	bool evalMitCrdUsgAvail(DbsBrly* dbsbrly);
	bool evalMitCrdUsrAvail(DbsBrly* dbsbrly);
	bool evalMitCrdPrsAvail(DbsBrly* dbsbrly);
	bool evalMitCrdFilAvail(DbsBrly* dbsbrly);
	bool evalMitCrdOprAvail(DbsBrly* dbsbrly);
	bool evalMitCrdPtyAvail(DbsBrly* dbsbrly);
	bool evalMspCrd2Avail(DbsBrly* dbsbrly);
	bool evalMitCrdRegAvail(DbsBrly* dbsbrly);
	bool evalMitCrdLocAvail(DbsBrly* dbsbrly);
	bool evalMitCrdLegAvail(DbsBrly* dbsbrly);
	bool evalMitCrdTtbAvail(DbsBrly* dbsbrly);
	bool evalMitCrdFltAvail(DbsBrly* dbsbrly);
	bool evalMitCrdSegAvail(DbsBrly* dbsbrly);
	bool evalMspCrd3Avail(DbsBrly* dbsbrly);
	bool evalMitCrdConAvail(DbsBrly* dbsbrly);
	bool evalMitCrdRlyAvail(DbsBrly* dbsbrly);
	bool evalMspApp2Avail(DbsBrly* dbsbrly);
	bool evalMitAppLoiAvail(DbsBrly* dbsbrly);

public:
	CrdBrlyNav(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~CrdBrlyNav();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlBrlyNavConnect* pnlconnect;
	PnlBrlyNavBase* pnlbase;
	PnlBrlyNavAdmin* pnladmin;
	PnlBrlyNavHeadbar* pnlheadbar;
	DlgBrlyNavLoaini* dlgloaini;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void warnTerm(DbsBrly* dbsbrly);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleDpchAppDoClose(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitSesSpsClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitSesTrmClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdUsgClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdUsrClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdPrsClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdFilClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdOprClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdPtyClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdRegClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdLocClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdLegClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdTtbClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdFltClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdSegClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdConClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdRlyClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitAppLoiClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyDlgClose(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);

private:
	void changeStage(DbsBrly* dbsbrly, Sbecore::uint _ixVSge, DpchEngBrly** dpcheng = NULL);

public:
	std::string getSquawk(DbsBrly* dbsbrly);

private:
	Sbecore::uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeAlrbrlyabt(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeAlrbrlyabt(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeAlrbrlytrm(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeAlrbrlytrm(DbsBrly* dbsbrly);

};

#endif
