/**
	* \file Brlyopd.cpp
	* inter-thread exchange object for Brly operation daemon brlyopd (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "Brlyopd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchBrlydReg
 ******************************************************************************/

DpchBrlydReg::DpchBrlydReg() :
			DpchBrly(VecBrlyVDpch::DPCHBRLYDREG)
		{
};

bool DpchBrlydReg::all(
			const set<uint>& items
		) {
	if (!find(items, SCRNREF)) return false;

	return true;
};

void DpchBrlydReg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchBrlydReg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrNref", "", scrNref)) add(SCRNREF);
	};
};

/******************************************************************************
 namespace DpchBrlyopdAck
 ******************************************************************************/

void DpchBrlyopdAck::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchBrlyopdAck");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchBrlyopdReg
 ******************************************************************************/

void DpchBrlyopdReg::writeXML(
			xmlTextWriter* wr
			, const usmallint port
			, const uint ixBrlyVOpengtype
			, const usmallint opprcn
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchBrlyopdReg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeUsmallint(wr, "port", port);
		writeString(wr, "srefIxBrlyVOpengtype", VecBrlyVOpengtype::getSref(ixBrlyVOpengtype));
		writeUsmallint(wr, "opprcn", opprcn);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchBrlyopdUnreg
 ******************************************************************************/

void DpchBrlyopdUnreg::writeXML(
			xmlTextWriter* wr
			, const string& scrNref
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchBrlyopdUnreg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		writeString(wr, "scrNref", scrNref);
	xmlTextWriterEndElement(wr);
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
 class StgBrlyopd
 ******************************************************************************/

StgBrlyopd::StgBrlyopd(
			const string& engip
			, const usmallint engport
			, const usmallint engsrvportbase
			, const usmallint engsrvportofs
			, const usmallint opprcn
		) :
			Block()
		{
	this->engip = engip;
	this->engport = engport;
	this->engsrvportbase = engsrvportbase;
	this->engsrvportofs = engsrvportofs;
	this->opprcn = opprcn;
	mask = {ENGIP, ENGPORT, ENGSRVPORTBASE, ENGSRVPORTOFS, OPPRCN};
};

bool StgBrlyopd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgBrlyopd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemBrlyopd";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engip", engip)) add(ENGIP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engport", engport)) add(ENGPORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engsrvportbase", engsrvportbase)) add(ENGSRVPORTBASE);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engsrvportofs", engsrvportofs)) add(ENGSRVPORTOFS);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opprcn", opprcn)) add(OPPRCN);
	};

	return basefound;
};

void StgBrlyopd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgBrlyopd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemBrlyopd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engip", engip);
		writeUsmallintAttr(wr, itemtag, "sref", "engport", engport);
		writeUsmallintAttr(wr, itemtag, "sref", "engsrvportbase", engsrvportbase);
		writeUsmallintAttr(wr, itemtag, "sref", "engsrvportofs", engsrvportofs);
		writeUsmallintAttr(wr, itemtag, "sref", "opprcn", opprcn);
	xmlTextWriterEndElement(wr);
};

set<uint> StgBrlyopd::comm(
			const StgBrlyopd* comp
		) {
	set<uint> items;

	if (engip == comp->engip) insert(items, ENGIP);
	if (engport == comp->engport) insert(items, ENGPORT);
	if (engsrvportbase == comp->engsrvportbase) insert(items, ENGSRVPORTBASE);
	if (engsrvportofs == comp->engsrvportofs) insert(items, ENGSRVPORTOFS);
	if (opprcn == comp->opprcn) insert(items, OPPRCN);

	return(items);
};

set<uint> StgBrlyopd::diff(
			const StgBrlyopd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ENGIP, ENGPORT, ENGSRVPORTBASE, ENGSRVPORTOFS, OPPRCN};
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
 class ReqopBrly
 ******************************************************************************/

ReqopBrly::ReqopBrly(
			const uint ixVBasetype
			, const uint ixVState
		) :
			cReady("cReady", "ReqopBrly", "ReqopBrly")
		{
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;

	pdone = 0;

	pp = NULL;

	request = NULL;
	requestlen = 0;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;
};

ReqopBrly::~ReqopBrly() {
	if (pp) MHD_destroy_post_processor(pp);

	if (request) delete[] request;

	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	if (reply) delete[] reply;

	cReady.lockMutex("ReqopBrly", "~ReqopBrly");
	cReady.unlockMutex("ReqopBrly", "~ReqopBrly");
};

void ReqopBrly::setStateReply() {
	cReady.lockMutex("ReqopBrly", "setStateReply", "scrOref=" + dpchinv->scrOref);

	ixVState = VecVState::REPLY;

	pdone = 100;

	if (dpchret) {
		dpchret->scrOref = dpchinv->scrOref;
		dpchret->scrJref = dpchinv->scrJref;
		dpchret->pdone = pdone;
	};

	cReady.unlockMutex("ReqopBrly", "setStateReply", "scrOref=" + dpchinv->scrOref);

	cReady.signal("ReqopBrly", "setStateReply", "scrOref=" + dpchinv->scrOref);
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
		) {
	rwmAccess.rlock(srefObject, srefMember);
};

void ShrdatBrly::runlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	rwmAccess.runlock(srefObject, srefMember);
};

void ShrdatBrly::wlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	rwmAccess.wlock(srefObject, srefMember);
};

void ShrdatBrly::wunlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	rwmAccess.wunlock(srefObject, srefMember);
};

// IP ShrdatOpprc.subs --- INSERT

/******************************************************************************
 class XchgBrlyopd::ShrdatOpprc
 ******************************************************************************/

XchgBrlyopd::ShrdatOpprc::ShrdatOpprc() :
			ShrdatBrly("XchgBrly", "ShrdatOpprc")
		{
};

void XchgBrlyopd::ShrdatOpprc::init(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
		) {
	// IP ShrdatOpprc.init --- INSERT
};

void XchgBrlyopd::ShrdatOpprc::term(
			XchgBrly* xchg
		) {
	// IP ShrdatOpprc.term --- INSERT
};

/******************************************************************************
 class XchgBrlyopd
 ******************************************************************************/

XchgBrlyopd::XchgBrlyopd() :
			cStable("cStable", "XchgBrlyopd", "XchgBrlyopd")
			, mLogfile("mLogfile", "XchgBrlyopd", "XchgBrlyopd")
			, cTerm("cTerm", "XchgBrlyopd", "XchgBrlyopd")
			, cOpprcs("cOpprcs", "XchgBrlyopd", "XchgBrlyopd")
			, mReqs("mReqs", "XchgBrlyopd", "XchgBrlyopd")
		{
	// IP constructor.data --- INSERT
};

XchgBrlyopd::~XchgBrlyopd() {
	// empty out lists
	for (auto it = reqs.begin(); it != reqs.end(); it++) delete(*it);
	for (auto it = prcreqs.begin(); it != prcreqs.end(); it++) delete(it->second);
};

// IP cust --- INSERT

void XchgBrlyopd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	mLogfile.lock("XchgBrlyopd", "appendToLogfile");

	time(&rawtime);

	logfile.open(exedir + "/log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	mLogfile.unlock("XchgBrlyopd", "appendToLogfile");
};

void XchgBrlyopd::addReq(
			ReqopBrly* req
		) {
	mReqs.lock("XchgBrlyopd", "addReq");

	req->ixVState = ReqopBrly::VecVState::WAITPRC;
	reqs.push_back(req);

	mReqs.unlock("XchgBrlyopd", "addReq");

	cOpprcs.signal("XchgBrlyopd", "addReq");
};

ReqopBrly* XchgBrlyopd::pullFirstReq() {
	ReqopBrly* req;

	// get first element from list
	mReqs.lock("XchgBrlyopd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqopBrly::VecVState::PRC;
		reqs.pop_front();

		prcreqs[req->dpchinv->scrOref] = req;
	};

	mReqs.unlock("XchgBrlyopd", "pullFirstReq");

	return req;
};

ReqopBrly* XchgBrlyopd::getPrcreqByScrOref(
			const string& scrOref
		) {
	ReqopBrly* req = NULL;

	mReqs.lock("XchgBrlyopd", "getPrcreqByScrOref", "scrOref=" + scrOref);

	auto it = prcreqs.find(scrOref);

	if (it != prcreqs.end()) {
		req = it->second;
		req->cReady.lockMutex("XchgBrlyopd", "getPrcreqByScrOref", "scrOref=" + scrOref);
	};

	mReqs.unlock("XchgBrlyopd", "getPrcreqByScrOref", "scrOref=" + scrOref);

	return req;
};

void XchgBrlyopd::pullPrcreq(
			const string& scrOref
		) {
	mReqs.lock("XchgBrlyopd", "pullPrcreq", "scrOref=" + scrOref);

	auto it = prcreqs.find(scrOref);
	if (it != prcreqs.end()) prcreqs.erase(it);

	mReqs.unlock("XchgBrlyopd", "pullPrcreq", "scrOref=" + scrOref);
};

void XchgBrlyopd::setPdone(
			const string& scrOref
			, const utinyint pdone
		) {
	ReqopBrly* req = NULL;

	req = getPrcreqByScrOref(scrOref);

	if (req) {
		req->pdone = pdone;
		req->cReady.unlockMutex("XchgBrlyopd", "setPdone", "scrOref=" + scrOref);
	};
};
