/**
	* \file PnlBrlyUsrList_blks.cpp
	* job handler for job PnlBrlyUsrList (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyUsrList::VecVDo
 ******************************************************************************/

uint PnlBrlyUsrList::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butfilterclick") return BUTFILTERCLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyUsrList::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTFILTERCLICK) return("ButFilterClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyUsrList::ContIac
 ******************************************************************************/

PnlBrlyUsrList::ContIac::ContIac(
			const uint numFTos
		) :
			Block()
		{
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlBrlyUsrList::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyUsrList"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFTos")) {numFTos = me["numFTos"].asUInt(); add(NUMFTOS);};
	};

	return basefound;
};

bool PnlBrlyUsrList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyUsrList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlBrlyUsrList::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyUsrList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFTos"] = numFTos;
};

void PnlBrlyUsrList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyUsrList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyUsrList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlBrlyUsrList::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFTOS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyUsrList::ContInf
 ******************************************************************************/

PnlBrlyUsrList::ContInf::ContInf(
			const bool ButFilterOn
			, const uint numFCsiQst
		) :
			Block()
		{
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {BUTFILTERON, NUMFCSIQST};
};

void PnlBrlyUsrList::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyUsrList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButFilterOn"] = ButFilterOn;
	me["numFCsiQst"] = numFCsiQst;
};

void PnlBrlyUsrList::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyUsrList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButFilterOn", ButFilterOn);
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyUsrList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlyUsrList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTFILTERON, NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyUsrList::StatShr
 ******************************************************************************/

PnlBrlyUsrList::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXBRLYVEXPSTATE, BUTDELETEACTIVE};
};

void PnlBrlyUsrList::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyUsrList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["ButDeleteActive"] = ButDeleteActive;
};

void PnlBrlyUsrList::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyUsrList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyUsrList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlBrlyUsrList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, BUTDELETEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyUsrList::StgIac
 ******************************************************************************/

PnlBrlyUsrList::StgIac::StgIac(
			const uint TcoGrpWidth
			, const uint TcoOwnWidth
			, const uint TcoPrsWidth
			, const uint TcoSrfWidth
			, const uint TcoUsgWidth
			, const uint TcoSteWidth
			, const uint TcoLclWidth
			, const uint TcoUlvWidth
		) :
			Block()
		{
	this->TcoGrpWidth = TcoGrpWidth;
	this->TcoOwnWidth = TcoOwnWidth;
	this->TcoPrsWidth = TcoPrsWidth;
	this->TcoSrfWidth = TcoSrfWidth;
	this->TcoUsgWidth = TcoUsgWidth;
	this->TcoSteWidth = TcoSteWidth;
	this->TcoLclWidth = TcoLclWidth;
	this->TcoUlvWidth = TcoUlvWidth;
	mask = {TCOGRPWIDTH, TCOOWNWIDTH, TCOPRSWIDTH, TCOSRFWIDTH, TCOUSGWIDTH, TCOSTEWIDTH, TCOLCLWIDTH, TCOULVWIDTH};
};

bool PnlBrlyUsrList::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacBrlyUsrList"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TcoGrpWidth")) {TcoGrpWidth = me["TcoGrpWidth"].asUInt(); add(TCOGRPWIDTH);};
		if (me.isMember("TcoOwnWidth")) {TcoOwnWidth = me["TcoOwnWidth"].asUInt(); add(TCOOWNWIDTH);};
		if (me.isMember("TcoPrsWidth")) {TcoPrsWidth = me["TcoPrsWidth"].asUInt(); add(TCOPRSWIDTH);};
		if (me.isMember("TcoSrfWidth")) {TcoSrfWidth = me["TcoSrfWidth"].asUInt(); add(TCOSRFWIDTH);};
		if (me.isMember("TcoUsgWidth")) {TcoUsgWidth = me["TcoUsgWidth"].asUInt(); add(TCOUSGWIDTH);};
		if (me.isMember("TcoSteWidth")) {TcoSteWidth = me["TcoSteWidth"].asUInt(); add(TCOSTEWIDTH);};
		if (me.isMember("TcoLclWidth")) {TcoLclWidth = me["TcoLclWidth"].asUInt(); add(TCOLCLWIDTH);};
		if (me.isMember("TcoUlvWidth")) {TcoUlvWidth = me["TcoUlvWidth"].asUInt(); add(TCOULVWIDTH);};
	};

	return basefound;
};

