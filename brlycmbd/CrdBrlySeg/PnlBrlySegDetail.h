/**
	* \file PnlBrlySegDetail.h
	* job handler for job PnlBrlySegDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYSEGDETAIL_H
#define PNLBRLYSEGDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlySegDetailDo PnlBrlySegDetail::VecVDo

#define ContIacBrlySegDetail PnlBrlySegDetail::ContIac
#define ContInfBrlySegDetail PnlBrlySegDetail::ContInf
#define StatAppBrlySegDetail PnlBrlySegDetail::StatApp
#define StatShrBrlySegDetail PnlBrlySegDetail::StatShr
#define TagBrlySegDetail PnlBrlySegDetail::Tag

#define DpchAppBrlySegDetailData PnlBrlySegDetail::DpchAppData
#define DpchAppBrlySegDetailDo PnlBrlySegDetail::DpchAppDo
#define DpchEngBrlySegDetailData PnlBrlySegDetail::DpchEngData

/**
	* PnlBrlySegDetail
	*/
class PnlBrlySegDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlySegDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTREUVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlySegDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPRET = 1;
		static const Sbecore::uint TXFDPH = 2;
		static const Sbecore::uint TXFAL0 = 3;
		static const Sbecore::uint TXFAL1 = 4;
		static const Sbecore::uint TXFTH0 = 5;
		static const Sbecore::uint TXFTH1 = 6;
		static const Sbecore::uint TXFPH0 = 7;
		static const Sbecore::uint TXFPH1 = 8;
		static const Sbecore::uint TXFSTA = 9;
		static const Sbecore::uint TXFSTO = 10;
		static const Sbecore::uint CHKCDN = 11;

	public:
		ContIac(const Sbecore::uint numFPupRet = 1, const std::string& TxfDph = "", const std::string& TxfAl0 = "", const std::string& TxfAl1 = "", const std::string& TxfTh0 = "", const std::string& TxfTh1 = "", const std::string& TxfPh0 = "", const std::string& TxfPh1 = "", const std::string& TxfSta = "", const std::string& TxfSto = "", const bool ChkCdn = false);

	public:
		Sbecore::uint numFPupRet;
		std::string TxfDph;
		std::string TxfAl0;
		std::string TxfAl1;
		std::string TxfTh0;
		std::string TxfTh1;
		std::string TxfPh0;
		std::string TxfPh1;
		std::string TxfSta;
		std::string TxfSto;
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
	  * ContInf (full: ContInfBrlySegDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTREU = 1;

	public:
		ContInf(const std::string& TxtReu = "");

	public:
		std::string TxtReu;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlySegDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlySegDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTREUACTIVE = 3;
		static const Sbecore::uint BUTREUVIEWAVAIL = 4;
		static const Sbecore::uint BUTREUVIEWACTIVE = 5;
		static const Sbecore::uint TXFDPHACTIVE = 6;
		static const Sbecore::uint TXFAL0ACTIVE = 7;
		static const Sbecore::uint TXFAL1ACTIVE = 8;
		static const Sbecore::uint TXFTH0ACTIVE = 9;
		static const Sbecore::uint TXFTH1ACTIVE = 10;
		static const Sbecore::uint TXFPH0ACTIVE = 11;
		static const Sbecore::uint TXFPH1ACTIVE = 12;
		static const Sbecore::uint TXFSTAACTIVE = 13;
		static const Sbecore::uint TXFSTOACTIVE = 14;
		static const Sbecore::uint CHKCDNACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxfDphActive = true, const bool TxfAl0Active = true, const bool TxfAl1Active = true, const bool TxfTh0Active = true, const bool TxfTh1Active = true, const bool TxfPh0Active = true, const bool TxfPh1Active = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool ChkCdnActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxfDphActive;
		bool TxfAl0Active;
		bool TxfAl1Active;
		bool TxfTh0Active;
		bool TxfTh1Active;
		bool TxfPh0Active;
		bool TxfPh1Active;
		bool TxfStaActive;
		bool TxfStoActive;
		bool ChkCdnActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlySegDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlySegDetailData)
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
		* DpchAppDo (full: DpchAppBrlySegDetailDo)
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
		* DpchEngData (full: DpchEngBrlySegDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPRET = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupRet = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
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
	bool evalTxtReuActive(DbsBrly* dbsbrly);
	bool evalButReuViewAvail(DbsBrly* dbsbrly);
	bool evalButReuViewActive(DbsBrly* dbsbrly);
	bool evalTxfDphActive(DbsBrly* dbsbrly);
	bool evalTxfAl0Active(DbsBrly* dbsbrly);
	bool evalTxfAl1Active(DbsBrly* dbsbrly);
	bool evalTxfTh0Active(DbsBrly* dbsbrly);
	bool evalTxfTh1Active(DbsBrly* dbsbrly);
	bool evalTxfPh0Active(DbsBrly* dbsbrly);
	bool evalTxfPh1Active(DbsBrly* dbsbrly);
	bool evalTxfStaActive(DbsBrly* dbsbrly);
	bool evalTxfStoActive(DbsBrly* dbsbrly);
	bool evalChkCdnActive(DbsBrly* dbsbrly);

public:
	PnlBrlySegDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlySegDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupRet;

	BrlyMSegment recSeg;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecSeg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlySegUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlySeg_retEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlySeg_reuEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
