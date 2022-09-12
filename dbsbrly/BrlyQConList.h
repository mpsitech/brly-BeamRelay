/**
	* \file BrlyQConList.h
	* Dbs and XML wrapper for table TblBrlyQConList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCONLIST_H
#define BRLYQCONLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQConList: record of TblBrlyQConList
	*/
class BrlyQConList {

public:
	BrlyQConList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refBrlyMFlight = 0, const std::string stubRefBrlyMFlight = "", const Sbecore::ubigint corRefBrlyMLeg = 0, const std::string stubCorRefBrlyMLeg = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "", const Sbecore::uint ixVModel = 0, const std::string srefIxVModel = "", const std::string titIxVModel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::ubigint refBrlyMFlight;
	std::string stubRefBrlyMFlight;
	Sbecore::ubigint corRefBrlyMLeg;
	std::string stubCorRefBrlyMLeg;
	Sbecore::uint start;
	std::string ftmStart;
	Sbecore::uint stop;
	std::string ftmStop;
	Sbecore::uint ixVModel;
	std::string srefIxVModel;
	std::string titIxVModel;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQConList: recordset of TblBrlyQConList
	*/
class ListBrlyQConList {

public:
	ListBrlyQConList();
	ListBrlyQConList(const ListBrlyQConList& src);
	~ListBrlyQConList();

	void clear();
	unsigned int size() const;
	void append(BrlyQConList* rec);

	ListBrlyQConList& operator=(const ListBrlyQConList& src);

public:
	std::vector<BrlyQConList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQConList: C++ wrapper for table TblBrlyQConList
	*/
class TblBrlyQConList {

public:
	TblBrlyQConList();
	virtual ~TblBrlyQConList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQConList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQConList* rec);
	Sbecore::ubigint insertNewRec(BrlyQConList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refBrlyMFlight = 0, const std::string stubRefBrlyMFlight = "", const Sbecore::ubigint corRefBrlyMLeg = 0, const std::string stubCorRefBrlyMLeg = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "", const Sbecore::uint ixVModel = 0, const std::string srefIxVModel = "", const std::string titIxVModel = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQConList& rst, BrlyQConList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refBrlyMFlight = 0, const std::string stubRefBrlyMFlight = "", const Sbecore::ubigint corRefBrlyMLeg = 0, const std::string stubCorRefBrlyMLeg = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "", const Sbecore::uint ixVModel = 0, const std::string srefIxVModel = "", const std::string titIxVModel = "");
	virtual void insertRst(ListBrlyQConList& rst);
	virtual void updateRec(BrlyQConList* rec);
	virtual void updateRst(ListBrlyQConList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQConList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQConList: C++ wrapper for table TblBrlyQConList (MySQL database)
	*/
class MyTblBrlyQConList : public TblBrlyQConList, public Sbecore::MyTable {

public:
	MyTblBrlyQConList();
	~MyTblBrlyQConList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConList& rst);

	Sbecore::ubigint insertRec(BrlyQConList* rec);
	void insertRst(ListBrlyQConList& rst);
	void updateRec(BrlyQConList* rec);
	void updateRst(ListBrlyQConList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQConList: C++ wrapper for table TblBrlyQConList (PgSQL database)
	*/
class PgTblBrlyQConList : public TblBrlyQConList, public Sbecore::PgTable {

public:
	PgTblBrlyQConList();
	~PgTblBrlyQConList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQConList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConList& rst);

	Sbecore::ubigint insertRec(BrlyQConList* rec);
	void insertRst(ListBrlyQConList& rst);
	void updateRec(BrlyQConList* rec);
	void updateRst(ListBrlyQConList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConList& rst);
};
#endif

#endif
