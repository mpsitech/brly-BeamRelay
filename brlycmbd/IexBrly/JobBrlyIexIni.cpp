/**
	* \file JobBrlyIexIni.cpp
	* job handler for job JobBrlyIexIni (implementation)
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

#include "JobBrlyIexIni.h"

#include "JobBrlyIexIni_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexBrlyIni;

/******************************************************************************
 class JobBrlyIexIni
 ******************************************************************************/

JobBrlyIexIni::JobBrlyIexIni(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) :
			JobBrly(xchg, VecBrlyVJob::JOBBRLYIEXINI, jrefSup, ixBrlyVLocale)
		{
	jref = xchg->addJob(dbsbrly, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbsbrly, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobBrlyIexIni::~JobBrlyIexIni() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
double JobBrlyIexIni::radToDeg(
			double _rad																					// angle in degrees (0° .. 360°)
		) {
	return(180.0*_rad/pi);
};
// IP cust --- IEND

void JobBrlyIexIni::reset(
			DbsBrly* dbsbrly
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbsbrly, VecVSge::IDLE);
};

void JobBrlyIexIni::parseFromFile(
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

void JobBrlyIexIni::import(
			DbsBrly* dbsbrly
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbsbrly, VecVSge::IMPORT);
};

void JobBrlyIexIni::reverse(
			DbsBrly* dbsbrly
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbsbrly, VecVSge::REVERSE);
};

void JobBrlyIexIni::collect(
			DbsBrly* dbsbrly
			, const map<uint,uint>& _icsBrlyVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsBrlyVIop = _icsBrlyVIop;
		changeStage(dbsbrly, VecVSge::COLLECT);
	};
};

void JobBrlyIexIni::exportToFile(
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

void JobBrlyIexIni::handleRequest(
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

void JobBrlyIexIni::changeStage(
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

string JobBrlyIexIni::getSquawk(
			DbsBrly* dbsbrly
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing initialization data import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting initialization data for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "initialization data collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting initialization data";
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing initialization data import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting initialization data for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "initialization data collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting initialization data";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobBrlyIexIni::enterSgeIdle(
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

	imeiavcontrolpar.clear();
	imeiavkeylistkey.clear();
	imeiavvaluelistval.clear();
	imeimfile.clear();
	imeimlocation.clear();
	imeimoperator.clear();
	imeimplntype.clear();
	imeimregion.clear();
	imeimusergroup.clear();

	return retval;
};

void JobBrlyIexIni::leaveSgeIdle(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobBrlyIexIni::enterSgeParse(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexBrlyIni::parseFromFile(fullpath, xmlNotTxt, rectpath, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimlocation, imeimoperator, imeimplntype, imeimregion, imeimusergroup);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecBrlyVError::getIx, VecBrlyVError::getTitle, ixBrlyVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobBrlyIexIni::leaveSgeParse(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobBrlyIexIni::enterSgePrserr(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobBrlyIexIni::leaveSgePrserr(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobBrlyIexIni::enterSgePrsdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobBrlyIexIni::leaveSgePrsdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobBrlyIexIni::enterSgeImport(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMLocation* loc = NULL;
	ImeitemIMOperator* opr = NULL;
	ImeitemIMPlntype* pty = NULL;
	ImeitemIMRegion* reg = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMRegionDstswitch* regAdss = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* klkJkey = NULL;
	ImeitemIJMRegion* regJ = NULL;
	ImeitemIJMRegionTitle* regJtit = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint num0;

	// IP enterSgeImport.prep --- IBEGIN
	ImeitemIMRegion* reg2 = NULL;

	ubigint refEaon;
	BrlyMEquipment* eqp = NULL;
	
	string s;

	double earthradius = xchg->stgbrlygeometry.earthradius;
	double hrznaltitude = xchg->stgbrlygeometry.hrznaltitude;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIAVControlPar
		for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
			ctlApar = imeiavcontrolpar.nodes[ix0];

			ctlApar->ixBrlyVControl = VecBrlyVControl::getIx(ctlApar->srefIxBrlyVControl);
			if (ctlApar->ixBrlyVControl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",ctlApar->srefIxBrlyVControl}, {"iel","srefIxBrlyVControl"}, {"lineno",to_string(ctlApar->lineno)}});
			//ctlApar->Par: TBL
			//ctlApar->Val: TBL

			dbsbrly->tblbrlyavcontrolpar->insertRec(ctlApar);
			impcnt++;
		};

		// -- ImeIAVKeylistKey
		for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey.nodes.size(); ix0++) {
			klsAkey = imeiavkeylistkey.nodes[ix0];

			klsAkey->klsIxBrlyVKeylist = VecBrlyVKeylist::getIx(klsAkey->srefKlsIxBrlyVKeylist);
			if (klsAkey->klsIxBrlyVKeylist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",klsAkey->srefKlsIxBrlyVKeylist}, {"iel","srefKlsIxBrlyVKeylist"}, {"lineno",to_string(klsAkey->lineno)}});
			//klsAkey->klsNum: CUST
			klsAkey->klsNum = (ix0+1); // TBD
			klsAkey->x1IxBrlyVMaintable = VecBrlyVMaintable::VOID;
			klsAkey->Fixed = true;
			//klsAkey->sref: TBL
			//klsAkey->Avail: TBL
			//klsAkey->Implied: TBL
			//klsAkey->refJ: SUB
			//klsAkey->Title: TBL
			//klsAkey->Comment: TBL

			dbsbrly->tblbrlyavkeylistkey->insertRec(klsAkey);
			impcnt++;

			if (((klsAkey->Title != "") || (klsAkey->Comment != "")) && klsAkey->imeijavkeylistkey.nodes.empty()) {
				klkJkey = new ImeitemIJAVKeylistKey();
				klsAkey->imeijavkeylistkey.nodes.push_back(klkJkey);

				klkJkey->refBrlyAVKeylistKey = klsAkey->ref;
				klkJkey->Title = klsAkey->Title;
				klkJkey->Comment = klsAkey->Comment;
			};

			for (unsigned int ix1 = 0; ix1 < klsAkey->imeijavkeylistkey.nodes.size(); ix1++) {
				klkJkey = klsAkey->imeijavkeylistkey.nodes[ix1];

				klkJkey->refBrlyAVKeylistKey = klsAkey->ref;
				if (klkJkey->srefX1IxBrlyVLocale == "") klkJkey->srefX1IxBrlyVLocale = "enus";
				klkJkey->x1IxBrlyVLocale = VecBrlyVLocale::getIx(klkJkey->srefX1IxBrlyVLocale);
				if (klkJkey->x1IxBrlyVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",klkJkey->srefX1IxBrlyVLocale}, {"iel","srefX1IxBrlyVLocale"}, {"lineno",to_string(klkJkey->lineno)}});
				//klkJkey->Title: TBL
				//klkJkey->Comment: TBL

				dbsbrly->tblbrlyjavkeylistkey->insertRec(klkJkey);
				impcnt++;

				if (ix1 == 0) {
					klsAkey->refJ = klkJkey->ref;
					klsAkey->Title = klkJkey->Title;
					klsAkey->Comment = klkJkey->Comment;
					dbsbrly->tblbrlyavkeylistkey->updateRec(klsAkey);
				};
			};
		};

		// -- ImeIAVValuelistVal
		for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
			vlsAval = imeiavvaluelistval.nodes[ix0];

			vlsAval->vlsIxBrlyVValuelist = VecBrlyVValuelist::getIx(vlsAval->srefVlsIxBrlyVValuelist);
			if (vlsAval->vlsIxBrlyVValuelist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vlsAval->srefVlsIxBrlyVValuelist}, {"iel","srefVlsIxBrlyVValuelist"}, {"lineno",to_string(vlsAval->lineno)}});
			//vlsAval->vlsNum: CUST
			vlsAval->vlsNum = (ix0+1);
			vlsAval->x1IxBrlyVLocale = VecBrlyVLocale::getIx(vlsAval->srefX1IxBrlyVLocale);
			if (vlsAval->x1IxBrlyVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vlsAval->srefX1IxBrlyVLocale}, {"iel","srefX1IxBrlyVLocale"}, {"lineno",to_string(vlsAval->lineno)}});
			//vlsAval->Val: TBL

			dbsbrly->tblbrlyavvaluelistval->insertRec(vlsAval);
			impcnt++;
		};

		// -- ImeIMOperator
		for (unsigned int ix0 = 0; ix0 < imeimoperator.nodes.size(); ix0++) {
			opr = imeimoperator.nodes[ix0];

			//opr->sref: TBL
			//opr->srefICAO: TBL
			//opr->Title: TBL

			dbsbrly->tblbrlymoperator->insertRec(opr);
			impcnt++;

			if (opr->sref.compare("EaOn") == 0) refEaon = opr->ref;
		};

		// -- ImeIMPlntype
		for (unsigned int ix0 = 0; ix0 < imeimplntype.nodes.size(); ix0++) {
			pty = imeimplntype.nodes[ix0];

			//pty->sref: TBL
			//pty->Title: TBL
			//pty->srefBrlyKEqptype: TBL
			//pty->Capacity: TBL

			dbsbrly->tblbrlymplntype->insertRec(pty);
			impcnt++;
		};

		// -- ImeIMRegion
		for (unsigned int ix0 = 0; ix0 < imeimregion.nodes.size(); ix0++) {
			reg = imeimregion.nodes[ix0];

			//reg->supRefBrlyMRegion: IMPPP
			for (unsigned int i = 0; i < ix0; i++) {
				reg2 = imeimregion.nodes[i];

				s = reg2->sref;
				if (reg2->hsrefSupRefBrlyMRegion.length() > 0) s = reg2->hsrefSupRefBrlyMRegion + ";" + s;

				if (s == reg->hsrefSupRefBrlyMRegion) {
					reg->supRefBrlyMRegion = reg2->ref;
					break;
				};
			};
			//reg->sref: TBL
			//reg->refJTitle: SUB
			//reg->Title: TBL
			//reg->refJ: SUB
			if (reg->srefIxVDst != "") {
				reg->ixVDst = VecBrlyVMRegionDst::getIx(reg->srefIxVDst);
				if (reg->ixVDst == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",reg->srefIxVDst}, {"iel","srefIxVDst"}, {"lineno",to_string(reg->lineno)}});
			};
			//reg->toffset: TBL

			dbsbrly->tblbrlymregion->insertRec(reg);
			impcnt++;

			if (((reg->Title != "")) && reg->imeijmregiontitle.nodes.empty()) {
				regJtit = new ImeitemIJMRegionTitle();
				reg->imeijmregiontitle.nodes.push_back(regJtit);

				regJtit->refBrlyMRegion = reg->ref;
				regJtit->Title = reg->Title;
			};

			if (((reg->srefIxVDst != "") || (reg->toffset != 0.0)) && reg->imeijmregion.nodes.empty()) {
				regJ = new ImeitemIJMRegion();
				reg->imeijmregion.nodes.push_back(regJ);

				regJ->refBrlyMRegion = reg->ref;
				regJ->srefIxVDst = reg->srefIxVDst;
				regJ->toffset = reg->toffset;
			};

			for (unsigned int ix1 = 0; ix1 < reg->imeiamregiondstswitch.nodes.size(); ix1++) {
				regAdss = reg->imeiamregiondstswitch.nodes[ix1];

				regAdss->refBrlyMRegion = reg->ref;
				regAdss->startd = Ftm::invdate(regAdss->ftmStartd);
				if (regAdss->startd == 0) throw SbeException(SbeException::IEX_FTM, {{"ftm",regAdss->ftmStartd}, {"iel","ftmStartd"}, {"lineno",to_string(regAdss->lineno)}});
				regAdss->startt = Ftm::invtime(regAdss->ftmStartt);
				//if (regAdss->startt == 0) throw SbeException(SbeException::IEX_FTM, {{"ftm",regAdss->ftmStartt}, {"iel","ftmStartt"}, {"lineno",to_string(regAdss->lineno)}});

				dbsbrly->tblbrlyamregiondstswitch->insertRec(regAdss);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < reg->imeijmregion.nodes.size(); ix1++) {
				regJ = reg->imeijmregion.nodes[ix1];

				regJ->refBrlyMRegion = reg->ref;
				if (regJ->ftmX1Startd != "") {
					regJ->x1Startd = Ftm::invdate(regJ->ftmX1Startd);
					if (regJ->x1Startd == 0) throw SbeException(SbeException::IEX_FTM, {{"ftm",regJ->ftmX1Startd}, {"iel","ftmX1Startd"}, {"lineno",to_string(regJ->lineno)}});
				};
				if (regJ->ftmX1Stopd != "") {
					regJ->x1Stopd = Ftm::invdate(regJ->ftmX1Stopd);
					if (regJ->x1Stopd == 0) throw SbeException(SbeException::IEX_FTM, {{"ftm",regJ->ftmX1Stopd}, {"iel","ftmX1Stopd"}, {"lineno",to_string(regJ->lineno)}});
				};
				regJ->ixVDst = VecBrlyVMRegionDst::getIx(regJ->srefIxVDst);
				if (regJ->ixVDst == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",regJ->srefIxVDst}, {"iel","srefIxVDst"}, {"lineno",to_string(regJ->lineno)}});
				//regJ->toffset: TBL

				dbsbrly->tblbrlyjmregion->insertRec(regJ);
				impcnt++;

				if (ix1 == 0) {
					reg->refJ = regJ->ref;
					reg->ixVDst = regJ->ixVDst;
					reg->toffset = regJ->toffset;
					dbsbrly->tblbrlymregion->updateRec(reg);
				};
			};

			for (unsigned int ix1 = 0; ix1 < reg->imeijmregiontitle.nodes.size(); ix1++) {
				regJtit = reg->imeijmregiontitle.nodes[ix1];

				regJtit->refBrlyMRegion = reg->ref;
				if (regJtit->srefX1IxBrlyVLocale == "") regJtit->srefX1IxBrlyVLocale = "enus";
				regJtit->x1IxBrlyVLocale = VecBrlyVLocale::getIx(regJtit->srefX1IxBrlyVLocale);
				if (regJtit->x1IxBrlyVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",regJtit->srefX1IxBrlyVLocale}, {"iel","srefX1IxBrlyVLocale"}, {"lineno",to_string(regJtit->lineno)}});
				//regJtit->Title: TBL

				dbsbrly->tblbrlyjmregiontitle->insertRec(regJtit);
				impcnt++;

				if (ix1 == 0) {
					reg->refJTitle = regJtit->ref;
					reg->Title = regJtit->Title;
					dbsbrly->tblbrlymregion->updateRec(reg);
				};
			};
		};

		// -- ImeIMFile
		for (unsigned int ix0 = 0; ix0 < imeimfile.nodes.size(); ix0++) {
			fil = imeimfile.nodes[ix0];

			fil->refIxVTbl = VecBrlyVMFileRefTbl::VOID;
			//fil->osrefKContent: TBL
			//fil->Filename: TBL
			//fil->srefKMimetype: TBL
			//fil->Comment: TBL
			//fil->Archived = PP (DlgBrlyNavLoaini);
			//fil->Archivename = PP (DlgBrlyNavLoaini);
			//fil->Size = PP (DlgBrlyNavLoaini);

			dbsbrly->tblbrlymfile->insertRec(fil);
			impcnt++;
		};

		// -- ImeIMLocation
		for (unsigned int ix0 = 0; ix0 < imeimlocation.nodes.size(); ix0++) {
			loc = imeimlocation.nodes[ix0];

			loc->ixVBasetype = VecBrlyVMLocationBasetype::getIx(loc->srefIxVBasetype);
			if (loc->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",loc->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(loc->lineno)}});
			//loc->refBrlyMRegion: PREVIMP
			for (unsigned int i=0;i<imeimregion.nodes.size();i++) {
				reg = imeimregion.nodes[i];

				s = reg->sref;
				if (reg->hsrefSupRefBrlyMRegion.length() > 0) s = reg->hsrefSupRefBrlyMRegion + ";" + s;

				if (s == loc->hsrefRefBrlyMRegion) {
					loc->refBrlyMRegion = reg->ref;
					break;
				};
			};
			if (loc->refBrlyMRegion == 0) throw SbeException(SbeException::IEX_THSREF, {{"thsref",loc->hsrefRefBrlyMRegion}, {"iel","hsrefRefBrlyMRegion"}, {"lineno",to_string(loc->lineno)}});
			//loc->refBrlyMEquipment: CUSTSQLPP
			//loc->sref: TBL
			//loc->srefICAO: TBL
			//loc->Title: TBL
			//loc->alt: TBL
			//loc->theta: TBL
			//loc->phi: TBL
			//loc->tz: TBL
			loc->alpha = 0.0;
			if ((loc->ixVBasetype == VecBrlyVMLocationBasetype::APT) || (loc->ixVBasetype == VecBrlyVMLocationBasetype::GND)) {
				loc->alpha = 85.0;
			} else if (loc->ixVBasetype == VecBrlyVMLocationBasetype::ELV) {
				loc->alpha = radToDeg(acos((earthradius + hrznaltitude) / (earthradius + loc->alt)));
			};
			loc->Calcdone = false;

			// uinc'ed equipment
			if (loc->ixVBasetype == VecBrlyVMLocationBasetype::ELV) {
				if (loc->alt <= 4000.0) dbsbrly->tblbrlymequipment->insertNewRec(&eqp, VecBrlyVMEquipmentHkTbl::LOC, 0, refEaon, 0, "bll", true);
				else dbsbrly->tblbrlymequipment->insertNewRec(&eqp, VecBrlyVMEquipmentHkTbl::LOC, 0, refEaon, 0, "blh", true);
			} else {
				dbsbrly->tblbrlymequipment->insertNewRec(&eqp, VecBrlyVMEquipmentHkTbl::LOC, 0, refEaon, 0, "gnd", true);
			};
			loc->refBrlyMEquipment = eqp->ref;

			dbsbrly->tblbrlymlocation->insertRec(loc);
			impcnt++;

			eqp->hkUref = loc->ref;
			dbsbrly->tblbrlymequipment->updateRec(eqp);
			delete eqp;
		};

		// -- ImeIMUsergroup
		for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
			usg = imeimusergroup.nodes[ix0];

			//usg->sref: TBL
			//usg->Comment: TBL

			dbsbrly->tblbrlymusergroup->insertRec(usg);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
				usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

				usgAacc->refBrlyMUsergroup = usg->ref;
				usgAacc->x1IxBrlyVFeatgroup = VecBrlyVFeatgroup::getIx(usgAacc->srefX1IxBrlyVFeatgroup);
				if (usgAacc->x1IxBrlyVFeatgroup == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usgAacc->srefX1IxBrlyVFeatgroup}, {"iel","srefX1IxBrlyVFeatgroup"}, {"lineno",to_string(usgAacc->lineno)}});
				//usgAacc->x2FeaSrefUix: TBL
				usgAacc->ixBrlyWAccess = VecBrlyWAccess::getIx(usgAacc->srefsIxBrlyWAccess);

				dbsbrly->tblbrlyamusergroupaccess->insertRec(usgAacc);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
				usr = usg->imeimuser.nodes[ix1];

				//usr->refRUsergroup: IMPPP
				usr->refBrlyMUsergroup = usg->ref;
				//usr->refBrlyMPerson: SUB
				//usr->sref: TBL
				//usr->refJState: SUB
				if (usr->srefIxVState != "") {
					usr->ixVState = VecBrlyVMUserState::getIx(usr->srefIxVState);
					if (usr->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(usr->lineno)}});
				};
				usr->ixBrlyVLocale = VecBrlyVLocale::getIx(usr->srefIxBrlyVLocale);
				if (usr->ixBrlyVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxBrlyVLocale}, {"iel","srefIxBrlyVLocale"}, {"lineno",to_string(usr->lineno)}});
				usr->ixBrlyVUserlevel = VecBrlyVUserlevel::getIx(usr->srefIxBrlyVUserlevel);
				if (usr->ixBrlyVUserlevel == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxBrlyVUserlevel}, {"iel","srefIxBrlyVUserlevel"}, {"lineno",to_string(usr->lineno)}});
				//usr->Password: TBL
				//usr->Fullkey: TBL
				//usr->Comment: TBL

				dbsbrly->tblbrlymuser->insertRec(usr);
				impcnt++;

				usr->refRUsergroup = dbsbrly->tblbrlyrmusermusergroup->insertNewRec(NULL, usr->ref, usg->ref, usr->ixBrlyVUserlevel);
				usr->refBrlyMUsergroup = usg->ref;
				dbsbrly->tblbrlymuser->updateRec(usr);

				if (((usr->srefIxVState != "")) && usr->imeijmuserstate.nodes.empty()) {
					usrJste = new ImeitemIJMUserState();
					usr->imeijmuserstate.nodes.push_back(usrJste);

					usrJste->refBrlyMUser = usr->ref;
					usrJste->srefIxVState = usr->srefIxVState;
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
					usrAacc = usr->imeiamuseraccess.nodes[ix2];

					usrAacc->refBrlyMUser = usr->ref;
					usrAacc->x1IxBrlyVFeatgroup = VecBrlyVFeatgroup::getIx(usrAacc->srefX1IxBrlyVFeatgroup);
					if (usrAacc->x1IxBrlyVFeatgroup == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usrAacc->srefX1IxBrlyVFeatgroup}, {"iel","srefX1IxBrlyVFeatgroup"}, {"lineno",to_string(usrAacc->lineno)}});
					//usrAacc->x2FeaSrefUix: TBL
					usrAacc->ixBrlyWAccess = VecBrlyWAccess::getIx(usrAacc->srefsIxBrlyWAccess);

					dbsbrly->tblbrlyamuseraccess->insertRec(usrAacc);
					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
					usrJste = usr->imeijmuserstate.nodes[ix2];

					usrJste->refBrlyMUser = usr->ref;
					usrJste->x1Start = Ftm::invstamp("&now;");
					usrJste->ixVState = VecBrlyVMUserState::getIx(usrJste->srefIxVState);
					if (usrJste->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usrJste->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(usrJste->lineno)}});

					dbsbrly->tblbrlyjmuserstate->insertRec(usrJste);
					impcnt++;

					if (ix2 == 0) {
						usr->refJState = usrJste->ref;
						usr->ixVState = usrJste->ixVState;
						dbsbrly->tblbrlymuser->updateRec(usr);
					};
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
					prs = usr->imeimperson.nodes[ix2];

					prs->ixWDerivate = VecBrlyWMPersonDerivate::USR;
					prs->ixVSex = VecBrlyVMPersonSex::getIx(prs->srefIxVSex);
					if (prs->ixVSex == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prs->srefIxVSex}, {"iel","srefIxVSex"}, {"lineno",to_string(prs->lineno)}});
					//prs->Title: TBL
					//prs->Firstname: TBL
					//prs->refJLastname: SUB
					//prs->Lastname: TBL

					dbsbrly->tblbrlymperson->insertRec(prs);
					impcnt++;

					if (((prs->Lastname != "")) && prs->imeijmpersonlastname.nodes.empty()) {
						prsJlnm = new ImeitemIJMPersonLastname();
						prs->imeijmpersonlastname.nodes.push_back(prsJlnm);

						prsJlnm->refBrlyMPerson = prs->ref;
						prsJlnm->Lastname = prs->Lastname;
					};

					if (ix2 == 0) {
						usr->refBrlyMPerson = prs->ref;
						dbsbrly->tblbrlymuser->updateRec(usr);
					};

					for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
						prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

						prsJlnm->refBrlyMPerson = prs->ref;
						prsJlnm->x1Startd = Ftm::invdate("&today;");
						//prsJlnm->Lastname: TBL

						dbsbrly->tblbrlyjmpersonlastname->insertRec(prsJlnm);
						impcnt++;

						if (ix3 == 0) {
							prs->refJLastname = prsJlnm->ref;
							prs->Lastname = prsJlnm->Lastname;
							dbsbrly->tblbrlymperson->updateRec(prs);
						};
					};
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- INSERT
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecBrlyVError::getIx, VecBrlyVError::getTitle, ixBrlyVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobBrlyIexIni::leaveSgeImport(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobBrlyIexIni::enterSgeImperr(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobBrlyIexIni::leaveSgeImperr(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobBrlyIexIni::enterSgeReverse(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMLocation* loc = NULL;
	ImeitemIMOperator* opr = NULL;
	ImeitemIMPlntype* pty = NULL;
	ImeitemIMRegion* reg = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMRegionDstswitch* regAdss = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* klkJkey = NULL;
	ImeitemIJMRegion* regJ = NULL;
	ImeitemIJMRegionTitle* regJtit = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	// -- ImeIAVControlPar
	for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];
		if (ctlApar->ref != 0) dbsbrly->tblbrlyavcontrolpar->removeRecByRef(ctlApar->ref);
	};

	// -- ImeIAVKeylistKey
	for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey.nodes.size(); ix0++) {
		klsAkey = imeiavkeylistkey.nodes[ix0];
		if (klsAkey->ref != 0) dbsbrly->tblbrlyavkeylistkey->removeRecByRef(klsAkey->ref);

		for (unsigned int ix1 = 0; ix1 < klsAkey->imeijavkeylistkey.nodes.size(); ix1++) {
			klkJkey = klsAkey->imeijavkeylistkey.nodes[ix1];
			if (klkJkey->ref != 0) dbsbrly->tblbrlyjavkeylistkey->removeRecByRef(klkJkey->ref);
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];
		if (vlsAval->ref != 0) dbsbrly->tblbrlyavvaluelistval->removeRecByRef(vlsAval->ref);
	};

	// -- ImeIMFile
	for (unsigned int ix0 = 0; ix0 < imeimfile.nodes.size(); ix0++) {
		fil = imeimfile.nodes[ix0];
		if (fil->ref != 0) dbsbrly->tblbrlymfile->removeRecByRef(fil->ref);
	};

	// -- ImeIMLocation
	for (unsigned int ix0 = 0; ix0 < imeimlocation.nodes.size(); ix0++) {
		loc = imeimlocation.nodes[ix0];
		if (loc->ref != 0) dbsbrly->tblbrlymlocation->removeRecByRef(loc->ref);
	};

	// -- ImeIMOperator
	for (unsigned int ix0 = 0; ix0 < imeimoperator.nodes.size(); ix0++) {
		opr = imeimoperator.nodes[ix0];
		if (opr->ref != 0) dbsbrly->tblbrlymoperator->removeRecByRef(opr->ref);
	};

	// -- ImeIMPlntype
	for (unsigned int ix0 = 0; ix0 < imeimplntype.nodes.size(); ix0++) {
		pty = imeimplntype.nodes[ix0];
		if (pty->ref != 0) dbsbrly->tblbrlymplntype->removeRecByRef(pty->ref);
	};

	// -- ImeIMRegion
	for (unsigned int ix0 = 0; ix0 < imeimregion.nodes.size(); ix0++) {
		reg = imeimregion.nodes[ix0];
		if (reg->ref != 0) dbsbrly->tblbrlymregion->removeRecByRef(reg->ref);

		for (unsigned int ix1 = 0; ix1 < reg->imeiamregiondstswitch.nodes.size(); ix1++) {
			regAdss = reg->imeiamregiondstswitch.nodes[ix1];
			if (regAdss->ref != 0) dbsbrly->tblbrlyamregiondstswitch->removeRecByRef(regAdss->ref);
		};

		for (unsigned int ix1 = 0; ix1 < reg->imeijmregion.nodes.size(); ix1++) {
			regJ = reg->imeijmregion.nodes[ix1];
			if (regJ->ref != 0) dbsbrly->tblbrlyjmregion->removeRecByRef(regJ->ref);
		};

		for (unsigned int ix1 = 0; ix1 < reg->imeijmregiontitle.nodes.size(); ix1++) {
			regJtit = reg->imeijmregiontitle.nodes[ix1];
			if (regJtit->ref != 0) dbsbrly->tblbrlyjmregiontitle->removeRecByRef(regJtit->ref);
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
		usg = imeimusergroup.nodes[ix0];
		if (usg->ref != 0) dbsbrly->tblbrlymusergroup->removeRecByRef(usg->ref);

		for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];
			if (usgAacc->ref != 0) dbsbrly->tblbrlyamusergroupaccess->removeRecByRef(usgAacc->ref);
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
			usr = usg->imeimuser.nodes[ix1];
			if (usr->ref != 0) dbsbrly->tblbrlymuser->removeRecByRef(usr->ref);

			for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];
				if (usrAacc->ref != 0) dbsbrly->tblbrlyamuseraccess->removeRecByRef(usrAacc->ref);
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];
				if (usrJste->ref != 0) dbsbrly->tblbrlyjmuserstate->removeRecByRef(usrJste->ref);
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
				prs = usr->imeimperson.nodes[ix2];
				if (prs->ref != 0) dbsbrly->tblbrlymperson->removeRecByRef(prs->ref);

				for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];
					if (prsJlnm->ref != 0) dbsbrly->tblbrlyjmpersonlastname->removeRecByRef(prsJlnm->ref);
				};
			};
		};
	};

	return retval;
};

