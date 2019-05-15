#include "Maze.h"
#include "cocos2d.h"

USING_NS_CC;

Maze::Maze()
{
	LoadTileMap();
	LoadPropertyList();
}

Maze::~Maze()
{
}

void Maze::LoadTileMap()
{
	m_TiledMap = TMXTiledMap::create("TileMap.tmx");
	// TODO assert not null
	m_BackgroundLayer = m_TiledMap->getLayer("Background");
	m_ObjectGroup = m_TiledMap->getObjectGroup("Objects");
}

void Maze::LoadPropertyList()
{
	m_SpriteFrameCache = SpriteFrameCache::getInstance();
	// TODO extract const field
	m_SpriteFrameCache->addSpriteFramesWithFile("TexturePacker_spritesheet.plist");
}

Vec2 Maze::TileToWorldPos(const Vec2 & tileGridPos) const
{
	Sprite* tileSprite = GetBackgroundLayer()->getTileAt(tileGridPos);
	Vec2 tileLocalPos = tileSprite->getPosition();
	Vec2 tileWorldPos = tileSprite->getParent()->convertToWorldSpace(tileLocalPos);

	return tileWorldPos;
}

