#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "Utils.h"
#include "GameplayScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

// TODO move to Utils namespace
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool MainMenuScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    m_OpenGLVisibleSize = Director::getInstance()->getVisibleSize();
    m_OpenGLOrigin = Director::getInstance()->getVisibleOrigin();

	SubscribeToInputEvents();

	// draw scene name label
	{
		auto label = Label::createWithTTF("GAMEPLAY SCENE", m_FontFilePath, m_FontSize);
		if (label == nullptr)
		{
			problemLoading(m_FontFilePath.c_str());
		}
		else
		{
			label->setPosition(Utils::GetScreenPoint(0.5f, 0.5f));
			// add the label as a child to this layer
			this->addChild(label, 1);
		}
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
