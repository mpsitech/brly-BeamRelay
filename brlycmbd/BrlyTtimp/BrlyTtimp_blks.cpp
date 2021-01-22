/**
	* \file BrlyTtimp_blks.cpp
	* invocation / return data blocks for operation pack BrlyTtimp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyTtimp_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvBrlyTtimpRawstar
 ******************************************************************************/

DpchInvBrlyTtimpRawstar::DpchInvBrlyTtimpRawstar(
			const ubigint oref
			, const ubigint jref
			, const string& infile
			, const string& outfile
		) :
			DpchInvBrly(VecBrlyVDpch::DPCHINVBRLYTTIMPRAWSTAR, oref, jref)
		{
	this->infile = infile;
	this->outfile = outfile;
};

void DpchInvBrlyTtimpRawstar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrlyTtimpRawstar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "infile", "", infile)) add(INFILE);
		if (extractStringUclc(docctx, basexpath, "outfile", "", outfile)) add(OUTFILE);
	};
};

void DpchInvBrlyTtimpRawstar::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvBrlyTtimpRawstar");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeString(wr, "infile", infile);
		writeString(wr, "outfile", outfile);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
