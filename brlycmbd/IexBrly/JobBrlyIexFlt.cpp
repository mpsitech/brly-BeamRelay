/**
	* \file JobBrlyIexFlt.cpp
	* job handler for job JobBrlyIexFlt (implementation)
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

#include "JobBrlyIexFlt.h"

#include "JobBrlyIexFlt_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexBrlyFlt;

/******************************************************************************
 class JobBrlyIexFlt
 ******************************************************************************/

JobBrlyIexFlt::JobBrlyIexFlt(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::JOBBRLYIEXFLT, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbsbrly, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobBrlyIexFlt::~JobBrlyIexFlt() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobBrlyIexFlt::reset(
			DbsBrly* dbsbrly
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbsbrly, VecVSge::IDLE);
};

void JobBrlyIexFlt::parseFromFile(
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

void JobBrlyIexFlt::import(
			DbsBrly* dbsbrly
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbsbrly, VecVSge::IMPORT);
};

void JobBrlyIexFlt::reverse(
			DbsBrly* dbsbrly
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbsbrly, VecVSge::REVERSE);
};

void JobBrlyIexFlt::collect(
			DbsBrly* dbsbrly
			, const map<uint,uint>& _icsBrlyVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsBrlyVIop = _icsBrlyVIop;
		changeStage(dbsbrly, VecVSge::COLLECT);
	};
};

void JobBrlyIexFlt::exportToFile(
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

void JobBrlyIexFlt::handleRequest(
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

void JobBrlyIexFlt::changeStage(
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

string JobBrlyIexFlt::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing FlightAware flight data";
			else if (ixVSge == VecVSge::PRSDONE) retval = "FlightAware flight data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing FlightAware flight data (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing FlightAware flight data import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting FlightAware flight data for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "FlightAware flight data collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting FlightAware flight data";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing FlightAware flight data";
			else if (ixVSge == VecVSge::PRSDONE) retval = "FlightAware flight data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing FlightAware flight data (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing FlightAware flight data import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting FlightAware flight data for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "FlightAware flight data collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting FlightAware flight data";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobBrlyIexFlt::enterSgeIdle(
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

	imeimfaflight.clear();

	return retval;
};

void JobBrlyIexFlt::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobBrlyIexFlt::enterSgeParse(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexBrlyFlt::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimfaflight);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecBrlyVError::getIx, VecBrlyVError::getTitle, ixBrlyVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobBrlyIexFlt::leaveSgeParse(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobBrlyIexFlt::enterSgePrserr(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobBrlyIexFlt::leaveSgePrserr(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobBrlyIexFlt::enterSgePrsdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobBrlyIexFlt::leaveSgePrsdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobBrlyIexFlt::enterSgeImport(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMFaflight* faf = NULL;
	ImeitemIAMFaflightWaypoint* fafAwpt = NULL;

	uint num1;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint ref, ref2;

	map<string, ubigint> refsLoc;
	map<string, ubigint> refsLeg;
	map<string, ubigint>::iterator it;

	ListBrlyMFlight flts;
	BrlyMFlight* flt = NULL;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMFaflight
		for (unsigned int ix0 = 0; ix0 < imeimfaflight.nodes.size(); ix0++) {
			faf = imeimfaflight.nodes[ix0];

			faf->ixBrlyVIop = VecBrlyVIop::getIx(faf->srefIxBrlyVIop);
			if ((faf->ixBrlyVIop != VecBrlyVIop::INS) && (faf->ixBrlyVIop != VecBrlyVIop::RETR)) throw SbeException(SbeException::IEX_IOP, {{"iop",faf->srefIxBrlyVIop}, {"ime","ImeIMFaflight"}, {"lineno",to_string(faf->lineno)}});

			if (faf->ixBrlyVIop == VecBrlyVIop::RETR) {
				// retrieve
				dbsbrly->loadRefBySQL("SELECT ref FROM TblBrlyMFaflight WHERE faFlightID = '" + faf->faFlightID + "'", faf->ref);
				if (faf->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMFaflight"}, {"lineno",to_string(faf->lineno)}});

			} else {
				//faf->refBrlyMFlight: CUSTSQL
				ref = 0;
				it = refsLeg.find(faf->iLeg);

				if (it == refsLeg.end()) {
					if (faf->iLeg.length() == 7) {
						ref = 0;
						it = refsLoc.find(faf->iLeg.substr(0, 3));
						if (it == refsLoc.end()) {
							if (dbsbrly->tblbrlymlocation->loadRefBySrf(faf->iLeg.substr(0, 3), ref)) refsLoc[faf->iLeg.substr(0, 3)] = ref;
						} else {
							ref = it->second;
						};

						ref2 = 0;
						it = refsLoc.find(faf->iLeg.substr(4));
						if (it == refsLoc.end()) {
							if (dbsbrly->tblbrlymlocation->loadRefBySrf(faf->iLeg.substr(4), ref2)) refsLoc[faf->iLeg.substr(4)] = ref2;
						} else {
							ref2 = it->second;
						};

						if (dbsbrly->tblbrlymleg->loadRefByTypBloElo(VecBrlyVMLegBasetype::RTE, ref, ref2, ref)) {
							refsLeg[faf->iLeg] = ref;
						} else {
							ref = 0;
						};
					};

				} else {
					ref = it->second;
				};

				if (ref == 0) cout << "unable to find leg '" << faf->iLeg << "'" << endl;

				if (ref != 0) {
					dbsbrly->tblbrlymflight->loadRstBySQL("SELECT * FROM TblBrlyMFlight WHERE refBrlyMLeg = " + to_string(ref) + " AND start > " + to_string(faf->actualdeparturetime-6*3600)
								+ " AND start < " + to_string(faf->actualdeparturetime+6*3600), false, flts);

					if (flts.nodes.size() == 0) cout << faf->faFlightID << ": empty flts." << endl;

					for (unsigned int i = 0; i < flts.nodes.size();i++) {
						flt = flts.nodes[i];

						if (flt->sref.find(faf->hintRefBrlyMFlight + " ") == 0) {
							faf->refBrlyMFlight = flt->ref;
							break;
						};
					};
				};

				if (faf->refBrlyMFlight == 0) throw SbeException(SbeException::IEX_THINT, {{"thint",faf->hintRefBrlyMFlight}, {"iel","hintRefBrlyMFlight"}, {"lineno",to_string(faf->lineno)}});

				//faf->faFlightID: TBL
				//faf->ident: TBL
				//faf->aircrafttype: TBL
				//faf->filed_ete: TBL
				//faf->filed_time: TBL
				//faf->filed_departuretime: TBL
				//faf->filed_airspeed_kts: TBL
				//faf->filed_airspeed_mach: TBL
				//faf->filed_altitude: TBL
				//faf->route: TBL
				//faf->actualdeparturetime: TBL
				//faf->estimatedarrivaltime: TBL
				//faf->actualarrivaltime: TBL
				//faf->diverted: TBL
				//faf->origin: TBL
				//faf->destination: TBL
				//faf->originName: TBL
				//faf->originCity: TBL
				//faf->destinationName: TBL
				//faf->destinationCity: TBL

				dbsbrly->tblbrlymfaflight->insertRec(faf);
				impcnt++;

				flt->refBrlyMFaflight = faf->ref;
				dbsbrly->tblbrlymflight->updateRec(flt);
			};

			if (faf->ref != 0) {
				num1 = 1;

				for (unsigned int ix1 = 0; ix1 < faf->imeiamfaflightwaypoint.nodes.size(); ix1++) {
					fafAwpt = faf->imeiamfaflightwaypoint.nodes[ix1];

					fafAwpt->fafRefBrlyMFaflight = faf->ref;
					fafAwpt->fafNum = num1++;
					//fafAwpt->timestamp: TBL
					//fafAwpt->latitude: TBL
					//fafAwpt->longitude: TBL
					//fafAwpt->groundspeed: TBL
					//fafAwpt->altitude: TBL
					//fafAwpt->altitudeStatus: TBL
					//fafAwpt->updateType: TBL
					//fafAwpt->altitudeChange: TBL

					dbsbrly->tblbrlyamfaflightwaypoint->insertRec(fafAwpt);
					impcnt++;
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// -- ImeIMFaflight
		for (unsigned int ix0 = 0; ix0 < imeimfaflight.nodes.size(); ix0++) {
			faf = imeimfaflight.nodes[ix0];

			// retrieve
			//if (faf->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMFaflight"}, {"lineno",to_string(faf->lineno)}});

			faf->ixBrlyVIop = VecBrlyVIop::getIx(faf->srefIxBrlyVIop);
			if ((faf->ixBrlyVIop != VecBrlyVIop::INS) && (faf->ixBrlyVIop != VecBrlyVIop::RETR)) throw SbeException(SbeException::IEX_IOP, {{"iop",faf->srefIxBrlyVIop}, {"ime","ImeIMFaflight"}, {"lineno",to_string(faf->lineno)}});
			//faf->refBrlyMFlight: CUSTSQL
			//if (faf->refBrlyMFlight == 0) throw SbeException(SbeException::IEX_THINT, {{"thint",faf->hintRefBrlyMFlight}, {"iel","hintRefBrlyMFlight"}, {"lineno",to_string(faf->lineno)}});
			//faf->faFlightID: TBL
			//faf->ident: TBL
			//faf->aircrafttype: TBL
			//faf->filed_ete: TBL
			//faf->filed_time: TBL
			//faf->filed_departuretime: TBL
			//faf->filed_airspeed_kts: TBL
			//faf->filed_airspeed_mach: TBL
			//faf->filed_altitude: TBL
			//faf->route: TBL
			//faf->actualdeparturetime: TBL
			//faf->estimatedarrivaltime: TBL
			//faf->actualarrivaltime: TBL
			//faf->diverted: TBL
			//faf->origin: TBL
			//faf->destination: TBL
			//faf->originName: TBL
			//faf->originCity: TBL
			//faf->destinationName: TBL
			//faf->destinationCity: TBL

			dbsbrly->tblbrlymfaflight->insertRec(faf);
			impcnt++;

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < faf->imeiamfaflightwaypoint.nodes.size(); ix1++) {
				fafAwpt = faf->imeiamfaflightwaypoint.nodes[ix1];

				fafAwpt->fafRefBrlyMFaflight = faf->ref;
				fafAwpt->fafNum = num1++;
				//fafAwpt->timestamp: TBL
				//fafAwpt->latitude: TBL
				//fafAwpt->longitude: TBL
				//fafAwpt->groundspeed: TBL
				//fafAwpt->altitude: TBL
				//fafAwpt->altitudeStatus: TBL
				//fafAwpt->updateType: TBL
				//fafAwpt->altitudeChange: TBL

				dbsbrly->tblbrlyamfaflightwaypoint->insertRec(fafAwpt);
				impcnt++;
			};
		};
		// IP enterSgeImport.traverse --- END

		// IP enterSgeImport.ppr --- INSERT
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecBrlyVError::getIx, VecBrlyVError::getTitle, ixBrlyVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobBrlyIexFlt::leaveSgeImport(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobBrlyIexFlt::enterSgeImperr(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobBrlyIexFlt::leaveSgeImperr(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobBrlyIexFlt::enterSgeReverse(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMFaflight* faf = NULL;
	ImeitemIAMFaflightWaypoint* fafAwpt = NULL;

	// -- ImeIMFaflight
	for (unsigned int ix0 = 0; ix0 < imeimfaflight.nodes.size(); ix0++) {
		faf = imeimfaflight.nodes[ix0];
		if (faf->ref != 0) dbsbrly->tblbrlymfaflight->removeRecByRef(faf->ref);

		for (unsigned int ix1 = 0; ix1 < faf->imeiamfaflightwaypoint.nodes.size(); ix1++) {
			fafAwpt = faf->imeiamfaflightwaypoint.nodes[ix1];
			if (fafAwpt->ref != 0) dbsbrly->tblbrlyamfaflightwaypoint->removeRecByRef(fafAwpt->ref);
		};
	};

	return retval;
};

void JobBrlyIexFlt::leaveSgeReverse(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobBrlyIexFlt::enterSgeCollect(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMFaflight* faf = NULL;
	ImeitemIAMFaflightWaypoint* fafAwpt = NULL;

	uint ixBrlyVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMFaflight
	for (unsigned int ix0 = 0; ix0 < imeimfaflight.nodes.size(); ix0++) {
		faf = imeimfaflight.nodes[ix0];

		if (faf->ref != 0) {
			//faf->srefIxBrlyVIop: IOP
			//faf->iLeg: IARG
			//faf->hintRefBrlyMFlight: STUB
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIAMFAFLIGHTWAYPOINT, ixBrlyVIop)) {
			dbsbrly->tblbrlyamfaflightwaypoint->loadRefsByFaf(faf->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) faf->imeiamfaflightwaypoint.nodes.push_back(new ImeitemIAMFaflightWaypoint(dbsbrly, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < faf->imeiamfaflightwaypoint.nodes.size(); ix1++) {
			fafAwpt = faf->imeiamfaflightwaypoint.nodes[ix1];

			if (fafAwpt->ref != 0) {
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobBrlyIexFlt::leaveSgeCollect(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobBrlyIexFlt::enterSgeCltdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobBrlyIexFlt::leaveSgeCltdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobBrlyIexFlt::enterSgeExport(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexBrlyFlt::exportToFile(fullpath, xmlNotTxt, shorttags, imeimfaflight);

	return retval;
};

void JobBrlyIexFlt::leaveSgeExport(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobBrlyIexFlt::enterSgeDone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobBrlyIexFlt::leaveSgeDone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeDone --- INSERT
};
