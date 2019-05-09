#pragma once

#include "cocos2d.h"

class PacMan
{
public:
	PacMan(cocos2d::SpriteFrameCache* frameCache);
	~PacMan();

	// Returns PacMan sprite node.
	cocos2d::Sprite* GetSpriteNode()
	{
		return m_PacManSprite;
	}

private:
	cocos2d::SpriteFrameCache* m_SpriteFrameCache;

	cocos2d::Sprite* m_PacManSprite;

	// Creates PacMan sprite and animates it.
	// Initializes related class fields.
	void CreatePacManSprite();
};

