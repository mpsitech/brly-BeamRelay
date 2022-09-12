/**
	* \file PnlBrlyRegDetail_blks.cpp
	* job handler for job PnlBrlyRegDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyRegDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyRegDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjtieditclick") return BUTJTIEDITCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "butjeditclick") return BUTJEDITCLICK;

	return(0);
};

string PnlBrlyRegDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTJEDITCLICK) return("ButJEditClick");

	return("");
};

/******************************************************************************
 class PnlBrlyRegDetail::ContIac
 ******************************************************************************/

PnlBrlyRegDetail::ContIac::ContIac(
			const uint numFPupJti
			, const uint numFPupJ
			, const uint numFPupDst
		) :
			Block()
		{
	this->numFPupJti = numFPupJti;
	this->numFPupJ = numFPupJ;
	this->numFPupDst = numFPupDst;

	mask = {NUMFPUPJTI, NUMFPUPJ, NUMFPUPDST};
};

bool PnlBrlyRegDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyRegDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupJti")) {numFPupJti = me["numFPupJti"].asUInt(); add(NUMFPUPJTI);};
		if (me.isMember("numFPupJ")) {numFPupJ = me["numFPupJ"].asUInt(); add(NUMFPUPJ);};
		if (me.isMember("numFPupDst")) {numFPupDst = me["numFPupDst"].asUInt(); add(NUMFPUPDST);};
	};

	return basefound;
};

bool PnlBrlyRegDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyRegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyRegDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJti", numFPupJti)) add(NUMFPUPJTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupDst", numFPupDst)) add(NUMFPUPDST);
	};

	return basefound;
};

void PnlBrlyRegDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyRegDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupJti"] = numFPupJti;
	me["numFPupJ"] = numFPupJ;
	me["numFPupDst"] = numFPupDst;
};

void PnlBrlyRegDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyRegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyRegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJti", numFPupJti);
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeUintAttr(wr, itemtag, "sref", "numFPupDst", numFPupDst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyRegDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJti == comp->numFPupJti) insert(items, NUMFPUPJTI);
	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (numFPupDst == comp->numFPupDst) insert(items, NUMFPUPDST);

	return(items);
};

set<uint> PnlBrlyRegDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJTI, NUMFPUPJ, NUMFPUPDST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRegDetail::ContInf
 ******************************************************************************/

PnlBrlyRegDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTit
			, const string& TxtSup
			, const string& TxtTof
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTit = TxtTit;
	this->TxtSup = TxtSup;
	this->TxtTof = TxtTof;

	mask = {TXTSRF, TXTTIT, TXTSUP, TXTTOF};
};

void PnlBrlyRegDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyRegDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtTit"] = TxtTit;
	me["TxtSup"] = TxtSup;
	me["TxtTof"] = TxtTof;
};

void PnlBrlyRegDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyRegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyRegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtTit", TxtTit);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
		writeStringAttr(wr, itemtag, "sref", "TxtTof", TxtTof);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyRegDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTit == comp->TxtTit) insert(items, TXTTIT);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtTof == comp->TxtTof) insert(items, TXTTOF);

	return(items);
};

set<uint> PnlBrlyRegDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTIT, TXTSUP, TXTTOF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRegDetail::StatApp
 ******************************************************************************/

void PnlBrlyRegDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyRegDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
};

void PnlBrlyRegDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyRegDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyRegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyRegDetail::StatShr
 ******************************************************************************/

PnlBrlyRegDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupJtiActive
			, const bool ButJtiEditAvail
			, const bool TxtTitActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool PupJActive
			, const bool ButJEditAvail
			, const bool PupDstActive
			, const bool TxtTofActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupJtiActive = PupJtiActive;
	this->ButJtiEditAvail = ButJtiEditAvail;
	this->TxtTitActive = TxtTitActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->PupJActive = PupJActive;
	this->ButJEditAvail = ButJEditAvail;
	this->PupDstActive = PupDstActive;
	this->TxtTofActive = TxtTofActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, PUPJACTIVE, BUTJEDITAVAIL, PUPDSTACTIVE, TXTTOFACTIVE};
};

void PnlBrlyRegDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyRegDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["PupJtiActive"] = PupJtiActive;
	me["ButJtiEditAvail"] = ButJtiEditAvail;
	me["TxtTitActive"] = TxtTitActive;
	me["TxtSupActive"] = TxtSupActive;
	me["ButSupViewAvail"] = ButSupViewAvail;
	me["ButSupViewActive"] = ButSupViewActive;
	me["PupJActive"] = PupJActive;
	me["ButJEditAvail"] = ButJEditAvail;
	me["PupDstActive"] = PupDstActive;
	me["TxtTofActive"] = TxtTofActive;
};

void PnlBrlyRegDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyRegDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyRegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJtiActive", PupJtiActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJtiEditAvail", ButJtiEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtTitActive", TxtTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSupActive", TxtSupActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewAvail", ButSupViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewActive", ButSupViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJActive", PupJActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJEditAvail", ButJEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupDstActive", PupDstActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTofActive", TxtTofActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyRegDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupJtiActive == comp->PupJtiActive) insert(items, PUPJTIACTIVE);
	if (ButJtiEditAvail == comp->ButJtiEditAvail) insert(items, BUTJTIEDITAVAIL);
	if (TxtTitActive == comp->TxtTitActive) insert(items, TXTTITACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (PupJActive == comp->PupJActive) insert(items, PUPJACTIVE);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (PupDstActive == comp->PupDstActive) insert(items, PUPDSTACTIVE);
	if (TxtTofActive == comp->TxtTofActive) insert(items, TXTTOFACTIVE);

	return(items);
};

set<uint> PnlBrlyRegDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, PUPJACTIVE, BUTJEDITAVAIL, PUPDSTACTIVE, TXTTOFACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyRegDetail::Tag
 ******************************************************************************/

void PnlBrlyRegDetail::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyRegDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptTit"] = "name";
		me["CptSup"] = "super region";
		me["CptDst"] = "DST type";
		me["CptTof"] = "time zone";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["CptSrf"] = "Bezeichner";
		me["CptTit"] = "Name";
		me["CptSup"] = "\\u00dcberregion";
		me["CptDst"] = "DST type";
		me["CptTof"] = "Zeitzone";
	};
	me["Cpt"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale));
};

void PnlBrlyRegDetail::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyRegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyRegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "super region");
			writeStringAttr(wr, itemtag, "sref", "CptDst", "DST type");
			writeStringAttr(wr, itemtag, "sref", "CptTof", "time zone");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "Bezeichner");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "\\u00dcberregion");
			writeStringAttr(wr, itemtag, "sref", "CptDst", "DST type");
			writeStringAttr(wr, itemtag, "sref", "CptTof", "Zeitzone");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyRegDetail::DpchAppData
 ******************************************************************************/

PnlBrlyRegDetail::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYREGDETAILDATA)
		{
};

string PnlBrlyRegDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRegDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyRegDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlBrlyRegDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyRegDetailData");
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
 class PnlBrlyRegDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyRegDetail::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYREGDETAILDO)
		{
	ixVDo = 0;
};

string PnlBrlyRegDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRegDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyRegDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyRegDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyRegDetailDo");
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
 class PnlBrlyRegDetail::DpchEngData
 ******************************************************************************/

PnlBrlyRegDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupDst
			, Feed* feedFPupJ
			, Feed* feedFPupJti
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYREGDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPDST, FEEDFPUPJ, FEEDFPUPJTI, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPDST) && feedFPupDst) this->feedFPupDst = *feedFPupDst;
	if (find(this->mask, FEEDFPUPJ) && feedFPupJ) this->feedFPupJ = *feedFPupJ;
	if (find(this->mask, FEEDFPUPJTI) && feedFPupJti) this->feedFPupJti = *feedFPupJti;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyRegDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPDST)) ss.push_back("feedFPupDst");
	if (has(FEEDFPUPJ)) ss.push_back("feedFPupJ");
	if (has(FEEDFPUPJTI)) ss.push_back("feedFPupJti");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyRegDetail::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPDST)) {feedFPupDst = src->feedFPupDst; add(FEEDFPUPDST);};
	if (src->has(FEEDFPUPJ)) {feedFPupJ = src->feedFPupJ; add(FEEDFPUPJ);};
	if (src->has(FEEDFPUPJTI)) {feedFPupJti = src->feedFPupJti; add(FEEDFPUPJTI);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyRegDetail::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyRegDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPDST)) feedFPupDst.writeJSON(me);
	if (has(FEEDFPUPJ)) feedFPupJ.writeJSON(me);
	if (has(FEEDFPUPJTI)) feedFPupJti.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void PnlBrlyRegDetail::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyRegDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPDST)) feedFPupDst.writeXML(wr);
		if (has(FEEDFPUPJ)) feedFPupJ.writeXML(wr);
		if (has(FEEDFPUPJTI)) feedFPupJti.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
