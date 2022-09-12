/**
	* \file BrlyMPerson.h
	* database access for table TblBrlyMPerson (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMPERSON_H
#define BRLYMPERSON_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecBrlyVMPersonSex TblBrlyMPerson::VecVSex
#define VecBrlyWMPersonDerivate TblBrlyMPerson::VecWDerivate

/**
	* BrlyMPerson: record of TblBrlyMPerson
	*/
class BrlyMPerson {

public:
	BrlyMPerson(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::uint ixWDerivate;
	Sbecore::uint ixVSex;
	std::string Title;
	std::string Firstname;
	Sbecore::ubigint refJLastname;
	std::string Lastname;
	Sbecore::ubigint telRefADetail;
	std::string telVal;
	Sbecore::ubigint emlRefADetail;
	std::string emlVal;
	std::string Salutation;

public:
	bool operator==(const BrlyMPerson& comp);
	bool operator!=(const BrlyMPerson& comp);
};

/**
	* ListBrlyMPerson: recordset of TblBrlyMPerson
	*/
class ListBrlyMPerson {

public:
	ListBrlyMPerson();
	ListBrlyMPerson(const ListBrlyMPerson& src);
	~ListBrlyMPerson();

	void clear();
	unsigned int size() const;
	void append(BrlyMPerson* rec);

	BrlyMPerson* operator[](const Sbecore::uint ix);
	ListBrlyMPerson& operator=(const ListBrlyMPerson& src);
	bool operator==(const ListBrlyMPerson& comp);
	bool operator!=(const ListBrlyMPerson& comp);

public:
	std::vector<BrlyMPerson*> nodes;
};

/**
	* TblBrlyMPerson: C++ wrapper for table TblBrlyMPerson
	*/
class TblBrlyMPerson {

public:
	/**
		* VecVSex (full: VecBrlyVMPersonSex)
		*/
	class VecVSex {

	public:
		static const Sbecore::uint F = 1;
		static const Sbecore::uint M = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecWDerivate (full: VecBrlyWMPersonDerivate)
		*/
	class VecWDerivate {

	public:
		static const Sbecore::uint USR = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

public:
	TblBrlyMPerson();
	virtual ~TblBrlyMPerson();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMPerson** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMPerson& rst);

	virtual Sbecore::ubigint insertRec(BrlyMPerson* rec);
	Sbecore::ubigint insertNewRec(BrlyMPerson** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyMPerson& rst, BrlyMPerson** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");
	virtual void insertRst(ListBrlyMPerson& rst, bool transact = false);
	virtual void updateRec(BrlyMPerson* rec);
	virtual void updateRst(ListBrlyMPerson& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMPerson** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMPerson& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMPerson: C++ wrapper for table TblBrlyMPerson (MySQL database)
	*/
class MyTblBrlyMPerson : public TblBrlyMPerson, public Sbecore::MyTable {

public:
	MyTblBrlyMPerson();
	~MyTblBrlyMPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMPerson& rst);

	Sbecore::ubigint insertRec(BrlyMPerson* rec);
	void insertRst(ListBrlyMPerson& rst, bool transact = false);
	void updateRec(BrlyMPerson* rec);
	void updateRst(ListBrlyMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMPerson** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMPerson: C++ wrapper for table TblBrlyMPerson (PgSQL database)
	*/
class PgTblBrlyMPerson : public TblBrlyMPerson, public Sbecore::PgTable {

public:
	PgTblBrlyMPerson();
	~PgTblBrlyMPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMPerson** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMPerson& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMPerson** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMPerson& rst);

	Sbecore::ubigint insertRec(BrlyMPerson* rec);
	void insertRst(ListBrlyMPerson& rst, bool transact = false);
	void updateRec(BrlyMPerson* rec);
	void updateRst(ListBrlyMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMPerson** rec);
};
#endif

#endif
