/**
	* \file BrlyDnsmap_blks.h
	* invocation / return data blocks for operation pack BrlyDnsmap (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDNSMAP_BLKS_H
#define BRLYDNSMAP_BLKS_H

#include "Brly.h"

/**
	* DpchInvBrlyDnsmapCollect
	*/
class DpchInvBrlyDnsmapCollect : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint CAPACITY = 3;
	static const Sbecore::uint CON = 4;
	static const Sbecore::uint DT = 5;
	static const Sbecore::uint FLT = 6;
	static const Sbecore::uint FULLHEIGHT = 7;
	static const Sbecore::uint FULLWIDTH = 8;
	static const Sbecore::uint LEG = 9;
	static const Sbecore::uint PACCTR = 10;
	static const Sbecore::uint PHI0 = 11;
	static const Sbecore::uint PHI1 = 12;
	static const Sbecore::uint PREACH = 13;
	static const Sbecore::uint SEG = 14;
	static const Sbecore::uint SREFARENA = 15;
	static const Sbecore::uint SREFSBRLYKEQPTYPE = 16;
	static const Sbecore::uint START = 17;
	static const Sbecore::uint STOP = 18;
	static const Sbecore::uint THETA0 = 19;
	static const Sbecore::uint THETA1 = 20;

public:
	DpchInvBrlyDnsmapCollect(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const bool capacity = false, const bool con = false, const Sbecore::uint dt = 0, const bool flt = false, const Sbecore::uint fullheight = 0, const Sbecore::uint fullwidth = 0, const bool leg = false, const bool pacctr = false, const double phi0 = 0.0, const double phi1 = 0.0, const bool pReach = false, const bool seg = false, const std::string& srefArena = "", const std::string& srefsBrlyKEqptype = "", const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const double theta0 = 0.0, const double theta1 = 0.0);

public:
	bool capacity;
	bool con;
	Sbecore::uint dt;
	bool flt;
	Sbecore::uint fullheight;
	Sbecore::uint fullwidth;
	bool leg;
	bool pacctr;
	double phi0;
	double phi1;
	bool pReach;
	bool seg;
	std::string srefArena;
	std::string srefsBrlyKEqptype;
	Sbecore::uint start;
	Sbecore::uint stop;
	double theta0;
	double theta1;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetBrlyDnsmapCollect
	*/
class DpchRetBrlyDnsmapCollect : public DpchRetBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint REFBRLYMFILE = 5;

public:
	DpchRetBrlyDnsmapCollect(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const Sbecore::ubigint refBrlyMFile = 0);

public:
	Sbecore::ubigint refBrlyMFile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDnsmapFrame
	*/
class DpchInvBrlyDnsmapFrame : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFBRLYMFILE = 3;
	static const Sbecore::uint FULLSIZE = 4;
	static const Sbecore::uint GRAYSCALE = 5;
	static const Sbecore::uint ALTZMAX = 6;
	static const Sbecore::uint TIX = 7;

public:
	DpchInvBrlyDnsmapFrame(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refBrlyMFile = 0, const bool fullsize = false, const bool grayscale = false, const double altzmax = 0.0, const Sbecore::uint tIx = 0);

public:
	Sbecore::ubigint refBrlyMFile;
	bool fullsize;
	bool grayscale;
	double altzmax;
	Sbecore::uint tIx;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetBrlyDnsmapFrame
	*/
class DpchRetBrlyDnsmapFrame : public DpchRetBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint FILENAME = 5;

public:
	DpchRetBrlyDnsmapFrame(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::string& filename = "");

public:
	std::string filename;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyDnsmapVideo
	*/
class DpchInvBrlyDnsmapVideo : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint ALTZMAX = 3;
	static const Sbecore::uint FRMRATE = 4;
	static const Sbecore::uint FULLSIZE = 5;
	static const Sbecore::uint GRAYSCALE = 6;
	static const Sbecore::uint REFBRLYMFILE = 7;

public:
	DpchInvBrlyDnsmapVideo(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const double altzmax = 0.0, const Sbecore::uint frmrate = 0, const bool fullsize = false, const bool grayscale = false, const Sbecore::ubigint refBrlyMFile = 0);

public:
	double altzmax;
	Sbecore::uint frmrate;
	bool fullsize;
	bool grayscale;
	Sbecore::ubigint refBrlyMFile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetBrlyDnsmapVideo
	*/
class DpchRetBrlyDnsmapVideo : public DpchRetBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchRetBrlyDnsmapVideo(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::string& folder = "");

public:
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
