/**
	* \file VecBrlyVTag.h
	* vector VecBrlyVTag (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef VECBRLYVTAG_H
#define VECBRLYVTAG_H

#include <sbecore/Xmlio.h>

/**
	* VecBrlyVTag
	*/
namespace VecBrlyVTag {
	const Sbecore::uint ABOUT = 1;
	const Sbecore::uint ALWAYS = 2;
	const Sbecore::uint CANCEL = 3;
	const Sbecore::uint CLOSE = 4;
	const Sbecore::uint CLSESS = 5;
	const Sbecore::uint CLUST = 6;
	const Sbecore::uint CREATE = 7;
	const Sbecore::uint DETAIL = 8;
	const Sbecore::uint DONE = 9;
	const Sbecore::uint DOWNLOAD = 10;
	const Sbecore::uint EMPLONG = 11;
	const Sbecore::uint EMPSHORT = 12;
	const Sbecore::uint ERROR = 13;
	const Sbecore::uint FILENAME = 14;
	const Sbecore::uint FLS = 15;
	const Sbecore::uint GENERAL = 16;
	const Sbecore::uint GOTO = 17;
	const Sbecore::uint GRP = 18;
	const Sbecore::uint HELP = 19;
	const Sbecore::uint IMPERR = 20;
	const Sbecore::uint IMPORT = 21;
	const Sbecore::uint LOAINI = 22;
	const Sbecore::uint NAV = 23;
	const Sbecore::uint NEW = 24;
	const Sbecore::uint NO = 25;
	const Sbecore::uint OK = 26;
	const Sbecore::uint OPSCPLLAST = 27;
	const Sbecore::uint OPSPREP = 28;
	const Sbecore::uint OWN = 29;
	const Sbecore::uint PROGRESS = 30;
	const Sbecore::uint PRSERR = 31;
	const Sbecore::uint QUEST = 32;
	const Sbecore::uint REC = 33;
	const Sbecore::uint REVERSE = 34;
	const Sbecore::uint RUN = 35;
	const Sbecore::uint SESS = 36;
	const Sbecore::uint SHOWLONG = 37;
	const Sbecore::uint SHOWSHORT = 38;
	const Sbecore::uint STOP = 39;
	const Sbecore::uint SUSPSESS = 40;
	const Sbecore::uint TRU = 41;
	const Sbecore::uint UPLOAD = 42;
	const Sbecore::uint YES = 43;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif
