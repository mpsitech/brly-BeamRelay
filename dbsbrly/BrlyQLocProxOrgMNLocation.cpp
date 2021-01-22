/**
	* \file BrlyQLocProxOrgMNLocation.cpp
	* Dbs and XML wrapper for table TblBrlyQLocProxOrgMNLocation (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQLocProxOrgMNLocation.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQLocProxOrgMNLocation
 ******************************************************************************/

BrlyQLocProxOrgMNLocation::BrlyQLocProxOrgMNLocation(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double deltaphi
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->deltaphi = deltaphi;
};

void BrlyQLocProxOrgMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLocProxOrgMNLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeDouble(wr, "dph", deltaphi);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeDouble(wr, "deltaphi", deltaphi);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLocProxOrgMNLocation
 ******************************************************************************/

ListBrlyQLocProxOrgMNLocation::ListBrlyQLocProxOrgMNLocation() {
};

ListBrlyQLocProxOrgMNLocation::ListBrlyQLocProxOrgMNLocation(
			const ListBrlyQLocProxOrgMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQLocProxOrgMNLocation(*(src.nodes[i]));
};

ListBrlyQLocProxOrgMNLocation::~ListBrlyQLocProxOrgMNLocation() {
	clear();
};

void ListBrlyQLocProxOrgMNLocation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLocProxOrgMNLocation::size() const {
	return(nodes.size());
};

void ListBrlyQLocProxOrgMNLocation::append(
			BrlyQLocProxOrgMNLocation* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLocProxOrgMNLocation& ListBrlyQLocProxOrgMNLocation::operator=(
			const ListBrlyQLocProxOrgMNLocation& src
		) {
	BrlyQLocProxOrgMNLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQLocProxOrgMNLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLocProxOrgMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLocProxOrgMNLocation";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLocProxOrgMNLocation
 ******************************************************************************/

TblBrlyQLocProxOrgMNLocation::TblBrlyQLocProxOrgMNLocation() {
};

TblBrlyQLocProxOrgMNLocation::~TblBrlyQLocProxOrgMNLocation() {
};

bool TblBrlyQLocProxOrgMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocProxOrgMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLocProxOrgMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	return 0;
};

ubigint TblBrlyQLocProxOrgMNLocation::insertRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
	return 0;
};

ubigint TblBrlyQLocProxOrgMNLocation::insertNewRec(
			BrlyQLocProxOrgMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double deltaphi
		) {
	ubigint retval = 0;
	BrlyQLocProxOrgMNLocation* _rec = NULL;

	_rec = new BrlyQLocProxOrgMNLocation(0, jref, jnum, mref, stubMref, ref, deltaphi);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLocProxOrgMNLocation::appendNewRecToRst(
			ListBrlyQLocProxOrgMNLocation& rst
			, BrlyQLocProxOrgMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double deltaphi
		) {
	ubigint retval = 0;
	BrlyQLocProxOrgMNLocation* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, deltaphi);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLocProxOrgMNLocation::insertRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
};

void TblBrlyQLocProxOrgMNLocation::updateRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
};

void TblBrlyQLocProxOrgMNLocation::updateRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
};

void TblBrlyQLocProxOrgMNLocation::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLocProxOrgMNLocation::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLocProxOrgMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocProxOrgMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLocProxOrgMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQLocProxOrgMNLocation
 ******************************************************************************/

MyTblBrlyQLocProxOrgMNLocation::MyTblBrlyQLocProxOrgMNLocation() :
			TblBrlyQLocProxOrgMNLocation()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLocProxOrgMNLocation::~MyTblBrlyQLocProxOrgMNLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLocProxOrgMNLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLocProxOrgMNLocation (jref, jnum, mref, ref, deltaphi) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLocProxOrgMNLocation SET jref = ?, jnum = ?, mref = ?, ref = ?, deltaphi = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLocProxOrgMNLocation WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLocProxOrgMNLocation WHERE jref = ?", false);
};

bool MyTblBrlyQLocProxOrgMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocProxOrgMNLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLocProxOrgMNLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLocProxOrgMNLocation();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->deltaphi = atof((char*) dbrow[5]); else _rec->deltaphi = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLocProxOrgMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLocProxOrgMNLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLocProxOrgMNLocation();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->deltaphi = atof((char*) dbrow[5]); else rec->deltaphi = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQLocProxOrgMNLocation::insertRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->deltaphi,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQLocProxOrgMNLocation::insertRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLocProxOrgMNLocation::updateRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->deltaphi,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLocProxOrgMNLocation::updateRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLocProxOrgMNLocation::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLocProxOrgMNLocation::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQLocProxOrgMNLocation::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQLocProxOrgMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocProxOrgMNLocation** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQLocProxOrgMNLocation WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLocProxOrgMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLocProxOrgMNLocation WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQLocProxOrgMNLocation
 ******************************************************************************/

PgTblBrlyQLocProxOrgMNLocation::PgTblBrlyQLocProxOrgMNLocation() :
			TblBrlyQLocProxOrgMNLocation()
			, PgTable()
		{
};

PgTblBrlyQLocProxOrgMNLocation::~PgTblBrlyQLocProxOrgMNLocation() {
};

void PgTblBrlyQLocProxOrgMNLocation::initStatements() {
	createStatement("TblBrlyQLocProxOrgMNLocation_insertRec", "INSERT INTO TblBrlyQLocProxOrgMNLocation (jref, jnum, mref, ref, deltaphi) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblBrlyQLocProxOrgMNLocation_updateRec", "UPDATE TblBrlyQLocProxOrgMNLocation SET jref = $1, jnum = $2, mref = $3, ref = $4, deltaphi = $5 WHERE qref = $6", 6);
	createStatement("TblBrlyQLocProxOrgMNLocation_removeRecByQref", "DELETE FROM TblBrlyQLocProxOrgMNLocation WHERE qref = $1", 1);
	createStatement("TblBrlyQLocProxOrgMNLocation_removeRstByJref", "DELETE FROM TblBrlyQLocProxOrgMNLocation WHERE jref = $1", 1);

	createStatement("TblBrlyQLocProxOrgMNLocation_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, deltaphi FROM TblBrlyQLocProxOrgMNLocation WHERE qref = $1", 1);
	createStatement("TblBrlyQLocProxOrgMNLocation_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, deltaphi FROM TblBrlyQLocProxOrgMNLocation WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQLocProxOrgMNLocation::loadRec(
			PGresult* res
			, BrlyQLocProxOrgMNLocation** rec
		) {
	char* ptr;

	BrlyQLocProxOrgMNLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLocProxOrgMNLocation();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "deltaphi")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->deltaphi = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLocProxOrgMNLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLocProxOrgMNLocation* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "deltaphi")
		};

		while (numread < numrow) {
			rec = new BrlyQLocProxOrgMNLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->deltaphi = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLocProxOrgMNLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLocProxOrgMNLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocProxOrgMNLocation::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocProxOrgMNLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocProxOrgMNLocation::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLocProxOrgMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocProxOrgMNLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLocProxOrgMNLocation::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocProxOrgMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLocProxOrgMNLocation::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQLocProxOrgMNLocation::insertRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	string _deltaphi = to_string(rec->deltaphi);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		_deltaphi.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLocProxOrgMNLocation_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocProxOrgMNLocation::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQLocProxOrgMNLocation::insertRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLocProxOrgMNLocation::updateRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	string _deltaphi = to_string(rec->deltaphi);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		_deltaphi.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLocProxOrgMNLocation_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocProxOrgMNLocation::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLocProxOrgMNLocation::updateRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLocProxOrgMNLocation::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocProxOrgMNLocation_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocProxOrgMNLocation::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLocProxOrgMNLocation::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocProxOrgMNLocation_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocProxOrgMNLocation::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQLocProxOrgMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocProxOrgMNLocation** rec
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

	return loadRecByStmt("TblBrlyQLocProxOrgMNLocation_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLocProxOrgMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLocProxOrgMNLocation_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
