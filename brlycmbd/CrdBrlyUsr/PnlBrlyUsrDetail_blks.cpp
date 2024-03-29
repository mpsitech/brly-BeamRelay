/**
	* \file PnlBrlyUsrDetail_blks.cpp
	* job handler for job PnlBrlyUsrDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyUsrDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyUsrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butprsviewclick") return BUTPRSVIEWCLICK;
	if (s == "butusgviewclick") return BUTUSGVIEWCLICK;
	if (s == "butjsteditclick") return BUTJSTEDITCLICK;

	return(0);
};

string PnlBrlyUsrDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
	if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
	if (ix == BUTJSTEDITCLICK) return("ButJstEditClick");

	return("");
};

/******************************************************************************
 class PnlBrlyUsrDetail::ContIac
 ******************************************************************************/

PnlBrlyUsrDetail::ContIac::ContIac(
			const uint numFPupJst
			, const uint numFPupSte
			, const uint numFPupLcl
			, const uint numFPupUlv
			, const string& TxfPwd
			, const string& TxfFky
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupJst = numFPupJst;
	this->numFPupSte = numFPupSte;
	this->numFPupLcl = numFPupLcl;
	this->numFPupUlv = numFPupUlv;
	this->TxfPwd = TxfPwd;
	this->TxfFky = TxfFky;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPJST, NUMFPUPSTE, NUMFPUPLCL, NUMFPUPULV, TXFPWD, TXFFKY, TXFCMT};
};

bool PnlBrlyUsrDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyUsrDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupJst")) {numFPupJst = me["numFPupJst"].asUInt(); add(NUMFPUPJST);};
		if (me.isMember("numFPupSte")) {numFPupSte = me["numFPupSte"].asUInt(); add(NUMFPUPSTE);};
		if (me.isMember("numFPupLcl")) {numFPupLcl = me["numFPupLcl"].asUInt(); add(NUMFPUPLCL);};
		if (me.isMember("numFPupUlv")) {numFPupUlv = me["numFPupUlv"].asUInt(); add(NUMFPUPULV);};
		if (me.isMember("TxfPwd")) {TxfPwd = me["TxfPwd"].asString(); add(TXFPWD);};
		if (me.isMember("TxfFky")) {TxfFky = me["TxfFky"].asString(); add(TXFFKY);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlBrlyUsrDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyUsrDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJst", numFPupJst)) add(NUMFPUPJST);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSte", numFPupSte)) add(NUMFPUPSTE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupLcl", numFPupLcl)) add(NUMFPUPLCL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupUlv", numFPupUlv)) add(NUMFPUPULV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPwd", TxfPwd)) add(TXFPWD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFky", TxfFky)) add(TXFFKY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlBrlyUsrDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyUsrDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupJst"] = numFPupJst;
	me["numFPupSte"] = numFPupSte;
	me["numFPupLcl"] = numFPupLcl;
	me["numFPupUlv"] = numFPupUlv;
	me["TxfPwd"] = TxfPwd;
	me["TxfFky"] = TxfFky;
	me["TxfCmt"] = TxfCmt;
};

void PnlBrlyUsrDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyUsrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyUsrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJst", numFPupJst);
		writeUintAttr(wr, itemtag, "sref", "numFPupSte", numFPupSte);
		writeUintAttr(wr, itemtag, "sref", "numFPupLcl", numFPupLcl);
		writeUintAttr(wr, itemtag, "sref", "numFPupUlv", numFPupUlv);
		writeStringAttr(wr, itemtag, "sref", "TxfPwd", TxfPwd);
		writeStringAttr(wr, itemtag, "sref", "TxfFky", TxfFky);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyUsrDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJst == comp->numFPupJst) insert(items, NUMFPUPJST);
	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (numFPupLcl == comp->numFPupLcl) insert(items, NUMFPUPLCL);
	if (numFPupUlv == comp->numFPupUlv) insert(items, NUMFPUPULV);
	if (TxfPwd == comp->TxfPwd) insert(items, TXFPWD);
	if (TxfFky == comp->TxfFky) insert(items, TXFFKY);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlBrlyUsrDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJST, NUMFPUPSTE, NUMFPUPLCL, NUMFPUPULV, TXFPWD, TXFFKY, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyUsrDetail::ContInf
 ******************************************************************************/

PnlBrlyUsrDetail::ContInf::ContInf(
			const string& TxtPrs
			, const string& TxtSrf
			, const string& TxtUsg
		) :
			Block()
		{
	this->TxtPrs = TxtPrs;
	this->TxtSrf = TxtSrf;
	this->TxtUsg = TxtUsg;

	mask = {TXTPRS, TXTSRF, TXTUSG};
};

void PnlBrlyUsrDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyUsrDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtPrs"] = TxtPrs;
	me["TxtSrf"] = TxtSrf;
	me["TxtUsg"] = TxtUsg;
};

void PnlBrlyUsrDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyUsrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyUsrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrs", TxtPrs);
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtUsg", TxtUsg);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyUsrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrs == comp->TxtPrs) insert(items, TXTPRS);
	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtUsg == comp->TxtUsg) insert(items, TXTUSG);

	return(items);
};

set<uint> PnlBrlyUsrDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRS, TXTSRF, TXTUSG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyUsrDetail::StatApp
 ******************************************************************************/

void PnlBrlyUsrDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyUsrDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
};

void PnlBrlyUsrDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyUsrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyUsrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyUsrDetail::StatShr
 ******************************************************************************/

PnlBrlyUsrDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtPrsActive
			, const bool ButPrsViewAvail
			, const bool ButPrsViewActive
			, const bool TxtSrfActive
			, const bool TxtUsgActive
			, const bool ButUsgViewAvail
			, const bool ButUsgViewActive
			, const bool PupJstActive
			, const bool ButJstEditAvail
			, const bool PupSteActive
			, const bool PupLclActive
			, const bool PupUlvActive
			, const bool TxfPwdActive
			, const bool TxfFkyActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtPrsActive = TxtPrsActive;
	this->ButPrsViewAvail = ButPrsViewAvail;
	this->ButPrsViewActive = ButPrsViewActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtUsgActive = TxtUsgActive;
	this->ButUsgViewAvail = ButUsgViewAvail;
	this->ButUsgViewActive = ButUsgViewActive;
	this->PupJstActive = PupJstActive;
	this->ButJstEditAvail = ButJstEditAvail;
	this->PupSteActive = PupSteActive;
	this->PupLclActive = PupLclActive;
	this->PupUlvActive = PupUlvActive;
	this->TxfPwdActive = TxfPwdActive;
	this->TxfFkyActive = TxfFkyActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRSACTIVE, BUTPRSVIEWAVAIL, BUTPRSVIEWACTIVE, TXTSRFACTIVE, TXTUSGACTIVE, BUTUSGVIEWAVAIL, BUTUSGVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, PUPLCLACTIVE, PUPULVACTIVE, TXFPWDACTIVE, TXFFKYACTIVE, TXFCMTACTIVE};
};

void PnlBrlyUsrDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyUsrDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtPrsActive"] = TxtPrsActive;
	me["ButPrsViewAvail"] = ButPrsViewAvail;
	me["ButPrsViewActive"] = ButPrsViewActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxtUsgActive"] = TxtUsgActive;
	me["ButUsgViewAvail"] = ButUsgViewAvail;
	me["ButUsgViewActive"] = ButUsgViewActive;
	me["PupJstActive"] = PupJstActive;
	me["ButJstEditAvail"] = ButJstEditAvail;
	me["PupSteActive"] = PupSteActive;
	me["PupLclActive"] = PupLclActive;
	me["PupUlvActive"] = PupUlvActive;
	me["TxfPwdActive"] = TxfPwdActive;
	me["TxfFkyActive"] = TxfFkyActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlBrlyUsrDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyUsrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyUsrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrsActive", TxtPrsActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPrsViewAvail", ButPrsViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrsViewActive", ButPrsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtUsgActive", TxtUsgActive);
		writeBoolAttr(wr, itemtag, "sref", "ButUsgViewAvail", ButUsgViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUsgViewActive", ButUsgViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJstActive", PupJstActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJstEditAvail", ButJstEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupSteActive", PupSteActive);
		writeBoolAttr(wr, itemtag, "sref", "PupLclActive", PupLclActive);
		writeBoolAttr(wr, itemtag, "sref", "PupUlvActive", PupUlvActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfPwdActive", TxfPwdActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFkyActive", TxfFkyActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyUsrDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtPrsActive == comp->TxtPrsActive) insert(items, TXTPRSACTIVE);
	if (ButPrsViewAvail == comp->ButPrsViewAvail) insert(items, BUTPRSVIEWAVAIL);
	if (ButPrsViewActive == comp->ButPrsViewActive) insert(items, BUTPRSVIEWACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtUsgActive == comp->TxtUsgActive) insert(items, TXTUSGACTIVE);
	if (ButUsgViewAvail == comp->ButUsgViewAvail) insert(items, BUTUSGVIEWAVAIL);
	if (ButUsgViewActive == comp->ButUsgViewActive) insert(items, BUTUSGVIEWACTIVE);
	if (PupJstActive == comp->PupJstActive) insert(items, PUPJSTACTIVE);
	if (ButJstEditAvail == comp->ButJstEditAvail) insert(items, BUTJSTEDITAVAIL);
	if (PupSteActive == comp->PupSteActive) insert(items, PUPSTEACTIVE);
	if (PupLclActive == comp->PupLclActive) insert(items, PUPLCLACTIVE);
	if (PupUlvActive == comp->PupUlvActive) insert(items, PUPULVACTIVE);
	if (TxfPwdActive == comp->TxfPwdActive) insert(items, TXFPWDACTIVE);
	if (TxfFkyActive == comp->TxfFkyActive) insert(items, TXFFKYACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlBrlyUsrDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRSACTIVE, BUTPRSVIEWAVAIL, BUTPRSVIEWACTIVE, TXTSRFACTIVE, TXTUSGACTIVE, BUTUSGVIEWAVAIL, BUTUSGVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, PUPLCLACTIVE, PUPULVACTIVE, TXFPWDACTIVE, TXFFKYACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyUsrDetail::Tag
 ******************************************************************************/

void PnlBrlyUsrDetail::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyUsrDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["CptPrs"] = "person";
		me["CptSrf"] = "login";
		me["CptUsg"] = "primary user group";
		me["CptSte"] = "state";
		me["CptLcl"] = "locale";
		me["CptUlv"] = "user level";
		me["CptPwd"] = "password";
		me["CptFky"] = "full key (X.509)";
		me["CptCmt"] = "comment";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["CptPrs"] = "Person";
		me["CptSrf"] = "Login";
		me["CptUsg"] = "prim\\u00e4re Benutzergruppe";
		me["CptSte"] = "state";
		me["CptLcl"] = "locale";
		me["CptUlv"] = "user level";
		me["CptPwd"] = "Passwort";
		me["CptFky"] = "vollst\\u008andiger Schl\\u009fssel (X.509)";
		me["CptCmt"] = "Notiz";
	};
	me["Cpt"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale));
};

