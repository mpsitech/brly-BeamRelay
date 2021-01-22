/**
	* \file BrlyCLeg.h
	* Dbs and XML wrapper for table TblBrlyCLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYCLEG_H
#define BRLYCLEG_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblBrlyCLeg: C++ wrapper for table TblBrlyCLeg
	*/
class TblBrlyCLeg {

public:
	TblBrlyCLeg();
	virtual ~TblBrlyCLeg();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblBrlyCLeg: C++ wrapper for table TblBrlyCLeg (MySQL database)
	*/
class MyTblBrlyCLeg : public TblBrlyCLeg, public Sbecore::MyTable {

public:
	MyTblBrlyCLeg();
	~MyTblBrlyCLeg();

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
	* PgTblBrlyCLeg: C++ wrapper for table TblBrlyCLeg (PgSQL database)
	*/
class PgTblBrlyCLeg : public TblBrlyCLeg, public Sbecore::PgTable {

public:
	PgTblBrlyCLeg();
	~PgTblBrlyCLeg();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif
