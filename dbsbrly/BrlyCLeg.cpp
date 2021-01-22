/**
	* \file BrlyCLeg.cpp
	* Dbs and XML wrapper for table TblBrlyCLeg (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyCLeg.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblBrlyCLeg
 ******************************************************************************/

TblBrlyCLeg::TblBrlyCLeg() {
};

TblBrlyCLeg::~TblBrlyCLeg() {
};

ubigint TblBrlyCLeg::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyCLeg
 ******************************************************************************/

MyTblBrlyCLeg::MyTblBrlyCLeg() :
			TblBrlyCLeg()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblBrlyCLeg::~MyTblBrlyCLeg() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblBrlyCLeg::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblBrlyCLeg () VALUES ()", false);
};

ubigint MyTblBrlyCLeg::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblBrlyCLeg::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblBrlyCLeg::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyCLeg
 ******************************************************************************/

PgTblBrlyCLeg::PgTblBrlyCLeg() :
			TblBrlyCLeg()
			, PgTable()
		{
};

PgTblBrlyCLeg::~PgTblBrlyCLeg() {
};

void PgTblBrlyCLeg::initStatements() {
	createStatement("TblBrlyCLeg_getNewRef", "SELECT nextval('TblBrlyCLeg')", 0);
};

ubigint PgTblBrlyCLeg::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblBrlyCLeg_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyCLeg::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif
