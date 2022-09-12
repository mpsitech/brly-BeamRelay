/**
	* \file QryBrlyLegMapLeg_blks.cpp
	* job handler for job QryBrlyLegMapLeg (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryBrlyLegMapLeg::StatShr
 ******************************************************************************/

QryBrlyLegMapLeg::StatShr::StatShr(
			const uint ntot
		) :
			Block()
		{
	this->ntot = ntot;

	mask = {NTOT};
};

void QryBrlyLegMapLeg::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrQryBrlyLegMapLeg";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ntot"] = ntot;
};

void QryBrlyLegMapLeg::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryBrlyLegMapLeg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryBrlyLegMapLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
	xmlTextWriterEndElement(wr);
};

set<uint> QryBrlyLegMapLeg::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);

	return(items);
};

set<uint> QryBrlyLegMapLeg::StatShr::diff(
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
 class QryBrlyLegMapLeg::StgIac
 ******************************************************************************/

QryBrlyLegMapLeg::StgIac::StgIac(
			const uint jnum
		) :
			Block()
		{
	this->jnum = jnum;
	mask = {JNUM};
};

bool QryBrlyLegMapLeg::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacQryBrlyLegMapLeg"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("jnum")) {jnum = me["jnum"].asUInt(); add(JNUM);};
	};

	return basefound;
};

bool QryBrlyLegMapLeg::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryBrlyLegMapLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryBrlyLegMapLeg";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
	};

	return basefound;
};

void QryBrlyLegMapLeg::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacQryBrlyLegMapLeg";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["jnum"] = jnum;
};

void QryBrlyLegMapLeg::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryBrlyLegMapLeg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryBrlyLegMapLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
	xmlTextWriterEndElement(wr);
};

set<uint> QryBrlyLegMapLeg::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);

	return(items);
};

set<uint> QryBrlyLegMapLeg::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
