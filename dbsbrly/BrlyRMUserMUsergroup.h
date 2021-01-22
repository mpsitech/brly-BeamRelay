/**
	* \file BrlyRMUserMUsergroup.h
	* database access for table TblBrlyRMUserMUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYRMUSERMUSERGROUP_H
#define BRLYRMUSERMUSERGROUP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyRMUserMUsergroup: record of TblBrlyRMUserMUsergroup
	*/
class BrlyRMUserMUsergroup {

public:
	BrlyRMUserMUsergroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::uint ixBrlyVUserlevel = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMUser;
	Sbecore::ubigint refBrlyMUsergroup;
	Sbecore::uint ixBrlyVUserlevel;

public:
	bool operator==(const BrlyRMUserMUsergroup& comp);
	bool operator!=(const BrlyRMUserMUsergroup& comp);
};

/**
	* ListBrlyRMUserMUsergroup: recordset of TblBrlyRMUserMUsergroup
	*/
class ListBrlyRMUserMUsergroup {

public:
	ListBrlyRMUserMUsergroup();
	ListBrlyRMUserMUsergroup(const ListBrlyRMUserMUsergroup& src);
	~ListBrlyRMUserMUsergroup();

	void clear();
	unsigned int size() const;
	void append(BrlyRMUserMUsergroup* rec);

	BrlyRMUserMUsergroup* operator[](const Sbecore::uint ix);
	ListBrlyRMUserMUsergroup& operator=(const ListBrlyRMUserMUsergroup& src);
	bool operator==(const ListBrlyRMUserMUsergroup& comp);
	bool operator!=(const ListBrlyRMUserMUsergroup& comp);

public:
	std::vector<BrlyRMUserMUsergroup*> nodes;
};

/**
	* TblBrlyRMUserMUsergroup: C++ wrapper for table TblBrlyRMUserMUsergroup
	*/
class TblBrlyRMUserMUsergroup {

public:

public:
	TblBrlyRMUserMUsergroup();
	virtual ~TblBrlyRMUserMUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyRMUserMUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMUserMUsergroup& rst);

	virtual Sbecore::ubigint insertRec(BrlyRMUserMUsergroup* rec);
	Sbecore::ubigint insertNewRec(BrlyRMUserMUsergroup** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::uint ixBrlyVUserlevel = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyRMUserMUsergroup& rst, BrlyRMUserMUsergroup** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::uint ixBrlyVUserlevel = 0);
	virtual void insertRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	virtual void updateRec(BrlyRMUserMUsergroup* rec);
	virtual void updateRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyRMUserMUsergroup** rec);
	virtual Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, ListBrlyRMUserMUsergroup& rst);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyRMUserMUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyRMUserMUsergroup: C++ wrapper for table TblBrlyRMUserMUsergroup (MySQL database)
	*/
class MyTblBrlyRMUserMUsergroup : public TblBrlyRMUserMUsergroup, public Sbecore::MyTable {

public:
	MyTblBrlyRMUserMUsergroup();
	~MyTblBrlyRMUserMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(BrlyRMUserMUsergroup* rec);
	void insertRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	void updateRec(BrlyRMUserMUsergroup* rec);
	void updateRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, ListBrlyRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyRMUserMUsergroup& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyRMUserMUsergroup: C++ wrapper for table TblBrlyRMUserMUsergroup (PgSQL database)
	*/
class PgTblBrlyRMUserMUsergroup : public TblBrlyRMUserMUsergroup, public Sbecore::PgTable {

public:
	PgTblBrlyRMUserMUsergroup();
	~PgTblBrlyRMUserMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMUserMUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyRMUserMUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMUserMUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(BrlyRMUserMUsergroup* rec);
	void insertRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	void updateRec(BrlyRMUserMUsergroup* rec);
	void updateRst(ListBrlyRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, ListBrlyRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refBrlyMUser, const bool append, ListBrlyRMUserMUsergroup& rst);
};
#endif

#endif
