/**
	* \file BrlyMapgen.h
	* Brly operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYMAPGEN_H
#define BRLYMAPGEN_H

#include "BrlyMapgen_blks.h"

// IP include.cust --- IBEGIN
#include <cmath>
#include <netcdf.h>
#include <png.h>
// IP include.cust --- IEND

#define ShrdatBrlyMapgen BrlyMapgen::Shrdat

namespace BrlyMapgen {
	/**
		* Shrdat (full: ShrdatBrlyMapgen)
		*/
	class Shrdat : public ShrdatBrly {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		// IP Shrdat.vars --- IBEGIN
		short* etopo;

		// color map look-up tables
		std::vector<Sbecore::utinyint> RvsZ;
		std::vector<Sbecore::utinyint> GvsZ;
		std::vector<Sbecore::utinyint> BvsZ;
		// IP Shrdat.vars --- IEND

	public:
		void init(XchgBrly* xchg, DbsBrly* dbsbrly);
		void term(XchgBrly* xchg);
	};

	extern Shrdat shrdat;

	// IP cust --- IBEGIN

	const double pi = 3.141592653589793238462643383279;

	namespace Cootype {
		const unsigned int BGNVIS = 0;
		const unsigned int ENDVIS = 1;
		const unsigned int NXSEC = 2;
		const unsigned int EXSEC = 3;
		const unsigned int SXSEC = 4;
		const unsigned int WXSEC = 5;
		const unsigned int BGNLEG = 6;
		const unsigned int ENDLEG = 7;
	};

	class Coo {

	public:
		Coo(const unsigned int type = 0, const double x = 0.0, const double y = 0.0, const double lam = 0.0);

	public:
		unsigned int type;
		double x;
		double y;
		double lam;
	};

	void writeMappng(XchgBrly* xchg, const std::string& outpath, const int width, const int height, short* z);
	void getRmatEquatorLeg(double _theta0, double _phi0, double _theta1, double _phi1, double** _rmat);
	void getRmatZeroLocation(double _theta0, double _phi0, double** _rmat);
	void getXRmat(double _phiX, double** _rmat);
	void getYRmat(double _phiY, double** _rmat);
	void getZRmat(double _phiZ, double** _rmat);
	void multAmatBmat(double* _amat, double* _bmat, double** _cmat, unsigned int _N);
	void multAmatBmatT(double* _amat, double* _bmat, double** _cmat, unsigned int _N);
	void multAmatBvec(double* _amat, double* _bvec, double** _cvec, unsigned int _N);
	void sphrToCart(double _r, double _theta, double _phi, double** _vec);
	double degToRad(double _deg);
	double radToDeg(double _rad);
	void locToRad(BrlyMLocation* loc);
	void legToRad(BrlyMLeg* leg);
	// IP cust --- IEND
};

#endif
