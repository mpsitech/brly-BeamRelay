/**
	* \file BrlyJMPersonLastname.cpp
	* database access for table TblBrlyJMPersonLastname (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyJMPersonLastname.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class BrlyJMPersonLastname
 ******************************************************************************/

BrlyJMPersonLastname::BrlyJMPersonLastname(
			const ubigint ref
			, const ubigint refBrlyMPerson
			, const uint x1Startd
			, const string Lastname
		) {

	this->ref = ref;
	this->refBrlyMPerson = refBrlyMPerson;
	this->x1Startd = x1Startd;
	this->Lastname = Lastname;
};

bool BrlyJMPersonLastname::operator==(
			const BrlyJMPersonLastname& comp
		) {
	return false;
};

bool BrlyJMPersonLastname::operator!=(
			const BrlyJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyJMPersonLastname
 ******************************************************************************/

ListBrlyJMPersonLastname::ListBrlyJMPersonLastname() {
};

ListBrlyJMPersonLastname::ListBrlyJMPersonLastname(
			const ListBrlyJMPersonLastname& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyJMPersonLastname(*(src.nodes[i]));
};

ListBrlyJMPersonLastname::~ListBrlyJMPersonLastname() {
	clear();
};

void ListBrlyJMPersonLastname::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyJMPersonLastname::size() const {
	return(nodes.size());
};

void ListBrlyJMPersonLastname::append(
			BrlyJMPersonLastname* rec
		) {
	nodes.push_back(rec);
};

BrlyJMPersonLastname* ListBrlyJMPersonLastname::operator[](
			const uint ix
		) {
	BrlyJMPersonLastname* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyJMPersonLastname& ListBrlyJMPersonLastname::operator=(
			const ListBrlyJMPersonLastname& src
		) {
	BrlyJMPersonLastname* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyJMPersonLastname(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyJMPersonLastname::operator==(
			const ListBrlyJMPersonLastname& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListBrlyJMPersonLastname::operator!=(
			const ListBrlyJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyJMPersonLastname
 ******************************************************************************/

TblBrlyJMPersonLastname::TblBrlyJMPersonLastname() {
};

TblBrlyJMPersonLastname::~TblBrlyJMPersonLastname() {
};

bool TblBrlyJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, BrlyJMPersonLastname** rec
		) {
	return false;
};

ubigint TblBrlyJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblBrlyJMPersonLastname::insertRec(
			BrlyJMPersonLastname* rec
		) {
	return 0;
};

ubigint TblBrlyJMPersonLastname::insertNewRec(
			BrlyJMPersonLastname** rec
			, const ubigint refBrlyMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	BrlyJMPersonLastname* _rec = NULL;

	_rec = new BrlyJMPersonLastname(0, refBrlyMPerson, x1Startd, Lastname);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyJMPersonLastname::appendNewRecToRst(
			ListBrlyJMPersonLastname& rst
			, BrlyJMPersonLastname** rec
			, const ubigint refBrlyMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	BrlyJMPersonLastname* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMPerson, x1Startd, Lastname);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyJMPersonLastname::insertRst(
			ListBrlyJMPersonLastname& rst
			, bool transact
		) {
};

void TblBrlyJMPersonLastname::updateRec(
			BrlyJMPersonLastname* rec
		) {
};

void TblBrlyJMPersonLastname::updateRst(
			ListBrlyJMPersonLastname& rst
			, bool transact
		) {
};

void TblBrlyJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyJMPersonLastname::loadRecByRef(
			ubigint ref
			, BrlyJMPersonLastname** rec
		) {
	return false;
};

bool TblBrlyJMPersonLastname::loadRecByPrsSta(
			ubigint refBrlyMPerson
			, uint x1Startd
			, BrlyJMPersonLastname** rec
		) {
	return false;
};

ubigint TblBrlyJMPersonLastname::loadRefsByPrs(
			ubigint refBrlyMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyJMPersonLastname::loadRstByPrs(
			ubigint refBrlyMPerson
			, const bool append
			, ListBrlyJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblBrlyJMPersonLastname::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyJMPersonLastname& rst
		) {
	ubigint numload = 0;
	BrlyJMPersonLastname* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyJMPersonLastname
 ******************************************************************************/

MyTblBrlyJMPersonLastname::MyTblBrlyJMPersonLastname() :
			TblBrlyJMPersonLastname()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyJMPersonLastname::~MyTblBrlyJMPersonLastname() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyJMPersonLastname::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyJMPersonLastname (refBrlyMPerson, x1Startd, Lastname) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyJMPersonLastname SET refBrlyMPerson = ?, x1Startd = ?, Lastname = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyJMPersonLastname WHERE ref = ?", false);
};

bool MyTblBrlyJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, BrlyJMPersonLastname** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyJMPersonLastname* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyJMPersonLastname::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyJMPersonLastname::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyJMPersonLastname();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMPerson = atoll((char*) dbrow[1]); else _rec->refBrlyMPerson = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->Lastname.assign(dbrow[3], dblengths[3]); else _rec->Lastname = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMPersonLastname& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyJMPersonLastname* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyJMPersonLastname::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyJMPersonLastname::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyJMPersonLastname();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMPerson = atoll((char*) dbrow[1]); else rec->refBrlyMPerson = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->Lastname.assign(dbrow[3], dblengths[3]); else rec->Lastname = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyJMPersonLastname::insertRec(
			BrlyJMPersonLastname* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyJMPersonLastname::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyJMPersonLastname::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblBrlyJMPersonLastname::insertRst(
			ListBrlyJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyJMPersonLastname::updateRec(
			BrlyJMPersonLastname* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyJMPersonLastname::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyJMPersonLastname::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyJMPersonLastname::updateRst(
			ListBrlyJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblBrlyJMPersonLastname::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblBrlyJMPersonLastname::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyJMPersonLastname::loadRecByRef(
			ubigint ref
			, BrlyJMPersonLastname** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyJMPersonLastname WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyJMPersonLastname::loadRecByPrsSta(
			ubigint refBrlyMPerson
			, uint x1Startd
			, BrlyJMPersonLastname** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMPerson, x1Startd, Lastname FROM TblBrlyJMPersonLastname WHERE refBrlyMPerson = " + to_string(refBrlyMPerson) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblBrlyJMPersonLastname::loadRefsByPrs(
			ubigint refBrlyMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyJMPersonLastname WHERE refBrlyMPerson = " + to_string(refBrlyMPerson) + "", append, refs);
};

ubigint MyTblBrlyJMPersonLastname::loadRstByPrs(
			ubigint refBrlyMPerson
			, const bool append
			, ListBrlyJMPersonLastname& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMPerson, x1Startd, Lastname FROM TblBrlyJMPersonLastname WHERE refBrlyMPerson = " + to_string(refBrlyMPerson) + " ORDER BY x1Startd ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyJMPersonLastname
 ******************************************************************************/

PgTblBrlyJMPersonLastname::PgTblBrlyJMPersonLastname() :
			TblBrlyJMPersonLastname()
			, PgTable()
		{
};

PgTblBrlyJMPersonLastname::~PgTblBrlyJMPersonLastname() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyJMPersonLastname::initStatements() {
	createStatement("TblBrlyJMPersonLastname_insertRec", "INSERT INTO TblBrlyJMPersonLastname (refBrlyMPerson, x1Startd, Lastname) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblBrlyJMPersonLastname_updateRec", "UPDATE TblBrlyJMPersonLastname SET refBrlyMPerson = $1, x1Startd = $2, Lastname = $3 WHERE ref = $4", 4);
	createStatement("TblBrlyJMPersonLastname_removeRecByRef", "DELETE FROM TblBrlyJMPersonLastname WHERE ref = $1", 1);

	createStatement("TblBrlyJMPersonLastname_loadRecByRef", "SELECT ref, refBrlyMPerson, x1Startd, Lastname FROM TblBrlyJMPersonLastname WHERE ref = $1", 1);
	createStatement("TblBrlyJMPersonLastname_loadRecByPrsSta", "SELECT ref, refBrlyMPerson, x1Startd, Lastname FROM TblBrlyJMPersonLastname WHERE refBrlyMPerson = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2);
	createStatement("TblBrlyJMPersonLastname_loadRefsByPrs", "SELECT ref FROM TblBrlyJMPersonLastname WHERE refBrlyMPerson = $1", 1);
	createStatement("TblBrlyJMPersonLastname_loadRstByPrs", "SELECT ref, refBrlyMPerson, x1Startd, Lastname FROM TblBrlyJMPersonLastname WHERE refBrlyMPerson = $1 ORDER BY x1Startd ASC", 1);
};

bool PgTblBrlyJMPersonLastname::loadRec(
			PGresult* res
			, BrlyJMPersonLastname** rec
		) {
	char* ptr;

	BrlyJMPersonLastname* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyJMPersonLastname();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyJMPersonLastname::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyJMPersonLastname& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyJMPersonLastname* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		while (numread < numrow) {
			rec = new BrlyJMPersonLastname();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyJMPersonLastname::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyJMPersonLastname::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyJMPersonLastname::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyJMPersonLastname::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, BrlyJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyJMPersonLastname::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyJMPersonLastname::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyJMPersonLastname::insertRec(
			BrlyJMPersonLastname* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMPerson = htonl64(rec->refBrlyMPerson);
	uint _x1Startd = htonl(rec->x1Startd);

	const char* vals[] = {
		(char*) &_refBrlyMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyJMPersonLastname_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyJMPersonLastname::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblBrlyJMPersonLastname::insertRst(
			ListBrlyJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyJMPersonLastname::updateRec(
			BrlyJMPersonLastname* rec
		) {
	PGresult* res;

	ubigint _refBrlyMPerson = htonl64(rec->refBrlyMPerson);
	uint _x1Startd = htonl(rec->x1Startd);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyJMPersonLastname_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyJMPersonLastname::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyJMPersonLastname::updateRst(
			ListBrlyJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyJMPersonLastname_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyJMPersonLastname::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyJMPersonLastname::loadRecByRef(
			ubigint ref
			, BrlyJMPersonLastname** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyJMPersonLastname_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyJMPersonLastname::loadRecByPrsSta(
			ubigint refBrlyMPerson
			, uint x1Startd
			, BrlyJMPersonLastname** rec
		) {
	ubigint _refBrlyMPerson = htonl64(refBrlyMPerson);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refBrlyMPerson,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblBrlyJMPersonLastname_loadRecByPrsSta", 2, vals, l, f, rec);
};

ubigint PgTblBrlyJMPersonLastname::loadRefsByPrs(
			ubigint refBrlyMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyMPerson = htonl64(refBrlyMPerson);

	const char* vals[] = {
		(char*) &_refBrlyMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyJMPersonLastname_loadRefsByPrs", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyJMPersonLastname::loadRstByPrs(
			ubigint refBrlyMPerson
			, const bool append
			, ListBrlyJMPersonLastname& rst
		) {
	ubigint _refBrlyMPerson = htonl64(refBrlyMPerson);

	const char* vals[] = {
		(char*) &_refBrlyMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyJMPersonLastname_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif
