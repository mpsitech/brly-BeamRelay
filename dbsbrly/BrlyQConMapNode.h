/**
	* \file BrlyQConMapNode.h
	* Dbs and XML wrapper for table TblBrlyQConMapNode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCONMAPNODE_H
#define BRLYQCONMAPNODE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQConMapNode: record of TblBrlyQConMapNode
	*/
class BrlyQConMapNode {

public:
	BrlyQConMapNode(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::ubigint refBrlyMRelay = 0, const Sbecore::ubigint supRefBrlyMNode = 0, const Sbecore::ubigint refBrlyMEquipment = 0, const int jnumRly = 0, const double x0 = 0.0, const double y0 = 0.0, const double u0 = 0.0, const double v0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const double du = 0.0, const double dv = 0.0, const int dt = 0);

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::ubigint refBrlyMRelay;
	Sbecore::ubigint supRefBrlyMNode;
	Sbecore::ubigint refBrlyMEquipment;
	int jnumRly;
	double x0;
	double y0;
	double u0;
	double v0;
	int t0;
	double dx;
	double dy;
	double du;
	double dv;
	int dt;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQConMapNode: recordset of TblBrlyQConMapNode
	*/
class ListBrlyQConMapNode {

public:
	ListBrlyQConMapNode();
	ListBrlyQConMapNode(const ListBrlyQConMapNode& src);
	~ListBrlyQConMapNode();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMapNode* rec);

	ListBrlyQConMapNode& operator=(const ListBrlyQConMapNode& src);

public:
	std::vector<BrlyQConMapNode*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQConMapNode: C++ wrapper for table TblBrlyQConMapNode
	*/
class TblBrlyQConMapNode {

public:
	TblBrlyQConMapNode();
	virtual ~TblBrlyQConMapNode();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapNode** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapNode& rst);

	virtual Sbecore::ubigint insertRec(BrlyQConMapNode* rec);
	Sbecore::ubigint insertNewRec(BrlyQConMapNode** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::ubigint refBrlyMRelay = 0, const Sbecore::ubigint supRefBrlyMNode = 0, const Sbecore::ubigint refBrlyMEquipment = 0, const int jnumRly = 0, const double x0 = 0.0, const double y0 = 0.0, const double u0 = 0.0, const double v0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const double du = 0.0, const double dv = 0.0, const int dt = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQConMapNode& rst, BrlyQConMapNode** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::ubigint refBrlyMRelay = 0, const Sbecore::ubigint supRefBrlyMNode = 0, const Sbecore::ubigint refBrlyMEquipment = 0, const int jnumRly = 0, const double x0 = 0.0, const double y0 = 0.0, const double u0 = 0.0, const double v0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const double du = 0.0, const double dv = 0.0, const int dt = 0);
	virtual void insertRst(ListBrlyQConMapNode& rst);
	virtual void updateRec(BrlyQConMapNode* rec);
	virtual void updateRst(ListBrlyQConMapNode& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapNode** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapNode& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQConMapNode: C++ wrapper for table TblBrlyQConMapNode (MySQL database)
	*/
class MyTblBrlyQConMapNode : public TblBrlyQConMapNode, public Sbecore::MyTable {

public:
	MyTblBrlyQConMapNode();
	~MyTblBrlyQConMapNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapNode& rst);

	Sbecore::ubigint insertRec(BrlyQConMapNode* rec);
	void insertRst(ListBrlyQConMapNode& rst);
	void updateRec(BrlyQConMapNode* rec);
	void updateRst(ListBrlyQConMapNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapNode& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQConMapNode: C++ wrapper for table TblBrlyQConMapNode (PgSQL database)
	*/
class PgTblBrlyQConMapNode : public TblBrlyQConMapNode, public Sbecore::PgTable {

public:
	PgTblBrlyQConMapNode();
	~PgTblBrlyQConMapNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMapNode** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMapNode& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMapNode** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMapNode& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConMapNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConMapNode& rst);

	Sbecore::ubigint insertRec(BrlyQConMapNode* rec);
	void insertRst(ListBrlyQConMapNode& rst);
	void updateRec(BrlyQConMapNode* rec);
	void updateRst(ListBrlyQConMapNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConMapNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConMapNode& rst);
};
#endif

#endif
