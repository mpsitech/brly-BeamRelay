/**
	* \file BrlydOpprc.h
	* operation processor for Brly daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDOPPRC_H
#define BRLYDOPPRC_H

/**
	* BrlydOpprc
	*/
namespace BrlydOpprc {
	void* run(void* arg);
	void cleanup(void* _arg);

	Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _ret);

	void writeDpchInv(CURL* curl, XchgBrlyd* xchg, ReqBrly* req);
	Sbecore::uint readDpchRet(XchgBrlyd* xchg, ReqBrly* req);
};

/**
	* BrlydOpprc_arg
	*/
struct BrlydOpprc_arg {
	XchgBrlyd* xchg;
	NodeBrly* node;
};

/**
	* BrlydOpprc_cuarg
	*/
struct BrlydOpprc_cuarg {
	XchgBrlyd* xchg;
	ReqBrly** req;
	Sbecore::ubigint* oref;
	Sbecore::ubigint* jref;
};

#endif
