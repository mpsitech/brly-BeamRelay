/**
	* \file BrlyQUsrList.h
	* Dbs and XML wrapper for table TblBrlyQUsrList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQUSRLIST_H
#define BRLYQUSRLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQUsrList: record of TblBrlyQUsrList
	*/
class BrlyQUsrList {

public:
	BrlyQUsrList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refBrlyMPerson = 0, const std::string stubRefBrlyMPerson = "", const std::string sref = "", const Sbecore::ubigint refBrlyMUsergroup = 0, const std::string stubRefBrlyMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixBrlyVLocale = 0, const std::string srefIxBrlyVLocale = "", const std::string titIxBrlyVLocale = "", const Sbecore::uint ixBrlyVUserlevel = 0, const std::string srefIxBrlyVUserlevel = "", const std::string titIxBrlyVUserlevel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::ubigint refBrlyMPerson;
	std::string stubRefBrlyMPerson;
	std::string sref;
	Sbecore::ubigint refBrlyMUsergroup;
	std::string stubRefBrlyMUsergroup;
	Sbecore::uint ixVState;
	std::string srefIxVState;
	std::string titIxVState;
	Sbecore::uint ixBrlyVLocale;
	std::string srefIxBrlyVLocale;
	std::string titIxBrlyVLocale;
	Sbecore::uint ixBrlyVUserlevel;
	std::string srefIxBrlyVUserlevel;
	std::string titIxBrlyVUserlevel;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQUsrList: recordset of TblBrlyQUsrList
	*/
class ListBrlyQUsrList {

public:
	ListBrlyQUsrList();
	ListBrlyQUsrList(const ListBrlyQUsrList& src);
	~ListBrlyQUsrList();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsrList* rec);

	ListBrlyQUsrList& operator=(const ListBrlyQUsrList& src);

public:
	std::vector<BrlyQUsrList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQUsrList: C++ wrapper for table TblBrlyQUsrList
	*/
class TblBrlyQUsrList {

public:
	TblBrlyQUsrList();
	virtual ~TblBrlyQUsrList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQUsrList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsrList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQUsrList* rec);
	Sbecore::ubigint insertNewRec(BrlyQUsrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refBrlyMPerson = 0, const std::string stubRefBrlyMPerson = "", const std::string sref = "", const Sbecore::ubigint refBrlyMUsergroup = 0, const std::string stubRefBrlyMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixBrlyVLocale = 0, const std::string srefIxBrlyVLocale = "", const std::string titIxBrlyVLocale = "", const Sbecore::uint ixBrlyVUserlevel = 0, const std::string srefIxBrlyVUserlevel = "", const std::string titIxBrlyVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQUsrList& rst, BrlyQUsrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refBrlyMPerson = 0, const std::string stubRefBrlyMPerson = "", const std::string sref = "", const Sbecore::ubigint refBrlyMUsergroup = 0, const std::string stubRefBrlyMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixBrlyVLocale = 0, const std::string srefIxBrlyVLocale = "", const std::string titIxBrlyVLocale = "", const Sbecore::uint ixBrlyVUserlevel = 0, const std::string srefIxBrlyVUserlevel = "", const std::string titIxBrlyVUserlevel = "");
	virtual void insertRst(ListBrlyQUsrList& rst);
	virtual void updateRec(BrlyQUsrList* rec);
	virtual void updateRst(ListBrlyQUsrList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsrList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsrList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQUsrList: C++ wrapper for table TblBrlyQUsrList (MySQL database)
	*/
class MyTblBrlyQUsrList : public TblBrlyQUsrList, public Sbecore::MyTable {

public:
	MyTblBrlyQUsrList();
	~MyTblBrlyQUsrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsrList& rst);

	Sbecore::ubigint insertRec(BrlyQUsrList* rec);
	void insertRst(ListBrlyQUsrList& rst);
	void updateRec(BrlyQUsrList* rec);
	void updateRst(ListBrlyQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsrList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQUsrList: C++ wrapper for table TblBrlyQUsrList (PgSQL database)
	*/
class PgTblBrlyQUsrList : public TblBrlyQUsrList, public Sbecore::PgTable {

public:
	PgTblBrlyQUsrList();
	~PgTblBrlyQUsrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsrList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsrList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsrList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsrList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsrList& rst);

	Sbecore::ubigint insertRec(BrlyQUsrList* rec);
	void insertRst(ListBrlyQUsrList& rst);
	void updateRec(BrlyQUsrList* rec);
	void updateRst(ListBrlyQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsrList& rst);
};
#endif

#endif
