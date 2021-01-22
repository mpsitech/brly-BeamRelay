/**
	* \file BrlyAMUserAccess.cpp
	* database access for table TblBrlyAMUserAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyAMUserAccess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class BrlyAMUserAccess
 ******************************************************************************/

BrlyAMUserAccess::BrlyAMUserAccess(
			const ubigint ref
			, const ubigint refBrlyMUser
			, const uint x1IxBrlyVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixBrlyWAccess
		) {

	this->ref = ref;
	this->refBrlyMUser = refBrlyMUser;
	this->x1IxBrlyVFeatgroup = x1IxBrlyVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixBrlyWAccess = ixBrlyWAccess;
};

bool BrlyAMUserAccess::operator==(
			const BrlyAMUserAccess& comp
		) {
	return false;
};

bool BrlyAMUserAccess::operator!=(
			const BrlyAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAMUserAccess
 ******************************************************************************/

ListBrlyAMUserAccess::ListBrlyAMUserAccess() {
};

ListBrlyAMUserAccess::ListBrlyAMUserAccess(
			const ListBrlyAMUserAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyAMUserAccess(*(src.nodes[i]));
};

ListBrlyAMUserAccess::~ListBrlyAMUserAccess() {
	clear();
};

void ListBrlyAMUserAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAMUserAccess::size() const {
	return(nodes.size());
};

void ListBrlyAMUserAccess::append(
			BrlyAMUserAccess* rec
		) {
	nodes.push_back(rec);
};

BrlyAMUserAccess* ListBrlyAMUserAccess::operator[](
			const uint ix
		) {
	BrlyAMUserAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAMUserAccess& ListBrlyAMUserAccess::operator=(
			const ListBrlyAMUserAccess& src
		) {
	BrlyAMUserAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyAMUserAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAMUserAccess::operator==(
			const ListBrlyAMUserAccess& comp
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

bool ListBrlyAMUserAccess::operator!=(
			const ListBrlyAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAMUserAccess
 ******************************************************************************/

TblBrlyAMUserAccess::TblBrlyAMUserAccess() {
};

TblBrlyAMUserAccess::~TblBrlyAMUserAccess() {
};

bool TblBrlyAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUserAccess** rec
		) {
	return false;
};

ubigint TblBrlyAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	return 0;
};

ubigint TblBrlyAMUserAccess::insertRec(
			BrlyAMUserAccess* rec
		) {
	return 0;
};

ubigint TblBrlyAMUserAccess::insertNewRec(
			BrlyAMUserAccess** rec
			, const ubigint refBrlyMUser
			, const uint x1IxBrlyVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixBrlyWAccess
		) {
	ubigint retval = 0;
	BrlyAMUserAccess* _rec = NULL;

	_rec = new BrlyAMUserAccess(0, refBrlyMUser, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAMUserAccess::appendNewRecToRst(
			ListBrlyAMUserAccess& rst
			, BrlyAMUserAccess** rec
			, const ubigint refBrlyMUser
			, const uint x1IxBrlyVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixBrlyWAccess
		) {
	ubigint retval = 0;
	BrlyAMUserAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMUser, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAMUserAccess::insertRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
};

void TblBrlyAMUserAccess::updateRec(
			BrlyAMUserAccess* rec
		) {
};

void TblBrlyAMUserAccess::updateRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
};

void TblBrlyAMUserAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAMUserAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUserAccess** rec
		) {
	return false;
};

ubigint TblBrlyAMUserAccess::loadRefsByUsr(
			ubigint refBrlyMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyAMUserAccess::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	return 0;
};

ubigint TblBrlyAMUserAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	ubigint numload = 0;
	BrlyAMUserAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyAMUserAccess
 ******************************************************************************/

MyTblBrlyAMUserAccess::MyTblBrlyAMUserAccess() :
			TblBrlyAMUserAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAMUserAccess::~MyTblBrlyAMUserAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAMUserAccess (refBrlyMUser, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAMUserAccess SET refBrlyMUser = ?, x1IxBrlyVFeatgroup = ?, x2FeaSrefUix = ?, ixBrlyWAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAMUserAccess WHERE ref = ?", false);
};

bool MyTblBrlyAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUserAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAMUserAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyAMUserAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyAMUserAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyAMUserAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMUser = atoll((char*) dbrow[1]); else _rec->refBrlyMUser = 0;
		if (dbrow[2]) _rec->x1IxBrlyVFeatgroup = atol((char*) dbrow[2]); else _rec->x1IxBrlyVFeatgroup = 0;
		if (dbrow[3]) _rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else _rec->x2FeaSrefUix = "";
		if (dbrow[4]) _rec->ixBrlyWAccess = atol((char*) dbrow[4]); else _rec->ixBrlyWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAMUserAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyAMUserAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyAMUserAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyAMUserAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMUser = atoll((char*) dbrow[1]); else rec->refBrlyMUser = 0;
			if (dbrow[2]) rec->x1IxBrlyVFeatgroup = atol((char*) dbrow[2]); else rec->x1IxBrlyVFeatgroup = 0;
			if (dbrow[3]) rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else rec->x2FeaSrefUix = "";
			if (dbrow[4]) rec->ixBrlyWAccess = atol((char*) dbrow[4]); else rec->ixBrlyWAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyAMUserAccess::insertRec(
			BrlyAMUserAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixBrlyWAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyAMUserAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyAMUserAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblBrlyAMUserAccess::insertRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAMUserAccess::updateRec(
			BrlyAMUserAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixBrlyWAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyAMUserAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyAMUserAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyAMUserAccess::updateRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblBrlyAMUserAccess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblBrlyAMUserAccess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyAMUserAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUserAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyAMUserAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyAMUserAccess::loadRefsByUsr(
			ubigint refBrlyMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyAMUserAccess WHERE refBrlyMUser = " + to_string(refBrlyMUser) + "", append, refs);
};

ubigint MyTblBrlyAMUserAccess::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMUser, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess FROM TblBrlyAMUserAccess WHERE refBrlyMUser = " + to_string(refBrlyMUser) + " ORDER BY x1IxBrlyVFeatgroup ASC, x2FeaSrefUix ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyAMUserAccess
 ******************************************************************************/

PgTblBrlyAMUserAccess::PgTblBrlyAMUserAccess() :
			TblBrlyAMUserAccess()
			, PgTable()
		{
};

PgTblBrlyAMUserAccess::~PgTblBrlyAMUserAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAMUserAccess::initStatements() {
	createStatement("TblBrlyAMUserAccess_insertRec", "INSERT INTO TblBrlyAMUserAccess (refBrlyMUser, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblBrlyAMUserAccess_updateRec", "UPDATE TblBrlyAMUserAccess SET refBrlyMUser = $1, x1IxBrlyVFeatgroup = $2, x2FeaSrefUix = $3, ixBrlyWAccess = $4 WHERE ref = $5", 5);
	createStatement("TblBrlyAMUserAccess_removeRecByRef", "DELETE FROM TblBrlyAMUserAccess WHERE ref = $1", 1);

	createStatement("TblBrlyAMUserAccess_loadRecByRef", "SELECT ref, refBrlyMUser, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess FROM TblBrlyAMUserAccess WHERE ref = $1", 1);
	createStatement("TblBrlyAMUserAccess_loadRefsByUsr", "SELECT ref FROM TblBrlyAMUserAccess WHERE refBrlyMUser = $1", 1);
	createStatement("TblBrlyAMUserAccess_loadRstByUsr", "SELECT ref, refBrlyMUser, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess FROM TblBrlyAMUserAccess WHERE refBrlyMUser = $1 ORDER BY x1IxBrlyVFeatgroup ASC, x2FeaSrefUix ASC", 1);
};

bool PgTblBrlyAMUserAccess::loadRec(
			PGresult* res
			, BrlyAMUserAccess** rec
		) {
	char* ptr;

	BrlyAMUserAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAMUserAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "x1ixbrlyvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixbrlywaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxBrlyVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixBrlyWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAMUserAccess::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAMUserAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "x1ixbrlyvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixbrlywaccess")
		};

		while (numread < numrow) {
			rec = new BrlyAMUserAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxBrlyVFeatgroup = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixBrlyWAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyAMUserAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMUserAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMUserAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMUserAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMUserAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMUserAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyAMUserAccess::insertRec(
			BrlyAMUserAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _x1IxBrlyVFeatgroup = htonl(rec->x1IxBrlyVFeatgroup);
	uint _ixBrlyWAccess = htonl(rec->ixBrlyWAccess);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_x1IxBrlyVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixBrlyWAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyAMUserAccess_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMUserAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblBrlyAMUserAccess::insertRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAMUserAccess::updateRec(
			BrlyAMUserAccess* rec
		) {
	PGresult* res;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _x1IxBrlyVFeatgroup = htonl(rec->x1IxBrlyVFeatgroup);
	uint _ixBrlyWAccess = htonl(rec->ixBrlyWAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_x1IxBrlyVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixBrlyWAccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyAMUserAccess_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyAMUserAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyAMUserAccess::updateRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAMUserAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyAMUserAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyAMUserAccess::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyAMUserAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUserAccess** rec
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

	return loadRecByStmt("TblBrlyAMUserAccess_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyAMUserAccess::loadRefsByUsr(
			ubigint refBrlyMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);

	const char* vals[] = {
		(char*) &_refBrlyMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyAMUserAccess_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyAMUserAccess::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);

	const char* vals[] = {
		(char*) &_refBrlyMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyAMUserAccess_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif
