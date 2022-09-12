/**
	* \file BrlyQUsgAAccess.h
	* Dbs and XML wrapper for table TblBrlyQUsgAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQUSGAACCESS_H
#define BRLYQUSGAACCESS_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQUsgAAccess: record of TblBrlyQUsgAAccess
	*/
class BrlyQUsgAAccess {

public:
	BrlyQUsgAAccess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string srefX1IxBrlyVFeatgroup = "", const std::string titX1IxBrlyVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0, const std::string srefsIxBrlyWAccess = "", const std::string titsIxBrlyWAccess = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1IxBrlyVFeatgroup;
	std::string srefX1IxBrlyVFeatgroup;
	std::string titX1IxBrlyVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixBrlyWAccess;
	std::string srefsIxBrlyWAccess;
	std::string titsIxBrlyWAccess;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQUsgAAccess: recordset of TblBrlyQUsgAAccess
	*/
class ListBrlyQUsgAAccess {

public:
	ListBrlyQUsgAAccess();
	ListBrlyQUsgAAccess(const ListBrlyQUsgAAccess& src);
	~ListBrlyQUsgAAccess();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsgAAccess* rec);

	ListBrlyQUsgAAccess& operator=(const ListBrlyQUsgAAccess& src);

public:
	std::vector<BrlyQUsgAAccess*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQUsgAAccess: C++ wrapper for table TblBrlyQUsgAAccess
	*/
class TblBrlyQUsgAAccess {

public:
	TblBrlyQUsgAAccess();
	virtual ~TblBrlyQUsgAAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQUsgAAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsgAAccess& rst);

	virtual Sbecore::ubigint insertRec(BrlyQUsgAAccess* rec);
	Sbecore::ubigint insertNewRec(BrlyQUsgAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string srefX1IxBrlyVFeatgroup = "", const std::string titX1IxBrlyVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0, const std::string srefsIxBrlyWAccess = "", const std::string titsIxBrlyWAccess = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQUsgAAccess& rst, BrlyQUsgAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string srefX1IxBrlyVFeatgroup = "", const std::string titX1IxBrlyVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0, const std::string srefsIxBrlyWAccess = "", const std::string titsIxBrlyWAccess = "");
	virtual void insertRst(ListBrlyQUsgAAccess& rst);
	virtual void updateRec(BrlyQUsgAAccess* rec);
	virtual void updateRst(ListBrlyQUsgAAccess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsgAAccess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsgAAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQUsgAAccess: C++ wrapper for table TblBrlyQUsgAAccess (MySQL database)
	*/
class MyTblBrlyQUsgAAccess : public TblBrlyQUsgAAccess, public Sbecore::MyTable {

public:
	MyTblBrlyQUsgAAccess();
	~MyTblBrlyQUsgAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsgAAccess& rst);

	Sbecore::ubigint insertRec(BrlyQUsgAAccess* rec);
	void insertRst(ListBrlyQUsgAAccess& rst);
	void updateRec(BrlyQUsgAAccess* rec);
	void updateRst(ListBrlyQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsgAAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQUsgAAccess: C++ wrapper for table TblBrlyQUsgAAccess (PgSQL database)
	*/
class PgTblBrlyQUsgAAccess : public TblBrlyQUsgAAccess, public Sbecore::PgTable {

public:
	PgTblBrlyQUsgAAccess();
	~PgTblBrlyQUsgAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsgAAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsgAAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsgAAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsgAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsgAAccess& rst);

	Sbecore::ubigint insertRec(BrlyQUsgAAccess* rec);
	void insertRst(ListBrlyQUsgAAccess& rst);
	void updateRec(BrlyQUsgAAccess* rec);
	void updateRst(ListBrlyQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsgAAccess& rst);
};
#endif

#endif
