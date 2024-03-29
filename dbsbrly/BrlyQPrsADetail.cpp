/**
	* \file BrlyQPrsADetail.cpp
	* Dbs and XML wrapper for table TblBrlyQPrsADetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQPrsADetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQPrsADetail
 ******************************************************************************/

BrlyQPrsADetail::BrlyQPrsADetail(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1SrefKType = x1SrefKType;
	this->titX1SrefKType = titX1SrefKType;
	this->Val = Val;
};

void BrlyQPrsADetail::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["typ"] = x1SrefKType;
		me["typ2"] = titX1SrefKType;
		me["val"] = Val;
	} else {
		me["x1SrefKType"] = x1SrefKType;
		me["titX1SrefKType"] = titX1SrefKType;
		me["Val"] = Val;
	};
};

void BrlyQPrsADetail::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQPrsADetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "typ", x1SrefKType);
		writeString(wr, "typ2", titX1SrefKType);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "x1SrefKType", x1SrefKType);
		writeString(wr, "titX1SrefKType", titX1SrefKType);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQPrsADetail
 ******************************************************************************/

ListBrlyQPrsADetail::ListBrlyQPrsADetail() {
};

ListBrlyQPrsADetail::ListBrlyQPrsADetail(
			const ListBrlyQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQPrsADetail(*(src.nodes[i]));
};

ListBrlyQPrsADetail::~ListBrlyQPrsADetail() {
	clear();
};

void ListBrlyQPrsADetail::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQPrsADetail::size() const {
	return(nodes.size());
};

void ListBrlyQPrsADetail::append(
			BrlyQPrsADetail* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQPrsADetail& ListBrlyQPrsADetail::operator=(
			const ListBrlyQPrsADetail& src
		) {
	BrlyQPrsADetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQPrsADetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQPrsADetail::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQPrsADetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQPrsADetail::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQPrsADetail";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQPrsADetail
 ******************************************************************************/

TblBrlyQPrsADetail::TblBrlyQPrsADetail() {
};

TblBrlyQPrsADetail::~TblBrlyQPrsADetail() {
};

bool TblBrlyQPrsADetail::loadRecBySQL(
			const string& sqlstr
			, BrlyQPrsADetail** rec
		) {
	return false;
};

ubigint TblBrlyQPrsADetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPrsADetail& rst
		) {
	return 0;
};

ubigint TblBrlyQPrsADetail::insertRec(
			BrlyQPrsADetail* rec
		) {
	return 0;
};

ubigint TblBrlyQPrsADetail::insertNewRec(
			BrlyQPrsADetail** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	BrlyQPrsADetail* _rec = NULL;

	_rec = new BrlyQPrsADetail(0, jref, jnum, ref, x1SrefKType, titX1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQPrsADetail::appendNewRecToRst(
			ListBrlyQPrsADetail& rst
			, BrlyQPrsADetail** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	BrlyQPrsADetail* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1SrefKType, titX1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQPrsADetail::insertRst(
			ListBrlyQPrsADetail& rst
		) {
};

void TblBrlyQPrsADetail::updateRec(
			BrlyQPrsADetail* rec
		) {
};

void TblBrlyQPrsADetail::updateRst(
			ListBrlyQPrsADetail& rst
		) {
};

void TblBrlyQPrsADetail::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQPrsADetail::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQPrsADetail::loadRecByQref(
			ubigint qref
			, BrlyQPrsADetail** rec
		) {
	return false;
};

ubigint TblBrlyQPrsADetail::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPrsADetail& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQPrsADetail
 ******************************************************************************/

MyTblBrlyQPrsADetail::MyTblBrlyQPrsADetail() :
			TblBrlyQPrsADetail()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQPrsADetail::~MyTblBrlyQPrsADetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQPrsADetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQPrsADetail (jref, jnum, ref, x1SrefKType, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQPrsADetail SET jref = ?, jnum = ?, ref = ?, x1SrefKType = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQPrsADetail WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQPrsADetail WHERE jref = ?", false);
};

bool MyTblBrlyQPrsADetail::loadRecBySQL(
			const string& sqlstr
			, BrlyQPrsADetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQPrsADetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQPrsADetail::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQPrsADetail::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQPrsADetail();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1SrefKType.assign(dbrow[4], dblengths[4]); else _rec->x1SrefKType = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQPrsADetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPrsADetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQPrsADetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQPrsADetail::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQPrsADetail::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQPrsADetail();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1SrefKType.assign(dbrow[4], dblengths[4]); else rec->x1SrefKType = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQPrsADetail::insertRec(
			BrlyQPrsADetail* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->x1SrefKType.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQPrsADetail::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQPrsADetail::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQPrsADetail::insertRst(
			ListBrlyQPrsADetail& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQPrsADetail::updateRec(
			BrlyQPrsADetail* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x1SrefKType.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQPrsADetail::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQPrsADetail::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQPrsADetail::updateRst(
			ListBrlyQPrsADetail& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQPrsADetail::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQPrsADetail::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQPrsADetail::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQPrsADetail::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQPrsADetail::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQPrsADetail::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQPrsADetail::loadRecByQref(
			ubigint qref
			, BrlyQPrsADetail** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQPrsADetail WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQPrsADetail::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPrsADetail& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQPrsADetail WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQPrsADetail
 ******************************************************************************/

PgTblBrlyQPrsADetail::PgTblBrlyQPrsADetail() :
			TblBrlyQPrsADetail()
			, PgTable()
		{
};

PgTblBrlyQPrsADetail::~PgTblBrlyQPrsADetail() {
};

void PgTblBrlyQPrsADetail::initStatements() {
	createStatement("TblBrlyQPrsADetail_insertRec", "INSERT INTO TblBrlyQPrsADetail (jref, jnum, ref, x1SrefKType, Val) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblBrlyQPrsADetail_updateRec", "UPDATE TblBrlyQPrsADetail SET jref = $1, jnum = $2, ref = $3, x1SrefKType = $4, Val = $5 WHERE qref = $6", 6);
	createStatement("TblBrlyQPrsADetail_removeRecByQref", "DELETE FROM TblBrlyQPrsADetail WHERE qref = $1", 1);
	createStatement("TblBrlyQPrsADetail_removeRstByJref", "DELETE FROM TblBrlyQPrsADetail WHERE jref = $1", 1);

	createStatement("TblBrlyQPrsADetail_loadRecByQref", "SELECT qref, jref, jnum, ref, x1SrefKType, Val FROM TblBrlyQPrsADetail WHERE qref = $1", 1);
	createStatement("TblBrlyQPrsADetail_loadRstByJref", "SELECT qref, jref, jnum, ref, x1SrefKType, Val FROM TblBrlyQPrsADetail WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQPrsADetail::loadRec(
			PGresult* res
			, BrlyQPrsADetail** rec
		) {
	char* ptr;

	BrlyQPrsADetail* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQPrsADetail();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1SrefKType.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQPrsADetail::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQPrsADetail& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQPrsADetail* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new BrlyQPrsADetail();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1SrefKType.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQPrsADetail::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQPrsADetail** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQPrsADetail::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQPrsADetail::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQPrsADetail& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQPrsADetail::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQPrsADetail::loadRecBySQL(
			const string& sqlstr
			, BrlyQPrsADetail** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQPrsADetail::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQPrsADetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPrsADetail& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQPrsADetail::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQPrsADetail::insertRec(
			BrlyQPrsADetail* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQPrsADetail_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQPrsADetail::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQPrsADetail::insertRst(
			ListBrlyQPrsADetail& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQPrsADetail::updateRec(
			BrlyQPrsADetail* rec
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
		rec->x1SrefKType.c_str(),
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQPrsADetail_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQPrsADetail::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQPrsADetail::updateRst(
			ListBrlyQPrsADetail& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQPrsADetail::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQPrsADetail_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQPrsADetail::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQPrsADetail::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQPrsADetail_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQPrsADetail::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQPrsADetail::loadRecByQref(
			ubigint qref
			, BrlyQPrsADetail** rec
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

	return loadRecByStmt("TblBrlyQPrsADetail_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQPrsADetail::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPrsADetail& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQPrsADetail_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
