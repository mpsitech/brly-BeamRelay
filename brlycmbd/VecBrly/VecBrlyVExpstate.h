/**
	* \file VecBrlyVExpstate.h
	* vector VecBrlyVExpstate (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef VECBRLYVEXPSTATE_H
#define VECBRLYVEXPSTATE_H

#include <sbecore/Xmlio.h>

/**
	* VecBrlyVExpstate
	*/
namespace VecBrlyVExpstate {
	const Sbecore::uint DETD = 1;
	const Sbecore::uint MAXD = 2;
	const Sbecore::uint MIND = 3;
	const Sbecore::uint REGD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
