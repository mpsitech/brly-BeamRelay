/**
	* \file BrlyQPtyList.h
	* Dbs and XML wrapper for table TblBrlyQPtyList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQPTYLIST_H
#define BRLYQPTYLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQPtyList: record of TblBrlyQPtyList
	*/
class BrlyQPtyList {

public:
	BrlyQPtyList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string srefBrlyKEqptype = "", const std::string titSrefBrlyKEqptype = "", const Sbecore::usmallint Capacity = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	std::string srefBrlyKEqptype;
	std::string titSrefBrlyKEqptype;
	Sbecore::usmallint Capacity;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQPtyList: recordset of TblBrlyQPtyList
	*/
class ListBrlyQPtyList {

public:
	ListBrlyQPtyList();
	ListBrlyQPtyList(const ListBrlyQPtyList& src);
	~ListBrlyQPtyList();

	void clear();
	unsigned int size() const;
	void append(BrlyQPtyList* rec);

	ListBrlyQPtyList& operator=(const ListBrlyQPtyList& src);

public:
	std::vector<BrlyQPtyList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQPtyList: C++ wrapper for table TblBrlyQPtyList
	*/
class TblBrlyQPtyList {

public:
	TblBrlyQPtyList();
	virtual ~TblBrlyQPtyList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQPtyList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPtyList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQPtyList* rec);
	Sbecore::ubigint insertNewRec(BrlyQPtyList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string srefBrlyKEqptype = "", const std::string titSrefBrlyKEqptype = "", const Sbecore::usmallint Capacity = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQPtyList& rst, BrlyQPtyList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string srefBrlyKEqptype = "", const std::string titSrefBrlyKEqptype = "", const Sbecore::usmallint Capacity = 0);
	virtual void insertRst(ListBrlyQPtyList& rst);
	virtual void updateRec(BrlyQPtyList* rec);
	virtual void updateRst(ListBrlyQPtyList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQPtyList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPtyList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQPtyList: C++ wrapper for table TblBrlyQPtyList (MySQL database)
	*/
class MyTblBrlyQPtyList : public TblBrlyQPtyList, public Sbecore::MyTable {

public:
	MyTblBrlyQPtyList();
	~MyTblBrlyQPtyList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQPtyList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPtyList& rst);

	Sbecore::ubigint insertRec(BrlyQPtyList* rec);
	void insertRst(ListBrlyQPtyList& rst);
	void updateRec(BrlyQPtyList* rec);
	void updateRst(ListBrlyQPtyList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQPtyList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPtyList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQPtyList: C++ wrapper for table TblBrlyQPtyList (PgSQL database)
	*/
class PgTblBrlyQPtyList : public TblBrlyQPtyList, public Sbecore::PgTable {

public:
	PgTblBrlyQPtyList();
	~PgTblBrlyQPtyList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQPtyList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQPtyList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQPtyList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQPtyList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQPtyList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPtyList& rst);

	Sbecore::ubigint insertRec(BrlyQPtyList* rec);
	void insertRst(ListBrlyQPtyList& rst);
	void updateRec(BrlyQPtyList* rec);
	void updateRst(ListBrlyQPtyList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQPtyList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPtyList& rst);
};
#endif

#endif
