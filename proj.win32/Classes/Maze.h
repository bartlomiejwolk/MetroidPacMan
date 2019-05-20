#pragma once

#include "cocos2d.h"

// TODO consider making it static or a singleton
// TODO create `Sprite* GetTileAt(Vec2)`. Use `GetBackgroundLayer()->getTileAt(Vec2)`
// TODO make sure it's destroyed when no longer used
class Maze
{
public:
	Maze();
	~Maze();

	cocos2d::TMXTiledMap* GetTileMap() const
	{
		return m_TiledMap;
	}

	cocos2d::TMXLayer* GetBackgroundLayer() const
	{
		return m_BackgroundLayer;
	}

	cocos2d::SpriteFrameCache* GetSpriteFrameCache() const
	{
		return m_SpriteFrameCache;
	}

	// Returns tile position in world space. Tile anchor point is bottom-left.
	// First element specifies row, second - column.
	// First tile is at (0, 0), top-left of the screen.
	cocos2d::Vec2 TileToWorldPos(const cocos2d::Vec2& tileGridPos) const;

private:
	//cocos2d::TMXObjectGroup* m_ObjectGroup;

	cocos2d::SpriteFrameCache* m_SpriteFrameCache;

	cocos2d::TMXTiledMap* m_TiledMap;

	cocos2d::TMXLayer* m_BackgroundLayer;

	//cocos2d::TMXLayer* m_ObjectLayer;

	// Loads `.tmx` tilemap file.
	void LoadTileMap();

	// Loads `.plist` file.
	void LoadPropertyList();

};

