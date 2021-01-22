/**
	* \file BrlyQRly1NNode.h
	* Dbs and XML wrapper for table TblBrlyQRly1NNode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQRLY1NNODE_H
#define BRLYQRLY1NNODE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQRly1NNode: record of TblBrlyQRly1NNode
	*/
class BrlyQRly1NNode {

public:
	BrlyQRly1NNode(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListBrlyQRly1NNode: recordset of TblBrlyQRly1NNode
	*/
class ListBrlyQRly1NNode {

public:
	ListBrlyQRly1NNode();
	ListBrlyQRly1NNode(const ListBrlyQRly1NNode& src);
	~ListBrlyQRly1NNode();

	void clear();
	unsigned int size() const;
	void append(BrlyQRly1NNode* rec);

	ListBrlyQRly1NNode& operator=(const ListBrlyQRly1NNode& src);

public:
	std::vector<BrlyQRly1NNode*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQRly1NNode: C++ wrapper for table TblBrlyQRly1NNode
	*/
class TblBrlyQRly1NNode {

public:
	TblBrlyQRly1NNode();
	virtual ~TblBrlyQRly1NNode();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQRly1NNode** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRly1NNode& rst);

	virtual Sbecore::ubigint insertRec(BrlyQRly1NNode* rec);
	Sbecore::ubigint insertNewRec(BrlyQRly1NNode** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQRly1NNode& rst, BrlyQRly1NNode** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQRly1NNode& rst);
	virtual void updateRec(BrlyQRly1NNode* rec);
	virtual void updateRst(ListBrlyQRly1NNode& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQRly1NNode** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRly1NNode& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQRly1NNode: C++ wrapper for table TblBrlyQRly1NNode (MySQL database)
	*/
class MyTblBrlyQRly1NNode : public TblBrlyQRly1NNode, public Sbecore::MyTable {

public:
	MyTblBrlyQRly1NNode();
	~MyTblBrlyQRly1NNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQRly1NNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRly1NNode& rst);

	Sbecore::ubigint insertRec(BrlyQRly1NNode* rec);
	void insertRst(ListBrlyQRly1NNode& rst);
	void updateRec(BrlyQRly1NNode* rec);
	void updateRst(ListBrlyQRly1NNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQRly1NNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRly1NNode& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQRly1NNode: C++ wrapper for table TblBrlyQRly1NNode (PgSQL database)
	*/
class PgTblBrlyQRly1NNode : public TblBrlyQRly1NNode, public Sbecore::PgTable {

public:
	PgTblBrlyQRly1NNode();
	~PgTblBrlyQRly1NNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQRly1NNode** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQRly1NNode& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQRly1NNode** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQRly1NNode& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQRly1NNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQRly1NNode& rst);

	Sbecore::ubigint insertRec(BrlyQRly1NNode* rec);
	void insertRst(ListBrlyQRly1NNode& rst);
	void updateRec(BrlyQRly1NNode* rec);
	void updateRst(ListBrlyQRly1NNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQRly1NNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQRly1NNode& rst);
};
#endif

#endif
