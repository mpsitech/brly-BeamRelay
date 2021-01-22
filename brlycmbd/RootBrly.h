/**
	* \file RootBrly.h
	* job handler for job RootBrly (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef ROOTBRLY_H
#define ROOTBRLY_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "SessBrly.h"

#define DpchAppRootBrlyLogin RootBrly::DpchAppLogin
#define DpchEngRootBrlyData RootBrly::DpchEngData

/**
	* RootBrly
	*/
class RootBrly : public JobBrly {

public:
	/**
		* DpchAppLogin (full: DpchAppRootBrlyLogin)
		*/
	class DpchAppLogin : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint USERNAME = 2;
		static const Sbecore::uint PASSWORD = 3;
		static const Sbecore::uint M2MNOTREG = 4;
		static const Sbecore::uint CHKSUSPSESS = 5;

	public:
		DpchAppLogin();

	public:
		std::string username;
		std::string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngRootBrlyData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint FEEDFENSSPS = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Xmlio::Feed* feedFEnsSps = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Xmlio::Feed feedFEnsSps;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

public:
	RootBrly(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const bool _clearAll);
	~RootBrly();

public:

	std::list<SessBrly*> sesss;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void clearAll(DbsBrly* dbsbrly);
	void clearQtb(DbsBrly* dbsbrly);

	bool authenticate(DbsBrly* dbsbrly, const std::string& username, const std::string& password, Sbecore::ubigint& refBrlyMUser);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:
	bool handleClearAll(DbsBrly* dbsbrly);
	bool handleCreateSess(DbsBrly* dbsbrly);
	bool handleEraseSess(DbsBrly* dbsbrly);

	void handleDpchAppLogin(DbsBrly* dbsbrly, DpchAppLogin* dpchapplogin, const std::string ip, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlySuspsess(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyLogout(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig, const bool boolvalInv);

};

#endif
