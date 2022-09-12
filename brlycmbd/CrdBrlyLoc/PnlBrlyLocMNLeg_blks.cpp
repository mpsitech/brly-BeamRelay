/**
	* \file PnlBrlyLocMNLeg_blks.cpp
	* job handler for job PnlBrlyLocMNLeg (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyLocMNLeg::VecVDo
 ******************************************************************************/

uint PnlBrlyLocMNLeg::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	if (s == "butaddclick") return BUTADDCLICK;
	if (s == "butsubclick") return BUTSUBCLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyLocMNLeg::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	if (ix == BUTADDCLICK) return("ButAddClick");
	if (ix == BUTSUBCLICK) return("ButSubClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLocMNLeg::ContInf
 ******************************************************************************/

PnlBrlyLocMNLeg::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlBrlyLocMNLeg::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLocMNLeg";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFCsiQst"] = numFCsiQst;
};

void PnlBrlyLocMNLeg::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLocMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyLocMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocMNLeg::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlyLocMNLeg::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocMNLeg::StatApp
 ******************************************************************************/

void PnlBrlyLocMNLeg::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyLocMNLeg";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
};

void PnlBrlyLocMNLeg::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyLocMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyLocMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocMNLeg::StatShr
 ******************************************************************************/

PnlBrlyLocMNLeg::StatShr::StatShr(
			const bool ButViewAvail
			, const bool ButViewActive
			, const bool ButAddAvail
			, const bool ButSubAvail
			, const bool ButSubActive
		) :
			Block()
		{
	this->ButViewAvail = ButViewAvail;
	this->ButViewActive = ButViewActive;
	this->ButAddAvail = ButAddAvail;
	this->ButSubAvail = ButSubAvail;
	this->ButSubActive = ButSubActive;

	mask = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
};

void PnlBrlyLocMNLeg::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLocMNLeg";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButViewAvail"] = ButViewAvail;
	me["ButViewActive"] = ButViewActive;
	me["ButAddAvail"] = ButAddAvail;
	me["ButSubAvail"] = ButSubAvail;
	me["ButSubActive"] = ButSubActive;
};

void PnlBrlyLocMNLeg::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLocMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyLocMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButViewAvail", ButViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButViewActive", ButViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButAddAvail", ButAddAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSubAvail", ButSubAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSubActive", ButSubActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocMNLeg::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewAvail == comp->ButViewAvail) insert(items, BUTVIEWAVAIL);
	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);
	if (ButAddAvail == comp->ButAddAvail) insert(items, BUTADDAVAIL);
	if (ButSubAvail == comp->ButSubAvail) insert(items, BUTSUBAVAIL);
	if (ButSubActive == comp->ButSubActive) insert(items, BUTSUBACTIVE);

	return(items);
};

set<uint> PnlBrlyLocMNLeg::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocMNLeg::StgIac
 ******************************************************************************/

PnlBrlyLocMNLeg::StgIac::StgIac(
			const uint TcoMrefWidth
			, const uint TcoLp0Width
			, const uint TcoLp1Width
			, const uint TcoLphWidth
			, const uint TcoLthWidth
			, const uint TcoXp0Width
			, const uint TcoXp1Width
		) :
			Block()
		{
	this->TcoMrefWidth = TcoMrefWidth;
	this->TcoLp0Width = TcoLp0Width;
	this->TcoLp1Width = TcoLp1Width;
	this->TcoLphWidth = TcoLphWidth;
	this->TcoLthWidth = TcoLthWidth;
	this->TcoXp0Width = TcoXp0Width;
	this->TcoXp1Width = TcoXp1Width;
	mask = {TCOMREFWIDTH, TCOLP0WIDTH, TCOLP1WIDTH, TCOLPHWIDTH, TCOLTHWIDTH, TCOXP0WIDTH, TCOXP1WIDTH};
};

