/**
	* \file BrlycmbdJobprc.h
	* job processor for Brly combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYCMBDJOBPRC_H
#define BRLYCMBDJOBPRC_H

/**
	* BrlycmbdJobprc
	*/
namespace BrlycmbdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgBrlycmbd* xchg, DbsBrly* dbsbrly, ReqBrly* req);
};

#endif
