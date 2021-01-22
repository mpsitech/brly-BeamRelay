/**
	* \file Brly.h
	* Brly global functionality (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLY_H
#define BRLY_H

#define BRLY_VERSION "0.2.13"
#define BRLY_VERSION_MAJOR 0
#define BRLY_VERSION_MINOR 2
#define BRLY_VERSION_SUB 13

// IP include.cust --- IBEGIN
#include <netcdf.h>
// IP include.cust --- IEND

#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "VecBrlyVCall.h"
#include "VecBrlyVDpch.h"
#include "VecBrlyVError.h"
#include "VecBrlyVExpstate.h"
#include "VecBrlyVIop.h"
#include "VecBrlyVJob.h"
#include "VecBrlyVMimetype.h"
#include "VecBrlyVOpengtype.h"
#include "VecBrlyVOppack.h"
#include "VecBrlyVQrystate.h"
#include "VecBrlyVReqitmode.h"
#include "VecBrlyVStub.h"
#include "VecBrlyVTag.h"

#include <DbsBrly.h>

#include <sbecore/Engtypes.h>
#include <sbecore/Stub.h>

/**
	* Acv
	*/
namespace Acv {
	Sbecore::ubigint addfile(DbsBrly* dbsbrly, const std::string& acvpath, const std::string& path, const Sbecore::ubigint grp, const Sbecore::ubigint own, const Sbecore::uint refIxVTbl, const Sbecore::ubigint refUref, const std::string& osrefKContent, const std::string& Filename, const std::string& srefKMimetype, const std::string& Comment);
	void alterfile(DbsBrly* dbsbrly, const std::string& acvpath, const std::string& path, const Sbecore::ubigint ref);
	std::string getfile(DbsBrly* dbsbrly, const Sbecore::ubigint refBrlyMFile);
};

/**
	* Lop
	*/
namespace Lop {
	void apply(const Sbecore::uint ixBrlyVLop, std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);

	void insert(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
	void remove(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
};

/**
	* Oolop
	*/
namespace Oolop {
	void apply(const Sbecore::uint ixBrlyVOolop, std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);

	void insertBefore(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void insertAfter(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void remove(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
	void toBefore(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void toAfter(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void swap(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
};

/**
	* Tmp
	*/
namespace Tmp {
	std::string newfile(const std::string& tmppath, const std::string& ext);
	std::string newfolder(const std::string& tmppath);
	std::string random();
};

// IP cust --- IBEGIN
/**
  * Cdf
  */
namespace Cdf {
	void putBoolVec(const int ncid, const int varid, const std::vector<bool>& vec);
	void putUintVec(const int ncid, const int varid, const std::vector<Sbecore::uint>& vec);
	void putUbigintVec(const int ncid, const int varid, const std::vector<Sbecore::ubigint>& vec);
	void putDoubleVec(const int ncid, const int varid, const std::vector<double>& vec);

	bool getGroup(const int ncid, const std::string& path, int& pathid);

	bool getBoolVec(const int ncid, const std::string& path, const std::string& varsref, std::vector<bool>& vec);
	bool getUintVec(const int ncid, const std::string& path, const std::string& varsref, std::vector<Sbecore::uint>& vec);
	bool getUbigintVec(const int ncid, const std::string& path, const std::string& varsref, std::vector<Sbecore::ubigint>& vec);
	bool getDoubleVec(const int ncid, const std::string& path, const std::string& varsref, std::vector<double>& vec);

	bool getDoubleVecSlc(const int ncid, const std::string& path, const std::string& varsref, const std::vector<std::string>& slcDims, const std::vector<int>& slcIcs, const unsigned int Ntarget, std::vector<double>& vec);

	bool getUint(const int ncid, const std::string& path, const std::string& varsref, uint& val);
	bool getDouble(const int ncid, const std::string& path, const std::string& varsref, double& val);

	bool getDim(const int ncid, const std::string& path, const std::string& dimsref, int& dimid, unsigned int& dim);

	bool getAttr(const int ncid, const std::string& path, const std::string& varsref, const std::string& attrsref, std::string& attr);
};

/**
  * Rlychunk
  */
class Rlychunk {

public:
	unsigned int start;
	unsigned int stop;

	Sbecore::ubigint refRlyBwd;
	Sbecore::ubigint refRlyFwd;

	bool bwd;

	bool ctdBwd;
	bool ctdFwd;

	unsigned int Nhop;

public:
	Rlychunk();
	Rlychunk(BrlyMRelay* rly);

	void dump();
};

/**
  * Rlystat
  */
class Rlystat {

public:
	unsigned int start;
	unsigned int stop;

	ListBrlyMRelay rlys;
	std::list<Rlychunk> listRly;

	double pCtdBwd;
	double pCtdFwd;

	double avgNhopBwd;
	double avgNhopFwd;

	double pCtd;
	double pCtdBoth;

	double avgNhop;

	std::list<Rlychunk>::iterator itLast;

public:
	Rlystat(DbsBrly* dbsbrly, BrlyMConnection* con);

	void boilDown();
	void statsBwdFwd();
	void statsCombined();

	bool getCtd(const unsigned int t);
};

/**
  * Bgmode
  */
namespace Bgmode {
	const unsigned int CTDBWD = 1;
	const unsigned int CTDFWD = 2;
	const unsigned int CTDBOTH = 3;
	const unsigned int NCTD = 4;
	const unsigned int ALONE = 5;
};
// IP cust --- IEND

/**
	* Brly
	*/
namespace Brly {
	// IP gbl --- IBEGIN
	void loadLegsByArena(DbsBrly* dbsbrly, const std::string arena, const bool go, const bool back, const bool corr, std::vector<Sbecore::ubigint>& refsLeg1, std::vector<Sbecore::ubigint>& refsLeg2);
	bool isInArena(const std::vector<Sbecore::ubigint>& refsLeg, const Sbecore::ubigint refLeg);

	void initEqplineup(DbsBrly* dbsbrly, const Sbecore::ubigint refBrlyMConnection, std::list<Sbecore::ubigint>& lineup, ListBrlyORMConnectionMEquipment& ops);
	Sbecore::ubigint advanceEqplineup(std::list<Sbecore::ubigint>& lineup, ListBrlyORMConnectionMEquipment& ops, Sbecore::ubigint opix, Sbecore::uint t);
	// IP gbl --- IEND
};

/**
	* OpengBrly
	*/
namespace OpengBrly {
	void getIcsBrlyVOppackByIxBrlyVOpengtype(const Sbecore::uint ixBrlyVOpengtype, std::vector<Sbecore::uint>& icsBrlyVOppack);
	void getIcsBrlyVDpchByIxBrlyVOppack(const Sbecore::uint ixBrlyVOppack, std::set<Sbecore::uint>& icsBrlyVDpch);
};

/**
	* StubBrly
	*/
namespace StubBrly {
	std::string getStub(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVStub, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);

	std::string getStubConStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubEqpShort(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubEqpStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFafStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFilStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFltSref(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFltStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubGroup(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLegShort(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLegStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLocSref(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLocStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLocTitle(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubNdeLong(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubNdeStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOprSref(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOprStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOwner(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrsStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPtySref(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPtyStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRegHsref(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRegLong(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRegStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRlyLong(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRlyStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSegStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSesMenu(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSesStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubTtbStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubTtbTitle(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsgStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsrStd(DbsBrly* dbsbrly, const Sbecore::ubigint ref, const Sbecore::uint ixBrlyVLocale = VecBrlyVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
};

/**
	* BrlyException
	*/
class BrlyException : public Sbecore::SbeException {

public:

public:
	BrlyException(const Sbecore::uint ix, const std::map<std::string,std::string>& vals);

public:
	std::string getSref();
};

/**
	* ContInfBrlyAlert
	*/
class ContInfBrlyAlert : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint TXTCPT = 1;
	static const Sbecore::uint TXTMSG1 = 2;
	static const Sbecore::uint TXTMSG2 = 3;
	static const Sbecore::uint TXTMSG3 = 4;
	static const Sbecore::uint TXTMSG4 = 5;
	static const Sbecore::uint TXTMSG5 = 6;
	static const Sbecore::uint TXTMSG6 = 7;
	static const Sbecore::uint TXTMSG7 = 8;
	static const Sbecore::uint TXTMSG8 = 9;
	static const Sbecore::uint TXTMSG9 = 10;
	static const Sbecore::uint TXTMSG10 = 11;
	static const Sbecore::uint TXTMSG11 = 12;
	static const Sbecore::uint TXTMSG12 = 13;

public:
	ContInfBrlyAlert(const std::string& TxtCpt = "", const std::string& TxtMsg1 = "", const std::string& TxtMsg2 = "", const std::string& TxtMsg3 = "", const std::string& TxtMsg4 = "", const std::string& TxtMsg5 = "", const std::string& TxtMsg6 = "", const std::string& TxtMsg7 = "", const std::string& TxtMsg8 = "", const std::string& TxtMsg9 = "", const std::string& TxtMsg10 = "", const std::string& TxtMsg11 = "", const std::string& TxtMsg12 = "");

public:
	std::string TxtCpt;
	std::string TxtMsg1;
	std::string TxtMsg2;
	std::string TxtMsg3;
	std::string TxtMsg4;
	std::string TxtMsg5;
	std::string TxtMsg6;
	std::string TxtMsg7;
	std::string TxtMsg8;
	std::string TxtMsg9;
	std::string TxtMsg10;
	std::string TxtMsg11;
	std::string TxtMsg12;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> compare(const ContInfBrlyAlert* comp);
};

/**
	* DpchBrly
	*/
class DpchBrly : public Sbecore::Xmlio::Block {

public:
	DpchBrly(const Sbecore::uint ixBrlyVDpch = 0);
	virtual ~DpchBrly();

public:
	Sbecore::uint ixBrlyVDpch;
};

/**
	* DpchInvBrly
	*/
class DpchInvBrly : public DpchBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint ALL = 3;

public:
	DpchInvBrly(const Sbecore::uint ixBrlyVDpch = VecBrlyVDpch::DPCHINVBRLY, const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0);
	virtual ~DpchInvBrly();

public:
	std::string scrOref;
	Sbecore::ubigint oref;
	std::string scrJref;
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);

	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetBrly
	*/
class DpchRetBrly : public DpchBrly {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;

public:
	DpchRetBrly(const Sbecore::uint ixBrlyVDpch = VecBrlyVDpch::DPCHRETBRLY, const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::utinyint ixOpVOpres = Sbecore::VecOpVOpres::PROGRESS, const Sbecore::utinyint pdone = 0);
	virtual ~DpchRetBrly();

public:
	std::string scrOref;
	Sbecore::ubigint oref;
	std::string scrJref;
	Sbecore::ubigint jref;
	Sbecore::utinyint ixOpVOpres;
	Sbecore::utinyint pdone;

public:
	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

#endif
