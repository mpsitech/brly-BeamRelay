/**
	* \file DlgBrlyTtbNew.h
	* job handler for job DlgBrlyTtbNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef DLGBRLYTTBNEW_H
#define DLGBRLYTTBNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgBrlyTtbNewDo DlgBrlyTtbNew::VecVDo
#define VecVDlgBrlyTtbNewSge DlgBrlyTtbNew::VecVSge

#define ContIacDlgBrlyTtbNew DlgBrlyTtbNew::ContIac
#define ContInfDlgBrlyTtbNew DlgBrlyTtbNew::ContInf
#define StatAppDlgBrlyTtbNew DlgBrlyTtbNew::StatApp
#define StatShrDlgBrlyTtbNew DlgBrlyTtbNew::StatShr
#define TagDlgBrlyTtbNew DlgBrlyTtbNew::Tag

#define DpchAppDlgBrlyTtbNewData DlgBrlyTtbNew::DpchAppData
#define DpchAppDlgBrlyTtbNewDo DlgBrlyTtbNew::DpchAppDo
#define DpchEngDlgBrlyTtbNewData DlgBrlyTtbNew::DpchEngData

/**
	* DlgBrlyTtbNew
	*/
class DlgBrlyTtbNew : public JobBrly {

public:
	/**
		* VecVDo (full: VecVDlgBrlyTtbNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCNCCLICK = 1;
		static const Sbecore::uint BUTCRECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgBrlyTtbNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgBrlyTtbNew)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDETPUPALI = 1;
		static const Sbecore::uint DETTXFTIT = 2;
		static const Sbecore::uint DETTXFSTA = 3;
		static const Sbecore::uint DETTXFSTO = 4;

	public:
		ContIac(const Sbecore::uint numFDetPupAli = 1, const std::string& DetTxfTit = "", const std::string& DetTxfSta = "", const std::string& DetTxfSto = "");

	public:
		Sbecore::uint numFDetPupAli;
		std::string DetTxfTit;
		std::string DetTxfSta;
		std::string DetTxfSto;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgBrlyTtbNew)
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
		* StatApp (full: StatAppDlgBrlyTtbNew)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgBrlyTtbNew)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCNCACTIVE = 1;
		static const Sbecore::uint BUTCREACTIVE = 2;

	public:
		StatShr(const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool ButCncActive;
		bool ButCreActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgBrlyTtbNew)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgBrlyTtbNewData)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgBrlyTtbNewDo)
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
		* DpchEngData (full: DpchEngDlgBrlyTtbNewData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETPUPALI = 4;
		static const Sbecore::uint FEEDFSGE = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFDetPupAli = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFDetPupAli;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButCncActive(DbsBrly* dbsbrly);
	bool evalButCreActive(DbsBrly* dbsbrly);

public:
	DlgBrlyTtbNew(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~DlgBrlyTtbNew();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFDetPupAli;
	Sbecore::Feed feedFSge;

	bool valid;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButCncClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButCreClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

private:
	void changeStage(DbsBrly* dbsbrly, Sbecore::uint _ixVSge, DpchEngBrly** dpcheng = NULL);

public:
	std::string getSquawk(DbsBrly* dbsbrly);

private:
	Sbecore::uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCreate(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCreate(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

};

#endif
