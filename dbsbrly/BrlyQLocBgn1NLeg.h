/**
	* \file BrlyQLocBgn1NLeg.h
	* Dbs and XML wrapper for table TblBrlyQLocBgn1NLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCBGN1NLEG_H
#define BRLYQLOCBGN1NLEG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocBgn1NLeg: record of TblBrlyQLocBgn1NLeg
	*/
class BrlyQLocBgn1NLeg {

public:
	BrlyQLocBgn1NLeg(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListBrlyQLocBgn1NLeg: recordset of TblBrlyQLocBgn1NLeg
	*/
class ListBrlyQLocBgn1NLeg {

public:
	ListBrlyQLocBgn1NLeg();
	ListBrlyQLocBgn1NLeg(const ListBrlyQLocBgn1NLeg& src);
	~ListBrlyQLocBgn1NLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocBgn1NLeg* rec);

	ListBrlyQLocBgn1NLeg& operator=(const ListBrlyQLocBgn1NLeg& src);

public:
	std::vector<BrlyQLocBgn1NLeg*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocBgn1NLeg: C++ wrapper for table TblBrlyQLocBgn1NLeg
	*/
class TblBrlyQLocBgn1NLeg {

public:
	TblBrlyQLocBgn1NLeg();
	virtual ~TblBrlyQLocBgn1NLeg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocBgn1NLeg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocBgn1NLeg& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocBgn1NLeg* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocBgn1NLeg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocBgn1NLeg& rst, BrlyQLocBgn1NLeg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQLocBgn1NLeg& rst);
	virtual void updateRec(BrlyQLocBgn1NLeg* rec);
	virtual void updateRst(ListBrlyQLocBgn1NLeg& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocBgn1NLeg** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocBgn1NLeg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocBgn1NLeg: C++ wrapper for table TblBrlyQLocBgn1NLeg (MySQL database)
	*/
class MyTblBrlyQLocBgn1NLeg : public TblBrlyQLocBgn1NLeg, public Sbecore::MyTable {

public:
	MyTblBrlyQLocBgn1NLeg();
	~MyTblBrlyQLocBgn1NLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocBgn1NLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocBgn1NLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLocBgn1NLeg* rec);
	void insertRst(ListBrlyQLocBgn1NLeg& rst);
	void updateRec(BrlyQLocBgn1NLeg* rec);
	void updateRst(ListBrlyQLocBgn1NLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocBgn1NLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocBgn1NLeg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocBgn1NLeg: C++ wrapper for table TblBrlyQLocBgn1NLeg (PgSQL database)
	*/
class PgTblBrlyQLocBgn1NLeg : public TblBrlyQLocBgn1NLeg, public Sbecore::PgTable {

public:
	PgTblBrlyQLocBgn1NLeg();
	~PgTblBrlyQLocBgn1NLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocBgn1NLeg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocBgn1NLeg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocBgn1NLeg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocBgn1NLeg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocBgn1NLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocBgn1NLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLocBgn1NLeg* rec);
	void insertRst(ListBrlyQLocBgn1NLeg& rst);
	void updateRec(BrlyQLocBgn1NLeg* rec);
	void updateRst(ListBrlyQLocBgn1NLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocBgn1NLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocBgn1NLeg& rst);
};
#endif

#endif
