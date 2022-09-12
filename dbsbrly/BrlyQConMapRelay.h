/**
	* \file BrlyQConMapRelay.h
	* Dbs and XML wrapper for table TblBrlyQConMapRelay (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCONMAPRELAY_H
#define BRLYQCONMAPRELAY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQConMapRelay: record of TblBrlyQConMapRelay
	*/
class BrlyQConMapRelay {

public:
	BrlyQConMapRelay(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const bool Connected = false, const std::string yesnoConnected = "", const Sbecore::usmallint Nhop = 0);

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1Start;
	Sbecore::uint x1Stop;
	Sbecore::uint ixVDir;
	std::string srefIxVDir;
	bool Connected;
	std::string yesnoConnected;
	Sbecore::usmallint Nhop;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQConMapRelay: recordset of TblBrlyQConMapRelay
	*/
class ListBrlyQConMapRelay {

public:
	ListBrlyQConMapRelay();
	ListBrlyQConMapRelay(const ListBrlyQConMapRelay& src);
	~ListBrlyQConMapRelay();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMapRelay* rec);

	ListBrlyQConMapRelay& operator=(const ListBrlyQConMapRelay& src);

public:
	std::vector<BrlyQConMapRelay*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQConMapRelay: C++ wrapper for table TblBrlyQConMapRelay
	*/
class TblBrlyQConMapRelay {

public:
	TblBrlyQConMapRelay();
	virtual ~TblBrlyQConMapRelay();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapRelay** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapRelay& rst);

	virtual Sbecore::ubigint insertRec(BrlyQConMapRelay* rec);
	Sbecore::ubigint insertNewRec(BrlyQConMapRelay** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const bool Connected = false, const std::string yesnoConnected = "", const Sbecore::usmallint Nhop = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQConMapRelay& rst, BrlyQConMapRelay** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const bool Connected = false, const std::string yesnoConnected = "", const Sbecore::usmallint Nhop = 0);
	virtual void insertRst(ListBrlyQConMapRelay& rst);
	virtual void updateRec(BrlyQConMapRelay* rec);
	virtual void updateRst(ListBrlyQConMapRelay& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapRelay** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapRelay& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQConMapRelay: C++ wrapper for table TblBrlyQConMapRelay (MySQL database)
	*/
class MyTblBrlyQConMapRelay : public TblBrlyQConMapRelay, public Sbecore::MyTable {

public:
	MyTblBrlyQConMapRelay();
	~MyTblBrlyQConMapRelay();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapRelay** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapRelay& rst);

	Sbecore::ubigint insertRec(BrlyQConMapRelay* rec);
	void insertRst(ListBrlyQConMapRelay& rst);
	void updateRec(BrlyQConMapRelay* rec);
	void updateRst(ListBrlyQConMapRelay& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapRelay** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapRelay& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQConMapRelay: C++ wrapper for table TblBrlyQConMapRelay (PgSQL database)
	*/
class PgTblBrlyQConMapRelay : public TblBrlyQConMapRelay, public Sbecore::PgTable {

public:
	PgTblBrlyQConMapRelay();
	~PgTblBrlyQConMapRelay();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMapRelay** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMapRelay& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMapRelay** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMapRelay& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapRelay** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapRelay& rst);

	Sbecore::ubigint insertRec(BrlyQConMapRelay* rec);
	void insertRst(ListBrlyQConMapRelay& rst);
	void updateRec(BrlyQConMapRelay* rec);
	void updateRst(ListBrlyQConMapRelay& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapRelay** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapRelay& rst);
};
#endif

#endif
