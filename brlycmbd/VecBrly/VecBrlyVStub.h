/**
	* \file VecBrlyVStub.h
	* vector VecBrlyVStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef VECBRLYVSTUB_H
#define VECBRLYVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecBrlyVStub
	*/
namespace VecBrlyVStub {
	const Sbecore::uint STUBBRLYGROUP = 1;
	const Sbecore::uint STUBBRLYUSGSTD = 2;
	const Sbecore::uint STUBBRLYOWNER = 3;
	const Sbecore::uint STUBBRLYUSRSTD = 4;
	const Sbecore::uint STUBBRLYTTBSTD = 5;
	const Sbecore::uint STUBBRLYTTBTITLE = 6;
	const Sbecore::uint STUBBRLYSESMENU = 7;
	const Sbecore::uint STUBBRLYSESSTD = 8;
	const Sbecore::uint STUBBRLYSEGSTD = 9;
	const Sbecore::uint STUBBRLYRLYLONG = 10;
	const Sbecore::uint STUBBRLYRLYSTD = 11;
	const Sbecore::uint STUBBRLYREGHSREF = 12;
	const Sbecore::uint STUBBRLYREGLONG = 13;
	const Sbecore::uint STUBBRLYREGSTD = 14;
	const Sbecore::uint STUBBRLYPTYSREF = 15;
	const Sbecore::uint STUBBRLYPTYSTD = 16;
	const Sbecore::uint STUBBRLYPRSSTD = 17;
	const Sbecore::uint STUBBRLYOPRSREF = 18;
	const Sbecore::uint STUBBRLYOPRSTD = 19;
	const Sbecore::uint STUBBRLYNDELONG = 20;
	const Sbecore::uint STUBBRLYNDESTD = 21;
	const Sbecore::uint STUBBRLYLOCSREF = 22;
	const Sbecore::uint STUBBRLYLOCSTD = 23;
	const Sbecore::uint STUBBRLYLOCTITLE = 24;
	const Sbecore::uint STUBBRLYFAFSTD = 25;
	const Sbecore::uint STUBBRLYFILSTD = 26;
	const Sbecore::uint STUBBRLYFLTSREF = 27;
	const Sbecore::uint STUBBRLYFLTSTD = 28;
	const Sbecore::uint STUBBRLYLEGSHORT = 29;
	const Sbecore::uint STUBBRLYLEGSTD = 30;
	const Sbecore::uint STUBBRLYEQPSHORT = 31;
	const Sbecore::uint STUBBRLYEQPSTD = 32;
	const Sbecore::uint STUBBRLYCONSTD = 33;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
