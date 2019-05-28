#pragma once

#include "cocos2d.h"
#include "Maze.h"

class PathFinding
{
public:
	PathFinding(const Maze* maze);
	virtual ~PathFinding();

	// startPos Position of the start tile in grid coordinates.
	// endPos Position of the end tile in grid coordinates.
	// X: column, Y: row.
	void FindPath(cocos2d::Vec2 startPos, cocos2d::Vec2 endPos);

private:
	const Maze* m_Maze;
};

