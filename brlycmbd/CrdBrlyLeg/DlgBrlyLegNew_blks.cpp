/**
	* \file DlgBrlyLegNew_blks.cpp
	* job handler for job DlgBrlyLegNew (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgBrlyLegNew::VecVDit
 ******************************************************************************/

uint DlgBrlyLegNew::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	if (s == "inc") return INC;

	return(0);
};

string DlgBrlyLegNew::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	if (ix == INC) return("Inc");

	return("");
};

string DlgBrlyLegNew::VecVDit::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == DET) return("Details");
		if (ix == INC) return("Incorporation");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == DET) return("Details");
		if (ix == INC) return("Einberechnung");
		return(getTitle(ix, 1));
	};

	return("");
};

void DlgBrlyLegNew::VecVDit::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DlgBrlyLegNew::VecVDo
 ******************************************************************************/

uint DlgBrlyLegNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgBrlyLegNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgBrlyLegNew::VecVDoDet
 ******************************************************************************/

uint DlgBrlyLegNew::VecVDoDet::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgBrlyLegNew::VecVDoDet::getSref(
			const uint ix
		) {
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgBrlyLegNew::VecVDoInc
 ******************************************************************************/

uint DlgBrlyLegNew::VecVDoInc::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgBrlyLegNew::VecVDoInc::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgBrlyLegNew::VecVSge
 ******************************************************************************/

uint DlgBrlyLegNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "credone") return CREDONE;
	if (s == "inco") return INCO;
	if (s == "done") return DONE;

	return(0);
};

string DlgBrlyLegNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == CREDONE) return("credone");
	if (ix == INCO) return("inco");
	if (ix == DONE) return("done");

	return("");
};

void DlgBrlyLegNew::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgBrlyLegNew::ContIac
 ******************************************************************************/

DlgBrlyLegNew::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgBrlyLegNew::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgBrlyLegNew"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDse")) {numFDse = me["numFDse"].asUInt(); add(NUMFDSE);};
	};

	return basefound;
};

bool DlgBrlyLegNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyLegNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyLegNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgBrlyLegNew::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyLegNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDse"] = numFDse;
};

void DlgBrlyLegNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyLegNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyLegNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyLegNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgBrlyLegNew::ContIac::diff(
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
 class DlgBrlyLegNew::ContIacDet
 ******************************************************************************/

DlgBrlyLegNew::ContIacDet::ContIacDet(
			const uint numFPupTyp
			, const string& TxfBgn
			, const string& TxfEnd
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->TxfBgn = TxfBgn;
	this->TxfEnd = TxfEnd;

	mask = {NUMFPUPTYP, TXFBGN, TXFEND};
};

bool DlgBrlyLegNew::ContIacDet::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgBrlyLegNewDet"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupTyp")) {numFPupTyp = me["numFPupTyp"].asUInt(); add(NUMFPUPTYP);};
		if (me.isMember("TxfBgn")) {TxfBgn = me["TxfBgn"].asString(); add(TXFBGN);};
		if (me.isMember("TxfEnd")) {TxfEnd = me["TxfEnd"].asString(); add(TXFEND);};
	};

	return basefound;
};

bool DlgBrlyLegNew::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyLegNewDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyLegNewDet";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfBgn", TxfBgn)) add(TXFBGN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEnd", TxfEnd)) add(TXFEND);
	};

	return basefound;
};

void DlgBrlyLegNew::ContIacDet::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyLegNewDet";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupTyp"] = numFPupTyp;
	me["TxfBgn"] = TxfBgn;
	me["TxfEnd"] = TxfEnd;
};

void DlgBrlyLegNew::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyLegNewDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyLegNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfBgn", TxfBgn);
		writeStringAttr(wr, itemtag, "sref", "TxfEnd", TxfEnd);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyLegNew::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfBgn == comp->TxfBgn) insert(items, TXFBGN);
	if (TxfEnd == comp->TxfEnd) insert(items, TXFEND);

	return(items);
};

set<uint> DlgBrlyLegNew::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, TXFBGN, TXFEND};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::ContInf
 ******************************************************************************/

DlgBrlyLegNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgBrlyLegNew::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyLegNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
};

void DlgBrlyLegNew::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyLegNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyLegNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyLegNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgBrlyLegNew::ContInf::diff(
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
 class DlgBrlyLegNew::ContInfInc
 ******************************************************************************/

DlgBrlyLegNew::ContInfInc::ContInfInc(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgBrlyLegNew::ContInfInc::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyLegNewInc";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtPrg"] = TxtPrg;
};

void DlgBrlyLegNew::ContInfInc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyLegNewInc";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyLegNewInc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyLegNew::ContInfInc::comm(
			const ContInfInc* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgBrlyLegNew::ContInfInc::diff(
			const ContInfInc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::StatApp
 ******************************************************************************/

void DlgBrlyLegNew::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgBrlyLegNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdone"] = initdone;
	me["shortMenu"] = shortMenu;
};

void DlgBrlyLegNew::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgBrlyLegNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgBrlyLegNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyLegNew::StatShr
 ******************************************************************************/

DlgBrlyLegNew::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgBrlyLegNew::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyLegNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButDneActive"] = ButDneActive;
};

void DlgBrlyLegNew::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyLegNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyLegNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyLegNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgBrlyLegNew::StatShr::diff(
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
 class DlgBrlyLegNew::StatShrDet
 ******************************************************************************/

DlgBrlyLegNew::StatShrDet::StatShrDet(
			const bool ButCreActive
		) :
			Block()
		{
	this->ButCreActive = ButCreActive;

	mask = {BUTCREACTIVE};
};

void DlgBrlyLegNew::StatShrDet::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyLegNewDet";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButCreActive"] = ButCreActive;
};

void DlgBrlyLegNew::StatShrDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyLegNewDet";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyLegNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyLegNew::StatShrDet::comm(
			const StatShrDet* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgBrlyLegNew::StatShrDet::diff(
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
 class DlgBrlyLegNew::StatShrInc
 ******************************************************************************/

DlgBrlyLegNew::StatShrInc::StatShrInc(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgBrlyLegNew::StatShrInc::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyLegNewInc";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButRunActive"] = ButRunActive;
	me["ButStoActive"] = ButStoActive;
};

void DlgBrlyLegNew::StatShrInc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyLegNewInc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyLegNewInc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyLegNew::StatShrInc::comm(
			const StatShrInc* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgBrlyLegNew::StatShrInc::diff(
			const StatShrInc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyLegNew::Tag
 ******************************************************************************/

void DlgBrlyLegNew::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyLegNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Create new leg";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Neue Strecke erstellen";
	};
	me["ButDne"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DONE, ixBrlyVLocale));
};

void DlgBrlyLegNew::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyLegNew";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyLegNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Create new leg");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Neue Strecke erstellen");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DONE, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyLegNew::TagDet
 ******************************************************************************/

void DlgBrlyLegNew::TagDet::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyLegNewDet";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["CptTyp"] = "Type";
		me["CptBgn"] = "Begin location";
		me["CptEnd"] = "End location";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["CptTyp"] = "Typ";
		me["CptBgn"] = "Beginn";
		me["CptEnd"] = "Ende";
	};
	me["ButCre"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CREATE, ixBrlyVLocale));
};

void DlgBrlyLegNew::TagDet::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyLegNewDet";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyLegNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "Type");
			writeStringAttr(wr, itemtag, "sref", "CptBgn", "Begin location");
			writeStringAttr(wr, itemtag, "sref", "CptEnd", "End location");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "Typ");
			writeStringAttr(wr, itemtag, "sref", "CptBgn", "Beginn");
			writeStringAttr(wr, itemtag, "sref", "CptEnd", "Ende");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CREATE, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyLegNew::TagInc
 ******************************************************************************/

void DlgBrlyLegNew::TagInc::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyLegNewInc";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
	};
	me["CptPrg"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::PROGRESS, ixBrlyVLocale));
	me["ButRun"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::RUN, ixBrlyVLocale));
	me["ButSto"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::STOP, ixBrlyVLocale));
};

void DlgBrlyLegNew::TagInc::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyLegNewInc";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyLegNewInc";

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
 class DlgBrlyLegNew::DpchAppData
 ******************************************************************************/

DlgBrlyLegNew::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYLEGNEWDATA)
		{
};

string DlgBrlyLegNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyLegNew::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgBrlyLegNewData"];}();

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

void DlgBrlyLegNew::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgBrlyLegNewData");
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
 class DlgBrlyLegNew::DpchAppDo
 ******************************************************************************/

DlgBrlyLegNew::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYLEGNEWDO)
		{
	ixVDo = 0;
	ixVDoDet = 0;
	ixVDoInc = 0;
};

string DlgBrlyLegNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDODET)) ss.push_back("ixVDoDet");
	if (has(IXVDOINC)) ss.push_back("ixVDoInc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyLegNew::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgBrlyLegNewDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
		if (me.isMember("srefIxVDoDet")) {ixVDoDet = VecVDoDet::getIx(me["srefIxVDoDet"].asString()); add(IXVDODET);};
		if (me.isMember("srefIxVDoInc")) {ixVDoInc = VecVDoInc::getIx(me["srefIxVDoInc"].asString()); add(IXVDOINC);};
	} else {
	};
};

void DlgBrlyLegNew::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoDet;
	string srefIxVDoInc;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgBrlyLegNewDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoDet", "", srefIxVDoDet)) {
			ixVDoDet = VecVDoDet::getIx(srefIxVDoDet);
			add(IXVDODET);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoInc", "", srefIxVDoInc)) {
			ixVDoInc = VecVDoInc::getIx(srefIxVDoInc);
			add(IXVDOINC);
		};
	} else {
	};
};

/******************************************************************************
 class DlgBrlyLegNew::DpchEngData
 ******************************************************************************/

DlgBrlyLegNew::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, ContInf* continf
			, ContInfInc* continfinc
			, Feed* feedFDetPupTyp
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrDet* statshrdet
			, StatShrInc* statshrinc
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGDLGBRLYLEGNEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACDET, CONTINF, CONTINFINC, FEEDFDETPUPTYP, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRDET, STATSHRINC, TAG, TAGDET, TAGINC};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFINC) && continfinc) this->continfinc = *continfinc;
	if (find(this->mask, FEEDFDETPUPTYP) && feedFDetPupTyp) this->feedFDetPupTyp = *feedFDetPupTyp;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRDET) && statshrdet) this->statshrdet = *statshrdet;
	if (find(this->mask, STATSHRINC) && statshrinc) this->statshrinc = *statshrinc;
};

string DlgBrlyLegNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFINC)) ss.push_back("continfinc");
	if (has(FEEDFDETPUPTYP)) ss.push_back("feedFDetPupTyp");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRDET)) ss.push_back("statshrdet");
	if (has(STATSHRINC)) ss.push_back("statshrinc");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGDET)) ss.push_back("tagdet");
	if (has(TAGINC)) ss.push_back("taginc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyLegNew::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACDET)) {contiacdet = src->contiacdet; add(CONTIACDET);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFINC)) {continfinc = src->continfinc; add(CONTINFINC);};
	if (src->has(FEEDFDETPUPTYP)) {feedFDetPupTyp = src->feedFDetPupTyp; add(FEEDFDETPUPTYP);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRDET)) {statshrdet = src->statshrdet; add(STATSHRDET);};
	if (src->has(STATSHRINC)) {statshrinc = src->statshrinc; add(STATSHRINC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGDET)) add(TAGDET);
	if (src->has(TAGINC)) add(TAGINC);
};

void DlgBrlyLegNew::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgBrlyLegNewData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTIACDET)) contiacdet.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(CONTINFINC)) continfinc.writeJSON(me);
	if (has(FEEDFDETPUPTYP)) feedFDetPupTyp.writeJSON(me);
	if (has(FEEDFDSE)) feedFDse.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STATSHRDET)) statshrdet.writeJSON(me);
	if (has(STATSHRINC)) statshrinc.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
	if (has(TAGDET)) TagDet::writeJSON(ixBrlyVLocale, me);
	if (has(TAGINC)) TagInc::writeJSON(ixBrlyVLocale, me);
};

void DlgBrlyLegNew::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgBrlyLegNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFINC)) continfinc.writeXML(wr);
		if (has(FEEDFDETPUPTYP)) feedFDetPupTyp.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRDET)) statshrdet.writeXML(wr);
		if (has(STATSHRINC)) statshrinc.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(TAGDET)) TagDet::writeXML(ixBrlyVLocale, wr);
		if (has(TAGINC)) TagInc::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
