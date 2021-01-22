/**
	* \file BrlyAMUserAccess.h
	* database access for table TblBrlyAMUserAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYAMUSERACCESS_H
#define BRLYAMUSERACCESS_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyAMUserAccess: record of TblBrlyAMUserAccess
	*/
class BrlyAMUserAccess {

public:
	BrlyAMUserAccess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMUser;
	Sbecore::uint x1IxBrlyVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixBrlyWAccess;

public:
	bool operator==(const BrlyAMUserAccess& comp);
	bool operator!=(const BrlyAMUserAccess& comp);
};

/**
	* ListBrlyAMUserAccess: recordset of TblBrlyAMUserAccess
	*/
class ListBrlyAMUserAccess {

public:
	ListBrlyAMUserAccess();
	ListBrlyAMUserAccess(const ListBrlyAMUserAccess& src);
	~ListBrlyAMUserAccess();

	void clear();
	unsigned int size() const;
	void append(BrlyAMUserAccess* rec);

	BrlyAMUserAccess* operator[](const Sbecore::uint ix);
	ListBrlyAMUserAccess& operator=(const ListBrlyAMUserAccess& src);
	bool operator==(const ListBrlyAMUserAccess& comp);
	bool operator!=(const ListBrlyAMUserAccess& comp);

public:
	std::vector<BrlyAMUserAccess*> nodes;
};

/**
	* TblBrlyAMUserAccess: C++ wrapper for table TblBrlyAMUserAccess
	*/
class TblBrlyAMUserAccess {

public:

public:
	TblBrlyAMUserAccess();
	virtual ~TblBrlyAMUserAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyAMUserAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMUserAccess& rst);

	virtual Sbecore::ubigint insertRec(BrlyAMUserAccess* rec);
	Sbecore::ubigint insertNewRec(BrlyAMUserAccess** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyAMUserAccess& rst, BrlyAMUserAccess** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0);
	virtual void insertRst(ListBrlyAMUserAccess& rst, bool transact = false);
	virtual void updateRec(BrlyAMUserAccess* rec);
	virtual void updateRst(ListBrlyAMUserAccess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyAMUserAccess** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refBrlyMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyAMUserAccess& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyAMUserAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyAMUserAccess: C++ wrapper for table TblBrlyAMUserAccess (MySQL database)
	*/
class MyTblBrlyAMUserAccess : public TblBrlyAMUserAccess, public Sbecore::MyTable {

public:
	MyTblBrlyAMUserAccess();
	~MyTblBrlyAMUserAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMUserAccess& rst);

	Sbecore::ubigint insertRec(BrlyAMUserAccess* rec);
	void insertRst(ListBrlyAMUserAccess& rst, bool transact = false);
	void updateRec(BrlyAMUserAccess* rec);
	void updateRst(ListBrlyAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refBrlyMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyAMUserAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyAMUserAccess: C++ wrapper for table TblBrlyAMUserAccess (PgSQL database)
	*/
class PgTblBrlyAMUserAccess : public TblBrlyAMUserAccess, public Sbecore::PgTable {

public:
	PgTblBrlyAMUserAccess();
	~PgTblBrlyAMUserAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAMUserAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyAMUserAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAMUserAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAMUserAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMUserAccess& rst);

	Sbecore::ubigint insertRec(BrlyAMUserAccess* rec);
	void insertRst(ListBrlyAMUserAccess& rst, bool transact = false);
	void updateRec(BrlyAMUserAccess* rec);
	void updateRst(ListBrlyAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refBrlyMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyAMUserAccess& rst);
};
#endif

#endif
