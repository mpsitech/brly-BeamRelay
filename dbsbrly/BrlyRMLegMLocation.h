/**
	* \file BrlyRMLegMLocation.h
	* database access for table TblBrlyRMLegMLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYRMLEGMLOCATION_H
#define BRLYRMLEGMLOCATION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyRMLegMLocation: record of TblBrlyRMLegMLocation
	*/
class BrlyRMLegMLocation {

public:
	BrlyRMLegMLocation(const Sbecore::ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const Sbecore::ubigint refBrlyMLeg = 0, const Sbecore::ubigint refBrlyMLocation = 0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);

public:
	Sbecore::ubigint ref;
	double x1VisLegphi0;
	double x1VisLegphi1;
	Sbecore::ubigint refBrlyMLeg;
	Sbecore::ubigint refBrlyMLocation;
	double legphi;
	double legtheta;
	double xVisLegphi0;
	double xVisLegphi1;

public:
	bool operator==(const BrlyRMLegMLocation& comp);
	bool operator!=(const BrlyRMLegMLocation& comp);
};

/**
	* ListBrlyRMLegMLocation: recordset of TblBrlyRMLegMLocation
	*/
class ListBrlyRMLegMLocation {

public:
	ListBrlyRMLegMLocation();
	ListBrlyRMLegMLocation(const ListBrlyRMLegMLocation& src);
	~ListBrlyRMLegMLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyRMLegMLocation* rec);

	BrlyRMLegMLocation* operator[](const Sbecore::uint ix);
	ListBrlyRMLegMLocation& operator=(const ListBrlyRMLegMLocation& src);
	bool operator==(const ListBrlyRMLegMLocation& comp);
	bool operator!=(const ListBrlyRMLegMLocation& comp);

public:
	std::vector<BrlyRMLegMLocation*> nodes;
};

/**
	* TblBrlyRMLegMLocation: C++ wrapper for table TblBrlyRMLegMLocation
	*/
class TblBrlyRMLegMLocation {

public:

public:
	TblBrlyRMLegMLocation();
	virtual ~TblBrlyRMLegMLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyRMLegMLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMLegMLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyRMLegMLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyRMLegMLocation** rec = NULL, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const Sbecore::ubigint refBrlyMLeg = 0, const Sbecore::ubigint refBrlyMLocation = 0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyRMLegMLocation& rst, BrlyRMLegMLocation** rec = NULL, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const Sbecore::ubigint refBrlyMLeg = 0, const Sbecore::ubigint refBrlyMLocation = 0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	virtual void insertRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	virtual void updateRec(BrlyRMLegMLocation* rec);
	virtual void updateRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyRMLegMLocation** rec);
	virtual Sbecore::ubigint loadRstByLeg(Sbecore::ubigint refBrlyMLeg, const bool append, ListBrlyRMLegMLocation& rst);
	virtual Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refBrlyMLocation, const bool append, ListBrlyRMLegMLocation& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyRMLegMLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyRMLegMLocation: C++ wrapper for table TblBrlyRMLegMLocation (MySQL database)
	*/
class MyTblBrlyRMLegMLocation : public TblBrlyRMLegMLocation, public Sbecore::MyTable {

public:
	MyTblBrlyRMLegMLocation();
	~MyTblBrlyRMLegMLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMLegMLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMLegMLocation& rst);

	Sbecore::ubigint insertRec(BrlyRMLegMLocation* rec);
	void insertRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	void updateRec(BrlyRMLegMLocation* rec);
	void updateRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMLegMLocation** rec);
	Sbecore::ubigint loadRstByLeg(Sbecore::ubigint refBrlyMLeg, const bool append, ListBrlyRMLegMLocation& rst);
	Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refBrlyMLocation, const bool append, ListBrlyRMLegMLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyRMLegMLocation: C++ wrapper for table TblBrlyRMLegMLocation (PgSQL database)
	*/
class PgTblBrlyRMLegMLocation : public TblBrlyRMLegMLocation, public Sbecore::PgTable {

public:
	PgTblBrlyRMLegMLocation();
	~PgTblBrlyRMLegMLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMLegMLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyRMLegMLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMLegMLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMLegMLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMLegMLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMLegMLocation& rst);

	Sbecore::ubigint insertRec(BrlyRMLegMLocation* rec);
	void insertRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	void updateRec(BrlyRMLegMLocation* rec);
	void updateRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMLegMLocation** rec);
	Sbecore::ubigint loadRstByLeg(Sbecore::ubigint refBrlyMLeg, const bool append, ListBrlyRMLegMLocation& rst);
	Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refBrlyMLocation, const bool append, ListBrlyRMLegMLocation& rst);
};
#endif

#endif
