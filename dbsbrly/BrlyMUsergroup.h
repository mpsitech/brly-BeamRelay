/**
	* \file BrlyMUsergroup.h
	* database access for table TblBrlyMUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMUSERGROUP_H
#define BRLYMUSERGROUP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyMUsergroup: record of TblBrlyMUsergroup
	*/
class BrlyMUsergroup {

public:
	BrlyMUsergroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const BrlyMUsergroup& comp);
	bool operator!=(const BrlyMUsergroup& comp);
};

/**
	* ListBrlyMUsergroup: recordset of TblBrlyMUsergroup
	*/
class ListBrlyMUsergroup {

public:
	ListBrlyMUsergroup();
	ListBrlyMUsergroup(const ListBrlyMUsergroup& src);
	~ListBrlyMUsergroup();

	void clear();
	unsigned int size() const;
	void append(BrlyMUsergroup* rec);

	BrlyMUsergroup* operator[](const Sbecore::uint ix);
	ListBrlyMUsergroup& operator=(const ListBrlyMUsergroup& src);
	bool operator==(const ListBrlyMUsergroup& comp);
	bool operator!=(const ListBrlyMUsergroup& comp);

public:
	std::vector<BrlyMUsergroup*> nodes;
};

/**
	* TblBrlyMUsergroup: C++ wrapper for table TblBrlyMUsergroup
	*/
class TblBrlyMUsergroup {

public:

public:
	TblBrlyMUsergroup();
	virtual ~TblBrlyMUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMUsergroup& rst);

	virtual Sbecore::ubigint insertRec(BrlyMUsergroup* rec);
	Sbecore::ubigint insertNewRec(BrlyMUsergroup** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyMUsergroup& rst, BrlyMUsergroup** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListBrlyMUsergroup& rst, bool transact = false);
	virtual void updateRec(BrlyMUsergroup* rec);
	virtual void updateRst(ListBrlyMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMUsergroup** rec);
	virtual bool loadRecBySrf(std::string sref, BrlyMUsergroup** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMUsergroup: C++ wrapper for table TblBrlyMUsergroup (MySQL database)
	*/
class MyTblBrlyMUsergroup : public TblBrlyMUsergroup, public Sbecore::MyTable {

public:
	MyTblBrlyMUsergroup();
	~MyTblBrlyMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMUsergroup& rst);

	Sbecore::ubigint insertRec(BrlyMUsergroup* rec);
	void insertRst(ListBrlyMUsergroup& rst, bool transact = false);
	void updateRec(BrlyMUsergroup* rec);
	void updateRst(ListBrlyMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMUsergroup** rec);
	bool loadRecBySrf(std::string sref, BrlyMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMUsergroup: C++ wrapper for table TblBrlyMUsergroup (PgSQL database)
	*/
class PgTblBrlyMUsergroup : public TblBrlyMUsergroup, public Sbecore::PgTable {

public:
	PgTblBrlyMUsergroup();
	~PgTblBrlyMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMUsergroup** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMUsergroup& rst);

	Sbecore::ubigint insertRec(BrlyMUsergroup* rec);
	void insertRst(ListBrlyMUsergroup& rst, bool transact = false);
	void updateRec(BrlyMUsergroup* rec);
	void updateRst(ListBrlyMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMUsergroup** rec);
	bool loadRecBySrf(std::string sref, BrlyMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
