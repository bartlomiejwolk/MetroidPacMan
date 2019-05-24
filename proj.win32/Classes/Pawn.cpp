#include "Pawn.h"
#include "cocos2d.h"
#include "Utils.h"

USING_NS_CC;

Pawn::Pawn(SpriteFrameCache* frameCache)
{
	m_SpriteFrameCache = frameCache;
}


Pawn::~Pawn()
{
}

void Pawn::CreateSprite()
{
	// intentionally left empty
}

void Pawn::MoveToPoint(Vec2 point)
{
	// TODO magic number
	MoveTo* moveToAction = MoveTo::create(0.3f, point);
	auto callback = CallFunc::create([this]() { Pawn::TargetPointReached.emit(); });
	auto sequence = Sequence::create(moveToAction, callback, nullptr);
	m_PawnSprite->runAction(sequence);
}
