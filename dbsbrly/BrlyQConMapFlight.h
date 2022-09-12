/**
	* \file BrlyQConMapFlight.h
	* Dbs and XML wrapper for table TblBrlyQConMapFlight (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCONMAPFLIGHT_H
#define BRLYQCONMAPFLIGHT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQConMapFlight: record of TblBrlyQConMapFlight
	*/
class BrlyQConMapFlight {

public:
	BrlyQConMapFlight(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mrefBrlyMEquipment = 0, const Sbecore::ubigint mrefBrlyMLeg = 0, const Sbecore::uint mstart = 0, const Sbecore::uint mstop = 0, const double x0 = 0.0, const double y0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const int dt = 0);

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1Start;
	Sbecore::uint x1Stop;
	double x2Legphi0;
	double x2Legphi1;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint mrefBrlyMEquipment;
	Sbecore::ubigint mrefBrlyMLeg;
	Sbecore::uint mstart;
	Sbecore::uint mstop;
	double x0;
	double y0;
	int t0;
	double dx;
	double dy;
	int dt;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQConMapFlight: recordset of TblBrlyQConMapFlight
	*/
class ListBrlyQConMapFlight {

public:
	ListBrlyQConMapFlight();
	ListBrlyQConMapFlight(const ListBrlyQConMapFlight& src);
	~ListBrlyQConMapFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMapFlight* rec);

	ListBrlyQConMapFlight& operator=(const ListBrlyQConMapFlight& src);

public:
	std::vector<BrlyQConMapFlight*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQConMapFlight: C++ wrapper for table TblBrlyQConMapFlight
	*/
class TblBrlyQConMapFlight {

public:
	TblBrlyQConMapFlight();
	virtual ~TblBrlyQConMapFlight();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapFlight** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapFlight& rst);

	virtual Sbecore::ubigint insertRec(BrlyQConMapFlight* rec);
	Sbecore::ubigint insertNewRec(BrlyQConMapFlight** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mrefBrlyMEquipment = 0, const Sbecore::ubigint mrefBrlyMLeg = 0, const Sbecore::uint mstart = 0, const Sbecore::uint mstop = 0, const double x0 = 0.0, const double y0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const int dt = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQConMapFlight& rst, BrlyQConMapFlight** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint mrefBrlyMEquipment = 0, const Sbecore::ubigint mrefBrlyMLeg = 0, const Sbecore::uint mstart = 0, const Sbecore::uint mstop = 0, const double x0 = 0.0, const double y0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const int dt = 0);
	virtual void insertRst(ListBrlyQConMapFlight& rst);
	virtual void updateRec(BrlyQConMapFlight* rec);
	virtual void updateRst(ListBrlyQConMapFlight& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapFlight** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapFlight& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQConMapFlight: C++ wrapper for table TblBrlyQConMapFlight (MySQL database)
	*/
class MyTblBrlyQConMapFlight : public TblBrlyQConMapFlight, public Sbecore::MyTable {

public:
	MyTblBrlyQConMapFlight();
	~MyTblBrlyQConMapFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapFlight& rst);

	Sbecore::ubigint insertRec(BrlyQConMapFlight* rec);
	void insertRst(ListBrlyQConMapFlight& rst);
	void updateRec(BrlyQConMapFlight* rec);
	void updateRst(ListBrlyQConMapFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapFlight& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQConMapFlight: C++ wrapper for table TblBrlyQConMapFlight (PgSQL database)
	*/
class PgTblBrlyQConMapFlight : public TblBrlyQConMapFlight, public Sbecore::PgTable {

public:
	PgTblBrlyQConMapFlight();
	~PgTblBrlyQConMapFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMapFlight** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMapFlight& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMapFlight** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMapFlight& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapFlight** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapFlight& rst);

	Sbecore::ubigint insertRec(BrlyQConMapFlight* rec);
	void insertRst(ListBrlyQConMapFlight& rst);
	void updateRec(BrlyQConMapFlight* rec);
	void updateRst(ListBrlyQConMapFlight& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapFlight** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapFlight& rst);
};
#endif

#endif
