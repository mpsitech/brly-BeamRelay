/**
	* \file CrdBrlyTtb.h
	* job handler for job CrdBrlyTtb (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef CRDBRLYTTB_H
#define CRDBRLYTTB_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include <sys/types.h>
#include <dirent.h>
// IP include.cust --- IEND

#include "JobBrlyIexFlt.h"
#include "PnlBrlyTtbList.h"
#include "PnlBrlyTtbHeadbar.h"
#include "PnlBrlyTtbRec.h"
#include "DlgBrlyTtbNew.h"
#include "DlgBrlyTtbImpflt.h"
#include "DlgBrlyTtbTrlorig.h"

#define VecVBrlyTtbDo CrdBrlyTtb::VecVDo
#define VecVBrlyTtbSge CrdBrlyTtb::VecVSge

#define ContInfBrlyTtb CrdBrlyTtb::ContInf
#define StatAppBrlyTtb CrdBrlyTtb::StatApp
#define StatShrBrlyTtb CrdBrlyTtb::StatShr
#define TagBrlyTtb CrdBrlyTtb::Tag

#define DpchAppBrlyTtbDo CrdBrlyTtb::DpchAppDo
#define DpchEngBrlyTtbData CrdBrlyTtb::DpchEngData

/**
	* CrdBrlyTtb
	*/
class CrdBrlyTtb : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyTtbDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDTRLCLICK = 4;
		static const Sbecore::uint MITCRDIFLCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyTtbSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRBRLYABT = 2;
		static const Sbecore::uint IMPIDLE = 3;
		static const Sbecore::uint IMPORT = 4;
		static const Sbecore::uint IMPDONE = 5;
		static const Sbecore::uint SEGMENT = 6;
		static const Sbecore::uint SEGDONE = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfBrlyTtb)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDTTB = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdTtb = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdTtb;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyTtb)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrBrlyTtb)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JREFDLGIMPFLT = 1;
		static const Sbecore::uint JREFDLGNEW = 2;
		static const Sbecore::uint JREFDLGTRLORIG = 3;
		static const Sbecore::uint JREFHEADBAR = 4;
		static const Sbecore::uint JREFLIST = 5;
		static const Sbecore::uint JREFREC = 6;
		static const Sbecore::uint MSPCRD1AVAIL = 7;
		static const Sbecore::uint MITCRDNEWAVAIL = 8;
		static const Sbecore::uint MITCRDTRLAVAIL = 9;
		static const Sbecore::uint MITCRDIFLAVAIL = 10;
		static const Sbecore::uint MITCRDIFLACTIVE = 11;

	public:
		StatShr(const Sbecore::ubigint jrefDlgimpflt = 0, const Sbecore::ubigint jrefDlgnew = 0, const Sbecore::ubigint jrefDlgtrlorig = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdTrlAvail = true, const bool MitCrdIflAvail = true, const bool MitCrdIflActive = true);

	public:
		Sbecore::ubigint jrefDlgimpflt;
		Sbecore::ubigint jrefDlgnew;
		Sbecore::ubigint jrefDlgtrlorig;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdTrlAvail;
		bool MitCrdIflAvail;
		bool MitCrdIflActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyTtb)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyTtbDo)
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
		* DpchEngData (full: DpchEngBrlyTtbData)
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
	bool evalMitCrdTrlAvail(DbsBrly* dbsbrly);
	bool evalMitCrdIflAvail(DbsBrly* dbsbrly);
	bool evalMitCrdIflActive(DbsBrly* dbsbrly);

public:
	CrdBrlyTtb(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale, const Sbecore::ubigint ref = 0);
	~CrdBrlyTtb();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFSge;

	JobBrlyIexFlt* iex;
	PnlBrlyTtbList* pnllist;
	PnlBrlyTtbHeadbar* pnlheadbar;
	PnlBrlyTtbRec* pnlrec;
	DlgBrlyTtbNew* dlgnew;
	DlgBrlyTtbImpflt* dlgimpflt;
	DlgBrlyTtbTrlorig* dlgtrlorig;

	// IP vars.cust --- IBEGIN
	std::string infolder;
	unsigned int fltcnt;

	Sbecore::uint start;
	Sbecore::uint stop;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	void stats1_dump(DbsBrly* dbsbrly, const std::vector<Sbecore::ubigint>& refsLeg1, const std::vector<Sbecore::ubigint>& refsLeg2);
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
	bool handleImportFA(DbsBrly* dbsbrly);
	bool handleSegment(DbsBrly* dbsbrly);
	bool handleStats1(DbsBrly* dbsbrly);
	bool handleValidate(DbsBrly* dbsbrly);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleDpchAppDoClose(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdNewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdTrlClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitCrdIflClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

	void handleTimerInSgeImpidle(DbsBrly* dbsbrly, const std::string& sref);
	void handleTimerWithSrefMonInSgeImport(DbsBrly* dbsbrly);
	void handleTimerWithSrefMonInSgeSegment(DbsBrly* dbsbrly);

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
	Sbecore::uint enterSgeImpidle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImpidle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeImport(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImport(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeImpdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImpdone(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeSegment(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeSegment(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeSegdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeSegdone(DbsBrly* dbsbrly);

};

#endif
