/**
	* \file PnlBrlyUsrHeadbar_blks.cpp
	* job handler for job PnlBrlyUsrHeadbar (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyUsrHeadbar::StgInf
 ******************************************************************************/

void PnlBrlyUsrHeadbar::StgInf::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgInfBrlyUsrHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["MenAppCptwidth"] = "100";
		me["MenAppWidth"] = "176";
		me["MenCrdCptwidth"] = "46";
		me["MenCrdWidth"] = "323";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["MenAppCptwidth"] = "100";
		me["MenAppWidth"] = "176";
		me["MenCrdCptwidth"] = "82";
		me["MenCrdWidth"] = "323";
	};
};

void PnlBrlyUsrHeadbar::StgInf::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfBrlyUsrHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfBrlyUsrHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "176");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "46");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "176");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "82");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyUsrHeadbar::Tag
 ******************************************************************************/

void PnlBrlyUsrHeadbar::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyUsrHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["MenApp"] = "BeamRelay";
		me["MenCrd"] = "User";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["MenApp"] = "BeamRelay";
		me["MenCrd"] = "Benutzer";
	};
};

void PnlBrlyUsrHeadbar::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyUsrHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyUsrHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "BeamRelay");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "User");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "BeamRelay");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Benutzer");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyUsrHeadbar::DpchEngData
 ******************************************************************************/

PnlBrlyUsrHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYUSRHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STGINF, TAG};
	else this->mask = mask;

};

string PnlBrlyUsrHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyUsrHeadbar::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyUsrHeadbar::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyUsrHeadbarData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(STGINF)) StgInf::writeJSON(ixBrlyVLocale, me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyUsrHeadbar::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyUsrHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STGINF)) StgInf::writeXML(ixBrlyVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
