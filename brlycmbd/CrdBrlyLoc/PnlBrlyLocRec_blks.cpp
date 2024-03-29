/**
	* \file PnlBrlyLocRec_blks.cpp
	* job handler for job PnlBrlyLocRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyLocRec::VecVDo
 ******************************************************************************/

uint PnlBrlyLocRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyLocRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyLocRec::ContInf
 ******************************************************************************/

PnlBrlyLocRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlBrlyLocRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLocRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlBrlyLocRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyLocRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyLocRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyLocRec::ContInf::diff(
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
 class PnlBrlyLocRec::StatApp
 ******************************************************************************/

void PnlBrlyLocRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdoneDetail
			, const bool initdoneMap
			, const bool initdoneBgn1NLeg
			, const bool initdoneEnd1NLeg
			, const bool initdoneEqp1NNode
			, const bool initdoneMNSegment
			, const bool initdoneMNFlight
			, const bool initdoneMNLeg
			, const bool initdoneVisOrgMNLocation
			, const bool initdoneProxOrgMNLocation
			, const bool initdoneEqpMNConnection
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyLocRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdoneDetail"] = initdoneDetail;
	me["initdoneMap"] = initdoneMap;
	me["initdoneBgn1NLeg"] = initdoneBgn1NLeg;
	me["initdoneEnd1NLeg"] = initdoneEnd1NLeg;
	me["initdoneEqp1NNode"] = initdoneEqp1NNode;
	me["initdoneMNSegment"] = initdoneMNSegment;
	me["initdoneMNFlight"] = initdoneMNFlight;
	me["initdoneMNLeg"] = initdoneMNLeg;
	me["initdoneVisOrgMNLocation"] = initdoneVisOrgMNLocation;
	me["initdoneProxOrgMNLocation"] = initdoneProxOrgMNLocation;
	me["initdoneEqpMNConnection"] = initdoneEqpMNConnection;
};

void PnlBrlyLocRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneMap
			, const bool initdoneBgn1NLeg
			, const bool initdoneEnd1NLeg
			, const bool initdoneEqp1NNode
			, const bool initdoneMNSegment
			, const bool initdoneMNFlight
			, const bool initdoneMNLeg
			, const bool initdoneVisOrgMNLocation
			, const bool initdoneProxOrgMNLocation
			, const bool initdoneEqpMNConnection
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyLocRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyLocRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMap", initdoneMap);
		writeBoolAttr(wr, itemtag, "sref", "initdoneBgn1NLeg", initdoneBgn1NLeg);
		writeBoolAttr(wr, itemtag, "sref", "initdoneEnd1NLeg", initdoneEnd1NLeg);
		writeBoolAttr(wr, itemtag, "sref", "initdoneEqp1NNode", initdoneEqp1NNode);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNSegment", initdoneMNSegment);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNFlight", initdoneMNFlight);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNLeg", initdoneMNLeg);
		writeBoolAttr(wr, itemtag, "sref", "initdoneVisOrgMNLocation", initdoneVisOrgMNLocation);
		writeBoolAttr(wr, itemtag, "sref", "initdoneProxOrgMNLocation", initdoneProxOrgMNLocation);
		writeBoolAttr(wr, itemtag, "sref", "initdoneEqpMNConnection", initdoneEqpMNConnection);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocRec::StatShr
 ******************************************************************************/

PnlBrlyLocRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefMap
			, const ubigint jrefBgn1NLeg
			, const bool pnlbgn1nlegAvail
			, const ubigint jrefEnd1NLeg
			, const bool pnlend1nlegAvail
			, const ubigint jrefEqp1NNode
			, const bool pnleqp1nnodeAvail
			, const ubigint jrefMNSegment
			, const ubigint jrefMNFlight
			, const ubigint jrefMNLeg
			, const ubigint jrefVisOrgMNLocation
			, const ubigint jrefProxOrgMNLocation
			, const ubigint jrefEqpMNConnection
			, const bool pnleqpmnconnectionAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefMap = jrefMap;
	this->jrefBgn1NLeg = jrefBgn1NLeg;
	this->pnlbgn1nlegAvail = pnlbgn1nlegAvail;
	this->jrefEnd1NLeg = jrefEnd1NLeg;
	this->pnlend1nlegAvail = pnlend1nlegAvail;
	this->jrefEqp1NNode = jrefEqp1NNode;
	this->pnleqp1nnodeAvail = pnleqp1nnodeAvail;
	this->jrefMNSegment = jrefMNSegment;
	this->jrefMNFlight = jrefMNFlight;
	this->jrefMNLeg = jrefMNLeg;
	this->jrefVisOrgMNLocation = jrefVisOrgMNLocation;
	this->jrefProxOrgMNLocation = jrefProxOrgMNLocation;
	this->jrefEqpMNConnection = jrefEqpMNConnection;
	this->pnleqpmnconnectionAvail = pnleqpmnconnectionAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, JREFDETAIL, JREFMAP, JREFBGN1NLEG, PNLBGN1NLEGAVAIL, JREFEND1NLEG, PNLEND1NLEGAVAIL, JREFEQP1NNODE, PNLEQP1NNODEAVAIL, JREFMNSEGMENT, JREFMNFLIGHT, JREFMNLEG, JREFVISORGMNLOCATION, JREFPROXORGMNLOCATION, JREFEQPMNCONNECTION, PNLEQPMNCONNECTIONAVAIL, BUTREGULARIZEACTIVE};
};

void PnlBrlyLocRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLocRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJrefMap"] = Scr::scramble(jrefMap);
	me["scrJrefBgn1NLeg"] = Scr::scramble(jrefBgn1NLeg);
	me["pnlbgn1nlegAvail"] = pnlbgn1nlegAvail;
	me["scrJrefEnd1NLeg"] = Scr::scramble(jrefEnd1NLeg);
	me["pnlend1nlegAvail"] = pnlend1nlegAvail;
	me["scrJrefEqp1NNode"] = Scr::scramble(jrefEqp1NNode);
	me["pnleqp1nnodeAvail"] = pnleqp1nnodeAvail;
	me["scrJrefMNSegment"] = Scr::scramble(jrefMNSegment);
	me["scrJrefMNFlight"] = Scr::scramble(jrefMNFlight);
	me["scrJrefMNLeg"] = Scr::scramble(jrefMNLeg);
	me["scrJrefVisOrgMNLocation"] = Scr::scramble(jrefVisOrgMNLocation);
	me["scrJrefProxOrgMNLocation"] = Scr::scramble(jrefProxOrgMNLocation);
	me["scrJrefEqpMNConnection"] = Scr::scramble(jrefEqpMNConnection);
	me["pnleqpmnconnectionAvail"] = pnleqpmnconnectionAvail;
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlBrlyLocRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyLocRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyLocRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMap", Scr::scramble(jrefMap));
		writeStringAttr(wr, itemtag, "sref", "scrJrefBgn1NLeg", Scr::scramble(jrefBgn1NLeg));
		writeBoolAttr(wr, itemtag, "sref", "pnlbgn1nlegAvail", pnlbgn1nlegAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefEnd1NLeg", Scr::scramble(jrefEnd1NLeg));
		writeBoolAttr(wr, itemtag, "sref", "pnlend1nlegAvail", pnlend1nlegAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefEqp1NNode", Scr::scramble(jrefEqp1NNode));
		writeBoolAttr(wr, itemtag, "sref", "pnleqp1nnodeAvail", pnleqp1nnodeAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNSegment", Scr::scramble(jrefMNSegment));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNFlight", Scr::scramble(jrefMNFlight));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNLeg", Scr::scramble(jrefMNLeg));
		writeStringAttr(wr, itemtag, "sref", "scrJrefVisOrgMNLocation", Scr::scramble(jrefVisOrgMNLocation));
		writeStringAttr(wr, itemtag, "sref", "scrJrefProxOrgMNLocation", Scr::scramble(jrefProxOrgMNLocation));
		writeStringAttr(wr, itemtag, "sref", "scrJrefEqpMNConnection", Scr::scramble(jrefEqpMNConnection));
		writeBoolAttr(wr, itemtag, "sref", "pnleqpmnconnectionAvail", pnleqpmnconnectionAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyLocRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefMap == comp->jrefMap) insert(items, JREFMAP);
	if (jrefBgn1NLeg == comp->jrefBgn1NLeg) insert(items, JREFBGN1NLEG);
	if (pnlbgn1nlegAvail == comp->pnlbgn1nlegAvail) insert(items, PNLBGN1NLEGAVAIL);
	if (jrefEnd1NLeg == comp->jrefEnd1NLeg) insert(items, JREFEND1NLEG);
	if (pnlend1nlegAvail == comp->pnlend1nlegAvail) insert(items, PNLEND1NLEGAVAIL);
	if (jrefEqp1NNode == comp->jrefEqp1NNode) insert(items, JREFEQP1NNODE);
	if (pnleqp1nnodeAvail == comp->pnleqp1nnodeAvail) insert(items, PNLEQP1NNODEAVAIL);
	if (jrefMNSegment == comp->jrefMNSegment) insert(items, JREFMNSEGMENT);
	if (jrefMNFlight == comp->jrefMNFlight) insert(items, JREFMNFLIGHT);
	if (jrefMNLeg == comp->jrefMNLeg) insert(items, JREFMNLEG);
	if (jrefVisOrgMNLocation == comp->jrefVisOrgMNLocation) insert(items, JREFVISORGMNLOCATION);
	if (jrefProxOrgMNLocation == comp->jrefProxOrgMNLocation) insert(items, JREFPROXORGMNLOCATION);
	if (jrefEqpMNConnection == comp->jrefEqpMNConnection) insert(items, JREFEQPMNCONNECTION);
	if (pnleqpmnconnectionAvail == comp->pnleqpmnconnectionAvail) insert(items, PNLEQPMNCONNECTIONAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyLocRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, JREFDETAIL, JREFMAP, JREFBGN1NLEG, PNLBGN1NLEGAVAIL, JREFEND1NLEG, PNLEND1NLEGAVAIL, JREFEQP1NNODE, PNLEQP1NNODEAVAIL, JREFMNSEGMENT, JREFMNFLIGHT, JREFMNLEG, JREFVISORGMNLOCATION, JREFPROXORGMNLOCATION, JREFEQPMNCONNECTION, PNLEQPMNCONNECTIONAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyLocRec::Tag
 ******************************************************************************/

void PnlBrlyLocRec::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLocRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Location";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Ort";
	};
};

void PnlBrlyLocRec::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyLocRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyLocRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Location");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Ort");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyLocRec::DpchAppDo
 ******************************************************************************/

PnlBrlyLocRec::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYLOCRECDO)
		{
	ixVDo = 0;
};

string PnlBrlyLocRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyLocRec::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyLocRecDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyLocRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyLocRecDo");
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
 class PnlBrlyLocRec::DpchEngData
 ******************************************************************************/

PnlBrlyLocRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYLOCRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyLocRec::DpchEngData::getSrefsMask() {
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

void PnlBrlyLocRec::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyLocRec::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyLocRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyLocRec::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyLocRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
