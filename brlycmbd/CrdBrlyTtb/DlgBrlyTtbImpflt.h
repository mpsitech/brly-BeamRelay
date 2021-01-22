/**
	* \file DlgBrlyTtbImpflt.h
	* job handler for job DlgBrlyTtbImpflt (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef DLGBRLYTTBIMPFLT_H
#define DLGBRLYTTBIMPFLT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobBrlyIexTtb.h"

#define VecVDlgBrlyTtbImpfltDit DlgBrlyTtbImpflt::VecVDit
#define VecVDlgBrlyTtbImpfltDo DlgBrlyTtbImpflt::VecVDo
#define VecVDlgBrlyTtbImpfltDoImp DlgBrlyTtbImpflt::VecVDoImp
#define VecVDlgBrlyTtbImpfltDoPpr DlgBrlyTtbImpflt::VecVDoPpr
#define VecVDlgBrlyTtbImpfltSge DlgBrlyTtbImpflt::VecVSge

#define ContIacDlgBrlyTtbImpflt DlgBrlyTtbImpflt::ContIac
#define ContInfDlgBrlyTtbImpflt DlgBrlyTtbImpflt::ContInf
#define ContInfDlgBrlyTtbImpfltImp DlgBrlyTtbImpflt::ContInfImp
#define ContInfDlgBrlyTtbImpfltLfi DlgBrlyTtbImpflt::ContInfLfi
#define ContInfDlgBrlyTtbImpfltPpr DlgBrlyTtbImpflt::ContInfPpr
#define StatAppDlgBrlyTtbImpflt DlgBrlyTtbImpflt::StatApp
#define StatShrDlgBrlyTtbImpflt DlgBrlyTtbImpflt::StatShr
#define StatShrDlgBrlyTtbImpfltIfi DlgBrlyTtbImpflt::StatShrIfi
#define StatShrDlgBrlyTtbImpfltImp DlgBrlyTtbImpflt::StatShrImp
#define StatShrDlgBrlyTtbImpfltLfi DlgBrlyTtbImpflt::StatShrLfi
#define StatShrDlgBrlyTtbImpfltPpr DlgBrlyTtbImpflt::StatShrPpr
#define TagDlgBrlyTtbImpflt DlgBrlyTtbImpflt::Tag
#define TagDlgBrlyTtbImpfltIfi DlgBrlyTtbImpflt::TagIfi
#define TagDlgBrlyTtbImpfltImp DlgBrlyTtbImpflt::TagImp
#define TagDlgBrlyTtbImpfltLfi DlgBrlyTtbImpflt::TagLfi
#define TagDlgBrlyTtbImpfltPpr DlgBrlyTtbImpflt::TagPpr

#define DpchAppDlgBrlyTtbImpfltData DlgBrlyTtbImpflt::DpchAppData
#define DpchAppDlgBrlyTtbImpfltDo DlgBrlyTtbImpflt::DpchAppDo
#define DpchEngDlgBrlyTtbImpfltData DlgBrlyTtbImpflt::DpchEngData

/**
	* DlgBrlyTtbImpflt
	*/
