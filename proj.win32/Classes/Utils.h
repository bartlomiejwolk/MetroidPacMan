#pragma once

#include "cocos2d.h"
#include "Enums.h"

namespace Utils 
{
	/**
	 * Converts viewport point to OpenGL point.
	 *
	 * @param width Distance from (0, 0) bottom-left along horizontal axis represented as value from 0 to 1.
	 * @param height Distance from (0, 0) bottom-left along vertical axis represented as value from 0 to 1.
	 * @return Screen point as OpenGL point.
	 */
	static cocos2d::Point GetScreenPoint(float width, float height)
	{
		cocos2d::Size openGLVisibleSize = cocos2d::Director::getInstance()->getVisibleSize();
		cocos2d::Point result = cocos2d::Point(openGLVisibleSize.width * width, openGLVisibleSize.height * height);

		return result;
	}

	static cocos2d::Vec2 GetNeighbourTilePos(cocos2d::Vec2 tileGridPos, Direction direction)
	{
		cocos2d::Vec2 neighbourTile;

		switch (direction)
		{
		case Direction::UP:
		{
			neighbourTile = cocos2d::Vec2(tileGridPos.x, tileGridPos.y - 1);
			break;
		}
		case Direction::DOWN:
		{
			neighbourTile = cocos2d::Vec2(tileGridPos.x, tileGridPos.y + 1);
			break;
		}
		case Direction::LEFT:
		{
			neighbourTile = cocos2d::Vec2(tileGridPos.x - 1, tileGridPos.y);
			break;
		}
		case Direction::RIGHT:
		{
			neighbourTile = cocos2d::Vec2(tileGridPos.x + 1, tileGridPos.y);
			break;
		}
		}

		return neighbourTile;
	}

};