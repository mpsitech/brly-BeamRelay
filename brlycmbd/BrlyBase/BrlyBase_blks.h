/**
	* \file BrlyBase_blks.h
	* invocation / return data blocks for operation pack BrlyBase (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYBASE_BLKS_H
#define BRLYBASE_BLKS_H

#include "Brly.h"

/**
	* DpchInvBrlyBaseLegleg
	*/
class DpchInvBrlyBaseLegleg : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint NUMFIRST = 3;
	static const Sbecore::uint NUMLAST = 4;
	static const Sbecore::uint REFSBRLYMLEG = 5;
	static const Sbecore::uint APPEND = 6;
	static const Sbecore::uint INTERMIX = 7;

public:
	DpchInvBrlyBaseLegleg(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint numFirst = 0, const Sbecore::uint numLast = 0, const std::vector<Sbecore::ubigint>& refsBrlyMLeg = {}, const bool append = false, const bool intermix = false);

public:
	Sbecore::uint numFirst;
	Sbecore::uint numLast;
	std::vector<Sbecore::ubigint> refsBrlyMLeg;
	bool append;
	bool intermix;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyBaseLegloc
	*/
class DpchInvBrlyBaseLegloc : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint NUMFIRST = 3;
	static const Sbecore::uint NUMLAST = 4;
	static const Sbecore::uint REFSBRLYMLEG = 5;
	static const Sbecore::uint REFSBRLYMLOCATION = 6;
	static const Sbecore::uint APPEND = 7;
	static const Sbecore::uint APPENDLOC = 8;

public:
	DpchInvBrlyBaseLegloc(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint numFirst = 0, const Sbecore::uint numLast = 0, const std::vector<Sbecore::ubigint>& refsBrlyMLeg = {}, const std::vector<Sbecore::ubigint>& refsBrlyMLocation = {}, const bool append = false, const bool appendloc = false);

public:
	Sbecore::uint numFirst;
	Sbecore::uint numLast;
	std::vector<Sbecore::ubigint> refsBrlyMLeg;
	std::vector<Sbecore::ubigint> refsBrlyMLocation;
	bool append;
	bool appendloc;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvBrlyBaseLocloc
	*/
class DpchInvBrlyBaseLocloc : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint NUMFIRST = 3;
	static const Sbecore::uint NUMLAST = 4;
	static const Sbecore::uint REFSBRLYMLOCATION = 5;
	static const Sbecore::uint APPEND = 6;
	static const Sbecore::uint INTERMIX = 7;

public:
	DpchInvBrlyBaseLocloc(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint numFirst = 0, const Sbecore::uint numLast = 0, const std::vector<Sbecore::ubigint>& refsBrlyMLocation = {}, const bool append = false, const bool intermix = false);

public:
	Sbecore::uint numFirst;
	Sbecore::uint numLast;
	std::vector<Sbecore::ubigint> refsBrlyMLocation;
	bool append;
	bool intermix;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