void PnlBrlyUsrDetail::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyUsrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyUsrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "person");
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "login");
			writeStringAttr(wr, itemtag, "sref", "CptUsg", "primary user group");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "state");
			writeStringAttr(wr, itemtag, "sref", "CptLcl", "locale");
			writeStringAttr(wr, itemtag, "sref", "CptUlv", "user level");
			writeStringAttr(wr, itemtag, "sref", "CptPwd", "password");
			writeStringAttr(wr, itemtag, "sref", "CptFky", "full key (X.509)");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "Person");
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "Login");
			writeStringAttr(wr, itemtag, "sref", "CptUsg", "prim\\u00e4re Benutzergruppe");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "state");
			writeStringAttr(wr, itemtag, "sref", "CptLcl", "locale");
			writeStringAttr(wr, itemtag, "sref", "CptUlv", "user level");
			writeStringAttr(wr, itemtag, "sref", "CptPwd", "Passwort");
			writeStringAttr(wr, itemtag, "sref", "CptFky", "vollst\\u008andiger Schl\\u009fssel (X.509)");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "Notiz");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyUsrDetail::DpchAppData
 ******************************************************************************/

PnlBrlyUsrDetail::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYUSRDETAILDATA)
		{
};

string PnlBrlyUsrDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyUsrDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyUsrDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlBrlyUsrDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyUsrDetailData");
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
 class PnlBrlyUsrDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyUsrDetail::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYUSRDETAILDO)
		{
	ixVDo = 0;
};

string PnlBrlyUsrDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyUsrDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyUsrDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyUsrDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyUsrDetailDo");
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
 class PnlBrlyUsrDetail::DpchEngData
 ******************************************************************************/

PnlBrlyUsrDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupJst
			, Feed* feedFPupLcl
			, Feed* feedFPupSte
			, Feed* feedFPupUlv
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYUSRDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPJST, FEEDFPUPLCL, FEEDFPUPSTE, FEEDFPUPULV, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPJST) && feedFPupJst) this->feedFPupJst = *feedFPupJst;
	if (find(this->mask, FEEDFPUPLCL) && feedFPupLcl) this->feedFPupLcl = *feedFPupLcl;
	if (find(this->mask, FEEDFPUPSTE) && feedFPupSte) this->feedFPupSte = *feedFPupSte;
	if (find(this->mask, FEEDFPUPULV) && feedFPupUlv) this->feedFPupUlv = *feedFPupUlv;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyUsrDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPJST)) ss.push_back("feedFPupJst");
	if (has(FEEDFPUPLCL)) ss.push_back("feedFPupLcl");
	if (has(FEEDFPUPSTE)) ss.push_back("feedFPupSte");
	if (has(FEEDFPUPULV)) ss.push_back("feedFPupUlv");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyUsrDetail::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPJST)) {feedFPupJst = src->feedFPupJst; add(FEEDFPUPJST);};
	if (src->has(FEEDFPUPLCL)) {feedFPupLcl = src->feedFPupLcl; add(FEEDFPUPLCL);};
	if (src->has(FEEDFPUPSTE)) {feedFPupSte = src->feedFPupSte; add(FEEDFPUPSTE);};
	if (src->has(FEEDFPUPULV)) {feedFPupUlv = src->feedFPupUlv; add(FEEDFPUPULV);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyUsrDetail::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyUsrDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPJST)) feedFPupJst.writeJSON(me);
	if (has(FEEDFPUPLCL)) feedFPupLcl.writeJSON(me);
	if (has(FEEDFPUPSTE)) feedFPupSte.writeJSON(me);
	if (has(FEEDFPUPULV)) feedFPupUlv.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyUsrDetail::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyUsrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPJST)) feedFPupJst.writeXML(wr);
		if (has(FEEDFPUPLCL)) feedFPupLcl.writeXML(wr);
		if (has(FEEDFPUPSTE)) feedFPupSte.writeXML(wr);
		if (has(FEEDFPUPULV)) feedFPupUlv.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
