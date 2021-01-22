/**
	* \file BrlyRMLocationMSegment.h
	* database access for table TblBrlyRMLocationMSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYRMLOCATIONMSEGMENT_H
#define BRLYRMLOCATIONMSEGMENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyRMLocationMSegment: record of TblBrlyRMLocationMSegment
	*/
class BrlyRMLocationMSegment {

public:
	BrlyRMLocationMSegment(const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const Sbecore::ubigint refBrlyMLocation = 0, const Sbecore::ubigint refBrlyMSegment = 0, const double segphi = 0.0, const double segtheta = 0.0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint x1Start;
	Sbecore::uint x1Stop;
	double x2VisSegphi0;
	double x2VisSegphi1;
	Sbecore::ubigint refBrlyMLocation;
	Sbecore::ubigint refBrlyMSegment;
	double segphi;
	double segtheta;

public:
	bool operator==(const BrlyRMLocationMSegment& comp);
	bool operator!=(const BrlyRMLocationMSegment& comp);
};

/**
	* ListBrlyRMLocationMSegment: recordset of TblBrlyRMLocationMSegment
	*/
class ListBrlyRMLocationMSegment {

public:
	ListBrlyRMLocationMSegment();
	ListBrlyRMLocationMSegment(const ListBrlyRMLocationMSegment& src);
	~ListBrlyRMLocationMSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyRMLocationMSegment* rec);

	BrlyRMLocationMSegment* operator[](const Sbecore::uint ix);
	ListBrlyRMLocationMSegment& operator=(const ListBrlyRMLocationMSegment& src);
	bool operator==(const ListBrlyRMLocationMSegment& comp);
	bool operator!=(const ListBrlyRMLocationMSegment& comp);

public:
	std::vector<BrlyRMLocationMSegment*> nodes;
};

/**
	* TblBrlyRMLocationMSegment: C++ wrapper for table TblBrlyRMLocationMSegment
	*/
class TblBrlyRMLocationMSegment {

public:

public:
	TblBrlyRMLocationMSegment();
	virtual ~TblBrlyRMLocationMSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyRMLocationMSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMLocationMSegment& rst);

	virtual Sbecore::ubigint insertRec(BrlyRMLocationMSegment* rec);
	Sbecore::ubigint insertNewRec(BrlyRMLocationMSegment** rec = NULL, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const Sbecore::ubigint refBrlyMLocation = 0, const Sbecore::ubigint refBrlyMSegment = 0, const double segphi = 0.0, const double segtheta = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyRMLocationMSegment& rst, BrlyRMLocationMSegment** rec = NULL, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const Sbecore::ubigint refBrlyMLocation = 0, const Sbecore::ubigint refBrlyMSegment = 0, const double segphi = 0.0, const double segtheta = 0.0);
	virtual void insertRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	virtual void updateRec(BrlyRMLocationMSegment* rec);
	virtual void updateRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyRMLocationMSegment** rec);
	virtual Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refBrlyMLocation, const bool append, ListBrlyRMLocationMSegment& rst);
	virtual Sbecore::ubigint loadRstBySeg(Sbecore::ubigint refBrlyMSegment, const bool append, ListBrlyRMLocationMSegment& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyRMLocationMSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyRMLocationMSegment: C++ wrapper for table TblBrlyRMLocationMSegment (MySQL database)
	*/
class MyTblBrlyRMLocationMSegment : public TblBrlyRMLocationMSegment, public Sbecore::MyTable {

public:
	MyTblBrlyRMLocationMSegment();
	~MyTblBrlyRMLocationMSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMLocationMSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMLocationMSegment& rst);

	Sbecore::ubigint insertRec(BrlyRMLocationMSegment* rec);
	void insertRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	void updateRec(BrlyRMLocationMSegment* rec);
	void updateRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMLocationMSegment** rec);
	Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refBrlyMLocation, const bool append, ListBrlyRMLocationMSegment& rst);
	Sbecore::ubigint loadRstBySeg(Sbecore::ubigint refBrlyMSegment, const bool append, ListBrlyRMLocationMSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyRMLocationMSegment: C++ wrapper for table TblBrlyRMLocationMSegment (PgSQL database)
	*/
class PgTblBrlyRMLocationMSegment : public TblBrlyRMLocationMSegment, public Sbecore::PgTable {

public:
	PgTblBrlyRMLocationMSegment();
	~PgTblBrlyRMLocationMSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMLocationMSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyRMLocationMSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMLocationMSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMLocationMSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMLocationMSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMLocationMSegment& rst);

	Sbecore::ubigint insertRec(BrlyRMLocationMSegment* rec);
	void insertRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	void updateRec(BrlyRMLocationMSegment* rec);
	void updateRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMLocationMSegment** rec);
	Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refBrlyMLocation, const bool append, ListBrlyRMLocationMSegment& rst);
	Sbecore::ubigint loadRstBySeg(Sbecore::ubigint refBrlyMSegment, const bool append, ListBrlyRMLocationMSegment& rst);
};
#endif

#endif
