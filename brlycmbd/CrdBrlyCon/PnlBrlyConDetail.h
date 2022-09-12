/**
	* \file PnlBrlyConDetail.h
	* job handler for job PnlBrlyConDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYCONDETAIL_H
#define PNLBRLYCONDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyConDetailDo PnlBrlyConDetail::VecVDo

#define ContIacBrlyConDetail PnlBrlyConDetail::ContIac
#define ContInfBrlyConDetail PnlBrlyConDetail::ContInf
#define StatAppBrlyConDetail PnlBrlyConDetail::StatApp
#define StatShrBrlyConDetail PnlBrlyConDetail::StatShr
#define TagBrlyConDetail PnlBrlyConDetail::Tag

#define DpchAppBrlyConDetailData PnlBrlyConDetail::DpchAppData
#define DpchAppBrlyConDetailDo PnlBrlyConDetail::DpchAppDo
#define DpchEngBrlyConDetailData PnlBrlyConDetail::DpchEngData

/**
	* PnlBrlyConDetail
	*/
class PnlBrlyConDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyConDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTFLTVIEWCLICK = 2;
		static const Sbecore::uint BUTTTBVIEWCLICK = 3;
		static const Sbecore::uint BUTETYEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyConDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFSTA = 1;
		static const Sbecore::uint TXFSTO = 2;
		static const Sbecore::uint NUMFPUPMOD = 3;
		static const Sbecore::uint NUMSFLSTETY = 4;
		static const Sbecore::uint TXFETY = 5;

	public:
		ContIac(const std::string& TxfSta = "", const std::string& TxfSto = "", const Sbecore::uint numFPupMod = 1, const std::vector<Sbecore::uint>& numsFLstEty = {}, const std::string& TxfEty = "");

	public:
		std::string TxfSta;
		std::string TxfSto;
		Sbecore::uint numFPupMod;
		std::vector<Sbecore::uint> numsFLstEty;
		std::string TxfEty;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyConDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTFLT = 1;
		static const Sbecore::uint TXTCOR = 2;
		static const Sbecore::uint TXTTTB = 3;

	public:
		ContInf(const std::string& TxtFlt = "", const std::string& TxtCor = "", const std::string& TxtTtb = "");

	public:
		std::string TxtFlt;
		std::string TxtCor;
		std::string TxtTtb;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyConDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstEtyAlt = true, const Sbecore::uint LstEtyNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstEtyAlt = true, const Sbecore::uint LstEtyNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyConDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFETYVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTFLTACTIVE = 4;
		static const Sbecore::uint BUTFLTVIEWAVAIL = 5;
		static const Sbecore::uint BUTFLTVIEWACTIVE = 6;
		static const Sbecore::uint TXTCORACTIVE = 7;
		static const Sbecore::uint TXFSTAACTIVE = 8;
		static const Sbecore::uint TXFSTOACTIVE = 9;
		static const Sbecore::uint PUPMODACTIVE = 10;
		static const Sbecore::uint TXTTTBACTIVE = 11;
		static const Sbecore::uint BUTTTBVIEWAVAIL = 12;
		static const Sbecore::uint BUTTTBVIEWACTIVE = 13;
		static const Sbecore::uint LSTETYACTIVE = 14;
		static const Sbecore::uint BUTETYEDITAVAIL = 15;

	public:
		StatShr(const bool TxfEtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtFltActive = true, const bool ButFltViewAvail = true, const bool ButFltViewActive = true, const bool TxtCorActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool PupModActive = true, const bool TxtTtbActive = true, const bool ButTtbViewAvail = true, const bool ButTtbViewActive = true, const bool LstEtyActive = true, const bool ButEtyEditAvail = true);

	public:
		bool TxfEtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtFltActive;
		bool ButFltViewAvail;
		bool ButFltViewActive;
		bool TxtCorActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool PupModActive;
		bool TxtTtbActive;
		bool ButTtbViewAvail;
		bool ButTtbViewActive;
		bool LstEtyActive;
		bool ButEtyEditAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyConDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyConDetailData)
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
		* DpchAppDo (full: DpchAppBrlyConDetailDo)
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
		* DpchEngData (full: DpchEngBrlyConDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTETY = 4;
		static const Sbecore::uint FEEDFPUPMOD = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstEty = NULL, Sbecore::Feed* feedFPupMod = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstEty;
		Sbecore::Feed feedFPupMod;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtFltActive(DbsBrly* dbsbrly);
	bool evalButFltViewAvail(DbsBrly* dbsbrly);
	bool evalButFltViewActive(DbsBrly* dbsbrly);
	bool evalTxtCorActive(DbsBrly* dbsbrly);
	bool evalTxfStaActive(DbsBrly* dbsbrly);
	bool evalTxfStoActive(DbsBrly* dbsbrly);
	bool evalPupModActive(DbsBrly* dbsbrly);
	bool evalTxtTtbActive(DbsBrly* dbsbrly);
	bool evalButTtbViewAvail(DbsBrly* dbsbrly);
	bool evalButTtbViewActive(DbsBrly* dbsbrly);
	bool evalLstEtyActive(DbsBrly* dbsbrly);
	bool evalButEtyEditAvail(DbsBrly* dbsbrly);

public:
	PnlBrlyConDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyConDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstEty;
	Sbecore::Feed feedFPupMod;

	BrlyMConnection recCon;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstEty(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshTxfEty(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshEty(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refreshRecCon(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFltViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButTtbViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEtyEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyKlsAkeyMod_klsEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallBrlyConUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyCon_ttbEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyCon_fltEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
