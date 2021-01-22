/**
	* \file BrlyJMRegion.h
	* database access for table TblBrlyJMRegion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYJMREGION_H
#define BRLYJMREGION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyJMRegion: record of TblBrlyJMRegion
	*/
class BrlyJMRegion {

public:
	BrlyJMRegion(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::uint ixVDst = 0, const double toffset = 0.0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMRegion;
	Sbecore::uint x1Startd;
	Sbecore::uint x1Stopd;
	Sbecore::uint ixVDst;
	double toffset;

public:
	bool operator==(const BrlyJMRegion& comp);
	bool operator!=(const BrlyJMRegion& comp);
};

/**
	* ListBrlyJMRegion: recordset of TblBrlyJMRegion
	*/
class ListBrlyJMRegion {

public:
	ListBrlyJMRegion();
	ListBrlyJMRegion(const ListBrlyJMRegion& src);
	~ListBrlyJMRegion();

	void clear();
	unsigned int size() const;
	void append(BrlyJMRegion* rec);

	BrlyJMRegion* operator[](const Sbecore::uint ix);
	ListBrlyJMRegion& operator=(const ListBrlyJMRegion& src);
	bool operator==(const ListBrlyJMRegion& comp);
	bool operator!=(const ListBrlyJMRegion& comp);

public:
	std::vector<BrlyJMRegion*> nodes;
};

/**
	* TblBrlyJMRegion: C++ wrapper for table TblBrlyJMRegion
	*/
class TblBrlyJMRegion {

public:

public:
	TblBrlyJMRegion();
	virtual ~TblBrlyJMRegion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyJMRegion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMRegion& rst);

	virtual Sbecore::ubigint insertRec(BrlyJMRegion* rec);
	Sbecore::ubigint insertNewRec(BrlyJMRegion** rec = NULL, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::uint ixVDst = 0, const double toffset = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyJMRegion& rst, BrlyJMRegion** rec = NULL, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::uint ixVDst = 0, const double toffset = 0.0);
	virtual void insertRst(ListBrlyJMRegion& rst, bool transact = false);
	virtual void updateRec(BrlyJMRegion* rec);
	virtual void updateRst(ListBrlyJMRegion& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyJMRegion** rec);
	virtual bool loadRecByRegStaSto(Sbecore::ubigint refBrlyMRegion, Sbecore::uint x1Startd, Sbecore::uint x1Stopd, BrlyJMRegion** rec);
	virtual Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyJMRegion& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyJMRegion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyJMRegion: C++ wrapper for table TblBrlyJMRegion (MySQL database)
	*/
class MyTblBrlyJMRegion : public TblBrlyJMRegion, public Sbecore::MyTable {

public:
	MyTblBrlyJMRegion();
	~MyTblBrlyJMRegion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyJMRegion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMRegion& rst);

	Sbecore::ubigint insertRec(BrlyJMRegion* rec);
	void insertRst(ListBrlyJMRegion& rst, bool transact = false);
	void updateRec(BrlyJMRegion* rec);
	void updateRst(ListBrlyJMRegion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyJMRegion** rec);
	bool loadRecByRegStaSto(Sbecore::ubigint refBrlyMRegion, Sbecore::uint x1Startd, Sbecore::uint x1Stopd, BrlyJMRegion** rec);
	Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyJMRegion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyJMRegion: C++ wrapper for table TblBrlyJMRegion (PgSQL database)
	*/
class PgTblBrlyJMRegion : public TblBrlyJMRegion, public Sbecore::PgTable {

public:
	PgTblBrlyJMRegion();
	~PgTblBrlyJMRegion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyJMRegion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyJMRegion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyJMRegion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyJMRegion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyJMRegion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMRegion& rst);

	Sbecore::ubigint insertRec(BrlyJMRegion* rec);
	void insertRst(ListBrlyJMRegion& rst, bool transact = false);
	void updateRec(BrlyJMRegion* rec);
	void updateRst(ListBrlyJMRegion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyJMRegion** rec);
	bool loadRecByRegStaSto(Sbecore::ubigint refBrlyMRegion, Sbecore::uint x1Startd, Sbecore::uint x1Stopd, BrlyJMRegion** rec);
	Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyJMRegion& rst);
};
#endif

#endif
