/**
	* \file CrdBrlyNav_blks.cpp
	* job handler for job CrdBrlyNav (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdBrlyNav::VecVDo
 ******************************************************************************/

uint CrdBrlyNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitsesspsclick") return MITSESSPSCLICK;
	if (s == "mitsestrmclick") return MITSESTRMCLICK;
	if (s == "mitcrdusgclick") return MITCRDUSGCLICK;
	if (s == "mitcrdusrclick") return MITCRDUSRCLICK;
	if (s == "mitcrdprsclick") return MITCRDPRSCLICK;
	if (s == "mitcrdfilclick") return MITCRDFILCLICK;
	if (s == "mitcrdoprclick") return MITCRDOPRCLICK;
	if (s == "mitcrdptyclick") return MITCRDPTYCLICK;
	if (s == "mitcrdregclick") return MITCRDREGCLICK;
	if (s == "mitcrdlocclick") return MITCRDLOCCLICK;
	if (s == "mitcrdlegclick") return MITCRDLEGCLICK;
	if (s == "mitcrdttbclick") return MITCRDTTBCLICK;
	if (s == "mitcrdfltclick") return MITCRDFLTCLICK;
	if (s == "mitcrdsegclick") return MITCRDSEGCLICK;
	if (s == "mitcrdconclick") return MITCRDCONCLICK;
	if (s == "mitcrdrlyclick") return MITCRDRLYCLICK;
	if (s == "mitapploiclick") return MITAPPLOICLICK;

	return(0);
};

string CrdBrlyNav::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITSESSPSCLICK) return("MitSesSpsClick");
	if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
	if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
	if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
	if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
	if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
	if (ix == MITCRDOPRCLICK) return("MitCrdOprClick");
	if (ix == MITCRDPTYCLICK) return("MitCrdPtyClick");
	if (ix == MITCRDREGCLICK) return("MitCrdRegClick");
	if (ix == MITCRDLOCCLICK) return("MitCrdLocClick");
	if (ix == MITCRDLEGCLICK) return("MitCrdLegClick");
	if (ix == MITCRDTTBCLICK) return("MitCrdTtbClick");
	if (ix == MITCRDFLTCLICK) return("MitCrdFltClick");
	if (ix == MITCRDSEGCLICK) return("MitCrdSegClick");
	if (ix == MITCRDCONCLICK) return("MitCrdConClick");
	if (ix == MITCRDRLYCLICK) return("MitCrdRlyClick");
	if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

	return("");
};

/******************************************************************************
 class CrdBrlyNav::VecVSge
 ******************************************************************************/

uint CrdBrlyNav::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrbrlyabt") return ALRBRLYABT;
	if (s == "alrbrlytrm") return ALRBRLYTRM;

	return(0);
};

string CrdBrlyNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRBRLYABT) return("alrbrlyabt");
	if (ix == ALRBRLYTRM) return("alrbrlytrm");

	return("");
};

void CrdBrlyNav::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdBrlyNav::ContInf
 ******************************************************************************/

CrdBrlyNav::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxSesSes1
			, const string& MtxSesSes2
			, const string& MtxSesSes3
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxSesSes1 = MtxSesSes1;
	this->MtxSesSes2 = MtxSesSes2;
	this->MtxSesSes3 = MtxSesSes3;

	mask = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
};

void CrdBrlyNav::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
	me["MtxSesSes1"] = MtxSesSes1;
	me["MtxSesSes2"] = MtxSesSes2;
	me["MtxSesSes3"] = MtxSesSes3;
};

void CrdBrlyNav::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyNav";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes1", MtxSesSes1);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes2", MtxSesSes2);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes3", MtxSesSes3);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdBrlyNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxSesSes1 == comp->MtxSesSes1) insert(items, MTXSESSES1);
	if (MtxSesSes2 == comp->MtxSesSes2) insert(items, MTXSESSES2);
	if (MtxSesSes3 == comp->MtxSesSes3) insert(items, MTXSESSES3);

	return(items);
};

set<uint> CrdBrlyNav::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyNav::StatApp
 ******************************************************************************/

void CrdBrlyNav::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixBrlyVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneAdmin
			, const bool initdoneBase
			, const bool initdoneConnect
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxBrlyVReqitmode"] = VecBrlyVReqitmode::getSref(ixBrlyVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdoneAdmin"] = initdoneAdmin;
	me["initdoneBase"] = initdoneBase;
	me["initdoneConnect"] = initdoneConnect;
};

void CrdBrlyNav::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneAdmin
			, const bool initdoneBase
			, const bool initdoneConnect
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVReqitmode", VecBrlyVReqitmode::getSref(ixBrlyVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAdmin", initdoneAdmin);
		writeBoolAttr(wr, itemtag, "sref", "initdoneBase", initdoneBase);
		writeBoolAttr(wr, itemtag, "sref", "initdoneConnect", initdoneConnect);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdBrlyNav::StatShr
 ******************************************************************************/

CrdBrlyNav::StatShr::StatShr(
			const ubigint jrefDlgloaini
			, const ubigint jrefHeadbar
			, const ubigint jrefAdmin
			, const bool pnladminAvail
			, const ubigint jrefBase
			, const bool pnlbaseAvail
			, const ubigint jrefConnect
			, const bool pnlconnectAvail
			, const bool MitSesSpsAvail
			, const bool MspCrd1Avail
			, const bool MitCrdUsgAvail
			, const bool MitCrdUsrAvail
			, const bool MitCrdPrsAvail
			, const bool MitCrdFilAvail
			, const bool MitCrdOprAvail
			, const bool MitCrdPtyAvail
			, const bool MspCrd2Avail
			, const bool MitCrdRegAvail
			, const bool MitCrdLocAvail
			, const bool MitCrdLegAvail
			, const bool MitCrdTtbAvail
			, const bool MitCrdFltAvail
			, const bool MitCrdSegAvail
			, const bool MspCrd3Avail
			, const bool MitCrdConAvail
			, const bool MitCrdRlyAvail
			, const bool MspApp2Avail
			, const bool MitAppLoiAvail
		) :
			Block()
		{
	this->jrefDlgloaini = jrefDlgloaini;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefAdmin = jrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->jrefBase = jrefBase;
	this->pnlbaseAvail = pnlbaseAvail;
	this->jrefConnect = jrefConnect;
	this->pnlconnectAvail = pnlconnectAvail;
	this->MitSesSpsAvail = MitSesSpsAvail;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdUsgAvail = MitCrdUsgAvail;
	this->MitCrdUsrAvail = MitCrdUsrAvail;
	this->MitCrdPrsAvail = MitCrdPrsAvail;
	this->MitCrdFilAvail = MitCrdFilAvail;
	this->MitCrdOprAvail = MitCrdOprAvail;
	this->MitCrdPtyAvail = MitCrdPtyAvail;
	this->MspCrd2Avail = MspCrd2Avail;
	this->MitCrdRegAvail = MitCrdRegAvail;
	this->MitCrdLocAvail = MitCrdLocAvail;
	this->MitCrdLegAvail = MitCrdLegAvail;
	this->MitCrdTtbAvail = MitCrdTtbAvail;
	this->MitCrdFltAvail = MitCrdFltAvail;
	this->MitCrdSegAvail = MitCrdSegAvail;
	this->MspCrd3Avail = MspCrd3Avail;
	this->MitCrdConAvail = MitCrdConAvail;
	this->MitCrdRlyAvail = MitCrdRlyAvail;
	this->MspApp2Avail = MspApp2Avail;
	this->MitAppLoiAvail = MitAppLoiAvail;

	mask = {JREFDLGLOAINI, JREFHEADBAR, JREFADMIN, PNLADMINAVAIL, JREFBASE, PNLBASEAVAIL, JREFCONNECT, PNLCONNECTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MITCRDOPRAVAIL, MITCRDPTYAVAIL, MSPCRD2AVAIL, MITCRDREGAVAIL, MITCRDLOCAVAIL, MITCRDLEGAVAIL, MITCRDTTBAVAIL, MITCRDFLTAVAIL, MITCRDSEGAVAIL, MSPCRD3AVAIL, MITCRDCONAVAIL, MITCRDRLYAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

void CrdBrlyNav::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefDlgloaini"] = Scr::scramble(jrefDlgloaini);
	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefAdmin"] = Scr::scramble(jrefAdmin);
	me["pnladminAvail"] = pnladminAvail;
	me["scrJrefBase"] = Scr::scramble(jrefBase);
	me["pnlbaseAvail"] = pnlbaseAvail;
	me["scrJrefConnect"] = Scr::scramble(jrefConnect);
	me["pnlconnectAvail"] = pnlconnectAvail;
	me["MitSesSpsAvail"] = MitSesSpsAvail;
	me["MspCrd1Avail"] = MspCrd1Avail;
	me["MitCrdUsgAvail"] = MitCrdUsgAvail;
	me["MitCrdUsrAvail"] = MitCrdUsrAvail;
	me["MitCrdPrsAvail"] = MitCrdPrsAvail;
	me["MitCrdFilAvail"] = MitCrdFilAvail;
	me["MitCrdOprAvail"] = MitCrdOprAvail;
	me["MitCrdPtyAvail"] = MitCrdPtyAvail;
	me["MspCrd2Avail"] = MspCrd2Avail;
	me["MitCrdRegAvail"] = MitCrdRegAvail;
	me["MitCrdLocAvail"] = MitCrdLocAvail;
	me["MitCrdLegAvail"] = MitCrdLegAvail;
	me["MitCrdTtbAvail"] = MitCrdTtbAvail;
	me["MitCrdFltAvail"] = MitCrdFltAvail;
	me["MitCrdSegAvail"] = MitCrdSegAvail;
	me["MspCrd3Avail"] = MspCrd3Avail;
	me["MitCrdConAvail"] = MitCrdConAvail;
	me["MitCrdRlyAvail"] = MitCrdRlyAvail;
	me["MspApp2Avail"] = MspApp2Avail;
	me["MitAppLoiAvail"] = MitAppLoiAvail;
};

void CrdBrlyNav::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgloaini", Scr::scramble(jrefDlgloaini));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAdmin", Scr::scramble(jrefAdmin));
		writeBoolAttr(wr, itemtag, "sref", "pnladminAvail", pnladminAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefBase", Scr::scramble(jrefBase));
		writeBoolAttr(wr, itemtag, "sref", "pnlbaseAvail", pnlbaseAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefConnect", Scr::scramble(jrefConnect));
		writeBoolAttr(wr, itemtag, "sref", "pnlconnectAvail", pnlconnectAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitSesSpsAvail", MitSesSpsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsgAvail", MitCrdUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsrAvail", MitCrdUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrsAvail", MitCrdPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFilAvail", MitCrdFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdOprAvail", MitCrdOprAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPtyAvail", MitCrdPtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd2Avail", MspCrd2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRegAvail", MitCrdRegAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdLocAvail", MitCrdLocAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdLegAvail", MitCrdLegAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTtbAvail", MitCrdTtbAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFltAvail", MitCrdFltAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSegAvail", MitCrdSegAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd3Avail", MspCrd3Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdConAvail", MitCrdConAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRlyAvail", MitCrdRlyAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspApp2Avail", MspApp2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitAppLoiAvail", MitAppLoiAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdBrlyNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgloaini == comp->jrefDlgloaini) insert(items, JREFDLGLOAINI);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefAdmin == comp->jrefAdmin) insert(items, JREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (jrefBase == comp->jrefBase) insert(items, JREFBASE);
	if (pnlbaseAvail == comp->pnlbaseAvail) insert(items, PNLBASEAVAIL);
	if (jrefConnect == comp->jrefConnect) insert(items, JREFCONNECT);
	if (pnlconnectAvail == comp->pnlconnectAvail) insert(items, PNLCONNECTAVAIL);
	if (MitSesSpsAvail == comp->MitSesSpsAvail) insert(items, MITSESSPSAVAIL);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUsgAvail == comp->MitCrdUsgAvail) insert(items, MITCRDUSGAVAIL);
	if (MitCrdUsrAvail == comp->MitCrdUsrAvail) insert(items, MITCRDUSRAVAIL);
	if (MitCrdPrsAvail == comp->MitCrdPrsAvail) insert(items, MITCRDPRSAVAIL);
	if (MitCrdFilAvail == comp->MitCrdFilAvail) insert(items, MITCRDFILAVAIL);
	if (MitCrdOprAvail == comp->MitCrdOprAvail) insert(items, MITCRDOPRAVAIL);
	if (MitCrdPtyAvail == comp->MitCrdPtyAvail) insert(items, MITCRDPTYAVAIL);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdRegAvail == comp->MitCrdRegAvail) insert(items, MITCRDREGAVAIL);
	if (MitCrdLocAvail == comp->MitCrdLocAvail) insert(items, MITCRDLOCAVAIL);
	if (MitCrdLegAvail == comp->MitCrdLegAvail) insert(items, MITCRDLEGAVAIL);
	if (MitCrdTtbAvail == comp->MitCrdTtbAvail) insert(items, MITCRDTTBAVAIL);
	if (MitCrdFltAvail == comp->MitCrdFltAvail) insert(items, MITCRDFLTAVAIL);
	if (MitCrdSegAvail == comp->MitCrdSegAvail) insert(items, MITCRDSEGAVAIL);
	if (MspCrd3Avail == comp->MspCrd3Avail) insert(items, MSPCRD3AVAIL);
	if (MitCrdConAvail == comp->MitCrdConAvail) insert(items, MITCRDCONAVAIL);
	if (MitCrdRlyAvail == comp->MitCrdRlyAvail) insert(items, MITCRDRLYAVAIL);
	if (MspApp2Avail == comp->MspApp2Avail) insert(items, MSPAPP2AVAIL);
	if (MitAppLoiAvail == comp->MitAppLoiAvail) insert(items, MITAPPLOIAVAIL);

	return(items);
};

set<uint> CrdBrlyNav::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGLOAINI, JREFHEADBAR, JREFADMIN, PNLADMINAVAIL, JREFBASE, PNLBASEAVAIL, JREFCONNECT, PNLCONNECTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MITCRDOPRAVAIL, MITCRDPTYAVAIL, MSPCRD2AVAIL, MITCRDREGAVAIL, MITCRDLOCAVAIL, MITCRDLEGAVAIL, MITCRDTTBAVAIL, MITCRDFLTAVAIL, MITCRDSEGAVAIL, MSPCRD3AVAIL, MITCRDCONAVAIL, MITCRDRLYAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyNav::Tag
 ******************************************************************************/

void CrdBrlyNav::Tag::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagBrlyNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
		me["MitCrdUsg"] = "User groups ...";
		me["MitCrdUsr"] = "Users ...";
		me["MitCrdPrs"] = "Persons ...";
		me["MitCrdFil"] = "Files ...";
		me["MitCrdOpr"] = "Operators ...";
		me["MitCrdPty"] = "Plane types ...";
		me["MitCrdReg"] = "Regions ...";
		me["MitCrdLoc"] = "Locations ...";
		me["MitCrdLeg"] = "Legs ...";
		me["MitCrdTtb"] = "Timetables ...";
		me["MitCrdFlt"] = "Flights ...";
		me["MitCrdSeg"] = "Segments ...";
		me["MitCrdCon"] = "Connections ...";
		me["MitCrdRly"] = "Relays ...";
	} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
		me["MitCrdUsg"] = "Benutzergruppen ...";
		me["MitCrdUsr"] = "Benutzer ...";
		me["MitCrdPrs"] = "Personen ...";
		me["MitCrdFil"] = "Dateien ...";
		me["MitCrdOpr"] = "Betreiber ...";
		me["MitCrdPty"] = "Flugzeugtypen ...";
		me["MitCrdReg"] = "Regionen ...";
		me["MitCrdLoc"] = "Orte ...";
		me["MitCrdLeg"] = "Strecken ...";
		me["MitCrdTtb"] = "Flugpl\\u00e4ne ...";
		me["MitCrdFlt"] = "Fl\\u00fcge ...";
		me["MitCrdSeg"] = "Segmente ...";
		me["MitCrdCon"] = "Verbindungen ...";
		me["MitCrdRly"] = "Verbindungsketten ...";
	};
	me["MitAppAbt"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::ABOUT, ixBrlyVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::HELP, ixBrlyVLocale)) + " ...";
	me["MitSesSps"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::SUSPSESS, ixBrlyVLocale));
	me["MitSesTrm"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CLSESS, ixBrlyVLocale));
	me["MitAppLoi"] = StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::LOAINI, ixBrlyVLocale)) + " ...";
};

