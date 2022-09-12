/**
	* \file DbsBrly.h
	* C++ wrapper for database DbsBrly (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef DBSBRLY_H
#define DBSBRLY_H

#define BRLY_VERSION "0.2.15"
#define BRLY_VERSION_MAJOR 0
#define BRLY_VERSION_MINOR 2
#define BRLY_VERSION_SUB 15

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include "BrlyAccRMUserUniversal.h"
#include "BrlyAMFaflightWaypoint.h"
#include "BrlyAMPersonDetail.h"
#include "BrlyAMRegionDstswitch.h"
#include "BrlyAMUserAccess.h"
#include "BrlyAMUsergroupAccess.h"
#include "BrlyAVControlPar.h"
#include "BrlyAVKeylistKey.h"
#include "BrlyAVValuelistVal.h"
#include "BrlyCFile.h"
#include "BrlyCLeg.h"
#include "BrlyHistRMUserUniversal.h"
#include "BrlyJAVKeylistKey.h"
#include "BrlyJMPersonLastname.h"
#include "BrlyJMRegion.h"
#include "BrlyJMRegionTitle.h"
#include "BrlyJMUserState.h"
#include "BrlyLRMConnectionMEquipment.h"
#include "BrlyMConnection.h"
#include "BrlyMEquipment.h"
#include "BrlyMFaflight.h"
#include "BrlyMFile.h"
#include "BrlyMFlight.h"
#include "BrlyMLeg.h"
#include "BrlyMLocation.h"
#include "BrlyMNode.h"
#include "BrlyMOperator.h"
#include "BrlyMPerson.h"
#include "BrlyMPlntype.h"
#include "BrlyMRegion.h"
#include "BrlyMRelay.h"
#include "BrlyMSegment.h"
#include "BrlyMSession.h"
#include "BrlyMTimetable.h"
#include "BrlyMUser.h"
#include "BrlyMUsergroup.h"
#include "BrlyORMConnectionMEquipment.h"
#include "BrlyProxRMLocationMLocation.h"
#include "BrlyRMConnectionMFlight.h"
#include "BrlyRMConnectionMSegment.h"
#include "BrlyRMFlightMFlight.h"
#include "BrlyRMFlightMLocation.h"
#include "BrlyRMLegMLeg.h"
#include "BrlyRMLegMLocation.h"
#include "BrlyRMLocationMSegment.h"
#include "BrlyRMSegmentMSegment.h"
#include "BrlyRMUsergroupUniversal.h"
#include "BrlyRMUserMUsergroup.h"
#include "BrlyVisRMLocationMLocation.h"

#include "BrlyQCon1NRelay.h"
#include "BrlyQConConMNEquipment.h"
#include "BrlyQConList.h"
#include "BrlyQConMapFlight.h"
#include "BrlyQConMapLeg.h"
#include "BrlyQConMapLocation.h"
#include "BrlyQConMapNode.h"
#include "BrlyQConMapRelay.h"
#include "BrlyQConMNFlight.h"
#include "BrlyQConMNSegment.h"
#include "BrlyQConRef1NSegment.h"
#include "BrlyQFilList.h"
#include "BrlyQFlt1NConnection.h"
#include "BrlyQFltEqp1NNode.h"
#include "BrlyQFltEqpMNConnection.h"
#include "BrlyQFltFafAWaypoint.h"
#include "BrlyQFltList.h"
#include "BrlyQFltMNConnection.h"
#include "BrlyQFltMNLocation.h"
#include "BrlyQFltOrgMNFlight.h"
#include "BrlyQFltRef1NSegment.h"
#include "BrlyQLeg1NFlight.h"
#include "BrlyQLegCor1NConnection.h"
#include "BrlyQLegList.h"
#include "BrlyQLegMapLeg.h"
#include "BrlyQLegMapLocation.h"
#include "BrlyQLegMNLocation.h"
#include "BrlyQLegOrgMNLeg.h"
#include "BrlyQLocBgn1NLeg.h"
#include "BrlyQLocEnd1NLeg.h"
#include "BrlyQLocEqp1NNode.h"
#include "BrlyQLocEqpMNConnection.h"
#include "BrlyQLocList.h"
#include "BrlyQLocMapLeg.h"
#include "BrlyQLocMapProxLocation.h"
#include "BrlyQLocMapVisLocation.h"
#include "BrlyQLocMNFlight.h"
#include "BrlyQLocMNLeg.h"
#include "BrlyQLocMNSegment.h"
#include "BrlyQLocProxOrgMNLocation.h"
#include "BrlyQLocVisOrgMNLocation.h"
#include "BrlyQOpr1NEquipment.h"
#include "BrlyQOprList.h"
#include "BrlyQPreselect.h"
#include "BrlyQPrsADetail.h"
#include "BrlyQPrsList.h"
#include "BrlyQPty1NEquipment.h"
#include "BrlyQPtyList.h"
#include "BrlyQReg1NLocation.h"
#include "BrlyQRegADstswitch.h"
#include "BrlyQRegList.h"
#include "BrlyQRegSup1NRegion.h"
#include "BrlyQRly1NNode.h"
#include "BrlyQRlyList.h"
#include "BrlyQSegList.h"
#include "BrlyQSegMNConnection.h"
#include "BrlyQSegMNLocation.h"
#include "BrlyQSegOrgMNSegment.h"
#include "BrlyQSelect.h"
#include "BrlyQTtb1NFlight.h"
#include "BrlyQTtbList.h"
#include "BrlyQTtbRef1NFile.h"
#include "BrlyQUsgAAccess.h"
#include "BrlyQUsgList.h"
#include "BrlyQUsgMNUser.h"
#include "BrlyQUsr1NSession.h"
#include "BrlyQUsrAAccess.h"
#include "BrlyQUsrList.h"
#include "BrlyQUsrMNUsergroup.h"

#define VecBrlyVCard DbsBrly::VecVCard
#define VecBrlyVControl DbsBrly::VecVControl
#define VecBrlyVFeatgroup DbsBrly::VecVFeatgroup
#define VecBrlyVKeylist DbsBrly::VecVKeylist
#define VecBrlyVLat DbsBrly::VecVLat
#define VecBrlyVLocale DbsBrly::VecVLocale
#define VecBrlyVLop DbsBrly::VecVLop
#define VecBrlyVMaintable DbsBrly::VecVMaintable
#define VecBrlyVOolop DbsBrly::VecVOolop
#define VecBrlyVPreset DbsBrly::VecVPreset
#define VecBrlyVRecaccess DbsBrly::VecVRecaccess
#define VecBrlyVUserlevel DbsBrly::VecVUserlevel
#define VecBrlyVValuelist DbsBrly::VecVValuelist
#define VecBrlyWAccess DbsBrly::VecWAccess

/**
	* DbsBrly
	*/
class DbsBrly {

public:
	/**
		* VecVCard (full: VecBrlyVCard)
		*/
	class VecVCard {

	public:
		static const Sbecore::uint CRDBRLYUSG = 1;
		static const Sbecore::uint CRDBRLYUSR = 2;
		static const Sbecore::uint CRDBRLYPRS = 3;
		static const Sbecore::uint CRDBRLYFIL = 4;
		static const Sbecore::uint CRDBRLYOPR = 5;
		static const Sbecore::uint CRDBRLYPTY = 6;
		static const Sbecore::uint CRDBRLYNAV = 7;
		static const Sbecore::uint CRDBRLYREG = 8;
		static const Sbecore::uint CRDBRLYLOC = 9;
		static const Sbecore::uint CRDBRLYLEG = 10;
		static const Sbecore::uint CRDBRLYTTB = 11;
		static const Sbecore::uint CRDBRLYFLT = 12;
		static const Sbecore::uint CRDBRLYSEG = 13;
		static const Sbecore::uint CRDBRLYCON = 14;
		static const Sbecore::uint CRDBRLYRLY = 15;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVControl (full: VecBrlyVControl)
		*/
	class VecVControl {

	public:
		static const Sbecore::uint PNLBRLYUSGLIST_TCOGRP = 1;
		static const Sbecore::uint PNLBRLYUSGLIST_TCOOWN = 2;
		static const Sbecore::uint PNLBRLYUSGLIST_TCOSRF = 3;
		static const Sbecore::uint PNLBRLYUSGAACCESS_TCOFEG = 4;
		static const Sbecore::uint PNLBRLYUSGAACCESS_TCOFEA = 5;
		static const Sbecore::uint PNLBRLYUSGAACCESS_TCOACC = 6;
		static const Sbecore::uint PNLBRLYUSGMNUSER_TCOMREF = 7;
		static const Sbecore::uint PNLBRLYUSGMNUSER_TCOULV = 8;
		static const Sbecore::uint PNLBRLYUSRLIST_TCOGRP = 9;
		static const Sbecore::uint PNLBRLYUSRLIST_TCOOWN = 10;
		static const Sbecore::uint PNLBRLYUSRLIST_TCOPRS = 11;
		static const Sbecore::uint PNLBRLYUSRLIST_TCOSRF = 12;
		static const Sbecore::uint PNLBRLYUSRLIST_TCOUSG = 13;
		static const Sbecore::uint PNLBRLYUSRLIST_TCOSTE = 14;
		static const Sbecore::uint PNLBRLYUSRLIST_TCOLCL = 15;
		static const Sbecore::uint PNLBRLYUSRLIST_TCOULV = 16;
		static const Sbecore::uint PNLBRLYUSRAACCESS_TCOFEG = 17;
		static const Sbecore::uint PNLBRLYUSRAACCESS_TCOFEA = 18;
		static const Sbecore::uint PNLBRLYUSRAACCESS_TCOACC = 19;
		static const Sbecore::uint PNLBRLYUSR1NSESSION_TCOREF = 20;
		static const Sbecore::uint PNLBRLYUSRMNUSERGROUP_TCOMREF = 21;
		static const Sbecore::uint PNLBRLYUSRMNUSERGROUP_TCOULV = 22;
		static const Sbecore::uint PNLBRLYPRSLIST_TCOGRP = 23;
		static const Sbecore::uint PNLBRLYPRSLIST_TCOOWN = 24;
		static const Sbecore::uint PNLBRLYPRSLIST_TCOTIT = 25;
		static const Sbecore::uint PNLBRLYPRSLIST_TCOFNM = 26;
		static const Sbecore::uint PNLBRLYPRSLIST_TCOLNM = 27;
		static const Sbecore::uint PNLBRLYPRSLIST_TCOSEX = 28;
		static const Sbecore::uint PNLBRLYPRSLIST_TCOTEL = 29;
		static const Sbecore::uint PNLBRLYPRSLIST_TCOEML = 30;
		static const Sbecore::uint PNLBRLYPRSADETAIL_TCOTYP = 31;
		static const Sbecore::uint PNLBRLYPRSADETAIL_TCOVAL = 32;
		static const Sbecore::uint PNLBRLYFILLIST_TCOGRP = 33;
		static const Sbecore::uint PNLBRLYFILLIST_TCOOWN = 34;
		static const Sbecore::uint PNLBRLYFILLIST_TCOFNM = 35;
		static const Sbecore::uint PNLBRLYFILLIST_TCORET = 36;
		static const Sbecore::uint PNLBRLYFILLIST_TCOREU = 37;
		static const Sbecore::uint PNLBRLYFILLIST_TCOCNT = 38;
		static const Sbecore::uint PNLBRLYFILLIST_TCOMIM = 39;
		static const Sbecore::uint PNLBRLYFILLIST_TCOSIZ = 40;
		static const Sbecore::uint PNLBRLYOPRLIST_TCOSRF = 41;
		static const Sbecore::uint PNLBRLYOPRLIST_TCOICA = 42;
		static const Sbecore::uint PNLBRLYOPRLIST_TCOTIT = 43;
		static const Sbecore::uint PNLBRLYOPR1NEQUIPMENT_TCOREF = 44;
		static const Sbecore::uint PNLBRLYPTYLIST_TCOSRF = 45;
		static const Sbecore::uint PNLBRLYPTYLIST_TCOTIT = 46;
		static const Sbecore::uint PNLBRLYPTYLIST_TCOETY = 47;
		static const Sbecore::uint PNLBRLYPTYLIST_TCOCAP = 48;
		static const Sbecore::uint PNLBRLYPTY1NEQUIPMENT_TCOREF = 49;
		static const Sbecore::uint PNLBRLYREGLIST_TCOSRF = 50;
		static const Sbecore::uint PNLBRLYREGLIST_TCOTIT = 51;
		static const Sbecore::uint PNLBRLYREGLIST_TCOSUP = 52;
		static const Sbecore::uint PNLBRLYREGLIST_TCODST = 53;
		static const Sbecore::uint PNLBRLYREGLIST_TCOTOF = 54;
		static const Sbecore::uint PNLBRLYREGADSTSWITCH_TCOSTD = 55;
		static const Sbecore::uint PNLBRLYREGADSTSWITCH_TCOSTT = 56;
		static const Sbecore::uint PNLBRLYREG1NLOCATION_TCOREF = 57;
		static const Sbecore::uint PNLBRLYREGSUP1NREGION_TCOREF = 58;
		static const Sbecore::uint PNLBRLYLOCLIST_TCOSRF = 59;
		static const Sbecore::uint PNLBRLYLOCLIST_TCOICA = 60;
		static const Sbecore::uint PNLBRLYLOCLIST_TCOTIT = 61;
		static const Sbecore::uint PNLBRLYLOCLIST_TCOTYP = 62;
		static const Sbecore::uint PNLBRLYLOCLIST_TCOREG = 63;
		static const Sbecore::uint PNLBRLYLOCLIST_TCOEQP = 64;
		static const Sbecore::uint PNLBRLYLOCLIST_TCOALT = 65;
		static const Sbecore::uint PNLBRLYLOCLIST_TCOTHE = 66;
		static const Sbecore::uint PNLBRLYLOCLIST_TCOPHI = 67;
		static const Sbecore::uint PNLBRLYLOCBGN1NLEG_TCOREF = 68;
		static const Sbecore::uint PNLBRLYLOCEND1NLEG_TCOREF = 69;
		static const Sbecore::uint PNLBRLYLOCEQP1NNODE_TCOREF = 70;
		static const Sbecore::uint PNLBRLYLOCMNSEGMENT_TCOMREF = 71;
		static const Sbecore::uint PNLBRLYLOCMNSEGMENT_TCOSTA = 72;
		static const Sbecore::uint PNLBRLYLOCMNSEGMENT_TCOSTO = 73;
		static const Sbecore::uint PNLBRLYLOCMNSEGMENT_TCOSP0 = 74;
		static const Sbecore::uint PNLBRLYLOCMNSEGMENT_TCOSP1 = 75;
		static const Sbecore::uint PNLBRLYLOCMNSEGMENT_TCOSPH = 76;
		static const Sbecore::uint PNLBRLYLOCMNSEGMENT_TCOSTH = 77;
		static const Sbecore::uint PNLBRLYLOCMNFLIGHT_TCOMREF = 78;
		static const Sbecore::uint PNLBRLYLOCMNFLIGHT_TCOSTA = 79;
		static const Sbecore::uint PNLBRLYLOCMNFLIGHT_TCOSTO = 80;
		static const Sbecore::uint PNLBRLYLOCMNFLIGHT_TCOXSA = 81;
		static const Sbecore::uint PNLBRLYLOCMNFLIGHT_TCOXSO = 82;
		static const Sbecore::uint PNLBRLYLOCMNLEG_TCOMREF = 83;
		static const Sbecore::uint PNLBRLYLOCMNLEG_TCOLP0 = 84;
		static const Sbecore::uint PNLBRLYLOCMNLEG_TCOLP1 = 85;
		static const Sbecore::uint PNLBRLYLOCMNLEG_TCOLPH = 86;
		static const Sbecore::uint PNLBRLYLOCMNLEG_TCOLTH = 87;
		static const Sbecore::uint PNLBRLYLOCMNLEG_TCOXP0 = 88;
		static const Sbecore::uint PNLBRLYLOCMNLEG_TCOXP1 = 89;
		static const Sbecore::uint PNLBRLYLOCVISORGMNLOCATION_TCOMREF = 90;
		static const Sbecore::uint PNLBRLYLOCPROXORGMNLOCATION_TCOMREF = 91;
		static const Sbecore::uint PNLBRLYLOCPROXORGMNLOCATION_TCODPH = 92;
		static const Sbecore::uint PNLBRLYLOCEQPMNCONNECTION_TCOMREF = 93;
		static const Sbecore::uint PNLBRLYLEGLIST_TCOGRP = 94;
		static const Sbecore::uint PNLBRLYLEGLIST_TCOOWN = 95;
		static const Sbecore::uint PNLBRLYLEGLIST_TCOBLO = 96;
		static const Sbecore::uint PNLBRLYLEGLIST_TCOELO = 97;
		static const Sbecore::uint PNLBRLYLEGLIST_TCOTYP = 98;
		static const Sbecore::uint PNLBRLYLEGLIST_TCOALT = 99;
		static const Sbecore::uint PNLBRLYLEG1NFLIGHT_TCOREF = 100;
		static const Sbecore::uint PNLBRLYLEGCOR1NCONNECTION_TCOREF = 101;
		static const Sbecore::uint PNLBRLYLEGMNLOCATION_TCOMREF = 102;
		static const Sbecore::uint PNLBRLYLEGMNLOCATION_TCOLP0 = 103;
		static const Sbecore::uint PNLBRLYLEGMNLOCATION_TCOLP1 = 104;
		static const Sbecore::uint PNLBRLYLEGMNLOCATION_TCOLPH = 105;
		static const Sbecore::uint PNLBRLYLEGMNLOCATION_TCOLTH = 106;
		static const Sbecore::uint PNLBRLYLEGMNLOCATION_TCOXP0 = 107;
		static const Sbecore::uint PNLBRLYLEGMNLOCATION_TCOXP1 = 108;
		static const Sbecore::uint PNLBRLYLEGORGMNLEG_TCOMREF = 109;
		static const Sbecore::uint PNLBRLYLEGORGMNLEG_TCODP0 = 110;
		static const Sbecore::uint PNLBRLYLEGORGMNLEG_TCODP1 = 111;
		static const Sbecore::uint PNLBRLYLEGORGMNLEG_TCOOP0 = 112;
		static const Sbecore::uint PNLBRLYLEGORGMNLEG_TCOOP1 = 113;
		static const Sbecore::uint PNLBRLYLEGORGMNLEG_TCOXD0 = 114;
		static const Sbecore::uint PNLBRLYLEGORGMNLEG_TCOXD1 = 115;
		static const Sbecore::uint PNLBRLYLEGORGMNLEG_TCOXO0 = 116;
		static const Sbecore::uint PNLBRLYLEGORGMNLEG_TCOXO1 = 117;
		static const Sbecore::uint PNLBRLYTTBLIST_TCOTIT = 118;
		static const Sbecore::uint PNLBRLYTTBLIST_TCOFIL = 119;
		static const Sbecore::uint PNLBRLYTTBLIST_TCOALI = 120;
		static const Sbecore::uint PNLBRLYTTBLIST_TCOSTA = 121;
		static const Sbecore::uint PNLBRLYTTBLIST_TCOSTO = 122;
		static const Sbecore::uint PNLBRLYTTB1NFLIGHT_TCOREF = 123;
		static const Sbecore::uint PNLBRLYTTBREF1NFILE_TCOREF = 124;
		static const Sbecore::uint PNLBRLYFLTLIST_TCOSRF = 125;
		static const Sbecore::uint PNLBRLYFLTLIST_TCOEQP = 126;
		static const Sbecore::uint PNLBRLYFLTLIST_TCOLEG = 127;
		static const Sbecore::uint PNLBRLYFLTLIST_TCOSTA = 128;
		static const Sbecore::uint PNLBRLYFLTLIST_TCOSTO = 129;
		static const Sbecore::uint PNLBRLYFLTFAFAWAYPOINT_TCOTMS = 130;
		static const Sbecore::uint PNLBRLYFLTFAFAWAYPOINT_TCOLAT = 131;
		static const Sbecore::uint PNLBRLYFLTFAFAWAYPOINT_TCOLON = 132;
		static const Sbecore::uint PNLBRLYFLTFAFAWAYPOINT_TCOGSP = 133;
		static const Sbecore::uint PNLBRLYFLTFAFAWAYPOINT_TCOALT = 134;
		static const Sbecore::uint PNLBRLYFLTFAFAWAYPOINT_TCOAST = 135;
		static const Sbecore::uint PNLBRLYFLTFAFAWAYPOINT_TCOUTY = 136;
		static const Sbecore::uint PNLBRLYFLTFAFAWAYPOINT_TCOACH = 137;
		static const Sbecore::uint PNLBRLYFLT1NCONNECTION_TCOREF = 138;
		static const Sbecore::uint PNLBRLYFLTREF1NSEGMENT_TCOREF = 139;
		static const Sbecore::uint PNLBRLYFLTEQP1NNODE_TCOREF = 140;
		static const Sbecore::uint PNLBRLYFLTMNLOCATION_TCOMREF = 141;
		static const Sbecore::uint PNLBRLYFLTMNLOCATION_TCOSTA = 142;
		static const Sbecore::uint PNLBRLYFLTMNLOCATION_TCOSTO = 143;
		static const Sbecore::uint PNLBRLYFLTMNLOCATION_TCOXSA = 144;
		static const Sbecore::uint PNLBRLYFLTMNLOCATION_TCOXSO = 145;
		static const Sbecore::uint PNLBRLYFLTORGMNFLIGHT_TCOMREF = 146;
		static const Sbecore::uint PNLBRLYFLTORGMNFLIGHT_TCOSTA = 147;
		static const Sbecore::uint PNLBRLYFLTORGMNFLIGHT_TCOSTO = 148;
		static const Sbecore::uint PNLBRLYFLTORGMNFLIGHT_TCOXSA = 149;
		static const Sbecore::uint PNLBRLYFLTORGMNFLIGHT_TCOXSO = 150;
		static const Sbecore::uint PNLBRLYFLTMNCONNECTION_TCOMREF = 151;
		static const Sbecore::uint PNLBRLYFLTMNCONNECTION_TCOSTA = 152;
		static const Sbecore::uint PNLBRLYFLTMNCONNECTION_TCOSTO = 153;
		static const Sbecore::uint PNLBRLYFLTMNCONNECTION_TCOLP0 = 154;
		static const Sbecore::uint PNLBRLYFLTMNCONNECTION_TCOLP1 = 155;
		static const Sbecore::uint PNLBRLYFLTEQPMNCONNECTION_TCOMREF = 156;
		static const Sbecore::uint PNLBRLYSEGLIST_TCORET = 157;
		static const Sbecore::uint PNLBRLYSEGLIST_TCOREU = 158;
		static const Sbecore::uint PNLBRLYSEGLIST_TCOAL0 = 159;
		static const Sbecore::uint PNLBRLYSEGLIST_TCOAL1 = 160;
		static const Sbecore::uint PNLBRLYSEGLIST_TCOTH0 = 161;
		static const Sbecore::uint PNLBRLYSEGLIST_TCOTH1 = 162;
		static const Sbecore::uint PNLBRLYSEGLIST_TCOPH0 = 163;
		static const Sbecore::uint PNLBRLYSEGLIST_TCOPH1 = 164;
		static const Sbecore::uint PNLBRLYSEGLIST_TCOSTA = 165;
		static const Sbecore::uint PNLBRLYSEGLIST_TCOSTO = 166;
		static const Sbecore::uint PNLBRLYSEGORGMNSEGMENT_TCOMREF = 167;
		static const Sbecore::uint PNLBRLYSEGORGMNSEGMENT_TCOSTA = 168;
		static const Sbecore::uint PNLBRLYSEGORGMNSEGMENT_TCOSTO = 169;
		static const Sbecore::uint PNLBRLYSEGORGMNSEGMENT_TCODP0 = 170;
		static const Sbecore::uint PNLBRLYSEGORGMNSEGMENT_TCODP1 = 171;
		static const Sbecore::uint PNLBRLYSEGORGMNSEGMENT_TCOOP0 = 172;
		static const Sbecore::uint PNLBRLYSEGORGMNSEGMENT_TCOOP1 = 173;
		static const Sbecore::uint PNLBRLYSEGMNLOCATION_TCOMREF = 174;
		static const Sbecore::uint PNLBRLYSEGMNLOCATION_TCOSTA = 175;
		static const Sbecore::uint PNLBRLYSEGMNLOCATION_TCOSTO = 176;
		static const Sbecore::uint PNLBRLYSEGMNLOCATION_TCOSP0 = 177;
		static const Sbecore::uint PNLBRLYSEGMNLOCATION_TCOSP1 = 178;
		static const Sbecore::uint PNLBRLYSEGMNLOCATION_TCOSPH = 179;
		static const Sbecore::uint PNLBRLYSEGMNLOCATION_TCOSTH = 180;
		static const Sbecore::uint PNLBRLYSEGMNCONNECTION_TCOMREF = 181;
		static const Sbecore::uint PNLBRLYSEGMNCONNECTION_TCOSTA = 182;
		static const Sbecore::uint PNLBRLYSEGMNCONNECTION_TCOSTO = 183;
		static const Sbecore::uint PNLBRLYSEGMNCONNECTION_TCOLP0 = 184;
		static const Sbecore::uint PNLBRLYSEGMNCONNECTION_TCOLP1 = 185;
		static const Sbecore::uint PNLBRLYCONLIST_TCOGRP = 186;
		static const Sbecore::uint PNLBRLYCONLIST_TCOOWN = 187;
		static const Sbecore::uint PNLBRLYCONLIST_TCOFLT = 188;
		static const Sbecore::uint PNLBRLYCONLIST_TCOCOR = 189;
		static const Sbecore::uint PNLBRLYCONLIST_TCOSTA = 190;
		static const Sbecore::uint PNLBRLYCONLIST_TCOSTO = 191;
		static const Sbecore::uint PNLBRLYCONLIST_TCOMOD = 192;
		static const Sbecore::uint PNLBRLYCON1NRELAY_TCOREF = 193;
		static const Sbecore::uint PNLBRLYCONREF1NSEGMENT_TCOREF = 194;
		static const Sbecore::uint PNLBRLYCONCONMNEQUIPMENT_TCOMREF = 195;
		static const Sbecore::uint PNLBRLYCONMNFLIGHT_TCOMREF = 196;
		static const Sbecore::uint PNLBRLYCONMNFLIGHT_TCOSTA = 197;
		static const Sbecore::uint PNLBRLYCONMNFLIGHT_TCOSTO = 198;
		static const Sbecore::uint PNLBRLYCONMNFLIGHT_TCOLP0 = 199;
		static const Sbecore::uint PNLBRLYCONMNFLIGHT_TCOLP1 = 200;
		static const Sbecore::uint PNLBRLYCONMNSEGMENT_TCOMREF = 201;
		static const Sbecore::uint PNLBRLYCONMNSEGMENT_TCOSTA = 202;
		static const Sbecore::uint PNLBRLYCONMNSEGMENT_TCOSTO = 203;
		static const Sbecore::uint PNLBRLYCONMNSEGMENT_TCOLP0 = 204;
		static const Sbecore::uint PNLBRLYCONMNSEGMENT_TCOLP1 = 205;
		static const Sbecore::uint PNLBRLYRLYLIST_TCOSTA = 206;
		static const Sbecore::uint PNLBRLYRLYLIST_TCOSTO = 207;
		static const Sbecore::uint PNLBRLYRLYLIST_TCOCON = 208;
		static const Sbecore::uint PNLBRLYRLYLIST_TCODIR = 209;
		static const Sbecore::uint PNLBRLYRLYLIST_TCOCTD = 210;
		static const Sbecore::uint PNLBRLYRLY1NNODE_TCOREF = 211;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVFeatgroup (full: VecBrlyVFeatgroup)
		*/
	class VecVFeatgroup {

	public:
		static const Sbecore::uint VECBRLYVCARD = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVKeylist (full: VecBrlyVKeylist)
		*/
	class VecVKeylist {

	public:
		static const Sbecore::uint KLSTBRLYKALLIANCE = 1;
		static const Sbecore::uint KLSTBRLYKAMPERSONDETAILTYPE = 2;
		static const Sbecore::uint KLSTBRLYKEQPTYPE = 3;
		static const Sbecore::uint KLSTBRLYKMFILECONTENT = 4;
		static const Sbecore::uint KLSTBRLYKMFILEMIMETYPE = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);
	};

	/**
		* VecVLat (full: VecBrlyVLat)
		*/
	class VecVLat {

	public:
		static const Sbecore::uint DLO = 1;
		static const Sbecore::uint INI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVLocale (full: VecBrlyVLocale)
		*/
	class VecVLocale {

	public:
		static const Sbecore::uint ENUS = 1;
		static const Sbecore::uint DECH = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVLop (full: VecBrlyVLop)
		*/
	class VecVLop {

	public:
		static const Sbecore::uint INS = 1;
		static const Sbecore::uint RMV = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVMaintable (full: VecBrlyVMaintable)
		*/
	class VecVMaintable {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TBLBRLYMCONNECTION = 2;
		static const Sbecore::uint TBLBRLYMEQUIPMENT = 3;
		static const Sbecore::uint TBLBRLYMFAFLIGHT = 4;
		static const Sbecore::uint TBLBRLYMFILE = 5;
		static const Sbecore::uint TBLBRLYMFLIGHT = 6;
		static const Sbecore::uint TBLBRLYMLEG = 7;
		static const Sbecore::uint TBLBRLYMLOCATION = 8;
		static const Sbecore::uint TBLBRLYMNODE = 9;
		static const Sbecore::uint TBLBRLYMOPERATOR = 10;
		static const Sbecore::uint TBLBRLYMPERSON = 11;
		static const Sbecore::uint TBLBRLYMPLNTYPE = 12;
		static const Sbecore::uint TBLBRLYMREGION = 13;
		static const Sbecore::uint TBLBRLYMRELAY = 14;
		static const Sbecore::uint TBLBRLYMSEGMENT = 15;
		static const Sbecore::uint TBLBRLYMSESSION = 16;
		static const Sbecore::uint TBLBRLYMTIMETABLE = 17;
		static const Sbecore::uint TBLBRLYMUSER = 18;
		static const Sbecore::uint TBLBRLYMUSERGROUP = 19;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVOolop (full: VecBrlyVOolop)
		*/
	class VecVOolop {

	public:
		static const Sbecore::uint INA = 1;
		static const Sbecore::uint INB = 2;
		static const Sbecore::uint RMV = 3;
		static const Sbecore::uint SWP = 4;
		static const Sbecore::uint TOA = 5;
		static const Sbecore::uint TOB = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVPreset (full: VecBrlyVPreset)
		*/
	class VecVPreset {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint PREBRLYADMIN = 2;
		static const Sbecore::uint PREBRLYCON1NRELAY_X1 = 3;
		static const Sbecore::uint PREBRLYCONCONMNEQUIPMENT_OPR_X1 = 4;
		static const Sbecore::uint PREBRLYCONLIST_COR = 5;
		static const Sbecore::uint PREBRLYCONLIST_FLT = 6;
		static const Sbecore::uint PREBRLYCONLIST_GRP = 7;
		static const Sbecore::uint PREBRLYCONLIST_OWN = 8;
		static const Sbecore::uint PREBRLYCONLIST_STA = 9;
		static const Sbecore::uint PREBRLYCONMNFLIGHT_X1 = 10;
		static const Sbecore::uint PREBRLYCONMNFLIGHT_X2 = 11;
		static const Sbecore::uint PREBRLYCONMNSEGMENT_X1 = 12;
		static const Sbecore::uint PREBRLYCONMNSEGMENT_X2 = 13;
		static const Sbecore::uint PREBRLYFILLIST_FNM = 14;
		static const Sbecore::uint PREBRLYFILLIST_GRP = 15;
		static const Sbecore::uint PREBRLYFILLIST_OWN = 16;
		static const Sbecore::uint PREBRLYFILLIST_RET = 17;
		static const Sbecore::uint PREBRLYFILLIST_REU = 18;
		static const Sbecore::uint PREBRLYFLTDSTMNFLIGHT_X1 = 19;
		static const Sbecore::uint PREBRLYFLTLIST_EQP = 20;
		static const Sbecore::uint PREBRLYFLTLIST_LEG = 21;
		static const Sbecore::uint PREBRLYFLTLIST_SRF = 22;
		static const Sbecore::uint PREBRLYFLTLIST_STA = 23;
		static const Sbecore::uint PREBRLYFLTLIST_STO = 24;
		static const Sbecore::uint PREBRLYFLTMNCONNECTION_X1 = 25;
		static const Sbecore::uint PREBRLYFLTMNCONNECTION_X2 = 26;
		static const Sbecore::uint PREBRLYFLTMNLOCATION_X1 = 27;
		static const Sbecore::uint PREBRLYFLTORGMNFLIGHT_X1 = 28;
		static const Sbecore::uint PREBRLYGROUP = 29;
		static const Sbecore::uint PREBRLYIP = 30;
		static const Sbecore::uint PREBRLYIXCRDACCCON = 31;
		static const Sbecore::uint PREBRLYIXCRDACCFIL = 32;
		static const Sbecore::uint PREBRLYIXCRDACCFLT = 33;
		static const Sbecore::uint PREBRLYIXCRDACCLEG = 34;
		static const Sbecore::uint PREBRLYIXCRDACCLOC = 35;
		static const Sbecore::uint PREBRLYIXCRDACCOPR = 36;
		static const Sbecore::uint PREBRLYIXCRDACCPRS = 37;
		static const Sbecore::uint PREBRLYIXCRDACCPTY = 38;
		static const Sbecore::uint PREBRLYIXCRDACCREG = 39;
		static const Sbecore::uint PREBRLYIXCRDACCRLY = 40;
		static const Sbecore::uint PREBRLYIXCRDACCSEG = 41;
		static const Sbecore::uint PREBRLYIXCRDACCTTB = 42;
		static const Sbecore::uint PREBRLYIXCRDACCUSG = 43;
		static const Sbecore::uint PREBRLYIXCRDACCUSR = 44;
		static const Sbecore::uint PREBRLYIXLCL = 45;
		static const Sbecore::uint PREBRLYIXORD = 46;
		static const Sbecore::uint PREBRLYIXPRE = 47;
		static const Sbecore::uint PREBRLYIXRECACC = 48;
		static const Sbecore::uint PREBRLYJREFNOTIFY = 49;
		static const Sbecore::uint PREBRLYJREFSESS = 50;
		static const Sbecore::uint PREBRLYLEGDSTMNLEG_X1 = 51;
		static const Sbecore::uint PREBRLYLEGLIST_BLO = 52;
		static const Sbecore::uint PREBRLYLEGLIST_ELO = 53;
		static const Sbecore::uint PREBRLYLEGLIST_GRP = 54;
		static const Sbecore::uint PREBRLYLEGLIST_OWN = 55;
		static const Sbecore::uint PREBRLYLEGLIST_TYP = 56;
		static const Sbecore::uint PREBRLYLEGMNLOCATION_X1 = 57;
		static const Sbecore::uint PREBRLYLEGORGMNLEG_X1 = 58;
		static const Sbecore::uint PREBRLYLOCLIST_EQP = 59;
		static const Sbecore::uint PREBRLYLOCLIST_ICA = 60;
		static const Sbecore::uint PREBRLYLOCLIST_REG = 61;
		static const Sbecore::uint PREBRLYLOCLIST_SRF = 62;
		static const Sbecore::uint PREBRLYLOCLIST_TIT = 63;
		static const Sbecore::uint PREBRLYLOCLIST_TYP = 64;
		static const Sbecore::uint PREBRLYLOCMNFLIGHT_X1 = 65;
		static const Sbecore::uint PREBRLYLOCMNLEG_X1 = 66;
		static const Sbecore::uint PREBRLYLOCMNSEGMENT_X1 = 67;
		static const Sbecore::uint PREBRLYLOCMNSEGMENT_X2 = 68;
		static const Sbecore::uint PREBRLYNOADM = 69;
		static const Sbecore::uint PREBRLYOPRLIST_ICA = 70;
		static const Sbecore::uint PREBRLYOPRLIST_SRF = 71;
		static const Sbecore::uint PREBRLYOPRLIST_TIT = 72;
		static const Sbecore::uint PREBRLYOWNER = 73;
		static const Sbecore::uint PREBRLYPHI = 74;
		static const Sbecore::uint PREBRLYPRSADETAIL_X1 = 75;
		static const Sbecore::uint PREBRLYPRSLIST_GRP = 76;
		static const Sbecore::uint PREBRLYPRSLIST_LNM = 77;
		static const Sbecore::uint PREBRLYPRSLIST_OWN = 78;
		static const Sbecore::uint PREBRLYPTYLIST_SRF = 79;
		static const Sbecore::uint PREBRLYPTYLIST_TIT = 80;
		static const Sbecore::uint PREBRLYREFAPT = 81;
		static const Sbecore::uint PREBRLYREFCON = 82;
		static const Sbecore::uint PREBRLYREFCOR = 83;
		static const Sbecore::uint PREBRLYREFEQP = 84;
		static const Sbecore::uint PREBRLYREFFAF = 85;
		static const Sbecore::uint PREBRLYREFFIL = 86;
		static const Sbecore::uint PREBRLYREFFLT = 87;
		static const Sbecore::uint PREBRLYREFLEG = 88;
		static const Sbecore::uint PREBRLYREFLOC = 89;
		static const Sbecore::uint PREBRLYREFNDE = 90;
		static const Sbecore::uint PREBRLYREFOPR = 91;
		static const Sbecore::uint PREBRLYREFPLN = 92;
		static const Sbecore::uint PREBRLYREFPRS = 93;
		static const Sbecore::uint PREBRLYREFPTY = 94;
		static const Sbecore::uint PREBRLYREFREG = 95;
		static const Sbecore::uint PREBRLYREFRIP = 96;
		static const Sbecore::uint PREBRLYREFRLY = 97;
		static const Sbecore::uint PREBRLYREFRTE = 98;
		static const Sbecore::uint PREBRLYREFSEG = 99;
		static const Sbecore::uint PREBRLYREFSEL = 100;
		static const Sbecore::uint PREBRLYREFSES = 101;
		static const Sbecore::uint PREBRLYREFTTB = 102;
		static const Sbecore::uint PREBRLYREFUSG = 103;
		static const Sbecore::uint PREBRLYREFUSR = 104;
		static const Sbecore::uint PREBRLYREGLIST_SRF = 105;
		static const Sbecore::uint PREBRLYREGLIST_SUP = 106;
		static const Sbecore::uint PREBRLYREGLIST_TIT = 107;
		static const Sbecore::uint PREBRLYRLYLIST_CON = 108;
		static const Sbecore::uint PREBRLYRLYLIST_DIR = 109;
		static const Sbecore::uint PREBRLYRLYLIST_STA = 110;
		static const Sbecore::uint PREBRLYRLYLIST_STO = 111;
		static const Sbecore::uint PREBRLYSEGDSTMNSEGMENT_X1 = 112;
		static const Sbecore::uint PREBRLYSEGDSTMNSEGMENT_X2 = 113;
		static const Sbecore::uint PREBRLYSEGLIST_RET = 114;
		static const Sbecore::uint PREBRLYSEGLIST_REU = 115;
		static const Sbecore::uint PREBRLYSEGLIST_STA = 116;
		static const Sbecore::uint PREBRLYSEGLIST_STO = 117;
		static const Sbecore::uint PREBRLYSEGMNCONNECTION_X1 = 118;
		static const Sbecore::uint PREBRLYSEGMNCONNECTION_X2 = 119;
		static const Sbecore::uint PREBRLYSEGMNLOCATION_X1 = 120;
		static const Sbecore::uint PREBRLYSEGMNLOCATION_X2 = 121;
		static const Sbecore::uint PREBRLYSEGORGMNSEGMENT_X1 = 122;
		static const Sbecore::uint PREBRLYSEGORGMNSEGMENT_X2 = 123;
		static const Sbecore::uint PREBRLYSESS = 124;
		static const Sbecore::uint PREBRLYSUSPSESS = 125;
		static const Sbecore::uint PREBRLYSYSDATE = 126;
		static const Sbecore::uint PREBRLYSYSSTAMP = 127;
		static const Sbecore::uint PREBRLYSYSTIME = 128;
		static const Sbecore::uint PREBRLYTIME = 129;
		static const Sbecore::uint PREBRLYTLAST = 130;
		static const Sbecore::uint PREBRLYTTBLIST_FIL = 131;
		static const Sbecore::uint PREBRLYTTBLIST_TIT = 132;
		static const Sbecore::uint PREBRLYUSGAACCESS_X1 = 133;
		static const Sbecore::uint PREBRLYUSGAACCESS_X2 = 134;
		static const Sbecore::uint PREBRLYUSGLIST_GRP = 135;
		static const Sbecore::uint PREBRLYUSGLIST_OWN = 136;
		static const Sbecore::uint PREBRLYUSGLIST_SRF = 137;
		static const Sbecore::uint PREBRLYUSRAACCESS_X1 = 138;
		static const Sbecore::uint PREBRLYUSRAACCESS_X2 = 139;
		static const Sbecore::uint PREBRLYUSRLIST_GRP = 140;
		static const Sbecore::uint PREBRLYUSRLIST_OWN = 141;
		static const Sbecore::uint PREBRLYUSRLIST_PRS = 142;
		static const Sbecore::uint PREBRLYUSRLIST_SRF = 143;
		static const Sbecore::uint PREBRLYUSRLIST_STE = 144;
		static const Sbecore::uint PREBRLYUSRLIST_USG = 145;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);
	};

	/**
		* VecVRecaccess (full: VecBrlyVRecaccess)
		*/
	class VecVRecaccess {

	public:
		static const Sbecore::uint FULL = 1;
		static const Sbecore::uint NONE = 2;
		static const Sbecore::uint VIEW = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVUserlevel (full: VecBrlyVUserlevel)
		*/
	class VecVUserlevel {

	public:
		static const Sbecore::uint ADM = 1;
		static const Sbecore::uint GADM = 2;
		static const Sbecore::uint REG = 3;
		static const Sbecore::uint VTOR = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVValuelist (full: VecBrlyVValuelist)
		*/
	class VecVValuelist {

	public:
		static const Sbecore::uint VLSTBRLYUMPERSONTITLE = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);
	};

	/**
		* VecWAccess (full: VecBrlyWAccess)
		*/
	class VecWAccess {

	public:
		static const Sbecore::uint EDIT = 1;
		static const Sbecore::uint EXEC = 2;
		static const Sbecore::uint VIEW = 4;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixBrlyVLocale);

		static void fillFeed(const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	};

public:
	DbsBrly();
	~DbsBrly();

	void init(const Sbecore::uint _ixDbsVDbstype, const std::string& _dbspath, const std::string& _dbsname, const std::string& _ip, const Sbecore::uint _port, const std::string& _username, const std::string& _password);
	void term();

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	void initMy();
	void termMy();
#endif
#if defined(SBECORE_PG)
	void initPg();
	void termPg();
#endif

public:
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string username;
	std::string password;
	std::string ip;
	int port;

	bool initdone;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	MYSQL* dbsMy;
#endif
#if defined(SBECORE_PG)
	PGconn* dbsPg;
#endif

public:
	void begin();																						//!< transaction functionality
	bool commit();
	void rollback();

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	void beginMy();
	bool commitMy();
	void rollbackMy();
#endif
#if defined(SBECORE_PG)
	void beginPg();
	bool commitPg();
	void rollbackPg();
#endif

	bool loadUintBySQL(const std::string& sqlstr, Sbecore::uint& val);		//!< execute a SQL query returning a single uint (arbitrary tables)
	bool loadStringBySQL(const std::string& sqlstr, std::string& val);//!< execute a SQL query returning a single string (arbitrary tables)

	bool loadRefBySQL(const std::string& sqlstr, Sbecore::ubigint& ref);	//!< execute a SQL query returning a single reference (arbitrary tables)
																													//! load a list of references by a SQL query (arbitrary tables)
	Sbecore::ubigint loadRefsBySQL(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	bool loadUintBySQLMy(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLMy(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLMy(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLMy(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

#if defined(SBECORE_PG)
	bool loadUintBySQLPg(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLPg(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLPg(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLPg(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

	void executeQuery(const std::string& sqlstr);								//!< run single SQL command
	void executeQueryDiv(const std::string& sqlstrmy, const std::string& sqlstrpg);
	void executeFile(const std::string& fullpath);								//!< SQL file batch execution

public:
	Sbecore::uint getIxWSubsetByRefBrlyMEquipment(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByBrlyMEquipment(BrlyMEquipment* rec);

	Sbecore::uint getIxWSubsetByRefBrlyMLeg(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByBrlyMLeg(BrlyMLeg* rec);

	Sbecore::uint getIxWSubsetByRefBrlyMLocation(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByBrlyMLocation(BrlyMLocation* rec);

	Sbecore::uint getIxWSubsetByRefBrlyMRegion(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByBrlyMRegion(BrlyMRegion* rec);

	void fillFeedFromKlst(const Sbecore::uint klsIxBrlyVKeylist, const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);
	void fillFeedFromKlstByMtbUref(const Sbecore::uint klsIxBrlyVKeylist, const Sbecore::uint x1IxBrlyVMaintable, const Sbecore::ubigint x1Uref, const Sbecore::uint ixBrlyVLocale, Sbecore::Feed& feed);

	std::string getKlstTitleBySref(const Sbecore::uint klsIxBrlyVKeylist, const std::string& sref, const Sbecore::uint ixBrlyVLocale = 0);
	std::string getKlstTitleByMtbUrefSref(const Sbecore::uint klsIxBrlyVKeylist, const Sbecore::uint x1IxBrlyVMaintable, const Sbecore::ubigint x1Uref, const std::string& sref, const Sbecore::uint ixBrlyVLocale = 0);

	void fillFeedFromVlst(const Sbecore::uint vlsIxBrlyVValuelist, const Sbecore::uint x1IxBrlyVLocale, Sbecore::Feed& feed);

public:
	TblBrlyAccRMUserUniversal* tblbrlyaccrmuseruniversal;
	TblBrlyAMFaflightWaypoint* tblbrlyamfaflightwaypoint;
	TblBrlyAMPersonDetail* tblbrlyampersondetail;
	TblBrlyAMRegionDstswitch* tblbrlyamregiondstswitch;
	TblBrlyAMUserAccess* tblbrlyamuseraccess;
	TblBrlyAMUsergroupAccess* tblbrlyamusergroupaccess;
	TblBrlyAVControlPar* tblbrlyavcontrolpar;
	TblBrlyAVKeylistKey* tblbrlyavkeylistkey;
	TblBrlyAVValuelistVal* tblbrlyavvaluelistval;
	TblBrlyCFile* tblbrlycfile;
	TblBrlyCLeg* tblbrlycleg;
	TblBrlyHistRMUserUniversal* tblbrlyhistrmuseruniversal;
	TblBrlyJAVKeylistKey* tblbrlyjavkeylistkey;
	TblBrlyJMPersonLastname* tblbrlyjmpersonlastname;
	TblBrlyJMRegion* tblbrlyjmregion;
	TblBrlyJMRegionTitle* tblbrlyjmregiontitle;
	TblBrlyJMUserState* tblbrlyjmuserstate;
	TblBrlyLRMConnectionMEquipment* tblbrlylrmconnectionmequipment;
	TblBrlyMConnection* tblbrlymconnection;
	TblBrlyMEquipment* tblbrlymequipment;
	TblBrlyMFaflight* tblbrlymfaflight;
	TblBrlyMFile* tblbrlymfile;
	TblBrlyMFlight* tblbrlymflight;
	TblBrlyMLeg* tblbrlymleg;
	TblBrlyMLocation* tblbrlymlocation;
	TblBrlyMNode* tblbrlymnode;
	TblBrlyMOperator* tblbrlymoperator;
	TblBrlyMPerson* tblbrlymperson;
	TblBrlyMPlntype* tblbrlymplntype;
	TblBrlyMRegion* tblbrlymregion;
	TblBrlyMRelay* tblbrlymrelay;
	TblBrlyMSegment* tblbrlymsegment;
	TblBrlyMSession* tblbrlymsession;
	TblBrlyMTimetable* tblbrlymtimetable;
	TblBrlyMUser* tblbrlymuser;
	TblBrlyMUsergroup* tblbrlymusergroup;
	TblBrlyORMConnectionMEquipment* tblbrlyormconnectionmequipment;
	TblBrlyProxRMLocationMLocation* tblbrlyproxrmlocationmlocation;
	TblBrlyRMConnectionMFlight* tblbrlyrmconnectionmflight;
	TblBrlyRMConnectionMSegment* tblbrlyrmconnectionmsegment;
	TblBrlyRMFlightMFlight* tblbrlyrmflightmflight;
	TblBrlyRMFlightMLocation* tblbrlyrmflightmlocation;
	TblBrlyRMLegMLeg* tblbrlyrmlegmleg;
	TblBrlyRMLegMLocation* tblbrlyrmlegmlocation;
	TblBrlyRMLocationMSegment* tblbrlyrmlocationmsegment;
	TblBrlyRMSegmentMSegment* tblbrlyrmsegmentmsegment;
	TblBrlyRMUsergroupUniversal* tblbrlyrmusergroupuniversal;
	TblBrlyRMUserMUsergroup* tblbrlyrmusermusergroup;
	TblBrlyVisRMLocationMLocation* tblbrlyvisrmlocationmlocation;

	TblBrlyQCon1NRelay* tblbrlyqcon1nrelay;
	TblBrlyQConConMNEquipment* tblbrlyqconconmnequipment;
	TblBrlyQConList* tblbrlyqconlist;
	TblBrlyQConMapFlight* tblbrlyqconmapflight;
	TblBrlyQConMapLeg* tblbrlyqconmapleg;
	TblBrlyQConMapLocation* tblbrlyqconmaplocation;
	TblBrlyQConMapNode* tblbrlyqconmapnode;
	TblBrlyQConMapRelay* tblbrlyqconmaprelay;
	TblBrlyQConMNFlight* tblbrlyqconmnflight;
	TblBrlyQConMNSegment* tblbrlyqconmnsegment;
	TblBrlyQConRef1NSegment* tblbrlyqconref1nsegment;
	TblBrlyQFilList* tblbrlyqfillist;
	TblBrlyQFlt1NConnection* tblbrlyqflt1nconnection;
	TblBrlyQFltEqp1NNode* tblbrlyqflteqp1nnode;
	TblBrlyQFltEqpMNConnection* tblbrlyqflteqpmnconnection;
	TblBrlyQFltFafAWaypoint* tblbrlyqfltfafawaypoint;
	TblBrlyQFltList* tblbrlyqfltlist;
	TblBrlyQFltMNConnection* tblbrlyqfltmnconnection;
	TblBrlyQFltMNLocation* tblbrlyqfltmnlocation;
	TblBrlyQFltOrgMNFlight* tblbrlyqfltorgmnflight;
	TblBrlyQFltRef1NSegment* tblbrlyqfltref1nsegment;
	TblBrlyQLeg1NFlight* tblbrlyqleg1nflight;
	TblBrlyQLegCor1NConnection* tblbrlyqlegcor1nconnection;
	TblBrlyQLegList* tblbrlyqleglist;
	TblBrlyQLegMapLeg* tblbrlyqlegmapleg;
	TblBrlyQLegMapLocation* tblbrlyqlegmaplocation;
	TblBrlyQLegMNLocation* tblbrlyqlegmnlocation;
	TblBrlyQLegOrgMNLeg* tblbrlyqlegorgmnleg;
	TblBrlyQLocBgn1NLeg* tblbrlyqlocbgn1nleg;
	TblBrlyQLocEnd1NLeg* tblbrlyqlocend1nleg;
	TblBrlyQLocEqp1NNode* tblbrlyqloceqp1nnode;
	TblBrlyQLocEqpMNConnection* tblbrlyqloceqpmnconnection;
	TblBrlyQLocList* tblbrlyqloclist;
	TblBrlyQLocMapLeg* tblbrlyqlocmapleg;
	TblBrlyQLocMapProxLocation* tblbrlyqlocmapproxlocation;
	TblBrlyQLocMapVisLocation* tblbrlyqlocmapvislocation;
	TblBrlyQLocMNFlight* tblbrlyqlocmnflight;
	TblBrlyQLocMNLeg* tblbrlyqlocmnleg;
	TblBrlyQLocMNSegment* tblbrlyqlocmnsegment;
	TblBrlyQLocProxOrgMNLocation* tblbrlyqlocproxorgmnlocation;
	TblBrlyQLocVisOrgMNLocation* tblbrlyqlocvisorgmnlocation;
	TblBrlyQOpr1NEquipment* tblbrlyqopr1nequipment;
	TblBrlyQOprList* tblbrlyqoprlist;
	TblBrlyQPreselect* tblbrlyqpreselect;
	TblBrlyQPrsADetail* tblbrlyqprsadetail;
	TblBrlyQPrsList* tblbrlyqprslist;
	TblBrlyQPty1NEquipment* tblbrlyqpty1nequipment;
	TblBrlyQPtyList* tblbrlyqptylist;
	TblBrlyQReg1NLocation* tblbrlyqreg1nlocation;
	TblBrlyQRegADstswitch* tblbrlyqregadstswitch;
	TblBrlyQRegList* tblbrlyqreglist;
	TblBrlyQRegSup1NRegion* tblbrlyqregsup1nregion;
	TblBrlyQRly1NNode* tblbrlyqrly1nnode;
	TblBrlyQRlyList* tblbrlyqrlylist;
	TblBrlyQSegList* tblbrlyqseglist;
	TblBrlyQSegMNConnection* tblbrlyqsegmnconnection;
	TblBrlyQSegMNLocation* tblbrlyqsegmnlocation;
	TblBrlyQSegOrgMNSegment* tblbrlyqsegorgmnsegment;
	TblBrlyQSelect* tblbrlyqselect;
	TblBrlyQTtb1NFlight* tblbrlyqttb1nflight;
	TblBrlyQTtbList* tblbrlyqttblist;
	TblBrlyQTtbRef1NFile* tblbrlyqttbref1nfile;
	TblBrlyQUsgAAccess* tblbrlyqusgaaccess;
	TblBrlyQUsgList* tblbrlyqusglist;
	TblBrlyQUsgMNUser* tblbrlyqusgmnuser;
	TblBrlyQUsr1NSession* tblbrlyqusr1nsession;
	TblBrlyQUsrAAccess* tblbrlyqusraaccess;
	TblBrlyQUsrList* tblbrlyqusrlist;
	TblBrlyQUsrMNUsergroup* tblbrlyqusrmnusergroup;
};
#endif
