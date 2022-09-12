/**
	* \file Brlycmbd.h
	* inter-thread exchange object for Brly combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYCMBD_H
#define BRLYCMBD_H

#ifdef __CYGWIN__
	#include <sys/select.h>
#endif

#include <unistd.h>

#ifndef _WIN32
	#include <sys/socket.h>
#endif
#ifdef _WIN32
	#include <windows.h>
	#include <winsock.h>
	typedef int socklen_t;
#endif

#include <sys/stat.h>

#include <microhttpd.h>
#if MHD_VERSION < 0x0097002
	#define MHD_Result int
#endif

#include <sbecore/Txtrd.h>
#include <sbecore/DbsMon.h>

#include "Brly.h"

#include "SqkBrlyBase.h"
#include "SqkBrlyDnsmap.h"
#include "SqkBrlyDyn.h"
#include "SqkBrlyMapgen.h"
#include "SqkBrlyTtimp.h"

// IP include.cust --- INSERT

class XchgBrlycmbd;
typedef XchgBrlycmbd XchgBrly;

/**
	* DpchAppBrly
	*/
class DpchAppBrly : public DpchBrly {

public:
	static const Sbecore::uint JREF = 1;

public:
	DpchAppBrly(const Sbecore::uint ixBrlyVDpch = 0);
	virtual ~DpchAppBrly();

public:
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void readJSON(const Json::Value& sup, bool addbasetag = false);
	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppBrlyAlert
	*/
class DpchAppBrlyAlert : public DpchAppBrly {

public:
	static const Sbecore::uint JREF = 1;
	static const Sbecore::uint NUMFMCB = 2;

public:
	DpchAppBrlyAlert();

public:
	Sbecore::uint numFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readJSON(const Json::Value& sup, bool addbasetag = false);
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppBrlyInit
	*/
class DpchAppBrlyInit : public DpchAppBrly {

public:
	DpchAppBrlyInit();
};

/**
	* DpchAppBrlyResume
	*/
class DpchAppBrlyResume : public DpchAppBrly {

public:
	DpchAppBrlyResume();
};

/**
	* DpchEngBrly
	*/
class DpchEngBrly : public DpchBrly {

public:
	static const Sbecore::uint JREF = 1;

public:
	DpchEngBrly(const Sbecore::uint ixBrlyVDpch = 0, const Sbecore::ubigint jref = 0);
	virtual ~DpchEngBrly();

public:
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();
	virtual void merge(DpchEngBrly* dpcheng);

	virtual void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
	virtual void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngBrlyAck
	*/
class DpchEngBrlyAck : public DpchEngBrly {

public:
	DpchEngBrlyAck(const Sbecore::ubigint jref = 0);
};

/**
	* DpchEngBrlyAlert
	*/
class DpchEngBrlyAlert : public DpchEngBrly {

public:
	static const Sbecore::uint JREF = 1;
	static const Sbecore::uint CONTINF = 2;
	static const Sbecore::uint FEEDFMCB = 3;
	static const Sbecore::uint ALL = 4;

public:
	DpchEngBrlyAlert(const Sbecore::ubigint jref = 0, ContInfBrlyAlert* continf = NULL, Sbecore::Feed* feedFMcb = NULL, const std::set<Sbecore::uint>& mask = {NONE});

public:
	ContInfBrlyAlert continf;
	Sbecore::Feed feedFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();
	void merge(DpchEngBrly* dpcheng);

	void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
	void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngBrlyConfirm
	*/
class DpchEngBrlyConfirm : public DpchEngBrly {

public:
	static const Sbecore::uint ACCEPTED = 1;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREF = 3;
	static const Sbecore::uint ALL = 4;

public:
	DpchEngBrlyConfirm(const bool accepted = false, const Sbecore::ubigint jref = 0, const std::string& sref = "", const std::set<Sbecore::uint>& mask = {ALL});

public:
	bool accepted;
	std::string sref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();
	void merge(DpchEngBrly* dpcheng);

