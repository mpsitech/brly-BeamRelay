/**
	* \file PnlBrlyNavBase_blks.cpp
	* job handler for job PnlBrlyNavBase (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyNavBase::VecVDo
 ******************************************************************************/

uint PnlBrlyNavBase::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregviewclick") return BUTREGVIEWCLICK;
	if (s == "butregnewcrdclick") return BUTREGNEWCRDCLICK;
	if (s == "butlocviewclick") return BUTLOCVIEWCLICK;
	if (s == "butlocnewcrdclick") return BUTLOCNEWCRDCLICK;
	if (s == "butlegviewclick") return BUTLEGVIEWCLICK;
	if (s == "butlegnewcrdclick") return BUTLEGNEWCRDCLICK;
	if (s == "butttbviewclick") return BUTTTBVIEWCLICK;
	if (s == "butttbnewcrdclick") return BUTTTBNEWCRDCLICK;
	if (s == "butfltviewclick") return BUTFLTVIEWCLICK;
	if (s == "butfltnewcrdclick") return BUTFLTNEWCRDCLICK;
	if (s == "butsegviewclick") return BUTSEGVIEWCLICK;
	if (s == "butsegnewcrdclick") return BUTSEGNEWCRDCLICK;

	return(0);
};

string PnlBrlyNavBase::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGVIEWCLICK) return("ButRegViewClick");
	if (ix == BUTREGNEWCRDCLICK) return("ButRegNewcrdClick");
	if (ix == BUTLOCVIEWCLICK) return("ButLocViewClick");
	if (ix == BUTLOCNEWCRDCLICK) return("ButLocNewcrdClick");
	if (ix == BUTLEGVIEWCLICK) return("ButLegViewClick");
	if (ix == BUTLEGNEWCRDCLICK) return("ButLegNewcrdClick");
	if (ix == BUTTTBVIEWCLICK) return("ButTtbViewClick");
	if (ix == BUTTTBNEWCRDCLICK) return("ButTtbNewcrdClick");
	if (ix == BUTFLTVIEWCLICK) return("ButFltViewClick");
	if (ix == BUTFLTNEWCRDCLICK) return("ButFltNewcrdClick");
	if (ix == BUTSEGVIEWCLICK) return("ButSegViewClick");
	if (ix == BUTSEGNEWCRDCLICK) return("ButSegNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlBrlyNavBase::ContIac
 ******************************************************************************/

PnlBrlyNavBase::ContIac::ContIac(
			const uint numFLstReg
			, const uint numFLstLoc
			, const uint numFLstLeg
			, const uint numFLstTtb
			, const uint numFLstFlt
			, const uint numFLstSeg
		) :
			Block()
		{
	this->numFLstReg = numFLstReg;
	this->numFLstLoc = numFLstLoc;
	this->numFLstLeg = numFLstLeg;
	this->numFLstTtb = numFLstTtb;
	this->numFLstFlt = numFLstFlt;
	this->numFLstSeg = numFLstSeg;

	mask = {NUMFLSTREG, NUMFLSTLOC, NUMFLSTLEG, NUMFLSTTTB, NUMFLSTFLT, NUMFLSTSEG};
};

bool PnlBrlyNavBase::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyNavBase"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstReg")) {numFLstReg = me["numFLstReg"].asUInt(); add(NUMFLSTREG);};
		if (me.isMember("numFLstLoc")) {numFLstLoc = me["numFLstLoc"].asUInt(); add(NUMFLSTLOC);};
		if (me.isMember("numFLstLeg")) {numFLstLeg = me["numFLstLeg"].asUInt(); add(NUMFLSTLEG);};
		if (me.isMember("numFLstTtb")) {numFLstTtb = me["numFLstTtb"].asUInt(); add(NUMFLSTTTB);};
		if (me.isMember("numFLstFlt")) {numFLstFlt = me["numFLstFlt"].asUInt(); add(NUMFLSTFLT);};
		if (me.isMember("numFLstSeg")) {numFLstSeg = me["numFLstSeg"].asUInt(); add(NUMFLSTSEG);};
	};

	return basefound;
};

bool PnlBrlyNavBase::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyNavBase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyNavBase";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstReg", numFLstReg)) add(NUMFLSTREG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLoc", numFLstLoc)) add(NUMFLSTLOC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLeg", numFLstLeg)) add(NUMFLSTLEG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTtb", numFLstTtb)) add(NUMFLSTTTB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFlt", numFLstFlt)) add(NUMFLSTFLT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSeg", numFLstSeg)) add(NUMFLSTSEG);
	};

	return basefound;
};

void PnlBrlyNavBase::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyNavBase";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstReg"] = numFLstReg;
	me["numFLstLoc"] = numFLstLoc;
	me["numFLstLeg"] = numFLstLeg;
	me["numFLstTtb"] = numFLstTtb;
	me["numFLstFlt"] = numFLstFlt;
	me["numFLstSeg"] = numFLstSeg;
};

void PnlBrlyNavBase::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyNavBase";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyNavBase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstReg", numFLstReg);
		writeUintAttr(wr, itemtag, "sref", "numFLstLoc", numFLstLoc);
		writeUintAttr(wr, itemtag, "sref", "numFLstLeg", numFLstLeg);
		writeUintAttr(wr, itemtag, "sref", "numFLstTtb", numFLstTtb);
		writeUintAttr(wr, itemtag, "sref", "numFLstFlt", numFLstFlt);
		writeUintAttr(wr, itemtag, "sref", "numFLstSeg", numFLstSeg);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyNavBase::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstReg == comp->numFLstReg) insert(items, NUMFLSTREG);
	if (numFLstLoc == comp->numFLstLoc) insert(items, NUMFLSTLOC);
	if (numFLstLeg == comp->numFLstLeg) insert(items, NUMFLSTLEG);
	if (numFLstTtb == comp->numFLstTtb) insert(items, NUMFLSTTTB);
	if (numFLstFlt == comp->numFLstFlt) insert(items, NUMFLSTFLT);
	if (numFLstSeg == comp->numFLstSeg) insert(items, NUMFLSTSEG);

	return(items);
};

set<uint> PnlBrlyNavBase::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTREG, NUMFLSTLOC, NUMFLSTLEG, NUMFLSTTTB, NUMFLSTFLT, NUMFLSTSEG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavBase::StatApp
 ******************************************************************************/

void PnlBrlyNavBase::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
			, const bool LstRegAlt
			, const bool LstLocAlt
			, const bool LstLegAlt
			, const bool LstTtbAlt
			, const bool LstFltAlt
			, const bool LstSegAlt
			, const uint LstRegNumFirstdisp
			, const uint LstLocNumFirstdisp
			, const uint LstLegNumFirstdisp
			, const uint LstTtbNumFirstdisp
			, const uint LstFltNumFirstdisp
			, const uint LstSegNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyNavBase";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["LstRegAlt"] = LstRegAlt;
	me["LstLocAlt"] = LstLocAlt;
	me["LstLegAlt"] = LstLegAlt;
	me["LstTtbAlt"] = LstTtbAlt;
	me["LstFltAlt"] = LstFltAlt;
	me["LstSegAlt"] = LstSegAlt;
	me["LstRegNumFirstdisp"] = LstRegNumFirstdisp;
	me["LstLocNumFirstdisp"] = LstLocNumFirstdisp;
	me["LstLegNumFirstdisp"] = LstLegNumFirstdisp;
	me["LstTtbNumFirstdisp"] = LstTtbNumFirstdisp;
	me["LstFltNumFirstdisp"] = LstFltNumFirstdisp;
	me["LstSegNumFirstdisp"] = LstSegNumFirstdisp;
};

void PnlBrlyNavBase::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
			, const bool LstRegAlt
			, const bool LstLocAlt
			, const bool LstLegAlt
			, const bool LstTtbAlt
			, const bool LstFltAlt
			, const bool LstSegAlt
			, const uint LstRegNumFirstdisp
			, const uint LstLocNumFirstdisp
			, const uint LstLegNumFirstdisp
			, const uint LstTtbNumFirstdisp
			, const uint LstFltNumFirstdisp
			, const uint LstSegNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyNavBase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyNavBase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstRegAlt", LstRegAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstLocAlt", LstLocAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstLegAlt", LstLegAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstTtbAlt", LstTtbAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFltAlt", LstFltAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSegAlt", LstSegAlt);
		writeUintAttr(wr, itemtag, "sref", "LstRegNumFirstdisp", LstRegNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstLocNumFirstdisp", LstLocNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstLegNumFirstdisp", LstLegNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstTtbNumFirstdisp", LstTtbNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFltNumFirstdisp", LstFltNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSegNumFirstdisp", LstSegNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavBase::StatShr
 ******************************************************************************/

PnlBrlyNavBase::StatShr::StatShr(
			const bool LstRegAvail
			, const bool ButRegViewActive
			, const bool LstLocAvail
			, const bool ButLocViewActive
			, const bool LstLegAvail
			, const bool ButLegViewActive
			, const bool LstTtbAvail
			, const bool ButTtbViewActive
			, const bool LstFltAvail
			, const bool ButFltViewActive
			, const bool LstSegAvail
			, const bool ButSegViewActive
		) :
			Block()
		{
	this->LstRegAvail = LstRegAvail;
	this->ButRegViewActive = ButRegViewActive;
	this->LstLocAvail = LstLocAvail;
	this->ButLocViewActive = ButLocViewActive;
	this->LstLegAvail = LstLegAvail;
	this->ButLegViewActive = ButLegViewActive;
	this->LstTtbAvail = LstTtbAvail;
	this->ButTtbViewActive = ButTtbViewActive;
	this->LstFltAvail = LstFltAvail;
	this->ButFltViewActive = ButFltViewActive;
	this->LstSegAvail = LstSegAvail;
	this->ButSegViewActive = ButSegViewActive;

	mask = {LSTREGAVAIL, BUTREGVIEWACTIVE, LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTLEGAVAIL, BUTLEGVIEWACTIVE, LSTTTBAVAIL, BUTTTBVIEWACTIVE, LSTFLTAVAIL, BUTFLTVIEWACTIVE, LSTSEGAVAIL, BUTSEGVIEWACTIVE};
};

void PnlBrlyNavBase::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyNavBase";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstRegAvail"] = LstRegAvail;
	me["ButRegViewActive"] = ButRegViewActive;
	me["LstLocAvail"] = LstLocAvail;
	me["ButLocViewActive"] = ButLocViewActive;
	me["LstLegAvail"] = LstLegAvail;
	me["ButLegViewActive"] = ButLegViewActive;
	me["LstTtbAvail"] = LstTtbAvail;
	me["ButTtbViewActive"] = ButTtbViewActive;
	me["LstFltAvail"] = LstFltAvail;
	me["ButFltViewActive"] = ButFltViewActive;
	me["LstSegAvail"] = LstSegAvail;
	me["ButSegViewActive"] = ButSegViewActive;
};

