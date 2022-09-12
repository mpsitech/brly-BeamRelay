/**
	* \file BrlyQConMNSegment.h
	* Dbs and XML wrapper for table TblBrlyQConMNSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCONMNSEGMENT_H
#define BRLYQCONMNSEGMENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQConMNSegment: record of TblBrlyQConMNSegment
	*/
class BrlyQConMNSegment {

public:
	BrlyQConMNSegment(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

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
	* ListBrlyQConMNSegment: recordset of TblBrlyQConMNSegment
	*/
class ListBrlyQConMNSegment {

public:
	ListBrlyQConMNSegment();
	ListBrlyQConMNSegment(const ListBrlyQConMNSegment& src);
	~ListBrlyQConMNSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMNSegment* rec);

	ListBrlyQConMNSegment& operator=(const ListBrlyQConMNSegment& src);

public:
	std::vector<BrlyQConMNSegment*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQConMNSegment: C++ wrapper for table TblBrlyQConMNSegment
	*/
class TblBrlyQConMNSegment {

public:
	TblBrlyQConMNSegment();
	virtual ~TblBrlyQConMNSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQConMNSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMNSegment& rst);

	virtual Sbecore::ubigint insertRec(BrlyQConMNSegment* rec);
	Sbecore::ubigint insertNewRec(BrlyQConMNSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQConMNSegment& rst, BrlyQConMNSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	virtual void insertRst(ListBrlyQConMNSegment& rst);
	virtual void updateRec(BrlyQConMNSegment* rec);
	virtual void updateRst(ListBrlyQConMNSegment& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMNSegment** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMNSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQConMNSegment: C++ wrapper for table TblBrlyQConMNSegment (MySQL database)
	*/
class MyTblBrlyQConMNSegment : public TblBrlyQConMNSegment, public Sbecore::MyTable {

public:
	MyTblBrlyQConMNSegment();
	~MyTblBrlyQConMNSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMNSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMNSegment& rst);

	Sbecore::ubigint insertRec(BrlyQConMNSegment* rec);
	void insertRst(ListBrlyQConMNSegment& rst);
	void updateRec(BrlyQConMNSegment* rec);
	void updateRst(ListBrlyQConMNSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMNSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMNSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQConMNSegment: C++ wrapper for table TblBrlyQConMNSegment (PgSQL database)
	*/
class PgTblBrlyQConMNSegment : public TblBrlyQConMNSegment, public Sbecore::PgTable {

public:
	PgTblBrlyQConMNSegment();
	~PgTblBrlyQConMNSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMNSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMNSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMNSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMNSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMNSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMNSegment& rst);

	Sbecore::ubigint insertRec(BrlyQConMNSegment* rec);
	void insertRst(ListBrlyQConMNSegment& rst);
	void updateRec(BrlyQConMNSegment* rec);
	void updateRst(ListBrlyQConMNSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMNSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMNSegment& rst);
};
#endif

#endif
