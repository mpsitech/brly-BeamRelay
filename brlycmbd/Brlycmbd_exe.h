/**
	* \file Brlycmbd_exe.h
	* Brly combined daemon main (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYCMBD_EXE_H
#define BRLYCMBD_EXE_H

#include <string>
#include <vector>

#include <signal.h>

#include "BrlycmbdAppsrv.h"
#include "BrlycmbdJobprc.h"
#include "BrlycmbdOpprc.h"

/**
	* Brlycmbd
	*/
class Brlycmbd {

public:
	Brlycmbd(const std::string& exedir, const bool clearAll, const bool startMon);
	~Brlycmbd();

public:
	std::string exedir;

	DbsBrly dbsbrly;

	XchgBrlycmbd* xchg;
	
	RootBrly* root;

	MHD_Daemon* appsrv;

	std::vector<pthread_t> jobprcs;

	std::vector<pthread_t> opprcs;

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif
