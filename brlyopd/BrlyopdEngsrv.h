/**
	* \file BrlyopdEngsrv.h
	* engine server for Brly operation daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYOPDENGSRV_H
#define BRLYOPDENGSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

#include "BrlyTtimp_blks.h"
#include "BrlyMapgen_blks.h"
#include "BrlyDyn_blks.h"
#include "BrlyDnsmap_blks.h"
#include "BrlyBase_blks.h"

/**
	* BrlyopdEngsrv
	*/
namespace BrlyopdEngsrv {
	MHD_Daemon* start(XchgBrlyopd* xchg);
	void stop(MHD_Daemon* d);

	MHD_Result MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	MHD_Result MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
	MHD_Result MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	Sbecore::uint readDpchInv(ReqopBrly* req);
	void writeDpchAck(ReqopBrly* req);
	void writeDpchRet(ReqopBrly* req);
};

#endif
