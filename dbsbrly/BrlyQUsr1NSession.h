/**
	* \file BrlyQUsr1NSession.h
	* Dbs and XML wrapper for table TblBrlyQUsr1NSession (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQUSR1NSESSION_H
#define BRLYQUSR1NSESSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQUsr1NSession: record of TblBrlyQUsr1NSession
	*/
class BrlyQUsr1NSession {

public:
	BrlyQUsr1NSession(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListBrlyQUsr1NSession: recordset of TblBrlyQUsr1NSession
	*/
class ListBrlyQUsr1NSession {

public:
	ListBrlyQUsr1NSession();
	ListBrlyQUsr1NSession(const ListBrlyQUsr1NSession& src);
	~ListBrlyQUsr1NSession();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsr1NSession* rec);

	ListBrlyQUsr1NSession& operator=(const ListBrlyQUsr1NSession& src);

public:
	std::vector<BrlyQUsr1NSession*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQUsr1NSession: C++ wrapper for table TblBrlyQUsr1NSession
	*/
class TblBrlyQUsr1NSession {

public:
	TblBrlyQUsr1NSession();
	virtual ~TblBrlyQUsr1NSession();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQUsr1NSession** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsr1NSession& rst);

	virtual Sbecore::ubigint insertRec(BrlyQUsr1NSession* rec);
	Sbecore::ubigint insertNewRec(BrlyQUsr1NSession** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQUsr1NSession& rst, BrlyQUsr1NSession** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQUsr1NSession& rst);
	virtual void updateRec(BrlyQUsr1NSession* rec);
	virtual void updateRst(ListBrlyQUsr1NSession& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsr1NSession** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsr1NSession& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQUsr1NSession: C++ wrapper for table TblBrlyQUsr1NSession (MySQL database)
	*/
class MyTblBrlyQUsr1NSession : public TblBrlyQUsr1NSession, public Sbecore::MyTable {

public:
	MyTblBrlyQUsr1NSession();
	~MyTblBrlyQUsr1NSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsr1NSession& rst);

	Sbecore::ubigint insertRec(BrlyQUsr1NSession* rec);
	void insertRst(ListBrlyQUsr1NSession& rst);
	void updateRec(BrlyQUsr1NSession* rec);
	void updateRst(ListBrlyQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsr1NSession& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQUsr1NSession: C++ wrapper for table TblBrlyQUsr1NSession (PgSQL database)
	*/
class PgTblBrlyQUsr1NSession : public TblBrlyQUsr1NSession, public Sbecore::PgTable {

public:
	PgTblBrlyQUsr1NSession();
	~PgTblBrlyQUsr1NSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsr1NSession** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsr1NSession& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsr1NSession** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsr1NSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsr1NSession& rst);

	Sbecore::ubigint insertRec(BrlyQUsr1NSession* rec);
	void insertRst(ListBrlyQUsr1NSession& rst);
	void updateRec(BrlyQUsr1NSession* rec);
	void updateRst(ListBrlyQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsr1NSession& rst);
};
#endif

#endif
