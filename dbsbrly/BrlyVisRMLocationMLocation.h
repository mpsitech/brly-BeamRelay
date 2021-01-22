/**
	* \file BrlyVisRMLocationMLocation.h
	* database access for table TblBrlyVisRMLocationMLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYVISRMLOCATIONMLOCATION_H
#define BRLYVISRMLOCATIONMLOCATION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyVisRMLocationMLocation: record of TblBrlyVisRMLocationMLocation
	*/
class BrlyVisRMLocationMLocation {

public:
	BrlyVisRMLocationMLocation(const Sbecore::ubigint ref = 0, const Sbecore::ubigint dstRefBrlyMLocation = 0, const Sbecore::ubigint orgRefBrlyMLocation = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint dstRefBrlyMLocation;
	Sbecore::ubigint orgRefBrlyMLocation;

public:
	bool operator==(const BrlyVisRMLocationMLocation& comp);
	bool operator!=(const BrlyVisRMLocationMLocation& comp);
};

/**
	* ListBrlyVisRMLocationMLocation: recordset of TblBrlyVisRMLocationMLocation
	*/
class ListBrlyVisRMLocationMLocation {

public:
	ListBrlyVisRMLocationMLocation();
	ListBrlyVisRMLocationMLocation(const ListBrlyVisRMLocationMLocation& src);
	~ListBrlyVisRMLocationMLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyVisRMLocationMLocation* rec);

	BrlyVisRMLocationMLocation* operator[](const Sbecore::uint ix);
	ListBrlyVisRMLocationMLocation& operator=(const ListBrlyVisRMLocationMLocation& src);
	bool operator==(const ListBrlyVisRMLocationMLocation& comp);
	bool operator!=(const ListBrlyVisRMLocationMLocation& comp);

public:
	std::vector<BrlyVisRMLocationMLocation*> nodes;
};

/**
	* TblBrlyVisRMLocationMLocation: C++ wrapper for table TblBrlyVisRMLocationMLocation
	*/
class TblBrlyVisRMLocationMLocation {

public:

public:
	TblBrlyVisRMLocationMLocation();
	virtual ~TblBrlyVisRMLocationMLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyVisRMLocationMLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyVisRMLocationMLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyVisRMLocationMLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyVisRMLocationMLocation** rec = NULL, const Sbecore::ubigint dstRefBrlyMLocation = 0, const Sbecore::ubigint orgRefBrlyMLocation = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyVisRMLocationMLocation& rst, BrlyVisRMLocationMLocation** rec = NULL, const Sbecore::ubigint dstRefBrlyMLocation = 0, const Sbecore::ubigint orgRefBrlyMLocation = 0);
	virtual void insertRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	virtual void updateRec(BrlyVisRMLocationMLocation* rec);
	virtual void updateRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyVisRMLocationMLocation** rec);
	virtual Sbecore::ubigint loadDlosByOlo(Sbecore::ubigint orgRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& dstRefBrlyMLocations);
	virtual Sbecore::ubigint loadOlosByDlo(Sbecore::ubigint dstRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& orgRefBrlyMLocations);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyVisRMLocationMLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyVisRMLocationMLocation: C++ wrapper for table TblBrlyVisRMLocationMLocation (MySQL database)
	*/
class MyTblBrlyVisRMLocationMLocation : public TblBrlyVisRMLocationMLocation, public Sbecore::MyTable {

public:
	MyTblBrlyVisRMLocationMLocation();
	~MyTblBrlyVisRMLocationMLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyVisRMLocationMLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyVisRMLocationMLocation& rst);

	Sbecore::ubigint insertRec(BrlyVisRMLocationMLocation* rec);
	void insertRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	void updateRec(BrlyVisRMLocationMLocation* rec);
	void updateRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyVisRMLocationMLocation** rec);
	Sbecore::ubigint loadDlosByOlo(Sbecore::ubigint orgRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& dstRefBrlyMLocations);
	Sbecore::ubigint loadOlosByDlo(Sbecore::ubigint dstRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& orgRefBrlyMLocations);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyVisRMLocationMLocation: C++ wrapper for table TblBrlyVisRMLocationMLocation (PgSQL database)
	*/
class PgTblBrlyVisRMLocationMLocation : public TblBrlyVisRMLocationMLocation, public Sbecore::PgTable {

public:
	PgTblBrlyVisRMLocationMLocation();
	~PgTblBrlyVisRMLocationMLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyVisRMLocationMLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyVisRMLocationMLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyVisRMLocationMLocation** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyVisRMLocationMLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyVisRMLocationMLocation& rst);

	Sbecore::ubigint insertRec(BrlyVisRMLocationMLocation* rec);
	void insertRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	void updateRec(BrlyVisRMLocationMLocation* rec);
	void updateRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyVisRMLocationMLocation** rec);
	Sbecore::ubigint loadDlosByOlo(Sbecore::ubigint orgRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& dstRefBrlyMLocations);
	Sbecore::ubigint loadOlosByDlo(Sbecore::ubigint dstRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& orgRefBrlyMLocations);
};
#endif

#endif
