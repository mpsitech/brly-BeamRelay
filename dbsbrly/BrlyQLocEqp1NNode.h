/**
	* \file BrlyQLocEqp1NNode.h
	* Dbs and XML wrapper for table TblBrlyQLocEqp1NNode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQLOCEQP1NNODE_H
#define BRLYQLOCEQP1NNODE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQLocEqp1NNode: record of TblBrlyQLocEqp1NNode
	*/
class BrlyQLocEqp1NNode {

public:
	BrlyQLocEqp1NNode(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQLocEqp1NNode: recordset of TblBrlyQLocEqp1NNode
	*/
class ListBrlyQLocEqp1NNode {

public:
	ListBrlyQLocEqp1NNode();
	ListBrlyQLocEqp1NNode(const ListBrlyQLocEqp1NNode& src);
	~ListBrlyQLocEqp1NNode();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocEqp1NNode* rec);

	ListBrlyQLocEqp1NNode& operator=(const ListBrlyQLocEqp1NNode& src);

public:
	std::vector<BrlyQLocEqp1NNode*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQLocEqp1NNode: C++ wrapper for table TblBrlyQLocEqp1NNode
	*/
class TblBrlyQLocEqp1NNode {

public:
	TblBrlyQLocEqp1NNode();
	virtual ~TblBrlyQLocEqp1NNode();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQLocEqp1NNode** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocEqp1NNode& rst);

	virtual Sbecore::ubigint insertRec(BrlyQLocEqp1NNode* rec);
	Sbecore::ubigint insertNewRec(BrlyQLocEqp1NNode** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQLocEqp1NNode& rst, BrlyQLocEqp1NNode** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQLocEqp1NNode& rst);
	virtual void updateRec(BrlyQLocEqp1NNode* rec);
	virtual void updateRst(ListBrlyQLocEqp1NNode& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocEqp1NNode** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocEqp1NNode& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQLocEqp1NNode: C++ wrapper for table TblBrlyQLocEqp1NNode (MySQL database)
	*/
class MyTblBrlyQLocEqp1NNode : public TblBrlyQLocEqp1NNode, public Sbecore::MyTable {

public:
	MyTblBrlyQLocEqp1NNode();
	~MyTblBrlyQLocEqp1NNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocEqp1NNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocEqp1NNode& rst);

	Sbecore::ubigint insertRec(BrlyQLocEqp1NNode* rec);
	void insertRst(ListBrlyQLocEqp1NNode& rst);
	void updateRec(BrlyQLocEqp1NNode* rec);
	void updateRst(ListBrlyQLocEqp1NNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocEqp1NNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocEqp1NNode& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQLocEqp1NNode: C++ wrapper for table TblBrlyQLocEqp1NNode (PgSQL database)
	*/
class PgTblBrlyQLocEqp1NNode : public TblBrlyQLocEqp1NNode, public Sbecore::PgTable {

public:
	PgTblBrlyQLocEqp1NNode();
	~PgTblBrlyQLocEqp1NNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocEqp1NNode** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocEqp1NNode& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocEqp1NNode** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocEqp1NNode& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQLocEqp1NNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQLocEqp1NNode& rst);

	Sbecore::ubigint insertRec(BrlyQLocEqp1NNode* rec);
	void insertRst(ListBrlyQLocEqp1NNode& rst);
	void updateRec(BrlyQLocEqp1NNode* rec);
	void updateRst(ListBrlyQLocEqp1NNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQLocEqp1NNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQLocEqp1NNode& rst);
};
#endif

#endif