bool PnlBrlyUsrList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyUsrList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoGrpWidth", TcoGrpWidth)) add(TCOGRPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoOwnWidth", TcoOwnWidth)) add(TCOOWNWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPrsWidth", TcoPrsWidth)) add(TCOPRSWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", TcoSrfWidth)) add(TCOSRFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoUsgWidth", TcoUsgWidth)) add(TCOUSGWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSteWidth", TcoSteWidth)) add(TCOSTEWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLclWidth", TcoLclWidth)) add(TCOLCLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoUlvWidth", TcoUlvWidth)) add(TCOULVWIDTH);
	};

	return basefound;
};

void PnlBrlyUsrList::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyUsrList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TcoGrpWidth"] = TcoGrpWidth;
	me["TcoOwnWidth"] = TcoOwnWidth;
	me["TcoPrsWidth"] = TcoPrsWidth;
	me["TcoSrfWidth"] = TcoSrfWidth;
	me["TcoUsgWidth"] = TcoUsgWidth;
	me["TcoSteWidth"] = TcoSteWidth;
	me["TcoLclWidth"] = TcoLclWidth;
	me["TcoUlvWidth"] = TcoUlvWidth;
};

void PnlBrlyUsrList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyUsrList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoGrpWidth", TcoGrpWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoOwnWidth", TcoOwnWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoPrsWidth", TcoPrsWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoUsgWidth", TcoUsgWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSteWidth", TcoSteWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLclWidth", TcoLclWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoUlvWidth", TcoUlvWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyUsrList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoGrpWidth == comp->TcoGrpWidth) insert(items, TCOGRPWIDTH);
	if (TcoOwnWidth == comp->TcoOwnWidth) insert(items, TCOOWNWIDTH);
	if (TcoPrsWidth == comp->TcoPrsWidth) insert(items, TCOPRSWIDTH);
	if (TcoSrfWidth == comp->TcoSrfWidth) insert(items, TCOSRFWIDTH);
	if (TcoUsgWidth == comp->TcoUsgWidth) insert(items, TCOUSGWIDTH);
	if (TcoSteWidth == comp->TcoSteWidth) insert(items, TCOSTEWIDTH);
	if (TcoLclWidth == comp->TcoLclWidth) insert(items, TCOLCLWIDTH);
	if (TcoUlvWidth == comp->TcoUlvWidth) insert(items, TCOULVWIDTH);

	return(items);
};

set<uint> PnlBrlyUsrList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOGRPWIDTH, TCOOWNWIDTH, TCOPRSWIDTH, TCOSRFWIDTH, TCOUSGWIDTH, TCOSTEWIDTH, TCOLCLWIDTH, TCOULVWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyUsrList::Tag
 ******************************************************************************/

void PnlBrlyUsrList::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyUsrList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Users";
		me["TcoPrs"] = "Person";
		me["TcoSrf"] = "Login";
		me["TcoUsg"] = "Primary user group";
		me["TcoSte"] = "State";
		me["TcoLcl"] = "Locale";
		me["TcoUlv"] = "User level";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Benutzer";
		me["TcoPrs"] = "Person";
		me["TcoSrf"] = "Login";
		me["TcoUsg"] = "Prim\\u00e4re Benutzergruppe";
		me["TcoSte"] = "Status";
		me["TcoLcl"] = "Sprachversion";
		me["TcoUlv"] = "Benutzerebene";
	};
	me["TxtRecord1"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::REC, ixBrlyVLocale));
	me["TxtRecord2"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale));
	me["Trs"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...";
	me["TxtShowing1"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::SHOWLONG, ixBrlyVLocale));
	me["TxtShowing2"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale));
	me["TcoGrp"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GRP, ixBrlyVLocale));
	me["TcoOwn"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::OWN, ixBrlyVLocale));
};

