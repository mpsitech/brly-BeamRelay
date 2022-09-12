/**
	* \file BrlyQUsgMNUser.h
	* Dbs and XML wrapper for table TblBrlyQUsgMNUser (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQUSGMNUSER_H
#define BRLYQUSGMNUSER_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQUsgMNUser: record of TblBrlyQUsgMNUser
	*/
class BrlyQUsgMNUser {

public:
	BrlyQUsgMNUser(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixBrlyVUserlevel = 0, const std::string srefIxBrlyVUserlevel = "", const std::string titIxBrlyVUserlevel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint ixBrlyVUserlevel;
	std::string srefIxBrlyVUserlevel;
	std::string titIxBrlyVUserlevel;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQUsgMNUser: recordset of TblBrlyQUsgMNUser
	*/
class ListBrlyQUsgMNUser {

public:
	ListBrlyQUsgMNUser();
	ListBrlyQUsgMNUser(const ListBrlyQUsgMNUser& src);
	~ListBrlyQUsgMNUser();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsgMNUser* rec);

	ListBrlyQUsgMNUser& operator=(const ListBrlyQUsgMNUser& src);

public:
	std::vector<BrlyQUsgMNUser*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQUsgMNUser: C++ wrapper for table TblBrlyQUsgMNUser
	*/
class TblBrlyQUsgMNUser {

public:
	TblBrlyQUsgMNUser();
	virtual ~TblBrlyQUsgMNUser();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQUsgMNUser** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsgMNUser& rst);

	virtual Sbecore::ubigint insertRec(BrlyQUsgMNUser* rec);
	Sbecore::ubigint insertNewRec(BrlyQUsgMNUser** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixBrlyVUserlevel = 0, const std::string srefIxBrlyVUserlevel = "", const std::string titIxBrlyVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQUsgMNUser& rst, BrlyQUsgMNUser** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixBrlyVUserlevel = 0, const std::string srefIxBrlyVUserlevel = "", const std::string titIxBrlyVUserlevel = "");
	virtual void insertRst(ListBrlyQUsgMNUser& rst);
	virtual void updateRec(BrlyQUsgMNUser* rec);
	virtual void updateRst(ListBrlyQUsgMNUser& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsgMNUser** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsgMNUser& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQUsgMNUser: C++ wrapper for table TblBrlyQUsgMNUser (MySQL database)
	*/
class MyTblBrlyQUsgMNUser : public TblBrlyQUsgMNUser, public Sbecore::MyTable {

public:
	MyTblBrlyQUsgMNUser();
	~MyTblBrlyQUsgMNUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsgMNUser& rst);

	Sbecore::ubigint insertRec(BrlyQUsgMNUser* rec);
	void insertRst(ListBrlyQUsgMNUser& rst);
	void updateRec(BrlyQUsgMNUser* rec);
	void updateRst(ListBrlyQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsgMNUser& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQUsgMNUser: C++ wrapper for table TblBrlyQUsgMNUser (PgSQL database)
	*/
class PgTblBrlyQUsgMNUser : public TblBrlyQUsgMNUser, public Sbecore::PgTable {

public:
	PgTblBrlyQUsgMNUser();
	~PgTblBrlyQUsgMNUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsgMNUser** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsgMNUser& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsgMNUser** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsgMNUser& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsgMNUser& rst);

	Sbecore::ubigint insertRec(BrlyQUsgMNUser* rec);
	void insertRst(ListBrlyQUsgMNUser& rst);
	void updateRec(BrlyQUsgMNUser* rec);
	void updateRst(ListBrlyQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsgMNUser& rst);
};
#endif

#endif
