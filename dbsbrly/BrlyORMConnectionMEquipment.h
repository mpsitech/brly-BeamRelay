/**
	* \file BrlyORMConnectionMEquipment.h
	* database access for table TblBrlyORMConnectionMEquipment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYORMCONNECTIONMEQUIPMENT_H
#define BRLYORMCONNECTIONMEQUIPMENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyORMConnectionMEquipment: record of TblBrlyORMConnectionMEquipment
	*/
class BrlyORMConnectionMEquipment {

public:
	BrlyORMConnectionMEquipment(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixBrlyVOolop = 0, const Sbecore::ubigint pr1RefLR = 0, const Sbecore::ubigint pr2RefLR = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMConnection;
	Sbecore::uint x1Start;
	Sbecore::uint ixBrlyVOolop;
	Sbecore::ubigint pr1RefLR;
	Sbecore::ubigint pr2RefLR;

public:
	bool operator==(const BrlyORMConnectionMEquipment& comp);
	bool operator!=(const BrlyORMConnectionMEquipment& comp);
};

/**
	* ListBrlyORMConnectionMEquipment: recordset of TblBrlyORMConnectionMEquipment
	*/
class ListBrlyORMConnectionMEquipment {

public:
	ListBrlyORMConnectionMEquipment();
	ListBrlyORMConnectionMEquipment(const ListBrlyORMConnectionMEquipment& src);
	~ListBrlyORMConnectionMEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyORMConnectionMEquipment* rec);

	BrlyORMConnectionMEquipment* operator[](const Sbecore::uint ix);
	ListBrlyORMConnectionMEquipment& operator=(const ListBrlyORMConnectionMEquipment& src);
	bool operator==(const ListBrlyORMConnectionMEquipment& comp);
	bool operator!=(const ListBrlyORMConnectionMEquipment& comp);

public:
	std::vector<BrlyORMConnectionMEquipment*> nodes;
};

/**
	* TblBrlyORMConnectionMEquipment: C++ wrapper for table TblBrlyORMConnectionMEquipment
	*/
class TblBrlyORMConnectionMEquipment {

public:

public:
	TblBrlyORMConnectionMEquipment();
	virtual ~TblBrlyORMConnectionMEquipment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyORMConnectionMEquipment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyORMConnectionMEquipment& rst);

	virtual Sbecore::ubigint insertRec(BrlyORMConnectionMEquipment* rec);
	Sbecore::ubigint insertNewRec(BrlyORMConnectionMEquipment** rec = NULL, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixBrlyVOolop = 0, const Sbecore::ubigint pr1RefLR = 0, const Sbecore::ubigint pr2RefLR = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyORMConnectionMEquipment& rst, BrlyORMConnectionMEquipment** rec = NULL, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixBrlyVOolop = 0, const Sbecore::ubigint pr1RefLR = 0, const Sbecore::ubigint pr2RefLR = 0);
	virtual void insertRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	virtual void updateRec(BrlyORMConnectionMEquipment* rec);
	virtual void updateRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyORMConnectionMEquipment** rec);
	virtual bool loadRecByP1lP2lLop(Sbecore::ubigint pr1RefLR, Sbecore::ubigint pr2RefLR, Sbecore::uint ixBrlyVOolop, BrlyORMConnectionMEquipment** rec);
	virtual Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyORMConnectionMEquipment& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyORMConnectionMEquipment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyORMConnectionMEquipment: C++ wrapper for table TblBrlyORMConnectionMEquipment (MySQL database)
	*/
class MyTblBrlyORMConnectionMEquipment : public TblBrlyORMConnectionMEquipment, public Sbecore::MyTable {

public:
	MyTblBrlyORMConnectionMEquipment();
	~MyTblBrlyORMConnectionMEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyORMConnectionMEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyORMConnectionMEquipment& rst);

	Sbecore::ubigint insertRec(BrlyORMConnectionMEquipment* rec);
	void insertRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	void updateRec(BrlyORMConnectionMEquipment* rec);
	void updateRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyORMConnectionMEquipment** rec);
	bool loadRecByP1lP2lLop(Sbecore::ubigint pr1RefLR, Sbecore::ubigint pr2RefLR, Sbecore::uint ixBrlyVOolop, BrlyORMConnectionMEquipment** rec);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyORMConnectionMEquipment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyORMConnectionMEquipment: C++ wrapper for table TblBrlyORMConnectionMEquipment (PgSQL database)
	*/
class PgTblBrlyORMConnectionMEquipment : public TblBrlyORMConnectionMEquipment, public Sbecore::PgTable {

public:
	PgTblBrlyORMConnectionMEquipment();
	~PgTblBrlyORMConnectionMEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyORMConnectionMEquipment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyORMConnectionMEquipment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyORMConnectionMEquipment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyORMConnectionMEquipment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyORMConnectionMEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyORMConnectionMEquipment& rst);

	Sbecore::ubigint insertRec(BrlyORMConnectionMEquipment* rec);
	void insertRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	void updateRec(BrlyORMConnectionMEquipment* rec);
	void updateRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyORMConnectionMEquipment** rec);
	bool loadRecByP1lP2lLop(Sbecore::ubigint pr1RefLR, Sbecore::ubigint pr2RefLR, Sbecore::uint ixBrlyVOolop, BrlyORMConnectionMEquipment** rec);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyORMConnectionMEquipment& rst);
};
#endif

#endif
