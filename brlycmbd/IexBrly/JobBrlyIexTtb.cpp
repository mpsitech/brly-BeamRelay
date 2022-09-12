/**
	* \file JobBrlyIexTtb.cpp
	* job handler for job JobBrlyIexTtb (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "JobBrlyIexTtb.h"

#include "JobBrlyIexTtb_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexBrlyTtb;

/******************************************************************************
 class JobBrlyIexTtb
 ******************************************************************************/

JobBrlyIexTtb::JobBrlyIexTtb(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::JOBBRLYIEXTTB, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbsbrly, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobBrlyIexTtb::~JobBrlyIexTtb() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
long JobBrlyIexTtb::dayToDate(
			int day
			, int month
			, int year
		) {
	tm* tmDay = new tm;
	tmDay->tm_year = year-1900; tmDay->tm_mon = month-1; tmDay->tm_mday = day; tmDay->tm_hour = 0; tmDay->tm_min = 0; tmDay->tm_sec = 0;
	time_t timetDate = timegm(tmDay);
	delete tmDay;

	return(timetDate / (3600*24));
};

void JobBrlyIexTtb::dateToDay(
			long date
			, int* day
			, int* month
			, int* year
		) {
	time_t timetDate = 3600*24*date;

	tm tmDate = *(gmtime(&timetDate));

	*day = tmDate.tm_mday;
	*month = tmDate.tm_mon+1;
	*year = tmDate.tm_year+1900;
};

long JobBrlyIexTtb::dayToIndex(
			long startd
			, int day
			, int month
		) {
	// deduce yearStart from startd
	int _day, _month, _year;
	dateToDay(startd, &_day, &_month, &_year);

	long retval = dayToDate(day, month, _year);
	if (retval < startd) retval = dayToDate(day, month, _year+1);
	retval -= startd;

	return(retval);
};

void JobBrlyIexTtb::parseMonthDay(
			string s
			, int* month
			, int* day
		) {
	int m, d;
	long ptr1 = 0;
	long slen = s.length();

	if (s[ptr1] == ' ') ptr1++;
	m = ((int) s[ptr1]) - 48;
	ptr1++;
	if (s[ptr1] != '/') {
		m = m*10 + ((int) s[ptr1]) - 48;
		ptr1++;
	};
	ptr1++;

	d = ((int) s[ptr1]) - 48;
	ptr1++;
	if (ptr1 <= slen)
		if (((((int) s[ptr1]) - 48) >= 0) && ((((int) s[ptr1]) - 48) <= 9)) d = d*10 + ((int) s[ptr1]) - 48;
	
	*month = m;
	*day = d;
};

void JobBrlyIexTtb::sphrToCart(
			double _r																						// radius
			, double _theta																			// angle from equatorial (x-y) plane
			, double _phi																				// angle from x-axis
			, double** _vec																			// pointer to carterian result vector (double[3]) ; created if NULL
		) {
	if (*_vec == NULL) *_vec = new double[3];
	
	(*_vec)[0] = _r*cos(_theta)*cos(_phi);
	(*_vec)[1] = _r*cos(_theta)*sin(_phi);
	(*_vec)[2] = _r*sin(_theta);
};

double JobBrlyIexTtb::degToRad(
			double _deg																					// angle in degrees (0° .. 360°)
		) {
	return(pi*_deg/180.0);
};

double JobBrlyIexTtb::radToDeg(
			double _rad																					// angle in degrees (0° .. 360°)
		) {
	return(180.0*_rad/pi);
};

void JobBrlyIexTtb::locToRad(
			BrlyMLocation* loc
		) {
	loc->theta = degToRad(loc->theta);
	loc->phi = degToRad(loc->phi);
	loc->alpha = degToRad(loc->alpha);
};

void JobBrlyIexTtb::legToDeg(
			BrlyMLeg* leg
		) {
	leg->deltaphi = radToDeg(leg->deltaphi);
	leg->alpha = radToDeg(leg->alpha);
	leg->xPhi0 = radToDeg(leg->xPhi0);
	leg->xPhi1 = radToDeg(leg->xPhi1);
	leg->xAlpha = radToDeg(leg->xAlpha);
};

JobBrlyIexTtb::Tofs::Tofs(
			DbsBrly* dbsbrly
			, BrlyMRegion* reg
			, const uint startd
			, const uint stopd
			, const bool ndstini
			, const uint dstswd
		) {
	ref = reg->ref;
	supRefBrlyMRegion = reg->supRefBrlyMRegion;
	ixVDst = reg->ixVDst;
	toffset = -((int) (reg->toffset*3600.0));

	dstini = ndstini;
	this->dstswd = dstswd;
	dstswt = 0;
	dstsw = 0;

	initdone = false;

	ListBrlyJMRegion regJs;
	BrlyJMRegion* regJ = NULL;

	bool found;

	// - determine time zone and DST affiliation (override, depending on timetable period)
	dbsbrly->tblbrlyjmregion->loadRstByReg(ref, false, regJs);

	if (regJs.nodes.size() > 1) {
		// detect time zone change that takes place within period
		found = false;
		for (unsigned int j = 0; j < regJs.nodes.size(); j++) {
			regJ = regJs.nodes[j];

			if (regJ->x1Startd != 0) {
				if ((regJ->x1Startd > startd) && (regJ->x1Startd < stopd)) {
					found = true;
					break;
				};
			};

			if (regJ->x1Stopd != 0) {
				if ((regJ->x1Stopd > startd) && (regJ->x1Stopd < stopd)) {
					found = true;
					break;
				};
			};
		};

		if (found) cout << "region '" << StubBrly::getStubRegLong(dbsbrly, reg->ref) << "' changes time zone during timetable period." << endl;

		if (!found) {
			for (unsigned int j = 0; j < regJs.nodes.size(); j++) {
				if ((regJ->x1Startd != 0) && (regJ->x1Stopd != 0)) {
					// first try: span beginning before period and ending after period
					if ((regJ->x1Startd <= ((unsigned int) startd)) && (regJ->x1Stopd >= ((unsigned int) startd))) {
						found = true;
						break;
					};

				} else if ((regJ->x1Startd == 0) && (regJ->x1Stopd != 0)) {
					// second try: span ending after period
					if (regJ->x1Stopd >= ((unsigned int) startd)) {
						found = true;
						break;
					};

				} else if ((regJ->x1Startd != 0) && (regJ->x1Stopd == 0)) {
					// third try: span beginning before period
					if (regJ->x1Startd <= ((unsigned int) stopd)) {
						found = true;
						break;
					};
				};
			};
		};

		if (found) {
			ixVDst = regJ->ixVDst;
			toffset = -((int) (regJ->toffset*3600.0));
		};
	};

	if (ixVDst == VecBrlyVMRegionDst::SDST) dstini = !dstini;
};

void JobBrlyIexTtb::Tofs::init(
			DbsBrly* dbsbrly
			, vector<Tofs*>& tofss
			, const uint startd
			, const uint stopd
			, const int tm_year
			, const bool janjun
		) {
	// only dstsw... are affected

	ListBrlyAMRegionDstswitch rads;
	BrlyAMRegionDstswitch* rad = NULL;

	Tofs* sup = NULL;

	time_t timetRad;
	tm tmRad;
	
	bool found;

	if (!initdone) {
		if (ixVDst != VecBrlyVMRegionDst::NONE) {
			dbsbrly->tblbrlyamregiondstswitch->loadRstByReg(ref, false, rads);

			if (rads.nodes.size() > 0) {
				// first try: region has own set of DST switch times
				for (unsigned int i = 0; i < rads.nodes.size();i++) {
					rad = rads.nodes[i];
					timetRad = 3600*24*rad->startd;
					tmRad = *(gmtime(&timetRad));

					if ((rad->startd >= startd) && (rad->startd <= stopd)) {
						// during timetable period
						dstini = ((janjun && (ixVDst == VecBrlyVMRegionDst::SDST)) || (!janjun && (ixVDst == VecBrlyVMRegionDst::NDST)));
						dstswd = rad->startd;
						dstswt = rad->startt;

					} else {
						// before or after timetable period but in same half year as timetable start
						if (tmRad.tm_year == tm_year) {
							if (janjun && (tmRad.tm_mon < 6)) {
								dstini = ((rad->startd < startd) && (ixVDst == VecBrlyVMRegionDst::NDST)) || ((rad->startd > stopd) && (ixVDst == VecBrlyVMRegionDst::SDST));
								dstswd = 0;
							} else if (!janjun && (tmRad.tm_mon >= 6)) {
								dstini = ((rad->startd < startd) && (ixVDst == VecBrlyVMRegionDst::SDST)) || ((rad->startd > stopd) && (ixVDst == VecBrlyVMRegionDst::NDST));
								dstswd = 0;
							};
						};
					};
				};

			} else {
				// second try: inherit from sup region, init if required
				if (supRefBrlyMRegion != 0) {
					found = false;

					for (unsigned int i = 0; i < tofss.size();i++) {
						sup = tofss[i];
						if (tofss[i]->ref == supRefBrlyMRegion) {
							found = true;
							break;
						};
					};

					if (found) {
						sup->init(dbsbrly, tofss, startd, stopd, tm_year, janjun);
						
						dstini = sup->dstini;
						dstswd = sup->dstswd;
						dstswt = sup->dstswt;
					};
				};
			};

			// calculate DST switch time stamp (quasi local time)
			dstsw = 86400*dstswd + dstswt;
		};

		initdone = true;
	};
};

int JobBrlyIexTtb::Tofs::getTofs(
			const uint lclt
		) {
	// return value is added to local time stamp
	int retval = toffset;

	if (ixVDst != VecBrlyVMRegionDst::NONE) {
		if (dstsw == 0) {
			if (dstini) retval -= 3600;
		} else {
			if (lclt < dstsw) {
				if (dstini) retval -= 3600;
			} else {
				if (!dstini) retval -= 3600;
			};
		};
	};

	return retval;
};
// IP cust --- IEND

void JobBrlyIexTtb::reset(
			DbsBrly* dbsbrly
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbsbrly, VecVSge::IDLE);
};

