/**
	* \file BrlyQConMapLocation.h
	* Dbs and XML wrapper for table TblBrlyQConMapLocation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCONMAPLOCATION_H
#define BRLYQCONMAPLOCATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQConMapLocation: record of TblBrlyQConMapLocation
	*/
class BrlyQConMapLocation {

public:
	BrlyQConMapLocation(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mrefBrlyMEquipment = 0, const double x = 0.0, const double y = 0.0);

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	double legphi;
	double legtheta;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint mrefBrlyMEquipment;
	double x;
	double y;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQConMapLocation: recordset of TblBrlyQConMapLocation
	*/
class ListBrlyQConMapLocation {

public:
	ListBrlyQConMapLocation();
	ListBrlyQConMapLocation(const ListBrlyQConMapLocation& src);
	~ListBrlyQConMapLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMapLocation* rec);

	ListBrlyQConMapLocation& operator=(const ListBrlyQConMapLocation& src);

public:
	std::vector<BrlyQConMapLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQConMapLocation: C++ wrapper for table TblBrlyQConMapLocation
	*/
class TblBrlyQConMapLocation {

public:
	TblBrlyQConMapLocation();
	virtual ~TblBrlyQConMapLocation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapLocation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapLocation& rst);

	virtual Sbecore::ubigint insertRec(BrlyQConMapLocation* rec);
	Sbecore::ubigint insertNewRec(BrlyQConMapLocation** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mrefBrlyMEquipment = 0, const double x = 0.0, const double y = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQConMapLocation& rst, BrlyQConMapLocation** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mrefBrlyMEquipment = 0, const double x = 0.0, const double y = 0.0);
	virtual void insertRst(ListBrlyQConMapLocation& rst);
	virtual void updateRec(BrlyQConMapLocation* rec);
	virtual void updateRst(ListBrlyQConMapLocation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapLocation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapLocation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQConMapLocation: C++ wrapper for table TblBrlyQConMapLocation (MySQL database)
	*/
class MyTblBrlyQConMapLocation : public TblBrlyQConMapLocation, public Sbecore::MyTable {

public:
	MyTblBrlyQConMapLocation();
	~MyTblBrlyQConMapLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapLocation& rst);

	Sbecore::ubigint insertRec(BrlyQConMapLocation* rec);
	void insertRst(ListBrlyQConMapLocation& rst);
	void updateRec(BrlyQConMapLocation* rec);
	void updateRst(ListBrlyQConMapLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapLocation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQConMapLocation: C++ wrapper for table TblBrlyQConMapLocation (PgSQL database)
	*/
class PgTblBrlyQConMapLocation : public TblBrlyQConMapLocation, public Sbecore::PgTable {

public:
	PgTblBrlyQConMapLocation();
	~PgTblBrlyQConMapLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMapLocation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMapLocation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMapLocation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMapLocation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapLocation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapLocation& rst);

	Sbecore::ubigint insertRec(BrlyQConMapLocation* rec);
	void insertRst(ListBrlyQConMapLocation& rst);
	void updateRec(BrlyQConMapLocation* rec);
	void updateRst(ListBrlyQConMapLocation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapLocation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapLocation& rst);
};
#endif

#endif
