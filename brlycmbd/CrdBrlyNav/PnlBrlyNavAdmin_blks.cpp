/**
	* \file PnlBrlyNavAdmin_blks.cpp
	* job handler for job PnlBrlyNavAdmin (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyNavAdmin::VecVDo
 ******************************************************************************/

uint PnlBrlyNavAdmin::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butusgviewclick") return BUTUSGVIEWCLICK;
	if (s == "butusgnewcrdclick") return BUTUSGNEWCRDCLICK;
	if (s == "butusrviewclick") return BUTUSRVIEWCLICK;
	if (s == "butusrnewcrdclick") return BUTUSRNEWCRDCLICK;
	if (s == "butprsviewclick") return BUTPRSVIEWCLICK;
	if (s == "butprsnewcrdclick") return BUTPRSNEWCRDCLICK;
	if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	if (s == "butfilnewcrdclick") return BUTFILNEWCRDCLICK;
	if (s == "butoprviewclick") return BUTOPRVIEWCLICK;
	if (s == "butoprnewcrdclick") return BUTOPRNEWCRDCLICK;
	if (s == "butptyviewclick") return BUTPTYVIEWCLICK;
	if (s == "butptynewcrdclick") return BUTPTYNEWCRDCLICK;

	return(0);
};

string PnlBrlyNavAdmin::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
	if (ix == BUTUSGNEWCRDCLICK) return("ButUsgNewcrdClick");
	if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");
	if (ix == BUTUSRNEWCRDCLICK) return("ButUsrNewcrdClick");
	if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
	if (ix == BUTPRSNEWCRDCLICK) return("ButPrsNewcrdClick");
	if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");
	if (ix == BUTOPRVIEWCLICK) return("ButOprViewClick");
	if (ix == BUTOPRNEWCRDCLICK) return("ButOprNewcrdClick");
	if (ix == BUTPTYVIEWCLICK) return("ButPtyViewClick");
	if (ix == BUTPTYNEWCRDCLICK) return("ButPtyNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlBrlyNavAdmin::ContIac
 ******************************************************************************/

PnlBrlyNavAdmin::ContIac::ContIac(
			const uint numFLstUsg
			, const uint numFLstUsr
			, const uint numFLstPrs
			, const uint numFLstFil
			, const uint numFLstOpr
			, const uint numFLstPty
		) :
			Block()
		{
	this->numFLstUsg = numFLstUsg;
	this->numFLstUsr = numFLstUsr;
	this->numFLstPrs = numFLstPrs;
	this->numFLstFil = numFLstFil;
	this->numFLstOpr = numFLstOpr;
	this->numFLstPty = numFLstPty;

	mask = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS, NUMFLSTFIL, NUMFLSTOPR, NUMFLSTPTY};
};

bool PnlBrlyNavAdmin::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyNavAdmin"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstUsg")) {numFLstUsg = me["numFLstUsg"].asUInt(); add(NUMFLSTUSG);};
		if (me.isMember("numFLstUsr")) {numFLstUsr = me["numFLstUsr"].asUInt(); add(NUMFLSTUSR);};
		if (me.isMember("numFLstPrs")) {numFLstPrs = me["numFLstPrs"].asUInt(); add(NUMFLSTPRS);};
		if (me.isMember("numFLstFil")) {numFLstFil = me["numFLstFil"].asUInt(); add(NUMFLSTFIL);};
		if (me.isMember("numFLstOpr")) {numFLstOpr = me["numFLstOpr"].asUInt(); add(NUMFLSTOPR);};
		if (me.isMember("numFLstPty")) {numFLstPty = me["numFLstPty"].asUInt(); add(NUMFLSTPTY);};
	};

	return basefound;
};

bool PnlBrlyNavAdmin::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyNavAdmin";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsg", numFLstUsg)) add(NUMFLSTUSG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsr", numFLstUsr)) add(NUMFLSTUSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrs", numFLstPrs)) add(NUMFLSTPRS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFil", numFLstFil)) add(NUMFLSTFIL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstOpr", numFLstOpr)) add(NUMFLSTOPR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPty", numFLstPty)) add(NUMFLSTPTY);
	};

	return basefound;
};

void PnlBrlyNavAdmin::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyNavAdmin";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstUsg"] = numFLstUsg;
	me["numFLstUsr"] = numFLstUsr;
	me["numFLstPrs"] = numFLstPrs;
	me["numFLstFil"] = numFLstFil;
	me["numFLstOpr"] = numFLstOpr;
	me["numFLstPty"] = numFLstPty;
};

void PnlBrlyNavAdmin::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstUsg", numFLstUsg);
		writeUintAttr(wr, itemtag, "sref", "numFLstUsr", numFLstUsr);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrs", numFLstPrs);
		writeUintAttr(wr, itemtag, "sref", "numFLstFil", numFLstFil);
		writeUintAttr(wr, itemtag, "sref", "numFLstOpr", numFLstOpr);
		writeUintAttr(wr, itemtag, "sref", "numFLstPty", numFLstPty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyNavAdmin::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstUsg == comp->numFLstUsg) insert(items, NUMFLSTUSG);
	if (numFLstUsr == comp->numFLstUsr) insert(items, NUMFLSTUSR);
	if (numFLstPrs == comp->numFLstPrs) insert(items, NUMFLSTPRS);
	if (numFLstFil == comp->numFLstFil) insert(items, NUMFLSTFIL);
	if (numFLstOpr == comp->numFLstOpr) insert(items, NUMFLSTOPR);
	if (numFLstPty == comp->numFLstPty) insert(items, NUMFLSTPTY);

	return(items);
};

set<uint> PnlBrlyNavAdmin::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS, NUMFLSTFIL, NUMFLSTOPR, NUMFLSTPTY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavAdmin::StatApp
 ******************************************************************************/

void PnlBrlyNavAdmin::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
			, const bool LstUsgAlt
			, const bool LstUsrAlt
			, const bool LstPrsAlt
			, const bool LstFilAlt
			, const bool LstOprAlt
			, const bool LstPtyAlt
			, const uint LstUsgNumFirstdisp
			, const uint LstUsrNumFirstdisp
			, const uint LstPrsNumFirstdisp
			, const uint LstFilNumFirstdisp
			, const uint LstOprNumFirstdisp
			, const uint LstPtyNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyNavAdmin";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["LstUsgAlt"] = LstUsgAlt;
	me["LstUsrAlt"] = LstUsrAlt;
	me["LstPrsAlt"] = LstPrsAlt;
	me["LstFilAlt"] = LstFilAlt;
	me["LstOprAlt"] = LstOprAlt;
	me["LstPtyAlt"] = LstPtyAlt;
	me["LstUsgNumFirstdisp"] = LstUsgNumFirstdisp;
	me["LstUsrNumFirstdisp"] = LstUsrNumFirstdisp;
	me["LstPrsNumFirstdisp"] = LstPrsNumFirstdisp;
	me["LstFilNumFirstdisp"] = LstFilNumFirstdisp;
	me["LstOprNumFirstdisp"] = LstOprNumFirstdisp;
	me["LstPtyNumFirstdisp"] = LstPtyNumFirstdisp;
};

void PnlBrlyNavAdmin::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
			, const bool LstUsgAlt
			, const bool LstUsrAlt
			, const bool LstPrsAlt
			, const bool LstFilAlt
			, const bool LstOprAlt
			, const bool LstPtyAlt
			, const uint LstUsgNumFirstdisp
			, const uint LstUsrNumFirstdisp
			, const uint LstPrsNumFirstdisp
			, const uint LstFilNumFirstdisp
			, const uint LstOprNumFirstdisp
			, const uint LstPtyNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstUsgAlt", LstUsgAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstUsrAlt", LstUsrAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPrsAlt", LstPrsAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFilAlt", LstFilAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstOprAlt", LstOprAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPtyAlt", LstPtyAlt);
		writeUintAttr(wr, itemtag, "sref", "LstUsgNumFirstdisp", LstUsgNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstUsrNumFirstdisp", LstUsrNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPrsNumFirstdisp", LstPrsNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFilNumFirstdisp", LstFilNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstOprNumFirstdisp", LstOprNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPtyNumFirstdisp", LstPtyNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavAdmin::StatShr
 ******************************************************************************/

PnlBrlyNavAdmin::StatShr::StatShr(
			const bool LstUsgAvail
			, const bool ButUsgViewActive
			, const bool LstUsrAvail
			, const bool ButUsrViewActive
			, const bool LstPrsAvail
			, const bool ButPrsViewActive
			, const bool LstFilAvail
			, const bool ButFilViewActive
			, const bool LstOprAvail
			, const bool ButOprViewActive
			, const bool LstPtyAvail
			, const bool ButPtyViewActive
		) :
			Block()
		{
	this->LstUsgAvail = LstUsgAvail;
	this->ButUsgViewActive = ButUsgViewActive;
	this->LstUsrAvail = LstUsrAvail;
	this->ButUsrViewActive = ButUsrViewActive;
	this->LstPrsAvail = LstPrsAvail;
	this->ButPrsViewActive = ButPrsViewActive;
	this->LstFilAvail = LstFilAvail;
	this->ButFilViewActive = ButFilViewActive;
	this->LstOprAvail = LstOprAvail;
	this->ButOprViewActive = ButOprViewActive;
	this->LstPtyAvail = LstPtyAvail;
	this->ButPtyViewActive = ButPtyViewActive;

	mask = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE, LSTOPRAVAIL, BUTOPRVIEWACTIVE, LSTPTYAVAIL, BUTPTYVIEWACTIVE};
};

void PnlBrlyNavAdmin::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyNavAdmin";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstUsgAvail"] = LstUsgAvail;
	me["ButUsgViewActive"] = ButUsgViewActive;
	me["LstUsrAvail"] = LstUsrAvail;
	me["ButUsrViewActive"] = ButUsrViewActive;
	me["LstPrsAvail"] = LstPrsAvail;
	me["ButPrsViewActive"] = ButPrsViewActive;
	me["LstFilAvail"] = LstFilAvail;
	me["ButFilViewActive"] = ButFilViewActive;
	me["LstOprAvail"] = LstOprAvail;
	me["ButOprViewActive"] = ButOprViewActive;
	me["LstPtyAvail"] = LstPtyAvail;
	me["ButPtyViewActive"] = ButPtyViewActive;
};

void PnlBrlyNavAdmin::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstUsgAvail", LstUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUsgViewActive", ButUsgViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstUsrAvail", LstUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUsrViewActive", ButUsrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPrsAvail", LstPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrsViewActive", ButPrsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFilAvail", LstFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFilViewActive", ButFilViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOprAvail", LstOprAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButOprViewActive", ButOprViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPtyAvail", LstPtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPtyViewActive", ButPtyViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyNavAdmin::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstUsgAvail == comp->LstUsgAvail) insert(items, LSTUSGAVAIL);
	if (ButUsgViewActive == comp->ButUsgViewActive) insert(items, BUTUSGVIEWACTIVE);
	if (LstUsrAvail == comp->LstUsrAvail) insert(items, LSTUSRAVAIL);
	if (ButUsrViewActive == comp->ButUsrViewActive) insert(items, BUTUSRVIEWACTIVE);
	if (LstPrsAvail == comp->LstPrsAvail) insert(items, LSTPRSAVAIL);
	if (ButPrsViewActive == comp->ButPrsViewActive) insert(items, BUTPRSVIEWACTIVE);
	if (LstFilAvail == comp->LstFilAvail) insert(items, LSTFILAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);
	if (LstOprAvail == comp->LstOprAvail) insert(items, LSTOPRAVAIL);
	if (ButOprViewActive == comp->ButOprViewActive) insert(items, BUTOPRVIEWACTIVE);
	if (LstPtyAvail == comp->LstPtyAvail) insert(items, LSTPTYAVAIL);
	if (ButPtyViewActive == comp->ButPtyViewActive) insert(items, BUTPTYVIEWACTIVE);

	return(items);
};

set<uint> PnlBrlyNavAdmin::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE, LSTOPRAVAIL, BUTOPRVIEWACTIVE, LSTPTYAVAIL, BUTPTYVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavAdmin::Tag
 ******************************************************************************/

void PnlBrlyNavAdmin::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyNavAdmin";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Administration module";
		me["CptUsg"] = "user groups";
		me["CptUsr"] = "users";
		me["CptPrs"] = "persons";
		me["CptFil"] = "files";
		me["CptOpr"] = "operators";
		me["CptPty"] = "plane types";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Verwaltung";
		me["CptUsg"] = "Benutzergruppen";
		me["CptUsr"] = "Benutzer";
		me["CptPrs"] = "Personen";
		me["CptFil"] = "Dateien";
		me["CptOpr"] = "Betreiber";
		me["CptPty"] = "Flugzeugtypen";
	};
};

void PnlBrlyNavAdmin::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Administration module");
			writeStringAttr(wr, itemtag, "sref", "CptUsg", "user groups");
			writeStringAttr(wr, itemtag, "sref", "CptUsr", "users");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "persons");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "files");
			writeStringAttr(wr, itemtag, "sref", "CptOpr", "operators");
			writeStringAttr(wr, itemtag, "sref", "CptPty", "plane types");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Verwaltung");
			writeStringAttr(wr, itemtag, "sref", "CptUsg", "Benutzergruppen");
			writeStringAttr(wr, itemtag, "sref", "CptUsr", "Benutzer");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "Personen");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Dateien");
			writeStringAttr(wr, itemtag, "sref", "CptOpr", "Betreiber");
			writeStringAttr(wr, itemtag, "sref", "CptPty", "Flugzeugtypen");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavAdmin::DpchAppData
 ******************************************************************************/

PnlBrlyNavAdmin::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVADMINDATA)
		{
};

string PnlBrlyNavAdmin::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavAdmin::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyNavAdminData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlBrlyNavAdmin::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyNavAdminData");
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
 class PnlBrlyNavAdmin::DpchAppDo
 ******************************************************************************/

PnlBrlyNavAdmin::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVADMINDO)
		{
	ixVDo = 0;
};

string PnlBrlyNavAdmin::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavAdmin::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyNavAdminDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyNavAdmin::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyNavAdminDo");
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
	} else {
	};
};

/******************************************************************************
 class PnlBrlyNavAdmin::DpchEngData
 ******************************************************************************/

PnlBrlyNavAdmin::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstFil
			, Feed* feedFLstOpr
			, Feed* feedFLstPrs
			, Feed* feedFLstPty
			, Feed* feedFLstUsg
			, Feed* feedFLstUsr
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYNAVADMINDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTFIL, FEEDFLSTOPR, FEEDFLSTPRS, FEEDFLSTPTY, FEEDFLSTUSG, FEEDFLSTUSR, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTFIL) && feedFLstFil) this->feedFLstFil = *feedFLstFil;
	if (find(this->mask, FEEDFLSTOPR) && feedFLstOpr) this->feedFLstOpr = *feedFLstOpr;
	if (find(this->mask, FEEDFLSTPRS) && feedFLstPrs) this->feedFLstPrs = *feedFLstPrs;
	if (find(this->mask, FEEDFLSTPTY) && feedFLstPty) this->feedFLstPty = *feedFLstPty;
	if (find(this->mask, FEEDFLSTUSG) && feedFLstUsg) this->feedFLstUsg = *feedFLstUsg;
	if (find(this->mask, FEEDFLSTUSR) && feedFLstUsr) this->feedFLstUsr = *feedFLstUsr;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyNavAdmin::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFIL)) ss.push_back("feedFLstFil");
	if (has(FEEDFLSTOPR)) ss.push_back("feedFLstOpr");
	if (has(FEEDFLSTPRS)) ss.push_back("feedFLstPrs");
	if (has(FEEDFLSTPTY)) ss.push_back("feedFLstPty");
	if (has(FEEDFLSTUSG)) ss.push_back("feedFLstUsg");
	if (has(FEEDFLSTUSR)) ss.push_back("feedFLstUsr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavAdmin::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTFIL)) {feedFLstFil = src->feedFLstFil; add(FEEDFLSTFIL);};
	if (src->has(FEEDFLSTOPR)) {feedFLstOpr = src->feedFLstOpr; add(FEEDFLSTOPR);};
	if (src->has(FEEDFLSTPRS)) {feedFLstPrs = src->feedFLstPrs; add(FEEDFLSTPRS);};
	if (src->has(FEEDFLSTPTY)) {feedFLstPty = src->feedFLstPty; add(FEEDFLSTPTY);};
	if (src->has(FEEDFLSTUSG)) {feedFLstUsg = src->feedFLstUsg; add(FEEDFLSTUSG);};
	if (src->has(FEEDFLSTUSR)) {feedFLstUsr = src->feedFLstUsr; add(FEEDFLSTUSR);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyNavAdmin::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyNavAdminData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTFIL)) feedFLstFil.writeJSON(me);
	if (has(FEEDFLSTOPR)) feedFLstOpr.writeJSON(me);
	if (has(FEEDFLSTPRS)) feedFLstPrs.writeJSON(me);
	if (has(FEEDFLSTPTY)) feedFLstPty.writeJSON(me);
	if (has(FEEDFLSTUSG)) feedFLstUsg.writeJSON(me);
	if (has(FEEDFLSTUSR)) feedFLstUsr.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyNavAdmin::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyNavAdminData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTFIL)) feedFLstFil.writeXML(wr);
		if (has(FEEDFLSTOPR)) feedFLstOpr.writeXML(wr);
		if (has(FEEDFLSTPRS)) feedFLstPrs.writeXML(wr);
		if (has(FEEDFLSTPTY)) feedFLstPty.writeXML(wr);
		if (has(FEEDFLSTUSG)) feedFLstUsg.writeXML(wr);
		if (has(FEEDFLSTUSR)) feedFLstUsr.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
