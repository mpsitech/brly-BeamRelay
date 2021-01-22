/**
	* \file BrlyJMRegionTitle.h
	* database access for table TblBrlyJMRegionTitle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYJMREGIONTITLE_H
#define BRLYJMREGIONTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyJMRegionTitle: record of TblBrlyJMRegionTitle
	*/
class BrlyJMRegionTitle {

public:
	BrlyJMRegionTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::uint x1IxBrlyVLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMRegion;
	Sbecore::uint x1IxBrlyVLocale;
	std::string Title;

public:
	bool operator==(const BrlyJMRegionTitle& comp);
	bool operator!=(const BrlyJMRegionTitle& comp);
};

/**
	* ListBrlyJMRegionTitle: recordset of TblBrlyJMRegionTitle
	*/
class ListBrlyJMRegionTitle {

public:
	ListBrlyJMRegionTitle();
	ListBrlyJMRegionTitle(const ListBrlyJMRegionTitle& src);
	~ListBrlyJMRegionTitle();

	void clear();
	unsigned int size() const;
	void append(BrlyJMRegionTitle* rec);

	BrlyJMRegionTitle* operator[](const Sbecore::uint ix);
	ListBrlyJMRegionTitle& operator=(const ListBrlyJMRegionTitle& src);
	bool operator==(const ListBrlyJMRegionTitle& comp);
	bool operator!=(const ListBrlyJMRegionTitle& comp);

public:
	std::vector<BrlyJMRegionTitle*> nodes;
};

/**
	* TblBrlyJMRegionTitle: C++ wrapper for table TblBrlyJMRegionTitle
	*/
class TblBrlyJMRegionTitle {

public:

public:
	TblBrlyJMRegionTitle();
	virtual ~TblBrlyJMRegionTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyJMRegionTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMRegionTitle& rst);

	virtual Sbecore::ubigint insertRec(BrlyJMRegionTitle* rec);
	Sbecore::ubigint insertNewRec(BrlyJMRegionTitle** rec = NULL, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::uint x1IxBrlyVLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyJMRegionTitle& rst, BrlyJMRegionTitle** rec = NULL, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::uint x1IxBrlyVLocale = 0, const std::string Title = "");
	virtual void insertRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	virtual void updateRec(BrlyJMRegionTitle* rec);
	virtual void updateRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyJMRegionTitle** rec);
	virtual bool loadRecByRegLcl(Sbecore::ubigint refBrlyMRegion, Sbecore::uint x1IxBrlyVLocale, BrlyJMRegionTitle** rec);
	virtual Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyJMRegionTitle& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyJMRegionTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyJMRegionTitle: C++ wrapper for table TblBrlyJMRegionTitle (MySQL database)
	*/
class MyTblBrlyJMRegionTitle : public TblBrlyJMRegionTitle, public Sbecore::MyTable {

public:
	MyTblBrlyJMRegionTitle();
	~MyTblBrlyJMRegionTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyJMRegionTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMRegionTitle& rst);

	Sbecore::ubigint insertRec(BrlyJMRegionTitle* rec);
	void insertRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	void updateRec(BrlyJMRegionTitle* rec);
	void updateRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyJMRegionTitle** rec);
	bool loadRecByRegLcl(Sbecore::ubigint refBrlyMRegion, Sbecore::uint x1IxBrlyVLocale, BrlyJMRegionTitle** rec);
	Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyJMRegionTitle& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyJMRegionTitle: C++ wrapper for table TblBrlyJMRegionTitle (PgSQL database)
	*/
class PgTblBrlyJMRegionTitle : public TblBrlyJMRegionTitle, public Sbecore::PgTable {

public:
	PgTblBrlyJMRegionTitle();
	~PgTblBrlyJMRegionTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyJMRegionTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyJMRegionTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyJMRegionTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyJMRegionTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyJMRegionTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMRegionTitle& rst);

	Sbecore::ubigint insertRec(BrlyJMRegionTitle* rec);
	void insertRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	void updateRec(BrlyJMRegionTitle* rec);
	void updateRst(ListBrlyJMRegionTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyJMRegionTitle** rec);
	bool loadRecByRegLcl(Sbecore::ubigint refBrlyMRegion, Sbecore::uint x1IxBrlyVLocale, BrlyJMRegionTitle** rec);
	Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyJMRegionTitle& rst);
};
#endif

#endif
