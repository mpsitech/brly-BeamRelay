/**
	* \file BrlyQLocMNFlight.h
	* Dbs and XML wrapper for table TblBrlyQLocMNFlight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCMNFLIGHT_H
#define BRLYQLOCMNFLIGHT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocMNFlight: record of TblBrlyQLocMNFlight
	*/
class BrlyQLocMNFlight {

public:
	BrlyQLocMNFlight(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const std::string ftmX1VisStart = "", const Sbecore::uint x1VisStop = 0, const std::string ftmX1VisStop = "", const Sbecore::uint xVisStart = 0, const std::string ftmXVisStart = "", const Sbecore::uint xVisStop = 0, const std::string ftmXVisStop = "");

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
	* ListBrlyQLocMNFlight: recordset of TblBrlyQLocMNFlight
	*/
class ListBrlyQLocMNFlight {

public:
	ListBrlyQLocMNFlight();
	ListBrlyQLocMNFlight(const ListBrlyQLocMNFlight& src);
	~ListBrlyQLocMNFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMNFlight* rec);

	ListBrlyQLocMNFlight& operator=(const ListBrlyQLocMNFlight& src);

public:
	std::vector<BrlyQLocMNFlight*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocMNFlight: C++ wrapper for table TblBrlyQLocMNFlight
	*/
class TblBrlyQLocMNFlight {

public:
	TblBrlyQLocMNFlight();
	virtual ~TblBrlyQLocMNFlight();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMNFlight** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMNFlight& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocMNFlight* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocMNFlight** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const std::string ftmX1VisStart = "", const Sbecore::uint x1VisStop = 0, const std::string ftmX1VisStop = "", const Sbecore::uint xVisStart = 0, const std::string ftmXVisStart = "", const Sbecore::uint xVisStop = 0, const std::string ftmXVisStop = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocMNFlight& rst, BrlyQLocMNFlight** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const std::string ftmX1VisStart = "", const Sbecore::uint x1VisStop = 0, const std::string ftmX1VisStop = "", const Sbecore::uint xVisStart = 0, const std::string ftmXVisStart = "", const Sbecore::uint xVisStop = 0, const std::string ftmXVisStop = "");
	virtual void insertRst(ListBrlyQLocMNFlight& rst);
	virtual void updateRec(BrlyQLocMNFlight* rec);
	virtual void updateRst(ListBrlyQLocMNFlight& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMNFlight** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMNFlight& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocMNFlight: C++ wrapper for table TblBrlyQLocMNFlight (MySQL database)
	*/
class MyTblBrlyQLocMNFlight : public TblBrlyQLocMNFlight, public Sbecore::MyTable {

public:
	MyTblBrlyQLocMNFlight();
	~MyTblBrlyQLocMNFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMNFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMNFlight& rst);

	Sbecore::ubigint insertRec(BrlyQLocMNFlight* rec);
	void insertRst(ListBrlyQLocMNFlight& rst);
	void updateRec(BrlyQLocMNFlight* rec);
	void updateRst(ListBrlyQLocMNFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMNFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMNFlight& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocMNFlight: C++ wrapper for table TblBrlyQLocMNFlight (PgSQL database)
	*/
class PgTblBrlyQLocMNFlight : public TblBrlyQLocMNFlight, public Sbecore::PgTable {

public:
	PgTblBrlyQLocMNFlight();
	~PgTblBrlyQLocMNFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMNFlight** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMNFlight& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMNFlight** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMNFlight& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMNFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMNFlight& rst);

	Sbecore::ubigint insertRec(BrlyQLocMNFlight* rec);
	void insertRst(ListBrlyQLocMNFlight& rst);
	void updateRec(BrlyQLocMNFlight* rec);
	void updateRst(ListBrlyQLocMNFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMNFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMNFlight& rst);
};
#endif

#endif
