#include "GameplayScene.h"
#include "SimpleAudioEngine.h"
#include "Utils.h"
#include "IntroScene.h"

USING_NS_CC;

Scene* GameplayScene::createScene()
{
    return GameplayScene::create();
}

bool GameplayScene::init()
{
    if ( !PacManScene::init() )
    {
        return false;
    }

	Draw1UPLabel();
	Draw2UPLabel();
	DrawHighScoreLabel();
 
	SubscribeToInputEvents();
	LoadTileMap();
	LoadPropertyList();
	CreatePacManSprite();

	// DEBUG draw scene name label
	{
		auto label = Label::createWithTTF("GAMEPLAY SCENE", m_FontFilePath, m_FontSize);
		assert(label && "Error while loading resource!");
		
		label->setPosition(Utils::GetScreenPoint(0.5f, 0.5f));
		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	{
 		auto powerUpObject = m_ObjectGroup->getObject("PowerUpTopLeft");
		auto x = powerUpObject["x"].asInt();
 		auto y = powerUpObject["y"].asInt();
		auto width = powerUpObject["width"].asInt();
		auto height = powerUpObject["height"].asInt();
		auto rotation = powerUpObject["rotation"].asInt();

		/*auto bgTile = bgLayer->getTileAt(Vec2(1, 3));
		bgTile->setPosition(Utils::GetScreenPoint(0.5f, 0.5f));*/

		//auto bgTile = bgLayer->getTileAt(Vec2(1, 1));
		//auto objectTile = objectLayer->getTileAt(Vec2(1, 1));
	}

    return true;
}

void GameplayScene::LoadTileMap() 
{
	auto tilemap = TMXTiledMap::create("TileMap.tmx");
	// TODO assert layers are not null
	auto bgLayer = tilemap->getLayer("Background");
	auto gameplayLayer = tilemap->getLayer("Gameplay");
	// TODO assert object group is not null
	m_ObjectGroup = tilemap->getObjectGroup("Objects");
	addChild(tilemap, 0, 99);
}

void GameplayScene::LoadPropertyList()
{
	m_SpriteFrameCache = SpriteFrameCache::getInstance();
	// TODO extract const field
	m_SpriteFrameCache->addSpriteFramesWithFile("TexturePacker_spritesheet.plist");
}

void GameplayScene::CreatePacManSprite()
{
	// create sprite
	auto testSprite = Sprite::createWithSpriteFrameName("image_part_051.png");
	testSprite->setPosition(Utils::GetScreenPoint(0.5f, 0.5f));
	this->addChild(testSprite);

	// get sprite frames
	Vector<SpriteFrame*> frames = Vector<SpriteFrame*>();
	frames.pushBack(m_SpriteFrameCache->getSpriteFrameByName("image_part_051.png")); // small
	frames.pushBack(m_SpriteFrameCache->getSpriteFrameByName("image_part_049.png")); // medium
	frames.pushBack(m_SpriteFrameCache->getSpriteFrameByName("image_part_051.png")); // small
	frames.pushBack(m_SpriteFrameCache->getSpriteFrameByName("image_part_113.png")); // closed

	// create and run animation
	auto animation = Animation::createWithSpriteFrames(frames, 0.1f, 1);
	auto animate = Animate::create(animation);
	testSprite->runAction(RepeatForever::create(animate));
}

void GameplayScene::SubscribeToInputEvents()
{
	auto eventListener = EventListenerKeyboard::create();
	eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event)
	{
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_ESCAPE:
		{
			auto introScene = IntroScene::createScene();
			Director::getInstance()->replaceScene(introScene);
			break;
		}
		}
	};
	// must be called after event handlers have been assigned
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

void GameplayScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void GameplayScene::update(float delta)
{
}
