/**
	* \file BrlyMRelay.h
	* database access for table TblBrlyMRelay (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMRELAY_H
#define BRLYMRELAY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecBrlyVMRelayDir TblBrlyMRelay::VecVDir

/**
	* BrlyMRelay: record of TblBrlyMRelay
	*/
class BrlyMRelay {

public:
	BrlyMRelay(const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::uint ixVDir = 0, const bool Connected = false, const Sbecore::usmallint Nhop = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint x1Start;
	Sbecore::uint x1Stop;
	Sbecore::ubigint refBrlyMConnection;
	Sbecore::uint ixVDir;
	bool Connected;
	Sbecore::usmallint Nhop;

public:
	bool operator==(const BrlyMRelay& comp);
	bool operator!=(const BrlyMRelay& comp);
};

/**
	* ListBrlyMRelay: recordset of TblBrlyMRelay
	*/
class ListBrlyMRelay {

public:
	ListBrlyMRelay();
	ListBrlyMRelay(const ListBrlyMRelay& src);
	~ListBrlyMRelay();

	void clear();
	unsigned int size() const;
	void append(BrlyMRelay* rec);

	BrlyMRelay* operator[](const Sbecore::uint ix);
	ListBrlyMRelay& operator=(const ListBrlyMRelay& src);
	bool operator==(const ListBrlyMRelay& comp);
	bool operator!=(const ListBrlyMRelay& comp);

public:
	std::vector<BrlyMRelay*> nodes;
};

/**
	* TblBrlyMRelay: C++ wrapper for table TblBrlyMRelay
	*/
class TblBrlyMRelay {

public:
	/**
		* VecVDir (full: VecBrlyVMRelayDir)
		*/
	class VecVDir {

	public:
		static const Sbecore::uint BWD = 1;
		static const Sbecore::uint FWD = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

public:
	TblBrlyMRelay();
	virtual ~TblBrlyMRelay();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMRelay** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMRelay& rst);

	virtual Sbecore::ubigint insertRec(BrlyMRelay* rec);
	Sbecore::ubigint insertNewRec(BrlyMRelay** rec = NULL, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::uint ixVDir = 0, const bool Connected = false, const Sbecore::usmallint Nhop = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyMRelay& rst, BrlyMRelay** rec = NULL, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const Sbecore::ubigint refBrlyMConnection = 0, const Sbecore::uint ixVDir = 0, const bool Connected = false, const Sbecore::usmallint Nhop = 0);
	virtual void insertRst(ListBrlyMRelay& rst, bool transact = false);
	virtual void updateRec(BrlyMRelay* rec);
	virtual void updateRst(ListBrlyMRelay& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMRelay** rec);
	virtual Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyMRelay& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMRelay& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMRelay: C++ wrapper for table TblBrlyMRelay (MySQL database)
	*/
class MyTblBrlyMRelay : public TblBrlyMRelay, public Sbecore::MyTable {

public:
	MyTblBrlyMRelay();
	~MyTblBrlyMRelay();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMRelay** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMRelay& rst);

	Sbecore::ubigint insertRec(BrlyMRelay* rec);
	void insertRst(ListBrlyMRelay& rst, bool transact = false);
	void updateRec(BrlyMRelay* rec);
	void updateRst(ListBrlyMRelay& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMRelay** rec);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyMRelay& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMRelay: C++ wrapper for table TblBrlyMRelay (PgSQL database)
	*/
class PgTblBrlyMRelay : public TblBrlyMRelay, public Sbecore::PgTable {

public:
	PgTblBrlyMRelay();
	~PgTblBrlyMRelay();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMRelay** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMRelay& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMRelay** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMRelay& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMRelay** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMRelay& rst);

	Sbecore::ubigint insertRec(BrlyMRelay* rec);
	void insertRst(ListBrlyMRelay& rst, bool transact = false);
	void updateRec(BrlyMRelay* rec);
	void updateRst(ListBrlyMRelay& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMRelay** rec);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refBrlyMConnection, const bool append, ListBrlyMRelay& rst);
};
#endif

#endif
