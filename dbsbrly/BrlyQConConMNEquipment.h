/**
	* \file BrlyQConConMNEquipment.h
	* Dbs and XML wrapper for table TblBrlyQConConMNEquipment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQCONCONMNEQUIPMENT_H
#define BRLYQCONCONMNEQUIPMENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQConConMNEquipment: record of TblBrlyQConConMNEquipment
	*/
class BrlyQConConMNEquipment {

public:
	BrlyQConConMNEquipment(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint conIxBrlyVLat = 0, const std::string srefConIxBrlyVLat = "", const Sbecore::uint conNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint conIxBrlyVLat;
	std::string srefConIxBrlyVLat;
	Sbecore::uint conNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListBrlyQConConMNEquipment: recordset of TblBrlyQConConMNEquipment
	*/
class ListBrlyQConConMNEquipment {

public:
	ListBrlyQConConMNEquipment();
	ListBrlyQConConMNEquipment(const ListBrlyQConConMNEquipment& src);
	~ListBrlyQConConMNEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyQConConMNEquipment* rec);

	ListBrlyQConConMNEquipment& operator=(const ListBrlyQConConMNEquipment& src);

public:
	std::vector<BrlyQConConMNEquipment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQConConMNEquipment: C++ wrapper for table TblBrlyQConConMNEquipment
	*/
class TblBrlyQConConMNEquipment {

public:
	TblBrlyQConConMNEquipment();
	virtual ~TblBrlyQConConMNEquipment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQConConMNEquipment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConConMNEquipment& rst);

	virtual Sbecore::ubigint insertRec(BrlyQConConMNEquipment* rec);
	Sbecore::ubigint insertNewRec(BrlyQConConMNEquipment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint conIxBrlyVLat = 0, const std::string srefConIxBrlyVLat = "", const Sbecore::uint conNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListBrlyQConConMNEquipment& rst, BrlyQConConMNEquipment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint conIxBrlyVLat = 0, const std::string srefConIxBrlyVLat = "", const Sbecore::uint conNum = 0);
	virtual void insertRst(ListBrlyQConConMNEquipment& rst);
	virtual void updateRec(BrlyQConConMNEquipment* rec);
	virtual void updateRst(ListBrlyQConConMNEquipment& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQConConMNEquipment** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConConMNEquipment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQConConMNEquipment: C++ wrapper for table TblBrlyQConConMNEquipment (MySQL database)
	*/
class MyTblBrlyQConConMNEquipment : public TblBrlyQConConMNEquipment, public Sbecore::MyTable {

public:
	MyTblBrlyQConConMNEquipment();
	~MyTblBrlyQConConMNEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConConMNEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConConMNEquipment& rst);

	Sbecore::ubigint insertRec(BrlyQConConMNEquipment* rec);
	void insertRst(ListBrlyQConConMNEquipment& rst);
	void updateRec(BrlyQConConMNEquipment* rec);
	void updateRst(ListBrlyQConConMNEquipment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConConMNEquipment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConConMNEquipment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQConConMNEquipment: C++ wrapper for table TblBrlyQConConMNEquipment (PgSQL database)
	*/
class PgTblBrlyQConConMNEquipment : public TblBrlyQConConMNEquipment, public Sbecore::PgTable {

public:
	PgTblBrlyQConConMNEquipment();
	~PgTblBrlyQConConMNEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConConMNEquipment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQConConMNEquipment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConConMNEquipment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConConMNEquipment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQConConMNEquipment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQConConMNEquipment& rst);

	Sbecore::ubigint insertRec(BrlyQConConMNEquipment* rec);
	void insertRst(ListBrlyQConConMNEquipment& rst);
	void updateRec(BrlyQConConMNEquipment* rec);
	void updateRst(ListBrlyQConConMNEquipment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQConConMNEquipment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQConConMNEquipment& rst);
};
#endif

#endif
