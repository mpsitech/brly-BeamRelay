/**
	* \file IexBrlyFlt.h
	* data blocks and readers/writers for import/export complex IexBrlyFlt (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef IEXBRLYFLT_H
#define IEXBRLYFLT_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsBrly.h"
#include "VecBrlyVIop.h"

#define VecVIexBrlyFltIme IexBrlyFlt::VecVIme

#define ImeitemIBrlyFltAMFaflightWaypoint IexBrlyFlt::ImeitemIAMFaflightWaypoint
#define ImeIBrlyFltAMFaflightWaypoint IexBrlyFlt::ImeIAMFaflightWaypoint
#define VecWImeIBrlyFltAMFaflightWaypointIel IexBrlyFlt::ImeIAMFaflightWaypoint::VecWIel

#define ImeitemIBrlyFltMFaflight IexBrlyFlt::ImeitemIMFaflight
#define ImeIBrlyFltMFaflight IexBrlyFlt::ImeIMFaflight
#define VecWImeIBrlyFltMFaflightIel IexBrlyFlt::ImeIMFaflight::VecWIel

/**
	* IexBrlyFlt
	*/
namespace IexBrlyFlt {
	/**
		* VecVIme (full: VecVIexBrlyFltIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMFAFLIGHTWAYPOINT = 1;
		static const Sbecore::uint IMEIMFAFLIGHT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAMFaflightWaypoint (full: ImeitemIBrlyFltAMFaflightWaypoint)
		*/
	class ImeitemIAMFaflightWaypoint : public BrlyAMFaflightWaypoint {

	public:
		ImeitemIAMFaflightWaypoint(const Sbecore::uint timestamp = 0, const double latitude = 0.0, const double longitude = 0.0, const Sbecore::usmallint groundspeed = 0, const Sbecore::usmallint altitude = 0, const std::string& altitudeStatus = "", const std::string& updateType = "", const std::string& altitudeChange = "");
		ImeitemIAMFaflightWaypoint(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMFaflightWaypoint (full: ImeIBrlyFltAMFaflightWaypoint)
		*/
	class ImeIAMFaflightWaypoint {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyFltAMFaflightWaypointIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint TIMESTAMP = 1;
			static const Sbecore::uint LATITUDE = 2;
			static const Sbecore::uint LONGITUDE = 4;
			static const Sbecore::uint GROUNDSPEED = 8;
			static const Sbecore::uint ALTITUDE = 16;
			static const Sbecore::uint ALTITUDESTATUS = 32;
			static const Sbecore::uint UPDATETYPE = 64;
			static const Sbecore::uint ALTITUDECHANGE = 128;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMFaflightWaypoint();
		~ImeIAMFaflightWaypoint();

	public:
		std::vector<ImeitemIAMFaflightWaypoint*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFaflight (full: ImeitemIBrlyFltMFaflight)
		*/
	class ImeitemIMFaflight : public BrlyMFaflight {

	public:
		ImeitemIMFaflight(const Sbecore::uint ixBrlyVIop = 0, const std::string& iLeg = "", const std::string& hintRefBrlyMFlight = "", const std::string& faFlightID = "", const std::string& ident = "", const std::string& aircrafttype = "", const std::string& filed_ete = "", const Sbecore::uint filed_time = 0, const Sbecore::uint filed_departuretime = 0, const Sbecore::usmallint filed_airspeed_kts = 0, const double filed_airspeed_mach = 0.0, const Sbecore::usmallint filed_altitude = 0, const std::string& route = "", const Sbecore::uint actualdeparturetime = 0, const Sbecore::uint estimatedarrivaltime = 0, const Sbecore::uint actualarrivaltime = 0, const std::string& diverted = "", const std::string& origin = "", const std::string& destination = "", const std::string& originName = "", const std::string& originCity = "", const std::string& destinationName = "", const std::string& destinationCity = "");
		ImeitemIMFaflight(DbsBrly* dbsbrly, const Sbecore::uint ixBrlyVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixBrlyVIop;
		std::string srefIxBrlyVIop;
		std::string iLeg;
		std::string hintRefBrlyMFlight;

		ImeIAMFaflightWaypoint imeiamfaflightwaypoint;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFaflight (full: ImeIBrlyFltMFaflight)
		*/
	class ImeIMFaflight {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyFltMFaflightIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXBRLYVIOP = 1;
			static const Sbecore::uint ILEG = 2;
			static const Sbecore::uint HINTREFBRLYMFLIGHT = 4;
			static const Sbecore::uint FAFLIGHTID = 8;
			static const Sbecore::uint IDENT = 16;
			static const Sbecore::uint AIRCRAFTTYPE = 32;
			static const Sbecore::uint FILED_ETE = 64;
			static const Sbecore::uint FILED_TIME = 128;
			static const Sbecore::uint FILED_DEPARTURETIME = 256;
			static const Sbecore::uint FILED_AIRSPEED_KTS = 512;
			static const Sbecore::uint FILED_AIRSPEED_MACH = 1024;
			static const Sbecore::uint FILED_ALTITUDE = 2048;
			static const Sbecore::uint ROUTE = 4096;
			static const Sbecore::uint ACTUALDEPARTURETIME = 8192;
			static const Sbecore::uint ESTIMATEDARRIVALTIME = 16384;
			static const Sbecore::uint ACTUALARRIVALTIME = 32768;
			static const Sbecore::uint DIVERTED = 65536;
			static const Sbecore::uint ORIGIN = 131072;
			static const Sbecore::uint DESTINATION = 262144;
			static const Sbecore::uint ORIGINNAME = 524288;
			static const Sbecore::uint ORIGINCITY = 1048576;
			static const Sbecore::uint DESTINATIONNAME = 2097152;
			static const Sbecore::uint DESTINATIONCITY = 4194304;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFaflight();
		~ImeIMFaflight();

	public:
		std::vector<ImeitemIMFaflight*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIMFaflight& imeimfaflight);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMFaflight& imeimfaflight);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMFaflight& imeimfaflight);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMFaflight& imeimfaflight);

	void writeTxt(std::fstream& outfile, ImeIMFaflight& imeimfaflight);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMFaflight& imeimfaflight);

	std::map<Sbecore::uint,Sbecore::uint> icsBrlyVIopInsAll();
	Sbecore::uint getIxBrlyVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsBrlyVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixBrlyVIop);
};

#endif
