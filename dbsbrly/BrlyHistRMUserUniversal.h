/**
	* \file BrlyHistRMUserUniversal.h
	* database access for table TblBrlyHistRMUserUniversal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYHISTRMUSERUNIVERSAL_H
#define BRLYHISTRMUSERUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyHistRMUserUniversal: record of TblBrlyHistRMUserUniversal
	*/
class BrlyHistRMUserUniversal {

public:
	BrlyHistRMUserUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint unvIxBrlyVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixBrlyVCard = 0, const Sbecore::uint ixBrlyVPreset = 0, const Sbecore::uint preIxBrlyVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMUser;
	Sbecore::uint unvIxBrlyVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixBrlyVCard;
	Sbecore::uint ixBrlyVPreset;
	Sbecore::uint preIxBrlyVMaintable;
	Sbecore::ubigint preUref;
	Sbecore::uint start;

public:
	bool operator==(const BrlyHistRMUserUniversal& comp);
	bool operator!=(const BrlyHistRMUserUniversal& comp);
};

/**
	* ListBrlyHistRMUserUniversal: recordset of TblBrlyHistRMUserUniversal
	*/
class ListBrlyHistRMUserUniversal {

public:
	ListBrlyHistRMUserUniversal();
	ListBrlyHistRMUserUniversal(const ListBrlyHistRMUserUniversal& src);
	~ListBrlyHistRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(BrlyHistRMUserUniversal* rec);

	BrlyHistRMUserUniversal* operator[](const Sbecore::uint ix);
	ListBrlyHistRMUserUniversal& operator=(const ListBrlyHistRMUserUniversal& src);
	bool operator==(const ListBrlyHistRMUserUniversal& comp);
	bool operator!=(const ListBrlyHistRMUserUniversal& comp);

public:
	std::vector<BrlyHistRMUserUniversal*> nodes;
};

/**
	* TblBrlyHistRMUserUniversal: C++ wrapper for table TblBrlyHistRMUserUniversal
	*/
class TblBrlyHistRMUserUniversal {

public:

public:
	TblBrlyHistRMUserUniversal();
	virtual ~TblBrlyHistRMUserUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyHistRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyHistRMUserUniversal& rst);

	virtual Sbecore::ubigint insertRec(BrlyHistRMUserUniversal* rec);
	Sbecore::ubigint insertNewRec(BrlyHistRMUserUniversal** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint unvIxBrlyVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixBrlyVCard = 0, const Sbecore::uint ixBrlyVPreset = 0, const Sbecore::uint preIxBrlyVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyHistRMUserUniversal& rst, BrlyHistRMUserUniversal** rec = NULL, const Sbecore::ubigint refBrlyMUser = 0, const Sbecore::uint unvIxBrlyVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixBrlyVCard = 0, const Sbecore::uint ixBrlyVPreset = 0, const Sbecore::uint preIxBrlyVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);
	virtual void insertRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(BrlyHistRMUserUniversal* rec);
	virtual void updateRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyHistRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refBrlyMUser, Sbecore::uint unvIxBrlyVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixBrlyVCard, BrlyHistRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refBrlyMUser, Sbecore::uint unvIxBrlyVMaintable, Sbecore::uint ixBrlyVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	virtual Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refBrlyMUser, Sbecore::uint ixBrlyVCard, const bool append, ListBrlyHistRMUserUniversal& rst);
	virtual bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyHistRMUserUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyHistRMUserUniversal: C++ wrapper for table TblBrlyHistRMUserUniversal (MySQL database)
	*/
class MyTblBrlyHistRMUserUniversal : public TblBrlyHistRMUserUniversal, public Sbecore::MyTable {

public:
	MyTblBrlyHistRMUserUniversal();
	~MyTblBrlyHistRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(BrlyHistRMUserUniversal* rec);
	void insertRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	void updateRec(BrlyHistRMUserUniversal* rec);
	void updateRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refBrlyMUser, Sbecore::uint unvIxBrlyVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixBrlyVCard, BrlyHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refBrlyMUser, Sbecore::uint unvIxBrlyVMaintable, Sbecore::uint ixBrlyVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refBrlyMUser, Sbecore::uint ixBrlyVCard, const bool append, ListBrlyHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyHistRMUserUniversal: C++ wrapper for table TblBrlyHistRMUserUniversal (PgSQL database)
	*/
class PgTblBrlyHistRMUserUniversal : public TblBrlyHistRMUserUniversal, public Sbecore::PgTable {

public:
	PgTblBrlyHistRMUserUniversal();
	~PgTblBrlyHistRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyHistRMUserUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyHistRMUserUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyHistRMUserUniversal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(BrlyHistRMUserUniversal* rec);
	void insertRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	void updateRec(BrlyHistRMUserUniversal* rec);
	void updateRst(ListBrlyHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refBrlyMUser, Sbecore::uint unvIxBrlyVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixBrlyVCard, BrlyHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refBrlyMUser, Sbecore::uint unvIxBrlyVMaintable, Sbecore::uint ixBrlyVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refBrlyMUser, Sbecore::uint ixBrlyVCard, const bool append, ListBrlyHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#endif
