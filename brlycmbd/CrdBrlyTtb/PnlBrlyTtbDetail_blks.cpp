/**
	* \file PnlBrlyTtbDetail_blks.cpp
	* job handler for job PnlBrlyTtbDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyTtbDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyTtbDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	if (s == "butalieditclick") return BUTALIEDITCLICK;

	return(0);
};

string PnlBrlyTtbDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	if (ix == BUTALIEDITCLICK) return("ButAliEditClick");

	return("");
};

/******************************************************************************
 class PnlBrlyTtbDetail::ContIac
 ******************************************************************************/

PnlBrlyTtbDetail::ContIac::ContIac(
			const string& TxfTit
			, const uint numFPupAli
			, const string& TxfAli
			, const string& TxfSta
			, const string& TxfSto
		) :
			Block()
		{
	this->TxfTit = TxfTit;
	this->numFPupAli = numFPupAli;
	this->TxfAli = TxfAli;
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;

	mask = {TXFTIT, NUMFPUPALI, TXFALI, TXFSTA, TXFSTO};
};

bool PnlBrlyTtbDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyTtbDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfTit")) {TxfTit = me["TxfTit"].asString(); add(TXFTIT);};
		if (me.isMember("numFPupAli")) {numFPupAli = me["numFPupAli"].asUInt(); add(NUMFPUPALI);};
		if (me.isMember("TxfAli")) {TxfAli = me["TxfAli"].asString(); add(TXFALI);};
		if (me.isMember("TxfSta")) {TxfSta = me["TxfSta"].asString(); add(TXFSTA);};
		if (me.isMember("TxfSto")) {TxfSto = me["TxfSto"].asString(); add(TXFSTO);};
	};

	return basefound;
};

bool PnlBrlyTtbDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyTtbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyTtbDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAli", numFPupAli)) add(NUMFPUPALI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAli", TxfAli)) add(TXFALI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
	};

	return basefound;
};

void PnlBrlyTtbDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyTtbDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfTit"] = TxfTit;
	me["numFPupAli"] = numFPupAli;
	me["TxfAli"] = TxfAli;
	me["TxfSta"] = TxfSta;
	me["TxfSto"] = TxfSto;
};

void PnlBrlyTtbDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyTtbDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyTtbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupAli", numFPupAli);
		writeStringAttr(wr, itemtag, "sref", "TxfAli", TxfAli);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyTtbDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (numFPupAli == comp->numFPupAli) insert(items, NUMFPUPALI);
	if (TxfAli == comp->TxfAli) insert(items, TXFALI);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);

	return(items);
};

set<uint> PnlBrlyTtbDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMFPUPALI, TXFALI, TXFSTA, TXFSTO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyTtbDetail::ContInf
 ******************************************************************************/

PnlBrlyTtbDetail::ContInf::ContInf(
			const string& TxtFil
		) :
			Block()
		{
	this->TxtFil = TxtFil;

	mask = {TXTFIL};
};

void PnlBrlyTtbDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyTtbDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtFil"] = TxtFil;
};

void PnlBrlyTtbDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyTtbDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyTtbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFil", TxtFil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyTtbDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFil == comp->TxtFil) insert(items, TXTFIL);

	return(items);
};

set<uint> PnlBrlyTtbDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyTtbDetail::StatApp
 ******************************************************************************/

void PnlBrlyTtbDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
			, const bool PupAliAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyTtbDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["PupAliAlt"] = PupAliAlt;
};

void PnlBrlyTtbDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
			, const bool PupAliAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyTtbDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyTtbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupAliAlt", PupAliAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyTtbDetail::StatShr
 ******************************************************************************/

PnlBrlyTtbDetail::StatShr::StatShr(
			const bool TxfAliValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxfTitActive
			, const bool TxtFilActive
			, const bool ButFilViewAvail
			, const bool ButFilViewActive
			, const bool PupAliActive
			, const bool ButAliEditAvail
			, const bool TxfStaActive
			, const bool TxfStoActive
		) :
			Block()
		{
	this->TxfAliValid = TxfAliValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxfTitActive = TxfTitActive;
	this->TxtFilActive = TxtFilActive;
	this->ButFilViewAvail = ButFilViewAvail;
	this->ButFilViewActive = ButFilViewActive;
	this->PupAliActive = PupAliActive;
	this->ButAliEditAvail = ButAliEditAvail;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;

	mask = {TXFALIVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXTFILACTIVE, BUTFILVIEWAVAIL, BUTFILVIEWACTIVE, PUPALIACTIVE, BUTALIEDITAVAIL, TXFSTAACTIVE, TXFSTOACTIVE};
};

void PnlBrlyTtbDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyTtbDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfAliValid"] = TxfAliValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxfTitActive"] = TxfTitActive;
	me["TxtFilActive"] = TxtFilActive;
	me["ButFilViewAvail"] = ButFilViewAvail;
	me["ButFilViewActive"] = ButFilViewActive;
	me["PupAliActive"] = PupAliActive;
	me["ButAliEditAvail"] = ButAliEditAvail;
	me["TxfStaActive"] = TxfStaActive;
	me["TxfStoActive"] = TxfStoActive;
};

void PnlBrlyTtbDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyTtbDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyTtbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfAliValid", TxfAliValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTitActive", TxfTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtFilActive", TxtFilActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFilViewAvail", ButFilViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFilViewActive", ButFilViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupAliActive", PupAliActive);
		writeBoolAttr(wr, itemtag, "sref", "ButAliEditAvail", ButAliEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStoActive", TxfStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyTtbDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfAliValid == comp->TxfAliValid) insert(items, TXFALIVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxtFilActive == comp->TxtFilActive) insert(items, TXTFILACTIVE);
	if (ButFilViewAvail == comp->ButFilViewAvail) insert(items, BUTFILVIEWAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);
	if (PupAliActive == comp->PupAliActive) insert(items, PUPALIACTIVE);
	if (ButAliEditAvail == comp->ButAliEditAvail) insert(items, BUTALIEDITAVAIL);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);

	return(items);
};

set<uint> PnlBrlyTtbDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFALIVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXTFILACTIVE, BUTFILVIEWAVAIL, BUTFILVIEWACTIVE, PUPALIACTIVE, BUTALIEDITAVAIL, TXFSTAACTIVE, TXFSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyTtbDetail::Tag
 ******************************************************************************/

void PnlBrlyTtbDetail::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyTtbDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["CptTit"] = "name";
		me["CptFil"] = "file";
		me["CptAli"] = "airline alliance";
		me["CptSta"] = "validity start";
		me["CptSto"] = "validity stop";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["CptTit"] = "Name";
		me["CptFil"] = "Datei";
		me["CptAli"] = "Luftfahrtallianz";
		me["CptSta"] = "G\\u00fcltigkeitsbeginn";
		me["CptSto"] = "G\\u00fcltigkeitsende";
	};
	me["Cpt"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale));
};

void PnlBrlyTtbDetail::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyTtbDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyTtbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "file");
			writeStringAttr(wr, itemtag, "sref", "CptAli", "airline alliance");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "validity start");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "validity stop");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Datei");
			writeStringAttr(wr, itemtag, "sref", "CptAli", "Luftfahrtallianz");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "G\\u00fcltigkeitsbeginn");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "G\\u00fcltigkeitsende");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyTtbDetail::DpchAppData
 ******************************************************************************/

PnlBrlyTtbDetail::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYTTBDETAILDATA)
		{
};

string PnlBrlyTtbDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyTtbDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyTtbDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlBrlyTtbDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyTtbDetailData");
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
 class PnlBrlyTtbDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyTtbDetail::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYTTBDETAILDO)
		{
	ixVDo = 0;
};

string PnlBrlyTtbDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyTtbDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyTtbDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyTtbDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyTtbDetailDo");
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
 class PnlBrlyTtbDetail::DpchEngData
 ******************************************************************************/

PnlBrlyTtbDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupAli
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYTTBDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPALI, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPALI) && feedFPupAli) this->feedFPupAli = *feedFPupAli;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyTtbDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPALI)) ss.push_back("feedFPupAli");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyTtbDetail::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPALI)) {feedFPupAli = src->feedFPupAli; add(FEEDFPUPALI);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyTtbDetail::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyTtbDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPALI)) feedFPupAli.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyTtbDetail::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyTtbDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPALI)) feedFPupAli.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
