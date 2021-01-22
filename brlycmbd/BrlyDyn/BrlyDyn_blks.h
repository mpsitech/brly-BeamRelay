/**
	* \file BrlyDyn_blks.h
	* invocation / return data blocks for operation pack BrlyDyn (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDYN_BLKS_H
#define BRLYDYN_BLKS_H

#include "Brly.h"

/**
	* DpchInvBrlyDynConflt
	*/
class DpchInvBrlyDynConflt : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFBRLYMCONNECTION = 3;

public:
	DpchInvBrlyDynConflt(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refBrlyMConnection = 0);

public:
	Sbecore::ubigint refBrlyMConnection;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynConseg
	*/
class DpchInvBrlyDynConseg : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFBRLYMCONNECTION = 3;

public:
	DpchInvBrlyDynConseg(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refBrlyMConnection = 0);

public:
	Sbecore::ubigint refBrlyMConnection;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynEqplist
	*/
class DpchInvBrlyDynEqplist : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFBRLYMCONNECTION = 3;

public:
	DpchInvBrlyDynEqplist(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refBrlyMConnection = 0);

public:
	Sbecore::ubigint refBrlyMConnection;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynFltfltloc
	*/
class DpchInvBrlyDynFltfltloc : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFSBRLYMFLIGHT = 3;

public:
	DpchInvBrlyDynFltfltloc(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const std::vector<Sbecore::ubigint>& refsBrlyMFlight = {});

public:
	std::vector<Sbecore::ubigint> refsBrlyMFlight;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynFltseg
	*/
class DpchInvBrlyDynFltseg : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint NUMFIRST = 3;
	static const Sbecore::uint NUMLAST = 4;
	static const Sbecore::uint REFSBRLYMFLIGHT = 5;
	static const Sbecore::uint START = 6;
	static const Sbecore::uint STOP = 7;

public:
	DpchInvBrlyDynFltseg(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint numFirst = 0, const Sbecore::uint numLast = 0, const std::vector<Sbecore::ubigint>& refsBrlyMFlight = {}, const Sbecore::uint start = 0, const Sbecore::uint stop = 0);

public:
	Sbecore::uint numFirst;
	Sbecore::uint numLast;
	std::vector<Sbecore::ubigint> refsBrlyMFlight;
	Sbecore::uint start;
	Sbecore::uint stop;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynRly
	*/
class DpchInvBrlyDynRly : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFBRLYMCONNECTION = 3;

public:
	DpchInvBrlyDynRly(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refBrlyMConnection = 0);

public:
	Sbecore::ubigint refBrlyMConnection;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDynSeglocseg
	*/
class DpchInvBrlyDynSeglocseg : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFSBRLYMFLIGHT = 3;

public:
	DpchInvBrlyDynSeglocseg(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const std::vector<Sbecore::ubigint>& refsBrlyMFlight = {});

public:
	std::vector<Sbecore::ubigint> refsBrlyMFlight;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
