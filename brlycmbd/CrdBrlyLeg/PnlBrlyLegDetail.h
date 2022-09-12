/**
	* \file PnlBrlyLegDetail.h
	* job handler for job PnlBrlyLegDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYLEGDETAIL_H
#define PNLBRLYLEGDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyLegDetailDo PnlBrlyLegDetail::VecVDo

#define ContIacBrlyLegDetail PnlBrlyLegDetail::ContIac
#define ContInfBrlyLegDetail PnlBrlyLegDetail::ContInf
#define StatAppBrlyLegDetail PnlBrlyLegDetail::StatApp
#define StatShrBrlyLegDetail PnlBrlyLegDetail::StatShr
#define TagBrlyLegDetail PnlBrlyLegDetail::Tag

#define DpchAppBrlyLegDetailData PnlBrlyLegDetail::DpchAppData
#define DpchAppBrlyLegDetailDo PnlBrlyLegDetail::DpchAppDo
#define DpchEngBrlyLegDetailData PnlBrlyLegDetail::DpchEngData

/**
	* PnlBrlyLegDetail
	*/
class PnlBrlyLegDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLegDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyLegDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint TXFALT = 3;
		static const Sbecore::uint TXFDPH = 4;
		static const Sbecore::uint TXFAPH = 5;
		static const Sbecore::uint TXFXAL = 6;
		static const Sbecore::uint TXFXP0 = 7;
		static const Sbecore::uint TXFXP1 = 8;
		static const Sbecore::uint TXFXAP = 9;
		static const Sbecore::uint CHKCDN = 10;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFLstClu = 1, const std::string& TxfAlt = "", const std::string& TxfDph = "", const std::string& TxfAph = "", const std::string& TxfXal = "", const std::string& TxfXp0 = "", const std::string& TxfXp1 = "", const std::string& TxfXap = "", const bool ChkCdn = false);

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFLstClu;
		std::string TxfAlt;
		std::string TxfDph;
		std::string TxfAph;
		std::string TxfXal;
		std::string TxfXp0;
		std::string TxfXp1;
		std::string TxfXap;
		bool ChkCdn;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyLegDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTBLO = 1;
		static const Sbecore::uint TXTELO = 2;
		static const Sbecore::uint TXTCLU = 3;

	public:
		ContInf(const std::string& TxtBlo = "", const std::string& TxtElo = "", const std::string& TxtClu = "");

	public:
		std::string TxtBlo;
		std::string TxtElo;
		std::string TxtClu;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyLegDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstCluAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstCluAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyLegDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTBLOACTIVE = 3;
		static const Sbecore::uint TXTELOACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint LSTCLUACTIVE = 6;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 7;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 8;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 9;
		static const Sbecore::uint TXFALTACTIVE = 10;
		static const Sbecore::uint TXFDPHACTIVE = 11;
		static const Sbecore::uint TXFAPHACTIVE = 12;
		static const Sbecore::uint TXFXALACTIVE = 13;
		static const Sbecore::uint TXFXP0ACTIVE = 14;
		static const Sbecore::uint TXFXP1ACTIVE = 15;
		static const Sbecore::uint TXFXAPACTIVE = 16;
		static const Sbecore::uint CHKCDNACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtBloActive = true, const bool TxtEloActive = true, const bool PupTypActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxfAltActive = true, const bool TxfDphActive = true, const bool TxfAphActive = true, const bool TxfXalActive = true, const bool TxfXp0Active = true, const bool TxfXp1Active = true, const bool TxfXapActive = true, const bool ChkCdnActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtBloActive;
		bool TxtEloActive;
		bool PupTypActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxfAltActive;
		bool TxfDphActive;
		bool TxfAphActive;
		bool TxfXalActive;
		bool TxfXp0Active;
		bool TxfXp1Active;
		bool TxfXapActive;
		bool ChkCdnActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyLegDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLegDetailData)
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
		* DpchAppDo (full: DpchAppBrlyLegDetailDo)
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
		* DpchEngData (full: DpchEngBrlyLegDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstClu = NULL, Sbecore::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFPupTyp;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtBloActive(DbsBrly* dbsbrly);
	bool evalTxtEloActive(DbsBrly* dbsbrly);
	bool evalPupTypActive(DbsBrly* dbsbrly);
	bool evalLstCluActive(DbsBrly* dbsbrly);
	bool evalButCluViewActive(DbsBrly* dbsbrly);
	bool evalButCluClusterAvail(DbsBrly* dbsbrly);
	bool evalButCluUnclusterAvail(DbsBrly* dbsbrly);
	bool evalTxfAltActive(DbsBrly* dbsbrly);
	bool evalTxfDphActive(DbsBrly* dbsbrly);
	bool evalTxfAphActive(DbsBrly* dbsbrly);
	bool evalTxfXalActive(DbsBrly* dbsbrly);
	bool evalTxfXp0Active(DbsBrly* dbsbrly);
	bool evalTxfXp1Active(DbsBrly* dbsbrly);
	bool evalTxfXapActive(DbsBrly* dbsbrly);
	bool evalChkCdnActive(DbsBrly* dbsbrly);

public:
	PnlBrlyLegDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyLegDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstClu;
	Sbecore::Feed feedFPupTyp;

	BrlyMLeg recLeg;
	Sbecore::uint ixWSubsetLeg;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstClu(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshClu(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refreshRecLeg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButCluViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButCluClusterClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButCluUnclusterClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyLegMod_cluEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyLegUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyLeg_typEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyLeg_inSbs(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyLeg_cluEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
