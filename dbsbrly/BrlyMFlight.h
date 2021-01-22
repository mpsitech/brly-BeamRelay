/**
	* \file BrlyMFlight.h
	* database access for table TblBrlyMFlight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMFLIGHT_H
#define BRLYMFLIGHT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyMFlight: record of TblBrlyMFlight
	*/
class BrlyMFlight {

public:
	BrlyMFlight(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMTimetable = 0, const Sbecore::ubigint refBrlyMEquipment = 0, const Sbecore::ubigint refBrlyMFaflight = 0, const Sbecore::ubigint refBrlyMLeg = 0, const std::string sref = "", const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const Sbecore::uint xStart = 0, const Sbecore::uint xStop = 0, const bool Calcdone = false, const bool Segdone = false);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMTimetable;
	Sbecore::ubigint refBrlyMEquipment;
	Sbecore::ubigint refBrlyMFaflight;
	Sbecore::ubigint refBrlyMLeg;
	std::string sref;
	Sbecore::uint start;
	Sbecore::uint stop;
	Sbecore::uint xStart;
	Sbecore::uint xStop;
	bool Calcdone;
	bool Segdone;

public:
	bool operator==(const BrlyMFlight& comp);
	bool operator!=(const BrlyMFlight& comp);
};

/**
	* ListBrlyMFlight: recordset of TblBrlyMFlight
	*/
class ListBrlyMFlight {

public:
	ListBrlyMFlight();
	ListBrlyMFlight(const ListBrlyMFlight& src);
	~ListBrlyMFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyMFlight* rec);

	BrlyMFlight* operator[](const Sbecore::uint ix);
	ListBrlyMFlight& operator=(const ListBrlyMFlight& src);
	bool operator==(const ListBrlyMFlight& comp);
	bool operator!=(const ListBrlyMFlight& comp);

public:
	std::vector<BrlyMFlight*> nodes;
};

/**
	* TblBrlyMFlight: C++ wrapper for table TblBrlyMFlight
	*/
class TblBrlyMFlight {

public:

public:
	TblBrlyMFlight();
	virtual ~TblBrlyMFlight();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMFlight** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMFlight& rst);

	virtual Sbecore::ubigint insertRec(BrlyMFlight* rec);
	Sbecore::ubigint insertNewRec(BrlyMFlight** rec = NULL, const Sbecore::ubigint refBrlyMTimetable = 0, const Sbecore::ubigint refBrlyMEquipment = 0, const Sbecore::ubigint refBrlyMFaflight = 0, const Sbecore::ubigint refBrlyMLeg = 0, const std::string sref = "", const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const Sbecore::uint xStart = 0, const Sbecore::uint xStop = 0, const bool Calcdone = false, const bool Segdone = false);
	Sbecore::ubigint appendNewRecToRst(ListBrlyMFlight& rst, BrlyMFlight** rec = NULL, const Sbecore::ubigint refBrlyMTimetable = 0, const Sbecore::ubigint refBrlyMEquipment = 0, const Sbecore::ubigint refBrlyMFaflight = 0, const Sbecore::ubigint refBrlyMLeg = 0, const std::string sref = "", const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const Sbecore::uint xStart = 0, const Sbecore::uint xStop = 0, const bool Calcdone = false, const bool Segdone = false);
	virtual void insertRst(ListBrlyMFlight& rst, bool transact = false);
	virtual void updateRec(BrlyMFlight* rec);
	virtual void updateRst(ListBrlyMFlight& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMFlight** rec);
	virtual bool loadRecByEqp(Sbecore::ubigint refBrlyMEquipment, BrlyMFlight** rec);
	virtual bool loadRecByFaf(Sbecore::ubigint refBrlyMFaflight, BrlyMFlight** rec);
	virtual Sbecore::ubigint loadRefsByLeg(Sbecore::ubigint refBrlyMLeg, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByLeg(Sbecore::ubigint refBrlyMLeg, const bool append, ListBrlyMFlight& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMFlight& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMFlight: C++ wrapper for table TblBrlyMFlight (MySQL database)
	*/
class MyTblBrlyMFlight : public TblBrlyMFlight, public Sbecore::MyTable {

public:
	MyTblBrlyMFlight();
	~MyTblBrlyMFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMFlight& rst);

	Sbecore::ubigint insertRec(BrlyMFlight* rec);
	void insertRst(ListBrlyMFlight& rst, bool transact = false);
	void updateRec(BrlyMFlight* rec);
	void updateRst(ListBrlyMFlight& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMFlight** rec);
	bool loadRecByEqp(Sbecore::ubigint refBrlyMEquipment, BrlyMFlight** rec);
	bool loadRecByFaf(Sbecore::ubigint refBrlyMFaflight, BrlyMFlight** rec);
	Sbecore::ubigint loadRefsByLeg(Sbecore::ubigint refBrlyMLeg, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLeg(Sbecore::ubigint refBrlyMLeg, const bool append, ListBrlyMFlight& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMFlight: C++ wrapper for table TblBrlyMFlight (PgSQL database)
	*/
class PgTblBrlyMFlight : public TblBrlyMFlight, public Sbecore::PgTable {

public:
	PgTblBrlyMFlight();
	~PgTblBrlyMFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMFlight** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMFlight& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMFlight** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMFlight& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMFlight& rst);

	Sbecore::ubigint insertRec(BrlyMFlight* rec);
	void insertRst(ListBrlyMFlight& rst, bool transact = false);
	void updateRec(BrlyMFlight* rec);
	void updateRst(ListBrlyMFlight& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMFlight** rec);
	bool loadRecByEqp(Sbecore::ubigint refBrlyMEquipment, BrlyMFlight** rec);
	bool loadRecByFaf(Sbecore::ubigint refBrlyMFaflight, BrlyMFlight** rec);
	Sbecore::ubigint loadRefsByLeg(Sbecore::ubigint refBrlyMLeg, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLeg(Sbecore::ubigint refBrlyMLeg, const bool append, ListBrlyMFlight& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
