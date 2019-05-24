#pragma once

#include "cocos2d.h"
#include "Signal.h"

class Pawn
{
public:
	Pawn(cocos2d::SpriteFrameCache* frameCache);

	virtual ~Pawn();

	Signal<> TargetPointReached;

	// Returns Pawn sprite node.
	cocos2d::Sprite* GetSpriteNode()
	{
		return m_PawnSprite;
	}

	// Sets Pawn sprite position relative to the parent node.
	void SetPosition(cocos2d::Vec2 position)
	{
		m_PawnSprite->setPosition(position);
	}

	// Animates Pawn sprite movement to GL point in world space.
	void MoveToPoint(cocos2d::Vec2 point);

protected:
	// Creates sprite and animates it.
	// Initializes related class fields.
	virtual void CreateSprite();

	// TODO remove `m_` prefix from protected fields
protected:
	cocos2d::SpriteFrameCache* m_SpriteFrameCache;

	cocos2d::Sprite* m_PawnSprite;
	
};