void CrdBrlyNav::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyNav";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "User groups ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Users ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Persons ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Files ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdOpr", "Operators ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPty", "Plane types ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdReg", "Regions ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLoc", "Locations ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLeg", "Legs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTtb", "Timetables ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFlt", "Flights ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSeg", "Segments ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCon", "Connections ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdRly", "Relays ...");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "Benutzergruppen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Benutzer ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Personen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Dateien ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdOpr", "Betreiber ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPty", "Flugzeugtypen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdReg", "Regionen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLoc", "Orte ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLeg", "Strecken ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTtb", "Flugpl\\u00e4ne ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFlt", "Fl\\u00fcge ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSeg", "Segmente ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCon", "Verbindungen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdRly", "Verbindungsketten ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::ABOUT, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::HELP, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitSesSps", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::SUSPSESS, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitSesTrm", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CLSESS, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitAppLoi", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::LOAINI, ixBrlyVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdBrlyNav::DpchAppDo
 ******************************************************************************/

CrdBrlyNav::DpchAppDo::DpchAppDo() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVDO)
		{
	ixVDo = 0;
};

string CrdBrlyNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdBrlyNav::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppBrlyNavDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdBrlyNav::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyNavDo");
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
 class CrdBrlyNav::DpchEngData
 ******************************************************************************/

CrdBrlyNav::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYNAVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdBrlyNav::DpchEngData::getSrefsMask() {
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

void CrdBrlyNav::DpchEngData::merge(
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

void CrdBrlyNav::DpchEngData::writeJSON(
			const uint ixBrlyVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngBrlyNavData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixBrlyVLocale, me);
};

void CrdBrlyNav::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyNavData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};
