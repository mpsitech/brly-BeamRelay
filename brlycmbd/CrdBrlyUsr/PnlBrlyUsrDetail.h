/**
	* \file PnlBrlyUsrDetail.h
	* job handler for job PnlBrlyUsrDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYUSRDETAIL_H
#define PNLBRLYUSRDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyUsrDetailDo PnlBrlyUsrDetail::VecVDo

#define ContIacBrlyUsrDetail PnlBrlyUsrDetail::ContIac
#define ContInfBrlyUsrDetail PnlBrlyUsrDetail::ContInf
#define StatAppBrlyUsrDetail PnlBrlyUsrDetail::StatApp
#define StatShrBrlyUsrDetail PnlBrlyUsrDetail::StatShr
#define TagBrlyUsrDetail PnlBrlyUsrDetail::Tag

#define DpchAppBrlyUsrDetailData PnlBrlyUsrDetail::DpchAppData
#define DpchAppBrlyUsrDetailDo PnlBrlyUsrDetail::DpchAppDo
#define DpchEngBrlyUsrDetailData PnlBrlyUsrDetail::DpchEngData

/**
	* PnlBrlyUsrDetail
	*/
class PnlBrlyUsrDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyUsrDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRSVIEWCLICK = 2;
		static const Sbecore::uint BUTUSGVIEWCLICK = 3;
		static const Sbecore::uint BUTJSTEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyUsrDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPJST = 1;
		static const Sbecore::uint NUMFPUPSTE = 2;
		static const Sbecore::uint NUMFPUPLCL = 3;
		static const Sbecore::uint NUMFPUPULV = 4;
		static const Sbecore::uint TXFPWD = 5;
		static const Sbecore::uint TXFFKY = 6;
		static const Sbecore::uint TXFCMT = 7;

	public:
		ContIac(const Sbecore::uint numFPupJst = 1, const Sbecore::uint numFPupSte = 1, const Sbecore::uint numFPupLcl = 1, const Sbecore::uint numFPupUlv = 1, const std::string& TxfPwd = "", const std::string& TxfFky = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupJst;
		Sbecore::uint numFPupSte;
		Sbecore::uint numFPupLcl;
		Sbecore::uint numFPupUlv;
		std::string TxfPwd;
		std::string TxfFky;
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
	  * ContInf (full: ContInfBrlyUsrDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRS = 1;
		static const Sbecore::uint TXTSRF = 2;
		static const Sbecore::uint TXTUSG = 3;

	public:
		ContInf(const std::string& TxtPrs = "", const std::string& TxtSrf = "", const std::string& TxtUsg = "");

	public:
		std::string TxtPrs;
		std::string TxtSrf;
		std::string TxtUsg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyUsrDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyUsrDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRSACTIVE = 3;
		static const Sbecore::uint BUTPRSVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRSVIEWACTIVE = 5;
		static const Sbecore::uint TXTSRFACTIVE = 6;
		static const Sbecore::uint TXTUSGACTIVE = 7;
		static const Sbecore::uint BUTUSGVIEWAVAIL = 8;
		static const Sbecore::uint BUTUSGVIEWACTIVE = 9;
		static const Sbecore::uint PUPJSTACTIVE = 10;
		static const Sbecore::uint BUTJSTEDITAVAIL = 11;
		static const Sbecore::uint PUPSTEACTIVE = 12;
		static const Sbecore::uint PUPLCLACTIVE = 13;
		static const Sbecore::uint PUPULVACTIVE = 14;
		static const Sbecore::uint TXFPWDACTIVE = 15;
		static const Sbecore::uint TXFFKYACTIVE = 16;
		static const Sbecore::uint TXFCMTACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrsActive = true, const bool ButPrsViewAvail = true, const bool ButPrsViewActive = true, const bool TxtSrfActive = true, const bool TxtUsgActive = true, const bool ButUsgViewAvail = true, const bool ButUsgViewActive = true, const bool PupJstActive = true, const bool ButJstEditAvail = true, const bool PupSteActive = true, const bool PupLclActive = true, const bool PupUlvActive = true, const bool TxfPwdActive = true, const bool TxfFkyActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrsActive;
		bool ButPrsViewAvail;
		bool ButPrsViewActive;
		bool TxtSrfActive;
		bool TxtUsgActive;
		bool ButUsgViewAvail;
		bool ButUsgViewActive;
		bool PupJstActive;
		bool ButJstEditAvail;
		bool PupSteActive;
		bool PupLclActive;
		bool PupUlvActive;
		bool TxfPwdActive;
		bool TxfFkyActive;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyUsrDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyUsrDetailData)
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
		* DpchAppDo (full: DpchAppBrlyUsrDetailDo)
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
		* DpchEngData (full: DpchEngBrlyUsrDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJST = 4;
		static const Sbecore::uint FEEDFPUPLCL = 5;
		static const Sbecore::uint FEEDFPUPSTE = 6;
		static const Sbecore::uint FEEDFPUPULV = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupJst = NULL, Sbecore::Feed* feedFPupLcl = NULL, Sbecore::Feed* feedFPupSte = NULL, Sbecore::Feed* feedFPupUlv = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupJst;
		Sbecore::Feed feedFPupLcl;
		Sbecore::Feed feedFPupSte;
		Sbecore::Feed feedFPupUlv;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtPrsActive(DbsBrly* dbsbrly);
	bool evalButPrsViewAvail(DbsBrly* dbsbrly);
	bool evalButPrsViewActive(DbsBrly* dbsbrly);
	bool evalTxtSrfActive(DbsBrly* dbsbrly);
	bool evalTxtUsgActive(DbsBrly* dbsbrly);
	bool evalButUsgViewAvail(DbsBrly* dbsbrly);
	bool evalButUsgViewActive(DbsBrly* dbsbrly);
	bool evalPupJstActive(DbsBrly* dbsbrly);
	bool evalButJstEditAvail(DbsBrly* dbsbrly);
	bool evalPupSteActive(DbsBrly* dbsbrly);
	bool evalPupLclActive(DbsBrly* dbsbrly);
	bool evalPupUlvActive(DbsBrly* dbsbrly);
	bool evalTxfPwdActive(DbsBrly* dbsbrly);
	bool evalTxfFkyActive(DbsBrly* dbsbrly);
	bool evalTxfCmtActive(DbsBrly* dbsbrly);

public:
	PnlBrlyUsrDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyUsrDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupJst;
	Sbecore::Feed feedFPupLcl;
	Sbecore::Feed feedFPupSte;
	Sbecore::Feed feedFPupUlv;

	BrlyMUser recUsr;

	BrlyJMUserState recUsrJste;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJst(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refreshRecUsr(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshRecUsrJste(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButUsgViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButJstEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyUsrJsteMod_usrEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyUsr_prsEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyUsr_usgEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyUsrUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);

};

#endif