bool PnlBrlyLocMNLeg::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacBrlyLocMNLeg"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TcoMrefWidth")) {TcoMrefWidth = me["TcoMrefWidth"].asUInt(); add(TCOMREFWIDTH);};
		if (me.isMember("TcoLp0Width")) {TcoLp0Width = me["TcoLp0Width"].asUInt(); add(TCOLP0WIDTH);};
		if (me.isMember("TcoLp1Width")) {TcoLp1Width = me["TcoLp1Width"].asUInt(); add(TCOLP1WIDTH);};
		if (me.isMember("TcoLphWidth")) {TcoLphWidth = me["TcoLphWidth"].asUInt(); add(TCOLPHWIDTH);};
		if (me.isMember("TcoLthWidth")) {TcoLthWidth = me["TcoLthWidth"].asUInt(); add(TCOLTHWIDTH);};
		if (me.isMember("TcoXp0Width")) {TcoXp0Width = me["TcoXp0Width"].asUInt(); add(TCOXP0WIDTH);};
		if (me.isMember("TcoXp1Width")) {TcoXp1Width = me["TcoXp1Width"].asUInt(); add(TCOXP1WIDTH);};
	};

	return basefound;
};

bool PnlBrlyLocMNLeg::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyLocMNLeg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyLocMNLeg";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", TcoMrefWidth)) add(TCOMREFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLp0Width", TcoLp0Width)) add(TCOLP0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLp1Width", TcoLp1Width)) add(TCOLP1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLphWidth", TcoLphWidth)) add(TCOLPHWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLthWidth", TcoLthWidth)) add(TCOLTHWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXp0Width", TcoXp0Width)) add(TCOXP0WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXp1Width", TcoXp1Width)) add(TCOXP1WIDTH);
	};

	return basefound;
};

void PnlBrlyLocMNLeg::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLocMNLeg";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TcoMrefWidth"] = TcoMrefWidth;
	me["TcoLp0Width"] = TcoLp0Width;
	me["TcoLp1Width"] = TcoLp1Width;
	me["TcoLphWidth"] = TcoLphWidth;
	me["TcoLthWidth"] = TcoLthWidth;
	me["TcoXp0Width"] = TcoXp0Width;
	me["TcoXp1Width"] = TcoXp1Width;
};

void PnlBrlyLocMNLeg::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLocMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyLocMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLp0Width", TcoLp0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoLp1Width", TcoLp1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoLphWidth", TcoLphWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLthWidth", TcoLthWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoXp0Width", TcoXp0Width);
		writeUintAttr(wr, itemtag, "sref", "TcoXp1Width", TcoXp1Width);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocMNLeg::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoMrefWidth == comp->TcoMrefWidth) insert(items, TCOMREFWIDTH);
	if (TcoLp0Width == comp->TcoLp0Width) insert(items, TCOLP0WIDTH);
	if (TcoLp1Width == comp->TcoLp1Width) insert(items, TCOLP1WIDTH);
	if (TcoLphWidth == comp->TcoLphWidth) insert(items, TCOLPHWIDTH);
	if (TcoLthWidth == comp->TcoLthWidth) insert(items, TCOLTHWIDTH);
	if (TcoXp0Width == comp->TcoXp0Width) insert(items, TCOXP0WIDTH);
	if (TcoXp1Width == comp->TcoXp1Width) insert(items, TCOXP1WIDTH);

	return(items);
};

set<uint> PnlBrlyLocMNLeg::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOMREFWIDTH, TCOLP0WIDTH, TCOLP1WIDTH, TCOLPHWIDTH, TCOLTHWIDTH, TCOXP0WIDTH, TCOXP1WIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocMNLeg::Tag
 ******************************************************************************/

