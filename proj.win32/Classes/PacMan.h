#pragma once

#include "cocos2d.h"
#include "Signal.h"
#include "Pawn.h"

// `PacMan` class should not depend on the `Maze` class.
class PacMan : public Pawn
{
public:
	// Generate constructor equal to that of the base class.
	// https://softwareengineering.stackexchange.com/a/197901
	//using Pawn::Pawn;

	PacMan(cocos2d::SpriteFrameCache* frameCache);

protected:
	void CreateSprite() override;

};

