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
	// set PacMan initial position
	Vec2 newPos = m_Maze->TileToWorldPos(m_CurrentPawnTilePos);
	m_PacMan->SetPosition(newPos);
	
	MovePacManRight();
}

void PlayerPawnController::update(float delta)
{
}

void PlayerPawnController::OnPawnReachedTargetPoint()
{
	CCLOG("OnPawnReachedTargetPoint");

	// TODO try using `m_CurrentPawnTilePos++`
	m_CurrentPawnTilePos = Vec2(m_CurrentPawnTilePos.x + 1, 1);
	// TODO create custom macro to log Vec2
	CCLOG("m_CurrentPawnTilePos: (%f, %f)", m_CurrentPawnTilePos.x, m_CurrentPawnTilePos.y);

	if (RightTileValid())
	{
		MovePacManRight();
	}
}

void PlayerPawnController::MovePacManRight()
{
	Vec2 worldPos = m_Maze->TileToWorldPos(Vec2(m_CurrentPawnTilePos.x + 1, 1));
	m_PacMan->MoveToPoint(worldPos);
}

bool PlayerPawnController::RightTileValid()
{
	return !m_Maze->IsWall(Vec2(m_CurrentPawnTilePos.x + 1, 1));
}