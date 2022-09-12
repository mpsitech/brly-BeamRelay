/**
	* \file BrlyQPrsList.h
	* Dbs and XML wrapper for table TblBrlyQPrsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQPRSLIST_H
#define BRLYQPRSLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQPrsList: record of TblBrlyQPrsList
	*/
class BrlyQPrsList {

public:
	BrlyQPrsList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Title;
	std::string Firstname;
	std::string Lastname;
	Sbecore::uint ixVSex;
	std::string srefIxVSex;
	std::string titIxVSex;
	std::string telVal;
	std::string emlVal;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQPrsList: recordset of TblBrlyQPrsList
	*/
class ListBrlyQPrsList {

public:
	ListBrlyQPrsList();
	ListBrlyQPrsList(const ListBrlyQPrsList& src);
	~ListBrlyQPrsList();

	void clear();
	unsigned int size() const;
	void append(BrlyQPrsList* rec);

	ListBrlyQPrsList& operator=(const ListBrlyQPrsList& src);

public:
	std::vector<BrlyQPrsList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQPrsList: C++ wrapper for table TblBrlyQPrsList
	*/
class TblBrlyQPrsList {

public:
	TblBrlyQPrsList();
	virtual ~TblBrlyQPrsList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQPrsList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPrsList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQPrsList* rec);
	Sbecore::ubigint insertNewRec(BrlyQPrsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQPrsList& rst, BrlyQPrsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");
	virtual void insertRst(ListBrlyQPrsList& rst);
	virtual void updateRec(BrlyQPrsList* rec);
	virtual void updateRst(ListBrlyQPrsList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQPrsList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPrsList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQPrsList: C++ wrapper for table TblBrlyQPrsList (MySQL database)
	*/
class MyTblBrlyQPrsList : public TblBrlyQPrsList, public Sbecore::MyTable {

public:
	MyTblBrlyQPrsList();
	~MyTblBrlyQPrsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPrsList& rst);

	Sbecore::ubigint insertRec(BrlyQPrsList* rec);
	void insertRst(ListBrlyQPrsList& rst);
	void updateRec(BrlyQPrsList* rec);
	void updateRst(ListBrlyQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPrsList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQPrsList: C++ wrapper for table TblBrlyQPrsList (PgSQL database)
	*/
class PgTblBrlyQPrsList : public TblBrlyQPrsList, public Sbecore::PgTable {

public:
	PgTblBrlyQPrsList();
	~PgTblBrlyQPrsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQPrsList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQPrsList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQPrsList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQPrsList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPrsList& rst);

	Sbecore::ubigint insertRec(BrlyQPrsList* rec);
	void insertRst(ListBrlyQPrsList& rst);
	void updateRec(BrlyQPrsList* rec);
	void updateRst(ListBrlyQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPrsList& rst);
};
#endif

#endif
