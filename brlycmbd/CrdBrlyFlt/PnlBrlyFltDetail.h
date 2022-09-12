/**
	* \file PnlBrlyFltDetail.h
	* job handler for job PnlBrlyFltDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYFLTDETAIL_H
#define PNLBRLYFLTDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyFltDetailDo PnlBrlyFltDetail::VecVDo

#define ContIacBrlyFltDetail PnlBrlyFltDetail::ContIac
#define ContInfBrlyFltDetail PnlBrlyFltDetail::ContInf
#define StatAppBrlyFltDetail PnlBrlyFltDetail::StatApp
#define StatShrBrlyFltDetail PnlBrlyFltDetail::StatShr
#define TagBrlyFltDetail PnlBrlyFltDetail::Tag

#define DpchAppBrlyFltDetailData PnlBrlyFltDetail::DpchAppData
#define DpchAppBrlyFltDetailDo PnlBrlyFltDetail::DpchAppDo
#define DpchEngBrlyFltDetailData PnlBrlyFltDetail::DpchEngData

/**
	* PnlBrlyFltDetail
	*/
class PnlBrlyFltDetail : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyFltDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTTTBVIEWCLICK = 2;
		static const Sbecore::uint BUTFAFNEWCLICK = 3;
		static const Sbecore::uint BUTFAFDELETECLICK = 4;
		static const Sbecore::uint BUTEQPNEWCLICK = 5;
		static const Sbecore::uint BUTEQPDELETECLICK = 6;
		static const Sbecore::uint BUTEQPOPRVIEWCLICK = 7;
		static const Sbecore::uint BUTEQPPTYVIEWCLICK = 8;
		static const Sbecore::uint BUTEQPETYEDITCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyFltDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFSTA = 1;
		static const Sbecore::uint TXFSTO = 2;
		static const Sbecore::uint TXFXSA = 3;
		static const Sbecore::uint TXFXSO = 4;
		static const Sbecore::uint CHKCDN = 5;
		static const Sbecore::uint CHKSDN = 6;
		static const Sbecore::uint TXFFAFFID = 7;
		static const Sbecore::uint TXFFAFIDT = 8;
		static const Sbecore::uint TXFFAFACT = 9;
		static const Sbecore::uint TXFFAFFET = 10;
		static const Sbecore::uint TXFFAFFTI = 11;
		static const Sbecore::uint TXFFAFFDT = 12;
		static const Sbecore::uint TXFFAFFSK = 13;
		static const Sbecore::uint TXFFAFFSM = 14;
		static const Sbecore::uint TXFFAFFAT = 15;
		static const Sbecore::uint TXFFAFRTE = 16;
		static const Sbecore::uint TXFFAFADT = 17;
		static const Sbecore::uint TXFFAFEAT = 18;
		static const Sbecore::uint TXFFAFAAT = 19;
		static const Sbecore::uint TXFFAFDVT = 20;
		static const Sbecore::uint TXFFAFORG = 21;
		static const Sbecore::uint TXFFAFDST = 22;
		static const Sbecore::uint TXFFAFONM = 23;
		static const Sbecore::uint TXFFAFOCT = 24;
		static const Sbecore::uint TXFFAFDNM = 25;
		static const Sbecore::uint TXFFAFDCT = 26;
		static const Sbecore::uint NUMFPUPEQPETY = 27;
		static const Sbecore::uint TXFEQPETY = 28;
		static const Sbecore::uint CHKEQPFIB = 29;

	public:
		ContIac(const std::string& TxfSta = "", const std::string& TxfSto = "", const std::string& TxfXsa = "", const std::string& TxfXso = "", const bool ChkCdn = false, const bool ChkSdn = false, const std::string& TxfFafFid = "", const std::string& TxfFafIdt = "", const std::string& TxfFafAct = "", const std::string& TxfFafFet = "", const std::string& TxfFafFti = "", const std::string& TxfFafFdt = "", const std::string& TxfFafFsk = "", const std::string& TxfFafFsm = "", const std::string& TxfFafFat = "", const std::string& TxfFafRte = "", const std::string& TxfFafAdt = "", const std::string& TxfFafEat = "", const std::string& TxfFafAat = "", const std::string& TxfFafDvt = "", const std::string& TxfFafOrg = "", const std::string& TxfFafDst = "", const std::string& TxfFafOnm = "", const std::string& TxfFafOct = "", const std::string& TxfFafDnm = "", const std::string& TxfFafDct = "", const Sbecore::uint numFPupEqpEty = 1, const std::string& TxfEqpEty = "", const bool ChkEqpFib = false);

	public:
		std::string TxfSta;
		std::string TxfSto;
		std::string TxfXsa;
		std::string TxfXso;
		bool ChkCdn;
		bool ChkSdn;
		std::string TxfFafFid;
		std::string TxfFafIdt;
		std::string TxfFafAct;
		std::string TxfFafFet;
		std::string TxfFafFti;
		std::string TxfFafFdt;
		std::string TxfFafFsk;
		std::string TxfFafFsm;
		std::string TxfFafFat;
		std::string TxfFafRte;
		std::string TxfFafAdt;
		std::string TxfFafEat;
		std::string TxfFafAat;
		std::string TxfFafDvt;
		std::string TxfFafOrg;
		std::string TxfFafDst;
		std::string TxfFafOnm;
		std::string TxfFafOct;
		std::string TxfFafDnm;
		std::string TxfFafDct;
		Sbecore::uint numFPupEqpEty;
		std::string TxfEqpEty;
		bool ChkEqpFib;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyFltDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTTB = 2;
		static const Sbecore::uint TXTLEG = 3;
		static const Sbecore::uint TXTEQPOPR = 4;
		static const Sbecore::uint TXTEQPPTY = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTtb = "", const std::string& TxtLeg = "", const std::string& TxtEqpOpr = "", const std::string& TxtEqpPty = "");

	public:
		std::string TxtSrf;
		std::string TxtTtb;
		std::string TxtLeg;
		std::string TxtEqpOpr;
		std::string TxtEqpPty;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyFltDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool PupEqpEtyAlt = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool PupEqpEtyAlt = false);
	};

	/**
		* StatShr (full: StatShrBrlyFltDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFEQPETYVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXTTTBACTIVE = 5;
		static const Sbecore::uint BUTTTBVIEWAVAIL = 6;
		static const Sbecore::uint BUTTTBVIEWACTIVE = 7;
		static const Sbecore::uint TXTLEGACTIVE = 8;
		static const Sbecore::uint TXFSTAACTIVE = 9;
		static const Sbecore::uint TXFSTOACTIVE = 10;
		static const Sbecore::uint TXFXSAACTIVE = 11;
		static const Sbecore::uint TXFXSOACTIVE = 12;
		static const Sbecore::uint CHKCDNACTIVE = 13;
		static const Sbecore::uint CHKSDNACTIVE = 14;
		static const Sbecore::uint BUTFAFNEWAVAIL = 15;
		static const Sbecore::uint BUTFAFDELETEAVAIL = 16;
		static const Sbecore::uint TXFFAFFIDAVAIL = 17;
		static const Sbecore::uint TXFFAFFIDACTIVE = 18;
		static const Sbecore::uint TXFFAFIDTAVAIL = 19;
		static const Sbecore::uint TXFFAFIDTACTIVE = 20;
		static const Sbecore::uint TXFFAFACTAVAIL = 21;
		static const Sbecore::uint TXFFAFACTACTIVE = 22;
		static const Sbecore::uint TXFFAFFETAVAIL = 23;
		static const Sbecore::uint TXFFAFFETACTIVE = 24;
		static const Sbecore::uint TXFFAFFTIAVAIL = 25;
		static const Sbecore::uint TXFFAFFTIACTIVE = 26;
		static const Sbecore::uint TXFFAFFDTAVAIL = 27;
		static const Sbecore::uint TXFFAFFDTACTIVE = 28;
		static const Sbecore::uint TXFFAFFSKAVAIL = 29;
		static const Sbecore::uint TXFFAFFSKACTIVE = 30;
		static const Sbecore::uint TXFFAFFSMAVAIL = 31;
		static const Sbecore::uint TXFFAFFSMACTIVE = 32;
		static const Sbecore::uint TXFFAFFATAVAIL = 33;
		static const Sbecore::uint TXFFAFFATACTIVE = 34;
		static const Sbecore::uint TXFFAFRTEAVAIL = 35;
		static const Sbecore::uint TXFFAFRTEACTIVE = 36;
		static const Sbecore::uint TXFFAFADTAVAIL = 37;
		static const Sbecore::uint TXFFAFADTACTIVE = 38;
		static const Sbecore::uint TXFFAFEATAVAIL = 39;
		static const Sbecore::uint TXFFAFEATACTIVE = 40;
		static const Sbecore::uint TXFFAFAATAVAIL = 41;
		static const Sbecore::uint TXFFAFAATACTIVE = 42;
		static const Sbecore::uint TXFFAFDVTAVAIL = 43;
		static const Sbecore::uint TXFFAFDVTACTIVE = 44;
		static const Sbecore::uint TXFFAFORGAVAIL = 45;
		static const Sbecore::uint TXFFAFORGACTIVE = 46;
		static const Sbecore::uint TXFFAFDSTAVAIL = 47;
		static const Sbecore::uint TXFFAFDSTACTIVE = 48;
		static const Sbecore::uint TXFFAFONMAVAIL = 49;
		static const Sbecore::uint TXFFAFONMACTIVE = 50;
		static const Sbecore::uint TXFFAFOCTAVAIL = 51;
		static const Sbecore::uint TXFFAFOCTACTIVE = 52;
		static const Sbecore::uint TXFFAFDNMAVAIL = 53;
		static const Sbecore::uint TXFFAFDNMACTIVE = 54;
		static const Sbecore::uint TXFFAFDCTAVAIL = 55;
		static const Sbecore::uint TXFFAFDCTACTIVE = 56;
		static const Sbecore::uint BUTEQPNEWAVAIL = 57;
		static const Sbecore::uint BUTEQPDELETEAVAIL = 58;
		static const Sbecore::uint TXTEQPOPRAVAIL = 59;
		static const Sbecore::uint TXTEQPOPRACTIVE = 60;
		static const Sbecore::uint BUTEQPOPRVIEWAVAIL = 61;
		static const Sbecore::uint BUTEQPOPRVIEWACTIVE = 62;
		static const Sbecore::uint TXTEQPPTYAVAIL = 63;
		static const Sbecore::uint TXTEQPPTYACTIVE = 64;
		static const Sbecore::uint BUTEQPPTYVIEWAVAIL = 65;
		static const Sbecore::uint BUTEQPPTYVIEWACTIVE = 66;
		static const Sbecore::uint PUPEQPETYAVAIL = 67;
		static const Sbecore::uint PUPEQPETYACTIVE = 68;
		static const Sbecore::uint BUTEQPETYEDITAVAIL = 69;
		static const Sbecore::uint CHKEQPFIBAVAIL = 70;
		static const Sbecore::uint CHKEQPFIBACTIVE = 71;

	public:
		StatShr(const bool TxfEqpEtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtTtbActive = true, const bool ButTtbViewAvail = true, const bool ButTtbViewActive = true, const bool TxtLegActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxfXsaActive = true, const bool TxfXsoActive = true, const bool ChkCdnActive = true, const bool ChkSdnActive = true, const bool ButFafNewAvail = true, const bool ButFafDeleteAvail = true, const bool TxfFafFidAvail = true, const bool TxfFafFidActive = true, const bool TxfFafIdtAvail = true, const bool TxfFafIdtActive = true, const bool TxfFafActAvail = true, const bool TxfFafActActive = true, const bool TxfFafFetAvail = true, const bool TxfFafFetActive = true, const bool TxfFafFtiAvail = true, const bool TxfFafFtiActive = true, const bool TxfFafFdtAvail = true, const bool TxfFafFdtActive = true, const bool TxfFafFskAvail = true, const bool TxfFafFskActive = true, const bool TxfFafFsmAvail = true, const bool TxfFafFsmActive = true, const bool TxfFafFatAvail = true, const bool TxfFafFatActive = true, const bool TxfFafRteAvail = true, const bool TxfFafRteActive = true, const bool TxfFafAdtAvail = true, const bool TxfFafAdtActive = true, const bool TxfFafEatAvail = true, const bool TxfFafEatActive = true, const bool TxfFafAatAvail = true, const bool TxfFafAatActive = true, const bool TxfFafDvtAvail = true, const bool TxfFafDvtActive = true, const bool TxfFafOrgAvail = true, const bool TxfFafOrgActive = true, const bool TxfFafDstAvail = true, const bool TxfFafDstActive = true, const bool TxfFafOnmAvail = true, const bool TxfFafOnmActive = true, const bool TxfFafOctAvail = true, const bool TxfFafOctActive = true, const bool TxfFafDnmAvail = true, const bool TxfFafDnmActive = true, const bool TxfFafDctAvail = true, const bool TxfFafDctActive = true, const bool ButEqpNewAvail = true, const bool ButEqpDeleteAvail = true, const bool TxtEqpOprAvail = true, const bool TxtEqpOprActive = true, const bool ButEqpOprViewAvail = true, const bool ButEqpOprViewActive = true, const bool TxtEqpPtyAvail = true, const bool TxtEqpPtyActive = true, const bool ButEqpPtyViewAvail = true, const bool ButEqpPtyViewActive = true, const bool PupEqpEtyAvail = true, const bool PupEqpEtyActive = true, const bool ButEqpEtyEditAvail = true, const bool ChkEqpFibAvail = true, const bool ChkEqpFibActive = true);

	public:
		bool TxfEqpEtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtTtbActive;
		bool ButTtbViewAvail;
		bool ButTtbViewActive;
		bool TxtLegActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxfXsaActive;
		bool TxfXsoActive;
		bool ChkCdnActive;
		bool ChkSdnActive;
		bool ButFafNewAvail;
		bool ButFafDeleteAvail;
		bool TxfFafFidAvail;
		bool TxfFafFidActive;
		bool TxfFafIdtAvail;
		bool TxfFafIdtActive;
		bool TxfFafActAvail;
		bool TxfFafActActive;
		bool TxfFafFetAvail;
		bool TxfFafFetActive;
		bool TxfFafFtiAvail;
		bool TxfFafFtiActive;
		bool TxfFafFdtAvail;
		bool TxfFafFdtActive;
		bool TxfFafFskAvail;
		bool TxfFafFskActive;
		bool TxfFafFsmAvail;
		bool TxfFafFsmActive;
		bool TxfFafFatAvail;
		bool TxfFafFatActive;
		bool TxfFafRteAvail;
		bool TxfFafRteActive;
		bool TxfFafAdtAvail;
		bool TxfFafAdtActive;
		bool TxfFafEatAvail;
		bool TxfFafEatActive;
		bool TxfFafAatAvail;
		bool TxfFafAatActive;
		bool TxfFafDvtAvail;
		bool TxfFafDvtActive;
		bool TxfFafOrgAvail;
		bool TxfFafOrgActive;
		bool TxfFafDstAvail;
		bool TxfFafDstActive;
		bool TxfFafOnmAvail;
		bool TxfFafOnmActive;
		bool TxfFafOctAvail;
		bool TxfFafOctActive;
		bool TxfFafDnmAvail;
		bool TxfFafDnmActive;
		bool TxfFafDctAvail;
		bool TxfFafDctActive;
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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyFltDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFltDetailData)
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
		* DpchAppDo (full: DpchAppBrlyFltDetailDo)
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
		* DpchEngData (full: DpchEngBrlyFltDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPEQPETY = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupEqpEty = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupEqpEty;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsBrly* dbsbrly);
	bool evalButSaveActive(DbsBrly* dbsbrly);
	bool evalTxtSrfActive(DbsBrly* dbsbrly);
	bool evalTxtTtbActive(DbsBrly* dbsbrly);
	bool evalButTtbViewAvail(DbsBrly* dbsbrly);
	bool evalButTtbViewActive(DbsBrly* dbsbrly);
	bool evalTxtLegActive(DbsBrly* dbsbrly);
	bool evalTxfStaActive(DbsBrly* dbsbrly);
	bool evalTxfStoActive(DbsBrly* dbsbrly);
	bool evalTxfXsaActive(DbsBrly* dbsbrly);
	bool evalTxfXsoActive(DbsBrly* dbsbrly);
	bool evalChkCdnActive(DbsBrly* dbsbrly);
	bool evalChkSdnActive(DbsBrly* dbsbrly);
	bool evalButFafNewAvail(DbsBrly* dbsbrly);
	bool evalButFafDeleteAvail(DbsBrly* dbsbrly);
	bool evalTxfFafFidAvail(DbsBrly* dbsbrly);
	bool evalTxfFafFidActive(DbsBrly* dbsbrly);
	bool evalTxfFafIdtAvail(DbsBrly* dbsbrly);
	bool evalTxfFafIdtActive(DbsBrly* dbsbrly);
	bool evalTxfFafActAvail(DbsBrly* dbsbrly);
	bool evalTxfFafActActive(DbsBrly* dbsbrly);
	bool evalTxfFafFetAvail(DbsBrly* dbsbrly);
	bool evalTxfFafFetActive(DbsBrly* dbsbrly);
	bool evalTxfFafFtiAvail(DbsBrly* dbsbrly);
	bool evalTxfFafFtiActive(DbsBrly* dbsbrly);
	bool evalTxfFafFdtAvail(DbsBrly* dbsbrly);
	bool evalTxfFafFdtActive(DbsBrly* dbsbrly);
	bool evalTxfFafFskAvail(DbsBrly* dbsbrly);
	bool evalTxfFafFskActive(DbsBrly* dbsbrly);
	bool evalTxfFafFsmAvail(DbsBrly* dbsbrly);
	bool evalTxfFafFsmActive(DbsBrly* dbsbrly);
	bool evalTxfFafFatAvail(DbsBrly* dbsbrly);
	bool evalTxfFafFatActive(DbsBrly* dbsbrly);
	bool evalTxfFafRteAvail(DbsBrly* dbsbrly);
	bool evalTxfFafRteActive(DbsBrly* dbsbrly);
	bool evalTxfFafAdtAvail(DbsBrly* dbsbrly);
	bool evalTxfFafAdtActive(DbsBrly* dbsbrly);
	bool evalTxfFafEatAvail(DbsBrly* dbsbrly);
	bool evalTxfFafEatActive(DbsBrly* dbsbrly);
	bool evalTxfFafAatAvail(DbsBrly* dbsbrly);
	bool evalTxfFafAatActive(DbsBrly* dbsbrly);
	bool evalTxfFafDvtAvail(DbsBrly* dbsbrly);
	bool evalTxfFafDvtActive(DbsBrly* dbsbrly);
	bool evalTxfFafOrgAvail(DbsBrly* dbsbrly);
	bool evalTxfFafOrgActive(DbsBrly* dbsbrly);
	bool evalTxfFafDstAvail(DbsBrly* dbsbrly);
	bool evalTxfFafDstActive(DbsBrly* dbsbrly);
	bool evalTxfFafOnmAvail(DbsBrly* dbsbrly);
	bool evalTxfFafOnmActive(DbsBrly* dbsbrly);
	bool evalTxfFafOctAvail(DbsBrly* dbsbrly);
	bool evalTxfFafOctActive(DbsBrly* dbsbrly);
	bool evalTxfFafDnmAvail(DbsBrly* dbsbrly);
	bool evalTxfFafDnmActive(DbsBrly* dbsbrly);
	bool evalTxfFafDctAvail(DbsBrly* dbsbrly);
	bool evalTxfFafDctActive(DbsBrly* dbsbrly);
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
	PnlBrlyFltDetail(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyFltDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupEqpEty;

	BrlyMFlight recFlt;

	BrlyMFaflight recFaf;

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

	void refreshRecFlt(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshRecFaf(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
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
	void handleDpchAppDoButTtbViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFafNewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFafDeleteClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEqpNewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEqpDeleteClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEqpOprViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEqpPtyViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButEqpEtyEditClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyKlsAkeyMod_klsEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallBrlyFltUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyEqpUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyFafUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyFlt_ttbEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyFlt_fafEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyFlt_eqpEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_ptyEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_oprEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallBrlyEqp_inSbs(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallBrlyEqp_hktEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