void PnlBrlyLocMNLeg::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLocMNLeg";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Legs within visibility range";
		me["TcoMref"] = "Leg";
		me["TcoLp0"] = "Vis. from [\\u00b0]";
		me["TcoLp1"] = "Vis. to [\\u00b0]";
		me["TcoLph"] = "Azimuth [\\u00b0]";
		me["TcoLth"] = "Elevation [\\u00b0]";
		me["TcoXp0"] = "XVisLegphi0";
		me["TcoXp1"] = "XVisLegphi1";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Strecken im Bereich der Sichtbarkeit";
		me["TcoMref"] = "Strecke";
		me["TcoLp0"] = "Sichtb. von [\\u00b0]";
		me["TcoLp1"] = "Sichtb. bis [\\u00b0]";
		me["TcoLph"] = "Azimut [\\u00b0]";
		me["TcoLth"] = "Elevation [\\u00b0]";
		me["TcoXp0"] = "XVisLegphi0";
		me["TcoXp1"] = "XVisLegphi1";
	};
	me["TxtRecord1"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::REC, ixBrlyVLocale));
	me["TxtRecord2"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale));
	me["Trs"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...";
	me["TxtShowing1"] = VecBrlyVTag::getTitle(VecBrlyVTag::SHOWSHORT, ixBrlyVLocale);
	me["TxtShowing2"] = VecBrlyVTag::getTitle(VecBrlyVTag::EMPSHORT, ixBrlyVLocale);
};

void PnlBrlyLocMNLeg::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLocMNLeg";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyLocMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Legs within visibility range");
			writeStringAttr(wr, itemtag, "sref", "TcoMref", "Leg");
			writeStringAttr(wr, itemtag, "sref", "TcoLp0", "Vis. from [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoLp1", "Vis. to [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoLph", "Azimuth [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoLth", "Elevation [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoXp0", "XVisLegphi0");
			writeStringAttr(wr, itemtag, "sref", "TcoXp1", "XVisLegphi1");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Strecken im Bereich der Sichtbarkeit");
			writeStringAttr(wr, itemtag, "sref", "TcoMref", "Strecke");
			writeStringAttr(wr, itemtag, "sref", "TcoLp0", "Sichtb. von [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoLp1", "Sichtb. bis [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoLph", "Azimut [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoLth", "Elevation [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "TcoXp0", "XVisLegphi0");
			writeStringAttr(wr, itemtag, "sref", "TcoXp1", "XVisLegphi1");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::REC, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecBrlyVTag::getTitle(VecBrlyVTag::SHOWSHORT, ixBrlyVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecBrlyVTag::getTitle(VecBrlyVTag::EMPSHORT, ixBrlyVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocMNLeg::DpchAppData
 ******************************************************************************/

PnlBrlyLocMNLeg::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCMNLEGDATA)
		{
};

string PnlBrlyLocMNLeg::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMNLeg::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyLocMNLegData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (stgiac.readJSON(me, true)) add(STGIAC);
		if (stgiacqry.readJSON(me, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryBrlyLocMNLeg::StgIac();
	};
};

void PnlBrlyLocMNLeg::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLocMNLegData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryBrlyLocMNLeg::StgIac();
	};
};

/******************************************************************************
 class PnlBrlyLocMNLeg::DpchAppDo
 ******************************************************************************/

PnlBrlyLocMNLeg::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCMNLEGDO)
		{
	ixVDo = 0;
};

string PnlBrlyLocMNLeg::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocMNLeg::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyLocMNLegDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyLocMNLeg::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLocMNLegDo");
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
 class PnlBrlyLocMNLeg::DpchEngData
 ******************************************************************************/

PnlBrlyLocMNLeg::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListBrlyQLocMNLeg* rst
			, QryBrlyLocMNLeg::StatShr* statshrqry
			, QryBrlyLocMNLeg::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCMNLEGDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFCSIQST, STATAPP, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlBrlyLocMNLeg::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(STATAPP)) ss.push_back("statapp");
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

void PnlBrlyLocMNLeg::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlBrlyLocMNLeg::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyLocMNLegData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFCSIQST)) feedFCsiQst.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STGIAC)) stgiac.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
	if (has(RST)) rst.writeJSON(me);
	if (has(STATAPPQRY)) QryBrlyLocMNLeg::StatApp::writeJSON(me);
	if (has(STATSHRQRY)) statshrqry.writeJSON(me);
	if (has(STGIACQRY)) stgiacqry.writeJSON(me);
};

void PnlBrlyLocMNLeg::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLocMNLegData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryBrlyLocMNLeg::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
