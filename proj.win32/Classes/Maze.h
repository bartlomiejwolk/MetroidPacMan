#pragma once

#include "cocos2d.h"
#include "Enums.h"
#include "Tile.h"
#include <array>

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
	// First tile is at (0, 0), top-left of the screen.
	// tileGridPos X: column, Y: row (it's defined this way in the TMX file).
	cocos2d::Vec2 TileToWorldPos(const cocos2d::Vec2& gridPos) const;

	// TODO shouldn't it be GetTileAtPos() ?
	MetroidPacMan::Tile* GridPosToTile(const cocos2d::Vec2& gridPos);

	bool IsWall(cocos2d::Vec2 tileGridPos) const;

	bool IsWaypoint(cocos2d::Vec2 tileGridPos) const;

private:
	//cocos2d::TMXObjectGroup* m_ObjectGroup;

	cocos2d::SpriteFrameCache* m_SpriteFrameCache;

	cocos2d::TMXTiledMap* m_TiledMap;

	// Contains black background.
	cocos2d::TMXLayer* m_BackgroundLayer;

	// Contains maze walls.
	cocos2d::TMXLayer* m_WallsLayer;

	cocos2d::TMXLayer* m_WaypointsLayer;

	//cocos2d::TMXLayer* m_ObjectLayer;

	// Loads `.tmx` tilemap file.
	void LoadTileMap();

	// Loads `.plist` file.
	void LoadPropertyList();

	void InitGrid();

	static const int GRID_ROWS = 31;

	static const int GRID_COLUMNS = 28;

	// TODO create typedef/using for 2d array type declaration
	// 2D array of grid tiles used for pathfinding.
	std::array<std::array<MetroidPacMan::Tile, GRID_ROWS>, GRID_COLUMNS> m_Grid;

public:
	std::array<std::array<MetroidPacMan::Tile, GRID_ROWS>, GRID_COLUMNS>& GetGrid()
	{
		return m_Grid;
	}

};

