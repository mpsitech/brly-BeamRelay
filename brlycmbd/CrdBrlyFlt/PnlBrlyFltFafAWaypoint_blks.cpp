/**
	* \file PnlBrlyFltFafAWaypoint_blks.cpp
	* job handler for job PnlBrlyFltFafAWaypoint (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::VecVDo
 ******************************************************************************/

uint PnlBrlyFltFafAWaypoint::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butupclick") return BUTUPCLICK;
	if (s == "butdownclick") return BUTDOWNCLICK;
	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyFltFafAWaypoint::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUPCLICK) return("ButUpClick");
	if (ix == BUTDOWNCLICK) return("ButDownClick");
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::ContInf
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlBrlyFltFafAWaypoint::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyFltFafAWaypoint";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFCsiQst"] = numFCsiQst;
};

void PnlBrlyFltFafAWaypoint::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyFltFafAWaypoint";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyFltFafAWaypoint";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFltFafAWaypoint::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlyFltFafAWaypoint::ContInf::diff(
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
 class PnlBrlyFltFafAWaypoint::StatApp
 ******************************************************************************/

void PnlBrlyFltFafAWaypoint::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyFltFafAWaypoint";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
};

void PnlBrlyFltFafAWaypoint::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyFltFafAWaypoint";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyFltFafAWaypoint";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::StatShr
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::StatShr::StatShr(
			const bool ButUpAvail
			, const bool ButUpActive
			, const bool ButDownAvail
			, const bool ButDownActive
			, const bool ButNewAvail
			, const bool ButDuplicateAvail
			, const bool ButDuplicateActive
			, const bool ButDeleteAvail
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ButUpAvail = ButUpAvail;
	this->ButUpActive = ButUpActive;
	this->ButDownAvail = ButDownAvail;
	this->ButDownActive = ButDownActive;
	this->ButNewAvail = ButNewAvail;
	this->ButDuplicateAvail = ButDuplicateAvail;
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteAvail = ButDeleteAvail;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE};
};

void PnlBrlyFltFafAWaypoint::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyFltFafAWaypoint";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButUpAvail"] = ButUpAvail;
	me["ButUpActive"] = ButUpActive;
	me["ButDownAvail"] = ButDownAvail;
	me["ButDownActive"] = ButDownActive;
	me["ButNewAvail"] = ButNewAvail;
	me["ButDuplicateAvail"] = ButDuplicateAvail;
	me["ButDuplicateActive"] = ButDuplicateActive;
	me["ButDeleteAvail"] = ButDeleteAvail;
	me["ButDeleteActive"] = ButDeleteActive;
};

void PnlBrlyFltFafAWaypoint::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyFltFafAWaypoint";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyFltFafAWaypoint";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButUpAvail", ButUpAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUpActive", ButUpActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDownAvail", ButDownAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDownActive", ButDownActive);
		writeBoolAttr(wr, itemtag, "sref", "ButNewAvail", ButNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateAvail", ButDuplicateAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateActive", ButDuplicateActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteAvail", ButDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFltFafAWaypoint::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUpAvail == comp->ButUpAvail) insert(items, BUTUPAVAIL);
	if (ButUpActive == comp->ButUpActive) insert(items, BUTUPACTIVE);
	if (ButDownAvail == comp->ButDownAvail) insert(items, BUTDOWNAVAIL);
	if (ButDownActive == comp->ButDownActive) insert(items, BUTDOWNACTIVE);
	if (ButNewAvail == comp->ButNewAvail) insert(items, BUTNEWAVAIL);
	if (ButDuplicateAvail == comp->ButDuplicateAvail) insert(items, BUTDUPLICATEAVAIL);
	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteAvail == comp->ButDeleteAvail) insert(items, BUTDELETEAVAIL);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlBrlyFltFafAWaypoint::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::StgIac
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::StgIac::StgIac(
			const uint TcoTmsWidth
			, const uint TcoLatWidth
			, const uint TcoLonWidth
			, const uint TcoGspWidth
			, const uint TcoAltWidth
			, const uint TcoAstWidth
			, const uint TcoUtyWidth
			, const uint TcoAchWidth
		) :
			Block()
		{
	this->TcoTmsWidth = TcoTmsWidth;
	this->TcoLatWidth = TcoLatWidth;
	this->TcoLonWidth = TcoLonWidth;
	this->TcoGspWidth = TcoGspWidth;
	this->TcoAltWidth = TcoAltWidth;
	this->TcoAstWidth = TcoAstWidth;
	this->TcoUtyWidth = TcoUtyWidth;
	this->TcoAchWidth = TcoAchWidth;
	mask = {TCOTMSWIDTH, TCOLATWIDTH, TCOLONWIDTH, TCOGSPWIDTH, TCOALTWIDTH, TCOASTWIDTH, TCOUTYWIDTH, TCOACHWIDTH};
};

bool PnlBrlyFltFafAWaypoint::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacBrlyFltFafAWaypoint"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TcoTmsWidth")) {TcoTmsWidth = me["TcoTmsWidth"].asUInt(); add(TCOTMSWIDTH);};
		if (me.isMember("TcoLatWidth")) {TcoLatWidth = me["TcoLatWidth"].asUInt(); add(TCOLATWIDTH);};
		if (me.isMember("TcoLonWidth")) {TcoLonWidth = me["TcoLonWidth"].asUInt(); add(TCOLONWIDTH);};
		if (me.isMember("TcoGspWidth")) {TcoGspWidth = me["TcoGspWidth"].asUInt(); add(TCOGSPWIDTH);};
		if (me.isMember("TcoAltWidth")) {TcoAltWidth = me["TcoAltWidth"].asUInt(); add(TCOALTWIDTH);};
		if (me.isMember("TcoAstWidth")) {TcoAstWidth = me["TcoAstWidth"].asUInt(); add(TCOASTWIDTH);};
		if (me.isMember("TcoUtyWidth")) {TcoUtyWidth = me["TcoUtyWidth"].asUInt(); add(TCOUTYWIDTH);};
		if (me.isMember("TcoAchWidth")) {TcoAchWidth = me["TcoAchWidth"].asUInt(); add(TCOACHWIDTH);};
	};

	return basefound;
};

bool PnlBrlyFltFafAWaypoint::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyFltFafAWaypoint");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyFltFafAWaypoint";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTmsWidth", TcoTmsWidth)) add(TCOTMSWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLatWidth", TcoLatWidth)) add(TCOLATWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLonWidth", TcoLonWidth)) add(TCOLONWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoGspWidth", TcoGspWidth)) add(TCOGSPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAltWidth", TcoAltWidth)) add(TCOALTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAstWidth", TcoAstWidth)) add(TCOASTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoUtyWidth", TcoUtyWidth)) add(TCOUTYWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAchWidth", TcoAchWidth)) add(TCOACHWIDTH);
	};

	return basefound;
};

void PnlBrlyFltFafAWaypoint::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyFltFafAWaypoint";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TcoTmsWidth"] = TcoTmsWidth;
	me["TcoLatWidth"] = TcoLatWidth;
	me["TcoLonWidth"] = TcoLonWidth;
	me["TcoGspWidth"] = TcoGspWidth;
	me["TcoAltWidth"] = TcoAltWidth;
	me["TcoAstWidth"] = TcoAstWidth;
	me["TcoUtyWidth"] = TcoUtyWidth;
	me["TcoAchWidth"] = TcoAchWidth;
};

void PnlBrlyFltFafAWaypoint::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyFltFafAWaypoint";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyFltFafAWaypoint";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoTmsWidth", TcoTmsWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLatWidth", TcoLatWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLonWidth", TcoLonWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoGspWidth", TcoGspWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAltWidth", TcoAltWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAstWidth", TcoAstWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoUtyWidth", TcoUtyWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAchWidth", TcoAchWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFltFafAWaypoint::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoTmsWidth == comp->TcoTmsWidth) insert(items, TCOTMSWIDTH);
	if (TcoLatWidth == comp->TcoLatWidth) insert(items, TCOLATWIDTH);
	if (TcoLonWidth == comp->TcoLonWidth) insert(items, TCOLONWIDTH);
	if (TcoGspWidth == comp->TcoGspWidth) insert(items, TCOGSPWIDTH);
	if (TcoAltWidth == comp->TcoAltWidth) insert(items, TCOALTWIDTH);
	if (TcoAstWidth == comp->TcoAstWidth) insert(items, TCOASTWIDTH);
	if (TcoUtyWidth == comp->TcoUtyWidth) insert(items, TCOUTYWIDTH);
	if (TcoAchWidth == comp->TcoAchWidth) insert(items, TCOACHWIDTH);

	return(items);
};

set<uint> PnlBrlyFltFafAWaypoint::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOTMSWIDTH, TCOLATWIDTH, TCOLONWIDTH, TCOGSPWIDTH, TCOALTWIDTH, TCOASTWIDTH, TCOUTYWIDTH, TCOACHWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::Tag
 ******************************************************************************/

void PnlBrlyFltFafAWaypoint::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyFltFafAWaypoint";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Waypoints";
		me["TcoTms"] = "Timestamp";
		me["TcoLat"] = "Latitude";
		me["TcoLon"] = "Longitude";
		me["TcoGsp"] = "Groundspeed";
		me["TcoAlt"] = "Altitude";
		me["TcoAst"] = "AltitudeStatus";
		me["TcoUty"] = "UpdateType";
		me["TcoAch"] = "AltitudeChange";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Wegpunkte";
		me["TcoTms"] = "Timestamp";
		me["TcoLat"] = "Latitude";
		me["TcoLon"] = "Longitude";
		me["TcoGsp"] = "Groundspeed";
		me["TcoAlt"] = "Altitude";
		me["TcoAst"] = "AltitudeStatus";
		me["TcoUty"] = "UpdateType";
		me["TcoAch"] = "AltitudeChange";
	};
	me["TxtRecord1"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::REC, ixBrlyVLocale));
	me["TxtRecord2"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale));
	me["Trs"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...";
	me["TxtShowing1"] = VecBrlyVTag::getTitle(VecBrlyVTag::SHOWSHORT, ixBrlyVLocale);
	me["TxtShowing2"] = VecBrlyVTag::getTitle(VecBrlyVTag::EMPSHORT, ixBrlyVLocale);
};

void PnlBrlyFltFafAWaypoint::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyFltFafAWaypoint";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyFltFafAWaypoint";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Waypoints");
			writeStringAttr(wr, itemtag, "sref", "TcoTms", "Timestamp");
			writeStringAttr(wr, itemtag, "sref", "TcoLat", "Latitude");
			writeStringAttr(wr, itemtag, "sref", "TcoLon", "Longitude");
			writeStringAttr(wr, itemtag, "sref", "TcoGsp", "Groundspeed");
			writeStringAttr(wr, itemtag, "sref", "TcoAlt", "Altitude");
			writeStringAttr(wr, itemtag, "sref", "TcoAst", "AltitudeStatus");
			writeStringAttr(wr, itemtag, "sref", "TcoUty", "UpdateType");
			writeStringAttr(wr, itemtag, "sref", "TcoAch", "AltitudeChange");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Wegpunkte");
			writeStringAttr(wr, itemtag, "sref", "TcoTms", "Timestamp");
			writeStringAttr(wr, itemtag, "sref", "TcoLat", "Latitude");
			writeStringAttr(wr, itemtag, "sref", "TcoLon", "Longitude");
			writeStringAttr(wr, itemtag, "sref", "TcoGsp", "Groundspeed");
			writeStringAttr(wr, itemtag, "sref", "TcoAlt", "Altitude");
			writeStringAttr(wr, itemtag, "sref", "TcoAst", "AltitudeStatus");
			writeStringAttr(wr, itemtag, "sref", "TcoUty", "UpdateType");
			writeStringAttr(wr, itemtag, "sref", "TcoAch", "AltitudeChange");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::REC, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecBrlyVTag::getTitle(VecBrlyVTag::SHOWSHORT, ixBrlyVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecBrlyVTag::getTitle(VecBrlyVTag::EMPSHORT, ixBrlyVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::DpchAppData
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTFAFAWAYPOINTDATA)
		{
};

string PnlBrlyFltFafAWaypoint::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltFafAWaypoint::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyFltFafAWaypointData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (stgiac.readJSON(me, true)) add(STGIAC);
		if (stgiacqry.readJSON(me, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryBrlyFltFafAWaypoint::StgIac();
	};
};

void PnlBrlyFltFafAWaypoint::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyFltFafAWaypointData");
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
		stgiacqry = QryBrlyFltFafAWaypoint::StgIac();
	};
};

/******************************************************************************
 class PnlBrlyFltFafAWaypoint::DpchAppDo
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTFAFAWAYPOINTDO)
		{
	ixVDo = 0;
};

string PnlBrlyFltFafAWaypoint::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltFafAWaypoint::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyFltFafAWaypointDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyFltFafAWaypoint::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyFltFafAWaypointDo");
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
 class PnlBrlyFltFafAWaypoint::DpchEngData
 ******************************************************************************/

PnlBrlyFltFafAWaypoint::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListBrlyQFltFafAWaypoint* rst
			, QryBrlyFltFafAWaypoint::StatShr* statshrqry
			, QryBrlyFltFafAWaypoint::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYFLTFAFAWAYPOINTDATA, jref)
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

string PnlBrlyFltFafAWaypoint::DpchEngData::getSrefsMask() {
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

void PnlBrlyFltFafAWaypoint::DpchEngData::merge(
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

void PnlBrlyFltFafAWaypoint::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyFltFafAWaypointData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFCSIQST)) feedFCsiQst.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STGIAC)) stgiac.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
	if (has(RST)) rst.writeJSON(me);
	if (has(STATAPPQRY)) QryBrlyFltFafAWaypoint::StatApp::writeJSON(me);
	if (has(STATSHRQRY)) statshrqry.writeJSON(me);
	if (has(STGIACQRY)) stgiacqry.writeJSON(me);
};

void PnlBrlyFltFafAWaypoint::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyFltFafAWaypointData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryBrlyFltFafAWaypoint::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
