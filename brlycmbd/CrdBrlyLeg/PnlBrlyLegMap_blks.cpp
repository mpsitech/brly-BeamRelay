/**
	* \file PnlBrlyLegMap_blks.cpp
	* job handler for job PnlBrlyLegMap (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyLegMap::VecVDo
 ******************************************************************************/

uint PnlBrlyLegMap::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "buthomeclick") return BUTHOMECLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyLegMap::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTHOMECLICK) return("ButHomeClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLegMap::VecVSge
 ******************************************************************************/

uint PnlBrlyLegMap::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "mapgen") return MAPGEN;

	return(0);
};

string PnlBrlyLegMap::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == MAPGEN) return("mapgen");

	return("");
};

void PnlBrlyLegMap::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class PnlBrlyLegMap::ContIac
 ******************************************************************************/

PnlBrlyLegMap::ContIac::ContIac(
			const double SldH
			, const double SldV
			, const double SldScl
		) :
			Block()
		{
	this->SldH = SldH;
	this->SldV = SldV;
	this->SldScl = SldScl;

	mask = {SLDH, SLDV, SLDSCL};
};

bool PnlBrlyLegMap::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyLegMap"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("SldH")) {SldH = me["SldH"].asDouble(); add(SLDH);};
		if (me.isMember("SldV")) {SldV = me["SldV"].asDouble(); add(SLDV);};
		if (me.isMember("SldScl")) {SldScl = me["SldScl"].asDouble(); add(SLDSCL);};
	};

	return basefound;
};

bool PnlBrlyLegMap::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyLegMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyLegMap";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldH", SldH)) add(SLDH);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldV", SldV)) add(SLDV);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldScl", SldScl)) add(SLDSCL);
	};

	return basefound;
};

void PnlBrlyLegMap::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyLegMap";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["SldH"] = SldH;
	me["SldV"] = SldV;
	me["SldScl"] = SldScl;
};

void PnlBrlyLegMap::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyLegMap";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyLegMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldH", SldH);
		writeDoubleAttr(wr, itemtag, "sref", "SldV", SldV);
		writeDoubleAttr(wr, itemtag, "sref", "SldScl", SldScl);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegMap::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldH, comp->SldH) < 1.0e-4) insert(items, SLDH);
	if (compareDouble(SldV, comp->SldV) < 1.0e-4) insert(items, SLDV);
	if (compareDouble(SldScl, comp->SldScl) < 1.0e-4) insert(items, SLDSCL);

	return(items);
};

set<uint> PnlBrlyLegMap::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDH, SLDV, SLDSCL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegMap::ContInf
 ******************************************************************************/

PnlBrlyLegMap::ContInf::ContInf(
			const uint numFSge
			, const string& Dld
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->Dld = Dld;

	mask = {NUMFSGE, DLD};
};

void PnlBrlyLegMap::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLegMap";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
	me["Dld"] = Dld;
};

void PnlBrlyLegMap::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLegMap";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyLegMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegMap::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> PnlBrlyLegMap::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, DLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegMap::StatShr
 ******************************************************************************/

PnlBrlyLegMap::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const double SldHMin
			, const double SldHMax
			, const double SldVMin
			, const double SldVMax
			, const double SldSclMin
			, const double SldSclMax
			, const double SldSclRast
		) :
			Block()
		{
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->SldHMin = SldHMin;
	this->SldHMax = SldHMax;
	this->SldVMin = SldVMin;
	this->SldVMax = SldVMax;
	this->SldSclMin = SldSclMin;
	this->SldSclMax = SldSclMax;
	this->SldSclRast = SldSclRast;

	mask = {IXBRLYVEXPSTATE, SLDHMIN, SLDHMAX, SLDVMIN, SLDVMAX, SLDSCLMIN, SLDSCLMAX, SLDSCLRAST};
};

void PnlBrlyLegMap::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLegMap";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["SldHMin"] = SldHMin;
	me["SldHMax"] = SldHMax;
	me["SldVMin"] = SldVMin;
	me["SldVMax"] = SldVMax;
	me["SldSclMin"] = SldSclMin;
	me["SldSclMax"] = SldSclMax;
	me["SldSclRast"] = SldSclRast;
};

