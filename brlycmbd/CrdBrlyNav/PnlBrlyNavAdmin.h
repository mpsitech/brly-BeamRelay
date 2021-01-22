/**
	* \file PnlBrlyNavAdmin.h
	* job handler for job PnlBrlyNavAdmin (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYNAVADMIN_H
#define PNLBRLYNAVADMIN_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyNavAdminDo PnlBrlyNavAdmin::VecVDo

#define ContIacBrlyNavAdmin PnlBrlyNavAdmin::ContIac
#define StatAppBrlyNavAdmin PnlBrlyNavAdmin::StatApp
#define StatShrBrlyNavAdmin PnlBrlyNavAdmin::StatShr
#define TagBrlyNavAdmin PnlBrlyNavAdmin::Tag

#define DpchAppBrlyNavAdminData PnlBrlyNavAdmin::DpchAppData
#define DpchAppBrlyNavAdminDo PnlBrlyNavAdmin::DpchAppDo
#define DpchEngBrlyNavAdminData PnlBrlyNavAdmin::DpchEngData

/**
	* PnlBrlyNavAdmin
	*/
class PnlBrlyNavAdmin : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyNavAdminDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUSGVIEWCLICK = 1;
		static const Sbecore::uint BUTUSGNEWCRDCLICK = 2;
		static const Sbecore::uint BUTUSRVIEWCLICK = 3;
		static const Sbecore::uint BUTUSRNEWCRDCLICK = 4;
		static const Sbecore::uint BUTPRSVIEWCLICK = 5;
		static const Sbecore::uint BUTPRSNEWCRDCLICK = 6;
		static const Sbecore::uint BUTFILVIEWCLICK = 7;
		static const Sbecore::uint BUTFILNEWCRDCLICK = 8;
		static const Sbecore::uint BUTOPRVIEWCLICK = 9;
		static const Sbecore::uint BUTOPRNEWCRDCLICK = 10;
		static const Sbecore::uint BUTPTYVIEWCLICK = 11;
		static const Sbecore::uint BUTPTYNEWCRDCLICK = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyNavAdmin)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTUSG = 1;
		static const Sbecore::uint NUMFLSTUSR = 2;
		static const Sbecore::uint NUMFLSTPRS = 3;
		static const Sbecore::uint NUMFLSTFIL = 4;
		static const Sbecore::uint NUMFLSTOPR = 5;
		static const Sbecore::uint NUMFLSTPTY = 6;

	public:
		ContIac(const Sbecore::uint numFLstUsg = 1, const Sbecore::uint numFLstUsr = 1, const Sbecore::uint numFLstPrs = 1, const Sbecore::uint numFLstFil = 1, const Sbecore::uint numFLstOpr = 1, const Sbecore::uint numFLstPty = 1);

	public:
		Sbecore::uint numFLstUsg;
		Sbecore::uint numFLstUsr;
		Sbecore::uint numFLstPrs;
		Sbecore::uint numFLstFil;
		Sbecore::uint numFLstOpr;
		Sbecore::uint numFLstPty;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppBrlyNavAdmin)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const bool LstFilAlt = true, const bool LstOprAlt = true, const bool LstPtyAlt = true, const Sbecore::uint LstUsgNumFirstdisp = 1, const Sbecore::uint LstUsrNumFirstdisp = 1, const Sbecore::uint LstPrsNumFirstdisp = 1, const Sbecore::uint LstFilNumFirstdisp = 1, const Sbecore::uint LstOprNumFirstdisp = 1, const Sbecore::uint LstPtyNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyNavAdmin)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTUSGAVAIL = 1;
		static const Sbecore::uint BUTUSGVIEWACTIVE = 2;
		static const Sbecore::uint LSTUSRAVAIL = 3;
		static const Sbecore::uint BUTUSRVIEWACTIVE = 4;
		static const Sbecore::uint LSTPRSAVAIL = 5;
		static const Sbecore::uint BUTPRSVIEWACTIVE = 6;
		static const Sbecore::uint LSTFILAVAIL = 7;
		static const Sbecore::uint BUTFILVIEWACTIVE = 8;
		static const Sbecore::uint LSTOPRAVAIL = 9;
		static const Sbecore::uint BUTOPRVIEWACTIVE = 10;
		static const Sbecore::uint LSTPTYAVAIL = 11;
		static const Sbecore::uint BUTPTYVIEWACTIVE = 12;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true, const bool LstOprAvail = true, const bool ButOprViewActive = true, const bool LstPtyAvail = true, const bool ButPtyViewActive = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;
		bool LstOprAvail;
		bool ButOprViewActive;
		bool LstPtyAvail;
		bool ButPtyViewActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyNavAdmin)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyNavAdminData)
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
		* DpchAppDo (full: DpchAppBrlyNavAdminDo)
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
		* DpchEngData (full: DpchEngBrlyNavAdminData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTFIL = 3;
		static const Sbecore::uint FEEDFLSTOPR = 4;
		static const Sbecore::uint FEEDFLSTPRS = 5;
		static const Sbecore::uint FEEDFLSTPTY = 6;
		static const Sbecore::uint FEEDFLSTUSG = 7;
		static const Sbecore::uint FEEDFLSTUSR = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint TAG = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstFil = NULL, Sbecore::Xmlio::Feed* feedFLstOpr = NULL, Sbecore::Xmlio::Feed* feedFLstPrs = NULL, Sbecore::Xmlio::Feed* feedFLstPty = NULL, Sbecore::Xmlio::Feed* feedFLstUsg = NULL, Sbecore::Xmlio::Feed* feedFLstUsr = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstFil;
		Sbecore::Xmlio::Feed feedFLstOpr;
		Sbecore::Xmlio::Feed feedFLstPrs;
		Sbecore::Xmlio::Feed feedFLstPty;
		Sbecore::Xmlio::Feed feedFLstUsg;
		Sbecore::Xmlio::Feed feedFLstUsr;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalLstUsgAvail(DbsBrly* dbsbrly);
	bool evalButUsgViewActive(DbsBrly* dbsbrly);
	bool evalLstUsrAvail(DbsBrly* dbsbrly);
	bool evalButUsrViewActive(DbsBrly* dbsbrly);
	bool evalLstPrsAvail(DbsBrly* dbsbrly);
	bool evalButPrsViewActive(DbsBrly* dbsbrly);
	bool evalLstFilAvail(DbsBrly* dbsbrly);
	bool evalButFilViewActive(DbsBrly* dbsbrly);
	bool evalLstOprAvail(DbsBrly* dbsbrly);
	bool evalButOprViewActive(DbsBrly* dbsbrly);
	bool evalLstPtyAvail(DbsBrly* dbsbrly);
	bool evalButPtyViewActive(DbsBrly* dbsbrly);

public:
	PnlBrlyNavAdmin(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyNavAdmin();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstFil;
	Sbecore::Xmlio::Feed feedFLstOpr;
	Sbecore::Xmlio::Feed feedFLstPrs;
	Sbecore::Xmlio::Feed feedFLstPty;
	Sbecore::Xmlio::Feed feedFLstUsg;
	Sbecore::Xmlio::Feed feedFLstUsr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstUsg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshUsg(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstUsr(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshUsr(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstPrs(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshPrs(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstFil(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshFil(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstOpr(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshOpr(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstPty(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshPty(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButUsgViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButUsgNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButUsrViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButUsrNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButPrsNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFilViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFilNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButOprViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButOprNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButPtyViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButPtyNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyHusrRunvMod_crdUsrEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
