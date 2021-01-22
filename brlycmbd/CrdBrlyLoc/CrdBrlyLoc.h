/**
	* \file CrdBrlyLoc.h
	* job handler for job CrdBrlyLoc (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef CRDBRLYLOC_H
#define CRDBRLYLOC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlBrlyLocList.h"
#include "PnlBrlyLocHeadbar.h"
#include "PnlBrlyLocRec.h"

#define VecVBrlyLocDo CrdBrlyLoc::VecVDo
#define VecVBrlyLocSge CrdBrlyLoc::VecVSge

#define ContInfBrlyLoc CrdBrlyLoc::ContInf
#define StatAppBrlyLoc CrdBrlyLoc::StatApp
#define StatShrBrlyLoc CrdBrlyLoc::StatShr
#define TagBrlyLoc CrdBrlyLoc::Tag

#define DpchAppBrlyLocDo CrdBrlyLoc::DpchAppDo
#define DpchEngBrlyLocData CrdBrlyLoc::DpchEngData

/**
	* CrdBrlyLoc
	*/
class CrdBrlyLoc : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLocDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyLocSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRBRLYABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfBrlyLoc)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDLOC = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdLoc = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdLoc;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyLoc)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrBrlyLoc)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

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
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyLoc)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocDo)
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
		* DpchEngData (full: DpchEngBrlyLocData)
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

public:
	CrdBrlyLoc(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale, const Sbecore::ubigint ref = 0);
	~CrdBrlyLoc();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFSge;

	PnlBrlyLocList* pnllist;
	PnlBrlyLocHeadbar* pnlheadbar;
	PnlBrlyLocRec* pnlrec;

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	double degToRad(double _deg);
	void locToRad(BrlyMLocation* loc);

	inline double evalDfaprDalphagpr(const double re, const double af, const double alphag, const double eg, const double alphagpr0);
	inline double evalFapr(const double re, const double af, const double alphag, const double eg, const double alphagpr0);
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
	bool handleVisgraph(DbsBrly* dbsbrly);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

	void handleDpchAppDoClose(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

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

};

#endif
