/**
	* \file PnlBrlyNavHeadbar.h
	* job handler for job PnlBrlyNavHeadbar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYNAVHEADBAR_H
#define PNLBRLYNAVHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatShrBrlyNavHeadbar PnlBrlyNavHeadbar::StatShr
#define StgInfBrlyNavHeadbar PnlBrlyNavHeadbar::StgInf
#define TagBrlyNavHeadbar PnlBrlyNavHeadbar::Tag

#define DpchEngBrlyNavHeadbarData PnlBrlyNavHeadbar::DpchEngData

/**
	* PnlBrlyNavHeadbar
	*/
class PnlBrlyNavHeadbar : public JobBrly {

public:
	/**
		* StatShr (full: StatShrBrlyNavHeadbar)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgInf (full: StgInfBrlyNavHeadbar)
		*/
	class StgInf {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagBrlyNavHeadbar)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngBrlyNavHeadbarData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint STGINF = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeJSON(const Sbecore::uint ixBrlyVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalMenCrdAvail(DbsBrly* dbsbrly);
	bool evalMspCrd1Avail(DbsBrly* dbsbrly);
	bool evalMitCrdUsgAvail(DbsBrly* dbsbrly);
	bool evalMitCrdUsrAvail(DbsBrly* dbsbrly);
	bool evalMitCrdPrsAvail(DbsBrly* dbsbrly);
	bool evalMitCrdFilAvail(DbsBrly* dbsbrly);
	bool evalMitCrdOprAvail(DbsBrly* dbsbrly);
	bool evalMitCrdPtyAvail(DbsBrly* dbsbrly);
	bool evalMspCrd2Avail(DbsBrly* dbsbrly);
	bool evalMitCrdRegAvail(DbsBrly* dbsbrly);
	bool evalMitCrdLocAvail(DbsBrly* dbsbrly);
	bool evalMitCrdLegAvail(DbsBrly* dbsbrly);
	bool evalMitCrdTtbAvail(DbsBrly* dbsbrly);
	bool evalMitCrdFltAvail(DbsBrly* dbsbrly);
	bool evalMitCrdSegAvail(DbsBrly* dbsbrly);
	bool evalMspCrd3Avail(DbsBrly* dbsbrly);
	bool evalMitCrdConAvail(DbsBrly* dbsbrly);
	bool evalMitCrdRlyAvail(DbsBrly* dbsbrly);

public:
	PnlBrlyNavHeadbar(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyNavHeadbar();

public:
	StatShr statshr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);

};

#endif
