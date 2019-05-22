#pragma once

#include "cocos2d.h"
#include "Maze.h"
#include "PacMan.h"

class PlayerPawnController : public cocos2d::Node
{
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

	// Current Pawn position in tilemap coordinates.
	// Updated in `OnPawnReachedTargetPoint()`.
	cocos2d::Vec2 m_CurrentPawnTilePos = cocos2d::Vec2(1, 1);

	virtual bool init() override;

	virtual void onEnter() override;

	// Called in `init()`.
	void SubscribeToInputEvents();

	void HandleInput(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);

	void MovePacManRight();

	bool RightTileValid();
};

