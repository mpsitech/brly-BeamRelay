/**
	* \file BrlyQLocEqpMNConnection.cpp
	* Dbs and XML wrapper for table TblBrlyQLocEqpMNConnection (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQLocEqpMNConnection.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQLocEqpMNConnection
 ******************************************************************************/

BrlyQLocEqpMNConnection::BrlyQLocEqpMNConnection(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint conIxBrlyVLat
			, const string srefConIxBrlyVLat
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->conIxBrlyVLat = conIxBrlyVLat;
	this->srefConIxBrlyVLat = srefConIxBrlyVLat;
};

void BrlyQLocEqpMNConnection::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["lat"] = srefConIxBrlyVLat;
	} else {
		me["stubMref"] = stubMref;
		me["srefConIxBrlyVLat"] = srefConIxBrlyVLat;
	};
};

void BrlyQLocEqpMNConnection::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLocEqpMNConnection";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "lat", srefConIxBrlyVLat);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefConIxBrlyVLat", srefConIxBrlyVLat);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLocEqpMNConnection
 ******************************************************************************/

ListBrlyQLocEqpMNConnection::ListBrlyQLocEqpMNConnection() {
};

ListBrlyQLocEqpMNConnection::ListBrlyQLocEqpMNConnection(
			const ListBrlyQLocEqpMNConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQLocEqpMNConnection(*(src.nodes[i]));
};

ListBrlyQLocEqpMNConnection::~ListBrlyQLocEqpMNConnection() {
	clear();
};

void ListBrlyQLocEqpMNConnection::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLocEqpMNConnection::size() const {
	return(nodes.size());
};

void ListBrlyQLocEqpMNConnection::append(
			BrlyQLocEqpMNConnection* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLocEqpMNConnection& ListBrlyQLocEqpMNConnection::operator=(
			const ListBrlyQLocEqpMNConnection& src
		) {
	BrlyQLocEqpMNConnection* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQLocEqpMNConnection(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLocEqpMNConnection::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQLocEqpMNConnection";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQLocEqpMNConnection::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLocEqpMNConnection";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLocEqpMNConnection
 ******************************************************************************/

TblBrlyQLocEqpMNConnection::TblBrlyQLocEqpMNConnection() {
};

TblBrlyQLocEqpMNConnection::~TblBrlyQLocEqpMNConnection() {
};

bool TblBrlyQLocEqpMNConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocEqpMNConnection** rec
		) {
	return false;
};

ubigint TblBrlyQLocEqpMNConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocEqpMNConnection& rst
		) {
	return 0;
};

ubigint TblBrlyQLocEqpMNConnection::insertRec(
			BrlyQLocEqpMNConnection* rec
		) {
	return 0;
};

ubigint TblBrlyQLocEqpMNConnection::insertNewRec(
			BrlyQLocEqpMNConnection** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint conIxBrlyVLat
			, const string srefConIxBrlyVLat
		) {
	ubigint retval = 0;
	BrlyQLocEqpMNConnection* _rec = NULL;

	_rec = new BrlyQLocEqpMNConnection(0, jref, jnum, mref, stubMref, ref, conIxBrlyVLat, srefConIxBrlyVLat);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLocEqpMNConnection::appendNewRecToRst(
			ListBrlyQLocEqpMNConnection& rst
			, BrlyQLocEqpMNConnection** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint conIxBrlyVLat
			, const string srefConIxBrlyVLat
		) {
	ubigint retval = 0;
	BrlyQLocEqpMNConnection* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, conIxBrlyVLat, srefConIxBrlyVLat);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLocEqpMNConnection::insertRst(
			ListBrlyQLocEqpMNConnection& rst
		) {
};

void TblBrlyQLocEqpMNConnection::updateRec(
			BrlyQLocEqpMNConnection* rec
		) {
};

void TblBrlyQLocEqpMNConnection::updateRst(
			ListBrlyQLocEqpMNConnection& rst
		) {
};

void TblBrlyQLocEqpMNConnection::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLocEqpMNConnection::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLocEqpMNConnection::loadRecByQref(
			ubigint qref
			, BrlyQLocEqpMNConnection** rec
		) {
	return false;
};

ubigint TblBrlyQLocEqpMNConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocEqpMNConnection& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQLocEqpMNConnection
 ******************************************************************************/

MyTblBrlyQLocEqpMNConnection::MyTblBrlyQLocEqpMNConnection() :
			TblBrlyQLocEqpMNConnection()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLocEqpMNConnection::~MyTblBrlyQLocEqpMNConnection() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLocEqpMNConnection::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLocEqpMNConnection (jref, jnum, mref, ref, conIxBrlyVLat) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLocEqpMNConnection SET jref = ?, jnum = ?, mref = ?, ref = ?, conIxBrlyVLat = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLocEqpMNConnection WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLocEqpMNConnection WHERE jref = ?", false);
};

bool MyTblBrlyQLocEqpMNConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocEqpMNConnection** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLocEqpMNConnection* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLocEqpMNConnection();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->conIxBrlyVLat = atol((char*) dbrow[5]); else _rec->conIxBrlyVLat = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLocEqpMNConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocEqpMNConnection& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLocEqpMNConnection* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLocEqpMNConnection();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->conIxBrlyVLat = atol((char*) dbrow[5]); else rec->conIxBrlyVLat = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQLocEqpMNConnection::insertRec(
			BrlyQLocEqpMNConnection* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->conIxBrlyVLat,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQLocEqpMNConnection::insertRst(
			ListBrlyQLocEqpMNConnection& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLocEqpMNConnection::updateRec(
			BrlyQLocEqpMNConnection* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->conIxBrlyVLat,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLocEqpMNConnection::updateRst(
			ListBrlyQLocEqpMNConnection& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLocEqpMNConnection::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLocEqpMNConnection::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQLocEqpMNConnection::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQLocEqpMNConnection::loadRecByQref(
			ubigint qref
			, BrlyQLocEqpMNConnection** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQLocEqpMNConnection WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLocEqpMNConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocEqpMNConnection& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLocEqpMNConnection WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQLocEqpMNConnection
 ******************************************************************************/

PgTblBrlyQLocEqpMNConnection::PgTblBrlyQLocEqpMNConnection() :
			TblBrlyQLocEqpMNConnection()
			, PgTable()
		{
};

PgTblBrlyQLocEqpMNConnection::~PgTblBrlyQLocEqpMNConnection() {
};

void PgTblBrlyQLocEqpMNConnection::initStatements() {
	createStatement("TblBrlyQLocEqpMNConnection_insertRec", "INSERT INTO TblBrlyQLocEqpMNConnection (jref, jnum, mref, ref, conIxBrlyVLat) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblBrlyQLocEqpMNConnection_updateRec", "UPDATE TblBrlyQLocEqpMNConnection SET jref = $1, jnum = $2, mref = $3, ref = $4, conIxBrlyVLat = $5 WHERE qref = $6", 6);
	createStatement("TblBrlyQLocEqpMNConnection_removeRecByQref", "DELETE FROM TblBrlyQLocEqpMNConnection WHERE qref = $1", 1);
	createStatement("TblBrlyQLocEqpMNConnection_removeRstByJref", "DELETE FROM TblBrlyQLocEqpMNConnection WHERE jref = $1", 1);

	createStatement("TblBrlyQLocEqpMNConnection_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, conIxBrlyVLat FROM TblBrlyQLocEqpMNConnection WHERE qref = $1", 1);
	createStatement("TblBrlyQLocEqpMNConnection_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, conIxBrlyVLat FROM TblBrlyQLocEqpMNConnection WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQLocEqpMNConnection::loadRec(
			PGresult* res
			, BrlyQLocEqpMNConnection** rec
		) {
	char* ptr;

	BrlyQLocEqpMNConnection* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLocEqpMNConnection();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "conixbrlyvlat")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->conIxBrlyVLat = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLocEqpMNConnection::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLocEqpMNConnection& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLocEqpMNConnection* rec;

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
			PQfnumber(res, "conixbrlyvlat")
		};

		while (numread < numrow) {
			rec = new BrlyQLocEqpMNConnection();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->conIxBrlyVLat = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLocEqpMNConnection::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLocEqpMNConnection** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocEqpMNConnection::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocEqpMNConnection::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLocEqpMNConnection& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocEqpMNConnection::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLocEqpMNConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocEqpMNConnection** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLocEqpMNConnection::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocEqpMNConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocEqpMNConnection& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLocEqpMNConnection::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQLocEqpMNConnection::insertRec(
			BrlyQLocEqpMNConnection* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _conIxBrlyVLat = htonl(rec->conIxBrlyVLat);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_conIxBrlyVLat
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLocEqpMNConnection_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocEqpMNConnection::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQLocEqpMNConnection::insertRst(
			ListBrlyQLocEqpMNConnection& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLocEqpMNConnection::updateRec(
			BrlyQLocEqpMNConnection* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _conIxBrlyVLat = htonl(rec->conIxBrlyVLat);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_conIxBrlyVLat,
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

	res = PQexecPrepared(dbs, "TblBrlyQLocEqpMNConnection_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocEqpMNConnection::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLocEqpMNConnection::updateRst(
			ListBrlyQLocEqpMNConnection& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLocEqpMNConnection::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocEqpMNConnection_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocEqpMNConnection::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLocEqpMNConnection::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocEqpMNConnection_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocEqpMNConnection::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQLocEqpMNConnection::loadRecByQref(
			ubigint qref
			, BrlyQLocEqpMNConnection** rec
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

	return loadRecByStmt("TblBrlyQLocEqpMNConnection_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLocEqpMNConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocEqpMNConnection& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLocEqpMNConnection_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
