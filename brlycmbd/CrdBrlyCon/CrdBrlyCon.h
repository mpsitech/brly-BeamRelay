/**
	* \file CrdBrlyCon.h
	* job handler for job CrdBrlyCon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef CRDBRLYCON_H
#define CRDBRLYCON_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlBrlyConList.h"
#include "PnlBrlyConHeadbar.h"
#include "PnlBrlyConRec.h"
#include "DlgBrlyConNew.h"

#define VecVBrlyConDo CrdBrlyCon::VecVDo
#define VecVBrlyConSge CrdBrlyCon::VecVSge

#define ContInfBrlyCon CrdBrlyCon::ContInf
#define StatAppBrlyCon CrdBrlyCon::StatApp
#define StatShrBrlyCon CrdBrlyCon::StatShr
#define TagBrlyCon CrdBrlyCon::Tag

#define DpchAppBrlyConDo CrdBrlyCon::DpchAppDo
#define DpchEngBrlyConData CrdBrlyCon::DpchEngData

/**
	* CrdBrlyCon
	*/
class CrdBrlyCon : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyConDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyConSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRBRLYABT = 2;
		static const Sbecore::uint CRGIDLE = 3;
		static const Sbecore::uint CORRGEN = 4;
		static const Sbecore::uint CORRCALC = 5;
		static const Sbecore::uint CRGDONE = 6;
		static const Sbecore::uint CONGEN = 7;
		static const Sbecore::uint CNGDONE = 8;
		static const Sbecore::uint CALC1 = 9;
		static const Sbecore::uint CALC2 = 10;
		static const Sbecore::uint CALC3 = 11;
		static const Sbecore::uint CALC4 = 12;
		static const Sbecore::uint DONE = 13;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfBrlyCon)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDCON = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdCon = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdCon;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyCon)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrBrlyCon)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JREFDLGNEW = 1;
		static const Sbecore::uint JREFHEADBAR = 2;
		static const Sbecore::uint JREFLIST = 3;
		static const Sbecore::uint JREFREC = 4;
		static const Sbecore::uint MSPCRD1AVAIL = 5;
		static const Sbecore::uint MITCRDNEWAVAIL = 6;

	public:
		StatShr(const Sbecore::ubigint jrefDlgnew = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true);

	public:
		Sbecore::ubigint jrefDlgnew;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyCon)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyConDo)
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
		* DpchEngData (full: DpchEngBrlyConData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalMspCrd1Avail(DbsBrly* dbsbrly);
	bool evalMitCrdNewAvail(DbsBrly* dbsbrly);

public:
	CrdBrlyCon(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale, const Sbecore::ubigint ref = 0);
	~CrdBrlyCon();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFSge;

	PnlBrlyConList* pnllist;
	PnlBrlyConHeadbar* pnlheadbar;
	PnlBrlyConRec* pnlrec;
	DlgBrlyConNew* dlgnew;

	// IP vars.cust --- IBEGIN
	std::string arena;
	unsigned int date;

	ListBrlyMLeg rts;
	ListBrlyMLeg corrs;
	ListBrlyMConnection cons;
	ListBrlyMFlight flts;

	std::string svgfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	void wrBgseg(std::fstream& outfile, const unsigned int start, const unsigned int mode, double x, const double y, double width, const double height);

	double radToDeg(double _rad);
	// IP cust --- IEND

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void changeRef(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint ref, const bool notif = false);
	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:
	bool handleBargraph(DbsBrly* dbsbrly);
	bool handleCalc(DbsBrly* dbsbrly);
	bool handleCleanup1(DbsBrly* dbsbrly);
	bool handleCleanup2(DbsBrly* dbsbrly);
	bool handleCongen(DbsBrly* dbsbrly);
	bool handleCorrgen(DbsBrly* dbsbrly);
	bool handleLineup(DbsBrly* dbsbrly);
	bool handlePickup(DbsBrly* dbsbrly);
	bool handleStats2(DbsBrly* dbsbrly);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleDpchAppDoClose(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdNewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

	void handleTimerWithSrefMonInSgeCorrcalc(DbsBrly* dbsbrly);
	void handleTimerWithSrefMonInSgeCalc1(DbsBrly* dbsbrly);
	void handleTimerWithSrefMonInSgeCalc2(DbsBrly* dbsbrly);
	void handleTimerWithSrefMonInSgeCalc3(DbsBrly* dbsbrly);
	void handleTimerWithSrefMonInSgeCalc4(DbsBrly* dbsbrly);
	void handleTimerInSgeCrgidle(DbsBrly* dbsbrly, const std::string& sref);
	void handleTimerWithSrefMonInSgeCorrgen(DbsBrly* dbsbrly);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyRefPreSet(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
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
	Sbecore::uint enterSgeCrgidle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCrgidle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCorrgen(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCorrgen(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCorrcalc(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCorrcalc(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCrgdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCrgdone(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCongen(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCongen(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCngdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCngdone(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCalc1(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc1(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCalc2(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc2(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCalc3(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc3(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCalc4(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCalc4(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

};

#endif
