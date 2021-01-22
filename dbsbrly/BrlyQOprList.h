/**
	* \file BrlyQOprList.h
	* Dbs and XML wrapper for table TblBrlyQOprList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQOPRLIST_H
#define BRLYQOPRLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQOprList: record of TblBrlyQOprList
	*/
class BrlyQOprList {

public:
	BrlyQOprList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string srefICAO;
	std::string Title;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQOprList: recordset of TblBrlyQOprList
	*/
class ListBrlyQOprList {

public:
	ListBrlyQOprList();
	ListBrlyQOprList(const ListBrlyQOprList& src);
	~ListBrlyQOprList();

	void clear();
	unsigned int size() const;
	void append(BrlyQOprList* rec);

	ListBrlyQOprList& operator=(const ListBrlyQOprList& src);

public:
	std::vector<BrlyQOprList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQOprList: C++ wrapper for table TblBrlyQOprList
	*/
class TblBrlyQOprList {

public:
	TblBrlyQOprList();
	virtual ~TblBrlyQOprList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQOprList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQOprList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQOprList* rec);
	Sbecore::ubigint insertNewRec(BrlyQOprList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQOprList& rst, BrlyQOprList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "");
	virtual void insertRst(ListBrlyQOprList& rst);
	virtual void updateRec(BrlyQOprList* rec);
	virtual void updateRst(ListBrlyQOprList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQOprList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQOprList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQOprList: C++ wrapper for table TblBrlyQOprList (MySQL database)
	*/
class MyTblBrlyQOprList : public TblBrlyQOprList, public Sbecore::MyTable {

public:
	MyTblBrlyQOprList();
	~MyTblBrlyQOprList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQOprList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQOprList& rst);

	Sbecore::ubigint insertRec(BrlyQOprList* rec);
	void insertRst(ListBrlyQOprList& rst);
	void updateRec(BrlyQOprList* rec);
	void updateRst(ListBrlyQOprList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQOprList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQOprList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQOprList: C++ wrapper for table TblBrlyQOprList (PgSQL database)
	*/
class PgTblBrlyQOprList : public TblBrlyQOprList, public Sbecore::PgTable {

public:
	PgTblBrlyQOprList();
	~PgTblBrlyQOprList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQOprList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQOprList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQOprList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQOprList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQOprList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQOprList& rst);

	Sbecore::ubigint insertRec(BrlyQOprList* rec);
	void insertRst(ListBrlyQOprList& rst);
	void updateRec(BrlyQOprList* rec);
	void updateRst(ListBrlyQOprList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQOprList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQOprList& rst);
};
#endif

#endif
