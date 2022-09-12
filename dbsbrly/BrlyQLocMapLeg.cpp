/**
	* \file BrlyQLocMapLeg.cpp
	* Dbs and XML wrapper for table TblBrlyQLocMapLeg (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQLocMapLeg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQLocMapLeg
 ******************************************************************************/

BrlyQLocMapLeg::BrlyQLocMapLeg(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double x1VisLegphi0
			, const double x1VisLegphi1
			, const ubigint mref
			, const string stubMref
			, const ubigint mbgnRefBrlyMLocation
			, const ubigint mendRefBrlyMLocation
			, const double dx
			, const double dy
			, const double x0
			, const double y0
			, const double lam1
			, const double lam2
			, const double lam3
		) {
	this->qref = qref;
	this->qwr = qwr;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1VisLegphi0 = x1VisLegphi0;
	this->x1VisLegphi1 = x1VisLegphi1;
	this->mref = mref;
	this->stubMref = stubMref;
	this->mbgnRefBrlyMLocation = mbgnRefBrlyMLocation;
	this->mendRefBrlyMLocation = mendRefBrlyMLocation;
	this->dx = dx;
	this->dy = dy;
	this->x0 = x0;
	this->y0 = y0;
	this->lam1 = lam1;
	this->lam2 = lam2;
	this->lam3 = lam3;
};

void BrlyQLocMapLeg::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["dx"] = dx;
		me["dy"] = dy;
		me["x0"] = x0;
		me["y0"] = y0;
		me["lm1"] = lam1;
		me["lm2"] = lam2;
		me["lm3"] = lam3;
	} else {
		me["stubMref"] = stubMref;
		me["dx"] = dx;
		me["dy"] = dy;
		me["x0"] = x0;
		me["y0"] = y0;
		me["lam1"] = lam1;
		me["lam2"] = lam2;
		me["lam3"] = lam3;
	};
};

void BrlyQLocMapLeg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLocMapLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeDouble(wr, "dx", dx);
		writeDouble(wr, "dy", dy);
		writeDouble(wr, "x0", x0);
		writeDouble(wr, "y0", y0);
		writeDouble(wr, "lm1", lam1);
		writeDouble(wr, "lm2", lam2);
		writeDouble(wr, "lm3", lam3);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeDouble(wr, "dx", dx);
		writeDouble(wr, "dy", dy);
		writeDouble(wr, "x0", x0);
		writeDouble(wr, "y0", y0);
		writeDouble(wr, "lam1", lam1);
		writeDouble(wr, "lam2", lam2);
		writeDouble(wr, "lam3", lam3);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLocMapLeg
 ******************************************************************************/

ListBrlyQLocMapLeg::ListBrlyQLocMapLeg() {
};

ListBrlyQLocMapLeg::ListBrlyQLocMapLeg(
			const ListBrlyQLocMapLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQLocMapLeg(*(src.nodes[i]));
};

ListBrlyQLocMapLeg::~ListBrlyQLocMapLeg() {
	clear();
};

void ListBrlyQLocMapLeg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLocMapLeg::size() const {
	return(nodes.size());
};

void ListBrlyQLocMapLeg::append(
			BrlyQLocMapLeg* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLocMapLeg& ListBrlyQLocMapLeg::operator=(
			const ListBrlyQLocMapLeg& src
		) {
	BrlyQLocMapLeg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQLocMapLeg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLocMapLeg::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQLocMapLeg";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]->qwr) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQLocMapLeg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLocMapLeg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLocMapLeg
 ******************************************************************************/

TblBrlyQLocMapLeg::TblBrlyQLocMapLeg() {
};

TblBrlyQLocMapLeg::~TblBrlyQLocMapLeg() {
};

bool TblBrlyQLocMapLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocMapLeg** rec
		) {
	return false;
};

ubigint TblBrlyQLocMapLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocMapLeg& rst
		) {
	return 0;
};

ubigint TblBrlyQLocMapLeg::insertRec(
			BrlyQLocMapLeg* rec
		) {
	return 0;
};

ubigint TblBrlyQLocMapLeg::insertNewRec(
			BrlyQLocMapLeg** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double x1VisLegphi0
			, const double x1VisLegphi1
			, const ubigint mref
			, const string stubMref
			, const ubigint mbgnRefBrlyMLocation
			, const ubigint mendRefBrlyMLocation
			, const double dx
			, const double dy
			, const double x0
			, const double y0
			, const double lam1
			, const double lam2
			, const double lam3
		) {
	ubigint retval = 0;
	BrlyQLocMapLeg* _rec = NULL;

	_rec = new BrlyQLocMapLeg(0, qwr, jref, jnum, ref, x1VisLegphi0, x1VisLegphi1, mref, stubMref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0, lam1, lam2, lam3);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLocMapLeg::appendNewRecToRst(
			ListBrlyQLocMapLeg& rst
			, BrlyQLocMapLeg** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double x1VisLegphi0
			, const double x1VisLegphi1
			, const ubigint mref
			, const string stubMref
			, const ubigint mbgnRefBrlyMLocation
			, const ubigint mendRefBrlyMLocation
			, const double dx
			, const double dy
			, const double x0
			, const double y0
			, const double lam1
			, const double lam2
			, const double lam3
		) {
	ubigint retval = 0;
	BrlyQLocMapLeg* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, ref, x1VisLegphi0, x1VisLegphi1, mref, stubMref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0, lam1, lam2, lam3);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLocMapLeg::insertRst(
			ListBrlyQLocMapLeg& rst
		) {
};

void TblBrlyQLocMapLeg::updateRec(
			BrlyQLocMapLeg* rec
		) {
};

void TblBrlyQLocMapLeg::updateRst(
			ListBrlyQLocMapLeg& rst
		) {
};

void TblBrlyQLocMapLeg::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLocMapLeg::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLocMapLeg::loadRecByQref(
			ubigint qref
			, BrlyQLocMapLeg** rec
		) {
	return false;
};

ubigint TblBrlyQLocMapLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocMapLeg& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQLocMapLeg
 ******************************************************************************/

MyTblBrlyQLocMapLeg::MyTblBrlyQLocMapLeg() :
			TblBrlyQLocMapLeg()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLocMapLeg::~MyTblBrlyQLocMapLeg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLocMapLeg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLocMapLeg (qwr, jref, jnum, ref, x1VisLegphi0, x1VisLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0, lam1, lam2, lam3) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLocMapLeg SET qwr = ?, jref = ?, jnum = ?, ref = ?, x1VisLegphi0 = ?, x1VisLegphi1 = ?, mref = ?, mbgnRefBrlyMLocation = ?, mendRefBrlyMLocation = ?, dx = ?, dy = ?, x0 = ?, y0 = ?, lam1 = ?, lam2 = ?, lam3 = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLocMapLeg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLocMapLeg WHERE jref = ?", false);
};

bool MyTblBrlyQLocMapLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocMapLeg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLocMapLeg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLocMapLeg::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLocMapLeg::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLocMapLeg();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1VisLegphi0 = atof((char*) dbrow[5]); else _rec->x1VisLegphi0 = 0.0;
		if (dbrow[6]) _rec->x1VisLegphi1 = atof((char*) dbrow[6]); else _rec->x1VisLegphi1 = 0.0;
		if (dbrow[7]) _rec->mref = atoll((char*) dbrow[7]); else _rec->mref = 0;
		if (dbrow[8]) _rec->mbgnRefBrlyMLocation = atoll((char*) dbrow[8]); else _rec->mbgnRefBrlyMLocation = 0;
		if (dbrow[9]) _rec->mendRefBrlyMLocation = atoll((char*) dbrow[9]); else _rec->mendRefBrlyMLocation = 0;
		if (dbrow[10]) _rec->dx = atof((char*) dbrow[10]); else _rec->dx = 0.0;
		if (dbrow[11]) _rec->dy = atof((char*) dbrow[11]); else _rec->dy = 0.0;
		if (dbrow[12]) _rec->x0 = atof((char*) dbrow[12]); else _rec->x0 = 0.0;
		if (dbrow[13]) _rec->y0 = atof((char*) dbrow[13]); else _rec->y0 = 0.0;
		if (dbrow[14]) _rec->lam1 = atof((char*) dbrow[14]); else _rec->lam1 = 0.0;
		if (dbrow[15]) _rec->lam2 = atof((char*) dbrow[15]); else _rec->lam2 = 0.0;
		if (dbrow[16]) _rec->lam3 = atof((char*) dbrow[16]); else _rec->lam3 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLocMapLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocMapLeg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLocMapLeg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQLocMapLeg::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQLocMapLeg::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLocMapLeg();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1VisLegphi0 = atof((char*) dbrow[5]); else rec->x1VisLegphi0 = 0.0;
			if (dbrow[6]) rec->x1VisLegphi1 = atof((char*) dbrow[6]); else rec->x1VisLegphi1 = 0.0;
			if (dbrow[7]) rec->mref = atoll((char*) dbrow[7]); else rec->mref = 0;
			if (dbrow[8]) rec->mbgnRefBrlyMLocation = atoll((char*) dbrow[8]); else rec->mbgnRefBrlyMLocation = 0;
			if (dbrow[9]) rec->mendRefBrlyMLocation = atoll((char*) dbrow[9]); else rec->mendRefBrlyMLocation = 0;
			if (dbrow[10]) rec->dx = atof((char*) dbrow[10]); else rec->dx = 0.0;
			if (dbrow[11]) rec->dy = atof((char*) dbrow[11]); else rec->dy = 0.0;
			if (dbrow[12]) rec->x0 = atof((char*) dbrow[12]); else rec->x0 = 0.0;
			if (dbrow[13]) rec->y0 = atof((char*) dbrow[13]); else rec->y0 = 0.0;
			if (dbrow[14]) rec->lam1 = atof((char*) dbrow[14]); else rec->lam1 = 0.0;
			if (dbrow[15]) rec->lam2 = atof((char*) dbrow[15]); else rec->lam2 = 0.0;
			if (dbrow[16]) rec->lam3 = atof((char*) dbrow[16]); else rec->lam3 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQLocMapLeg::insertRec(
			BrlyQLocMapLeg* rec
		) {
	unsigned long l[16]; my_bool n[16]; my_bool e[16];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->x1VisLegphi0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x1VisLegphi1,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->mref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->mbgnRefBrlyMLocation,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->mendRefBrlyMLocation,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->dx,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->dy,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->x0,&(l[11]),&(n[11]),&(e[11])),
		bindDouble(&rec->y0,&(l[12]),&(n[12]),&(e[12])),
		bindDouble(&rec->lam1,&(l[13]),&(n[13]),&(e[13])),
		bindDouble(&rec->lam2,&(l[14]),&(n[14]),&(e[14])),
		bindDouble(&rec->lam3,&(l[15]),&(n[15]),&(e[15]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQLocMapLeg::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQLocMapLeg::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQLocMapLeg::insertRst(
			ListBrlyQLocMapLeg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLocMapLeg::updateRec(
			BrlyQLocMapLeg* rec
		) {
	unsigned long l[17]; my_bool n[17]; my_bool e[17];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->x1VisLegphi0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x1VisLegphi1,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->mref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->mbgnRefBrlyMLocation,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->mendRefBrlyMLocation,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->dx,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->dy,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->x0,&(l[11]),&(n[11]),&(e[11])),
		bindDouble(&rec->y0,&(l[12]),&(n[12]),&(e[12])),
		bindDouble(&rec->lam1,&(l[13]),&(n[13]),&(e[13])),
		bindDouble(&rec->lam2,&(l[14]),&(n[14]),&(e[14])),
		bindDouble(&rec->lam3,&(l[15]),&(n[15]),&(e[15])),
		bindUbigint(&rec->qref,&(l[16]),&(n[16]),&(e[16]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQLocMapLeg::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQLocMapLeg::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLocMapLeg::updateRst(
			ListBrlyQLocMapLeg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLocMapLeg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQLocMapLeg::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQLocMapLeg::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQLocMapLeg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQLocMapLeg::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQLocMapLeg::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQLocMapLeg::loadRecByQref(
			ubigint qref
			, BrlyQLocMapLeg** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQLocMapLeg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLocMapLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocMapLeg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLocMapLeg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQLocMapLeg
 ******************************************************************************/

PgTblBrlyQLocMapLeg::PgTblBrlyQLocMapLeg() :
			TblBrlyQLocMapLeg()
			, PgTable()
		{
};

PgTblBrlyQLocMapLeg::~PgTblBrlyQLocMapLeg() {
};

void PgTblBrlyQLocMapLeg::initStatements() {
	createStatement("TblBrlyQLocMapLeg_insertRec", "INSERT INTO TblBrlyQLocMapLeg (qwr, jref, jnum, ref, x1VisLegphi0, x1VisLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0, lam1, lam2, lam3) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16) RETURNING qref", 16);
	createStatement("TblBrlyQLocMapLeg_updateRec", "UPDATE TblBrlyQLocMapLeg SET qwr = $1, jref = $2, jnum = $3, ref = $4, x1VisLegphi0 = $5, x1VisLegphi1 = $6, mref = $7, mbgnRefBrlyMLocation = $8, mendRefBrlyMLocation = $9, dx = $10, dy = $11, x0 = $12, y0 = $13, lam1 = $14, lam2 = $15, lam3 = $16 WHERE qref = $17", 17);
	createStatement("TblBrlyQLocMapLeg_removeRecByQref", "DELETE FROM TblBrlyQLocMapLeg WHERE qref = $1", 1);
	createStatement("TblBrlyQLocMapLeg_removeRstByJref", "DELETE FROM TblBrlyQLocMapLeg WHERE jref = $1", 1);

	createStatement("TblBrlyQLocMapLeg_loadRecByQref", "SELECT qref, qwr, jref, jnum, ref, x1VisLegphi0, x1VisLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0, lam1, lam2, lam3 FROM TblBrlyQLocMapLeg WHERE qref = $1", 1);
	createStatement("TblBrlyQLocMapLeg_loadRstByJref", "SELECT qref, qwr, jref, jnum, ref, x1VisLegphi0, x1VisLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0, lam1, lam2, lam3 FROM TblBrlyQLocMapLeg WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQLocMapLeg::loadRec(
			PGresult* res
			, BrlyQLocMapLeg** rec
		) {
	char* ptr;

	BrlyQLocMapLeg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLocMapLeg();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1vislegphi0"),
			PQfnumber(res, "x1vislegphi1"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "mbgnrefbrlymlocation"),
			PQfnumber(res, "mendrefbrlymlocation"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0"),
			PQfnumber(res, "lam1"),
			PQfnumber(res, "lam2"),
			PQfnumber(res, "lam3")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qwr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1VisLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1VisLegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->mbgnRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->mendRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->dx = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->dy = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->x0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->y0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->lam1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->lam2 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->lam3 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLocMapLeg::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLocMapLeg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLocMapLeg* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1vislegphi0"),
			PQfnumber(res, "x1vislegphi1"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "mbgnrefbrlymlocation"),
			PQfnumber(res, "mendrefbrlymlocation"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0"),
			PQfnumber(res, "lam1"),
			PQfnumber(res, "lam2"),
			PQfnumber(res, "lam3")
		};

		while (numread < numrow) {
			rec = new BrlyQLocMapLeg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1VisLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1VisLegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->mbgnRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->mendRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->dx = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->dy = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->x0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->y0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->lam1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[15]); rec->lam2 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[16]); rec->lam3 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLocMapLeg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLocMapLeg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocMapLeg::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocMapLeg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLocMapLeg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocMapLeg::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLocMapLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocMapLeg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLocMapLeg::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocMapLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocMapLeg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQLocMapLeg::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQLocMapLeg::insertRec(
			BrlyQLocMapLeg* rec
		) {
	PGresult* res;
	char* ptr;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	string _x1VisLegphi0 = to_string(rec->x1VisLegphi0);
	string _x1VisLegphi1 = to_string(rec->x1VisLegphi1);
	ubigint _mref = htonl64(rec->mref);
	ubigint _mbgnRefBrlyMLocation = htonl64(rec->mbgnRefBrlyMLocation);
	ubigint _mendRefBrlyMLocation = htonl64(rec->mendRefBrlyMLocation);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);
	string _x0 = to_string(rec->x0);
	string _y0 = to_string(rec->y0);
	string _lam1 = to_string(rec->lam1);
	string _lam2 = to_string(rec->lam2);
	string _lam3 = to_string(rec->lam3);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		_x1VisLegphi0.c_str(),
		_x1VisLegphi1.c_str(),
		(char*) &_mref,
		(char*) &_mbgnRefBrlyMLocation,
		(char*) &_mendRefBrlyMLocation,
		_dx.c_str(),
		_dy.c_str(),
		_x0.c_str(),
		_y0.c_str(),
		_lam1.c_str(),
		_lam2.c_str(),
		_lam3.c_str()
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLocMapLeg_insertRec", 16, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQLocMapLeg::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQLocMapLeg::insertRst(
			ListBrlyQLocMapLeg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLocMapLeg::updateRec(
			BrlyQLocMapLeg* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	string _x1VisLegphi0 = to_string(rec->x1VisLegphi0);
	string _x1VisLegphi1 = to_string(rec->x1VisLegphi1);
	ubigint _mref = htonl64(rec->mref);
	ubigint _mbgnRefBrlyMLocation = htonl64(rec->mbgnRefBrlyMLocation);
	ubigint _mendRefBrlyMLocation = htonl64(rec->mendRefBrlyMLocation);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);
	string _x0 = to_string(rec->x0);
	string _y0 = to_string(rec->y0);
	string _lam1 = to_string(rec->lam1);
	string _lam2 = to_string(rec->lam2);
	string _lam3 = to_string(rec->lam3);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		_x1VisLegphi0.c_str(),
		_x1VisLegphi1.c_str(),
		(char*) &_mref,
		(char*) &_mbgnRefBrlyMLocation,
		(char*) &_mendRefBrlyMLocation,
		_dx.c_str(),
		_dy.c_str(),
		_x0.c_str(),
		_y0.c_str(),
		_lam1.c_str(),
		_lam2.c_str(),
		_lam3.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLocMapLeg_updateRec", 17, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocMapLeg::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLocMapLeg::updateRst(
			ListBrlyQLocMapLeg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLocMapLeg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocMapLeg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocMapLeg::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQLocMapLeg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocMapLeg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQLocMapLeg::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQLocMapLeg::loadRecByQref(
			ubigint qref
			, BrlyQLocMapLeg** rec
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

	return loadRecByStmt("TblBrlyQLocMapLeg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLocMapLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocMapLeg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLocMapLeg_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
