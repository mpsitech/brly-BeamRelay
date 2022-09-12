/**
	* \file PnlBrlyConDetail_blks.cpp
	* job handler for job PnlBrlyConDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyConDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyConDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butfltviewclick") return BUTFLTVIEWCLICK;
	if (s == "butttbviewclick") return BUTTTBVIEWCLICK;
	if (s == "butetyeditclick") return BUTETYEDITCLICK;

	return(0);
};

string PnlBrlyConDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTFLTVIEWCLICK) return("ButFltViewClick");
	if (ix == BUTTTBVIEWCLICK) return("ButTtbViewClick");
	if (ix == BUTETYEDITCLICK) return("ButEtyEditClick");

	return("");
};

/******************************************************************************
 class PnlBrlyConDetail::ContIac
 ******************************************************************************/

PnlBrlyConDetail::ContIac::ContIac(
			const string& TxfSta
			, const string& TxfSto
			, const uint numFPupMod
			, const vector<uint>& numsFLstEty
			, const string& TxfEty
		) :
			Block()
		{
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->numFPupMod = numFPupMod;
	this->numsFLstEty = numsFLstEty;
	this->TxfEty = TxfEty;

	mask = {TXFSTA, TXFSTO, NUMFPUPMOD, NUMSFLSTETY, TXFETY};
};

bool PnlBrlyConDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyConDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfSta")) {TxfSta = me["TxfSta"].asString(); add(TXFSTA);};
		if (me.isMember("TxfSto")) {TxfSto = me["TxfSto"].asString(); add(TXFSTO);};
		if (me.isMember("numFPupMod")) {numFPupMod = me["numFPupMod"].asUInt(); add(NUMFPUPMOD);};
		if (Jsonio::extractUintvec(me, "numsFLstEty", numsFLstEty)) add(NUMSFLSTETY);
		if (me.isMember("TxfEty")) {TxfEty = me["TxfEty"].asString(); add(TXFETY);};
	};

	return basefound;
};

bool PnlBrlyConDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyConDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMod", numFPupMod)) add(NUMFPUPMOD);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstEty", numsFLstEty)) add(NUMSFLSTETY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEty", TxfEty)) add(TXFETY);
	};

	return basefound;
};

void PnlBrlyConDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyConDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfSta"] = TxfSta;
	me["TxfSto"] = TxfSto;
	me["numFPupMod"] = numFPupMod;
	Jsonio::writeUintvec(me, "numsFLstEty", numsFLstEty);
	me["TxfEty"] = TxfEty;
};

void PnlBrlyConDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyConDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeUintAttr(wr, itemtag, "sref", "numFPupMod", numFPupMod);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstEty", numsFLstEty);
		writeStringAttr(wr, itemtag, "sref", "TxfEty", TxfEty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyConDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (numFPupMod == comp->numFPupMod) insert(items, NUMFPUPMOD);
	if (compareUintvec(numsFLstEty, comp->numsFLstEty)) insert(items, NUMSFLSTETY);
	if (TxfEty == comp->TxfEty) insert(items, TXFETY);

	return(items);
};

set<uint> PnlBrlyConDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSTA, TXFSTO, NUMFPUPMOD, NUMSFLSTETY, TXFETY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConDetail::ContInf
 ******************************************************************************/

PnlBrlyConDetail::ContInf::ContInf(
			const string& TxtFlt
			, const string& TxtCor
			, const string& TxtTtb
		) :
			Block()
		{
	this->TxtFlt = TxtFlt;
	this->TxtCor = TxtCor;
	this->TxtTtb = TxtTtb;

	mask = {TXTFLT, TXTCOR, TXTTTB};
};

void PnlBrlyConDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyConDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtFlt"] = TxtFlt;
	me["TxtCor"] = TxtCor;
	me["TxtTtb"] = TxtTtb;
};

void PnlBrlyConDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyConDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFlt", TxtFlt);
		writeStringAttr(wr, itemtag, "sref", "TxtCor", TxtCor);
		writeStringAttr(wr, itemtag, "sref", "TxtTtb", TxtTtb);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyConDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFlt == comp->TxtFlt) insert(items, TXTFLT);
	if (TxtCor == comp->TxtCor) insert(items, TXTCOR);
	if (TxtTtb == comp->TxtTtb) insert(items, TXTTTB);

	return(items);
};

set<uint> PnlBrlyConDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFLT, TXTCOR, TXTTTB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConDetail::StatApp
 ******************************************************************************/

void PnlBrlyConDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
			, const bool LstEtyAlt
			, const uint LstEtyNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyConDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["LstEtyAlt"] = LstEtyAlt;
	me["LstEtyNumFirstdisp"] = LstEtyNumFirstdisp;
};

void PnlBrlyConDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
			, const bool LstEtyAlt
			, const uint LstEtyNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyConDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstEtyAlt", LstEtyAlt);
		writeUintAttr(wr, itemtag, "sref", "LstEtyNumFirstdisp", LstEtyNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConDetail::StatShr
 ******************************************************************************/

PnlBrlyConDetail::StatShr::StatShr(
			const bool TxfEtyValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtFltActive
			, const bool ButFltViewAvail
			, const bool ButFltViewActive
			, const bool TxtCorActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool PupModActive
			, const bool TxtTtbActive
			, const bool ButTtbViewAvail
			, const bool ButTtbViewActive
			, const bool LstEtyActive
			, const bool ButEtyEditAvail
		) :
			Block()
		{
	this->TxfEtyValid = TxfEtyValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtFltActive = TxtFltActive;
	this->ButFltViewAvail = ButFltViewAvail;
	this->ButFltViewActive = ButFltViewActive;
	this->TxtCorActive = TxtCorActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->PupModActive = PupModActive;
	this->TxtTtbActive = TxtTtbActive;
	this->ButTtbViewAvail = ButTtbViewAvail;
	this->ButTtbViewActive = ButTtbViewActive;
	this->LstEtyActive = LstEtyActive;
	this->ButEtyEditAvail = ButEtyEditAvail;

	mask = {TXFETYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFLTACTIVE, BUTFLTVIEWAVAIL, BUTFLTVIEWACTIVE, TXTCORACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, PUPMODACTIVE, TXTTTBACTIVE, BUTTTBVIEWAVAIL, BUTTTBVIEWACTIVE, LSTETYACTIVE, BUTETYEDITAVAIL};
};

void PnlBrlyConDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyConDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfEtyValid"] = TxfEtyValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtFltActive"] = TxtFltActive;
	me["ButFltViewAvail"] = ButFltViewAvail;
	me["ButFltViewActive"] = ButFltViewActive;
	me["TxtCorActive"] = TxtCorActive;
	me["TxfStaActive"] = TxfStaActive;
	me["TxfStoActive"] = TxfStoActive;
	me["PupModActive"] = PupModActive;
	me["TxtTtbActive"] = TxtTtbActive;
	me["ButTtbViewAvail"] = ButTtbViewAvail;
	me["ButTtbViewActive"] = ButTtbViewActive;
	me["LstEtyActive"] = LstEtyActive;
	me["ButEtyEditAvail"] = ButEtyEditAvail;
};

void PnlBrlyConDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyConDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfEtyValid", TxfEtyValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtFltActive", TxtFltActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFltViewAvail", ButFltViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFltViewActive", ButFltViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtCorActive", TxtCorActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStoActive", TxfStoActive);
		writeBoolAttr(wr, itemtag, "sref", "PupModActive", PupModActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTtbActive", TxtTtbActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTtbViewAvail", ButTtbViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTtbViewActive", ButTtbViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstEtyActive", LstEtyActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEtyEditAvail", ButEtyEditAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyConDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfEtyValid == comp->TxfEtyValid) insert(items, TXFETYVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtFltActive == comp->TxtFltActive) insert(items, TXTFLTACTIVE);
	if (ButFltViewAvail == comp->ButFltViewAvail) insert(items, BUTFLTVIEWAVAIL);
	if (ButFltViewActive == comp->ButFltViewActive) insert(items, BUTFLTVIEWACTIVE);
	if (TxtCorActive == comp->TxtCorActive) insert(items, TXTCORACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (PupModActive == comp->PupModActive) insert(items, PUPMODACTIVE);
	if (TxtTtbActive == comp->TxtTtbActive) insert(items, TXTTTBACTIVE);
	if (ButTtbViewAvail == comp->ButTtbViewAvail) insert(items, BUTTTBVIEWAVAIL);
	if (ButTtbViewActive == comp->ButTtbViewActive) insert(items, BUTTTBVIEWACTIVE);
	if (LstEtyActive == comp->LstEtyActive) insert(items, LSTETYACTIVE);
	if (ButEtyEditAvail == comp->ButEtyEditAvail) insert(items, BUTETYEDITAVAIL);

	return(items);
};

set<uint> PnlBrlyConDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFETYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFLTACTIVE, BUTFLTVIEWAVAIL, BUTFLTVIEWACTIVE, TXTCORACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, PUPMODACTIVE, TXTTTBACTIVE, BUTTTBVIEWAVAIL, BUTTTBVIEWACTIVE, LSTETYACTIVE, BUTETYEDITAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyConDetail::Tag
 ******************************************************************************/

void PnlBrlyConDetail::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyConDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["CptFlt"] = "flight";
		me["CptCor"] = "leg";
		me["CptSta"] = "start time";
		me["CptSto"] = "stop time";
		me["CptMod"] = "model";
		me["CptTtb"] = "timetable";
		me["CptEty"] = "equipment types";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["CptFlt"] = "Flug";
		me["CptCor"] = "Strecke";
		me["CptSta"] = "Start";
		me["CptSto"] = "Stopp";
		me["CptMod"] = "model";
		me["CptTtb"] = "Flugplan";
		me["CptEty"] = "Ger\\u00e4ttypen";
	};
	me["Cpt"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale));
};

void PnlBrlyConDetail::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyConDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptFlt", "flight");
			writeStringAttr(wr, itemtag, "sref", "CptCor", "leg");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "start time");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "stop time");
			writeStringAttr(wr, itemtag, "sref", "CptMod", "model");
			writeStringAttr(wr, itemtag, "sref", "CptTtb", "timetable");
			writeStringAttr(wr, itemtag, "sref", "CptEty", "equipment types");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptFlt", "Flug");
			writeStringAttr(wr, itemtag, "sref", "CptCor", "Strecke");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "Start");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "Stopp");
			writeStringAttr(wr, itemtag, "sref", "CptMod", "model");
			writeStringAttr(wr, itemtag, "sref", "CptTtb", "Flugplan");
			writeStringAttr(wr, itemtag, "sref", "CptEty", "Ger\\u00e4ttypen");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyConDetail::DpchAppData
 ******************************************************************************/

PnlBrlyConDetail::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONDETAILDATA)
		{
};

string PnlBrlyConDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyConDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlBrlyConDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyConDetailData");
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
 class PnlBrlyConDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyConDetail::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYCONDETAILDO)
		{
	ixVDo = 0;
};

string PnlBrlyConDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyConDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyConDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyConDetailDo");
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
 class PnlBrlyConDetail::DpchEngData
 ******************************************************************************/

PnlBrlyConDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstEty
			, Feed* feedFPupMod
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYCONDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTETY, FEEDFPUPMOD, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTETY) && feedFLstEty) this->feedFLstEty = *feedFLstEty;
	if (find(this->mask, FEEDFPUPMOD) && feedFPupMod) this->feedFPupMod = *feedFPupMod;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyConDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTETY)) ss.push_back("feedFLstEty");
	if (has(FEEDFPUPMOD)) ss.push_back("feedFPupMod");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyConDetail::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTETY)) {feedFLstEty = src->feedFLstEty; add(FEEDFLSTETY);};
	if (src->has(FEEDFPUPMOD)) {feedFPupMod = src->feedFPupMod; add(FEEDFPUPMOD);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyConDetail::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyConDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFLSTETY)) feedFLstEty.writeJSON(me);
	if (has(FEEDFPUPMOD)) feedFPupMod.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyConDetail::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyConDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTETY)) feedFLstEty.writeXML(wr);
		if (has(FEEDFPUPMOD)) feedFPupMod.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
