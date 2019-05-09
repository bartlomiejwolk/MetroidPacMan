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
	// TODO assert layers are not null
	auto bgLayer = m_TiledMap->getLayer("Background");
	auto gameplayLayer = m_TiledMap->getLayer("Gameplay");
	// TODO assert object group is not null
	m_ObjectGroup = m_TiledMap->getObjectGroup("Objects");
}

void Maze::LoadPropertyList()
{
	m_SpriteFrameCache = SpriteFrameCache::getInstance();
	// TODO extract const field
	m_SpriteFrameCache->addSpriteFramesWithFile("TexturePacker_spritesheet.plist");
}
