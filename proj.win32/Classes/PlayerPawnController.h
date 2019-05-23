#pragma once

#include "cocos2d.h"
#include "Maze.h"
#include "PacMan.h"
#include "Enums.h"

class PlayerPawnController : public cocos2d::Node
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

	void OnPawnReachedTargetPoint();

	// TODO delete. Initialize Maze during construction
	void SetMazeRef(Maze* maze)
	{
		m_Maze = maze;
	}

	// TODO replace with possession mechanizm
	void SetPacManRef(PacMan* pacMan)
	{
		m_PacMan = pacMan;
	}

private:
	// TODO use shared pointer
	Maze* m_Maze;

	// TODO use shared pointer
	PacMan* m_PacMan;

	// Last tile that the Pawn arrived to in tilemap coordinates.
	// Updated in `OnPawnReachedTargetPoint()`.
	cocos2d::Vec2 m_LastPawnTilePos = cocos2d::Vec2(1, 1);

	// TODO rename to PawnMovementDirection
	// The direction that the Pawn is currently heading towards.
	Direction m_PawnDirection = Direction::NONE;

	// Updated with player input.
	Direction m_InputDirection = Direction::NONE;

	PawnState m_PawnState = PawnState::WAITING;

	virtual bool init() override;

	virtual void onEnter() override;

	// Called in `init()`.
	void SubscribeToInputEvents();

	void HandleInput(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);

	bool TileValid(cocos2d::Vec2 tileMapPos);

	// Sends commands to the Pawn to update it based on current PC state.
	void UpdatePawn();

	void HandleInputMovement();

	void HandleContinuousMovement();

	// Moves Pawn to tile pointed by `m_PawnDirection`.
	void MovePawn(cocos2d::Vec2 gridPos);
};