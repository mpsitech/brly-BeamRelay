/**
	* \file BrlyMLocation.h
	* database access for table TblBrlyMLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMLOCATION_H
#define BRLYMLOCATION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecBrlyVMLocationBasetype TblBrlyMLocation::VecVBasetype
#define VecBrlyWMLocationSubset TblBrlyMLocation::VecWSubset

/**
	* BrlyMLocation: record of TblBrlyMLocation
	*/
class BrlyMLocation {

public:
	BrlyMLocation(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::ubigint refBrlyMEquipment = 0, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0, const std::string tz = "", const double alpha = 0.0, const bool Calcdone = false);

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refBrlyMRegion;
	Sbecore::ubigint refBrlyMEquipment;
	std::string sref;
	std::string srefICAO;
	std::string Title;
	double alt;
	double theta;
	double phi;
	std::string tz;
	double alpha;
	bool Calcdone;

public:
	bool operator==(const BrlyMLocation& comp);
	bool operator!=(const BrlyMLocation& comp);
};

/**
	* ListBrlyMLocation: recordset of TblBrlyMLocation
	*/
class ListBrlyMLocation {

public:
	ListBrlyMLocation();
	ListBrlyMLocation(const ListBrlyMLocation& src);
	~ListBrlyMLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyMLocation* rec);

	BrlyMLocation* operator[](const Sbecore::uint ix);
	ListBrlyMLocation& operator=(const ListBrlyMLocation& src);
	bool operator==(const ListBrlyMLocation& comp);
	bool operator!=(const ListBrlyMLocation& comp);

public:
	std::vector<BrlyMLocation*> nodes;
};

/**
	* TblBrlyMLocation: C++ wrapper for table TblBrlyMLocation
	*/
class TblBrlyMLocation {

public:
	/**
		* VecVBasetype (full: VecBrlyVMLocationBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint APT = 1;
		static const Sbecore::uint GND = 2;
		static const Sbecore::uint ELV = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecWSubset (full: VecBrlyWMLocationSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSBRLYBMLOCATIONAPT = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);
	};

public:
	TblBrlyMLocation();
	virtual ~TblBrlyMLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyMLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyMLocation** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::ubigint refBrlyMEquipment = 0, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0, const std::string tz = "", const double alpha = 0.0, const bool Calcdone = false);
	Sbecore::ubigint appendNewRecToRst(ListBrlyMLocation& rst, BrlyMLocation** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refBrlyMRegion = 0, const Sbecore::ubigint refBrlyMEquipment = 0, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0, const std::string tz = "", const double alpha = 0.0, const bool Calcdone = false);
	virtual void insertRst(ListBrlyMLocation& rst, bool transact = false);
	virtual void updateRec(BrlyMLocation* rec);
	virtual void updateRst(ListBrlyMLocation& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMLocation** rec);
	virtual bool loadRecByEqp(Sbecore::ubigint refBrlyMEquipment, BrlyMLocation** rec);
	virtual bool loadRecBySrf(std::string sref, BrlyMLocation** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRst(const bool append, ListBrlyMLocation& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	virtual Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyMLocation& rst);
	virtual Sbecore::ubigint loadRstByTyp(Sbecore::uint ixVBasetype, const bool append, ListBrlyMLocation& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMLocation: C++ wrapper for table TblBrlyMLocation (MySQL database)
	*/
class MyTblBrlyMLocation : public TblBrlyMLocation, public Sbecore::MyTable {

public:
	MyTblBrlyMLocation();
	~MyTblBrlyMLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMLocation& rst);

	Sbecore::ubigint insertRec(BrlyMLocation* rec);
	void insertRst(ListBrlyMLocation& rst, bool transact = false);
	void updateRec(BrlyMLocation* rec);
	void updateRst(ListBrlyMLocation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMLocation** rec);
	bool loadRecByEqp(Sbecore::ubigint refBrlyMEquipment, BrlyMLocation** rec);
	bool loadRecBySrf(std::string sref, BrlyMLocation** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRst(const bool append, ListBrlyMLocation& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyMLocation& rst);
	Sbecore::ubigint loadRstByTyp(Sbecore::uint ixVBasetype, const bool append, ListBrlyMLocation& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMLocation: C++ wrapper for table TblBrlyMLocation (PgSQL database)
	*/
class PgTblBrlyMLocation : public TblBrlyMLocation, public Sbecore::PgTable {

public:
	PgTblBrlyMLocation();
	~PgTblBrlyMLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMLocation& rst);

	Sbecore::ubigint insertRec(BrlyMLocation* rec);
	void insertRst(ListBrlyMLocation& rst, bool transact = false);
	void updateRec(BrlyMLocation* rec);
	void updateRst(ListBrlyMLocation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMLocation** rec);
	bool loadRecByEqp(Sbecore::ubigint refBrlyMEquipment, BrlyMLocation** rec);
	bool loadRecBySrf(std::string sref, BrlyMLocation** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByReg(Sbecore::ubigint refBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRst(const bool append, ListBrlyMLocation& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByReg(Sbecore::ubigint refBrlyMRegion, const bool append, ListBrlyMLocation& rst);
	Sbecore::ubigint loadRstByTyp(Sbecore::uint ixVBasetype, const bool append, ListBrlyMLocation& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif
