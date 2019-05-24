#include "Akabei.h"
#include "cocos2d.h"
#include "Utils.h"

USING_NS_CC;

Akabei::Akabei(cocos2d::SpriteFrameCache * frameCache) : Pawn(frameCache)
{
	CreateSprite();
}

Akabei::~Akabei()
{
}

void Akabei::CreateSprite()
{
	// create sprite
	m_PawnSprite = Sprite::createWithSpriteFrameName("image_part_101.png");
	// TODO create method to set anchor point and set it from the gameplay scene
	// offset anchor point to avoid sprite clipping into maze walls
	m_PawnSprite->setAnchorPoint(Vec2(0.25f, 0.25f));
	// TODO define default position in header file
	m_PawnSprite->setPosition(Utils::GetScreenPoint(0.5f, 0.5f));

	// get sprite frames
	Vector<SpriteFrame*> frames = Vector<SpriteFrame*>();
	frames.pushBack(m_SpriteFrameCache->getSpriteFrameByName("image_part_101.png")); // small
	frames.pushBack(m_SpriteFrameCache->getSpriteFrameByName("image_part_102.png")); // medium

	// create and run animation
	auto animation = Animation::createWithSpriteFrames(frames, 0.15f, 1);
	auto animate = Animate::create(animation);
	m_PawnSprite->runAction(RepeatForever::create(animate));
}
