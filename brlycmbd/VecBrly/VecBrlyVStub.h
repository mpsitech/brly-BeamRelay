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
	const Sbecore::uint STUBBRLYCONSTD = 1;
	const Sbecore::uint STUBBRLYEQPSHORT = 2;
	const Sbecore::uint STUBBRLYEQPSTD = 3;
	const Sbecore::uint STUBBRLYFAFSTD = 4;
	const Sbecore::uint STUBBRLYFILSTD = 5;
	const Sbecore::uint STUBBRLYFLTSREF = 6;
	const Sbecore::uint STUBBRLYFLTSTD = 7;
	const Sbecore::uint STUBBRLYLEGSHORT = 8;
	const Sbecore::uint STUBBRLYLEGSTD = 9;
	const Sbecore::uint STUBBRLYLOCSREF = 10;
	const Sbecore::uint STUBBRLYLOCSTD = 11;
	const Sbecore::uint STUBBRLYLOCTITLE = 12;
	const Sbecore::uint STUBBRLYNDELONG = 13;
	const Sbecore::uint STUBBRLYNDESTD = 14;
	const Sbecore::uint STUBBRLYOPRSREF = 15;
	const Sbecore::uint STUBBRLYOPRSTD = 16;
	const Sbecore::uint STUBBRLYPRSSTD = 17;
	const Sbecore::uint STUBBRLYPTYSREF = 18;
	const Sbecore::uint STUBBRLYPTYSTD = 19;
	const Sbecore::uint STUBBRLYREGHSREF = 20;
	const Sbecore::uint STUBBRLYREGLONG = 21;
	const Sbecore::uint STUBBRLYREGSTD = 22;
	const Sbecore::uint STUBBRLYRLYLONG = 23;
	const Sbecore::uint STUBBRLYRLYSTD = 24;
	const Sbecore::uint STUBBRLYSEGSTD = 25;
	const Sbecore::uint STUBBRLYSESMENU = 26;
	const Sbecore::uint STUBBRLYSESSTD = 27;
	const Sbecore::uint STUBBRLYTTBSTD = 28;
	const Sbecore::uint STUBBRLYTTBTITLE = 29;
	const Sbecore::uint STUBBRLYOWNER = 30;
	const Sbecore::uint STUBBRLYUSRSTD = 31;
	const Sbecore::uint STUBBRLYGROUP = 32;
	const Sbecore::uint STUBBRLYUSGSTD = 33;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
