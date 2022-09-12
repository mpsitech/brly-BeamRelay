/**
	* \file PnlBrlyConMap.h
	* job handler for job PnlBrlyConMap (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYCONMAP_H
#define PNLBRLYCONMAP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryBrlyConMapRelay.h"
#include "QryBrlyConMapLocation.h"
#include "QryBrlyConMapNode.h"
#include "QryBrlyConMapLeg.h"
#include "QryBrlyConMapFlight.h"

#define VecVBrlyConMapDo PnlBrlyConMap::VecVDo
#define VecVBrlyConMapSge PnlBrlyConMap::VecVSge

#define ContIacBrlyConMap PnlBrlyConMap::ContIac
#define ContInfBrlyConMap PnlBrlyConMap::ContInf
#define StatAppBrlyConMap PnlBrlyConMap::StatApp
#define StatShrBrlyConMap PnlBrlyConMap::StatShr
#define StgIacBrlyConMap PnlBrlyConMap::StgIac
#define TagBrlyConMap PnlBrlyConMap::Tag

#define DpchAppBrlyConMapData PnlBrlyConMap::DpchAppData
#define DpchAppBrlyConMapDo PnlBrlyConMap::DpchAppDo
#define DpchEngBrlyConMapData PnlBrlyConMap::DpchEngData
#define DpchEngBrlyConMapImage PnlBrlyConMap::DpchEngImage

/**
	* PnlBrlyConMap
	*/
