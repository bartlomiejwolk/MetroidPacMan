#pragma once

#include "Pawn.h"

class Akabei : public Pawn
{
public:
	Akabei(cocos2d::SpriteFrameCache* frameCache);

	~Akabei();

protected:
	void CreateSprite() override;

};

