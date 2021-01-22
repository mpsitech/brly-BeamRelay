/**
	* \file BrlyTtimpRawstar.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYTTIMPRAWSTAR_H
#define BRLYTTIMPRAWSTAR_H

#include "BrlyTtimp.h"

// IP include.cust --- INSERT

namespace BrlyTtimpRawstar {

	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyTtimpRawstar* dpchinv);
	// IP cust --- IBEGIN

	class Leg {

	public:
		Leg(const Sbecore::ubigint iref, const std::string& srefBgnRefBrlyMLocation, const std::string& srefEndRefBrlyMLocation);

		Sbecore::ubigint iref;
		std::string srefBgnRefBrlyMLocation;
		std::string srefEndRefBrlyMLocation;
	};

	class Flight {

	public:
		Flight(const std::string& hintRefBrlyMEquipment, const Sbecore::ubigint irefRefBrlyMLeg, const std::string& sref, const int hintStart, const int hintStop, const std::string& iDate, const std::string& iWeekday);

		std::string hintRefBrlyMEquipment;
		Sbecore::ubigint irefRefBrlyMLeg;
		std::string sref;
		int hintStart;
		int hintStop;
		std::string iDate;
		std::string iWeekday;
	};

	void parseFile(std::fstream& infile, std::vector<Leg*>& legs, std::vector<Flight*>& flts);
	void writeLegs(std::fstream& outfile, const std::vector<Leg*>& legs);
	void writeFlights(std::fstream& outfile, const std::vector<Flight*>& flts);
	// IP cust --- IEND
};

#endif