void PnlBrlyUsrList::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyUsrList";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Users");
			writeStringAttr(wr, itemtag, "sref", "TcoPrs", "Person");
			writeStringAttr(wr, itemtag, "sref", "TcoSrf", "Login");
			writeStringAttr(wr, itemtag, "sref", "TcoUsg", "Primary user group");
			writeStringAttr(wr, itemtag, "sref", "TcoSte", "State");
			writeStringAttr(wr, itemtag, "sref", "TcoLcl", "Locale");
			writeStringAttr(wr, itemtag, "sref", "TcoUlv", "User level");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Benutzer");
			writeStringAttr(wr, itemtag, "sref", "TcoPrs", "Person");
			writeStringAttr(wr, itemtag, "sref", "TcoSrf", "Login");
			writeStringAttr(wr, itemtag, "sref", "TcoUsg", "Prim\\u00e4re Benutzergruppe");
			writeStringAttr(wr, itemtag, "sref", "TcoSte", "Status");
			writeStringAttr(wr, itemtag, "sref", "TcoLcl", "Sprachversion");
			writeStringAttr(wr, itemtag, "sref", "TcoUlv", "Benutzerebene");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::REC, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::SHOWLONG, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TcoGrp", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GRP, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TcoOwn", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::OWN, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyUsrList::DpchAppData
 ******************************************************************************/

PnlBrlyUsrList::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYUSRLISTDATA)
		{
};

string PnlBrlyUsrList::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyUsrList::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyUsrListData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
		if (stgiac.readJSON(me, true)) add(STGIAC);
		if (stgiacqry.readJSON(me, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryBrlyUsrList::StgIac();
	};
};

void PnlBrlyUsrList::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyUsrListData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryBrlyUsrList::StgIac();
	};
};

/******************************************************************************
 class PnlBrlyUsrList::DpchAppDo
 ******************************************************************************/

PnlBrlyUsrList::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYUSRLISTDO)
		{
	ixVDo = 0;
};

string PnlBrlyUsrList::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyUsrList::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyUsrListDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyUsrList::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyUsrListDo");
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
 class PnlBrlyUsrList::DpchEngData
 ******************************************************************************/

PnlBrlyUsrList::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFCsiQst
			, Feed* feedFTos
			, StatShr* statshr
			, StgIac* stgiac
			, ListBrlyQUsrList* rst
			, QryBrlyUsrList::StatShr* statshrqry
			, QryBrlyUsrList::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYUSRLISTDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFCSIQST, FEEDFTOS, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, FEEDFTOS) && feedFTos) this->feedFTos = *feedFTos;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlBrlyUsrList::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(FEEDFTOS)) ss.push_back("feedFTos");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyUsrList::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(FEEDFTOS)) {feedFTos = src->feedFTos; add(FEEDFTOS);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlBrlyUsrList::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyUsrListData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFCSIQST)) feedFCsiQst.writeJSON(me);
	if (has(FEEDFTOS)) feedFTos.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STGIAC)) stgiac.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
	if (has(RST)) rst.writeJSON(me);
	if (has(STATAPPQRY)) QryBrlyUsrList::StatApp::writeJSON(me);
	if (has(STATSHRQRY)) statshrqry.writeJSON(me);
	if (has(STGIACQRY)) stgiacqry.writeJSON(me);
};

void PnlBrlyUsrList::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyUsrListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(FEEDFTOS)) feedFTos.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryBrlyUsrList::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
