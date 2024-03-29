/**
	* \file DlgBrlyConNew_blks.cpp
	* job handler for job DlgBrlyConNew (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgBrlyConNew::VecVDit
 ******************************************************************************/

uint DlgBrlyConNew::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	if (s == "cal") return CAL;

	return(0);
};

string DlgBrlyConNew::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	if (ix == CAL) return("Cal");

	return("");
};

string DlgBrlyConNew::VecVDit::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == DET) return("Details");
		if (ix == CAL) return("Calculation");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == DET) return("Details");
		if (ix == CAL) return("Berechnung");
		return(getTitle(ix, 1));
	};

	return("");
};

void DlgBrlyConNew::VecVDit::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DlgBrlyConNew::VecVDo
 ******************************************************************************/

uint DlgBrlyConNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgBrlyConNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgBrlyConNew::VecVDoCal
 ******************************************************************************/

uint DlgBrlyConNew::VecVDoCal::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgBrlyConNew::VecVDoCal::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgBrlyConNew::VecVDoDet
 ******************************************************************************/

uint DlgBrlyConNew::VecVDoDet::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgBrlyConNew::VecVDoDet::getSref(
			const uint ix
		) {
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgBrlyConNew::VecVSge
 ******************************************************************************/

uint DlgBrlyConNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "credone") return CREDONE;
	if (s == "calc1") return CALC1;
	if (s == "calc2") return CALC2;
	if (s == "calc3") return CALC3;
	if (s == "calc4") return CALC4;
	if (s == "done") return DONE;

	return(0);
};

string DlgBrlyConNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == CREDONE) return("credone");
	if (ix == CALC1) return("calc1");
	if (ix == CALC2) return("calc2");
	if (ix == CALC3) return("calc3");
	if (ix == CALC4) return("calc4");
	if (ix == DONE) return("done");

	return("");
};

void DlgBrlyConNew::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 8; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgBrlyConNew::ContIac
 ******************************************************************************/

DlgBrlyConNew::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgBrlyConNew::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgBrlyConNew"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDse")) {numFDse = me["numFDse"].asUInt(); add(NUMFDSE);};
	};

	return basefound;
};

bool DlgBrlyConNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyConNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyConNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgBrlyConNew::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyConNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDse"] = numFDse;
};

void DlgBrlyConNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyConNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyConNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyConNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgBrlyConNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDSE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyConNew::ContIacDet
 ******************************************************************************/

DlgBrlyConNew::ContIacDet::ContIacDet(
			const string& TxfFlt
			, const uint numFPupMdl
			, const uint numFPupTtb
			, const string& TxfEty
		) :
			Block()
		{
	this->TxfFlt = TxfFlt;
	this->numFPupMdl = numFPupMdl;
	this->numFPupTtb = numFPupTtb;
	this->TxfEty = TxfEty;

	mask = {TXFFLT, NUMFPUPMDL, NUMFPUPTTB, TXFETY};
};

bool DlgBrlyConNew::ContIacDet::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgBrlyConNewDet"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfFlt")) {TxfFlt = me["TxfFlt"].asString(); add(TXFFLT);};
		if (me.isMember("numFPupMdl")) {numFPupMdl = me["numFPupMdl"].asUInt(); add(NUMFPUPMDL);};
		if (me.isMember("numFPupTtb")) {numFPupTtb = me["numFPupTtb"].asUInt(); add(NUMFPUPTTB);};
		if (me.isMember("TxfEty")) {TxfEty = me["TxfEty"].asString(); add(TXFETY);};
	};

	return basefound;
};

bool DlgBrlyConNew::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyConNewDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyConNewDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFlt", TxfFlt)) add(TXFFLT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMdl", numFPupMdl)) add(NUMFPUPMDL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTtb", numFPupTtb)) add(NUMFPUPTTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEty", TxfEty)) add(TXFETY);
	};

	return basefound;
};

void DlgBrlyConNew::ContIacDet::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyConNewDet";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfFlt"] = TxfFlt;
	me["numFPupMdl"] = numFPupMdl;
	me["numFPupTtb"] = numFPupTtb;
	me["TxfEty"] = TxfEty;
};

void DlgBrlyConNew::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyConNewDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyConNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFlt", TxfFlt);
		writeUintAttr(wr, itemtag, "sref", "numFPupMdl", numFPupMdl);
		writeUintAttr(wr, itemtag, "sref", "numFPupTtb", numFPupTtb);
		writeStringAttr(wr, itemtag, "sref", "TxfEty", TxfEty);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyConNew::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (TxfFlt == comp->TxfFlt) insert(items, TXFFLT);
	if (numFPupMdl == comp->numFPupMdl) insert(items, NUMFPUPMDL);
	if (numFPupTtb == comp->numFPupTtb) insert(items, NUMFPUPTTB);
	if (TxfEty == comp->TxfEty) insert(items, TXFETY);

	return(items);
};

set<uint> DlgBrlyConNew::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFLT, NUMFPUPMDL, NUMFPUPTTB, TXFETY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyConNew::ContInf
 ******************************************************************************/

DlgBrlyConNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgBrlyConNew::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyConNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
};

void DlgBrlyConNew::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyConNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyConNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyConNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgBrlyConNew::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyConNew::ContInfCal
 ******************************************************************************/

DlgBrlyConNew::ContInfCal::ContInfCal(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgBrlyConNew::ContInfCal::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyConNewCal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtPrg"] = TxtPrg;
};

void DlgBrlyConNew::ContInfCal::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyConNewCal";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyConNewCal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyConNew::ContInfCal::comm(
			const ContInfCal* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgBrlyConNew::ContInfCal::diff(
			const ContInfCal* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyConNew::StatApp
 ******************************************************************************/

void DlgBrlyConNew::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgBrlyConNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdone"] = initdone;
	me["shortMenu"] = shortMenu;
};

void DlgBrlyConNew::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgBrlyConNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgBrlyConNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyConNew::StatShr
 ******************************************************************************/

DlgBrlyConNew::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgBrlyConNew::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyConNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButDneActive"] = ButDneActive;
};

void DlgBrlyConNew::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyConNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyConNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyConNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgBrlyConNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDNEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyConNew::StatShrCal
 ******************************************************************************/

DlgBrlyConNew::StatShrCal::StatShrCal(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgBrlyConNew::StatShrCal::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyConNewCal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButRunActive"] = ButRunActive;
	me["ButStoActive"] = ButStoActive;
};

void DlgBrlyConNew::StatShrCal::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyConNewCal";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyConNewCal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyConNew::StatShrCal::comm(
			const StatShrCal* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgBrlyConNew::StatShrCal::diff(
			const StatShrCal* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyConNew::StatShrDet
 ******************************************************************************/

DlgBrlyConNew::StatShrDet::StatShrDet(
			const bool ButCreActive
		) :
			Block()
		{
	this->ButCreActive = ButCreActive;

	mask = {BUTCREACTIVE};
};

void DlgBrlyConNew::StatShrDet::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyConNewDet";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButCreActive"] = ButCreActive;
};

void DlgBrlyConNew::StatShrDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyConNewDet";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyConNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyConNew::StatShrDet::comm(
			const StatShrDet* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgBrlyConNew::StatShrDet::diff(
			const StatShrDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyConNew::Tag
 ******************************************************************************/

void DlgBrlyConNew::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyConNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Create new connection";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Neue Verbindung erstellen";
	};
	me["ButDne"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DONE, ixBrlyVLocale));
};

void DlgBrlyConNew::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyConNew";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyConNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Create new connection");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Neue Verbindung erstellen");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DONE, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyConNew::TagCal
 ******************************************************************************/

void DlgBrlyConNew::TagCal::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyConNewCal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
	};
	me["CptPrg"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::PROGRESS, ixBrlyVLocale));
	me["ButRun"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::RUN, ixBrlyVLocale));
	me["ButSto"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::STOP, ixBrlyVLocale));
};

void DlgBrlyConNew::TagCal::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyConNewCal";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyConNewCal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::PROGRESS, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::RUN, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::STOP, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyConNew::TagDet
 ******************************************************************************/

void DlgBrlyConNew::TagDet::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyConNewDet";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["CptFlt"] = "Flight";
		me["CptMdl"] = "Model";
		me["CptTtb"] = "Timetable";
		me["CptEty"] = "Equipment types";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["CptFlt"] = "Flug";
		me["CptMdl"] = "Modell";
		me["CptTtb"] = "Flugplan";
		me["CptEty"] = "Ger\\u00e4ttypen";
	};
	me["ButCre"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CREATE, ixBrlyVLocale));
};

void DlgBrlyConNew::TagDet::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyConNewDet";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyConNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptFlt", "Flight");
			writeStringAttr(wr, itemtag, "sref", "CptMdl", "Model");
			writeStringAttr(wr, itemtag, "sref", "CptTtb", "Timetable");
			writeStringAttr(wr, itemtag, "sref", "CptEty", "Equipment types");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptFlt", "Flug");
			writeStringAttr(wr, itemtag, "sref", "CptMdl", "Modell");
			writeStringAttr(wr, itemtag, "sref", "CptTtb", "Flugplan");
			writeStringAttr(wr, itemtag, "sref", "CptEty", "Ger\\u00e4ttypen");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CREATE, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyConNew::DpchAppData
 ******************************************************************************/

DlgBrlyConNew::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYCONNEWDATA)
		{
};

string DlgBrlyConNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyConNew::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgBrlyConNewData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
		if (contiacdet.readJSON(me, true)) add(CONTIACDET);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
	};
};

void DlgBrlyConNew::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgBrlyConNewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
	};
};

/******************************************************************************
 class DlgBrlyConNew::DpchAppDo
 ******************************************************************************/

DlgBrlyConNew::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYCONNEWDO)
		{
	ixVDo = 0;
	ixVDoCal = 0;
	ixVDoDet = 0;
};

string DlgBrlyConNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOCAL)) ss.push_back("ixVDoCal");
	if (has(IXVDODET)) ss.push_back("ixVDoDet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyConNew::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgBrlyConNewDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
		if (me.isMember("srefIxVDoCal")) {ixVDoCal = VecVDoCal::getIx(me["srefIxVDoCal"].asString()); add(IXVDOCAL);};
		if (me.isMember("srefIxVDoDet")) {ixVDoDet = VecVDoDet::getIx(me["srefIxVDoDet"].asString()); add(IXVDODET);};
	} else {
	};
};

void DlgBrlyConNew::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoCal;
	string srefIxVDoDet;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgBrlyConNewDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoCal", "", srefIxVDoCal)) {
			ixVDoCal = VecVDoCal::getIx(srefIxVDoCal);
			add(IXVDOCAL);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoDet", "", srefIxVDoDet)) {
			ixVDoDet = VecVDoDet::getIx(srefIxVDoDet);
			add(IXVDODET);
		};
	} else {
	};
};

/******************************************************************************
 class DlgBrlyConNew::DpchEngData
 ******************************************************************************/

DlgBrlyConNew::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, ContInf* continf
			, ContInfCal* continfcal
			, Feed* feedFDetPupMdl
			, Feed* feedFDetPupTtb
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrCal* statshrcal
			, StatShrDet* statshrdet
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGDLGBRLYCONNEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACDET, CONTINF, CONTINFCAL, FEEDFDETPUPMDL, FEEDFDETPUPTTB, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRCAL, STATSHRDET, TAG, TAGCAL, TAGDET};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFCAL) && continfcal) this->continfcal = *continfcal;
	if (find(this->mask, FEEDFDETPUPMDL) && feedFDetPupMdl) this->feedFDetPupMdl = *feedFDetPupMdl;
	if (find(this->mask, FEEDFDETPUPTTB) && feedFDetPupTtb) this->feedFDetPupTtb = *feedFDetPupTtb;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRCAL) && statshrcal) this->statshrcal = *statshrcal;
	if (find(this->mask, STATSHRDET) && statshrdet) this->statshrdet = *statshrdet;
};

string DlgBrlyConNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFCAL)) ss.push_back("continfcal");
	if (has(FEEDFDETPUPMDL)) ss.push_back("feedFDetPupMdl");
	if (has(FEEDFDETPUPTTB)) ss.push_back("feedFDetPupTtb");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRCAL)) ss.push_back("statshrcal");
	if (has(STATSHRDET)) ss.push_back("statshrdet");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGCAL)) ss.push_back("tagcal");
	if (has(TAGDET)) ss.push_back("tagdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyConNew::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACDET)) {contiacdet = src->contiacdet; add(CONTIACDET);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFCAL)) {continfcal = src->continfcal; add(CONTINFCAL);};
	if (src->has(FEEDFDETPUPMDL)) {feedFDetPupMdl = src->feedFDetPupMdl; add(FEEDFDETPUPMDL);};
	if (src->has(FEEDFDETPUPTTB)) {feedFDetPupTtb = src->feedFDetPupTtb; add(FEEDFDETPUPTTB);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRCAL)) {statshrcal = src->statshrcal; add(STATSHRCAL);};
	if (src->has(STATSHRDET)) {statshrdet = src->statshrdet; add(STATSHRDET);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGCAL)) add(TAGCAL);
	if (src->has(TAGDET)) add(TAGDET);
};

void DlgBrlyConNew::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgBrlyConNewData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTIACDET)) contiacdet.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(CONTINFCAL)) continfcal.writeJSON(me);
	if (has(FEEDFDETPUPMDL)) feedFDetPupMdl.writeJSON(me);
	if (has(FEEDFDETPUPTTB)) feedFDetPupTtb.writeJSON(me);
	if (has(FEEDFDSE)) feedFDse.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STATSHRCAL)) statshrcal.writeJSON(me);
	if (has(STATSHRDET)) statshrdet.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
	if (has(TAGCAL)) TagCal::writeJSON(ixBrlyVLocale, me);
	if (has(TAGDET)) TagDet::writeJSON(ixBrlyVLocale, me);
};

void DlgBrlyConNew::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgBrlyConNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFCAL)) continfcal.writeXML(wr);
		if (has(FEEDFDETPUPMDL)) feedFDetPupMdl.writeXML(wr);
		if (has(FEEDFDETPUPTTB)) feedFDetPupTtb.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRCAL)) statshrcal.writeXML(wr);
		if (has(STATSHRDET)) statshrdet.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(TAGCAL)) TagCal::writeXML(ixBrlyVLocale, wr);
		if (has(TAGDET)) TagDet::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