void JobBrlyIexTtb::parseFromFile(
			DbsBrly* dbsbrly
			, const string& _fullpath
			, const bool _xmlNotTxt
			, const string& _rectpath
		) {
	if (ixVSge == VecVSge::IDLE) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		rectpath = _rectpath;

		changeStage(dbsbrly, VecVSge::PARSE);
	};
};

void JobBrlyIexTtb::import(
			DbsBrly* dbsbrly
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbsbrly, VecVSge::IMPORT);
};

void JobBrlyIexTtb::reverse(
			DbsBrly* dbsbrly
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbsbrly, VecVSge::REVERSE);
};

void JobBrlyIexTtb::collect(
			DbsBrly* dbsbrly
			, const map<uint,uint>& _icsBrlyVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsBrlyVIop = _icsBrlyVIop;
		changeStage(dbsbrly, VecVSge::COLLECT);
	};
};

void JobBrlyIexTtb::exportToFile(
			DbsBrly* dbsbrly
			, const string& _fullpath
			, const bool _xmlNotTxt
			, const bool _shorttags
		) {
	if ((ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::CLTDONE)) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		shorttags = _shorttags;

		changeStage(dbsbrly, VecVSge::EXPORT);
	};
};

void JobBrlyIexTtb::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

void JobBrlyIexTtb::changeStage(
			DbsBrly* dbsbrly
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsbrly); break;
				case VecVSge::PARSE: leaveSgeParse(dbsbrly); break;
				case VecVSge::PRSERR: leaveSgePrserr(dbsbrly); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbsbrly); break;
				case VecVSge::IMPORT: leaveSgeImport(dbsbrly); break;
				case VecVSge::IMPERR: leaveSgeImperr(dbsbrly); break;
				case VecVSge::REVERSE: leaveSgeReverse(dbsbrly); break;
				case VecVSge::COLLECT: leaveSgeCollect(dbsbrly); break;
				case VecVSge::CLTDONE: leaveSgeCltdone(dbsbrly); break;
				case VecVSge::EXPORT: leaveSgeExport(dbsbrly); break;
				case VecVSge::DONE: leaveSgeDone(dbsbrly); break;
			};

			setStage(dbsbrly, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsbrly, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbsbrly, reenter); break;
			case VecVSge::PRSERR: _ixVSge = enterSgePrserr(dbsbrly, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbsbrly, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbsbrly, reenter); break;
			case VecVSge::IMPERR: _ixVSge = enterSgeImperr(dbsbrly, reenter); break;
			case VecVSge::REVERSE: _ixVSge = enterSgeReverse(dbsbrly, reenter); break;
			case VecVSge::COLLECT: _ixVSge = enterSgeCollect(dbsbrly, reenter); break;
			case VecVSge::CLTDONE: _ixVSge = enterSgeCltdone(dbsbrly, reenter); break;
			case VecVSge::EXPORT: _ixVSge = enterSgeExport(dbsbrly, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsbrly, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobBrlyIexTtb::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing timetable raw data";
			else if (ixVSge == VecVSge::PRSDONE) retval = "timetable raw data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing timetable raw data (&impcnt; records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing timetable raw data import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting timetable raw data for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "timetable raw data collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting timetable raw data";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing timetable raw data";
			else if (ixVSge == VecVSge::PRSDONE) retval = "timetable raw data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing timetable raw data (&impcnt; records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing timetable raw data import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting timetable raw data for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "timetable raw data collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting timetable raw data";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobBrlyIexTtb::enterSgeIdle(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;
	rectpath = "";

	lineno = 0;
	impcnt = 0;

	icsBrlyVIop.clear();

	imeimflight.clear();
	imeimleg.clear();

	return retval;
};

void JobBrlyIexTtb::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobBrlyIexTtb::enterSgeParse(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexBrlyTtb::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimflight, imeimleg);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecBrlyVError::getIx, VecBrlyVError::getTitle, ixBrlyVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobBrlyIexTtb::leaveSgeParse(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobBrlyIexTtb::enterSgePrserr(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobBrlyIexTtb::leaveSgePrserr(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobBrlyIexTtb::enterSgePrsdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobBrlyIexTtb::leaveSgePrsdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobBrlyIexTtb::enterSgeImport(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMFlight* flt = NULL;
	ImeitemIMLeg* leg = NULL;

	set<ubigint> irefs0;

	// IP enterSgeImport.prep --- IBEGIN
	ostringstream sqlstr;

	BrlyMTimetable* ttb = NULL;

	ListBrlyMOperator oprs;
	BrlyMOperator* opr = NULL;

	ListBrlyMPlntype ptys;
	BrlyMPlntype* pty = NULL;

	ListBrlyMRegion regs;
	BrlyMRegion* reg = NULL;

	ListBrlyMLocation locs;
	BrlyMLocation* loc = NULL;

	BrlyMLocation* bgnloc = NULL;
	BrlyMLocation* endloc = NULL;

	int startd;

	int ofsWday, wday;

	tm tmDstsw;
	uint d;

	bool ndstini;
	uint dstswd;

	vector<bool> act;
	vector<bool> act2;
	bool hasact2;

	vector<Tofs*> tofss;
	Tofs* tofs = NULL;

	map<ubigint, Tofs*> tofsByLoc;

	ImeitemIMLeg* leg2 = NULL;

	ListBrlyMLeg oldlegs;
	BrlyMLeg* oldleg = NULL;

	BrlyMEquipment* eqp = NULL;

	double* bgncart = NULL;
	double* endcart = NULL;
	double delta;

	bool found;

	string sref;
	int start, stop;

	ostringstream str;
	vector<string> ss;
	string s;

	size_t ptr;
	unsigned int ixStart, ixStop;

	int month, day;

	bool exc;

	ubigint refBrlyMTimetable;
	refBrlyMTimetable = xchg->getRefPreset(VecBrlyVPreset::PREBRLYREFTTB, jref);

	double earthradius = xchg->stgbrlygeometry.earthradius;
	double hrznaltitude = xchg->stgbrlygeometry.hrznaltitude;
	double acraltitude = xchg->stgbrlygeometry.acraltitude;

	sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMOperator ORDER BY sref ASC";
	dbsbrly->tblbrlymoperator->loadRstBySQL(sqlstr.str(), false, oprs);

	sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMPlntype ORDER BY sref ASC";
	dbsbrly->tblbrlymplntype->loadRstBySQL(sqlstr.str(), false, ptys);

	// - set up timetable validity dates
	dbsbrly->tblbrlymtimetable->loadRecByRef(refBrlyMTimetable, &ttb);

	startd = ttb->startd;

	time_t timetStart = 3600*24*ttb->startd;
	tm tmStart = *(gmtime(&timetStart));

	ofsWday = (tmStart.tm_wday+6)%7; // tm_wday == 0: sunday, value between 0 and 6
	act.resize(ttb->stopd - ttb->startd + 1, false);
	act2.resize(ttb->stopd - ttb->startd + 1, false);

	// - set a default time for the DST switch in case the timetable period encompasses it
	ndstini = ((tmStart.tm_mon >= 3) && (tmStart.tm_mon <= 9));
	dstswd = 0;

	if (ttb->stopd < (ttb->startd+180)) {
		found = false;

		// find 1.4. following the begin of the period
		tmDstsw = tmStart;
		tmDstsw.tm_mon = 3;
		tmDstsw.tm_mday = 1;
		if ((tmStart.tm_mon > 3) || ((tmStart.tm_mon == 3) && (tmStart.tm_mday > 1))) tmDstsw.tm_year++;

		d = mktime(&tmDstsw)/(3600*24);
		if ( (d >= ttb->startd) && (d <= ttb->stopd) ) {
			dstswd = d;
			found = true;
		};

		if (!found) {
			// find 1.10. following the begin of the period
			tmDstsw = tmStart;
			tmDstsw.tm_mon = 10;
			tmDstsw.tm_mday = 1;
			if ((tmStart.tm_mon > 9) || ((tmStart.tm_mon == 9) && (tmStart.tm_mday > 1))) tmDstsw.tm_year++;

			d = mktime(&tmDstsw)/(3600*24);
			if ( (d >= ttb->startd) && (d <= ttb->stopd) ) dstswd = d;
		};
	};

	// - set up regions, airports and their time offsets
	sqlstr.str(""); sqlstr << "SELECT * FROM TblBrlyMRegion";
	dbsbrly->tblbrlymregion->loadRstBySQL(sqlstr.str(), false, regs);

	for (unsigned int i=0;i<regs.nodes.size();i++) {
		reg = regs.nodes[i];

		tofs = new Tofs(dbsbrly, reg, ttb->startd, ttb->stopd, ndstini, dstswd);
		tofss.push_back(tofs);
	};

	for (unsigned int i=0;i<regs.nodes.size();i++) tofss[i]->init(dbsbrly, tofss, ttb->startd, ttb->stopd, tmStart.tm_year, (tmStart.tm_mon < 6));

	dbsbrly->tblbrlymlocation->loadRstByTyp(VecBrlyVMLocationBasetype::APT, false, locs);
	for (unsigned int i=0;i<locs.nodes.size();i++) locToRad(locs.nodes[i]);

	for (unsigned int i=0;i<locs.nodes.size();i++) {
		loc = locs.nodes[i];

		for (unsigned int j=0;j<regs.nodes.size();j++) {
			reg = regs.nodes[j];
			tofs = tofss[j];

			if (loc->refBrlyMRegion == reg->ref) {
				tofsByLoc[loc->ref] = tofs;
				break;
			};
		};
	};

/*
/// DEBUG
	vector<uint> ts;

	if (ttb->Title.compare("star2011-12") == 0) {
		ts.push_back(1324382400); // 20-12-2011
		ts.push_back(1329134400); // 13-2-2012

	} else if (ttb->Title.compare("owMar2014") == 0) {
		ts.push_back(1393675200); // 1-3-2014
		ts.push_back(1394280000); // 8-3-2014
		ts.push_back(1394366400); // 9-3-2014
		ts.push_back(1395576000); // 23-3-2014
		ts.push_back(1396180800); // 30-3-2014
		ts.push_back(1396353600); // 1-4-2014
	};

	fstream outfile;

	outfile.open("/home/epsi/bin/brlyd/DST.txt", ios::out);

	outfile << "region";
	for (unsigned int i=0;i<ts.size();i++) outfile << "\t" << Ftm::date(ts[i]/86400);
	outfile << endl;

	for (unsigned int i=0;i<regs.nodes.size();i++) {
		reg = regs.nodes[i];
		tofs = tofss[i];

		outfile << StubBrly::getStubRegLong(dbsbrly, reg->ref);
		for (unsigned int j=0;j<ts.size();j++) outfile << "\t" << (((double) tofs->getTofs(ts[j]))/3600.0); // note that ts[*] are not local times
		outfile << endl;
	};

	outfile.close();

	return;
*/

	delete ttb;

	// load pre-existing legs
	dbsbrly->tblbrlymleg->loadRstByTyp(VecBrlyVMLegBasetype::RTE, false, oldlegs);

	// equipment record master
	eqp = new BrlyMEquipment();

	// standard opening angle (10500m)
	double alpha = acos((earthradius + hrznaltitude) / (earthradius + acraltitude));
	double alphag = 2.0*pi*85.0/360.0;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN
		// -- ImeIMLeg
		irefs0.clear();

		for (unsigned int ix0 = 0; ix0 < imeimleg.nodes.size(); ix0++) {
			leg = imeimleg.nodes[ix0];

			if (irefs0.find(leg->iref) != irefs0.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(leg->iref)}, {"ime","ImeIMLeg"}, {"lineno",to_string(leg->lineno)}});
			irefs0.insert(leg->iref);

			leg->ixVBasetype = VecBrlyVMLegBasetype::RTE;
			//leg->bgnRefBrlyMLocation: RST
			for (unsigned int i=0;i<locs.nodes.size();i++) {
				loc = locs.nodes[i];
				if (loc->sref.compare(leg->srefBgnRefBrlyMLocation) == 0) {
					leg->bgnRefBrlyMLocation = loc->ref;
					break;
				};
			};
			if (leg->bgnRefBrlyMLocation == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",leg->srefBgnRefBrlyMLocation}, {"iel","srefBgnRefBrlyMLocation"}, {"lineno",to_string(leg->lineno)}});
			//leg->endRefBrlyMLocation: RST
			for (unsigned int i=0;i<locs.nodes.size();i++) {
				loc = locs.nodes[i];
				if (loc->sref.compare(leg->srefEndRefBrlyMLocation) == 0) {
					leg->endRefBrlyMLocation = loc->ref;
					break;
				};
			};
			if (leg->endRefBrlyMLocation == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",leg->srefEndRefBrlyMLocation}, {"iel","srefEndRefBrlyMLocation"}, {"lineno",to_string(leg->lineno)}});

			// retrieve
			for (unsigned int i=0;i<oldlegs.nodes.size();i++) {
				oldleg = oldlegs.nodes[i];

				if ((oldleg->bgnRefBrlyMLocation == leg->bgnRefBrlyMLocation) && (oldleg->endRefBrlyMLocation == leg->endRefBrlyMLocation)) {
					leg->ref = oldleg->ref;
					leg->refBrlyCLeg = oldleg->refBrlyCLeg;

					break;
				};
			};

			if (leg->ref == 0) {
				leg->alt = acraltitude;

				for (unsigned int i=0;i<locs.nodes.size();i++) {
					bgnloc = locs.nodes[i];
					if (bgnloc->ref == leg->bgnRefBrlyMLocation) break;
				};
				for (unsigned int i=0;i<locs.nodes.size();i++) {
					endloc = locs.nodes[i];
					if (endloc->ref == leg->endRefBrlyMLocation) break;
				};
				sphrToCart(1.0, bgnloc->theta, bgnloc->phi, &bgncart);
				sphrToCart(1.0, endloc->theta, endloc->phi, &endcart);
				delta = acos(bgncart[0]*endcart[0] + bgncart[1]*endcart[1] + bgncart[2]*endcart[2]);
				leg->deltaphi = delta;

				leg->alpha = 0.0;

				// extended model
				leg->xAlt = (1.0/tan(alphag)*delta*earthradius)/3.0 + (bgnloc->alt+endloc->alt)/2.0;
				if (leg->xAlt > acraltitude) leg->xAlt = acraltitude;

				leg->xPhi0 = (leg->xAlt-bgnloc->alt)/(1.0/tan(alphag)*earthradius);
				leg->xPhi1 = delta - (leg->xAlt-endloc->alt)/(1.0/tan(alphag)*earthradius);

				if (leg->xAlt > hrznaltitude) leg->xAlpha = acos((earthradius + hrznaltitude) / (earthradius + leg->xAlt));
				else leg->xAlpha = 0.0;

				leg->Calcdone = false;

				legToDeg(leg);

				dbsbrly->tblbrlymleg->insertRec(leg);
				impcnt++;
			};
		};

		// -- ImeIMFlight
		for (unsigned int ix0 = 0; ix0 < imeimflight.nodes.size(); ix0++) {
			flt = imeimflight.nodes[ix0];

			//flt->refBrlyMTimetable: PRESET
			flt->refBrlyMTimetable = refBrlyMTimetable;
			//flt->refBrlyMEquipment: THINT
			//flt->refBrlyMLeg: PREVIMP
			for (unsigned int i=0;i<imeimleg.nodes.size();i++) {
				leg = imeimleg.nodes[i];
				if (leg->iref == flt->irefRefBrlyMLeg) {
					flt->refBrlyMLeg = leg->ref;
					break;
				};
			};
			if (flt->refBrlyMLeg == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(flt->irefRefBrlyMLeg)}, {"iel","irefRefBrlyMLeg"}, {"lineno",to_string(flt->lineno)}});
			//flt->sref: TBL
			//flt->start: THINT
			//flt->stop: THINT
			flt->Calcdone = false;

			// uinc'ed equipment
			eqp->hkIxVTbl = VecBrlyVMEquipmentHkTbl::FLT;
			//eqp->hkUref = CUSTSQL;
			//eqp->refBrlyMOperator = CUSTSQL;
			for (unsigned int i=0;i<oprs.nodes.size();i++) {
				opr = oprs.nodes[i];
				if (opr->sref.compare(flt->sref.substr(0,2)) == 0) {
					eqp->refBrlyMOperator = opr->ref;
					break;
				};
			};
			//eqp->refBrlyMPlntype = CUSTSQL;
			//eqp->srefBrlyKEqptype = CUSTSQL;
			for (unsigned int i=0;i<ptys.nodes.size();i++) {
				pty = ptys.nodes[i];
				if (pty->sref.compare(flt->hintRefBrlyMEquipment) == 0) {
					eqp->refBrlyMPlntype = pty->ref;
					eqp->srefBrlyKEqptype = pty->srefBrlyKEqptype;
					break;
				};
			};
			eqp->Fiber = false;

			sref = flt->sref;
			start = atol(flt->hintStart.c_str());
			stop = atol(flt->hintStop.c_str());

			// - determine validity dates
			for (unsigned int i=0;i<act.size();i++) act[i] = false;
			for (unsigned int i=0;i<act2.size();i++) act2[i] = false;

			// start with week days
			for (unsigned int i=0;i<flt->iWeekday.length();i++) {
				wday = ((int) (flt->iWeekday[i])) - 48 - 1 - ofsWday; // value between -6 and 6
				if (wday < 0) wday += 7;

				for (unsigned int j=wday;j<act.size();j+=7) act[j] = true;
			};

			// process additional validity information
			exc = false;
			hasact2 = false;

			StrMod::stringToVector(flt->iDate, ss);
			for (unsigned int i=0;i<ss.size();i++) {
				s = ss[i];

				if (s.find("Eff.") == 0) {
					exc = false;

					// parse date
					parseMonthDay(s.substr(4), &month, &day);

					ixStart = dayToIndex(startd, day, month);
					for (unsigned int l=0;l<ixStart;l++) act[l] = false; 

				} else if (s.find("Disc.") == 0) {
					exc = false;

					// parse date
					parseMonthDay(s.substr(5), &month, &day);

					ixStop = dayToIndex(startd, day, month);
					for (unsigned int l=ixStop+1;l<act.size();l++) act[l] = false; 

				} else if (s.find("Exc.") == 0) {
					exc = true;
		
					// parse date or date span
					ptr = s.find('-');
					if (ptr == string::npos) {
						parseMonthDay(s.substr(4), &month, &day);
						ixStart = dayToIndex(startd, day, month);
						ixStop = ixStart;

					} else {
						// date span
						parseMonthDay(s.substr(4, ptr-4), &month, &day);
						ixStart = dayToIndex(startd, day, month);

						parseMonthDay(s.substr(ptr+1), &month, &day);
						ixStop = dayToIndex(startd, day, month);
					};
		
					for (unsigned int l=ixStart;l<=ixStop;l++) act[l] = false;

				} else {
					// parse date or date span
					ptr = s.find('-');
					if (ptr == string::npos) {
						parseMonthDay(s, &month, &day);
						ixStart = dayToIndex(startd, day, month);
						ixStop = ixStart;

					} else {
						if (s.find('/') == string::npos) {
							// OW: date span given as Unix dates (numbers)
							ixStart = atoi(s.substr(0, ptr).c_str())-startd;
							ixStop = atoi(s.substr(ptr+1).c_str())-startd;

						} else {
							// *A: date span is human readable
							parseMonthDay(s.substr(0, ptr), &month, &day);
							ixStart = dayToIndex(startd, day, month);

							parseMonthDay(s.substr(ptr+1), &month, &day);
							ixStop = dayToIndex(startd, day, month);
						};
					};
		
					// could be part of "Exc." section or not
					if (exc) {
						for (unsigned int l=ixStart;l<=ixStop;l++) act[l] = false;
					} else {
						hasact2 = true;
						for (unsigned int l=ixStart;l<=ixStop;l++) act2[l] = true;
					};
				};
			};

			if (hasact2) for (unsigned int l=0;l<act.size();l++) act[l] = act[l] && act2[l];

			// - insert flights
			for (unsigned int i=0;i<act.size();i++) {
				if (act[i]) {
					flt->ref = 0;

					eqp->ref = 0;
					dbsbrly->tblbrlymequipment->insertRec(eqp);
					flt->refBrlyMEquipment = eqp->ref;

					flt->sref = sref + " " + Ftm::date(startd+i);
					flt->start = start + (startd+i)*86400 + tofsByLoc[leg->bgnRefBrlyMLocation]->getTofs(start + (startd+i)*86400);
					flt->stop = stop + (startd+i)*86400 + tofsByLoc[leg->endRefBrlyMLocation]->getTofs(stop + (startd+i)*86400);

					dbsbrly->tblbrlymflight->insertRec(flt);

					eqp->hkUref = flt->ref;
					dbsbrly->tblbrlymequipment->updateRec(eqp);

					impcnt++;
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		// see that each leg w/o clust gets clust'ed
		for (unsigned int ix0=0;ix0<imeimleg.nodes.size();ix0++) {
			leg = imeimleg.nodes[ix0];

			if (leg->refBrlyCLeg == 0) {
				// try in legs first, then in oldlegs
				found = false;

				for (unsigned int i=ix0+1;i<imeimleg.nodes.size();i++) {
					leg2 = imeimleg.nodes[i];

					if ((leg2->bgnRefBrlyMLocation == leg->endRefBrlyMLocation) && (leg2->endRefBrlyMLocation == leg->bgnRefBrlyMLocation)) {
						leg->refBrlyCLeg = dbsbrly->tblbrlycleg->getNewRef();
						dbsbrly->tblbrlymleg->updateRec(leg);

						leg2->refBrlyCLeg = leg->refBrlyCLeg;
						dbsbrly->tblbrlymleg->updateRec(leg2);

						found = true;
					};
				};

				if (!found) {
					for (unsigned int i=0;i<oldlegs.nodes.size();i++) {
						oldleg = oldlegs.nodes[i];

						if ((oldleg->bgnRefBrlyMLocation == leg->endRefBrlyMLocation) && (oldleg->endRefBrlyMLocation == leg->bgnRefBrlyMLocation)) {
							leg->refBrlyCLeg = dbsbrly->tblbrlycleg->getNewRef();
							dbsbrly->tblbrlymleg->updateRec(leg);

							oldleg->refBrlyCLeg = leg->refBrlyCLeg;
							dbsbrly->tblbrlymleg->updateRec(oldleg);
						};
					};
				};
			};
		};

		for (unsigned int i=0;i<tofss.size();i++) delete tofss[i];

		if (bgncart) delete[] bgncart;
		if (endcart) delete[] endcart;
		
		delete eqp;
		// IP enterSgeImport.ppr --- IEND
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecBrlyVError::getIx, VecBrlyVError::getTitle, ixBrlyVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobBrlyIexTtb::leaveSgeImport(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobBrlyIexTtb::enterSgeImperr(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobBrlyIexTtb::leaveSgeImperr(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobBrlyIexTtb::enterSgeReverse(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMFlight* flt = NULL;
	ImeitemIMLeg* leg = NULL;

	// -- ImeIMFlight
	for (unsigned int ix0 = 0; ix0 < imeimflight.nodes.size(); ix0++) {
		flt = imeimflight.nodes[ix0];
		if (flt->ref != 0) dbsbrly->tblbrlymflight->removeRecByRef(flt->ref);
	};

	// -- ImeIMLeg
	for (unsigned int ix0 = 0; ix0 < imeimleg.nodes.size(); ix0++) {
		leg = imeimleg.nodes[ix0];
		if (leg->ref != 0) dbsbrly->tblbrlymleg->removeRecByRef(leg->ref);
	};

	return retval;
};

void JobBrlyIexTtb::leaveSgeReverse(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobBrlyIexTtb::enterSgeCollect(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMFlight* flt = NULL;
	ImeitemIMLeg* leg = NULL;

	uint ixBrlyVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMFlight
	for (unsigned int ix0 = 0; ix0 < imeimflight.nodes.size(); ix0++) {
		flt = imeimflight.nodes[ix0];

		if (flt->ref != 0) {
			//flt->hintRefBrlyMEquipment: STUB
			//flt->irefRefBrlyMLeg: IREF
			//flt->hintStart: STUB
			//flt->hintStop: STUB
			//flt->iDate: IARG
			//flt->iWeekday: IARG
		};
	};

	// -- ImeIMLeg
	for (unsigned int ix0 = 0; ix0 < imeimleg.nodes.size(); ix0++) {
		leg = imeimleg.nodes[ix0];

		if (leg->ref != 0) {
			leg->iref = ix0+1;
			leg->srefBgnRefBrlyMLocation = StubBrly::getStubLocSref(dbsbrly, leg->bgnRefBrlyMLocation, ixBrlyVLocale, Stub::VecVNonetype::VOID, stcch);
			leg->srefEndRefBrlyMLocation = StubBrly::getStubLocSref(dbsbrly, leg->endRefBrlyMLocation, ixBrlyVLocale, Stub::VecVNonetype::VOID, stcch);
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobBrlyIexTtb::leaveSgeCollect(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobBrlyIexTtb::enterSgeCltdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobBrlyIexTtb::leaveSgeCltdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobBrlyIexTtb::enterSgeExport(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexBrlyTtb::exportToFile(fullpath, xmlNotTxt, shorttags, imeimflight, imeimleg);

	return retval;
};

void JobBrlyIexTtb::leaveSgeExport(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobBrlyIexTtb::enterSgeDone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobBrlyIexTtb::leaveSgeDone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeDone --- INSERT
};