void PnlBrlyNavBase::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyNavBase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyNavBase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstRegAvail", LstRegAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegViewActive", ButRegViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstLocAvail", LstLocAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLocViewActive", ButLocViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstLegAvail", LstLegAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLegViewActive", ButLegViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstTtbAvail", LstTtbAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTtbViewActive", ButTtbViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFltAvail", LstFltAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFltViewActive", ButFltViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSegAvail", LstSegAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSegViewActive", ButSegViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyNavBase::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstRegAvail == comp->LstRegAvail) insert(items, LSTREGAVAIL);
	if (ButRegViewActive == comp->ButRegViewActive) insert(items, BUTREGVIEWACTIVE);
	if (LstLocAvail == comp->LstLocAvail) insert(items, LSTLOCAVAIL);
	if (ButLocViewActive == comp->ButLocViewActive) insert(items, BUTLOCVIEWACTIVE);
	if (LstLegAvail == comp->LstLegAvail) insert(items, LSTLEGAVAIL);
	if (ButLegViewActive == comp->ButLegViewActive) insert(items, BUTLEGVIEWACTIVE);
	if (LstTtbAvail == comp->LstTtbAvail) insert(items, LSTTTBAVAIL);
	if (ButTtbViewActive == comp->ButTtbViewActive) insert(items, BUTTTBVIEWACTIVE);
	if (LstFltAvail == comp->LstFltAvail) insert(items, LSTFLTAVAIL);
	if (ButFltViewActive == comp->ButFltViewActive) insert(items, BUTFLTVIEWACTIVE);
	if (LstSegAvail == comp->LstSegAvail) insert(items, LSTSEGAVAIL);
	if (ButSegViewActive == comp->ButSegViewActive) insert(items, BUTSEGVIEWACTIVE);

	return(items);
};

set<uint> PnlBrlyNavBase::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTREGAVAIL, BUTREGVIEWACTIVE, LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTLEGAVAIL, BUTLEGVIEWACTIVE, LSTTTBAVAIL, BUTTTBVIEWACTIVE, LSTFLTAVAIL, BUTFLTVIEWACTIVE, LSTSEGAVAIL, BUTSEGVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyNavBase::Tag
 ******************************************************************************/

void PnlBrlyNavBase::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyNavBase";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Basic data module";
		me["CptReg"] = "regions";
		me["CptLoc"] = "locations";
		me["CptLeg"] = "legs";
		me["CptTtb"] = "timetables";
		me["CptFlt"] = "flights";
		me["CptSeg"] = "segments";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Stammdaten";
		me["CptReg"] = "Regionen";
		me["CptLoc"] = "Orte";
		me["CptLeg"] = "Strecken";
		me["CptTtb"] = "Flugpl\\u00e4ne";
		me["CptFlt"] = "Fl\\u00fcge";
		me["CptSeg"] = "Segmente";
	};
};

void PnlBrlyNavBase::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyNavBase";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyNavBase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Basic data module");
			writeStringAttr(wr, itemtag, "sref", "CptReg", "regions");
			writeStringAttr(wr, itemtag, "sref", "CptLoc", "locations");
			writeStringAttr(wr, itemtag, "sref", "CptLeg", "legs");
			writeStringAttr(wr, itemtag, "sref", "CptTtb", "timetables");
			writeStringAttr(wr, itemtag, "sref", "CptFlt", "flights");
			writeStringAttr(wr, itemtag, "sref", "CptSeg", "segments");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Stammdaten");
			writeStringAttr(wr, itemtag, "sref", "CptReg", "Regionen");
			writeStringAttr(wr, itemtag, "sref", "CptLoc", "Orte");
			writeStringAttr(wr, itemtag, "sref", "CptLeg", "Strecken");
			writeStringAttr(wr, itemtag, "sref", "CptTtb", "Flugpl\\u00e4ne");
			writeStringAttr(wr, itemtag, "sref", "CptFlt", "Fl\\u00fcge");
			writeStringAttr(wr, itemtag, "sref", "CptSeg", "Segmente");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyNavBase::DpchAppData
 ******************************************************************************/

PnlBrlyNavBase::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVBASEDATA)
		{
};

string PnlBrlyNavBase::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavBase::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyNavBaseData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlBrlyNavBase::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyNavBaseData");
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
 class PnlBrlyNavBase::DpchAppDo
 ******************************************************************************/

PnlBrlyNavBase::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVBASEDO)
		{
	ixVDo = 0;
};

string PnlBrlyNavBase::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavBase::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyNavBaseDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyNavBase::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyNavBaseDo");
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
 class PnlBrlyNavBase::DpchEngData
 ******************************************************************************/

PnlBrlyNavBase::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstFlt
			, Feed* feedFLstLeg
			, Feed* feedFLstLoc
			, Feed* feedFLstReg
			, Feed* feedFLstSeg
			, Feed* feedFLstTtb
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYNAVBASEDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTFLT, FEEDFLSTLEG, FEEDFLSTLOC, FEEDFLSTREG, FEEDFLSTSEG, FEEDFLSTTTB, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTFLT) && feedFLstFlt) this->feedFLstFlt = *feedFLstFlt;
	if (find(this->mask, FEEDFLSTLEG) && feedFLstLeg) this->feedFLstLeg = *feedFLstLeg;
	if (find(this->mask, FEEDFLSTLOC) && feedFLstLoc) this->feedFLstLoc = *feedFLstLoc;
	if (find(this->mask, FEEDFLSTREG) && feedFLstReg) this->feedFLstReg = *feedFLstReg;
	if (find(this->mask, FEEDFLSTSEG) && feedFLstSeg) this->feedFLstSeg = *feedFLstSeg;
	if (find(this->mask, FEEDFLSTTTB) && feedFLstTtb) this->feedFLstTtb = *feedFLstTtb;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyNavBase::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFLT)) ss.push_back("feedFLstFlt");
	if (has(FEEDFLSTLEG)) ss.push_back("feedFLstLeg");
	if (has(FEEDFLSTLOC)) ss.push_back("feedFLstLoc");
	if (has(FEEDFLSTREG)) ss.push_back("feedFLstReg");
	if (has(FEEDFLSTSEG)) ss.push_back("feedFLstSeg");
	if (has(FEEDFLSTTTB)) ss.push_back("feedFLstTtb");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyNavBase::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTFLT)) {feedFLstFlt = src->feedFLstFlt; add(FEEDFLSTFLT);};
	if (src->has(FEEDFLSTLEG)) {feedFLstLeg = src->feedFLstLeg; add(FEEDFLSTLEG);};
	if (src->has(FEEDFLSTLOC)) {feedFLstLoc = src->feedFLstLoc; add(FEEDFLSTLOC);};
	if (src->has(FEEDFLSTREG)) {feedFLstReg = src->feedFLstReg; add(FEEDFLSTREG);};
	if (src->has(FEEDFLSTSEG)) {feedFLstSeg = src->feedFLstSeg; add(FEEDFLSTSEG);};
	if (src->has(FEEDFLSTTTB)) {feedFLstTtb = src->feedFLstTtb; add(FEEDFLSTTTB);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyNavBase::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyNavBaseData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTFLT)) feedFLstFlt.writeJSON(me);
	if (has(FEEDFLSTLEG)) feedFLstLeg.writeJSON(me);
	if (has(FEEDFLSTLOC)) feedFLstLoc.writeJSON(me);
	if (has(FEEDFLSTREG)) feedFLstReg.writeJSON(me);
	if (has(FEEDFLSTSEG)) feedFLstSeg.writeJSON(me);
	if (has(FEEDFLSTTTB)) feedFLstTtb.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyNavBase::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyNavBaseData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTFLT)) feedFLstFlt.writeXML(wr);
		if (has(FEEDFLSTLEG)) feedFLstLeg.writeXML(wr);
		if (has(FEEDFLSTLOC)) feedFLstLoc.writeXML(wr);
		if (has(FEEDFLSTREG)) feedFLstReg.writeXML(wr);
		if (has(FEEDFLSTSEG)) feedFLstSeg.writeXML(wr);
		if (has(FEEDFLSTTTB)) feedFLstTtb.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
