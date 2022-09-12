/**
	* \file BrlyQLegList.cpp
	* Dbs and XML wrapper for table TblBrlyQLegList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQLegList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQLegList
 ******************************************************************************/

BrlyQLegList::BrlyQLegList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint bgnRefBrlyMLocation
			, const string stubBgnRefBrlyMLocation
			, const ubigint endRefBrlyMLocation
			, const string stubEndRefBrlyMLocation
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const double alt
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->bgnRefBrlyMLocation = bgnRefBrlyMLocation;
	this->stubBgnRefBrlyMLocation = stubBgnRefBrlyMLocation;
	this->endRefBrlyMLocation = endRefBrlyMLocation;
	this->stubEndRefBrlyMLocation = stubEndRefBrlyMLocation;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->alt = alt;
};

void BrlyQLegList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["grp"] = stubGrp;
		me["own"] = stubOwn;
		me["blo"] = stubBgnRefBrlyMLocation;
		me["elo"] = stubEndRefBrlyMLocation;
		me["typ"] = srefIxVBasetype;
		me["typ2"] = titIxVBasetype;
		me["alt"] = alt;
	} else {
		me["stubGrp"] = stubGrp;
		me["stubOwn"] = stubOwn;
		me["stubBgnRefBrlyMLocation"] = stubBgnRefBrlyMLocation;
		me["stubEndRefBrlyMLocation"] = stubEndRefBrlyMLocation;
		me["srefIxVBasetype"] = srefIxVBasetype;
		me["titIxVBasetype"] = titIxVBasetype;
		me["alt"] = alt;
	};
};

void BrlyQLegList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLegList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "blo", stubBgnRefBrlyMLocation);
		writeString(wr, "elo", stubEndRefBrlyMLocation);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeDouble(wr, "alt", alt);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "stubBgnRefBrlyMLocation", stubBgnRefBrlyMLocation);
		writeString(wr, "stubEndRefBrlyMLocation", stubEndRefBrlyMLocation);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeDouble(wr, "alt", alt);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLegList
 ******************************************************************************/

ListBrlyQLegList::ListBrlyQLegList() {
};

ListBrlyQLegList::ListBrlyQLegList(
			const ListBrlyQLegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQLegList(*(src.nodes[i]));
};

ListBrlyQLegList::~ListBrlyQLegList() {
	clear();
};

void ListBrlyQLegList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLegList::size() const {
	return(nodes.size());
};

void ListBrlyQLegList::append(
			BrlyQLegList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLegList& ListBrlyQLegList::operator=(
			const ListBrlyQLegList& src
		) {
	BrlyQLegList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQLegList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLegList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQLegList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQLegList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLegList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLegList
 ******************************************************************************/

TblBrlyQLegList::TblBrlyQLegList() {
};

TblBrlyQLegList::~TblBrlyQLegList() {
};

bool TblBrlyQLegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegList** rec
		) {
	return false;
};

ubigint TblBrlyQLegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegList& rst
		) {
	return 0;
};

ubigint TblBrlyQLegList::insertRec(
			BrlyQLegList* rec
		) {
	return 0;
};

ubigint TblBrlyQLegList::insertNewRec(
			BrlyQLegList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint bgnRefBrlyMLocation
			, const string stubBgnRefBrlyMLocation
			, const ubigint endRefBrlyMLocation
			, const string stubEndRefBrlyMLocation
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const double alt
		) {
	ubigint retval = 0;
	BrlyQLegList* _rec = NULL;

	_rec = new BrlyQLegList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, bgnRefBrlyMLocation, stubBgnRefBrlyMLocation, endRefBrlyMLocation, stubEndRefBrlyMLocation, ixVBasetype, srefIxVBasetype, titIxVBasetype, alt);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLegList::appendNewRecToRst(
			ListBrlyQLegList& rst
			, BrlyQLegList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint bgnRefBrlyMLocation
			, const string stubBgnRefBrlyMLocation
			, const ubigint endRefBrlyMLocation
			, const string stubEndRefBrlyMLocation
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const double alt
		) {
	ubigint retval = 0;
	BrlyQLegList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, bgnRefBrlyMLocation, stubBgnRefBrlyMLocation, endRefBrlyMLocation, stubEndRefBrlyMLocation, ixVBasetype, srefIxVBasetype, titIxVBasetype, alt);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLegList::insertRst(
			ListBrlyQLegList& rst
		) {
};

void TblBrlyQLegList::updateRec(
			BrlyQLegList* rec
		) {
};

void TblBrlyQLegList::updateRst(
			ListBrlyQLegList& rst
		) {
};

void TblBrlyQLegList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLegList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLegList::loadRecByQref(
			ubigint qref
			, BrlyQLegList** rec
		) {
	return false;
};

ubigint TblBrlyQLegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQLegList
 ******************************************************************************/

MyTblBrlyQLegList::MyTblBrlyQLegList() :
			TblBrlyQLegList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLegList::~MyTblBrlyQLegList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLegList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLegList (jref, jnum, ref, grp, own, bgnRefBrlyMLocation, endRefBrlyMLocation, ixVBasetype, alt) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLegList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, bgnRefBrlyMLocation = ?, endRefBrlyMLocation = ?, ixVBasetype = ?, alt = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLegList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLegList WHERE jref = ?", false);
};

