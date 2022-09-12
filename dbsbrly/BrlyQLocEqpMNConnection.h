/**
	* \file BrlyQLocEqpMNConnection.h
	* Dbs and XML wrapper for table TblBrlyQLocEqpMNConnection (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCEQPMNCONNECTION_H
#define BRLYQLOCEQPMNCONNECTION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocEqpMNConnection: record of TblBrlyQLocEqpMNConnection
	*/
class BrlyQLocEqpMNConnection {

public:
	BrlyQLocEqpMNConnection(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint conIxBrlyVLat = 0, const std::string srefConIxBrlyVLat = "");

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
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocEqpMNConnection: recordset of TblBrlyQLocEqpMNConnection
	*/
class ListBrlyQLocEqpMNConnection {

public:
	ListBrlyQLocEqpMNConnection();
	ListBrlyQLocEqpMNConnection(const ListBrlyQLocEqpMNConnection& src);
	~ListBrlyQLocEqpMNConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocEqpMNConnection* rec);

	ListBrlyQLocEqpMNConnection& operator=(const ListBrlyQLocEqpMNConnection& src);

public:
	std::vector<BrlyQLocEqpMNConnection*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocEqpMNConnection: C++ wrapper for table TblBrlyQLocEqpMNConnection
	*/
class TblBrlyQLocEqpMNConnection {

public:
	TblBrlyQLocEqpMNConnection();
	virtual ~TblBrlyQLocEqpMNConnection();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocEqpMNConnection** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocEqpMNConnection& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocEqpMNConnection* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocEqpMNConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint conIxBrlyVLat = 0, const std::string srefConIxBrlyVLat = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocEqpMNConnection& rst, BrlyQLocEqpMNConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint conIxBrlyVLat = 0, const std::string srefConIxBrlyVLat = "");
	virtual void insertRst(ListBrlyQLocEqpMNConnection& rst);
	virtual void updateRec(BrlyQLocEqpMNConnection* rec);
	virtual void updateRst(ListBrlyQLocEqpMNConnection& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocEqpMNConnection** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocEqpMNConnection& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocEqpMNConnection: C++ wrapper for table TblBrlyQLocEqpMNConnection (MySQL database)
	*/
class MyTblBrlyQLocEqpMNConnection : public TblBrlyQLocEqpMNConnection, public Sbecore::MyTable {

public:
	MyTblBrlyQLocEqpMNConnection();
	~MyTblBrlyQLocEqpMNConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocEqpMNConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocEqpMNConnection& rst);

	Sbecore::ubigint insertRec(BrlyQLocEqpMNConnection* rec);
	void insertRst(ListBrlyQLocEqpMNConnection& rst);
	void updateRec(BrlyQLocEqpMNConnection* rec);
	void updateRst(ListBrlyQLocEqpMNConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocEqpMNConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocEqpMNConnection& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocEqpMNConnection: C++ wrapper for table TblBrlyQLocEqpMNConnection (PgSQL database)
	*/
class PgTblBrlyQLocEqpMNConnection : public TblBrlyQLocEqpMNConnection, public Sbecore::PgTable {

public:
	PgTblBrlyQLocEqpMNConnection();
	~PgTblBrlyQLocEqpMNConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocEqpMNConnection** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocEqpMNConnection& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocEqpMNConnection** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocEqpMNConnection& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocEqpMNConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocEqpMNConnection& rst);

	Sbecore::ubigint insertRec(BrlyQLocEqpMNConnection* rec);
	void insertRst(ListBrlyQLocEqpMNConnection& rst);
	void updateRec(BrlyQLocEqpMNConnection* rec);
	void updateRst(ListBrlyQLocEqpMNConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocEqpMNConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocEqpMNConnection& rst);
};
#endif

#endif
