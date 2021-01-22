/**
	* \file PnlBrlyFltFafAWaypoint.h
	* job handler for job PnlBrlyFltFafAWaypoint (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYFLTFAFAWAYPOINT_H
#define PNLBRLYFLTFAFAWAYPOINT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryBrlyFltFafAWaypoint.h"

#define VecVBrlyFltFafAWaypointDo PnlBrlyFltFafAWaypoint::VecVDo

#define ContInfBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::ContInf
#define StatAppBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::StatApp
#define StatShrBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::StatShr
#define StgIacBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::StgIac
#define TagBrlyFltFafAWaypoint PnlBrlyFltFafAWaypoint::Tag

#define DpchAppBrlyFltFafAWaypointData PnlBrlyFltFafAWaypoint::DpchAppData
#define DpchAppBrlyFltFafAWaypointDo PnlBrlyFltFafAWaypoint::DpchAppDo
#define DpchEngBrlyFltFafAWaypointData PnlBrlyFltFafAWaypoint::DpchEngData

/**
	* PnlBrlyFltFafAWaypoint
	*/
class PnlBrlyFltFafAWaypoint : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyFltFafAWaypointDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUPCLICK = 1;
		static const Sbecore::uint BUTDOWNCLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDUPLICATECLICK = 4;
		static const Sbecore::uint BUTDELETECLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyFltFafAWaypoint)
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
		* StatApp (full: StatAppBrlyFltFafAWaypoint)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrBrlyFltFafAWaypoint)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTUPAVAIL = 1;
		static const Sbecore::uint BUTUPACTIVE = 2;
		static const Sbecore::uint BUTDOWNAVAIL = 3;
		static const Sbecore::uint BUTDOWNACTIVE = 4;
		static const Sbecore::uint BUTNEWAVAIL = 5;
		static const Sbecore::uint BUTDUPLICATEAVAIL = 6;
		static const Sbecore::uint BUTDUPLICATEACTIVE = 7;
		static const Sbecore::uint BUTDELETEAVAIL = 8;
		static const Sbecore::uint BUTDELETEACTIVE = 9;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacBrlyFltFafAWaypoint)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOTMSWIDTH = 1;
		static const Sbecore::uint TCOLATWIDTH = 2;
		static const Sbecore::uint TCOLONWIDTH = 3;
		static const Sbecore::uint TCOGSPWIDTH = 4;
		static const Sbecore::uint TCOALTWIDTH = 5;
		static const Sbecore::uint TCOASTWIDTH = 6;
		static const Sbecore::uint TCOUTYWIDTH = 7;
		static const Sbecore::uint TCOACHWIDTH = 8;

	public:
		StgIac(const Sbecore::uint TcoTmsWidth = 100, const Sbecore::uint TcoLatWidth = 100, const Sbecore::uint TcoLonWidth = 100, const Sbecore::uint TcoGspWidth = 100, const Sbecore::uint TcoAltWidth = 100, const Sbecore::uint TcoAstWidth = 100, const Sbecore::uint TcoUtyWidth = 100, const Sbecore::uint TcoAchWidth = 100);

	public:
		Sbecore::uint TcoTmsWidth;
		Sbecore::uint TcoLatWidth;
		Sbecore::uint TcoLonWidth;
		Sbecore::uint TcoGspWidth;
		Sbecore::uint TcoAltWidth;
		Sbecore::uint TcoAstWidth;
		Sbecore::uint TcoUtyWidth;
		Sbecore::uint TcoAchWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagBrlyFltFafAWaypoint)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFltFafAWaypointData)
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
		QryBrlyFltFafAWaypoint::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyFltFafAWaypointDo)
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
		* DpchEngData (full: DpchEngBrlyFltFafAWaypointData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListBrlyQFltFafAWaypoint* rst = NULL, QryBrlyFltFafAWaypoint::StatShr* statshrqry = NULL, QryBrlyFltFafAWaypoint::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListBrlyQFltFafAWaypoint rst;
		QryBrlyFltFafAWaypoint::StatShr statshrqry;
		QryBrlyFltFafAWaypoint::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButUpAvail(DbsBrly* dbsbrly);
	bool evalButUpActive(DbsBrly* dbsbrly);
	bool evalButDownAvail(DbsBrly* dbsbrly);
	bool evalButDownActive(DbsBrly* dbsbrly);
	bool evalButNewAvail(DbsBrly* dbsbrly);
	bool evalButDuplicateAvail(DbsBrly* dbsbrly);
	bool evalButDuplicateActive(DbsBrly* dbsbrly);
	bool evalButDeleteAvail(DbsBrly* dbsbrly);
	bool evalButDeleteActive(DbsBrly* dbsbrly);

public:
	PnlBrlyFltFafAWaypoint(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyFltFafAWaypoint();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Xmlio::Feed feedFCsiQst;

	QryBrlyFltFafAWaypoint* qry;

	BrlyAMFaflightWaypoint recFafAwpt;

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
	void handleDpchAppDataStgiacqry(DbsBrly* dbsbrly, QryBrlyFltFafAWaypoint::StgIac* _stgiacqry, DpchEngBrly** dpcheng);

	void handleDpchAppDoButUpClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButDownClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButNewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButDuplicateClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);

};

#endif
