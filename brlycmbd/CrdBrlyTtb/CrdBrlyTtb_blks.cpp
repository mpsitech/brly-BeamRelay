/**
	* \file CrdBrlyTtb_blks.cpp
	* job handler for job CrdBrlyTtb (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdBrlyTtb::VecVDo
 ******************************************************************************/

uint CrdBrlyTtb::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	if (s == "mitcrdtrlclick") return MITCRDTRLCLICK;
	if (s == "mitcrdiflclick") return MITCRDIFLCLICK;

	return(0);
};

string CrdBrlyTtb::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	if (ix == MITCRDTRLCLICK) return("MitCrdTrlClick");
	if (ix == MITCRDIFLCLICK) return("MitCrdIflClick");

	return("");
};

/******************************************************************************
 class CrdBrlyTtb::VecVSge
 ******************************************************************************/

uint CrdBrlyTtb::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrbrlyabt") return ALRBRLYABT;
	if (s == "impidle") return IMPIDLE;
	if (s == "import") return IMPORT;
	if (s == "impdone") return IMPDONE;
	if (s == "segment") return SEGMENT;
	if (s == "segdone") return SEGDONE;

	return(0);
};

string CrdBrlyTtb::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRBRLYABT) return("alrbrlyabt");
	if (ix == IMPIDLE) return("impidle");
	if (ix == IMPORT) return("import");
	if (ix == IMPDONE) return("impdone");
	if (ix == SEGMENT) return("segment");
	if (ix == SEGDONE) return("segdone");

	return("");
};

void CrdBrlyTtb::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 7; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdBrlyTtb::ContInf
 ******************************************************************************/

CrdBrlyTtb::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdTtb
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdTtb = MtxCrdTtb;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDTTB};
};

void CrdBrlyTtb::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyTtb";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
	me["MtxCrdTtb"] = MtxCrdTtb;
};

void CrdBrlyTtb::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyTtb";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyTtb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdTtb", MtxCrdTtb);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdBrlyTtb::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdTtb == comp->MtxCrdTtb) insert(items, MTXCRDTTB);

	return(items);
};

set<uint> CrdBrlyTtb::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDTTB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyTtb::StatApp
 ******************************************************************************/

void CrdBrlyTtb::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyTtb";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVReqitmode"] = VecBrlyVReqitmode::getSref(ixBrlyVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdoneList"] = initdoneList;
	me["initdoneRec"] = initdoneRec;
};

void CrdBrlyTtb::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyTtb";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyTtb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVReqitmode", VecBrlyVReqitmode::getSref(ixBrlyVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneList", initdoneList);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRec", initdoneRec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdBrlyTtb::StatShr
 ******************************************************************************/

CrdBrlyTtb::StatShr::StatShr(
			const ubigint jrefDlgimpflt
			, const ubigint jrefDlgnew
			, const ubigint jrefDlgtrlorig
			, const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdTrlAvail
			, const bool MitCrdIflAvail
			, const bool MitCrdIflActive
		) :
			Block()
		{
	this->jrefDlgimpflt = jrefDlgimpflt;
	this->jrefDlgnew = jrefDlgnew;
	this->jrefDlgtrlorig = jrefDlgtrlorig;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefList = jrefList;
	this->jrefRec = jrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdNewAvail = MitCrdNewAvail;
	this->MitCrdTrlAvail = MitCrdTrlAvail;
	this->MitCrdIflAvail = MitCrdIflAvail;
	this->MitCrdIflActive = MitCrdIflActive;

	mask = {JREFDLGIMPFLT, JREFDLGNEW, JREFDLGTRLORIG, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDTRLAVAIL, MITCRDIFLAVAIL, MITCRDIFLACTIVE};
};

void CrdBrlyTtb::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyTtb";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefDlgimpflt"] = Scr::scramble(jrefDlgimpflt);
	me["scrJrefDlgnew"] = Scr::scramble(jrefDlgnew);
	me["scrJrefDlgtrlorig"] = Scr::scramble(jrefDlgtrlorig);
	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefList"] = Scr::scramble(jrefList);
	me["scrJrefRec"] = Scr::scramble(jrefRec);
	me["MspCrd1Avail"] = MspCrd1Avail;
	me["MitCrdNewAvail"] = MitCrdNewAvail;
	me["MitCrdTrlAvail"] = MitCrdTrlAvail;
	me["MitCrdIflAvail"] = MitCrdIflAvail;
	me["MitCrdIflActive"] = MitCrdIflActive;
};

void CrdBrlyTtb::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyTtb";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyTtb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgimpflt", Scr::scramble(jrefDlgimpflt));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgnew", Scr::scramble(jrefDlgnew));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgtrlorig", Scr::scramble(jrefDlgtrlorig));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(jrefRec));
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdNewAvail", MitCrdNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTrlAvail", MitCrdTrlAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIflAvail", MitCrdIflAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIflActive", MitCrdIflActive);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdBrlyTtb::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgimpflt == comp->jrefDlgimpflt) insert(items, JREFDLGIMPFLT);
	if (jrefDlgnew == comp->jrefDlgnew) insert(items, JREFDLGNEW);
	if (jrefDlgtrlorig == comp->jrefDlgtrlorig) insert(items, JREFDLGTRLORIG);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdTrlAvail == comp->MitCrdTrlAvail) insert(items, MITCRDTRLAVAIL);
	if (MitCrdIflAvail == comp->MitCrdIflAvail) insert(items, MITCRDIFLAVAIL);
	if (MitCrdIflActive == comp->MitCrdIflActive) insert(items, MITCRDIFLACTIVE);

	return(items);
};

set<uint> CrdBrlyTtb::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGIMPFLT, JREFDLGNEW, JREFDLGTRLORIG, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDTRLAVAIL, MITCRDIFLAVAIL, MITCRDIFLACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyTtb::Tag
 ******************************************************************************/

void CrdBrlyTtb::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyTtb";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["MitCrdTrl"] = "Translate from original format ...";
		me["MitCrdIfl"] = "Import flights ...";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["MitCrdTrl"] = "Aus Original-Format \\u00fcbersetzen ...";
		me["MitCrdIfl"] = "Fl\\u00fcge importieren ...";
	};
	me["MitAppAbt"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::ABOUT, ixBrlyVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::HELP, ixBrlyVLocale)) + " ...";
	me["MitCrdNew"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::NEW, ixBrlyVLocale)) + " ...";
};

void CrdBrlyTtb::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyTtb";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyTtb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdTrl", "Translate from original format ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIfl", "Import flights ...");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdTrl", "Aus Original-Format \\u00fcbersetzen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIfl", "Fl\\u00fcge importieren ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::ABOUT, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::HELP, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitCrdNew", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::NEW, ixBrlyVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdBrlyTtb::DpchAppDo
 ******************************************************************************/

CrdBrlyTtb::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYTTBDO)
		{
	ixVDo = 0;
};

string CrdBrlyTtb::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdBrlyTtb::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyTtbDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdBrlyTtb::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyTtbDo");
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
 class CrdBrlyTtb::DpchEngData
 ******************************************************************************/

CrdBrlyTtb::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYTTBDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdBrlyTtb::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdBrlyTtb::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdBrlyTtb::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyTtbData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void CrdBrlyTtb::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyTtbData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
