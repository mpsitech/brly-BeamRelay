/**
	* \file PnlBrlyFilList_blks.cpp
	* job handler for job PnlBrlyFilList (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlBrlyFilList::VecVDo
 ******************************************************************************/

uint PnlBrlyFilList::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butfilterclick") return BUTFILTERCLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlBrlyFilList::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTFILTERCLICK) return("ButFilterClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlBrlyFilList::ContIac
 ******************************************************************************/

PnlBrlyFilList::ContIac::ContIac(
			const uint numFTos
		) :
			Block()
		{
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlBrlyFilList::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacBrlyFilList"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFTos")) {numFTos = me["numFTos"].asUInt(); add(NUMFTOS);};
	};

	return basefound;
};

bool PnlBrlyFilList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyFilList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyFilList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlBrlyFilList::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyFilList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFTos"] = numFTos;
};

void PnlBrlyFilList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyFilList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyFilList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFilList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlBrlyFilList::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFTOS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFilList::ContInf
 ******************************************************************************/

PnlBrlyFilList::ContInf::ContInf(
			const bool ButFilterOn
			, const uint numFCsiQst
		) :
			Block()
		{
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {BUTFILTERON, NUMFCSIQST};
};

void PnlBrlyFilList::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyFilList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButFilterOn"] = ButFilterOn;
	me["numFCsiQst"] = numFCsiQst;
};

void PnlBrlyFilList::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyFilList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyFilList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButFilterOn", ButFilterOn);
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFilList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlBrlyFilList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTFILTERON, NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFilList::StatShr
 ******************************************************************************/

PnlBrlyFilList::StatShr::StatShr(
			const uint ixBrlyVExpstate
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXBRLYVEXPSTATE, BUTDELETEACTIVE};
};

void PnlBrlyFilList::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyFilList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVExpstate"] = VecBrlyVExpstate::getSref(ixBrlyVExpstate);
	me["ButDeleteActive"] = ButDeleteActive;
};

void PnlBrlyFilList::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyFilList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyFilList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFilList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlBrlyFilList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, BUTDELETEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFilList::StgIac
 ******************************************************************************/

PnlBrlyFilList::StgIac::StgIac(
			const uint TcoGrpWidth
			, const uint TcoOwnWidth
			, const uint TcoFnmWidth
			, const uint TcoRetWidth
			, const uint TcoReuWidth
			, const uint TcoCntWidth
			, const uint TcoMimWidth
			, const uint TcoSizWidth
		) :
			Block()
		{
	this->TcoGrpWidth = TcoGrpWidth;
	this->TcoOwnWidth = TcoOwnWidth;
	this->TcoFnmWidth = TcoFnmWidth;
	this->TcoRetWidth = TcoRetWidth;
	this->TcoReuWidth = TcoReuWidth;
	this->TcoCntWidth = TcoCntWidth;
	this->TcoMimWidth = TcoMimWidth;
	this->TcoSizWidth = TcoSizWidth;
	mask = {TCOGRPWIDTH, TCOOWNWIDTH, TCOFNMWIDTH, TCORETWIDTH, TCOREUWIDTH, TCOCNTWIDTH, TCOMIMWIDTH, TCOSIZWIDTH};
};

bool PnlBrlyFilList::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacBrlyFilList"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TcoGrpWidth")) {TcoGrpWidth = me["TcoGrpWidth"].asUInt(); add(TCOGRPWIDTH);};
		if (me.isMember("TcoOwnWidth")) {TcoOwnWidth = me["TcoOwnWidth"].asUInt(); add(TCOOWNWIDTH);};
		if (me.isMember("TcoFnmWidth")) {TcoFnmWidth = me["TcoFnmWidth"].asUInt(); add(TCOFNMWIDTH);};
		if (me.isMember("TcoRetWidth")) {TcoRetWidth = me["TcoRetWidth"].asUInt(); add(TCORETWIDTH);};
		if (me.isMember("TcoReuWidth")) {TcoReuWidth = me["TcoReuWidth"].asUInt(); add(TCOREUWIDTH);};
		if (me.isMember("TcoCntWidth")) {TcoCntWidth = me["TcoCntWidth"].asUInt(); add(TCOCNTWIDTH);};
		if (me.isMember("TcoMimWidth")) {TcoMimWidth = me["TcoMimWidth"].asUInt(); add(TCOMIMWIDTH);};
		if (me.isMember("TcoSizWidth")) {TcoSizWidth = me["TcoSizWidth"].asUInt(); add(TCOSIZWIDTH);};
	};

	return basefound;
};

bool PnlBrlyFilList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacBrlyFilList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacBrlyFilList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoGrpWidth", TcoGrpWidth)) add(TCOGRPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoOwnWidth", TcoOwnWidth)) add(TCOOWNWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFnmWidth", TcoFnmWidth)) add(TCOFNMWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRetWidth", TcoRetWidth)) add(TCORETWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoReuWidth", TcoReuWidth)) add(TCOREUWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCntWidth", TcoCntWidth)) add(TCOCNTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMimWidth", TcoMimWidth)) add(TCOMIMWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSizWidth", TcoSizWidth)) add(TCOSIZWIDTH);
	};

	return basefound;
};

void PnlBrlyFilList::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyFilList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TcoGrpWidth"] = TcoGrpWidth;
	me["TcoOwnWidth"] = TcoOwnWidth;
	me["TcoFnmWidth"] = TcoFnmWidth;
	me["TcoRetWidth"] = TcoRetWidth;
	me["TcoReuWidth"] = TcoReuWidth;
	me["TcoCntWidth"] = TcoCntWidth;
	me["TcoMimWidth"] = TcoMimWidth;
	me["TcoSizWidth"] = TcoSizWidth;
};

void PnlBrlyFilList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacBrlyFilList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacBrlyFilList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoGrpWidth", TcoGrpWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoOwnWidth", TcoOwnWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoFnmWidth", TcoFnmWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoRetWidth", TcoRetWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoReuWidth", TcoReuWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCntWidth", TcoCntWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMimWidth", TcoMimWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSizWidth", TcoSizWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFilList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoGrpWidth == comp->TcoGrpWidth) insert(items, TCOGRPWIDTH);
	if (TcoOwnWidth == comp->TcoOwnWidth) insert(items, TCOOWNWIDTH);
	if (TcoFnmWidth == comp->TcoFnmWidth) insert(items, TCOFNMWIDTH);
	if (TcoRetWidth == comp->TcoRetWidth) insert(items, TCORETWIDTH);
	if (TcoReuWidth == comp->TcoReuWidth) insert(items, TCOREUWIDTH);
	if (TcoCntWidth == comp->TcoCntWidth) insert(items, TCOCNTWIDTH);
	if (TcoMimWidth == comp->TcoMimWidth) insert(items, TCOMIMWIDTH);
	if (TcoSizWidth == comp->TcoSizWidth) insert(items, TCOSIZWIDTH);

	return(items);
};

set<uint> PnlBrlyFilList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOGRPWIDTH, TCOOWNWIDTH, TCOFNMWIDTH, TCORETWIDTH, TCOREUWIDTH, TCOCNTWIDTH, TCOMIMWIDTH, TCOSIZWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFilList::Tag
 ******************************************************************************/

void PnlBrlyFilList::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyFilList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["Cpt"] = "Files";
		me["TcoFnm"] = "File name";
		me["TcoRet"] = "Table of reference";
		me["TcoReu"] = "Reference";
		me["TcoCnt"] = "Content";
		me["TcoMim"] = "MIME type";
		me["TcoSiz"] = "Size [kB]";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["Cpt"] = "Dateien";
		me["TcoFnm"] = "Dateiname";
		me["TcoRet"] = "Referenztabelle";
		me["TcoReu"] = "Referenz";
		me["TcoCnt"] = "Inhalt";
		me["TcoMim"] = "MIME-Typ";
		me["TcoSiz"] = "Gr\\u00f6sse [kB]";
	};
	me["TxtRecord1"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::REC, ixBrlyVLocale));
	me["TxtRecord2"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale));
	me["Trs"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...";
	me["TxtShowing1"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::SHOWLONG, ixBrlyVLocale));
	me["TxtShowing2"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale));
	me["TcoGrp"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GRP, ixBrlyVLocale));
	me["TcoOwn"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::OWN, ixBrlyVLocale));
};

void PnlBrlyFilList::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyFilList";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyFilList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Files");
			writeStringAttr(wr, itemtag, "sref", "TcoFnm", "File name");
			writeStringAttr(wr, itemtag, "sref", "TcoRet", "Table of reference");
			writeStringAttr(wr, itemtag, "sref", "TcoReu", "Reference");
			writeStringAttr(wr, itemtag, "sref", "TcoCnt", "Content");
			writeStringAttr(wr, itemtag, "sref", "TcoMim", "MIME type");
			writeStringAttr(wr, itemtag, "sref", "TcoSiz", "Size [kB]");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Dateien");
			writeStringAttr(wr, itemtag, "sref", "TcoFnm", "Dateiname");
			writeStringAttr(wr, itemtag, "sref", "TcoRet", "Referenztabelle");
			writeStringAttr(wr, itemtag, "sref", "TcoReu", "Referenz");
			writeStringAttr(wr, itemtag, "sref", "TcoCnt", "Inhalt");
			writeStringAttr(wr, itemtag, "sref", "TcoMim", "MIME-Typ");
			writeStringAttr(wr, itemtag, "sref", "TcoSiz", "Gr\\u00f6sse [kB]");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::REC, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GOTO, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::SHOWLONG, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::EMPLONG, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TcoGrp", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::GRP, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TcoOwn", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::OWN, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFilList::DpchAppData
 ******************************************************************************/

PnlBrlyFilList::DpchAppData::DpchAppData() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFILLISTDATA)
		{
};

string PnlBrlyFilList::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFilList::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyFilListData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
		if (stgiac.readJSON(me, true)) add(STGIAC);
		if (stgiacqry.readJSON(me, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryBrlyFilList::StgIac();
	};
};

void PnlBrlyFilList::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyFilListData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryBrlyFilList::StgIac();
	};
};

/******************************************************************************
 class PnlBrlyFilList::DpchAppDo
 ******************************************************************************/

PnlBrlyFilList::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFILLISTDO)
		{
	ixVDo = 0;
};

string PnlBrlyFilList::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFilList::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyFilListDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlBrlyFilList::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyFilListDo");
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
 class PnlBrlyFilList::DpchEngData
 ******************************************************************************/

PnlBrlyFilList::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFCsiQst
			, Feed* feedFTos
			, StatShr* statshr
			, StgIac* stgiac
			, ListBrlyQFilList* rst
			, QryBrlyFilList::StatShr* statshrqry
			, QryBrlyFilList::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYFILLISTDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFCSIQST, FEEDFTOS, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, FEEDFTOS) && feedFTos) this->feedFTos = *feedFTos;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlBrlyFilList::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(FEEDFTOS)) ss.push_back("feedFTos");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFilList::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(FEEDFTOS)) {feedFTos = src->feedFTos; add(FEEDFTOS);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlBrlyFilList::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyFilListData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFCSIQST)) feedFCsiQst.writeJSON(me);
	if (has(FEEDFTOS)) feedFTos.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STGIAC)) stgiac.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
	if (has(RST)) rst.writeJSON(me);
	if (has(STATAPPQRY)) QryBrlyFilList::StatApp::writeJSON(me);
	if (has(STATSHRQRY)) statshrqry.writeJSON(me);
	if (has(STGIACQRY)) stgiacqry.writeJSON(me);
};

void PnlBrlyFilList::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyFilListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(FEEDFTOS)) feedFTos.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryBrlyFilList::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
