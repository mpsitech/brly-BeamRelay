/**
	* \file BrlyQFltMNConnection.h
	* Dbs and XML wrapper for table TblBrlyQFltMNConnection (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQFLTMNCONNECTION_H
#define BRLYQFLTMNCONNECTION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQFltMNConnection: record of TblBrlyQFltMNConnection
	*/
class BrlyQFltMNConnection {

public:
	BrlyQFltMNConnection(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

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
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQFltMNConnection: recordset of TblBrlyQFltMNConnection
	*/
class ListBrlyQFltMNConnection {

public:
	ListBrlyQFltMNConnection();
	ListBrlyQFltMNConnection(const ListBrlyQFltMNConnection& src);
	~ListBrlyQFltMNConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltMNConnection* rec);

	ListBrlyQFltMNConnection& operator=(const ListBrlyQFltMNConnection& src);

public:
	std::vector<BrlyQFltMNConnection*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQFltMNConnection: C++ wrapper for table TblBrlyQFltMNConnection
	*/
class TblBrlyQFltMNConnection {

public:
	TblBrlyQFltMNConnection();
	virtual ~TblBrlyQFltMNConnection();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQFltMNConnection** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltMNConnection& rst);

	virtual Sbecore::ubigint insertRec(BrlyQFltMNConnection* rec);
	Sbecore::ubigint insertNewRec(BrlyQFltMNConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQFltMNConnection& rst, BrlyQFltMNConnection** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	virtual void insertRst(ListBrlyQFltMNConnection& rst);
	virtual void updateRec(BrlyQFltMNConnection* rec);
	virtual void updateRst(ListBrlyQFltMNConnection& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltMNConnection** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltMNConnection& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQFltMNConnection: C++ wrapper for table TblBrlyQFltMNConnection (MySQL database)
	*/
class MyTblBrlyQFltMNConnection : public TblBrlyQFltMNConnection, public Sbecore::MyTable {

public:
	MyTblBrlyQFltMNConnection();
	~MyTblBrlyQFltMNConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltMNConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltMNConnection& rst);

	Sbecore::ubigint insertRec(BrlyQFltMNConnection* rec);
	void insertRst(ListBrlyQFltMNConnection& rst);
	void updateRec(BrlyQFltMNConnection* rec);
	void updateRst(ListBrlyQFltMNConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltMNConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltMNConnection& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQFltMNConnection: C++ wrapper for table TblBrlyQFltMNConnection (PgSQL database)
	*/
class PgTblBrlyQFltMNConnection : public TblBrlyQFltMNConnection, public Sbecore::PgTable {

public:
	PgTblBrlyQFltMNConnection();
	~PgTblBrlyQFltMNConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltMNConnection** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltMNConnection& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltMNConnection** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltMNConnection& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltMNConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltMNConnection& rst);

	Sbecore::ubigint insertRec(BrlyQFltMNConnection* rec);
	void insertRst(ListBrlyQFltMNConnection& rst);
	void updateRec(BrlyQFltMNConnection* rec);
	void updateRst(ListBrlyQFltMNConnection& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltMNConnection** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltMNConnection& rst);
};
#endif

#endif
