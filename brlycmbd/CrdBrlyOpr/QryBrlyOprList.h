/**
	* \file QryBrlyOprList.h
	* job handler for job QryBrlyOprList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef QRYBRLYOPRLIST_H
#define QRYBRLYOPRLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVQryBrlyOprListOrd QryBrlyOprList::VecVOrd

#define StatAppQryBrlyOprList QryBrlyOprList::StatApp
#define StatShrQryBrlyOprList QryBrlyOprList::StatShr
#define StgIacQryBrlyOprList QryBrlyOprList::StgIac

/**
	* QryBrlyOprList
	*/
class QryBrlyOprList : public JobBrly {

public:
	/**
		* VecVOrd (full: VecVQryBrlyOprListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint TIT = 1;
		static const Sbecore::uint ICA = 2;
		static const Sbecore::uint SRF = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryBrlyOprList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 3, const Sbecore::uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryBrlyOprList)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NTOT = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StatShr(const Sbecore::uint ntot = 0, const Sbecore::uint jnumFirstload = 0, const Sbecore::uint nload = 0);

	public:
		Sbecore::uint ntot;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryBrlyOprList)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JNUM = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StgIac(const Sbecore::uint jnum = 0, const Sbecore::uint jnumFirstload = 1, const Sbecore::uint nload = 100);

	public:
		Sbecore::uint jnum;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryBrlyOprList(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~QryBrlyOprList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQOprList rst;

	Sbecore::uint ixBrlyVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsBrly* dbsbrly, const bool call = false);
	void rerun_filtSQL(std::string& sqlstr, const std::string& preSrf, const std::string& preIca, const std::string& preTit, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);
	void rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);

	void fetch(DbsBrly* dbsbrly);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	BrlyQOprList* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:
	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyOprUpd_refEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyOprMod(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyStubChgFromSelf(DbsBrly* dbsbrly);

};

#endif
