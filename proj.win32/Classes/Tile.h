#pragma once

#include "cocos2d.h"

namespace MetroidPacMan
{
	struct Tile
	{
		// Required to initialize empty array.
		Tile();

		Tile(cocos2d::Vec2 gridPos);

		// Required by std::set.
		// Current implementation doesn't serve any purpose.
		// TODO fix implementation to make sure this class works well with the std::set
		bool operator<(const Tile& rhs) const
		{
			return GridPosition.x < rhs.GridPosition.x;
		}

		bool operator==(const Tile& rhs)
		{
			return GridPosition.x == rhs.GridPosition.x && GridPosition.y == rhs.GridPosition.y;
		}

		cocos2d::Size Dimentions;

		// X : row, Y : column
		cocos2d::Vec2 GridPosition;

		// Position in GL points relative to the scene Node.
		// Tile pivot point is at the center of the tile.
		cocos2d::Vec2 WorldPosition;

		bool IsWall;

		// Used by A*.
		int GCost;

		// Used by A*.
		int HCost;

		int GetFCost()
		{
			return GCost + HCost;
		}
	};
}

