/**
	* \file BrlyRMConnectionMSegment.h
	* database access for table TblBrlyRMConnectionMSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYRMCONNECTIONMSEGMENT_H
#define BRLYRMCONNECTIONMSEGMENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyRMConnectionMSegment: record of TblBrlyRMConnectionMSegment
	*/
class BrlyRMConnectionMSegment {

public:
	BrlyRMConnectionMSegment(const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::ubigint refBrlyMSegment = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint x1Start;
	Sbecore::uint x1Stop;
	double x2Legphi0;
	double x2Legphi1;
	Sbecore::ubigint refBrlyMConnection;
	Sbecore::ubigint refBrlyMSegment;

public:
	bool operator==(const BrlyRMConnectionMSegment& comp);
	bool operator!=(const BrlyRMConnectionMSegment& comp);
};

/**
	* ListBrlyRMConnectionMSegment: recordset of TblBrlyRMConnectionMSegment
	*/
class ListBrlyRMConnectionMSegment {

public:
	ListBrlyRMConnectionMSegment();
	ListBrlyRMConnectionMSegment(const ListBrlyRMConnectionMSegment& src);
	~ListBrlyRMConnectionMSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyRMConnectionMSegment* rec);

	BrlyRMConnectionMSegment* operator[](const Sbecore::uint ix);
	ListBrlyRMConnectionMSegment& operator=(const ListBrlyRMConnectionMSegment& src);
	bool operator==(const ListBrlyRMConnectionMSegment& comp);
	bool operator!=(const ListBrlyRMConnectionMSegment& comp);

public:
	std::vector<BrlyRMConnectionMSegment*> nodes;
};

/**
	* TblBrlyRMConnectionMSegment: C++ wrapper for table TblBrlyRMConnectionMSegment
	*/
class TblBrlyRMConnectionMSegment {

public:

public:
	TblBrlyRMConnectionMSegment();
	virtual ~TblBrlyRMConnectionMSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyRMConnectionMSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMConnectionMSegment& rst);

	virtual Sbecore::ubigint insertRec(BrlyRMConnectionMSegment* rec);
	Sbecore::ubigint insertNewRec(BrlyRMConnectionMSegment** rec = NULL, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::ubigint refBrlyMSegment = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyRMConnectionMSegment& rst, BrlyRMConnectionMSegment** rec = NULL, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::ubigint refBrlyMSegment = 0);
	virtual void insertRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	virtual void updateRec(BrlyRMConnectionMSegment* rec);
	virtual void updateRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyRMConnectionMSegment** rec);
	virtual Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMSegment& rst);
	virtual Sbecore::ubigint loadRstBySeg(Sbecore::ubigint refBrlyMSegment, const bool append, ListBrlyRMConnectionMSegment& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyRMConnectionMSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyRMConnectionMSegment: C++ wrapper for table TblBrlyRMConnectionMSegment (MySQL database)
	*/
class MyTblBrlyRMConnectionMSegment : public TblBrlyRMConnectionMSegment, public Sbecore::MyTable {

public:
	MyTblBrlyRMConnectionMSegment();
	~MyTblBrlyRMConnectionMSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMConnectionMSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMConnectionMSegment& rst);

	Sbecore::ubigint insertRec(BrlyRMConnectionMSegment* rec);
	void insertRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	void updateRec(BrlyRMConnectionMSegment* rec);
	void updateRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMConnectionMSegment** rec);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMSegment& rst);
	Sbecore::ubigint loadRstBySeg(Sbecore::ubigint refBrlyMSegment, const bool append, ListBrlyRMConnectionMSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyRMConnectionMSegment: C++ wrapper for table TblBrlyRMConnectionMSegment (PgSQL database)
	*/
class PgTblBrlyRMConnectionMSegment : public TblBrlyRMConnectionMSegment, public Sbecore::PgTable {

public:
	PgTblBrlyRMConnectionMSegment();
	~PgTblBrlyRMConnectionMSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMConnectionMSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyRMConnectionMSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMConnectionMSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMConnectionMSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMConnectionMSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMConnectionMSegment& rst);

	Sbecore::ubigint insertRec(BrlyRMConnectionMSegment* rec);
	void insertRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	void updateRec(BrlyRMConnectionMSegment* rec);
	void updateRst(ListBrlyRMConnectionMSegment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMConnectionMSegment** rec);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyRMConnectionMSegment& rst);
	Sbecore::ubigint loadRstBySeg(Sbecore::ubigint refBrlyMSegment, const bool append, ListBrlyRMConnectionMSegment& rst);
};
#endif

#endif
