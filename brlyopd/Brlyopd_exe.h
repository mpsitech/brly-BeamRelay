/**
	* \file Brlyopd_exe.h
	* Brly operation daemon brlyopd main (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYOPD_EXE_H
#define BRLYOPD_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

#include <signal.h>

#include "BrlyopdEngsrv.h"
#include "BrlyopdOpprc.h"

/**
	* Brlyopd
	*/
class Brlyopd {

public:
	Brlyopd(const std::string& exedir, const Sbecore::usmallint engsrvportofs);
	~Brlyopd();

public:
	std::string exedir;

	DbsBrly dbsbrly;

	XchgBrlyopd* xchg;

	MHD_Daemon* engsrv;

	std::vector<pthread_t> opprcs;

public:
	char* curlbuf;
	size_t curlbuflen;

	bool CurlPostDpch(const std::string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, std::string& rplydpch);
	static Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _inst);

public:
	void loadPref();
	void storePref();
};

#endif
