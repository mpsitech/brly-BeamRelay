/**
	* \file QryBrlyConMapRelay_blks.cpp
	* job handler for job QryBrlyConMapRelay (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryBrlyConMapRelay::StatShr
 ******************************************************************************/

QryBrlyConMapRelay::StatShr::StatShr(
			const uint ntot
		) :
			Block()
		{
	this->ntot = ntot;

	mask = {NTOT};
};

void QryBrlyConMapRelay::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryBrlyConMapRelay";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryBrlyConMapRelay";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
	xmlTextWriterEndElement(wr);
};

set<uint> QryBrlyConMapRelay::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);

	return(items);
};

set<uint> QryBrlyConMapRelay::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NTOT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryBrlyConMapRelay::StgIac
 ******************************************************************************/

QryBrlyConMapRelay::StgIac::StgIac(
			const uint jnum
		) :
			Block()
		{
	this->jnum = jnum;
	mask = {JNUM};
};

bool QryBrlyConMapRelay::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryBrlyConMapRelay");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryBrlyConMapRelay";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
	};

	return basefound;
};

void QryBrlyConMapRelay::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryBrlyConMapRelay";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryBrlyConMapRelay";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
	xmlTextWriterEndElement(wr);
};

set<uint> QryBrlyConMapRelay::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);

	return(items);
};

set<uint> QryBrlyConMapRelay::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
