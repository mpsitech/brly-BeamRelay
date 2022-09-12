/**
	* \file SessBrly_blks.cpp
	* job handler for job SessBrly (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class SessBrly::StatShr
 ******************************************************************************/

SessBrly::StatShr::StatShr(
			const ubigint jrefCrdnav
		) :
			Block()
		{
	this->jrefCrdnav = jrefCrdnav;

	mask = {JREFCRDNAV};
};

void SessBrly::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrSessBrly";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefCrdnav"] = Scr::scramble(jrefCrdnav);
};

void SessBrly::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrSessBrly";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrSessBrly";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefCrdnav", Scr::scramble(jrefCrdnav));
	xmlTextWriterEndElement(wr);
};

set<uint> SessBrly::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefCrdnav == comp->jrefCrdnav) insert(items, JREFCRDNAV);

	return(items);
};

set<uint> SessBrly::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFCRDNAV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class SessBrly::DpchEngData
 ******************************************************************************/

SessBrly::DpchEngData::DpchEngData(
			const ubigint jref
			, Feed* feedFEnsSec
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGSESSBRLYDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, FEEDFENSSEC, STATSHR};
	else this->mask = mask;

	if (find(this->mask, FEEDFENSSEC) && feedFEnsSec) this->feedFEnsSec = *feedFEnsSec;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string SessBrly::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(FEEDFENSSEC)) ss.push_back("feedFEnsSec");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void SessBrly::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(FEEDFENSSEC)) {feedFEnsSec = src->feedFEnsSec; add(FEEDFENSSEC);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
};

void SessBrly::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngSessBrlyData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(FEEDFENSSEC)) feedFEnsSec.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
};

void SessBrly::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngSessBrlyData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(FEEDFENSSEC)) feedFEnsSec.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
