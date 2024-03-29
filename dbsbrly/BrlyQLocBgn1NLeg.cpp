/**
	* \file BrlyQLocBgn1NLeg.cpp
	* Dbs and XML wrapper for table TblBrlyQLocBgn1NLeg (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQLocBgn1NLeg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQLocBgn1NLeg
 ******************************************************************************/

BrlyQLocBgn1NLeg::BrlyQLocBgn1NLeg(
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

void BrlyQLocBgn1NLeg::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["ref"] = stubRef;
	} else {
		me["stubRef"] = stubRef;
	};
};

void BrlyQLocBgn1NLeg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLocBgn1NLeg";

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
 class ListBrlyQLocBgn1NLeg
 ******************************************************************************/

ListBrlyQLocBgn1NLeg::ListBrlyQLocBgn1NLeg() {
};

ListBrlyQLocBgn1NLeg::ListBrlyQLocBgn1NLeg(
			const ListBrlyQLocBgn1NLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQLocBgn1NLeg(*(src.nodes[i]));
};

ListBrlyQLocBgn1NLeg::~ListBrlyQLocBgn1NLeg() {
	clear();
};

void ListBrlyQLocBgn1NLeg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLocBgn1NLeg::size() const {
	return(nodes.size());
};

void ListBrlyQLocBgn1NLeg::append(
			BrlyQLocBgn1NLeg* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLocBgn1NLeg& ListBrlyQLocBgn1NLeg::operator=(
			const ListBrlyQLocBgn1NLeg& src
		) {
	BrlyQLocBgn1NLeg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQLocBgn1NLeg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLocBgn1NLeg::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQLocBgn1NLeg";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQLocBgn1NLeg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLocBgn1NLeg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLocBgn1NLeg
 ******************************************************************************/

TblBrlyQLocBgn1NLeg::TblBrlyQLocBgn1NLeg() {
};

TblBrlyQLocBgn1NLeg::~TblBrlyQLocBgn1NLeg() {
};

bool TblBrlyQLocBgn1NLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocBgn1NLeg** rec
		) {
	return false;
};

ubigint TblBrlyQLocBgn1NLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocBgn1NLeg& rst
		) {
	return 0;
};

ubigint TblBrlyQLocBgn1NLeg::insertRec(
			BrlyQLocBgn1NLeg* rec
		) {
	return 0;
};

ubigint TblBrlyQLocBgn1NLeg::insertNewRec(
			BrlyQLocBgn1NLeg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQLocBgn1NLeg* _rec = NULL;

	_rec = new BrlyQLocBgn1NLeg(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLocBgn1NLeg::appendNewRecToRst(
			ListBrlyQLocBgn1NLeg& rst
			, BrlyQLocBgn1NLeg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQLocBgn1NLeg* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLocBgn1NLeg::insertRst(
			ListBrlyQLocBgn1NLeg& rst
		) {
};

void TblBrlyQLocBgn1NLeg::updateRec(
			BrlyQLocBgn1NLeg* rec
		) {
};

void TblBrlyQLocBgn1NLeg::updateRst(
			ListBrlyQLocBgn1NLeg& rst
		) {
};

void TblBrlyQLocBgn1NLeg::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLocBgn1NLeg::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLocBgn1NLeg::loadRecByQref(
			ubigint qref
			, BrlyQLocBgn1NLeg** rec
		) {
	return false;
};

ubigint TblBrlyQLocBgn1NLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocBgn1NLeg& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQLocBgn1NLeg
 ******************************************************************************/

MyTblBrlyQLocBgn1NLeg::MyTblBrlyQLocBgn1NLeg() :
			TblBrlyQLocBgn1NLeg()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLocBgn1NLeg::~MyTblBrlyQLocBgn1NLeg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLocBgn1NLeg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLocBgn1NLeg (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLocBgn1NLeg SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLocBgn1NLeg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLocBgn1NLeg WHERE jref = ?", false);
};

bool MyTblBrlyQLocBgn1NLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocBgn1NLeg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLocBgn1NLeg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLocBgn1NLeg();

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

ubigint MyTblBrlyQLocBgn1NLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocBgn1NLeg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLocBgn1NLeg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLocBgn1NLeg();

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

ubigint MyTblBrlyQLocBgn1NLeg::insertRec(
			BrlyQLocBgn1NLeg* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQLocBgn1NLeg::insertRst(
			ListBrlyQLocBgn1NLeg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLocBgn1NLeg::updateRec(
			BrlyQLocBgn1NLeg* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLocBgn1NLeg::updateRst(
			ListBrlyQLocBgn1NLeg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLocBgn1NLeg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLocBgn1NLeg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQLocBgn1NLeg::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQLocBgn1NLeg::loadRecByQref(
			ubigint qref
			, BrlyQLocBgn1NLeg** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQLocBgn1NLeg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLocBgn1NLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocBgn1NLeg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLocBgn1NLeg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQLocBgn1NLeg
 ******************************************************************************/

PgTblBrlyQLocBgn1NLeg::PgTblBrlyQLocBgn1NLeg() :
			TblBrlyQLocBgn1NLeg()
			, PgTable()
		{
};

PgTblBrlyQLocBgn1NLeg::~PgTblBrlyQLocBgn1NLeg() {
};

void PgTblBrlyQLocBgn1NLeg::initStatements() {
	createStatement("TblBrlyQLocBgn1NLeg_insertRec", "INSERT INTO TblBrlyQLocBgn1NLeg (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblBrlyQLocBgn1NLeg_updateRec", "UPDATE TblBrlyQLocBgn1NLeg SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblBrlyQLocBgn1NLeg_removeRecByQref", "DELETE FROM TblBrlyQLocBgn1NLeg WHERE qref = $1", 1);
	createStatement("TblBrlyQLocBgn1NLeg_removeRstByJref", "DELETE FROM TblBrlyQLocBgn1NLeg WHERE jref = $1", 1);

	createStatement("TblBrlyQLocBgn1NLeg_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblBrlyQLocBgn1NLeg WHERE qref = $1", 1);
	createStatement("TblBrlyQLocBgn1NLeg_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblBrlyQLocBgn1NLeg WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQLocBgn1NLeg::loadRec(
			PGresult* res
			, BrlyQLocBgn1NLeg** rec
		) {
	char* ptr;

	BrlyQLocBgn1NLeg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLocBgn1NLeg();

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

ubigint PgTblBrlyQLocBgn1NLeg::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLocBgn1NLeg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLocBgn1NLeg* rec;

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
			rec = new BrlyQLocBgn1NLeg();

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

bool PgTblBrlyQLocBgn1NLeg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLocBgn1NLeg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocBgn1NLeg::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocBgn1NLeg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLocBgn1NLeg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocBgn1NLeg::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLocBgn1NLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocBgn1NLeg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLocBgn1NLeg::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocBgn1NLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocBgn1NLeg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLocBgn1NLeg::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQLocBgn1NLeg::insertRec(
			BrlyQLocBgn1NLeg* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQLocBgn1NLeg_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocBgn1NLeg::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQLocBgn1NLeg::insertRst(
			ListBrlyQLocBgn1NLeg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLocBgn1NLeg::updateRec(
			BrlyQLocBgn1NLeg* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQLocBgn1NLeg_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocBgn1NLeg::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLocBgn1NLeg::updateRst(
			ListBrlyQLocBgn1NLeg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLocBgn1NLeg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocBgn1NLeg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocBgn1NLeg::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLocBgn1NLeg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocBgn1NLeg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocBgn1NLeg::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQLocBgn1NLeg::loadRecByQref(
			ubigint qref
			, BrlyQLocBgn1NLeg** rec
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

	return loadRecByStmt("TblBrlyQLocBgn1NLeg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLocBgn1NLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocBgn1NLeg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLocBgn1NLeg_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
