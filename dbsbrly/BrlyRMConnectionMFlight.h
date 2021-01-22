/**
	* \file BrlyRMConnectionMFlight.h
	* database access for table TblBrlyRMConnectionMFlight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYRMCONNECTIONMFLIGHT_H
#define BRLYRMCONNECTIONMFLIGHT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyRMConnectionMFlight: record of TblBrlyRMConnectionMFlight
	*/
class BrlyRMConnectionMFlight {

public:
	BrlyRMConnectionMFlight(const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::ubigint refBrlyMFlight = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint x1Start;
	Sbecore::uint x1Stop;
	double x2Legphi0;
	double x2Legphi1;
	Sbecore::ubigint refBrlyMConnection;
	Sbecore::ubigint refBrlyMFlight;

public:
	bool operator==(const BrlyRMConnectionMFlight& comp);
	bool operator!=(const BrlyRMConnectionMFlight& comp);
};

/**
	* ListBrlyRMConnectionMFlight: recordset of TblBrlyRMConnectionMFlight
	*/
class ListBrlyRMConnectionMFlight {

public:
	ListBrlyRMConnectionMFlight();
	ListBrlyRMConnectionMFlight(const ListBrlyRMConnectionMFlight& src);
	~ListBrlyRMConnectionMFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyRMConnectionMFlight* rec);

	BrlyRMConnectionMFlight* operator[](const Sbecore::uint ix);
	ListBrlyRMConnectionMFlight& operator=(const ListBrlyRMConnectionMFlight& src);
	bool operator==(const ListBrlyRMConnectionMFlight& comp);
	bool operator!=(const ListBrlyRMConnectionMFlight& comp);

public:
	std::vector<BrlyRMConnectionMFlight*> nodes;
};

/**
	* TblBrlyRMConnectionMFlight: C++ wrapper for table TblBrlyRMConnectionMFlight
	*/
class TblBrlyRMConnectionMFlight {

public:

public:
	TblBrlyRMConnectionMFlight();
	virtual ~TblBrlyRMConnectionMFlight();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyRMConnectionMFlight** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMConnectionMFlight& rst);

	virtual Sbecore::ubigint insertRec(BrlyRMConnectionMFlight* rec);
	Sbecore::ubigint insertNewRec(BrlyRMConnectionMFlight** rec = NULL, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::ubigint refBrlyMFlight = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyRMConnectionMFlight& rst, BrlyRMConnectionMFlight** rec = NULL, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::ubigint refBrlyMFlight = 0);
	virtual void insertRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	virtual void updateRec(BrlyRMConnectionMFlight* rec);
	virtual void updateRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyRMConnectionMFlight** rec);
	virtual Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMFlight& rst);
	virtual Sbecore::ubigint loadRstByFlt(Sbecore::ubigint refBrlyMFlight, const bool append, ListBrlyRMConnectionMFlight& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyRMConnectionMFlight& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyRMConnectionMFlight: C++ wrapper for table TblBrlyRMConnectionMFlight (MySQL database)
	*/
class MyTblBrlyRMConnectionMFlight : public TblBrlyRMConnectionMFlight, public Sbecore::MyTable {

public:
	MyTblBrlyRMConnectionMFlight();
	~MyTblBrlyRMConnectionMFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMConnectionMFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMConnectionMFlight& rst);

	Sbecore::ubigint insertRec(BrlyRMConnectionMFlight* rec);
	void insertRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	void updateRec(BrlyRMConnectionMFlight* rec);
	void updateRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMConnectionMFlight** rec);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMFlight& rst);
	Sbecore::ubigint loadRstByFlt(Sbecore::ubigint refBrlyMFlight, const bool append, ListBrlyRMConnectionMFlight& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyRMConnectionMFlight: C++ wrapper for table TblBrlyRMConnectionMFlight (PgSQL database)
	*/
class PgTblBrlyRMConnectionMFlight : public TblBrlyRMConnectionMFlight, public Sbecore::PgTable {

public:
	PgTblBrlyRMConnectionMFlight();
	~PgTblBrlyRMConnectionMFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMConnectionMFlight** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyRMConnectionMFlight& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMConnectionMFlight** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMConnectionMFlight& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMConnectionMFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMConnectionMFlight& rst);

	Sbecore::ubigint insertRec(BrlyRMConnectionMFlight* rec);
	void insertRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	void updateRec(BrlyRMConnectionMFlight* rec);
	void updateRst(ListBrlyRMConnectionMFlight& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMConnectionMFlight** rec);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMFlight& rst);
	Sbecore::ubigint loadRstByFlt(Sbecore::ubigint refBrlyMFlight, const bool append, ListBrlyRMConnectionMFlight& rst);
};
#endif

#endif