void PnlBrlyLegMap::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLegMap";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyLegMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeDoubleAttr(wr, itemtag, "sref", "SldHMin", SldHMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldHMax", SldHMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldVMin", SldVMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldVMax", SldVMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldSclMin", SldSclMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldSclMax", SldSclMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldSclRast", SldSclRast);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegMap::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (compareDouble(SldHMin, comp->SldHMin) < 1.0e-4) insert(items, SLDHMIN);
	if (compareDouble(SldHMax, comp->SldHMax) < 1.0e-4) insert(items, SLDHMAX);
	if (compareDouble(SldVMin, comp->SldVMin) < 1.0e-4) insert(items, SLDVMIN);
	if (compareDouble(SldVMax, comp->SldVMax) < 1.0e-4) insert(items, SLDVMAX);
	if (compareDouble(SldSclMin, comp->SldSclMin) < 1.0e-4) insert(items, SLDSCLMIN);
	if (compareDouble(SldSclMax, comp->SldSclMax) < 1.0e-4) insert(items, SLDSCLMAX);
	if (compareDouble(SldSclRast, comp->SldSclRast) < 1.0e-4) insert(items, SLDSCLRAST);

	return(items);
};

set<uint> PnlBrlyLegMap::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, SLDHMIN, SLDHMAX, SLDVMIN, SLDVMAX, SLDSCLMIN, SLDSCLMAX, SLDSCLRAST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegMap::StgIac
 ******************************************************************************/

PnlBrlyLegMap::StgIac::StgIac(
			const uint width
			, const uint height
		) :
			Block()
		{
	this->width = width;
	this->height = height;
	mask = {WIDTH, HEIGHT};
};

bool PnlBrlyLegMap::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacBrlyLegMap"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("width")) {width = me["width"].asUInt(); add(WIDTH);};
		if (me.isMember("height")) {height = me["height"].asUInt(); add(HEIGHT);};
	};

	return basefound;
};

bool PnlBrlyLegMap::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyLegMap");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyLegMap";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "width", width)) add(WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "height", height)) add(HEIGHT);
	};

	return basefound;
};

void PnlBrlyLegMap::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLegMap";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["width"] = width;
	me["height"] = height;
};

void PnlBrlyLegMap::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyLegMap";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyLegMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "width", width);
		writeUintAttr(wr, itemtag, "sref", "height", height);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLegMap::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (width == comp->width) insert(items, WIDTH);
	if (height == comp->height) insert(items, HEIGHT);

	return(items);
};

set<uint> PnlBrlyLegMap::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {WIDTH, HEIGHT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLegMap::Tag
 ******************************************************************************/

void PnlBrlyLegMap::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLegMap";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Map";
		me["ButDetach"] = "";
		me["ButAttach"] = "";
		me["ButHome"] = "";
		me["CptScl"] = "Scale";
		me["ButRefresh"] = "";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Landkarte";
		me["ButDetach"] = "";
		me["ButAttach"] = "";
		me["ButHome"] = "";
		me["CptScl"] = "Skalierung";
		me["ButRefresh"] = "";
	};
	me["Dld"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DOWNLOAD, ixBrlyVLocale));
};

void PnlBrlyLegMap::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLegMap";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyLegMap";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Map");
			writeStringAttr(wr, itemtag, "sref", "ButDetach", "");
			writeStringAttr(wr, itemtag, "sref", "ButAttach", "");
			writeStringAttr(wr, itemtag, "sref", "ButHome", "");
			writeStringAttr(wr, itemtag, "sref", "CptScl", "Scale");
			writeStringAttr(wr, itemtag, "sref", "ButRefresh", "");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Landkarte");
			writeStringAttr(wr, itemtag, "sref", "ButDetach", "");
			writeStringAttr(wr, itemtag, "sref", "ButAttach", "");
			writeStringAttr(wr, itemtag, "sref", "ButHome", "");
			writeStringAttr(wr, itemtag, "sref", "CptScl", "Skalierung");
			writeStringAttr(wr, itemtag, "sref", "ButRefresh", "");
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DOWNLOAD, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegMap::DpchAppData
 ******************************************************************************/

PnlBrlyLegMap::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGMAPDATA)
		{
};

string PnlBrlyLegMap::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIACQRYLEG)) ss.push_back("stgiacqryleg");
	if (has(STGIACQRYLOCATION)) ss.push_back("stgiacqrylocation");
	if (has(STGIAC)) ss.push_back("stgiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegMap::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyLegMapData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
		if (stgiacqryleg.readJSON(me, true)) add(STGIACQRYLEG);
		if (stgiacqrylocation.readJSON(me, true)) add(STGIACQRYLOCATION);
		if (stgiac.readJSON(me, true)) add(STGIAC);
	} else {
		contiac = ContIac();
		stgiacqryleg = QryBrlyLegMapLeg::StgIac();
		stgiacqrylocation = QryBrlyLegMapLocation::StgIac();
		stgiac = StgIac();
	};
};

void PnlBrlyLegMap::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLegMapData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (stgiacqryleg.readXML(docctx, basexpath, true)) add(STGIACQRYLEG);
		if (stgiacqrylocation.readXML(docctx, basexpath, true)) add(STGIACQRYLOCATION);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
	} else {
		contiac = ContIac();
		stgiacqryleg = QryBrlyLegMapLeg::StgIac();
		stgiacqrylocation = QryBrlyLegMapLocation::StgIac();
		stgiac = StgIac();
	};
};

/******************************************************************************
 class PnlBrlyLegMap::DpchAppDo
 ******************************************************************************/

PnlBrlyLegMap::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLEGMAPDO)
		{
	ixVDo = 0;
};

string PnlBrlyLegMap::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegMap::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyLegMapDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyLegMap::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLegMapDo");
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
 class PnlBrlyLegMap::DpchEngData
 ******************************************************************************/

PnlBrlyLegMap::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, ListBrlyQLegMapLeg* rstleg
			, ListBrlyQLegMapLocation* rstlocation
			, QryBrlyLegMapLeg::StatShr* statshrqryleg
			, QryBrlyLegMapLocation::StatShr* statshrqrylocation
			, QryBrlyLegMapLeg::StgIac* stgiacqryleg
			, QryBrlyLegMapLocation::StgIac* stgiacqrylocation
			, StgIac* stgiac
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGMAPDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFSGE, STATSHR, TAG, RSTLEG, RSTLOCATION, STATSHRQRYLEG, STATSHRQRYLOCATION, STGIACQRYLEG, STGIACQRYLOCATION, STGIAC};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, RSTLEG) && rstleg) this->rstleg = *rstleg;
	if (find(this->mask, RSTLOCATION) && rstlocation) this->rstlocation = *rstlocation;
	if (find(this->mask, STATSHRQRYLEG) && statshrqryleg) this->statshrqryleg = *statshrqryleg;
	if (find(this->mask, STATSHRQRYLOCATION) && statshrqrylocation) this->statshrqrylocation = *statshrqrylocation;
	if (find(this->mask, STGIACQRYLEG) && stgiacqryleg) this->stgiacqryleg = *stgiacqryleg;
	if (find(this->mask, STGIACQRYLOCATION) && stgiacqrylocation) this->stgiacqrylocation = *stgiacqrylocation;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
};

string PnlBrlyLegMap::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");
	if (has(RSTLEG)) ss.push_back("rstleg");
	if (has(RSTLOCATION)) ss.push_back("rstlocation");
	if (has(STATSHRQRYLEG)) ss.push_back("statshrqryleg");
	if (has(STATSHRQRYLOCATION)) ss.push_back("statshrqrylocation");
	if (has(STGIACQRYLEG)) ss.push_back("stgiacqryleg");
	if (has(STGIACQRYLOCATION)) ss.push_back("stgiacqrylocation");
	if (has(STGIAC)) ss.push_back("stgiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegMap::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RSTLEG)) {rstleg = src->rstleg; add(RSTLEG);};
	if (src->has(RSTLOCATION)) {rstlocation = src->rstlocation; add(RSTLOCATION);};
	if (src->has(STATSHRQRYLEG)) {statshrqryleg = src->statshrqryleg; add(STATSHRQRYLEG);};
	if (src->has(STATSHRQRYLOCATION)) {statshrqrylocation = src->statshrqrylocation; add(STATSHRQRYLOCATION);};
	if (src->has(STGIACQRYLEG)) {stgiacqryleg = src->stgiacqryleg; add(STGIACQRYLEG);};
	if (src->has(STGIACQRYLOCATION)) {stgiacqrylocation = src->stgiacqrylocation; add(STGIACQRYLOCATION);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
};

void PnlBrlyLegMap::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyLegMapData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
	if (has(RSTLEG)) rstleg.writeJSON(me);
	if (has(RSTLOCATION)) rstlocation.writeJSON(me);
	if (has(STATSHRQRYLEG)) statshrqryleg.writeJSON(me);
	if (has(STATSHRQRYLOCATION)) statshrqrylocation.writeJSON(me);
	if (has(STGIACQRYLEG)) stgiacqryleg.writeJSON(me);
	if (has(STGIACQRYLOCATION)) stgiacqrylocation.writeJSON(me);
	if (has(STGIAC)) stgiac.writeJSON(me);
};

void PnlBrlyLegMap::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLegMapData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(RSTLEG)) rstleg.writeXML(wr);
		if (has(RSTLOCATION)) rstlocation.writeXML(wr);
		if (has(STATSHRQRYLEG)) statshrqryleg.writeXML(wr);
		if (has(STATSHRQRYLOCATION)) statshrqrylocation.writeXML(wr);
		if (has(STGIACQRYLEG)) stgiacqryleg.writeXML(wr);
		if (has(STGIACQRYLOCATION)) stgiacqrylocation.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLegMap::DpchEngImage
 ******************************************************************************/

PnlBrlyLegMap::DpchEngImage::DpchEngImage(
			const ubigint jref
			, ListBrlyQLegMapLeg* rstleg
			, ListBrlyQLegMapLocation* rstlocation
			, QryBrlyLegMapLeg::StatShr* statshrqryleg
			, QryBrlyLegMapLocation::StatShr* statshrqrylocation
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLEGMAPIMAGE, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, RSTLEG, RSTLOCATION, STATSHRQRYLEG, STATSHRQRYLOCATION};
	else this->mask = mask;

	if (find(this->mask, RSTLEG) && rstleg) this->rstleg = *rstleg;
	if (find(this->mask, RSTLOCATION) && rstlocation) this->rstlocation = *rstlocation;
	if (find(this->mask, STATSHRQRYLEG) && statshrqryleg) this->statshrqryleg = *statshrqryleg;
	if (find(this->mask, STATSHRQRYLOCATION) && statshrqrylocation) this->statshrqrylocation = *statshrqrylocation;
};

string PnlBrlyLegMap::DpchEngImage::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(RSTLEG)) ss.push_back("rstleg");
	if (has(RSTLOCATION)) ss.push_back("rstlocation");
	if (has(STATSHRQRYLEG)) ss.push_back("statshrqryleg");
	if (has(STATSHRQRYLOCATION)) ss.push_back("statshrqrylocation");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLegMap::DpchEngImage::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngImage* src = (DpchEngImage*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(RSTLEG)) {rstleg = src->rstleg; add(RSTLEG);};
	if (src->has(RSTLOCATION)) {rstlocation = src->rstlocation; add(RSTLOCATION);};
	if (src->has(STATSHRQRYLEG)) {statshrqryleg = src->statshrqryleg; add(STATSHRQRYLEG);};
	if (src->has(STATSHRQRYLOCATION)) {statshrqrylocation = src->statshrqrylocation; add(STATSHRQRYLOCATION);};
};

void PnlBrlyLegMap::DpchEngImage::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyLegMapImage"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(RSTLEG)) rstleg.writeJSON(me);
	if (has(RSTLOCATION)) rstlocation.writeJSON(me);
	if (has(STATSHRQRYLEG)) statshrqryleg.writeJSON(me);
	if (has(STATSHRQRYLOCATION)) statshrqrylocation.writeJSON(me);
};

void PnlBrlyLegMap::DpchEngImage::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLegMapImage");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(RSTLEG)) rstleg.writeXML(wr);
		if (has(RSTLOCATION)) rstlocation.writeXML(wr);
		if (has(STATSHRQRYLEG)) statshrqryleg.writeXML(wr);
		if (has(STATSHRQRYLOCATION)) statshrqrylocation.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
