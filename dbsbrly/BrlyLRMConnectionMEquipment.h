/**
	* \file BrlyLRMConnectionMEquipment.h
	* database access for table TblBrlyLRMConnectionMEquipment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYLRMCONNECTIONMEQUIPMENT_H
#define BRLYLRMCONNECTIONMEQUIPMENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyLRMConnectionMEquipment: record of TblBrlyLRMConnectionMEquipment
	*/
class BrlyLRMConnectionMEquipment {

public:
	BrlyLRMConnectionMEquipment(const Sbecore::ubigint ref = 0, const Sbecore::uint conIxBrlyVLat = 0, const Sbecore::ubigint conRefBrlyMConnection = 0, const Sbecore::uint conNum = 0, const Sbecore::ubigint refBrlyMEquipment = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint conIxBrlyVLat;
	Sbecore::ubigint conRefBrlyMConnection;
	Sbecore::uint conNum;
	Sbecore::ubigint refBrlyMEquipment;

public:
	bool operator==(const BrlyLRMConnectionMEquipment& comp);
	bool operator!=(const BrlyLRMConnectionMEquipment& comp);
};

/**
	* ListBrlyLRMConnectionMEquipment: recordset of TblBrlyLRMConnectionMEquipment
	*/
class ListBrlyLRMConnectionMEquipment {

public:
	ListBrlyLRMConnectionMEquipment();
	ListBrlyLRMConnectionMEquipment(const ListBrlyLRMConnectionMEquipment& src);
	~ListBrlyLRMConnectionMEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyLRMConnectionMEquipment* rec);

	BrlyLRMConnectionMEquipment* operator[](const Sbecore::uint ix);
	ListBrlyLRMConnectionMEquipment& operator=(const ListBrlyLRMConnectionMEquipment& src);
	bool operator==(const ListBrlyLRMConnectionMEquipment& comp);
	bool operator!=(const ListBrlyLRMConnectionMEquipment& comp);

public:
	std::vector<BrlyLRMConnectionMEquipment*> nodes;
};

/**
	* TblBrlyLRMConnectionMEquipment: C++ wrapper for table TblBrlyLRMConnectionMEquipment
	*/
class TblBrlyLRMConnectionMEquipment {

public:

public:
	TblBrlyLRMConnectionMEquipment();
	virtual ~TblBrlyLRMConnectionMEquipment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyLRMConnectionMEquipment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyLRMConnectionMEquipment& rst);

	virtual Sbecore::ubigint insertRec(BrlyLRMConnectionMEquipment* rec);
	Sbecore::ubigint insertNewRec(BrlyLRMConnectionMEquipment** rec = NULL, const Sbecore::uint conIxBrlyVLat = 0, const Sbecore::ubigint conRefBrlyMConnection = 0, const Sbecore::uint conNum = 0, const Sbecore::ubigint refBrlyMEquipment = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyLRMConnectionMEquipment& rst, BrlyLRMConnectionMEquipment** rec = NULL, const Sbecore::uint conIxBrlyVLat = 0, const Sbecore::ubigint conRefBrlyMConnection = 0, const Sbecore::uint conNum = 0, const Sbecore::ubigint refBrlyMEquipment = 0);
	virtual void insertRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	virtual void updateRec(BrlyLRMConnectionMEquipment* rec);
	virtual void updateRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyLRMConnectionMEquipment** rec);
	virtual Sbecore::ubigint loadConsByEqp(Sbecore::ubigint refBrlyMEquipment, const bool append, std::vector<Sbecore::ubigint>& conRefBrlyMConnections);
	virtual Sbecore::ubigint loadEqpsByCon(Sbecore::ubigint conRefBrlyMConnection, const bool append, std::vector<Sbecore::ubigint>& refBrlyMEquipments);
	virtual Sbecore::ubigint loadRefsByConLat(Sbecore::ubigint conRefBrlyMConnection, Sbecore::uint conIxBrlyVLat, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCon(Sbecore::ubigint conRefBrlyMConnection, const bool append, ListBrlyLRMConnectionMEquipment& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyLRMConnectionMEquipment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyLRMConnectionMEquipment: C++ wrapper for table TblBrlyLRMConnectionMEquipment (MySQL database)
	*/
class MyTblBrlyLRMConnectionMEquipment : public TblBrlyLRMConnectionMEquipment, public Sbecore::MyTable {

public:
	MyTblBrlyLRMConnectionMEquipment();
	~MyTblBrlyLRMConnectionMEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyLRMConnectionMEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyLRMConnectionMEquipment& rst);

	Sbecore::ubigint insertRec(BrlyLRMConnectionMEquipment* rec);
	void insertRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	void updateRec(BrlyLRMConnectionMEquipment* rec);
	void updateRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyLRMConnectionMEquipment** rec);
	Sbecore::ubigint loadConsByEqp(Sbecore::ubigint refBrlyMEquipment, const bool append, std::vector<Sbecore::ubigint>& conRefBrlyMConnections);
	Sbecore::ubigint loadEqpsByCon(Sbecore::ubigint conRefBrlyMConnection, const bool append, std::vector<Sbecore::ubigint>& refBrlyMEquipments);
	Sbecore::ubigint loadRefsByConLat(Sbecore::ubigint conRefBrlyMConnection, Sbecore::uint conIxBrlyVLat, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint conRefBrlyMConnection, const bool append, ListBrlyLRMConnectionMEquipment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyLRMConnectionMEquipment: C++ wrapper for table TblBrlyLRMConnectionMEquipment (PgSQL database)
	*/
class PgTblBrlyLRMConnectionMEquipment : public TblBrlyLRMConnectionMEquipment, public Sbecore::PgTable {

public:
	PgTblBrlyLRMConnectionMEquipment();
	~PgTblBrlyLRMConnectionMEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyLRMConnectionMEquipment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyLRMConnectionMEquipment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyLRMConnectionMEquipment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyLRMConnectionMEquipment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyLRMConnectionMEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyLRMConnectionMEquipment& rst);

	Sbecore::ubigint insertRec(BrlyLRMConnectionMEquipment* rec);
	void insertRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	void updateRec(BrlyLRMConnectionMEquipment* rec);
	void updateRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyLRMConnectionMEquipment** rec);
	Sbecore::ubigint loadConsByEqp(Sbecore::ubigint refBrlyMEquipment, const bool append, std::vector<Sbecore::ubigint>& conRefBrlyMConnections);
	Sbecore::ubigint loadEqpsByCon(Sbecore::ubigint conRefBrlyMConnection, const bool append, std::vector<Sbecore::ubigint>& refBrlyMEquipments);
	Sbecore::ubigint loadRefsByConLat(Sbecore::ubigint conRefBrlyMConnection, Sbecore::uint conIxBrlyVLat, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint conRefBrlyMConnection, const bool append, ListBrlyLRMConnectionMEquipment& rst);
};
#endif

#endif
