/* ***************************************************************************** */
/* Copyright:      Francois Panneton and Pierre L'Ecuyer, University of Montreal */
/*                 Makoto Matsumoto, Hiroshima University                        */
/* Notice:         This code can be used freely for personal, academic,          */
/*                 or non-commercial purposes. For commercial purposes,          */
/*                 please contact P. L'Ecuyer at: lecuyer@iro.UMontreal.ca       */
/* ***************************************************************************** */

// Source: http://www.iro.umontreal.ca/~panneton/WELLRNG.html
// Also see http://en.wikipedia.org/wiki/Mersenne_twister, another good rng algorithm

#ifndef WELL_H
#define WELL_H

#include "Includes.h"

void InitRNG ();
unsigned int RNG ();

#endif