/**
	* \file BrlyMPlntype.h
	* database access for table TblBrlyMPlntype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMPLNTYPE_H
#define BRLYMPLNTYPE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyMPlntype: record of TblBrlyMPlntype
	*/
class BrlyMPlntype {

public:
	BrlyMPlntype(const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string srefBrlyKEqptype = "", const Sbecore::usmallint Capacity = 0);

public:
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	std::string srefBrlyKEqptype;
	Sbecore::usmallint Capacity;

public:
	bool operator==(const BrlyMPlntype& comp);
	bool operator!=(const BrlyMPlntype& comp);
};

/**
	* ListBrlyMPlntype: recordset of TblBrlyMPlntype
	*/
class ListBrlyMPlntype {

public:
	ListBrlyMPlntype();
	ListBrlyMPlntype(const ListBrlyMPlntype& src);
	~ListBrlyMPlntype();

	void clear();
	unsigned int size() const;
	void append(BrlyMPlntype* rec);

	BrlyMPlntype* operator[](const Sbecore::uint ix);
	ListBrlyMPlntype& operator=(const ListBrlyMPlntype& src);
	bool operator==(const ListBrlyMPlntype& comp);
	bool operator!=(const ListBrlyMPlntype& comp);

public:
	std::vector<BrlyMPlntype*> nodes;
};

/**
	* TblBrlyMPlntype: C++ wrapper for table TblBrlyMPlntype
	*/
class TblBrlyMPlntype {

public:

public:
	TblBrlyMPlntype();
	virtual ~TblBrlyMPlntype();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMPlntype** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMPlntype& rst);

	virtual Sbecore::ubigint insertRec(BrlyMPlntype* rec);
	Sbecore::ubigint insertNewRec(BrlyMPlntype** rec = NULL, const std::string sref = "", const std::string Title = "", const std::string srefBrlyKEqptype = "", const Sbecore::usmallint Capacity = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyMPlntype& rst, BrlyMPlntype** rec = NULL, const std::string sref = "", const std::string Title = "", const std::string srefBrlyKEqptype = "", const Sbecore::usmallint Capacity = 0);
	virtual void insertRst(ListBrlyMPlntype& rst, bool transact = false);
	virtual void updateRec(BrlyMPlntype* rec);
	virtual void updateRst(ListBrlyMPlntype& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMPlntype** rec);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMPlntype& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMPlntype: C++ wrapper for table TblBrlyMPlntype (MySQL database)
	*/
class MyTblBrlyMPlntype : public TblBrlyMPlntype, public Sbecore::MyTable {

public:
	MyTblBrlyMPlntype();
	~MyTblBrlyMPlntype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMPlntype** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMPlntype& rst);

	Sbecore::ubigint insertRec(BrlyMPlntype* rec);
	void insertRst(ListBrlyMPlntype& rst, bool transact = false);
	void updateRec(BrlyMPlntype* rec);
	void updateRst(ListBrlyMPlntype& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMPlntype** rec);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMPlntype: C++ wrapper for table TblBrlyMPlntype (PgSQL database)
	*/
class PgTblBrlyMPlntype : public TblBrlyMPlntype, public Sbecore::PgTable {

public:
	PgTblBrlyMPlntype();
	~PgTblBrlyMPlntype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMPlntype** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMPlntype& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMPlntype** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMPlntype** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMPlntype& rst);

	Sbecore::ubigint insertRec(BrlyMPlntype* rec);
	void insertRst(ListBrlyMPlntype& rst, bool transact = false);
	void updateRec(BrlyMPlntype* rec);
	void updateRst(ListBrlyMPlntype& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMPlntype** rec);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif
