/**
	* \file BrlydOpengcli.h
	* operation engine client for Brly daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDOPENGCLI_H
#define BRLYDOPENGCLI_H

#include "BrlydOpprc.h"

/**
	* BrlydOpengcli
	*/
namespace BrlydOpengcli {
	void* run(void* arg);
	bool run_checkNodes(XchgBrly* xchg);

	bool CurlPostDpch(const std::string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, std::string& rplydpch);
	Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _arg);
};

/**
	* BrlydOpengcli_curlarg
	*/
struct BrlydOpengcli_curlarg {
	char* buf;
	size_t buflen;
};

#endif
