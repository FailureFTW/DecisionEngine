#ifndef POSITION_H
#define POSITION_H

#include "Includes.h"

struct StateInfo
{
	SquareType Board[16];
	SquareType Rankings[16][2];
	ScoreType Score;

};

#endif