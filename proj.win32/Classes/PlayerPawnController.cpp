#include "PlayerPawnController.h"
#include "cocos2d.h"

USING_NS_CC;

PlayerPawnController* PlayerPawnController::create()
{
	PlayerPawnController* pc = new (std::nothrow) PlayerPawnController();
	if (pc && pc->init())
	{
		pc->autorelease();
		return pc;
	}
	CC_SAFE_DELETE(pc);
	return nullptr;
}

bool PlayerPawnController::init()
{
	return true;
}

void PlayerPawnController::onEnter()
{
	// set PacMan position to tile (1, 1)
	Vec2 newPos = m_Maze->TileToWorldPos(Vec2(1, 1));
	m_PacMan->SetPosition(newPos);

	// move to tile (2, 1)
	Vec2 worldPos = m_Maze->TileToWorldPos(Vec2(1, 13));
	m_PacMan->MoveToPoint(worldPos);
}

void PlayerPawnController::update(float delta)
{
}

void PlayerPawnController::OnPawnReachedTargetPoint()
{
	CCLOG("OnPawnReachedTargetPoint");
}
