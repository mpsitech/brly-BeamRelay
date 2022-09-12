/**
	* \file DlgBrlyLegNew.h
	* job handler for job DlgBrlyLegNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef DLGBRLYLEGNEW_H
#define DLGBRLYLEGNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgBrlyLegNewDit DlgBrlyLegNew::VecVDit
#define VecVDlgBrlyLegNewDo DlgBrlyLegNew::VecVDo
#define VecVDlgBrlyLegNewDoDet DlgBrlyLegNew::VecVDoDet
#define VecVDlgBrlyLegNewDoInc DlgBrlyLegNew::VecVDoInc
#define VecVDlgBrlyLegNewSge DlgBrlyLegNew::VecVSge

#define ContIacDlgBrlyLegNew DlgBrlyLegNew::ContIac
#define ContIacDlgBrlyLegNewDet DlgBrlyLegNew::ContIacDet
#define ContInfDlgBrlyLegNew DlgBrlyLegNew::ContInf
#define ContInfDlgBrlyLegNewInc DlgBrlyLegNew::ContInfInc
#define StatAppDlgBrlyLegNew DlgBrlyLegNew::StatApp
#define StatShrDlgBrlyLegNew DlgBrlyLegNew::StatShr
#define StatShrDlgBrlyLegNewDet DlgBrlyLegNew::StatShrDet
#define StatShrDlgBrlyLegNewInc DlgBrlyLegNew::StatShrInc
#define TagDlgBrlyLegNew DlgBrlyLegNew::Tag
#define TagDlgBrlyLegNewDet DlgBrlyLegNew::TagDet
#define TagDlgBrlyLegNewInc DlgBrlyLegNew::TagInc

#define DpchAppDlgBrlyLegNewData DlgBrlyLegNew::DpchAppData
#define DpchAppDlgBrlyLegNewDo DlgBrlyLegNew::DpchAppDo
#define DpchEngDlgBrlyLegNewData DlgBrlyLegNew::DpchEngData

/**
	* DlgBrlyLegNew
	*/
class DlgBrlyLegNew : public JobBrly {

public:
	/**
		* VecVDit (full: VecVDlgBrlyLegNewDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint INC = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgBrlyLegNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgBrlyLegNewDoDet)
		*/
	class VecVDoDet {

	public:
		static const Sbecore::uint BUTCRECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoInc (full: VecVDlgBrlyLegNewDoInc)
		*/
	class VecVDoInc {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyLegNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint CREDONE = 3;
		static const Sbecore::uint INCO = 4;
		static const Sbecore::uint DONE = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyLegNew)
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
	  * ContIacDet (full: ContIacDlgBrlyLegNewDet)
	  */
	class ContIacDet : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint TXFBGN = 2;
		static const Sbecore::uint TXFEND = 3;

	public:
		ContIacDet(const Sbecore::uint numFPupTyp = 1, const std::string& TxfBgn = "", const std::string& TxfEnd = "");

	public:
		Sbecore::uint numFPupTyp;
		std::string TxfBgn;
		std::string TxfEnd;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyLegNew)
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
	  * ContInfInc (full: ContInfDlgBrlyLegNewInc)
	  */
	class ContInfInc : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfInc(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfInc* comp);
		std::set<Sbecore::uint> diff(const ContInfInc* comp);
	};

	/**
		* StatApp (full: StatAppDlgBrlyLegNew)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgBrlyLegNew)
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
		* StatShrDet (full: StatShrDlgBrlyLegNewDet)
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
		* StatShrInc (full: StatShrDlgBrlyLegNewInc)
		*/
	class StatShrInc : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrInc(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrInc* comp);
		std::set<Sbecore::uint> diff(const StatShrInc* comp);
	};

	/**
		* Tag (full: TagDlgBrlyLegNew)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgBrlyLegNewDet)
		*/
	class TagDet {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagInc (full: TagDlgBrlyLegNewInc)
		*/
	class TagInc {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyLegNewData)
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
		* DpchAppDo (full: DpchAppDlgBrlyLegNewDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDODET = 3;
		static const Sbecore::uint IXVDOINC = 4;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoDet;
		Sbecore::uint ixVDoInc;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyLegNewData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint CONTINFINC = 5;
		static const Sbecore::uint FEEDFDETPUPTYP = 6;
		static const Sbecore::uint FEEDFDSE = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint STATSHRDET = 11;
		static const Sbecore::uint STATSHRINC = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint TAGDET = 14;
		static const Sbecore::uint TAGINC = 15;
		static const Sbecore::uint ALL = 16;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, ContInfInc* continfinc = NULL, Sbecore::Feed* feedFDetPupTyp = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrDet* statshrdet = NULL, StatShrInc* statshrinc = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfInc continfinc;
		Sbecore::Feed feedFDetPupTyp;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrDet statshrdet;
		StatShrInc statshrinc;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalIncButRunActive(DbsBrly* dbsbrly);
	bool evalIncButStoActive(DbsBrly* dbsbrly);
	bool evalButDneActive(DbsBrly* dbsbrly);
	bool evalDetButCreActive(DbsBrly* dbsbrly);

public:
	DlgBrlyLegNew(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~DlgBrlyLegNew();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	ContInfInc continfinc;
	StatShr statshr;
	StatShrDet statshrdet;
	StatShrInc statshrinc;

	Sbecore::Feed feedFDetPupTyp;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	Sbecore::uint ixVDit;

	bool valid;

	// IP vars.cust --- INSERT

public:
// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	void sphrToCart(double _r, double _theta, double _phi, double** _vec);
	double degToRad(double _deg);
	double radToDeg(double _rad);
// IP cust --- IEND

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshDet(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshInc(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiacdet(DbsBrly* dbsbrly, ContIacDet* _contiacdet, DpchEngBrly** dpcheng);

	void handleDpchAppDoButDneClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoDetButCreClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoIncButRunClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoIncButStoClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleTimerWithSrefMonInSgeInco(DbsBrly* dbsbrly);

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
	Sbecore::uint enterSgeInco(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeInco(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

};

#endif
