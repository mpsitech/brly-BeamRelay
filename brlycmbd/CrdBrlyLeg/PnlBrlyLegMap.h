/**
	* \file PnlBrlyLegMap.h
	* job handler for job PnlBrlyLegMap (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYLEGMAP_H
#define PNLBRLYLEGMAP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryBrlyLegMapLeg.h"
#include "QryBrlyLegMapLocation.h"

#define VecVBrlyLegMapDo PnlBrlyLegMap::VecVDo
#define VecVBrlyLegMapSge PnlBrlyLegMap::VecVSge

#define ContIacBrlyLegMap PnlBrlyLegMap::ContIac
#define ContInfBrlyLegMap PnlBrlyLegMap::ContInf
#define StatShrBrlyLegMap PnlBrlyLegMap::StatShr
#define StgIacBrlyLegMap PnlBrlyLegMap::StgIac
#define TagBrlyLegMap PnlBrlyLegMap::Tag

#define DpchAppBrlyLegMapData PnlBrlyLegMap::DpchAppData
#define DpchAppBrlyLegMapDo PnlBrlyLegMap::DpchAppDo
#define DpchEngBrlyLegMapData PnlBrlyLegMap::DpchEngData
#define DpchEngBrlyLegMapImage PnlBrlyLegMap::DpchEngImage

/**
	* PnlBrlyLegMap
	*/
class PnlBrlyLegMap : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLegMapDo)
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
		* VecVSge (full: VecVBrlyLegMapSge)
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
	  * ContIac (full: ContIacBrlyLegMap)
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
	  * ContInf (full: ContInfBrlyLegMap)
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
		* StatShr (full: StatShrBrlyLegMap)
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
		* StgIac (full: StgIacBrlyLegMap)
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
		* Tag (full: TagBrlyLegMap)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLegMapData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIACQRYLEG = 3;
		static const Sbecore::uint STGIACQRYLOCATION = 4;
		static const Sbecore::uint STGIAC = 5;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		QryBrlyLegMapLeg::StgIac stgiacqryleg;
		QryBrlyLegMapLocation::StgIac stgiacqrylocation;
		StgIac stgiac;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLegMapDo)
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
		* DpchEngData (full: DpchEngBrlyLegMapData)
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
		static const Sbecore::uint RSTLOCATION = 8;
		static const Sbecore::uint STATSHRQRYLEG = 9;
		static const Sbecore::uint STATSHRQRYLOCATION = 10;
		static const Sbecore::uint STGIACQRYLEG = 11;
		static const Sbecore::uint STGIACQRYLOCATION = 12;
		static const Sbecore::uint STGIAC = 13;
		static const Sbecore::uint ALL = 14;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, ListBrlyQLegMapLeg* rstleg = NULL, ListBrlyQLegMapLocation* rstlocation = NULL, QryBrlyLegMapLeg::StatShr* statshrqryleg = NULL, QryBrlyLegMapLocation::StatShr* statshrqrylocation = NULL, QryBrlyLegMapLeg::StgIac* stgiacqryleg = NULL, QryBrlyLegMapLocation::StgIac* stgiacqrylocation = NULL, StgIac* stgiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		ListBrlyQLegMapLeg rstleg;
		ListBrlyQLegMapLocation rstlocation;
		QryBrlyLegMapLeg::StatShr statshrqryleg;
		QryBrlyLegMapLocation::StatShr statshrqrylocation;
		QryBrlyLegMapLeg::StgIac stgiacqryleg;
		QryBrlyLegMapLocation::StgIac stgiacqrylocation;
		StgIac stgiac;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	/**
		* DpchEngImage (full: DpchEngBrlyLegMapImage)
		*/
	class DpchEngImage : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint RSTLEG = 2;
		static const Sbecore::uint RSTLOCATION = 3;
		static const Sbecore::uint STATSHRQRYLEG = 4;
		static const Sbecore::uint STATSHRQRYLOCATION = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngImage(const Sbecore::ubigint jref = 0, ListBrlyQLegMapLeg* rstleg = NULL, ListBrlyQLegMapLocation* rstlocation = NULL, QryBrlyLegMapLeg::StatShr* statshrqryleg = NULL, QryBrlyLegMapLocation::StatShr* statshrqrylocation = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ListBrlyQLegMapLeg rstleg;
		ListBrlyQLegMapLocation rstlocation;
		QryBrlyLegMapLeg::StatShr statshrqryleg;
		QryBrlyLegMapLocation::StatShr statshrqrylocation;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

public:
	PnlBrlyLegMap(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyLegMap();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFSge;

	QryBrlyLegMapLeg* qryleg;
	QryBrlyLegMapLocation* qrylocation;

	// IP vars.cust --- IBEGIN
	Sbecore::uint wkm;
	Sbecore::uint hkm;

	bool standalone;

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
	void handleDpchAppDataStgiacqryleg(DbsBrly* dbsbrly, QryBrlyLegMapLeg::StgIac* _stgiacqryleg, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqrylocation(DbsBrly* dbsbrly, QryBrlyLegMapLocation::StgIac* _stgiacqrylocation, DpchEngBrly** dpcheng);
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
