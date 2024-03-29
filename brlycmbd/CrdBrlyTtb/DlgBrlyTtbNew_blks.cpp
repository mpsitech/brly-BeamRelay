/**
	* \file DlgBrlyTtbNew_blks.cpp
	* job handler for job DlgBrlyTtbNew (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgBrlyTtbNew::VecVDo
 ******************************************************************************/

uint DlgBrlyTtbNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcncclick") return BUTCNCCLICK;
	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgBrlyTtbNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCNCCLICK) return("ButCncClick");
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgBrlyTtbNew::VecVSge
 ******************************************************************************/

uint DlgBrlyTtbNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "done") return DONE;

	return(0);
};

string DlgBrlyTtbNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == DONE) return("done");

	return("");
};

void DlgBrlyTtbNew::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgBrlyTtbNew::ContIac
 ******************************************************************************/

DlgBrlyTtbNew::ContIac::ContIac(
			const uint numFDetPupAli
			, const string& DetTxfTit
			, const string& DetTxfSta
			, const string& DetTxfSto
		) :
			Block()
		{
	this->numFDetPupAli = numFDetPupAli;
	this->DetTxfTit = DetTxfTit;
	this->DetTxfSta = DetTxfSta;
	this->DetTxfSto = DetTxfSto;

	mask = {NUMFDETPUPALI, DETTXFTIT, DETTXFSTA, DETTXFSTO};
};

bool DlgBrlyTtbNew::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgBrlyTtbNew"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDetPupAli")) {numFDetPupAli = me["numFDetPupAli"].asUInt(); add(NUMFDETPUPALI);};
		if (me.isMember("DetTxfTit")) {DetTxfTit = me["DetTxfTit"].asString(); add(DETTXFTIT);};
		if (me.isMember("DetTxfSta")) {DetTxfSta = me["DetTxfSta"].asString(); add(DETTXFSTA);};
		if (me.isMember("DetTxfSto")) {DetTxfSto = me["DetTxfSto"].asString(); add(DETTXFSTO);};
	};

	return basefound;
};

bool DlgBrlyTtbNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgBrlyTtbNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgBrlyTtbNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupAli", numFDetPupAli)) add(NUMFDETPUPALI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfTit", DetTxfTit)) add(DETTXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfSta", DetTxfSta)) add(DETTXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfSto", DetTxfSto)) add(DETTXFSTO);
	};

	return basefound;
};

void DlgBrlyTtbNew::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyTtbNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDetPupAli"] = numFDetPupAli;
	me["DetTxfTit"] = DetTxfTit;
	me["DetTxfSta"] = DetTxfSta;
	me["DetTxfSto"] = DetTxfSto;
};

void DlgBrlyTtbNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgBrlyTtbNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgBrlyTtbNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDetPupAli", numFDetPupAli);
		writeStringAttr(wr, itemtag, "sref", "DetTxfTit", DetTxfTit);
		writeStringAttr(wr, itemtag, "sref", "DetTxfSta", DetTxfSta);
		writeStringAttr(wr, itemtag, "sref", "DetTxfSto", DetTxfSto);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyTtbNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDetPupAli == comp->numFDetPupAli) insert(items, NUMFDETPUPALI);
	if (DetTxfTit == comp->DetTxfTit) insert(items, DETTXFTIT);
	if (DetTxfSta == comp->DetTxfSta) insert(items, DETTXFSTA);
	if (DetTxfSto == comp->DetTxfSto) insert(items, DETTXFSTO);

	return(items);
};

set<uint> DlgBrlyTtbNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDETPUPALI, DETTXFTIT, DETTXFSTA, DETTXFSTO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyTtbNew::ContInf
 ******************************************************************************/

DlgBrlyTtbNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgBrlyTtbNew::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyTtbNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
};

void DlgBrlyTtbNew::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgBrlyTtbNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgBrlyTtbNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyTtbNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgBrlyTtbNew::ContInf::diff(
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
 class DlgBrlyTtbNew::StatApp
 ******************************************************************************/

void DlgBrlyTtbNew::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgBrlyTtbNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["shortMenu"] = shortMenu;
};

void DlgBrlyTtbNew::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgBrlyTtbNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgBrlyTtbNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyTtbNew::StatShr
 ******************************************************************************/

DlgBrlyTtbNew::StatShr::StatShr(
			const bool ButCncActive
			, const bool ButCreActive
		) :
			Block()
		{
	this->ButCncActive = ButCncActive;
	this->ButCreActive = ButCreActive;

	mask = {BUTCNCACTIVE, BUTCREACTIVE};
};

void DlgBrlyTtbNew::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyTtbNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButCncActive"] = ButCncActive;
	me["ButCreActive"] = ButCreActive;
};

void DlgBrlyTtbNew::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgBrlyTtbNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgBrlyTtbNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCncActive", ButCncActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgBrlyTtbNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButCncActive == comp->ButCncActive) insert(items, BUTCNCACTIVE);
	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgBrlyTtbNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCNCACTIVE, BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgBrlyTtbNew::Tag
 ******************************************************************************/

void DlgBrlyTtbNew::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyTtbNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Create new timetable";
		me["DetCptAli"] = "Airline alliance";
		me["DetCptTit"] = "Name";
		me["DetCptSta"] = "Validity start";
		me["DetCptSto"] = "Validity stop";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Neuen Flugplan erstellen";
		me["DetCptAli"] = "Luftfahrtallianz";
		me["DetCptTit"] = "Name";
		me["DetCptSta"] = "G\\u00fcltigkeitsbeginn";
		me["DetCptSto"] = "G\\u00fcltigkeitsende";
	};
	me["ButCnc"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CANCEL, ixBrlyVLocale));
	me["ButCre"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CREATE, ixBrlyVLocale));
};

void DlgBrlyTtbNew::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgBrlyTtbNew";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgBrlyTtbNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Create new timetable");
			writeStringAttr(wr, itemtag, "sref", "DetCptAli", "Airline alliance");
			writeStringAttr(wr, itemtag, "sref", "DetCptTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "DetCptSta", "Validity start");
			writeStringAttr(wr, itemtag, "sref", "DetCptSto", "Validity stop");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Neuen Flugplan erstellen");
			writeStringAttr(wr, itemtag, "sref", "DetCptAli", "Luftfahrtallianz");
			writeStringAttr(wr, itemtag, "sref", "DetCptTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "DetCptSta", "G\\u00fcltigkeitsbeginn");
			writeStringAttr(wr, itemtag, "sref", "DetCptSto", "G\\u00fcltigkeitsende");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCnc", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CANCEL, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CREATE, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgBrlyTtbNew::DpchAppData
 ******************************************************************************/

DlgBrlyTtbNew::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYTTBNEWDATA)
		{
};

string DlgBrlyTtbNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyTtbNew::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgBrlyTtbNewData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void DlgBrlyTtbNew::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgBrlyTtbNewData");
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
 class DlgBrlyTtbNew::DpchAppDo
 ******************************************************************************/

DlgBrlyTtbNew::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPDLGBRLYTTBNEWDO)
		{
	ixVDo = 0;
};

string DlgBrlyTtbNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyTtbNew::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgBrlyTtbNewDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void DlgBrlyTtbNew::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgBrlyTtbNewDo");
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
 class DlgBrlyTtbNew::DpchEngData
 ******************************************************************************/

DlgBrlyTtbNew::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFDetPupAli
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGDLGBRLYTTBNEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFDETPUPALI, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFDETPUPALI) && feedFDetPupAli) this->feedFDetPupAli = *feedFDetPupAli;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgBrlyTtbNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETPUPALI)) ss.push_back("feedFDetPupAli");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgBrlyTtbNew::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFDETPUPALI)) {feedFDetPupAli = src->feedFDetPupAli; add(FEEDFDETPUPALI);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgBrlyTtbNew::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgBrlyTtbNewData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFDETPUPALI)) feedFDetPupAli.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void DlgBrlyTtbNew::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgBrlyTtbNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFDETPUPALI)) feedFDetPupAli.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
