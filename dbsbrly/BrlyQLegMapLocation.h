/**
	* \file BrlyQLegMapLocation.h
	* Dbs and XML wrapper for table TblBrlyQLegMapLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLEGMAPLOCATION_H
#define BRLYQLEGMAPLOCATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLegMapLocation: record of TblBrlyQLegMapLocation
	*/
class BrlyQLegMapLocation {

public:
	BrlyQLegMapLocation(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const double x = 0.0, const double y = 0.0);

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	double legphi;
	double legtheta;
	Sbecore::ubigint mref;
	std::string stubMref;
	double x;
	double y;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLegMapLocation: recordset of TblBrlyQLegMapLocation
	*/
class ListBrlyQLegMapLocation {

public:
	ListBrlyQLegMapLocation();
	ListBrlyQLegMapLocation(const ListBrlyQLegMapLocation& src);
	~ListBrlyQLegMapLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegMapLocation* rec);

	ListBrlyQLegMapLocation& operator=(const ListBrlyQLegMapLocation& src);

public:
	std::vector<BrlyQLegMapLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLegMapLocation: C++ wrapper for table TblBrlyQLegMapLocation
	*/
class TblBrlyQLegMapLocation {

public:
	TblBrlyQLegMapLocation();
	virtual ~TblBrlyQLegMapLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLegMapLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegMapLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLegMapLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyQLegMapLocation** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const double x = 0.0, const double y = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLegMapLocation& rst, BrlyQLegMapLocation** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const double x = 0.0, const double y = 0.0);
	virtual void insertRst(ListBrlyQLegMapLocation& rst);
	virtual void updateRec(BrlyQLegMapLocation* rec);
	virtual void updateRst(ListBrlyQLegMapLocation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegMapLocation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegMapLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLegMapLocation: C++ wrapper for table TblBrlyQLegMapLocation (MySQL database)
	*/
class MyTblBrlyQLegMapLocation : public TblBrlyQLegMapLocation, public Sbecore::MyTable {

public:
	MyTblBrlyQLegMapLocation();
	~MyTblBrlyQLegMapLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegMapLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegMapLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLegMapLocation* rec);
	void insertRst(ListBrlyQLegMapLocation& rst);
	void updateRec(BrlyQLegMapLocation* rec);
	void updateRst(ListBrlyQLegMapLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegMapLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegMapLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLegMapLocation: C++ wrapper for table TblBrlyQLegMapLocation (PgSQL database)
	*/
class PgTblBrlyQLegMapLocation : public TblBrlyQLegMapLocation, public Sbecore::PgTable {

public:
	PgTblBrlyQLegMapLocation();
	~PgTblBrlyQLegMapLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegMapLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegMapLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegMapLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegMapLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegMapLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegMapLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLegMapLocation* rec);
	void insertRst(ListBrlyQLegMapLocation& rst);
	void updateRec(BrlyQLegMapLocation* rec);
	void updateRst(ListBrlyQLegMapLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegMapLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegMapLocation& rst);
};
#endif

#endif
