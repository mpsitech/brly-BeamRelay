/**
	* \file BrlyQRegADstswitch.cpp
	* Dbs and XML wrapper for table TblBrlyQRegADstswitch (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQRegADstswitch.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQRegADstswitch
 ******************************************************************************/

BrlyQRegADstswitch::BrlyQRegADstswitch(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint startd
			, const string ftmStartd
			, const uint startt
			, const string ftmStartt
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->startd = startd;
	this->ftmStartd = ftmStartd;
	this->startt = startt;
	this->ftmStartt = ftmStartt;
};

void BrlyQRegADstswitch::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQRegADstswitch";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "std", ftmStartd);
		writeString(wr, "stt", ftmStartt);
	} else {
		writeString(wr, "ftmStartd", ftmStartd);
		writeString(wr, "ftmStartt", ftmStartt);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQRegADstswitch
 ******************************************************************************/

ListBrlyQRegADstswitch::ListBrlyQRegADstswitch() {
};

ListBrlyQRegADstswitch::ListBrlyQRegADstswitch(
			const ListBrlyQRegADstswitch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQRegADstswitch(*(src.nodes[i]));
};

ListBrlyQRegADstswitch::~ListBrlyQRegADstswitch() {
	clear();
};

void ListBrlyQRegADstswitch::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQRegADstswitch::size() const {
	return(nodes.size());
};

void ListBrlyQRegADstswitch::append(
			BrlyQRegADstswitch* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQRegADstswitch& ListBrlyQRegADstswitch::operator=(
			const ListBrlyQRegADstswitch& src
		) {
	BrlyQRegADstswitch* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQRegADstswitch(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQRegADstswitch::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQRegADstswitch";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQRegADstswitch
 ******************************************************************************/

TblBrlyQRegADstswitch::TblBrlyQRegADstswitch() {
};

TblBrlyQRegADstswitch::~TblBrlyQRegADstswitch() {
};

bool TblBrlyQRegADstswitch::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegADstswitch** rec
		) {
	return false;
};

ubigint TblBrlyQRegADstswitch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegADstswitch& rst
		) {
	return 0;
};

ubigint TblBrlyQRegADstswitch::insertRec(
			BrlyQRegADstswitch* rec
		) {
	return 0;
};

ubigint TblBrlyQRegADstswitch::insertNewRec(
			BrlyQRegADstswitch** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint startd
			, const string ftmStartd
			, const uint startt
			, const string ftmStartt
		) {
	ubigint retval = 0;
	BrlyQRegADstswitch* _rec = NULL;

	_rec = new BrlyQRegADstswitch(0, jref, jnum, ref, startd, ftmStartd, startt, ftmStartt);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQRegADstswitch::appendNewRecToRst(
			ListBrlyQRegADstswitch& rst
			, BrlyQRegADstswitch** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint startd
			, const string ftmStartd
			, const uint startt
			, const string ftmStartt
		) {
	ubigint retval = 0;
	BrlyQRegADstswitch* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, startd, ftmStartd, startt, ftmStartt);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQRegADstswitch::insertRst(
			ListBrlyQRegADstswitch& rst
		) {
};

void TblBrlyQRegADstswitch::updateRec(
			BrlyQRegADstswitch* rec
		) {
};

void TblBrlyQRegADstswitch::updateRst(
			ListBrlyQRegADstswitch& rst
		) {
};

void TblBrlyQRegADstswitch::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQRegADstswitch::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQRegADstswitch::loadRecByQref(
			ubigint qref
			, BrlyQRegADstswitch** rec
		) {
	return false;
};

ubigint TblBrlyQRegADstswitch::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegADstswitch& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQRegADstswitch
 ******************************************************************************/

MyTblBrlyQRegADstswitch::MyTblBrlyQRegADstswitch() :
			TblBrlyQRegADstswitch()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQRegADstswitch::~MyTblBrlyQRegADstswitch() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQRegADstswitch::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQRegADstswitch (jref, jnum, ref, startd, startt) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQRegADstswitch SET jref = ?, jnum = ?, ref = ?, startd = ?, startt = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQRegADstswitch WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQRegADstswitch WHERE jref = ?", false);
};

bool MyTblBrlyQRegADstswitch::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegADstswitch** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQRegADstswitch* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQRegADstswitch::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQRegADstswitch::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQRegADstswitch();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->startd = atol((char*) dbrow[4]); else _rec->startd = 0;
		if (dbrow[5]) _rec->startt = atol((char*) dbrow[5]); else _rec->startt = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQRegADstswitch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegADstswitch& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQRegADstswitch* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQRegADstswitch::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQRegADstswitch::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQRegADstswitch();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->startd = atol((char*) dbrow[4]); else rec->startd = 0;
			if (dbrow[5]) rec->startt = atol((char*) dbrow[5]); else rec->startt = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQRegADstswitch::insertRec(
			BrlyQRegADstswitch* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->startd,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->startt,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQRegADstswitch::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQRegADstswitch::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQRegADstswitch::insertRst(
			ListBrlyQRegADstswitch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQRegADstswitch::updateRec(
			BrlyQRegADstswitch* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->startd,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->startt,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQRegADstswitch::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQRegADstswitch::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQRegADstswitch::updateRst(
			ListBrlyQRegADstswitch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQRegADstswitch::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQRegADstswitch::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQRegADstswitch::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQRegADstswitch::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQRegADstswitch::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQRegADstswitch::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQRegADstswitch::loadRecByQref(
			ubigint qref
			, BrlyQRegADstswitch** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQRegADstswitch WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQRegADstswitch::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegADstswitch& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQRegADstswitch WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQRegADstswitch
 ******************************************************************************/

PgTblBrlyQRegADstswitch::PgTblBrlyQRegADstswitch() :
			TblBrlyQRegADstswitch()
			, PgTable()
		{
};

PgTblBrlyQRegADstswitch::~PgTblBrlyQRegADstswitch() {
};

void PgTblBrlyQRegADstswitch::initStatements() {
	createStatement("TblBrlyQRegADstswitch_insertRec", "INSERT INTO TblBrlyQRegADstswitch (jref, jnum, ref, startd, startt) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblBrlyQRegADstswitch_updateRec", "UPDATE TblBrlyQRegADstswitch SET jref = $1, jnum = $2, ref = $3, startd = $4, startt = $5 WHERE qref = $6", 6);
	createStatement("TblBrlyQRegADstswitch_removeRecByQref", "DELETE FROM TblBrlyQRegADstswitch WHERE qref = $1", 1);
	createStatement("TblBrlyQRegADstswitch_removeRstByJref", "DELETE FROM TblBrlyQRegADstswitch WHERE jref = $1", 1);

	createStatement("TblBrlyQRegADstswitch_loadRecByQref", "SELECT qref, jref, jnum, ref, startd, startt FROM TblBrlyQRegADstswitch WHERE qref = $1", 1);
	createStatement("TblBrlyQRegADstswitch_loadRstByJref", "SELECT qref, jref, jnum, ref, startd, startt FROM TblBrlyQRegADstswitch WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQRegADstswitch::loadRec(
			PGresult* res
			, BrlyQRegADstswitch** rec
		) {
	char* ptr;

	BrlyQRegADstswitch* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQRegADstswitch();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->startt = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQRegADstswitch::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQRegADstswitch& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQRegADstswitch* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt")
		};

		while (numread < numrow) {
			rec = new BrlyQRegADstswitch();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->startt = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQRegADstswitch::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQRegADstswitch** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQRegADstswitch::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQRegADstswitch::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQRegADstswitch& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQRegADstswitch::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQRegADstswitch::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegADstswitch** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQRegADstswitch::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQRegADstswitch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegADstswitch& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQRegADstswitch::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQRegADstswitch::insertRec(
			BrlyQRegADstswitch* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_startd,
		(char*) &_startt
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQRegADstswitch_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQRegADstswitch::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQRegADstswitch::insertRst(
			ListBrlyQRegADstswitch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQRegADstswitch::updateRec(
			BrlyQRegADstswitch* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_startd,
		(char*) &_startt,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQRegADstswitch_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQRegADstswitch::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQRegADstswitch::updateRst(
			ListBrlyQRegADstswitch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQRegADstswitch::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQRegADstswitch_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQRegADstswitch::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQRegADstswitch::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQRegADstswitch_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQRegADstswitch::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQRegADstswitch::loadRecByQref(
			ubigint qref
			, BrlyQRegADstswitch** rec
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

	return loadRecByStmt("TblBrlyQRegADstswitch_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQRegADstswitch::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegADstswitch& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQRegADstswitch_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
