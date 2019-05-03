#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "Utils.h"
#include "GameplayScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

bool MainMenuScene::init()
{
    if ( !PacManScene::init() )
    {
        return false;
    }

	Draw1UPLabel();
	Draw2UPLabel();
	DrawHighScoreLabel();
	DrawCredits();

	SubscribeToInputEvents();

	// draw scene name label
	{
		auto label = Label::createWithTTF("MAIN MENU SCENE", m_FontFilePath, m_FontSize);
		assert(label && "Error while loading resource!");

		label->setPosition(Utils::GetScreenPoint(0.5f, 0.5f));
		// add the label as a child to this layer
		this->addChild(label, 1);
	}

    return true;
}

void MainMenuScene::SubscribeToInputEvents()
{
	auto eventListener = EventListenerKeyboard::create();
	eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event)
	{
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_SPACE:
		case EventKeyboard::KeyCode::KEY_ENTER:
		{
			auto gameplayScene = GameplayScene::createScene();
			Director::getInstance()->replaceScene(gameplayScene);
			break;
		}
		}
	};
	// must be called after event handlers have been assigned
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

void MainMenuScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
