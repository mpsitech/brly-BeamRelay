/**
	* \file BrlyRMUsergroupUniversal.h
	* database access for table TblBrlyRMUsergroupUniversal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYRMUSERGROUPUNIVERSAL_H
#define BRLYRMUSERGROUPUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyRMUsergroupUniversal: record of TblBrlyRMUsergroupUniversal
	*/
class BrlyRMUsergroupUniversal {

public:
	BrlyRMUsergroupUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::uint unvIxBrlyVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixBrlyVRecaccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMUsergroup;
	Sbecore::uint unvIxBrlyVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixBrlyVRecaccess;

public:
	bool operator==(const BrlyRMUsergroupUniversal& comp);
	bool operator!=(const BrlyRMUsergroupUniversal& comp);
};

/**
	* ListBrlyRMUsergroupUniversal: recordset of TblBrlyRMUsergroupUniversal
	*/
class ListBrlyRMUsergroupUniversal {

public:
	ListBrlyRMUsergroupUniversal();
	ListBrlyRMUsergroupUniversal(const ListBrlyRMUsergroupUniversal& src);
	~ListBrlyRMUsergroupUniversal();

	void clear();
	unsigned int size() const;
	void append(BrlyRMUsergroupUniversal* rec);

	BrlyRMUsergroupUniversal* operator[](const Sbecore::uint ix);
	ListBrlyRMUsergroupUniversal& operator=(const ListBrlyRMUsergroupUniversal& src);
	bool operator==(const ListBrlyRMUsergroupUniversal& comp);
	bool operator!=(const ListBrlyRMUsergroupUniversal& comp);

public:
	std::vector<BrlyRMUsergroupUniversal*> nodes;
};

/**
	* TblBrlyRMUsergroupUniversal: C++ wrapper for table TblBrlyRMUsergroupUniversal
	*/
class TblBrlyRMUsergroupUniversal {

public:

public:
	TblBrlyRMUsergroupUniversal();
	virtual ~TblBrlyRMUsergroupUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyRMUsergroupUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMUsergroupUniversal& rst);

	virtual Sbecore::ubigint insertRec(BrlyRMUsergroupUniversal* rec);
	Sbecore::ubigint insertNewRec(BrlyRMUsergroupUniversal** rec = NULL, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::uint unvIxBrlyVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixBrlyVRecaccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyRMUsergroupUniversal& rst, BrlyRMUsergroupUniversal** rec = NULL, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::uint unvIxBrlyVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixBrlyVRecaccess = 0);
	virtual void insertRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	virtual void updateRec(BrlyRMUsergroupUniversal* rec);
	virtual void updateRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyRMUsergroupUniversal** rec);
	virtual bool loadRecByUsgMtbUnv(Sbecore::ubigint refBrlyMUsergroup, Sbecore::uint unvIxBrlyVMaintable, Sbecore::ubigint unvUref, BrlyRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyRMUsergroupUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyRMUsergroupUniversal: C++ wrapper for table TblBrlyRMUsergroupUniversal (MySQL database)
	*/
class MyTblBrlyRMUsergroupUniversal : public TblBrlyRMUsergroupUniversal, public Sbecore::MyTable {

public:
	MyTblBrlyRMUsergroupUniversal();
	~MyTblBrlyRMUsergroupUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(BrlyRMUsergroupUniversal* rec);
	void insertRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(BrlyRMUsergroupUniversal* rec);
	void updateRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refBrlyMUsergroup, Sbecore::uint unvIxBrlyVMaintable, Sbecore::ubigint unvUref, BrlyRMUsergroupUniversal** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyRMUsergroupUniversal: C++ wrapper for table TblBrlyRMUsergroupUniversal (PgSQL database)
	*/
class PgTblBrlyRMUsergroupUniversal : public TblBrlyRMUsergroupUniversal, public Sbecore::PgTable {

public:
	PgTblBrlyRMUsergroupUniversal();
	~PgTblBrlyRMUsergroupUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyRMUsergroupUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMUsergroupUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(BrlyRMUsergroupUniversal* rec);
	void insertRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(BrlyRMUsergroupUniversal* rec);
	void updateRst(ListBrlyRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refBrlyMUsergroup, Sbecore::uint unvIxBrlyVMaintable, Sbecore::ubigint unvUref, BrlyRMUsergroupUniversal** rec);
};
#endif

#endif
