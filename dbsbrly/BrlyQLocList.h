/**
	* \file BrlyQLocList.h
	* Dbs and XML wrapper for table TblBrlyQLocList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCLIST_H
#define BRLYQLOCLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocList: record of TblBrlyQLocList
	*/
class BrlyQLocList {

public:
	BrlyQLocList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refBrlyMRegion = 0, const std::string stubRefBrlyMRegion = "", const Sbecore::ubigint refBrlyMEquipment = 0, const std::string stubRefBrlyMEquipment = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string srefICAO;
	std::string Title;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refBrlyMRegion;
	std::string stubRefBrlyMRegion;
	Sbecore::ubigint refBrlyMEquipment;
	std::string stubRefBrlyMEquipment;
	double alt;
	double theta;
	double phi;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocList: recordset of TblBrlyQLocList
	*/
class ListBrlyQLocList {

public:
	ListBrlyQLocList();
	ListBrlyQLocList(const ListBrlyQLocList& src);
	~ListBrlyQLocList();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocList* rec);

	ListBrlyQLocList& operator=(const ListBrlyQLocList& src);

public:
	std::vector<BrlyQLocList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocList: C++ wrapper for table TblBrlyQLocList
	*/
class TblBrlyQLocList {

public:
	TblBrlyQLocList();
	virtual ~TblBrlyQLocList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocList& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocList* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refBrlyMRegion = 0, const std::string stubRefBrlyMRegion = "", const Sbecore::ubigint refBrlyMEquipment = 0, const std::string stubRefBrlyMEquipment = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocList& rst, BrlyQLocList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string srefICAO = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refBrlyMRegion = 0, const std::string stubRefBrlyMRegion = "", const Sbecore::ubigint refBrlyMEquipment = 0, const std::string stubRefBrlyMEquipment = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0);
	virtual void insertRst(ListBrlyQLocList& rst);
	virtual void updateRec(BrlyQLocList* rec);
	virtual void updateRst(ListBrlyQLocList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocList: C++ wrapper for table TblBrlyQLocList (MySQL database)
	*/
class MyTblBrlyQLocList : public TblBrlyQLocList, public Sbecore::MyTable {

public:
	MyTblBrlyQLocList();
	~MyTblBrlyQLocList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocList& rst);

	Sbecore::ubigint insertRec(BrlyQLocList* rec);
	void insertRst(ListBrlyQLocList& rst);
	void updateRec(BrlyQLocList* rec);
	void updateRst(ListBrlyQLocList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocList: C++ wrapper for table TblBrlyQLocList (PgSQL database)
	*/
class PgTblBrlyQLocList : public TblBrlyQLocList, public Sbecore::PgTable {

public:
	PgTblBrlyQLocList();
	~PgTblBrlyQLocList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocList& rst);

	Sbecore::ubigint insertRec(BrlyQLocList* rec);
	void insertRst(ListBrlyQLocList& rst);
	void updateRec(BrlyQLocList* rec);
	void updateRst(ListBrlyQLocList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocList& rst);
};
#endif

#endif
