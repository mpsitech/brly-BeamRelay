/**
	* \file BrlyQSegMNConnection.h
	* Dbs and XML wrapper for table TblBrlyQSegMNConnection (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQSEGMNCONNECTION_H
#define BRLYQSEGMNCONNECTION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQSegMNConnection: record of TblBrlyQSegMNConnection
	*/
class BrlyQSegMNConnection {

public:
	BrlyQSegMNConnection(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint x1Start;
	std::string ftmX1Start;
	Sbecore::uint x1Stop;
	std::string ftmX1Stop;
	double x2Legphi0;
	double x2Legphi1;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQSegMNConnection: recordset of TblBrlyQSegMNConnection
	*/
class ListBrlyQSegMNConnection {

public:
	ListBrlyQSegMNConnection();
	ListBrlyQSegMNConnection(const ListBrlyQSegMNConnection& src);
	~ListBrlyQSegMNConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQSegMNConnection* rec);

	ListBrlyQSegMNConnection& operator=(const ListBrlyQSegMNConnection& src);

public:
	std::vector<BrlyQSegMNConnection*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQSegMNConnection: C++ wrapper for table TblBrlyQSegMNConnection
	*/
class TblBrlyQSegMNConnection {

public:
	TblBrlyQSegMNConnection();
	virtual ~TblBrlyQSegMNConnection();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQSegMNConnection** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegMNConnection& rst);

	virtual Sbecore::ubigint insertRec(BrlyQSegMNConnection* rec);
	Sbecore::ubigint insertNewRec(BrlyQSegMNConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQSegMNConnection& rst, BrlyQSegMNConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	virtual void insertRst(ListBrlyQSegMNConnection& rst);
	virtual void updateRec(BrlyQSegMNConnection* rec);
	virtual void updateRst(ListBrlyQSegMNConnection& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegMNConnection** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegMNConnection& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQSegMNConnection: C++ wrapper for table TblBrlyQSegMNConnection (MySQL database)
	*/
class MyTblBrlyQSegMNConnection : public TblBrlyQSegMNConnection, public Sbecore::MyTable {

public:
	MyTblBrlyQSegMNConnection();
	~MyTblBrlyQSegMNConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQSegMNConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegMNConnection& rst);

	Sbecore::ubigint insertRec(BrlyQSegMNConnection* rec);
	void insertRst(ListBrlyQSegMNConnection& rst);
	void updateRec(BrlyQSegMNConnection* rec);
	void updateRst(ListBrlyQSegMNConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegMNConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegMNConnection& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQSegMNConnection: C++ wrapper for table TblBrlyQSegMNConnection (PgSQL database)
	*/
class PgTblBrlyQSegMNConnection : public TblBrlyQSegMNConnection, public Sbecore::PgTable {

public:
	PgTblBrlyQSegMNConnection();
	~PgTblBrlyQSegMNConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQSegMNConnection** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQSegMNConnection& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQSegMNConnection** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQSegMNConnection& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQSegMNConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegMNConnection& rst);

	Sbecore::ubigint insertRec(BrlyQSegMNConnection* rec);
	void insertRst(ListBrlyQSegMNConnection& rst);
	void updateRec(BrlyQSegMNConnection* rec);
	void updateRst(ListBrlyQSegMNConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegMNConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegMNConnection& rst);
};
#endif

#endif
