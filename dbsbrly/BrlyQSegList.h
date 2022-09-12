/**
	* \file BrlyQSegList.h
	* Dbs and XML wrapper for table TblBrlyQSegList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQSEGLIST_H
#define BRLYQSEGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQSegList: record of TblBrlyQSegList
	*/
class BrlyQSegList {

public:
	BrlyQSegList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	double alt0;
	double alt1;
	double theta0;
	double theta1;
	double phi0;
	double phi1;
	Sbecore::uint start;
	std::string ftmStart;
	Sbecore::uint stop;
	std::string ftmStop;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQSegList: recordset of TblBrlyQSegList
	*/
class ListBrlyQSegList {

public:
	ListBrlyQSegList();
	ListBrlyQSegList(const ListBrlyQSegList& src);
	~ListBrlyQSegList();

	void clear();
	unsigned int size() const;
	void append(BrlyQSegList* rec);

	ListBrlyQSegList& operator=(const ListBrlyQSegList& src);

public:
	std::vector<BrlyQSegList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQSegList: C++ wrapper for table TblBrlyQSegList
	*/
class TblBrlyQSegList {

public:
	TblBrlyQSegList();
	virtual ~TblBrlyQSegList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQSegList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQSegList* rec);
	Sbecore::ubigint insertNewRec(BrlyQSegList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQSegList& rst, BrlyQSegList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "");
	virtual void insertRst(ListBrlyQSegList& rst);
	virtual void updateRec(BrlyQSegList* rec);
	virtual void updateRst(ListBrlyQSegList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQSegList: C++ wrapper for table TblBrlyQSegList (MySQL database)
	*/
class MyTblBrlyQSegList : public TblBrlyQSegList, public Sbecore::MyTable {

public:
	MyTblBrlyQSegList();
	~MyTblBrlyQSegList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQSegList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegList& rst);

	Sbecore::ubigint insertRec(BrlyQSegList* rec);
	void insertRst(ListBrlyQSegList& rst);
	void updateRec(BrlyQSegList* rec);
	void updateRst(ListBrlyQSegList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQSegList: C++ wrapper for table TblBrlyQSegList (PgSQL database)
	*/
class PgTblBrlyQSegList : public TblBrlyQSegList, public Sbecore::PgTable {

public:
	PgTblBrlyQSegList();
	~PgTblBrlyQSegList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQSegList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQSegList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQSegList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQSegList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQSegList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegList& rst);

	Sbecore::ubigint insertRec(BrlyQSegList* rec);
	void insertRst(ListBrlyQSegList& rst);
	void updateRec(BrlyQSegList* rec);
	void updateRst(ListBrlyQSegList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegList& rst);
};
#endif

#endif
