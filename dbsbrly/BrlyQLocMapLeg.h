/**
	* \file BrlyQLocMapLeg.h
	* Dbs and XML wrapper for table TblBrlyQLocMapLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCMAPLEG_H
#define BRLYQLOCMAPLEG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocMapLeg: record of TblBrlyQLocMapLeg
	*/
class BrlyQLocMapLeg {

public:
	BrlyQLocMapLeg(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mbgnRefBrlyMLocation = 0, const Sbecore::ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0, const double lam1 = 0.0, const double lam2 = 0.0, const double lam3 = 0.0);

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	double x1VisLegphi0;
	double x1VisLegphi1;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint mbgnRefBrlyMLocation;
	Sbecore::ubigint mendRefBrlyMLocation;
	double dx;
	double dy;
	double x0;
	double y0;
	double lam1;
	double lam2;
	double lam3;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocMapLeg: recordset of TblBrlyQLocMapLeg
	*/
class ListBrlyQLocMapLeg {

public:
	ListBrlyQLocMapLeg();
	ListBrlyQLocMapLeg(const ListBrlyQLocMapLeg& src);
	~ListBrlyQLocMapLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMapLeg* rec);

	ListBrlyQLocMapLeg& operator=(const ListBrlyQLocMapLeg& src);

public:
	std::vector<BrlyQLocMapLeg*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocMapLeg: C++ wrapper for table TblBrlyQLocMapLeg
	*/
class TblBrlyQLocMapLeg {

public:
	TblBrlyQLocMapLeg();
	virtual ~TblBrlyQLocMapLeg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMapLeg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMapLeg& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocMapLeg* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocMapLeg** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mbgnRefBrlyMLocation = 0, const Sbecore::ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0, const double lam1 = 0.0, const double lam2 = 0.0, const double lam3 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocMapLeg& rst, BrlyQLocMapLeg** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mbgnRefBrlyMLocation = 0, const Sbecore::ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0, const double lam1 = 0.0, const double lam2 = 0.0, const double lam3 = 0.0);
	virtual void insertRst(ListBrlyQLocMapLeg& rst);
	virtual void updateRec(BrlyQLocMapLeg* rec);
	virtual void updateRst(ListBrlyQLocMapLeg& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMapLeg** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMapLeg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocMapLeg: C++ wrapper for table TblBrlyQLocMapLeg (MySQL database)
	*/
class MyTblBrlyQLocMapLeg : public TblBrlyQLocMapLeg, public Sbecore::MyTable {

public:
	MyTblBrlyQLocMapLeg();
	~MyTblBrlyQLocMapLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMapLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMapLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLocMapLeg* rec);
	void insertRst(ListBrlyQLocMapLeg& rst);
	void updateRec(BrlyQLocMapLeg* rec);
	void updateRst(ListBrlyQLocMapLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMapLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMapLeg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocMapLeg: C++ wrapper for table TblBrlyQLocMapLeg (PgSQL database)
	*/
class PgTblBrlyQLocMapLeg : public TblBrlyQLocMapLeg, public Sbecore::PgTable {

public:
	PgTblBrlyQLocMapLeg();
	~PgTblBrlyQLocMapLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMapLeg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMapLeg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMapLeg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMapLeg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMapLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMapLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLocMapLeg* rec);
	void insertRst(ListBrlyQLocMapLeg& rst);
	void updateRec(BrlyQLocMapLeg* rec);
	void updateRst(ListBrlyQLocMapLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMapLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMapLeg& rst);
};
#endif

#endif
