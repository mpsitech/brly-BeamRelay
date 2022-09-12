/**
	* \file BrlyQRegSup1NRegion.h
	* Dbs and XML wrapper for table TblBrlyQRegSup1NRegion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQREGSUP1NREGION_H
#define BRLYQREGSUP1NREGION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQRegSup1NRegion: record of TblBrlyQRegSup1NRegion
	*/
class BrlyQRegSup1NRegion {

public:
	BrlyQRegSup1NRegion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListBrlyQRegSup1NRegion: recordset of TblBrlyQRegSup1NRegion
	*/
class ListBrlyQRegSup1NRegion {

public:
	ListBrlyQRegSup1NRegion();
	ListBrlyQRegSup1NRegion(const ListBrlyQRegSup1NRegion& src);
	~ListBrlyQRegSup1NRegion();

	void clear();
	unsigned int size() const;
	void append(BrlyQRegSup1NRegion* rec);

	ListBrlyQRegSup1NRegion& operator=(const ListBrlyQRegSup1NRegion& src);

public:
	std::vector<BrlyQRegSup1NRegion*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQRegSup1NRegion: C++ wrapper for table TblBrlyQRegSup1NRegion
	*/
class TblBrlyQRegSup1NRegion {

public:
	TblBrlyQRegSup1NRegion();
	virtual ~TblBrlyQRegSup1NRegion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQRegSup1NRegion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRegSup1NRegion& rst);

	virtual Sbecore::ubigint insertRec(BrlyQRegSup1NRegion* rec);
	Sbecore::ubigint insertNewRec(BrlyQRegSup1NRegion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQRegSup1NRegion& rst, BrlyQRegSup1NRegion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQRegSup1NRegion& rst);
	virtual void updateRec(BrlyQRegSup1NRegion* rec);
	virtual void updateRst(ListBrlyQRegSup1NRegion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQRegSup1NRegion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRegSup1NRegion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQRegSup1NRegion: C++ wrapper for table TblBrlyQRegSup1NRegion (MySQL database)
	*/
class MyTblBrlyQRegSup1NRegion : public TblBrlyQRegSup1NRegion, public Sbecore::MyTable {

public:
	MyTblBrlyQRegSup1NRegion();
	~MyTblBrlyQRegSup1NRegion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQRegSup1NRegion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRegSup1NRegion& rst);

	Sbecore::ubigint insertRec(BrlyQRegSup1NRegion* rec);
	void insertRst(ListBrlyQRegSup1NRegion& rst);
	void updateRec(BrlyQRegSup1NRegion* rec);
	void updateRst(ListBrlyQRegSup1NRegion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQRegSup1NRegion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRegSup1NRegion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQRegSup1NRegion: C++ wrapper for table TblBrlyQRegSup1NRegion (PgSQL database)
	*/
class PgTblBrlyQRegSup1NRegion : public TblBrlyQRegSup1NRegion, public Sbecore::PgTable {

public:
	PgTblBrlyQRegSup1NRegion();
	~PgTblBrlyQRegSup1NRegion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQRegSup1NRegion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQRegSup1NRegion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQRegSup1NRegion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQRegSup1NRegion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQRegSup1NRegion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRegSup1NRegion& rst);

	Sbecore::ubigint insertRec(BrlyQRegSup1NRegion* rec);
	void insertRst(ListBrlyQRegSup1NRegion& rst);
	void updateRec(BrlyQRegSup1NRegion* rec);
	void updateRst(ListBrlyQRegSup1NRegion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQRegSup1NRegion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRegSup1NRegion& rst);
};
#endif

#endif
