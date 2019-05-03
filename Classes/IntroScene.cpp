#include "IntroScene.h"
#include "SimpleAudioEngine.h"
#include "Utils.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* IntroScene::createScene()
{
    return IntroScene::create();
}

bool IntroScene::init()
{
    if (!PacManScene::init())
    {
        return false;
    }

	Draw1UPLabel();
	Draw2UPLabel();
	DrawHighScoreLabel();
	DrawCharacterNicknames();
	DrawPointsInfo();
	DrawCompanyName();
	DrawCredits();
	RunPacManAnimation();

	SubscribeToInputEvents();

    return true;
}

// TODO move to a custom base scene class
void IntroScene::SubscribeToInputEvents()
{
	auto eventListener = EventListenerKeyboard::create();
	eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event)
	{
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_SPACE:
		case EventKeyboard::KeyCode::KEY_ENTER:
		{
			auto mainMenuScene = MainMenuScene::createScene();
			Director::getInstance()->replaceScene(mainMenuScene);
			break;
		}
		}
	};
	// must be called after event handlers have been assigned
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

void IntroScene::RunPacManAnimation()
{
	// PacMan
	{
		auto sprite = Sprite::create("PacMan.png");
		// TODO replace with assert macro
		/*if (sprite == nullptr)
		{
			Utils::ProblemLoading("PacMan.png");
			return;
		}*/
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
		/*if (sprite == nullptr)
		{
			problemLoading("'PowerUp.png'");
			return;
		}*/
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
		/*if (sprite == nullptr)
		{
			problemLoading("'Pinky.png'");
			return;
		}*/
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
		/*if (sprite == nullptr)
		{
			problemLoading("'Akabei.png'");
			return;
		}*/
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
		/*if (sprite == nullptr)
		{
			problemLoading("'Aosuke.png'");
			return;
		}*/
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
		/*if (sprite == nullptr)
		{
			problemLoading("'Guzuta.png'");
			return;
		}*/
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

void IntroScene::DrawCharacterNicknames()
{
	Label *label = nullptr;
	
	float x = 0;
	float y = 0;

	// draw "CHARACTER / NICKNAME"
	label = Label::createWithTTF("CHARACTER / NICKNAME", m_FontFilePath, m_FontSize);
	/*if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}*/
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 2;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.8;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);

	// draw OIKAKE----"AKABEI"
	label = Label::createWithTTF("OIKAKE----\"AKABEI\"", m_FontFilePath, m_FontSize);
	label->setAnchorPoint(Vec2(0, 0));
	/*if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}*/
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.3;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.7;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);

	// draw MACHIBUSE----"PINKY"
	label = Label::createWithTTF("MACHIBUSE--\"PINKY\"", m_FontFilePath, m_FontSize);
	label->setAnchorPoint(Vec2(0, 0));
	/*if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}*/
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.3;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.65;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);

	// draw KIMAGURE----"AOSUKE"
	label = Label::createWithTTF("KIMAGURE--\"AOSUKE\"", m_FontFilePath, m_FontSize);
	label->setAnchorPoint(Vec2(0, 0));
	/*if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}*/
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.3;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.6;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);

	// draw OTOBOKE----"GUZUTA"
	label = Label::createWithTTF("OTOBOKE---\"GUZUTA\"", m_FontFilePath, m_FontSize);
	label->setAnchorPoint(Vec2(0, 0));
	/*if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}*/
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
	/*if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}*/
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 2;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.35;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);

	// draw "20 PTS"
	label = Label::createWithTTF("20 PTS", m_FontFilePath, m_FontSize);
	/*if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}*/
	x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 2;
	y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.3;
	label->setPosition(Vec2(x, y));
	this->addChild(label, 1);
}

void IntroScene::DrawCompanyName()
{
	auto label = Label::createWithTTF("METROIDSNES", m_FontFilePath, m_FontSize);
	/*if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}*/

	// position the label on the screen
	float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 2;
	float y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.15;
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void IntroScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
