/**
	* \file BrlyMConnection.h
	* database access for table TblBrlyMConnection (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMCONNECTION_H
#define BRLYMCONNECTION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecBrlyVMConnectionModel TblBrlyMConnection::VecVModel

/**
	* BrlyMConnection: record of TblBrlyMConnection
	*/
class BrlyMConnection {

public:
	BrlyMConnection(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refBrlyMFlight = 0, const Sbecore::ubigint corRefBrlyMLeg = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const Sbecore::uint ixVModel = 0, const Sbecore::ubigint refBrlyMTimetable = 0, const std::string srefsBrlyKEqptype = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refBrlyMFlight;
	Sbecore::ubigint corRefBrlyMLeg;
	Sbecore::uint start;
	Sbecore::uint stop;
	Sbecore::uint ixVModel;
	Sbecore::ubigint refBrlyMTimetable;
	std::string srefsBrlyKEqptype;

public:
	bool operator==(const BrlyMConnection& comp);
	bool operator!=(const BrlyMConnection& comp);
};

/**
	* ListBrlyMConnection: recordset of TblBrlyMConnection
	*/
class ListBrlyMConnection {

public:
	ListBrlyMConnection();
	ListBrlyMConnection(const ListBrlyMConnection& src);
	~ListBrlyMConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyMConnection* rec);

	BrlyMConnection* operator[](const Sbecore::uint ix);
	ListBrlyMConnection& operator=(const ListBrlyMConnection& src);
	bool operator==(const ListBrlyMConnection& comp);
	bool operator!=(const ListBrlyMConnection& comp);

public:
	std::vector<BrlyMConnection*> nodes;
};

/**
	* TblBrlyMConnection: C++ wrapper for table TblBrlyMConnection
	*/
class TblBrlyMConnection {

public:
	/**
		* VecVModel (full: VecBrlyVMConnectionModel)
		*/
	class VecVModel {

	public:
		static const Sbecore::uint SPL = 1;
		static const Sbecore::uint EXT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblBrlyMConnection();
	virtual ~TblBrlyMConnection();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMConnection** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMConnection& rst);

	virtual Sbecore::ubigint insertRec(BrlyMConnection* rec);
	Sbecore::ubigint insertNewRec(BrlyMConnection** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refBrlyMFlight = 0, const Sbecore::ubigint corRefBrlyMLeg = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const Sbecore::uint ixVModel = 0, const Sbecore::ubigint refBrlyMTimetable = 0, const std::string srefsBrlyKEqptype = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyMConnection& rst, BrlyMConnection** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refBrlyMFlight = 0, const Sbecore::ubigint corRefBrlyMLeg = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const Sbecore::uint ixVModel = 0, const Sbecore::ubigint refBrlyMTimetable = 0, const std::string srefsBrlyKEqptype = "");
	virtual void insertRst(ListBrlyMConnection& rst, bool transact = false);
	virtual void updateRec(BrlyMConnection* rec);
	virtual void updateRst(ListBrlyMConnection& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMConnection** rec);
	virtual Sbecore::ubigint loadRefsByLeg(const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByLeg(const bool append, ListBrlyMConnection& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMConnection& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMConnection: C++ wrapper for table TblBrlyMConnection (MySQL database)
	*/
class MyTblBrlyMConnection : public TblBrlyMConnection, public Sbecore::MyTable {

public:
	MyTblBrlyMConnection();
	~MyTblBrlyMConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMConnection& rst);

	Sbecore::ubigint insertRec(BrlyMConnection* rec);
	void insertRst(ListBrlyMConnection& rst, bool transact = false);
	void updateRec(BrlyMConnection* rec);
	void updateRst(ListBrlyMConnection& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMConnection** rec);
	Sbecore::ubigint loadRefsByLeg(const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLeg(const bool append, ListBrlyMConnection& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMConnection: C++ wrapper for table TblBrlyMConnection (PgSQL database)
	*/
class PgTblBrlyMConnection : public TblBrlyMConnection, public Sbecore::PgTable {

public:
	PgTblBrlyMConnection();
	~PgTblBrlyMConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMConnection** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMConnection& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMConnection** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMConnection& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMConnection** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMConnection& rst);

	Sbecore::ubigint insertRec(BrlyMConnection* rec);
	void insertRst(ListBrlyMConnection& rst, bool transact = false);
	void updateRec(BrlyMConnection* rec);
	void updateRst(ListBrlyMConnection& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMConnection** rec);
	Sbecore::ubigint loadRefsByLeg(const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLeg(const bool append, ListBrlyMConnection& rst);
};
#endif

#endif
