/**
	* \file BrlyQRegList.h
	* Dbs and XML wrapper for table TblBrlyQRegList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQREGLIST_H
#define BRLYQREGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQRegList: record of TblBrlyQRegList
	*/
class BrlyQRegList {

public:
	BrlyQRegList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint supRefBrlyMRegion = 0, const std::string stubSupRefBrlyMRegion = "", const Sbecore::uint ixVDst = 0, const std::string srefIxVDst = "", const std::string titIxVDst = "", const double toffset = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint supRefBrlyMRegion;
	std::string stubSupRefBrlyMRegion;
	Sbecore::uint ixVDst;
	std::string srefIxVDst;
	std::string titIxVDst;
	double toffset;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQRegList: recordset of TblBrlyQRegList
	*/
class ListBrlyQRegList {

public:
	ListBrlyQRegList();
	ListBrlyQRegList(const ListBrlyQRegList& src);
	~ListBrlyQRegList();

	void clear();
	unsigned int size() const;
	void append(BrlyQRegList* rec);

	ListBrlyQRegList& operator=(const ListBrlyQRegList& src);

public:
	std::vector<BrlyQRegList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQRegList: C++ wrapper for table TblBrlyQRegList
	*/
class TblBrlyQRegList {

public:
	TblBrlyQRegList();
	virtual ~TblBrlyQRegList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQRegList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRegList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQRegList* rec);
	Sbecore::ubigint insertNewRec(BrlyQRegList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint supRefBrlyMRegion = 0, const std::string stubSupRefBrlyMRegion = "", const Sbecore::uint ixVDst = 0, const std::string srefIxVDst = "", const std::string titIxVDst = "", const double toffset = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQRegList& rst, BrlyQRegList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint supRefBrlyMRegion = 0, const std::string stubSupRefBrlyMRegion = "", const Sbecore::uint ixVDst = 0, const std::string srefIxVDst = "", const std::string titIxVDst = "", const double toffset = 0.0);
	virtual void insertRst(ListBrlyQRegList& rst);
	virtual void updateRec(BrlyQRegList* rec);
	virtual void updateRst(ListBrlyQRegList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQRegList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRegList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQRegList: C++ wrapper for table TblBrlyQRegList (MySQL database)
	*/
class MyTblBrlyQRegList : public TblBrlyQRegList, public Sbecore::MyTable {

public:
	MyTblBrlyQRegList();
	~MyTblBrlyQRegList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQRegList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRegList& rst);

	Sbecore::ubigint insertRec(BrlyQRegList* rec);
	void insertRst(ListBrlyQRegList& rst);
	void updateRec(BrlyQRegList* rec);
	void updateRst(ListBrlyQRegList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQRegList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRegList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQRegList: C++ wrapper for table TblBrlyQRegList (PgSQL database)
	*/
class PgTblBrlyQRegList : public TblBrlyQRegList, public Sbecore::PgTable {

public:
	PgTblBrlyQRegList();
	~PgTblBrlyQRegList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQRegList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQRegList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQRegList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQRegList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQRegList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRegList& rst);

	Sbecore::ubigint insertRec(BrlyQRegList* rec);
	void insertRst(ListBrlyQRegList& rst);
	void updateRec(BrlyQRegList* rec);
	void updateRst(ListBrlyQRegList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQRegList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRegList& rst);
};
#endif

#endif
