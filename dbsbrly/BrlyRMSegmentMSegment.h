/**
	* \file BrlyRMSegmentMSegment.h
	* database access for table TblBrlyRMSegmentMSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYRMSEGMENTMSEGMENT_H
#define BRLYRMSEGMENTMSEGMENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyRMSegmentMSegment: record of TblBrlyRMSegmentMSegment
	*/
class BrlyRMSegmentMSegment {

public:
	BrlyRMSegmentMSegment(const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const Sbecore::ubigint dstRefBrlyMSegment = 0, const Sbecore::ubigint orgRefBrlyMSegment = 0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint x1Start;
	Sbecore::uint x1Stop;
	double x2VisDstSegphi0;
	double x2VisDstSegphi1;
	Sbecore::ubigint dstRefBrlyMSegment;
	Sbecore::ubigint orgRefBrlyMSegment;
	double VisOrgSegphi0;
	double VisOrgSegphi1;

public:
	bool operator==(const BrlyRMSegmentMSegment& comp);
	bool operator!=(const BrlyRMSegmentMSegment& comp);
};

/**
	* ListBrlyRMSegmentMSegment: recordset of TblBrlyRMSegmentMSegment
	*/
class ListBrlyRMSegmentMSegment {

public:
	ListBrlyRMSegmentMSegment();
	ListBrlyRMSegmentMSegment(const ListBrlyRMSegmentMSegment& src);
	~ListBrlyRMSegmentMSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyRMSegmentMSegment* rec);

	BrlyRMSegmentMSegment* operator[](const Sbecore::uint ix);
	ListBrlyRMSegmentMSegment& operator=(const ListBrlyRMSegmentMSegment& src);
	bool operator==(const ListBrlyRMSegmentMSegment& comp);
	bool operator!=(const ListBrlyRMSegmentMSegment& comp);

public:
	std::vector<BrlyRMSegmentMSegment*> nodes;
};

/**
	* TblBrlyRMSegmentMSegment: C++ wrapper for table TblBrlyRMSegmentMSegment
	*/
class TblBrlyRMSegmentMSegment {

public:

public:
	TblBrlyRMSegmentMSegment();
	virtual ~TblBrlyRMSegmentMSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyRMSegmentMSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMSegmentMSegment& rst);

	virtual Sbecore::ubigint insertRec(BrlyRMSegmentMSegment* rec);
	Sbecore::ubigint insertNewRec(BrlyRMSegmentMSegment** rec = NULL, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const Sbecore::ubigint dstRefBrlyMSegment = 0, const Sbecore::ubigint orgRefBrlyMSegment = 0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyRMSegmentMSegment& rst, BrlyRMSegmentMSegment** rec = NULL, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const Sbecore::ubigint dstRefBrlyMSegment = 0, const Sbecore::ubigint orgRefBrlyMSegment = 0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);
	virtual void insertRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	virtual void updateRec(BrlyRMSegmentMSegment* rec);
	virtual void updateRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyRMSegmentMSegment** rec);
	virtual Sbecore::ubigint loadRstByDsg(Sbecore::ubigint dstRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
	virtual Sbecore::ubigint loadRstByOsg(Sbecore::ubigint orgRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyRMSegmentMSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyRMSegmentMSegment: C++ wrapper for table TblBrlyRMSegmentMSegment (MySQL database)
	*/
class MyTblBrlyRMSegmentMSegment : public TblBrlyRMSegmentMSegment, public Sbecore::MyTable {

public:
	MyTblBrlyRMSegmentMSegment();
	~MyTblBrlyRMSegmentMSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMSegmentMSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMSegmentMSegment& rst);

	Sbecore::ubigint insertRec(BrlyRMSegmentMSegment* rec);
	void insertRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	void updateRec(BrlyRMSegmentMSegment* rec);
	void updateRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMSegmentMSegment** rec);
	Sbecore::ubigint loadRstByDsg(Sbecore::ubigint dstRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
	Sbecore::ubigint loadRstByOsg(Sbecore::ubigint orgRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyRMSegmentMSegment: C++ wrapper for table TblBrlyRMSegmentMSegment (PgSQL database)
	*/
class PgTblBrlyRMSegmentMSegment : public TblBrlyRMSegmentMSegment, public Sbecore::PgTable {

public:
	PgTblBrlyRMSegmentMSegment();
	~PgTblBrlyRMSegmentMSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMSegmentMSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyRMSegmentMSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMSegmentMSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMSegmentMSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMSegmentMSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMSegmentMSegment& rst);

	Sbecore::ubigint insertRec(BrlyRMSegmentMSegment* rec);
	void insertRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	void updateRec(BrlyRMSegmentMSegment* rec);
	void updateRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMSegmentMSegment** rec);
	Sbecore::ubigint loadRstByDsg(Sbecore::ubigint dstRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
	Sbecore::ubigint loadRstByOsg(Sbecore::ubigint orgRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
};
#endif

#endif
