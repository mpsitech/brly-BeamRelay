/**
	* \file BrlyAMPersonDetail.h
	* database access for table TblBrlyAMPersonDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYAMPERSONDETAIL_H
#define BRLYAMPERSONDETAIL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyAMPersonDetail: record of TblBrlyAMPersonDetail
	*/
class BrlyAMPersonDetail {

public:
	BrlyAMPersonDetail(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMPerson;
	std::string x1SrefKType;
	std::string Val;

public:
	bool operator==(const BrlyAMPersonDetail& comp);
	bool operator!=(const BrlyAMPersonDetail& comp);
};

/**
	* ListBrlyAMPersonDetail: recordset of TblBrlyAMPersonDetail
	*/
class ListBrlyAMPersonDetail {

public:
	ListBrlyAMPersonDetail();
	ListBrlyAMPersonDetail(const ListBrlyAMPersonDetail& src);
	~ListBrlyAMPersonDetail();

	void clear();
	unsigned int size() const;
	void append(BrlyAMPersonDetail* rec);

	BrlyAMPersonDetail* operator[](const Sbecore::uint ix);
	ListBrlyAMPersonDetail& operator=(const ListBrlyAMPersonDetail& src);
	bool operator==(const ListBrlyAMPersonDetail& comp);
	bool operator!=(const ListBrlyAMPersonDetail& comp);

public:
	std::vector<BrlyAMPersonDetail*> nodes;
};

/**
	* TblBrlyAMPersonDetail: C++ wrapper for table TblBrlyAMPersonDetail
	*/
class TblBrlyAMPersonDetail {

public:

public:
	TblBrlyAMPersonDetail();
	virtual ~TblBrlyAMPersonDetail();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyAMPersonDetail** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMPersonDetail& rst);

	virtual Sbecore::ubigint insertRec(BrlyAMPersonDetail* rec);
	Sbecore::ubigint insertNewRec(BrlyAMPersonDetail** rec = NULL, const Sbecore::ubigint refBrlyMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyAMPersonDetail& rst, BrlyAMPersonDetail** rec = NULL, const Sbecore::ubigint refBrlyMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");
	virtual void insertRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	virtual void updateRec(BrlyAMPersonDetail* rec);
	virtual void updateRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyAMPersonDetail** rec);
	virtual bool loadRecByPrsTyp(Sbecore::ubigint refBrlyMPerson, std::string x1SrefKType, BrlyAMPersonDetail** rec);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refBrlyMPerson, const bool append, ListBrlyAMPersonDetail& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyAMPersonDetail& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyAMPersonDetail: C++ wrapper for table TblBrlyAMPersonDetail (MySQL database)
	*/
class MyTblBrlyAMPersonDetail : public TblBrlyAMPersonDetail, public Sbecore::MyTable {

public:
	MyTblBrlyAMPersonDetail();
	~MyTblBrlyAMPersonDetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMPersonDetail& rst);

	Sbecore::ubigint insertRec(BrlyAMPersonDetail* rec);
	void insertRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	void updateRec(BrlyAMPersonDetail* rec);
	void updateRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAMPersonDetail** rec);
	bool loadRecByPrsTyp(Sbecore::ubigint refBrlyMPerson, std::string x1SrefKType, BrlyAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refBrlyMPerson, const bool append, ListBrlyAMPersonDetail& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyAMPersonDetail: C++ wrapper for table TblBrlyAMPersonDetail (PgSQL database)
	*/
class PgTblBrlyAMPersonDetail : public TblBrlyAMPersonDetail, public Sbecore::PgTable {

public:
	PgTblBrlyAMPersonDetail();
	~PgTblBrlyAMPersonDetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAMPersonDetail** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyAMPersonDetail& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAMPersonDetail** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAMPersonDetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAMPersonDetail& rst);

	Sbecore::ubigint insertRec(BrlyAMPersonDetail* rec);
	void insertRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	void updateRec(BrlyAMPersonDetail* rec);
	void updateRst(ListBrlyAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAMPersonDetail** rec);
	bool loadRecByPrsTyp(Sbecore::ubigint refBrlyMPerson, std::string x1SrefKType, BrlyAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refBrlyMPerson, const bool append, ListBrlyAMPersonDetail& rst);
};
#endif

#endif
