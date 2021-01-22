/**
	* \file BrlycmbdOpprc.h
	* operation processor for Brly combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
  */
// IP header --- ABOVE

#ifndef BRLYCMBDOPPRC_H
#define BRLYCMBDOPPRC_H

#include "BrlyBaseLegleg.h"
#include "BrlyBaseLegloc.h"
#include "BrlyBaseLocloc.h"
#include "BrlyDnsmapCollect.h"
#include "BrlyDnsmapFrame.h"
#include "BrlyDnsmapVideo.h"
#include "BrlyDynConflt.h"
#include "BrlyDynConseg.h"
#include "BrlyDynEqplist.h"
#include "BrlyDynFltfltloc.h"
#include "BrlyDynFltseg.h"
#include "BrlyDynRly.h"
#include "BrlyDynSeglocseg.h"
#include "BrlyMapgenConmap.h"
#include "BrlyMapgenLegmap.h"
#include "BrlyMapgenLocmap.h"
#include "BrlyTtimpRawstar.h"

/**
	* BrlycmbdOpprc
	*/
namespace BrlycmbdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif
