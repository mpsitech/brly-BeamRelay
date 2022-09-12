/**
	* \file BrlyQSegList.cpp
	* Dbs and XML wrapper for table TblBrlyQSegList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQSegList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQSegList
 ******************************************************************************/

BrlyQSegList::BrlyQSegList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const double alt0
			, const double alt1
			, const double theta0
			, const double theta1
			, const double phi0
			, const double phi1
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
	this->alt0 = alt0;
	this->alt1 = alt1;
	this->theta0 = theta0;
	this->theta1 = theta1;
	this->phi0 = phi0;
	this->phi1 = phi1;
	this->start = start;
	this->ftmStart = ftmStart;
	this->stop = stop;
	this->ftmStop = ftmStop;
};

void BrlyQSegList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["ret"] = srefRefIxVTbl;
		me["ret2"] = titRefIxVTbl;
		me["reu"] = stubRefUref;
		me["al0"] = alt0;
		me["al1"] = alt1;
		me["th0"] = theta0;
		me["th1"] = theta1;
		me["ph0"] = phi0;
		me["ph1"] = phi1;
		me["sta"] = ftmStart;
		me["sto"] = ftmStop;
	} else {
		me["srefRefIxVTbl"] = srefRefIxVTbl;
		me["titRefIxVTbl"] = titRefIxVTbl;
		me["stubRefUref"] = stubRefUref;
		me["alt0"] = alt0;
		me["alt1"] = alt1;
		me["theta0"] = theta0;
		me["theta1"] = theta1;
		me["phi0"] = phi0;
		me["phi1"] = phi1;
		me["ftmStart"] = ftmStart;
		me["ftmStop"] = ftmStop;
	};
};

void BrlyQSegList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQSegList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeDouble(wr, "al0", alt0);
		writeDouble(wr, "al1", alt1);
		writeDouble(wr, "th0", theta0);
		writeDouble(wr, "th1", theta1);
		writeDouble(wr, "ph0", phi0);
		writeDouble(wr, "ph1", phi1);
		writeString(wr, "sta", ftmStart);
		writeString(wr, "sto", ftmStop);
	} else {
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeDouble(wr, "alt0", alt0);
		writeDouble(wr, "alt1", alt1);
		writeDouble(wr, "theta0", theta0);
		writeDouble(wr, "theta1", theta1);
		writeDouble(wr, "phi0", phi0);
		writeDouble(wr, "phi1", phi1);
		writeString(wr, "ftmStart", ftmStart);
		writeString(wr, "ftmStop", ftmStop);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQSegList
 ******************************************************************************/

ListBrlyQSegList::ListBrlyQSegList() {
};

ListBrlyQSegList::ListBrlyQSegList(
			const ListBrlyQSegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQSegList(*(src.nodes[i]));
};

ListBrlyQSegList::~ListBrlyQSegList() {
	clear();
};

void ListBrlyQSegList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQSegList::size() const {
	return(nodes.size());
};

void ListBrlyQSegList::append(
			BrlyQSegList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQSegList& ListBrlyQSegList::operator=(
			const ListBrlyQSegList& src
		) {
	BrlyQSegList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQSegList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQSegList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQSegList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQSegList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQSegList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQSegList
 ******************************************************************************/

TblBrlyQSegList::TblBrlyQSegList() {
};

TblBrlyQSegList::~TblBrlyQSegList() {
};

bool TblBrlyQSegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegList** rec
		) {
	return false;
};

ubigint TblBrlyQSegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegList& rst
		) {
	return 0;
};

ubigint TblBrlyQSegList::insertRec(
			BrlyQSegList* rec
		) {
	return 0;
};

ubigint TblBrlyQSegList::insertNewRec(
			BrlyQSegList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const double alt0
			, const double alt1
			, const double theta0
			, const double theta1
			, const double phi0
			, const double phi1
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	ubigint retval = 0;
	BrlyQSegList* _rec = NULL;

	_rec = new BrlyQSegList(0, jref, jnum, ref, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, alt0, alt1, theta0, theta1, phi0, phi1, start, ftmStart, stop, ftmStop);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQSegList::appendNewRecToRst(
			ListBrlyQSegList& rst
			, BrlyQSegList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const double alt0
			, const double alt1
			, const double theta0
			, const double theta1
			, const double phi0
			, const double phi1
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	ubigint retval = 0;
	BrlyQSegList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, alt0, alt1, theta0, theta1, phi0, phi1, start, ftmStart, stop, ftmStop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQSegList::insertRst(
			ListBrlyQSegList& rst
		) {
};

void TblBrlyQSegList::updateRec(
			BrlyQSegList* rec
		) {
};

void TblBrlyQSegList::updateRst(
			ListBrlyQSegList& rst
		) {
};

void TblBrlyQSegList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQSegList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQSegList::loadRecByQref(
			ubigint qref
			, BrlyQSegList** rec
		) {
	return false;
};

ubigint TblBrlyQSegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQSegList
 ******************************************************************************/

MyTblBrlyQSegList::MyTblBrlyQSegList() :
			TblBrlyQSegList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQSegList::~MyTblBrlyQSegList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQSegList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQSegList (jref, jnum, ref, refIxVTbl, refUref, alt0, alt1, theta0, theta1, phi0, phi1, start, stop) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQSegList SET jref = ?, jnum = ?, ref = ?, refIxVTbl = ?, refUref = ?, alt0 = ?, alt1 = ?, theta0 = ?, theta1 = ?, phi0 = ?, phi1 = ?, start = ?, stop = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQSegList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQSegList WHERE jref = ?", false);
};

bool MyTblBrlyQSegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQSegList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQSegList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQSegList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQSegList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refIxVTbl = atol((char*) dbrow[4]); else _rec->refIxVTbl = 0;
		if (dbrow[5]) _rec->refUref = atoll((char*) dbrow[5]); else _rec->refUref = 0;
		if (dbrow[6]) _rec->alt0 = atof((char*) dbrow[6]); else _rec->alt0 = 0.0;
		if (dbrow[7]) _rec->alt1 = atof((char*) dbrow[7]); else _rec->alt1 = 0.0;
		if (dbrow[8]) _rec->theta0 = atof((char*) dbrow[8]); else _rec->theta0 = 0.0;
		if (dbrow[9]) _rec->theta1 = atof((char*) dbrow[9]); else _rec->theta1 = 0.0;
		if (dbrow[10]) _rec->phi0 = atof((char*) dbrow[10]); else _rec->phi0 = 0.0;
		if (dbrow[11]) _rec->phi1 = atof((char*) dbrow[11]); else _rec->phi1 = 0.0;
		if (dbrow[12]) _rec->start = atol((char*) dbrow[12]); else _rec->start = 0;
		if (dbrow[13]) _rec->stop = atol((char*) dbrow[13]); else _rec->stop = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQSegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQSegList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQSegList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQSegList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQSegList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refIxVTbl = atol((char*) dbrow[4]); else rec->refIxVTbl = 0;
			if (dbrow[5]) rec->refUref = atoll((char*) dbrow[5]); else rec->refUref = 0;
			if (dbrow[6]) rec->alt0 = atof((char*) dbrow[6]); else rec->alt0 = 0.0;
			if (dbrow[7]) rec->alt1 = atof((char*) dbrow[7]); else rec->alt1 = 0.0;
			if (dbrow[8]) rec->theta0 = atof((char*) dbrow[8]); else rec->theta0 = 0.0;
			if (dbrow[9]) rec->theta1 = atof((char*) dbrow[9]); else rec->theta1 = 0.0;
			if (dbrow[10]) rec->phi0 = atof((char*) dbrow[10]); else rec->phi0 = 0.0;
			if (dbrow[11]) rec->phi1 = atof((char*) dbrow[11]); else rec->phi1 = 0.0;
			if (dbrow[12]) rec->start = atol((char*) dbrow[12]); else rec->start = 0;
			if (dbrow[13]) rec->stop = atol((char*) dbrow[13]); else rec->stop = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQSegList::insertRec(
			BrlyQSegList* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->alt0,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->alt1,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->theta0,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->theta1,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->phi0,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->phi1,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->start,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->stop,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQSegList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQSegList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQSegList::insertRst(
			ListBrlyQSegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQSegList::updateRec(
			BrlyQSegList* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->alt0,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->alt1,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->theta0,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->theta1,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->phi0,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->phi1,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->start,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->stop,&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->qref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQSegList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQSegList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQSegList::updateRst(
			ListBrlyQSegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQSegList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQSegList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQSegList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQSegList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQSegList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQSegList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQSegList::loadRecByQref(
			ubigint qref
			, BrlyQSegList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQSegList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQSegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQSegList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQSegList
 ******************************************************************************/

PgTblBrlyQSegList::PgTblBrlyQSegList() :
			TblBrlyQSegList()
			, PgTable()
		{
};

PgTblBrlyQSegList::~PgTblBrlyQSegList() {
};

void PgTblBrlyQSegList::initStatements() {
	createStatement("TblBrlyQSegList_insertRec", "INSERT INTO TblBrlyQSegList (jref, jnum, ref, refIxVTbl, refUref, alt0, alt1, theta0, theta1, phi0, phi1, start, stop) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING qref", 13);
	createStatement("TblBrlyQSegList_updateRec", "UPDATE TblBrlyQSegList SET jref = $1, jnum = $2, ref = $3, refIxVTbl = $4, refUref = $5, alt0 = $6, alt1 = $7, theta0 = $8, theta1 = $9, phi0 = $10, phi1 = $11, start = $12, stop = $13 WHERE qref = $14", 14);
	createStatement("TblBrlyQSegList_removeRecByQref", "DELETE FROM TblBrlyQSegList WHERE qref = $1", 1);
	createStatement("TblBrlyQSegList_removeRstByJref", "DELETE FROM TblBrlyQSegList WHERE jref = $1", 1);

	createStatement("TblBrlyQSegList_loadRecByQref", "SELECT qref, jref, jnum, ref, refIxVTbl, refUref, alt0, alt1, theta0, theta1, phi0, phi1, start, stop FROM TblBrlyQSegList WHERE qref = $1", 1);
	createStatement("TblBrlyQSegList_loadRstByJref", "SELECT qref, jref, jnum, ref, refIxVTbl, refUref, alt0, alt1, theta0, theta1, phi0, phi1, start, stop FROM TblBrlyQSegList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQSegList::loadRec(
			PGresult* res
			, BrlyQSegList** rec
		) {
	char* ptr;

	BrlyQSegList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQSegList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "alt0"),
			PQfnumber(res, "alt1"),
			PQfnumber(res, "theta0"),
			PQfnumber(res, "theta1"),
			PQfnumber(res, "phi0"),
			PQfnumber(res, "phi1"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->alt0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->alt1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->theta0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->theta1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->phi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->phi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->stop = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQSegList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQSegList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQSegList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "alt0"),
			PQfnumber(res, "alt1"),
			PQfnumber(res, "theta0"),
			PQfnumber(res, "theta1"),
			PQfnumber(res, "phi0"),
			PQfnumber(res, "phi1"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop")
		};

		while (numread < numrow) {
			rec = new BrlyQSegList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->alt0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->alt1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->theta0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->theta1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->phi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->phi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->stop = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQSegList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQSegList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQSegList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQSegList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQSegList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQSegList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQSegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQSegList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQSegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQSegList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQSegList::insertRec(
			BrlyQSegList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	string _alt0 = to_string(rec->alt0);
	string _alt1 = to_string(rec->alt1);
	string _theta0 = to_string(rec->theta0);
	string _theta1 = to_string(rec->theta1);
	string _phi0 = to_string(rec->phi0);
	string _phi1 = to_string(rec->phi1);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		_alt0.c_str(),
		_alt1.c_str(),
		_theta0.c_str(),
		_theta1.c_str(),
		_phi0.c_str(),
		_phi1.c_str(),
		(char*) &_start,
		(char*) &_stop
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQSegList_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQSegList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQSegList::insertRst(
			ListBrlyQSegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQSegList::updateRec(
			BrlyQSegList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	string _alt0 = to_string(rec->alt0);
	string _alt1 = to_string(rec->alt1);
	string _theta0 = to_string(rec->theta0);
	string _theta1 = to_string(rec->theta1);
	string _phi0 = to_string(rec->phi0);
	string _phi1 = to_string(rec->phi1);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		_alt0.c_str(),
		_alt1.c_str(),
		_theta0.c_str(),
		_theta1.c_str(),
		_phi0.c_str(),
		_phi1.c_str(),
		(char*) &_start,
		(char*) &_stop,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQSegList_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQSegList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQSegList::updateRst(
			ListBrlyQSegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQSegList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQSegList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQSegList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQSegList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQSegList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQSegList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQSegList::loadRecByQref(
			ubigint qref
			, BrlyQSegList** rec
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

	return loadRecByStmt("TblBrlyQSegList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQSegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQSegList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
