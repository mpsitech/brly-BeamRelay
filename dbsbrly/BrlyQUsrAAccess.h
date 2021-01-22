/**
	* \file BrlyQUsrAAccess.h
	* Dbs and XML wrapper for table TblBrlyQUsrAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQUSRAACCESS_H
#define BRLYQUSRAACCESS_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQUsrAAccess: record of TblBrlyQUsrAAccess
	*/
class BrlyQUsrAAccess {

public:
	BrlyQUsrAAccess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string srefX1IxBrlyVFeatgroup = "", const std::string titX1IxBrlyVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0, const std::string srefsIxBrlyWAccess = "", const std::string titsIxBrlyWAccess = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1IxBrlyVFeatgroup;
	std::string srefX1IxBrlyVFeatgroup;
	std::string titX1IxBrlyVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixBrlyWAccess;
	std::string srefsIxBrlyWAccess;
	std::string titsIxBrlyWAccess;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQUsrAAccess: recordset of TblBrlyQUsrAAccess
	*/
class ListBrlyQUsrAAccess {

public:
	ListBrlyQUsrAAccess();
	ListBrlyQUsrAAccess(const ListBrlyQUsrAAccess& src);
	~ListBrlyQUsrAAccess();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsrAAccess* rec);

	ListBrlyQUsrAAccess& operator=(const ListBrlyQUsrAAccess& src);

public:
	std::vector<BrlyQUsrAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQUsrAAccess: C++ wrapper for table TblBrlyQUsrAAccess
	*/
class TblBrlyQUsrAAccess {

public:
	TblBrlyQUsrAAccess();
	virtual ~TblBrlyQUsrAAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQUsrAAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsrAAccess& rst);

	virtual Sbecore::ubigint insertRec(BrlyQUsrAAccess* rec);
	Sbecore::ubigint insertNewRec(BrlyQUsrAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string srefX1IxBrlyVFeatgroup = "", const std::string titX1IxBrlyVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0, const std::string srefsIxBrlyWAccess = "", const std::string titsIxBrlyWAccess = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQUsrAAccess& rst, BrlyQUsrAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string srefX1IxBrlyVFeatgroup = "", const std::string titX1IxBrlyVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0, const std::string srefsIxBrlyWAccess = "", const std::string titsIxBrlyWAccess = "");
	virtual void insertRst(ListBrlyQUsrAAccess& rst);
	virtual void updateRec(BrlyQUsrAAccess* rec);
	virtual void updateRst(ListBrlyQUsrAAccess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsrAAccess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsrAAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQUsrAAccess: C++ wrapper for table TblBrlyQUsrAAccess (MySQL database)
	*/
class MyTblBrlyQUsrAAccess : public TblBrlyQUsrAAccess, public Sbecore::MyTable {

public:
	MyTblBrlyQUsrAAccess();
	~MyTblBrlyQUsrAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsrAAccess& rst);

	Sbecore::ubigint insertRec(BrlyQUsrAAccess* rec);
	void insertRst(ListBrlyQUsrAAccess& rst);
	void updateRec(BrlyQUsrAAccess* rec);
	void updateRst(ListBrlyQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsrAAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQUsrAAccess: C++ wrapper for table TblBrlyQUsrAAccess (PgSQL database)
	*/
class PgTblBrlyQUsrAAccess : public TblBrlyQUsrAAccess, public Sbecore::PgTable {

public:
	PgTblBrlyQUsrAAccess();
	~PgTblBrlyQUsrAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsrAAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsrAAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsrAAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsrAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQUsrAAccess& rst);

	Sbecore::ubigint insertRec(BrlyQUsrAAccess* rec);
	void insertRst(ListBrlyQUsrAAccess& rst);
	void updateRec(BrlyQUsrAAccess* rec);
	void updateRst(ListBrlyQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQUsrAAccess& rst);
};
#endif

#endif
