/**
	* \file JobBrlyIexIni.h
	* job handler for job JobBrlyIexIni (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef JOBBRLYIEXINI_H
#define JOBBRLYIEXINI_H

#include "IexBrlyIni.h"

// IP include.cust --- INSERT

#define VecVJobBrlyIexIniSge JobBrlyIexIni::VecVSge

/**
	* JobBrlyIexIni
	*/
class JobBrlyIexIni : public JobBrly {

public:
	/**
		* VecVSge (full: VecVJobBrlyIexIniSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint PARSE = 2;
		static const Sbecore::uint PRSERR = 3;
		static const Sbecore::uint PRSDONE = 4;
		static const Sbecore::uint IMPORT = 5;
		static const Sbecore::uint IMPERR = 6;
		static const Sbecore::uint REVERSE = 7;
		static const Sbecore::uint COLLECT = 8;
		static const Sbecore::uint CLTDONE = 9;
		static const Sbecore::uint EXPORT = 10;
		static const Sbecore::uint DONE = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

public:
	JobBrlyIexIni(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~JobBrlyIexIni();

public:

	std::string fullpath;
	bool xmlNotTxt;
	std::string rectpath;

	Sbecore::uint lineno;
	Sbecore::uint impcnt;

	std::map<Sbecore::uint,Sbecore::uint> icsBrlyVIop;

	bool shorttags;

	IexBrlyIni::ImeIAVControlPar imeiavcontrolpar;
	IexBrlyIni::ImeIAVKeylistKey imeiavkeylistkey;
	IexBrlyIni::ImeIAVValuelistVal imeiavvaluelistval;
	IexBrlyIni::ImeIMFile imeimfile;
	IexBrlyIni::ImeIMLocation imeimlocation;
	IexBrlyIni::ImeIMOperator imeimoperator;
	IexBrlyIni::ImeIMPlntype imeimplntype;
	IexBrlyIni::ImeIMRegion imeimregion;
	IexBrlyIni::ImeIMUsergroup imeimusergroup;

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	double radToDeg(double _rad);
	// IP cust --- IEND

public:
	void reset(DbsBrly* dbsbrly);

	void parseFromFile(DbsBrly* dbsbrly, const std::string& _fullpath, const bool _xmlNotTxt, const std::string& _rectpath = "");
	void import(DbsBrly* dbsbrly);
	void reverse(DbsBrly* dbsbrly);
	void collect(DbsBrly* dbsbrly, const std::map<Sbecore::uint,Sbecore::uint>& _icsBrlyVIop = IexBrlyIni::icsBrlyVIopInsAll());
	void exportToFile(DbsBrly* dbsbrly, const std::string& _fullpath, const bool _xmlNotTxt, const bool _shorttags = true);

public:

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

private:

private:
	void changeStage(DbsBrly* dbsbrly, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsBrly* dbsbrly);

private:
	Sbecore::uint enterSgeIdle(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeIdle(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeParse(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeParse(DbsBrly* dbsbrly);
	Sbecore::uint enterSgePrserr(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgePrserr(DbsBrly* dbsbrly);
	Sbecore::uint enterSgePrsdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgePrsdone(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeImport(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImport(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeImperr(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeImperr(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeReverse(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeReverse(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCollect(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCollect(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeCltdone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeCltdone(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeExport(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeExport(DbsBrly* dbsbrly);
	Sbecore::uint enterSgeDone(DbsBrly* dbsbrly, const bool reenter);
	void leaveSgeDone(DbsBrly* dbsbrly);

};

#endif
