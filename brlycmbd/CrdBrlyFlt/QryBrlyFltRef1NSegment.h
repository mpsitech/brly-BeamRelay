/**
	* \file QryBrlyFltRef1NSegment.h
	* job handler for job QryBrlyFltRef1NSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef QRYBRLYFLTREF1NSEGMENT_H
#define QRYBRLYFLTREF1NSEGMENT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatAppQryBrlyFltRef1NSegment QryBrlyFltRef1NSegment::StatApp
#define StatShrQryBrlyFltRef1NSegment QryBrlyFltRef1NSegment::StatShr
#define StgIacQryBrlyFltRef1NSegment QryBrlyFltRef1NSegment::StgIac

/**
	* QryBrlyFltRef1NSegment
	*/
class QryBrlyFltRef1NSegment : public JobBrly {

public:
	/**
		* StatApp (full: StatAppQryBrlyFltRef1NSegment)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 1, const Sbecore::uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryBrlyFltRef1NSegment)
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
		* StgIac (full: StgIacQryBrlyFltRef1NSegment)
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
	QryBrlyFltRef1NSegment(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~QryBrlyFltRef1NSegment();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQFltRef1NSegment rst;

	Sbecore::uint ixBrlyVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsBrly* dbsbrly, const bool call = false);

	void fetch(DbsBrly* dbsbrly);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	BrlyQFltRef1NSegment* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:
	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlySegMod_retReuEq(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);
	bool handleCallBrlyStubChgFromSelf(DbsBrly* dbsbrly);

};

#endif
