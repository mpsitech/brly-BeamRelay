/**
	* \file BrlyAVControlPar.h
	* database access for table TblBrlyAVControlPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYAVCONTROLPAR_H
#define BRLYAVCONTROLPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyAVControlPar: record of TblBrlyAVControlPar
	*/
class BrlyAVControlPar {

public:
	BrlyAVControlPar(const Sbecore::ubigint ref = 0, const Sbecore::uint ixBrlyVControl = 0, const Sbecore::ubigint x1RefBrlyMUser = 0, const Sbecore::uint x2IxBrlyVLocale = 0, const std::string Par = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixBrlyVControl;
	Sbecore::ubigint x1RefBrlyMUser;
	Sbecore::uint x2IxBrlyVLocale;
	std::string Par;
	std::string Val;

public:
	bool operator==(const BrlyAVControlPar& comp);
	bool operator!=(const BrlyAVControlPar& comp);
};

/**
	* ListBrlyAVControlPar: recordset of TblBrlyAVControlPar
	*/
class ListBrlyAVControlPar {

public:
	ListBrlyAVControlPar();
	ListBrlyAVControlPar(const ListBrlyAVControlPar& src);
	~ListBrlyAVControlPar();

	void clear();
	unsigned int size() const;
	void append(BrlyAVControlPar* rec);

	BrlyAVControlPar* operator[](const Sbecore::uint ix);
	ListBrlyAVControlPar& operator=(const ListBrlyAVControlPar& src);
	bool operator==(const ListBrlyAVControlPar& comp);
	bool operator!=(const ListBrlyAVControlPar& comp);

public:
	std::vector<BrlyAVControlPar*> nodes;
};

/**
	* TblBrlyAVControlPar: C++ wrapper for table TblBrlyAVControlPar
	*/
class TblBrlyAVControlPar {

public:

public:
	TblBrlyAVControlPar();
	virtual ~TblBrlyAVControlPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyAVControlPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAVControlPar& rst);

	virtual Sbecore::ubigint insertRec(BrlyAVControlPar* rec);
	Sbecore::ubigint insertNewRec(BrlyAVControlPar** rec = NULL, const Sbecore::uint ixBrlyVControl = 0, const Sbecore::ubigint x1RefBrlyMUser = 0, const Sbecore::uint x2IxBrlyVLocale = 0, const std::string Par = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyAVControlPar& rst, BrlyAVControlPar** rec = NULL, const Sbecore::uint ixBrlyVControl = 0, const Sbecore::ubigint x1RefBrlyMUser = 0, const Sbecore::uint x2IxBrlyVLocale = 0, const std::string Par = "", const std::string Val = "");
	virtual void insertRst(ListBrlyAVControlPar& rst, bool transact = false);
	virtual void updateRec(BrlyAVControlPar* rec);
	virtual void updateRst(ListBrlyAVControlPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyAVControlPar** rec);
	virtual bool loadRefByCtlUsrPar(Sbecore::uint ixBrlyVControl, Sbecore::ubigint x1RefBrlyMUser, std::string Par, Sbecore::ubigint& ref);
	virtual bool loadValByCtlUsrPar(Sbecore::uint ixBrlyVControl, Sbecore::ubigint x1RefBrlyMUser, std::string Par, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyAVControlPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyAVControlPar: C++ wrapper for table TblBrlyAVControlPar (MySQL database)
	*/
class MyTblBrlyAVControlPar : public TblBrlyAVControlPar, public Sbecore::MyTable {

public:
	MyTblBrlyAVControlPar();
	~MyTblBrlyAVControlPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAVControlPar& rst);

	Sbecore::ubigint insertRec(BrlyAVControlPar* rec);
	void insertRst(ListBrlyAVControlPar& rst, bool transact = false);
	void updateRec(BrlyAVControlPar* rec);
	void updateRst(ListBrlyAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAVControlPar** rec);
	bool loadRefByCtlUsrPar(Sbecore::uint ixBrlyVControl, Sbecore::ubigint x1RefBrlyMUser, std::string Par, Sbecore::ubigint& ref);
	bool loadValByCtlUsrPar(Sbecore::uint ixBrlyVControl, Sbecore::ubigint x1RefBrlyMUser, std::string Par, std::string& Val);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyAVControlPar: C++ wrapper for table TblBrlyAVControlPar (PgSQL database)
	*/
class PgTblBrlyAVControlPar : public TblBrlyAVControlPar, public Sbecore::PgTable {

public:
	PgTblBrlyAVControlPar();
	~PgTblBrlyAVControlPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAVControlPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyAVControlPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAVControlPar** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyAVControlPar& rst);

	Sbecore::ubigint insertRec(BrlyAVControlPar* rec);
	void insertRst(ListBrlyAVControlPar& rst, bool transact = false);
	void updateRec(BrlyAVControlPar* rec);
	void updateRst(ListBrlyAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyAVControlPar** rec);
	bool loadRefByCtlUsrPar(Sbecore::uint ixBrlyVControl, Sbecore::ubigint x1RefBrlyMUser, std::string Par, Sbecore::ubigint& ref);
	bool loadValByCtlUsrPar(Sbecore::uint ixBrlyVControl, Sbecore::ubigint x1RefBrlyMUser, std::string Par, std::string& Val);
};
#endif

#endif
