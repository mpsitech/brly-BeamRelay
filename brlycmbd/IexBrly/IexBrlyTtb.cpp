/**
	* \file IexBrlyTtb.cpp
	* data blocks and readers/writers for import/export complex IexBrlyTtb (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#include "IexBrlyTtb.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexBrlyTtb::VecVIme
 ******************************************************************************/

uint IexBrlyTtb::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeimflight") return IMEIMFLIGHT;
	if (s == "imeimleg") return IMEIMLEG;

	return(0);
};

string IexBrlyTtb::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIMFLIGHT) return("ImeIMFlight");
	if (ix == IMEIMLEG) return("ImeIMLeg");

	return("");
};

/******************************************************************************
 class IexBrlyTtb::ImeitemIMFlight
 ******************************************************************************/

IexBrlyTtb::ImeitemIMFlight::ImeitemIMFlight(
			const string& hintRefBrlyMEquipment
			, const ubigint irefRefBrlyMLeg
			, const string& sref
			, const string& hintStart
			, const string& hintStop
			, const string& iDate
			, const string& iWeekday
		) : BrlyMFlight() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRefBrlyMEquipment = hintRefBrlyMEquipment;
	this->irefRefBrlyMLeg = irefRefBrlyMLeg;
	this->sref = sref;
	this->hintStart = hintStart;
	this->hintStop = hintStop;
	this->iDate = iDate;
	this->iWeekday = iWeekday;
};

IexBrlyTtb::ImeitemIMFlight::ImeitemIMFlight(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIMFlight()
		{
	BrlyMFlight* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymflight->loadRecByRef(ref, &rec)) {
		refBrlyMTimetable = rec->refBrlyMTimetable;
		refBrlyMEquipment = rec->refBrlyMEquipment;
		refBrlyMLeg = rec->refBrlyMLeg;
		sref = rec->sref;
		start = rec->start;
		stop = rec->stop;
		Calcdone = rec->Calcdone;

		delete rec;
	};
};

void IexBrlyTtb::ImeitemIMFlight::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hintRefBrlyMEquipment = txtrd.fields[0]; ixWIelValid += ImeIMFlight::VecWIel::HINTREFBRLYMEQUIPMENT;};
	if (txtrd.fields.size() > 1) {irefRefBrlyMLeg = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMFlight::VecWIel::IREFREFBRLYMLEG;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMFlight::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {hintStart = txtrd.fields[3]; ixWIelValid += ImeIMFlight::VecWIel::HINTSTART;};
	if (txtrd.fields.size() > 4) {hintStop = txtrd.fields[4]; ixWIelValid += ImeIMFlight::VecWIel::HINTSTOP;};
	if (txtrd.fields.size() > 5) {iDate = txtrd.fields[5]; ixWIelValid += ImeIMFlight::VecWIel::IDATE;};
	if (txtrd.fields.size() > 6) {iWeekday = txtrd.fields[6]; ixWIelValid += ImeIMFlight::VecWIel::IWEEKDAY;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFlight"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyTtb::ImeitemIMFlight::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hintRefBrlyMEquipment", "eqp", hintRefBrlyMEquipment)) ixWIelValid += ImeIMFlight::VecWIel::HINTREFBRLYMEQUIPMENT;
		if (extractUbigintUclc(docctx, basexpath, "irefRefBrlyMLeg", "leg", irefRefBrlyMLeg)) ixWIelValid += ImeIMFlight::VecWIel::IREFREFBRLYMLEG;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMFlight::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "hintStart", "sta", hintStart)) ixWIelValid += ImeIMFlight::VecWIel::HINTSTART;
		if (extractStringUclc(docctx, basexpath, "hintStop", "sto", hintStop)) ixWIelValid += ImeIMFlight::VecWIel::HINTSTOP;
		if (extractStringUclc(docctx, basexpath, "iDate", "dte", iDate)) ixWIelValid += ImeIMFlight::VecWIel::IDATE;
		if (extractStringUclc(docctx, basexpath, "iWeekday", "wdy", iWeekday)) ixWIelValid += ImeIMFlight::VecWIel::IWEEKDAY;
	};
};

void IexBrlyTtb::ImeitemIMFlight::writeTxt(
			fstream& outfile
		) {
	outfile << hintRefBrlyMEquipment << "\t" << irefRefBrlyMLeg << "\t" << sref << "\t" << hintStart << "\t" << hintStop << "\t" << iDate << "\t" << iWeekday << endl;
};

void IexBrlyTtb::ImeitemIMFlight::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","eqp","leg","srf","sta","sto","dte","wdy"};
	else tags = {"ImeitemIMFlight","hintRefBrlyMEquipment","irefRefBrlyMLeg","sref","hintStart","hintStop","iDate","iWeekday"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRefBrlyMEquipment);
		writeUbigint(wr, tags[2], irefRefBrlyMLeg);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], hintStart);
		writeString(wr, tags[5], hintStop);
		writeString(wr, tags[6], iDate);
		writeString(wr, tags[7], iWeekday);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyTtb::ImeIMFlight::VecWIel
 ******************************************************************************/

uint IexBrlyTtb::ImeIMFlight::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hintrefbrlymequipment") ix |= HINTREFBRLYMEQUIPMENT;
		else if (ss[i] == "irefrefbrlymleg") ix |= IREFREFBRLYMLEG;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "hintstart") ix |= HINTSTART;
		else if (ss[i] == "hintstop") ix |= HINTSTOP;
		else if (ss[i] == "idate") ix |= IDATE;
		else if (ss[i] == "iweekday") ix |= IWEEKDAY;
	};

	return(ix);
};

void IexBrlyTtb::ImeIMFlight::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IWEEKDAY); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyTtb::ImeIMFlight::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTREFBRLYMEQUIPMENT) ss.push_back("hintRefBrlyMEquipment");
	if (ix & IREFREFBRLYMLEG) ss.push_back("irefRefBrlyMLeg");
	if (ix & SREF) ss.push_back("sref");
	if (ix & HINTSTART) ss.push_back("hintStart");
	if (ix & HINTSTOP) ss.push_back("hintStop");
	if (ix & IDATE) ss.push_back("iDate");
	if (ix & IWEEKDAY) ss.push_back("iWeekday");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyTtb::ImeIMFlight
 ******************************************************************************/

IexBrlyTtb::ImeIMFlight::ImeIMFlight() {
};

IexBrlyTtb::ImeIMFlight::~ImeIMFlight() {
	clear();
};

void IexBrlyTtb::ImeIMFlight::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyTtb::ImeIMFlight::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyTtb::ImeitemIMFlight* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyTtb::ImeitemIMFlight();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFlight"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFLIGHT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFlight"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFlight"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyTtb::ImeIMFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyTtb::ImeitemIMFlight* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFlight");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFlight", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFlight";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyTtb::ImeitemIMFlight();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyTtb::ImeIMFlight::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFlight." << StrMod::replaceChar(ImeIMFlight::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMFlight.end" << endl;
	};
};

void IexBrlyTtb::ImeIMFlight::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFlight");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyTtb::ImeitemIMLeg
 ******************************************************************************/

IexBrlyTtb::ImeitemIMLeg::ImeitemIMLeg(
			const ubigint iref
			, const string& srefBgnRefBrlyMLocation
			, const string& srefEndRefBrlyMLocation
		) : BrlyMLeg() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->srefBgnRefBrlyMLocation = srefBgnRefBrlyMLocation;
	this->srefEndRefBrlyMLocation = srefEndRefBrlyMLocation;
};

IexBrlyTtb::ImeitemIMLeg::ImeitemIMLeg(
			DbsBrly* dbsbrly
			, const ubigint ref
		) :
			ImeitemIMLeg()
		{
	BrlyMLeg* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymleg->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		bgnRefBrlyMLocation = rec->bgnRefBrlyMLocation;
		endRefBrlyMLocation = rec->endRefBrlyMLocation;
		alt = rec->alt;
		deltaphi = rec->deltaphi;
		alpha = rec->alpha;
		Calcdone = rec->Calcdone;

		delete rec;
	};
};

void IexBrlyTtb::ImeitemIMLeg::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMLeg::VecWIel::IREF;};
	if (txtrd.fields.size() > 1) {srefBgnRefBrlyMLocation = txtrd.fields[1]; ixWIelValid += ImeIMLeg::VecWIel::SREFBGNREFBRLYMLOCATION;};
	if (txtrd.fields.size() > 2) {srefEndRefBrlyMLocation = txtrd.fields[2]; ixWIelValid += ImeIMLeg::VecWIel::SREFENDREFBRLYMLOCATION;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMLeg"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexBrlyTtb::ImeitemIMLeg::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMLeg::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefBgnRefBrlyMLocation", "bgn", srefBgnRefBrlyMLocation)) ixWIelValid += ImeIMLeg::VecWIel::SREFBGNREFBRLYMLOCATION;
		if (extractStringUclc(docctx, basexpath, "srefEndRefBrlyMLocation", "end", srefEndRefBrlyMLocation)) ixWIelValid += ImeIMLeg::VecWIel::SREFENDREFBRLYMLOCATION;
	};
};

void IexBrlyTtb::ImeitemIMLeg::writeTxt(
			fstream& outfile
		) {
	outfile << iref << "\t" << srefBgnRefBrlyMLocation << "\t" << srefEndRefBrlyMLocation << endl;
};

void IexBrlyTtb::ImeitemIMLeg::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","bgn","end"};
	else tags = {"ImeitemIMLeg","iref","srefBgnRefBrlyMLocation","srefEndRefBrlyMLocation"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], srefBgnRefBrlyMLocation);
		writeString(wr, tags[3], srefEndRefBrlyMLocation);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyTtb::ImeIMLeg::VecWIel
 ******************************************************************************/

uint IexBrlyTtb::ImeIMLeg::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefbgnrefbrlymlocation") ix |= SREFBGNREFBRLYMLOCATION;
		else if (ss[i] == "srefendrefbrlymlocation") ix |= SREFENDREFBRLYMLOCATION;
	};

	return(ix);
};

void IexBrlyTtb::ImeIMLeg::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFENDREFBRLYMLOCATION); i *= 2) if (ix & i) ics.insert(i);
};

string IexBrlyTtb::ImeIMLeg::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFBGNREFBRLYMLOCATION) ss.push_back("srefBgnRefBrlyMLocation");
	if (ix & SREFENDREFBRLYMLOCATION) ss.push_back("srefEndRefBrlyMLocation");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyTtb::ImeIMLeg
 ******************************************************************************/

IexBrlyTtb::ImeIMLeg::ImeIMLeg() {
};

IexBrlyTtb::ImeIMLeg::~ImeIMLeg() {
	clear();
};

void IexBrlyTtb::ImeIMLeg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexBrlyTtb::ImeIMLeg::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyTtb::ImeitemIMLeg* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexBrlyTtb::ImeitemIMLeg();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMLeg"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMLEG) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMLeg"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMLeg"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexBrlyTtb::ImeIMLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyTtb::ImeitemIMLeg* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMLeg");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMLeg", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMLeg";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyTtb::ImeitemIMLeg();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyTtb::ImeIMLeg::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMLeg." << StrMod::replaceChar(ImeIMLeg::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMLeg.end" << endl;
	};
};

void IexBrlyTtb::ImeIMLeg::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMLeg");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexBrlyTtb
 ******************************************************************************/

void IexBrlyTtb::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMFlight& imeimflight
			, ImeIMLeg& imeimleg
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimflight, imeimleg);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexBrlyTtb", Version(""), VecVIme::getIx);
			readTxt(rd, imeimflight, imeimleg);
	};
};

void IexBrlyTtb::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMFlight& imeimflight
			, ImeIMLeg& imeimleg
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimflight, imeimleg);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimflight, imeimleg);
		txtfile.close();
	};
};

void IexBrlyTtb::readTxt(
			Txtrd& txtrd
			, ImeIMFlight& imeimflight
			, ImeIMLeg& imeimleg
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMFLIGHT)) imeimflight.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMLEG)) imeimleg.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexBrlyTtb::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMFlight& imeimflight
			, ImeIMLeg& imeimleg
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexBrlyTtb")) {

		// look for XML sub-blocks
		imeimflight.readXML(docctx, basexpath);
		imeimleg.readXML(docctx, basexpath);

	} else {
		imeimflight = ImeIMFlight();
		imeimleg = ImeIMLeg();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexBrlyTtb"}});
	};
};

void IexBrlyTtb::writeTxt(
			fstream& outfile
			, ImeIMFlight& imeimflight
			, ImeIMLeg& imeimleg
		) {
	outfile << "IexBrlyTtb v" BRLY_VERSION << endl;

	imeimflight.writeTxt(outfile);
	imeimleg.writeTxt(outfile);
};

void IexBrlyTtb::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMFlight& imeimflight
			, ImeIMLeg& imeimleg
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexBrlyTtb");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST BRLY_VERSION);

		imeimflight.writeXML(wr, shorttags);
		imeimleg.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexBrlyTtb::icsBrlyVIopInsAll() {
	return {{(uint)VecVIme::IMEIMLEG,VecBrlyVIop::RETRINS}};
};

uint IexBrlyTtb::getIxBrlyVIop(
			const map<uint,uint>& icsBrlyVIop
			, const uint ixVIme
			, uint& ixBrlyVIop
		) {
	ixBrlyVIop = 0;

	auto it = icsBrlyVIop.find(ixVIme);
	if (it != icsBrlyVIop.end()) ixBrlyVIop = it->second;

	return ixBrlyVIop;
};
