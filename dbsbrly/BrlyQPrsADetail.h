/**
	* \file BrlyQPrsADetail.h
	* Dbs and XML wrapper for table TblBrlyQPrsADetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQPRSADETAIL_H
#define BRLYQPRSADETAIL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQPrsADetail: record of TblBrlyQPrsADetail
	*/
class BrlyQPrsADetail {

public:
	BrlyQPrsADetail(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKType;
	std::string titX1SrefKType;
	std::string Val;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQPrsADetail: recordset of TblBrlyQPrsADetail
	*/
class ListBrlyQPrsADetail {

public:
	ListBrlyQPrsADetail();
	ListBrlyQPrsADetail(const ListBrlyQPrsADetail& src);
	~ListBrlyQPrsADetail();

	void clear();
	unsigned int size() const;
	void append(BrlyQPrsADetail* rec);

	ListBrlyQPrsADetail& operator=(const ListBrlyQPrsADetail& src);

public:
	std::vector<BrlyQPrsADetail*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQPrsADetail: C++ wrapper for table TblBrlyQPrsADetail
	*/
class TblBrlyQPrsADetail {

public:
	TblBrlyQPrsADetail();
	virtual ~TblBrlyQPrsADetail();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQPrsADetail** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPrsADetail& rst);

	virtual Sbecore::ubigint insertRec(BrlyQPrsADetail* rec);
	Sbecore::ubigint insertNewRec(BrlyQPrsADetail** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQPrsADetail& rst, BrlyQPrsADetail** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");
	virtual void insertRst(ListBrlyQPrsADetail& rst);
	virtual void updateRec(BrlyQPrsADetail* rec);
	virtual void updateRst(ListBrlyQPrsADetail& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQPrsADetail** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPrsADetail& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQPrsADetail: C++ wrapper for table TblBrlyQPrsADetail (MySQL database)
	*/
class MyTblBrlyQPrsADetail : public TblBrlyQPrsADetail, public Sbecore::MyTable {

public:
	MyTblBrlyQPrsADetail();
	~MyTblBrlyQPrsADetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPrsADetail& rst);

	Sbecore::ubigint insertRec(BrlyQPrsADetail* rec);
	void insertRst(ListBrlyQPrsADetail& rst);
	void updateRec(BrlyQPrsADetail* rec);
	void updateRst(ListBrlyQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPrsADetail& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQPrsADetail: C++ wrapper for table TblBrlyQPrsADetail (PgSQL database)
	*/
class PgTblBrlyQPrsADetail : public TblBrlyQPrsADetail, public Sbecore::PgTable {

public:
	PgTblBrlyQPrsADetail();
	~PgTblBrlyQPrsADetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQPrsADetail** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQPrsADetail& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQPrsADetail** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQPrsADetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPrsADetail& rst);

	Sbecore::ubigint insertRec(BrlyQPrsADetail* rec);
	void insertRst(ListBrlyQPrsADetail& rst);
	void updateRec(BrlyQPrsADetail* rec);
	void updateRst(ListBrlyQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPrsADetail& rst);
};
#endif

#endif
