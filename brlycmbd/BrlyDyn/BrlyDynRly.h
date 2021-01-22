/**
	* \file BrlyDynRly.h
	* Brly operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDYNRLY_H
#define BRLYDYNRLY_H

#include "BrlyDyn.h"

// IP include.cust --- INSERT

namespace BrlyDynRly {

	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyDynRly* dpchinv);
	// IP cust --- IBEGIN

	/**
		* BrlyDynRly::Node
		*/
	class Node {

	public:
		// time-invariant properties
		Sbecore::ubigint eqpref;
		bool fiber;

		// time-varying properties
		bool relay; // true: node is part of established relay
		unsigned int tNext; // concerns start / stop of visibility only

		// connection tree
		Sbecore::ubigint eqprefUp;
		std::vector<Sbecore::ubigint> eqprefsDown;
		Sbecore::ubigint eqprefDown;

		// connectivity information (known upfront)
		std::map<Sbecore::ubigint, unsigned int> eqprefsVstart;
		std::map<Sbecore::ubigint, unsigned int> eqprefsVstop;

	public:
		Node(DbsBrly* dbsbrly, const BrlyMConnection* con, std::map<Sbecore::ubigint, Sbecore::ubigint>& eqprefsConLoc, std::map<Sbecore::ubigint, Sbecore::ubigint>& eqprefsConFlt, std::map<Sbecore::ubigint, unsigned int>& startsConFlt, std::map<Sbecore::ubigint, unsigned int>& stopsConFlt, const Sbecore::ubigint refBrlyMEquipment);

		// recursion method for establishing the connection tree
		bool evalTree(std::map<Sbecore::ubigint, Node*>& nodes, std::list<Sbecore::ubigint>& lineup, const std::list<Sbecore::ubigint>::iterator pivotit, const unsigned int t, const bool forward);
		void resetTree(std::map<Sbecore::ubigint, Node*>& nodes, const unsigned int stop);
		void insertInDbs(DbsBrly* dbsbrly, std::map<Sbecore::ubigint, Node*>& nodes, const Sbecore::ubigint refBrlyMRelay, const Sbecore::ubigint supRefBrlyMNode, const Sbecore::uint supLvl, const Sbecore::uint supNum, ListBrlyMNode& ndes, unsigned int& _tNext);

		void dump(DbsBrly* dbsbrly, std::map<Sbecore::ubigint, Node*>& nodes, const unsigned int il);
	};

	bool findInList(std::list<Sbecore::ubigint>& l, const Sbecore::ubigint v, std::list<Sbecore::ubigint>::iterator& it);
	void insertInDbs(DbsBrly* dbsbrly, std::map<Sbecore::ubigint, Node*>& nodes, const Sbecore::ubigint refBrlyMRelay, const Sbecore::ubigint supRefBrlyMNode, const Sbecore::uint supLvl, const Sbecore::uint supNum, ListBrlyMNode& ndes, unsigned int& _tNext);
	// IP cust --- IEND
};

#endif
