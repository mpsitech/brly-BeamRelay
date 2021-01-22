/**
	* \file PnlBrlyRlyDetail.h
	* job handler for job PnlBrlyRlyDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYRLYDETAIL_H
#define PNLBRLYRLYDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyRlyDetailDo PnlBrlyRlyDetail::VecVDo

#define ContIacBrlyRlyDetail PnlBrlyRlyDetail::ContIac
#define ContInfBrlyRlyDetail PnlBrlyRlyDetail::ContInf
#define StatAppBrlyRlyDetail PnlBrlyRlyDetail::StatApp
#define StatShrBrlyRlyDetail PnlBrlyRlyDetail::StatShr
#define TagBrlyRlyDetail PnlBrlyRlyDetail::Tag

#define DpchAppBrlyRlyDetailData PnlBrlyRlyDetail::DpchAppData
#define DpchAppBrlyRlyDetailDo PnlBrlyRlyDetail::DpchAppDo
#define DpchEngBrlyRlyDetailData PnlBrlyRlyDetail::DpchEngData

/**
	* PnlBrlyRlyDetail
	*/
class PnlBrlyRlyDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyRlyDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCONVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyRlyDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSTA = 1;
		static const Sbecore::uint TXFSTO = 2;
		static const Sbecore::uint NUMFPUPDIR = 3;
		static const Sbecore::uint CHKCTD = 4;
		static const Sbecore::uint TXFNHP = 5;

	public:
		ContIac(const std::string& TxfSta = "", const std::string& TxfSto = "", const Sbecore::uint numFPupDir = 1, const bool ChkCtd = false, const std::string& TxfNhp = "");

	public:
		std::string TxfSta;
		std::string TxfSto;
		Sbecore::uint numFPupDir;
		bool ChkCtd;
		std::string TxfNhp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyRlyDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTCON = 1;

	public:
		ContInf(const std::string& TxtCon = "");

	public:
		std::string TxtCon;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyRlyDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyRlyDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXFSTAACTIVE = 3;
		static const Sbecore::uint TXFSTOACTIVE = 4;
		static const Sbecore::uint TXTCONACTIVE = 5;
		static const Sbecore::uint BUTCONVIEWAVAIL = 6;
		static const Sbecore::uint BUTCONVIEWACTIVE = 7;
		static const Sbecore::uint PUPDIRACTIVE = 8;
		static const Sbecore::uint CHKCTDACTIVE = 9;
		static const Sbecore::uint TXFNHPACTIVE = 10;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxtConActive = true, const bool ButConViewAvail = true, const bool ButConViewActive = true, const bool PupDirActive = true, const bool ChkCtdActive = true, const bool TxfNhpActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxtConActive;
		bool ButConViewAvail;
		bool ButConViewActive;
		bool PupDirActive;
		bool ChkCtdActive;
		bool TxfNhpActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyRlyDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyRlyDetailData)
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
		* DpchAppDo (full: DpchAppBrlyRlyDetailDo)
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
		* DpchEngData (full: DpchEngBrlyRlyDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPDIR = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupDir = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupDir;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxfStaActive(DbsBrly* dbsbrly);
	bool evalTxfStoActive(DbsBrly* dbsbrly);
	bool evalTxtConActive(DbsBrly* dbsbrly);
	bool evalButConViewAvail(DbsBrly* dbsbrly);
	bool evalButConViewActive(DbsBrly* dbsbrly);
	bool evalPupDirActive(DbsBrly* dbsbrly);
	bool evalChkCtdActive(DbsBrly* dbsbrly);
	bool evalTxfNhpActive(DbsBrly* dbsbrly);

public:
	PnlBrlyRlyDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyRlyDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupDir;

	BrlyMRelay recRly;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecRly(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButConViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyRlyUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyRly_conEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
