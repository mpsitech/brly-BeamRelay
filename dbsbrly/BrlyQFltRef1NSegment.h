/**
	* \file BrlyQFltRef1NSegment.h
	* Dbs and XML wrapper for table TblBrlyQFltRef1NSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQFLTREF1NSEGMENT_H
#define BRLYQFLTREF1NSEGMENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQFltRef1NSegment: record of TblBrlyQFltRef1NSegment
	*/
class BrlyQFltRef1NSegment {

public:
	BrlyQFltRef1NSegment(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint refNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQFltRef1NSegment: recordset of TblBrlyQFltRef1NSegment
	*/
class ListBrlyQFltRef1NSegment {

public:
	ListBrlyQFltRef1NSegment();
	ListBrlyQFltRef1NSegment(const ListBrlyQFltRef1NSegment& src);
	~ListBrlyQFltRef1NSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltRef1NSegment* rec);

	ListBrlyQFltRef1NSegment& operator=(const ListBrlyQFltRef1NSegment& src);

public:
	std::vector<BrlyQFltRef1NSegment*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQFltRef1NSegment: C++ wrapper for table TblBrlyQFltRef1NSegment
	*/
class TblBrlyQFltRef1NSegment {

public:
	TblBrlyQFltRef1NSegment();
	virtual ~TblBrlyQFltRef1NSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQFltRef1NSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltRef1NSegment& rst);

	virtual Sbecore::ubigint insertRec(BrlyQFltRef1NSegment* rec);
	Sbecore::ubigint insertNewRec(BrlyQFltRef1NSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQFltRef1NSegment& rst, BrlyQFltRef1NSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListBrlyQFltRef1NSegment& rst);
	virtual void updateRec(BrlyQFltRef1NSegment* rec);
	virtual void updateRst(ListBrlyQFltRef1NSegment& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltRef1NSegment** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltRef1NSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQFltRef1NSegment: C++ wrapper for table TblBrlyQFltRef1NSegment (MySQL database)
	*/
class MyTblBrlyQFltRef1NSegment : public TblBrlyQFltRef1NSegment, public Sbecore::MyTable {

public:
	MyTblBrlyQFltRef1NSegment();
	~MyTblBrlyQFltRef1NSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltRef1NSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltRef1NSegment& rst);

	Sbecore::ubigint insertRec(BrlyQFltRef1NSegment* rec);
	void insertRst(ListBrlyQFltRef1NSegment& rst);
	void updateRec(BrlyQFltRef1NSegment* rec);
	void updateRst(ListBrlyQFltRef1NSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltRef1NSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltRef1NSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQFltRef1NSegment: C++ wrapper for table TblBrlyQFltRef1NSegment (PgSQL database)
	*/
class PgTblBrlyQFltRef1NSegment : public TblBrlyQFltRef1NSegment, public Sbecore::PgTable {

public:
	PgTblBrlyQFltRef1NSegment();
	~PgTblBrlyQFltRef1NSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltRef1NSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltRef1NSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltRef1NSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltRef1NSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltRef1NSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltRef1NSegment& rst);

	Sbecore::ubigint insertRec(BrlyQFltRef1NSegment* rec);
	void insertRst(ListBrlyQFltRef1NSegment& rst);
	void updateRec(BrlyQFltRef1NSegment* rec);
	void updateRst(ListBrlyQFltRef1NSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltRef1NSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltRef1NSegment& rst);
};
#endif

#endif
