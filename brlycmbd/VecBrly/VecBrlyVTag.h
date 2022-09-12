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
	const Sbecore::uint ANNOUNCE = 3;
	const Sbecore::uint CANCEL = 4;
	const Sbecore::uint CLOSE = 5;
	const Sbecore::uint CLSESS = 6;
	const Sbecore::uint CLUST = 7;
	const Sbecore::uint CREATE = 8;
	const Sbecore::uint DETAIL = 9;
	const Sbecore::uint DONE = 10;
	const Sbecore::uint DOWNLOAD = 11;
	const Sbecore::uint EMPLONG = 12;
	const Sbecore::uint EMPSHORT = 13;
	const Sbecore::uint ERROR = 14;
	const Sbecore::uint FILENAME = 15;
	const Sbecore::uint FLS = 16;
	const Sbecore::uint GENERAL = 17;
	const Sbecore::uint GOTO = 18;
	const Sbecore::uint GRP = 19;
	const Sbecore::uint HELP = 20;
	const Sbecore::uint HOUR = 21;
	const Sbecore::uint HOURS = 22;
	const Sbecore::uint IMPERR = 23;
	const Sbecore::uint IMPORT = 24;
	const Sbecore::uint LOAINI = 25;
	const Sbecore::uint MINUTE = 26;
	const Sbecore::uint MINUTES = 27;
	const Sbecore::uint NAV = 28;
	const Sbecore::uint NEW = 29;
	const Sbecore::uint NO = 30;
	const Sbecore::uint OK = 31;
	const Sbecore::uint OPSCPLLAST = 32;
	const Sbecore::uint OPSPREP = 33;
	const Sbecore::uint OWN = 34;
	const Sbecore::uint PROGRESS = 35;
	const Sbecore::uint PRSERR = 36;
	const Sbecore::uint QUEST = 37;
	const Sbecore::uint REC = 38;
	const Sbecore::uint REVERSE = 39;
	const Sbecore::uint RUN = 40;
	const Sbecore::uint SECOND = 41;
	const Sbecore::uint SECONDS = 42;
	const Sbecore::uint SESS = 43;
	const Sbecore::uint SHOWLONG = 44;
	const Sbecore::uint SHOWSHORT = 45;
	const Sbecore::uint STOP = 46;
	const Sbecore::uint SUSPSESS = 47;
	const Sbecore::uint TRU = 48;
	const Sbecore::uint UPLOAD = 49;
	const Sbecore::uint YES = 50;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
};

#endif
