/**
	* \file BrlyQFltEqp1NNode.h
	* Dbs and XML wrapper for table TblBrlyQFltEqp1NNode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQFLTEQP1NNODE_H
#define BRLYQFLTEQP1NNODE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQFltEqp1NNode: record of TblBrlyQFltEqp1NNode
	*/
class BrlyQFltEqp1NNode {

public:
	BrlyQFltEqp1NNode(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQFltEqp1NNode: recordset of TblBrlyQFltEqp1NNode
	*/
class ListBrlyQFltEqp1NNode {

public:
	ListBrlyQFltEqp1NNode();
	ListBrlyQFltEqp1NNode(const ListBrlyQFltEqp1NNode& src);
	~ListBrlyQFltEqp1NNode();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltEqp1NNode* rec);

	ListBrlyQFltEqp1NNode& operator=(const ListBrlyQFltEqp1NNode& src);

public:
	std::vector<BrlyQFltEqp1NNode*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQFltEqp1NNode: C++ wrapper for table TblBrlyQFltEqp1NNode
	*/
class TblBrlyQFltEqp1NNode {

public:
	TblBrlyQFltEqp1NNode();
	virtual ~TblBrlyQFltEqp1NNode();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQFltEqp1NNode** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltEqp1NNode& rst);

	virtual Sbecore::ubigint insertRec(BrlyQFltEqp1NNode* rec);
	Sbecore::ubigint insertNewRec(BrlyQFltEqp1NNode** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQFltEqp1NNode& rst, BrlyQFltEqp1NNode** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQFltEqp1NNode& rst);
	virtual void updateRec(BrlyQFltEqp1NNode* rec);
	virtual void updateRst(ListBrlyQFltEqp1NNode& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltEqp1NNode** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltEqp1NNode& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQFltEqp1NNode: C++ wrapper for table TblBrlyQFltEqp1NNode (MySQL database)
	*/
class MyTblBrlyQFltEqp1NNode : public TblBrlyQFltEqp1NNode, public Sbecore::MyTable {

public:
	MyTblBrlyQFltEqp1NNode();
	~MyTblBrlyQFltEqp1NNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltEqp1NNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltEqp1NNode& rst);

	Sbecore::ubigint insertRec(BrlyQFltEqp1NNode* rec);
	void insertRst(ListBrlyQFltEqp1NNode& rst);
	void updateRec(BrlyQFltEqp1NNode* rec);
	void updateRst(ListBrlyQFltEqp1NNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltEqp1NNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltEqp1NNode& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQFltEqp1NNode: C++ wrapper for table TblBrlyQFltEqp1NNode (PgSQL database)
	*/
class PgTblBrlyQFltEqp1NNode : public TblBrlyQFltEqp1NNode, public Sbecore::PgTable {

public:
	PgTblBrlyQFltEqp1NNode();
	~PgTblBrlyQFltEqp1NNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltEqp1NNode** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltEqp1NNode& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltEqp1NNode** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltEqp1NNode& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQFltEqp1NNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQFltEqp1NNode& rst);

	Sbecore::ubigint insertRec(BrlyQFltEqp1NNode* rec);
	void insertRst(ListBrlyQFltEqp1NNode& rst);
	void updateRec(BrlyQFltEqp1NNode* rec);
	void updateRst(ListBrlyQFltEqp1NNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQFltEqp1NNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQFltEqp1NNode& rst);
};
#endif

#endif
