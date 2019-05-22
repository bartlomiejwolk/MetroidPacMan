#include "PacManScene.h"
#include "Utils.h"

USING_NS_CC;

bool PacManScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	SubscribeToInputEvents();

	m_OpenGLVisibleSize = Director::getInstance()->getVisibleSize();
	m_OpenGLOrigin = Director::getInstance()->getVisibleOrigin();

	// reposition top and bottom UI
	this->addChild(&m_UITop);
	this->addChild(&m_UIBotton);
	m_UITop.setPosition(Vec2(0, -180));
	m_UIBotton.setPosition(Vec2(0, 150));

	return true;
}

void PacManScene::SubscribeToInputEvents()
{
	auto eventListener = EventListenerKeyboard::create();
	eventListener->onKeyPressed = CC_CALLBACK_2(PacManScene::HandleInput, this);
	// NOTE: must be called after event handlers have been assigned
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

void PacManScene::HandleInput(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
}

void PacManScene::Draw1UPLabel()
{
	auto label = Label::createWithTTF("1UP", m_FontFilePath, m_FontSize);

	// TODO use string formatted message
	/*printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");*/
	assert(label && "Error while loading resource!");

	// position the label on the screen
	float x = m_OpenGLVisibleSize.width / 3;
	float y = m_OpenGLVisibleSize.height - label->getContentSize().height;
	label->setAnchorPoint(Vec2(0.5f, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	m_UITop.addChild(label, 1);
}

void PacManScene::Draw2UPLabel()
{
	auto label = Label::createWithTTF("2UP", m_FontFilePath, m_FontSize);
	assert(label && "Error while loading resource!");

	// position the label on the screen
	float x = m_OpenGLVisibleSize.width - m_OpenGLVisibleSize.width / 3;
	float y = m_OpenGLVisibleSize.height - label->getContentSize().height;
	label->setAnchorPoint(Vec2(0.5f, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	m_UITop.addChild(label, 1);
}

void PacManScene::DrawHighScoreLabel()
{
	auto label = Label::createWithTTF("HIGH SCORE", m_FontFilePath, m_FontSize);
	assert(label && "Error while loading resource!");

	// position the label on the screen
	float x = m_OpenGLVisibleSize.width / 2;
	float y = m_OpenGLVisibleSize.height - label->getContentSize().height;
	label->setAnchorPoint(Vec2(0.5f, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	m_UITop.addChild(label, 1);
}

void PacManScene::DrawHighScoreValueLabel(int highscore)
{
	std::string highscoreText = std::to_string(highscore);
	auto label = Label::createWithTTF(highscoreText, m_FontFilePath, m_FontSize);
	assert(label && "Error while loading resource!");

	// position the label on the screen
	float x = m_OpenGLVisibleSize.width / 2;
	float y = m_OpenGLVisibleSize.height - label->getContentSize().height * 2;
	label->setAnchorPoint(Vec2(0.5f, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	m_UITop.addChild(label, 1);
}

void PacManScene::DrawPlayerScoreValueLabel(int score)
{
	std::string scoreText = std::to_string(score);
	auto label = Label::createWithTTF(scoreText, m_FontFilePath, m_FontSize);
	assert(label && "Error while loading resource!");

	// position the label on the screen
	float x = m_OpenGLVisibleSize.width / 3;
	float y = m_OpenGLVisibleSize.height - label->getContentSize().height * 2;
	label->setAnchorPoint(Vec2(0.5f, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	m_UITop.addChild(label, 1);
}

void PacManScene::DrawCredits()
{
	auto label = Label::createWithTTF("CREDIT  0", m_FontFilePath, m_FontSize);
	assert(label && "Error while loading resource!");

	// position the label on the screen
	float x = m_OpenGLVisibleSize.width * 0.25;
	float y = m_OpenGLVisibleSize.height * 0.01;
	label->setAnchorPoint(Vec2(0, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	m_UIBotton.addChild(label, 1);
}

