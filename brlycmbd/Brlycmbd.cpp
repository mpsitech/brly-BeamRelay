/**
	* \file Brlycmbd.cpp
	* inter-thread exchange object for Brly combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "Brlycmbd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchAppBrly
 ******************************************************************************/

DpchAppBrly::DpchAppBrly(
			const uint ixBrlyVDpch
		) :
			DpchBrly(ixBrlyVDpch)
		{
	jref = 0;
};

DpchAppBrly::~DpchAppBrly() {
};

bool DpchAppBrly::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchAppBrly::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchAppBrly::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup[VecBrlyVDpch::getSref(ixBrlyVDpch)];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {
			jref = Scr::descramble(me["scrJref"].asString());
			add(JREF);
		};
	};
};

void DpchAppBrly::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrJref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecBrlyVDpch::getSref(ixBrlyVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
	};
};

/******************************************************************************
 class DpchAppBrlyAlert
 ******************************************************************************/

DpchAppBrlyAlert::DpchAppBrlyAlert() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYALERT)
		{
};

bool DpchAppBrlyAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

string DpchAppBrlyAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(NUMFMCB)) ss.push_back("numFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchAppBrlyAlert::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyAlert"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {
			jref = Scr::descramble(me["scrJref"].asString());
			add(JREF);
		};
		if (me.isMember("numFMcb")) {numFMcb = me["numFMcb"].asInt(); add(NUMFMCB);};
	};
};

void DpchAppBrlyAlert::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractUintUclc(docctx, basexpath, "numFMcb", "", numFMcb)) add(NUMFMCB);
	} else {
	};
};

/******************************************************************************
 class DpchAppBrlyInit
 ******************************************************************************/

DpchAppBrlyInit::DpchAppBrlyInit() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYINIT)
		{
};

/******************************************************************************
 class DpchAppBrlyResume
 ******************************************************************************/

DpchAppBrlyResume::DpchAppBrlyResume() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYRESUME)
		{
};

/******************************************************************************
 class DpchEngBrly
 ******************************************************************************/

DpchEngBrly::DpchEngBrly(
			const uint ixBrlyVDpch
			, const ubigint jref
		) :
			DpchBrly(ixBrlyVDpch)
		{
	this->jref = jref;

	mask = {JREF};
};

DpchEngBrly::~DpchEngBrly() {
};

bool DpchEngBrly::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchEngBrly::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchEngBrly::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngBrly* src = dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
};

void DpchEngBrly::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup[VecBrlyVDpch::getSref(ixBrlyVDpch)] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
};

void DpchEngBrly::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	string tag = VecBrlyVDpch::getSref(ixBrlyVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngBrlyAck
 ******************************************************************************/

DpchEngBrlyAck::DpchEngBrlyAck(
			const ubigint jref
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYACK, jref)
		{
};

/******************************************************************************
 class DpchEngBrlyAlert
 ******************************************************************************/

DpchEngBrlyAlert::DpchEngBrlyAlert(
			const ubigint jref
			, ContInfBrlyAlert* continf
			, Feed* feedFMcb
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYALERT, jref)
		{
	if (continf) this->continf = *continf;
	if (feedFMcb) this->feedFMcb = *feedFMcb;

	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFMCB};
	else this->mask = mask;
};

bool DpchEngBrlyAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

string DpchEngBrlyAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFMCB)) ss.push_back("feedFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngBrlyAlert::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngBrlyAlert* src = (DpchEngBrlyAlert*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFMCB)) {feedFMcb = src->feedFMcb; add(FEEDFMCB);};
};

void DpchEngBrlyAlert::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyAlert"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFMCB)) feedFMcb.writeJSON(me);
};

void DpchEngBrlyAlert::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFMCB)) feedFMcb.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngBrlyConfirm
 ******************************************************************************/

DpchEngBrlyConfirm::DpchEngBrlyConfirm(
			const bool accepted
			, const ubigint jref
			, const string& sref
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONFIRM, jref)
		{
	this->accepted = accepted;
	this->jref = jref;
	this->sref = sref;

	if (find(mask, ALL)) this->mask = {ACCEPTED, JREF, SREF};
	else this->mask = mask;
};

bool DpchEngBrlyConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

string DpchEngBrlyConfirm::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(ACCEPTED)) ss.push_back("accepted");
	if (has(JREF)) ss.push_back("jref");
	if (has(SREF)) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngBrlyConfirm::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngBrlyConfirm* src = (DpchEngBrlyConfirm*) dpcheng;

	if (src->has(ACCEPTED)) {accepted = src->accepted; add(ACCEPTED);};
	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(SREF)) {sref = src->sref; add(SREF);};
};

void DpchEngBrlyConfirm::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyConfirm"] = Json::Value(Json::objectValue);

	if (has(ACCEPTED)) me["accepted"] = accepted;
	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(SREF)) me["sref"] = sref;
};

void DpchEngBrlyConfirm::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyConfirm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(ACCEPTED)) writeBool(wr, "accepted", accepted);
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(SREF)) writeString(wr, "sref", sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngBrlySuspend
 ******************************************************************************/

DpchEngBrlySuspend::DpchEngBrlySuspend(
			const ubigint jref
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYSUSPEND, jref)
		{
};

/******************************************************************************
 class StgBrlyAppearance
 ******************************************************************************/

StgBrlyAppearance::StgBrlyAppearance(
			const usmallint histlength
			, const bool suspsess
			, const uint sesstterm
			, const uint sesstwarn
			, const uint roottterm
		) :
			Block()
		{
	this->histlength = histlength;
	this->suspsess = suspsess;
	this->sesstterm = sesstterm;
	this->sesstwarn = sesstwarn;
	this->roottterm = roottterm;
	mask = {HISTLENGTH, SUSPSESS, SESSTTERM, SESSTWARN, ROOTTTERM};
};

bool StgBrlyAppearance::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyAppearance");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyAppearance";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "histlength", histlength)) add(HISTLENGTH);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "suspsess", suspsess)) add(SUSPSESS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sesstterm", sesstterm)) add(SESSTTERM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sesstwarn", sesstwarn)) add(SESSTWARN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "roottterm", roottterm)) add(ROOTTTERM);
	};

	return basefound;
};

void StgBrlyAppearance::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyAppearance";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyAppearance";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "histlength", histlength);
		writeBoolAttr(wr, itemtag, "sref", "suspsess", suspsess);
		writeUintAttr(wr, itemtag, "sref", "sesstterm", sesstterm);
		writeUintAttr(wr, itemtag, "sref", "sesstwarn", sesstwarn);
		writeUintAttr(wr, itemtag, "sref", "roottterm", roottterm);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyAppearance::comm(
			const StgBrlyAppearance* comp
		) {
	set<uint> items;

	if (histlength == comp->histlength) insert(items, HISTLENGTH);
	if (suspsess == comp->suspsess) insert(items, SUSPSESS);
	if (sesstterm == comp->sesstterm) insert(items, SESSTTERM);
	if (sesstwarn == comp->sesstwarn) insert(items, SESSTWARN);
	if (roottterm == comp->roottterm) insert(items, ROOTTTERM);

	return(items);
};

set<uint> StgBrlyAppearance::diff(
			const StgBrlyAppearance* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {HISTLENGTH, SUSPSESS, SESSTTERM, SESSTWARN, ROOTTTERM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyAppsrv
 ******************************************************************************/

StgBrlyAppsrv::StgBrlyAppsrv(
			const usmallint port
			, const bool https
			, const string& cors
		) :
			Block()
		{
	this->port = port;
	this->https = https;
	this->cors = cors;
	mask = {PORT, HTTPS, CORS};
};

bool StgBrlyAppsrv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyAppsrv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyAppsrv";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "https", https)) add(HTTPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "cors", cors)) add(CORS);
	};

	return basefound;
};

void StgBrlyAppsrv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyAppsrv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyAppsrv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeBoolAttr(wr, itemtag, "sref", "https", https);
		writeStringAttr(wr, itemtag, "sref", "cors", cors);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyAppsrv::comm(
			const StgBrlyAppsrv* comp
		) {
	set<uint> items;

	if (port == comp->port) insert(items, PORT);
	if (https == comp->https) insert(items, HTTPS);
	if (cors == comp->cors) insert(items, CORS);

	return(items);
};

set<uint> StgBrlyAppsrv::diff(
			const StgBrlyAppsrv* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PORT, HTTPS, CORS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlycmbd
 ******************************************************************************/

StgBrlycmbd::StgBrlycmbd(
			const usmallint jobprcn
			, const usmallint opprcn
			, const bool appsrv
		) :
			Block()
		{
	this->jobprcn = jobprcn;
	this->opprcn = opprcn;
	this->appsrv = appsrv;
	mask = {JOBPRCN, OPPRCN, APPSRV};
};

bool StgBrlycmbd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlycmbd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlycmbd";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jobprcn", jobprcn)) add(JOBPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opprcn", opprcn)) add(OPPRCN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "appsrv", appsrv)) add(APPSRV);
	};

	return basefound;
};

void StgBrlycmbd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlycmbd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlycmbd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "jobprcn", jobprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "opprcn", opprcn);
		writeBoolAttr(wr, itemtag, "sref", "appsrv", appsrv);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlycmbd::comm(
			const StgBrlycmbd* comp
		) {
	set<uint> items;

	if (jobprcn == comp->jobprcn) insert(items, JOBPRCN);
	if (opprcn == comp->opprcn) insert(items, OPPRCN);
	if (appsrv == comp->appsrv) insert(items, APPSRV);

	return(items);
};

set<uint> StgBrlycmbd::diff(
			const StgBrlycmbd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JOBPRCN, OPPRCN, APPSRV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyDatabase
 ******************************************************************************/

StgBrlyDatabase::StgBrlyDatabase(
			const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& username
			, const string& password
			, const string& ip
			, const usmallint port
		) :
			Block()
		{
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	mask = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
};

bool StgBrlyDatabase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyDatabase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyDatabase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
	};

	return basefound;
};

void StgBrlyDatabase::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyDatabase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyDatabase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyDatabase::comm(
			const StgBrlyDatabase* comp
		) {
	set<uint> items;

	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);

	return(items);
};

set<uint> StgBrlyDatabase::diff(
			const StgBrlyDatabase* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyFlightaware
 ******************************************************************************/

StgBrlyFlightaware::StgBrlyFlightaware(
			const string& ip
			, const string& key
		) :
			Block()
		{
	this->ip = ip;
	this->key = key;
	mask = {IP, KEY};
};

bool StgBrlyFlightaware::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyFlightaware");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyFlightaware";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "key", key)) add(KEY);
	};

	return basefound;
};

void StgBrlyFlightaware::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyFlightaware";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyFlightaware";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeStringAttr(wr, itemtag, "sref", "key", key);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyFlightaware::comm(
			const StgBrlyFlightaware* comp
		) {
	set<uint> items;

	if (ip == comp->ip) insert(items, IP);
	if (key == comp->key) insert(items, KEY);

	return(items);
};

set<uint> StgBrlyFlightaware::diff(
			const StgBrlyFlightaware* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IP, KEY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyGeometry
 ******************************************************************************/

StgBrlyGeometry::StgBrlyGeometry(
			const double acraltitude
			, const double corrwidth1
			, const double corrwidth2
			, const double earthradius
			, const double hrznaltitude
		) :
			Block()
		{
	this->acraltitude = acraltitude;
	this->corrwidth1 = corrwidth1;
	this->corrwidth2 = corrwidth2;
	this->earthradius = earthradius;
	this->hrznaltitude = hrznaltitude;
	mask = {ACRALTITUDE, CORRWIDTH1, CORRWIDTH2, EARTHRADIUS, HRZNALTITUDE};
};

bool StgBrlyGeometry::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyGeometry");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyGeometry";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acraltitude", acraltitude)) add(ACRALTITUDE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "corrwidth1", corrwidth1)) add(CORRWIDTH1);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "corrwidth2", corrwidth2)) add(CORRWIDTH2);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "earthradius", earthradius)) add(EARTHRADIUS);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "hrznaltitude", hrznaltitude)) add(HRZNALTITUDE);
	};

	return basefound;
};

