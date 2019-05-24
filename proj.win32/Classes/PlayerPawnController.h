#pragma once

#include "cocos2d.h"
#include "Maze.h"
#include "PacMan.h"
#include "Enums.h"
#include "PawnController.h"

class PlayerPawnController : public PawnController
{
	enum class PawnState
	{
		// Pawn is waiting new target point coordinates.
		WAITING,

		// Pawn is moving towards target point.
		MOVING, 
	};

public:
	static PlayerPawnController* create();

	virtual void update(float delta) override;

	void OnPawnReachedTargetPoint() override;

private:

	// Last tile that the Pawn arrived to in tilemap coordinates.
	// Updated in `OnPawnReachedTargetPoint()`.
	// Initialized to Pawn default postion in the Maze.
	cocos2d::Vec2 m_CurrentPawnTilePos = cocos2d::Vec2(14, 17);

	// The direction that the Pawn is currently heading towards.
	// Also defines the direction that the Pawn move towards.
	Direction m_PawnMovementDir = Direction::RIGHT;

	// Updated with player input.
	Direction m_InputDirection = Direction::NONE;

	PawnState m_PawnState = PawnState::WAITING;

	virtual bool init() override;

	virtual void onEnter() override;

	// Called in `init()`.
	void SubscribeToInputEvents();

	void HandleInput(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);

	bool IsTileValid(cocos2d::Vec2 tileMapPos);

	// Moves Pawn using player input.
	// Called only from `OnPawnReachedTargetPoint()`.
	void MovePawn_Input();

	// Moves Pawn using its current movement direction.
	// Called only from `OnPawnReachedTargetPoint()`.
	void MovePawn_Continuous();

	// Moves Pawn to tile.
	void MovePawn(cocos2d::Vec2 gridPos);
};