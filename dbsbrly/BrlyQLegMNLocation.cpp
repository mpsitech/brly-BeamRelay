/**
	* \file BrlyQLegMNLocation.cpp
	* Dbs and XML wrapper for table TblBrlyQLegMNLocation (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQLegMNLocation.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQLegMNLocation
 ******************************************************************************/

BrlyQLegMNLocation::BrlyQLegMNLocation(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double x1VisLegphi0
			, const double x1VisLegphi1
			, const double legphi
			, const double legtheta
			, const double xVisLegphi0
			, const double xVisLegphi1
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->x1VisLegphi0 = x1VisLegphi0;
	this->x1VisLegphi1 = x1VisLegphi1;
	this->legphi = legphi;
	this->legtheta = legtheta;
	this->xVisLegphi0 = xVisLegphi0;
	this->xVisLegphi1 = xVisLegphi1;
};

void BrlyQLegMNLocation::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["lp0"] = x1VisLegphi0;
		me["lp1"] = x1VisLegphi1;
		me["lph"] = legphi;
		me["lth"] = legtheta;
		me["xp0"] = xVisLegphi0;
		me["xp1"] = xVisLegphi1;
	} else {
		me["stubMref"] = stubMref;
		me["x1VisLegphi0"] = x1VisLegphi0;
		me["x1VisLegphi1"] = x1VisLegphi1;
		me["legphi"] = legphi;
		me["legtheta"] = legtheta;
		me["xVisLegphi0"] = xVisLegphi0;
		me["xVisLegphi1"] = xVisLegphi1;
	};
};

void BrlyQLegMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLegMNLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeDouble(wr, "lp0", x1VisLegphi0);
		writeDouble(wr, "lp1", x1VisLegphi1);
		writeDouble(wr, "lph", legphi);
		writeDouble(wr, "lth", legtheta);
		writeDouble(wr, "xp0", xVisLegphi0);
		writeDouble(wr, "xp1", xVisLegphi1);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeDouble(wr, "x1VisLegphi0", x1VisLegphi0);
		writeDouble(wr, "x1VisLegphi1", x1VisLegphi1);
		writeDouble(wr, "legphi", legphi);
		writeDouble(wr, "legtheta", legtheta);
		writeDouble(wr, "xVisLegphi0", xVisLegphi0);
		writeDouble(wr, "xVisLegphi1", xVisLegphi1);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLegMNLocation
 ******************************************************************************/

ListBrlyQLegMNLocation::ListBrlyQLegMNLocation() {
};

ListBrlyQLegMNLocation::ListBrlyQLegMNLocation(
			const ListBrlyQLegMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQLegMNLocation(*(src.nodes[i]));
};

ListBrlyQLegMNLocation::~ListBrlyQLegMNLocation() {
	clear();
};

void ListBrlyQLegMNLocation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLegMNLocation::size() const {
	return(nodes.size());
};

void ListBrlyQLegMNLocation::append(
			BrlyQLegMNLocation* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLegMNLocation& ListBrlyQLegMNLocation::operator=(
			const ListBrlyQLegMNLocation& src
		) {
	BrlyQLegMNLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQLegMNLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLegMNLocation::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQLegMNLocation";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQLegMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLegMNLocation";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLegMNLocation
 ******************************************************************************/

TblBrlyQLegMNLocation::TblBrlyQLegMNLocation() {
};

TblBrlyQLegMNLocation::~TblBrlyQLegMNLocation() {
};

bool TblBrlyQLegMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLegMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegMNLocation& rst
		) {
	return 0;
};

ubigint TblBrlyQLegMNLocation::insertRec(
			BrlyQLegMNLocation* rec
		) {
	return 0;
};

ubigint TblBrlyQLegMNLocation::insertNewRec(
			BrlyQLegMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double x1VisLegphi0
			, const double x1VisLegphi1
			, const double legphi
			, const double legtheta
			, const double xVisLegphi0
			, const double xVisLegphi1
		) {
	ubigint retval = 0;
	BrlyQLegMNLocation* _rec = NULL;

	_rec = new BrlyQLegMNLocation(0, jref, jnum, mref, stubMref, ref, x1VisLegphi0, x1VisLegphi1, legphi, legtheta, xVisLegphi0, xVisLegphi1);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLegMNLocation::appendNewRecToRst(
			ListBrlyQLegMNLocation& rst
			, BrlyQLegMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double x1VisLegphi0
			, const double x1VisLegphi1
			, const double legphi
			, const double legtheta
			, const double xVisLegphi0
			, const double xVisLegphi1
		) {
	ubigint retval = 0;
	BrlyQLegMNLocation* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1VisLegphi0, x1VisLegphi1, legphi, legtheta, xVisLegphi0, xVisLegphi1);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLegMNLocation::insertRst(
			ListBrlyQLegMNLocation& rst
		) {
};

void TblBrlyQLegMNLocation::updateRec(
			BrlyQLegMNLocation* rec
		) {
};

void TblBrlyQLegMNLocation::updateRst(
			ListBrlyQLegMNLocation& rst
		) {
};

void TblBrlyQLegMNLocation::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLegMNLocation::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLegMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLegMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLegMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegMNLocation& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQLegMNLocation
 ******************************************************************************/

MyTblBrlyQLegMNLocation::MyTblBrlyQLegMNLocation() :
			TblBrlyQLegMNLocation()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLegMNLocation::~MyTblBrlyQLegMNLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLegMNLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLegMNLocation (jref, jnum, mref, ref, x1VisLegphi0, x1VisLegphi1, legphi, legtheta, xVisLegphi0, xVisLegphi1) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLegMNLocation SET jref = ?, jnum = ?, mref = ?, ref = ?, x1VisLegphi0 = ?, x1VisLegphi1 = ?, legphi = ?, legtheta = ?, xVisLegphi0 = ?, xVisLegphi1 = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLegMNLocation WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLegMNLocation WHERE jref = ?", false);
};

bool MyTblBrlyQLegMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegMNLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLegMNLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLegMNLocation::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLegMNLocation::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLegMNLocation();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1VisLegphi0 = atof((char*) dbrow[5]); else _rec->x1VisLegphi0 = 0.0;
		if (dbrow[6]) _rec->x1VisLegphi1 = atof((char*) dbrow[6]); else _rec->x1VisLegphi1 = 0.0;
		if (dbrow[7]) _rec->legphi = atof((char*) dbrow[7]); else _rec->legphi = 0.0;
		if (dbrow[8]) _rec->legtheta = atof((char*) dbrow[8]); else _rec->legtheta = 0.0;
		if (dbrow[9]) _rec->xVisLegphi0 = atof((char*) dbrow[9]); else _rec->xVisLegphi0 = 0.0;
		if (dbrow[10]) _rec->xVisLegphi1 = atof((char*) dbrow[10]); else _rec->xVisLegphi1 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLegMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegMNLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLegMNLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLegMNLocation::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLegMNLocation::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLegMNLocation();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1VisLegphi0 = atof((char*) dbrow[5]); else rec->x1VisLegphi0 = 0.0;
			if (dbrow[6]) rec->x1VisLegphi1 = atof((char*) dbrow[6]); else rec->x1VisLegphi1 = 0.0;
			if (dbrow[7]) rec->legphi = atof((char*) dbrow[7]); else rec->legphi = 0.0;
			if (dbrow[8]) rec->legtheta = atof((char*) dbrow[8]); else rec->legtheta = 0.0;
			if (dbrow[9]) rec->xVisLegphi0 = atof((char*) dbrow[9]); else rec->xVisLegphi0 = 0.0;
			if (dbrow[10]) rec->xVisLegphi1 = atof((char*) dbrow[10]); else rec->xVisLegphi1 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQLegMNLocation::insertRec(
			BrlyQLegMNLocation* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->x1VisLegphi0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x1VisLegphi1,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->legphi,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->legtheta,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->xVisLegphi0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->xVisLegphi1,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQLegMNLocation::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQLegMNLocation::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQLegMNLocation::insertRst(
			ListBrlyQLegMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLegMNLocation::updateRec(
			BrlyQLegMNLocation* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->x1VisLegphi0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x1VisLegphi1,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->legphi,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->legtheta,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->xVisLegphi0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->xVisLegphi1,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQLegMNLocation::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQLegMNLocation::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLegMNLocation::updateRst(
			ListBrlyQLegMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLegMNLocation::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQLegMNLocation::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQLegMNLocation::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLegMNLocation::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQLegMNLocation::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQLegMNLocation::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQLegMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLegMNLocation** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQLegMNLocation WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLegMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegMNLocation& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLegMNLocation WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQLegMNLocation
 ******************************************************************************/

PgTblBrlyQLegMNLocation::PgTblBrlyQLegMNLocation() :
			TblBrlyQLegMNLocation()
			, PgTable()
		{
};

PgTblBrlyQLegMNLocation::~PgTblBrlyQLegMNLocation() {
};

void PgTblBrlyQLegMNLocation::initStatements() {
	createStatement("TblBrlyQLegMNLocation_insertRec", "INSERT INTO TblBrlyQLegMNLocation (jref, jnum, mref, ref, x1VisLegphi0, x1VisLegphi1, legphi, legtheta, xVisLegphi0, xVisLegphi1) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblBrlyQLegMNLocation_updateRec", "UPDATE TblBrlyQLegMNLocation SET jref = $1, jnum = $2, mref = $3, ref = $4, x1VisLegphi0 = $5, x1VisLegphi1 = $6, legphi = $7, legtheta = $8, xVisLegphi0 = $9, xVisLegphi1 = $10 WHERE qref = $11", 11);
	createStatement("TblBrlyQLegMNLocation_removeRecByQref", "DELETE FROM TblBrlyQLegMNLocation WHERE qref = $1", 1);
	createStatement("TblBrlyQLegMNLocation_removeRstByJref", "DELETE FROM TblBrlyQLegMNLocation WHERE jref = $1", 1);

	createStatement("TblBrlyQLegMNLocation_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1VisLegphi0, x1VisLegphi1, legphi, legtheta, xVisLegphi0, xVisLegphi1 FROM TblBrlyQLegMNLocation WHERE qref = $1", 1);
	createStatement("TblBrlyQLegMNLocation_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1VisLegphi0, x1VisLegphi1, legphi, legtheta, xVisLegphi0, xVisLegphi1 FROM TblBrlyQLegMNLocation WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQLegMNLocation::loadRec(
			PGresult* res
			, BrlyQLegMNLocation** rec
		) {
	char* ptr;

	BrlyQLegMNLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLegMNLocation();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1vislegphi0"),
			PQfnumber(res, "x1vislegphi1"),
			PQfnumber(res, "legphi"),
			PQfnumber(res, "legtheta"),
			PQfnumber(res, "xvislegphi0"),
			PQfnumber(res, "xvislegphi1")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1VisLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1VisLegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->legphi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->legtheta = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->xVisLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->xVisLegphi1 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLegMNLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLegMNLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLegMNLocation* rec;

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
			PQfnumber(res, "x1vislegphi0"),
			PQfnumber(res, "x1vislegphi1"),
			PQfnumber(res, "legphi"),
			PQfnumber(res, "legtheta"),
			PQfnumber(res, "xvislegphi0"),
			PQfnumber(res, "xvislegphi1")
		};

		while (numread < numrow) {
			rec = new BrlyQLegMNLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1VisLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1VisLegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->legphi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->legtheta = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->xVisLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->xVisLegphi1 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLegMNLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLegMNLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLegMNLocation::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegMNLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLegMNLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLegMNLocation::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLegMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegMNLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLegMNLocation::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegMNLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLegMNLocation::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQLegMNLocation::insertRec(
			BrlyQLegMNLocation* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	string _x1VisLegphi0 = to_string(rec->x1VisLegphi0);
	string _x1VisLegphi1 = to_string(rec->x1VisLegphi1);
	string _legphi = to_string(rec->legphi);
	string _legtheta = to_string(rec->legtheta);
	string _xVisLegphi0 = to_string(rec->xVisLegphi0);
	string _xVisLegphi1 = to_string(rec->xVisLegphi1);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		_x1VisLegphi0.c_str(),
		_x1VisLegphi1.c_str(),
		_legphi.c_str(),
		_legtheta.c_str(),
		_xVisLegphi0.c_str(),
		_xVisLegphi1.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLegMNLocation_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLegMNLocation::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQLegMNLocation::insertRst(
			ListBrlyQLegMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLegMNLocation::updateRec(
			BrlyQLegMNLocation* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	string _x1VisLegphi0 = to_string(rec->x1VisLegphi0);
	string _x1VisLegphi1 = to_string(rec->x1VisLegphi1);
	string _legphi = to_string(rec->legphi);
	string _legtheta = to_string(rec->legtheta);
	string _xVisLegphi0 = to_string(rec->xVisLegphi0);
	string _xVisLegphi1 = to_string(rec->xVisLegphi1);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		_x1VisLegphi0.c_str(),
		_x1VisLegphi1.c_str(),
		_legphi.c_str(),
		_legtheta.c_str(),
		_xVisLegphi0.c_str(),
		_xVisLegphi1.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLegMNLocation_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLegMNLocation::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLegMNLocation::updateRst(
			ListBrlyQLegMNLocation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLegMNLocation::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegMNLocation_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLegMNLocation::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLegMNLocation::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegMNLocation_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLegMNLocation::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQLegMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLegMNLocation** rec
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

	return loadRecByStmt("TblBrlyQLegMNLocation_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLegMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegMNLocation& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLegMNLocation_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
