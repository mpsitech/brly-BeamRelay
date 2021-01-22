/**
	* \file BrlyMUser.cpp
	* database access for table TblBrlyMUser (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyMUser.h"

#include "BrlyMUser_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class BrlyMUser
 ******************************************************************************/

BrlyMUser::BrlyMUser(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refBrlyMUsergroup
			, const ubigint refBrlyMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixBrlyVLocale
			, const uint ixBrlyVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refRUsergroup = refRUsergroup;
	this->refBrlyMUsergroup = refBrlyMUsergroup;
	this->refBrlyMPerson = refBrlyMPerson;
	this->sref = sref;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->ixBrlyVLocale = ixBrlyVLocale;
	this->ixBrlyVUserlevel = ixBrlyVUserlevel;
	this->Password = Password;
	this->Fullkey = Fullkey;
	this->Comment = Comment;
};

bool BrlyMUser::operator==(
			const BrlyMUser& comp
		) {
	return false;
};

bool BrlyMUser::operator!=(
			const BrlyMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMUser
 ******************************************************************************/

ListBrlyMUser::ListBrlyMUser() {
};

ListBrlyMUser::ListBrlyMUser(
			const ListBrlyMUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyMUser(*(src.nodes[i]));
};

ListBrlyMUser::~ListBrlyMUser() {
	clear();
};

void ListBrlyMUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMUser::size() const {
	return(nodes.size());
};

void ListBrlyMUser::append(
			BrlyMUser* rec
		) {
	nodes.push_back(rec);
};

BrlyMUser* ListBrlyMUser::operator[](
			const uint ix
		) {
	BrlyMUser* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMUser& ListBrlyMUser::operator=(
			const ListBrlyMUser& src
		) {
	BrlyMUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyMUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMUser::operator==(
			const ListBrlyMUser& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListBrlyMUser::operator!=(
			const ListBrlyMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMUser
 ******************************************************************************/

TblBrlyMUser::TblBrlyMUser() {
};

TblBrlyMUser::~TblBrlyMUser() {
};

bool TblBrlyMUser::loadRecBySQL(
			const string& sqlstr
			, BrlyMUser** rec
		) {
	return false;
};

ubigint TblBrlyMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMUser& rst
		) {
	return 0;
};

ubigint TblBrlyMUser::insertRec(
			BrlyMUser* rec
		) {
	return 0;
};

ubigint TblBrlyMUser::insertNewRec(
			BrlyMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refBrlyMUsergroup
			, const ubigint refBrlyMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixBrlyVLocale
			, const uint ixBrlyVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	BrlyMUser* _rec = NULL;

	_rec = new BrlyMUser(0, grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMUser::appendNewRecToRst(
			ListBrlyMUser& rst
			, BrlyMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refBrlyMUsergroup
			, const ubigint refBrlyMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixBrlyVLocale
			, const uint ixBrlyVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	BrlyMUser* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMUser::insertRst(
			ListBrlyMUser& rst
			, bool transact
		) {
};

void TblBrlyMUser::updateRec(
			BrlyMUser* rec
		) {
};

void TblBrlyMUser::updateRst(
			ListBrlyMUser& rst
			, bool transact
		) {
};

void TblBrlyMUser::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMUser::loadRecByRef(
			ubigint ref
			, BrlyMUser** rec
		) {
	return false;
};

bool TblBrlyMUser::loadRecByPrs(
			ubigint refBrlyMPerson
			, BrlyMUser** rec
		) {
	return false;
};

bool TblBrlyMUser::loadRecBySrf(
			string sref
			, BrlyMUser** rec
		) {
	return false;
};

bool TblBrlyMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, BrlyMUser** rec
		) {
	return false;
};

bool TblBrlyMUser::loadRefByPrs(
			ubigint refBrlyMPerson
			, ubigint& ref
		) {
	return false;
};

bool TblBrlyMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblBrlyMUser::loadRefsByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblBrlyMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblBrlyMUser::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMUser& rst
		) {
	ubigint numload = 0;
	BrlyMUser* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyMUser
 ******************************************************************************/

MyTblBrlyMUser::MyTblBrlyMUser() :
			TblBrlyMUser()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMUser::~MyTblBrlyMUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMUser (grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMUser SET grp = ?, own = ?, refRUsergroup = ?, refBrlyMUsergroup = ?, refBrlyMPerson = ?, sref = ?, refJState = ?, ixVState = ?, ixBrlyVLocale = ?, ixBrlyVUserlevel = ?, Password = ?, Fullkey = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMUser WHERE ref = ?", false);
};

bool MyTblBrlyMUser::loadRecBySQL(
			const string& sqlstr
			, BrlyMUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyMUser::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyMUser::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMUser();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refRUsergroup = atoll((char*) dbrow[3]); else _rec->refRUsergroup = 0;
		if (dbrow[4]) _rec->refBrlyMUsergroup = atoll((char*) dbrow[4]); else _rec->refBrlyMUsergroup = 0;
		if (dbrow[5]) _rec->refBrlyMPerson = atoll((char*) dbrow[5]); else _rec->refBrlyMPerson = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->refJState = atoll((char*) dbrow[7]); else _rec->refJState = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->ixBrlyVLocale = atol((char*) dbrow[9]); else _rec->ixBrlyVLocale = 0;
		if (dbrow[10]) _rec->ixBrlyVUserlevel = atol((char*) dbrow[10]); else _rec->ixBrlyVUserlevel = 0;
		if (dbrow[11]) _rec->Password.assign(dbrow[11], dblengths[11]); else _rec->Password = "";
		if (dbrow[12]) _rec->Fullkey.assign(dbrow[12], dblengths[12]); else _rec->Fullkey = "";
		if (dbrow[13]) _rec->Comment.assign(dbrow[13], dblengths[13]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyMUser::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyMUser::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMUser();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refRUsergroup = atoll((char*) dbrow[3]); else rec->refRUsergroup = 0;
			if (dbrow[4]) rec->refBrlyMUsergroup = atoll((char*) dbrow[4]); else rec->refBrlyMUsergroup = 0;
			if (dbrow[5]) rec->refBrlyMPerson = atoll((char*) dbrow[5]); else rec->refBrlyMPerson = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->refJState = atoll((char*) dbrow[7]); else rec->refJState = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->ixBrlyVLocale = atol((char*) dbrow[9]); else rec->ixBrlyVLocale = 0;
			if (dbrow[10]) rec->ixBrlyVUserlevel = atol((char*) dbrow[10]); else rec->ixBrlyVUserlevel = 0;
			if (dbrow[11]) rec->Password.assign(dbrow[11], dblengths[11]); else rec->Password = "";
			if (dbrow[12]) rec->Fullkey.assign(dbrow[12], dblengths[12]); else rec->Fullkey = "";
			if (dbrow[13]) rec->Comment.assign(dbrow[13], dblengths[13]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyMUser::insertRec(
			BrlyMUser* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();
	l[11] = rec->Fullkey.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixBrlyVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Fullkey.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyMUser::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyMUser::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblBrlyMUser::insertRst(
			ListBrlyMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMUser::updateRec(
			BrlyMUser* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();
	l[11] = rec->Fullkey.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixBrlyVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Fullkey.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyMUser::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyMUser::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyMUser::updateRst(
			ListBrlyMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMUser::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblBrlyMUser::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblBrlyMUser::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyMUser::loadRecByRef(
			ubigint ref
			, BrlyMUser** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyMUser WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMUser::loadRecByPrs(
			ubigint refBrlyMPerson
			, BrlyMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment FROM TblBrlyMUser WHERE refBrlyMPerson = " + to_string(refBrlyMPerson) + "", rec);
};

bool MyTblBrlyMUser::loadRecBySrf(
			string sref
			, BrlyMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment FROM TblBrlyMUser WHERE sref = '" + sref + "'", rec);
};

bool MyTblBrlyMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, BrlyMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment FROM TblBrlyMUser WHERE sref = '" + sref + "' AND Password = '" + Password + "'", rec);
};

bool MyTblBrlyMUser::loadRefByPrs(
			ubigint refBrlyMPerson
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblBrlyMUser WHERE refBrlyMPerson = " + to_string(refBrlyMPerson) + "", ref);
};

bool MyTblBrlyMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblBrlyMUser WHERE sref = '" + sref + "'", ref);
};

ubigint MyTblBrlyMUser::loadRefsByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMUser WHERE refBrlyMUsergroup = " + to_string(refBrlyMUsergroup) + "", append, refs);
};

bool MyTblBrlyMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblBrlyMUser WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyMUser
 ******************************************************************************/

PgTblBrlyMUser::PgTblBrlyMUser() :
			TblBrlyMUser()
			, PgTable()
		{
};

PgTblBrlyMUser::~PgTblBrlyMUser() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMUser::initStatements() {
	createStatement("TblBrlyMUser_insertRec", "INSERT INTO TblBrlyMUser (grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13);
	createStatement("TblBrlyMUser_updateRec", "UPDATE TblBrlyMUser SET grp = $1, own = $2, refRUsergroup = $3, refBrlyMUsergroup = $4, refBrlyMPerson = $5, sref = $6, refJState = $7, ixVState = $8, ixBrlyVLocale = $9, ixBrlyVUserlevel = $10, Password = $11, Fullkey = $12, Comment = $13 WHERE ref = $14", 14);
	createStatement("TblBrlyMUser_removeRecByRef", "DELETE FROM TblBrlyMUser WHERE ref = $1", 1);

	createStatement("TblBrlyMUser_loadRecByRef", "SELECT ref, grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment FROM TblBrlyMUser WHERE ref = $1", 1);
	createStatement("TblBrlyMUser_loadRecByPrs", "SELECT ref, grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment FROM TblBrlyMUser WHERE refBrlyMPerson = $1", 1);
	createStatement("TblBrlyMUser_loadRecBySrf", "SELECT ref, grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment FROM TblBrlyMUser WHERE sref = $1", 1);
	createStatement("TblBrlyMUser_loadRecBySrfPwd", "SELECT ref, grp, own, refRUsergroup, refBrlyMUsergroup, refBrlyMPerson, sref, refJState, ixVState, ixBrlyVLocale, ixBrlyVUserlevel, Password, Fullkey, Comment FROM TblBrlyMUser WHERE sref = $1 AND Password = $2", 2);
	createStatement("TblBrlyMUser_loadRefByPrs", "SELECT ref FROM TblBrlyMUser WHERE refBrlyMPerson = $1", 1);
	createStatement("TblBrlyMUser_loadRefBySrf", "SELECT ref FROM TblBrlyMUser WHERE sref = $1", 1);
	createStatement("TblBrlyMUser_loadRefsByUsg", "SELECT ref FROM TblBrlyMUser WHERE refBrlyMUsergroup = $1", 1);
	createStatement("TblBrlyMUser_loadSrfByRef", "SELECT sref FROM TblBrlyMUser WHERE ref = $1", 1);
};

bool PgTblBrlyMUser::loadRec(
			PGresult* res
			, BrlyMUser** rec
		) {
	char* ptr;

	BrlyMUser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMUser();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "refbrlymperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixbrlyvlocale"),
			PQfnumber(res, "ixbrlyvuserlevel"),
			PQfnumber(res, "password"),
			PQfnumber(res, "fullkey"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refRUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refBrlyMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refBrlyMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixBrlyVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixBrlyVUserlevel = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Password.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Fullkey.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMUser::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMUser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMUser* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "refbrlymperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixbrlyvlocale"),
			PQfnumber(res, "ixbrlyvuserlevel"),
			PQfnumber(res, "password"),
			PQfnumber(res, "fullkey"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new BrlyMUser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refRUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refBrlyMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refBrlyMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixBrlyVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixBrlyVUserlevel = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Password.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Fullkey.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMUser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMUser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyMUser::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblBrlyMUser::loadRecBySQL(
			const string& sqlstr
			, BrlyMUser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyMUser::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMUser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyMUser::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyMUser::insertRec(
			BrlyMUser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	ubigint _refBrlyMPerson = htonl64(rec->refBrlyMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixBrlyVLocale = htonl(rec->ixBrlyVLocale);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refBrlyMUsergroup,
		(char*) &_refBrlyMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixBrlyVLocale,
		(char*) &_ixBrlyVUserlevel,
		rec->Password.c_str(),
		rec->Fullkey.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyMUser_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyMUser::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblBrlyMUser::insertRst(
			ListBrlyMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMUser::updateRec(
			BrlyMUser* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	ubigint _refBrlyMPerson = htonl64(rec->refBrlyMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixBrlyVLocale = htonl(rec->ixBrlyVLocale);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refBrlyMUsergroup,
		(char*) &_refBrlyMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixBrlyVLocale,
		(char*) &_ixBrlyVUserlevel,
		rec->Password.c_str(),
		rec->Fullkey.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMUser_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyMUser::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyMUser::updateRst(
			ListBrlyMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMUser::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyMUser_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyMUser::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyMUser::loadRecByRef(
			ubigint ref
			, BrlyMUser** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMUser_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMUser::loadRecByPrs(
			ubigint refBrlyMPerson
			, BrlyMUser** rec
		) {
	ubigint _refBrlyMPerson = htonl64(refBrlyMPerson);

	const char* vals[] = {
		(char*) &_refBrlyMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMUser_loadRecByPrs", 1, vals, l, f, rec);
};

bool PgTblBrlyMUser::loadRecBySrf(
			string sref
			, BrlyMUser** rec
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRecByStmt("TblBrlyMUser_loadRecBySrf", 1, vals, l, f, rec);
};

bool PgTblBrlyMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, BrlyMUser** rec
		) {

	const char* vals[] = {
		sref.c_str(),
		Password.c_str()
	};
	const int l[] = {
		0,
		0
	};
	const int f[] = {0,0};

	return loadRecByStmt("TblBrlyMUser_loadRecBySrfPwd", 2, vals, l, f, rec);
};

bool PgTblBrlyMUser::loadRefByPrs(
			ubigint refBrlyMPerson
			, ubigint& ref
		) {
	ubigint _refBrlyMPerson = htonl64(refBrlyMPerson);

	const char* vals[] = {
		(char*) &_refBrlyMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblBrlyMUser_loadRefByPrs", 1, vals, l, f, ref);
};

bool PgTblBrlyMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRefByStmt("TblBrlyMUser_loadRefBySrf", 1, vals, l, f, ref);
};

ubigint PgTblBrlyMUser::loadRefsByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyMUsergroup = htonl64(refBrlyMUsergroup);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyMUser_loadRefsByUsg", 1, vals, l, f, append, refs);
};

bool PgTblBrlyMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblBrlyMUser_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
