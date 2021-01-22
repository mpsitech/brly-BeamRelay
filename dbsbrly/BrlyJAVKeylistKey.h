/**
	* \file BrlyJAVKeylistKey.h
	* database access for table TblBrlyJAVKeylistKey (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYJAVKEYLISTKEY_H
#define BRLYJAVKEYLISTKEY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyJAVKeylistKey: record of TblBrlyJAVKeylistKey
	*/
class BrlyJAVKeylistKey {

public:
	BrlyJAVKeylistKey(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyAVKeylistKey = 0, const Sbecore::uint x1IxBrlyVLocale = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyAVKeylistKey;
	Sbecore::uint x1IxBrlyVLocale;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const BrlyJAVKeylistKey& comp);
	bool operator!=(const BrlyJAVKeylistKey& comp);
};

/**
	* ListBrlyJAVKeylistKey: recordset of TblBrlyJAVKeylistKey
	*/
class ListBrlyJAVKeylistKey {

public:
	ListBrlyJAVKeylistKey();
	ListBrlyJAVKeylistKey(const ListBrlyJAVKeylistKey& src);
	~ListBrlyJAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(BrlyJAVKeylistKey* rec);

	BrlyJAVKeylistKey* operator[](const Sbecore::uint ix);
	ListBrlyJAVKeylistKey& operator=(const ListBrlyJAVKeylistKey& src);
	bool operator==(const ListBrlyJAVKeylistKey& comp);
	bool operator!=(const ListBrlyJAVKeylistKey& comp);

public:
	std::vector<BrlyJAVKeylistKey*> nodes;
};

/**
	* TblBrlyJAVKeylistKey: C++ wrapper for table TblBrlyJAVKeylistKey
	*/
class TblBrlyJAVKeylistKey {

public:

public:
	TblBrlyJAVKeylistKey();
	virtual ~TblBrlyJAVKeylistKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyJAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJAVKeylistKey& rst);

	virtual Sbecore::ubigint insertRec(BrlyJAVKeylistKey* rec);
	Sbecore::ubigint insertNewRec(BrlyJAVKeylistKey** rec = NULL, const Sbecore::ubigint refBrlyAVKeylistKey = 0, const Sbecore::uint x1IxBrlyVLocale = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyJAVKeylistKey& rst, BrlyJAVKeylistKey** rec = NULL, const Sbecore::ubigint refBrlyAVKeylistKey = 0, const Sbecore::uint x1IxBrlyVLocale = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(BrlyJAVKeylistKey* rec);
	virtual void updateRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyJAVKeylistKey** rec);
	virtual bool loadRecByKlkLcl(Sbecore::ubigint refBrlyAVKeylistKey, Sbecore::uint x1IxBrlyVLocale, BrlyJAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refBrlyAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refBrlyAVKeylistKey, const bool append, ListBrlyJAVKeylistKey& rst);
	virtual bool loadTitByKlkLcl(Sbecore::ubigint refBrlyAVKeylistKey, Sbecore::uint x1IxBrlyVLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyJAVKeylistKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyJAVKeylistKey: C++ wrapper for table TblBrlyJAVKeylistKey (MySQL database)
	*/
class MyTblBrlyJAVKeylistKey : public TblBrlyJAVKeylistKey, public Sbecore::MyTable {

public:
	MyTblBrlyJAVKeylistKey();
	~MyTblBrlyJAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(BrlyJAVKeylistKey* rec);
	void insertRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	void updateRec(BrlyJAVKeylistKey* rec);
	void updateRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refBrlyAVKeylistKey, Sbecore::uint x1IxBrlyVLocale, BrlyJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refBrlyAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refBrlyAVKeylistKey, const bool append, ListBrlyJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refBrlyAVKeylistKey, Sbecore::uint x1IxBrlyVLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyJAVKeylistKey: C++ wrapper for table TblBrlyJAVKeylistKey (PgSQL database)
	*/
class PgTblBrlyJAVKeylistKey : public TblBrlyJAVKeylistKey, public Sbecore::PgTable {

public:
	PgTblBrlyJAVKeylistKey();
	~PgTblBrlyJAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyJAVKeylistKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyJAVKeylistKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyJAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyJAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(BrlyJAVKeylistKey* rec);
	void insertRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	void updateRec(BrlyJAVKeylistKey* rec);
	void updateRst(ListBrlyJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refBrlyAVKeylistKey, Sbecore::uint x1IxBrlyVLocale, BrlyJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refBrlyAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refBrlyAVKeylistKey, const bool append, ListBrlyJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refBrlyAVKeylistKey, Sbecore::uint x1IxBrlyVLocale, std::string& Title);
};
#endif

#endif
