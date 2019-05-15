#include "PacMan.h"
#include "cocos2d.h"
#include "Utils.h"

USING_NS_CC;

PacMan::PacMan(SpriteFrameCache* frameCache)
{
	m_SpriteFrameCache = frameCache;
	CreatePacManSprite();
}

PacMan::~PacMan()
{
}

void PacMan::CreatePacManSprite()
{
	// create sprite
	m_PacManSprite = Sprite::createWithSpriteFrameName("image_part_051.png");
	// TODO create method to set anchor point and set it from the gameplay scene
	// offset anchor point to avoid sprite clipping into maze walls
	m_PacManSprite->setAnchorPoint(Vec2(0.25f, 0.25f));
	// TODO define default position in header file
	m_PacManSprite->setPosition(Utils::GetScreenPoint(0.5f, 0.5f));

	// get sprite frames
	Vector<SpriteFrame*> frames = Vector<SpriteFrame*>();
	frames.pushBack(m_SpriteFrameCache->getSpriteFrameByName("image_part_051.png")); // small
	frames.pushBack(m_SpriteFrameCache->getSpriteFrameByName("image_part_049.png")); // medium
	frames.pushBack(m_SpriteFrameCache->getSpriteFrameByName("image_part_051.png")); // small
	frames.pushBack(m_SpriteFrameCache->getSpriteFrameByName("image_part_113.png")); // closed

	// create and run animation
	auto animation = Animation::createWithSpriteFrames(frames, 0.1f, 1);
	auto animate = Animate::create(animation);
	m_PacManSprite->runAction(RepeatForever::create(animate));
}