void StgBrlyGeometry::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyGeometry";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyGeometry";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "acraltitude", acraltitude);
		writeDoubleAttr(wr, itemtag, "sref", "corrwidth1", corrwidth1);
		writeDoubleAttr(wr, itemtag, "sref", "corrwidth2", corrwidth2);
		writeDoubleAttr(wr, itemtag, "sref", "earthradius", earthradius);
		writeDoubleAttr(wr, itemtag, "sref", "hrznaltitude", hrznaltitude);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyGeometry::comm(
			const StgBrlyGeometry* comp
		) {
	set<uint> items;

	if (compareDouble(acraltitude, comp->acraltitude) < 1.0e-4) insert(items, ACRALTITUDE);
	if (compareDouble(corrwidth1, comp->corrwidth1) < 1.0e-4) insert(items, CORRWIDTH1);
	if (compareDouble(corrwidth2, comp->corrwidth2) < 1.0e-4) insert(items, CORRWIDTH2);
	if (compareDouble(earthradius, comp->earthradius) < 1.0e-4) insert(items, EARTHRADIUS);
	if (compareDouble(hrznaltitude, comp->hrznaltitude) < 1.0e-4) insert(items, HRZNALTITUDE);

	return(items);
};

set<uint> StgBrlyGeometry::diff(
			const StgBrlyGeometry* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACRALTITUDE, CORRWIDTH1, CORRWIDTH2, EARTHRADIUS, HRZNALTITUDE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyMonitor
 ******************************************************************************/

StgBrlyMonitor::StgBrlyMonitor(
			const string& username
			, const string& password
			, const string& ip
			, const usmallint port
			, const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& dbsusername
			, const string& dbspassword
		) :
			Block()
		{
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->dbsusername = dbsusername;
	this->dbspassword = dbspassword;
	mask = {USERNAME, PASSWORD, IP, PORT, IXDBSVDBSTYPE, DBSPATH, DBSNAME, DBSUSERNAME, DBSPASSWORD};
};

bool StgBrlyMonitor::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyMonitor");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyMonitor";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsusername", dbsusername)) add(DBSUSERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspassword", dbspassword)) add(DBSPASSWORD);
	};

	return basefound;
};

void StgBrlyMonitor::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyMonitor";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyMonitor";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "dbsusername", dbsusername);
		writeStringAttr(wr, itemtag, "sref", "dbspassword", dbspassword);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyMonitor::comm(
			const StgBrlyMonitor* comp
		) {
	set<uint> items;

	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);
	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (dbsusername == comp->dbsusername) insert(items, DBSUSERNAME);
	if (dbspassword == comp->dbspassword) insert(items, DBSPASSWORD);

	return(items);
};

set<uint> StgBrlyMonitor::diff(
			const StgBrlyMonitor* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {USERNAME, PASSWORD, IP, PORT, IXDBSVDBSTYPE, DBSPATH, DBSNAME, DBSUSERNAME, DBSPASSWORD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgBrlyPath
 ******************************************************************************/

StgBrlyPath::StgBrlyPath(
			const string& acvpath
			, const string& keypath
			, const string& monpath
			, const string& tmppath
			, const string& webpath
			, const string& helpurl
		) :
			Block()
		{
	this->acvpath = acvpath;
	this->keypath = keypath;
	this->monpath = monpath;
	this->tmppath = tmppath;
	this->webpath = webpath;
	this->helpurl = helpurl;
	mask = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
};

bool StgBrlyPath::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyPath");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyPath";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acvpath", acvpath)) add(ACVPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "keypath", keypath)) add(KEYPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "monpath", monpath)) add(MONPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "tmppath", tmppath)) add(TMPPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "webpath", webpath)) add(WEBPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "helpurl", helpurl)) add(HELPURL);
	};

	return basefound;
};

void StgBrlyPath::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyPath";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyPath";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "acvpath", acvpath);
		writeStringAttr(wr, itemtag, "sref", "keypath", keypath);
		writeStringAttr(wr, itemtag, "sref", "monpath", monpath);
		writeStringAttr(wr, itemtag, "sref", "tmppath", tmppath);
		writeStringAttr(wr, itemtag, "sref", "webpath", webpath);
		writeStringAttr(wr, itemtag, "sref", "helpurl", helpurl);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyPath::comm(
			const StgBrlyPath* comp
		) {
	set<uint> items;

	if (acvpath == comp->acvpath) insert(items, ACVPATH);
	if (keypath == comp->keypath) insert(items, KEYPATH);
	if (monpath == comp->monpath) insert(items, MONPATH);
	if (tmppath == comp->tmppath) insert(items, TMPPATH);
	if (webpath == comp->webpath) insert(items, WEBPATH);
	if (helpurl == comp->helpurl) insert(items, HELPURL);

	return(items);
};

set<uint> StgBrlyPath::diff(
			const StgBrlyPath* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 namespace AlrBrly
 ******************************************************************************/

DpchEngBrlyAlert* AlrBrly::prepareAlrAbt(
			const ubigint jref
			, const uint ixBrlyVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfBrlyAlert continf;
	// IP prepareAlrAbt --- BEGIN
	continf.TxtCpt = VecBrlyVTag::getTitle(VecBrlyVTag::ABOUT, ixBrlyVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		continf.TxtMsg1 = "BeamRelay version v0.2.15 released on 11-9-2022";
		continf.TxtMsg2 = "\\u00a9 MPSI Technologies GmbH";
		continf.TxtMsg4 = "contributors: Alexander Wirthmueller";
		continf.TxtMsg6 = "libraries: png 1.6.36 and netcdf 4.7.3";
		continf.TxtMsg8 = "BeamRelay uses airline alliance timetable data to calculate the feasibility of multi-hop free-space optical data relays.";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		continf.TxtMsg1 = "BeamRelay Version v0.2.15 ver\\u00f6ffentlicht am 11-9-2022";
		continf.TxtMsg2 = "\\u00a9 MPSI Technologies GmbH";
		continf.TxtMsg4 = "Mitwirkende: Alexander Wirthmueller";
		continf.TxtMsg6 = "Programmbibliotheken: png 1.6.36 und netcdf 4.7.3";
		continf.TxtMsg8 = "BeamRelay verwendet Flugplandaten von Luftfahrt-Allianzen, um die Machbarkeit optischer Daten\\u00fcbertragung \\u00fcber mehrere Stationen zu berechnen.";
	};

	feedFMcbAlert.clear();

	VecBrlyVTag::appendToFeed(VecBrlyVTag::CLOSE, ixBrlyVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrAbt --- END
	return(new DpchEngBrlyAlert(jref, &continf, &feedFMcbAlert, {DpchEngBrlyAlert::ALL}));
};

DpchEngBrlyAlert* AlrBrly::prepareAlrIer(
			const ubigint jref
			, const uint ixBrlyVLocale
			, const string& iexsqk
			, Feed& feedFMcbAlert
		) {
	ContInfBrlyAlert continf;
	// IP prepareAlrIer --- BEGIN
	continf.TxtCpt = VecBrlyVTag::getTitle(VecBrlyVTag::IMPERR, ixBrlyVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		continf.TxtMsg1 = "" + iexsqk + "";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		continf.TxtMsg1 = "" + iexsqk + "";
	};

	feedFMcbAlert.clear();

	VecBrlyVTag::appendToFeed(VecBrlyVTag::CANCEL, ixBrlyVLocale, feedFMcbAlert);
	VecBrlyVTag::appendToFeed(VecBrlyVTag::REVERSE, ixBrlyVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrIer --- END
	return(new DpchEngBrlyAlert(jref, &continf, &feedFMcbAlert, {DpchEngBrlyAlert::ALL}));
};

DpchEngBrlyAlert* AlrBrly::prepareAlrPer(
			const ubigint jref
			, const uint ixBrlyVLocale
			, const string& iexsqk
			, Feed& feedFMcbAlert
		) {
	ContInfBrlyAlert continf;
	// IP prepareAlrPer --- BEGIN
	continf.TxtCpt = VecBrlyVTag::getTitle(VecBrlyVTag::PRSERR, ixBrlyVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		continf.TxtMsg1 = "" + iexsqk + "";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		continf.TxtMsg1 = "" + iexsqk + "";
	};

	feedFMcbAlert.clear();

	VecBrlyVTag::appendToFeed(VecBrlyVTag::OK, ixBrlyVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrPer --- END
	return(new DpchEngBrlyAlert(jref, &continf, &feedFMcbAlert, {DpchEngBrlyAlert::ALL}));
};

DpchEngBrlyAlert* AlrBrly::prepareAlrSav(
			const ubigint jref
			, const uint ixBrlyVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfBrlyAlert continf;
	// IP prepareAlrSav --- BEGIN
	continf.TxtCpt = VecBrlyVTag::getTitle(VecBrlyVTag::QUEST, ixBrlyVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		continf.TxtMsg1 = "Save changes?";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		continf.TxtMsg1 = "\\u00c4nderungen speichern?";
	};

	feedFMcbAlert.clear();

	VecBrlyVTag::appendToFeed(VecBrlyVTag::CANCEL, ixBrlyVLocale, feedFMcbAlert);
	VecBrlyVTag::appendToFeed(VecBrlyVTag::FLS, ixBrlyVLocale, feedFMcbAlert);
	VecBrlyVTag::appendToFeed(VecBrlyVTag::TRU, ixBrlyVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrSav --- END
	return(new DpchEngBrlyAlert(jref, &continf, &feedFMcbAlert, {DpchEngBrlyAlert::ALL}));
};

DpchEngBrlyAlert* AlrBrly::prepareAlrTrm(
			const ubigint jref
			, const uint ixBrlyVLocale
			, const uint sesstterm
			, const uint sesstwarn
			, Feed& feedFMcbAlert
		) {
	ContInfBrlyAlert continf;
	// IP prepareAlrTrm --- BEGIN
	continf.TxtCpt = VecBrlyVTag::getTitle(VecBrlyVTag::ANNOUNCE, ixBrlyVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		continf.TxtMsg1 = "Your session has been inactive for " + prepareAlrTrm_dtToString(ixBrlyVLocale, sesstterm) + ". It will be terminated in " + prepareAlrTrm_dtToString(ixBrlyVLocale, sesstwarn) + ".";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		continf.TxtMsg1 = "Ihre Sitzung ist seit " + prepareAlrTrm_dtToString(ixBrlyVLocale, sesstterm) + " inaktiv. Sie wird in " + prepareAlrTrm_dtToString(ixBrlyVLocale, sesstwarn) + " beendet.";
	};

	feedFMcbAlert.clear();

	VecBrlyVTag::appendToFeed(VecBrlyVTag::OK, ixBrlyVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrTrm --- END
	return(new DpchEngBrlyAlert(jref, &continf, &feedFMcbAlert, {DpchEngBrlyAlert::ALL}));
};

string AlrBrly::prepareAlrTrm_dtToString(
			const uint ixBrlyVLocale
			, const time_t dt
		) {
	string s;

	if ((dt%3600) == 0) {
		s = to_string(dt/3600);

		if (dt == 3600) s += " " + VecBrlyVTag::getTitle(VecBrlyVTag::HOUR, ixBrlyVLocale);
		else s += " " + VecBrlyVTag::getTitle(VecBrlyVTag::HOURS, ixBrlyVLocale);

	} else if ((dt%60) == 0) {
		s = to_string(dt/60);

		if (dt == 60) s += " " + VecBrlyVTag::getTitle(VecBrlyVTag::MINUTE, ixBrlyVLocale);
		else s += " " + VecBrlyVTag::getTitle(VecBrlyVTag::MINUTES, ixBrlyVLocale);

	} else {
		s = to_string(dt);

		if (dt == 1) s += " " + VecBrlyVTag::getTitle(VecBrlyVTag::SECOND, ixBrlyVLocale);
		else s += " " + VecBrlyVTag::getTitle(VecBrlyVTag::SECONDS, ixBrlyVLocale);
	};

	return s;
};

/******************************************************************************
 class ReqBrly
 ******************************************************************************/

ReqBrly::ReqBrly(
			const uint ixVBasetype
			, const uint ixVState
			, const string& ip
		) :
			cReady("cReady", "ReqBrly", "ReqBrly")
		{
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	retain = !((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::DPCHAPP) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD) || (ixVBasetype == VecVBasetype::METHOD));

	file = NULL;
	filelen = 0;

	request = NULL;
	requestlen = 0;

	jsonNotXml = false;

	jref = 0;

	wref = 0;

	call = NULL;

	weak = false;

	dpchapp = NULL;

	dpcheng = NULL;
	ixBrlyVLocale = VecBrlyVLocale::ENUS;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;

	method = NULL;
};

ReqBrly::~ReqBrly() {
	if (pp) MHD_destroy_post_processor(pp);

	if (file) {
		if (file->is_open()) file->close();
		delete file;
	};

	if (call) delete call;

	if (request) delete[] request;

	if (dpchapp) delete dpchapp;

	if (dpcheng) delete dpcheng;

	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	if (reply) delete[] reply;

	if (method) delete method;
};

void ReqBrly::setStateReply() {
	cReady.lockMutex("ReqBrly", "setStateReply", "jref=" + to_string(jref));
	ixVState = VecVState::REPLY;
	cReady.unlockMutex("ReqBrly", "setStateReply", "jref=" + to_string(jref));

	cReady.signal("ReqBrly", "setStateReply", "jref=" + to_string(jref));
};

/******************************************************************************
 class DcolBrly
 ******************************************************************************/

DcolBrly::DcolBrly(
			const ubigint jref
			, const uint ixBrlyVLocale
		) :
			mAccess("dcol.mAccess", "DcolBrly", "DcolBrly", "jref=" + to_string(jref))
		{
	this->jref = jref;
	this->ixBrlyVLocale = ixBrlyVLocale;

	hot = false;

	req = NULL;
};

DcolBrly::~DcolBrly() {
	for (auto it = dpchs.begin(); it != dpchs.end(); it++) delete(*it);

	if (req) req->cReady.signal("DcolBrly", "~DcolBrly", "jref=" + to_string(jref));

	mAccess.lock("DcolBrly", "~DcolBrly", "jref=" + to_string(jref));
	mAccess.unlock("DcolBrly", "~DcolBrly", "jref=" + to_string(jref));
};

void DcolBrly::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

void DcolBrly::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class JobBrly
 ******************************************************************************/

JobBrly::JobBrly(
			XchgBrly* xchg
			, const uint ixBrlyVJob
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			mAccess("mAccess", VecBrlyVJob::getSref(ixBrlyVJob), VecBrlyVJob::getSref(ixBrlyVJob), "jrefSup=" + to_string(jrefSup))
			, mOps("mOps", VecBrlyVJob::getSref(ixBrlyVJob), VecBrlyVJob::getSref(ixBrlyVJob), "jrefSup=" + to_string(jrefSup))
		{
	this->xchg = xchg;

	jref = 0;

	this->ixBrlyVJob = ixBrlyVJob;

	this->ixBrlyVLocale = ixBrlyVLocale;

	muteRefresh = false;

	ixVSge = 1;
	nextIxVSgeSuccess = 1;
	nextIxVSgeFailure = 1;

	opN = 0;
	opNSuccess = 0;
	opNFailure = 0;

	wrefLast = 0;
	wrefMin = 0;

	reqCmd = NULL;
};

JobBrly::~JobBrly() {
	if (reqCmd) delete reqCmd;

	mAccess.lock(VecBrlyVJob::getSref(ixBrlyVJob), "~" + VecBrlyVJob::getSref(ixBrlyVJob), "jref=" + to_string(jref));
	mAccess.unlock(VecBrlyVJob::getSref(ixBrlyVJob), "~" + VecBrlyVJob::getSref(ixBrlyVJob), "jref=" + to_string(jref));
};

ubigint JobBrly::insertSubjob(
			map<ubigint, JobBrly*>& subjobs
			, JobBrly* subjob
		) {
	subjobs[subjob->jref] = subjob;

	return subjob->jref;
};

bool JobBrly::eraseSubjobByJref(
			map<ubigint, JobBrly*>& subjobs
			, const ubigint _jref
		) {
	auto it = subjobs.find(_jref);

	if (it != subjobs.end()) {
		delete it->second;
		subjobs.erase(it);

		return true;
	};

	return false;
};

DpchEngBrly* JobBrly::getNewDpchEng(
			set<uint> items
		) {
	return new DpchEngBrlyConfirm(true, jref, "");
};

void JobBrly::refresh(
			DbsBrly* dbsbrly
			, set<uint>& moditems
			, const bool unmute
		) {
};

void JobBrly::refreshWithDpchEng(
			DbsBrly* dbsbrly
			, DpchEngBrly** dpcheng
			, const bool unmute
		) {
	set<uint> moditems;

	DpchEngBrly* _dpcheng = NULL;

	refresh(dbsbrly, moditems, unmute);
	if (muteRefresh) return;

	if (dpcheng) {
		_dpcheng = getNewDpchEng(moditems);

		if (*dpcheng) {
			if (_dpcheng->ixBrlyVDpch == VecBrlyVDpch::DPCHENGBRLYCONFIRM) delete _dpcheng;
			else if (_dpcheng->ixBrlyVDpch == (*dpcheng)->ixBrlyVDpch) {
				(*dpcheng)->merge(_dpcheng);
				delete _dpcheng;

			} else xchg->submitDpch(_dpcheng);

		} else *dpcheng = _dpcheng;

	} else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
};

string JobBrly::getSquawk(
			DbsBrly* dbsbrly
		) {
	return "";
};

void JobBrly::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
};

void JobBrly::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
};

void JobBrly::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

bool JobBrly::trylockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return mAccess.trylock(srefObject, srefMember, "jref=" + to_string(jref));
};

void JobBrly::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

void JobBrly::lockAccess(
			const string& srefMember
		) {
	mAccess.lock(VecBrlyVJob::getSref(ixBrlyVJob), srefMember, "jref=" + to_string(jref));
};

bool JobBrly::trylockAccess(
			const string& srefMember
		) {
	return mAccess.trylock(VecBrlyVJob::getSref(ixBrlyVJob), srefMember, "jref=" + to_string(jref));
};

void JobBrly::unlockAccess(
			const string& srefMember
		) {
	mAccess.unlock(VecBrlyVJob::getSref(ixBrlyVJob), srefMember, "jref=" + to_string(jref));
};

void JobBrly::setStage(
			DbsBrly* dbsbrly
			, const uint _ixVSge
		) {
	xchg->setJobStage(dbsbrly, this, _ixVSge);
};

void JobBrly::clearInvs() {
	for (unsigned int i = 0; i < invs.size(); i++) delete invs[i];
	invs.clear();
};

ubigint JobBrly::addInv(
			DpchInvBrly* inv
		) {
	inv->oref = xchg->orefseq.getNewRef();
	inv->jref = jref;

	invs.push_back(inv);

	opN++;

	return(inv->oref);
};

void JobBrly::addInvs(
			vector<DpchInvBrly*>& _invs
		) {
	for (unsigned int i = 0; i < _invs.size(); i++) addInv(_invs[i]);
};

void JobBrly::submitInvs(
			DbsBrly* dbsbrly
			, const uint nextIxVSgeEmpty
			, uint& _ixVSge
		) {
	if (opN == 0) {
		_ixVSge = nextIxVSgeEmpty;

	} else {
		xchg->addInvs(dbsbrly, this, invs);
		invs.clear();
	};
};

void JobBrly::clearOps() {
	mOps.lock(VecBrlyVJob::getSref(ixBrlyVJob), "clearOps", "jref=" + to_string(jref));

	for (auto it = ops.begin(); it != ops.end(); it++) delete(*it);
	ops.clear();

	mOps.unlock(VecBrlyVJob::getSref(ixBrlyVJob), "clearOps", "jref=" + to_string(jref));
};

void JobBrly::addOp(
			DbsBrly* dbsbrly
			, DpchInvBrly* inv
		) {
	string squawk;

	mOps.lock(VecBrlyVJob::getSref(ixBrlyVJob), "addOp", "jref=" + to_string(jref));

	// generate squawk
	if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELEGLEG) {
		squawk = SqkBrlyBase::getSquawkLegleg(dbsbrly, (DpchInvBrlyBaseLegleg*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELEGLOC) {
		squawk = SqkBrlyBase::getSquawkLegloc(dbsbrly, (DpchInvBrlyBaseLegloc*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELOCLOC) {
		squawk = SqkBrlyBase::getSquawkLocloc(dbsbrly, (DpchInvBrlyBaseLocloc*) inv);
	};
	if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPCOLLECT) {
		squawk = SqkBrlyDnsmap::getSquawkCollect(dbsbrly, (DpchInvBrlyDnsmapCollect*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPFRAME) {
		squawk = SqkBrlyDnsmap::getSquawkFrame(dbsbrly, (DpchInvBrlyDnsmapFrame*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPVIDEO) {
		squawk = SqkBrlyDnsmap::getSquawkVideo(dbsbrly, (DpchInvBrlyDnsmapVideo*) inv);
	};
	if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNCONFLT) {
		squawk = SqkBrlyDyn::getSquawkConflt(dbsbrly, (DpchInvBrlyDynConflt*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNCONSEG) {
		squawk = SqkBrlyDyn::getSquawkConseg(dbsbrly, (DpchInvBrlyDynConseg*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNEQPLIST) {
		squawk = SqkBrlyDyn::getSquawkEqplist(dbsbrly, (DpchInvBrlyDynEqplist*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNFLTFLTLOC) {
		squawk = SqkBrlyDyn::getSquawkFltfltloc(dbsbrly, (DpchInvBrlyDynFltfltloc*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNFLTSEG) {
		squawk = SqkBrlyDyn::getSquawkFltseg(dbsbrly, (DpchInvBrlyDynFltseg*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNRLY) {
		squawk = SqkBrlyDyn::getSquawkRly(dbsbrly, (DpchInvBrlyDynRly*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNSEGLOCSEG) {
		squawk = SqkBrlyDyn::getSquawkSeglocseg(dbsbrly, (DpchInvBrlyDynSeglocseg*) inv);
	};
	if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENCONMAP) {
		squawk = SqkBrlyMapgen::getSquawkConmap(dbsbrly, (DpchInvBrlyMapgenConmap*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENLEGMAP) {
		squawk = SqkBrlyMapgen::getSquawkLegmap(dbsbrly, (DpchInvBrlyMapgenLegmap*) inv);
	} else if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENLOCMAP) {
		squawk = SqkBrlyMapgen::getSquawkLocmap(dbsbrly, (DpchInvBrlyMapgenLocmap*) inv);
	};
	if (inv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYTTIMPRAWSTAR) {
		squawk = SqkBrlyTtimp::getSquawkRawstar(dbsbrly, (DpchInvBrlyTtimpRawstar*) inv);
	};

	// append to op list
	ops.push_back(new Op(inv->oref, inv->ixBrlyVDpch, squawk));

	mOps.unlock(VecBrlyVJob::getSref(ixBrlyVJob), "addOp", "jref=" + to_string(jref));
};

void JobBrly::removeOp(
			const ubigint oref
		) {
	Op* op = NULL;

	mOps.lock(VecBrlyVJob::getSref(ixBrlyVJob), "removeOp", "jref=" + to_string(jref));

	for (auto it = ops.begin(); it != ops.end(); it++) {
		op = *it;

		if (op->oref == oref) {
			// found
			ops.erase(it);

			// keep squawk of this op
			opsqkLast = op->squawk;

			delete op;
			
			break;
		};
	};

	mOps.unlock(VecBrlyVJob::getSref(ixBrlyVJob), "removeOp", "jref=" + to_string(jref));
};

string JobBrly::getOpsqkLast() {
	string retval;

	mOps.lock(VecBrlyVJob::getSref(ixBrlyVJob), "getOpsqkLast", "jref=" + to_string(jref));

	retval = opsqkLast;

	mOps.unlock(VecBrlyVJob::getSref(ixBrlyVJob), "getOpsqkLast", "jref=" + to_string(jref));

	return retval;
};

void JobBrly::callback(
			const uint nextIxVSge
		) {
	nextIxVSgeSuccess = nextIxVSge;
	wrefLast = xchg->addWakeup(jref, "callback", 0);
};

void JobBrly::invalidateWakeups() {
	wrefMin = wrefLast + 1;
};

/******************************************************************************
 class CsjobBrly
 ******************************************************************************/

CsjobBrly::CsjobBrly(
			XchgBrly* xchg
			, const uint ixBrlyVJob
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, ixBrlyVJob, jrefSup, ixBrlyVLocale)
		{
	srvNotCli = false;
	srv = NULL;
};

bool CsjobBrly::handleClaim(
			DbsBrly* dbsbrly
			, map<ubigint,Claim*>& claims
			, const ubigint jrefNewest
		) {
	return false;
};

/******************************************************************************
 class ShrdatBrly
 ******************************************************************************/

ShrdatBrly::ShrdatBrly(
			const string& srefSupclass
			, const string& srefObject
		) :
			rwmAccess("shrdat.mAccess", srefSupclass + "::" + srefObject, srefObject)
		{
	this->srefSupclass = srefSupclass;
	this->srefObject = srefObject;
};

ShrdatBrly::~ShrdatBrly() {
};

void ShrdatBrly::init(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
		) {
};

void ShrdatBrly::term(
			XchgBrly* xchg
		) {
};

void ShrdatBrly::rlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.rlock(srefObject, srefMember, args);
};

void ShrdatBrly::runlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.runlock(srefObject, srefMember, args);
};

void ShrdatBrly::rlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.rlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatBrly::runlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.runlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatBrly::wlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.wlock(srefObject, srefMember, args);
};

void ShrdatBrly::wunlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.wunlock(srefObject, srefMember, args);
};

void ShrdatBrly::wlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.wlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatBrly::wunlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.wunlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class StmgrBrly
 ******************************************************************************/

StmgrBrly::StmgrBrly(
			XchgBrly* xchg
			, const ubigint jref
			, const uint ixVNonetype
		) :
			mAccess("stmgr.mAccess", "StmgrBrly", "StmgrBrly", "jref=" + to_string(jref))
		{
	this->xchg = xchg;

	this->jref = jref;
	this->ixVNonetype = ixVNonetype;

	stcch = new Stcch(true);
};

StmgrBrly::~StmgrBrly() {
	delete stcch;

	mAccess.lock("StmgrBrly", "~StmgrBrly", "jref=" + to_string(jref));
	mAccess.unlock("StmgrBrly", "~StmgrBrly", "jref=" + to_string(jref));
};

void StmgrBrly::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	set<uint> icsBrlyVStub;
	pair<multimap<stcchitemref_t,Stcchitem*>::iterator,multimap<stcchitemref_t,Stcchitem*>::iterator> rng;

	bool notif = false;

	begin();

	if (call->ixVCall == VecBrlyVCall::CALLBRLYCONUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYCONSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYCONSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYEQPUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYEQPSHORT);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYEQPSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYEQPSHORT);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYEQPSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFAFUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYFAFSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFILUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYFILSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYFILSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYFLTUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYFLTSREF);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYFLTSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYFLTSREF);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLEGUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLEGSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLEGSHORT);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLEGSHORT);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLEGSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYLOCUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLOCSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLOCTITLE);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLOCSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYLOCSREF);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYNDEUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYNDELONG);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYNDESTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYNDESTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYNDELONG);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYOPRUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYOPRSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYOPRSREF);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYOPRSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYPRSUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYPRSSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYPRSSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYPTYUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYPTYSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYPTYSREF);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYPTYSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYREGUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYREGSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYREGHSREF);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYREGHSREF);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYREGSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYREGLONG);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYREGLONG);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYRLYUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYRLYLONG);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYRLYSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYRLYLONG);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYRLYSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSEGUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYSEGSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYSEGSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYSESUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYSESMENU);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYSESSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYSESSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYSESMENU);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYTTBUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYTTBTITLE);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYTTBSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYTTBSTD);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSGUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYUSGSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYGROUP);
	} else if (call->ixVCall == VecBrlyVCall::CALLBRLYUSRUPD_REFEQ) {
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYUSRSTD);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYOWNER);
		insert(icsBrlyVStub, VecBrlyVStub::STUBBRLYUSRSTD);
	};

	for (auto it = icsBrlyVStub.begin(); it != icsBrlyVStub.end(); it++) {
		rng = stcch->nodes.equal_range(stcchitemref_t(*it, call->argInv.ref, 0));
		for (auto it2 = rng.first; it2 != rng.second; it2++) if (refresh(dbsbrly, it2->second)) notif = true;
	};

	commit();

	if (notif) xchg->triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYSTUBCHG, jref);
};

