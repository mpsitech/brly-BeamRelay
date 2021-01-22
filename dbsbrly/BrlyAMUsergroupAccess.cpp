/**
	* \file BrlyAMUsergroupAccess.cpp
	* database access for table TblBrlyAMUsergroupAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyAMUsergroupAccess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class BrlyAMUsergroupAccess
 ******************************************************************************/

BrlyAMUsergroupAccess::BrlyAMUsergroupAccess(
			const ubigint ref
			, const ubigint refBrlyMUsergroup
			, const uint x1IxBrlyVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixBrlyWAccess
		) {

	this->ref = ref;
	this->refBrlyMUsergroup = refBrlyMUsergroup;
	this->x1IxBrlyVFeatgroup = x1IxBrlyVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixBrlyWAccess = ixBrlyWAccess;
};

bool BrlyAMUsergroupAccess::operator==(
			const BrlyAMUsergroupAccess& comp
		) {
	return false;
};

bool BrlyAMUsergroupAccess::operator!=(
			const BrlyAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAMUsergroupAccess
 ******************************************************************************/

ListBrlyAMUsergroupAccess::ListBrlyAMUsergroupAccess() {
};

ListBrlyAMUsergroupAccess::ListBrlyAMUsergroupAccess(
			const ListBrlyAMUsergroupAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyAMUsergroupAccess(*(src.nodes[i]));
};

ListBrlyAMUsergroupAccess::~ListBrlyAMUsergroupAccess() {
	clear();
};

void ListBrlyAMUsergroupAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAMUsergroupAccess::size() const {
	return(nodes.size());
};

void ListBrlyAMUsergroupAccess::append(
			BrlyAMUsergroupAccess* rec
		) {
	nodes.push_back(rec);
};

BrlyAMUsergroupAccess* ListBrlyAMUsergroupAccess::operator[](
			const uint ix
		) {
	BrlyAMUsergroupAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAMUsergroupAccess& ListBrlyAMUsergroupAccess::operator=(
			const ListBrlyAMUsergroupAccess& src
		) {
	BrlyAMUsergroupAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyAMUsergroupAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAMUsergroupAccess::operator==(
			const ListBrlyAMUsergroupAccess& comp
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

bool ListBrlyAMUsergroupAccess::operator!=(
			const ListBrlyAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAMUsergroupAccess
 ******************************************************************************/

TblBrlyAMUsergroupAccess::TblBrlyAMUsergroupAccess() {
};

TblBrlyAMUsergroupAccess::~TblBrlyAMUsergroupAccess() {
};

bool TblBrlyAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblBrlyAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblBrlyAMUsergroupAccess::insertRec(
			BrlyAMUsergroupAccess* rec
		) {
	return 0;
};

ubigint TblBrlyAMUsergroupAccess::insertNewRec(
			BrlyAMUsergroupAccess** rec
			, const ubigint refBrlyMUsergroup
			, const uint x1IxBrlyVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixBrlyWAccess
		) {
	ubigint retval = 0;
	BrlyAMUsergroupAccess* _rec = NULL;

	_rec = new BrlyAMUsergroupAccess(0, refBrlyMUsergroup, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAMUsergroupAccess::appendNewRecToRst(
			ListBrlyAMUsergroupAccess& rst
			, BrlyAMUsergroupAccess** rec
			, const ubigint refBrlyMUsergroup
			, const uint x1IxBrlyVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixBrlyWAccess
		) {
	ubigint retval = 0;
	BrlyAMUsergroupAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMUsergroup, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAMUsergroupAccess::insertRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblBrlyAMUsergroupAccess::updateRec(
			BrlyAMUsergroupAccess* rec
		) {
};

void TblBrlyAMUsergroupAccess::updateRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblBrlyAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblBrlyAMUsergroupAccess::loadRefsByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyAMUsergroupAccess::loadRstByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblBrlyAMUsergroupAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	ubigint numload = 0;
	BrlyAMUsergroupAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyAMUsergroupAccess
 ******************************************************************************/

MyTblBrlyAMUsergroupAccess::MyTblBrlyAMUsergroupAccess() :
			TblBrlyAMUsergroupAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAMUsergroupAccess::~MyTblBrlyAMUsergroupAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAMUsergroupAccess (refBrlyMUsergroup, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAMUsergroupAccess SET refBrlyMUsergroup = ?, x1IxBrlyVFeatgroup = ?, x2FeaSrefUix = ?, ixBrlyWAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAMUsergroupAccess WHERE ref = ?", false);
};

bool MyTblBrlyAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUsergroupAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAMUsergroupAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyAMUsergroupAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyAMUsergroupAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyAMUsergroupAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMUsergroup = atoll((char*) dbrow[1]); else _rec->refBrlyMUsergroup = 0;
		if (dbrow[2]) _rec->x1IxBrlyVFeatgroup = atol((char*) dbrow[2]); else _rec->x1IxBrlyVFeatgroup = 0;
		if (dbrow[3]) _rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else _rec->x2FeaSrefUix = "";
		if (dbrow[4]) _rec->ixBrlyWAccess = atol((char*) dbrow[4]); else _rec->ixBrlyWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAMUsergroupAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyAMUsergroupAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyAMUsergroupAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyAMUsergroupAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMUsergroup = atoll((char*) dbrow[1]); else rec->refBrlyMUsergroup = 0;
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

ubigint MyTblBrlyAMUsergroupAccess::insertRec(
			BrlyAMUsergroupAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixBrlyWAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyAMUsergroupAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyAMUsergroupAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblBrlyAMUsergroupAccess::insertRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAMUsergroupAccess::updateRec(
			BrlyAMUsergroupAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixBrlyWAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyAMUsergroupAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyAMUsergroupAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyAMUsergroupAccess::updateRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblBrlyAMUsergroupAccess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblBrlyAMUsergroupAccess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUsergroupAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyAMUsergroupAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyAMUsergroupAccess::loadRefsByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = " + to_string(refBrlyMUsergroup) + "", append, refs);
};

ubigint MyTblBrlyAMUsergroupAccess::loadRstByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMUsergroup, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = " + to_string(refBrlyMUsergroup) + " ORDER BY x1IxBrlyVFeatgroup ASC, x2FeaSrefUix ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyAMUsergroupAccess
 ******************************************************************************/

PgTblBrlyAMUsergroupAccess::PgTblBrlyAMUsergroupAccess() :
			TblBrlyAMUsergroupAccess()
			, PgTable()
		{
};

PgTblBrlyAMUsergroupAccess::~PgTblBrlyAMUsergroupAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAMUsergroupAccess::initStatements() {
	createStatement("TblBrlyAMUsergroupAccess_insertRec", "INSERT INTO TblBrlyAMUsergroupAccess (refBrlyMUsergroup, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblBrlyAMUsergroupAccess_updateRec", "UPDATE TblBrlyAMUsergroupAccess SET refBrlyMUsergroup = $1, x1IxBrlyVFeatgroup = $2, x2FeaSrefUix = $3, ixBrlyWAccess = $4 WHERE ref = $5", 5);
	createStatement("TblBrlyAMUsergroupAccess_removeRecByRef", "DELETE FROM TblBrlyAMUsergroupAccess WHERE ref = $1", 1);

	createStatement("TblBrlyAMUsergroupAccess_loadRecByRef", "SELECT ref, refBrlyMUsergroup, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess FROM TblBrlyAMUsergroupAccess WHERE ref = $1", 1);
	createStatement("TblBrlyAMUsergroupAccess_loadRefsByUsg", "SELECT ref FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = $1", 1);
	createStatement("TblBrlyAMUsergroupAccess_loadRstByUsg", "SELECT ref, refBrlyMUsergroup, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = $1 ORDER BY x1IxBrlyVFeatgroup ASC, x2FeaSrefUix ASC", 1);
};

bool PgTblBrlyAMUsergroupAccess::loadRec(
			PGresult* res
			, BrlyAMUsergroupAccess** rec
		) {
	char* ptr;

	BrlyAMUsergroupAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAMUsergroupAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "x1ixbrlyvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixbrlywaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxBrlyVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixBrlyWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAMUsergroupAccess::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAMUsergroupAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "x1ixbrlyvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixbrlywaccess")
		};

		while (numread < numrow) {
			rec = new BrlyAMUsergroupAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMUsergroup = atoll(ptr);
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

bool PgTblBrlyAMUsergroupAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMUsergroupAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMUsergroupAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMUsergroupAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMUsergroupAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMUsergroupAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyAMUsergroupAccess::insertRec(
			BrlyAMUsergroupAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _x1IxBrlyVFeatgroup = htonl(rec->x1IxBrlyVFeatgroup);
	uint _ixBrlyWAccess = htonl(rec->ixBrlyWAccess);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup,
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

	res = PQexecPrepared(dbs, "TblBrlyAMUsergroupAccess_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMUsergroupAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblBrlyAMUsergroupAccess::insertRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAMUsergroupAccess::updateRec(
			BrlyAMUsergroupAccess* rec
		) {
	PGresult* res;

	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _x1IxBrlyVFeatgroup = htonl(rec->x1IxBrlyVFeatgroup);
	uint _ixBrlyWAccess = htonl(rec->ixBrlyWAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup,
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

	res = PQexecPrepared(dbs, "TblBrlyAMUsergroupAccess_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyAMUsergroupAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyAMUsergroupAccess::updateRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAMUsergroupAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyAMUsergroupAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyAMUsergroupAccess::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUsergroupAccess** rec
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

	return loadRecByStmt("TblBrlyAMUsergroupAccess_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyAMUsergroupAccess::loadRefsByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyMUsergroup = htonl64(refBrlyMUsergroup);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyAMUsergroupAccess_loadRefsByUsg", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyAMUsergroupAccess::loadRstByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	ubigint _refBrlyMUsergroup = htonl64(refBrlyMUsergroup);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyAMUsergroupAccess_loadRstByUsg", 1, vals, l, f, append, rst);
};

#endif
