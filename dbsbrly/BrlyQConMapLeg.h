/**
	* \file BrlyQConMapLeg.h
	* Dbs and XML wrapper for table TblBrlyQConMapLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCONMAPLEG_H
#define BRLYQCONMAPLEG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQConMapLeg: record of TblBrlyQConMapLeg
	*/
class BrlyQConMapLeg {

public:
	BrlyQConMapLeg(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mbgnRefBrlyMLocation = 0, const Sbecore::ubigint mendRefBrlyMLocation = 0, const double mdeltaphi = 0.0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	double VisOrgLegphi0;
	double VisOrgLegphi1;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint mbgnRefBrlyMLocation;
	Sbecore::ubigint mendRefBrlyMLocation;
	double mdeltaphi;
	double dx;
	double dy;
	double x0;
	double y0;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQConMapLeg: recordset of TblBrlyQConMapLeg
	*/
class ListBrlyQConMapLeg {

public:
	ListBrlyQConMapLeg();
	ListBrlyQConMapLeg(const ListBrlyQConMapLeg& src);
	~ListBrlyQConMapLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMapLeg* rec);

	ListBrlyQConMapLeg& operator=(const ListBrlyQConMapLeg& src);

public:
	std::vector<BrlyQConMapLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQConMapLeg: C++ wrapper for table TblBrlyQConMapLeg
	*/
class TblBrlyQConMapLeg {

public:
	TblBrlyQConMapLeg();
	virtual ~TblBrlyQConMapLeg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapLeg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapLeg& rst);

	virtual Sbecore::ubigint insertRec(BrlyQConMapLeg* rec);
	Sbecore::ubigint insertNewRec(BrlyQConMapLeg** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mbgnRefBrlyMLocation = 0, const Sbecore::ubigint mendRefBrlyMLocation = 0, const double mdeltaphi = 0.0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQConMapLeg& rst, BrlyQConMapLeg** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mbgnRefBrlyMLocation = 0, const Sbecore::ubigint mendRefBrlyMLocation = 0, const double mdeltaphi = 0.0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);
	virtual void insertRst(ListBrlyQConMapLeg& rst);
	virtual void updateRec(BrlyQConMapLeg* rec);
	virtual void updateRst(ListBrlyQConMapLeg& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapLeg** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapLeg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQConMapLeg: C++ wrapper for table TblBrlyQConMapLeg (MySQL database)
	*/
class MyTblBrlyQConMapLeg : public TblBrlyQConMapLeg, public Sbecore::MyTable {

public:
	MyTblBrlyQConMapLeg();
	~MyTblBrlyQConMapLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapLeg& rst);

	Sbecore::ubigint insertRec(BrlyQConMapLeg* rec);
	void insertRst(ListBrlyQConMapLeg& rst);
	void updateRec(BrlyQConMapLeg* rec);
	void updateRst(ListBrlyQConMapLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapLeg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQConMapLeg: C++ wrapper for table TblBrlyQConMapLeg (PgSQL database)
	*/
class PgTblBrlyQConMapLeg : public TblBrlyQConMapLeg, public Sbecore::PgTable {

public:
	PgTblBrlyQConMapLeg();
	~PgTblBrlyQConMapLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMapLeg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMapLeg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMapLeg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMapLeg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapLeg& rst);

	Sbecore::ubigint insertRec(BrlyQConMapLeg* rec);
	void insertRst(ListBrlyQConMapLeg& rst);
	void updateRec(BrlyQConMapLeg* rec);
	void updateRst(ListBrlyQConMapLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapLeg& rst);
};
#endif

#endif
