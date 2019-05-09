#pragma once

#include "cocos2d.h"

// TODO consider making it static or a singleton
class Maze
{
public:
	Maze();
	~Maze();

	cocos2d::TMXTiledMap* GetTileMap()
	{
		return m_TiledMap;
	}

	cocos2d::SpriteFrameCache* GetSpriteFrameCache()
	{
		return m_SpriteFrameCache;
	}

private:
	cocos2d::TMXObjectGroup* m_ObjectGroup;

	cocos2d::SpriteFrameCache* m_SpriteFrameCache;

	cocos2d::TMXTiledMap* m_TiledMap;

	// Loads `.tmx` tilemap file.
	void LoadTileMap();

	// Loads `.plist` file.
	void LoadPropertyList();

};

