/**
	* \file QryBrlyConMapLocation_blks.cpp
	* job handler for job QryBrlyConMapLocation (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryBrlyConMapLocation::StatShr
 ******************************************************************************/

QryBrlyConMapLocation::StatShr::StatShr(
			const uint ntot
		) :
			Block()
		{
	this->ntot = ntot;

	mask = {NTOT};
};

void QryBrlyConMapLocation::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrQryBrlyConMapLocation";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ntot"] = ntot;
};

void QryBrlyConMapLocation::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryBrlyConMapLocation";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryBrlyConMapLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
	xmlTextWriterEndElement(wr);
};

set<uint> QryBrlyConMapLocation::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);

	return(items);
};

set<uint> QryBrlyConMapLocation::StatShr::diff(
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
 class QryBrlyConMapLocation::StgIac
 ******************************************************************************/

QryBrlyConMapLocation::StgIac::StgIac(
			const uint jnum
		) :
			Block()
		{
	this->jnum = jnum;
	mask = {JNUM};
};

bool QryBrlyConMapLocation::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacQryBrlyConMapLocation"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("jnum")) {jnum = me["jnum"].asUInt(); add(JNUM);};
	};

	return basefound;
};

bool QryBrlyConMapLocation::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryBrlyConMapLocation");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryBrlyConMapLocation";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
	};

	return basefound;
};

void QryBrlyConMapLocation::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacQryBrlyConMapLocation";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["jnum"] = jnum;
};

void QryBrlyConMapLocation::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryBrlyConMapLocation";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryBrlyConMapLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
	xmlTextWriterEndElement(wr);
};

set<uint> QryBrlyConMapLocation::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);

	return(items);
};

set<uint> QryBrlyConMapLocation::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