void JobBrlyIexIni::leaveSgeReverse(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobBrlyIexIni::enterSgeCollect(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMLocation* loc = NULL;
	ImeitemIMOperator* opr = NULL;
	ImeitemIMPlntype* pty = NULL;
	ImeitemIMRegion* reg = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMRegionDstswitch* regAdss = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* klkJkey = NULL;
	ImeitemIJMRegion* regJ = NULL;
	ImeitemIJMRegionTitle* regJtit = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint ixBrlyVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		if (ctlApar->ref != 0) {
		};
	};

	// -- ImeIAVKeylistKey
	for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey.nodes.size(); ix0++) {
		klsAkey = imeiavkeylistkey.nodes[ix0];

		if (klsAkey->ref != 0) {
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIJAVKEYLISTKEY, ixBrlyVIop)) {
			dbsbrly->tblbrlyjavkeylistkey->loadRefsByKlk(klsAkey->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey->refJ) {refs[i] = refs[0]; refs[0] = klsAkey->refJ; break;};
			for (unsigned int i = 0; i < refs.size(); i++) klsAkey->imeijavkeylistkey.nodes.push_back(new ImeitemIJAVKeylistKey(dbsbrly, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < klsAkey->imeijavkeylistkey.nodes.size(); ix1++) {
			klkJkey = klsAkey->imeijavkeylistkey.nodes[ix1];

			if (klkJkey->ref != 0) {
			};
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		if (vlsAval->ref != 0) {
		};
	};

	// -- ImeIMFile
	for (unsigned int ix0 = 0; ix0 < imeimfile.nodes.size(); ix0++) {
		fil = imeimfile.nodes[ix0];

		if (fil->ref != 0) {
		};
	};

	// -- ImeIMLocation
	for (unsigned int ix0 = 0; ix0 < imeimlocation.nodes.size(); ix0++) {
		loc = imeimlocation.nodes[ix0];

		if (loc->ref != 0) {
			loc->hsrefRefBrlyMRegion = StubBrly::getStubRegHsref(dbsbrly, loc->refBrlyMRegion, ixBrlyVLocale, Stub::VecVNonetype::VOID, stcch);
		};
	};

	// -- ImeIMOperator
	for (unsigned int ix0 = 0; ix0 < imeimoperator.nodes.size(); ix0++) {
		opr = imeimoperator.nodes[ix0];

		if (opr->ref != 0) {
		};
	};

	// -- ImeIMPlntype
	for (unsigned int ix0 = 0; ix0 < imeimplntype.nodes.size(); ix0++) {
		pty = imeimplntype.nodes[ix0];

		if (pty->ref != 0) {
		};
	};

	// -- ImeIMRegion
	for (unsigned int ix0 = 0; ix0 < imeimregion.nodes.size(); ix0++) {
		reg = imeimregion.nodes[ix0];

		if (reg->ref != 0) {
			reg->hsrefSupRefBrlyMRegion = StubBrly::getStubRegHsref(dbsbrly, reg->supRefBrlyMRegion, ixBrlyVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIAMREGIONDSTSWITCH, ixBrlyVIop)) {
			dbsbrly->tblbrlyamregiondstswitch->loadRefsByReg(reg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) reg->imeiamregiondstswitch.nodes.push_back(new ImeitemIAMRegionDstswitch(dbsbrly, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < reg->imeiamregiondstswitch.nodes.size(); ix1++) {
			regAdss = reg->imeiamregiondstswitch.nodes[ix1];

			if (regAdss->ref != 0) {
			};
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIJMREGION, ixBrlyVIop)) {
			dbsbrly->tblbrlyjmregion->loadRefsByReg(reg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == reg->refJ) {refs[i] = refs[0]; refs[0] = reg->refJ; break;};
			for (unsigned int i = 0; i < refs.size(); i++) reg->imeijmregion.nodes.push_back(new ImeitemIJMRegion(dbsbrly, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < reg->imeijmregion.nodes.size(); ix1++) {
			regJ = reg->imeijmregion.nodes[ix1];

			if (regJ->ref != 0) {
			};
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIJMREGIONTITLE, ixBrlyVIop)) {
			dbsbrly->tblbrlyjmregiontitle->loadRefsByReg(reg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == reg->refJTitle) {refs[i] = refs[0]; refs[0] = reg->refJTitle; break;};
			for (unsigned int i = 0; i < refs.size(); i++) reg->imeijmregiontitle.nodes.push_back(new ImeitemIJMRegionTitle(dbsbrly, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < reg->imeijmregiontitle.nodes.size(); ix1++) {
			regJtit = reg->imeijmregiontitle.nodes[ix1];

			if (regJtit->ref != 0) {
			};
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
		usg = imeimusergroup.nodes[ix0];

		if (usg->ref != 0) {
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIAMUSERGROUPACCESS, ixBrlyVIop)) {
			dbsbrly->tblbrlyamusergroupaccess->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) usg->imeiamusergroupaccess.nodes.push_back(new ImeitemIAMUsergroupAccess(dbsbrly, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			if (usgAacc->ref != 0) {
			};
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIMUSER, ixBrlyVIop)) {
			dbsbrly->tblbrlymuser->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) usg->imeimuser.nodes.push_back(new ImeitemIMUser(dbsbrly, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			if (usr->ref != 0) {
			};

			if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIAMUSERACCESS, ixBrlyVIop)) {
				dbsbrly->tblbrlyamuseraccess->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) usr->imeiamuseraccess.nodes.push_back(new ImeitemIAMUserAccess(dbsbrly, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];

				if (usrAacc->ref != 0) {
				};
			};

			if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIJMUSERSTATE, ixBrlyVIop)) {
				dbsbrly->tblbrlyjmuserstate->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == usr->refJState) {refs[i] = refs[0]; refs[0] = usr->refJState; break;};
				for (unsigned int i = 0; i < refs.size(); i++) usr->imeijmuserstate.nodes.push_back(new ImeitemIJMUserState(dbsbrly, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				if (usrJste->ref != 0) {
				};
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				if (prs->ref != 0) {
				};

				if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIJMPERSONLASTNAME, ixBrlyVIop)) {
					dbsbrly->tblbrlyjmpersonlastname->loadRefsByPrs(prs->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == prs->refJLastname) {refs[i] = refs[0]; refs[0] = prs->refJLastname; break;};
					for (unsigned int i = 0; i < refs.size(); i++) prs->imeijmpersonlastname.nodes.push_back(new ImeitemIJMPersonLastname(dbsbrly, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					if (prsJlnm->ref != 0) {
					};
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobBrlyIexIni::leaveSgeCollect(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobBrlyIexIni::enterSgeCltdone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobBrlyIexIni::leaveSgeCltdone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobBrlyIexIni::enterSgeExport(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexBrlyIni::exportToFile(fullpath, xmlNotTxt, shorttags, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimlocation, imeimoperator, imeimplntype, imeimregion, imeimusergroup);

	return retval;
};

void JobBrlyIexIni::leaveSgeExport(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobBrlyIexIni::enterSgeDone(
			DbsBrly* dbsbrly
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobBrlyIexIni::leaveSgeDone(
			DbsBrly* dbsbrly
		) {
	// IP leaveSgeDone --- INSERT
};
