/**
	* \file BrlyQUsgAAccess.cpp
	* Dbs and XML wrapper for table TblBrlyQUsgAAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQUsgAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQUsgAAccess
 ******************************************************************************/

BrlyQUsgAAccess::BrlyQUsgAAccess(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxBrlyVFeatgroup
			, const string srefX1IxBrlyVFeatgroup
			, const string titX1IxBrlyVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixBrlyWAccess
			, const string srefsIxBrlyWAccess
			, const string titsIxBrlyWAccess
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1IxBrlyVFeatgroup = x1IxBrlyVFeatgroup;
	this->srefX1IxBrlyVFeatgroup = srefX1IxBrlyVFeatgroup;
	this->titX1IxBrlyVFeatgroup = titX1IxBrlyVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixBrlyWAccess = ixBrlyWAccess;
	this->srefsIxBrlyWAccess = srefsIxBrlyWAccess;
	this->titsIxBrlyWAccess = titsIxBrlyWAccess;
};

void BrlyQUsgAAccess::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["feg"] = srefX1IxBrlyVFeatgroup;
		me["feg2"] = titX1IxBrlyVFeatgroup;
		me["fea"] = x2FeaSrefUix;
		me["acc"] = srefsIxBrlyWAccess;
		me["acc2"] = titsIxBrlyWAccess;
	} else {
		me["srefX1IxBrlyVFeatgroup"] = srefX1IxBrlyVFeatgroup;
		me["titX1IxBrlyVFeatgroup"] = titX1IxBrlyVFeatgroup;
		me["x2FeaSrefUix"] = x2FeaSrefUix;
		me["srefsIxBrlyWAccess"] = srefsIxBrlyWAccess;
		me["titsIxBrlyWAccess"] = titsIxBrlyWAccess;
	};
};

void BrlyQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQUsgAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "feg", srefX1IxBrlyVFeatgroup);
		writeString(wr, "feg2", titX1IxBrlyVFeatgroup);
		writeString(wr, "fea", x2FeaSrefUix);
		writeString(wr, "acc", srefsIxBrlyWAccess);
		writeString(wr, "acc2", titsIxBrlyWAccess);
	} else {
		writeString(wr, "srefX1IxBrlyVFeatgroup", srefX1IxBrlyVFeatgroup);
		writeString(wr, "titX1IxBrlyVFeatgroup", titX1IxBrlyVFeatgroup);
		writeString(wr, "x2FeaSrefUix", x2FeaSrefUix);
		writeString(wr, "srefsIxBrlyWAccess", srefsIxBrlyWAccess);
		writeString(wr, "titsIxBrlyWAccess", titsIxBrlyWAccess);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQUsgAAccess
 ******************************************************************************/

ListBrlyQUsgAAccess::ListBrlyQUsgAAccess() {
};

ListBrlyQUsgAAccess::ListBrlyQUsgAAccess(
			const ListBrlyQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQUsgAAccess(*(src.nodes[i]));
};

ListBrlyQUsgAAccess::~ListBrlyQUsgAAccess() {
	clear();
};

void ListBrlyQUsgAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQUsgAAccess::size() const {
	return(nodes.size());
};

void ListBrlyQUsgAAccess::append(
			BrlyQUsgAAccess* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQUsgAAccess& ListBrlyQUsgAAccess::operator=(
			const ListBrlyQUsgAAccess& src
		) {
	BrlyQUsgAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQUsgAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQUsgAAccess::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQUsgAAccess";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQUsgAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQUsgAAccess
 ******************************************************************************/

TblBrlyQUsgAAccess::TblBrlyQUsgAAccess() {
};

TblBrlyQUsgAAccess::~TblBrlyQUsgAAccess() {
};

bool TblBrlyQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgAAccess** rec
		) {
	return false;
};

ubigint TblBrlyQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	return 0;
};

ubigint TblBrlyQUsgAAccess::insertRec(
			BrlyQUsgAAccess* rec
		) {
	return 0;
};

ubigint TblBrlyQUsgAAccess::insertNewRec(
			BrlyQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxBrlyVFeatgroup
			, const string srefX1IxBrlyVFeatgroup
			, const string titX1IxBrlyVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixBrlyWAccess
			, const string srefsIxBrlyWAccess
			, const string titsIxBrlyWAccess
		) {
	ubigint retval = 0;
	BrlyQUsgAAccess* _rec = NULL;

	_rec = new BrlyQUsgAAccess(0, jref, jnum, ref, x1IxBrlyVFeatgroup, srefX1IxBrlyVFeatgroup, titX1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess, srefsIxBrlyWAccess, titsIxBrlyWAccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQUsgAAccess::appendNewRecToRst(
			ListBrlyQUsgAAccess& rst
			, BrlyQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxBrlyVFeatgroup
			, const string srefX1IxBrlyVFeatgroup
			, const string titX1IxBrlyVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixBrlyWAccess
			, const string srefsIxBrlyWAccess
			, const string titsIxBrlyWAccess
		) {
	ubigint retval = 0;
	BrlyQUsgAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxBrlyVFeatgroup, srefX1IxBrlyVFeatgroup, titX1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess, srefsIxBrlyWAccess, titsIxBrlyWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQUsgAAccess::insertRst(
			ListBrlyQUsgAAccess& rst
		) {
};

void TblBrlyQUsgAAccess::updateRec(
			BrlyQUsgAAccess* rec
		) {
};

void TblBrlyQUsgAAccess::updateRst(
			ListBrlyQUsgAAccess& rst
		) {
};

void TblBrlyQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQUsgAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsgAAccess** rec
		) {
	return false;
};

ubigint TblBrlyQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQUsgAAccess
 ******************************************************************************/

MyTblBrlyQUsgAAccess::MyTblBrlyQUsgAAccess() :
			TblBrlyQUsgAAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQUsgAAccess::~MyTblBrlyQUsgAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQUsgAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQUsgAAccess (jref, jnum, ref, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQUsgAAccess SET jref = ?, jnum = ?, ref = ?, x1IxBrlyVFeatgroup = ?, x2FeaSrefUix = ?, ixBrlyWAccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQUsgAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQUsgAAccess WHERE jref = ?", false);
};

bool MyTblBrlyQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQUsgAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQUsgAAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQUsgAAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQUsgAAccess();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxBrlyVFeatgroup = atol((char*) dbrow[4]); else _rec->x1IxBrlyVFeatgroup = 0;
		if (dbrow[5]) _rec->x2FeaSrefUix.assign(dbrow[5], dblengths[5]); else _rec->x2FeaSrefUix = "";
		if (dbrow[6]) _rec->ixBrlyWAccess = atol((char*) dbrow[6]); else _rec->ixBrlyWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQUsgAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQUsgAAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQUsgAAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQUsgAAccess();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxBrlyVFeatgroup = atol((char*) dbrow[4]); else rec->x1IxBrlyVFeatgroup = 0;
			if (dbrow[5]) rec->x2FeaSrefUix.assign(dbrow[5], dblengths[5]); else rec->x2FeaSrefUix = "";
			if (dbrow[6]) rec->ixBrlyWAccess = atol((char*) dbrow[6]); else rec->ixBrlyWAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQUsgAAccess::insertRec(
			BrlyQUsgAAccess* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxBrlyVFeatgroup,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixBrlyWAccess,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQUsgAAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQUsgAAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQUsgAAccess::insertRst(
			ListBrlyQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQUsgAAccess::updateRec(
			BrlyQUsgAAccess* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxBrlyVFeatgroup,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixBrlyWAccess,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQUsgAAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQUsgAAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQUsgAAccess::updateRst(
			ListBrlyQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQUsgAAccess::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQUsgAAccess::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQUsgAAccess::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQUsgAAccess::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQUsgAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsgAAccess** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQUsgAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQUsgAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQUsgAAccess
 ******************************************************************************/

PgTblBrlyQUsgAAccess::PgTblBrlyQUsgAAccess() :
			TblBrlyQUsgAAccess()
			, PgTable()
		{
};

PgTblBrlyQUsgAAccess::~PgTblBrlyQUsgAAccess() {
};

void PgTblBrlyQUsgAAccess::initStatements() {
	createStatement("TblBrlyQUsgAAccess_insertRec", "INSERT INTO TblBrlyQUsgAAccess (jref, jnum, ref, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblBrlyQUsgAAccess_updateRec", "UPDATE TblBrlyQUsgAAccess SET jref = $1, jnum = $2, ref = $3, x1IxBrlyVFeatgroup = $4, x2FeaSrefUix = $5, ixBrlyWAccess = $6 WHERE qref = $7", 7);
	createStatement("TblBrlyQUsgAAccess_removeRecByQref", "DELETE FROM TblBrlyQUsgAAccess WHERE qref = $1", 1);
	createStatement("TblBrlyQUsgAAccess_removeRstByJref", "DELETE FROM TblBrlyQUsgAAccess WHERE jref = $1", 1);

	createStatement("TblBrlyQUsgAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess FROM TblBrlyQUsgAAccess WHERE qref = $1", 1);
	createStatement("TblBrlyQUsgAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess FROM TblBrlyQUsgAAccess WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQUsgAAccess::loadRec(
			PGresult* res
			, BrlyQUsgAAccess** rec
		) {
	char* ptr;

	BrlyQUsgAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQUsgAAccess();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixbrlyvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixbrlywaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1IxBrlyVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixBrlyWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQUsgAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQUsgAAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixbrlyvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixbrlywaccess")
		};

		while (numread < numrow) {
			rec = new BrlyQUsgAAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1IxBrlyVFeatgroup = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixBrlyWAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQUsgAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQUsgAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsgAAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsgAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsgAAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQUsgAAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQUsgAAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQUsgAAccess::insertRec(
			BrlyQUsgAAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxBrlyVFeatgroup = htonl(rec->x1IxBrlyVFeatgroup);
	uint _ixBrlyWAccess = htonl(rec->ixBrlyWAccess);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxBrlyVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixBrlyWAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsgAAccess_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsgAAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQUsgAAccess::insertRst(
			ListBrlyQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQUsgAAccess::updateRec(
			BrlyQUsgAAccess* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxBrlyVFeatgroup = htonl(rec->x1IxBrlyVFeatgroup);
	uint _ixBrlyWAccess = htonl(rec->ixBrlyWAccess);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxBrlyVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixBrlyWAccess,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsgAAccess_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsgAAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQUsgAAccess::updateRst(
			ListBrlyQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQUsgAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsgAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsgAAccess::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQUsgAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsgAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsgAAccess::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQUsgAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsgAAccess** rec
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

	return loadRecByStmt("TblBrlyQUsgAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQUsgAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
