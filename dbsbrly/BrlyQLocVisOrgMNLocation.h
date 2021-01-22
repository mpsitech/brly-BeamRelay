/**
	* \file BrlyQLocVisOrgMNLocation.h
	* Dbs and XML wrapper for table TblBrlyQLocVisOrgMNLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCVISORGMNLOCATION_H
#define BRLYQLOCVISORGMNLOCATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocVisOrgMNLocation: record of TblBrlyQLocVisOrgMNLocation
	*/
class BrlyQLocVisOrgMNLocation {

public:
	BrlyQLocVisOrgMNLocation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocVisOrgMNLocation: recordset of TblBrlyQLocVisOrgMNLocation
	*/
class ListBrlyQLocVisOrgMNLocation {

public:
	ListBrlyQLocVisOrgMNLocation();
	ListBrlyQLocVisOrgMNLocation(const ListBrlyQLocVisOrgMNLocation& src);
	~ListBrlyQLocVisOrgMNLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocVisOrgMNLocation* rec);

	ListBrlyQLocVisOrgMNLocation& operator=(const ListBrlyQLocVisOrgMNLocation& src);

public:
	std::vector<BrlyQLocVisOrgMNLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocVisOrgMNLocation: C++ wrapper for table TblBrlyQLocVisOrgMNLocation
	*/
class TblBrlyQLocVisOrgMNLocation {

public:
	TblBrlyQLocVisOrgMNLocation();
	virtual ~TblBrlyQLocVisOrgMNLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocVisOrgMNLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocVisOrgMNLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocVisOrgMNLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocVisOrgMNLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocVisOrgMNLocation& rst, BrlyQLocVisOrgMNLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListBrlyQLocVisOrgMNLocation& rst);
	virtual void updateRec(BrlyQLocVisOrgMNLocation* rec);
	virtual void updateRst(ListBrlyQLocVisOrgMNLocation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocVisOrgMNLocation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocVisOrgMNLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocVisOrgMNLocation: C++ wrapper for table TblBrlyQLocVisOrgMNLocation (MySQL database)
	*/
class MyTblBrlyQLocVisOrgMNLocation : public TblBrlyQLocVisOrgMNLocation, public Sbecore::MyTable {

public:
	MyTblBrlyQLocVisOrgMNLocation();
	~MyTblBrlyQLocVisOrgMNLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocVisOrgMNLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocVisOrgMNLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLocVisOrgMNLocation* rec);
	void insertRst(ListBrlyQLocVisOrgMNLocation& rst);
	void updateRec(BrlyQLocVisOrgMNLocation* rec);
	void updateRst(ListBrlyQLocVisOrgMNLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocVisOrgMNLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocVisOrgMNLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocVisOrgMNLocation: C++ wrapper for table TblBrlyQLocVisOrgMNLocation (PgSQL database)
	*/
class PgTblBrlyQLocVisOrgMNLocation : public TblBrlyQLocVisOrgMNLocation, public Sbecore::PgTable {

public:
	PgTblBrlyQLocVisOrgMNLocation();
	~PgTblBrlyQLocVisOrgMNLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocVisOrgMNLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocVisOrgMNLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocVisOrgMNLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocVisOrgMNLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocVisOrgMNLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocVisOrgMNLocation& rst);

	Sbecore::ubigint insertRec(BrlyQLocVisOrgMNLocation* rec);
	void insertRst(ListBrlyQLocVisOrgMNLocation& rst);
	void updateRec(BrlyQLocVisOrgMNLocation* rec);
	void updateRst(ListBrlyQLocVisOrgMNLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocVisOrgMNLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocVisOrgMNLocation& rst);
};
#endif

#endif
