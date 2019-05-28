#pragma once

#include "cocos2d.h"

namespace MetroidPacMan
{
	struct Tile
	{
		// Required to initialize empty array.
		Tile();

		Tile(cocos2d::Vec2 gridPos);

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

