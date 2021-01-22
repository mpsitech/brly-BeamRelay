/**
	* \file PnlBrlyLocDetail.h
	* job handler for job PnlBrlyLocDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYLOCDETAIL_H
#define PNLBRLYLOCDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyLocDetailDo PnlBrlyLocDetail::VecVDo

#define ContIacBrlyLocDetail PnlBrlyLocDetail::ContIac
#define ContInfBrlyLocDetail PnlBrlyLocDetail::ContInf
#define StatAppBrlyLocDetail PnlBrlyLocDetail::StatApp
#define StatShrBrlyLocDetail PnlBrlyLocDetail::StatShr
#define TagBrlyLocDetail PnlBrlyLocDetail::Tag

#define DpchAppBrlyLocDetailData PnlBrlyLocDetail::DpchAppData
#define DpchAppBrlyLocDetailDo PnlBrlyLocDetail::DpchAppDo
#define DpchEngBrlyLocDetailData PnlBrlyLocDetail::DpchEngData

/**
	* PnlBrlyLocDetail
	*/
class PnlBrlyLocDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLocDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTEQPNEWCLICK = 2;
		static const Sbecore::uint BUTEQPDELETECLICK = 3;
		static const Sbecore::uint BUTEQPOPRVIEWCLICK = 4;
		static const Sbecore::uint BUTEQPPTYVIEWCLICK = 5;
		static const Sbecore::uint BUTEQPETYEDITCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyLocDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFICA = 1;
		static const Sbecore::uint TXFTIT = 2;
		static const Sbecore::uint NUMFPUPTYP = 3;
		static const Sbecore::uint TXFALT = 4;
		static const Sbecore::uint TXFTHE = 5;
		static const Sbecore::uint TXFPHI = 6;
		static const Sbecore::uint TXFTZ = 7;
		static const Sbecore::uint TXFAPH = 8;
		static const Sbecore::uint CHKCDN = 9;
		static const Sbecore::uint NUMFPUPEQPETY = 10;
		static const Sbecore::uint TXFEQPETY = 11;
		static const Sbecore::uint CHKEQPFIB = 12;

	public:
		ContIac(const std::string& TxfIca = "", const std::string& TxfTit = "", const Sbecore::uint numFPupTyp = 1, const std::string& TxfAlt = "", const std::string& TxfThe = "", const std::string& TxfPhi = "", const std::string& TxfTz = "", const std::string& TxfAph = "", const bool ChkCdn = false, const Sbecore::uint numFPupEqpEty = 1, const std::string& TxfEqpEty = "", const bool ChkEqpFib = false);

	public:
		std::string TxfIca;
		std::string TxfTit;
		Sbecore::uint numFPupTyp;
		std::string TxfAlt;
		std::string TxfThe;
		std::string TxfPhi;
		std::string TxfTz;
		std::string TxfAph;
		bool ChkCdn;
		Sbecore::uint numFPupEqpEty;
		std::string TxfEqpEty;
		bool ChkEqpFib;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyLocDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTREG = 2;
		static const Sbecore::uint TXTEQPOPR = 3;
		static const Sbecore::uint TXTEQPPTY = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtReg = "", const std::string& TxtEqpOpr = "", const std::string& TxtEqpPty = "");

	public:
		std::string TxtSrf;
		std::string TxtReg;
		std::string TxtEqpOpr;
		std::string TxtEqpPty;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyLocDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool PupEqpEtyAlt = false);
	};

	/**
		* StatShr (full: StatShrBrlyLocDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFEQPETYVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXFICAACTIVE = 5;
		static const Sbecore::uint TXFTITACTIVE = 6;
		static const Sbecore::uint PUPTYPACTIVE = 7;
		static const Sbecore::uint TXTREGACTIVE = 8;
		static const Sbecore::uint TXFALTACTIVE = 9;
		static const Sbecore::uint TXFTHEACTIVE = 10;
		static const Sbecore::uint TXFPHIACTIVE = 11;
		static const Sbecore::uint TXFTZACTIVE = 12;
		static const Sbecore::uint TXFAPHACTIVE = 13;
		static const Sbecore::uint CHKCDNACTIVE = 14;
		static const Sbecore::uint BUTEQPNEWAVAIL = 15;
		static const Sbecore::uint BUTEQPDELETEAVAIL = 16;
		static const Sbecore::uint TXTEQPOPRAVAIL = 17;
		static const Sbecore::uint TXTEQPOPRACTIVE = 18;
		static const Sbecore::uint BUTEQPOPRVIEWAVAIL = 19;
		static const Sbecore::uint BUTEQPOPRVIEWACTIVE = 20;
		static const Sbecore::uint TXTEQPPTYAVAIL = 21;
		static const Sbecore::uint TXTEQPPTYACTIVE = 22;
		static const Sbecore::uint BUTEQPPTYVIEWAVAIL = 23;
		static const Sbecore::uint BUTEQPPTYVIEWACTIVE = 24;
		static const Sbecore::uint PUPEQPETYAVAIL = 25;
		static const Sbecore::uint PUPEQPETYACTIVE = 26;
		static const Sbecore::uint BUTEQPETYEDITAVAIL = 27;
		static const Sbecore::uint CHKEQPFIBAVAIL = 28;
		static const Sbecore::uint CHKEQPFIBACTIVE = 29;

	public:
		StatShr(const bool TxfEqpEtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfIcaActive = true, const bool TxfTitActive = true, const bool PupTypActive = true, const bool TxtRegActive = true, const bool TxfAltActive = true, const bool TxfTheActive = true, const bool TxfPhiActive = true, const bool TxfTzActive = true, const bool TxfAphActive = true, const bool ChkCdnActive = true, const bool ButEqpNewAvail = true, const bool ButEqpDeleteAvail = true, const bool TxtEqpOprAvail = true, const bool TxtEqpOprActive = true, const bool ButEqpOprViewAvail = true, const bool ButEqpOprViewActive = true, const bool TxtEqpPtyAvail = true, const bool TxtEqpPtyActive = true, const bool ButEqpPtyViewAvail = true, const bool ButEqpPtyViewActive = true, const bool PupEqpEtyAvail = true, const bool PupEqpEtyActive = true, const bool ButEqpEtyEditAvail = true, const bool ChkEqpFibAvail = true, const bool ChkEqpFibActive = true);

	public:
		bool TxfEqpEtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfIcaActive;
		bool TxfTitActive;
		bool PupTypActive;
		bool TxtRegActive;
		bool TxfAltActive;
		bool TxfTheActive;
		bool TxfPhiActive;
		bool TxfTzActive;
		bool TxfAphActive;
		bool ChkCdnActive;
		bool ButEqpNewAvail;
		bool ButEqpDeleteAvail;
		bool TxtEqpOprAvail;
		bool TxtEqpOprActive;
		bool ButEqpOprViewAvail;
		bool ButEqpOprViewActive;
		bool TxtEqpPtyAvail;
		bool TxtEqpPtyActive;
		bool ButEqpPtyViewAvail;
		bool ButEqpPtyViewActive;
		bool PupEqpEtyAvail;
		bool PupEqpEtyActive;
		bool ButEqpEtyEditAvail;
		bool ChkEqpFibAvail;
		bool ChkEqpFibActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyLocDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLocDetailData)
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
		* DpchAppDo (full: DpchAppBrlyLocDetailDo)
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
		* DpchEngData (full: DpchEngBrlyLocDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPEQPETY = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupEqpEty = NULL, Sbecore::Xmlio::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupEqpEty;
		Sbecore::Xmlio::Feed feedFPupTyp;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtSrfActive(DbsBrly* dbsbrly);
	bool evalTxfIcaActive(DbsBrly* dbsbrly);
	bool evalTxfTitActive(DbsBrly* dbsbrly);
	bool evalPupTypActive(DbsBrly* dbsbrly);
	bool evalTxtRegActive(DbsBrly* dbsbrly);
	bool evalTxfAltActive(DbsBrly* dbsbrly);
	bool evalTxfTheActive(DbsBrly* dbsbrly);
	bool evalTxfPhiActive(DbsBrly* dbsbrly);
	bool evalTxfTzActive(DbsBrly* dbsbrly);
	bool evalTxfAphActive(DbsBrly* dbsbrly);
	bool evalChkCdnActive(DbsBrly* dbsbrly);
	bool evalButEqpNewAvail(DbsBrly* dbsbrly);
	bool evalButEqpDeleteAvail(DbsBrly* dbsbrly);
	bool evalTxtEqpOprAvail(DbsBrly* dbsbrly);
	bool evalTxtEqpOprActive(DbsBrly* dbsbrly);
	bool evalButEqpOprViewAvail(DbsBrly* dbsbrly);
	bool evalButEqpOprViewActive(DbsBrly* dbsbrly);
	bool evalTxtEqpPtyAvail(DbsBrly* dbsbrly);
	bool evalTxtEqpPtyActive(DbsBrly* dbsbrly);
	bool evalButEqpPtyViewAvail(DbsBrly* dbsbrly);
	bool evalButEqpPtyViewActive(DbsBrly* dbsbrly);
	bool evalPupEqpEtyAvail(DbsBrly* dbsbrly);
	bool evalPupEqpEtyActive(DbsBrly* dbsbrly);
	bool evalButEqpEtyEditAvail(DbsBrly* dbsbrly);
	bool evalChkEqpFibAvail(DbsBrly* dbsbrly);
	bool evalChkEqpFibActive(DbsBrly* dbsbrly);

public:
	PnlBrlyLocDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyLocDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupEqpEty;
	Sbecore::Xmlio::Feed feedFPupTyp;

	BrlyMLocation recLoc;
	Sbecore::uint ixWSubsetLoc;

	BrlyMEquipment recEqp;
	Sbecore::uint ixWSubsetEqp;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshPupEqpEty(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshTxfEqpEty(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshEqpEty(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refreshRecLoc(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshRecEqp(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButSaveClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEqpNewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEqpDeleteClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEqpOprViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEqpPtyViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEqpEtyEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyKlsAkeyMod_klsEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallBrlyLocUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyEqpUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyEqp_inSbs(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyEqp_hktEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyLoc_typEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyLoc_inSbs(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyLoc_eqpEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_ptyEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_oprEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
