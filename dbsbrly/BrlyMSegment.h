/**
	* \file BrlyMSegment.h
	* database access for table TblBrlyMSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMSEGMENT_H
#define BRLYMSEGMENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecBrlyVMSegmentRefTbl TblBrlyMSegment::VecVRefTbl

/**
	* BrlyMSegment: record of TblBrlyMSegment
	*/
class BrlyMSegment {

public:
	BrlyMSegment(const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint refNum = 0, const double deltaphi = 0.0, const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const bool Calcdone = false);

public:
	Sbecore::ubigint ref;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::uint refNum;
	double deltaphi;
	double alt0;
	double alt1;
	double theta0;
	double theta1;
	double phi0;
	double phi1;
	Sbecore::uint start;
	Sbecore::uint stop;
	bool Calcdone;

public:
	bool operator==(const BrlyMSegment& comp);
	bool operator!=(const BrlyMSegment& comp);
};

/**
	* ListBrlyMSegment: recordset of TblBrlyMSegment
	*/
class ListBrlyMSegment {

public:
	ListBrlyMSegment();
	ListBrlyMSegment(const ListBrlyMSegment& src);
	~ListBrlyMSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyMSegment* rec);

	BrlyMSegment* operator[](const Sbecore::uint ix);
	ListBrlyMSegment& operator=(const ListBrlyMSegment& src);
	bool operator==(const ListBrlyMSegment& comp);
	bool operator!=(const ListBrlyMSegment& comp);

public:
	std::vector<BrlyMSegment*> nodes;
};

/**
	* TblBrlyMSegment: C++ wrapper for table TblBrlyMSegment
	*/
class TblBrlyMSegment {

public:
	/**
		* VecVRefTbl (full: VecBrlyVMSegmentRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint CON = 1;
		static const Sbecore::uint FLT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblBrlyMSegment();
	virtual ~TblBrlyMSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMSegment& rst);

	virtual Sbecore::ubigint insertRec(BrlyMSegment* rec);
	Sbecore::ubigint insertNewRec(BrlyMSegment** rec = NULL, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint refNum = 0, const double deltaphi = 0.0, const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const bool Calcdone = false);
	Sbecore::ubigint appendNewRecToRst(ListBrlyMSegment& rst, BrlyMSegment** rec = NULL, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint refNum = 0, const double deltaphi = 0.0, const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const bool Calcdone = false);
	virtual void insertRst(ListBrlyMSegment& rst, bool transact = false);
	virtual void updateRec(BrlyMSegment* rec);
	virtual void updateRst(ListBrlyMSegment& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMSegment** rec);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListBrlyMSegment& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMSegment: C++ wrapper for table TblBrlyMSegment (MySQL database)
	*/
class MyTblBrlyMSegment : public TblBrlyMSegment, public Sbecore::MyTable {

public:
	MyTblBrlyMSegment();
	~MyTblBrlyMSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMSegment& rst);

	Sbecore::ubigint insertRec(BrlyMSegment* rec);
	void insertRst(ListBrlyMSegment& rst, bool transact = false);
	void updateRec(BrlyMSegment* rec);
	void updateRst(ListBrlyMSegment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMSegment** rec);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListBrlyMSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMSegment: C++ wrapper for table TblBrlyMSegment (PgSQL database)
	*/
class PgTblBrlyMSegment : public TblBrlyMSegment, public Sbecore::PgTable {

public:
	PgTblBrlyMSegment();
	~PgTblBrlyMSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMSegment& rst);

	Sbecore::ubigint insertRec(BrlyMSegment* rec);
	void insertRst(ListBrlyMSegment& rst, bool transact = false);
	void updateRec(BrlyMSegment* rec);
	void updateRst(ListBrlyMSegment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMSegment** rec);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListBrlyMSegment& rst);
};
#endif

#endif
