/**
	* \file QryBrlyConMapLeg.h
	* job handler for job QryBrlyConMapLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef QRYBRLYCONMAPLEG_H
#define QRYBRLYCONMAPLEG_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatShrQryBrlyConMapLeg QryBrlyConMapLeg::StatShr
#define StgIacQryBrlyConMapLeg QryBrlyConMapLeg::StgIac

/**
	* QryBrlyConMapLeg
	*/
class QryBrlyConMapLeg : public JobBrly {

public:
	/**
		* StatShr (full: StatShrQryBrlyConMapLeg)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NTOT = 1;

	public:
		StatShr(const Sbecore::uint ntot = 0);

	public:
		Sbecore::uint ntot;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryBrlyConMapLeg)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JNUM = 1;

	public:
		StgIac(const Sbecore::uint jnum = 0);

	public:
		Sbecore::uint jnum;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryBrlyConMapLeg(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~QryBrlyConMapLeg();

public:
	StatShr statshr;
	StgIac stgiac;

	ListBrlyQConMapLeg rst;

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
	BrlyQConMapLeg* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:
	bool handleRerun(DbsBrly* dbsbrly);
	bool handleShow(DbsBrly* dbsbrly);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyStubChgFromSelf(DbsBrly* dbsbrly);

};

#endif