bool MyTblBrlyQLegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLegList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLegList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLegList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLegList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->bgnRefBrlyMLocation = atoll((char*) dbrow[6]); else _rec->bgnRefBrlyMLocation = 0;
		if (dbrow[7]) _rec->endRefBrlyMLocation = atoll((char*) dbrow[7]); else _rec->endRefBrlyMLocation = 0;
		if (dbrow[8]) _rec->ixVBasetype = atol((char*) dbrow[8]); else _rec->ixVBasetype = 0;
		if (dbrow[9]) _rec->alt = atof((char*) dbrow[9]); else _rec->alt = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLegList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLegList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLegList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLegList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->bgnRefBrlyMLocation = atoll((char*) dbrow[6]); else rec->bgnRefBrlyMLocation = 0;
			if (dbrow[7]) rec->endRefBrlyMLocation = atoll((char*) dbrow[7]); else rec->endRefBrlyMLocation = 0;
			if (dbrow[8]) rec->ixVBasetype = atol((char*) dbrow[8]); else rec->ixVBasetype = 0;
			if (dbrow[9]) rec->alt = atof((char*) dbrow[9]); else rec->alt = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQLegList::insertRec(
			BrlyQLegList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->bgnRefBrlyMLocation,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->endRefBrlyMLocation,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVBasetype,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->alt,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQLegList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQLegList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQLegList::insertRst(
			ListBrlyQLegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLegList::updateRec(
			BrlyQLegList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->bgnRefBrlyMLocation,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->endRefBrlyMLocation,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVBasetype,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->alt,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQLegList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQLegList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLegList::updateRst(
			ListBrlyQLegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLegList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQLegList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQLegList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLegList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQLegList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQLegList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQLegList::loadRecByQref(
			ubigint qref
			, BrlyQLegList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQLegList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLegList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQLegList
 ******************************************************************************/

PgTblBrlyQLegList::PgTblBrlyQLegList() :
			TblBrlyQLegList()
			, PgTable()
		{
};

PgTblBrlyQLegList::~PgTblBrlyQLegList() {
};

void PgTblBrlyQLegList::initStatements() {
	createStatement("TblBrlyQLegList_insertRec", "INSERT INTO TblBrlyQLegList (jref, jnum, ref, grp, own, bgnRefBrlyMLocation, endRefBrlyMLocation, ixVBasetype, alt) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblBrlyQLegList_updateRec", "UPDATE TblBrlyQLegList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, bgnRefBrlyMLocation = $6, endRefBrlyMLocation = $7, ixVBasetype = $8, alt = $9 WHERE qref = $10", 10);
	createStatement("TblBrlyQLegList_removeRecByQref", "DELETE FROM TblBrlyQLegList WHERE qref = $1", 1);
	createStatement("TblBrlyQLegList_removeRstByJref", "DELETE FROM TblBrlyQLegList WHERE jref = $1", 1);

	createStatement("TblBrlyQLegList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, bgnRefBrlyMLocation, endRefBrlyMLocation, ixVBasetype, alt FROM TblBrlyQLegList WHERE qref = $1", 1);
	createStatement("TblBrlyQLegList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, bgnRefBrlyMLocation, endRefBrlyMLocation, ixVBasetype, alt FROM TblBrlyQLegList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQLegList::loadRec(
			PGresult* res
			, BrlyQLegList** rec
		) {
	char* ptr;

	BrlyQLegList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLegList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "bgnrefbrlymlocation"),
			PQfnumber(res, "endrefbrlymlocation"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "alt")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->bgnRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->endRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->alt = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLegList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLegList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLegList* rec;

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
			PQfnumber(res, "bgnrefbrlymlocation"),
			PQfnumber(res, "endrefbrlymlocation"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "alt")
		};

		while (numread < numrow) {
			rec = new BrlyQLegList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->bgnRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->endRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->alt = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLegList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLegList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLegList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLegList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLegList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLegList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLegList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQLegList::insertRec(
			BrlyQLegList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _bgnRefBrlyMLocation = htonl64(rec->bgnRefBrlyMLocation);
	ubigint _endRefBrlyMLocation = htonl64(rec->endRefBrlyMLocation);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	string _alt = to_string(rec->alt);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_bgnRefBrlyMLocation,
		(char*) &_endRefBrlyMLocation,
		(char*) &_ixVBasetype,
		_alt.c_str()
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
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLegList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLegList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQLegList::insertRst(
			ListBrlyQLegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLegList::updateRec(
			BrlyQLegList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _bgnRefBrlyMLocation = htonl64(rec->bgnRefBrlyMLocation);
	ubigint _endRefBrlyMLocation = htonl64(rec->endRefBrlyMLocation);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	string _alt = to_string(rec->alt);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_bgnRefBrlyMLocation,
		(char*) &_endRefBrlyMLocation,
		(char*) &_ixVBasetype,
		_alt.c_str(),
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
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLegList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLegList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLegList::updateRst(
			ListBrlyQLegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLegList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLegList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLegList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLegList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQLegList::loadRecByQref(
			ubigint qref
			, BrlyQLegList** rec
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

	return loadRecByStmt("TblBrlyQLegList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLegList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
