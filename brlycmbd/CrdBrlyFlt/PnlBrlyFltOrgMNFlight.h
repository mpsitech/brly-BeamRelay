/**
	* \file PnlBrlyFltOrgMNFlight.h
	* job handler for job PnlBrlyFltOrgMNFlight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYFLTORGMNFLIGHT_H
#define PNLBRLYFLTORGMNFLIGHT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryBrlyFltOrgMNFlight.h"

#define VecVBrlyFltOrgMNFlightDo PnlBrlyFltOrgMNFlight::VecVDo

#define ContInfBrlyFltOrgMNFlight PnlBrlyFltOrgMNFlight::ContInf
#define StatAppBrlyFltOrgMNFlight PnlBrlyFltOrgMNFlight::StatApp
#define StatShrBrlyFltOrgMNFlight PnlBrlyFltOrgMNFlight::StatShr
#define StgIacBrlyFltOrgMNFlight PnlBrlyFltOrgMNFlight::StgIac
#define TagBrlyFltOrgMNFlight PnlBrlyFltOrgMNFlight::Tag

#define DpchAppBrlyFltOrgMNFlightData PnlBrlyFltOrgMNFlight::DpchAppData
#define DpchAppBrlyFltOrgMNFlightDo PnlBrlyFltOrgMNFlight::DpchAppDo
#define DpchEngBrlyFltOrgMNFlightData PnlBrlyFltOrgMNFlight::DpchEngData

/**
	* PnlBrlyFltOrgMNFlight
	*/
class PnlBrlyFltOrgMNFlight : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyFltOrgMNFlightDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTVIEWCLICK = 1;
		static const Sbecore::uint BUTADDCLICK = 2;
		static const Sbecore::uint BUTSUBCLICK = 3;
		static const Sbecore::uint BUTREFRESHCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyFltOrgMNFlight)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyFltOrgMNFlight)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyFltOrgMNFlight)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTVIEWAVAIL = 1;
		static const Sbecore::uint BUTVIEWACTIVE = 2;
		static const Sbecore::uint BUTADDAVAIL = 3;
		static const Sbecore::uint BUTSUBAVAIL = 4;
		static const Sbecore::uint BUTSUBACTIVE = 5;

	public:
		StatShr(const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButViewAvail;
		bool ButViewActive;
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacBrlyFltOrgMNFlight)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOMREFWIDTH = 1;
		static const Sbecore::uint TCOSTAWIDTH = 2;
		static const Sbecore::uint TCOSTOWIDTH = 3;
		static const Sbecore::uint TCOXSAWIDTH = 4;
		static const Sbecore::uint TCOXSOWIDTH = 5;

	public:
		StgIac(const Sbecore::uint TcoMrefWidth = 150, const Sbecore::uint TcoStaWidth = 175, const Sbecore::uint TcoStoWidth = 175, const Sbecore::uint TcoXsaWidth = 100, const Sbecore::uint TcoXsoWidth = 100);

	public:
		Sbecore::uint TcoMrefWidth;
		Sbecore::uint TcoStaWidth;
		Sbecore::uint TcoStoWidth;
		Sbecore::uint TcoXsaWidth;
		Sbecore::uint TcoXsoWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagBrlyFltOrgMNFlight)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFltOrgMNFlightData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryBrlyFltOrgMNFlight::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFltOrgMNFlightDo)
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
		* DpchEngData (full: DpchEngBrlyFltOrgMNFlightData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint STGIAC = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint RST = 8;
		static const Sbecore::uint STATAPPQRY = 9;
		static const Sbecore::uint STATSHRQRY = 10;
		static const Sbecore::uint STGIACQRY = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListBrlyQFltOrgMNFlight* rst = NULL, QryBrlyFltOrgMNFlight::StatShr* statshrqry = NULL, QryBrlyFltOrgMNFlight::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListBrlyQFltOrgMNFlight rst;
		QryBrlyFltOrgMNFlight::StatShr statshrqry;
		QryBrlyFltOrgMNFlight::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButViewAvail(DbsBrly* dbsbrly);
	bool evalButViewActive(DbsBrly* dbsbrly);
	bool evalButAddAvail(DbsBrly* dbsbrly);
	bool evalButSubAvail(DbsBrly* dbsbrly);
	bool evalButSubActive(DbsBrly* dbsbrly);

public:
	PnlBrlyFltOrgMNFlight(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyFltOrgMNFlight();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Xmlio::Feed feedFCsiQst;

	QryBrlyFltOrgMNFlight* qry;

	BrlyRMFlightMFlight recFltRflt;

	BrlyMFlight recFlt;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiac(DbsBrly* dbsbrly, StgIac* _stgiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqry(DbsBrly* dbsbrly, QryBrlyFltOrgMNFlight::StgIac* _stgiacqry, DpchEngBrly** dpcheng);

	void handleDpchAppDoButViewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButAddClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButSubClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);

};

#endif
