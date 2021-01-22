/**
	* \file BrlyQFltMNLocation.h
	* Dbs and XML wrapper for table TblBrlyQFltMNLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQFLTMNLOCATION_H
#define BRLYQFLTMNLOCATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQFltMNLocation: record of TblBrlyQFltMNLocation
	*/
class BrlyQFltMNLocation {

public:
	BrlyQFltMNLocation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const std::string ftmX1VisStart = "", const Sbecore::uint x1VisStop = 0, const std::string ftmX1VisStop = "", const Sbecore::uint xVisStart = 0, const std::string ftmXVisStart = "", const Sbecore::uint xVisStop = 0, const std::string ftmXVisStop = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint x1VisStart;
	std::string ftmX1VisStart;
	Sbecore::uint x1VisStop;
	std::string ftmX1VisStop;
	Sbecore::uint xVisStart;
	std::string ftmXVisStart;
	Sbecore::uint xVisStop;
	std::string ftmXVisStop;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQFltMNLocation: recordset of TblBrlyQFltMNLocation
	*/
class ListBrlyQFltMNLocation {

public:
	ListBrlyQFltMNLocation();
	ListBrlyQFltMNLocation(const ListBrlyQFltMNLocation& src);
	~ListBrlyQFltMNLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltMNLocation* rec);

	ListBrlyQFltMNLocation& operator=(const ListBrlyQFltMNLocation& src);

public:
	std::vector<BrlyQFltMNLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQFltMNLocation: C++ wrapper for table TblBrlyQFltMNLocation
	*/
class TblBrlyQFltMNLocation {

public:
	TblBrlyQFltMNLocation();
	virtual ~TblBrlyQFltMNLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQFltMNLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltMNLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyQFltMNLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyQFltMNLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const std::string ftmX1VisStart = "", const Sbecore::uint x1VisStop = 0, const std::string ftmX1VisStop = "", const Sbecore::uint xVisStart = 0, const std::string ftmXVisStart = "", const Sbecore::uint xVisStop = 0, const std::string ftmXVisStop = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQFltMNLocation& rst, BrlyQFltMNLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const std::string ftmX1VisStart = "", const Sbecore::uint x1VisStop = 0, const std::string ftmX1VisStop = "", const Sbecore::uint xVisStart = 0, const std::string ftmXVisStart = "", const Sbecore::uint xVisStop = 0, const std::string ftmXVisStop = "");
	virtual void insertRst(ListBrlyQFltMNLocation& rst);
	virtual void updateRec(BrlyQFltMNLocation* rec);
	virtual void updateRst(ListBrlyQFltMNLocation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltMNLocation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltMNLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQFltMNLocation: C++ wrapper for table TblBrlyQFltMNLocation (MySQL database)
	*/
class MyTblBrlyQFltMNLocation : public TblBrlyQFltMNLocation, public Sbecore::MyTable {

public:
	MyTblBrlyQFltMNLocation();
	~MyTblBrlyQFltMNLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltMNLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltMNLocation& rst);

	Sbecore::ubigint insertRec(BrlyQFltMNLocation* rec);
	void insertRst(ListBrlyQFltMNLocation& rst);
	void updateRec(BrlyQFltMNLocation* rec);
	void updateRst(ListBrlyQFltMNLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltMNLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltMNLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQFltMNLocation: C++ wrapper for table TblBrlyQFltMNLocation (PgSQL database)
	*/
class PgTblBrlyQFltMNLocation : public TblBrlyQFltMNLocation, public Sbecore::PgTable {

public:
	PgTblBrlyQFltMNLocation();
	~PgTblBrlyQFltMNLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltMNLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltMNLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltMNLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltMNLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltMNLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltMNLocation& rst);

	Sbecore::ubigint insertRec(BrlyQFltMNLocation* rec);
	void insertRst(ListBrlyQFltMNLocation& rst);
	void updateRec(BrlyQFltMNLocation* rec);
	void updateRst(ListBrlyQFltMNLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltMNLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltMNLocation& rst);
};
#endif

#endif
