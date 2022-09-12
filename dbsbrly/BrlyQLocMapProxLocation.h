/**
	* \file BrlyQLocMapProxLocation.h
	* Dbs and XML wrapper for table TblBrlyQLocMapProxLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCMAPPROXLOCATION_H
#define BRLYQLOCMAPPROXLOCATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocMapProxLocation: record of TblBrlyQLocMapProxLocation
	*/
class BrlyQLocMapProxLocation {

public:
	BrlyQLocMapProxLocation(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);

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
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocMapProxLocation: recordset of TblBrlyQLocMapProxLocation
	*/
class ListBrlyQLocMapProxLocation {

public:
	ListBrlyQLocMapProxLocation();
	ListBrlyQLocMapProxLocation(const ListBrlyQLocMapProxLocation& src);
	~ListBrlyQLocMapProxLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMapProxLocation* rec);

	ListBrlyQLocMapProxLocation& operator=(const ListBrlyQLocMapProxLocation& src);

public:
	std::vector<BrlyQLocMapProxLocation*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocMapProxLocation: C++ wrapper for table TblBrlyQLocMapProxLocation
	*/
class TblBrlyQLocMapProxLocation {

public:
	TblBrlyQLocMapProxLocation();
	virtual ~TblBrlyQLocMapProxLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMapProxLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMapProxLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocMapProxLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocMapProxLocation** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocMapProxLocation& rst, BrlyQLocMapProxLocation** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);
	virtual void insertRst(ListBrlyQLocMapProxLocation& rst);
	virtual void updateRec(BrlyQLocMapProxLocation* rec);
	virtual void updateRst(ListBrlyQLocMapProxLocation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMapProxLocation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMapProxLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocMapProxLocation: C++ wrapper for table TblBrlyQLocMapProxLocation (MySQL database)
	*/
class MyTblBrlyQLocMapProxLocation : public TblBrlyQLocMapProxLocation, public Sbecore::MyTable {

public:
	MyTblBrlyQLocMapProxLocation();
	~MyTblBrlyQLocMapProxLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMapProxLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMapProxLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLocMapProxLocation* rec);
	void insertRst(ListBrlyQLocMapProxLocation& rst);
	void updateRec(BrlyQLocMapProxLocation* rec);
	void updateRst(ListBrlyQLocMapProxLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMapProxLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMapProxLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocMapProxLocation: C++ wrapper for table TblBrlyQLocMapProxLocation (PgSQL database)
	*/
class PgTblBrlyQLocMapProxLocation : public TblBrlyQLocMapProxLocation, public Sbecore::PgTable {

public:
	PgTblBrlyQLocMapProxLocation();
	~PgTblBrlyQLocMapProxLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMapProxLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMapProxLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMapProxLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMapProxLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMapProxLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMapProxLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLocMapProxLocation* rec);
	void insertRst(ListBrlyQLocMapProxLocation& rst);
	void updateRec(BrlyQLocMapProxLocation* rec);
	void updateRst(ListBrlyQLocMapProxLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMapProxLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMapProxLocation& rst);
};
#endif

#endif
