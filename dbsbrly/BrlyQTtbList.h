/**
	* \file BrlyQTtbList.h
	* Dbs and XML wrapper for table TblBrlyQTtbList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQTTBLIST_H
#define BRLYQTTBLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQTtbList: record of TblBrlyQTtbList
	*/
class BrlyQTtbList {

public:
	BrlyQTtbList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Title = "", const Sbecore::ubigint refBrlyMFile = 0, const std::string stubRefBrlyMFile = "", const std::string srefBrlyKAlliance = "", const std::string titSrefBrlyKAlliance = "", const Sbecore::uint startd = 0, const std::string ftmStartd = "", const Sbecore::uint stopd = 0, const std::string ftmStopd = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string Title;
	Sbecore::ubigint refBrlyMFile;
	std::string stubRefBrlyMFile;
	std::string srefBrlyKAlliance;
	std::string titSrefBrlyKAlliance;
	Sbecore::uint startd;
	std::string ftmStartd;
	Sbecore::uint stopd;
	std::string ftmStopd;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQTtbList: recordset of TblBrlyQTtbList
	*/
class ListBrlyQTtbList {

public:
	ListBrlyQTtbList();
	ListBrlyQTtbList(const ListBrlyQTtbList& src);
	~ListBrlyQTtbList();

	void clear();
	unsigned int size() const;
	void append(BrlyQTtbList* rec);

	ListBrlyQTtbList& operator=(const ListBrlyQTtbList& src);

public:
	std::vector<BrlyQTtbList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQTtbList: C++ wrapper for table TblBrlyQTtbList
	*/
class TblBrlyQTtbList {

public:
	TblBrlyQTtbList();
	virtual ~TblBrlyQTtbList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQTtbList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQTtbList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQTtbList* rec);
	Sbecore::ubigint insertNewRec(BrlyQTtbList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Title = "", const Sbecore::ubigint refBrlyMFile = 0, const std::string stubRefBrlyMFile = "", const std::string srefBrlyKAlliance = "", const std::string titSrefBrlyKAlliance = "", const Sbecore::uint startd = 0, const std::string ftmStartd = "", const Sbecore::uint stopd = 0, const std::string ftmStopd = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQTtbList& rst, BrlyQTtbList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Title = "", const Sbecore::ubigint refBrlyMFile = 0, const std::string stubRefBrlyMFile = "", const std::string srefBrlyKAlliance = "", const std::string titSrefBrlyKAlliance = "", const Sbecore::uint startd = 0, const std::string ftmStartd = "", const Sbecore::uint stopd = 0, const std::string ftmStopd = "");
	virtual void insertRst(ListBrlyQTtbList& rst);
	virtual void updateRec(BrlyQTtbList* rec);
	virtual void updateRst(ListBrlyQTtbList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQTtbList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQTtbList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQTtbList: C++ wrapper for table TblBrlyQTtbList (MySQL database)
	*/
class MyTblBrlyQTtbList : public TblBrlyQTtbList, public Sbecore::MyTable {

public:
	MyTblBrlyQTtbList();
	~MyTblBrlyQTtbList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQTtbList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQTtbList& rst);

	Sbecore::ubigint insertRec(BrlyQTtbList* rec);
	void insertRst(ListBrlyQTtbList& rst);
	void updateRec(BrlyQTtbList* rec);
	void updateRst(ListBrlyQTtbList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQTtbList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQTtbList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQTtbList: C++ wrapper for table TblBrlyQTtbList (PgSQL database)
	*/
class PgTblBrlyQTtbList : public TblBrlyQTtbList, public Sbecore::PgTable {

public:
	PgTblBrlyQTtbList();
	~PgTblBrlyQTtbList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQTtbList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQTtbList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQTtbList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQTtbList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQTtbList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQTtbList& rst);

	Sbecore::ubigint insertRec(BrlyQTtbList* rec);
	void insertRst(ListBrlyQTtbList& rst);
	void updateRec(BrlyQTtbList* rec);
	void updateRst(ListBrlyQTtbList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQTtbList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQTtbList& rst);
};
#endif

#endif
