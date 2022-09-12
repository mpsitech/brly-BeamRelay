/**
	* \file BrlyQLocProxOrgMNLocation.h
	* Dbs and XML wrapper for table TblBrlyQLocProxOrgMNLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCPROXORGMNLOCATION_H
#define BRLYQLOCPROXORGMNLOCATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocProxOrgMNLocation: record of TblBrlyQLocProxOrgMNLocation
	*/
class BrlyQLocProxOrgMNLocation {

public:
	BrlyQLocProxOrgMNLocation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double deltaphi = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	double deltaphi;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocProxOrgMNLocation: recordset of TblBrlyQLocProxOrgMNLocation
	*/
class ListBrlyQLocProxOrgMNLocation {

public:
	ListBrlyQLocProxOrgMNLocation();
	ListBrlyQLocProxOrgMNLocation(const ListBrlyQLocProxOrgMNLocation& src);
	~ListBrlyQLocProxOrgMNLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocProxOrgMNLocation* rec);

	ListBrlyQLocProxOrgMNLocation& operator=(const ListBrlyQLocProxOrgMNLocation& src);

public:
	std::vector<BrlyQLocProxOrgMNLocation*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocProxOrgMNLocation: C++ wrapper for table TblBrlyQLocProxOrgMNLocation
	*/
class TblBrlyQLocProxOrgMNLocation {

public:
	TblBrlyQLocProxOrgMNLocation();
	virtual ~TblBrlyQLocProxOrgMNLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocProxOrgMNLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocProxOrgMNLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocProxOrgMNLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocProxOrgMNLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double deltaphi = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocProxOrgMNLocation& rst, BrlyQLocProxOrgMNLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double deltaphi = 0.0);
	virtual void insertRst(ListBrlyQLocProxOrgMNLocation& rst);
	virtual void updateRec(BrlyQLocProxOrgMNLocation* rec);
	virtual void updateRst(ListBrlyQLocProxOrgMNLocation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocProxOrgMNLocation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocProxOrgMNLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocProxOrgMNLocation: C++ wrapper for table TblBrlyQLocProxOrgMNLocation (MySQL database)
	*/
class MyTblBrlyQLocProxOrgMNLocation : public TblBrlyQLocProxOrgMNLocation, public Sbecore::MyTable {

public:
	MyTblBrlyQLocProxOrgMNLocation();
	~MyTblBrlyQLocProxOrgMNLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocProxOrgMNLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocProxOrgMNLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLocProxOrgMNLocation* rec);
	void insertRst(ListBrlyQLocProxOrgMNLocation& rst);
	void updateRec(BrlyQLocProxOrgMNLocation* rec);
	void updateRst(ListBrlyQLocProxOrgMNLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocProxOrgMNLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocProxOrgMNLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocProxOrgMNLocation: C++ wrapper for table TblBrlyQLocProxOrgMNLocation (PgSQL database)
	*/
class PgTblBrlyQLocProxOrgMNLocation : public TblBrlyQLocProxOrgMNLocation, public Sbecore::PgTable {

public:
	PgTblBrlyQLocProxOrgMNLocation();
	~PgTblBrlyQLocProxOrgMNLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocProxOrgMNLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocProxOrgMNLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocProxOrgMNLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocProxOrgMNLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocProxOrgMNLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocProxOrgMNLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLocProxOrgMNLocation* rec);
	void insertRst(ListBrlyQLocProxOrgMNLocation& rst);
	void updateRec(BrlyQLocProxOrgMNLocation* rec);
	void updateRst(ListBrlyQLocProxOrgMNLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocProxOrgMNLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocProxOrgMNLocation& rst);
};
#endif

#endif
