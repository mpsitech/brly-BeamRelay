/**
	* \file BrlyQTtb1NFlight.h
	* Dbs and XML wrapper for table TblBrlyQTtb1NFlight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQTTB1NFLIGHT_H
#define BRLYQTTB1NFLIGHT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQTtb1NFlight: record of TblBrlyQTtb1NFlight
	*/
class BrlyQTtb1NFlight {

public:
	BrlyQTtb1NFlight(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListBrlyQTtb1NFlight: recordset of TblBrlyQTtb1NFlight
	*/
class ListBrlyQTtb1NFlight {

public:
	ListBrlyQTtb1NFlight();
	ListBrlyQTtb1NFlight(const ListBrlyQTtb1NFlight& src);
	~ListBrlyQTtb1NFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQTtb1NFlight* rec);

	ListBrlyQTtb1NFlight& operator=(const ListBrlyQTtb1NFlight& src);

public:
	std::vector<BrlyQTtb1NFlight*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQTtb1NFlight: C++ wrapper for table TblBrlyQTtb1NFlight
	*/
class TblBrlyQTtb1NFlight {

public:
	TblBrlyQTtb1NFlight();
	virtual ~TblBrlyQTtb1NFlight();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQTtb1NFlight** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQTtb1NFlight& rst);

	virtual Sbecore::ubigint insertRec(BrlyQTtb1NFlight* rec);
	Sbecore::ubigint insertNewRec(BrlyQTtb1NFlight** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQTtb1NFlight& rst, BrlyQTtb1NFlight** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQTtb1NFlight& rst);
	virtual void updateRec(BrlyQTtb1NFlight* rec);
	virtual void updateRst(ListBrlyQTtb1NFlight& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQTtb1NFlight** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQTtb1NFlight& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQTtb1NFlight: C++ wrapper for table TblBrlyQTtb1NFlight (MySQL database)
	*/
class MyTblBrlyQTtb1NFlight : public TblBrlyQTtb1NFlight, public Sbecore::MyTable {

public:
	MyTblBrlyQTtb1NFlight();
	~MyTblBrlyQTtb1NFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQTtb1NFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQTtb1NFlight& rst);

	Sbecore::ubigint insertRec(BrlyQTtb1NFlight* rec);
	void insertRst(ListBrlyQTtb1NFlight& rst);
	void updateRec(BrlyQTtb1NFlight* rec);
	void updateRst(ListBrlyQTtb1NFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQTtb1NFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQTtb1NFlight& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQTtb1NFlight: C++ wrapper for table TblBrlyQTtb1NFlight (PgSQL database)
	*/
class PgTblBrlyQTtb1NFlight : public TblBrlyQTtb1NFlight, public Sbecore::PgTable {

public:
	PgTblBrlyQTtb1NFlight();
	~PgTblBrlyQTtb1NFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQTtb1NFlight** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQTtb1NFlight& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQTtb1NFlight** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQTtb1NFlight& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQTtb1NFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQTtb1NFlight& rst);

	Sbecore::ubigint insertRec(BrlyQTtb1NFlight* rec);
	void insertRst(ListBrlyQTtb1NFlight& rst);
	void updateRec(BrlyQTtb1NFlight* rec);
	void updateRst(ListBrlyQTtb1NFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQTtb1NFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQTtb1NFlight& rst);
};
#endif

#endif
