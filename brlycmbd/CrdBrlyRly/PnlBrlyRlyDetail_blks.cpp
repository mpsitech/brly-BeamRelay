/**
	* \file PnlBrlyRlyDetail_blks.cpp
	* job handler for job PnlBrlyRlyDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyRlyDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyRlyDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butconviewclick") return BUTCONVIEWCLICK;

	return(0);
};

string PnlBrlyRlyDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCONVIEWCLICK) return("ButConViewClick");

	return("");
};

/******************************************************************************
 class PnlBrlyRlyDetail::ContIac
 ******************************************************************************/

PnlBrlyRlyDetail::ContIac::ContIac(
			const string& TxfSta
			, const string& TxfSto
			, const uint numFPupDir
			, const bool ChkCtd
			, const string& TxfNhp
		) :
			Block()
		{
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->numFPupDir = numFPupDir;
	this->ChkCtd = ChkCtd;
	this->TxfNhp = TxfNhp;

	mask = {TXFSTA, TXFSTO, NUMFPUPDIR, CHKCTD, TXFNHP};
};

bool PnlBrlyRlyDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyRlyDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfSta")) {TxfSta = me["TxfSta"].asString(); add(TXFSTA);};
		if (me.isMember("TxfSto")) {TxfSto = me["TxfSto"].asString(); add(TXFSTO);};
		if (me.isMember("numFPupDir")) {numFPupDir = me["numFPupDir"].asUInt(); add(NUMFPUPDIR);};
		if (me.isMember("ChkCtd")) {ChkCtd = me["ChkCtd"].asBool(); add(CHKCTD);};
		if (me.isMember("TxfNhp")) {TxfNhp = me["TxfNhp"].asString(); add(TXFNHP);};
	};

	return basefound;
};

bool PnlBrlyRlyDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyRlyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyRlyDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupDir", numFPupDir)) add(NUMFPUPDIR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCtd", ChkCtd)) add(CHKCTD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfNhp", TxfNhp)) add(TXFNHP);
	};

	return basefound;
};

void PnlBrlyRlyDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyRlyDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfSta"] = TxfSta;
	me["TxfSto"] = TxfSto;
	me["numFPupDir"] = numFPupDir;
	me["ChkCtd"] = ChkCtd;
	me["TxfNhp"] = TxfNhp;
};

void PnlBrlyRlyDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyRlyDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyRlyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeUintAttr(wr, itemtag, "sref", "numFPupDir", numFPupDir);
		writeBoolAttr(wr, itemtag, "sref", "ChkCtd", ChkCtd);
		writeStringAttr(wr, itemtag, "sref", "TxfNhp", TxfNhp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyRlyDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (numFPupDir == comp->numFPupDir) insert(items, NUMFPUPDIR);
	if (ChkCtd == comp->ChkCtd) insert(items, CHKCTD);
	if (TxfNhp == comp->TxfNhp) insert(items, TXFNHP);

	return(items);
};

set<uint> PnlBrlyRlyDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSTA, TXFSTO, NUMFPUPDIR, CHKCTD, TXFNHP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRlyDetail::ContInf
 ******************************************************************************/

PnlBrlyRlyDetail::ContInf::ContInf(
			const string& TxtCon
		) :
			Block()
		{
	this->TxtCon = TxtCon;

	mask = {TXTCON};
};

void PnlBrlyRlyDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyRlyDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtCon"] = TxtCon;
};

void PnlBrlyRlyDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyRlyDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyRlyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCon", TxtCon);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyRlyDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtCon == comp->TxtCon) insert(items, TXTCON);

	return(items);
};

set<uint> PnlBrlyRlyDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCON};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRlyDetail::StatApp
 ******************************************************************************/

void PnlBrlyRlyDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyRlyDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
};

void PnlBrlyRlyDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyRlyDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyRlyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyRlyDetail::StatShr
 ******************************************************************************/

PnlBrlyRlyDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool TxtConActive
			, const bool ButConViewAvail
			, const bool ButConViewActive
			, const bool PupDirActive
			, const bool ChkCtdActive
			, const bool TxfNhpActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->TxtConActive = TxtConActive;
	this->ButConViewAvail = ButConViewAvail;
	this->ButConViewActive = ButConViewActive;
	this->PupDirActive = PupDirActive;
	this->ChkCtdActive = ChkCtdActive;
	this->TxfNhpActive = TxfNhpActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXTCONACTIVE, BUTCONVIEWAVAIL, BUTCONVIEWACTIVE, PUPDIRACTIVE, CHKCTDACTIVE, TXFNHPACTIVE};
};

void PnlBrlyRlyDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyRlyDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxfStaActive"] = TxfStaActive;
	me["TxfStoActive"] = TxfStoActive;
	me["TxtConActive"] = TxtConActive;
	me["ButConViewAvail"] = ButConViewAvail;
	me["ButConViewActive"] = ButConViewActive;
	me["PupDirActive"] = PupDirActive;
	me["ChkCtdActive"] = ChkCtdActive;
	me["TxfNhpActive"] = TxfNhpActive;
};

void PnlBrlyRlyDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyRlyDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyRlyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStoActive", TxfStoActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtConActive", TxtConActive);
		writeBoolAttr(wr, itemtag, "sref", "ButConViewAvail", ButConViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButConViewActive", ButConViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupDirActive", PupDirActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkCtdActive", ChkCtdActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfNhpActive", TxfNhpActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyRlyDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (TxtConActive == comp->TxtConActive) insert(items, TXTCONACTIVE);
	if (ButConViewAvail == comp->ButConViewAvail) insert(items, BUTCONVIEWAVAIL);
	if (ButConViewActive == comp->ButConViewActive) insert(items, BUTCONVIEWACTIVE);
	if (PupDirActive == comp->PupDirActive) insert(items, PUPDIRACTIVE);
	if (ChkCtdActive == comp->ChkCtdActive) insert(items, CHKCTDACTIVE);
	if (TxfNhpActive == comp->TxfNhpActive) insert(items, TXFNHPACTIVE);

	return(items);
};

set<uint> PnlBrlyRlyDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXTCONACTIVE, BUTCONVIEWAVAIL, BUTCONVIEWACTIVE, PUPDIRACTIVE, CHKCTDACTIVE, TXFNHPACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRlyDetail::Tag
 ******************************************************************************/

void PnlBrlyRlyDetail::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyRlyDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["CptSta"] = "x1Start";
		me["CptSto"] = "x1Stop";
		me["CptCon"] = "connection";
		me["CptDir"] = "direction";
		me["CptCtd"] = "connected";
		me["CptNhp"] = "number of hops";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["CptSta"] = "x1Start";
		me["CptSto"] = "x1Stop";
		me["CptCon"] = "Verbindung";
		me["CptDir"] = "direction";
		me["CptCtd"] = "verbunden";
		me["CptNhp"] = "Anzahl der Etappen";
	};
	me["Cpt"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale));
};

void PnlBrlyRlyDetail::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyRlyDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyRlyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSta", "x1Start");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "x1Stop");
			writeStringAttr(wr, itemtag, "sref", "CptCon", "connection");
			writeStringAttr(wr, itemtag, "sref", "CptDir", "direction");
			writeStringAttr(wr, itemtag, "sref", "CptCtd", "connected");
			writeStringAttr(wr, itemtag, "sref", "CptNhp", "number of hops");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptSta", "x1Start");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "x1Stop");
			writeStringAttr(wr, itemtag, "sref", "CptCon", "Verbindung");
			writeStringAttr(wr, itemtag, "sref", "CptDir", "direction");
			writeStringAttr(wr, itemtag, "sref", "CptCtd", "verbunden");
			writeStringAttr(wr, itemtag, "sref", "CptNhp", "Anzahl der Etappen");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyRlyDetail::DpchAppData
 ******************************************************************************/

PnlBrlyRlyDetail::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYRLYDETAILDATA)
		{
};

string PnlBrlyRlyDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRlyDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyRlyDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlBrlyRlyDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyRlyDetailData");
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
 class PnlBrlyRlyDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyRlyDetail::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYRLYDETAILDO)
		{
	ixVDo = 0;
};

string PnlBrlyRlyDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRlyDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyRlyDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyRlyDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyRlyDetailDo");
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
 class PnlBrlyRlyDetail::DpchEngData
 ******************************************************************************/

PnlBrlyRlyDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupDir
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYRLYDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPDIR, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPDIR) && feedFPupDir) this->feedFPupDir = *feedFPupDir;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyRlyDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPDIR)) ss.push_back("feedFPupDir");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRlyDetail::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPDIR)) {feedFPupDir = src->feedFPupDir; add(FEEDFPUPDIR);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyRlyDetail::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyRlyDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPDIR)) feedFPupDir.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyRlyDetail::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyRlyDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPDIR)) feedFPupDir.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