class DlgBrlyTtbImpflt : public JobBrly {

public:
	/**
		* VecVDit (full: VecVDlgBrlyTtbImpfltDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint IFI = 1;
		static const Sbecore::uint IMP = 2;
		static const Sbecore::uint PPR = 3;
		static const Sbecore::uint LFI = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgBrlyTtbImpfltDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgBrlyTtbImpfltDoImp)
		*/
	class VecVDoImp {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoPpr (full: VecVDlgBrlyTtbImpfltDoPpr)
		*/
	class VecVDoPpr {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyTtbImpfltSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint PRSIDLE = 2;
		static const Sbecore::uint PARSE = 3;
		static const Sbecore::uint ALRBRLYPER = 4;
		static const Sbecore::uint PRSDONE = 5;
		static const Sbecore::uint IMPIDLE = 6;
		static const Sbecore::uint IMPORT = 7;
		static const Sbecore::uint IMPDONE = 8;
		static const Sbecore::uint POSTPRC = 9;
		static const Sbecore::uint DONE = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyTtbImpflt)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyTtbImpflt)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfImp (full: ContInfDlgBrlyTtbImpfltImp)
	  */
	class ContInfImp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfImp(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfImp* comp);
		std::set<Sbecore::uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgBrlyTtbImpfltLfi)
	  */
	class ContInfLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfLfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfLfi* comp);
		std::set<Sbecore::uint> diff(const ContInfLfi* comp);
	};

	/**
	  * ContInfPpr (full: ContInfDlgBrlyTtbImpfltPpr)
	  */
	class ContInfPpr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfPpr(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfPpr* comp);
		std::set<Sbecore::uint> diff(const ContInfPpr* comp);
	};

	/**
		* StatApp (full: StatAppDlgBrlyTtbImpflt)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgBrlyTtbImpflt)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StatShrIfi (full: StatShrDlgBrlyTtbImpfltIfi)
		*/
	class StatShrIfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrIfi* comp);
		std::set<Sbecore::uint> diff(const StatShrIfi* comp);
	};

	/**
		* StatShrImp (full: StatShrDlgBrlyTtbImpfltImp)
		*/
	class StatShrImp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrImp* comp);
		std::set<Sbecore::uint> diff(const StatShrImp* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgBrlyTtbImpfltLfi)
		*/
	class StatShrLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrLfi* comp);
		std::set<Sbecore::uint> diff(const StatShrLfi* comp);
	};

	/**
		* StatShrPpr (full: StatShrDlgBrlyTtbImpfltPpr)
		*/
	class StatShrPpr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrPpr(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrPpr* comp);
		std::set<Sbecore::uint> diff(const StatShrPpr* comp);
	};

	/**
		* Tag (full: TagDlgBrlyTtbImpflt)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagIfi (full: TagDlgBrlyTtbImpfltIfi)
		*/
	class TagIfi {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagImp (full: TagDlgBrlyTtbImpfltImp)
		*/
	class TagImp {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgBrlyTtbImpfltLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagPpr (full: TagDlgBrlyTtbImpfltPpr)
		*/
	class TagPpr {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyTtbImpfltData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgBrlyTtbImpfltDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOIMP = 3;
		static const Sbecore::uint IXVDOPPR = 4;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoImp;
		Sbecore::uint ixVDoPpr;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyTtbImpfltData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFIMP = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint CONTINFPPR = 6;
		static const Sbecore::uint FEEDFDSE = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint STATSHRIFI = 11;
		static const Sbecore::uint STATSHRIMP = 12;
		static const Sbecore::uint STATSHRLFI = 13;
		static const Sbecore::uint STATSHRPPR = 14;
		static const Sbecore::uint TAG = 15;
		static const Sbecore::uint TAGIFI = 16;
		static const Sbecore::uint TAGIMP = 17;
		static const Sbecore::uint TAGLFI = 18;
		static const Sbecore::uint TAGPPR = 19;
		static const Sbecore::uint ALL = 20;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfImp* continfimp = NULL, ContInfLfi* continflfi = NULL, ContInfPpr* continfppr = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrIfi* statshrifi = NULL, StatShrImp* statshrimp = NULL, StatShrLfi* statshrlfi = NULL, StatShrPpr* statshrppr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfLfi continflfi;
		ContInfPpr continfppr;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;
		StatShrPpr statshrppr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsBrly* dbsbrly);
	bool evalLfiDldActive(DbsBrly* dbsbrly);
	bool evalPprButRunActive(DbsBrly* dbsbrly);
	bool evalPprButStoActive(DbsBrly* dbsbrly);
	bool evalImpButRunActive(DbsBrly* dbsbrly);
	bool evalImpButStoActive(DbsBrly* dbsbrly);
	bool evalIfiUldActive(DbsBrly* dbsbrly);

public:
	DlgBrlyTtbImpflt(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~DlgBrlyTtbImpflt();

public:
	ContIac contiac;
	ContInf continf;
	ContInfImp continfimp;
	ContInfLfi continflfi;
	ContInfPpr continfppr;
	StatShr statshr;
	StatShrIfi statshrifi;
	StatShrImp statshrimp;
	StatShrLfi statshrlfi;
	StatShrPpr statshrppr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	JobBrlyIexTtb* iex;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshIfi(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshImp(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshPpr(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButDneClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoImpButRunClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoImpButStoClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoPprButRunClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoPprButStoClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppBrlyAlert(DbsBrly* dbsbrly, DpchAppBrlyAlert* dpchappbrlyalert, DpchEngBrly** dpcheng);

	void handleUploadInSgeIdle(DbsBrly* dbsbrly, const std::string& filename);

	std::string handleDownload(DbsBrly* dbsbrly);

	void handleTimerWithSrefMonInSgePostprc(DbsBrly* dbsbrly);
	void handleTimerInSgePrsidle(DbsBrly* dbsbrly, const std::string& sref);
	void handleTimerInSgeImpidle(DbsBrly* dbsbrly, const std::string& sref);
	void handleTimerWithSrefMonInSgeImport(DbsBrly* dbsbrly);

private:
	void changeStage(DbsBrly* dbsbrly, Sbecore::uint _ixVSge, DpchEngBrly** dpcheng = NULL);

public:
	std::string getSquawk(DbsBrly* dbsbrly);

private:
	Sbecore::uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgePrsidle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgePrsidle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeParse(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeParse(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeAlrbrlyper(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeAlrbrlyper(DbsBrly* dbsbrly);
	Sbecore::uint enterSgePrsdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgePrsdone(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeImpidle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImpidle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeImport(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImport(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeImpdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImpdone(DbsBrly* dbsbrly);
	Sbecore::uint enterSgePostprc(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgePostprc(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

};

#endif
