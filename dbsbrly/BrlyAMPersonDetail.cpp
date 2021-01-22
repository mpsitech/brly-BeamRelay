/**
	* \file BrlyAMPersonDetail.cpp
	* database access for table TblBrlyAMPersonDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyAMPersonDetail.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class BrlyAMPersonDetail
 ******************************************************************************/

BrlyAMPersonDetail::BrlyAMPersonDetail(
			const ubigint ref
			, const ubigint refBrlyMPerson
			, const string x1SrefKType
			, const string Val
		) {

	this->ref = ref;
	this->refBrlyMPerson = refBrlyMPerson;
	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

bool BrlyAMPersonDetail::operator==(
			const BrlyAMPersonDetail& comp
		) {
	return false;
};

bool BrlyAMPersonDetail::operator!=(
			const BrlyAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAMPersonDetail
 ******************************************************************************/

ListBrlyAMPersonDetail::ListBrlyAMPersonDetail() {
};

ListBrlyAMPersonDetail::ListBrlyAMPersonDetail(
			const ListBrlyAMPersonDetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyAMPersonDetail(*(src.nodes[i]));
};

ListBrlyAMPersonDetail::~ListBrlyAMPersonDetail() {
	clear();
};

void ListBrlyAMPersonDetail::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAMPersonDetail::size() const {
	return(nodes.size());
};

void ListBrlyAMPersonDetail::append(
			BrlyAMPersonDetail* rec
		) {
	nodes.push_back(rec);
};

BrlyAMPersonDetail* ListBrlyAMPersonDetail::operator[](
			const uint ix
		) {
	BrlyAMPersonDetail* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAMPersonDetail& ListBrlyAMPersonDetail::operator=(
			const ListBrlyAMPersonDetail& src
		) {
	BrlyAMPersonDetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyAMPersonDetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAMPersonDetail::operator==(
			const ListBrlyAMPersonDetail& comp
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

bool ListBrlyAMPersonDetail::operator!=(
			const ListBrlyAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAMPersonDetail
 ******************************************************************************/

TblBrlyAMPersonDetail::TblBrlyAMPersonDetail() {
};

TblBrlyAMPersonDetail::~TblBrlyAMPersonDetail() {
};

bool TblBrlyAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, BrlyAMPersonDetail** rec
		) {
	return false;
};

ubigint TblBrlyAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMPersonDetail& rst
		) {
	return 0;
};

ubigint TblBrlyAMPersonDetail::insertRec(
			BrlyAMPersonDetail* rec
		) {
	return 0;
};

ubigint TblBrlyAMPersonDetail::insertNewRec(
			BrlyAMPersonDetail** rec
			, const ubigint refBrlyMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	BrlyAMPersonDetail* _rec = NULL;

	_rec = new BrlyAMPersonDetail(0, refBrlyMPerson, x1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAMPersonDetail::appendNewRecToRst(
			ListBrlyAMPersonDetail& rst
			, BrlyAMPersonDetail** rec
			, const ubigint refBrlyMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	BrlyAMPersonDetail* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMPerson, x1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAMPersonDetail::insertRst(
			ListBrlyAMPersonDetail& rst
			, bool transact
		) {
};

void TblBrlyAMPersonDetail::updateRec(
			BrlyAMPersonDetail* rec
		) {
};

void TblBrlyAMPersonDetail::updateRst(
			ListBrlyAMPersonDetail& rst
			, bool transact
		) {
};

void TblBrlyAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAMPersonDetail::loadRecByRef(
			ubigint ref
			, BrlyAMPersonDetail** rec
		) {
	return false;
};

bool TblBrlyAMPersonDetail::loadRecByPrsTyp(
			ubigint refBrlyMPerson
			, string x1SrefKType
			, BrlyAMPersonDetail** rec
		) {
	return false;
};

ubigint TblBrlyAMPersonDetail::loadRstByPrs(
			ubigint refBrlyMPerson
			, const bool append
			, ListBrlyAMPersonDetail& rst
		) {
	return 0;
};

ubigint TblBrlyAMPersonDetail::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAMPersonDetail& rst
		) {
	ubigint numload = 0;
	BrlyAMPersonDetail* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyAMPersonDetail
 ******************************************************************************/

MyTblBrlyAMPersonDetail::MyTblBrlyAMPersonDetail() :
			TblBrlyAMPersonDetail()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAMPersonDetail::~MyTblBrlyAMPersonDetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAMPersonDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAMPersonDetail (refBrlyMPerson, x1SrefKType, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAMPersonDetail SET refBrlyMPerson = ?, x1SrefKType = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAMPersonDetail WHERE ref = ?", false);
};

bool MyTblBrlyAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, BrlyAMPersonDetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAMPersonDetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyAMPersonDetail::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyAMPersonDetail::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyAMPersonDetail();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMPerson = atoll((char*) dbrow[1]); else _rec->refBrlyMPerson = 0;
		if (dbrow[2]) _rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKType = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMPersonDetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAMPersonDetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyAMPersonDetail::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyAMPersonDetail::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyAMPersonDetail();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMPerson = atoll((char*) dbrow[1]); else rec->refBrlyMPerson = 0;
			if (dbrow[2]) rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else rec->x1SrefKType = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyAMPersonDetail::insertRec(
			BrlyAMPersonDetail* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyAMPersonDetail::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyAMPersonDetail::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblBrlyAMPersonDetail::insertRst(
			ListBrlyAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAMPersonDetail::updateRec(
			BrlyAMPersonDetail* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyAMPersonDetail::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyAMPersonDetail::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyAMPersonDetail::updateRst(
			ListBrlyAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblBrlyAMPersonDetail::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblBrlyAMPersonDetail::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyAMPersonDetail::loadRecByRef(
			ubigint ref
			, BrlyAMPersonDetail** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyAMPersonDetail WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyAMPersonDetail::loadRecByPrsTyp(
			ubigint refBrlyMPerson
			, string x1SrefKType
			, BrlyAMPersonDetail** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMPerson, x1SrefKType, Val FROM TblBrlyAMPersonDetail WHERE refBrlyMPerson = " + to_string(refBrlyMPerson) + " AND x1SrefKType = '" + x1SrefKType + "'", rec);
};

ubigint MyTblBrlyAMPersonDetail::loadRstByPrs(
			ubigint refBrlyMPerson
			, const bool append
			, ListBrlyAMPersonDetail& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMPerson, x1SrefKType, Val FROM TblBrlyAMPersonDetail WHERE refBrlyMPerson = " + to_string(refBrlyMPerson) + " ORDER BY x1SrefKType ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyAMPersonDetail
 ******************************************************************************/

PgTblBrlyAMPersonDetail::PgTblBrlyAMPersonDetail() :
			TblBrlyAMPersonDetail()
			, PgTable()
		{
};

PgTblBrlyAMPersonDetail::~PgTblBrlyAMPersonDetail() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAMPersonDetail::initStatements() {
	createStatement("TblBrlyAMPersonDetail_insertRec", "INSERT INTO TblBrlyAMPersonDetail (refBrlyMPerson, x1SrefKType, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblBrlyAMPersonDetail_updateRec", "UPDATE TblBrlyAMPersonDetail SET refBrlyMPerson = $1, x1SrefKType = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblBrlyAMPersonDetail_removeRecByRef", "DELETE FROM TblBrlyAMPersonDetail WHERE ref = $1", 1);

	createStatement("TblBrlyAMPersonDetail_loadRecByRef", "SELECT ref, refBrlyMPerson, x1SrefKType, Val FROM TblBrlyAMPersonDetail WHERE ref = $1", 1);
	createStatement("TblBrlyAMPersonDetail_loadRecByPrsTyp", "SELECT ref, refBrlyMPerson, x1SrefKType, Val FROM TblBrlyAMPersonDetail WHERE refBrlyMPerson = $1 AND x1SrefKType = $2", 2);
	createStatement("TblBrlyAMPersonDetail_loadRstByPrs", "SELECT ref, refBrlyMPerson, x1SrefKType, Val FROM TblBrlyAMPersonDetail WHERE refBrlyMPerson = $1 ORDER BY x1SrefKType ASC", 1);
};

bool PgTblBrlyAMPersonDetail::loadRec(
			PGresult* res
			, BrlyAMPersonDetail** rec
		) {
	char* ptr;

	BrlyAMPersonDetail* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAMPersonDetail();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKType.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAMPersonDetail::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAMPersonDetail& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAMPersonDetail* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new BrlyAMPersonDetail();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKType.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyAMPersonDetail::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMPersonDetail::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMPersonDetail::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyAMPersonDetail& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMPersonDetail::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, BrlyAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMPersonDetail::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMPersonDetail& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMPersonDetail::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyAMPersonDetail::insertRec(
			BrlyAMPersonDetail* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMPerson = htonl64(rec->refBrlyMPerson);

	const char* vals[] = {
		(char*) &_refBrlyMPerson,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyAMPersonDetail_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMPersonDetail::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblBrlyAMPersonDetail::insertRst(
			ListBrlyAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAMPersonDetail::updateRec(
			BrlyAMPersonDetail* rec
		) {
	PGresult* res;

	ubigint _refBrlyMPerson = htonl64(rec->refBrlyMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMPerson,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyAMPersonDetail_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyAMPersonDetail::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyAMPersonDetail::updateRst(
			ListBrlyAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAMPersonDetail::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyAMPersonDetail_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyAMPersonDetail::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyAMPersonDetail::loadRecByRef(
			ubigint ref
			, BrlyAMPersonDetail** rec
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

	return loadRecByStmt("TblBrlyAMPersonDetail_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyAMPersonDetail::loadRecByPrsTyp(
			ubigint refBrlyMPerson
			, string x1SrefKType
			, BrlyAMPersonDetail** rec
		) {
	ubigint _refBrlyMPerson = htonl64(refBrlyMPerson);

	const char* vals[] = {
		(char*) &_refBrlyMPerson,
		x1SrefKType.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRecByStmt("TblBrlyAMPersonDetail_loadRecByPrsTyp", 2, vals, l, f, rec);
};

ubigint PgTblBrlyAMPersonDetail::loadRstByPrs(
			ubigint refBrlyMPerson
			, const bool append
			, ListBrlyAMPersonDetail& rst
		) {
	ubigint _refBrlyMPerson = htonl64(refBrlyMPerson);

	const char* vals[] = {
		(char*) &_refBrlyMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyAMPersonDetail_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif
