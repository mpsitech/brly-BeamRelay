/**
	* \file BrlyQLegOrgMNLeg.h
	* Dbs and XML wrapper for table TblBrlyQLegOrgMNLeg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLEGORGMNLEG_H
#define BRLYQLEGORGMNLEG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLegOrgMNLeg: record of TblBrlyQLegOrgMNLeg
	*/
class BrlyQLegOrgMNLeg {

public:
	BrlyQLegOrgMNLeg(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	double x1VisDstLegphi0;
	double x1VisDstLegphi1;
	double VisOrgLegphi0;
	double VisOrgLegphi1;
	double xVisDstLegphi0;
	double xVisDstLegphi1;
	double xVisOrgLegphi0;
	double xVisOrgLegphi1;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLegOrgMNLeg: recordset of TblBrlyQLegOrgMNLeg
	*/
class ListBrlyQLegOrgMNLeg {

public:
	ListBrlyQLegOrgMNLeg();
	ListBrlyQLegOrgMNLeg(const ListBrlyQLegOrgMNLeg& src);
	~ListBrlyQLegOrgMNLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegOrgMNLeg* rec);

	ListBrlyQLegOrgMNLeg& operator=(const ListBrlyQLegOrgMNLeg& src);

public:
	std::vector<BrlyQLegOrgMNLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLegOrgMNLeg: C++ wrapper for table TblBrlyQLegOrgMNLeg
	*/
class TblBrlyQLegOrgMNLeg {

public:
	TblBrlyQLegOrgMNLeg();
	virtual ~TblBrlyQLegOrgMNLeg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLegOrgMNLeg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegOrgMNLeg& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLegOrgMNLeg* rec);
	Sbecore::ubigint insertNewRec(BrlyQLegOrgMNLeg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLegOrgMNLeg& rst, BrlyQLegOrgMNLeg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);
	virtual void insertRst(ListBrlyQLegOrgMNLeg& rst);
	virtual void updateRec(BrlyQLegOrgMNLeg* rec);
	virtual void updateRst(ListBrlyQLegOrgMNLeg& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegOrgMNLeg** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegOrgMNLeg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLegOrgMNLeg: C++ wrapper for table TblBrlyQLegOrgMNLeg (MySQL database)
	*/
class MyTblBrlyQLegOrgMNLeg : public TblBrlyQLegOrgMNLeg, public Sbecore::MyTable {

public:
	MyTblBrlyQLegOrgMNLeg();
	~MyTblBrlyQLegOrgMNLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegOrgMNLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegOrgMNLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLegOrgMNLeg* rec);
	void insertRst(ListBrlyQLegOrgMNLeg& rst);
	void updateRec(BrlyQLegOrgMNLeg* rec);
	void updateRst(ListBrlyQLegOrgMNLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegOrgMNLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegOrgMNLeg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLegOrgMNLeg: C++ wrapper for table TblBrlyQLegOrgMNLeg (PgSQL database)
	*/
class PgTblBrlyQLegOrgMNLeg : public TblBrlyQLegOrgMNLeg, public Sbecore::PgTable {

public:
	PgTblBrlyQLegOrgMNLeg();
	~PgTblBrlyQLegOrgMNLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegOrgMNLeg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegOrgMNLeg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegOrgMNLeg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegOrgMNLeg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLegOrgMNLeg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLegOrgMNLeg& rst);

	Sbecore::ubigint insertRec(BrlyQLegOrgMNLeg* rec);
	void insertRst(ListBrlyQLegOrgMNLeg& rst);
	void updateRec(BrlyQLegOrgMNLeg* rec);
	void updateRst(ListBrlyQLegOrgMNLeg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLegOrgMNLeg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLegOrgMNLeg& rst);
};
#endif

#endif
