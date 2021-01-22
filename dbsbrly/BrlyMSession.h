/**
	* \file BrlyMSession.h
	* database access for table TblBrlyMSession (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMSESSION_H
#define BRLYMSESSION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyMSession: record of TblBrlyMSession
	*/
class BrlyMSession {

public:
	BrlyMSession(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMUser;
	Sbecore::uint start;
	Sbecore::uint stop;
	std::string Ip;

public:
	bool operator==(const BrlyMSession& comp);
	bool operator!=(const BrlyMSession& comp);
};

/**
	* ListBrlyMSession: recordset of TblBrlyMSession
	*/
class ListBrlyMSession {

public:
	ListBrlyMSession();
	ListBrlyMSession(const ListBrlyMSession& src);
	~ListBrlyMSession();

	void clear();
	unsigned int size() const;
	void append(BrlyMSession* rec);

	BrlyMSession* operator[](const Sbecore::uint ix);
	ListBrlyMSession& operator=(const ListBrlyMSession& src);
	bool operator==(const ListBrlyMSession& comp);
	bool operator!=(const ListBrlyMSession& comp);

public:
	std::vector<BrlyMSession*> nodes;
};

/**
	* TblBrlyMSession: C++ wrapper for table TblBrlyMSession
	*/
class TblBrlyMSession {

public:

public:
	TblBrlyMSession();
	virtual ~TblBrlyMSession();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMSession** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMSession& rst);

	virtual Sbecore::ubigint insertRec(BrlyMSession* rec);
	Sbecore::ubigint insertNewRec(BrlyMSession** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyMSession& rst, BrlyMSession** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");
	virtual void insertRst(ListBrlyMSession& rst, bool transact = false);
	virtual void updateRec(BrlyMSession* rec);
	virtual void updateRst(ListBrlyMSession& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMSession** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refBrlyMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyMSession& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMSession& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMSession: C++ wrapper for table TblBrlyMSession (MySQL database)
	*/
class MyTblBrlyMSession : public TblBrlyMSession, public Sbecore::MyTable {

public:
	MyTblBrlyMSession();
	~MyTblBrlyMSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMSession& rst);

	Sbecore::ubigint insertRec(BrlyMSession* rec);
	void insertRst(ListBrlyMSession& rst, bool transact = false);
	void updateRec(BrlyMSession* rec);
	void updateRst(ListBrlyMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMSession** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refBrlyMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyMSession& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMSession: C++ wrapper for table TblBrlyMSession (PgSQL database)
	*/
class PgTblBrlyMSession : public TblBrlyMSession, public Sbecore::PgTable {

public:
	PgTblBrlyMSession();
	~PgTblBrlyMSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMSession** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMSession& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMSession** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMSession& rst);

	Sbecore::ubigint insertRec(BrlyMSession* rec);
	void insertRst(ListBrlyMSession& rst, bool transact = false);
	void updateRec(BrlyMSession* rec);
	void updateRst(ListBrlyMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMSession** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refBrlyMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyMSession& rst);
};
#endif

#endif
