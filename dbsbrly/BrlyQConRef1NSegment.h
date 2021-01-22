/**
	* \file BrlyQConRef1NSegment.h
	* Dbs and XML wrapper for table TblBrlyQConRef1NSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCONREF1NSEGMENT_H
#define BRLYQCONREF1NSEGMENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQConRef1NSegment: record of TblBrlyQConRef1NSegment
	*/
class BrlyQConRef1NSegment {

public:
	BrlyQConRef1NSegment(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint refNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQConRef1NSegment: recordset of TblBrlyQConRef1NSegment
	*/
class ListBrlyQConRef1NSegment {

public:
	ListBrlyQConRef1NSegment();
	ListBrlyQConRef1NSegment(const ListBrlyQConRef1NSegment& src);
	~ListBrlyQConRef1NSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyQConRef1NSegment* rec);

	ListBrlyQConRef1NSegment& operator=(const ListBrlyQConRef1NSegment& src);

public:
	std::vector<BrlyQConRef1NSegment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQConRef1NSegment: C++ wrapper for table TblBrlyQConRef1NSegment
	*/
class TblBrlyQConRef1NSegment {

public:
	TblBrlyQConRef1NSegment();
	virtual ~TblBrlyQConRef1NSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQConRef1NSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConRef1NSegment& rst);

	virtual Sbecore::ubigint insertRec(BrlyQConRef1NSegment* rec);
	Sbecore::ubigint insertNewRec(BrlyQConRef1NSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQConRef1NSegment& rst, BrlyQConRef1NSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListBrlyQConRef1NSegment& rst);
	virtual void updateRec(BrlyQConRef1NSegment* rec);
	virtual void updateRst(ListBrlyQConRef1NSegment& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQConRef1NSegment** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConRef1NSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQConRef1NSegment: C++ wrapper for table TblBrlyQConRef1NSegment (MySQL database)
	*/
class MyTblBrlyQConRef1NSegment : public TblBrlyQConRef1NSegment, public Sbecore::MyTable {

public:
	MyTblBrlyQConRef1NSegment();
	~MyTblBrlyQConRef1NSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConRef1NSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConRef1NSegment& rst);

	Sbecore::ubigint insertRec(BrlyQConRef1NSegment* rec);
	void insertRst(ListBrlyQConRef1NSegment& rst);
	void updateRec(BrlyQConRef1NSegment* rec);
	void updateRst(ListBrlyQConRef1NSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConRef1NSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConRef1NSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQConRef1NSegment: C++ wrapper for table TblBrlyQConRef1NSegment (PgSQL database)
	*/
class PgTblBrlyQConRef1NSegment : public TblBrlyQConRef1NSegment, public Sbecore::PgTable {

public:
	PgTblBrlyQConRef1NSegment();
	~PgTblBrlyQConRef1NSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConRef1NSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQConRef1NSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConRef1NSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConRef1NSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConRef1NSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConRef1NSegment& rst);

	Sbecore::ubigint insertRec(BrlyQConRef1NSegment* rec);
	void insertRst(ListBrlyQConRef1NSegment& rst);
	void updateRec(BrlyQConRef1NSegment* rec);
	void updateRst(ListBrlyQConRef1NSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConRef1NSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConRef1NSegment& rst);
};
#endif

#endif
