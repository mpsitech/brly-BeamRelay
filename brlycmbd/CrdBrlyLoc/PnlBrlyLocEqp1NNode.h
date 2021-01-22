/**
	* \file PnlBrlyLocEqp1NNode.h
	* job handler for job PnlBrlyLocEqp1NNode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef PNLBRLYLOCEQP1NNODE_H
#define PNLBRLYLOCEQP1NNODE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryBrlyLocEqp1NNode.h"

#define VecVBrlyLocEqp1NNodeDo PnlBrlyLocEqp1NNode::VecVDo

#define ContInfBrlyLocEqp1NNode PnlBrlyLocEqp1NNode::ContInf
#define StatAppBrlyLocEqp1NNode PnlBrlyLocEqp1NNode::StatApp
#define StgIacBrlyLocEqp1NNode PnlBrlyLocEqp1NNode::StgIac
#define TagBrlyLocEqp1NNode PnlBrlyLocEqp1NNode::Tag

#define DpchAppBrlyLocEqp1NNodeData PnlBrlyLocEqp1NNode::DpchAppData
#define DpchAppBrlyLocEqp1NNodeDo PnlBrlyLocEqp1NNode::DpchAppDo
#define DpchEngBrlyLocEqp1NNodeData PnlBrlyLocEqp1NNode::DpchEngData

/**
	* PnlBrlyLocEqp1NNode
	*/
class PnlBrlyLocEqp1NNode : public JobBrly {

public:
	/**
		* VecVDo (full: VecVBrlyLocEqp1NNodeDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREFRESHCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLocEqp1NNode)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppBrlyLocEqp1NNode)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);
	};

	/**
		* StgIac (full: StgIacBrlyLocEqp1NNode)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOREFWIDTH = 1;

	public:
		StgIac(const Sbecore::uint TcoRefWidth = 100);

	public:
		Sbecore::uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagBrlyLocEqp1NNode)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLocEqp1NNodeData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryBrlyLocEqp1NNode::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocEqp1NNodeDo)
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
		* DpchEngData (full: DpchEngBrlyLocEqp1NNodeData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STGIAC = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint RST = 7;
		static const Sbecore::uint STATAPPQRY = 8;
		static const Sbecore::uint STATSHRQRY = 9;
		static const Sbecore::uint STGIACQRY = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFCsiQst = NULL, StgIac* stgiac = NULL, ListBrlyQLocEqp1NNode* rst = NULL, QryBrlyLocEqp1NNode::StatShr* statshrqry = NULL, QryBrlyLocEqp1NNode::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		StgIac stgiac;
		ListBrlyQLocEqp1NNode rst;
		QryBrlyLocEqp1NNode::StatShr statshrqry;
		QryBrlyLocEqp1NNode::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngBrly* dpcheng);

		void writeXML(const Sbecore::uint ixBrlyVLocale, xmlTextWriter* wr);
	};

public:
	PnlBrlyLocEqp1NNode(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~PnlBrlyLocEqp1NNode();

public:
	ContInf continf;
	StgIac stgiac;

	Sbecore::Xmlio::Feed feedFCsiQst;

	QryBrlyLocEqp1NNode* qry;

	BrlyMNode recNde;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngBrly* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsBrly* dbsbrly, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

	void handleDpchAppBrlyInit(DbsBrly* dbsbrly, DpchAppBrlyInit* dpchappbrlyinit, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiac(DbsBrly* dbsbrly, StgIac* _stgiac, DpchEngBrly** dpcheng);
	void handleDpchAppDataStgiacqry(DbsBrly* dbsbrly, QryBrlyLocEqp1NNode::StgIac* _stgiacqry, DpchEngBrly** dpcheng);

	void handleDpchAppDoButRefreshClick(DbsBrly* dbsbrly, DpchEngBrly** dpcheng);

public:
	void handleCall(DbsBrly* dbsbrly, Sbecore::Call* call);

private:
	bool handleCallBrlyStatChg(DbsBrly* dbsbrly, const Sbecore::ubigint jrefTrig);

};

#endif
