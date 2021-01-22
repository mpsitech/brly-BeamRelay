/**
	* \file BrlyAMUsergroupAccess.h
	* database access for table TblBrlyAMUsergroupAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYAMUSERGROUPACCESS_H
#define BRLYAMUSERGROUPACCESS_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyAMUsergroupAccess: record of TblBrlyAMUsergroupAccess
	*/
class BrlyAMUsergroupAccess {

public:
	BrlyAMUsergroupAccess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMUsergroup;
	Sbecore::uint x1IxBrlyVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixBrlyWAccess;

public:
	bool operator==(const BrlyAMUsergroupAccess& comp);
	bool operator!=(const BrlyAMUsergroupAccess& comp);
};

/**
	* ListBrlyAMUsergroupAccess: recordset of TblBrlyAMUsergroupAccess
	*/
class ListBrlyAMUsergroupAccess {

public:
	ListBrlyAMUsergroupAccess();
	ListBrlyAMUsergroupAccess(const ListBrlyAMUsergroupAccess& src);
	~ListBrlyAMUsergroupAccess();

	void clear();
	unsigned int size() const;
	void append(BrlyAMUsergroupAccess* rec);

	BrlyAMUsergroupAccess* operator[](const Sbecore::uint ix);
	ListBrlyAMUsergroupAccess& operator=(const ListBrlyAMUsergroupAccess& src);
	bool operator==(const ListBrlyAMUsergroupAccess& comp);
	bool operator!=(const ListBrlyAMUsergroupAccess& comp);

public:
	std::vector<BrlyAMUsergroupAccess*> nodes;
};

/**
	* TblBrlyAMUsergroupAccess: C++ wrapper for table TblBrlyAMUsergroupAccess
	*/
class TblBrlyAMUsergroupAccess {

public:

public:
	TblBrlyAMUsergroupAccess();
	virtual ~TblBrlyAMUsergroupAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyAMUsergroupAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMUsergroupAccess& rst);

	virtual Sbecore::ubigint insertRec(BrlyAMUsergroupAccess* rec);
	Sbecore::ubigint insertNewRec(BrlyAMUsergroupAccess** rec = NULL, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyAMUsergroupAccess& rst, BrlyAMUsergroupAccess** rec = NULL, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0);
	virtual void insertRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	virtual void updateRec(BrlyAMUsergroupAccess* rec);
	virtual void updateRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyAMUsergroupAccess** rec);
	virtual Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, ListBrlyAMUsergroupAccess& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyAMUsergroupAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyAMUsergroupAccess: C++ wrapper for table TblBrlyAMUsergroupAccess (MySQL database)
	*/
class MyTblBrlyAMUsergroupAccess : public TblBrlyAMUsergroupAccess, public Sbecore::MyTable {

public:
	MyTblBrlyAMUsergroupAccess();
	~MyTblBrlyAMUsergroupAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(BrlyAMUsergroupAccess* rec);
	void insertRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	void updateRec(BrlyAMUsergroupAccess* rec);
	void updateRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, ListBrlyAMUsergroupAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyAMUsergroupAccess: C++ wrapper for table TblBrlyAMUsergroupAccess (PgSQL database)
	*/
class PgTblBrlyAMUsergroupAccess : public TblBrlyAMUsergroupAccess, public Sbecore::PgTable {

public:
	PgTblBrlyAMUsergroupAccess();
	~PgTblBrlyAMUsergroupAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAMUsergroupAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyAMUsergroupAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAMUsergroupAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(BrlyAMUsergroupAccess* rec);
	void insertRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	void updateRec(BrlyAMUsergroupAccess* rec);
	void updateRst(ListBrlyAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, ListBrlyAMUsergroupAccess& rst);
};
#endif

#endif
