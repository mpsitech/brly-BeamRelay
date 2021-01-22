/**
	* \file IexBrlyIni.cpp
	* data blocks and readers/writers for import/export complex IexBrlyIni (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#include "IexBrlyIni.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexBrlyIni::VecVIme
 ******************************************************************************/

uint IexBrlyIni::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamregiondstswitch") return IMEIAMREGIONDSTSWITCH;
	if (s == "imeiamuseraccess") return IMEIAMUSERACCESS;
	if (s == "imeiamusergroupaccess") return IMEIAMUSERGROUPACCESS;
	if (s == "imeiavcontrolpar") return IMEIAVCONTROLPAR;
	if (s == "imeiavkeylistkey") return IMEIAVKEYLISTKEY;
	if (s == "imeiavvaluelistval") return IMEIAVVALUELISTVAL;
	if (s == "imeijavkeylistkey") return IMEIJAVKEYLISTKEY;
	if (s == "imeijmpersonlastname") return IMEIJMPERSONLASTNAME;
	if (s == "imeijmregion") return IMEIJMREGION;
	if (s == "imeijmregiontitle") return IMEIJMREGIONTITLE;
	if (s == "imeijmuserstate") return IMEIJMUSERSTATE;
	if (s == "imeimfile") return IMEIMFILE;
	if (s == "imeimlocation") return IMEIMLOCATION;
	if (s == "imeimoperator") return IMEIMOPERATOR;
	if (s == "imeimperson") return IMEIMPERSON;
	if (s == "imeimplntype") return IMEIMPLNTYPE;
	if (s == "imeimregion") return IMEIMREGION;
	if (s == "imeimuser") return IMEIMUSER;
	if (s == "imeimusergroup") return IMEIMUSERGROUP;

	return(0);
};

string IexBrlyIni::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMREGIONDSTSWITCH) return("ImeIAMRegionDstswitch");
	if (ix == IMEIAMUSERACCESS) return("ImeIAMUserAccess");
	if (ix == IMEIAMUSERGROUPACCESS) return("ImeIAMUsergroupAccess");
	if (ix == IMEIAVCONTROLPAR) return("ImeIAVControlPar");
	if (ix == IMEIAVKEYLISTKEY) return("ImeIAVKeylistKey");
	if (ix == IMEIAVVALUELISTVAL) return("ImeIAVValuelistVal");
	if (ix == IMEIJAVKEYLISTKEY) return("ImeIJAVKeylistKey");
	if (ix == IMEIJMPERSONLASTNAME) return("ImeIJMPersonLastname");
	if (ix == IMEIJMREGION) return("ImeIJMRegion");
	if (ix == IMEIJMREGIONTITLE) return("ImeIJMRegionTitle");
	if (ix == IMEIJMUSERSTATE) return("ImeIJMUserState");
	if (ix == IMEIMFILE) return("ImeIMFile");
	if (ix == IMEIMLOCATION) return("ImeIMLocation");
	if (ix == IMEIMOPERATOR) return("ImeIMOperator");
	if (ix == IMEIMPERSON) return("ImeIMPerson");
	if (ix == IMEIMPLNTYPE) return("ImeIMPlntype");
	if (ix == IMEIMREGION) return("ImeIMRegion");
	if (ix == IMEIMUSER) return("ImeIMUser");
	if (ix == IMEIMUSERGROUP) return("ImeIMUsergroup");

	return("");
};

/******************************************************************************
 class IexBrlyIni::ImeitemIAVControlPar
 ******************************************************************************/

IexBrlyIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			const uint ixBrlyVControl
			, const string& Par
			, const string& Val
		) : BrlyAVControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixBrlyVControl = ixBrlyVControl;
	this->Par = Par;
	this->Val = Val;
};

IexBrlyIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIAVControlPar()
		{
	BrlyAVControlPar* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyavcontrolpar->loadRecByRef(ref, &rec)) {
		ixBrlyVControl = rec->ixBrlyVControl;
		Par = rec->Par;
		Val = rec->Val;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxBrlyVControl = txtrd.fields[0]; ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXBRLYVCONTROL;};
	if (txtrd.fields.size() > 1) {Par = txtrd.fields[1]; ixWIelValid += ImeIAVControlPar::VecWIel::PAR;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAVControlPar::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIAVControlPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxBrlyVControl", "ctl", srefIxBrlyVControl)) ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXBRLYVCONTROL;
		if (extractStringUclc(docctx, basexpath, "Par", "par", Par)) ixWIelValid += ImeIAVControlPar::VecWIel::PAR;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVControlPar::VecWIel::VAL;
	};
};

void IexBrlyIni::ImeitemIAVControlPar::writeTxt(
			fstream& outfile
		) {
	outfile << VecBrlyVControl::getSref(ixBrlyVControl) << "\t" << Par << "\t" << Val << endl;
};

void IexBrlyIni::ImeitemIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ctl","par","val"};
	else tags = {"ImeitemIAVControlPar","srefIxBrlyVControl","Par","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVControl::getSref(ixBrlyVControl));
		writeString(wr, tags[2], Par);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIAVControlPar::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIAVControlPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixbrlyvcontrol") ix |= SREFIXBRLYVCONTROL;
		else if (ss[i] == "par") ix |= PAR;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexBrlyIni::ImeIAVControlPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIAVControlPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXBRLYVCONTROL) ss.push_back("srefIxBrlyVControl");
	if (ix & PAR) ss.push_back("Par");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIAVControlPar
 ******************************************************************************/

IexBrlyIni::ImeIAVControlPar::ImeIAVControlPar() {
};

IexBrlyIni::ImeIAVControlPar::~ImeIAVControlPar() {
	clear();
};

void IexBrlyIni::ImeIAVControlPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIAVControlPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyIni::ImeitemIAVControlPar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIAVControlPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIAVControlPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVControlPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVControlPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVControlPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIAVControlPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIAVControlPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVControlPar." << StrMod::replaceChar(ImeIAVControlPar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVControlPar.end" << endl;
	};
};

void IexBrlyIni::ImeIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVControlPar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIJAVKeylistKey
 ******************************************************************************/

IexBrlyIni::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			const uint x1IxBrlyVLocale
			, const string& Title
			, const string& Comment
		) : BrlyJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxBrlyVLocale = x1IxBrlyVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexBrlyIni::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIJAVKeylistKey()
		{
	BrlyJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyjavkeylistkey->loadRecByRef(ref, &rec)) {
		refBrlyAVKeylistKey = rec->refBrlyAVKeylistKey;
		x1IxBrlyVLocale = rec->x1IxBrlyVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxBrlyVLocale = txtrd.fields[0]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::SREFX1IXBRLYVLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxBrlyVLocale", "lcl", srefX1IxBrlyVLocale)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::SREFX1IXBRLYVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;
	};
};

void IexBrlyIni::ImeitemIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecBrlyVLocale::getSref(x1IxBrlyVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexBrlyIni::ImeitemIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey","srefX1IxBrlyVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVLocale::getSref(x1IxBrlyVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIJAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIJAVKeylistKey::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixbrlyvlocale") ix |= SREFX1IXBRLYVLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexBrlyIni::ImeIJAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIJAVKeylistKey::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXBRLYVLOCALE) ss.push_back("srefX1IxBrlyVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIJAVKeylistKey
 ******************************************************************************/

IexBrlyIni::ImeIJAVKeylistKey::ImeIJAVKeylistKey() {
};

IexBrlyIni::ImeIJAVKeylistKey::~ImeIJAVKeylistKey() {
	clear();
};

void IexBrlyIni::ImeIJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIJAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexBrlyIni::ImeitemIJAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIJAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIJAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJAVKeylistKey." << StrMod::replaceChar(ImeIJAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJAVKeylistKey.end" << endl;
	};
};

void IexBrlyIni::ImeIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIAVKeylistKey
 ******************************************************************************/

IexBrlyIni::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
			const uint klsIxBrlyVKeylist
			, const string& sref
			, const string& Avail
			, const string& Implied
			, const string& Title
			, const string& Comment
		) : BrlyAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxBrlyVKeylist = klsIxBrlyVKeylist;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->Title = Title;
	this->Comment = Comment;
};

IexBrlyIni::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIAVKeylistKey()
		{
	BrlyAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxBrlyVKeylist = rec->klsIxBrlyVKeylist;
		klsNum = rec->klsNum;
		x1IxBrlyVMaintable = rec->x1IxBrlyVMaintable;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefKlsIxBrlyVKeylist = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey::VecWIel::SREFKLSIXBRLYVKEYLIST;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Avail = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 3) {Implied = txtrd.fields[3]; ixWIelValid += ImeIAVKeylistKey::VecWIel::IMPLIED;};
	if (txtrd.fields.size() > 4) {Title = txtrd.fields[4]; ixWIelValid += ImeIAVKeylistKey::VecWIel::TITLE;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIAVKeylistKey::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY)) {
					imeijavkeylistkey.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxBrlyVKeylist", "kls", srefKlsIxBrlyVKeylist)) ixWIelValid += ImeIAVKeylistKey::VecWIel::SREFKLSIXBRLYVKEYLIST;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey::VecWIel::IMPLIED;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAVKeylistKey::VecWIel::COMMENT;
		imeijavkeylistkey.readXML(docctx, basexpath);
	};
};

void IexBrlyIni::ImeitemIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << VecBrlyVKeylist::getSref(klsIxBrlyVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey.writeTxt(outfile);
};

void IexBrlyIni::ImeitemIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp","tit","cmt"};
	else tags = {"ImeitemIAVKeylistKey","srefKlsIxBrlyVKeylist","sref","Avail","Implied","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVKeylist::getSref(klsIxBrlyVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		writeString(wr, tags[5], Title);
		writeString(wr, tags[6], Comment);
		imeijavkeylistkey.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIAVKeylistKey::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefklsixbrlyvkeylist") ix |= SREFKLSIXBRLYVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "implied") ix |= IMPLIED;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexBrlyIni::ImeIAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIAVKeylistKey::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXBRLYVKEYLIST) ss.push_back("srefKlsIxBrlyVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIAVKeylistKey
 ******************************************************************************/

IexBrlyIni::ImeIAVKeylistKey::ImeIAVKeylistKey() {
};

IexBrlyIni::ImeIAVKeylistKey::~ImeIAVKeylistKey() {
	clear();
};

void IexBrlyIni::ImeIAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyIni::ImeitemIAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVKeylistKey." << StrMod::replaceChar(ImeIAVKeylistKey::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVKeylistKey.end" << endl;
	};
};

void IexBrlyIni::ImeIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIAVValuelistVal
 ******************************************************************************/

IexBrlyIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			const uint vlsIxBrlyVValuelist
			, const uint x1IxBrlyVLocale
			, const string& Val
		) : BrlyAVValuelistVal() {
	lineno = 0;
	ixWIelValid = 0;

	this->vlsIxBrlyVValuelist = vlsIxBrlyVValuelist;
	this->x1IxBrlyVLocale = x1IxBrlyVLocale;
	this->Val = Val;
};

IexBrlyIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIAVValuelistVal()
		{
	BrlyAVValuelistVal* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyavvaluelistval->loadRecByRef(ref, &rec)) {
		vlsIxBrlyVValuelist = rec->vlsIxBrlyVValuelist;
		vlsNum = rec->vlsNum;
		x1IxBrlyVLocale = rec->x1IxBrlyVLocale;
		Val = rec->Val;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefVlsIxBrlyVValuelist = txtrd.fields[0]; ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXBRLYVVALUELIST;};
	if (txtrd.fields.size() > 1) {srefX1IxBrlyVLocale = txtrd.fields[1]; ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXBRLYVLOCALE;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefVlsIxBrlyVValuelist", "vls", srefVlsIxBrlyVValuelist)) ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXBRLYVVALUELIST;
		if (extractStringUclc(docctx, basexpath, "srefX1IxBrlyVLocale", "lcl", srefX1IxBrlyVLocale)) ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXBRLYVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;
	};
};

void IexBrlyIni::ImeitemIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	outfile << VecBrlyVValuelist::getSref(vlsIxBrlyVValuelist) << "\t" << VecBrlyVLocale::getSref(x1IxBrlyVLocale) << "\t" << Val << endl;
};

void IexBrlyIni::ImeitemIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","vls","lcl","val"};
	else tags = {"ImeitemIAVValuelistVal","srefVlsIxBrlyVValuelist","srefX1IxBrlyVLocale","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVValuelist::getSref(vlsIxBrlyVValuelist));
		writeString(wr, tags[2], VecBrlyVLocale::getSref(x1IxBrlyVLocale));
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIAVValuelistVal::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIAVValuelistVal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefvlsixbrlyvvaluelist") ix |= SREFVLSIXBRLYVVALUELIST;
		else if (ss[i] == "srefx1ixbrlyvlocale") ix |= SREFX1IXBRLYVLOCALE;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexBrlyIni::ImeIAVValuelistVal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIAVValuelistVal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFVLSIXBRLYVVALUELIST) ss.push_back("srefVlsIxBrlyVValuelist");
	if (ix & SREFX1IXBRLYVLOCALE) ss.push_back("srefX1IxBrlyVLocale");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIAVValuelistVal
 ******************************************************************************/

IexBrlyIni::ImeIAVValuelistVal::ImeIAVValuelistVal() {
};

IexBrlyIni::ImeIAVValuelistVal::~ImeIAVValuelistVal() {
	clear();
};

void IexBrlyIni::ImeIAVValuelistVal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIAVValuelistVal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyIni::ImeitemIAVValuelistVal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIAVValuelistVal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVValuelistVal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVValuelistVal", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVValuelistVal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIAVValuelistVal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVValuelistVal." << StrMod::replaceChar(ImeIAVValuelistVal::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVValuelistVal.end" << endl;
	};
};

void IexBrlyIni::ImeIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVValuelistVal");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIMFile
 ******************************************************************************/

IexBrlyIni::ImeitemIMFile::ImeitemIMFile(
			const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : BrlyMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexBrlyIni::ImeitemIMFile::ImeitemIMFile(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIMFile()
		{
	BrlyMFile* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymfile->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		osrefKContent = rec->osrefKContent;
		Filename = rec->Filename;
		srefKMimetype = rec->srefKMimetype;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIMFile::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {osrefKContent = txtrd.fields[0]; ixWIelValid += ImeIMFile::VecWIel::OSREFKCONTENT;};
	if (txtrd.fields.size() > 1) {Filename = txtrd.fields[1]; ixWIelValid += ImeIMFile::VecWIel::FILENAME;};
	if (txtrd.fields.size() > 2) {srefKMimetype = txtrd.fields[2]; ixWIelValid += ImeIMFile::VecWIel::SREFKMIMETYPE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMFile::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFile"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIMFile::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile::VecWIel::COMMENT;
	};
};

void IexBrlyIni::ImeitemIMFile::writeTxt(
			fstream& outfile
		) {
	outfile << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexBrlyIni::ImeitemIMFile::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], osrefKContent);
		writeString(wr, tags[2], Filename);
		writeString(wr, tags[3], srefKMimetype);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIMFile::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIMFile::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "osrefkcontent") ix |= OSREFKCONTENT;
		else if (ss[i] == "filename") ix |= FILENAME;
		else if (ss[i] == "srefkmimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexBrlyIni::ImeIMFile::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIMFile::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIMFile
 ******************************************************************************/

IexBrlyIni::ImeIMFile::ImeIMFile() {
};

IexBrlyIni::ImeIMFile::~ImeIMFile() {
	clear();
};

void IexBrlyIni::ImeIMFile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIMFile::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIMFile* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyIni::ImeitemIMFile();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFile"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFILE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIMFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIMFile* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIMFile();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIMFile::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFile." << StrMod::replaceChar(ImeIMFile::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMFile.end" << endl;
	};
};

void IexBrlyIni::ImeIMFile::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIMLocation
 ******************************************************************************/

IexBrlyIni::ImeitemIMLocation::ImeitemIMLocation(
			const uint ixVBasetype
			, const string& hsrefRefBrlyMRegion
			, const string& sref
			, const string& srefICAO
			, const string& Title
			, const double alt
			, const double theta
			, const double phi
			, const string& tz
		) : BrlyMLocation() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->hsrefRefBrlyMRegion = hsrefRefBrlyMRegion;
	this->sref = sref;
	this->srefICAO = srefICAO;
	this->Title = Title;
	this->alt = alt;
	this->theta = theta;
	this->phi = phi;
	this->tz = tz;
};

IexBrlyIni::ImeitemIMLocation::ImeitemIMLocation(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIMLocation()
		{
	BrlyMLocation* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymlocation->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refBrlyMRegion = rec->refBrlyMRegion;
		refBrlyMEquipment = rec->refBrlyMEquipment;
		sref = rec->sref;
		srefICAO = rec->srefICAO;
		Title = rec->Title;
		alt = rec->alt;
		theta = rec->theta;
		phi = rec->phi;
		tz = rec->tz;
		alpha = rec->alpha;
		Calcdone = rec->Calcdone;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIMLocation::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMLocation::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {hsrefRefBrlyMRegion = txtrd.fields[1]; ixWIelValid += ImeIMLocation::VecWIel::HSREFREFBRLYMREGION;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMLocation::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {srefICAO = txtrd.fields[3]; ixWIelValid += ImeIMLocation::VecWIel::SREFICAO;};
	if (txtrd.fields.size() > 4) {Title = txtrd.fields[4]; ixWIelValid += ImeIMLocation::VecWIel::TITLE;};
	if (txtrd.fields.size() > 5) {alt = atof(txtrd.fields[5].c_str()); ixWIelValid += ImeIMLocation::VecWIel::ALT;};
	if (txtrd.fields.size() > 6) {theta = atof(txtrd.fields[6].c_str()); ixWIelValid += ImeIMLocation::VecWIel::THETA;};
	if (txtrd.fields.size() > 7) {phi = atof(txtrd.fields[7].c_str()); ixWIelValid += ImeIMLocation::VecWIel::PHI;};
	if (txtrd.fields.size() > 8) {tz = txtrd.fields[8]; ixWIelValid += ImeIMLocation::VecWIel::TZ;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMLocation"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIMLocation::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMLocation::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "hsrefRefBrlyMRegion", "reg", hsrefRefBrlyMRegion)) ixWIelValid += ImeIMLocation::VecWIel::HSREFREFBRLYMREGION;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMLocation::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefICAO", "ica", srefICAO)) ixWIelValid += ImeIMLocation::VecWIel::SREFICAO;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMLocation::VecWIel::TITLE;
		if (extractDoubleUclc(docctx, basexpath, "alt", "alt", alt)) ixWIelValid += ImeIMLocation::VecWIel::ALT;
		if (extractDoubleUclc(docctx, basexpath, "theta", "the", theta)) ixWIelValid += ImeIMLocation::VecWIel::THETA;
		if (extractDoubleUclc(docctx, basexpath, "phi", "phi", phi)) ixWIelValid += ImeIMLocation::VecWIel::PHI;
		if (extractStringUclc(docctx, basexpath, "tz", "tz", tz)) ixWIelValid += ImeIMLocation::VecWIel::TZ;
	};
};

void IexBrlyIni::ImeitemIMLocation::writeTxt(
			fstream& outfile
		) {
	outfile << VecBrlyVMLocationBasetype::getSref(ixVBasetype) << "\t" << hsrefRefBrlyMRegion << "\t" << sref << "\t" << srefICAO << "\t" << Title << "\t" << alt << "\t" << theta << "\t" << phi << "\t" << tz << endl;
};

void IexBrlyIni::ImeitemIMLocation::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","reg","srf","ica","tit","alt","the","phi","tz"};
	else tags = {"ImeitemIMLocation","srefIxVBasetype","hsrefRefBrlyMRegion","sref","srefICAO","Title","alt","theta","phi","tz"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVMLocationBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], hsrefRefBrlyMRegion);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], srefICAO);
		writeString(wr, tags[5], Title);
		writeDouble(wr, tags[6], alt);
		writeDouble(wr, tags[7], theta);
		writeDouble(wr, tags[8], phi);
		writeString(wr, tags[9], tz);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIMLocation::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIMLocation::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "hsrefrefbrlymregion") ix |= HSREFREFBRLYMREGION;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "sreficao") ix |= SREFICAO;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "alt") ix |= ALT;
		else if (ss[i] == "theta") ix |= THETA;
		else if (ss[i] == "phi") ix |= PHI;
		else if (ss[i] == "tz") ix |= TZ;
	};

	return(ix);
};

void IexBrlyIni::ImeIMLocation::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TZ); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIMLocation::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & HSREFREFBRLYMREGION) ss.push_back("hsrefRefBrlyMRegion");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFICAO) ss.push_back("srefICAO");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & ALT) ss.push_back("alt");
	if (ix & THETA) ss.push_back("theta");
	if (ix & PHI) ss.push_back("phi");
	if (ix & TZ) ss.push_back("tz");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIMLocation
 ******************************************************************************/

IexBrlyIni::ImeIMLocation::ImeIMLocation() {
};

IexBrlyIni::ImeIMLocation::~ImeIMLocation() {
	clear();
};

void IexBrlyIni::ImeIMLocation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIMLocation::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIMLocation* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyIni::ImeitemIMLocation();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMLocation"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMLOCATION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMLocation"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMLocation"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIMLocation::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIMLocation* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMLocation");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMLocation", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMLocation";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIMLocation();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIMLocation::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMLocation." << StrMod::replaceChar(ImeIMLocation::VecWIel::getSrefs(511), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMLocation.end" << endl;
	};
};

void IexBrlyIni::ImeIMLocation::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMLocation");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIMOperator
 ******************************************************************************/

IexBrlyIni::ImeitemIMOperator::ImeitemIMOperator(
			const string& sref
			, const string& srefICAO
			, const string& Title
		) : BrlyMOperator() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->srefICAO = srefICAO;
	this->Title = Title;
};

IexBrlyIni::ImeitemIMOperator::ImeitemIMOperator(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIMOperator()
		{
	BrlyMOperator* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymoperator->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		srefICAO = rec->srefICAO;
		Title = rec->Title;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIMOperator::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMOperator::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefICAO = txtrd.fields[1]; ixWIelValid += ImeIMOperator::VecWIel::SREFICAO;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIMOperator::VecWIel::TITLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMOperator"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIMOperator::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMOperator::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefICAO", "ica", srefICAO)) ixWIelValid += ImeIMOperator::VecWIel::SREFICAO;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMOperator::VecWIel::TITLE;
	};
};

void IexBrlyIni::ImeitemIMOperator::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << srefICAO << "\t" << Title << endl;
};

void IexBrlyIni::ImeitemIMOperator::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","ica","tit"};
	else tags = {"ImeitemIMOperator","sref","srefICAO","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], srefICAO);
		writeString(wr, tags[3], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIMOperator::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIMOperator::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "sreficao") ix |= SREFICAO;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexBrlyIni::ImeIMOperator::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIMOperator::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFICAO) ss.push_back("srefICAO");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIMOperator
 ******************************************************************************/

IexBrlyIni::ImeIMOperator::ImeIMOperator() {
};

IexBrlyIni::ImeIMOperator::~ImeIMOperator() {
	clear();
};

void IexBrlyIni::ImeIMOperator::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIMOperator::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIMOperator* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyIni::ImeitemIMOperator();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMOperator"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMOPERATOR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMOperator"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMOperator"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIMOperator::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIMOperator* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMOperator");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMOperator", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMOperator";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIMOperator();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIMOperator::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMOperator." << StrMod::replaceChar(ImeIMOperator::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMOperator.end" << endl;
	};
};

void IexBrlyIni::ImeIMOperator::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMOperator");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIMPlntype
 ******************************************************************************/

IexBrlyIni::ImeitemIMPlntype::ImeitemIMPlntype(
			const string& sref
			, const string& Title
			, const string& srefBrlyKEqptype
			, const usmallint Capacity
		) : BrlyMPlntype() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
	this->srefBrlyKEqptype = srefBrlyKEqptype;
	this->Capacity = Capacity;
};

IexBrlyIni::ImeitemIMPlntype::ImeitemIMPlntype(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIMPlntype()
		{
	BrlyMPlntype* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymplntype->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Title = rec->Title;
		srefBrlyKEqptype = rec->srefBrlyKEqptype;
		Capacity = rec->Capacity;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIMPlntype::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMPlntype::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMPlntype::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {srefBrlyKEqptype = txtrd.fields[2]; ixWIelValid += ImeIMPlntype::VecWIel::SREFBRLYKEQPTYPE;};
	if (txtrd.fields.size() > 3) {Capacity = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIMPlntype::VecWIel::CAPACITY;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPlntype"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIMPlntype::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPlntype::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPlntype::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "srefBrlyKEqptype", "ety", srefBrlyKEqptype)) ixWIelValid += ImeIMPlntype::VecWIel::SREFBRLYKEQPTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Capacity", "cap", Capacity)) ixWIelValid += ImeIMPlntype::VecWIel::CAPACITY;
	};
};

void IexBrlyIni::ImeitemIMPlntype::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Title << "\t" << srefBrlyKEqptype << "\t" << Capacity << endl;
};

void IexBrlyIni::ImeitemIMPlntype::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","ety","cap"};
	else tags = {"ImeitemIMPlntype","sref","Title","srefBrlyKEqptype","Capacity"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], srefBrlyKEqptype);
		writeUsmallint(wr, tags[4], Capacity);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIMPlntype::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIMPlntype::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "srefbrlykeqptype") ix |= SREFBRLYKEQPTYPE;
		else if (ss[i] == "capacity") ix |= CAPACITY;
	};

	return(ix);
};

void IexBrlyIni::ImeIMPlntype::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*CAPACITY); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIMPlntype::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & SREFBRLYKEQPTYPE) ss.push_back("srefBrlyKEqptype");
	if (ix & CAPACITY) ss.push_back("Capacity");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIMPlntype
 ******************************************************************************/

IexBrlyIni::ImeIMPlntype::ImeIMPlntype() {
};

IexBrlyIni::ImeIMPlntype::~ImeIMPlntype() {
	clear();
};

void IexBrlyIni::ImeIMPlntype::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIMPlntype::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIMPlntype* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyIni::ImeitemIMPlntype();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPlntype"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPLNTYPE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPlntype"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPlntype"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIMPlntype::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIMPlntype* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPlntype");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPlntype", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPlntype";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIMPlntype();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIMPlntype::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMPlntype." << StrMod::replaceChar(ImeIMPlntype::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMPlntype.end" << endl;
	};
};

void IexBrlyIni::ImeIMPlntype::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPlntype");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIAMRegionDstswitch
 ******************************************************************************/

IexBrlyIni::ImeitemIAMRegionDstswitch::ImeitemIAMRegionDstswitch(
			const uint startd
			, const uint startt
		) : BrlyAMRegionDstswitch() {
	lineno = 0;
	ixWIelValid = 0;

	this->startd = startd;
	this->startt = startt;
};

IexBrlyIni::ImeitemIAMRegionDstswitch::ImeitemIAMRegionDstswitch(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIAMRegionDstswitch()
		{
	BrlyAMRegionDstswitch* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyamregiondstswitch->loadRecByRef(ref, &rec)) {
		refBrlyMRegion = rec->refBrlyMRegion;
		startd = rec->startd;
		startt = rec->startt;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIAMRegionDstswitch::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {ftmStartd = txtrd.fields[0]; ixWIelValid += ImeIAMRegionDstswitch::VecWIel::FTMSTARTD;};
	if (txtrd.fields.size() > 1) {ftmStartt = txtrd.fields[1]; ixWIelValid += ImeIAMRegionDstswitch::VecWIel::FTMSTARTT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMRegionDstswitch"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIAMRegionDstswitch::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "ftmStartd", "std", ftmStartd)) ixWIelValid += ImeIAMRegionDstswitch::VecWIel::FTMSTARTD;
		if (extractStringUclc(docctx, basexpath, "ftmStartt", "stt", ftmStartt)) ixWIelValid += ImeIAMRegionDstswitch::VecWIel::FTMSTARTT;
	};
};

void IexBrlyIni::ImeitemIAMRegionDstswitch::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Ftm::date(startd)
 << "\t" << Ftm::time(startt)
 << endl;
};

void IexBrlyIni::ImeitemIAMRegionDstswitch::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","std","stt"};
	else tags = {"ImeitemIAMRegionDstswitch","ftmStartd","ftmStartt"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Ftm::date(startd));
		writeString(wr, tags[2], Ftm::time(startt));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIAMRegionDstswitch::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIAMRegionDstswitch::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "ftmstartd") ix |= FTMSTARTD;
		else if (ss[i] == "ftmstartt") ix |= FTMSTARTT;
	};

	return(ix);
};

void IexBrlyIni::ImeIAMRegionDstswitch::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*FTMSTARTT); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIAMRegionDstswitch::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & FTMSTARTD) ss.push_back("ftmStartd");
	if (ix & FTMSTARTT) ss.push_back("ftmStartt");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIAMRegionDstswitch
 ******************************************************************************/

IexBrlyIni::ImeIAMRegionDstswitch::ImeIAMRegionDstswitch() {
};

IexBrlyIni::ImeIAMRegionDstswitch::~ImeIAMRegionDstswitch() {
	clear();
};

void IexBrlyIni::ImeIAMRegionDstswitch::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIAMRegionDstswitch::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIAMRegionDstswitch* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexBrlyIni::ImeitemIAMRegionDstswitch();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMRegionDstswitch"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMRegionDstswitch"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMREGIONDSTSWITCH) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMRegionDstswitch"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMRegionDstswitch"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIAMRegionDstswitch::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIAMRegionDstswitch* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMRegionDstswitch");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMRegionDstswitch", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMRegionDstswitch";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIAMRegionDstswitch();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIAMRegionDstswitch::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMRegionDstswitch." << StrMod::replaceChar(ImeIAMRegionDstswitch::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMRegionDstswitch.end" << endl;
	};
};

void IexBrlyIni::ImeIAMRegionDstswitch::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMRegionDstswitch");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIJMRegion
 ******************************************************************************/

IexBrlyIni::ImeitemIJMRegion::ImeitemIJMRegion(
			const uint x1Startd
			, const uint x1Stopd
			, const uint ixVDst
			, const double toffset
		) : BrlyJMRegion() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1Startd = x1Startd;
	this->x1Stopd = x1Stopd;
	this->ixVDst = ixVDst;
	this->toffset = toffset;
};

IexBrlyIni::ImeitemIJMRegion::ImeitemIJMRegion(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIJMRegion()
		{
	BrlyJMRegion* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyjmregion->loadRecByRef(ref, &rec)) {
		refBrlyMRegion = rec->refBrlyMRegion;
		x1Startd = rec->x1Startd;
		x1Stopd = rec->x1Stopd;
		ixVDst = rec->ixVDst;
		toffset = rec->toffset;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIJMRegion::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {ftmX1Startd = txtrd.fields[0]; ixWIelValid += ImeIJMRegion::VecWIel::FTMX1STARTD;};
	if (txtrd.fields.size() > 1) {ftmX1Stopd = txtrd.fields[1]; ixWIelValid += ImeIJMRegion::VecWIel::FTMX1STOPD;};
	if (txtrd.fields.size() > 2) {srefIxVDst = txtrd.fields[2]; ixWIelValid += ImeIJMRegion::VecWIel::SREFIXVDST;};
	if (txtrd.fields.size() > 3) {toffset = atof(txtrd.fields[3].c_str()); ixWIelValid += ImeIJMRegion::VecWIel::TOFFSET;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMRegion"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIJMRegion::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "ftmX1Startd", "sta", ftmX1Startd)) ixWIelValid += ImeIJMRegion::VecWIel::FTMX1STARTD;
		if (extractStringUclc(docctx, basexpath, "ftmX1Stopd", "sto", ftmX1Stopd)) ixWIelValid += ImeIJMRegion::VecWIel::FTMX1STOPD;
		if (extractStringUclc(docctx, basexpath, "srefIxVDst", "dst", srefIxVDst)) ixWIelValid += ImeIJMRegion::VecWIel::SREFIXVDST;
		if (extractDoubleUclc(docctx, basexpath, "toffset", "tof", toffset)) ixWIelValid += ImeIJMRegion::VecWIel::TOFFSET;
	};
};

void IexBrlyIni::ImeitemIJMRegion::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Ftm::date(x1Startd)
 << "\t" << Ftm::date(x1Stopd)
 << "\t" << VecBrlyVMRegionDst::getSref(ixVDst) << "\t" << toffset << endl;
};

void IexBrlyIni::ImeitemIJMRegion::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sta","sto","dst","tof"};
	else tags = {"ImeitemIJMRegion","ftmX1Startd","ftmX1Stopd","srefIxVDst","toffset"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Ftm::date(x1Startd));
		writeString(wr, tags[2], Ftm::date(x1Stopd));
		writeString(wr, tags[3], VecBrlyVMRegionDst::getSref(ixVDst));
		writeDouble(wr, tags[4], toffset);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIJMRegion::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIJMRegion::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "ftmx1startd") ix |= FTMX1STARTD;
		else if (ss[i] == "ftmx1stopd") ix |= FTMX1STOPD;
		else if (ss[i] == "srefixvdst") ix |= SREFIXVDST;
		else if (ss[i] == "toffset") ix |= TOFFSET;
	};

	return(ix);
};

void IexBrlyIni::ImeIJMRegion::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TOFFSET); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIJMRegion::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & FTMX1STARTD) ss.push_back("ftmX1Startd");
	if (ix & FTMX1STOPD) ss.push_back("ftmX1Stopd");
	if (ix & SREFIXVDST) ss.push_back("srefIxVDst");
	if (ix & TOFFSET) ss.push_back("toffset");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIJMRegion
 ******************************************************************************/

IexBrlyIni::ImeIJMRegion::ImeIJMRegion() {
};

IexBrlyIni::ImeIJMRegion::~ImeIJMRegion() {
	clear();
};

void IexBrlyIni::ImeIJMRegion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIJMRegion::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIJMRegion* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexBrlyIni::ImeitemIJMRegion();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMRegion"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMRegion"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMREGION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMRegion"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMRegion"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIJMRegion::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIJMRegion* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMRegion");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMRegion", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMRegion";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIJMRegion();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIJMRegion::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMRegion." << StrMod::replaceChar(ImeIJMRegion::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJMRegion.end" << endl;
	};
};

void IexBrlyIni::ImeIJMRegion::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMRegion");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIJMRegionTitle
 ******************************************************************************/

IexBrlyIni::ImeitemIJMRegionTitle::ImeitemIJMRegionTitle(
			const uint x1IxBrlyVLocale
			, const string& Title
		) : BrlyJMRegionTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxBrlyVLocale = x1IxBrlyVLocale;
	this->Title = Title;
};

IexBrlyIni::ImeitemIJMRegionTitle::ImeitemIJMRegionTitle(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIJMRegionTitle()
		{
	BrlyJMRegionTitle* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyjmregiontitle->loadRecByRef(ref, &rec)) {
		refBrlyMRegion = rec->refBrlyMRegion;
		x1IxBrlyVLocale = rec->x1IxBrlyVLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIJMRegionTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxBrlyVLocale = txtrd.fields[0]; ixWIelValid += ImeIJMRegionTitle::VecWIel::SREFX1IXBRLYVLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMRegionTitle::VecWIel::TITLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMRegionTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIJMRegionTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxBrlyVLocale", "lcl", srefX1IxBrlyVLocale)) ixWIelValid += ImeIJMRegionTitle::VecWIel::SREFX1IXBRLYVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMRegionTitle::VecWIel::TITLE;
	};
};

void IexBrlyIni::ImeitemIJMRegionTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecBrlyVLocale::getSref(x1IxBrlyVLocale) << "\t" << Title << endl;
};

void IexBrlyIni::ImeitemIJMRegionTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit"};
	else tags = {"ImeitemIJMRegionTitle","srefX1IxBrlyVLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVLocale::getSref(x1IxBrlyVLocale));
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIJMRegionTitle::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIJMRegionTitle::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixbrlyvlocale") ix |= SREFX1IXBRLYVLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexBrlyIni::ImeIJMRegionTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIJMRegionTitle::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXBRLYVLOCALE) ss.push_back("srefX1IxBrlyVLocale");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIJMRegionTitle
 ******************************************************************************/

IexBrlyIni::ImeIJMRegionTitle::ImeIJMRegionTitle() {
};

IexBrlyIni::ImeIJMRegionTitle::~ImeIJMRegionTitle() {
	clear();
};

void IexBrlyIni::ImeIJMRegionTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIJMRegionTitle::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIJMRegionTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexBrlyIni::ImeitemIJMRegionTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMRegionTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMRegionTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMREGIONTITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMRegionTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMRegionTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIJMRegionTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIJMRegionTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMRegionTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMRegionTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMRegionTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIJMRegionTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIJMRegionTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMRegionTitle." << StrMod::replaceChar(ImeIJMRegionTitle::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJMRegionTitle.end" << endl;
	};
};

void IexBrlyIni::ImeIJMRegionTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMRegionTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIMRegion
 ******************************************************************************/

IexBrlyIni::ImeitemIMRegion::ImeitemIMRegion(
			const string& hsrefSupRefBrlyMRegion
			, const string& sref
			, const string& Title
			, const uint ixVDst
			, const double toffset
		) : BrlyMRegion() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefSupRefBrlyMRegion = hsrefSupRefBrlyMRegion;
	this->sref = sref;
	this->Title = Title;
	this->ixVDst = ixVDst;
	this->toffset = toffset;
};

IexBrlyIni::ImeitemIMRegion::ImeitemIMRegion(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIMRegion()
		{
	BrlyMRegion* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymregion->loadRecByRef(ref, &rec)) {
		supRefBrlyMRegion = rec->supRefBrlyMRegion;
		sref = rec->sref;
		refJTitle = rec->refJTitle;
		Title = rec->Title;
		refJ = rec->refJ;
		ixVDst = rec->ixVDst;
		toffset = rec->toffset;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIMRegion::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefSupRefBrlyMRegion = txtrd.fields[0]; ixWIelValid += ImeIMRegion::VecWIel::HSREFSUPREFBRLYMREGION;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMRegion::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIMRegion::VecWIel::TITLE;};
	if (txtrd.fields.size() > 3) {srefIxVDst = txtrd.fields[3]; ixWIelValid += ImeIMRegion::VecWIel::SREFIXVDST;};
	if (txtrd.fields.size() > 4) {toffset = atof(txtrd.fields[4].c_str()); ixWIelValid += ImeIMRegion::VecWIel::TOFFSET;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMREGIONDSTSWITCH)) {
					imeiamregiondstswitch.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMREGION)) {
					imeijmregion.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMREGIONTITLE)) {
					imeijmregiontitle.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRegion"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIMRegion::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefBrlyMRegion", "sup", hsrefSupRefBrlyMRegion)) ixWIelValid += ImeIMRegion::VecWIel::HSREFSUPREFBRLYMREGION;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMRegion::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMRegion::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "srefIxVDst", "dst", srefIxVDst)) ixWIelValid += ImeIMRegion::VecWIel::SREFIXVDST;
		if (extractDoubleUclc(docctx, basexpath, "toffset", "tof", toffset)) ixWIelValid += ImeIMRegion::VecWIel::TOFFSET;
		imeiamregiondstswitch.readXML(docctx, basexpath);
		imeijmregion.readXML(docctx, basexpath);
		imeijmregiontitle.readXML(docctx, basexpath);
	};
};

void IexBrlyIni::ImeitemIMRegion::writeTxt(
			fstream& outfile
		) {
	outfile << hsrefSupRefBrlyMRegion << "\t" << sref << "\t" << Title << "\t" << VecBrlyVMRegionDst::getSref(ixVDst) << "\t" << toffset << endl;
	imeiamregiondstswitch.writeTxt(outfile);
	imeijmregion.writeTxt(outfile);
	imeijmregiontitle.writeTxt(outfile);
};

void IexBrlyIni::ImeitemIMRegion::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sup","srf","tit","dst","tof"};
	else tags = {"ImeitemIMRegion","hsrefSupRefBrlyMRegion","sref","Title","srefIxVDst","toffset"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefSupRefBrlyMRegion);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Title);
		writeString(wr, tags[4], VecBrlyVMRegionDst::getSref(ixVDst));
		writeDouble(wr, tags[5], toffset);
		imeiamregiondstswitch.writeXML(wr, shorttags);
		imeijmregion.writeXML(wr, shorttags);
		imeijmregiontitle.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIMRegion::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIMRegion::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefsuprefbrlymregion") ix |= HSREFSUPREFBRLYMREGION;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "srefixvdst") ix |= SREFIXVDST;
		else if (ss[i] == "toffset") ix |= TOFFSET;
	};

	return(ix);
};

void IexBrlyIni::ImeIMRegion::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TOFFSET); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIMRegion::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFSUPREFBRLYMREGION) ss.push_back("hsrefSupRefBrlyMRegion");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & SREFIXVDST) ss.push_back("srefIxVDst");
	if (ix & TOFFSET) ss.push_back("toffset");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIMRegion
 ******************************************************************************/

IexBrlyIni::ImeIMRegion::ImeIMRegion() {
};

IexBrlyIni::ImeIMRegion::~ImeIMRegion() {
	clear();
};

void IexBrlyIni::ImeIMRegion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIMRegion::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIMRegion* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyIni::ImeitemIMRegion();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRegion"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMREGION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRegion"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRegion"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIMRegion::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIMRegion* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMRegion");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMRegion", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMRegion";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIMRegion();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIMRegion::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMRegion." << StrMod::replaceChar(ImeIMRegion::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMRegion.end" << endl;
	};
};

void IexBrlyIni::ImeIMRegion::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMRegion");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIAMUsergroupAccess
 ******************************************************************************/

IexBrlyIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			const uint x1IxBrlyVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixBrlyWAccess
		) : BrlyAMUsergroupAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxBrlyVFeatgroup = x1IxBrlyVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixBrlyWAccess = ixBrlyWAccess;
};

IexBrlyIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIAMUsergroupAccess()
		{
	BrlyAMUsergroupAccess* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyamusergroupaccess->loadRecByRef(ref, &rec)) {
		refBrlyMUsergroup = rec->refBrlyMUsergroup;
		x1IxBrlyVFeatgroup = rec->x1IxBrlyVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixBrlyWAccess = rec->ixBrlyWAccess;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxBrlyVFeatgroup = txtrd.fields[0]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXBRLYVFEATGROUP;};
	if (txtrd.fields.size() > 1) {x2FeaSrefUix = txtrd.fields[1]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;};
	if (txtrd.fields.size() > 2) {srefsIxBrlyWAccess = txtrd.fields[2]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXBRLYWACCESS;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxBrlyVFeatgroup", "feg", srefX1IxBrlyVFeatgroup)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXBRLYVFEATGROUP;
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxBrlyWAccess", "acc", srefsIxBrlyWAccess)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXBRLYWACCESS;
	};
};

void IexBrlyIni::ImeitemIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecBrlyVFeatgroup::getSref(x1IxBrlyVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecBrlyWAccess::getSrefs(ixBrlyWAccess) << endl;
};

void IexBrlyIni::ImeitemIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUsergroupAccess","srefX1IxBrlyVFeatgroup","x2FeaSrefUix","srefsIxBrlyWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVFeatgroup::getSref(x1IxBrlyVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecBrlyWAccess::getSrefs(ixBrlyWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIAMUsergroupAccess::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIAMUsergroupAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixbrlyvfeatgroup") ix |= SREFX1IXBRLYVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixbrlywaccess") ix |= SREFSIXBRLYWACCESS;
	};

	return(ix);
};

void IexBrlyIni::ImeIAMUsergroupAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXBRLYWACCESS); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIAMUsergroupAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXBRLYVFEATGROUP) ss.push_back("srefX1IxBrlyVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXBRLYWACCESS) ss.push_back("srefsIxBrlyWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIAMUsergroupAccess
 ******************************************************************************/

IexBrlyIni::ImeIAMUsergroupAccess::ImeIAMUsergroupAccess() {
};

IexBrlyIni::ImeIAMUsergroupAccess::~ImeIAMUsergroupAccess() {
	clear();
};

void IexBrlyIni::ImeIAMUsergroupAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIAMUsergroupAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexBrlyIni::ImeitemIAMUsergroupAccess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIAMUsergroupAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUsergroupAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUsergroupAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUsergroupAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIAMUsergroupAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMUsergroupAccess." << StrMod::replaceChar(ImeIAMUsergroupAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMUsergroupAccess.end" << endl;
	};
};

void IexBrlyIni::ImeIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUsergroupAccess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIAMUserAccess
 ******************************************************************************/

IexBrlyIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			const uint x1IxBrlyVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixBrlyWAccess
		) : BrlyAMUserAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxBrlyVFeatgroup = x1IxBrlyVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixBrlyWAccess = ixBrlyWAccess;
};

IexBrlyIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIAMUserAccess()
		{
	BrlyAMUserAccess* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyamuseraccess->loadRecByRef(ref, &rec)) {
		refBrlyMUser = rec->refBrlyMUser;
		x1IxBrlyVFeatgroup = rec->x1IxBrlyVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixBrlyWAccess = rec->ixBrlyWAccess;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxBrlyVFeatgroup = txtrd.fields[0]; ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXBRLYVFEATGROUP;};
	if (txtrd.fields.size() > 1) {x2FeaSrefUix = txtrd.fields[1]; ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;};
	if (txtrd.fields.size() > 2) {srefsIxBrlyWAccess = txtrd.fields[2]; ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXBRLYWACCESS;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxBrlyVFeatgroup", "feg", srefX1IxBrlyVFeatgroup)) ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXBRLYVFEATGROUP;
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxBrlyWAccess", "acc", srefsIxBrlyWAccess)) ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXBRLYWACCESS;
	};
};

void IexBrlyIni::ImeitemIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecBrlyVFeatgroup::getSref(x1IxBrlyVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecBrlyWAccess::getSrefs(ixBrlyWAccess) << endl;
};

void IexBrlyIni::ImeitemIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUserAccess","srefX1IxBrlyVFeatgroup","x2FeaSrefUix","srefsIxBrlyWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVFeatgroup::getSref(x1IxBrlyVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecBrlyWAccess::getSrefs(ixBrlyWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIAMUserAccess::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIAMUserAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixbrlyvfeatgroup") ix |= SREFX1IXBRLYVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixbrlywaccess") ix |= SREFSIXBRLYWACCESS;
	};

	return(ix);
};

void IexBrlyIni::ImeIAMUserAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXBRLYWACCESS); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIAMUserAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXBRLYVFEATGROUP) ss.push_back("srefX1IxBrlyVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXBRLYWACCESS) ss.push_back("srefsIxBrlyWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIAMUserAccess
 ******************************************************************************/

IexBrlyIni::ImeIAMUserAccess::ImeIAMUserAccess() {
};

IexBrlyIni::ImeIAMUserAccess::~ImeIAMUserAccess() {
	clear();
};

void IexBrlyIni::ImeIAMUserAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIAMUserAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexBrlyIni::ImeitemIAMUserAccess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIAMUserAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUserAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUserAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUserAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIAMUserAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMUserAccess." << StrMod::replaceChar(ImeIAMUserAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMUserAccess.end" << endl;
	};
};

void IexBrlyIni::ImeIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUserAccess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIJMUserState
 ******************************************************************************/

IexBrlyIni::ImeitemIJMUserState::ImeitemIJMUserState(
			const uint ixVState
		) : BrlyJMUserState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexBrlyIni::ImeitemIJMUserState::ImeitemIJMUserState(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIJMUserState()
		{
	BrlyJMUserState* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyjmuserstate->loadRecByRef(ref, &rec)) {
		refBrlyMUser = rec->refBrlyMUser;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVState = txtrd.fields[0]; ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMUserState"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIJMUserState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;
	};
};

void IexBrlyIni::ImeitemIJMUserState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecBrlyVMUserState::getSref(ixVState) << endl;
};

void IexBrlyIni::ImeitemIJMUserState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMUserState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVMUserState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIJMUserState::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIJMUserState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexBrlyIni::ImeIJMUserState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVSTATE); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIJMUserState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIJMUserState
 ******************************************************************************/

IexBrlyIni::ImeIJMUserState::ImeIJMUserState() {
};

IexBrlyIni::ImeIJMUserState::~ImeIJMUserState() {
	clear();
};

void IexBrlyIni::ImeIJMUserState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIJMUserState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexBrlyIni::ImeitemIJMUserState();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIJMUserState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIJMUserState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMUserState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMUserState", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMUserState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIJMUserState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIJMUserState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMUserState." << StrMod::replaceChar(ImeIJMUserState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMUserState.end" << endl;
	};
};

void IexBrlyIni::ImeIJMUserState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMUserState");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIJMPersonLastname
 ******************************************************************************/

IexBrlyIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			const string& Lastname
		) : BrlyJMPersonLastname() {
	lineno = 0;
	ixWIelValid = 0;

	this->Lastname = Lastname;
};

IexBrlyIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIJMPersonLastname()
		{
	BrlyJMPersonLastname* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyjmpersonlastname->loadRecByRef(ref, &rec)) {
		refBrlyMPerson = rec->refBrlyMPerson;
		x1Startd = rec->x1Startd;
		Lastname = rec->Lastname;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Lastname = txtrd.fields[0]; ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;
	};
};

void IexBrlyIni::ImeitemIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Lastname << endl;
};

void IexBrlyIni::ImeitemIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lnm"};
	else tags = {"ImeitemIJMPersonLastname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Lastname);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIJMPersonLastname::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIJMPersonLastname::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexBrlyIni::ImeIJMPersonLastname::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LASTNAME); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIJMPersonLastname::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIJMPersonLastname
 ******************************************************************************/

IexBrlyIni::ImeIJMPersonLastname::ImeIJMPersonLastname() {
};

IexBrlyIni::ImeIJMPersonLastname::~ImeIJMPersonLastname() {
	clear();
};

void IexBrlyIni::ImeIJMPersonLastname::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIJMPersonLastname* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexBrlyIni::ImeitemIJMPersonLastname();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIJMPersonLastname* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMPersonLastname");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMPersonLastname", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMPersonLastname";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIJMPersonLastname();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPersonLastname." << StrMod::replaceChar(ImeIJMPersonLastname::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMPersonLastname.end" << endl;
	};
};

