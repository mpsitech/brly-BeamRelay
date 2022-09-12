/**
	* \file BrlyQLeg1NFlight.h
	* Dbs and XML wrapper for table TblBrlyQLeg1NFlight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLEG1NFLIGHT_H
#define BRLYQLEG1NFLIGHT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLeg1NFlight: record of TblBrlyQLeg1NFlight
	*/
class BrlyQLeg1NFlight {

public:
	BrlyQLeg1NFlight(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListBrlyQLeg1NFlight: recordset of TblBrlyQLeg1NFlight
	*/
class ListBrlyQLeg1NFlight {

public:
	ListBrlyQLeg1NFlight();
	ListBrlyQLeg1NFlight(const ListBrlyQLeg1NFlight& src);
	~ListBrlyQLeg1NFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQLeg1NFlight* rec);

	ListBrlyQLeg1NFlight& operator=(const ListBrlyQLeg1NFlight& src);

public:
	std::vector<BrlyQLeg1NFlight*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLeg1NFlight: C++ wrapper for table TblBrlyQLeg1NFlight
	*/
class TblBrlyQLeg1NFlight {

public:
	TblBrlyQLeg1NFlight();
	virtual ~TblBrlyQLeg1NFlight();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLeg1NFlight** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLeg1NFlight& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLeg1NFlight* rec);
	Sbecore::ubigint insertNewRec(BrlyQLeg1NFlight** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLeg1NFlight& rst, BrlyQLeg1NFlight** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQLeg1NFlight& rst);
	virtual void updateRec(BrlyQLeg1NFlight* rec);
	virtual void updateRst(ListBrlyQLeg1NFlight& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLeg1NFlight** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLeg1NFlight& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLeg1NFlight: C++ wrapper for table TblBrlyQLeg1NFlight (MySQL database)
	*/
class MyTblBrlyQLeg1NFlight : public TblBrlyQLeg1NFlight, public Sbecore::MyTable {

public:
	MyTblBrlyQLeg1NFlight();
	~MyTblBrlyQLeg1NFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLeg1NFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLeg1NFlight& rst);

	Sbecore::ubigint insertRec(BrlyQLeg1NFlight* rec);
	void insertRst(ListBrlyQLeg1NFlight& rst);
	void updateRec(BrlyQLeg1NFlight* rec);
	void updateRst(ListBrlyQLeg1NFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLeg1NFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLeg1NFlight& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLeg1NFlight: C++ wrapper for table TblBrlyQLeg1NFlight (PgSQL database)
	*/
class PgTblBrlyQLeg1NFlight : public TblBrlyQLeg1NFlight, public Sbecore::PgTable {

public:
	PgTblBrlyQLeg1NFlight();
	~PgTblBrlyQLeg1NFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLeg1NFlight** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLeg1NFlight& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLeg1NFlight** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLeg1NFlight& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLeg1NFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLeg1NFlight& rst);

	Sbecore::ubigint insertRec(BrlyQLeg1NFlight* rec);
	void insertRst(ListBrlyQLeg1NFlight& rst);
	void updateRec(BrlyQLeg1NFlight* rec);
	void updateRst(ListBrlyQLeg1NFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLeg1NFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLeg1NFlight& rst);
};
#endif

#endif
