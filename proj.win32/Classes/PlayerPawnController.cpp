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
	Vec2 newPos = m_Maze->TileToWorldPos(m_LastPawnTilePos);
	m_PacMan->SetPosition(newPos);
	
	// Set initial Pawn state and direction.
	m_PawnDirection = Direction::RIGHT;
	//m_PawnState = PawnState::MOVING;

	// Notify self that Pawn is ready to move.
	HandleContinuousMovement();
}

void PlayerPawnController::SubscribeToInputEvents()
{
	auto eventListener = EventListenerKeyboard::create();
	eventListener->onKeyPressed = CC_CALLBACK_2(PlayerPawnController::HandleInput, this);
	// NOTE: must be called after event handlers have been assigned
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

// TODO update `m_InputDirection` only when Pawn is near waypoint
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

	if (m_PawnState == PawnState::WAITING)
	{
		if (m_InputDirection != Direction::NONE)
		{
			HandleInputMovement();
		}
	}
}

void PlayerPawnController::update(float delta)
{
}

// TODO create custom macro to log Vec2
void PlayerPawnController::OnPawnReachedTargetPoint()
{
	CCLOG("OnPawnReachedTargetPoint");

	// TODO if this is called multiple time in a frame, the `m_LastPawnTilePos` will become invalid
	m_LastPawnTilePos = Utils::GetNeighbourTilePos(m_LastPawnTilePos, m_PawnDirection);

	CCLOG("m_LastPawnTilePos: (%f, %f)", m_LastPawnTilePos.x, m_LastPawnTilePos.y);
	m_PawnState = PawnState::WAITING;

	HandleInputMovement();
	HandleContinuousMovement();
}

bool PlayerPawnController::TileValid(Vec2 tileMapPos)
{
	return !m_Maze->IsWall(tileMapPos);
}

// TODO remove
void PlayerPawnController::UpdatePawn()
{
	
}

void PlayerPawnController::HandleInputMovement()
{
	if (m_InputDirection == Direction::NONE)
	{
		return;
	}
	
	if (m_PawnState == PawnState::MOVING)
	{
		return;
	}

	// Check if target tile is valid.
	Vec2 targetTile = Utils::GetNeighbourTilePos(m_LastPawnTilePos, m_InputDirection);
	if (!TileValid(targetTile))
	{
		return;
	}

	m_PawnDirection = m_InputDirection;
	m_InputDirection = Direction::NONE; // consume input
	m_PawnState = PawnState::MOVING;

	MovePawn(targetTile);
}

void PlayerPawnController::HandleContinuousMovement()
{
	// Pawn is already moving due to player input.
	if (m_PawnState == PawnState::MOVING)
	{
		return;
	}

	// Check if target tile is valid.
	Vec2 targetTilePos = Utils::GetNeighbourTilePos(m_LastPawnTilePos, m_PawnDirection);
	if (!TileValid(targetTilePos))
	{
		m_PawnDirection = Direction::NONE;
		return;
	}

	MovePawn(targetTilePos);
	m_PawnState = PawnState::MOVING;
}

void PlayerPawnController::MovePawn(Vec2 gridPos)
{
	Vec2 worldPos = m_Maze->TileToWorldPos(gridPos);
	m_PacMan->MoveToPoint(worldPos);
}
