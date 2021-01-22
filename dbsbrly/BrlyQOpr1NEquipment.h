/**
	* \file BrlyQOpr1NEquipment.h
	* Dbs and XML wrapper for table TblBrlyQOpr1NEquipment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQOPR1NEQUIPMENT_H
#define BRLYQOPR1NEQUIPMENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQOpr1NEquipment: record of TblBrlyQOpr1NEquipment
	*/
class BrlyQOpr1NEquipment {

public:
	BrlyQOpr1NEquipment(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListBrlyQOpr1NEquipment: recordset of TblBrlyQOpr1NEquipment
	*/
class ListBrlyQOpr1NEquipment {

public:
	ListBrlyQOpr1NEquipment();
	ListBrlyQOpr1NEquipment(const ListBrlyQOpr1NEquipment& src);
	~ListBrlyQOpr1NEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyQOpr1NEquipment* rec);

	ListBrlyQOpr1NEquipment& operator=(const ListBrlyQOpr1NEquipment& src);

public:
	std::vector<BrlyQOpr1NEquipment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQOpr1NEquipment: C++ wrapper for table TblBrlyQOpr1NEquipment
	*/
class TblBrlyQOpr1NEquipment {

public:
	TblBrlyQOpr1NEquipment();
	virtual ~TblBrlyQOpr1NEquipment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQOpr1NEquipment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQOpr1NEquipment& rst);

	virtual Sbecore::ubigint insertRec(BrlyQOpr1NEquipment* rec);
	Sbecore::ubigint insertNewRec(BrlyQOpr1NEquipment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQOpr1NEquipment& rst, BrlyQOpr1NEquipment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQOpr1NEquipment& rst);
	virtual void updateRec(BrlyQOpr1NEquipment* rec);
	virtual void updateRst(ListBrlyQOpr1NEquipment& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQOpr1NEquipment** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQOpr1NEquipment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQOpr1NEquipment: C++ wrapper for table TblBrlyQOpr1NEquipment (MySQL database)
	*/
class MyTblBrlyQOpr1NEquipment : public TblBrlyQOpr1NEquipment, public Sbecore::MyTable {

public:
	MyTblBrlyQOpr1NEquipment();
	~MyTblBrlyQOpr1NEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQOpr1NEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQOpr1NEquipment& rst);

	Sbecore::ubigint insertRec(BrlyQOpr1NEquipment* rec);
	void insertRst(ListBrlyQOpr1NEquipment& rst);
	void updateRec(BrlyQOpr1NEquipment* rec);
	void updateRst(ListBrlyQOpr1NEquipment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQOpr1NEquipment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQOpr1NEquipment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQOpr1NEquipment: C++ wrapper for table TblBrlyQOpr1NEquipment (PgSQL database)
	*/
class PgTblBrlyQOpr1NEquipment : public TblBrlyQOpr1NEquipment, public Sbecore::PgTable {

public:
	PgTblBrlyQOpr1NEquipment();
	~PgTblBrlyQOpr1NEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQOpr1NEquipment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQOpr1NEquipment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQOpr1NEquipment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQOpr1NEquipment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQOpr1NEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQOpr1NEquipment& rst);

	Sbecore::ubigint insertRec(BrlyQOpr1NEquipment* rec);
	void insertRst(ListBrlyQOpr1NEquipment& rst);
	void updateRec(BrlyQOpr1NEquipment* rec);
	void updateRst(ListBrlyQOpr1NEquipment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQOpr1NEquipment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQOpr1NEquipment& rst);
};
#endif

#endif
