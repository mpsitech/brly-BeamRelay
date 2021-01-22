/**
	* \file BrlyRMFlightMFlight.h
	* database access for table TblBrlyRMFlightMFlight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYRMFLIGHTMFLIGHT_H
#define BRLYRMFLIGHTMFLIGHT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyRMFlightMFlight: record of TblBrlyRMFlightMFlight
	*/
class BrlyRMFlightMFlight {

public:
	BrlyRMFlightMFlight(const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const Sbecore::uint x1VisStop = 0, const Sbecore::ubigint dstRefBrlyMFlight = 0, const Sbecore::ubigint orgRefBrlyMFlight = 0, const Sbecore::uint xVisStart = 0, const Sbecore::uint xVisStop = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint x1VisStart;
	Sbecore::uint x1VisStop;
	Sbecore::ubigint dstRefBrlyMFlight;
	Sbecore::ubigint orgRefBrlyMFlight;
	Sbecore::uint xVisStart;
	Sbecore::uint xVisStop;

public:
	bool operator==(const BrlyRMFlightMFlight& comp);
	bool operator!=(const BrlyRMFlightMFlight& comp);
};

/**
	* ListBrlyRMFlightMFlight: recordset of TblBrlyRMFlightMFlight
	*/
class ListBrlyRMFlightMFlight {

public:
	ListBrlyRMFlightMFlight();
	ListBrlyRMFlightMFlight(const ListBrlyRMFlightMFlight& src);
	~ListBrlyRMFlightMFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyRMFlightMFlight* rec);

	BrlyRMFlightMFlight* operator[](const Sbecore::uint ix);
	ListBrlyRMFlightMFlight& operator=(const ListBrlyRMFlightMFlight& src);
	bool operator==(const ListBrlyRMFlightMFlight& comp);
	bool operator!=(const ListBrlyRMFlightMFlight& comp);

public:
	std::vector<BrlyRMFlightMFlight*> nodes;
};

/**
	* TblBrlyRMFlightMFlight: C++ wrapper for table TblBrlyRMFlightMFlight
	*/
class TblBrlyRMFlightMFlight {

public:

public:
	TblBrlyRMFlightMFlight();
	virtual ~TblBrlyRMFlightMFlight();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyRMFlightMFlight** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMFlightMFlight& rst);

	virtual Sbecore::ubigint insertRec(BrlyRMFlightMFlight* rec);
	Sbecore::ubigint insertNewRec(BrlyRMFlightMFlight** rec = NULL, const Sbecore::uint x1VisStart = 0, const Sbecore::uint x1VisStop = 0, const Sbecore::ubigint dstRefBrlyMFlight = 0, const Sbecore::ubigint orgRefBrlyMFlight = 0, const Sbecore::uint xVisStart = 0, const Sbecore::uint xVisStop = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyRMFlightMFlight& rst, BrlyRMFlightMFlight** rec = NULL, const Sbecore::uint x1VisStart = 0, const Sbecore::uint x1VisStop = 0, const Sbecore::ubigint dstRefBrlyMFlight = 0, const Sbecore::ubigint orgRefBrlyMFlight = 0, const Sbecore::uint xVisStart = 0, const Sbecore::uint xVisStop = 0);
	virtual void insertRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	virtual void updateRec(BrlyRMFlightMFlight* rec);
	virtual void updateRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyRMFlightMFlight** rec);
	virtual Sbecore::ubigint loadRstByDfl(Sbecore::ubigint dstRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
	virtual Sbecore::ubigint loadRstByOfl(Sbecore::ubigint orgRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyRMFlightMFlight& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyRMFlightMFlight: C++ wrapper for table TblBrlyRMFlightMFlight (MySQL database)
	*/
class MyTblBrlyRMFlightMFlight : public TblBrlyRMFlightMFlight, public Sbecore::MyTable {

public:
	MyTblBrlyRMFlightMFlight();
	~MyTblBrlyRMFlightMFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMFlightMFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMFlightMFlight& rst);

	Sbecore::ubigint insertRec(BrlyRMFlightMFlight* rec);
	void insertRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	void updateRec(BrlyRMFlightMFlight* rec);
	void updateRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMFlightMFlight** rec);
	Sbecore::ubigint loadRstByDfl(Sbecore::ubigint dstRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
	Sbecore::ubigint loadRstByOfl(Sbecore::ubigint orgRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyRMFlightMFlight: C++ wrapper for table TblBrlyRMFlightMFlight (PgSQL database)
	*/
class PgTblBrlyRMFlightMFlight : public TblBrlyRMFlightMFlight, public Sbecore::PgTable {

public:
	PgTblBrlyRMFlightMFlight();
	~PgTblBrlyRMFlightMFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMFlightMFlight** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyRMFlightMFlight& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMFlightMFlight** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMFlightMFlight& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyRMFlightMFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyRMFlightMFlight& rst);

	Sbecore::ubigint insertRec(BrlyRMFlightMFlight* rec);
	void insertRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	void updateRec(BrlyRMFlightMFlight* rec);
	void updateRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyRMFlightMFlight** rec);
	Sbecore::ubigint loadRstByDfl(Sbecore::ubigint dstRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
	Sbecore::ubigint loadRstByOfl(Sbecore::ubigint orgRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
};
#endif

#endif
