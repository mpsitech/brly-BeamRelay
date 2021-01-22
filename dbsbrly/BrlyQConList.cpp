/**
	* \file BrlyQConList.cpp
	* Dbs and XML wrapper for table TblBrlyQConList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQConList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQConList
 ******************************************************************************/

BrlyQConList::BrlyQConList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refBrlyMFlight
			, const string stubRefBrlyMFlight
			, const ubigint corRefBrlyMLeg
			, const string stubCorRefBrlyMLeg
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
			, const uint ixVModel
			, const string srefIxVModel
			, const string titIxVModel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->refBrlyMFlight = refBrlyMFlight;
	this->stubRefBrlyMFlight = stubRefBrlyMFlight;
	this->corRefBrlyMLeg = corRefBrlyMLeg;
	this->stubCorRefBrlyMLeg = stubCorRefBrlyMLeg;
	this->start = start;
	this->ftmStart = ftmStart;
	this->stop = stop;
	this->ftmStop = ftmStop;
	this->ixVModel = ixVModel;
	this->srefIxVModel = srefIxVModel;
	this->titIxVModel = titIxVModel;
};

void BrlyQConList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQConList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "flt", stubRefBrlyMFlight);
		writeString(wr, "cor", stubCorRefBrlyMLeg);
		writeString(wr, "sta", ftmStart);
		writeString(wr, "sto", ftmStop);
		writeString(wr, "mod", srefIxVModel);
		writeString(wr, "mod2", titIxVModel);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "stubRefBrlyMFlight", stubRefBrlyMFlight);
		writeString(wr, "stubCorRefBrlyMLeg", stubCorRefBrlyMLeg);
		writeString(wr, "ftmStart", ftmStart);
		writeString(wr, "ftmStop", ftmStop);
		writeString(wr, "srefIxVModel", srefIxVModel);
		writeString(wr, "titIxVModel", titIxVModel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQConList
 ******************************************************************************/

ListBrlyQConList::ListBrlyQConList() {
};

ListBrlyQConList::ListBrlyQConList(
			const ListBrlyQConList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQConList(*(src.nodes[i]));
};

ListBrlyQConList::~ListBrlyQConList() {
	clear();
};

void ListBrlyQConList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQConList::size() const {
	return(nodes.size());
};

void ListBrlyQConList::append(
			BrlyQConList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQConList& ListBrlyQConList::operator=(
			const ListBrlyQConList& src
		) {
	BrlyQConList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQConList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQConList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQConList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQConList
 ******************************************************************************/

TblBrlyQConList::TblBrlyQConList() {
};

TblBrlyQConList::~TblBrlyQConList() {
};

bool TblBrlyQConList::loadRecBySQL(
			const string& sqlstr
			, BrlyQConList** rec
		) {
	return false;
};

ubigint TblBrlyQConList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConList& rst
		) {
	return 0;
};

ubigint TblBrlyQConList::insertRec(
			BrlyQConList* rec
		) {
	return 0;
};

ubigint TblBrlyQConList::insertNewRec(
			BrlyQConList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refBrlyMFlight
			, const string stubRefBrlyMFlight
			, const ubigint corRefBrlyMLeg
			, const string stubCorRefBrlyMLeg
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
			, const uint ixVModel
			, const string srefIxVModel
			, const string titIxVModel
		) {
	ubigint retval = 0;
	BrlyQConList* _rec = NULL;

	_rec = new BrlyQConList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, refBrlyMFlight, stubRefBrlyMFlight, corRefBrlyMLeg, stubCorRefBrlyMLeg, start, ftmStart, stop, ftmStop, ixVModel, srefIxVModel, titIxVModel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQConList::appendNewRecToRst(
			ListBrlyQConList& rst
			, BrlyQConList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refBrlyMFlight
			, const string stubRefBrlyMFlight
			, const ubigint corRefBrlyMLeg
			, const string stubCorRefBrlyMLeg
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
			, const uint ixVModel
			, const string srefIxVModel
			, const string titIxVModel
		) {
	ubigint retval = 0;
	BrlyQConList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, refBrlyMFlight, stubRefBrlyMFlight, corRefBrlyMLeg, stubCorRefBrlyMLeg, start, ftmStart, stop, ftmStop, ixVModel, srefIxVModel, titIxVModel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQConList::insertRst(
			ListBrlyQConList& rst
		) {
};

void TblBrlyQConList::updateRec(
			BrlyQConList* rec
		) {
};

void TblBrlyQConList::updateRst(
			ListBrlyQConList& rst
		) {
};

void TblBrlyQConList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQConList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQConList::loadRecByQref(
			ubigint qref
			, BrlyQConList** rec
		) {
	return false;
};

ubigint TblBrlyQConList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQConList
 ******************************************************************************/

MyTblBrlyQConList::MyTblBrlyQConList() :
			TblBrlyQConList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQConList::~MyTblBrlyQConList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQConList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQConList (jref, jnum, ref, grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQConList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, refBrlyMFlight = ?, corRefBrlyMLeg = ?, start = ?, stop = ?, ixVModel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQConList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQConList WHERE jref = ?", false);
};

bool MyTblBrlyQConList::loadRecBySQL(
			const string& sqlstr
			, BrlyQConList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQConList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQConList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQConList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQConList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->refBrlyMFlight = atoll((char*) dbrow[6]); else _rec->refBrlyMFlight = 0;
		if (dbrow[7]) _rec->corRefBrlyMLeg = atoll((char*) dbrow[7]); else _rec->corRefBrlyMLeg = 0;
		if (dbrow[8]) _rec->start = atol((char*) dbrow[8]); else _rec->start = 0;
		if (dbrow[9]) _rec->stop = atol((char*) dbrow[9]); else _rec->stop = 0;
		if (dbrow[10]) _rec->ixVModel = atol((char*) dbrow[10]); else _rec->ixVModel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQConList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQConList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQConList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQConList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQConList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->refBrlyMFlight = atoll((char*) dbrow[6]); else rec->refBrlyMFlight = 0;
			if (dbrow[7]) rec->corRefBrlyMLeg = atoll((char*) dbrow[7]); else rec->corRefBrlyMLeg = 0;
			if (dbrow[8]) rec->start = atol((char*) dbrow[8]); else rec->start = 0;
			if (dbrow[9]) rec->stop = atol((char*) dbrow[9]); else rec->stop = 0;
			if (dbrow[10]) rec->ixVModel = atol((char*) dbrow[10]); else rec->ixVModel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQConList::insertRec(
			BrlyQConList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMFlight,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->corRefBrlyMLeg,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->stop,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVModel,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQConList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQConList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQConList::insertRst(
			ListBrlyQConList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQConList::updateRec(
			BrlyQConList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMFlight,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->corRefBrlyMLeg,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->stop,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVModel,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQConList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQConList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQConList::updateRst(
			ListBrlyQConList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQConList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQConList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQConList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQConList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQConList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQConList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQConList::loadRecByQref(
			ubigint qref
			, BrlyQConList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQConList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQConList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQConList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQConList
 ******************************************************************************/

PgTblBrlyQConList::PgTblBrlyQConList() :
			TblBrlyQConList()
			, PgTable()
		{
};

PgTblBrlyQConList::~PgTblBrlyQConList() {
};

void PgTblBrlyQConList::initStatements() {
	createStatement("TblBrlyQConList_insertRec", "INSERT INTO TblBrlyQConList (jref, jnum, ref, grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblBrlyQConList_updateRec", "UPDATE TblBrlyQConList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, refBrlyMFlight = $6, corRefBrlyMLeg = $7, start = $8, stop = $9, ixVModel = $10 WHERE qref = $11", 11);
	createStatement("TblBrlyQConList_removeRecByQref", "DELETE FROM TblBrlyQConList WHERE qref = $1", 1);
	createStatement("TblBrlyQConList_removeRstByJref", "DELETE FROM TblBrlyQConList WHERE jref = $1", 1);

	createStatement("TblBrlyQConList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel FROM TblBrlyQConList WHERE qref = $1", 1);
	createStatement("TblBrlyQConList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel FROM TblBrlyQConList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQConList::loadRec(
			PGresult* res
			, BrlyQConList** rec
		) {
	char* ptr;

	BrlyQConList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQConList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refbrlymflight"),
			PQfnumber(res, "correfbrlymleg"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ixvmodel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refBrlyMFlight = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->corRefBrlyMLeg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixVModel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQConList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQConList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQConList* rec;

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
			PQfnumber(res, "refbrlymflight"),
			PQfnumber(res, "correfbrlymleg"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ixvmodel")
		};

		while (numread < numrow) {
			rec = new BrlyQConList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refBrlyMFlight = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->corRefBrlyMLeg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixVModel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQConList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQConList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQConList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQConList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQConList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQConList::loadRecBySQL(
			const string& sqlstr
			, BrlyQConList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQConList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQConList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQConList::insertRec(
			BrlyQConList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refBrlyMFlight = htonl64(rec->refBrlyMFlight);
	ubigint _corRefBrlyMLeg = htonl64(rec->corRefBrlyMLeg);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	uint _ixVModel = htonl(rec->ixVModel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refBrlyMFlight,
		(char*) &_corRefBrlyMLeg,
		(char*) &_start,
		(char*) &_stop,
		(char*) &_ixVModel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQConList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQConList::insertRst(
			ListBrlyQConList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQConList::updateRec(
			BrlyQConList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refBrlyMFlight = htonl64(rec->refBrlyMFlight);
	ubigint _corRefBrlyMLeg = htonl64(rec->corRefBrlyMLeg);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	uint _ixVModel = htonl(rec->ixVModel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refBrlyMFlight,
		(char*) &_corRefBrlyMLeg,
		(char*) &_start,
		(char*) &_stop,
		(char*) &_ixVModel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQConList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQConList::updateRst(
			ListBrlyQConList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQConList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQConList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQConList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQConList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQConList::loadRecByQref(
			ubigint qref
			, BrlyQConList** rec
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

	return loadRecByStmt("TblBrlyQConList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQConList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQConList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
