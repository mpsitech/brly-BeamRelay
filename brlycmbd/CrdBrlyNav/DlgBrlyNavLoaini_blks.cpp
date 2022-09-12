/**
	* \file DlgBrlyNavLoaini_blks.cpp
	* job handler for job DlgBrlyNavLoaini (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgBrlyNavLoaini::VecVDit
 ******************************************************************************/

uint DlgBrlyNavLoaini::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ifi") return IFI;
	if (s == "imp") return IMP;
	if (s == "ppr") return PPR;
	if (s == "lfi") return LFI;

	return(0);
};

string DlgBrlyNavLoaini::VecVDit::getSref(
			const uint ix
		) {
	if (ix == IFI) return("Ifi");
	if (ix == IMP) return("Imp");
	if (ix == PPR) return("Ppr");
	if (ix == LFI) return("Lfi");

	return("");
};

string DlgBrlyNavLoaini::VecVDit::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == IFI) return("Initialization file");
		if (ix == IMP) return("Import");
		if (ix == PPR) return("Postprocessing");
		if (ix == LFI) return("Log file");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == IFI) return("Initialisierungsdatei");
		if (ix == IMP) return("Importieren");
		if (ix == PPR) return("Nachbearbeitung");
		if (ix == LFI) return("Protokoll");
		return(getTitle(ix, 1));
	};

	return("");
};

void DlgBrlyNavLoaini::VecVDit::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DlgBrlyNavLoaini::VecVDo
 ******************************************************************************/

uint DlgBrlyNavLoaini::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgBrlyNavLoaini::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgBrlyNavLoaini::VecVDoImp
 ******************************************************************************/

uint DlgBrlyNavLoaini::VecVDoImp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgBrlyNavLoaini::VecVDoImp::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgBrlyNavLoaini::VecVDoPpr
 ******************************************************************************/

uint DlgBrlyNavLoaini::VecVDoPpr::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgBrlyNavLoaini::VecVDoPpr::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgBrlyNavLoaini::VecVSge
 ******************************************************************************/

uint DlgBrlyNavLoaini::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "prsidle") return PRSIDLE;
	if (s == "parse") return PARSE;
	if (s == "alrbrlyper") return ALRBRLYPER;
	if (s == "prsdone") return PRSDONE;
	if (s == "impidle") return IMPIDLE;
	if (s == "import") return IMPORT;
	if (s == "impdone") return IMPDONE;
	if (s == "postprc") return POSTPRC;
	if (s == "done") return DONE;

	return(0);
};

string DlgBrlyNavLoaini::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == PRSIDLE) return("prsidle");
	if (ix == PARSE) return("parse");
	if (ix == ALRBRLYPER) return("alrbrlyper");
	if (ix == PRSDONE) return("prsdone");
	if (ix == IMPIDLE) return("impidle");
	if (ix == IMPORT) return("import");
	if (ix == IMPDONE) return("impdone");
	if (ix == POSTPRC) return("postprc");
	if (ix == DONE) return("done");

	return("");
};

void DlgBrlyNavLoaini::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 10; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgBrlyNavLoaini::ContIac
 ******************************************************************************/

DlgBrlyNavLoaini::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgBrlyNavLoaini::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgBrlyNavLoaini"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDse")) {numFDse = me["numFDse"].asUInt(); add(NUMFDSE);};
	};

	return basefound;
};

bool DlgBrlyNavLoaini::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyNavLoaini");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyNavLoaini";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgBrlyNavLoaini::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyNavLoaini";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDse"] = numFDse;
};

void DlgBrlyNavLoaini::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyNavLoaini";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyNavLoaini";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyNavLoaini::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgBrlyNavLoaini::ContIac::diff(
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
 class DlgBrlyNavLoaini::ContInf
 ******************************************************************************/

DlgBrlyNavLoaini::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgBrlyNavLoaini::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyNavLoaini";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
};

void DlgBrlyNavLoaini::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyNavLoaini";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyNavLoaini";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyNavLoaini::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgBrlyNavLoaini::ContInf::diff(
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
 class DlgBrlyNavLoaini::ContInfImp
 ******************************************************************************/

DlgBrlyNavLoaini::ContInfImp::ContInfImp(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgBrlyNavLoaini::ContInfImp::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyNavLoainiImp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtPrg"] = TxtPrg;
};

void DlgBrlyNavLoaini::ContInfImp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyNavLoainiImp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyNavLoainiImp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyNavLoaini::ContInfImp::comm(
			const ContInfImp* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgBrlyNavLoaini::ContInfImp::diff(
			const ContInfImp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyNavLoaini::ContInfLfi
 ******************************************************************************/

DlgBrlyNavLoaini::ContInfLfi::ContInfLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

void DlgBrlyNavLoaini::ContInfLfi::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyNavLoainiLfi";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["Dld"] = Dld;
};

void DlgBrlyNavLoaini::ContInfLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyNavLoainiLfi";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyNavLoainiLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyNavLoaini::ContInfLfi::comm(
			const ContInfLfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgBrlyNavLoaini::ContInfLfi::diff(
			const ContInfLfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyNavLoaini::ContInfPpr
 ******************************************************************************/

DlgBrlyNavLoaini::ContInfPpr::ContInfPpr(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgBrlyNavLoaini::ContInfPpr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyNavLoainiPpr";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtPrg"] = TxtPrg;
};

void DlgBrlyNavLoaini::ContInfPpr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyNavLoainiPpr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyNavLoainiPpr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyNavLoaini::ContInfPpr::comm(
			const ContInfPpr* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgBrlyNavLoaini::ContInfPpr::diff(
			const ContInfPpr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyNavLoaini::StatApp
 ******************************************************************************/

void DlgBrlyNavLoaini::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgBrlyNavLoaini";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdone"] = initdone;
	me["shortMenu"] = shortMenu;
};

void DlgBrlyNavLoaini::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgBrlyNavLoaini";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgBrlyNavLoaini";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyNavLoaini::StatShr
 ******************************************************************************/

DlgBrlyNavLoaini::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgBrlyNavLoaini::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyNavLoaini";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButDneActive"] = ButDneActive;
};

void DlgBrlyNavLoaini::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyNavLoaini";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyNavLoaini";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyNavLoaini::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgBrlyNavLoaini::StatShr::diff(
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
 class DlgBrlyNavLoaini::StatShrIfi
 ******************************************************************************/

DlgBrlyNavLoaini::StatShrIfi::StatShrIfi(
			const bool UldActive
		) :
			Block()
		{
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

void DlgBrlyNavLoaini::StatShrIfi::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyNavLoainiIfi";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["UldActive"] = UldActive;
};

void DlgBrlyNavLoaini::StatShrIfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyNavLoainiIfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyNavLoainiIfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyNavLoaini::StatShrIfi::comm(
			const StatShrIfi* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgBrlyNavLoaini::StatShrIfi::diff(
			const StatShrIfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyNavLoaini::StatShrImp
 ******************************************************************************/

DlgBrlyNavLoaini::StatShrImp::StatShrImp(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgBrlyNavLoaini::StatShrImp::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyNavLoainiImp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButRunActive"] = ButRunActive;
	me["ButStoActive"] = ButStoActive;
};

void DlgBrlyNavLoaini::StatShrImp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyNavLoainiImp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyNavLoainiImp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyNavLoaini::StatShrImp::comm(
			const StatShrImp* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgBrlyNavLoaini::StatShrImp::diff(
			const StatShrImp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyNavLoaini::StatShrLfi
 ******************************************************************************/

DlgBrlyNavLoaini::StatShrLfi::StatShrLfi(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

void DlgBrlyNavLoaini::StatShrLfi::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyNavLoainiLfi";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["DldActive"] = DldActive;
};

void DlgBrlyNavLoaini::StatShrLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyNavLoainiLfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyNavLoainiLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyNavLoaini::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgBrlyNavLoaini::StatShrLfi::diff(
			const StatShrLfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyNavLoaini::StatShrPpr
 ******************************************************************************/

DlgBrlyNavLoaini::StatShrPpr::StatShrPpr(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgBrlyNavLoaini::StatShrPpr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyNavLoainiPpr";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButRunActive"] = ButRunActive;
	me["ButStoActive"] = ButStoActive;
};

void DlgBrlyNavLoaini::StatShrPpr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyNavLoainiPpr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyNavLoainiPpr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyNavLoaini::StatShrPpr::comm(
			const StatShrPpr* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgBrlyNavLoaini::StatShrPpr::diff(
			const StatShrPpr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyNavLoaini::Tag
 ******************************************************************************/

void DlgBrlyNavLoaini::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyNavLoaini";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
	};
	me["Cpt"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::LOAINI, ixBrlyVLocale));
	me["ButDne"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DONE, ixBrlyVLocale));
};

void DlgBrlyNavLoaini::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyNavLoaini";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyNavLoaini";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::LOAINI, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DONE, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyNavLoaini::TagIfi
 ******************************************************************************/

void DlgBrlyNavLoaini::TagIfi::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyNavLoainiIfi";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
	};
	me["Uld"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::UPLOAD, ixBrlyVLocale));
	me["Cpt"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::FILENAME, ixBrlyVLocale));
};

void DlgBrlyNavLoaini::TagIfi::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyNavLoainiIfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyNavLoainiIfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::UPLOAD, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::FILENAME, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyNavLoaini::TagImp
 ******************************************************************************/

void DlgBrlyNavLoaini::TagImp::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyNavLoainiImp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
	};
	me["CptPrg"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::PROGRESS, ixBrlyVLocale));
	me["ButRun"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::RUN, ixBrlyVLocale));
	me["ButSto"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::STOP, ixBrlyVLocale));
};

void DlgBrlyNavLoaini::TagImp::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyNavLoainiImp";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyNavLoainiImp";

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
 class DlgBrlyNavLoaini::TagLfi
 ******************************************************************************/

void DlgBrlyNavLoaini::TagLfi::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyNavLoainiLfi";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
	};
	me["Dld"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DOWNLOAD, ixBrlyVLocale));
};

void DlgBrlyNavLoaini::TagLfi::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyNavLoainiLfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyNavLoainiLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DOWNLOAD, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyNavLoaini::TagPpr
 ******************************************************************************/

void DlgBrlyNavLoaini::TagPpr::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyNavLoainiPpr";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
	};
	me["CptPrg"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::PROGRESS, ixBrlyVLocale));
	me["ButRun"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::RUN, ixBrlyVLocale));
	me["ButSto"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::STOP, ixBrlyVLocale));
};

void DlgBrlyNavLoaini::TagPpr::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyNavLoainiPpr";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyNavLoainiPpr";

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
 class DlgBrlyNavLoaini::DpchAppData
 ******************************************************************************/

DlgBrlyNavLoaini::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYNAVLOAINIDATA)
		{
};

string DlgBrlyNavLoaini::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyNavLoaini::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgBrlyNavLoainiData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void DlgBrlyNavLoaini::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgBrlyNavLoainiData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class DlgBrlyNavLoaini::DpchAppDo
 ******************************************************************************/

DlgBrlyNavLoaini::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYNAVLOAINIDO)
		{
	ixVDo = 0;
	ixVDoImp = 0;
	ixVDoPpr = 0;
};

string DlgBrlyNavLoaini::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOIMP)) ss.push_back("ixVDoImp");
	if (has(IXVDOPPR)) ss.push_back("ixVDoPpr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyNavLoaini::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgBrlyNavLoainiDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
		if (me.isMember("srefIxVDoImp")) {ixVDoImp = VecVDoImp::getIx(me["srefIxVDoImp"].asString()); add(IXVDOIMP);};
		if (me.isMember("srefIxVDoPpr")) {ixVDoPpr = VecVDoPpr::getIx(me["srefIxVDoPpr"].asString()); add(IXVDOPPR);};
	} else {
	};
};

void DlgBrlyNavLoaini::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoImp;
	string srefIxVDoPpr;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgBrlyNavLoainiDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoImp", "", srefIxVDoImp)) {
			ixVDoImp = VecVDoImp::getIx(srefIxVDoImp);
			add(IXVDOIMP);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoPpr", "", srefIxVDoPpr)) {
			ixVDoPpr = VecVDoPpr::getIx(srefIxVDoPpr);
			add(IXVDOPPR);
		};
	} else {
	};
};

/******************************************************************************
 class DlgBrlyNavLoaini::DpchEngData
 ******************************************************************************/

DlgBrlyNavLoaini::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, ContInfImp* continfimp
			, ContInfLfi* continflfi
			, ContInfPpr* continfppr
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrIfi* statshrifi
			, StatShrImp* statshrimp
			, StatShrLfi* statshrlfi
			, StatShrPpr* statshrppr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGDLGBRLYNAVLOAINIDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, CONTINFIMP, CONTINFLFI, CONTINFPPR, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRIFI, STATSHRIMP, STATSHRLFI, STATSHRPPR, TAG, TAGIFI, TAGIMP, TAGLFI, TAGPPR};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFIMP) && continfimp) this->continfimp = *continfimp;
	if (find(this->mask, CONTINFLFI) && continflfi) this->continflfi = *continflfi;
	if (find(this->mask, CONTINFPPR) && continfppr) this->continfppr = *continfppr;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRIFI) && statshrifi) this->statshrifi = *statshrifi;
	if (find(this->mask, STATSHRIMP) && statshrimp) this->statshrimp = *statshrimp;
	if (find(this->mask, STATSHRLFI) && statshrlfi) this->statshrlfi = *statshrlfi;
	if (find(this->mask, STATSHRPPR) && statshrppr) this->statshrppr = *statshrppr;
};

string DlgBrlyNavLoaini::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFIMP)) ss.push_back("continfimp");
	if (has(CONTINFLFI)) ss.push_back("continflfi");
	if (has(CONTINFPPR)) ss.push_back("continfppr");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRIFI)) ss.push_back("statshrifi");
	if (has(STATSHRIMP)) ss.push_back("statshrimp");
	if (has(STATSHRLFI)) ss.push_back("statshrlfi");
	if (has(STATSHRPPR)) ss.push_back("statshrppr");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGIFI)) ss.push_back("tagifi");
	if (has(TAGIMP)) ss.push_back("tagimp");
	if (has(TAGLFI)) ss.push_back("taglfi");
	if (has(TAGPPR)) ss.push_back("tagppr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyNavLoaini::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFIMP)) {continfimp = src->continfimp; add(CONTINFIMP);};
	if (src->has(CONTINFLFI)) {continflfi = src->continflfi; add(CONTINFLFI);};
	if (src->has(CONTINFPPR)) {continfppr = src->continfppr; add(CONTINFPPR);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRIFI)) {statshrifi = src->statshrifi; add(STATSHRIFI);};
	if (src->has(STATSHRIMP)) {statshrimp = src->statshrimp; add(STATSHRIMP);};
	if (src->has(STATSHRLFI)) {statshrlfi = src->statshrlfi; add(STATSHRLFI);};
	if (src->has(STATSHRPPR)) {statshrppr = src->statshrppr; add(STATSHRPPR);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGIFI)) add(TAGIFI);
	if (src->has(TAGIMP)) add(TAGIMP);
	if (src->has(TAGLFI)) add(TAGLFI);
	if (src->has(TAGPPR)) add(TAGPPR);
};

void DlgBrlyNavLoaini::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgBrlyNavLoainiData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(CONTINFIMP)) continfimp.writeJSON(me);
	if (has(CONTINFLFI)) continflfi.writeJSON(me);
	if (has(CONTINFPPR)) continfppr.writeJSON(me);
	if (has(FEEDFDSE)) feedFDse.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STATSHRIFI)) statshrifi.writeJSON(me);
	if (has(STATSHRIMP)) statshrimp.writeJSON(me);
	if (has(STATSHRLFI)) statshrlfi.writeJSON(me);
	if (has(STATSHRPPR)) statshrppr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
	if (has(TAGIFI)) TagIfi::writeJSON(ixBrlyVLocale, me);
	if (has(TAGIMP)) TagImp::writeJSON(ixBrlyVLocale, me);
	if (has(TAGLFI)) TagLfi::writeJSON(ixBrlyVLocale, me);
	if (has(TAGPPR)) TagPpr::writeJSON(ixBrlyVLocale, me);
};

void DlgBrlyNavLoaini::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgBrlyNavLoainiData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFIMP)) continfimp.writeXML(wr);
		if (has(CONTINFLFI)) continflfi.writeXML(wr);
		if (has(CONTINFPPR)) continfppr.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRIFI)) statshrifi.writeXML(wr);
		if (has(STATSHRIMP)) statshrimp.writeXML(wr);
		if (has(STATSHRLFI)) statshrlfi.writeXML(wr);
		if (has(STATSHRPPR)) statshrppr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(TAGIFI)) TagIfi::writeXML(ixBrlyVLocale, wr);
		if (has(TAGIMP)) TagImp::writeXML(ixBrlyVLocale, wr);
		if (has(TAGLFI)) TagLfi::writeXML(ixBrlyVLocale, wr);
		if (has(TAGPPR)) TagPpr::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
