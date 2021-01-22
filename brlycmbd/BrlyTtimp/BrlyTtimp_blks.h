/**
	* \file BrlyTtimp_blks.h
	* invocation / return data blocks for operation pack BrlyTtimp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYTTIMP_BLKS_H
#define BRLYTTIMP_BLKS_H

#include "Brly.h"

/**
	* DpchInvBrlyTtimpRawstar
	*/
class DpchInvBrlyTtimpRawstar : public DpchInvBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint INFILE = 3;
	static const Sbecore::uint OUTFILE = 4;

public:
	DpchInvBrlyTtimpRawstar(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const std::string& infile = "", const std::string& outfile = "");

public:
	std::string infile;
	std::string outfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
