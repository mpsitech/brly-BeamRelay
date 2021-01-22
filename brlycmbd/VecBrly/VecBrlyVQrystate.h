/**
	* \file VecBrlyVQrystate.h
	* vector VecBrlyVQrystate (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef VECBRLYVQRYSTATE_H
#define VECBRLYVQRYSTATE_H

#include <sbecore/Xmlio.h>

/**
	* VecBrlyVQrystate
	*/
namespace VecBrlyVQrystate {
	const Sbecore::uint MNR = 1;
	const Sbecore::uint OOD = 2;
	const Sbecore::uint SLM = 3;
	const Sbecore::uint UTD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

	void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif
