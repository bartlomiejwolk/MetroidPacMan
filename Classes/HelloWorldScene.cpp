/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

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

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(m_OpenGLVisibleSize.width/2 + m_OpenGLOrigin.x, m_OpenGLVisibleSize.height/2 + m_OpenGLOrigin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    return true;
}

void HelloWorld::Draw1UPLabel()
{
	// TODO create const for font filepath
	auto label = Label::createWithTTF("1UP", m_FontFilePath, m_FontSize);
	if (label == nullptr)
	{
		problemLoading(m_FontFilePath.c_str());
		return;
	}

	// position the label on the screen
	float x = m_OpenGLOrigin.x + m_OpenGLVisibleSize.width / 4;
	float y = m_OpenGLOrigin.y + m_OpenGLVisibleSize.height - label->getContentSize().height;
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void HelloWorld::Draw2UPLabel()
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
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void HelloWorld::DrawHighScoreLabel()
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

void HelloWorld::DrawCharacterNicknames()
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

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
