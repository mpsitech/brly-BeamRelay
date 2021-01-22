/**
	* \file BrlyMFaflight.h
	* database access for table TblBrlyMFaflight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMFAFLIGHT_H
#define BRLYMFAFLIGHT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyMFaflight: record of TblBrlyMFaflight
	*/
class BrlyMFaflight {

public:
	BrlyMFaflight(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMFlight = 0, const std::string faFlightID = "", const std::string ident = "", const std::string aircrafttype = "", const std::string filed_ete = "", const Sbecore::uint filed_time = 0, const Sbecore::uint filed_departuretime = 0, const Sbecore::usmallint filed_airspeed_kts = 0, const double filed_airspeed_mach = 0.0, const Sbecore::usmallint filed_altitude = 0, const std::string route = "", const Sbecore::uint actualdeparturetime = 0, const Sbecore::uint estimatedarrivaltime = 0, const Sbecore::uint actualarrivaltime = 0, const std::string diverted = "", const std::string origin = "", const std::string destination = "", const std::string originName = "", const std::string originCity = "", const std::string destinationName = "", const std::string destinationCity = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMFlight;
	std::string faFlightID;
	std::string ident;
	std::string aircrafttype;
	std::string filed_ete;
	Sbecore::uint filed_time;
	Sbecore::uint filed_departuretime;
	Sbecore::usmallint filed_airspeed_kts;
	double filed_airspeed_mach;
	Sbecore::usmallint filed_altitude;
	std::string route;
	Sbecore::uint actualdeparturetime;
	Sbecore::uint estimatedarrivaltime;
	Sbecore::uint actualarrivaltime;
	std::string diverted;
	std::string origin;
	std::string destination;
	std::string originName;
	std::string originCity;
	std::string destinationName;
	std::string destinationCity;

public:
	bool operator==(const BrlyMFaflight& comp);
	bool operator!=(const BrlyMFaflight& comp);
};

/**
	* ListBrlyMFaflight: recordset of TblBrlyMFaflight
	*/
class ListBrlyMFaflight {

public:
	ListBrlyMFaflight();
	ListBrlyMFaflight(const ListBrlyMFaflight& src);
	~ListBrlyMFaflight();

	void clear();
	unsigned int size() const;
	void append(BrlyMFaflight* rec);

	BrlyMFaflight* operator[](const Sbecore::uint ix);
	ListBrlyMFaflight& operator=(const ListBrlyMFaflight& src);
	bool operator==(const ListBrlyMFaflight& comp);
	bool operator!=(const ListBrlyMFaflight& comp);

public:
	std::vector<BrlyMFaflight*> nodes;
};

/**
	* TblBrlyMFaflight: C++ wrapper for table TblBrlyMFaflight
	*/
class TblBrlyMFaflight {

public:

public:
	TblBrlyMFaflight();
	virtual ~TblBrlyMFaflight();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMFaflight** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMFaflight& rst);

	virtual Sbecore::ubigint insertRec(BrlyMFaflight* rec);
	Sbecore::ubigint insertNewRec(BrlyMFaflight** rec = NULL, const Sbecore::ubigint refBrlyMFlight = 0, const std::string faFlightID = "", const std::string ident = "", const std::string aircrafttype = "", const std::string filed_ete = "", const Sbecore::uint filed_time = 0, const Sbecore::uint filed_departuretime = 0, const Sbecore::usmallint filed_airspeed_kts = 0, const double filed_airspeed_mach = 0.0, const Sbecore::usmallint filed_altitude = 0, const std::string route = "", const Sbecore::uint actualdeparturetime = 0, const Sbecore::uint estimatedarrivaltime = 0, const Sbecore::uint actualarrivaltime = 0, const std::string diverted = "", const std::string origin = "", const std::string destination = "", const std::string originName = "", const std::string originCity = "", const std::string destinationName = "", const std::string destinationCity = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyMFaflight& rst, BrlyMFaflight** rec = NULL, const Sbecore::ubigint refBrlyMFlight = 0, const std::string faFlightID = "", const std::string ident = "", const std::string aircrafttype = "", const std::string filed_ete = "", const Sbecore::uint filed_time = 0, const Sbecore::uint filed_departuretime = 0, const Sbecore::usmallint filed_airspeed_kts = 0, const double filed_airspeed_mach = 0.0, const Sbecore::usmallint filed_altitude = 0, const std::string route = "", const Sbecore::uint actualdeparturetime = 0, const Sbecore::uint estimatedarrivaltime = 0, const Sbecore::uint actualarrivaltime = 0, const std::string diverted = "", const std::string origin = "", const std::string destination = "", const std::string originName = "", const std::string originCity = "", const std::string destinationName = "", const std::string destinationCity = "");
	virtual void insertRst(ListBrlyMFaflight& rst, bool transact = false);
	virtual void updateRec(BrlyMFaflight* rec);
	virtual void updateRst(ListBrlyMFaflight& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMFaflight** rec);
	virtual bool loadFidByRef(Sbecore::ubigint ref, std::string& faFlightID);
	virtual bool loadRecByFlt(Sbecore::ubigint refBrlyMFlight, BrlyMFaflight** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMFaflight& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMFaflight: C++ wrapper for table TblBrlyMFaflight (MySQL database)
	*/
class MyTblBrlyMFaflight : public TblBrlyMFaflight, public Sbecore::MyTable {

public:
	MyTblBrlyMFaflight();
	~MyTblBrlyMFaflight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMFaflight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMFaflight& rst);

	Sbecore::ubigint insertRec(BrlyMFaflight* rec);
	void insertRst(ListBrlyMFaflight& rst, bool transact = false);
	void updateRec(BrlyMFaflight* rec);
	void updateRst(ListBrlyMFaflight& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMFaflight** rec);
	bool loadFidByRef(Sbecore::ubigint ref, std::string& faFlightID);
	bool loadRecByFlt(Sbecore::ubigint refBrlyMFlight, BrlyMFaflight** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMFaflight: C++ wrapper for table TblBrlyMFaflight (PgSQL database)
	*/
class PgTblBrlyMFaflight : public TblBrlyMFaflight, public Sbecore::PgTable {

public:
	PgTblBrlyMFaflight();
	~PgTblBrlyMFaflight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMFaflight** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMFaflight& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMFaflight** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMFaflight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMFaflight& rst);

	Sbecore::ubigint insertRec(BrlyMFaflight* rec);
	void insertRst(ListBrlyMFaflight& rst, bool transact = false);
	void updateRec(BrlyMFaflight* rec);
	void updateRst(ListBrlyMFaflight& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMFaflight** rec);
	bool loadFidByRef(Sbecore::ubigint ref, std::string& faFlightID);
	bool loadRecByFlt(Sbecore::ubigint refBrlyMFlight, BrlyMFaflight** rec);
};
#endif

#endif
