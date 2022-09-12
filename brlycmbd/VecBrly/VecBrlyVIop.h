/**
	* \file VecBrlyVIop.h
	* vector VecBrlyVIop (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef VECBRLYVIOP_H
#define VECBRLYVIOP_H

#include <sbecore/Xmlio.h>

/**
	* VecBrlyVIop
	*/
namespace VecBrlyVIop {
	const Sbecore::uint INS = 1;
	const Sbecore::uint RETR = 2;
	const Sbecore::uint RETRINS = 3;
	const Sbecore::uint RETRUPD = 4;
	const Sbecore::uint RETRUPDINS = 5;
	const Sbecore::uint RMV = 6;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

	void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
};

#endif
