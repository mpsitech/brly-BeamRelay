/**
	* \file BrlyQCon1NRelay.h
	* Dbs and XML wrapper for table TblBrlyQCon1NRelay (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCON1NRELAY_H
#define BRLYQCON1NRELAY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQCon1NRelay: record of TblBrlyQCon1NRelay
	*/
class BrlyQCon1NRelay {

public:
	BrlyQCon1NRelay(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQCon1NRelay: recordset of TblBrlyQCon1NRelay
	*/
class ListBrlyQCon1NRelay {

public:
	ListBrlyQCon1NRelay();
	ListBrlyQCon1NRelay(const ListBrlyQCon1NRelay& src);
	~ListBrlyQCon1NRelay();

	void clear();
	unsigned int size() const;
	void append(BrlyQCon1NRelay* rec);

	ListBrlyQCon1NRelay& operator=(const ListBrlyQCon1NRelay& src);

public:
	std::vector<BrlyQCon1NRelay*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQCon1NRelay: C++ wrapper for table TblBrlyQCon1NRelay
	*/
class TblBrlyQCon1NRelay {

public:
	TblBrlyQCon1NRelay();
	virtual ~TblBrlyQCon1NRelay();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQCon1NRelay** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQCon1NRelay& rst);

	virtual Sbecore::ubigint insertRec(BrlyQCon1NRelay* rec);
	Sbecore::ubigint insertNewRec(BrlyQCon1NRelay** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQCon1NRelay& rst, BrlyQCon1NRelay** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQCon1NRelay& rst);
	virtual void updateRec(BrlyQCon1NRelay* rec);
	virtual void updateRst(ListBrlyQCon1NRelay& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQCon1NRelay** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQCon1NRelay& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQCon1NRelay: C++ wrapper for table TblBrlyQCon1NRelay (MySQL database)
	*/
class MyTblBrlyQCon1NRelay : public TblBrlyQCon1NRelay, public Sbecore::MyTable {

public:
	MyTblBrlyQCon1NRelay();
	~MyTblBrlyQCon1NRelay();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQCon1NRelay** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQCon1NRelay& rst);

	Sbecore::ubigint insertRec(BrlyQCon1NRelay* rec);
	void insertRst(ListBrlyQCon1NRelay& rst);
	void updateRec(BrlyQCon1NRelay* rec);
	void updateRst(ListBrlyQCon1NRelay& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQCon1NRelay** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQCon1NRelay& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQCon1NRelay: C++ wrapper for table TblBrlyQCon1NRelay (PgSQL database)
	*/
class PgTblBrlyQCon1NRelay : public TblBrlyQCon1NRelay, public Sbecore::PgTable {

public:
	PgTblBrlyQCon1NRelay();
	~PgTblBrlyQCon1NRelay();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQCon1NRelay** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQCon1NRelay& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQCon1NRelay** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQCon1NRelay& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQCon1NRelay** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQCon1NRelay& rst);

	Sbecore::ubigint insertRec(BrlyQCon1NRelay* rec);
	void insertRst(ListBrlyQCon1NRelay& rst);
	void updateRec(BrlyQCon1NRelay* rec);
	void updateRst(ListBrlyQCon1NRelay& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQCon1NRelay** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQCon1NRelay& rst);
};
#endif

#endif
