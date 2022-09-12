/**
	* \file BrlyQTtbRef1NFile.h
	* Dbs and XML wrapper for table TblBrlyQTtbRef1NFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYQTTBREF1NFILE_H
#define BRLYQTTBREF1NFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* BrlyQTtbRef1NFile: record of TblBrlyQTtbRef1NFile
	*/
class BrlyQTtbRef1NFile {

public:
	BrlyQTtbRef1NFile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListBrlyQTtbRef1NFile: recordset of TblBrlyQTtbRef1NFile
	*/
class ListBrlyQTtbRef1NFile {

public:
	ListBrlyQTtbRef1NFile();
	ListBrlyQTtbRef1NFile(const ListBrlyQTtbRef1NFile& src);
	~ListBrlyQTtbRef1NFile();

	void clear();
	unsigned int size() const;
	void append(BrlyQTtbRef1NFile* rec);

	ListBrlyQTtbRef1NFile& operator=(const ListBrlyQTtbRef1NFile& src);

public:
	std::vector<BrlyQTtbRef1NFile*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblBrlyQTtbRef1NFile: C++ wrapper for table TblBrlyQTtbRef1NFile
	*/
class TblBrlyQTtbRef1NFile {

public:
	TblBrlyQTtbRef1NFile();
	virtual ~TblBrlyQTtbRef1NFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyQTtbRef1NFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQTtbRef1NFile& rst);

	virtual Sbecore::ubigint insertRec(BrlyQTtbRef1NFile* rec);
	Sbecore::ubigint insertNewRec(BrlyQTtbRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyQTtbRef1NFile& rst, BrlyQTtbRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListBrlyQTtbRef1NFile& rst);
	virtual void updateRec(BrlyQTtbRef1NFile* rec);
	virtual void updateRst(ListBrlyQTtbRef1NFile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, BrlyQTtbRef1NFile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQTtbRef1NFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyQTtbRef1NFile: C++ wrapper for table TblBrlyQTtbRef1NFile (MySQL database)
	*/
class MyTblBrlyQTtbRef1NFile : public TblBrlyQTtbRef1NFile, public Sbecore::MyTable {

public:
	MyTblBrlyQTtbRef1NFile();
	~MyTblBrlyQTtbRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQTtbRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQTtbRef1NFile& rst);

	Sbecore::ubigint insertRec(BrlyQTtbRef1NFile* rec);
	void insertRst(ListBrlyQTtbRef1NFile& rst);
	void updateRec(BrlyQTtbRef1NFile* rec);
	void updateRst(ListBrlyQTtbRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQTtbRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQTtbRef1NFile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyQTtbRef1NFile: C++ wrapper for table TblBrlyQTtbRef1NFile (PgSQL database)
	*/
class PgTblBrlyQTtbRef1NFile : public TblBrlyQTtbRef1NFile, public Sbecore::PgTable {

public:
	PgTblBrlyQTtbRef1NFile();
	~PgTblBrlyQTtbRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQTtbRef1NFile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyQTtbRef1NFile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQTtbRef1NFile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQTtbRef1NFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyQTtbRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyQTtbRef1NFile& rst);

	Sbecore::ubigint insertRec(BrlyQTtbRef1NFile* rec);
	void insertRst(ListBrlyQTtbRef1NFile& rst);
	void updateRec(BrlyQTtbRef1NFile* rec);
	void updateRst(ListBrlyQTtbRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, BrlyQTtbRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListBrlyQTtbRef1NFile& rst);
};
#endif

#endif
