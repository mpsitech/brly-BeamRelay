/**
	* \file BrlyQFilList.h
	* Dbs and XML wrapper for table TblBrlyQFilList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQFILLIST_H
#define BRLYQFILLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQFilList: record of TblBrlyQFilList
	*/
class BrlyQFilList {

public:
	BrlyQFilList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Filename;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	std::string osrefKContent;
	std::string titOsrefKContent;
	std::string srefKMimetype;
	std::string titSrefKMimetype;
	Sbecore::usmallint Size;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQFilList: recordset of TblBrlyQFilList
	*/
class ListBrlyQFilList {

public:
	ListBrlyQFilList();
	ListBrlyQFilList(const ListBrlyQFilList& src);
	~ListBrlyQFilList();

	void clear();
	unsigned int size() const;
	void append(BrlyQFilList* rec);

	ListBrlyQFilList& operator=(const ListBrlyQFilList& src);

public:
	std::vector<BrlyQFilList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQFilList: C++ wrapper for table TblBrlyQFilList
	*/
class TblBrlyQFilList {

public:
	TblBrlyQFilList();
	virtual ~TblBrlyQFilList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQFilList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFilList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQFilList* rec);
	Sbecore::ubigint insertNewRec(BrlyQFilList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQFilList& rst, BrlyQFilList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);
	virtual void insertRst(ListBrlyQFilList& rst);
	virtual void updateRec(BrlyQFilList* rec);
	virtual void updateRst(ListBrlyQFilList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQFilList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFilList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQFilList: C++ wrapper for table TblBrlyQFilList (MySQL database)
	*/
class MyTblBrlyQFilList : public TblBrlyQFilList, public Sbecore::MyTable {

public:
	MyTblBrlyQFilList();
	~MyTblBrlyQFilList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFilList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFilList& rst);

	Sbecore::ubigint insertRec(BrlyQFilList* rec);
	void insertRst(ListBrlyQFilList& rst);
	void updateRec(BrlyQFilList* rec);
	void updateRst(ListBrlyQFilList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFilList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFilList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQFilList: C++ wrapper for table TblBrlyQFilList (PgSQL database)
	*/
class PgTblBrlyQFilList : public TblBrlyQFilList, public Sbecore::PgTable {

public:
	PgTblBrlyQFilList();
	~PgTblBrlyQFilList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFilList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQFilList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFilList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFilList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFilList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFilList& rst);

	Sbecore::ubigint insertRec(BrlyQFilList* rec);
	void insertRst(ListBrlyQFilList& rst);
	void updateRec(BrlyQFilList* rec);
	void updateRst(ListBrlyQFilList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFilList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFilList& rst);
};
#endif

#endif
