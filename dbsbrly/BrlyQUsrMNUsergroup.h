/**
	* \file BrlyQUsrMNUsergroup.h
	* Dbs and XML wrapper for table TblBrlyQUsrMNUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQUSRMNUSERGROUP_H
#define BRLYQUSRMNUSERGROUP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQUsrMNUsergroup: record of TblBrlyQUsrMNUsergroup
	*/
class BrlyQUsrMNUsergroup {

public:
	BrlyQUsrMNUsergroup(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixBrlyVUserlevel = 0, const std::string srefIxBrlyVUserlevel = "", const std::string titIxBrlyVUserlevel = "");

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
	* ListBrlyQUsrMNUsergroup: recordset of TblBrlyQUsrMNUsergroup
	*/
class ListBrlyQUsrMNUsergroup {

public:
	ListBrlyQUsrMNUsergroup();
	ListBrlyQUsrMNUsergroup(const ListBrlyQUsrMNUsergroup& src);
	~ListBrlyQUsrMNUsergroup();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsrMNUsergroup* rec);

	ListBrlyQUsrMNUsergroup& operator=(const ListBrlyQUsrMNUsergroup& src);

public:
	std::vector<BrlyQUsrMNUsergroup*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQUsrMNUsergroup: C++ wrapper for table TblBrlyQUsrMNUsergroup
	*/
class TblBrlyQUsrMNUsergroup {

public:
	TblBrlyQUsrMNUsergroup();
	virtual ~TblBrlyQUsrMNUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQUsrMNUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsrMNUsergroup& rst);

	virtual Sbecore::ubigint insertRec(BrlyQUsrMNUsergroup* rec);
	Sbecore::ubigint insertNewRec(BrlyQUsrMNUsergroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixBrlyVUserlevel = 0, const std::string srefIxBrlyVUserlevel = "", const std::string titIxBrlyVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQUsrMNUsergroup& rst, BrlyQUsrMNUsergroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixBrlyVUserlevel = 0, const std::string srefIxBrlyVUserlevel = "", const std::string titIxBrlyVUserlevel = "");
	virtual void insertRst(ListBrlyQUsrMNUsergroup& rst);
	virtual void updateRec(BrlyQUsrMNUsergroup* rec);
	virtual void updateRst(ListBrlyQUsrMNUsergroup& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsrMNUsergroup** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsrMNUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQUsrMNUsergroup: C++ wrapper for table TblBrlyQUsrMNUsergroup (MySQL database)
	*/
class MyTblBrlyQUsrMNUsergroup : public TblBrlyQUsrMNUsergroup, public Sbecore::MyTable {

public:
	MyTblBrlyQUsrMNUsergroup();
	~MyTblBrlyQUsrMNUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(BrlyQUsrMNUsergroup* rec);
	void insertRst(ListBrlyQUsrMNUsergroup& rst);
	void updateRec(BrlyQUsrMNUsergroup* rec);
	void updateRst(ListBrlyQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsrMNUsergroup& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQUsrMNUsergroup: C++ wrapper for table TblBrlyQUsrMNUsergroup (PgSQL database)
	*/
class PgTblBrlyQUsrMNUsergroup : public TblBrlyQUsrMNUsergroup, public Sbecore::PgTable {

public:
	PgTblBrlyQUsrMNUsergroup();
	~PgTblBrlyQUsrMNUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsrMNUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsrMNUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(BrlyQUsrMNUsergroup* rec);
	void insertRst(ListBrlyQUsrMNUsergroup& rst);
	void updateRec(BrlyQUsrMNUsergroup* rec);
	void updateRst(ListBrlyQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsrMNUsergroup& rst);
};
#endif

#endif
