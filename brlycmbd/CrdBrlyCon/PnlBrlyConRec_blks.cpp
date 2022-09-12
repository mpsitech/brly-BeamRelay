/**
	* \file PnlBrlyConRec_blks.cpp
	* job handler for job PnlBrlyConRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyConRec::VecVDo
 ******************************************************************************/

uint PnlBrlyConRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyConRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyConRec::ContInf
 ******************************************************************************/

PnlBrlyConRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlBrlyConRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyConRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlBrlyConRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyConRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyConRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyConRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyConRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConRec::StatApp
 ******************************************************************************/

void PnlBrlyConRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneMap
			, const bool initdone1NRelay
			, const bool initdoneRef1NSegment
			, const bool initdoneConMNEquipment
			, const bool initdoneMNFlight
			, const bool initdoneMNSegment
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyConRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdonePre"] = initdonePre;
	me["initdoneDetail"] = initdoneDetail;
	me["initdoneMap"] = initdoneMap;
	me["initdone1NRelay"] = initdone1NRelay;
	me["initdoneRef1NSegment"] = initdoneRef1NSegment;
	me["initdoneConMNEquipment"] = initdoneConMNEquipment;
	me["initdoneMNFlight"] = initdoneMNFlight;
	me["initdoneMNSegment"] = initdoneMNSegment;
};

void PnlBrlyConRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneMap
			, const bool initdone1NRelay
			, const bool initdoneRef1NSegment
			, const bool initdoneConMNEquipment
			, const bool initdoneMNFlight
			, const bool initdoneMNSegment
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyConRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyConRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMap", initdoneMap);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NRelay", initdone1NRelay);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NSegment", initdoneRef1NSegment);
		writeBoolAttr(wr, itemtag, "sref", "initdoneConMNEquipment", initdoneConMNEquipment);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNFlight", initdoneMNFlight);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNSegment", initdoneMNSegment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConRec::StatShr
 ******************************************************************************/

PnlBrlyConRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const ubigint jrefPre
			, const ubigint jrefDetail
			, const ubigint jrefMap
			, const ubigint jref1NRelay
			, const ubigint jrefRef1NSegment
			, const ubigint jrefConMNEquipment
			, const ubigint jrefMNFlight
			, const ubigint jrefMNSegment
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->jrefPre = jrefPre;
	this->jrefDetail = jrefDetail;
	this->jrefMap = jrefMap;
	this->jref1NRelay = jref1NRelay;
	this->jrefRef1NSegment = jrefRef1NSegment;
	this->jrefConMNEquipment = jrefConMNEquipment;
	this->jrefMNFlight = jrefMNFlight;
	this->jrefMNSegment = jrefMNSegment;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, JREFPRE, JREFDETAIL, JREFMAP, JREF1NRELAY, JREFREF1NSEGMENT, JREFCONMNEQUIPMENT, JREFMNFLIGHT, JREFMNSEGMENT, BUTREGULARIZEACTIVE};
};

void PnlBrlyConRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyConRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["scrJrefPre"] = Scr::scramble(jrefPre);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJrefMap"] = Scr::scramble(jrefMap);
	me["scrJref1NRelay"] = Scr::scramble(jref1NRelay);
	me["scrJrefRef1NSegment"] = Scr::scramble(jrefRef1NSegment);
	me["scrJrefConMNEquipment"] = Scr::scramble(jrefConMNEquipment);
	me["scrJrefMNFlight"] = Scr::scramble(jrefMNFlight);
	me["scrJrefMNSegment"] = Scr::scramble(jrefMNSegment);
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlBrlyConRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyConRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyConRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(jrefPre));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMap", Scr::scramble(jrefMap));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NRelay", Scr::scramble(jref1NRelay));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NSegment", Scr::scramble(jrefRef1NSegment));
		writeStringAttr(wr, itemtag, "sref", "scrJrefConMNEquipment", Scr::scramble(jrefConMNEquipment));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNFlight", Scr::scramble(jrefMNFlight));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNSegment", Scr::scramble(jrefMNSegment));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyConRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefMap == comp->jrefMap) insert(items, JREFMAP);
	if (jref1NRelay == comp->jref1NRelay) insert(items, JREF1NRELAY);
	if (jrefRef1NSegment == comp->jrefRef1NSegment) insert(items, JREFREF1NSEGMENT);
	if (jrefConMNEquipment == comp->jrefConMNEquipment) insert(items, JREFCONMNEQUIPMENT);
	if (jrefMNFlight == comp->jrefMNFlight) insert(items, JREFMNFLIGHT);
	if (jrefMNSegment == comp->jrefMNSegment) insert(items, JREFMNSEGMENT);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyConRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, JREFPRE, JREFDETAIL, JREFMAP, JREF1NRELAY, JREFREF1NSEGMENT, JREFCONMNEQUIPMENT, JREFMNFLIGHT, JREFMNSEGMENT, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConRec::Tag
 ******************************************************************************/

void PnlBrlyConRec::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyConRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Connection";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Verbindung";
	};
};

void PnlBrlyConRec::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyConRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyConRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Connection");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Verbindung");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConRec::DpchAppDo
 ******************************************************************************/

PnlBrlyConRec::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONRECDO)
		{
	ixVDo = 0;
};

string PnlBrlyConRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConRec::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyConRecDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyConRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyConRecDo");
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
 class PnlBrlyConRec::DpchEngData
 ******************************************************************************/

PnlBrlyConRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyConRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConRec::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyConRec::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyConRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyConRec::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyConRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
