/**
	* \file BrlyMLeg.h
	* database access for table TblBrlyMLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMLEG_H
#define BRLYMLEG_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecBrlyVMLegBasetype TblBrlyMLeg::VecVBasetype
#define VecBrlyWMLegSubset TblBrlyMLeg::VecWSubset

/**
	* BrlyMLeg: record of TblBrlyMLeg
	*/
class BrlyMLeg {

public:
	BrlyMLeg(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refBrlyCLeg = 0, const Sbecore::ubigint bgnRefBrlyMLocation = 0, const Sbecore::ubigint endRefBrlyMLocation = 0, const double alt = 0.0, const double deltaphi = 0.0, const double alpha = 0.0, const double xAlt = 0.0, const double xPhi0 = 0.0, const double xPhi1 = 0.0, const double xAlpha = 0.0, const bool Calcdone = false);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refBrlyCLeg;
	Sbecore::ubigint bgnRefBrlyMLocation;
	Sbecore::ubigint endRefBrlyMLocation;
	double alt;
	double deltaphi;
	double alpha;
	double xAlt;
	double xPhi0;
	double xPhi1;
	double xAlpha;
	bool Calcdone;

public:
	bool operator==(const BrlyMLeg& comp);
	bool operator!=(const BrlyMLeg& comp);
};

/**
	* ListBrlyMLeg: recordset of TblBrlyMLeg
	*/
class ListBrlyMLeg {

public:
	ListBrlyMLeg();
	ListBrlyMLeg(const ListBrlyMLeg& src);
	~ListBrlyMLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyMLeg* rec);

	BrlyMLeg* operator[](const Sbecore::uint ix);
	ListBrlyMLeg& operator=(const ListBrlyMLeg& src);
	bool operator==(const ListBrlyMLeg& comp);
	bool operator!=(const ListBrlyMLeg& comp);

public:
	std::vector<BrlyMLeg*> nodes;
};

/**
	* TblBrlyMLeg: C++ wrapper for table TblBrlyMLeg
	*/
class TblBrlyMLeg {

public:
	/**
		* VecVBasetype (full: VecBrlyVMLegBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint CORR = 1;
		static const Sbecore::uint RTE = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWSubset (full: VecBrlyWMLegSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSBRLYBMLEGCOR = 1;
		static const Sbecore::uint SBSBRLYBMLEGRTE = 2;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);
	};

public:
	TblBrlyMLeg();
	virtual ~TblBrlyMLeg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMLeg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMLeg& rst);

	virtual Sbecore::ubigint insertRec(BrlyMLeg* rec);
	Sbecore::ubigint insertNewRec(BrlyMLeg** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refBrlyCLeg = 0, const Sbecore::ubigint bgnRefBrlyMLocation = 0, const Sbecore::ubigint endRefBrlyMLocation = 0, const double alt = 0.0, const double deltaphi = 0.0, const double alpha = 0.0, const double xAlt = 0.0, const double xPhi0 = 0.0, const double xPhi1 = 0.0, const double xAlpha = 0.0, const bool Calcdone = false);
	Sbecore::ubigint appendNewRecToRst(ListBrlyMLeg& rst, BrlyMLeg** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refBrlyCLeg = 0, const Sbecore::ubigint bgnRefBrlyMLocation = 0, const Sbecore::ubigint endRefBrlyMLocation = 0, const double alt = 0.0, const double deltaphi = 0.0, const double alpha = 0.0, const double xAlt = 0.0, const double xPhi0 = 0.0, const double xPhi1 = 0.0, const double xAlpha = 0.0, const bool Calcdone = false);
	virtual void insertRst(ListBrlyMLeg& rst, bool transact = false);
	virtual void updateRec(BrlyMLeg* rec);
	virtual void updateRst(ListBrlyMLeg& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMLeg** rec);
	virtual bool loadRefByTypBloElo(Sbecore::uint ixVBasetype, Sbecore::ubigint bgnRefBrlyMLocation, Sbecore::ubigint endRefBrlyMLocation, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByBlo(Sbecore::ubigint bgnRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refBrlyCLeg, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByElo(Sbecore::ubigint endRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRst(const bool append, ListBrlyMLeg& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	virtual Sbecore::ubigint loadRstByBlo(Sbecore::ubigint bgnRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refBrlyCLeg, const bool append, ListBrlyMLeg& rst);
	virtual Sbecore::ubigint loadRstByElo(Sbecore::ubigint endRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	virtual Sbecore::ubigint loadRstByTyp(Sbecore::uint ixVBasetype, const bool append, ListBrlyMLeg& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMLeg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMLeg: C++ wrapper for table TblBrlyMLeg (MySQL database)
	*/
class MyTblBrlyMLeg : public TblBrlyMLeg, public Sbecore::MyTable {

public:
	MyTblBrlyMLeg();
	~MyTblBrlyMLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMLeg& rst);

	Sbecore::ubigint insertRec(BrlyMLeg* rec);
	void insertRst(ListBrlyMLeg& rst, bool transact = false);
	void updateRec(BrlyMLeg* rec);
	void updateRst(ListBrlyMLeg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMLeg** rec);
	bool loadRefByTypBloElo(Sbecore::uint ixVBasetype, Sbecore::ubigint bgnRefBrlyMLocation, Sbecore::ubigint endRefBrlyMLocation, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByBlo(Sbecore::ubigint bgnRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refBrlyCLeg, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByElo(Sbecore::ubigint endRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRst(const bool append, ListBrlyMLeg& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByBlo(Sbecore::ubigint bgnRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refBrlyCLeg, const bool append, ListBrlyMLeg& rst);
	Sbecore::ubigint loadRstByElo(Sbecore::ubigint endRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	Sbecore::ubigint loadRstByTyp(Sbecore::uint ixVBasetype, const bool append, ListBrlyMLeg& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMLeg: C++ wrapper for table TblBrlyMLeg (PgSQL database)
	*/
class PgTblBrlyMLeg : public TblBrlyMLeg, public Sbecore::PgTable {

public:
	PgTblBrlyMLeg();
	~PgTblBrlyMLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMLeg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMLeg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMLeg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMLeg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMLeg& rst);

	Sbecore::ubigint insertRec(BrlyMLeg* rec);
	void insertRst(ListBrlyMLeg& rst, bool transact = false);
	void updateRec(BrlyMLeg* rec);
	void updateRst(ListBrlyMLeg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMLeg** rec);
	bool loadRefByTypBloElo(Sbecore::uint ixVBasetype, Sbecore::ubigint bgnRefBrlyMLocation, Sbecore::ubigint endRefBrlyMLocation, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByBlo(Sbecore::ubigint bgnRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refBrlyCLeg, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByElo(Sbecore::ubigint endRefBrlyMLocation, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRst(const bool append, ListBrlyMLeg& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByBlo(Sbecore::ubigint bgnRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refBrlyCLeg, const bool append, ListBrlyMLeg& rst);
	Sbecore::ubigint loadRstByElo(Sbecore::ubigint endRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	Sbecore::ubigint loadRstByTyp(Sbecore::uint ixVBasetype, const bool append, ListBrlyMLeg& rst, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
};
#endif

#endif
