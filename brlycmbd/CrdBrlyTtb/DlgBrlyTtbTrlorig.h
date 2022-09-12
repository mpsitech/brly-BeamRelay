/**
	* \file DlgBrlyTtbTrlorig.h
	* job handler for job DlgBrlyTtbTrlorig (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef DLGBRLYTTBTRLORIG_H
#define DLGBRLYTTBTRLORIG_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgBrlyTtbTrlorigDit DlgBrlyTtbTrlorig::VecVDit
#define VecVDlgBrlyTtbTrlorigDo DlgBrlyTtbTrlorig::VecVDo
#define VecVDlgBrlyTtbTrlorigDoTrl DlgBrlyTtbTrlorig::VecVDoTrl
#define VecVDlgBrlyTtbTrlorigSge DlgBrlyTtbTrlorig::VecVSge
#define VecVDlgBrlyTtbTrlorigSrc DlgBrlyTtbTrlorig::VecVSrc

#define ContIacDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::ContIac
#define ContIacDlgBrlyTtbTrlorigDet DlgBrlyTtbTrlorig::ContIacDet
#define ContInfDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::ContInf
#define ContInfDlgBrlyTtbTrlorigTfi DlgBrlyTtbTrlorig::ContInfTfi
#define ContInfDlgBrlyTtbTrlorigTrl DlgBrlyTtbTrlorig::ContInfTrl
#define StatAppDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::StatApp
#define StatShrDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::StatShr
#define StatShrDlgBrlyTtbTrlorigRfi DlgBrlyTtbTrlorig::StatShrRfi
#define StatShrDlgBrlyTtbTrlorigTfi DlgBrlyTtbTrlorig::StatShrTfi
#define StatShrDlgBrlyTtbTrlorigTrl DlgBrlyTtbTrlorig::StatShrTrl
#define TagDlgBrlyTtbTrlorig DlgBrlyTtbTrlorig::Tag
#define TagDlgBrlyTtbTrlorigDet DlgBrlyTtbTrlorig::TagDet
#define TagDlgBrlyTtbTrlorigRfi DlgBrlyTtbTrlorig::TagRfi
#define TagDlgBrlyTtbTrlorigTfi DlgBrlyTtbTrlorig::TagTfi
#define TagDlgBrlyTtbTrlorigTrl DlgBrlyTtbTrlorig::TagTrl

#define DpchAppDlgBrlyTtbTrlorigData DlgBrlyTtbTrlorig::DpchAppData
#define DpchAppDlgBrlyTtbTrlorigDo DlgBrlyTtbTrlorig::DpchAppDo
#define DpchEngDlgBrlyTtbTrlorigData DlgBrlyTtbTrlorig::DpchEngData

/**
	* DlgBrlyTtbTrlorig
	*/
class DlgBrlyTtbTrlorig : public JobBrly {

public:
	/**
		* VecVDit (full: VecVDlgBrlyTtbTrlorigDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint RFI = 2;
		static const Sbecore::uint TRL = 3;
		static const Sbecore::uint TFI = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgBrlyTtbTrlorigDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoTrl (full: VecVDlgBrlyTtbTrlorigDoTrl)
		*/
	class VecVDoTrl {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyTtbTrlorigSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ULDDONE = 2;
		static const Sbecore::uint TRANSLATE = 3;
		static const Sbecore::uint DONE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVSrc (full: VecVDlgBrlyTtbTrlorigSrc)
		*/
	class VecVSrc {

	public:
		static const Sbecore::uint STAR = 1;
		static const Sbecore::uint OW = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyTtbTrlorig)
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
	  * ContIacDet (full: ContIacDlgBrlyTtbTrlorigDet)
	  */
	class ContIacDet : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPSRC = 1;

	public:
		ContIacDet(const Sbecore::uint numFPupSrc = 1);

	public:
		Sbecore::uint numFPupSrc;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyTtbTrlorig)
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
	  * ContInfTfi (full: ContInfDlgBrlyTtbTrlorigTfi)
	  */
	class ContInfTfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfTfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfTfi* comp);
		std::set<Sbecore::uint> diff(const ContInfTfi* comp);
	};

	/**
	  * ContInfTrl (full: ContInfDlgBrlyTtbTrlorigTrl)
	  */
	class ContInfTrl : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfTrl(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfTrl* comp);
		std::set<Sbecore::uint> diff(const ContInfTrl* comp);
	};

	/**
		* StatApp (full: StatAppDlgBrlyTtbTrlorig)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgBrlyTtbTrlorig)
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
		* StatShrRfi (full: StatShrDlgBrlyTtbTrlorigRfi)
		*/
	class StatShrRfi : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrRfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrRfi* comp);
		std::set<Sbecore::uint> diff(const StatShrRfi* comp);
	};

	/**
		* StatShrTfi (full: StatShrDlgBrlyTtbTrlorigTfi)
		*/
	class StatShrTfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrTfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrTfi* comp);
		std::set<Sbecore::uint> diff(const StatShrTfi* comp);
	};

	/**
		* StatShrTrl (full: StatShrDlgBrlyTtbTrlorigTrl)
		*/
	class StatShrTrl : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrTrl(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrTrl* comp);
		std::set<Sbecore::uint> diff(const StatShrTrl* comp);
	};

	/**
		* Tag (full: TagDlgBrlyTtbTrlorig)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgBrlyTtbTrlorigDet)
		*/
	class TagDet {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagRfi (full: TagDlgBrlyTtbTrlorigRfi)
		*/
	class TagRfi {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagTfi (full: TagDlgBrlyTtbTrlorigTfi)
		*/
	class TagTfi {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagTrl (full: TagDlgBrlyTtbTrlorigTrl)
		*/
	class TagTrl {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyTtbTrlorigData)
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
		* DpchAppDo (full: DpchAppDlgBrlyTtbTrlorigDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOTRL = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoTrl;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgBrlyTtbTrlorigData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint CONTINFTFI = 5;
		static const Sbecore::uint CONTINFTRL = 6;
		static const Sbecore::uint FEEDFDETPUPSRC = 7;
		static const Sbecore::uint FEEDFDSE = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint STATSHRRFI = 12;
		static const Sbecore::uint STATSHRTFI = 13;
		static const Sbecore::uint STATSHRTRL = 14;
		static const Sbecore::uint TAG = 15;
		static const Sbecore::uint TAGDET = 16;
		static const Sbecore::uint TAGRFI = 17;
		static const Sbecore::uint TAGTFI = 18;
		static const Sbecore::uint TAGTRL = 19;
		static const Sbecore::uint ALL = 20;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, ContInfTfi* continftfi = NULL, ContInfTrl* continftrl = NULL, Sbecore::Feed* feedFDetPupSrc = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrRfi* statshrrfi = NULL, StatShrTfi* statshrtfi = NULL, StatShrTrl* statshrtrl = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfTfi continftfi;
		ContInfTrl continftrl;
		Sbecore::Feed feedFDetPupSrc;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrRfi statshrrfi;
		StatShrTfi statshrtfi;
		StatShrTrl statshrtrl;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsBrly* dbsbrly);
	bool evalTfiDldActive(DbsBrly* dbsbrly);
	bool evalTrlButRunActive(DbsBrly* dbsbrly);
	bool evalTrlButStoActive(DbsBrly* dbsbrly);
	bool evalRfiUldActive(DbsBrly* dbsbrly);

public:
	DlgBrlyTtbTrlorig(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~DlgBrlyTtbTrlorig();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	ContInfTfi continftfi;
	ContInfTrl continftrl;
	StatShr statshr;
	StatShrRfi statshrrfi;
	StatShrTfi statshrtfi;
	StatShrTrl statshrtrl;

	Sbecore::Feed feedFDetPupSrc;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshDet(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshRfi(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshTrl(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshTfi(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiacdet(DbsBrly* dbsbrly, ContIacDet* _contiacdet, DpchEngBrly** dpcheng);

	void handleDpchAppDoButDneClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleDpchAppDoTrlButRunClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoTrlButStoClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	void handleUploadInSgeIdle(DbsBrly* dbsbrly, const std::string& filename);

	std::string handleDownload(DbsBrly* dbsbrly);

private:
	void changeStage(DbsBrly* dbsbrly, Sbecore::uint _ixVSge, DpchEngBrly** dpcheng = NULL);

public:
	std::string getSquawk(DbsBrly* dbsbrly);

private:
	Sbecore::uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeUlddone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeUlddone(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeTranslate(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeTranslate(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

};

#endif
