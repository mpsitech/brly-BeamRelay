/**
	* \file PnlBrlyFltHeadbar_blks.cpp
	* job handler for job PnlBrlyFltHeadbar (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyFltHeadbar::StgInf
 ******************************************************************************/

void PnlBrlyFltHeadbar::StgInf::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgInfBrlyFltHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["MenAppCptwidth"] = "100";
		me["MenAppWidth"] = "176";
		me["MenCrdCptwidth"] = "64";
		me["MenCrdWidth"] = "323";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["MenAppCptwidth"] = "100";
		me["MenAppWidth"] = "176";
		me["MenCrdCptwidth"] = "46";
		me["MenCrdWidth"] = "323";
	};
};

void PnlBrlyFltHeadbar::StgInf::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfBrlyFltHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfBrlyFltHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "176");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "64");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "176");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "46");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltHeadbar::Tag
 ******************************************************************************/

void PnlBrlyFltHeadbar::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyFltHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["MenApp"] = "BeamRelay";
		me["MenCrd"] = "Flight";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["MenApp"] = "BeamRelay";
		me["MenCrd"] = "Flug";
	};
};

void PnlBrlyFltHeadbar::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyFltHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyFltHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "BeamRelay");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Flight");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "BeamRelay");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Flug");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltHeadbar::DpchEngData
 ******************************************************************************/

PnlBrlyFltHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYFLTHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STGINF, TAG};
	else this->mask = mask;

};

string PnlBrlyFltHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltHeadbar::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyFltHeadbar::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyFltHeadbarData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(STGINF)) StgInf::writeJSON(ixBrlyVLocale, me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyFltHeadbar::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyFltHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STGINF)) StgInf::writeXML(ixBrlyVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
