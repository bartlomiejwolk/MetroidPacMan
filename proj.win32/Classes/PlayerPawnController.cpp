#include "PlayerPawnController.h"
#include "cocos2d.h"
#include "Utils.h"

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
	m_Pawn->SetPosition(newPos);
	
	MovePawn_Continuous();
}

void PlayerPawnController::SubscribeToInputEvents()
{
	auto eventListener = EventListenerKeyboard::create();
	eventListener->onKeyPressed = CC_CALLBACK_2(PlayerPawnController::HandleInput, this);
	// NOTE: must be called after event handlers have been assigned
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

// TODO call `MovePawn_Input` only when Pawn is near waypoint
void PlayerPawnController::HandleInput(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		CCLOG("KEY_LEFT_ARROW");
		m_InputDirection = Direction::LEFT;
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		CCLOG("KEY_RIGHT_ARROW");
		m_InputDirection = Direction::RIGHT;
		break;
	}
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		CCLOG("KEY_UP_ARROW");
		m_InputDirection = Direction::UP;
		break;
	}
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		CCLOG("KEY_DOWN_ARROW");
		m_InputDirection = Direction::DOWN;
		break;
	}
	}

	MovePawn_Input();
}

void PlayerPawnController::update(float delta)
{
}

// TODO create custom macro to log Vec2
void PlayerPawnController::OnPawnReachedTargetPoint()
{
	m_CurrentPawnTilePos = Utils::GetNeighbourTilePos(m_CurrentPawnTilePos, m_PawnMovementDir);

	CCLOG("updated m_LastPawnTilePos: (%f, %f)", m_CurrentPawnTilePos.x, m_CurrentPawnTilePos.y);
	m_PawnState = PawnState::WAITING;

	// Only one of these two methods will move the Pawn.
	// Execution order matters!
	MovePawn_Input();
	MovePawn_Continuous();
}

bool PlayerPawnController::IsTileValid(Vec2 tileMapPos)
{
	return !m_Maze->IsWall(tileMapPos);
}

void PlayerPawnController::MovePawn_Input()
{
	if (m_PawnState != PawnState::WAITING)
	{
		return;
	}

	if (m_InputDirection == Direction::NONE)
	{
		return;
	}
	
	// Check if target tile is valid.
	Vec2 targetTile = Utils::GetNeighbourTilePos(m_CurrentPawnTilePos, m_InputDirection);
	if (!IsTileValid(targetTile))
	{
		return;
	}

	m_PawnMovementDir = m_InputDirection;
	m_InputDirection = Direction::NONE; // consume input
	m_PawnState = PawnState::MOVING;

	MovePawn(targetTile);
}

void PlayerPawnController::MovePawn_Continuous()
{
	// Pawn is already moving due to player input.
	if (m_PawnState != PawnState::WAITING)
	{
		return;
	}

	// Check if target tile is valid.
	Vec2 targetTilePos = Utils::GetNeighbourTilePos(m_CurrentPawnTilePos, m_PawnMovementDir);
	if (!IsTileValid(targetTilePos))
	{
		m_PawnMovementDir = Direction::NONE;
		return;
	}

	m_PawnState = PawnState::MOVING;
	MovePawn(targetTilePos);
}

void PlayerPawnController::MovePawn(Vec2 gridPos)
{
	Vec2 worldPos = m_Maze->TileToWorldPos(gridPos);
	m_Pawn->MoveToPoint(worldPos);
}
