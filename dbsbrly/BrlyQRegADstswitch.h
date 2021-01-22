/**
	* \file BrlyQRegADstswitch.h
	* Dbs and XML wrapper for table TblBrlyQRegADstswitch (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQREGADSTSWITCH_H
#define BRLYQREGADSTSWITCH_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQRegADstswitch: record of TblBrlyQRegADstswitch
	*/
class BrlyQRegADstswitch {

public:
	BrlyQRegADstswitch(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint startd = 0, const std::string ftmStartd = "", const Sbecore::uint startt = 0, const std::string ftmStartt = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint startd;
	std::string ftmStartd;
	Sbecore::uint startt;
	std::string ftmStartt;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQRegADstswitch: recordset of TblBrlyQRegADstswitch
	*/
class ListBrlyQRegADstswitch {

public:
	ListBrlyQRegADstswitch();
	ListBrlyQRegADstswitch(const ListBrlyQRegADstswitch& src);
	~ListBrlyQRegADstswitch();

	void clear();
	unsigned int size() const;
	void append(BrlyQRegADstswitch* rec);

	ListBrlyQRegADstswitch& operator=(const ListBrlyQRegADstswitch& src);

public:
	std::vector<BrlyQRegADstswitch*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQRegADstswitch: C++ wrapper for table TblBrlyQRegADstswitch
	*/
class TblBrlyQRegADstswitch {

public:
	TblBrlyQRegADstswitch();
	virtual ~TblBrlyQRegADstswitch();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQRegADstswitch** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRegADstswitch& rst);

	virtual Sbecore::ubigint insertRec(BrlyQRegADstswitch* rec);
	Sbecore::ubigint insertNewRec(BrlyQRegADstswitch** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint startd = 0, const std::string ftmStartd = "", const Sbecore::uint startt = 0, const std::string ftmStartt = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQRegADstswitch& rst, BrlyQRegADstswitch** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint startd = 0, const std::string ftmStartd = "", const Sbecore::uint startt = 0, const std::string ftmStartt = "");
	virtual void insertRst(ListBrlyQRegADstswitch& rst);
	virtual void updateRec(BrlyQRegADstswitch* rec);
	virtual void updateRst(ListBrlyQRegADstswitch& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQRegADstswitch** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRegADstswitch& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQRegADstswitch: C++ wrapper for table TblBrlyQRegADstswitch (MySQL database)
	*/
class MyTblBrlyQRegADstswitch : public TblBrlyQRegADstswitch, public Sbecore::MyTable {

public:
	MyTblBrlyQRegADstswitch();
	~MyTblBrlyQRegADstswitch();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQRegADstswitch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRegADstswitch& rst);

	Sbecore::ubigint insertRec(BrlyQRegADstswitch* rec);
	void insertRst(ListBrlyQRegADstswitch& rst);
	void updateRec(BrlyQRegADstswitch* rec);
	void updateRst(ListBrlyQRegADstswitch& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQRegADstswitch** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRegADstswitch& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQRegADstswitch: C++ wrapper for table TblBrlyQRegADstswitch (PgSQL database)
	*/
class PgTblBrlyQRegADstswitch : public TblBrlyQRegADstswitch, public Sbecore::PgTable {

public:
	PgTblBrlyQRegADstswitch();
	~PgTblBrlyQRegADstswitch();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQRegADstswitch** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQRegADstswitch& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQRegADstswitch** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQRegADstswitch& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQRegADstswitch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRegADstswitch& rst);

	Sbecore::ubigint insertRec(BrlyQRegADstswitch* rec);
	void insertRst(ListBrlyQRegADstswitch& rst);
	void updateRec(BrlyQRegADstswitch* rec);
	void updateRst(ListBrlyQRegADstswitch& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQRegADstswitch** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRegADstswitch& rst);
};
#endif

#endif
