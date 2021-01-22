/**
	* \file BrlyAMRegionDstswitch.h
	* database access for table TblBrlyAMRegionDstswitch (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYAMREGIONDSTSWITCH_H
#define BRLYAMREGIONDSTSWITCH_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyAMRegionDstswitch: record of TblBrlyAMRegionDstswitch
	*/
class BrlyAMRegionDstswitch {

public:
	BrlyAMRegionDstswitch(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::uint startd = 0, const Sbecore::uint startt = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMRegion;
	Sbecore::uint startd;
	Sbecore::uint startt;

public:
	bool operator==(const BrlyAMRegionDstswitch& comp);
	bool operator!=(const BrlyAMRegionDstswitch& comp);
};

/**
	* ListBrlyAMRegionDstswitch: recordset of TblBrlyAMRegionDstswitch
	*/
class ListBrlyAMRegionDstswitch {

public:
	ListBrlyAMRegionDstswitch();
	ListBrlyAMRegionDstswitch(const ListBrlyAMRegionDstswitch& src);
	~ListBrlyAMRegionDstswitch();

	void clear();
	unsigned int size() const;
	void append(BrlyAMRegionDstswitch* rec);

	BrlyAMRegionDstswitch* operator[](const Sbecore::uint ix);
	ListBrlyAMRegionDstswitch& operator=(const ListBrlyAMRegionDstswitch& src);
	bool operator==(const ListBrlyAMRegionDstswitch& comp);
	bool operator!=(const ListBrlyAMRegionDstswitch& comp);

public:
	std::vector<BrlyAMRegionDstswitch*> nodes;
};

/**
	* TblBrlyAMRegionDstswitch: C++ wrapper for table TblBrlyAMRegionDstswitch
	*/
class TblBrlyAMRegionDstswitch {

public:

public:
	TblBrlyAMRegionDstswitch();
	virtual ~TblBrlyAMRegionDstswitch();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyAMRegionDstswitch** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMRegionDstswitch& rst);

	virtual Sbecore::ubigint insertRec(BrlyAMRegionDstswitch* rec);
	Sbecore::ubigint insertNewRec(BrlyAMRegionDstswitch** rec = NULL, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::uint startd = 0, const Sbecore::uint startt = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyAMRegionDstswitch& rst, BrlyAMRegionDstswitch** rec = NULL, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::uint startd = 0, const Sbecore::uint startt = 0);
	virtual void insertRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	virtual void updateRec(BrlyAMRegionDstswitch* rec);
	virtual void updateRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyAMRegionDstswitch** rec);
	virtual Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyAMRegionDstswitch& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyAMRegionDstswitch& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyAMRegionDstswitch: C++ wrapper for table TblBrlyAMRegionDstswitch (MySQL database)
	*/
class MyTblBrlyAMRegionDstswitch : public TblBrlyAMRegionDstswitch, public Sbecore::MyTable {

public:
	MyTblBrlyAMRegionDstswitch();
	~MyTblBrlyAMRegionDstswitch();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAMRegionDstswitch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMRegionDstswitch& rst);

	Sbecore::ubigint insertRec(BrlyAMRegionDstswitch* rec);
	void insertRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	void updateRec(BrlyAMRegionDstswitch* rec);
	void updateRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAMRegionDstswitch** rec);
	Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyAMRegionDstswitch& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyAMRegionDstswitch: C++ wrapper for table TblBrlyAMRegionDstswitch (PgSQL database)
	*/
class PgTblBrlyAMRegionDstswitch : public TblBrlyAMRegionDstswitch, public Sbecore::PgTable {

public:
	PgTblBrlyAMRegionDstswitch();
	~PgTblBrlyAMRegionDstswitch();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAMRegionDstswitch** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyAMRegionDstswitch& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAMRegionDstswitch** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAMRegionDstswitch& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAMRegionDstswitch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMRegionDstswitch& rst);

	Sbecore::ubigint insertRec(BrlyAMRegionDstswitch* rec);
	void insertRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	void updateRec(BrlyAMRegionDstswitch* rec);
	void updateRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAMRegionDstswitch** rec);
	Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyAMRegionDstswitch& rst);
};
#endif

#endif
