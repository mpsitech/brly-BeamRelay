/**
	* \file PnlBrlyRegRec_blks.cpp
	* job handler for job PnlBrlyRegRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyRegRec::VecVDo
 ******************************************************************************/

uint PnlBrlyRegRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlBrlyRegRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlBrlyRegRec::ContInf
 ******************************************************************************/

PnlBrlyRegRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlBrlyRegRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyRegRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlBrlyRegRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyRegRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyRegRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyRegRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlBrlyRegRec::ContInf::diff(
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
 class PnlBrlyRegRec::StatApp
 ******************************************************************************/

void PnlBrlyRegRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdoneDetail
			, const bool initdoneADstswitch
			, const bool initdone1NLocation
			, const bool initdoneSup1NRegion
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyRegRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdoneDetail"] = initdoneDetail;
	me["initdoneADstswitch"] = initdoneADstswitch;
	me["initdone1NLocation"] = initdone1NLocation;
	me["initdoneSup1NRegion"] = initdoneSup1NRegion;
};

void PnlBrlyRegRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneADstswitch
			, const bool initdone1NLocation
			, const bool initdoneSup1NRegion
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyRegRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyRegRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneADstswitch", initdoneADstswitch);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NLocation", initdone1NLocation);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NRegion", initdoneSup1NRegion);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyRegRec::StatShr
 ******************************************************************************/

PnlBrlyRegRec::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefADstswitch
			, const ubigint jref1NLocation
			, const bool pnl1nlocationAvail
			, const ubigint jrefSup1NRegion
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefADstswitch = jrefADstswitch;
	this->jref1NLocation = jref1NLocation;
	this->pnl1nlocationAvail = pnl1nlocationAvail;
	this->jrefSup1NRegion = jrefSup1NRegion;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXBRLYVEXPSTATE, JREFDETAIL, JREFADSTSWITCH, JREF1NLOCATION, PNL1NLOCATIONAVAIL, JREFSUP1NREGION, BUTREGULARIZEACTIVE};
};

void PnlBrlyRegRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyRegRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJrefADstswitch"] = Scr::scramble(jrefADstswitch);
	me["scrJref1NLocation"] = Scr::scramble(jref1NLocation);
	me["pnl1nlocationAvail"] = pnl1nlocationAvail;
	me["scrJrefSup1NRegion"] = Scr::scramble(jrefSup1NRegion);
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlBrlyRegRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyRegRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyRegRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefADstswitch", Scr::scramble(jrefADstswitch));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NLocation", Scr::scramble(jref1NLocation));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nlocationAvail", pnl1nlocationAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NRegion", Scr::scramble(jrefSup1NRegion));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyRegRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefADstswitch == comp->jrefADstswitch) insert(items, JREFADSTSWITCH);
	if (jref1NLocation == comp->jref1NLocation) insert(items, JREF1NLOCATION);
	if (pnl1nlocationAvail == comp->pnl1nlocationAvail) insert(items, PNL1NLOCATIONAVAIL);
	if (jrefSup1NRegion == comp->jrefSup1NRegion) insert(items, JREFSUP1NREGION);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlBrlyRegRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, JREFDETAIL, JREFADSTSWITCH, JREF1NLOCATION, PNL1NLOCATIONAVAIL, JREFSUP1NREGION, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRegRec::Tag
 ******************************************************************************/

void PnlBrlyRegRec::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyRegRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Region";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Region";
	};
};

void PnlBrlyRegRec::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyRegRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyRegRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Region");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Region");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyRegRec::DpchAppDo
 ******************************************************************************/

PnlBrlyRegRec::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYREGRECDO)
		{
	ixVDo = 0;
};

string PnlBrlyRegRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRegRec::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyRegRecDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyRegRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyRegRecDo");
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
 class PnlBrlyRegRec::DpchEngData
 ******************************************************************************/

PnlBrlyRegRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYREGRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyRegRec::DpchEngData::getSrefsMask() {
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

void PnlBrlyRegRec::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyRegRec::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyRegRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyRegRec::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyRegRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
