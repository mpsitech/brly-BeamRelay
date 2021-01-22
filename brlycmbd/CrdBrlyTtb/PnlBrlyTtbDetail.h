/**
	* \file PnlBrlyTtbDetail.h
	* job handler for job PnlBrlyTtbDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYTTBDETAIL_H
#define PNLBRLYTTBDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyTtbDetailDo PnlBrlyTtbDetail::VecVDo

#define ContIacBrlyTtbDetail PnlBrlyTtbDetail::ContIac
#define ContInfBrlyTtbDetail PnlBrlyTtbDetail::ContInf
#define StatAppBrlyTtbDetail PnlBrlyTtbDetail::StatApp
#define StatShrBrlyTtbDetail PnlBrlyTtbDetail::StatShr
#define TagBrlyTtbDetail PnlBrlyTtbDetail::Tag

#define DpchAppBrlyTtbDetailData PnlBrlyTtbDetail::DpchAppData
#define DpchAppBrlyTtbDetailDo PnlBrlyTtbDetail::DpchAppDo
#define DpchEngBrlyTtbDetailData PnlBrlyTtbDetail::DpchEngData

/**
	* PnlBrlyTtbDetail
	*/
class PnlBrlyTtbDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyTtbDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTFILVIEWCLICK = 2;
		static const Sbecore::uint BUTALIEDITCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyTtbDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint NUMFPUPALI = 2;
		static const Sbecore::uint TXFALI = 3;
		static const Sbecore::uint TXFSTA = 4;
		static const Sbecore::uint TXFSTO = 5;

	public:
		ContIac(const std::string& TxfTit = "", const Sbecore::uint numFPupAli = 1, const std::string& TxfAli = "", const std::string& TxfSta = "", const std::string& TxfSto = "");

	public:
		std::string TxfTit;
		Sbecore::uint numFPupAli;
		std::string TxfAli;
		std::string TxfSta;
		std::string TxfSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyTtbDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTFIL = 1;

	public:
		ContInf(const std::string& TxtFil = "");

	public:
		std::string TxtFil;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyTtbDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool PupAliAlt = false);
	};

	/**
		* StatShr (full: StatShrBrlyTtbDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFALIVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXFTITACTIVE = 4;
		static const Sbecore::uint TXTFILACTIVE = 5;
		static const Sbecore::uint BUTFILVIEWAVAIL = 6;
		static const Sbecore::uint BUTFILVIEWACTIVE = 7;
		static const Sbecore::uint PUPALIACTIVE = 8;
		static const Sbecore::uint BUTALIEDITAVAIL = 9;
		static const Sbecore::uint TXFSTAACTIVE = 10;
		static const Sbecore::uint TXFSTOACTIVE = 11;

	public:
		StatShr(const bool TxfAliValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxtFilActive = true, const bool ButFilViewAvail = true, const bool ButFilViewActive = true, const bool PupAliActive = true, const bool ButAliEditAvail = true, const bool TxfStaActive = true, const bool TxfStoActive = true);

	public:
		bool TxfAliValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxtFilActive;
		bool ButFilViewAvail;
		bool ButFilViewActive;
		bool PupAliActive;
		bool ButAliEditAvail;
		bool TxfStaActive;
		bool TxfStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyTtbDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyTtbDetailData)
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
		* DpchAppDo (full: DpchAppBrlyTtbDetailDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngBrlyTtbDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPALI = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupAli = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupAli;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxfTitActive(DbsBrly* dbsbrly);
	bool evalTxtFilActive(DbsBrly* dbsbrly);
	bool evalButFilViewAvail(DbsBrly* dbsbrly);
	bool evalButFilViewActive(DbsBrly* dbsbrly);
	bool evalPupAliActive(DbsBrly* dbsbrly);
	bool evalButAliEditAvail(DbsBrly* dbsbrly);
	bool evalTxfStaActive(DbsBrly* dbsbrly);
	bool evalTxfStoActive(DbsBrly* dbsbrly);

public:
	PnlBrlyTtbDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyTtbDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupAli;

	BrlyMTimetable recTtb;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshPupAli(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshTxfAli(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshAli(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refreshRecTtb(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFilViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButAliEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyKlsAkeyMod_klsEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallBrlyTtbUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyTtb_filEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
