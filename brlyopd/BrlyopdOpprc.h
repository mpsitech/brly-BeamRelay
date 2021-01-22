/**
	* \file BrlyopdOpprc.h
	* operation processor for Brly operation daemon brlyopd (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYOPDOPPRC_H
#define BRLYOPDOPPRC_H

#include "BrlyTtimpRawstar.h"
#include "BrlyMapgenConmap.h"
#include "BrlyMapgenLegmap.h"
#include "BrlyMapgenLocmap.h"
#include "BrlyDynConflt.h"
#include "BrlyDynConseg.h"
#include "BrlyDynEqplist.h"
#include "BrlyDynFltfltloc.h"
#include "BrlyDynFltseg.h"
#include "BrlyDynRly.h"
#include "BrlyDynSeglocseg.h"
#include "BrlyDnsmapCollect.h"
#include "BrlyDnsmapFrame.h"
#include "BrlyDnsmapVideo.h"
#include "BrlyBaseLegleg.h"
#include "BrlyBaseLegloc.h"
#include "BrlyBaseLocloc.h"

/**
	* BrlyopdOpprc
	*/
namespace BrlyopdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif
