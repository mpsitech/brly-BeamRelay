/**
	* \file BrlyQUsrList.cpp
	* Dbs and XML wrapper for table TblBrlyQUsrList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQUsrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQUsrList
 ******************************************************************************/

BrlyQUsrList::BrlyQUsrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refBrlyMPerson
			, const string stubRefBrlyMPerson
			, const string sref
			, const ubigint refBrlyMUsergroup
			, const string stubRefBrlyMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixBrlyVLocale
			, const string srefIxBrlyVLocale
			, const string titIxBrlyVLocale
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->refBrlyMPerson = refBrlyMPerson;
	this->stubRefBrlyMPerson = stubRefBrlyMPerson;
	this->sref = sref;
	this->refBrlyMUsergroup = refBrlyMUsergroup;
	this->stubRefBrlyMUsergroup = stubRefBrlyMUsergroup;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ixBrlyVLocale = ixBrlyVLocale;
	this->srefIxBrlyVLocale = srefIxBrlyVLocale;
	this->titIxBrlyVLocale = titIxBrlyVLocale;
	this->ixBrlyVUserlevel = ixBrlyVUserlevel;
	this->srefIxBrlyVUserlevel = srefIxBrlyVUserlevel;
	this->titIxBrlyVUserlevel = titIxBrlyVUserlevel;
};

void BrlyQUsrList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["grp"] = stubGrp;
		me["own"] = stubOwn;
		me["prs"] = stubRefBrlyMPerson;
		me["srf"] = sref;
		me["usg"] = stubRefBrlyMUsergroup;
		me["ste"] = srefIxVState;
		me["ste2"] = titIxVState;
		me["lcl"] = srefIxBrlyVLocale;
		me["lcl2"] = titIxBrlyVLocale;
		me["ulv"] = srefIxBrlyVUserlevel;
		me["ulv2"] = titIxBrlyVUserlevel;
	} else {
		me["stubGrp"] = stubGrp;
		me["stubOwn"] = stubOwn;
		me["stubRefBrlyMPerson"] = stubRefBrlyMPerson;
		me["sref"] = sref;
		me["stubRefBrlyMUsergroup"] = stubRefBrlyMUsergroup;
		me["srefIxVState"] = srefIxVState;
		me["titIxVState"] = titIxVState;
		me["srefIxBrlyVLocale"] = srefIxBrlyVLocale;
		me["titIxBrlyVLocale"] = titIxBrlyVLocale;
		me["srefIxBrlyVUserlevel"] = srefIxBrlyVUserlevel;
		me["titIxBrlyVUserlevel"] = titIxBrlyVUserlevel;
	};
};

void BrlyQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "prs", stubRefBrlyMPerson);
		writeString(wr, "srf", sref);
		writeString(wr, "usg", stubRefBrlyMUsergroup);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "lcl", srefIxBrlyVLocale);
		writeString(wr, "lcl2", titIxBrlyVLocale);
		writeString(wr, "ulv", srefIxBrlyVUserlevel);
		writeString(wr, "ulv2", titIxBrlyVUserlevel);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "stubRefBrlyMPerson", stubRefBrlyMPerson);
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefBrlyMUsergroup", stubRefBrlyMUsergroup);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "srefIxBrlyVLocale", srefIxBrlyVLocale);
		writeString(wr, "titIxBrlyVLocale", titIxBrlyVLocale);
		writeString(wr, "srefIxBrlyVUserlevel", srefIxBrlyVUserlevel);
		writeString(wr, "titIxBrlyVUserlevel", titIxBrlyVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQUsrList
 ******************************************************************************/

ListBrlyQUsrList::ListBrlyQUsrList() {
};

ListBrlyQUsrList::ListBrlyQUsrList(
			const ListBrlyQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQUsrList(*(src.nodes[i]));
};

ListBrlyQUsrList::~ListBrlyQUsrList() {
	clear();
};

void ListBrlyQUsrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQUsrList::size() const {
	return(nodes.size());
};

void ListBrlyQUsrList::append(
			BrlyQUsrList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQUsrList& ListBrlyQUsrList::operator=(
			const ListBrlyQUsrList& src
		) {
	BrlyQUsrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQUsrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQUsrList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQUsrList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQUsrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQUsrList
 ******************************************************************************/

TblBrlyQUsrList::TblBrlyQUsrList() {
};

TblBrlyQUsrList::~TblBrlyQUsrList() {
};

bool TblBrlyQUsrList::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrList** rec
		) {
	return false;
};

ubigint TblBrlyQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	return 0;
};

ubigint TblBrlyQUsrList::insertRec(
			BrlyQUsrList* rec
		) {
	return 0;
};

ubigint TblBrlyQUsrList::insertNewRec(
			BrlyQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refBrlyMPerson
			, const string stubRefBrlyMPerson
			, const string sref
			, const ubigint refBrlyMUsergroup
			, const string stubRefBrlyMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixBrlyVLocale
			, const string srefIxBrlyVLocale
			, const string titIxBrlyVLocale
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	ubigint retval = 0;
	BrlyQUsrList* _rec = NULL;

	_rec = new BrlyQUsrList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, refBrlyMPerson, stubRefBrlyMPerson, sref, refBrlyMUsergroup, stubRefBrlyMUsergroup, ixVState, srefIxVState, titIxVState, ixBrlyVLocale, srefIxBrlyVLocale, titIxBrlyVLocale, ixBrlyVUserlevel, srefIxBrlyVUserlevel, titIxBrlyVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQUsrList::appendNewRecToRst(
			ListBrlyQUsrList& rst
			, BrlyQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refBrlyMPerson
			, const string stubRefBrlyMPerson
			, const string sref
			, const ubigint refBrlyMUsergroup
			, const string stubRefBrlyMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixBrlyVLocale
			, const string srefIxBrlyVLocale
			, const string titIxBrlyVLocale
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	ubigint retval = 0;
	BrlyQUsrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, refBrlyMPerson, stubRefBrlyMPerson, sref, refBrlyMUsergroup, stubRefBrlyMUsergroup, ixVState, srefIxVState, titIxVState, ixBrlyVLocale, srefIxBrlyVLocale, titIxBrlyVLocale, ixBrlyVUserlevel, srefIxBrlyVUserlevel, titIxBrlyVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQUsrList::insertRst(
			ListBrlyQUsrList& rst
		) {
};

void TblBrlyQUsrList::updateRec(
			BrlyQUsrList* rec
		) {
};

void TblBrlyQUsrList::updateRst(
			ListBrlyQUsrList& rst
		) {
};

void TblBrlyQUsrList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQUsrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQUsrList::loadRecByQref(
			ubigint qref
			, BrlyQUsrList** rec
		) {
	return false;
};

ubigint TblBrlyQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQUsrList
 ******************************************************************************/

MyTblBrlyQUsrList::MyTblBrlyQUsrList() :
			TblBrlyQUsrList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQUsrList::~MyTblBrlyQUsrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQUsrList (jref, jnum, ref, grp, own, refBrlyMPerson, sref, refBrlyMUsergroup, ixVState, ixBrlyVLocale, ixBrlyVUserlevel) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQUsrList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, refBrlyMPerson = ?, sref = ?, refBrlyMUsergroup = ?, ixVState = ?, ixBrlyVLocale = ?, ixBrlyVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQUsrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQUsrList WHERE jref = ?", false);
};

bool MyTblBrlyQUsrList::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQUsrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQUsrList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQUsrList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQUsrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->refBrlyMPerson = atoll((char*) dbrow[6]); else _rec->refBrlyMPerson = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->refBrlyMUsergroup = atoll((char*) dbrow[8]); else _rec->refBrlyMUsergroup = 0;
		if (dbrow[9]) _rec->ixVState = atol((char*) dbrow[9]); else _rec->ixVState = 0;
		if (dbrow[10]) _rec->ixBrlyVLocale = atol((char*) dbrow[10]); else _rec->ixBrlyVLocale = 0;
		if (dbrow[11]) _rec->ixBrlyVUserlevel = atol((char*) dbrow[11]); else _rec->ixBrlyVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQUsrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQUsrList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQUsrList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQUsrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->refBrlyMPerson = atoll((char*) dbrow[6]); else rec->refBrlyMPerson = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->refBrlyMUsergroup = atoll((char*) dbrow[8]); else rec->refBrlyMUsergroup = 0;
			if (dbrow[9]) rec->ixVState = atol((char*) dbrow[9]); else rec->ixVState = 0;
			if (dbrow[10]) rec->ixBrlyVLocale = atol((char*) dbrow[10]); else rec->ixBrlyVLocale = 0;
			if (dbrow[11]) rec->ixBrlyVUserlevel = atol((char*) dbrow[11]); else rec->ixBrlyVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQUsrList::insertRec(
			BrlyQUsrList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMPerson,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refBrlyMUsergroup,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixBrlyVLocale,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQUsrList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQUsrList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQUsrList::insertRst(
			ListBrlyQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQUsrList::updateRec(
			BrlyQUsrList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMPerson,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refBrlyMUsergroup,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixBrlyVLocale,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQUsrList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQUsrList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQUsrList::updateRst(
			ListBrlyQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQUsrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQUsrList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQUsrList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQUsrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQUsrList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQUsrList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQUsrList::loadRecByQref(
			ubigint qref
			, BrlyQUsrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQUsrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQUsrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQUsrList
 ******************************************************************************/

PgTblBrlyQUsrList::PgTblBrlyQUsrList() :
			TblBrlyQUsrList()
			, PgTable()
		{
};

PgTblBrlyQUsrList::~PgTblBrlyQUsrList() {
};

void PgTblBrlyQUsrList::initStatements() {
	createStatement("TblBrlyQUsrList_insertRec", "INSERT INTO TblBrlyQUsrList (jref, jnum, ref, grp, own, refBrlyMPerson, sref, refBrlyMUsergroup, ixVState, ixBrlyVLocale, ixBrlyVUserlevel) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblBrlyQUsrList_updateRec", "UPDATE TblBrlyQUsrList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, refBrlyMPerson = $6, sref = $7, refBrlyMUsergroup = $8, ixVState = $9, ixBrlyVLocale = $10, ixBrlyVUserlevel = $11 WHERE qref = $12", 12);
	createStatement("TblBrlyQUsrList_removeRecByQref", "DELETE FROM TblBrlyQUsrList WHERE qref = $1", 1);
	createStatement("TblBrlyQUsrList_removeRstByJref", "DELETE FROM TblBrlyQUsrList WHERE jref = $1", 1);

	createStatement("TblBrlyQUsrList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, refBrlyMPerson, sref, refBrlyMUsergroup, ixVState, ixBrlyVLocale, ixBrlyVUserlevel FROM TblBrlyQUsrList WHERE qref = $1", 1);
	createStatement("TblBrlyQUsrList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, refBrlyMPerson, sref, refBrlyMUsergroup, ixVState, ixBrlyVLocale, ixBrlyVUserlevel FROM TblBrlyQUsrList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQUsrList::loadRec(
			PGresult* res
			, BrlyQUsrList** rec
		) {
	char* ptr;

	BrlyQUsrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQUsrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refbrlymperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixbrlyvlocale"),
			PQfnumber(res, "ixbrlyvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refBrlyMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refBrlyMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixBrlyVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ixBrlyVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQUsrList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQUsrList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refbrlymperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixbrlyvlocale"),
			PQfnumber(res, "ixbrlyvuserlevel")
		};

		while (numread < numrow) {
			rec = new BrlyQUsrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refBrlyMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refBrlyMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixBrlyVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ixBrlyVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQUsrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQUsrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsrList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsrList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQUsrList::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQUsrList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQUsrList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQUsrList::insertRec(
			BrlyQUsrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refBrlyMPerson = htonl64(rec->refBrlyMPerson);
	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixBrlyVLocale = htonl(rec->ixBrlyVLocale);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refBrlyMPerson,
		rec->sref.c_str(),
		(char*) &_refBrlyMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixBrlyVLocale,
		(char*) &_ixBrlyVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsrList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsrList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQUsrList::insertRst(
			ListBrlyQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQUsrList::updateRec(
			BrlyQUsrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refBrlyMPerson = htonl64(rec->refBrlyMPerson);
	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixBrlyVLocale = htonl(rec->ixBrlyVLocale);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refBrlyMPerson,
		rec->sref.c_str(),
		(char*) &_refBrlyMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixBrlyVLocale,
		(char*) &_ixBrlyVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsrList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsrList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQUsrList::updateRst(
			ListBrlyQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQUsrList::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyQUsrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsrList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQUsrList::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyQUsrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsrList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQUsrList::loadRecByQref(
			ubigint qref
			, BrlyQUsrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQUsrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQUsrList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
