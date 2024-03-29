/**
	* \file VecBrlyVTag.cpp
	* vector VecBrlyVTag (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#include "VecBrlyVTag.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecBrlyVTag
 ******************************************************************************/

uint VecBrlyVTag::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "about") return ABOUT;
	if (s == "always") return ALWAYS;
	if (s == "announce") return ANNOUNCE;
	if (s == "cancel") return CANCEL;
	if (s == "close") return CLOSE;
	if (s == "clsess") return CLSESS;
	if (s == "clust") return CLUST;
	if (s == "create") return CREATE;
	if (s == "detail") return DETAIL;
	if (s == "done") return DONE;
	if (s == "download") return DOWNLOAD;
	if (s == "emplong") return EMPLONG;
	if (s == "empshort") return EMPSHORT;
	if (s == "error") return ERROR;
	if (s == "filename") return FILENAME;
	if (s == "fls") return FLS;
	if (s == "general") return GENERAL;
	if (s == "goto") return GOTO;
	if (s == "grp") return GRP;
	if (s == "help") return HELP;
	if (s == "hour") return HOUR;
	if (s == "hours") return HOURS;
	if (s == "imperr") return IMPERR;
	if (s == "import") return IMPORT;
	if (s == "loaini") return LOAINI;
	if (s == "minute") return MINUTE;
	if (s == "minutes") return MINUTES;
	if (s == "nav") return NAV;
	if (s == "new") return NEW;
	if (s == "no") return NO;
	if (s == "ok") return OK;
	if (s == "opscpllast") return OPSCPLLAST;
	if (s == "opsprep") return OPSPREP;
	if (s == "own") return OWN;
	if (s == "progress") return PROGRESS;
	if (s == "prserr") return PRSERR;
	if (s == "quest") return QUEST;
	if (s == "rec") return REC;
	if (s == "reverse") return REVERSE;
	if (s == "run") return RUN;
	if (s == "second") return SECOND;
	if (s == "seconds") return SECONDS;
	if (s == "sess") return SESS;
	if (s == "showlong") return SHOWLONG;
	if (s == "showshort") return SHOWSHORT;
	if (s == "stop") return STOP;
	if (s == "suspsess") return SUSPSESS;
	if (s == "tru") return TRU;
	if (s == "upload") return UPLOAD;
	if (s == "yes") return YES;

	return(0);
};

string VecBrlyVTag::getSref(
			const uint ix
		) {
	if (ix == ABOUT) return("about");
	if (ix == ALWAYS) return("always");
	if (ix == ANNOUNCE) return("announce");
	if (ix == CANCEL) return("cancel");
	if (ix == CLOSE) return("close");
	if (ix == CLSESS) return("clsess");
	if (ix == CLUST) return("clust");
	if (ix == CREATE) return("create");
	if (ix == DETAIL) return("detail");
	if (ix == DONE) return("done");
	if (ix == DOWNLOAD) return("download");
	if (ix == EMPLONG) return("emplong");
	if (ix == EMPSHORT) return("empshort");
	if (ix == ERROR) return("error");
	if (ix == FILENAME) return("filename");
	if (ix == FLS) return("fls");
	if (ix == GENERAL) return("general");
	if (ix == GOTO) return("goto");
	if (ix == GRP) return("grp");
	if (ix == HELP) return("help");
	if (ix == HOUR) return("hour");
	if (ix == HOURS) return("hours");
	if (ix == IMPERR) return("imperr");
	if (ix == IMPORT) return("import");
	if (ix == LOAINI) return("loaini");
	if (ix == MINUTE) return("minute");
	if (ix == MINUTES) return("minutes");
	if (ix == NAV) return("nav");
	if (ix == NEW) return("new");
	if (ix == NO) return("no");
	if (ix == OK) return("ok");
	if (ix == OPSCPLLAST) return("opscpllast");
	if (ix == OPSPREP) return("opsprep");
	if (ix == OWN) return("own");
	if (ix == PROGRESS) return("progress");
	if (ix == PRSERR) return("prserr");
	if (ix == QUEST) return("quest");
	if (ix == REC) return("rec");
	if (ix == REVERSE) return("reverse");
	if (ix == RUN) return("run");
	if (ix == SECOND) return("second");
	if (ix == SECONDS) return("seconds");
	if (ix == SESS) return("sess");
	if (ix == SHOWLONG) return("showlong");
	if (ix == SHOWSHORT) return("showshort");
	if (ix == STOP) return("stop");
	if (ix == SUSPSESS) return("suspsess");
	if (ix == TRU) return("tru");
	if (ix == UPLOAD) return("upload");
	if (ix == YES) return("yes");

	return("");
};

string VecBrlyVTag::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == ABOUT) return("About BeamRelay");
		if (ix == ALWAYS) return("always");
		if (ix == ANNOUNCE) return("announcement");
		if (ix == CANCEL) return("cancel");
		if (ix == CLOSE) return("close");
		if (ix == CLSESS) return("close session");
		if (ix == CLUST) return("clustered with");
		if (ix == CREATE) return("create");
		if (ix == DETAIL) return("details");
		if (ix == DONE) return("done");
		if (ix == DOWNLOAD) return("download");
		if (ix == EMPLONG) return("no entries");
		if (ix == EMPSHORT) return("empty");
		if (ix == ERROR) return("error");
		if (ix == FILENAME) return("file name");
		if (ix == FLS) return("No");
		if (ix == GENERAL) return("generally");
		if (ix == GOTO) return("go to");
		if (ix == GRP) return("group");
		if (ix == HELP) return("BeamRelay help");
		if (ix == HOUR) return("hour");
		if (ix == HOURS) return("hours");
		if (ix == IMPERR) return("import error");
		if (ix == IMPORT) return("import");
		if (ix == LOAINI) return("load initialization data");
		if (ix == MINUTE) return("minute");
		if (ix == MINUTES) return("minutes");
		if (ix == NAV) return("navigation");
		if (ix == NEW) return("new");
		if (ix == NO) return("no");
		if (ix == OK) return("OK");
		if (ix == OPSCPLLAST) return("operations completed, last");
		if (ix == OPSPREP) return("operations prepared");
		if (ix == OWN) return("owner");
		if (ix == PROGRESS) return("progress");
		if (ix == PRSERR) return("parse error");
		if (ix == QUEST) return("question");
		if (ix == REC) return("records &firstload; to &lastload; of &ntot;");
		if (ix == REVERSE) return("reverse");
		if (ix == RUN) return("execute");
		if (ix == SECOND) return("second");
		if (ix == SECONDS) return("seconds");
		if (ix == SESS) return("session");
		if (ix == SHOWLONG) return("showing &firstdisp; to &lastdisp; of &ntot;");
		if (ix == SHOWSHORT) return("&firstdisp;-&lastdisp; of &ntot;");
		if (ix == SUSPSESS) return("suspend session");
		if (ix == TRU) return("Yes");
		if (ix == UPLOAD) return("upload");
		if (ix == YES) return("yes");
		return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == ABOUT) return("\\u00dcber BeamRelay");
		if (ix == ALWAYS) return("immer");
		if (ix == ANNOUNCE) return("Ank\\u00fcndigung");
		if (ix == CANCEL) return("abbrechen");
		if (ix == CLOSE) return("Schliessen");
		if (ix == CLSESS) return("Sitzung beenden");
		if (ix == CLUST) return("geb\\u00fcndelt mit");
		if (ix == CREATE) return("erstellen");
		if (ix == DETAIL) return("Details");
		if (ix == DONE) return("fertig");
		if (ix == DOWNLOAD) return("herunterladen");
		if (ix == EMPLONG) return("keine Eintr\\u00e4ge");
		if (ix == EMPSHORT) return("leer");
		if (ix == ERROR) return("Fehler");
		if (ix == FILENAME) return("Dateiname");
		if (ix == FLS) return("Nein");
		if (ix == GENERAL) return("allgemein");
		if (ix == GOTO) return("gehe zu");
		if (ix == GRP) return("Gruppe");
		if (ix == HELP) return("BeamRelay Hilfe");
		if (ix == HOUR) return("Stunde");
		if (ix == HOURS) return("Stunden");
		if (ix == IMPERR) return("Fehler beim Importieren");
		if (ix == IMPORT) return("importieren");
		if (ix == LOAINI) return("Initialisierungsdaten laden");
		if (ix == MINUTE) return("Minute");
		if (ix == MINUTES) return("Minuten");
		if (ix == NAV) return("Navigation");
		if (ix == NEW) return("neu");
		if (ix == NO) return("nein");
		if (ix == OK) return("OK");
		if (ix == OPSCPLLAST) return("Operationen ausgef\\u00fchrt, letzte");
		if (ix == OPSPREP) return("Operationen vorbereitet");
		if (ix == OWN) return("Eigent\\u00fcmer");
		if (ix == PROGRESS) return("Fortschritt");
		if (ix == PRSERR) return("Fehler beim Parsen");
		if (ix == QUEST) return("Frage");
		if (ix == REC) return("Datens\\u00e4tze &firstload; bis &lastload; von &ntot;");
		if (ix == REVERSE) return("umkehren");
		if (ix == RUN) return("ausf\\u00fchren");
		if (ix == SECOND) return("Sekunde");
		if (ix == SECONDS) return("Sekunden");
		if (ix == SESS) return("Sitzung");
		if (ix == SHOWLONG) return("zeige &firstdisp; bis &lastdisp; von &ntot;");
		if (ix == SHOWSHORT) return("&firstdisp;-&lastdisp; von &ntot;");
		if (ix == SUSPSESS) return("Sitzung unterbrechen");
		if (ix == TRU) return("Ja");
		if (ix == UPLOAD) return("hochladen");
		if (ix == YES) return("ja");
		return(getTitle(ix, 1));
	};

	return("");
};

void VecBrlyVTag::appendToFeed(
			const uint ix
			, const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixBrlyVLocale));
};
