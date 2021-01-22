/**
	* \file BrlyQFltEqpMNConnection.h
	* Dbs and XML wrapper for table TblBrlyQFltEqpMNConnection (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQFLTEQPMNCONNECTION_H
#define BRLYQFLTEQPMNCONNECTION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQFltEqpMNConnection: record of TblBrlyQFltEqpMNConnection
	*/
class BrlyQFltEqpMNConnection {

public:
	BrlyQFltEqpMNConnection(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint conIxBrlyVLat = 0, const std::string srefConIxBrlyVLat = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint conIxBrlyVLat;
	std::string srefConIxBrlyVLat;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQFltEqpMNConnection: recordset of TblBrlyQFltEqpMNConnection
	*/
class ListBrlyQFltEqpMNConnection {

public:
	ListBrlyQFltEqpMNConnection();
	ListBrlyQFltEqpMNConnection(const ListBrlyQFltEqpMNConnection& src);
	~ListBrlyQFltEqpMNConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltEqpMNConnection* rec);

	ListBrlyQFltEqpMNConnection& operator=(const ListBrlyQFltEqpMNConnection& src);

public:
	std::vector<BrlyQFltEqpMNConnection*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQFltEqpMNConnection: C++ wrapper for table TblBrlyQFltEqpMNConnection
	*/
class TblBrlyQFltEqpMNConnection {

public:
	TblBrlyQFltEqpMNConnection();
	virtual ~TblBrlyQFltEqpMNConnection();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQFltEqpMNConnection** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltEqpMNConnection& rst);

	virtual Sbecore::ubigint insertRec(BrlyQFltEqpMNConnection* rec);
	Sbecore::ubigint insertNewRec(BrlyQFltEqpMNConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint conIxBrlyVLat = 0, const std::string srefConIxBrlyVLat = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQFltEqpMNConnection& rst, BrlyQFltEqpMNConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint conIxBrlyVLat = 0, const std::string srefConIxBrlyVLat = "");
	virtual void insertRst(ListBrlyQFltEqpMNConnection& rst);
	virtual void updateRec(BrlyQFltEqpMNConnection* rec);
	virtual void updateRst(ListBrlyQFltEqpMNConnection& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltEqpMNConnection** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltEqpMNConnection& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQFltEqpMNConnection: C++ wrapper for table TblBrlyQFltEqpMNConnection (MySQL database)
	*/
class MyTblBrlyQFltEqpMNConnection : public TblBrlyQFltEqpMNConnection, public Sbecore::MyTable {

public:
	MyTblBrlyQFltEqpMNConnection();
	~MyTblBrlyQFltEqpMNConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltEqpMNConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltEqpMNConnection& rst);

	Sbecore::ubigint insertRec(BrlyQFltEqpMNConnection* rec);
	void insertRst(ListBrlyQFltEqpMNConnection& rst);
	void updateRec(BrlyQFltEqpMNConnection* rec);
	void updateRst(ListBrlyQFltEqpMNConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltEqpMNConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltEqpMNConnection& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQFltEqpMNConnection: C++ wrapper for table TblBrlyQFltEqpMNConnection (PgSQL database)
	*/
class PgTblBrlyQFltEqpMNConnection : public TblBrlyQFltEqpMNConnection, public Sbecore::PgTable {

public:
	PgTblBrlyQFltEqpMNConnection();
	~PgTblBrlyQFltEqpMNConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltEqpMNConnection** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltEqpMNConnection& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltEqpMNConnection** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltEqpMNConnection& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltEqpMNConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltEqpMNConnection& rst);

	Sbecore::ubigint insertRec(BrlyQFltEqpMNConnection* rec);
	void insertRst(ListBrlyQFltEqpMNConnection& rst);
	void updateRec(BrlyQFltEqpMNConnection* rec);
	void updateRst(ListBrlyQFltEqpMNConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltEqpMNConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltEqpMNConnection& rst);
};
#endif

#endif
