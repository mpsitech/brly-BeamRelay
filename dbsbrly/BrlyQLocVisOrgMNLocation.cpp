/**
	* \file BrlyQLocVisOrgMNLocation.cpp
	* Dbs and XML wrapper for table TblBrlyQLocVisOrgMNLocation (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQLocVisOrgMNLocation.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQLocVisOrgMNLocation
 ******************************************************************************/

BrlyQLocVisOrgMNLocation::BrlyQLocVisOrgMNLocation(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
};

void BrlyQLocVisOrgMNLocation::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
	} else {
		me["stubMref"] = stubMref;
	};
};

void BrlyQLocVisOrgMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLocVisOrgMNLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
	} else {
		writeString(wr, "stubMref", stubMref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLocVisOrgMNLocation
 ******************************************************************************/

ListBrlyQLocVisOrgMNLocation::ListBrlyQLocVisOrgMNLocation() {
};

ListBrlyQLocVisOrgMNLocation::ListBrlyQLocVisOrgMNLocation(
			const ListBrlyQLocVisOrgMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQLocVisOrgMNLocation(*(src.nodes[i]));
};

ListBrlyQLocVisOrgMNLocation::~ListBrlyQLocVisOrgMNLocation() {
	clear();
};

void ListBrlyQLocVisOrgMNLocation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLocVisOrgMNLocation::size() const {
	return(nodes.size());
};

void ListBrlyQLocVisOrgMNLocation::append(
			BrlyQLocVisOrgMNLocation* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLocVisOrgMNLocation& ListBrlyQLocVisOrgMNLocation::operator=(
			const ListBrlyQLocVisOrgMNLocation& src
		) {
	BrlyQLocVisOrgMNLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQLocVisOrgMNLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLocVisOrgMNLocation::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQLocVisOrgMNLocation";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQLocVisOrgMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLocVisOrgMNLocation";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLocVisOrgMNLocation
 ******************************************************************************/

TblBrlyQLocVisOrgMNLocation::TblBrlyQLocVisOrgMNLocation() {
};

TblBrlyQLocVisOrgMNLocation::~TblBrlyQLocVisOrgMNLocation() {
};

bool TblBrlyQLocVisOrgMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocVisOrgMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLocVisOrgMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocVisOrgMNLocation& rst
		) {
	return 0;
};

ubigint TblBrlyQLocVisOrgMNLocation::insertRec(
			BrlyQLocVisOrgMNLocation* rec
		) {
	return 0;
};

ubigint TblBrlyQLocVisOrgMNLocation::insertNewRec(
			BrlyQLocVisOrgMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	BrlyQLocVisOrgMNLocation* _rec = NULL;

	_rec = new BrlyQLocVisOrgMNLocation(0, jref, jnum, mref, stubMref, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLocVisOrgMNLocation::appendNewRecToRst(
			ListBrlyQLocVisOrgMNLocation& rst
			, BrlyQLocVisOrgMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	BrlyQLocVisOrgMNLocation* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLocVisOrgMNLocation::insertRst(
			ListBrlyQLocVisOrgMNLocation& rst
		) {
};

void TblBrlyQLocVisOrgMNLocation::updateRec(
			BrlyQLocVisOrgMNLocation* rec
		) {
};

void TblBrlyQLocVisOrgMNLocation::updateRst(
			ListBrlyQLocVisOrgMNLocation& rst
		) {
};

void TblBrlyQLocVisOrgMNLocation::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLocVisOrgMNLocation::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLocVisOrgMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocVisOrgMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLocVisOrgMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocVisOrgMNLocation& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQLocVisOrgMNLocation
 ******************************************************************************/

MyTblBrlyQLocVisOrgMNLocation::MyTblBrlyQLocVisOrgMNLocation() :
			TblBrlyQLocVisOrgMNLocation()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLocVisOrgMNLocation::~MyTblBrlyQLocVisOrgMNLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLocVisOrgMNLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLocVisOrgMNLocation (jref, jnum, mref, ref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLocVisOrgMNLocation SET jref = ?, jnum = ?, mref = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLocVisOrgMNLocation WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLocVisOrgMNLocation WHERE jref = ?", false);
};

bool MyTblBrlyQLocVisOrgMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocVisOrgMNLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLocVisOrgMNLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLocVisOrgMNLocation();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLocVisOrgMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocVisOrgMNLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLocVisOrgMNLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLocVisOrgMNLocation();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQLocVisOrgMNLocation::insertRec(
			BrlyQLocVisOrgMNLocation* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQLocVisOrgMNLocation::insertRst(
			ListBrlyQLocVisOrgMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLocVisOrgMNLocation::updateRec(
			BrlyQLocVisOrgMNLocation* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLocVisOrgMNLocation::updateRst(
			ListBrlyQLocVisOrgMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLocVisOrgMNLocation::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLocVisOrgMNLocation::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQLocVisOrgMNLocation::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQLocVisOrgMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocVisOrgMNLocation** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQLocVisOrgMNLocation WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLocVisOrgMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocVisOrgMNLocation& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLocVisOrgMNLocation WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQLocVisOrgMNLocation
 ******************************************************************************/

PgTblBrlyQLocVisOrgMNLocation::PgTblBrlyQLocVisOrgMNLocation() :
			TblBrlyQLocVisOrgMNLocation()
			, PgTable()
		{
};

PgTblBrlyQLocVisOrgMNLocation::~PgTblBrlyQLocVisOrgMNLocation() {
};

void PgTblBrlyQLocVisOrgMNLocation::initStatements() {
	createStatement("TblBrlyQLocVisOrgMNLocation_insertRec", "INSERT INTO TblBrlyQLocVisOrgMNLocation (jref, jnum, mref, ref) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblBrlyQLocVisOrgMNLocation_updateRec", "UPDATE TblBrlyQLocVisOrgMNLocation SET jref = $1, jnum = $2, mref = $3, ref = $4 WHERE qref = $5", 5);
	createStatement("TblBrlyQLocVisOrgMNLocation_removeRecByQref", "DELETE FROM TblBrlyQLocVisOrgMNLocation WHERE qref = $1", 1);
	createStatement("TblBrlyQLocVisOrgMNLocation_removeRstByJref", "DELETE FROM TblBrlyQLocVisOrgMNLocation WHERE jref = $1", 1);

	createStatement("TblBrlyQLocVisOrgMNLocation_loadRecByQref", "SELECT qref, jref, jnum, mref, ref FROM TblBrlyQLocVisOrgMNLocation WHERE qref = $1", 1);
	createStatement("TblBrlyQLocVisOrgMNLocation_loadRstByJref", "SELECT qref, jref, jnum, mref, ref FROM TblBrlyQLocVisOrgMNLocation WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQLocVisOrgMNLocation::loadRec(
			PGresult* res
			, BrlyQLocVisOrgMNLocation** rec
		) {
	char* ptr;

	BrlyQLocVisOrgMNLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLocVisOrgMNLocation();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLocVisOrgMNLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLocVisOrgMNLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLocVisOrgMNLocation* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new BrlyQLocVisOrgMNLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLocVisOrgMNLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLocVisOrgMNLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocVisOrgMNLocation::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocVisOrgMNLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLocVisOrgMNLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocVisOrgMNLocation::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLocVisOrgMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocVisOrgMNLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLocVisOrgMNLocation::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocVisOrgMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocVisOrgMNLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLocVisOrgMNLocation::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQLocVisOrgMNLocation::insertRec(
			BrlyQLocVisOrgMNLocation* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLocVisOrgMNLocation_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocVisOrgMNLocation::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQLocVisOrgMNLocation::insertRst(
			ListBrlyQLocVisOrgMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLocVisOrgMNLocation::updateRec(
			BrlyQLocVisOrgMNLocation* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLocVisOrgMNLocation_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocVisOrgMNLocation::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLocVisOrgMNLocation::updateRst(
			ListBrlyQLocVisOrgMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLocVisOrgMNLocation::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocVisOrgMNLocation_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocVisOrgMNLocation::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLocVisOrgMNLocation::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocVisOrgMNLocation_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocVisOrgMNLocation::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQLocVisOrgMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocVisOrgMNLocation** rec
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

	return loadRecByStmt("TblBrlyQLocVisOrgMNLocation_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLocVisOrgMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocVisOrgMNLocation& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLocVisOrgMNLocation_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
