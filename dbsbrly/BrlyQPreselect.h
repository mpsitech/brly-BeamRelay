/**
	* \file BrlyQPreselect.h
	* Dbs and XML wrapper for table TblBrlyQPreselect (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQPRESELECT_H
#define BRLYQPRESELECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQPreselect: record of TblBrlyQPreselect
	*/
class BrlyQPreselect {

public:
	BrlyQPreselect(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQPreselect: recordset of TblBrlyQPreselect
	*/
class ListBrlyQPreselect {

public:
	ListBrlyQPreselect();
	ListBrlyQPreselect(const ListBrlyQPreselect& src);
	~ListBrlyQPreselect();

	void clear();
	unsigned int size() const;
	void append(BrlyQPreselect* rec);

	ListBrlyQPreselect& operator=(const ListBrlyQPreselect& src);

public:
	std::vector<BrlyQPreselect*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQPreselect: C++ wrapper for table TblBrlyQPreselect
	*/
class TblBrlyQPreselect {

public:
	TblBrlyQPreselect();
	virtual ~TblBrlyQPreselect();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQPreselect** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPreselect& rst);

	virtual Sbecore::ubigint insertRec(BrlyQPreselect* rec);
	Sbecore::ubigint insertNewRec(BrlyQPreselect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQPreselect& rst, BrlyQPreselect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListBrlyQPreselect& rst);
	virtual void updateRec(BrlyQPreselect* rec);
	virtual void updateRst(ListBrlyQPreselect& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQPreselect** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPreselect& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQPreselect: C++ wrapper for table TblBrlyQPreselect (MySQL database)
	*/
class MyTblBrlyQPreselect : public TblBrlyQPreselect, public Sbecore::MyTable {

public:
	MyTblBrlyQPreselect();
	~MyTblBrlyQPreselect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPreselect& rst);

	Sbecore::ubigint insertRec(BrlyQPreselect* rec);
	void insertRst(ListBrlyQPreselect& rst);
	void updateRec(BrlyQPreselect* rec);
	void updateRst(ListBrlyQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPreselect& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQPreselect: C++ wrapper for table TblBrlyQPreselect (PgSQL database)
	*/
class PgTblBrlyQPreselect : public TblBrlyQPreselect, public Sbecore::PgTable {

public:
	PgTblBrlyQPreselect();
	~PgTblBrlyQPreselect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQPreselect** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQPreselect& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQPreselect** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQPreselect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPreselect& rst);

	Sbecore::ubigint insertRec(BrlyQPreselect* rec);
	void insertRst(ListBrlyQPreselect& rst);
	void updateRec(BrlyQPreselect* rec);
	void updateRst(ListBrlyQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPreselect& rst);
};
#endif

#endif
