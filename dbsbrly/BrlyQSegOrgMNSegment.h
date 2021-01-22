/**
	* \file BrlyQSegOrgMNSegment.h
	* Dbs and XML wrapper for table TblBrlyQSegOrgMNSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQSEGORGMNSEGMENT_H
#define BRLYQSEGORGMNSEGMENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQSegOrgMNSegment: record of TblBrlyQSegOrgMNSegment
	*/
class BrlyQSegOrgMNSegment {

public:
	BrlyQSegOrgMNSegment(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);

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
	double x2VisDstSegphi0;
	double x2VisDstSegphi1;
	double VisOrgSegphi0;
	double VisOrgSegphi1;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQSegOrgMNSegment: recordset of TblBrlyQSegOrgMNSegment
	*/
class ListBrlyQSegOrgMNSegment {

public:
	ListBrlyQSegOrgMNSegment();
	ListBrlyQSegOrgMNSegment(const ListBrlyQSegOrgMNSegment& src);
	~ListBrlyQSegOrgMNSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyQSegOrgMNSegment* rec);

	ListBrlyQSegOrgMNSegment& operator=(const ListBrlyQSegOrgMNSegment& src);

public:
	std::vector<BrlyQSegOrgMNSegment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQSegOrgMNSegment: C++ wrapper for table TblBrlyQSegOrgMNSegment
	*/
class TblBrlyQSegOrgMNSegment {

public:
	TblBrlyQSegOrgMNSegment();
	virtual ~TblBrlyQSegOrgMNSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQSegOrgMNSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegOrgMNSegment& rst);

	virtual Sbecore::ubigint insertRec(BrlyQSegOrgMNSegment* rec);
	Sbecore::ubigint insertNewRec(BrlyQSegOrgMNSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQSegOrgMNSegment& rst, BrlyQSegOrgMNSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);
	virtual void insertRst(ListBrlyQSegOrgMNSegment& rst);
	virtual void updateRec(BrlyQSegOrgMNSegment* rec);
	virtual void updateRst(ListBrlyQSegOrgMNSegment& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegOrgMNSegment** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegOrgMNSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQSegOrgMNSegment: C++ wrapper for table TblBrlyQSegOrgMNSegment (MySQL database)
	*/
class MyTblBrlyQSegOrgMNSegment : public TblBrlyQSegOrgMNSegment, public Sbecore::MyTable {

public:
	MyTblBrlyQSegOrgMNSegment();
	~MyTblBrlyQSegOrgMNSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQSegOrgMNSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegOrgMNSegment& rst);

	Sbecore::ubigint insertRec(BrlyQSegOrgMNSegment* rec);
	void insertRst(ListBrlyQSegOrgMNSegment& rst);
	void updateRec(BrlyQSegOrgMNSegment* rec);
	void updateRst(ListBrlyQSegOrgMNSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegOrgMNSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegOrgMNSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQSegOrgMNSegment: C++ wrapper for table TblBrlyQSegOrgMNSegment (PgSQL database)
	*/
class PgTblBrlyQSegOrgMNSegment : public TblBrlyQSegOrgMNSegment, public Sbecore::PgTable {

public:
	PgTblBrlyQSegOrgMNSegment();
	~PgTblBrlyQSegOrgMNSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQSegOrgMNSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQSegOrgMNSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQSegOrgMNSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQSegOrgMNSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQSegOrgMNSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegOrgMNSegment& rst);

	Sbecore::ubigint insertRec(BrlyQSegOrgMNSegment* rec);
	void insertRst(ListBrlyQSegOrgMNSegment& rst);
	void updateRec(BrlyQSegOrgMNSegment* rec);
	void updateRst(ListBrlyQSegOrgMNSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegOrgMNSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegOrgMNSegment& rst);
};
#endif

#endif
