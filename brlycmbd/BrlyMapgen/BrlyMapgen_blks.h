/**
	* \file BrlyMapgen_blks.h
	* invocation / return data blocks for operation pack BrlyMapgen (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMAPGEN_BLKS_H
#define BRLYMAPGEN_BLKS_H

#include "Brly.h"

/**
	* DpchInvBrlyMapgenConmap
	*/
class DpchInvBrlyMapgenConmap : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFBRLYMCONNECTION = 3;
	static const Sbecore::uint JREFLEG = 4;
	static const Sbecore::uint JREFLOC = 5;
	static const Sbecore::uint JREFFLT = 6;
	static const Sbecore::uint JREFRLY = 7;
	static const Sbecore::uint JREFNDE = 8;
	static const Sbecore::uint SCALE = 9;
	static const Sbecore::uint WIDTH = 10;
	static const Sbecore::uint HEIGHT = 11;
	static const Sbecore::uint XOFFSET = 12;
	static const Sbecore::uint YOFFSET = 13;
	static const Sbecore::uint WRTREE = 14;
	static const Sbecore::uint FILENAME = 15;

public:
	DpchInvBrlyMapgenConmap(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::ubigint jrefLeg = 0, const Sbecore::ubigint jrefLoc = 0, const Sbecore::ubigint jrefFlt = 0, const Sbecore::ubigint jrefRly = 0, const Sbecore::ubigint jrefNde = 0, const Sbecore::uint scale = 1, const Sbecore::uint width = 300, const Sbecore::uint height = 300, const int xoffset = 0, const int yoffset = 0, const bool wrtree = false, const std::string& filename = "");

public:
	Sbecore::ubigint refBrlyMConnection;
	Sbecore::ubigint jrefLeg;
	Sbecore::ubigint jrefLoc;
	Sbecore::ubigint jrefFlt;
	Sbecore::ubigint jrefRly;
	Sbecore::ubigint jrefNde;
	Sbecore::uint scale;
	Sbecore::uint width;
	Sbecore::uint height;
	int xoffset;
	int yoffset;
	bool wrtree;
	std::string filename;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyMapgenLegmap
	*/
class DpchInvBrlyMapgenLegmap : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFBRLYMLEG = 3;
	static const Sbecore::uint JREFLEG = 4;
	static const Sbecore::uint JREFLOC = 5;
	static const Sbecore::uint SCALE = 6;
	static const Sbecore::uint WIDTH = 7;
	static const Sbecore::uint HEIGHT = 8;
	static const Sbecore::uint XOFFSET = 9;
	static const Sbecore::uint YOFFSET = 10;
	static const Sbecore::uint FILENAME = 11;

public:
	DpchInvBrlyMapgenLegmap(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refBrlyMLeg = 0, const Sbecore::ubigint jrefLeg = 0, const Sbecore::ubigint jrefLoc = 0, const Sbecore::uint scale = 1, const Sbecore::uint width = 300, const Sbecore::uint height = 300, const int xoffset = 0, const int yoffset = 0, const std::string& filename = "");

public:
	Sbecore::ubigint refBrlyMLeg;
	Sbecore::ubigint jrefLeg;
	Sbecore::ubigint jrefLoc;
	Sbecore::uint scale;
	Sbecore::uint width;
	Sbecore::uint height;
	int xoffset;
	int yoffset;
	std::string filename;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyMapgenLocmap
	*/
class DpchInvBrlyMapgenLocmap : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFBRLYMLOCATION = 3;
	static const Sbecore::uint JREFLEG = 4;
	static const Sbecore::uint JREFPROXLOC = 5;
	static const Sbecore::uint JREFVISLOC = 6;
	static const Sbecore::uint SCALE = 7;
	static const Sbecore::uint WIDTH = 8;
	static const Sbecore::uint HEIGHT = 9;
	static const Sbecore::uint XOFFSET = 10;
	static const Sbecore::uint YOFFSET = 11;
	static const Sbecore::uint FILENAME = 12;

public:
	DpchInvBrlyMapgenLocmap(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refBrlyMLocation = 0, const Sbecore::ubigint jrefLeg = 0, const Sbecore::ubigint jrefProxloc = 0, const Sbecore::ubigint jrefVisloc = 0, const Sbecore::uint scale = 1, const Sbecore::uint width = 300, const Sbecore::uint height = 300, const int xoffset = 0, const int yoffset = 0, const std::string& filename = "");

public:
	Sbecore::ubigint refBrlyMLocation;
	Sbecore::ubigint jrefLeg;
	Sbecore::ubigint jrefProxloc;
	Sbecore::ubigint jrefVisloc;
	Sbecore::uint scale;
	Sbecore::uint width;
	Sbecore::uint height;
	int xoffset;
	int yoffset;
	std::string filename;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
