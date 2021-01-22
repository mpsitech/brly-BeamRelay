/**
	* \file PnlBrlyRegDetail.h
	* job handler for job PnlBrlyRegDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYREGDETAIL_H
#define PNLBRLYREGDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyRegDetailDo PnlBrlyRegDetail::VecVDo

#define ContIacBrlyRegDetail PnlBrlyRegDetail::ContIac
#define ContInfBrlyRegDetail PnlBrlyRegDetail::ContInf
#define StatAppBrlyRegDetail PnlBrlyRegDetail::StatApp
#define StatShrBrlyRegDetail PnlBrlyRegDetail::StatShr
#define TagBrlyRegDetail PnlBrlyRegDetail::Tag

#define DpchAppBrlyRegDetailData PnlBrlyRegDetail::DpchAppData
#define DpchAppBrlyRegDetailDo PnlBrlyRegDetail::DpchAppDo
#define DpchEngBrlyRegDetailData PnlBrlyRegDetail::DpchEngData

/**
	* PnlBrlyRegDetail
	*/
class PnlBrlyRegDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyRegDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJTIEDITCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;
		static const Sbecore::uint BUTJEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyRegDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJTI = 1;
		static const Sbecore::uint NUMFPUPJ = 2;
		static const Sbecore::uint NUMFPUPDST = 3;

	public:
		ContIac(const Sbecore::uint numFPupJti = 1, const Sbecore::uint numFPupJ = 1, const Sbecore::uint numFPupDst = 1);

	public:
		Sbecore::uint numFPupJti;
		Sbecore::uint numFPupJ;
		Sbecore::uint numFPupDst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyRegDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTSUP = 3;
		static const Sbecore::uint TXTTOF = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtSup = "", const std::string& TxtTof = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtSup;
		std::string TxtTof;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyRegDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyRegDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPJTIACTIVE = 4;
		static const Sbecore::uint BUTJTIEDITAVAIL = 5;
		static const Sbecore::uint TXTTITACTIVE = 6;
		static const Sbecore::uint TXTSUPACTIVE = 7;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 8;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 9;
		static const Sbecore::uint PUPJACTIVE = 10;
		static const Sbecore::uint BUTJEDITAVAIL = 11;
		static const Sbecore::uint PUPDSTACTIVE = 12;
		static const Sbecore::uint TXTTOFACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool PupDstActive = true, const bool TxtTofActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool PupDstActive;
		bool TxtTofActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyRegDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyRegDetailData)
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
		* DpchAppDo (full: DpchAppBrlyRegDetailDo)
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
		* DpchEngData (full: DpchEngBrlyRegDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPDST = 4;
		static const Sbecore::uint FEEDFPUPJ = 5;
		static const Sbecore::uint FEEDFPUPJTI = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupDst = NULL, Sbecore::Xmlio::Feed* feedFPupJ = NULL, Sbecore::Xmlio::Feed* feedFPupJti = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupDst;
		Sbecore::Xmlio::Feed feedFPupJ;
		Sbecore::Xmlio::Feed feedFPupJti;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtSrfActive(DbsBrly* dbsbrly);
	bool evalPupJtiActive(DbsBrly* dbsbrly);
	bool evalButJtiEditAvail(DbsBrly* dbsbrly);
	bool evalTxtTitActive(DbsBrly* dbsbrly);
	bool evalTxtSupActive(DbsBrly* dbsbrly);
	bool evalButSupViewAvail(DbsBrly* dbsbrly);
	bool evalButSupViewActive(DbsBrly* dbsbrly);
	bool evalPupJActive(DbsBrly* dbsbrly);
	bool evalButJEditAvail(DbsBrly* dbsbrly);
	bool evalPupDstActive(DbsBrly* dbsbrly);
	bool evalTxtTofActive(DbsBrly* dbsbrly);

public:
	PnlBrlyRegDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyRegDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupDst;
	Sbecore::Xmlio::Feed feedFPupJ;
	Sbecore::Xmlio::Feed feedFPupJti;

	BrlyMRegion recReg;
	Sbecore::uint ixWSubsetReg;

	BrlyJMRegion recRegJ;

	BrlyJMRegionTitle recRegJtit;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJti(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshJ(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refreshRecReg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshRecRegJ(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshRecRegJtit(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButJtiEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButSupViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButJEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyRegJtitMod_regEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyRegJMod_regEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyRegUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyReg_supEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyReg_isLeaf(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, bool& boolvalRet);
	bool handleCallBrlyReg_inSbs(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
