/**
	* \file BrlyAccRMUserUniversal.h
	* database access for table TblBrlyAccRMUserUniversal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYACCRMUSERUNIVERSAL_H
#define BRLYACCRMUSERUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyAccRMUserUniversal: record of TblBrlyAccRMUserUniversal
	*/
class BrlyAccRMUserUniversal {

public:
	BrlyAccRMUserUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint unvIxBrlyVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixBrlyVRecaccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMUser;
	Sbecore::uint unvIxBrlyVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixBrlyVRecaccess;

public:
	bool operator==(const BrlyAccRMUserUniversal& comp);
	bool operator!=(const BrlyAccRMUserUniversal& comp);
};

/**
	* ListBrlyAccRMUserUniversal: recordset of TblBrlyAccRMUserUniversal
	*/
class ListBrlyAccRMUserUniversal {

public:
	ListBrlyAccRMUserUniversal();
	ListBrlyAccRMUserUniversal(const ListBrlyAccRMUserUniversal& src);
	~ListBrlyAccRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(BrlyAccRMUserUniversal* rec);

	BrlyAccRMUserUniversal* operator[](const Sbecore::uint ix);
	ListBrlyAccRMUserUniversal& operator=(const ListBrlyAccRMUserUniversal& src);
	bool operator==(const ListBrlyAccRMUserUniversal& comp);
	bool operator!=(const ListBrlyAccRMUserUniversal& comp);

public:
	std::vector<BrlyAccRMUserUniversal*> nodes;
};

/**
	* TblBrlyAccRMUserUniversal: C++ wrapper for table TblBrlyAccRMUserUniversal
	*/
class TblBrlyAccRMUserUniversal {

public:

public:
	TblBrlyAccRMUserUniversal();
	virtual ~TblBrlyAccRMUserUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyAccRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAccRMUserUniversal& rst);

	virtual Sbecore::ubigint insertRec(BrlyAccRMUserUniversal* rec);
	Sbecore::ubigint insertNewRec(BrlyAccRMUserUniversal** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint unvIxBrlyVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixBrlyVRecaccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyAccRMUserUniversal& rst, BrlyAccRMUserUniversal** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint unvIxBrlyVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixBrlyVRecaccess = 0);
	virtual void insertRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(BrlyAccRMUserUniversal* rec);
	virtual void updateRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyAccRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnv(Sbecore::ubigint refBrlyMUser, Sbecore::uint unvIxBrlyVMaintable, Sbecore::ubigint unvUref, BrlyAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyAccRMUserUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyAccRMUserUniversal: C++ wrapper for table TblBrlyAccRMUserUniversal (MySQL database)
	*/
class MyTblBrlyAccRMUserUniversal : public TblBrlyAccRMUserUniversal, public Sbecore::MyTable {

public:
	MyTblBrlyAccRMUserUniversal();
	~MyTblBrlyAccRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(BrlyAccRMUserUniversal* rec);
	void insertRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	void updateRec(BrlyAccRMUserUniversal* rec);
	void updateRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refBrlyMUser, Sbecore::uint unvIxBrlyVMaintable, Sbecore::ubigint unvUref, BrlyAccRMUserUniversal** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyAccRMUserUniversal: C++ wrapper for table TblBrlyAccRMUserUniversal (PgSQL database)
	*/
class PgTblBrlyAccRMUserUniversal : public TblBrlyAccRMUserUniversal, public Sbecore::PgTable {

public:
	PgTblBrlyAccRMUserUniversal();
	~PgTblBrlyAccRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAccRMUserUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyAccRMUserUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAccRMUserUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(BrlyAccRMUserUniversal* rec);
	void insertRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	void updateRec(BrlyAccRMUserUniversal* rec);
	void updateRst(ListBrlyAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refBrlyMUser, Sbecore::uint unvIxBrlyVMaintable, Sbecore::ubigint unvUref, BrlyAccRMUserUniversal** rec);
};
#endif

#endif
