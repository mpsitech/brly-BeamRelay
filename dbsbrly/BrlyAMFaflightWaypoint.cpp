/**
	* \file BrlyAMFaflightWaypoint.cpp
	* database access for table TblBrlyAMFaflightWaypoint (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyAMFaflightWaypoint.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class BrlyAMFaflightWaypoint
 ******************************************************************************/

BrlyAMFaflightWaypoint::BrlyAMFaflightWaypoint(
			const ubigint ref
			, const ubigint fafRefBrlyMFaflight
			, const uint fafNum
			, const uint timestamp
			, const double latitude
			, const double longitude
			, const usmallint groundspeed
			, const usmallint altitude
			, const string altitudeStatus
			, const string updateType
			, const string altitudeChange
		) {

	this->ref = ref;
	this->fafRefBrlyMFaflight = fafRefBrlyMFaflight;
	this->fafNum = fafNum;
	this->timestamp = timestamp;
	this->latitude = latitude;
	this->longitude = longitude;
	this->groundspeed = groundspeed;
	this->altitude = altitude;
	this->altitudeStatus = altitudeStatus;
	this->updateType = updateType;
	this->altitudeChange = altitudeChange;
};

bool BrlyAMFaflightWaypoint::operator==(
			const BrlyAMFaflightWaypoint& comp
		) {
	return false;
};

