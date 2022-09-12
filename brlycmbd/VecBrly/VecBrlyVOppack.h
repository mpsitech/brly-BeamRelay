/**
	* \file VecBrlyVOppack.h
	* vector VecBrlyVOppack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef VECBRLYVOPPACK_H
#define VECBRLYVOPPACK_H

#include <sbecore/Xmlio.h>

/**
	* VecBrlyVOppack
	*/
namespace VecBrlyVOppack {
	const Sbecore::uint BRLYBASE = 1;
	const Sbecore::uint BRLYDNSMAP = 2;
	const Sbecore::uint BRLYDYN = 3;
	const Sbecore::uint BRLYMAPGEN = 4;
	const Sbecore::uint BRLYTTIMP = 5;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix);
	std::string getComment(const Sbecore::uint ix);

	void appendToFeed(const Sbecore::uint ix, Sbecore::Feed& feed);
	void fillFeed(Sbecore::Feed& feed);
};

#endif
