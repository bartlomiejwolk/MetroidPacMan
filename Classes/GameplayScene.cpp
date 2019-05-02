#include "GameplayScene.h"
#include "SimpleAudioEngine.h"
#include "Utils.h"

USING_NS_CC;

Scene* GameplayScene::createScene()
{
    return GameplayScene::create();
}

// TODO move to Utils namespace
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool GameplayScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    m_OpenGLVisibleSize = Director::getInstance()->getVisibleSize();
    m_OpenGLOrigin = Director::getInstance()->getVisibleOrigin();

	// draw scene name label
	{
		auto label = Label::createWithTTF("Gameplay Scene", m_FontFilePath, m_FontSize);
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

void GameplayScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
