/**
	* \file BrlyQLocMNLeg.h
	* Dbs and XML wrapper for table TblBrlyQLocMNLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCMNLEG_H
#define BRLYQLOCMNLEG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocMNLeg: record of TblBrlyQLocMNLeg
	*/
class BrlyQLocMNLeg {

public:
	BrlyQLocMNLeg(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	double x1VisLegphi0;
	double x1VisLegphi1;
	double legphi;
	double legtheta;
	double xVisLegphi0;
	double xVisLegphi1;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocMNLeg: recordset of TblBrlyQLocMNLeg
	*/
class ListBrlyQLocMNLeg {

public:
	ListBrlyQLocMNLeg();
	ListBrlyQLocMNLeg(const ListBrlyQLocMNLeg& src);
	~ListBrlyQLocMNLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMNLeg* rec);

	ListBrlyQLocMNLeg& operator=(const ListBrlyQLocMNLeg& src);

public:
	std::vector<BrlyQLocMNLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocMNLeg: C++ wrapper for table TblBrlyQLocMNLeg
	*/
class TblBrlyQLocMNLeg {

public:
	TblBrlyQLocMNLeg();
	virtual ~TblBrlyQLocMNLeg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMNLeg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMNLeg& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocMNLeg* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocMNLeg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocMNLeg& rst, BrlyQLocMNLeg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	virtual void insertRst(ListBrlyQLocMNLeg& rst);
	virtual void updateRec(BrlyQLocMNLeg* rec);
	virtual void updateRst(ListBrlyQLocMNLeg& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMNLeg** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMNLeg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocMNLeg: C++ wrapper for table TblBrlyQLocMNLeg (MySQL database)
	*/
class MyTblBrlyQLocMNLeg : public TblBrlyQLocMNLeg, public Sbecore::MyTable {

public:
	MyTblBrlyQLocMNLeg();
	~MyTblBrlyQLocMNLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMNLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMNLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLocMNLeg* rec);
	void insertRst(ListBrlyQLocMNLeg& rst);
	void updateRec(BrlyQLocMNLeg* rec);
	void updateRst(ListBrlyQLocMNLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMNLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMNLeg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocMNLeg: C++ wrapper for table TblBrlyQLocMNLeg (PgSQL database)
	*/
class PgTblBrlyQLocMNLeg : public TblBrlyQLocMNLeg, public Sbecore::PgTable {

public:
	PgTblBrlyQLocMNLeg();
	~PgTblBrlyQLocMNLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMNLeg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMNLeg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMNLeg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMNLeg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMNLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMNLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLocMNLeg* rec);
	void insertRst(ListBrlyQLocMNLeg& rst);
	void updateRec(BrlyQLocMNLeg* rec);
	void updateRst(ListBrlyQLocMNLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMNLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMNLeg& rst);
};
#endif

#endif
