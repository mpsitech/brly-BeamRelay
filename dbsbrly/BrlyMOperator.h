/**
	* \file BrlyMOperator.h
	* database access for table TblBrlyMOperator (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMOPERATOR_H
#define BRLYMOPERATOR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyMOperator: record of TblBrlyMOperator
	*/
class BrlyMOperator {

public:
	BrlyMOperator(const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "");

public:
	Sbecore::ubigint ref;
	std::string sref;
	std::string srefICAO;
	std::string Title;

public:
	bool operator==(const BrlyMOperator& comp);
	bool operator!=(const BrlyMOperator& comp);
};

/**
	* ListBrlyMOperator: recordset of TblBrlyMOperator
	*/
class ListBrlyMOperator {

public:
	ListBrlyMOperator();
	ListBrlyMOperator(const ListBrlyMOperator& src);
	~ListBrlyMOperator();

	void clear();
	unsigned int size() const;
	void append(BrlyMOperator* rec);

	BrlyMOperator* operator[](const Sbecore::uint ix);
	ListBrlyMOperator& operator=(const ListBrlyMOperator& src);
	bool operator==(const ListBrlyMOperator& comp);
	bool operator!=(const ListBrlyMOperator& comp);

public:
	std::vector<BrlyMOperator*> nodes;
};

/**
	* TblBrlyMOperator: C++ wrapper for table TblBrlyMOperator
	*/
class TblBrlyMOperator {

public:

public:
	TblBrlyMOperator();
	virtual ~TblBrlyMOperator();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMOperator** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMOperator& rst);

	virtual Sbecore::ubigint insertRec(BrlyMOperator* rec);
	Sbecore::ubigint insertNewRec(BrlyMOperator** rec = NULL, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyMOperator& rst, BrlyMOperator** rec = NULL, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "");
	virtual void insertRst(ListBrlyMOperator& rst, bool transact = false);
	virtual void updateRec(BrlyMOperator* rec);
	virtual void updateRst(ListBrlyMOperator& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMOperator** rec);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMOperator& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMOperator: C++ wrapper for table TblBrlyMOperator (MySQL database)
	*/
class MyTblBrlyMOperator : public TblBrlyMOperator, public Sbecore::MyTable {

public:
	MyTblBrlyMOperator();
	~MyTblBrlyMOperator();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMOperator** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMOperator& rst);

	Sbecore::ubigint insertRec(BrlyMOperator* rec);
	void insertRst(ListBrlyMOperator& rst, bool transact = false);
	void updateRec(BrlyMOperator* rec);
	void updateRst(ListBrlyMOperator& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMOperator** rec);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMOperator: C++ wrapper for table TblBrlyMOperator (PgSQL database)
	*/
class PgTblBrlyMOperator : public TblBrlyMOperator, public Sbecore::PgTable {

public:
	PgTblBrlyMOperator();
	~PgTblBrlyMOperator();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMOperator** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMOperator& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMOperator** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMOperator** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMOperator& rst);

	Sbecore::ubigint insertRec(BrlyMOperator* rec);
	void insertRst(ListBrlyMOperator& rst, bool transact = false);
	void updateRec(BrlyMOperator* rec);
	void updateRst(ListBrlyMOperator& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMOperator** rec);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif
