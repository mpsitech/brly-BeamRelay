/**
	* \file VecBrlyVCall.h
	* vector VecBrlyVCall (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef VECBRLYVCALL_H
#define VECBRLYVCALL_H

#include <sbecore/Xmlio.h>

/**
	* VecBrlyVCall
	*/
namespace VecBrlyVCall {
	const Sbecore::uint CALLBRLYBOOLVALPRESET = 1;
	const Sbecore::uint CALLBRLYCLAIMCHG = 2;
	const Sbecore::uint CALLBRLYCON_FLTEQ = 3;
	const Sbecore::uint CALLBRLYCON_TTBEQ = 4;
	const Sbecore::uint CALLBRLYCONMOD = 5;
	const Sbecore::uint CALLBRLYCONMOD_COREQ = 6;
	const Sbecore::uint CALLBRLYCONMOD_FLTEQ = 7;
	const Sbecore::uint CALLBRLYCONREQPMOD_CONEQ = 8;
	const Sbecore::uint CALLBRLYCONREQPMOD_EQPEQ = 9;
	const Sbecore::uint CALLBRLYCONRFLTMOD_CONEQ = 10;
	const Sbecore::uint CALLBRLYCONRFLTMOD_FLTEQ = 11;
	const Sbecore::uint CALLBRLYCONRSEGMOD_CONEQ = 12;
	const Sbecore::uint CALLBRLYCONRSEGMOD_SEGEQ = 13;
	const Sbecore::uint CALLBRLYCONUPD_REFEQ = 14;
	const Sbecore::uint CALLBRLYCRDACTIVE = 15;
	const Sbecore::uint CALLBRLYCRDCLOSE = 16;
	const Sbecore::uint CALLBRLYCRDOPEN = 17;
	const Sbecore::uint CALLBRLYCTLAPARMOD_USREQ = 18;
	const Sbecore::uint CALLBRLYDATCHG = 19;
	const Sbecore::uint CALLBRLYDBLVALPRESET = 20;
	const Sbecore::uint CALLBRLYDLGCLOSE = 21;
	const Sbecore::uint CALLBRLYEQP_HKTEQ = 22;
	const Sbecore::uint CALLBRLYEQP_INSBS = 23;
	const Sbecore::uint CALLBRLYEQP_OPREQ = 24;
	const Sbecore::uint CALLBRLYEQP_PTYEQ = 25;
	const Sbecore::uint CALLBRLYEQPMOD = 26;
	const Sbecore::uint CALLBRLYEQPMOD_HKTHKUEQ = 27;
	const Sbecore::uint CALLBRLYEQPMOD_OPREQ = 28;
	const Sbecore::uint CALLBRLYEQPMOD_PTYEQ = 29;
	const Sbecore::uint CALLBRLYEQPUPD_REFEQ = 30;
	const Sbecore::uint CALLBRLYFAFAWPTMOD_FAFEQ = 31;
	const Sbecore::uint CALLBRLYFAFMOD = 32;
	const Sbecore::uint CALLBRLYFAFUPD_REFEQ = 33;
	const Sbecore::uint CALLBRLYFIL_CLUEQ = 34;
	const Sbecore::uint CALLBRLYFIL_RETEQ = 35;
	const Sbecore::uint CALLBRLYFIL_REUEQ = 36;
	const Sbecore::uint CALLBRLYFILMOD = 37;
	const Sbecore::uint CALLBRLYFILMOD_CLUEQ = 38;
	const Sbecore::uint CALLBRLYFILMOD_RETREUEQ = 39;
	const Sbecore::uint CALLBRLYFILUPD_REFEQ = 40;
	const Sbecore::uint CALLBRLYFLT_EQPEQ = 41;
	const Sbecore::uint CALLBRLYFLT_FAFEQ = 42;
	const Sbecore::uint CALLBRLYFLT_TTBEQ = 43;
	const Sbecore::uint CALLBRLYFLTMOD = 44;
	const Sbecore::uint CALLBRLYFLTMOD_LEGEQ = 45;
	const Sbecore::uint CALLBRLYFLTMOD_TTBEQ = 46;
	const Sbecore::uint CALLBRLYFLTRFLTMOD_DFLEQ = 47;
	const Sbecore::uint CALLBRLYFLTRFLTMOD_OFLEQ = 48;
	const Sbecore::uint CALLBRLYFLTRLOCMOD_FLTEQ = 49;
	const Sbecore::uint CALLBRLYFLTRLOCMOD_LOCEQ = 50;
	const Sbecore::uint CALLBRLYFLTUPD_REFEQ = 51;
	const Sbecore::uint CALLBRLYHUSRRUNVMOD_CRDUSREQ = 52;
	const Sbecore::uint CALLBRLYINTVALPRESET = 53;
	const Sbecore::uint CALLBRLYIXPRESET = 54;
	const Sbecore::uint CALLBRLYKLKJKEYMOD_KLSAKEYEQ = 55;
	const Sbecore::uint CALLBRLYKLSAKEYMOD_KLSEQ = 56;
	const Sbecore::uint CALLBRLYKLSAKEYMOD_KLSMTBURFEQ = 57;
	const Sbecore::uint CALLBRLYLEG_CLUEQ = 58;
	const Sbecore::uint CALLBRLYLEG_INSBS = 59;
	const Sbecore::uint CALLBRLYLEG_TYPEQ = 60;
	const Sbecore::uint CALLBRLYLEGMOD = 61;
	const Sbecore::uint CALLBRLYLEGMOD_BLOEQ = 62;
	const Sbecore::uint CALLBRLYLEGMOD_CLUEQ = 63;
	const Sbecore::uint CALLBRLYLEGMOD_ELOEQ = 64;
	const Sbecore::uint CALLBRLYLEGRLEGMOD_DLGEQ = 65;
	const Sbecore::uint CALLBRLYLEGRLEGMOD_OLGEQ = 66;
	const Sbecore::uint CALLBRLYLEGRLOCMOD_LEGEQ = 67;
	const Sbecore::uint CALLBRLYLEGRLOCMOD_LOCEQ = 68;
	const Sbecore::uint CALLBRLYLEGUPD_REFEQ = 69;
	const Sbecore::uint CALLBRLYLOC_EQPEQ = 70;
	const Sbecore::uint CALLBRLYLOC_INSBS = 71;
	const Sbecore::uint CALLBRLYLOC_TYPEQ = 72;
	const Sbecore::uint CALLBRLYLOCMOD = 73;
	const Sbecore::uint CALLBRLYLOCMOD_REGEQ = 74;
	const Sbecore::uint CALLBRLYLOCRSEGMOD_LOCEQ = 75;
	const Sbecore::uint CALLBRLYLOCRSEGMOD_SEGEQ = 76;
	const Sbecore::uint CALLBRLYLOCUPD_REFEQ = 77;
	const Sbecore::uint CALLBRLYLOG = 78;
	const Sbecore::uint CALLBRLYLOGOUT = 79;
	const Sbecore::uint CALLBRLYMONSTATCHG = 80;
	const Sbecore::uint CALLBRLYNDEMOD = 81;
	const Sbecore::uint CALLBRLYNDEMOD_EQPEQ = 82;
	const Sbecore::uint CALLBRLYNDEMOD_RLYEQ = 83;
	const Sbecore::uint CALLBRLYNDEMOD_SUPEQ = 84;
	const Sbecore::uint CALLBRLYNDEUPD_REFEQ = 85;
	const Sbecore::uint CALLBRLYNODECHG = 86;
	const Sbecore::uint CALLBRLYOPRMOD = 87;
	const Sbecore::uint CALLBRLYOPRUPD_REFEQ = 88;
	const Sbecore::uint CALLBRLYPLOCRLOCMOD_DLOEQ = 89;
	const Sbecore::uint CALLBRLYPLOCRLOCMOD_OLOEQ = 90;
	const Sbecore::uint CALLBRLYPRSADETMOD_PRSEQ = 91;
	const Sbecore::uint CALLBRLYPRSJLNMMOD_PRSEQ = 92;
	const Sbecore::uint CALLBRLYPRSMOD = 93;
	const Sbecore::uint CALLBRLYPRSUPD_REFEQ = 94;
	const Sbecore::uint CALLBRLYPTYMOD = 95;
	const Sbecore::uint CALLBRLYPTYUPD_REFEQ = 96;
	const Sbecore::uint CALLBRLYRECACCESS = 97;
	const Sbecore::uint CALLBRLYREFPRESET = 98;
	const Sbecore::uint CALLBRLYREFSPRESET = 99;
	const Sbecore::uint CALLBRLYREG_INSBS = 100;
	const Sbecore::uint CALLBRLYREG_ISLEAF = 101;
	const Sbecore::uint CALLBRLYREG_SUPEQ = 102;
	const Sbecore::uint CALLBRLYREGADSSMOD_REGEQ = 103;
	const Sbecore::uint CALLBRLYREGJMOD_REGEQ = 104;
	const Sbecore::uint CALLBRLYREGJTITMOD_REGEQ = 105;
	const Sbecore::uint CALLBRLYREGMOD = 106;
	const Sbecore::uint CALLBRLYREGMOD_SUPEQ = 107;
	const Sbecore::uint CALLBRLYREGUPD_REFEQ = 108;
	const Sbecore::uint CALLBRLYRLY_CONEQ = 109;
	const Sbecore::uint CALLBRLYRLYMOD = 110;
	const Sbecore::uint CALLBRLYRLYMOD_CONEQ = 111;
	const Sbecore::uint CALLBRLYRLYUPD_REFEQ = 112;
	const Sbecore::uint CALLBRLYSEG_RETEQ = 113;
	const Sbecore::uint CALLBRLYSEG_REUEQ = 114;
	const Sbecore::uint CALLBRLYSEGMOD = 115;
	const Sbecore::uint CALLBRLYSEGMOD_RETREUEQ = 116;
	const Sbecore::uint CALLBRLYSEGRSEGMOD_DSGEQ = 117;
	const Sbecore::uint CALLBRLYSEGRSEGMOD_OSGEQ = 118;
	const Sbecore::uint CALLBRLYSEGUPD_REFEQ = 119;
	const Sbecore::uint CALLBRLYSESMOD = 120;
	const Sbecore::uint CALLBRLYSESMOD_USREQ = 121;
	const Sbecore::uint CALLBRLYSESUPD_REFEQ = 122;
	const Sbecore::uint CALLBRLYSGECHG = 123;
	const Sbecore::uint CALLBRLYSHRDATCHG = 124;
	const Sbecore::uint CALLBRLYSREFPRESET = 125;
	const Sbecore::uint CALLBRLYSTATCHG = 126;
	const Sbecore::uint CALLBRLYSTGCHG = 127;
	const Sbecore::uint CALLBRLYSTUBCHG = 128;
	const Sbecore::uint CALLBRLYSUSPSESS = 129;
	const Sbecore::uint CALLBRLYTTB_FILEQ = 130;
	const Sbecore::uint CALLBRLYTTBMOD = 131;
	const Sbecore::uint CALLBRLYTTBUPD_REFEQ = 132;
	const Sbecore::uint CALLBRLYTXTVALPRESET = 133;
	const Sbecore::uint CALLBRLYUSGAACCMOD_USGEQ = 134;
	const Sbecore::uint CALLBRLYUSGMOD = 135;
	const Sbecore::uint CALLBRLYUSGUPD_REFEQ = 136;
	const Sbecore::uint CALLBRLYUSR_PRSEQ = 137;
	const Sbecore::uint CALLBRLYUSR_USGEQ = 138;
	const Sbecore::uint CALLBRLYUSRAACCMOD_USREQ = 139;
	const Sbecore::uint CALLBRLYUSRJSTEMOD_USREQ = 140;
	const Sbecore::uint CALLBRLYUSRMOD = 141;
	const Sbecore::uint CALLBRLYUSRRUSGMOD_USGEQ = 142;
	const Sbecore::uint CALLBRLYUSRRUSGMOD_USREQ = 143;
	const Sbecore::uint CALLBRLYUSRUPD_REFEQ = 144;
	const Sbecore::uint CALLBRLYVLOCRLOCMOD_DLOEQ = 145;
	const Sbecore::uint CALLBRLYVLOCRLOCMOD_OLOEQ = 146;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
