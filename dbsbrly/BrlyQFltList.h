/**
	* \file BrlyQFltList.h
	* Dbs and XML wrapper for table TblBrlyQFltList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQFLTLIST_H
#define BRLYQFLTLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQFltList: record of TblBrlyQFltList
	*/
class BrlyQFltList {

public:
	BrlyQFltList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refBrlyMEquipment = 0, const std::string stubRefBrlyMEquipment = "", const Sbecore::ubigint refBrlyMFaflight = 0, const Sbecore::ubigint refBrlyMLeg = 0, const std::string stubRefBrlyMLeg = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refBrlyMEquipment;
	std::string stubRefBrlyMEquipment;
	Sbecore::ubigint refBrlyMFaflight;
	Sbecore::ubigint refBrlyMLeg;
	std::string stubRefBrlyMLeg;
	Sbecore::uint start;
	std::string ftmStart;
	Sbecore::uint stop;
	std::string ftmStop;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQFltList: recordset of TblBrlyQFltList
	*/
class ListBrlyQFltList {

public:
	ListBrlyQFltList();
	ListBrlyQFltList(const ListBrlyQFltList& src);
	~ListBrlyQFltList();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltList* rec);

	ListBrlyQFltList& operator=(const ListBrlyQFltList& src);

public:
	std::vector<BrlyQFltList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQFltList: C++ wrapper for table TblBrlyQFltList
	*/
class TblBrlyQFltList {

public:
	TblBrlyQFltList();
	virtual ~TblBrlyQFltList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQFltList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQFltList* rec);
	Sbecore::ubigint insertNewRec(BrlyQFltList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refBrlyMEquipment = 0, const std::string stubRefBrlyMEquipment = "", const Sbecore::ubigint refBrlyMFaflight = 0, const Sbecore::ubigint refBrlyMLeg = 0, const std::string stubRefBrlyMLeg = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQFltList& rst, BrlyQFltList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refBrlyMEquipment = 0, const std::string stubRefBrlyMEquipment = "", const Sbecore::ubigint refBrlyMFaflight = 0, const Sbecore::ubigint refBrlyMLeg = 0, const std::string stubRefBrlyMLeg = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "");
	virtual void insertRst(ListBrlyQFltList& rst);
	virtual void updateRec(BrlyQFltList* rec);
	virtual void updateRst(ListBrlyQFltList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQFltList: C++ wrapper for table TblBrlyQFltList (MySQL database)
	*/
class MyTblBrlyQFltList : public TblBrlyQFltList, public Sbecore::MyTable {

public:
	MyTblBrlyQFltList();
	~MyTblBrlyQFltList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltList& rst);

	Sbecore::ubigint insertRec(BrlyQFltList* rec);
	void insertRst(ListBrlyQFltList& rst);
	void updateRec(BrlyQFltList* rec);
	void updateRst(ListBrlyQFltList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQFltList: C++ wrapper for table TblBrlyQFltList (PgSQL database)
	*/
class PgTblBrlyQFltList : public TblBrlyQFltList, public Sbecore::PgTable {

public:
	PgTblBrlyQFltList();
	~PgTblBrlyQFltList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltList& rst);

	Sbecore::ubigint insertRec(BrlyQFltList* rec);
	void insertRst(ListBrlyQFltList& rst);
	void updateRec(BrlyQFltList* rec);
	void updateRst(ListBrlyQFltList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltList& rst);
};
#endif

#endif