class PnlBrlyConMap : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyConMapDo)
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
		* VecVSge (full: VecVBrlyConMapSge)
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
	  * ContIac (full: ContIacBrlyConMap)
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
	  * ContInf (full: ContInfBrlyConMap)
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
		* StatApp (full: StatAppBrlyConMap)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint t = 0, const bool running = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint t = 0, const bool running = false);
	};

	/**
		* StatShr (full: StatShrBrlyConMap)
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
		* StgIac (full: StgIacBrlyConMap)
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
		* Tag (full: TagBrlyConMap)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyConMapData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIACQRYFLIGHT = 3;
		static const Sbecore::uint STGIACQRYLEG = 4;
		static const Sbecore::uint STGIACQRYLOCATION = 5;
		static const Sbecore::uint STGIACQRYNODE = 6;
		static const Sbecore::uint STGIACQRYRELAY = 7;
		static const Sbecore::uint STGIAC = 8;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		QryBrlyConMapFlight::StgIac stgiacqryflight;
		QryBrlyConMapLeg::StgIac stgiacqryleg;
		QryBrlyConMapLocation::StgIac stgiacqrylocation;
		QryBrlyConMapNode::StgIac stgiacqrynode;
		QryBrlyConMapRelay::StgIac stgiacqryrelay;
		StgIac stgiac;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyConMapDo)
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
		* DpchEngData (full: DpchEngBrlyConMapData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFSGE = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint RSTFLIGHT = 7;
		static const Sbecore::uint RSTLEG = 8;
		static const Sbecore::uint RSTLOCATION = 9;
		static const Sbecore::uint RSTNODE = 10;
		static const Sbecore::uint RSTRELAY = 11;
		static const Sbecore::uint STATSHRQRYFLIGHT = 12;
		static const Sbecore::uint STATSHRQRYLEG = 13;
		static const Sbecore::uint STATSHRQRYLOCATION = 14;
		static const Sbecore::uint STATSHRQRYNODE = 15;
		static const Sbecore::uint STATSHRQRYRELAY = 16;
		static const Sbecore::uint STGIACQRYFLIGHT = 17;
		static const Sbecore::uint STGIACQRYLEG = 18;
		static const Sbecore::uint STGIACQRYLOCATION = 19;
		static const Sbecore::uint STGIACQRYNODE = 20;
		static const Sbecore::uint STGIACQRYRELAY = 21;
		static const Sbecore::uint STATAPP = 22;
		static const Sbecore::uint STGIAC = 23;
		static const Sbecore::uint ALL = 24;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, ListBrlyQConMapFlight* rstflight = NULL, ListBrlyQConMapLeg* rstleg = NULL, ListBrlyQConMapLocation* rstlocation = NULL, ListBrlyQConMapNode* rstnode = NULL, ListBrlyQConMapRelay* rstrelay = NULL, QryBrlyConMapFlight::StatShr* statshrqryflight = NULL, QryBrlyConMapLeg::StatShr* statshrqryleg = NULL, QryBrlyConMapLocation::StatShr* statshrqrylocation = NULL, QryBrlyConMapNode::StatShr* statshrqrynode = NULL, QryBrlyConMapRelay::StatShr* statshrqryrelay = NULL, QryBrlyConMapFlight::StgIac* stgiacqryflight = NULL, QryBrlyConMapLeg::StgIac* stgiacqryleg = NULL, QryBrlyConMapLocation::StgIac* stgiacqrylocation = NULL, QryBrlyConMapNode::StgIac* stgiacqrynode = NULL, QryBrlyConMapRelay::StgIac* stgiacqryrelay = NULL, StgIac* stgiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		ListBrlyQConMapFlight rstflight;
		ListBrlyQConMapLeg rstleg;
		ListBrlyQConMapLocation rstlocation;
		ListBrlyQConMapNode rstnode;
		ListBrlyQConMapRelay rstrelay;
		QryBrlyConMapFlight::StatShr statshrqryflight;
		QryBrlyConMapLeg::StatShr statshrqryleg;
		QryBrlyConMapLocation::StatShr statshrqrylocation;
		QryBrlyConMapNode::StatShr statshrqrynode;
		QryBrlyConMapRelay::StatShr statshrqryrelay;
		QryBrlyConMapFlight::StgIac stgiacqryflight;
		QryBrlyConMapLeg::StgIac stgiacqryleg;
		QryBrlyConMapLocation::StgIac stgiacqrylocation;
		QryBrlyConMapNode::StgIac stgiacqrynode;
		QryBrlyConMapRelay::StgIac stgiacqryrelay;
		StgIac stgiac;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	/**
		* DpchEngImage (full: DpchEngBrlyConMapImage)
		*/
	class DpchEngImage : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint RSTLEG = 2;
		static const Sbecore::uint RSTLOCATION = 3;
		static const Sbecore::uint RSTFLIGHT = 4;
		static const Sbecore::uint RSTRELAY = 5;
		static const Sbecore::uint RSTNODE = 6;
		static const Sbecore::uint STATSHRQRYLEG = 7;
		static const Sbecore::uint STATSHRQRYLOCATION = 8;
		static const Sbecore::uint STATSHRQRYFLIGHT = 9;
		static const Sbecore::uint STATSHRQRYRELAY = 10;
		static const Sbecore::uint STATSHRQRYNODE = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngImage(const Sbecore::ubigint jref = 0, ListBrlyQConMapLeg* rstleg = NULL, ListBrlyQConMapLocation* rstlocation = NULL, ListBrlyQConMapFlight* rstflight = NULL, ListBrlyQConMapRelay* rstrelay = NULL, ListBrlyQConMapNode* rstnode = NULL, QryBrlyConMapLeg::StatShr* statshrqryleg = NULL, QryBrlyConMapLocation::StatShr* statshrqrylocation = NULL, QryBrlyConMapFlight::StatShr* statshrqryflight = NULL, QryBrlyConMapRelay::StatShr* statshrqryrelay = NULL, QryBrlyConMapNode::StatShr* statshrqrynode = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ListBrlyQConMapLeg rstleg;
		ListBrlyQConMapLocation rstlocation;
		ListBrlyQConMapFlight rstflight;
		ListBrlyQConMapRelay rstrelay;
		ListBrlyQConMapNode rstnode;
		QryBrlyConMapLeg::StatShr statshrqryleg;
		QryBrlyConMapLocation::StatShr statshrqrylocation;
		QryBrlyConMapFlight::StatShr statshrqryflight;
		QryBrlyConMapRelay::StatShr statshrqryrelay;
		QryBrlyConMapNode::StatShr statshrqrynode;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

public:
	PnlBrlyConMap(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyConMap();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFSge;

	QryBrlyConMapRelay* qryrelay;
	QryBrlyConMapLocation* qrylocation;
	QryBrlyConMapNode* qrynode;
	QryBrlyConMapLeg* qryleg;
	QryBrlyConMapFlight* qryflight;

	// IP vars.cust --- IBEGIN
	Sbecore::uint wkm;
	Sbecore::uint hkm;

	bool standalone;
	bool wrtree;

	std::string srcfile;
	std::string tgzfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	void calcDist(DbsBrly* dbsbrly);
	// IP cust --- IEND

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
	void handleDpchAppDataStgiacqryflight(DbsBrly* dbsbrly, QryBrlyConMapFlight::StgIac* _stgiacqryflight, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqryleg(DbsBrly* dbsbrly, QryBrlyConMapLeg::StgIac* _stgiacqryleg, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqrylocation(DbsBrly* dbsbrly, QryBrlyConMapLocation::StgIac* _stgiacqrylocation, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqrynode(DbsBrly* dbsbrly, QryBrlyConMapNode::StgIac* _stgiacqrynode, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqryrelay(DbsBrly* dbsbrly, QryBrlyConMapRelay::StgIac* _stgiacqryrelay, DpchEngBrly** dpcheng);
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
