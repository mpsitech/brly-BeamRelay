/**
	* \file BrlyQRlyList.h
	* Dbs and XML wrapper for table TblBrlyQRlyList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQRLYLIST_H
#define BRLYQRLYLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQRlyList: record of TblBrlyQRlyList
	*/
class BrlyQRlyList {

public:
	BrlyQRlyList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const Sbecore::ubigint refBrlyMConnection = 0, const std::string stubRefBrlyMConnection = "", const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "", const bool Connected = false, const std::string yesnoConnected = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1Start;
	std::string ftmX1Start;
	Sbecore::uint x1Stop;
	std::string ftmX1Stop;
	Sbecore::ubigint refBrlyMConnection;
	std::string stubRefBrlyMConnection;
	Sbecore::uint ixVDir;
	std::string srefIxVDir;
	std::string titIxVDir;
	bool Connected;
	std::string yesnoConnected;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQRlyList: recordset of TblBrlyQRlyList
	*/
class ListBrlyQRlyList {

public:
	ListBrlyQRlyList();
	ListBrlyQRlyList(const ListBrlyQRlyList& src);
	~ListBrlyQRlyList();

	void clear();
	unsigned int size() const;
	void append(BrlyQRlyList* rec);

	ListBrlyQRlyList& operator=(const ListBrlyQRlyList& src);

public:
	std::vector<BrlyQRlyList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQRlyList: C++ wrapper for table TblBrlyQRlyList
	*/
class TblBrlyQRlyList {

public:
	TblBrlyQRlyList();
	virtual ~TblBrlyQRlyList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQRlyList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRlyList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQRlyList* rec);
	Sbecore::ubigint insertNewRec(BrlyQRlyList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const Sbecore::ubigint refBrlyMConnection = 0, const std::string stubRefBrlyMConnection = "", const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "", const bool Connected = false, const std::string yesnoConnected = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQRlyList& rst, BrlyQRlyList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const Sbecore::ubigint refBrlyMConnection = 0, const std::string stubRefBrlyMConnection = "", const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "", const bool Connected = false, const std::string yesnoConnected = "");
	virtual void insertRst(ListBrlyQRlyList& rst);
	virtual void updateRec(BrlyQRlyList* rec);
	virtual void updateRst(ListBrlyQRlyList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQRlyList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRlyList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQRlyList: C++ wrapper for table TblBrlyQRlyList (MySQL database)
	*/
class MyTblBrlyQRlyList : public TblBrlyQRlyList, public Sbecore::MyTable {

public:
	MyTblBrlyQRlyList();
	~MyTblBrlyQRlyList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQRlyList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRlyList& rst);

	Sbecore::ubigint insertRec(BrlyQRlyList* rec);
	void insertRst(ListBrlyQRlyList& rst);
	void updateRec(BrlyQRlyList* rec);
	void updateRst(ListBrlyQRlyList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQRlyList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRlyList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQRlyList: C++ wrapper for table TblBrlyQRlyList (PgSQL database)
	*/
class PgTblBrlyQRlyList : public TblBrlyQRlyList, public Sbecore::PgTable {

public:
	PgTblBrlyQRlyList();
	~PgTblBrlyQRlyList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQRlyList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQRlyList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQRlyList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQRlyList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQRlyList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRlyList& rst);

	Sbecore::ubigint insertRec(BrlyQRlyList* rec);
	void insertRst(ListBrlyQRlyList& rst);
	void updateRec(BrlyQRlyList* rec);
	void updateRst(ListBrlyQRlyList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQRlyList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRlyList& rst);
};
#endif

#endif
