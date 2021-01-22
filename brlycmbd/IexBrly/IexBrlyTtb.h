/**
	* \file IexBrlyTtb.h
	* data blocks and readers/writers for import/export complex IexBrlyTtb (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef IEXBRLYTTB_H
#define IEXBRLYTTB_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsBrly.h"
#include "VecBrlyVIop.h"

#define VecVIexBrlyTtbIme IexBrlyTtb::VecVIme

#define ImeitemIBrlyTtbMFlight IexBrlyTtb::ImeitemIMFlight
#define ImeIBrlyTtbMFlight IexBrlyTtb::ImeIMFlight
#define VecWImeIBrlyTtbMFlightIel IexBrlyTtb::ImeIMFlight::VecWIel

#define ImeitemIBrlyTtbMLeg IexBrlyTtb::ImeitemIMLeg
#define ImeIBrlyTtbMLeg IexBrlyTtb::ImeIMLeg
#define VecWImeIBrlyTtbMLegIel IexBrlyTtb::ImeIMLeg::VecWIel

/**
	* IexBrlyTtb
	*/
namespace IexBrlyTtb {
	/**
		* VecVIme (full: VecVIexBrlyTtbIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIMFLIGHT = 1;
		static const Sbecore::uint IMEIMLEG = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIMFlight (full: ImeitemIBrlyTtbMFlight)
		*/
	class ImeitemIMFlight : public BrlyMFlight {

	public:
		ImeitemIMFlight(const std::string& hintRefBrlyMEquipment = "", const Sbecore::ubigint irefRefBrlyMLeg = 0, const std::string& sref = "", const std::string& hintStart = "", const std::string& hintStop = "", const std::string& iDate = "", const std::string& iWeekday = "");
		ImeitemIMFlight(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hintRefBrlyMEquipment;
		Sbecore::ubigint irefRefBrlyMLeg;
		std::string hintStart;
		std::string hintStop;
		std::string iDate;
		std::string iWeekday;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFlight (full: ImeIBrlyTtbMFlight)
		*/
	class ImeIMFlight {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyTtbMFlightIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HINTREFBRLYMEQUIPMENT = 1;
			static const Sbecore::uint IREFREFBRLYMLEG = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint HINTSTART = 8;
			static const Sbecore::uint HINTSTOP = 16;
			static const Sbecore::uint IDATE = 32;
			static const Sbecore::uint IWEEKDAY = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFlight();
		~ImeIMFlight();

	public:
		std::vector<ImeitemIMFlight*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMLeg (full: ImeitemIBrlyTtbMLeg)
		*/
	class ImeitemIMLeg : public BrlyMLeg {

	public:
		ImeitemIMLeg(const Sbecore::ubigint iref = 0, const std::string& srefBgnRefBrlyMLocation = "", const std::string& srefEndRefBrlyMLocation = "");
		ImeitemIMLeg(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;
		std::string srefBgnRefBrlyMLocation;
		std::string srefEndRefBrlyMLocation;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMLeg (full: ImeIBrlyTtbMLeg)
		*/
	class ImeIMLeg {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyTtbMLegIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;
			static const Sbecore::uint SREFBGNREFBRLYMLOCATION = 2;
			static const Sbecore::uint SREFENDREFBRLYMLOCATION = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMLeg();
		~ImeIMLeg();

	public:
		std::vector<ImeitemIMLeg*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIMFlight& imeimflight, ImeIMLeg& imeimleg);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMFlight& imeimflight, ImeIMLeg& imeimleg);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMFlight& imeimflight, ImeIMLeg& imeimleg);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMFlight& imeimflight, ImeIMLeg& imeimleg);

	void writeTxt(std::fstream& outfile, ImeIMFlight& imeimflight, ImeIMLeg& imeimleg);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMFlight& imeimflight, ImeIMLeg& imeimleg);

	std::map<Sbecore::uint,Sbecore::uint> icsBrlyVIopInsAll();
	Sbecore::uint getIxBrlyVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsBrlyVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixBrlyVIop);
};

#endif
