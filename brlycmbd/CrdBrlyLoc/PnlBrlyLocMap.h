/**
	* \file PnlBrlyLocMap.h
	* job handler for job PnlBrlyLocMap (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYLOCMAP_H
#define PNLBRLYLOCMAP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryBrlyLocMapVisLocation.h"
#include "QryBrlyLocMapProxLocation.h"
#include "QryBrlyLocMapLeg.h"

#define VecVBrlyLocMapDo PnlBrlyLocMap::VecVDo
#define VecVBrlyLocMapSge PnlBrlyLocMap::VecVSge

#define ContIacBrlyLocMap PnlBrlyLocMap::ContIac
#define ContInfBrlyLocMap PnlBrlyLocMap::ContInf
#define StatShrBrlyLocMap PnlBrlyLocMap::StatShr
#define StgIacBrlyLocMap PnlBrlyLocMap::StgIac
#define TagBrlyLocMap PnlBrlyLocMap::Tag

#define DpchAppBrlyLocMapData PnlBrlyLocMap::DpchAppData
#define DpchAppBrlyLocMapDo PnlBrlyLocMap::DpchAppDo
#define DpchEngBrlyLocMapData PnlBrlyLocMap::DpchEngData
#define DpchEngBrlyLocMapImage PnlBrlyLocMap::DpchEngImage

/**
	* PnlBrlyLocMap
	*/
class PnlBrlyLocMap : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLocMapDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTHOMECLICK = 3;
		static const Sbecore::uint BUTREFRESHCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyLocMapSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint MAPGEN = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacBrlyLocMap)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint SLDH = 1;
		static const Sbecore::uint SLDV = 2;
		static const Sbecore::uint SLDSCL = 3;

	public:
		ContIac(const double SldH = 0.0, const double SldV = 0.0, const double SldScl = 1);

	public:
		double SldH;
		double SldV;
		double SldScl;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyLocMap)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint DLD = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& Dld = "file");

	public:
		Sbecore::uint numFSge;
		std::string Dld;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrBrlyLocMap)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXBRLYVEXPSTATE = 1;
		static const Sbecore::uint SLDHMIN = 2;
		static const Sbecore::uint SLDHMAX = 3;
		static const Sbecore::uint SLDVMIN = 4;
		static const Sbecore::uint SLDVMAX = 5;
		static const Sbecore::uint SLDSCLMIN = 6;
		static const Sbecore::uint SLDSCLMAX = 7;
		static const Sbecore::uint SLDSCLRAST = 8;

	public:
		StatShr(const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const double SldHMin = -1.0, const double SldHMax = 1.0, const double SldVMin = -1.0, const double SldVMax = 1.0, const double SldSclMin = 1, const double SldSclMax = 10, const double SldSclRast = 0.1);

	public:
		Sbecore::uint ixBrlyVExpstate;
		double SldHMin;
		double SldHMax;
		double SldVMin;
		double SldVMax;
		double SldSclMin;
		double SldSclMax;
		double SldSclRast;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacBrlyLocMap)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint WIDTH = 1;
		static const Sbecore::uint HEIGHT = 2;

	public:
		StgIac(const Sbecore::uint width = 400, const Sbecore::uint height = 300);

	public:
		Sbecore::uint width;
		Sbecore::uint height;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagBrlyLocMap)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLocMapData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIACQRYLEG = 3;
		static const Sbecore::uint STGIACQRYPROXLOCATION = 4;
		static const Sbecore::uint STGIACQRYVISLOCATION = 5;
		static const Sbecore::uint STGIAC = 6;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		QryBrlyLocMapLeg::StgIac stgiacqryleg;
		QryBrlyLocMapProxLocation::StgIac stgiacqryproxlocation;
		QryBrlyLocMapVisLocation::StgIac stgiacqryvislocation;
		StgIac stgiac;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocMapDo)
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
		* DpchEngData (full: DpchEngBrlyLocMapData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFSGE = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint RSTLEG = 7;
		static const Sbecore::uint RSTPROXLOCATION = 8;
		static const Sbecore::uint RSTVISLOCATION = 9;
		static const Sbecore::uint STATSHRQRYLEG = 10;
		static const Sbecore::uint STATSHRQRYPROXLOCATION = 11;
		static const Sbecore::uint STATSHRQRYVISLOCATION = 12;
		static const Sbecore::uint STGIACQRYLEG = 13;
		static const Sbecore::uint STGIACQRYPROXLOCATION = 14;
		static const Sbecore::uint STGIACQRYVISLOCATION = 15;
		static const Sbecore::uint STGIAC = 16;
		static const Sbecore::uint ALL = 17;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, ListBrlyQLocMapLeg* rstleg = NULL, ListBrlyQLocMapProxLocation* rstproxlocation = NULL, ListBrlyQLocMapVisLocation* rstvislocation = NULL, QryBrlyLocMapLeg::StatShr* statshrqryleg = NULL, QryBrlyLocMapProxLocation::StatShr* statshrqryproxlocation = NULL, QryBrlyLocMapVisLocation::StatShr* statshrqryvislocation = NULL, QryBrlyLocMapLeg::StgIac* stgiacqryleg = NULL, QryBrlyLocMapProxLocation::StgIac* stgiacqryproxlocation = NULL, QryBrlyLocMapVisLocation::StgIac* stgiacqryvislocation = NULL, StgIac* stgiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		ListBrlyQLocMapLeg rstleg;
		ListBrlyQLocMapProxLocation rstproxlocation;
		ListBrlyQLocMapVisLocation rstvislocation;
		QryBrlyLocMapLeg::StatShr statshrqryleg;
		QryBrlyLocMapProxLocation::StatShr statshrqryproxlocation;
		QryBrlyLocMapVisLocation::StatShr statshrqryvislocation;
		QryBrlyLocMapLeg::StgIac stgiacqryleg;
		QryBrlyLocMapProxLocation::StgIac stgiacqryproxlocation;
		QryBrlyLocMapVisLocation::StgIac stgiacqryvislocation;
		StgIac stgiac;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	/**
		* DpchEngImage (full: DpchEngBrlyLocMapImage)
		*/
	class DpchEngImage : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint RSTLEG = 2;
		static const Sbecore::uint RSTPROXLOCATION = 3;
		static const Sbecore::uint RSTVISLOCATION = 4;
		static const Sbecore::uint STATSHRQRYLEG = 5;
		static const Sbecore::uint STATSHRQRYPROXLOCATION = 6;
		static const Sbecore::uint STATSHRQRYVISLOCATION = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngImage(const Sbecore::ubigint jref = 0, ListBrlyQLocMapLeg* rstleg = NULL, ListBrlyQLocMapProxLocation* rstproxlocation = NULL, ListBrlyQLocMapVisLocation* rstvislocation = NULL, QryBrlyLocMapLeg::StatShr* statshrqryleg = NULL, QryBrlyLocMapProxLocation::StatShr* statshrqryproxlocation = NULL, QryBrlyLocMapVisLocation::StatShr* statshrqryvislocation = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ListBrlyQLocMapLeg rstleg;
		ListBrlyQLocMapProxLocation rstproxlocation;
		ListBrlyQLocMapVisLocation rstvislocation;
		QryBrlyLocMapLeg::StatShr statshrqryleg;
		QryBrlyLocMapProxLocation::StatShr statshrqryproxlocation;
		QryBrlyLocMapVisLocation::StatShr statshrqryvislocation;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

public:
	PnlBrlyLocMap(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyLocMap();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFSge;

	QryBrlyLocMapVisLocation* qryvislocation;
	QryBrlyLocMapProxLocation* qryproxlocation;
	QryBrlyLocMapLeg* qryleg;

	// IP vars.cust --- IBEGIN
	bool standalone;

	std::string srcfile;
	std::string tgzfile;
	// IP vars.cust --- IEND

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
	bool handleMapgen(DbsBrly* dbsbrly);

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqryleg(DbsBrly* dbsbrly, QryBrlyLocMapLeg::StgIac* _stgiacqryleg, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqryproxlocation(DbsBrly* dbsbrly, QryBrlyLocMapProxLocation::StgIac* _stgiacqryproxlocation, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqryvislocation(DbsBrly* dbsbrly, QryBrlyLocMapVisLocation::StgIac* _stgiacqryvislocation, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiac(DbsBrly* dbsbrly, StgIac* _stgiac, DpchEngBrly** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButHomeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

	std::string handleDownload(DbsBrly* dbsbrly);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);

private:
	void changeStage(DbsBrly* dbsbrly, Sbecore::uint _ixVSge, DpchEngBrly** dpcheng = NULL);

public:
	std::string getSquawk(DbsBrly* dbsbrly);

private:
	Sbecore::uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeMapgen(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeMapgen(DbsBrly* dbsbrly);

};

#endif
