/**
	* \file PnlBrlyLocList.h
	* job handler for job PnlBrlyLocList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYLOCLIST_H
#define PNLBRLYLOCLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryBrlyLocList.h"

#define VecVBrlyLocListDo PnlBrlyLocList::VecVDo

#define ContIacBrlyLocList PnlBrlyLocList::ContIac
#define ContInfBrlyLocList PnlBrlyLocList::ContInf
#define StatShrBrlyLocList PnlBrlyLocList::StatShr
#define StgIacBrlyLocList PnlBrlyLocList::StgIac
#define TagBrlyLocList PnlBrlyLocList::Tag

#define DpchAppBrlyLocListData PnlBrlyLocList::DpchAppData
#define DpchAppBrlyLocListDo PnlBrlyLocList::DpchAppDo
#define DpchEngBrlyLocListData PnlBrlyLocList::DpchEngData

/**
	* PnlBrlyLocList
	*/
class PnlBrlyLocList : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLocListDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDELETECLICK = 4;
		static const Sbecore::uint BUTFILTERCLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyLocList)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFTOS = 1;

	public:
		ContIac(const Sbecore::uint numFTos = 1);

	public:
		Sbecore::uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyLocList)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTFILTERON = 1;
		static const Sbecore::uint NUMFCSIQST = 2;

	public:
		ContInf(const bool ButFilterOn = false, const Sbecore::uint numFCsiQst = 1);

	public:
		bool ButFilterOn;
		Sbecore::uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrBrlyLocList)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXBRLYVEXPSTATE = 1;
		static const Sbecore::uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		Sbecore::uint ixBrlyVExpstate;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacBrlyLocList)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOSRFWIDTH = 1;
		static const Sbecore::uint TCOICAWIDTH = 2;
		static const Sbecore::uint TCOTITWIDTH = 3;
		static const Sbecore::uint TCOTYPWIDTH = 4;
		static const Sbecore::uint TCOREGWIDTH = 5;
		static const Sbecore::uint TCOEQPWIDTH = 6;
		static const Sbecore::uint TCOALTWIDTH = 7;
		static const Sbecore::uint TCOTHEWIDTH = 8;
		static const Sbecore::uint TCOPHIWIDTH = 9;

	public:
		StgIac(const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoIcaWidth = 100, const Sbecore::uint TcoTitWidth = 175, const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoRegWidth = 100, const Sbecore::uint TcoEqpWidth = 100, const Sbecore::uint TcoAltWidth = 100, const Sbecore::uint TcoTheWidth = 100, const Sbecore::uint TcoPhiWidth = 100);

	public:
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoIcaWidth;
		Sbecore::uint TcoTitWidth;
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoRegWidth;
		Sbecore::uint TcoEqpWidth;
		Sbecore::uint TcoAltWidth;
		Sbecore::uint TcoTheWidth;
		Sbecore::uint TcoPhiWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagBrlyLocList)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLocListData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		StgIac stgiac;
		QryBrlyLocList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocListDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngBrlyLocListData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFCSIQST = 4;
		static const Sbecore::uint FEEDFTOS = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint STGIAC = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint RST = 9;
		static const Sbecore::uint STATAPPQRY = 10;
		static const Sbecore::uint STATSHRQRY = 11;
		static const Sbecore::uint STGIACQRY = 12;
		static const Sbecore::uint ALL = 13;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFCsiQst = NULL, Sbecore::Xmlio::Feed* feedFTos = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListBrlyQLocList* rst = NULL, QryBrlyLocList::StatShr* statshrqry = NULL, QryBrlyLocList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		Sbecore::Xmlio::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		ListBrlyQLocList rst;
		QryBrlyLocList::StatShr statshrqry;
		QryBrlyLocList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

	bool evalButDeleteActive(DbsBrly* dbsbrly);

public:
	PnlBrlyLocList(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyLocList();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Xmlio::Feed feedFCsiQst;
	Sbecore::Xmlio::Feed feedFTos;

	QryBrlyLocList* qry;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void minimize(DbsBrly* dbsbrly, const bool notif = false, DpchEngBrly** dpcheng = NULL);
	void regularize(DbsBrly* dbsbrly, const bool notif = false, DpchEngBrly** dpcheng = NULL);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataContiac(DbsBrly* dbsbrly, ContIac* _contiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiac(DbsBrly* dbsbrly, StgIac* _stgiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqry(DbsBrly* dbsbrly, QryBrlyLocList::StgIac* _stgiacqry, DpchEngBrly** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButNewClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButFilterClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);

};

#endif
