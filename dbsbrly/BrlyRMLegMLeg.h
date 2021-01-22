/**
	* \file BrlyRMLegMLeg.h
	* database access for table TblBrlyRMLegMLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYRMLEGMLEG_H
#define BRLYRMLEGMLEG_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyRMLegMLeg: record of TblBrlyRMLegMLeg
	*/
class BrlyRMLegMLeg {

public:
	BrlyRMLegMLeg(const Sbecore::ubigint ref = 0, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const Sbecore::ubigint dstRefBrlyMLeg = 0, const Sbecore::ubigint orgRefBrlyMLeg = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);

public:
	Sbecore::ubigint ref;
	double x1VisDstLegphi0;
	double x1VisDstLegphi1;
	Sbecore::ubigint dstRefBrlyMLeg;
	Sbecore::ubigint orgRefBrlyMLeg;
	double VisOrgLegphi0;
	double VisOrgLegphi1;
	double xVisDstLegphi0;
	double xVisDstLegphi1;
	double xVisOrgLegphi0;
	double xVisOrgLegphi1;

public:
	bool operator==(const BrlyRMLegMLeg& comp);
	bool operator!=(const BrlyRMLegMLeg& comp);
};

/**
	* ListBrlyRMLegMLeg: recordset of TblBrlyRMLegMLeg
	*/
class ListBrlyRMLegMLeg {

public:
	ListBrlyRMLegMLeg();
	ListBrlyRMLegMLeg(const ListBrlyRMLegMLeg& src);
	~ListBrlyRMLegMLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyRMLegMLeg* rec);

	BrlyRMLegMLeg* operator[](const Sbecore::uint ix);
	ListBrlyRMLegMLeg& operator=(const ListBrlyRMLegMLeg& src);
	bool operator==(const ListBrlyRMLegMLeg& comp);
	bool operator!=(const ListBrlyRMLegMLeg& comp);

public:
	std::vector<BrlyRMLegMLeg*> nodes;
};

/**
	* TblBrlyRMLegMLeg: C++ wrapper for table TblBrlyRMLegMLeg
	*/
class TblBrlyRMLegMLeg {

public:

public:
	TblBrlyRMLegMLeg();
	virtual ~TblBrlyRMLegMLeg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyRMLegMLeg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMLegMLeg& rst);

	virtual Sbecore::ubigint insertRec(BrlyRMLegMLeg* rec);
	Sbecore::ubigint insertNewRec(BrlyRMLegMLeg** rec = NULL, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const Sbecore::ubigint dstRefBrlyMLeg = 0, const Sbecore::ubigint orgRefBrlyMLeg = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyRMLegMLeg& rst, BrlyRMLegMLeg** rec = NULL, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const Sbecore::ubigint dstRefBrlyMLeg = 0, const Sbecore::ubigint orgRefBrlyMLeg = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);
	virtual void insertRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	virtual void updateRec(BrlyRMLegMLeg* rec);
	virtual void updateRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyRMLegMLeg** rec);
	virtual Sbecore::ubigint loadRstByDlg(Sbecore::ubigint dstRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
	virtual Sbecore::ubigint loadRstByOlg(Sbecore::ubigint orgRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyRMLegMLeg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyRMLegMLeg: C++ wrapper for table TblBrlyRMLegMLeg (MySQL database)
	*/
class MyTblBrlyRMLegMLeg : public TblBrlyRMLegMLeg, public Sbecore::MyTable {

public:
	MyTblBrlyRMLegMLeg();
	~MyTblBrlyRMLegMLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMLegMLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMLegMLeg& rst);

	Sbecore::ubigint insertRec(BrlyRMLegMLeg* rec);
	void insertRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	void updateRec(BrlyRMLegMLeg* rec);
	void updateRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMLegMLeg** rec);
	Sbecore::ubigint loadRstByDlg(Sbecore::ubigint dstRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
	Sbecore::ubigint loadRstByOlg(Sbecore::ubigint orgRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyRMLegMLeg: C++ wrapper for table TblBrlyRMLegMLeg (PgSQL database)
	*/
class PgTblBrlyRMLegMLeg : public TblBrlyRMLegMLeg, public Sbecore::PgTable {

public:
	PgTblBrlyRMLegMLeg();
	~PgTblBrlyRMLegMLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMLegMLeg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyRMLegMLeg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMLegMLeg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMLegMLeg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMLegMLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMLegMLeg& rst);

	Sbecore::ubigint insertRec(BrlyRMLegMLeg* rec);
	void insertRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	void updateRec(BrlyRMLegMLeg* rec);
	void updateRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMLegMLeg** rec);
	Sbecore::ubigint loadRstByDlg(Sbecore::ubigint dstRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
	Sbecore::ubigint loadRstByOlg(Sbecore::ubigint orgRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
};
#endif

#endif
