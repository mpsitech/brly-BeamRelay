/**
	* \file BrlyProxRMLocationMLocation.h
	* database access for table TblBrlyProxRMLocationMLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYPROXRMLOCATIONMLOCATION_H
#define BRLYPROXRMLOCATIONMLOCATION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyProxRMLocationMLocation: record of TblBrlyProxRMLocationMLocation
	*/
class BrlyProxRMLocationMLocation {

public:
	BrlyProxRMLocationMLocation(const Sbecore::ubigint ref = 0, const Sbecore::ubigint dstRefBrlyMLocation = 0, const Sbecore::ubigint orgRefBrlyMLocation = 0, const double deltaphi = 0.0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint dstRefBrlyMLocation;
	Sbecore::ubigint orgRefBrlyMLocation;
	double deltaphi;

public:
	bool operator==(const BrlyProxRMLocationMLocation& comp);
	bool operator!=(const BrlyProxRMLocationMLocation& comp);
};

/**
	* ListBrlyProxRMLocationMLocation: recordset of TblBrlyProxRMLocationMLocation
	*/
class ListBrlyProxRMLocationMLocation {

public:
	ListBrlyProxRMLocationMLocation();
	ListBrlyProxRMLocationMLocation(const ListBrlyProxRMLocationMLocation& src);
	~ListBrlyProxRMLocationMLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyProxRMLocationMLocation* rec);

	BrlyProxRMLocationMLocation* operator[](const Sbecore::uint ix);
	ListBrlyProxRMLocationMLocation& operator=(const ListBrlyProxRMLocationMLocation& src);
	bool operator==(const ListBrlyProxRMLocationMLocation& comp);
	bool operator!=(const ListBrlyProxRMLocationMLocation& comp);

public:
	std::vector<BrlyProxRMLocationMLocation*> nodes;
};

/**
	* TblBrlyProxRMLocationMLocation: C++ wrapper for table TblBrlyProxRMLocationMLocation
	*/
class TblBrlyProxRMLocationMLocation {

public:

public:
	TblBrlyProxRMLocationMLocation();
	virtual ~TblBrlyProxRMLocationMLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyProxRMLocationMLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyProxRMLocationMLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyProxRMLocationMLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyProxRMLocationMLocation** rec = NULL, const Sbecore::ubigint dstRefBrlyMLocation = 0, const Sbecore::ubigint orgRefBrlyMLocation = 0, const double deltaphi = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyProxRMLocationMLocation& rst, BrlyProxRMLocationMLocation** rec = NULL, const Sbecore::ubigint dstRefBrlyMLocation = 0, const Sbecore::ubigint orgRefBrlyMLocation = 0, const double deltaphi = 0.0);
	virtual void insertRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	virtual void updateRec(BrlyProxRMLocationMLocation* rec);
	virtual void updateRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyProxRMLocationMLocation** rec);
	virtual Sbecore::ubigint loadRstByDlo(Sbecore::ubigint dstRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
	virtual Sbecore::ubigint loadRstByOlo(Sbecore::ubigint orgRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyProxRMLocationMLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyProxRMLocationMLocation: C++ wrapper for table TblBrlyProxRMLocationMLocation (MySQL database)
	*/
class MyTblBrlyProxRMLocationMLocation : public TblBrlyProxRMLocationMLocation, public Sbecore::MyTable {

public:
	MyTblBrlyProxRMLocationMLocation();
	~MyTblBrlyProxRMLocationMLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyProxRMLocationMLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyProxRMLocationMLocation& rst);

	Sbecore::ubigint insertRec(BrlyProxRMLocationMLocation* rec);
	void insertRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	void updateRec(BrlyProxRMLocationMLocation* rec);
	void updateRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyProxRMLocationMLocation** rec);
	Sbecore::ubigint loadRstByDlo(Sbecore::ubigint dstRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
	Sbecore::ubigint loadRstByOlo(Sbecore::ubigint orgRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyProxRMLocationMLocation: C++ wrapper for table TblBrlyProxRMLocationMLocation (PgSQL database)
	*/
class PgTblBrlyProxRMLocationMLocation : public TblBrlyProxRMLocationMLocation, public Sbecore::PgTable {

public:
	PgTblBrlyProxRMLocationMLocation();
	~PgTblBrlyProxRMLocationMLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyProxRMLocationMLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyProxRMLocationMLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyProxRMLocationMLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyProxRMLocationMLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyProxRMLocationMLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyProxRMLocationMLocation& rst);

	Sbecore::ubigint insertRec(BrlyProxRMLocationMLocation* rec);
	void insertRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	void updateRec(BrlyProxRMLocationMLocation* rec);
	void updateRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyProxRMLocationMLocation** rec);
	Sbecore::ubigint loadRstByDlo(Sbecore::ubigint dstRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
	Sbecore::ubigint loadRstByOlo(Sbecore::ubigint orgRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
};
#endif

#endif
