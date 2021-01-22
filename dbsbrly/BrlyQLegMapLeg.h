/**
	* \file BrlyQLegMapLeg.h
	* Dbs and XML wrapper for table TblBrlyQLegMapLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLEGMAPLEG_H
#define BRLYQLEGMAPLEG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLegMapLeg: record of TblBrlyQLegMapLeg
	*/
class BrlyQLegMapLeg {

public:
	BrlyQLegMapLeg(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mbgnRefBrlyMLocation = 0, const Sbecore::ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);

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
	double dx;
	double dy;
	double x0;
	double y0;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLegMapLeg: recordset of TblBrlyQLegMapLeg
	*/
class ListBrlyQLegMapLeg {

public:
	ListBrlyQLegMapLeg();
	ListBrlyQLegMapLeg(const ListBrlyQLegMapLeg& src);
	~ListBrlyQLegMapLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegMapLeg* rec);

	ListBrlyQLegMapLeg& operator=(const ListBrlyQLegMapLeg& src);

public:
	std::vector<BrlyQLegMapLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLegMapLeg: C++ wrapper for table TblBrlyQLegMapLeg
	*/
class TblBrlyQLegMapLeg {

public:
	TblBrlyQLegMapLeg();
	virtual ~TblBrlyQLegMapLeg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLegMapLeg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegMapLeg& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLegMapLeg* rec);
	Sbecore::ubigint insertNewRec(BrlyQLegMapLeg** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mbgnRefBrlyMLocation = 0, const Sbecore::ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLegMapLeg& rst, BrlyQLegMapLeg** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mbgnRefBrlyMLocation = 0, const Sbecore::ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);
	virtual void insertRst(ListBrlyQLegMapLeg& rst);
	virtual void updateRec(BrlyQLegMapLeg* rec);
	virtual void updateRst(ListBrlyQLegMapLeg& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegMapLeg** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegMapLeg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLegMapLeg: C++ wrapper for table TblBrlyQLegMapLeg (MySQL database)
	*/
class MyTblBrlyQLegMapLeg : public TblBrlyQLegMapLeg, public Sbecore::MyTable {

public:
	MyTblBrlyQLegMapLeg();
	~MyTblBrlyQLegMapLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegMapLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegMapLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLegMapLeg* rec);
	void insertRst(ListBrlyQLegMapLeg& rst);
	void updateRec(BrlyQLegMapLeg* rec);
	void updateRst(ListBrlyQLegMapLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegMapLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegMapLeg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLegMapLeg: C++ wrapper for table TblBrlyQLegMapLeg (PgSQL database)
	*/
class PgTblBrlyQLegMapLeg : public TblBrlyQLegMapLeg, public Sbecore::PgTable {

public:
	PgTblBrlyQLegMapLeg();
	~PgTblBrlyQLegMapLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegMapLeg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegMapLeg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegMapLeg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegMapLeg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegMapLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegMapLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLegMapLeg* rec);
	void insertRst(ListBrlyQLegMapLeg& rst);
	void updateRec(BrlyQLegMapLeg* rec);
	void updateRst(ListBrlyQLegMapLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegMapLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegMapLeg& rst);
};
#endif

#endif
