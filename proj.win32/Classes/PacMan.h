#pragma once

#include "cocos2d.h"
#include "Signal.h"

// `PacMan` class should not depend on the `Maze` class.
class PacMan
{
public:
	PacMan(cocos2d::SpriteFrameCache* frameCache);
	
	~PacMan();

	Signal<> TargetPointReached;

	// Returns PacMan sprite node.
	cocos2d::Sprite* GetSpriteNode()
	{
		return m_PacManSprite;
	}

	// Sets PacMan sprite position relative to the parent node.
	void SetPosition(cocos2d::Vec2 position)
	{
		m_PacManSprite->setPosition(position);
	}

	// Moves PacMan sprite to GL point in world space.
	void MoveToPoint(cocos2d::Vec2 point);

private:
	cocos2d::SpriteFrameCache* m_SpriteFrameCache;

	cocos2d::Sprite* m_PacManSprite;

	// Creates PacMan sprite and animates it.
	// Initializes related class fields.
	void CreatePacManSprite();
};

