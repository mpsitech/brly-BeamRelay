/**
	* \file PnlBrlyNavBase.h
	* job handler for job PnlBrlyNavBase (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYNAVBASE_H
#define PNLBRLYNAVBASE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyNavBaseDo PnlBrlyNavBase::VecVDo

#define ContIacBrlyNavBase PnlBrlyNavBase::ContIac
#define StatAppBrlyNavBase PnlBrlyNavBase::StatApp
#define StatShrBrlyNavBase PnlBrlyNavBase::StatShr
#define TagBrlyNavBase PnlBrlyNavBase::Tag

#define DpchAppBrlyNavBaseData PnlBrlyNavBase::DpchAppData
#define DpchAppBrlyNavBaseDo PnlBrlyNavBase::DpchAppDo
#define DpchEngBrlyNavBaseData PnlBrlyNavBase::DpchEngData

/**
	* PnlBrlyNavBase
	*/
class PnlBrlyNavBase : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyNavBaseDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGVIEWCLICK = 1;
		static const Sbecore::uint BUTREGNEWCRDCLICK = 2;
		static const Sbecore::uint BUTLOCVIEWCLICK = 3;
		static const Sbecore::uint BUTLOCNEWCRDCLICK = 4;
		static const Sbecore::uint BUTLEGVIEWCLICK = 5;
		static const Sbecore::uint BUTLEGNEWCRDCLICK = 6;
		static const Sbecore::uint BUTTTBVIEWCLICK = 7;
		static const Sbecore::uint BUTTTBNEWCRDCLICK = 8;
		static const Sbecore::uint BUTFLTVIEWCLICK = 9;
		static const Sbecore::uint BUTFLTNEWCRDCLICK = 10;
		static const Sbecore::uint BUTSEGVIEWCLICK = 11;
		static const Sbecore::uint BUTSEGNEWCRDCLICK = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyNavBase)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTREG = 1;
		static const Sbecore::uint NUMFLSTLOC = 2;
		static const Sbecore::uint NUMFLSTLEG = 3;
		static const Sbecore::uint NUMFLSTTTB = 4;
		static const Sbecore::uint NUMFLSTFLT = 5;
		static const Sbecore::uint NUMFLSTSEG = 6;

	public:
		ContIac(const Sbecore::uint numFLstReg = 1, const Sbecore::uint numFLstLoc = 1, const Sbecore::uint numFLstLeg = 1, const Sbecore::uint numFLstTtb = 1, const Sbecore::uint numFLstFlt = 1, const Sbecore::uint numFLstSeg = 1);

	public:
		Sbecore::uint numFLstReg;
		Sbecore::uint numFLstLoc;
		Sbecore::uint numFLstLeg;
		Sbecore::uint numFLstTtb;
		Sbecore::uint numFLstFlt;
		Sbecore::uint numFLstSeg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppBrlyNavBase)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstRegAlt = true, const bool LstLocAlt = true, const bool LstLegAlt = true, const bool LstTtbAlt = true, const bool LstFltAlt = true, const bool LstSegAlt = true, const Sbecore::uint LstRegNumFirstdisp = 1, const Sbecore::uint LstLocNumFirstdisp = 1, const Sbecore::uint LstLegNumFirstdisp = 1, const Sbecore::uint LstTtbNumFirstdisp = 1, const Sbecore::uint LstFltNumFirstdisp = 1, const Sbecore::uint LstSegNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyNavBase)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTREGAVAIL = 1;
		static const Sbecore::uint BUTREGVIEWACTIVE = 2;
		static const Sbecore::uint LSTLOCAVAIL = 3;
		static const Sbecore::uint BUTLOCVIEWACTIVE = 4;
		static const Sbecore::uint LSTLEGAVAIL = 5;
		static const Sbecore::uint BUTLEGVIEWACTIVE = 6;
		static const Sbecore::uint LSTTTBAVAIL = 7;
		static const Sbecore::uint BUTTTBVIEWACTIVE = 8;
		static const Sbecore::uint LSTFLTAVAIL = 9;
		static const Sbecore::uint BUTFLTVIEWACTIVE = 10;
		static const Sbecore::uint LSTSEGAVAIL = 11;
		static const Sbecore::uint BUTSEGVIEWACTIVE = 12;

	public:
		StatShr(const bool LstRegAvail = true, const bool ButRegViewActive = true, const bool LstLocAvail = true, const bool ButLocViewActive = true, const bool LstLegAvail = true, const bool ButLegViewActive = true, const bool LstTtbAvail = true, const bool ButTtbViewActive = true, const bool LstFltAvail = true, const bool ButFltViewActive = true, const bool LstSegAvail = true, const bool ButSegViewActive = true);

	public:
		bool LstRegAvail;
		bool ButRegViewActive;
		bool LstLocAvail;
		bool ButLocViewActive;
		bool LstLegAvail;
		bool ButLegViewActive;
		bool LstTtbAvail;
		bool ButTtbViewActive;
		bool LstFltAvail;
		bool ButFltViewActive;
		bool LstSegAvail;
		bool ButSegViewActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyNavBase)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyNavBaseData)
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
		* DpchAppDo (full: DpchAppBrlyNavBaseDo)
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
		* DpchEngData (full: DpchEngBrlyNavBaseData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTFLT = 3;
		static const Sbecore::uint FEEDFLSTLEG = 4;
		static const Sbecore::uint FEEDFLSTLOC = 5;
		static const Sbecore::uint FEEDFLSTREG = 6;
		static const Sbecore::uint FEEDFLSTSEG = 7;
		static const Sbecore::uint FEEDFLSTTTB = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint TAG = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstFlt = NULL, Sbecore::Xmlio::Feed* feedFLstLeg = NULL, Sbecore::Xmlio::Feed* feedFLstLoc = NULL, Sbecore::Xmlio::Feed* feedFLstReg = NULL, Sbecore::Xmlio::Feed* feedFLstSeg = NULL, Sbecore::Xmlio::Feed* feedFLstTtb = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstFlt;
		Sbecore::Xmlio::Feed feedFLstLeg;
		Sbecore::Xmlio::Feed feedFLstLoc;
		Sbecore::Xmlio::Feed feedFLstReg;
		Sbecore::Xmlio::Feed feedFLstSeg;
		Sbecore::Xmlio::Feed feedFLstTtb;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalLstRegAvail(DbsBrly* dbsbrly);
	bool evalButRegViewActive(DbsBrly* dbsbrly);
	bool evalLstLocAvail(DbsBrly* dbsbrly);
	bool evalButLocViewActive(DbsBrly* dbsbrly);
	bool evalLstLegAvail(DbsBrly* dbsbrly);
	bool evalButLegViewActive(DbsBrly* dbsbrly);
	bool evalLstTtbAvail(DbsBrly* dbsbrly);
	bool evalButTtbViewActive(DbsBrly* dbsbrly);
	bool evalLstFltAvail(DbsBrly* dbsbrly);
	bool evalButFltViewActive(DbsBrly* dbsbrly);
	bool evalLstSegAvail(DbsBrly* dbsbrly);
	bool evalButSegViewActive(DbsBrly* dbsbrly);

public:
	PnlBrlyNavBase(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyNavBase();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstFlt;
	Sbecore::Xmlio::Feed feedFLstLeg;
	Sbecore::Xmlio::Feed feedFLstLoc;
	Sbecore::Xmlio::Feed feedFLstReg;
	Sbecore::Xmlio::Feed feedFLstSeg;
	Sbecore::Xmlio::Feed feedFLstTtb;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstReg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshReg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstLoc(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLoc(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstLeg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLeg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstTtb(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshTtb(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstFlt(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshFlt(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstSeg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshSeg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButRegViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRegNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButLocViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButLocNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButLegViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButLegNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButTtbViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButTtbNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFltViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFltNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButSegViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButSegNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyHusrRunvMod_crdUsrEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
