#include "GameplayScene.h"
#include "SimpleAudioEngine.h"
#include "Utils.h"
#include "IntroScene.h"
#include "PacMan.h"
#include "Maze.h"
#include "PlayerPawnController.h"

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
	DrawHighScoreValueLabel(99999);
	DrawPlayerScoreValueLabel(99999);
 
	SubscribeToInputEvents();

	// create maze
	{
		m_Maze = new Maze();
		TMXTiledMap* mazeTileMap = m_Maze->GetTileMap();
		mazeTileMap->setPosition(Vec2(768, 300));
		addChild(mazeTileMap, 0, 99);
	}

	// Requires maze to be initialized!
	{
		DrawLives();
		DrawFruits();
	}

	// create PacMan object
	{
		// TODO destroy PacMan in destructor
		m_PacMan = new PacMan(m_Maze->GetSpriteFrameCache());
		this->addChild(m_PacMan->GetSpriteNode());
	}

	// TEST
	{
		/*auto powerUpObject = m_ObjectGroup->getObject("PowerUpTopLeft");
		auto x = powerUpObject["x"].asInt();
		auto y = powerUpObject["y"].asInt();
		auto width = powerUpObject["width"].asInt();
		auto height = powerUpObject["height"].asInt();
		auto rotation = powerUpObject["rotation"].asInt();*/

		/*auto bgTile = bgLayer->getTileAt(Vec2(1, 3));
		bgTile->setPosition(Utils::GetScreenPoint(0.5f, 0.5f));*/

		//auto bgTile = bgLayer->getTileAt(Vec2(1, 1));
		//auto objectTile = objectLayer->getTileAt(Vec2(1, 1));
	}

	// create Player Pawn Controller
	{
		PlayerPawnController ppc = PlayerPawnController();

		// set PacMan position to tile (1, 1)
		Vec2 newPos = m_Maze->TileToWorldPos(Vec2(1, 1));
		m_PacMan->SetPosition(newPos);
	}

    return true;
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

void GameplayScene::DrawLives()
{
	// create life sprite
	auto sprite = Sprite::createWithSpriteFrameName("image_part_051.png");
	sprite->setAnchorPoint(Vec2(0, 0));
	sprite->setPosition(Utils::GetScreenPoint(0.3f, 0));
	m_UIBotton.addChild(sprite);
}

void GameplayScene::DrawFruits()
{
	// create fruit sprite
	auto sprite = Sprite::createWithSpriteFrameName("image_part_081.png");
	sprite->setAnchorPoint(Vec2(0, 0));
	sprite->setPosition(Utils::GetScreenPoint(0.7f, 0));
	m_UIBotton.addChild(sprite);
}
