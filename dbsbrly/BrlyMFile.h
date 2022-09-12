/**
	* \file BrlyMFile.h
	* database access for table TblBrlyMFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMFILE_H
#define BRLYMFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecBrlyVMFileRefTbl TblBrlyMFile::VecVRefTbl

/**
	* BrlyMFile: record of TblBrlyMFile
	*/
class BrlyMFile {

public:
	BrlyMFile(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refBrlyCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::usmallint Size = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refBrlyCFile;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	std::string osrefKContent;
	Sbecore::uint Archived;
	std::string Filename;
	std::string Archivename;
	std::string srefKMimetype;
	Sbecore::usmallint Size;
	std::string Comment;

public:
	bool operator==(const BrlyMFile& comp);
	bool operator!=(const BrlyMFile& comp);
};

/**
	* ListBrlyMFile: recordset of TblBrlyMFile
	*/
class ListBrlyMFile {

public:
	ListBrlyMFile();
	ListBrlyMFile(const ListBrlyMFile& src);
	~ListBrlyMFile();

	void clear();
	unsigned int size() const;
	void append(BrlyMFile* rec);

	BrlyMFile* operator[](const Sbecore::uint ix);
	ListBrlyMFile& operator=(const ListBrlyMFile& src);
	bool operator==(const ListBrlyMFile& comp);
	bool operator!=(const ListBrlyMFile& comp);

public:
	std::vector<BrlyMFile*> nodes;
};

/**
	* TblBrlyMFile: C++ wrapper for table TblBrlyMFile
	*/
class TblBrlyMFile {

public:
	/**
		* VecVRefTbl (full: VecBrlyVMFileRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TTB = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

public:
	TblBrlyMFile();
	virtual ~TblBrlyMFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, BrlyMFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMFile& rst);

	virtual Sbecore::ubigint insertRec(BrlyMFile* rec);
	Sbecore::ubigint insertNewRec(BrlyMFile** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refBrlyCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::usmallint Size = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListBrlyMFile& rst, BrlyMFile** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refBrlyCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::usmallint Size = 0, const std::string Comment = "");
	virtual void insertRst(ListBrlyMFile& rst, bool transact = false);
	virtual void updateRec(BrlyMFile* rec);
	virtual void updateRst(ListBrlyMFile& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, BrlyMFile** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refBrlyCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refBrlyCFile, const bool append, ListBrlyMFile& rst);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListBrlyMFile& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListBrlyMFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyBrlyMFile: C++ wrapper for table TblBrlyMFile (MySQL database)
	*/
class MyTblBrlyMFile : public TblBrlyMFile, public Sbecore::MyTable {

public:
	MyTblBrlyMFile();
	~MyTblBrlyMFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMFile& rst);

	Sbecore::ubigint insertRec(BrlyMFile* rec);
	void insertRst(ListBrlyMFile& rst, bool transact = false);
	void updateRec(BrlyMFile* rec);
	void updateRst(ListBrlyMFile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMFile** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refBrlyCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refBrlyCFile, const bool append, ListBrlyMFile& rst);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListBrlyMFile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgBrlyMFile: C++ wrapper for table TblBrlyMFile (PgSQL database)
	*/
class PgTblBrlyMFile : public TblBrlyMFile, public Sbecore::PgTable {

public:
	PgTblBrlyMFile();
	~PgTblBrlyMFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMFile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListBrlyMFile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMFile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, BrlyMFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListBrlyMFile& rst);

	Sbecore::ubigint insertRec(BrlyMFile* rec);
	void insertRst(ListBrlyMFile& rst, bool transact = false);
	void updateRec(BrlyMFile* rec);
	void updateRst(ListBrlyMFile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, BrlyMFile** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refBrlyCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refBrlyCFile, const bool append, ListBrlyMFile& rst);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListBrlyMFile& rst);
};
#endif

#endif
