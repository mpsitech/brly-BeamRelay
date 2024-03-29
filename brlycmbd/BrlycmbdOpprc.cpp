/**
	* \file BrlycmbdOpprc.cpp
	* operation processor for Brly combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "Brlycmbd.h"

#include "BrlycmbdOpprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace BrlycmbdOpprc
 ******************************************************************************/

void* BrlycmbdOpprc::run(
			void* arg
		) {
	XchgBrlycmbd* xchg = (XchgBrlycmbd*) arg;

	ReqBrly* req = NULL;
	DpchInvBrly* inv = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	cout << Mt::getTid() << flush;

	// open database connection
	DbsBrly dbsbrly;
	int contry = 10;

	while (contry > 0) {
		try {
			dbsbrly.init(xchg->stgbrlydatabase.ixDbsVDbstype, xchg->stgbrlydatabase.dbspath, xchg->stgbrlydatabase.dbsname, xchg->stgbrlydatabase.ip
						, xchg->stgbrlydatabase.port, xchg->stgbrlydatabase.username, xchg->stgbrlydatabase.password);
			break;

		} catch (SbeException& e) {
			contry--;

			if (contry == 0) {
				e.vals["tid"] = Mt::getTid();
				e.vals["object"] = "BrlycmbdOpprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("BrlycmbdOpprc", "run");

	try {
		// main loop: wait for operation invocations
		while (true) {
			xchg->cOpprcs.lockMutex("BrlycmbdOpprc", "run");
			inv = xchg->pullFirstInv();

			while (!inv) {
				xchg->cOpprcs.wait("BrlycmbdOpprc", "run");
				inv = xchg->pullFirstInv();
			};

			xchg->cOpprcs.unlockMutex("BrlycmbdOpprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cOpprcs.signal("BrlycmbdOpprc", "run");

			// prepare request
			req = new ReqBrly(ReqBrly::VecVBasetype::DPCHRET);

			req->jref = inv->jref;
			req->dpchinv = inv;

			// perform op
			if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELEGLEG) {
				req->dpchret = BrlyBaseLegleg::run(xchg, &dbsbrly, (DpchInvBrlyBaseLegleg*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELEGLOC) {
				req->dpchret = BrlyBaseLegloc::run(xchg, &dbsbrly, (DpchInvBrlyBaseLegloc*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELOCLOC) {
				req->dpchret = BrlyBaseLocloc::run(xchg, &dbsbrly, (DpchInvBrlyBaseLocloc*) req->dpchinv);
			};
			if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPCOLLECT) {
				req->dpchret = BrlyDnsmapCollect::run(xchg, &dbsbrly, (DpchInvBrlyDnsmapCollect*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPFRAME) {
				req->dpchret = BrlyDnsmapFrame::run(xchg, &dbsbrly, (DpchInvBrlyDnsmapFrame*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPVIDEO) {
				req->dpchret = BrlyDnsmapVideo::run(xchg, &dbsbrly, (DpchInvBrlyDnsmapVideo*) req->dpchinv);
			};
			if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNCONFLT) {
				req->dpchret = BrlyDynConflt::run(xchg, &dbsbrly, (DpchInvBrlyDynConflt*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNCONSEG) {
				req->dpchret = BrlyDynConseg::run(xchg, &dbsbrly, (DpchInvBrlyDynConseg*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNEQPLIST) {
				req->dpchret = BrlyDynEqplist::run(xchg, &dbsbrly, (DpchInvBrlyDynEqplist*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNFLTFLTLOC) {
				req->dpchret = BrlyDynFltfltloc::run(xchg, &dbsbrly, (DpchInvBrlyDynFltfltloc*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNFLTSEG) {
				req->dpchret = BrlyDynFltseg::run(xchg, &dbsbrly, (DpchInvBrlyDynFltseg*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNRLY) {
				req->dpchret = BrlyDynRly::run(xchg, &dbsbrly, (DpchInvBrlyDynRly*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNSEGLOCSEG) {
				req->dpchret = BrlyDynSeglocseg::run(xchg, &dbsbrly, (DpchInvBrlyDynSeglocseg*) req->dpchinv);
			};
			if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENCONMAP) {
				req->dpchret = BrlyMapgenConmap::run(xchg, &dbsbrly, (DpchInvBrlyMapgenConmap*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENLEGMAP) {
				req->dpchret = BrlyMapgenLegmap::run(xchg, &dbsbrly, (DpchInvBrlyMapgenLegmap*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENLOCMAP) {
				req->dpchret = BrlyMapgenLocmap::run(xchg, &dbsbrly, (DpchInvBrlyMapgenLocmap*) req->dpchinv);
			};
			if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYTTIMPRAWSTAR) {
				req->dpchret = BrlyTtimpRawstar::run(xchg, &dbsbrly, (DpchInvBrlyTtimpRawstar*) req->dpchinv);
			};

			if (req->dpchret) {
				req->dpchret->oref = req->dpchinv->oref;
				req->dpchret->jref = req->dpchinv->jref;

				xchg->addReq(req);

			} else {
				delete req;
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

void BrlycmbdOpprc::cleanup(
			void* arg
		) {
	XchgBrlycmbd* xchg = (XchgBrlycmbd*) arg;

	xchg->cOpprcs.unlockMutex("BrlycmbdOpprc", "cleanup");
};
