#include "PacManScene.h"

USING_NS_CC;

bool PacManScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	m_OpenGLVisibleSize = Director::getInstance()->getVisibleSize();
	m_OpenGLOrigin = Director::getInstance()->getVisibleOrigin();

	return true;
}

void PacManScene::Draw1UPLabel()
{
	auto label = Label::createWithTTF("1UP", m_FontFilePath, m_FontSize);

	// TODO use string formatted message
	/*printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");*/
	assert(label && "Error while loading resource!");

	// TODO extract to class fields. Create public init() to initialize before using this class
	auto openGLVisibleSize = Director::getInstance()->getVisibleSize();
	auto openGLOrigin = Director::getInstance()->getVisibleOrigin();

	// position the label on the screen
	float x = openGLOrigin.x + openGLVisibleSize.width / 4;
	float y = openGLOrigin.y + openGLVisibleSize.height - label->getContentSize().height;
	label->setAnchorPoint(Vec2(0, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void PacManScene::Draw2UPLabel()
{
	auto label = Label::createWithTTF("2UP", m_FontFilePath, m_FontSize);
	assert(label && "Error while loading resource!");

	// position the label on the screen
	float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.75;
	float y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height - label->getContentSize().height;
	label->setAnchorPoint(Vec2(1, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void PacManScene::DrawHighScoreLabel()
{
	auto label = Label::createWithTTF("HIGH SCORE", m_FontFilePath, m_FontSize);
	assert(label && "Error while loading resource!");

	// position the label on the screen
	float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 2;
	float y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height - label->getContentSize().height;
	label->setAnchorPoint(Vec2(0.5f, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void PacManScene::DrawCredits()
{
	auto label = Label::createWithTTF("CREDIT  0", m_FontFilePath, m_FontSize);
	assert(label && "Error while loading resource!");

	// position the label on the screen
	float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width * 0.25;
	float y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height * 0.01;
	label->setAnchorPoint(Vec2(0, 0));
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

