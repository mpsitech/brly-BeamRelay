/**
	* \file BrlyJMUserState.h
	* database access for table TblBrlyJMUserState (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYJMUSERSTATE_H
#define BRLYJMUSERSTATE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyJMUserState: record of TblBrlyJMUserState
	*/
class BrlyJMUserState {

public:
	BrlyJMUserState(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMUser;
	Sbecore::uint x1Start;
	Sbecore::uint ixVState;

public:
	bool operator==(const BrlyJMUserState& comp);
	bool operator!=(const BrlyJMUserState& comp);
};

/**
	* ListBrlyJMUserState: recordset of TblBrlyJMUserState
	*/
class ListBrlyJMUserState {

public:
	ListBrlyJMUserState();
	ListBrlyJMUserState(const ListBrlyJMUserState& src);
	~ListBrlyJMUserState();

	void clear();
	unsigned int size() const;
	void append(BrlyJMUserState* rec);

	BrlyJMUserState* operator[](const Sbecore::uint ix);
	ListBrlyJMUserState& operator=(const ListBrlyJMUserState& src);
	bool operator==(const ListBrlyJMUserState& comp);
	bool operator!=(const ListBrlyJMUserState& comp);

public:
	std::vector<BrlyJMUserState*> nodes;
};

/**
	* TblBrlyJMUserState: C++ wrapper for table TblBrlyJMUserState
	*/
class TblBrlyJMUserState {

public:

public:
	TblBrlyJMUserState();
	virtual ~TblBrlyJMUserState();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyJMUserState** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMUserState& rst);

	virtual Sbecore::ubigint insertRec(BrlyJMUserState* rec);
	Sbecore::ubigint insertNewRec(BrlyJMUserState** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyJMUserState& rst, BrlyJMUserState** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	virtual void insertRst(ListBrlyJMUserState& rst, bool transact = false);
	virtual void updateRec(BrlyJMUserState* rec);
	virtual void updateRst(ListBrlyJMUserState& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyJMUserState** rec);
	virtual bool loadRecByUsrSta(Sbecore::ubigint refBrlyMUser, Sbecore::uint x1Start, BrlyJMUserState** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refBrlyMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyJMUserState& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyJMUserState& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyJMUserState: C++ wrapper for table TblBrlyJMUserState (MySQL database)
	*/
class MyTblBrlyJMUserState : public TblBrlyJMUserState, public Sbecore::MyTable {

public:
	MyTblBrlyJMUserState();
	~MyTblBrlyJMUserState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMUserState& rst);

	Sbecore::ubigint insertRec(BrlyJMUserState* rec);
	void insertRst(ListBrlyJMUserState& rst, bool transact = false);
	void updateRec(BrlyJMUserState* rec);
	void updateRst(ListBrlyJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refBrlyMUser, Sbecore::uint x1Start, BrlyJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refBrlyMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyJMUserState& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyJMUserState: C++ wrapper for table TblBrlyJMUserState (PgSQL database)
	*/
class PgTblBrlyJMUserState : public TblBrlyJMUserState, public Sbecore::PgTable {

public:
	PgTblBrlyJMUserState();
	~PgTblBrlyJMUserState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyJMUserState** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyJMUserState& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyJMUserState** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyJMUserState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMUserState& rst);

	Sbecore::ubigint insertRec(BrlyJMUserState* rec);
	void insertRst(ListBrlyJMUserState& rst, bool transact = false);
	void updateRec(BrlyJMUserState* rec);
	void updateRst(ListBrlyJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refBrlyMUser, Sbecore::uint x1Start, BrlyJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refBrlyMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyJMUserState& rst);
};
#endif

#endif
