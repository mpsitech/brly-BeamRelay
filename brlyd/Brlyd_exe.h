/**
	* \file Brlyd_exe.h
	* Brly daemon main (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYD_EXE_H
#define BRLYD_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

#include <signal.h>

#include "BrlydAppsrv.h"
#include "BrlydJobprc.h"
#include "BrlydOpengcli.h"
#include "BrlydOpengsrv.h"

/**
	* Brlyd
	*/
class Brlyd {

public:
	Brlyd(const std::string& exedir, const bool clearAll, const bool startMon);
	~Brlyd();

public:
	std::string exedir;

	DbsBrly dbsbrly;

	XchgBrlyd* xchg;
	
	RootBrly* root;

	MHD_Daemon* opengsrv;
	MHD_Daemon* appsrv;

	std::vector<pthread_t> jobprcs;

	pthread_t opengcli;

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif
