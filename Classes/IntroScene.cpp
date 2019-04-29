#include "IntroScene.h"
#include "SimpleAudioEngine.h"
#include "Utils.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* IntroScene::createScene()
{
    return IntroScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool IntroScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    m_OpenGLVisibleSize = Director::getInstance()->getVisibleSize();
    m_OpenGLOrigin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(IntroScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
		Size contentSize = closeItem->getContentSize();
        float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width - contentSize.width/2;
        float y = m_OpenGLOrigin.y + contentSize.height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

	Draw1UPLabel();
	Draw2UPLabel();
	DrawHighScoreLabel();
	DrawCharacterNicknames();
	DrawPointsInfo();
	DrawCompanyName();
	DrawCredits();

	RunPacManAnimation();

    return true;
}

void IntroScene::RunPacManAnimation()
{
	// PacMan
	{
		auto sprite = Sprite::create("PacMan.png");
		if (sprite == nullptr)
		{
			problemLoading("'PacMan.png'");
			return;
		}
		// position the sprite on the center of the screen
		sprite->setPosition(Utils::GetScreenPoint(1.1f, 0.45f));
		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
		auto moveToPowerUpAction = MoveTo::create(4, Utils::GetScreenPoint(0.35f, 0.45f));
		auto chaseGhostsAction = MoveTo::create(4, Utils::GetScreenPoint(1.1f, 0.45f));
		auto rotate180Action = RotateBy::create(0, 180);
		auto sequence = Sequence::create(moveToPowerUpAction, rotate180Action, chaseGhostsAction, NULL);
		sprite->runAction(sequence);
	}

	// PowerUp
	{
		auto sprite = Sprite::create("PowerUp.png");
		if (sprite == nullptr)
		{
			problemLoading("'PowerUp.png'");
			return;
		}
		// position the sprite on the center of the screen
		sprite->setPosition(Utils::GetScreenPoint(0.35f, 0.45f));
		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
		auto action = Place::create(Utils::GetScreenPoint(999, 999));
		DelayTime *delay = DelayTime::create(4);
		auto sequence = Sequence::create(delay, action, NULL);
		sprite->runAction(sequence);
	}

	// Pinky
	{
		auto sprite = Sprite::create("Pinky.png");
		if (sprite == nullptr)
		{
			problemLoading("'Pinky.png'");
			return;
		}
		// position the sprite on the center of the screen
		sprite->setPosition(Utils::GetScreenPoint(1.2f, 0.45f));
		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
		auto chasePacManAction = MoveTo::create(4, Utils::GetScreenPoint(0.4f, 0.45f));
		auto escapeAction = MoveTo::create(7, Utils::GetScreenPoint(1.2f, 0.45f));
		auto sequence = Sequence::create(chasePacManAction, escapeAction, NULL);
		sprite->runAction(sequence);
	}

	// Akabei
	{
		auto sprite = Sprite::create("Akabei.png");
		if (sprite == nullptr)
		{
			problemLoading("'Akabei.png'");
			return;
		}
		// position the sprite on the center of the screen
		sprite->setPosition(Utils::GetScreenPoint(1.25f, 0.45f));
		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
		auto chasePacManAction = MoveTo::create(4, Utils::GetScreenPoint(0.45f, 0.45f));
		auto escapeAction = MoveTo::create(7, Utils::GetScreenPoint(1.25f, 0.45f));
		auto sequence = Sequence::create(chasePacManAction, escapeAction, NULL);
		sprite->runAction(sequence);
	}

	// Aosuke
	{
		auto sprite = Sprite::create("Aosuke.png");
		if (sprite == nullptr)
		{
			problemLoading("'Aosuke.png'");
			return;
		}
		// position the sprite on the center of the screen
		sprite->setPosition(Utils::GetScreenPoint(1.3f, 0.45f));
		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
		auto chasePacManAction = MoveTo::create(4, Utils::GetScreenPoint(0.5f, 0.45f));
		auto escapeAction = MoveTo::create(7, Utils::GetScreenPoint(1.3f, 0.45f));
		auto sequence = Sequence::create(chasePacManAction, escapeAction, NULL);
		sprite->runAction(sequence);
	}

	// Guzuta
	{
		auto sprite = Sprite::create("Guzuta.png");
		if (sprite == nullptr)
		{
			problemLoading("'Guzuta.png'");
			return;
		}
		// position the sprite on the center of the screen
		sprite->setPosition(Utils::GetScreenPoint(1.35f, 0.45f));
		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
		auto chasePacManAction = MoveTo::create(4, Utils::GetScreenPoint(0.55f, 0.45f));
		auto escapeAction = MoveTo::create(7, Utils::GetScreenPoint(1.35f, 0.45f));
		auto sequence = Sequence::create(chasePacManAction, escapeAction, NULL);
		sprite->runAction(sequence);
	}

}

void IntroScene::Draw1UPLabel()
{
	auto label = Label::createWithTTF("1UP", m_FontFilePath, m_FontSize);
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}

	// position the label on the screen
	float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 4;
	float y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height - label->getContentSize().height;
	label->setAnchorPoint(Vec2(0, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void IntroScene::Draw2UPLabel()
{
	auto label = Label::createWithTTF("2UP", m_FontFilePath, m_FontSize);
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}

	// position the label on the screen
	float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.75;
	float y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height - label->getContentSize().height;
	label->setAnchorPoint(Vec2(1, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void IntroScene::DrawHighScoreLabel()
{
	auto label = Label::createWithTTF("HIGH SCORE", m_FontFilePath, m_FontSize);
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}

	// position the label on the screen
	float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 2;
	float y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height - label->getContentSize().height;
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void IntroScene::DrawCharacterNicknames()
{
	Label *label = nullptr;
	
	float x = 0;
	float y = 0;

	// draw "CHARACTER / NICKNAME"
	label = Label::createWithTTF("CHARACTER / NICKNAME", m_FontFilePath, m_FontSize);
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 2;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.8;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);

	// draw OIKAKE----"AKABEI"
	label = Label::createWithTTF("OIKAKE----\"AKABEI\"", m_FontFilePath, m_FontSize);
	label->setAnchorPoint(Vec2(0, 0));
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.3;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.7;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);

	// draw MACHIBUSE----"PINKY"
	label = Label::createWithTTF("MACHIBUSE--\"PINKY\"", m_FontFilePath, m_FontSize);
	label->setAnchorPoint(Vec2(0, 0));
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.3;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.65;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);

	// draw KIMAGURE----"AOSUKE"
	label = Label::createWithTTF("KIMAGURE--\"AOSUKE\"", m_FontFilePath, m_FontSize);
	label->setAnchorPoint(Vec2(0, 0));
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.3;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.6;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);

	// draw OTOBOKE----"GUZUTA"
	label = Label::createWithTTF("OTOBOKE---\"GUZUTA\"", m_FontFilePath, m_FontSize);
	label->setAnchorPoint(Vec2(0, 0));
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.3;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.55;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);
}

void IntroScene::DrawPointsInfo()
{
	Label *label = nullptr;

	float x = 0;
	float y = 0;

	// draw "10 PTS"
	label = Label::createWithTTF("10 PTS", m_FontFilePath, m_FontSize);
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 2;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.35;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);

	// draw "20 PTS"
	label = Label::createWithTTF("20 PTS", m_FontFilePath, m_FontSize);
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 2;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.3;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);
}

void IntroScene::DrawCompanyName()
{
	auto label = Label::createWithTTF("METROIDSNES", m_FontFilePath, m_FontSize);
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}

	// position the label on the screen
	float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 2;
	float y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.15;
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void IntroScene::DrawCredits() 
{
	auto label = Label::createWithTTF("CREDIT  0", m_FontFilePath, m_FontSize);
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}

	// position the label on the screen
	float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.25;
	float y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.01;
	label->setAnchorPoint(Vec2(0, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void IntroScene::menuCloseCallback(Ref* pSender)
{
	auto mainMenuScene = MainMenuScene::createScene();
    //Close the cocos2d-x game scene and quit the application
	Director::getInstance()->pushScene(mainMenuScene);

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
