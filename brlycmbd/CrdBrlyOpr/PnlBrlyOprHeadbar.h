/**
	* \file PnlBrlyOprHeadbar.h
	* job handler for job PnlBrlyOprHeadbar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYOPRHEADBAR_H
#define PNLBRLYOPRHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StgInfBrlyOprHeadbar PnlBrlyOprHeadbar::StgInf
#define TagBrlyOprHeadbar PnlBrlyOprHeadbar::Tag

#define DpchEngBrlyOprHeadbarData PnlBrlyOprHeadbar::DpchEngData

/**
	* PnlBrlyOprHeadbar
	*/
class PnlBrlyOprHeadbar : public JobBrly {

public:
	/**
		* StgInf (full: StgInfBrlyOprHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagBrlyOprHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngBrlyOprHeadbarData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STGINF = 2;
		static const Sbecore::uint TAG = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

public:
	PnlBrlyOprHeadbar(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyOprHeadbar();

public:

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
