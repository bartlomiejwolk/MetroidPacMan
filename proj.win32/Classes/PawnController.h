#pragma once

#include "cocos2d.h"
#include "Maze.h"
#include "Pawn.h"

class PawnController : public cocos2d::Node
{
public:
	PawnController();
	virtual ~PawnController();

	// TODO delete. Initialize Maze during construction
	void SetMazeRef(Maze* maze)
	{
		m_Maze = maze;
	}

	// TODO replace with possession mechanizm
	void SetPawnRef(Pawn* pawn)
	{
		m_Pawn = pawn;
	}

	virtual void OnPawnReachedTargetPoint();

	// TODO remove prefix from protected fields
protected:
	// TODO use shared pointer
	Maze* m_Maze;

	// TODO use shared pointer
	Pawn* m_Pawn;

};

