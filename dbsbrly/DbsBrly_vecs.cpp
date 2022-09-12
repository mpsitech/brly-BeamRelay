/**
	* \file DbsBrly_vecs.cpp
	* C++ wrapper for database DbsBrly (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DbsBrly::VecVCard
 ******************************************************************************/

uint DbsBrly::VecVCard::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdbrlyusg") return CRDBRLYUSG;
	if (s == "crdbrlyusr") return CRDBRLYUSR;
	if (s == "crdbrlyprs") return CRDBRLYPRS;
	if (s == "crdbrlyfil") return CRDBRLYFIL;
	if (s == "crdbrlyopr") return CRDBRLYOPR;
	if (s == "crdbrlypty") return CRDBRLYPTY;
	if (s == "crdbrlynav") return CRDBRLYNAV;
	if (s == "crdbrlyreg") return CRDBRLYREG;
	if (s == "crdbrlyloc") return CRDBRLYLOC;
	if (s == "crdbrlyleg") return CRDBRLYLEG;
	if (s == "crdbrlyttb") return CRDBRLYTTB;
	if (s == "crdbrlyflt") return CRDBRLYFLT;
	if (s == "crdbrlyseg") return CRDBRLYSEG;
	if (s == "crdbrlycon") return CRDBRLYCON;
	if (s == "crdbrlyrly") return CRDBRLYRLY;

	return(0);
};

string DbsBrly::VecVCard::getSref(
			const uint ix
		) {
	if (ix == CRDBRLYUSG) return("CrdBrlyUsg");
	if (ix == CRDBRLYUSR) return("CrdBrlyUsr");
	if (ix == CRDBRLYPRS) return("CrdBrlyPrs");
	if (ix == CRDBRLYFIL) return("CrdBrlyFil");
	if (ix == CRDBRLYOPR) return("CrdBrlyOpr");
	if (ix == CRDBRLYPTY) return("CrdBrlyPty");
	if (ix == CRDBRLYNAV) return("CrdBrlyNav");
	if (ix == CRDBRLYREG) return("CrdBrlyReg");
	if (ix == CRDBRLYLOC) return("CrdBrlyLoc");
	if (ix == CRDBRLYLEG) return("CrdBrlyLeg");
	if (ix == CRDBRLYTTB) return("CrdBrlyTtb");
	if (ix == CRDBRLYFLT) return("CrdBrlyFlt");
	if (ix == CRDBRLYSEG) return("CrdBrlySeg");
	if (ix == CRDBRLYCON) return("CrdBrlyCon");
	if (ix == CRDBRLYRLY) return("CrdBrlyRly");

	return("");
};

string DbsBrly::VecVCard::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == CRDBRLYUSG) return("user groups");
		if (ix == CRDBRLYUSR) return("users");
		if (ix == CRDBRLYPRS) return("persons");
		if (ix == CRDBRLYFIL) return("files");
		if (ix == CRDBRLYOPR) return("operators");
		if (ix == CRDBRLYPTY) return("plane types");
		if (ix == CRDBRLYREG) return("regions");
		if (ix == CRDBRLYLOC) return("locations");
		if (ix == CRDBRLYLEG) return("legs");
		if (ix == CRDBRLYTTB) return("timetables");
		if (ix == CRDBRLYFLT) return("flights");
		if (ix == CRDBRLYSEG) return("segments");
		if (ix == CRDBRLYCON) return("connections");
		if (ix == CRDBRLYRLY) return("relays");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == CRDBRLYUSG) return("Benutzergruppen");
		if (ix == CRDBRLYUSR) return("Benutzer");
		if (ix == CRDBRLYPRS) return("Personen");
		if (ix == CRDBRLYFIL) return("Dateien");
		if (ix == CRDBRLYOPR) return("Betreiber");
		if (ix == CRDBRLYPTY) return("Flugzeugtypen");
		if (ix == CRDBRLYREG) return("Regionen");
		if (ix == CRDBRLYLOC) return("Orte");
		if (ix == CRDBRLYLEG) return("Strecken");
		if (ix == CRDBRLYTTB) return("Flugpl\\u00e4ne");
		if (ix == CRDBRLYFLT) return("Fl\\u00fcge");
		if (ix == CRDBRLYSEG) return("Segmente");
		if (ix == CRDBRLYCON) return("Verbindungen");
		if (ix == CRDBRLYRLY) return("Verbindungsketten");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsBrly::VecVCard::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 15; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVControl
 ******************************************************************************/

uint DbsBrly::VecVControl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "pnlbrlyusglist.tcogrp") return PNLBRLYUSGLIST_TCOGRP;
	if (s == "pnlbrlyusglist.tcoown") return PNLBRLYUSGLIST_TCOOWN;
	if (s == "pnlbrlyusglist.tcosrf") return PNLBRLYUSGLIST_TCOSRF;
	if (s == "pnlbrlyusgaaccess.tcofeg") return PNLBRLYUSGAACCESS_TCOFEG;
	if (s == "pnlbrlyusgaaccess.tcofea") return PNLBRLYUSGAACCESS_TCOFEA;
	if (s == "pnlbrlyusgaaccess.tcoacc") return PNLBRLYUSGAACCESS_TCOACC;
	if (s == "pnlbrlyusgmnuser.tcomref") return PNLBRLYUSGMNUSER_TCOMREF;
	if (s == "pnlbrlyusgmnuser.tcoulv") return PNLBRLYUSGMNUSER_TCOULV;
	if (s == "pnlbrlyusrlist.tcogrp") return PNLBRLYUSRLIST_TCOGRP;
	if (s == "pnlbrlyusrlist.tcoown") return PNLBRLYUSRLIST_TCOOWN;
	if (s == "pnlbrlyusrlist.tcoprs") return PNLBRLYUSRLIST_TCOPRS;
	if (s == "pnlbrlyusrlist.tcosrf") return PNLBRLYUSRLIST_TCOSRF;
	if (s == "pnlbrlyusrlist.tcousg") return PNLBRLYUSRLIST_TCOUSG;
	if (s == "pnlbrlyusrlist.tcoste") return PNLBRLYUSRLIST_TCOSTE;
	if (s == "pnlbrlyusrlist.tcolcl") return PNLBRLYUSRLIST_TCOLCL;
	if (s == "pnlbrlyusrlist.tcoulv") return PNLBRLYUSRLIST_TCOULV;
	if (s == "pnlbrlyusraaccess.tcofeg") return PNLBRLYUSRAACCESS_TCOFEG;
	if (s == "pnlbrlyusraaccess.tcofea") return PNLBRLYUSRAACCESS_TCOFEA;
	if (s == "pnlbrlyusraaccess.tcoacc") return PNLBRLYUSRAACCESS_TCOACC;
	if (s == "pnlbrlyusr1nsession.tcoref") return PNLBRLYUSR1NSESSION_TCOREF;
	if (s == "pnlbrlyusrmnusergroup.tcomref") return PNLBRLYUSRMNUSERGROUP_TCOMREF;
	if (s == "pnlbrlyusrmnusergroup.tcoulv") return PNLBRLYUSRMNUSERGROUP_TCOULV;
	if (s == "pnlbrlyprslist.tcogrp") return PNLBRLYPRSLIST_TCOGRP;
	if (s == "pnlbrlyprslist.tcoown") return PNLBRLYPRSLIST_TCOOWN;
	if (s == "pnlbrlyprslist.tcotit") return PNLBRLYPRSLIST_TCOTIT;
	if (s == "pnlbrlyprslist.tcofnm") return PNLBRLYPRSLIST_TCOFNM;
	if (s == "pnlbrlyprslist.tcolnm") return PNLBRLYPRSLIST_TCOLNM;
	if (s == "pnlbrlyprslist.tcosex") return PNLBRLYPRSLIST_TCOSEX;
	if (s == "pnlbrlyprslist.tcotel") return PNLBRLYPRSLIST_TCOTEL;
	if (s == "pnlbrlyprslist.tcoeml") return PNLBRLYPRSLIST_TCOEML;
	if (s == "pnlbrlyprsadetail.tcotyp") return PNLBRLYPRSADETAIL_TCOTYP;
	if (s == "pnlbrlyprsadetail.tcoval") return PNLBRLYPRSADETAIL_TCOVAL;
	if (s == "pnlbrlyfillist.tcogrp") return PNLBRLYFILLIST_TCOGRP;
	if (s == "pnlbrlyfillist.tcoown") return PNLBRLYFILLIST_TCOOWN;
	if (s == "pnlbrlyfillist.tcofnm") return PNLBRLYFILLIST_TCOFNM;
	if (s == "pnlbrlyfillist.tcoret") return PNLBRLYFILLIST_TCORET;
	if (s == "pnlbrlyfillist.tcoreu") return PNLBRLYFILLIST_TCOREU;
	if (s == "pnlbrlyfillist.tcocnt") return PNLBRLYFILLIST_TCOCNT;
	if (s == "pnlbrlyfillist.tcomim") return PNLBRLYFILLIST_TCOMIM;
	if (s == "pnlbrlyfillist.tcosiz") return PNLBRLYFILLIST_TCOSIZ;
	if (s == "pnlbrlyoprlist.tcosrf") return PNLBRLYOPRLIST_TCOSRF;
	if (s == "pnlbrlyoprlist.tcoica") return PNLBRLYOPRLIST_TCOICA;
	if (s == "pnlbrlyoprlist.tcotit") return PNLBRLYOPRLIST_TCOTIT;
	if (s == "pnlbrlyopr1nequipment.tcoref") return PNLBRLYOPR1NEQUIPMENT_TCOREF;
	if (s == "pnlbrlyptylist.tcosrf") return PNLBRLYPTYLIST_TCOSRF;
	if (s == "pnlbrlyptylist.tcotit") return PNLBRLYPTYLIST_TCOTIT;
	if (s == "pnlbrlyptylist.tcoety") return PNLBRLYPTYLIST_TCOETY;
	if (s == "pnlbrlyptylist.tcocap") return PNLBRLYPTYLIST_TCOCAP;
	if (s == "pnlbrlypty1nequipment.tcoref") return PNLBRLYPTY1NEQUIPMENT_TCOREF;
	if (s == "pnlbrlyreglist.tcosrf") return PNLBRLYREGLIST_TCOSRF;
	if (s == "pnlbrlyreglist.tcotit") return PNLBRLYREGLIST_TCOTIT;
	if (s == "pnlbrlyreglist.tcosup") return PNLBRLYREGLIST_TCOSUP;
	if (s == "pnlbrlyreglist.tcodst") return PNLBRLYREGLIST_TCODST;
	if (s == "pnlbrlyreglist.tcotof") return PNLBRLYREGLIST_TCOTOF;
	if (s == "pnlbrlyregadstswitch.tcostd") return PNLBRLYREGADSTSWITCH_TCOSTD;
	if (s == "pnlbrlyregadstswitch.tcostt") return PNLBRLYREGADSTSWITCH_TCOSTT;
	if (s == "pnlbrlyreg1nlocation.tcoref") return PNLBRLYREG1NLOCATION_TCOREF;
	if (s == "pnlbrlyregsup1nregion.tcoref") return PNLBRLYREGSUP1NREGION_TCOREF;
	if (s == "pnlbrlyloclist.tcosrf") return PNLBRLYLOCLIST_TCOSRF;
	if (s == "pnlbrlyloclist.tcoica") return PNLBRLYLOCLIST_TCOICA;
	if (s == "pnlbrlyloclist.tcotit") return PNLBRLYLOCLIST_TCOTIT;
	if (s == "pnlbrlyloclist.tcotyp") return PNLBRLYLOCLIST_TCOTYP;
	if (s == "pnlbrlyloclist.tcoreg") return PNLBRLYLOCLIST_TCOREG;
	if (s == "pnlbrlyloclist.tcoeqp") return PNLBRLYLOCLIST_TCOEQP;
	if (s == "pnlbrlyloclist.tcoalt") return PNLBRLYLOCLIST_TCOALT;
	if (s == "pnlbrlyloclist.tcothe") return PNLBRLYLOCLIST_TCOTHE;
	if (s == "pnlbrlyloclist.tcophi") return PNLBRLYLOCLIST_TCOPHI;
	if (s == "pnlbrlylocbgn1nleg.tcoref") return PNLBRLYLOCBGN1NLEG_TCOREF;
	if (s == "pnlbrlylocend1nleg.tcoref") return PNLBRLYLOCEND1NLEG_TCOREF;
	if (s == "pnlbrlyloceqp1nnode.tcoref") return PNLBRLYLOCEQP1NNODE_TCOREF;
	if (s == "pnlbrlylocmnsegment.tcomref") return PNLBRLYLOCMNSEGMENT_TCOMREF;
	if (s == "pnlbrlylocmnsegment.tcosta") return PNLBRLYLOCMNSEGMENT_TCOSTA;
	if (s == "pnlbrlylocmnsegment.tcosto") return PNLBRLYLOCMNSEGMENT_TCOSTO;
	if (s == "pnlbrlylocmnsegment.tcosp0") return PNLBRLYLOCMNSEGMENT_TCOSP0;
	if (s == "pnlbrlylocmnsegment.tcosp1") return PNLBRLYLOCMNSEGMENT_TCOSP1;
	if (s == "pnlbrlylocmnsegment.tcosph") return PNLBRLYLOCMNSEGMENT_TCOSPH;
	if (s == "pnlbrlylocmnsegment.tcosth") return PNLBRLYLOCMNSEGMENT_TCOSTH;
	if (s == "pnlbrlylocmnflight.tcomref") return PNLBRLYLOCMNFLIGHT_TCOMREF;
	if (s == "pnlbrlylocmnflight.tcosta") return PNLBRLYLOCMNFLIGHT_TCOSTA;
	if (s == "pnlbrlylocmnflight.tcosto") return PNLBRLYLOCMNFLIGHT_TCOSTO;
	if (s == "pnlbrlylocmnflight.tcoxsa") return PNLBRLYLOCMNFLIGHT_TCOXSA;
	if (s == "pnlbrlylocmnflight.tcoxso") return PNLBRLYLOCMNFLIGHT_TCOXSO;
	if (s == "pnlbrlylocmnleg.tcomref") return PNLBRLYLOCMNLEG_TCOMREF;
	if (s == "pnlbrlylocmnleg.tcolp0") return PNLBRLYLOCMNLEG_TCOLP0;
	if (s == "pnlbrlylocmnleg.tcolp1") return PNLBRLYLOCMNLEG_TCOLP1;
	if (s == "pnlbrlylocmnleg.tcolph") return PNLBRLYLOCMNLEG_TCOLPH;
	if (s == "pnlbrlylocmnleg.tcolth") return PNLBRLYLOCMNLEG_TCOLTH;
	if (s == "pnlbrlylocmnleg.tcoxp0") return PNLBRLYLOCMNLEG_TCOXP0;
	if (s == "pnlbrlylocmnleg.tcoxp1") return PNLBRLYLOCMNLEG_TCOXP1;
	if (s == "pnlbrlylocvisorgmnlocation.tcomref") return PNLBRLYLOCVISORGMNLOCATION_TCOMREF;
	if (s == "pnlbrlylocproxorgmnlocation.tcomref") return PNLBRLYLOCPROXORGMNLOCATION_TCOMREF;
	if (s == "pnlbrlylocproxorgmnlocation.tcodph") return PNLBRLYLOCPROXORGMNLOCATION_TCODPH;
	if (s == "pnlbrlyloceqpmnconnection.tcomref") return PNLBRLYLOCEQPMNCONNECTION_TCOMREF;
	if (s == "pnlbrlyleglist.tcogrp") return PNLBRLYLEGLIST_TCOGRP;
	if (s == "pnlbrlyleglist.tcoown") return PNLBRLYLEGLIST_TCOOWN;
	if (s == "pnlbrlyleglist.tcoblo") return PNLBRLYLEGLIST_TCOBLO;
	if (s == "pnlbrlyleglist.tcoelo") return PNLBRLYLEGLIST_TCOELO;
	if (s == "pnlbrlyleglist.tcotyp") return PNLBRLYLEGLIST_TCOTYP;
	if (s == "pnlbrlyleglist.tcoalt") return PNLBRLYLEGLIST_TCOALT;
	if (s == "pnlbrlyleg1nflight.tcoref") return PNLBRLYLEG1NFLIGHT_TCOREF;
	if (s == "pnlbrlylegcor1nconnection.tcoref") return PNLBRLYLEGCOR1NCONNECTION_TCOREF;
	if (s == "pnlbrlylegmnlocation.tcomref") return PNLBRLYLEGMNLOCATION_TCOMREF;
	if (s == "pnlbrlylegmnlocation.tcolp0") return PNLBRLYLEGMNLOCATION_TCOLP0;
	if (s == "pnlbrlylegmnlocation.tcolp1") return PNLBRLYLEGMNLOCATION_TCOLP1;
	if (s == "pnlbrlylegmnlocation.tcolph") return PNLBRLYLEGMNLOCATION_TCOLPH;
	if (s == "pnlbrlylegmnlocation.tcolth") return PNLBRLYLEGMNLOCATION_TCOLTH;
	if (s == "pnlbrlylegmnlocation.tcoxp0") return PNLBRLYLEGMNLOCATION_TCOXP0;
	if (s == "pnlbrlylegmnlocation.tcoxp1") return PNLBRLYLEGMNLOCATION_TCOXP1;
	if (s == "pnlbrlylegorgmnleg.tcomref") return PNLBRLYLEGORGMNLEG_TCOMREF;
	if (s == "pnlbrlylegorgmnleg.tcodp0") return PNLBRLYLEGORGMNLEG_TCODP0;
	if (s == "pnlbrlylegorgmnleg.tcodp1") return PNLBRLYLEGORGMNLEG_TCODP1;
	if (s == "pnlbrlylegorgmnleg.tcoop0") return PNLBRLYLEGORGMNLEG_TCOOP0;
	if (s == "pnlbrlylegorgmnleg.tcoop1") return PNLBRLYLEGORGMNLEG_TCOOP1;
	if (s == "pnlbrlylegorgmnleg.tcoxd0") return PNLBRLYLEGORGMNLEG_TCOXD0;
	if (s == "pnlbrlylegorgmnleg.tcoxd1") return PNLBRLYLEGORGMNLEG_TCOXD1;
	if (s == "pnlbrlylegorgmnleg.tcoxo0") return PNLBRLYLEGORGMNLEG_TCOXO0;
	if (s == "pnlbrlylegorgmnleg.tcoxo1") return PNLBRLYLEGORGMNLEG_TCOXO1;
	if (s == "pnlbrlyttblist.tcotit") return PNLBRLYTTBLIST_TCOTIT;
	if (s == "pnlbrlyttblist.tcofil") return PNLBRLYTTBLIST_TCOFIL;
	if (s == "pnlbrlyttblist.tcoali") return PNLBRLYTTBLIST_TCOALI;
	if (s == "pnlbrlyttblist.tcosta") return PNLBRLYTTBLIST_TCOSTA;
	if (s == "pnlbrlyttblist.tcosto") return PNLBRLYTTBLIST_TCOSTO;
	if (s == "pnlbrlyttb1nflight.tcoref") return PNLBRLYTTB1NFLIGHT_TCOREF;
	if (s == "pnlbrlyttbref1nfile.tcoref") return PNLBRLYTTBREF1NFILE_TCOREF;
	if (s == "pnlbrlyfltlist.tcosrf") return PNLBRLYFLTLIST_TCOSRF;
	if (s == "pnlbrlyfltlist.tcoeqp") return PNLBRLYFLTLIST_TCOEQP;
	if (s == "pnlbrlyfltlist.tcoleg") return PNLBRLYFLTLIST_TCOLEG;
	if (s == "pnlbrlyfltlist.tcosta") return PNLBRLYFLTLIST_TCOSTA;
	if (s == "pnlbrlyfltlist.tcosto") return PNLBRLYFLTLIST_TCOSTO;
	if (s == "pnlbrlyfltfafawaypoint.tcotms") return PNLBRLYFLTFAFAWAYPOINT_TCOTMS;
	if (s == "pnlbrlyfltfafawaypoint.tcolat") return PNLBRLYFLTFAFAWAYPOINT_TCOLAT;
	if (s == "pnlbrlyfltfafawaypoint.tcolon") return PNLBRLYFLTFAFAWAYPOINT_TCOLON;
	if (s == "pnlbrlyfltfafawaypoint.tcogsp") return PNLBRLYFLTFAFAWAYPOINT_TCOGSP;
	if (s == "pnlbrlyfltfafawaypoint.tcoalt") return PNLBRLYFLTFAFAWAYPOINT_TCOALT;
	if (s == "pnlbrlyfltfafawaypoint.tcoast") return PNLBRLYFLTFAFAWAYPOINT_TCOAST;
	if (s == "pnlbrlyfltfafawaypoint.tcouty") return PNLBRLYFLTFAFAWAYPOINT_TCOUTY;
	if (s == "pnlbrlyfltfafawaypoint.tcoach") return PNLBRLYFLTFAFAWAYPOINT_TCOACH;
	if (s == "pnlbrlyflt1nconnection.tcoref") return PNLBRLYFLT1NCONNECTION_TCOREF;
	if (s == "pnlbrlyfltref1nsegment.tcoref") return PNLBRLYFLTREF1NSEGMENT_TCOREF;
	if (s == "pnlbrlyflteqp1nnode.tcoref") return PNLBRLYFLTEQP1NNODE_TCOREF;
	if (s == "pnlbrlyfltmnlocation.tcomref") return PNLBRLYFLTMNLOCATION_TCOMREF;
	if (s == "pnlbrlyfltmnlocation.tcosta") return PNLBRLYFLTMNLOCATION_TCOSTA;
	if (s == "pnlbrlyfltmnlocation.tcosto") return PNLBRLYFLTMNLOCATION_TCOSTO;
	if (s == "pnlbrlyfltmnlocation.tcoxsa") return PNLBRLYFLTMNLOCATION_TCOXSA;
	if (s == "pnlbrlyfltmnlocation.tcoxso") return PNLBRLYFLTMNLOCATION_TCOXSO;
	if (s == "pnlbrlyfltorgmnflight.tcomref") return PNLBRLYFLTORGMNFLIGHT_TCOMREF;
	if (s == "pnlbrlyfltorgmnflight.tcosta") return PNLBRLYFLTORGMNFLIGHT_TCOSTA;
	if (s == "pnlbrlyfltorgmnflight.tcosto") return PNLBRLYFLTORGMNFLIGHT_TCOSTO;
	if (s == "pnlbrlyfltorgmnflight.tcoxsa") return PNLBRLYFLTORGMNFLIGHT_TCOXSA;
	if (s == "pnlbrlyfltorgmnflight.tcoxso") return PNLBRLYFLTORGMNFLIGHT_TCOXSO;
	if (s == "pnlbrlyfltmnconnection.tcomref") return PNLBRLYFLTMNCONNECTION_TCOMREF;
	if (s == "pnlbrlyfltmnconnection.tcosta") return PNLBRLYFLTMNCONNECTION_TCOSTA;
	if (s == "pnlbrlyfltmnconnection.tcosto") return PNLBRLYFLTMNCONNECTION_TCOSTO;
	if (s == "pnlbrlyfltmnconnection.tcolp0") return PNLBRLYFLTMNCONNECTION_TCOLP0;
	if (s == "pnlbrlyfltmnconnection.tcolp1") return PNLBRLYFLTMNCONNECTION_TCOLP1;
	if (s == "pnlbrlyflteqpmnconnection.tcomref") return PNLBRLYFLTEQPMNCONNECTION_TCOMREF;
	if (s == "pnlbrlyseglist.tcoret") return PNLBRLYSEGLIST_TCORET;
	if (s == "pnlbrlyseglist.tcoreu") return PNLBRLYSEGLIST_TCOREU;
	if (s == "pnlbrlyseglist.tcoal0") return PNLBRLYSEGLIST_TCOAL0;
	if (s == "pnlbrlyseglist.tcoal1") return PNLBRLYSEGLIST_TCOAL1;
	if (s == "pnlbrlyseglist.tcoth0") return PNLBRLYSEGLIST_TCOTH0;
	if (s == "pnlbrlyseglist.tcoth1") return PNLBRLYSEGLIST_TCOTH1;
	if (s == "pnlbrlyseglist.tcoph0") return PNLBRLYSEGLIST_TCOPH0;
	if (s == "pnlbrlyseglist.tcoph1") return PNLBRLYSEGLIST_TCOPH1;
	if (s == "pnlbrlyseglist.tcosta") return PNLBRLYSEGLIST_TCOSTA;
	if (s == "pnlbrlyseglist.tcosto") return PNLBRLYSEGLIST_TCOSTO;
	if (s == "pnlbrlysegorgmnsegment.tcomref") return PNLBRLYSEGORGMNSEGMENT_TCOMREF;
	if (s == "pnlbrlysegorgmnsegment.tcosta") return PNLBRLYSEGORGMNSEGMENT_TCOSTA;
	if (s == "pnlbrlysegorgmnsegment.tcosto") return PNLBRLYSEGORGMNSEGMENT_TCOSTO;
	if (s == "pnlbrlysegorgmnsegment.tcodp0") return PNLBRLYSEGORGMNSEGMENT_TCODP0;
	if (s == "pnlbrlysegorgmnsegment.tcodp1") return PNLBRLYSEGORGMNSEGMENT_TCODP1;
	if (s == "pnlbrlysegorgmnsegment.tcoop0") return PNLBRLYSEGORGMNSEGMENT_TCOOP0;
	if (s == "pnlbrlysegorgmnsegment.tcoop1") return PNLBRLYSEGORGMNSEGMENT_TCOOP1;
	if (s == "pnlbrlysegmnlocation.tcomref") return PNLBRLYSEGMNLOCATION_TCOMREF;
	if (s == "pnlbrlysegmnlocation.tcosta") return PNLBRLYSEGMNLOCATION_TCOSTA;
	if (s == "pnlbrlysegmnlocation.tcosto") return PNLBRLYSEGMNLOCATION_TCOSTO;
	if (s == "pnlbrlysegmnlocation.tcosp0") return PNLBRLYSEGMNLOCATION_TCOSP0;
	if (s == "pnlbrlysegmnlocation.tcosp1") return PNLBRLYSEGMNLOCATION_TCOSP1;
	if (s == "pnlbrlysegmnlocation.tcosph") return PNLBRLYSEGMNLOCATION_TCOSPH;
	if (s == "pnlbrlysegmnlocation.tcosth") return PNLBRLYSEGMNLOCATION_TCOSTH;
	if (s == "pnlbrlysegmnconnection.tcomref") return PNLBRLYSEGMNCONNECTION_TCOMREF;
	if (s == "pnlbrlysegmnconnection.tcosta") return PNLBRLYSEGMNCONNECTION_TCOSTA;
	if (s == "pnlbrlysegmnconnection.tcosto") return PNLBRLYSEGMNCONNECTION_TCOSTO;
	if (s == "pnlbrlysegmnconnection.tcolp0") return PNLBRLYSEGMNCONNECTION_TCOLP0;
	if (s == "pnlbrlysegmnconnection.tcolp1") return PNLBRLYSEGMNCONNECTION_TCOLP1;
	if (s == "pnlbrlyconlist.tcogrp") return PNLBRLYCONLIST_TCOGRP;
	if (s == "pnlbrlyconlist.tcoown") return PNLBRLYCONLIST_TCOOWN;
	if (s == "pnlbrlyconlist.tcoflt") return PNLBRLYCONLIST_TCOFLT;
	if (s == "pnlbrlyconlist.tcocor") return PNLBRLYCONLIST_TCOCOR;
	if (s == "pnlbrlyconlist.tcosta") return PNLBRLYCONLIST_TCOSTA;
	if (s == "pnlbrlyconlist.tcosto") return PNLBRLYCONLIST_TCOSTO;
	if (s == "pnlbrlyconlist.tcomod") return PNLBRLYCONLIST_TCOMOD;
	if (s == "pnlbrlycon1nrelay.tcoref") return PNLBRLYCON1NRELAY_TCOREF;
	if (s == "pnlbrlyconref1nsegment.tcoref") return PNLBRLYCONREF1NSEGMENT_TCOREF;
	if (s == "pnlbrlyconconmnequipment.tcomref") return PNLBRLYCONCONMNEQUIPMENT_TCOMREF;
	if (s == "pnlbrlyconmnflight.tcomref") return PNLBRLYCONMNFLIGHT_TCOMREF;
	if (s == "pnlbrlyconmnflight.tcosta") return PNLBRLYCONMNFLIGHT_TCOSTA;
	if (s == "pnlbrlyconmnflight.tcosto") return PNLBRLYCONMNFLIGHT_TCOSTO;
	if (s == "pnlbrlyconmnflight.tcolp0") return PNLBRLYCONMNFLIGHT_TCOLP0;
	if (s == "pnlbrlyconmnflight.tcolp1") return PNLBRLYCONMNFLIGHT_TCOLP1;
	if (s == "pnlbrlyconmnsegment.tcomref") return PNLBRLYCONMNSEGMENT_TCOMREF;
	if (s == "pnlbrlyconmnsegment.tcosta") return PNLBRLYCONMNSEGMENT_TCOSTA;
	if (s == "pnlbrlyconmnsegment.tcosto") return PNLBRLYCONMNSEGMENT_TCOSTO;
	if (s == "pnlbrlyconmnsegment.tcolp0") return PNLBRLYCONMNSEGMENT_TCOLP0;
	if (s == "pnlbrlyconmnsegment.tcolp1") return PNLBRLYCONMNSEGMENT_TCOLP1;
	if (s == "pnlbrlyrlylist.tcosta") return PNLBRLYRLYLIST_TCOSTA;
	if (s == "pnlbrlyrlylist.tcosto") return PNLBRLYRLYLIST_TCOSTO;
	if (s == "pnlbrlyrlylist.tcocon") return PNLBRLYRLYLIST_TCOCON;
	if (s == "pnlbrlyrlylist.tcodir") return PNLBRLYRLYLIST_TCODIR;
	if (s == "pnlbrlyrlylist.tcoctd") return PNLBRLYRLYLIST_TCOCTD;
	if (s == "pnlbrlyrly1nnode.tcoref") return PNLBRLYRLY1NNODE_TCOREF;

	return(0);
};

string DbsBrly::VecVControl::getSref(
			const uint ix
		) {
	if (ix == PNLBRLYUSGLIST_TCOGRP) return("PnlBrlyUsgList.TcoGrp");
	if (ix == PNLBRLYUSGLIST_TCOOWN) return("PnlBrlyUsgList.TcoOwn");
	if (ix == PNLBRLYUSGLIST_TCOSRF) return("PnlBrlyUsgList.TcoSrf");
	if (ix == PNLBRLYUSGAACCESS_TCOFEG) return("PnlBrlyUsgAAccess.TcoFeg");
	if (ix == PNLBRLYUSGAACCESS_TCOFEA) return("PnlBrlyUsgAAccess.TcoFea");
	if (ix == PNLBRLYUSGAACCESS_TCOACC) return("PnlBrlyUsgAAccess.TcoAcc");
	if (ix == PNLBRLYUSGMNUSER_TCOMREF) return("PnlBrlyUsgMNUser.TcoMref");
	if (ix == PNLBRLYUSGMNUSER_TCOULV) return("PnlBrlyUsgMNUser.TcoUlv");
	if (ix == PNLBRLYUSRLIST_TCOGRP) return("PnlBrlyUsrList.TcoGrp");
	if (ix == PNLBRLYUSRLIST_TCOOWN) return("PnlBrlyUsrList.TcoOwn");
	if (ix == PNLBRLYUSRLIST_TCOPRS) return("PnlBrlyUsrList.TcoPrs");
	if (ix == PNLBRLYUSRLIST_TCOSRF) return("PnlBrlyUsrList.TcoSrf");
	if (ix == PNLBRLYUSRLIST_TCOUSG) return("PnlBrlyUsrList.TcoUsg");
	if (ix == PNLBRLYUSRLIST_TCOSTE) return("PnlBrlyUsrList.TcoSte");
	if (ix == PNLBRLYUSRLIST_TCOLCL) return("PnlBrlyUsrList.TcoLcl");
	if (ix == PNLBRLYUSRLIST_TCOULV) return("PnlBrlyUsrList.TcoUlv");
	if (ix == PNLBRLYUSRAACCESS_TCOFEG) return("PnlBrlyUsrAAccess.TcoFeg");
	if (ix == PNLBRLYUSRAACCESS_TCOFEA) return("PnlBrlyUsrAAccess.TcoFea");
	if (ix == PNLBRLYUSRAACCESS_TCOACC) return("PnlBrlyUsrAAccess.TcoAcc");
	if (ix == PNLBRLYUSR1NSESSION_TCOREF) return("PnlBrlyUsr1NSession.TcoRef");
	if (ix == PNLBRLYUSRMNUSERGROUP_TCOMREF) return("PnlBrlyUsrMNUsergroup.TcoMref");
	if (ix == PNLBRLYUSRMNUSERGROUP_TCOULV) return("PnlBrlyUsrMNUsergroup.TcoUlv");
	if (ix == PNLBRLYPRSLIST_TCOGRP) return("PnlBrlyPrsList.TcoGrp");
	if (ix == PNLBRLYPRSLIST_TCOOWN) return("PnlBrlyPrsList.TcoOwn");
	if (ix == PNLBRLYPRSLIST_TCOTIT) return("PnlBrlyPrsList.TcoTit");
	if (ix == PNLBRLYPRSLIST_TCOFNM) return("PnlBrlyPrsList.TcoFnm");
	if (ix == PNLBRLYPRSLIST_TCOLNM) return("PnlBrlyPrsList.TcoLnm");
	if (ix == PNLBRLYPRSLIST_TCOSEX) return("PnlBrlyPrsList.TcoSex");
	if (ix == PNLBRLYPRSLIST_TCOTEL) return("PnlBrlyPrsList.TcoTel");
	if (ix == PNLBRLYPRSLIST_TCOEML) return("PnlBrlyPrsList.TcoEml");
	if (ix == PNLBRLYPRSADETAIL_TCOTYP) return("PnlBrlyPrsADetail.TcoTyp");
	if (ix == PNLBRLYPRSADETAIL_TCOVAL) return("PnlBrlyPrsADetail.TcoVal");
	if (ix == PNLBRLYFILLIST_TCOGRP) return("PnlBrlyFilList.TcoGrp");
	if (ix == PNLBRLYFILLIST_TCOOWN) return("PnlBrlyFilList.TcoOwn");
	if (ix == PNLBRLYFILLIST_TCOFNM) return("PnlBrlyFilList.TcoFnm");
	if (ix == PNLBRLYFILLIST_TCORET) return("PnlBrlyFilList.TcoRet");
	if (ix == PNLBRLYFILLIST_TCOREU) return("PnlBrlyFilList.TcoReu");
	if (ix == PNLBRLYFILLIST_TCOCNT) return("PnlBrlyFilList.TcoCnt");
	if (ix == PNLBRLYFILLIST_TCOMIM) return("PnlBrlyFilList.TcoMim");
	if (ix == PNLBRLYFILLIST_TCOSIZ) return("PnlBrlyFilList.TcoSiz");
	if (ix == PNLBRLYOPRLIST_TCOSRF) return("PnlBrlyOprList.TcoSrf");
	if (ix == PNLBRLYOPRLIST_TCOICA) return("PnlBrlyOprList.TcoIca");
	if (ix == PNLBRLYOPRLIST_TCOTIT) return("PnlBrlyOprList.TcoTit");
	if (ix == PNLBRLYOPR1NEQUIPMENT_TCOREF) return("PnlBrlyOpr1NEquipment.TcoRef");
	if (ix == PNLBRLYPTYLIST_TCOSRF) return("PnlBrlyPtyList.TcoSrf");
	if (ix == PNLBRLYPTYLIST_TCOTIT) return("PnlBrlyPtyList.TcoTit");
	if (ix == PNLBRLYPTYLIST_TCOETY) return("PnlBrlyPtyList.TcoEty");
	if (ix == PNLBRLYPTYLIST_TCOCAP) return("PnlBrlyPtyList.TcoCap");
	if (ix == PNLBRLYPTY1NEQUIPMENT_TCOREF) return("PnlBrlyPty1NEquipment.TcoRef");
	if (ix == PNLBRLYREGLIST_TCOSRF) return("PnlBrlyRegList.TcoSrf");
	if (ix == PNLBRLYREGLIST_TCOTIT) return("PnlBrlyRegList.TcoTit");
	if (ix == PNLBRLYREGLIST_TCOSUP) return("PnlBrlyRegList.TcoSup");
	if (ix == PNLBRLYREGLIST_TCODST) return("PnlBrlyRegList.TcoDst");
	if (ix == PNLBRLYREGLIST_TCOTOF) return("PnlBrlyRegList.TcoTof");
	if (ix == PNLBRLYREGADSTSWITCH_TCOSTD) return("PnlBrlyRegADstswitch.TcoStd");
	if (ix == PNLBRLYREGADSTSWITCH_TCOSTT) return("PnlBrlyRegADstswitch.TcoStt");
	if (ix == PNLBRLYREG1NLOCATION_TCOREF) return("PnlBrlyReg1NLocation.TcoRef");
	if (ix == PNLBRLYREGSUP1NREGION_TCOREF) return("PnlBrlyRegSup1NRegion.TcoRef");
	if (ix == PNLBRLYLOCLIST_TCOSRF) return("PnlBrlyLocList.TcoSrf");
	if (ix == PNLBRLYLOCLIST_TCOICA) return("PnlBrlyLocList.TcoIca");
	if (ix == PNLBRLYLOCLIST_TCOTIT) return("PnlBrlyLocList.TcoTit");
	if (ix == PNLBRLYLOCLIST_TCOTYP) return("PnlBrlyLocList.TcoTyp");
	if (ix == PNLBRLYLOCLIST_TCOREG) return("PnlBrlyLocList.TcoReg");
	if (ix == PNLBRLYLOCLIST_TCOEQP) return("PnlBrlyLocList.TcoEqp");
	if (ix == PNLBRLYLOCLIST_TCOALT) return("PnlBrlyLocList.TcoAlt");
	if (ix == PNLBRLYLOCLIST_TCOTHE) return("PnlBrlyLocList.TcoThe");
	if (ix == PNLBRLYLOCLIST_TCOPHI) return("PnlBrlyLocList.TcoPhi");
	if (ix == PNLBRLYLOCBGN1NLEG_TCOREF) return("PnlBrlyLocBgn1NLeg.TcoRef");
	if (ix == PNLBRLYLOCEND1NLEG_TCOREF) return("PnlBrlyLocEnd1NLeg.TcoRef");
	if (ix == PNLBRLYLOCEQP1NNODE_TCOREF) return("PnlBrlyLocEqp1NNode.TcoRef");
	if (ix == PNLBRLYLOCMNSEGMENT_TCOMREF) return("PnlBrlyLocMNSegment.TcoMref");
	if (ix == PNLBRLYLOCMNSEGMENT_TCOSTA) return("PnlBrlyLocMNSegment.TcoSta");
	if (ix == PNLBRLYLOCMNSEGMENT_TCOSTO) return("PnlBrlyLocMNSegment.TcoSto");
	if (ix == PNLBRLYLOCMNSEGMENT_TCOSP0) return("PnlBrlyLocMNSegment.TcoSp0");
	if (ix == PNLBRLYLOCMNSEGMENT_TCOSP1) return("PnlBrlyLocMNSegment.TcoSp1");
	if (ix == PNLBRLYLOCMNSEGMENT_TCOSPH) return("PnlBrlyLocMNSegment.TcoSph");
	if (ix == PNLBRLYLOCMNSEGMENT_TCOSTH) return("PnlBrlyLocMNSegment.TcoSth");
	if (ix == PNLBRLYLOCMNFLIGHT_TCOMREF) return("PnlBrlyLocMNFlight.TcoMref");
	if (ix == PNLBRLYLOCMNFLIGHT_TCOSTA) return("PnlBrlyLocMNFlight.TcoSta");
	if (ix == PNLBRLYLOCMNFLIGHT_TCOSTO) return("PnlBrlyLocMNFlight.TcoSto");
	if (ix == PNLBRLYLOCMNFLIGHT_TCOXSA) return("PnlBrlyLocMNFlight.TcoXsa");
	if (ix == PNLBRLYLOCMNFLIGHT_TCOXSO) return("PnlBrlyLocMNFlight.TcoXso");
	if (ix == PNLBRLYLOCMNLEG_TCOMREF) return("PnlBrlyLocMNLeg.TcoMref");
	if (ix == PNLBRLYLOCMNLEG_TCOLP0) return("PnlBrlyLocMNLeg.TcoLp0");
	if (ix == PNLBRLYLOCMNLEG_TCOLP1) return("PnlBrlyLocMNLeg.TcoLp1");
	if (ix == PNLBRLYLOCMNLEG_TCOLPH) return("PnlBrlyLocMNLeg.TcoLph");
	if (ix == PNLBRLYLOCMNLEG_TCOLTH) return("PnlBrlyLocMNLeg.TcoLth");
	if (ix == PNLBRLYLOCMNLEG_TCOXP0) return("PnlBrlyLocMNLeg.TcoXp0");
	if (ix == PNLBRLYLOCMNLEG_TCOXP1) return("PnlBrlyLocMNLeg.TcoXp1");
	if (ix == PNLBRLYLOCVISORGMNLOCATION_TCOMREF) return("PnlBrlyLocVisOrgMNLocation.TcoMref");
	if (ix == PNLBRLYLOCPROXORGMNLOCATION_TCOMREF) return("PnlBrlyLocProxOrgMNLocation.TcoMref");
	if (ix == PNLBRLYLOCPROXORGMNLOCATION_TCODPH) return("PnlBrlyLocProxOrgMNLocation.TcoDph");
	if (ix == PNLBRLYLOCEQPMNCONNECTION_TCOMREF) return("PnlBrlyLocEqpMNConnection.TcoMref");
	if (ix == PNLBRLYLEGLIST_TCOGRP) return("PnlBrlyLegList.TcoGrp");
	if (ix == PNLBRLYLEGLIST_TCOOWN) return("PnlBrlyLegList.TcoOwn");
	if (ix == PNLBRLYLEGLIST_TCOBLO) return("PnlBrlyLegList.TcoBlo");
	if (ix == PNLBRLYLEGLIST_TCOELO) return("PnlBrlyLegList.TcoElo");
	if (ix == PNLBRLYLEGLIST_TCOTYP) return("PnlBrlyLegList.TcoTyp");
	if (ix == PNLBRLYLEGLIST_TCOALT) return("PnlBrlyLegList.TcoAlt");
	if (ix == PNLBRLYLEG1NFLIGHT_TCOREF) return("PnlBrlyLeg1NFlight.TcoRef");
	if (ix == PNLBRLYLEGCOR1NCONNECTION_TCOREF) return("PnlBrlyLegCor1NConnection.TcoRef");
	if (ix == PNLBRLYLEGMNLOCATION_TCOMREF) return("PnlBrlyLegMNLocation.TcoMref");
	if (ix == PNLBRLYLEGMNLOCATION_TCOLP0) return("PnlBrlyLegMNLocation.TcoLp0");
	if (ix == PNLBRLYLEGMNLOCATION_TCOLP1) return("PnlBrlyLegMNLocation.TcoLp1");
	if (ix == PNLBRLYLEGMNLOCATION_TCOLPH) return("PnlBrlyLegMNLocation.TcoLph");
	if (ix == PNLBRLYLEGMNLOCATION_TCOLTH) return("PnlBrlyLegMNLocation.TcoLth");
	if (ix == PNLBRLYLEGMNLOCATION_TCOXP0) return("PnlBrlyLegMNLocation.TcoXp0");
	if (ix == PNLBRLYLEGMNLOCATION_TCOXP1) return("PnlBrlyLegMNLocation.TcoXp1");
	if (ix == PNLBRLYLEGORGMNLEG_TCOMREF) return("PnlBrlyLegOrgMNLeg.TcoMref");
	if (ix == PNLBRLYLEGORGMNLEG_TCODP0) return("PnlBrlyLegOrgMNLeg.TcoDp0");
	if (ix == PNLBRLYLEGORGMNLEG_TCODP1) return("PnlBrlyLegOrgMNLeg.TcoDp1");
	if (ix == PNLBRLYLEGORGMNLEG_TCOOP0) return("PnlBrlyLegOrgMNLeg.TcoOp0");
	if (ix == PNLBRLYLEGORGMNLEG_TCOOP1) return("PnlBrlyLegOrgMNLeg.TcoOp1");
	if (ix == PNLBRLYLEGORGMNLEG_TCOXD0) return("PnlBrlyLegOrgMNLeg.TcoXd0");
	if (ix == PNLBRLYLEGORGMNLEG_TCOXD1) return("PnlBrlyLegOrgMNLeg.TcoXd1");
	if (ix == PNLBRLYLEGORGMNLEG_TCOXO0) return("PnlBrlyLegOrgMNLeg.TcoXo0");
	if (ix == PNLBRLYLEGORGMNLEG_TCOXO1) return("PnlBrlyLegOrgMNLeg.TcoXo1");
	if (ix == PNLBRLYTTBLIST_TCOTIT) return("PnlBrlyTtbList.TcoTit");
	if (ix == PNLBRLYTTBLIST_TCOFIL) return("PnlBrlyTtbList.TcoFil");
	if (ix == PNLBRLYTTBLIST_TCOALI) return("PnlBrlyTtbList.TcoAli");
	if (ix == PNLBRLYTTBLIST_TCOSTA) return("PnlBrlyTtbList.TcoSta");
	if (ix == PNLBRLYTTBLIST_TCOSTO) return("PnlBrlyTtbList.TcoSto");
	if (ix == PNLBRLYTTB1NFLIGHT_TCOREF) return("PnlBrlyTtb1NFlight.TcoRef");
	if (ix == PNLBRLYTTBREF1NFILE_TCOREF) return("PnlBrlyTtbRef1NFile.TcoRef");
	if (ix == PNLBRLYFLTLIST_TCOSRF) return("PnlBrlyFltList.TcoSrf");
	if (ix == PNLBRLYFLTLIST_TCOEQP) return("PnlBrlyFltList.TcoEqp");
	if (ix == PNLBRLYFLTLIST_TCOLEG) return("PnlBrlyFltList.TcoLeg");
	if (ix == PNLBRLYFLTLIST_TCOSTA) return("PnlBrlyFltList.TcoSta");
	if (ix == PNLBRLYFLTLIST_TCOSTO) return("PnlBrlyFltList.TcoSto");
	if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOTMS) return("PnlBrlyFltFafAWaypoint.TcoTms");
	if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOLAT) return("PnlBrlyFltFafAWaypoint.TcoLat");
	if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOLON) return("PnlBrlyFltFafAWaypoint.TcoLon");
	if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOGSP) return("PnlBrlyFltFafAWaypoint.TcoGsp");
	if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOALT) return("PnlBrlyFltFafAWaypoint.TcoAlt");
	if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOAST) return("PnlBrlyFltFafAWaypoint.TcoAst");
	if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOUTY) return("PnlBrlyFltFafAWaypoint.TcoUty");
	if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOACH) return("PnlBrlyFltFafAWaypoint.TcoAch");
	if (ix == PNLBRLYFLT1NCONNECTION_TCOREF) return("PnlBrlyFlt1NConnection.TcoRef");
	if (ix == PNLBRLYFLTREF1NSEGMENT_TCOREF) return("PnlBrlyFltRef1NSegment.TcoRef");
	if (ix == PNLBRLYFLTEQP1NNODE_TCOREF) return("PnlBrlyFltEqp1NNode.TcoRef");
	if (ix == PNLBRLYFLTMNLOCATION_TCOMREF) return("PnlBrlyFltMNLocation.TcoMref");
	if (ix == PNLBRLYFLTMNLOCATION_TCOSTA) return("PnlBrlyFltMNLocation.TcoSta");
	if (ix == PNLBRLYFLTMNLOCATION_TCOSTO) return("PnlBrlyFltMNLocation.TcoSto");
	if (ix == PNLBRLYFLTMNLOCATION_TCOXSA) return("PnlBrlyFltMNLocation.TcoXsa");
	if (ix == PNLBRLYFLTMNLOCATION_TCOXSO) return("PnlBrlyFltMNLocation.TcoXso");
	if (ix == PNLBRLYFLTORGMNFLIGHT_TCOMREF) return("PnlBrlyFltOrgMNFlight.TcoMref");
	if (ix == PNLBRLYFLTORGMNFLIGHT_TCOSTA) return("PnlBrlyFltOrgMNFlight.TcoSta");
	if (ix == PNLBRLYFLTORGMNFLIGHT_TCOSTO) return("PnlBrlyFltOrgMNFlight.TcoSto");
	if (ix == PNLBRLYFLTORGMNFLIGHT_TCOXSA) return("PnlBrlyFltOrgMNFlight.TcoXsa");
	if (ix == PNLBRLYFLTORGMNFLIGHT_TCOXSO) return("PnlBrlyFltOrgMNFlight.TcoXso");
	if (ix == PNLBRLYFLTMNCONNECTION_TCOMREF) return("PnlBrlyFltMNConnection.TcoMref");
	if (ix == PNLBRLYFLTMNCONNECTION_TCOSTA) return("PnlBrlyFltMNConnection.TcoSta");
	if (ix == PNLBRLYFLTMNCONNECTION_TCOSTO) return("PnlBrlyFltMNConnection.TcoSto");
	if (ix == PNLBRLYFLTMNCONNECTION_TCOLP0) return("PnlBrlyFltMNConnection.TcoLp0");
	if (ix == PNLBRLYFLTMNCONNECTION_TCOLP1) return("PnlBrlyFltMNConnection.TcoLp1");
	if (ix == PNLBRLYFLTEQPMNCONNECTION_TCOMREF) return("PnlBrlyFltEqpMNConnection.TcoMref");
	if (ix == PNLBRLYSEGLIST_TCORET) return("PnlBrlySegList.TcoRet");
	if (ix == PNLBRLYSEGLIST_TCOREU) return("PnlBrlySegList.TcoReu");
	if (ix == PNLBRLYSEGLIST_TCOAL0) return("PnlBrlySegList.TcoAl0");
	if (ix == PNLBRLYSEGLIST_TCOAL1) return("PnlBrlySegList.TcoAl1");
	if (ix == PNLBRLYSEGLIST_TCOTH0) return("PnlBrlySegList.TcoTh0");
	if (ix == PNLBRLYSEGLIST_TCOTH1) return("PnlBrlySegList.TcoTh1");
	if (ix == PNLBRLYSEGLIST_TCOPH0) return("PnlBrlySegList.TcoPh0");
	if (ix == PNLBRLYSEGLIST_TCOPH1) return("PnlBrlySegList.TcoPh1");
	if (ix == PNLBRLYSEGLIST_TCOSTA) return("PnlBrlySegList.TcoSta");
	if (ix == PNLBRLYSEGLIST_TCOSTO) return("PnlBrlySegList.TcoSto");
	if (ix == PNLBRLYSEGORGMNSEGMENT_TCOMREF) return("PnlBrlySegOrgMNSegment.TcoMref");
	if (ix == PNLBRLYSEGORGMNSEGMENT_TCOSTA) return("PnlBrlySegOrgMNSegment.TcoSta");
	if (ix == PNLBRLYSEGORGMNSEGMENT_TCOSTO) return("PnlBrlySegOrgMNSegment.TcoSto");
	if (ix == PNLBRLYSEGORGMNSEGMENT_TCODP0) return("PnlBrlySegOrgMNSegment.TcoDp0");
	if (ix == PNLBRLYSEGORGMNSEGMENT_TCODP1) return("PnlBrlySegOrgMNSegment.TcoDp1");
	if (ix == PNLBRLYSEGORGMNSEGMENT_TCOOP0) return("PnlBrlySegOrgMNSegment.TcoOp0");
	if (ix == PNLBRLYSEGORGMNSEGMENT_TCOOP1) return("PnlBrlySegOrgMNSegment.TcoOp1");
	if (ix == PNLBRLYSEGMNLOCATION_TCOMREF) return("PnlBrlySegMNLocation.TcoMref");
	if (ix == PNLBRLYSEGMNLOCATION_TCOSTA) return("PnlBrlySegMNLocation.TcoSta");
	if (ix == PNLBRLYSEGMNLOCATION_TCOSTO) return("PnlBrlySegMNLocation.TcoSto");
	if (ix == PNLBRLYSEGMNLOCATION_TCOSP0) return("PnlBrlySegMNLocation.TcoSp0");
	if (ix == PNLBRLYSEGMNLOCATION_TCOSP1) return("PnlBrlySegMNLocation.TcoSp1");
	if (ix == PNLBRLYSEGMNLOCATION_TCOSPH) return("PnlBrlySegMNLocation.TcoSph");
	if (ix == PNLBRLYSEGMNLOCATION_TCOSTH) return("PnlBrlySegMNLocation.TcoSth");
	if (ix == PNLBRLYSEGMNCONNECTION_TCOMREF) return("PnlBrlySegMNConnection.TcoMref");
	if (ix == PNLBRLYSEGMNCONNECTION_TCOSTA) return("PnlBrlySegMNConnection.TcoSta");
	if (ix == PNLBRLYSEGMNCONNECTION_TCOSTO) return("PnlBrlySegMNConnection.TcoSto");
	if (ix == PNLBRLYSEGMNCONNECTION_TCOLP0) return("PnlBrlySegMNConnection.TcoLp0");
	if (ix == PNLBRLYSEGMNCONNECTION_TCOLP1) return("PnlBrlySegMNConnection.TcoLp1");
	if (ix == PNLBRLYCONLIST_TCOGRP) return("PnlBrlyConList.TcoGrp");
	if (ix == PNLBRLYCONLIST_TCOOWN) return("PnlBrlyConList.TcoOwn");
	if (ix == PNLBRLYCONLIST_TCOFLT) return("PnlBrlyConList.TcoFlt");
	if (ix == PNLBRLYCONLIST_TCOCOR) return("PnlBrlyConList.TcoCor");
	if (ix == PNLBRLYCONLIST_TCOSTA) return("PnlBrlyConList.TcoSta");
	if (ix == PNLBRLYCONLIST_TCOSTO) return("PnlBrlyConList.TcoSto");
	if (ix == PNLBRLYCONLIST_TCOMOD) return("PnlBrlyConList.TcoMod");
	if (ix == PNLBRLYCON1NRELAY_TCOREF) return("PnlBrlyCon1NRelay.TcoRef");
	if (ix == PNLBRLYCONREF1NSEGMENT_TCOREF) return("PnlBrlyConRef1NSegment.TcoRef");
	if (ix == PNLBRLYCONCONMNEQUIPMENT_TCOMREF) return("PnlBrlyConConMNEquipment.TcoMref");
	if (ix == PNLBRLYCONMNFLIGHT_TCOMREF) return("PnlBrlyConMNFlight.TcoMref");
	if (ix == PNLBRLYCONMNFLIGHT_TCOSTA) return("PnlBrlyConMNFlight.TcoSta");
	if (ix == PNLBRLYCONMNFLIGHT_TCOSTO) return("PnlBrlyConMNFlight.TcoSto");
	if (ix == PNLBRLYCONMNFLIGHT_TCOLP0) return("PnlBrlyConMNFlight.TcoLp0");
	if (ix == PNLBRLYCONMNFLIGHT_TCOLP1) return("PnlBrlyConMNFlight.TcoLp1");
	if (ix == PNLBRLYCONMNSEGMENT_TCOMREF) return("PnlBrlyConMNSegment.TcoMref");
	if (ix == PNLBRLYCONMNSEGMENT_TCOSTA) return("PnlBrlyConMNSegment.TcoSta");
	if (ix == PNLBRLYCONMNSEGMENT_TCOSTO) return("PnlBrlyConMNSegment.TcoSto");
	if (ix == PNLBRLYCONMNSEGMENT_TCOLP0) return("PnlBrlyConMNSegment.TcoLp0");
	if (ix == PNLBRLYCONMNSEGMENT_TCOLP1) return("PnlBrlyConMNSegment.TcoLp1");
	if (ix == PNLBRLYRLYLIST_TCOSTA) return("PnlBrlyRlyList.TcoSta");
	if (ix == PNLBRLYRLYLIST_TCOSTO) return("PnlBrlyRlyList.TcoSto");
	if (ix == PNLBRLYRLYLIST_TCOCON) return("PnlBrlyRlyList.TcoCon");
	if (ix == PNLBRLYRLYLIST_TCODIR) return("PnlBrlyRlyList.TcoDir");
	if (ix == PNLBRLYRLYLIST_TCOCTD) return("PnlBrlyRlyList.TcoCtd");
	if (ix == PNLBRLYRLY1NNODE_TCOREF) return("PnlBrlyRly1NNode.TcoRef");

	return("");
};

/******************************************************************************
 class DbsBrly::VecVFeatgroup
 ******************************************************************************/

uint DbsBrly::VecVFeatgroup::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vecbrlyvcard") return VECBRLYVCARD;

	return(0);
};

string DbsBrly::VecVFeatgroup::getSref(
			const uint ix
		) {
	if (ix == VECBRLYVCARD) return("VecBrlyVCard");

	return("");
};

string DbsBrly::VecVFeatgroup::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == VECBRLYVCARD) return("card");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == VECBRLYVCARD) return("Karte");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsBrly::VecVFeatgroup::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVKeylist
 ******************************************************************************/

uint DbsBrly::VecVKeylist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "klstbrlykalliance") return KLSTBRLYKALLIANCE;
	if (s == "klstbrlykampersondetailtype") return KLSTBRLYKAMPERSONDETAILTYPE;
	if (s == "klstbrlykeqptype") return KLSTBRLYKEQPTYPE;
	if (s == "klstbrlykmfilecontent") return KLSTBRLYKMFILECONTENT;
	if (s == "klstbrlykmfilemimetype") return KLSTBRLYKMFILEMIMETYPE;

	return(0);
};

string DbsBrly::VecVKeylist::getSref(
			const uint ix
		) {
	if (ix == KLSTBRLYKALLIANCE) return("KlstBrlyKAlliance");
	if (ix == KLSTBRLYKAMPERSONDETAILTYPE) return("KlstBrlyKAMPersonDetailType");
	if (ix == KLSTBRLYKEQPTYPE) return("KlstBrlyKEqptype");
	if (ix == KLSTBRLYKMFILECONTENT) return("KlstBrlyKMFileContent");
	if (ix == KLSTBRLYKMFILEMIMETYPE) return("KlstBrlyKMFileMimetype");

	return("");
};

string DbsBrly::VecVKeylist::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == KLSTBRLYKALLIANCE) return("airline alliance");
		if (ix == KLSTBRLYKAMPERSONDETAILTYPE) return("type");
		if (ix == KLSTBRLYKEQPTYPE) return("equipment type");
		if (ix == KLSTBRLYKMFILECONTENT) return("content");
		if (ix == KLSTBRLYKMFILEMIMETYPE) return("MIME type");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == KLSTBRLYKALLIANCE) return("Luftfahrtallianz");
		if (ix == KLSTBRLYKAMPERSONDETAILTYPE) return("Typ");
		if (ix == KLSTBRLYKEQPTYPE) return("Ger\\u00e4tetyp");
		if (ix == KLSTBRLYKMFILECONTENT) return("Inhalt");
		if (ix == KLSTBRLYKMFILEMIMETYPE) return("MIME-Typ");
		return(getTitle(ix, 1));
	};

	return("");
};

/******************************************************************************
 class DbsBrly::VecVLat
 ******************************************************************************/

uint DbsBrly::VecVLat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dlo") return DLO;
	if (s == "ini") return INI;

	return(0);
};

string DbsBrly::VecVLat::getSref(
			const uint ix
		) {
	if (ix == DLO) return("dlo");
	if (ix == INI) return("ini");

	return("");
};

/******************************************************************************
 class DbsBrly::VecVLocale
 ******************************************************************************/

uint DbsBrly::VecVLocale::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "enus") return ENUS;
	if (s == "dech") return DECH;

	return(0);
};

string DbsBrly::VecVLocale::getSref(
			const uint ix
		) {
	if (ix == ENUS) return("enus");
	if (ix == DECH) return("dech");

	return("");
};

string DbsBrly::VecVLocale::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == ENUS) return("English (United States)");
		if (ix == DECH) return("German (Switzerland)");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == ENUS) return("Englisch (Vereinigte Staaten)");
		if (ix == DECH) return("Deutsch (Schweiz)");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsBrly::VecVLocale::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVLop
 ******************************************************************************/

uint DbsBrly::VecVLop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "rmv") return RMV;

	return(0);
};

string DbsBrly::VecVLop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RMV) return("rmv");

	return("");
};

/******************************************************************************
 class DbsBrly::VecVMaintable
 ******************************************************************************/

uint DbsBrly::VecVMaintable::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tblbrlymconnection") return TBLBRLYMCONNECTION;
	if (s == "tblbrlymequipment") return TBLBRLYMEQUIPMENT;
	if (s == "tblbrlymfaflight") return TBLBRLYMFAFLIGHT;
	if (s == "tblbrlymfile") return TBLBRLYMFILE;
	if (s == "tblbrlymflight") return TBLBRLYMFLIGHT;
	if (s == "tblbrlymleg") return TBLBRLYMLEG;
	if (s == "tblbrlymlocation") return TBLBRLYMLOCATION;
	if (s == "tblbrlymnode") return TBLBRLYMNODE;
	if (s == "tblbrlymoperator") return TBLBRLYMOPERATOR;
	if (s == "tblbrlymperson") return TBLBRLYMPERSON;
	if (s == "tblbrlymplntype") return TBLBRLYMPLNTYPE;
	if (s == "tblbrlymregion") return TBLBRLYMREGION;
	if (s == "tblbrlymrelay") return TBLBRLYMRELAY;
	if (s == "tblbrlymsegment") return TBLBRLYMSEGMENT;
	if (s == "tblbrlymsession") return TBLBRLYMSESSION;
	if (s == "tblbrlymtimetable") return TBLBRLYMTIMETABLE;
	if (s == "tblbrlymuser") return TBLBRLYMUSER;
	if (s == "tblbrlymusergroup") return TBLBRLYMUSERGROUP;

	return(0);
};

string DbsBrly::VecVMaintable::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBLBRLYMCONNECTION) return("TblBrlyMConnection");
	if (ix == TBLBRLYMEQUIPMENT) return("TblBrlyMEquipment");
	if (ix == TBLBRLYMFAFLIGHT) return("TblBrlyMFaflight");
	if (ix == TBLBRLYMFILE) return("TblBrlyMFile");
	if (ix == TBLBRLYMFLIGHT) return("TblBrlyMFlight");
	if (ix == TBLBRLYMLEG) return("TblBrlyMLeg");
	if (ix == TBLBRLYMLOCATION) return("TblBrlyMLocation");
	if (ix == TBLBRLYMNODE) return("TblBrlyMNode");
	if (ix == TBLBRLYMOPERATOR) return("TblBrlyMOperator");
	if (ix == TBLBRLYMPERSON) return("TblBrlyMPerson");
	if (ix == TBLBRLYMPLNTYPE) return("TblBrlyMPlntype");
	if (ix == TBLBRLYMREGION) return("TblBrlyMRegion");
	if (ix == TBLBRLYMRELAY) return("TblBrlyMRelay");
	if (ix == TBLBRLYMSEGMENT) return("TblBrlyMSegment");
	if (ix == TBLBRLYMSESSION) return("TblBrlyMSession");
	if (ix == TBLBRLYMTIMETABLE) return("TblBrlyMTimetable");
	if (ix == TBLBRLYMUSER) return("TblBrlyMUser");
	if (ix == TBLBRLYMUSERGROUP) return("TblBrlyMUsergroup");

	return("");
};

string DbsBrly::VecVMaintable::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TBLBRLYMCONNECTION) return("connection");
		if (ix == TBLBRLYMEQUIPMENT) return("equipment");
		if (ix == TBLBRLYMFAFLIGHT) return("FlightAware flight");
		if (ix == TBLBRLYMFILE) return("file");
		if (ix == TBLBRLYMFLIGHT) return("flight");
		if (ix == TBLBRLYMLEG) return("leg");
		if (ix == TBLBRLYMLOCATION) return("location");
		if (ix == TBLBRLYMNODE) return("node");
		if (ix == TBLBRLYMOPERATOR) return("operator");
		if (ix == TBLBRLYMPERSON) return("person");
		if (ix == TBLBRLYMPLNTYPE) return("plane type");
		if (ix == TBLBRLYMREGION) return("region");
		if (ix == TBLBRLYMRELAY) return("relay");
		if (ix == TBLBRLYMSEGMENT) return("segment");
		if (ix == TBLBRLYMSESSION) return("session");
		if (ix == TBLBRLYMTIMETABLE) return("timetable");
		if (ix == TBLBRLYMUSER) return("user");
		if (ix == TBLBRLYMUSERGROUP) return("user group");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == VOID) return("kein");
		if (ix == TBLBRLYMCONNECTION) return("Verbindung");
		if (ix == TBLBRLYMEQUIPMENT) return("Ger\\u00e4t");
		if (ix == TBLBRLYMFAFLIGHT) return("FlightAware Flug");
		if (ix == TBLBRLYMFILE) return("Datei");
		if (ix == TBLBRLYMFLIGHT) return("Flug");
		if (ix == TBLBRLYMLEG) return("Strecke");
		if (ix == TBLBRLYMLOCATION) return("Ort");
		if (ix == TBLBRLYMNODE) return("Knotenpunkt");
		if (ix == TBLBRLYMOPERATOR) return("Betreiber");
		if (ix == TBLBRLYMPERSON) return("Person");
		if (ix == TBLBRLYMPLNTYPE) return("Flugzeugtyp");
		if (ix == TBLBRLYMREGION) return("Region");
		if (ix == TBLBRLYMRELAY) return("Verbindungskette");
		if (ix == TBLBRLYMSEGMENT) return("Segment");
		if (ix == TBLBRLYMSESSION) return("Siztung");
		if (ix == TBLBRLYMTIMETABLE) return("Flugplan");
		if (ix == TBLBRLYMUSER) return("Benutzer");
		if (ix == TBLBRLYMUSERGROUP) return("Benutzergruppe");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsBrly::VecVMaintable::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 19; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVOolop
 ******************************************************************************/

uint DbsBrly::VecVOolop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ina") return INA;
	if (s == "inb") return INB;
	if (s == "rmv") return RMV;
	if (s == "swp") return SWP;
	if (s == "toa") return TOA;
	if (s == "tob") return TOB;

	return(0);
};

string DbsBrly::VecVOolop::getSref(
			const uint ix
		) {
	if (ix == INA) return("ina");
	if (ix == INB) return("inb");
	if (ix == RMV) return("rmv");
	if (ix == SWP) return("swp");
	if (ix == TOA) return("toa");
	if (ix == TOB) return("tob");

	return("");
};

/******************************************************************************
 class DbsBrly::VecVPreset
 ******************************************************************************/

uint DbsBrly::VecVPreset::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "prebrlyadmin") return PREBRLYADMIN;
	if (s == "prebrlycon1nrelay.x1") return PREBRLYCON1NRELAY_X1;
	if (s == "prebrlyconconmnequipment.opr.x1") return PREBRLYCONCONMNEQUIPMENT_OPR_X1;
	if (s == "prebrlyconlist.cor") return PREBRLYCONLIST_COR;
	if (s == "prebrlyconlist.flt") return PREBRLYCONLIST_FLT;
	if (s == "prebrlyconlist.grp") return PREBRLYCONLIST_GRP;
	if (s == "prebrlyconlist.own") return PREBRLYCONLIST_OWN;
	if (s == "prebrlyconlist.sta") return PREBRLYCONLIST_STA;
	if (s == "prebrlyconmnflight.x1") return PREBRLYCONMNFLIGHT_X1;
	if (s == "prebrlyconmnflight.x2") return PREBRLYCONMNFLIGHT_X2;
	if (s == "prebrlyconmnsegment.x1") return PREBRLYCONMNSEGMENT_X1;
	if (s == "prebrlyconmnsegment.x2") return PREBRLYCONMNSEGMENT_X2;
	if (s == "prebrlyfillist.fnm") return PREBRLYFILLIST_FNM;
	if (s == "prebrlyfillist.grp") return PREBRLYFILLIST_GRP;
	if (s == "prebrlyfillist.own") return PREBRLYFILLIST_OWN;
	if (s == "prebrlyfillist.ret") return PREBRLYFILLIST_RET;
	if (s == "prebrlyfillist.reu") return PREBRLYFILLIST_REU;
	if (s == "prebrlyfltdstmnflight.x1") return PREBRLYFLTDSTMNFLIGHT_X1;
	if (s == "prebrlyfltlist.eqp") return PREBRLYFLTLIST_EQP;
	if (s == "prebrlyfltlist.leg") return PREBRLYFLTLIST_LEG;
	if (s == "prebrlyfltlist.srf") return PREBRLYFLTLIST_SRF;
	if (s == "prebrlyfltlist.sta") return PREBRLYFLTLIST_STA;
	if (s == "prebrlyfltlist.sto") return PREBRLYFLTLIST_STO;
	if (s == "prebrlyfltmnconnection.x1") return PREBRLYFLTMNCONNECTION_X1;
	if (s == "prebrlyfltmnconnection.x2") return PREBRLYFLTMNCONNECTION_X2;
	if (s == "prebrlyfltmnlocation.x1") return PREBRLYFLTMNLOCATION_X1;
	if (s == "prebrlyfltorgmnflight.x1") return PREBRLYFLTORGMNFLIGHT_X1;
	if (s == "prebrlygroup") return PREBRLYGROUP;
	if (s == "prebrlyip") return PREBRLYIP;
	if (s == "prebrlyixcrdacccon") return PREBRLYIXCRDACCCON;
	if (s == "prebrlyixcrdaccfil") return PREBRLYIXCRDACCFIL;
	if (s == "prebrlyixcrdaccflt") return PREBRLYIXCRDACCFLT;
	if (s == "prebrlyixcrdaccleg") return PREBRLYIXCRDACCLEG;
	if (s == "prebrlyixcrdaccloc") return PREBRLYIXCRDACCLOC;
	if (s == "prebrlyixcrdaccopr") return PREBRLYIXCRDACCOPR;
	if (s == "prebrlyixcrdaccprs") return PREBRLYIXCRDACCPRS;
	if (s == "prebrlyixcrdaccpty") return PREBRLYIXCRDACCPTY;
	if (s == "prebrlyixcrdaccreg") return PREBRLYIXCRDACCREG;
	if (s == "prebrlyixcrdaccrly") return PREBRLYIXCRDACCRLY;
	if (s == "prebrlyixcrdaccseg") return PREBRLYIXCRDACCSEG;
	if (s == "prebrlyixcrdaccttb") return PREBRLYIXCRDACCTTB;
	if (s == "prebrlyixcrdaccusg") return PREBRLYIXCRDACCUSG;
	if (s == "prebrlyixcrdaccusr") return PREBRLYIXCRDACCUSR;
	if (s == "prebrlyixlcl") return PREBRLYIXLCL;
	if (s == "prebrlyixord") return PREBRLYIXORD;
	if (s == "prebrlyixpre") return PREBRLYIXPRE;
	if (s == "prebrlyixrecacc") return PREBRLYIXRECACC;
	if (s == "prebrlyjrefnotify") return PREBRLYJREFNOTIFY;
	if (s == "prebrlyjrefsess") return PREBRLYJREFSESS;
	if (s == "prebrlylegdstmnleg.x1") return PREBRLYLEGDSTMNLEG_X1;
	if (s == "prebrlyleglist.blo") return PREBRLYLEGLIST_BLO;
	if (s == "prebrlyleglist.elo") return PREBRLYLEGLIST_ELO;
	if (s == "prebrlyleglist.grp") return PREBRLYLEGLIST_GRP;
	if (s == "prebrlyleglist.own") return PREBRLYLEGLIST_OWN;
	if (s == "prebrlyleglist.typ") return PREBRLYLEGLIST_TYP;
	if (s == "prebrlylegmnlocation.x1") return PREBRLYLEGMNLOCATION_X1;
	if (s == "prebrlylegorgmnleg.x1") return PREBRLYLEGORGMNLEG_X1;
	if (s == "prebrlyloclist.eqp") return PREBRLYLOCLIST_EQP;
	if (s == "prebrlyloclist.ica") return PREBRLYLOCLIST_ICA;
	if (s == "prebrlyloclist.reg") return PREBRLYLOCLIST_REG;
	if (s == "prebrlyloclist.srf") return PREBRLYLOCLIST_SRF;
	if (s == "prebrlyloclist.tit") return PREBRLYLOCLIST_TIT;
	if (s == "prebrlyloclist.typ") return PREBRLYLOCLIST_TYP;
	if (s == "prebrlylocmnflight.x1") return PREBRLYLOCMNFLIGHT_X1;
	if (s == "prebrlylocmnleg.x1") return PREBRLYLOCMNLEG_X1;
	if (s == "prebrlylocmnsegment.x1") return PREBRLYLOCMNSEGMENT_X1;
	if (s == "prebrlylocmnsegment.x2") return PREBRLYLOCMNSEGMENT_X2;
	if (s == "prebrlynoadm") return PREBRLYNOADM;
	if (s == "prebrlyoprlist.ica") return PREBRLYOPRLIST_ICA;
	if (s == "prebrlyoprlist.srf") return PREBRLYOPRLIST_SRF;
	if (s == "prebrlyoprlist.tit") return PREBRLYOPRLIST_TIT;
	if (s == "prebrlyowner") return PREBRLYOWNER;
	if (s == "prebrlyphi") return PREBRLYPHI;
	if (s == "prebrlyprsadetail.x1") return PREBRLYPRSADETAIL_X1;
	if (s == "prebrlyprslist.grp") return PREBRLYPRSLIST_GRP;
	if (s == "prebrlyprslist.lnm") return PREBRLYPRSLIST_LNM;
	if (s == "prebrlyprslist.own") return PREBRLYPRSLIST_OWN;
	if (s == "prebrlyptylist.srf") return PREBRLYPTYLIST_SRF;
	if (s == "prebrlyptylist.tit") return PREBRLYPTYLIST_TIT;
	if (s == "prebrlyrefapt") return PREBRLYREFAPT;
	if (s == "prebrlyrefcon") return PREBRLYREFCON;
	if (s == "prebrlyrefcor") return PREBRLYREFCOR;
	if (s == "prebrlyrefeqp") return PREBRLYREFEQP;
	if (s == "prebrlyreffaf") return PREBRLYREFFAF;
	if (s == "prebrlyreffil") return PREBRLYREFFIL;
	if (s == "prebrlyrefflt") return PREBRLYREFFLT;
	if (s == "prebrlyrefleg") return PREBRLYREFLEG;
	if (s == "prebrlyrefloc") return PREBRLYREFLOC;
	if (s == "prebrlyrefnde") return PREBRLYREFNDE;
	if (s == "prebrlyrefopr") return PREBRLYREFOPR;
	if (s == "prebrlyrefpln") return PREBRLYREFPLN;
	if (s == "prebrlyrefprs") return PREBRLYREFPRS;
	if (s == "prebrlyrefpty") return PREBRLYREFPTY;
	if (s == "prebrlyrefreg") return PREBRLYREFREG;
	if (s == "prebrlyrefrip") return PREBRLYREFRIP;
	if (s == "prebrlyrefrly") return PREBRLYREFRLY;
	if (s == "prebrlyrefrte") return PREBRLYREFRTE;
	if (s == "prebrlyrefseg") return PREBRLYREFSEG;
	if (s == "prebrlyrefsel") return PREBRLYREFSEL;
	if (s == "prebrlyrefses") return PREBRLYREFSES;
	if (s == "prebrlyrefttb") return PREBRLYREFTTB;
	if (s == "prebrlyrefusg") return PREBRLYREFUSG;
	if (s == "prebrlyrefusr") return PREBRLYREFUSR;
	if (s == "prebrlyreglist.srf") return PREBRLYREGLIST_SRF;
	if (s == "prebrlyreglist.sup") return PREBRLYREGLIST_SUP;
	if (s == "prebrlyreglist.tit") return PREBRLYREGLIST_TIT;
	if (s == "prebrlyrlylist.con") return PREBRLYRLYLIST_CON;
	if (s == "prebrlyrlylist.dir") return PREBRLYRLYLIST_DIR;
	if (s == "prebrlyrlylist.sta") return PREBRLYRLYLIST_STA;
	if (s == "prebrlyrlylist.sto") return PREBRLYRLYLIST_STO;
	if (s == "prebrlysegdstmnsegment.x1") return PREBRLYSEGDSTMNSEGMENT_X1;
	if (s == "prebrlysegdstmnsegment.x2") return PREBRLYSEGDSTMNSEGMENT_X2;
	if (s == "prebrlyseglist.ret") return PREBRLYSEGLIST_RET;
	if (s == "prebrlyseglist.reu") return PREBRLYSEGLIST_REU;
	if (s == "prebrlyseglist.sta") return PREBRLYSEGLIST_STA;
	if (s == "prebrlyseglist.sto") return PREBRLYSEGLIST_STO;
	if (s == "prebrlysegmnconnection.x1") return PREBRLYSEGMNCONNECTION_X1;
	if (s == "prebrlysegmnconnection.x2") return PREBRLYSEGMNCONNECTION_X2;
	if (s == "prebrlysegmnlocation.x1") return PREBRLYSEGMNLOCATION_X1;
	if (s == "prebrlysegmnlocation.x2") return PREBRLYSEGMNLOCATION_X2;
	if (s == "prebrlysegorgmnsegment.x1") return PREBRLYSEGORGMNSEGMENT_X1;
	if (s == "prebrlysegorgmnsegment.x2") return PREBRLYSEGORGMNSEGMENT_X2;
	if (s == "prebrlysess") return PREBRLYSESS;
	if (s == "prebrlysuspsess") return PREBRLYSUSPSESS;
	if (s == "prebrlysysdate") return PREBRLYSYSDATE;
	if (s == "prebrlysysstamp") return PREBRLYSYSSTAMP;
	if (s == "prebrlysystime") return PREBRLYSYSTIME;
	if (s == "prebrlytime") return PREBRLYTIME;
	if (s == "prebrlytlast") return PREBRLYTLAST;
	if (s == "prebrlyttblist.fil") return PREBRLYTTBLIST_FIL;
	if (s == "prebrlyttblist.tit") return PREBRLYTTBLIST_TIT;
	if (s == "prebrlyusgaaccess.x1") return PREBRLYUSGAACCESS_X1;
	if (s == "prebrlyusgaaccess.x2") return PREBRLYUSGAACCESS_X2;
	if (s == "prebrlyusglist.grp") return PREBRLYUSGLIST_GRP;
	if (s == "prebrlyusglist.own") return PREBRLYUSGLIST_OWN;
	if (s == "prebrlyusglist.srf") return PREBRLYUSGLIST_SRF;
	if (s == "prebrlyusraaccess.x1") return PREBRLYUSRAACCESS_X1;
	if (s == "prebrlyusraaccess.x2") return PREBRLYUSRAACCESS_X2;
	if (s == "prebrlyusrlist.grp") return PREBRLYUSRLIST_GRP;
	if (s == "prebrlyusrlist.own") return PREBRLYUSRLIST_OWN;
	if (s == "prebrlyusrlist.prs") return PREBRLYUSRLIST_PRS;
	if (s == "prebrlyusrlist.srf") return PREBRLYUSRLIST_SRF;
	if (s == "prebrlyusrlist.ste") return PREBRLYUSRLIST_STE;
	if (s == "prebrlyusrlist.usg") return PREBRLYUSRLIST_USG;

	return(0);
};

string DbsBrly::VecVPreset::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PREBRLYADMIN) return("PreBrlyAdmin");
	if (ix == PREBRLYCON1NRELAY_X1) return("PreBrlyCon1NRelay.x1");
	if (ix == PREBRLYCONCONMNEQUIPMENT_OPR_X1) return("PreBrlyConConMNEquipment.opr.x1");
	if (ix == PREBRLYCONLIST_COR) return("PreBrlyConList.cor");
	if (ix == PREBRLYCONLIST_FLT) return("PreBrlyConList.flt");
	if (ix == PREBRLYCONLIST_GRP) return("PreBrlyConList.grp");
	if (ix == PREBRLYCONLIST_OWN) return("PreBrlyConList.own");
	if (ix == PREBRLYCONLIST_STA) return("PreBrlyConList.sta");
	if (ix == PREBRLYCONMNFLIGHT_X1) return("PreBrlyConMNFlight.x1");
	if (ix == PREBRLYCONMNFLIGHT_X2) return("PreBrlyConMNFlight.x2");
	if (ix == PREBRLYCONMNSEGMENT_X1) return("PreBrlyConMNSegment.x1");
	if (ix == PREBRLYCONMNSEGMENT_X2) return("PreBrlyConMNSegment.x2");
	if (ix == PREBRLYFILLIST_FNM) return("PreBrlyFilList.fnm");
	if (ix == PREBRLYFILLIST_GRP) return("PreBrlyFilList.grp");
	if (ix == PREBRLYFILLIST_OWN) return("PreBrlyFilList.own");
	if (ix == PREBRLYFILLIST_RET) return("PreBrlyFilList.ret");
	if (ix == PREBRLYFILLIST_REU) return("PreBrlyFilList.reu");
	if (ix == PREBRLYFLTDSTMNFLIGHT_X1) return("PreBrlyFltDstMNFlight.x1");
	if (ix == PREBRLYFLTLIST_EQP) return("PreBrlyFltList.eqp");
	if (ix == PREBRLYFLTLIST_LEG) return("PreBrlyFltList.leg");
	if (ix == PREBRLYFLTLIST_SRF) return("PreBrlyFltList.srf");
	if (ix == PREBRLYFLTLIST_STA) return("PreBrlyFltList.sta");
	if (ix == PREBRLYFLTLIST_STO) return("PreBrlyFltList.sto");
	if (ix == PREBRLYFLTMNCONNECTION_X1) return("PreBrlyFltMNConnection.x1");
	if (ix == PREBRLYFLTMNCONNECTION_X2) return("PreBrlyFltMNConnection.x2");
	if (ix == PREBRLYFLTMNLOCATION_X1) return("PreBrlyFltMNLocation.x1");
	if (ix == PREBRLYFLTORGMNFLIGHT_X1) return("PreBrlyFltOrgMNFlight.x1");
	if (ix == PREBRLYGROUP) return("PreBrlyGroup");
	if (ix == PREBRLYIP) return("PreBrlyIp");
	if (ix == PREBRLYIXCRDACCCON) return("PreBrlyIxCrdaccCon");
	if (ix == PREBRLYIXCRDACCFIL) return("PreBrlyIxCrdaccFil");
	if (ix == PREBRLYIXCRDACCFLT) return("PreBrlyIxCrdaccFlt");
	if (ix == PREBRLYIXCRDACCLEG) return("PreBrlyIxCrdaccLeg");
	if (ix == PREBRLYIXCRDACCLOC) return("PreBrlyIxCrdaccLoc");
	if (ix == PREBRLYIXCRDACCOPR) return("PreBrlyIxCrdaccOpr");
	if (ix == PREBRLYIXCRDACCPRS) return("PreBrlyIxCrdaccPrs");
	if (ix == PREBRLYIXCRDACCPTY) return("PreBrlyIxCrdaccPty");
	if (ix == PREBRLYIXCRDACCREG) return("PreBrlyIxCrdaccReg");
	if (ix == PREBRLYIXCRDACCRLY) return("PreBrlyIxCrdaccRly");
	if (ix == PREBRLYIXCRDACCSEG) return("PreBrlyIxCrdaccSeg");
	if (ix == PREBRLYIXCRDACCTTB) return("PreBrlyIxCrdaccTtb");
	if (ix == PREBRLYIXCRDACCUSG) return("PreBrlyIxCrdaccUsg");
	if (ix == PREBRLYIXCRDACCUSR) return("PreBrlyIxCrdaccUsr");
	if (ix == PREBRLYIXLCL) return("PreBrlyIxLcl");
	if (ix == PREBRLYIXORD) return("PreBrlyIxOrd");
	if (ix == PREBRLYIXPRE) return("PreBrlyIxPre");
	if (ix == PREBRLYIXRECACC) return("PreBrlyIxRecacc");
	if (ix == PREBRLYJREFNOTIFY) return("PreBrlyJrefNotify");
	if (ix == PREBRLYJREFSESS) return("PreBrlyJrefSess");
	if (ix == PREBRLYLEGDSTMNLEG_X1) return("PreBrlyLegDstMNLeg.x1");
	if (ix == PREBRLYLEGLIST_BLO) return("PreBrlyLegList.blo");
	if (ix == PREBRLYLEGLIST_ELO) return("PreBrlyLegList.elo");
	if (ix == PREBRLYLEGLIST_GRP) return("PreBrlyLegList.grp");
	if (ix == PREBRLYLEGLIST_OWN) return("PreBrlyLegList.own");
	if (ix == PREBRLYLEGLIST_TYP) return("PreBrlyLegList.typ");
	if (ix == PREBRLYLEGMNLOCATION_X1) return("PreBrlyLegMNLocation.x1");
	if (ix == PREBRLYLEGORGMNLEG_X1) return("PreBrlyLegOrgMNLeg.x1");
	if (ix == PREBRLYLOCLIST_EQP) return("PreBrlyLocList.eqp");
	if (ix == PREBRLYLOCLIST_ICA) return("PreBrlyLocList.ica");
	if (ix == PREBRLYLOCLIST_REG) return("PreBrlyLocList.reg");
	if (ix == PREBRLYLOCLIST_SRF) return("PreBrlyLocList.srf");
	if (ix == PREBRLYLOCLIST_TIT) return("PreBrlyLocList.tit");
	if (ix == PREBRLYLOCLIST_TYP) return("PreBrlyLocList.typ");
	if (ix == PREBRLYLOCMNFLIGHT_X1) return("PreBrlyLocMNFlight.x1");
	if (ix == PREBRLYLOCMNLEG_X1) return("PreBrlyLocMNLeg.x1");
	if (ix == PREBRLYLOCMNSEGMENT_X1) return("PreBrlyLocMNSegment.x1");
	if (ix == PREBRLYLOCMNSEGMENT_X2) return("PreBrlyLocMNSegment.x2");
	if (ix == PREBRLYNOADM) return("PreBrlyNoadm");
	if (ix == PREBRLYOPRLIST_ICA) return("PreBrlyOprList.ica");
	if (ix == PREBRLYOPRLIST_SRF) return("PreBrlyOprList.srf");
	if (ix == PREBRLYOPRLIST_TIT) return("PreBrlyOprList.tit");
	if (ix == PREBRLYOWNER) return("PreBrlyOwner");
	if (ix == PREBRLYPHI) return("PreBrlyPhi");
	if (ix == PREBRLYPRSADETAIL_X1) return("PreBrlyPrsADetail.x1");
	if (ix == PREBRLYPRSLIST_GRP) return("PreBrlyPrsList.grp");
	if (ix == PREBRLYPRSLIST_LNM) return("PreBrlyPrsList.lnm");
	if (ix == PREBRLYPRSLIST_OWN) return("PreBrlyPrsList.own");
	if (ix == PREBRLYPTYLIST_SRF) return("PreBrlyPtyList.srf");
	if (ix == PREBRLYPTYLIST_TIT) return("PreBrlyPtyList.tit");
	if (ix == PREBRLYREFAPT) return("PreBrlyRefApt");
	if (ix == PREBRLYREFCON) return("PreBrlyRefCon");
	if (ix == PREBRLYREFCOR) return("PreBrlyRefCor");
	if (ix == PREBRLYREFEQP) return("PreBrlyRefEqp");
	if (ix == PREBRLYREFFAF) return("PreBrlyRefFaf");
	if (ix == PREBRLYREFFIL) return("PreBrlyRefFil");
	if (ix == PREBRLYREFFLT) return("PreBrlyRefFlt");
	if (ix == PREBRLYREFLEG) return("PreBrlyRefLeg");
	if (ix == PREBRLYREFLOC) return("PreBrlyRefLoc");
	if (ix == PREBRLYREFNDE) return("PreBrlyRefNde");
	if (ix == PREBRLYREFOPR) return("PreBrlyRefOpr");
	if (ix == PREBRLYREFPLN) return("PreBrlyRefPln");
	if (ix == PREBRLYREFPRS) return("PreBrlyRefPrs");
	if (ix == PREBRLYREFPTY) return("PreBrlyRefPty");
	if (ix == PREBRLYREFREG) return("PreBrlyRefReg");
	if (ix == PREBRLYREFRIP) return("PreBrlyRefRip");
	if (ix == PREBRLYREFRLY) return("PreBrlyRefRly");
	if (ix == PREBRLYREFRTE) return("PreBrlyRefRte");
	if (ix == PREBRLYREFSEG) return("PreBrlyRefSeg");
	if (ix == PREBRLYREFSEL) return("PreBrlyRefSel");
	if (ix == PREBRLYREFSES) return("PreBrlyRefSes");
	if (ix == PREBRLYREFTTB) return("PreBrlyRefTtb");
	if (ix == PREBRLYREFUSG) return("PreBrlyRefUsg");
	if (ix == PREBRLYREFUSR) return("PreBrlyRefUsr");
	if (ix == PREBRLYREGLIST_SRF) return("PreBrlyRegList.srf");
	if (ix == PREBRLYREGLIST_SUP) return("PreBrlyRegList.sup");
	if (ix == PREBRLYREGLIST_TIT) return("PreBrlyRegList.tit");
	if (ix == PREBRLYRLYLIST_CON) return("PreBrlyRlyList.con");
	if (ix == PREBRLYRLYLIST_DIR) return("PreBrlyRlyList.dir");
	if (ix == PREBRLYRLYLIST_STA) return("PreBrlyRlyList.sta");
	if (ix == PREBRLYRLYLIST_STO) return("PreBrlyRlyList.sto");
	if (ix == PREBRLYSEGDSTMNSEGMENT_X1) return("PreBrlySegDstMNSegment.x1");
	if (ix == PREBRLYSEGDSTMNSEGMENT_X2) return("PreBrlySegDstMNSegment.x2");
	if (ix == PREBRLYSEGLIST_RET) return("PreBrlySegList.ret");
	if (ix == PREBRLYSEGLIST_REU) return("PreBrlySegList.reu");
	if (ix == PREBRLYSEGLIST_STA) return("PreBrlySegList.sta");
	if (ix == PREBRLYSEGLIST_STO) return("PreBrlySegList.sto");
	if (ix == PREBRLYSEGMNCONNECTION_X1) return("PreBrlySegMNConnection.x1");
	if (ix == PREBRLYSEGMNCONNECTION_X2) return("PreBrlySegMNConnection.x2");
	if (ix == PREBRLYSEGMNLOCATION_X1) return("PreBrlySegMNLocation.x1");
	if (ix == PREBRLYSEGMNLOCATION_X2) return("PreBrlySegMNLocation.x2");
	if (ix == PREBRLYSEGORGMNSEGMENT_X1) return("PreBrlySegOrgMNSegment.x1");
	if (ix == PREBRLYSEGORGMNSEGMENT_X2) return("PreBrlySegOrgMNSegment.x2");
	if (ix == PREBRLYSESS) return("PreBrlySess");
	if (ix == PREBRLYSUSPSESS) return("PreBrlySuspsess");
	if (ix == PREBRLYSYSDATE) return("PreBrlySysdate");
	if (ix == PREBRLYSYSSTAMP) return("PreBrlySysstamp");
	if (ix == PREBRLYSYSTIME) return("PreBrlySystime");
	if (ix == PREBRLYTIME) return("PreBrlyTime");
	if (ix == PREBRLYTLAST) return("PreBrlyTlast");
	if (ix == PREBRLYTTBLIST_FIL) return("PreBrlyTtbList.fil");
	if (ix == PREBRLYTTBLIST_TIT) return("PreBrlyTtbList.tit");
	if (ix == PREBRLYUSGAACCESS_X1) return("PreBrlyUsgAAccess.x1");
	if (ix == PREBRLYUSGAACCESS_X2) return("PreBrlyUsgAAccess.x2");
	if (ix == PREBRLYUSGLIST_GRP) return("PreBrlyUsgList.grp");
	if (ix == PREBRLYUSGLIST_OWN) return("PreBrlyUsgList.own");
	if (ix == PREBRLYUSGLIST_SRF) return("PreBrlyUsgList.srf");
	if (ix == PREBRLYUSRAACCESS_X1) return("PreBrlyUsrAAccess.x1");
	if (ix == PREBRLYUSRAACCESS_X2) return("PreBrlyUsrAAccess.x2");
	if (ix == PREBRLYUSRLIST_GRP) return("PreBrlyUsrList.grp");
	if (ix == PREBRLYUSRLIST_OWN) return("PreBrlyUsrList.own");
	if (ix == PREBRLYUSRLIST_PRS) return("PreBrlyUsrList.prs");
	if (ix == PREBRLYUSRLIST_SRF) return("PreBrlyUsrList.srf");
	if (ix == PREBRLYUSRLIST_STE) return("PreBrlyUsrList.ste");
	if (ix == PREBRLYUSRLIST_USG) return("PreBrlyUsrList.usg");

	return("");
};

string DbsBrly::VecVPreset::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == PREBRLYPHI) return("angular position [\\u00b0]");
		if (ix == PREBRLYREFAPT) return("airport");
		if (ix == PREBRLYREFCON) return("connection");
		if (ix == PREBRLYREFCOR) return("corridor");
		if (ix == PREBRLYREFEQP) return("equipment");
		if (ix == PREBRLYREFFAF) return("FlightAware flight");
		if (ix == PREBRLYREFFIL) return("file");
		if (ix == PREBRLYREFFLT) return("flight");
		if (ix == PREBRLYREFLEG) return("leg");
		if (ix == PREBRLYREFLOC) return("location");
		if (ix == PREBRLYREFNDE) return("node");
		if (ix == PREBRLYREFOPR) return("operator");
		if (ix == PREBRLYREFPLN) return("plane");
		if (ix == PREBRLYREFPRS) return("person");
		if (ix == PREBRLYREFPTY) return("plane type");
		if (ix == PREBRLYREFREG) return("region");
		if (ix == PREBRLYREFRIP) return("impartible region");
		if (ix == PREBRLYREFRLY) return("relay");
		if (ix == PREBRLYREFRTE) return("route");
		if (ix == PREBRLYREFSEG) return("segment");
		if (ix == PREBRLYREFSES) return("session");
		if (ix == PREBRLYREFTTB) return("timetable");
		if (ix == PREBRLYREFUSG) return("user group");
		if (ix == PREBRLYREFUSR) return("user");
		if (ix == PREBRLYTIME) return("time");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == VOID) return("kein");
		if (ix == PREBRLYPHI) return("Winkelposition [\\u00b0]");
		if (ix == PREBRLYREFAPT) return("Flughafen");
		if (ix == PREBRLYREFCON) return("Verbindung");
		if (ix == PREBRLYREFCOR) return("Korridor");
		if (ix == PREBRLYREFEQP) return("Ger\\u00e4t");
		if (ix == PREBRLYREFFAF) return("FlightAware Flug");
		if (ix == PREBRLYREFFIL) return("Datei");
		if (ix == PREBRLYREFFLT) return("Flug");
		if (ix == PREBRLYREFLEG) return("Strecke");
		if (ix == PREBRLYREFLOC) return("Ort");
		if (ix == PREBRLYREFNDE) return("Knotenpunkt");
		if (ix == PREBRLYREFOPR) return("Betreiber");
		if (ix == PREBRLYREFPLN) return("Flugzeug");
		if (ix == PREBRLYREFPRS) return("Person");
		if (ix == PREBRLYREFPTY) return("Flugzeugtyp");
		if (ix == PREBRLYREFREG) return("Region");
		if (ix == PREBRLYREFRIP) return("unteilbare Region");
		if (ix == PREBRLYREFRLY) return("Verbindungskette");
		if (ix == PREBRLYREFRTE) return("Route");
		if (ix == PREBRLYREFSEG) return("Segment");
		if (ix == PREBRLYREFSES) return("Siztung");
		if (ix == PREBRLYREFTTB) return("Flugplan");
		if (ix == PREBRLYREFUSG) return("Benutzergruppe");
		if (ix == PREBRLYREFUSR) return("Benutzer");
		if (ix == PREBRLYTIME) return("Zeit");
		return(getTitle(ix, 1));
	};

	return("");
};

/******************************************************************************
 class DbsBrly::VecVRecaccess
 ******************************************************************************/

uint DbsBrly::VecVRecaccess::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "full") return FULL;
	if (s == "none") return NONE;
	if (s == "view") return VIEW;

	return(0);
};

string DbsBrly::VecVRecaccess::getSref(
			const uint ix
		) {
	if (ix == FULL) return("full");
	if (ix == NONE) return("none");
	if (ix == VIEW) return("view");

	return("");
};

string DbsBrly::VecVRecaccess::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == FULL) return("full");
		if (ix == NONE) return("none");
		if (ix == VIEW) return("view");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == FULL) return("voll");
		if (ix == NONE) return("kein");
		if (ix == VIEW) return("anschauen");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsBrly::VecVRecaccess::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVUserlevel
 ******************************************************************************/

uint DbsBrly::VecVUserlevel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "adm") return ADM;
	if (s == "gadm") return GADM;
	if (s == "reg") return REG;
	if (s == "vtor") return VTOR;

	return(0);
};

string DbsBrly::VecVUserlevel::getSref(
			const uint ix
		) {
	if (ix == ADM) return("adm");
	if (ix == GADM) return("gadm");
	if (ix == REG) return("reg");
	if (ix == VTOR) return("vtor");

	return("");
};

string DbsBrly::VecVUserlevel::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == ADM) return("administrator");
		if (ix == GADM) return("user group administrator");
		if (ix == REG) return("regular user");
		if (ix == VTOR) return("visitor");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == ADM) return("Administrator");
		if (ix == GADM) return("Gruppenadministrator");
		if (ix == REG) return("regul\\u00e4rer Benutzer");
		if (ix == VTOR) return("Besucher");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsBrly::VecVUserlevel::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVValuelist
 ******************************************************************************/

uint DbsBrly::VecVValuelist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vlstbrlyumpersontitle") return VLSTBRLYUMPERSONTITLE;

	return(0);
};

string DbsBrly::VecVValuelist::getSref(
			const uint ix
		) {
	if (ix == VLSTBRLYUMPERSONTITLE) return("VlstBrlyUMPersonTitle");

	return("");
};

string DbsBrly::VecVValuelist::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == VLSTBRLYUMPERSONTITLE) return("title");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == VLSTBRLYUMPERSONTITLE) return("Anrede");
		return(getTitle(ix, 1));
	};

	return("");
};

/******************************************************************************
 class DbsBrly::VecWAccess
 ******************************************************************************/

uint DbsBrly::VecWAccess::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "edit") ix |= EDIT;
		else if (ss[i] == "exec") ix |= EXEC;
		else if (ss[i] == "view") ix |= VIEW;
	};

	return(ix);
};

void DbsBrly::VecWAccess::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VIEW); i *= 2) if (ix & i) ics.insert(i);
};

string DbsBrly::VecWAccess::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & EDIT) ss.push_back("edit");
	if (ix & EXEC) ss.push_back("exec");
	if (ix & VIEW) ss.push_back("view");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string DbsBrly::VecWAccess::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == EDIT) return("edit");
		if (ix == EXEC) return("execute");
		if (ix == VIEW) return("view");
		return(getSrefs(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == EDIT) return("\\u00e4ndern");
		if (ix == EXEC) return("ausf\\u00fchren");
		if (ix == VIEW) return("anschauen");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsBrly::VecWAccess::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= VIEW; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixBrlyVLocale));
};
