/**
	* \file BrlyJMRegionTitle.cpp
	* database access for table TblBrlyJMRegionTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyJMRegionTitle.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class BrlyJMRegionTitle
 ******************************************************************************/

BrlyJMRegionTitle::BrlyJMRegionTitle(
			const ubigint ref
			, const ubigint refBrlyMRegion
			, const uint x1IxBrlyVLocale
			, const string Title
		) {

	this->ref = ref;
	this->refBrlyMRegion = refBrlyMRegion;
	this->x1IxBrlyVLocale = x1IxBrlyVLocale;
	this->Title = Title;
};

bool BrlyJMRegionTitle::operator==(
			const BrlyJMRegionTitle& comp
		) {
	return false;
};

bool BrlyJMRegionTitle::operator!=(
			const BrlyJMRegionTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyJMRegionTitle
 ******************************************************************************/

ListBrlyJMRegionTitle::ListBrlyJMRegionTitle() {
};

ListBrlyJMRegionTitle::ListBrlyJMRegionTitle(
			const ListBrlyJMRegionTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyJMRegionTitle(*(src.nodes[i]));
};

ListBrlyJMRegionTitle::~ListBrlyJMRegionTitle() {
	clear();
};

void ListBrlyJMRegionTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyJMRegionTitle::size() const {
	return(nodes.size());
};

void ListBrlyJMRegionTitle::append(
			BrlyJMRegionTitle* rec
		) {
	nodes.push_back(rec);
};

BrlyJMRegionTitle* ListBrlyJMRegionTitle::operator[](
			const uint ix
		) {
	BrlyJMRegionTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyJMRegionTitle& ListBrlyJMRegionTitle::operator=(
			const ListBrlyJMRegionTitle& src
		) {
	BrlyJMRegionTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyJMRegionTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyJMRegionTitle::operator==(
			const ListBrlyJMRegionTitle& comp
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

bool ListBrlyJMRegionTitle::operator!=(
			const ListBrlyJMRegionTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyJMRegionTitle
 ******************************************************************************/

TblBrlyJMRegionTitle::TblBrlyJMRegionTitle() {
};

TblBrlyJMRegionTitle::~TblBrlyJMRegionTitle() {
};

bool TblBrlyJMRegionTitle::loadRecBySQL(
			const string& sqlstr
			, BrlyJMRegionTitle** rec
		) {
	return false;
};

ubigint TblBrlyJMRegionTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	return 0;
};

ubigint TblBrlyJMRegionTitle::insertRec(
			BrlyJMRegionTitle* rec
		) {
	return 0;
};

ubigint TblBrlyJMRegionTitle::insertNewRec(
			BrlyJMRegionTitle** rec
			, const ubigint refBrlyMRegion
			, const uint x1IxBrlyVLocale
			, const string Title
		) {
	ubigint retval = 0;
	BrlyJMRegionTitle* _rec = NULL;

	_rec = new BrlyJMRegionTitle(0, refBrlyMRegion, x1IxBrlyVLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyJMRegionTitle::appendNewRecToRst(
			ListBrlyJMRegionTitle& rst
			, BrlyJMRegionTitle** rec
			, const ubigint refBrlyMRegion
			, const uint x1IxBrlyVLocale
			, const string Title
		) {
	ubigint retval = 0;
	BrlyJMRegionTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMRegion, x1IxBrlyVLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyJMRegionTitle::insertRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
};

void TblBrlyJMRegionTitle::updateRec(
			BrlyJMRegionTitle* rec
		) {
};

void TblBrlyJMRegionTitle::updateRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
};

void TblBrlyJMRegionTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyJMRegionTitle::loadRecByRef(
			ubigint ref
			, BrlyJMRegionTitle** rec
		) {
	return false;
};

bool TblBrlyJMRegionTitle::loadRecByRegLcl(
			ubigint refBrlyMRegion
			, uint x1IxBrlyVLocale
			, BrlyJMRegionTitle** rec
		) {
	return false;
};

ubigint TblBrlyJMRegionTitle::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyJMRegionTitle::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	return 0;
};

ubigint TblBrlyJMRegionTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	ubigint numload = 0;
	BrlyJMRegionTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyJMRegionTitle
 ******************************************************************************/

MyTblBrlyJMRegionTitle::MyTblBrlyJMRegionTitle() :
			TblBrlyJMRegionTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyJMRegionTitle::~MyTblBrlyJMRegionTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyJMRegionTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyJMRegionTitle (refBrlyMRegion, x1IxBrlyVLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyJMRegionTitle SET refBrlyMRegion = ?, x1IxBrlyVLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyJMRegionTitle WHERE ref = ?", false);
};

bool MyTblBrlyJMRegionTitle::loadRecBySQL(
			const string& sqlstr
			, BrlyJMRegionTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyJMRegionTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyJMRegionTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyJMRegionTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyJMRegionTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMRegion = atoll((char*) dbrow[1]); else _rec->refBrlyMRegion = 0;
		if (dbrow[2]) _rec->x1IxBrlyVLocale = atol((char*) dbrow[2]); else _rec->x1IxBrlyVLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyJMRegionTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyJMRegionTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyJMRegionTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyJMRegionTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyJMRegionTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMRegion = atoll((char*) dbrow[1]); else rec->refBrlyMRegion = 0;
			if (dbrow[2]) rec->x1IxBrlyVLocale = atol((char*) dbrow[2]); else rec->x1IxBrlyVLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyJMRegionTitle::insertRec(
			BrlyJMRegionTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMRegion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyJMRegionTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyJMRegionTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblBrlyJMRegionTitle::insertRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyJMRegionTitle::updateRec(
			BrlyJMRegionTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMRegion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyJMRegionTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyJMRegionTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyJMRegionTitle::updateRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyJMRegionTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblBrlyJMRegionTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblBrlyJMRegionTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyJMRegionTitle::loadRecByRef(
			ubigint ref
			, BrlyJMRegionTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyJMRegionTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyJMRegionTitle::loadRecByRegLcl(
			ubigint refBrlyMRegion
			, uint x1IxBrlyVLocale
			, BrlyJMRegionTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMRegion, x1IxBrlyVLocale, Title FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + " AND x1IxBrlyVLocale = " + to_string(x1IxBrlyVLocale) + "", rec);
};

ubigint MyTblBrlyJMRegionTitle::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + "", append, refs);
};

ubigint MyTblBrlyJMRegionTitle::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMRegion, x1IxBrlyVLocale, Title FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + " ORDER BY x1IxBrlyVLocale ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyJMRegionTitle
 ******************************************************************************/

PgTblBrlyJMRegionTitle::PgTblBrlyJMRegionTitle() :
			TblBrlyJMRegionTitle()
			, PgTable()
		{
};

PgTblBrlyJMRegionTitle::~PgTblBrlyJMRegionTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyJMRegionTitle::initStatements() {
	createStatement("TblBrlyJMRegionTitle_insertRec", "INSERT INTO TblBrlyJMRegionTitle (refBrlyMRegion, x1IxBrlyVLocale, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblBrlyJMRegionTitle_updateRec", "UPDATE TblBrlyJMRegionTitle SET refBrlyMRegion = $1, x1IxBrlyVLocale = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblBrlyJMRegionTitle_removeRecByRef", "DELETE FROM TblBrlyJMRegionTitle WHERE ref = $1", 1);

	createStatement("TblBrlyJMRegionTitle_loadRecByRef", "SELECT ref, refBrlyMRegion, x1IxBrlyVLocale, Title FROM TblBrlyJMRegionTitle WHERE ref = $1", 1);
	createStatement("TblBrlyJMRegionTitle_loadRecByRegLcl", "SELECT ref, refBrlyMRegion, x1IxBrlyVLocale, Title FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = $1 AND x1IxBrlyVLocale = $2", 2);
	createStatement("TblBrlyJMRegionTitle_loadRefsByReg", "SELECT ref FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = $1", 1);
	createStatement("TblBrlyJMRegionTitle_loadRstByReg", "SELECT ref, refBrlyMRegion, x1IxBrlyVLocale, Title FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = $1 ORDER BY x1IxBrlyVLocale ASC", 1);
};

bool PgTblBrlyJMRegionTitle::loadRec(
			PGresult* res
			, BrlyJMRegionTitle** rec
		) {
	char* ptr;

	BrlyJMRegionTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyJMRegionTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "x1ixbrlyvlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMRegion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxBrlyVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyJMRegionTitle::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyJMRegionTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "x1ixbrlyvlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new BrlyJMRegionTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMRegion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxBrlyVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyJMRegionTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyJMRegionTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyJMRegionTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyJMRegionTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyJMRegionTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyJMRegionTitle::loadRecBySQL(
			const string& sqlstr
			, BrlyJMRegionTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyJMRegionTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyJMRegionTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyJMRegionTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyJMRegionTitle::insertRec(
			BrlyJMRegionTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	uint _x1IxBrlyVLocale = htonl(rec->x1IxBrlyVLocale);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_x1IxBrlyVLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyJMRegionTitle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyJMRegionTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblBrlyJMRegionTitle::insertRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyJMRegionTitle::updateRec(
			BrlyJMRegionTitle* rec
		) {
	PGresult* res;

	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	uint _x1IxBrlyVLocale = htonl(rec->x1IxBrlyVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_x1IxBrlyVLocale,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyJMRegionTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyJMRegionTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyJMRegionTitle::updateRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyJMRegionTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyJMRegionTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyJMRegionTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyJMRegionTitle::loadRecByRef(
			ubigint ref
			, BrlyJMRegionTitle** rec
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

	return loadRecByStmt("TblBrlyJMRegionTitle_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyJMRegionTitle::loadRecByRegLcl(
			ubigint refBrlyMRegion
			, uint x1IxBrlyVLocale
			, BrlyJMRegionTitle** rec
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);
	uint _x1IxBrlyVLocale = htonl(x1IxBrlyVLocale);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_x1IxBrlyVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblBrlyJMRegionTitle_loadRecByRegLcl", 2, vals, l, f, rec);
};

ubigint PgTblBrlyJMRegionTitle::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);

	const char* vals[] = {
		(char*) &_refBrlyMRegion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyJMRegionTitle_loadRefsByReg", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyJMRegionTitle::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);

	const char* vals[] = {
		(char*) &_refBrlyMRegion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyJMRegionTitle_loadRstByReg", 1, vals, l, f, append, rst);
};

#endif
