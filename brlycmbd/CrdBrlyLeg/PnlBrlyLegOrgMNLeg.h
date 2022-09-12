/**
	* \file PnlBrlyLegOrgMNLeg.h
	* job handler for job PnlBrlyLegOrgMNLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYLEGORGMNLEG_H
#define PNLBRLYLEGORGMNLEG_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryBrlyLegOrgMNLeg.h"

#define VecVBrlyLegOrgMNLegDo PnlBrlyLegOrgMNLeg::VecVDo

#define ContInfBrlyLegOrgMNLeg PnlBrlyLegOrgMNLeg::ContInf
#define StatAppBrlyLegOrgMNLeg PnlBrlyLegOrgMNLeg::StatApp
#define StatShrBrlyLegOrgMNLeg PnlBrlyLegOrgMNLeg::StatShr
#define StgIacBrlyLegOrgMNLeg PnlBrlyLegOrgMNLeg::StgIac
#define TagBrlyLegOrgMNLeg PnlBrlyLegOrgMNLeg::Tag

#define DpchAppBrlyLegOrgMNLegData PnlBrlyLegOrgMNLeg::DpchAppData
#define DpchAppBrlyLegOrgMNLegDo PnlBrlyLegOrgMNLeg::DpchAppDo
#define DpchEngBrlyLegOrgMNLegData PnlBrlyLegOrgMNLeg::DpchEngData

/**
	* PnlBrlyLegOrgMNLeg
	*/
class PnlBrlyLegOrgMNLeg : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLegOrgMNLegDo)
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
	  * ContInf (full: ContInfBrlyLegOrgMNLeg)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyLegOrgMNLeg)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyLegOrgMNLeg)
		*/
	class StatShr : public Sbecore::Block {

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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacBrlyLegOrgMNLeg)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOMREFWIDTH = 1;
		static const Sbecore::uint TCODP0WIDTH = 2;
		static const Sbecore::uint TCODP1WIDTH = 3;
		static const Sbecore::uint TCOOP0WIDTH = 4;
		static const Sbecore::uint TCOOP1WIDTH = 5;
		static const Sbecore::uint TCOXD0WIDTH = 6;
		static const Sbecore::uint TCOXD1WIDTH = 7;
		static const Sbecore::uint TCOXO0WIDTH = 8;
		static const Sbecore::uint TCOXO1WIDTH = 9;

	public:
		StgIac(const Sbecore::uint TcoMrefWidth = 250, const Sbecore::uint TcoDp0Width = 100, const Sbecore::uint TcoDp1Width = 100, const Sbecore::uint TcoOp0Width = 150, const Sbecore::uint TcoOp1Width = 150, const Sbecore::uint TcoXd0Width = 100, const Sbecore::uint TcoXd1Width = 100, const Sbecore::uint TcoXo0Width = 100, const Sbecore::uint TcoXo1Width = 100);

	public:
		Sbecore::uint TcoMrefWidth;
		Sbecore::uint TcoDp0Width;
		Sbecore::uint TcoDp1Width;
		Sbecore::uint TcoOp0Width;
		Sbecore::uint TcoOp1Width;
		Sbecore::uint TcoXd0Width;
		Sbecore::uint TcoXd1Width;
		Sbecore::uint TcoXo0Width;
		Sbecore::uint TcoXo1Width;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagBrlyLegOrgMNLeg)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLegOrgMNLegData)
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
		QryBrlyLegOrgMNLeg::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLegOrgMNLegDo)
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
		* DpchEngData (full: DpchEngBrlyLegOrgMNLegData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListBrlyQLegOrgMNLeg* rst = NULL, QryBrlyLegOrgMNLeg::StatShr* statshrqry = NULL, QryBrlyLegOrgMNLeg::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListBrlyQLegOrgMNLeg rst;
		QryBrlyLegOrgMNLeg::StatShr statshrqry;
		QryBrlyLegOrgMNLeg::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButViewAvail(DbsBrly* dbsbrly);
	bool evalButViewActive(DbsBrly* dbsbrly);
	bool evalButAddAvail(DbsBrly* dbsbrly);
	bool evalButSubAvail(DbsBrly* dbsbrly);
	bool evalButSubActive(DbsBrly* dbsbrly);

public:
	PnlBrlyLegOrgMNLeg(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyLegOrgMNLeg();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFCsiQst;

	QryBrlyLegOrgMNLeg* qry;

	BrlyRMLegMLeg recLegRleg;

	BrlyMLeg recLeg;
	Sbecore::uint ixWSubsetLeg;

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
	void handleDpchAppDataStgiacqry(DbsBrly* dbsbrly, QryBrlyLegOrgMNLeg::StgIac* _stgiacqry, DpchEngBrly** dpcheng);

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
