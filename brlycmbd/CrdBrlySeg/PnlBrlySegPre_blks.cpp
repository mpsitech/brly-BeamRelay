/**
	* \file PnlBrlySegPre_blks.cpp
	* job handler for job PnlBrlySegPre (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlySegPre::ContIac
 ******************************************************************************/

PnlBrlySegPre::ContIac::ContIac(
			const double SldTme
			, const double SldPhi
		) :
			Block()
		{
	this->SldTme = SldTme;
	this->SldPhi = SldPhi;

	mask = {SLDTME, SLDPHI};
};

bool PnlBrlySegPre::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlySegPre"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("SldTme")) {SldTme = me["SldTme"].asDouble(); add(SLDTME);};
		if (me.isMember("SldPhi")) {SldPhi = me["SldPhi"].asDouble(); add(SLDPHI);};
	};

	return basefound;
};

bool PnlBrlySegPre::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlySegPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlySegPre";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldTme", SldTme)) add(SLDTME);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldPhi", SldPhi)) add(SLDPHI);
	};

	return basefound;
};

void PnlBrlySegPre::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlySegPre";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["SldTme"] = SldTme;
	me["SldPhi"] = SldPhi;
};

void PnlBrlySegPre::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlySegPre";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlySegPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldTme", SldTme);
		writeDoubleAttr(wr, itemtag, "sref", "SldPhi", SldPhi);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegPre::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldTme, comp->SldTme) < 1.0e-4) insert(items, SLDTME);
	if (compareDouble(SldPhi, comp->SldPhi) < 1.0e-4) insert(items, SLDPHI);

	return(items);
};

set<uint> PnlBrlySegPre::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDTME, SLDPHI};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegPre::StatApp
 ******************************************************************************/

void PnlBrlySegPre::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlySegPre";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
};

void PnlBrlySegPre::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlySegPre";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlySegPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlySegPre::StatShr
 ******************************************************************************/

PnlBrlySegPre::StatShr::StatShr(
			const double SldTmeMin
			, const double SldTmeMax
			, const double SldPhiMin
			, const double SldPhiMax
		) :
			Block()
		{
	this->SldTmeMin = SldTmeMin;
	this->SldTmeMax = SldTmeMax;
	this->SldPhiMin = SldPhiMin;
	this->SldPhiMax = SldPhiMax;

	mask = {SLDTMEMIN, SLDTMEMAX, SLDPHIMIN, SLDPHIMAX};
};

void PnlBrlySegPre::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlySegPre";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["SldTmeMin"] = SldTmeMin;
	me["SldTmeMax"] = SldTmeMax;
	me["SldPhiMin"] = SldPhiMin;
	me["SldPhiMax"] = SldPhiMax;
};

void PnlBrlySegPre::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlySegPre";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlySegPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldTmeMin", SldTmeMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldTmeMax", SldTmeMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldPhiMin", SldPhiMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldPhiMax", SldPhiMax);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlySegPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (compareDouble(SldTmeMin, comp->SldTmeMin) < 1.0e-4) insert(items, SLDTMEMIN);
	if (compareDouble(SldTmeMax, comp->SldTmeMax) < 1.0e-4) insert(items, SLDTMEMAX);
	if (compareDouble(SldPhiMin, comp->SldPhiMin) < 1.0e-4) insert(items, SLDPHIMIN);
	if (compareDouble(SldPhiMax, comp->SldPhiMax) < 1.0e-4) insert(items, SLDPHIMAX);

	return(items);
};

set<uint> PnlBrlySegPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDTMEMIN, SLDTMEMAX, SLDPHIMIN, SLDPHIMAX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlySegPre::Tag
 ******************************************************************************/

void PnlBrlySegPre::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlySegPre";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Time and angular position";
		me["CptTme"] = "time";
		me["CptPhi"] = "angular position [\\u00b0]";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Zeit und Winkelposition";
		me["CptTme"] = "Zeit";
		me["CptPhi"] = "Winkelposition [\\u00b0]";
	};
};

void PnlBrlySegPre::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlySegPre";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlySegPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Time and angular position");
			writeStringAttr(wr, itemtag, "sref", "CptTme", "time");
			writeStringAttr(wr, itemtag, "sref", "CptPhi", "angular position [\\u00b0]");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Zeit und Winkelposition");
			writeStringAttr(wr, itemtag, "sref", "CptTme", "Zeit");
			writeStringAttr(wr, itemtag, "sref", "CptPhi", "Winkelposition [\\u00b0]");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlySegPre::DpchAppData
 ******************************************************************************/

PnlBrlySegPre::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYSEGPREDATA)
		{
};

string PnlBrlySegPre::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegPre::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlySegPreData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlBrlySegPre::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlySegPreData");
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
 class PnlBrlySegPre::DpchEngData
 ******************************************************************************/

PnlBrlySegPre::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYSEGPREDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlySegPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlySegPre::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlySegPre::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlySegPreData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlySegPre::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlySegPreData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
