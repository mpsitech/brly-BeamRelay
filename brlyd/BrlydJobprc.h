/**
	* \file BrlydJobprc.h
	* job processor for Brly daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDJOBPRC_H
#define BRLYDJOBPRC_H

/**
	* BrlydJobprc
	*/
namespace BrlydJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgBrlyd* xchg, DbsBrly* dbsbrly, ReqBrly* req);
};

#endif
