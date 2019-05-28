#include "Maze.h"
#include "cocos2d.h"
#include "Tile.h"

USING_NS_CC;

Maze::Maze()
{
	LoadTileMap();
	LoadPropertyList();
	InitGrid();
}

Maze::~Maze()
{
}

void Maze::LoadTileMap()
{
	m_TiledMap = TMXTiledMap::create("TileMap.tmx");
	// TODO assert not null
	m_BackgroundLayer = m_TiledMap->getLayer("Background");
	m_WallsLayer = m_TiledMap->getLayer("Walls");
	m_WaypointsLayer = m_TiledMap->getLayer("Waypoints");
	//m_ObjectGroup = m_TiledMap->getObjectGroup("Objects");
}

void Maze::LoadPropertyList()
{
	m_SpriteFrameCache = SpriteFrameCache::getInstance();
	// TODO extract const field
	m_SpriteFrameCache->addSpriteFramesWithFile("TexturePacker_spritesheet.plist");
}

void Maze::InitGrid()
{
	for (int x = 0; x < GRID_COLUMNS; x++)
	{
		for (int y = 0; y < GRID_ROWS; y++)
		{
			// Init tile `GridPosition` field.
			m_Grid[x][y].GridPosition = Vec2(x, y);

			// Init tile `IsWall` field.
			auto wallRef = m_WallsLayer->getTileAt(Vec2(x, y));
			m_Grid[x][y].IsWall = wallRef != nullptr;
		}
	}
}

Vec2 Maze::TileToWorldPos(const Vec2 & gridPos) const
{
	Sprite* tileSprite = GetBackgroundLayer()->getTileAt(gridPos);
	Vec2 tileLocalPos = tileSprite->getPosition();
	// TODO test without `getParent()`
	Vec2 tileWorldPos = tileSprite->getParent()->convertToWorldSpace(tileLocalPos);

	return tileWorldPos;
}

MetroidPacMan::Tile * Maze::GridPosToTile(const cocos2d::Vec2& gridPos) const
{
	return nullptr;
}

bool Maze::IsWall(cocos2d::Vec2 tileGridPos) const
{
	Sprite* tile = m_WallsLayer->getTileAt(tileGridPos);
	// tile without a wall on it will be nullptr
	return tile != nullptr;
}

bool Maze::IsWaypoint(cocos2d::Vec2 tileGridPos) const
{
	Sprite* tile = m_WallsLayer->getTileAt(tileGridPos);
	// tile without a waypoint on it will be nullptr
	return tile != nullptr;
}

