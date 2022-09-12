/**
	* \file BrlyQFlt1NConnection.h
	* Dbs and XML wrapper for table TblBrlyQFlt1NConnection (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQFLT1NCONNECTION_H
#define BRLYQFLT1NCONNECTION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQFlt1NConnection: record of TblBrlyQFlt1NConnection
	*/
class BrlyQFlt1NConnection {

public:
	BrlyQFlt1NConnection(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQFlt1NConnection: recordset of TblBrlyQFlt1NConnection
	*/
class ListBrlyQFlt1NConnection {

public:
	ListBrlyQFlt1NConnection();
	ListBrlyQFlt1NConnection(const ListBrlyQFlt1NConnection& src);
	~ListBrlyQFlt1NConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQFlt1NConnection* rec);

	ListBrlyQFlt1NConnection& operator=(const ListBrlyQFlt1NConnection& src);

public:
	std::vector<BrlyQFlt1NConnection*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQFlt1NConnection: C++ wrapper for table TblBrlyQFlt1NConnection
	*/
class TblBrlyQFlt1NConnection {

public:
	TblBrlyQFlt1NConnection();
	virtual ~TblBrlyQFlt1NConnection();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQFlt1NConnection** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFlt1NConnection& rst);

	virtual Sbecore::ubigint insertRec(BrlyQFlt1NConnection* rec);
	Sbecore::ubigint insertNewRec(BrlyQFlt1NConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQFlt1NConnection& rst, BrlyQFlt1NConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQFlt1NConnection& rst);
	virtual void updateRec(BrlyQFlt1NConnection* rec);
	virtual void updateRst(ListBrlyQFlt1NConnection& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQFlt1NConnection** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFlt1NConnection& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQFlt1NConnection: C++ wrapper for table TblBrlyQFlt1NConnection (MySQL database)
	*/
class MyTblBrlyQFlt1NConnection : public TblBrlyQFlt1NConnection, public Sbecore::MyTable {

public:
	MyTblBrlyQFlt1NConnection();
	~MyTblBrlyQFlt1NConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFlt1NConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFlt1NConnection& rst);

	Sbecore::ubigint insertRec(BrlyQFlt1NConnection* rec);
	void insertRst(ListBrlyQFlt1NConnection& rst);
	void updateRec(BrlyQFlt1NConnection* rec);
	void updateRst(ListBrlyQFlt1NConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFlt1NConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFlt1NConnection& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQFlt1NConnection: C++ wrapper for table TblBrlyQFlt1NConnection (PgSQL database)
	*/
class PgTblBrlyQFlt1NConnection : public TblBrlyQFlt1NConnection, public Sbecore::PgTable {

public:
	PgTblBrlyQFlt1NConnection();
	~PgTblBrlyQFlt1NConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFlt1NConnection** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQFlt1NConnection& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFlt1NConnection** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFlt1NConnection& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFlt1NConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFlt1NConnection& rst);

	Sbecore::ubigint insertRec(BrlyQFlt1NConnection* rec);
	void insertRst(ListBrlyQFlt1NConnection& rst);
	void updateRec(BrlyQFlt1NConnection* rec);
	void updateRst(ListBrlyQFlt1NConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFlt1NConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFlt1NConnection& rst);
};
#endif

#endif
