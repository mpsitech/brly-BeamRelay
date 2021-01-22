/**
	* \file BrlyQSelect.h
	* Dbs and XML wrapper for table TblBrlyQSelect (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQSELECT_H
#define BRLYQSELECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQSelect: record of TblBrlyQSelect
	*/
class BrlyQSelect {

public:
	BrlyQSelect(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::uint ix;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQSelect: recordset of TblBrlyQSelect
	*/
class ListBrlyQSelect {

public:
	ListBrlyQSelect();
	ListBrlyQSelect(const ListBrlyQSelect& src);
	~ListBrlyQSelect();

	void clear();
	unsigned int size() const;
	void append(BrlyQSelect* rec);

	ListBrlyQSelect& operator=(const ListBrlyQSelect& src);

public:
	std::vector<BrlyQSelect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQSelect: C++ wrapper for table TblBrlyQSelect
	*/
class TblBrlyQSelect {

public:
	TblBrlyQSelect();
	virtual ~TblBrlyQSelect();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQSelect** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSelect& rst);

	virtual Sbecore::ubigint insertRec(BrlyQSelect* rec);
	Sbecore::ubigint insertNewRec(BrlyQSelect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQSelect& rst, BrlyQSelect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListBrlyQSelect& rst);
	virtual void updateRec(BrlyQSelect* rec);
	virtual void updateRst(ListBrlyQSelect& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQSelect** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSelect& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQSelect: C++ wrapper for table TblBrlyQSelect (MySQL database)
	*/
class MyTblBrlyQSelect : public TblBrlyQSelect, public Sbecore::MyTable {

public:
	MyTblBrlyQSelect();
	~MyTblBrlyQSelect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSelect& rst);

	Sbecore::ubigint insertRec(BrlyQSelect* rec);
	void insertRst(ListBrlyQSelect& rst);
	void updateRec(BrlyQSelect* rec);
	void updateRst(ListBrlyQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSelect& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQSelect: C++ wrapper for table TblBrlyQSelect (PgSQL database)
	*/
class PgTblBrlyQSelect : public TblBrlyQSelect, public Sbecore::PgTable {

public:
	PgTblBrlyQSelect();
	~PgTblBrlyQSelect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQSelect** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQSelect& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQSelect** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQSelect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSelect& rst);

	Sbecore::ubigint insertRec(BrlyQSelect* rec);
	void insertRst(ListBrlyQSelect& rst);
	void updateRec(BrlyQSelect* rec);
	void updateRst(ListBrlyQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSelect& rst);
};
#endif

#endif
