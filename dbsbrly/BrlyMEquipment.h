/**
	* \file BrlyMEquipment.h
	* database access for table TblBrlyMEquipment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMEQUIPMENT_H
#define BRLYMEQUIPMENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecBrlyVMEquipmentHkTbl TblBrlyMEquipment::VecVHkTbl
#define VecBrlyWMEquipmentSubset TblBrlyMEquipment::VecWSubset

/**
	* BrlyMEquipment: record of TblBrlyMEquipment
	*/
class BrlyMEquipment {

public:
	BrlyMEquipment(const Sbecore::ubigint ref = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::ubigint refBrlyMOperator = 0, const Sbecore::ubigint refBrlyMPlntype = 0, const std::string srefBrlyKEqptype = "", const bool Fiber = false);

public:
	Sbecore::ubigint ref;
	Sbecore::uint hkIxVTbl;
	Sbecore::ubigint hkUref;
	Sbecore::ubigint refBrlyMOperator;
	Sbecore::ubigint refBrlyMPlntype;
	std::string srefBrlyKEqptype;
	bool Fiber;

public:
	bool operator==(const BrlyMEquipment& comp);
	bool operator!=(const BrlyMEquipment& comp);
};

/**
	* ListBrlyMEquipment: recordset of TblBrlyMEquipment
	*/
class ListBrlyMEquipment {

public:
	ListBrlyMEquipment();
	ListBrlyMEquipment(const ListBrlyMEquipment& src);
	~ListBrlyMEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyMEquipment* rec);

	BrlyMEquipment* operator[](const Sbecore::uint ix);
	ListBrlyMEquipment& operator=(const ListBrlyMEquipment& src);
	bool operator==(const ListBrlyMEquipment& comp);
	bool operator!=(const ListBrlyMEquipment& comp);

public:
	std::vector<BrlyMEquipment*> nodes;
};

/**
	* TblBrlyMEquipment: C++ wrapper for table TblBrlyMEquipment
	*/
class TblBrlyMEquipment {

public:
	/**
		* VecVHkTbl (full: VecBrlyVMEquipmentHkTbl)
		*/
	class VecVHkTbl {

	public:
		static const Sbecore::uint FLT = 1;
		static const Sbecore::uint LOC = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWSubset (full: VecBrlyWMEquipmentSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSBRLYBMEQUIPMENTPLN = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);
	};

public:
	TblBrlyMEquipment();
	virtual ~TblBrlyMEquipment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMEquipment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMEquipment& rst);

	virtual Sbecore::ubigint insertRec(BrlyMEquipment* rec);
	Sbecore::ubigint insertNewRec(BrlyMEquipment** rec = NULL, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::ubigint refBrlyMOperator = 0, const Sbecore::ubigint refBrlyMPlntype = 0, const std::string srefBrlyKEqptype = "", const bool Fiber = false);
	Sbecore::ubigint appendNewRecToRst(ListBrlyMEquipment& rst, BrlyMEquipment** rec = NULL, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::ubigint refBrlyMOperator = 0, const Sbecore::ubigint refBrlyMPlntype = 0, const std::string srefBrlyKEqptype = "", const bool Fiber = false);
	virtual void insertRst(ListBrlyMEquipment& rst, bool transact = false);
	virtual void updateRec(BrlyMEquipment* rec);
	virtual void updateRst(ListBrlyMEquipment& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMEquipment** rec);
	virtual bool loadRecByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, BrlyMEquipment** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMEquipment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMEquipment: C++ wrapper for table TblBrlyMEquipment (MySQL database)
	*/
class MyTblBrlyMEquipment : public TblBrlyMEquipment, public Sbecore::MyTable {

public:
	MyTblBrlyMEquipment();
	~MyTblBrlyMEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMEquipment& rst);

	Sbecore::ubigint insertRec(BrlyMEquipment* rec);
	void insertRst(ListBrlyMEquipment& rst, bool transact = false);
	void updateRec(BrlyMEquipment* rec);
	void updateRst(ListBrlyMEquipment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMEquipment** rec);
	bool loadRecByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, BrlyMEquipment** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMEquipment: C++ wrapper for table TblBrlyMEquipment (PgSQL database)
	*/
class PgTblBrlyMEquipment : public TblBrlyMEquipment, public Sbecore::PgTable {

public:
	PgTblBrlyMEquipment();
	~PgTblBrlyMEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMEquipment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMEquipment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMEquipment** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMEquipment& rst);

	Sbecore::ubigint insertRec(BrlyMEquipment* rec);
	void insertRst(ListBrlyMEquipment& rst, bool transact = false);
	void updateRec(BrlyMEquipment* rec);
	void updateRst(ListBrlyMEquipment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMEquipment** rec);
	bool loadRecByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, BrlyMEquipment** rec);
};
#endif

#endif
