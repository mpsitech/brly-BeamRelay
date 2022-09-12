/**
	* \file PnlBrlyFltRec_blks.cpp
	* job handler for job PnlBrlyFltRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyFltRec::VecVDo
 ******************************************************************************/

uint PnlBrlyFltRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyFltRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyFltRec::ContInf
 ******************************************************************************/

PnlBrlyFltRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlBrlyFltRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyFltRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlBrlyFltRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyFltRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyFltRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFltRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyFltRec::ContInf::diff(
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
 class PnlBrlyFltRec::StatApp
 ******************************************************************************/

void PnlBrlyFltRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneFafAWaypoint
			, const bool initdone1NConnection
			, const bool initdoneRef1NSegment
			, const bool initdoneEqp1NNode
			, const bool initdoneMNLocation
			, const bool initdoneOrgMNFlight
			, const bool initdoneMNConnection
			, const bool initdoneEqpMNConnection
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyFltRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdonePre"] = initdonePre;
	me["initdoneDetail"] = initdoneDetail;
	me["initdoneFafAWaypoint"] = initdoneFafAWaypoint;
	me["initdone1NConnection"] = initdone1NConnection;
	me["initdoneRef1NSegment"] = initdoneRef1NSegment;
	me["initdoneEqp1NNode"] = initdoneEqp1NNode;
	me["initdoneMNLocation"] = initdoneMNLocation;
	me["initdoneOrgMNFlight"] = initdoneOrgMNFlight;
	me["initdoneMNConnection"] = initdoneMNConnection;
	me["initdoneEqpMNConnection"] = initdoneEqpMNConnection;
};

void PnlBrlyFltRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneFafAWaypoint
			, const bool initdone1NConnection
			, const bool initdoneRef1NSegment
			, const bool initdoneEqp1NNode
			, const bool initdoneMNLocation
			, const bool initdoneOrgMNFlight
			, const bool initdoneMNConnection
			, const bool initdoneEqpMNConnection
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyFltRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyFltRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneFafAWaypoint", initdoneFafAWaypoint);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NConnection", initdone1NConnection);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NSegment", initdoneRef1NSegment);
		writeBoolAttr(wr, itemtag, "sref", "initdoneEqp1NNode", initdoneEqp1NNode);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNLocation", initdoneMNLocation);
		writeBoolAttr(wr, itemtag, "sref", "initdoneOrgMNFlight", initdoneOrgMNFlight);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNConnection", initdoneMNConnection);
		writeBoolAttr(wr, itemtag, "sref", "initdoneEqpMNConnection", initdoneEqpMNConnection);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltRec::StatShr
 ******************************************************************************/

PnlBrlyFltRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const ubigint jrefPre
			, const ubigint jrefDetail
			, const ubigint jrefFafAWaypoint
			, const bool pnlfafawaypointAvail
			, const ubigint jref1NConnection
			, const ubigint jrefRef1NSegment
			, const ubigint jrefEqp1NNode
			, const bool pnleqp1nnodeAvail
			, const ubigint jrefMNLocation
			, const ubigint jrefOrgMNFlight
			, const ubigint jrefMNConnection
			, const ubigint jrefEqpMNConnection
			, const bool pnleqpmnconnectionAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->jrefPre = jrefPre;
	this->jrefDetail = jrefDetail;
	this->jrefFafAWaypoint = jrefFafAWaypoint;
	this->pnlfafawaypointAvail = pnlfafawaypointAvail;
	this->jref1NConnection = jref1NConnection;
	this->jrefRef1NSegment = jrefRef1NSegment;
	this->jrefEqp1NNode = jrefEqp1NNode;
	this->pnleqp1nnodeAvail = pnleqp1nnodeAvail;
	this->jrefMNLocation = jrefMNLocation;
	this->jrefOrgMNFlight = jrefOrgMNFlight;
	this->jrefMNConnection = jrefMNConnection;
	this->jrefEqpMNConnection = jrefEqpMNConnection;
	this->pnleqpmnconnectionAvail = pnleqpmnconnectionAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, JREFPRE, JREFDETAIL, JREFFAFAWAYPOINT, PNLFAFAWAYPOINTAVAIL, JREF1NCONNECTION, JREFREF1NSEGMENT, JREFEQP1NNODE, PNLEQP1NNODEAVAIL, JREFMNLOCATION, JREFORGMNFLIGHT, JREFMNCONNECTION, JREFEQPMNCONNECTION, PNLEQPMNCONNECTIONAVAIL, BUTREGULARIZEACTIVE};
};

void PnlBrlyFltRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyFltRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["scrJrefPre"] = Scr::scramble(jrefPre);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJrefFafAWaypoint"] = Scr::scramble(jrefFafAWaypoint);
	me["pnlfafawaypointAvail"] = pnlfafawaypointAvail;
	me["scrJref1NConnection"] = Scr::scramble(jref1NConnection);
	me["scrJrefRef1NSegment"] = Scr::scramble(jrefRef1NSegment);
	me["scrJrefEqp1NNode"] = Scr::scramble(jrefEqp1NNode);
	me["pnleqp1nnodeAvail"] = pnleqp1nnodeAvail;
	me["scrJrefMNLocation"] = Scr::scramble(jrefMNLocation);
	me["scrJrefOrgMNFlight"] = Scr::scramble(jrefOrgMNFlight);
	me["scrJrefMNConnection"] = Scr::scramble(jrefMNConnection);
	me["scrJrefEqpMNConnection"] = Scr::scramble(jrefEqpMNConnection);
	me["pnleqpmnconnectionAvail"] = pnleqpmnconnectionAvail;
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlBrlyFltRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyFltRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyFltRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(jrefPre));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefFafAWaypoint", Scr::scramble(jrefFafAWaypoint));
		writeBoolAttr(wr, itemtag, "sref", "pnlfafawaypointAvail", pnlfafawaypointAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NConnection", Scr::scramble(jref1NConnection));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NSegment", Scr::scramble(jrefRef1NSegment));
		writeStringAttr(wr, itemtag, "sref", "scrJrefEqp1NNode", Scr::scramble(jrefEqp1NNode));
		writeBoolAttr(wr, itemtag, "sref", "pnleqp1nnodeAvail", pnleqp1nnodeAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNLocation", Scr::scramble(jrefMNLocation));
		writeStringAttr(wr, itemtag, "sref", "scrJrefOrgMNFlight", Scr::scramble(jrefOrgMNFlight));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNConnection", Scr::scramble(jrefMNConnection));
		writeStringAttr(wr, itemtag, "sref", "scrJrefEqpMNConnection", Scr::scramble(jrefEqpMNConnection));
		writeBoolAttr(wr, itemtag, "sref", "pnleqpmnconnectionAvail", pnleqpmnconnectionAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFltRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefFafAWaypoint == comp->jrefFafAWaypoint) insert(items, JREFFAFAWAYPOINT);
	if (pnlfafawaypointAvail == comp->pnlfafawaypointAvail) insert(items, PNLFAFAWAYPOINTAVAIL);
	if (jref1NConnection == comp->jref1NConnection) insert(items, JREF1NCONNECTION);
	if (jrefRef1NSegment == comp->jrefRef1NSegment) insert(items, JREFREF1NSEGMENT);
	if (jrefEqp1NNode == comp->jrefEqp1NNode) insert(items, JREFEQP1NNODE);
	if (pnleqp1nnodeAvail == comp->pnleqp1nnodeAvail) insert(items, PNLEQP1NNODEAVAIL);
	if (jrefMNLocation == comp->jrefMNLocation) insert(items, JREFMNLOCATION);
	if (jrefOrgMNFlight == comp->jrefOrgMNFlight) insert(items, JREFORGMNFLIGHT);
	if (jrefMNConnection == comp->jrefMNConnection) insert(items, JREFMNCONNECTION);
	if (jrefEqpMNConnection == comp->jrefEqpMNConnection) insert(items, JREFEQPMNCONNECTION);
	if (pnleqpmnconnectionAvail == comp->pnleqpmnconnectionAvail) insert(items, PNLEQPMNCONNECTIONAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyFltRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, JREFPRE, JREFDETAIL, JREFFAFAWAYPOINT, PNLFAFAWAYPOINTAVAIL, JREF1NCONNECTION, JREFREF1NSEGMENT, JREFEQP1NNODE, PNLEQP1NNODEAVAIL, JREFMNLOCATION, JREFORGMNFLIGHT, JREFMNCONNECTION, JREFEQPMNCONNECTION, PNLEQPMNCONNECTIONAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltRec::Tag
 ******************************************************************************/

void PnlBrlyFltRec::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyFltRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Flight";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Flug";
	};
};

void PnlBrlyFltRec::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyFltRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyFltRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Flight");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Flug");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltRec::DpchAppDo
 ******************************************************************************/

PnlBrlyFltRec::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTRECDO)
		{
	ixVDo = 0;
};

string PnlBrlyFltRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltRec::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyFltRecDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyFltRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyFltRecDo");
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
 class PnlBrlyFltRec::DpchEngData
 ******************************************************************************/

PnlBrlyFltRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYFLTRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyFltRec::DpchEngData::getSrefsMask() {
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

void PnlBrlyFltRec::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyFltRec::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyFltRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyFltRec::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyFltRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