void IexBrlyIni::ImeIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMPersonLastname");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIMPerson
 ******************************************************************************/

IexBrlyIni::ImeitemIMPerson::ImeitemIMPerson(
			const uint ixVSex
			, const string& Title
			, const string& Firstname
			, const string& Lastname
		) : BrlyMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
};

IexBrlyIni::ImeitemIMPerson::ImeitemIMPerson(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIMPerson()
		{
	BrlyMPerson* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymperson->loadRecByRef(ref, &rec)) {
		ixWDerivate = rec->ixWDerivate;
		ixVSex = rec->ixVSex;
		Title = rec->Title;
		Firstname = rec->Firstname;
		refJLastname = rec->refJLastname;
		Lastname = rec->Lastname;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIMPerson::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVSex = txtrd.fields[0]; ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMPerson::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Firstname = txtrd.fields[2]; ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;};
	if (txtrd.fields.size() > 3) {Lastname = txtrd.fields[3]; ixWIelValid += ImeIMPerson::VecWIel::LASTNAME;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME)) {
					imeijmpersonlastname.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPerson"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex)) ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPerson::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname)) ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIMPerson::VecWIel::LASTNAME;
		imeijmpersonlastname.readXML(docctx, basexpath);
	};
};

void IexBrlyIni::ImeitemIMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecBrlyVMPersonSex::getSref(ixVSex) << "\t" << Title << "\t" << Firstname << "\t" << Lastname << endl;
	imeijmpersonlastname.writeTxt(outfile);
};

void IexBrlyIni::ImeitemIMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sex","tit","fnm","lnm"};
	else tags = {"ImeitemIMPerson","srefIxVSex","Title","Firstname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVMPersonSex::getSref(ixVSex));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Firstname);
		writeString(wr, tags[4], Lastname);
		imeijmpersonlastname.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIMPerson::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvsex") ix |= SREFIXVSEX;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "firstname") ix |= FIRSTNAME;
		else if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexBrlyIni::ImeIMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LASTNAME); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSEX) ss.push_back("srefIxVSex");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & FIRSTNAME) ss.push_back("Firstname");
	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIMPerson
 ******************************************************************************/

IexBrlyIni::ImeIMPerson::ImeIMPerson() {
};

IexBrlyIni::ImeIMPerson::~ImeIMPerson() {
	clear();
};

void IexBrlyIni::ImeIMPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexBrlyIni::ImeitemIMPerson();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPERSON) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIMPerson* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPerson");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPerson", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPerson";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPerson." << StrMod::replaceChar(ImeIMPerson::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPerson.end" << endl;
	};
};

void IexBrlyIni::ImeIMPerson::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPerson");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIMUser
 ******************************************************************************/

IexBrlyIni::ImeitemIMUser::ImeitemIMUser(
			const string& sref
			, const uint ixVState
			, const uint ixBrlyVLocale
			, const uint ixBrlyVUserlevel
			, const string& Password
			, const string& Fullkey
			, const string& Comment
		) : BrlyMUser() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixVState = ixVState;
	this->ixBrlyVLocale = ixBrlyVLocale;
	this->ixBrlyVUserlevel = ixBrlyVUserlevel;
	this->Password = Password;
	this->Fullkey = Fullkey;
	this->Comment = Comment;
};

IexBrlyIni::ImeitemIMUser::ImeitemIMUser(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIMUser()
		{
	BrlyMUser* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymuser->loadRecByRef(ref, &rec)) {
		refRUsergroup = rec->refRUsergroup;
		refBrlyMUsergroup = rec->refBrlyMUsergroup;
		refBrlyMPerson = rec->refBrlyMPerson;
		sref = rec->sref;
		refJState = rec->refJState;
		ixVState = rec->ixVState;
		ixBrlyVLocale = rec->ixBrlyVLocale;
		ixBrlyVUserlevel = rec->ixBrlyVUserlevel;
		Password = rec->Password;
		Fullkey = rec->Fullkey;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIMUser::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUser::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxVState = txtrd.fields[1]; ixWIelValid += ImeIMUser::VecWIel::SREFIXVSTATE;};
	if (txtrd.fields.size() > 2) {srefIxBrlyVLocale = txtrd.fields[2]; ixWIelValid += ImeIMUser::VecWIel::SREFIXBRLYVLOCALE;};
	if (txtrd.fields.size() > 3) {srefIxBrlyVUserlevel = txtrd.fields[3]; ixWIelValid += ImeIMUser::VecWIel::SREFIXBRLYVUSERLEVEL;};
	if (txtrd.fields.size() > 4) {Password = txtrd.fields[4]; ixWIelValid += ImeIMUser::VecWIel::PASSWORD;};
	if (txtrd.fields.size() > 5) {Fullkey = txtrd.fields[5]; ixWIelValid += ImeIMUser::VecWIel::FULLKEY;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMUser::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS)) {
					imeiamuseraccess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE)) {
					imeijmuserstate.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPERSON)) {
					imeimperson.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUser"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIMUser::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUser::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIMUser::VecWIel::SREFIXVSTATE;
		if (extractStringUclc(docctx, basexpath, "srefIxBrlyVLocale", "lcl", srefIxBrlyVLocale)) ixWIelValid += ImeIMUser::VecWIel::SREFIXBRLYVLOCALE;
		if (extractStringUclc(docctx, basexpath, "srefIxBrlyVUserlevel", "ulv", srefIxBrlyVUserlevel)) ixWIelValid += ImeIMUser::VecWIel::SREFIXBRLYVUSERLEVEL;
		if (extractStringUclc(docctx, basexpath, "Password", "pwd", Password)) ixWIelValid += ImeIMUser::VecWIel::PASSWORD;
		if (extractStringUclc(docctx, basexpath, "Fullkey", "fky", Fullkey)) ixWIelValid += ImeIMUser::VecWIel::FULLKEY;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUser::VecWIel::COMMENT;
		imeiamuseraccess.readXML(docctx, basexpath);
		imeijmuserstate.readXML(docctx, basexpath);
		imeimperson.readXML(docctx, basexpath);
	};
};

void IexBrlyIni::ImeitemIMUser::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << VecBrlyVMUserState::getSref(ixVState) << "\t" << VecBrlyVLocale::getSref(ixBrlyVLocale) << "\t" << VecBrlyVUserlevel::getSref(ixBrlyVUserlevel) << "\t" << Password << "\t" << Fullkey << "\t" << Comment << endl;
	imeiamuseraccess.writeTxt(outfile);
	imeijmuserstate.writeTxt(outfile);
	imeimperson.writeTxt(outfile);
};

void IexBrlyIni::ImeitemIMUser::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","ste","lcl","ulv","pwd","fky","cmt"};
	else tags = {"ImeitemIMUser","sref","srefIxVState","srefIxBrlyVLocale","srefIxBrlyVUserlevel","Password","Fullkey","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecBrlyVMUserState::getSref(ixVState));
		writeString(wr, tags[3], VecBrlyVLocale::getSref(ixBrlyVLocale));
		writeString(wr, tags[4], VecBrlyVUserlevel::getSref(ixBrlyVUserlevel));
		writeString(wr, tags[5], Password);
		writeString(wr, tags[6], Fullkey);
		writeString(wr, tags[7], Comment);
		imeiamuseraccess.writeXML(wr, shorttags);
		imeijmuserstate.writeXML(wr, shorttags);
		imeimperson.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIMUser::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIMUser::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
		else if (ss[i] == "srefixbrlyvlocale") ix |= SREFIXBRLYVLOCALE;
		else if (ss[i] == "srefixbrlyvuserlevel") ix |= SREFIXBRLYVUSERLEVEL;
		else if (ss[i] == "password") ix |= PASSWORD;
		else if (ss[i] == "fullkey") ix |= FULLKEY;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexBrlyIni::ImeIMUser::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIMUser::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");
	if (ix & SREFIXBRLYVLOCALE) ss.push_back("srefIxBrlyVLocale");
	if (ix & SREFIXBRLYVUSERLEVEL) ss.push_back("srefIxBrlyVUserlevel");
	if (ix & PASSWORD) ss.push_back("Password");
	if (ix & FULLKEY) ss.push_back("Fullkey");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIMUser
 ******************************************************************************/

IexBrlyIni::ImeIMUser::ImeIMUser() {
};

IexBrlyIni::ImeIMUser::~ImeIMUser() {
	clear();
};

void IexBrlyIni::ImeIMUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIMUser::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIMUser* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexBrlyIni::ImeitemIMUser();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUSER) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIMUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIMUser* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUser");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUser", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUser";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIMUser();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIMUser::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMUser." << StrMod::replaceChar(ImeIMUser::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMUser.end" << endl;
	};
};

void IexBrlyIni::ImeIMUser::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUser");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyIni::ImeitemIMUsergroup
 ******************************************************************************/

IexBrlyIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			const string& sref
			, const string& Comment
		) : BrlyMUsergroup() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexBrlyIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIMUsergroup()
		{
	BrlyMUsergroup* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymusergroup->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexBrlyIni::ImeitemIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUsergroup::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS)) {
					imeiamusergroupaccess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMUSER)) {
					imeimuser.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyIni::ImeitemIMUsergroup::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUsergroup::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;
		imeiamusergroupaccess.readXML(docctx, basexpath);
		imeimuser.readXML(docctx, basexpath);
	};
};

void IexBrlyIni::ImeitemIMUsergroup::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Comment << endl;
	imeiamusergroupaccess.writeTxt(outfile);
	imeimuser.writeTxt(outfile);
};

void IexBrlyIni::ImeitemIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMUsergroup","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamusergroupaccess.writeXML(wr, shorttags);
		imeimuser.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyIni::ImeIMUsergroup::VecWIel
 ******************************************************************************/

uint IexBrlyIni::ImeIMUsergroup::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexBrlyIni::ImeIMUsergroup::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyIni::ImeIMUsergroup::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyIni::ImeIMUsergroup
 ******************************************************************************/

IexBrlyIni::ImeIMUsergroup::ImeIMUsergroup() {
};

IexBrlyIni::ImeIMUsergroup::~ImeIMUsergroup() {
	clear();
};

void IexBrlyIni::ImeIMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyIni::ImeIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyIni::ImeitemIMUsergroup* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyIni::ImeitemIMUsergroup();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyIni::ImeIMUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyIni::ImeitemIMUsergroup* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUsergroup");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUsergroup", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUsergroup";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyIni::ImeitemIMUsergroup();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyIni::ImeIMUsergroup::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUsergroup." << StrMod::replaceChar(ImeIMUsergroup::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUsergroup.end" << endl;
	};
};

void IexBrlyIni::ImeIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUsergroup");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexBrlyIni
 ******************************************************************************/

void IexBrlyIni::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMLocation& imeimlocation
			, ImeIMOperator& imeimoperator
			, ImeIMPlntype& imeimplntype
			, ImeIMRegion& imeimregion
			, ImeIMUsergroup& imeimusergroup
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimlocation, imeimoperator, imeimplntype, imeimregion, imeimusergroup);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexBrlyIni", Version("0.2.9"), VecVIme::getIx);
			readTxt(rd, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimlocation, imeimoperator, imeimplntype, imeimregion, imeimusergroup);
	};
};

void IexBrlyIni::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMLocation& imeimlocation
			, ImeIMOperator& imeimoperator
			, ImeIMPlntype& imeimplntype
			, ImeIMRegion& imeimregion
			, ImeIMUsergroup& imeimusergroup
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimlocation, imeimoperator, imeimplntype, imeimregion, imeimusergroup);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimlocation, imeimoperator, imeimplntype, imeimregion, imeimusergroup);
		txtfile.close();
	};
};

void IexBrlyIni::readTxt(
			Txtrd& txtrd
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMLocation& imeimlocation
			, ImeIMOperator& imeimoperator
			, ImeIMPlntype& imeimplntype
			, ImeIMRegion& imeimregion
			, ImeIMUsergroup& imeimusergroup
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR)) imeiavcontrolpar.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY)) imeiavkeylistkey.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL)) imeiavvaluelistval.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMFILE)) imeimfile.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMLOCATION)) imeimlocation.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMOPERATOR)) imeimoperator.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMPLNTYPE)) imeimplntype.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMREGION)) imeimregion.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP)) imeimusergroup.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexBrlyIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMLocation& imeimlocation
			, ImeIMOperator& imeimoperator
			, ImeIMPlntype& imeimplntype
			, ImeIMRegion& imeimregion
			, ImeIMUsergroup& imeimusergroup
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexBrlyIni")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.2.9")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.2.9"}});
		};

		// look for XML sub-blocks
		imeiavcontrolpar.readXML(docctx, basexpath);
		imeiavkeylistkey.readXML(docctx, basexpath);
		imeiavvaluelistval.readXML(docctx, basexpath);
		imeimfile.readXML(docctx, basexpath);
		imeimlocation.readXML(docctx, basexpath);
		imeimoperator.readXML(docctx, basexpath);
		imeimplntype.readXML(docctx, basexpath);
		imeimregion.readXML(docctx, basexpath);
		imeimusergroup.readXML(docctx, basexpath);

	} else {
		imeiavcontrolpar = ImeIAVControlPar();
		imeiavkeylistkey = ImeIAVKeylistKey();
		imeiavvaluelistval = ImeIAVValuelistVal();
		imeimfile = ImeIMFile();
		imeimlocation = ImeIMLocation();
		imeimoperator = ImeIMOperator();
		imeimplntype = ImeIMPlntype();
		imeimregion = ImeIMRegion();
		imeimusergroup = ImeIMUsergroup();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexBrlyIni"}});
	};
};

void IexBrlyIni::writeTxt(
			fstream& outfile
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMLocation& imeimlocation
			, ImeIMOperator& imeimoperator
			, ImeIMPlntype& imeimplntype
			, ImeIMRegion& imeimregion
			, ImeIMUsergroup& imeimusergroup
		) {
	outfile << "IexBrlyIni v" BRLY_VERSION << endl;

	imeiavcontrolpar.writeTxt(outfile);
	imeiavkeylistkey.writeTxt(outfile);
	imeiavvaluelistval.writeTxt(outfile);
	imeimfile.writeTxt(outfile);
	imeimlocation.writeTxt(outfile);
	imeimoperator.writeTxt(outfile);
	imeimplntype.writeTxt(outfile);
	imeimregion.writeTxt(outfile);
	imeimusergroup.writeTxt(outfile);
};

void IexBrlyIni::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMLocation& imeimlocation
			, ImeIMOperator& imeimoperator
			, ImeIMPlntype& imeimplntype
			, ImeIMRegion& imeimregion
			, ImeIMUsergroup& imeimusergroup
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexBrlyIni");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST BRLY_VERSION);

		imeiavcontrolpar.writeXML(wr, shorttags);
		imeiavkeylistkey.writeXML(wr, shorttags);
		imeiavvaluelistval.writeXML(wr, shorttags);
		imeimfile.writeXML(wr, shorttags);
		imeimlocation.writeXML(wr, shorttags);
		imeimoperator.writeXML(wr, shorttags);
		imeimplntype.writeXML(wr, shorttags);
		imeimregion.writeXML(wr, shorttags);
		imeimusergroup.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexBrlyIni::icsBrlyVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMREGIONDSTSWITCH,VecBrlyVIop::INS},{(uint)VecVIme::IMEIAMUSERACCESS,VecBrlyVIop::INS},{(uint)VecVIme::IMEIAMUSERGROUPACCESS,VecBrlyVIop::INS},{(uint)VecVIme::IMEIAVCONTROLPAR,VecBrlyVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecBrlyVIop::INS},{(uint)VecVIme::IMEIAVVALUELISTVAL,VecBrlyVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecBrlyVIop::INS},{(uint)VecVIme::IMEIJMPERSONLASTNAME,VecBrlyVIop::INS},{(uint)VecVIme::IMEIJMREGION,VecBrlyVIop::INS},{(uint)VecVIme::IMEIJMREGIONTITLE,VecBrlyVIop::INS},{(uint)VecVIme::IMEIJMUSERSTATE,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMFILE,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMLOCATION,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMOPERATOR,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMPERSON,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMPLNTYPE,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMREGION,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMUSER,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMUSERGROUP,VecBrlyVIop::INS}};
};

uint IexBrlyIni::getIxBrlyVIop(
			const map<uint,uint>& icsBrlyVIop
			, const uint ixVIme
			, uint& ixBrlyVIop
		) {
	ixBrlyVIop = 0;

	auto it = icsBrlyVIop.find(ixVIme);
	if (it != icsBrlyVIop.end()) ixBrlyVIop = it->second;

	return ixBrlyVIop;
};
