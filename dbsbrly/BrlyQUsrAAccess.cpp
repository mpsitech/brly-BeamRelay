/**
	* \file BrlyQUsrAAccess.cpp
	* Dbs and XML wrapper for table TblBrlyQUsrAAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQUsrAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQUsrAAccess
 ******************************************************************************/

BrlyQUsrAAccess::BrlyQUsrAAccess(
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

void BrlyQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQUsrAAccess";

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
 class ListBrlyQUsrAAccess
 ******************************************************************************/

ListBrlyQUsrAAccess::ListBrlyQUsrAAccess() {
};

ListBrlyQUsrAAccess::ListBrlyQUsrAAccess(
			const ListBrlyQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQUsrAAccess(*(src.nodes[i]));
};

ListBrlyQUsrAAccess::~ListBrlyQUsrAAccess() {
	clear();
};

void ListBrlyQUsrAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQUsrAAccess::size() const {
	return(nodes.size());
};

void ListBrlyQUsrAAccess::append(
			BrlyQUsrAAccess* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQUsrAAccess& ListBrlyQUsrAAccess::operator=(
			const ListBrlyQUsrAAccess& src
		) {
	BrlyQUsrAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQUsrAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQUsrAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQUsrAAccess
 ******************************************************************************/

TblBrlyQUsrAAccess::TblBrlyQUsrAAccess() {
};

TblBrlyQUsrAAccess::~TblBrlyQUsrAAccess() {
};

bool TblBrlyQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrAAccess** rec
		) {
	return false;
};

ubigint TblBrlyQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	return 0;
};

ubigint TblBrlyQUsrAAccess::insertRec(
			BrlyQUsrAAccess* rec
		) {
	return 0;
};

ubigint TblBrlyQUsrAAccess::insertNewRec(
			BrlyQUsrAAccess** rec
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
	BrlyQUsrAAccess* _rec = NULL;

	_rec = new BrlyQUsrAAccess(0, jref, jnum, ref, x1IxBrlyVFeatgroup, srefX1IxBrlyVFeatgroup, titX1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess, srefsIxBrlyWAccess, titsIxBrlyWAccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQUsrAAccess::appendNewRecToRst(
			ListBrlyQUsrAAccess& rst
			, BrlyQUsrAAccess** rec
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
	BrlyQUsrAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxBrlyVFeatgroup, srefX1IxBrlyVFeatgroup, titX1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess, srefsIxBrlyWAccess, titsIxBrlyWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQUsrAAccess::insertRst(
			ListBrlyQUsrAAccess& rst
		) {
};

void TblBrlyQUsrAAccess::updateRec(
			BrlyQUsrAAccess* rec
		) {
};

void TblBrlyQUsrAAccess::updateRst(
			ListBrlyQUsrAAccess& rst
		) {
};

void TblBrlyQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQUsrAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsrAAccess** rec
		) {
	return false;
};

ubigint TblBrlyQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQUsrAAccess
 ******************************************************************************/

MyTblBrlyQUsrAAccess::MyTblBrlyQUsrAAccess() :
			TblBrlyQUsrAAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQUsrAAccess::~MyTblBrlyQUsrAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQUsrAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQUsrAAccess (jref, jnum, ref, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQUsrAAccess SET jref = ?, jnum = ?, ref = ?, x1IxBrlyVFeatgroup = ?, x2FeaSrefUix = ?, ixBrlyWAccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQUsrAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQUsrAAccess WHERE jref = ?", false);
};

bool MyTblBrlyQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQUsrAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQUsrAAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQUsrAAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQUsrAAccess();

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

ubigint MyTblBrlyQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQUsrAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQUsrAAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQUsrAAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQUsrAAccess();

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

ubigint MyTblBrlyQUsrAAccess::insertRec(
			BrlyQUsrAAccess* rec
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
		string dbms = "MyTblBrlyQUsrAAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQUsrAAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQUsrAAccess::insertRst(
			ListBrlyQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQUsrAAccess::updateRec(
			BrlyQUsrAAccess* rec
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
		string dbms = "MyTblBrlyQUsrAAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQUsrAAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQUsrAAccess::updateRst(
			ListBrlyQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQUsrAAccess::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQUsrAAccess::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQUsrAAccess::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQUsrAAccess::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQUsrAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsrAAccess** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQUsrAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQUsrAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQUsrAAccess
 ******************************************************************************/

PgTblBrlyQUsrAAccess::PgTblBrlyQUsrAAccess() :
			TblBrlyQUsrAAccess()
			, PgTable()
		{
};

PgTblBrlyQUsrAAccess::~PgTblBrlyQUsrAAccess() {
};

void PgTblBrlyQUsrAAccess::initStatements() {
	createStatement("TblBrlyQUsrAAccess_insertRec", "INSERT INTO TblBrlyQUsrAAccess (jref, jnum, ref, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblBrlyQUsrAAccess_updateRec", "UPDATE TblBrlyQUsrAAccess SET jref = $1, jnum = $2, ref = $3, x1IxBrlyVFeatgroup = $4, x2FeaSrefUix = $5, ixBrlyWAccess = $6 WHERE qref = $7", 7);
	createStatement("TblBrlyQUsrAAccess_removeRecByQref", "DELETE FROM TblBrlyQUsrAAccess WHERE qref = $1", 1);
	createStatement("TblBrlyQUsrAAccess_removeRstByJref", "DELETE FROM TblBrlyQUsrAAccess WHERE jref = $1", 1);

	createStatement("TblBrlyQUsrAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess FROM TblBrlyQUsrAAccess WHERE qref = $1", 1);
	createStatement("TblBrlyQUsrAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxBrlyVFeatgroup, x2FeaSrefUix, ixBrlyWAccess FROM TblBrlyQUsrAAccess WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQUsrAAccess::loadRec(
			PGresult* res
			, BrlyQUsrAAccess** rec
		) {
	char* ptr;

	BrlyQUsrAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQUsrAAccess();

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

ubigint PgTblBrlyQUsrAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQUsrAAccess* rec;

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
			rec = new BrlyQUsrAAccess();

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

bool PgTblBrlyQUsrAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsrAAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsrAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsrAAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQUsrAAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQUsrAAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQUsrAAccess::insertRec(
			BrlyQUsrAAccess* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrAAccess_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQUsrAAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQUsrAAccess::insertRst(
			ListBrlyQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQUsrAAccess::updateRec(
			BrlyQUsrAAccess* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrAAccess_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsrAAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQUsrAAccess::updateRst(
			ListBrlyQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQUsrAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsrAAccess::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQUsrAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQUsrAAccess::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQUsrAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsrAAccess** rec
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

	return loadRecByStmt("TblBrlyQUsrAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQUsrAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
