/**
	* \file BrlyQFltEqp1NNode.cpp
	* Dbs and XML wrapper for table TblBrlyQFltEqp1NNode (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQFltEqp1NNode.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQFltEqp1NNode
 ******************************************************************************/

BrlyQFltEqp1NNode::BrlyQFltEqp1NNode(
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

void BrlyQFltEqp1NNode::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQFltEqp1NNode";

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
 class ListBrlyQFltEqp1NNode
 ******************************************************************************/

ListBrlyQFltEqp1NNode::ListBrlyQFltEqp1NNode() {
};

ListBrlyQFltEqp1NNode::ListBrlyQFltEqp1NNode(
			const ListBrlyQFltEqp1NNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQFltEqp1NNode(*(src.nodes[i]));
};

ListBrlyQFltEqp1NNode::~ListBrlyQFltEqp1NNode() {
	clear();
};

void ListBrlyQFltEqp1NNode::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQFltEqp1NNode::size() const {
	return(nodes.size());
};

void ListBrlyQFltEqp1NNode::append(
			BrlyQFltEqp1NNode* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQFltEqp1NNode& ListBrlyQFltEqp1NNode::operator=(
			const ListBrlyQFltEqp1NNode& src
		) {
	BrlyQFltEqp1NNode* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQFltEqp1NNode(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQFltEqp1NNode::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQFltEqp1NNode";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQFltEqp1NNode
 ******************************************************************************/

TblBrlyQFltEqp1NNode::TblBrlyQFltEqp1NNode() {
};

TblBrlyQFltEqp1NNode::~TblBrlyQFltEqp1NNode() {
};

bool TblBrlyQFltEqp1NNode::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltEqp1NNode** rec
		) {
	return false;
};

ubigint TblBrlyQFltEqp1NNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltEqp1NNode& rst
		) {
	return 0;
};

ubigint TblBrlyQFltEqp1NNode::insertRec(
			BrlyQFltEqp1NNode* rec
		) {
	return 0;
};

ubigint TblBrlyQFltEqp1NNode::insertNewRec(
			BrlyQFltEqp1NNode** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQFltEqp1NNode* _rec = NULL;

	_rec = new BrlyQFltEqp1NNode(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQFltEqp1NNode::appendNewRecToRst(
			ListBrlyQFltEqp1NNode& rst
			, BrlyQFltEqp1NNode** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQFltEqp1NNode* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQFltEqp1NNode::insertRst(
			ListBrlyQFltEqp1NNode& rst
		) {
};

void TblBrlyQFltEqp1NNode::updateRec(
			BrlyQFltEqp1NNode* rec
		) {
};

void TblBrlyQFltEqp1NNode::updateRst(
			ListBrlyQFltEqp1NNode& rst
		) {
};

void TblBrlyQFltEqp1NNode::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQFltEqp1NNode::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQFltEqp1NNode::loadRecByQref(
			ubigint qref
			, BrlyQFltEqp1NNode** rec
		) {
	return false;
};

ubigint TblBrlyQFltEqp1NNode::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltEqp1NNode& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQFltEqp1NNode
 ******************************************************************************/

MyTblBrlyQFltEqp1NNode::MyTblBrlyQFltEqp1NNode() :
			TblBrlyQFltEqp1NNode()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQFltEqp1NNode::~MyTblBrlyQFltEqp1NNode() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQFltEqp1NNode::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQFltEqp1NNode (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQFltEqp1NNode SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQFltEqp1NNode WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQFltEqp1NNode WHERE jref = ?", false);
};

bool MyTblBrlyQFltEqp1NNode::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltEqp1NNode** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQFltEqp1NNode* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQFltEqp1NNode::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQFltEqp1NNode::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQFltEqp1NNode();

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

ubigint MyTblBrlyQFltEqp1NNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltEqp1NNode& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQFltEqp1NNode* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQFltEqp1NNode::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQFltEqp1NNode::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQFltEqp1NNode();

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

ubigint MyTblBrlyQFltEqp1NNode::insertRec(
			BrlyQFltEqp1NNode* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQFltEqp1NNode::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQFltEqp1NNode::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQFltEqp1NNode::insertRst(
			ListBrlyQFltEqp1NNode& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQFltEqp1NNode::updateRec(
			BrlyQFltEqp1NNode* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQFltEqp1NNode::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQFltEqp1NNode::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQFltEqp1NNode::updateRst(
			ListBrlyQFltEqp1NNode& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQFltEqp1NNode::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQFltEqp1NNode::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQFltEqp1NNode::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQFltEqp1NNode::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQFltEqp1NNode::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQFltEqp1NNode::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQFltEqp1NNode::loadRecByQref(
			ubigint qref
			, BrlyQFltEqp1NNode** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQFltEqp1NNode WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQFltEqp1NNode::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltEqp1NNode& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQFltEqp1NNode WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQFltEqp1NNode
 ******************************************************************************/

PgTblBrlyQFltEqp1NNode::PgTblBrlyQFltEqp1NNode() :
			TblBrlyQFltEqp1NNode()
			, PgTable()
		{
};

PgTblBrlyQFltEqp1NNode::~PgTblBrlyQFltEqp1NNode() {
};

void PgTblBrlyQFltEqp1NNode::initStatements() {
	createStatement("TblBrlyQFltEqp1NNode_insertRec", "INSERT INTO TblBrlyQFltEqp1NNode (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblBrlyQFltEqp1NNode_updateRec", "UPDATE TblBrlyQFltEqp1NNode SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblBrlyQFltEqp1NNode_removeRecByQref", "DELETE FROM TblBrlyQFltEqp1NNode WHERE qref = $1", 1);
	createStatement("TblBrlyQFltEqp1NNode_removeRstByJref", "DELETE FROM TblBrlyQFltEqp1NNode WHERE jref = $1", 1);

	createStatement("TblBrlyQFltEqp1NNode_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblBrlyQFltEqp1NNode WHERE qref = $1", 1);
	createStatement("TblBrlyQFltEqp1NNode_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblBrlyQFltEqp1NNode WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQFltEqp1NNode::loadRec(
			PGresult* res
			, BrlyQFltEqp1NNode** rec
		) {
	char* ptr;

	BrlyQFltEqp1NNode* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQFltEqp1NNode();

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

ubigint PgTblBrlyQFltEqp1NNode::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQFltEqp1NNode& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQFltEqp1NNode* rec;

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
			rec = new BrlyQFltEqp1NNode();

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

bool PgTblBrlyQFltEqp1NNode::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQFltEqp1NNode** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQFltEqp1NNode::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltEqp1NNode::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQFltEqp1NNode& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQFltEqp1NNode::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQFltEqp1NNode::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltEqp1NNode** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQFltEqp1NNode::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltEqp1NNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltEqp1NNode& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQFltEqp1NNode::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQFltEqp1NNode::insertRec(
			BrlyQFltEqp1NNode* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQFltEqp1NNode_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQFltEqp1NNode::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQFltEqp1NNode::insertRst(
			ListBrlyQFltEqp1NNode& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQFltEqp1NNode::updateRec(
			BrlyQFltEqp1NNode* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQFltEqp1NNode_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQFltEqp1NNode::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQFltEqp1NNode::updateRst(
			ListBrlyQFltEqp1NNode& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQFltEqp1NNode::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFltEqp1NNode_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQFltEqp1NNode::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQFltEqp1NNode::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFltEqp1NNode_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQFltEqp1NNode::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQFltEqp1NNode::loadRecByQref(
			ubigint qref
			, BrlyQFltEqp1NNode** rec
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

	return loadRecByStmt("TblBrlyQFltEqp1NNode_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQFltEqp1NNode::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltEqp1NNode& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQFltEqp1NNode_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
