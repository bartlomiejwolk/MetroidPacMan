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
	SubscribeToInputEvents();

	return true;
}

void PlayerPawnController::onEnter()
{
	Node::onEnter();

	// set PacMan initial position
	Vec2 newPos = m_Maze->TileToWorldPos(m_CurrentPawnTilePos);
	m_PacMan->SetPosition(newPos);
	
	MovePacManRight();
}

void PlayerPawnController::SubscribeToInputEvents()
{
	auto eventListener = EventListenerKeyboard::create();
	eventListener->onKeyPressed = CC_CALLBACK_2(PlayerPawnController::HandleInput, this);
	// NOTE: must be called after event handlers have been assigned
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

void PlayerPawnController::HandleInput(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		CCLOG("KEY_LEFT_ARROW");
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		CCLOG("KEY_RIGHT_ARROW");
		break;
	}
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		CCLOG("KEY_UP_ARROW");
		break;
	}
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		CCLOG("KEY_DOWN_ARROW");
		break;
	}
	}
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