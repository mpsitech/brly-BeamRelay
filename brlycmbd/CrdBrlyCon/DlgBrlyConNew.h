/**
	* \file DlgBrlyConNew.h
	* job handler for job DlgBrlyConNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef DLGBRLYCONNEW_H
#define DLGBRLYCONNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgBrlyConNewDit DlgBrlyConNew::VecVDit
#define VecVDlgBrlyConNewDo DlgBrlyConNew::VecVDo
#define VecVDlgBrlyConNewDoCal DlgBrlyConNew::VecVDoCal
#define VecVDlgBrlyConNewDoDet DlgBrlyConNew::VecVDoDet
#define VecVDlgBrlyConNewSge DlgBrlyConNew::VecVSge

#define ContIacDlgBrlyConNew DlgBrlyConNew::ContIac
#define ContIacDlgBrlyConNewDet DlgBrlyConNew::ContIacDet
#define ContInfDlgBrlyConNew DlgBrlyConNew::ContInf
#define ContInfDlgBrlyConNewCal DlgBrlyConNew::ContInfCal
#define StatAppDlgBrlyConNew DlgBrlyConNew::StatApp
#define StatShrDlgBrlyConNew DlgBrlyConNew::StatShr
#define StatShrDlgBrlyConNewCal DlgBrlyConNew::StatShrCal
#define StatShrDlgBrlyConNewDet DlgBrlyConNew::StatShrDet
#define TagDlgBrlyConNew DlgBrlyConNew::Tag
#define TagDlgBrlyConNewCal DlgBrlyConNew::TagCal
#define TagDlgBrlyConNewDet DlgBrlyConNew::TagDet

#define DpchAppDlgBrlyConNewData DlgBrlyConNew::DpchAppData
#define DpchAppDlgBrlyConNewDo DlgBrlyConNew::DpchAppDo
#define DpchEngDlgBrlyConNewData DlgBrlyConNew::DpchEngData

/**
	* DlgBrlyConNew
	*/
class DlgBrlyConNew : public JobBrly {

public:
	/**
		* VecVDit (full: VecVDlgBrlyConNewDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint CAL = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgBrlyConNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoCal (full: VecVDlgBrlyConNewDoCal)
		*/
	class VecVDoCal {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgBrlyConNewDoDet)
		*/
	class VecVDoDet {

	public:
		static const Sbecore::uint BUTCRECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyConNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint CREDONE = 3;
		static const Sbecore::uint CALC1 = 4;
		static const Sbecore::uint CALC2 = 5;
		static const Sbecore::uint CALC3 = 6;
		static const Sbecore::uint CALC4 = 7;
		static const Sbecore::uint DONE = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyConNew)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacDet (full: ContIacDlgBrlyConNewDet)
	  */
	class ContIacDet : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFFLT = 1;
		static const Sbecore::uint NUMFPUPMDL = 2;
		static const Sbecore::uint NUMFPUPTTB = 3;
		static const Sbecore::uint TXFETY = 4;

	public:
		ContIacDet(const std::string& TxfFlt = "", const Sbecore::uint numFPupMdl = 1, const Sbecore::uint numFPupTtb = 1, const std::string& TxfEty = "");

	public:
		std::string TxfFlt;
		Sbecore::uint numFPupMdl;
		Sbecore::uint numFPupTtb;
		std::string TxfEty;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyConNew)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfCal (full: ContInfDlgBrlyConNewCal)
	  */
	class ContInfCal : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfCal(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfCal* comp);
		std::set<Sbecore::uint> diff(const ContInfCal* comp);
	};

	/**
		* StatApp (full: StatAppDlgBrlyConNew)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgBrlyConNew)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StatShrCal (full: StatShrDlgBrlyConNewCal)
		*/
	class StatShrCal : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrCal(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrCal* comp);
		std::set<Sbecore::uint> diff(const StatShrCal* comp);
	};

	/**
		* StatShrDet (full: StatShrDlgBrlyConNewDet)
		*/
	class StatShrDet : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCREACTIVE = 1;

	public:
		StatShrDet(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrDet* comp);
		std::set<Sbecore::uint> diff(const StatShrDet* comp);
	};

	/**
		* Tag (full: TagDlgBrlyConNew)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagCal (full: TagDlgBrlyConNewCal)
		*/
	class TagCal {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgBrlyConNewDet)
		*/
	class TagDet {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyConNewData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgBrlyConNewDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOCAL = 3;
		static const Sbecore::uint IXVDODET = 4;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoCal;
		Sbecore::uint ixVDoDet;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyConNewData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint CONTINFCAL = 5;
		static const Sbecore::uint FEEDFDETPUPMDL = 6;
		static const Sbecore::uint FEEDFDETPUPTTB = 7;
		static const Sbecore::uint FEEDFDSE = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint STATSHRCAL = 12;
		static const Sbecore::uint STATSHRDET = 13;
		static const Sbecore::uint TAG = 14;
		static const Sbecore::uint TAGCAL = 15;
		static const Sbecore::uint TAGDET = 16;
		static const Sbecore::uint ALL = 17;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, ContInfCal* continfcal = NULL, Sbecore::Feed* feedFDetPupMdl = NULL, Sbecore::Feed* feedFDetPupTtb = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrCal* statshrcal = NULL, StatShrDet* statshrdet = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfCal continfcal;
		Sbecore::Feed feedFDetPupMdl;
		Sbecore::Feed feedFDetPupTtb;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrCal statshrcal;
		StatShrDet statshrdet;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalCalButRunActive(DbsBrly* dbsbrly);
	bool evalCalButStoActive(DbsBrly* dbsbrly);
	bool evalButDneActive(DbsBrly* dbsbrly);
	bool evalDetButCreActive(DbsBrly* dbsbrly);

public:
	DlgBrlyConNew(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~DlgBrlyConNew();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	ContInfCal continfcal;
	StatShr statshr;
	StatShrCal statshrcal;
	StatShrDet statshrdet;

	Sbecore::Feed feedFDetPupMdl;
	Sbecore::Feed feedFDetPupTtb;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	Sbecore::uint ixVDit;

	bool valid;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshDet(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshCal(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiacdet(DbsBrly* dbsbrly, ContIacDet* _contiacdet, DpchEngBrly** dpcheng);

	void handleDpchAppDoButDneClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoCalButRunClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoCalButStoClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoDetButCreClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleTimerWithSrefMonInSgeCalc2(DbsBrly* dbsbrly);

private:
	void changeStage(DbsBrly* dbsbrly, Sbecore::uint _ixVSge, DpchEngBrly** dpcheng = NULL);

public:
	std::string getSquawk(DbsBrly* dbsbrly);

private:
	Sbecore::uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCreate(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCreate(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCredone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCredone(DbsBrly* dbsbrly);
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
