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
	m_PawnState = PawnState::MOVING;

	// Notify self that Pawn is ready to move.
	UpdatePawn();
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
			// Pawn should try to move in the input direction.
			m_PawnDirection = m_InputDirection;

			// Consume input.
			m_InputDirection = Direction::NONE;

			UpdatePawn();
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

	UpdatePawn();
}

// TODO remove
void PlayerPawnController::MovePacManRight()
{
	Vec2 worldPos = m_Maze->TileToWorldPos(Vec2(m_LastPawnTilePos.x + 1, 1));
	m_PacMan->MoveToPoint(worldPos);
}

bool PlayerPawnController::TileValid(Vec2 tileMapPos)
{
	return !m_Maze->IsWall(tileMapPos);
}

void PlayerPawnController::UpdatePawn()
{
	m_LastPawnTilePos = Utils::GetNeighbourTilePos(m_LastPawnTilePos, m_PawnDirection);

	CCLOG("m_LastPawnTilePos: (%f, %f)", m_LastPawnTilePos.x, m_LastPawnTilePos.y);
	m_PawnState = PawnState::WAITING;

	// if input is not NONE and the next tile in input direction is valid, change m_PawnDirection to input dir.
	if (m_InputDirection != Direction::NONE)
	{
		if (!m_Maze->IsWall(Utils::GetNeighbourTilePos(m_LastPawnTilePos, m_InputDirection)))
		{
			m_PawnDirection = m_InputDirection;
			m_InputDirection = Direction::NONE;
		}
	}

	MovePawn(m_PawnDirection);

	// Handle case when the Pawn is stuck against a wall.
	if (m_PawnState == PawnState::WAITING)
	{
		if (m_InputDirection != Direction::NONE)
		{
			// Pawn should try to move in the input direction.
			m_PawnDirection = m_InputDirection;

			// Consume input.
			m_InputDirection = Direction::NONE;

			UpdatePawn();
		}
	}
}

void PlayerPawnController::MovePawn(Direction dir)
{
	// Check if target tile is valid.
	Vec2 targetTilePos = Utils::GetNeighbourTilePos(m_LastPawnTilePos, dir);
	if (!TileValid(targetTilePos))
	{
		m_PawnDirection = Direction::NONE;
		return;
	}

	// Move Pawn.
	Vec2 worldPos = m_Maze->TileToWorldPos(targetTilePos);
	m_PacMan->MoveToPoint(worldPos);
	
	m_PawnState = PawnState::MOVING;
}