bool BrlyAMFaflightWaypoint::operator!=(
			const BrlyAMFaflightWaypoint& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAMFaflightWaypoint
 ******************************************************************************/

ListBrlyAMFaflightWaypoint::ListBrlyAMFaflightWaypoint() {
};

ListBrlyAMFaflightWaypoint::ListBrlyAMFaflightWaypoint(
			const ListBrlyAMFaflightWaypoint& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyAMFaflightWaypoint(*(src.nodes[i]));
};

ListBrlyAMFaflightWaypoint::~ListBrlyAMFaflightWaypoint() {
	clear();
};

void ListBrlyAMFaflightWaypoint::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAMFaflightWaypoint::size() const {
	return(nodes.size());
};

void ListBrlyAMFaflightWaypoint::append(
			BrlyAMFaflightWaypoint* rec
		) {
	nodes.push_back(rec);
};

BrlyAMFaflightWaypoint* ListBrlyAMFaflightWaypoint::operator[](
			const uint ix
		) {
	BrlyAMFaflightWaypoint* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAMFaflightWaypoint& ListBrlyAMFaflightWaypoint::operator=(
			const ListBrlyAMFaflightWaypoint& src
		) {
	BrlyAMFaflightWaypoint* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyAMFaflightWaypoint(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAMFaflightWaypoint::operator==(
			const ListBrlyAMFaflightWaypoint& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListBrlyAMFaflightWaypoint::operator!=(
			const ListBrlyAMFaflightWaypoint& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAMFaflightWaypoint
 ******************************************************************************/

TblBrlyAMFaflightWaypoint::TblBrlyAMFaflightWaypoint() {
};

TblBrlyAMFaflightWaypoint::~TblBrlyAMFaflightWaypoint() {
};

bool TblBrlyAMFaflightWaypoint::loadRecBySQL(
			const string& sqlstr
			, BrlyAMFaflightWaypoint** rec
		) {
	return false;
};

ubigint TblBrlyAMFaflightWaypoint::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMFaflightWaypoint& rst
		) {
	return 0;
};

ubigint TblBrlyAMFaflightWaypoint::insertRec(
			BrlyAMFaflightWaypoint* rec
		) {
	return 0;
};

ubigint TblBrlyAMFaflightWaypoint::insertNewRec(
			BrlyAMFaflightWaypoint** rec
			, const ubigint fafRefBrlyMFaflight
			, const uint fafNum
			, const uint timestamp
			, const double latitude
			, const double longitude
			, const usmallint groundspeed
			, const usmallint altitude
			, const string altitudeStatus
			, const string updateType
			, const string altitudeChange
		) {
	ubigint retval = 0;
	BrlyAMFaflightWaypoint* _rec = NULL;

	_rec = new BrlyAMFaflightWaypoint(0, fafRefBrlyMFaflight, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAMFaflightWaypoint::appendNewRecToRst(
			ListBrlyAMFaflightWaypoint& rst
			, BrlyAMFaflightWaypoint** rec
			, const ubigint fafRefBrlyMFaflight
			, const uint fafNum
			, const uint timestamp
			, const double latitude
			, const double longitude
			, const usmallint groundspeed
			, const usmallint altitude
			, const string altitudeStatus
			, const string updateType
			, const string altitudeChange
		) {
	ubigint retval = 0;
	BrlyAMFaflightWaypoint* _rec = NULL;

	retval = insertNewRec(&_rec, fafRefBrlyMFaflight, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAMFaflightWaypoint::insertRst(
			ListBrlyAMFaflightWaypoint& rst
			, bool transact
		) {
};

void TblBrlyAMFaflightWaypoint::updateRec(
			BrlyAMFaflightWaypoint* rec
		) {
};

void TblBrlyAMFaflightWaypoint::updateRst(
			ListBrlyAMFaflightWaypoint& rst
			, bool transact
		) {
};

void TblBrlyAMFaflightWaypoint::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAMFaflightWaypoint::loadRecByRef(
			ubigint ref
			, BrlyAMFaflightWaypoint** rec
		) {
	return false;
};

ubigint TblBrlyAMFaflightWaypoint::loadRefsByFaf(
			ubigint fafRefBrlyMFaflight
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyAMFaflightWaypoint::loadRstByFaf(
			ubigint fafRefBrlyMFaflight
			, const bool append
			, ListBrlyAMFaflightWaypoint& rst
		) {
	return 0;
};

ubigint TblBrlyAMFaflightWaypoint::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAMFaflightWaypoint& rst
		) {
	ubigint numload = 0;
	BrlyAMFaflightWaypoint* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyAMFaflightWaypoint
 ******************************************************************************/

MyTblBrlyAMFaflightWaypoint::MyTblBrlyAMFaflightWaypoint() :
			TblBrlyAMFaflightWaypoint()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAMFaflightWaypoint::~MyTblBrlyAMFaflightWaypoint() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAMFaflightWaypoint::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAMFaflightWaypoint (fafRefBrlyMFaflight, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAMFaflightWaypoint SET fafRefBrlyMFaflight = ?, fafNum = ?, timestamp = ?, latitude = ?, longitude = ?, groundspeed = ?, altitude = ?, altitudeStatus = ?, updateType = ?, altitudeChange = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAMFaflightWaypoint WHERE ref = ?", false);
};

bool MyTblBrlyAMFaflightWaypoint::loadRecBySQL(
			const string& sqlstr
			, BrlyAMFaflightWaypoint** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAMFaflightWaypoint* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyAMFaflightWaypoint::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyAMFaflightWaypoint::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyAMFaflightWaypoint();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->fafRefBrlyMFaflight = atoll((char*) dbrow[1]); else _rec->fafRefBrlyMFaflight = 0;
		if (dbrow[2]) _rec->fafNum = atol((char*) dbrow[2]); else _rec->fafNum = 0;
		if (dbrow[3]) _rec->timestamp = atol((char*) dbrow[3]); else _rec->timestamp = 0;
		if (dbrow[4]) _rec->latitude = atof((char*) dbrow[4]); else _rec->latitude = 0.0;
		if (dbrow[5]) _rec->longitude = atof((char*) dbrow[5]); else _rec->longitude = 0.0;
		if (dbrow[6]) _rec->groundspeed = atoi((char*) dbrow[6]); else _rec->groundspeed = 0;
		if (dbrow[7]) _rec->altitude = atoi((char*) dbrow[7]); else _rec->altitude = 0;
		if (dbrow[8]) _rec->altitudeStatus.assign(dbrow[8], dblengths[8]); else _rec->altitudeStatus = "";
		if (dbrow[9]) _rec->updateType.assign(dbrow[9], dblengths[9]); else _rec->updateType = "";
		if (dbrow[10]) _rec->altitudeChange.assign(dbrow[10], dblengths[10]); else _rec->altitudeChange = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAMFaflightWaypoint::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMFaflightWaypoint& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAMFaflightWaypoint* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyAMFaflightWaypoint::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyAMFaflightWaypoint::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyAMFaflightWaypoint();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->fafRefBrlyMFaflight = atoll((char*) dbrow[1]); else rec->fafRefBrlyMFaflight = 0;
			if (dbrow[2]) rec->fafNum = atol((char*) dbrow[2]); else rec->fafNum = 0;
			if (dbrow[3]) rec->timestamp = atol((char*) dbrow[3]); else rec->timestamp = 0;
			if (dbrow[4]) rec->latitude = atof((char*) dbrow[4]); else rec->latitude = 0.0;
			if (dbrow[5]) rec->longitude = atof((char*) dbrow[5]); else rec->longitude = 0.0;
			if (dbrow[6]) rec->groundspeed = atoi((char*) dbrow[6]); else rec->groundspeed = 0;
			if (dbrow[7]) rec->altitude = atoi((char*) dbrow[7]); else rec->altitude = 0;
			if (dbrow[8]) rec->altitudeStatus.assign(dbrow[8], dblengths[8]); else rec->altitudeStatus = "";
			if (dbrow[9]) rec->updateType.assign(dbrow[9], dblengths[9]); else rec->updateType = "";
			if (dbrow[10]) rec->altitudeChange.assign(dbrow[10], dblengths[10]); else rec->altitudeChange = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyAMFaflightWaypoint::insertRec(
			BrlyAMFaflightWaypoint* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[7] = rec->altitudeStatus.length();
	l[8] = rec->updateType.length();
	l[9] = rec->altitudeChange.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->fafRefBrlyMFaflight,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->fafNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->timestamp,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->latitude,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->longitude,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->groundspeed,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->altitude,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->altitudeStatus.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->updateType.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->altitudeChange.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyAMFaflightWaypoint::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyAMFaflightWaypoint::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblBrlyAMFaflightWaypoint::insertRst(
			ListBrlyAMFaflightWaypoint& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAMFaflightWaypoint::updateRec(
			BrlyAMFaflightWaypoint* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[7] = rec->altitudeStatus.length();
	l[8] = rec->updateType.length();
	l[9] = rec->altitudeChange.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->fafRefBrlyMFaflight,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->fafNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->timestamp,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->latitude,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->longitude,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->groundspeed,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->altitude,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->altitudeStatus.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->updateType.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->altitudeChange.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyAMFaflightWaypoint::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyAMFaflightWaypoint::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyAMFaflightWaypoint::updateRst(
			ListBrlyAMFaflightWaypoint& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAMFaflightWaypoint::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblBrlyAMFaflightWaypoint::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblBrlyAMFaflightWaypoint::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyAMFaflightWaypoint::loadRecByRef(
			ubigint ref
			, BrlyAMFaflightWaypoint** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyAMFaflightWaypoint WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyAMFaflightWaypoint::loadRefsByFaf(
			ubigint fafRefBrlyMFaflight
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyAMFaflightWaypoint WHERE fafRefBrlyMFaflight = " + to_string(fafRefBrlyMFaflight) + "", append, refs);
};

ubigint MyTblBrlyAMFaflightWaypoint::loadRstByFaf(
			ubigint fafRefBrlyMFaflight
			, const bool append
			, ListBrlyAMFaflightWaypoint& rst
		) {
	return loadRstBySQL("SELECT ref, fafRefBrlyMFaflight, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange FROM TblBrlyAMFaflightWaypoint WHERE fafRefBrlyMFaflight = " + to_string(fafRefBrlyMFaflight) + " ORDER BY fafNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyAMFaflightWaypoint
 ******************************************************************************/

PgTblBrlyAMFaflightWaypoint::PgTblBrlyAMFaflightWaypoint() :
			TblBrlyAMFaflightWaypoint()
			, PgTable()
		{
};

PgTblBrlyAMFaflightWaypoint::~PgTblBrlyAMFaflightWaypoint() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAMFaflightWaypoint::initStatements() {
	createStatement("TblBrlyAMFaflightWaypoint_insertRec", "INSERT INTO TblBrlyAMFaflightWaypoint (fafRefBrlyMFaflight, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10);
	createStatement("TblBrlyAMFaflightWaypoint_updateRec", "UPDATE TblBrlyAMFaflightWaypoint SET fafRefBrlyMFaflight = $1, fafNum = $2, timestamp = $3, latitude = $4, longitude = $5, groundspeed = $6, altitude = $7, altitudeStatus = $8, updateType = $9, altitudeChange = $10 WHERE ref = $11", 11);
	createStatement("TblBrlyAMFaflightWaypoint_removeRecByRef", "DELETE FROM TblBrlyAMFaflightWaypoint WHERE ref = $1", 1);

	createStatement("TblBrlyAMFaflightWaypoint_loadRecByRef", "SELECT ref, fafRefBrlyMFaflight, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange FROM TblBrlyAMFaflightWaypoint WHERE ref = $1", 1);
	createStatement("TblBrlyAMFaflightWaypoint_loadRefsByFaf", "SELECT ref FROM TblBrlyAMFaflightWaypoint WHERE fafRefBrlyMFaflight = $1", 1);
	createStatement("TblBrlyAMFaflightWaypoint_loadRstByFaf", "SELECT ref, fafRefBrlyMFaflight, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange FROM TblBrlyAMFaflightWaypoint WHERE fafRefBrlyMFaflight = $1 ORDER BY fafNum ASC", 1);
};

bool PgTblBrlyAMFaflightWaypoint::loadRec(
			PGresult* res
			, BrlyAMFaflightWaypoint** rec
		) {
	char* ptr;

	BrlyAMFaflightWaypoint* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAMFaflightWaypoint();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "fafrefbrlymfaflight"),
			PQfnumber(res, "fafnum"),
			PQfnumber(res, "timestamp"),
			PQfnumber(res, "latitude"),
			PQfnumber(res, "longitude"),
			PQfnumber(res, "groundspeed"),
			PQfnumber(res, "altitude"),
			PQfnumber(res, "altitudestatus"),
			PQfnumber(res, "updatetype"),
			PQfnumber(res, "altitudechange")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->fafRefBrlyMFaflight = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->fafNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->timestamp = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->latitude = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->longitude = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->groundspeed = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->altitude = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->altitudeStatus.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->updateType.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->altitudeChange.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAMFaflightWaypoint::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAMFaflightWaypoint& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAMFaflightWaypoint* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "fafrefbrlymfaflight"),
			PQfnumber(res, "fafnum"),
			PQfnumber(res, "timestamp"),
			PQfnumber(res, "latitude"),
			PQfnumber(res, "longitude"),
			PQfnumber(res, "groundspeed"),
			PQfnumber(res, "altitude"),
			PQfnumber(res, "altitudestatus"),
			PQfnumber(res, "updatetype"),
			PQfnumber(res, "altitudechange")
		};

		while (numread < numrow) {
			rec = new BrlyAMFaflightWaypoint();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->fafRefBrlyMFaflight = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->fafNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->timestamp = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->latitude = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->longitude = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->groundspeed = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->altitude = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->altitudeStatus.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->updateType.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->altitudeChange.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyAMFaflightWaypoint::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAMFaflightWaypoint** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMFaflightWaypoint::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMFaflightWaypoint::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyAMFaflightWaypoint& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMFaflightWaypoint::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyAMFaflightWaypoint::loadRecBySQL(
			const string& sqlstr
			, BrlyAMFaflightWaypoint** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMFaflightWaypoint::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMFaflightWaypoint::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMFaflightWaypoint& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMFaflightWaypoint::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyAMFaflightWaypoint::insertRec(
			BrlyAMFaflightWaypoint* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _fafRefBrlyMFaflight = htonl64(rec->fafRefBrlyMFaflight);
	uint _fafNum = htonl(rec->fafNum);
	uint _timestamp = htonl(rec->timestamp);
	string _latitude = to_string(rec->latitude);
	string _longitude = to_string(rec->longitude);
	usmallint _groundspeed = htons(rec->groundspeed);
	usmallint _altitude = htons(rec->altitude);

	const char* vals[] = {
		(char*) &_fafRefBrlyMFaflight,
		(char*) &_fafNum,
		(char*) &_timestamp,
		_latitude.c_str(),
		_longitude.c_str(),
		(char*) &_groundspeed,
		(char*) &_altitude,
		rec->altitudeStatus.c_str(),
		rec->updateType.c_str(),
		rec->altitudeChange.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyAMFaflightWaypoint_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyAMFaflightWaypoint::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblBrlyAMFaflightWaypoint::insertRst(
			ListBrlyAMFaflightWaypoint& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAMFaflightWaypoint::updateRec(
			BrlyAMFaflightWaypoint* rec
		) {
	PGresult* res;

	ubigint _fafRefBrlyMFaflight = htonl64(rec->fafRefBrlyMFaflight);
	uint _fafNum = htonl(rec->fafNum);
	uint _timestamp = htonl(rec->timestamp);
	string _latitude = to_string(rec->latitude);
	string _longitude = to_string(rec->longitude);
	usmallint _groundspeed = htons(rec->groundspeed);
	usmallint _altitude = htons(rec->altitude);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_fafRefBrlyMFaflight,
		(char*) &_fafNum,
		(char*) &_timestamp,
		_latitude.c_str(),
		_longitude.c_str(),
		(char*) &_groundspeed,
		(char*) &_altitude,
		rec->altitudeStatus.c_str(),
		rec->updateType.c_str(),
		rec->altitudeChange.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyAMFaflightWaypoint_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyAMFaflightWaypoint::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyAMFaflightWaypoint::updateRst(
			ListBrlyAMFaflightWaypoint& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAMFaflightWaypoint::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyAMFaflightWaypoint_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyAMFaflightWaypoint::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyAMFaflightWaypoint::loadRecByRef(
			ubigint ref
			, BrlyAMFaflightWaypoint** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyAMFaflightWaypoint_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyAMFaflightWaypoint::loadRefsByFaf(
			ubigint fafRefBrlyMFaflight
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _fafRefBrlyMFaflight = htonl64(fafRefBrlyMFaflight);

	const char* vals[] = {
		(char*) &_fafRefBrlyMFaflight
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyAMFaflightWaypoint_loadRefsByFaf", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyAMFaflightWaypoint::loadRstByFaf(
			ubigint fafRefBrlyMFaflight
			, const bool append
			, ListBrlyAMFaflightWaypoint& rst
		) {
	ubigint _fafRefBrlyMFaflight = htonl64(fafRefBrlyMFaflight);

	const char* vals[] = {
		(char*) &_fafRefBrlyMFaflight
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyAMFaflightWaypoint_loadRstByFaf", 1, vals, l, f, append, rst);
};

#endif