	void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
	void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngBrlySuspend
	*/
class DpchEngBrlySuspend : public DpchEngBrly {

public:
	DpchEngBrlySuspend(const Sbecore::ubigint jref = 0);
};

/**
	* StgBrlyAppearance
	*/
class StgBrlyAppearance : public Sbecore::Block {

public:
	static const Sbecore::uint HISTLENGTH = 1;
	static const Sbecore::uint SUSPSESS = 2;
	static const Sbecore::uint SESSTTERM = 3;
	static const Sbecore::uint SESSTWARN = 4;
	static const Sbecore::uint ROOTTTERM = 5;

public:
	StgBrlyAppearance(const Sbecore::usmallint histlength = 20, const bool suspsess = true, const Sbecore::uint sesstterm = 0, const Sbecore::uint sesstwarn = 0, const Sbecore::uint roottterm = 0);

public:
	Sbecore::usmallint histlength;
	bool suspsess;
	Sbecore::uint sesstterm;
	Sbecore::uint sesstwarn;
	Sbecore::uint roottterm;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgBrlyAppearance* comp);
	std::set<Sbecore::uint> diff(const StgBrlyAppearance* comp);
};

/**
	* StgBrlyAppsrv
	*/
class StgBrlyAppsrv : public Sbecore::Block {

public:
	static const Sbecore::uint PORT = 1;
	static const Sbecore::uint HTTPS = 2;
	static const Sbecore::uint CORS = 3;

public:
	StgBrlyAppsrv(const Sbecore::usmallint port = 13100, const bool https = false, const std::string& cors = "");

public:
	Sbecore::usmallint port;
	bool https;
	std::string cors;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgBrlyAppsrv* comp);
	std::set<Sbecore::uint> diff(const StgBrlyAppsrv* comp);
};

/**
	* StgBrlycmbd
	*/
class StgBrlycmbd : public Sbecore::Block {

public:
	static const Sbecore::uint JOBPRCN = 1;
	static const Sbecore::uint OPPRCN = 2;
	static const Sbecore::uint APPSRV = 3;

public:
	StgBrlycmbd(const Sbecore::usmallint jobprcn = 4, const Sbecore::usmallint opprcn = 1, const bool appsrv = true);

public:
	Sbecore::usmallint jobprcn;
	Sbecore::usmallint opprcn;
	bool appsrv;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgBrlycmbd* comp);
	std::set<Sbecore::uint> diff(const StgBrlycmbd* comp);
};

/**
	* StgBrlyDatabase
	*/
class StgBrlyDatabase : public Sbecore::Block {

public:
	static const Sbecore::uint IXDBSVDBSTYPE = 1;
	static const Sbecore::uint DBSPATH = 2;
	static const Sbecore::uint DBSNAME = 3;
	static const Sbecore::uint USERNAME = 4;
	static const Sbecore::uint PASSWORD = 5;
	static const Sbecore::uint IP = 6;
	static const Sbecore::uint PORT = 7;

public:
	StgBrlyDatabase(const Sbecore::uint ixDbsVDbstype = 0, const std::string& dbspath = "./DbsBrly.sql", const std::string& dbsname = "DbsBrly", const std::string& username = "mpsitech", const std::string& password = "f9w8feeh", const std::string& ip = "127.0.0.1", const Sbecore::usmallint port = 3306);

public:
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string username;
	std::string password;
	std::string ip;
	Sbecore::usmallint port;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgBrlyDatabase* comp);
	std::set<Sbecore::uint> diff(const StgBrlyDatabase* comp);
};

/**
	* StgBrlyFlightaware
	*/
class StgBrlyFlightaware : public Sbecore::Block {

public:
	static const Sbecore::uint IP = 1;
	static const Sbecore::uint KEY = 2;

public:
	StgBrlyFlightaware(const std::string& ip = "flightxml.flightaware.com/json/FlightXML2", const std::string& key = "YXdpcnRobToyMjY5NzU4ZmI0NGIxODQxNjBlZTk2NWU4ZTAyZjk3OTZkZTJmMzE0");

public:
	std::string ip;
	std::string key;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgBrlyFlightaware* comp);
	std::set<Sbecore::uint> diff(const StgBrlyFlightaware* comp);
};

/**
	* StgBrlyGeometry
	*/
class StgBrlyGeometry : public Sbecore::Block {

public:
	static const Sbecore::uint ACRALTITUDE = 1;
	static const Sbecore::uint CORRWIDTH1 = 2;
	static const Sbecore::uint CORRWIDTH2 = 3;
	static const Sbecore::uint EARTHRADIUS = 4;
	static const Sbecore::uint HRZNALTITUDE = 5;

public:
	StgBrlyGeometry(const double acraltitude = 10500, const double corrwidth1 = 100000, const double corrwidth2 = 500000, const double earthradius = 6371000, const double hrznaltitude = 2000);

public:
	double acraltitude;
	double corrwidth1;
	double corrwidth2;
	double earthradius;
	double hrznaltitude;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgBrlyGeometry* comp);
	std::set<Sbecore::uint> diff(const StgBrlyGeometry* comp);
};

/**
	* StgBrlyMonitor
	*/
class StgBrlyMonitor : public Sbecore::Block {

public:
	static const Sbecore::uint USERNAME = 1;
	static const Sbecore::uint PASSWORD = 2;
	static const Sbecore::uint IP = 3;
	static const Sbecore::uint PORT = 4;
	static const Sbecore::uint IXDBSVDBSTYPE = 5;
	static const Sbecore::uint DBSPATH = 6;
	static const Sbecore::uint DBSNAME = 7;
	static const Sbecore::uint DBSUSERNAME = 8;
	static const Sbecore::uint DBSPASSWORD = 9;

public:
	StgBrlyMonitor(const std::string& username = "wzemuser", const std::string& password = "asdf1234", const std::string& ip = "127.0.0.1", const Sbecore::usmallint port = 14100, const Sbecore::uint ixDbsVDbstype = 0, const std::string& dbspath = "./DbsWzem.sql", const std::string& dbsname = "DbsWzem", const std::string& dbsusername = "", const std::string& dbspassword = "");

public:
	std::string username;
	std::string password;
	std::string ip;
	Sbecore::usmallint port;
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string dbsusername;
	std::string dbspassword;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgBrlyMonitor* comp);
	std::set<Sbecore::uint> diff(const StgBrlyMonitor* comp);
};

/**
	* StgBrlyPath
	*/
class StgBrlyPath : public Sbecore::Block {

public:
	static const Sbecore::uint ACVPATH = 1;
	static const Sbecore::uint KEYPATH = 2;
	static const Sbecore::uint MONPATH = 3;
	static const Sbecore::uint TMPPATH = 4;
	static const Sbecore::uint WEBPATH = 5;
	static const Sbecore::uint HELPURL = 6;

public:
	StgBrlyPath(const std::string& acvpath = "${WHIZROOT}/acv/brly", const std::string& keypath = "", const std::string& monpath = "${WHIZROOT}/mon/brly", const std::string& tmppath = "${WHIZROOT}/tmp/brly", const std::string& webpath = "${WHIZROOT}/web/appbrly", const std::string& helpurl = "/brly");

public:
	std::string acvpath;
	std::string keypath;
	std::string monpath;
	std::string tmppath;
	std::string webpath;
	std::string helpurl;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgBrlyPath* comp);
	std::set<Sbecore::uint> diff(const StgBrlyPath* comp);
};

/**
	* AlrBrly
	*/
namespace AlrBrly {
	DpchEngBrlyAlert* prepareAlrAbt(const Sbecore::ubigint jref, const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feedFMcbAlert);
	DpchEngBrlyAlert* prepareAlrIer(const Sbecore::ubigint jref, const Sbecore::uint ixBrlyVLocale, const std::string& iexsqk, Sbecore::Feed& feedFMcbAlert);
	DpchEngBrlyAlert* prepareAlrPer(const Sbecore::ubigint jref, const Sbecore::uint ixBrlyVLocale, const std::string& iexsqk, Sbecore::Feed& feedFMcbAlert);
	DpchEngBrlyAlert* prepareAlrSav(const Sbecore::ubigint jref, const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feedFMcbAlert);
	DpchEngBrlyAlert* prepareAlrTrm(const Sbecore::ubigint jref, const Sbecore::uint ixBrlyVLocale, const Sbecore::uint sesstterm, const Sbecore::uint sesstwarn, Sbecore::Feed& feedFMcbAlert);
	std::string prepareAlrTrm_dtToString(const uint ixBrlyVLocale, const time_t dt);
};

/**
	* ReqBrly
	*/
class ReqBrly {

public:
	/**
		* VecVBasetype
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint REDIRECT = 1; // web client triggered root request (GET)
		static const Sbecore::uint PREFLIGHT = 2; // web client triggered Dpch pre-flight request (OPTIONS)
		static const Sbecore::uint WEB = 3; // web client triggered ui file request (GET)
		static const Sbecore::uint CMD = 4; // command line request
		static const Sbecore::uint DPCHAPP = 5; // web client triggered Dpch request (POST+DpchApp)
		static const Sbecore::uint NOTIFY = 6; // web client triggered notify-on-Dpch request (GET)
		static const Sbecore::uint POLL = 7; // web client triggered Dpch poll request (GET)
		static const Sbecore::uint UPLOAD = 8; // web client triggered file upload request (POST)
		static const Sbecore::uint DOWNLOAD = 9; // web client triggered file download request (GET)
		static const Sbecore::uint DPCHRET = 10; // op engine or opprc triggered op return (DpchRet)
		static const Sbecore::uint METHOD = 11; // M2M interface triggered method request
		static const Sbecore::uint TIMER = 12; // timer triggered request
		static const Sbecore::uint EXTCALL = 13; // externally triggered call request
	};

	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint RECEIVE = 1; // during data reception - appsrv internal
		static const Sbecore::uint WAITPRC = 2; // before caught by job processor that is idle - in reqs list
		static const Sbecore::uint PRC = 3; // while being processesd by job processor ; appsrv thread waiting on cReply
		static const Sbecore::uint REPLY = 4; // after being processed by job processor
	};

public:
	ReqBrly(const Sbecore::uint ixVBasetype = VecVBasetype::NONE, const Sbecore::uint ixVState = VecVState::RECEIVE, const std::string& ip = "");
	~ReqBrly();

public:
	Sbecore::uint ixVBasetype;
	Sbecore::uint ixVState;

	// specific data for base type CMD
	std::string cmd;

	// specific data for base types DPCHAPP, NOTIFY, POLL, UPLOAD, DOWNLOAD
	std::string ip;

	// specific data for base types DPCHAPP, NOTIFY, POLL, UPLOAD
	MHD_PostProcessor* pp;

	// specific data for base types CMD, DPCHAPP, NOTIFY, UPLOAD, DOWNLOAD, METHOD
	bool retain;
	Sbecore::Cond cReady; // mutex also protects compare/set of ixVState to REPLY

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	std::string filename; // full path
	std::fstream* file;
	size_t filelen;

	// specific data for base types DPCHAPP, NOTIFY, POLL, DPCHRET
	char* request;
	size_t requestlen;

	// specifc data for base types DPCHAPP, NOTIFY, POLL
	bool jsonNotXml;

	// specific data for base types CMD, DPCHAPP, NOTIFY, POLL, UPLOAD, DOWNLOAD, DPCHRET, TIMER
	Sbecore::ubigint jref;

	// specific data for base type TIMER
	Sbecore::ubigint wref;
	std::string sref;

	// specific data for base type EXTCALL
	Sbecore::Call* call;

	// specific data for base types CMD, DPCHAPP, UPLOAD, DOWNLOAD, DPCHRET, TIMER
	bool weak;

	// specific data for base type DPCHAPP
	DpchAppBrly* dpchapp;

	// specific data for base types DPCHAPP, NOTIFY, POLL
	DpchEngBrly* dpcheng;
	Sbecore::uint ixBrlyVLocale;

	// specific data for base type DPCHRET
	DpchInvBrly* dpchinv;
	DpchRetBrly* dpchret;

	// specific data for base types DPCHAPP, NOTIFY, POLL, DPCHRET
	char* reply;
	size_t replylen;

	// specific data for base type METHOD
	Sbecore::Method* method;

public:
	void setStateReply();
};

/**
	* DcolBrly
	*/
class DcolBrly {

public:
	DcolBrly(const Sbecore::ubigint jref = 0, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS);
	~DcolBrly();

public:
	Sbecore::ubigint jref;

	Sbecore::uint ixBrlyVLocale;

	Sbecore::Mutex mAccess;

	bool hot;

	std::list<DpchEngBrly*> dpchs;

	ReqBrly* req;

public:
	void lockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
	void unlockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
};

/**
	* JobBrly
	*/
class JobBrly {

public:
	JobBrly(XchgBrly* xchg, const Sbecore::uint ixBrlyVJob = 0, const Sbecore::ubigint jrefSup = 0, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS);
	virtual ~JobBrly();

public:
	XchgBrly* xchg;

	Sbecore::ubigint jref;

	Sbecore::uint ixBrlyVJob;

	Sbecore::uint ixBrlyVLocale;

	Sbecore::Mutex mAccess;

	bool muteRefresh;

	Sbecore::uint ixVSge;
	Sbecore::uint nextIxVSgeSuccess;
	Sbecore::uint nextIxVSgeFailure;

	std::string lasterror;

	Sbecore::uint opN;
	Sbecore::uint opNSuccess;
	Sbecore::uint opNFailure;

	std::vector<DpchInvBrly*> invs;

	Sbecore::Mutex mOps;
	std::list<Sbecore::Op*> ops;
	std::string opsqkLast;

	Sbecore::ubigint wrefLast;
	Sbecore::ubigint wrefMin;

	ReqBrly* reqCmd;

public:
	Sbecore::ubigint insertSubjob(std::map<Sbecore::ubigint, JobBrly*>& subjobs, JobBrly* subjob);
	bool eraseSubjobByJref(std::map<Sbecore::ubigint, JobBrly*>& subjobs, const Sbecore::ubigint _jref);

	virtual DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	virtual void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void refreshWithDpchEng(DbsBrly* dbsbrly, DpchEngBrly** dpcheng = NULL, const bool unmute = false);

	virtual std::string getSquawk(DbsBrly* dbsbrly);

	virtual void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);
	virtual void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

	void lockAccess(const std::string& srefObject, const std::string& srefMember);
	bool trylockAccess(const std::string& srefObject, const std::string& srefMember);
	void unlockAccess(const std::string& srefObject, const std::string& srefMember);

	void lockAccess(const std::string& srefMember);
	bool trylockAccess(const std::string& srefMember);
	void unlockAccess(const std::string& srefMember);

	void setStage(DbsBrly* dbsbrly, const Sbecore::uint _ixVSge);

	void clearInvs();
	Sbecore::ubigint addInv(DpchInvBrly* inv);
	void addInvs(std::vector<DpchInvBrly*>& _invs);
	void submitInvs(DbsBrly* dbsbrly, const Sbecore::uint nextIxVSgeEmpty, Sbecore::uint& _ixVSge);

	void clearOps();
	void addOp(DbsBrly* dbsbrly, DpchInvBrly* inv);
	void removeOp(const Sbecore::ubigint oref);
	std::string getOpsqkLast();

	void callback(const Sbecore::uint nextIxVSge);
	void invalidateWakeups();
};

/**
	* CsjobBrly
	*/
class CsjobBrly : public JobBrly {

public:
	CsjobBrly(XchgBrly* xchg, const Sbecore::uint ixBrlyVJob = 0, const Sbecore::ubigint jrefSup = 0, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS);

public:
	bool srvNotCli;
	CsjobBrly* srv; // client

public:
	virtual bool handleClaim(DbsBrly* dbsbrly, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest); // server
};

/**
	* ShrdatBrly
	*/
class ShrdatBrly {

public:
	ShrdatBrly(const std::string& srefSupclass, const std::string& srefObject);
	~ShrdatBrly();

public:
	std::string srefSupclass;
	std::string srefObject;

	Sbecore::Rwmutex rwmAccess;

public:
	virtual void init(XchgBrly* xchg, DbsBrly* dbsbrly);
	virtual void term(XchgBrly* xchg);

	void rlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void runlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void rlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
	void runlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);

	void wlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void wunlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void wlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
	void wunlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
};

