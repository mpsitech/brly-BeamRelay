/**
	* \file RootBrly_blks.cpp
	* job handler for job RootBrly (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class RootBrly::DpchAppLogin
 ******************************************************************************/

RootBrly::DpchAppLogin::DpchAppLogin() :
			DpchAppBrly(VecBrlyVDpch::DPCHAPPROOTBRLYLOGIN)
		{
	m2mNotReg = false;
	chksuspsess = false;
};

string RootBrly::DpchAppLogin::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(USERNAME)) ss.push_back("username");
	if (has(PASSWORD)) ss.push_back("password");
	if (has(M2MNOTREG)) ss.push_back("m2mNotReg");
	if (has(CHKSUSPSESS)) ss.push_back("chksuspsess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootBrly::DpchAppLogin::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppRootBrlyLogin");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "username", "", username)) add(USERNAME);
		if (extractStringUclc(docctx, basexpath, "password", "", password)) add(PASSWORD);
		if (extractBoolUclc(docctx, basexpath, "m2mNotReg", "", m2mNotReg)) add(M2MNOTREG);
		if (extractBoolUclc(docctx, basexpath, "chksuspsess", "", chksuspsess)) add(CHKSUSPSESS);
	} else {
	};
};

/******************************************************************************
 class RootBrly::DpchEngData
 ******************************************************************************/

RootBrly::DpchEngData::DpchEngData(
			const ubigint jref
			, Feed* feedFEnsSps
			, const set<uint>& mask
		) :
			DpchEngBrly(VecBrlyVDpch::DPCHENGROOTBRLYDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, FEEDFENSSPS};
	else this->mask = mask;

	if (find(this->mask, FEEDFENSSPS) && feedFEnsSps) this->feedFEnsSps = *feedFEnsSps;
};

string RootBrly::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(FEEDFENSSPS)) ss.push_back("feedFEnsSps");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootBrly::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(FEEDFENSSPS)) {feedFEnsSps = src->feedFEnsSps; add(FEEDFENSSPS);};
};

void RootBrly::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngRootBrlyData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(FEEDFENSSPS)) feedFEnsSps.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
