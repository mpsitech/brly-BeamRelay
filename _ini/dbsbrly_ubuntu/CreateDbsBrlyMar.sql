-- file CreateDbsBrlyMy.sql
-- MySQL / MariaDB database create script
-- copyright: (C) 2016-2020 MPSI Technologies GmbH
-- author: Alexander Wirthmueller (auto-generation)
-- date created: 11 Sep 2022
-- IP header --- ABOVE

DROP DATABASE IF EXISTS DbsBrly;
CREATE DATABASE DbsBrly;
USE DbsBrly;

CREATE USER IF NOT EXISTS 'default'@'%' IDENTIFIED BY 'asdf1234';
GRANT ALL PRIVILEGES ON DbsBrly.* TO 'default'@'%';

CREATE USER IF NOT EXISTS 'default'@'localhost' IDENTIFIED BY 'asdf1234';
GRANT ALL PRIVILEGES ON DbsBrly.* TO 'default'@'localhost';

CREATE TABLE TblBrlyAccRMUserUniversal(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMUser BIGINT UNSIGNED,
	unvIxBrlyVMaintable INT UNSIGNED,
	unvUref BIGINT UNSIGNED,
	ixBrlyVRecaccess INT UNSIGNED,
	INDEX (refBrlyMUser),
	INDEX (unvIxBrlyVMaintable),
	INDEX (unvUref)
) ENGINE = ARIA;

CREATE TABLE TblBrlyAMFaflightWaypoint(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	fafRefBrlyMFaflight BIGINT UNSIGNED,
	fafNum INT UNSIGNED,
	timestamp INT UNSIGNED,
	latitude DOUBLE,
	longitude DOUBLE,
	groundspeed SMALLINT UNSIGNED,
	altitude SMALLINT UNSIGNED,
	altitudeStatus VARCHAR(5),
	updateType VARCHAR(5),
	altitudeChange VARCHAR(5),
	INDEX (fafRefBrlyMFaflight),
	INDEX (fafNum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyAMPersonDetail(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMPerson BIGINT UNSIGNED,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192),
	INDEX (refBrlyMPerson)
) ENGINE = ARIA;

CREATE TABLE TblBrlyAMRegionDstswitch(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMRegion BIGINT UNSIGNED,
	startd INT UNSIGNED,
	startt INT UNSIGNED,
	INDEX (refBrlyMRegion),
	INDEX (startd)
) ENGINE = ARIA;

CREATE TABLE TblBrlyAMUserAccess(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMUser BIGINT UNSIGNED,
	x1IxBrlyVFeatgroup INT UNSIGNED,
	x2FeaSrefUix VARCHAR(50),
	ixBrlyWAccess INT UNSIGNED,
	INDEX (refBrlyMUser),
	INDEX (x1IxBrlyVFeatgroup),
	INDEX (x2FeaSrefUix)
) ENGINE = ARIA;

CREATE TABLE TblBrlyAMUsergroupAccess(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMUsergroup BIGINT UNSIGNED,
	x1IxBrlyVFeatgroup INT UNSIGNED,
	x2FeaSrefUix VARCHAR(50),
	ixBrlyWAccess INT UNSIGNED,
	INDEX (refBrlyMUsergroup),
	INDEX (x1IxBrlyVFeatgroup),
	INDEX (x2FeaSrefUix)
) ENGINE = ARIA;

CREATE TABLE TblBrlyAVControlPar(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	ixBrlyVControl INT UNSIGNED,
	x1RefBrlyMUser BIGINT UNSIGNED,
	x2IxBrlyVLocale INT UNSIGNED,
	Par VARCHAR(192),
	Val VARCHAR(192),
	INDEX (ixBrlyVControl),
	INDEX (x1RefBrlyMUser),
	INDEX (x2IxBrlyVLocale),
	INDEX (Par)
) ENGINE = ARIA;

CREATE TABLE TblBrlyAVKeylistKey(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	klsIxBrlyVKeylist INT UNSIGNED,
	klsNum INT UNSIGNED,
	x1IxBrlyVMaintable INT UNSIGNED,
	x1Uref BIGINT UNSIGNED,
	Fixed TINYINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT UNSIGNED,
	Title VARCHAR(192),
	Comment TEXT,
	INDEX (klsIxBrlyVKeylist),
	INDEX (klsNum),
	INDEX (x1IxBrlyVMaintable),
	INDEX (x1Uref),
	INDEX (sref)
) ENGINE = ARIA;

CREATE TABLE TblBrlyAVValuelistVal(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	vlsIxBrlyVValuelist INT UNSIGNED,
	vlsNum INT UNSIGNED,
	x1IxBrlyVLocale INT UNSIGNED,
	Val VARCHAR(192),
	INDEX (vlsIxBrlyVValuelist),
	INDEX (vlsNum),
	INDEX (x1IxBrlyVLocale)
) ENGINE = ARIA;

CREATE TABLE TblBrlyCFile(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY
) ENGINE = ARIA;

CREATE TABLE TblBrlyCLeg(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY
) ENGINE = ARIA;

CREATE TABLE TblBrlyHistRMUserUniversal(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMUser BIGINT UNSIGNED,
	unvIxBrlyVMaintable INT UNSIGNED,
	unvUref BIGINT UNSIGNED,
	ixBrlyVCard INT UNSIGNED,
	ixBrlyVPreset INT UNSIGNED,
	preIxBrlyVMaintable INT UNSIGNED,
	preUref BIGINT UNSIGNED,
	start INT UNSIGNED,
	INDEX (refBrlyMUser),
	INDEX (unvIxBrlyVMaintable),
	INDEX (unvUref),
	INDEX (ixBrlyVCard),
	INDEX (ixBrlyVPreset),
	INDEX (preIxBrlyVMaintable),
	INDEX (preUref)
) ENGINE = ARIA;

CREATE TABLE TblBrlyJAVKeylistKey(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyAVKeylistKey BIGINT UNSIGNED,
	x1IxBrlyVLocale INT UNSIGNED,
	Title VARCHAR(192),
	Comment TEXT,
	INDEX (refBrlyAVKeylistKey),
	INDEX (x1IxBrlyVLocale)
) ENGINE = ARIA;

CREATE TABLE TblBrlyJMPersonLastname(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMPerson BIGINT UNSIGNED,
	x1Startd INT UNSIGNED,
	Lastname VARCHAR(50),
	INDEX (refBrlyMPerson),
	INDEX (x1Startd),
	INDEX (Lastname)
) ENGINE = ARIA;

CREATE TABLE TblBrlyJMRegion(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMRegion BIGINT UNSIGNED,
	x1Startd INT UNSIGNED,
	x1Stopd INT UNSIGNED,
	ixVDst INT UNSIGNED,
	toffset DOUBLE,
	INDEX (refBrlyMRegion),
	INDEX (x1Startd),
	INDEX (x1Stopd)
) ENGINE = ARIA;

CREATE TABLE TblBrlyJMRegionTitle(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMRegion BIGINT UNSIGNED,
	x1IxBrlyVLocale INT UNSIGNED,
	Title VARCHAR(50),
	INDEX (refBrlyMRegion),
	INDEX (x1IxBrlyVLocale),
	INDEX (Title)
) ENGINE = ARIA;

CREATE TABLE TblBrlyJMUserState(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMUser BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	ixVState INT UNSIGNED,
	INDEX (refBrlyMUser),
	INDEX (x1Start)
) ENGINE = ARIA;

CREATE TABLE TblBrlyLRMConnectionMEquipment(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	conIxBrlyVLat INT UNSIGNED,
	conRefBrlyMConnection BIGINT UNSIGNED,
	conNum INT UNSIGNED,
	refBrlyMEquipment BIGINT UNSIGNED,
	INDEX (conIxBrlyVLat),
	INDEX (conRefBrlyMConnection),
	INDEX (conNum),
	INDEX (refBrlyMEquipment)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMConnection(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	refBrlyMFlight BIGINT UNSIGNED,
	corRefBrlyMLeg BIGINT UNSIGNED,
	start INT UNSIGNED,
	stop INT UNSIGNED,
	ixVModel INT UNSIGNED,
	refBrlyMTimetable BIGINT UNSIGNED,
	srefsBrlyKEqptype VARCHAR(192),
	INDEX (grp),
	INDEX (own),
	INDEX (refBrlyMFlight),
	INDEX (corRefBrlyMLeg),
	INDEX (start)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMEquipment(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	hkIxVTbl INT UNSIGNED,
	hkUref BIGINT UNSIGNED,
	refBrlyMOperator BIGINT UNSIGNED,
	refBrlyMPlntype BIGINT UNSIGNED,
	srefBrlyKEqptype VARCHAR(50),
	Fiber TINYINT,
	INDEX (hkIxVTbl),
	INDEX (hkUref),
	INDEX (refBrlyMOperator),
	INDEX (refBrlyMPlntype)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMFaflight(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMFlight BIGINT UNSIGNED,
	faFlightID VARCHAR(50),
	ident VARCHAR(10),
	aircrafttype VARCHAR(5),
	filed_ete VARCHAR(10),
	filed_time INT UNSIGNED,
	filed_departuretime INT UNSIGNED,
	filed_airspeed_kts SMALLINT UNSIGNED,
	filed_airspeed_mach DOUBLE,
	filed_altitude SMALLINT UNSIGNED,
	route TEXT,
	actualdeparturetime INT UNSIGNED,
	estimatedarrivaltime INT UNSIGNED,
	actualarrivaltime INT UNSIGNED,
	diverted VARCHAR(5),
	origin VARCHAR(5),
	destination VARCHAR(5),
	originName VARCHAR(50),
	originCity VARCHAR(50),
	destinationName VARCHAR(50),
	destinationCity VARCHAR(50),
	INDEX (refBrlyMFlight),
	INDEX (faFlightID),
	INDEX (ident),
	INDEX (filed_departuretime)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMFile(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	refBrlyCFile BIGINT UNSIGNED,
	refIxVTbl INT UNSIGNED,
	refUref BIGINT UNSIGNED,
	osrefKContent VARCHAR(50),
	Archived INT UNSIGNED,
	Filename VARCHAR(50),
	Archivename VARCHAR(30),
	srefKMimetype VARCHAR(50),
	Size SMALLINT UNSIGNED,
	Comment TEXT,
	INDEX (grp),
	INDEX (own),
	INDEX (refBrlyCFile),
	INDEX (refIxVTbl),
	INDEX (refUref),
	INDEX (Filename)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMFlight(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMTimetable BIGINT UNSIGNED,
	refBrlyMEquipment BIGINT UNSIGNED,
	refBrlyMFaflight BIGINT UNSIGNED,
	refBrlyMLeg BIGINT UNSIGNED,
	sref VARCHAR(50),
	start INT UNSIGNED,
	stop INT UNSIGNED,
	xStart INT UNSIGNED,
	xStop INT UNSIGNED,
	Calcdone TINYINT,
	Segdone TINYINT,
	INDEX (refBrlyMTimetable),
	INDEX (refBrlyMEquipment),
	INDEX (refBrlyMFaflight),
	INDEX (refBrlyMLeg),
	INDEX (sref),
	INDEX (start),
	INDEX (stop),
	INDEX (Calcdone),
	INDEX (Segdone)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMLeg(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	ixVBasetype INT UNSIGNED,
	refBrlyCLeg BIGINT UNSIGNED,
	bgnRefBrlyMLocation BIGINT UNSIGNED,
	endRefBrlyMLocation BIGINT UNSIGNED,
	alt DOUBLE,
	deltaphi DOUBLE,
	alpha DOUBLE,
	xAlt DOUBLE,
	xPhi0 DOUBLE,
	xPhi1 DOUBLE,
	xAlpha DOUBLE,
	Calcdone TINYINT,
	INDEX (grp),
	INDEX (own),
	INDEX (ixVBasetype),
	INDEX (refBrlyCLeg),
	INDEX (bgnRefBrlyMLocation),
	INDEX (endRefBrlyMLocation),
	INDEX (Calcdone)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMLocation(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	ixVBasetype INT UNSIGNED,
	refBrlyMRegion BIGINT UNSIGNED,
	refBrlyMEquipment BIGINT UNSIGNED,
	sref VARCHAR(50),
	srefICAO VARCHAR(5),
	Title VARCHAR(50),
	alt DOUBLE,
	theta DOUBLE,
	phi DOUBLE,
	tz VARCHAR(50),
	alpha DOUBLE,
	Calcdone TINYINT,
	INDEX (ixVBasetype),
	INDEX (refBrlyMRegion),
	INDEX (refBrlyMEquipment),
	INDEX (sref),
	INDEX (srefICAO),
	INDEX (Title),
	INDEX (Calcdone)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMNode(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMRelay BIGINT UNSIGNED,
	supRefBrlyMNode BIGINT UNSIGNED,
	supLvl SMALLINT UNSIGNED,
	supNum INT UNSIGNED,
	refBrlyMEquipment BIGINT UNSIGNED,
	INDEX (refBrlyMRelay),
	INDEX (supRefBrlyMNode),
	INDEX (supLvl),
	INDEX (supNum),
	INDEX (refBrlyMEquipment)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMOperator(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	sref VARCHAR(50),
	srefICAO VARCHAR(5),
	Title VARCHAR(50),
	INDEX (sref),
	INDEX (srefICAO),
	INDEX (Title)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMPerson(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	ixWDerivate INT UNSIGNED,
	ixVSex INT UNSIGNED,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	refJLastname BIGINT UNSIGNED,
	Lastname VARCHAR(50),
	telRefADetail BIGINT UNSIGNED,
	telVal VARCHAR(192),
	emlRefADetail BIGINT UNSIGNED,
	emlVal VARCHAR(192),
	Salutation VARCHAR(100),
	INDEX (grp),
	INDEX (own),
	INDEX (ixWDerivate),
	INDEX (Lastname)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMPlntype(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	sref VARCHAR(50),
	Title VARCHAR(50),
	srefBrlyKEqptype VARCHAR(50),
	Capacity SMALLINT UNSIGNED,
	INDEX (sref),
	INDEX (Title)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMRegion(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	supRefBrlyMRegion BIGINT UNSIGNED,
	supLvl SMALLINT UNSIGNED,
	sref VARCHAR(50),
	refJTitle BIGINT UNSIGNED,
	Title VARCHAR(50),
	refJ BIGINT UNSIGNED,
	ixVDst INT UNSIGNED,
	toffset DOUBLE,
	INDEX (supRefBrlyMRegion),
	INDEX (supLvl),
	INDEX (sref),
	INDEX (Title)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMRelay(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	refBrlyMConnection BIGINT UNSIGNED,
	ixVDir INT UNSIGNED,
	Connected TINYINT,
	Nhop SMALLINT UNSIGNED,
	INDEX (x1Start),
	INDEX (x1Stop),
	INDEX (refBrlyMConnection),
	INDEX (ixVDir)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMSegment(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refIxVTbl INT UNSIGNED,
	refUref BIGINT UNSIGNED,
	refNum INT UNSIGNED,
	deltaphi DOUBLE,
	alt0 DOUBLE,
	alt1 DOUBLE,
	theta0 DOUBLE,
	theta1 DOUBLE,
	phi0 DOUBLE,
	phi1 DOUBLE,
	start INT UNSIGNED,
	stop INT UNSIGNED,
	Calcdone TINYINT,
	INDEX (refIxVTbl),
	INDEX (refUref),
	INDEX (refNum),
	INDEX (start),
	INDEX (stop),
	INDEX (Calcdone)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMSession(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMUser BIGINT UNSIGNED,
	start INT UNSIGNED,
	stop INT UNSIGNED,
	Ip VARCHAR(30),
	INDEX (refBrlyMUser),
	INDEX (start)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMTimetable(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMFile BIGINT UNSIGNED,
	srefBrlyKAlliance VARCHAR(50),
	Title VARCHAR(50),
	startd INT UNSIGNED,
	stopd INT UNSIGNED,
	INDEX (refBrlyMFile),
	INDEX (Title)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMUser(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	refRUsergroup BIGINT UNSIGNED,
	refBrlyMUsergroup BIGINT UNSIGNED,
	refBrlyMPerson BIGINT UNSIGNED,
	sref VARCHAR(50),
	refJState BIGINT UNSIGNED,
	ixVState INT UNSIGNED,
	ixBrlyVLocale INT UNSIGNED,
	ixBrlyVUserlevel INT UNSIGNED,
	Password VARCHAR(30),
	Fullkey TEXT,
	Comment TEXT,
	INDEX (grp),
	INDEX (own),
	INDEX (refBrlyMUsergroup),
	INDEX (refBrlyMPerson),
	INDEX (sref),
	INDEX (ixVState)
) ENGINE = ARIA;

CREATE TABLE TblBrlyMUsergroup(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	sref VARCHAR(50),
	Comment TEXT,
	INDEX (grp),
	INDEX (own),
	INDEX (sref)
) ENGINE = ARIA;

CREATE TABLE TblBrlyORMConnectionMEquipment(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMConnection BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	ixBrlyVOolop INT UNSIGNED,
	pr1RefLR BIGINT UNSIGNED,
	pr2RefLR BIGINT UNSIGNED,
	INDEX (refBrlyMConnection),
	INDEX (x1Start),
	INDEX (ixBrlyVOolop),
	INDEX (pr1RefLR),
	INDEX (pr2RefLR)
) ENGINE = ARIA;

CREATE TABLE TblBrlyProxRMLocationMLocation(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	dstRefBrlyMLocation BIGINT UNSIGNED,
	orgRefBrlyMLocation BIGINT UNSIGNED,
	deltaphi DOUBLE,
	INDEX (dstRefBrlyMLocation),
	INDEX (orgRefBrlyMLocation),
	INDEX (deltaphi)
) ENGINE = ARIA;

CREATE TABLE TblBrlyRMConnectionMFlight(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2Legphi0 DOUBLE,
	x2Legphi1 DOUBLE,
	refBrlyMConnection BIGINT UNSIGNED,
	refBrlyMFlight BIGINT UNSIGNED,
	INDEX (x1Start),
	INDEX (x1Stop),
	INDEX (x2Legphi0),
	INDEX (x2Legphi1),
	INDEX (refBrlyMConnection),
	INDEX (refBrlyMFlight)
) ENGINE = ARIA;

CREATE TABLE TblBrlyRMConnectionMSegment(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2Legphi0 DOUBLE,
	x2Legphi1 DOUBLE,
	refBrlyMConnection BIGINT UNSIGNED,
	refBrlyMSegment BIGINT UNSIGNED,
	INDEX (x1Start),
	INDEX (x1Stop),
	INDEX (x2Legphi0),
	INDEX (x2Legphi1),
	INDEX (refBrlyMConnection),
	INDEX (refBrlyMSegment)
) ENGINE = ARIA;

CREATE TABLE TblBrlyRMFlightMFlight(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1VisStart INT UNSIGNED,
	x1VisStop INT UNSIGNED,
	dstRefBrlyMFlight BIGINT UNSIGNED,
	orgRefBrlyMFlight BIGINT UNSIGNED,
	xVisStart INT UNSIGNED,
	xVisStop INT UNSIGNED,
	INDEX (x1VisStart),
	INDEX (x1VisStop),
	INDEX (dstRefBrlyMFlight),
	INDEX (orgRefBrlyMFlight)
) ENGINE = ARIA;

CREATE TABLE TblBrlyRMFlightMLocation(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1VisStart INT UNSIGNED,
	x1VisStop INT UNSIGNED,
	refBrlyMFlight BIGINT UNSIGNED,
	refBrlyMLocation BIGINT UNSIGNED,
	xVisStart INT UNSIGNED,
	xVisStop INT UNSIGNED,
	INDEX (x1VisStart),
	INDEX (x1VisStop),
	INDEX (refBrlyMFlight),
	INDEX (refBrlyMLocation)
) ENGINE = ARIA;

CREATE TABLE TblBrlyRMLegMLeg(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1VisDstLegphi0 DOUBLE,
	x1VisDstLegphi1 DOUBLE,
	dstRefBrlyMLeg BIGINT UNSIGNED,
	orgRefBrlyMLeg BIGINT UNSIGNED,
	VisOrgLegphi0 DOUBLE,
	VisOrgLegphi1 DOUBLE,
	xVisDstLegphi0 DOUBLE,
	xVisDstLegphi1 DOUBLE,
	xVisOrgLegphi0 DOUBLE,
	xVisOrgLegphi1 DOUBLE,
	INDEX (x1VisDstLegphi0),
	INDEX (x1VisDstLegphi1),
	INDEX (dstRefBrlyMLeg),
	INDEX (orgRefBrlyMLeg)
) ENGINE = ARIA;

CREATE TABLE TblBrlyRMLegMLocation(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1VisLegphi0 DOUBLE,
	x1VisLegphi1 DOUBLE,
	refBrlyMLeg BIGINT UNSIGNED,
	refBrlyMLocation BIGINT UNSIGNED,
	legphi DOUBLE,
	legtheta DOUBLE,
	xVisLegphi0 DOUBLE,
	xVisLegphi1 DOUBLE,
	INDEX (x1VisLegphi0),
	INDEX (x1VisLegphi1),
	INDEX (refBrlyMLeg),
	INDEX (refBrlyMLocation),
	INDEX (legphi)
) ENGINE = ARIA;

CREATE TABLE TblBrlyRMLocationMSegment(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2VisSegphi0 DOUBLE,
	x2VisSegphi1 DOUBLE,
	refBrlyMLocation BIGINT UNSIGNED,
	refBrlyMSegment BIGINT UNSIGNED,
	segphi DOUBLE,
	segtheta DOUBLE,
	INDEX (x1Start),
	INDEX (x1Stop),
	INDEX (x2VisSegphi0),
	INDEX (x2VisSegphi1),
	INDEX (refBrlyMLocation),
	INDEX (refBrlyMSegment),
	INDEX (segphi)
) ENGINE = ARIA;

CREATE TABLE TblBrlyRMSegmentMSegment(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2VisDstSegphi0 DOUBLE,
	x2VisDstSegphi1 DOUBLE,
	dstRefBrlyMSegment BIGINT UNSIGNED,
	orgRefBrlyMSegment BIGINT UNSIGNED,
	VisOrgSegphi0 DOUBLE,
	VisOrgSegphi1 DOUBLE,
	INDEX (x1Start),
	INDEX (x1Stop),
	INDEX (x2VisDstSegphi0),
	INDEX (x2VisDstSegphi1),
	INDEX (dstRefBrlyMSegment),
	INDEX (orgRefBrlyMSegment)
) ENGINE = ARIA;

CREATE TABLE TblBrlyRMUsergroupUniversal(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMUsergroup BIGINT UNSIGNED,
	unvIxBrlyVMaintable INT UNSIGNED,
	unvUref BIGINT UNSIGNED,
	ixBrlyVRecaccess INT UNSIGNED,
	INDEX (refBrlyMUsergroup),
	INDEX (unvIxBrlyVMaintable),
	INDEX (unvUref)
) ENGINE = ARIA;

CREATE TABLE TblBrlyRMUserMUsergroup(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refBrlyMUser BIGINT UNSIGNED,
	refBrlyMUsergroup BIGINT UNSIGNED,
	ixBrlyVUserlevel INT UNSIGNED,
	INDEX (refBrlyMUser),
	INDEX (refBrlyMUsergroup)
) ENGINE = ARIA;

CREATE TABLE TblBrlyVisRMLocationMLocation(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	dstRefBrlyMLocation BIGINT UNSIGNED,
	orgRefBrlyMLocation BIGINT UNSIGNED,
	INDEX (dstRefBrlyMLocation),
	INDEX (orgRefBrlyMLocation)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQCon1NRelay(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQConConMNEquipment(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	conIxBrlyVLat INT UNSIGNED,
	conNum INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQConList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	refBrlyMFlight BIGINT UNSIGNED,
	corRefBrlyMLeg BIGINT UNSIGNED,
	start INT UNSIGNED,
	stop INT UNSIGNED,
	ixVModel INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQConMapFlight(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	qwr TINYINT,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2Legphi0 DOUBLE,
	x2Legphi1 DOUBLE,
	mref BIGINT UNSIGNED,
	mrefBrlyMEquipment BIGINT UNSIGNED,
	mrefBrlyMLeg BIGINT UNSIGNED,
	mstart INT UNSIGNED,
	mstop INT UNSIGNED,
	x0 DOUBLE,
	y0 DOUBLE,
	t0 INT,
	dx DOUBLE,
	dy DOUBLE,
	dt INT,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQConMapLeg(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	qwr TINYINT,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	VisOrgLegphi0 DOUBLE,
	VisOrgLegphi1 DOUBLE,
	mref BIGINT UNSIGNED,
	mbgnRefBrlyMLocation BIGINT UNSIGNED,
	mendRefBrlyMLocation BIGINT UNSIGNED,
	mdeltaphi DOUBLE,
	dx DOUBLE,
	dy DOUBLE,
	x0 DOUBLE,
	y0 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQConMapLocation(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	qwr TINYINT,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	legphi DOUBLE,
	legtheta DOUBLE,
	mref BIGINT UNSIGNED,
	mrefBrlyMEquipment BIGINT UNSIGNED,
	x DOUBLE,
	y DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQConMapNode(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	qwr TINYINT,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	refBrlyMRelay BIGINT UNSIGNED,
	supRefBrlyMNode BIGINT UNSIGNED,
	refBrlyMEquipment BIGINT UNSIGNED,
	jnumRly INT,
	x0 DOUBLE,
	y0 DOUBLE,
	u0 DOUBLE,
	v0 DOUBLE,
	t0 INT,
	dx DOUBLE,
	dy DOUBLE,
	du DOUBLE,
	dv DOUBLE,
	dt INT,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQConMapRelay(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	qwr TINYINT,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	ixVDir INT UNSIGNED,
	Connected TINYINT,
	Nhop SMALLINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQConMNFlight(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2Legphi0 DOUBLE,
	x2Legphi1 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQConMNSegment(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2Legphi0 DOUBLE,
	x2Legphi1 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQConRef1NSegment(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	refNum INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQFilList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	Filename VARCHAR(50),
	refIxVTbl INT UNSIGNED,
	refUref BIGINT UNSIGNED,
	osrefKContent VARCHAR(50),
	srefKMimetype VARCHAR(50),
	Size SMALLINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQFlt1NConnection(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQFltEqp1NNode(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQFltEqpMNConnection(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	conIxBrlyVLat INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQFltFafAWaypoint(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	fafNum INT UNSIGNED,
	timestamp INT UNSIGNED,
	latitude DOUBLE,
	longitude DOUBLE,
	groundspeed SMALLINT UNSIGNED,
	altitude SMALLINT UNSIGNED,
	altitudeStatus VARCHAR(5),
	updateType VARCHAR(5),
	altitudeChange VARCHAR(5),
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQFltList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	sref VARCHAR(50),
	refBrlyMEquipment BIGINT UNSIGNED,
	refBrlyMFaflight BIGINT UNSIGNED,
	refBrlyMLeg BIGINT UNSIGNED,
	start INT UNSIGNED,
	stop INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQFltMNConnection(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2Legphi0 DOUBLE,
	x2Legphi1 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQFltMNLocation(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1VisStart INT UNSIGNED,
	x1VisStop INT UNSIGNED,
	xVisStart INT UNSIGNED,
	xVisStop INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQFltOrgMNFlight(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1VisStart INT UNSIGNED,
	x1VisStop INT UNSIGNED,
	xVisStart INT UNSIGNED,
	xVisStop INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQFltRef1NSegment(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	refNum INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLeg1NFlight(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLegCor1NConnection(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLegList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	bgnRefBrlyMLocation BIGINT UNSIGNED,
	endRefBrlyMLocation BIGINT UNSIGNED,
	ixVBasetype INT UNSIGNED,
	alt DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLegMapLeg(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	qwr TINYINT,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	VisOrgLegphi0 DOUBLE,
	VisOrgLegphi1 DOUBLE,
	mref BIGINT UNSIGNED,
	mbgnRefBrlyMLocation BIGINT UNSIGNED,
	mendRefBrlyMLocation BIGINT UNSIGNED,
	dx DOUBLE,
	dy DOUBLE,
	x0 DOUBLE,
	y0 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLegMapLocation(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	qwr TINYINT,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	legphi DOUBLE,
	legtheta DOUBLE,
	mref BIGINT UNSIGNED,
	x DOUBLE,
	y DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLegMNLocation(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1VisLegphi0 DOUBLE,
	x1VisLegphi1 DOUBLE,
	legphi DOUBLE,
	legtheta DOUBLE,
	xVisLegphi0 DOUBLE,
	xVisLegphi1 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLegOrgMNLeg(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1VisDstLegphi0 DOUBLE,
	x1VisDstLegphi1 DOUBLE,
	VisOrgLegphi0 DOUBLE,
	VisOrgLegphi1 DOUBLE,
	xVisDstLegphi0 DOUBLE,
	xVisDstLegphi1 DOUBLE,
	xVisOrgLegphi0 DOUBLE,
	xVisOrgLegphi1 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocBgn1NLeg(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocEnd1NLeg(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocEqp1NNode(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocEqpMNConnection(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	conIxBrlyVLat INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	sref VARCHAR(50),
	srefICAO VARCHAR(5),
	Title VARCHAR(50),
	ixVBasetype INT UNSIGNED,
	refBrlyMRegion BIGINT UNSIGNED,
	refBrlyMEquipment BIGINT UNSIGNED,
	alt DOUBLE,
	theta DOUBLE,
	phi DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocMapLeg(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	qwr TINYINT,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1VisLegphi0 DOUBLE,
	x1VisLegphi1 DOUBLE,
	mref BIGINT UNSIGNED,
	mbgnRefBrlyMLocation BIGINT UNSIGNED,
	mendRefBrlyMLocation BIGINT UNSIGNED,
	dx DOUBLE,
	dy DOUBLE,
	x0 DOUBLE,
	y0 DOUBLE,
	lam1 DOUBLE,
	lam2 DOUBLE,
	lam3 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocMapProxLocation(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	qwr TINYINT,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	mref BIGINT UNSIGNED,
	mtheta DOUBLE,
	mphi DOUBLE,
	x DOUBLE,
	y DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocMapVisLocation(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	qwr TINYINT,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	mref BIGINT UNSIGNED,
	mtheta DOUBLE,
	mphi DOUBLE,
	x DOUBLE,
	y DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocMNFlight(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1VisStart INT UNSIGNED,
	x1VisStop INT UNSIGNED,
	xVisStart INT UNSIGNED,
	xVisStop INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocMNLeg(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1VisLegphi0 DOUBLE,
	x1VisLegphi1 DOUBLE,
	legphi DOUBLE,
	legtheta DOUBLE,
	xVisLegphi0 DOUBLE,
	xVisLegphi1 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocMNSegment(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2VisSegphi0 DOUBLE,
	x2VisSegphi1 DOUBLE,
	segphi DOUBLE,
	segtheta DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocProxOrgMNLocation(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	deltaphi DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQLocVisOrgMNLocation(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQOpr1NEquipment(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQOprList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	sref VARCHAR(50),
	srefICAO VARCHAR(5),
	Title VARCHAR(50),
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQPreselect(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQPrsADetail(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192),
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQPrsList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	Lastname VARCHAR(50),
	ixVSex INT UNSIGNED,
	telVal VARCHAR(192),
	emlVal VARCHAR(192),
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQPty1NEquipment(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQPtyList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	sref VARCHAR(50),
	Title VARCHAR(50),
	srefBrlyKEqptype VARCHAR(50),
	Capacity SMALLINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQReg1NLocation(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQRegADstswitch(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	startd INT UNSIGNED,
	startt INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQRegList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	sref VARCHAR(50),
	Title VARCHAR(50),
	supRefBrlyMRegion BIGINT UNSIGNED,
	ixVDst INT UNSIGNED,
	toffset DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQRegSup1NRegion(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQRly1NNode(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQRlyList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	refBrlyMConnection BIGINT UNSIGNED,
	ixVDir INT UNSIGNED,
	Connected TINYINT,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQSegList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	refIxVTbl INT UNSIGNED,
	refUref BIGINT UNSIGNED,
	alt0 DOUBLE,
	alt1 DOUBLE,
	theta0 DOUBLE,
	theta1 DOUBLE,
	phi0 DOUBLE,
	phi1 DOUBLE,
	start INT UNSIGNED,
	stop INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQSegMNConnection(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2Legphi0 DOUBLE,
	x2Legphi1 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQSegMNLocation(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2VisSegphi0 DOUBLE,
	x2VisSegphi1 DOUBLE,
	segphi DOUBLE,
	segtheta DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQSegOrgMNSegment(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	x1Stop INT UNSIGNED,
	x2VisDstSegphi0 DOUBLE,
	x2VisDstSegphi1 DOUBLE,
	VisOrgSegphi0 DOUBLE,
	VisOrgSegphi1 DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQSelect(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ix INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (ix)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQTtb1NFlight(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQTtbList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	Title VARCHAR(50),
	refBrlyMFile BIGINT UNSIGNED,
	srefBrlyKAlliance VARCHAR(50),
	startd INT UNSIGNED,
	stopd INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQTtbRef1NFile(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQUsgAAccess(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1IxBrlyVFeatgroup INT UNSIGNED,
	x2FeaSrefUix VARCHAR(50),
	ixBrlyWAccess INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQUsgList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	sref VARCHAR(50),
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQUsgMNUser(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	ixBrlyVUserlevel INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQUsr1NSession(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQUsrAAccess(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1IxBrlyVFeatgroup INT UNSIGNED,
	x2FeaSrefUix VARCHAR(50),
	ixBrlyWAccess INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQUsrList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	refBrlyMPerson BIGINT UNSIGNED,
	sref VARCHAR(50),
	refBrlyMUsergroup BIGINT UNSIGNED,
	ixVState INT UNSIGNED,
	ixBrlyVLocale INT UNSIGNED,
	ixBrlyVUserlevel INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;

CREATE TABLE TblBrlyQUsrMNUsergroup(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	ixBrlyVUserlevel INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = ARIA;
