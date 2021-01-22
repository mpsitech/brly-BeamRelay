/**
	* \file BrlyQLocMapVisLocation.h
	* Dbs and XML wrapper for table TblBrlyQLocMapVisLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCMAPVISLOCATION_H
#define BRLYQLOCMAPVISLOCATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocMapVisLocation: record of TblBrlyQLocMapVisLocation
	*/
class BrlyQLocMapVisLocation {

public:
	BrlyQLocMapVisLocation(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint mref;
	std::string stubMref;
	double mtheta;
	double mphi;
	double x;
	double y;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocMapVisLocation: recordset of TblBrlyQLocMapVisLocation
	*/
class ListBrlyQLocMapVisLocation {

public:
	ListBrlyQLocMapVisLocation();
	ListBrlyQLocMapVisLocation(const ListBrlyQLocMapVisLocation& src);
	~ListBrlyQLocMapVisLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMapVisLocation* rec);

	ListBrlyQLocMapVisLocation& operator=(const ListBrlyQLocMapVisLocation& src);

public:
	std::vector<BrlyQLocMapVisLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocMapVisLocation: C++ wrapper for table TblBrlyQLocMapVisLocation
	*/
class TblBrlyQLocMapVisLocation {

public:
	TblBrlyQLocMapVisLocation();
	virtual ~TblBrlyQLocMapVisLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMapVisLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMapVisLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocMapVisLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocMapVisLocation** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocMapVisLocation& rst, BrlyQLocMapVisLocation** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);
	virtual void insertRst(ListBrlyQLocMapVisLocation& rst);
	virtual void updateRec(BrlyQLocMapVisLocation* rec);
	virtual void updateRst(ListBrlyQLocMapVisLocation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMapVisLocation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMapVisLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocMapVisLocation: C++ wrapper for table TblBrlyQLocMapVisLocation (MySQL database)
	*/
class MyTblBrlyQLocMapVisLocation : public TblBrlyQLocMapVisLocation, public Sbecore::MyTable {

public:
	MyTblBrlyQLocMapVisLocation();
	~MyTblBrlyQLocMapVisLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMapVisLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMapVisLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLocMapVisLocation* rec);
	void insertRst(ListBrlyQLocMapVisLocation& rst);
	void updateRec(BrlyQLocMapVisLocation* rec);
	void updateRst(ListBrlyQLocMapVisLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMapVisLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMapVisLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocMapVisLocation: C++ wrapper for table TblBrlyQLocMapVisLocation (PgSQL database)
	*/
class PgTblBrlyQLocMapVisLocation : public TblBrlyQLocMapVisLocation, public Sbecore::PgTable {

public:
	PgTblBrlyQLocMapVisLocation();
	~PgTblBrlyQLocMapVisLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMapVisLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMapVisLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMapVisLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMapVisLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMapVisLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMapVisLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLocMapVisLocation* rec);
	void insertRst(ListBrlyQLocMapVisLocation& rst);
	void updateRec(BrlyQLocMapVisLocation* rec);
	void updateRst(ListBrlyQLocMapVisLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMapVisLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMapVisLocation& rst);
};
#endif

#endif
