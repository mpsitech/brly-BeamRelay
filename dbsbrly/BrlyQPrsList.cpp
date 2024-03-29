/**
	* \file BrlyQPrsList.cpp
	* Dbs and XML wrapper for table TblBrlyQPrsList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "BrlyQPrsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class BrlyQPrsList
 ******************************************************************************/

BrlyQPrsList::BrlyQPrsList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->ixVSex = ixVSex;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->telVal = telVal;
	this->emlVal = emlVal;
};

void BrlyQPrsList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["grp"] = stubGrp;
		me["own"] = stubOwn;
		me["tit"] = Title;
		me["fnm"] = Firstname;
		me["lnm"] = Lastname;
		me["sex"] = srefIxVSex;
		me["sex2"] = titIxVSex;
		me["tel"] = telVal;
		me["eml"] = emlVal;
	} else {
		me["stubGrp"] = stubGrp;
		me["stubOwn"] = stubOwn;
		me["Title"] = Title;
		me["Firstname"] = Firstname;
		me["Lastname"] = Lastname;
		me["srefIxVSex"] = srefIxVSex;
		me["titIxVSex"] = titIxVSex;
		me["telVal"] = telVal;
		me["emlVal"] = emlVal;
	};
};

void BrlyQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "tit", Title);
		writeString(wr, "fnm", Firstname);
		writeString(wr, "lnm", Lastname);
		writeString(wr, "sex", srefIxVSex);
		writeString(wr, "sex2", titIxVSex);
		writeString(wr, "tel", telVal);
		writeString(wr, "eml", emlVal);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "Title", Title);
		writeString(wr, "Firstname", Firstname);
		writeString(wr, "Lastname", Lastname);
		writeString(wr, "srefIxVSex", srefIxVSex);
		writeString(wr, "titIxVSex", titIxVSex);
		writeString(wr, "telVal", telVal);
		writeString(wr, "emlVal", emlVal);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQPrsList
 ******************************************************************************/

ListBrlyQPrsList::ListBrlyQPrsList() {
};

ListBrlyQPrsList::ListBrlyQPrsList(
			const ListBrlyQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new BrlyQPrsList(*(src.nodes[i]));
};

ListBrlyQPrsList::~ListBrlyQPrsList() {
	clear();
};

void ListBrlyQPrsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQPrsList::size() const {
	return(nodes.size());
};

void ListBrlyQPrsList::append(
			BrlyQPrsList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQPrsList& ListBrlyQPrsList::operator=(
			const ListBrlyQPrsList& src
		) {
	BrlyQPrsList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new BrlyQPrsList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQPrsList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListBrlyQPrsList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListBrlyQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQPrsList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQPrsList
 ******************************************************************************/

TblBrlyQPrsList::TblBrlyQPrsList() {
};

TblBrlyQPrsList::~TblBrlyQPrsList() {
};

bool TblBrlyQPrsList::loadRecBySQL(
			const string& sqlstr
			, BrlyQPrsList** rec
		) {
	return false;
};

ubigint TblBrlyQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPrsList& rst
		) {
	return 0;
};

ubigint TblBrlyQPrsList::insertRec(
			BrlyQPrsList* rec
		) {
	return 0;
};

ubigint TblBrlyQPrsList::insertNewRec(
			BrlyQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	ubigint retval = 0;
	BrlyQPrsList* _rec = NULL;

	_rec = new BrlyQPrsList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, Title, Firstname, Lastname, ixVSex, srefIxVSex, titIxVSex, telVal, emlVal);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQPrsList::appendNewRecToRst(
			ListBrlyQPrsList& rst
			, BrlyQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	ubigint retval = 0;
	BrlyQPrsList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, Title, Firstname, Lastname, ixVSex, srefIxVSex, titIxVSex, telVal, emlVal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQPrsList::insertRst(
			ListBrlyQPrsList& rst
		) {
};

void TblBrlyQPrsList::updateRec(
			BrlyQPrsList* rec
		) {
};

void TblBrlyQPrsList::updateRst(
			ListBrlyQPrsList& rst
		) {
};

void TblBrlyQPrsList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQPrsList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQPrsList::loadRecByQref(
			ubigint qref
			, BrlyQPrsList** rec
		) {
	return false;
};

ubigint TblBrlyQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPrsList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblBrlyQPrsList
 ******************************************************************************/

MyTblBrlyQPrsList::MyTblBrlyQPrsList() :
			TblBrlyQPrsList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQPrsList::~MyTblBrlyQPrsList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQPrsList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQPrsList (jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQPrsList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, Title = ?, Firstname = ?, Lastname = ?, ixVSex = ?, telVal = ?, emlVal = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQPrsList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQPrsList WHERE jref = ?", false);
};

bool MyTblBrlyQPrsList::loadRecBySQL(
			const string& sqlstr
			, BrlyQPrsList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQPrsList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQPrsList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQPrsList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQPrsList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";
		if (dbrow[7]) _rec->Firstname.assign(dbrow[7], dblengths[7]); else _rec->Firstname = "";
		if (dbrow[8]) _rec->Lastname.assign(dbrow[8], dblengths[8]); else _rec->Lastname = "";
		if (dbrow[9]) _rec->ixVSex = atol((char*) dbrow[9]); else _rec->ixVSex = 0;
		if (dbrow[10]) _rec->telVal.assign(dbrow[10], dblengths[10]); else _rec->telVal = "";
		if (dbrow[11]) _rec->emlVal.assign(dbrow[11], dblengths[11]); else _rec->emlVal = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPrsList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQPrsList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblBrlyQPrsList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblBrlyQPrsList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQPrsList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			if (dbrow[7]) rec->Firstname.assign(dbrow[7], dblengths[7]); else rec->Firstname = "";
			if (dbrow[8]) rec->Lastname.assign(dbrow[8], dblengths[8]); else rec->Lastname = "";
			if (dbrow[9]) rec->ixVSex = atol((char*) dbrow[9]); else rec->ixVSex = 0;
			if (dbrow[10]) rec->telVal.assign(dbrow[10], dblengths[10]); else rec->telVal = "";
			if (dbrow[11]) rec->emlVal.assign(dbrow[11], dblengths[11]); else rec->emlVal = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblBrlyQPrsList::insertRec(
			BrlyQPrsList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->Title.length();
	l[6] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->telVal.length();
	l[10] = rec->emlVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVSex,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->telVal.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->emlVal.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblBrlyQPrsList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblBrlyQPrsList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblBrlyQPrsList::insertRst(
			ListBrlyQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQPrsList::updateRec(
			BrlyQPrsList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->Title.length();
	l[6] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->telVal.length();
	l[10] = rec->emlVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVSex,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->telVal.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->emlVal.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblBrlyQPrsList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblBrlyQPrsList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQPrsList::updateRst(
			ListBrlyQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQPrsList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblBrlyQPrsList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblBrlyQPrsList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblBrlyQPrsList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblBrlyQPrsList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblBrlyQPrsList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblBrlyQPrsList::loadRecByQref(
			ubigint qref
			, BrlyQPrsList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblBrlyQPrsList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPrsList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQPrsList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblBrlyQPrsList
 ******************************************************************************/

PgTblBrlyQPrsList::PgTblBrlyQPrsList() :
			TblBrlyQPrsList()
			, PgTable()
		{
};

PgTblBrlyQPrsList::~PgTblBrlyQPrsList() {
};

void PgTblBrlyQPrsList::initStatements() {
	createStatement("TblBrlyQPrsList_insertRec", "INSERT INTO TblBrlyQPrsList (jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblBrlyQPrsList_updateRec", "UPDATE TblBrlyQPrsList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, Title = $6, Firstname = $7, Lastname = $8, ixVSex = $9, telVal = $10, emlVal = $11 WHERE qref = $12", 12);
	createStatement("TblBrlyQPrsList_removeRecByQref", "DELETE FROM TblBrlyQPrsList WHERE qref = $1", 1);
	createStatement("TblBrlyQPrsList_removeRstByJref", "DELETE FROM TblBrlyQPrsList WHERE jref = $1", 1);

	createStatement("TblBrlyQPrsList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal FROM TblBrlyQPrsList WHERE qref = $1", 1);
	createStatement("TblBrlyQPrsList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal FROM TblBrlyQPrsList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblBrlyQPrsList::loadRec(
			PGresult* res
			, BrlyQPrsList** rec
		) {
	char* ptr;

	BrlyQPrsList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQPrsList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "telval"),
			PQfnumber(res, "emlval")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Firstname.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVSex = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->telVal.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->emlVal.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQPrsList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQPrsList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQPrsList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "telval"),
			PQfnumber(res, "emlval")
		};

		while (numread < numrow) {
			rec = new BrlyQPrsList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Firstname.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVSex = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->telVal.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->emlVal.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQPrsList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQPrsList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQPrsList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQPrsList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQPrsList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQPrsList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblBrlyQPrsList::loadRecBySQL(
			const string& sqlstr
			, BrlyQPrsList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQPrsList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblBrlyQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPrsList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblBrlyQPrsList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblBrlyQPrsList::insertRec(
			BrlyQPrsList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVSex = htonl(rec->ixVSex);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		rec->Lastname.c_str(),
		(char*) &_ixVSex,
		rec->telVal.c_str(),
		rec->emlVal.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQPrsList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblBrlyQPrsList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblBrlyQPrsList::insertRst(
			ListBrlyQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQPrsList::updateRec(
			BrlyQPrsList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		rec->Lastname.c_str(),
		(char*) &_ixVSex,
		rec->telVal.c_str(),
		rec->emlVal.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQPrsList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQPrsList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQPrsList::updateRst(
			ListBrlyQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQPrsList::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyQPrsList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQPrsList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblBrlyQPrsList::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyQPrsList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblBrlyQPrsList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblBrlyQPrsList::loadRecByQref(
			ubigint qref
			, BrlyQPrsList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQPrsList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPrsList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQPrsList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
