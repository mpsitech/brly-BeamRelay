/**
	* \file BrlyMTimetable.h
	* database access for table TblBrlyMTimetable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMTIMETABLE_H
#define BRLYMTIMETABLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyMTimetable: record of TblBrlyMTimetable
	*/
class BrlyMTimetable {

public:
	BrlyMTimetable(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMFile = 0, const std::string srefBrlyKAlliance = "", const std::string Title = "", const Sbecore::uint startd = 0, const Sbecore::uint stopd = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMFile;
	std::string srefBrlyKAlliance;
	std::string Title;
	Sbecore::uint startd;
	Sbecore::uint stopd;

public:
	bool operator==(const BrlyMTimetable& comp);
	bool operator!=(const BrlyMTimetable& comp);
};

/**
	* ListBrlyMTimetable: recordset of TblBrlyMTimetable
	*/
class ListBrlyMTimetable {

public:
	ListBrlyMTimetable();
	ListBrlyMTimetable(const ListBrlyMTimetable& src);
	~ListBrlyMTimetable();

	void clear();
	unsigned int size() const;
	void append(BrlyMTimetable* rec);

	BrlyMTimetable* operator[](const Sbecore::uint ix);
	ListBrlyMTimetable& operator=(const ListBrlyMTimetable& src);
	bool operator==(const ListBrlyMTimetable& comp);
	bool operator!=(const ListBrlyMTimetable& comp);

public:
	std::vector<BrlyMTimetable*> nodes;
};

/**
	* TblBrlyMTimetable: C++ wrapper for table TblBrlyMTimetable
	*/
class TblBrlyMTimetable {

public:

public:
	TblBrlyMTimetable();
	virtual ~TblBrlyMTimetable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMTimetable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMTimetable& rst);

	virtual Sbecore::ubigint insertRec(BrlyMTimetable* rec);
	Sbecore::ubigint insertNewRec(BrlyMTimetable** rec = NULL, const Sbecore::ubigint refBrlyMFile = 0, const std::string srefBrlyKAlliance = "", const std::string Title = "", const Sbecore::uint startd = 0, const Sbecore::uint stopd = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyMTimetable& rst, BrlyMTimetable** rec = NULL, const Sbecore::ubigint refBrlyMFile = 0, const std::string srefBrlyKAlliance = "", const std::string Title = "", const Sbecore::uint startd = 0, const Sbecore::uint stopd = 0);
	virtual void insertRst(ListBrlyMTimetable& rst, bool transact = false);
	virtual void updateRec(BrlyMTimetable* rec);
	virtual void updateRst(ListBrlyMTimetable& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMTimetable** rec);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMTimetable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMTimetable: C++ wrapper for table TblBrlyMTimetable (MySQL database)
	*/
class MyTblBrlyMTimetable : public TblBrlyMTimetable, public Sbecore::MyTable {

public:
	MyTblBrlyMTimetable();
	~MyTblBrlyMTimetable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMTimetable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMTimetable& rst);

	Sbecore::ubigint insertRec(BrlyMTimetable* rec);
	void insertRst(ListBrlyMTimetable& rst, bool transact = false);
	void updateRec(BrlyMTimetable* rec);
	void updateRst(ListBrlyMTimetable& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMTimetable** rec);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMTimetable: C++ wrapper for table TblBrlyMTimetable (PgSQL database)
	*/
class PgTblBrlyMTimetable : public TblBrlyMTimetable, public Sbecore::PgTable {

public:
	PgTblBrlyMTimetable();
	~PgTblBrlyMTimetable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMTimetable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMTimetable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMTimetable** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMTimetable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMTimetable& rst);

	Sbecore::ubigint insertRec(BrlyMTimetable* rec);
	void insertRst(ListBrlyMTimetable& rst, bool transact = false);
	void updateRec(BrlyMTimetable* rec);
	void updateRst(ListBrlyMTimetable& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMTimetable** rec);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif
