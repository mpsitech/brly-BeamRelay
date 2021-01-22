/**
	* \file BrlyQUsgList.cpp
	* Dbs and XML wrapper for table TblBrlyQUsgList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQUsgList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQUsgList
 ******************************************************************************/

BrlyQUsgList::BrlyQUsgList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string sref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->sref = sref;
};

void BrlyQUsgList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQUsgList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "srf", sref);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "sref", sref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQUsgList
 ******************************************************************************/

ListBrlyQUsgList::ListBrlyQUsgList() {
};

ListBrlyQUsgList::ListBrlyQUsgList(
			const ListBrlyQUsgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQUsgList(*(src.nodes[i]));
};

ListBrlyQUsgList::~ListBrlyQUsgList() {
	clear();
};

void ListBrlyQUsgList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQUsgList::size() const {
	return(nodes.size());
};

void ListBrlyQUsgList::append(
			BrlyQUsgList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQUsgList& ListBrlyQUsgList::operator=(
			const ListBrlyQUsgList& src
		) {
	BrlyQUsgList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQUsgList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQUsgList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQUsgList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQUsgList
 ******************************************************************************/

TblBrlyQUsgList::TblBrlyQUsgList() {
};

TblBrlyQUsgList::~TblBrlyQUsgList() {
};

bool TblBrlyQUsgList::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgList** rec
		) {
	return false;
};

ubigint TblBrlyQUsgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgList& rst
		) {
	return 0;
};

ubigint TblBrlyQUsgList::insertRec(
			BrlyQUsgList* rec
		) {
	return 0;
};

ubigint TblBrlyQUsgList::insertNewRec(
			BrlyQUsgList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string sref
		) {
	ubigint retval = 0;
	BrlyQUsgList* _rec = NULL;

	_rec = new BrlyQUsgList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, sref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQUsgList::appendNewRecToRst(
			ListBrlyQUsgList& rst
			, BrlyQUsgList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string sref
		) {
	ubigint retval = 0;
	BrlyQUsgList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, sref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQUsgList::insertRst(
			ListBrlyQUsgList& rst
		) {
};

void TblBrlyQUsgList::updateRec(
			BrlyQUsgList* rec
		) {
};

void TblBrlyQUsgList::updateRst(
			ListBrlyQUsgList& rst
		) {
};

void TblBrlyQUsgList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQUsgList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQUsgList::loadRecByQref(
			ubigint qref
			, BrlyQUsgList** rec
		) {
	return false;
};

ubigint TblBrlyQUsgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQUsgList
 ******************************************************************************/

MyTblBrlyQUsgList::MyTblBrlyQUsgList() :
			TblBrlyQUsgList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQUsgList::~MyTblBrlyQUsgList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQUsgList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQUsgList (jref, jnum, ref, grp, own, sref) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQUsgList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, sref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQUsgList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQUsgList WHERE jref = ?", false);
};

bool MyTblBrlyQUsgList::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQUsgList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQUsgList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQUsgList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQUsgList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQUsgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQUsgList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQUsgList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQUsgList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQUsgList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQUsgList::insertRec(
			BrlyQUsgList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[5] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQUsgList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQUsgList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQUsgList::insertRst(
			ListBrlyQUsgList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQUsgList::updateRec(
			BrlyQUsgList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[5] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQUsgList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQUsgList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQUsgList::updateRst(
			ListBrlyQUsgList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQUsgList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQUsgList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQUsgList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQUsgList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQUsgList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQUsgList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQUsgList::loadRecByQref(
			ubigint qref
			, BrlyQUsgList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQUsgList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQUsgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQUsgList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQUsgList
 ******************************************************************************/

PgTblBrlyQUsgList::PgTblBrlyQUsgList() :
			TblBrlyQUsgList()
			, PgTable()
		{
};

PgTblBrlyQUsgList::~PgTblBrlyQUsgList() {
};

void PgTblBrlyQUsgList::initStatements() {
	createStatement("TblBrlyQUsgList_insertRec", "INSERT INTO TblBrlyQUsgList (jref, jnum, ref, grp, own, sref) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblBrlyQUsgList_updateRec", "UPDATE TblBrlyQUsgList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, sref = $6 WHERE qref = $7", 7);
	createStatement("TblBrlyQUsgList_removeRecByQref", "DELETE FROM TblBrlyQUsgList WHERE qref = $1", 1);
	createStatement("TblBrlyQUsgList_removeRstByJref", "DELETE FROM TblBrlyQUsgList WHERE jref = $1", 1);

	createStatement("TblBrlyQUsgList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, sref FROM TblBrlyQUsgList WHERE qref = $1", 1);
	createStatement("TblBrlyQUsgList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, sref FROM TblBrlyQUsgList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQUsgList::loadRec(
			PGresult* res
			, BrlyQUsgList** rec
		) {
	char* ptr;

	BrlyQUsgList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQUsgList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQUsgList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQUsgList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQUsgList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref")
		};

		while (numread < numrow) {
			rec = new BrlyQUsgList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQUsgList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQUsgList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsgList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsgList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQUsgList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsgList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQUsgList::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQUsgList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQUsgList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQUsgList::insertRec(
			BrlyQUsgList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyQUsgList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsgList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQUsgList::insertRst(
			ListBrlyQUsgList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQUsgList::updateRec(
			BrlyQUsgList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsgList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsgList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQUsgList::updateRst(
			ListBrlyQUsgList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQUsgList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsgList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsgList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQUsgList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsgList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsgList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQUsgList::loadRecByQref(
			ubigint qref
			, BrlyQUsgList** rec
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

	return loadRecByStmt("TblBrlyQUsgList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQUsgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQUsgList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
