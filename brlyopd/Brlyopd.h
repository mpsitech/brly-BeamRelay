/**
	* \file Brlycmbd.h
	* inter-thread exchange object for Brly combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYOPD_H
#define BRLYOPD_H

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

#ifdef _WIN32
	#include <pthread.h>
#endif

#include <microhttpd.h>
#if MHD_VERSION < 0x0097002
	#define MHD_Result int
#endif

#include <curl/curl.h>

#include "Brly.h"

class XchgBrlyopd;
typedef XchgBrlyopd XchgBrly;

/**
	* DpchBrlydReg (written by dOpengsrv, read by opd_exe)
	*/
class DpchBrlydReg : public DpchBrly {

public:
	static const Sbecore::uint SCRNREF = 1;

public:
	DpchBrlydReg();

public:
	std::string scrNref;

public:
	static bool all(const std::set<Sbecore::uint>& items);

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchBrlyopdAck (written by opd_exe, identified by d_exe)
	*/
namespace DpchBrlyopdAck {
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchBrlyopdReg (written by opd_exe, read by dOpengsrv)
	*/
namespace DpchBrlyopdReg {
	void writeXML(xmlTextWriter* wr, const Sbecore::usmallint port = 0, const Sbecore::uint ixBrlyVOpengtype = 0, const Sbecore::usmallint opprcn = 0);
};

/**
	* DpchBrlyopdUnreg (written by opd_exe, read by dOpengsrv)
	*/
namespace DpchBrlyopdUnreg {
	void writeXML(xmlTextWriter* wr, const std::string& scrNref = "");
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
	* StgBrlyopd
	*/
class StgBrlyopd : public Sbecore::Block {

public:
	static const Sbecore::uint ENGIP = 1;
	static const Sbecore::uint ENGPORT = 2;
	static const Sbecore::uint ENGSRVPORTBASE = 3;
	static const Sbecore::uint ENGSRVPORTOFS = 4;
	static const Sbecore::uint OPPRCN = 5;

public:
	StgBrlyopd(const std::string& engip = "127.0.0.1", const Sbecore::usmallint engport = 0, const Sbecore::usmallint engsrvportbase = 13140, const Sbecore::usmallint engsrvportofs = 0, const Sbecore::usmallint opprcn = 4);

public:
	std::string engip;
	Sbecore::usmallint engport;
	Sbecore::usmallint engsrvportbase;
	Sbecore::usmallint engsrvportofs;
	Sbecore::usmallint opprcn;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgBrlyopd* comp);
	std::set<Sbecore::uint> diff(const StgBrlyopd* comp);
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
	* ReqopBrly
	*/
class ReqopBrly {

public:
	/**
		* VecVBasetype
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint DPCHINV = 1; // engine triggered Dpch request (POST+DpchInv)
		static const Sbecore::uint POLL = 2; // engine triggered Dpch poll request (GET)
	};

	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const Sbecore::uint RECEIVE = 0; // during data reception - engsrv internal
		static const Sbecore::uint WAITPRC = 1; // before caught by op processor that is idle - in reqs list
		static const Sbecore::uint PRC = 2; // while being processesd by op processor - in prcreqs list ; engsrv thread waiting on cReply until timeout
		static const Sbecore::uint REPLY = 3; // after being processed by job processor ; in prcreqs list until sent by engsrv
	};

public:
	ReqopBrly(const Sbecore::uint ixVBasetype = VecVBasetype::NONE, const Sbecore::uint ixVState = VecVState::RECEIVE);
	~ReqopBrly();

public:
	Sbecore::uint ixVBasetype;
	Sbecore::uint ixVState;

	Sbecore::utinyint pdone;

	MHD_PostProcessor* pp;

	Sbecore::Cond cReady; // also protects compare/set of ixVState to REPLY, and pdone

	char* request;
	size_t requestlen;

	DpchInvBrly* dpchinv;
	DpchRetBrly* dpchret;

	char* reply;
	size_t replylen;

public:
	void setStateReply();
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

	void rlockAccess(const std::string& srefObject, const std::string& srefMember);
	void runlockAccess(const std::string& srefObject, const std::string& srefMember);

	void wlockAccess(const std::string& srefObject, const std::string& srefMember);
	void wunlockAccess(const std::string& srefObject, const std::string& srefMember);
};

/**
	* XchgBrlyopd
	*/
class XchgBrlyopd {

public:
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
	XchgBrlyopd();
	~XchgBrlyopd();

public:
	StgBrlyDatabase stgbrlydatabase;
	StgBrlyFlightaware stgbrlyflightaware;
	StgBrlyGeometry stgbrlygeometry;
	StgBrlyMonitor stgbrlymonitor;
	StgBrlyopd stgbrlyopd;
	StgBrlyPath stgbrlypath;

	ShrdatOpprc shrdatOpprc;

public:
	// IP cust --- INSERT

public:
	// executable/archive/temporary folder paths and help URL
	std::string exedir;
	std::string acvpath;
	std::string tmppath;
	std::string helpurl;

	// condition for thread start-up
	Sbecore::Cond cStable;

	// node reference as assigned by engine
	std::string scrNref;

	// mutex for log file
	Sbecore::Mutex mLogfile;

	// condition for termination
	Sbecore::Cond cTerm;

	// condition for op processors
	Sbecore::Cond cOpprcs;

	// request list and active request list
	Sbecore::Mutex mReqs;
	std::list<ReqopBrly*> reqs;
	std::map<std::string, ReqopBrly*> prcreqs;

public:
	// log file methods
	void appendToLogfile(const std::string& str);

	// request list methods
	void addReq(ReqopBrly* req);
	ReqopBrly* pullFirstReq();
	
	ReqopBrly* getPrcreqByScrOref(const std::string& scrOref);
	void pullPrcreq(const std::string& scrOref);
	
	void setPdone(const std::string& scrOref, const Sbecore::utinyint pdone);
};

#endif
