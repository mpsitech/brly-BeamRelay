/**
	* \file BrlyQLocMNSegment.h
	* Dbs and XML wrapper for table TblBrlyQLocMNSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCMNSEGMENT_H
#define BRLYQLOCMNSEGMENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocMNSegment: record of TblBrlyQLocMNSegment
	*/
class BrlyQLocMNSegment {

public:
	BrlyQLocMNSegment(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);

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
	double x2VisSegphi0;
	double x2VisSegphi1;
	double segphi;
	double segtheta;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocMNSegment: recordset of TblBrlyQLocMNSegment
	*/
class ListBrlyQLocMNSegment {

public:
	ListBrlyQLocMNSegment();
	ListBrlyQLocMNSegment(const ListBrlyQLocMNSegment& src);
	~ListBrlyQLocMNSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMNSegment* rec);

	ListBrlyQLocMNSegment& operator=(const ListBrlyQLocMNSegment& src);

public:
	std::vector<BrlyQLocMNSegment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocMNSegment: C++ wrapper for table TblBrlyQLocMNSegment
	*/
class TblBrlyQLocMNSegment {

public:
	TblBrlyQLocMNSegment();
	virtual ~TblBrlyQLocMNSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMNSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMNSegment& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocMNSegment* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocMNSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocMNSegment& rst, BrlyQLocMNSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);
	virtual void insertRst(ListBrlyQLocMNSegment& rst);
	virtual void updateRec(BrlyQLocMNSegment* rec);
	virtual void updateRst(ListBrlyQLocMNSegment& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMNSegment** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMNSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocMNSegment: C++ wrapper for table TblBrlyQLocMNSegment (MySQL database)
	*/
class MyTblBrlyQLocMNSegment : public TblBrlyQLocMNSegment, public Sbecore::MyTable {

public:
	MyTblBrlyQLocMNSegment();
	~MyTblBrlyQLocMNSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMNSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMNSegment& rst);

	Sbecore::ubigint insertRec(BrlyQLocMNSegment* rec);
	void insertRst(ListBrlyQLocMNSegment& rst);
	void updateRec(BrlyQLocMNSegment* rec);
	void updateRst(ListBrlyQLocMNSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMNSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMNSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocMNSegment: C++ wrapper for table TblBrlyQLocMNSegment (PgSQL database)
	*/
class PgTblBrlyQLocMNSegment : public TblBrlyQLocMNSegment, public Sbecore::PgTable {

public:
	PgTblBrlyQLocMNSegment();
	~PgTblBrlyQLocMNSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMNSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMNSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMNSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMNSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocMNSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocMNSegment& rst);

	Sbecore::ubigint insertRec(BrlyQLocMNSegment* rec);
	void insertRst(ListBrlyQLocMNSegment& rst);
	void updateRec(BrlyQLocMNSegment* rec);
	void updateRst(ListBrlyQLocMNSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocMNSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocMNSegment& rst);
};
#endif

#endif
