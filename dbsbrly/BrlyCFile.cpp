/**
	* \file BrlyCFile.cpp
	* Dbs and XML wrapper for table TblBrlyCFile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyCFile.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblBrlyCFile
 ******************************************************************************/

TblBrlyCFile::TblBrlyCFile() {
};

TblBrlyCFile::~TblBrlyCFile() {
};

ubigint TblBrlyCFile::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyCFile
 ******************************************************************************/

MyTblBrlyCFile::MyTblBrlyCFile() :
			TblBrlyCFile()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblBrlyCFile::~MyTblBrlyCFile() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblBrlyCFile::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblBrlyCFile () VALUES ()", false);
};

ubigint MyTblBrlyCFile::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblBrlyCFile::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblBrlyCFile::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyCFile
 ******************************************************************************/

PgTblBrlyCFile::PgTblBrlyCFile() :
			TblBrlyCFile()
			, PgTable()
		{
};

PgTblBrlyCFile::~PgTblBrlyCFile() {
};

void PgTblBrlyCFile::initStatements() {
	createStatement("TblBrlyCFile_getNewRef", "SELECT nextval('TblBrlyCFile')", 0);
};

ubigint PgTblBrlyCFile::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblBrlyCFile_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyCFile::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif
