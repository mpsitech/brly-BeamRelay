/**
	* \file BrlyMNode.h
	* database access for table TblBrlyMNode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMNODE_H
#define BRLYMNODE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyMNode: record of TblBrlyMNode
	*/
class BrlyMNode {

public:
	BrlyMNode(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refBrlyMRelay = 0, const Sbecore::ubigint supRefBrlyMNode = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::uint supNum = 0, const Sbecore::ubigint refBrlyMEquipment = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refBrlyMRelay;
	Sbecore::ubigint supRefBrlyMNode;
	Sbecore::usmallint supLvl;
	Sbecore::uint supNum;
	Sbecore::ubigint refBrlyMEquipment;

public:
	bool operator==(const BrlyMNode& comp);
	bool operator!=(const BrlyMNode& comp);
};

/**
	* ListBrlyMNode: recordset of TblBrlyMNode
	*/
class ListBrlyMNode {

public:
	ListBrlyMNode();
	ListBrlyMNode(const ListBrlyMNode& src);
	~ListBrlyMNode();

	void clear();
	unsigned int size() const;
	void append(BrlyMNode* rec);

	BrlyMNode* operator[](const Sbecore::uint ix);
	ListBrlyMNode& operator=(const ListBrlyMNode& src);
	bool operator==(const ListBrlyMNode& comp);
	bool operator!=(const ListBrlyMNode& comp);

public:
	std::vector<BrlyMNode*> nodes;
};

/**
	* TblBrlyMNode: C++ wrapper for table TblBrlyMNode
	*/
class TblBrlyMNode {

public:

public:
	TblBrlyMNode();
	virtual ~TblBrlyMNode();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMNode** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMNode& rst);

	virtual Sbecore::ubigint insertRec(BrlyMNode* rec);
	Sbecore::ubigint insertNewRec(BrlyMNode** rec = NULL, const Sbecore::ubigint refBrlyMRelay = 0, const Sbecore::ubigint supRefBrlyMNode = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::uint supNum = 0, const Sbecore::ubigint refBrlyMEquipment = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyMNode& rst, BrlyMNode** rec = NULL, const Sbecore::ubigint refBrlyMRelay = 0, const Sbecore::ubigint supRefBrlyMNode = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::uint supNum = 0, const Sbecore::ubigint refBrlyMEquipment = 0);
	virtual void insertRst(ListBrlyMNode& rst, bool transact = false);
	virtual void updateRec(BrlyMNode* rec);
	virtual void updateRst(ListBrlyMNode& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMNode** rec);
	virtual bool confirmByRef(Sbecore::ubigint ref);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefBrlyMNode, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByRly(Sbecore::ubigint refBrlyMRelay, const bool append, ListBrlyMNode& rst);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefBrlyMNode, const bool append, ListBrlyMNode& rst);
	virtual bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefBrlyMNode);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMNode& rst);
	Sbecore::ubigint loadHrefsup(Sbecore::ubigint ref, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadHrefsdown(Sbecore::ubigint ref, const bool append, std::vector<Sbecore::ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	Sbecore::ubigint loadHrstup(Sbecore::ubigint ref, ListBrlyMNode& rst);
	Sbecore::ubigint loadHrstdown(Sbecore::ubigint ref, const bool append, ListBrlyMNode& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMNode: C++ wrapper for table TblBrlyMNode (MySQL database)
	*/
class MyTblBrlyMNode : public TblBrlyMNode, public Sbecore::MyTable {

public:
	MyTblBrlyMNode();
	~MyTblBrlyMNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMNode& rst);

	Sbecore::ubigint insertRec(BrlyMNode* rec);
	void insertRst(ListBrlyMNode& rst, bool transact = false);
	void updateRec(BrlyMNode* rec);
	void updateRst(ListBrlyMNode& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMNode** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefBrlyMNode, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRly(Sbecore::ubigint refBrlyMRelay, const bool append, ListBrlyMNode& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefBrlyMNode, const bool append, ListBrlyMNode& rst);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefBrlyMNode);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMNode: C++ wrapper for table TblBrlyMNode (PgSQL database)
	*/
class PgTblBrlyMNode : public TblBrlyMNode, public Sbecore::PgTable {

public:
	PgTblBrlyMNode();
	~PgTblBrlyMNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMNode** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMNode& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMNode** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMNode& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMNode& rst);

	Sbecore::ubigint insertRec(BrlyMNode* rec);
	void insertRst(ListBrlyMNode& rst, bool transact = false);
	void updateRec(BrlyMNode* rec);
	void updateRst(ListBrlyMNode& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMNode** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefBrlyMNode, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRly(Sbecore::ubigint refBrlyMRelay, const bool append, ListBrlyMNode& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefBrlyMNode, const bool append, ListBrlyMNode& rst);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefBrlyMNode);
};
#endif

#endif
