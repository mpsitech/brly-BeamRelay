/**
	* \file VecBrlyVReqitmode.h
	* vector VecBrlyVReqitmode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef VECBRLYVREQITMODE_H
#define VECBRLYVREQITMODE_H

#include <sbecore/Xmlio.h>

/**
	* VecBrlyVReqitmode
	*/
namespace VecBrlyVReqitmode {
	const Sbecore::uint IDLE = 1;
	const Sbecore::uint NOTIFY = 2;
	const Sbecore::uint POLL = 3;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
