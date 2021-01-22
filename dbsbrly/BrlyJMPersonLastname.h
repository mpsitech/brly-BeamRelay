/**
	* \file BrlyJMPersonLastname.h
	* database access for table TblBrlyJMPersonLastname (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYJMPERSONLASTNAME_H
#define BRLYJMPERSONLASTNAME_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyJMPersonLastname: record of TblBrlyJMPersonLastname
	*/
class BrlyJMPersonLastname {

public:
	BrlyJMPersonLastname(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMPerson;
	Sbecore::uint x1Startd;
	std::string Lastname;

public:
	bool operator==(const BrlyJMPersonLastname& comp);
	bool operator!=(const BrlyJMPersonLastname& comp);
};

/**
	* ListBrlyJMPersonLastname: recordset of TblBrlyJMPersonLastname
	*/
class ListBrlyJMPersonLastname {

public:
	ListBrlyJMPersonLastname();
	ListBrlyJMPersonLastname(const ListBrlyJMPersonLastname& src);
	~ListBrlyJMPersonLastname();

	void clear();
	unsigned int size() const;
	void append(BrlyJMPersonLastname* rec);

	BrlyJMPersonLastname* operator[](const Sbecore::uint ix);
	ListBrlyJMPersonLastname& operator=(const ListBrlyJMPersonLastname& src);
	bool operator==(const ListBrlyJMPersonLastname& comp);
	bool operator!=(const ListBrlyJMPersonLastname& comp);

public:
	std::vector<BrlyJMPersonLastname*> nodes;
};

/**
	* TblBrlyJMPersonLastname: C++ wrapper for table TblBrlyJMPersonLastname
	*/
class TblBrlyJMPersonLastname {

public:

public:
	TblBrlyJMPersonLastname();
	virtual ~TblBrlyJMPersonLastname();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyJMPersonLastname** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMPersonLastname& rst);

	virtual Sbecore::ubigint insertRec(BrlyJMPersonLastname* rec);
	Sbecore::ubigint insertNewRec(BrlyJMPersonLastname** rec = NULL, const Sbecore::ubigint refBrlyMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyJMPersonLastname& rst, BrlyJMPersonLastname** rec = NULL, const Sbecore::ubigint refBrlyMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");
	virtual void insertRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	virtual void updateRec(BrlyJMPersonLastname* rec);
	virtual void updateRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyJMPersonLastname** rec);
	virtual bool loadRecByPrsSta(Sbecore::ubigint refBrlyMPerson, Sbecore::uint x1Startd, BrlyJMPersonLastname** rec);
	virtual Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refBrlyMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refBrlyMPerson, const bool append, ListBrlyJMPersonLastname& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyJMPersonLastname& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyJMPersonLastname: C++ wrapper for table TblBrlyJMPersonLastname (MySQL database)
	*/
class MyTblBrlyJMPersonLastname : public TblBrlyJMPersonLastname, public Sbecore::MyTable {

public:
	MyTblBrlyJMPersonLastname();
	~MyTblBrlyJMPersonLastname();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMPersonLastname& rst);

	Sbecore::ubigint insertRec(BrlyJMPersonLastname* rec);
	void insertRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	void updateRec(BrlyJMPersonLastname* rec);
	void updateRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyJMPersonLastname** rec);
	bool loadRecByPrsSta(Sbecore::ubigint refBrlyMPerson, Sbecore::uint x1Startd, BrlyJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refBrlyMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refBrlyMPerson, const bool append, ListBrlyJMPersonLastname& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyJMPersonLastname: C++ wrapper for table TblBrlyJMPersonLastname (PgSQL database)
	*/
class PgTblBrlyJMPersonLastname : public TblBrlyJMPersonLastname, public Sbecore::PgTable {

public:
	PgTblBrlyJMPersonLastname();
	~PgTblBrlyJMPersonLastname();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyJMPersonLastname** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyJMPersonLastname& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyJMPersonLastname** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyJMPersonLastname& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyJMPersonLastname& rst);

	Sbecore::ubigint insertRec(BrlyJMPersonLastname* rec);
	void insertRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	void updateRec(BrlyJMPersonLastname* rec);
	void updateRst(ListBrlyJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyJMPersonLastname** rec);
	bool loadRecByPrsSta(Sbecore::ubigint refBrlyMPerson, Sbecore::uint x1Startd, BrlyJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refBrlyMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refBrlyMPerson, const bool append, ListBrlyJMPersonLastname& rst);
};
#endif

#endif
