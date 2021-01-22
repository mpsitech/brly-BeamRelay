/**
	* \file BrlyQUsgList.h
	* Dbs and XML wrapper for table TblBrlyQUsgList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQUSGLIST_H
#define BRLYQUSGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQUsgList: record of TblBrlyQUsgList
	*/
class BrlyQUsgList {

public:
	BrlyQUsgList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string sref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQUsgList: recordset of TblBrlyQUsgList
	*/
class ListBrlyQUsgList {

public:
	ListBrlyQUsgList();
	ListBrlyQUsgList(const ListBrlyQUsgList& src);
	~ListBrlyQUsgList();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsgList* rec);

	ListBrlyQUsgList& operator=(const ListBrlyQUsgList& src);

public:
	std::vector<BrlyQUsgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQUsgList: C++ wrapper for table TblBrlyQUsgList
	*/
class TblBrlyQUsgList {

public:
	TblBrlyQUsgList();
	virtual ~TblBrlyQUsgList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQUsgList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsgList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQUsgList* rec);
	Sbecore::ubigint insertNewRec(BrlyQUsgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQUsgList& rst, BrlyQUsgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");
	virtual void insertRst(ListBrlyQUsgList& rst);
	virtual void updateRec(BrlyQUsgList* rec);
	virtual void updateRst(ListBrlyQUsgList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsgList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsgList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQUsgList: C++ wrapper for table TblBrlyQUsgList (MySQL database)
	*/
class MyTblBrlyQUsgList : public TblBrlyQUsgList, public Sbecore::MyTable {

public:
	MyTblBrlyQUsgList();
	~MyTblBrlyQUsgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsgList& rst);

	Sbecore::ubigint insertRec(BrlyQUsgList* rec);
	void insertRst(ListBrlyQUsgList& rst);
	void updateRec(BrlyQUsgList* rec);
	void updateRst(ListBrlyQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsgList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQUsgList: C++ wrapper for table TblBrlyQUsgList (PgSQL database)
	*/
class PgTblBrlyQUsgList : public TblBrlyQUsgList, public Sbecore::PgTable {

public:
	PgTblBrlyQUsgList();
	~PgTblBrlyQUsgList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsgList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsgList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsgList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsgList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsgList& rst);

	Sbecore::ubigint insertRec(BrlyQUsgList* rec);
	void insertRst(ListBrlyQUsgList& rst);
	void updateRec(BrlyQUsgList* rec);
	void updateRst(ListBrlyQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsgList& rst);
};
#endif

#endif
