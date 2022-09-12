/**
	* \file BrlycmbdJobprc.cpp
	* job processor for Brly combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "Brlycmbd.h"

#include "BrlycmbdJobprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace BrlycmbdJobprc
 ******************************************************************************/

void* BrlycmbdJobprc::run(
			void* arg
		) {
	XchgBrlycmbd* xchg = (XchgBrlycmbd*) arg;

	ReqBrly* req = NULL;
	JobBrly* job = NULL;

	ubigint eref;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	cout << Mt::getTid() << flush;

	// open database connection
	DbsBrly dbsbrly;
	int contry = 10;

	while (contry > 0) {
		try {
			dbsbrly.init(xchg->stgbrlydatabase.ixDbsVDbstype, xchg->stgbrlydatabase.dbspath, xchg->stgbrlydatabase.dbsname, xchg->stgbrlydatabase.ip,
						xchg->stgbrlydatabase.port, xchg->stgbrlydatabase.username, xchg->stgbrlydatabase.password);
			break;

		} catch (SbeException& e) {
			contry--;

			if (contry == 0) {
				e.vals["tid"] = Mt::getTid();
				e.vals["object"] = "BrlycmbdJobprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("BrlycmbdJobprc", "run");

	try {
		// main loop: wait for requests
		while (true) {
			xchg->cJobprcs.lockMutex("BrlycmbdJobprc", "run");
			req = xchg->pullFirstReq();

			while (!req) {
				xchg->cJobprcs.wait("BrlycmbdJobprc", "run");
				req = xchg->pullFirstReq();
			};

			xchg->cJobprcs.unlockMutex("BrlycmbdJobprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cJobprcs.signal("BrlycmbdJobprc", "run");

			// --- handle request
			if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
				xchg->mon.eventHandleReqCmd(req->jref, req->cmd);

				// pass on to job
				accessJob(xchg, &dbsbrly, req);

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DPCHAPP) {
				if (req->dpchapp) {
					//cout << "BrlycmbdJobprc::run() DPCHAPP request:'" << VecBrlyVDpch::getSref(req->dpchapp->ixBrlyVDpch) << "'" << endl;
					eref = xchg->mon.eventHandleReqDpchapp(req->jref, VecBrlyVDpch::getSref(req->dpchapp->ixBrlyVDpch), req->dpchapp->getSrefsMask(), "");

					// pass on to job
					accessJob(xchg, &dbsbrly, req);
				};

				if (!req->dpcheng) req->dpcheng = new DpchEngBrlyAck(req->jref);
				xchg->mon.eventReplyReqDpchapp(eref, req->jref, VecBrlyVDpch::getSref(req->dpcheng->ixBrlyVDpch), req->dpcheng->getSrefsMask(), "");

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::UPLOAD) {
				//cout << "BrlycmbdJobprc::run() UPLOAD request file name: '" << req->filename << "'" << endl;
				xchg->mon.eventHandleReqUpload(req->jref, req->filename);

				// pass on to job
				accessJob(xchg, &dbsbrly, req);

				// usually the job leaves req unchanged

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DOWNLOAD) {
				eref = xchg->mon.eventHandleReqDownload(req->jref);

				// pass on to job
				accessJob(xchg, &dbsbrly, req);

				xchg->mon.eventReplyReqDownload(eref, req->jref, req->filename);

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DPCHRET) {
				if (req->dpchret) {
					//cout << "BrlycmbdJobprc::run() DPCHRET request: '" << VecBrlyVDpch::getSref(req->dpchret->ixBrlyVDpch) << "'" << endl;

					job = xchg->getJobByJref(req->jref);
					if (job) job->removeOp(req->dpchret->oref);

					xchg->mon.eventHandleReqDpchret(req->jref, VecBrlyVDpch::getSref(req->dpchret->ixBrlyVDpch), "", req->dpchret->oref);

					accessJob(xchg, &dbsbrly, req);
				};

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::METHOD) {
				if (req->method) {
					//cout << "BrlycmbdJobprc::run() METHOD request: '" << VecBrlyVFeatgroup::getSref(req->method->ixVFeatgroup) << "." << req->method->srefIxVMethod << "'" << endl;
					xchg->mon.eventHandleReqMethod(req->jref, VecBrlyVFeatgroup::getSref(req->method->ixVFeatgroup), req->method->srefIxVMethod);

					// pass on to job
					accessJob(xchg, &dbsbrly, req);
				};

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::TIMER) {
				// pass on to job
				job = xchg->getJobByJref(req->jref);

				if (job) if (req->wref >= job->wrefMin) {
					xchg->mon.eventHandleReqTimer(req->jref, req->sref);
					accessJob(xchg, &dbsbrly, req);
				};

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::EXTCALL) {
				xchg->triggerCall(&dbsbrly, req->call);
			};

			if ((req->ixVBasetype == ReqBrly::VecVBasetype::DPCHRET) || (req->ixVBasetype == ReqBrly::VecVBasetype::TIMER) || (req->ixVBasetype == ReqBrly::VecVBasetype::EXTCALL)) {
				// ret, timer and extcall requests can be deleted here
				delete req;

			} else {
				// all other requests are being waited for for further processing
				if (!(req->retain)) req->setStateReply();
			};
		};

	} catch (BrlyException& e) {
		cout << e.getSquawk(VecBrlyVError::getIx, VecBrlyVError::getTitle, VecBrlyVLocale::ENUS) << endl;
		throw;

	} catch (SbeException& e) {
		cout << e.getSquawk(VecBrlyVError::getIx, VecBrlyVError::getTitle, VecBrlyVLocale::ENUS) << endl;
		throw;
	};

	pthread_cleanup_pop(1);

	return(NULL);
};

void BrlycmbdJobprc::cleanup(
			void* arg
		) {
	XchgBrlycmbd* xchg = (XchgBrlycmbd*) arg;

	xchg->cJobprcs.unlockMutex("BrlycmbdJobprc", "cleanup");
};

void BrlycmbdJobprc::accessJob(
			XchgBrlycmbd* xchg
			, DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	time_t rawtime;

	JobBrly* job = NULL;

	if ((req->ixVBasetype == ReqBrly::VecVBasetype::CMD) || (req->ixVBasetype == ReqBrly::VecVBasetype::DPCHAPP) || (req->ixVBasetype == ReqBrly::VecVBasetype::UPLOAD) || (req->ixVBasetype == ReqBrly::VecVBasetype::DOWNLOAD)) {
		if ((xchg->stgbrlyappearance.roottterm != 0) || (xchg->stgbrlyappearance.sesstterm != 0)) {
			time(&rawtime);
			xchg->triggerIxRefCall(dbsbrly, VecBrlyVCall::CALLBRLYREFPRESET, req->jref, VecBrlyVPreset::PREBRLYTLAST, rawtime);
		};
	};

	job = xchg->getJobByJref(req->jref);
	if (job) {
		if (!req->weak) job->lockAccess("BrlycmbdJobprc", "accessJob");

		req->ixBrlyVLocale = job->ixBrlyVLocale;
		job->handleRequest(dbsbrly, req);
	};

	if (!req->weak) {
		job = xchg->getJobByJref(req->jref);
		if (job) job->unlockAccess("BrlycmbdJobprc", "accessJob");
	};
};