bool StmgrBrly::refresh(
			DbsBrly* dbsbrly
			, Stcchitem* stit
		) {
	set<stcchitemref_t> strefsSub_backup;
	string stub_backup;

	while (!stit->strefsSup.empty()) stcch->unlink(*stit->strefsSup.begin(), stit->stref);

	strefsSub_backup = stit->strefsSub;
	stub_backup = stit->stub;

	StubBrly::getStub(dbsbrly, stit->stref.ixVStub, stit->stref.ref, stit->stref.ixVLocale, ixVNonetype, stcch, NULL, true);

	if (stit->stub != stub_backup) {
		for (auto it = strefsSub_backup.begin(); it != strefsSub_backup.end(); it++) refresh(dbsbrly, stcch->getStitByStref(*it));
		return true;
	} else return false;
};

void StmgrBrly::begin() {
	stcch->begin();
};

void StmgrBrly::commit() {
	for (auto it = stcch->icsVStubNew.begin(); it != stcch->icsVStubNew.end(); it++) {
		if (*it == VecBrlyVStub::STUBBRLYCONSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYCONUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYCONUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYEQPSHORT) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYEQPUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYEQPUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYEQPSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYEQPUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYEQPUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYFAFSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYFAFUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYFILSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYFILUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYFILUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYFLTSREF) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYFLTUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYFLTUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYFLTSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYFLTUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYGROUP) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYUSGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYLEGSHORT) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLEGUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLEGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYLEGSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLEGUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLEGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYLOCSREF) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLOCUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYLOCSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLOCUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLOCUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYLOCTITLE) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYLOCUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYNDELONG) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYNDEUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYNDEUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYNDESTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYNDEUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYNDEUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYOPRSREF) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYOPRUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYOPRSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYOPRUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYOPRUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYOWNER) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYUSRUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYPRSSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYPRSUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYPRSUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYPTYSREF) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYPTYUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYPTYSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYPTYUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYPTYUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYREGHSREF) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYREGLONG) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYREGSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYREGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYRLYLONG) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYRLYUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYRLYUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYRLYSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYRLYUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYRLYUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYSEGSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYSEGUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYSEGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYSESMENU) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYSESUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYSESUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYSESSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYSESUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYSESUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYTTBSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYTTBUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYTTBUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYTTBTITLE) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYTTBUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYUSGSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYUSGUPD_REFEQ, jref);
		} else if (*it == VecBrlyVStub::STUBBRLYUSRSTD) {
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYUSRUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecBrlyVCall::CALLBRLYUSRUPD_REFEQ, jref);
		};
	};

	stcch->commit();
};

void StmgrBrly::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

void StmgrBrly::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class WakeupBrly
 ******************************************************************************/

WakeupBrly::WakeupBrly(
			XchgBrly* xchg
			, const ubigint wref
			, const ubigint jref
			, const string sref
			, const uint64_t deltat
			, const bool weak
		) {
	this->xchg = xchg;
	this->wref = wref;
	this->jref = jref;
	this->sref = sref;
	this->deltat = deltat;
	this->weak = weak;
};

/******************************************************************************
 class ExtcallBrly
 ******************************************************************************/

ExtcallBrly::ExtcallBrly(
			XchgBrly* xchg
			, Call* call
		) {
	this->xchg = xchg;
	this->call = call;
};

// IP ShrdatJobprc.subs --- INSERT

/******************************************************************************
 class XchgBrlycmbd::ShrdatJobprc
 ******************************************************************************/

XchgBrlycmbd::ShrdatJobprc::ShrdatJobprc() :
			ShrdatBrly("XchgBrly", "ShrdatJobprc")
		{
};

void XchgBrlycmbd::ShrdatJobprc::init(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
		) {
	// IP ShrdatJobprc.init --- INSERT
};

void XchgBrlycmbd::ShrdatJobprc::term(
			XchgBrly* xchg
		) {
	// IP ShrdatJobprc.term --- INSERT
};

// IP ShrdatOpprc.subs --- INSERT

/******************************************************************************
 class XchgBrlycmbd::ShrdatOpprc
 ******************************************************************************/

XchgBrlycmbd::ShrdatOpprc::ShrdatOpprc() :
			ShrdatBrly("XchgBrly", "ShrdatOpprc")
		{
};

void XchgBrlycmbd::ShrdatOpprc::init(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
		) {
	// IP ShrdatOpprc.init --- INSERT
};

void XchgBrlycmbd::ShrdatOpprc::term(
			XchgBrly* xchg
		) {
	// IP ShrdatOpprc.term --- INSERT
};

/******************************************************************************
 class XchgBrlycmbd
 ******************************************************************************/

XchgBrlycmbd::XchgBrlycmbd() :
			cStable("cStable", "XchgBrlycmbd", "XchgBrlycmbd")
			, mLogfile("mLogfile", "XchgBrlycmbd", "XchgBrlycmbd")
			, cJobprcs("cJobprcs", "XchgBrlycmbd", "XchgBrlycmbd")
			, cOpprcs("cOpprcs", "XchgBrlycmbd", "XchgBrlycmbd")
			, mReqs("mReqs", "XchgBrlycmbd", "XchgBrlycmbd")
			, orefseq("orefseq")
			, mInvs("mInvs", "XchgBrlycmbd", "XchgBrlycmbd")
			, rwmPresets("rwmPresets", "XchgBrlycmbd", "XchgBrlycmbd")
			, rwmStmgrs("rwmStmgrs", "XchgBrlycmbd", "XchgBrlycmbd")
			, rwmClstns("rwmClstns", "XchgBrlycmbd", "XchgBrlycmbd")
			, rwmDcols("rwmDcols", "XchgBrlycmbd", "XchgBrlycmbd")
			, jrefseq("jrefseq")
			, rwmJobs("rwmJobs", "XchgBrlycmbd", "XchgBrlycmbd")
			, rwmCsjobinfos("rwmCsjobinfos", "XchgBrlycmbd", "XchgBrlycmbd")
			, wrefseq("wrefseq")
		{
	// root job
	jrefRoot = 0;

	// job receiving commands
	jrefCmd = 0;

	// client-server job information

};

XchgBrlycmbd::~XchgBrlycmbd() {
	// empty out lists
	for (auto it = reqs.begin(); it != reqs.end(); it++) delete(*it);
	for (auto it = invs.begin(); it != invs.end(); it++) delete(*it);
	for (auto it = presets.begin(); it != presets.end(); it++) delete(it->second);
	for (auto it = stmgrs.begin(); it != stmgrs.end(); it++) delete(it->second);
	for (auto it = clstns.begin(); it != clstns.end(); it++) delete(it->second);
	for (auto it = dcols.begin(); it != dcols.end(); it++) delete(it->second);
	for (auto it = jobs.begin(); it != jobs.end(); it++) delete(it->second);
	for (auto it = jobinfos.begin(); it != jobinfos.end(); it++) delete(it->second);
	for (auto it = csjobinfos.begin(); it != csjobinfos.end(); it++) delete(it->second);
};

// IP cust --- INSERT

void XchgBrlycmbd::startMon() {
	JobBrly* job = NULL;
	Jobinfo* jobinfo = NULL;

	DcolBrly* dcol = NULL;
	bool Dcol;

	StmgrBrly* stmgr = NULL;
	bool Stmgr;

	Clstn* clstn = NULL;
	Preset* preset = NULL;

	mon.start("BeamRelay v0.2.15", stgbrlymonitor.ixDbsVDbstype, stgbrlymonitor.dbspath, stgbrlymonitor.dbsname, stgbrlymonitor.ip, stgbrlymonitor.port, stgbrlymonitor.dbsusername, stgbrlymonitor.dbspassword, stgbrlymonitor.username, stgbrlymonitor.password);

	rwmJobs.rlock("XchgBrlycmbd", "startMon");
	for (auto it = jobs.begin(); it != jobs.end(); it++) {
		job = it->second;
		jobinfo = jobinfos[job->jref];

		dcol = getDcolByJref(job->jref, false);
		if (dcol) {
			Dcol = true;
			dcol->unlockAccess("XchgBrlycmbd", "startMon");
		} else Dcol = false;

		stmgr = getStmgrByJref(job->jref);
		if (stmgr) {
			Stmgr = true;
			stmgr->unlockAccess("XchgBrlycmbd", "startMon");
		} else Stmgr = false;

		if (getCsjobNotJob(job->ixBrlyVJob)) mon.insertJob(jobinfo->jrefSup, VecBrlyVJob::getSref(job->ixBrlyVJob), job->jref, true, ((CsjobBrly*) job)->srvNotCli, Dcol, Stmgr);
		else mon.insertJob(jobinfo->jrefSup, VecBrlyVJob::getSref(job->ixBrlyVJob), job->jref, false, false, Dcol, Stmgr);
	};
	rwmJobs.runlock("XchgBrlycmbd", "startMon");

	rwmClstns.rlock("XchgBrlycmbd", "startMon");
	for (auto it = clstns.begin(); it != clstns.end(); it++) {
		clstn = it->second;
		mon.insertClstn(clstn->cref.jref, Clstn::VecVTarget::getSref(clstn->cref.ixVTarget), VecBrlyVCall::getSref(clstn->cref.ixVCall), Clstn::VecVJobmask::getSref(clstn->cref.ixVJobmask), clstn->cref.jrefTrig, clstn->cref.arg, clstn->cref.ixVSge, Clstn::VecVJactype::getSref(clstn->ixVJactype));
	};
	rwmClstns.runlock("XchgBrlycmbd", "startMon");

	rwmPresets.rlock("XchgBrlycmbd", "startMon");
	for (auto it = presets.begin(); it != presets.end(); it++) {
		preset = it->second;
		mon.insertPreset(preset->pref.jref, VecBrlyVPreset::getSref(preset->pref.ixVPreset), preset->arg);
	};
	rwmPresets.runlock("XchgBrlycmbd", "startMon");

	triggerCall(NULL, VecBrlyVCall::CALLBRLYMONSTATCHG, jrefRoot);
};

