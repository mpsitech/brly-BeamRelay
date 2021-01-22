/**
	* \file BrlyQReg1NLocation.h
	* Dbs and XML wrapper for table TblBrlyQReg1NLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQREG1NLOCATION_H
#define BRLYQREG1NLOCATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQReg1NLocation: record of TblBrlyQReg1NLocation
	*/
class BrlyQReg1NLocation {

public:
	BrlyQReg1NLocation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQReg1NLocation: recordset of TblBrlyQReg1NLocation
	*/
class ListBrlyQReg1NLocation {

public:
	ListBrlyQReg1NLocation();
	ListBrlyQReg1NLocation(const ListBrlyQReg1NLocation& src);
	~ListBrlyQReg1NLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQReg1NLocation* rec);

	ListBrlyQReg1NLocation& operator=(const ListBrlyQReg1NLocation& src);

public:
	std::vector<BrlyQReg1NLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQReg1NLocation: C++ wrapper for table TblBrlyQReg1NLocation
	*/
class TblBrlyQReg1NLocation {

public:
	TblBrlyQReg1NLocation();
	virtual ~TblBrlyQReg1NLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQReg1NLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQReg1NLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyQReg1NLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyQReg1NLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQReg1NLocation& rst, BrlyQReg1NLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQReg1NLocation& rst);
	virtual void updateRec(BrlyQReg1NLocation* rec);
	virtual void updateRst(ListBrlyQReg1NLocation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQReg1NLocation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQReg1NLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQReg1NLocation: C++ wrapper for table TblBrlyQReg1NLocation (MySQL database)
	*/
class MyTblBrlyQReg1NLocation : public TblBrlyQReg1NLocation, public Sbecore::MyTable {

public:
	MyTblBrlyQReg1NLocation();
	~MyTblBrlyQReg1NLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQReg1NLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQReg1NLocation& rst);

	Sbecore::ubigint insertRec(BrlyQReg1NLocation* rec);
	void insertRst(ListBrlyQReg1NLocation& rst);
	void updateRec(BrlyQReg1NLocation* rec);
	void updateRst(ListBrlyQReg1NLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQReg1NLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQReg1NLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQReg1NLocation: C++ wrapper for table TblBrlyQReg1NLocation (PgSQL database)
	*/
class PgTblBrlyQReg1NLocation : public TblBrlyQReg1NLocation, public Sbecore::PgTable {

public:
	PgTblBrlyQReg1NLocation();
	~PgTblBrlyQReg1NLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQReg1NLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQReg1NLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQReg1NLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQReg1NLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQReg1NLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQReg1NLocation& rst);

	Sbecore::ubigint insertRec(BrlyQReg1NLocation* rec);
	void insertRst(ListBrlyQReg1NLocation& rst);
	void updateRec(BrlyQReg1NLocation* rec);
	void updateRst(ListBrlyQReg1NLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQReg1NLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQReg1NLocation& rst);
};
#endif

#endif