/**
	* StmgrBrly
	*/
class StmgrBrly {

public:
	StmgrBrly(XchgBrly* xchg, const Sbecore::ubigint jref, const Sbecore::uint ixVNonetype);
	~StmgrBrly();

public:
	XchgBrly* xchg;

	Sbecore::ubigint jref;
	Sbecore::uint ixVNonetype;

	Sbecore::Stcch* stcch;

	Sbecore::Mutex mAccess;

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);
	bool refresh(DbsBrly* dbsbrly, Sbecore::Stcchitem* stit);

	void begin();
	void commit();

	void lockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
	void unlockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
};

/**
	* WakeupBrly
	*/
class WakeupBrly {

public:
	WakeupBrly(XchgBrly* xchg, const Sbecore::ubigint wref, const Sbecore::ubigint jref, const std::string sref, const uint64_t deltat = 0, const bool weak = false);

public:
	XchgBrly* xchg;

	Sbecore::ubigint wref;

	Sbecore::ubigint jref;
	std::string sref;
	uint64_t deltat;
	bool weak;
};

/**
	* ExtcallBrly
	*/
class ExtcallBrly {

public:
	ExtcallBrly(XchgBrly* xchg, Sbecore::Call* call);

public:
	XchgBrly* xchg;
	Sbecore::Call* call;
};

/**
	* XchgBrlycmbd
	*/
class XchgBrlycmbd {

public:
	/**
		* ShrdatJobprc
		*/
	class ShrdatJobprc : public ShrdatBrly {

	public:
		// IP ShrdatJobprc.subs --- INSERT

	public:
		ShrdatJobprc();

	public:
		// IP ShrdatJobprc.vars --- INSERT

	public:
		void init(XchgBrly* xchg, DbsBrly* dbsbrly);
		void term(XchgBrly* xchg);
	};

	/**
		* ShrdatOpprc
		*/
	class ShrdatOpprc : public ShrdatBrly {

	public:
		// IP ShrdatOpprc.subs --- INSERT

	public:
		ShrdatOpprc();

	public:
		// IP ShrdatOpprc.vars --- INSERT

	public:
		void init(XchgBrly* xchg, DbsBrly* dbsbrly);
		void term(XchgBrly* xchg);
	};

public:
	XchgBrlycmbd();
	~XchgBrlycmbd();

public:
	StgBrlyAppearance stgbrlyappearance;
	StgBrlyAppsrv stgbrlyappsrv;
	StgBrlycmbd stgbrlycmbd;
	StgBrlyDatabase stgbrlydatabase;
	StgBrlyFlightaware stgbrlyflightaware;
	StgBrlyGeometry stgbrlygeometry;
	StgBrlyMonitor stgbrlymonitor;
	StgBrlyPath stgbrlypath;

	ShrdatJobprc shrdatJobprc;
	ShrdatOpprc shrdatOpprc;

public:
	// IP cust --- INSERT

public:
	// executable/archive/temporary folder paths and help URL
	std::string exedir;
	std::string acvpath;
	std::string tmppath;
	std::string helpurl;

	std::string key;
	std::string cert;

	// condition for thread start-up
	Sbecore::Cond cStable;

	// root job
	Sbecore::ubigint jrefRoot;

	// job receiving commands
	Sbecore::ubigint jrefCmd;

	// monitor object
	Sbecore::DbsMon mon;

	// log file
	Sbecore::Mutex mLogfile;

	// condition for job processors
	Sbecore::Cond cJobprcs;

	// condition for op processors
	Sbecore::Cond cOpprcs;

	// request list
	Sbecore::Mutex mReqs;
	std::list<ReqBrly*> reqs;

	// operation invocation list
	Sbecore::Refseq orefseq;
	Sbecore::Mutex mInvs;
	std::list<DpchInvBrly*> invs;

	// presetting list
	Sbecore::Rwmutex rwmPresets;
	std::multimap<Sbecore::presetref_t,Sbecore::Preset*> presets;

	// stub manager list
	Sbecore::Rwmutex rwmStmgrs;
	std::map<Sbecore::ubigint,StmgrBrly*> stmgrs;

