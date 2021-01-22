/**
	* \file BrlyAVKeylistKey.h
	* database access for table TblBrlyAVKeylistKey (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYAVKEYLISTKEY_H
#define BRLYAVKEYLISTKEY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyAVKeylistKey: record of TblBrlyAVKeylistKey
	*/
class BrlyAVKeylistKey {

public:
	BrlyAVKeylistKey(const Sbecore::ubigint ref = 0, const Sbecore::uint klsIxBrlyVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxBrlyVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint klsIxBrlyVKeylist;
	Sbecore::uint klsNum;
	Sbecore::uint x1IxBrlyVMaintable;
	Sbecore::ubigint x1Uref;
	bool Fixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	Sbecore::ubigint refJ;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const BrlyAVKeylistKey& comp);
	bool operator!=(const BrlyAVKeylistKey& comp);
};

/**
	* ListBrlyAVKeylistKey: recordset of TblBrlyAVKeylistKey
	*/
class ListBrlyAVKeylistKey {

public:
	ListBrlyAVKeylistKey();
	ListBrlyAVKeylistKey(const ListBrlyAVKeylistKey& src);
	~ListBrlyAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(BrlyAVKeylistKey* rec);

	BrlyAVKeylistKey* operator[](const Sbecore::uint ix);
	ListBrlyAVKeylistKey& operator=(const ListBrlyAVKeylistKey& src);
	bool operator==(const ListBrlyAVKeylistKey& comp);
	bool operator!=(const ListBrlyAVKeylistKey& comp);

public:
	std::vector<BrlyAVKeylistKey*> nodes;
};

/**
	* TblBrlyAVKeylistKey: C++ wrapper for table TblBrlyAVKeylistKey
	*/
class TblBrlyAVKeylistKey {

public:

public:
	TblBrlyAVKeylistKey();
	virtual ~TblBrlyAVKeylistKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAVKeylistKey& rst);

	virtual Sbecore::ubigint insertRec(BrlyAVKeylistKey* rec);
	Sbecore::ubigint insertNewRec(BrlyAVKeylistKey** rec = NULL, const Sbecore::uint klsIxBrlyVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxBrlyVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyAVKeylistKey& rst, BrlyAVKeylistKey** rec = NULL, const Sbecore::uint klsIxBrlyVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxBrlyVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(BrlyAVKeylistKey* rec);
	virtual void updateRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyAVKeylistKey** rec);
	virtual bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxBrlyVKeylist, Sbecore::uint x1IxBrlyVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	virtual bool loadRefByKlsSrf(Sbecore::uint klsIxBrlyVKeylist, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxBrlyVKeylist, const bool append, ListBrlyAVKeylistKey& rst);
	virtual Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxBrlyVKeylist, Sbecore::uint x1IxBrlyVMaintable, Sbecore::ubigint x1Uref, const bool append, ListBrlyAVKeylistKey& rst);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyAVKeylistKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyAVKeylistKey: C++ wrapper for table TblBrlyAVKeylistKey (MySQL database)
	*/
class MyTblBrlyAVKeylistKey : public TblBrlyAVKeylistKey, public Sbecore::MyTable {

public:
	MyTblBrlyAVKeylistKey();
	~MyTblBrlyAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAVKeylistKey& rst);

	Sbecore::ubigint insertRec(BrlyAVKeylistKey* rec);
	void insertRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	void updateRec(BrlyAVKeylistKey* rec);
	void updateRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxBrlyVKeylist, Sbecore::uint x1IxBrlyVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxBrlyVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxBrlyVKeylist, const bool append, ListBrlyAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxBrlyVKeylist, Sbecore::uint x1IxBrlyVMaintable, Sbecore::ubigint x1Uref, const bool append, ListBrlyAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyAVKeylistKey: C++ wrapper for table TblBrlyAVKeylistKey (PgSQL database)
	*/
class PgTblBrlyAVKeylistKey : public TblBrlyAVKeylistKey, public Sbecore::PgTable {

public:
	PgTblBrlyAVKeylistKey();
	~PgTblBrlyAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAVKeylistKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyAVKeylistKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAVKeylistKey& rst);

	Sbecore::ubigint insertRec(BrlyAVKeylistKey* rec);
	void insertRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	void updateRec(BrlyAVKeylistKey* rec);
	void updateRst(ListBrlyAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxBrlyVKeylist, Sbecore::uint x1IxBrlyVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxBrlyVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxBrlyVKeylist, const bool append, ListBrlyAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxBrlyVKeylist, Sbecore::uint x1IxBrlyVMaintable, Sbecore::ubigint x1Uref, const bool append, ListBrlyAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif
