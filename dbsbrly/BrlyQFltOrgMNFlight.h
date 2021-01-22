/**
	* \file BrlyQFltOrgMNFlight.h
	* Dbs and XML wrapper for table TblBrlyQFltOrgMNFlight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQFLTORGMNFLIGHT_H
#define BRLYQFLTORGMNFLIGHT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQFltOrgMNFlight: record of TblBrlyQFltOrgMNFlight
	*/
class BrlyQFltOrgMNFlight {

public:
	BrlyQFltOrgMNFlight(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const std::string ftmX1VisStart = "", const Sbecore::uint x1VisStop = 0, const std::string ftmX1VisStop = "", const Sbecore::uint xVisStart = 0, const std::string ftmXVisStart = "", const Sbecore::uint xVisStop = 0, const std::string ftmXVisStop = "");

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
	* ListBrlyQFltOrgMNFlight: recordset of TblBrlyQFltOrgMNFlight
	*/
class ListBrlyQFltOrgMNFlight {

public:
	ListBrlyQFltOrgMNFlight();
	ListBrlyQFltOrgMNFlight(const ListBrlyQFltOrgMNFlight& src);
	~ListBrlyQFltOrgMNFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltOrgMNFlight* rec);

	ListBrlyQFltOrgMNFlight& operator=(const ListBrlyQFltOrgMNFlight& src);

public:
	std::vector<BrlyQFltOrgMNFlight*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQFltOrgMNFlight: C++ wrapper for table TblBrlyQFltOrgMNFlight
	*/
class TblBrlyQFltOrgMNFlight {

public:
	TblBrlyQFltOrgMNFlight();
	virtual ~TblBrlyQFltOrgMNFlight();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQFltOrgMNFlight** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltOrgMNFlight& rst);

	virtual Sbecore::ubigint insertRec(BrlyQFltOrgMNFlight* rec);
	Sbecore::ubigint insertNewRec(BrlyQFltOrgMNFlight** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const std::string ftmX1VisStart = "", const Sbecore::uint x1VisStop = 0, const std::string ftmX1VisStop = "", const Sbecore::uint xVisStart = 0, const std::string ftmXVisStart = "", const Sbecore::uint xVisStop = 0, const std::string ftmXVisStop = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQFltOrgMNFlight& rst, BrlyQFltOrgMNFlight** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1VisStart = 0, const std::string ftmX1VisStart = "", const Sbecore::uint x1VisStop = 0, const std::string ftmX1VisStop = "", const Sbecore::uint xVisStart = 0, const std::string ftmXVisStart = "", const Sbecore::uint xVisStop = 0, const std::string ftmXVisStop = "");
	virtual void insertRst(ListBrlyQFltOrgMNFlight& rst);
	virtual void updateRec(BrlyQFltOrgMNFlight* rec);
	virtual void updateRst(ListBrlyQFltOrgMNFlight& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltOrgMNFlight** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltOrgMNFlight& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQFltOrgMNFlight: C++ wrapper for table TblBrlyQFltOrgMNFlight (MySQL database)
	*/
class MyTblBrlyQFltOrgMNFlight : public TblBrlyQFltOrgMNFlight, public Sbecore::MyTable {

public:
	MyTblBrlyQFltOrgMNFlight();
	~MyTblBrlyQFltOrgMNFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltOrgMNFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltOrgMNFlight& rst);

	Sbecore::ubigint insertRec(BrlyQFltOrgMNFlight* rec);
	void insertRst(ListBrlyQFltOrgMNFlight& rst);
	void updateRec(BrlyQFltOrgMNFlight* rec);
	void updateRst(ListBrlyQFltOrgMNFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltOrgMNFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltOrgMNFlight& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQFltOrgMNFlight: C++ wrapper for table TblBrlyQFltOrgMNFlight (PgSQL database)
	*/
class PgTblBrlyQFltOrgMNFlight : public TblBrlyQFltOrgMNFlight, public Sbecore::PgTable {

public:
	PgTblBrlyQFltOrgMNFlight();
	~PgTblBrlyQFltOrgMNFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltOrgMNFlight** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltOrgMNFlight& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltOrgMNFlight** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltOrgMNFlight& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltOrgMNFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltOrgMNFlight& rst);

	Sbecore::ubigint insertRec(BrlyQFltOrgMNFlight* rec);
	void insertRst(ListBrlyQFltOrgMNFlight& rst);
	void updateRec(BrlyQFltOrgMNFlight* rec);
	void updateRst(ListBrlyQFltOrgMNFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltOrgMNFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltOrgMNFlight& rst);
};
#endif

#endif