	// call listener list
	Sbecore::Rwmutex rwmClstns;
	std::multimap<Sbecore::clstnref_t,Sbecore::Clstn*> clstns;
	std::multimap<Sbecore::clstnref2_t,Sbecore::clstnref_t> cref2sClstns;

	// dispatch collector list
	Sbecore::Rwmutex rwmDcols;
	std::map<Sbecore::ubigint,DcolBrly*> dcols;

	// job list
	Sbecore::Refseq jrefseq;
	Sbecore::Rwmutex rwmJobs;
	std::map<Sbecore::ubigint,JobBrly*> jobs;
	std::map<Sbecore::ubigint,Sbecore::uint> ixBrlyVJobs;
	std::map<Sbecore::ubigint,Sbecore::Jobinfo*> jobinfos;

	// client/server job information
	Sbecore::Rwmutex rwmCsjobinfos;
	std::map<Sbecore::uint,Sbecore::Csjobinfo*> csjobinfos;

	// sequence for wakeup references
	Sbecore::Refseq wrefseq;

public:
	// monitor object methods
	void startMon();
	void stopMon();

	// log file methods
	void appendToLogfile(const std::string& str);

	// request list methods
	void addReq(ReqBrly* req);
	ReqBrly* pullFirstReq();

	// operation invocation list methods
	void addInvs(DbsBrly* dbsbrly, JobBrly* job, std::vector<DpchInvBrly*>& dpchinvs);
	DpchInvBrly* pullFirstInv();

	// presetting methods
	Sbecore::Preset* addPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref, const Sbecore::Arg& arg);

	Sbecore::Preset* addIxPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref, const Sbecore::uint ix);
	Sbecore::Preset* addRefPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref, const Sbecore::ubigint ref);
	Sbecore::Preset* addRefsPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref, const std::vector<Sbecore::ubigint>& refs);
	Sbecore::Preset* addSrefPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref, const std::string& sref);
	Sbecore::Preset* addIntvalPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref, const int intval);
	Sbecore::Preset* addDblvalPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref, const double dblval);
	Sbecore::Preset* addBoolvalPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref, const bool boolval);
	Sbecore::Preset* addTxtvalPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref, const std::string& txtval);

	Sbecore::Preset* getPresetByPref(const Sbecore::presetref_t& pref);

	Sbecore::Arg getPreset(const Sbecore::uint ixBrlyVPreset, Sbecore::ubigint jref);

	Sbecore::uint getIxPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref);
	Sbecore::ubigint getRefPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref);
	std::vector<Sbecore::ubigint> getRefsPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref);
	std::string getSrefPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref);
	int getIntvalPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref);
	double getDblvalPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref);
	bool getBoolvalPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref);
	std::string getTxtvalPreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref);

	void getPresetsByJref(const Sbecore::ubigint jref, std::vector<Sbecore::uint>& icsBrlyVPreset, std::vector<Sbecore::Arg>& args);

	void removePreset(const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jref);
	void removePresetsByJref(const Sbecore::ubigint jref);

	// stub manager methods
	StmgrBrly* addStmgr(const Sbecore::ubigint jref, const Sbecore::uint ixVNonetype);
	StmgrBrly* getStmgrByJref(const Sbecore::ubigint jref);
	void removeStmgrByJref(const Sbecore::ubigint jref);

	// call listener list methods
	Sbecore::Clstn* addClstn(const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig = 0, const bool chgarg = false, const Sbecore::Arg& arg = Sbecore::Arg(), const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);

	Sbecore::Clstn* addIxClstn(const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addRefClstn(const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::ubigint ref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addIxRefClstn(const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::ubigint ref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addIxRefSrefClstn(const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::ubigint ref, const std::string& sref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);

	Sbecore::Clstn* addClstnStmgr(const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref);

	Sbecore::Clstn* getClstnByCref(const Sbecore::clstnref_t& cref);
	void getClstnsByJref(const Sbecore::ubigint jref, const Sbecore::uint ixVTarget, std::vector<Sbecore::uint>& icsBrlyVCall, std::vector<Sbecore::uint>& icsVJobmask);

	void removeClstns(const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVTarget = Sbecore::Clstn::VecVTarget::JOB);
	void removeClstnsByJref(const Sbecore::ubigint jref, const Sbecore::uint ixVTarget = Sbecore::Clstn::VecVTarget::JOB);

	// call methods
	void findJrefsByCall(Sbecore::Call* call, std::vector<Sbecore::ubigint>& jrefTrigs, std::vector<Sbecore::ubigint>& jrefs, std::vector<Sbecore::uint>& icsVTarget, std::vector<Sbecore::uint>& icsVJactype);

	void triggerCall(DbsBrly* dbsbrly, Sbecore::Call* call);

	bool triggerArgToArgCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::Arg& argInv, Sbecore::Arg& argRet);
	bool triggerCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref);
	bool triggerIxCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv);
	bool triggerRefCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv);
	bool triggerIntvalCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const int intvalInv);
	bool triggerBoolvalCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const bool boolvalInv);
	bool triggerIxRefCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool triggerIxSrefCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& srefInv);
	bool triggerIxSrefToIxCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& srefInv, Sbecore::uint& ixRet);
	bool triggerIxIntvalCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const int intvalInv);
	bool triggerIxDblvalCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const double dblvalInv);
	bool triggerIxTxtvalCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& txtvalInv);
	bool triggerSrefCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const std::string& srefInv);
	bool triggerToBoolvalCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, bool& boolvalRet);
	bool triggerIxToBoolvalCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, bool& boolvalRet);
	bool triggerRefToSrefCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, std::string& srefRet);
	bool triggerRefToBoolvalCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool triggerIxRefToIxCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool triggerIxRefToRefCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::ubigint& refRet);
	bool triggerIxRefSrefCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);
	bool triggerIxRefSrefIntvalCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv);
	bool triggerIxRefSrefIntvalToRefCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv, Sbecore::ubigint& refRet);
	bool triggerRefToIxCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool triggerSrefToRefCall(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVCall, const Sbecore::ubigint jref, const std::string& srefInv, Sbecore::ubigint& refRet);

	// dispatch collector list methods
	DcolBrly* addDcol(const Sbecore::ubigint jref);
	DcolBrly* getDcolByJref(Sbecore::ubigint jref, const bool tree = true);
	void removeDcolByJref(const Sbecore::ubigint jref);
	void removeDcolsByJref(const Sbecore::ubigint jref);

	void submitDpch(DpchEngBrly* dpcheng);
	DpchEngBrly* pullFirstDpch(DcolBrly* dcol);

	// job list methods
	Sbecore::ubigint addJob(DbsBrly* dbsbrly, JobBrly* job, const Sbecore::ubigint jrefSup);
	JobBrly* getJobByJref(const Sbecore::ubigint jref);
	Sbecore::Jobinfo* getJobinfoByJref(const Sbecore::ubigint jref);
	void removeJobByJref(const Sbecore::ubigint jref);

	bool getJobSup(const Sbecore::ubigint jrefSup, Sbecore::ubigint jref);
	void setJobStage(DbsBrly* dbsbrly, JobBrly* job, const Sbecore::uint ixVSge);

	// client/server job methods
	void addCsjobClaim(DbsBrly* dbsbrly, CsjobBrly* csjob, Sbecore::Claim* claim);

	bool getCsjobClaim(CsjobBrly* csjob, bool& takenNotAvailable, bool& fulfilled, bool& run);
	bool getCsjobClaim(CsjobBrly* csjob, bool& takenNotAvailable, bool& fulfilled);

	void clearCsjobRun(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVJob);

	void removeCsjobClaim(DbsBrly* dbsbrly, CsjobBrly* csjob);

	bool getCsjobNotJob(const Sbecore::uint ixBrlyVJob);
	std::set<Sbecore::ubigint> getCsjobClisByJref(const Sbecore::ubigint jref);

	// timer methods
	Sbecore::ubigint addWakeup(const Sbecore::ubigint jref, const std::string sref, const uint64_t deltat = 0, const bool weak = false);
	static void* runWakeup(void* arg);

	// external call methods
	static void runExtcall(void* arg);
};
#endif
