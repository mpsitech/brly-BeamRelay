/**
	* \file PnlBrlyNavConnect_blks.cpp
	* job handler for job PnlBrlyNavConnect (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyNavConnect::VecVDo
 ******************************************************************************/

uint PnlBrlyNavConnect::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butconviewclick") return BUTCONVIEWCLICK;
	if (s == "butconnewcrdclick") return BUTCONNEWCRDCLICK;
	if (s == "butrlyviewclick") return BUTRLYVIEWCLICK;
	if (s == "butrlynewcrdclick") return BUTRLYNEWCRDCLICK;

	return(0);
};

string PnlBrlyNavConnect::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCONVIEWCLICK) return("ButConViewClick");
	if (ix == BUTCONNEWCRDCLICK) return("ButConNewcrdClick");
	if (ix == BUTRLYVIEWCLICK) return("ButRlyViewClick");
	if (ix == BUTRLYNEWCRDCLICK) return("ButRlyNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlBrlyNavConnect::ContIac
 ******************************************************************************/

PnlBrlyNavConnect::ContIac::ContIac(
			const uint numFLstCon
			, const uint numFLstRly
		) :
			Block()
		{
	this->numFLstCon = numFLstCon;
	this->numFLstRly = numFLstRly;

	mask = {NUMFLSTCON, NUMFLSTRLY};
};

bool PnlBrlyNavConnect::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyNavConnect"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstCon")) {numFLstCon = me["numFLstCon"].asUInt(); add(NUMFLSTCON);};
		if (me.isMember("numFLstRly")) {numFLstRly = me["numFLstRly"].asUInt(); add(NUMFLSTRLY);};
	};

	return basefound;
};

bool PnlBrlyNavConnect::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyNavConnect");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyNavConnect";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCon", numFLstCon)) add(NUMFLSTCON);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRly", numFLstRly)) add(NUMFLSTRLY);
	};

	return basefound;
};

void PnlBrlyNavConnect::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyNavConnect";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstCon"] = numFLstCon;
	me["numFLstRly"] = numFLstRly;
};

void PnlBrlyNavConnect::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyNavConnect";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyNavConnect";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstCon", numFLstCon);
		writeUintAttr(wr, itemtag, "sref", "numFLstRly", numFLstRly);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyNavConnect::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstCon == comp->numFLstCon) insert(items, NUMFLSTCON);
	if (numFLstRly == comp->numFLstRly) insert(items, NUMFLSTRLY);

	return(items);
};

set<uint> PnlBrlyNavConnect::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCON, NUMFLSTRLY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavConnect::StatApp
 ******************************************************************************/

void PnlBrlyNavConnect::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
			, const bool LstConAlt
			, const bool LstRlyAlt
			, const uint LstConNumFirstdisp
			, const uint LstRlyNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyNavConnect";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["LstConAlt"] = LstConAlt;
	me["LstRlyAlt"] = LstRlyAlt;
	me["LstConNumFirstdisp"] = LstConNumFirstdisp;
	me["LstRlyNumFirstdisp"] = LstRlyNumFirstdisp;
};

void PnlBrlyNavConnect::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
			, const bool LstConAlt
			, const bool LstRlyAlt
			, const uint LstConNumFirstdisp
			, const uint LstRlyNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyNavConnect";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyNavConnect";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstConAlt", LstConAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstRlyAlt", LstRlyAlt);
		writeUintAttr(wr, itemtag, "sref", "LstConNumFirstdisp", LstConNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstRlyNumFirstdisp", LstRlyNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavConnect::StatShr
 ******************************************************************************/

PnlBrlyNavConnect::StatShr::StatShr(
			const bool LstConAvail
			, const bool ButConViewActive
			, const bool LstRlyAvail
			, const bool ButRlyViewActive
		) :
			Block()
		{
	this->LstConAvail = LstConAvail;
	this->ButConViewActive = ButConViewActive;
	this->LstRlyAvail = LstRlyAvail;
	this->ButRlyViewActive = ButRlyViewActive;

	mask = {LSTCONAVAIL, BUTCONVIEWACTIVE, LSTRLYAVAIL, BUTRLYVIEWACTIVE};
};

void PnlBrlyNavConnect::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyNavConnect";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstConAvail"] = LstConAvail;
	me["ButConViewActive"] = ButConViewActive;
	me["LstRlyAvail"] = LstRlyAvail;
	me["ButRlyViewActive"] = ButRlyViewActive;
};

void PnlBrlyNavConnect::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyNavConnect";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyNavConnect";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstConAvail", LstConAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButConViewActive", ButConViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstRlyAvail", LstRlyAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRlyViewActive", ButRlyViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyNavConnect::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstConAvail == comp->LstConAvail) insert(items, LSTCONAVAIL);
	if (ButConViewActive == comp->ButConViewActive) insert(items, BUTCONVIEWACTIVE);
	if (LstRlyAvail == comp->LstRlyAvail) insert(items, LSTRLYAVAIL);
	if (ButRlyViewActive == comp->ButRlyViewActive) insert(items, BUTRLYVIEWACTIVE);

	return(items);
};

set<uint> PnlBrlyNavConnect::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTCONAVAIL, BUTCONVIEWACTIVE, LSTRLYAVAIL, BUTRLYVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavConnect::Tag
 ******************************************************************************/

void PnlBrlyNavConnect::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyNavConnect";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Connection module";
		me["CptCon"] = "connections";
		me["CptRly"] = "relays";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Verbindungsdaten";
		me["CptCon"] = "Verbindungen";
		me["CptRly"] = "Verbindungsketten";
	};
};

void PnlBrlyNavConnect::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyNavConnect";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyNavConnect";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Connection module");
			writeStringAttr(wr, itemtag, "sref", "CptCon", "connections");
			writeStringAttr(wr, itemtag, "sref", "CptRly", "relays");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Verbindungsdaten");
			writeStringAttr(wr, itemtag, "sref", "CptCon", "Verbindungen");
			writeStringAttr(wr, itemtag, "sref", "CptRly", "Verbindungsketten");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavConnect::DpchAppData
 ******************************************************************************/

PnlBrlyNavConnect::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVCONNECTDATA)
		{
};

string PnlBrlyNavConnect::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavConnect::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyNavConnectData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlBrlyNavConnect::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyNavConnectData");
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
 class PnlBrlyNavConnect::DpchAppDo
 ******************************************************************************/

PnlBrlyNavConnect::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVCONNECTDO)
		{
	ixVDo = 0;
};

string PnlBrlyNavConnect::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavConnect::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyNavConnectDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyNavConnect::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyNavConnectDo");
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
 class PnlBrlyNavConnect::DpchEngData
 ******************************************************************************/

PnlBrlyNavConnect::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstCon
			, Feed* feedFLstRly
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYNAVCONNECTDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCON, FEEDFLSTRLY, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCON) && feedFLstCon) this->feedFLstCon = *feedFLstCon;
	if (find(this->mask, FEEDFLSTRLY) && feedFLstRly) this->feedFLstRly = *feedFLstRly;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyNavConnect::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCON)) ss.push_back("feedFLstCon");
	if (has(FEEDFLSTRLY)) ss.push_back("feedFLstRly");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavConnect::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCON)) {feedFLstCon = src->feedFLstCon; add(FEEDFLSTCON);};
	if (src->has(FEEDFLSTRLY)) {feedFLstRly = src->feedFLstRly; add(FEEDFLSTRLY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyNavConnect::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyNavConnectData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTCON)) feedFLstCon.writeJSON(me);
	if (has(FEEDFLSTRLY)) feedFLstRly.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyNavConnect::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyNavConnectData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCON)) feedFLstCon.writeXML(wr);
		if (has(FEEDFLSTRLY)) feedFLstRly.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
