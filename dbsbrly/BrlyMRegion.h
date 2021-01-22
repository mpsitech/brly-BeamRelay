/**
	* \file BrlyMRegion.h
	* database access for table TblBrlyMRegion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMREGION_H
#define BRLYMREGION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecBrlyVMRegionDst TblBrlyMRegion::VecVDst
#define VecBrlyWMRegionSubset TblBrlyMRegion::VecWSubset

/**
	* BrlyMRegion: record of TblBrlyMRegion
	*/
class BrlyMRegion {

public:
	BrlyMRegion(const Sbecore::ubigint ref = 0, const Sbecore::ubigint supRefBrlyMRegion = 0, const Sbecore::usmallint supLvl = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const Sbecore::ubigint refJ = 0, const Sbecore::uint ixVDst = 0, const double toffset = 0.0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint supRefBrlyMRegion;
	Sbecore::usmallint supLvl;
	std::string sref;
	Sbecore::ubigint refJTitle;
	std::string Title;
	Sbecore::ubigint refJ;
	Sbecore::uint ixVDst;
	double toffset;

public:
	bool operator==(const BrlyMRegion& comp);
	bool operator!=(const BrlyMRegion& comp);
};

/**
	* ListBrlyMRegion: recordset of TblBrlyMRegion
	*/
class ListBrlyMRegion {

public:
	ListBrlyMRegion();
	ListBrlyMRegion(const ListBrlyMRegion& src);
	~ListBrlyMRegion();

	void clear();
	unsigned int size() const;
	void append(BrlyMRegion* rec);

	BrlyMRegion* operator[](const Sbecore::uint ix);
	ListBrlyMRegion& operator=(const ListBrlyMRegion& src);
	bool operator==(const ListBrlyMRegion& comp);
	bool operator!=(const ListBrlyMRegion& comp);

public:
	std::vector<BrlyMRegion*> nodes;
};

/**
	* TblBrlyMRegion: C++ wrapper for table TblBrlyMRegion
	*/
class TblBrlyMRegion {

public:
	/**
		* VecVDst (full: VecBrlyVMRegionDst)
		*/
	class VecVDst {

	public:
		static const Sbecore::uint NONE = 1;
		static const Sbecore::uint NDST = 2;
		static const Sbecore::uint SDST = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWSubset (full: VecBrlyWMRegionSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSBRLYBMREGIONRIP = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);
	};

public:
	TblBrlyMRegion();
	virtual ~TblBrlyMRegion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMRegion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMRegion& rst);

	virtual Sbecore::ubigint insertRec(BrlyMRegion* rec);
	Sbecore::ubigint insertNewRec(BrlyMRegion** rec = NULL, const Sbecore::ubigint supRefBrlyMRegion = 0, const Sbecore::usmallint supLvl = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const Sbecore::ubigint refJ = 0, const Sbecore::uint ixVDst = 0, const double toffset = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyMRegion& rst, BrlyMRegion** rec = NULL, const Sbecore::ubigint supRefBrlyMRegion = 0, const Sbecore::usmallint supLvl = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const Sbecore::ubigint refJ = 0, const Sbecore::uint ixVDst = 0, const double toffset = 0.0);
	virtual void insertRst(ListBrlyMRegion& rst, bool transact = false);
	virtual void updateRec(BrlyMRegion* rec);
	virtual void updateRst(ListBrlyMRegion& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMRegion** rec);
	virtual bool confirmByRef(Sbecore::ubigint ref);
	virtual bool loadRefBySupSrf(Sbecore::ubigint supRefBrlyMRegion, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefBrlyMRegion, const bool append, ListBrlyMRegion& rst);
	virtual bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefBrlyMRegion);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMRegion& rst);
	Sbecore::ubigint loadHrefsup(Sbecore::ubigint ref, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadHrefsdown(Sbecore::ubigint ref, const bool append, std::vector<Sbecore::ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	Sbecore::ubigint loadHrstup(Sbecore::ubigint ref, ListBrlyMRegion& rst);
	Sbecore::ubigint loadHrstdown(Sbecore::ubigint ref, const bool append, ListBrlyMRegion& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMRegion: C++ wrapper for table TblBrlyMRegion (MySQL database)
	*/
class MyTblBrlyMRegion : public TblBrlyMRegion, public Sbecore::MyTable {

public:
	MyTblBrlyMRegion();
	~MyTblBrlyMRegion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMRegion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMRegion& rst);

	Sbecore::ubigint insertRec(BrlyMRegion* rec);
	void insertRst(ListBrlyMRegion& rst, bool transact = false);
	void updateRec(BrlyMRegion* rec);
	void updateRst(ListBrlyMRegion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMRegion** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	bool loadRefBySupSrf(Sbecore::ubigint supRefBrlyMRegion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefBrlyMRegion, const bool append, ListBrlyMRegion& rst);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefBrlyMRegion);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMRegion: C++ wrapper for table TblBrlyMRegion (PgSQL database)
	*/
class PgTblBrlyMRegion : public TblBrlyMRegion, public Sbecore::PgTable {

public:
	PgTblBrlyMRegion();
	~PgTblBrlyMRegion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMRegion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMRegion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMRegion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMRegion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMRegion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMRegion& rst);

	Sbecore::ubigint insertRec(BrlyMRegion* rec);
	void insertRst(ListBrlyMRegion& rst, bool transact = false);
	void updateRec(BrlyMRegion* rec);
	void updateRst(ListBrlyMRegion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMRegion** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	bool loadRefBySupSrf(Sbecore::ubigint supRefBrlyMRegion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefBrlyMRegion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefBrlyMRegion, const bool append, ListBrlyMRegion& rst);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefBrlyMRegion);
};
#endif

#endif
