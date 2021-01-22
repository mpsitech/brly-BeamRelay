/**
	* \file BrlyQUsgMNUser.cpp
	* Dbs and XML wrapper for table TblBrlyQUsgMNUser (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQUsgMNUser.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQUsgMNUser
 ******************************************************************************/

BrlyQUsgMNUser::BrlyQUsgMNUser(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->ixBrlyVUserlevel = ixBrlyVUserlevel;
	this->srefIxBrlyVUserlevel = srefIxBrlyVUserlevel;
	this->titIxBrlyVUserlevel = titIxBrlyVUserlevel;
};

void BrlyQUsgMNUser::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQUsgMNUser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "ulv", srefIxBrlyVUserlevel);
		writeString(wr, "ulv2", titIxBrlyVUserlevel);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefIxBrlyVUserlevel", srefIxBrlyVUserlevel);
		writeString(wr, "titIxBrlyVUserlevel", titIxBrlyVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQUsgMNUser
 ******************************************************************************/

ListBrlyQUsgMNUser::ListBrlyQUsgMNUser() {
};

ListBrlyQUsgMNUser::ListBrlyQUsgMNUser(
			const ListBrlyQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQUsgMNUser(*(src.nodes[i]));
};

ListBrlyQUsgMNUser::~ListBrlyQUsgMNUser() {
	clear();
};

void ListBrlyQUsgMNUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQUsgMNUser::size() const {
	return(nodes.size());
};

void ListBrlyQUsgMNUser::append(
			BrlyQUsgMNUser* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQUsgMNUser& ListBrlyQUsgMNUser::operator=(
			const ListBrlyQUsgMNUser& src
		) {
	BrlyQUsgMNUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQUsgMNUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQUsgMNUser::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQUsgMNUser";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQUsgMNUser
 ******************************************************************************/

TblBrlyQUsgMNUser::TblBrlyQUsgMNUser() {
};

TblBrlyQUsgMNUser::~TblBrlyQUsgMNUser() {
};

bool TblBrlyQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgMNUser** rec
		) {
	return false;
};

ubigint TblBrlyQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgMNUser& rst
		) {
	return 0;
};

ubigint TblBrlyQUsgMNUser::insertRec(
			BrlyQUsgMNUser* rec
		) {
	return 0;
};

ubigint TblBrlyQUsgMNUser::insertNewRec(
			BrlyQUsgMNUser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	ubigint retval = 0;
	BrlyQUsgMNUser* _rec = NULL;

	_rec = new BrlyQUsgMNUser(0, jref, jnum, mref, stubMref, ref, ixBrlyVUserlevel, srefIxBrlyVUserlevel, titIxBrlyVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQUsgMNUser::appendNewRecToRst(
			ListBrlyQUsgMNUser& rst
			, BrlyQUsgMNUser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	ubigint retval = 0;
	BrlyQUsgMNUser* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixBrlyVUserlevel, srefIxBrlyVUserlevel, titIxBrlyVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQUsgMNUser::insertRst(
			ListBrlyQUsgMNUser& rst
		) {
};

void TblBrlyQUsgMNUser::updateRec(
			BrlyQUsgMNUser* rec
		) {
};

void TblBrlyQUsgMNUser::updateRst(
			ListBrlyQUsgMNUser& rst
		) {
};

void TblBrlyQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQUsgMNUser::loadRecByQref(
			ubigint qref
			, BrlyQUsgMNUser** rec
		) {
	return false;
};

ubigint TblBrlyQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgMNUser& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQUsgMNUser
 ******************************************************************************/

MyTblBrlyQUsgMNUser::MyTblBrlyQUsgMNUser() :
			TblBrlyQUsgMNUser()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQUsgMNUser::~MyTblBrlyQUsgMNUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQUsgMNUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQUsgMNUser (jref, jnum, mref, ref, ixBrlyVUserlevel) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQUsgMNUser SET jref = ?, jnum = ?, mref = ?, ref = ?, ixBrlyVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQUsgMNUser WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQUsgMNUser WHERE jref = ?", false);
};

bool MyTblBrlyQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgMNUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQUsgMNUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQUsgMNUser::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQUsgMNUser::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQUsgMNUser();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixBrlyVUserlevel = atol((char*) dbrow[5]); else _rec->ixBrlyVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgMNUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQUsgMNUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQUsgMNUser::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQUsgMNUser::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQUsgMNUser();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixBrlyVUserlevel = atol((char*) dbrow[5]); else rec->ixBrlyVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQUsgMNUser::insertRec(
			BrlyQUsgMNUser* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQUsgMNUser::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQUsgMNUser::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQUsgMNUser::insertRst(
			ListBrlyQUsgMNUser& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQUsgMNUser::updateRec(
			BrlyQUsgMNUser* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQUsgMNUser::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQUsgMNUser::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQUsgMNUser::updateRst(
			ListBrlyQUsgMNUser& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQUsgMNUser::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQUsgMNUser::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQUsgMNUser::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQUsgMNUser::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQUsgMNUser::loadRecByQref(
			ubigint qref
			, BrlyQUsgMNUser** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQUsgMNUser WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgMNUser& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQUsgMNUser WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQUsgMNUser
 ******************************************************************************/

PgTblBrlyQUsgMNUser::PgTblBrlyQUsgMNUser() :
			TblBrlyQUsgMNUser()
			, PgTable()
		{
};

PgTblBrlyQUsgMNUser::~PgTblBrlyQUsgMNUser() {
};

void PgTblBrlyQUsgMNUser::initStatements() {
	createStatement("TblBrlyQUsgMNUser_insertRec", "INSERT INTO TblBrlyQUsgMNUser (jref, jnum, mref, ref, ixBrlyVUserlevel) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblBrlyQUsgMNUser_updateRec", "UPDATE TblBrlyQUsgMNUser SET jref = $1, jnum = $2, mref = $3, ref = $4, ixBrlyVUserlevel = $5 WHERE qref = $6", 6);
	createStatement("TblBrlyQUsgMNUser_removeRecByQref", "DELETE FROM TblBrlyQUsgMNUser WHERE qref = $1", 1);
	createStatement("TblBrlyQUsgMNUser_removeRstByJref", "DELETE FROM TblBrlyQUsgMNUser WHERE jref = $1", 1);

	createStatement("TblBrlyQUsgMNUser_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixBrlyVUserlevel FROM TblBrlyQUsgMNUser WHERE qref = $1", 1);
	createStatement("TblBrlyQUsgMNUser_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixBrlyVUserlevel FROM TblBrlyQUsgMNUser WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQUsgMNUser::loadRec(
			PGresult* res
			, BrlyQUsgMNUser** rec
		) {
	char* ptr;

	BrlyQUsgMNUser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQUsgMNUser();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixbrlyvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixBrlyVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQUsgMNUser::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQUsgMNUser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQUsgMNUser* rec;

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
			PQfnumber(res, "ixbrlyvuserlevel")
		};

		while (numread < numrow) {
			rec = new BrlyQUsgMNUser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixBrlyVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQUsgMNUser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQUsgMNUser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsgMNUser::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsgMNUser::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQUsgMNUser& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsgMNUser::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgMNUser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQUsgMNUser::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgMNUser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQUsgMNUser::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQUsgMNUser::insertRec(
			BrlyQUsgMNUser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixBrlyVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsgMNUser_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsgMNUser::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQUsgMNUser::insertRst(
			ListBrlyQUsgMNUser& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQUsgMNUser::updateRec(
			BrlyQUsgMNUser* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixBrlyVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsgMNUser_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsgMNUser::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQUsgMNUser::updateRst(
			ListBrlyQUsgMNUser& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQUsgMNUser::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsgMNUser_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsgMNUser::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQUsgMNUser::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsgMNUser_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsgMNUser::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQUsgMNUser::loadRecByQref(
			ubigint qref
			, BrlyQUsgMNUser** rec
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

	return loadRecByStmt("TblBrlyQUsgMNUser_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgMNUser& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQUsgMNUser_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
