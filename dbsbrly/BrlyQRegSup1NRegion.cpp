/**
	* \file BrlyQRegSup1NRegion.cpp
	* Dbs and XML wrapper for table TblBrlyQRegSup1NRegion (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQRegSup1NRegion.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQRegSup1NRegion
 ******************************************************************************/

BrlyQRegSup1NRegion::BrlyQRegSup1NRegion(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void BrlyQRegSup1NRegion::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQRegSup1NRegion";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQRegSup1NRegion
 ******************************************************************************/

ListBrlyQRegSup1NRegion::ListBrlyQRegSup1NRegion() {
};

ListBrlyQRegSup1NRegion::ListBrlyQRegSup1NRegion(
			const ListBrlyQRegSup1NRegion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQRegSup1NRegion(*(src.nodes[i]));
};

ListBrlyQRegSup1NRegion::~ListBrlyQRegSup1NRegion() {
	clear();
};

void ListBrlyQRegSup1NRegion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQRegSup1NRegion::size() const {
	return(nodes.size());
};

void ListBrlyQRegSup1NRegion::append(
			BrlyQRegSup1NRegion* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQRegSup1NRegion& ListBrlyQRegSup1NRegion::operator=(
			const ListBrlyQRegSup1NRegion& src
		) {
	BrlyQRegSup1NRegion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQRegSup1NRegion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQRegSup1NRegion::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQRegSup1NRegion";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQRegSup1NRegion
 ******************************************************************************/

TblBrlyQRegSup1NRegion::TblBrlyQRegSup1NRegion() {
};

TblBrlyQRegSup1NRegion::~TblBrlyQRegSup1NRegion() {
};

bool TblBrlyQRegSup1NRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegSup1NRegion** rec
		) {
	return false;
};

ubigint TblBrlyQRegSup1NRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	return 0;
};

ubigint TblBrlyQRegSup1NRegion::insertRec(
			BrlyQRegSup1NRegion* rec
		) {
	return 0;
};

ubigint TblBrlyQRegSup1NRegion::insertNewRec(
			BrlyQRegSup1NRegion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQRegSup1NRegion* _rec = NULL;

	_rec = new BrlyQRegSup1NRegion(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQRegSup1NRegion::appendNewRecToRst(
			ListBrlyQRegSup1NRegion& rst
			, BrlyQRegSup1NRegion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQRegSup1NRegion* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQRegSup1NRegion::insertRst(
			ListBrlyQRegSup1NRegion& rst
		) {
};

void TblBrlyQRegSup1NRegion::updateRec(
			BrlyQRegSup1NRegion* rec
		) {
};

void TblBrlyQRegSup1NRegion::updateRst(
			ListBrlyQRegSup1NRegion& rst
		) {
};

void TblBrlyQRegSup1NRegion::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQRegSup1NRegion::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQRegSup1NRegion::loadRecByQref(
			ubigint qref
			, BrlyQRegSup1NRegion** rec
		) {
	return false;
};

ubigint TblBrlyQRegSup1NRegion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQRegSup1NRegion
 ******************************************************************************/

MyTblBrlyQRegSup1NRegion::MyTblBrlyQRegSup1NRegion() :
			TblBrlyQRegSup1NRegion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQRegSup1NRegion::~MyTblBrlyQRegSup1NRegion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQRegSup1NRegion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQRegSup1NRegion (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQRegSup1NRegion SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQRegSup1NRegion WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQRegSup1NRegion WHERE jref = ?", false);
};

bool MyTblBrlyQRegSup1NRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegSup1NRegion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQRegSup1NRegion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQRegSup1NRegion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQRegSup1NRegion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQRegSup1NRegion();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQRegSup1NRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQRegSup1NRegion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQRegSup1NRegion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQRegSup1NRegion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQRegSup1NRegion();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQRegSup1NRegion::insertRec(
			BrlyQRegSup1NRegion* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQRegSup1NRegion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQRegSup1NRegion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQRegSup1NRegion::insertRst(
			ListBrlyQRegSup1NRegion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQRegSup1NRegion::updateRec(
			BrlyQRegSup1NRegion* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQRegSup1NRegion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQRegSup1NRegion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQRegSup1NRegion::updateRst(
			ListBrlyQRegSup1NRegion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQRegSup1NRegion::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQRegSup1NRegion::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQRegSup1NRegion::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQRegSup1NRegion::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQRegSup1NRegion::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQRegSup1NRegion::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQRegSup1NRegion::loadRecByQref(
			ubigint qref
			, BrlyQRegSup1NRegion** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQRegSup1NRegion WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQRegSup1NRegion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQRegSup1NRegion WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQRegSup1NRegion
 ******************************************************************************/

PgTblBrlyQRegSup1NRegion::PgTblBrlyQRegSup1NRegion() :
			TblBrlyQRegSup1NRegion()
			, PgTable()
		{
};

PgTblBrlyQRegSup1NRegion::~PgTblBrlyQRegSup1NRegion() {
};

void PgTblBrlyQRegSup1NRegion::initStatements() {
	createStatement("TblBrlyQRegSup1NRegion_insertRec", "INSERT INTO TblBrlyQRegSup1NRegion (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblBrlyQRegSup1NRegion_updateRec", "UPDATE TblBrlyQRegSup1NRegion SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblBrlyQRegSup1NRegion_removeRecByQref", "DELETE FROM TblBrlyQRegSup1NRegion WHERE qref = $1", 1);
	createStatement("TblBrlyQRegSup1NRegion_removeRstByJref", "DELETE FROM TblBrlyQRegSup1NRegion WHERE jref = $1", 1);

	createStatement("TblBrlyQRegSup1NRegion_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblBrlyQRegSup1NRegion WHERE qref = $1", 1);
	createStatement("TblBrlyQRegSup1NRegion_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblBrlyQRegSup1NRegion WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQRegSup1NRegion::loadRec(
			PGresult* res
			, BrlyQRegSup1NRegion** rec
		) {
	char* ptr;

	BrlyQRegSup1NRegion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQRegSup1NRegion();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQRegSup1NRegion::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQRegSup1NRegion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new BrlyQRegSup1NRegion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQRegSup1NRegion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQRegSup1NRegion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQRegSup1NRegion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQRegSup1NRegion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQRegSup1NRegion::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQRegSup1NRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegSup1NRegion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQRegSup1NRegion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQRegSup1NRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQRegSup1NRegion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQRegSup1NRegion::insertRec(
			BrlyQRegSup1NRegion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQRegSup1NRegion_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQRegSup1NRegion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQRegSup1NRegion::insertRst(
			ListBrlyQRegSup1NRegion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQRegSup1NRegion::updateRec(
			BrlyQRegSup1NRegion* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQRegSup1NRegion_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQRegSup1NRegion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQRegSup1NRegion::updateRst(
			ListBrlyQRegSup1NRegion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQRegSup1NRegion::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQRegSup1NRegion_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQRegSup1NRegion::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQRegSup1NRegion::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQRegSup1NRegion_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQRegSup1NRegion::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQRegSup1NRegion::loadRecByQref(
			ubigint qref
			, BrlyQRegSup1NRegion** rec
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

	return loadRecByStmt("TblBrlyQRegSup1NRegion_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQRegSup1NRegion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQRegSup1NRegion_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
