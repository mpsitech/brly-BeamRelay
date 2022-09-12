/**
	* \file PnlBrlyFilDetail.h
	* job handler for job PnlBrlyFilDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYFILDETAIL_H
#define PNLBRLYFILDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyFilDetailDo PnlBrlyFilDetail::VecVDo

#define ContIacBrlyFilDetail PnlBrlyFilDetail::ContIac
#define ContInfBrlyFilDetail PnlBrlyFilDetail::ContInf
#define StatAppBrlyFilDetail PnlBrlyFilDetail::StatApp
#define StatShrBrlyFilDetail PnlBrlyFilDetail::StatShr
#define TagBrlyFilDetail PnlBrlyFilDetail::Tag

#define DpchAppBrlyFilDetailData PnlBrlyFilDetail::DpchAppData
#define DpchAppBrlyFilDetailDo PnlBrlyFilDetail::DpchAppDo
#define DpchEngBrlyFilDetailData PnlBrlyFilDetail::DpchEngData

/**
	* PnlBrlyFilDetail
	*/
class PnlBrlyFilDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyFilDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTREUVIEWCLICK = 5;
		static const Sbecore::uint BUTCNTEDITCLICK = 6;
		static const Sbecore::uint BUTMIMEDITCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyFilDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFFNM = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint NUMFPUPRET = 3;
		static const Sbecore::uint NUMFPUPCNT = 4;
		static const Sbecore::uint TXFCNT = 5;
		static const Sbecore::uint TXFACV = 6;
		static const Sbecore::uint TXFANM = 7;
		static const Sbecore::uint NUMFPUPMIM = 8;
		static const Sbecore::uint TXFMIM = 9;
		static const Sbecore::uint TXFSIZ = 10;
		static const Sbecore::uint TXFCMT = 11;

	public:
		ContIac(const std::string& TxfFnm = "", const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupCnt = 1, const std::string& TxfCnt = "", const std::string& TxfAcv = "", const std::string& TxfAnm = "", const Sbecore::uint numFPupMim = 1, const std::string& TxfMim = "", const std::string& TxfSiz = "", const std::string& TxfCmt = "");

	public:
		std::string TxfFnm;
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupCnt;
		std::string TxfCnt;
		std::string TxfAcv;
		std::string TxfAnm;
		Sbecore::uint numFPupMim;
		std::string TxfMim;
		std::string TxfSiz;
		std::string TxfCmt;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyFilDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTCLU = 1;
		static const Sbecore::uint TXTREU = 2;

	public:
		ContInf(const std::string& TxtClu = "", const std::string& TxtReu = "");

	public:
		std::string TxtClu;
		std::string TxtReu;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyFilDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstCluAlt = true, const bool PupCntAlt = false, const bool PupMimAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstCluAlt = true, const bool PupCntAlt = false, const bool PupMimAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyFilDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCNTVALID = 1;
		static const Sbecore::uint TXFMIMVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXFFNMACTIVE = 5;
		static const Sbecore::uint LSTCLUACTIVE = 6;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 7;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 8;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint PUPCNTACTIVE = 13;
		static const Sbecore::uint BUTCNTEDITAVAIL = 14;
		static const Sbecore::uint TXFACVACTIVE = 15;
		static const Sbecore::uint TXFANMACTIVE = 16;
		static const Sbecore::uint PUPMIMACTIVE = 17;
		static const Sbecore::uint BUTMIMEDITAVAIL = 18;
		static const Sbecore::uint TXFSIZACTIVE = 19;
		static const Sbecore::uint TXFCMTACTIVE = 20;

	public:
		StatShr(const bool TxfCntValid = false, const bool TxfMimValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfFnmActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool PupCntActive = true, const bool ButCntEditAvail = true, const bool TxfAcvActive = true, const bool TxfAnmActive = true, const bool PupMimActive = true, const bool ButMimEditAvail = true, const bool TxfSizActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfCntValid;
		bool TxfMimValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfFnmActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool PupCntActive;
		bool ButCntEditAvail;
		bool TxfAcvActive;
		bool TxfAnmActive;
		bool PupMimActive;
		bool ButMimEditAvail;
		bool TxfSizActive;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyFilDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFilDetailData)
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
		* DpchAppDo (full: DpchAppBrlyFilDetailDo)
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
		* DpchEngData (full: DpchEngBrlyFilDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPCNT = 5;
		static const Sbecore::uint FEEDFPUPMIM = 6;
		static const Sbecore::uint FEEDFPUPRET = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstClu = NULL, Sbecore::Feed* feedFPupCnt = NULL, Sbecore::Feed* feedFPupMim = NULL, Sbecore::Feed* feedFPupRet = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFPupCnt;
		Sbecore::Feed feedFPupMim;
		Sbecore::Feed feedFPupRet;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxfFnmActive(DbsBrly* dbsbrly);
	bool evalLstCluActive(DbsBrly* dbsbrly);
	bool evalButCluViewActive(DbsBrly* dbsbrly);
	bool evalButCluClusterAvail(DbsBrly* dbsbrly);
	bool evalButCluUnclusterAvail(DbsBrly* dbsbrly);
	bool evalTxtReuActive(DbsBrly* dbsbrly);
	bool evalButReuViewAvail(DbsBrly* dbsbrly);
	bool evalButReuViewActive(DbsBrly* dbsbrly);
	bool evalPupCntActive(DbsBrly* dbsbrly);
	bool evalButCntEditAvail(DbsBrly* dbsbrly);
	bool evalTxfAcvActive(DbsBrly* dbsbrly);
	bool evalTxfAnmActive(DbsBrly* dbsbrly);
	bool evalPupMimActive(DbsBrly* dbsbrly);
	bool evalButMimEditAvail(DbsBrly* dbsbrly);
	bool evalTxfSizActive(DbsBrly* dbsbrly);
	bool evalTxfCmtActive(DbsBrly* dbsbrly);

public:
	PnlBrlyFilDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyFilDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstClu;
	Sbecore::Feed feedFPupCnt;
	Sbecore::Feed feedFPupMim;
	Sbecore::Feed feedFPupRet;

	BrlyMFile recFil;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstClu(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshClu(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshPupCnt(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshTxfCnt(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshCnt(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshPupMim(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshTxfMim(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshMim(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refreshRecFil(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

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
	void handleDpchAppDoButReuViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButCntEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButMimEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyFilMod_cluEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyKlsAkeyMod_klsEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallBrlyFilUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyFil_reuEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyFil_cluEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyFil_retEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
