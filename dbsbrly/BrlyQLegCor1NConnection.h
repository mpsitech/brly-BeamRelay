/**
	* \file BrlyQLegCor1NConnection.h
	* Dbs and XML wrapper for table TblBrlyQLegCor1NConnection (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLEGCOR1NCONNECTION_H
#define BRLYQLEGCOR1NCONNECTION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLegCor1NConnection: record of TblBrlyQLegCor1NConnection
	*/
class BrlyQLegCor1NConnection {

public:
	BrlyQLegCor1NConnection(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListBrlyQLegCor1NConnection: recordset of TblBrlyQLegCor1NConnection
	*/
class ListBrlyQLegCor1NConnection {

public:
	ListBrlyQLegCor1NConnection();
	ListBrlyQLegCor1NConnection(const ListBrlyQLegCor1NConnection& src);
	~ListBrlyQLegCor1NConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegCor1NConnection* rec);

	ListBrlyQLegCor1NConnection& operator=(const ListBrlyQLegCor1NConnection& src);

public:
	std::vector<BrlyQLegCor1NConnection*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLegCor1NConnection: C++ wrapper for table TblBrlyQLegCor1NConnection
	*/
class TblBrlyQLegCor1NConnection {

public:
	TblBrlyQLegCor1NConnection();
	virtual ~TblBrlyQLegCor1NConnection();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLegCor1NConnection** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegCor1NConnection& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLegCor1NConnection* rec);
	Sbecore::ubigint insertNewRec(BrlyQLegCor1NConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLegCor1NConnection& rst, BrlyQLegCor1NConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQLegCor1NConnection& rst);
	virtual void updateRec(BrlyQLegCor1NConnection* rec);
	virtual void updateRst(ListBrlyQLegCor1NConnection& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegCor1NConnection** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegCor1NConnection& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLegCor1NConnection: C++ wrapper for table TblBrlyQLegCor1NConnection (MySQL database)
	*/
class MyTblBrlyQLegCor1NConnection : public TblBrlyQLegCor1NConnection, public Sbecore::MyTable {

public:
	MyTblBrlyQLegCor1NConnection();
	~MyTblBrlyQLegCor1NConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegCor1NConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegCor1NConnection& rst);

	Sbecore::ubigint insertRec(BrlyQLegCor1NConnection* rec);
	void insertRst(ListBrlyQLegCor1NConnection& rst);
	void updateRec(BrlyQLegCor1NConnection* rec);
	void updateRst(ListBrlyQLegCor1NConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegCor1NConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegCor1NConnection& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLegCor1NConnection: C++ wrapper for table TblBrlyQLegCor1NConnection (PgSQL database)
	*/
class PgTblBrlyQLegCor1NConnection : public TblBrlyQLegCor1NConnection, public Sbecore::PgTable {

public:
	PgTblBrlyQLegCor1NConnection();
	~PgTblBrlyQLegCor1NConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegCor1NConnection** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegCor1NConnection& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegCor1NConnection** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegCor1NConnection& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegCor1NConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegCor1NConnection& rst);

	Sbecore::ubigint insertRec(BrlyQLegCor1NConnection* rec);
	void insertRst(ListBrlyQLegCor1NConnection& rst);
	void updateRec(BrlyQLegCor1NConnection* rec);
	void updateRst(ListBrlyQLegCor1NConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegCor1NConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegCor1NConnection& rst);
};
#endif

#endif
