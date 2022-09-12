/**
	* \file BrlyQLegList.h
	* Dbs and XML wrapper for table TblBrlyQLegList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLEGLIST_H
#define BRLYQLEGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLegList: record of TblBrlyQLegList
	*/
class BrlyQLegList {

public:
	BrlyQLegList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint bgnRefBrlyMLocation = 0, const std::string stubBgnRefBrlyMLocation = "", const Sbecore::ubigint endRefBrlyMLocation = 0, const std::string stubEndRefBrlyMLocation = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const double alt = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::ubigint bgnRefBrlyMLocation;
	std::string stubBgnRefBrlyMLocation;
	Sbecore::ubigint endRefBrlyMLocation;
	std::string stubEndRefBrlyMLocation;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	double alt;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLegList: recordset of TblBrlyQLegList
	*/
class ListBrlyQLegList {

public:
	ListBrlyQLegList();
	ListBrlyQLegList(const ListBrlyQLegList& src);
	~ListBrlyQLegList();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegList* rec);

	ListBrlyQLegList& operator=(const ListBrlyQLegList& src);

public:
	std::vector<BrlyQLegList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLegList: C++ wrapper for table TblBrlyQLegList
	*/
class TblBrlyQLegList {

public:
	TblBrlyQLegList();
	virtual ~TblBrlyQLegList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLegList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLegList* rec);
	Sbecore::ubigint insertNewRec(BrlyQLegList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint bgnRefBrlyMLocation = 0, const std::string stubBgnRefBrlyMLocation = "", const Sbecore::ubigint endRefBrlyMLocation = 0, const std::string stubEndRefBrlyMLocation = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const double alt = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLegList& rst, BrlyQLegList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint bgnRefBrlyMLocation = 0, const std::string stubBgnRefBrlyMLocation = "", const Sbecore::ubigint endRefBrlyMLocation = 0, const std::string stubEndRefBrlyMLocation = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const double alt = 0.0);
	virtual void insertRst(ListBrlyQLegList& rst);
	virtual void updateRec(BrlyQLegList* rec);
	virtual void updateRst(ListBrlyQLegList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLegList: C++ wrapper for table TblBrlyQLegList (MySQL database)
	*/
class MyTblBrlyQLegList : public TblBrlyQLegList, public Sbecore::MyTable {

public:
	MyTblBrlyQLegList();
	~MyTblBrlyQLegList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegList& rst);

	Sbecore::ubigint insertRec(BrlyQLegList* rec);
	void insertRst(ListBrlyQLegList& rst);
	void updateRec(BrlyQLegList* rec);
	void updateRst(ListBrlyQLegList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLegList: C++ wrapper for table TblBrlyQLegList (PgSQL database)
	*/
class PgTblBrlyQLegList : public TblBrlyQLegList, public Sbecore::PgTable {

public:
	PgTblBrlyQLegList();
	~PgTblBrlyQLegList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegList& rst);

	Sbecore::ubigint insertRec(BrlyQLegList* rec);
	void insertRst(ListBrlyQLegList& rst);
	void updateRec(BrlyQLegList* rec);
	void updateRst(ListBrlyQLegList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegList& rst);
};
#endif

#endif
