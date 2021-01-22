/**
	* \file BrlyAMFaflightWaypoint.h
	* database access for table TblBrlyAMFaflightWaypoint (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYAMFAFLIGHTWAYPOINT_H
#define BRLYAMFAFLIGHTWAYPOINT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyAMFaflightWaypoint: record of TblBrlyAMFaflightWaypoint
	*/
class BrlyAMFaflightWaypoint {

public:
	BrlyAMFaflightWaypoint(const Sbecore::ubigint ref = 0, const Sbecore::ubigint fafRefBrlyMFaflight = 0, const Sbecore::uint fafNum = 0, const Sbecore::uint timestamp = 0, const double latitude = 0.0, const double longitude = 0.0, const Sbecore::usmallint groundspeed = 0, const Sbecore::usmallint altitude = 0, const std::string altitudeStatus = "", const std::string updateType = "", const std::string altitudeChange = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint fafRefBrlyMFaflight;
	Sbecore::uint fafNum;
	Sbecore::uint timestamp;
	double latitude;
	double longitude;
	Sbecore::usmallint groundspeed;
	Sbecore::usmallint altitude;
	std::string altitudeStatus;
	std::string updateType;
	std::string altitudeChange;

public:
	bool operator==(const BrlyAMFaflightWaypoint& comp);
	bool operator!=(const BrlyAMFaflightWaypoint& comp);
};

/**
	* ListBrlyAMFaflightWaypoint: recordset of TblBrlyAMFaflightWaypoint
	*/
class ListBrlyAMFaflightWaypoint {

public:
	ListBrlyAMFaflightWaypoint();
	ListBrlyAMFaflightWaypoint(const ListBrlyAMFaflightWaypoint& src);
	~ListBrlyAMFaflightWaypoint();

	void clear();
	unsigned int size() const;
	void append(BrlyAMFaflightWaypoint* rec);

	BrlyAMFaflightWaypoint* operator[](const Sbecore::uint ix);
	ListBrlyAMFaflightWaypoint& operator=(const ListBrlyAMFaflightWaypoint& src);
	bool operator==(const ListBrlyAMFaflightWaypoint& comp);
	bool operator!=(const ListBrlyAMFaflightWaypoint& comp);

public:
	std::vector<BrlyAMFaflightWaypoint*> nodes;
};

/**
	* TblBrlyAMFaflightWaypoint: C++ wrapper for table TblBrlyAMFaflightWaypoint
	*/
class TblBrlyAMFaflightWaypoint {

public:

public:
	TblBrlyAMFaflightWaypoint();
	virtual ~TblBrlyAMFaflightWaypoint();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyAMFaflightWaypoint** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMFaflightWaypoint& rst);

	virtual Sbecore::ubigint insertRec(BrlyAMFaflightWaypoint* rec);
	Sbecore::ubigint insertNewRec(BrlyAMFaflightWaypoint** rec = NULL, const Sbecore::ubigint fafRefBrlyMFaflight = 0, const Sbecore::uint fafNum = 0, const Sbecore::uint timestamp = 0, const double latitude = 0.0, const double longitude = 0.0, const Sbecore::usmallint groundspeed = 0, const Sbecore::usmallint altitude = 0, const std::string altitudeStatus = "", const std::string updateType = "", const std::string altitudeChange = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyAMFaflightWaypoint& rst, BrlyAMFaflightWaypoint** rec = NULL, const Sbecore::ubigint fafRefBrlyMFaflight = 0, const Sbecore::uint fafNum = 0, const Sbecore::uint timestamp = 0, const double latitude = 0.0, const double longitude = 0.0, const Sbecore::usmallint groundspeed = 0, const Sbecore::usmallint altitude = 0, const std::string altitudeStatus = "", const std::string updateType = "", const std::string altitudeChange = "");
	virtual void insertRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	virtual void updateRec(BrlyAMFaflightWaypoint* rec);
	virtual void updateRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyAMFaflightWaypoint** rec);
	virtual Sbecore::ubigint loadRefsByFaf(Sbecore::ubigint fafRefBrlyMFaflight, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByFaf(Sbecore::ubigint fafRefBrlyMFaflight, const bool append, ListBrlyAMFaflightWaypoint& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyAMFaflightWaypoint& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyAMFaflightWaypoint: C++ wrapper for table TblBrlyAMFaflightWaypoint (MySQL database)
	*/
class MyTblBrlyAMFaflightWaypoint : public TblBrlyAMFaflightWaypoint, public Sbecore::MyTable {

public:
	MyTblBrlyAMFaflightWaypoint();
	~MyTblBrlyAMFaflightWaypoint();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAMFaflightWaypoint** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMFaflightWaypoint& rst);

	Sbecore::ubigint insertRec(BrlyAMFaflightWaypoint* rec);
	void insertRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	void updateRec(BrlyAMFaflightWaypoint* rec);
	void updateRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAMFaflightWaypoint** rec);
	Sbecore::ubigint loadRefsByFaf(Sbecore::ubigint fafRefBrlyMFaflight, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByFaf(Sbecore::ubigint fafRefBrlyMFaflight, const bool append, ListBrlyAMFaflightWaypoint& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyAMFaflightWaypoint: C++ wrapper for table TblBrlyAMFaflightWaypoint (PgSQL database)
	*/
class PgTblBrlyAMFaflightWaypoint : public TblBrlyAMFaflightWaypoint, public Sbecore::PgTable {

public:
	PgTblBrlyAMFaflightWaypoint();
	~PgTblBrlyAMFaflightWaypoint();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAMFaflightWaypoint** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyAMFaflightWaypoint& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAMFaflightWaypoint** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAMFaflightWaypoint& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAMFaflightWaypoint** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMFaflightWaypoint& rst);

	Sbecore::ubigint insertRec(BrlyAMFaflightWaypoint* rec);
	void insertRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	void updateRec(BrlyAMFaflightWaypoint* rec);
	void updateRst(ListBrlyAMFaflightWaypoint& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAMFaflightWaypoint** rec);
	Sbecore::ubigint loadRefsByFaf(Sbecore::ubigint fafRefBrlyMFaflight, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByFaf(Sbecore::ubigint fafRefBrlyMFaflight, const bool append, ListBrlyAMFaflightWaypoint& rst);
};
#endif

#endif
