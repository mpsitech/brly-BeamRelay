/**
	* \file BrlyQSegMNLocation.h
	* Dbs and XML wrapper for table TblBrlyQSegMNLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQSEGMNLOCATION_H
#define BRLYQSEGMNLOCATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQSegMNLocation: record of TblBrlyQSegMNLocation
	*/
class BrlyQSegMNLocation {

public:
	BrlyQSegMNLocation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);

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
	* ListBrlyQSegMNLocation: recordset of TblBrlyQSegMNLocation
	*/
class ListBrlyQSegMNLocation {

public:
	ListBrlyQSegMNLocation();
	ListBrlyQSegMNLocation(const ListBrlyQSegMNLocation& src);
	~ListBrlyQSegMNLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQSegMNLocation* rec);

	ListBrlyQSegMNLocation& operator=(const ListBrlyQSegMNLocation& src);

public:
	std::vector<BrlyQSegMNLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQSegMNLocation: C++ wrapper for table TblBrlyQSegMNLocation
	*/
class TblBrlyQSegMNLocation {

public:
	TblBrlyQSegMNLocation();
	virtual ~TblBrlyQSegMNLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQSegMNLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegMNLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyQSegMNLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyQSegMNLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQSegMNLocation& rst, BrlyQSegMNLocation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const std::string ftmX1Start = "", const Sbecore::uint x1Stop = 0, const std::string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);
	virtual void insertRst(ListBrlyQSegMNLocation& rst);
	virtual void updateRec(BrlyQSegMNLocation* rec);
	virtual void updateRst(ListBrlyQSegMNLocation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegMNLocation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegMNLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQSegMNLocation: C++ wrapper for table TblBrlyQSegMNLocation (MySQL database)
	*/
class MyTblBrlyQSegMNLocation : public TblBrlyQSegMNLocation, public Sbecore::MyTable {

public:
	MyTblBrlyQSegMNLocation();
	~MyTblBrlyQSegMNLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQSegMNLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegMNLocation& rst);

	Sbecore::ubigint insertRec(BrlyQSegMNLocation* rec);
	void insertRst(ListBrlyQSegMNLocation& rst);
	void updateRec(BrlyQSegMNLocation* rec);
	void updateRst(ListBrlyQSegMNLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegMNLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegMNLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQSegMNLocation: C++ wrapper for table TblBrlyQSegMNLocation (PgSQL database)
	*/
class PgTblBrlyQSegMNLocation : public TblBrlyQSegMNLocation, public Sbecore::PgTable {

public:
	PgTblBrlyQSegMNLocation();
	~PgTblBrlyQSegMNLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQSegMNLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQSegMNLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQSegMNLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQSegMNLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQSegMNLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQSegMNLocation& rst);

	Sbecore::ubigint insertRec(BrlyQSegMNLocation* rec);
	void insertRst(ListBrlyQSegMNLocation& rst);
	void updateRec(BrlyQSegMNLocation* rec);
	void updateRst(ListBrlyQSegMNLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQSegMNLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQSegMNLocation& rst);
};
#endif

#endif
