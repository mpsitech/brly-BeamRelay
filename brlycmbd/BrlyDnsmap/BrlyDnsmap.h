/**
	* \file BrlyDnsmap.h
	* Brly operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYDNSMAP_H
#define BRLYDNSMAP_H

#include "BrlyDnsmap_blks.h"

// IP include.cust --- IBEGIN
#include <netcdf.h>
#include <png.h>
// IP include.cust --- IEND

namespace BrlyDnsmap {

	// IP cust --- IBEGIN
	void scalePng(const std::string& tmppath, const unsigned int width, const unsigned int height, const bool grayscale);
	void preparePng(std::vector<double>& zdat, const bool spczmax, double zmax, const unsigned int width, const unsigned int height, const unsigned int fullwidth, const unsigned int fullheight, const unsigned int x0, const unsigned int y0, const bool grayscale, unsigned char** imgdat);
	std::string writePng(const std::string& tmppath, unsigned char* imgdat, const unsigned int width, const unsigned int height);
	void setPngPixel(unsigned char* imgdat, const unsigned int width, const unsigned int height, const unsigned int x, const unsigned int y, const unsigned char rval, const unsigned char gval, const unsigned char bval);
	// IP cust --- IEND
};

#endif
