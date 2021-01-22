/**
	* \file BrlyAVValuelistVal.h
	* database access for table TblBrlyAVValuelistVal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYAVVALUELISTVAL_H
#define BRLYAVVALUELISTVAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyAVValuelistVal: record of TblBrlyAVValuelistVal
	*/
class BrlyAVValuelistVal {

public:
	BrlyAVValuelistVal(const Sbecore::ubigint ref = 0, const Sbecore::uint vlsIxBrlyVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxBrlyVLocale = 0, const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint vlsIxBrlyVValuelist;
	Sbecore::uint vlsNum;
	Sbecore::uint x1IxBrlyVLocale;
	std::string Val;

public:
	bool operator==(const BrlyAVValuelistVal& comp);
	bool operator!=(const BrlyAVValuelistVal& comp);
};

/**
	* ListBrlyAVValuelistVal: recordset of TblBrlyAVValuelistVal
	*/
class ListBrlyAVValuelistVal {

public:
	ListBrlyAVValuelistVal();
	ListBrlyAVValuelistVal(const ListBrlyAVValuelistVal& src);
	~ListBrlyAVValuelistVal();

	void clear();
	unsigned int size() const;
	void append(BrlyAVValuelistVal* rec);

	BrlyAVValuelistVal* operator[](const Sbecore::uint ix);
	ListBrlyAVValuelistVal& operator=(const ListBrlyAVValuelistVal& src);
	bool operator==(const ListBrlyAVValuelistVal& comp);
	bool operator!=(const ListBrlyAVValuelistVal& comp);

public:
	std::vector<BrlyAVValuelistVal*> nodes;
};

/**
	* TblBrlyAVValuelistVal: C++ wrapper for table TblBrlyAVValuelistVal
	*/
class TblBrlyAVValuelistVal {

public:

public:
	TblBrlyAVValuelistVal();
	virtual ~TblBrlyAVValuelistVal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyAVValuelistVal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAVValuelistVal& rst);

	virtual Sbecore::ubigint insertRec(BrlyAVValuelistVal* rec);
	Sbecore::ubigint insertNewRec(BrlyAVValuelistVal** rec = NULL, const Sbecore::uint vlsIxBrlyVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxBrlyVLocale = 0, const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyAVValuelistVal& rst, BrlyAVValuelistVal** rec = NULL, const Sbecore::uint vlsIxBrlyVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxBrlyVLocale = 0, const std::string Val = "");
	virtual void insertRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	virtual void updateRec(BrlyAVValuelistVal* rec);
	virtual void updateRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyAVValuelistVal** rec);
	virtual Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxBrlyVValuelist, Sbecore::uint x1IxBrlyVLocale, const bool append, ListBrlyAVValuelistVal& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyAVValuelistVal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyAVValuelistVal: C++ wrapper for table TblBrlyAVValuelistVal (MySQL database)
	*/
class MyTblBrlyAVValuelistVal : public TblBrlyAVValuelistVal, public Sbecore::MyTable {

public:
	MyTblBrlyAVValuelistVal();
	~MyTblBrlyAVValuelistVal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAVValuelistVal& rst);

	Sbecore::ubigint insertRec(BrlyAVValuelistVal* rec);
	void insertRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	void updateRec(BrlyAVValuelistVal* rec);
	void updateRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxBrlyVValuelist, Sbecore::uint x1IxBrlyVLocale, const bool append, ListBrlyAVValuelistVal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyAVValuelistVal: C++ wrapper for table TblBrlyAVValuelistVal (PgSQL database)
	*/
class PgTblBrlyAVValuelistVal : public TblBrlyAVValuelistVal, public Sbecore::PgTable {

public:
	PgTblBrlyAVValuelistVal();
	~PgTblBrlyAVValuelistVal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAVValuelistVal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyAVValuelistVal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAVValuelistVal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAVValuelistVal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAVValuelistVal& rst);

	Sbecore::ubigint insertRec(BrlyAVValuelistVal* rec);
	void insertRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	void updateRec(BrlyAVValuelistVal* rec);
	void updateRst(ListBrlyAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxBrlyVValuelist, Sbecore::uint x1IxBrlyVLocale, const bool append, ListBrlyAVValuelistVal& rst);
};
#endif

#endif
