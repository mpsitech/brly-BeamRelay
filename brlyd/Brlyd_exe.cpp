/**
	* \file Brlycmbd_exe.cpp
	* Brly combined daemon main (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "Brlyd.h"

#include "Brlyd_exe.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

Brlyd* brlyd;

/******************************************************************************
 class Brlyd
 ******************************************************************************/

Brlyd::Brlyd(
			const string& exedir
			, const bool clearAll
			, const bool startMon
		) {
	pthread_attr_t attr;

	srand(time(NULL));

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	mysql_library_init(0, NULL, NULL);
#endif

	// 1. create exchange object
	xchg = new XchgBrlyd();
	xchg->exedir = exedir;

	// 2. load preferences and SSL key/certificate
	loadPref();
	if (xchg->stgbrlyappsrv.https) loadKeycert();

	// 3. connect to database
	dbsbrly.init(xchg->stgbrlydatabase.ixDbsVDbstype, xchg->stgbrlydatabase.dbspath, xchg->stgbrlydatabase.dbsname, xchg->stgbrlydatabase.ip
			, xchg->stgbrlydatabase.port, xchg->stgbrlydatabase.username, xchg->stgbrlydatabase.password);

	// 4. initialize shared data
	xchg->shrdatJobprc.init(xchg, &dbsbrly);

	// 5. start monitoring (optional)
	if (startMon) xchg->startMon();

	// 6. establish root job
	root = new RootBrly(xchg, &dbsbrly, 0, clearAll);

	// 7. start job processor threads
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	cout << "\tstarting " << xchg->stgbrlyd.jobprcn << " job processor threads ... {" << flush;

	for (unsigned int i = 0; i < xchg->stgbrlyd.jobprcn; i++) {
		if (i != 0) cout << ", " << flush;

		xchg->cStable.lockMutex("Brlyd", "Brlyd[1]");

		jobprcs.push_back(0);
		pthread_create(&(jobprcs[i]), &attr, &BrlydJobprc::run, (void*) xchg);

		xchg->cStable.wait();
		xchg->cStable.unlockMutex("Brlyd", "Brlyd[1]");
	};

	cout << "} success" << endl;

	// 8. start op engine client thread
	cout << "\tstarting operation engine client thread ..." << flush;

	xchg->cStable.lockMutex("Brlyd", "Brlyd[2]");

	pthread_create(&opengcli, &attr, &BrlydOpengcli::run, (void*) xchg);

	xchg->cStable.wait();
	xchg->cStable.unlockMutex("Brlyd", "Brlyd[2]");

	cout << " success" << endl;

	// 9. start op engine server
	cout << "\tstarting operation engine server ..." << flush;
	opengsrv = BrlydOpengsrv::start(xchg);
	cout << " success" << endl;

	// 10. start web server
	if (xchg->stgbrlyd.appsrv) {
		cout << "\tstarting application server ..." << flush;
		appsrv = BrlydAppsrv::start(xchg);
		cout << " success" << endl;
	};

	pthread_attr_destroy(&attr);
};

Brlyd::~Brlyd() {

	// 3. stop web server
	if (xchg->stgbrlyd.appsrv) BrlydAppsrv::stop(appsrv);

	// 4. stop op engine server
	BrlydOpengsrv::stop(opengsrv);

	// 5. end op engine client thread (cURLs to all nodes with DpchBrlydQuit)
	xchg->cOpengcli.lockMutex("Brlyd", "term");
	xchg->termOpengcli = true;
	xchg->cOpengcli.unlockMutex("Brlyd", "term");

	xchg->cOpengcli.signal("Brlyd", "term");

	pthread_join(opengcli, NULL);

	// 6. end job processor threads
	for (unsigned int i = 0; i < jobprcs.size(); i++) {
		//if (jobprcs[i]) {
			pthread_cancel(jobprcs[i]);
			pthread_join(jobprcs[i], NULL);
		//};
	};

	// 7. delete root job
	delete root;
	root = NULL;

	// 8. terminate shared data
	xchg->shrdatJobprc.term(xchg);

	// 9. store preferences
	storePref();

	// 10. delete exchange object
	delete xchg;
};

void Brlyd::loadPref() {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	string basexpath;

	parseFile(xchg->exedir + "/PrefBrlyd.xml", &doc, &docctx);

	if (checkUclcXPaths(docctx, basexpath, "/", "PrefBrlyd")) {
		xchg->stgbrlyappearance.readXML(docctx, basexpath, true);
		xchg->stgbrlyappsrv.readXML(docctx, basexpath, true);
		xchg->stgbrlyd.readXML(docctx, basexpath, true);
		xchg->stgbrlydatabase.readXML(docctx, basexpath, true);
		xchg->stgbrlyflightaware.readXML(docctx, basexpath, true);
		xchg->stgbrlygeometry.readXML(docctx, basexpath, true);
		xchg->stgbrlymonitor.readXML(docctx, basexpath, true);
		xchg->stgbrlypath.readXML(docctx, basexpath, true);
	};

	closeParsed(doc, docctx);

	xchg->acvpath = xchg->stgbrlypath.acvpath;
#ifdef _WIN32
	if (_access(xchg->acvpath.c_str(), 0)) throw SbeException(SbeException::PATHNF, {{"path",xchg->acvpath}});
#else
	if (access(xchg->acvpath.c_str(), R_OK)) throw SbeException(SbeException::PATHNF, {{"path",xchg->acvpath}});
#endif

	xchg->tmppath = xchg->stgbrlypath.tmppath;
#ifdef _WIN32
	if (_access(xchg->tmppath.c_str(), 0)) throw SbeException(SbeException::PATHNF, {{"path",xchg->tmppath}});
#else
	if (access(xchg->tmppath.c_str(), R_OK)) throw SbeException(SbeException::PATHNF, {{"path",xchg->tmppath}});
#endif

	xchg->helpurl = xchg->stgbrlypath.helpurl;
};

void Brlyd::storePref() {
	xmlTextWriter* wr = NULL;

	startwriteFile(xchg->exedir + "/PrefBrlyd.xml", &wr);
	xmlTextWriterStartElement(wr, BAD_CAST "PrefBrlyd");
		xchg->stgbrlyappearance.writeXML(wr);
		xchg->stgbrlyappsrv.writeXML(wr);
		xchg->stgbrlyd.writeXML(wr);
		xchg->stgbrlydatabase.writeXML(wr);
		xchg->stgbrlyflightaware.writeXML(wr);
		xchg->stgbrlygeometry.writeXML(wr);
		xchg->stgbrlymonitor.writeXML(wr);
		xchg->stgbrlypath.writeXML(wr);
	xmlTextWriterEndElement(wr);
	closewriteFile(wr);
};

void Brlyd::loadKeycert() {
	ifstream infile;
	char* buf = new char[1048576];

	string s;

	// key file
	s = xchg->exedir + "/server.key";
	infile.open(s.c_str(), ifstream::in);
	if (infile.fail()) throw SbeException(SbeException::PATHNF, {{"path",s}});

	while (infile.good() && !infile.eof()) {
		s = StrMod::readLine(infile, buf, 1048576);
		xchg->key += s + "\n";
	};

	infile.close();

	// certificate file
	s = xchg->exedir + "/server.pem";
	infile.open(s.c_str(), ifstream::in);
	if (infile.fail()) throw SbeException(SbeException::PATHNF, {{"path",s}});

	while (infile.good() && !infile.eof()) {
		s = StrMod::readLine(infile, buf, 1048576);
		xchg->cert += s + "\n";
	};

	infile.close();

	delete[] buf;
};

/******************************************************************************
 settings for jobs
 ******************************************************************************/

/******************************************************************************
 shared data for jobs
 ******************************************************************************/

/******************************************************************************
 main program
 ******************************************************************************/

void showSubjobs(
			XchgBrlyd* xchg
			, JobBrly* job
			, Jobinfo* jobinfo
			, bool clstns
			, bool ops
			, bool presets
			, bool sges
			, bool dcolcont
			, bool stmgrcont
			, unsigned int indent
		) {
	string id;

	string setgray = "\033[38;2;196;196;196m";
	string reset = "\033[0m";

	bool csjobNotJob = false;
	bool srvNotCli = false;

	DcolBrly* dcol = NULL;
	StmgrBrly* stmgr = NULL;

	vector<uint> icsBrlyVCall;
	vector<uint> icsVJobmask;

	vector<uint> icsBrlyVPreset;
	vector<Arg> args;

	string s;

	// indentation
	for (unsigned int i = 0; i < indent; i++) id = id + "\t";

	// actual entry
	if (jobinfo->jrefsSub.empty()) cout << "\t" << id << "- ";
	else cout << "\t" << id << "+ ";
	cout << VecBrlyVJob::getSref(job->ixBrlyVJob);

	csjobNotJob = xchg->getCsjobNotJob(job->ixBrlyVJob);
	if (csjobNotJob) srvNotCli = ((CsjobBrly*) job)->srvNotCli;

	if (csjobNotJob) {
		if (srvNotCli) cout << "/SRV";
		else cout << "/CLI";
	};

	cout << " (" << job->jref;

	dcol = xchg->getDcolByJref(job->jref, false);
	if (dcol) {
		cout << ", dcol";
		dcol->unlockAccess("", "showSubjobs");
	};

	stmgr = xchg->getStmgrByJref(job->jref);
	if (stmgr) {
		cout << ", stmgr";
		stmgr->unlockAccess("", "showSubjobs");
	};

	cout << ")" << endl;

	if (clstns) {
		// call listeners
		cout << setgray;

		xchg->getClstnsByJref(job->jref, Clstn::VecVTarget::JOB, icsBrlyVCall, icsVJobmask);
		for (unsigned int i = 0; i < icsBrlyVCall.size(); i++)
					cout << "\t\t" << id << VecBrlyVCall::getSref(icsBrlyVCall[i]) << " (" << Clstn::VecVJobmask::getSref(icsVJobmask[i]) << ")" << endl;

		xchg->getClstnsByJref(job->jref, Clstn::VecVTarget::STMGR, icsBrlyVCall, icsVJobmask);
		for (unsigned int i = 0; i < icsBrlyVCall.size(); i++)
					cout << "\t\t" << id << "stmgr: " << VecBrlyVCall::getSref(icsBrlyVCall[i]) << endl;

		cout << reset;
	};

	if (ops) {
		// ops
		cout << setgray;

		job->mOps.lock("", "showSubjobs", "jref=" + to_string(job->jref));

		for (auto it = job->ops.begin(); it != job->ops.end(); it++)
					cout << "\t\t" << id << VecBrlyVDpch::getSref((*it)->ixVDpch).substr(4+3) << " (" << to_string((*it)->oref) << "): " << (*it)->squawk << endl;

		job->mOps.unlock("", "showSubjobs", "jref=" + to_string(job->jref));

		cout << reset;
	};

	if (presets) {
		// presettings
		cout << setgray;

		xchg->getPresetsByJref(job->jref, icsBrlyVPreset, args);

		for (unsigned int i = 0; i < icsBrlyVPreset.size(); i++)
					cout << "\t\t" << id << VecBrlyVPreset::getSref(icsBrlyVPreset[i]) << ": " << args[i].to_string() << endl;

		cout << reset;
	};

	if (sges) {
		// stages
		if (!csjobNotJob || (csjobNotJob && srvNotCli)) {
			s = job->getSquawk(NULL);

			if (s != "") {
				cout << setgray;

				cout << "\t\t" << id << job->ixVSge << ": " << s << endl;

				cout << reset;
			};
		};
	};

	if (dcolcont) {
		// dispatch collector content
		dcol = xchg->getDcolByJref(job->jref, false);

		if (dcol) {
			cout << setgray;

			for (auto it = dcol->dpchs.begin(); it != dcol->dpchs.end(); it++)
						cout << "\t\t" << id << VecBrlyVDpch::getSref((*it)->ixBrlyVDpch) << " (" << (*it)->jref << ")" << endl;

			dcol->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	if (stmgrcont) {
		// stub manager content
		stmgr = xchg->getStmgrByJref(job->jref);

		if (stmgr) {
			cout << setgray;

			for (auto it = stmgr->stcch->nodes.begin(); it != stmgr->stcch->nodes.end(); it++)
						cout << "\t\t" << id << VecBrlyVStub::getSref(it->second->stref.ixVStub) << " (" << it->second->stref.ref << "): " << it->second->stub << endl;

			stmgr->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	// sub-entries
	Jobinfo* jobinfo2 = NULL;

	for (auto it = jobinfo->jrefsSub.begin(); it != jobinfo->jrefsSub.end(); it++) {
		job = xchg->getJobByJref(*it);
		jobinfo2 = xchg->getJobinfoByJref(*it);

		if (job && jobinfo2) showSubjobs(xchg, job, jobinfo2, clstns, ops, presets, sges, dcolcont, stmgrcont, indent + 1);
	};
};

void handleSignal(
			int sig
		) {
	// deleting brlyd forces PrefBrlyd to be written
	if (brlyd) delete brlyd;

	exit(sig);
};

int main(
			const int argc
			, const char** argv
		) {
	char* buf = NULL;
	string exedir;
	size_t ptr;

	string s;
	bool nocp = false;
	bool clearAll = false;
	bool startMon = false;

	Cond cDummy("cDummy", "", "main");

	string cmd;

	string input;
	int iinput;

	string s_backup;

	XchgBrlyd* xchg;

	JobBrly* job;
	Jobinfo* jobinfo;

	ReqBrly* req;

	brlyd = NULL;

	// ensure proper termination on signals such as ctrl-c
#ifndef _WIN32
	signal(SIGHUP, handleSignal);
#endif
	signal(SIGINT, handleSignal); // 2
	signal(SIGTERM, handleSignal); // 15

	// evaluate command line options
	for (int i = 1; i < argc; i++) {
		s = argv[i];

		if (s.find("-exedir=") == 0) exedir = s.substr(8);
		else if (s == "-nocp") nocp = true;
		else if (s == "-clearAll") clearAll = true;
		else if (s == "-startMon") startMon = true;
	};

	if (exedir == "") {
		// determine executable path
		buf = new char[4096];

		if (readlink("/proc/self/exe", buf, 4096) >= 1) {
			exedir = buf;

		} else {
			if (strlen(argv[0]) >= 1) {
				exedir = argv[0];

				if (exedir[0] != '/') {
					if (getcwd(buf, 4096)) {
						exedir = "/" + exedir;
						exedir = buf + exedir;
					};
				};
			};
		};

		delete[] buf;

		ptr = exedir.rfind('/');
		if ((ptr != string::npos) && (ptr > 0)) exedir = exedir.substr(0, ptr);
	};

	try {
		// welcome message
		cout << "Welcome to BeamRelay v0.2.15!" << endl;

		// calls brlyd.init()
		brlyd = new Brlyd(exedir, clearAll, startMon);
		xchg = brlyd->xchg;

		cout << "Initialization complete." << endl;
		cout << endl;

		if (nocp) {
			// wait on a dummy condition
			cDummy.lockMutex("", "main");
			cDummy.wait("", "main");
			cDummy.unlockMutex("", "main");

		} else {
			// main command loop
			while (cmd != "quit") {
				cout << "Brlyd >> ";

				do {
					cin.clear();
					cin >> cmd;
				} while (cin.fail());

				if (cmd == "quit") {

				} else if (cmd == "cmdsetStd") {
					cout << "\tquit" << endl;

					cout << "\tstartMon" << endl;
					cout << "\tstopMon" << endl;

					cout << "\tstartMtdump" << endl;
					cout << "\tstopMtdump" << endl;

					cout << "\tshowNodes" << endl;

					cout << "\tshowJobs" << endl;
					cout << "\tshowSubjobs" << endl;

					cout << "\tshowClstns" << endl;
					cout << "\tshowOps" << endl;
					cout << "\tshowPresets" << endl;
					cout << "\tshowSges" << endl;

					cout << "\tshowDcolContent" << endl;
					cout << "\tshowStmgrContent" << endl;

					cout << "\tgotoJob" << endl;
					cout << "\tgotoSupjob" << endl;

				} else if (cmd == "startMon") {
					xchg->startMon();

				} else if (cmd == "stopMon") {
					xchg->stopMon();

				} else if (cmd == "startMtdump") {
					Mt::ixVVerbose = Mt::VecVVerbose::ALL;

				} else if (cmd == "stopMtdump") {
					Mt::ixVVerbose = Mt::VecVVerbose::ERROR;

				} else if (cmd == "showNodes") {
					NodeBrly* node = NULL;

					xchg->rwmNodes.rlock("", "main");

					for (auto it = xchg->nodes.begin(); it != xchg->nodes.end(); it++) {
						node = it->second;
						cout << "\tnode " << node->nref << " at " << node->ip << ":" << node->port << " running " << node->opprcn << " op processors" << endl;
					};

					xchg->rwmNodes.runlock("", "main");

				} else if ( (cmd == "showJobs") || (cmd == "showSubjobs") || (cmd == "showClstns") || (cmd == "showOps") || (cmd == "showPresets")
							|| (cmd == "showSges") || (cmd == "showDcolContent") || (cmd == "showStmgrContent") ) {

					xchg->rwmJobs.rlock("", "main[1]");

					if (cmd == "showSubjobs") {
						job = xchg->getJobByJref(xchg->jrefCmd);
						jobinfo = xchg->getJobinfoByJref(xchg->jrefCmd);
					} else {
						job = xchg->getJobByJref(xchg->jrefRoot);
						jobinfo = xchg->getJobinfoByJref(xchg->jrefRoot);
					};

					if (job && jobinfo) {
						if (cmd == "showJobs") showSubjobs(xchg, job, jobinfo, false, false, false, false, false, false, 0);
						else if (cmd == "showSubjobs") showSubjobs(xchg, job, jobinfo, false, false, false, false, false, false, 0);
						else if (cmd == "showClstns") showSubjobs(xchg, job, jobinfo, true, false, false, false, false, false, 0);
						else if (cmd == "showOps") showSubjobs(xchg, job, jobinfo, false, true, false, false, false, false, 0);
						else if (cmd == "showPresets") showSubjobs(xchg, job, jobinfo, false, false, true, false, false, false, 0);
						else if (cmd == "showSges") showSubjobs(xchg, job, jobinfo, false, false, false, true, false, false, 0);
						else if (cmd == "showDcolContent") showSubjobs(xchg, job, jobinfo, false, false, false, false, true, false, 0);
						else if (cmd == "showStmgrContent") showSubjobs(xchg, job, jobinfo, false, false, false, false, false, true, 0);
					};

					xchg->rwmJobs.runlock("", "main[1]");

				} else if (cmd == "gotoJob") {
					cout << "\tjob reference: ";
					cin >> input;
					iinput = atoi(input.c_str());

					if (xchg->getJobinfoByJref(iinput)) xchg->jrefCmd = iinput;
					else cout << "\tjob reference doesn't exist!" << endl;

				} else if (cmd == "gotoSupjob") {
					xchg->rwmJobs.rlock("", "main[2]");

					jobinfo = xchg->getJobinfoByJref(xchg->jrefCmd);

					if (jobinfo) {
						if (jobinfo->jrefSup != 0) xchg->jrefCmd = jobinfo->jrefSup;
						else cout << "\talready at topmost job!" << endl;
					};

					xchg->rwmJobs.runlock("", "main[2]");

				} else {
					job = xchg->getJobByJref(xchg->jrefCmd);

					if (job) {
						req = new ReqBrly(ReqBrly::VecVBasetype::CMD, ReqBrly::VecVState::RECEIVE);
						req->cmd = cmd;
						req->jref = xchg->jrefCmd;

						xchg->addReq(req);

						s_backup = "";

						while (req->ixVState != ReqBrly::VecVState::REPLY) {
							// wait for job processor to finish or to time out
							req->cReady.lockMutex("", "main");
							req->cReady.timedwait(1000000, "", "main");
							req->cReady.unlockMutex("", "main");

							if (req->ixVState == ReqBrly::VecVState::WAITPRC) {
								cout << "\twaiting for processing" << endl;

							} else if (req->ixVState == ReqBrly::VecVState::PRC) {
								s = job->getSquawk(&(brlyd->dbsbrly));
								if (s != s_backup) {
									cout << "\t" << s << endl;
									s_backup = s;
								};
							};
						};

						delete req;
					};
				};
			};
		};

		delete brlyd;

	} catch (BrlyException& e) {
		cout << e.getSquawk(VecBrlyVError::getIx, VecBrlyVError::getTitle, VecBrlyVLocale::ENUS) << endl;
		throw;

	} catch (SbeException& e) {
		cout << e.getSquawk(VecBrlyVError::getIx, VecBrlyVError::getTitle, VecBrlyVLocale::ENUS) << endl;
		throw;
	};

	return(0);
};
