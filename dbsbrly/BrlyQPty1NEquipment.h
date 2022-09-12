/**
	* \file BrlyQPty1NEquipment.h
	* Dbs and XML wrapper for table TblBrlyQPty1NEquipment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQPTY1NEQUIPMENT_H
#define BRLYQPTY1NEQUIPMENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQPty1NEquipment: record of TblBrlyQPty1NEquipment
	*/
class BrlyQPty1NEquipment {

public:
	BrlyQPty1NEquipment(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListBrlyQPty1NEquipment: recordset of TblBrlyQPty1NEquipment
	*/
class ListBrlyQPty1NEquipment {

public:
	ListBrlyQPty1NEquipment();
	ListBrlyQPty1NEquipment(const ListBrlyQPty1NEquipment& src);
	~ListBrlyQPty1NEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyQPty1NEquipment* rec);

	ListBrlyQPty1NEquipment& operator=(const ListBrlyQPty1NEquipment& src);

public:
	std::vector<BrlyQPty1NEquipment*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQPty1NEquipment: C++ wrapper for table TblBrlyQPty1NEquipment
	*/
class TblBrlyQPty1NEquipment {

public:
	TblBrlyQPty1NEquipment();
	virtual ~TblBrlyQPty1NEquipment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQPty1NEquipment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPty1NEquipment& rst);

	virtual Sbecore::ubigint insertRec(BrlyQPty1NEquipment* rec);
	Sbecore::ubigint insertNewRec(BrlyQPty1NEquipment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQPty1NEquipment& rst, BrlyQPty1NEquipment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQPty1NEquipment& rst);
	virtual void updateRec(BrlyQPty1NEquipment* rec);
	virtual void updateRst(ListBrlyQPty1NEquipment& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQPty1NEquipment** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPty1NEquipment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQPty1NEquipment: C++ wrapper for table TblBrlyQPty1NEquipment (MySQL database)
	*/
class MyTblBrlyQPty1NEquipment : public TblBrlyQPty1NEquipment, public Sbecore::MyTable {

public:
	MyTblBrlyQPty1NEquipment();
	~MyTblBrlyQPty1NEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQPty1NEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPty1NEquipment& rst);

	Sbecore::ubigint insertRec(BrlyQPty1NEquipment* rec);
	void insertRst(ListBrlyQPty1NEquipment& rst);
	void updateRec(BrlyQPty1NEquipment* rec);
	void updateRst(ListBrlyQPty1NEquipment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQPty1NEquipment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPty1NEquipment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQPty1NEquipment: C++ wrapper for table TblBrlyQPty1NEquipment (PgSQL database)
	*/
class PgTblBrlyQPty1NEquipment : public TblBrlyQPty1NEquipment, public Sbecore::PgTable {

public:
	PgTblBrlyQPty1NEquipment();
	~PgTblBrlyQPty1NEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQPty1NEquipment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQPty1NEquipment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQPty1NEquipment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQPty1NEquipment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQPty1NEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQPty1NEquipment& rst);

	Sbecore::ubigint insertRec(BrlyQPty1NEquipment* rec);
	void insertRst(ListBrlyQPty1NEquipment& rst);
	void updateRec(BrlyQPty1NEquipment* rec);
	void updateRst(ListBrlyQPty1NEquipment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQPty1NEquipment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQPty1NEquipment& rst);
};
#endif

#endif
