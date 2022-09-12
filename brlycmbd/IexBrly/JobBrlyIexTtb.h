/**
	* \file JobBrlyIexTtb.h
	* job handler for job JobBrlyIexTtb (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef JOBBRLYIEXTTB_H
#define JOBBRLYIEXTTB_H

#include "IexBrlyTtb.h"

// IP include.cust --- INSERT

#define VecVJobBrlyIexTtbSge JobBrlyIexTtb::VecVSge

/**
	* JobBrlyIexTtb
	*/
class JobBrlyIexTtb : public JobBrly {

public:
	/**
		* VecVSge (full: VecVJobBrlyIexTtbSge)
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

		static void fillFeed(Sbecore::Feed& feed);
	};

public:
	JobBrlyIexTtb(XchgBrly* xchg, DbsBrly* dbsbrly, const Sbecore::ubigint jrefSup, const Sbecore::uint ixBrlyVLocale);
	~JobBrlyIexTtb();

public:

	std::string fullpath;
	bool xmlNotTxt;
	std::string rectpath;

	Sbecore::uint lineno;
	Sbecore::uint impcnt;

	std::map<Sbecore::uint,Sbecore::uint> icsBrlyVIop;

	bool shorttags;

	IexBrlyTtb::ImeIMFlight imeimflight;
	IexBrlyTtb::ImeIMLeg imeimleg;

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	long dayToDate(int day, int month, int year);
	void dateToDay(long date, int* day, int* month, int* year);
	long dayToIndex(long startd, int day, int month);
	void parseMonthDay(std::string s, int* month, int* day);
	void sphrToCart(double _r, double _theta, double _phi, double** _vec);
	double degToRad(double _deg);
	double radToDeg(double _rad);
	void locToRad(BrlyMLocation* loc);
	void legToDeg(BrlyMLeg* leg);

	/**
		* IexBrlyTtb::Tofs
		*/
	class Tofs {

	public:
		Tofs(DbsBrly* dbsbrly, BrlyMRegion* reg, const Sbecore::uint startd, const Sbecore::uint stopd, const bool ndstini, const Sbecore::uint dstswd);
		void init(DbsBrly* dbsbrly, std::vector<Tofs*>& tofss, const Sbecore::uint startd, const Sbecore::uint stopd, const int tm_year, const bool janjun);

		int getTofs(const Sbecore::uint lclt);

	public:
		Sbecore::ubigint ref;
		Sbecore::ubigint supRefBrlyMRegion;
		Sbecore::uint ixVDst;
		int toffset; // double value in database

		bool dstini;
		Sbecore::uint dstswd;
		Sbecore::uint dstswt;
		Sbecore::uint dstsw;

		bool initdone;
	};
	// IP cust --- IEND

public:
	void reset(DbsBrly* dbsbrly);

	void parseFromFile(DbsBrly* dbsbrly, const std::string& _fullpath, const bool _xmlNotTxt, const std::string& _rectpath = "");
	void import(DbsBrly* dbsbrly);
	void reverse(DbsBrly* dbsbrly);
	void collect(DbsBrly* dbsbrly, const std::map<Sbecore::uint,Sbecore::uint>& _icsBrlyVIop = IexBrlyTtb::icsBrlyVIopInsAll());
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
