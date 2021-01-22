/**
	* \file BrlyCFile.h
	* Dbs and XML wrapper for table TblBrlyCFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYCFILE_H
#define BRLYCFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblBrlyCFile: C++ wrapper for table TblBrlyCFile
	*/
class TblBrlyCFile {

public:
	TblBrlyCFile();
	virtual ~TblBrlyCFile();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblBrlyCFile: C++ wrapper for table TblBrlyCFile (MySQL database)
	*/
class MyTblBrlyCFile : public TblBrlyCFile, public Sbecore::MyTable {

public:
	MyTblBrlyCFile();
	~MyTblBrlyCFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtGetNewRef;

public:
	Sbecore::ubigint getNewRef();
};
#endif

#if defined(SBECORE_PG)
/**
	* PgTblBrlyCFile: C++ wrapper for table TblBrlyCFile (PgSQL database)
	*/
class PgTblBrlyCFile : public TblBrlyCFile, public Sbecore::PgTable {

public:
	PgTblBrlyCFile();
	~PgTblBrlyCFile();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif
