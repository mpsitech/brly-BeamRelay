/**
	* \file BrlyQLocEnd1NLeg.h
	* Dbs and XML wrapper for table TblBrlyQLocEnd1NLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCEND1NLEG_H
#define BRLYQLOCEND1NLEG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocEnd1NLeg: record of TblBrlyQLocEnd1NLeg
	*/
class BrlyQLocEnd1NLeg {

public:
	BrlyQLocEnd1NLeg(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocEnd1NLeg: recordset of TblBrlyQLocEnd1NLeg
	*/
class ListBrlyQLocEnd1NLeg {

public:
	ListBrlyQLocEnd1NLeg();
	ListBrlyQLocEnd1NLeg(const ListBrlyQLocEnd1NLeg& src);
	~ListBrlyQLocEnd1NLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocEnd1NLeg* rec);

	ListBrlyQLocEnd1NLeg& operator=(const ListBrlyQLocEnd1NLeg& src);

public:
	std::vector<BrlyQLocEnd1NLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocEnd1NLeg: C++ wrapper for table TblBrlyQLocEnd1NLeg
	*/
class TblBrlyQLocEnd1NLeg {

public:
	TblBrlyQLocEnd1NLeg();
	virtual ~TblBrlyQLocEnd1NLeg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocEnd1NLeg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocEnd1NLeg& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocEnd1NLeg* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocEnd1NLeg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocEnd1NLeg& rst, BrlyQLocEnd1NLeg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQLocEnd1NLeg& rst);
	virtual void updateRec(BrlyQLocEnd1NLeg* rec);
	virtual void updateRst(ListBrlyQLocEnd1NLeg& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocEnd1NLeg** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocEnd1NLeg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocEnd1NLeg: C++ wrapper for table TblBrlyQLocEnd1NLeg (MySQL database)
	*/
class MyTblBrlyQLocEnd1NLeg : public TblBrlyQLocEnd1NLeg, public Sbecore::MyTable {

public:
	MyTblBrlyQLocEnd1NLeg();
	~MyTblBrlyQLocEnd1NLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocEnd1NLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocEnd1NLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLocEnd1NLeg* rec);
	void insertRst(ListBrlyQLocEnd1NLeg& rst);
	void updateRec(BrlyQLocEnd1NLeg* rec);
	void updateRst(ListBrlyQLocEnd1NLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocEnd1NLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocEnd1NLeg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocEnd1NLeg: C++ wrapper for table TblBrlyQLocEnd1NLeg (PgSQL database)
	*/
class PgTblBrlyQLocEnd1NLeg : public TblBrlyQLocEnd1NLeg, public Sbecore::PgTable {

public:
	PgTblBrlyQLocEnd1NLeg();
	~PgTblBrlyQLocEnd1NLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocEnd1NLeg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocEnd1NLeg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocEnd1NLeg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocEnd1NLeg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocEnd1NLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocEnd1NLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLocEnd1NLeg* rec);
	void insertRst(ListBrlyQLocEnd1NLeg& rst);
	void updateRec(BrlyQLocEnd1NLeg* rec);
	void updateRst(ListBrlyQLocEnd1NLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocEnd1NLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocEnd1NLeg& rst);
};
#endif

#endif
