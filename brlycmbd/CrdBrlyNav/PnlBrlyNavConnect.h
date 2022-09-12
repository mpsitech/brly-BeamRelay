/**
	* \file PnlBrlyNavConnect.h
	* job handler for job PnlBrlyNavConnect (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYNAVCONNECT_H
#define PNLBRLYNAVCONNECT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVBrlyNavConnectDo PnlBrlyNavConnect::VecVDo

#define ContIacBrlyNavConnect PnlBrlyNavConnect::ContIac
#define StatAppBrlyNavConnect PnlBrlyNavConnect::StatApp
#define StatShrBrlyNavConnect PnlBrlyNavConnect::StatShr
#define TagBrlyNavConnect PnlBrlyNavConnect::Tag

#define DpchAppBrlyNavConnectData PnlBrlyNavConnect::DpchAppData
#define DpchAppBrlyNavConnectDo PnlBrlyNavConnect::DpchAppDo
#define DpchEngBrlyNavConnectData PnlBrlyNavConnect::DpchEngData

/**
	* PnlBrlyNavConnect
	*/
class PnlBrlyNavConnect : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyNavConnectDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCONVIEWCLICK = 1;
		static const Sbecore::uint BUTCONNEWCRDCLICK = 2;
		static const Sbecore::uint BUTRLYVIEWCLICK = 3;
		static const Sbecore::uint BUTRLYNEWCRDCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyNavConnect)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTCON = 1;
		static const Sbecore::uint NUMFLSTRLY = 2;

	public:
		ContIac(const Sbecore::uint numFLstCon = 1, const Sbecore::uint numFLstRly = 1);

	public:
		Sbecore::uint numFLstCon;
		Sbecore::uint numFLstRly;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppBrlyNavConnect)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstConAlt = true, const bool LstRlyAlt = true, const Sbecore::uint LstConNumFirstdisp = 1, const Sbecore::uint LstRlyNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstConAlt = true, const bool LstRlyAlt = true, const Sbecore::uint LstConNumFirstdisp = 1, const Sbecore::uint LstRlyNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrBrlyNavConnect)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTCONAVAIL = 1;
		static const Sbecore::uint BUTCONVIEWACTIVE = 2;
		static const Sbecore::uint LSTRLYAVAIL = 3;
		static const Sbecore::uint BUTRLYVIEWACTIVE = 4;

	public:
		StatShr(const bool LstConAvail = true, const bool ButConViewActive = true, const bool LstRlyAvail = true, const bool ButRlyViewActive = true);

	public:
		bool LstConAvail;
		bool ButConViewActive;
		bool LstRlyAvail;
		bool ButRlyViewActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagBrlyNavConnect)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyNavConnectData)
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
		* DpchAppDo (full: DpchAppBrlyNavConnectDo)
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
		* DpchEngData (full: DpchEngBrlyNavConnectData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCON = 3;
		static const Sbecore::uint FEEDFLSTRLY = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstCon = NULL, Sbecore::Feed* feedFLstRly = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstCon;
		Sbecore::Feed feedFLstRly;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalLstConAvail(DbsBrly* dbsbrly);
	bool evalButConViewActive(DbsBrly* dbsbrly);
	bool evalLstRlyAvail(DbsBrly* dbsbrly);
	bool evalButRlyViewActive(DbsBrly* dbsbrly);

public:
	PnlBrlyNavConnect(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyNavConnect();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstCon;
	Sbecore::Feed feedFLstRly;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstCon(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshCon(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshLstRly(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refreshRly(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems);
	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButConViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButConNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRlyViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRlyNewcrdClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyHusrRunvMod_crdUsrEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
