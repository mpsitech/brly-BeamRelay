/**
	* \file BrlyQLegMNLocation.h
	* Dbs and XML wrapper for table TblBrlyQLegMNLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLEGMNLOCATION_H
#define BRLYQLEGMNLOCATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLegMNLocation: record of TblBrlyQLegMNLocation
	*/
class BrlyQLegMNLocation {

public:
	BrlyQLegMNLocation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	double x1VisLegphi0;
	double x1VisLegphi1;
	double legphi;
	double legtheta;
	double xVisLegphi0;
	double xVisLegphi1;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLegMNLocation: recordset of TblBrlyQLegMNLocation
	*/
class ListBrlyQLegMNLocation {

public:
	ListBrlyQLegMNLocation();
	ListBrlyQLegMNLocation(const ListBrlyQLegMNLocation& src);
	~ListBrlyQLegMNLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegMNLocation* rec);

	ListBrlyQLegMNLocation& operator=(const ListBrlyQLegMNLocation& src);

public:
	std::vector<BrlyQLegMNLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLegMNLocation: C++ wrapper for table TblBrlyQLegMNLocation
	*/
class TblBrlyQLegMNLocation {

public:
	TblBrlyQLegMNLocation();
	virtual ~TblBrlyQLegMNLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLegMNLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegMNLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLegMNLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyQLegMNLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLegMNLocation& rst, BrlyQLegMNLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	virtual void insertRst(ListBrlyQLegMNLocation& rst);
	virtual void updateRec(BrlyQLegMNLocation* rec);
	virtual void updateRst(ListBrlyQLegMNLocation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegMNLocation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegMNLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLegMNLocation: C++ wrapper for table TblBrlyQLegMNLocation (MySQL database)
	*/
class MyTblBrlyQLegMNLocation : public TblBrlyQLegMNLocation, public Sbecore::MyTable {

public:
	MyTblBrlyQLegMNLocation();
	~MyTblBrlyQLegMNLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegMNLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegMNLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLegMNLocation* rec);
	void insertRst(ListBrlyQLegMNLocation& rst);
	void updateRec(BrlyQLegMNLocation* rec);
	void updateRst(ListBrlyQLegMNLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegMNLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegMNLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLegMNLocation: C++ wrapper for table TblBrlyQLegMNLocation (PgSQL database)
	*/
class PgTblBrlyQLegMNLocation : public TblBrlyQLegMNLocation, public Sbecore::PgTable {

public:
	PgTblBrlyQLegMNLocation();
	~PgTblBrlyQLegMNLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegMNLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegMNLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegMNLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegMNLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegMNLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegMNLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLegMNLocation* rec);
	void insertRst(ListBrlyQLegMNLocation& rst);
	void updateRec(BrlyQLegMNLocation* rec);
	void updateRst(ListBrlyQLegMNLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegMNLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegMNLocation& rst);
};
#endif

#endif
