/**
	* \file BrlyMUser.h
	* database access for table TblBrlyMUser (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMUSER_H
#define BRLYMUSER_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecBrlyVMUserState TblBrlyMUser::VecVState

/**
	* BrlyMUser: record of TblBrlyMUser
	*/
class BrlyMUser {

public:
	BrlyMUser(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::ubigint refBrlyMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixBrlyVLocale = 0, const Sbecore::uint ixBrlyVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refRUsergroup;
	Sbecore::ubigint refBrlyMUsergroup;
	Sbecore::ubigint refBrlyMPerson;
	std::string sref;
	Sbecore::ubigint refJState;
	Sbecore::uint ixVState;
	Sbecore::uint ixBrlyVLocale;
	Sbecore::uint ixBrlyVUserlevel;
	std::string Password;
	std::string Fullkey;
	std::string Comment;

public:
	bool operator==(const BrlyMUser& comp);
	bool operator!=(const BrlyMUser& comp);
};

/**
	* ListBrlyMUser: recordset of TblBrlyMUser
	*/
class ListBrlyMUser {

public:
	ListBrlyMUser();
	ListBrlyMUser(const ListBrlyMUser& src);
	~ListBrlyMUser();

	void clear();
	unsigned int size() const;
	void append(BrlyMUser* rec);

	BrlyMUser* operator[](const Sbecore::uint ix);
	ListBrlyMUser& operator=(const ListBrlyMUser& src);
	bool operator==(const ListBrlyMUser& comp);
	bool operator!=(const ListBrlyMUser& comp);

public:
	std::vector<BrlyMUser*> nodes;
};

/**
	* TblBrlyMUser: C++ wrapper for table TblBrlyMUser
	*/
class TblBrlyMUser {

public:
	/**
		* VecVState (full: VecBrlyVMUserState)
		*/
	class VecVState {

	public:
		static const Sbecore::uint ACT = 1;
		static const Sbecore::uint DSG = 2;
		static const Sbecore::uint DUE = 3;
		static const Sbecore::uint EXP = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblBrlyMUser();
	virtual ~TblBrlyMUser();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMUser** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMUser& rst);

	virtual Sbecore::ubigint insertRec(BrlyMUser* rec);
	Sbecore::ubigint insertNewRec(BrlyMUser** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::ubigint refBrlyMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixBrlyVLocale = 0, const Sbecore::uint ixBrlyVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyMUser& rst, BrlyMUser** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refBrlyMUsergroup = 0, const Sbecore::ubigint refBrlyMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixBrlyVLocale = 0, const Sbecore::uint ixBrlyVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");
	virtual void insertRst(ListBrlyMUser& rst, bool transact = false);
	virtual void updateRec(BrlyMUser* rec);
	virtual void updateRst(ListBrlyMUser& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMUser** rec);
	virtual bool loadRecByPrs(Sbecore::ubigint refBrlyMPerson, BrlyMUser** rec);
	virtual bool loadRecBySrf(std::string sref, BrlyMUser** rec);
	virtual bool loadRecBySrfPwd(std::string sref, std::string Password, BrlyMUser** rec);
	virtual bool loadRefByPrs(Sbecore::ubigint refBrlyMPerson, Sbecore::ubigint& ref);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMUser& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMUser: C++ wrapper for table TblBrlyMUser (MySQL database)
	*/
class MyTblBrlyMUser : public TblBrlyMUser, public Sbecore::MyTable {

public:
	MyTblBrlyMUser();
	~MyTblBrlyMUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMUser& rst);

	Sbecore::ubigint insertRec(BrlyMUser* rec);
	void insertRst(ListBrlyMUser& rst, bool transact = false);
	void updateRec(BrlyMUser* rec);
	void updateRst(ListBrlyMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMUser** rec);
	bool loadRecByPrs(Sbecore::ubigint refBrlyMPerson, BrlyMUser** rec);
	bool loadRecBySrf(std::string sref, BrlyMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, BrlyMUser** rec);
	bool loadRefByPrs(Sbecore::ubigint refBrlyMPerson, Sbecore::ubigint& ref);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMUser: C++ wrapper for table TblBrlyMUser (PgSQL database)
	*/
class PgTblBrlyMUser : public TblBrlyMUser, public Sbecore::PgTable {

public:
	PgTblBrlyMUser();
	~PgTblBrlyMUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMUser** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMUser& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMUser** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMUser& rst);

	Sbecore::ubigint insertRec(BrlyMUser* rec);
	void insertRst(ListBrlyMUser& rst, bool transact = false);
	void updateRec(BrlyMUser* rec);
	void updateRst(ListBrlyMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMUser** rec);
	bool loadRecByPrs(Sbecore::ubigint refBrlyMPerson, BrlyMUser** rec);
	bool loadRecBySrf(std::string sref, BrlyMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, BrlyMUser** rec);
	bool loadRefByPrs(Sbecore::ubigint refBrlyMPerson, Sbecore::ubigint& ref);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refBrlyMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
