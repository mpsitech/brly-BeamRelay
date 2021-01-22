/**
	* \file BrlyRMFlightMLocation.h
	* database access for table TblBrlyRMFlightMLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYRMFLIGHTMLOCATION_H
#define BRLYRMFLIGHTMLOCATION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyRMFlightMLocation: record of TblBrlyRMFlightMLocation
	*/
class BrlyRMFlightMLocation {

public:
	BrlyRMFlightMLocation(const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const Sbecore::uint x1VisStop = 0, const Sbecore::ubigint refBrlyMFlight = 0, const Sbecore::ubigint refBrlyMLocation = 0, const Sbecore::uint xVisStart = 0, const Sbecore::uint xVisStop = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint x1VisStart;
	Sbecore::uint x1VisStop;
	Sbecore::ubigint refBrlyMFlight;
	Sbecore::ubigint refBrlyMLocation;
	Sbecore::uint xVisStart;
	Sbecore::uint xVisStop;

public:
	bool operator==(const BrlyRMFlightMLocation& comp);
	bool operator!=(const BrlyRMFlightMLocation& comp);
};

/**
	* ListBrlyRMFlightMLocation: recordset of TblBrlyRMFlightMLocation
	*/
class ListBrlyRMFlightMLocation {

public:
	ListBrlyRMFlightMLocation();
	ListBrlyRMFlightMLocation(const ListBrlyRMFlightMLocation& src);
	~ListBrlyRMFlightMLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyRMFlightMLocation* rec);

	BrlyRMFlightMLocation* operator[](const Sbecore::uint ix);
	ListBrlyRMFlightMLocation& operator=(const ListBrlyRMFlightMLocation& src);
	bool operator==(const ListBrlyRMFlightMLocation& comp);
	bool operator!=(const ListBrlyRMFlightMLocation& comp);

public:
	std::vector<BrlyRMFlightMLocation*> nodes;
};

/**
	* TblBrlyRMFlightMLocation: C++ wrapper for table TblBrlyRMFlightMLocation
	*/
class TblBrlyRMFlightMLocation {

public:

public:
	TblBrlyRMFlightMLocation();
	virtual ~TblBrlyRMFlightMLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyRMFlightMLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMFlightMLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyRMFlightMLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyRMFlightMLocation** rec = NULL, const Sbecore::uint x1VisStart = 0, const Sbecore::uint x1VisStop = 0, const Sbecore::ubigint refBrlyMFlight = 0, const Sbecore::ubigint refBrlyMLocation = 0, const Sbecore::uint xVisStart = 0, const Sbecore::uint xVisStop = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyRMFlightMLocation& rst, BrlyRMFlightMLocation** rec = NULL, const Sbecore::uint x1VisStart = 0, const Sbecore::uint x1VisStop = 0, const Sbecore::ubigint refBrlyMFlight = 0, const Sbecore::ubigint refBrlyMLocation = 0, const Sbecore::uint xVisStart = 0, const Sbecore::uint xVisStop = 0);
	virtual void insertRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	virtual void updateRec(BrlyRMFlightMLocation* rec);
	virtual void updateRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyRMFlightMLocation** rec);
	virtual Sbecore::ubigint loadRstByFlt(Sbecore::ubigint refBrlyMFlight, const bool append, ListBrlyRMFlightMLocation& rst);
	virtual Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refBrlyMLocation, const bool append, ListBrlyRMFlightMLocation& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyRMFlightMLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyRMFlightMLocation: C++ wrapper for table TblBrlyRMFlightMLocation (MySQL database)
	*/
class MyTblBrlyRMFlightMLocation : public TblBrlyRMFlightMLocation, public Sbecore::MyTable {

public:
	MyTblBrlyRMFlightMLocation();
	~MyTblBrlyRMFlightMLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMFlightMLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMFlightMLocation& rst);

	Sbecore::ubigint insertRec(BrlyRMFlightMLocation* rec);
	void insertRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	void updateRec(BrlyRMFlightMLocation* rec);
	void updateRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMFlightMLocation** rec);
	Sbecore::ubigint loadRstByFlt(Sbecore::ubigint refBrlyMFlight, const bool append, ListBrlyRMFlightMLocation& rst);
	Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refBrlyMLocation, const bool append, ListBrlyRMFlightMLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyRMFlightMLocation: C++ wrapper for table TblBrlyRMFlightMLocation (PgSQL database)
	*/
class PgTblBrlyRMFlightMLocation : public TblBrlyRMFlightMLocation, public Sbecore::PgTable {

public:
	PgTblBrlyRMFlightMLocation();
	~PgTblBrlyRMFlightMLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMFlightMLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyRMFlightMLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMFlightMLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMFlightMLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMFlightMLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMFlightMLocation& rst);

	Sbecore::ubigint insertRec(BrlyRMFlightMLocation* rec);
	void insertRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	void updateRec(BrlyRMFlightMLocation* rec);
	void updateRst(ListBrlyRMFlightMLocation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMFlightMLocation** rec);
	Sbecore::ubigint loadRstByFlt(Sbecore::ubigint refBrlyMFlight, const bool append, ListBrlyRMFlightMLocation& rst);
	Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refBrlyMLocation, const bool append, ListBrlyRMFlightMLocation& rst);
};
#endif

#endif
