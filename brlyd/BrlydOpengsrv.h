/**
	* \file BrlydOpengsrv.h
	* op engine server for Brly daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDOPENGSRV_H
#define BRLYDOPENGSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

/**
	* BrlydOpengsrv
	*/
namespace BrlydOpengsrv {
	MHD_Daemon* start(XchgBrly* xchg);
	void stop(MHD_Daemon* d);

	MHD_Result MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	MHD_Result MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
	MHD_Result MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	Sbecore::uint readDpch(XchgBrlyd* xchg, ReqopengconBrly* req);
	void writeDpchAck(ReqopengconBrly* req);
	void writeDpchReg(XchgBrlyd* xchg, ReqopengconBrly* req, const Sbecore::ubigint nref);
};

#endif
