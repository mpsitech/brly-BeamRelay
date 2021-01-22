/**
	* \file VecBrlyVOpengtype.h
	* vector VecBrlyVOpengtype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef VECBRLYVOPENGTYPE_H
#define VECBRLYVOPENGTYPE_H

#include <sbecore/Xmlio.h>

/**
	* VecBrlyVOpengtype
	*/
namespace VecBrlyVOpengtype {
	const Sbecore::uint BRLYOPD = 1;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
	void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif
