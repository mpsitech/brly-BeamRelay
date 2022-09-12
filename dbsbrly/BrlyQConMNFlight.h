/**
	* \file BrlyQConMNFlight.h
	* Dbs and XML wrapper for table TblBrlyQConMNFlight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCONMNFLIGHT_H
#define BRLYQCONMNFLIGHT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQConMNFlight: record of TblBrlyQConMNFlight
	*/
class BrlyQConMNFlight {

public:
	BrlyQConMNFlight(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint x1Start;
	std::string ftmX1Start;
	Sbecore::uint x1Stop;
	std::string ftmX1Stop;
	double x2Legphi0;
	double x2Legphi1;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQConMNFlight: recordset of TblBrlyQConMNFlight
	*/
class ListBrlyQConMNFlight {

public:
	ListBrlyQConMNFlight();
	ListBrlyQConMNFlight(const ListBrlyQConMNFlight& src);
	~ListBrlyQConMNFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMNFlight* rec);

	ListBrlyQConMNFlight& operator=(const ListBrlyQConMNFlight& src);

public:
	std::vector<BrlyQConMNFlight*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQConMNFlight: C++ wrapper for table TblBrlyQConMNFlight
	*/
class TblBrlyQConMNFlight {

public:
	TblBrlyQConMNFlight();
	virtual ~TblBrlyQConMNFlight();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQConMNFlight** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMNFlight& rst);

	virtual Sbecore::ubigint insertRec(BrlyQConMNFlight* rec);
	Sbecore::ubigint insertNewRec(BrlyQConMNFlight** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQConMNFlight& rst, BrlyQConMNFlight** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	virtual void insertRst(ListBrlyQConMNFlight& rst);
	virtual void updateRec(BrlyQConMNFlight* rec);
	virtual void updateRst(ListBrlyQConMNFlight& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMNFlight** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMNFlight& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQConMNFlight: C++ wrapper for table TblBrlyQConMNFlight (MySQL database)
	*/
class MyTblBrlyQConMNFlight : public TblBrlyQConMNFlight, public Sbecore::MyTable {

public:
	MyTblBrlyQConMNFlight();
	~MyTblBrlyQConMNFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMNFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMNFlight& rst);

	Sbecore::ubigint insertRec(BrlyQConMNFlight* rec);
	void insertRst(ListBrlyQConMNFlight& rst);
	void updateRec(BrlyQConMNFlight* rec);
	void updateRst(ListBrlyQConMNFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMNFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMNFlight& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQConMNFlight: C++ wrapper for table TblBrlyQConMNFlight (PgSQL database)
	*/
class PgTblBrlyQConMNFlight : public TblBrlyQConMNFlight, public Sbecore::PgTable {

public:
	PgTblBrlyQConMNFlight();
	~PgTblBrlyQConMNFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMNFlight** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMNFlight& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMNFlight** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMNFlight& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMNFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMNFlight& rst);

	Sbecore::ubigint insertRec(BrlyQConMNFlight* rec);
	void insertRst(ListBrlyQConMNFlight& rst);
	void updateRec(BrlyQConMNFlight* rec);
	void updateRst(ListBrlyQConMNFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMNFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMNFlight& rst);
};
#endif

#endif
