/**
	* \file BrlyQFltFafAWaypoint.h
	* Dbs and XML wrapper for table TblBrlyQFltFafAWaypoint (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQFLTFAFAWAYPOINT_H
#define BRLYQFLTFAFAWAYPOINT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQFltFafAWaypoint: record of TblBrlyQFltFafAWaypoint
	*/
class BrlyQFltFafAWaypoint {

public:
	BrlyQFltFafAWaypoint(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint fafNum = 0, const Sbecore::uint timestamp = 0, const std::string ftmTimestamp = "", const double latitude = 0.0, const double longitude = 0.0, const Sbecore::usmallint groundspeed = 0, const Sbecore::usmallint altitude = 0, const std::string altitudeStatus = "", const std::string updateType = "", const std::string altitudeChange = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint fafNum;
	Sbecore::uint timestamp;
	std::string ftmTimestamp;
	double latitude;
	double longitude;
	Sbecore::usmallint groundspeed;
	Sbecore::usmallint altitude;
	std::string altitudeStatus;
	std::string updateType;
	std::string altitudeChange;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQFltFafAWaypoint: recordset of TblBrlyQFltFafAWaypoint
	*/
class ListBrlyQFltFafAWaypoint {

public:
	ListBrlyQFltFafAWaypoint();
	ListBrlyQFltFafAWaypoint(const ListBrlyQFltFafAWaypoint& src);
	~ListBrlyQFltFafAWaypoint();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltFafAWaypoint* rec);

	ListBrlyQFltFafAWaypoint& operator=(const ListBrlyQFltFafAWaypoint& src);

public:
	std::vector<BrlyQFltFafAWaypoint*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQFltFafAWaypoint: C++ wrapper for table TblBrlyQFltFafAWaypoint
	*/
class TblBrlyQFltFafAWaypoint {

public:
	TblBrlyQFltFafAWaypoint();
	virtual ~TblBrlyQFltFafAWaypoint();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQFltFafAWaypoint** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltFafAWaypoint& rst);

	virtual Sbecore::ubigint insertRec(BrlyQFltFafAWaypoint* rec);
	Sbecore::ubigint insertNewRec(BrlyQFltFafAWaypoint** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint fafNum = 0, const Sbecore::uint timestamp = 0, const std::string ftmTimestamp = "", const double latitude = 0.0, const double longitude = 0.0, const Sbecore::usmallint groundspeed = 0, const Sbecore::usmallint altitude = 0, const std::string altitudeStatus = "", const std::string updateType = "", const std::string altitudeChange = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQFltFafAWaypoint& rst, BrlyQFltFafAWaypoint** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint fafNum = 0, const Sbecore::uint timestamp = 0, const std::string ftmTimestamp = "", const double latitude = 0.0, const double longitude = 0.0, const Sbecore::usmallint groundspeed = 0, const Sbecore::usmallint altitude = 0, const std::string altitudeStatus = "", const std::string updateType = "", const std::string altitudeChange = "");
	virtual void insertRst(ListBrlyQFltFafAWaypoint& rst);
	virtual void updateRec(BrlyQFltFafAWaypoint* rec);
	virtual void updateRst(ListBrlyQFltFafAWaypoint& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltFafAWaypoint** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltFafAWaypoint& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQFltFafAWaypoint: C++ wrapper for table TblBrlyQFltFafAWaypoint (MySQL database)
	*/
class MyTblBrlyQFltFafAWaypoint : public TblBrlyQFltFafAWaypoint, public Sbecore::MyTable {

public:
	MyTblBrlyQFltFafAWaypoint();
	~MyTblBrlyQFltFafAWaypoint();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltFafAWaypoint** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltFafAWaypoint& rst);

	Sbecore::ubigint insertRec(BrlyQFltFafAWaypoint* rec);
	void insertRst(ListBrlyQFltFafAWaypoint& rst);
	void updateRec(BrlyQFltFafAWaypoint* rec);
	void updateRst(ListBrlyQFltFafAWaypoint& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltFafAWaypoint** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltFafAWaypoint& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQFltFafAWaypoint: C++ wrapper for table TblBrlyQFltFafAWaypoint (PgSQL database)
	*/
class PgTblBrlyQFltFafAWaypoint : public TblBrlyQFltFafAWaypoint, public Sbecore::PgTable {

public:
	PgTblBrlyQFltFafAWaypoint();
	~PgTblBrlyQFltFafAWaypoint();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltFafAWaypoint** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltFafAWaypoint& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltFafAWaypoint** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltFafAWaypoint& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltFafAWaypoint** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltFafAWaypoint& rst);

	Sbecore::ubigint insertRec(BrlyQFltFafAWaypoint* rec);
	void insertRst(ListBrlyQFltFafAWaypoint& rst);
	void updateRec(BrlyQFltFafAWaypoint* rec);
	void updateRst(ListBrlyQFltFafAWaypoint& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltFafAWaypoint** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltFafAWaypoint& rst);
};
#endif

#endif