void XchgBrlycmbd::stopMon() {
	mon.stop();

	triggerCall(NULL, VecBrlyVCall::CALLBRLYMONSTATCHG, jrefRoot);
};

void XchgBrlycmbd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	mLogfile.lock("XchgBrlycmbd", "appendToLogfile");

	time(&rawtime);

	logfile.open(exedir + "/log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	mLogfile.unlock("XchgBrlycmbd", "appendToLogfile");
};

void XchgBrlycmbd::addReq(
			ReqBrly* req
		) {
	if (jrefRoot == 0) return;

	mReqs.lock("XchgBrlycmbd", "addReq", "jref=" + to_string(req->jref));

	req->ixVState = ReqBrly::VecVState::WAITPRC;
	reqs.push_back(req);

	mReqs.unlock("XchgBrlycmbd", "addReq", "jref=" + to_string(req->jref));

	cJobprcs.signal("XchgBrlycmbd", "addReq", "jref=" + to_string(req->jref));
};

ReqBrly* XchgBrlycmbd::pullFirstReq() {
	ReqBrly* req;

	// get first element from list
	mReqs.lock("XchgBrlycmbd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqBrly::VecVState::PRC;
		reqs.pop_front();
	};

	mReqs.unlock("XchgBrlycmbd", "pullFirstReq");

	return req;
};

void XchgBrlycmbd::addInvs(
			DbsBrly* dbsbrly
			, JobBrly* job
			, vector<DpchInvBrly*>& dpchinvs
		) {
	// append to inv list and signal the news (note the double-lock)
	mInvs.lock("XchgBrlycmbd", "addInvs", "jref=" + to_string(job->jref));
	job->mOps.lock("XchgBrlycmbd", "addInvs", "jref=" + to_string(job->jref));

	for (unsigned int i = 0; i < dpchinvs.size(); i++) {
		job->addOp(dbsbrly, dpchinvs[i]);

		invs.push_back(dpchinvs[i]);

		mon.eventAddInv(job->jref, VecBrlyVDpch::getSref(dpchinvs[i]->ixBrlyVDpch), "", dpchinvs[i]->oref);
	};

	job->mOps.unlock("XchgBrlycmbd", "addInvs", "jref=" + to_string(job->jref));
	mInvs.unlock("XchgBrlycmbd", "addInvs", "jref=" + to_string(job->jref));

	cOpprcs.broadcast("XchgBrlycmbd", "addInvs", "jref=" + to_string(job->jref));
};

DpchInvBrly* XchgBrlycmbd::pullFirstInv() {
	DpchInvBrly* inv;

	// get first element from list
	mInvs.lock("XchgBrlycmbd", "pullFirstInv");

	inv = NULL;

	if (!invs.empty()) {
		inv = *(invs.begin());
		invs.pop_front();
	};

	mInvs.unlock("XchgBrlycmbd", "pullFirstInv");

	return inv;
};

Preset* XchgBrlycmbd::addPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const Arg& arg
		) {
	presetref_t pref(jref, ixBrlyVPreset);
	Preset* preset;

	// create new presetting (override value if exists) and append to presetting list
	preset = getPresetByPref(pref);

	rwmPresets.wlock("XchgBrlycmbd", "addPreset", "jref=" + to_string(jref));

	if (preset) {
		preset->arg = arg;

		mon.eventChangePreset(jref, VecBrlyVPreset::getSref(ixBrlyVPreset), arg);

	} else {
		preset = new Preset(pref, arg);
		presets.insert(pair<presetref_t,Preset*>(pref, preset));

		mon.eventAddPreset(jref, VecBrlyVPreset::getSref(ixBrlyVPreset), arg);
	};

	rwmPresets.wunlock("XchgBrlycmbd", "addPreset", "jref=" + to_string(jref));

	return(preset);
};

Preset* XchgBrlycmbd::addIxPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const uint ix
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX)));
};

Preset* XchgBrlycmbd::addRefPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const ubigint ref
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF)));
};

Preset* XchgBrlycmbd::addRefsPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const vector<ubigint>& refs
		) {
	Arg arg(0, 0, refs, "", 0, 0.0, false, "", Arg::REFS);

	return(addPreset(ixBrlyVPreset, jref, arg));
};

Preset* XchgBrlycmbd::addSrefPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const string& sref
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF)));
};

Preset* XchgBrlycmbd::addIntvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const int intval
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, 0, {}, "", intval, 0.0, false, "", Arg::INTVAL)));
};

Preset* XchgBrlycmbd::addDblvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const double dblval
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, 0, {}, "", 0, dblval, false, "", Arg::DBLVAL)));
};

Preset* XchgBrlycmbd::addBoolvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const bool boolval
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, boolval, "", Arg::BOOLVAL)));
};

Preset* XchgBrlycmbd::addTxtvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
			, const string& txtval
		) {
	return(addPreset(ixBrlyVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, false, txtval, Arg::TXTVAL)));
};

Preset* XchgBrlycmbd::getPresetByPref(
			const presetref_t& pref
		) {
	Preset* preset = NULL;

	rwmPresets.rlock("XchgBrlycmbd", "getPresetByPref");

	auto it = presets.find(pref);
	if (it != presets.end()) preset = it->second;

	rwmPresets.runlock("XchgBrlycmbd", "getPresetByPref");

	return preset;
};

Arg XchgBrlycmbd::getPreset(
			const uint ixBrlyVPreset
			, ubigint jref
		) {
	Arg arg;

	Jobinfo* jobinfo = NULL;
	Preset* preset = NULL;

	if ( (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSDATE) || (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSTIME) || (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSSTAMP) ) {
		time_t rawtime;
		time(&rawtime);

		if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSSTAMP) {
			arg.mask = Arg::REF;
			arg.ref = rawtime;

		} else {
			arg.mask = Arg::INTVAL;

			if (ixBrlyVPreset == VecBrlyVPreset::PREBRLYSYSDATE) arg.intval = (rawtime-rawtime%(3600*24))/(3600*24);
			else arg.intval = rawtime%(3600*24);
		};

	} else {
		rwmJobs.rlock("XchgBrlycmbd", "getPreset", "jref=" + to_string(jref));
		rwmPresets.rlock("XchgBrlycmbd", "getPreset", "jref=" + to_string(jref));

		jobinfo = getJobinfoByJref(jref);

		if (jobinfo && (ixBrlyVPreset == VecBrlyVPreset::PREBRLYIXLCL)) {
			arg.mask = Arg::IX;
			arg.ix = jobs[jref]->ixBrlyVLocale;

		} else {
			while (jobinfo && !preset) {
				preset = getPresetByPref(presetref_t(jref, ixBrlyVPreset));

				if (preset) arg = preset->arg;
				else {
					jref = jobinfo->jrefSup;
					jobinfo = getJobinfoByJref(jref);
				};
			};
		};

		rwmPresets.runlock("XchgBrlycmbd", "getPreset", "jref=" + to_string(jref));
		rwmJobs.runlock("XchgBrlycmbd", "getPreset", "jref=" + to_string(jref));
	};

	return(arg);
};

uint XchgBrlycmbd::getIxPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::IX) return(arg.ix);
	else return(0);
};

ubigint XchgBrlycmbd::getRefPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::REF) return(arg.ref);
	else return(0);
};

vector<ubigint> XchgBrlycmbd::getRefsPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);
	vector<ubigint> empty;

	if (arg.mask & Arg::REFS) return(arg.refs);
	else return(empty);
};

string XchgBrlycmbd::getSrefPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::SREF) return(arg.sref);
	else return("");
};

int XchgBrlycmbd::getIntvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::INTVAL) return(arg.intval);
	else return(intvalInvalid);
};

double XchgBrlycmbd::getDblvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::DBLVAL) return(arg.dblval);
	else return(dblvalInvalid);
};

bool XchgBrlycmbd::getBoolvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::BOOLVAL) return(arg.boolval);
	else return(false);
};

string XchgBrlycmbd::getTxtvalPreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixBrlyVPreset, jref);

	if (arg.mask & Arg::TXTVAL) return(arg.txtval);
	else return("");
};

void XchgBrlycmbd::getPresetsByJref(
			const ubigint jref
			, vector<uint>& icsBrlyVPreset
			, vector<Arg>& args
		) {
	Preset* preset = NULL;

	icsBrlyVPreset.clear();
	args.clear();

	rwmPresets.rlock("XchgBrlycmbd", "getPresetsByJref", "jref=" + to_string(jref));

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		preset = it->second;

		icsBrlyVPreset.push_back(preset->pref.ixVPreset);
		args.push_back(preset->arg);
	};

	rwmPresets.runlock("XchgBrlycmbd", "getPresetsByJref", "jref=" + to_string(jref));
};

void XchgBrlycmbd::removePreset(
			const uint ixBrlyVPreset
			, const ubigint jref
		) {
	rwmPresets.wlock("XchgBrlycmbd", "removePreset", "jref=" + to_string(jref) + ",srefIxBrlyVPreset=" + VecBrlyVPreset::getSref(ixBrlyVPreset));

	auto it = presets.find(presetref_t(jref, ixBrlyVPreset));
	if (it != presets.end()) {
		delete it->second;
		presets.erase(it);

		mon.eventRemovePreset(jref, VecBrlyVPreset::getSref(ixBrlyVPreset));
	};

	rwmPresets.wunlock("XchgBrlycmbd", "removePreset", "jref=" + to_string(jref) + ",srefIxBrlyVPreset=" + VecBrlyVPreset::getSref(ixBrlyVPreset));
};

void XchgBrlycmbd::removePresetsByJref(
			const ubigint jref
		) {
	rwmPresets.wlock("XchgBrlycmbd", "removePresetsByJref", "jref=" + to_string(jref));

	uint ixVPreset;

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		ixVPreset = it->second->pref.ixVPreset;
		delete it->second;

		mon.eventRemovePreset(jref, VecBrlyVPreset::getSref(ixVPreset));
	};
	presets.erase(rng.first, rng.second);

	rwmPresets.wunlock("XchgBrlycmbd", "removePresetsByJref", "jref=" + to_string(jref));
};

StmgrBrly* XchgBrlycmbd::addStmgr(
			const ubigint jref
			, const uint ixVNonetype
		) {
	StmgrBrly* stmgr = NULL;

	// create new stmgr and append to stmgr list
	stmgr = getStmgrByJref(jref);

	if (!stmgr) {
		rwmStmgrs.wlock("XchgBrlycmbd", "addStmgr", "jref=" + to_string(jref));

		stmgr = new StmgrBrly(this, jref, ixVNonetype);
		stmgrs[jref] = stmgr;

		rwmStmgrs.wunlock("XchgBrlycmbd", "addStmgr", "jref=" + to_string(jref));

		mon.eventAddStmgr(jref);
	};

	return(stmgr);
};

StmgrBrly* XchgBrlycmbd::getStmgrByJref(
			const ubigint jref
		) {
	StmgrBrly* stmgr = NULL;

	rwmStmgrs.rlock("XchgBrlycmbd", "getStmgrByJref", "jref=" + to_string(jref));

	auto it = stmgrs.find(jref);

	if (it != stmgrs.end()) {
		stmgr = it->second;
		stmgr->lockAccess("XchgBrlycmbd", "getStmgrByJref");
	};

	rwmStmgrs.runlock("XchgBrlycmbd", "getStmgrByJref", "jref=" + to_string(jref));

	return(stmgr);
};

void XchgBrlycmbd::removeStmgrByJref(
			const ubigint jref
		) {
	rwmStmgrs.wlock("XchgBrlycmbd", "removeStmgrByJref", "jref=" + to_string(jref));

	removeClstnsByJref(jref, Clstn::VecVTarget::STMGR);

	auto it = stmgrs.find(jref);
	if (it != stmgrs.end()) {
		delete it->second;
		stmgrs.erase(it);

		mon.eventRemoveStmgr(jref);
	};

	rwmStmgrs.wunlock("XchgBrlycmbd", "removeStmgrByJref", "jref=" + to_string(jref));
};

Clstn* XchgBrlycmbd::addClstn(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const Arg& arg
			, const uint ixVSge
			, const uint ixVJactype
		) {
	clstnref_t cref(ixBrlyVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig, arg, ixVSge);
	clstnref2_t cref2(cref);

	multimap<clstnref_t,Clstn*>::iterator it;
	Clstn* clstn = NULL;

	rwmClstns.wlock("XchgBrlycmbd", "addClstn", "jref=" + to_string(jref) + ",srefIxBrlyVCall=" + VecBrlyVCall::getSref(ixBrlyVCall));

	if (!chgarg) it = clstns.end();
	else {
		Arg argFind = arg;
		argFind.clearContent();

		clstnref_t crefFind(ixBrlyVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig, argFind, ixVSge);

		it = clstns.find(crefFind);
	};

	if (it == clstns.end()) {
		// create new clstn and append to clstn list
		clstn = new Clstn(cref, ixVJactype);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(jref, "job", VecBrlyVCall::getSref(ixBrlyVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJactype::getSref(ixVJactype));

	} else {
		// change clstn argument
		clstn = it->second;
		clstn->cref = cref;

		cref2sClstns.erase(clstnref2_t(it->first));
		clstns.erase(it->first);

		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));
		
		mon.eventChangeClstnArg(jref, "job", VecBrlyVCall::getSref(ixBrlyVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJactype::getSref(ixVJactype));
	};

	rwmClstns.wunlock("XchgBrlycmbd", "addClstn", "jref=" + to_string(jref) + ",srefIxBrlyVCall=" + VecBrlyVCall::getSref(ixBrlyVCall));

	return(clstn);
};

Clstn* XchgBrlycmbd::addIxClstn(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX);

	return(addClstn(ixBrlyVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgBrlycmbd::addRefClstn(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const ubigint ref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF);

	return(addClstn(ixBrlyVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgBrlycmbd::addIxRefClstn(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const ubigint ref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, ref, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);

	return(addClstn(ixBrlyVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
		};

Clstn* XchgBrlycmbd::addIxRefSrefClstn(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const ubigint ref
			, const string& sref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, ref, {}, sref, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);

	return(addClstn(ixBrlyVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgBrlycmbd::addClstnStmgr(
			const uint ixBrlyVCall
			, const ubigint jref
		) {
	clstnref_t cref(ixBrlyVCall, jref, Clstn::VecVTarget::STMGR, Clstn::VecVJobmask::ALL);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	clstn = getClstnByCref(cref);

	if (!clstn) {
		rwmClstns.wlock("XchgBrlycmbd", "addClstnStmgr", "jref=" + to_string(jref) + ",srefIxBrlyVCall=" + VecBrlyVCall::getSref(ixBrlyVCall));

		clstn = new Clstn(cref, Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		rwmClstns.wunlock("XchgBrlycmbd", "addClstnStmgr", "jref=" + to_string(jref) + ",srefIxBrlyVCall=" + VecBrlyVCall::getSref(ixBrlyVCall));

		mon.eventAddClstn(jref, "stmgr", VecBrlyVCall::getSref(ixBrlyVCall), Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::ALL), 0, Arg(), 0, Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	return(clstn);
};

Clstn* XchgBrlycmbd::getClstnByCref(
			const clstnref_t& cref
		) {
	Clstn* clstn = NULL;

	rwmClstns.rlock("XchgBrlycmbd", "getClstnByCref");

	auto it = clstns.find(cref);
	if (it != clstns.end()) clstn = it->second;

	rwmClstns.runlock("XchgBrlycmbd", "getClstnByCref");

	return clstn;
};

void XchgBrlycmbd::getClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
			, vector<uint>& icsBrlyVCall
			, vector<uint>& icsVJobmask
		) {
	Clstn* clstn = NULL;

	icsBrlyVCall.clear();
	icsVJobmask.clear();

	rwmClstns.rlock("XchgBrlycmbd", "getClstnsByJref", "jref=" + to_string(jref));

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		clstn = getClstnByCref(it->second);

		if (clstn) {
			icsBrlyVCall.push_back(clstn->cref.ixVCall);
			icsVJobmask.push_back(clstn->cref.ixVJobmask);
		};
	};

	rwmClstns.runlock("XchgBrlycmbd", "getClstnsByJref", "jref=" + to_string(jref));
};

void XchgBrlycmbd::removeClstns(
			const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixVTarget
		) {
	rwmClstns.wlock("XchgBrlycmbd", "removeClstns", "jref=" + to_string(jref));

	uint ixVJobmask;
	ubigint jrefTrig;
	Arg arg;
	uint ixVSge;
	uint ixVJactype;

	auto rng = clstns.equal_range(clstnref_t(ixBrlyVCall, jref, ixVTarget));
	for (auto it = rng.first; it != rng.second; it++) {
		ixVJobmask = it->second->cref.ixVJobmask;
		jrefTrig = it->second->cref.jrefTrig;
		arg = it->second->cref.arg;
		ixVSge = it->second->cref.ixVSge;
		ixVJactype = it->second->ixVJactype;

		cref2sClstns.erase(clstnref2_t(it->first));
		delete it->second;

		mon.eventRemoveClstn(jref, Clstn::VecVTarget::getSref(ixVTarget), VecBrlyVCall::getSref(ixBrlyVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJobmask::getSref(ixVJactype));
	};
	clstns.erase(rng.first, rng.second);

	rwmClstns.wunlock("XchgBrlycmbd", "removeClstns", "jref=" + to_string(jref));
};

void XchgBrlycmbd::removeClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
		) {
	rwmClstns.wlock("XchgBrlycmbd", "removeClstnsByJref", "jref=" + to_string(jref));

	uint ixVCall;
	uint ixVJobmask;
	ubigint jrefTrig;
	Arg arg;
	uint ixVSge;
	uint ixVJactype;

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget));
	for (auto it = rng.first; it != rng.second; it++) {
		auto it2 = clstns.find(it->second);

		ixVCall = it2->second->cref.ixVCall;
		ixVJobmask = it2->second->cref.ixVJobmask;
		jrefTrig = it2->second->cref.jrefTrig;
		arg = it2->second->cref.arg;
		ixVSge = it2->second->cref.ixVSge;
		ixVJactype = it2->second->ixVJactype;

		delete it2->second;
		clstns.erase(it2);

		mon.eventRemoveClstn(jref, Clstn::VecVTarget::getSref(ixVTarget), VecBrlyVCall::getSref(ixVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJobmask::getSref(ixVJactype));
	};
	cref2sClstns.erase(rng.first, rng.second);

	rwmClstns.wunlock("XchgBrlycmbd", "removeClstnsByJref", "jref=" + to_string(jref));
};

void XchgBrlycmbd::findJrefsByCall(
			Call* call
			, vector<ubigint>& jrefTrigs
			, vector<ubigint>& jrefs
			, vector<uint>& icsVTarget
			, vector<uint>& icsVJactype
		) {
	Clstn* clstn = NULL;

	set<ubigint> jrefsClissrv;

	ubigint jrefTrig;
	bool match;

	rwmJobs.rlock("XchgBrlycmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
	rwmClstns.rlock("XchgBrlycmbd", "findJrefsByCall", "jref=" + to_string(call->jref));

	jrefsClissrv = getCsjobClisByJref(call->jref);
	jrefsClissrv.insert(call->jref);

	auto rng = clstns.equal_range(clstnref_t(call->ixVCall, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		clstn = it->second;

		jrefTrig = call->jref;

		if (clstn->cref.ixVTarget == Clstn::VecVTarget::JOB) {
			match = true;

			if (clstn->cref.arg.mask & Arg::IX) if (clstn->cref.arg.ix != call->argInv.ix) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::REF) if (clstn->cref.arg.ref != call->argInv.ref) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::SREF) if (clstn->cref.arg.sref != call->argInv.sref) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::INTVAL) if (clstn->cref.arg.intval != call->argInv.intval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::DBLVAL) if (clstn->cref.arg.dblval != call->argInv.dblval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::BOOLVAL) if (clstn->cref.arg.boolval != call->argInv.boolval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::TXTVAL) if (clstn->cref.arg.txtval != call->argInv.txtval) match = false;

			if (match) if (clstn->cref.ixVSge != 0) if (clstn->cref.ixVSge != jobinfos[clstn->cref.jref]->ixVSge) match = false;

			if (match) {
				match = false;

				if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::ALL) {
					// don't care about jrefsClissrv
					match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::IMM) {
					for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
						// check if trigger job is immediate sub-job to listener job
						if (clstn->cref.jref == jobinfos[*it]->jrefSup) {
							jrefTrig = *it;
							match = true;
							break;
						};
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SELF) {
					// check if trigger job is equivalent to listener job
					if (clstn->cref.jref == call->jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
					for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
						// require specific jref
						if (clstn->cref.jrefTrig == (*it)) {
							jrefTrig = *it;
							match = true;
							break;
						};
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::TREE) {
					if (clstn->cref.jref == call->jref) match = true;
					else {
						for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
							// check if trigger job is down the tree from listener job
							if (getJobSup(clstn->cref.jref, *it)) {
								jrefTrig = *it;
								match = true;
								break;
							};
						};
					};
				};
			};

			if (match) {
				jrefTrigs.push_back(jrefTrig);
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(clstn->ixVJactype);
			};

		} else if (clstn->cref.ixVTarget == Clstn::VecVTarget::STMGR) {
			jrefTrigs.push_back(jrefTrig);
			jrefs.push_back(clstn->cref.jref);
			icsVTarget.push_back(clstn->cref.ixVTarget);
			icsVJactype.push_back(0);

		} else {
			// targets DDSPUB and UASRV
			match = true;

			if (clstn->cref.arg.mask & Arg::SREF) if (clstn->cref.arg.sref != call->argInv.sref) match = false;

			if (match) if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
				match = false;

				for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
					// require specific jref
					if (clstn->cref.jrefTrig == (*it)) {
						jrefTrig = *it;
						match = true;
						break;
					};
				};
			};

			if (match) {
				jrefTrigs.push_back(jrefTrig);
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(0);
			};
		};
	};

	rwmClstns.runlock("XchgBrlycmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
	rwmJobs.runlock("XchgBrlycmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
};

void XchgBrlycmbd::triggerCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
	vector<ubigint> jrefTrigs;
	vector<ubigint> jrefs;
	vector<uint> icsVTarget;
	vector<uint> icsVJactype;

	uint ixVTarget;
	ubigint jref;
	uint ixVJactype;

	JobBrly* job = NULL;

	StmgrBrly* stmgr = NULL;

	ubigint eref;

	Arg argRet_old;

	eref = mon.eventTriggerCall(call->jref, VecBrlyVCall::getSref(call->ixVCall), call->argInv);

	findJrefsByCall(call, jrefTrigs, jrefs, icsVTarget, icsVJactype);

	for (unsigned int i = 0; i < jrefs.size(); i++) {
		call->jref = jrefTrigs[i];
		jref = jrefs[i];
		ixVTarget = icsVTarget[i];
		ixVJactype = icsVJactype[i];

		if (ixVTarget == Clstn::VecVTarget::JOB) {
			job = getJobByJref(jref);
			if (job) {
				if (ixVJactype != Clstn::VecVJactype::WEAK) {
					if (ixVJactype == Clstn::VecVJactype::LOCK) {
						job->lockAccess("XchgBrlycmbd", "triggerCall");

					} else if (ixVJactype == Clstn::VecVJactype::TRY) {
						if (!job->trylockAccess("XchgBrlycmbd", "triggerCall")) continue;
					};
				};

				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				job->handleCall(dbsbrly, call);

				if (call->argRet != argRet_old) mon.eventRetCall(eref, jref, call->argRet);
			};

			if (ixVJactype != Clstn::VecVJactype::WEAK) {
				job = getJobByJref(jref);
				if (job) job->unlockAccess("XchgBrlycmbd", "triggerCall");
			};

		} else if (ixVTarget == Clstn::VecVTarget::STMGR) {
			stmgr = getStmgrByJref(jref);

			if (stmgr) {
				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				stmgr->handleCall(dbsbrly, call);

				if (!(call->argRet == argRet_old)) mon.eventRetCall(eref, jref, call->argRet);

				stmgr->unlockAccess("XchgBrlycmbd", "triggerCall");
			};

		};

		if (call->abort) break;
	};

	mon.eventFinalizeCall(eref);
};

bool XchgBrlycmbd::triggerArgToArgCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const Arg& argInv
			, Arg& argRet
		) {
	Call* call;
	ubigint retval;

	call = new Call(ixBrlyVCall, jref, argInv);
	triggerCall(dbsbrly, call);

	argRet = call->argRet;
	retval = call->abort;

	delete call;
	return retval;
};

bool XchgBrlycmbd::triggerCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
		) {
	Arg argInv;
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerIxCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerRefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const ubigint refInv
		) {
	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerIntvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const int intvalInv
		) {
	Arg argInv(0, 0, {}, "", intvalInv, 0.0, false, "", Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerBoolvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const bool boolvalInv
		) {
	Arg argInv(0, 0, {}, "", 0, 0.0, boolvalInv, "", Arg::BOOLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerIxRefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
		) {
	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerIxSrefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
		) {
	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerIxSrefToIxCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;
	
	return retval;
};

bool XchgBrlycmbd::triggerIxIntvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const int intvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", intvalInv, 0.0, false, "", Arg::IX + Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerIxDblvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const double dblvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, dblvalInv, false, "", Arg::IX + Arg::DBLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerIxTxtvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const string& txtvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, txtvalInv, Arg::IX + Arg::TXTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerSrefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const string& srefInv
		) {
	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet));
};

bool XchgBrlycmbd::triggerToBoolvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv;
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgBrlycmbd::triggerIxToBoolvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgBrlycmbd::triggerRefToSrefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const ubigint refInv
			, string& srefRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) srefRet = argRet.sref;

	return(retval);
};

bool XchgBrlycmbd::triggerRefToBoolvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgBrlycmbd::triggerIxRefToIxCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgBrlycmbd::triggerIxRefToRefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgBrlycmbd::triggerIxRefSrefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgBrlycmbd::triggerIxRefSrefIntvalCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgBrlycmbd::triggerIxRefSrefIntvalToRefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgBrlycmbd::triggerRefToIxCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgBrlycmbd::triggerSrefToRefCall(
			DbsBrly* dbsbrly
			, const uint ixBrlyVCall
			, const ubigint jref
			, const string& srefInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsbrly, ixBrlyVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

DcolBrly* XchgBrlycmbd::addDcol(
			const ubigint jref
		) {
	JobBrly* job = NULL;

	DcolBrly* dcol = NULL;

	// create new dcol and append to dcol list
	rwmJobs.rlock("XchgBrlycmbd", "addDcol", "jref=" + to_string(jref));

	job = getJobByJref(jref);

	if (job) {
		dcol = getDcolByJref(jref);

		if (!dcol) {
			rwmDcols.wlock("XchgBrlycmbd", "addDcol", "jref=" + to_string(jref));

			dcol = new DcolBrly(jref, job->ixBrlyVLocale);
			dcols[jref] = dcol;

			dcol->lockAccess("XchgBrlycmbd", "addDcol");

			rwmDcols.wunlock("XchgBrlycmbd", "addDcol", "jref=" + to_string(jref));

			mon.eventAddDcol(jref);
		};
	};

	rwmJobs.runlock("XchgBrlycmbd", "addDcol", "jref=" + to_string(jref));

	// make dcol the session's active notify dcol
	triggerIxRefCall(NULL, VecBrlyVCall::CALLBRLYREFPRESET, jref, VecBrlyVPreset::PREBRLYJREFNOTIFY, jref);

	return(dcol);
};

DcolBrly* XchgBrlycmbd::getDcolByJref(
			ubigint jref
			, const bool tree
		) {
	Jobinfo* jobinfo = NULL;

	DcolBrly* dcol = NULL;

	rwmJobs.rlock("XchgBrlycmbd", "getDcolByJref", "jref=" + to_string(jref));
	rwmDcols.rlock("XchgBrlycmbd", "getDcolByJref", "jref=" + to_string(jref));

	jobinfo = getJobinfoByJref(jref);

	while (jobinfo != NULL) {
		auto it = dcols.find(jref);

		if (it != dcols.end()) {
			dcol = it->second;
			dcol->lockAccess("XchgBrlycmbd", "getDcolByJref");

			break;
		};

		if (!tree) break;

		jref = jobinfo->jrefSup;
		jobinfo = getJobinfoByJref(jref);
	};

	rwmDcols.runlock("XchgBrlycmbd", "getDcolByJref", "jref=" + to_string(jref));
	rwmJobs.runlock("XchgBrlycmbd", "getDcolByJref", "jref=" + to_string(jref));

	return(dcol);
};

void XchgBrlycmbd::removeDcolByJref(
			const ubigint jref
		) {
	rwmDcols.wlock("XchgBrlycmbd", "removeDcolByJref", "jref=" + to_string(jref));

	auto it = dcols.find(jref);
	if (it != dcols.end()) {
		delete it->second;
		dcols.erase(it);

		mon.eventRemoveDcol(jref);
	};

	rwmDcols.wunlock("XchgBrlycmbd", "removeDcolByJref", "jref=" + to_string(jref));
};

void XchgBrlycmbd::removeDcolsByJref(
			const ubigint jref
		) {
	Jobinfo* jobinfo = NULL;

	vector<ubigint> jrefs;

	rwmJobs.rlock("XchgBrlycmbd", "removeDcolsByJref", "jref=" + to_string(jref));
	rwmDcols.wlock("XchgBrlycmbd", "removeDcolsByJref", "jref=" + to_string(jref));

	jrefs.push_back(jref);

	// sub-tree without recursion
	for (unsigned int i = 0; i < jrefs.size(); i++) {
		jobinfo = getJobinfoByJref(jrefs[i]);

		if (jobinfo) for (auto it = jobinfo->jrefsSub.begin(); it != jobinfo->jrefsSub.end(); it++) jrefs.push_back(*it);
	};

	for (unsigned int i = 0; i < jrefs.size(); i++) {
		auto it = dcols.find(jrefs[i]);
		if (it != dcols.end()) {
			delete it->second;
			dcols.erase(it);

			mon.eventRemoveDcol(jrefs[i]);
		};
	};

	rwmDcols.wunlock("XchgBrlycmbd", "removeDcolsByJref", "jref=" + to_string(jref));
	rwmJobs.runlock("XchgBrlycmbd", "removeDcolsByJref", "jref=" + to_string(jref));
};

void XchgBrlycmbd::submitDpch(
			DpchEngBrly* dpcheng
		) {
	DcolBrly* dcol = NULL;

	Cond* cReady_backup;

	DpchEngBrly* dpchtest;

	// find dcol in charge
	dcol = getDcolByJref(dpcheng->jref);

	if (dcol) {
		mon.eventSubmitDpch(dpcheng->jref, VecBrlyVDpch::getSref(dpcheng->ixBrlyVDpch), dpcheng->getSrefsMask(), "");

		if (dcol->req != NULL) {
			// a request is waiting
			delete dcol->req->dpcheng;
			dcol->req->dpcheng = dpcheng;

			cReady_backup = &(dcol->req->cReady);

			dcol->req = NULL;
			//cout << "XchgBrlycmbd::submitDpch() waiting request for ixBrlyVDpch = " << dpcheng->ixBrlyVDpch << ", jref = " << dpcheng->jref << endl;

			cReady_backup->signal("XchgBrlycmbd", "submitDpch", "jref=" + to_string(dcol->jref));

			dcol->unlockAccess("XchgBrlycmbd", "submitDpch");

		} else {
			// merge with similar dispatch if available
			for (auto it = dcol->dpchs.begin(); it != dcol->dpchs.end();) {
				dpchtest = *it;

				if ((dpchtest->ixBrlyVDpch == dpcheng->ixBrlyVDpch) && (dpchtest->jref == dpcheng->jref)) {
					dpchtest->merge(dpcheng);
					//cout << "XchgBrlycmbd::submitDpch() merge for ixBrlyVDpch = " << dpcheng->ixBrlyVDpch << ", jref = " << dpcheng->jref << endl;

					delete dpcheng;
					dpcheng = NULL;

					break;

				} else it++;
			};

			// append to list of dispatches
			if (dpcheng) {
				dcol->dpchs.push_back(dpcheng);
				//cout << "XchgBrlycmbd::submitDpch() append for ixBrlyVDpch = " << dpcheng->ixBrlyVDpch << ", jref = " << dpcheng->jref << endl;
			};

			dcol->unlockAccess("XchgBrlycmbd", "submitDpch");
		};

	} else {
		delete dpcheng;
	};
};

DpchEngBrly* XchgBrlycmbd::pullFirstDpch(
			DcolBrly* dcol
		) {
	DpchEngBrly* dpcheng = NULL;

	// get first element from list ; assume access is locked
	if (!dcol->dpchs.empty()) {
		dpcheng = *(dcol->dpchs.begin());
		dcol->dpchs.pop_front();
	};

	return dpcheng;
};

ubigint XchgBrlycmbd::addJob(
			DbsBrly* dbsbrly
			, JobBrly* job
			, const ubigint jrefSup
		) {
	CsjobBrly* csjob = NULL;
	Csjobinfo* csjobinfo = NULL;

	bool csjobNotJob = getCsjobNotJob(job->ixBrlyVJob);
	bool srvNotCli = false;

	// get new jref and append to job list
	rwmJobs.wlock("XchgBrlycmbd", "addJob", "jrefSup=" + to_string(jrefSup));

	job->jref = jrefseq.getNewRef();
	jobs[job->jref] = job;

	if (jobs.size() == 1) {
		// root job
		jrefRoot = job->jref;
		jrefCmd = job->jref;
	};

	ixBrlyVJobs[job->jref] = job->ixBrlyVJob;
	jobinfos[job->jref] = new Jobinfo(jrefSup);

	if (jrefSup != 0) jobinfos[jrefSup]->jrefsSub.insert(job->jref);

	if (csjobNotJob) {
		rwmCsjobinfos.wlock("XchgBrlycmbd", "addJob", "jref=" + to_string(job->jref));

		csjob = (CsjobBrly*) job;
		csjobinfo = csjobinfos[job->ixBrlyVJob];

		if (jrefSup == jrefRoot) {
			csjob->srvNotCli = true;
			srvNotCli = true;
			
			csjobinfo->jrefSrv = job->jref;
			for (auto it = csjobinfo->jrefsCli.begin(); it != csjobinfo->jrefsCli.end(); it++) {
				jobs[*it]->ixVSge = job->ixVSge;
				((CsjobBrly*) (jobs[*it]))->srv = csjob;
			};

		} else {
			csjob->srvNotCli = false;
			
			if (csjobinfo->jrefSrv != 0) {
				job->ixVSge = jobs[csjobinfo->jrefSrv]->ixVSge;
				csjob->srv = (CsjobBrly*) jobs[csjobinfo->jrefSrv];
			};
			csjobinfo->jrefsCli.insert(job->jref);
		};

		rwmCsjobinfos.wunlock("XchgBrlycmbd", "addJob", "jref=" + to_string(job->jref));
	};

	rwmJobs.wunlock("XchgBrlycmbd", "addJob", "jref=" + to_string(job->jref));

	mon.eventAddJob(jrefSup, VecBrlyVJob::getSref(job->ixBrlyVJob), job->jref, csjobNotJob, srvNotCli);

	return(job->jref);
};

JobBrly* XchgBrlycmbd::getJobByJref(
			const ubigint jref
		) {
	JobBrly* job = NULL;

	rwmJobs.rlock("XchgBrlycmbd", "getJobByJref", "jref=" + to_string(jref));

	auto it = jobs.find(jref);
	if (it != jobs.end()) job = it->second;

	rwmJobs.runlock("XchgBrlycmbd", "getJobByJref", "jref=" + to_string(jref));

	return job;
};

Jobinfo* XchgBrlycmbd::getJobinfoByJref(
			const ubigint jref
		) {
	Jobinfo* jobinfo = NULL;

	rwmJobs.rlock("XchgBrlycmbd", "getJobinfoByJref", "jref=" + to_string(jref));

	auto it = jobinfos.find(jref);
	if (it != jobinfos.end()) jobinfo = it->second;

	rwmJobs.runlock("XchgBrlycmbd", "getJobinfoByJref", "jref=" + to_string(jref));

	return jobinfo;
};

void XchgBrlycmbd::removeJobByJref(
			const ubigint jref
		) {
	JobBrly* job = NULL;
	Jobinfo* jobinfo = NULL;

	CsjobBrly* csjob = NULL;
	Csjobinfo* csjobinfo = NULL;

	bool csjobNotJob;

	rwmJobs.rlock("XchgBrlycmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

	job = getJobByJref(jref);

	if (job) {
 		csjobNotJob = getCsjobNotJob(job->ixBrlyVJob);

		job->invalidateWakeups();

		removePresetsByJref(jref);
		removeStmgrByJref(jref);
		removeClstnsByJref(jref);
		removeDcolByJref(jref);

		if (csjobNotJob) {
			rwmCsjobinfos.rlock("XchgBrlycmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

			csjob = (CsjobBrly*) job;
			csjobinfo = csjobinfos[job->ixBrlyVJob];

			removeCsjobClaim(NULL, csjob);

			rwmCsjobinfos.runlock("XchgBrlycmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

			rwmCsjobinfos.wlock("XchgBrlycmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

			if (csjob->srvNotCli) {
				csjobinfo->jrefSrv = 0;
				for (auto it = csjobinfo->jrefsCli.begin(); it != csjobinfo->jrefsCli.end(); it++) ((CsjobBrly*) (jobs[*it]))->srv = NULL;

			} else csjobinfo->jrefsCli.erase(jref);

			rwmCsjobinfos.wunlock("XchgBrlycmbd", "removeJobByJref[2]", "jref=" + to_string(jref));
		};

		jobinfo = jobinfos[jref];

		rwmJobs.runlock("XchgBrlycmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

		rwmJobs.wlock("XchgBrlycmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

		if (jobinfo->jrefSup != 0) jobinfos[jobinfo->jrefSup]->jrefsSub.erase(jref);

		rwmJobs.wunlock("XchgBrlycmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

		while (jobinfo->jrefsSub.size() > 0) delete jobs[*(jobinfo->jrefsSub.begin())];

		rwmJobs.wlock("XchgBrlycmbd", "removeJobByJref[3]", "jref=" + to_string(jref));

		// remove job from list only here otherwise sub-job delete will loop forever
		jobs.erase(jref);

		delete jobinfo;
		jobinfos.erase(jref);

		ixBrlyVJobs.erase(jref);

		if (jobs.empty()) {
			// root job
			jrefRoot = 0;
			jrefCmd = 0;
		};

		rwmJobs.wunlock("XchgBrlycmbd", "removeJobByJref[3]", "jref=" + to_string(jref));

		mon.eventRemoveJob(jref);

	} else rwmJobs.wunlock("XchgBrlycmbd", "removeJobByJref[4]", "jref=" + to_string(jref));
};

bool XchgBrlycmbd::getJobSup(
			const ubigint jrefSup
			, ubigint jref
		) {
	bool retval = false;

	Jobinfo* jobinfo = NULL;

	jobinfo = getJobinfoByJref(jref);

	while (jobinfo) {
		if (jobinfo->jrefSup == jrefSup) {
			retval = true;
			break;
		};

		jref = jobinfo->jrefSup;
		jobinfo = getJobinfoByJref(jref);
	};

	return retval;
};

void XchgBrlycmbd::setJobStage(
			DbsBrly* dbsbrly
			, JobBrly* job
			, const uint ixVSge
		) {
	set<ubigint> jrefsCli;

	bool csjobNotJob = getCsjobNotJob(job->ixBrlyVJob);

	rwmJobs.rlock("XchgBrlycmbd", "setJobStage", "jref=" + to_string(job->jref));
	if (csjobNotJob) rwmCsjobinfos.rlock("XchgBrlycmbd", "setJobStage", "jref=" + to_string(job->jref));

	jobinfos[job->jref]->ixVSge = ixVSge;
	job->ixVSge = ixVSge;
	
	if (csjobNotJob) {
		jrefsCli = getCsjobClisByJref(job->jref);
		
		for (auto it = jrefsCli.begin(); it != jrefsCli.end(); it++) {
			jobinfos[*it]->ixVSge = ixVSge;
			jobs[*it]->ixVSge = ixVSge;
		};
	};

	if (csjobNotJob) rwmCsjobinfos.runlock("XchgBrlycmbd", "setJobStage", "jref=" + to_string(job->jref));
	rwmJobs.runlock("XchgBrlycmbd", "setJobStage", "jref=" + to_string(job->jref));

	triggerIxCall(dbsbrly, VecBrlyVCall::CALLBRLYSGECHG, job->jref, ixVSge);
};

void XchgBrlycmbd::addCsjobClaim(
			DbsBrly* dbsbrly
			, CsjobBrly* csjob
			, Claim* claim
		) {
	Csjobinfo* csjobinfo = NULL;;

	bool mod;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgBrlycmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixBrlyVJob];

		rwmCsjobinfos.runlock("XchgBrlycmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->lockAccess("XchgBrlycmbd", "addCsjobClaim");

		csjobinfo->mClaims.wlock("XchgBrlycmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		if (it != csjobinfo->claims.end()) delete it->second;

		csjobinfo->claims[csjob->jref] = claim;

		mod = csjob->srv->handleClaim(dbsbrly, csjobinfo->claims, csjob->jref);

		csjobinfo->mClaims.wunlock("XchgBrlycmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->unlockAccess("XchgBrlycmbd", "addCsjobClaim");

		if (mod) triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYCLAIMCHG, csjob->jref);
	};
};

bool XchgBrlycmbd::getCsjobClaim(
			CsjobBrly* csjob
			, bool& takenNotAvailable
			, bool& fulfilled
			, bool& run
		) {
	bool retval = false;

	Csjobinfo* csjobinfo = NULL;;

	takenNotAvailable = false;
	fulfilled = false;
	run = false;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgBrlycmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixBrlyVJob];

		csjobinfo->mClaims.rlock("XchgBrlycmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		retval = (it != csjobinfo->claims.end());

		if (retval) {
			takenNotAvailable = it->second->takenNotAvailable;
			fulfilled = it->second->fulfilled;
			run = it->second->run;
		};

		csjobinfo->mClaims.runlock("XchgBrlycmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		rwmCsjobinfos.runlock("XchgBrlycmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));
	};

	return retval;
};

bool XchgBrlycmbd::getCsjobClaim(
			CsjobBrly* csjob
			, bool& takenNotAvailable
			, bool& fulfilled
		) {
	bool run;

	return getCsjobClaim(csjob, takenNotAvailable, fulfilled, run);
};

void XchgBrlycmbd::clearCsjobRun(
			DbsBrly* dbsbrly
			, const uint ixBrlyVJob
		) {
	Csjobinfo* csjobinfo = NULL;
	Claim* claim = NULL;

	bool mod = false;

	rwmCsjobinfos.rlock("XchgBrlycmbd", "clearCsjobRun", "srefIxBrlyVJob=" + VecBrlyVJob::getSref(ixBrlyVJob));

	auto it = csjobinfos.find(ixBrlyVJob);
	if (it != csjobinfos.end()) csjobinfo = it->second;

	rwmCsjobinfos.runlock("XchgBrlycmbd", "clearCsjobRun", "srefIxBrlyVJob=" + VecBrlyVJob::getSref(ixBrlyVJob));

	if (csjobinfo) {
		csjobinfo->mClaims.wlock("XchgBrlycmbd", "clearCsjobRun", "srefIxBrlyVJob=" + VecBrlyVJob::getSref(ixBrlyVJob));

		for (auto it2 = csjobinfo->claims.begin(); it2 != csjobinfo->claims.end(); it2++) {
			claim = it2->second;

			if (claim->run) {
				claim->run = false;
				mod = true;
			};
		};

		csjobinfo->mClaims.wunlock("XchgBrlycmbd", "clearCsjobRun", "srefIxBrlyVJob=" + VecBrlyVJob::getSref(ixBrlyVJob));

		if (mod) triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYCLAIMCHG, csjobinfo->jrefSrv);
	};
};

void XchgBrlycmbd::removeCsjobClaim(
			DbsBrly* dbsbrly
			, CsjobBrly* csjob
		) {
	Csjobinfo* csjobinfo = NULL;;

	bool mod = false;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgBrlycmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixBrlyVJob];

		rwmCsjobinfos.runlock("XchgBrlycmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->lockAccess("XchgBrlycmbd", "removeCsjobClaim");

		csjobinfo->mClaims.wlock("XchgBrlycmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		if (it != csjobinfo->claims.end()) {
			delete it->second;
			csjobinfo->claims.erase(it);

			mod = csjob->srv->handleClaim(dbsbrly, csjobinfo->claims, 0);
		};

		csjobinfo->mClaims.wunlock("XchgBrlycmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->unlockAccess("XchgBrlycmbd", "removeCsjobClaim");

		if (mod) triggerCall(dbsbrly, VecBrlyVCall::CALLBRLYCLAIMCHG, csjobinfo->jrefSrv);
	};
};

bool XchgBrlycmbd::getCsjobNotJob(
			const uint ixBrlyVJob
		) {
	bool retval;

	rwmCsjobinfos.rlock("XchgBrlycmbd", "getCsjobNotJob", "srefIxBrlyVJob=" + VecBrlyVJob::getSref(ixBrlyVJob));

	retval = (csjobinfos.find(ixBrlyVJob) != csjobinfos.end());

	rwmCsjobinfos.runlock("XchgBrlycmbd", "getCsjobNotJob", "srefIxBrlyVJob=" + VecBrlyVJob::getSref(ixBrlyVJob));

	return retval;
};

set<ubigint> XchgBrlycmbd::getCsjobClisByJref(
			const ubigint jref
		) {
	set<ubigint> retval;

	rwmCsjobinfos.rlock("XchgBrlycmbd", "getCsjobClis", "jref=" + to_string(jref));

	auto it = csjobinfos.find(ixBrlyVJobs[jref]);
	
	if (it != csjobinfos.end()) retval = it->second->jrefsCli;

	rwmCsjobinfos.runlock("XchgBrlycmbd", "getCsjobClis", "jref=" + to_string(jref));

	return retval;
};

ubigint XchgBrlycmbd::addWakeup(
			const ubigint jref
			, const string sref
			, const uint64_t deltat
			, const bool weak
		) {
	int res;

	ubigint wref;

	pthread_t timer;

	wref = wrefseq.getNewRef();

	if (deltat == 0) {
		// immediate callback: generate request to be treated by job processor
		ReqBrly* req = new ReqBrly(ReqBrly::VecVBasetype::TIMER);
		req->jref = jref;
		req->wref = wref;
		req->sref = sref;
		req->weak = false;

		addReq(req);

	} else {
		// delayed callback: generate dedicated wait thread
		WakeupBrly* wakeup = new WakeupBrly(this, wref, jref, sref, deltat, weak);

		for (unsigned int i = 0; i < 3; i++) {
			res = pthread_create(&timer, NULL, &runWakeup, (void*) wakeup);
			if ((res == 0) || (res != EAGAIN)) break;
		};
		if (res != 0) cout << "XchgBrlycmbd::addWakeup() error creating timer thread (" << res << ")" << endl;
		else {
			res = pthread_detach(timer);
			if (res != 0) cout << "XchgBrlycmbd::addWakeup() error detaching timer thread (" << res << ")" << endl;
		};
	};

	return(wref);
};

void* XchgBrlycmbd::runWakeup(
			void* arg
		) {
	WakeupBrly* wakeup = (WakeupBrly*) arg;

	// wait for time specified in microseconds
	timespec deltat;
	deltat.tv_sec = wakeup->deltat / 1000000;
	deltat.tv_nsec = 1000 * (wakeup->deltat%1000000);
#ifdef _WIN32
	usleep(wakeup->deltat);
#else
	nanosleep(&deltat, NULL);
#endif

	// generate request to be treated by job processor
	ReqBrly* req = new ReqBrly(ReqBrly::VecVBasetype::TIMER);
	req->jref = wakeup->jref;
	req->wref = wakeup->wref;
	req->sref = wakeup->sref;
	req->weak = wakeup->weak;

	wakeup->xchg->addReq(req);

	delete wakeup;

	return(NULL);
};

void XchgBrlycmbd::runExtcall(
			void* arg
		) {
	ExtcallBrly* extcall = (ExtcallBrly*) arg;

	// generate request to be treated by job processor
	ReqBrly* req = new ReqBrly(ReqBrly::VecVBasetype::EXTCALL);
	req->call = new Call(*(extcall->call));

	extcall->xchg->addReq(req);
};
